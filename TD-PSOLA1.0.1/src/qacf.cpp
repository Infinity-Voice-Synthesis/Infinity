#include "qacf.h"
#include "ui_qacf.h"

qacf::qacf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qacf)
{
    ui->setupUi(this);
}

qacf::~qacf()
{
    delete ui;
}

QVector<qreal>* qacf::acf(QVector<qreal>* data,int K)
{
    QVector<qreal>* out=new QVector<qreal>;
    int N=data->size();
    double E0=0;
    for(int i=0;i<=N-K;i++)
    {
        E0=E0+data->at(i)*data->at(i);
    }
    for(int i=0;i<K;i++)
    {
        double sigma=0;
        for(int j=0;j<=N-1-K;j++)
        {
            sigma=sigma+(data->at(j)*data->at(j+i));
        }
        double E=0;
        for(int j=i;j<=i+N-K;j++)
        {
            E=E+data->at(j)*data->at(j);
        }
        out->append(sigma/sqrt(E0*E));
    }
    ui->graphicsView->cleardata();
    ui->graphicsView->setseriesdata(out);
    return out;
}

double qacf::gf(QVector<qreal>* data,double cut,int fs)
{
    int len=data->size();
    QVector<qreal>* dataca =new QVector<qreal>;
    for (int i=0;i<len;i++)
    {
        if(data->at(i)>cut)
        {
            dataca->append(data->at(i));
        }
        else

        {
            dataca->append(-1);
        }
    }
    int af=0;
    int rf=0;
    int flag=0;
    for (int i=0;i<len;i++)
    {
        if(dataca->at(i)!=-1&&flag==0)
        {
        }
        else if (dataca->at(i)==-1&&flag==0)
        {
            flag=1;
        }
        else if(dataca->at(i)!=-1&&flag==1)
        {
            af=i;
            flag=2;
        }
        else if(dataca->at(i)!=-1&&flag==2)
        {
        }
        else if(dataca->at(i)==-1&&flag==2)
        {
            rf=i;
            break;
        }
        else
        {

        }
    }
    double maxn=0;
    for (int i=af;i<rf;i++)
    {
        maxn=qMax(dataca->at(i),maxn);
    }
    int out=0;
    for (int i=af;i<rf;i++)
    {
        if(dataca->at(i)==maxn)
        {
            out=i;
        }
    }
    double outt=1/((double)out/(double)fs);
    return outt;
}
