#define NUM_OF_PRIMES 32
// prime numbers lookup table
static const size_t primes[NUM_OF_PRIMES] =
{
  /* 0     */              5ul,
  /* 1     */              11ul, 
  /* 2     */              23ul, 
  /* 3     */              47ul, 
  /* 4     */              97ul, 
  /* 5     */              199ul, 
  /* 6     */              409ul, 
  /* 7     */              823ul, 
  /* 8     */              1741ul, 
  /* 9     */              3469ul, 
  /* 10    */              6949ul, 
  /* 11    */              14033ul, 
  /* 12    */              28411ul, 
  /* 13    */              57557ul, 
  /* 14    */              116731ul, 
  /* 15    */              236897ul,
  /* 16    */              480881ul, 
  /* 17    */              976369ul,
  /* 18    */              1982627ul, 
  /* 19    */              4026031ul,
  /* 20    */              8175383ul, 
  /* 21    */              16601593ul, 
  /* 22    */              33712729ul,
  /* 23    */              68460391ul, 
  /* 24    */              139022417ul, 
  /* 25    */              282312799ul, 
  /* 26    */              573292817ul, 
  /* 27    */              1164186217ul,
  /* 28    */              2364114217ul, 
  /* 29    */              4294967291ul,
  /* 30    */ (std::size_t)8589934583ull,
  /* 31    */ (std::size_t)17179869143ull,
};


template <typename K, typename V>
class HashTable;


template <typename K, typename V>
class HashNode {
	K key;
	V value;
	friend HashTable<K,V>;
public:
	HashNode(K key, V value);
	HashNode() = delete;
};


template <typename K, typename V>
class HashTable {
	HashNode<K,V>** storage;
	int size, capacity, curr_prime;
	size_t hashFunc(K key);
	void resize();
public:
	HashTable();
	void printHashTable();
	void insert(K key, V value);
	V get(K key);
	void remove(K key);
	~HashTable();
  size_t getSize();
};

#include "HashTable.cpp"
