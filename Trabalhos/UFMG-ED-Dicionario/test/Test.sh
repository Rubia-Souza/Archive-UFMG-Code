#! /bin/sh
cd ../bin;

# Executa teste com Árvore AVL
./run -i ../test/entrada00.txt -o ./saidaAVL-endrada00.txt -t arv
./run -i ../test/entrada01.txt -o ./saidaAVL-endrada01.txt -t arv
./run -i ../test/entrada02.txt -o ./saidaAVL-endrada02.txt -t arv
./run -i ../test/entrada03.txt -o ./saidaAVL-endrada03.txt -t arv
./run -i ../test/entrada04.txt -o ./saidaAVL-endrada04.txt -t arv

# Executa teste com Hash
./run -i ../test/entrada00.txt -o ./saidaHash-endrada00.txt -t hash
./run -i ../test/entrada01.txt -o ./saidaHash-endrada01.txt -t hash
./run -i ../test/entrada02.txt -o ./saidaHash-endrada02.txt -t hash
./run -i ../test/entrada03.txt -o ./saidaHash-endrada03.txt -t hash
./run -i ../test/entrada04.txt -o ./saidaHash-endrada04.txt -t hash
