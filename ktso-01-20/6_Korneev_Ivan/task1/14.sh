#!/bin/bash
function Sum() {
    expr $1 + $2
}

echo -n "Enter First Number: "
read n1
echo -n "Enter Second Number: "
read n2
echo -n "Sum is: "
Sum $n1 $n2
