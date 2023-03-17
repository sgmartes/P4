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

void Product_Ctor(Product* this, int barcode, char* name, float price){
    this->barcode=barcode;
    strncpy(this->name,name,MAX);
    this->price=price;
}

void Product_SetBarcode(Product* this, int barcode){
    this->barcode=barcode;
}
void Product_SetName(Product* this, char* name){
    strncpy(this->name,name,MAX);
}
void Product_SetPrice(Product* this, float price){
    this->price=price;
}

const int Product_GetBarcode(const Product* this){
    return this->barcode;
}
const char* Product_GetName(const Product* this){
    return this->name;
}
const float Product_GetPrice(const Product* this){
    return this->price;
}

void Product_Imprimir(Product* this){
    printf("Información del producto:\n");
    printf("Nombre: %s\nPrecio: %.2f\nC. de barras: %d\n",this->name,this->price,this->barcode);
}

void Product_Assign(Product* this, const Product* other){
    this->barcode=other->barcode;
    strncpy(this->name,other->name,MAX);
    this->price=other->price;
}

bool Product_IsEqual(const Product* this, const Product* other){
    return(this->barcode==other->barcode && strcmp(this->name,other->name)==0 && this->price==other->price);
}

bool Product_IsEqual_ByBarcode(const Product* this, const Product* other){
    return(this->barcode==other->barcode);
}

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
    free(*this);
    *this=NULL;
}

int main(){
    Product* stock[TAM];
    for(size_t i=0;i<TAM;++i){
        stock[i]=Product_New(123,"Caguama",40.50);
    }

    Product_SetBarcode(stock[0],199);
    Product_SetName(stock[1],"Panesito");
    Product_SetPrice(stock[2],31.11);

    for(size_t i=0;i<TAM;++i){
        Product_Imprimir(stock[i]);
    }

    for(size_t i=0;i<TAM;++i){
        Product_Delete(&stock[i]);
    }
}