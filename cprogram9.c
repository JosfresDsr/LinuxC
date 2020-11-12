#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>

int main(){
    char nuevo_archivo[]="prueba/nuevo.txt";
    char nuevo_directorio[]="prueba";
    unlink(nuevo_archivo);
    if(rmdir(nuevo_directorio)!=0){
        perror("rmdir() error");
    }else{
        puts("eliminado!");
    }
}
