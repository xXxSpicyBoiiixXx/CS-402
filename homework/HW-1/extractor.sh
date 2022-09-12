#!/bin/bash 

SPICE="spice.din"
TEX="tex.din"
RESULTS_DIR=results
TEMP=temp

READ_DATA_SPICE=./$RESULTS_DIR/read-data-spice.txt 
READ_DATA_TEX=./$RESULTS_DIR/read-data-tex.txt
WRITE_DATA_SPICE=./$RESULTS_DIR/write-data-spice.txt
WRITE_DATA_TEX=./$RESULTS_DIR/write-data-tex.txt
IF_DATA_SPICE=./$RESULTS_DIR/instruction-fetch-spice.txt
IF_DATA_TEX=./$RESULTS_DIR/instruction-fetch-tex.txt 

COMPLETE_DATA=./$RESULTS_DIR/complete-data.txt

awk -F' ' '$1~/^0/' $SPICE > $READ_DATA_SPICE
awk -F' ' '$1~/^1/' $SPICE > $WRITE_DATA_SPICE
awk -F' ' '$1~/^2/' $SPICE > $IF_DATA_SPICE

awk -F' ' '$1~/^0/' $TEX > $READ_DATA_TEX
awk -F' ' '$1~/^1/' $TEX > $WRITE_DATA_TEX
awk -F' ' '$1~/^2/' $TEX > $IF_DATA_TEX

echo >> $COMPLETE_DATA
echo -n "Frequency of reads in $SPICE: " >> $COMPLETE_DATA
wc -l $READ_DATA_SPICE | awk '{ print $1 }' >> $COMPLETE_DATA
echo -n "Frequency of writes in $SPICE: " >> $COMPLETE_DATA
wc -l $WRITE_DATA_SPICE | awk '{ print $1 }' >> $COMPLETE_DATA
echo -n "Frequency of instruction fetch in $SPICE: " >> $COMPLETE_DATA
wc -l $IF_DATA_SPICE | awk '{ print $1 }' >> $COMPLETE_DATA
echo >> $COMPLETE_DATA
echo -n "Frequency of reads in $TEX: " >> $COMPLETE_DATA
wc -l $READ_DATA_TEX | awk '{ print $1 }' >> $COMPLETE_DATA
echo -n "Frequency of writes in $TEX: " >> $COMPLETE_DATA
wc -l $WRITE_DATA_TEX | awk '{ print $1 }' >> $COMPLETE_DATA
echo -n "Frequency of instruction fetch in $TEX: " >> $COMPLETE_DATA
wc -l $IF_DATA_TEX | awk '{ print $1 }' >> $COMPLETE_DATA
echo >> $COMPLETE_DATA

awk '{print $2}' $READ_DATA_SPICE > ./$TEMP/read-spice-temp.txt
awk '{print $2}' $WRITE_DATA_SPICE > ./$TEMP/write-spice-temp.txt
awk '{print $2}' $IF_DATA_SPICE > ./$TEMP/if-spice-temp.txt

awk '{print $2}' $READ_DATA_TEX > ./$TEMP/read-tex-temp.txt
awk '{print $2}' $WRITE_DATA_TEX > ./$TEMP/write-tex-temp.txt
awk '{print $2}' $IF_DATA_TEX > ./$TEMP/if-tex-temp.txt

