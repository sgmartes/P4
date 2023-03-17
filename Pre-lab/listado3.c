// objetos_din.c
// ejemplo de creación y uso de objetos dinámicos
//
// Instrucción de compilación
// gcc -Wall -std=c99 -o objetos_din.out objetos_din.c -lm

#include <stdio.h>
// para printf, scanf

#include <stdlib.h>
// para malloc and friends

#include <math.h>
// para las funciones trigonométricas

double* Crear(){
    double* p = (double*) malloc( sizeof( double ) );
    return p;
}

void Destruir( double* p ){
    free( p );
}

int main(){
    double* p = Crear();
    if( NULL == p ){
        printf( "Error asignando memoria\n" );
        exit( 1 );
    }

    double* q = Crear();
    double* r = Crear();
    // deberíamos verificar también que q y r no hayan devuelto NULL
    printf( "Ingrese el ángulo en radianes:\n$ ");
    scanf( "%lf", p );
    
    *q = sin( *p );
    
    *r = cos( *p );
    printf( "Ángulo\tSeno\tCoseno\n" );
    printf( "%.4lf\t%.4lf\t%.4lf\n", *p, *q, *r );
    Destruir( p );
    
    Destruir( q );
    Destruir( r );
}