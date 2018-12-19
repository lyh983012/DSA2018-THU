#include <cstdio>
#include "temperature.h"

using namespace std;

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k); 

    int **a = new int *[n + 1];
    for (int x = 1; x <= n; x++) { 
        a[x] = new int[m + 1];
        for (int y = 1; y <= m; y++)
            scanf("%d", &a[x][y]);
    }

    init(n, m, a);

    for (int i = 0; i < k; i++) {
        int op;
        scanf("%d", &op);
        if (op == 0) {
            int x, y, temp;
            scanf("%d%d%d", &x, &y, &temp);
            change(x, y, temp);
        } else {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            printf("%d\n", query(x1, y1, x2, y2));
        }
    }

    for (int i = 1; i <= n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
