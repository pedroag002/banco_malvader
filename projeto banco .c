#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{//data de nascimento
	int dia;
	int mes;
	int ano;
}Data;

typedef struct{//endereco
	int cep;
	int numerocasa;
	char rua[100];
	char bairro[50];
	char cidade[50];
	char estado[50];
	char logradouro[50];
}End;

typedef struct{//transacoes
	char tipo;
	float deposito;
	float saque;
}Trans;

typedef struct{//conta poupanca
	char numconta[20];
	char agencia[6];
	float saldo; 
	int limite;
	char codigo[3];
	char datavencdia[5];
	char datavencmes[5];
	char datavencano[5];
	Trans trans;
}Contacp;

typedef struct{//conta corrente
	char numconta[20];
	char agencia[6];	
	int limite;
	char datavencdia[5];
	char datavencmes[5];
	char datavencano[5];
	float saldo;
	char codigo[3];
	Trans trans;
}Contacc;

typedef struct{//cliente
	char nomecliente[50];
	char cpf[12];
	char telefone[15];
	char senha[7];
	Data nasc;
	End endereco;
	Contacp contacp;
	Contacc contacc;
}Cliente;

typedef struct{//funcionario
	char codigo[20];
	char cargo[100];
	char nome[50];
	char cpf[12];
	char telefone[15];
	Data nasc;
	End endereco;
}Funcionario;

void cadastrarcontacorrente(){ //insere os dados da conta poupanca                                           
	Contacc contacc;
	Cliente cliente;
	cliente.contacc.saldo=0;
	int k;
	FILE *arqcc;
	arqcc=fopen("contascc.txt","a+b");
	if(arqcc==NULL){
		printf("ERRO AO ABRIR O ARQUIVO");
		system("pause");
		return;
	}
		system("cls");
		printf("+--------------------------+\n");
		printf("| CADASTRAR CONTA CORRENTE |\n");
		printf("+--------------------------+\n\n");
		
		printf("INSIRA O NUMERO DA AGENCIA: \n");
		fflush(stdin);
		fgets(cliente.contacc.agencia, 6 , stdin);
    	cliente.contacc.agencia[strcspn(cliente.contacc.agencia, "\n")] = '\0';
    	
    	printf("INSIRA O NUMERO DA CONTA: \n");
		fflush(stdin);
		fgets(cliente.contacc.numconta, 20 , stdin);
    	cliente.contacc.numconta[strcspn(cliente.contacc.numconta, "\n")] = '\0';
		
		printf("INSIRA A DATA DE VENCIMENTO DA CONTA: \n");
    	printf("DIA: ");
    	fflush(stdin);
		fgets(cliente.contacc.datavencdia, 5 , stdin);
    	cliente.contacc.datavencdia[strcspn(cliente.contacc.datavencdia, "\n")] = '\0';
    	
    	printf("MES: ");
    	fflush(stdin);
    	fgets(cliente.contacc.datavencmes, 5 , stdin);
    	cliente.contacc.datavencmes[strcspn(cliente.contacc.datavencmes, "\n")] = '\0';
    	
    	printf("ANO: ");
    	fflush(stdin);
    	fgets(cliente.contacc.datavencano, 5 , stdin);
    	cliente.contacc.datavencano[strcspn(cliente.contacc.datavencano, "\n")] = '\0';
		
		printf("INSIRA O LIMITE DA CONTA: \n");
		fflush(stdin);
		scanf("%d",&cliente.contacc.limite);
		
		printf("INSIRA O NOME DO CLIENTE: \n");
		fflush(stdin);
		fgets(cliente.nomecliente, 50 , stdin);
    	cliente.nomecliente[strcspn(cliente.nomecliente, "\n")] = '\0';
		
		printf("INSIRA A SENHA DO CLIENTE: \n");
		fflush(stdin);
		fgets(cliente.senha, 7 , stdin);
    	cliente.senha[strcspn(cliente.senha, "\n")] = '\0';
		
		printf("INSIRA O CPF DO CLIENTE: \n");
		fflush(stdin);
		fgets(cliente.cpf, 12 , stdin);
    	cliente.cpf[strcspn(cliente.cpf, "\n")] = '\0';
		
		printf("INSIRA O NUMERO DE TELEFONE: \n");
		fflush(stdin);
		fgets(cliente.telefone, 15 , stdin);
    	cliente.telefone[strcspn(cliente.telefone, "\n")] = '\0';
		
		printf("INSIRA A DATA DE NASCIMENTO DIA/MES/ANO \n");
		fflush(stdin);
		scanf("%d %d %d",&cliente.nasc.dia,&cliente.nasc.mes,&cliente.nasc.ano);
		
		printf("endereco: \n");
		
		printf("CEP: ");
		scanf("%d",&cliente.endereco.cep);
		fflush(stdin);
		getchar();
		
		printf("ESTADO: ");
		fflush(stdin);
		fgets(cliente.endereco.estado, 50 , stdin);
    	cliente.endereco.estado[strcspn(cliente.endereco.estado, "\n")] = '\0';
		
		printf("CIDADE: ");
		fflush(stdin);
		fgets(cliente.endereco.cidade, 50 , stdin);
    	cliente.endereco.cidade[strcspn(cliente.endereco.cidade, "\n")] = '\0';
		
		printf("BAIRRO: ");
		fflush(stdin);
		fgets(cliente.endereco.bairro, 50 , stdin);
    	cliente.endereco.bairro[strcspn(cliente.endereco.bairro, "\n")] = '\0';
		
		printf("LOGRADOURO: ");
		fflush(stdin);
		fgets(cliente.endereco.logradouro, 50 , stdin);
    	cliente.endereco.logradouro[strcspn(cliente.endereco.logradouro, "\n")] = '\0';
    	
    	printf("RUA: ");
    	fflush(stdin);
		fgets(cliente.endereco.rua, 100, stdin);
    	cliente.endereco.rua[strcspn(cliente.endereco.rua, "\n")] = '\0';
		
		printf("numero da casa: ");
		scanf("%d",&cliente.endereco.numerocasa);
		
		fwrite(&cliente,sizeof(cliente),1,arqcc);
		if(ferror(arqcc)){
			printf("\nERRO NA GRAVACAO\n");
		}else{
			printf("GRAVACAO OK \n");	
			}	
	fclose(arqcc);
	system("pause");	
}

void cadastrarcontapoupanca(){ //insere os dados da conta poupanca 													
	Contacp contacp;
	Cliente cliente;
	cliente.contacp.saldo=0;
	int j;
	FILE *arqcp;
	arqcp=fopen("contascp.txt","a+b");
	if(arqcp==NULL){
	printf("ERRO AO ABRIR O ARQUIVO");
	system("pause");
	return;
	}
	
		system("cls");
		printf("+--------------------------+\n");
		printf("| CADASTRAR CONTA POUPANCA |\n");
		printf("+--------------------------+\n\n");
		
		printf("INSIRA O NUMERO DA AGENCIA: \n");
		fflush(stdin);
    	fgets(cliente.contacp.agencia, 6 , stdin);
    	cliente.contacp.agencia[strcspn(cliente.contacp.agencia, "\n")] = '\0';
		
		printf("INSIRA O NUMERO DA CONTA: \n");
		fflush(stdin);
    	fgets(cliente.contacp.numconta, 20 , stdin);
    	cliente.contacp.numconta[strcspn(cliente.contacp.numconta, "\n")] = '\0';
    	
    	printf("INSIRA A DATA DE VENCIMENTO DA CONTA: \n");
    	printf("DIA: ");
    	fflush(stdin);
		fgets(cliente.contacp.datavencdia, 5 , stdin);
    	cliente.contacp.datavencdia[strcspn(cliente.contacp.datavencdia, "\n")] = '\0';
    	
    	printf("MES: ");
    	fflush(stdin);
    	fgets(cliente.contacp.datavencmes, 5 , stdin);
    	cliente.contacp.datavencmes[strcspn(cliente.contacp.datavencmes, "\n")] = '\0';
    	
    	printf("ANO: ");
    	fflush(stdin);
    	fgets(cliente.contacp.datavencano, 5 , stdin);
    	cliente.contacp.datavencano[strcspn(cliente.contacp.datavencano, "\n")] = '\0';
    	
		printf("INSIRA O LIMITE DA CONTA: \n");
		fflush(stdin);
		scanf("%d",&cliente.contacp.limite);
		
		printf("INSIRA O NOME DO CLIENTE: \n");
		fflush(stdin);
    	fgets(cliente.nomecliente, 50 , stdin);
    	cliente.nomecliente[strcspn(cliente.nomecliente, "\n")] = '\0';
		
		printf("INSIRA A SENHA DO CLIENTE: \n");
		fflush(stdin);
   	 	fgets(cliente.senha, 7, stdin);
    	cliente.senha[strcspn(cliente.senha, "\n")] = '\0';
		
		printf("INSIRA O CPF DO CLIENTE: \n");
		fflush(stdin);
    	fgets(cliente.cpf, 12 , stdin);
    	cliente.cpf[strcspn(cliente.cpf, "\n")] = '\0';
		
		printf("INSIRA O NUMERO DE TELEFONE DO CLIENTE: \n");
		fflush(stdin);
   		fgets(cliente.telefone, 15 , stdin);
    	cliente.telefone[strcspn(cliente.telefone, "\n")] = '\0';
		
		printf("INSIRA A DATA DE NASCIMENTO DO CLIENTE: \n");
		printf("DIA: ");
		scanf("%d",&cliente.nasc.dia);
		
		printf("MES: ");
		scanf("%d",&cliente.nasc.mes);
		
		printf("ANO: ");
		scanf("%d",&cliente.nasc.ano);
		
		printf("INSIRA O ENDERECO DO CLIENTE: \n");
		
		printf("CEP: ");
		fflush(stdin);
		scanf("%d",&cliente.endereco.cep);
		
		printf("ESTADO: ");
		fflush(stdin);
    	fgets(cliente.endereco.estado, 50 , stdin);
    	cliente.endereco.estado[strcspn(cliente.endereco.estado, "\n")] = '\0';
		
		printf("CIDADE: ");
		fflush(stdin);
    	fgets(cliente.endereco.cidade, 50 , stdin);
    	cliente.endereco.cidade[strcspn(cliente.endereco.cidade, "\n")] = '\0';
		
		printf("BAIRRO: ");
		fflush(stdin);
    	fgets(cliente.endereco.bairro, 50 , stdin);
    	cliente.endereco.bairro[strcspn(cliente.endereco.bairro, "\n")] = '\0';
		
		printf("LOGRADOURO: ");
		fflush(stdin);
    	fgets(cliente.endereco.logradouro, 50 , stdin);
    	cliente.endereco.logradouro[strcspn(cliente.endereco.logradouro, "\n")] = '\0';
		
		printf("RUA: ");
		fflush(stdin);
    	fgets(cliente.endereco.rua, 100 , stdin);
    	cliente.endereco.rua[strcspn(cliente.endereco.rua, "\n")] = '\0';
		
		printf("NUMERO DA CASA: ");
		scanf("%d",&cliente.endereco.numerocasa);
		
		fwrite(&cliente,sizeof(cliente),1,arqcp);
		if(ferror(arqcp)){
		printf("\nERRO NA GRAVACAO\n");
		}else{
			printf("GRAVACAO OK\n\n");
			}
	fclose(arqcp);
	system("pause");		
}

