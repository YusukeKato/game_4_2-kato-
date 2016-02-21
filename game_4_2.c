/*
 * game_4_2.c
 *
 * game_4_2
 * RPG
 * Yusuke Kato
 * 2016.2.20
 * 2016.2.21
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

/* flag */
int fg=0,fg2=1;
/* キャラクター（変更考える） */
struct character
{
	char name[64];
	int level;
	int hp;
	int power;
};

/********** バトルシステム（変更考える） **********/
void battle(void)
{
	FILE *fp;
	int hp;
	int power;
	int teki;
	struct character enemy;
	struct character player;
	
	fp = fopen("game_4_2_save_data.txt","r");
		while(fscanf(fp,"%s %d %d %d",player.name,&player.level,&player.hp,&player.power) != EOF){
			printf("\n name : %s\n level: %d\n HP   : %d\n power; %d\n\n"
						,player.name
						,player.level
						,player.hp
						,player.power);
		}
	fclose(fp);
	
	printf(" ！！！バトル開始！！！\n\n");
	/* バトル後、元に戻すため*/
	hp = player.hp;
	power = player.power;
	/* 敵の能力決定*/
	if(player.level<=10)
	{
		srand((unsigned)time(NULL));
		enemy.level = rand()%20 + 1;
		enemy.hp = enemy.level * 3;
		enemy.power = enemy.level;
	}
	else if(player.level<=30&&player.level>10)
	{
		srand((unsigned)time(NULL));
		enemy.level = rand()%50 + 20;
		enemy.hp = enemy.level * 5;
		enemy.power = enemy.level;
	}
	else if(player.level<=60&&player.level>30)
	{
		srand((unsigned)time(NULL));
		enemy.level = rand()%50 + 20;
		enemy.hp = enemy.level * 8;
		enemy.power = enemy.level;
	}
	else if(player.level<=90&&player.level>60)
	{
		srand((unsigned)time(NULL));
		enemy.level = rand()%100 + 70;
		enemy.hp = enemy.level * 10;
		enemy.power = enemy.level;
	}
	else if(player.level>90)
	{
		srand((unsigned)time(NULL));
		enemy.level = rand()%200 + 100;
		enemy.hp = enemy.level * 20;
		enemy.power = enemy.level;
	}
	/* 敵決定 */
	srand((unsigned)time(NULL));
	teki = rand()%100 + 1;
	if(teki>=1&&teki<=30)
	{
		strncpy(enemy.name,"くそやろう",sizeof(enemy.name));
	}
	else if(teki>=31&&teki<=50)
	{
		strncpy(enemy.name,"昼飯泥棒",sizeof(enemy.name));
		enemy.level += 1;
		enemy.hp += 10;
		enemy.power += 5;
	}
	else if(teki>=51&&teki<=60)
	{
		strncpy(enemy.name,"竹中さん",sizeof(enemy.name));
		enemy.level += 0;
		enemy.hp += 0;
		enemy.power += 0;
	}
	else if(teki>=61&&teki<=85)
	{
		strncpy(enemy.name,"やさしいひと",sizeof(enemy.name));
		enemy.level += 3;
		enemy.hp += 50;
		enemy.power += 25;
	}		
	else if(teki>=86&&teki<=100)
	{
		strncpy(enemy.name,"魔王代理",sizeof(enemy.name));
		enemy.level += 5;
		enemy.hp += 100;
		enemy.power += 50;
	}
	if(player.level>80)
	{
		strncpy(enemy.name,"ラスボス魔王",sizeof(enemy.name));
		enemy.level = 100;
		enemy.hp += 1000;
		enemy.power += 500;
	}
	printf(" レベル%d の %s があらわれた！！\n",enemy.level,enemy.name);
	printf("==============================\n");
	for(;;)
	{
		Sleep(2000);//sleep(s) Sleep(ms)
		if(player.level<=10)
		{
			srand((unsigned)time(NULL));
			player.power += rand()%50 + 5;
			Sleep(1000);
			srand((unsigned)time(NULL));
			enemy.power += rand()%20 + 0;
			printf(" 1 \n");
		} 
		else if(player.level<=30&&player.level>10) 
		{
			srand((unsigned)time(NULL));
			player.power += rand()%100 + 10;
			Sleep(1000);
			srand((unsigned)time(NULL));
			enemy.power += rand()%50 + 0;
			printf(" 2 \n");
		} 
		else if(player.level<=60&&player.level>30) 
		{
			srand((unsigned)time(NULL));
			player.power += rand()%200 + 20;
			Sleep(1000);
			srand((unsigned)time(NULL));
			enemy.power += rand()%100 + 0;
			printf(" 3 \n");
		} 
		else if(player.level<=80&&player.level>60) 
		{
			srand((unsigned)time(NULL));
			player.power += rand()%400 + 40;
			Sleep(1000);
			srand((unsigned)time(NULL));
			enemy.power += rand()%200 + 0;
			printf(" 4 \n");
		} 
		else if(player.level>80) 
		{
			srand((unsigned)time(NULL));
			player.power += rand()%600 + 60;
			Sleep(1000);
			srand((unsigned)time(NULL));
			enemy.power += rand()%300 + 0;
			printf(" 5 \n");
		} 
		else 
		{
			printf(" \nエラー\n\n");
			exit(0);
		}
		printf(" %s の攻撃！！",player.name);
		printf(" %d のダメージ！！\n",player.power);
		enemy.hp = enemy.hp - player.power;
		if(enemy.hp<=0)
		{
			/* バトル前に値を戻す */
			player.hp = hp;
			player.power = power;
			
			printf(" %s は勝利した！！\n",player.name);
			if(teki>=1&&teki<=30)
			{
				printf(" レベルが１上がった！！\n");
				player.level += 1;
				player.hp += 10;
				player.power += 5;
			}
			else if(teki>=31&&teki<=50)
			{
				printf(" レベルが２上がった！！\n");
				player.level += 3;
				player.hp += 30;
				player.power += 15;
			}
			else if(teki>=51&&teki<=60)
			{
				printf(" レベルが１０上がった！！\n");
				player.level += 20;
				player.hp += 200;
				player.power += 100;
			}
			else if(teki>=61&&teki<=85)
			{
				printf(" レベルが３上がった！！\n");
				player.level += 5;
				player.hp += 50;
				player.power += 25;
			}
			else if(teki>=86&&teki<=100)
			{
				printf(" レベルが５上がった！！\n");
				player.level += 10;
				player.hp += 100;
				player.power += 50;
			}
			if(player.level>80)
			{
				printf("\n\n ！！！！！ゲームクリア！！！！！\n\n\n");
				exit(0);
			}
			break;
		}
		printf(" %s の攻撃！！",enemy.name);
		printf(" %d のダメージ！！\n",enemy.power);
		player.hp = player.hp - enemy.power;
		if(player.hp<=0)
		{
			printf("\n %s は敗北した・・・・・・\n\n",player.name);
			printf(" ゲームを終了します\n");
			exit(0);
		}
	}
	printf("==============================\n");
	fp = fopen("game_4_2_save_data.txt","w");
	fprintf(fp,"%s %d %d %d\n"
					,player.name
					,player.level
					,player.hp
					,player.power);
	fclose(fp);
	fp = fopen("game_4_2_save_data.txt","r");
	while(fscanf(fp,"%s %d %d %d",player.name,&player.level,&player.hp,&player.power) != EOF)
	{
		printf(" name : %s\n level: %d\n HP   : %d\n power; %d\n\n"
						,player.name
						,player.level
						,player.hp
						,player.power);
	}
	fclose(fp);
	printf(" ・・・・・・バトル終了・・・・・・\n");
}

