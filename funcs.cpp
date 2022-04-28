#include "funcs.h"

// air or fuel
float Cp(float temp, float CLow, float CHigh, float tLow, float tHigh)
{
    return CLow + (temp - tLow) / (tHigh - tLow) * (CHigh - CLow);
}

// air + fuel
float Cpmix(float a, float L0, float CpAir, float CpFuel)
{
    float aL0 = a * L0;
    return (aL0 - L0) / (1 + aL0) * CpAir + (1 + L0) / (1 + aL0) * CpFuel;
}

// air compress degree
float TendCompDegree(float Tstart, float degree, float R, float C,float eff)
{
    float newC, buffC = C;
    while(true)
    {
        newC = Tstart + Tstart * (pow(degree, R/buffC) - 1) / eff;
        if(abs(newC - buffC) / buffC < 0.01f)
        {
            buffC = newC;
            break;
        }
        buffC = newC;
    }
    return buffC;
}

// air compress Work
float TendCompWork(float Tstart, float work, float C, float eff)
{
    float newC, buffC = C;
    while(true)
    {
        newC = Tstart + work / (eff * buffC);
        if(abs(newC - buffC) / buffC < 0.01f)
        {
            buffC = newC;
            break;
        }
        buffC = newC;
    }
    return buffC;
}

// fuel or mix expand degree
float TendExpDegree(float Tstart, float degree, float R, float C,float eff)
{
    float newC, buffC = C;
    while(true)
    {
        newC = Tstart - Tstart * (1 - pow(degree, R/buffC)) * eff;
        if(abs(newC - buffC) / buffC < 0.01f)
        {
            buffC = newC;
            break;
        }
        buffC = newC;
    }
    return buffC;
}

// fuel or mix expand Work
float TendExpWork(float Tstart, float work, float C, float eff)
{
    float newC, buffC = C;
    while(true)
    {
        newC = Tstart - (work * eff) / buffC;
        if(abs(newC - buffC) / buffC < 0.01f)
        {
            buffC = newC;
            break;
        }
        buffC = newC;
    }
    return buffC;
}

float CAvgpmi(float Tstart, float Tend, float Cstart, float Cend)
{
    return (Cstart * Tstart - Cend * Tend) / (Tstart - Tend);
}

float CAvgpms(float Tstart, float Tend, float Cstart, float Cend) // t in celsius
{
    return (Cstart * log((Tstart + 273.15) / 273.15) - Cend * log((Tend + 273.15) / 273.15)) / log(Tstart/Tend);
}
