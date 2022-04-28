#include "tempcalc.h"
#include "ui_tempcalc.h"

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

    int pmiOrPms = 2; // pmi default
    if(ui->radioButton_pms->isChecked())
    {
        pmiOrPms = 3;
    }

    TableData data = table.getData(temp , 0, pmiOrPms);

    float CpAir = Cp(temp, data.cLow, data.cHigh, data.tLow, data.tHigh);
    ui->output_air->setText(QString::number(CpAir));
    ui->le_capAir->setText(QString::number(CpAir));
}

void TempCalc::on_pb_calcFuel_clicked()
{
    float temp = ui->le_fuel->text().toFloat();

    int pmiOrPms = 2; // pmi default
    if(ui->radioButton_pms->isChecked())
    {
        pmiOrPms = 3;
    }

    TableData data = table.getData(temp , 1, pmiOrPms);

    float CpFuel = Cp(temp, data.cLow, data.cHigh, data.tLow, data.tHigh);
    ui->output_fuel->setText(QString::number(CpFuel));
    ui->le_capFuel->setText(QString::number(CpFuel));
}


void TempCalc::on_pb_calcMix_clicked()
{
    float CpAir = ui->le_capAir->text().toFloat();
    float CpFuel = ui->le_capFuel->text().toFloat();

    float CpMix = Cpmix(a, L0, CpAir, CpFuel); // a and L0 must takes from other module

    ui->output_mix->setText(QString::number(CpMix));
}

