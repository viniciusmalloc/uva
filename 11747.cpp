#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int v, a;

struct no {
    int pai;
    int rank;
};

typedef struct no Tno;
vector<Tno> pset;

void Link(int x, int y)
{
    if (pset[x].rank > pset[y].rank)
        pset[y].pai = x;
    else {
        pset[x].pai = y;
        if (pset[x].rank == pset[y].rank)
            pset[y].rank = pset[y].rank + 1;
    }
}

void initialize()
{
    pset.resize(v);
    for (int i = 0; i < v; i++) {
        pset[i].pai = i;
        pset[i].rank = 0;
    }
}

int findSet(int x)
{
    if (pset[x].pai != x)
        pset[x].pai = findSet(pset[x].pai);
    return (pset[x].pai);
}

void Union(int x, int y)
{
    Link(findSet(x), findSet(y));
}

typedef struct aresta {
    int de, para, peso;
} Taresta;

bool operator<(const Taresta& a, const Taresta b)
{
    return a.peso < b.peso;
}

int main()
{
    ios::sync_with_stdio(false);
    int de, para, peso;
    for (cin >> v >> a; v + a; cin >> v >> a) {
        vector<Taresta> grafo(a), agm;
        int total = 0, resto = 0;
        vector<int> pesos;
        for (int i = 0; i < a; i++) {
            cin >> de >> para >> peso;
            grafo[i].de = de;
            grafo[i].para = para;
            grafo[i].peso = peso;
        }
        sort(pesos.begin(), pesos.end());
        sort(grafo.begin(), grafo.begin() + a);
        vector<Taresta>::iterator it;
        initialize();
        for (it = grafo.begin(); it != grafo.end(); it++) {
            if (findSet(it->de) != findSet(it->para))
                Union(it->de, it->para);
            else
                pesos.push_back(it->peso);
        }
        if (pesos.size() == 0)
            cout << "forest";
        else {
            for (int j = 0; j < pesos.size(); j++) {
                if (j == 0)
                    cout << pesos[j];
                else
                    cout << " " << pesos[j];
            }
        }
        cout << "\n";
    }
    return 0;
}
