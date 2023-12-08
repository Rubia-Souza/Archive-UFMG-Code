#include "Set.hpp"

// Construtor
StringSet::StringSet(int tamanho) {
    tamanhoOriginal = tamanho;
    tamanhoTabela = 2 * tamanhoOriginal; // Tamanho inicial da tabela
    tamanhoConjunto = 0;
    tabela = new ElementoTabela[tamanhoTabela];

    for (int i = 0; i < tamanhoTabela; ++i) {
        tabela[i].vazio = true; // Marcando todas as posições como vazias
        tabela[i].retirada = false;
    }
}

// Destrutor
StringSet::~StringSet() {
    delete[] tabela;
}

// Função Hash
int StringSet::Hash(string s) {
    int hash = 0;
    for (char c : s) {
        hash = (hash * 31 + static_cast<int>(c)) % tamanhoTabela;
    }
    return hash;
}

// Função Rehash
void StringSet::Rehash(int pos) {
    int i = 1;
    int newPos = (pos + i) % tamanhoTabela;
    while (!tabela[newPos].vazio && i <= tamanhoTabela) {
        newPos = (pos + (++i)) % tamanhoTabela;
    }
    if (i <= tamanhoTabela) {
        tabela[newPos].dado = tabela[pos].dado;
        tabela[newPos].vazio = false;
        tabela[newPos].retirada = false;
        tabela[pos].vazio = true;
    } else {
        Resize(2 * tamanhoTabela);
    }
}

// Função Resize
void StringSet::Resize(size_t newSize) {
    ElementoTabela* novaTabela = new ElementoTabela[newSize];
    for (unsigned i = 0; i < newSize; ++i) {
        novaTabela[i].vazio = true;
        novaTabela[i].retirada = false;
    }

    for (int i = 0; i < tamanhoTabela; ++i) {
        if (!tabela[i].vazio && !tabela[i].retirada) {
            int newPos = Hash(tabela[i].dado);
            int j = 1;
            while (!novaTabela[newPos].vazio) {
                newPos = (newPos + j) % newSize;
                j++;
            }
            novaTabela[newPos].dado = tabela[i].dado;
            novaTabela[newPos].vazio = false;
        }
    }

    delete[] tabela;
    tabela = novaTabela;
    tamanhoTabela = newSize;
}

// Função Inserir
void StringSet::Inserir(string s) {
    int pos = Hash(s);
    int i = 1;

    while (!tabela[pos].vazio && tabela[pos].dado != s && i <= tamanhoTabela) {
        pos = (pos + i) % tamanhoTabela;
        ++i;
    }

    if (i > tamanhoTabela) {
        Resize(2 * tamanhoTabela);
        Inserir(s);
    } else {
        if (tabela[pos].vazio || tabela[pos].retirada) {
            tabela[pos].dado = s;
            tabela[pos].vazio = false;
            tabela[pos].retirada = false;
            tamanhoConjunto++;
        }
    }
}

// Função Remover
void StringSet::Remover(string s) {
    int pos = Hash(s);
    int i = 1;

    while (!tabela[pos].vazio && tabela[pos].dado != s && i <= tamanhoTabela) {
        pos = (pos + i) % tamanhoTabela;
        ++i;
    }

    if (!tabela[pos].vazio && tabela[pos].dado == s) {
        tabela[pos].vazio = true;
        tabela[pos].retirada = true;
        tamanhoConjunto--;
    }
}

// Função Pertence
bool StringSet::Pertence(string s) {
    int pos = Hash(s);
    int i = 1;

    while (!tabela[pos].vazio && tabela[pos].dado != s && i <= tamanhoTabela) {
        pos = (pos + i) % tamanhoTabela;
        ++i;
    }

    return (!tabela[pos].vazio && tabela[pos].dado == s && !tabela[pos].retirada);
}

// Função Interseção
StringSet* StringSet::Intersecao(StringSet* S) {
    StringSet* result = new StringSet(tamanhoOriginal);

    for (int i = 0; i < tamanhoTabela; ++i) {
        if (!tabela[i].vazio && !tabela[i].retirada && S->Pertence(tabela[i].dado)) {
            result->Inserir(tabela[i].dado);
        }
    }

    return result;
}

// Função União
StringSet* StringSet::Uniao(StringSet* S) {
    StringSet* result = new StringSet(tamanhoOriginal);

    for (int i = 0; i < tamanhoTabela; ++i) {
        if (!tabela[i].vazio && !tabela[i].retirada) {
            result->Inserir(tabela[i].dado);
        }
    }

    for (int i = 0; i < S->tamanhoTabela; ++i) {
        if (!S->tabela[i].vazio && !S->tabela[i].retirada) {
            result->Inserir(S->tabela[i].dado);
        }
    }

    return result;
}

// Função Diferença Simétrica
StringSet* StringSet::DiferencaSimetrica(StringSet* S) {
    StringSet* result = new StringSet(tamanhoOriginal);

    for (int i = 0; i < tamanhoTabela; ++i) {
        if (!tabela[i].vazio && !tabela[i].retirada && !S->Pertence(tabela[i].dado)) {
            result->Inserir(tabela[i].dado);
        }
    }

    for (int i = 0; i < S->tamanhoTabela; ++i) {
        if (!S->tabela[i].vazio && !S->tabela[i].retirada && !Pertence(S->tabela[i].dado)) {
            result->Inserir(S->tabela[i].dado);
        }
    }

    return result;
}

// Função Imprimir
void StringSet::Imprimir() {
    for (int i = 0; i < tamanhoTabela; ++i) {
        if (!tabela[i].vazio && !tabela[i].retirada) {
            cout << tabela[i].dado << " ";
        }
    }
    cout << endl;
}
