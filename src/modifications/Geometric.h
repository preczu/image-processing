#ifndef GEOMETRIC_MODIFICATIONS
#define GEOMETRIC_MODIFICATIONS

#include "../../lib/CImg.templ"

using namespace std;
using namespace cimg_library;

CImg<int> hflip(CImg<int>);
CImg<int> vflip(CImg<int>);
CImg<int> dflip(CImg<int>);
CImg<int> shrink(CImg<int>, float);
CImg<int> enlarge(CImg<int>, float);

#endif //GEOMETRIC_MODIFICATIONS


