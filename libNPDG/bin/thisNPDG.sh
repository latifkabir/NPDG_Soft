NPDGBIN=$(dirname $BASH_ARGV[0])
NPDGROOT=$(cd $NPDGBIN/..;pwd)

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$NPDGROOT/lib
export PATH=$PATH:$NPDGROOT/bin


