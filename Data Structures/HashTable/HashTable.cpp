#include <iostream>
#include <cstring>


template <typename K, typename V>
HashNode<K,V>::HashNode(K key, V value) : key(key), value(value) {}


template <typename K, typename V>
HashTable<K,V>::HashTable() : size(0), capacity(primes[0]), curr_prime(0) {
	storage = new HashNode<K,V>*[capacity];

	for (int i = 0; i < capacity; i++) {
		storage[i] = NULL;
	}
}

template <typename K, typename V>
HashTable<K,V>::~HashTable() {
	for (int i = 0; i < capacity; i++) {
		if (storage[i])
			delete storage[i];
	}

	delete[] storage;
}


template <typename K, typename V>
size_t HashTable<K,V>::hashFunc(K key) {
	return std::hash<K>{}(key) % capacity;
}


template <typename K, typename V>
void HashTable<K,V>::insert(K key, V value) {
	if (size >= capacity / 2) {
		std::cout << "ITS RESIZING!! CAP IS " << capacity << std::endl;
		resize();
	}

	size_t i = hashFunc(key);

	while (storage[i] && storage[i]->key != key) {
		i++;
	}

	if (storage[i] && storage[i]->key == key)
		storage[i]->value = value;
	else {
		storage[i] = new HashNode<K,V>(key, value);
		size++;
	}
}


template <typename K, typename V>
void HashTable<K,V>::resize() {
	HashNode<K,V>** new_table;

	// create a new hash table
	if (curr_prime == NUM_OF_PRIMES - 1) {
		throw std::length_error("Cannot resize, hashTable too large");
	} else {
		new_table = new HashNode<K,V>*[primes[++curr_prime]];
		std::memset(new_table, 0, sizeof(HashNode<K,V>*));

		// copy over old hash table to new hash table
		for (int i = 0; i < capacity; i++) {
			if (storage[i]) {
				new_table[hashFunc(storage[i]->key)] = storage[i];
			}
		}

		swap(new_table, storage);
		delete[] new_table;
		capacity = primes[curr_prime];
	}
}

template <typename K, typename V>
void HashTable<K,V>::printHashTable() {
	for (int i = 0; i < capacity; i++) {
		if (storage[i]) {
			std::cout << "KEY: " << storage[i]->key << " VALUE: " << storage[i]->value;
			std::cout << " INDEX: " << i << std::endl;
		}

	}
}


template <typename K, typename V>
void HashTable<K,V>::remove(K key) {
	int i = hashFunc(key);
	int starting_i = i;

	while(storage[i]) {
		if(storage[i]->key == key) {
			delete storage[i];
			storage[i] = NULL;
			size--;
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