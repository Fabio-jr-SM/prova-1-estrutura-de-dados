/*****************************************************************************


Nome: Fábio Júnior Senna Moura


*****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "car.h"


//Funçoes principais requisitadas
void cad_veiculo(veiculos_concessionaria *veic,int tam);
void listarMarca(veiculos_concessionaria *veic,int tam,int variavelControle);
void listarDescValor(veiculos_concessionaria *veic,int tam);
void BuscarNumero(veiculos_concessionaria *veic, int tam,int variavelControle);
void buscarPlaca(veiculos_concessionaria *veic, int tam,int variavelControle);

//função adicional para Verificar e garantir que o numero seja único
int verificarNumero(int numero,int tam,veiculos_concessionaria *veic);

//Funções de ordenação
int selmin(veiculos_concessionaria *veic, int i, int n,int variavelControle);
void selecao(veiculos_concessionaria *veic, int tamanho,int variavelControle);
void quickSort(veiculos_concessionaria *veic, int beg, int end);
int partition(veiculos_concessionaria *veic, int beg, int end);

//Funcoes de pesquisa binaria
int binarySearch(veiculos_concessionaria *veic, int len, int target);
int binarySearchPlaca(veiculos_concessionaria *veic, int len, char placa_busca[8]);
/*****************************************************************************

ALGORITMOS PRINCIPAIS

*****************************************************************************/


void menu(veiculos_concessionaria *veic,int tam){
    int op = 1,variavelControle;
    while(op!=6){
        printf("\n=====Menu de opções=====\n");
        printf("(1) Cadastro Veiculos\n");
        printf("(2) Buscar Veiculo pelo numero\n");
        printf("(3) Buscar Veiculo pela placa\n");
        printf("(4) Listar veiculo pela marca\n");
        printf("(5) Listar veiculo pela ordem decrescente do valor\n");
        printf("(6) Sair\n");
        scanf("%d",&op);

        system("cls");

        switch(op){
            case 1:cad_veiculo(veic,tam);break;
            case 2:BuscarNumero(veic,tam,variavelControle=1);break;
            case 3:buscarPlaca(veic,tam,variavelControle=2);break;
            case 4:listarMarca(veic,tam,variavelControle=0);break;
            case 5:listarDescValor(veic,tam);break;
            case 6:printf("Saindo!!");break;
            default: printf("\nOpção invalida!");
        }
    }
}

void cad_veiculo(veiculos_concessionaria *veic,int tam){
    for(int i=0;i<tam;i++){
        
        do{
            printf("\n\nNome do Carro: ");
            scanf(" %s%*[^\n]",veic[i].nome_veiculo);
            
            if(strlen(veic[i].nome_veiculo) > 20)
                printf("Tente novamente, nome grande!\n");
        }while(strlen(veic[i].nome_veiculo) > 20);
          
        do{
            printf("\nNome da marca: ");
            scanf(" %s%*[^\n]",veic[i].marca_fabricante);
            if(strlen(veic[i].marca_fabricante) > 15)
                printf("Tente novamente, nome grande!\n");
        }while(strlen(veic[i].marca_fabricante) > 15);
        
        
        int numero;
        do {
            printf("\nNumero do veiculo: ");
            scanf("%d", &numero);
            if (numero < 100 || numero > 150)
                printf("Tente novamente no intervalo: (100 - 150)\n");
            else if (verificarNumero(numero, tam, veic))
                printf("Número já existe, tente novamente.\n");
        } while (numero < 100 || numero > 150 || verificarNumero(numero, tam, veic));

        veic[i].numero_veiculo = numero;

        do{
            printf("\nPlaca do veiculo: ");
            scanf(" %s%*[^\n]",veic[i].placa);
            if(strlen(veic[i].placa) > 8)
                printf("Tente novamente, Muitos caracters!\n");
        }while(strlen(veic[i].placa) > 8);
        
        
        printf("\nValor do Veiculo: ");
        scanf("%f",&veic[i].preco_veiculo);

        system("cls");
    }
}

void listarMarca(veiculos_concessionaria *veic,int tam,int variavelControle){
    // Ordena os veículos por marca usando o algoritmo de seleção
    selecao(veic, tam,variavelControle);

    // Imprime os veículos ordenados
    printf("\nVeículos por ordem crescente de marca:\n");
    for (int i = 0; i < tam; i++) {
        printf("Marca: %-15s | Nome: %-20s | Placa %-8s | Preço: %.2f | Numero: %d\n", 
                                            veic[i].marca_fabricante, 
                                            veic[i].nome_veiculo, 
                                            veic[i].placa,
                                            veic[i].preco_veiculo,
                                            veic[i].numero_veiculo);
    }    
}

