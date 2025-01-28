/* ---------------------- common.c ------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef NEED_MALLOC
#include <malloc.h>
#endif

	/* library functions for PL/0 compiler */
void error( char *s )  /* print error message */
{
    printf( "pl0: %s\n", s );
}

char *strsave( char *s )  /* save string s */
{
    char *p;
    
    if(( p = (char *)malloc( strlen( s ) + 1 )) == NULL ) {
	perror( "malloc" );
	exit( 1 );
    }
    return strcpy( p, s );
}

void cleararray( char *a, int s )  /* clear array a */
{
    int i;
    
    for( i=1; i<=s; i++ ) *a++ = '\0';
}
