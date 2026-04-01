#include <stdio.h> 
long int multNmbrs ( int n ); 
int main () 
{ 
int n; 
printf ( "Enter a positive integer: " );
 scanf( "%d" , &n ); 
 printf( "Factorial of %d = % ld " , n , multNmbrs ( n ) ); 
 return 0; 
 }
  long int multNmbrs ( int n ) 
  {
       if ( n>=1 ) 
       return n*multNmbrs ( n-1 ) ; 
       else
        return 1;
         } 