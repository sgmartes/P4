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
    return p;
}

void Reloj_Delete( Reloj** this ){
    free(*this);
    *this=NULL;
}

//                  main.c
int main (){
    Reloj* casio=Reloj_New(8,30,15);
    Reloj* swatch=Reloj_New(11,31,11);
    
    Reloj_Imprime(casio);
    Reloj_Imprime(swatch);

    int info=0;
    printf("Ingrese las horas de casio\n$ ");
    scanf("%d",&info);
    Reloj_SetHoras(casio,info);
    printf("Ingrese los minutos de casio\n$ ");
    scanf("%d",&info);
    Reloj_SetMinutos(casio,info);
    printf("Ingrese los segundos de casio\n$ ");
    scanf("%d",&info);
    Reloj_SetSegundos(casio,info);

    printf("Ingrese las horas de swatch\n$ ");
    scanf("%d",&info);
    Reloj_SetHoras(swatch,info);
    printf("Ingrese los minutos de swatch\n$ ");
    scanf("%d",&info);
    Reloj_SetMinutos(swatch,info);
    printf("Ingrese los segundos de swatch\n$ ");
    scanf("%d",&info);
    Reloj_SetSegundos(swatch,info);

    printf("Reloj casio:\n");
    printf("%02d:%02d:%02d\n",Reloj_GetHoras(casio),Reloj_GetMinutos(casio),Reloj_GetSegundos(casio));
    printf("Reloj swatch:\n");
    printf("%02d:%02d:%02d\n",Reloj_GetHoras(swatch),Reloj_GetMinutos(swatch),Reloj_GetSegundos(swatch));
    
    Reloj_Delete(&casio);
    Reloj_Delete(&swatch);
}