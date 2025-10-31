#include <stdio.h>

int main(void)
{
    int matriz[5][5];
    int i, j;
    int linha;
    int col;
    int ans = 0;

    // ler matrix
    i = 0;
    while(i < 5)
    {
        j = 0;
        while(j < 5)
        {
            scanf("%d", &matriz[i][j]);
            //guardar a posicao do 1
            if(matriz[i][j] == 1)
            {
                linha = i;
                col = j;
            }
            j++;
        }
        i++;
    }

    //contar as movimentacoes
    if(linha > 2)
        ans += linha - 2;
    if(linha < 2)
        ans += 2 - linha;
    if(col > 2)
        ans += col - 2;
    if(col < 2)
        ans += 2 - col;
    printf("%d", ans);
       

    return 0;
}


