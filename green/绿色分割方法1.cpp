
void green_demo_1(Mat &image) {
	const double r = -0.7, g = 0.6, b = 0.2;
	const double thresh = 20;
	std::vector<Mat>mv;
	split(image, mv);		//将split拆分为mv[]
	Mat B = mv[0], G = mv[1], R = mv[2];

	Mat dst = Mat::zeros(mv[0].size(), CV_8UC1);
	
	int w = mv[0].cols;  //宽度，表示第几列
	int h = mv[0].rows;  //高度，行数，表示第几行
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			double g_pixel = G.at<uchar>(row, col);
			double b_pixel = B.at<uchar>(row, col);
			double r_pixel = R.at<uchar>(row, col);
			double p_cyan = r * r_pixel + g * g_pixel + b * b_pixel;
			
			if (p_cyan<0) {
				p_cyan = 0;
			}
			else if (p_cyan >255) {
				p_cyan = 255;
			}
			if (p_cyan>thresh) {
				p_cyan = 255;
			}
			else {
				p_cyan = 0;
			}
			dst.at<uchar>(row, col)= p_cyan;
		}
	}
	imshow("2005", dst);
	mv[0] = B & dst;
	mv[1] = G & dst;
	mv[2] = R & dst;
	merge(mv, dst);
	imshow("end", dst);

}
