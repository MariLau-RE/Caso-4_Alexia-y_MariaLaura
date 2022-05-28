#ifndef _GENETICBASE_
#define _GENETICBASE_ 1
#include "headers/cromodistribution.h"
#include "headers/individual.h"
#include <vector>

using namespace std;

class GeneticBase {
    private:
        vector<cromodistribution*> *representation;
        vector<individual*> *population;
        vector<individual*> *fitnessPopulation;
        vector<individual*> *unfitnessPopulation;
        int populationQuantity;
        int targetGenerations;
        int widthImage, heightImage;



        void evaluateFitness() {
            fitnessPopulation->clear();
            unfitnessPopulation->clear();

            for(int i=0;i<population->size(); i++) {
               population->at(i)->setFitnessValue(fitness(population->at(i)));
                // ajustarlo al fitness y fitness criteria del problema
                if (population->at(i)->getFitnessValue()>50) {  // fitness criteria of selection NEVER will be an absolute value, always is relative to the population
                    fitnessPopulation->push_back(population->at(i));
                } else {
                    unfitnessPopulation->push_back(population->at(i));
                }
            }
        }

        float fitness(individual *pIndividual)     {
        int Fitness = 0;
        int distance;

        for (individual *ind : *population)
        {
            // si las distancias relativas estÃ¡n entre sÃ­ a X unidades de distancia se consideran fit
            distance = abs(ind->getDistance() - pIndividual->getDistance());
            /*if (distance < )
            {
                Fitness++;
            }*/
        }
        cout << "Fitness value: " << Fitness << endl;
        return Fitness;
    }

        void reproduce(int pAmountOfChildrens) {
            // previous population will be cleared, full saved, partial saved --> depending on the problem
            population->clear();

            for(int i=0; i<pAmountOfChildrens; i++) {
                // select any two fitness parents
                int parent_a_index = rand()%fitnessPopulation->size();
                individual* parent_a = fitnessPopulation->at(parent_a_index);

                int parent_b_index = rand()%fitnessPopulation->size();
                individual* parent_b = fitnessPopulation->at(parent_b_index);

                population->push_back(cross(parent_a, parent_b));
            }
        }

        individual* cross(individual *pParent_a, individual *pParent_b) {
            // this operation will depends on: nibble size, si el punto de corte es fixed o variable point

            int cut_position = (rand() % (NIBBLE_SIZE-MIN_GENOTYPE_SIZE_BY_PARENT*2)) + MIN_GENOTYPE_SIZE_BY_PARENT;

            unsigned char mask_a = CROMO_MAX_VALUE - 1; // 255 -> 11111111
            mask_a <<= cut_position;

            unsigned char mask_b = CROMO_MAX_VALUE - 1; // 255 -> 11111111
            mask_b >>= NIBBLE_SIZE - cut_position;

            unsigned char kid = (pParent_a->getCromosoma() & mask_a) | (pParent_b->getCromosoma() & mask_b);

           // individual *children = new individual(kid , pointX1, pointY1, int pointX2, int pointY2, int pColor, int pSize, bool pShape);

            // hace falta la mutación, hay que agregar el % de mutación y la mutación en si misma
           // return children;
        }

    public:
        GeneticBase() {
            this->population = new vector<individual*>();
            this->fitnessPopulation = new vector<individual*>();
            this->unfitnessPopulation = new vector<individual*>();
            this->representation = new vector<cromodistribution*>(); 
            this->populationQuantity = 0;
            this->targetGenerations = 20;
        }

        void addDistribution(cromodistribution* pDistribution) {
            representation->push_back(pDistribution);
        }

        void initPopulation(int pAmountOfIndividuals) {
            population->clear();

            for(int i=0; i<pAmountOfIndividuals; i++) {
                // aqui está asumiendo nibble de 8 bits, unsigned char
               // individual* p = new individual((unsigned char) rand()%CROMO_MAX_VALUE);
                //population->push_back(p);
            }
        }
        
        void produceGenerations(int ptargetGenerations, int pChildrensPerGenerations) {
            for(int i=0; i<ptargetGenerations; i++) {
                evaluateFitness();
                reproduce(pChildrensPerGenerations);
            }
        }

        vector<individual*> getPopulation() {
            return *this->population;
        }
};

#endif