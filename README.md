# gstreamer-sender-receiver
A simple example of sender and receiver via UDP using GStreamer and OpenCV

This example was tested on Ubuntu Linux 19.10 using the OpenCV 4.4.0 and GStreamer libraries

How to compile:

- g++ sender.cpp -o sender `pkg-config --cflags --libs opencv4`
- g++ receiver.cpp -o receiver `pkg-config --cflags --libs opencv4`

How to perform:

1) Open a terminal and type ./sender
2) Open another terminal and type ./receiver