void cadastrarfuncionarios(){//cadastra os dados dos funcionarios 
	Funcionario funcionario;
	int j;
	FILE *arqfunc;
	arqfunc=fopen("funcionarios.txt","a+b");
	if(arqfunc==NULL){
	printf("ERRO AO ABRIR O ARQUIVO");
	}
	
	system("cls");
	printf("+-----------------------+\n");
	printf("| CADASTRAR FUNCIONARIO |\n");
	printf("+-----------------------+\n\n");
		
	printf("insira o codigo do funcionario: \n");
	fflush(stdin);
	fgets(funcionario.codigo, 20 , stdin);
	funcionario.codigo[strcspn(funcionario.codigo, "\n")] = '\0';
			
	printf("insira o cargo do funcionario: \n");
	fflush(stdin);
	fgets(funcionario.cargo, 100 , stdin);
	funcionario.cargo[strcspn(funcionario.cargo, "\n")] = '\0';
			
	printf("insira o nome do funcionario: \n");
	fflush(stdin);
	fgets(funcionario.nome, 50 , stdin);
	funcionario.nome[strcspn(funcionario.nome, "\n")] = '\0';
			
	printf("insira o CPF do funcionario: \n");
	fflush(stdin);
	fgets(funcionario.cpf, 12 , stdin);
	funcionario.cpf[strcspn(funcionario.cpf, "\n")] = '\0';
			
	printf("insira a data de nascimento do funcionario DIA/MES/ANO \n");
	scanf("%d %d %d",&funcionario.nasc.dia,&funcionario.nasc.mes,&funcionario.nasc.ano);
			
	printf("insira o numero do telefone do funcionario: \n");
	fflush(stdin);
	fgets(funcionario.telefone, 15 , stdin);
	funcionario.telefone[strcspn(funcionario.telefone, "\n")] = '\0';
			
	printf("insira o endereco do funcionario: \n");
		
	printf("CEP: \n");
	scanf("%d",&funcionario.endereco.cep);
		
	printf("estado: \n");
	fflush(stdin);
	fgets(funcionario.endereco.estado, 50 , stdin);
	funcionario.endereco.estado[strcspn(funcionario.endereco.estado, "\n")] = '\0';
		
	printf("cidade: \n");
	fflush(stdin);
	fgets(funcionario.endereco.cidade, 50 , stdin);
	funcionario.endereco.cidade[strcspn(funcionario.endereco.cidade, "\n")] = '\0';
		
	printf("bairro: \n");
	fflush(stdin);
	fgets(funcionario.endereco.bairro, 50 , stdin);
	funcionario.endereco.bairro[strcspn(funcionario.endereco.bairro, "\n")] = '\0';
		
	printf("logradouro: \n");
	fflush(stdin);
	fgets(funcionario.endereco.logradouro, 50 , stdin);
	funcionario.endereco.logradouro[strcspn(funcionario.endereco.logradouro, "\n")] = '\0';
		
	printf("RUA: \n");
	fflush(stdin);
	fgets(funcionario.endereco.rua, 50 , stdin);
	funcionario.endereco.rua[strcspn(funcionario.endereco.rua, "\n")] = '\0';
			
	printf("numero da casa: \n");
	scanf("%d",&funcionario.endereco.numerocasa);
			
	fwrite(&funcionario,sizeof(funcionario),1,arqfunc);
		
	if(ferror(arqfunc)){
		printf("\nERRO NA GRAVACAO\n");
	}else{
		printf("GRAVACAO OK\n\n");
		}
	
	fclose(arqfunc);	
	system("pause");				
}

void consultarcontascp(){//imprime as informacoes das contas poupancas 
	char numconta[20];
	Contacp contacp;
	Cliente cliente;
	FILE *arqcp;
	int encontrada=0;
	arqcp=fopen("contascp.txt","rb");
	if(arqcp==NULL){
	printf("ERRO AO ABRIR O ARQUIVO");
	}
	
	printf("DIGITE O NUMERO DA CONTA A SER CONSULTADA: ");
	fflush(stdin);	
	fgets(numconta, 20, stdin);
    numconta[strcspn(numconta, "\n")] = '\0';
		
	while(fread(&cliente,sizeof(Cliente),1,arqcp) == 1){
		if(strcmp(numconta,cliente.contacp.numconta)==0){
			encontrada=1;
			printf("CONTA-POUPANCA \n");
			printf("AGENCIA: %s \n",cliente.contacp.agencia);
			printf("NUMERO DA CONTA: %s \n",cliente.contacp.numconta);
			printf("SALDO: %.2f \n",cliente.contacp.saldo);
			printf("LIMITE: %d \n",cliente.contacp.limite);
			printf("DATA DE VENCIMENTO: %s/%s/%s \n",cliente.contacp.datavencdia,cliente.contacp.datavencmes,cliente.contacp.datavencano);
			printf("NOME: %s \n",cliente.nomecliente);
			printf("SENHA: %s \n",cliente.senha);
			printf("CPF: %s \n",cliente.cpf);
			printf("TELEFONE: %s \n",cliente.telefone);
			printf("DATA DE NASCIMENTO: %d/%d/%d \n",cliente.nasc.dia,cliente.nasc.mes,cliente.nasc.ano);
			printf("endereco: \n");
			printf("CEP: %d \n",cliente.endereco.cep);
			printf("ESTADO: %s \n",cliente.endereco.estado);
			printf("CIDADE: %s \n",cliente.endereco.cidade);
			printf("BAIRRO: %s \n",cliente.endereco.bairro);
			printf("LOGRADOURO: %s \n",cliente.endereco.logradouro);
			printf("RUA: %s \n",cliente.endereco.rua);
			printf("NUMERO DA CASA: %d \n",cliente.endereco.numerocasa);
			printf("---------------------------------------------------\n\n");	
			}
		}
		
	if(!encontrada){
		printf("CONTA NAO ENCONTRADA. \n\n");
	}
	fclose(arqcp);
	system("pause");
}

void consultarcontascc(){//imprime as informacoes das contas correntes       
	char numconta[20];
	Contacc contacc;
	Cliente cliente;	
	FILE *arqcc;
	int encontrada=0;
	arqcc=fopen("contascc.txt","rb");
	if(arqcc==NULL){
	printf("ERRO AO ABRIR O ARQUIVO");
	}
	
	printf("DIGITE O NUMERO DA CONTA A SER CONSULTADA: ");
	fflush(stdin);
	fgets(numconta, 20, stdin);
    numconta[strcspn(numconta, "\n")] = '\0';
		
	while(fread(&cliente,sizeof(Cliente),1,arqcc) == 1){
		if(strcmp(numconta,cliente.contacc.numconta)==0){
			encontrada=1;
			printf("CONTA-CORRENTE\n");
			printf("AGENCIA: %s \n",cliente.contacc.agencia);
			printf("NUMERO DA CONTA: %s \n",cliente.contacc.numconta);
			printf("DATA DE VENCIMENTO DA CONTA: %s/%s/%s \n",cliente.contacc.datavencdia,cliente.contacc.datavencmes,cliente.contacc.datavencano);
			printf("NOME: %s \n",cliente.nomecliente);
			printf("SENHA: %s \n",cliente.senha);
			printf("SALDO: %.2f \n",cliente.contacc.saldo);
			printf("LIMITE: %d \n",cliente.contacc.limite);
			printf("CPF: %s \n",cliente.cpf);
			printf("TELEFONE: %s \n",cliente.telefone);
			printf("DATA DE NASCIMENTO: %d/%d/%d \n",cliente.nasc.dia,cliente.nasc.mes,cliente.nasc.ano);
			printf("ENDERECO: \n");
			printf("CEP: %d \n",cliente.endereco.cep);
			printf("ESTADO: %s \n",cliente.endereco.estado);
			printf("CIDADE: %s \n",cliente.endereco.cidade);
			printf("BAIRRO: %s \n",cliente.endereco.bairro);
			printf("LOGRADOURO: %s \n",cliente.endereco.logradouro);
			printf("RUA: %s \n",cliente.endereco.rua);
			printf("NUMERO DA CASA: %d \n",cliente.endereco.numerocasa);
			printf("---------------------------------------------------\n\n");
			}		
		}
	if(!encontrada){
		printf("CONTA NAO ENCONTRADA.\n\n");
	}	
	fclose(arqcc);
	system("pause");
}

void consultarfuncionario(){//consulta funcionario 
	Funcionario funcionario;
	char codfunc[20];
	FILE *arqfunc;
	arqfunc=fopen("funcionarios.txt","rb");
	if(arqfunc==NULL){
	printf("ERRO AO ABRIR O ARQUIVO");
	}
	
	printf("DIGITE O NUMERO DA CONTA A SER CONSULTADA: ");
	fflush(stdin);
	fgets(codfunc, 20, stdin);
    codfunc[strcspn(codfunc, "\n")] = '\0';
		
	while(fread(&funcionario,sizeof(funcionario),1,arqfunc)==1){
		if(strcmp(codfunc,funcionario.codigo)==0){
			printf("CODIGO DO FUNCIONARIO: %s \n",funcionario.codigo);
			printf("CARGO: %s \n",funcionario.cargo);
			printf("NOME: %s \n",funcionario.nome);
			printf("CPF: %s \n",funcionario.cpf);
			printf("DATA DE NASCIMENTO: %d/%d/%d \n",funcionario.nasc.dia,funcionario.nasc.mes,funcionario.nasc.ano);
			printf("TELEFONE: %s \n",funcionario.telefone);
			printf("endereco: \n");
			printf("CEP: %d \n",funcionario.endereco.cep);
			printf("ESTADO: %s \n",funcionario.endereco.estado);
			printf("CIDADE: %s \n",funcionario.endereco.cidade);
			printf("BAIRRO: %s \n",funcionario.endereco.bairro);
			printf("LOGRADOURO: %s \n",funcionario.endereco.logradouro);
			printf("NUMERO DA CASA: %d \n",funcionario.endereco.numerocasa);
			printf("RUA: %s \n",funcionario.endereco.rua);
			printf("----------------------------------------------------\n");
		}
	}
	fclose(arqfunc);
	system("pause");
}

void consultarcliente(){//consulta as informacoes dos clientes  
	Contacc contacc;
	Contacp contacp;
	Cliente cliente;
	FILE *arqcp;
	FILE *arqcc;
	char nomecliente[50];
	
	arqcc=fopen("contascc.txt","rb");
	if(arqcc==NULL){
	printf("ERRO AO ABRIR O ARQUIVO");
	system("pause");
	return;
	}
		
	arqcp=fopen("contascp.txt","rb");
	if(arqcp==NULL){
		printf("ERRO AO ABRIR O ARQUIVO");
		system("pause");
		return;
	}	
		
	printf("digite o nome do cliente: ");
	fflush(stdin);
	fgets(nomecliente, 50, stdin);
    nomecliente[strcspn(nomecliente, "\n")] = '\0';
		
	while(fread(&cliente,sizeof(Cliente),1,arqcc)==1){
		if(strcmp(nomecliente,cliente.nomecliente)==0){
			printf("cliente: %s \n",cliente.nomecliente);
			printf("cpf: %s \n",cliente.cpf);
			printf("data de nascimento: %d/%d/%d \n",cliente.nasc.dia,cliente.nasc.mes,cliente.nasc.ano);
			printf("telefone: %s \n",cliente.telefone);
			printf("endereco: \n");
			printf("CEP: %d \n",cliente.endereco.cep);
			printf("ESTADO: %s \n",cliente.endereco.estado);
			printf("CIDADE: %s \n",cliente.endereco.cidade);
			printf("BAIRRO: %s \n",cliente.endereco.bairro);
			printf("LOGRADOURO: %s \n",cliente.endereco.logradouro);
			printf("RUA: %s \n",cliente.endereco.rua);
			printf("NUMERO DA CASA: %d \n",cliente.endereco.numerocasa);
			printf("----------------------------------------------------\n");
		}
		
	}
	
	while(fread(&cliente,sizeof(Cliente),1,arqcp)==1){
		if(strcmp(nomecliente,cliente.nomecliente)==0){
			printf("cliente: %s \n",cliente.nomecliente);
			printf("cpf: %s \n",cliente.cpf);
			printf("data de nascimento: %d/%d/%d \n",cliente.nasc.dia,cliente.nasc.mes,cliente.nasc.ano);
			printf("telefone: %s \n",cliente.telefone);
			printf("endereco: \n");
			printf("CEP: %d \n",cliente.endereco.cep);
			printf("ESTADO: %s \n",cliente.endereco.estado);
			printf("CIDADE: %s \n",cliente.endereco.cidade);
			printf("BAIRRO: %s \n",cliente.endereco.bairro);
			printf("LOGRADOURO: %s \n",cliente.endereco.logradouro);
			printf("RUA: %s \n",cliente.endereco.rua);
			printf("NUMERO DA CASA: %d \n",cliente.endereco.numerocasa);
			printf("----------------------------------------------------\n");
		}
		
	}
	fclose(arqcc);
	fclose(arqcp);
	system("pause");
}

