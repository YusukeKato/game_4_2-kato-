/*
 * game_4_2
 * RPG
 * Yusuke Kato
 * 2016.2.20
 * 2016.2.22
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

FILE *fp;
/* flag */
int fg=0,fg2=1;
int flag = 0; //storyのセーブに使う(main関数)
/* キャラクター（変更考える） */
struct character
{
	char name[64];
	int level;
	int hp;
	int mp;
	int power;
	int defense;
	int money;
	int kusuri;//個数
	int flag;//進度
};

void help(void)
{
	struct character player;
	printf("==============================\n");
	printf(" 2016.2.21時点\n");
	fp = fopen("game_4_2_save_data.txt","r");
		while(fscanf(fp,"%s %d %d %d %d %d %d %d %d",player.name,&player.level,&player.hp,&player.mp,&player.power,&player.defense,&player.money,&player.kusuri,&player.flag) != EOF){
			printf("\n 名前: %s\n レベル: %d\n HP: %d\n MP: %d\n 攻撃 ; %d\n 防御 : %d\n お金: %d\n 薬の数: %d\n 進度: %d\n\n"
						,player.name
						,player.level
						,player.hp
						,player.mp
						,player.power
						,player.defense
						,player.money
						,player.kusuri
						,player.flag);
		}
	fclose(fp);
	printf( "\n\n 闘ってレベル上げて、ボスへ挑む。\n\n"
			" ＜アイテム説明＞\n\n"
			" ・薬：HPとMPを回復する\n"
			" ・剣：攻撃の最大値を上げる\n"
			" ・盾：防御の最大値を上げる\n"
			" ・HPフエール：HPの最大値を上げる\n"
			" ・MPフエール：MPの最大値を上げる\n\n\n");
	printf("==============================\n");
}

void story_1(void)
{
	printf("=================================================\n");
	printf( "\n\t私は勇者となった。\n"
			"\n\t使命は魔王をたおすこと。\n"
			"\n\tその使命を果たすため、\n"
			"\n\t私は旅に出た。\n\n");
	printf("=================================================\n");
}

