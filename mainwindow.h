#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_sevenBtn_clicked();

    void on_eightBtn_clicked();

    void on_nineBtn_clicked();

    void on_fourBtn_clicked();

    void on_fiveBtn_clicked();

    void on_sixBtn_clicked();

    void on_oneBtn_clicked();

    void on_twoBtn_clicked();

    void on_threeBtn_clicked();

    void on_pointBtn_clicked();

    void on_zeroBtn_clicked();

    void on_acBtn_clicked();

    void on_equBtn_clicked();

    void on_plusBtn_clicked();

    void on_minBtn_clicked();

    void on_mulBtn_clicked();

    void on_divBtn_clicked();

private:
    Ui::MainWindow *ui;

    QString display;

    bool endCalee;
    bool point;
    bool error;

    int prec;
    int func;

    double calee;
    double calor;

    void addNum(int add);
    void cal();
    void resetVar();
};

#endif // MAINWINDOW_H
