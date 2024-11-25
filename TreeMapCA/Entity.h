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

}
