.data
vetor: .word 200, 190, 340, 100 # exemplo
vetor2: .word 1000, 1500, 1300, 1200, 500
vetor3: .word 721, 363, 940, 120, 380, 534, 1200, 850

##### START MODIFIQUE AQUI START #####
#
# Este espaço é para você definir as suas constantes e vetores auxiliares.
#
##### END MODIFIQUE AQUI END #####

.text

teste1:
    la x10, vetor
    addi x11, x0, 4
    addi x12, x0, 200

    jal ra, main

# Ao final do reajuste (aplica_reajuste) você deve retornar o programa para a próxima instrução abaixo, que consiste na correção/verificação.

##### START INSTRUÇÃO DE CORREÇÃO/VERIFICAÇÃO #####

# Utilizado para correção (considerando um limiar de 200 para o vetor de exemplo após a aplicação do reajuste.
addi a4, x0, 3  # configurando a quantidade de salários acima do limiar de 200.
beq a4, t0, teste2 # Verifica a quantidade de salários acima do limiar.

##### END INSTRUÇÃO DE CORREÇÃO/VERIFICAÇÃO #####

teste2:
    la x10, vetor2
    addi x11, x0, 5
    addi x12, x0, 2000

    jal ra, main

    addi a4, x0, 1  # configurando a quantidade de salários acima do limiar de 200.
    beq a4, t0, teste3 # Verifica a quantidade de salários acima do limiar.

teste3:
    la x10, vetor3
    addi x11, x0, 8
    addi x12, x0, 1000

    jal ra, main

    addi a4, x0, 4  # configurando a quantidade de salários acima do limiar de 200.
    beq a4, t0, FIM # Verifica a quantidade de salários acima do limiar.

main:

##### START MODIFIQUE AQUI START #####

    # IMPORTANTE: Nessa questão considerei que os valores dos registradores a0, a1 e a2 já são passados como parâmetro para a função.
    # Ou seja, não é necessário carregar o vetor em a0, nem o tamanho do vetor em a1 e nem o limiar em a2.

    # t0 (x5) = quantidade salários acima do limiar
    # t1 (x6) = indice ajustado do vetor
    # t2 (x7) = indice do vetor
    # t3 (x28) = elemento atual do vetor
    # t4 (x29) = valor a ser adicionado no salário

    # a0 (x10) = endereco do vetor
    # a1 (x11) = tamanho do vetor
    # a2 (x12) = limiar desejado

    # Adiciona ponto de retorno na pilha
    addi x2, x2, -4     # Aloca uma posição na pilha
    sw x1, 0(x2)        # Armazena o endereço de retorno na pilha

    # Caso fosse necessário carregar o vetor em x10 bastaria descomentar as linhas abaixo
    # Carrega vetor em a0
    # la x10, vetor       # a0 = endereço do vetor

    # Chamar função de reajuste
    jal x1, aplica_reajuste

    # Contar quantidade de salários acima do limiar
    addi x5, x0, 0      # quantidade_salarios_acima_limiar = 0
    addi x6, x0, 0      # indice_ajustado = 0
    addi x7, x0, 0      # indice = 0

    # Armazena posição inicial do vetor na pilha
    addi x2, x2, -4     # Aloca uma posição na pilha
    sw x10, 0(x2)       # Armazena o endereço inicial do vetor na pilha

    loop_limiar:
        beq x7, x11, fim_loop_limiar    # indice == tamanho vetor ? goto fim_loop_limiar : continue

        # Carregar valor do salário no vetor
        lw x28, 0(x10)      # salario_atual = vetor[x10]

        # Ajusta posição do vetor
        addi x10, x10, 4    # indice_ajustado += 4
        addi x7, x7, 1      # indice++

        # Verificar salarios acima do limiar
        bge x28, x12, acima_limiar  # se salario_atual >= limiar ? incrementar contador limiar : continue

        j loop_limiar       # goto loop_limiar

        acima_limiar:
            addi x5, x5, 1  # quantidade_salarios_acima_limiar++
            j loop_limiar   # goto loop_limiar
    fim_loop_limiar:

    # Recarrega posição inicial do vetor
    lw x10, 0(x2)       # Carrega o endereço inicial do vetor
    addi x2, x2, 4      # Desaloca uma posição da pilha

    # Recarrega ponto de retorno da pilha
    lw x1, 0(x2)        # Carrega o endereço de retorno da pilha
    addi x2, x2, 4      # Desaloca uma posição da pilha

    jalr x0, 0(x1)      # return

##### END MODIFIQUE AQUI END #####

# dica, você deve salvar o endereço da primeira chamada (em stack (sp)) para depois recuperá-lo.
aplica_reajuste:

##### START MODIFIQUE AQUI START #####

    # Inicializa variáveis
    addi x6, x0, 0      # indice_ajustado = 0
    addi x7, x0, 0      # indice = 0
    addi x28, x0, 0     # salario_atual = 0
    addi x29, x0, 0     # valor_adicionado = 0

    # Adiciona ponto de retorno na pilha
    addi x2, x2, -4     # Aloca uma posição na pilha
    sw x1, 0(x2)        # Armazena o endereço de retorno na pilha

    # Armazena posição inicial do vetor na pilha
    addi x2, x2, -4     # Aloca uma posição na pilha
    sw x10, 0(x2)       # Armazena o endereço inicial do vetor na pilha

    loop_reajuste: 
        beq x7, x11, fim_loop_reajuste  # indice == tamanho vetor ? goto fim_loop_reajuste : continue

        # Carregar valor atual do salário no vetor
        lw x28, 0(x10)      # salario_atual = vetor[x10]

        # Aumentar salário em 50%
        srli x29, x28, 1    # valor_adicionado = salario_atual / 2 - Divide salário por 2 para obter 50% dele
        add x28, x29, x28   # salario_atual = salario_atual + valor_adicionado - Soma 50% do salário a ele mesmo

        # Atualiza valor do salário no vetor
        sw x28, 0(x10)      # vetor[x10] = salario_atual

        # Ajusta posição do vetor
        addi x10, x10, 4    # indice_ajustado += 4
        addi x7, x7, 1      # indice++

        j loop_reajuste     # goto loop_reajuste
    fim_loop_reajuste:

    # Recarrega posição inicial do vetor
    lw x10, 0(x2)       # Carrega o endereço inicial do vetor
    addi x2, x2, 4      # Desaloca uma posição da pilha

    # Recarrega ponto de retorno da pilha
    lw x1, 0(x2)        # Carrega o endereço de retorno da pilha
    addi x2, x2, 4      # Desaloca uma posição da pilha

    jalr x0, 0(x1)      # return

##### END MODIFIQUE AQUI END #####

FIM: addi x0, x0, 1