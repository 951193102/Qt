/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionExit;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionClose;
    QAction *actionCloseAll;
    QAction *actionTile;
    QAction *actionCascade;
    QAction *actionNext;
    QAction *actionPrevious;
    QAction *actionAbout;
    QAction *action_QtAboutQt;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menubar;
    QMenu *menu_F;
    QMenu *menu_E;
    QMenu *menu_W;
    QMenu *menu_H;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *mainwindow)
    {
        if (mainwindow->objectName().isEmpty())
            mainwindow->setObjectName(QStringLiteral("mainwindow"));
        mainwindow->resize(800, 600);
        actionNew = new QAction(mainwindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(mainwindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(mainwindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSaveAs = new QAction(mainwindow);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionExit = new QAction(mainwindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionUndo = new QAction(mainwindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(mainwindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionCut = new QAction(mainwindow);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        actionCopy = new QAction(mainwindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionPaste = new QAction(mainwindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actionClose = new QAction(mainwindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionCloseAll = new QAction(mainwindow);
        actionCloseAll->setObjectName(QStringLiteral("actionCloseAll"));
        actionTile = new QAction(mainwindow);
        actionTile->setObjectName(QStringLiteral("actionTile"));
        actionCascade = new QAction(mainwindow);
        actionCascade->setObjectName(QStringLiteral("actionCascade"));
        actionNext = new QAction(mainwindow);
        actionNext->setObjectName(QStringLiteral("actionNext"));
        actionPrevious = new QAction(mainwindow);
        actionPrevious->setObjectName(QStringLiteral("actionPrevious"));
        actionAbout = new QAction(mainwindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        action_QtAboutQt = new QAction(mainwindow);
        action_QtAboutQt->setObjectName(QStringLiteral("action_QtAboutQt"));
        centralwidget = new QWidget(mainwindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        mainwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainwindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menu_F = new QMenu(menubar);
        menu_F->setObjectName(QStringLiteral("menu_F"));
        menu_E = new QMenu(menubar);
        menu_E->setObjectName(QStringLiteral("menu_E"));
        menu_W = new QMenu(menubar);
        menu_W->setObjectName(QStringLiteral("menu_W"));
        menu_H = new QMenu(menubar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        mainwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(mainwindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        mainwindow->setStatusBar(statusbar);
        toolBar = new QToolBar(mainwindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        mainwindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu_F->menuAction());
        menubar->addAction(menu_E->menuAction());
        menubar->addAction(menu_W->menuAction());
        menubar->addAction(menu_H->menuAction());
        menu_F->addAction(actionNew);
        menu_F->addAction(actionOpen);
        menu_F->addSeparator();
        menu_F->addAction(actionSave);
        menu_F->addAction(actionSaveAs);
        menu_F->addAction(actionExit);
        menu_E->addAction(actionUndo);
        menu_E->addAction(actionRedo);
        menu_E->addSeparator();
        menu_E->addAction(actionCut);
        menu_E->addAction(actionCopy);
        menu_E->addAction(actionPaste);
        menu_W->addAction(actionClose);
        menu_W->addAction(actionCloseAll);
        menu_W->addSeparator();
        menu_W->addAction(actionTile);
        menu_W->addAction(actionCascade);
        menu_W->addSeparator();
        menu_W->addAction(actionNext);
        menu_W->addAction(actionPrevious);
        menu_H->addAction(actionAbout);
        menu_H->addAction(action_QtAboutQt);

        retranslateUi(mainwindow);

        QMetaObject::connectSlotsByName(mainwindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainwindow)
    {
        mainwindow->setWindowTitle(QApplication::translate("mainwindow", "mainwindow", 0));
        actionNew->setText(QApplication::translate("mainwindow", "\346\226\260\345\273\272\346\226\207\344\273\266(&N)", 0));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("mainwindow", "\346\226\260\345\273\272\346\226\207\344\273\266", 0));
#endif // QT_NO_TOOLTIP
        actionNew->setShortcut(QApplication::translate("mainwindow", "Ctrl+N", 0));
        actionOpen->setText(QApplication::translate("mainwindow", "\346\211\223\345\274\200\346\226\207\344\273\266(&O)...", 0));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("mainwindow", "\346\211\223\345\274\200\346\226\207\344\273\266", 0));
#endif // QT_NO_TOOLTIP
        actionOpen->setShortcut(QApplication::translate("mainwindow", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("mainwindow", "\344\277\235\345\255\230(&S)", 0));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("mainwindow", "\344\277\235\345\255\230", 0));
#endif // QT_NO_TOOLTIP
        actionSave->setShortcut(QApplication::translate("mainwindow", "Ctrl+S", 0));
        actionSaveAs->setText(QApplication::translate("mainwindow", "\345\217\246\345\255\230\344\270\272(&A)...", 0));
#ifndef QT_NO_TOOLTIP
        actionSaveAs->setToolTip(QApplication::translate("mainwindow", "\345\217\246\345\255\230\344\270\272", 0));
#endif // QT_NO_TOOLTIP
        actionExit->setText(QApplication::translate("mainwindow", "\351\200\200\345\207\272(X)", 0));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("mainwindow", "\351\200\200\345\207\272", 0));
#endif // QT_NO_TOOLTIP
        actionUndo->setText(QApplication::translate("mainwindow", "\346\222\244\351\224\200(&Z)", 0));
#ifndef QT_NO_TOOLTIP
        actionUndo->setToolTip(QApplication::translate("mainwindow", "\346\222\244\351\224\200", 0));
#endif // QT_NO_TOOLTIP
        actionUndo->setShortcut(QApplication::translate("mainwindow", "Ctrl+Z", 0));
        actionRedo->setText(QApplication::translate("mainwindow", "\346\201\242\345\244\215(&Y)", 0));
        actionRedo->setShortcut(QApplication::translate("mainwindow", "Ctrl+Y", 0));
        actionCut->setText(QApplication::translate("mainwindow", "\345\211\252\345\210\207(&X)", 0));
#ifndef QT_NO_TOOLTIP
        actionCut->setToolTip(QApplication::translate("mainwindow", "\345\211\252\345\210\207", 0));
#endif // QT_NO_TOOLTIP
        actionCut->setShortcut(QApplication::translate("mainwindow", "Ctrl+C", 0));
        actionCopy->setText(QApplication::translate("mainwindow", "\345\244\215\345\210\266(&C)", 0));
#ifndef QT_NO_TOOLTIP
        actionCopy->setToolTip(QApplication::translate("mainwindow", "\345\244\215\345\210\266", 0));
#endif // QT_NO_TOOLTIP
        actionCopy->setShortcut(QApplication::translate("mainwindow", "Ctrl+C", 0));
        actionPaste->setText(QApplication::translate("mainwindow", "\347\262\230\350\264\264(&V)", 0));
#ifndef QT_NO_TOOLTIP
        actionPaste->setToolTip(QApplication::translate("mainwindow", "\347\262\230\350\264\264", 0));
#endif // QT_NO_TOOLTIP
        actionPaste->setShortcut(QApplication::translate("mainwindow", "Ctrl+V", 0));
        actionClose->setText(QApplication::translate("mainwindow", "\345\205\263\351\227\255(O)", 0));
#ifndef QT_NO_TOOLTIP
        actionClose->setToolTip(QApplication::translate("mainwindow", "\345\205\263\351\227\255", 0));
#endif // QT_NO_TOOLTIP
        actionCloseAll->setText(QApplication::translate("mainwindow", "\345\205\263\351\227\255\346\211\200\346\234\211\347\252\227\345\217\243(&A)", 0));
#ifndef QT_NO_TOOLTIP
        actionCloseAll->setToolTip(QApplication::translate("mainwindow", "\345\205\263\351\227\255\346\211\200\346\234\211\347\252\227\345\217\243", 0));
#endif // QT_NO_TOOLTIP
        actionTile->setText(QApplication::translate("mainwindow", "\345\271\263\351\223\272(&T)", 0));
#ifndef QT_NO_TOOLTIP
        actionTile->setToolTip(QApplication::translate("mainwindow", "\345\271\263\351\223\272", 0));
#endif // QT_NO_TOOLTIP
        actionCascade->setText(QApplication::translate("mainwindow", "\345\261\202\345\217\240(&C)", 0));
#ifndef QT_NO_TOOLTIP
        actionCascade->setToolTip(QApplication::translate("mainwindow", "\345\261\202\345\217\240", 0));
#endif // QT_NO_TOOLTIP
        actionNext->setText(QApplication::translate("mainwindow", "\344\270\213\344\270\200\344\270\252(&X)", 0));
#ifndef QT_NO_TOOLTIP
        actionNext->setToolTip(QApplication::translate("mainwindow", "\344\270\213\344\270\200\344\270\252", 0));
#endif // QT_NO_TOOLTIP
        actionNext->setShortcut(QApplication::translate("mainwindow", "Ctrl+Tab", 0));
        actionPrevious->setText(QApplication::translate("mainwindow", "\n"
"\345\211\215\344\270\200\344\270\252(&V)", 0));
#ifndef QT_NO_TOOLTIP
        actionPrevious->setToolTip(QApplication::translate("mainwindow", "\345\211\215\344\270\200\344\270\252", 0));
#endif // QT_NO_TOOLTIP
        actionPrevious->setShortcut(QApplication::translate("mainwindow", "Ctrl+Shift+Backtab", 0));
        actionAbout->setText(QApplication::translate("mainwindow", "\345\205\263\344\272\216(&A)", 0));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("mainwindow", "\345\205\263\344\272\216", 0));
#endif // QT_NO_TOOLTIP
        action_QtAboutQt->setText(QApplication::translate("mainwindow", "\345\205\263\344\272\216Qt(&Q)", 0));
#ifndef QT_NO_TOOLTIP
        action_QtAboutQt->setToolTip(QApplication::translate("mainwindow", "\345\205\263\344\272\216Qt", 0));
#endif // QT_NO_TOOLTIP
        menu_F->setTitle(QApplication::translate("mainwindow", "\346\226\207\344\273\266(&F)", 0));
        menu_E->setTitle(QApplication::translate("mainwindow", "\347\274\226\350\276\221(&E)", 0));
        menu_W->setTitle(QApplication::translate("mainwindow", "\347\252\227\345\217\243(&W)", 0));
        menu_H->setTitle(QApplication::translate("mainwindow", "\345\270\256\347\273\204(&H)", 0));
        toolBar->setWindowTitle(QApplication::translate("mainwindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class mainwindow: public Ui_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
