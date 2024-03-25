#!/usr/bin/bash

COUNT=$1

while [ $COUNT -gt 0 ]; do
    echo "Count is: $COUNT"
    COUNT=$((COUNT - 1))
    sleep 1
done
echo "The count has reached zero."
