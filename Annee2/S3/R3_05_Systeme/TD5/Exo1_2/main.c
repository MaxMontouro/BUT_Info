#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/wait.h>
#include <errno.h>
#include <pthread.h>
#include <signal.h>


int main(){
    
    while(1){
        if(signal(SIGINT, SIG_IGN)){
            printf(".\n");
            sleep(1);
        }
    }
    return 0;
}