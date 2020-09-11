#!/bin/bash

./build_app.sh

echo "Starting gdb server : $PORT ./data/bin/$APP_TO_DEBUG"
pwd
ls -la ./bin
gdbserver :$PORT ./bin/$APP_TO_DEBUG
