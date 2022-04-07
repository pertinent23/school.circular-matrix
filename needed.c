#include <stdio.h>
#include <stdlib.h>
#include "needed.h"

/**
    * @brief 
    * the last direction during the
    * making up of the matrix
*/
int direction = 0;

/**
    * @brief 
    * the size of the array position
*/
int numPosition = 0;

/**
    * @brief 
    * this matrix 
    * will be use in 
    * all the progamm
*/
Matrix *MAIN_MATRIX;

/**
    * @brief 
    * this, is the list of direction
    * in the order to roam the whole
    * matrix in a circular manner
*/
Tuple **directions;

/**
    * @brief 
    * 
    * List of position attent 
    * by the algorithm
*/
Tuple **positions;

Tuple *makeTuple( int i, int j ) {
    /**
        * @brief 
        *  this function will be 
        * use to create a new tuble 
        * ( 1, 1 )
    */
    Tuple *result;
        result = ( Tuple* ) malloc( sizeof( Tuple ) );
            result->i = i;
            result->j = j;
    return result; 
}

Tuple *getNextPosition( int n ) {
    Tuple *pos;
        if ( numPosition > 0 ) {
            pos = Sum( getLastPosition(), getDirection() );
            if ( numPosition == ( n * n ) ) {
                return NULL;
            } else {
                if ( pos->i > n || pos->j > n || pos->i < 1 || pos->j < 1 || isAlreadyPosition( pos ) ) {
                        nextDirection();
                        destroyTuple( pos );
                    return getNextPosition( n );
                }
                    addPosition( pos );
                return pos;
            }
        }
        pos = makeTuple( 1, 1 );
        addPosition( pos );
    return pos;
}

Tuple *Sum( Tuple *tuple1, Tuple *tuple2 )  {
    /**
        * @brief 
        * this function will be use
        * to add a tuple in a other one
    */
    Tuple *final;
        final = makeTuple( tuple1->i + tuple2->i, tuple1->j + tuple2->j );
    return final;
}

int isAlreadyPosition( Tuple *_ ) {
    if ( numPosition == 0 )
        return 0;
        int i = 0;
        Tuple *val;
            for ( ; i < numPosition; i++ ) {
                val = positions[ i ];
                    if ( val->i == _->i && val->j == _->j )
                        return 1;
            }
    return 0;
}

int addPosition( Tuple *_ ) {
        positions[ numPosition ] = _;
    return ++numPosition;
}

Tuple *getLastPosition() {
    return numPosition > 0 ? positions[ numPosition - 1 ] : NULL;
}

void nextDirection() {
    direction = direction + 1 > 3 ? 0 : ++direction;
}

Tuple *getDirection() {
    return directions[ direction ];
}

Matrix *makeMatrix( int order ) {
    /**
        * @brief 
        *  this function will be use to create
        * a new matrix
    */
    Matrix *mat;
    int i = 0;
        mat = ( Matrix * ) malloc( sizeof( Matrix ) );
            mat->order = order;
            mat->tab = malloc( sizeof( int * ) * order );
                for( ; i < order; i++ )
                    mat->tab[ i ] = malloc( sizeof( int ) * order );
    return mat;
}

int getData( int i, int j ) {
    return MAIN_MATRIX->tab[ i ][ j ];
}

int getDataUsingTuple( Tuple *tup ) {
    return getData( tup->i, tup->j );
}

void setData( int i, int j, int _  ) {
    MAIN_MATRIX->tab[ i - 1 ][ j - 1 ] = _;
}

void setDataUsingTuple( Tuple *tup, int _ ) {
    setData( tup->i, tup->j, _ );
}

void loadDirections() {
    directions = ( Tuple ** ) malloc( sizeof( Tuple * ) * 4 );
    directions[ 0 ] = makeTuple( 0, 1 );
    directions[ 1 ] = makeTuple( -1, 0 );
    directions[ 2 ] = makeTuple( 0, -1 );
    directions[ 3 ] = makeTuple( 1, 0 );
};

void load( int n ) {
    MAIN_MATRIX = makeMatrix( n );
    loadDirections();
    positions =  ( Tuple ** ) malloc( sizeof( Tuple ** ) * ( n * n ) );
}

void unload( int n ) {
    int i = 0;
        for( ; i < n * n; i++ )
            destroyTuple( positions[ i ] );
    destroyMatrix( MAIN_MATRIX );
    destroyDirections();
    free( positions );
}

void destroyDirections() {
    free( directions[ 0 ] );
    free( directions[ 1 ] );
    free( directions[ 2 ] );
    free( directions[ 3 ] );
    free( directions );
};


void destroyTuple( Tuple *_ ) {
    free( _ );
}

void destroyMatrix( Matrix *_ ) {
    free( _ );
}