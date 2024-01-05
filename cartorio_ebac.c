#include <stdio.h>//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>// biclioteca de aloca��o de espa�o em mem�ria
#include <locale.h>// biblioteca de aloca��o de texto por regi�o
#include <string.h>// biblioteca respons�vel por cuidar das string

int registro()//fun��o responsavel por cadastrar usu�rio
{
	//inicio cria��o de vari�rveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim cria��o de vari�rveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�ria
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE*file;//cria o aquivo
	file = fopen(arquivo,"w");//cria o arquivo
	fprintf(file,cpf);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abri o arquivo criado
	fprintf(file,",");//acresenta a virgula no final
	fclose(file);//salva e fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");//abri o arquivo criado
	fprintf(file,nome);//salva o valor da variavel
	fclose(file);//salva e fecha o arquivo
	
	file = fopen(arquivo, "a");//abri o arquivo criado
	fprintf(file,",");//acresenta a virgula no final
	fclose(file);//salva e fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");//abri o arquivo criado
	fprintf(file,sobrenome);//salva o valor da variavel
	fclose(file);//salva e fecha o arquivo
	
	file = fopen(arquivo, "a");//abri o arquivo criado
	fprintf(file,",");//acresenta a virgula no final
	fclose(file);//salva e fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");//abri o arquivo criado
	fprintf(file,cargo);//salva o valor da variavel
	fclose(file);//salva e fecha o arquivo
	
	file = fopen(arquivo, "a");//abri o arquivo criado
	fprintf(file,",");//acresenta a virgula no final
	fclose(file);//salva e fecha o arquivo
	
	system("pause");//pausa o programa para o usu�rio
}

int consultar()
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE*file;
	file=fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");	
	}
	
	while(fgets(conteudo,200,file)!=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar()
{
	char cpf[48];//variavel a ser consultada
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	

	
	FILE*file;
	file=fopen(cpf,"r");//abrir e "r" lendo arquivo
	
	if(file==NULL)//Analise de usu�rio inexistente.
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		
	}
	remove(cpf);//deleta o usu�rio consultado
		
	if(file!=NULL)//Analisse de usu�rio existente
	{
		printf("O usu�rio foi deletado com sucesso!.\n");
	}	
	system("pause");
}

int main()
{
	int opcao = 0; //Definindo vari�veis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de adminstrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin");
	
	if(comparacao==0)
	{
	
		for(laco=1;laco=1;)
		{
	
			system("cls");
			setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
			printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n ");
			printf("\t2 - Consultar nomes\n ");
			printf("\t3 - Deletar nomes\n\n ");
			printf("\t4 - Sair do sistema\n\n");
			printf("op��o: ");//fim do menu
	
			scanf ("%d", &opcao);// armazenando a esoclha do usu�rio
	
			system("cls");//responsavel por limpar a tela
		
			switch(opcao)//inicio da sele��o do menu
			{
				case 1:
				registro();//chamada de fun��es
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
				printf("Essa op��o n�o esta disponivel\n");
				system("pause");
				break;	
			}// fim da sele��o
	
	
		}


	}
	
	else
	printf("\n\n ACESSO NEGADO!");	

}



