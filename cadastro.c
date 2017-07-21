#include<stdio.h>
#include<stdlib.h>
#define MAX_ALUNOS 30

typedef struct aluno
{
    int id;
    char nome[30];
    int turma;
    float provas[4];
    float freq;
} Aluno;

void cadastrar( Aluno *a, int size);
void exibir_todos(Aluno *p, int size);
void exibir_aprovados(Aluno *p, int size);
void exibir_media_turma(Aluno *p, int size, int turma);

int main()
{
    int option, t, size, total = 0;
    Aluno *alunos[MAX_ALUNOS];
    //alunos = (Aluno*) malloc(MAX_ALUNOS + total * sizeof(Aluno));

    while(1)
    {
        printf("1. Cadastrar alunos\n2. Exibir todos os alunos\n3. Exibir alunos aprovados\n4. Exibir media final de turma\n5. Sair\n");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            printf("Quantos alunos deseja cadastrar?\n");
            scanf("%d", &size);
            total += size;
            cadastrar(&alunos, size);
            break;
        case 2:
            exibir_todos(&alunos, total);
            break;
        case 3:
            exibir_aprovados(&alunos, total);
            break;
        case 4:
            printf("Qual turma deseja exibir a media? ");
            scanf("%d", &t);
            exibir_media_turma(&alunos, total, t);
            break;
        case 5:
            //free(alunos);
            exit(0);
        default:
            printf("Comando nao reconhecido...\n");
        }
    }
    return 0;
}

void cadastrar( Aluno *a, int size)
{
    int i, provas;
    static int id = 0;
    system("cls");
    for(i = 0; i < size; i++)
    {
        if(id < MAX_ALUNOS)
        {
            //id, nome, provas, freq;
            printf("Registro de aluno\n");
            //id
            a[id].id = id;
            //nome
            printf("Nome: ");
            fflush(stdin);
            scanf("%[^\n]s", a[id].nome);
            a[id].nome[strlen(a[id].nome)] = '\0';
            //provas
            for(provas = 0; provas < 4; provas++)
            {
                printf("Nota da prova %d (separado por .):", provas);
                fflush(stdin);
                do
                {
                    scanf("%f", &a[id].provas[provas]);
                    if(!(a[id].provas[provas] >= 0 && a[id].provas[provas] <=10))
                        printf("Nota invalida, por favor insira uma nota entre 0 e 10...\n");
                }
                while (!(a[id].provas[provas] >= 0 && a[id].provas[provas] <=10));
            }
            //turma
            printf("Turma: ");
            scanf("%d", &a[id].turma);
            //freq
            printf("Frequencia: ");
            do
            {
                fflush(stdin);
                scanf("%f", &a[id]. freq);
                fflush(stdin);
                if(!(a[id].freq >=0 && a[id].freq <= 100)) printf("Frequencia invalida, por favor insira uma frequencia entre 0 e 100...\n");
            }
            while(!(a[id].freq >=0 && a[id].freq <= 100));
            id++;
        }
        else printf("Maximo de alunos atingido...\n");
        system("cls");
        printf("Aluno cadastrado com sucesso!\n");
        printf("Pressione ENTER para continuar...\n");
        getchar();
        system("cls");
        fflush(stdin);
    }

}

void exibir_todos(Aluno *p, int size)
{
    int i, j;
    system("cls");
    printf("==========================================\n");
    for(i = 0; i < size; i++)
    {
        //id, nome, turma, provas, freq;
        printf("%d - Nome: %s\n", p[i].id, p[i].nome);
        printf("Turma: %d\n", p[i].turma);
        -
        printf("Nota das provas: \n");
        for(j = 0; j < 4; j++)
        {
            printf("Prova %d: %.2f\n",j+1, p[i].provas[j]);
        }
        printf("Frequencia: %.2f\n", p[i].freq);
        printf("==========================================\n");
    }
    printf("Pressione ENTER para continuar...\n");
    fflush(stdin);
    getchar();
    system("cls");
}

void exibir_aprovados(Aluno *p, int size)
{
    int i, j, aprovados = 0;
    float media;
    system("cls");
    printf("Alunos aprovados: \n");
    printf("==========================================\n");
    for(i = 0; i < size; i++)
    {
        media = 0.0f;
        for(j = 0; j < 4; j++)
            media += p[i].provas[j];
        media /= 4;
        if(media >= 6 && p[i].freq >= 75)
        {
            printf("Nome: %s\n", p[i].nome);
            printf("Media: %.2f\n", media);
            printf("Frequencia: %.2f\n", p[i].freq);
            printf("==========================================\n");
            aprovados++;
        }
    }
    if(aprovados == 0) printf("Nenhum aluno foi aprovado...\n");
    printf("Pressione ENTER para continuar...\n");
    fflush(stdin);
    getchar();
    system("cls");
}

void exibir_media_turma(Aluno *p, int size, int turma)
{
    int i, j, alunoTurma = 0;
    float mediaA, mediaT = 0.0f;

    system("cls");
    for(i = 0; i < size; i++)
    {
        mediaA = 0.0f;
        if(p[i].turma == turma)
        {
            for(j=0; j<4; j++)
            {
                mediaA += p[i].provas[j];
            }
            mediaA /= 4;
            mediaT += mediaA;
            alunoTurma++;
        }
    }
    mediaT /= alunoTurma;
    if(alunoTurma > 0)
        printf("A media da turma eh %.2f pontos.\n", mediaT);
    else printf("Nenhum aluno esta registrado na turma %d..\n", turma);
    printf("Pressione ENTER para continuar...\n");
    fflush(stdin);
    getchar();
    system("cls");
}
