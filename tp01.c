#include<stdio.h>
#include<stdlib.h>

typedef struct dict Tdict;
typedef struct node Tnode;

/*
 * Structure to represent a dictionary, wich may be used to transiction
 *  function of AFD.
 *      - char symbol: symbol to consume
 *      - Tnode *next: next state after consume symbol 
 */
struct dict {
    char symbol;
    Tnode *next;    
};

/*
 *  Structure to represent the AFD state, wich have three atributes
 *      - name: state name. eg: A, B, C ...
 *      - status: it represents wheter the state is final, initial, none
 *      - transitions; transition function  
 */
struct node {
    char name;      
    char status; 
    Tdict *transitions;
};

//####################### Functions Signatures #######################

void read_states(Tnode *states, int *nstates);
void read_alphabet(char *alphabet, int *nalphabet);
void read_transitions();
void print(Tnode *states, int nstates, char *alphabet,int nalphabet);

//########################## Functions Body ##########################
int main()
{
    // main variables
    Tnode *states;
    char *alphabet;
    int nstates,nalphabet;

    // read states
    states = (Tnode *) malloc (sizeof(Tnode));   
    read_states(states, &nstates);    

    // read alphabet
    alphabet = (char *) malloc (sizeof(char));
    read_alphabet(alphabet, &nalphabet);    

    print(states, nstates, alphabet, nalphabet);

    // TODO: read transitions
    read_transitions();
    
    // TODO: read initial and final states
    
    // TODO: read words to recognize
}

void print(Tnode *states, int nstates, char *alphabet,int nalphabet)
{
    int i;

    // print
    printf("\n%d states:\n", nstates);
    for(i=0;i<nstates;i++)
        printf("\t%d : %c\n", i, states[i].name);

    printf("\n%d symbols in alphabet: %s\n", nalphabet, alphabet);
}

void read_transitions()
{
    char symbol;    
    // loop to read until find '#'
    
    printf("\ntransitions\n");
    do
    {
        scanf(" %c",&symbol);
        if (symbol == '#')
            break;
            
        printf(" %c",symbol);
        // loop to read until find ';'
        do
        {
            scanf(" %c",&symbol);
            if (symbol == ';')
                break;
            printf(" %c",symbol);
        }while(1);
        printf("\n");
    }while(1);
}

void read_alphabet(char *alphabet, int *nalphabet)
{
    char symbol;    
    *nalphabet = 0;
    do{
        scanf(" %c",&symbol);
        if (symbol == ';')
            break;
        (*nalphabet)++;
        alphabet = (char *) realloc (alphabet, (*nalphabet)*sizeof(char));
        alphabet[(*nalphabet)-1] = symbol;
    }
    while(1);
}

void read_states(Tnode *states, int *nstates)
{
    char symbol;    
    *nstates = 0;
    do{
        scanf(" %c",&symbol);
        if (symbol == ';')
            break;
        (*nstates)++;
        states = (Tnode *) realloc (states, (*nstates)*sizeof(Tnode));
        states[(*nstates)-1].name = symbol;
    }
    while(1);
}

