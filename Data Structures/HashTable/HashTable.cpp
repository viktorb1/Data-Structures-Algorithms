#include <iostream>
#include <cstring>


template <typename K, typename V>
HashNode<K,V>::HashNode(K key, V value) : key(key), value(value) {}

template <typename K, typename V>
HashNode<K,V>::HashNode() {}


template <typename K, typename V>
HashTable<K,V>::HashTable() : size(0), capacity(primes[0]), curr_prime(0) {
	empty_node = new HashNode<K,V>();
	storage = new HashNode<K,V>*[capacity];

	for (int i = 0; i < capacity; i++) {
		storage[i] = NULL;
	}
}


template <typename K, typename V>
HashTable<K,V>::~HashTable() {
	delete empty_node;

	for (int i = 0; i < capacity; i++) {
		if (storage[i] && storage[i] != empty_node)
			delete storage[i];
	}

	delete[] storage;
}

template <typename K, typename V>
size_t HashTable<K,V>::getSize() {
	return size;
}


template <typename K, typename V>
size_t HashTable<K,V>::hashFunc(K key) {
	return std::hash<K>{}(key) % capacity;
}


template <typename K, typename V>
void HashTable<K,V>::insert(K key, V value) {
	if (size > capacity / 2)
		resize();

	size_t i = hashFunc(key);

	while (storage[i] && storage[i]->key != key && storage[i] != empty_node) {
		i++;
		i %= capacity;
	}

	if (!storage[i] || storage[i] == empty_node)
		size++;
	else
		delete storage[i];

	storage[i] = new HashNode<K,V>(key, value);

}


template <typename K, typename V>
void HashTable<K,V>::resize() {

	// create a new hash table
	if (curr_prime == NUM_OF_PRIMES - 1) {
		throw std::length_error("Cannot resize, hashTable too large");
	} else {
		HashNode<K,V>** new_table = new HashNode<K,V>*[primes[++curr_prime]];
		std::memset(new_table, 0, sizeof(HashNode<K,V>*)*primes[curr_prime]);

		size_t old_capacity = capacity;
		size = 0;
		HashNode<K,V>** old_table = storage;
		storage = new_table;
		capacity = primes[curr_prime];

		// copy over old hash table to new hash table
		for (int i = 0; i < old_capacity; i++) {
			if (old_table[i]) {
				insert(old_table[i]->key, old_table[i]->value);
				delete old_table[i];
			}
		}

		delete[] old_table;
	}
}

template <typename K, typename V>
void HashTable<K,V>::printHashTable() {
	int j = 1; 

	for (int i = 0; i < capacity; i++) {
		if (storage[i] && storage[i] != empty_node) {
			std::cout << j++ << ". ";
			std::cout << "KEY: " << storage[i]->key << " VALUE: " << storage[i]->value;
			std::cout << " INDEX: " << i << std::endl;
		}

	}
}


template <typename K, typename V>
void HashTable<K,V>::remove(K key) {
	int i = hashFunc(key);
	int starting_i = i;

	// it's not deleting the other values because it can't skip over the previous values

	while(storage[i]) {
		if(storage[i]->key == key) {
			delete storage[i];
			storage[i] = empty_node;
			size--;
			break;
		}

		i++;
		i %= capacity;

		if (i == starting_i)
			break;
	}
}

template <typename K, typename V>
V HashTable<K,V>::get(K key) {
	int i = hashFunc(key);
	int starting_i = i;

	while(storage[i]) {
		if(storage[i]->key == key)
			return storage[i]->value;

		i++;
		i %= capacity;

		if (i == starting_i) // make
			return (V)NULL;
	}

	return (V)NULL;
}