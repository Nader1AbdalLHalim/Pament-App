#pragma once
#include "terminal.h"
#ifndef server_h
#define server_h


typedef unsigned long long int uint64_t;
typedef struct accountsDB
{
	uint64_t PAN[9];
}ST_account_t;

typedef struct balancessDB
{
	uint64_t balance[9];
}ST_balance_t;
typedef enum EN_serverError_t
{
	ACCEPTED, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE
}EN_serverError_t;
int isValidAccount(ST_cardData_t cardData, ST_account_t primary);
int isAmountAvailable(ST_balance_t money, ST_terminalData_t* terminalData, int sign);
//EN_serverError_t saveTransaction(ST_transaction_t *transData);
#endif
