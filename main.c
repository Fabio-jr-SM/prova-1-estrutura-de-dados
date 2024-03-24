/*****************************************************************************


Nome: Fábio Júnior Senna Moura


*****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "car.h"

int main() 
{
    int tam,op_main;

    veiculos_concessionaria *veiculos;

    //Menu para o usuario escolher o modo de preenchimento
    printf("Escolha:\n(1) Preencher Automaticamente (10 Carros)\n(2) Preencer Manualmente\n");
    scanf("%d",&op_main);
    system("cls");

    //verificando opção escolhida
    if (op_main == 1){
        tam = 10;
        veiculos = malloc(tam*sizeof(veiculos_concessionaria));
        veiculos = preenherAutomaticamente(veiculos,tam);

    }else if (op_main == 2){
        printf("Digite a quantidade de carros: ");
        scanf("%d",&tam);
        veiculos = malloc(tam*sizeof(veiculos_concessionaria));
    }

    menu(veiculos,tam);

    free(veiculos);
    return 0;
}