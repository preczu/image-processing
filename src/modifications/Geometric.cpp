#include <iostream>
#include "../../lib/CImg.templ"
#include "Geometric.h"

using namespace std;
using namespace cimg_library;

CImg<int> hflip(CImg<int> img){
    CImg<int> hflipImg(img.width(),img.height(),1,3,0);
    for (int i=0; i<img.width(); i++){
        for (int j=0;j<img.height();j++){
            for (int k=0;k<3;k++){
                hflipImg(img.width()-1-i,j,0,k)=img(i,j,0,k);
            }
        }
    }
    return hflipImg;
}

CImg<int> vflip(CImg<int> img){
    CImg<int> vflipImg(img.width(),img.height(),1,3,0);
    for (int i=0; i<img.width(); i++){
        for (int j=0;j<img.height();j++){
            for (int k=0;k<3;k++){
                vflipImg(i,img.height()-1-j,0,k)=img(i,j,0,k);
            }
        }
    }
    return vflipImg;
}

CImg<int> dflip(CImg<int> img){
    CImg<int> dflipImg(img.width(),img.height(),1,3,0);
    for (int i=0; i<img.width(); i++) {
        for (int j = 0; j < img.height(); j++) {
            for (int k = 0; k < 3; k++) {
                dflipImg(img.width() - 1 - i, img.height() - 1 - j, 0, k) = img(i, j, 0, k);
            }
        }
    }
    return dflipImg;
}


CImg<int> shrink(CImg<int> img, char* val){
    float factor = atof(val);
    CImg<int> shrinkedImg((img.width()/factor),(img.height()/factor),1,3,0);
    for (int i=0; i<shrinkedImg.width(); i++){
        for (int j=0;j<shrinkedImg.height();j++){
            for (int k=0;k<3;k++){
                shrinkedImg(i,j,0,k)=img(i*factor,j*factor,0,k);
            }
        }
    }
    return shrinkedImg;
}

CImg<int> enlarge(CImg<int> img, char* val){
    float factor = atof(val);
    CImg<int> enlargeImg((factor*img.width()),(factor*img.height()),1,3,0);
    for (int i=0; i<img.width(); i++){
        for (int j=0;j<img.height();j++){
            for (int k=0;k<3;k++){
                enlargeImg(factor*i,factor*j,0,k)=img(i,j,0,k);
                enlargeImg(factor*i+1,factor*j,0,k)=img(i,j,0,k);
                enlargeImg(factor*i,factor*j+1,0,k)=img(i,j,0,k);
                enlargeImg(factor*i+1,factor*j+1,0,k)=img(i,j,0,k);
            }
        }
    }

/* for (int i=0; i<enlargeImg.width(); i++) {
     for (int j = 0; j < enlargeImg.height(); j++) {
         if (enlargeImg(i, j, 0, 1) == 0 && enlargeImg(i, j, 0, 2) == 0 && enlargeImg(i, j, 0, 0) == 0) {
             for (int k = 0; k < 3; k++) {
                 int mean = ((enlargeImg(i - 1, j, 0, k) + enlargeImg(i + 1, j, 0, k)) / 2);
                 if (i - 1 < 0)i = 0;
                 else if (i + 1 > enlargeImg.width()) i = enlargeImg.width();
                 else if (j - 1 < 0) j = 0;
                 else if (j + 1 > enlargeImg.height()) j = enlargeImg.height();
                 enlargeImg(i, j, 0, k) = mean;
             }
         }
     }
 }*/
     return enlargeImg;

}