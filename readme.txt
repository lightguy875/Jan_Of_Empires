----- PRÉREQUISITOS -----
>>> g++ --> sudo apt-get install build-essential
>>> SDL2 --> sudo apt-get -y install libsdl2-2.0-0 libsdl2-dev libsdl2-doc libsdl2-gfx-1.0-0 libsdl2-gfx-dev libsdl2-image-2.0-0 libsdl2-image-dev libsdl2-mixer-2.0-0 libsdl2-mixer-dev libsdl2-net-2.0-0 libsdl2-net-dev libsdl2-ttf-2.0-0 libsdl2-ttf-dev
        Caso haja erro, instale o synaptic (sudo apt-get install synaptic), faça o search de libsdl2 e instale os pacotes acima mencionados
>>> make --> sudo apt-get -y install cmake
----- COMO COMPILAR -----
1) Abra o terminal na pasta src
2) Os seguintes comandos estão disponíveis:
    >>> make clean: limpa o repositório dos objetos gerados a partir da compilação
    >>> make test: para compilar e rodar os testes (back-end)
    >>> make cov: gera o relatório de cobertura de testes. Use este comando após compilar com make test.
    >>> make project: para compilar e rodar o jogo
