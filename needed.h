#ifndef NEEDED_H
#define NEEDED_H

typedef struct
{
    int **tab;
    int order;
} Matrix;

typedef struct
{
    int i;
    int j;
} Tuple;

Tuple *makeTuple( int i, int j );
Tuple *Sum( Tuple *_tuple1_, Tuple *_tuple2_ );
Tuple *getDirection();
Tuple *getLastPosition();
Tuple *getNextPosition( int n );

Matrix *makeMatrix( int order );

int isAlreadyPosition( Tuple *_ );
int addPosition( Tuple *_ );
int getData( int i, int j );
int getDataUsingTuple( Tuple *tup );

void load( int n );
void unload( int n );
void nextDirection();
void loadDirections();
void destroyDirections();
void destroyTuple( Tuple *_ );
void destroyMatrix( Matrix *_ );
void setData( int i, int j, int _  );
void setDataUsingTuple( Tuple *tup, int _ );

#endif