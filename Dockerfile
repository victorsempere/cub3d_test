FROM gcc:10
WORKDIR /data
RUN apt-get update; \
apt-get install -y gdb gdbserver
VOLUME [ "/data" ]
