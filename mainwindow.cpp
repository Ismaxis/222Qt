#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect(ui->radioButton_inputType1, SIGNAL(clicked()), this, SLOT(inputType_changed()));
    //connect(ui->radioButton_inputType2, SIGNAL(clicked()), this, SLOT(inputType_changed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_temp_button_clicked()
{
    TempCalc calcWin(this);
    calcWin.exec();
}

