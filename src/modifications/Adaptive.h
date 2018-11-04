#include <iostream>
#include <vector>
#include <algorithm>
#include "../../lib/CImg.templ"

using namespace cimg_library;
using namespace std;
#include "../../lib/CImg.templ"

using namespace cimg_library;
using namespace std;

int zxyFun(int x, int y, CImg<int> &image);
CImg<int> adaptive(CImg<int> &image, float maskValue, float smax);