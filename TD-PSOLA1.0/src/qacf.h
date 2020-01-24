#ifndef QACF_H
#define QACF_H

#include <QDialog>
#include <QtMath>

namespace Ui {
class qacf;
}

class qacf : public QDialog
{
    Q_OBJECT

public:
    explicit qacf(QWidget *parent = nullptr);
    ~qacf();
    QVector<qreal>* acf(QVector<qreal>* data,int K);
    double gf(QVector<qreal>* data,double cut,int fs);

private:
    Ui::qacf *ui;
};

#endif // QACF_H
