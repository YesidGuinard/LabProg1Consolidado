#include <stdio.h>
#include <stdlib.h>


void insertion_sort(int vector[], int len) {
    int i;
    int j;
    int tmp;

	for( i = 1; i < len; ++i) {
		tmp = vector[i];
		j = i-1;
		while(j >= 0 && tmp < vector[j]) {
			vector[j+1] = vector[j];
			j--;
		}
		vector[j+1] = tmp;
	}
}

int main () {
    int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int n =10;
    int i;
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    insertion_sort(a, n);
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    return 0;
}
