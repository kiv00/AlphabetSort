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
	int dlin=1,kolvo=0,max=0,i=-1,j=0;
	FILE *op, *sort;
	char name1[1000],name2[1000],zapros[1002],sim,pred='.';
	printf("enter the file name: ");
	scanf("%s", zapros);
	strcpy(name1,"../texts/");
	strcpy(name2,"../Sort/");
	strcat(name1,zapros);
	strcat(name2,zapros);
	op=fopen(name1,"r");
	sort=fopen(name2,"w");
	while((sim=getc(op))!=EOF){
			if((sim>64&&sim<91)||(sim>96&&sim<123)||(sim>191&&sim<256)){
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
	while((sim=getc(op))!=EOF){
		if((sim>64&&sim<91)||(sim>96&&sim<123)){
				if(!((pred>64&&pred<91)||(pred>96&&pred<123))){
					i++;
					j=1;
					if(sim>64&&sim<91) sim+=32;
					slova[i][0]=sim;
				}else{
					if(sim>64&&sim<91) sim+=32;
					slova[i][j]=sim;
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
	
	fclose(op);
	fclose(sort);
	printf("Complete!\n");
	system("PAUSE");
	return EXIT_SUCCESS;
}	
