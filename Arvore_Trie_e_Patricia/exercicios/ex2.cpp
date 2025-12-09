#include <iostream>
#include "../includes/trie.h"

int main() {
    // Cria uma Trie
    Trie t;

    // Insere as palavras
    vector<string> palavras = {"livro", "monitor", "fone", "panela", "geladeira", "tabuleiro", "caneta", "teclado", "tecla"};
    cout << "Inserindo palavras: ";
    for (auto &s : palavras) {
        cout << s << " ";
        t.inserir(s);
    }
    cout << "\n\n";

    // Testa prefixos
    cout << "=== Buscando Prefixos ===" << '\n';
    vector<string> prefixos = {"l", "xyz", "liv", "moto", "ma", "mon", "f", "fo", "perf", "pan", "pane", "gel", "tar", "tab", "tec", "cano", "cane"};
    for (string &s : prefixos) {
        cout << "Prefixo '" << s << "': " << (t.ehPrefixo(s) ? "true" : "false") << '\n';
    }
    cout << '\n';

    return 0;
}
