#include<QApplication>
#include<QMouseEvent>
#include<QDragEnterEvent>
#include<QDragMoveEvent>
#include<QDropEvent>
#include<QLabel>
#include<QPainter>
#include<QPixmap>
#include<QMimeData>
#include<QDrag>
#include "mywidget.h"

myWidget::myWidget(QWidget *parent) :
    QMainWindow(parent)
{

    this->setAcceptDrops(true);//设置接受拖拽
    QLabel *label=new QLabel(this);
   QPixmap pixmap("1.png");
   label->setPixmap(pixmap);
   label->resize(pixmap.size());
   label->move(100,100);
   label->setAttribute(Qt::WA_DeleteOnClose);

}

void myWidget::mousePressEvent(QMouseEvent *event)
{
    QLabel * child=static_cast<QLabel *>(childAt(event->pos()));
    if(!child->inherits("QLable")) return;
    QPixmap pixmap=*child->pixmap();

    QByteArray itemdata;
    QDataStream dataStream(&itemdata,QIODevice::WriteOnly);
    dataStream<<pixmap<<QPoint(event->pos()-child->pos());


    QMimeData * mimdata=new QMimeData;
    mimdata->setData("myimage/png",itemdata);

    QDrag *drag=new QDrag(this);
    drag->setMimeData(mimdata);
    drag->setPixmap(pixmap);
    drag->setHotSpot(QPoint(event->pos()-child->pos()));

    QPixmap tempPixmap=pixmap;
    QPainter painter(&tempPixmap);
    painter.fillRect(pixmap.rect(),QColor(127,127,127,127));
    painter.end();
    drag->setPixmap(tempPixmap);


    if(drag->exec(Qt::CopyAction|Qt::MoveAction,Qt::CopyAction)==Qt::MoveAction)
    {
        child->close();
    }
    else
    {
        child->show();
        child->setPixmap(pixmap);
    }


}

void myWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("myimage/png"))
    {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void myWidget::dragMoveEvent(QDragMoveEvent *event)
{
    if(event->mimeData()->hasFormat("myimage/png"))
    {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void myWidget::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasFormat("myimage/png"))
    {
        QByteArray itemdata=event->mimeData()->data("myimage/png");
        QDataStream dataStream(&itemdata,QIODevice::ReadOnly);
        QPixmap pixmap;
        QPoint offset;
        dataStream<<pixmap<<offset;

        QLabel *newlabel=new QLabel(this);
        newlabel->setPixmap(pixmap);
        newlabel->resize(pixmap.size());
        newlabel->move(event->pos()-offset);
        newlabel->show();
        newlabel->setAttribute(Qt::WA_DeleteOnClose);
        event->setDropAction(Qt::MoveAction);
        event->accept();


    }
    else
    {
        event->ignore();
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
