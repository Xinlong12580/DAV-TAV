#!/bin/bash
d_type=$1
if [[ $d_type != data_module && $d_type != MC_module ]] ; then
	echo "invalid input"
	exit
fi
dir=$(dirname $(readlink -f $BASH_SOURCE))
dir_module=$dir/$d_type
if [ -e $dir_module ] ; then
	echo "rm $dir_module"
	rm $dir_module -rf
fi
mkdir -p $dir_module
cd $dir_module
cmake $dir/"$d_type"_src
make
