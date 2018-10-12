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

void decode_predictions(const Mat& scores, const Mat& geometry, float scoreThresh,
                        vector<RotatedRect>& rects, vector<float>& confidences ) {
    // grab the number of rows and columns from the scores volume, then
    // initialize our set of bounding box rectangles and corresponding
    // confidence scores
    const int numRows = scores.size[2];
    const int numCols = scores.size[3];

    // loop over the number of rows
    for (int y = 0; y < numRows; y++)
    {
        // extract the scores (probabilities), followed by the
        // geometrical data used to derive potential bounding box
        // coordinates that surround text
        const float* scoresData = scores.ptr<float>(0, 0, y);
        const float* x0_data = geometry.ptr<float>(0, 0, y);
        const float* x1_data = geometry.ptr<float>(0, 1, y);
        const float* x2_data = geometry.ptr<float>(0, 2, y);
        const float* x3_data = geometry.ptr<float>(0, 3, y);
        const float* anglesData = geometry.ptr<float>(0, 4, y);

        // loop over the number of columns
        for (int x = 0; x < numCols; x++)
        {
            float score = scoresData[x];
            if (score < scoreThresh)
                continue;

            // compute the offset factor as our resulting feature
            // maps will be 4x smaller than the input image
            float offsetX = x * 4.0f;
            float offsetY = y * 4.0f;

            // extract the rotation angle for the prediction and
            // then compute the sin and cosine
            float angle = anglesData[x];
            float cosA = std::cos(angle);
            float sinA = std::sin(angle);

            // use the geometry volume to derive the width and height
            // of the bounding box
            float h = x0_data[x] + x2_data[x];
            float w = x1_data[x] + x3_data[x];

            // compute both the starting and ending (x, y)-coordinates
            // for the text prediction bounding box
            Point2f offset(offsetX + cosA * x1_data[x] + sinA * x2_data[x],
                           offsetY - sinA * x1_data[x] + cosA * x2_data[x]);
            Point2f p1 = Point2f(-sinA * h, -cosA * h) + offset;
            Point2f p3 = Point2f(-cosA * w, sinA * w) + offset;
            RotatedRect r(0.5f * (p1 + p3), Size2f(w, h), -angle * 180.0f / (float)CV_PI);
            rects.push_back(r);
            confidences.push_back(score);
        }
    }
}