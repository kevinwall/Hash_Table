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

		emplate <class KeyType, class DataType, class KeyHash, class KeyEqual>
		bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>:: insert ( const KeyType & k_ , const DataType & d_ ) throw ( std::bad_alloc ){

			KeyHash client;
			KeyEqual equal;

			if(mSize <= mCount) {
			rehash();
			}

			auto end = client(k_) % m_size;
			auto fast = m_data_table[end].begin();
			auto slow = m_data_table[end].before_begin();

			for(; fast !=  m_data_table[end].end(); fast++){
				if(true == equal((*fast).m_key, k_)){
					(*i).m_data = d_;
					return false;
				}
			}

			m_count++;
			m_data_table[end].emplace_after(slow,k_,d_);
			return true;
		}

		
		bool remove ( const KeyType & k_ ){
			KeyHash client;
			KeyEqual equal;

			auto end = client(k_) % m_size;
			auto fast = m_data_table[end].begin();
			auto slow = m_data_table[end].before_begin();

			for(; fast !=  m_data_table[end].end(); fast++){
				if(true == equal((*fast).m_key, k_)){
					slow++;
						m_data_table[end].erase_after(slow,fast);
						m_count--;
						return true;
				}
				fast++;
			}
			
			return false;
				
		}
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



