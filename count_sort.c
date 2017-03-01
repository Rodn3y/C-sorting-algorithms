
//count sort macht vor allem sinn, wenn die Werte des Arrays aus einem kleinen Wertebereich stammen (wahrscheinlich das Werte mehrfach auftreten)


#include <stdio.h>
#include <stdlib.h>


void print_array (int array[], int length){
    
    for (int b = 0; b<length; b++){
        
        printf ("array[%d] = %d\n", b, array[b]);
    }
    printf("\n==========\n");
}



void count_sort (int input_array[], int output_array[], int length){
    
    int k = 0;
    
    int * count_array = calloc(16, sizeof(int)); //calloc(maximaler wert, sizeof(int))
    
    for (int j = 0; j<length; j++){
        
        count_array[input_array[j]] = count_array[input_array[j]]+1;
    }
    
    for (int j = 0; j<length; j++){
        
        printf("count_array[%d] = %d\n", j, count_array[j]);
        
    }
    
    for (int j = 0; j<=20; j++){ //hier muss bis zum maximalen wert gecounted werden
        
        for (int i = 0; i<count_array[j]; i++){
            
            output_array[k] = j;
            k++;
            
        }
        
        
    }
}


int main() {
    
    int input_array[] = {1, 3, 5, 2, 12, 14, 16, 14, 8};
    
    //int output_array[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    int output_array[9];
    
    
    int length = sizeof(input_array)/sizeof(int);
    
    print_array(input_array, length);
    
    count_sort(input_array, output_array, length);
    
    print_array(output_array, length);
}
