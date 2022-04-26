
#include<quickopencv.h>


void GreenDemo::green_channels_demo(Mat &image)
{

	std::vector<Mat>mv;
	

	split(image, mv);		//将split拆分为mv[]
	//imshow("blue", mv[0]);	//mv现在是单通道的，1为GRAYIMG，灰度图像，单通道图像
	//imshow("green", mv[1]);
	//imshow("red", mv[2]);

	Mat dst;
	Mat B = mv[0], G = mv[1], R = mv[2];
	
	Mat MxG = 2*G-R-B;
	

	//merge(mv, dst);		//此时合并mv[]给dst，dst为三通道BGR
	imshow("绿色",MxG);

	MxG.convertTo(MxG,CV_32F);
	normalize(MxG, MxG, 1, 0, NORM_MINMAX);
	MxG.convertTo(MxG, CV_8U);
	//threshold(MxG, MxG, 12, 255,THRESH_BINARY);
	//adaptiveThreshold(MxG, dst, 50, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 3, 0);
	//adaptiveThreshold(MxG, MxG, 25, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 7, 5);
	threshold(MxG, MxG, -1, 255, THRESH_OTSU);//OTSU只需传入0即可，它会自动找到阈值

	mv[0] = B & MxG;
	mv[1] = G & MxG; 
	mv[2] = R & MxG;
	merge(mv, dst);
	imshow("green2", dst);
}

