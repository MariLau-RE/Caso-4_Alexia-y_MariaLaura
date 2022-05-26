#include <bits/stdc++.h>
#include <time.h>
#include <vector>
#include <stdlib.h> 

#define STB_IMAGE_IMPLEMENTATION
#include "headers/stb_image.h"
#include "headers/quadrant.hpp"
#include "headers/RGB.hpp"

using namespace std;


void sampling() {
    
    // Get image data
    int widthImage, heightImage, channelsImage;

    unsigned char *image = stbi_load("images/image.jpg", &widthImage, &heightImage, &channelsImage, 0);
    size_t imageSize = widthImage * heightImage * channelsImage;
    int areaImage = widthImage * heightImage;

    if(image!=NULL) { 
        cout << "Image loaded successfully" << endl;
        cout << "Width: " << widthImage << endl;
        cout << "Height: " << heightImage << endl;
        cout << "Channels: " << channelsImage << endl;
        cout << "Image size: " << imageSize << endl;
    } else {
        cout << "Image not loaded" << endl;
    }

    // Generate a random point
    int randomPointPosX, randomPointPosY;

    srand(time(0)); // Use current time as seed for random generator
    randomPointPosX = rand() % widthImage + 1;
    randomPointPosY = rand() % heightImage + 1;

    cout << "pointX: " << randomPointPosX << endl;
    cout << "pointY: " << randomPointPosY << endl;

    // Calculate the RGB of the random point
    RGB imageRGB = RGB(image, randomPointPosX, randomPointPosY, widthImage); // instance of RGB class
    stbi_image_free(image);

    // Calculate the area
    int maxPointX, maxPointY, minPointY, minPointX;
    int lastPointPosX, lastPointPosY;
    int areaPoints, widthArea, heightArea;
    vector<vector<int>> pointsList;

    // aqui el loop de los pixeles
        if (pointsList.empty()){
            pointsList.push_back({randomPointPosX,randomPointPosY});
        }
        else{
            randomPointPosX = rand() % widthImage + 1;
            randomPointPosY = rand() % heightImage + 1;
            pointsList.push_back({randomPointPosX,randomPointPosY});

            // si el color es parecido (usar lo de la clase RGb para get los colores) entonces
                // aqui creo que funcion que recorra toda las lista de puntos y compare area para saber en cual se agrega
            // else
                vector<int> lastPoint = pointsList.back(); // Get the last element of pointsList
                lastPointPosX = pointsList.back()[0];
                lastPointPosY = pointsList.back()[1];

                // Check the maximum and minimum points
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
        
                if (randomPointPosX <= minPointX){ widthArea = abs(randomPointPosX - maxPointX); }
                if (randomPointPosX >= maxPointX){ widthArea = abs(randomPointPosX - minPointX); }
                if (randomPointPosY <= minPointY){ heightArea = abs(randomPointPosY - maxPointY); }
                if (randomPointPosY >= maxPointY){ heightArea = abs(randomPointPosY - minPointY); }

                areaPoints = widthArea * heightArea;
                // aqui se guarda el area etc etc
        }
}

int main(){

    sampling();

}
