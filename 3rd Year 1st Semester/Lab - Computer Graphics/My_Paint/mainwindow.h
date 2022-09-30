#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void Mouse_Pressed();
    void showMousePosition(QPoint& pos);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_show_axes_clicked();

    void on_Draw_clicked();

    void on_set_point1_clicked();

    void on_set_point2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_spinBox_valueChanged();

    void on_draw_DDA_clicked();

    void on_set_p1_clicked();

    void on_set_p2_clicked();

    void on_draw_Bresenham_clicked();

    void on_axes_stateChanged();

    void on_draw_Polar_clicked();

    void on_draw_Bresenhsam_mid_point_clicked();

    void on_draw_Polar_Ellipse_clicked();

    void on_draw_Bresenhsam_mid_point_Ellipse_clicked();

    void on_boundary_fill_4_clicked();

private:
    Ui::MainWindow *ui;
    QPoint p1,p2;
    void point(int,int, QColor);
    void DDA();
    void Bresenham();
    void polar();
    void Bresenham_mid_point();
    void polar_Ellipse();
    void Bresenham_mid_point_Ellipse();
    void boundary4fill(int x, int y, QColor newcolor, QColor edgecolor);
};

#endif // MAINWINDOW_H
