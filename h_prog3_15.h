//include
#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#include <Windows.h>
#include <iostream>
#include<string.h>
#include <time.h>

//�����F��`
using namespace std;
#define     COL_BLACK   0x00
#define     COL_DARK_BLUE       0x01
#define     COL_DARK_GREEN 0x02
#define     COL_DARK_CYAN       0x03
#define     COL_DARK_RED     0x04
#define     COL_DARK_VIOLET 0x05
#define     COL_DARK_YELLOW   0x06
#define     COL_GRAY 0x07
#define     COL_LIGHT_GRAY      0x08
#define     COL_BLUE     0x09
#define     COL_GREEN   0x0a
#define     COL_CYAN     0x0b
#define     COL_RED      0x0c
#define     COL_VIOLET  0x0d
#define     COL_YELLOW 0x0e
#define     COL_WHITE   0x0f
#define     COL_INTENSITY     0x08 
#define     COL_RED_MASK     0x04
#define     COL_GREEN_MASK 0x02 
#define     COL_BLUE_MASK   0x01

//�e��`
#define MAX_IDOL 10//�ő�A�C�h����
#define EVENT 100//�C�x���g��
#define RANDOM 3//�����_��
#define TEXTDEF 250//�ő啶����

//�e��`
#define IDOL_1 1	//1�Ԗڂ̃A�C�h��
#define IDOL_2 2	//2�Ԗڂ̃A�C�h��
#define IDOL_3 3	//3�Ԗڂ̃A�C�h��
#define IDOL_4 4	//4�Ԗڂ̃A�C�h��
#define IDOL_5 5	//5�Ԗڂ̃A�C�h��
#define IDOL_6 6	//6�Ԗڂ̃A�C�h��
#define IDOL_7 7	//7�Ԗڂ̃A�C�h��
#define IDOL_8 8	//8�Ԗڂ̃A�C�h��
#define IDOL_9 9	//9�Ԗڂ̃A�C�h��

//�A�C�h���̃f�[�^���i�[����\����IDOL
typedef struct{
	char    name[TEXTDEF];	//      
    int     rank;			//      
    int     fun;			//      
    int     tension;		//      
	int		fatigue;		//
	int     status[3];		//		
}IDOL;

//�e�L�X�g�f�[�^���i�[����\����IDOL�QTEXT
typedef struct{
	char text[MAX_IDOL][EVENT][RANDOM][TEXTDEF];
}IDOL_TEXT;

//�Z�[�u�f�[�^���i�[����\����SaveData
typedef struct{
	int play_days;
	int play_idol;
	int money;
	IDOL idol;
}SaveData;

