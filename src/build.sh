cd ..
mkdir build
cd build
cmake ..
cd ..
cmake --build build
cp ./build/bot ./src/bot
echo Moved: ./build/bot ./src/bot