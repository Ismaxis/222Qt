#ifndef TEMPCALC_H
#define TEMPCALC_H

#include <QDialog>
#include "Sheet.h"
#include "tableData.h"
#include "funcs.h"

namespace Ui {
class TempCalc;
}

extern float RFuel;
extern float RAir;
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