void excluircontacorrente(){//exclui contas correntes
    int senhaadm = 54321;
    int senha3;
    char numconta[20];
    int found = 0;
    Contacc contacc;
    Cliente cliente;
    
    printf("DIGITE A SENHA DO ADMINISTRADOR PARA ACESSAR O MENU: \n");
    scanf("%d", &senha3);
    if (senhaadm != senha3) {
        printf("***ACESSO NEGADO***\n");
        return;
    }
	printf("***ACESSO PERMITIDO***\n\n");

    printf("DIGITE O NUMERO DA CONTA A SER EXCLUIDA: ");
    fflush(stdin);
    fgets(numconta, 20, stdin);
    numconta[strcspn(numconta, "\n")] = '\0';

    FILE *arqcc = fopen("contascc.txt", "rb");
    if (arqcc == NULL) {
        printf("ERRO AO EXCLUIR CONTA, CRIE UMA CONTA PRIMEIRO. \n\n");
        system("pause");
        return;
    }

    FILE *tempArqcc = fopen("temp_contascc.txt", "wb");
    if (tempArqcc == NULL) {
        printf("ERRO AO CRIAR ARQUIVO TEMPOR�RIO\n");
        fclose(arqcc);
        system("pause");
        return;
    }

    while(fread(&cliente, sizeof(cliente), 1, arqcc)){
        if(strcmp(numconta,cliente.contacc.numconta)==0){
            found = 1;
        }else{
            fwrite(&cliente, sizeof(cliente), 1, tempArqcc);
        }
    } 

    fclose(arqcc);
    fclose(tempArqcc);

    if (!found) {
        printf("CONTA NAO ENCONTRADA.\n");
        remove("temp_contascc.txt");
    } else {
        remove("contascc.txt");
        rename("temp_contascc.txt", "contascc.txt");
        printf("CONTA EXCLUIDA COM SUCESSO.\n");	
    }
    system("pause");
}

void excluircontapoupanca(){//exclui contas poupancas
    int senhaadm = 54321;
    int senha3;
    char numconta[20];
    int found = 0;
    Contacp contacp;
    Cliente cliente;
    
    printf("DIGITE A SENHA DO ADMINISTRADOR PARA ACESSAR O MENU: \n");
    scanf("%d", &senha3);
    if (senhaadm != senha3) {
        printf("***ACESSO NEGADO***\n");
        return;
    }
	printf("***ACESSO PERMITIDO***\n\n");

    printf("DIGITE O NUMERO DA CONTA A SER EXCLUIDA: ");
    fflush(stdin);
    fgets(numconta, 20, stdin);
    numconta[strcspn(numconta, "\n")] = '\0';

    FILE *arqcp = fopen("contascp.txt", "rb");
    if (arqcp == NULL) {
        printf("ERRO AO EXCLUIR CONTA, CRIE UMA CONTA PRIMEIRO. \n\n");
        system("pause");
        return;
    }

    FILE *tempArqcp = fopen("temp_contascp.txt", "wb");
    if (tempArqcp == NULL) {
        printf("ERRO AO CRIAR ARQUIVO TEMPOR�RIO\n");
        fclose(arqcp);
        system("pause");
        return;
    }

    while(fread(&cliente, sizeof(cliente), 1, arqcp)){
        if(cliente.contacp.numconta[20] == numconta[20]){
            found = 1;
        }else{
            fwrite(&cliente, sizeof(cliente), 1, tempArqcp);
        }
    } 

    fclose(arqcp);
    fclose(tempArqcp);

    if(!found){
        printf("CONTA NAO ENCONTRADA.\n");
        remove("temp_contascp.txt");
    }else{
        remove("contascp.txt");
        rename("temp_contascp.txt", "contascp.txt");
        printf("CONTA EXCLUIDA COM SUCESSO.\n");
    }
    system("pause");
}

void alterartipocontacp(){//altera conta poupanca para corrente
    int senhaadm = 54321;
    int senha3;
    char numconta[20];
    int found = 0;
    Contacp contacp;
    Cliente cliente;
    Contacc contacc;
    
    printf("DIGITE A SENHA DO ADMINISTRADOR PARA ACESSAR O MENU: \n");
    scanf("%d", &senha3);
    if (senhaadm != senha3) {
        printf("***ACESSO NEGADO***\n");
        return;
    }
    
    printf("***ACESSO PERMITIDO***\n\n");
    
    FILE *arqcp = fopen("contascp.txt", "r+b");
    if (arqcp == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO\n");
        system("pause");
        return;
    }
    
    FILE *arqcc = fopen("contascc.txt", "ab");
    if (arqcc == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO\n");
        system("pause");
        return;
    }

	printf("Digite o numero da conta a ser alterada: ");
    fflush(stdin);
    fgets(numconta, sizeof(numconta), stdin);
    numconta[strcspn(numconta, "\n")] = '\0';

    while(fread(&cliente, sizeof(Cliente), 1, arqcp)){
        if(strcmp(cliente.contacp.numconta,numconta)==0){
            found = 1;
            break;
        }
    }

	if(!found){
        printf("Conta n�o encontrada.\n");
        fclose(arqcc);
        system("pause");
        return;
    }

    fseek(arqcp, -(long int)sizeof(cliente), SEEK_CUR);
	
 	strcpy(cliente.contacc.agencia,cliente.contacp.agencia);
    strcpy(cliente.contacc.numconta,cliente.contacp.numconta);
    strcpy(cliente.contacc.datavencdia,cliente.contacp.datavencdia);
    strcpy(cliente.contacc.datavencmes,cliente.contacp.datavencmes);
    strcpy(cliente.contacc.datavencano,cliente.contacp.datavencano);
    cliente.contacc.saldo=cliente.contacp.saldo;
    cliente.contacc.limite=cliente.contacp.limite;
    
    fwrite(&cliente, sizeof(Cliente), 1, arqcc);
    if(ferror(arqcc)){
        printf("\nERRO NA GRAVACAO\n");
    }else{
        printf("CONTA ALTERADA COM SUCESSO\n");
    }
	
	fclose(arqcc);
	
	FILE *tempArqcp = fopen("temp_contascp.txt", "w");
    if (tempArqcp == NULL) {
        printf("ERRO AO CRIAR ARQUIVO TEMPOR�RIO\n");
        fclose(arqcp);
        return;
    }

    while(fread(&cliente, sizeof(Cliente), 1, arqcp)){
        if(strcmp(numconta,cliente.contacc.numconta)==0){
            found = 1;
        }else{
            fwrite(&cliente, sizeof(Cliente), 1, tempArqcp);
        }
    } 
    
    fclose(tempArqcp);
    fclose(arqcp);
    
    if (!found) {
        remove("temp_contascp.txt");
    } else {
        remove("contascp.txt");
        rename("temp_contascp.txt", "contascp.txt");
    }
}

void alterardadoscontacp(){//altera dados da conta poupanca
	int senhaadm = 54321;
    int senha3;
    char numconta[20];
    int found = 0;
    Contacp contacp;
    Cliente cliente;
    
    printf("DIGITE A SENHA DO ADMINISTRADOR PARA ACESSAR O MENU: \n");
    scanf("%d", &senha3);
    if (senhaadm != senha3) {
        printf("***ACESSO NEGADO***\n");
        return;
    }
    
    printf("***ACESSO PERMITIDO***\n\n");
    
    FILE *arqcp = fopen("contascp.txt", "r+b");
    if (arqcp == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO\n");
        system("pause");
        return;
    }
    
	printf("Digite o numero da conta a ser alterada: ");
    fflush(stdin);
    fgets(numconta, sizeof(numconta), stdin);
    numconta[strcspn(numconta, "\n")] = '\0';

    while(fread(&cliente, sizeof(Cliente), 1, arqcp)){
        if(strcmp(cliente.contacp.numconta,numconta)==0){
            found = 1;
            break;
        }
    }

	if(!found){
        printf("Conta n�o encontrada.\n");
        fclose(arqcp);
        system("pause");
        return;
    }

    fseek(arqcp, -(long int)sizeof(cliente), SEEK_CUR);

    printf("INSIRA OS DADOS NOVOS DA CONTA:\n\n");
    
    printf("INSIRA O LIMITE DISPONIVEL: \n");
    scanf("%d",&cliente.contacp.limite);
    
    printf("INSIRA A DATA DE VENCIMENTO DA CONTA: \n");
   	printf("DIA: ");
    fflush(stdin);
	fgets(cliente.contacp.datavencdia, 2 , stdin);
    cliente.contacp.datavencdia[strcspn(cliente.contacp.datavencdia, "\n")] = '\0';
    	
    printf("MES: ");
    fflush(stdin);
    fgets(cliente.contacp.datavencmes, 2 , stdin);
    cliente.contacp.datavencmes[strcspn(cliente.contacp.datavencmes, "\n")] = '\0';
    	
    printf("ANO: ");
    fflush(stdin);
    fgets(cliente.contacp.datavencano, 4 , stdin);
    cliente.contacp.datavencano[strcspn(cliente.contacp.datavencano, "\n")] = '\0';
  
    fwrite(&cliente, sizeof(Cliente), 1, arqcp);
    if(ferror(arqcp)){
        printf("\nERRO NA GRAVACAO\n");
    }else{
        printf("CONTA ALTERADA COM SUCESSO\n");
    }
	fclose(arqcp);
	system("pause");
}

void alterardadoscontacc(){//altera os dados das contas correntes
    int senhaadm = 54321;
    int senha3;
    char numconta[20];
    int found = 0;
    Contacc contacc;
    Cliente cliente;
    Contacp contacp;
    
    printf("DIGITE A SENHA DO ADMINISTRADOR PARA ACESSAR O MENU: \n");
    scanf("%d", &senha3);
    if (senhaadm != senha3) {
        printf("***ACESSO NEGADO***\n");
        return;
    }
    
    printf("***ACESSO PERMITIDO***\n\n");

    FILE *arqcc = fopen("contascc.txt", "r+b");
    if (arqcc == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO\n");
        system("pause");
        return;
    }

	printf("DIGITE O NUMERO DA CONTA A SER ALTERADA: ");
    fflush(stdin);
    fgets(numconta, sizeof(numconta), stdin);
    numconta[strcspn(numconta, "\n")] = '\0';

    while(fread(&cliente, sizeof(Cliente), 1, arqcc)){
        if(strcmp(cliente.contacc.numconta,numconta)==0){
            found = 1;
            break;
        }
    }

	if(!found){
        printf("Conta n�o encontrada.\n");
        fclose(arqcc);
        system("pause");
        return;
    }

    fseek(arqcc, -(long int)sizeof(Cliente), SEEK_CUR);

    printf("INSIRA OS DADOS NOVOS DA CONTA:\n\n");
    printf("INSIRA O LIMITE DISPONIVEL: \n");
    scanf("%d",&cliente.contacc.limite);
    
    printf("INSIRA A DATA DE VENCIMENTO DA CONTA: \n");
    printf("DIA: ");
    fflush(stdin);
	fgets(cliente.contacc.datavencdia, 2 , stdin);
    cliente.contacc.datavencdia[strcspn(cliente.contacc.datavencdia, "\n")] = '\0';
    	
    printf("MES: ");
   	fflush(stdin);
   	fgets(cliente.contacc.datavencmes, 2 , stdin);
    cliente.contacc.datavencmes[strcspn(cliente.contacc.datavencmes, "\n")] = '\0';
    	
    printf("ANO: ");
    fflush(stdin);
    fgets(cliente.contacc.datavencano, 4 , stdin);
    cliente.contacc.datavencano[strcspn(cliente.contacc.datavencano, "\n")] = '\0';
    
    fwrite(&cliente, sizeof(Cliente), 1, arqcc);
    if (ferror(arqcc)) {
        printf("\nERRO NA GRAVACAO\n");
    } else {
        printf("DADOS ALTERADOS COM SUCESSO\n");
    }
	fclose(arqcc);
	system("pause");
}

