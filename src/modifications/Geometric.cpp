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


CImg<int> shrink(CImg<int> img, float factor){
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

CImg<int> enlarge(CImg<int> img, float factor){

    CImg<int> enlargeImg((factor*img.width()),(factor*img.height()),1,3,0);

        for (int x = 0; x < img.width(); x++) {
            for (int y = 0; y < img.height(); y++) {
                for (int k = 0; k < 3; k++) {
                    enlargeImg(factor*x, factor*y,0,k) = img(x,y,0,k);
                    enlargeImg(factor*x + 1, factor*y,0,k) = img(x,y,0,k);
                    enlargeImg(factor*x, factor*y + 1,0,k) = img(x,y,0,k);
                    enlargeImg(factor*x + 1, factor*y +1,0,k) = img(x,y,0,k);


                }
            }
        }
 
        //filling empty pixels in rows
        for (int x = 1; x < enlargeImg.width() - 1; x++) {
            for (int y = 0; y < enlargeImg.height(); y++) {
                if(enlargeImg( x, y, 0, 0) == 0 && enlargeImg( x, y, 0, 1) == 0 && enlargeImg( x, y, 0, 2) == 0){
                    for (int c = 0; c < 3; c++){
                        if(enlargeImg( x+1, y, 0, c) != 0 && enlargeImg( x-1, y, 0, c) != 0){
                            int sum = enlargeImg( x+1, y, 0, c) + enlargeImg( x-1, y, 0, c);
                            int counter = 2;
                            enlargeImg( x, y, 0, c) = sum / counter;
                        }
                    }
                }
            }
        }
    
        //filling empty pixels in columns
        for (int x = 0; x < enlargeImg.width(); x++) {
            for (int y = 1; y < enlargeImg.height() - 1; y++) {
                if(enlargeImg( x, y, 0, 0) == 0 && enlargeImg( x, y, 0, 1) == 0 && enlargeImg( x, y, 0, 2) == 0){
                    for (int c = 0; c < 3; c++){
                        if(enlargeImg( x, y+1, 0, c) != 0 && enlargeImg( x, y-1, 0, c) != 0){
                            int sum = enlargeImg( x, y+1, 0, c) + enlargeImg( x, y-1, 0, c);
                            int counter = 2;
                            enlargeImg( x, y, 0, c) = sum / counter;
                        }
                    }
                }
            }
        }
     return enlargeImg;

}