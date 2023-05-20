 	#!/bin/bash
	echo "Enter login"
	read login
	echo "Enter password"
	read password
	if [ $login = "aleks" ] && [ $password = "aleks1" ]
	then
	echo "success auth!"
	else
	echo "auth failed!"
	fi