/********** バトルシステム（変更考える） **********/
void battle(void)
{
	int hp;
	int mp;
	int power;
	int defense;
	int enehp;
	int teki;
	int fg=0;
	int move;
	//int kusuri_hp;
	//int kusuri_mp;
	struct character enemy;
	struct character player;
	
	fp = fopen("game_4_2_save_data.txt","r");
		while(fscanf(fp,"%s %d %d %d %d %d %d %d %d",player.name,&player.level,&player.hp,&player.mp,&player.power,&player.defense,&player.money,&player.kusuri,&player.flag) != EOF){
			printf("\n 名前: %s\n レベル: %d\n HP: %d\n MP: %d\n 攻撃 ; %d\n 防御 : %d\n お金: %d\n 薬の数: %d\n 進度: %d\n\n"
						,player.name
						,player.level
						,player.hp
						,player.mp
						,player.power
						,player.defense
						,player.money
						,player.kusuri
						,player.flag);
		}
	fclose(fp);
	
	printf(" ！！！バトル開始！！！\n\n");
	/* バトル後、元に戻すため*/
	hp = player.hp;
	mp = player.mp;
	power = player.power;
	defense = player.defense;
	/***** 敵決定 *****/
	srand((unsigned)time(NULL));
	teki = rand()%100 + 1;
	if(teki>=1&&teki<10)
	{
		strncpy(enemy.name,"くそやろう",sizeof(enemy.name));
		enemy.level = 1;
		enemy.hp = 1;
		enemy.power = 1;
		enemy.defense = 1;
	}
	else if(teki>=10&&teki<20)
	{
		strncpy(enemy.name,"昼飯泥棒",sizeof(enemy.name));
		enemy.level = 2;
		enemy.hp = 10;
		enemy.power = 10;
		enemy.defense = 10;
	}
	else if(teki>=20&&teki<30)
	{
		strncpy(enemy.name,"空飛ぶコッペパン",sizeof(enemy.name));
		enemy.level = 3;
		enemy.hp = 20;
		enemy.power = 20;
		enemy.defense = 20;
	}
	else if(teki>=40&&teki<50)
	{
		strncpy(enemy.name,"東を向いて",sizeof(enemy.name));
		enemy.level = 4;
		enemy.hp = 30;
		enemy.power = 30;
		enemy.defense = 30;
	}
	else if(teki>=50&&teki<60)
	{
		strncpy(enemy.name,"やさしいひと",sizeof(enemy.name));
		enemy.level = 5;
		enemy.hp = 40;
		enemy.power = 40;
		enemy.defense = 40;
	}
	else if(teki>=60&&teki<70)
	{
		strncpy(enemy.name,"未来",sizeof(enemy.name));
		enemy.level = 6;
		enemy.hp = 50;
		enemy.power = 50;
		enemy.defense = 50;
	}
	else if(teki>=70&&teki<80)
	{
		strncpy(enemy.name,"つかれた",sizeof(enemy.name));
		enemy.level = 7;
		enemy.hp = 10;
		enemy.power = 200;
		enemy.defense = 10;
	}
	else if(teki>=80&&teki<90)
	{
		strncpy(enemy.name,"竹中さん",sizeof(enemy.name));
		enemy.level = 8;
		enemy.hp = 200;
		enemy.power = 200;
		enemy.defense = 100;
	}		
	else if(teki>=90&&teki<100)
	{
		strncpy(enemy.name,"魔王代理",sizeof(enemy.name));
		enemy.level = 10;
		enemy.hp = 300;
		enemy.power = 150;
		enemy.defense = 100;
	}
	else if(teki==100)
	{
		strncpy(enemy.name,"俺の名は・・・・・",sizeof(enemy.name));
		enemy.level = 100;
		enemy.hp = 10000;
		enemy.power = 1000;
		enemy.defense+= 1000;
	}
	/***** 敵の能力決定 *****/
	srand((unsigned)time(NULL));
	enemy.level += player.level * (rand()%20+1);
	enemy.hp += enemy.level * 5;
	enemy.power += enemy.level;
	enemy.defense += enemy.level;
	
	printf(" レベル%d の %s があらわれた！！\n\n",enemy.level,enemy.name);
	/********** バトルスタート **********/
	printf("==================================================\n");
	while(fg==0)
	{
		printf(" 行動を選択してください\n");
		printf( " 1:攻撃\n"
				" 2:魔法\n"
				" 3:薬を使う\n"
				" 4:様子を見る\n"
				" 5:逃げる\n");
		printf(" 入力：");
		scanf("%d",&move);
		switch(move)
		{
			case 1:
			srand((unsigned)time(NULL));
			player.power += rand()%500 + 1;
			printf(" %s の攻撃！！",player.name);
			printf(" %d のダメージ！！\n",player.power);
			enemy.hp -= player.power;
			player.power = power;
			break;
			case 2:
			if(player.mp<50)
			{
				printf(" MPが足りません\n");
				break;
			}
			player.power += rand()%1000 + 1;
			printf(" %s の攻撃！！",player.name);
			printf(" %d のダメージ！！\n",(player.power*2)-enemy.defense);
			enemy.hp -= (player.power*2)-enemy.defense;
			player.mp -= 50;
			player.power = power;
			break;
			case 3:
			printf(" %s は薬を使った",player.name);
			printf(" HPとMPが回復した\n");
			player.hp = hp;
			player.mp = mp;
			break;
			case 4:
			printf(" %s は様子を見た・・・・・・\n",player.name);
			printf(" %s はHPが少し回復した\n",player.name);
			player.hp += 300;
			break;
			case 5:
			printf(" だめだ、逃げられない！！\n");
			printf(" %s はMPが少し回復した\n",player.name);
			player.mp += 30;
			break;
			default:
			break;
		}
		if(enemy.hp<=0)
		{
			fg=1;
			/* バトル前の値に戻す*/
			player.hp = hp;
			player.mp = mp;
			player.power = power;
			player.defense = defense;
			/********** バトル後のレベルアップとか **********/
			if(teki>=1&&teki<10)
			{
				printf(" %s をたおした！！！\n",enemy.name);
				printf("\n レベル１上がった！！\n");
				printf(" 能力値が上がった！！お金もらった！！\n\n");
				srand((unsigned)time(NULL));
				player.level += 1;
				player.hp += rand()%20 + 10;
				player.mp += rand()%10 + 1;
				player.power += rand()%20 + 10;
				player.defense += rand()%10 + 5;
				player.money += 100;
				player.kusuri += 0;
			}
			else if(teki>=10&&teki<20)
			{
				printf(" %s をたおした！！！\n",enemy.name);
				printf("\n レベル２上がった！！\n");
				printf(" 能力値が上がった！！お金もらった！！\n\n");
				srand((unsigned)time(NULL));
				player.level += 2;
				player.hp += rand()%40 + 20;
				player.mp += rand()%20 + 5;
				player.power += rand()%40 + 20;
				player.defense += rand()%30 + 15;
				player.money += 2000;
				player.kusuri += 0;
			}
			else if(teki>=20&&teki<30)
			{
				printf(" %s をたおした！！！\n",enemy.name);
				printf("\n レベル３上がった！！\n");
				printf(" 能力値が上がった！！お金もらった！！\n\n");
				srand((unsigned)time(NULL));
				player.level += 3;
				player.hp += rand()%100 + 50;
				player.mp += rand()%30 + 10;
				player.power += rand()%40 + 10;
				player.defense += rand()%40 + 10;
				player.money += 1000;
				player.kusuri += 0;
			}
			else if(teki>=40&&teki<50)
			{
				printf(" %s をたおした！！！\n",enemy.name);
				printf("\n レベル４上がった！！\n");
				printf(" 能力値が上がった！！お金もらった！！\n\n");
				srand((unsigned)time(NULL));
				player.level += 4;
				player.hp += rand()%100 + 50;
				player.mp += rand()%50 + 20;
				player.power += rand()%30 + 10;
				player.defense += rand()%50 + 40;
				player.money += 3000;
				player.kusuri += 0;
			}
			else if(teki>=50&&teki<60)
			{
				printf(" %s をたおした！！！\n",enemy.name);
				printf("\n レベル５上がった！！\n");
				printf(" 能力値が上がった！！お金もらった！！\n\n");
				srand((unsigned)time(NULL));
				player.level += 1;
				player.hp += rand()%150 + 50;
				player.mp += rand()%50 + 30;
				player.power += rand()%100 + 20;
				player.defense += rand()%80 + 20;
				player.money += 5000;
				player.kusuri += 1;
			}
			else if(teki>=60&&teki<70)
			{
				printf(" %s をたおした！！！\n",enemy.name);
				printf("\n レベル６上がった！！\n");
				printf(" 能力値が上がった！！お金もらった！！\n\n");
				srand((unsigned)time(NULL));
				player.level += 6;
				player.hp += rand()%300 + 200;
				player.mp += rand()%30 + 20;
				player.power += rand()%50 + 40;
				player.defense += rand()%50 + 40;
				player.money += 5000;
				player.kusuri += 2;
			}
			else if(teki>=70&&teki<80)
			{
				printf(" %s をたおした！！！\n",enemy.name);
				printf("\n レベル７上がった！！\n");
				printf(" 能力値が上がった！！お金もらった！！\n\n");
				srand((unsigned)time(NULL));
				player.level += 7;
				player.hp += rand()%200 + 100;
				player.mp += rand()%100 + 10;
				player.power += rand()%50 + 10;
				player.defense += rand()%50 + 10;
				player.money += 2000;
				player.kusuri += 3;
			}
			else if(teki>=80&&teki<90)
			{
				printf(" %s をたおした！！！\n",enemy.name);
				printf("\n レベル８上がった！！\n");
				printf(" 能力値が上がった！！お金もらった！！\n\n");
				srand((unsigned)time(NULL));
				player.level += 8;
				player.hp += rand()%500 + 400;
				player.mp += rand()%200 + 100;
				player.power += rand()%100 + 80;
				player.defense += rand()%100 + 80;
				player.money += 30000;
				player.kusuri += 20;
			}		
			else if(teki>=90&&teki<100)
			{
				printf(" %s をたおした！！！\n",enemy.name);
				printf("\n レベル１０上がった！！\n");
				printf(" 能力値が上がった！！お金もらった！！\n\n");
				srand((unsigned)time(NULL));
				player.level += 10;
				player.hp += rand()%500 + 100;
				player.mp += rand()%200 + 10;
				player.power += rand()%100 + 10;
				player.defense += rand()%100 + 10;
				player.money += 8000;
				player.kusuri += 10;
			}
			else if(teki==100)
			{
				printf(" %s をたおした！！！\n",enemy.name);
				printf("\n レベル１００上がった！！\n");
				printf(" 能力値が上がった！！お金もらった！！\n\n");
				srand((unsigned)time(NULL));
				player.level += 100;
				player.hp += rand()%3000 + 1000;
				player.mp += rand()%1000 + 200;
				player.power += rand()%2000 + 1000;
				player.defense += rand()%2000 + 1000;
				player.money += 100000;
				player.kusuri += 100;
			}
		}
		if(fg==0)
		{
			srand((unsigned)time(NULL));
			enemy.power += (rand()%20 + 1)*player.level;
			printf(" %s の攻撃！！",enemy.name);
			printf(" %d のダメージ！！\n",enemy.power-player.defense);
			player.hp -= enemy.power-player.defense;
			enemy.hp = enehp;
		}
		if(player.hp<=0)
		{
			fg=1;
			printf(" %s は敗北しました・・・・・・\n",player.name);
			printf("\n\n ・・・GAME OVER・・・ \n\n\n");
			exit(0);
		}
		printf("==================================================\n");
	}
	fp = fopen("game_4_2_save_data.txt","w");
			fprintf(fp,"%s %d %d %d %d %d %d %d %d\n"
					,player.name
					,player.level
					,player.hp
					,player.mp
					,player.power
					,player.defense
					,player.money
					,player.kusuri
					,player.flag);
	fclose(fp);
	fp = fopen("game_4_2_save_data.txt","r");
	while(fscanf(fp,"%s %d %d %d %d %d %d %d %d",player.name,&player.level,&player.hp,&player.mp,&player.power,&player.defense,&player.money,&player.kusuri,&player.flag) != EOF){
		printf("\n 名前: %s\n レベル: %d\n HP: %d\n MP: %d\n 攻撃 ; %d\n 防御 : %d\n お金: %d\n 薬の数: %d\n 進度: %d\n\n"
						,player.name
						,player.level
						,player.hp
						,player.mp
						,player.power
						,player.defense
						,player.money
						,player.kusuri
						,player.flag);
	}
	fclose(fp);
	printf("==================================================\n");
	printf("\n ・・・・・・バトル終了・・・・・・\n\n");
}

