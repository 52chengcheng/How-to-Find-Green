#include<opencv2\opencv.hpp>
#include<GreenDemo.h>
#include<iostream>


using namespace cv;
using namespace std;


int main(int argc, char**argv) {

	Mat src = imread("F:/Open cv/picture/超绿特征分割示例图.png");
	
	/*if (src.empty())
	{
		printf("not image....\n");
		return -1;
	}*/
	
	//namedWindow("input", WINDOW_FREERATIO);
	imshow("input",src);


	GreenDemo qd;
	qd.green_channels_demo(src);
	waitKey(0);		//设置waitKey(0),则表示程序会无限制的等待用户
	destroyAllWindows();	//您可以调用destroyWindow（）或destroyAllWindows（）来关闭窗口并取消分配任何相关的内存使用。对于一个简单的程序，实际上不必调用这些函数，因为退出时操作系统会自动关闭应用程序的所有资源和窗口
	return 0;


}
