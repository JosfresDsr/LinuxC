#include<stdio.h>
#include<stdlib.h>

struct numbers{
  int a,b,c;
};

int main(int argc, char const *argv[]) {
  struct numbers numeros={1,2,3},lectura;
  int num=0;
  FILE *Pfile;
  if((Pfile=fopen("program.dat","w+b"))==NULL){
      printf("%s\n","ERROR AL ABRIR" );
      exit(1);
  }


  fwrite(&numeros,sizeof(struct numbers),1,Pfile);
  fclose(Pfile);
  //printf("%i\n%i\n%i\n",numeros.a,numeros.b,numeros.c);
  if((Pfile=fopen("program.dat","r"))==NULL){
      printf("%s\n","ERROR AL LEER" );
      exit(1);
  }
  while (fread(&lectura,sizeof(struct numbers),1,Pfile)) {
    printf("%i\n%i\n%i\n",lectura.a,lectura.b,lectura.c);
  }
  fclose(Pfile);
}
