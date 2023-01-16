#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar dos strings

int cadastrar() //função responsável por cadastrar os usuários no sistema
{	
	//início da criação de variáveis/string
	printf("Você escolheu cadastrar usuário!\n"); 

	char arquivo[40]; //nome do arquivo é o nome do CPF, já que é individual
	char cpf[40]; //mesmo CPF sendo um número, precisamos de uma string, os colchetes significa string
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação dde variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",cpf); //faremos por CPF por ser individual e %s refere-se à string
	
	strcpy(arquivo,cpf); //puxa do CPF para o arquivo e respnsável por copiar os valores das strings

	FILE *file; //acessa o FILE (função já pronta pelo sistema) e cria o arquivo file no banc de dados, mas ainda não falamos do que esse file é composto e farems isso na linha abaixo
	file = fopen(arquivo,"w"); //abre o arquivo com o que estiver dentro dessa variável e será um arquivo novo (write-w)
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //atualizazr informação
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
	
	printf("Usuário cadastrado com sucesso, obrigado!\n");
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	printf("Você escolheu consultar usuário!\n");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //r de read
	
	if(file == NULL) //se for nulo - não existe
	{
		printf("Usuário não localizado.\n");
	}
	
	while(fgets(conteudo,200,file) != NULL) //salvará os 200 caracteres que estão dentro do arquivo e parará quando for nulo
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
	}	
	
	fclose(file);
	
	system("pause");

}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	printf("Você escolheu deletar usuário!\n");

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
		printf("\n\tDeseja deletar este usuário?\n");
		printf ("\t1 - Sim\n");
		printf("\t2 - Não\n");
		printf("Opção: \n");
		scanf("%d",&opcao);
		
		switch(opcao)
		{
			case 1:
			remove(cpf);
			printf("Usuário deletado com sucesso!\n");
			break;
			
			case 2:
			printf("Operação cancelada, retorne ao menu principal!\n");
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			break;
			
			system("pause");
		}
	
		if(file == NULL)
	
			{
			printf("O usuário não está cadastrado!\n");
			}	
			
			system("pause");
	}
}	

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int opcao=0; //definindo as variáveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin"); //compara as duas strings e se caso ambas forem iguais ela retorna 0
	
	if(comparacao == 0)
	{
		printf("Usuário autorizado!");
		
		for(laco=1;laco=1;)
		{
		
			system("cls");

			setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
			printf("### Cartório da EBAC ###\n\n"); //início do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Cadastrar usuário\n");
			printf("\t2 - Consultar usuário\n");
			printf("\t3 - Deletar usuário\n"); 
			printf("\t4 - Sair do sistema\n\n"); 
			printf("Opção: "); //fim do menu
	
			scanf("%d",&opcao); //armazenando a escolha do usuário
	
			system("cls"); //reponsável por limpar a tela
	
			switch(opcao)
			{
				case 1: //início da seleção
				cadastrar(); //chamada de funções
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
				printf("Essa opção não está disponível!\n");
				system("pause");
				break;
			
			}//final da seleção
		}
	}
	else
		printf("Senha incorreta!");	
}
