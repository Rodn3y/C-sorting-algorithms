
#include <stdio.h>


void print_array (int array[], int length){
    
    for (int b = 0; b<length; b++){
        
        printf ("array[%d] = %d\n", b, array[b]);
    }
    printf("\n==========\n");
}


void swap(int array[], int i){
    
    int h = array[i];
    array[i] = array[i+1];
    array[i+1] = h;
    
}


void bubble_sort (int array[], int length){
    
    int j;
    int i;
    
    //Die größten Elemente steigen auf (bubblen), wie Luftblasen, die zu ihrer
    //richtigen Position aufsteigen
    
    for (j = (length -1); j >=0; j--){ //Die letzten Elemente von j bis n sind sortiert (zu Beginn j= n-1)
        
        for (i = 0; i <= j; i++){ //unsortierter Teil verkleinert sich mit jedem Durchlauf (äusere schleife) um 1
            
            if (array[i] > array [i+1]){
                
                swap(array, i);
            }
        }
    }
}


int main() {
    
    int array[] = {15, 8, 3, 14, 7, 6, 14, 18, 19, 2};
    int length = sizeof(array)/sizeof(int);
    
    print_array(array, length);
    
    bubble_sort(array, length);
    
    print_array(array, length);
}
