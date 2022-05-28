#ifndef _INDIVIDUAL_
#define _INDIVIDUAL_ 1

#define MIN_GENOTYPE_SIZE_BY_PARENT 2

class individual {
    private: 
        // any important related info
        // decide the size of your nibble for your problem
        float fitnessValue;
        unsigned char cromosome;
    public:
        individual(unsigned char pValue) {
            this->cromosome = pValue;
        }

        unsigned char getCromosoma() {
            return this->cromosome;
        }

        void setFitnessValue(float pValue) {
            this->fitnessValue = pValue;
        }

        float getFitnessValue() {
            return this->fitnessValue;
        }
};


#endif