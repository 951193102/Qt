#include<QApplication>
#include<QMdiSubWindow>
#include<QFileDialog>
#include<QDebug>
#include<QSignalMapper>
#include<QMessageBox>
#include<QCloseEvent>
#include<QSettings>
#include<QLabel>
#include"MdiChild.h"
#include"MainWindow.h"
#include"ui_mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainwindow)
{
    ui->setupUi(this);
    actionSeperator=new QAction(this);
    actionSeperator->setSeparator(true);
    m_windowMapper_=new QSignalMapper(this);


    updateMenu();
    connect(ui->mdiArea,SIGNAL(subWindowActivated(QMdiSubWindow*)),this,SLOT(updateMenu()));
    connect(m_windowMapper_,SIGNAL(mapped(QWidget*)),this,SLOT(setActionSubWindow(QWidget*)));
    updateWindowMenu();
    connect(ui->menu_W,SIGNAL(aboutToShow()),this,SLOT(updateWindowMenu()));
    readSetting();
    initWindow();
}

mainwindow::~mainwindow()
{
    delete ui;
}

MdiChild *mainwindow::actionMdiChild()
{
    if(QMdiSubWindow *activeSubWindow=ui->mdiArea->activeSubWindow())
    {
        return qobject_cast<MdiChild *>(activeSubWindow->widget());
    }
    return 0;
}

QMdiSubWindow *mainwindow::findSubWindow(const QString &filename)
{
    QString canonicalFilePath=QFileInfo(filename).canonicalFilePath();
    foreach (QMdiSubWindow *subwindow, ui->mdiArea->subWindowList()) {
        MdiChild *child=qobject_cast<MdiChild*>(subwindow->widget());
        if(child->currentFile()==canonicalFilePath)
        {
            return subwindow;
        }
    }
    return 0;
}

void mainwindow::readSetting()
{
    QSettings settings("mdihz","myMdi");
    if(settings.status())
    {
        ui->statusbar->showMessage(tr("读取配置文件错误"),2000);
        return;
    }
    QPoint pos=settings.value("pos").toPoint();
    QSize size=settings.value("size").toSize();
    this->move(pos);
    this->resize(size);
}

void mainwindow::writeSetting()
{
    QSettings settings("mdihz","myMdi");
    //写入位置信息
    settings.setValue("pos",pos());
    settings.setValue("size",size());
}

void mainwindow::initWindow()
{
    setWindowTitle(tr("多文档编辑器"));
    ui->toolBar->setWindowTitle(tr("工具栏"));

    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    ui->statusbar->setWindowTitle(tr("欢迎使用多文档编辑器"));
    QLabel * label=new QLabel(this);
    label->setFrameStyle(QFrame::Box|QFrame::Sunken);
    label->setText(tr("<a href=\"www.baidu.com\">百度一下</a>"));
    label->setTextFormat(Qt::RichText);
    label->setOpenExternalLinks(true);//可以打开连接
    ui->statusbar->addPermanentWidget(label);
    ui->actionNew->setToolTip("创建新文件");
}

void mainwindow::closeEvent(QCloseEvent *event)
{
    emit this->on_actionCloseAll_triggered();
    if(ui->mdiArea->currentSubWindow())//如果还有窗口没有关闭
    {
        event->ignore();
    }
    else
    {
        writeSetting();
        event->accept();
    }
}

void mainwindow::updateMenu()
{
    bool hasChild=(actionMdiChild()!=0);
    ui->actionSave->setEnabled(hasChild);
    ui->actionSaveAs->setEnabled(hasChild);
    ui->actionPaste->setEnabled(hasChild);
    ui->actionClose->setEnabled(hasChild);
    ui->actionCloseAll->setEnabled(hasChild);
    ui->actionTile->setEnabled(hasChild);
    ui->actionCascade->setEnabled(hasChild);
    ui->actionNext->setEnabled(hasChild);
    ui->actionPrevious->setEnabled(hasChild);

    actionSeperator->setVisible(hasChild);

    bool hashSelection=(actionMdiChild()&&actionMdiChild()->textCursor().hasSelection());
    ui->actionCut->setEnabled(hashSelection);
    ui->actionCopy->setEnabled(hashSelection);

    ui->actionUndo->setEnabled((actionMdiChild()&&actionMdiChild()->document()->isUndoAvailable()));
    ui->actionRedo->setEnabled((actionMdiChild()&&actionMdiChild()->document()->isRedoAvailable()));

}

void mainwindow::updateWindowMenu()
{
    ui->menu_W->clear();
    ui->menu_W->addAction(ui->actionClose);
    ui->menu_W->addAction(ui->actionCloseAll);
    ui->menu_W->addSeparator();
    ui->menu_W->addAction(ui->actionTile);
    ui->menu_W->addAction(ui->actionCascade);
    ui->menu_W->addSeparator();

    ui->menu_W->addAction(ui->actionNext);
    ui->menu_W->addAction(ui->actionPrevious);
    ui->menu_W->addAction(actionSeperator);

    QList<QMdiSubWindow*> windows=ui->mdiArea->subWindowList();
    actionSeperator->setVisible(!windows.isEmpty());
    for(int i=0;i<windows.size();++i)
    {
        MdiChild *child=qobject_cast<MdiChild*>(windows.at(i)->widget());
        QString text;
        if(i<9)//如果窗口数小于9,则设置编号
        {
            text=tr("&%1 %2").arg(i+1).arg(child->userFriendlyCurrentFile());
        }
        else
        {
             text=tr("&%1 %2").arg(i+1).arg(child->userFriendlyCurrentFile());
        }
        QAction *action=ui->menu_W->addAction(text);
        action->setCheckable(true);//设定当前窗口是选中状态
        action->setChecked(child==actionMdiChild());
        //关联信号到信号映射器mapper槽
        connect(action,SIGNAL(triggered()),m_windowMapper_,SLOT(map()));
        m_windowMapper_->setMapping(action,windows.at(i));


    }
}

