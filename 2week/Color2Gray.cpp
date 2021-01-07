
#include <opencv2/imgproc.hpp >
#include <opencv2/highgui.hpp >

using namespace cv;

int main() {
	
	int height, width;
	int cy, cx;	
	int BLK = 50;
	int gray;
	Mat imgColor = imread("test.jpg", IMREAD_COLOR); //������ �����ϰ� ���� �����鼭 imgColor�� �Ҵ� 
	width = imgColor.cols;
	height = imgColor.rows;

	cx = width / 2;
	cy = height / 2;

	for (int i = cx - BLK; i <= cx + BLK; i++) {
		for (int j = cy - BLK; j <= cy + BLK; j++) {

			gray = (imgColor.at<Vec3b>(j, i)[0] + imgColor.at<Vec3b>(j, i)[1] + imgColor.at<Vec3b>(j, i)[2]) / 3;

			imgColor.at<Vec3b>(j, i)[0] = gray; //blue
			imgColor.at<Vec3b>(j, i)[1] = gray;	//green
			imgColor.at<Vec3b>(j, i)[2] = gray; //red
		}
	}	



	imshow("color", imgColor); //imgColor�� color�� �̸��� ���ο� â���� ����
	waitKey(5000);
	return 0;
}

