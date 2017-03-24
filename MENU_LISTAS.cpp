#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

struct Nodo{
    int num;
    Nodo *Siguiente;
};
void init_pila();
void vacia_pila_bool(Nodo *&);
void ins_pila(Nodo *&, int);
void most_pila(Nodo *&, int);
void limpiar_pila(Nodo *&, int &);

int main(){
    int opc,v_menu=1, n;
    char salir;
    Nodo *pila =NULL;

    do{
        printf("\n\t\tMENU LISTAS\n\n");

        printf("\n1. Inicializar Pila");
        printf("\n2. Verificar estado de Pila");
        printf("\n3. Insertar Elementos de Pila");
        printf("\n4. Mostrar Elementos de Pila");
        printf("\n5. Quitar Elementos de Pila");
        printf("\n0. SALIR\n");
        printf("\nOpcion: ");scanf("%d",&opc);

            switch(opc){
            case 0:
                v_menu=0;
                break;
            case 1:
                init_pila();
                break;
            case 2:
                vacia_pila_bool(pila,n);
                break;
            case 3:
                printf("Presiones (0) cuando termine el ingreso de numeros");
                do{
                    printf("\nIngrese un numero: ");
                    scanf("%d",&n);
                    ins_pila(pila, n);
                }while(n!=0);
                break;
            case 4:

                while(pila!=NULL){
                most_pila(pila,n);
                    if(pila!=NULL){
                        printf("%d -> ",n);
                    }else{
                        printf("%d -> FIN",n);
                    }
                }
                break;
            case 5:
                while(pila!=NULL){
                limpiar_pila(pila,n);
                    if(pila!=NULL){
                        printf("%d -> ",n);
                    }else{
                        printf("%d -> FIN",n);
                    }
                }
                break;
        }
        getch();
    }while(v_menu !=0);

    printf("\n\n");
    system("pause");
    return 0;
}

void init_pila(){//FUNCION PARA INICIALIZAR PILA
    Nodo *pila =NULL;
    printf("\nInicializacion realizada correctamente!!\n");
}

void vacia_pila_bool(Nodo *&pila){//FUNCION PARA VALIDAR SI LA PILA ESTA VACIA O NO
    bool validador;

    if(pila==NULL){
        validador=true;
    }else{
        validador=false;
    }

    if(validador==true){
        printf("\nLa Pila esta Vacia.\n");
    }else{
        printf("\nLa Pila no esta Vacia.\n");
    }
}

void ins_pila(Nodo *&pila, int n){//FUNCION PARA INSERTAR VALORES A LA PILA

    Nodo *nuevo_nodo=(Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->num=n;
    nuevo_nodo->Siguiente=pila;
    pila= nuevo_nodo;
}

void most_pila(Nodo *&pila, int n){//FUNCION PARA MOSTRAR LOS VALORES INGRESADOS EN LA PILA
    Nodo *aux=pila;
    n=aux->num;
    pila=aux->Siguiente;
}

void limpiar_pila(Nodo *&pila, int &n){//FUNCION PARA LIMPIAR PILA
    Nodo *aux=pila;
    n=aux->num;
    pila=aux->Siguiente;
    free(aux);
}
