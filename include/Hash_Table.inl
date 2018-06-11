#include <forward_list>
#include "Contas.h"

namespace  sc{
template <class KeyType, class DataType, class KeyHash, class KeyEqual>
unsigned long int HashTbl<KeyType, DataType, KeyHash, KeyEqual>::FindPrime(int capacity) 
{
		
int count = 0;
		
for(i = capacity; 1 < i && capacity <= i; i++) 
{
	for(e = i - 1; 1 < e; e--) 
	{
		if(count == (capacity - 3) ) 
		{
			return i;
		}

		count++;

		}			
	}

}

template <class KeyType, class DataType, class KeyHash, class KeyEqual>
HashTbl<KeyType, DataType, KeyHash, KeyEqual>::HashTbl ( size_t tbl_size_ = DEFAULT_SIZE )
{

	m_size = FindPrime( tbl_size_ );
	mpDataTable = new std::list< Entry >[m_size];
	m_count = 0;

}

		
template <class KeyType, class DataType, class KeyHash, class KeyEqual>
HashTbl<KeyType, DataType, KeyHash, KeyEqual>::~HashTbl ()
{

	for( int i(0) ; i < m_size; ++i)
	{
		m_data_table[i].~forward_list();
	}

	m_size = 0;
}

		
template <class KeyType, class DataType, class KeyHash, class KeyEqual>
bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>:: insert ( const KeyType & k_ , const DataType & d_ ) throw ( std::bad_alloc ){

	KeyHash client;
	KeyEqual equal;

	if(mSize <= mCount) 
	{
		rehash();
	}

	auto end = client(k_) % m_size;
	auto fast = m_data_table[end].begin();
	auto slow = m_data_table[end].before_begin();

	for(; fast !=  m_data_table[end].end(); fast++)
	{
		if(true == equal((*fast).m_key, k_))
		{
			(*i).m_data = d_;
			return false;
		}
	}

	m_count++;
	m_data_table[end].emplace_after(slow,k_,d_);
	return true;
}

		
template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
bool HashTbl< KeyType, DataType, KeyHash, KeyEqual >:: remove ( const KeyType & k_ ){

	KeyHash client;
	KeyEqual equal;

	auto end = client(k_) % m_size;
	auto fast = m_data_table[end].begin();
	auto slow = m_data_table[end].before_begin();

	for(; fast !=  m_data_table[end].end(); fast++){
		if(true == equal((*fast).m_key, k_))
		{
			slow++;
			m_data_table[end].erase_after(slow,fast);
			m_count--;
			return true;
		}

		//fast++; //Aqui
	}
			
	return false;

}

template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
bool HashTbl< KeyType, DataType, KeyHash, KeyEqual >:: retrieve ( const KeyType & k_ , DataType & d_ ) const{

	KeyHash client;
	KeyEqual equal;

	auto end = client(k_) % m_size;
	auto i = m_data_table[end].begin();

	for(; i != m_data_table[end].end(); i++)
	{
		if(true == equal((*fast).m_key, k_))
		{
			d_ = (*i).m_data;
			return true;
		}

		i++; //Aqui
	}

	return false;

}
		
		
template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
void HashTbl< KeyType, DataType, KeyHash, KeyEqual >:: clear (void){

	for( auto i = m_count; i > 0 ; i--)
	{
		m_data_table[i].~forward_list();
	}

	m_count = 0;

}


template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
bool HashTbl< KeyType, DataType, KeyHash, KeyEqual >:: empty ( void ) const{

	return ( m_count == 0);

}
		

		
template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
unsigned long int HashTbl< KeyType, DataType, KeyHash, KeyEqual >::count ( void ) const{

	return m_count;

}
		

template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
void HashTbl< KeyType, DataType, KeyHash, KeyEqual >:: print () const{

	KeyHash hash;

	for( auto i = 0 ; i<m_size; i++0)
	{
		std::cout << i << " key = ";
		for( auto & e : m_data_table[i])
		{
			std::cout << hash(e.m_key)<< ";" << e;m_data << " ";
		}
		
		std::cout << std::endl;

	}
}


template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
void HashTbl< KeyType, DataType, KeyHash, KeyEqual >:: rehash (){

	unsigned long int newCapacity = FindPrime( 2* m_size );
	std::list< Entry > *aux_data = new std::list< Entry > [newCapacity];
	KeyHash client;

	for(unsigned long int i = 0 ; i < m_size; i++)
	{
		if( m_data_table[i].empty())
		{
			continue;
		}

		auto first = m_data_table[i].begin();

		for(; first != m_data_table[i].end(); first++)
		{
			Entry aux( first->m_key, first->m_data );

			unsigned long int hash = client(aux,m_key);
			unsigned long int end( hash % newCapacity );

			aux_data[end].push_back(aux);
		}
	}

	~HashTbl();
	m_data_table = aux_data;
	m_size = newCapacity;
}
}