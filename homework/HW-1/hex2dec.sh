#!/bin/bash

# This takes a while to execute, so
# the assignment didn't ask for 
# the instruction fetches. If need be
# you can uncomment them out and run the program
# but be warned about the execution timing. 

RESULTS_DIR=results

READ_DATA_SPICE_DEC=./$RESULTS_DIR/read-data-spice-dec.txt
READ_DATA_TEX_DEC=./$RESULTS_DIR/read-data-tex-dec.txt
WRITE_DATA_SPICE_DEC=./$RESULTS_DIR/write-data-spice-dec.txt
WRITE_DATA_TEX_DEC=./$RESULTS_DIR/write-data-tex-dec.txt
IF_DATA_SPICE_DEC=./$RESULTS_DIR/instruction-fetch-spice-dec.txt
IF_DATA_TEX_DEC=./$RESULTS_DIR/instruction-fetch-tex-dec.txt 

for line in `cat ./temp/read-spice-temp.txt`; do 
    READ_SPICE=$(bc <<< "ibase=16; $(tr '[:lower:]' '[:upper:]' <<< "${line}")")
    echo $READ_SPICE >> $READ_DATA_SPICE_DEC
done 

for line in `cat ./temp/write-spice-temp.txt`; do 
    WRITE_SPICE=$(bc <<< "ibase=16; $(tr '[:lower:]' '[:upper:]' <<< "${line}")")
    echo $WRITE_SPICE >> $WRITE_DATA_SPICE_DEC
done 

for line in `cat ./temp/if-spice-temp.txt`; do 
    IF_SPICE=$(bc <<< "ibase=16; $(tr '[:lower:]' '[:upper:]' <<< "${line}")")
    echo $IF_SPICE >> $IF_DATA_SPICE_DEC
done 

for line in `cat ./temp/read-tex-temp.txt`; do 
    READ_TEX=$(bc <<< "ibase=16; $(tr '[:lower:]' '[:upper:]' <<< "${line}")")
    echo $READ_TEX >> $READ_DATA_TEX_DEC
done 

for line in `cat ./temp/read-tex-temp.txt`; do 
    WRITE_TEX=$(bc <<< "ibase=16; $(tr '[:lower:]' '[:upper:]' <<< "${line}")")
    echo $WRITE_TEX >> $WRITE_DATA_TEX_DEC
done 

for line in `cat ./temp/if-tex-temp.txt`; do 
    IF_TEX=$(bc <<< "ibase=16; $(tr '[:lower:]' '[:upper:]' <<< "${line}")")
    echo $IF_TEX >> $IF_DATA_TEX_DEC
done 

