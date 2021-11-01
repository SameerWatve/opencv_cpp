#include <opencv2/opencv.hpp>
#include <vector>

int main(int argc, char **argv)
{
  cv::Mat canvas = cv::imread(argv[1]);//load image
  //draw cirlce
  cv::circle(canvas, cv::Point(canvas.cols / 2, canvas.rows / 2), 100, cv::Scalar(255, 255, 255));

  // draw reactangle
  // cv::rectangle(canvas, cv::Point(20,5), cv::Point(400,200), cv::Scalar(0,255,0));
  std::cout << canvas.rows << canvas.cols << std::endl;
  for (int i = 5; i < 200; ++i) {
    for (int j = 20; j < 400; ++j) {
      canvas.at<cv::Vec3b>(i, j) = cv::Vec3b(0, 255, 0);
    }
  }

  // roi
  for (int i = 700, j = 0, count = 0; i < 801; i += 20, j += 20, count += 50) {
    cv::Mat roi = canvas(cv::Rect(i, j, 1600 - 2 * i, 200 - 2 * j));
    roi.setTo(count);// roi = i*2;
  }

  // split, min max pixel value
  std::vector<cv::Mat> bgr_planes;
  split(canvas, bgr_planes);
  cv::Mat green = bgr_planes[1];
  double minPixelValue, maxPixelValue;
  cv::Point minPixelLoc, maxPixelLoc;
  cv::minMaxLoc(green, &minPixelValue, &maxPixelValue, &minPixelLoc, &maxPixelLoc);
  std::cout << "minPixelValue: " << minPixelValue << " maxPixelValue: " << maxPixelValue << " minPixelLoc: " << minPixelLoc << " maxPixelLoc: " << maxPixelLoc << std::endl;

  cv::imshow("output", green);
  cv::waitKey(-1);
}