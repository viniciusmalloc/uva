#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>

using namespace std;

typedef pair<string, map<string, bool>> smap;

int main()
{
    ios::sync_with_stdio(false);
    int n, num, w, p;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        queue<smap> qmapa;
        queue<int> q;
        queue<string> qs;
        set<string> st;
        cin >> num;
        string str, word, resp, aux;
        map<string, bool> sb;
        for (int k = 0; k < num; ++k) {
            map<string, bool> mapa;
            cin >> str;
            cin >> w >> p;
            q.push(p);
            cin.ignore(1);
            for (int j = 0; j < w; ++j) {
                cin >> word;
                mapa.insert(make_pair(word, true));
            }
            qmapa.push(make_pair(str, mapa));
        }
        cin.ignore();
        while (getline(cin, aux) && aux.size()) {
            string lp;
            for (int x = 0; x < aux.size(); ++x) {
                if ((aux[x] >= 'A' && aux[x] <= 'Z') || (aux[x] >= 'a' && aux[x] <= 'z'))
                    lp += aux[x];
                else {
                    st.insert(lp);
                    lp = "";
                }
            }
            st.insert(lp);
        }
        map<string, bool>::iterator it;
        while (!qmapa.empty()) {
            int count = 0;
            sb = qmapa.front().second;
            aux = qmapa.front().first;
            int r = q.front();
            q.pop();
            qmapa.pop();
            if (r == 0)
                qs.push(aux);
            else {
                for (it = sb.begin(); it != sb.end(); ++it) {
                    if (st.count(it->first)) {
                        count++;
                        if (count == r) {
                            qs.push(aux);
                            break;
                        }
                    }
                }
            }
        }
        int tam = qs.size(), l = 0;
        if (tam == 0)
            cout << "SQF Problem.";
        else {
            while (!qs.empty()) {
                if (l < tam - 1) {
                    cout << qs.front() << ",";
                    l++;
                } else {
                    cout << qs.front();
                    l++;
                }
                qs.pop();
            }
        }
        cout << "\n";
    }
    return 0;
}
