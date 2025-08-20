#!/bin/bash

cmake -S /home/water/ws/libunifex -B /home/water/ws/libunifex/build -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang

cmake --build /home/water/ws/libunifex/build -j2
