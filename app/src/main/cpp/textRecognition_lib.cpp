#include <jni.h>
#include <string>
#include <android/log.h>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/dnn.hpp>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <tuple>
#include "decode_predictions.cpp"

using namespace std;
using namespace cv;
using namespace cv::dnn;

extern "C"
{


JNIEXPORT jstring JNICALL
Java_com_example_malattas_imageprocessingtools_TextRecognitionActivity_textRecognition(
        JNIEnv *env, jobject instance, jstring jImPath);

}

JNIEXPORT jstring Java_com_example_malattas_imageprocessingtools_TextRecognitionActivity_textRecognition(
        JNIEnv *env, jobject instance, jstring jImPath) {

    const char *imPath = (*env).GetStringUTFChars(jImPath, NULL);
    jstring result;

    string outText, test;
    string imPath_ = "/storage/emulated/0/DCIM/ImageProcessing/test.jpg";

    // initilize tesseract OCR engine
    tesseract::TessBaseAPI *myOCR = new tesseract::TessBaseAPI();
    __android_log_print(ANDROID_LOG_INFO, "__TESSERACT__", "Tesseract-ocr version: %s",
                        myOCR->Version());

    myOCR->Init("/storage/emulated/0/DCIM/ImageProcessing/", "eng");
    __android_log_print(ANDROID_LOG_INFO, "__TESSERACT__", "Tesseract-ocr Init: %s", imPath);
    __android_log_print(ANDROID_LOG_INFO, "__TESSERACT__", "Tesseract-ocr Init: %s",
                        imPath_.c_str());

    // Set Page segmentation mode to PSM_AUTO (3)
    myOCR->SetPageSegMode(tesseract::PSM_AUTO);

    // Open input image using OpenCV
    Mat im_ = imread(imPath, IMREAD_COLOR);

    // Set image data
    myOCR->SetImage(im_.data, im_.cols, im_.rows, 3, (int) im_.step);

    // Run Tesseract OCR on image
    outText = string(myOCR->GetUTF8Text());
    __android_log_print(ANDROID_LOG_INFO, "__TESSERACT__", "Tesseract-ocr OUT: %s",
                        outText.c_str());

    //result = (*env).NewStringUTF(outText.c_str());
    result = (*env).NewStringUTF(myOCR->Version());

    float confThreshold = 0.5;
    float nmsThreshold = 0.4;
    int newW = 320;
    int newH = 320;
    String model = "/storage/emulated/0/DCIM/ImageProcessing/tessdata/frozen_east_text_detection.pb";

    __android_log_print(ANDROID_LOG_INFO, "__TESSERACT__", "%s", model.c_str());
    // load the input image and grab the image dimensions
    Mat im = imread(imPath, IMREAD_COLOR);
    Mat orig;
    im.copyTo(im);
    int origH = im.rows;
    int origW = im.cols;

    // set the new width and height and then determine the ratio in change
    // for both the width and height
    // int newW = 0;
    // int newH = 0;

    int rW = (int) (origW / float(newW));
    int rH = (int) (origH / float(newH));

    __android_log_print(ANDROID_LOG_INFO, "__TESSERACT__", "%s", "test");
    // resize the image and grab the new image dimensions
    resize(im, im, Size(newW, newH));
    int H = im.rows;
    int W = im.cols;
    __android_log_print(ANDROID_LOG_INFO, "__TESSERACT__", "%s", "test2");
    vector<Mat> outs;
    vector<String> layerNames(2);
    layerNames[0] = "feature_fusion/Conv_7/Sigmoid";
    layerNames[1] = "feature_fusion/concat_3";

    //load the pre-trained EAST text detector
    __android_log_print(ANDROID_LOG_INFO, "__TESSERACT__", "%s",
                        "[INFO] loading EAST text detector...");

    Net net = readNet(model);

    // construct a blob from the image and then perform a forward pass of
    // the model to obtain the two output layer sets
    Mat frame, blob;
    blobFromImage(frame, blob, 1.0, Size(newW, newH), Scalar(123.68, 116.78, 103.94), true, false);
    net.setInput(blob);
    net.forward(outs, layerNames);

    Mat scores = outs[0];
    Mat geometry = outs[1];

    // Decode predicted bounding boxes.
    std::vector<RotatedRect> boxes;
    std::vector<float> confidences;
    decode_predictions(scores, geometry, confThreshold, boxes, confidences);

    // Apply non-maximum suppression procedure.
    std::vector<int> indices;
    NMSBoxes(boxes, confidences, confThreshold, nmsThreshold, indices);

    // Render detections.
    Point2f ratio((float) frame.cols / newW, (float) frame.rows / newH);
    for (size_t i = 0; i < indices.size(); ++i) {
        RotatedRect &box = boxes[indices[i]];

        Point2f vertices[4];
        box.points(vertices);
        for (int j = 0; j < 4; ++j) {
            vertices[j].x *= ratio.x;
            vertices[j].y *= ratio.y;
        }
        for (int j = 0; j < 4; ++j)
            line(frame, vertices[j], vertices[(j + 1) % 4], Scalar(0, 255, 0), 1);
    }

    // Put efficiency information.
    std::vector<double> layersTimes;
    double freq = getTickFrequency() / 1000;
    double t = net.getPerfProfile(layersTimes) / freq;
    std::string label = format("Inference time: %.2f ms", t);
    putText(frame, label, Point(0, 15), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0));

    return result;
}