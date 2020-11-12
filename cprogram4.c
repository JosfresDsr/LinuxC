#include<stdio.h>
#include<time.h>

void funn(){

    printf("Inicio \n");
    printf("Presione una tecla para salir de la funcion\n");
    while(1){
        if(getchar())
            break;
    }
    printf("Funcion terminada");
}
int main(){
    clock_t t;
    t=clock();
    funn();
    t=clock()-t;
    double tiempo_total=((double)t)/CLOCKS_PER_SEC;
    printf("Tiempo total: %f", tiempo_total);
}
