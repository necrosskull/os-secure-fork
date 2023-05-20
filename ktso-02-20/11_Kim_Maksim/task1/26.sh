#!/bin/bash

echo "First thread wait 5 sec. second wait 10 sec"
date
sleep 5 && echo "First thread" && date &

sleep 10 && echo "Second thread" && date &

wait

