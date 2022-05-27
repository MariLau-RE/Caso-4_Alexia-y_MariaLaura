#include <bits/stdc++.h>
#include <time.h>
#include <vector>
#include <stdlib.h> 

#define STB_IMAGE_IMPLEMENTATION
#include "headers/stb_image.h"
#include "headers/quadrant.hpp"
#include "headers/RGB.hpp"
#include "headers/grayscale.cpp"

using namespace std;



void sampling(int widthImage, int heightImage, unsigned char *image) {

    // Generate a random point
    int randomPointPosX, randomPointPosY;

    srand(time(0)); // Use current time as seed for random generator
    randomPointPosX = rand() % widthImage + 1;
    randomPointPosY = rand() % heightImage + 1;

    // Calculate the RGB of the random point
    RGB imageRGB = RGB(image, randomPointPosX, randomPointPosY, widthImage); // instance of RGB class
    stbi_image_free(image);

    // Calculate the area
    int maxPointX = -1, maxPointY = -1, minPointY = -1, minPointX = -1;
    int lastPointPosX = 0, lastPointPosY = 0;
    int areaPoints = 0, widthArea = 0, heightArea= 0;
    vector<vector<int>> pointsList;

    for(int i=0; i<3; i++){
        if (pointsList.empty()){
            pointsList.push_back({randomPointPosX,randomPointPosY});
        }
        else{
            randomPointPosX = rand() % widthImage + 1;
            randomPointPosY = rand() % heightImage + 1;

            // si el color es parecido (usar lo de la clase RGb para get los colores) entonces
                // aqui creo que funcion que recorra toda las lista de puntos y compare area para saber en cual se agrega
            // else
                vector<int> lastPoint = pointsList.back(); // Get the last element of pointsList
                lastPointPosX = lastPoint[0];
                lastPointPosY = lastPoint[1];

                // Check the maximum and minimum points
                if (maxPointX == -1 && maxPointY == -1 && minPointX == -1 && minPointY == -1){
                    if (lastPointPosX >= randomPointPosX){
                        minPointX = randomPointPosX;
                        maxPointX = lastPointPosX;
                    }
                    else{
                        minPointX = lastPointPosX;
                        maxPointX = randomPointPosX;
                    }
                    if (lastPointPosY >= randomPointPosY){
                        minPointY = randomPointPosY;
                        maxPointY = lastPointPosY;
                    }
                    else{ 
                        minPointY = lastPointPosY;
                        maxPointY = randomPointPosY;
                    }
                }
                else {
                    if (randomPointPosX > maxPointX){
                        maxPointX = randomPointPosX;
                    }
                    if (randomPointPosY > maxPointY){
                        maxPointY = randomPointPosY;
                    }
                    if (randomPointPosY < minPointY){
                        minPointY = randomPointPosY;
                    }
                    if (randomPointPosX < minPointX){
                        minPointX = randomPointPosX;
                    }
                }

                pointsList.push_back({randomPointPosX,randomPointPosY}); // agrega el punto random
        
                if (randomPointPosX <= minPointX){ 
                    widthArea = abs(randomPointPosX - maxPointX); 
                }
                if (randomPointPosX >= maxPointX){ 
                    widthArea = abs(randomPointPosX - minPointX); 
                }
                if (randomPointPosY <= minPointY){ 
                    heightArea = abs(randomPointPosY - maxPointY); 
                }
                if (randomPointPosY >= maxPointY){ 
                    heightArea = abs(randomPointPosY - minPointY); 
                }

                areaPoints = widthArea * heightArea;
                cout << endl;
                cout << "Iteracion numero " << i << endl;
                cout << "areaPoints: " << areaPoints << endl;
                // aqui se guarda el area etc etc
        }
    }
}

int main(){
    // Load image
    int widthImage, heightImage, channelsImage;
    unsigned char *image = stbi_load("images/image.jpg", &widthImage, &heightImage, &channelsImage, 0);

    if(image == NULL) { 
        cout << "Image not loaded" << endl;
    } 
    else {
        sampling(widthImage, heightImage, image);
    }
}

