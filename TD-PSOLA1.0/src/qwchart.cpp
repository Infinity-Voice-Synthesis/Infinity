#include "qwchart.h"

QWchart::QWchart(QWidget *parent) : QChartView(parent)
{
    series->setUseOpenGL(true);
    pointa->setUseOpenGL(true);
    pointn->setUseOpenGL(true);
    chart->removeAllSeries();
    if(!chart->axes(Qt::Horizontal).isEmpty())
    {
        chart->removeAxis(chart->axes(Qt::Horizontal).back());
    }
    if(!chart->axes(Qt::Vertical).isEmpty())
    {
        chart->removeAxis(chart->axes(Qt::Vertical).back());
    }
    //chart->axes(Qt::Horizontal).back()->setRange(0, data.size())
    pens.setColor(Qt::blue);
    pens.setWidth(2);
    series->setPen(pens);
    series->setName(tr("波形数据"));
    pointa->setName(tr("变异点"));
    pointn->setName(tr("非变异点"));
    pointa->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    pointn->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    pointa->setBorderColor(Qt::yellow);
    pointn->setBorderColor(Qt::green);
    pointa->setBrush(QBrush(Qt::yellow));
    pointn->setBrush(QBrush(Qt::green));
    pointa->setMarkerSize(4);
    pointn->setMarkerSize(4);
    chart->addSeries(series);
    chart->addSeries(pointa);
    chart->addSeries(pointn);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).back()->setRange(-1,1);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignTop);
    this->setChart(chart);
    cleardata();
}

void QWchart::setseriesdata(QVector<qreal> *data)
{
    if(data->size()>0)
    {
        for(int i=0;i<data->size();i++)
        {
            series->append(i,data->at(i));
        }
        chart->axes(Qt::Horizontal).back()->setRange(0,data->size());
    }
}
void QWchart::setpointndata(QVector<qreal> *x,QVector<qreal> *y)
{
    if(x->size()>0&&(x->size()==y->size()))
    {
        for(int i=0;i<x->size();i++)
        {
            pointn->append(x->at(i),y->at(i));
        }
    }
}
void QWchart::setpointodata(QVector<qreal> *x,QVector<qreal> *y)
{
    if(x->size()>0&&(x->size()==y->size()))
    {
        for(int i=0;i<x->size();i++)
        {
            pointa->append(x->at(i),y->at(i));
        }
    }
}

void QWchart::clearseriesdata()
{
    series->clear();
}
void QWchart::clearpointdata()
{
    pointa->clear();
    pointn->clear();
}
void QWchart::cleardata()
{
    clearseriesdata();
    clearpointdata();
}

void QWchart::mouseMoveEvent(QMouseEvent *event)
{
    emit mousemove(event->pos());
    QChartView::mouseMoveEvent(event);
}
