# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# set(CMAKE_VERBOSE_MAKEFILE on)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
# set(OpenCV_STATIC ON)

# FILE(GLOB_RECURSE cppfiles src/main/cpp/*)

set(libs "${CMAKE_CURRENT_SOURCE_DIR}/src/main/jniLibs")
include_directories(C:\\Users\\malattas\\Documents\\dev\\my-opencv-sdk\\native\\jni\\include)

add_library(libopencv_aruco SHARED IMPORTED)
set_target_properties(libopencv_aruco PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_aruco.so")

add_library(libopencv_bgsegm SHARED IMPORTED)
set_target_properties(libopencv_bgsegm PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_bgsegm.so")

add_library(libopencv_bioinspired SHARED IMPORTED)
set_target_properties(libopencv_bioinspired PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_bioinspired.so")

add_library(libopencv_calib3d SHARED IMPORTED)
set_target_properties(libopencv_calib3d PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_calib3d.so")

add_library(libopencv_ccalib SHARED IMPORTED)
set_target_properties(libopencv_ccalib PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_ccalib.so")

add_library(libopencv_core SHARED IMPORTED)
set_target_properties(libopencv_core PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_core.so")

add_library(libopencv_datasets SHARED IMPORTED)
set_target_properties(libopencv_datasets PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_datasets.so")

add_library(libopencv_dnn SHARED IMPORTED)
set_target_properties(libopencv_dnn PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_dnn.so")

add_library(libopencv_dnn_objdetect SHARED IMPORTED)
set_target_properties(libopencv_dnn_objdetect PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_dnn_objdetect.so")

add_library(libopencv_dpm SHARED IMPORTED)
set_target_properties(libopencv_dpm PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_dpm.so")

add_library(libopencv_face SHARED IMPORTED)
set_target_properties(libopencv_face PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_face.so")

add_library(libopencv_features2d SHARED IMPORTED)
set_target_properties(libopencv_features2d PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_features2d.so")

add_library(libopencv_flann SHARED IMPORTED)
set_target_properties(libopencv_flann PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_flann.so")

add_library(libopencv_fuzzy SHARED IMPORTED)
set_target_properties(libopencv_fuzzy PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_fuzzy.so")

add_library(libopencv_hfs SHARED IMPORTED)
set_target_properties(libopencv_hfs PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_hfs.so")

add_library(libopencv_highgui SHARED IMPORTED)
set_target_properties(libopencv_highgui PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_highgui.so")

add_library(libopencv_img_hash SHARED IMPORTED)
set_target_properties(libopencv_img_hash PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_img_hash.so")

add_library(libopencv_imgcodecs SHARED IMPORTED)
set_target_properties(libopencv_imgcodecs PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_imgcodecs.so")

add_library(libopencv_imgproc SHARED IMPORTED)
set_target_properties(libopencv_imgproc PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_imgproc.so")

add_library(libopencv_java4 SHARED IMPORTED)
set_target_properties(libopencv_java4 PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_java4.so")

add_library(libopencv_line_descriptor SHARED IMPORTED)
set_target_properties(libopencv_line_descriptor PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_line_descriptor.so")

add_library(libopencv_ml SHARED IMPORTED)
set_target_properties(libopencv_ml PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_ml.so")

add_library(libopencv_objdetect SHARED IMPORTED)
set_target_properties(libopencv_objdetect PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_objdetect.so")

add_library(libopencv_optflow SHARED IMPORTED)
set_target_properties(libopencv_optflow PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_optflow.so")

add_library(libopencv_phase_unwrapping SHARED IMPORTED)
set_target_properties(libopencv_phase_unwrapping PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_phase_unwrapping.so")

add_library(libopencv_photo SHARED IMPORTED)
set_target_properties(libopencv_photo PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_photo.so")

add_library(libopencv_plot SHARED IMPORTED)
set_target_properties(libopencv_plot PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_plot.so")

add_library(libopencv_reg SHARED IMPORTED)
set_target_properties(libopencv_reg PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_reg.so")

add_library(libopencv_rgbd SHARED IMPORTED)
set_target_properties(libopencv_rgbd PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_rgbd.so")

add_library(libopencv_saliency SHARED IMPORTED)
set_target_properties(libopencv_saliency PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_saliency.so")

add_library(libopencv_shape SHARED IMPORTED)
set_target_properties(libopencv_shape PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_shape.so")

add_library(libopencv_stereo SHARED IMPORTED)
set_target_properties(libopencv_stereo PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_stereo.so")

add_library(libopencv_stitching SHARED IMPORTED)
set_target_properties(libopencv_stitching PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_stitching.so")

add_library(libopencv_structured_light SHARED IMPORTED)
set_target_properties(libopencv_structured_light PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_structured_light.so")

add_library(libopencv_superres SHARED IMPORTED)
set_target_properties(libopencv_superres PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_superres.so")

add_library(libopencv_surface_matching SHARED IMPORTED)
set_target_properties(libopencv_surface_matching PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_surface_matching.so")

add_library(libopencv_text SHARED IMPORTED)
set_target_properties(libopencv_text PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_text.so")

add_library(libopencv_tracking SHARED IMPORTED)
set_target_properties(libopencv_tracking PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_tracking.so")

add_library(libopencv_video SHARED IMPORTED)
set_target_properties(libopencv_video PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_video.so")

add_library(libopencv_videoio SHARED IMPORTED)
set_target_properties(libopencv_videoio PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_videoio.so")

add_library(libopencv_videostab SHARED IMPORTED)
set_target_properties(libopencv_videostab PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_videostab.so")

add_library(libopencv_xfeatures2d SHARED IMPORTED)
set_target_properties(libopencv_xfeatures2d PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_xfeatures2d.so")

add_library(libopencv_ximgproc SHARED IMPORTED)
set_target_properties(libopencv_ximgproc PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_ximgproc.so")

add_library(libopencv_xobjdetect SHARED IMPORTED)
set_target_properties(libopencv_xobjdetect PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_xobjdetect.so")

add_library(libopencv_xphoto SHARED IMPORTED)
set_target_properties(libopencv_xphoto PROPERTIES IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_xphoto.so")

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -fexceptions -frtti")

# include_directories(C:/Users/malattas/Documents/dev/opencv-3.4.3-android-sdk/sdk/native/jni/include)
# add_library( lib_opencv SHARED IMPORTED )
# set_target_properties(lib_opencv PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_java3.so)

include_directories(C:\\cygwin64\\usr\\local\\include)

add_library( lib_tesseract SHARED IMPORTED )

set_target_properties(lib_tesseract PROPERTIES IMPORTED_LOCATION C:\\Users\\malattas\\Documents\\AndroidProject\\ImageProcessingTools\\tess-two\\libs\\${ANDROID_ABI}\\libc++_shared.so)
set_target_properties(lib_tesseract PROPERTIES IMPORTED_LOCATION C:\\Users\\malattas\\Documents\\AndroidProject\\ImageProcessingTools\\tess-two\\libs\\${ANDROID_ABI}\\libjpgt.so)
set_target_properties(lib_tesseract PROPERTIES IMPORTED_LOCATION C:\\Users\\malattas\\Documents\\AndroidProject\\ImageProcessingTools\\tess-two\\libs\\${ANDROID_ABI}\\liblept.so)
set_target_properties(lib_tesseract PROPERTIES IMPORTED_LOCATION C:\\Users\\malattas\\Documents\\AndroidProject\\ImageProcessingTools\\tess-two\\libs\\${ANDROID_ABI}\\libpngt.so)
set_target_properties(lib_tesseract PROPERTIES IMPORTED_LOCATION C:\\Users\\malattas\\Documents\\AndroidProject\\ImageProcessingTools\\tess-two\\libs\\${ANDROID_ABI}\\libtess.so)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        native-lib

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        src/main/cpp/trackingColor_lib.cpp
        src/main/cpp/textRecognition_lib.cpp
        # ${cppfiles}
        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        native-lib

        # SHAREDlibs
        libopencv_aruco
        libopencv_bgsegm
        libopencv_bioinspired
        libopencv_calib3d
        libopencv_ccalib
        libopencv_core
        libopencv_datasets
        libopencv_dnn
        libopencv_dnn_objdetect
        libopencv_dpm
        libopencv_face
        libopencv_features2d
        libopencv_flann
        libopencv_fuzzy
        libopencv_hfs
        libopencv_highgui
        libopencv_img_hash
        libopencv_imgcodecs
        libopencv_imgproc
        # libopencv_java4
        libopencv_line_descriptor
        libopencv_ml
        libopencv_objdetect
        libopencv_optflow
        libopencv_phase_unwrapping
        libopencv_photo
        libopencv_plot
        libopencv_reg
        libopencv_rgbd
        libopencv_saliency
        libopencv_shape
        libopencv_stereo
        libopencv_stitching
        libopencv_structured_light
        libopencv_superres
        libopencv_surface_matching
        libopencv_text
        libopencv_tracking
        libopencv_video
        libopencv_videoio
        libopencv_videostab
        libopencv_xfeatures2d
        libopencv_ximgproc
        libopencv_xobjdetect
        libopencv_xphoto

        # tesseract
        lib_tesseract

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})