export DIR_TOP=$(dirname $(readlink -f $BASH_SOURCE))
echo $DIR_TOP
export LD_LIBRARY_PATH=$DIR_TOP/data_module/:$LD_LIBRARY_PATH
