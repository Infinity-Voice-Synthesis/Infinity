#ifndef QWCHART_H
#define QWCHART_H

#include <QObject>
#include <QWidget>
#include <QtCharts>
QT_CHARTS_USE_NAMESPACE

class QWchart : public QChartView
{
    Q_OBJECT
public:
    explicit QWchart(QWidget *parent = nullptr);
    QLineSeries *series=new QLineSeries;
    QScatterSeries *pointn=new QScatterSeries;
    QScatterSeries *pointa=new QScatterSeries;
    QPen pens;
    QChart *chart=new QChart;
    void setseriesdata(QVector<qreal> *data);
    void setpointndata(QVector<qreal> *x,QVector<qreal> *y);
    void setpointodata(QVector<qreal> *x,QVector<qreal> *y);
    void clearseriesdata();
    void clearpointdata();
    void cleardata();
protected:
    void mouseMoveEvent(QMouseEvent *event) override;
signals:
    void mousemove(QPoint point);
};

#endif // QWCHART_H
