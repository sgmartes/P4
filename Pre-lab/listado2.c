//arreglo_din_func.c
// ejemplo de creación y uso de los arreglos dinámicos

#include <stdio.h>
//Para printf y scanf

#include <stdlib.h>
//Para malloc y demás

#include <string.h>
//Para memset

int* Crear( size_t tam, int init_val ){
    int* p=(int*)malloc(tam*sizeof(int));
    memset(p, init_val, tam*sizeof(int));
    return p;
}

void Destruir(int* p){
    free(p);
    p=NULL;
}

int main(){
    size_t tam;
    printf("¿Cuántos elementos tenrá el arreglo?\n$ ");
    scanf("%ld", &tam);

    int* arr=Crear(tam,-1);
    if (NULL==arr){
        printf("Error asignando memoria\n");
        exit(1);
    }

    for (size_t i=0;i<tam;++i){
        printf("%ld) %d\n",i,arr[i]);
    }

    Destruir(arr);
}