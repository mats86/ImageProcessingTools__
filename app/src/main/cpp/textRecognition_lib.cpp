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
#include "C:\Users\malattas\Documents\AndroidProject\ImageProcessingTools\app\src\main\cpp\decode_predictions.cpp"

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
    __android_log_print(ANDROID_LOG_INFO, "__TESSERACT__", "Tesseract-ocr version: %s", myOCR->Version());

    myOCR->Init("/storage/emulated/0/DCIM/ImageProcessing/", "eng");
    __android_log_print(ANDROID_LOG_INFO, "__TESSERACT__", "Tesseract-ocr Init: %s", imPath);
    __android_log_print(ANDROID_LOG_INFO, "__TESSERACT__", "Tesseract-ocr Init: %s", imPath_.c_str());

    // Set Page segmentation mode to PSM_AUTO (3)
    myOCR->SetPageSegMode(tesseract::PSM_AUTO);

    // Open input image using OpenCV
    Mat im_ = imread(imPath, IMREAD_COLOR);

    // Set image data
    myOCR->SetImage(im_.data, im_.cols, im_.rows, 3, (int)im_.step);

    // Run Tesseract OCR on image
    outText = string(myOCR->GetUTF8Text());
    __android_log_print(ANDROID_LOG_INFO, "__TESSERACT__", "Tesseract-ocr OUT: %s", outText.c_str());

    //result = (*env).NewStringUTF(outText.c_str());
    result = (*env).NewStringUTF(myOCR->Version());

    // return result;

    // load the input image and grab the image dimensions
    Mat im = imread(imPath, IMREAD_COLOR);
    Mat orig;
    im.copyTo(im);
    int origH = im.rows;
    int origW = im.cols;

    // set the new width and height and then determine the ratio in change
    // for both the width and height
    int newW, newH;

    int rW = (int)(origW / float(newW));
    int rH = (int)(origH / float(newH));

    // resize the image and grab the new image dimensions
    resize(im, im, Size(newW, newH));
    int H = im.rows;
    int W = im.cols;

    vector<Mat> outs;
    vector<String> layerNames;
    layerNames[0] = "feature_fusion/Conv_7/Sigmoid";
    layerNames[1] = "feature_fusion/concat_3";

    //load the pre-trained EAST text detector
    __android_log_print(ANDROID_LOG_INFO, "%s", "[INFO] loading EAST text detector...");
    Net net = readNet("test");

    // construct a blob from the image and then perform a forward pass of
    // the model to obtain the two output layer sets
    Mat frame, blob;
    blobFromImage(im, blob, 1.0, Size(W, H), Scalar(123.68, 116.78, 103.94), true, false);
    net.setInput(blob);
    net.forward(outs, layerNames);
    Mat scores = outs[0];
    Mat geometry = outs[1];
    d_predictions decode_;
    decode_ = decode_predictions(scores, geometry);

    float nmsThreshold = parser.get<float>("nms");

    NMSBoxes(decode_.rects, decode_.confidences);


    // net.f

}