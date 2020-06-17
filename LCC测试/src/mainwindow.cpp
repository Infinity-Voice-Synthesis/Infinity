    #include "mainwindow.h"
    #include "ui_mainwindow.h"

    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        ui->tip->appendPlainText("许可证管理器测试工具v1.0.0\n作者：無常\n");
    }

    MainWindow::~MainWindow()
    {
        delete ui;
    }


    void MainWindow::on_refresh_clicked()
    {
        ui->tip->clear();
        ui->tip->appendPlainText("许可证管理器测试工具v1.0.0\n作者：無常\n");
        LCC *lcc=new LCC;
        ifparts *parts=lcc->getparts();
        //
        ui->tip->appendPlainText("SEG\n");
        for(int i=0;i<parts->SEG->size();i++){
            ui->tip->appendPlainText("name:"+parts->SEG->at(i)->name);
            ui->tip->appendPlainText("id:"+parts->SEG->at(i)->id);
            ui->tip->appendPlainText("icon:"+parts->SEG->at(i)->icon);
            ui->tip->appendPlainText("tool:"+parts->SEG->at(i)->tool);
            ui->tip->appendPlainText("\n");
            ui->tip->appendPlainText("lan:");
            for(int j=0;j<parts->SEG->at(i)->lan->size();j++){
                ui->tip->appendPlainText("     "+parts->SEG->at(i)->lan->at(j).name);
            }
            ui->tip->appendPlainText("\n");
            ui->tip->appendPlainText("FST:");
            for(int j=0;j<parts->SEG->at(i)->FST->size();j++){
                ui->tip->appendPlainText("     name:"+parts->SEG->at(i)->FST->at(j)->name);
                ui->tip->appendPlainText("     up:"+QString::asprintf("%.2f",parts->SEG->at(i)->FST->at(j)->up));
                ui->tip->appendPlainText("     down:"+QString::asprintf("%.2f",parts->SEG->at(i)->FST->at(j)->down));
                ui->tip->appendPlainText("     normal:"+QString::asprintf("%.2f",parts->SEG->at(i)->FST->at(j)->normal));
                ui->tip->appendPlainText("\n");
            }
            ui->tip->appendPlainText("\n");
            ui->tip->appendPlainText("WST:");
            for(int j=0;j<parts->SEG->at(i)->WST->size();j++){
                ui->tip->appendPlainText("     name:"+parts->SEG->at(i)->WST->at(j)->name);
                ui->tip->appendPlainText("     up:"+QString::asprintf("%.2f",parts->SEG->at(i)->WST->at(j)->up));
                ui->tip->appendPlainText("     down:"+QString::asprintf("%.2f",parts->SEG->at(i)->WST->at(j)->down));
                ui->tip->appendPlainText("     normal:"+QString::asprintf("%.2f",parts->SEG->at(i)->WST->at(j)->normal));
                ui->tip->appendPlainText("\n");
            }
            ui->tip->appendPlainText("\n");
            ui->tip->appendPlainText("DB:");
            for(int j=0;j<parts->SEG->at(i)->DB->size();j++){
                ui->tip->appendPlainText("     name:"+parts->SEG->at(i)->DB->at(j)->name);
                ui->tip->appendPlainText("     id:"+parts->SEG->at(i)->DB->at(j)->id);
                ui->tip->appendPlainText("     icon:"+parts->SEG->at(i)->DB->at(j)->icon);
                ui->tip->appendPlainText("     lan:");
                for(int k=0;k<parts->SEG->at(i)->DB->at(j)->lan->size();k++){
                    ui->tip->appendPlainText("          "+parts->SEG->at(i)->DB->at(j)->lan->at(k).name);
                }
                ui->tip->appendPlainText("     adb:");
                for(int k=0;k<parts->SEG->at(i)->DB->at(j)->adb->size();k++){
                    ui->tip->appendPlainText("          name:"+parts->SEG->at(i)->DB->at(j)->adb->at(k)->name);
                    ui->tip->appendPlainText("          up:"+QString::asprintf("%d",parts->SEG->at(i)->DB->at(j)->adb->at(k)->up));
                    ui->tip->appendPlainText("          down:"+QString::asprintf("%d",parts->SEG->at(i)->DB->at(j)->adb->at(k)->down));
                    ui->tip->appendPlainText("\n");
                }
                ui->tip->appendPlainText("     cha:");
                for(int k=0;k<parts->SEG->at(i)->DB->at(j)->cha->size();k++){
                    ui->tip->appendPlainText("          "+parts->SEG->at(i)->DB->at(j)->cha->at(k).name);
                }
                ui->tip->appendPlainText("     dictionary:");
                for(int k=0;k<parts->SEG->at(i)->DB->at(j)->dictionary->size();k++){
                    ui->tip->appendPlainText("          name:"+parts->SEG->at(i)->DB->at(j)->dictionary->at(k)->name);
                    ui->tip->appendPlainText("          C:"+parts->SEG->at(i)->DB->at(j)->dictionary->at(k)->C);
                    ui->tip->appendPlainText("          V1:"+parts->SEG->at(i)->DB->at(j)->dictionary->at(k)->V1);
                    ui->tip->appendPlainText("          V2:"+parts->SEG->at(i)->DB->at(j)->dictionary->at(k)->V2);
                    ui->tip->appendPlainText("          V3:"+parts->SEG->at(i)->DB->at(j)->dictionary->at(k)->V3);
                    ui->tip->appendPlainText("          CP:"+QString::asprintf("%.2f",parts->SEG->at(i)->DB->at(j)->dictionary->at(k)->CP));
                    ui->tip->appendPlainText("          V1P:"+QString::asprintf("%.2f",parts->SEG->at(i)->DB->at(j)->dictionary->at(k)->V1P));
                    ui->tip->appendPlainText("          V2P:"+QString::asprintf("%.2f",parts->SEG->at(i)->DB->at(j)->dictionary->at(k)->V2P));
                    ui->tip->appendPlainText("          V3P:"+QString::asprintf("%.2f",parts->SEG->at(i)->DB->at(j)->dictionary->at(k)->V3P));
                    ui->tip->appendPlainText("          P1:"+QString::asprintf("%.2f",parts->SEG->at(i)->DB->at(j)->dictionary->at(k)->P1));
                    ui->tip->appendPlainText("          P2:"+QString::asprintf("%.2f",parts->SEG->at(i)->DB->at(j)->dictionary->at(k)->P2));
                    ui->tip->appendPlainText("\n");
                }
                ui->tip->appendPlainText("\n");
            }
            ui->tip->appendPlainText("\n");
        }
        ui->tip->appendPlainText("\n");
        ui->tip->appendPlainText("AEG\n");
        for(int i=0;i<parts->AEG->size();i++){
            ui->tip->appendPlainText("name:"+parts->AEG->at(i)->name);
            ui->tip->appendPlainText("id:"+parts->AEG->at(i)->id);
            ui->tip->appendPlainText("icon:"+parts->AEG->at(i)->icon);
            ui->tip->appendPlainText("     eff:");
            for(int j=0;j<parts->AEG->at(i)->EFF->size();j++){
                ui->tip->appendPlainText("     name:"+parts->AEG->at(i)->EFF->at(j)->name);
                ui->tip->appendPlainText("     sets:");
                for(int k=0;k<parts->AEG->at(i)->EFF->at(j)->sets->size();k++){
                    ui->tip->appendPlainText("          name:"+parts->AEG->at(i)->EFF->at(j)->sets->at(k)->name);
                    ui->tip->appendPlainText("          up:"+QString::asprintf("%.2f",parts->AEG->at(i)->EFF->at(j)->sets->at(k)->up));
                    ui->tip->appendPlainText("          down:"+QString::asprintf("%.2f",parts->AEG->at(i)->EFF->at(j)->sets->at(k)->down));
                    ui->tip->appendPlainText("          normal:"+QString::asprintf("%.2f",parts->AEG->at(i)->EFF->at(j)->sets->at(k)->normal));
                    ui->tip->appendPlainText("\n");
                }
                ui->tip->appendPlainText("\n");
            }
            ui->tip->appendPlainText("\n");
        }
        ui->tip->appendPlainText("\n");
        ui->tip->appendPlainText("PLU\n");
        for(int i=0;i<parts->PLU->size();i++){
            ui->tip->appendPlainText("name:"+parts->PLU->at(i)->name);
            ui->tip->appendPlainText("id:"+parts->PLU->at(i)->id);
            ui->tip->appendPlainText("\n");
        }
        ui->tip->appendPlainText("\n");
        ui->tip->appendPlainText("Done!!\n");
        delete lcc;
    }
