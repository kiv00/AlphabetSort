#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include "func.h"






int main(){
	setlocale(LC_ALL,"Russian");
	int i=-1,j=0;
	long long count=0,max=0;
	FILE *op, *sort;
	char name1[1000],name2[1000],zapros[1002],simbol, pred='.';
	printf("enter the file name: ");
	scanf("%s", zapros);
	strcpy(name1,"../texts/");
	strcpy(name2,"../Sort/");
	strcat(name1,zapros);
	strcat(name2,zapros);
	sort=fopen(name2,"w");
	countWord(&max,&count,name1);
	printf(" %d %d",max,count);
	char slova[count][max];
	op=fopen(name1,"r");
	rewind(op);
	pred='.';
	while((simbol=getc(op))!=EOF){
		if((simbol>64&&simbol<91)||(simbol>96&&simbol<123)){
				if(!((pred>64&&pred<91)||(pred>96&&pred<123))){
					i++;
					j=1;
					if(simbol>64&&simbol<91) simbol+=32;
					slova[i][0]=simbol;
				}else{
					if(simbol>64&&simbol<91) simbol+=32;
					slova[i][j]=simbol;
					j++;
					slova[i][j]=0;
				}
			}
			pred=simbol;
		}
		
	char **slovaDinam;
	slovaDinam = (char**)malloc(count*sizeof(char*));
	for (i=0; i<count; i++) {
	slovaDinam[i] = (char*)malloc(max*sizeof(char));}
		
	for(int i=0; i<count;i++)
	strcpy(slovaDinam[i], slova[i]);
	
	Sort(slovaDinam, count, max);
		
	count = Unique(slovaDinam, count);
	
	for(int i=0; i<count;i++){
			fputs(slovaDinam[i],sort);
			putc('\n',sort);
		}
	fclose(op);
	fclose(sort);
	printf("Complete!\n");
	system("PAUSE");
	return EXIT_SUCCESS;
}	
