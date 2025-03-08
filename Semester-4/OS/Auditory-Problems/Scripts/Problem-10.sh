#!usr/bin/bash

toLower() {
    echo $@ | tr '[A-Z]' '[a-z]'
}

toLower "$@"
