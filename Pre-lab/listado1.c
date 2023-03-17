//arreglo_din.c
// ejemplo de creación y uso de los arreglos dinámicos

#include <stdio.h>
//Para printf y scanf

#include <stdlib.h>
//Para malloc y demás

int main(){
    size_t tam;
    printf( "¿Cuántos elementos tenrá su arreglo?\n$ " );
    scanf( "%ld", &tam );

    int* p = (int*) malloc( tam * sizeof(int) );

    if ( NULL == p ){
        printf( "Error asignando memoria\n" );
        exit( 1 );
    }

    for( size_t i = 0; i<tam; ++i){
        p[ i ] = i + 5;
    }

    for( size_t i = 0; i<tam; ++i){
        printf( "%ld) %d\n", i, p[ i ]);
    }

    free( p );
    p=NULL;
}