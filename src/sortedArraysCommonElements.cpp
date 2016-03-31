/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int is_equal(char *,char *);
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	if (A == NULL || B == NULL || ALen <= 0 || BLen <= 0){  //checking for invalid inputs
		return NULL;
	}
	int i, j,k=0,common_size;

	//common_size is the size of the common structre array
	if (ALen <= BLen){
		common_size = ALen;
	}
	else{
		common_size = BLen;
	}

	//common array is for storing structures with common dates
	struct transaction *common = (struct transaction *)malloc(common_size*sizeof(struct transaction));

	for (i = 0; i < ALen; i++){
		for (j = 0; j < BLen; j++){
			if(is_equal(A[i].date, B[j].date)){
				common[k++]=A[i];                      //if two dates are equal then copy the structure two common structure
			}
		}
	}

	//if no common elements
	if (k == 0) 
		return NULL;

	//if common elements
	return common;
}
int is_equal(char *s1, char *s2){
	//returns 1 if two strings i.e, dates are equal,else return 0
	int i, j;
	for (i = 0; s1[i] != '\0'&&s2[i]!='\0'; i++){
		if (s1[i] != s2[i])//if mismatch
			return 0;
	}
	return 1;//two strings are equal
}