//COEN 146L : Lab2, step 4
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
        if (argc != 2) {  // check correct usage
		fprintf(stderr, "usage: %s <n connections> \n", argv[0]);
		exit(1);
	}
        //Declare and values to n (n connections), np (np parralel connections), RTT0, RTT1, RTT2, RTTHTTP, RTTDNS, ..
        int n = atoi(argv[1]);
        int RTT0 = 3;
        int RTT1 = 20;
        int RTT2 =26;
        int RTTHTTP = 47;
        int RTTDNS = RTT0 + RTT1 + RTT2;


        int sec = RTTDNS + 2 * RTTHTTP;
        printf("One object: %d msec\n", sec);

        int np6 = RTTDNS + 2*RTTHTTP + 2*6*RTTHTTP;
        printf("Non-Persistent 6 objects: %d msec\n", np6);

        //find how many np (parralel connections)
        int np;

        if(n>6.0){
            np= 1;
        }
        else{
            np = 6/n;
        }
        if((n<6) && (6%n != 0))
        {
            np += 1;
        }

        int pers = RTTDNS + 2*RTTHTTP + np*RTTHTTP;
        printf("%d parallel connection - Persistent: %d msec\n",n, pers);
        int nonp = RTTDNS + 2*RTTHTTP + 2*np*RTTHTTP;
        printf("%d parallel connection - Non-Persistent: %d msec\n",n,nonp);

return 0;
}
