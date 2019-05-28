#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std; //Нужно составить массив из указателей на массивы различной длинны.


int main() {
	int n, q, i, j, k;
	scanf("%d %d\n", &n, &q);
	int **array = new int*[n]; // выделяем массив из n указателей типа int - строки
	for (i = 0; i < n; i++){
		scanf("%d", &k);
		array[i] = new int[k]; // заполняем строки
		array[i][0] = k;
		for(j = 1; j < k + 1; j++)
			scanf("%d", &array[i][j]);
	}


	/*printf("\nOUT:\n");	       //Вывод списка массивов
	for(i = 0; i < n; i++) {
		for(j = 0; j < array[i][0]+1; j++) 
			printf("%d ", array[i][j]);
		printf("\n");
	}*/
	int a[q];
	for (n = 0; n < q; n++){
		scanf("%d %d", &i, &j);
		*(a+n) = array[i][j+1];	
	}
	i = 0;
	while (q > 0){
		printf("%d\n", *(a+i)); //К массивам можно обращаться по указателям *(a+i),						а можно как к элементам массива a[i]
		q--; 
		i++;
	}
	return 0;
}

