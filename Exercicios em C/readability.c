#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

int main(void){
    
    int letras = 0;
    int palavras = 1;
    int frases = 0;
    float resultado;

    string s = get_string("Insira seu texto: ");
    
    for (int i = 0, n = strlen(s); i < n; i++){
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            letras++;
        }
        else if (s[i] == ' '){
            palavras++;
        }
        else if (s[i] == '.' || s[i] == '!' || s[i] == '?'){
            frases++;
        }
    }

    float letrasm = ((float) letras / palavras) * 100;
    float frasesm = ((float) frases / palavras) * 100;

    resultado = ((0.0588 * letrasm) - (0.296 * frasesm) - 15.8);
    
    int a = (int) round(resultado);
    
    if (a < 0){
        printf("Before Grade 1\n"); 
    }
    else if (a > 16){
        printf("Grade 16+\n");
    }
    else{
        printf("Grade %.i\n", a);
    }
}