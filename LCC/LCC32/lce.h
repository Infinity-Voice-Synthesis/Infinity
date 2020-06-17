#ifndef LCE_H
#define LCE_H

#include <QDialog>
#include "iflcc.h"
#include <QMessageBox>

namespace Ui {
class LCE;
}

class LCE : public QDialog
{
    Q_OBJECT

public:
    explicit LCE(QWidget *parent = nullptr);
    ~LCE();
    void setS(IFLCC *lcc,QString name);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::LCE *ui;
    IFLCC *lcc=nullptr;
signals:
    //void accepted(IFLCC *lcc);
};

#endif // LCE_H
