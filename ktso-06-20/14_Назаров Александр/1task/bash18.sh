 	#!/bin/bash
	
	exec 2> /dev/null
	
	line=$(ls $1)
	if [ -z "$line" ]
	then
	echo -n
	else
	echo "$1 exists"
	fi
