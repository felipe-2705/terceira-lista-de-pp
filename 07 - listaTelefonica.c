#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct endereco{
	char rua[31];
	int numero;
	char complemento[31];
	char bairro[31];
	char cep[21];
	char cidade[31];
	char estado[21];
	char pais[31];
} Endereco;

typedef struct telefone{
	int codInternacional;
	int codArea;
	int numero;
} Telefone;

typedef struct data{
	int dia;
	int mes;
	int ano;
} Data;

typedef struct lista{
    char nome[30];
    char email[30];
    struct endereco address;
    struct telefone fone;
    struct data dataNascimento;
    char Observacoes[100];
} Lista;
///Declaracao de funções
int menu();
struct lista cadastraContato(void);
void imprimirSimples(Lista cadastro);
void imprimirCompleto(Lista cadastro);
int retirar(Lista contato[100], int size);
void buscanome(Lista contato[100], int size);
void buscames(Lista contato[100], int size);
void buscamesedia(Lista contato[100], int size);
/// Programa
int main(int argc,char **argv){

    int x, Size = 0, i=0;
    struct lista contato[100];
    //lista agenda[100];

    x = menu();
    while(x != 9){
    switch (x)
    {
    case 1:
        contato[Size++] = cadastraContato();
        break;
    case 2:
        Size = retirar(contato, Size);
        break;
    case 3:
        for(i=0;i<Size;i++)
            imprimirSimples(contato[i]);
        system("pause");
        system("cls");
        break;
    case 4:
        for(i=0;i<Size;i++)
            imprimirCompleto(contato[i]);
        system("pause");
        system("cls");
        break;
    case 5:
        buscanome(contato, Size);
        system("pause");
        system("cls");
        break;
    case 6:
        buscames(contato, Size);
        system("pause");
        system("cls");
        break;
    case 7:
        buscamesedia(contato, Size);
        system("pause");
        system("cls");
        break;
    case 8:
        exit(1);
        break;
    }
    x = menu();
    }
    return EXIT_SUCCESS;
}
///Funções
int menu(){
    int x = 0;
    printf("Escolha a opcao que voce deseja: \n\n");
    printf("1: Inserir pessoa.\n");
    printf("2: Retirar pessoa.\n");
    printf("   Imprimir agenda.\n");
    printf("\t3: Nome, telefone e e-mail.\n");
    printf("\t4: Todos os dados.\n");
    printf("5: Buscar pelo primeiro nome.\n");
    printf("6: Buscar por mes de aniversario.\n");
    printf("7: Buscar por dia e mes de aniversario.\n");
    printf("8: Sair.\n");
    scanf("%d",&x);
    system("cls");
    if(x >=1 && x <=9){
       return x;
    }else{
        printf("Erro!\n\n");
        return -1;
    }
}
struct lista cadastraContato(void)
{
    Lista cadastro;
    fflush(stdin);
    printf("Nome: ");
    scanf("%[^\n]s",&cadastro.nome);
    fflush(stdin);
    printf("Email: ");
    scanf("%[^\n]s",&cadastro.email);
    fflush(stdin);
    ///Endereco
    printf("Endereco...\n");
    printf("\tRua: ");
    scanf("%[^\n]s",&cadastro.address.rua);
    fflush(stdin);
    printf("\tNumero: ");
    scanf("%d",&cadastro.address.numero);
    fflush(stdin);
    printf("\tComplemento: ");
    scanf("%[^\n]s",&cadastro.address.complemento);
    fflush(stdin);
    printf("\tBairro: ");
    scanf("%[^\n]s",&cadastro.address.bairro);
    fflush(stdin);
    printf("\tCEP: ");
    scanf("%[^\n]s",&cadastro.address.cep);
    fflush(stdin);
    printf("\tCidade: ");
    scanf("%[^\n]s",&cadastro.address.cidade);
    fflush(stdin);
    printf("\tEstado: ");
    scanf("%[^\n]s",&cadastro.address.estado);
    fflush(stdin);
    printf("\tPais: ");
    scanf("%[^\n]s",&cadastro.address.pais);
    fflush(stdin);
    ///Fone
    printf("Telefone...\n");
    printf("\tCod. Internacional: ");
    scanf("%d",&cadastro.fone.codInternacional);
    fflush(stdin);
    printf("\tCod. de Area: ");
    scanf("%d",&cadastro.fone.codArea);
    fflush(stdin);
    printf("\tNumero: ");
    scanf("%d",&cadastro.fone.numero);
    fflush(stdin);
    ///Data de nascimento
    printf("Data de nascimento...\n");
    printf("\tDia: ");
    scanf("%d",&cadastro.dataNascimento.dia);
    fflush(stdin);
    printf("\tMes: ");
    scanf("%d",&cadastro.dataNascimento.mes);
    fflush(stdin);
    printf("\tAno: ");
    scanf("%d",&cadastro.dataNascimento.ano);
    fflush(stdin);
    ///Observacoes
    printf("Observacoes: \n");
    scanf("%[^\n]s",&cadastro.Observacoes);
    fflush(stdin);
    system("cls");
    return cadastro;
}
void imprimirSimples(Lista cadastro){
    printf("%s\n",cadastro.nome);
    printf("%s\n",cadastro.email);
    printf("+%d %d %d\n\n",cadastro.fone.codInternacional,cadastro.fone.codArea,cadastro.fone.numero);
}
void imprimirCompleto(Lista cadastro){
    printf("%s\n",cadastro.nome);
    printf("%s\n",cadastro.email);
    printf("+%d %d %d\n",cadastro.fone.codInternacional,cadastro.fone.codArea,cadastro.fone.numero);
    printf("%s, %d, %s, %s, %s, %s, %s, %s.\n",cadastro.address.rua,cadastro.address.numero,cadastro.address.complemento,cadastro.address.bairro,cadastro.address.cep,cadastro.address.cidade,cadastro.address.estado,cadastro.address.pais);
    printf("%d/%d/%d.\n",cadastro.dataNascimento.dia, cadastro.dataNascimento.mes, cadastro.dataNascimento.ano);
    printf("%s \n\n",cadastro.Observacoes);
}
int retirar(Lista contato[100], int size){
    char nome[30];
    int i, j;
    printf("Digite o nome completo da pessoa que voce deseja retirar: ");
    fflush(stdin);
    scanf("%[^\n]s",&nome);
    fflush(stdin);

    for(i=0;i<size;i++){
        if(strcmp(nome, contato[i].nome) == 0){
           for(j=i;j<size-1;j++){
                contato[j] = contato[j+1];
           }
           size--;
        }
    }
    return size;
}
 void buscanome(Lista contato[100], int size){
char nome[30];
    int i;
    printf("Digite o nome da pessoa que deseja buscar: ");
    fflush(stdin);
    scanf("%[^\n]s",&nome);
    fflush(stdin);

    for(i=0;i<size;i++){
        if(strcmp(nome, contato[i].nome) == 0){
           imprimirSimples(contato[i]);
        }
    }
}
void buscames(Lista contato[100], int size){
     int mes, i;
     printf("Digite o mes que voce deseja filtrar: ");
     scanf("%d",&mes);
    for(i=0;i<size;i++){
        if(contato[i].dataNascimento.mes == mes){
           imprimirSimples(contato[i]);
        }
    }
}
void buscamesedia(Lista contato[100], int size){
     int mes, dia, i;
     printf("Digite o dia que voce deseja filtrar: ");
     scanf("%d",&dia);
     printf("Digite o mes que voce deseja filtrar: ");
     scanf("%d",&mes);

    for(i=0;i<size;i++){
        if((contato[i].dataNascimento.mes == mes) && (contato[i].dataNascimento.dia == dia)){
           imprimirSimples(contato[i]);
        }
    }
}
