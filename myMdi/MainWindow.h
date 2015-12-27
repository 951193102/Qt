#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class mainwindow;
}

class MdiChild;
class QMdiSubWindow;
class QSignalMapper;
class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = 0);
    ~mainwindow();
private:
    QAction * actionSeperator;
    QSignalMapper * m_windowMapper_;//信号映射器

    MdiChild * actionMdiChild();//返回活动窗口
    QMdiSubWindow * findSubWindow(const QString & filename);
    void readSetting();//读取窗口设置
    void writeSetting();//写入窗口设置
    void initWindow();//初始化窗口
protected:
    void closeEvent(QCloseEvent *);
private slots:
    void updateMenu();
    void updateWindowMenu();//更新窗口菜单
    MdiChild * createMdiChild();
    void setActionSubWindow(QWidget* window);
    void showTextRowAndCol();//显示光标的行号和列号
private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionClose_triggered();

    void on_actionCloseAll_triggered();

    void on_actionSaveAs_triggered();

    void on_actionExit_triggered();

    void on_actionTile_triggered();

    void on_actionCascade_triggered();

    void on_actionNext_triggered();

    void on_actionPrevious_triggered();

    void on_actionAbout_triggered();

    void on_action_QtAboutQt_triggered();

private:
    Ui::mainwindow *ui;
};

#endif // MAINWINDOW_H
