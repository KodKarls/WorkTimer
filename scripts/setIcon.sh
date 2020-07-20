#!/bin/bash

# Variables
icon="res/icon.rc"

debugPath="bin/debug/.obj"
releasePath="bin/release/.obj"

# Compile resource to .res file
windres ${icon} -O coff -o ${debugPath}/icon.res
windres ${icon} -O coff -o ${releasePath}/icon.res

echo "icon.res was created"