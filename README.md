# Jan of Empires Deluxe Edition
Simple Strategy game

# Ideia do jogo
É um jogo de estratégia em turnos onde você controla 3 unidades para explorar, adquirir recursos, aumentar o poder da sua unidade usando os pilares para vencer o oponente. Cada tipo de unidade tem vantagem sobre outra unidade. O jogo é single-player com 1 CPU de oponente.

# Elementos do Jogo

## Recursos
Os recursos servem para criar pilares novos, aumentar o poder do necromancer que o pilar representa ou, se somente houver o pilar, criar o necromancer usando o pilar que o representa.

Dois tipos de recursos:
-Metal: para criação de pilares. Menos abundante no mapa (terá o suficiente para criar mais 2 pilares para cada jogador).
-Ossos: para aumento de poder das unidades. Mais abundante no mapa.

## Prédios (Pilares)
Os prédios são pilares. Cada pilar representa uma fábrica de um tipo de unidade que será criada a partir da quantidade de ossos. Cada pilar cria uma única unidade, que é o necromancer. Depois de criado o necromancer, o pilar pode aumentar o poder do necromancer utilizando ossos.

Cada pilar tem:
-HP: representa a vida do pilar. Se chega a zero, ele é destruído.

É possível reconstruir pilares, com o máximo de 3 por jogador.

Três tipos de pilares:
-Pilar da Espada: é o pilar que cria o necromancer guerreiro.
-Pilar da Lança: é o pilar que cria o necromancer cavaleiro.
-Pilar do Arco : é o pilar que cria o necromancer arqueiro.


## Unidades (Necromancers)
As unidades são representadas por um único elemento, o Necromancer. 
Cada necromancer tem um número associado que define quanto de poder ele tem. 
Por exemplo: no mapa há uma unidade A com o número 20. Isso significa que a unidade A tem 20 de poder.

Cada unidade tem: 
-MP: representa quanto de poder a unidade tem e representa a vida da unidade. Se ela chegar a zero, a unidade morre.

São 3 tipos de unidades:

-Necromancer Guerreiro (A): é o necromancer que invoca somente undeads guerreiros. A quantidade de undeads é o que define o poder do necromancer (é o número que mostra a força da unidade). Ele tem vantagem sobre o Necromancer Cavaleiro e desvantagem sobre o Necromancer Arqueiro.

-Necromancer Cavaleiro (B): é o necromancer que invoca somente undeads cavaleiros. A quantidade de undeads é o que define o poder do necromancer (é o número que mostra a força da unidade). Ele tem vantagem sobre o Necromancer Arqueiro e desvantagem sobre o Necromancer Guerreiro.

-Necromancer Arqueiro (C): é o necromancer que invoca somente undeads arqueiros. EA quantidade de undeads é o que define o poder do necromancer (é o número que mostra a força da unidade). Ele tem vantagem sobre o Necromancer Guerreiro e desvantagem sobre o Necromancer Cavaleiro.

O máximo de unidades no jogo são 6.

# Regras definidas para o jogo

## Inicialização
Inicialmente cada jogardor possui:
- 1 Pilar da Espada
- 1 Necromancer guerreiro

## Turno
Em UM turno o jogador pode criar pilares, fortalecer unidades e mover apenas uma delas. Ele acaba quando o jogador move uma peça ou decide terminar o turno.

## Captação de recursos
Os recursos são espalhados randômicamente no mapa no início do jogo.
São capturados quando o jogador move uma unidade para o mesmo bloco em que o recurso está inserido.

## Combate
O combate acontece automaticamente quando duas unidades estão vizinhas
O combate acontece sempre entre apenas duas unidades
No combate, verificam-se os poderes de cada unidade, e as capacidades e fraquezas de cada uma em relação a outra, de acordo com os seus tipos. Então, é decrescido poder de cada uma de acordo com o estabelecido.

## Condições de término do jogo
As condições para o término do jogo são os seguintes:
-Se todos os pilares do oponente forem destruídos;
-Se todos os recursos do mapa acabarem: nesse caso, a quantidade da vida dos pilares + unidades é somado. Quem tiver mais, vence.

# Useful links
+ [SDL Tutorial link](http://lazyfoo.net/tutorials/SDL/)



