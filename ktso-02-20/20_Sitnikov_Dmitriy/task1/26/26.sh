#!/bin/bash
sleep 1 &
a=$!
sleep 3 &
wait $a
echo "1st rip"
wait $!
echo "2nd rip"
