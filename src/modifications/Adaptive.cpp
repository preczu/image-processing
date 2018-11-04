#include <iostream>
#include <vector>
#include <algorithm>
#include "../../lib/CImg.templ"

using namespace cimg_library;
using namespace std;

int zxyFun(int x, int y, CImg<int> &image) {
    int result = 0;
    for (int c = 0; c < image.spectrum(); c++) {
        result += image(x, y, 0, c);
    }
    return result;
}

CImg<int> adaptive(CImg<int> &image, float maskValue, float smax) {
    CImg<int> result(image.width(), image.height(), 1, image.spectrum());
    vector<int> pixels;
    int windowSize = maskValue;
    for (int i = 0; i < image.width(); i++) {
        for (int j = 0; j < image.height(); j++) {
            for (int c = 0; c < image.spectrum(); c++){
                for (int x = 0; x < maskValue; x++){
					for (int y = 0; y < maskValue; y++) {
						if(i+x-1>=0 && i+x-1 < image.width() && j+y-1 >=0 && j+y-1 <image.height()) {
							pixels.push_back(image(i+x-1,j+y-1,0,c));
						} 						
					}
				}
				sort(pixels.begin(),pixels.end());	
				int zmin = pixels[0];
                int zmax = pixels[pixels.size()-1];
                int zmed;
                if (pixels.size()%2 == 1) {
                    zmed = pixels[pixels.size()/2];
                }
                else if (pixels.size()%2 == 0) {
                    int pom1;
                    int pom2;
                    zmed = (pixels[pixels.size()/2] + pixels[pixels.size()/2+1])/2;	
                }
                int zxy = zxyFun(i,j,image);
                
                int a1 = zmed - zmin;
                int a2 = zmed - zmax;
                if (a1 > 0 && a2 < 0){
                    int b1 = zxy - zmin;
                    int b2 = zxy - zmax;
                    if (b1 > 0 && b2 < 0){
                        result ( i, j, 0, c) = zxy;
                    }
                    else result ( i, j, 0, c) = zmed;
                }
                else {
                    windowSize++;
                    if (windowSize <= smax) {
                        adaptive(image, windowSize, smax);
                    }
                    else result(i, j, 0, c) = zmed;
                }
				pixels.clear();
            }
        }
    }
    return result;
}