#include <iostream>
#include <unistd.h>
#include "../lib/CImg.templ"
#include "modifications/Basic.h"
#include "modifications/Geometric.h"
#include "modifications/N.h"

using namespace std;
using namespace cimg_library;

//N5
// ./image-processing

void help() {
    cout << " \n"
    "                 image-processing\n"
    " \n"
    "             program to process images\n"
    "          Anna Preczyńska and Piotr Kocik\n"
    " \n"
    "  usage: image-processing <command> <value> <name_of_image_to_edit> <name_of_edited_image>\n"
    " \n"
    "Commands:\n"
    "   --help          list avaiable commands and the usage of the program\n"
    " \n"
    "   --brightness    change the brightness of the image, with all possible values\n"
    "   --contrast      change the contrast of the image, with any value bigger than zero\n"
    "   --negative      change the image into negative one, without any value\n"
    " \n"
    "   --hflip         horizontal image, without any value\n"
    "   --vflip         vertical image, without any value\n"
    "   --dflip         diagonal image, without any value\n"
    "   --shrink        make image smaller by value bigger than zero\n"
    "   --enlarge       make iage bigger by value from zero to two\n";
}

void displaying() {
        CImg<int> img1("../out/original.bmp");
        CImg<int> img2("../out/modified.bmp");
        img1.append(img2).display("Image");
}

int checkIntValue(char* val) {
    int number = atoi(val);
    return number;
}

float checkFloatValue(char* val){
    float number = atof(val);
    return number;
}

