/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *wField;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLCDNumber *num_high_score;
    QLabel *label_2;
    QLCDNumber *num_score;
    QLabel *label_3;
    QLCDNumber *num_level;
    QLabel *label_4;
    QLCDNumber *num_speed;
    QWidget *wNext_field;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_pause;
    QLabel *label_welcome;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 800);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        wField = new QWidget(centralwidget);
        wField->setObjectName(QString::fromUtf8("wField"));
        wField->setGeometry(QRect(10, 10, 370, 730));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(wField->sizePolicy().hasHeightForWidth());
        wField->setSizePolicy(sizePolicy);
        wField->setMinimumSize(QSize(370, 730));
        horizontalLayout_3 = new QHBoxLayout(wField);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 740, 571, 40));
        QFont font;
        font.setPointSize(10);
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(380, 540, 211, 21));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMaximumSize(QSize(50, 16777215));
        QFont font1;
        font1.setPointSize(12);
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_5);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(380, 10, 211, 471));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        verticalLayout->addWidget(label);

        num_high_score = new QLCDNumber(verticalLayoutWidget);
        num_high_score->setObjectName(QString::fromUtf8("num_high_score"));

        verticalLayout->addWidget(num_high_score);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        num_score = new QLCDNumber(verticalLayoutWidget);
        num_score->setObjectName(QString::fromUtf8("num_score"));

        verticalLayout->addWidget(num_score);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);

        num_level = new QLCDNumber(verticalLayoutWidget);
        num_level->setObjectName(QString::fromUtf8("num_level"));

        verticalLayout->addWidget(num_level);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setFrameShape(QFrame::NoFrame);
        label_4->setScaledContents(false);

        verticalLayout->addWidget(label_4);

        num_speed = new QLCDNumber(verticalLayoutWidget);
        num_speed->setObjectName(QString::fromUtf8("num_speed"));

        verticalLayout->addWidget(num_speed);

        wNext_field = new QWidget(centralwidget);
        wNext_field->setObjectName(QString::fromUtf8("wNext_field"));
        wNext_field->setGeometry(QRect(410, 570, 154, 154));
        sizePolicy.setHeightForWidth(wNext_field->sizePolicy().hasHeightForWidth());
        wNext_field->setSizePolicy(sizePolicy);
        wNext_field->setMinimumSize(QSize(50, 50));
        horizontalLayout_2 = new QHBoxLayout(wNext_field);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_pause = new QLabel(centralwidget);
        label_pause->setObjectName(QString::fromUtf8("label_pause"));
        label_pause->setGeometry(QRect(400, 490, 171, 41));
        label_pause->setFont(font1);
        label_pause->setFrameShape(QFrame::NoFrame);
        label_pause->setAlignment(Qt::AlignCenter);
        label_welcome = new QLabel(centralwidget);
        label_welcome->setObjectName(QString::fromUtf8("label_welcome"));
        label_welcome->setGeometry(QRect(6, 4, 591, 741));
        QFont font2;
        font2.setPointSize(18);
        label_welcome->setFont(font2);
        label_welcome->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CPP3_s21_brickgame", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "ENTER - Start, P - pause, Q - end game, SPACE - action, ARROWS - moving", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "High Score", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Score", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Level", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Speed", nullptr));
        label_pause->setText(QCoreApplication::translate("MainWindow", "PAUSE", nullptr));
        label_welcome->setText(QCoreApplication::translate("MainWindow", "WELCOME TO BRICK GAME\n"
"\n"
"PRESS ENTER TO START THE GAME\n"
"\n"
"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
