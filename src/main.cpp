#include <iostream>
#include <unistd.h>
#include "../lib/CImg.templ"
#include "modifications/Basic.h"
#include "modifications/Geometric.h"
#include "modifications/N.h"
#include "modifications/Filters.h"


using namespace std;
using namespace cimg_library;

//N5

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
    "   --enlarge       make image bigger by value from zero to three\n";
}

void displaying() {
        CImg<int> img1("../out/original.bmp");
        CImg<int> img2("../out/modified.bmp");
        img1.append(img2).display("Image");
}

int checkIntValue(char* val) {
    int number = atoi(val);
    if (number == 0){
        if (val != "0"){
            cout << "You forgot to give the value! \n" << endl;
            help();
            exit(0);
        }
        else return number;
    }
    else return number;
    return number;
}

float checkFloatValue(char* val){
    float number = atof(val);
    if (number == 0){
        if (val != "0"){
            cout << "You forgot to give the value! \n" << endl;
            help();
            exit(0);
        }
        else return number;
    }
    else return number;
}

void input(int argc, char* argv[]) {
    int numberOfArgc = argc;                                //integer used to some geometric functions

    if (string("--help").compare(argv[1]) == 0) {
        help();
    }
    else if (string("--brightness").compare(argv[1]) == 0) {
            if( numberOfArgc == 2){
                help();
                exit(0);
            }
            
            float value;                                    //it will be used to check if    
            value = checkFloatValue(argv[2]);               //checking whether argv[2] is any possible value and converting it into float
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
            if( numberOfArgc == 2){
                help();
                exit(0);
            }
            
            float value;                                    //it will be used to check if    
            value = checkFloatValue(argv[2]);               //checking whether argv[2] is any possible value and converting it into float
            if(argc == 3){
                CImg<int> img("../img/color-24bit/lenac.bmp");
                img.save("original.bmp");                   //saving an image in folder "../out"
                img = contrast(img, value);                 //implementing the function
                img.save("modified.bmp");                   //saving the resultant image in folder "../out"
            }
            else{
                if (argc == 4){
                    CImg<int> img(argv[3]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = contrast(img, value);             //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                }
                else if (argc == 5){
                    CImg<int> img(argv[3]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = contrast(img, value);             //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                    img.save(argv[4]);                      //saving the resultant image with a name given as an input
                }
            }            
            displaying();                                   //displaying pictures
    }

    else if (string("--negative").compare(argv[1]) == 0) {
        if (numberOfArgc < 5){
            if(argc == 2){
                CImg<int> img("../img/color-24bit/lenac.bmp");
                img.save("original.bmp");                   //saving an image in folder "../out"
                img = negative(img);                        //implementing the function
                img.save("modified.bmp");                   //saving the resultant image in folder "../out"
            }
            else{
                if (argc == 3){
                    CImg<int> img(argv[2]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = negative(img);                    //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                }
                else if (argc == 4){
                    CImg<int> img(argv[2]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = negative(img);                    //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                    img.save(argv[3]);                      //saving the resultant image with a name given as an input
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
                img = hflip(img);                           //implementing the function
                img.save("modified.bmp");                   //saving the resultant image in folder "../out"
            }
            else{
                if (argc == 3){
                    CImg<int> img(argv[2]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = hflip(img);                       //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                }
                else if (argc == 4){
                    CImg<int> img(argv[2]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = hflip(img);                       //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                    img.save(argv[3]);                      //saving the resultant image with a name given as an input
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
                img = vflip(img);                           //implementing the function
                img.save("modified.bmp");                   //saving the resultant image in folder "../out"
            }
            else{
                if (argc == 3){
                    CImg<int> img(argv[2]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = vflip(img);                       //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                }
                else if (argc == 4){
                    CImg<int> img(argv[2]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = vflip(img);                       //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                    img.save(argv[3]);                      //saving the resultant image with a name given as an input
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
                img = dflip(img);                           //implementing the function
                img.save("modified.bmp");                   //saving the resultant image in folder "../out"
            }
            else{
                if (argc == 3){
                    CImg<int> img(argv[2]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = dflip(img);                       //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                }
                else if (argc == 4){
                    CImg<int> img(argv[2]);                 //defining an image from input                
                    img.save("original.bmp");               //saving an image in folder "../out"
                    img = dflip(img);                       //implementing the function
                    img.save("modified.bmp");               //saving the resultant image in folder "../out"
                    img.save(argv[3]);                      //saving the resultant image with a name given as an input
                }
            }           
            displaying();                                   //displaying pictures
        }
        else help();
    }

    else if (string("--shrink").compare(argv[1]) == 0) {
            if( numberOfArgc == 2){
                help();
                exit(0);
            }
            
            float value;                                    //it will be used to check if    
            value = checkFloatValue(argv[2]);               //checking whether argv[2] is any possible value and converting it into float
            if (value < 1) {
                help();
                exit(0);
            }
            else{
                if(argc == 3){
                    CImg<int> img("../img/color-24bit/lenac.bmp");
                    img.save("original.bmp");                   //saving an image in folder "../out"
                    img = shrink(img, value);                   //implementing the function
                    img.save("modified.bmp");                   //saving the resultant image in folder "../out"
                }
                else{
                    if (argc == 4){
                        CImg<int> img(argv[3]);                 //defining an image from input                
                        img.save("original.bmp");               //saving an image in folder "../out"
                        img = shrink(img, value);               //implementing the function
                        img.save("modified.bmp");               //saving the resultant image in folder "../out"
                    }
                    else if (argc == 5){
                        CImg<int> img(argv[3]);                 //defining an image from input                
                        img.save("original.bmp");               //saving an image in folder "../out"
                        img = shrink(img, value);               //implementing the function
                        img.save("modified.bmp");               //saving the resultant image in folder "../out"
                        img.save(argv[4]);                      //saving the resultant image with a name given as an input
                    }
                }            
                displaying();                                   //displaying pictures
            }
    }

    else if (string("--enlarge").compare(argv[1]) == 0) {
            if( numberOfArgc == 2){
                help();
                exit(0);
            }
            
            float value;                                    //it will be used to check if    
            value = checkFloatValue(argv[2]);               //checking whether argv[2] is any possible value and converting it into float
            if (value < 1 || value > 3) {
                help();
                exit(0);
            }
            else {
                if(argc == 3){
                    CImg<int> img("../img/color-24bit/lenac.bmp");
                    img.save("original.bmp");                   //saving an image in folder "../out"
                    img = enlarge(img, value);                  //implementing the function
                    img.save("modified.bmp");                   //saving the resultant image in folder "../out"
                }
                else{
                    if (argc == 4){
                        CImg<int> img(argv[3]);                 //defining an image from input                
                        img.save("original.bmp");               //saving an image in folder "../out"
                        img = enlarge(img, value);              //implementing the function
                        img.save("modified.bmp");               //saving the resultant image in folder "../out"
                    }
                    else if (argc == 5){
                        CImg<int> img(argv[3]);                 //defining an image from input                
                        img.save("original.bmp");               //saving an image in folder "../out"
                        img = enlarge(img, value);              //implementing the function
                        img.save("modified.bmp");               //saving the resultant image in folder "../out"
                        img.save(argv[4]);                      //saving the resultant image with a name given as an input
                    }
                }            
                displaying();                                   //displaying pictures
            }
    }

    else if (string("--adaptive").compare(argv[1]) == 0){
            ///////
    }

    else if (string("--min").compare(argv[1]) == 0){
                    ///////
    }

    else if (string("--max").compare(argv[1]) == 0){
                    ///////
    }

    else if (string("--mse").compare(argv[1]) == 0){
                    ///////
    }

    else if (string("--pmse").compare(argv[1]) == 0){
                    ///////
    }

    else if (string("--snr").compare(argv[1]) == 0){
                    ///////
    }

    else if (string("--psnr").compare(argv[1]) == 0){
                    ///////
    }

    else if (string("--md").compare(argv[1]) == 0){
                    ///////
    }

    else {
        help();
        exit(0);
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
    return 0;
}

