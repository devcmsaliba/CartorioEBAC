#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar dos strings

int cadastrar() //fun��o respons�vel por cadastrar os usu�rios no sistema
{	
	//in�cio da cria��o de vari�veis/string
	printf("Voc� escolheu cadastrar usu�rio!\n"); 

	char arquivo[40]; //nome do arquivo � o nome do CPF, j� que � individual
	char cpf[40]; //mesmo CPF sendo um n�mero, precisamos de uma string, os colchetes significa string
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o dde vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //faremos por CPF por ser individual e %s refere-se � string
	
	strcpy(arquivo,cpf); //puxa do CPF para o arquivo e respns�vel por copiar os valores das strings

	FILE *file; //acessa o FILE (fun��o j� pronta pelo sistema) e cria o arquivo file no banc de dados, mas ainda n�o falamos do que esse file � composto e farems isso na linha abaixo
	file = fopen(arquivo,"w"); //abre o arquivo com o que estiver dentro dessa vari�vel e ser� um arquivo novo (write-w)
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //atualizazr informa��o
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	printf("Usu�rio cadastrado com sucesso, obrigado!\n");
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	printf("Voc� escolheu consultar usu�rio!\n");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //r de read
	
	if(file == NULL) //se for nulo - n�o existe
	{
		printf("Usu�rio n�o localizado.\n");
	}
	
	while(fgets(conteudo,200,file) != NULL) //salvar� os 200 caracteres que est�o dentro do arquivo e parar� quando for nulo
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
	}	
	
	fclose(file);
	
	system("pause");

}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	printf("Voc� escolheu deletar usu�rio!\n");

	char cpf[40];
	int opcao;
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf); //string
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file != NULL)
	
	{
		printf("CPF: ");
		printf(cpf);
		printf("\n\tDeseja deletar este usu�rio?\n");
		printf ("\t1 - Sim\n");
		printf("\t2 - N�o\n");
		printf("Op��o: \n");
		scanf("%d",&opcao);
		
		switch(opcao)
		{
			case 1:
			remove(cpf);
			printf("Usu�rio deletado com sucesso!\n");
			break;
			
			case 2:
			printf("Opera��o cancelada, retorne ao menu principal!\n");
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			break;
			
			system("pause");
		}
	
		if(file == NULL)
	
			{
			printf("O usu�rio n�o est� cadastrado!\n");
			}	
			
			system("pause");
	}
}	

int main()
{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");

		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Cadastrar usu�rio\n");
		printf("\t2 - Consultar usu�rio\n");
		printf("\t3 - Deletar usu�rio\n"); 
		printf("\t4 - Sair do sistema\n\n"); 
		printf("Op��o: "); //fim do menu
	
		scanf("%d",&opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //repons�vel por limpar a tela
	
		switch(opcao)
		{
			case 1: //in�cio da sele��o
			cadastrar(); //chamada de fun��es
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break; //final da sele��o
			
		}
	
	}
}
