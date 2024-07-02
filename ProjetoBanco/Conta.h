#pragma once

#include <iostream>
#include <string>


class Conta {

	/*Essas são os atributos de uma CLASSE/CONTA*/
private :
	std::string Banco;
	std::string Titular;
	int Agencia;
	int NumeroDeContas;
	double Saldo{ 0.0 };

	/*MÉTODOS/FUNCIONALIDADES DE UMA CONTA*/

public :
	bool Sacar(double Valor);
	void Depositar(double Valor);
	void Transferir(Conta &Destino, double ValorTransferir);
	double ConsultarSaldo();
	
	/*MÉTODOS ACESSORES GET*/

public : 
	std::string GetBanco();
	std::string GetTitular();
	int GetAgencia();
	int GetNumeroDaConta();

	/*MÉTODOS ACESSORES SET*/

public :
	void SetBanco(std::string Banco);
	void SetTitular(std::string Titular);
	void SetAgencia(int Agencia);
	void SetNumeroDaConta(int NumeroDeContas);
	
};