#include <stdio.h>
#include <string.h>

int compare_letters( int word[][26], int a, int test[] )
{
     int i;
     for( i = 0 ; i < 26 ; i++ )
          if( word[a][i] != test[i] )
              return 0;
     return 1;
}

void clear( int in[] )
{
     int i;
     for( i = 0 ; i < 26 ; i++ )
          in[i] = 0;
}

int main(void)
{
    long cases, word_cases, i, j, l;
    
    scanf("%ld", &cases);
    while( cases-- ) {
           char word[99][49] = {0}, test[49] = {0};
           int word_letters[99][26] = {0},test_letters[26] = {0};
           scanf("%ld", &word_cases);
           
           for( i = 0 ; i < word_cases ; i++ ) {
                scanf("%s", word[i]);
                
                l = strlen(word[i]);
                for( j = 0 ; j < l ; j++ ) {
                     if( word[i][j] >= 'a' && word[i][j] <= 'z' )
                         word_letters[i][ word[i][j]-'a' ]++;
                     else
                         word_letters[i][ word[i][j]-'A' ]++;
                }
           }
           // store the number of letters of these words

           while( scanf("%s", &test) && strcmp( test, "END" ) != 0 ) {
                  printf("Anagrams for: %s\n", test);
                  clear( test_letters );
                  // set all of the elements to zero
                  
                  l = strlen( test );
                  for( i = 0 ; i < l ; i++ ) {
                     if( test[i] >= 'a' && test[i] <= 'z' )
                         test_letters[ test[i]-'a' ]++;
                     else
                         test_letters[ test[i]-'A' ]++;
                  }
                  // store the number of letters of this test word
                  
                  for( i = 0, j = 0 ; i < word_cases ; i++ )
                       if( compare_letters( word_letters, i, test_letters ) ) {
                           j++;
                           printf("  %ld) %s\n", j, word[i]);
                       }
                  if( j == 0 )
                      printf("No anagrams for: %s\n", test);
           }
           if( cases )
               printf("\n");
    }
    return 0;
}