void alterartipocontacc(){//altera conta corrente para poupanca
    int senhaadm = 54321;
    int senha3;
    char numconta[20];
    int found = 0;
    Contacc contacc;
    Cliente cliente;
    Contacp contacp;
    
    printf("DIGITE A SENHA DO ADMINISTRADOR PARA ACESSAR O MENU: \n");
    scanf("%d", &senha3);
    if (senhaadm != senha3) {
        printf("***ACESSO NEGADO***\n");
        return;
    }
    
    printf("***ACESSO PERMITIDO***\n\n");

    FILE *arqcc = fopen("contascc.txt", "r+b");
    if (arqcc == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO\n");
        system("pause");
        return;
    }
    
    FILE *arqcp = fopen("contascp.txt", "ab");
    if (arqcp == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO\n");
        system("pause");
        return;
    }

	printf("DIGITE O NUMERO DA CONTA A SER ALTERADA: ");
    fflush(stdin);
    fgets(numconta, sizeof(numconta), stdin);
    numconta[strcspn(numconta, "\n")] = '\0';

    while(fread(&cliente, sizeof(Cliente), 1, arqcc)){
        if(strcmp(cliente.contacc.numconta,numconta)==0){
            found = 1;
            break;
        }
    }

	if(!found){
        printf("Conta n�o encontrada.\n");
        fclose(arqcc);
        system("pause");
        return;
    }

    fseek(arqcc, -(long int)sizeof(Cliente), SEEK_CUR);

    strcpy(cliente.contacp.agencia,cliente.contacc.agencia);
    strcpy(cliente.contacp.numconta,cliente.contacc.numconta);
    strcpy(cliente.contacp.datavencdia,cliente.contacc.datavencdia);
    strcpy(cliente.contacp.datavencmes,cliente.contacc.datavencmes);
    strcpy(cliente.contacp.datavencano,cliente.contacc.datavencano);
    cliente.contacp.saldo=cliente.contacc.saldo;
    cliente.contacp.limite=cliente.contacc.limite;

    
    fwrite(&cliente, sizeof(Cliente), 1, arqcp);
    if (ferror(arqcp)) {
        printf("\nERRO NA GRAVACAO\n");
    } else {
        printf("GRAVACAO OK\n");
    }
	fclose(arqcp);
	
	FILE *tempArqcc = fopen("temp_contascc.txt", "w");
    if (tempArqcc == NULL) {
        printf("ERRO AO CRIAR ARQUIVO TEMPOR�RIO\n");
        fclose(arqcc);
        return;
    }

    while(fread(&cliente, sizeof(Cliente), 1, arqcc)){
        if(strcmp(numconta,cliente.contacc.numconta)==0){
            found = 1;
        }else{
            fwrite(&cliente, sizeof(Cliente), 1, tempArqcc);
        }
    } 
    
    fclose(tempArqcc);
    fclose(arqcc);
    
    if(!found){
        remove("temp_contascc.txt");
    }else{
        remove("contascc.txt");
        rename("temp_contascc.txt", "contascc.txt");
    }
}

void alterarclientecc(){//altera os dados dos clientes
	int senhaadm = 54321;
    int senha3;
    char nomecliente[50];
    int found = 0;
    Contacc contacc;
    Cliente cliente;
    FILE *arqcp;
	FILE *arqcc;
    
    printf("DIGITE A SENHA DO ADMINISTRADOR PARA ACESSAR O MENU: \n");
    scanf("%d", &senha3);
    if (senhaadm != senha3) {
        printf("***ACESSO NEGADO***\n");
        return;
    }
    
    printf("***ACESSO PERMITIDO***\n\n");

    arqcc=fopen("contascc.txt","r+b");
    if(arqcc==NULL){
		printf("ERRO AO ABRIR O ARQUIVO");
		system("pause");
		return;
	}
	
    printf("DIGITE O NOME DO CLIENTE A SER ALTERADO: ");
    fflush(stdin);
    fgets(nomecliente, 50, stdin);
    nomecliente[strcspn(nomecliente, "\n")] = '\0';
    
    while(fread(&cliente, sizeof(Cliente), 1, arqcc)){
        if(strcmp(cliente.nomecliente,nomecliente)==0){
            found = 1;
            
            break;
        }
    }
    
    if(!found){
        printf("Conta n�o encontrada.\n");
        fclose(arqcc);
        system("pause");
        return;
    }

	fseek(arqcc, -(long int)sizeof(Cliente), SEEK_CUR);
	
    printf("insira o numero do telefone do cliente: \n");
	fflush(stdin);
    fgets(cliente.telefone, 15 , stdin);
    cliente.telefone[strcspn(cliente.telefone, "\n")] = '\0';
		
	printf("endereco: \n");
		
	printf("ESTADO: ");
	fflush(stdin);
    fgets(cliente.endereco.estado, 50 , stdin);
    cliente.endereco.estado[strcspn(cliente.endereco.estado, "\n")] = '\0';
		
	printf("CIDADE: ");
	fflush(stdin);
    fgets(cliente.endereco.cidade, 50 , stdin);
    cliente.endereco.cidade[strcspn(cliente.endereco.cidade, "\n")] = '\0';
		
	printf("BAIRRO: ");
	fflush(stdin);
    fgets(cliente.endereco.bairro, 50 , stdin);
    cliente.endereco.bairro[strcspn(cliente.endereco.bairro, "\n")] = '\0';
		
	printf("LOGRADOURO: ");
	fflush(stdin);
    fgets(cliente.endereco.logradouro, 50 , stdin);
    cliente.endereco.logradouro[strcspn(cliente.endereco.logradouro, "\n")] = '\0';
	
	printf("RUA: ");
	fflush(stdin);
    fgets(cliente.endereco.rua, 100 , stdin);
    cliente.endereco.rua[strcspn(cliente.endereco.rua, "\n")] = '\0';	

	printf("NUMERO DA CASA: ");
    scanf("%d", &cliente.endereco.numerocasa);

    fwrite(&cliente, sizeof(cliente), 1, arqcc);
    if (ferror(arqcc)) {
        printf("\nERRO NA GRAVACAO\n");
        fclose(arqcc);
        fclose(arqcp);
        system("pause");
        return;
    } else {
        printf("GRAVACAO OK\n");
    }
    system("pause");
	fclose(arqcc);
}

void alterarclientecp(){//altera os dados dos clientes
	int senhaadm = 54321;
    int senha3;
    char nomecliente[50];
    int found = 0;
    Contacp contacp;
    Contacc contacc;
    Cliente cliente;
    FILE *arqcp;
	FILE *arqcc;
    
    printf("DIGITE A SENHA DO ADMINISTRADOR PARA ACESSAR O MENU: \n");
    scanf("%d", &senha3);
    if (senhaadm != senha3) {
        printf("***ACESSO NEGADO***\n");
        return;
    }
    
    printf("***ACESSO PERMITIDO***\n\n");

	arqcp=fopen("contascp.txt","r+b");
	if(arqcp==NULL){
		printf("ERRO AO ABRIR O ARQUIVO");
		system("pause");
		return;
	}
	
    printf("DIGITE O NOME DO CLIENTE A SER ALTERADO: ");
    fflush(stdin);
    fgets(nomecliente, 50, stdin);
    nomecliente[strcspn(nomecliente, "\n")] = '\0';
    
    while(fread(&cliente, sizeof(cliente), 1, arqcp)){
        if(strcmp(cliente.nomecliente,nomecliente)==0){
            found = 1;
            break;
        }
    }
    
    if(!found){
        printf("Conta n�o encontrada.\n");
        fclose(arqcc);
        fclose(arqcp);
        system("pause");
        return;
    }

	fseek(arqcp, -(long int)sizeof(Cliente), SEEK_CUR);
	
    printf("insira o numero do telefone do cliente: \n");
	fflush(stdin);
    fgets(cliente.telefone, 15 , stdin);
    cliente.telefone[strcspn(cliente.telefone, "\n")] = '\0';
		
	printf("endereco: \n");
		
	printf("ESTADO: ");
	fflush(stdin);
    fgets(cliente.endereco.estado, 50 , stdin);
    cliente.endereco.estado[strcspn(cliente.endereco.estado, "\n")] = '\0';
		
	printf("CIDADE: ");
	fflush(stdin);
    fgets(cliente.endereco.cidade, 50 , stdin);
    cliente.endereco.cidade[strcspn(cliente.endereco.cidade, "\n")] = '\0';
		
	printf("BAIRRO: ");
	fflush(stdin);
    fgets(cliente.endereco.bairro, 50 , stdin);
   	cliente.endereco.bairro[strcspn(cliente.endereco.bairro, "\n")] = '\0';
		
	printf("LOGRADOURO: ");
	fflush(stdin);
   	fgets(cliente.endereco.logradouro, 50 , stdin);
   	cliente.endereco.logradouro[strcspn(cliente.endereco.logradouro, "\n")] = '\0';
		
	printf("RUA: ");
	fflush(stdin);
    fgets(cliente.endereco.rua, 100 , stdin);
    cliente.endereco.rua[strcspn(cliente.endereco.rua, "\n")] = '\0';
		
	printf("NUMERO DA CASA: ");
    scanf("%d", &cliente.endereco.numerocasa);

	fwrite(&cliente, sizeof(cliente), 1, arqcp);
    if (ferror(arqcp)) {
        printf("\nERRO NA GRAVACAO\n");
        fclose(arqcc);
        fclose(arqcp);
        system("pause");
        return;
    } else {
        printf("GRAVACAO OK\n");
    }

    fclose(arqcc);
    fclose(arqcp);
}

