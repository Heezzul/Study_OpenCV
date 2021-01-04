#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv; 

int main() {

	Mat imgColor = imread("test.jpg", IMREAD_COLOR); //파일의 절대경로를 지정하고 색을 가지면서 imgColor에 할당 
	Mat imgGray = imread("test.jpg", IMREAD_GRAYSCALE); //이미지를 회색으로 imgGray에 할당 

	imshow("color", imgColor); //imgColor을 color의 이름의 새로운 창으로 본다
	imshow("gray", imgGray);//imgGray을 gray의 이름의 새로운 창으로 본다

	
	waitKey(5000);

	return 0;
}
