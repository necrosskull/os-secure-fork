#!/bin/bash
cat /etc/network/interfaces | while read line
do
	echo $line
done
