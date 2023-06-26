#!/bin/bash
set -ex
FILESDIR=$1
SEARCHSTR=$2
if [ $# -ne 2 ]; then
	echo "Please specify location of file as argument 1, and string to be searched
	      as argument 2\n"
	exit 1
fi
if ! [ -d $FILESDIR ]; then
	echo "Argument 1 does not represent directory in the system\n"
	exit 1
fi
CMD_TEST="grep  -Ir $SEARCHSTR $FILESDIR"
if $CMD_TEST; then
	X=$(ls $FILESDIR | wc -w)
	Y=$($CMD_TEST | wc -l)
	echo  "The number of files are $X and the number of matching lines are $Y"
fi
