//reloj_mejoradoqoiwuehoasiucgioauysgd

#include <stdio.h>
#include <stdlib.h>


//                  Reloj.h
typedef struct{
    int horas;
    int minutos;
    int segundos;
}Reloj;


//                  Reloj.c
void Reloj_Imprime(const Reloj* this){
    printf( "%02d:%02d:%02d\n", this->horas, this->minutos, this->segundos );
}

void Reloj_Poner(Reloj* this, int horas, int minutos, int segundos){
    this->horas=horas;
    this->minutos=minutos;
    this->segundos=segundos;
}

void Reloj_Incrementar(Reloj* this){
    ++this->segundos;
    if (this->segundos>59){
        this->segundos=0;
        ++this->minutos;
        if (this->minutos>59){
            this->minutos=0;
            ++this->horas;
            if (this->horas>23){
                this->horas=0;
            }
        }
    }
}
//     
//
//      DUDA 1
//
void Reloj_SetHoras(Reloj* this, int horas){
    this->horas=horas;
}
void Reloj_SetMinutos(Reloj* this, int minutos){
    this->minutos=minutos;
}
void Reloj_SetSegundos(Reloj* this, int segundos){
    this->segundos=segundos;
}


int Reloj_GetHoras(Reloj* this){
    return this->horas;
}
int Reloj_GetMinutos(Reloj* this){
    return this->minutos;
}
int Reloj_GetSegundos(Reloj* this){
    return this->segundos;
}

Reloj* Reloj_New( int horas, int minutos, int segundos ){
    Reloj* p=(Reloj*)malloc(sizeof(Reloj));
    if (NULL==p){
        printf("Error asignando memoria\n");
        exit(1);
    }
    Reloj_Poner(p, horas, minutos, segundos);

    printf("La dirección del objeto creado (en heap) es: %p\n",p);

    return p;
}

void Reloj_Delete( Reloj** this ){

    printf( "&this=%p, this=%p, *this=%p\n", &this, this, *this );
    
    free(*this);
    *this=NULL;

    printf( "&this=%p, this=%p, *this=%p\n", &this, this, *this );
    
}

//                  main.c
int main (){
    Reloj* casio=Reloj_New(8,30,15);
    Reloj* swatch=Reloj_New(11,31,11);
    
    printf("\n");
    printf("La dirección de casio es %p y su valor es %p\n",&casio,casio);
    printf("La dirección de swatch es %p y su valor es %p\n",&swatch,swatch);


    Reloj_Imprime(casio);
    Reloj_Imprime(swatch);

    for(size_t i=0;i<3600;++i){
        Reloj_Incrementar(casio);
    }
    
    printf("La hora de casio es: %d\n",Reloj_GetHoras(casio));


    Reloj_Delete(&casio);
    Reloj_Delete(&swatch);
}