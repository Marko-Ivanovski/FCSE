#!/usr.bin/bash

for file in $*; do
    if [ -f "$file" ]; then
        echo "=========== $file ==========="
        cat -n "$file"
    else
        echo "The file $file does not exist."
    fi
done
