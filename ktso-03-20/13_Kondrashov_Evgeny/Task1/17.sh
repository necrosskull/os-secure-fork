#!/bin/bash
cat /proc/cpuinfo | grep -c processor
#c - это count (количество строк с совпадением) 
#| - вывод команды перед чертой служит вводом команды после черты
