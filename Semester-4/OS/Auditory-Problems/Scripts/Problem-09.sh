#!/usr/bin/bash

PRICE=$1
PRICE='echo "scale=2; 3.5 * $PRICE" | bc'
echo "$PRICE"
