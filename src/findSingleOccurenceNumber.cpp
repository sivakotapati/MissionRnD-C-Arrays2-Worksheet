/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#include<stdio.h>
#include<malloc.h>
//void sort(int *, int);
int findSingleOccurenceNumber(int *A, int len) {

	//returns element that occured only once in the array,returns -1 in error cases
	if (A == NULL || len <= 0)
		return -1;
	int i, max;

	//finding max number in the array
	max = A[0];
	for (i = 1; i < len; i++){
		if (A[i]>max){
			max = A[i];
		}
	}

	int *count = (int *)malloc((max+1)*sizeof(int));

	//intitializing count of every number to zero
	for (i = 0; i <= max; i++){
		count[i] = 0;
	}

	//couting no.of times a number present in the Array
	for (i = 0; i <len; i++){
		count[A[i]]++;
	}
	
	//checking if number occured only once in the array
	for (i = 0; i <len; i++){
		if (count[A[i]] == 1)
			return A[i];//returning the number that occured only once
	}
	return -1;
}

