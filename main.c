#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "struct.h"
#include <string.h>
#include <conio.h>

 struct Veiculo Carro[23];
 struct Cliente Cli[100];
 int x,y,xa;



int main()
{
     x = 0;
     y = 0;
     xa = 0;
    setlocale(LC_ALL,"Portuguese");

CriaCarro(Carro);

//criacliteste(Cli);

Menu();


}
void Menu(void)
{
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
    while(op < 3)
    {
        system("cls");

        printf("******************** ######################## ********************\n");
        printf("*              ESCOLHA A OP��O ADMINISTRATIVA DESEJADA           *\n");
        printf("******************** ######################## ********************\n\n");

        printf("1 - Cadastro de Cliente");
        printf("\n2 - Altera��o de Cadastro");
        printf("\n3 - Retornar menu anterior\n\n");

        scanf("%d", &op);

        if(op == 1)
        {
            printf("******************** ## CADASTRO DE USU�RIO ## ********************\n\n");

            for(int i = 1; i <= 100; i++)
            {
                if(Cli[i].CodCli == 0)
                {
                    printf("Digite o nome do cliente: ");
                    scanf("%s", &Cli[i].NomCli);

                    printf("\nDigite o CPF do cliente: ");
                    scanf("%s", &Cli[i].CPF);

                    Cli[i].CodCli = i;

                    system("cls || clear");

                    gotoxy(45,10);
                    printf("CLIENTE CADASTRADO COM SUCESSO!\n");
                    gotoxy(50,11);
                    printf("C�DIGO CADASTRADO: %d", Cli[i].CodCli);
                    sleep(3);
                    system("CLS || CLEAR");

                    MenuAdm();
                }
            }
        }

        if(op == 2)
        {

        }

        if(op == 3)
        {
            system("cls");
            Menu();
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
    system("cls");
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
        printf("\n3 - Relatorio de Loca��es\n\n");


        scanf("%d",&op);

        if (op == 1)
        {
            system("cls");

            int CodVeiculo
                ,CodCli
                ,VlrDia
                ,OpTipoCarro
                ,OpGrupo
                ,ExistCli
                ,PosCli
                ,TpSeg;
            float vlrBas;

            char OpSeg[1];

            vlrBas = 50;
            ExistCli = 0;

            printf("******************** ######################## ********************\n");
            printf("*                       Sa�da de Ve�culos                        *\n");
            printf("*                           Autom�veis                           *\n");
            printf("******************** ######################## ********************\n\n");
//
//            printf("Data da loca��o \n");
//            scanf("%d",&Dia);
//            printf("/");
//            scanf("%d",&Mes);
//            printf("/");
//            scanf("%d",&Ano);

            while(ExistCli == 0)
            {

                printf("C�digo do cliente: ");
                scanf("%d", &CodCli);

                for(int i = 1; i < 100; i++)
                {
                    if(CodCli == Cli[i].CodCli)
                    {
                        ExistCli = 1;
                        PosCli = i;
                    }
                }

                if(ExistCli == 1)
                {
                    printf("Usu�rio: %s\n\n", Cli[PosCli].NomCli);


                    do{

                            printf("******************** ## ESCOLHA UM GRUPO ## ********************\n\n");

                            printf("1 - Hatch\n");
                            printf("2 - Sedan\n");
                            printf("3 - Utilit�rio\n");
                            printf("4 - Retornar ao menu anterior\n");

                            scanf("%d", &OpTipoCarro);

                            switch(OpTipoCarro)
                            {
                                case 1:

                                    x = 11;
                                    y = 12;
                                    int seq;

                                    seq = 1;


                                    system("cls");

                                    printf("Op��o escolhida: 1 - Hatch\n\n");
                                    printf("******************** ## ESCOLHA UM TIPO ## ********************\n\n");

                                    printf("11 - Hatch B�sico Econ�mico\n");
                                    printf("12 - Hatch Econ�mico\n");
                                    printf("13 - Hatch Plus\n");
                                    printf("14 - Hatch Plus Autom�tico\n");
                                    printf("Op��o: ");

                                    scanf("%d", &OpGrupo);
                                    printf("\n\nC�digo");
                                    gotoxy(x,y);
                                    printf("Carro");
                                    gotoxy(x+11,y);
                                    printf("Dispon�vel\n");

                                    for(int i = 0; i <= 23; i++)
                                    {

                                        if(OpGrupo == Carro[i].Grupo)
                                        {
                                            printf("%d - ",seq);

                                                gotoxy(x,y=y+1);
                                                printf("%s", Carro[i].Model);

                                            if(Carro[i].ClienteCar == 0)
                                            {
                                                gotoxy(x+11,y);
                                                printf("[S]\n");
                                            }
                                            else
                                            {
                                                gotoxy(x+11,y);
                                                printf("[N]\n");
                                            }
                                            seq++;
                                            sleep(1);
                                        }

                                    }

                                    printf("*************************************\n");
                                    printf("Digite o c�digo do carro desejado\n");
                                    printf("*************************************\n\n");
                                    printf("Op��o: ");
                                    scanf("%d", &CodVeiculo);

                                    for(int i = 0; i <= 23; i++)
                                    {
                                        if(Carro[i].Grupo == OpGrupo)
                                        {
                                            if(Carro[i].CodVeiculo == CodVeiculo)
                                            {
                                                Carro[i].ClienteCar = CodCli;

    //                                            system("cls || clear");
    //
    //                                            gotoxy(45,10);
    //                                            printf("CLIENTE CADASTRADO COM SUCESSO!");
    //                                            sleep(3);
    //                                            system("cls || clear");
    //
    //
    //                                            Menu();
                                            }
                                        }
                                    }





                                    break;

                                case 2:
                                    OpGrupo = 0;
                                    system("cls");

                                    printf("Op��o escolhida: 2 - Sedan\n\n");

                                    printf("21 - Sedan Compacto\n");
                                    printf("22 - Sedan Compacto Plus\n");
                                    printf("23 - Sedan Compacto Plus Autom�tico\n");

                                    scanf("%d", &OpGrupo);
                                    break;

                                case 3:
                                    OpGrupo = 0;
                                    system("cls");

                                    printf("Op��o escolhida: 3 - Utilit�rio\n\n");

                                    printf("31 - SUV Manual\n");
                                    printf("32 - SUV Autom�tico\n");
                                    printf("33 - Pick-Up Cabine Simples\n");
                                    printf("34 - Pick-Up Cabine Dupla\n");
                                    printf("35 - Pick-Up Cabine Dupla Autom�tico\n");
                                    printf("36 - Van 15 Lugares\n");

                                    scanf("%d", &OpGrupo);

                                case 4:
                                    MenuLoc();

                                default:
                                    system("cls || clear");

                                    gotoxy(45,10);
                                    printf("Digite uma op��o v�lida!\n\n");

                                    sleep(3);

                                    system("cls || clear");
                                    break;

                            }
                        system("cls");

                        printf("******************** ######################## ********************\n");
                        printf("*                       Sa�da de Ve�culos                        *\n");
                        printf("*                            Seguro                              *\n");
                        printf("******************** ######################## ********************\n\n");

                        printf("Deseja adicionar o seguro? (S/N)\n");
                        printf("(");
                        gotoxy(5,7);
                        printf(")");

                        scanf("%s", OpSeg);

                        int a;
                        a = 0;
                        a = strcmp(OpSeg, "s");


                        if(a == 0)
                        {
                            system("cls");

                            printf("******************** ######################## ********************\n");
                            printf("*                       Sa�da de Ve�culos                        *\n");
                            printf("*                            Seguro                              *\n");
                            printf("******************** ######################## ********************\n\n");

                            printf("1 - Gold\n");
                            printf("2 - Diamond\n");
                            printf("3 - Platinum\n");
                            printf("4 - Sair\n\n");

                            scanf("%d", &TpSeg);

                            switch(TpSeg)
                            {
                                case 1:
                                    for(int i = 0;i <= 23; i++)
                                    {
                                        if(Carro[i].Grupo == OpGrupo)
                                        {
                                            if(Carro[i].CodVeiculo == CodVeiculo)
                                            {
                                                Carro[i].Seg = TpSeg;

                                                system("CLS || CLEAR");

                                                gotoxy(45,10);
                                                printf("SEGURO ADICIONADO COM SUCESSO!\n");
                                                gotoxy(45,11);
                                                printf("SEGURO ESCOLHIDO: %d", Carro[i].Seg);
                                                printf(" - Seguro Gold");
                                                gotoxy(50,12);
                                                printf("OBRIGADO PELA PREFER�NCIA!");
                                                sleep(3);
                                                system("CLS || CLEAR");

                                                Menu();
                                            }
                                        }
                                    }

                                    break;

                                case 2:
                                     for(int i = 0;i <= 23; i++)
                                    {
                                        if(Carro[i].Grupo == OpGrupo)
                                        {
                                            if(Carro[i].CodVeiculo == CodVeiculo)
                                            {
                                                Carro[i].Seg = TpSeg;

                                                system("CLS || CLEAR");

                                                gotoxy(45,10);
                                                printf("SEGURO ADICIONADO COM SUCESSO!\n");
                                                gotoxy(45,11);
                                                printf("SEGURO ESCOLHIDO: %d", Carro[i].Seg);
                                                printf(" - Seguro Diamond");
                                                gotoxy(50,12);
                                                printf("OBRIGADO PELA PREFER�NCIA!");
                                                sleep(3);
                                                system("CLS || CLEAR");

                                                Menu();
                                            }
                                        }
                                    }

                                    break;

                                case 3:
                                     for(int i = 0;i <= 23; i++)
                                    {
                                        if(Carro[i].Grupo == OpGrupo)
                                        {
                                            if(Carro[i].CodVeiculo == CodVeiculo)
                                            {
                                                Carro[i].Seg = TpSeg;

                                                system("CLS || CLEAR");

                                                gotoxy(45,10);
                                                printf("SEGURO ADICIONADO COM SUCESSO!\n");
                                                gotoxy(45,11);
                                                printf("SEGURO ESCOLHIDO: %d", Carro[i].Seg);
                                                printf(" - Seguro Platinum");
                                                gotoxy(50,12);
                                                printf("OBRIGADO PELA PREFER�NCIA!");
                                                sleep(3);
                                                system("CLS || CLEAR");

                                                Menu();
                                            }
                                        }
                                    }

                                    break;

                                default:

                                    Menu();

                            }

                        }
                        else
                        {
                            printf("Davi � baitol�o!");
                        }

                    }while(OpTipoCarro);

                }
                else
                {
                    printf("Cliente n�o encontrado!\n\n");
                }
            }
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

void CriaCarro(struct Veiculo Carro[23])
{

//    VE�CULOS DO GRUPO 11

    Carro[0].CodVeiculo = 1;
    Carro[0].ClienteCar = 0;
    Carro[0].AnoCar = 2017;
    Carro[0].Grupo = 11;
    strcpy(Carro[0].Model, "Up");
    strcpy(Carro[0].Marca, "Wolkswagen");

    Carro[1].CodVeiculo = 2;
    Carro[1].ClienteCar = 0;
    Carro[1].AnoCar = 2017;
    Carro[1].Grupo = 11;
    strcpy(Carro[1].Model, "Kwid");
    strcpy(Carro[1].Marca, "Renault");

//    VE�CULOS DO GRUPO 12

    Carro[2].CodVeiculo = 1;
    Carro[2].ClienteCar = 0;
    Carro[2].AnoCar = 2017;
    Carro[2].Grupo = 12;
    strcpy(Carro[2].Model, "K�");
    strcpy(Carro[2].Marca, "Ford");

    Carro[3].CodVeiculo = 2;
    Carro[3].ClienteCar = 0;
    Carro[3].AnoCar = 2017;
    Carro[3].Grupo = 12;
    strcpy(Carro[3].Model, "Onix");
    strcpy(Carro[3].Marca, "Chevrolet");

    Carro[4].CodVeiculo = 3;
    Carro[4].ClienteCar = 0;
    Carro[4].AnoCar = 2017;
    Carro[4].Grupo = 12;
    strcpy(Carro[4].Model, "Sandero");
    strcpy(Carro[4].Marca, "Renault");

//    VE�CULOS DO GRUPO 13

    Carro[5].CodVeiculo = 1;
    Carro[5].ClienteCar = 0;
    Carro[5].AnoCar = 2017;
    Carro[5].Grupo = 13;
    strcpy(Carro[5].Model, "Fiesta");
    strcpy(Carro[5].Marca, "Ford");

    Carro[6].CodVeiculo = 2;
    Carro[6].ClienteCar = 0;
    Carro[6].AnoCar = 2017;
    Carro[6].Grupo = 13;
    strcpy(Carro[6].Model, "Punto");
    strcpy(Carro[6].Marca, "Fiat");

//    VE�CULOS DO GRUPO 14

    Carro[7].CodVeiculo = 1;
    Carro[7].ClienteCar = 0;
    Carro[7].AnoCar = 2017;
    Carro[7].Grupo = 14;
    strcpy(Carro[7].Model, "Fiesta");
    strcpy(Carro[7].Marca, "Ford");

//    VE�CULOS DO GRUPO 21

    Carro[8].CodVeiculo = 1;
    Carro[8].ClienteCar = 0;
    Carro[8].AnoCar = 2017;
    Carro[8].Grupo = 21;
    strcpy(Carro[8].Model, "Ka+");
    strcpy(Carro[8].Marca, "Ford");

//    VE�CULOS DO GRUPO 22

    Carro[9].CodVeiculo = 1;
    Carro[9].ClienteCar = 0;
    Carro[9].AnoCar = 2017;
    Carro[9].Grupo = 22;
    strcpy(Carro[9].Model, "HB20 S");
    strcpy(Carro[9].Marca, "Hyundai");

    Carro[10].CodVeiculo = 2;
    Carro[10].ClienteCar = 0;
    Carro[10].AnoCar = 2017;
    Carro[10].Grupo = 22;
    strcpy(Carro[10].Model, "Prisma");
    strcpy(Carro[10].Marca, "Chevrolet");


//    VE�CULOS DO GRUPO 23

    Carro[11].CodVeiculo = 1;
    Carro[11].ClienteCar = 0;
    Carro[11].AnoCar = 2017;
    Carro[11].Grupo = 23;
    strcpy(Carro[11].Model, "HB20 S");
    strcpy(Carro[11].Marca, "Hyundai");

    Carro[12].CodVeiculo = 2;
    Carro[12].ClienteCar = 0;
    Carro[12].AnoCar = 2017;
    Carro[12].Grupo = 23;
    strcpy(Carro[12].Model, "Prisma");
    strcpy(Carro[12].Marca, "Chevrolet");

//    VE�CULOS DO GRUPO 31

    Carro[13].CodVeiculo = 1;
    Carro[13].ClienteCar = 0;
    Carro[13].AnoCar = 2017;
    Carro[13].Grupo = 31;
    strcpy(Carro[13].Model, "Duster");
    strcpy(Carro[13].Marca, "Renault");

    Carro[14].CodVeiculo = 2;
    Carro[14].ClienteCar = 0;
    Carro[14].AnoCar = 2017;
    Carro[14].Grupo = 31;
    strcpy(Carro[14].Model, "Renagade");
    strcpy(Carro[14].Marca, "Jeep");

//    VE�CULOS DO GRUPO 32

    Carro[15].CodVeiculo = 1;
    Carro[15].ClienteCar = 0;
    Carro[15].AnoCar = 2017;
    Carro[15].Grupo = 32;
    strcpy(Carro[15].Model, "Duster");
    strcpy(Carro[15].Marca, "Renault");

    Carro[16].CodVeiculo = 2;
    Carro[16].ClienteCar = 0;
    Carro[16].AnoCar = 2017;
    Carro[16].Grupo = 32;
    strcpy(Carro[16].Model, "Renagade");
    strcpy(Carro[16].Marca, "Jeep");

//    VE�CULOS DO GRUPO 33

    Carro[17].CodVeiculo = 1;
    Carro[17].ClienteCar = 0;
    Carro[17].AnoCar = 2017;
    Carro[17].Grupo = 33;
    strcpy(Carro[17].Model, "Montana");
    strcpy(Carro[17].Marca, "Chevrolet");

    Carro[18].CodVeiculo = 2;
    Carro[18].ClienteCar = 0;
    Carro[18].AnoCar = 2017;
    Carro[18].Grupo = 33;
    strcpy(Carro[18].Model, "Strada");
    strcpy(Carro[18].Marca, "Fiat");

//    VE�CULOS DO GRUPO 34

    Carro[19].CodVeiculo = 1;
    Carro[19].ClienteCar = 0;
    Carro[19].AnoCar = 2017;
    Carro[19].Grupo = 34;
    strcpy(Carro[19].Model, "Oroch");
    strcpy(Carro[19].Marca, "Renault");

//    VE�CULOS DO GRUPO 35

    Carro[20].CodVeiculo = 1;
    Carro[20].ClienteCar = 0;
    Carro[20].AnoCar = 2017;
    Carro[20].Grupo = 35;
    strcpy(Carro[20].Model, "Toro");
    strcpy(Carro[20].Marca, "Fiat");

    Carro[21].CodVeiculo = 2;
    Carro[21].ClienteCar = 0;
    Carro[21].AnoCar = 2017;
    Carro[21].Grupo = 35;
    strcpy(Carro[21].Model, "Oroch");
    strcpy(Carro[21].Marca, "Renault");

//    VE�CULOS DO GRUPO 36

    Carro[22].CodVeiculo = 1;
    Carro[22].ClienteCar = 0;
    Carro[22].AnoCar = 2017;
    Carro[22].Grupo = 36;
    strcpy(Carro[22].Model, "Ducato");
    strcpy(Carro[22].Marca, "Fiat");

    return Carro;
}

criacliteste(struct Cliente cli[3])
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

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}


