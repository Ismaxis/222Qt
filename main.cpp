#include "mainwindow.h"

#include <QApplication>

float RFuel = 290.1;
float RAir = 287.0;

float tLow = 1000; // celsius
float CpmiLowFuel = 1.2078f;
float CpmsLowFuel = 1.1718f;
float CpmiLowAir = 1.0907f;
float CpmsLowAir = 1.0659f;

float tHigh = 1050;
float CpmiHighFuel = 1.2143f;
float CpmsHighFuel = 1.1761f;
float CpmiHighAir = 1.0954f;
float CpmsHighAir = 1.0689f;

float a = 3;
float L0 = 12;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
