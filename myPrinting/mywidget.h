#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QMainWindow>

class QPrinter;
class QTextEdit;
class myWidget : public QMainWindow
{
    Q_OBJECT
public:
    explicit myWidget(QWidget *parent = 0);
private:
    QTextEdit *m_edit_;
signals:

public slots:
    void doPrint();
    void doPrintPreview();
    void printPreview(QPrinter *);
    void createPdf();
};

#endif // MYWIDGET_H