void alterarfuncionario(){//altera os dados dos funcionarios
    int senhaadm = 54321;
    int senha3;
    char codfunc[20];
    int found = 0;
    Funcionario funcionario;
    
    printf("DIGITE A SENHA DO ADMINISTRADOR PARA ACESSAR O MENU: \n");
    scanf("%d", &senha3);
    if (senhaadm != senha3) {
        printf("***ACESSO NEGADO***\n");
        return;
    }
    
    printf("***ACESSO PERMITIDO***\n\n");

    
    printf("DIGITE O CODIGO DO FUNCIONARIO A SER ALTERADO: ");
    fflush(stdin);
    gets(codfunc);

    FILE *arqfunc = fopen("funcionarios.txt", "r+b");
    if (arqfunc == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO\n");
        return;
    }
    
    while(fread(&funcionario, sizeof(funcionario), 1, arqfunc)){
        if(strcmp(funcionario.codigo,codfunc)==0){
            found = 1;
            break;
        }
    }

	if(!found){
        printf("Conta n�o encontrada.\n");
        fclose(arqfunc);
        system("pause");
        return;
    }


    fseek(arqfunc, -(long int)sizeof(Funcionario), SEEK_CUR);
    
    printf("insira o codigo do funcionario: \n");
	fflush(stdin);
	fgets(funcionario.codigo, 20 , stdin);
	funcionario.codigo[strcspn(funcionario.codigo, "\n")] = '\0';
	
	printf("insira o cargo do funcionario: \n");
	fflush(stdin);
	fgets(funcionario.cargo, 100 , stdin);
	funcionario.cargo[strcspn(funcionario.cargo, "\n")] = '\0';
	
	printf("insira o numero de telefone do funcionario: \n");
	fflush(stdin);
	fgets(funcionario.telefone, 15 , stdin);
	funcionario.telefone[strcspn(funcionario.telefone, "\n")] = '\0';
	
	printf("insira o endere�o do funcionario: \n");
	
	printf("CEP: \n");
	scanf("%d",&funcionario.endereco.cep);
	
	printf("estado: \n");
	fflush(stdin);
	fgets(funcionario.endereco.estado, 50 , stdin);
	funcionario.endereco.estado[strcspn(funcionario.endereco.estado, "\n")] = '\0';
	
	printf("cidade: ");
	fflush(stdin);
	fgets(funcionario.endereco.cidade, 50 , stdin);
	funcionario.endereco.cidade[strcspn(funcionario.endereco.cidade, "\n")] = '\0';
	
	printf("bairro: \n");
	fflush(stdin);
	fgets(funcionario.endereco.bairro, 50 , stdin);
	funcionario.endereco.bairro[strcspn(funcionario.endereco.bairro, "\n")] = '\0';
	
	printf("logradouro: \n");
	fflush(stdin);
	fgets(funcionario.endereco.logradouro, 50 , stdin);
	funcionario.endereco.logradouro[strcspn(funcionario.endereco.logradouro, "\n")] = '\0';
		
	printf("RUA: \n");
	fflush(stdin);
	fgets(funcionario.endereco.rua, 50 , stdin);
	funcionario.endereco.rua[strcspn(funcionario.endereco.rua, "\n")] = '\0';
	
	printf("numero da casa: \n");
	scanf("%d",&funcionario.endereco.numerocasa);

    fwrite(&funcionario, sizeof(Funcionario), 1,arqfunc);
    
    if(ferror(arqfunc)){
        printf("\nERRO NA GRAVACAO\n");
    }else{
        printf("GRAVACAO OK\n");
    }
    fclose(arqfunc);
    system("pause");
}

void subsubmenualterarcontacc(){//altera dados conta corrente
	int i;
	do{
		system("cls");
		printf("+-----------------------+\n");
		printf("| ALTERAR CONTA CORRENTE|\n");
		printf("+-----------------------+\n\n");
		printf("[1]ALTERAR CONTA CORRENTE PARA POUPANCA \n");
		printf("[2]ALTERAR DADOS DA CONTA\n");
		printf("[3]VOLTAR\n");
		scanf("%d",&i);
		switch(i){
			case 1:
				alterartipocontacc();
			break;
			case 2:
				alterardadoscontacc();
			break;
			case 3:
				break;
			default:
				printf("OPCAO INVALIDA.\n");
		}
	}while(i!=3);
}
	
void subsubmenualterarcontacp(){//altera dados conta poupanca
	int i;
	do{
		system("cls");
		printf("+-----------------------+\n");
		printf("| ALTERAR CONTA POUPANCA|\n");
		printf("+-----------------------+\n\n");
		printf("[1]ALTERAR CONTA POUPANCA PARA CORRENTE \n");
		printf("[2]ALTERAR DADOS DA CONTA\n");
		printf("[3]VOLTAR\n");
		scanf("%d",&i);
		switch(i){
			case 1:
				alterartipocontacp();
			break;
			case 2:
				alterardadoscontacp();
			break;
			case 3:
				break;
			default:
				printf("OPCAO INVALIDA.\n");
		}
	}while(i!=3);
}
	
void submenualterarcontas(){//menu que escolhe as contas que vao ser alteradas
	int i;
	do{
		system("cls");
		printf("+----------------+\n");
		printf("| ALTERAR CONTAS |\n");
		printf("+----------------+\n\n");
		printf("[1]ALTERAR CONTA POUPANCA\n");
		printf("[2]ALTERAR CONTA CORRENTE\n");
		printf("[3]VOLTAR\n");
		scanf("%d",&i);
		switch(i){
			case 1:
				subsubmenualterarcontacp();
			break;
			case 2:
				subsubmenualterarcontacc();
			break;
			case 3:
				break;
			default:
				printf("OPCAO INVALIDA.\n");
		}
	}while(i!=3);
}

void submenuconsultarcontas(){//menu para escolher qual conta que vai ser consultada
	int i;
	do{//esse menu e para selecionar o tipo de conta que vai ser consultada
		system("cls");
		printf("SELECIONE A CONTA A SER CONSULTADA:\n");//esse menu e para selecionar o tipo de conta que vai ser consultada
		printf("[1]CONTA POUPANCA\n");
		printf("[2]CONTA CORRENTE\n");
		printf("[3]VOLTAR\n");
		scanf("%d",&i);
		switch(i){
			case 1:
				consultarcontascp();//esse menu e para selecionar o tipo de conta que vai ser consultada
			break;
			case 2:
				consultarcontascc();//esse menu e para selecionar o tipo de conta que vai ser consultada
			break;
			case 3:
				break;
			default:
				printf("OPCAO INVALIDA.\n");
		}	
	}while(i!=3);
}

void subsubmenualterarcliente(){
		int i;
	do{
		system("cls");
		printf("+---------------+\n");
		printf("| ALTERAR DADOS |\n");
		printf("+---------------+\n\n");
		printf(" [1] <-- ALTERAR CLIENTE CONTA POUPANCA \n");
		printf(" [2] <-- ALTERAR CLIENTE CONTA CORRENTE \n");
		printf(" [3] <-- VOLTAR \n");
		scanf("%d",&i);
		
		switch(i){
			case 1:
				alterarclientecp();
			break;
			case 2:
				alterarclientecc();
			break;
			case 3:
				break;
			default:
				printf("OPCAO INVALIDA.\n");
		}
	}while(i!=3);
}

void relatoriopoupanca(){//gera relatorios das contas poupancas
	char numconta[20];
	Cliente cliente;
	Contacp contacp;
	FILE *arqcp, *relatoriocp;
	
	arqcp=fopen("contascp.txt","rb");
	if(arqcp==NULL){
	printf("ERRO AO ABRIR O ARQUIVO");
	system("pause");
	return;
	}
	
	relatoriocp = fopen("relatoriocp.csv", "a");
    if (relatoriocp == NULL) {
        printf("ERRO AO CRIAR O ARQUIVO RELATORIOCP");
        fclose(arqcp);
        system("pause");
        return;
    }
	
	printf("DIGITE O NUMERO DA CONTA A SER CONSULTADA: ");
	fflush(stdin);	
	fgets(numconta, 20, stdin);
    numconta[strcspn(numconta, "\n")] = '\0';
		
	while(fread(&cliente,sizeof(Cliente),1,arqcp) == 1){
		if(strcmp(numconta,cliente.contacp.numconta)==0){
			fprintf(relatoriocp,"CONTA-POUPANCA \n");
			fprintf(relatoriocp,"AGENCIA, %s \n",cliente.contacp.agencia);
			fprintf(relatoriocp,"NUMERO DA CONTA, %s \n",cliente.contacp.numconta);
			fprintf(relatoriocp,"DATA DE VENCIMENTO, %s/%s/%s \n",cliente.contacp.datavencdia,cliente.contacp.datavencmes,cliente.contacp.datavencano);
			fprintf(relatoriocp,"SALDO, %.2f \n",cliente.contacp.saldo);
			fprintf(relatoriocp,"LIMITE, %d \n",cliente.contacp.limite);
			fprintf(relatoriocp,"NOME, %s \n",cliente.nomecliente);
			fprintf(relatoriocp,"SENHA, %s \n",cliente.senha);
			fprintf(relatoriocp,"CPF, %s \n",cliente.cpf);
			fprintf(relatoriocp,"TELEFONE, %s \n",cliente.telefone);
			fprintf(relatoriocp,"DATA DE NASCIMENTO, %d/%d/%d \n",cliente.nasc.dia,cliente.nasc.mes,cliente.nasc.ano);
			fprintf(relatoriocp,"ENDERECO, \n");
			fprintf(relatoriocp,"CEP, %d \n",cliente.endereco.cep);
			fprintf(relatoriocp,"ESTADO, %s \n",cliente.endereco.estado);
			fprintf(relatoriocp,"CIDADE, %s \n",cliente.endereco.cidade);
			fprintf(relatoriocp,"BAIRRO, %s \n",cliente.endereco.bairro);
			fprintf(relatoriocp,"LOGRADOURO, %s \n",cliente.endereco.logradouro);
			fprintf(relatoriocp,"RUA, %s \n",cliente.endereco.rua);
			fprintf(relatoriocp,"NUMERO DA CASA, %d \n",cliente.endereco.numerocasa);
			fprintf(relatoriocp,"__________________________________________________ \n");
			}
		}
	printf("RELATORIO GERADO COM SUCESSO.");
	fclose(arqcp);
	fclose(relatoriocp);
	system("relatoriocp.csv");
}

void relatoriocorrente(){//gera relatorios das contas correntes
	char numconta[20];
	Cliente cliente;
	Contacp contacp;
	FILE *arqcc, *relatoriocc;
	
	arqcc=fopen("contascc.txt","rb");
	if(arqcc==NULL){
	printf("ERRO AO ABRIR O ARQUIVO");
	system("pause");
	return;
	}
	
	relatoriocc = fopen("relatoriocc.csv", "a");
    if (relatoriocc == NULL) {
        printf("ERRO AO CRIAR O ARQUIVO EXTRATO");
        fclose(arqcc);
        system("pause");
        return;
    }
	
	fprintf(relatoriocc,"AGENCIA,NUMERO DA CONTA,SALDO,LIMITE,NOME,SENHA,CPF,TELEFONE,DATA DE NASCIMENTO,ENDERECO,CEP,ESTADO,CIDADE,BAIRRO,LOGRADOURO,RUA,NUMERO DA CASA \n");
	
	printf("DIGITE O NUMERO DA CONTA A SER CONSULTADA: ");
	fflush(stdin);	
	fgets(numconta, 20, stdin);
    numconta[strcspn(numconta, "\n")] = '\0';
		
	while(fread(&cliente,sizeof(Cliente),1,arqcc) == 1){
		if(strcmp(numconta,cliente.contacc.numconta)==0){
			fprintf(relatoriocc,"CONTA-CORRENTE \n");
			fprintf(relatoriocc,"AGENCIA, %s \n",cliente.contacc.agencia);
			fprintf(relatoriocc,"NUMERO DA CONTA, %s \n",cliente.contacc.numconta);
			fprintf(relatoriocc,"DATA DE NASCIMENTO, %s/%s/%s \n",cliente.contacc.datavencdia,cliente.contacc.datavencmes,cliente.contacc.datavencano);
			fprintf(relatoriocc,"SALDO, %.2f \n",cliente.contacc.saldo);
			fprintf(relatoriocc,"LIMITE, %d \n",cliente.contacc.limite);
			fprintf(relatoriocc,"NOME, %s \n",cliente.nomecliente);
			fprintf(relatoriocc,"SENHA, %s \n",cliente.senha);
			fprintf(relatoriocc,"CPF, %s \n",cliente.cpf);
			fprintf(relatoriocc,"TELEFONE, %s \n",cliente.telefone);
			fprintf(relatoriocc,"DATA DE NASCIMENTO, %d/%d/%d \n",cliente.nasc.dia,cliente.nasc.mes,cliente.nasc.ano);
			fprintf(relatoriocc,"ENDERECO, \n");
			fprintf(relatoriocc,"CEP, %d \n",cliente.endereco.cep);
			fprintf(relatoriocc,"ESTADO, %s \n",cliente.endereco.estado);
			fprintf(relatoriocc,"CIDADE, %s \n",cliente.endereco.cidade);
			fprintf(relatoriocc,"BAIRRO, %s \n",cliente.endereco.bairro);
			fprintf(relatoriocc,"LOGRADOURO, %s \n",cliente.endereco.logradouro);
			fprintf(relatoriocc,"RUA, %s \n",cliente.endereco.rua);
			fprintf(relatoriocc,"NUMERO DA CASA, %d \n",cliente.endereco.numerocasa);
			fprintf(relatoriocc,"__________________________________________________ \n");
			}
		}
	printf("RELATORIO GERADO COM SUCESSO. \n");
	fclose(arqcc);
	fclose(relatoriocc);
	system("relatoriocc.csv");
}

