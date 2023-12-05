#include <stdio.h> //biblioteca de comunicação com o usúario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca DE alocações de texto por região
#include <string.h> //biblioteca responsável pelas strings

int registro()// Função respónsavel por cadastrar os usuários no sistema
{
    //início da criação de variáveis/string	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string

	printf(" Digite o CPF a ser cadastrado:\n "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a strings

    strcpy(arquivo, cpf);//reponsável por copiar os valores das strings
    
    FILE *file;//cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
    fprintf(file,cpf);//salva o valor da variavel
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a"); //atualiza o arquivo e o "a" é respónsavel por essa atualização
    fprintf(file, ","); //separa a informação coletada
    fclose(file);

    printf("Digite o nome a ser cadastrado:\n ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a"); //cadastra o nome do usuário
    fprintf(file, nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado:\n ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a"); //cadastra o  sobrenome do usuário
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado:\n "); 
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a"); //cadastra o cargo do usuário
    fprintf(file, cargo);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
}


int consulta() // Função respónsavel por consultar os usuários do sistema
{ 
    setlocale(LC_ALL, "Portuguese"); 
		
	char cpf[40];
	char conteudo[200];

	printf("Digite o cpf a ser consultado: \n"); 
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // Encontra e apresenta a resposta ao usuário 
	
	if(file == NULL) //caso o pedido do usuário não existir
	{ 		
	  printf("Não foi possivel abrir o arquivo, não localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	
	{
		printf("\nEssas são as informações do usúario: "); //Resposta ao pedido do usuário
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");	
}
    
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
    	fclose(file);
     	printf("O usuário não se enconta no sitema!. \n");
    	system("pause");
	}

	
else if(file != NULL) //caso o pedido do usuário for realizado
    {
    	fclose(file);
    	printf("Usuário deletado com sucesso!. \n"); //  resposta ao usuário	
    	system("pause");
    	
    	remove(cpf);
	}	
}

int main()
{
	int opcao=0;  //Definindo variáveis
	int laco=1;
	for(laco=1;laco=1;)
	
	{

		system("cls"); //respónsavel por limpar a tela
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo linguagens 
	
	    printf("C### Cartório da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
     	printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar os nomes\n");
	    printf("\t3 - Deletar nomes  \n");
	    printf("\t4 - Sair do sistema\n");
	    printf("Opção:");// fim do menu
	
     	scanf("%d", &opcao);//Armazenando as escolhas dos usúarios
	
	
	    system("cls");
	    
	    switch(opcao) // Inicio da seleção do menu
	    {
	    	case 1://int registro
	    	registro(); //chamada de funções
			break;

			case 2://int consulta
	    	consulta();//chamada de funções
			break;
						
			case 3://int deletar
			deletar();//chamada de funções
	        break;
	        
	        printf("Obrigado por utilizar o sistema!\n");
	        return 0;
	        break;
				        
	        default://caso o pedido do usuário não existir
	        printf("Essa opção não está disponivel! \n");
	        system ("pause");
	        break;		    	
		} //Fim da seleção	
    }	
}
