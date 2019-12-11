# ESP32_ROS
1. Install ESP32 

$cd ~/Arduino
$mkdir -p hardware/espressif
$cd hardware/espressif 
$git clone https://github.com/espressif/arduino-esp32.git esp32
$cd esp32 
$git submodule update --init --recursive
$cd tools $python3 get.py

2. Install rosserial_arduino 
$sudo apt-get install ros-kinetic-rosserial-arduino
$sudo apt-get install ros-kinetic-rosserial
$cd <sketchbook>/libraries
$rm -rf ros_lib
$rosrun rosserial_arduino make_libraries.py 

3. Copy files from ESP32_ros_lib_files folder to Home/Arduino/libraries/ros_lib folder
