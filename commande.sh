#!/bin/sh
 
export QMAKESPEC=/share/deep_learning/anaconda/mkspecs/linux-g++-64

qmake
make

exit 0;