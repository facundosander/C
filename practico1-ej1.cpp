#include <stdio.h>


int PromClase(int n1, int n2, int n3, int n4, int n5){
    int resultado = n1;
    int arr[4];
    arr[0]=n2;
    arr[1]=n3;
    arr[2]=n4;
    arr[3]=n5;
    for (size_t i = 0; i < 4; i++)
    {
        if (resultado > arr[i])
        {
            resultado = arr[i];
        }
        
    }
    
    return resultado = (n1 + n2 + n3 + n4 + n5 - resultado) / 4;

}

int main()
{
    int n1,n2,n3,n4,n5;
    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);
    scanf("%d", &n4);
    scanf("%d", &n5);
    int resu = PromClase(n1,n2,n3,n4,n5);
    printf("%d", resu);
    return 0;
}
