/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widgetOperations;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxRotate;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayoutRotate;
    QLabel *labelRotOx;
    QLineEdit *lineEditRotOx;
    QLabel *labelRotOy;
    QLineEdit *lineEditRotOy;
    QLabel *labelRotOz;
    QLineEdit *lineEditRotOz;
    QPushButton *pushButtonRotate;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBoxScale;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayoutScale;
    QLabel *labelScaleKx;
    QLineEdit *lineEditScaleKx;
    QLabel *labelScaleKy;
    QLineEdit *lineEditScaleKy;
    QLabel *labelScaleKz;
    QLineEdit *lineEditScaleKz;
    QPushButton *pushButtonScale;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBoxMoving;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayoutMoving;
    QLabel *labelMoveDx;
    QLineEdit *lineEditMoveDx;
    QLabel *labelMoveDy;
    QLineEdit *lineEditMoveDy;
    QLabel *labelMoveDz;
    QLineEdit *lineEditMoveDz;
    QPushButton *pushButtonMoving;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(512, 688);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widgetOperations = new QWidget(centralWidget);
        widgetOperations->setObjectName(QStringLiteral("widgetOperations"));
        verticalLayout = new QVBoxLayout(widgetOperations);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBoxRotate = new QGroupBox(widgetOperations);
        groupBoxRotate->setObjectName(QStringLiteral("groupBoxRotate"));
        verticalLayout_2 = new QVBoxLayout(groupBoxRotate);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayoutRotate = new QHBoxLayout();
        horizontalLayoutRotate->setSpacing(6);
        horizontalLayoutRotate->setObjectName(QStringLiteral("horizontalLayoutRotate"));
        labelRotOx = new QLabel(groupBoxRotate);
        labelRotOx->setObjectName(QStringLiteral("labelRotOx"));

        horizontalLayoutRotate->addWidget(labelRotOx);

        lineEditRotOx = new QLineEdit(groupBoxRotate);
        lineEditRotOx->setObjectName(QStringLiteral("lineEditRotOx"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditRotOx->sizePolicy().hasHeightForWidth());
        lineEditRotOx->setSizePolicy(sizePolicy);
        lineEditRotOx->setMaximumSize(QSize(75, 16777215));

        horizontalLayoutRotate->addWidget(lineEditRotOx);

        labelRotOy = new QLabel(groupBoxRotate);
        labelRotOy->setObjectName(QStringLiteral("labelRotOy"));

        horizontalLayoutRotate->addWidget(labelRotOy);

        lineEditRotOy = new QLineEdit(groupBoxRotate);
        lineEditRotOy->setObjectName(QStringLiteral("lineEditRotOy"));
        sizePolicy.setHeightForWidth(lineEditRotOy->sizePolicy().hasHeightForWidth());
        lineEditRotOy->setSizePolicy(sizePolicy);
        lineEditRotOy->setMaximumSize(QSize(75, 16777215));

        horizontalLayoutRotate->addWidget(lineEditRotOy);

        labelRotOz = new QLabel(groupBoxRotate);
        labelRotOz->setObjectName(QStringLiteral("labelRotOz"));

        horizontalLayoutRotate->addWidget(labelRotOz);

        lineEditRotOz = new QLineEdit(groupBoxRotate);
        lineEditRotOz->setObjectName(QStringLiteral("lineEditRotOz"));
        sizePolicy.setHeightForWidth(lineEditRotOz->sizePolicy().hasHeightForWidth());
        lineEditRotOz->setSizePolicy(sizePolicy);
        lineEditRotOz->setMaximumSize(QSize(75, 16777215));

        horizontalLayoutRotate->addWidget(lineEditRotOz);


        verticalLayout_2->addLayout(horizontalLayoutRotate);

        pushButtonRotate = new QPushButton(groupBoxRotate);
        pushButtonRotate->setObjectName(QStringLiteral("pushButtonRotate"));
        sizePolicy.setHeightForWidth(pushButtonRotate->sizePolicy().hasHeightForWidth());
        pushButtonRotate->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(pushButtonRotate, 0, Qt::AlignHCenter);


        verticalLayout->addWidget(groupBoxRotate);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        groupBoxScale = new QGroupBox(widgetOperations);
        groupBoxScale->setObjectName(QStringLiteral("groupBoxScale"));
        verticalLayout_3 = new QVBoxLayout(groupBoxScale);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayoutScale = new QHBoxLayout();
        horizontalLayoutScale->setSpacing(6);
        horizontalLayoutScale->setObjectName(QStringLiteral("horizontalLayoutScale"));
        labelScaleKx = new QLabel(groupBoxScale);
        labelScaleKx->setObjectName(QStringLiteral("labelScaleKx"));

        horizontalLayoutScale->addWidget(labelScaleKx);

        lineEditScaleKx = new QLineEdit(groupBoxScale);
        lineEditScaleKx->setObjectName(QStringLiteral("lineEditScaleKx"));
        sizePolicy.setHeightForWidth(lineEditScaleKx->sizePolicy().hasHeightForWidth());
        lineEditScaleKx->setSizePolicy(sizePolicy);
        lineEditScaleKx->setMaximumSize(QSize(75, 16777215));

        horizontalLayoutScale->addWidget(lineEditScaleKx);

        labelScaleKy = new QLabel(groupBoxScale);
        labelScaleKy->setObjectName(QStringLiteral("labelScaleKy"));

        horizontalLayoutScale->addWidget(labelScaleKy);

        lineEditScaleKy = new QLineEdit(groupBoxScale);
        lineEditScaleKy->setObjectName(QStringLiteral("lineEditScaleKy"));
        sizePolicy.setHeightForWidth(lineEditScaleKy->sizePolicy().hasHeightForWidth());
        lineEditScaleKy->setSizePolicy(sizePolicy);
        lineEditScaleKy->setMaximumSize(QSize(75, 16777215));

        horizontalLayoutScale->addWidget(lineEditScaleKy);

        labelScaleKz = new QLabel(groupBoxScale);
        labelScaleKz->setObjectName(QStringLiteral("labelScaleKz"));

        horizontalLayoutScale->addWidget(labelScaleKz);

        lineEditScaleKz = new QLineEdit(groupBoxScale);
        lineEditScaleKz->setObjectName(QStringLiteral("lineEditScaleKz"));
        sizePolicy.setHeightForWidth(lineEditScaleKz->sizePolicy().hasHeightForWidth());
        lineEditScaleKz->setSizePolicy(sizePolicy);
        lineEditScaleKz->setMaximumSize(QSize(75, 16777215));

        horizontalLayoutScale->addWidget(lineEditScaleKz);


        verticalLayout_3->addLayout(horizontalLayoutScale);

        pushButtonScale = new QPushButton(groupBoxScale);
        pushButtonScale->setObjectName(QStringLiteral("pushButtonScale"));
        sizePolicy.setHeightForWidth(pushButtonScale->sizePolicy().hasHeightForWidth());
        pushButtonScale->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButtonScale, 0, Qt::AlignHCenter);


        verticalLayout->addWidget(groupBoxScale);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        groupBoxMoving = new QGroupBox(widgetOperations);
        groupBoxMoving->setObjectName(QStringLiteral("groupBoxMoving"));
        verticalLayout_4 = new QVBoxLayout(groupBoxMoving);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayoutMoving = new QHBoxLayout();
        horizontalLayoutMoving->setSpacing(6);
        horizontalLayoutMoving->setObjectName(QStringLiteral("horizontalLayoutMoving"));
        labelMoveDx = new QLabel(groupBoxMoving);
        labelMoveDx->setObjectName(QStringLiteral("labelMoveDx"));

        horizontalLayoutMoving->addWidget(labelMoveDx);

        lineEditMoveDx = new QLineEdit(groupBoxMoving);
        lineEditMoveDx->setObjectName(QStringLiteral("lineEditMoveDx"));
        sizePolicy.setHeightForWidth(lineEditMoveDx->sizePolicy().hasHeightForWidth());
        lineEditMoveDx->setSizePolicy(sizePolicy);
        lineEditMoveDx->setMaximumSize(QSize(75, 16777215));

        horizontalLayoutMoving->addWidget(lineEditMoveDx);

        labelMoveDy = new QLabel(groupBoxMoving);
        labelMoveDy->setObjectName(QStringLiteral("labelMoveDy"));

        horizontalLayoutMoving->addWidget(labelMoveDy);

        lineEditMoveDy = new QLineEdit(groupBoxMoving);
        lineEditMoveDy->setObjectName(QStringLiteral("lineEditMoveDy"));
        sizePolicy.setHeightForWidth(lineEditMoveDy->sizePolicy().hasHeightForWidth());
        lineEditMoveDy->setSizePolicy(sizePolicy);
        lineEditMoveDy->setMaximumSize(QSize(75, 16777215));

        horizontalLayoutMoving->addWidget(lineEditMoveDy);

        labelMoveDz = new QLabel(groupBoxMoving);
        labelMoveDz->setObjectName(QStringLiteral("labelMoveDz"));

        horizontalLayoutMoving->addWidget(labelMoveDz);

        lineEditMoveDz = new QLineEdit(groupBoxMoving);
        lineEditMoveDz->setObjectName(QStringLiteral("lineEditMoveDz"));
        sizePolicy.setHeightForWidth(lineEditMoveDz->sizePolicy().hasHeightForWidth());
        lineEditMoveDz->setSizePolicy(sizePolicy);
        lineEditMoveDz->setMaximumSize(QSize(75, 16777215));

        horizontalLayoutMoving->addWidget(lineEditMoveDz);


        verticalLayout_4->addLayout(horizontalLayoutMoving);

        pushButtonMoving = new QPushButton(groupBoxMoving);
        pushButtonMoving->setObjectName(QStringLiteral("pushButtonMoving"));
        sizePolicy.setHeightForWidth(pushButtonMoving->sizePolicy().hasHeightForWidth());
        pushButtonMoving->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(pushButtonMoving, 0, Qt::AlignHCenter);


        verticalLayout->addWidget(groupBoxMoving);


        horizontalLayout->addWidget(widgetOperations);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 512, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionOpen);
        menu->addAction(actionSave);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214", Q_NULLPTR));
        groupBoxRotate->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", Q_NULLPTR));
        labelRotOx->setText(QApplication::translate("MainWindow", "ox:", Q_NULLPTR));
        labelRotOy->setText(QApplication::translate("MainWindow", "oy:", Q_NULLPTR));
        labelRotOz->setText(QApplication::translate("MainWindow", "oz:", Q_NULLPTR));
        pushButtonRotate->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", Q_NULLPTR));
        groupBoxScale->setTitle(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", Q_NULLPTR));
        labelScaleKx->setText(QApplication::translate("MainWindow", "kx:", Q_NULLPTR));
        labelScaleKy->setText(QApplication::translate("MainWindow", "ky:", Q_NULLPTR));
        labelScaleKz->setText(QApplication::translate("MainWindow", "kz:", Q_NULLPTR));
        pushButtonScale->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        groupBoxMoving->setTitle(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201", Q_NULLPTR));
        labelMoveDx->setText(QApplication::translate("MainWindow", "dx:", Q_NULLPTR));
        labelMoveDy->setText(QApplication::translate("MainWindow", "dy:", Q_NULLPTR));
        labelMoveDz->setText(QApplication::translate("MainWindow", "dz:", Q_NULLPTR));
        pushButtonMoving->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
