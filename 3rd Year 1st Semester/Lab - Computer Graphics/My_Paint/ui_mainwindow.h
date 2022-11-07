/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QPushButton *boundary_fill_4;
    QLabel *label_9;
    QLabel *boundary_fill_4_time;
    QPushButton *flood_fill;
    QLabel *flood_fill_time;
    QLabel *Polar_Time_Ellipse;
    QLabel *label_6;
    QSpinBox *ry;
    QSpinBox *rx;
    QLabel *label_8;
    QLabel *Bresenham_mid_point_Time_Ellipse;
    QPushButton *draw_Polar_Ellipse;
    QPushButton *draw_Bresenhsam_mid_point_Ellipse;
    QLabel *label_7;
    QPushButton *store_to_stack;
    QPushButton *boundary_8;
    QPushButton *flood_8;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_17;
    QLabel *label_18;
    QPushButton *rotate;
    QPushButton *shear;
    QDoubleSpinBox *scaling_y;
    QLabel *label_10;
    QPushButton *reflect_y;
    QSpinBox *shearing_y;
    QSpinBox *shearing_x;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_15;
    QSpinBox *translation_y;
    QLabel *label_16;
    QPushButton *scale;
    QSpinBox *translation_x;
    QSpinBox *rotation_degree;
    QPushButton *reflect_x;
    QLabel *label_13;
    QDoubleSpinBox *scaling_x;
    QPushButton *translate;
    QPushButton *scanline_fill;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1243, 765);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new my_label(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 700, 701));
        frame->setCursor(QCursor(Qt::CrossCursor));
        frame->setMouseTracking(true);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::Box);
        frame->setLineWidth(1);
        mouse_movement = new QLabel(centralWidget);
        mouse_movement->setObjectName(QString::fromUtf8("mouse_movement"));
        mouse_movement->setGeometry(QRect(720, 30, 111, 31));
        mouse_movement->setFrameShape(QFrame::Panel);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(710, 10, 121, 20));
        mouse_pressed = new QLabel(centralWidget);
        mouse_pressed->setObjectName(QString::fromUtf8("mouse_pressed"));
        mouse_pressed->setGeometry(QRect(720, 100, 111, 31));
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
        draw_DDA->setGeometry(QRect(1010, 390, 89, 25));
        draw_Bresenham = new QPushButton(centralWidget);
        draw_Bresenham->setObjectName(QString::fromUtf8("draw_Bresenham"));
        draw_Bresenham->setGeometry(QRect(990, 430, 111, 25));
        axes = new QCheckBox(centralWidget);
        axes->setObjectName(QString::fromUtf8("axes"));
        axes->setGeometry(QRect(720, 150, 61, 23));
        DDA_Time = new QLabel(centralWidget);
        DDA_Time->setObjectName(QString::fromUtf8("DDA_Time"));
        DDA_Time->setGeometry(QRect(1110, 380, 71, 31));
        DDA_Time->setFrameShape(QFrame::Panel);
        Bresenham_Time = new QLabel(centralWidget);
        Bresenham_Time->setObjectName(QString::fromUtf8("Bresenham_Time"));
        Bresenham_Time->setGeometry(QRect(1110, 420, 71, 31));
        Bresenham_Time->setFrameShape(QFrame::Panel);
        radius = new QSpinBox(centralWidget);
        radius->setObjectName(QString::fromUtf8("radius"));
        radius->setGeometry(QRect(1140, 40, 44, 26));
        draw_Polar = new QPushButton(centralWidget);
        draw_Polar->setObjectName(QString::fromUtf8("draw_Polar"));
        draw_Polar->setGeometry(QRect(1020, 80, 91, 31));
        Polar_Time = new QLabel(centralWidget);
        Polar_Time->setObjectName(QString::fromUtf8("Polar_Time"));
        Polar_Time->setGeometry(QRect(1120, 80, 71, 31));
        Polar_Time->setFrameShape(QFrame::Panel);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1100, 40, 51, 21));
        draw_Bresenhsam_mid_point = new QPushButton(centralWidget);
        draw_Bresenhsam_mid_point->setObjectName(QString::fromUtf8("draw_Bresenhsam_mid_point"));
        draw_Bresenhsam_mid_point->setGeometry(QRect(920, 120, 191, 31));
        Bresenham_mid_point_Time = new QLabel(centralWidget);
        Bresenham_mid_point_Time->setObjectName(QString::fromUtf8("Bresenham_mid_point_Time"));
        Bresenham_mid_point_Time->setGeometry(QRect(1120, 120, 71, 31));
        Bresenham_mid_point_Time->setFrameShape(QFrame::Panel);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1120, 10, 41, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1080, 350, 67, 17));
        boundary_fill_4 = new QPushButton(centralWidget);
        boundary_fill_4->setObjectName(QString::fromUtf8("boundary_fill_4"));
        boundary_fill_4->setGeometry(QRect(720, 380, 81, 31));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(720, 350, 67, 17));
        boundary_fill_4_time = new QLabel(centralWidget);
        boundary_fill_4_time->setObjectName(QString::fromUtf8("boundary_fill_4_time"));
        boundary_fill_4_time->setEnabled(true);
        boundary_fill_4_time->setGeometry(QRect(810, 380, 61, 31));
        boundary_fill_4_time->setFrameShape(QFrame::Panel);
        flood_fill = new QPushButton(centralWidget);
        flood_fill->setObjectName(QString::fromUtf8("flood_fill"));
        flood_fill->setGeometry(QRect(720, 420, 81, 31));
        flood_fill_time = new QLabel(centralWidget);
        flood_fill_time->setObjectName(QString::fromUtf8("flood_fill_time"));
        flood_fill_time->setGeometry(QRect(810, 420, 61, 31));
        flood_fill_time->setFrameShape(QFrame::Box);
        Polar_Time_Ellipse = new QLabel(centralWidget);
        Polar_Time_Ellipse->setObjectName(QString::fromUtf8("Polar_Time_Ellipse"));
        Polar_Time_Ellipse->setGeometry(QRect(1120, 260, 71, 31));
        Polar_Time_Ellipse->setFrameShape(QFrame::Panel);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1080, 180, 67, 17));
        ry = new QSpinBox(centralWidget);
        ry->setObjectName(QString::fromUtf8("ry"));
        ry->setGeometry(QRect(1160, 210, 44, 26));
        rx = new QSpinBox(centralWidget);
        rx->setObjectName(QString::fromUtf8("rx"));
        rx->setGeometry(QRect(1070, 210, 44, 26));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(1040, 210, 21, 21));
        Bresenham_mid_point_Time_Ellipse = new QLabel(centralWidget);
        Bresenham_mid_point_Time_Ellipse->setObjectName(QString::fromUtf8("Bresenham_mid_point_Time_Ellipse"));
        Bresenham_mid_point_Time_Ellipse->setGeometry(QRect(1120, 300, 71, 31));
        Bresenham_mid_point_Time_Ellipse->setFrameShape(QFrame::Panel);
        draw_Polar_Ellipse = new QPushButton(centralWidget);
        draw_Polar_Ellipse->setObjectName(QString::fromUtf8("draw_Polar_Ellipse"));
        draw_Polar_Ellipse->setGeometry(QRect(1020, 260, 91, 31));
        draw_Bresenhsam_mid_point_Ellipse = new QPushButton(centralWidget);
        draw_Bresenhsam_mid_point_Ellipse->setObjectName(QString::fromUtf8("draw_Bresenhsam_mid_point_Ellipse"));
        draw_Bresenhsam_mid_point_Ellipse->setGeometry(QRect(920, 300, 191, 31));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1130, 210, 21, 21));
        store_to_stack = new QPushButton(centralWidget);
        store_to_stack->setObjectName(QString::fromUtf8("store_to_stack"));
        store_to_stack->setGeometry(QRect(720, 310, 91, 31));
        boundary_8 = new QPushButton(centralWidget);
        boundary_8->setObjectName(QString::fromUtf8("boundary_8"));
        boundary_8->setGeometry(QRect(880, 380, 81, 31));
        flood_8 = new QPushButton(centralWidget);
        flood_8->setObjectName(QString::fromUtf8("flood_8"));
        flood_8->setGeometry(QRect(880, 420, 71, 31));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(720, 600, 21, 21));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(720, 630, 21, 16));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(810, 630, 21, 16));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(910, 600, 21, 21));
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(990, 570, 61, 16));
        rotate = new QPushButton(centralWidget);
        rotate->setObjectName(QString::fromUtf8("rotate"));
        rotate->setGeometry(QRect(910, 630, 61, 24));
        shear = new QPushButton(centralWidget);
        shear->setObjectName(QString::fromUtf8("shear"));
        shear->setGeometry(QRect(990, 660, 61, 21));
        scaling_y = new QDoubleSpinBox(centralWidget);
        scaling_y->setObjectName(QString::fromUtf8("scaling_y"));
        scaling_y->setGeometry(QRect(830, 630, 62, 22));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(720, 570, 71, 20));
        reflect_y = new QPushButton(centralWidget);
        reflect_y->setObjectName(QString::fromUtf8("reflect_y"));
        reflect_y->setGeometry(QRect(1070, 630, 75, 24));
        shearing_y = new QSpinBox(centralWidget);
        shearing_y->setObjectName(QString::fromUtf8("shearing_y"));
        shearing_y->setGeometry(QRect(1010, 630, 42, 22));
        shearing_x = new QSpinBox(centralWidget);
        shearing_x->setObjectName(QString::fromUtf8("shearing_x"));
        shearing_x->setGeometry(QRect(1010, 600, 42, 22));
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(990, 600, 21, 21));
        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(990, 630, 21, 16));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(810, 600, 21, 21));
        translation_y = new QSpinBox(centralWidget);
        translation_y->setObjectName(QString::fromUtf8("translation_y"));
        translation_y->setGeometry(QRect(750, 630, 42, 22));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(910, 570, 71, 16));
        scale = new QPushButton(centralWidget);
        scale->setObjectName(QString::fromUtf8("scale"));
        scale->setGeometry(QRect(820, 660, 61, 24));
        translation_x = new QSpinBox(centralWidget);
        translation_x->setObjectName(QString::fromUtf8("translation_x"));
        translation_x->setGeometry(QRect(750, 600, 42, 22));
        rotation_degree = new QSpinBox(centralWidget);
        rotation_degree->setObjectName(QString::fromUtf8("rotation_degree"));
        rotation_degree->setGeometry(QRect(930, 600, 42, 22));
        reflect_x = new QPushButton(centralWidget);
        reflect_x->setObjectName(QString::fromUtf8("reflect_x"));
        reflect_x->setGeometry(QRect(1070, 600, 75, 24));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(820, 570, 49, 16));
        scaling_x = new QDoubleSpinBox(centralWidget);
        scaling_x->setObjectName(QString::fromUtf8("scaling_x"));
        scaling_x->setGeometry(QRect(830, 600, 62, 22));
        translate = new QPushButton(centralWidget);
        translate->setObjectName(QString::fromUtf8("translate"));
        translate->setGeometry(QRect(720, 660, 75, 24));
        scanline_fill = new QPushButton(centralWidget);
        scanline_fill->setObjectName(QString::fromUtf8("scanline_fill"));
        scanline_fill->setGeometry(QRect(720, 460, 81, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1243, 21));
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
        boundary_fill_4->setText(QCoreApplication::translate("MainWindow", "Boundary 4", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Filling:", nullptr));
        boundary_fill_4_time->setText(QString());
        flood_fill->setText(QCoreApplication::translate("MainWindow", "Flood 4", nullptr));
        flood_fill_time->setText(QString());
        Polar_Time_Ellipse->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "Ellipse:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Rx", nullptr));
        Bresenham_mid_point_Time_Ellipse->setText(QString());
        draw_Polar_Ellipse->setText(QCoreApplication::translate("MainWindow", "Draw Polar", nullptr));
        draw_Bresenhsam_mid_point_Ellipse->setText(QCoreApplication::translate("MainWindow", "Draw Bresenham mid-point", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Ry", nullptr));
        store_to_stack->setText(QCoreApplication::translate("MainWindow", "Store to Stack", nullptr));
        boundary_8->setText(QCoreApplication::translate("MainWindow", "Boundary 8", nullptr));
        flood_8->setText(QCoreApplication::translate("MainWindow", "Flood 8", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "D:", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Shearing:", nullptr));
        rotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        shear->setText(QCoreApplication::translate("MainWindow", "Shear", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Translation:", nullptr));
        reflect_y->setText(QCoreApplication::translate("MainWindow", "Reflect Y", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Rotation:", nullptr));
        scale->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        reflect_x->setText(QCoreApplication::translate("MainWindow", "Reflect X", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Scaling:", nullptr));
        translate->setText(QCoreApplication::translate("MainWindow", "Translate", nullptr));
        scanline_fill->setText(QCoreApplication::translate("MainWindow", "Scanline", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