void menuaberturadeconta(){//menu de abertura de contas
	int i;
	do{
		system("cls");
		printf("+--------------+\n");
		printf("| ABRIR CONTAS |\n");
		printf("+--------------+\n\n");
		printf(" [1] <-- CONTA POUPANCA - CP \n");
		printf(" [2] <-- CONTA CORRENTE - CC \n");
		printf(" [3] <-- voltar \n");
		scanf("%d",&i);
		
		switch(i){
		case 1:
			cadastrarcontapoupanca();
		break;
		case 2:
			cadastrarcontacorrente();
		break;	
		case 3:
			break;
		default:
			printf("OPCAO INVALIDA.\n");
		}	
	}while(i!=3);	
}

void menuexcluircontas(){//menu excluir contas
	int i;
	do{
		system("cls");
		printf("+----------------+\n");
		printf("| EXCLUIR CONTAS |\n");
		printf("+----------------+\n\n");
		printf("ESCOLHA QUAL CONTA EXCLUIR \n");
		printf("[1] CONTA-POUPANCA \n");
		printf("[2] CONTA-CORRENTE \n");
		printf("[3] VOLTAR \n");
		scanf("%d",&i);
		
		switch(i){
			case 1:
				excluircontapoupanca();
			break;
			case 2:
				excluircontacorrente();
			break;
			case 3:
				break;
			default:
				printf("OPCAO INVALIDA.\n");
		}
	}while(i!=3);
}

void menuconsultardados(){//menu que consulta os dados
	int i;
	do{
		system("cls");
		printf("+-----------------+\n");
		printf("| CONSULTAR DADOS |\n");
		printf("+-----------------+\n\n");
		printf("[1] <-- CONSULTAR CONTA \n");
		printf("[2] <-- CONSULTAR FUNCIONARIO \n");
		printf("[3] <-- CONSULTAR CLIENTE \n");
		printf("[4] <-- VOLTAR \n");
		scanf("%d",&i);
		switch(i){
			case 1:
				submenuconsultarcontas();
				break;
			case 2:
				consultarfuncionario();//consulta funcionario
			break;
			case 3:   //colocar consultar cliente
				consultarcliente();
			break;
			case 4:
				break;
			default:
				printf("OPCAO INVALIDA.\n");				
		}
	}while(i!=4);
}

void menualterardados(){//menu que altera os dados
	int i;
	do{
		system("cls");
		printf("+---------------+\n");
		printf("| ALTERAR DADOS |\n");
		printf("+---------------+\n\n");
		printf(" [1] <-- ALTERAR CONTA \n");
		printf(" [2] <-- ALTERAR FUNCIONARIO \n");
		printf(" [3] <-- ALTERAR CLIENTE \n");
		printf(" [4] <-- VOLTAR \n");
		scanf("%d",&i);
		
		switch(i){
			case 1:
				submenualterarcontas();
			break;
			case 2:
				alterarfuncionario();
			break;
			case 3:
				subsubmenualterarcliente();
			break;
			case 4:
				break;
			default:
				printf("OPCAO INVALIDA.\n");
		}
	}while(i!=4);
}

void menurelatorios(){//menu que gera relatrios
	int i;
	do{
		system("cls");
		printf("+------------------+\n");
		printf("| GERAR RELATORIOS |\n");
		printf("+------------------+\n\n");
		printf(" [1] <-- GERAR RELATORIO CONTA-POUPANCA \n");
		printf(" [2] <-- GERAR RELATORIO CONTA-CORRENTE \n");
		printf(" [3] <-- VOLTAR \n");
		scanf("%d",&i);
		
		switch(i){
			case 1:
				relatoriopoupanca();
			break;
			case 2:
				relatoriocorrente();
			break;
			case 3:
				break;
			default:
				printf("OPCAO INVALIDA.\n");
		}
	}while(i!=3);
}

void menufuncionario(){ //menu para acessar as opcoes dos funcionarios
	int i;
	/*int senhafunc,senha2;
	senhafunc=12345;
	
	printf("digite a senha para  acessar menu: \n");
	scanf("%d",&senha2);
	
	if(senhafunc==senha2){
		system("cls");
		printf("***ACESSO PERMITIDO***\n\n");
	}else{
		printf("***ACESSO NEGADO***\n");
		return; 
	}
	*/
		do{
			system("cls");
			printf("+------------------+\n");
			printf("| MENU FUNCIONARIO |\n");
			printf("+------------------+\n\n");
			printf("[1] <-- ABERTURA DE CONTA \n");
			printf("[2] <-- ENCERRAMENTO DE CONTA \n");
			printf("[3] <-- CONSULTAR DADOS \n");
			printf("[4] <-- ALTERAR DADOS \n");
			printf("[5] <-- CADASTRO DE FUNCIONARIOS \n");
			printf("[6] <-- GERAR RELATORIOS \n");
			printf("[7] <-- SAIR \n");
			scanf("%d",&i);
		
		switch(i){
			case 1:
				menuaberturadeconta();
			break;
			case 2:
				menuexcluircontas();
			break;
			case 3:
				menuconsultardados();
			break;
			case 4:
				menualterardados();
			break;
			case 5:
				cadastrarfuncionarios();
			break;
			case 6:
				menurelatorios();
			break;
			case 7:
				break;
			default:
				printf("OPCAO INVALIDA.");
			}
		}while(i!=7);
}

void saldocontapoupanca(){//verifica o saldo das contas poupancas
	char numconta[20];
	Cliente cliente;
	Contacp contacp;
	Trans trans;
	FILE *arqcp;
	arqcp=fopen("contascp.txt","rb");
	if(arqcp==NULL){
	printf("ERRO AO ABRIR O ARQUIVO");
	}
	
	printf("DIGITE O NUMERO DA CONTA A SER CONSULTADA: ");
	fflush(stdin);	
	fgets(numconta, 20, stdin);
    numconta[strcspn(numconta, "\n")] = '\0';
		
	while(fread(&cliente,sizeof(cliente),1,arqcp) == 1){
		if(strcmp(numconta,cliente.contacp.numconta)==0){
			printf("SALDO : %.2f \n",cliente.contacp.saldo);
		}else{
			printf("CONTA NAO ENCONTRADA. \n");
        	system("pause");
        	return;
		}
	}
	fclose(arqcp);
	system("pause");
}

void saldocontacorrente(){//verifica o saldo das contas correntes
	char numconta[20];
	Cliente cliente;
	Contacc contacc;
	FILE *arqcc;
	arqcc=fopen("contascc.txt","rb");
	if(arqcc==NULL){
	printf("ERRO AO ABRIR O ARQUIVO");
	}
	
	printf("DIGITE O NUMERO DA CONTA A SER CONSULTADA: ");
	fflush(stdin);	
	fgets(numconta, 20, stdin);
    numconta[strcspn(numconta, "\n")] = '\0';
		
	while(fread(&cliente,sizeof(cliente),1,arqcc) == 1){
		if(strcmp(numconta,cliente.contacc.numconta)==0){
			printf("SALDO : %.2f \n",cliente.contacc.saldo);
		}else{
			printf("CONTA NAO ENCONTRADA. \n");
        	system("pause");
        	return;
		}
	}
	fclose(arqcc);
	system("pause");
}

void depositocontapoupanca(){//verifica o deposito das contas poupancas
	char numconta[20];
	int found=0;
	Cliente cliente;
	Contacp contacp;
	Trans trans;
	cliente.contacp.trans.deposito=0;
	FILE *arqcp;
	FILE *arqtrancp;
	
	arqcp=fopen("contascp.txt","r+b");
	if(arqcp==NULL){
	printf("ERRO AO ABRIR O ARQUIVO, CRIE UMA CONTA NO MENU FUNCIONARIO PRIMEIRO. \n\n");
	system("pause");
	return;
	}
	
	arqtrancp=fopen("transacoescp.txt","a+b");
	if(arqtrancp==NULL){
	printf("ERRO AO ABRIR O ARQUIVO");
	system("pause");
	return;
	}
	
	printf("DIGITE O NUMERO DA CONTA PARA DESPOSITO: ");
	fflush(stdin);	
	fgets(numconta, 20, stdin);
    numconta[strcspn(numconta, "\n")] = '\0';
		
	while (fread(&cliente, sizeof(cliente), 1, arqcp)) {
        if(strcmp(cliente.contacp.numconta,numconta)==0){
            found = 1;
            break;
        }else{
        	printf("CONTA NAO ENCONTRADA. \n");
        	system("pause");
        	return;
		}
    }

    fseek(arqcp, -(long int)sizeof(cliente), SEEK_CUR);
    
    printf("INSIRA O VALOR DO DEPOSITO: ");
    scanf("%f",&cliente.contacp.trans.deposito);

    cliente.contacp.saldo = cliente.contacp.saldo + cliente.contacp.trans.deposito;
    cliente.contacp.trans.saque=0;
    
    fwrite(&cliente, sizeof(cliente), 1, arqcp);
    if (ferror(arqcp)) {
        printf("\nERRO NA GRAVACAO\n");
    } else {
        printf("GRAVACAO OK\n");
    }
    
	fwrite(&cliente, sizeof(Cliente),1,arqtrancp);
	if (ferror(arqtrancp)) {
        printf("\nERRO NA GRAVACAO\n");
    } else {
        printf("GRAVACAO OK\n");
    }
    
	fclose(arqcp);
	fclose(arqtrancp);
	system("pause");
}

void depositocontacorrente(){//verifica o deposito das contas correntes
	char numconta[20];
	int found=0;
	float deposito;
	Cliente cliente;
	Contacc contacc;
	FILE *arqcc;
	FILE *arqtrancc;
	
	arqcc=fopen("contascc.txt","r+b");
	if(arqcc==NULL){
	printf("ERRO AO ABRIR O ARQUIVO, CRIE UMA CONTA NO MENU FUNCIONARIO PRIMEIRO. \n\n");
	system("pause");
	return;
	}
	
	arqtrancc=fopen("transacoescc.txt","a+b");
	if(arqtrancc==NULL){
	printf("ERRO AO ABRIR O ARQUIVO");
	}
	printf("DIGITE O NUMERO DA CONTA PARA DESPOSITO: ");
	fflush(stdin);	
	fgets(numconta, 20, stdin);
    numconta[strcspn(numconta, "\n")] = '\0';
		
	while (fread(&cliente, sizeof(cliente), 1, arqcc)) {
        if(strcmp(cliente.contacc.numconta,numconta)==0){
            found = 1;
            break;
        }else{
        	printf("CONTA NAO ENCONTRADA. \n");
        	system("pause");
        	return;
		}
    }

    fseek(arqcc, -(long int)sizeof(cliente), SEEK_CUR);
    
    printf("INSIRA O VALOR DO DEPOSITO: ");
    scanf("%f",&cliente.contacc.trans.deposito);
    
    cliente.contacc.saldo = cliente.contacc.saldo + cliente.contacc.trans.deposito;
    cliente.contacc.trans.saque=0;
    
    fwrite(&cliente, sizeof(cliente), 1, arqcc);
    if (ferror(arqcc)) {
        printf("\nERRO NA GRAVACAO\n");
    } else {
        printf("GRAVACAO OK\n");
    }
	
	fwrite(&cliente, sizeof(Cliente),1,arqtrancc);
	if (ferror(arqtrancc)) {
        printf("\nERRO NA GRAVACAO\n");
    } else {
        printf("GRAVACAO OK\n");
    }
	
	fclose(arqcc);
	fclose(arqtrancc);
	system("pause");
	
}

