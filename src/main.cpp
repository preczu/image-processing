#include <iostream>
#include <unistd.h>
#include "../lib/CImg.templ"
#include "modifications/B.h"
#include "modifications/G.h"
#include "modifications/N.h"

using namespace std;
using namespace cimg_library;

//N5

void help(){
    cout << " " << endl;
    cout << "                 image-processing" << endl;
    cout << " " << endl;
    cout << "             program to process images" << endl;
    cout << "          Anna Preczyńska and Piotr Kocik" << endl;
    cout << " " << endl;
    cout << "  usage: image-processing <command> <value> <name_of_image_to_edit> <name_of_edited_image>" << endl;
    cout << " " << endl;
    cout << "Commands:" << endl;
    cout << "   --help          list avaiable commands and the usage of the program" << endl;
    cout << " " << endl;
    cout << "   --brightness    change the brightness of the image, with all possible values" << endl;
    cout << "   --contrast      change the contrast of the image, with any value bigger than zero" << endl;
    cout << "   --negative      change the image into negative one, without any value" << endl;
    cout << " " << endl;
    cout << "   --hflip         horizontal image, without any value" << endl;
    cout << "   --vflip         vertical image, without any value" << endl;
    cout << "   --dflip         diagonal image, without any value" << endl;
    cout << "   --shrink        make image smaller by value bigger than zero" << endl;
    cout << "   --enlarge       make iage bigger by value from zero to two" << endl;
}

int main(int argc, char* argv[]) {
    help();
    CImg<int> image("../img/color-24bit/lenac.bmp");
    image.save("original.bmp");


    image = brightness(image, argv[1]);
    image.save("modified.bmp");
    CImg<int> img1("../out/original.bmp");
    CImg<int> img2("../out/modified.bmp");
    img1.append(img2).display("Image");
    //task();
    return 0;
}

//to build the project press Ctrl + Shift + B and select build task.
//to build and run press f5.
