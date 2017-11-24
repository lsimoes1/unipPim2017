#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "struct.h"
#include <string.h>

 struct Veiculo Carro[10];
 struct Cliente Cli[10];


int main()
{
    setlocale(LC_ALL,"Portuguese");

    CriaCarro(Carro);

    criacliteste(Cli);

    int op;

    op = 0;
    while(op != 5) //OP == 5 � DE TESTES
    {
        printf("******************** ######################## ********************\n");
        printf("*                    Escolha a Op��o Desejada                    *\n");
        printf("******************** ######################## ********************\n\n");
        printf("1 - Gest�o administrativa");
        printf("\n2 - Gest�o de loca��o");
        printf("\n3 - Financeiro");
        printf("\n4 - Encerrar aplica��o\n\n");

        scanf("%d", &op);

        if( op >= 5 )
        {
            system("cls");
            printf("\n\n\nDigite uma op��o v�lida!\n\n\n");
        }
        else
        {
            if(op == 1)
            {
                MenuAdm();
            }

            if(op == 2)
            {
               MenuLoc();
            }

            if(op == 3)
            {
                MenuFin();
            }
            if(op == 4)
            {
                system("cls");
                printf("\n\n\nPrograma ser� encerrado!");
            }

            if(op == 5)
            {

            }
        }
    }
}

