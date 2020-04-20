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
	long long dlin=1,kolvo=0,max=0;
	FILE *op, *sort;
	char name1[1000],name2[1000],zapros[1002],simbol,pred='.';
	printf("enter the file name: ");
	scanf("%s", zapros);
	strcpy(name1,"../texts/");
	strcpy(name2,"../Sort/");
	strcat(name1,zapros);
	strcat(name2,zapros);
	op=fopen(name1,"r");
	sort=fopen(name2,"w");
	while((simbol=getc(op))!=EOF){
			if((simbol>64&&simbol<91)||(simbol>96&&simbol<123)||(simbol>191&&simbol<256)){
				if((pred>64&&pred<91)||(pred>96&&pred<123)||(pred>191&&pred<256)){
					dlin++;
				}else {
					if(dlin>max) max=dlin;
					dlin=1;
					kolvo++;
				}
			}
			pred=sim;
	}
	max++;
	char slova[kolvo][max];
	rewind(op);
	pred='.';
	while((simbol=getc(op))!=EOF){
		if((simbol>64&&simbol<91)||(simbol>96&&simbol<123)){
				if(!((pred>64&&pred<91)||(pred>96&&pred<123))){
					i++;
					j=1;
					if(simbol>64&&simbol<91) sim+=32;
					slova[i][0]=simbol;
				}else{
					if(simbol>64&&simbol<91) simbol+=32;
					slova[i][j]=simbol;
					j++;
					slova[i][j]=0;
				}
			}
			pred=sim;
		}
		
	char **slovadin;
	slovadin = (char**)malloc(kolvo*sizeof(char*));
	for (i=0; i<kolvo; i++) {
	slovadin[i] = (char*)malloc(max*sizeof(char));}
		
	for(int i=0; i<kolvo;i++)
	strcpy(slovadin[i], slova[i]);
	
	Sort(slovadin, kolvo, max);
		
	kolvo = Unique(slovadin, kolvo);
	
	for(int i=0; i<kolvo;i++){
			fputs(slovadin[i],sort);
			putc('\n',sort);
		}
	fclose(op);
	fclose(sort);
	printf("Complete!\n");
	system("PAUSE");
	return EXIT_SUCCESS;
}	
