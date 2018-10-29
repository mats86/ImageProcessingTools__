#include <jni.h>
#include <string>
#include <android/log.h>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/dnn.hpp>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <tuple>
// #include "decodeFunction.cpp"

using namespace cv;
using namespace dnn;

extern "C"
{
    JNIEXPORT jstring JNICALL
    Java_com_example_malattas_imageprocessingtools_TextRecognitionActivity_textRecognition(
            JNIEnv *env,
            jobject /* this */,
            /*jlong addrRgba,*/
            jstring jImPath) {
        const char *imPath = (*env).GetStringUTFChars(jImPath, NULL);
        jstring result;

//        std::string outText, test;
//        std::string imPath_ = "/storage/emulated/0/DCIM/ImageProcessing/test.jpg";
//
//        // initilize tesseract OCR engine
//        tesseract::TessBaseAPI *myOCR = new tesseract::TessBaseAPI();
//        __android_log_print(ANDROID_LOG_INFO, "__TESSERACT__", "Tesseract-ocr version: %s",
//                            myOCR->Version());
//
//        myOCR->Init("/storage/emulated/0/DCIM/ImageProcessing/", "eng");
//        __android_log_print(ANDROID_LOG_INFO, "__TESSERACT__", "Tesseract-ocr Init: %s", imPath);
//        __android_log_print(ANDROID_LOG_INFO, "__TESSERACT__", "Tesseract-ocr Init: %s",
//                            imPath_.c_str());
//
//        // Set Page segmentation mode to PSM_AUTO (3)
//        myOCR->SetPageSegMode(tesseract::PSM_AUTO);
//
//        // Open input image using OpenCV
//        Mat im_ = imread(imPath, IMREAD_COLOR);
//
//        // Set image data
//        myOCR->SetImage(im_.data, im_.cols, im_.rows, 3, (int) im_.step);
//
//        // Run Tesseract OCR on image
//        outText = std::string(myOCR->GetUTF8Text());
//        __android_log_print(ANDROID_LOG_INFO, "__TESSERACT__", "Tesseract-ocr OUT: %s",
//                            outText.c_str());
//
//        //result = (*env).NewStringUTF(outText.c_str());
//        result = (*env).NewStringUTF(myOCR->Version());
//
//        float confThreshold = 0.5;
//        float nmsThreshold = 0.4;
//        int inpWidth = 320;
//        int inpHeight = 320;
//        String model = "/Users/mats86/Downloads/frozen_east_text_detection.pb";
//
//        // Load network.
//        Net net = readNet(model);
//
//        std::vector<Mat> outs;
//        std::vector<String> outNames(2);
//        outNames[0] = "feature_fusion/Conv_7/Sigmoid";
//        outNames[1] = "feature_fusion/concat_3";
//
//        Mat frame, blob;
//
//        frame = imread(imPath, IMREAD_COLOR);
//        blobFromImage(frame, blob, 1.0, Size(inpWidth, inpHeight), Scalar(123.68, 116.78, 103.94), true, false);
//        net.setInput(blob);
//        net.forward(outs, outNames);
//
//        Mat scores = outs[0];
//        Mat geometry = outs[1];
//
//        // Decode predicted bounding boxes.
//        std::vector<RotatedRect> boxes;
//        std::vector<float> confidences;
//        decodeFunction(scores, geometry, confThreshold, boxes, confidences);
//
//        // Apply non-maximum suppression procedure.
//        std::vector<int> indices;
//        NMSBoxes(boxes, confidences, confThreshold, nmsThreshold, indices);
//        // Render detections.
//        Point2f ratio((float)frame.cols / inpWidth, (float)frame.rows / inpHeight);
//        for (size_t i = 0; i < indices.size(); ++i)
//        {
//            RotatedRect& box = boxes[indices[i]];
//            Point2f vertices[4];
//            box.points(vertices);
//            for (int j = 0; j < 4; ++j)
//            {
//                vertices[j].x *= ratio.x;
//                vertices[j].y *= ratio.y;
//            }
//            for (int j = 0; j < 4; ++j)
//                line(frame, vertices[j], vertices[(j + 1) % 4], Scalar(0, 255, 0), 1);
//        }
//        // Put efficiency information.
//        std::vector<double> layersTimes;
//        double freq = getTickFrequency() / 1000;
//        double t = net.getPerfProfile(layersTimes) / freq;
//        std::string label = format("Inference time: %.2f ms", t);
//        __android_log_print(ANDROID_LOG_INFO, "__TESSERACT__", "Tesseract-ocr OUT: %s", label.c_str());

        return result;
    }

    void decodeFunction(const Mat& scores, const Mat& geometry, float scoreThresh,
                        std::vector<RotatedRect>& detections, std::vector<float>& confidences)
    {
        detections.clear();
        CV_Assert(scores.dims == 4); CV_Assert(geometry.dims == 4); CV_Assert(scores.size[0] == 1);
        CV_Assert(geometry.size[0] == 1); CV_Assert(scores.size[1] == 1); CV_Assert(geometry.size[1] == 5);
        CV_Assert(scores.size[2] == geometry.size[2]); CV_Assert(scores.size[3] == geometry.size[3]);
        const int height = scores.size[2];
        const int width = scores.size[3];
        for (int y = 0; y < height; ++y)
        {
            const float* scoresData = scores.ptr<float>(0, 0, y);
            const float* x0_data = geometry.ptr<float>(0, 0, y);
            const float* x1_data = geometry.ptr<float>(0, 1, y);
            const float* x2_data = geometry.ptr<float>(0, 2, y);
            const float* x3_data = geometry.ptr<float>(0, 3, y);
            const float* anglesData = geometry.ptr<float>(0, 4, y);
            for (int x = 0; x < width; ++x)
            {
                float score = scoresData[x];
                if (score < scoreThresh)
                    continue;
                // Decode a prediction.
                // Multiple by 4 because feature maps are 4 time less than input image.
                float offsetX = x * 4.0f, offsetY = y * 4.0f;
                float angle = anglesData[x];
                float cosA = std::cos(angle);
                float sinA = std::sin(angle);
                float h = x0_data[x] + x2_data[x];
                float w = x1_data[x] + x3_data[x];
                Point2f offset(offsetX + cosA * x1_data[x] + sinA * x2_data[x],
                               offsetY - sinA * x1_data[x] + cosA * x2_data[x]);
                Point2f p1 = Point2f(-sinA * h, -cosA * h) + offset;
                Point2f p3 = Point2f(-cosA * w, sinA * w) + offset;
                RotatedRect r(0.5f * (p1 + p3), Size2f(w, h), -angle * 180.0f / (float)CV_PI);
                detections.push_back(r);
                confidences.push_back(score);
            }
        }
    }
}