void saquecontapoupanca(){//verifica o saque das contas poupancas
	char numconta[20];
	int found=0;
	Cliente cliente;
	Contacp contacp;
	Trans trans;
	FILE *arqcp;
	FILE *arqtrancp;
	
	arqcp=fopen("contascp.txt","r+b");
	if(arqcp==NULL){
	printf("ERRO AO ABRIR O ARQUIVO, CRIE UMA CONTA NO MENU FUNCIONARIO PRIMEIRO. \n\n");
	system("pause");
	return;
	}
	
	arqtrancp=fopen("transacoescp.txt","a+b");
	if(arqtrancp==NULL){
	printf("ERRO AO ABRIR O ARQUIVO");
	}
	
	printf("DIGITE O NUMERO DA CONTA PARA SAQUE: ");
	fflush(stdin);	
	fgets(numconta, 20, stdin);
    numconta[strcspn(numconta, "\n")] = '\0';
		
	while (fread(&cliente, sizeof(cliente), 1, arqcp)) {
        if(strcmp(cliente.contacp.numconta,numconta)==0){
            found = 1;
            break;
        }else{
        	printf("CONTA NAO ENCONTRADA. \n");
        	system("pause");
        	return;
		}
    }

    fseek(arqcp, -(long int)sizeof(cliente), SEEK_CUR);
    
    printf("INSIRA O VALOR DO SAQUE: ");
    scanf("%f",&cliente.contacp.trans.saque);
    if(cliente.contacp.trans.saque>cliente.contacp.saldo){
    	printf("SALDO INSUFICIENTE.\n");
    	system("pause");
    	return;
	}
    cliente.contacp.saldo = cliente.contacp.saldo - cliente.contacp.trans.saque;
    cliente.contacp.trans.deposito=0;
    
    fwrite(&cliente, sizeof(cliente), 1, arqcp);
    if (ferror(arqcp)) {
        printf("\nERRO NA GRAVACAO\n");
    } else {
        printf("GRAVACAO OK\n");
    }
    
	fwrite(&cliente, sizeof(Cliente),1,arqtrancp);
	if (ferror(arqtrancp)) {
        printf("\nERRO NA GRAVACAO\n");
    } else {
        printf("GRAVACAO OK\n");
    }
    
	fclose(arqcp);
	fclose(arqtrancp);
	system("pause");
	
}

void saquecontacorrente(){//verifica o saque das contas correntes
	char numconta[20];
	int found=0;
	float saque;
	Cliente cliente;
	Contacc contacc;
	FILE *arqcc;
	FILE *arqtrancc;
	
	arqcc=fopen("contascc.txt","r+b");
	if(arqcc==NULL){
	printf("ERRO AO ABRIR O ARQUIVO, CRIE UMA CONTA NO MENU FUNCIONARIO PRIMEIRO. \n\n");
	system("pause");
	return;
	}
	
	arqtrancc=fopen("transacoescc.txt","a+b");
	if(arqtrancc==NULL){
	printf("ERRO AO ABRIR O ARQUIVO");
	system("pause");
	return;
	}
	
	printf("DIGITE O NUMERO DA CONTA PARA SAQUE: ");
	fflush(stdin);	
	fgets(numconta, 20, stdin);
    numconta[strcspn(numconta, "\n")] = '\0';
		
	while (fread(&cliente, sizeof(cliente), 1, arqcc)) {
        if(strcmp(cliente.contacc.numconta,numconta)==0){
            found = 1;
            break;
        }else{
        	printf("CONTA NAO ENCONTRADA. \n");
        	system("pause");
        	return;
		}
    }

    fseek(arqcc, -(long int)sizeof(cliente), SEEK_CUR);
    
    printf("INSIRA O VALOR DO SAQUE: ");
    scanf("%f",&cliente.contacc.trans.saque);
    if(cliente.contacc.trans.saque>cliente.contacc.saldo){
    	printf("SALDO INSUFICIENTE.");
	}
    
    cliente.contacc.saldo = cliente.contacc.saldo - cliente.contacc.trans.saque;
    cliente.contacc.trans.deposito=0;
    
    fwrite(&cliente, sizeof(cliente), 1, arqcc);
    if (ferror(arqcc)) {
        printf("\nERRO NA GRAVACAO\n");
    } else {
        printf("GRAVACAO OK\n");
    }
    
    fwrite(&cliente, sizeof(Cliente),1,arqtrancc);
	if (ferror(arqtrancc)) {
        printf("\nERRO NA GRAVACAO\n");
    } else {
        printf("GRAVACAO OK\n");
    }
    
	fclose(arqcc);
	system("pause");
}

void extratopoupanca(){//verifica o extrato das contas poupancas
	char numconta[20];
	Cliente cliente;
	Contacp contacp;
	Trans trans;
	FILE *arqtrancp, *extrato;
	
	arqtrancp=fopen("transacoescp.txt","rb");
	if(arqtrancp==NULL){
	printf("ERRO AO CRIAR O ARQUIVO TRANSACOES, EFETUE UMA TRANSACAO NA CONTA PARA CRIAR O ARQUIVO DE TRANSACOES.\n\n");
	system("pause");
	return;
	}
	
	extrato = fopen("extrato.csv", "w");
    if (extrato == NULL) {
        printf("ERRO AO CRIAR O ARQUIVO EXTRATO, EFETUE UMA TRANSACAO PARA CRIAR O ARQUIVO DE EXTRATO.\n\n");
        fclose(arqtrancp);
        system("pause");
        return;
    }
	
	fprintf(extrato,"numero da conta,depositos,saques,saldo \n");
	
	printf("DIGITE O NUMERO DA CONTA A SER CONSULTADA: ");
	fflush(stdin);	
	fgets(numconta, 20, stdin);
    numconta[strcspn(numconta, "\n")] = '\0';
		
	while(fread(&cliente,sizeof(Cliente),1,arqtrancp) == 1){
		if(strcmp(numconta,cliente.contacp.numconta)==0){
			fprintf(extrato,"CONTA-POUPANCA \n");
			fprintf(extrato,"NUMERO DA CONTA,  %s \n",cliente.contacp.numconta);
			fprintf(extrato,"DEPOSITO, + %.2f \n",cliente.contacp.trans.deposito);
			fprintf(extrato,"SAQUE, - %.2f \n",cliente.contacp.trans.saque);
			fprintf(extrato,"SALDO, %.2f \n",cliente.contacp.saldo);
			fprintf(extrato,"---------------------------------------------------\n\n");
			printf("CONTA-POUPANCA \n");
			printf("NUMERO DA CONTA:  %s \n",cliente.contacp.numconta);	
			printf("DEPOSITO: + %.2f \n",cliente.contacp.trans.deposito);
			printf("SAQUE: - %.2f \n",cliente.contacp.trans.saque);
			printf("SALDO: %.2f \n",cliente.contacp.saldo);
			printf("---------------------------------------------------\n\n");
			}
		}
	fclose(arqtrancp);
	fclose(extrato);
	system("extrato.csv");
}

void extratocorrente(){//verifica o extrato das contas correntes
	char numconta[20];
	Cliente cliente;
	Contacc contacc;
	Trans trans;
	FILE *arqtrancc, *extrato;
	
	arqtrancc=fopen("transacoescc.txt","rb");
	if(arqtrancc==NULL){
	printf("ERRO AO CRIAR O ARQUIVO TRANSACOES, EFETUE UMA TRANSACAO NA CONTA PARA CRIAR O ARQUIVO DE TRANSACOES. \n\n");
	system("pause");
	return;
	}
	
	extrato = fopen("extrato.csv", "w");
    if (extrato == NULL) {
        printf("ERRO AO CRIAR O ARQUIVO EXTRATO, EFETUE UMA TRANSACAO PARA CRIAR O ARQUIVO DE EXTRATO. \n\n");
        fclose(arqtrancc);
        system("pause");
        return;
    }
	
	printf("DIGITE O NUMERO DA CONTA A SER CONSULTADA: ");
	fflush(stdin);	
	fgets(numconta, 20, stdin);
    numconta[strcspn(numconta, "\n")] = '\0';
		
	while(fread(&cliente,sizeof(Cliente),1,arqtrancc) == 1){
		if(strcmp(numconta,cliente.contacc.numconta)==0){
			fprintf(extrato,"CONTA-CORRENTE \n");
			fprintf(extrato,"NUMERO DA CONTA,  %s \n",cliente.contacc.numconta);
			fprintf(extrato,"DEPOSITO, + %.2f \n",cliente.contacc.trans.deposito);
			fprintf(extrato,"SAQUE, - %.2f \n",cliente.contacc.trans.saque);
			fprintf(extrato,"SALDO, %.2f \n",cliente.contacc.saldo);
			fprintf(extrato,"---------------------------------------------------\n\n");
			printf("CONTA-CORRENTE \n");
			printf("NUMERO DA CONTA:  %s \n",cliente.contacc.numconta);
			printf("DEPOSITO: + %.2f \n",cliente.contacc.trans.deposito);
			printf("SAQUE: - %.2f \n",cliente.contacc.trans.saque);
			printf("SALDO: %.2f \n",cliente.contacc.saldo);
			printf("---------------------------------------------------\n\n");	
			}
		}
	fclose(arqtrancc);
	fclose(extrato);
	system("extrato.csv");
}

void limitecontapoupanca(){//verifica o limite das contas poupancas
	char numconta[20];
	Cliente cliente;
	Contacp contacp;
	FILE *arqcp;
	arqcp=fopen("contascp.txt","rb");
	if(arqcp==NULL){
	printf("ERRO AO ABRIR O ARQUIVO, CRIE UMA CONTA NO MENU FUNCIONARIO PRIMEIRO. \n\n");
	system("pause");
	return;
	}
	
	printf("DIGITE O NUMERO DA CONTA A SER CONSULTADA: ");
	fflush(stdin);	
	fgets(numconta, 20, stdin);
    numconta[strcspn(numconta, "\n")] = '\0';
		
	while(fread(&cliente,sizeof(cliente),1,arqcp) == 1){
		if(strcmp(numconta,cliente.contacp.numconta)==0){
			printf("LIMITE : %d \n",cliente.contacp.limite);
		}else{
			printf("CONTA NAO ENCONTRADA. \n");
		}
	}
	fclose(arqcp);
	system("pause");
}

void limitecontacorrente(){//verifica o limite das contas correntes
	char numconta[20];
	Cliente cliente;
	Contacc contacc;
	FILE *arqcc;
	arqcc=fopen("contascc.txt","rb");
	if(arqcc==NULL){
	printf("ERRO AO ABRIR O ARQUIVO, CRIE UMA CONTA NO MENU FUNCIONARIO PRIMEIRO. \n\n");
	system("pause");
	return;
	}
	
	printf("DIGITE O NUMERO DA CONTA A SER CONSULTADA: ");
	fflush(stdin);	
	fgets(numconta, 20, stdin);
    numconta[strcspn(numconta, "\n")] = '\0';
		
	while(fread(&cliente,sizeof(cliente),1,arqcc) == 1){
		if(strcmp(numconta,cliente.contacc.numconta)==0){
			printf("LIMITE : %d \n",cliente.contacc.limite);
		}else{
			printf("CONTA NAO ENCONTRADA. \n");
		}
	}
	fclose(arqcc);
	system("pause");
}

