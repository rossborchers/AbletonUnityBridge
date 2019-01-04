@echo off

cd Modules\Link
mkdir build

cd build 
cmake ..

cmake --build .
pause