/********** キャラクター作成 **********/
void make_char(void)
{
	FILE *fp;
	struct character player;
	for(;;)
	{
		fp = fopen("game_4_2_save_data.txt","r");
		while(fscanf(fp,"%s %d %d %d",player.name,&player.level,&player.hp,&player.power) != EOF){
			printf("\n name : %s\n level: %d\n HP   : %d\n power; %d\n\n"
						,player.name
						,player.level
						,player.hp
						,player.power);
		}
		printf( " 新しいキャラクターを作りますか\n"
				" 0:はい  1:いいえ\n"
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
			player.power = 5;
	
			fp = fopen("game_4_2_save_data.txt","w");
			fprintf(fp,"%s %d %d %d\n"
					,player.name
					,player.level
					,player.hp
					,player.power);
	
			printf("\n name : %s\n level: %d\n HP   : %d\n power: %d\n\n"
					,player.name
					,player.level
					,player.hp
					,player.power);
			
			printf( " 以上でよろしいですか\n"
					" 0:はい  1:いいえ\n"
					" 入力：");
			scanf("%d",&fg2);
			if(fg2==0) fg=1;
			if(fg==1) break;
		}
		else
		{
			printf(" エラー\n");
			break;
		}
		if(fg==1) break;
	}
	fclose(fp);	
}

void story(void)
{
	for(;;)
	{
		battle();
		Sleep(5000);
	}
}

int main(void)
{
	printf(" \n\nゲームを始めます\n");
	make_char();
	story();
	printf(" \n\nゲームを終了します\n\n");
	return 0;
}