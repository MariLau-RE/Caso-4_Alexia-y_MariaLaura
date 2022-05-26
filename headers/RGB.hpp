#include <bits/stdc++.h>
using namespace std;

class RGB{
    private:
        const size_t sizeRGB = 3;
        unsigned char *image;
        size_t indexRGB;
   
        int redColor;
        int greenColor;
        int blueColor;
        int widthImage;
        
    public:
        RGB(unsigned char *pImage, int pRandomPointX, int pRandomPointY, int pWidth){
            this->widthImage = pWidth;
            this->image = pImage;
            this->indexRGB = sizeRGB * (pRandomPointY * pWidth + pRandomPointX);
        }

        int getRedColor(){ return image[indexRGB + 0]; }
        int getGreenColor(){ return image[indexRGB + 1]; }
        int getBlueColor(){ return image[indexRGB + 2]; }
};