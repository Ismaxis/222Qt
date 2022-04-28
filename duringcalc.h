#ifndef DURINGCALC_H
#define DURINGCALC_H

#include <QDialog>
#include "Table.h"
#include "funcs.h"

extern Table table;

extern float RFuel;
extern float RAir;
extern float a;
extern float L0;

namespace Ui {
class DuringCalc;
}

class DuringCalc : public QDialog
{
    Q_OBJECT

public:
    explicit DuringCalc(QWidget *parent = nullptr);
    ~DuringCalc();

private slots:
    void on_pb_calcAir_clicked();

    void on_pb_calcFuel_clicked();

    void on_pb_calcMix_clicked();

private:
    Ui::DuringCalc *ui;
};

#endif // DURINGCALC_H
