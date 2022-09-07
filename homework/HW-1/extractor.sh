#!/bin/bash 

FILE=$0
SPICE="spice.din"
TEX="tex.din"
OUT_SPICE=./frequency-spice.txt
OUT_TEX=./frequency-tex.txt

awk '{print $1}' $SPICE > $OUT_SPICE

#if [$0 = $SPICE];
#then 
#    awk '{print $1}' $FILE > $OUT_SPICE  
#fi

#if [$0 = $TEX];
#then 
#    awk '{print $1}' $FILE > $OUT_TEX
#fi
