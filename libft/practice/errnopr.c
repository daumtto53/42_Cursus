#include <stdio.h>
#include <stdlib.h>
#include <error.h>


void main()

{

  FILE *fp;

  if ((fp = fopen("data.txt", "r")) == NULL) {
    perror("ERROR");
    exit(1);
  }
  exit(0);

}
