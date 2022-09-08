#!/bin/bash 

SPICE="spice.din"
TEX="tex.din"
READ_DATA_SPICE=./read-data-spice.txt 
READ_DATA_TEX=./read-data-tex.txt
WRITE_DATA_SPICE=./write-data-spice.txt
WRITE_DATA_TEX=./write-data-tex.txt
IF_DATA_SPICE=./instruction-fetch-spice.txt
IF_DATA_TEX=./instruction-fetch-tex.txt 

awk -F' ' '$1~/^0/' $SPICE > $READ_DATA_SPICE
awk -F' ' '$1~/^1/' $SPICE > $WRITE_DATA_SPICE
awk -F' ' '$1~/^2/' $SPICE > $IF_DATA_SPICE

awk -F' ' '$1~/^0/' $TEX > $READ_DATA_TEX
awk -F' ' '$1~/^1/' $TEX > $WRITE_DATA_TEX
awk -F' ' '$1~/^2/' $TEX > $IF_DATA_TEX

echo 
echo -n "Frequency of reads in $SPICE: " 
wc -l $READ_DATA_SPICE | awk '{ print $1 }'
echo -n "Frequency of writes in $SPICE: "
wc -l $WRITE_DATA_SPICE | awk '{ print $1 }' 
echo -n "Frequency of instruction fetch in $SPICE: "
wc -l $IF_DATA_SPICE | awk '{ print $1 }'
echo 
echo -n "Frequency of reads in $TEX: " 
wc -l $READ_DATA_TEX | awk '{ print $1 }'
echo -n "Frequency of writes in $TEX: "
wc -l $WRITE_DATA_TEX | awk '{ print $1 }' 
echo -n "Frequency of instruction fetch in $TEX: "
wc -l $IF_DATA_TEX | awk '{ print $1 }'
echo
