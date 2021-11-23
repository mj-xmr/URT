#!/bin/bash -e

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

echo "Building... have a lot of patience."

export PATH=/usr/lib/ccache:$PATH
export CFLAGS="-O3 -march=native"
export CXXFLAGS=$CFLAGS

cd "$DIR"
make

URT_INCLUDE=/usr/include/URT
sudo mkdir -p "$URT_INCLUDE"
sudo cp ../lib/*.so* /usr/lib/
sudo cp ../include/*.h* "$URT_INCLUDE"