void MenuAdm(void)
{
    int op;
    op = 0;
    while(op < 5)
    {
        system("cls");

        printf("******************** ######################## ********************\n");
        printf("*              Escolha a Op��o Administrativa Desejada           *\n");
        printf("******************** ######################## ********************\n\n");

        printf("1 - Cadastro de Usuario");
        printf("\n2 - Entrada de ve�culos");
        printf("\n3 - Manuten��o programada");
        printf("\n4 - Cadastro de clientes");
        printf("\n5 - Retornar menu anterior\n\n");

        scanf("%d", &op);

        if(op == 1)
        {

        }

        if(op == 2)
        {
        //Entrade de Ve�culos
        }

        if(op == 3)
        {
            system("cls");
            op = 0;

            printf("******************** ######################## ********************\n");
            printf("*              Escolha a Op��o Administrativa Desejada           *\n");
            printf("******************** ######################## ********************\n\n");

            printf("\n1 - Manuten��o Programda");
            printf("\n2 - Vistoria veicular");
            printf("\n3 - retornar op��o anterior\n\n");

            scanf("%d", &op);

            if(op == 1)
            {
                //Manuten��o programada
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

void MenuFin(void)
{
    int op;
    op = 0;
    system("cls");

    while(op != 4)
    {

        printf("******************** ######################## ********************\n");
        printf("*               Escolha a Op��o Fincaneira Desejada              *\n");
        printf("******************** ######################## ********************\n\n");


        printf("1-Gerar Nota Fiscal");
        printf("\n2-Gerar Fatura");
        printf("\n3-Recebimentos");
        printf("\n4-Pend�ncias de Pagamento");
        printf("\n5-Retornar Menu Anterior");

        scanf("%d", &op);

        if(op == 1)
        {
            //NotaFiscal
        }

        if(op == 2)
        {
            //GerarFatura
        }

        if(op == 3)
        {
            system("cls");

            printf("******************** ######################## ********************\n");
            printf("*           Escolha a Op��o de Recebimentos Desejada             *\n");
            printf("******************** ######################## ********************\n\n");

            printf("\n1 - Contas a Pagar");
            printf("\n2 - Contas a receber");
        }
        if(op == 4)
        {
            //Pend�ncias de Pagamento
        }
    }
}

void MenuLoc(void)
{
    int op;
    op = 0;
    system ("cls");
    while(op !=3)
    {
        printf("******************** ######################## ********************\n");
        printf("*                       Gest�o de Loca��o                        *\n");
        printf("******************** ######################## ********************\n");
        printf("\n1 - Saida de Veiculos");
        printf("\n2 - Relatorios de Veiculos");
        printf("\n3 - Relatorio de Loca��es");


        scanf("%d",&op);

        if (op == 1)
        {
            system("cls");

            int tpVeic, CodCli, VlrDia, OpTipoCarro, OpHatch, OpSedan, OpUtil;
            float vlrBas;

            vlrBas = 80;

            int Dia, Mes, Ano;

            printf("******************** ######################## ********************\n");
            printf("*                       Sa�da de Ve�culos                        *\n");
            printf("********************        Autom�veis        ********************\n");
            printf("******************** ######################## ********************\n");
//
//            printf("Data da loca��o \n");
//            scanf("%d",&Dia);
//            printf("/");
//            scanf("%d",&Mes);
//            printf("/");
//            scanf("%d",&Ano);

            printf("C�digo do cliente: \n");
            scanf("%d", &CodCli);
            int i;
            for(i = 0; i < 10; i++)
            {
                if(CodCli == Cli[i].CodCli)
                {
                    printf("%s\n\n", Cli[i].NomCli);

                    Cli[i].CodCli = 20;
                    break;
                }

            }

            int x;
            for(x = 0; x <= 10; x++)
            {
                printf("%d\n\n", Cli[x].CodCli);
            }



            printf("1 - Hatch\n");
            printf("2 - Sedan\n");
            printf("3 - Utilit�rio\n");

            scanf("%d", &OpTipoCarro);

            if(OpTipoCarro == 1)
            {
                system("cls");

                printf("Op��o escolhida: 1\n\n");

                printf("11 - Hatch B�sico Econ�mico\n");
                printf("12 - Hatch Econ�mico\n");
                printf("13 - Hatch Plus\n");
                printf("14 - Hatch Plus Autom�tico\n");

                scanf("%d", &OpHatch);



            }

            if(OpTipoCarro == 2)
            {
                system("cls");

                printf("Op��o escolhida: 2\n\n");

                printf("21 - Sedan Compacto\n");
                printf("22 - Sedan Compacto Plus\n");
                printf("23 - Sedan Compacto Plus Autom�tico\n");

                scanf("%d", &OpSedan);
            }

            if(OpTipoCarro == 3)
            {
                system("cls");

                printf("Op��o escolhida: 3\n\n");

                printf("21 - SUV Manual\n");
                printf("22 - SUV Autom�tico\n");
                printf("23 - Pick-Up Cabine Simples\n");
                printf("24 - Pick-Up Cabine Dupla\n");
                printf("25 - Pick-Up Cabine Dupla Autom�tico\n");
                printf("26 - Van 15 Lugares\n");

                scanf("%d", &OpUtil);

            }

            system("cls");

            printf("******************** ######################## ********************\n");
            printf("*                       Sa�da de Ve�culos                        *\n");
            printf("********************         Seguro           ********************\n");
            printf("******************** ######################## ********************\n");

        }

        if(op == 2)
        {
            //relatorio de veiculos
        }

        if(op == 3)
        {
        //relatorio de loca��es
        }
    }
}

void CriaCarro(struct Veiculo Carro[10])
{

    Carro[0].CodVeiculo = 1;
    Carro[0].ClienteCar = 0;
    Carro[0].AnoCar = 2017;
    Carro[0].TipCar = 0;
    strcpy(Carro[0].NomCar, "Toyota");

    Carro[1].CodVeiculo = 2;
    Carro[1].ClienteCar = 0;
    Carro[1].AnoCar = 2015;
    Carro[1].TipCar = 0;
    strcpy(Carro[1].NomCar, "Davi � baitola");

    return Carro;

}

void criacliteste(struct Cliente cli[3])
{
    cli[0].CodCli = 10;
    strcpy(cli[0].NomCli, "Davi Baitola");
    strcpy(cli[0].CPF, "40684748851");

    cli[1].CodCli = 2;
    strcpy(cli[1].NomCli, "Kananda");
    strcpy(cli[1].CPF, "92832");

    cli[2].CodCli = 5;
    strcpy(cli[2].NomCli, "Robinson Meu Ovo");
   strcpy(cli[2].CPF, "00001293");



}
