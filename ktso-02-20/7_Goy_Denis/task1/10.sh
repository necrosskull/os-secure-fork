#1/bin/bash
echo -n "Enter season of year: "
read s
if([[ == winter ]] || [[ == summer ]] || [[ == spring ]]) then
echo "Correct!"
elif ([ == autumn ]]D then
echo "Correct! That's my favorite season!"
else echo "Incorrect!"
fi