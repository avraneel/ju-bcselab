/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <my_label.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    my_label *frame;
    QLabel *mouse_movement;
    QLabel *label_3;
    QLabel *mouse_pressed;
    QLabel *label_5;
    QFrame *x_axis;
    QFrame *y_axis;
    QCheckBox *show_axes;
    QPushButton *Draw;
    QSpinBox *circle_radius;
    QRadioButton *draw_circle;
    QRadioButton *draw_line;
    QPushButton *set_point1;
    QPushButton *set_point2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpinBox *spinBox;
    QPushButton *set_p1;
    QPushButton *set_p2;
    QPushButton *draw_DDA;
    QPushButton *draw_Bresenham;
    QCheckBox *axes;
    QLabel *DDA_Time;
    QLabel *Bresenham_Time;
    QSpinBox *radius;
    QPushButton *draw_Polar;
    QLabel *Polar_Time;
    QLabel *label;
    QPushButton *draw_Bresenhsam_mid_point;
    QLabel *Bresenham_mid_point_Time;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QSpinBox *rx;
    QSpinBox *ry;
    QPushButton *draw_Polar_Ellipse;
    QLabel *Polar_Time_Ellipse;
    QLabel *Bresenham_mid_point_Time_Ellipse;
    QPushButton *draw_Bresenhsam_mid_point_Ellipse;
    QPushButton *boundary_fill_4;
    QLabel *label_9;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1216, 736);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new my_label(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 700, 700));
        frame->setCursor(QCursor(Qt::CrossCursor));
        frame->setMouseTracking(true);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::Box);
        frame->setLineWidth(1);
        mouse_movement = new QLabel(centralWidget);
        mouse_movement->setObjectName(QString::fromUtf8("mouse_movement"));
        mouse_movement->setGeometry(QRect(720, 40, 111, 31));
        mouse_movement->setFrameShape(QFrame::Panel);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(710, 10, 141, 20));
        mouse_pressed = new QLabel(centralWidget);
        mouse_pressed->setObjectName(QString::fromUtf8("mouse_pressed"));
        mouse_pressed->setGeometry(QRect(720, 110, 111, 31));
        mouse_pressed->setFrameShape(QFrame::Panel);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(720, 80, 111, 20));
        x_axis = new QFrame(centralWidget);
        x_axis->setObjectName(QString::fromUtf8("x_axis"));
        x_axis->setGeometry(QRect(0, 225, 700, 1));
        x_axis->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 255);"));
        x_axis->setFrameShape(QFrame::HLine);
        x_axis->setFrameShadow(QFrame::Sunken);
        y_axis = new QFrame(centralWidget);
        y_axis->setObjectName(QString::fromUtf8("y_axis"));
        y_axis->setGeometry(QRect(225, 0, 1, 700));
        y_axis->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85, 255, 255);"));
        y_axis->setFrameShape(QFrame::VLine);
        y_axis->setFrameShadow(QFrame::Sunken);
        show_axes = new QCheckBox(centralWidget);
        show_axes->setObjectName(QString::fromUtf8("show_axes"));
        show_axes->setGeometry(QRect(1050, 40, 51, 16));
        Draw = new QPushButton(centralWidget);
        Draw->setObjectName(QString::fromUtf8("Draw"));
        Draw->setGeometry(QRect(890, 60, 61, 16));
        circle_radius = new QSpinBox(centralWidget);
        circle_radius->setObjectName(QString::fromUtf8("circle_radius"));
        circle_radius->setGeometry(QRect(1040, 60, 46, 20));
        draw_circle = new QRadioButton(centralWidget);
        draw_circle->setObjectName(QString::fromUtf8("draw_circle"));
        draw_circle->setGeometry(QRect(1040, 20, 61, 21));
        draw_line = new QRadioButton(centralWidget);
        draw_line->setObjectName(QString::fromUtf8("draw_line"));
        draw_line->setGeometry(QRect(920, 10, 81, 16));
        set_point1 = new QPushButton(centralWidget);
        set_point1->setObjectName(QString::fromUtf8("set_point1"));
        set_point1->setGeometry(QRect(1010, 0, 81, 23));
        set_point2 = new QPushButton(centralWidget);
        set_point2->setObjectName(QString::fromUtf8("set_point2"));
        set_point2->setGeometry(QRect(940, 30, 81, 23));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(970, 60, 61, 16));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(780, 190, 89, 25));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(720, 190, 44, 26));
        set_p1 = new QPushButton(centralWidget);
        set_p1->setObjectName(QString::fromUtf8("set_p1"));
        set_p1->setGeometry(QRect(720, 240, 89, 25));
        set_p2 = new QPushButton(centralWidget);
        set_p2->setObjectName(QString::fromUtf8("set_p2"));
        set_p2->setGeometry(QRect(720, 270, 89, 25));
        draw_DDA = new QPushButton(centralWidget);
        draw_DDA->setObjectName(QString::fromUtf8("draw_DDA"));
        draw_DDA->setGeometry(QRect(1030, 120, 89, 25));
        draw_Bresenham = new QPushButton(centralWidget);
        draw_Bresenham->setObjectName(QString::fromUtf8("draw_Bresenham"));
        draw_Bresenham->setGeometry(QRect(970, 160, 151, 25));
        axes = new QCheckBox(centralWidget);
        axes->setObjectName(QString::fromUtf8("axes"));
        axes->setGeometry(QRect(720, 150, 61, 23));
        DDA_Time = new QLabel(centralWidget);
        DDA_Time->setObjectName(QString::fromUtf8("DDA_Time"));
        DDA_Time->setGeometry(QRect(1130, 120, 71, 31));
        DDA_Time->setFrameShape(QFrame::Panel);
        Bresenham_Time = new QLabel(centralWidget);
        Bresenham_Time->setObjectName(QString::fromUtf8("Bresenham_Time"));
        Bresenham_Time->setGeometry(QRect(1130, 160, 71, 31));
        Bresenham_Time->setFrameShape(QFrame::Panel);
        radius = new QSpinBox(centralWidget);
        radius->setObjectName(QString::fromUtf8("radius"));
        radius->setGeometry(QRect(1130, 250, 44, 26));
        draw_Polar = new QPushButton(centralWidget);
        draw_Polar->setObjectName(QString::fromUtf8("draw_Polar"));
        draw_Polar->setGeometry(QRect(1030, 290, 91, 31));
        Polar_Time = new QLabel(centralWidget);
        Polar_Time->setObjectName(QString::fromUtf8("Polar_Time"));
        Polar_Time->setGeometry(QRect(1130, 290, 71, 31));
        Polar_Time->setFrameShape(QFrame::Panel);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1060, 250, 51, 21));
        draw_Bresenhsam_mid_point = new QPushButton(centralWidget);
        draw_Bresenhsam_mid_point->setObjectName(QString::fromUtf8("draw_Bresenhsam_mid_point"));
        draw_Bresenhsam_mid_point->setGeometry(QRect(930, 330, 191, 31));
        Bresenham_mid_point_Time = new QLabel(centralWidget);
        Bresenham_mid_point_Time->setObjectName(QString::fromUtf8("Bresenham_mid_point_Time"));
        Bresenham_mid_point_Time->setGeometry(QRect(1130, 330, 71, 31));
        Bresenham_mid_point_Time->setFrameShape(QFrame::Panel);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1110, 210, 81, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1130, 90, 67, 17));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1110, 400, 67, 17));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1130, 430, 21, 21));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(1030, 430, 21, 21));
        rx = new QSpinBox(centralWidget);
        rx->setObjectName(QString::fromUtf8("rx"));
        rx->setGeometry(QRect(1060, 430, 44, 26));
        ry = new QSpinBox(centralWidget);
        ry->setObjectName(QString::fromUtf8("ry"));
        ry->setGeometry(QRect(1160, 430, 44, 26));
        draw_Polar_Ellipse = new QPushButton(centralWidget);
        draw_Polar_Ellipse->setObjectName(QString::fromUtf8("draw_Polar_Ellipse"));
        draw_Polar_Ellipse->setGeometry(QRect(1020, 480, 91, 31));
        Polar_Time_Ellipse = new QLabel(centralWidget);
        Polar_Time_Ellipse->setObjectName(QString::fromUtf8("Polar_Time_Ellipse"));
        Polar_Time_Ellipse->setGeometry(QRect(1120, 480, 71, 31));
        Polar_Time_Ellipse->setFrameShape(QFrame::Panel);
        Bresenham_mid_point_Time_Ellipse = new QLabel(centralWidget);
        Bresenham_mid_point_Time_Ellipse->setObjectName(QString::fromUtf8("Bresenham_mid_point_Time_Ellipse"));
        Bresenham_mid_point_Time_Ellipse->setGeometry(QRect(1120, 520, 71, 31));
        Bresenham_mid_point_Time_Ellipse->setFrameShape(QFrame::Panel);
        draw_Bresenhsam_mid_point_Ellipse = new QPushButton(centralWidget);
        draw_Bresenhsam_mid_point_Ellipse->setObjectName(QString::fromUtf8("draw_Bresenhsam_mid_point_Ellipse"));
        draw_Bresenhsam_mid_point_Ellipse->setGeometry(QRect(920, 520, 191, 31));
        boundary_fill_4 = new QPushButton(centralWidget);
        boundary_fill_4->setObjectName(QString::fromUtf8("boundary_fill_4"));
        boundary_fill_4->setGeometry(QRect(720, 400, 181, 31));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(720, 360, 67, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1216, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        frame->setText(QString());
        mouse_movement->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "    Mouse Movement", nullptr));
        mouse_pressed->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Mouse Pressed", nullptr));
        show_axes->setText(QCoreApplication::translate("MainWindow", "Show Axes", nullptr));
        Draw->setText(QCoreApplication::translate("MainWindow", "Draw", nullptr));
        draw_circle->setText(QCoreApplication::translate("MainWindow", "Draw Circle", nullptr));
        draw_line->setText(QCoreApplication::translate("MainWindow", "Draw Line", nullptr));
        set_point1->setText(QCoreApplication::translate("MainWindow", "Set point 1", nullptr));
        set_point2->setText(QCoreApplication::translate("MainWindow", "Set point 2", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Draw Grid", nullptr));
        set_p1->setText(QCoreApplication::translate("MainWindow", "Set P1", nullptr));
        set_p2->setText(QCoreApplication::translate("MainWindow", "Set P2", nullptr));
        draw_DDA->setText(QCoreApplication::translate("MainWindow", "Draw DDA", nullptr));
        draw_Bresenham->setText(QCoreApplication::translate("MainWindow", "Draw Bresenham", nullptr));
        axes->setText(QCoreApplication::translate("MainWindow", "Axes", nullptr));
        DDA_Time->setText(QString());
        Bresenham_Time->setText(QString());
        draw_Polar->setText(QCoreApplication::translate("MainWindow", "Draw Polar", nullptr));
        Polar_Time->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Radius", nullptr));
        draw_Bresenhsam_mid_point->setText(QCoreApplication::translate("MainWindow", "Draw Bresenham mid-point", nullptr));
        Bresenham_mid_point_Time->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Circle:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Line:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Ellipse:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Ry", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Rx", nullptr));
        draw_Polar_Ellipse->setText(QCoreApplication::translate("MainWindow", "Draw Polar", nullptr));
        Polar_Time_Ellipse->setText(QString());
        Bresenham_mid_point_Time_Ellipse->setText(QString());
        draw_Bresenhsam_mid_point_Ellipse->setText(QCoreApplication::translate("MainWindow", "Draw Bresenham mid-point", nullptr));
        boundary_fill_4->setText(QCoreApplication::translate("MainWindow", "Boundary Fill 4 connected", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Filling:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
