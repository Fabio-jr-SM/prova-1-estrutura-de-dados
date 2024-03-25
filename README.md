# Prova de Avaliação - Concessionária de Veículos União
## Aluno: Fábio Júnior Senna Moura
A seguir está a descrição da prova de avaliação 1 de Estrutura de dados cujo o objetivo é fazer um algoritmo de Concessionária de Veículos. Este é um exercício individual que avalia suas habilidades em programação na linguagem C, especialmente em relação à manipulação de estruturas de dados, algoritmos de busca e ordenação, bem como boas práticas de organização de código.

## Descrição da Prova

A Concessionária de veículos União precisa administrar o seu estoque e, para isso, conta com os seguintes dados:

- Número do veículo: valor numérico inteiro que não pode ser repetido, variando de 100 a 150;
- Marca fabricante: valor literal, com tamanho máximo de 15 caracteres;
- Nome do veículo: valor literal, com tamanho máximo de 20 caracteres;
- Placa: valor literal, com tamanho exato de 8 caracteres;
- Valor: valor numérico real, representando o preço do veículo.

A aplicação deve implementar os seguintes serviços, disponibilizados em telas ao usuário por meio de um menu de opções:

1. Cadastro de veículos: com todos os seus dados, na quantidade que o usuário desejar;
2. Busca de veículos pelo número, retornando os dados do veículo em caso de sucesso;
3. Busca de veículos pela placa, retornando o nome do veículo e valor;
4. Emissão dos seguintes relatórios em tela:
   - Listagem de veículos, pela ordem crescente da marca: Trazer informações de nome do veículo e valor;
   - Listagem de veículos pela ordem decrescente do valor.

### Instruções

- O insucesso das buscas deve apresentar a mensagem "informação não localizada!";
- Utilizar o algoritmo de busca binária para as operações de busca;
- Nas opções de relatórios e busca, devem ser utilizados algoritmos de ordenação das categorias básica (seleção, inserção ou troca) e sofisticada (merge sort e quick sort), na proporção de 50% para cada relatório;
- Todos os módulos do programa devem ser prototipados no arquivo de cabeçalho (.h) e desenvolvidos no arquivo espelho (arquivo .c, espelho do arquivo de cabeçalho .h);
- A definição da estrutura deve ser realizada no arquivo de cabeçalho;
- O arquivo que contém a função principal (main) deve conter apenas alguma definição de variáveis e a chamada ao menu de opções.

### Pontuação e Inovação

A pontuação total desta prova é de 10 pontos, sendo 1 ponto atribuído à inovação, que consiste em melhorias na estrutura, no código C e na apresentação que diferenciam dos demais grupos. Algumas Melhorias no codigo:

- Criado uma opção para o usuário preencher automaticamente ou manualmente os carros;
- Utilizado uma variável de controle para não repetir funções;
- Verificação e tratamento de erros no preenchimento dos dados cadastrais;
- Verificar se o número do veiculo varia de 100 a 150 e verificação se o numero é unico;

## Comandos para Compilar e Executar

Para compilar o programa, utilize os seguintes comandos no terminal:

```
gcc main.c car.c car.h -o main.exe
```

Para executar o programa compilado, utilize o seguinte comando no terminal:

```
.\main
```

Certifique-se de estar no diretório correto onde os arquivos estão localizados.

---

Esse README fornece instruções detalhadas sobre a prova de avaliação da Concessionária de Veículos União, incluindo uma descrição detalhada da prova, instruções para compilar e executar o programa e informações sobre pontuação e inovação. Qualquer dúvida, estou à disposição para ajudar.

Atenciosamente,
Fábio Junior Senna Moura