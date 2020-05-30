#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {TipoCasa, TipoCelular, tipoPriv} Tipo;
struct Nodo {

    char* puntero;
    char nombre;

};


struct listaNodos {
    void* nodo;
    Tipo tipo;
    struct listaNodos* sig;
} *cabeza;



void* crear_Nodo(char* idpuntero, char nombre )
{
    struct Nodo* elNodo;
    elNodo = (struct Nodo*) malloc(sizeof(struct Nodo));

    elNodo = idpuntero;
    elNodo->puntero = idpuntero;
    elNodo->nombre = nombre;
    return elNodo;

}

void insertarNodo(void* nuevoNodo, Tipo tipox) {
    struct listaNodos *auxnodo = NULL;
    auxnodo = (struct listaNodos *) malloc(sizeof(struct listaNodos));
    auxnodo->nodo = nuevoNodo;
    auxnodo->tipo = tipox;
    auxnodo->sig = NULL;

    if (cabeza == NULL)
    {
        cabeza = auxnodo;
    }else
    {
        auxnodo->sig = cabeza;
        cabeza = auxnodo;
    }
}

int tamLista(){
    struct listaNodos* auxN = cabeza;
    int cont = 0;
    if(cabeza != NULL){
            do {
                cont++;
                auxN = auxN->sig;
            }while (auxN != NULL);

        }
        return cont;

}

void imprimirNoDO(){

    struct listaNodos* auxN = cabeza;
    if (auxN == NULL)
    {
        printf("Vacio en lista ");

    } else
        while (auxN != NULL)
        {
            if (auxN->tipo == 0)
            {
                printf("TELEFONO CASA U OFICINA: %c\n",((struct Nodo*)auxN->nodo)->nombre) ;

            }
            if (auxN->tipo == 1)
            {
                printf("TELEFONO CElULAR: %c\n",((struct Nodo*)auxN->nodo)->nombre) ;

            }
            if (auxN->tipo == 2)
            {
                printf("TELEFONO PRIVADO: %c\n",((struct Nodo*)auxN->nodo)->nombre) ;
            }
        }

}


int main()
{
    char* lamarc = (char*) malloc( 1);
    strcpy(lamarc, "Telefono");
    insertarNodo(crear_Nodo(lamarc, '85857667'), TipoCelular);
    imprimirNoDO();

};


