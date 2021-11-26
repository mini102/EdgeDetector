// CV1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

void coinDetector(Mat& src, Mat& des) {
    GaussianBlur(src, src, Size(5, 5), 13);
    src.copyTo(des);
    
    std::vector<Vec3f> circles;
    HoughCircles(des, circles, HOUGH_GRADIENT, 1, 90, 225, 20, 0, 100);    
    char mystr[30];
    int i;
    for (i = 0; i < circles.size(); i++)
    {
        Vec3i c = circles[i];
        Point center(c[0], c[1]);
        int radius = c[2];

        circle(des, center, radius, Scalar(0, 255, 0), 2);
        circle(des, center, 2, Scalar(0, 0, 255), 3);
    }

    sprintf_s(mystr, "%d", i);
    printf(mystr);
    printf("\n");
    putText(des, mystr, Point(0, 50), 0, 2, Scalar(1, 1 ,1), 1, 8);

}


int main(int argc, const char* argv[])
{
    Mat coins0 = imread("C://Users//서채민//source//img//coins0.jpg",0);
    Mat coins1 = imread("C://Users//서채민//source//img//coins1.jpg",0);
    Mat coins2 = imread("C://Users//서채민//source//img//coins2.jpg",0);
    Mat coins3 = imread("C://Users//서채민//source//img//coins3.jpg",0);
    Mat coins4 = imread("C://Users//서채민//source//img//coins4.jpg",0);
    Mat coins5 = imread("C://Users//서채민//source//img//coins5.jpg",0);

    Mat C0;
    Mat C1;
    Mat C2;
    Mat C3;
    Mat C4;
    Mat C5;
    
    coinDetector(coins0, C0);
    coinDetector(coins1, C1);
    coinDetector(coins2, C2);
    coinDetector(coins3, C3);
    coinDetector(coins4, C4);
    coinDetector(coins5, C5);

    

    //imshow("original", coins0);
    imshow("couting0", C0);
    imshow("couting1", C1);
    imshow("couting2", C2);
    imshow("couting3", C3);
    imshow("couting4", C4);
    imshow("couting5", C5);
   
    waitKey();
    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.


/*coins0.convertTo(C0, CV_32F, 1 / 255.f);
    coins1.convertTo(C1, CV_32F, 1 / 255.f);
    coins2.convertTo(C2, CV_32F, 1 / 255.f);
    coins3.convertTo(C3, CV_32F, 1 / 255.f);
    coins4.convertTo(C4, CV_32F, 1 / 255.f);
    coins5.convertTo(C5, CV_32F, 1 / 255.f);*/

/*GaussianBlur(coins0, coins0, Size(7, 7), 4); //coins0: 7,7,4 /coins1,2,3: 17,17,4 coins5: 3,3,4
//Mat avg_kernel = Mat::ones(5, 5, CV_32F) / 25;	// coins0: 5,5  
//filter2D(coins1, coins1, -1, avg_kernel, Point(-1, -1), (0, 0), 4); // coins0: 4 
//medianBlur(coins1, coins1,13);  //coins0: 7, 
//Canny(coins0, coins0, 50, 100);
coins0.copyTo(C0);

std::vector<Vec3f> circles;
HoughCircles(C0, circles, HOUGH_GRADIENT, 1, 100, 170, 25, 0, 0);  //coins0: 1, 100, 170, 25, 0, 0 coins1:1, 100, 100, 15, 0, 0 /coins2: 1, 90, 105, 11, 0, 0/ 
//coins3: 1, 90, 105, 11, 0, 0 /coins4 1, 50, 90, 19, 0, 0 (14개)/ coins5 1, 50, 90, 100, 0, 0 (6개) 올리면 검출도 낮, 정확도 높
char mystr[30];
int i;
for (i = 0; i < circles.size(); i++)
{
    Vec3i c = circles[i];
    Point center(c[0], c[1]);
    int radius = c[2];

    circle(C0, center, radius, Scalar(0, 255, 0), 2);
    circle(C0, center, 2, Scalar(0, 0, 255), 3);
}

sprintf_s(mystr, "%d", i);
putText(C0, mystr, Point(0, 50), 0, 2, Scalar(1, 1, 1), 1, 8);*/