void green_demo_4(Mat &image) {
	std::vector<Mat>mv;
	split(image, mv);		//将split拆分为mv[]
	const double thresh=0.038;
	Mat B = mv[0], G = mv[1], R = mv[2];
	Mat dst1 = Mat::zeros(mv[0].size(), CV_64FC1);
	Mat dst2 = Mat::zeros(mv[0].size(), CV_8UC1);
	int w = mv[0].cols;  //宽度，表示第几列
	int h = mv[0].rows;  //高度，行数，表示第几行
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			double g_pixel = G.at<uchar>(row, col);
			double b_pixel = B.at<uchar>(row, col);
			double r_pixel = R.at<uchar>(row, col);
			double r = r_pixel / (r_pixel + g_pixel + b_pixel);
			double g = g_pixel / (r_pixel + g_pixel + b_pixel);
			double b = b_pixel / (r_pixel + g_pixel + b_pixel);
			double MxG = 2*g - r - b;
			//dst1.at<double>(row, col) = MxG;
			int pp = 25;
			if (MxG > thresh) {
				 pp = 255;
			}
			else {
				 pp = 0;
			}
			dst2.at<uchar>(row, col) = pp;
		}
	}
	mv[0] = B & dst2;
	mv[1] = G & dst2;
	mv[2] = R & dst2;
	merge(mv, dst2);
	imshow("gg", dst2);
}
