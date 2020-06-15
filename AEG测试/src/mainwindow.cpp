#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->percent->hide();
    ui->Tip->appendPlainText("Infinity音频引擎测试工具 v1.0.0\n作者：無常\n");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openfile_clicked()
{
    QString currentpath=QDir::currentPath();
    QDir::setCurrent(currentpath);
    ui->filepath->setText(QFileDialog::getOpenFileName(this,"选择引擎文件",currentpath,"Infinity音频引擎(*.dll);;所有文件(*.*)"));
}

void MainWindow::on_loadengine_clicked()
{
    QDateTime time=QDateTime::currentDateTime();
    if(!ui->filepath->text().isEmpty()){
        if(library->isLoaded()&&aegptr!=nullptr){
            if(running){
                StopFunction Stop=(StopFunction)library->resolve("Stop");
                CheckFunction Check=(CheckFunction)library->resolve("Check");
                disconnect(pb,SIGNAL(percentchanged(double)),this,SLOT(on_percentchanged(double)));
                disconnect(pb,SIGNAL(aegfinished()),this,SLOT(on_finished()));
                Stop(aegptr);
                while (Check(aegptr)) {

                }
                ui->percent->setValue(0);
                ui->percent->hide();
                running=false;
            }
        }

        library->setFileName(ui->filepath->text());
        library->load();
        if(library->isLoaded()){

            PrepareFunction Prepare=(PrepareFunction)library->resolve("Prepare");
            if(Prepare!=nullptr){
                aegptr=Prepare();
                if(aegptr!=nullptr){
                    ui->Tip->appendPlainText(time.time().toString()+" "+"引擎已初始化！\n"+ui->filepath->text()+"\n");
                }else{
                    ui->Tip->appendPlainText(time.time().toString()+" "+"引擎未能初始化！\n");
                }
            }else{
                library->unload();
                ui->Tip->appendPlainText(time.time().toString()+" "+"引擎无效！\n");
            }

        }else{
            ui->Tip->appendPlainText(time.time().toString()+" "+"引擎文件未成功加载！\n");
        }
    }else{
        ui->Tip->appendPlainText(time.time().toString()+" "+"引擎文件名为空！\n");
    }
}

void MainWindow::on_clean_clicked()
{
    QDateTime time=QDateTime::currentDateTime();
    if(library->isLoaded()){

        ClearFunction Clear=(ClearFunction)library->resolve("Clear");

        if(aegptr!=nullptr){
            if(running){
                CheckFunction Check=(CheckFunction)library->resolve("Check");
                StopFunction Stop=(StopFunction)library->resolve("Stop");
                disconnect(pb,SIGNAL(percentchanged(double)),this,SLOT(on_percentchanged(double)));
                disconnect(pb,SIGNAL(aegfinished()),this,SLOT(on_finished()));
                Stop(aegptr);
                while (Check(aegptr)) {

                }
                ui->percent->setValue(0);
                ui->percent->hide();
                running=false;
            }
            Clear(aegptr);
            aegptr=nullptr;
            library->unload();
            ui->Tip->appendPlainText(time.time().toString()+" "+"引擎已卸载！\n");
        }else{
            ui->Tip->appendPlainText(time.time().toString()+" "+"引擎类指针为空！\n");
        }

    }else{
        ui->Tip->appendPlainText(time.time().toString()+" "+"引擎文件未加载！\n");
    }
}

void MainWindow::on_stop_clicked()
{
    QDateTime time=QDateTime::currentDateTime();
    if(library->isLoaded()){
        if(aegptr!=nullptr){
            if(running){
                StopFunction Stop=(StopFunction)library->resolve("Stop");
                CheckFunction Check=(CheckFunction)library->resolve("Check");
                disconnect(pb,SIGNAL(percentchanged(double)),this,SLOT(on_percentchanged(double)));
                disconnect(pb,SIGNAL(aegfinished()),this,SLOT(on_finished()));
                Stop(aegptr);
                while (Check(aegptr)) {

                }
                ui->percent->setValue(0);
                ui->percent->hide();
                running=false;
                ui->Tip->appendPlainText(time.time().toString()+" "+"引擎已强制结束运行！\n");
            }else{
                ui->Tip->appendPlainText(time.time().toString()+" "+"引擎未运行！\n");
            }
        }else{
            ui->Tip->appendPlainText(time.time().toString()+":" "引擎类指针为空！\n");
        }

    }else{
        ui->Tip->appendPlainText(time.time().toString()+":" "引擎文件未加载！\n");
    }
}

void MainWindow::on_start_clicked()
{
    QDateTime time=QDateTime::currentDateTime();
    if(library->isLoaded()){
        if(aegptr!=nullptr){
            if(running){
                ui->Tip->appendPlainText(time.time().toString()+":" "引擎已在运行！\n");
            }else{
                RunFunction Run=(RunFunction)library->resolve("Run");

                pb->aegptr=aegptr;
                pb->library=library;
                connect(pb,SIGNAL(percentchanged(double)),this,SLOT(on_percentchanged(double)));
                connect(pb,SIGNAL(aegfinished()),this,SLOT(on_finished()));
                Run(aegptr,ui->track->value(),ui->time->value(),ui->fs->currentText().toInt(),ui->ain->text());
                pb->start();
                ui->percent->setValue(0);
                ui->percent->show();
                running=true;
                ui->Tip->appendPlainText(time.time().toString()+" "+"引擎已启动！\n"+"轨道："+QString::asprintf("%i",ui->track->value())+"\n"+"时长："+QString::asprintf("%.2f",ui->time->value())+"\n"+"采样率："+ui->fs->currentText()+"\n"+"引擎附加信息："+ui->ain->text()+"\n");
            }
        }else{
            ui->Tip->appendPlainText(time.time().toString()+" "+"引擎类指针为空！\n");
        }

    }else{
        ui->Tip->appendPlainText(time.time().toString()+" "+"引擎文件未加载！\n");
    }
}

void MainWindow::on_percentchanged(double value)
{
    ui->percent->setValue(value);
}

void MainWindow::on_finished()
{
    QDateTime time=QDateTime::currentDateTime();
    disconnect(pb,SIGNAL(percentchanged(double)),this,SLOT(on_percentchanged(double)));
    disconnect(pb,SIGNAL(aegfinished()),this,SLOT(on_finished()));
    ui->percent->setValue(100);
    ui->percent->hide();
    running=false;
    ui->Tip->appendPlainText(time.time().toString()+" "+"引擎已结束运行！\n");
}
