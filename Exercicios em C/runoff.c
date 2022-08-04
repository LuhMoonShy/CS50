#include <string.h>
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9
int preferences[MAX_VOTERS][MAX_CANDIDATES];
typedef struct{
string name;
int votes;
bool eliminated;
}
candidate;
candidate candidates[MAX_CANDIDATES];
int voter_count;
int candidate_count;
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);
int main(int argc, string argv[]){
    if (argc < 2){
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES){
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++){
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }
    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS){
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }
    for (int i = 0; i < voter_count; i++){
        for (int j = 0; j < candidate_count; j++){
            string name = get_string("Rank %i: ", j + 1);
            if (!vote(i, j, name)){
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }
    while (true){
        tabulate();
        bool won = print_winner();
        if (won){
            break;
        }
        int min = find_min();
        bool tie = is_tie(min);
        if (!tie){
            for (int i = 0; i < candidate_count; i++){
                if (!candidates[i].eliminated){
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }
        eliminate(min);
        for (int i = 0; i < candidate_count; i++){
            candidates[i].votes = 0;
        }
    }
return 0;
}
bool vote(int voter, int rank, string name){
    for (int i = 0; i < candidate_count; i++){
        if (strcmp(candidates[i].name, name) == 0){
            preferences[voter][rank] = i;
            return true;
        }
    }
return false;
}
void tabulate(void){
    for (int i = 0; i < voter_count; i++){
        int j = 0;
        int posicao = 0;
        while (j < candidate_count){
            if (j == preferences[i][posicao]){
                if (!candidates[j].eliminated){
                    candidates[j].votes++;
                 break;
                }
                else{
                    posicao++;
                    j = 0;
                    if (posicao == candidate_count){
                        break;
                    }
                    if (j == preferences[i][posicao]){
                        if (!candidates[j].eliminated){
                            candidates[j].votes++;
                            break;
                        }
                    }
                }
            }
            j++;
        }
    }
return;
}
bool print_winner(void){
    int maiorVotacao = 0;
    int vencedor = 0;
    vencedor = (voter_count / 2) + 1;
    for (int i = 0; i < candidate_count; i++){
        if(!candidates[i].eliminated){
            if (candidates[i].votes > maiorVotacao){
                maiorVotacao = candidates[i].votes;
            }
        }
    }
    for (int i = 0; i < candidate_count; i++){
        if(!candidates[i].eliminated){
            if (candidates[i].votes == maiorVotacao){
                if(candidates[i].votes >= vencedor){
                    printf("%s\n", candidates[i].name);
                    return true;
                }
            }
        }
    }
return false;
}
int find_min(void){
    int menorVotacao = voter_count;
    for (int i = 0; i < candidate_count; i++){
        if(!candidates[i].eliminated){
            if (candidates[i].votes < menorVotacao){
                menorVotacao = candidates[i].votes;
            }
        }
    }
    for (int i = 0; i < candidate_count; i++){
        if(!candidates[i].eliminated){
            if (candidates[i].votes == menorVotacao){
                return menorVotacao;
            }
        }
    }
return 0;
}
bool is_tie(int min){
    int quantidadeNaoEliminado = 0;
    int quantidadeVotoMinimo = 0;
    for (int i = 0; i < candidate_count; i++){
        if (!candidates[i].eliminated){
            quantidadeNaoEliminado++;
        }
        if (candidates[i].votes == min){
            quantidadeVotoMinimo++;
        }  
    }
}
if (quantidadeNaoEliminado == quantidadeVotoMinimo){
    return true;
}
return false;

void eliminate(int min){
    for (int i = 0; i < candidate_count; i++){
        if (candidates[i].votes == min){
            candidates[i].eliminated = true;
        }
    }
return;
}