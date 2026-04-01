#include<stdio.h>
#include<conio.h>

int fib(int n);

 void main ( ) 
 {
     int n , i , f ;
      clrscr ();
       printf ("enter limit : \t");
       scanf ( "%d%d%d" , &n ); 
       for ( i=1 ; i<=n; i++ ) 
       printf ( "%d\t" , fib(i));
        getch(); 
        } 
        int fib ( int n )
         {
             if ( n==1 )
              return 0 ; 
              else if ( n==2 )
              return 1 ;
               else return fib ( n-1 ) + fib ( n-2 ) ; 
               } 