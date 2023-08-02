/*******************************************************************************************/
//g++ main.cpp RTSPcam.cpp -o gstreamer_run `pkg-config --cflags --libs opencv4`
/*******************************************************************************************/
#include <opencv2/opencv.hpp>
#include "RTSPcam.h"
#define GSTREAMER
//#define FFMPEG
/*******************************************************************************************/
int main()
{
    cv::Mat frame;
    cv::namedWindow("RTSP REALTIME CAPTURE", cv::WINDOW_AUTOSIZE);
#ifdef GSTREAMER
    std::string pipeline = "rtspsrc location=rtsp://admin:admin@172.196.128.155:554/videoinput_1:0/h264_1/media.stm latency=0 ! rtph264depay ! h264parse ! omxh264dec ! nvvidconv ! videoconvert ! video/x-raw, format=BGR ! appsink";
    RTSPcam cam(pipeline, cv::CAP_GSTREAMER);
#endif 

#ifdef FFMPEG
    setenv("OPENCV_FFMPEG_CAPTURE_OPTIONS", "rtsp_transport;tcp", 1);
    const std::string RTSP_URL = "rtsp://192.168.178.129:8554/test/";
    RTSPcam cam(RTSP_URL, cv::CAP_FFMPEG);
#endif     
    while(true)
    {
        if(!cam.GetLatestFrame(frame))
		{
            std::cout << "Capture read error" << std::endl;
            break;
        }
        ///place here your time consuming algorithms
        //show frame
        cv::imshow("RTSP Camera Grabber",frame);
        char esc = cv::waitKey(1);
        if(esc == 27) 
			break;
    }
    cv::destroyAllWindows();
    return 0;
}
/*******************************************************************************************/

