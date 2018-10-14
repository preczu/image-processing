#include <iostream>
#include "../../lib/CImg.templ"
#include "B.h"

using namespace std;
using namespace cimg_library;

CImg<int> brightness(CImg<int> img, char* val) {
    int value = atoi(val);
    for (int i=0; i<img.width(); i++){
        for (int j=0;j<img.height();j++){
            for (int k=0;k<3;k++){
                if(img(i,j,0,k)+value<0) img(i,j,0,k)=0;
                else if(img(i,j,0,k)+value>255) img(i,j,0,k)=255;
                else img(i,j,0,k)=img(i,j,0,k)+value;
            }
        }
    }
    return img;
}

CImg<int> contrast(CImg<int> img, char* val) {
    float value = atof(val);
    if (value < 0) {cout << "Contrast value must be greater than 0 "; exit(0);}
    /*float factor = 128 - 128 * value;
    for (int i = 0; i < img.width(); i++) {
        for (int j = 0; j < img.height(); j++) {
            for (int k = 0; k < 3; k++) {
                if (value * img(i, j, 0, k) + factor > 255) img(i, j, 0, k) = 255;
                else if (value * img(i, j, 0, k) + factor < 0) img(i, j, 0, k) = 0;
                else img(i, j, 0, k) = value * img(i, j, 0, k) + factor;
            }
        }
    }*/
    float factor=(259*(value+255))/(255*(259-value));
    for (int i=0; i<img.width(); i++){
        for (int j=0;j<img.height();j++){
            for (int k=0;k<3;k++){
                //if(img(i,j,0,k)*factor<0) sContrImg(i,j,0,k)=0;
                //else if(img(i,j,0,k)*factor>255) sContrImg(i,j,0,k)=255;
                //sContrImg(i,j,0,k)=img(i,j,0,k)*factor;
                if(((img(i,j,0,k)-128)*factor)+128<0) img(i,j,0,k)=0;
                else if(((img(i,j,0,k)-128)*factor)+128>255) img(i,j,0,k)=255;
                else img(i,j,0,k)=(((img(i,j,0,k)-128)*factor)+128);
            }
        }
    }
    return img;
}

CImg<int> negative(CImg<int> img) {
    for (int i=0; i<img.width(); i++){
        for (int j=0;j<img.height();j++){
            for (int k=0;k<3;k++){
                if(255-(img(i,j,0,k))<0) img(i,j,0,k)=0;
                else if(255-(img(i,j,0,k))>255) img(i,j,0,k)=255;
                else img(i,j,0,k)=255-(img(i,j,0,k));
            }
        }
    }
    return img;
}