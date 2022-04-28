#include "mainwindow.h"
#include "Table.h"

#include <QApplication>

Table table;

float RFuel = 290.1;
float RAir = 287.0;
float a = 3;
float L0 = 12;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
