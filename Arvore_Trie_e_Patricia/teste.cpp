#include <iostream>
#include "./includes/trie.h"

int main() {
    // Create am example Trie
    Trie t;

    vector<string> palavras = {"and", "ant", "do", "dad"};
    for (auto &s : palavras)
        t.inserir(s);

    t.remover("ant");

    // One by one search strings
    vector<string> searchKeys = {"do", "da", "bat", "ant"};
    for (string &s : searchKeys){
        if (t.busca(s))
            cout << "true ";
        else
            cout << "false ";
        cout << '\n';
    } 
    cout<<"\n";

    vector<string> prefix = {"do", "da", "bat"};
    for (string &s : prefix){
        if (t.ehPrefixo(s))
            cout << "true ";
        else
            cout << "false ";
        cout << '\n';
    } 
    cout<<"\n";

    return 0;
}