 #include<stdio.h>
 #include<conio.h>
 #include<stdlib.h>

 void input();
 void writefile();
 void search();
 void output();

 struct date{
	   int month;
	   int day;
	   int year;
	   };

  struct account {
	int number;
	char name[100];
	int acct_no;
	float mobile_no;
	char street[100];
	char city[100];
	char acct_type;
	float oldbalance;
	float newbalance;
	float payment;
	struct date lastpayment;
  }customer;
  int tl,sl,ts;
 void main()
	{
	  int i,n;
	  char ch;
 //TODO: will be added soon
 }
