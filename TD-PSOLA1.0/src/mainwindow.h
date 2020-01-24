#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <about.h>
#include <ui_about.h>
#include <gplview.h>
#include <ui_gplview.h>
#include <qwavehandle.h>
#include <qwchart.h>
#include <QSound>
#include <QSoundEffect>
#include <QtCharts>
#include <qacf.h>
#include <ui_qacf.h>
QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString Filename;
    QString SaveFilename;
    QLabel *tip=new QLabel;
    QLabel *pla=new QLabel;
    QWaveHandle *wave=new QWaveHandle(this);
    QWaveHandle *waveo=new QWaveHandle(this);
    QVector<qreal> *xlist=new QVector<qreal>;
    QVector<int> *mark=new QVector<int>;
    QVector<qreal>* resampler();
    double ff;
    void psa();
    void psao();
    void psaoc(QVector<qreal> *in);
    void psola(QVector<qreal> *in);
    QVector<qreal> *xn=new QVector<qreal>;
    QVector<qreal> *yn=new QVector<qreal>;
    QVector<qreal> *xc=new QVector<qreal>;
    QVector<qreal> *yc=new QVector<qreal>;
private slots:
    void on_ow_triggered();

    void on_ab_triggered();

    void on_pw_triggered();

    void on_pb_triggered();

    void on_ew_triggered();

    void on_an_triggered();

    void on_do_2_triggered();

    void on_horizontalSlider_ot_valueChanged(int value);

    void on_doubleSpinBox_ot_valueChanged(double arg1);

    void on_horizontalSlider_of_valueChanged(int value);

    void on_chartn_changed(QPoint point);

    void on_charto_changed(QPoint point);

    void on_doubleSpinBox_of_valueChanged(double arg1);

    void on_ch_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
