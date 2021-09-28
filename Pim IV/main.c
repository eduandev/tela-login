
#include <stdio.h> // padrão
#include <stdlib.h> // padrão
#include <string.h> // Essa biblioteca serve para usar os structs e manipulação de strings
#include <locale.h>
#include <conio.h>


void menuRetorno();
void cadastrarAgente();
void Login();

typedef struct Agente{
 float login[1];
 float senha[1];
} Agente;


void main(){
 setlocale(LC_ALL, "Portuguese");

int entrar;
        system("cls");
        printf("\n===================================================================\n");
        printf("\n                           MENU INICIAL                            \n");
        printf("\n                         AGENTES DA SAÚDE                          \n");
        printf("\n===================================================================\n");
        printf("\nO QUE DESEJA FAZER?\n");
        printf("\n 1 - Entrar\n");
        printf("\n 2 - Cadastrar\n");
        printf("\n 3 - Sair do Sistema\n");
        printf("\nOpção: ");
        scanf("%d", &entrar);

        switch(entrar) {

        case 1:Login();
            break;
        case 2:cadastrarAgente();
            break;
        case 3:exit(1);
            break;
        default:printf("\nOpção inválida\n");
                system("pause");
                system("cls");
                menuRetorno();
            break;
}
};


void menuRetorno(){

   int retorno;
        system("cls");
        printf("-------------------------------------------");
        printf("\nO QUE DESEJA FAZER?\n");
        printf("-------------------------------------------");
        printf("\n 1 - Tentar Novamente\n");
        printf("\n 2 - Voltar ao Menu Inicial\n");
        printf("\n 3 - Sair do Sistema\n");
        printf("\nOpção: ");
        scanf("%d", &retorno);

    switch(retorno){

        case 1:Login();
            break;
        case 2:main();
            break;
        case 3:exit(1);
        break;
        default:printf("\nOpção inválida");
            break;
}

}


void cadastrarAgente(){

        FILE *cadastroagente;
        Agente usuario;
        cadastroagente = fopen("cadastroa.txt","ab");

    if(cadastroagente != NULL){

        system("cls");
        printf("\n-------------------------------------------------------------\n");
        printf("\n              CADASTRO DE USUÁRIOS AGENTES DA SAÚDE          \n");
        printf("\n-------------------------------------------------------------\n");
        printf("\n Digite um email:");
        scanf("%s", usuario.login);

        printf("\n Digite uma senha:");
        scanf("%s", usuario.senha);

        fwrite(&usuario,sizeof(Agente),1,cadastroagente);
        printf("\n Dados cadastrados com Sucesso!\n");
        system("pause");
        main();

    }else{

        system("cls");
        printf("\nErro na execução os dados não foram cadastrados.");
        menuRetorno();
}
        fclose(cadastroagente);
};


void Login(){

        FILE *cadastroagente;
        Agente usuario;
        cadastroagente = fopen("cadastroa.txt","rb");

    if(cadastroagente == NULL){

        printf("\nSenha ou usuário incorretos!\n");

    }else{

        char log[50]; // responsável por armazenar a senha inserida pelo usuário
        char key[10];

        system("cls");
        printf("\n-------------------------------------------------------------\n");
        printf("\n                 LOGIN DOS AGENTES DA SAÚDE                  \n");
        printf("\n-------------------------------------------------------------\n");
        printf("\nemail:");
        scanf("%s", log); // armazenando os dados inseridos pelo usuário para o vetor login que está dentro da função main

        printf("\nsenha:");
        scanf("%s", key);


    while(fread(&usuario,sizeof(struct Agente),1,cadastroagente)) {

    if(strcmp(log,usuario.login)==0 && strcmp(key,usuario.senha)==0){

        printf("\nUsuário logado\n");

    }else{
        printf("\nSENHA OU USUÁRIO NÃO DEFINIDOS\n");
        system("pause");
        system("cls");
        menuRetorno();
}
}

}
fclose(cadastroagente);
}


//======================================================================================================//

