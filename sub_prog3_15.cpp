#include "h_prog3_15.h"

int main(){
	IDOL_TEXT idoltext;
	//char型ポインタ三次元配列を宣言し、初期化する
	char *setText[MAX_IDOL][EVENT][RANDOM]={""};
	for(int i=0;i<MAX_IDOL;i++){
		for(int j=0;j<EVENT;j++){
			for(int k=0;k<RANDOM;k++){
				setText[i][j][k]="";
			}
		}
	}
	
	/*
	アイドルのテキストを設定します
	[X][ ][ ] 各アイドルの番号です 0番はシステム用です
	[ ][X][ ] 各イベント毎に振り分けられています
	[ ][ ][X] 基本は0番で表示します
			  1イベント内で複数のテキストの場合、またランダムに変化する場合にはその分だけ使用します
	
	各イベント
	0:0/名前 1/自己紹介 2/
	1:挨拶・テンション高
	2:挨拶・テンション中
	3:挨拶・テンション低
	4:ふれあい
	*/
	//システム側で使用
	setText[0][0][0]="こんにちは！";
	setText[0][0][1]="こんばんは！";
	//1番目のアイドルのテキスト
	setText[1][0][0]="藤井結香";
	setText[1][0][1]="「ええと、はじめまして！私は藤井結香と申します！\n  まだまだ右も左も分からない未熟者ですが、どうぞよろしくお願いします！」";
	setText[1][1][0]="「おはようございます！今日も良い天気ですね♪」";
	setText[1][1][1]="「今日のお昼ご飯は何にしようかな～」";
	setText[1][1][2]="「千里の道も一歩から！今日も頑張ります！」";
	setText[0][4][0]="彼女に目標を聞いてみた";
	setText[1][4][0]="「私の目標ですか？もちろん、自分が辿り着けるところまでトップを目指すことです！」";

	//文字列をコピーする
	for(int i=0;i<MAX_IDOL;i++){
		for(int j=0;j<EVENT;j++){
			for(int k=0;k<RANDOM;k++){
				strcpy(idoltext.text[i][j][k],setText[i][j][k]);
			}
		}
	}
	
	//printf("%s\n",idoltext.text[1][0][1]);
	//ファイルを書き込む
	FILE *fp = fopen("dat_prog3_15.dat", "wb" );
    if( fp == NULL ){
                return 0;
        }
    fwrite( &idoltext, sizeof(idoltext), 1, fp );
    fclose(fp);
    return 0;
}