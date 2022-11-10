#include "terminal.h"
EN_terminalError_t getTransactionDate(ST_terminalData_t* terminalData)
{
    printf("Please enter transaction Date:\t\tDD/MM/YYYY\n");
    int n = 0;
    int y = 0;
    char x;

    while ((x = getchar()) != '\n')
    {
        terminalData->transactionDate[y++] = x;
        n++;
    }
    if ((n == 10 && terminalData->transactionDate[2] == '/') && terminalData->transactionDate[5] == '/') return TERMINAL_OK;

    else  return WRONG_DATE;

}
/////////////////////////////////////////////////////
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t terminalData)
{
    /*  printf("EXPIRY DATE \n");
      for (int e = 0; e <= 5; e++)
      {
          printf("x2=%c , \n", cardData.cardExpirationDate[e]);
      }*/

    printf("TRANSACTION DATE\n");
    for (int r = 0; r < 10; r++)
    {
        printf("y2=%c , \n", terminalData.transactionDate[r]);
    }
    //////////////////////////////  //////////////////
    char* p;
    p = &cardData.cardExpirationDate[3];
    char* q;
    q = &cardData.cardExpirationDate[4];
    char* a;
    a = &terminalData.transactionDate[8];
    char* b;
    b = &terminalData.transactionDate[9];
    char* m;
    m = &cardData.cardExpirationDate[0];
    char* s;
    s = &cardData.cardExpirationDate[1];
    char* d;
    d = &terminalData.transactionDate[3];
    char* e;
    e = &terminalData.transactionDate[4];
    int result1;
    result1 = *p - *a;
    if (result1 <= -1) return EXPIRED_CARD;
    if (result1 >= 1)  return  TERMINAL_OK;
    if (result1 == 0)
    {

        int result2 = *q - *b;
        if (result2 <= -1) return EXPIRED_CARD;
        else if (result2 >= 1)  return   TERMINAL_OK;
        else if (result2 == 0)
        {

            int result3 = *m - *d;
            if (result3 <= -1) return EXPIRED_CARD;
            else if (result3 >= 1)  return  TERMINAL_OK;
            else if (result3 == 0)
            {

                int result4 = *s - *e;
                if (result4 <= -1) return EXPIRED_CARD;
                else if (result4 >= 1) return  TERMINAL_OK;
                else if (result4 == 0) return EXPIRED_CARD;
            }
        }

    }

}
EN_terminalError_t getTransactionAmount(ST_terminalData_t* terminalData)
{
    printf("enter your transaction amount:\n");
    scanf_s("%f", &terminalData->transAmount);
    if ((terminalData->transAmount) > 0)
    {
        return TERMINAL_OK;
    }
    else if ((terminalData->transAmount) <= 0)  return INVALID_AMOUNT;
}
/////////////////////////////////////////////////////////////////////////
EN_terminalError_t setMaxAmount(ST_terminalData_t* terminalData)
{
    printf("enter MAX transaction amount:\n");
    scanf_s("%f", &terminalData->maxTransAmount);
    if (terminalData->maxTransAmount <= 0) return INVALID_AMOUNT;
    else
    {
        return TERMINAL_OK;
    }
}
//////////////////////////////////////////////////////////////////////
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* terminalData)
{
    printf(" transamount:%f\n", terminalData->transAmount);
    printf(" MAx transamount:%f\n", terminalData->maxTransAmount);
    int mizo = terminalData->maxTransAmount - terminalData->transAmount;
    return mizo;

}