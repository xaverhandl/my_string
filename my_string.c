

//my own string library by Xaver Handl

#include <stdio.h>
#include <stdlib.h>
#include "faltung.h"
#include "faltung.c"
//Für Mathe-Zwecke ist hier eine pow funktion:
int mypow(int base, int exponent){
    int ret_val = 1;
    for(int i = 0; i<exponent; i++){
        ret_val = ret_val * base;
    }
    return ret_val;
}

// my own string library by Xaver Handl

float negativemypow(int base, int exponent) {
  float ret_val = 1;
  for (int i = 0; i < exponent; i++) {
    ret_val = ret_val / base;
  }
  return ret_val;
}

//Bestimmt länge von einem string
int len(char* string){
    int l = 0;
    while(*string != '\0'){
        *string++;
        l++;

    }
    return l;
}
//vergleicht zwei strings ob sie identisch sind, gibt 0 oder 1 zurück
int comparestr(char* s1, char* s2){
    int l1 = len(s1);
    int l2 = len(s2);
    if(l1 != l2){
        return 0;
    }
    else{
        for(int i = 0; i < l1; i++){
            if(s1[i] != s2[i]){
                return 0;
            }
        }
        return 1;
    }

}

//Addiere zwei string zu einem gesamt string
char* addstr(char* s1, char* s2){
    int l1 = 0;
    int l2 = 0;
    char* p1 = s1;
    char* p2 = s2;
    while(*p1 != '\0'){
        *p1++;
        l1++;
    }
    while(*p2 != '\0'){
        *p2 ++;
        l2++;
    }
    char* add_string = (char*)malloc(sizeof(char)*(l1+l2));
    for(int i = 0; i<l1; i++){
        add_string[i] = s1[i];
    }
    int counter = 0;
    for(int j = l1; j<(l1+l2); j++){
        add_string[j] = s2[counter];
        counter++;
    }
    return add_string;
}
//Multipliziere einen string, das er sich n mal wiederholt
char* multiplystr(char* string, int n){
    int l = len(string);
    char* mult_string = (char*)malloc(sizeof(char)*l*n);
    int counter = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<l; j++){
            mult_string[counter] = string[j];
            counter++;

        }
    }
    return mult_string;
}
//Finde Substring in String (ist der substring da oder nicht?) returnt 1 wenn er da ist, 0 wenn nicht
int findstr(char* string, char* sub_string){
    int l1 = len(string);
    int l2 = len(sub_string);
    int window_start = 0;
    int window_end = l2;
    char comp_string[l2];
    while(window_end != l1){
        int counter = 0;
        for(int i = window_start; i<window_end; i++){
            comp_string[counter] = string[i];
            counter++;
        }
        if(comparestr(comp_string,sub_string) == 1){
            return 1;
        }
        window_start++;
        window_end++;
    }
    return 0; 

}
//Wandelt float-char in float umwandeln z.B: "3830.83" ---> 3830.83
float convertfloatstr(char* float_string){
    int l = len(float_string);
    int breakpoint = 0;
    for(int i = 0; i<l; i++){
        if(float_string[i] == '.'){
            break;
        }
        breakpoint++;
    }
    int curr_num = 0;
    int n = breakpoint-1;
    for(int j = 0; j<breakpoint; j++){
        curr_num = curr_num + ((int)float_string[j] - '0')*mypow(10,n);
        n--;
    }
    float curr_float = 0;
    int n2 = 1;
    for(int k = breakpoint+1; k< l; k++){
        curr_float = curr_float + ((int)float_string[k] - '0')*negativemypow(10,n2);
        n2++;
    }
    
    return curr_num + curr_float;
}
char* reversestr(char* string){
    int l = len(string);
    char* reverse_string = (char*)malloc(sizeof(char)*l);
    for(int i = 0; i<l; i++){
        printf("%d",i);
        reverse_string[i] = string[(l-1)-i];
    }
    return reverse_string;

}
int main(void){
    float* my_array = (float*)malloc(sizeof(float)*10);
    float* my_array2 = (float*)malloc(sizeof(float)*10);
    for(int i = 0; i<10; i++){
        my_array[i] = i;
        my_array2[i] = i;
    }
    float* folded = (float*)malloc(sizeof(float)*(2*10 - 1));
    folded = faltung(my_array, my_array2, 10);
    printf("\n");
    for(int i = 0; i< 20; i++){
        printf("%.1f ", folded[i]);
    }

    }


