#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
}

About::~About()
{
    delete ui;
}

void About::on_pushButton_clicked()
{
    QMessageBox::aboutQt(this);
}

void About::on_GPL_clicked()
{
    GPLView *view=new GPLView(this);
    view->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
    view->setWindowFlag(Qt::WindowMaximizeButtonHint,true);
    view->exec();
}
