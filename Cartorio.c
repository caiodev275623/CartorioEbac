#include <stdio.h> //biblioteca de comunica��o com o us�ario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca DE aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings

int registro()// Fun��o resp�nsavel por cadastrar os usu�rios no sistema
{
    //in�cio da cria��o de vari�veis/string	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string

	printf(" Digite o CPF a ser cadastrado:\n "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a strings

    strcpy(arquivo, cpf);//repons�vel por copiar os valores das strings
    
    FILE *file;//cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
    fprintf(file,cpf);//salva o valor da variavel
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a"); //atualiza o arquivo e o "a" � resp�nsavel por essa atualiza��o
    fprintf(file, ","); //separa a informa��o coletada
    fclose(file);

    printf("Digite o nome a ser cadastrado:\n ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a"); //cadastra o nome do usu�rio
    fprintf(file, nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado:\n ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a"); //cadastra o  sobrenome do usu�rio
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado:\n "); 
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a"); //cadastra o cargo do usu�rio
    fprintf(file, cargo);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
}


int consulta() // Fun��o resp�nsavel por consultar os usu�rios do sistema
{ 
    setlocale(LC_ALL, "Portuguese"); 
		
	char cpf[40];
	char conteudo[200];

	printf("Digite o cpf a ser consultado: \n"); 
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // Encontra e apresenta a resposta ao usu�rio 
	
	if(file == NULL) //caso o pedido do usu�rio n�o existir
	{ 		
	  printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	
	{
		printf("\nEssas s�o as informa��es do us�ario: "); //Resposta ao pedido do usu�rio
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
     	printf("O usu�rio n�o se enconta no sitema!. \n");
    	system("pause");
	}

	
else if(file != NULL) //caso o pedido do usu�rio for realizado
    {
    	fclose(file);
    	printf("Usu�rio deletado com sucesso!. \n"); //  resposta ao usu�rio	
    	system("pause");
    	
    	remove(cpf);
	}	
}

int main()
{
	int opcao=0;  //Definindo vari�veis
	int laco=1;
	for(laco=1;laco=1;)
	
	{

		system("cls"); //resp�nsavel por limpar a tela
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo linguagens 
	
	    printf("C### Cart�rio da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
     	printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar os nomes\n");
	    printf("\t3 - Deletar nomes  \n");
	    printf("\t4 - Sair do sistema\n");
	    printf("Op��o:");// fim do menu
	
     	scanf("%d", &opcao);//Armazenando as escolhas dos us�arios
	
	
	    system("cls");
	    
	    switch(opcao) // Inicio da sele��o do menu
	    {
	    	case 1://int registro
	    	registro(); //chamada de fun��es
			break;

			case 2://int consulta
	    	consulta();//chamada de fun��es
			break;
						
			case 3://int deletar
			deletar();//chamada de fun��es
	        break;
	        
	        printf("Obrigado por utilizar o sistema!\n");
	        return 0;
	        break;
				        
	        default://caso o pedido do usu�rio n�o existir
	        printf("Essa op��o n�o est� disponivel! \n");
	        system ("pause");
	        break;		    	
		} //Fim da sele��o	
    }	
}
