#include "../include/Contas.h"

std::tuple < std::string, int, int, int, double >  Account::get_key()
{
	auto t = std::make_tuple(nome_cliente, codigo_banco, agencia, num_conta, saldo);

	return t;
}