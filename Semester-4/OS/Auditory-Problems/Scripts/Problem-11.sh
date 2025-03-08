#!/usr/bin/bash

ALL_FILES=$(ls)

select FILE in $ALL_FILES "Exit Program"; do
    if [ -z "$FILE" ]; then
        continue
    fi
    if [ "$FILE" = "Exit Program" ]; then
        break;
    fi

    if  [ ! -f "$FILE" ]; then
        echo "The file $FILE does not exist."
        continue
    fi
    echo "=========== $FILE ==========="
    cat "$FILE"
done
