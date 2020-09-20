#!/bin/bash

./build_app.sh

echo "Starting gdb server : $PORT $PATH_TO_APP/$APP_TO_DEBUG"
pwd
ls -la ./bin
gdbserver :$PORT $PATH_TO_APP/$APP_TO_DEBUG
