read input

size=${#input}

if [[ $size -gt 0 ]]
then
	echo -n "input is: "
	echo $input
else
	echo "Empty input"
fi