#include <opencv2/opencv.hpp>
#include <iostream>

auto main(int argc, char **argv) -> int
{
  if (argc != 2) {
    std::cout << "usage: hello_opencv <path_image>" << std::endl;
    return -1;
  }
  cv::Mat image = cv::imread(argv[1], 1);
  if (!image.data) {
    std::cout << "No image data" << std::endl;
    return -1;
  }
  image = image / 2;
  cv::imwrite("./data/result.png", image);
  return 0;
}