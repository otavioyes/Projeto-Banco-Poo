#pragma once

#include <iostream>
#include <string>


class Conta {

	/*Essas são os atributos de uma CLASSE/CONTA*/
public :
	std::string Banco;
	std::string Titular;
	int Agencia;
	int NumeroDeContas;
	double Saldo;

	/*MÉTODOS/FUNCIONALIDADES DE UMA CONTA*/

//Construtor VAZIO
Conta();


//Aqui é o construtor já com parametros, com isso podemos criar um objeto e já enviar os argumentos para serem 
//inicializados nos atributos (variaveis) do objeto.
public :
	Conta(std::string Banco,
		std::string Titular,
		int Agencia,
		int NumeroDeContas,
		double Saldo);

	~Conta();


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
	void GetEnderecoThis();

	/*MÉTODOS ACESSORES SET*/

public :
	void SetBanco(std::string Banco);
	void SetTitular(std::string Titular);
	void SetAgencia(int Agencia);
	void SetNumeroDaConta(int NumeroDeContas);
	
};