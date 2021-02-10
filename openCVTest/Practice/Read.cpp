#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
int main()
{
    std::string path = "/home/tipparn/Pictures/wallhaven-4ljzlq.jpg";
    std::string pathVideo = "/run/media/tipparn/FBA1-74CD/TV Shows/The EXPANSE/Season 01/The EXPANSE - S01 E01 - Dulcinea.mp4";
    VideoCapture video(pathVideo);
    Mat img;
while (true)
 {
    video.read(img);
    imshow("video", img);
    waitKey(20);
}
    return 0;
}