#ifndef N_MODIFICATIONS
#define N_MODIFICATIONS

#include "../../lib/CImg.templ"

using namespace std;
using namespace cimg_library;

CImg<int> hflip(CImg<int>);
CImg<int> vflip(CImg<int>);
CImg<int> dflip(CImg<int>);
CImg<int> shrinking(CImg<int>, char*);
CImg<int> enlargement(CImg<int>, char*);

#endif //N_MODIFICATIONS