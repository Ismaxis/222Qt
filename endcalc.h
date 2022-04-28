#ifndef ENDCALC_H
#define ENDCALC_H

#include <QDialog>
#include "Sheet.h"
#include "tableData.h"
#include "funcs.h"

extern float RAir;
extern float RFuel;
extern float a;
extern float L0;

namespace Ui {
class EndCalc;
}

class EndCalc : public QDialog
{
    Q_OBJECT

public:
    explicit EndCalc(QWidget *parent = nullptr);
    ~EndCalc();

private slots:
    void on_pb_calcAir_clicked();

    void on_radioButton_degree_clicked();

    void on_radioButton_work_clicked();

    void on_pb_calcFuel_clicked();

    void on_pb_calcMix_clicked();

private:
    Ui::EndCalc *ui;
    std::vector<std::vector<std::vector<float>>> tables;

    TableData getData(float temp, int tabelId, int pmiOrPms = 2);
};

#endif // ENDCALC_H
