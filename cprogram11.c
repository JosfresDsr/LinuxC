#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void sighandler(int ignum);
int main(){
    signal(SIGINT,sighandler);
    for(;;){
        printf("Durmiendo...\n");
        sleep(3);
    }
}

void sighandler(int signum){
    printf("Señal obtenida %d, saliendo...\n",signum);
    exit(1)
}
