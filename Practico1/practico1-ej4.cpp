#include <stdio.h>
#include <ctype.h>

bool EsPalindrome (char *frase){
    int largo = 0;
    char *inicio;
    char *fin;
    bool resu;
    inicio = frase;
    fin = frase;
    while (*fin != NULL){
        largo++;
        fin++;
    }
    fin--;
    largo = largo / 2;
    resu = true;
    for (size_t i = 0; i < largo && resu; i++)
    {
        if (tolower(*inicio) != tolower(*fin))
        {
            resu=false;
        }
        
    }
    
    return resu;
}

int main(){
    char *frase;
    char palabra[] = "neeNx";
    frase = palabra;
    printf("%d", EsPalindrome(frase));
    return 0;
}
