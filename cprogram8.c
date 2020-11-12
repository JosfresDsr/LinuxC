#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
    int resultado=mkdir("prueba",0777);
    if(resultado==0){
        printf("Se ha creado el directorio correctamente");
    }else
        printf("A ocurrido un error al crear el directorio");
}
