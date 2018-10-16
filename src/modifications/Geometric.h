#ifndef GEOMETRIC_MODIFICATIONS
#define GEOMETRIC_MODIFICATIONS

#include "../../lib/CImg.templ"

using namespace std;
using namespace cimg_library;

CImg<int> hflip(CImg<int>);
CImg<int> vflip(CImg<int>);
CImg<int> dflip(CImg<int>);
CImg<int> shrink(CImg<int>, char*);
CImg<int> enlarge(CImg<int>, char*);

#endif //GEOMETRIC_MODIFICATIONS


