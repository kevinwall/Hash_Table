#include <string>
#include <tuple>
#include <utility>
#include <iostream>
#include "../include/Hash_Table.h"

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
	sc::HashTbl<AcctKey, Account, KeyHash, KeyEqual> accounts(20);

	Account conta[] = {
		{"Kevin", 1, 13, 74, 15.00},
		{"Renato", 1, 18, 5666, 56.66},
		{"Douglas", 16, 7, 900, 17.4},
		{"Michael", 1, 4, 3000, 123.4},
		{"Maria", 1, 3, 233, 543.1},
		{"Larissa", 1, 16, 36, 135.56},
	};

	auto way = sizeof(conta) / sizeof(Account);

	for( auto i(0u) ; i < way ; i++){
		accounts.insert(conta[i].get_key(),conta[i]);
	}

	accounts.print();

	AcctKey acckey;
	Account test;
	std::cout<< std::endl;

	while( getline(std::cin,std::get<0>(acckey))){
		std::cout << " Nome do cliente:";
		std::cin >> std::get<0>(acckey);

		std::cout << " Codigo do banco:";
		std::cin >> std::get<1>(acckey);

		std::cout << " Agencia: ";
		std::cin >> std::get<2>(acckey);

		std::cout << "Numero do banco: ";
		std::cin >> std::get<3>(acckey);

		std::cout << " Saldo: ";
		std::cin >> std::get<4>(acckey);

		if(accounts.retrieve( acckey, test)){
			std::cout << test.nome_cliente << " " << test.codigo_banco << " " << test.agencia << " " << test.num_conta << " " << test.saldo << " ";
			accounts.remove( test.get_key());
		}else{
			std::cout << " Account " << std::get<0>(acckey) << " " << std::get<1>(acckey) << std::get<2>(acckey) << std::get<3>(acckey) << std::get<4>(acckey) ;
		}
	}

	accounts.print();

	return 0;
}