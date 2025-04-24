#include<stdio.h>
int main()
{
   int A[2][2],B[2][2],c[2][2];
   int i, j;
   int P, Q, R, S , T, U, V;
 
   printf("Enter the elements in first matrix");
    for(i=0;i<2;i++){
      for(j=0;j<2;j++){
        scanf("%d",&A[i][j]);
        }
       }
    printf("Enter the elements in second matrix");
    for(i=0;i<2;i++){
      for(j=0;j<2;j++){
        scanf("%d",&B[i][j]);
        }
       }
         
   P= (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
   Q= (A[1][0] + A[1][1]) * B[0][0];
   R= A[0][0] * (B[0][1] - B[1][1]);
   S= A[1][1] * (B[1][0] - B[0][0]);
   T= (A[0][0] + A[0][1]) * B[1][1];
   U= (A[1][0] - A[0][0]) * (B[0][0]+B[0][1]);
   V= (A[0][1] - A[1][1]) * (B[1][0]+B[1][1]);
   c[0][0] = P + S- T + V;
   c[0][1] = R + T;
   c[1][0] = Q + S;
   c[1][1] = P+R-Q+U;
   printf("\nProduct achieved using Strassen's algorithm: ");
   for(i = 0; i < 2 ; i++) {
      printf("\n");
      for(j = 0; j < 2; j++)
         printf("%d\t", c[i][j]);
   }
   return 0;
}

/*
dell@dell-OptiPlex-3000:~/Desktop/nisha/Assignment 4$ gcc strassen.c
dell@dell-OptiPlex-3000:~/Desktop/nisha/Assignment 4$ ./a.out
Enter the elements in first matrix 4
3
5
6
Enter the elements in second matrix3
-2
-4
2

Product achieved using Strassen's algorithm: 
0	-2	
-9	2	
*/

