#include <iostream>
#include "genetic.h"
#include "headers/cromodistribution.h"
#include <vector>
#include "headers/individual.h"
#include "SocketClient/socketWin.cpp"


using namespace std;

#define DISTRIBUTION_SIZE 3

int main() {

    // #0 prueba de que funciona 
    
    // class creation
    GeneticBase genetic;

    // 1. Chromosomatic representation
    cromodistribution distribution[DISTRIBUTION_SIZE] = {
        /*{True, 0, 99, 0.00, 0.39, 400, 1000},
        {False, 100, 199, 0.39, 0.78, 400, 1000},
        {True, 200, 255, 0.78, 1.00, 200, 1000}*/
    };


    for(int i=0; i<DISTRIBUTION_SIZE; i++) {
        genetic.addDistribution(&distribution[i]);
    }


    // 2. Initial population of individuals
    genetic.initPopulation(10);

    cout << "initial population" << endl;
    vector<individual*> result = genetic.getPopulation();
    for(int i=0; i<result.size(); i++) {
        cout << result.at(i)->getCromosoma() << endl;
    }

    // 3. measure the fitness of the population and reproduce it until reach the target generations
    // la cantidad de generaciones y cuantos hijos quiero hacer por generacion
    genetic.produceGenerations(3, 20);

    // check final population
    cout << "final population" << endl;
    result = genetic.getPopulation();
    for(int i=0; i<result.size(); i++) {
        cout << result.at(i)->getCromosoma() << endl;
    }
    
}