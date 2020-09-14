FROM gcc:10
ARG CUB3D_TEST_PATH=/home/visv/42/tests/cub3d_test/data
RUN apt-get update; \
apt-get install -y gdb gdbserver
RUN mkdir -p ${CUB3D_TEST_PATH};
WORKDIR ${CUB3D_TEST_PATH}
VOLUME [ "${CUB3D_TEST_PATH}" ]
