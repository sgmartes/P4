//producto.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 33
#define TAM 3

typedef struct{
    int barcode;
    char name[MAX];
    float price;
}Product;


Product* Product_New( int barcode, char* name, float price ){
    Product* p=(Product*)malloc(sizeof(Product));
    if (NULL==p){
        printf("Error asignando memoria\n");
        exit(1);
    }
    p->barcode=barcode;
    strncpy(p->name,name,MAX);
    p->price=price;
    
    return p;
}

void Product_Delete( Product** this ){
    fprintf( stdout, "Dentro del destructor (antes): El contenido de this es: %p\n", *this );
    free( *this );
    *this = NULL;
    fprintf( stdout, "Dentro del destructor (después): El contenido de this es: %p\n", *this );
}

int main(){
    Product* prod = Product_New( 123, "PROD", 1.0 );
    fprintf( stdout, "Dentro de main (antes): El contenido de prod es: %p\n", prod );
    Product_Delete( &prod );
    fprintf( stdout, "Dentro de main (después): El contenido de prod es: %p\n", prod );
}