#include "mywidget.h"
#include<QProgressDialog>
#include<QErrorMessage>
#include<QDebug>
#include<QWizard>
#include<QFrame>
#include<QLabel>
#include<QMovie>
#include<QToolBox>
#include<QSlider>
#include<QScrollBar>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
//    QProgressDialog * w=new QProgressDialog("文件复制进度","取消",0,5000,this);
//    w->setModal(true);
//      w->show();
//    for(int i=0;i<5000;++i)
//    {
//        w->setValue(i);
//        if(w->wasCanceled())break;
//    }
//  //  w->setValue(5000);
//    qDebug()<<"复制结束";
#if 0
    QErrorMessage *error=new QErrorMessage(this);
    error->setWindowTitle("错误提示");
    error->showMessage("出现错误");
#endif

#if 0
    QWizard * wizar=new QWizard(this);
    QWizardPage * page1=new QWizardPage();
    page1->setTitle("介绍");
    wizar->addPage(page1);
    QWizardPage * page2=new QWizardPage();
    page2->setTitle("用户选择信息");
    QWizardPage * page3=new QWizardPage();
    page3->setTitle("结束");
    wizar->setWindowTitle("向导对话框");
    wizar->addPage(page2);
    wizar->addPage(page3);
    wizar->exec();
#endif
#if 0
    QFrame  * frame=new QFrame(this);
    frame->setFrameShape(QFrame::Box);
    frame->setFrameShadow(QFrame::Sunken);
    frame->setLineWidth(5);
    frame->setMinimumWidth(10);
    //label添加动态图
    QMovie *move=new QMovie("../1.gif");
    QLabel *labe=new QLabel(this);
    labe->setMovie(move);
    move->setSpeed(200);
    move->start();
#endif
   QScrollBar * bar=new QScrollBar(this);
   bar->setMaximum(1000);
   bar->setMinimum(1);
   bar->show();
}