/********** ボスバトル（魔王） **********/
void battle_maou(void)
{
	int hp;
	int mp;
	int power;
	int defense;
	int fg=0;
	int move;
	int kusuri_hp = 1000;
	int kusuri_mp = 100;
	struct character enemy;
	struct character player;
	
	fp = fopen("game_4_2_save_data.txt","r");
		while(fscanf(fp,"%s %d %d %d %d %d %d %d %d",player.name,&player.level,&player.hp,&player.mp,&player.power,&player.defense,&player.money,&player.kusuri,&player.flag) != EOF){
			printf("\n 名前: %s\n レベル: %d\n HP: %d\n MP: %d\n 攻撃 ; %d\n 防御 : %d\n お金: %d\n 薬の数: %d\n 進度: %d\n\n"
						,player.name
						,player.level
						,player.hp
						,player.mp
						,player.power
						,player.defense
						,player.money
						,player.kusuri
						,player.flag);
		}
	fclose(fp);
	
	strncpy(enemy.name,"魔王",sizeof(enemy.name));
	enemy.level = 9999;
	enemy.hp = 20000;
	enemy.mp = 10000;
	enemy.power = 1000;
	enemy.defense = 1000;
	enemy.money = 10000;
	
	printf(" 魔王「私に勝てば世界はお前のものだ。さあ、闘おう。」\n\n");
	printf("==================================================\n");
	while(fg==0)
	{
		printf(" 行動を選択してください\n");
		printf( " 1:攻撃\n"
				" 2:魔法\n"
				" 3:薬を使う\n"
				" 4:様子を見る\n"
				" 5:逃げる\n");
		printf(" 入力：");
		scanf("%d",&move);
		switch(move)
		{
			case 1:
			printf(" %s の攻撃！！",player.name);
			printf(" %d のダメージ！！\n",player.power-enemy.defense);
			enemy.hp -= player.power - enemy.defense;
			break;
			case 2:
			if(player.mp<100)
			{
				printf(" MPが足りません\n");
				break;
			}
			printf(" %s の攻撃！！",player.name);
			printf(" %d のダメージ！！\n",player.power*2 - enemy.defense);
			enemy.hp -= player.power*2 - enemy.defense;
			player.mp -= 100;
			break;
			case 3:
			printf(" %s は薬を使った",player.name);
			printf(" HPとMPが回復した\n");
			player.hp += kusuri_hp;
			player.mp += kusuri_mp;
			break;
			case 4:
			printf(" %s は様子を見た・・・・・・\n",player.name);
			printf(" %s はHPが少し回復した\n",player.name);
			player.hp += 300;
			break;
			case 5:
			printf(" だめだ、逃げられない！！\n");
			printf(" %s はMPが少し回復した\n",player.name);
			player.mp += 30;
			break;
			default:
			break;
		}
		if(enemy.hp<=0)
		{
			fg=1;
			printf(" %s をたおしました\n",enemy.name);
			printf( " レベルが１０上がった！！\n"
					" お金を\10000もらった！！\n");
			player.level += 10;
			player.hp += 1000;
			player.mp += 300;
			player.power += 500;
			player.defense += 500;
			player.money += 100000;
			player.flag = 2;
		}
		if(fg==0)
		{
			srand((unsigned)time(NULL));
			enemy.power += (rand()%30 + 10)*player.level;
			printf(" %s の攻撃！！",enemy.name);
			printf(" %d のダメージ！！\n",enemy.power-player.defense);
			player.hp -= enemy.power - player.defense;
		}
		if(player.hp<=0)
		{
			fg=1;
			printf(" %s は敗北しました・・・・・・\n",player.name);
			exit(0);
		}
	}
	fp = fopen("game_4_2_save_data.txt","w");
	fprintf(fp,"%s %d %d %d %d %d %d %d %d\n"
					,player.name
					,player.level
					,player.hp
					,player.mp
					,player.power
					,player.defense
					,player.money
					,player.kusuri
					,player.flag);
	fclose(fp);
}

