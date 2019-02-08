#include<stdio.h>
#include<string.h>
#include<math.h>

void view(float array[], int tos){
    int i;
    printf("Stack : ");
    for(i=0;i<=tos;i++)
        printf("%.2f ", array[i]);
    printf("\n");
}

int push(float array[], int tos, float element){
    array[++tos] = element;
    return tos;
}

int pop(float array[], int tos){
    return tos-1;
}

float peek(float array[], int tos){
    return array[tos];
}

int empty(float array[], int tos){
    if(tos==-1)
        return 1;
    return 0;
}

int type(char element){
    if(element>47 && element<58)
        return 0;
    else if(element == ' ')
        return 1;
    return 2;
}

int stringToInt(int num, char element){
    int newNum = element-48;
    return 10*num+newNum;
}

float evaluate(float a, float b, char element){
    float result;
    switch(element){
    case '+':
        result = a+b;
        break;
    case '-':
        result = a-b;
        break;
    case '*':
        result = a*b;
        break;
    case '/':
        result = a/b;
        break;
    case '^':
        result = pow(a,b);
        break;
    }
    return result;
}

int main(){
    char postfix[50];
    int tos=-1, len, i=0, ptype;
    float stack[25], result, num;
    printf("Enter Postfix expression : ");
    gets(postfix);
    len = strlen(postfix);
    postfix[len] = '#';
    postfix[++len] = '\0';
    num=0;
    while(postfix[i]!='#'){
        char input = postfix[i];
        if(type(input) == 0){
            num=stringToInt(num, input);
            ptype = 0;
        }
        else if(type(input) == 1){
            if(ptype==0){
                tos = push(stack, tos, num);
                view(stack, tos);
                num=0;
            }
            ptype = 1;
        }
        else{
            float b = peek(stack, tos);
            tos = pop(stack, tos);
            float a = peek(stack, tos);
            tos = pop(stack, tos);
            num = evaluate(a,b,input);
            tos = push(stack, tos, num);
            view(stack, tos);
            num = 0;
            ptype = 2;
        }
        i++;
    }
    result = stack[0];
    printf("\nResult : %.2f", result);

    return 0;
}
