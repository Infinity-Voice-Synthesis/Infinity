#include "mainwindow.h"

#include <QPixmap>
#include <QSplashScreen>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/imag/splash.png"));
    splash->show();
    a.processEvents();
    w.Delay_MSec_Suspend(5000);
    w.show();
    w.setWindowState(Qt::WindowMaximized);
    splash->finish(&w);
    delete splash;
    return a.exec();
}
