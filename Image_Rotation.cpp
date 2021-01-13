#include <opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;


Mat rotate(Mat image1, double angle)
{
    Mat image2;
    Point2f pt(image1.cols / 2., image1.rows / 2.);  
    Mat r = getRotationMatrix2D(pt, angle, 1.0);
    warpAffine(image1, image2, r, Size(image1.cols, image1.rows));
    return image2;
}

int main()
{
    Mat image1 = imread("Sample.png");
    if (image1.empty())
    {
        cout << "Error!";
            cin.get();
            return -1;
    }
    int angle;
    cout << "Enter Angle:"<<endl;
    cin >> angle;
    Mat image2 = rotate(image1, angle);
    string windowname = "Rotated Image";
    namedWindow(windowname);
    imshow(windowname, image2);
    waitKey(0);
    destroyWindow(windowname);
    return 0;
} 
