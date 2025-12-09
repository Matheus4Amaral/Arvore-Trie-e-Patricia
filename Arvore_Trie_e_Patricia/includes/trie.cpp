#include "Trie.h"

No::No() {
    ehChave = false;
    // Inicialmente o nó não possui filhos
    filhos.assign(ALPHABET_SIZE, nullptr);
}

// Construtor da Trie
Trie::Trie() {
    // Inicializa a raiz
    raiz = new No();
}

// Insere uma chave na Trie
void Trie::inserir(const string& chave) {
    // Inicializa o atual como sendo a raiz
    No* atual = raiz;
    
    // Percorre cada caracter da chave
    for (char c : chave) {
        // Posição do caracter no conjunto de caracteres
        int idx = c - 'a';

        // Verifca se existe o próximo nó na Trie
        if (atual->filhos[idx] == nullptr) 
            // Cria um novo nó caso ainda não exista
            // Atualiza referência para o novo nó (prefixo novo)
            atual->filhos[idx] = new No();
        
        
        // Move o atual para o proximo nó
        atual = atual->filhos[idx];
    }
    
    // Marca como uma chave válida
    atual->ehChave = true;
}

// Remoção simples de uma chave na Trie, apenas marca que o nó final não forma chave
void Trie::remover(const string& chave) {
    // Inicializa o atual como sendo a raiz
    No* atual = raiz;

    // Percorre cada caracter da chave
    for (char c : chave) {
        // Posição do caracter no conjunto de caracteres
        int idx = c - 'a';
        
        // Verifca se existe o próximo nó na Trie
        if (atual->filhos[idx] == nullptr)
            return; // Caso não exista, não faz alterações na Trie
        
        // Move o atual para o proximo nó
        atual = atual->filhos[idx];
    }

    // Marca que a string (se existir) não forma chave
    atual->ehChave = false;
}

// Busca uma chave na Trie
bool Trie::busca(const string& chave) {
    // Inicializa o atual como sendo a raiz
    No* atual = raiz;

    // Percorre cada caracter da chave
    for (char c : chave) {
        // Posição do caracter no conjunto de caracteres
        int idx = c - 'a';
        
        // Verifca se existe o próximo nó na Trie
        if (atual->filhos[idx] == nullptr)
            return false;
        
        // Move o atual para o proximo nó
        atual = atual->filhos[idx];
    }

    // Retorna verdadeiro se a chave existir e terminar 
    return atual->ehChave;
}

// Verifica se existe o prefixo na Trie
bool Trie::ehPrefixo(const string& prefixo) {
    // Inicializa o atual como sendo a raiz
    No* atual = raiz;

    // Percorre cada caracter do prefixo
    for (char c : prefixo) {
        // Posição do caracter no conjunto de caracteres
        int idx = c - 'a';

        // Verifca se existe o próximo nó na Trie
        if (atual->filhos[idx] == nullptr)
            return false;

        // Move o atual para o proximo nó
        atual = atual->filhos[idx];
    }

    // Se chegou até aqui, é um prefixo
    return true;
}