
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

/**********************************************
* Exercicios de Listas Simplesmente Encadeadas
* Indice de variavel 
> Iniciando com i = inteiro
> Iniciando com e = estrutura
> Iniciando com p = ponteiro
**********************************************/

// Criando a estrutura que vai armazenar os dados
struct eNodo 
{
	// Criando a variavel pros valores
	int iDados;
	
	// Ponteiro pra referenciar o proximo valor
	struct eNodo *pProximo;
} *pInicio = NULL, *pFim; // Ponteiros dessa mesma estrutura

/********************************************
** Inserindo novos valores no final da lista
********************************************/
void insereDireita(int iValor, int *pSinal)
{
	// Criando um ponteiro para trabalhar com estrutura 
	eNodo *pAuxiliar;
	
	// O ponteiro aloca memoria 
	pAuxiliar = (struct eNodo *) malloc(sizeof(struct eNodo));
	
	// Certificando que o ponteiro tem algo
	if(pAuxiliar)
	{
		// O campo dados da estrutura recebe o valor digitado
		pAuxiliar->iDados = iValor;
		
		// O ponteiro PROXIMO recebe nulo pra nao dar problemas
		pAuxiliar->pProximo = NULL;
		
		// Certificando que vai ser o primeiro valor 
		if (pInicio == NULL)
		{
			pInicio = pAuxiliar;
		}
		else
		{
			// Inserindo a referencia do PROXIMO valor
			pFim->pProximo = pAuxiliar;
		}
		
		// Inserindo no final da lista o valor digitado
		pFim = pAuxiliar;
		
		// Variavel de controle de execucao
		*pSinal = 1;
	} 
	else 
	{
		*pSinal = 0;
	}
}

/*********************************************
** Inserindo novos valores no início da lista
*********************************************/
void insereAntesValor(int iValor, int iValorBuscado, int *pSinal)
{
	// Criando um ponteiro para trabalhar com estrutura 
	eNodo *pAuxiliar;
	
	// O ponteiro aloca memoria 
	pAuxiliar = (struct eNodo *) malloc(sizeof(struct eNodo));
	
	// Certificando que o ponteiro tem algo
	if(pAuxiliar)
	{
		// O campo dados da estrutura recebe o valor digitado
		pAuxiliar->iDados = iValor;
		
		// O ponteiro PROXIMO recebe nulo pra nao dar problemas
		pAuxiliar->pProximo = pInicio;
		pInicio = pAuxiliar;
		
		// Certificando que vai ser o primeiro valor 
		if (pInicio == NULL)
		{
			pFim = pInicio;
		}
		
		// Variavel de controle de execucao 
		*pSinal = 1;
	} 
	else 
	{
		*pSinal = 0;
	}
}










/*********************************************
** Inserindo novos valores no início da lista
*********************************************/
void insereEsquerda(int iValor, int *pSinal)
{
	// Criando um ponteiro para trabalhar com estrutura 
	eNodo *pAuxiliar;
	
	// O ponteiro aloca memoria 
	pAuxiliar = (struct eNodo *) malloc(sizeof(struct eNodo));
	
	// Certificando que o ponteiro tem algo
	if(pAuxiliar)
	{
		// O campo dados da estrutura recebe o valor digitado
		pAuxiliar->iDados = iValor;
		
		// O ponteiro PROXIMO recebe nulo pra nao dar problemas
		pAuxiliar->pProximo = pInicio;
		pInicio = pAuxiliar;
		
		// Certificando que vai ser o primeiro valor 
		if (pInicio == NULL)
		{
			pFim = pInicio;
		}
		
		// Variavel de controle de execucao 
		*pSinal = 1;
	} 
	else 
	{
		*pSinal = 0;
	}
}













/************************
* Listando tudo digitado 
************************/
void mostraLista()
{ 
	// Cria a referencia pra estrutura
	struct eNodo *pPonteiro;
	
	// Pega o inicio da estrutura 
	pPonteiro = pInicio;
	
	while(pPonteiro)
	{
		printf("Elemento = %i\n", pPonteiro->iDados);
		pPonteiro = pPonteiro->pProximo;
	}
	printf("Continue...");
	getch();
}

/********************
** Limpando a lista 
*********************/
void liberaLista() {
	struct eNodo *pPonteiro;
	pPonteiro = pInicio;
	
	while (pPonteiro) {
		pInicio = pInicio->pProximo;
		free(pInicio);
		pPonteiro = pInicio;
	}
}

/**********************
** Novo valor na lista 
***********************/
void trocarElemento(int iValorProcurado, int iNovoValor)
{
	struct eNodo *pPonteiro;
	pPonteiro = pInicio;
	
	while (pPonteiro) 
	{
		if (pPonteiro->iDados == iValorProcurado)
		{
			pPonteiro->iDados = iNovoValor;
		}
		pPonteiro = pPonteiro->pProximo;
	}
}

/**********************
** Novo valor na lista 
***********************/
void maiorElemento()
{
	struct eNodo *pPonteiro;
	pPonteiro = pInicio;
	int inicial = NULL, atual = NULL, maior = NULL;
	
	while (pPonteiro) 
	{
		if (inicial == NULL) {
			maior = pPonteiro->iDados;
		} else {
			if (pPonteiro->iDados > maior) {
				maior = pPonteiro->iDados;
			}
		}
		
		pPonteiro = pPonteiro->pProximo;
	}
	
	printf("\n --- Maior valor: %i -- \n", maior);
}

int main()
{
	int valor, i, ok;
	struct nodo *aux;
	
	printf("Digite 5 valores:\n");
	for (i=1; i<=5; i++) // insere 5 elementos pelo inicio da lista
	{
		scanf("%i", &valor);
		fflush(stdin);
		
		// insereEsquerda(valor, &ok);
		insereDireita(valor, &ok);
		
		if(!ok)
		{
			printf("Erro ao inserir este valor!\n");
			getch();
		}
	}
	
	mostraLista();
	
	// Aqui eh so trocar a chamada de cada funcao
	
	//////////////////////////////////////////////////
	// Trocar valor na lista 
	// printf("\n\nDigite valor a ser trocado da lista: ");
	// scanf("%i", &valor);
	
	// printf("\nNovo valor a ser inserido na lista: ");
	// scanf("%i", &i);
	
	// trocarElemento(valor, i);
	// mostraLista();
	//////////////////////////////////////////////////
	
	//////////////////////////////////////////////////
	// Maior valor da lista
	// maiorElemento();
	//////////////////////////////////////////////////
	
	liberaLista();
	getch();
}


