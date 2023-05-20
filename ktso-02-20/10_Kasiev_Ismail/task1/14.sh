#!/bin/bash

Sum() {
	echo "Sum is: $(( $1 + $2 ))"
}

echo -n "Enter First Number: "
read n1
echo -n "Enter Second Number: "
read n2

Sum n1 n2
