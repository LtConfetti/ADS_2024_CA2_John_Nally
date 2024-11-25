// TreeMapCA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryTree.h"
#include "TreeMap.h"
#include <fstream>
#include <sstream>
#include <string>
#include "BSTNode.h"

using namespace std;


TreeMap<char, BinaryTree<string>>

FileBreakdown() {
    TreeMap<char, BinaryTree<string>> words;
    ifstream in("Pepsi.txt");
    if (in) {
        string word = " ";
        while (getline(in, word, ' ')) {
            if (!words.containsKey(word[0])) {
                words.put(word[0], BinaryTree<string>());
            }
            words.get(word[0]).add(word);
        }
    }
    return words;
}

void printNode(BSTNode<string>* node) {
    if (node->getLeft() != nullptr) {
        printNode(node->getLeft());
    }
    cout << node->getItem() << ", ";
        if (node->getRight() != nullptr) {
            printNode(node->getRight());
        }
}


void printNode(BSTNode<Entity<char, BinaryTree<string>>>* node) {
    if (node->getLeft() != nullptr) {
        printNode(node->getLeft());
    }
    cout << node->getItem().key << ": ";
    printNode(node->getItem().value.root);
    cout << endl;
    if (node->getRight() != nullptr) {
        printNode(node->getRight());
    }
}


void printTreeMap(TreeMap<char, BinaryTree<string>>& map) {
    printNode(map.tree.root);

}

int main()
{
    TreeMap<char, BinaryTree<string>> printing = FileBreakdown();

    printTreeMap(printing);
}

