#ifndef MDICHILD_H
#define MDICHILD_H

#include <QCloseEvent>
#include <QTextEdit>
class QWidget;
class QMenu;

class MdiChild : public QTextEdit
{
    Q_OBJECT
public:
    explicit MdiChild(QWidget *parent = 0);
    void newFile();//新建文件操作
    bool loadFile(const QString & fileName);//加载文件
    bool save();//保存操作
    bool saveAs();//另存为
    bool savaFile(const QString & fileName);//保存文件
    QString userFriendlyCurrentFile();//提前文件名
    QString currentFile()//放回当前文件路径
    {
        return m_currentFile_;
    }

protected:
    void closeEvent(QCloseEvent * event);//关闭事件
    void contextMenuEvent(QContextMenuEvent *e);  //右键菜单事件
private slots:
    void documentWasModified();//文档被更改是，窗口显示更改状态
private:
    bool maybeSave();//是否保存
    void setCurrentFile(const QString & fileName);//设置当前文件
    void createContextMenu();

private:
    QString m_currentFile_;//保存当前文件路径
    bool m_isUntitled;//当前文件是否被保存到硬盘上的标志
    QMenu * m_contextMenu_;

signals:

public slots:

};

#endif // MDICHILD_H
