#!/bin/bash

MODULE=$1
echo "====================================="
echo "The current config for DAQ Module: $MODULE"
echo "====================================="
echo "                    "
echo "Printing Config of DAQ $MODULE in the order of :1.rgm 2.rtm_translen 3. hi_res_mode "
echo "4.nacc 5.Event/Sample rate 6.bank_mask 7.clk 8.clkdiv 9.trg "
echo "                    "
ssh root@192.168.0.$MODULE 'PATH=$PATH:/usr/local/bin/ 
get.site 1 <<EOF
rgm
rtm_translen
hi_res_mode
nacc
SIG:sample_count:FREQ
bank_mask
clk
clkdiv
trg
EOF
'
echo "                               "
