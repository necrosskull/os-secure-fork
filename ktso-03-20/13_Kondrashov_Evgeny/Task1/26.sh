#!/bin/bash

sleep 1 &
wait
echo "1st rip"
sleep 5 &
wait
echo "2nd rip"
