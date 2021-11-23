#!/bin/bash -e

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

echo "Building... have a lot of patience."

export PATH=/usr/lib/ccache:$PATH
export CFLAGS="-O3 -march=native"
export CXXFLAGS=$CFLAGS

#make -j $PROC || make # Too many resources
make
sudo make install
#cp ../lib/*.so* ${HOME}/devel/lib/tree/lib
#mkdir -p ${URT_INCLUDE}
#cp ../include/*.h* ${URT_INCLUDE}

