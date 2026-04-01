 #include<stdio.h> 
 #include<conio.h>
  int gcd ( int m , int n )
   { 
   if(n==0)
    return m ; /*Basecase*/ 
    if(m<n) 
    return gcd ( n , m ) ; /*Generalcase*/
     return gcd ( n , m%n ) ; /*Generalcase*/ }
      void main ( )
       { 
       int m , n , res ;
        clrscr ( ) ; 
        printf ( "Enter value for m & n : \n" );
         scanf( "%d%d" , &m , &n );
          res = gcd ( m , n );
           printf ( "GCD( %d ,%d ) = %d \n " , m , n , res );
           getch(); 
           } 