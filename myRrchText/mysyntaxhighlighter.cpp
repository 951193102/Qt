#include<QTextEdit>
#include<QRegExp>
#include<QDebug>
#include "mysyntaxhighlighter.h"

MySyntaxHighlighter::MySyntaxHighlighter(QObject *parent) :
    QSyntaxHighlighter(parent)
{
}

void MySyntaxHighlighter::highlightBlock(const QString &text)
{

   // qDebug()<<text;
    QTextCharFormat charFormat;
    charFormat.setForeground(Qt::green);
    charFormat.setFontWeight(QFont::Bold);
    QString strin="\\bchar\\b";
    QRegExp exp(strin);
    int index=text.indexOf(exp);
    while(index>=0)
    {
        int length=exp.matchedLength();
        this->setFormat(index,length,charFormat);
        index=text.indexOf(exp,index+length);
    }

}
