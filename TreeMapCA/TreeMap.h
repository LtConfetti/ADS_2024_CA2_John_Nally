#pragma once
#include "BinaryTree.h"
#include "Entity.h"

template <class K, class V>
class TreeMap {
public:

	BinaryTree<Entity<K, V>> tree;
	
	void clear();

	bool containsKey(K key);

	V& get(K key);

	BinaryTree<K> keySet();

	void put(K key, V value);

	int size();

	bool removeKey(K key);

	V& operator[](K key);
};

template<class K, class V>
inline void TreeMap<K, V>::clear()
{
	tree.clear();
}

template<class K, class V>
inline bool TreeMap<K, V>::containsKey(K key)
{
	BSTNode<Entity<K, V>>* node = tree.root;
	while (true)
	{
		if (node == nullptr) {
			return false;
		}

		else if (node->getItem().key == key) {
			return true;
		}
		else if (node->getItem().key < key) {
			node = node->getRight();
		}
		else {
			node = node->getLeft();
		}
	}
}

template<class K, class V>
inline V& TreeMap<K, V>::get(K key)
{
	Entity<K, V> getItems(key);

	return tree.get(getItems).value; 
}

template<class K, class V>
inline BinaryTree<K> TreeMap<K, V>::keySet()
{
	return BinaryTree<K>();
}

template<class K, class V>
inline void TreeMap<K, V>::put(K key, V value)
{
	Entity<K, V> newEntity(key, value);
	tree.add(newEntity);
}

template<class K, class V>
inline int TreeMap<K, V>::size()
{
	return tree.count();
}

template<class K, class V>
inline bool TreeMap<K, V>::removeKey(K key)
{
	Entity<K, V> removeItems(key);

	return tree.remove(removeItems);
}

template<class K, class V>
inline V& TreeMap<K, V>::operator[](K key)
{
	return get(key);
}
