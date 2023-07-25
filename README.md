# RTSP-with-OpenCV-using-Nvidia-Encoder
RTSP - streams in OpenCV via GSTREAMER and Nvidia Encoder  (with neglectable latency)

It is a known issue with RTSP streams and time-consuming algorithms such as deep learning frameworks. You're getting out of sync if individual frames take longer than your stream's frame rate to process. There is an increasing delay between reality and the captured images.

There are two possible solutions to this problem.
You could continuously grabbing images in a seperated thread.
Or determine the missed images and skipping them before grabbing a new frame. The latter solution is implemented here.

The code speaks for itself.
Using GStreamer to open the stream via OpenCV VideoCapture Library Call.
RTSP streams usually are compressed with H264. Therefore your decompression is sensitive for timing issues, like threads halted for some time.
But using Nvidia Encoder Supported Graphics Cards Decompression of H264 Video Frames Processing is done at Real Time.
