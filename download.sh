#!/usr/bin/env bash

REMOTE_IP="142.93.124.58"
BENCHMARK_FILE_DIR=${BENCHMARK_FILE_DIR:-"breadsticks_test_files"}
BENCHMARK_FILE=${BENCHMARK_FILE:-"randoms-1M.txt"}
BENCHMARK_FILE_PATH="${BENCHMARK_FILE_DIR}/${BENCHMARK_FILE}"

[ -d $BENCHMARK_FILE_DIR ] || echo "${BENCHMARK_FILE_DIR} doesnt exist. Creating..." && mkdir $DIR

[ -f "$BENCHMARK_FILE_PATH" ] || echo "${BENCHMARK_FILE_PATH} doesnt exist. Downloading..." && wget -O "$BENCHMARK_FILE_PATH" "http://${REMOTE_IP}/${BENCHMARK_FILE}"
