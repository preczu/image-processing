#include <iostream>
#include "../../lib/CImg.templ"
#include "Filters.h"

using namespace cimg_library;
using namespace std;

int getColor(int x, int y, CImg<int> &image)
{
	return image(x, y, 0, 0) + (image(x, y, 0, 1) << 8) + (image(x, y, 0, 2) << 16);
}

float mse(CImg<int> &image1, CImg<int> &image2)
{
	if (image1.width() != image2.width() || image1.height() != image2.height()) {
		throw string("different image dimensions");
	}
	float result = 0;

	for (int i = 0; i < image1.width(); i++)
	{
		for (int j = 0; j < image1.height(); j++)
		{
			int c1 = getColor(i, j, image1);
			int c2 = getColor(i, j, image2);
			int c = c1 - c2;
			//int x = c * c;
			result = result + c * c;
		}
	}
	return result / (image1.width()*image1.height());
}
float pmse(CImg<int> &image1, CImg<int> &image2)
{
	if (image1.width() != image2.width() || image1.height() != image2.height()) {
		throw string("different image dimensions");
	}
	float result = 0;
	float maxVal = 0;
	for (int i = 0; i < image1.width(); i++)
	{
		for (int j = 0; j < image1.height(); j++)
		{
			int c = getColor(i, j, image1);
			if (c > maxVal) {
				maxVal = c;
			}
		}
	}
	//float t = maxVal * maxVal;
	//float x = mse(image1, image2);
	return mse(image1, image2) / (maxVal*maxVal);
}
float snr(CImg<int> &image1, CImg<int> &image2)
{
	if (image1.width() != image2.width() || image1.height() != image2.height()) {
		throw string("different image dimensions");
	}
	float result = 0;
	float s1 = 0, s2 = 0;
	for (int i = 0; i < image1.width(); i++)
	{
		for (int j = 0; j < image1.height(); j++)
		{
			int c = getColor(i, j, image1);
			int c2 = getColor(i, j, image2);
			s1 = s1 + c * c;
			s2 = s2 + (c - c2)*(c - c2);
		}
	}
	return 10 * log10(s1 / s2); 
}
float psnr(CImg<int> &image1, CImg<int> &image2)
{
	if (image1.width() != image2.width() || image1.height() != image2.height()) {
		throw string("different image dimensions");
	}
	float result = 0;
	float maxVal = 0;
	float sum = 0, sum2 = 0;
	for (int i = 0; i < image1.width(); i++)
	{

		for (int j = 0; j < image1.height(); j++)
		{

			float c = getColor(i, j, image1);
			if (c > maxVal) {
				maxVal = c;
			}
		}
		float x = mse(image1, image2);
		return 10 * log10(maxVal*maxVal / mse(image1, image2));
	}

}
float md(CImg<int> &image1, CImg<int> &image2)
{
	if (image1.width() != image2.width() || image1.height() != image2.height()) {
		throw string("different image dimensions");
	}
	float maxVal = 0;
	for (int i = 0; i < image1.width(); i++)
	{
		for (int j = 0; j < image1.height(); j++)
		{
			float c = getColor(i, j, image1);
			float c2 = getColor(i, j, image2);
			float diff = std::abs(c - c2);
			if (diff > maxVal) {
				maxVal = diff;
			}
		}
	}
	return maxVal;
}
int getMinColor(int x, int y, int maskSize, CImg<int> &image1)
{
	int result = 0;
	for (int i = x - maskSize / 2; i <= x + maskSize / 2; i++)
	{
		for (int j = y - maskSize / 2; j <= y + maskSize / 2; j++)
		{
			if (i < 0 || j < 0 || i >= image1.width() || j >= image1.height())
			{
				continue;
			}
			auto color = getColor(i, j, image1);
			auto r = color & 255;
			auto g = (color >> 8) & 255;
			auto b = (color >> 16) & 255;
			if (result == 0 || color < result) {
				result = color;
			}
		}
	}
	return result;
}
int getMaxColor(int x, int y, int maskSize, CImg<int> &image1)
{
	int result = 0;
	for (int i = x - maskSize / 2; i <= x + maskSize / 2; i++)
	{
		for (int j = y - maskSize / 2; j <= y + maskSize / 2; j++)
		{
			if (i < 0 || j < 0 || i >= image1.width() || j >= image1.height())
			{
				continue;
			}
			auto color = getColor(i, j, image1);
			auto r = color & 255;
			auto g = (color >> 8) & 255;
			auto b = (color >> 16) & 255;
			if (color > result) {
				result = color;
			}
		}
	}
	return result;
}
int getMedianColor(int x, int y, int maskSize, CImg<int> &image1)
{
	int result = 0;
	vector<float> numbers;
	for (int i = x - maskSize / 2; i <= x + maskSize / 2; i++)
	{
		for (int j = y - maskSize / 2; j <= y + maskSize / 2; j++)
		{
			if (i < 0 || j < 0 || i >= image1.width() || j >= image1.height())
			{
				continue;
			}
			auto color = getColor(i, j, image1);
			numbers.push_back(color);
		}
	}
	sort(numbers.begin(), numbers.end());
	if (numbers.size() % 2 == 1) {
		return numbers[numbers.size() / 2];
	}
	return (numbers[numbers.size() / 2] + numbers[numbers.size() / 2 + 1]);
}
CImg<int> minFilter(CImg<int> &image1, int maskSize)
{
	CImg<int> result = image1;
	for (int i = 0; i < image1.width(); i++)
	{
		for (int j =0; j < image1.height(); j++)
		{
			auto color = getMinColor(i, j, maskSize, image1);
			auto r = color & 255;
			auto g = (color >> 8) & 255;
			auto b = (color >> 16) & 255;
			result(i, j, 0, 0) = r;
			result(i, j, 0, 1) = g;
			result(i, j, 0, 2) = b;
		}
	}
	return result;
}
CImg<int> maxFilter(CImg<int> &image1, int maskSize)
{
	CImg<int> result = image1;
	for (int i = maskSize / 2; i < image1.width() - maskSize / 2; i++)
	{
		for (int j = maskSize / 2; j < image1.height() - maskSize / 2; j++)
		{
			auto color = getMaxColor(i, j, maskSize, image1);
			auto r = color & 255;
			auto g = (color >> 8) & 255;
			auto b = (color >> 16) & 255;
			result(i, j, 0, 0) = r;
			result(i, j, 0, 1) = g;
			result(i, j, 0, 2) = b;
		}
	}
	return result;
}
int singleMedian(CImg<int> &image1, int maskSize, int Smax, int x, int y)
{
	auto median = getMedianColor(x, y, maskSize, image1);
	auto minColor = getMinColor(x, y, maskSize, image1);
	auto maxColor = getMaxColor(x, y, maskSize, image1);
	auto color = getColor(x, y, image1);
	int curSize = maskSize;
	auto a1 = median - minColor;
	auto a2 = median - maxColor;
	if (a1 > 0 && a2 < 0) {
		auto b1 = color - minColor;
		auto b2 = color - maxColor;
		if (b1 > 0 && b2 < 0) {
			return color;
		}
		else {
			return median;
		}
	}
	curSize++;
	if (curSize <= Smax) {
		return singleMedian(image1, curSize, Smax, x, y);
	}
	return color;
}
CImg<int> medianFilter(CImg<int> &image1, int maskSize, int Smax)
{
	CImg<int> result = image1;
	for (int i = 0; i < image1.width(); i++)
	{
		for (int j = 0; j < image1.height(); j++)
		{
			int color = singleMedian(image1, maskSize, Smax, i, j);
			int r = color & 255;
			int g = (color >> 8) & 255;
			int b = (color >> 16) & 255;
			result(i, j, 0, 0) = r;
			result(i, j, 0, 1) = g;
			result(i, j, 0, 2) = b;
		}
	}
	return result;
}