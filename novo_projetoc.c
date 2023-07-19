#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define SIZE 100
#define SIZEPACIENTE 50


struct cadastro{
char nome_adm[50];
int login_adm;
int senha_adm;
}adm[];//struct de cadastro do administrador

struct endereco {
char rua[40];
int numero;
char bairro[40];
char cidade[40];
char estado[2];
int cep;
}enderecopaciente[];//struct de endereço do paciente

struct datanas{
int dia,mes,ano_nas;

}datanaspaciente[];//struct de data


char paciente[SIZE][50];
char resposta_risco[SIZE][50];
char cpf[SIZE][50];
char telefone[SIZE][50];
int res;
char resposta[100];
struct endereco enderecopaciente[50];
struct datanas datanaspaciente[10];
char nome[SIZE][50];
int login[SIZE];
int senha[SIZE];
int opcao;
void cadastroPaciente();
void listaPaciente();
void pesquisaFuncionario();
void cadastroFuncionario();
void abertura();
void autenticacao();
void listaFuncionario();
void pesquisaPaciente();
void calcidade();

int main(void){
    abertura();
    autenticacao();
    cadastroFuncionario();
    cadastroPaciente();
    pesquisaPaciente(resposta_risco);
    //listaFuncionario();
    //pesquisaFuncionario();
}
void calcidade() {
    int i;
    static int linha;
    int ano_atual = 2023;
    int ano = datanaspaciente[i].ano_nas;
    int idade = 0;
    do{
        printf("Digite a data de nascimento:\n");
        printf("Digite o dia:\n");
        scanf("%d", &datanaspaciente[linha].dia);
        printf("Digite o mês: \n");
        scanf("%d", &datanaspaciente[linha].mes);
        printf("Digite o ano de nascimento: \n");
        scanf("%d", &datanaspaciente[linha].ano_nas);
        int idade = ano_atual - datanaspaciente[linha].ano_nas;
            if (idade > 65) {
                strcpy(resposta, "Atenção!\nPaciente pertence ao grupo de risco!");
                strcpy(&resposta_risco[linha],resposta);
                linha++;

            }
            if(idade <=64) {
                strcpy(resposta, "Paciente não pertence ao grupo de risco.");
                strcpy(&resposta_risco[linha],resposta);
                linha++;
            }

    }while(idade != 0);
}
void autenticacao(){
    int i=0;
    int login_adm = 2022;
    const senha_adm = 250854;
    printf("Digite seu login: \n");
    scanf("%4d",&login_adm);
    printf("Digite sua senha: \n");
    scanf("%6d",&senha_adm);
    if (login_adm == 2022 && senha_adm == 250854 || login_adm == login[i] && senha[i]){
        printf("________________________________________________________\n");
        printf("\n***** Voce esta autenticado! *****\n\a");
            return;
    }else
        {   printf("________________________________________________________\n");
            printf("\n***** Voce não esta autenticado! *****\n");}
            autenticacao();

}
void listaFuncionario(){
    int i;
    for(i=0;i<SIZE;i++){
        if(login[i]>0){
             printf("\nNome: %s \nLogin: %d", nome[i], login[i]);
        }

    }
}
void pesquisaPaciente(char *resposta_risco[SIZE][50]){
    char cpfPesquisa[SIZEPACIENTE];
    char pacientePesquisa[SIZEPACIENTE];
    int i;
    do{
            printf("\nDigite 1 para pesquisar por CPF ou 2 para pesquisar o nome do paciente:");
            scanf("%d",&opcao);
            switch(opcao){
                case 1:
                    printf("\nDigite o CPF:");
                    scanf("%s",&cpfPesquisa);
                    for(i=0;i<SIZEPACIENTE;i++){
                        if(strcmp(cpf[i], cpfPesquisa)==0){
                            printf("\nNome: %s\nCPF: %s\nTelefone: %s\nRua: %s\nNumero: %d\nEstado: %s\nCidade: %s\nCEP: %d\n%d/%d/%d \n\nPaciente pertence ao grupo de risco? %s",
                                   paciente[i], cpf[i], telefone[i], enderecopaciente[i].rua , enderecopaciente[i].numero,
                                   enderecopaciente[i].estado, enderecopaciente[i].cidade, enderecopaciente[i].cep, datanaspaciente[i].dia, datanaspaciente[i].mes,datanaspaciente[i].ano_nas, resposta_risco[i]);
                            }
                            }

                    break;
                case 2:
                    printf("\nDigiete o nome do paciente:");
                    scanf("%s",&pacientePesquisa);
                    for(i=0;i<SIZEPACIENTE;i++){
                        if(strcmp(paciente[i], pacientePesquisa)==0){
                            printf("\nNome: %s \nCPF: %s \nTelefone: %s\nRua: %s\nNumero: %d\nEstado: %s\nCidade: %s\nCEP: %d\n%d/%d/%d \nPaciente pertence ao grupo de risco? %s", paciente[i], cpf[i], telefone[i], enderecopaciente[i].rua ,
                                   enderecopaciente[i].numero, enderecopaciente[i].estado,
                                   enderecopaciente[i].cidade, enderecopaciente[i].cep, datanaspaciente[i].dia, datanaspaciente[i].mes,datanaspaciente[i].ano_nas, resposta_risco[i]);
                            }
                            }
                    break;
                default:
                    printf("\nOpçao Invalida!");
                    break;

    }



    }while(opcao==1 || opcao==2);
}

