#define _CRT_SECURE_NO_WARNINGS
#include <opencv2/imgproc.hpp >
#include <opencv2/highgui.hpp >
#include <math.h>

#define PI 3.14159265



using namespace cv;

int main() {

	int degree;
	double rad;
	printf("Input your scale degree : ");
	scanf("%d", &degree);
	rad = (double)degree*PI / 180;
	
	//roatation
	int x, y;
	int rx, ry;
	int cx, cy;
	Mat imgColor = imread("test.jpg", IMREAD_COLOR);
	int width = imgColor.cols;
	int height = imgColor.rows;
	cx = width / 2;
	cy = height / 2;
	Mat result(height, width, CV_8UC3);

	for (ry = 0; ry <height; ry++) {
		for (rx = 0; rx < width; rx++) {
				
			x = (int)((rx-cx) * cos(rad) + (ry-cy) * sin(rad))+cx;
			y = (int)((rx-cx) * (-sin(rad)) + (ry-cy) * cos(rad))+cy;
		
		
			//printf("%d %d\n", x, y);
			if (x <width && x >= 0 && y < height && y >= 0) {
				result.at<Vec3b>(ry, rx)[0] = imgColor.at<Vec3b>(y, x)[0];
				result.at<Vec3b>(ry, rx)[1] = imgColor.at<Vec3b>(y, x)[1];
				result.at<Vec3b>(ry, rx)[2] = imgColor.at<Vec3b>(y, x)[2];
			}
			else {
				result.at<Vec3b>(ry, rx)[0] = 0;
				result.at<Vec3b>(ry, rx)[1] = 0;
				result.at<Vec3b>(ry, rx)[2] = 0;
			}
		
			
		}
	}
	

	imshow("color", imgColor);
	imshow("rotation", result);
	
	waitKey(5000);
	return 0;
}
