#ifndef UTILS_HPP
#define UTILS_HPP

const unsigned short MP_INICIAL_GUERREIRO = 300;
const unsigned short MP_INICIAL_ARQUEIRO = 300;
const unsigned short MP_INICIAL_CAVALEIRO = 300;

const unsigned short HP_INICIAL_PILAR_ESPADA = 1000;
const unsigned short HP_INICIAL_PILAR_ARCO = 1000;
const unsigned short HP_INICIAL_PILAR_LANCA = 1000;

const unsigned short QUANTIDADE_OSSOS_POR_ITEM = 10;
const unsigned short QUANTIDADE_METAL_POR_ITEM = 20;

const unsigned short OSSOS_CRIAR_GUERREIRO = 30;
const unsigned short OSSOS_CRIAR_ARQUEIRO = 30;
const unsigned short OSSOS_CRIAR_CAVALEIRO = 30;

const unsigned short METAL_CRIAR_PILAR_ESPADA = 60;
const unsigned short METAL_CRIAR_PILAR_ARCO = 60;
const unsigned short METAL_CRIAR_PILAR_LANCA = 60;

const unsigned short MAPA_LARGURA = 20;
const unsigned short MAPA_ALTURA = 15;

const unsigned short OSSOS_MAPA = 20;
const unsigned short METAL_MAPA = 20;

const unsigned short X_PILAR_PLAYER = 0;
const unsigned short Y_PILAR_PLAYER = 0;

const unsigned short X_NECROMANCER_PLAYER = 1;
const unsigned short Y_NECROMANCER_PLAYER = 1;

const unsigned short X_PILAR_COMPUTADOR = MAPA_LARGURA - 1;
const unsigned short Y_PILAR_COMPUTADOR = MAPA_ALTURA - 1;

const unsigned short X_NECROMANCER_COMPUTADOR = MAPA_LARGURA - 2;
const unsigned short Y_NECROMANCER_COMPUTADOR = MAPA_ALTURA - 2;

const unsigned short DANO_DE_ATQ = 50;

const unsigned short ESPADA_ARCO_ATQ_MULTIPICADOR = 1;
const unsigned short ESPADA_ESPADA_ATQ_MULTIPICADOR = 2;
const unsigned short ESPADA_LANCA_ATQ_MULTIPICADOR = 3;

const unsigned short LANCA_ESPADA_ATQ_MULTIPICADOR = 1;
const unsigned short LANCA_LANCA_ATQ_MULTIPICADOR = 2;
const unsigned short LANCA_ARCO_ATQ_MULTIPICADOR = 3;

const unsigned short ARCO_LANCA_ATQ_MULTIPICADOR = 1;
const unsigned short ARCO_ARCO_ATQ_MULTIPICADOR = 2;
const unsigned short ARCO_ESPADA_ATQ_MULTIPICADOR = 3;

const unsigned short RANGE_MOVIMENTO = 2;
const unsigned short RANGE_COMBATE = 1;

#endif