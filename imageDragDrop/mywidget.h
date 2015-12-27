#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QMainWindow>

class myWidget : public QMainWindow
{
    Q_OBJECT
public:
    explicit myWidget(QWidget *parent = 0);
public:
    void mousePressEvent(QMouseEvent *);
    void dragEnterEvent(QDragEnterEvent *);
    void dragMoveEvent(QDragMoveEvent *);
    void dropEvent(QDropEvent *);
signals:

public slots:

};

#endif // MYWIDGET_H
