/*** CELEBA05

   The following example generates a SIGALRM signal.
   https://www.ibm.com/docs/en/zos/3.1.0?topic=functions-alarm-set-alarm

 ***/
#define _POSIX_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
///https://cppscripts.com/cpp-get-environment-variable

volatile int footprint=0;

void catcher(int signum) {
  //puts("inside signal catcher!");
  fprintf(stdout, "inside signal catcher!");
  footprint = 1;
}

void main(void) {
    const char* path = getenv("PATH");
    const char* dbHost = getenv("DB_HOST");
    const char* dbName = getenv("DB_NAME");
    const char* dbUser = getenv("DB_USER");
    const char* dbPwd = getenv("DB_PWD");
    if (path != NULL) {
        fprintf(stdout, "PATH: %s\n", path);
    } else {  
        fprintf(stderr, "PATH variable not found.");
    }  
    if (dbHost != NULL) {
        fprintf(stdout, "Database Host: %s\n", dbHost);
    } else {  
        fprintf(stderr, "Database Host variable not found.");
        EXIT_FAILURE;
    }  

  struct sigaction sact;
  volatile double count;
  time_t t;

  sigemptyset(&sact.sa_mask);
  sact.sa_flags = 0;
  sact.sa_handler = catcher;
  sigaction(SIGALRM, &sact, NULL);

  alarm(60); /* timer will pop in 60 seconds */

  time(&t);
  fprintf(stdout, "before loop, time is %s", ctime(&t));
  for (count=0; (count<9*1e10) && (footprint == 0); count++);
  time(&t);
  fprintf(stdout, "after loop, time is %s", ctime(&t));

  fprintf(stdout, "the sum so far is %.0f\n", count);

  if (footprint == 0)
    fprintf(stderr, "the signal catcher never gained control");
  else
    fprintf(stdout, "the signal catcher gained control");
}
