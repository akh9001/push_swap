#!/bin/bash

arg=$(ruby -e "puts (1..5).to_a.shuffle.join(' ')" 2> /dev/null)
	echo "_________________________________________"
	echo $arg
	./push_swap $arg > cmd
	./checker_Mac $arg < cmd
	echo "expected[12] calculate :  `wc -l cmd`"