#include<stdio.h>
#include<conio.h>

#define MAX 100

//states
void A(char);
void B(char);
void C(char);
void D(char);

//initial state
char state = 'A';

void main(){
    //input string
    char string[MAX];
    int i;

    printf("\nDFA accepting strings that contains 'aba' as substring");
    printf("\nInput symbols: (a,b)");

    printf("\nEnter a string: ");
    scanf("%s", string);

    //traversing through string
    for(i = 0; string[i] != '\0'; i++){
        switch(state){
            case 'A':
                A(string[i]);
                break;
            case 'B':
                B(string[i]);
                break;
            case 'C':
                C(string[i]);
                break;
            case 'D':
                D(string[i]);
                break;
        }
    }

    //check if current state is final state or not
    if(state == 'D'){
        printf("\nString is accepted.");
    }
    else{
        printf("\nString is not accepted.");
    }
}


//state transitions
void A(char c){
    if(c == 'a') state = 'B';
}

void B(char c){
    if(c == 'b') state = 'C';
}

void C(char c){
    if(c == 'a') state = 'D';
    else if(c == 'b') state = 'A';
}

void D(char c){
    return;
}