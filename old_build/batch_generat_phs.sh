#!/bin/bash

MAX=11
for ((mcp=0; mcp <= MAX ; mcp++)) ; do
for pix in $(seq 0 1 63)
do

echo $mcp $pix


 sbatch genphs $mcp $pix



done
done

