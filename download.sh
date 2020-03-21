#!/usr/bin/env bash

REMOTE_IP="142.93.124.58"
DIR="breadsticks_test_files"
BENCHMARK_FILE="randoms-1M.txt"
# export for child processes to get path dynamically
export BENCHMARK_FILE_PATH="${DIR}/${BENCHMARK_FILE}"

[ -d $DIR ] || echo "${DIR} doesnt exist. Creating..." && mkdir $DIR

[ -f "$BENCHMARK_FILE_PATH" ] || echo "${BENCHMARK_FILE_PATH} doesnt exist. Downloading..." && wget -O "$BENCHMARK_FILE_PATH" "http://${REMOTE_IP}/${BENCHMARK_FILE}"
