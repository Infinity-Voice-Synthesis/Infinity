#include "gplview.h"
#include "ui_gplview.h"

GPLView::GPLView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GPLView)
{
    ui->setupUi(this);
}

GPLView::~GPLView()
{
    delete ui;
}