MdiChild *mainwindow::createMdiChild()
{
    MdiChild  *child=new MdiChild(this);
    ui->mdiArea->addSubWindow(child);
    //根据Qtextedit是否有可复制信号，来设置拷贝和剪切操作
    connect(child,SIGNAL(copyAvailable(bool)),ui->actionCopy,SLOT(setEnabled(bool)));
    connect(child,SIGNAL(copyAvailable(bool)),ui->actionCut,SLOT(setEnabled(bool)));

    //根据document是否有撤销等信号，设置撤销和恢复
    connect(child->document(),SIGNAL(redoAvailable(bool)),ui->actionRedo,SLOT(setEnabled(bool)));
    connect(child->document(),SIGNAL(undoAvailable(bool)),ui->actionUndo,SLOT(setEnabled(bool)));
    connect(child,SIGNAL(cursorPositionChanged()),this,SLOT(showTextRowAndCol()));
    return child;
}

void mainwindow::setActionSubWindow(QWidget *window)
{
    if(!window)
        return;
    ui->mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow*>(window));
}

void mainwindow::showTextRowAndCol()
{
    if(actionMdiChild())
    {
        int rowNum=actionMdiChild()->textCursor().blockNumber()+1;
        int colNum=actionMdiChild()->textCursor().columnNumber()+1;
        ui->statusbar->showMessage(tr("%1行 %2列").arg(rowNum).arg(colNum));
    }
}

void mainwindow::on_actionNew_triggered()
{
    MdiChild  *child=createMdiChild();
    child->newFile();//新建文件
    child->show();
}

int main(int argc,char * argv[])
{
    QApplication app(argc,argv);
    mainwindow w;
    w.show();

    return app.exec();
}

void mainwindow::on_actionOpen_triggered()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("打开"),"",tr("文本文档(*.txt)\n所有文件(*.*)"));

    if(!filename.isEmpty())
    {
        QMdiSubWindow * existing=findSubWindow(filename);
        if(existing)//如果已经打开
        {
            ui->mdiArea->setActiveSubWindow(existing);
            return;
        }
        MdiChild *child=createMdiChild();//如果没有打开过
        if(child->loadFile(filename))
        {
            ui->statusbar->showMessage(tr("打开文件成功"),2000);
            ui->mdiArea->addSubWindow(child);
            child->show();

        }
        else
        {
            child->close();
        }

    }
}

void mainwindow::on_actionSave_triggered()
{
    if(actionMdiChild()&&actionMdiChild()->save())
    {
        ui->statusbar->showMessage(tr("保存文件成功"),2000);
    }
}

void mainwindow::on_actionUndo_triggered()
{
    if(actionMdiChild())
    {
        actionMdiChild()->undo();
    }
}

void mainwindow::on_actionRedo_triggered()
{
    if(actionMdiChild())
    {
        actionMdiChild()->redo();
    }
}

void mainwindow::on_actionCut_triggered()
{
    if(actionMdiChild()&&ui->actionCut->isEnabled())
    {
        actionMdiChild()->cut();
    }
}

void mainwindow::on_actionCopy_triggered()
{
    if(actionMdiChild()&&ui->actionCopy->isEnabled())
    {
        actionMdiChild()->copy();
    }
}

void mainwindow::on_actionPaste_triggered()
{
    if(actionMdiChild())
    {
        actionMdiChild()->paste();
    }
}

void mainwindow::on_actionClose_triggered()
{
    ui->mdiArea->closeActiveSubWindow();
}

void mainwindow::on_actionCloseAll_triggered()
{
    ui->mdiArea->closeAllSubWindows();
}

void mainwindow::on_actionSaveAs_triggered()
{
    if(actionMdiChild()&&actionMdiChild()->saveAs())
    {
        ui->statusbar->showMessage(tr("另存为文件成功"),2000);
    }
}

void mainwindow::on_actionExit_triggered()
{
   QApplication::closeAllWindows();
}

void mainwindow::on_actionTile_triggered()
{
    if(actionMdiChild())
    {
       emit ui->mdiArea->tileSubWindows();
    }
}

void mainwindow::on_actionCascade_triggered()
{
    if(actionMdiChild())
    {
        emit ui->mdiArea->cascadeSubWindows();
    }
}

void mainwindow::on_actionNext_triggered()
{
    if(actionMdiChild())
    {
       emit ui->mdiArea->activateNextSubWindow();
    }
}

void mainwindow::on_actionPrevious_triggered()
{
    if(actionMdiChild())
    {
       emit ui->mdiArea->activatePreviousSubWindow();
    }
}

void mainwindow::on_actionAbout_triggered()
{
    QMessageBox::about(this,tr("关于作者"),"多文档编辑器1.0.0版本");
}

void mainwindow::on_action_QtAboutQt_triggered()
{
    QMessageBox::aboutQt(this,tr("Qt关于"));
}
