#!/bin/bash
SERVER_RUNNING=`ps -axww | grep "slimserver\.pl\|slimserver" | grep -v grep | cat`
if [ z"$SERVER_RUNNING" != z ] ; then
	kill `echo $SERVER_RUNNING | sed -n 's/^[ ]*\([0-9]*\)[ ]*.*$/\1/p'`
fi