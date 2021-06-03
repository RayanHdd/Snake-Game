#include "header.h"

char *getstr( FILE *fp ){

char *on = ( char *)malloc( sizeof(char) * 50 );
// on == order name

int i , c;
i = 0;

while ( ( c = getc(fp)) != '=' && c != '\n')
{
        if ( c == EOF )
            return NULL;

        on[i++] = c;
}


on[i] = '\0';

return on;
}


int getint( FILE *fp ){

int c , n;
n = 0;

while ( (c = getc(fp) ) != ',' && c != '\n'){
    if ( c <= '9' && c >= '0' )
        n = n*10 + c - '0';

    else if ( c != ',' && c != '\n')
        return c;
}

return n;
}


void move(  char screen[][100] , char  mv ){
    //this func return a ASCII code of a character
    if ( mv == quit )
        is_end =  1;

    if ( mv == put[0]  )
        is_put = 1 ;



    int c1,c2,check,h,point[2] ;
    c1 = c2 = 0 ;

    if ( mv == up ){
        c1 = -1 ;
        c2 = 0 ;
    }

    if ( mv == left ){
            c1 = 0 ;
            c2 = -1 ;
        }

            if ( mv == down ){
                c1 = 1 ;
                c2 = 0 ;
            }

                if ( mv == right ){
                    c1 = 0 ;
                    c2 = 1 ;
                }

             ////////////////////////////////////////////////////////////////////



                    //    printf("\nIn first if\n");



                        if(screen[p1p[0]+c1 ][ p1p[1]+c2 ]  != wall  && screen[ p1p[0]+c1 ][ p1p[1]+c2 ] != solid_block  ){
                                    if ( screen[ p1p[0]+c1 ][ p1p[1]+c2 ] == death_block  )
                                    {
                                        screen[ p1p[0] ][ p1p[1] ] = ' ';
                                        screen[ p1p[0]+c1 ][ p1p[1]+c2 ] = player_char;
                                                    //game over
                                                    is_win = -1;
                                                    return;
                                    }

                                    if ( opp[0] != 0 && screen[ p1p[0]+c1 ][ p1p[1]+c2 ] == opp[0] && opp[1] == player_char ){
                                                    is_win = -1;
                                                    return;
                                    }

                                    if ( screen[ p1p[0]+c1 ][ p1p[1]+c2 ] == move_block && ( screen[ p1p[0] + 2*c1 ][ p1p[1] + 2*c2 ] == ' ' || screen[ p1p[0] + 2*c1 ][ p1p[1] + 2*c2 ] == target ) ){
                                        screen[ p1p[0] ][ p1p[1] ] = ' ';
                                        p1p[0] += c1 ;
                                        p1p[1] += c2 ;
                                        screen[ p1p[0] ][ p1p[1] ] = player_char;
                                        screen[ p1p[0] + c1 ][ p1p[1] + c2 ] = move_block;

                                    }

                                    if ( screen[ target_pos[0] ][ target_pos[1]  ]  == object ){

                                            is_win = 1;//win
                                            return;
                                    }


                                    if ( object == player_char && screen[p1p[0] + c1 ][ p1p[1] + c2 ] == target ){
                                            screen[ p1p[0] ] [ p1p[0] ] = ' ';
                                            p1p[0] += c1;
                                            p1p[1] += c2;
                                            screen[ p1p[0] ] [ p1p[0] ] = player_char;
                                            is_win = 1;
                                            return;

                                    }




                                    if ( screen[p1p[0] + c1 ][ p1p[1] + c2 ] == ' ' || screen[p1p[0] + c1 ][ p1p[1] + c2 ] == rpoint[0] ){
                                        if ( is_put == 1  ){
                                            if ( put[2] > 0 ){
                                                screen[ p1p[0] ][ p1p[1] ] = death_block ;
                                                is_put = 0;
                                                put[2] -= 1;
                                            }
                                            else{
                                                printf("\n\t\t\t\t\t\t\t\t\t\t\t You run out of deathblock !!!\n");
                                                is_put = 0;
                                                screen[ p1p[0] ][ p1p[1] ] = ' ';
                                            }
                                        }
                                        else
                                            screen[ p1p[0] ][ p1p[1] ] = ' ';

                                        p1p[0] += c1 ;
                                        p1p[1] += c2 ;



                                        if ( screen[ p1p[0] ][ p1p[1] ] ==  rpoint[0] ){
                                                p1s += rpoint[1] ;
                                           srt_arr( point ) ;
                                           screen[ point[0] ][ point[1] ] = rpoint[0] ;
                                        }




                                    screen[ p1p[0] ][ p1p[1] ] = player_char ;

                        }



                            }//block if



}//end of move

