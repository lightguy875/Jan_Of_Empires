#ifndef BLOCO_HPP
#define BLOCO_HPP

enum class TipoConteudoBloco{
    UNIDADE=0,PREDIO,RECURSO
};


class ColocavelEmBloco 
{
    public:
        TipoConteudoBloco tipo;
};

class Bloco
{
    public:
        bool vazio;
        ColocavelEmBloco *conteudo;

        Bloco();
        Bloco(ColocavelEmBloco *);
        bool preenche(ColocavelEmBloco *);
        bool retira(ColocavelEmBloco *);
        bool limpa();
};
#endif