#!/bin/bash
g++ mbx_daemon.cpp -o mbx_daemon -lrllib
make clean && qmake pvdp.pro && make
make clean && qmake pvs.pro && make

