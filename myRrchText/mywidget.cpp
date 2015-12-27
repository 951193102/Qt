#include<QApplication>
#include<QTextEdit>
#include<QTextFrame>
#include<QAction>
#include<QToolBar>
#include<QMenuBar>
#include<QDebug>
#include<QLineEdit>
#include<QPushButton>
#include<QDialog>
#include<QVBoxLayout>
#include<QFileDialog>

#define __DRAG_AND_DROP
#ifdef __DRAG_AND_DROP
#include<QDragEnterEvent>
#include<QUrl>
#include<QFile>
#include<QDropEvent>
#include<QMimeData>
#endif
#include "mywidget.h"
#include"mysyntaxhighlighter.h"

MyWidget::MyWidget(QWidget *parent) :
    QMainWindow(parent)
{
    this->setAcceptDrops(true);

    QMenuBar * menubar=this->menuBar();

    QAction *action_showtextframe=new QAction(tr("框架"),this);
    QToolBar *toolbar=this->addToolBar("Nagevi");
    QAction *action_showTextBlock=new QAction(tr("文本快"),this);
    QAction *action_setTextFont=new QAction(tr("字体"),this);
    QAction * action_insertTable=new QAction(tr("表格"),this);
    QAction * action_insertList=new QAction(tr("列表"),this);
    QAction  *action_insertImage=new QAction(tr("图片"),this);
    QAction *action_findText=new QAction(tr("查找"),this);


    action_setTextFont->setCheckable(true);
    connect(action_showtextframe,SIGNAL(triggered()),this,SLOT(showTextFrame()));
   // this->addAction(action_showtextframe);
    connect(action_showTextBlock,SIGNAL(triggered()),this,SLOT(showTextBlock()));
    connect(action_setTextFont,SIGNAL(triggered(bool)),this,SLOT(setTextFont(bool)));
    connect(action_insertTable,SIGNAL(triggered()),this,SLOT(insertTable()));
    connect(action_insertList,SIGNAL(triggered()),this,SLOT(insertList()));
    connect(action_insertImage,SIGNAL(triggered()),this,SLOT(inserImage()));
    connect(action_findText,SIGNAL(triggered()),this,SLOT(findText()));


    toolbar->addAction(action_showtextframe);
    toolbar->addAction(action_showTextBlock);
    toolbar->addAction(action_setTextFont);
    toolbar->addAction(action_insertTable);
    toolbar->addAction(action_insertList);
    toolbar->addAction(action_insertImage);
    toolbar->addAction(action_findText);

    menubar->addAction(action_showtextframe);

    m_edit_=new QTextEdit(this);
    this->setCentralWidget(m_edit_);

    QTextDocument * document=m_edit_->document();
    QTextFrame * rootframe=document->rootFrame();
    QTextFrameFormat fromat;
    fromat.setBorderBrush(Qt::red);
    fromat.setBorder(3);

    rootframe->setFrameFormat(fromat);
    //光标
    QTextFrameFormat textfromat;
    textfromat.setBackground(Qt::lightGray);
    textfromat.setMargin(0);
    textfromat.setPadding(5);
    textfromat.setBorder(2);
    textfromat.setBorderStyle(QTextFrameFormat::BorderStyle_DotDotDash);
    QTextCursor cursor=m_edit_->textCursor();
    cursor.insertFrame(textfromat);

    MySyntaxHighlighter * mySyntax=new MySyntaxHighlighter(this);
    mySyntax->setDocument(m_edit_->document());



}



void MyWidget::dragEnterEvent(QDragEnterEvent *event)
{

    if(event->mimeData()->hasFormat("text/plain"))
    {
         qDebug()<<"aaaa";
        event->acceptProposedAction();
    }

}

void MyWidget::dropEvent(QDropEvent *event)
{
    qDebug()<<"drop ";
    const QMimeData  *mimedat=event->mimeData();
    if(mimedat->hasUrls())
    {
        QList<QUrl> urlLists=mimedat->urls();
        //只处理一个文件
        QString filename=urlLists.first().toLocalFile();
        qDebug()<<filename;

    }
}

