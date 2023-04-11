#include <stdio.h>

int alunos_aprovados(int qtalunos, double nota[qtalunos]){

    int qt_apro = 0;
    for (int i = 0; i < qtalunos; i++)
    {
        if (nota[i] >= 7)
        {
            qt_apro += 1;
        }
        
    }
    return qt_apro;
}

int alunos_recuperacao(int qtalunos, double nota[qtalunos]){

    int qt_recu = 0;
    for (int i = 0; i < qtalunos; i++)
    {
        if (nota[i] < 7 && nota[i] >= 5)
        {
            qt_recu += 1;
        }
        
    }
    return qt_recu;
}

int alunos_reprovados(int qtalunos, double nota[qtalunos]){

    int qt_repro = 0;
    for (int i = 0; i < qtalunos; i++)
    {
        if (nota[i] < 5)
        {
            qt_repro += 1;
        }
        
    }
    return qt_repro;
}

int main(){

    int qtalunos;
    int cont1 = 0;
    int cont2 = 0;
    int cont3 = 0;

    scanf(" %d", &qtalunos);
    double nota[qtalunos];
    int n_chamada[qtalunos];

    for (int i = 0; i < qtalunos; i++)
    {
        scanf(" %d - %lf", &n_chamada[i], &nota[i]);
    }

    int qt_apro = alunos_aprovados(qtalunos, nota);
    int qt_recu = alunos_recuperacao(qtalunos, nota);
    int qt_repro = alunos_reprovados(qtalunos, nota);

    double apro[qt_apro];
    double recu[qt_recu];
    double repro[qt_repro];

    int ch_apro[qt_apro];
    int ch_recu[qt_recu];
    int ch_repro[qt_repro];


    for (int i = 0; i < qtalunos; i++)
    {
        if (nota[i] >= 7)
        {
            apro[cont1] = nota[i];
            ch_apro[cont1] = n_chamada[i];
            cont1 += 1;
        }else if (nota[i] < 7 && nota[i] >= 5)
        {
            recu[cont2] = nota[i];
            ch_recu[cont2] = n_chamada[i];
            cont2 += 1;
        }else{
            repro[cont3] = nota[i];
            ch_repro[cont3] = n_chamada[i];
            cont3 += 1; 
        }
               
    }
    
    printf("Aprovados:");
    
    for (int j = 0; j < qt_apro; j++)
    {
        if (j == qt_apro -1)
        {
            printf(" %d (%.1lf)\n", ch_apro[j], apro[j]);
        }else{
            printf(" %d (%.1lf),", ch_apro[j], apro[j]);
        }  
    }

    printf("Recuperação:");

    for (int j = 0; j < qt_recu; j++)
    {
        if (j == qt_recu -1)
        {
            printf(" %d (%.1lf)\n", ch_recu[j], recu[j]);
        }else{
            printf(" %d (%.1lf),", ch_recu[j], recu[j]);
        }  
    }

    printf("Reprovados:");

    for (int j = 0; j < qt_repro; j++)
    {
        if (j == qt_repro -1)
        {
            printf(" %d (%.1lf)\n", ch_repro[j], repro[j]);
        }else{
            printf(" %d (%.1lf),", ch_repro[j], repro[j]);
        }  
    }
    return 0;
}
    
