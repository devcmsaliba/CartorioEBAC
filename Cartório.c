#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar dos strings

int cadastrar()
{	
	printf("Voc� escolheu cadastrar nomes!\n");

	char arquivo[40]; //nome do arquivo � o nome do CPF, j� que � individual
	char cpf[40]; //mesmo CPF sendo um n�mero, precisamos de uma string, os colchetes significa string
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf); //faremos por CPF por ser individual
	
	strcpy(arquivo,cpf); //puxa do CPF para o arquivo e respns�vel por copiar os valores das strings

	FILE *file; //acessa o FILE (fun��o j� pronta pelo sistema) e cria o arquivo file no banc de dados, mas ainda n�o falamos do que esse file � composto e farems isso na linha abaixo
	file = fopen(arquivo, "w"); //abre o arquivo com o que estiver dentro dessa vari�vel e ser� um arquivo novo (write-w)
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualizazr informa��o e n�o incluir 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	printf("Cadastro realizado, obrigado!\n");
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	printf("Voc� escolheu consultar nomes!\n");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: \n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //r de read
	
	if(file == NULL) //se for nulo - n�o existe
	{
		printf("Informa��o n�o localizada.\n");
	}
	
	while(fgets(conteudo,200,file) != NULL) //salvar� os 200 caracteres que est�o dentro do arquivo e parar� quando for nulo
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
	}	
	
	system("pause");

}

int deletar()
{
	printf("Voc� escolheu deletar nomes!\n");
	system("pause");
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
		printf("\t1 - Cadastrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls");
	
		switch(opcao)
		{
			case 1: //in�cio da sele��o
			cadastrar();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break; //final da sele��o
			
		}
	
	}
}
