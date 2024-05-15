//my own string library by Xaver Handl

#include <stdio.h>
#include <stdlib.h>
//vergleicht zwei strings ob sie identisch sind, gibt 0 oder 1 zurück
int comparestr(char*s1, char*s2){
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
    }
    return 1;
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
    int l_sub = len(sub_string);
    int l_s = len(string);
    char sub_array[l_sub];
    char string_array[l_s];
    for(int i=0; i<l_sub;i++){
        sub_array[i] = sub_string[i];
    }
    for(int j= 0; j<l_s; j++){
        string_array[j] = string[j];
    }
    char compare_string[l_sub];
    for(int x = 0; x<l_sub; x++){
        compare_string[x] = '0';
    }
    int start = 0;
    int end = l_sub;
    int is_true = 1;
    while(end != l_s){
        for(int k = start; k<end; k++){
            compare_string[k] = string[k];
        }
        for(int k1 = 0; k1<l_sub; k1++){
            if(compare_string[k1] != sub_array[k1]){
                is_true = 0;
            }

        }
        start++;
        end++;

    }
    return is_true;
}
int main(void){
    char* s1 = "peter_maffei_123";
    char* s2 = "maffei";
    int l1 = len(s1);
    int l2 = len(s2);
    int n = 5;
    int is_true = findstr(s1,s2);
    printf("%d",is_true);

    }

