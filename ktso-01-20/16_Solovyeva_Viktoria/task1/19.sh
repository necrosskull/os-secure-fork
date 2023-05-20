#!/bin/bash
touch $1
echo "before removal"
ls
rm $1
echo "after removal"
ls
