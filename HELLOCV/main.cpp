#if 0

#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;

int main(void)
{


	return 0;

}




#endif

#if 1

#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;

int main(void)
{


	return 0;

}




#endif



#if 0

#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;

int main(void)
{
	VideoCapture cap(0);

	if (!cap.isOpened())
	{
		cerr << "VIDEO OPEN FAILED" << endl;
		return -1;
	}

	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
	double fps = cvRound(cap.get(CAP_PROP_FPS));
	
	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');	//	������ ������ ������ �� DIVX �ڵ��� ����ϱ� ���� ����
	int delay = cvRound(1000 / fps);


	VideoWriter outputvideo("output.avi", fourcc, fps, Size(w, h));	//	DIVX �ڵ��� �̿��ϴ� output.avi �������� w x h ũ��� �����Ѵ�.

	if (!outputvideo.isOpened())
	{
		cerr << "FILE OPEN FAILED" << endl;
		return -1;
	}

	Mat frame, inversed;
	while (1)
	{
		cap >> frame;

		if (frame.empty())
			break;

		inversed = ~frame;
		outputvideo << inversed;	//	inversed ������ �����Ѵ�.


		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(delay) == 27)
			break;
	}

	destroyAllWindows();

	return 0;

}




#endif
// VideoWriter - ������ �߶� ���� �����ϱ�


#if 0

#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;

int main(void)
{
	VideoCapture cap("stopwatch.avi");

	if (!cap.isOpened())
	{
		cerr << "Video Open Failed" << endl;
		return -1;
	}

	cout << "FRAME WIDTH : " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "FRAME HEIGHT : " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
	cout << "FRAME  : " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;		//	��ü ������ �� ���

	double fps = cap.get(CAP_PROP_FPS);
	cout << "FPS : " << fps << endl;	//	���� ������ �ʴ� ������ ���� �޾ƿ� ����Ѵ�.

	int delay = cvRound(1000 / fps);	//	FPS ������ ���� �� ������ �ð� ������ �޾ƿ� ����Ѵ�.


	Mat frame, inversed;
	while (1)
	{
		cap.read(frame);	//	ī�޶� ��ġ�κ��� �� �������� �޾ƿ� frame ������ �����Ѵ�. (cap >> frame)
		
		if (frame.empty())
			break;

		inversed = ~frame;

		namedWindow("frame");
		imshow("frame", frame);

		imshow("inversed", inversed);


		if (waitKey(delay) == 27)
			break;



	}


	destroyAllWindows();

	return 0;

}


#endif
// Videocapture - ���� ����ϱ�


#if 0

#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;

