#include <iostream>
#include <unistd.h>
#include "../lib/CImg.templ"
#include "modifications/B.h"
#include "modifications/G.h"


using namespace std;
using namespace cimg_library;

//N5

void displaying(CImg<unsigned char> img){
  img.display("Image");
}

int biggerContrast(CImg<double> img){
  //contrast correction factor factor=259(C+255)/[255(259-C)]
    CImg<double> bContrImg(img.width(),img.height(),1,3,0);
    int contrast= 125;
    float factor=(259*(contrast+255))/(255*(259-contrast));
    for (int i=0; i<img.width(); i++){
      for (int j=0;j<img.height();j++){
        for (int k=0;k<3;k++){ 
          if(((img(i,j,0,k)-128)*factor)+128<0) bContrImg(i,j,0,k)=0;
          else if(((img(i,j,0,k)-128)*factor)+128>255) bContrImg(i,j,0,k)=255;
          else bContrImg(i,j,0,k)=(((img(i,j,0,k)-128)*factor)+128);
          }
        }
      }
    displaying(bContrImg);
    return 0;
}

int smallerConstrast(CImg<double> img){
    CImg<double> sContrImg(img.width(),img.height(),1,3,0);
    int contrast= 10;
    float factor=(259*(contrast+255))/(255*(259-contrast));
    for (int i=0; i<img.width(); i++){
      for (int j=0;j<img.height();j++){
        for (int k=0;k<3;k++){ 
          //if(img(i,j,0,k)*factor<0) sContrImg(i,j,0,k)=0;
          //else if(img(i,j,0,k)*factor>255) sContrImg(i,j,0,k)=255;
          //sContrImg(i,j,0,k)=img(i,j,0,k)*factor;
          if(((img(i,j,0,k)-128)*factor)+128<0) sContrImg(i,j,0,k)=0;
          else if(((img(i,j,0,k)-128)*factor)+128>255) sContrImg(i,j,0,k)=255;
          else sContrImg(i,j,0,k)=(((img(i,j,0,k)-128)*factor)+128);
          }
        }
      }
    displaying(sContrImg);
    return 0;
}

int darker(CImg<double> img){
    CImg<double> darkimg(img.width(),img.height(),1,3,0);
    for (int i=0; i<img.width(); i++){
      for (int j=0;j<img.height();j++){
        for (int k=0;k<3;k++){ 
          if(img(i,j,0,k)-100<0) darkimg(i,j,0,k)=0;
          else if(img(i,j,0,k)-100>255) darkimg(i,j,0,k)=255;
          else darkimg(i,j,0,k)=img(i,j,0,k)-100;
          }
        }
      }
    displaying(darkimg);
    return 0;
}

int brighter(CImg<double> img){
    CImg<double> brightimg(img.width(),img.height(),1,3,0);
    for (int i=0; i<img.width(); i++){
      for (int j=0;j<img.height();j++){
        for (int k=0;k<3;k++){ 
          if(img(i,j,0,k)+100<0) brightimg(i,j,0,k)=0;
          else if(img(i,j,0,k)+100>255) brightimg(i,j,0,k)=255;
          else brightimg(i,j,0,k)=img(i,j,0,k)+100;
          }
        }
      }
    displaying(brightimg);
    return 0;
}

int negative(CImg<double> img){
  //contrast correction factor factor=259(C+255)/[255(259-C)]
    CImg<double> negativeImg(img.width(),img.height(),1,3,0);
    //int contrast= 125;
   // float factor=(259*(contrast+255))/(255*(259-contrast));
    for (int i=0; i<img.width(); i++){
      for (int j=0;j<img.height();j++){
        for (int k=0;k<3;k++){ 
          if(255-(img(i,j,0,k))<0) negativeImg(i,j,0,k)=0;
          else if(255-(img(i,j,0,k))>255) negativeImg(i,j,0,k)=255;
          else negativeImg(i,j,0,k)=255-(img(i,j,0,k));
          }
        }
      }
    displaying(negativeImg);
    return 0;
}

int hflip(CImg<double> img){
    CImg<double> hflipImg(img.width(),img.height(),1,3,0);
    for (int i=0; i<img.width(); i++){
      for (int j=0;j<img.height();j++){
        for (int k=0;k<3;k++){ 
                  hflipImg(img.width()-1-i,j,0,k)=img(i,j,0,k);
          }
        }
      }
    displaying(hflipImg);
    return 0;
}

int vflip(CImg<double> img){
    CImg<double> vflipImg(img.width(),img.height(),1,3,0);
    for (int i=0; i<img.width(); i++){
      for (int j=0;j<img.height();j++){
        for (int k=0;k<3;k++){ 
                  vflipImg(i,img.height()-1-j,0,k)=img(i,j,0,k);
          }
        }
      }
    displaying(vflipImg);
    return 0;
}

int dflip(CImg<double> img){
    CImg<double> dflipImg(img.width(),img.height(),1,3,0);
    for (int i=0; i<img.width(); i++){
      for (int j=0;j<img.height();j++){
        for (int k=0;k<3;k++){ 
                  dflipImg(img.width()-1-i,img.height()-1-j,0,k)=img(i,j,0,k);
          }
        }
      }
    displaying(dflipImg);
    return 0;
}

int enlargement(CImg<double> img){
  int factor=3;
  CImg<double> enlargeImg((factor*img.width()),(factor*img.height()),1,3,0);
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
     /* CImg<double> enlargenImg((enlargeImg.width()),(enlargeImg.height()),1,3,0);
  for (int i=0; i<enlargeImg.width(); i++){
      for (int j=0;j<enlargeImg.height();j++){
          if (enlargeImg(i,j,0,1)==0 && enlargeImg(i,j,0,2)==0 && enlargeImg(i,j,0,0)==0) {
            for (int k=0;k<3;k++){
            int mean=((enlargeImg(i-1,j,0,k)+enlargeImg(i+1,j,0,k))/2);
            if (i-1<0)i=0;
            else if (i+1>enlargeImg.width()) i=enlargeImg.width();
            else if (j-1<0) j=0;
            else if (j+1>enlargeImg.height()) j=enlargeImg.height();
            enlargenImg(i,j,0,k)=mean;
          }
        }
      }
  }*/
  displaying(enlargeImg);

}

int shrinking(CImg<double> img){
  int factor=2;
  CImg<double> shrinkedImg((img.width()/factor),(img.height()/factor),1,3,0);
  for (int i=0; i<shrinkedImg.width(); i++){
      for (int j=0;j<shrinkedImg.height();j++){
        for (int k=0;k<3;k++){ 
                  shrinkedImg(i,j,0,k)=img(i*factor,j*factor,0,k);
                  //shrinkedImg(factor*i+1,factor*j,0,k)=img(i,j,0,k);
                  //shrinkedImg(factor*i,factor*j+1,0,k)=img(i,j,0,k);
                  //shrinkedImg(factor*i+1,factor*j+1,0,k)=img(i,j,0,k);
          }
        }
      }
  displaying(shrinkedImg);
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
    CImg<unsigned char> image("../img/color-24bit/lenac.bmp");
    image.save("Original.bmp");
    changeBrightness(image, argv[1]);
    task();
    return 0;
}

//to build the project press Ctrl + Shift + B and select build task.
//to build and run press f5.
