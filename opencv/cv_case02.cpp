/**
 * @author yangjian 1171267147@qq.com
 * @brief 提取视频帧并进行显示0.

 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 */
#include <opencv2/opencv.hpp>

#include "log.h"

using namespace cv;

int main(int argc, char** argv)
{
    // spdlog::set_pattern("[%@,%!][%l] %v");
    LOG_INIT();
    if (argc < 2)
    {
        // spdlog::warn("usage: {} <input video>", argv[0]);
        // SPDLOG_LOGGER_WARN(spdlog::default_logger(), "usage: {} <input video>", argv[0]);
        LOG_WARN("usage: {} <input video>", argv[0]);
        return -1;
    }

    VideoCapture cap(argv[1]);

    if (!cap.isOpened())
    {
        // SPDLOG_LOGGER_ERROR(spdlog::default_logger(), "open {} failed!", argv[1]);
        LOG_ERROR("open {} failed!", argv[1]);
        return -1;
    }

    Mat frame;

    char key;

    namedWindow(argv[1], WINDOW_AUTOSIZE);
    do
    {
        cap.read(frame);
        if (!frame.empty())
            imshow(argv[1], frame);

        key = waitKey(100);
    } while (key != 'q');

    destroyWindow(argv[1]);

    return 0;
}