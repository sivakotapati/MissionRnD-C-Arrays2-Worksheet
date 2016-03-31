/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int is_greater(char *,int,int,int);
void get_yr_month_date(char *,int *,int *,int *);
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
//Return the number of transactions in that statement after a given date.,returns NULL for invalid inputs
	if (Arr == NULL||len<=0)
	return NULL;
	int i;

	int d1, m1, y1;
	get_yr_month_date(date, &d1, &m1, &y1);


	for (i = 0; i < len; i++){
		//checks Arr[i].date is greater than given date

		if (is_greater((Arr[i]).date,d1,m1,y1)){

			//len-i is no.of transactions greater than that date
			return len - i;//if Arr[i].date is greater than given date
		}
	}
	return 0;//if there is no date such that Arr[i].date is greater than given date
}
int is_greater(char *a,int d1,int m1,int y1){

	//returns 1 if date of transaction is greater than given date,else returns 0
	//d1,m1,y1 are given date
	//d2,m2my2 are transaction date
	int d2,m2,y2;
	get_yr_month_date(a,&d2,&m2,&y2);


	//checking whether transaction date is greater than given date
	if (y1<y2) return 1;
	else if (y2<y1) return 0;//if y1 not less than y2 and y2 is not less than y1 
	                         //means y1==y2 so check for months
	else if (m1<m2) return 1;
	else if (m2<m1) return 0;//if m1 not less than m2 and m2 is not less than m1 
	                         //means m1==m2 so check for days
	else if (d1<d2) return 1;
	else if (d2<d1) return 0;//if d1 not less than d2 and d2 is not less than d1 
	                         //means dob1==dob2 so two dates are equal

	else return 0;
}

void get_yr_month_date(char *s,int *dd,int *mm,int *yy){
//getting day,month,year from given date 
	int i;
	*dd = 0; *mm = 0; *yy = 0;
	//getting date
	for (i = 0;i<2; i++){
		*dd = ((*dd)*10)+(s[i] - '0');
	}

	//getting month
	for (i = 3; i < 5; i++){
		*mm = ((*mm) * 10) + (s[i] - '0');
	}

	//getting year
	for (i = 6;s[i]!='\0'; i++){
		*yy = ((*yy) * 10) + (s[i] - '0');
	}
}