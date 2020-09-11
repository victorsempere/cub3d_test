#!/bin/bash

echo "Lanzando comando Makefile: $MAKEFILE_BUILD_TARGET"
make -C ./src $MAKEFILE_BUILD_TARGET