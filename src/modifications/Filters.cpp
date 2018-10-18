#include <iostream>
#include "../../lib/CImg.templ"
#include "Filters.h"

using namespace cimg_library;
using namespace std;

inline unsigned long long getColor(int x, int y, CImage& image)
{
	return image(x, y, 0, 0) + (image(x, y, 0, 1) << 8) + (image(x, y, 0, 2) << 16);
}

long long mse(CImage& image1, CImage& image2)
{
	if (image1.width() != image2.width() || image1.height() != image2.height()) {
		throw string("different image dimensions");
	}
	long long result = 0;

	for (int i = 0; i < image1.width(); i++)
	{
		for (int j = 0; j < image1.height(); j++)
		{
			auto c1 = getColor(i, j, image1), c2 = getColor(i, j, image2);
			auto c = c1 - c2;
			auto x = c * c;
			result = result + c * c;
		}
	}
	return result / (image1.width()*image1.height());
}
long long pmse(CImage& image1, CImage& image2)
{
	if (image1.width() != image2.width() || image1.height() != image2.height()) {
		throw string("different image dimensions");
	}
	long long result = 0;
	long long maxVal = 0;
	for (int i = 0; i < image1.width(); i++)
	{
		for (int j = 0; j < image1.height(); j++)
		{
			auto c = getColor(i, j, image1);
			if (c > maxVal) {
				maxVal = c;
			}
		}
	}
	auto t = maxVal * maxVal;
	auto x = mse(image1, image2);
	return mse(image1, image2) / (maxVal*maxVal);
}
long long snr(CImage& image1, CImage& image2)
{
	if (image1.width() != image2.width() || image1.height() != image2.height()) {
		throw string("different image dimensions");
	}
	long long result = 0;
	unsigned long long s1 = 0, s2 = 0;
	for (int i = 0; i < image1.width(); i++)
	{
		for (int j = 0; j < image1.height(); j++)
		{
			auto c = getColor(i, j, image1);
			auto c2 = getColor(i, j, image2);
			s1 = s1 + c * c;//tu sie przekr�ca� licznik typu danych
			s2 = s2 + (c - c2)*(c - c2);
		}
	}
	return 10 * log10(s1 / s2); 
}
long long psnr(CImage& image1, CImage& image2)
{
	if (image1.width() != image2.width() || image1.height() != image2.height()) {
		throw string("different image dimensions");
	}
	long long result = 0;
	long long maxVal = 0;
	unsigned long long sum = 0, sum2 = 0;
	//wiki
	for (int i = 0; i < image1.width(); i++)
	{

		for (int j = 0; j < image1.height(); j++)
		{

			auto c = getColor(i, j, image1);
			if (c > maxVal) {
				maxVal = c;
			}
		}
		auto x = mse(image1, image2);
		return 10 * log10(maxVal*maxVal / mse(image1, image2));
	}
	/////instrukcja
	//for (int i = 0; i < image1.width(); i++)
	//{

	//	for (int j = 0; j < image1.height(); j++)
	//	{

	//		sum += (maxVal*maxVal);
		/*auto c1 = getColor(i, j, image1), c2 = getColor(i, j, image2);
		auto c = c1 - c2;
		sum2 = sum2 + c * c;*/
	//	}
	//}
		//return 10 * log10(sum/sum2);

}
long long md(CImage& image1, CImage& image2)
{
	if (image1.width() != image2.width() || image1.height() != image2.height()) {
		throw string("different image dimensions");
	}
	long long maxVal = 0;
	for (int i = 0; i < image1.width(); i++)
	{
		for (int j = 0; j < image1.height(); j++)
		{
			long long c = getColor(i, j, image1);
			long long c2 = getColor(i, j, image2);
			long long diff = std::abs(c - c2);
			if (diff > maxVal) {
				maxVal = diff;
			}
		}
	}
	return maxVal;
}
long long getMinColor(int x, int y, int maskSize, CImage& image1)
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
long long getMaxColor(int x, int y, int maskSize, CImage& image1)
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
long long getMedianColor(int x, int y, int maskSize, CImage& image1)
{
	int result = 0;
	vector<long long> numbers;
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
CImage minFilter(CImage& image1, int maskSize)
{
	CImage result = image1;
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
CImage maxFilter(CImage& image1, int maskSize)
{
	CImage result = image1;
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
long long singleMedian(CImage& image1, int maskSize, int Smax, int x, int y)
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
CImage medianFilter(CImage& image1, int maskSize, int Smax)
{
	CImage result = image1;
	for (int i = 0; i < image1.width(); i++)
	{
		for (int j = 0; j < image1.height(); j++)
		{
			auto color = singleMedian(image1, maskSize, Smax, i, j);
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