#!/usr/bin/env bash

cd /tmp
wget https://sourceforge.net/projects/irrlicht/files/Irrlicht%20SDK/1.8/1.8.4/irrlicht-1.8.4.zip/download
unzip download
cd irrlicht-1.8.4/source/Irrlicht/
make
cd ../..
sudo cp lib/Linux/libIrrlicht.a /usr/lib
sudo cp -r include /usr/include/irr