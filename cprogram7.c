#include<stdio.h>
#include<sys/statvfs.h>

int main(){
    struct statvfs buffer;
    if(statvfs(".",&buffer)==-1){
        perror("Error\n");
    }else{
        printf("Cada bloque tiene un tamaño de: %ld bytes\n", buffer.f_frsize);
        printf("Hay %ld bloques disponibles de:%ld\n",buffer.f_bavail,buffer.f_blocks);
    }
}
