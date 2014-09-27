//////////////////////////////////////////////////////////////////////////
//������������ֱ��ͼ�������ͷ�ļ�������������࣬��������ĳ�Ա�������ͳ�Ա����;
//////////////////////////////////////////////////////////////////////////
#ifndef HISTOGRAM_H_
#define HISTOGRAM_H_
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <vector>

class Histogram {
private:
	int histSize[1];
	float hrangee[2];
	const float* ranges[1];
	int channels[1];

protected:
	cv::Mat getHistogram(const cv::Mat&);

public:
	Histogram();
	cv::Mat getHistogramImage(const cv::Mat&, int channel = 0);
	cv::Mat stretch1(const cv::Mat& image, int minValue);//�Աȶ���ǿ1��������matlab��imadjust
    cv::Mat stretch3(const cv::Mat& image);//ֱ��ͼ���⻯;
};

#endif /* HISTOGRAM_H_ */
