#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
//alterar qtd de itens e peso total da mochila no define, o restante esta incluso no menu dentro da aplicação

#define qtd 3
#define pesomochila 10

	int matriz[qtd][2],guloso[qtd][2],dinamico[qtd+1][pesomochila+1]={ { 0 } }, valoresdinamico[qtd]={0};
	int temporario=0,loopguloso=0, pesoguloso=0, valorguloso=0, qtdvolatil=qtd, pesovolatil=pesomochila;
	int x,y;

void ordena(){
	for(y=0;y<qtd;y++){
	for(x=y+1;x<qtd;x++){
	if(matriz[y][2]>matriz[x][2]){
	temporario=matriz[y][1];
	matriz[y][1]=matriz[x][1];
	matriz[x][1]=temporario;
	temporario=matriz[y][2];
	matriz[y][2]=matriz[x][2];
	matriz[x][2]=temporario;
	} } }
}

void metodoguloso(int pesotemporario){

	for(y=0;y<qtd;y++){
	if(matriz[y][2]<=pesotemporario ){
	loopguloso++;
	pesotemporario=pesotemporario-matriz[y][2];
	guloso[y][1]=matriz[y][1];
	valorguloso=valorguloso+guloso[y][1];
	guloso[y][2]=matriz[y][2];
	} }
}

void metododinamico(){

	for(y=1;y<qtd+1;y++){ 
	for(x=1;x<pesomochila+1;x++){ 
	if(x>=matriz[y-1][2]){ 
	dinamico[y][x]=matriz[y-1][1];  
	temporario=x-matriz[y-1][2];                       
	dinamico[y][x]=dinamico[y][x]+dinamico[y-1][temporario];  }
	if(dinamico[y][x]<dinamico[y-1][x]){   
	dinamico[y][x]=dinamico[y-1][x]; 
	} } }
	
	do{
	if(dinamico[qtdvolatil][pesovolatil] != dinamico[qtdvolatil-1][pesovolatil]){
	valoresdinamico[qtdvolatil]=matriz[qtdvolatil-1][1];
	pesovolatil=pesovolatil-matriz[qtdvolatil-1][2];
	qtdvolatil--;}
	}while( dinamico[qtdvolatil][pesovolatil]>0 );
	
}
int main(){
	int escolha;
	int pesotemporario=pesomochila;
	
	do{
    printf("\n                Mochila\n");
    printf(" ------------------------------------------\n\n");
    printf("    1 - Adicionar Valor e Peso \n");
    printf("    2 - Resposta por metodo guloso \n");
    printf("    3 - Resposta por metodo dinamico\n");
    printf("    0 - Sair\n\n");
	printf(" ------------------------------------------\n\n");
    printf("    Informe a operacao a ser efetuada: ");
	scanf("%d", &escolha);
	printf("\n");

	switch(escolha){
	case 1:
			
	for(y=0;y<qtd;y++){
	printf("Valor:");
	scanf("%d", &matriz[y][1]);
	printf("peso:");	
	scanf("%d", &matriz[y][2]);
	}
	ordena();	
	break;
	
	case 2:
	metodoguloso(pesotemporario);
	printf("\n Mochila por metodo Guloso: \n");
	printf("O valor total da mochila e: %d \n", valorguloso );
	printf("Os itens selecionados foram: \n");
	for(y=0;y<loopguloso;y++){
	printf("%d - %d \n",guloso[y][1] ,guloso[y][2]);
	}			
	break;
	
	case 3:	
	metododinamico();
	printf("\n Mochila por metodo Dinamico: \n");
	printf("O valor total da mochila e: %d \n", dinamico[qtd][pesomochila] );
	printf("Os itens selecionados sao: \n" );
	for(y=0;y<=qtd;y++){
	if(valoresdinamico[y] > 0){
	printf("%d \n",valoresdinamico[y]);
	}
	} 
    break;
    
    case 0:
    system("PAUSE");
    break;
	}
	
	}while(escolha != 0);
	}
