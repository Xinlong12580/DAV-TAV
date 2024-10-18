#!/bin/bash
d_type=$1
echo $d_type
if [[ $d_type != data_module && $d_type != MC_module ]] ; then
	echo "invalid input"
	exit
fi
dir=$(dirname $(readlink -f $BASH_SOURCE))
dir_module=$dir/$d_type
if [ -e $dir_module ] ; then
	cd $dir_module
	echo "rm $dir_module"
	rm CMakeCache.txt CMakeFiles Makefile cmake_install.cmake libsim_ana.so sim_ana_Dict.cc sim_ana_Dict_rdict.pcm -rf
fi
mkdir -p $dir_module
cd $dir_module
cmake $dir/"$d_type"_src
make
