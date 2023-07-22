#!/bin/bash

# HP Omen 15, Linux 22.04 Ubuntu
# ARCH x84-64
# product: Intel(R) Core(TM) i7-10750H CPU @ 2.60GHz

# GeForce RTX 2070, 7.5

# Thu Jul 20 22:50:06 2023       
# +---------------------------------------------------------------------------------------+
# | NVIDIA-SMI 535.54.03              Driver Version: 535.54.03    CUDA Version: 12.2     |
# |-----------------------------------------+----------------------+----------------------+
# | GPU  Name                 Persistence-M | Bus-Id        Disp.A | Volatile Uncorr. ECC |
# | Fan  Temp   Perf          Pwr:Usage/Cap |         Memory-Usage | GPU-Util  Compute M. |
# |                                         |                      |               MIG M. |
# |=========================================+======================+======================|
# |   0  NVIDIA GeForce RTX 2070 ...    On  | 00000000:01:00.0 Off |                  N/A |
# | N/A   39C    P0              16W /  80W |      6MiB /  8192MiB |      0%      Default |
# |                                         |                      |                  N/A |
# +-----------------------------------------+----------------------+----------------------+
                                                                                         
# +---------------------------------------------------------------------------------------+
# | Processes:                                                                            |
# |  GPU   GI   CI        PID   Type   Process name                            GPU Memory |
# |        ID   ID                                                             Usage      |
# |=======================================================================================|
# |    0   N/A  N/A      1954      G   /usr/lib/xorg/Xorg                            4MiB |
# +---------------------------------------------------------------------------------------+




# dependencies and libraries
cd 

#sudo apt install cmake pkg-config unzip yasm git checkinstall libjpeg-dev libpng-dev libtiff-dev libavcodec-dev libavformat-dev libswscale-dev libavresample-dev libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libxvidcore-dev x264 libx264-dev libfaac-dev libmp3lame-dev libtheora-dev libfaac-dev libmp3lame-dev libvorbis-dev libopencore-amrnb-dev libopencore-amrwb-dev
sudo apt install cmake pkg-config unzip yasm git checkinstall libjpeg-dev libpng-dev libtiff-dev libavcodec-dev libavformat-dev libswscale-dev libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libxvidcore-dev x264 libx264-dev libfaac-dev libmp3lame-dev libtheora-dev libfaac-dev libmp3lame-dev libvorbis-dev libopencore-amrnb-dev libopencore-amrwb-dev
if [ $? -eq 0 ]; then
    echo OK
else
    echo FAIL
    exit 0
fi

#sudo apt-get install libdc1394-22 libdc1394-22-dev libxine2-dev libv4l-dev v4l-utils
sudo apt-get install libxine2-dev libv4l-dev v4l-utils
if [ $? -eq 0 ]; then
    echo OK
else
    echo FAIL
    exit 0
fi

cd /usr/include/linux
sudo ln -s -f ../libv4l1-videodev.h videodev.h
if [ $? -eq 0 ]; then
    echo OK
else
    echo FAIL
    exit 0
fi
cd ~

sudo apt-get install libgtk-3-dev libtbb-dev libatlas-base-dev gfortran
if [ $? -eq 0 ]; then
    echo OK
else
    echo FAIL
    exit 0
fi

sudo apt-get install python3.6
if [ $? -eq 0 ]; then
    echo OK
else
    echo FAIL
    exit 0
fi



# Installing OpenCV 
cd ~/Downloads
rm -r -f opencv.zip
rm -r -f  opencv-4.8.0/
wget -O opencv.zip https://github.com/opencv/opencv/archive/refs/tags/4.8.0.zip
if [ $? -eq 0 ]; then
    echo OK
else
    echo FAIL
    exit 0
fi

rm -r -f opencv_contrib-4.8.0
rm -r -f opencv_contrib.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/refs/tags/4.8.0.zip
if [ $? -eq 0 ]; then
    echo OK
else
    echo FAIL
    exit 0
fi

unzip opencv.zip
unzip opencv_contrib.zip


cd opencv-4.8.0
if [ $? -eq 0 ]; then
    echo OK
else
    echo FAIL
    exit 0
fi

mkdir build
cd build

cmake -D CMAKE_BUILD_TYPE=RELEASE \
-D CMAKE_INSTALL_PREFIX=/usr/local \
-D WITH_TBB=ON \
-D ENABLE_FAST_MATH=1 \
-D CUDA_FAST_MATH=1 \
-D WITH_CUBLAS=1 \
-D WITH_CUDA=ON \
-D BUILD_opencv_cudacodec=OFF \
-D WITH_CUDNN=OFF \
-D OPENCV_DNN_CUDA=OFF \
-D CUDA_ARCH_BIN=7.5 \
-D WITH_V4L=ON \
-D WITH_QT=OFF \
-D WITH_OPENGL=ON \
-D WITH_GSTREAMER=ON \
-D OPENCV_GENERATE_PKGCONFIG=ON \
-D OPENCV_PC_FILE_NAME=opencv.pc \
-D OPENCV_ENABLE_NONFREE=ON \
-D OPENCV_PYTHON3_INSTALL_PATH=~/.virtualenvs/cv/lib/python3.8/site-packages \
-D PYTHON_EXECUTABLE=~/.virtualenvs/cv/bin/python \
-D OPENCV_EXTRA_MODULES_PATH=~/Downloads/opencv_contrib-4.8.0/modules \
-D INSTALL_PYTHON_EXAMPLES=OFF \
-D INSTALL_C_EXAMPLES=OFF \
-D BUILD_EXAMPLES=OFF ..

echo "INFO ____________________________"
echo "Number of Cores"
nproc # to know how much cores do you have
make -j8 #where x is the number of cores, if not sure use -j4
sudo make install

# Attmepts to sort out linking so CMake can find CUDA
sudo /bin/bash -c 'echo "/usr/local/lib" >> /etc/ld.so.conf.d/opencv.conf'
sudo ldconfig
sudo ln -s /usr/local/cuda-12.2 /usr/local/cuda