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

    void on_flood_fill_clicked();

    void on_translate_clicked();

    void on_store_to_stack_clicked();

    void on_scale_clicked();

    void on_rotate_clicked();

    void on_shear_clicked();

    void on_reflect_x_clicked();

    void on_reflect_y_clicked();

    void on_boundary_8_clicked();

    void on_flood_8_clicked();

    void on_scanline_fill_clicked();

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
    void boundary4fill(int x, int y, QRgb edgecolor, int r, int g, int b);
    void boundary8fill(int x, int y, QRgb edgecolor, int r, int g, int b);
    void floodfill(int x, int y, int r, int g, int b);
    void floodfill8(int x, int y, int r, int g, int b);
    void translation(int x, int y, int tx, int ty);
    void scaling(double sx, double sy);
    void rotation(int d);
    void shearing(int shx, int shy);
    void reflect_x();
    void reflect_y();
};

#endif // MAINWINDOW_H
