/**
 * @author yangjian 1171267147@qq.com
 * @brief 通过opencv转化文件格式
 * @version 0.1
 * @date 2023-04-03
 *
 * @copyright Copyright (c) 2023
 */
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        cout << "usage: " << argv[0] << " <input image> <output image>" << endl;
        return 0;
    }

    Mat src = imread(argv[1], IMREAD_ANYCOLOR);
    if (src.empty())
    {
        cout << "read image is empty!" << endl;
        return 0;
    }
    imwrite(argv[2], src);
    return 0;
}