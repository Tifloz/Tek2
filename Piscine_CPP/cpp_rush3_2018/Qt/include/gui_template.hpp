/*
** EPITECH PROJECT, 2022
** MyGKrellm
** File description:
** Created by Florian Louvet,
*/
#ifndef MYGKRELLMGWJSXQ_H
#define MYGKRELLMGWJSXQ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
    public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_4;
    QCheckBox *checkBox;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(799, 589);
        MainWindow->setMinimumSize(QSize(799, 589));
        MainWindow->setAutoFillBackground(true);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 311, 251));
        groupBox->setMouseTracking(false);
        groupBox->setLayoutDirection(Qt::LeftToRight);
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setCheckable(false);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(480, 10, 311, 251));
        groupBox_2->setMouseTracking(false);
        groupBox_2->setLayoutDirection(Qt::LeftToRight);
        groupBox_2->setAlignment(Qt::AlignCenter);
        groupBox_2->setCheckable(false);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 300, 311, 251));
        groupBox_3->setMouseTracking(false);
        groupBox_3->setLayoutDirection(Qt::LeftToRight);
        groupBox_3->setAlignment(Qt::AlignCenter);
        groupBox_3->setCheckable(false);
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(480, 300, 311, 251));
        groupBox_4->setMouseTracking(false);
        groupBox_4->setLayoutDirection(Qt::LeftToRight);
        groupBox_4->setAlignment(Qt::AlignCenter);
        groupBox_4->setFlat(false);
        groupBox_4->setCheckable(false);
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(140, 10, 71, 21));
        checkBox->setChecked(true);
        checkBox->setTristate(false);
        checkBox_3 = new QCheckBox(centralwidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(610, 300, 71, 21));
        checkBox_3->setChecked(true);
        checkBox_3->setTristate(false);
        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(620, 10, 71, 21));
        checkBox_2->setChecked(true);
        checkBox_2->setTristate(false);
        checkBox_4 = new QCheckBox(centralwidget);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(150, 300, 71, 21));
        checkBox_4->setChecked(true);
        checkBox_4->setTristate(false);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(qtTrId(""));
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QString());
        groupBox_4->setTitle(QString());
        checkBox->setText(qtTrId("System"));
        checkBox_3->setText(qtTrId("RAM"));
        checkBox_2->setText(qtTrId("CPU"));
        checkBox_4->setText(qtTrId("Network"));
    } // retranslateUi

};

namespace Ui {
    class MainWindow : public Ui_MainWindow {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // MYGKRELLMGWJSXQ_H