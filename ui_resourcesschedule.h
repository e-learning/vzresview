/********************************************************************************
** Form generated from reading UI file 'resourcesschedule.ui'
**
** Created: Mon Nov 28 18:04:40 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESOURCESSCHEDULE_H
#define UI_RESOURCESSCHEDULE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_ResourcesSchedule
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *VEBox;
    QComboBox *ResourceBox;
    QLabel *label_2;
    QGroupBox *speed;
    QGridLayout *gridLayout_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QwtPlot *schedulePlot;
    QPushButton *StartButton;
    QPushButton *StopButton;

    void setupUi(QWidget *ResourcesSchedule)
    {
        if (ResourcesSchedule->objectName().isEmpty())
            ResourcesSchedule->setObjectName(QString::fromUtf8("ResourcesSchedule"));
        ResourcesSchedule->resize(553, 388);
        gridLayout_2 = new QGridLayout(ResourcesSchedule);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ResourcesSchedule);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        VEBox = new QComboBox(ResourcesSchedule);
        VEBox->setObjectName(QString::fromUtf8("VEBox"));

        gridLayout->addWidget(VEBox, 0, 1, 1, 1);

        ResourceBox = new QComboBox(ResourcesSchedule);
        ResourceBox->setObjectName(QString::fromUtf8("ResourceBox"));

        gridLayout->addWidget(ResourceBox, 1, 1, 1, 1);

        label_2 = new QLabel(ResourcesSchedule);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        speed = new QGroupBox(ResourcesSchedule);
        speed->setObjectName(QString::fromUtf8("speed"));
        gridLayout_3 = new QGridLayout(speed);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        radioButton = new QRadioButton(speed);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout_3->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(speed);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setChecked(true);

        gridLayout_3->addWidget(radioButton_2, 0, 1, 1, 1);


        gridLayout_2->addWidget(speed, 0, 1, 1, 1);

        schedulePlot = new QwtPlot(ResourcesSchedule);
        schedulePlot->setObjectName(QString::fromUtf8("schedulePlot"));

        gridLayout_2->addWidget(schedulePlot, 5, 0, 1, 2);

        StartButton = new QPushButton(ResourcesSchedule);
        StartButton->setObjectName(QString::fromUtf8("StartButton"));

        gridLayout_2->addWidget(StartButton, 6, 0, 1, 1);

        StopButton = new QPushButton(ResourcesSchedule);
        StopButton->setObjectName(QString::fromUtf8("StopButton"));

        gridLayout_2->addWidget(StopButton, 6, 1, 1, 1);


        retranslateUi(ResourcesSchedule);

        QMetaObject::connectSlotsByName(ResourcesSchedule);
    } // setupUi

    void retranslateUi(QWidget *ResourcesSchedule)
    {
        ResourcesSchedule->setWindowTitle(QApplication::translate("ResourcesSchedule", "ResourcesSchedule", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ResourcesSchedule", "VE:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ResourcesSchedule", "Resource", 0, QApplication::UnicodeUTF8));
        speed->setTitle(QApplication::translate("ResourcesSchedule", "Speed", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("ResourcesSchedule", "500", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("ResourcesSchedule", "1000", 0, QApplication::UnicodeUTF8));
        StartButton->setText(QApplication::translate("ResourcesSchedule", "Start", 0, QApplication::UnicodeUTF8));
        StopButton->setText(QApplication::translate("ResourcesSchedule", "Stop", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ResourcesSchedule: public Ui_ResourcesSchedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESOURCESSCHEDULE_H
