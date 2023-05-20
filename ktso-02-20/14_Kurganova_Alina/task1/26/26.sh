#!/bin/bash
sleep 5 &
p=$!
sleep 1 &
wait $p
echo "first rip"
wait $!
echo "second rip"


