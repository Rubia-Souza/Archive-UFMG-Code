#include <iostream>

using namespace std;

int main(){
    // 1) Declare uma variável do tipo inteiro e preencha com o valor informado na entrada
    int number = 0;
    cout << "Informe o valor de number: "; // TODO: Remove
    cin >> number;
    cout << "\n";  // TODO: Remove
    
    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int* intPointer = nullptr;
    cout << "Valor inicial intPointer: " << ((intPointer == NULL) ? "null" : "algo") << "\n"; // TODO: Remove

    // 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha com os dados passados
    size_t size = 0;
    cout << "Digite um tamanho para o vetor intArray: "; // TODO: Remove
    cin >> size;
    cout << "\n"; // TODO: Remove

    int* intArray = new int[size];
    for(size_t i = 0; i < size; i++) {
        cout << "Digite o valor " << i+1 << " do vetor: "; // TODO: Remove
        cin >> intArray[i];
        cout << "\n"; // TODO: Remove
    }

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << "Endereco de number: "; // TODO: Remove
    cout << &number << "\n";

    // 5) Imprima o VALOR da variável declarada em (1)
    cout << "Valor da variavel number: "; // TODO: Remove
    cout << number << "\n";

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << "Endereco da variavel intPointer: "; // TODO: Remove
    cout << &intPointer << "\n";
    
    // 7) Imprima o VALOR da variável declarada em (2)
    cout << "Valor da variavel intPointer: "; // TODO: Remove
    cout << intPointer << "\n";

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    cout << "Endereco da variavel intArray: "; // TODO: Remove
    cout << &intArray << "\n";

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << "Endereco primeira posicao intArray: "; // TODO: Remove
    cout << &intArray[0] << "\n";

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    cout << "Valor primeira posicao intArray: "; // TODO: Remove
    cout << intArray[0] << "\n";

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    intPointer = &number;

    // 12) Imprima o VALOR da variável declarada em (2)
    cout << "Endereco apontado por intPointer ao receber number: "; // TODO: Remove
    cout << intPointer  << "\n";

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << "Valor do endereco que intPointer aponta: "; // TODO: Remove
    cout << *intPointer << "\n";

    // 14) Imprima o resultado da comparação do ENDEREÇO de (1) e do VALOR de (2)
    cout << "Resultado da comparação do endereço de number e o valor contido no ponteiro intPointer: ";
    cout << (&number == intPointer) << "\n";

    // 15) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    *intPointer = 5;

    // 16) Imprima o VALOR da variável declarada em (1)
    cout << "Valor do number ao atualizar intPoitner com 5: "; // TODO: Remove
    cout << number << "\n";

    // 17) Atribua o ENDEREÇO da variável (3) à variável declarada em (2)
    intPointer = intArray;

    // 18) Imprima o VALOR da variável declarada em (2)
    cout << "Endereco apontado por intPointer ao receber intArray: "; // TODO: Remove
    cout << intPointer << "\n";

    // 19) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << "Valor do endereco apontado por intPoitner (deve ser a primeira posicao do intArray): "; // TODO: Remove
    cout << *intPointer << "\n";

    // 20) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    intPointer = &intArray[0];

    // 21) Imprima o VALOR da variável declarada em (2)
    cout << "Endereco apontado por intPointer ao receber primeira posicao de intArray: "; // TODO: Remove
    cout << intPointer << "\n";

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << "Valor contido no endereco apontado por intPointer apos receber posicao inicial intArray: "; // TODO: Remove
    cout << *intPointer << "\n";

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    for(size_t i = 0; i < size; i++) {
        intPointer[i] = intPointer[i] * 10;
    }

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    cout << "Todos elementos de intArray apos serem alterados por meio do intPointer (usando colchetes): \n"; // TODO: Remove
    for(size_t i = 0; i < size; i++) {
        cout << intPointer[i];
        if(i != size - 1) {
            cout << " ";
        }
        else {
            cout << "\n";
        }
    }

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    cout << "Imprimindo elementos do intArray por meio do endereço: \n"; // TODO: Remover
    for(int i = 0; i < size; i++) {
        cout << *(intArray + i);
        if(i != size - 1) {
            cout << " ";
        }
        else{
            cout << "\n";
        }
    }

    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    cout << "Imprimindo elementos do intArray por meio do endereço com o ponteiro intPointer: \n"; // TODO: Remover
    for(int i = 0; i < size; i++) {
        cout << *(intPointer + i);
        if(i != size - 1) {
            cout << " ";
        }
        else{
            cout << "\n";
        }
    }

    // 27) Atribua o ENDEREÇO da quinta posição de (3) à variável declarada em (2)
    intPointer = &intArray[4];

    // 28) Imprima o VALOR da variável declarada em (2)
    cout << "Endereco apontado por intPointer apor receber a quarta posicao do intArray[4]: "; // TODO: Remover
    cout << intPointer << "\n";

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << "Valor contido no endereco apontado por intPointer (deve ser o valor de intArray[4]): "; // TODO: Remover
    cout << *intPointer << "\n";

    // 30) Imprima o VALOR guardado no ENDEREÇO do ponteiro (2) decrementado de 4
    cout << "Valor do endereco intPointer (intArray[4]) menos 4: "; // TODO: Remover
    cout << *(intPointer - 4) << "\n";

    // 31) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int **pointerPointer = &intPointer;

    // 32) Imprima o VALOR da variável declarada em (31)
    cout << "Endereco do pointerPointer: "; // TODO: Remover
    cout << pointerPointer << "\n";

    // 33) Imprima o ENDEREÇO da variável declarada em (31)
    cout << "Endereco do pointerPointer: "; // TODO: Remover
    cout << &pointerPointer << "\n";

    // 34) Imprima o VALOR guardado no ENDEREÇO apontado por (31)
    cout << "Endereco do ponteiro que o pointerPointer aponta (endereco do intPointer): "; // TODO: Remover
    cout << *pointerPointer << "\n";    

    // 35) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (31)
    cout << "Valor contido no endereco que o ponteiro que o pointerPointer aponta: "; // TODO: Remover
    cout << **pointerPointer << "\n";
    
    return 0;
}
