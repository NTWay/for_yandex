/*Submit a solution for 3.2-Сортировка по многим полям
Full score:     120
Run penalty:    1
Score bonus:    
Time limit:     2 s
Real time limit:        5 s
Memory limit:   64M
Stack limit:    4M
Сортировка по многим полям
В базе данных хранится N записей, вида (Name,a1,a2,...,ak) — во всех записях одинаковое число параметров.

На вход задачи подаётся приоритет полей — перестановка на числах 1,...,k — записи нужно вывести в соответствии с этим приоритетом. В случае, если приоритет полей таков: 3 4 2 1, то это следует воспринимать так: надо читать как: приоритет значений из 3 колонки самый высокий, приоритет значений из колонки 4 ниже, приоритет значений из колонки 2 ещё ниже, а приоритет значений из колонки 1 самый низкий.

Input format
N (1⩽N⩽1000)

k (1⩽k;⩽10)

p1 p2 ... pk (перестановка на k числах, разделитель пробел)

N строк вида

Name a1 a2 ... ak (разделитель — пробел)

Output format
N строк с именами согласно приоритету

Example
in
        4
        3 4 2 1
        A 7 2 6 5
        B 6 4 4 7 
        C 1 5 6 6
        D 3 6 4 7
out
        C
        A
        D
        B
*/
#include <stdio.h>
#include <stdlib.h>

void Enter_arr(int **arr, char **Names, int N, int M)
{
        int i, j;
        for(i = 0; i < N; i++) //enter mass
                for(j = 0; j < M; j++){
                        if (!j){
                                scanf("%s", Names[i]);
                                arr[i][j] = i;
                        } else
                                scanf("%d", &arr[i][j]);
                }
}

void Out_arr(int **arr, int N, int M) //mass[NxM] 
{
        int i, j;
        printf("\n");
        for(i = 0; i < N; i++){ //out main_arr
                for(j = 0; j < M; j++)
                        printf("%d ", arr[i][j]);
                printf("\n");
        }
        printf("\n");
}

void One_line_to_another(int **arr, int j, int k, int M) //reverce line j to line k in mass[NxM] (j < N & k < N)
{

        int i;
        int line[M];
        for(i = 0; i < M; ++i){
                line[i] = arr[j][i];
                arr[j][i] = arr[k][i];
                arr[k][i] = line[i];
        }
        /* with dynamic array it also can be done, but you need to
         * assign each element of array!(not like below) 
        int *tmp = malloc(M * sizeof(int));
        tmp = *(arr + j);
        *(arr + j) = *(arr + k);
        *(arr + k) = tmp;
        printf("\n");
        for(int i = 0; i < M; i++)
                printf("%d  ", arr[k][i]);
        printf("\n\n");
        //free(tmp); //without this line work correct
        */
}


void Sort_arr(int **arr, int *transp, int N, int M)
{
        int j, index_sort, k;
        for(j = M - 2; j >= 0; j--){
                index_sort = transp[j];
                int flag_for_bubble_sort = 1;
                while(flag_for_bubble_sort){
                        flag_for_bubble_sort = 0;
                        for(k = 0; k < N-1; k++){
                                if(arr[k][index_sort] < arr[k+1][index_sort]){
                                        One_line_to_another(arr, k, k+1, M);
                                        flag_for_bubble_sort = 1;
                                }
                        }
                }
        }
}

int main(int argc, char **argv) //решаем с помощью поразрядной сортировки
{
        enum {Name_len = 20};
        int N, M, k, i;
        char **Names;
        int **Arr, *Transp;
        scanf("%d\n%d", &N, &k);
        M = k + 1;
        //alloc memory
        Names = (char **) malloc(N * sizeof(char *));
        Arr = malloc(N * sizeof(int *));
        for(i = 0; i < N; i++){
                *(Names + i) = malloc(Name_len * sizeof(char));
                *(Arr + i) = malloc(M * sizeof(int));
        }
        Transp = malloc(k * sizeof(int));
        for(i = 0; i < k; i++) //enter transpositions
                scanf("%d", &Transp[i]);


        Enter_arr(Arr, Names, N, M);
        Sort_arr(Arr, Transp, N, M);
        for(i = 0; i < N; i++)
                printf("%s\n", Names[Arr[i][0]]);

        return 0;
}
