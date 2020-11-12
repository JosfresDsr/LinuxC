 
#include<stdio.h>
#include<stdlib.h>

int main(){
    int* puntero=0;
    int num=10,sum=0;
    printf("Se alojaran %d elementos en la memoria\n",num);
    //puntero=(int*)malloc(num*sizeof(int));
    puntero=(int*)calloc(num,sizeof(int));
    if(puntero==NULL){
        printf("El alojo de memoria ha fallado\n");
        exit(1);
    }else{
        printf("Memoria alojada correctamente\n");
    }
    
    for(int i=0;i<num;++i){
        puntero[i]=i+1;
        printf("%d\n",puntero[i]);
    }
    
    free(puntero);
    printf("Se ha liberado la memoria contigua\n");
    
    
    
    
}
