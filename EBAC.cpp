#include <stdio.h> //Biblioteca de comunica��o.
#include <stdlib.h> //Aloca��o de espa�o na memoria.
#include <locale.h> //Aloca��o de texto por localidade (Pa�s)
#include <string.h>

int registrar(){
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);  //Fun��o strcpy � respons�vel por criar uma c�pia do valor de uma var�avel em outra vari�vel.
	
	FILE *file;  // Respos�vel por criar um arquivo novo
	file = fopen(arquivo, "w");  // O "W" � usado para indicar que queremos escrever um arquino novo
	fprintf(file, cpf);
	fclose(file);
	
	file = fopen(arquivo, "a"); // O "a" � usado para indicar que queremos adicionar uma nova informa��o a um arquivo j� existente.
	fprintf(file, " , ");
	fclose(file);
	
	printf("Digite o Nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " , ");
	fclose(file);

	printf("Digite o Sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);	
	
	file = fopen(arquivo, "a");
	fprintf(file, " , ");
	fclose(file);
	
	printf("Digite o Cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
}

int consultar(){
	setlocale(LC_ALL, "Portuguese");
	
	char cpf [40];
	char informacao [200];
	
	printf("Digite o CPF para consulta: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // O "r" � usado para indicar que queremos ler os dados de um arquivo j� existente.
	
	if (file == NULL){
		printf("Arquivo n�o localizado! \n");
		
	}
	
	while (fgets(informacao, 200, file) != NULL){
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", informacao);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
}

int deletar(){
	char cpf[40];
	
	printf("Digite o CPF: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	 
	if(file == NULL){
		printf("Usu�rio n�o localizado! \n");
	 	system("pause");
		 	 	
	}else{  //Caso o arquivo seja localizado, ser� fechado e removido. Em seguida, ser� exibida uma mensagem indicando que o arquivo foi deletado com sucesso.
		fclose(file); //Fecha o arquivo aberto
		remove(cpf);
		printf("Usu�rio deletado com sucesso! \n");
		system("pause");
	}
	 
}
int main(){ //Fun��o principal da aplica��o. Tudo que estiver dentro de MAIN, ser� executado
	int opcao = 0; 
	int laco = 1;
	char senha[10] = "";
	int comparar = 1;
	
		
	setlocale(LC_ALL, "Portuguese"); 
	printf("###Cart�rio JOHN's MARK### \n\n");
	printf("Digite a senha de acesso: ");
	scanf("%s", senha);	
	
	comparar = strcmp(senha, "admin");

	if(comparar == 0){
		for(laco=1; laco=1;){
			system("cls");
		
			setlocale(LC_ALL, "Portuguese");  // Permite que caracteres especiais brasileiros sejam usados
			printf("###Cart�rio JOHN's MARK### \n\n");
			printf("Escolha a op��o desejada no MENU: \n\n");
			printf("\t1- Registrar Nomes \n");
			printf("\t2- Consultar Nomes \n");
			printf("\t3- Deletar Nomes \n");
			printf("\t4- Sair \n");
			printf("Op��o: ");
		
			scanf("%d", &opcao);
		
			system("cls"); // Fun��o usada para limpar a tela
			
			switch(opcao){
				case 1:
					registrar();
					break;
			
				case 2:
					consultar();
					break;
				
				case 3:
					deletar();
					break;
				
				case 4:
					printf("Obrigado por usar nosso sistema! \n");
					return 0;
					break;
				
				default:
					printf("Essa op��o n�o est� dispon�vel! \n");
					system("pause");
					break;
			}
		}
	}else{
		system("cls");
		printf("Senha incorreta. \n\n");
	}
		
	
}
