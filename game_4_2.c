/*
 * game_4_2.c
 *
 * game_4_2
 * RPG
 * Yusuke Kato
 * 2016.2.20
 * 2016.2.20
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int fg=0,fg2=1;

struct person
{
	char name[64];
	int level;
	int hp;
};

void story(void)
{
	printf(" ");
}

void make_char(void)
{
	FILE *fp;
	struct person player;
	for(;;)
	{
		fp = fopen("game_4_2_save_data.txt","r");
		while(fscanf(fp,"%s %d %d",player.name,&player.level,&player.hp) != EOF){
			printf("\n name: %s level: %d  HP: %d\n\n",player.name,player.level,player.hp);
		}
		printf( " 新しいキャラクターを作りますか\n"
				" ０：はい  １：いいえ\n"
				" 入力：");
		scanf("%d",&fg);
		if(fg==1) break;
		else if(fg==0)
		{
			printf(" 名前を入力してください:");
			scanf("%s",&player.name);
			player.level = 1;
			srand((unsigned)time(NULL));
			player.hp = rand()%100 + 1;
	
			fp = fopen("game_4_2_save_data.txt","w");
			fprintf(fp,"%s %d %d\n"
					,player.name
					,player.level
					,player.hp);
	
			printf("\n name: %s level: %d HP: %d\n\n"
					,player.name
					,player.level
					,player.hp);
			
			printf( " 以上でよろしいですか\n"
					" ０：はい  １：いいえ\n"
					" 入力：");
			scanf("%d",&fg2);
			if(fg2==0) fg=1;
			if(fg==1) break;
		}
		else
		{
			printf(" キャラクターがいません\n");
			break;
		}
		if(fg==1) break;
	}
	fclose(fp);	
}

int main(void)
{
	printf(" ゲームを始めます\n");
	make_char();
	story();
	return 0;
}