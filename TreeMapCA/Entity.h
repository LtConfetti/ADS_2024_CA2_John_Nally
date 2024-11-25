#pragma once

template <class K, class V>
struct Entity
{
	K key;
	V value;

	Entity(K key, V value) {
		this->key = key;
		this->value = value;
	}

	//This used for get, remove which is already done in the binary tree for the TreeMap
	Entity(K key) { 
		this->key = key;
	}


	Entity() {

	}
	//
	bool operator==(Entity<K, V>& node) {
		return this->key == node.key;
	}

	bool operator<(Entity<K, V>& node) {
		return this->key < node.key;
	}

	bool operator>(Entity<K, V>& node) {
		return this->key > node.key;
	}

	template <class K, class V>
	friend std::ostream& operator<<(std::ostream& out, const Entity<K, V>& entity) {
		out << "(" << key << " | " << value << ")" << endl;
	}
};
