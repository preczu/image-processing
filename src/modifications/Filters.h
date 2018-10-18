#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include "../../lib/CImg.templ"
using namespace cimg_library;
using namespace std;
typedef CImg<unsigned char> CImage;
struct color
{
	int r, g, b;
	color(int _r, int _g, int _b)
	{
		r = _r;
		g = _g;
		b = _b;
	}
	color(unsigned long long value) {
		r = value & 255;
		g = (value >> 8) & 255;
		b = (value >> 16) & 255;
	}
};
inline unsigned long long getColor(int x, int y, CImage& image);
long long mse(CImage& image1, CImage& image2);
long long pmse(CImage& image1, CImage& image2);
long long snr(CImage& image1, CImage& image2);
long long psnr(CImage& image1, CImage& image2);
long long md(CImage& image1, CImage& image2);
long long getMinColor(int x, int y, int maskSize, CImage& image1);
long long getMaxColor(int x, int y, int maskSize, CImage& image1);
long long getMedianColor(int x, int y, int maskSize, CImage& image1);
CImage minFilter(CImage& image1, int maskSize);
CImage maxFilter(CImage& image1, int maskSize);
long long singleMedian(CImage& image1, int maskSize, int Smax, int x, int y);
CImage medianFilter(CImage& image1, int maskSize, int Smax);

