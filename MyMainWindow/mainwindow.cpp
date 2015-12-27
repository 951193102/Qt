#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTextEdit>
#include<QMdiArea>
#include<QMdiSubWindow>
#include<QDockWidget>
#include<QPushButton>
#include<QComboBox>
#include<QStatusBar>
#include<QLabel>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QMdiArea *midarea=new QMdiArea(this);
    QTextEdit * edit=new QTextEdit(this);
    QMdiSubWindow * subwindow=new QMdiSubWindow;
    subwindow->setWindowTitle("多文档子窗口1");
    QMdiSubWindow * subwindow1=new QMdiSubWindow;
    subwindow1->setWindowTitle("多文档子窗口2");
    midarea->addSubWindow(subwindow1);
      midarea->addSubWindow(subwindow);
    subwindow->show();
    ui->setupUi(this);
    this->setCentralWidget(edit);

    QDockWidget* dockwidget=new QDockWidget("工具箱",this);
    dockwidget->setWidget(new QPushButton("BUtton"));
    dockwidget->show();

    QStatusBar * status=this->statusBar();
    status->showMessage("欢迎使用多文档编辑器",2000);

    QLabel * permanet=new QLabel(this);
    permanet->setFrameStyle(QFrame::Box|QFrame::Sunken);
    permanet->setText("www.baidu.com");
    status->addPermanentWidget(permanet);

}

MainWindow::~MainWindow()
{
    delete ui;
}
