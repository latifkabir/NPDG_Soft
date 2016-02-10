#!/bin/bash
TXT=$1
echo "                $TXT"
# ssh basestar "echo $TXT | mutt -s \"n3HeAlert\" latifulkabir@uky.edu, -b 8595395240@txt.att.net, -b 8659194107@txt.att.net, -b 8653569698@txt.att.net, -b 8592133978@vmobl.com, -b 8652130704@vtext.com, -b cecoppola@gmail.com"
# ssh basestar "echo $TXT | mutt -s \"n3HeAlert\" latifulkabir@uky.edu, -b 8595395240@txt.att.net"
ssh basestar "echo $TXT | mutt -s \"n3HeAlert\" latifulkabir@uky.edu"

HOUR=$(date "+%k")
if [ $HOUR -lt 8 ]
then
    echo "                 Sent Text Alert"
else
    gnome-terminal --geometry=165x30+0+0 -t "Alert" -e "/home/daq/NPDGamma/Watchdog/bin/screenAlert"
fi

