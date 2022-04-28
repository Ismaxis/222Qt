#include "tempcalc.h"
#include "ui_tempcalc.h"
#include "funcs.cpp"

TempCalc::TempCalc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TempCalc)
{
    ui->setupUi(this);
}

TempCalc::~TempCalc()
{
    delete ui;
}

void TempCalc::on_pb_calcAir_clicked()
{
    float temp = ui->le_air->text().toFloat();
    float CpAir = 0;
    if(ui->radioButton_pmi->isChecked())
    {
        CpAir = Cp(temp, CpmiLowAir, CpmiHighAir, tLow, tHigh);
    }
    else if(ui->radioButton_pms->isChecked())
    {
        CpAir = Cp(temp, CpmsLowAir, CpmsHighAir, tLow, tHigh);
    }
    ui->output_air->setText(QString::number(CpAir));
    ui->le_capAir->setText(QString::number(CpAir));
}


void TempCalc::on_pb_calcFuel_clicked()
{
    float temp = ui->le_fuel->text().toFloat();
    float CpFuel = 0;
    if(ui->radioButton_pmi->isChecked())
    {
        CpFuel = Cp(temp, CpmiLowFuel, CpmiHighFuel, tLow, tHigh);
    }
    else if(ui->radioButton_pms->isChecked())
    {
        CpFuel = Cp(temp, CpmsLowFuel, CpmsHighFuel, tLow, tHigh);
    }
    ui->output_fuel->setText(QString::number(CpFuel));
    ui->le_capFuel->setText(QString::number(CpFuel));
}


void TempCalc::on_pb_calcMix_clicked()
{
    float CpAir = ui->le_capAir->text().toFloat();
    float CpFuel = ui->le_capFuel->text().toFloat();

    float CpMix = Cpmix(a, L0, CpAir, CpFuel);
    ui->output_mix->setText(QString::number(CpMix));
}

