#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>

using namespace std;
using namespace cv;


int main()
{
	VideoCapture cap(0, CAP_V4L2);

	if (!cap.isOpened()) {
		cerr << "VideoCapture not opened" << endl;
		exit(-1);
	}

	VideoWriter writer("appsrc ! videoconvert ! video/x-raw,format=YUY2,width=640,height=480,framerate=30/1 ! jpegenc ! rtpjpegpay ! udpsink host=127.0.0.1 port=5000", CAP_GSTREAMER, 0, 30, Size(640, 480), true);

	if (!writer.isOpened()) {
		cerr << "VideoWriter not opened" << endl;
		exit(-1);
	}

	while (true) {
		Mat frame;
		cap.read(frame);
		writer.write(frame);
	}

	return 0;
}
