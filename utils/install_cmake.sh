
#!/bin/sh

# Alternative sudo snap install cmake or sudo apt install cmake

# Build from Source
# Ref. https://github.com/Kitware/CMake/tree/master | master | July 16 12:37 2023
# Platform Linux x86_64 | Ubuntu 20.04

# CMake Version 3.27.0 latest version as per devel date.
sudo apt install build-essential libssl-dev

# Install
cd ~/Downloads
wget https://github.com/Kitware/CMake/releases/download/v3.27.0-rc5/cmake-3.27.0-rc5.tar.gz
tar xf cmake-3.27.0-rc5.tar.gz
cd cmake-3.27.0-rc5

./bootstrap 
make 
sudo make install

# Verify 
curl -OL https://github.com/Kitware/CMake/releases/download/v3.27.0-rc5/cmake-3.27.0-rc5-SHA-256.txt
curl -OL https://github.com/Kitware/CMake/releases/download/v3.27.0-rc5/cmake-3.27.0-rc5.tar.gz
sha256sum -c --ignore-missing cmake-3.27.0-rc5-SHA-256.txt

# Other
sudo apt-get update && sudo apt-get install build-essential