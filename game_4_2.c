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
int flag = 0; //story�̃Z�[�u�Ɏg��(main�֐�)
/* �L�����N�^�[�i�ύX�l����j */
struct character
{
	char name[64];
	int level;
	int hp;
	int mp;
	int power;
	int defense;
	int money;
	int kusuri;//��
	int flag;//�i�x
};

void help(void)
{
	struct character player;
	printf("==============================\n");
	printf(" 2016.2.21���_\n");
	fp = fopen("game_4_2_save_data.txt","r");
		while(fscanf(fp,"%s %d %d %d %d %d %d %d %d",player.name,&player.level,&player.hp,&player.mp,&player.power,&player.defense,&player.money,&player.kusuri,&player.flag) != EOF){
			printf("\n ���O: %s\n ���x��: %d\n HP: %d\n MP: %d\n �U�� ; %d\n �h�� : %d\n ����: %d\n ��̐�: %d\n �i�x: %d\n\n"
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
	printf( "\n\n �����ă��x���グ�āA�{�X�֒��ށB\n\n"
			" ���A�C�e��������\n\n"
			" �E��FHP��MP���񕜂���\n"
			" �E���F�U���̍ő�l���グ��\n"
			" �E���F�h��̍ő�l���グ��\n"
			" �EHP�t�G�[���FHP�̍ő�l���グ��\n"
			" �EMP�t�G�[���FMP�̍ő�l���グ��\n\n\n");
	printf("==============================\n");
}

void story_1(void)
{
	printf("=================================================\n");
	printf( "\n\t���͗E�҂ƂȂ����B\n"
			"\n\t�g���͖��������������ƁB\n"
			"\n\t���̎g�����ʂ������߁A\n"
			"\n\t���͗��ɏo���B\n\n");
	printf("=================================================\n");
}

/********** �o�g���V�X�e���i�ύX�l����j **********/
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
			printf("\n ���O: %s\n ���x��: %d\n HP: %d\n MP: %d\n �U�� ; %d\n �h�� : %d\n ����: %d\n ��̐�: %d\n �i�x: %d\n\n"
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
	
	printf(" �I�I�I�o�g���J�n�I�I�I\n\n");
	/* �o�g����A���ɖ߂�����*/
	hp = player.hp;
	mp = player.mp;
	power = player.power;
	defense = player.defense;
	/***** �G���� *****/
	srand((unsigned)time(NULL));
	teki = rand()%100 + 1;
	if(teki>=1&&teki<10)
	{
		strncpy(enemy.name,"������낤",sizeof(enemy.name));
		enemy.level = 1;
		enemy.hp = 1;
		enemy.power = 1;
		enemy.defense = 1;
	}
	else if(teki>=10&&teki<20)
	{
		strncpy(enemy.name,"���ѓD�_",sizeof(enemy.name));
		enemy.level = 2;
		enemy.hp = 10;
		enemy.power = 10;
		enemy.defense = 10;
	}
	else if(teki>=20&&teki<30)
	{
		strncpy(enemy.name,"���ԃR�b�y�p��",sizeof(enemy.name));
		enemy.level = 3;
		enemy.hp = 20;
		enemy.power = 20;
		enemy.defense = 20;
	}
	else if(teki>=40&&teki<50)
	{
		strncpy(enemy.name,"����������",sizeof(enemy.name));
		enemy.level = 4;
		enemy.hp = 30;
		enemy.power = 30;
		enemy.defense = 30;
	}
	else if(teki>=50&&teki<60)
	{
		strncpy(enemy.name,"�₳�����Ђ�",sizeof(enemy.name));
		enemy.level = 5;
		enemy.hp = 40;
		enemy.power = 40;
		enemy.defense = 40;
	}
	else if(teki>=60&&teki<70)
	{
		strncpy(enemy.name,"����",sizeof(enemy.name));
		enemy.level = 6;
		enemy.hp = 50;
		enemy.power = 50;
		enemy.defense = 50;
	}
	else if(teki>=70&&teki<80)
	{
		strncpy(enemy.name,"���ꂽ",sizeof(enemy.name));
		enemy.level = 7;
		enemy.hp = 10;
		enemy.power = 200;
		enemy.defense = 10;
	}
	else if(teki>=80&&teki<90)
	{
		strncpy(enemy.name,"�|������",sizeof(enemy.name));
		enemy.level = 8;
		enemy.hp = 200;
		enemy.power = 200;
		enemy.defense = 100;
	}		
	else if(teki>=90&&teki<100)
	{
		strncpy(enemy.name,"�����㗝",sizeof(enemy.name));
		enemy.level = 10;
		enemy.hp = 300;
		enemy.power = 150;
		enemy.defense = 100;
	}
	else if(teki==100)
	{
		strncpy(enemy.name,"���̖��́E�E�E�E�E",sizeof(enemy.name));
		enemy.level = 100;
		enemy.hp = 10000;
		enemy.power = 1000;
		enemy.defense+= 1000;
	}
	/***** �G�̔\�͌��� *****/
	srand((unsigned)time(NULL));
	enemy.level += player.level * (rand()%20+1);
	enemy.hp += enemy.level * 5;
	enemy.power += enemy.level;
	enemy.defense += enemy.level;
	
	printf(" ���x��%d �� %s �������ꂽ�I�I\n\n",enemy.level,enemy.name);
	/********** �o�g���X�^�[�g **********/
	printf("==================================================\n");
	while(fg==0)
	{
		printf(" �s����I�����Ă�������\n");
		printf( " 1:�U��\n"
				" 2:���@\n"
				" 3:����g��\n"
				" 4:�l�q������\n"
				" 5:������\n");
		printf(" ���́F");
		scanf("%d",&move);
		switch(move)
		{
			case 1:
			srand((unsigned)time(NULL));
			player.power += rand()%500 + 1;
			printf(" %s �̍U���I�I",player.name);
			printf(" %d �̃_���[�W�I�I\n",player.power);
			enemy.hp -= player.power;
			player.power = power;
			break;
			case 2:
			if(player.mp<50)
			{
				printf(" MP������܂���\n");
				break;
			}
			player.power += rand()%1000 + 1;
			printf(" %s �̍U���I�I",player.name);
			printf(" %d �̃_���[�W�I�I\n",(player.power*2)-enemy.defense);
			enemy.hp -= (player.power*2)-enemy.defense;
			player.mp -= 50;
			player.power = power;
			break;
			case 3:
			printf(" %s �͖���g����",player.name);
			printf(" HP��MP���񕜂���\n");
			player.hp = hp;
			player.mp = mp;
			break;
			case 4:
			printf(" %s �͗l�q�������E�E�E�E�E�E\n",player.name);
			printf(" %s ��HP�������񕜂���\n",player.name);
			player.hp += 300;
			break;
			case 5:
			printf(" ���߂��A�������Ȃ��I�I\n");
			printf(" %s ��MP�������񕜂���\n",player.name);
			player.mp += 30;
			break;
			default:
			break;
		}
		if(enemy.hp<=0)
		{
			fg=1;
			/* �o�g���O�̒l�ɖ߂�*/
			player.hp = hp;
			player.mp = mp;
			player.power = power;
			player.defense = defense;
			/********** �o�g����̃��x���A�b�v�Ƃ� **********/
			if(teki>=1&&teki<10)
			{
				printf(" %s �����������I�I�I\n",enemy.name);
				printf("\n ���x���P�オ�����I�I\n");
				printf(" �\�͒l���オ�����I�I������������I�I\n\n");
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
				printf(" %s �����������I�I�I\n",enemy.name);
				printf("\n ���x���Q�オ�����I�I\n");
				printf(" �\�͒l���オ�����I�I������������I�I\n\n");
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
				printf(" %s �����������I�I�I\n",enemy.name);
				printf("\n ���x���R�オ�����I�I\n");
				printf(" �\�͒l���オ�����I�I������������I�I\n\n");
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
				printf(" %s �����������I�I�I\n",enemy.name);
				printf("\n ���x���S�オ�����I�I\n");
				printf(" �\�͒l���オ�����I�I������������I�I\n\n");
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
				printf(" %s �����������I�I�I\n",enemy.name);
				printf("\n ���x���T�オ�����I�I\n");
				printf(" �\�͒l���オ�����I�I������������I�I\n\n");
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
				printf(" %s �����������I�I�I\n",enemy.name);
				printf("\n ���x���U�オ�����I�I\n");
				printf(" �\�͒l���オ�����I�I������������I�I\n\n");
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
				printf(" %s �����������I�I�I\n",enemy.name);
				printf("\n ���x���V�オ�����I�I\n");
				printf(" �\�͒l���オ�����I�I������������I�I\n\n");
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
				printf(" %s �����������I�I�I\n",enemy.name);
				printf("\n ���x���W�オ�����I�I\n");
				printf(" �\�͒l���オ�����I�I������������I�I\n\n");
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
				printf(" %s �����������I�I�I\n",enemy.name);
				printf("\n ���x���P�O�オ�����I�I\n");
				printf(" �\�͒l���オ�����I�I������������I�I\n\n");
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
				printf(" %s �����������I�I�I\n",enemy.name);
				printf("\n ���x���P�O�O�オ�����I�I\n");
				printf(" �\�͒l���オ�����I�I������������I�I\n\n");
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
			printf(" %s �̍U���I�I",enemy.name);
			printf(" %d �̃_���[�W�I�I\n",enemy.power-player.defense);
			player.hp -= enemy.power-player.defense;
			enemy.hp = enehp;
		}
		if(player.hp<=0)
		{
			fg=1;
			printf(" %s �͔s�k���܂����E�E�E�E�E�E\n",player.name);
			printf("\n\n �E�E�EGAME OVER�E�E�E \n\n\n");
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
		printf("\n ���O: %s\n ���x��: %d\n HP: %d\n MP: %d\n �U�� ; %d\n �h�� : %d\n ����: %d\n ��̐�: %d\n �i�x: %d\n\n"
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
	printf("\n �E�E�E�E�E�E�o�g���I���E�E�E�E�E�E\n\n");
}

/********** �{�X�o�g���i�����j **********/
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
			printf("\n ���O: %s\n ���x��: %d\n HP: %d\n MP: %d\n �U�� ; %d\n �h�� : %d\n ����: %d\n ��̐�: %d\n �i�x: %d\n\n"
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
	
	strncpy(enemy.name,"����",sizeof(enemy.name));
	enemy.level = 9999;
	enemy.hp = 20000;
	enemy.mp = 10000;
	enemy.power = 1000;
	enemy.defense = 1000;
	enemy.money = 10000;
	
	printf(" �����u���ɏ��Ăΐ��E�͂��O�̂��̂��B�����A�������B�v\n\n");
	printf("==================================================\n");
	while(fg==0)
	{
		printf(" �s����I�����Ă�������\n");
		printf( " 1:�U��\n"
				" 2:���@\n"
				" 3:����g��\n"
				" 4:�l�q������\n"
				" 5:������\n");
		printf(" ���́F");
		scanf("%d",&move);
		switch(move)
		{
			case 1:
			printf(" %s �̍U���I�I",player.name);
			printf(" %d �̃_���[�W�I�I\n",player.power-enemy.defense);
			enemy.hp -= player.power - enemy.defense;
			break;
			case 2:
			if(player.mp<100)
			{
				printf(" MP������܂���\n");
				break;
			}
			printf(" %s �̍U���I�I",player.name);
			printf(" %d �̃_���[�W�I�I\n",player.power*2 - enemy.defense);
			enemy.hp -= player.power*2 - enemy.defense;
			player.mp -= 100;
			break;
			case 3:
			printf(" %s �͖���g����",player.name);
			printf(" HP��MP���񕜂���\n");
			player.hp += kusuri_hp;
			player.mp += kusuri_mp;
			break;
			case 4:
			printf(" %s �͗l�q�������E�E�E�E�E�E\n",player.name);
			printf(" %s ��HP�������񕜂���\n",player.name);
			player.hp += 300;
			break;
			case 5:
			printf(" ���߂��A�������Ȃ��I�I\n");
			printf(" %s ��MP�������񕜂���\n",player.name);
			player.mp += 30;
			break;
			default:
			break;
		}
		if(enemy.hp<=0)
		{
			fg=1;
			printf(" %s ���������܂���\n",enemy.name);
			printf( " ���x�����P�O�オ�����I�I\n"
					" ������\10000��������I�I\n");
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
			printf(" %s �̍U���I�I",enemy.name);
			printf(" %d �̃_���[�W�I�I\n",enemy.power-player.defense);
			player.hp -= enemy.power - player.defense;
		}
		if(player.hp<=0)
		{
			fg=1;
			printf(" %s �͔s�k���܂����E�E�E�E�E�E\n",player.name);
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

/********** �X **********/
void shop(void)
{
	int shop;
	int fg=0;
	struct character player;
	fp = fopen("game_4_2_save_data.txt","r");
		while(fscanf(fp,"%s %d %d %d %d %d %d %d %d",player.name,&player.level,&player.hp,&player.mp,&player.power,&player.defense,&player.money,&player.kusuri,&player.flag) != EOF){
			printf("\n ���O: %s\n ���x��: %d\n HP: %d\n MP: %d\n �U�� ; %d\n �h�� : %d\n ����: %d\n ��̐�: %d\n �i�x: %d\n\n"
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
	printf(" ���X�ɂ���Ă���\n");
	while(fg==0)
	{
		printf(" ���𔃂��܂���\n");
		printf( " 1:��(100�~)\n"
				" 2:��(1000�~)\n"
				" 3:��(1000�~)\n"
				" 4:HP�t�G�[��(2000�~)\n"
				" 5:MP�t�G�[��(3000�~)\n"
				" 6:�X���o��\n");
		printf(" ���́F");
		scanf("%d",&shop);
		switch(shop)
		{
			case 1:
			if(player.money<100)
			{
				printf(" ����������Ȃ�\n");
				break;
			}
			printf(" ��𔃂���\n");
			player.money -= 100;
			player.kusuri += 1;
			break;
			case 2:
			if(player.money<1000)
			{
				printf(" ����������Ȃ�\n");
				break;
			}
			printf(" ���𔃂���\n");
			printf(" �U�����T�O�オ�����I�I");
			player.money -= 1000;
			player.power += 50;
			break;
			case 3:
			if(player.money<1000)
			{
				printf(" ����������Ȃ�\n");
				break;
			}
			printf(" ���𔃂���\n");
			printf(" �h�䂪�T�O�オ�����I�I");
			player.money -= 1000;
			player.defense += 50;
			break;
			case 4:
			if(player.money<2000)
			{
				printf(" ����������Ȃ�\n");
				break;
			}
			printf(" HP�t�G�[���𔃂���\n");
			printf(" HP�̏�����Q�O�O�オ�����I�I\n");
			player.money -= 2000;
			player.hp += 200;
			break;
			case 5:
			if(player.money<3000)
			{
				printf(" ����������Ȃ�\n");
				break;
			}
			printf(" MP�t�G�[���𔃂���\n");
			printf(" MP�̏�����T�O�オ�����I�I\n");
			player.money -= 3000;
			player.mp += 50;
			break;
			case 6:
			printf(" ���X���o�܂�\n");
			fg=1;
			break;
			default:
			printf(" �X���o��\n");
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
			printf("\n ���O: %s\n ���x��: %d\n HP: %d\n MP: %d\n �U�� ; %d\n �h�� : %d\n ����: %d\n ��̐�: %d\n �i�x: %d\n\n"
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
		printf("\n ���O: %s\n ���x��: %d\n HP: %d\n MP: %d\n �U�� ; %d\n �h�� : %d\n ����: %d\n ��̐�: %d\n �i�x: %d\n\n"
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

/********** �L�����N�^�[�쐬 **********/
void make_char(void)
{
	struct character player;
	for(;;)
	{
		fp = fopen("game_4_2_save_data.txt","r");
		while(fscanf(fp,"%s %d %d %d %d %d %d %d %d",player.name,&player.level,&player.hp,&player.mp,&player.power,&player.defense,&player.money,&player.kusuri,&player.flag) != EOF){
			printf("\n ���O: %s\n ���x��: %d\n HP: %d\n MP: %d\n �U�� ; %d\n �h�� : %d\n ����: %d\n ��̐�: %d\n �i�x: %d\n\n"
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
	
			printf("\n ���O: %s\n ���x��: %d\n HP: %d\n MP: %d\n �U��: %d\n �h��: %d\n ����: %d\n ��̐�: %d\n �i�x: %d\n\n"
					,player.name
					,player.level
					,player.hp
					,player.mp
					,player.power
					,player.defense
					,player.money
					,player.kusuri
					,player.flag);
			
			printf( " �ȏ�ł�낵���ł���\n"
					" 0:�͂�  1:������\n"
					" ���́F");
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
			printf(" �G���[\n");
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
		printf("\n ���O: %s\n ���x��: %d\n HP: %d\n MP: %d\n �U�� ; %d\n �h�� : %d\n ����: %d\n ��̐�: %d\n �i�x: %d\n\n"
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
			printf(" \n\n\t�I�I�I�I�I�Q�[���N���A�I�I�I�I�I\n\n");
			return 0;
		}
		printf("==================================================\n");
		printf(" �������܂���\n");
		printf( " 1:�킢��\n"
				" 2:�{�X��\n"
				" 3:���X�ɍs��\n"
				" 4:�I��\n"
				" 5:�w���v\n");
		printf(" ���́F");
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


/********** main�֐� **********/
int main(void)
{
	printf(" \n\n�Q�[�����J�n���܂�\n\n");
	make_char();
	senntaku();	
	printf(" \n\n�Q�[�����I�����܂�\n\n");
	return 0;
}