#!/bin/bash
echo -n "Enter season of year: "
read s
if([[$s == winter ]] || [[$s == summer ]] || [[$s == spring ]]) then
echo "Correct!"
elif ([ == autumn ]]) then
echo "Correct! That's my favorite season!"
else echo "Incorrect!"
fi