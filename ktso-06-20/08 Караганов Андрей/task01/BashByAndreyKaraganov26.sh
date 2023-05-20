#!/bin/bash

sleep 2 &
PID=$!
sleep 3 &
wait $PID
echo "first RIP"
wait $!
echo "second RIP" 
