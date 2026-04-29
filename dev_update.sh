#!/bin/bash
bear -- clang++ src/*.cpp \
    -std=c++17 \
    -I/usr/local/include \
    -Ithird-party \
    -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 \
    -g -o main 
