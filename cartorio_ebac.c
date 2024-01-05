#include <stdio.h>//biblioteca de comunicação com o usuário
#include <stdlib.h>// biclioteca de alocação de espaço em memória
#include <locale.h>// biblioteca de alocação de texto por região
#include <string.h>// biblioteca responsável por cuidar das string

int registro()//função responsavel por cadastrar usuário
{
	//inicio criação de variárveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim criação de variárveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuária
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
	
	system("pause");//pausa o programa para o usuário
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
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");	
	}
	
	while(fgets(conteudo,200,file)!=NULL)
	{
		printf("\nEssas são as informações do usuário: ");
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
	
	if(file==NULL)//Analise de usuário inexistente.
	{
		printf("O usuário não se encontra no sistema!.\n");
		
	}
	remove(cpf);//deleta o usuário consultado
		
	if(file!=NULL)//Analisse de usuário existente
	{
		printf("O usuário foi deletado com sucesso!.\n");
	}	
	system("pause");
}

int main()
{
	int opcao = 0; //Definindo variáveis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de adminstrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin");
	
	if(comparacao==0)
	{
	
		for(laco=1;laco=1;)
		{
	
			system("cls");
			setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
			printf("### Cartório da EBAC ###\n\n"); //inicio do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n ");
			printf("\t2 - Consultar nomes\n ");
			printf("\t3 - Deletar nomes\n\n ");
			printf("\t4 - Sair do sistema\n\n");
			printf("opção: ");//fim do menu
	
			scanf ("%d", &opcao);// armazenando a esoclha do usuário
	
			system("cls");//responsavel por limpar a tela
		
			switch(opcao)//inicio da seleção do menu
			{
				case 1:
				registro();//chamada de funções
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
				printf("Essa opção não esta disponivel\n");
				system("pause");
				break;	
			}// fim da seleção
	
	
		}


	}
	
	else
	printf("\n\n ACESSO NEGADO!");	

}



