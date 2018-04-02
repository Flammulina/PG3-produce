//include
#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#include <Windows.h>
#include <iostream>
#include<string.h>
#include <time.h>

//文字色定義
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

//各定義
#define MAX_IDOL 10//最大アイドル数
#define EVENT 100//イベント数
#define RANDOM 3//ランダム
#define TEXTDEF 250//最大文字数

//各定義
#define IDOL_1 1	//1番目のアイドル
#define IDOL_2 2	//2番目のアイドル
#define IDOL_3 3	//3番目のアイドル
#define IDOL_4 4	//4番目のアイドル
#define IDOL_5 5	//5番目のアイドル
#define IDOL_6 6	//6番目のアイドル
#define IDOL_7 7	//7番目のアイドル
#define IDOL_8 8	//8番目のアイドル
#define IDOL_9 9	//9番目のアイドル

//アイドルのデータを格納する構造体IDOL
typedef struct{
	char    name[TEXTDEF];	//      
    int     rank;			//      
    int     fun;			//      
    int     tension;		//      
	int		fatigue;		//
	int     status[3];		//		
}IDOL;

//テキストデータを格納する構造体IDOL＿TEXT
typedef struct{
	char text[MAX_IDOL][EVENT][RANDOM][TEXTDEF];
}IDOL_TEXT;

//セーブデータを格納する構造体SaveData
typedef struct{
	int play_days;
	int play_idol;
	int money;
	IDOL idol;
}SaveData;

