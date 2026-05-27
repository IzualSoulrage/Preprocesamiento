#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

int main(int argc, char *argv[])
{
    Mat img = imread("fruit1.png", IMREAD_COLOR);

    Mat resizedImage, paddedImage;
    float tam = 244.0f;
    int m = (img.cols > img.rows) ? img.cols : img.rows;
    float r = tam / m;
    int nw = img.cols * r;
    int nh = img.rows * r;
    resize(img, resizedImage, Size(nw, nh), 0, 0, INTER_LINEAR);

    int dw = tam - nw;
    int dh = tam - nh;

    int top = dh / 2;
    int bottom = dh - (dh / 2);
    int left = dw / 2;
    int right = dw - (dw / 2);

    copyMakeBorder(img, paddedImage, top, bottom, left, right, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));

    imshow("Imagen redimensionada", paddedImage);
    waitKey(0);
    return 0;
}


