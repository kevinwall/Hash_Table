#include <forward_list>
#include "Contas.h"




	template <class KeyType , class DataType>
	class HashEntry
	{
		public:
			HashEntry(KeyType k_, DataType d_) : m_key(k_), m_data(d_)
			{}

			KeyType m_key; 
			DataType m_data;
	};

	template < typename KeyType , typename DataType >
	class HashTbl {
		public:
		using Entry = HashEntry < KeyType , DataType >;

		template <class KeyType, class DataType, class KeyHash, class KeyEqual>
		unsigned long int HashTbl<KeyType, DataType, KeyHash, KeyEqual>::FindPrime(int capacity) {
		
		int count = 0;
		
		for(i = capacity; 1 < i && capacity <= i; i++) {
			for(e = i - 1; 1 < e; e--) {
				if(count == (capacity - 3) ) {
					return i;
				}
				count++;
			}			
		}

		}

		template <class KeyType, class DataType, class KeyHash, class KeyEqual>
		HashTbl<KeyType, DataType, KeyHash, KeyEqual>::HashTbl ( size_t tbl_size_ = DEFAULT_SIZE ){

			m_size = FindPrime( tbl_size_ );
			mpDataTable = new std::list< Entry >[m_size];
			m_count = 0;

		}

		template <class KeyType, class DataType, class KeyHash, class KeyEqual>
		HashTbl<KeyType, DataType, KeyHash, KeyEqual>::~HashTbl (){

			 for( int i(0) ; i < m_size; ++i){
			 	m_data_table[i].~forward_list();
			 }

			 m_size = 0;
		}


		bool insert ( const KeyType & k_ , const DataType & d_ );
		bool remove ( const KeyType & k_ );
		bool retrieve ( const KeyType & k_ , DataType & d_ ) const;
		void clear (void);
		bool empty ( void ) const;
		unsigned long int count ( void ) const;
		void print () const;

		private:
		void rehash ();
		unsigned int m_size;
		unsigned int m_count;
		std::forward_list <Entry> * m_data_table ;
		static const short DEFAULT_SIZE = 11;
	};



