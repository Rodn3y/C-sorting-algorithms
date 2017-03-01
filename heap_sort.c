//non-recursiv heapsort


#include <stdio.h>

void print_array(int array[], int length){
    
    for (int i = 0; i <length; i++){
        
        printf("%d ", array[i]);
        
    }
    
    printf("\n");
    
}

void heapify(int array[], int i, int array_size) {
    
    int maxChild = i * 2 + 1;
    
    // Find the biggest child
    if(maxChild < array_size) {
        int otherChild = maxChild + 1;
        // Reversed for stability
        maxChild = (array[otherChild] > array[maxChild])?otherChild:maxChild;
    } else {
        // Don't overflow
        if(maxChild > array_size) return;
    }
    
    // If we have the correct ordering, we are done.
    if(array[i] >= array[maxChild]) return;
    
    // Swap
    int temp = array[i];
    array[i] = array[maxChild];
    array[maxChild] = temp;
    
    // Tail queue recursion. Will be compiled as a loop with correct compiler switches.
    heapify(array, maxChild, array_size);
}


void heapSort(int array[], int length) {
    
    int i;
    int temp;
    
    for (i = (length / 2); i >= 0; i--) {
        heapify(array, i, length - 1);
        //print_array(array, length);
    }
    
    for (i = length-1; i >= 1; i--) {
        // Swap
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        
        heapify(array, 0, i-1);
        //print_array(array, length);

    }
}


int main (){
    
    int array[]= {24, 0, 4, 2, 4, 6, 7, 8, 6, 3};
    
    int length = sizeof(array)/sizeof(int);
    
    print_array(array, length);
    
    heapSort(array, length);
    
    print_array(array, length);
    
}