int main(void)
{
	VideoCapture CAM(0);

	if (!CAM.isOpened())
	{
		cerr << "CAM OPEN FAIL" << endl;
		return -1;
	}

	cout << "FRAME WIDTH : " << cvRound(CAM.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "FRAME HEIGHT : " << cvRound(CAM.get(CAP_PROP_FRAME_HEIGHT)) << endl;


	Mat frame, inversed;

	while (1)
	{
		CAM >> frame; // CAM.read(frame)

		if (frame.empty())
			break;

		inversed = frame;


		imshow("frame", frame);
		imshow("inversed", inversed);


		if (waitKey(10) == 27)	//	ESC Ű�� ������ ����. & CAM���� ���� �������� 10ms ����� �� ����.
			break;
	}

	destroyAllWindows();

	return 0;

}




#endif
// Videocapture - CAM ���� ����ϱ�



#if 0

#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;

void printMat(InputArray _Mat);


int main(void)
{
	uchar data1[] = { 1,2,3,4,5,6 };
	Mat mat1(2, 3, CV_8U, data1);
	printMat(mat1);


	Vec3f vec1 = { 1.2, 3.4, -2.1 };
	printMat(vec1);
	cout << vec1 << endl;
	

	return 0;

}

void printMat(InputArray _Mat) {

	Mat mat = _Mat.getMat();
	cout << mat << endl;

}




#endif
// Inputarray, Outputarray

#if 0

#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;

int main(void)
{
	Vec3b p1;
	Vec3b p2(0, 0, 255);	//	p1, p2������ Vector Ŭ������ ����. 3b�� ���� �Ǿ����Ƿ� 3���� �����Ͱ� unsigned char�� �����.

	cout << "p1 : " << p1 << endl;
	cout << "p2 : " << p2 << endl;
	
	p1[0] = 100;

	cout << "p1 : " << p1 << endl;
	cout << "p2 : " << p2 << endl;
	cout << "\n\n\n"<< endl;

	//---------------------------------------------------------//
	
	/* ���� ���Ǵ� Scalar ��� ���


	Scalar(���)
	Scalar(r,g,b)
	Scalar(���, r,g,b, ����)


	*/

	Scalar gray = 128;
	Scalar yellow(0, 255, 255);

	cout << "gray : " << gray << endl;
	cout << "yellow : " << yellow << endl;

	Mat y(256, 256, CV_8UC3, yellow);
	namedWindow("yellow");
	imshow("yellow", y);
	waitKey();


	return 0;

}




#endif
// vec, scalar


#if 0

#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;

int main(void)
{

	Mat img1 = imread("lenna.bmp", IMREAD_GRAYSCALE);		//	CV_8UC1

	Mat img1f;
	img1.convertTo(img1f, CV_32FC1);		//		��� ���� Ÿ�� ���� 8U -> 32F


	//--------------------------------------------------------//


	uchar data1[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	
	Mat mat1(3, 4, CV_8UC1, data1);

	Mat mat2 = mat1.reshape(0, 1);	//	int1�� ���ο� ä�� ��, in2�� ���ο� ���� ��
	Mat mat3 = mat1.reshape(0, 2);

	cout << "mat1 : " << mat1 << endl;
	cout << "mat2 : " << mat2 << endl;
	cout << "mat3 : " << mat3 << endl;


	mat1.resize(9, 200);	//	mat1�� �� ũ�⸦ 9��ŭ �ø��� ��ĭ�� '200'���� ä���.
	cout << "mat1 : " << mat1 << "\n\n\n" << endl;



	//--------------------------------------------------------//

	Mat mat4 = Mat::ones(1, 4, CV_8UC1) * 255;	//	mat4�� 1�� 4���� �̷���� �׷��̽����Ϸ� �ʱ�ȭ �ϰ�, �� ��Ŀ� 255�� ������.
	mat1.push_back(mat4);		//	mat1�� ������ �࿡ mat4 �����͸� �߰��Ѵ�.
	cout << "mat1 : " << mat1 << "\n\n\n" << endl;

	mat1.pop_back(1);		//	mat1�� ������ 1���� �����Ѵ�.
	cout << "mat1 : " << mat1 << "\n\n\n" << endl;

	return 0;

}




#endif
// ��� ������ ����



#if 0

#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;

int main(void)
{

	float data[] = { 1, 1, 2,3 };
	
	Mat mat1(2, 2, CV_32FC1, data);
	Mat mat2 = mat1.inv();

	cout << "mat1 : \n" << mat1 << endl;
	cout << "\nmat1 inv : \n" << mat2 << endl;

	Mat mat3 = mat1.t();
	cout << "\nmat1 ��ġ��� :  \n" << mat3 << endl;
	cout << "\nmat1 + mat1 : \n" << mat1 + mat1 << endl;
	cout << "\nmat1 + 3 : \n" << mat1 + 3 << endl;
	cout << "\nmat1 * 3 : \n" << mat1 * 3 << endl;
	cout << "\nmat1 * mat1 : \n" << mat1 * mat1 << endl;
	cout << "\nmat1 (mul) mat1 : \n" << mat1.mul(mat1) << endl;


	return 0;

}




#endif
// ��� ����


#if 0

#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;

int main(void)
{
	Mat img1 = imread("lenna.bmp");

	cout << "Width : " << img1.rows << endl;
	cout << "Height : " << img1.cols << endl;
	cout << "CHANNELS : " << img1.channels() << endl;
	cout << "DEPTH : " << img1.depth() << endl;

	if(img1.type() == CV_8UC1)
		cout << "img1 is Grayscale Image" << endl;
	else if (img1.type() == CV_8UC3)
		cout << "img1 is Truecolor Image" << endl;


	float data[] = { 2.0f, 1.144f, 4.232f, 5.2255f };
	
	
	Mat mat1(2, 2, CV_32FC1, data);
	cout << mat1 << endl;




	return 0;

}




#endif
// ��� ���� ����


#if 0

#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;

int main(void)
{

	Mat img1 = imread("cat.bmp");
	Mat img2 = img1(Rect(220, 120, 340, 240));		//		Mat img2 = img1(Rect(220, 120, 340, 240)).clone()
	
	img2 = ~img2;

	imshow("img1", img1);
	imshow("img2", img2);

	

	waitKey();
	destroyWindow("img1");

	return 0;

}




#endif
// �κ� ���� ���


#if 0

#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;

int main(void)
{

	Mat img1 = imread("dog.bmp");

	Mat img2 = img1;
	Mat img3;
	img3 = img1;

	Mat img4 = img1.clone();
	Mat img5;
	img1.copyTo(img5);

	
	img1.setTo(Scalar(0, 255, 255));
	img1 = Scalar(0, 255, 255);

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);	//	���� ����
	imshow("img4", img4);
	imshow("img5", img5);	// ���� ����

	waitKey();
	destroyAllWindows();


	return 0;

}




#endif
// ���� ����

#if 0

#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;

int main(void)
{

	Mat img1;
	Mat img2(480, 640, CV_8UC1);	//	unsigned char �ڷ����� ����ϴ� �Ѱ��� ä���� �ִ� ���� ( 640 x 480 ) >> �׷��̽�����
	Mat img3(480, 640, CV_8UC3);	//	unsigned char �ڷ����� ����ϴ� ������ ä���� �ִ� ���� ( 640 x 480 ) >> Ʈ���÷�

	Mat img4(480, 640, CV_8UC1, Scalar(128));
	Mat img4(Size(640, 480), CV_8UC1, Scalar(128));	//	��� �ȼ��� ��Ⱑ 128�� �ʱ�ȭ��, 640 X 480 �������� �׷��̽����� ����

	Mat img4(480, 640, CV_8UC3, Scalar(128, 128, 128));
	Mat img4(Size(640, 480), CV_8UC3, Scalar(128, 128, 128));	//	��� �ȼ��� RGB�� (128, 128, 128) �� �ʱ�ȭ��, 640 X 480 �������� Ʈ���÷� ����

	Mat img5 = Mat::zeros(3, 3, CV_32SC1);	//	Mat:zeros �Լ��� ��� �ȼ��� ��⸦ 0���� �ʱ�ȭ��.
											//	3 x 3 �������� 0���� �ʱ�ȭ�� ����


	float data[] = { 1,2,3,4,5,6 };
	Mat mat1(2, 3, CV_32FC1, data);	//	mat4 = | 1  2  3 |				Mat mat1 = (Mat_<float>(2,3) << 1,2,3,4,5,6);
									//		   | 4  5  6 |
									//									Mat_<float> mat1_(2,3);
									//									mat1_ << 1,2,3,4,5,6;
									//									Mat mat1 = mat1_;						

	return 0;

}




#endif
// �ȼ� �ʱ�ȭ

#if 0

#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;

int main(void)
{

	Mat imgs[3];
	for (int i = 0; i < 3; i++)
	{
		String filename = format("test%02d.bmp", i + 1);
		imgs[i] = imread(filename);

	}

	//	Opencv Mat Ŭ������ test01.bmp, test02.bmp, test03.bmp�� �ҷ���


	return 0;

}




#endif
// ���� ������ ���� ��


#if 0

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	
	Point pt1(20, 20);
	Point pt2(30, 20);

	cout << "Point : " << pt1 << endl;
	cout << "Point : " << pt2 << endl;

	Size sz1(10, 20);
	Size sz2;
	sz2.width = 10; sz2.height = 40;

	cout << "\n\nSize : " << sz1 << endl;
	cout << "Size : " << sz2 << endl;


	Rect rc1(0, 0, 50, 40);		//	������� ��ǥ, width, height
	Rect rc2;
	rc2.width = 60;
	rc2.height = 40;
	rc2.x = 20;
	rc2.y = 20;

	cout << "\n\nRect : " << rc1 << endl;
	cout << "Rect : " << rc2 << endl;


	Rect rc3 = rc1 + Size(10, 20);
	cout << "\n\nRect : " << rc3 << endl;
	rc3 = rc1 + sz1;					//		Size sz1(10, 20);
	cout << "Rect : " << rc3 << endl;


	rc3 = rc1 + Point(0,0);
	cout << "\n\nRect : " << rc3 << endl;
	rc3 = rc1 + pt1;					//		Point pt1(20, 20);
	cout << "Rect : " << rc3 << endl;




	Rect rc4 = rc1 & rc2;				//		Rect rc1(0, 0, 50, 40);		Rect rc2(20, 20, 60, 40);
	cout << "\n\nRect(�� �簢�� �����ϴ� ũ��) : " << rc4 << endl;
	rc4 = rc1 | rc2;					//		Rect rc1(0, 0, 50, 40);		Rect rc2(20, 20, 60, 40);
	cout << "Rect(�� �簢�� ��� �����ϴ� �ּ� ũ��) : " << rc4 << endl;


	cout << "\n\n=============================================================\n\n"<< endl;


	RotatedRect rtrc1(Point2f(40, 30), Size2f(40, 20), 30);	//	Point, Size, Angle	ȸ���� �簢��

	Point2f vertices[4];
	rtrc1.points(vertices);


	cout << "\n\nPoint 0: (" << vertices[0].x << ", " << vertices[0].y << ")" << endl;	//	�����ϴܺ��� �ð��������
	cout << "Point 1: (" << vertices[1].x << ", " << vertices[1].y << ")" << endl;
	cout << "Point 2: (" << vertices[2].x << ", " << vertices[2].y << ")" << endl;
	cout << "Point 3: (" << vertices[3].x << ", " << vertices[3].y << ")" << endl;

	Rect br = rtrc1.boundingRect2f();		//	ȸ���� �簢���� ���δ� �ּ� ũ���� �簢��

	cout << "Bounding Rect Point: " << br.tl() << endl;	//	ȸ���� �簢���� ���δ� �ּ� ũ���� �簢�� >> ���� ��� ��ǥ
	cout << "Bounding Rect Size: " << br.size() << endl;	//	ȸ���� �簢���� ���δ� �ּ� ũ���� �簢�� >> ũ��

	return 0;
}

#endif
//	Point, Size, Rect, RotatedRect

#if 0

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	cout << "HELLO OPENCV " << CV_VERSION << endl;

	Mat img = imread("lenna.bmp", IMREAD_COLOR);

	if (img.empty())
	{
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("image", WINDOW_NORMAL);	
	imshow("image", img);



	waitKey();

	return 0;
}

#endif