#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QImage>
#include <iostream>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintDevice>
#include <QPoint>
#include <cmath>
#include <math.h>
#include <iostream>
#include <chrono>
#include <QThread>
using namespace std::chrono;
using namespace std;

QImage img=QImage(700,700,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->x_axis->hide();
    ui->y_axis->hide();
    connect(ui->frame,SIGNAL(Mouse_Pos()),this,SLOT(Mouse_Pressed()));
    connect(ui->frame,SIGNAL(sendMousePosition(QPoint&)),this,SLOT(showMousePosition(QPoint&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::point(int x,int y, QColor c)
{
    int gs = ui->spinBox->value() + 1;
    QPainter painter(&img);
    QPen pen;
    pen.setWidth(gs);
    pen.setColor(c);
    painter.setPen(pen);
    painter.fillRect((x/gs)*gs+1, (y/gs)*gs+1, gs, gs, c);
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::showMousePosition(QPoint &pos)
{
    int gs = ui->spinBox->value() + 1;
    int x1 = (int)(pos.x()/gs - 350/gs);
    int y1 = (int)(350/gs - pos.y()/gs);
    ui->mouse_movement->setText(" X : "+QString::number(x1)+", Y : "+QString::number(y1));
}

void MainWindow::Mouse_Pressed()
{
    int gs = ui->spinBox->value() + 1;
    int x = ui->frame->x;
    int y = ui->frame->y;
    int new_x = (x-350);
    int new_y = (350-y);
    ui->mouse_pressed->setText(" X : "+QString::number(new_x/gs)+", Y : "+QString::number(new_y/gs));
    point(ui->frame->x,ui->frame->y, QColorConstants::White);
    ui->x_axis->move(0,ui->frame->y);
    ui->y_axis->move(ui->frame->x,0);
}

void MainWindow::on_show_axes_clicked()
{
    if(ui->show_axes->isChecked())
    {
        ui->x_axis->show();
        ui->y_axis->show();
    }
    else{
        ui->x_axis->hide();
        ui->y_axis->hide();
    }
}

void MainWindow::on_set_point1_clicked()
{
    if(ui->draw_line->isChecked()){
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);
    }
}

void MainWindow::on_set_point2_clicked()
{
    if(ui->draw_line->isChecked()){
        p2.setX(ui->frame->x);
        p2.setY(ui->frame->y);
    }
}

void MainWindow::on_Draw_clicked()
{
    int r0=ui->circle_radius->value();
    QPainter painter(&img);
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::red);
    if(ui->draw_circle->isChecked()){
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);
        painter.setPen(pen);
        painter.drawEllipse(p1,r0,r0);
    }
    if(ui->draw_line->isChecked()){
        painter.setPen(Qt::red);
        painter.drawLine(p1,p2);
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_clicked()
{
    for(int j=0;j<img.height();j++)
    {
        for(int i=0;i<img.width();i++)
        {
            img.setPixel(i,j,qRgb(0,0,0));
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_2_clicked()
{
       QPainter painter(&img);
       QPen pen;
       pen.setWidth(1);
       pen.setColor(Qt::red);
       p1.setY(0);
       p1.setX(0);
       p2.setY(700);
       p2.setX(0);

       int gs = ui->spinBox->value()+1;

       for(int i=1; i<=700;i+=gs)
       {
           p1.setX(i);
           p2.setX(i);
           painter.setPen(pen);
           painter.drawLine(p1,p2);
       }
       p1.setX(0);
       p1.setY(0);
       p2.setX(700);
       p2.setY(0);
       for(int i=1; i<=700;i+=gs)
       {
           p1.setY(i);
           p2.setY(i);
           painter.setPen(pen);
           painter.drawLine(p1,p2);
       }

       ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_spinBox_valueChanged()
{

        on_pushButton_clicked();
        on_pushButton_2_clicked();
        on_axes_stateChanged();
}

void MainWindow::on_set_p1_clicked()
{
      p1.setX(ui->frame->x);
      p1.setY(ui->frame->y);
}

void MainWindow::on_set_p2_clicked()
{
    p2.setX(ui->frame->x);
    p2.setY(ui->frame->y);
}

void MainWindow::on_draw_DDA_clicked()
{
    auto start = chrono::system_clock::now();
    DDA();
    auto end = chrono::system_clock::now();
    auto time_taken = chrono::duration_cast<milliseconds>(end-start).count();
    ui->DDA_Time->setText(QString::number(time_taken)+" ms");
}

void MainWindow::DDA()
{
    int gs = ui->spinBox->value()+1;
    float x0 = p1.x();
    float y0 = p1.y();
    float xn = p2.x();
    float yn = p2.y();
    float dx = float(xn - x0);
    float dy = float(yn - y0);
    float x = float(x0);
    float y = float(y0);
    float Dx, Dy;
    if(dx > dy) {
        Dx = gs;
        Dy = (dy/dx) * gs;
    }
    else {
        Dy = gs;
        Dx = (dx/dy) * gs;
    }
    int steps = int(dx > dy ? dx : dy);
    //cout << steps;
    for(int i = 0; i <= steps; i += gs) {
        ui->frame->repaint();
        QThread::msleep(100);
        point(x, y, Qt::blue);
        x += Dx;
        y += Dy;
        //cout << i << " ";
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_draw_Bresenham_clicked()
{
    auto start = chrono::system_clock::now();
    Bresenham();
    auto end = chrono::system_clock::now();
    auto time_taken = chrono::duration_cast<milliseconds>(end-start).count();
    ui->Bresenham_Time->setText(QString::number(time_taken)+" ms");

}

void MainWindow::Bresenham() {
    int gs = ui->spinBox->value()+1;
    float x0 = (int)p1.x()/gs;
    float y0 = (int)p1.y()/gs;
    float xn = (int)p2.x()/gs;
    float yn = (int)p2.y()/gs;
    float delx = fabs(xn - x0);
    float dely = fabs(yn - y0);
    float m = dely/delx;
    float x = x0;
    float y = y0;
    int p;
    double inc;
    if(m < 1) {
        p = (2*dely) - delx;
        for(int i = 0; i <= delx - 1; i ++) {
            if(p < 0)
                inc = 2*dely;
            else {
                if(yn > y0) {
                    y += 1;
                }
                else {
                    y -= 1;
                }
                inc = 2*(dely - delx);
            }
            if(xn > x0)
                x += 1;
            else
                x -= 1;
            p += inc;
            ui->frame->repaint();
            QThread::msleep(100);
            point(x*gs, y*gs, QColorConstants::Green);
         }
    }
    else {
        p = (2*delx) - dely;
        for(int i = 0; i <= dely - 1; i ++) {
            if(p < 0)
                inc = 2*delx;
            else {
                if(xn > x0) {
                    x += 1;
                }
                else {
                    x -= 1;
                }
                inc = 2*(delx - dely);
            }
            if(yn > y0)
                y += 1;
            else
                y -= 1;
            p += inc;
            ui->frame->repaint();
            QThread::msleep(100);
            point(x*gs, y*gs, QColorConstants::Green);
         }
     }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_axes_stateChanged()
{
    if(ui->axes->isChecked())
    {
        int gs = ui->spinBox->value()+1;
        for(int i = 0; i < 700; i+=gs)
        {
            point(350, i, Qt::red);
        }
        for(int i = 0; i < 700; i+=gs)
        {
            point(i, 350, Qt::red);
        }
    }
    else{
        on_pushButton_clicked();
        on_pushButton_2_clicked();
    }
}

void MainWindow::on_draw_Polar_clicked()
{
    auto start = chrono::system_clock::now();
    polar();
    auto end = chrono::system_clock::now();
    auto time_taken = chrono::duration_cast<milliseconds>(end-start).count();
    ui->Polar_Time->setText(QString::number(time_taken)+" ms");
}

void MainWindow::polar() {
    int gs = ui->spinBox->value()+1;
    int r = ui->radius->value();
    int xc = p1.x()/gs;
    int yc = p1.y()/gs;

    for(int i = 0; i < 30; i++) {
        int i2 = 30+i;
        int i3 = 60+i;
        int i4 = 90+i;
        int i5 = 120+i;
        int i6 = 150+i;
        int i7 = 180+i;
        int i8 = 210+i;
        int i9 = 240+i;
        int i10 = 270+i;
        int i11 = 300+i;
        int i12 = 330+i;
        double rad = (3.14/180)*i;
        double rd2 = (3.14/180)*i2;
        double rd3 = (3.14/180)*i3;
        double rd4 = (3.14/180)*i4;
        double rd5 = (3.14/180)*i5;
        double rd6 = (3.14/180)*i6;
        double rd7 = (3.14/180)*i7;
        double rd8 = (3.14/180)*i8;
        double rd9 = (3.14/180)*i9;
        double rd10 = (3.14/180)*i10;
        double rd11 = (3.14/180)*i11;
        double rd12 = (3.14/180)*i12;
        double x = round(xc + r*cos(rad));
        double y = round(yc + r*sin(rad));
        double x2 = round(xc + r*cos(rd2));
        double y2 = round(yc + r*sin(rd2));
        double x3 = round(xc + r*cos(rd3));
        double y3 = round(yc + r*sin(rd3));
        double x4 = round(xc + r*cos(rd4));
        double y4 = round(yc + r*sin(rd4));
        double x5 = round(xc + r*cos(rd5));
        double y5 = round(yc + r*sin(rd5));
        double x6 = round(xc + r*cos(rd6));
        double y6 = round(yc + r*sin(rd6));
        double x7 = round(xc + r*cos(rd7));
        double y7 = round(yc + r*sin(rd7));
        double x8 = round(xc + r*cos(rd8));
        double y8 = round(yc + r*sin(rd8));
        double x9 = round(xc + r*cos(rd9));
        double y9 = round(yc + r*sin(rd9));
        double x10 = round(xc + r*cos(rd10));
        double y10 = round(yc + r*sin(rd10));
        double x11 = round(xc + r*cos(rd11));
        double y11 = round(yc + r*sin(rd11));
        double x12 = round(xc + r*cos(rd12));
        double y12 = round(yc + r*sin(rd12));
        point(x*gs, y*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x2*gs, y2*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x3*gs, y3*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x4*gs, y4*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x5*gs, y5*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x6*gs, y6*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x7*gs, y7*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x8*gs, y8*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x9*gs, y9*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x10*gs, y10*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x11*gs, y11*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x12*gs, y12*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_draw_Bresenhsam_mid_point_clicked()
{
    auto start = chrono::system_clock::now();
    Bresenham_mid_point();
    auto end = chrono::system_clock::now();
    auto time_taken = chrono::duration_cast<milliseconds>(end-start).count();
    ui->Bresenham_mid_point_Time->setText(QString::number(time_taken)+" ms");
}

void MainWindow::Bresenham_mid_point() {
    int gs = ui->spinBox->value()+1;
    int r = ui->radius->value();
    int xc = p1.x()/gs;
    int yc = p1.y()/gs;
    int p = 1 - r;
    int x = 0;
    int y = r;
    // Plotting N,E,W,S
    point(xc*gs, (r + yc)*gs, QColorConstants::DarkYellow);
    //ui->frame->update();
    ui->frame->repaint();
    QThread::msleep(200);
    point((xc + r)*gs, yc*gs, QColorConstants::DarkYellow);
    //ui->frame->update();
    ui->frame->repaint();
    QThread::msleep(200);
    point(xc*gs, (yc - r)*gs, QColorConstants::DarkYellow);
    //ui->frame->update();
    ui->frame->repaint();
    QThread::msleep(200);
    point((xc - r)*gs, yc*gs, QColorConstants::DarkYellow);
    ui->frame->repaint();
    QThread::msleep(200);
    while(y > x) {
        if(p < 0)
            p += 2*x + 3;
        else {
            y -= 1;
            p += 2*(x-y) + 5;
        }
        x += 1;
        // Symmetry
        int x2 = y; int y2 = x;
        int x3 = x; int y3 = -y;
        int x4 = y; int y4 = -x;
        int x5 = -y; int y5 = -x;
        int x6 = -x; int y6 = -y;
        int x7 = -x; int y7 = y;
        int x8 = -y; int y8 = x;
        point(x*gs + xc*gs, y*gs + yc*gs, QColorConstants::DarkYellow);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x2*gs + xc*gs, y2*gs + yc*gs, QColorConstants::DarkYellow);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x3*gs + xc*gs, y3*gs + yc*gs, QColorConstants::DarkYellow);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x4*gs + xc*gs, y4*gs + yc*gs, QColorConstants::DarkYellow);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x5*gs + xc*gs, y5*gs + yc*gs, QColorConstants::DarkYellow);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x6*gs + xc*gs, y6*gs + yc*gs, QColorConstants::DarkYellow);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x7*gs + xc*gs, y7*gs + yc*gs, QColorConstants::DarkYellow);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x8*gs + xc*gs, y8*gs + yc*gs, QColorConstants::DarkYellow);
        ui->frame->repaint();
        QThread::msleep(100);
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_draw_Polar_Ellipse_clicked()
{
    auto start = chrono::system_clock::now();
    polar_Ellipse();
    auto end = chrono::system_clock::now();
    auto time_taken = chrono::duration_cast<milliseconds>(end-start).count();
    ui->Polar_Time_Ellipse->setText(QString::number(time_taken)+" ms");
}

void MainWindow::polar_Ellipse() {
    int gs = ui->spinBox->value()+1;
    int rx = ui->rx->value();
    int ry = ui->ry->value();
    int xc = p1.x()/gs;
    int yc = p1.y()/gs;

    for(int i = 0; i < 30; i++) {
        int i2 = 30+i;
        int i3 = 60+i;
        int i4 = 90+i;
        int i5 = 120+i;
        int i6 = 150+i;
        int i7 = 180+i;
        int i8 = 210+i;
        int i9 = 240+i;
        int i10 = 270+i;
        int i11 = 300+i;
        int i12 = 330+i;
        double rad = (3.14/180)*i;
        double rd2 = (3.14/180)*i2;
        double rd3 = (3.14/180)*i3;
        double rd4 = (3.14/180)*i4;
        double rd5 = (3.14/180)*i5;
        double rd6 = (3.14/180)*i6;
        double rd7 = (3.14/180)*i7;
        double rd8 = (3.14/180)*i8;
        double rd9 = (3.14/180)*i9;
        double rd10 = (3.14/180)*i10;
        double rd11 = (3.14/180)*i11;
        double rd12 = (3.14/180)*i12;
        double x = round(xc + rx*cos(rad));
        double y = round(yc + ry*sin(rad));
        cout << x << " " << y;
        double x2 = round(xc + rx*cos(rd2));
        double y2 = round(yc + ry*sin(rd2));
        double x3 = round(xc + rx*cos(rd3));
        double y3 = round(yc + ry*sin(rd3));
        double x4 = round(xc + rx*cos(rd4));
        double y4 = round(yc + ry*sin(rd4));
        double x5 = round(xc + rx*cos(rd5));
        double y5 = round(yc + ry*sin(rd5));
        double x6 = round(xc + rx*cos(rd6));
        double y6 = round(yc + ry*sin(rd6));
        double x7 = round(xc + rx*cos(rd7));
        double y7 = round(yc + ry*sin(rd7));
        double x8 = round(xc + rx*cos(rd8));
        double y8 = round(yc + ry*sin(rd8));
        double x9 = round(xc + rx*cos(rd9));
        double y9 = round(yc + ry*sin(rd9));
        double x10 = round(xc + rx*cos(rd10));
        double y10 = round(yc + ry*sin(rd10));
        double x11 = round(xc + rx*cos(rd11));
        double y11 = round(yc + ry*sin(rd11));
        double x12 = round(xc + rx*cos(rd12));
        double y12 = round(yc + ry*sin(rd12));
        point(x*gs, y*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x2*gs, y2*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x3*gs, y3*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x4*gs, y4*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x5*gs, y5*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x6*gs, y6*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x7*gs, y7*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x8*gs, y8*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x9*gs, y9*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x10*gs, y10*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x11*gs, y11*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x12*gs, y12*gs, QColorConstants::Svg::violet);
        ui->frame->repaint();
        QThread::msleep(100);
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_draw_Bresenhsam_mid_point_Ellipse_clicked()
{
    auto start = chrono::system_clock::now();
    Bresenham_mid_point_Ellipse();
    auto end = chrono::system_clock::now();
    auto time_taken = chrono::duration_cast<milliseconds>(end-start).count();
    ui->Bresenham_mid_point_Time_Ellipse->setText(QString::number(time_taken)+" ms");
}

void MainWindow::Bresenham_mid_point_Ellipse() {
    int gs = ui->spinBox->value()+1;
    int rx = ui->rx->value();
    int ry = ui->ry->value();
    int xc = p1.x()/gs;
    int yc = p1.y()/gs;
    double d2;
    int x = 0;
    int y = ry;
    double d1 = ry*ry - (rx*rx*ry) + (0.25*rx*rx);
    //QThread::msleep(5);
    point(xc*gs, (yc + ry)*gs, QColorConstants::Svg::lime);
    ui->frame->repaint();
    QThread::msleep(200);
    point((xc + rx)*gs, yc*gs, QColorConstants::Svg::lime);
    ui->frame->repaint();
    QThread::msleep(100);
    point(xc*gs, (yc - ry)*gs, QColorConstants::Svg::lime);
    ui->frame->repaint();
    QThread::msleep(100);
    point((xc - rx)*gs, yc*gs, QColorConstants::Svg::lime);
    ui->frame->repaint();
    QThread::msleep(100);

    while(rx*rx*(y - 0.5) > ry*ry*(x+1)) {
        if(d1 < 0) {
            d1 += ry*ry*(2*x + 3);
        }
        else {
            d1 += ry*ry*(2*x + 3) + rx*rx*(-2*y + 2);
            y -= 1;
        }
        x += 1;
        int x2 = x; int y2 = -y;
        int x3 = -x; int y3 = -y;
        int x4 = -x; int y4 = y;
        point(x*gs + xc*gs, y*gs + yc*gs, QColorConstants::Svg::lime);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x2*gs + xc*gs, y2*gs + yc*gs, QColorConstants::Svg::lime);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x3*gs + xc*gs, y3*gs + yc*gs, QColorConstants::Svg::lime);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x4*gs + xc*gs, y4*gs + yc*gs, QColorConstants::Svg::lime);
        ui->frame->repaint();
        QThread::msleep(100);
    }
    d2 = (ry*ry*(x + 0.5)*(x + 0.5)) + (rx*rx*(y-1)*(y-1)) - (rx*rx*ry*ry);
    while(y > 0) {
        if(d2 < 0) {
            d2 += (ry*ry*(2*x + 2)) + (rx*rx*(-2*y + 3));
            x += 1;
        }
        else
            d2 += rx*rx*(-2*y + 3);
        y -= 1;
        int x2 = x; int y2 = -y;
        int x3 = -x; int y3 = -y;
        int x4 = -x; int y4 = y;
        point(x*gs + xc*gs, y*gs + yc*gs, QColorConstants::Svg::lime);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x2*gs + xc*gs, y2*gs + yc*gs, QColorConstants::Svg::lime);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x3*gs + xc*gs, y3*gs + yc*gs, QColorConstants::Svg::lime);
        ui->frame->repaint();
        QThread::msleep(100);
        point(x4*gs + xc*gs, y4*gs + yc*gs, QColorConstants::Svg::lime);
        ui->frame->repaint();
        QThread::msleep(100);
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

// Implement the seed-fill algorithms: a) Boundary fill, b) Flood fill.

void MainWindow::on_boundary_fill_4_clicked()
{
    int gs = ui->spinBox->value()+1;
    int x = p1.x()/gs;
    int y = p1.y()/gs;
    auto start = chrono::system_clock::now();
    boundary4fill(x, y, QColorConstants::White, QColorConstants::Blue);
    auto end = chrono::system_clock::now();
    auto time_taken = chrono::duration_cast<milliseconds>(end-start).count();
    //ui->Bresenham_mid_point_Time_Ellipse->setText(QString::number(time_taken)+" ms");
}
void MainWindow::boundary4fill(int xx, int yy, QColor newcolor, QColor edgecolor) {
    int gs = ui->spinBox->value()+1;
    int x = xx;
    int y = yy;
    //auto current;
    auto current = img.pixel(x*gs + 1, y*gs + 1);
    cout << current << endl;
    if(current != edgecolor.rgba64() && current != newcolor.rgba64())
    {
        point(x*gs, y*gs, newcolor);
        ui->frame->repaint();
        QThread::msleep(100);
        boundary4fill(x+1, y, newcolor, edgecolor);
        point(x*gs, y*gs, newcolor);
        ui->frame->repaint();
        QThread::msleep(100);
        boundary4fill(x-1, y, newcolor, edgecolor);
        point(x*gs, y*gs, newcolor);
        ui->frame->repaint();
        QThread::msleep(100);
        boundary4fill(x, y+1, newcolor, edgecolor);
        point(x*gs, y*gs, newcolor);
        ui->frame->repaint();
        QThread::msleep(100);
        boundary4fill(x, y-1, newcolor, edgecolor);
    }
    else {
        return;
    }
}

