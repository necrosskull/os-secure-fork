#!/bin/bash
read first
read second
function sum() {
echo "sum is $(($first + $second))"
}
sum