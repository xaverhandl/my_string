#include <stdio.h>
#include <stdlib.h>

float* shift_right(float* array, int len){
    float* new_array = (float*)malloc(sizeof(float)*len);
    for(int i = 0; i<len; i++){
        new_array[i] = 0;
    }
    for(int j = 0; j<len; j++){
        new_array[j] = array[j-1];
    }
    return new_array;
}

float* shift_left(float* array, int len){
    float* new_array = (float*)malloc(sizeof(float)*len);    
    for(int i = 0; i<len; i++){
        new_array[i] = 0;
    }
    for(int j= 0; j<len-1; j++){
        new_array[j] = array[j+1];
    }    
    return new_array;
}

float* faltung(float* arr1, float* arr2, int l){
    float* new_arr1 = (float*)malloc(sizeof(float)*(3*l));
    float* new_arr2 = (float*)malloc(sizeof(float)*3*l);
    float* folded = (float*)malloc(sizeof(float)*(2*l - 1));
    float* temp = (float*)malloc(sizeof(float)*l);
    for(int i = 0; i<l; i++){
        temp[i] = arr2[i];
    }
    for(int i = 0; i<l; i++){
        arr2[i] = temp[(l-1)-i];
    }

    int counter = 0;
    for(int i = 0; i<l; i++){
        new_arr1[i] = 0;
        new_arr2[i] = 0;
        counter++;
    }
    for(int i = 0; i<l; i++){
        new_arr1[counter] = arr1[i];
        new_arr2[counter] = arr2[i];
        counter++;
    }
    for(int i= 0; i<l; i++){
        new_arr1[counter] = 0;
        new_arr2[counter] = 0;
        counter++;
    }
    for(int i = 0; i<l-1; i++){
        new_arr2 = shift_left(new_arr2,3*l);
    }

    float prod_sum = 0;
    for(int i = 0; i<2*l - 1; i++){
        for(int j = 0; j<3*l; j++){
            prod_sum = prod_sum + new_arr1[j]*new_arr2[j];
        }
        folded[i] = prod_sum;
        prod_sum = 0;
        new_arr2 = shift_right(new_arr2, 3*l);        
    }
    return folded;

}
