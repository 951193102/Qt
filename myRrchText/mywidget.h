#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QMainWindow>
class QTextEdit;
class QLineEdit;
class MySyntaxHighlighter;
class QDragEnterEvent;
class QDropEvent;
class MyWidget : public QMainWindow
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

public:

virtual    void dragEnterEvent(QDragEnterEvent *) override;//拖动进入事件
   virtual void dropEvent(QDropEvent *) override;//放下事件
private:
    QTextEdit * m_edit_;
    QLineEdit * m_linEdit_;
signals:

public slots:
    void showTextFrame();
    void showTextBlock();
    void setTextFont(bool);

    void insertTable();
    void insertList();
    void inserImage();

    void findText();
    void findNextText();
};

#endif // MYWIDGET_H
