#!/usr/bin/bash

if [ $# -lt 3 ]; then
    echo "Not enough arguments."
    exit 1
fi

OLD="$1"
NEW="$2"

shift
shift

for file in $*; do
    if [ -f "$file" ]; then
        NEWFILE=$(echo "$file" | sed "s/$OLD/$NEW/g")
        if [ -f "$NEWFILE" ]; then
            echo "The file $NEWFILE already exists."
        else
            mv "$file" "$NEWFILE"
        fi
    fi
done