void listarDescValor(veiculos_concessionaria *veic, int tam) {
    quickSort(veic, 0, tam - 1); 
    printf("\nVeículos por ordem decrescente Preço:\n");
    for (int i = tam - 1; i >= 0; i--) { 
        printf("Preço: %.2f | Marca: %-15s | Nome: %-20s | Placa %-8s | Numero: %d\n", 
                                            veic[i].preco_veiculo, 
                                            veic[i].marca_fabricante, 
                                            veic[i].nome_veiculo,
                                            veic[i].placa,
                                            veic[i].numero_veiculo);
    }
}

void BuscarNumero(veiculos_concessionaria *veic, int tam,int variavelControle){
    int numero_pesquisa;
    selecao(veic,tam,variavelControle);

    printf("Digite o numero para pesquisar: ");
    scanf("%d",&numero_pesquisa);
    int result = binarySearch(veic, tam, numero_pesquisa);
    if(result == -1)
    {  
        printf("O Numero não está presente.");
    }
    else
    {
        printf("===========CARRO ENCONTRADO===========\n");
        printf("Numero: %d | Marca: %-15s | Nome: %-20s | Placa: %-8s | Preço: %.2f\n", 
                                veic[result].numero_veiculo, 
                                veic[result].marca_fabricante, 
                                veic[result].nome_veiculo,
                                veic[result].placa,
                                veic[result].preco_veiculo);
    }
}

void buscarPlaca(veiculos_concessionaria *veic, int tam, int variavelControle){
    char placa_pesquisa[8];
    selecao(veic,tam,variavelControle);

    printf("Digite a placa para pesquisar: ");
    scanf(" %s%*[^\n]",placa_pesquisa);

    int result = binarySearchPlaca(veic, tam, placa_pesquisa);
    if(result == -1)
    {  
        printf("A placa não estã presente.");
    }
    else
    {
        printf("===========CARRO ENCONTRADO===========\n");
        printf("Numero: %d | Marca: %-15s | Nome: %-20s | Placa: %-8s | Preço: %.2f\n", 
                                veic[result].numero_veiculo, 
                                veic[result].marca_fabricante, 
                                veic[result].nome_veiculo,
                                veic[result].placa,
                                veic[result].preco_veiculo);
    }



    
}

/*****************************************************************************

OUTROS ALGORITMOS

*****************************************************************************/

void selecao(veiculos_concessionaria *veic, int tamanho,int variavelControle) {
    int i, k;
    veiculos_concessionaria temp;
    for(i = 0; i < tamanho - 1; i++) {
        k = selmin(veic, i, tamanho, variavelControle);
        temp = veic[i];
        veic[i] = veic[k];
        veic[k] = temp;
    }
}

int selmin(veiculos_concessionaria *veic, int i, int n,int variavelControle) {
    int j, k = i;
    for (j = i + 1; j < n; j++)
        if(variavelControle==0){    
            if (strcmp(veic[k].marca_fabricante, veic[j].marca_fabricante) > 0)
                k = j;
        }else if(variavelControle==1){
            if (veic[k].numero_veiculo > veic[j].numero_veiculo)
                k = j;
        }else if(variavelControle ==2){
            if (strcmp(veic[k].placa, veic[j].placa) > 0)
                k = j;
        }
    return k;
}

void quickSort(veiculos_concessionaria *veic, int beg, int end) {
    int loc;
    if (beg < end) {
        loc = partition(veic, beg, end);
        quickSort(veic, beg, loc - 1);
        quickSort(veic, loc + 1, end);
    }
}

int partition(veiculos_concessionaria *veic, int beg, int end) {
    veiculos_concessionaria temp;

    float pivot = veic[end].preco_veiculo;
    int i = beg - 1;

    for (int j = beg; j < end; j++) {
        if (veic[j].preco_veiculo >= pivot) {
            i++;

            temp = veic[i];
            veic[i] = veic[j];
            veic[j] = temp;

        }
    }

    veiculos_concessionaria temp_final;
    temp_final = veic[i+1];
    veic[i+1] = veic[end];
    veic[end] = temp_final;
    return i + 1;
}

int binarySearch(veiculos_concessionaria *veic, int len, int target){
    int max = (len - 1);
    int min = 0;
    
    int guess;  // this will hold the index of middle elements
    int step = 0;  // to find out in how many steps we completed the search
    
    while(max >= min)
    {
        guess = (max + min) / 2;
        // we made the first guess, incrementing step by 1
        step++;
        
        if(veic[guess].numero_veiculo ==  target)
        {
            printf("Numeros de etapas de pesquisa: %d \n", step);
            return guess;
        }
        else if(veic[guess].numero_veiculo >  target) 
        {
            // target would be in the left half
            max = (guess - 1);
        }
        else
        {
            // target would be in the right half
            min = (guess + 1);
        }
    }
 
    // We reach here when element is not 
    // present in array
    return -1;
}

