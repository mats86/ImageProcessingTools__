//
// Created by malattas on 10.10.2018.
//

#include <jni.h>
#include <string>
#include <android/log.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/dnn.hpp>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <tuple>

using namespace std;
using namespace cv;
using namespace cv::dnn;

struct rectsStruct {
    int startX;
    int startY;
    int endX;
    int endY;
};

typedef struct d_predictions{
    // rectsStruct rects;
    // int confidences;
    std::vector<RotatedRect> rects;
    std::vector<float> confidences;
};

d_predictions decode_predictions(Mat scores, Mat geometry) {
    // grab the number of rows and columns from the scores volume, then
    // initialize our set of bounding box rectangles and corresponding
    // confidence scores
}