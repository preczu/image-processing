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

int getColor(int x, int y, CImg<int>&);
float mse(CImg<int> &image1, CImg<int> &image2);
float pmse(CImg<int> &image1, CImg<int> &image2);
float snr(CImg<int> &image1, CImg<int> &image2);
float psnr(CImg<int> &image1, CImg<int> &image2);
float md(CImg<int> &image1, CImg<int> &image2);
int getMinColor(int x, int y, int maskSize, CImg<int> &image1);
int getMaxColor(int x, int y, int maskSize, CImg<int> &image1);
int getMedianColor(int x, int y, int maskSize, CImg<int> &image1);
CImg<int> minFilter(CImg<int> &image1, int maskSize);
CImg<int> maxFilter(CImg<int> &image1, int maskSize);
int singleMedian(CImg<int> &image1, int maskSize, int Smax, int x, int y);
CImg<int> medianFilter(CImg<int> &image1, int maskSize, int Smax);

