#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <ctime>
#include <cstdlib>

using namespace cv;

void randomRotation(Mat img, Mat* imgSet, int n, int s){
    int x = img.cols / 2;
    int y = img.rows / 2;
    double angle;
    imgSet[0] = img;
    for(int i = 1; i < n; i++){
        angle = (rand() % (90 - 10) + 10) + (90 * (i - 1));
        warpAffine(img, imgSet[i], getRotationMatrix2D(Point2f(x,y), angle, 1.0), Size(s, s) );
    }
}

void resizeSet(Mat* imgSet, int n, int s){
    for(int i = 0; i < n; i++){
        resize(imgSet[i], imgSet[i], Size(s, s), 0, 0, INTER_LINEAR);
    }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    Mat img = imread("fruit.jpg", IMREAD_COLOR);

    // redimension
    Mat croppedImage, resizedImage, paddedImage;
    Mat rotated [5];
    int sectionSize = 450;
    int tam = 300;


    //recorte
    croppedImage = img(Rect(img.cols/2-sectionSize/2, img.rows/2 - sectionSize/2, sectionSize, sectionSize));

    //rotacion
    randomRotation(croppedImage, rotated, 5, sectionSize);
    resizeSet(rotated, 5, tam);

    //Padding
    /*int m = (img.cols > img.rows) ? img.cols : img.rows;
    float r = tam / m;
    int nw = img.cols * r;
    int nh = img.rows * r;
    int dw = tam - nw;
    int dh = tam - nh;

    int top = dh / 2;
    int bottom = dh - (dh / 2);
    int left = dw / 2;
    int right = dw - (dw / 2);

    copyMakeBorder(resizedImage, paddedImage, top, bottom, left, right, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));*/

    for(int i = 0; i < 5; i++){
        imshow("Imagen redimensionada", rotated[i]);
        waitKey(0);
    }
    return 0;
}



