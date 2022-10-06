#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
int main()
//5 basics functions in openCV  
{
    std::string path = "/home/tipparn/Pictures/wallhaven-4ljzlq.jpg";
    Mat img = imread(path);
    Mat gray, imgCanny;
    Mat imgblur,imgDia,imgErode;

    cvtColor(img, gray, COLOR_BGR2GRAY);// take the picture and make it gray 
    GaussianBlur(img,imgblur,Size(3,3),3,0);//Blur the image 
    Canny(img,imgCanny,50,150);//make out the edges 

    Mat kernel =getStructuringElement(MORPH_RECT, Size(3,3)); // is the sructure to use in dilate and erode
    dilate(imgCanny,imgDia,kernel); // make the edges thicker 
    erode(imgDia,imgErode,kernel); // makes the edges less thicker

// show all the images we done 
    imshow("Image",img);
    imshow("Image Gray",gray);
    imshow("Image blur",imgblur);
    imshow("Image edge detect",imgCanny);
    imshow("Image dilation",imgDia);
    imshow("Image Erode",imgErode);
    waitKey(0);// wait for a key stroke
    return 0;

}
