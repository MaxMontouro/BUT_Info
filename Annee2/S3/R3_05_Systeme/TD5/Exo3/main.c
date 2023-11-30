#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/wait.h>
#include <errno.h>
#include <pthread.h>
#include <signal.h>

void action_loupe();

int main(){
    signal(SIGTSTP, action_loupe);
    while(1){
        
    }
}

void action_loupe(){
        printf("Loupé\n");
        signal(SIGTSTP, SIG_DFL);
}