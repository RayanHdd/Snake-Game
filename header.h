
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_SCREEN_SIZE 100

int seed[100][100];
char screen[1000][100];


int rpoint[3];// rpoint[0] == point character  | rpoint[1] == each point score | rpoint[2] == number of points
int opp[2];// opp[0] == competitor character | opp[1] == competitor target
int put[3];// put[0] == put key | put[1] == put object | put[2] == put objetc limit number in each game
int p1p[2];


char target , solid_block , death_block , move_block , up , down , left , right , player_char  ;
char   object ,  quit , wall , is_put , *p1n;
int Time , attack , rain_deathblock , screen_size[2] , p1s , is_vict , target_pos[2];
int n_G  ,  O_pos[2] , G_pos[10][2] , AI_targetPos[2]  , raindb_count , is_win , is_end , pre_move;





char *getstr( FILE *fp );
int getint( FILE *fp );
void srt_arr(int e[]  );
void move( char screen[][100] , char  mv  );
void save_order( FILE *orders );
void delay(int number_of_seconds);
void prints(char screen[][MAX_SCREEN_SIZE] , int a );
void save_data( char screen[][MAX_SCREEN_SIZE]  , FILE *map );
int move_AI( char screen[][MAX_SCREEN_SIZE] , int mv  , int p2p[]);
int check_p( char screen[][MAX_SCREEN_SIZE] , int a[] , int p2p[] );
void AI_closer( char screen[][MAX_SCREEN_SIZE] );
int random( int n);
void hidecursor( void );
void Kill_db( void );
void raindb( char screen[][MAX_SCREEN_SIZE] , int n  );
