#pragma once

#include <iostream>
#include <string>


class Conta {

	/*Essas s�o os atributos de uma CLASSE/CONTA*/
private :
	std::string Banco;
	std::string Titular;
	int Agencia;
	int NumeroDeContas;
	double Saldo{ 0.0 };

	/*M�TODOS/FUNCIONALIDADES DE UMA CONTA*/

public :
	bool Sacar(double Valor);
	void Depositar(double Valor);
	void Transferir(Conta &Destino, double ValorTransferir);
	double ConsultarSaldo();
	
	/*M�TODOS ACESSORES GET*/

public : 
	std::string GetBanco();
	std::string GetTitular();
	int GetAgencia();
	int GetNumeroDaConta();

	/*M�TODOS ACESSORES SET*/

public :
	void SetBanco(std::string Banco);
	void SetTitular(std::string Titular);
	void SetAgencia(int Agencia);
	void SetNumeroDaConta(int NumeroDeContas);
	
};