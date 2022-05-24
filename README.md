# Fermat-vs-Miller-Rabbin-algorithms
In this project I made a comparison between Fermat and Miller Rabin Algorithms for prime numbers to see which one is better
##About
ANALYSIS OF ALGORITHMS COURSE
NOVEMBER 2021
<https://curs.upb.ro/2021/mod/folder/view.php?id=564061>
Student : Trandafir Laura Florina 323CA
#Implementation:

                -algo1.cpp: I implemented the Fermat algorithm;
                -algo1.h: is the header for algo1.cpp where we have
                the signatures of the functions used in algo1.cpp;

                -algo2.cpp: I implemented the Miller-Rabins algorithm;
                -algo2.h: is the header for algo2.cpp where we have
                the signatures of the functions used in algo2.cpp;

"generator" folder:
                -generator1.cpp: is the program that generates the
                input tests using functions like Steve of Erastotene
                to generate prime numbers or random numbers using random()
                function and write them into the destined files. Each file
                contains on the first line the number of numbers it has and then
                the actual sequence;

                -generator2.cpp: is the program I use to generate the output tests.
                 First, I read the numbers from each input test and verify with the
                 function isPrime if the numbers are prime, if they are I add them 
                 into an array of primes. The output files contain on the first line
                 how many prime numbers each test has and then the sequence of primes;

                

"in" folder:
                -contains all the tests generated with generator1.cpp and follow
                the next patterns:
                TESTS 1-6: each test contain 20 random numbers;
                TESTS 7-12: each test contains 50 numbers generated with Sieve
                            of Eratosthene that are for sure primes and between 
                            0-10000
                TESTS 13-18: each test contains 100 numbers 50 primes and 50
                            that are generated randomly and between 
                            10000-100000;
                TESTS 19-24: each test contains 10000 numbers generated randomly
                            but includes corner cases like Charmichaek numbers.
                            The numbers are between 0-1000000;

"out" folder:
                -all the output tests generated with generator_out and 
                contain the numbers that are definitely primes
                and what should the algorithms(algo1.cpp and algo2.cpp) generate;

#MAKEFILE:
                -contains a build rule for the executables;
                -run rules:
                            -run-p1: it runs the first algorithm(Fermat);
                            -run-p2: it runs the second algorithm(Miller-Rabin)
                            -run-best: it runs the best algorithm, in this case Fermat;
                -clean rule;

#RUNTIME:        -using the linux function time, I see that the first algorithm 
                has a smaller run time of "real    0m0,289s", the second algorithm
                has a runtime of "real    0m1,873s"



References:
            Code sequences from:
            <https://www.geeksforgeeks.org/primality-test-set-2-fermet-method/>
		    <https://www.geeksforgeeks.org/primality-test-set-3-miller-rabin/>
            <https://stackoverflow.com/questions/33426414/find-all-carmichael-numbers-in-a-given-interval-a-b-c>
            <https://www.geeksforgeeks.org/sieve-of-eratosthenes/>
            <https://www.geeksforgeeks.org/prime-numbers/>
