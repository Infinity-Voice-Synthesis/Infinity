#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include <QMessageBox>
#include <gplview.h>


namespace Ui {
class About;
}

class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = nullptr);
    ~About();

private slots:
    void on_pushButton_clicked();

    void on_GPL_clicked();

private:
    Ui::About *ui;
};

#endif // ABOUT_H
