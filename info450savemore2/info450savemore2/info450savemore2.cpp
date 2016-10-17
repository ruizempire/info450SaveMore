// info450savemore2.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <cstdio>
#include <string.h>
using namespace std;

class Account_bank {

protected:
	char number_account[100];
	double balance;
	char type[100];

public:
	Account_bank(char Anumber[100], double Abalance);
	void details();
	int deposit(double value);

};

Account_bank::Account_bank(char Anumber[100], double Abalance) {

	strcpy_s(number_account, Anumber);
	balance = Abalance;
}

void Account_bank::details() {

	printf("Number Account is :%s\n", number_account);
	printf("Balance Account :%.2f\n", balance);
	printf("Type Account :%s\n\n", type);
}

int Account_bank::deposit(double value) {
	balance = balance + value;
	return 0;
}

class savings_account : public Account_bank {

public:

	savings_account(char Anumber[100], double Abalance);
	int withdrawal(double value);
	void interest();
};

savings_account::savings_account(char Anumber[100], double Abalance) : Account_bank(Anumber, Abalance) {
	strcpy_s(number_account, Anumber);
	balance = Abalance;
	strcpy_s(type, "Saving Account");
}

int savings_account::withdrawal(double value) {

	if (balance - value - 2.0 < 0) {
		return -1;
	}
	else {
		balance = balance - value;
		return 0;
	}
}

void savings_account::interest() {

	if (balance >= 10000) {
		balance = balance + balance * 0.02;
	}
	else {
		balance = balance + balance * 0.01;
	}
}


class checking_account : public Account_bank {

public:
	checking_account(char Anumber[100], double Abalance);
	int withdrawal(double value);
	int order_checks();
};

checking_account::checking_account(char Anumber[100], double Abalance) : Account_bank(Anumber, Abalance) {
	strcpy_s(number_account, Anumber);
	balance = Abalance;
	strcpy_s(type, "Checking Account");
}

int checking_account::withdrawal(double value) {

	if (balance - value - 5.00 < 0) {
		return -1;
	}
	else {
		if (balance<500) {
			balance = balance - value - 5.00;
		}
		else {
			balance = balance - value;
		}

		return 0;
	}

}

int checking_account::order_checks() {

	if (balance - 15 - 5.00 < 0) {
		return -1;
	}
	else {
		if (balance<500) {
			balance = balance - 15 - 5.00;
		}
		else {
			balance = balance - 15;
		}

		return 0;
	}
}

class certificate_deposit : public Account_bank {
private:
	int date;
public:
	certificate_deposit(char Anumber[100], double Abalance, int Adate);
	int withdrawal(double value);
	void interest();
	void details();
};

certificate_deposit::certificate_deposit(char Anumber[100], double Abalance, int Adate) : Account_bank(Anumber, Abalance) {

	strcpy_s(number_account, Anumber);
	balance = Abalance;
	strcpy_s(type, "Certificate of Deposit");
	date = Adate;

}

int certificate_deposit::withdrawal(double value) {

	if (balance - value - balance*0.10 < 0) {
		return -1;
	}
	else {

		balance = balance - value - balance*0.10;
		return 0;
	}

}

void certificate_deposit::details() {

	printf("Number Account is :%s\n", number_account);
	printf("Balance Account :%.2f\n", balance);
	printf("Type Account :%s\n", type);
	printf("Year term :%d\n\n", date);
}

void certificate_deposit::interest() {
	if (date<5) {
		balance = balance + balance*0.10;
	}
	else {
		balance = balance + balance*0.05;
	}
}

int main(int argc, char** argv) {

	savings_account one("121213555", 10000); // Create a new savings account and deposit $10k
	checking_account two("22221212", 600); // Create a new checking account and deposit $600
	certificate_deposit three("1256776444", 10000, 3); // Create a new CD account with a 3 year term and deposit $10K

	one.details(); // Get and display the attributes for savings account
	two.details(); // Get and display the attributes for checking account
	three.details(); // Get and display the attributes for Certificate of Deposit

	one.interest(); // Calculate monthly interest for the savings account
	three.interest(); // Calculate the monthly interest for the CD account

	one.details(); // Get and display the attributes for savings account
	two.details(); // Get and display the attributes for checking account
	three.details(); // Get and display the attributes for Certificate of Deposit


	two.order_checks(); // Order checks
	two.withdrawal(200); // Withdraw $200 from checking
	one.withdrawal(1000); // Withdraw $1000 from Savings
	three.withdrawal(2000); // Perform an early withdrawal of $2000 from the CD account


	one.details(); // Get and display the attributes for savings account
	two.details(); // Get and display the attributes for checking account
	three.details(); // Get and display the attributes for Certificate of Deposit
	return 0;
}
