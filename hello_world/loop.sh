#!/bin/sh
i=1
while true :
do
       	echo $i \>\> /foo
	i=$(($i+1))
       	sleep 1
done
