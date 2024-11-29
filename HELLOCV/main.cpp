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
	
	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');	//	동영상 파일을 생성할 때 DIVX 코덱을 사용하기 위한 변수
	int delay = cvRound(1000 / fps);


	VideoWriter outputvideo("output.avi", fourcc, fps, Size(w, h));	//	DIVX 코덱을 이용하는 output.avi 동영상을 w x h 크기로 저장한다.

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
		outputvideo << inversed;	//	inversed 비디오를 저장한다.


		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(delay) == 27)
			break;
	}

	destroyAllWindows();

	return 0;

}




#endif
// VideoWriter - 프레임 잘라서 영상 저장하기


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
	cout << "FRAME  : " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;		//	전체 프레임 수 출력

	double fps = cap.get(CAP_PROP_FPS);
	cout << "FPS : " << fps << endl;	//	비디오 파일의 초당 프레임 수를 받아와 출력한다.

	int delay = cvRound(1000 / fps);	//	FPS 값으로 부터 각 프레임 시간 간격을 받아와 계산한다.


	Mat frame, inversed;
	while (1)
	{
		cap.read(frame);	//	카메라 장치로부터 한 프레임을 받아와 frame 변수에 저장한다. (cap >> frame)
		
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
// Videocapture - 영상 출력하기


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


		if (waitKey(10) == 27)	//	ESC 키를 누르면 종료. & CAM으로 다음 프레임을 10ms 대기한 후 받음.
			break;
	}

	destroyAllWindows();

	return 0;

}




