//
//typedef struct {
//    int ano;
//    short mes;
//    short dia;
//} Data;

struct Cliente
{
    char NomCli[30]
        ,CPF[11];

//    Data DataNascimento;

    int CodCli,
        Idade;
};

struct Veiculo
{
    int CodVeiculo,
        ClienteCar,
        AnoCar,
        TipCar;

    char NomCar[20];


//    Data DataRetirada
//        ,DataEntrega;


//      CodVeiculo[0] = 1; //Astra
////    CodVeiculo[1] = 2; //Corsa
////    CodVeiculo[2] = 3; //Corolla

};


