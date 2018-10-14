#include <iostream>
#include "../../lib/CImg.templ"
#include "B.h"

using namespace std;
using namespace cimg_library;

CImg<int> brightness(CImg<int> img, char* val) {
    int value = atoi(val);
    //CImg<int> brightimg(img.width(),img.height(),1,3,0);
    for (int i=0; i<img.width(); i++){
        for (int j=0;j<img.height();j++){
            for (int k=0;k<3;k++){
                if(img(i,j,0,k)+value<0) img(i,j,0,k)=0;
                else if(img(i,j,0,k)+value>255) img(i,j,0,k)=255;
                else img(i,j,0,k)=img(i,j,0,k)+value;
            }
        }
    }
    img.save("modified.bmp");
    return img;
}

CImg<int> contrast(CImg<int> img, char* val) {
    float value = atof(val);
    if (value < 0) {cout << "Contrast value must be greater than 0 "; exit(0);}
    /*float beta = 128 - 128 * value;
    for (int x = 0; x < img.width(); x++) {
        for (int y = 0; y < img.height(); y++) {
            for (int j = 0; j < 3; j++) {
                if (value * img(x, y, 0, j) + beta > 255) img(x, y, 0, j) = 255;
                else if (value * img(x, y, 0, j) + beta < 0) img(x, y, 0, j) = 0;
                else img(x, y, 0, j) = value * img(x, y, 0, j) + beta;
            }
        }
    }*/
    CImg<int> contrastImg(img.width(),img.height(),1,3,0);
    float factor=(259*(value+255))/(255*(259-value));
    for (int i=0; i<img.width(); i++){
        for (int j=0;j<img.height();j++){
            for (int k=0;k<3;k++){
                //if(img(i,j,0,k)*factor<0) sContrImg(i,j,0,k)=0;
                //else if(img(i,j,0,k)*factor>255) sContrImg(i,j,0,k)=255;
                //sContrImg(i,j,0,k)=img(i,j,0,k)*factor;
                if(((img(i,j,0,k)-128)*factor)+128<0) contrastImg(i,j,0,k)=0;
                else if(((img(i,j,0,k)-128)*factor)+128>255) contrastImg(i,j,0,k)=255;
                else contrastImg(i,j,0,k)=(((img(i,j,0,k)-128)*factor)+128);
            }
        }
    }
    return contrastImg;
}

CImg<int> negative(CImg<int> img) {
    CImg<double> negativeImg(img.width(),img.height(),1,3,0);
    for (int i=0; i<img.width(); i++){
        for (int j=0;j<img.height();j++){
            for (int k=0;k<3;k++){
                if(255-(img(i,j,0,k))<0) negativeImg(i,j,0,k)=0;
                else if(255-(img(i,j,0,k))>255) negativeImg(i,j,0,k)=255;
                else negativeImg(i,j,0,k)=255-(img(i,j,0,k));
            }
        }
    }
    return negativeImg;
}