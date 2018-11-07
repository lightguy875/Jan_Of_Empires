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

## Prédios
Os prédios são pilares. Cada pilar representa a unidade que foi criada a partir do pilar usando ossos, e ele cria uma única unidade, que é o necromancer. Com o pilar podemos aumentar o poder do necromancer usando ossos.

Cada prédio tem:
-HP: representa a vida do pilar. Se chega a zero, ele é destruído.

É possível reconstruir pilares, com o máximo de 3 por jogador.

Três tipos de pilares:
-Pilar da Espada: é o pilar que representa o necromancer guerreiro.
-Pilar da Lança: é o pilar que representa o necromancer cavaleiro.
-Pilar do Arco : é o pilar que representa o necromancer arqueiro.


## Unidades
As unidades são representadas como um único elemento, que tem um número que define quanto de poder que ele tem. Por exemplo: em um bloco, há uma unidade A com o número 20. Isso significa que a unidade A tem 20 de poder.

Cada unidade tem: 
-MP: representa quanto de poder a unidade tem e representa a vida da unidade. Se ela chegar a zero, a unidade morre.

São 3 tipos de unidades:

-Necromancer Guerreiro (A): é o necromancer que invoca somente undeads guerreiros. Esses undeads não são representados no mapa, mas são o que definem o poder do necromancer (é o número que mostra a força da unidade). Ele tem vantagem sobre o Necromancer Cavaleiro e desvantagem sobre o Necromancer Arqueiro.

-Necromancer Cavaleiro (B): é o necromancer que invoca somente undeads cavaleiros. Esses undeads não são representados no mapa, mas são o que definem o poder do necromancer (é o número que mostra a força da unidade). Ele tem vantagem sobre o Necromancer Arqueiro e desvantagem sobre o Necromancer Guerreiro.

-Necromancer Arqueiro (C): é o necromancer que invoca somente undeads arqueiros. Esses undeads não são representados no mapa, mas são o que definem o poder do necromancer (é o número que mostra a força da unidade). Ele tem vantagem sobre o Necromancer Guerreiro e desvantagem sobre o Necromancer Cavaleiro.

O máximo de unidades no jogo são 6.

# Regras definidas para o jogo

## Inicialização
Elementos iniciais:
-Pilar da Espada
-Necromancer guerreiro
-Mapa com recursos espalhados randomicamente.

## Turno
O turno é definido para criar pilares, fortalecer as unidades e mover uma delas. Ele acaba quando o jogador decide terminar o turno, movendo ou não as unidades.

## Condições de término do jogo
As condições para o término do jogo são os seguintes:
-Se todos os pilares do oponente forem destruídos;
-Se todos os recursos do mapa acabarem: nesse caso, a quantidade da vida dos pilares + unidades é somado. Quem tiver mais, vence.

# Useful links
+ [SDL Tutorial link](http://lazyfoo.net/tutorials/SDL/)



