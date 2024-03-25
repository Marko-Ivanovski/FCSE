#!/usr/bin/bash

if [ "SHELL" = "/bin/bash" ]; then
    echo "You are using BASH."
else
    echo "You are not using BASH, you are using $SHELL."
fi
