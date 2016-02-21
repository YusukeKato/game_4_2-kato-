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
/* �L�����N�^�[�i�ύX�l����j */
struct character
{
	char name[64];
	int level;
	int hp;
	int power;
};

/********** �o�g���V�X�e���i�ύX�l����j **********/
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
	
	printf(" �I�I�I�o�g���J�n�I�I�I\n\n");
	/* �o�g����A���ɖ߂�����*/
	hp = player.hp;
	power = player.power;
	/* �G�̔\�͌���*/
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
	/* �G���� */
	srand((unsigned)time(NULL));
	teki = rand()%100 + 1;
	if(teki>=1&&teki<=30)
	{
		strncpy(enemy.name,"������낤",sizeof(enemy.name));
	}
	else if(teki>=31&&teki<=50)
	{
		strncpy(enemy.name,"���ѓD�_",sizeof(enemy.name));
		enemy.level += 1;
		enemy.hp += 10;
		enemy.power += 5;
	}
	else if(teki>=51&&teki<=60)
	{
		strncpy(enemy.name,"�|������",sizeof(enemy.name));
		enemy.level += 0;
		enemy.hp += 0;
		enemy.power += 0;
	}
	else if(teki>=61&&teki<=85)
	{
		strncpy(enemy.name,"�₳�����Ђ�",sizeof(enemy.name));
		enemy.level += 3;
		enemy.hp += 50;
		enemy.power += 25;
	}		
	else if(teki>=86&&teki<=100)
	{
		strncpy(enemy.name,"�����㗝",sizeof(enemy.name));
		enemy.level += 5;
		enemy.hp += 100;
		enemy.power += 50;
	}
	if(player.level>80)
	{
		strncpy(enemy.name,"���X�{�X����",sizeof(enemy.name));
		enemy.level = 100;
		enemy.hp += 1000;
		enemy.power += 500;
	}
	printf(" ���x��%d �� %s �������ꂽ�I�I\n",enemy.level,enemy.name);
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
			printf(" \n�G���[\n\n");
			exit(0);
		}
		printf(" %s �̍U���I�I",player.name);
		printf(" %d �̃_���[�W�I�I\n",player.power);
		enemy.hp = enemy.hp - player.power;
		if(enemy.hp<=0)
		{
			/* �o�g���O�ɒl��߂� */
			player.hp = hp;
			player.power = power;
			
			printf(" %s �͏��������I�I\n",player.name);
			if(teki>=1&&teki<=30)
			{
				printf(" ���x�����P�オ�����I�I\n");
				player.level += 1;
				player.hp += 10;
				player.power += 5;
			}
			else if(teki>=31&&teki<=50)
			{
				printf(" ���x�����Q�オ�����I�I\n");
				player.level += 3;
				player.hp += 30;
				player.power += 15;
			}
			else if(teki>=51&&teki<=60)
			{
				printf(" ���x�����P�O�オ�����I�I\n");
				player.level += 20;
				player.hp += 200;
				player.power += 100;
			}
			else if(teki>=61&&teki<=85)
			{
				printf(" ���x�����R�オ�����I�I\n");
				player.level += 5;
				player.hp += 50;
				player.power += 25;
			}
			else if(teki>=86&&teki<=100)
			{
				printf(" ���x�����T�オ�����I�I\n");
				player.level += 10;
				player.hp += 100;
				player.power += 50;
			}
			if(player.level>80)
			{
				printf("\n\n �I�I�I�I�I�Q�[���N���A�I�I�I�I�I\n\n\n");
				exit(0);
			}
			break;
		}
		printf(" %s �̍U���I�I",enemy.name);
		printf(" %d �̃_���[�W�I�I\n",enemy.power);
		player.hp = player.hp - enemy.power;
		if(player.hp<=0)
		{
			printf("\n %s �͔s�k�����E�E�E�E�E�E\n\n",player.name);
			printf(" �Q�[�����I�����܂�\n");
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
	printf(" �E�E�E�E�E�E�o�g���I���E�E�E�E�E�E\n");
}

/********** �L�����N�^�[�쐬 **********/
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
		printf( " �V�����L�����N�^�[�����܂���\n"
				" 0:�͂�  1:������\n"
				" ���́F");
		scanf("%d",&fg);
		if(fg==1) break;
		else if(fg==0)
		{
			printf(" ���O����͂��Ă�������:");
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
			
			printf( " �ȏ�ł�낵���ł���\n"
					" 0:�͂�  1:������\n"
					" ���́F");
			scanf("%d",&fg2);
			if(fg2==0) fg=1;
			if(fg==1) break;
		}
		else
		{
			printf(" �G���[\n");
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
	printf(" \n\n�Q�[�����n�߂܂�\n");
	make_char();
	story();
	printf(" \n\n�Q�[�����I�����܂�\n\n");
	return 0;
}