void srt_arr(int e[]  ){
//save random number to array
int g,h ;
    while ( 1>0){
        g = random( screen_size[0] ) ;
        h = random( screen_size[1] ) ;

        if ( screen[g][h] == ' '){
            e[0] = g ;
            e[1] = h ;
            break ;
        }
    }


}

int random( int n){

return (rand()%(n-1))+1 ;
}


void save_order( FILE *orders ){

int c ;

char *on;
// on == order name

while ( 1 ){
        on = getstr(orders);

        if ( on == NULL )
            break;
        if ( strcmp( on , "rpoint") == 0 ){

            rpoint[0] = getc(orders);
            getc(orders);

            c = rpoint[1] = getint(orders);
                   if ( c == -1 )
                        break;
            rpoint[2] = getint(orders);

            free( on );
            continue;
        }


            if ( strcmp( on , "opp" ) == 0 ){
                opp[0] = getc(orders);
                getc(orders);
                opp[1] = getc(orders);
                getc(orders);
                free( on );
                continue;
            }

                if ( strcmp( on , "put" ) == 0 ){
                    put[0] = getc(orders);
                    getc(orders);

                    put[1] = getc(orders);
                   getc(orders);

                    c = put[2] = getint(orders);
                    if ( c == -1)
                        break;

                    free( on );
                    continue;
                }


                    if ( strcmp( on , "solidblock") == 0 ){
                        free( on );
                        solid_block = getc(orders);
                        getc(orders);

                        continue;

                        }


                    if ( strcmp( on , "deathblock") == 0 ){
                        free( on );
                        death_block = getc( orders );
                        continue;
                        }

                    if ( strcmp( on , "moveblock") == 0){
                       free( on );
                        move_block = getc( orders );
                        continue;
                    }

                    if ( strcmp( on , "wall" ) == 0){
                        wall = getc( orders );
                        free( on );
                        continue;
                    }

                    if ( strcmp( on , "up" ) == 0){
                        up = getc( orders );
                        free( on );
                        continue;
                }
                    if ( strcmp( on , "down") == 0){
                        free( on );
                        down = getc( orders );
                        continue;
                    }

                    if ( strcmp( on , "left") == 0){
                        free( on );
                        left = getc( orders );
                        continue;
                    }

                    if ( strcmp( on , "right" ) == 0){
                        free( on );
                        right = getc( orders );
                        continue;
                    }

                    if ( strcmp( on , "character") == 0){
                        free( on );
                        player_char = getc( orders );
                        continue;
                    }

                    if ( strcmp( on , "time" ) == 0){
                        free( on );
                        Time = getint( orders );
                        continue;
                    }

                    if ( strcmp( on , "target") == 0){
                        free( on );
                        target = getc( orders );
                        continue;
                        }

                    if ( strcmp( on , "object") == 0){
                        free( on );
                        object = getc( orders );
                            continue;
                    }

                    if ( strcmp( on , "attack") == 0){
                        free( on );
                        attack = getint( orders );
                        continue;
                    }


                    if ( strcmp( on , "raindb") == 0){
                        free( on );
                        rain_deathblock = getint( orders );
                        continue;
                    }
                    if ( strcmp( on , "Exit" ) == 0){
                            free( on );
                            quit = getc( orders );
                            continue;
                    }



                    if ( c == -1 )
                        break;




}//end of while
fclose( orders );
}

