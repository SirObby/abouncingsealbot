cd ..
mkdir build
cd build
cmake ..
cd ..
cmake --build build
cp ./build/discord-bot ./src/discord-bot
echo Moved: ./build/discord-bot ./src/discord-bot