void input(int argc, char* argv[]) {
    int numberOfArgc = argc;

    if (string("--help").compare(argv[1]) == 0) {
        help();
    }
    else if (string("--brightness").compare(argv[1]) == 0) {
            float value;                                  //it will be used to check if    
            value = checkFloatValue(argv[2]);           //checking whether argv[2] is any possible value and converting it into float
            if(argc == 3){
                CImg<int> img("../img/color-24bit/lenac.bmp");
                img.save("original.bmp");                   //saving an image in folder "../out"
                img = brightness(img, value);               //implementing the function
                img.save("modified.bmp");                   //saving the resultant image in folder "../out"
            }
            else{
                if (argc == 4){
                    CImg<int> img(argv[3]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = brightness(img, value);           //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                }
                else if (argc == 5){
                    CImg<int> img(argv[3]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = brightness(img, value);           //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                    img.save(argv[4]);       //!!!          //saving the resultant image with a name given as an input
                }
            }            
            displaying();                                   //displaying pictures
    }

    else if (string("--contrast").compare(argv[1]) == 0) {
            float value;                                  //it will be used to check if    
            value = checkFloatValue(argv[2]);           //checking whether argv[2] is any possible value and converting it into float
            if(argc == 3){
                CImg<int> img("../img/color-24bit/lenac.bmp");
                img.save("original.bmp");                   //saving an image in folder "../out"
                img = contrast(img, value);               //implementing the function
                img.save("modified.bmp");                   //saving the resultant image in folder "../out"
            }
            else{
                if (argc == 4){
                    CImg<int> img(argv[3]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = contrast(img, value);           //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                }
                else if (argc == 5){
                    CImg<int> img(argv[3]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = contrast(img, value);           //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                    img.save(argv[4]);                    //saving the resultant image with a name given as an input
                }
            }            
            displaying();                                   //displaying pictures
    }

    else if (string("--negative").compare(argv[1]) == 0) {
        if (numberOfArgc < 5){
            if(argc == 2){
                CImg<int> img("../img/color-24bit/lenac.bmp");
                img.save("original.bmp");                   //saving an image in folder "../out"
                img = negative(img);               //implementing the function
                img.save("modified.bmp");                   //saving the resultant image in folder "../out"
            }
            else{
                if (argc == 3){
                    CImg<int> img(argv[2]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = negative(img);           //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                }
                else if (argc == 4){
                    CImg<int> img(argv[2]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = negative(img);           //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                    img.save(argv[3]);                    //saving the resultant image with a name given as an input
                }
            }            
            displaying();                                   //displaying pictures
        }
        else help();
    }
    
    else if (string("--hflip").compare(argv[1]) == 0) {
        if (numberOfArgc < 5){
            if(argc == 2){
                CImg<int> img("../img/color-24bit/lenac.bmp");
                img.save("original.bmp");                   //saving an image in folder "../out"
                img = hflip(img);               //implementing the function
                img.save("modified.bmp");                   //saving the resultant image in folder "../out"
            }
            else{
                if (argc == 3){
                    CImg<int> img(argv[2]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = hflip(img);           //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                }
                else if (argc == 4){
                    CImg<int> img(argv[2]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = hflip(img);           //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                    img.save(argv[3]);                    //saving the resultant image with a name given as an input
                }
            }           
            displaying();                                   //displaying pictures
        }
        else help();
    }

    else if (string("--vflip").compare(argv[1]) == 0) {
        if (numberOfArgc < 5){
            if(argc == 2){
                CImg<int> img("../img/color-24bit/lenac.bmp");
                img.save("original.bmp");                   //saving an image in folder "../out"
                img = vflip(img);               //implementing the function
                img.save("modified.bmp");                   //saving the resultant image in folder "../out"
            }
            else{
                if (argc == 3){
                    CImg<int> img(argv[2]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = vflip(img);           //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                }
                else if (argc == 4){
                    CImg<int> img(argv[2]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = vflip(img);           //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                    img.save(argv[3]);                    //saving the resultant image with a name given as an input
                }
            }           
            displaying();                                   //displaying pictures
            }
        else help();
    }

    else if (string("--dflip").compare(argv[1]) == 0) {
        if (numberOfArgc < 5){
            if(argc == 2){
                CImg<int> img("../img/color-24bit/lenac.bmp");
                img.save("original.bmp");                   //saving an image in folder "../out"
                img = dflip(img);               //implementing the function
                img.save("modified.bmp");                   //saving the resultant image in folder "../out"
            }
            else{
                if (argc == 3){
                    CImg<int> img(argv[2]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = dflip(img);           //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                }
                else if (argc == 4){
                    CImg<int> img(argv[2]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = dflip(img);           //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                    img.save(argv[3]);                    //saving the resultant image with a name given as an input
                }
            }           
            displaying();                                   //displaying pictures
        }
        else help();
    }
}

int main(int argc, char* argv[]) {

    if (argc < 2 && argc > 5){
        help();
        return 0;
    }
    else {
        input(argc, argv);    
    } 
        
    
    /*int value;
    //char image;
    //CImg<int> image("../img/color-24bit/girlc.bmp");
    if (string("--brightness").compare(argv[1]) == 0) {
        value = checkValue(argv[2]);
        //image= argv[3];
        CImg<int> img(argv[3]);
        img.save("original.bmp");
        //CImg<int> image("../img/color-24bit/girlc.bmp");
        img = brightness(img, argv[2]);
        img.save("modified.bmp");
        displaying();

    } else if (string("--contrast").compare(argv[1])) {
        value = checkValue(argv[2]);
        //image= argv[3];
        //CImg<int> img(image);
        CImg<int> image("../img/color-24bit/girlc.bmp");
        if (value < 0) value = value * (-1);
        contrast(image, argv[2]);

    }
    else if (string("--hflip").compare(argv[1])){
        //image= argv[2];
        //CImg<int> img(image);
        CImg<int> image("/img/color-24bit/girlc.bmp");
        hflip(image);
    }
    //help();
    return 0;
    //brightness();
    //else help();

    //wrong place of file*/

    /*CImg<int> image("../img/color-24bit/girlc.bmp");
    image.save("original.bmp");


    image = brightness(image, argv[1]);
    image.save("modified.bmp");
    CImg<int> img1("../out/original.bmp");
    CImg<int> img2("../out/modified.bmp");
    img1.append(img2).display("Image");
    //task();*/
}

