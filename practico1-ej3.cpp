#include <stdio.h>


int Ocurrenica(char frase[], int largo, char letra){
    int count=0;
    for (size_t i = 0; i < largo; i++)
    {
        if (frase[i] == letra)
        {
            count+=1;
        }
        
    }
    return count;
}



int main(){
char frase[100];
int largo=6;
char letra = 'p';
frase[0] = 'p';
frase[1] = 'e';
frase[2] = 'd';
frase[3] = 'r';
frase[4] = 'o';
frase[5] = 's';
int a = Ocurrenica(frase,largo, letra);
printf("%d", a);
}