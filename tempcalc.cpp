#include "tempcalc.h"
#include "ui_tempcalc.h"
#include "funcs.cpp"

TempCalc::TempCalc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TempCalc)
{
    ui->setupUi(this);
    Sheet reader;

    reader.setPath("D:/C++/222Qt/air.csv");
    tables.push_back(reader.readAsFloat());

    reader.setPath("D:/C++/222Qt/fuel.csv");
    tables.push_back(reader.readAsFloat());
}

TempCalc::~TempCalc()
{
    delete ui;
}

TableData TempCalc::getData(float temp, int tableId, int pmiOrPms)
{
    // 0 - air, 1 - fuel
    // 2 - pmi, 3 - pms;
    TableData result;

    for(int i = 1; i < tables[tableId].size(); i++)
    {
        if(tables[tableId][i][0] > temp)
        {
            result.tLow = tables[tableId][i - 1][0];
            result.cLow = tables[tableId][i - 1][pmiOrPms];
            result.tHigh = tables[tableId][i][0];
            result.cHigh = tables[tableId][i][pmiOrPms];
            break;
        }
    }
    return result;
}

void TempCalc::on_pb_calcAir_clicked()
{
    float temp = ui->le_air->text().toFloat();

    int pmiOrPms = 2; // pmi default
    if(ui->radioButton_pms->isChecked())
    {
        pmiOrPms = 3;
    }

    TableData curData = getData(temp , 0, pmiOrPms);

    float CpAir = Cp(temp, curData.cLow, curData.cHigh, curData.tLow, curData.tHigh);
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

    TableData curData = getData(temp , 1, pmiOrPms);

    float CpFuel = Cp(temp, curData.cLow, curData.cHigh, curData.tLow, curData.tHigh);
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

