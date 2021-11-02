/*	Universidade Católica de Brasília
Professora: Joyce Siqueira
Curso: Análise e Desenvolvimento de Sistemas
Alunos : Uc20200683 - Gabriel Bessa Rebouças
		 Uc20201448 - Harlyson Biscardi Silva
         Uc20201511 - Luiz Fernandes Veras		 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>

struct endereco{
	char rua[40];
	int numero;
	char bairro[40];
	char cidade[40];
	char estado[3];
	char cep[15];	
};
struct cadastro{	
	int idUsuario;	
	char nome[50];	
	char eMail[50];
	char sexo[15]; 
	struct endereco end;	
	double altura;
	int vacina;	
}cadastro;
struct cadastro_bkp{	
	int idUsuario;	
	char nome[50];	
	char eMail[50];
	char sexo[15]; 
	struct endereco end_bkp;	
	double altura;
	int vacina;	
}cadastro_bkp;
struct endereco_bkp{
	char rua[40];
	int numero;
	char bairro[40];
	char cidade[40];
	char estado[3];
	char cep[15];	
};

int ver_bkp = 0;

void cadastrar   		(struct cadastro *cad, int i);
void imprimir    		(struct cadastro *cad, int cont);
void validaNome  		(struct cadastro *cad, int i);
void validaSexo  		(struct cadastro *cad, int i);
void cadastrarId 		(struct cadastro *cad, int i);
void validaVacina		(struct cadastro *cad, int i);
void validaAltura		(struct cadastro *cad, int i);
void ordenacaoVetor		(struct cadastro *cad, int i, int cont);
void editar      		(struct cadastro *cad, int i, int cont);
void excluir     		(struct cadastro *cad, int i, int cont);
void excluirId   		(struct cadastro *cad, int i);
void validaEmail		(struct cadastro *cad, int i);
void ordenacaoVetor		(struct cadastro *cad, int i, int cont);
void pesquisar			(struct cadastro *cad, int i, int cont);
int  buscaBinariaId		(struct cadastro *cad, int cont,  int x);
void backup      		(struct cadastro *cad, int cont, int i);

int menu();

int main(){
	
	struct cadastro cad[1000];
	
	int opcao=0,cont=0, i=0;		
	
	do{ /* Estrutura de repetiÃ§Ã£o que executa o cÃ³digo pelo menos uma vez */
		opcao = menu();
		switch(opcao){ /*Comando condicional que compara as condiÃ§Ãµes de uma variavel, utilizamos para a criaÃ§Ã£o do menu*/ 
			case 1:
				system("cls"); /*limpa a tela*/
				printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX      CADASTRAR NOVO USUARIO      XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				cadastrar(cad, i);
				i++; /*controlador da posiÃ§Ã£o do vetor */
				cont++;
				printf("\n\t\t\tCadastro realizado com sucesso!!!\n\n");				
				system("pause");
				break;
			case 2:
				ordenacaoVetor(cad, i, cont);
				system("cls"); 
				printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX       USUARIOS CADASTRADOS       XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				imprimir (cad, cont);
				system ("pause"); /* pause na execuÃ§Ã£o */
				break;
			case 3:
				system("cls");
				printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX  PESQUISAR USUARIOS CADASTRADOS  XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				pesquisar(cad, i, cont);
				system ("pause");
				break;
			case 4:
				system("cls");
				printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX   EXCLUIR USUARIOS CADASTRADOS   XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				excluir(cad, i, cont);				
				system ("pause");
			break;
			case 5:
				system("cls");
				printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX    EDITAR USUARIOS CADASTRADOS   XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				editar(cad, i, cont);
				system ("pause");
				break;
			case 6:
                system("cls");
                printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX          REALIZAR BACKUP         XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				backup(cad, cont, i);
				system ("pause");
				break;
			case 7 :
               system("cls");
                printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX        SEE YOU LATER ;-P         XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				break;
			}
	}while(opcao !=7);
	
	return 0;	
}
void cadastrar (struct cadastro *cad, int i){
		
		cadastrarId(cad, i);
		fflush(stdin);
		
		printf("Informe seu nome...................: ");
		fgets(cad[i].nome,sizeof(cad[i].nome), stdin);
		validaNome(cad,i);
		fflush(stdin);
		
		printf("Informe seu Email..................: ");	
		fgets(cad[i].eMail,sizeof(cad[i].eMail), stdin);
		validaEmail(cad,i);	
		fflush(stdin);
		
		printf("Informe seu Sexo...................: ");
		fflush(stdin);	
		fgets(cad[i].sexo,sizeof(cad[i].sexo), stdin);
		fflush(stdin);
		validaSexo(cad,i);
			
		
		printf("Tomou vacina:[1] sim [2] nao: ");
		scanf("%d", &cad[i].vacina);
		validaVacina(cad, i);
		fflush(stdin);	
		
		printf("Informe seu altura.................: ");
		scanf("%lf", &cad[i].altura);
		validaAltura(cad,i);
		fflush(stdin);
							
		printf("Informe seu Endereco:\n");
		printf("Rua................................: ");
		fgets(cad[i].end.rua,sizeof(cad[i].end.rua), stdin);
		fflush(stdin);
		printf("Numero.............................: ");
		scanf("%i", &cad[i].end.numero);
		fflush(stdin);
		printf("Bairro.............................: ");
		fgets(cad[i].end.bairro,sizeof(cad[i].end.bairro), stdin);
		fflush(stdin);	
		printf("Cidade.............................: ");
		fgets(cad[i].end.cidade,sizeof(cad[i].end.cidade), stdin);
		fflush(stdin);	
		printf("Estado.............................: ");
		fgets(cad[i].end.estado,sizeof(cad[i].end.estado), stdin);
		fflush(stdin);	
		printf("Cep................................: ");
		fgets(cad[i].end.cep, sizeof(cad[i].end.cep), stdin);
		fflush(stdin);		
		printf("\n");
	}		
