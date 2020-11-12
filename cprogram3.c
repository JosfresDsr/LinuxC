//-lcrypt in gcc 
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<crypt.h>
#define _XOPEN_SOURCE

int main(){
    const char *const clave="$1$/iSaq7rB$EoUw5jJPPvAPECNaaWzMK/";
    char *resultado;
    int ok;
    resultado = crypt(getpass("Password:"), clave);
    ok=strcmp(resultado,clave)==0;    
    puts(ok ? "Acceso Autorizado":"Acceso Denegado");
    return ok?0:1;
}
