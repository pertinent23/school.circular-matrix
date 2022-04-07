#include <stdio.h>
#include <stdlib.h>
#include "needed.h"

void run( int n ) 
{
    int i = 0;
    Tuple *pos;
            do {
                i++;
                pos = getNextPosition( n );
                    if ( pos != NULL )
                        setDataUsingTuple( pos, i );
            } while ( pos != NULL );
        
}

void showMatrix( int n ) 
{
    int 
        i = 0, j = 0;
            for ( ; i < n ; i++ ) {
                printf( "\n" );
                j = 0;
                for( ; j < n; j++ )
                    printf( "\t_______" );
                
                printf( "\n\n" );
                j = 0;
                for( ; j < n; j++ )
                    printf( "\t| %d |", getData( i, j ) );
            }
        printf( "\n" );
        j = 0;
        for( ; j < n; j++ )
            printf( "\t_______" );
    printf( "\n\n" );
}

void launch( int _ ) 
{
    int order;
        system( "clear" );
            if ( _ != 0 )
                printf( "\n>>> Le nombre doit etre strictement positif!! \n\n" );
                    printf( "\n>>> Veillez entrer l'ordre de la matrice: " );
                    printf( "\n>>> " );
            scanf( "%d", &order );
        if ( order > 0 ) {
            load( order );
                        run( order );
                            showMatrix( order );
                    unload( order );
            printf( "\n" );
        } else {
            launch( 1 );
        }
}

int main() 
{
        launch( 0 );
    return 0;
}