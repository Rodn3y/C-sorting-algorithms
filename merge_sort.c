//Teile Eingabe auf mehrere Teile auf, löse Problem rekursiv auf den Teilen und füge Teillösung zu einer Gesamtlösung zusammen

#include <stdio.h>


void print (int a[], int max ){
    
    for(int i = 0; i < max; i++){
        
        printf("%d ", a[i]);
    
    }
    
    printf("\n");
    
}


void merging(int a[], int b[], int min, int mid, int max) {
    
    int l1, l2, i;
    
    for(l1 = min, l2 = mid + 1, i = min; l1 <= mid && l2 <= max; i++) {
        if(a[l1] <= a[l2])
            b[i] = a[l1++];
        else
            b[i] = a[l2++];
    }
    
    while(l1 <= mid)
        b[i++] = a[l1++];
    
    while(l2 <= max)
        b[i++] = a[l2++];
    
    for(i = min; i <= max; i++)
        a[i] = b[i];
}


void sort(int a[], int b[], int min, int max) {
    int mid;
    
    if(min < max) {
        mid = (min + max) / 2;
        sort(a, b, min, mid);
        sort(a, b, mid+1, max);
        merging(a, b, min, mid, max);
    } else { 
        return;
    }
}

int main() {
    
    int a[] = { 3, 2, 5, 7, 4, 543, 35, 32, 7, 45, 8, 9, 23, 5, 6, 9};

    int min = 0;
    int max = sizeof(a)/sizeof(int);
    
    int b[max];
    
    print(a, max);
    
    sort(a, b, min, max);
    
    print(a, max);
}


