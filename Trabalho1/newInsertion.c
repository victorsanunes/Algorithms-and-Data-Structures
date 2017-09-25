#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
 
char **getWords(int *Max_lines);
char **Insertion_sort(char** words, int Max_lines);
void print_lines(char**words, int Max_lines);
 
int main()
{
    clock_t ini_sort, fim_sort;
    double tempoSort;
    char **words;
    int Max_lines = 0;
 
    words = getWords(&Max_lines);
    //ini_sort = clock(); 
    words = Insertion_sort(words, Max_lines);
    //fim_sort = clock(); 
    //tempoSort = fim_sort - ini_sort;
    //printf("TEMPOO: %.2f", tempoSort);
    //print_lines(words, Max_lines);
     
    while (Max_lines >=0)
          free(words[Max_lines]);
    free(words);
     
getchar();
return 0;
}
 
 
char **getWords(int *Max_lines)
{
    FILE *fp;
    char buffer[22];
    char **words, **temp;
    int counter = 0;
    int n = 100;
     
    words = malloc(n * sizeof(char *) );
    printf("Initial array size is 100 words\n");
     
    if ( (fp = fopen("nomes.txt", "r" )) == NULL )
    {
     printf("Couldn't open file\n");
     exit(1); 
    }
     
    while( fgets(buffer, sizeof(buffer), fp))
    {
           strtok(buffer, "\n");
           words[counter] = malloc(strlen(buffer)+1);
           strcpy(words[counter], buffer);
            
           if ( (counter+1) == n )
           {
              n = n*2;
              temp= realloc(words, n*sizeof(char*));
              if(temp != NULL)
                      words = temp;
              else
              {
                  printf("unable to reallocate\n");
                  exit(1);
              }
              printf("Reached limit...increasing array to %d words\n", n);
           }    
           counter++;
    }        
fclose(fp);
*Max_lines = counter;  
return words;     
}
 
 
char **Insertion_sort(char** words, int Max_lines)
{
 int i, j;
 char *temp;
  
 for( i = 1 ; i < Max_lines; i++)
      {
       temp = words[i];
       j = i-1;
        while ( j >= 0 && words[j]>temp)
          {
                words[j+1]=words[j];
                j=j-1;
          }
        words[j+1] = temp;      
      }    
return words;
}
 
 
void print_lines(char**words, int Max_lines)
{
     int i;
     printf("\n\n");
     for(i = 0; i < Max_lines; i++)
           printf("%d: %s\n", i ,  words[i]);
}
