// #include <stdio.h>

#define MAX 10

void recur(char* src, char* des){
    
    // exit condition
    if(*src == '\0'){
        *des = '\0';
        return;
    }

    *des = *src;
    src++;
    des++;

    // recusion statement
    recur(src, des);
}

void isPalin(char str[], int start, int end, int* flag){
    // exit condition
    if (start == end-1 || start == end){
        return;
    } else if (str[start] != str[end]){
        *flag = 0;
        return;
    } else {
        start++;
        end--;
        isPalin(str, start, end, flag);
    }
}

int main(){
    char str[MAX], copy[MAX];
    int* flag = 1;

    printf("Enter String (also to check for Palindrome): ");
    scanf("%s", str);

    recur(str, copy);

    printf("\nThe Orignal String is : %s", str);
    printf("\nThe Copied String is : %s", copy);

    isPalin(str, 0, strlen(str)-1, flag);

    if(*flag == 0){
        printf("\n\n### The string is not a Plaindrome ###");
    } else {
        printf("\n\n### The string is not a Plaindrome ###");
    }
}