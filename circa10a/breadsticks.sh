#!/usr/bin/env bash
RESULT=$(awk '/^breadsticks\s[0-9]+$/ { SUM += $2 } END { print SUM }' $1)
echo "RESULT: ${RESULT}"