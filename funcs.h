#ifndef FUNCS_H
#define FUNCS_H
#include "math.h"

// air or fuel
float Cp(float temp, float CLow, float CHigh, float tLow, float tHigh);

// air + fuel
float Cpmix(float a, float L0, float CpAir, float CpFuel);

// air compress degree
float TendCompDegree(float Tstart, float degree, float R, float C,float eff);

// air compress Work
float TendCompWork(float Tstart, float work, float C, float eff);

// fuel or mix expand degree
float TendExpDegree(float Tstart, float degree, float R, float C,float eff);

// fuel or mix expand Work
float TendExpWork(float Tstart, float work, float C, float eff);

float CAvgpmi(float Tstart, float Tend, float Cstart, float Cend);

float CAvgpms(float Tstart, float Tend, float Cstart, float Cend);// t in celsius

#endif // FUNCS_H
