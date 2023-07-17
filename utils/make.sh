# Cheep script to compnestate for looking up a build cmd. 
cd /home/alex/synchronisation_buffer
rm -r -f build
mkdir build 
cd build
cmake ..
make 
echo ""
echo ""
echo ""
./synchronisation_buffer