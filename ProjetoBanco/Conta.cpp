#include "Conta.h"

#include <iostream>
#include <string>

bool Conta::Sacar(double Valor) {
   
    if (Saldo < Valor) {
        std::cout << "Saldo Insuficiente! " << '\n';
        std::cout << "Saldo Atual R$" << ConsultarSaldo() << '\n';
        return false;
    } 
    else {
        Saldo = Saldo - Valor;
        std::cout << "Transfer�ncia realizada com sucesso\n ";
        return true;
    }
}

void Conta::Depositar(double Valor) {
    Saldo += Valor;
    std::cout << "\nDeposito de R$" << Valor << " Realizado com sucesso!\n";
}

/*
AQUI O "DESTINO" � UM OBJETO DO TIPO CONTA, OU SEJA, O DESTINO SER� PARA UMA CONTA DE DESTINO QUE
NO CASO SER� UMA OUTRA CONTA
*/
void Conta::Transferir(Conta &Destino, double ValorTransferir) {
    if (Saldo < ValorTransferir) {
        std::cout << "Saldo Insuficiente. ";
    }
    else {
        /*Aqui o Destino est� com o Objeto passado para a fun��o,
        logo vai chamar o m�todo Depositar desse objeto
        */
        Destino.Depositar(ValorTransferir);
        /*Depois de depositar voc� deve retirar este valor depositado do saldo*/
        Saldo -= ValorTransferir;

        /*
        Aqui est� indo no Objeto Destino e trazendo as informa��es dos dados da Conta
        do destinat�rio, ou seja, para onde foi o dinheiro
        */
        std::cout << "\n*****DADOS*****\n";
        std::cout << "Banco: " << Destino.GetBanco() << "\n";
        std::cout << "Titular: " << Destino.GetTitular() << "\n";
        std::cout << "Ag�ncia: " << Destino.GetAgencia() << "\n";
        std::cout << "N�mero da Conta: " << Destino.GetNumeroDaConta() << "\n";
        std::cout << "Transfer�ncia de R$" << ValorTransferir << " realizada com sucesso!\n";
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

void Conta::GetEnderelo() {
    std::cout << "\n O this cont�m dentro dentro o endere�o " << this << '\n';
}

/*Aqui pode haver um erro chamado Problema de ambiguidade, para que isso n�o aconte�a
podemos usar o this*/
void Conta::SetBanco(std::string Banco) {
    (*this).Banco = Banco; //tamb�m pode ser escrito dessa forma: this->Banco = Banco;
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
