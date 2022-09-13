# Homework 1 Comments 

## Md Ali 
## CS 402 
## 09/11/2022

### Note

Please take note that all comments for homework 1 are included in this file. 

### Running the program
First run "make clean" to clear up all previous data. Then run "make" to complie the code. From there you can either run "make part1" to have the first part running or "make part2" to have the second part running, to get the "reverse" (switching from population of the matrix from coloumn to row first) you will simply have to type "make part2-r".  

Currently, I have left it as is with object files since the conversion between hex to binary took a long time. You can see the source code in the bash script of "hex2dec.sh" and that does all the conversion. I have also made a separte folder called "dec" for the decimal portions. The "dec" directory can be found in the "results" directory.


### Part 1 

1a. The historgrams are made with gnuplot. I only ploted a the first 1000 since the data is so sparsed. 

In terms of the histogram plots, it seems that there is an access pattern for each of these. For instance the instruction fetch for SPICE seems to have a sawtooth like structure while the instruction fetch for TeX has more of a binary box like pattern. In regards to SPICE read data graph there seems to specific bursts of reading data while the TeX read data pattern is again a binary like strcuture. Lastly, there is sortof a pattern of a binary structure in SPICE for the write data but tators off, bear in mind we only plotted the first 1000 data points for this specfic graph so it might be different if we plotted more but the write data historgram for TeX seems to have the same binary strucutre.  

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

1a. There are two programs "int-matrix.c" and "double-matrix.c" you can run them with the "make part2" execution and you will have prompts to input your matrices. From there are execution time outputs in seconds. Make sure that it is compatible for multiplication as it will through an error if you input invalid dimensions. 

The two systems I will be testing have the following set ups. 

1) Manufactuer: Apple
   CPU Type: Apple M1 
   Memory: 16 GB
   OS: macOS Monterey 12.5.1
   Compiler: GCC 

2) Manufactuer: Apple
   CPU Type: 8-Core Intel Core i9
   Memory: 16 GB
   OS: macOS Monterey 12.5.1
   Compiler: GCC

We utilized a 90000 x 10000 and 10000 x 90000 matrix for the calculation. For the M1 we have the following averages in seconds. These can be found in the "data" folder where we ran each of these caluclation five times and where the table is shown in each case depending on forward/reverse, chip type, and all the execution times for int or doubles.  

Forward Average Execution Time Int: 12.8016852
Forward Average Execution Time Double: 12.8228194   
Reverse Average Execution Time Int: 12.8276722
Reverse Average Execution Time Double: 12.876672

The same dimensions was used for the Intel i9 mac and can also be found in the same folder. 

Forward Average Execution Time Int: 8.3307206
Forward Average Execution Time Double: 8.354398
Reverse Average Execution Time Int: 8.3298408
Reverse Average Execution Time Double: 8.382781

The performance is not the same for the two systems, this is due to some overhead as well as I think hyperthreading is enable on the i9. In addition, the new M1 chip is still a bit experimental which might hinder the perfromance ratio. We can also see here with the averages that we indeed get that the doubles are slightly slower than the random integers but not too much of a noticeable comparison. What is noticeable is the time between the intel i9 and M1 chip since everything else has stayed consistent hardware wise. 

For the intel we have the cpufrequency to be 2.4 GHz which is far lower than we have. 
This seems true from the M1 side as well, but the CPU average frequency seems to be sitting in idle, possible due to possibly the arm architecture. 

Based on cost effectiveness, I would suggest the i9 but it has been known to have a heat throttle and consume resources at the cost of execution time. The real winner is the m1 mac as it utilizes very little resources and although slower, the price point and the computation power you manage to squeeze out far out weights intel's chip. Granted this i9 chip came out 2 years before Apple's M1 chip was annouced. 



  

