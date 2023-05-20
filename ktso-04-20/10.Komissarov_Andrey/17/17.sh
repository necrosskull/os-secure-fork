#!/bin/bash

line=$(grep -m1 ^"cpu cores" /proc/cpuinfo)
echo "${line##*: }"