#endif
// Videocapture - CAM 영상 출력하기



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
	Vec3b p2(0, 0, 255);	//	p1, p2변수를 Vector 클래스로 선언. 3b로 선언 되었으므로 3개의 데이터가 unsigned char로 저장됨.

	cout << "p1 : " << p1 << endl;
	cout << "p2 : " << p2 << endl;
	
	p1[0] = 100;

	cout << "p1 : " << p1 << endl;
	cout << "p2 : " << p2 << endl;
	cout << "\n\n\n"<< endl;

	//---------------------------------------------------------//
	
	/* 많이 사용되는 Scalar 사용 방법


	Scalar(밝기)
	Scalar(r,g,b)
	Scalar(밝기, r,g,b, 투명도)


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
	img1.convertTo(img1f, CV_32FC1);		//		행렬 원소 타입 변경 8U -> 32F


	//--------------------------------------------------------//


	uchar data1[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	
	Mat mat1(3, 4, CV_8UC1, data1);

	Mat mat2 = mat1.reshape(0, 1);	//	int1은 새로운 채널 수, in2는 새로운 행의 수
	Mat mat3 = mat1.reshape(0, 2);

	cout << "mat1 : " << mat1 << endl;
	cout << "mat2 : " << mat2 << endl;
	cout << "mat3 : " << mat3 << endl;


	mat1.resize(9, 200);	//	mat1의 행 크기를 9만큼 늘리고 빈칸을 '200'으로 채운다.
	cout << "mat1 : " << mat1 << "\n\n\n" << endl;



	//--------------------------------------------------------//

	Mat mat4 = Mat::ones(1, 4, CV_8UC1) * 255;	//	mat4를 1행 4열로 이루어진 그레이스케일로 초기화 하고, 각 행렬에 255를 곱해줌.
	mat1.push_back(mat4);		//	mat1의 마지막 행에 mat4 데이터를 추가한다.
	cout << "mat1 : " << mat1 << "\n\n\n" << endl;

	mat1.pop_back(1);		//	mat1의 마지막 1행을 제거한다.
	cout << "mat1 : " << mat1 << "\n\n\n" << endl;

	return 0;

}




#endif
// 행렬 데이터 변경



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
	cout << "\nmat1 전치행렬 :  \n" << mat3 << endl;
	cout << "\nmat1 + mat1 : \n" << mat1 + mat1 << endl;
	cout << "\nmat1 + 3 : \n" << mat1 + 3 << endl;
	cout << "\nmat1 * 3 : \n" << mat1 * 3 << endl;
	cout << "\nmat1 * mat1 : \n" << mat1 * mat1 << endl;
	cout << "\nmat1 (mul) mat1 : \n" << mat1.mul(mat1) << endl;


	return 0;

}




#endif
// 행렬 연산


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
// 행렬 정보 참조


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
// 부분 영상 출력


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
	imshow("img3", img3);	//	얕은 복사
	imshow("img4", img4);
	imshow("img5", img5);	// 깊은 복사

	waitKey();
	destroyAllWindows();


	return 0;

}




#endif
// 영상 복사

#if 0

#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;

int main(void)
{

	Mat img1;
	Mat img2(480, 640, CV_8UC1);	//	unsigned char 자료형을 사용하는 한개의 채널이 있는 영상 ( 640 x 480 ) >> 그레이스케일
	Mat img3(480, 640, CV_8UC3);	//	unsigned char 자료형을 사용하는 세개의 채널이 있는 영상 ( 640 x 480 ) >> 트루컬러

	Mat img4(480, 640, CV_8UC1, Scalar(128));
	Mat img4(Size(640, 480), CV_8UC1, Scalar(128));	//	모든 픽셀의 밝기가 128로 초기화된, 640 X 480 사이즈의 그레이스케일 영상

	Mat img4(480, 640, CV_8UC3, Scalar(128, 128, 128));
	Mat img4(Size(640, 480), CV_8UC3, Scalar(128, 128, 128));	//	모든 픽셀의 RGB가 (128, 128, 128) 로 초기화된, 640 X 480 사이즈의 트루컬러 영상

	Mat img5 = Mat::zeros(3, 3, CV_32SC1);	//	Mat:zeros 함수는 모든 픽셀의 밝기를 0으로 초기화함.
											//	3 x 3 사이즈의 0으로 초기화된 영상


	float data[] = { 1,2,3,4,5,6 };
	Mat mat1(2, 3, CV_32FC1, data);	//	mat4 = | 1  2  3 |				Mat mat1 = (Mat_<float>(2,3) << 1,2,3,4,5,6);
									//		   | 4  5  6 |
									//									Mat_<float> mat1_(2,3);
									//									mat1_ << 1,2,3,4,5,6;
									//									Mat mat1 = mat1_;						

	return 0;

}




#endif
// 픽셀 초기화

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

	//	Opencv Mat 클래스에 test01.bmp, test02.bmp, test03.bmp를 불러옴


	return 0;

}




#endif
// 여러 영상을 띄우는 법


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


	Rect rc1(0, 0, 50, 40);		//	좌측상단 좌표, width, height
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
	cout << "\n\nRect(두 사각형 교차하는 크기) : " << rc4 << endl;
	rc4 = rc1 | rc2;					//		Rect rc1(0, 0, 50, 40);		Rect rc2(20, 20, 60, 40);
	cout << "Rect(두 사각형 모두 포함하는 최소 크기) : " << rc4 << endl;


	cout << "\n\n=============================================================\n\n"<< endl;


	RotatedRect rtrc1(Point2f(40, 30), Size2f(40, 20), 30);	//	Point, Size, Angle	회전된 사각형

	Point2f vertices[4];
	rtrc1.points(vertices);


	cout << "\n\nPoint 0: (" << vertices[0].x << ", " << vertices[0].y << ")" << endl;	//	좌측하단부터 시계방향으로
	cout << "Point 1: (" << vertices[1].x << ", " << vertices[1].y << ")" << endl;
	cout << "Point 2: (" << vertices[2].x << ", " << vertices[2].y << ")" << endl;
	cout << "Point 3: (" << vertices[3].x << ", " << vertices[3].y << ")" << endl;

	Rect br = rtrc1.boundingRect2f();		//	회전된 사각형을 감싸는 최소 크기의 사각형

	cout << "Bounding Rect Point: " << br.tl() << endl;	//	회전된 사각형을 감싸는 최소 크기의 사각형 >> 좌측 상단 좌표
	cout << "Bounding Rect Size: " << br.size() << endl;	//	회전된 사각형을 감싸는 최소 크기의 사각형 >> 크기

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