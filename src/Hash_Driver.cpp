#include <string>
#include <tuple>
#include <utility>
#include <iostream>
#include "../include/Hash_Table.h"

using AcctKey = std::tuple < std::string, int, int, int, double >;

struct Account
{
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

	AcctKey get_key()
	{
		auto t = std::make_tuple(nome_cliente, codigo_banco, agencia, num_conta, saldo);

		return t;
	}
};

struct KeyHash
{
	size_t operator()(const AcctKey & k_) const
	{
		return( std::hash<std::string>()(std::get<0>(k_)) xor 
				std::hash<int>()(std::get<1>(k_)) xor
				std::hash<int>()(std::get<2>(k_)) xor
				std::hash<int>()(std::get<3>(k_)) xor
				std::hash<double>()(std::get<4>(k_))
				);
	}
};

struct KeyEqual
{
	size_t operator()(const AcctKey & lhs_ , const AcctKey & rhs_)const
	{
		return( std::get<0>(lhs_) == std::get<0>(rhs_) and
				std::get<1>(lhs_) == std::get<1>(rhs_) and
				std::get<2>(lhs_) == std::get<2>(rhs_) and
				std::get<3>(lhs_) == std::get<3>(rhs_) and
				std::get<4>(lhs_) == std::get<4>(rhs_)
				);
	}
};


int main()
{
	Account conta("Zé das drogas", 1, 13, 74, 15.00);
	Account conta_2("Zezo", 1, 13, 74, 15.00);

	KeyHash chave;

	KeyEqual igual;

	std::cout<<((chave(conta.get_key()))%23)<<std::endl;

	std::cout<<igual(conta.get_key(), conta_2.get_key())<<std::endl;

	return 0;
}