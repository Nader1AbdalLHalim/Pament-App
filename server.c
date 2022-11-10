#include"server.h"
#include<stdlib.h>
int isValidAccount(ST_cardData_t cardData, ST_account_t primary)
{
	static int sign;
	uint64_t q = 0;
	////////////////////////   ////////////////////////
	for (int j = 0; j <= 9; j++)
	{
		if (j == 0)
		{
			q += cardData.primaryAccountNumber[j] * 1000000000;
		}
		if (j == 1)
		{
			q += cardData.primaryAccountNumber[j] * 100000000;
		}
		if (j == 2)
		{
			q += cardData.primaryAccountNumber[j] * 10000000;
		}
		if (j == 3)
		{
			q += cardData.primaryAccountNumber[j] * 1000000;
		}

		if (j == 4)
		{
			q += cardData.primaryAccountNumber[j] * 100000;
		}
		if (j == 5)
		{
			q += cardData.primaryAccountNumber[j] * 10000;
		}
		if (j == 6)
		{
			q += cardData.primaryAccountNumber[j] * 1000;
		}
		if (j == 7)
		{
			q += cardData.primaryAccountNumber[j] * 100;

		}
		if (j == 8)
		{
			q += cardData.primaryAccountNumber[j] * 10;
		}
		if (j == 9)
		{
			q += cardData.primaryAccountNumber[j] * 1;
		}

	}
	printf("Q=%d\n", q);
	//////	  ////////////////////   /////////////
	for (int n = 0, i = 0; n <= 9 || i <= 0; n++)
	{
		if (primary.PAN[n] == q)
		{
			i++;
			printf("pan(%d): %d identical to data base\n", n, primary.PAN[n]);

			printf("n=%d\n", n);
			sign = n;

			return sign;
		}
		else if (n == 9 && primary.PAN[n] != q)
		{
			printf("error not found\n");
			n = 10;
			exit(0);
		}
	}


}

int isAmountAvailable(ST_balance_t money, ST_terminalData_t* terminalData, int sign)
{
	float credit = terminalData->transAmount;
	uint64_t remain;
	printf("wanted credit: %lf\n", credit);
	printf("balance[%d] = %i \n", sign, money.balance[sign]);
	if (money.balance[sign] >= credit)
	{
		printf("its done successfully\n");
		remain = money.balance[sign] - credit;
		money.balance[sign] = remain;
		printf("updated balance:%i\n", money.balance[sign]);
	}
	else if (money.balance[sign] < credit)
	{
		printf("low balance\n");
		exit(0);
	}

}