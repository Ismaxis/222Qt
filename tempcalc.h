#ifndef TEMPCALC_H
#define TEMPCALC_H

#include <QDialog>
#include "Sheet.h"
#include "tableData.h"

namespace Ui {
class TempCalc;
}

extern float RFuel;
extern float RAir;
extern float tLow;
extern float CpmiLowFuel;
extern float CpmsLowFuel;
extern float CpmiLowAir;
extern float CpmsLowAir;
extern float tHigh;
extern float CpmiHighFuel;
extern float CpmsHighFuel;
extern float CpmiHighAir;
extern float CpmsHighAir;
extern float a;
extern float L0;

class TempCalc : public QDialog
{
    Q_OBJECT

public:
    explicit TempCalc(QWidget *parent = nullptr);
    ~TempCalc();

private slots:
    void on_pb_calcAir_clicked();

    void on_pb_calcFuel_clicked();

    void on_pb_calcMix_clicked();

private:
    Ui::TempCalc *ui;
    std::vector<std::vector<std::vector<float>>> tables;

    TableData getData(float temp, int tabelId, int pmiOrPms);
};

#endif // TEMPCALC_H
