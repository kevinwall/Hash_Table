#ifndef Hash_Table_H
#define Hash_Table_H

#include <forward_list>

namespace sc{

	template <typename KeyType, typename DataType>
	class HashEntry
	{
		public:
			HashEntry(KeyType k_, DataType d_) : m_key(k_), m_data(d_)
			{
			//Empty
			}

			KeyType m_key; 
			DataType m_data;
	};

	template < typename KeyType, typename DataType, typename KeyHash = std::hash <KeyType>, typename KeyEqual = std::equal_to<KeyType> >
	class HashTbl 
	{
		public:
			using Entry = HashEntry < KeyType , DataType >;

			HashTbl (size_t tbl_size_ = DEFAULT_SIZE);
			virtual ~HashTbl ();
			bool insert (const KeyType & k_ , const DataType & d_);
			bool remove (const KeyType & k_);
			bool retrieve (const KeyType & k_ , DataType & d_) const;
			void clear (void);
			bool empty (void) const;
			unsigned long int count (void) const;
			void print() const;

		private:
			void rehash();
			unsigned int m_size;
			unsigned int m_count;
			std::forward_list <Entry> *m_data_table;
			static const short DEFAULT_SIZE = 11;
	};

	#include "Hash_Table.inl"
}

#endif