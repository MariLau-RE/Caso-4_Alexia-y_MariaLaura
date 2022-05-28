#include <iostream>
#include "genetic.h"
#include "headers/cromodistribution.h"
#include <vector>
#include "headers/individual.h"
#include "SocketClient/socketWin.cpp"

using namespace std;

#define DISTRIBUTION_SIZE 3

int main()
{

    socketclient client;

    // #0 prueba de que funciona

    // class creation
    GeneticBase genetic;

    // 1. Chromosomatic representation

    cromodistribution distribution[DISTRIBUTION_SIZE] =
        {
            {1000, 100, 1250, 275, 1000, 0, false, 0.0, 0.33, 0, 1417339208, 333, 1000},
            {214, 27, 500, 100, 420, 200, true, 0.34, 0.67, 1417339209, 2834678415, 333, 1000},
            {1000, 200, 842, 300, 420, 200, true, 0.67, 1.0, 2834678416, 4252017624, 334, 1000}};


    for (int i = 0; i < DISTRIBUTION_SIZE; i++)
    {
        genetic.addDistribution(&distribution[i]);
    }

    // 2. Initial population of individuals
    genetic.initPopulation(100);

    cout << "initial population" << endl;
    vector<individual *> result = genetic.getPopulation();
    for (int i = 0; i < result.size(); i++)
    {
        cout << result.at(i)->getCromosoma() << endl;
    }

    // 3. measure the fitness of the population and reproduce it until reach the target generations
    // la cantidad de generaciones y cuantos hijos quiero hacer por generacion
    genetic.produceGenerations(5, 200);

    // check final population
    cout << "final population" << endl;
    result = genetic.getPopulation();
    for (int i = 0; i < result.size(); i++)
    {
        cout << result.at(i)->getCromosoma();
        cout << "\t x: " << result.at(i)->getPoint().first << " y: " << result.at(i)->getPoint().second;
        cout << "\tcolor: " << result.at(i)->getColor() << endl;
    }
    client.init();
    cout << "init done" << endl;
    for (individual *ind : result)
    {
        int clr = ind->getColor();
        pair<int, int> coord = ind->getPoint();
        client.paintDot(clr, clr, clr, 255, coord.first, coord.second, 200);
        cout << "painted" << endl;
    }
    client.closeConnection();
}