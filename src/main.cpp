#include <iostream>
#include <unistd.h>
#include "../lib/CImg.templ"
#include "modifications/B.h"
#include "modifications/G.h"
#include "modifications/N.h"

using namespace std;
using namespace cimg_library;

//N5

void displaying(CImg<unsigned char> img){
  img.display("Image");
}


int stageB(CImg<double> img){
  return 0;
}

int stageA(CImg<double> img){
  //int A1=zmed(img)-zmin(img);
  //int A2=zmed(img)-zmax(img);
    //if(A1>0 &&A2<0) stageB(img);
    //else return 0;//increase the window size If window size ≤ Smax repeat stage A
    //else return zxy();
  return 0;
}

int adaptiveFilter(CImg<double> img){
    CImg<double> adaptiveImg(img.width(),img.height(),1,3,0);
    for (int i=0; i<img.width(); i++){
      for (int j=0;j<img.height();j++){
        for (int k=0;k<3;k++){ 
                  adaptiveImg(img.width()-1-i,img.height()-1-j,0,k)=img(i,j,0,k);
          }
        }
      }
    displaying(adaptiveImg);
    return 0;
}

int minFilter(CImg<double> img){
    CImg<double> adaptiveImg(img.width(),img.height(),1,3,0);
    for (int i=0; i<img.width(); i++){
      for (int j=0;j<img.height();j++){
        for (int k=0;k<3;k++){ 
                  adaptiveImg(img.width()-1-i,img.height()-1-j,0,k)=img(i,j,0,k);
          }
        }
      }
    displaying(adaptiveImg);
    return 0;
}

int maxFilter(CImg<double> img){
    CImg<double> adaptiveImg(img.width(),img.height(),1,3,0);
    for (int i=0; i<img.width(); i++){
      for (int j=0;j<img.height();j++){
        for (int k=0;k<3;k++){ 
                  adaptiveImg(img.width()-1-i,img.height()-1-j,0,k)=img(i,j,0,k);
          }
        }
      }
    displaying(adaptiveImg);
    return 0;
}

int task(){
    CImg<unsigned char> image("../img/color-24bit/lenac.bmp");
    displaying(image); //append
    //darker(image);            //displaying darker image
    //brighter(image);          //displaying brighter image
    //biggerContrast(image);    //displaying image with bigger contrast
    //smallerConstrast(image);  //displaying image with smaller contrast
    //negative(image);          //displaying negative image
    //hflip(image);             //displaying image after horizontal flip
    //vflip(image);             //displaying image after vertical flip
    //dflip(image);             //displaying image after diagonal flip
    //enlargement(image);       //displaying bigger image
    //shrinking(image);         //displaying smaller image

    return 0;
}

int main(int argc, char* argv[]) {
    CImg<int> image("../img/color-24bit/lenac.bmp");
    image.save("original.bmp");
    brightness(image, argv[1]);
    //image.save("modified.bmp");
    CImg<int> img1("../out/original.bmp");
    CImg<int> img2("../out/modified.bmp");
    (img1,img2).display();
    //task();
    return 0;
}

//to build the project press Ctrl + Shift + B and select build task.
//to build and run press f5.
