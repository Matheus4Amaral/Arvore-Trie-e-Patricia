#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

// Nó da Trie
struct No {
    vector<No*> filhos;
    bool ehChave;

    No();
};

//  Trie
struct Trie {
    No* raiz;

    Trie();
    void inserir(const string& chave);
    void remover(const string& chave);
    bool busca(const string& chave);
    bool ehPrefixo(const string& prefixo);
};

#endif
