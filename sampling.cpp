#include <bits/stdc++.h>
#include <time.h>
#include <vector>
#include <tuple>
#include <stdlib.h> 

#define STB_IMAGE_IMPLEMENTATION
#include "headers/stb_image.h"
#include "headers/RGB.hpp"
#include "headers/grayscale.cpp"

using namespace std;

vector<vector<int>>Color={{12,12,12},{47,47,47},{50,50,50},{65,65,65},
{83,83,83},{135,135,135},{161,161,161},{195,195,195},{220,220,220},{242,242,242}};

bool grayIsClose(int pPointX, int pPointY, RGB imageRGB){
    imageRGB.generateRGB(pPointX,pPointY);
    for(int grayIndex=0; grayIndex<Color.size(); grayIndex++){
        int rDist = abs(imageRGB.getRedColor()- Color[grayIndex][0]);
        int gDist = abs(imageRGB.getGreenColor() - Color[grayIndex][1]);
        int bDist = abs(imageRGB.getBlueColor()- Color[grayIndex][2]);

        if(rDist + gDist + bDist > gray)
            return false;

        return true;
    }
}

int calculateDimensions(int pRandomPointPosX, int pRandomPointPosY, int pMinPointX, int pMinPointY, int pMaxPointX, int pMaxPointY){
    int width = 0;
    int height = 0;

    if (pRandomPointPosX <= pMinPointX){ 
        width = abs(pRandomPointPosX - pMaxPointX); 
    }
    if (pRandomPointPosX >= pMaxPointX){ 
        width = abs(pRandomPointPosX - pMinPointX); 
    }
    if (pRandomPointPosY <= pMinPointY){ 
        height = abs(pRandomPointPosY - pMaxPointX); 
    }
    if (pRandomPointPosY >= pMaxPointY){ 
        height = abs(pRandomPointPosY - pMinPointX); 
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

            imageRGB.generateRGB(randomPointPosX,randomPointPosY);
            int grayRandomConvertion=((imageRGB.getRedColor()+0.299)*(imageRGB.getGreenColor()+0.587)*(imageRGB.getBlueColor()+0.114));
            imageRGB.generateRGB(lastPointPosX,lastPointPosY);
            int grayLastConvertion=((imageRGB.getRedColor()+0.299)*(imageRGB.getGreenColor()+0.587)*(imageRGB.getBlueColor()+0.114));

            if (grayRandomConvertion == grayLastConvertion){ // it could not compare if they are similar
                // funcion que recorre todas las areas para saber en cual area queda segun min max, return vector area, indice
                // de la area que si sea saco el maximo de X y Y, minimo de X y y, puntostotales
            }

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
            totalPoints ++;
            areaPoints = calculateDimensions(randomPointPosX, randomPointPosY, minPointX, minPointY, maxPointX, maxPointY);

            // si el color del last es parecido al random entonces
                //reemplazar datos con los que se sacaron
            //else
                areasList.push_back({areaPoints, totalPoints, maxPointX, maxPointY, minPointX, minPointY});
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

