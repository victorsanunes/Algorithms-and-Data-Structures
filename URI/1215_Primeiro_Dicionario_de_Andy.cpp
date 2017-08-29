#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;

void replace( char &c )
{

  if( c < 65 || (c > 90 && c < 97) || c > 122) 
    c = 32;
}

int main()
{
   int i = 0;
   set< string > words;
   char word[100], c;

  while ( scanf("%c", &c ) != EOF )
  {

      replace(c);
      if( c != 32 )
      {
        word[i++] = tolower(c);
        word[i] = '\0';
        continue;
      }

      if(i)
      {
        words.insert( word );
      }

      if(words.size() == 5000)
        break;

      i = 0;
  }

  for( set<string>::iterator it = words.begin(); it != words.end(); ++it )
      cout << *it << endl;


  return 0;
}
