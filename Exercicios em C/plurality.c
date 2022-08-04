#include <cs50.h>
#include <stdio.h>
#include <string.h>
#define MAX 9
typedef struct{
    string name;
    int votes;
}
candidato;
candidato candidatos[MAX];
int candidato_count;
bool vote(string name);
void print_winner(void);
int main(int argc, string argv[]){
    if (argc < 2){
        printf("Numero mínimo de dois candidatos.\n");
        return 1;
    }
    candidato_count = argc - 1;
    if (candidato_count > MAX){
        printf("Número máximo de candidatos é %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidato_count; i++){
        candidatos[i].name = argv[i + 1];
        candidatos[i].votes = 0;
    }
    int voter_count = get_int("Número de eleitores: ");
    for (int i = 0; i < voter_count; i++){
        string name = get_string("Voto: ");
        if (!vote(name)){
           printf("Voto inválido.\n");
        }
    }
    print_winner();
}
bool vote(string name){
    for (int i = 0; i < candidato_count; i++){
        if (strcmp(candidatos[i].name, name) == 0){
            candidatos[i].votes++;
            return true;
        }
    }
    return false;
}
void print_winner(void){
    int maximum_vote = 0;
    for (int i = 0; i < candidato_count; i++){
        if (candidatos[i].votes > maximum_vote){
            maximum_vote = candidatos[i].votes;
        }
    }
    for (int i = 0; i < candidato_count; i++){
        if (candidatos[i].votes == maximum_vote){
            printf("%s\n", candidatos[i].name);
        }
    }
return 0;
}