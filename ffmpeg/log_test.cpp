/**
 * @author yangjian 1171267147@qq.com
 * @brief ffmpeg日志模块测试
 * @version 0.1
 * @date 2023-03-26
 *
 * @copyright Copyright (c) 2023
 */
// !c++调用c库需要extern “C"声明，否则会无法正常链接到c库
// !因为c++中多态的存在，会扩展符号表，所以需要extern "C"
#ifdef __cplusplus
extern "C"
{
#include <libavutil/log.h>
#endif
#ifdef __cplusplus
}
#endif

int main(int argc, char *argv[])
{
    av_log_set_level(AV_LOG_INFO);

    av_log(nullptr, AV_LOG_DEBUG, "ffmpeg log: %s\n", "debug");

    av_log(nullptr, AV_LOG_INFO, "ffmpeg log: %s\n", "info");

    av_log(nullptr, AV_LOG_ERROR, "ffmpeg log: %s\n", "error");
    return 0;
}
