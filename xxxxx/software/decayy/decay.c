#include <unistd.h>   
#include <errno.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>                                                             
#include <time.h>                                                           

int main ( int argc, char *argv[] )
{
  int x,y,z;  
  srand(time(NULL));
 
    if ( argc != 3 )
    {
        printf( "usage: %s filename probability", argv[0] );
    }
    else
    {
      while(1){
	    
        FILE *file = fopen( argv[1], "r+" );
	int prob=atoi(argv[2]);
        if ( file == 0 )
        {
            printf( "Could not open file\n" );
        }
        else
        {
	  while  ( ( x = fgetc( file ) ) != EOF )
            {
	      // run through file and decay probability of reverting bit to 0
	      // for higher bits we can reduce probability
	      for (y=0;y<8;y++)
		{
		  if ((rand()%(prob*(y+1)))==1) x=x^(1<<y);
		}
	      //	      printf( "%c",x);
	      fseek(file, -1, SEEK_CUR);
	      fputc(x, file);
            }
            fclose( file );
	  }
        }
    }
}
