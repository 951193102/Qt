#include<QApplication>
#include<QPrinter>
#include<QPrintDialog>
#include<QPrintPreviewDialog>
#include<QFileDialog>
#include<QFileInfo>
#include<QToolBar>
#include<QAction>
#include<QTextEdit>
#include "mywidget.h"

myWidget::myWidget(QWidget *parent) :
    QMainWindow(parent)
{
    QAction *action_print=new QAction(tr("打印"),this);
    QAction *action_preview=new QAction(tr("打印预览"),this);
    QAction * action_pdf=new QAction(tr("生成pdf文档"),this);

    connect(action_print,SIGNAL(triggered()),this,SLOT(doPrint()));
    connect(action_preview,SIGNAL(triggered()),this,SLOT(doPrintPreview()));
    connect(action_pdf,SIGNAL(triggered()),this,SLOT(createPdf()));

    QToolBar * toolBar=this->addToolBar("NVA");
    toolBar->addAction(action_print);
    toolBar->addAction(action_preview);
    toolBar->addAction(action_pdf);




    m_edit_=new QTextEdit(this);
        this->setCentralWidget(m_edit_);
}

void myWidget::doPrint()
{
    QPrinter printer;
    QPrintDialog printdlg(&printer,this);
    if(m_edit_->textCursor().hasComplexSelection())//有选中打印区域
    {
        printdlg.addEnabledOption(QAbstractPrintDialog::PrintSelection);//打印选中区域
    }
    if(printdlg.exec()==QPrintDialog::Accepted)
    {
        m_edit_->print(&printer);
    }

}

void myWidget::doPrintPreview()
{
    QPrinter printer;
    QPrintPreviewDialog predlg(&printer,this);
    connect(&predlg,SIGNAL(paintRequested(QPrinter*)),this,SLOT(printPreview(QPrinter*)));
    predlg.exec();
}

void myWidget::printPreview(QPrinter *printer)
{
    m_edit_->print(printer);
}

void myWidget::createPdf()
{
    QString  filename=QFileDialog::getSaveFileName(0,tr("导出pdf文件"),QString(),QString(".pdf"));
    if(!filename.isEmpty())
    {
        if(QFileInfo(filename).suffix().isEmpty())
        {
            filename.append(".pdf");
        }
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filename);
        m_edit_->print(&printer);
    }

}


int main(int argc,char * argv[])
{
    QApplication app(argc,argv);

    myWidget w;
    w.resize(500,500);
    w.show();

    return app.exec();
}
