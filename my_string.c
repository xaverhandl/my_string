//my own string library by Xaver Handl

#include <stdio.h>
#include <stdlib.h>
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
int main(void){
    FILE* fp = fopen("test_string.txt","r");
    char buffer[3948271953+1];
    size_t read_size = fread(buffer, 1, 3948271953, fp);
    char* s2 = "deorm";
    int l2 = len(s2);
    int n = 5;
    int is_true = findstr(buffer,s2);
    printf("%d",is_true);

    }

