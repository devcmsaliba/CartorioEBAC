#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar dos strings

int cadastrar()
{	
	printf("Você escolheu cadastrar nomes!\n");

	char arquivo[40]; //nome do arquivo é o nome do CPF, já que é individual
	char cpf[40]; //mesmo CPF sendo um número, precisamos de uma string, os colchetes significa string
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf); //faremos por CPF por ser individual
	
	strcpy(arquivo,cpf); //puxa do CPF para o arquivo e respnsável por copiar os valores das strings

	FILE *file; //acessa o FILE (função já pronta pelo sistema) e cria o arquivo file no banc de dados, mas ainda não falamos do que esse file é composto e farems isso na linha abaixo
	file = fopen(arquivo, "w"); //abre o arquivo com o que estiver dentro dessa variável e será um arquivo novo (write-w)
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualizazr informação e não incluir 
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
	
	printf("Você escolheu consultar nomes!\n");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: \n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //r de read
	
	if(file == NULL) //se for nulo - não existe
	{
		printf("Informação não localizada.\n");
	}
	
	while(fgets(conteudo,200,file) != NULL) //salvará os 200 caracteres que estão dentro do arquivo e parará quando for nulo
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
	}	
	
	system("pause");

}

int deletar()
{
	printf("Você escolheu deletar nomes!\n");
	system("pause");
}

int main()
{
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");

		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Cadastrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls");
	
		switch(opcao)
		{
			case 1: //início da seleção
			cadastrar();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break; //final da seleção
			
		}
	
	}
}
