#!/usr/bin/env bash
RESULT=$(grep -oe "^breadsticks\s[0-9]\+$" $1 | awk '{ SUM += $2 } END { print SUM }')
echo "RESULT: ${RESULT}"