int binarySearchPlaca(veiculos_concessionaria *veic, int len, char placa_busca[8]){
    int max = (len - 1);
    int min = 0;
    
    int guess;  // this will hold the index of middle elements
    int step = 0;  // to find out in how many steps we completed the search
    
    while(max >= min)
    {
        guess = (max + min) / 2;
        // we made the first guess, incrementing step by 1
        step++;
        
        int comparison_result = strcmp(veic[guess].placa, placa_busca);
        
        if(comparison_result == 0)
        {
            printf("Numeros de etapas de pesquisa: %d \n", step);
            return guess;
        }
        else if(comparison_result > 0) 
        {
            // placa_busca would be in the left half
            max = (guess - 1);
        }
        else
        {
            // placa_busca would be in the right half
            min = (guess + 1);
        }
    }
 
    // We reach here when element is not 
    // present in array
    return -1;
}


int verificarNumero(int numero, int tam, veiculos_concessionaria *veic) {
    for (int i = 0; i < tam; i++) {
        if (numero == veic[i].numero_veiculo)
            return 1;
    }
    return 0;
}

//Função para preencher automaticamente 10 veiculos
veiculos_concessionaria* preenherAutomaticamente(veiculos_concessionaria *veiculos, int tam) {
    
    veiculos[0].numero_veiculo = 100;
    strcpy(veiculos[0].marca_fabricante, "Ferrari");
    strcpy(veiculos[0].nome_veiculo, "Spider");
    strcpy(veiculos[0].placa, "ABC1234");
    veiculos[0].preco_veiculo = 25000.00;

    veiculos[1].numero_veiculo = 101;
    strcpy(veiculos[1].marca_fabricante, "Porsche");
    strcpy(veiculos[1].nome_veiculo, "911");
    strcpy(veiculos[1].placa, "DEF5678");
    veiculos[1].preco_veiculo = 50000.00;

    veiculos[2].numero_veiculo = 102;
    strcpy(veiculos[2].marca_fabricante, "Lamborghini");
    strcpy(veiculos[2].nome_veiculo, "Aventador");
    strcpy(veiculos[2].placa, "GHI2468");
    veiculos[2].preco_veiculo = 75000.00;

    veiculos[3].numero_veiculo = 103;
    strcpy(veiculos[3].marca_fabricante, "Audi");
    strcpy(veiculos[3].nome_veiculo, "R8");
    strcpy(veiculos[3].placa, "JKL1357");
    veiculos[3].preco_veiculo = 30000.00;

    veiculos[4].numero_veiculo = 104;
    strcpy(veiculos[4].marca_fabricante, "BMW");
    strcpy(veiculos[4].nome_veiculo, "M3");
    strcpy(veiculos[4].placa, "MNO8024");
    veiculos[4].preco_veiculo = 40000.00;

    veiculos[5].numero_veiculo = 105;
    strcpy(veiculos[5].marca_fabricante, "Mercedes-Benz");
    strcpy(veiculos[5].nome_veiculo, "SLS AMG");
    strcpy(veiculos[5].placa, "PQR9753");
    veiculos[5].preco_veiculo = 60000.00;

    veiculos[6].numero_veiculo = 106;
    strcpy(veiculos[6].marca_fabricante, "Chevrolet");
    strcpy(veiculos[6].nome_veiculo, "Camaro");
    strcpy(veiculos[6].placa, "STU3698");
    veiculos[6].preco_veiculo = 35000.00;

    veiculos[7].numero_veiculo = 107;
    strcpy(veiculos[7].marca_fabricante, "Ford");
    strcpy(veiculos[7].nome_veiculo, "Mustang");
    strcpy(veiculos[7].placa, "VWX1470");
    veiculos[7].preco_veiculo = 32000.00;

    veiculos[8].numero_veiculo = 109;
    strcpy(veiculos[8].marca_fabricante, "Toyota");
    strcpy(veiculos[8].nome_veiculo, "Supra");
    strcpy(veiculos[8].placa, "YZA2586");
    veiculos[8].preco_veiculo = 28000.00;

    veiculos[9].numero_veiculo = 110;
    strcpy(veiculos[9].marca_fabricante, "Nissan");
    strcpy(veiculos[9].nome_veiculo,"GT-R");
    strcpy(veiculos[9].placa,"BCD91011");
    veiculos[9].preco_veiculo=300000.0;

    return veiculos;
}