/********** 店 **********/
void shop(void)
{
	int shop;
	int fg=0;
	struct character player;
	fp = fopen("game_4_2_save_data.txt","r");
		while(fscanf(fp,"%s %d %d %d %d %d %d %d %d",player.name,&player.level,&player.hp,&player.mp,&player.power,&player.defense,&player.money,&player.kusuri,&player.flag) != EOF){
			printf("\n 名前: %s\n レベル: %d\n HP: %d\n MP: %d\n 攻撃 ; %d\n 防御 : %d\n お金: %d\n 薬の数: %d\n 進度: %d\n\n"
						,player.name
						,player.level
						,player.hp
						,player.mp
						,player.power
						,player.defense
						,player.money
						,player.kusuri
						,player.flag);
		}
	fclose(fp);
	printf("\n==================================================\n");
	printf(" お店にやってきた\n");
	while(fg==0)
	{
		printf(" 何を買いますか\n");
		printf( " 1:薬(100円)\n"
				" 2:剣(1000円)\n"
				" 3:盾(1000円)\n"
				" 4:HPフエール(2000円)\n"
				" 5:MPフエール(3000円)\n"
				" 6:店を出る\n");
		printf(" 入力：");
		scanf("%d",&shop);
		switch(shop)
		{
			case 1:
			if(player.money<100)
			{
				printf(" お金が足りない\n");
				break;
			}
			printf(" 薬を買った\n");
			player.money -= 100;
			player.kusuri += 1;
			break;
			case 2:
			if(player.money<1000)
			{
				printf(" お金が足りない\n");
				break;
			}
			printf(" 剣を買った\n");
			printf(" 攻撃が５０上がった！！");
			player.money -= 1000;
			player.power += 50;
			break;
			case 3:
			if(player.money<1000)
			{
				printf(" お金が足りない\n");
				break;
			}
			printf(" 盾を買った\n");
			printf(" 防御が５０上がった！！");
			player.money -= 1000;
			player.defense += 50;
			break;
			case 4:
			if(player.money<2000)
			{
				printf(" お金が足りない\n");
				break;
			}
			printf(" HPフエールを買った\n");
			printf(" HPの上限が２００上がった！！\n");
			player.money -= 2000;
			player.hp += 200;
			break;
			case 5:
			if(player.money<3000)
			{
				printf(" お金が足りない\n");
				break;
			}
			printf(" MPフエールを買った\n");
			printf(" MPの上限が５０上がった！！\n");
			player.money -= 3000;
			player.mp += 50;
			break;
			case 6:
			printf(" お店を出ます\n");
			fg=1;
			break;
			default:
			printf(" 店を出る\n");
			fg=1;
			break;
		}
		printf("\n");
		fp = fopen("game_4_2_save_data.txt","w");
		fprintf(fp,"%s %d %d %d %d %d %d %d %d\n"
					,player.name
					,player.level
					,player.hp
					,player.mp
					,player.power
					,player.defense
					,player.money
					,player.kusuri
					,player.flag);
		fclose(fp);
		fp = fopen("game_4_2_save_data.txt","r");
		while(fscanf(fp,"%s %d %d %d %d %d %d %d %d",player.name,&player.level,&player.hp,&player.mp,&player.power,&player.defense,&player.money,&player.kusuri,&player.flag) != EOF){
			printf("\n 名前: %s\n レベル: %d\n HP: %d\n MP: %d\n 攻撃 ; %d\n 防御 : %d\n お金: %d\n 薬の数: %d\n 進度: %d\n\n"
						,player.name
						,player.level
						,player.hp
						,player.mp
						,player.power
						,player.defense
						,player.money
						,player.kusuri
						,player.flag);
		}
		fclose(fp);
	}
	printf("==================================================\n");
	fp = fopen("game_4_2_save_data.txt","w");
	fprintf(fp,"%s %d %d %d %d %d %d %d %d\n"
					,player.name
					,player.level
					,player.hp
					,player.mp
					,player.power
					,player.defense
					,player.money
					,player.kusuri
					,player.flag);
	fclose(fp);
	fp = fopen("game_4_2_save_data.txt","r");
	while(fscanf(fp,"%s %d %d %d %d %d %d %d %d",player.name,&player.level,&player.hp,&player.mp,&player.power,&player.defense,&player.money,&player.kusuri,&player.flag) != EOF){
		printf("\n 名前: %s\n レベル: %d\n HP: %d\n MP: %d\n 攻撃 ; %d\n 防御 : %d\n お金: %d\n 薬の数: %d\n 進度: %d\n\n"
						,player.name
						,player.level
						,player.hp
						,player.mp
						,player.power
						,player.defense
						,player.money
						,player.kusuri
						,player.flag);
	}
	fclose(fp);
}

