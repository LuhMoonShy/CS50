#include <stdio.h> 
#include <cs50.h>

int  main(void)
{
  int altura = 0;
  do{
    altura = get_int("Altura : ");
  }
  while (altura < 1 || altura > 8);
  for (int i = 0;i < altura;i++){
    for (int j = 0; j < altura; j++){
      if(i + j < altura - 1){
      printf (" ");
      }
      else{
      printf("#");
      }
    }
    printf("\n");
  }
return 0;
}