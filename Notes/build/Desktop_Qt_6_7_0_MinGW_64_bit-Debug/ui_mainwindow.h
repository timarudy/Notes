/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "noteslistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *newNoteBtn;
    QPushButton *removeNoteBtn;
    QSpacerItem *horizontalSpacer;
    QSplitter *splitter;
    NotesListWidget *notesListWidget;
    QTextEdit *textEdit;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        verticalLayout = new QVBoxLayout(MainWindow);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        newNoteBtn = new QPushButton(MainWindow);
        newNoteBtn->setObjectName("newNoteBtn");
        newNoteBtn->setMinimumSize(QSize(32, 32));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/plus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        newNoteBtn->setIcon(icon);

        horizontalLayout->addWidget(newNoteBtn);

        removeNoteBtn = new QPushButton(MainWindow);
        removeNoteBtn->setObjectName("removeNoteBtn");
        removeNoteBtn->setMinimumSize(QSize(32, 32));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/broom.svg"), QSize(), QIcon::Normal, QIcon::Off);
        removeNoteBtn->setIcon(icon1);

        horizontalLayout->addWidget(removeNoteBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 5);

        verticalLayout->addLayout(horizontalLayout);

        splitter = new QSplitter(MainWindow);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        splitter->setChildrenCollapsible(false);
        notesListWidget = new NotesListWidget(splitter);
        notesListWidget->setObjectName("notesListWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(notesListWidget->sizePolicy().hasHeightForWidth());
        notesListWidget->setSizePolicy(sizePolicy);
        splitter->addWidget(notesListWidget);
        textEdit = new QTextEdit(splitter);
        textEdit->setObjectName("textEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
        textEdit->setAutoFillBackground(false);
        textEdit->setStyleSheet(QString::fromUtf8("background-color: white;"));
        textEdit->setFrameShape(QFrame::NoFrame);
        splitter->addWidget(textEdit);

        verticalLayout->addWidget(splitter);

        verticalLayout->setStretch(1, 1);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        newNoteBtn->setText(QString());
        removeNoteBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
