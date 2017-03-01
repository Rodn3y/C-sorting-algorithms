
#include <stdio.h>


void print_array (int array[], int length){
    
    for (int b = 0; b<length; b++){
        
        printf ("array[%d] = %d\n", b, array[b]);
    }
    printf("\n==========\n");
}

void swap(int array[], int min, int j){
    
    int h = array[min];
    array[min] = array[j];
    array[j] = h;
    
}

void selection_sort (int array[], int length){
    
    int i = 0;
    int j = 0; //Idee: Die ersten j-1 Elemente des arrays sind bereits sortiert (wenn nichts sortiert ist, j = 1)
    int min;
    
    //Innerhalb eines Schleifendurchlaufs wird das j-kleineste Element
    //(entspricht dem kleinste aus dem Rest) an die sortierte Folge „angehängt“
    
    for (j = 0; j<(length-1); j++){
        
        min = j;
        
        for (i = (j+1); i<length; i++){
            
            if (array[i] < array[min]){
                
                min = i;
            }
        }
        
        swap(array, min, j);
        
    }
}


int main() {
    
    int array[] = {15, 8, 3, 14, 7, 6, 18, 19, 2};
    int length = sizeof(array)/sizeof(int);
    
    printf("length = %d\n", length);
    
    print_array(array, length);
    
    selection_sort(array, length);
    
    print_array(array, length);
}
