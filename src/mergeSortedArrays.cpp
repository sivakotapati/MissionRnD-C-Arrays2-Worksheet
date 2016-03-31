/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int is_lesser(char *, char *);
void get_year_month_date(char *, int *, int *, int *);
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL || ALen <= 0 || BLen <= 0)//checking for invlaid inputs
	{
		return NULL;
	}
	
	//c for storing result of sorting two sorted linked lists
	struct transaction *c = (struct transaction *)malloc((ALen + BLen)*sizeof(struct transaction));

	int i, j,k;
	
	//i is index of A
	//j is index of B
	//k is index of c
	i = 0, j = 0, k = 0;
	while( i < ALen&&j < BLen){

		//check A[i].date or B[j].date is lesser
		int r= is_lesser(A[i].date, B[j].date);
		if (r == 1){
			//if A[i].date is lesser then  copy A[i] to C[k]
			c[k++] = A[i++];
		}
		else if (r == 2){
			//if B[i].date is lesser then copy A[i] to C[k]
			c[k++] = B[j++];
		}
	}

	//if we completed all elements in B then copy A to c
	while (i < ALen){
		c[k++]= A[i];
	}

	//if we completed all elements in A then copy B to c
	while (j < BLen){
		c[k++]= B[j++];
	}

	return c; //returning base address of array which is  sorted 
}
int is_lesser(char *a, char *b){

	//returns 1 if A date is lesser than B date,else returns 0
	//d1,m1,y1 are A date
	//d2,m2my2 are B date
	int d1,d2,m1,m2,y1,y2;
	get_year_month_date(a, &d1, &m1, &y1);
	get_year_month_date(b, &d2, &m2, &y2);

	//checking whether A date is lesser than B date
	if (y1<y2) return 1;
	else if (y2<y1) return 2;//if y1 not less than y2 and y2 is not less than y1 
	                         //means y1==y2 so check for months
	else if (m1<m2) return 1;
	else if (m2<m1) return 2;//if m1 not less than m2 and m2 is not less than m1 
	                        //means m1==m2 so check for days
	else if (d1<d2) return 1;
	else if (d2<d1) return 2;//if d1 not less than d2 and d2 is not less than d1 
	                         //means dob1==dob2 so two dates are equal

	else return 1;
}

void get_year_month_date(char *s, int *dd, int *mm, int *yy){
	//getting day,month,year from given date 
	int i;
	*dd = 0; *mm = 0; *yy = 0;
	//getting date
	for (i = 0; i<2; i++){
		*dd = ((*dd) * 10) + (s[i] - '0');
	}

	//getting month
	for (i = 3; i < 5; i++){
		*mm = ((*mm) * 10) + (s[i] - '0');
	}

	//getting year
	for (i = 6; s[i] != '\0'; i++){
		*yy = ((*yy) * 10) + (s[i] - '0');
	}
}