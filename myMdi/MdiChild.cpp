#include<QPushButton>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QFileInfo>
#include<QApplication>
#include<QFileDialog>
#include<QCloseEvent>
#include<QMenu>

#include "MdiChild.h"

MdiChild::MdiChild(QWidget *parent) :
    QTextEdit(parent)
{

    this->setAttribute(Qt::WA_DeleteOnClose);//窗口关闭时，销毁这个对象
    m_isUntitled=true;
    createContextMenu();

}

void MdiChild::newFile()
{
    static int sequenceNumber=1;
    m_isUntitled=true;
    m_currentFile_=tr("未命名文件%1.txt").arg(sequenceNumber++);
    this->setWindowTitle(m_currentFile_+"[*]"+tr(" - 多文档编辑器"));
    connect(document(),SIGNAL(contentsChanged()),this,SLOT(documentWasModified()));//设置文档内容改变关联


}

bool MdiChild::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly|QFile::Text))//以只读方式打开
    {
        QMessageBox::warning(this,tr("多文档编辑器"),tr("无法读取文件 %1:\n%2.").arg(fileName)
                             .arg(file.errorString()));
        return false;
    }
    QTextStream textStream(&file);//新建文本流
    QApplication::setOverrideCursor(Qt::WaitCursor);//设置鼠标为等待模式
    this->setPlainText(textStream.readAll());//读取全部内容，加载到编辑器中
    QApplication::restoreOverrideCursor();//恢复鼠标状态
    setCurrentFile(fileName);\
    connect(document(),SIGNAL(contentsChanged()),this,SLOT(documentWasModified()));
    return true;
}

bool MdiChild::save()
{
    //如果未保存过，执行另存为操作，否则执行保存
    if(m_isUntitled)
    {
        return saveAs();
    }
    else
    {
        return savaFile(m_currentFile_);
    }

}

bool MdiChild::saveAs()
{
    QString filename=QFileDialog::getSaveFileName(this,tr("另存为"),m_currentFile_);
    if(filename.isEmpty())
    {
        return false;
    }
    return savaFile(filename);
}

bool MdiChild::savaFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this,tr("多文档编辑器"),tr("无法写入文件 %1:\n%2.")
                             .arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream fileout(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    fileout<<this->toPlainText();
    QApplication::restoreOverrideCursor();
    setCurrentFile(fileName);
    return true;
}

QString MdiChild::userFriendlyCurrentFile()
{
    return QFileInfo(m_currentFile_).fileName();
}

void MdiChild::closeEvent(QCloseEvent *event)
{
    if(maybeSave())
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void MdiChild::contextMenuEvent(QContextMenuEvent *e)
{
    m_contextMenu_->exec(e->globalPos());
}

void MdiChild::documentWasModified()
{
    this->setWindowModified(document()->isModified());
}

bool MdiChild::maybeSave()
{
    if(document()->isModified())
    {
        QMessageBox box;
        box.setWindowTitle(tr("多文档编辑器"));
        box.setText(tr("是否保存对 %1 的修改").arg(userFriendlyCurrentFile()));
        box.setIcon(QMessageBox::Warning);

        QPushButton *yesBtn=box.addButton(tr("是(&Y)"),QMessageBox::YesRole);
        box.addButton(tr("否(&N)"),QMessageBox::NoRole);
        QPushButton *cancelBtn=box.addButton(tr("取消"),QMessageBox::RejectRole);
        box.exec();
        if(box.clickedButton()==yesBtn)
        {
            return save();
        }
        else if(box.clickedButton()==cancelBtn)
            return false;
    }
    return true;
}

void MdiChild::setCurrentFile(const QString &fileName)
{
    //去除路径中的符号链接,"."和".."等
    m_currentFile_=QFileInfo(fileName).canonicalFilePath();
    m_isUntitled=false;
    document()->setModified(false);
    setWindowModified(false);
    setWindowTitle(userFriendlyCurrentFile()+"[*]");
}

void MdiChild::createContextMenu()
{

    QMenu * menu=new QMenu(this);
    QAction * undo=menu->addAction(tr("撤销(&U)"),this,SLOT(undo()),QKeySequence::Undo);
    undo->setEnabled(document()->isUndoAvailable());
    QAction * redo=menu->addAction(tr("恢复(&R)"),this,SLOT(redo()),QKeySequence::Redo);
    redo->setEnabled(document()->isRedoAvailable());
    menu->addSeparator();
    QAction *cut=menu->addAction(tr("剪切(&T)"),this,SLOT(cut()),QKeySequence::Cut);
    cut->setEnabled(this->textCursor().hasSelection());
    QAction *copy=menu->addAction(tr("复制(&C)"),this,SLOT(copy()),QKeySequence::Copy);
    copy->setEnabled(this->textCursor().hasSelection());

    menu->addAction(tr("粘贴(&P)"),this,SLOT(paste()),QKeySequence::Paste);

    QAction *clear=menu->addAction(tr("清空"),this,SLOT(clear()));
    clear->setEnabled(!document()->isEmpty());
    menu->addSeparator();

    QAction *select=menu->addAction(tr("全选"),this,SLOT(selectAll()),QKeySequence::SelectAll);
    select->setEnabled(!document()->isEmpty());

    m_contextMenu_=menu;
}