void imprimir (struct cadastro *cad, int cont){
	int i=0;
	
	for(i=0;i<cont;i++){
		if(cad[i].idUsuario != 0){
			printf("\tID Usuario.........................: %i\n",cad[i].idUsuario);
			printf("\tNome...............................: %s",cad[i].nome);
			printf("\tEmail cadastrado...................: %s",cad[i].eMail);
			printf("\tSexo...............................: %s",cad[i].sexo);
			printf("\tTomou vacina?......................: ");					
			if(cad[i].vacina == 1){/*condicional bolleana*/
				printf("SIM\n");
			}else{
				printf("NAO\n");
			}
			printf("\tAltura.............................: %.2f\n", cad[i].altura);
			printf("\tEndereco:\n");
			printf("\t\tRua........................: %s ", cad[i].end.rua);
			printf("\t\tNumero.....................: %i \n", cad[i].end.numero);
			printf("\t\tBairro.....................: %s", cad[i].end.bairro);
			printf("\t\tCidade.....................: %s", cad[i].end.cidade);
			printf("\t\tEstado.....................: %s \n", cad[i].end.estado);
			printf("\t\tCEP........................: %s \n", cad[i].end.cep);	
			printf("======================================================================\n");			
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
void cadastrarId(struct cadastro *cad, int i){ /* funcao para Criar id de forma randomica */

			srand(time(NULL));
			cad[i].idUsuario = rand()%10000;/*geraÃ§Ã£o de um Id automÃ¡tico por meio de numeros aleatÃ³rios*/
	

	printf("ID Usuario.........................: %i\n", cad[i].idUsuario);

}
void validaNome(struct cadastro *cad, int i){ /*funcao para validar nome*/
	do{			
		if (strlen(cad[i].nome)== 1){ /* verifica se a posicao estÃ¡ vazia */
			printf("Este campo nao pode ser vazio\n");
			printf("Informe seu nome.............................................: ");
			fgets(cad[i].nome,sizeof(cad[i].nome), stdin);
		}
	}while(strlen(cad[i].nome)== 1);	
}
void validaSexo(struct cadastro *cad, int i){  /*funcao para validar sexo*/
	
	do{		
		strupr(cad[i].sexo); //funÃ§Ã£o que converte a string para maiÃºsculo.
				
		if(strcmp(cad[i].sexo,"MASCULINO\n")!=0 && strcmp(cad[i].sexo,"FEMININO\n")!=0 && strcmp(cad[i].sexo, "NAO-DECLARADO\n")!=0){
			printf("Erro, opcao invalida\n");
			printf("Informe sexo: Masculino, Feminino ou Nao-declarado...........: ");
	   		fgets(cad[i].sexo,sizeof(cad[i].sexo), stdin);
			fflush(stdin); /*limpa buffer */
			   		
		}
	}while(strcmp(cad[i].sexo,"MASCULINO\n")!=0 && strcmp(cad[i].sexo,"FEMININO\n")!=0 && strcmp(cad[i].sexo, "NAO-DECLARADO\n")!=0);
}
void validaVacina(struct cadastro *cad, int i){ /*funcao bolleana para verificar o cadastro da vacina */
	do{		
		if (cad[i].vacina < 1 || cad[i].vacina > 2){
			printf("Erro, opcao invalida\n");
			printf("Tomou a vacina? digite [1] para SIM ou [2] para NAO..........: ");
			scanf("%d", &cad[i].vacina);
		}
	}while(cad[i].vacina < 1 || cad[i].vacina > 2);
}
void validaAltura(struct cadastro *cad, int i){/*funcao para cadastrar altura*/
	do{		
		if (cad[i].altura < 0.5 || cad[i].altura > 2){
			fflush(stdin);			
			printf("Erro, altura invalida\n");
			printf("valor nÃ£o pode ser inferior a 0.5 mt ou superior a 2.00 mts\n");
			printf("Informe sua altura separada por '.'ponto: ex: 1.60...........: ");
			scanf("%lf", &cad[i].altura);
			fflush(stdin);
		}
	}while(cad[i].altura < 0.5 || cad[i].altura > 2);
}
void editar(struct cadastro *cad, int i, int cont){
	
	int id, identificador=0, opcao=0;	
	
	printf("Informe o Id do cadastro a ser editado: "); 
	scanf("%d", &id); 
	fflush(stdin);

	for(i=0; i < cont; i++){ 
		if(	cad[i].idUsuario == id){				
			cadastrar(cad, i);
			identificador++; 		
			printf("\t\t\tCadastro editado com sucesso!\n\n");		
		}
	}
	if(identificador == 0){
		printf("Id nao foi localizada!\n");
	}
}
void excluir(struct cadastro *cad, int i, int cont){
	int id, identificador=0, opcao=0;	
	printf("Informe o Id do cadastro a ser excluido: ");
	scanf("%d", &id);
	fflush(stdin);
	for(i=0; i < cont; i++){
		if(	cad[i].idUsuario == id){				
			excluirId(cad, i);
			//cadastrarEmail();
			//cadastrarSexo();
			//cadastrarVacina();
			//cadastrarEndereco();
			//cadastrarAltura();
			identificador ++;
			printf("\t\t\tCadastro excluido com sucesso!\n\n");		
		}
	}
	if(identificador == 0){
		printf("\t\tId nao foi localizado!\n");	
	}			
}
void excluirId(struct cadastro *cad, int i){
	int idTemp, idEx = NULL;
	cad[i].idUsuario = idEx;
	//printf("ID Excluido com sucesso!\n");
}
void validaEmail(struct cadastro *cad, int i){/*funcao para cadastrar email*/

    char *validador;
	do{		
		strlwr(cad[i].eMail); //funÃ§Ã£o que converte a string para minusculo.
		validador = strchr(cad[i].eMail,'@'); //funÃ§Ã£o que percorre a string comparando o caractere @ com cada caractere da string, caso nÃ£o encontre retorna NULL.
		
		if(validador == NULL){/* condicional para verificar se o validor Ã© == NULL, se for Ã© porque nÃ£o tem o @*/
			printf("digite um e-mail valido\n"); /*imprime na tela para o usuÃ¡rio digitar um email vÃ¡lido*/
			printf("Informe o seu e-mail.........................................: ");
			scanf("%s", cad[i].eMail);
			strlwr(cad[i].eMail); //funÃ§Ã£o que converte a string para minusculo.
			validador = strchr(cad[i].eMail,'@');
		}
	}while(validador == NULL);/*estrutura de repetiÃ§Ã£o euanquento a condiÃ§Ã£o for verdadeira*/
}
void ordenacaoVetor(struct cadastro *cad, int i, int cont){/*funcao para ordenar o vetor*/
	
	int aux_idUsuario, contador=0, aux_vacina, j=0, aux_num=0;
	char Aux_nome[50], auxEmail[50], auxSexo[10], aux_rua[40],aux_bairro[40],aux_cidade[40],aux_uf[3], aux_cep[15];
	double auxAltura;
	
	
	for(i = 0; i < cont; i++){/*Estrutura que percorre o vetor*/
		for(j = i+1; j < cont; j++){/*Estrutura para comparar a posiÃ§Ã£o seguinte com a a*/
			if(cad[i].idUsuario > cad[j].idUsuario){ /*condicional que verifica se o id na posiÃ§Ã£o i Ã© maior que o id na posiÃ§Ãµo "j" seguinte */
				
				aux_idUsuario = cad[i].idUsuario; /*variavel auxiliar para armazenar os dados da variavel id na posiÃ§Ã£o i*/
				cad[i].idUsuario = cad[j].idUsuario;/*atribuiÃ§Ã£o do valor de uma variavel na posiÃ§Ã£o j para outra na posiÃ§Ã£o i*/
				cad[j].idUsuario = aux_idUsuario;/*variavel na posicao j que vai receber os dados da variÃ¡vel auxiliar*/
				
				strcpy(Aux_nome,cad[i].nome);// strcpy funcao da biblioteca string.h para copiar um vetor de string para uma variavela auxiliar.
				strcpy(cad[i].nome,cad[j].nome); /*atribuiÃ§Ã£o do valor de uma variavel na posiÃ§Ã£o j para outra na posiÃ§Ã£o i*/
				strcpy(cad[j].nome,Aux_nome); /*copiar os dados da variavel auxiliar para a variavel nome na posiÃ§Ã£o j*/
				
				strcpy(auxEmail,cad[i].eMail); /*variavel auxiliar para armazenar os dados da string*/
				strcpy(cad[i].eMail,cad[j].eMail); /*atribuiÃ§Ã£o do valor de uma variavel na posiÃ§Ã£o j para outra na posiÃ§Ã£o i*/
				strcpy(cad[j].eMail,auxEmail); /* copiar dados da variavel auxiliar para a posiÃ§Ã£o J da variavel eMail*/
				
				strcpy(auxSexo,cad[i].sexo);/*variavel auxiliar para armazenar os dados da variavel altura na posiÃ§Ã£o i*/
				strcpy(cad[i].sexo,cad[j].sexo);/*atribuiÃ§Ã£o do valor de uma variavel na posiÃ§Ã£o j para outra na posiÃ§Ã£o i*/
				strcpy(cad[j].sexo,auxSexo);/* copiar dados de uma variavel auxiliar para a posiÃ§Ã£o J do variavel sexo*/
				
				aux_vacina = cad[i].vacina;/*variavel auxiliar para armazenar os dados da variavel altura na posiÃ§Ã£o i*/
				cad[i].vacina = cad[j].vacina;/*atribuiÃ§Ã£o do valor de uma variavel na posiÃ§Ã£o j para outra na posiÃ§Ã£o i*/
				cad[j].vacina = aux_vacina;/* copiar dados da variavel auxiliar para a posiÃ§Ã£o J do variavel vacina*/
				
				strcpy(aux_rua,cad[i].end.rua);
				strcpy(cad[i].end.rua,cad[j].end.rua);
				strcpy(cad[j].end.rua,aux_rua);
				
				aux_num = cad[i].end.numero; /*variavel auxiliar para armazenar os dados da variavel id na posiÃ§Ã£o i*/
				cad[i].end.numero = cad[j].end.numero;/*atribuiÃ§Ã£o do valor de uma variavel na posiÃ§Ã£o j para outra na posiÃ§Ã£o i*/
				cad[j].end.numero = aux_num;
				
				strcpy(aux_bairro,cad[i].end.bairro);
				strcpy(cad[i].end.bairro,cad[j].end.bairro);
				strcpy(cad[j].end.bairro,aux_bairro);
				
				strcpy(aux_cidade,cad[i].end.cidade);
				strcpy(cad[i].end.bairro,cad[j].end.cidade);
				strcpy(cad[j].end.cidade, aux_cidade);
				
				strcpy(aux_uf,cad[i].end.estado);
				strcpy(cad[i].end.estado,cad[j].end.estado);
				strcpy(cad[j].end.estado, aux_uf);
				
				strcpy(aux_cep,cad[i].end.cep);
				strcpy(cad[i].end.cep, cad[j].end.cep);
				strcpy(cad[j].end.cep, aux_cep);				
				
				auxAltura = cad[i].altura;/*variavel auxiliar para armazenar os dados da variavel altura na posiÃ§Ã£o i*/
				cad[i].altura = cad[j].altura; /*atribuiÃ§Ã£o do valor de uma variavel na posiÃ§Ã£o j para outra na posiÃ§Ã£o i*/
				cad[j].altura = auxAltura;	/* copiar dados da variavel auxiliar para a posiÃ§Ã£o J do variavel altura*/							
			}	
		}
	}			
}
void pesquisar(struct cadastro *cad, int i, int cont){	
int idPesquisado, opcao, resultado=0,identificador = 0;
char opcao2[50];

	do{
		printf("\nInforme a opcao de pesquisa:\n[1] ID\n[2] EMAIL\n");
		scanf("%d",&opcao); /*le o Id a ser pesquisado*/
		printf("\nOpcao desejada: %d\n\n",opcao);
		
		if(opcao < 1 || opcao > 2){
			printf("Erro, opcao invalida\n\n");	/* valida se a escolha do usuÃ¡rio estÃ¡ dentro das opÃ§Ãµes oferecidas*/		
		}		
	}while(opcao < 1 || opcao > 2);
	
	switch(opcao){
		case 1:
			printf("Digite o Id que deseja procurar: ");
			scanf("%d", &idPesquisado);
			resultado = buscaBinariaId(cad, cont, idPesquisado);
			
			if(resultado != -1){
				printf("\tID Usuario.............................................: %i\n",cad[resultado].idUsuario);
				printf("\tNome...................................................: %s",cad[resultado].nome);
				printf("\tEmail cadastrado.......................................: %s",cad[resultado].eMail);
				printf("\tSexo...................................................: %s\n",cad[resultado].sexo);
				printf("\tTomou vacina?..........................................: ");					
				if(cad[i].vacina == 1){
					printf("SIM\n");
				}else{
					printf("NAO\n");
				}
				printf("\tAltura.................................................: %.2f\n", cad[resultado].altura);
				printf("\tEndereco................................................\n");
				printf("\t\tRua............................................: %s ", cad[resultado].end.rua);
				printf("\t\tNumero.........................................: %i \n", cad[resultado].end.numero);
				printf("\t\tBairro.........................................: %s \n", cad[resultado].end.bairro);
				printf("\t\tCidade.........................................: %s \n", cad[resultado].end.cidade);
				printf("\t\tEstado.........................................: %s \n", cad[resultado].end.estado);				
				printf("\n");
				}else{	
				printf("Valor nao encontrado\n");	
			break;			
		case 2:			
			printf("Informe o e-mail......................................: ");
			fflush(stdin);
			fgets(opcao2,sizeof(opcao2), stdin);
			fflush(stdin);
			strlwr(opcao2); 
				
			for(i=0;i<cont;i++){
				if(strcmp(opcao2, cad[i].eMail)==0){
					printf("\tID Usuario.............................................: %i\n",cad[i].idUsuario);
					printf("\tNome...................................................: %s",cad[i].nome);
					printf("\tEmail cadastrado.......................................: %s",cad[i].eMail);
					printf("\tSexo...................................................: %s\n",cad[i].sexo);
					printf("\tTomou vacina?..........................................: ");					
					if(cad[i].vacina == 1){
						printf("SIM\n");
					}else{
						printf("NAO\n");
					}
					printf("\tAltura.................................................: %.2f\n", cad[i].altura);
					printf("\tEndereco................................................\n");
					printf("\t\tRua............................................: %s ", cad[i].end.rua);
					printf("\t\tNumero.........................................: %i \n", cad[i].end.numero);
					printf("\t\tBairro.........................................: %s \n", cad[i].end.bairro);
					printf("\t\tCidade.........................................: %s \n", cad[i].end.cidade);
					printf("\t\tEstado.........................................: %s \n", cad[i].end.estado);				
					printf("\n");
					identificador++;					
				}
			}
			if(identificador==0){
				printf("Nao Localizado, tente novamente.\n");
				printf("%s\n", opcao2);
				printf("%s\n", cad[i].eMail);
			}
			break;
		}
	}	
}
int buscaBinariaId( struct cadastro *cad, int cont,  int idpesq){
	int inicio = 0, fim = cont - 1, meio;
	
	while(inicio <= fim){
		meio = (inicio + fim) / 2; /* Identifica a metade do vetor */
		
		if(idpesq==cad[meio].idUsuario){ /* verifica se o id estÃ¡ na posiÃ§Ã£o do meio do vetor */
			return meio; /*se sim, retorna o do meio */
		}else if(idpesq < cad[meio].idUsuario){ /* SenÃ£o verifica se o Id pesquisado Ã© menor que o Id na posiÃ§Ã£o do meio do vetor, se sim a pesquisa serÃ¡ atÃ© a metade do vetor*/
			fim = meio - 1;			
		}else{
			inicio = meio + 1;	/* senÃ£o o inicio serÃ¡ atualizado com a posiÃ§Ã£o do meio + 1 e a pesquisa serÃ¡ realizada a partir daquela posiÃ§Ã£o */		
		}		
	}
	return -1;
}
void backup(struct cadastro *cad, int cont, int i){
	
	struct cadastro_bkp cad_bkp[1000];
	int opcao=0;
	
	do{
		printf("[1] Sim\n[2] Nao\n[3] Restaurar backup\n", opcao);/* imprime na tela a opcao para o usuario*/	
		scanf("%d", &opcao);/*le a opcao desejada*/
		
		printf("Opcao desejada: %d\n", opcao);	/* imprime a opcao desejada */	
		
		if(opcao < 1 || opcao > 3){/* valida a opcao informada pelo usuario*/
			printf("\nErro, opcao invalida\n\n");/*imprime erro casa a opcao seja diferente da informada*/			
		}		
		
	}while(opcao < 1 || opcao > 3);	/* estrutura de repeticao que executa pelo menos uma vez e enquanto as condições forem verdadeira*/
	
	if(opcao == 1){
		if(cad[--i].idUsuario!= NULL){
			for(i = 0; i < cont; i++){
				cad_bkp[i].idUsuario = cad[i].idUsuario;
				strcpy(cad_bkp[i].nome,cad[i].nome);
				strcpy(cad_bkp[i].eMail,cad[i].eMail);
				strcpy(cad_bkp[i].sexo,cad[i].sexo);
				cad_bkp[i].vacina = cad[i].vacina;
				strcpy(cad_bkp[i].end_bkp.rua,cad[i].end.rua);
				cad_bkp[i].end_bkp.numero=cad[i].end.numero;
				strcpy(cad_bkp[i].end_bkp.bairro,cad[i].end.bairro);
				strcpy(cad_bkp[i].end_bkp.cidade,cad[i].end.cidade);
				strcpy(cad_bkp[i].end_bkp.estado,cad[i].end.estado);
				strcpy(cad_bkp[i].end_bkp.cep,cad[i].end.cep);
				cad_bkp[i].altura = cad[i].altura;
				ver_bkp++;/* contador para verificar se existe backup	*/
			}	
			printf("\t\t\tBackup realizado com sucesso!");//imprime mensagem para visualizacao do usuario.			
		}else{
			printf("\t\t\tBase de dados vazia, Backup nao realizado. ");			
		}		
	}else if (opcao == 2){
		printf("\t\t\tBackup nao realizado. ");	
	}else if(ver_bkp != 0){
		for(i = 0; i < cont; i++){
				cad[i].idUsuario = cad_bkp[i].idUsuario;
				strcpy(cad[i].nome,cad_bkp[i].nome);
				strcpy(cad[i].eMail, cad_bkp[i].eMail);
				strcpy(cad_bkp[i].sexo,cad[i].sexo);
				cad[i].vacina = cad_bkp[i].vacina;
				strcpy(cad[i].end.rua,cad_bkp[i].end_bkp.rua);
				cad[i].end.numero=cad_bkp[i].end_bkp.numero;
				strcpy(cad[i].end.bairro,cad_bkp[i].end_bkp.bairro);
				strcpy(cad[i].end.cidade,cad_bkp[i].end_bkp.cidade);
				strcpy(cad[i].end.estado,cad_bkp[i].end_bkp.estado);
				strcpy(cad[i].end.cep,cad_bkp[i].end_bkp.cep);
				cad[i].altura = cad_bkp[i].altura;
				ver_bkp++;/* contador para verificar se existe backup	*/
		}			
		printf("\t\t\tBackup Restaurado! ");
	}else{
		printf("\t\t\tNao existe Backup para restauracao, operacao nao realizada. ");
	}		
		printf("\n\tLog:\n", cad_bkp[i].idUsuario);//imprime uma lista de Id's que foram restaurados//
	for(i = 0; i < cont; i++){	
		
		if(cad[i].idUsuario!= 0 && ver_bkp!= 0 ){						
			printf("\n\tID Usuario...........................................: %i", cad_bkp[i].idUsuario);
			/*printf("\tNome.................................................: %s\n", bkp_nome[i]);
			printf("\tEmail cadastrado.....................................: %s",bkp_eMail[i]);
			printf("\n\tSexo.................................................: %s\n", bkp_sexo[i]);
			printf("\tTomou vacina?........................................: ");
			
			if(bkp_vacina[i] == 1){
				printf("SIM\n");
			}else if(bkp_vacina[i] == 2){
				printf("NAO\n");
				}else{
					printf(" \n");		
				}	
			printf("\tEndereco.............................................: %s\n", bkp_endereco[i]);
			printf("\tAltura...............................................:  %.2f", bkp_altura[i]);*/
				
		}
	}
	printf("\n\n");
}