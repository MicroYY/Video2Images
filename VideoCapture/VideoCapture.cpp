
#include <string>



#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
	cv::VideoCapture cap;
	cap.open(argv[1]);
	cv::Mat frame;
	std::stringstream s(argv[3]);
	int interval;
	s >> interval;
	for (int i = 0;; i++)
	{

		cap.read(frame);
		if (frame.empty())
			break;
		std::string name = argv[2] + std::to_string(i) + ".jpg";
		if (i % interval == 0)
			cv::imwrite(name, frame);
	}
}

