#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    if(argc!=7)
    
    {
        std::cout<<"Usage: " << argv[0] << " fixed_thresh invert(0=off,1==on) "
        "adaptive type(0==mean|1==gaussian) block_size offset image \n"
        "Example: "<<argv[0] << " 100 1 0 15 10 fruits.jpg \n";
        return -1;
    }
    auto fixed_threshold = (double)atof(argv[1]);
    auto threshold_type = atoi(argv[2]) ? cv::THRESH_BINARY : cv::THRESH_BINARY_INV;
    auto adaptive_method = atoi(argv[3]) ? cv::ADAPTIVE_THRESH_MEAN_C : cv::ADAPTIVE_THRESH_GAUSSIAN_C;
    auto block_size = atoi(argv[4]);
    auto offset = atoi(argv[5]);
    cv::Mat img = cv::imread(argv[6]);
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    if(gray.empty())
    {
        std::cout << "Ca't load image "<< argv[6] << std::endl;
        return -1;
    }
    cv::Mat out, out_adaptive;
    cv::threshold(gray, out, fixed_threshold, 255, threshold_type);
    cv::adaptiveThreshold(gray, out_adaptive, 255, adaptive_method, threshold_type, block_size, offset);

    // show results
    cv::imshow("raw", gray);
    cv::imshow("threshold", out);
    cv::imshow("adaptive threshold", out_adaptive);
    cv::waitKey(0);
    return 0;

    
}