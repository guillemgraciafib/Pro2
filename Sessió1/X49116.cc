#include <vector>
 using namespace std;
 
 struct parint {int prim, seg;};
 
 parint max_min1(const vector<int>& v) {
    /* Pre: v.size()>0 */
    /* Post: el primer componente del resultado es el valor maximo de v;
    el segundo componente del resultado es el valor minimo de v */ 
    parint back;    
    
    for (int i = 0; i < v.size(); ++i) {
        if (i == 0) {
            back.prim = v[i];
            back.seg = v[i];
        }
        else if (v[i] > back.prim) back.prim = v[i];
        else if (v[i] < back.seg) back.seg = v[i];
    }
    return back;
 }
 
 pair<int,int> max_min2(const vector<int>& v) {
     /* Pre: v.size()>0 */
    /* Post: el primer componente del resultado es el valor maximo de v;
    el segundo componente del resultado es el valor minimo de v */
    pair <int, int> p;
    int max = 0, min = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (i == 0) {
            max = v[i];
            min = v[i];
        }
        else if (v[i] > max) max = v[i];
        else if (v[i] < min) min = v[i];
    }
    p.first = max;
    p.second = min;
    
    return p;
 }
 
 void max_min3(const vector<int>& v, int& x, int& y)
 /* Pre: v.size()>0 */
 /* Post: x es el valor maximo de v;  y es el valor minimo de v */
 {
    for (int i = 0; i < v.size(); ++i) {
        if (i == 0) {
            x = v[i];
            y = v[i];
        }
        else if (v[i] > x) x = v[i];
        else if (v[i] < y) y = v[i];
    }
}