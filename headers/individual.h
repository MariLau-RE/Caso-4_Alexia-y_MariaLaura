#ifndef _INDIVIDUAL_
#define _INDIVIDUAL_ 1
#include "../main.hpp"
#define MIN_GENOTYPE_SIZE_BY_PARENT 2
#define BOUND_MARGIN 0.05

using namespace std;

class individual
{
private:
    // any important related info
    // decide the size of your nibble for your problem
    float fitnessValue;
    unsigned int cromosoma;
    pair<int, int> point;
    pair<int, int> secondPoint;
    int size;
    int color;
    int relativeDistance;
    bool type;

public:
    individual(unsigned int pValue, int p1X, int p1Y, int p2X, int p2Y, int pColor, int size, bool pType)
    {
        this->cromosoma = pValue;
        this->point = {p1X, p1Y};
        this->secondPoint = {p2X, p2Y};
        this->size = size;
        this->color = pColor;
        this->type = pType;
    }
    float distanceBetween2Points(int x1, int y1, int x2, int y2)
    {
        return sqrt((pow(x1 - x2, 2) + pow(y1 - y2, 2)));
    }

    int concatDistances(int topD, int botD, int leftD, int rightD)
    {
        string topS = to_string(topD);
        string botS = to_string(botD);
        string leftS = to_string(leftD);
        string rightS = to_string(rightD);
        // concatena los strings de las distancias
        return stol(topS + botS + leftS + rightS);
    }

    void setRelativeDistance(int imageWidth, int imageHeight)
    {
        pair<int, int> topBound, botBound, leftBound, rightBound;
        topBound = {imageWidth / 2, 0 + (BOUND_MARGIN * imageHeight)};
        botBound = {imageWidth / 2, imageHeight - (BOUND_MARGIN * imageHeight)};
        leftBound = {0 + (BOUND_MARGIN * imageWidth), imageHeight / 2};
        rightBound = {imageWidth - (BOUND_MARGIN * imageWidth), imageHeight / 2};

        // evalua las 4 distancias:
        int topDistance = distanceBetween2Points(point.first, point.second, topBound.first, topBound.second);
        int botDistance = distanceBetween2Points(point.first, point.second, botBound.first, botBound.second);
        int leftDistance = distanceBetween2Points(point.first, point.second, leftBound.first, leftBound.second);
        int rightpDistance = distanceBetween2Points(point.first, point.second, rightBound.first, rightBound.second);
        this->relativeDistance = concatDistances(topDistance, botDistance, leftDistance, rightpDistance);
        return;
    }

    bool operator>(const individual &other) const
    {
        return fitnessValue > other.getFitnessValue();
    }

    int getRelativeDistance()
    {
        return this->relativeDistance;
    }

    unsigned int getCromosoma()
    {
        return this->cromosoma;
    }

    void setFitnessValue(float pValue)
    {
        this->fitnessValue = pValue;
    }

    float getFitnessValue() const
    {
        return this->fitnessValue;
    }
    void setPoint(int x, int y)
    {
        this->point = {x, y};
    }

    pair<int, int> getPoint()
    {
        return this->point;
    }

    void setSecondPoint(int x, int y)
    {
        this->secondPoint = {x, y};
    }
    pair<int, int> getSecondPoint()
    {
        return this->secondPoint;
    }

    bool getType()
    {
        return this->type;
    }

    int getSize()
    {
        return this->size;
    }

    int getColor()
    {
        return this->color;
    }
};

#endif