#include"app.h"

void appStart(void)
{
	ST_cardData_t cardData;
	ST_terminalData_t terminalData;
	getCardHolderName(&cardData);//call
	getCardExpiryDate(&cardData);//call
	for (int i = 0; i < 5; i++)
	{
		printf("EX date : %c\n", cardData.cardExpirationDate[i]);
	}
	getCardPAN(&cardData);//call
	/////////////////////////////////
	getTransactionDate(&terminalData); //call
	int t;
	t = isCardExpired(cardData, terminalData);  //call
	if (t == EXPIRED_CARD)
	{
		printf("\ncard is expired");
		exit(0);
	}
	else if (t == TERMINAL_OK)
	{
		printf("\ncard is up to date\n\n");
	}

	setMaxAmount(&terminalData); //call

	getTransactionAmount(&terminalData); //call

	int N;

	N = isBelowMaxAmount(&terminalData); //call
	if (N < 0)
	{
		printf(" EXCEED_MAX_AMOUNT\n");
		exit(0);
	}
	else if (N >= 0)
	{
		printf(" TERMINAL_OK\n");

	}
	/////////////SERVER MODULE //////////////////////////////////////
	ST_account_t primary = {
						(1323456787),
							(2045678919),
							(1874563215),
							(1867891232),
							(1948239713),
							(1597536844),
							(1217538529),
							(1068527412),
							(1638527475) };

	ST_balance_t money = {
							(75000)    ,
							(35000)    ,
							(400000)   ,
							(654000)   ,
							(78946)    ,
							(987989)   ,
							(101201101),
							(10685274) ,
							(16385277) };

	isValidAccount(cardData, primary);  //function call 

	isAmountAvailable(money, &terminalData, isValidAccount(cardData, primary));   //function call
}