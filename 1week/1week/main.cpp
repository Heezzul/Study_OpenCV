#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv; 

int main() {

	Mat imgColor = imread("C:/test.jpg", IMREAD_COLOR); //������ �����θ� �����ϰ� ���� �����鼭 imgColor�� �Ҵ� 
	Mat imgGray = imread("C:/test.jpg", IMREAD_GRAYSCALE); //�̹����� ȸ������ imgGray�� �Ҵ� 

	imshow("color", imgColor); //imgColor�� color�� �̸��� ���ο� â���� ����
	imshow("gray", imgGray);//imgGray�� gray�� �̸��� ���ο� â���� ����

	
	waitKey(5000);

	return 0;
}