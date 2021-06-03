
#include "header.h"
#include "functions.c"




int main(){


    system("MODE 1920,1920");

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 243 );

 printf(" ");
    system("CLS");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Welcome to our console\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tDeveloped by Amir Masoud Heydari And Mohammad Eshrati\n");
    delay(45);//4.5 second




    system("CLS");
    raindb_count = 1;
    GAME:
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Name of Game File : ");
    char *Gfile_name = getstr( stdin );

    MAP:
    printf("\n\t\t\t\t\t\t\t\t\t Name of Map File : ");
    char *Mfile_name = getstr( stdin );


     FILE *game = fopen( Gfile_name , "r" );
    if ( game == 0 ){
            printf("\n\t\t\t\t\t\t\t\t\tThere is no file with this name : %s\n" , Gfile_name );
            getch();
        system("CLS");
        goto GAME;
    }


    FILE *map = fopen( Mfile_name , "r" );

    if ( map == 0 ){
        printf("\n\t\t\t\t\t\t\t\t\tThere is no file with this name : %s\n" , Mfile_name );
        getch();
        system("CLS");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        goto MAP;
    }
    save_order( game );
    save_data( screen ,  map );
     //int k;
    is_vict = 1;



    system( "CLS" );

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t    Input your name : ");
        p1n = getstr( stdin );


    system( "CLS" );

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tYour keys : %c(up), %c(down), %c(right), %c(left)\n\n\t\t\t\t\t\t\t\t%c(quit the game)\n", up , down , right , left , quit );
    printf("\n\t\t\t\t\t\t\t\tEsc( Pause )\n");
    if ( put[0] != 0 )
        printf("\n\t\t\t\t\t\t\t\t%c( put a deatblock )\n" , put[0] );
    if ( attack != 0 )
        printf("\n\t\t\t\t\t\t\t\t press arrow keys to attack \n");
    printf("\n\t\t\t\t\t\t\t\tPress any key to enter the game...\n");
    getch();
    system( "CLS" );







    int  mv1 , i , mv2 ;





    p1p[0] = O_pos[0];
    p1p[1] = O_pos[1];

     int second = Time*10;

          int j;
                //printf("%s" , screen[0] );




    srand( time(0) );
    //////////////////////////placing point////////////////////////

    if ( rpoint[1] != 0 ){
        int i , point[2];
        i = 0;
        while ( i < rpoint[2]  ){
            srt_arr( point );
            screen[ point[0] ][ point[1] ] = rpoint[0];
            ++i;
        }

    }

    char check;

//SetConsoleTextAttribute(hConsole, 3 );
    raindb_count = 1;
int k , pause ;

    for( ; ;  ){

                if  ( rain_deathblock != 0 )
                    raindb( screen , rain_deathblock );


                hidecursor();

                                if ( second <= 0 && Time != 0 ){
                                   if ( rain_deathblock != 0 || ( rpoint[0] != 0 && object == player_char ) )
                                        is_win = 1;

                                    break;
                                }


                                system("CLS") ;

                                prints( screen , screen_size[0] );

                                if ( rpoint[0] != 0 && Time != 0 )
                                    printf("\n\n\t\t\t\t\t\t\t\t\t\t%s score : %d\n\t\t\t\t\t\t\t\t\t\tRemaining seconds : %d.%d\n",p1n,p1s,second/10,second%10) ;

                                else{

                                    if ( Time != 0  )
                                        printf("\n\n\t\t\t\t\t\t\t\t  Remaining seconds : %d.%d\n",second/10,second%10) ;

                                    else if ( rpoint[0] != 0  )
                                        printf("\n\n\t\t\t\t\t\t\t\t\t  %s score : %d",p1n,p1s) ;
                                }


                            if ( kbhit() )
                                check = getch() ;



                            if ( check == 27 ){
                                PAUSE:    // '27'  == Esc    //pause
                                system("CLS");
                                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPause\n\t\t\t\t\t\t\t\t\tPress Esc to continue");
                                pause = getch();
                                if ( pause != 27 )
                                    goto PAUSE;
                                else
                                    check = 1;
                                    }

                            if ( mv1 == quit ){
                                system("CLS") ;
                                break;
                            }


                            if ( opp[0] != 0 ){

                             AI_closer( screen ) ;
                                    for( k = 0 ; k < n_G ; k++ ){
                                        mv2 = check_p( screen , AI_targetPos , G_pos[k] ) ;
                                        is_vict = move_AI( screen , mv2 , G_pos[k] ) ;
                                        if( is_vict == 0 )
                                             break ;

                                    }


                                if( is_vict == 0 )
                                    break ;
                            }
                              if ( check == up || check == down || check == left || check == right || check == quit || check == put[0] )
                                        mv1 = check;

                                else if ( abs(check) == 32  && attack != 0){

                                            Kill_db();
                                            check = 1 ;
                                }


                                 move( screen , mv1 ) ;

                                 if( opp[1] == player_char  ){
                                    AI_targetPos[0] = p1p[0];
                                    AI_targetPos[1] = p1p[1];
                                 }



                                if ( is_win == 1 || is_win == -1 || is_end == 1 )
                                    break;



                                delay( 0.001 );



                        if( Time != 0)
                            second -= 1;// decrease 0.3 second



    }//for

    system("CLS");
    if ( is_win == -1 || is_vict == 0 ){
         SetConsoleTextAttribute(hConsole, 252 );//red
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tYou lose !!!\n");
    }

    else if( is_win == 1  ) {
         SetConsoleTextAttribute(hConsole, 250 );
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tYou win\n");

    }
    else{
        if ( second == 0 && Time != 0 && rpoint[0] == 0)
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t     End " );

        else if ( rpoint[0] != 0 )
            printf("\n\t\t\t\t\t\t\t\t\t      Your score : %d" , p1s );
        else
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t     End " );
    }

    delay(40);//wait 4.0 second


free( Gfile_name);
free( Mfile_name);
free( p1n );

return 0;
}




