#include <opencv2/opencv.hpp>
#include <cstdio.h>

auto main(int argc, char **argv) -> int
{
  if (argc != 2) {
    printf("usage: hello_opencv <path_image>\n");
    return -1;
  }
  cv::Mat image = cv::imread(argv[1], 1);
  if (!image.data) {
    printf("No image data \n");
    return -1;
  }
  image = image / 2;
  cv::imwrite("./data/result.png", image);
  return 0;
}