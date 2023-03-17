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

int PedirInfo(Reloj* this, size_t n){
    int indice_reloj=0,hora,minutos,segundos;
    printf("Introduzca el reloj que desea modificar (1-%ld)\n$ ",n);
    scanf("%d",&indice_reloj);

    printf("Introduzca las horas\n$ ",n);
    scanf("%d",&hora);
    Reloj_SetHoras(&this[indice_reloj-1],hora);

    printf("Introduzca los minutos\n$ ",n);
    scanf("%d",&minutos);
    Reloj_SetMinutos(&this[indice_reloj-1],minutos);

    printf("Introduzca los segundos\n$ ",n);
    scanf("%d",&segundos);
    Reloj_SetSegundos(&this[indice_reloj-1],segundos);

    return indice_reloj;
}


Reloj* Crear(size_t tam){
    Reloj* r=(Reloj*)calloc(tam,sizeof(Reloj));
    if( NULL == r ){
        printf( "Error asignando memoria\n" );
        exit( 1 );
    }

    printf("La dirección de r (en stack) es: %p\n",&r);
    printf("La dirección del arreglo (en heap) es: %p\n",r);

    return r;
}

void Destruir(Reloj** p){

    printf( "&p=%p, p=%p, *p=%p\n", &p, p, *p );

    free(*p);
    *p=NULL;

    printf( "&p=%p, p=%p, *p=%p\n", &p, p, *p );

}



//                  main.c
int main (){
    size_t n=5;
    Reloj* relojes=Crear(n);
    printf("La dirección del arreglo relojes (&relojes[0]) es: %p\n",relojes);
    for(size_t i=0;i<n;++i){
        Reloj_Poner(&relojes[i],16,52,30);
    }
    for(size_t i=0;i<n;++i){
        Reloj_Imprime(&relojes[i]);
    }

    int indice=PedirInfo(relojes,n);
    
    printf("Se modificó el reloj %d\n",indice);
    printf("%02d:%02d:%02d\n",Reloj_GetHoras(&relojes[indice-1]),Reloj_GetMinutos(&relojes[indice-1]),Reloj_GetSegundos(&relojes[indice-1]));

    Destruir(&relojes);
}