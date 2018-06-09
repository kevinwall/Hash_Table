#include <string>
#include <tuple>

struct Account
{
	using AccKey = std::tuple < std::string, int, int, int, double >;

	std::string nome_cliente;
	int codigo_banco;
	int agencia;
	int num_conta;
	double saldo;

	Account( std::string nome = "Sem Nome", int codigo_b = 000, int age = 000, int num_c= 000, double sal= 000)
	: nome_cliente(nome), codigo_banco(codigo_b), agencia(age), num_conta(num_c), saldo(sal)  
	{
		//Empty
	}

	AccKey get_key()
	{
		auto t = std::make_tuple(nome_cliente, codigo_banco, agencia, num_conta, saldo);

		return t;
	}
};