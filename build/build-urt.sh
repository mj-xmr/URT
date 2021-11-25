#!/bin/bash -e

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

echo "Building URT... have a lot of patience."

export PATH=/usr/lib/ccache:$PATH
export CFLAGS="-O3 -march=native"
export CXXFLAGS=$CFLAGS

cd "$DIR"
make

if [ "$(uname)" == "Darwin" ]; then
	URT_INCLUDE=/opt/local/include/URT
	URT_LIB=/opt/local/lib
else
	URT_INCLUDE=/usr/include/URT
	URT_LIB=/usr/lib
fi

echo "Installing URT to: $URT_INCLUDE & $URT_LIB"

sudo mkdir -p "$URT_INCLUDE"
sudo cp -v ../lib/*.so* "$URT_LIB"
sudo cp -v ../include/*.h* "$URT_INCLUDE"

