#include <bits/stdc++.h>
#include <time.h>
#include <vector>
#include <tuple>
#include <stdlib.h> 

#define STB_IMAGE_IMPLEMENTATION
#include "headers/stb_image.h"
#include "headers/quadrant.hpp"
#include "headers/RGB.hpp"
#include "headers/grayscale.cpp"

using namespace std;

int calculateDimensions(int randomPointPosX, int randomPointPosY, int minPointX, int minPointY, int maxPointX, int maxPointY){
    int width = 0;
    int height = 0;

    if (randomPointPosX <= minPointX){ 
        width = abs(randomPointPosX - maxPointX); 
    }
    if (randomPointPosX >= maxPointX){ 
        width = abs(randomPointPosX - minPointX); 
    }
    if (randomPointPosY <= minPointY){ 
        height = abs(randomPointPosY - maxPointY); 
    }
    if (randomPointPosY >= maxPointY){ 
        height = abs(randomPointPosY - minPointY); 
    }

    return height * width;
}

void sampling(int widthImage, int heightImage, unsigned char *image, RGB imageRGB) {
    // Generate a random point
    int randomPointPosX, randomPointPosY;

    srand(time(0)); // Use current time as seed for random generator
    randomPointPosX = rand() % widthImage + 1;
    randomPointPosY = rand() % heightImage + 1;

    // Calculate the area
    int maxPointX = -1, maxPointY = -1, minPointY = -1, minPointX = -1;
    int lastPointPosX = 0, lastPointPosY = 0;
    int areaPoints = 0, widthArea = 0, heightArea= 0;
    vector<vector<int>> pointsList;
    vector<vector<int>> areasList;
    vector<vector<int>> tableProbs;
    int pixels = ((widthImage * heightImage) * 0.40);

    while (pixels > 0) {
        int totalPoints = 0;

        if (pointsList.empty()){
            pointsList.push_back({randomPointPosX,randomPointPosY});
        }
        else{
            // calculateTableProbs(lista de areas)

            randomPointPosX = rand() % widthImage + 1;
            randomPointPosY = rand() % heightImage + 1;

            vector<int> lastPoint = pointsList.back(); // Get the last element of pointsList
            lastPointPosX = lastPoint[0];
            lastPointPosY = lastPoint[1];

            // si el color del last NO es parecido al random (usar lo de la clase RGb para get los colores) entonces
                // funcion que recorre todas las areas para saber en cual area queda segun color, return vector area, indice
                // de la area que si sea saco el maximo de X y Y, minimo de X y y, puntostotales

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
                    if (randomPointPosX > maxPointX){ maxPointX = randomPointPosX; }
                    if (randomPointPosY > maxPointY){ maxPointY = randomPointPosY; }
                    if (randomPointPosY < minPointY){ minPointY = randomPointPosY; }
                    if (randomPointPosX < minPointX){ minPointX = randomPointPosX; }
                }
            
            pointsList.push_back({randomPointPosX,randomPointPosY});
            areaPoints = calculateDimensions(randomPointPosX, randomPointPosY, minPointX, minPointY, maxPointX, maxPointY);

            // si el color del last NO es parecido al random (usar lo de la clase RGb para get los colores) entonces
                //reemplzar datos con los que se sacaron
            //else
                areasList.push_back({areaPoints});
        }
        pixels --;
    }
}

int main(){
    // Load image
    int widthImage, heightImage, channelsImage;
    unsigned char *image = stbi_load("images/image.jpg", &widthImage, &heightImage, &channelsImage, 0);

    RGB imageRGB = RGB(image, widthImage); // instance of RGB class
    stbi_image_free(image);

    if(image == NULL) { 
        cout << "Image not loaded" << endl;
    } 
    else {
        sampling(widthImage, heightImage, image, imageRGB);
    }
}