/********** キャラクター作成 **********/
void make_char(void)
{
	struct character player;
	for(;;)
	{
		fp = fopen("game_4_2_save_data.txt","r");
		while(fscanf(fp,"%s %d %d %d %d %d %d %d %d",player.name,&player.level,&player.hp,&player.mp,&player.power,&player.defense,&player.money,&player.kusuri,&player.flag) != EOF){
			printf("\n 名前: %s\n レベル: %d\n HP: %d\n MP: %d\n 攻撃 ; %d\n 防御 : %d\n お金: %d\n 薬の数: %d\n 進度: %d\n\n"
						,player.name
						,player.level
						,player.hp
						,player.mp
						,player.power
						,player.defense
						,player.money
						,player.kusuri
						,player.flag);
		}
		fclose(fp);
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
			player.mp = rand()%30 + 1;
			player.power = rand()%50 + 10;
			player.defense = 50 - (rand()%50 + 5);
			player.money = (100 - player.hp) * 100;
			player.kusuri = 0;
			player.flag = 1;
	
			fp = fopen("game_4_2_save_data.txt","w");
			fprintf(fp,"%s %d %d %d %d %d %d %d %d\n"
					,player.name
					,player.level
					,player.hp
					,player.mp
					,player.power
					,player.defense
					,player.money
					,player.kusuri
					,player.flag);
			fclose(fp);
	
			printf("\n 名前: %s\n レベル: %d\n HP: %d\n MP: %d\n 攻撃: %d\n 防御: %d\n お金: %d\n 薬の数: %d\n 進度: %d\n\n"
					,player.name
					,player.level
					,player.hp
					,player.mp
					,player.power
					,player.defense
					,player.money
					,player.kusuri
					,player.flag);
			
			printf( " 以上でよろしいですか\n"
					" 0:はい  1:いいえ\n"
					" 入力：");
			scanf("%d",&fg2);
			if(fg2==0) fg=1;
			if(fg==1)
			{
				flag=1;
				break;
			}
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

/********** senntaku **********/
int senntaku(void)
{
	int moution;
	int fg=0;
	struct character player;
	fp = fopen("game_4_2_save_data.txt","r");
	while(fscanf(fp,"%s %d %d %d %d %d %d %d %d",player.name,&player.level,&player.hp,&player.mp,&player.power,&player.defense,&player.money,&player.kusuri,&player.flag) != EOF){
		printf("\n 名前: %s\n レベル: %d\n HP: %d\n MP: %d\n 攻撃 ; %d\n 防御 : %d\n お金: %d\n 薬の数: %d\n 進度: %d\n\n"
						,player.name
						,player.level
						,player.hp
						,player.mp
						,player.power
						,player.defense
						,player.money
						,player.kusuri
						,player.flag);
		}
	fclose(fp);
	
	story_1();
	
	while(fg==0)
	{
		if(player.flag==2)
		{
			printf(" \n\n\t！！！！！ゲームクリア！！！！！\n\n");
			return 0;
		}
		printf("==================================================\n");
		printf(" 何をしますか\n");
		printf( " 1:戦いへ\n"
				" 2:ボス戦\n"
				" 3:お店に行く\n"
				" 4:終了\n"
				" 5:ヘルプ\n");
		printf(" 入力：");
		scanf("%d",&moution);
		switch(moution)
		{
			case 1:
			battle();
			break;
			case 2:
			battle_maou();
			break;
			case 3:
			shop();
			break;
			case 4:
			fg=1;
			break;
			case 5:
			help();
			break;
		}
	}
}


/********** main関数 **********/
int main(void)
{
	printf(" \n\nゲームを開始します\n\n");
	make_char();
	senntaku();	
	printf(" \n\nゲームを終了します\n\n");
	return 0;
}