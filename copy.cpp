// It could not find `iostream.h` it was standarised to `iostream`.
// You could use `locate` to search for liblaries in system. ex: `locate iostream`.
#include <iostream>
#include <unistd.h>
#include "CImg.h"

using namespace std;
using namespace cimg_library;

//can't use return img :(

void help()
{
  cout << "Options:" << endl;
  cout << "1 --brightness" << endl;
  cout << "2 --contrast" << endl;
  cout << "3 --negative" << endl;
}

void displaying(CImg<unsigned char> img)
{
  //const unsigned char red[] = { 255,0,0 }, green[] = { 0,255,0 }, blue[] = { 0,0,255 };
  img.display("Image");
}

int badChoice (int choice)
{
  if (choice != 1)
  {
    int anotherChoice;
    cout << "There is no such option" << endl;
    help();
    cout << "Try again" << endl;
    cin >> anotherChoice;
    badChoice(anotherChoice);
  }
  else return choice;
}

int brightness(CImg<unsigned char> img)
{
  //const unsigned char red[] = { 255,0,0 }, green[] = { 0,255,0 }, blue[] = { 0,0,255 };
  //red[] = { 254,0,0 }, green[] = { 0,254,0 }, blue[] = { 0,0,254 };
  CImg<float> img;
// Change the (100,200) pixel to Red.
img(100,200,0,0) = 255; //R
img(100,200,0,1) = 0; //G
img(100,200,0,2) = 0; //B
  return img;
}

int checkTheChoice(int choice, CImg<unsigned char> img)
{
  badChoice(choice);
  if (choice=1)
  {
    brightness(img);
  }
  return img;
}

int task()
{
  CImg<unsigned char> image("lenac_small.bmp");
  displaying(image);
  int choice;
  cout << "To change brightness choose 1" << endl;
  cin >> choice;
  
}

int main() {
    //CImg<unsigned char> image("lenac_small.bmp");
    //const unsigned char red[] = { 255,0,0 }, green[] = { 0,255,0 }, blue[] = { 0,0,255 };
    //image.blur(2.5);
    task();
    return 0;
}

//to build the project press Ctrl + Shift + B and select build task.
//to build and run press f5.
