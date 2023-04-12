TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -pthread   -ljpeg  -lmicrohttpd  -lwebpmux -lwebp  -lavutil -lavformat -lavcodec -lswscale -lavdevice  -lopencv_stitching -lopencv_alphamat -lopencv_aruco -lopencv_barcode -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_cvv -lopencv_dnn_objdetect -lopencv_dnn_superres -lopencv_dpm -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_hdf -lopencv_hfs -lopencv_img_hash -lopencv_intensity_transform -lopencv_line_descriptor -lopencv_mcc -lopencv_quality -lopencv_rapid -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_shape -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_superres -lopencv_optflow -lopencv_surface_matching -lopencv_tracking -lopencv_highgui -lopencv_datasets -lopencv_text -lopencv_plot -lopencv_ml -lopencv_videostab -lopencv_videoio -lopencv_viz -lopencv_wechat_qrcode -lopencv_ximgproc -lopencv_video -lopencv_xobjdetect -lopencv_objdetect -lopencv_calib3d -lopencv_imgcodecs -lopencv_features2d -lopencv_dnn -lopencv_flann -lopencv_xphoto -lopencv_photo -lopencv_imgproc -lopencv_core  -lpulse -pthread  -lpulse-simple  -lasound  -lfftw3

DEFINES += _THREAD_SAFE _REENTRANT sysconfdir= LOCALEDIR=\\\"\\\"
INCLUDEPATH += /usr/include/p11-kit-1 /usr/include/x86_64-linux-gnu /usr/include/opencv4

DEFINES += HAVE_FFTW3 HAVE_OPENCV HAVE_PULSE HAVE_V4L2 HAVE_WEBP _GNU_SOURCE

SOURCES += \
        src/alg.cpp \
        src/alg_sec.cpp \
        src/conf.cpp \
        src/dbse.cpp \
        src/draw.cpp \
        src/event.cpp \
        src/exif.cpp \
        src/jpegutils.cpp \
        src/libcam.cpp \
        src/logger.cpp \
        src/motion_loop.cpp \
        src/motionplus.cpp \
        src/movie.cpp \
        src/netcam.cpp \
        src/picture.cpp \
        src/rotate.cpp \
        src/sound.cpp \
        src/util.cpp \
        src/video_common.cpp \
        src/video_loopback.cpp \
        src/video_v4l2.cpp \
        src/webu.cpp \
        src/webu_file.cpp \
        src/webu_html.cpp \
        src/webu_json.cpp \
        src/webu_post.cpp \
        src/webu_stream.cpp

HEADERS += \
    src/alg.hpp \
    src/alg_sec.hpp \
    src/conf.hpp \
    src/dbse.hpp \
    src/draw.hpp \
    src/event.hpp \
    src/exif.hpp \
    src/jpegutils.hpp \
    src/libcam.hpp \
    src/logger.hpp \
    src/motion_loop.hpp \
    src/motionplus.hpp \
    src/movie.hpp \
    src/netcam.hpp \
    src/picture.hpp \
    src/rotate.hpp \
    src/sound.hpp \
    src/util.hpp \
    src/video_common.hpp \
    src/video_loopback.hpp \
    src/video_v4l2.hpp \
    src/webu.hpp \
    src/webu_file.hpp \
    src/webu_html.hpp \
    src/webu_json.hpp \
    src/webu_post.hpp \
    src/webu_stream.hpp \
    config.hpp

DISTFILES += \
    doc/motionplus.gif \
    doc/motionplus_build.html \
    doc/motionplus_config.html \
    doc/motionplus_examples.html \
    doc/motionplus_guide.html \
    doc/motionplus_stylesheet.css \
    doc/samplepage.html
