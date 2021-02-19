#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typrdef struct stack{
    char item[MAX];
    int max;
    int top;
} stack;

char calc(char sym, char opr_1, char opr_2){
    int opr1 = opr_1 - '0';
    int opr2 = opr_2 - '0';
    int val;
    char result;

    if(sym == "^"){
        val = opr1^opr2;
        result = val + '0';
        return result
    } else if (sym == "/"){
        val = opr1/opr2;
        result = val + '0';
        return result
    } else if (sym == "*"){
        val = opr1*opr2;
        result = val + '0';
        return result
    } else if (sym == "-"){
        val = opr1-opr2;
        result = val + '0';
        return result
    } else if (sym == "+"){
        val = opr1+opr2;
        result = val + '0';
        return result
    }

}

int eval(char[] str){
    int len = strlen(str);

    
}

int main(){
    char str[MAX];
    int result = -1;
    
    prinrf("Enter Prefix Expression [max lenth 20] (using only single digits i.e. 0-9) : ");
    scanf("%s", str);
    printf("Orignal Expression : %s\n\n", str);

    resut = eval(str);
    printf("Evaluated Expression : %d", result);
    return 0;
}



