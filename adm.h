#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "struct.h"

void adm(void)
{
    int op;
    op = 0;
    while(op < 5)
    {
        system("cls");

        printf("***************Escolha a opção administrativa desejada***************\n\n");

        printf("1 - Cadastro de usuários");
        printf("\n2 - Entrada de veículos");
        printf("\n3 - Manutenção programada");
        printf("\n4 - Cadastro de clientes");
        printf("\n5 - Retornar menu anterior\n\n");

        scanf("%d", &op);

        if(op == 1)
        {
            fflush(stdin);

            struct Usuario usu1;

            printf("Digite o nome\n");
            gets(usu1.Nomusu);
            printf("Nome: %s", usu1.Nomusu);
            getch();



        }


        if(op == 2)
        {
        //Entrade de Veículos
        }

        if(op == 3)
        {
            system("cls");
            op = 0;

            printf("***************Escolha a opção administrativa desejada***************\n\n");
            printf("\n1 - Manutenção Programda");
            printf("\n2 - Vistoria veicular");
            printf("\n3 - retornar opção anterior\n\n");

            scanf("%d", &op);

            if(op == 1)
            {
                //Manutenção programada
            }

            if(op == 2)
            {
                //Vistoria veicular
            }
        }

        if(op == 4)
        {
            //Cadastro de Cliente
        }
    }
    system("cls");
}
