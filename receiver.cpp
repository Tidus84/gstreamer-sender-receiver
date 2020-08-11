#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	VideoCapture cap("udpsrc port=5000 ! application/x-rtp,media=video,payload=26,clock-rate=90000,encoding-name=JPEG,framerate=30/1 ! rtpjpegdepay ! jpegdec ! videoconvert ! appsink", CAP_GSTREAMER);

	if (!cap.isOpened()) {
		cerr << "VideoCapture not opened" << endl;
		exit(-1);
	}
    
	while (true) {
		Mat frame;
		cap.read(frame);        
		imshow("Receiver window", frame);
		if (waitKey(1) == 27)
			break;
	}

    return 0;
}
