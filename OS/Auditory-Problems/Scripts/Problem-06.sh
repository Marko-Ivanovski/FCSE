#!/usr/bin/bash

COUNT=0

while [ $COUNT -le 20 ]; do
    echo $COUNT
    COUNT=$((COUNT+1))
done
