# Homework 1 

The link for the homework is below: 

http://cs.iit.edu/~virgil/cs402/mail.fall2022/hw1.html

### Part 1 

(a) Using trace files, i.e. files that contain addresses issued by some CPU to execute some application(s), draw the histogram of address distribution for each of them. On the x axis of the plot you will have the address as a decimal number. On the y axis you will have the number of occurrences for each particular address. 

Comment based on the histograms, the files to use are: tex.din and spice.din 

The first file contains the trace obtained by executing TeX and the second is SPICE ("Simulation Program with INtegrated Circuit Emphasis") the general-purpose, open-source analog electronic circuit simulator. 

Each line in the file has two fileds: the first filed indicates what kind of operation the CPU performs (read, write, etc.) and hte second file is the address. Here is what the number in the first field means: 

0: read data
1: write data
2: instruction fetch 

The second field is the address being referenced: the address is a hexadecimal byte-address

(b) What is the frequency of writes (5)? What is the frequency of reads (5)? Please comment on these results (5).

(a) Write a program, using your favorite programming language, that multiplies two rectangular matrices -- please no square matrices -- whose elements are randomly generated. You will have two versions of the program, one in which matrix elements are integers and another one where they are real numbers (double)

You will compile and run the programs on two different systems -- most likely one of them will be your own desktop/laptop and the other one a computer in the lab, or otherwise on one of the UNIX computers IIT makes available to its students.

Measure the time it takes each program to complete (2x5) and then compare the performance of the two systems. Since the matrices are randomly generated, you will have to run the program several times, measure the running time and then take the average. Also the running time has to be significantly large (many seconds) to reduce the impact of measuring errors; this means you will have to work with matrices that have at least hundreds of lines and columns.

Is the performance ratio the same as the clock rate ratio of the two systems? Explain. Based on the  retail price of the two systems, which one is more cost effective? 

b) Change your multiplication algorithm and repeat the steps above; for instance, if you used the the naive multiplication algorith with the column in the inner loop, then just use the same algorithm with the row in the inner loop (same scoring as part a).

Make sure your work includes a description of the two systems (manufacturer, CPU type, amount of memory, operating system, etc.) and of the compiler used. Attach the source code, the tables with your time measurements for your work, and a link to your repository such that we can check-out the code, build, and execute. 


