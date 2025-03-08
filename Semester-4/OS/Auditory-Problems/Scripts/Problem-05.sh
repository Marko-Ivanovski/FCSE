#!/usr/bin/bash

FILETYPE=$(file "$1")

case "FILETYPE" in
    "$1: Zip archive"*) unzip "$1";;
    "$1: gzip compressed"*) gunzip "$1";;
    "$1: bzip2 compressed"*) bunzip2 "$1";;
    *) echo "The file $1 is an invalid file type.";;
    exit 1
esac
