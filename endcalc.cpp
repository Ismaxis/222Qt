#include "endcalc.h"
#include "ui_endcalc.h"

EndCalc::EndCalc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndCalc)
{
    ui->setupUi(this);

    ui->le_workAir->hide();
    ui->le_workFuel->hide();
}

EndCalc::~EndCalc()
{
    delete ui;
}


void EndCalc::on_pb_calcAir_clicked()
{
    float temp = ui->le_tempAir->text().toFloat();
    float degree = ui->le_degreeAir->text().toFloat();
    float work = ui->le_workAir->text().toFloat();
    float eff = ui->le_effAir->text().toFloat();

    TableData data = table.getData(temp, 0); // pmi always

    float Cstart = Cp(temp, data.cLow, data.cHigh, data.tLow, data.tHigh);

    float Tend = 0;
    if(ui->radioButton_degree->isChecked())
    {
        Tend = TendCompDegree(temp, degree, RAir, Cstart, eff);
    }
    else if(ui->radioButton_work->isChecked())
    {
        Tend = TendCompWork(temp, work, Cstart, eff);
    }

    ui->output_air->setText(QString::number(Tend));
    ui->le_capAir->setText(QString::number(Tend));
}

void EndCalc::on_pb_calcFuel_clicked()
{
    float temp = ui->le_tempFuel->text().toFloat();
    float degree = ui->le_degreeFuel->text().toFloat();
    float work = ui->le_workFuel->text().toFloat();
    float eff = ui->le_effFuel->text().toFloat();

    TableData data = table.getData(temp, 1); // pmi always

    float Cstart = Cp(temp, data.cLow, data.cHigh, data.tLow, data.tHigh);

    float Tend = 0;
    if(ui->radioButton_degree->isChecked())
    {
        Tend = TendExpDegree(temp, degree, RFuel, Cstart, eff);
    }
    else if(ui->radioButton_work->isChecked())
    {
        Tend = TendExpWork(temp, work, Cstart, eff);
    }

    ui->output_fuel->setText(QString::number(Tend));
    ui->le_capFuel->setText(QString::number(Tend));
}

void EndCalc::on_radioButton_degree_clicked()
{
    ui->le_degreeAir->show();
    ui->le_degreeFuel->show();
    ui->le_workAir->hide();
    ui->le_workFuel->hide();
}


void EndCalc::on_radioButton_work_clicked()
{
    ui->le_degreeAir->hide();
    ui->le_degreeFuel->hide();
    ui->le_workAir->show();
    ui->le_workFuel->show();
}

void EndCalc::on_pb_calcMix_clicked()
{
    float CpAir = ui->le_capAir->text().toFloat();
    float CpFuel = ui->le_capFuel->text().toFloat();

    float CpMix = Cpmix(a, L0, CpAir, CpFuel); // a and L0 must takes from other module
    ui->output_mix->setText(QString::number(CpMix));
}

