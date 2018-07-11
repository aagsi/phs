#!/bin/bash

MAX=11
for ((mcp=0; mcp <= MAX ; mcp++)) ; do
for pix in $(seq 0 1 63)
do

echo $mcp   $pix


./prtdirc -o smallphs_mcp_${mcp}_pix_${pix}_all.root  -s 0 -a 90 -x "opticalphoton" -p "3.18 eV" -e 1000000 -l 3 -h 1 -g 2017 -c 2017 -gsx 67 -gsy 14.7 -gx 85.0 -gz 447 -t1 $mcp -t2 $pix -b 1 -r 98455


done
done
