#!/bin/bash

echo "We're going to need Superuser privileges for this..."
sudo echo "Got SU privileges.."

mkdir -p temp
cd temp

libraries=()
libraries+=("https://github.com/KhronosGroup/OpenCL-SDK/releases/download/v2022.04.01/OpenCL-SDK-v2022.04.01-Source.tar.gz")
libraries+=("https://nav.dl.sourceforge.net/project/viennacl/1.7.x/ViennaCL-1.7.1.tar.gz")

# Install Boost
echo "Installing Boost"
wget -O lib.tar.gz 'https://boostorg.jfrog.io/artifactory/main/release/1.78.0/source/boost_1_78_0.tar.gz'
tar -xzf lib.tar.gz
folder=$(tar --exclude='*/*' -tvf lib.tar.gz | awk '{print $NF}')
cd $folder
./bootstrap.sh
sudo ./b2 install
cd ..
echo "Installed Boost Successfully"

# Install CUDA
# Code generated here https://developer.nvidia.com/cuda-downloads
echo "Installing CUDA for UBUNTU"
wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu2004/x86_64/cuda-ubuntu2004.pin
sudo mv cuda-ubuntu2004.pin /etc/apt/preferences.d/cuda-repository-pin-600
wget https://developer.download.nvidia.com/compute/cuda/11.6.2/local_installers/cuda-repo-ubuntu2004-11-6-local_11.6.2-510.47.03-1_amd64.deb
sudo dpkg -i cuda-repo-ubuntu2004-11-6-local_11.6.2-510.47.03-1_amd64.deb
sudo apt-key add /var/cuda-repo-ubuntu2004-11-6-local/7fa2af80.pub
sudo apt-get update
sudo apt-get -y install cuda
echo "Installed CUDA Successfully"

# Install X11
echo "Installing X11, CMake and g++"
sudo apt update
sudo apt install -y libx11-dev xorg-dev libudev-dev libglu1-mesa-dev freeglut3-dev mesa-common-dev libopengl-dev libglm-dev cmake g++ doxygen
echo "Installed X11, CMake and g++"

# Install CMake Libraries
for lib in "${libraries[@]}"
do
    wget -O lib.tar.gz $lib
    mkdir -p temp
    tar -xzf lib.tar.gz --directory temp
    cd temp
    folder=$(ls)
    echo "Installing $folder"
    cd *
    mkdir -p build
    cd build
    cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr/local ..
    sudo make all install
    cd ../../../
    rm -rf temp
    echo "Installed $folder Successfully"
done

cd ..
rm -rf temp