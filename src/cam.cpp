#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char **argv)
{
  cv::namedWindow("cam_vid", cv::WINDOW_AUTOSIZE);
  cv::VideoCapture cap;
  cap.open(0);
  if (!cap.isOpened()) {
    std::cerr << "Couldn't open" << std::endl;
  }
  cv::Mat frame;
  for (;;) {
    cap >> frame;
    if (frame.empty()) break;
    cv::imshow("cam_vid", frame);
    if (cv::waitKey(33) >= 0) break;
  }
  return 0;
}