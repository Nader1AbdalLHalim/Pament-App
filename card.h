#pragma once
#ifndef card_h
#define card_h

#include <stdio.h>


typedef unsigned char uint8_t;
typedef unsigned long long int uint64_t;
typedef struct card_data
{
	uint8_t cardHolderName[25];
	uint8_t primaryAccountNumber[9];
	uint8_t cardExpirationDate[6];
} ST_cardData_t; //new data type

typedef enum cardeError
{
	OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}  EN_cardError_t;//new data type

EN_cardError_t getCardHolderName(ST_cardData_t* cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);
EN_cardError_t getCardPAN(ST_cardData_t* cardData);
#endif