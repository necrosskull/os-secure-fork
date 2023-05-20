#!/bin/bash

# update branch
git pull -r
# add the directory
git add $2.sh && git add $2.png
git commit -m "task_1_$2"
git push origin main

