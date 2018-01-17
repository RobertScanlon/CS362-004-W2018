#!/bin/bash

r=""
for ((i=1; $i<=128; i++))
do
	r=$(./playdom $i | tail -n 3)
	echo -e "$r"	
done

