#!/bin/bash
sleep 5 &
Pr1=$!
sleep 1 &
Pr2=$!

wait $Pr1
echo "First RIP."
wait $Pr2
echo "Second RIP."
