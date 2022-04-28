#include "duringcalc.h"
#include "ui_duringcalc.h"

DuringCalc::DuringCalc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DuringCalc)
{
    ui->setupUi(this);
}

DuringCalc::~DuringCalc()
{
    delete ui;
}

void DuringCalc::on_pb_calcAir_clicked()
{
    float tempStart = ui->le_tempStartAir->text().toFloat();
    float tempEnd = ui->le_tempEndAir->text().toFloat();

    int pmiOrPms = 2; // pmi default
    if(ui->radioButton_pms->isChecked())
    {
        pmiOrPms = 3;
    }

    TableData dataStart = table.getData(tempStart , 0, pmiOrPms);
    TableData dataEnd = table.getData(tempEnd , 0, pmiOrPms);

    float CpAirStart = Cp(tempStart, dataStart.cLow, dataStart.cHigh, dataStart.tLow, dataStart.tHigh);
    float CpAirEnd = Cp(tempStart, dataEnd.cLow, dataEnd.cHigh, dataEnd.tLow, dataEnd.tHigh);

    float CpAirAvg = CAvgpmi(tempStart, tempEnd, CpAirStart, CpAirEnd); // avg capacity of air during process

    ui->output_air->setText(QString::number(CpAirAvg));
    ui->le_capAir->setText(QString::number(CpAirAvg));
}


void DuringCalc::on_pb_calcFuel_clicked()
{
    float tempStart = ui->le_tempStartFuel->text().toFloat();
    float tempEnd = ui->le_tempEndFuel->text().toFloat();

    int pmiOrPms = 2; // pmi default
    if(ui->radioButton_pms->isChecked())
    {
        pmiOrPms = 3;
    }

    TableData dataStart = table.getData(tempStart , 1, pmiOrPms);
    TableData dataEnd = table.getData(tempEnd , 1, pmiOrPms);

    float CpFuelStart = Cp(tempStart, dataStart.cLow, dataStart.cHigh, dataStart.tLow, dataStart.tHigh);
    float CpFuelEnd = Cp(tempStart, dataEnd.cLow, dataEnd.cHigh, dataEnd.tLow, dataEnd.tHigh);

    float CpFuelAvg = CAvgpmi(tempStart, tempEnd, CpFuelStart, CpFuelEnd); // avg capacity of air during process

    ui->output_fuel->setText(QString::number(CpFuelAvg));
    ui->le_capFuel->setText(QString::number(CpFuelAvg));
}


void DuringCalc::on_pb_calcMix_clicked()
{
    float CpAirAvg = ui->le_capAir->text().toFloat();
    float CpFuelAvg = ui->le_capFuel->text().toFloat();

    float CAvgMix = Cpmix(a, L0, CpAirAvg, CpFuelAvg); // avg capacity of mix during process

    ui->output_mix->setText(QString::number(CAvgMix));
}

