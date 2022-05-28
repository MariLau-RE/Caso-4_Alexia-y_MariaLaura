#ifndef _CROMODISTRIBUTION_
#define _CROMODISTRIBUTION_ 1

#define CROMO_MAX_VALUE 4294967296
#define NIBBLE_SIZE 32

using namespace std;

struct cromodistribution {
    int x1Coordinate;
    int x2Coordinate;
    int y1Coordinate;
    int y2Coordinate;
    int area;
    int grayscale;
    bool shape;
    float minProbability;
    float maxProbability;
    unsigned int minValue;
    unsigned int maxValue;
    int quantity;
    int totalPopulation;
};


#endif