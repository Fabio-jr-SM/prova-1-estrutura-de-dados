/*****************************************************************************


Nome: Fábio Júnior Senna Moura


*****************************************************************************/

struct veiculo{
    int numero_veiculo;
    char marca_fabricante[15];
    char nome_veiculo[20];
    char placa[8];
    float preco_veiculo;
};

typedef struct veiculo veiculos_concessionaria;

//menu
void menu(veiculos_concessionaria *veiculos,int tam);

//Preencher com 10 veiculos automaticamente
veiculos_concessionaria* preenherAutomaticamente(veiculos_concessionaria *veiculos,int tam);

