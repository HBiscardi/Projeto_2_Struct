#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cadastro{
	int idUsuario;	
	char nome[1000][50];	
	char eMail[1000][50];
	char sexo[1000][10]; 
	char endereco[1000][150];
	double altura;
	int vacina;	
}cadastro;

void cadastrar  (struct cadastro *cad, int i);
void imprimir   (struct cadastro *cad, int cont);
void validaNome (struct cadastro *cad, int i);
void validaSexo (struct cadastro *cad, int i);
void cadastrarId(struct cadastro *cad, int i);
void excluirId  (struct cadastro *cad, int i); //Pode ser que funcione após criar a função EDITAR
int menu();

int main(){
	
	struct cadastro cad[2];
	
	int opcao=0,cont=0, i=0;		
	
	do{ /* Estrutura de repetição que executa o código pelo menos uma vez */
		opcao = menu();
		switch(opcao){ /*Comando condicional que compara as condições de uma variavel, utilizamos para a criação do menu*/ 
			case 1:
				system("cls"); /*limpa a tela*/
				printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX      CADASTRAR NOVO USUARIO      XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				cadastrar(cad, i);
				i++; /*controlador da posição do vetor */
				cont++;
				printf("\n\t\t\tCadastro realizado com sucesso!!!\n\n");				
				system("pause");
				break;
			case 2:
				/*ordenacaoVetor(); /*função de ordenação do vetor*/
				system("cls"); /*limpa tela */
				printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX       USUARIOS CADASTRADOS       XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				imprimir (cad, cont);
			system ("pause"); /* pause na execução */
				break;
			/*case 3:
				system("cls");
				printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX  PESQUISAR USUARIOS CADASTRADOS  XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				pesquisar();		
			system ("pause");
				break;*/
			case 4:
				system("cls");
				printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX   EXCLUIR USUARIOS CADASTRADOS   XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				excluirId (cad, i);	
				printf("\nO cadastro foi excluido com sucesso!\n\n");
			system ("pause");
			break;
			case 5:/*
				system("cls");
				printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX    EDITAR USUARIOS CADASTRADOS   XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				editar();
			system ("pause");
				break;*\
			case 6:
               system("cls");
                printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX          REALIZAR BACKUP         XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				backup();
			system ("pause");
				break;
				*/
			case 7 :
               system("cls");
                printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX        See You Later   ;-P       XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				break;
		}
	}while(opcao !=7);
	
	return 0;	
}
void cadastrar (struct cadastro *cad, int i){
		
		cadastrarId(cad,i);
		fflush(stdin);
		
		printf("Informe seu nome.............................................: ");
		fgets(cad[i].nome[i],sizeof(cad[i].nome[i]), stdin);
		validaNome(cad,i);
		fflush(stdin);
		
		printf("Informe seu Email.............................................: ");	
		fgets(cad[i].eMail[i],sizeof(cad[i].eMail[i]), stdin);		
		fflush(stdin);
		
		printf("Informe seu Sexo.............................................: ");	
		fgets(cad[i].sexo[i],sizeof(cad[i].sexo[i]), stdin);
		validaSexo(cad,i);
		fflush(stdin);	
		
		printf("Tomou vacina:[1] sim [2] nao: ");
		scanf("%d", &cad[i].vacina);
		fflush(stdin);		
				
		printf("Informe seu Endereco.............................................: ");
		fgets(cad[i].endereco[i],sizeof(cad[i].endereco[i]), stdin);
		fflush(stdin);
		
		printf("Informe seu altura.............................................: ");
		scanf("%lf", &cad[i].altura);
		fflush(stdin);			
		
		printf("\n");	
	}		
void imprimir (struct cadastro *cad, int cont){
	int i=0;
	
	for(i=0;i<cont;i++){
		if(cad[i].idUsuario!= 0){
			printf("\tID Usuario.............................................: %i\n",cad[i].idUsuario);
			printf("\tNome...................................................: %s\n",cad[i].nome[i]);
			printf("\tEmail cadastrado.......................................: %s\n",cad[i].eMail[i]);
			printf("\tSexo...................................................: %s\n",cad[i].sexo[i]);
			printf("\tTomou vacina?..........................................: ");					
			if(cad[i].vacina == 1){/*condicional bolleana*/
				printf("SIM\n");
			}else{
				printf("NAO\n");
			}
			printf("\tEndereco...............................................: %s", cad[i].endereco[i]);
			printf("\tAltura.................................................:  %.2f\n", cad[i].altura);
			printf("\n");					
		}	
	}			
}
int menu(){
system ("cls");
	int opcao=0;
	do{
		system ("cls");
		printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
		printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
		printf("\nXX XXX XXX XXXX        SELECIONE UMA OPCAO:      XX XXX XXX XXX XXX XX");
		printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
		printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX  \n\n");		
		printf(" \t[1]\tCadastrar Novo Usuario\n");
		printf(" \t[2]\tListar Usuarios Cadastrados\n");
		printf(" \t[3]\tPesquisar Usuario\n");
		printf(" \t[4]\tExcluir Cadastro\n");
		printf(" \t[5]\tEditar Cadastro\n");
		printf(" \t[6]\tBackup\n");
		printf(" \t[7]\tSair\n");
		printf("\nOpcao desejada: ");
		scanf("%d", &opcao);
		getchar();
		printf("\n");
		if(opcao > 7 || opcao < 1){
			printf("\n\tATENCAO!!!\n\n");
			printf("\tOpcao Invalida\n\n"); /*valida a opcao digitada*/
			system("pause");
		}
	}while(opcao == 0);
return opcao;
}
void cadastrarId(struct cadastro *cad, int i){ /* funcao para cadastrar id de forma randomica */
	int idTemp;
	do{
		srand(time(NULL));
		idTemp = rand()%100000;/*geração de um Id automático por meio de numeros aleatórios*/

	}while (idTemp == cad[i].idUsuario); /*estrutura de repeticao para repetir a função randomica para geração de novo id, caso essejá exista */

	cad[i].idUsuario = idTemp;
	printf("ID Usuario...................................................: %i\n", cad[i].idUsuario);
}


void validaNome(struct cadastro *cad, int i){ /*funcao para validar nome*/
	do{			
		if (strlen(cad[i].nome[i])== 1){ /* verifica se a posicao está vazia */
			printf("Este campo nao pode ser vazio\n");
			printf("Informe seu nome.............................................: ");
			fgets(cad[i].nome[i],sizeof(cad[i].nome[i]), stdin);
		}
	}while(strlen(cad[i].nome[i])== 1);	
}
void validaSexo(struct cadastro *cad, int i){  /*funcao para validar sexo*/
	do{		
		strupr(cad[i].sexo[i]); //função que converte a string para maiúsculo.
		if(strcmp(cad[i].sexo[i],"MASCULINO")!=0 && strcmp(cad[i].sexo[i],"FEMININO")!=0 && strcmp(cad[i].sexo[i], "NAO-DECLARADO")!=0){
			printf("Erro, opcao invalida\n");
			printf("Informe sexo: Masculino, Feminino ou Nao-declarado...........: ");
	   		scanf("%s", cad[i].sexo[i]);
	   		fflush(stdin); /*limpa buffer */	   		
		}
	}while(strcmp(cad[i].sexo[i],"MASCULINO")!=0 && strcmp(cad[i].sexo[i],"FEMININO")!=0 && strcmp(cad[i].sexo[i], "NAO-DECLARADO")!=0);
}

void excluirId(struct cadastro *cad, int i){
	int idTemp, idEx = NULL;
	cad[i].idUsuario = idEx;
	//printf("ID Excluido com sucesso!\n");
}



