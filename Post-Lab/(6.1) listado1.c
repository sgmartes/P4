//arreglo_din.c
// ejemplo de creación y uso de los arreglos dinámicos

#include <stdio.h>
//Para printf y scanf

#include <stdlib.h>
//Para malloc y demás

int main(){
    size_t tam=10;
    /*printf( "¿Cuántos elementos tenrá su arreglo?\n$ " );
    scanf( "%ld", &tam );*/

    int* p = (int*) malloc( tam * sizeof(int) );//Asigna memoria

    if ( NULL == p ){
        printf( "Error asignando memoria\n" );
        exit( 1 );
    }

    for( size_t i = 0; i<tam; ++i){//Asigna valores
        p[ i ] = i+1;
    }

    for( size_t i = 0; i<tam; ++i){//Imprime valores
        printf( "%ld) %d\n", i, p[ i ]);
    }

    tam=20;
    p = (int*) realloc(p, tam * sizeof(int) );//Reasigna la memoria con otro tamaño
    for( size_t i = 0; i<tam; ++i){//Imprime valores
        printf( "%ld) %d\n", i, p[ i ]);
    }
    for( size_t i = 0; i<tam; ++i){//Asigna valores
        p[ i ] = i+1;
    }

    tam=5;
    p = (int*) realloc(p, tam * sizeof(int) );//Reasigna la memoria con otro tamaño
    for( size_t i = 0; i<tam; ++i){//Imprime valores
        printf( "%ld) %d\n", i, p[ i ]);
    }

    free( p );
    p=NULL;
}