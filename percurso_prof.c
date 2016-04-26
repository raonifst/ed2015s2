/*
* Exemplo de implementação do algoritmo de percurso em 
* profundidade.
*/

/* As cores são utilizadas para marcar quando um vertice ainda não foi visitado (BRANCO), 
*  está sendo visitado (CINZA) ou já foi visitado (PRETO).
*/
#define BRANCO 0
#define CINZA 1
#define PRETO 2

/*Estrutura de dados utilizada para armazenar um lista de vértices*/
typedef  struct  _celula{
    int  vertice;
    struct  _celula *prox;
}Celula;

typedef Celula* Lista;

/*
* Função que recebe que recebe um grafo G e um vértice v e calcula o percurso 
* em profundidade obtido a partir de v. Os vértices visitados neste percurso 
* são inseridos na Lista L em ordem de vistação.
* A função devolve 1 se há um ciclo alcançável a partir de v e 0 caso contrário.
*/
int percurso_prof(Grafo* G, int v, Lista* L)
{
    Lista adj, tmp, ciclo = 0;

    if(G->cor[v] == CINZA) /*Ciclo*/
        return 1;

    if(G->cor[v] == BRANCO) {

        G->cor[v] = CINZA;

	/* A função adjacentes a ser implementada deve devolver uma nova lista 
	*  com os que são adjacentes a v 
	*/
        adj = adjacentes(G, v);

        for(tmp = adj; adj != NULL; adj = adj->prox)
            ciclo = ciclo || percurso_prof(G, adj->vertice, L);
        G->cor[v] = PRETO;
	
	/*visita o vértice v*/
        inserir_lista(L, v);
	
	/*Apaga a memória reservada pela funcao adjacentes*/	
        if(tmp)
            destruir_lista(&tmp);
    }

    return ciclo;
}
