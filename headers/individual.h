#ifndef _INDIVIDUAL_
#define _INDIVIDUAL_ 1

#define MIN_GENOTYPE_SIZE_BY_PARENT 2

#include <math.h>

class individual {
    private: 
        // any important related info
        // decide the size of your nibble for your problem
        float fitnessValue;
        unsigned char cromosome;

        pair<int, int> pointX1Y1 ;
        pair<int, int> pointX2Y2;
        int size;
        int color;
        int Distance;
        bool shape;

        public:

    individual(unsigned int pValue, int pointX1, int pointY1, int pointX2, int pointY2, int pColor, int pSize, bool pShape)
    {
        this->cromosome = pValue;
        this->pointX1Y1 = {pointX1, pointY1};
        this->pointX2Y2 = {pointX2, pointY2};
        this->size = pSize;
        this->color = pColor;
        this->shape = pShape;
    }
    float distanceBetweenPoints(int x1, int y1, int x2, int y2)
    {
        return sqrt((pow(x2-x1, 2) + pow(y2-y1, 2)));
    }


    bool operator>(const individual &other) const
    {
        return fitnessValue > other.getFitnessValue();
    }

    int getDistance()
    {
        return this->Distance;
    }

    unsigned int getCromosoma()
    {
        return this->cromosome;
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
        this->pointX1Y1 = {x, y};
    }

    pair<int, int> getPoint()
    {
        return this->pointX1Y1;
    }

    void setSecondPoint(int x, int y)
    {
        this->pointX2Y2 = {x, y};
    }
    pair<int, int> getSecondPoint()
    {
        return this->pointX2Y2;
    }

    bool getType()
    {
        return this->shape;
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


