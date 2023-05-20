#!/bin/bash
sleep 5 &
p=$!
sleep 1 &
wait $p
echo "first"
wait $!
echo "second"
