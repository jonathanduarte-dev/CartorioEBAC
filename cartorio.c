#include <stdio.h> //biblioteca de comunicação do usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar da string

int registro()  // Função responsável por cadastrar o usuários no sistema
{
    //inicio criação de variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome [40];
    char cargo [40];
    //final criação de variáveis/string

    printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
    scanf("%s", cpf); //%s refere a String, puxa a variável 
    
    strcpy(arquivo, cpf); //Responsável por copia os valores das string ( no caso, atribuir o nome do CPF para o Arquivo)
    
    FILE *file; //"FILE" código para solicitar um comando para o nome do arquivo, "*file" seria o arquivo relacionado (cria um arquivo)
    file = fopen(arquivo, "w"); //repetindo o nome do arquivo desejado (no caso do "file") 
    //e o "fopen" para abrir o arquivo. | O código "w" vem de Write, ou seja, cria um arquivo novo
    fprintf(file, cpf); //Salva o valor da variável. Mesma coisa do "printf comum, só muda que vai aparecer para o arquivo.
    fclose(file); //igual ao "break" o "fclose" finaliza ou fecha o arquivo.
    
    file = fopen(arquivo, "a"); //"a" é para atribuir.
    fprintf(file, ","); // a "vírgula" aqui é apenas para separar as informações.
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome); //jogou dentro do arquivo, o sobrenome.
    fclose(file);
    
    file = fopen(arquivo, "a"); //"a" é para atribuir.
    fprintf(file, ","); // a "vírgula" aqui é apenas para separar as informações.
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
    system("read -p 'Pressione Enter para continuar...' var"); // Alteração para Linux
}

int consulta() // tomadas de decisões
{
    setlocale(LC_ALL, "Portuguese"); //"setlocale" Define a linguagem inserida. 
    
    char cpf[40];
    char conteudo[200];
        
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf); //"%s" é para definir um parâmetro de consulta
        
    FILE *file;
    file = fopen(cpf,"r");
        
    if(file == NULL) // == é o símbolo para igual 
    {
        printf("Não foi possível abrir o arquivo, não localizado!.\n");
    }
        
    while(fgets(conteudo, 200, file) != NULL) //  != é símbolo de Diferente / while é enquanto, ou seja, referente a validação
        
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }
    
    system("read -p 'Pressione Enter para continuar...' var"); // Alteração para Linux
}

int deletar()
{
    char cpf[40];
        
    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);
        
    remove(cpf);
        
    FILE *file;
    file = fopen(cpf,"r");
        
    if(file == NULL)
    {
        printf("O usuário não se encontra no sistema!.\n");
        system("read -p 'Pressione Enter para continuar...' var"); // Alteração para Linux
    }
}

int main()// O "()" (parênteses) determina que isso é uma FUNÇÃO
{   
    int opcao=0;
    int laco=1;
    
    for(laco=1;laco=1;)//"for" (faça) é um laço de repetição, e caso tenha incremento, utilizar o ++
    {
        system("clear"); // Alteração para Linux
        
        setlocale(LC_ALL, "Portuguese"); //"setlocale" Define a linguagem inserida.
    
        printf("### Cartório da EBAC ###\n\n"); // As "##" são meramente cosméticas kk
        printf("Escolha a opção desejada do menu: \n\n");
        printf("\t1 - Registrar nomes\n"); // O comando "\t" serve para espaçar a linha e o "\n" para pular linha
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair do sistema\n\n");
    
        scanf("%d", &opcao); // o comando "scanf" serve para escanear a variável inserida, e a "%d" serve para puxar as variáveis do tipo inteiro.
    
        system("clear"); // Alteração para Linux
       
        switch(opcao)//menu com a opção do Switch Case, ao invés do "if" 
        ///inicio da seleção menu
        {
            case 1:
                registro();//chamada de funções
                break; //o "break" (quebra) realiza o fechamento da chave 
            
            case 2:
                consulta();
                break;
            
            case 3:
                deletar();
                break; 
            
            case 4:
                printf("Obrigado por utilizar o sistema!\n\n");
                return 0;
                break;
                
            default: 
                printf("Essa opção não está disponível. Reinicie o programa e volte para o Menu.\n");
                system("read -p 'Pressione Enter para continuar...' var"); // Alteração para Linux
                break;      
        }
    }
}

