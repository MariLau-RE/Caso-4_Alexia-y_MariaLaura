#ifndef _CROMODISTRIBUTION_
#define _CROMODISTRIBUTION_ 1

#define CROMO_MAX_VALUE 4294967296
#define NIBBLE_SIZE 32

using namespace std;


struct cromodistribution
{
    // centroide y valores de lineas
    int x1Value;
    int y1Value;
    int x2Value;
    int y2Value;
    // tamaño en pixeles
    int area;
    // color grayscale
    int color;
    // true-> punto, false-> linea
    bool tipo;
    // rango probabilidad

    float minProbability;
    float maxProbability;
    // rango valores del gen
    unsigned int minValue;
    unsigned int maxValue;
    // cantidad de pixeles
    int quantity;
    // total poblacion
    int totalPopulation;
};

#endif