void delay(int number_of_seconds){


    int milli_seconds = 100*number_of_seconds ;


    clock_t start_time = clock() ;


    while ( clock() < start_time + milli_seconds );
}


void prints(char screen[][MAX_SCREEN_SIZE] ,int size ){


    char buff[1000000];
    setvbuf( stdout , buff , _IOFBF , sizeof(buff) );


    int i , j;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 243 );//red
    for( i = 0 ; i < screen_size[0] ; ++i){

        printf("\t\t\t\t\t\t\t\t\t");
        for ( j = 0 ; j <= screen_size[1]  ; ++j ){

            if ( screen[i][j] == rpoint[0])
                SetConsoleTextAttribute(hConsole, 14 );//yellow
            else{
                 if ( screen[i][j] == death_block )
                     SetConsoleTextAttribute(hConsole, 12 );//red
                 else if ( screen[i][j] == player_char || screen[i][j] == opp[0] || screen[i][j] == opp[1] )
                     SetConsoleTextAttribute(hConsole, 15 );//white
                 else if ( screen[i][j] == move_block )
                     SetConsoleTextAttribute(hConsole, 13 );// purple
                 else if ( screen[i][j] == solid_block || screen[i][j] == target )
                     SetConsoleTextAttribute(hConsole, 10 );// green
                 else
                    SetConsoleTextAttribute(hConsole, 3 );  //light blue
            }

            printf("%c",screen[i][j] );
        }
    }

}


void save_data( char screen[][MAX_SCREEN_SIZE] , FILE *input ){
char c ;
int j = 1 , num = 0 , i , k , h = 0 , q = 0 , y , x , w = 0 , l = 0 , state = 0 ;


  while( (c = getc(input)) != EOF ){
  if( c != '\n' && j >= 0 ){
   if( c >= '0' && c <= '9'){
   num = (10*num) + ( c - '0') ;
  }
   else

    if( (num/10.0) > 0 && j >= 0 ){
        screen_size[j] = num ;
        j-- ;
        num = 0 ;
        continue ;
    }

   }



   if( c == wall ){
    state = 1 ;
    screen[w][l++] = c ;
    }
    else{
    if( state == 1 ){
        if( c == '\n' ){
            screen[w][l] = c ;
            w++ ;
            l = 0 ;
        }
        else
         screen[w][l++] = c ;
    }

   }

    }

screen[w][l] = '\0' ;
for( i = 1 ; i < screen_size[0] ; i++ ){
    for( k = 1 ; k < screen_size[1] ; k++ ){
        if( screen[i][k] == opp[0] ){
            n_G++ ;
            G_pos[h][0] = i ;
            G_pos[h][1] = k ;

            h++;
    }

    if ( screen[i][k] == target ){
        target_pos[0] = i;
        target_pos[1] = k;

    }
    if( screen[i][k] == player_char ){
        O_pos[0] = i ;
        O_pos[1] = k ;
    }
}
}



fclose( input );
}
    /////////////////////////////////////////////////////////////




void raindb( char screen[][MAX_SCREEN_SIZE] , int n  ){


    int begin = (int)(screen_size[1] - n)/2.0;
    int end = begin + n;
    if ( raindb_count > 1 && raindb_count < screen_size[0] ){
        for ( ; begin < end ; ++begin )
            if( screen[raindb_count - 1][begin] == death_block ){
                screen[raindb_count - 1 ][begin] = ' ';

                if ( screen[raindb_count  ][begin]  == ' ' )
                    screen[raindb_count  ][begin] = death_block;

            }
        ++raindb_count;
    }

    else{
        if( raindb_count <= 1 ){
            for ( ; begin < end ; ++begin  )
                if ( screen[raindb_count][begin] == ' ' )
                    screen[raindb_count][begin] = death_block;

            ++raindb_count;
        }

        else if ( raindb_count >= screen_size[0] - 1   )
        {
            for ( ; begin < end ; ++begin )
            if( screen[raindb_count][begin] == death_block ){
                screen[raindb_count][begin] = ' ';
                if ( screen[ 1 ][begin]  = ' ' )
                    screen[ 1 ][begin] = death_block;

            }
                raindb_count = 1;
        }

    }

}

void hidecursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}


void Kill_db(void){
int aim  , X , Y , attack_pos[2] ;
//attack
attack_pos[0] = p1p[0];
attack_pos[1] = p1p[1];


            aim = getch();



            if ( aim == 72 ){
                //up
                X = -1;
                Y = 0;
            }
                if ( aim == 80 ){
                    //down
                    X = 1;
                    Y = 0;
                }
                    if ( aim == 75 ){
                        //left
                        X = 0;
                        Y = -1;
                    }
                        if ( aim == 77 ){
                            //right
                            X = 0;
                            Y = 1;
                        }

                  int i;
                  for ( i = 0 ; i < attack && screen[ attack_pos[0] + X ] [ attack_pos[1] + Y ] != wall  ; ++i ){
                        attack_pos[0] += X;
                        attack_pos[1] += Y;
                    if ( screen[ attack_pos[0] ][ attack_pos[1] ] == death_block  ){

                        screen[ attack_pos[0] ][ attack_pos[1] ] = ' ';
                            break;
                    }


                  }




}
void AI_closer( char screen[][MAX_SCREEN_SIZE] ){
int i , k ;

for( i = 1 ; i < screen_size[0] ; i++ ){
    for( k = 1 ; k < screen_size[1] ; k++ )
            if( screen[i][k] == opp[1] ){
               AI_targetPos[0] = i ;
               AI_targetPos[1] = k ;
                break ;
    }
    if( AI_targetPos[0] != 0 )
            break ;
}




}
    ////////////////////////////////////////////////////////////////

