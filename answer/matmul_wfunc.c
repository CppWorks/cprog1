#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define nra 3
#define nca 3
#define ncb 3

void print_matrix(double** a, int row, int col, char name[], char fmt_string[]);
             
int main() {
  int i,j,k;
  double a[nra][nca],b[nca][ncb],c[nra][ncb];
  double sum;
  char fmt_string[]="%5.1f ";

  for (i = 0; i < nra; i++){
    for (j = 0; j < nca; j++){
      a[i][j] = (double)(i+j);
    }
  }
  for (j = 0; j < nca; j++){
    for (k = 0; k < ncb; k++){
      b[j][k] = (double)(i*j);
    }
  }
  for (i = 0; i < nra; i++){
    for (k = 0; k < ncb; k++){
      c[i][k] = 0.0;
    }
  }
  
  for (i = 0; i < nra; i++){
    for (k = 0; k < ncb; k++){
      sum = 0.0;
      for (j = 0; j < nca; j++){
         sum = sum + a[i][j] * b[j][k];
      }
      c[i][k] = sum;
    }
  }

  printf("\n A=\n");
  /* output A matrix*/
  for (i = 0; i < nra; i++){
      for (j = 0; j < nca; j++){
          printf(fmt_string, a[i][j]);
      }
      printf("\n");
  }
  printf("\n B=\n");
  
  /* output B matrix*/
  for (i = 0; i < nca; i++){
      for (j = 0; j < ncb; j++){
          printf(fmt_string, b[i][j]);
      }
      printf("\n");
  }
  
  printf("\n C=\n");
  /* output C matrix*/
  for (i = 0; i < nra; i++){
      for (j = 0; j < nca; j++){
          printf(fmt_string, c[i][j]);
      }
      printf("\n");
  }
  
  print_matrix(c, nra, nca, "C", fmt_string);
}

void print_matrix(double** mat, int row, int col, char name[20], char fmt_string[20]) {
  int i, j;
  printf("\nMatrix %s:\n", name);
  /* output the matrix*/
  for (i = 0; i < row; i++){
      for (j = 0; j < col; j++){
          printf(fmt_string, mat[i][j]);
      }
      printf("\n");
  }
}
