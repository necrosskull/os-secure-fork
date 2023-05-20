#!/bin/bash
sleep 5 &
p=$!
sleep 1 &
wait $p
echo "first RIP"
wait $!
echo "second RIP"
