#include <math.h> 
#include <stdio.h>
 void insertionSort ( int arr[] , int N )
  {
       int i , j , key ; 
       for ( i=1 ; i<N ; i++) 
       { 
       key = arr [ i ] ; 
       j = i - 1 ; 
       while ( j >= 0 && arr[j] > key )
        {
             arr [ j+1 ] = arr [ j ] ;
              j = j-1 ;
               } 
               arr [ j+1 ] = key ;
                } 
                } 
          int main ( ) 
          { 
          int N , i , arr [ ] = { 12,11,13,5,6 }; 
          N = sizeof(arr) / sizeof ( arr[0] ) ; 
          printf ("Unsorted array :-\ n " ); 
          for ( i = 0 ; i < N ; i++ ) 
          printf( " %d ", arr[i] ); 
          printf("\n"); 
          insertionSort ( arr , N); 
          printf ( "Sorted array: " ); 
          for( i=0 ; i<N ; i++ ) 
          printf ( "%d ", arr[i]); 
          printf("\n"); 
          return 0 ; 
          } 