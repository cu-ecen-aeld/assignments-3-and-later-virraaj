#!/bin/bash
WRITEFILE=$1
WRITESTR=$2
if [ $# -ne 2 ]; then
	echo "Please specify file to be written to, and the string to be written"
	exit 1
fi
if ! [ -f $1 ]; then
	mkdir -p $(dirname $1)
	touch $1
	echo $2 > $1
else
	echo $2 > $1
fi
