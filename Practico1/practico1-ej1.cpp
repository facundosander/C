#include <stdio.h>


float PromClase(int cal1, int cal2, int cal3, int cal4, int cal5){
    float resultado = cal1;
    int arr[4];
    arr[0]=cal2;
    arr[1]=cal3;
    arr[2]=cal4;
    arr[3]=cal5;
    for (size_t i = 0; i < 4; i++)
    {
        if (resultado > arr[i])
        {
            resultado = arr[i];
        }
        
    }
    
    return resultado = (cal1 + cal2 + cal3 + cal4 + cal5 - resultado) / 4;

}

int main()
{
    int n1,n2,n3,n4,n5;
    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);
    scanf("%d", &n4);
    scanf("%d", &n5);
    float resu = PromClase(n1,n2,n3,n4,n5);
    printf("%f", resu);
    return 0;
}
