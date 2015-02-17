#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->display = "0";
    this->endCalee = false;
    this->point=false;
    this->error=false;
    this->prec=0;
    this->func=0;
    this->calee=0;
    this->calor=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addNum(int add)
{
    if(this->endCalee && !(this->error)){
        if(this->point){
            double dAdd = add * 1.0;
            prec++;
            int i = 0;
            while(i < prec){
                dAdd = dAdd * 0.1;
                i++;
            }
            this->calor = this->calor + dAdd;
            this->display.append(QString::number(add));
        }
        else if(!(this->point) && this->calor < 10000000){
            this->calor = (this->calor * 10.0) + add ;
            this->display = QString::number(this->calor, 'G', 8);
        }
        ui->result->display(this->display);
    }
    else if(!(this->endCalee) && !(this->error)){
        if(this->point){
            double dAdd = add * 1.0;
            prec++;
            int i = 0;
            while(i < prec){
                dAdd = dAdd * 0.1;
                i++;
            }
            this->calee = this->calee + dAdd;
            this->display.append(QString::number(add));
        }
        else if(!(this->point) && this->calee < 10000000){
            this->calee = (this->calee * 10.0) + add;
            this->display = QString::number(this->calee, 'G', 8);
        }
        ui->result->display(this->display);
    }
}

void MainWindow::cal()
{
    if(this->error){
        return;
    }
    switch(this->func){
    case 1:
        calee = calee + calor;
        break;
    case 2:
        calee = calee - calor;
        break;
    case 3:
        calee = calee * calor;
        break;
    case 4:
        calee = calee / calor;
        break;
    }
    if(calee < 100000000){
        ui->result->display(calee);
    }
    else{
        this->display = "ERROR";
        ui->result->display(this->display);
        this->error = true;
    }
}

void MainWindow::resetVar()
{
    this->display = "0";
    this->endCalee = false;
    this->point=false;
    this->func=0;
    this->prec=0;
    this->calee=0;
    this->calor=0;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_sevenBtn_clicked()
{
    addNum(7);
}

void MainWindow::on_eightBtn_clicked()
{
    addNum(8);
}

void MainWindow::on_nineBtn_clicked()
{
    addNum(9);
}

void MainWindow::on_fourBtn_clicked()
{
    addNum(4);
}

void MainWindow::on_fiveBtn_clicked()
{
    addNum(5);
}

void MainWindow::on_sixBtn_clicked()
{
    addNum(6);
}

void MainWindow::on_oneBtn_clicked()
{
    addNum(1);
}

void MainWindow::on_twoBtn_clicked()
{
    addNum(2);
}

void MainWindow::on_threeBtn_clicked()
{
    addNum(3);
}

void MainWindow::on_zeroBtn_clicked()
{
    addNum(0);
}

void MainWindow::on_pointBtn_clicked()
{
    if(!(this->error)){
        this->point = true;
        this->display.append(".");
    }
}

void MainWindow::on_acBtn_clicked()
{
    this->resetVar();
    this->error = false;
    ui->result->display(this->display);
}

void MainWindow::on_equBtn_clicked()
{
    this->cal();
    this->resetVar();
}

void MainWindow::on_plusBtn_clicked()
{
    if(!(this->error)){
        this->cal();
        this->calor=0;
        this->display="0";
        this->endCalee = true;
        this->func = 1;
    }
}

void MainWindow::on_minBtn_clicked()
{
    if(!(this->error)){
        this->cal();
        this->calor=0;
        this->display="0";
        this->endCalee = true;
        this->func = 2;
    }
}

void MainWindow::on_mulBtn_clicked()
{
    if(!(this->error)){
        this->cal();
        this->calor=0;
        this->display="0";
        this->endCalee = true;
        this->func = 3;
    }
}

void MainWindow::on_divBtn_clicked()
{
    if(!(this->error)){
        this->cal();
        this->calor=0;
        this->display="0";
        this->endCalee = true;
        this->func = 4;
    }
}
