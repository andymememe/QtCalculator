#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->display = "0"; // Displaying word
    this->endCalee = false; // Manipulate counter part or not
    this->point=false; // Decimal part or not
    this->error=false; // Error
    this->prec=0; // Precision
    this->func=0; // Function ID
    this->calee=0; // Be Counted
    this->calor=0; // Counter
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()){
    case Qt::Key_1:
    case (Qt::KeypadModifier + Qt::Key_1):
        this->on_oneBtn_clicked();
        break;
    case Qt::Key_2 :
    case (Qt::KeypadModifier + Qt::Key_2) :
        this->on_twoBtn_clicked();
        break;
    case Qt::Key_3:
    case (Qt::KeypadModifier + Qt::Key_3):
        this->on_threeBtn_clicked();
        break;
    case Qt::Key_4:
    case (Qt::KeypadModifier + Qt::Key_4):
        this->on_fourBtn_clicked();
        break;
    case Qt::Key_5:
    case (Qt::KeypadModifier + Qt::Key_5):
        this->on_fiveBtn_clicked();
        break;
    case Qt::Key_6:
    case (Qt::KeypadModifier + Qt::Key_6):
        this->on_sixBtn_clicked();
        break;
    case Qt::Key_7:
    case (Qt::KeypadModifier + Qt::Key_7):
        this->on_sevenBtn_clicked();
        break;
    case Qt::Key_8:
    case (Qt::KeypadModifier + Qt::Key_8):
        this->on_eightBtn_clicked();
        break;
    case Qt::Key_9:
    case (Qt::KeypadModifier + Qt::Key_9):
        this->on_nineBtn_clicked();
        break;
    case Qt::Key_0:
    case (Qt::KeypadModifier + Qt::Key_0):
        this->on_zeroBtn_clicked();
        break;
    case Qt::Key_Backspace:
        this->on_acBtn_clicked();
        break;
    case Qt::Key_Plus:
    case (Qt::KeypadModifier + Qt::Key_Plus):
        this->on_plusBtn_clicked();
        break;
    case Qt::Key_Minus:
    case (Qt::KeypadModifier + Qt::Key_Minus):
        this->on_minBtn_clicked();
        break;
    case Qt::Key_Asterisk:
    case (Qt::KeypadModifier + Qt::Key_Asterisk):
        this->on_mulBtn_clicked();
        break;
    case Qt::Key_Slash:
    case (Qt::KeypadModifier + Qt::Key_Slash):
        this->on_divBtn_clicked();
        break;
    case Qt::Key_Period:
    case (Qt::KeypadModifier + Qt::Key_Period):
        this->on_pointBtn_clicked();
        break;
    case Qt::Key_Enter:
    case (Qt::KeypadModifier + Qt::Key_Enter):
        this->on_equBtn_clicked();
        break;
    }
}

/**********************/
/* Add number in variable */
/**********************/
void MainWindow::addNum(int add)
{
    /* Add in the counter part */
    if(this->endCalee && !(this->error)){
        /* Add in the decimal part */
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
        /* Add in the integer part */
        else if(!(this->point) && this->calor < 10000000){
            this->calor = (this->calor * 10.0) + add ;
            this->display = QString::number(this->calor, 'G', 8);
        }
        ui->result->display(this->display);
    }
    /* Add in the be-counted part */
    else if(!(this->endCalee) && !(this->error)){
        /* Add in the decimal part */
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
        /* Add in the integer part */
        else if(!(this->point) && this->calee < 10000000){
            this->calee = (this->calee * 10.0) + add;
            this->display = QString::number(this->calee, 'G', 8);
        }
        ui->result->display(this->display);
    }
}

/**********/
/* Calculate */
/**********/
void MainWindow::cal()
{
    if(this->error){
        return;
    }
    switch(this->func){
    /* Add */
    case 1:
        calee = calee + calor;
        break;
    /* Minus */
    case 2:
        calee = calee - calor;
        break;
    /* Multiple */
    case 3:
        calee = calee * calor;
        break;
    /* Divide */
    case 4:
        calee = calee / calor;
        break;
    }

    /* Error detect */
    if(calee < 100000000){
        ui->result->display(calee);
    }
    else{
        this->display = "ERROR";
        ui->result->display(this->display);
        this->error = true;
    }
}

/****************/
/* Reset Everything */
/****************/
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

/******/
/* Slot */
/******/

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
        this->point = false;
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
        this->point = false;
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
        this->point = false;
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
        this->point = false;
        this->func = 4;
    }
}
