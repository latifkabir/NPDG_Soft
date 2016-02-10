#!/bin/bash

RUN=$1
LAST=$2
while [ $RUN -ne $LAST ]
do
    if [ -f /home/daq/DATA/run-${RUN}data-21 ] && [ -f /home/daq/DATA/run-${RUN}data-30 ]
    then
	scp -p /home/daq/DATA/run-${RUN}data-{21,30} basestar:/mnt/idata08/NPDG_Data/.
    else
	echo "FAILED to Transfer run:${RUN} . Files does NOT exist."
	echo "Failed to transfer run:${RUN}" >> /home/daq/NPDGamma/Watchdog/bin/logfile.txt
    fi
    RUN=`expr $RUN + 1`
done
