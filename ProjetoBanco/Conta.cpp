#include "Conta.h"

#include <iostream>
#include <string>

//Construtor padrão/default e também posso usar o construtor padrão para inicializar os atributos do objeto com algum
//valor padrão e evitar lixo de memória.
Conta::Conta(){

    this->Banco = "";
    this->Titular = "";
    this->Agencia = 0;
    this->NumeroDeContas = 0;
    this->Saldo = 0.0;
}


//Construotor com parametros 
Conta::Conta(std::string Banco, std::string Titular, int Agencia, int NumeroDeContas, double Saldo) {

    this->Banco = Banco;
    this->Titular = Titular;
    this->Agencia = Agencia;
    (*this).NumeroDeContas = NumeroDeContas;
    (*this).Saldo = Saldo;

    std::cout << "Construtor desse objeto: " << this << " Executado.\n";

}

Conta::~Conta() {
    std::cout << "Destrutor desse objeto: " << this << " Executado.\n";
}

bool Conta::Sacar(double Valor) {
   
    if (Saldo < Valor) {
        std::cout << "Saldo Insuficiente! " << '\n';
        std::cout << "Saldo Atual R$" << ConsultarSaldo() << '\n';
        return false;
    } 
    else {
        Saldo = Saldo - Valor;
        std::cout << "Transferência realizada com sucesso\n ";
        return true;
    }
}

void Conta::Depositar(double Valor) {
    Saldo += Valor;
    std::cout << "\nDeposito de R$" << Valor << " Realizado com sucesso!\n";
}

/*
AQUI O "DESTINO" É UM OBJETO DO TIPO CONTA, OU SEJA, O DESTINO SERÁ PARA UMA CONTA DE DESTINO QUE
NO CASO SERÁ UMA OUTRA CONTA
*/
void Conta::Transferir(Conta &Destino, double ValorTransferir) {
    if (Saldo < ValorTransferir) {
        std::cout << "Saldo Insuficiente. ";
    }
    else {
        /*Aqui o Destino está com o Objeto passado para a função,
        logo vai chamar o método Depositar desse objeto
        */
        Destino.Depositar(ValorTransferir);
        /*Depois de depositar você deve retirar este valor depositado do saldo*/
        Saldo -= ValorTransferir;

        /*
        Aqui está indo no Objeto Destino e trazendo as informações dos dados da Conta
        do destinatário, ou seja, para onde foi o dinheiro
        */
        std::cout << "\n*****DADOS*****\n";
        std::cout << "Banco: " << Destino.GetBanco() << "\n";
        std::cout << "Titular: " << Destino.GetTitular() << "\n";
        std::cout << "Agência: " << Destino.GetAgencia() << "\n";
        std::cout << "Número da Conta: " << Destino.GetNumeroDaConta() << "\n";
        std::cout << "Transferência de R$" << ValorTransferir << " realizada com sucesso!\n";
        std::cout << "Saldo Atual R$:" << ConsultarSaldo() << '\n';
    }
}


double Conta::ConsultarSaldo() {
    return Saldo;
}


std::string Conta::GetBanco() {
    return Banco;
}

std::string Conta::GetTitular() {
    return Titular;
}

int Conta::GetAgencia() {
    return Agencia;
}

int Conta::GetNumeroDaConta() {
    return NumeroDeContas;
}


void Conta::GetEnderecoThis() {
    std::cout << "\n O this contém dentro o endereço: " << this << '\n';
}

/*Aqui pode haver um erro chamado Problema de ambiguidade, para que isso não aconteça
podemos usar o this*/
void Conta::SetBanco(std::string Banco) {
    (*this).Banco = Banco; //também pode ser escrito dessa forma: this->Banco = Banco;
}

void Conta::SetTitular(std::string Titular) {
    (*this).Titular = Titular;
}


void Conta::SetAgencia(int Agencia) {
    this->Agencia = Agencia;
}

void Conta::SetNumeroDaConta(int NumeroDeConta) {
    this->NumeroDeContas = NumeroDeConta;
}
