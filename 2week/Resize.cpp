#define _CRT_SECURE_NO_WARNINGS
#include <opencv2/imgproc.hpp >
#include <opencv2/highgui.hpp >

#include <stdlib.h>

using namespace cv;

int main() {
	float N;
	int rx, ry;
	float ix, iy;
	int resize[3];
	float Nx, Ny;
	float green, yellow, pink, blue;

	int px, py;
	printf("Iniput your scale factor : ");
	scanf("%f", &N);

	Mat imgColor = imread("test.jpg", IMREAD_COLOR);

	int width = imgColor.cols; 
	int height = imgColor.rows;

	int rwidth = (int)(width * N);
	int rheight = (int)(height * N);
	Mat result(rheight, rwidth, CV_8UC3);

	for (ry = 0; ry < rheight; ry++) {
		for (rx = 0; rx < rwidth; rx++) {
			ix = (float)rx / N;
			iy = (float)ry / N;

			if (ix >= width-1 || ix < 0 || iy >= height-1  || iy < 0) {
				result.at<Vec3b>(ry, rx)[0] = 0;
				result.at<Vec3b>(ry, rx)[1] = 0;
				result.at<Vec3b>(ry, rx)[2] = 0;
			}
			else {
				px = int(ix);
				py = int(iy);
				Nx = ix - px;
				Ny = iy - py;

				for (int i = 0; i < 3; i++) {
					green = imgColor.at<Vec3b>(py, px)[i] * (1 - Ny) + imgColor.at<Vec3b>(py + 1, px)[i] * Ny;
					yellow = imgColor.at<Vec3b>(py, px)[i] * (1 - Nx) + imgColor.at<Vec3b>(py + 1, px + 1)[i] * Nx;
					pink = imgColor.at<Vec3b>(py + 1, px)[i] * (1 - Ny) + imgColor.at<Vec3b>(py + 1, px + 1)[i] * Ny;
					blue = imgColor.at<Vec3b>(py, px + 1)[i] * (1 - Nx) + imgColor.at<Vec3b>(py + 1, px + 1)[i] * Nx;
					resize[i] = (int)((((1 - Nx)*green + Nx * pink) + ((1 - Ny)*yellow + Ny * blue)) / 2);
				}

				result.at<Vec3b>(ry, rx)[0] = resize[0];
				result.at<Vec3b>(ry, rx)[1] = resize[1];
				result.at<Vec3b>(ry, rx)[2] = resize[2];
			}
					   
		}
	}


	imshow("color", imgColor);
	imshow("resize", result);
	waitKey(5000);
	return 0;
}
