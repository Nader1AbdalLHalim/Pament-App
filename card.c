#include "card.h"
EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	printf("please enter card holder name\n");
	int x = 0, n = 0;
	char ch;

	for (x < 25; (ch = getchar()) != '\n'; x++)
	{
		cardData->cardHolderName[n++] = ch;

	}
	if (20 < x && x < 25)
	{
		printf("num of characters = %d , okay\n", x);
		return OK;
	}
	else
	{
		printf("WRONG_NAME\n");
		printf("num of characters = %d\n", x);

		getCardHolderName(cardData);
		return WRONG_NAME;
	}
}
///////////////////////////////////////
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	printf("Please enter card Expiry Date:\t\t(MM/YY)\n");
	int n = 0, y = 0;
	char x;
	while ((x = getchar()) != '\n')
	{
		cardData->cardExpirationDate[y++] = x;
		n++;
	}

	if (n < 6 && cardData->cardExpirationDate[2] == '/')
		return OK;

	else
	{
		getCardExpiryDate(cardData);
		return WRONG_EXP_DATE;
	}

}
/////////////////////////////////
EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	printf("Please enter card's Primary Account Number:\n");
	int x = 0, y = 0, q = 0;
	char n;
	while ((n = getchar()) != '\n')
	{
		q = n - '0';
		if ((n >= 48 && n <= 57) || (n >= 97 && n <= 122) || (n >= 65 && n <= 90))
		{
			cardData->primaryAccountNumber[x++] = q;
			y++;
		}
		else
		{
			printf("only numbers and alphabetic characters allowed\n");
			getCardPAN(cardData);
		}

	}

}