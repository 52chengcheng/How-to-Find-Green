#include<GreenDemo.h>


void QuickDemo::green_and_demo(Mat &image) {
	std::vector<Mat>mv;
	split(image, mv);		//将split拆分为mv[]
	//imshow("blue", mv[0]);	//mv现在是单通道的，为GRAYIMG，灰度图像，单通道图像
	//imshow("green", mv[1]);
	//imshow("red", mv[2]);

	Mat dst;
	Mat B = mv[0], G = mv[1], R = mv[2];
	int w = image.cols;  //宽度，表示第几列
	int h = image.rows;  //高度，行数，表示第几行
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			int g_pixel = G.at<uchar>(row, col);
			int b_pixel = B.at<uchar>(row, col);
			int r_pixel = R.at<uchar>(row, col);
			if (g_pixel <= b_pixel || g_pixel <= r_pixel) {
				G.at<uchar>(row, col) = 0;
				B.at<uchar>(row, col) = 0;
				R.at<uchar>(row, col) = 0;
			}
		}
	}
	merge(mv, dst);
	imshow("and_green", dst);
}