void verificarsenhaadm(){
	int senhaadm,senha3;
	senhaadm=54321;
	
	printf("digite a senha para  acessar menu: \n");
	scanf("%d",&senha3);
	
	if(senhaadm==senha3){
		system("cls");
		printf("***ACESSO PERMITIDO***\n\n");
	}else{
		printf("***ACESSO NEGADO***\n");
		system("pause");
	}
}

void verificarsenhafunc(){
	int senhafunc,senha2;
	senhafunc=12345;
	
	printf("digite a senha para  acessar menu: \n");
	scanf("%d",&senha2);
	
	if(senhafunc==senha2){
		system("cls");
		menufuncionario();
	}else{
		printf("***ACESSO NEGADO***\n");
		return;
	}
}

void submenuconsultarlimite(){
	int i;
	do{
		system("cls");
		printf("CONSULTAR LIMITE \n\n");
		printf("[1] <-- CONSULTAR LIMITE CONTA POUPANCA \n");
		printf("[2] <-- CONSULTAR LIMITE CONTA CORRENTE \n");
		printf("[3] <-- VOLTAR \n");
		scanf("%d",&i);		
		switch(i){
			case 1:
				limitecontapoupanca();
			break;
			case 2:
				limitecontacorrente();	
			break;
			case 3:
				break;
			default:
				printf("OPCAO INVALIDA.\n");
		}
	}while(i!=3);
}

void submenuextrato(){
	int i;
	do{
		system("cls");
		printf("SAQUE \n\n");
		printf("[1] <-- EXTRATO CONTA POUPANCA \n");
		printf("[2] <-- EXTRATO CONTA CORRENTE \n");
		printf("[3] <-- VOLTAR \n");
		scanf("%d",&i);		
		switch(i){
			case 1:
				extratopoupanca();
			break;
			case 2:
				extratocorrente();
			break;
			case 3:
				break;
			default:
				printf("OPCAO INVALIDA.\n");
		}
	}while(i!=3);
}

void submenusaque(){
	int i;
	do{
		system("cls");
		printf("SAQUE \n\n");
		printf("[1] <-- SACAR CONTA POUPANCA \n");
		printf("[2] <-- SACAR CONTA CORRENTE \n");
		printf("[3] <-- VOLTAR \n");
		scanf("%d",&i);
		switch(i){
			case 1:
				saquecontapoupanca();
			break;
			case 2:
				saquecontacorrente();
			break;
			case 3:
				break;
			default:
				printf("OPCAO INVALIDA.\n");
		}
	}while(i!=3);
}

void submenudeposito(){
	int i;
	do{
		system("cls");
		printf("DEPOSITO \n\n");
		printf("[1] <-- DEPOSITAR CONTA POUPANCA \n");
		printf("[2] <-- DEPOSITAR CONTA CORRENTE \n");
		printf("[3] <-- VOLTAR \n");
		scanf("%d",&i);
		switch(i){
			case 1:
				depositocontapoupanca();
			break;
			case 2:
				depositocontacorrente();
			break;
			case 3:
				break;
			default:
				printf("OPCAO INVALIDA.\n");
		}
	}while(i!=3);
}

void submenusaldo(){
	int i;
	do{
		system("cls");
		printf("VERIFICAR SALDO \n\n");
		printf("[1] <-- SALDO CONTA POUPANCA \n");
		printf("[2] <-- SALDO CONTA CORRENTE \n");
		printf("[3] <-- VOLTAR \n");
		scanf("%d",&i);
		switch(i){
			case 1:
				saldocontapoupanca();
			break;
			case 2:
				saldocontacorrente();
			break;
			case 3:
				break;
			default:
				printf("OPCAO INVALIDA.\n");
		}
	}while(i!=3);
}

void menucliente(){
	int i;
	
	do{
		system("cls");
		printf("+--------------+\n");
		printf("| MENU CLIENTE |\n");
		printf("+--------------+\n\n");
		printf("[1] <-- SALDO \n");
		printf("[2] <-- DEPOSITO \n");
		printf("[3] <-- SAQUE \n");
		printf("[4] <-- EXTRATO \n");
		printf("[5] <-- CONSULTAR LIMITE \n");
		printf("[6] <-- SAIR \n");
		scanf("%d",&i);
		
		switch(i){
			case 1:
				submenusaldo();
			break;
			case 2:
				submenudeposito();
			break;
			case 3:
				submenusaque();
			break;
			case 4:
				submenuextrato();
			break;
			case 5:
				submenuconsultarlimite();
			break;
			case 6:
				break;
			default:
				printf("OPCAO INVALIDA.\n");
		}
	}while(i!=6);
}

void menuprincipal(){
	int i;
	do{
		system("cls");
		printf("\n\n[1] <-- funcionario \n");
		printf("[2] <-- cliente \n");
		printf("[3] <-- SAIR \n");
		scanf("%d",&i);
		
		switch(i){
			case 1:
				verificarsenhafunc();
				break;
			case 2:
				menucliente();
				break;
			case 3:
				break;
			default:
				printf("OPCAO INVALIDA.\n");			
		}
	}while(i!=3);
}

void logo(){
	printf("                                                                                                   ...::JJYJ::...                                            \n");
	printf("                                                                                               .~JPB##&&J&&&&J&&#BGPY~.                                      \n");
	printf("                                                                                           ^5#&&&&&&&&J&&&&J&&&&&&&&#5^                                      \n");
	printf("                                                                                          :P&&&&&&&&&&&J#&&&J&&&&&&&&&&&P:                                   \n");
	printf("                                                                                         ~#&&&&&&&&&&&&J#&&#J&&&&&&&&&&&&&!                                  \n");
	printf("                                                                                         ~&&&&&&&&&&&&&&J#&&#J&&&&&&&&&&&&&&~                                \n");
	printf("                                                                                        .#&&&&&&&&&&&&&&Y#&&#Y&&&&&&&&&&&&&&#.                               \n");
	printf("                                                                                        !&&&&&&&&&&&&&&&Y#&&#Y&&&&&&&&&&&&&&&!                               \n");
	printf("                                                                                        Y&&&&&&&&&&&&&&&Y#&&#Y&&&&&&&&&&&&&&&5                               \n");
	printf("                                                                                        B&&&&&&&&&&&&&&&Y#&&#Y&&&&&&&&&&&&&&&B                               \n");
	printf("                                                                                       :&&&&&&&&&&&&&&&&Y#&&#Y&&&&&&&&&&&&&&&&:                              \n");
	printf("                                                                                       7&&&&&&&&&&&&&&&&5#&&#5&&&&&&&&&&&&&&&&?                              \n");
	printf("                                                                                       G&&&&&#BBGBB##&&&#&&&&#&&&&#BBGGB#&&&&&G                              \n");
	printf("                                                                                     .P&&#GPPPGBBBGPPG#&&&&&&&&#GPPGGBGGPPPG#&&P.                            \n");
	printf("                                                                                    !#&&#B##BB#P5PB&&&&&&&&&&&&&&&&BP5P#BB####&&#7                           \n");
	printf("                                                                                  .P&&&&&GJYGG^    .7B&&&&&&&&&&G7.    ^GGYJG&&&&&P.                         \n");
	printf("                                                                                 ~#&&&&B75#&B.        ~G&&&&&&G~        .G&#57G&&&&#!                        \n");
	printf("                                                                                Y&&&&&Y7#&&&#5?~:.     J5B##B5J     ..^?5#&&&#?Y&&&&&Y.                      \n");
	printf("                                                                              .G&&&&&?J&&&&&&GG##BGPP5P#&G55G&#P5PPGB##BG&&&&&&Y?&&&&&G.                     \n");
	printf("                                                                             .G&&&&&7Y&&&&&&&&B55555PB#&&B55B&&#BGP555PB&&&&&&&&5?&&&&&B.                    \n");
	printf("                                                                            .G&&&&&JJ&&&&&&&&BGGPPPPGPG&&&&&&&&GGGGPPPBGB&&&&&&&&JJ&&&&&G.                   \n");
	printf("                                                                            5&&&&&Y7&&&&&&&&&&#GB##PJ?Y#&#PP#&#Y?JP##BB#&&&&&&&&&&7Y&&&&&P                   \n");
	printf("                                                                          Y&&&&&G^&&&&&&&&&#&&&&&J5#&&&&^  ^&&&&#5J&&&&&#&&&&&&&&&~P&&&&&J                   \n");
	printf("                                                                         !&&&&&#^B&&&&&&&&&GG&&&YP&&&&G! ^^ !G&&&&PY&&&GG&&&&&&&&&B^#&&&&&!                  \n");
	printf("                                                                         .B&&&&&7?&&&&&&&&&&&?B&#5&&&P~!J.&#.?!~P&&&5#&B?&&&&&&&&&&&?7&&&&&#.                \n");
	printf("                                                                          ^G&&&#~&&#BGP5YYYYPB~#&&&P7! #G.##.G# !7P&&&#~BPYYYY5PGB#&&^B&&&G^                 \n");
	printf("                                                                            !B&J^7^..        PJ~#5: BG BG.##.GB GB :5#~JP        ..:!^J&B!                   \n");
	printf("                                                                              !:             .G~~.:^YJ^YJ^YY^JY^?Y^: ~~G.             :!.                    \n");
	printf("                                                                                              ....^J5PGPPPPPPPPGP5?: ...                                     \n");
	printf("                                                                                                    .~JG#&&&&#GJ~.                                           \n");
	printf("                                                                                                        .^J?^.                                               \n");
	printf("_________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
	printf("                                    |||\xDB\xDB||||||||||||||\xDB\xDB|||||\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB|||||\xDB\xDB|||||||||||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB|||||\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB|||||||\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB|||||\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB|||||\n");
	printf("                                    |||\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB|||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB|||||||||||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB||||\xDB\xDB\xDB\xDB|||||\xDB\xDB|||||||||||||\xDB\xDB||||||||\xDB\xDB|||||\n");
	printf("                                    |||\xDB\xDB||||\xDB\xDB\xDB\xDB\xDB\xDB||||\xDB\xDB|||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB|||||||||||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB|||||||||||||\xDB\xDB||||||||\xDB\xDB|||||\n");
	printf("                                    |||\xDB\xDB|||||\xDB\xDB\xDB\xDB|||||\xDB\xDB|||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB|||||||||||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB|||||||||||||\xDB\xDB||||||||\xDB\xDB|||||\n");
	printf("                                    |||\xDB\xDB||||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB|||||\xDB\xDB|||||||||||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB|||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB|||||\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB|||||\n");
	printf("                                    |||\xDB\xDB||||||||||||||\xDB\xDB|||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB|||||||||||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB|||||||||||||\xDB\xDB||||||\xDB\xDB|||||||\n");
	printf("                                    |||\xDB\xDB||||||||||||||\xDB\xDB|||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB|||||||||||||\xDB\xDB\xDB\xDB||\xDB\xDB\xDB\xDB|||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB|||||||||||||\xDB\xDB||||||\xDB\xDB|||||||\n");
	printf("                                    |||\xDB\xDB||||||||||||||\xDB\xDB|||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB|||||||||||||||\xDB\xDB\xDB\xDB\xDB\xDB|||||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB||||\xDB\xDB\xDB\xDB|||||\xDB\xDB|||||||||||||\xDB\xDB||||||\xDB\xDB|||||||\n");
	printf("                                    |||\xDB\xDB||||||||||||||\xDB\xDB|||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB|||||||||\xDB\xDB|||||||||\xDB\xDB||||||\xDB\xDB|||||\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB|||||||\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB|||||\xDB\xDB||||||\xDB\xDB\xDB\xDB\xDB\xDB|||\n");
	printf("_________________________________________________________________________________________________________________________________________________________________________________________________________________");
}

int main(){
	logo();
	system("pause");
	menuprincipal();

return 0;
}
