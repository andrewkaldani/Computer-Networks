//COEN 146L : Lab2 - Steps 2 and 3

/*
* Name: Andrew Kaldani
* Date: <date> Wednesdayy
* Title: Lab2 – Step 2 and 3
* Description: implements quantitative comparisons between circuit switching and packet switching.
*/



#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double factorial(double n)
{
    //base case n =0
    if(n==0)
    {
        return 1;
    }
    else
    {
        //recurisive case n * fac( n-1)
        return n * factorial(n-1);
    }
}

int main(int argc, char *argv[]) {
    if (argc !=5){
	fprintf(stderr,"usage: %s <linkBandwidth> <userBandwidth> <tPSusers> <nPSusers> \n", argv[0]);
	exit(0);
    }
   int i, linkBandwidth, userBandwidth, nCSusers, nPSusers;
   double pPSusers, tPSusers, pPSusersBusy, pPSusersNotBusy;

   // Get values from command line
   linkBandwidth = atoi(argv[1]);
   userBandwidth = atoi(argv[2]);
   tPSusers  = atof(argv[3]);
   nPSusers = atoi(argv[4]);

   // 2a: Circuit Switching Senario
   // how many users --> nCSusers
   nCSusers = linkBandwidth/ userBandwidth;
   printf("2a: Circuit switching senario: %d users\n", nCSusers);

   // 3: Packet Switching Senario
   // compute: 3a, b, c, d, e, f, g, h
   pPSusers = tPSusers;
   pPSusersNotBusy = 1 - pPSusers;
   double pAllNotBusy = pow(pPSusersNotBusy,nPSusers-1);
   double pOneBusy = pPSusers * pAllNotBusy;
   double pExactlyOne = nPSusers * pOneBusy;
   double pTenBusy = pow(pPSusers,10) * pow(pPSusersNotBusy,nPSusers-10);
   double pAnyTenBusy = factorial(nPSusers)/(factorial(10) * factorial(nPSusers-10)) * pTenBusy ;
   double pTenMoreBusy =0;
   for(int i = 11; i <= nPSusers; i++){
       pTenMoreBusy +=  (factorial(nPSusers) / (factorial(i) * factorial(nPSusers - i))) * pow(pPSusers, i) * pow(pPSusersNotBusy,(nPSusers-i));
   }


   printf("3: Packet switching senario");
   printf("3a: The probability that a given (specific) user is busy transmitting = %f\n", pPSusers);
   printf("3b: The probability that ine specific other user is not busy =  %f\n", pPSusersNotBusy);
   printf("3c: The probablility that all of the other specific other users are not busy =  %e\n", pAllNotBusy);
   printf("3d: The probability that one specific user is transmitting and the remianing users are not transmitting =  %e\n", pOneBusy);
   printf("3e: The probability that exactly one of the nPSusers users is busy is pPSusers times the probability that a given specific user is transmitting and the remaining users are not transmitting = %le\n", pExactlyOne);
   printf("3f: The probabalitiy that 10 specific users of nPSusers are transmitting and the others are idle = %lg\n", pTenBusy);
   printf("3g: The probability that any 10 users of nPSusers are transmitting and the others are idle = %lg\n", pAnyTenBusy);
   printf("3h: The probability that more than 10 users of nPSusers are transmitting and the others are idle = %lg\n", pTenMoreBusy);
   return 0;
}
