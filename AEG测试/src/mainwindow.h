#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFileDialog>
#include <QLibrary>
#include "percentbackend.h"
#include <QDateTime>


typedef QObject* (*PrepareFunction)();
typedef void (*RunFunction)(QObject *,int,double,int,QString);
typedef void (*StopFunction)(QObject *);
typedef void (*ClearFunction)(QObject *);
typedef double (*GetFunction)(QObject *);
typedef bool (*CheckFunction)(QObject *);

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openfile_clicked();

    void on_loadengine_clicked();

    void on_clean_clicked();

    void on_stop_clicked();

    void on_start_clicked();

    void on_percentchanged(double value);

    void on_finished();
private:
    Ui::MainWindow *ui;
    QObject *aegptr=nullptr;
    QLibrary *library=new QLibrary;
    bool running=false;
    percentbackend *pb=new percentbackend;
};
#endif // MAINWINDOW_H
