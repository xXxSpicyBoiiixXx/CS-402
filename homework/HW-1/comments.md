# Homework 1 Comments 

## Md Ali 
## CS 402 
## 09/11/2022

### Note

Please take note that all comments for homework 1 are included in this file. 

### Running the program
First run "make clean" to clear up all previous data. Then run "make" to complie the code. From there you can either run "make part1" to have the first part running or "make part2" to have the second part running. 

Currently, I have left it as is with object files since the conversion between hex to binary took a long time. You can see the source code in the bash script of "hex2dec.sh" and that does all the conversion. 


### Part 1 

1a. The historgrams are made with gnuplot. I only ploted a the first 100 since the data is so sparsed. 

Both SPICE data and TeX data can be found in the result folder under the file "complete-data.txt". In addition, each individual section has it's on text files e.g. instruction-fetch, read-data, and write-data. 

1b. In regards to the SPICE data we have the following results: 

Frequency of reads in spice.din: 150699
Frequency of writes in spice.din: 66538
Frequency of instruction fetch in spice.din: 782764

In regards to the TeX data we have the following results: 

Frequency of reads in tex.din: 130655
Frequency of writes in tex.din: 104513
Frequency of instruction fetch in tex.din: 597309

Here we can see that in both trace files the fequency of reads is greater than the frequency of writes, but the instruction fetches needed for the opperations far out weights both of reads and writes. 

### Part 2

1a. There are two programs "int-matrix.c" and "double-matrix.c" you can run them with the "make part2" execution and you will have prompts to input your matrices. From there are execution time outputs in seconds. I have the matrix to be going to 500 by 500 but you can adjust this to be rectangle e.g. 200 by 400; 300 by 100; just make sure that it is compatible for multiplication as it will through an error if you input invalid dimensions. 

Note the cap is due to the segmentation faults on my systems. 

The two systems I will be testing have the following set ups. 


