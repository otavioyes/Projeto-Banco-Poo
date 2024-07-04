#include "Conta.h"

#include <iostream>
#include <string>
#include <locale>
 
/*O CÓDIGO RODA, PORÉM POSSUI DIVERSOS ERROS*/

int main() {

	setlocale(LC_ALL, "portuguese");

	//Esses dois objetos estão alocados na memória STACK/RAM
	/**************************************************************************/
	Conta ContaCliente01;
	Conta ContaCliente02;

	std::cout << "Endereço de memória do Cliente01 " << &ContaCliente01 << '\n';
	ContaCliente01.GetEnderecoThis();

	std::cout << "Endereço de memória do Cliente02 " << &ContaCliente02 << '\n';
	ContaCliente02.GetEnderecoThis();

	
	ContaCliente01.SetBanco("Nubank");
	ContaCliente01.SetTitular("Fernando");
	ContaCliente01.SetAgencia(3232);
	ContaCliente01.SetNumeroDaConta(7878785);

	ContaCliente01.Depositar(10000.00);
	ContaCliente01.Sacar(1000.00);
	std::cout << "AQUI É CONTA 1?\n";
	ContaCliente01.ConsultarSaldo();
	
	//std::cout << std::endl;

	ContaCliente02.SetBanco("CAIXA ECONOMICA FEDERAL");
	ContaCliente02.SetTitular("Otavio Correa");
	ContaCliente02.SetAgencia(5555);
	ContaCliente02.SetNumeroDaConta(1234567);

	ContaCliente02.Depositar(5000.00);
	std::cout << "AQUI É CONTA 2\n";
	ContaCliente02.Sacar(2000.00);
	ContaCliente02.ConsultarSaldo();

	ContaCliente01.Transferir(ContaCliente02, 777.55);
	
	ContaCliente01.Sacar(350.01); 

	

	return 0;
}