void MyWidget::showTextFrame()
{
    QTextDocument *document=m_edit_->document();
    QTextFrame * rootframe=document->rootFrame();
    QTextFrame::iterator it;
    for(it=rootframe->begin();it!=rootframe->end();++it)
    {
        QTextFrame *childframe=it.currentFrame();
        QTextBlock childblock=it.currentBlock();
        if(childframe)
        {

            qDebug()<<"frame";
            for(QTextFrame::iterator it2=childframe->begin();it2!=childframe->end();++it2)
            {
                QTextFrame *childframe1=it2.currentFrame();
                QTextBlock childblock1=it2.currentBlock();
                if(childframe1)
                    qDebug()<<"frame1";
                else if (childblock1.isValid())
                    qDebug()<<"block1"<<childblock1.text().toUtf8();
            }
        }
        else if (childblock.isValid())
            qDebug()<<"block"<<childblock.text().toUtf8();
    }
}

void MyWidget::showTextBlock()
{
    QTextDocument * document=this->m_edit_->document();
    QTextBlock firstBlock=document->firstBlock();
    for(int i=0;i<document->blockCount();++i)
    {
        qDebug()<<tr("第%1个文本快,文本块首行行号%2,文本块长度%3,文本块内容:").arg(i).arg(firstBlock.firstLineNumber())
                  .arg(firstBlock.length())<<firstBlock.text().toUtf8();
        firstBlock=firstBlock.next();
    }
}

void MyWidget::setTextFont(bool checked)
{
    qDebug()<<checked;
    if(checked) //处于选中状态
    {
        QTextCursor cursor=m_edit_->textCursor();
        QTextBlockFormat blockFormat;
        blockFormat.setAlignment(Qt::AlignCenter);
        cursor.insertBlock(blockFormat);//插入文本格式

        QTextCharFormat charFromat;
        charFromat.setBackground(Qt::lightGray);
        charFromat.setForeground(Qt::blue);
        charFromat.setFont(QFont(tr("华文新魏"),12,QFont::Bold,true));
        charFromat.setFontUnderline(true);
        cursor.setCharFormat(charFromat);
        cursor.insertText("测试字体");
    }
    else
    {

    }
}

void MyWidget::insertTable()
{
    //插入表格
    QTextCursor  cursor=m_edit_->textCursor();
    QTextTableFormat tableFromat;
    tableFromat.setCellPadding(10);
    tableFromat.setCellSpacing(2);
    cursor.insertTable(2,2,tableFromat);
}

void MyWidget::insertList()
{
    //插入列表
    QTextCursor cursor=m_edit_->textCursor();
    QTextListFormat listFormat;
    listFormat.setStyle(QTextListFormat::ListDecimal);//数字编号
    cursor.insertList(listFormat);
}

void MyWidget::inserImage()
{
    QString filename=QFileDialog::getOpenFileName(0,tr("选择插入图片"),"","jpg,png");
    if(filename.isEmpty())
    {
        return;
    }
    qDebug()<<filename;
    QTextImageFormat imageformat;
    imageformat.setName(filename);
    m_edit_->textCursor().insertImage(imageformat);
}

void MyWidget::findText()
{
    QDialog *dialog=new QDialog(this);
    m_linEdit_=new QLineEdit(dialog);
    QPushButton * btn=new QPushButton(tr("查找下一个"),dialog);
    connect(btn,SIGNAL(clicked()),this,SLOT(findNextText()));
    QVBoxLayout *vlayout=new QVBoxLayout(dialog);
    vlayout->addWidget(m_linEdit_);
    vlayout->addWidget(btn);
    dialog->show();


}

void MyWidget::findNextText()
{
    QString findString=m_linEdit_->text();
    QTextDocument *document=m_edit_->document();

    if(findString.isEmpty())
        return;
    bool isFind=m_edit_->find(findString);
    if(isFind)//查找成功
    {
        qDebug()<<tr("行号 %1,列号 %2").arg(m_edit_->textCursor().blockNumber())
                  .arg(m_edit_->textCursor().columnNumber());
    }
}


int main(int argc,char * argv[])
{
    QApplication app(argc,argv);

    MyWidget w;
    w.resize(500,500);
    w.show();

    return app.exec();
}
