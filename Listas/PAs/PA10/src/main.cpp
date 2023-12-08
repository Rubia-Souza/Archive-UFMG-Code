#include <bits/stdc++.h>

#include <string>
#include "Set.hpp"

using namespace std;

const char COMANDO_INSERIR = 'i';
const char COMANDO_REMOVER = 'r';
const char COMANDO_PERTENCE = 'n';
const char COMANDO_UNIAO = 'u';
const char COMANDO_INTERSECAO = 't';
const char COMANDO_DIFERENCA_SIMETRICA = 'd';
const char COMANDO_IMPRIMIR = 'p';

Set* LeConjunto(){
    int n;
    string k;
    cin >> n;
    Set* s = new Set(n);
    for(int i = 0; i < n; i++){
        cin >> k;
        s->inserir(k);
    }
    return s;
}


int main(int argc, char** argv){
    int n;
    char c;
    string t;

    cin >> n;
    Set* s = new Set(1);

    for(int i = 0; i < n; i++){
        cin >> c;
        switch(c) {
            case(COMANDO_INSERIR): {
                cin >> t;
                s->inserir(t);
                break;
            }
            case(COMANDO_REMOVER): {
                cin >> t;
                s->remover(t);
                break;
            }
            case(COMANDO_PERTENCE): {
                cin >> t;
                transform(t.begin(), t.end(), t.begin(), ::tolower);  // Converta a string para minúsculas.
                
                if(s->pertence(t)) {
                    cout << "O elemento " << t << " pertence ao conjunto!\n";
                }
                else {
                    cout << "O elemento " << t << " nao pertence ao conjunto!\n";
                }

                break;
            }
            case(COMANDO_UNIAO): {
                cout << "A uniao dos conjuntos e: ";
                Set* l = LeConjunto();
                Set* u = s->uniao(*l);
                
                u->print();
                
                delete l;
                delete u;

                break;
            }
            case(COMANDO_INTERSECAO): {
                cout << "A intersecao dos conjuntos e: ";
                Set* l = LeConjunto();
                Set* t = s->intersecao(*l);

                t->print();

                delete l;
                delete t;

                break;
            }
            case(COMANDO_DIFERENCA_SIMETRICA): {
                cout << "A diferenca simetrica dos conjuntos e: ";
                
                Set* l = LeConjunto();
                Set* d = s->diferencaSimetrica(*l);
                
                d->print();
                
                delete l;
                delete d;
                
                break;
            }
            case(COMANDO_IMPRIMIR): {
                s->print();
                break;
            }
            default: {
                break;
            }
        }
    }

    delete s;

    return 0;
}
