
#include <stdio.h>


void print_array (int array[], int length){
    
    for (int b = 0; b<length; b++){
        
        printf ("array[%d] = %d\n", b, array[b]);
    }
    printf("\n==========\n");
}


void insertion_sort (int array[], int length){
    
    int i = 0;
    int j = 0; //Idee: Die ersten j-1 Elemente des arrays sind bereits sortiert (wenn nichts sortiert ist, j = 1)
    int key = 0;
    
    for (j = 1; j<length; j++){ //Hier wird j festgelegt
                                //Innerhalb der Schleife wird das j-te Element in die sortierte Folge eingefügt
        key = array[j];
        i = j-1;
        
        while (i>=0 && array[i]>key){
            
            array[i + 1] = array[i];
            i = i-1;
        }
        array[i+1] = key;
    }
}


int main() {

    int array[] = {15, 8, 3, 14, 7, 6, 18, 19};
    int length = sizeof(array)/sizeof(int);
    
    print_array(array, length);
    
    insertion_sort(array, length);
    
    print_array(array, length);
}
