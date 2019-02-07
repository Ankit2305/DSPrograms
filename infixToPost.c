#include<stdio.h>
#include<string.h>

int push(char array[], int tos, char element){
    array[++tos] = element;
    return tos;
}

int pop(char array[], int tos){
    return tos-1;
}

char peek(char array[], int tos){
    return array[tos];
}

int empty(char array[], int tos){
    if(tos==-1)
        return 1;
    return 0;
}

int type(char element){
    if((element>64 && element<91) || (element>96 && element<123))
        return 0;
    else if(element=='(')
        return 1;
    else if(element == ')')
        return 2;
    else
        return 3;
}

int precidence(char element){
    if(element == '(' || element == ')')
        return 0;
    else if(element == '+' || element == '-')
        return 1;
    else if(element == '*' || element == '/' || element == '%')
        return 2;
    else
        return 3;
}

int main(){
    char infix[50], stack[30], post[50];
    int lenI, tos = -1, i=0, lenP = 0;
    printf("Enter Infix expression : ");
    gets(infix);
    lenI = strlen(infix);
    infix[lenI++] = ')';
    infix[lenI] = '\0';
    tos = push(stack, tos, '(');
    while(!empty(stack, tos)){
        char input = infix[i++];
        int charType = type(input);
        if(charType == 0){
            post[lenP++] = input;
            post[lenP] = '\0';
        }
        else if(charType == 3){
            while(precidence(input)<=precidence(peek(stack, tos))){
                post[lenP++] = peek(stack, tos);
                post[lenP] = '\0';
                tos = pop(stack, tos);
            }
            tos = push(stack, tos, input);
        }
        else if(charType == 1){
            tos = push(stack, tos, input);
        }
        else{
            while(peek(stack, tos)!='('){
                post[lenP++] = peek(stack, tos);
                post[lenP] = '\0';
                tos = pop(stack, tos);
            }
            tos = pop(stack, tos);
        }
    }
    printf("\nPostfix Expression : ");
    puts(post);
    return 0;
}