int check_p( char screen[][MAX_SCREEN_SIZE] , int a[] , int p2p[] ){
 int mv , c2, c1 ;
      //if( a[0] == p2p[0] && a[1] == p2p[1] ){
            //mv = 0 ;
        //return mv ;
      //}
     if ( a[0]  != p2p[0] && abs( a[0] - p2p[0]) > abs( a[1] - p2p[1] ) ) {
    if( a[0] < p2p[0]  )
        mv =  up ;
    else
        mv  = down ;
 }
 else{

   if( a[1] > p2p[1])
    mv =  right ;
   if( a[1] < p2p[1])
    mv = left ;

 }

    if ( mv == up ){
        c1 = -1 ;
        c2 = 0 ;
    }

    if ( mv == left ){
            c1 = 0 ;
            c2 = -1 ;
        }

            if ( mv == down ){
                c1 = 1 ;
                c2 = 0 ;
            }

                if ( mv == right ){
                    c1 = 0 ;
                    c2 = 1 ;
                }

if( screen[p2p[0]+c1][p2p[1]+c2] != ' ' ){
  if( screen[p2p[0]+c1][p2p[1]+c2] == opp[1] )
    return mv ;

   if( mv == up ){
     if( a[1] >= p2p[1] && screen[p2p[0]][p2p[1]+1] == ' ' )
         return right ;

     else if( a[1] <= p2p[1] && screen[p2p[0]][p2p[1]-1] == ' '  )
            return left ;

     else if( a[1] >= p2p[1] && screen[p2p[0]][p2p[1]+1] != ' ' && screen[p2p[0]][p2p[1]-1] == ' ' )
            return left ;
     else if( a[1] <= p2p[1] && screen[p2p[0]][p2p[1]-1] != ' ' && screen[p2p[0]][p2p[1]+1] == ' ' )
        return right ;
     else if( screen[p2p[0]][p2p[1]-1] != ' ' && screen[p2p[0]][p2p[1]+1] != ' ' && screen[p2p[0]+1][p2p[1]] == ' ' )
        return down ;

     }


  if( mv == down ){
        if( a[1] >= p2p[1] && screen[p2p[0]][p2p[1]+1] == ' '  )
         return right ;

        else if( a[1] <= p2p[1] && screen[p2p[0]][p2p[1]-1] == ' '  )
            return left ;
        else if( a[1] >= p2p[1] && screen[p2p[0]][p2p[1]+1] != ' ' && screen[p2p[0]][p2p[1]-1] == ' ' )
            return left ;
        else if( a[1] <= p2p[1] && screen[p2p[0]][p2p[1]-1] != ' ' && screen[p2p[0]][p2p[1]+1] == ' ' )
            return right ;
        else if( screen[p2p[0]][p2p[1]-1] != ' ' && screen[p2p[0]][p2p[1]+1] != ' ' && screen[p2p[0]-1][p2p[1]] == ' ' )
            return up ;

   }


   if( mv == right ){
      if( a[0] >= p2p[0] && screen[p2p[0]+1][p2p[1]] == ' '  )
            return down ;

        else if ( a[0] <= p2p[0] && screen[p2p[0]-1][p2p[1]] == ' '  )
                    return up ;
                else if( a[0] >= p2p[0] && screen[p2p[0]+1][p2p[1]] != ' ' && screen[p2p[0]-1][p2p[1]] == ' '  )
                    return up ;
                else if( a[0] <= p2p[0] && screen[p2p[0]-1][p2p[1]] != ' '  && screen[p2p[0]+1][p2p[1]] == ' '  )
                    return down ;
            else if( screen[p2p[0]-1][p2p[1]] != ' ' && screen[p2p[0]+1][p2p[1]] != ' ' && screen[p2p[0]][p2p[1]-1] == ' ')
                    return left ;

   }


   if( mv == left ){
        if( a[0] >= p2p[0] && screen[p2p[0]+1][p2p[1]] == ' '  )
            return down ;

        else if ( a[0] <= p2p[0] && screen[p2p[0]-1][p2p[1]] == ' '  )
                    return up ;
                else if( a[0] >= p2p[0] && screen[p2p[0]+1][p2p[1]] != ' ' && screen[p2p[0]-1][p2p[1]] == ' '  )
                    return up ;
                else if( a[0] <= p2p[0] && screen[p2p[0]-1][p2p[1]] != ' '  && screen[p2p[0]+1][p2p[1]] == ' '  )
                    return down ;
            else if( screen[p2p[0]-1][p2p[1]] != ' ' && screen[p2p[0]+1][p2p[1]] != ' ' && screen[p2p[0]][p2p[1]+1] == ' ')
                    return right ;


   }



    return 0 ;      //do NOT move !!!
   }

else
    return mv ;

}

            ////////////////////////////////////////////////////////////////

int move_AI( char screen[][MAX_SCREEN_SIZE] , int mv , int p2p[] ){

    int c1 , c2 ;
    c1 = c2 = 0 ;

    if ( mv == up ){
        c1 = -1 ;
        c2 = 0 ;
    }

    if ( mv == left ){
            c1 = 0 ;
            c2 = -1 ;
        }

            if ( mv == down ){
                c1 = 1 ;
                c2 = 0 ;
            }

                if ( mv == right ){
                    c1 = 0 ;
                    c2 = 1 ;
                }
                if ( mv == 0 ){
                    c1 = 0 ;
                    c2 = 0 ;
                }

             ////////////////////////////////////////////////////////////////////

                //if ( mv == up || mv == down || mv == left || mv == right ){
                      //  printf("\nIn second if\n");

                    //if( screen[p2p[0]+c1][p2p[1]+c2] == ' ' ){

                    if( screen[p2p[0]+c1][p2p[1]+c2] == opp[1] ){
                            screen[p2p[0]][p2p[1]] = ' ' ;
                            screen[p2p[0]+c1][p2p[1]+c2] = opp[0] ;
                                   return 0 ;
                    }
                        else{
                                screen[ p2p[0] ][ p2p[1] ] = ' ' ;
                                    p2p[0] += c1 ;
                                    p2p[1] += c2 ;

                                screen[ p2p[0] ][ p2p[1] ] = opp[0];
                    }







}


