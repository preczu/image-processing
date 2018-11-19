#include <iostream>
#include <vector>
#include <algorithm>
#include "../../lib/CImg.templ"

using namespace cimg_library;
using namespace std;

CImg<int> adaptive(CImg<int> &image, int smax) {
    CImg<int> result(image.width(), image.height(), 1, image.spectrum());
    int pixels[(smax*2+1)*(smax*2+1)];

    for (int i = 0; i < image.width(); i++) {
        for (int j = 0; j < image.height(); j++) {
            for (int c = 0; c < image.spectrum(); c++) {
                int currDepth = 1;

                while (true) {
                    int pixelSize = 0;
                    for (int x = 0; x < currDepth * 2 + 1; x++) {
                        for (int y = 0; y < currDepth * 2 + 1; y++) {
                            if (i + x - currDepth >= 0 && i + x - currDepth < image.width() &&
                                j + y - currDepth >= 0 &&
                                j + y - currDepth < image.height()) {
                                pixels[pixelSize] = (image(i + x - currDepth, j + y - currDepth, 0, c));
                                pixelSize++;
                            }
                        }
                    }
                    sort(pixels, pixels + pixelSize);
                    int zmin = pixels[0];
                    int zmax = pixels[pixelSize - 1];
                    int zmed;
                    if (pixelSize % 2 == 1) {
                        zmed = pixels[pixelSize / 2];
                    } else if (pixelSize % 2 == 0) {
                        zmed = (pixels[pixelSize / 2] + pixels[pixelSize / 2 + 1]) / 2;
                    }
                    int zxy = image(i, j, 0, c);

                    int a1 = zmed - zmin;
                    int a2 = zmed - zmax;
                    if (a1 > 0 && a2 < 0) {
                        int b1 = zxy - zmin;
                        int b2 = zxy - zmax;
                        if (b1 > 0 && b2 < 0) {
                            result(i, j, 0, c) = zxy;

                        }
                        else {
                            result(i, j, 0, c) = zmed;
                        }
                        break;
                    }
                    else {
                        currDepth++;
                        if (currDepth <= smax) {
                            pixelSize = 0;
                            continue;
                        }
                        else {
                            result(i, j, 0, c) = zxy;
                            break;
                        }
                    }
                }
            }
        }
    }
    return result;
}