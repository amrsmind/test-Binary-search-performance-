# test-Binary-search-performance-
measure the average of binary search algorithm in terms of the number of comparisons it does to find a word.

loadData (....) // Loads required num of words from
file

int binarySearch (....) // Looks for a given item in the data
& return its index or -1

int testPerformance (..) // Gets the time & num of
comparisons

.......................................

First when the word is found. For this case, pick a random
word (use random function C++ to pick an index between 0
and last index) and then search for it in the data.

Do this 100 times and calculate the average time and average
number of comparison.

Second, makeup a random non-existing word and search for it
and calculate the time and number of comparisons done until
algorithm returns that word is not found.

Do this 100 times and calculate the average time and average
number of comparison.

Repeat the previous step using a file of 10000, 20000, 30000, ....,
80000 words and draw the results on a plot using excel or any
drawing tool.
