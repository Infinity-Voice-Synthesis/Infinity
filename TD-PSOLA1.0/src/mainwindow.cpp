#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->toolBar->addAction(ui->ow);
    ui->toolBar->addAction(ui->pw);
    ui->toolBar->addAction(ui->pb);
    ui->toolBar->addAction(ui->ew);
    ui->toolBar->addAction(ui->ab);
    ui->statusbar->addWidget(pla);
    ui->statusbar->addPermanentWidget(tip);
    tip->setText(tr("-"));
    tip->setText(tr("就绪"));
    tip->setMinimumWidth(400);
    pla->setMinimumWidth(400);
    tip->setAlignment(Qt::AlignRight);
    ui->anyl->setDefaultAction(ui->an);
    ui->change->setDefaultAction(ui->ch);
    ui->pb->setEnabled(false);
    ui->ew->setEnabled(false);
    ui->anyl->setEnabled(false);
    ui->ch->setEnabled(false);
    ui->groupBox_2->setEnabled(false);
    connect(ui->chartsrc,SIGNAL(mousemove(QPoint)),this,SLOT(on_chartn_changed(QPoint)));
    connect(ui->chartobj,SIGNAL(mousemove(QPoint)),this,SLOT(on_charto_changed(QPoint)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ow_triggered()
{
    QString curpath=QDir::currentPath();
    QString title=tr("选择一个wav文件");
    QString filter=tr("波形文件(*.wav);;所有文件(*.*)");
    Filename=QFileDialog::getOpenFileName(this,title,curpath,filter);
    if(!Filename.isEmpty())
    {
        tip->setText(tr("分析文件：")+Filename);
        wave->clear();
        if(wave->ReadFile(Filename))
        {
            tip->setText(tr("打开文件：")+Filename);
        }
        else
        {
            tip->setText(tr("未能打开文件：")+Filename);
        }
    }
    ui->chartsrc->cleardata();
    ui->chartobj->cleardata();
    ui->chartsrc->setseriesdata(wave->wavedataL);
    ui->pb->setEnabled(false);
    ui->ew->setEnabled(false);
    ui->anyl->setEnabled(true);
    ui->ch->setEnabled(false);
    ui->groupBox_2->setEnabled(false);
    ui->len->setValue(((qreal)wave->wavedataL->size())/(qreal)wave->samplespersec);
    ui->doubleSpinBox_ot->setValue(((qreal)wave->wavedataL->size())/(qreal)wave->samplespersec);
    ui->ss->setValue(wave->wavedataL->size());
    ui->spr->setValue(wave->samplespersec);
    ui->fb->setValue(0);
}

void MainWindow::on_ab_triggered()
{
    About *aboutbox=new About(this);
    aboutbox->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
    aboutbox->exec();
}

void MainWindow::on_pw_triggered()
{
    tip->setText(tr("播放文件：")+Filename);
    QSound::play(Filename);
}

void MainWindow::on_pb_triggered()
{
    QString curpath=qApp->applicationDirPath();
    tip->setText(tr("播放缓存数据"));
    QSound::play("temp.wav");
}

void MainWindow::on_ew_triggered()
{
    QString curpath=QDir::currentPath();
    QString title=tr("保存为wav文件");
    QString filter=tr("波形文件(*.wav);;所有文件(*.*)");
    SaveFilename=QFileDialog::getSaveFileName(this,title,curpath,filter);
    if(!SaveFilename.isEmpty())
    {
        if(waveo->WriteFile(SaveFilename))
        {
            tip->setText(tr("保存文件：")+SaveFilename);
        }
        else
        {
            tip->setText(tr("未能保存文件：")+SaveFilename);
        }
    }
}

void MainWindow::on_an_triggered()
{
    qacf *acfc=new qacf;
    QVector<qreal> *acf=acfc->acf(wave->wavedataL,wave->wavedataL->size()/4);
    ff=acfc->gf(acf,0.9,wave->samplespersec);
    ui->fb->setValue(ff);
    ui->doubleSpinBox_of->setValue(ff);
    ui->ch->setEnabled(true);
    psa();
    ui->chartsrc->clearpointdata();
    ui->chartsrc->setpointndata(xn,yn);
    ui->chartsrc->setpointodata(xc,yc);
    ui->chartobj->cleardata();
    ui->chartobj->setseriesdata(wave->wavedataL);
    ui->groupBox_2->setEnabled(true);
    tip->setText(tr("分析源数据"));
    //acfc->show();
}

void MainWindow::on_do_2_triggered()
{

}

void MainWindow::on_horizontalSlider_ot_valueChanged(int value)
{
    if(ui->doubleSpinBox_ot->value()!=(double)value)
    {
        ui->doubleSpinBox_ot->setValue((double)value);
    }
}

void MainWindow::on_doubleSpinBox_ot_valueChanged(double arg1)
{
    if(ui->horizontalSlider_ot->value()!=(int)arg1)
    {
        ui->horizontalSlider_ot->setValue((int)arg1);
    }
    ui->chartobj->clearpointdata();
    ui->chartobj->chart->axes(Qt::Horizontal).back()->setRange(0,arg1*wave->samplespersec);
}

void MainWindow::on_horizontalSlider_of_valueChanged(int value)
{
    if(round(ui->doubleSpinBox_of->value())!=(double)value)
    {
        ui->doubleSpinBox_of->setValue((double)value);
    }
}

void MainWindow::on_chartn_changed(QPoint point)
{
    QPointF pt=ui->chartsrc->QChartView::chart()->mapToValue(point);
    pla->setText(QString::asprintf("Resource: X= %.2f sec,Y= %.2f",pt.x()/wave->samplespersec,pt.y()));
}

void MainWindow::on_charto_changed(QPoint point)
{
    QPointF pt=ui->chartobj->QChartView::chart()->mapToValue(point);
    pla->setText(QString::asprintf("Object: X= %.2f sec,Y= %.2f",pt.x()/wave->samplespersec,pt.y()));
}

void MainWindow::on_doubleSpinBox_of_valueChanged(double arg1)
{
    if(ui->horizontalSlider_of->value()!=round(arg1))
    {
        ui->horizontalSlider_of->setValue(round(arg1));
    }
}

void MainWindow::on_ch_triggered()
{
    waveo->clear();
    xlist->clear();
    mark->clear();
    xn->clear();
    yn->clear();
    xc->clear();
    yc->clear();
    QVector<qreal> *outcache=resampler();
    psaoc(outcache);
    psola(outcache);
    psao();
    ui->chartobj->cleardata();
    ui->chartobj->setseriesdata(waveo->wavedataL);
    ui->chartobj->setpointndata(xn,yn);
    ui->chartobj->setpointodata(xc,yc);
    QString curpath=qApp->applicationDirPath();
    if(waveo->WriteFile("temp.wav"))
    {
        ui->pb->setEnabled(true);
        ui->ew->setEnabled(true);
        tip->setText(tr("合成数据并缓存"));
    }
    else
    {
        ui->pb->setEnabled(false);
        ui->ew->setEnabled(false);
        tip->setText(tr("合成数据缓存失败"));
    }

}

void MainWindow::psa()
{
    xlist->clear();
    mark->clear();
    xn->clear();
    yn->clear();
    xc->clear();
    yc->clear();
    int T=(1/ff)*wave->samplespersec;
    double trap=0.1;
    int Tra=0;
    int mm=1;
    int count=1;
    int flag=0;
    xlist->append(0);
    mark->append(Tra);
    int zf=wave->wavedataL->size()-1;
    for (int i=wave->wavedataL->size()-1;i>=0;i--) {
        if(wave->wavedataL->at(i)==0)
        {

        }
        else
        {
            zf=i;
            break;
        }
    }
    while(flag+T<wave->wavedataL->size())
    {
        if(flag>zf)
        {
            break;
        }
        int nn=0;
        double minn=2;
        int mf=0;
        while (nn<T) {
            minn=qMin(minn,wave->wavedataL->at(flag+nn));
            nn++;
        }
        nn=0;
        mf=flag+T;
        while (nn<T) {
            if(wave->wavedataL->at(flag+nn)==minn)
            {
                mf=flag+nn;
                break;
            }
            nn++;
        }
        nn=1;
        while (nn<T&&mf+nn<wave->wavedataL->size()) {
            if((mf+nn)>=wave->wavedataL->size())
            {
                break;
            }
            if(wave->wavedataL->at(mf+nn)==0&&wave->wavedataL->at(mf+nn-1)==0)
            {
                break;
            }
            if(wave->wavedataL->at(mf+nn)>=0&&wave->wavedataL->at(mf+nn-1)<0&&mf+nn<wave->wavedataL->size())
            {
                xlist->append(mf+nn);
                count++;
                flag=mf+nn;
                if(abs(abs(xlist->at(mm)-xlist->at(mm-1))-T)/T>trap)
                {
                    Tra++;
                }
                mark->append(Tra);
                mm++;
                break;
            }
            nn++;
        }
    }
    xc->append(0);
    yc->append(wave->wavedataL->at(0));
    for (int i=0;i<xlist->size()-1;i++) {
        if(mark->at(i+1)-mark->at(i)==0)
        {
            xn->append(xlist->at(i));
            yn->append(wave->wavedataL->at(xlist->at(i)));
        }
        else
        {
            xc->append(xlist->at(i));
            yc->append(wave->wavedataL->at(xlist->at(i)));
        }
    }
}

QVector<qreal>* MainWindow::resampler()
{
    int len=wave->wavedataL->size();
    double T=ui->fb->value()/ui->doubleSpinBox_of->value();
    int leno=len*T;
    QVector<qreal> *outcache=new QVector<qreal>;
    for (int mm=0;mm<leno&&floor(mm/T)+1<len;mm++) {
        outcache->append(((mm/T)-floor(mm/T))*wave->wavedataL->at(floor(mm/T)+1)+(1-((mm/T)-floor(mm/T)))*wave->wavedataL->at(floor(mm/T)));
    }
    return outcache;
}

void MainWindow::psola(QVector<qreal> *in)
{
    int T=round((1/ui->doubleSpinBox_of->value())*wave->samplespersec);
    int counto=round((ui->doubleSpinBox_ot->value()*wave->samplespersec)/((1/ui->doubleSpinBox_of->value())*wave->samplespersec));
    double Pcha=T*counto-in->size();
    int Pca=(mark->size())-mark->at(mark->size()-1);
    QVector<int> *flag=new QVector<int>;
    for (int mm=0;mm<mark->size();mm++) {
        flag->append(1);
    }
    if(Pcha>=0)
    {
        int Tcha=round(Pcha/T);
        int jiabei=floor(Tcha/Pca);
        int yv=Tcha-floor(Tcha/Pca)*Pca;
        int mm=1;
        while (mm<mark->size()) {
            if(mark->at(mm)-mark->at(mm-1)==0)
            {
                flag->replace(mm,flag->at(mm)+jiabei);
            }
            mm++;
        }
        QVector<int> *temp=new QVector<int>;
        for (int mm=0;mm<yv;mm++) {
            temp->append(round(mm*(Pca/yv)));
        }
        int nn=1;
        mm=0;
        int jj=0;
        while(mm<yv&&nn<mark->size())
        {
            if(mark->at(nn)-mark->at(nn-1)==0)
            {
                if(temp->at(mm)==jj)
                {
                    flag->replace(nn,flag->at(nn)+1);
                    mm++;
                }
                jj++;
            }
            nn++;
        }
    }
    else
    {
        int jian=round(Pcha/T);
        QVector<int> *temp=new QVector<int>;
        for (int mm=0;mm<jian;mm++) {
            temp->append(round(mm*(Pca/jian)));
        }
        int nn=1;
        int mm=0;
        int jj=0;
        while(mm<jian&&nn<mark->size())
        {
            if(mark->at(nn)-mark->at(nn-1)==0)
            {
                if(temp->at(mm)==jj)
                {
                    flag->replace(nn,flag->at(nn)-1);
                    mm++;
                }
                jj++;
            }
            nn++;
        }
    }
    int Fn=1;
    int Fo=0;
    for (int mm=0;mm<ui->doubleSpinBox_ot->value()*wave->samplespersec;mm++) {
        waveo->wavedataL->append(0);
    }
    while(Fn<mark->size()&&(Fo+(xlist->at(Fn)-xlist->at(Fn-1))-1)<ui->doubleSpinBox_ot->value()*wave->samplespersec)
    {
        for (int nn=1;nn<=flag->at(Fn);nn++) {
            int le=(xlist->at(Fn)-xlist->at(Fn-1));
            for (int jj=0;jj<le;jj++) {
                waveo->wavedataL->replace(Fo+jj,in->at(xlist->at(Fn-1)+jj));
            }
            Fo+=le;
        }
        Fn++;
    }
}

void MainWindow::psao()
{
    xlist->clear();
    mark->clear();
    xn->clear();
    yn->clear();
    xc->clear();
    yc->clear();
    int T=(1/ui->doubleSpinBox_of->value())*waveo->samplespersec;
    double trap=0.1;
    int Tra=0;
    int mm=1;
    int count=1;
    int flag=0;
    xlist->append(0);
    mark->append(Tra);
    int zf=waveo->wavedataL->size()-1;
    for (int i=waveo->wavedataL->size()-1;i>=0;i--) {
        if(waveo->wavedataL->at(i)==0)
        {

        }
        else
        {
            zf=i;
            break;
        }
    }
    while(flag+T<waveo->wavedataL->size())
    {
        if(flag>zf)
        {
            break;
        }
        int nn=0;
        double minn=2;
        int mf=0;
        while (nn<T) {
            minn=qMin(minn,waveo->wavedataL->at(flag+nn));
            nn++;
        }
        nn=0;
        mf=flag+T;
        while (nn<T) {
            if(waveo->wavedataL->at(flag+nn)==minn)
            {
                mf=flag+nn;
                break;
            }
            nn++;
        }
        nn=1;
        while (nn<T&&mf+nn<waveo->wavedataL->size()) {
            if((mf+nn)>=waveo->wavedataL->size())
            {
                break;
            }
            if(waveo->wavedataL->at(mf+nn)==0&&waveo->wavedataL->at(mf+nn-1)==0)
            {
                break;
            }
            if(waveo->wavedataL->at(mf+nn)>=0&&waveo->wavedataL->at(mf+nn-1)<0&&mf+nn<waveo->wavedataL->size())
            {
                xlist->append(mf+nn);
                count++;
                flag=mf+nn;
                if(abs(abs(xlist->at(mm)-xlist->at(mm-1))-T)/T>trap)
                {
                    Tra++;
                }
                mark->append(Tra);
                mm++;
                break;
            }
            nn++;
        }
    }
    xc->append(0);
    yc->append(waveo->wavedataL->at(0));
    for (int i=0;i<xlist->size()-1;i++) {
        if(mark->at(i+1)-mark->at(i)==0)
        {
            xn->append(xlist->at(i));
            yn->append(waveo->wavedataL->at(xlist->at(i)));
        }
        else
        {
            xc->append(xlist->at(i));
            yc->append(waveo->wavedataL->at(xlist->at(i)));
        }
    }
}

void MainWindow::psaoc(QVector<qreal> *in)
{
    xlist->clear();
    mark->clear();
    xn->clear();
    yn->clear();
    xc->clear();
    yc->clear();
    int T=(1/ui->doubleSpinBox_of->value())*waveo->samplespersec;
    double trap=0.1;
    int Tra=0;
    int mm=1;
    int count=1;
    int flag=0;
    xlist->append(0);
    mark->append(Tra);
    int zf=in->size()-1;
    for (int i=in->size()-1;i>=0;i--) {
        if(in->at(i)==0)
        {

        }
        else
        {
            zf=i;
            break;
        }
    }
    while(flag+T<in->size())
    {
        if(flag>zf)
        {
            break;
        }
        int nn=0;
        double minn=2;
        int mf=0;
        while (nn<T) {
            minn=qMin(minn,in->at(flag+nn));
            nn++;
        }
        nn=0;
        mf=flag+T;
        while (nn<T) {
            if(in->at(flag+nn)==minn)
            {
                mf=flag+nn;
                break;
            }
            nn++;
        }
        nn=1;
        while (nn<T&&mf+nn<in->size()) {
            if((mf+nn)>=in->size())
            {
                break;
            }
            if(in->at(mf+nn)==0&&in->at(mf+nn-1)==0)
            {
                break;
            }
            if(in->at(mf+nn)>=0&&in->at(mf+nn-1)<0&&mf+nn<in->size())
            {
                xlist->append(mf+nn);
                count++;
                flag=mf+nn;
                if(abs(abs(xlist->at(mm)-xlist->at(mm-1))-T)/T>trap)
                {
                    Tra++;
                }
                mark->append(Tra);
                mm++;
                break;
            }
            nn++;
        }
    }
    xc->append(0);
    yc->append(in->at(0));
    for (int i=0;i<xlist->size()-1;i++) {
        if(mark->at(i+1)-mark->at(i)==0)
        {
            xn->append(xlist->at(i));
            yn->append(in->at(xlist->at(i)));
        }
        else
        {
            xc->append(xlist->at(i));
            yc->append(in->at(xlist->at(i)));
        }
    }
}