void abertura(){
  printf("\n");
  printf("________________________________________________________");
  printf("\n\n");
  printf("****************  SEJA MUITO BEMVINDO!  **************** \n\nSAMPCOVID-19 - SISTEMA DE ACOMPANHAMENTO E MONITORAMENTO \nDE PACIENTES COM COVID-19.\n");
  printf("________________________________________________________");
    printf("\n\nFAÇA SEU LOGIN PARA PODER ACESSAR O SISTEMA.\n\n");

}
void cadastroFuncionario(){
    static int linha;
    do{
        printf("Digite o nome do funcionario:\n");
        scanf("%s",&nome[linha]);
        printf("Digite o login:\n");
        scanf("%d",&login[linha]);
        printf("Digite a senha:\n");
        scanf("%d",&senha[linha]);
        printf("Digite 1 para continuar ou 2 para sair");
        scanf("%d",&opcao);
        linha++;

    }while(opcao == 1);

}// Fim do Cadastro dos Funcionários
void pesquisaFuncionario(){
    char pesquisaNome[50];
    int pesquisaLogin;
    int i;
    do{
            printf("Digite 1 para pesquisar nome ou 2 para pesquisar login:\n");
            scanf("%d",&opcao);
            switch(opcao){
                case 1:
                    printf("Digite o nome:\n");
                    scanf("%s",&pesquisaNome);
                    for(i=0;i<SIZE; i++){
                        if(strcmp(nome[i], pesquisaNome)==0){
                            printf("\nNome: %s \nLogin: %d", nome[i], login[i]);
                        }
                    }
                    break;
                case 2:
                    printf("Digite o Login:");
                    scanf("%d",&pesquisaLogin);
                    for(i=0;i<SIZE;i++){
                        if(login[i] == pesquisaLogin){
                            printf("\nNome: %s \nLogin: %d",nome[i],login[i]);
                        }
                    }
                    break;
                default:
                    printf("Opção Inválida!\n");
                    break;

            }
            printf("\nDigite 1 para continuar pesquisando");
            scanf("%d",&opcao);
    }while(opcao==1);
}
void cadastroPaciente(){
    static int linha;
    do{
        printf("Digite o nome do paciente:\n");
        scanf("%s",&paciente[linha]);
        printf("Digite o  cpf:\n");
        scanf("%s",&cpf[linha]);
        printf("Digite o telefone:\n");
        scanf("%s",&telefone[linha]);
        printf("Digite o endereco:\n");
        printf("Digite a rua:\n");
        scanf("%s",&enderecopaciente[linha].rua);
        printf("Digite o numero:\n");
        scanf("%d",&enderecopaciente[linha].numero);
        printf("Digite o bairro:\n");
        scanf("%s",&enderecopaciente[linha].bairro);
        printf("Digite a cidade:\n");
        scanf("%s",&enderecopaciente[linha].cidade);
        printf("Digite estado:\n");
        scanf("%s",&enderecopaciente[linha].estado);
        printf("Digite o CEP:\n");
        scanf("%d",&enderecopaciente[linha].cep);
            calcidade();
        printf("Digite 1 para continuar ou 2 para sair");
        scanf("%d",&opcao);
        linha++;

    }while(opcao == 1);
}

// Fim do Cadastro dos Pacientes
