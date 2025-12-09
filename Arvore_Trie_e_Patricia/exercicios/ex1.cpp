#include <iostream>
#include "../includes/trie.h"

int main() {
    // Cria uma Trie
    Trie t;

    // Insere as palavras
    vector<string> palavras = {"camisa", "camisola", "camiseta", "copo", "cordao", "corda", "cantil"};
    cout << "Inserindo palavras: ";
    for (auto &s : palavras) {
        cout << s << " ";
        t.inserir(s);
    }
    cout << "\n\n";

    // Remove camisola
    cout << "Removendo 'camisola'...\n";
    t.remover("camisola");
    cout << "Busca 'camisola' apos remocao: " << (t.busca("camisola") ? "true" : "false") << "\n\n";

    // Busca copo
    cout << "Buscando 'copo': " << (t.busca("copo") ? "true" : "false") << "\n\n";

    // Busca todas as palavras ainda existentes apos remocao
    cout << "=== Buscando Todas as Palavras Apos Remocao ===" << '\n';
    for (string &s : palavras) {
        cout << "Busca '" << s << "': " << (t.busca(s) ? "true" : "false") << '\n';
    }

    return 0;
}
