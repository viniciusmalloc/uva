#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

class No {
public:
    int valor;
    No *direito, *esquerdo;
    No();
    No(int);
};

No::No()
{
    this->direito = this->esquerdo = NULL;
}

No::No(int valor)
{
    this->valor = valor;
    this->direito = this->esquerdo = NULL;
}

class ArvoreBinaria {
protected:
    No* raiz;
    void PreOrdem(No*);
    void EmOrdem(No*);
    void PosOrdem(No*);

public:
    ArvoreBinaria();
    bool Vazio();
    int Busca(int);
    void insere(int);
    void PreOrdem();
    void EmOrdem();
    void PosOrdem();
};

void ArvoreBinaria::EmOrdem(No* inicio)
{
    if (inicio != NULL) {
        this->EmOrdem(inicio->esquerdo);
        printf(" %d", inicio->valor);
        this->EmOrdem(inicio->direito);
    }
}

void ArvoreBinaria::PreOrdem(No* inicio)
{
    if (inicio != NULL) {
        printf(" %d", inicio->valor);
        this->PreOrdem(inicio->esquerdo);
        this->PreOrdem(inicio->direito);
    }
}

void ArvoreBinaria::PosOrdem(No* inicio)
{
    if (inicio != NULL) {
        this->PosOrdem(inicio->esquerdo);
        this->PosOrdem(inicio->direito);
        printf("%d\n", inicio->valor);
    }
}

ArvoreBinaria::ArvoreBinaria()
{
    this->raiz = NULL;
}

bool ArvoreBinaria::Vazio()
{
    return this->raiz == NULL;
}

void ArvoreBinaria::insere(int valor)
{
    No* tmp = this->raiz;
    No* ant = NULL;

    while (tmp != NULL) {
        ant = tmp;
        if (tmp->valor < valor)
            tmp = tmp->direito;
        else
            tmp = tmp->esquerdo;
    }

    if (this->Vazio())
        this->raiz = new No(valor);
    else if (ant->valor < valor)
        ant->direito = new No(valor);
    else
        ant->esquerdo = new No(valor);
}

void ArvoreBinaria::PreOrdem()
{
    PreOrdem(this->raiz);
}

void ArvoreBinaria::EmOrdem()
{
    EmOrdem(this->raiz);
}

void ArvoreBinaria::PosOrdem()
{
    PosOrdem(this->raiz);
}

int main()
{
    int c, t = 1, n, q;
    ArvoreBinaria AB;
    while (scanf("%d", &c) != EOF)
        AB.insere(c);
    AB.PosOrdem();
    return 0;
}