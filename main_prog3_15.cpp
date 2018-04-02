#include "h_prog3_15.h"

IDOL p_idol;		//IDOL型を宣言 アイドルの各パラメータを格納する
SaveData Data;		//SaveData型を宣言 セーブデータを格納する
IDOL_TEXT idoltext;	//IDOL_TEXT型を宣言 テキストデータを格納する

//文字色変化を行う関数setColor
void setColor(int col){
    HANDLE hCons = GetStdHandle( STD_OUTPUT_HANDLE );
    WORD attr = 0;
    if( col & COL_INTENSITY )
        attr |= FOREGROUND_INTENSITY;
    if( col & COL_RED_MASK )
        attr |= FOREGROUND_RED;
    if( col & COL_GREEN_MASK )
        attr |= FOREGROUND_GREEN;
    if( col & COL_BLUE_MASK )
        attr |= FOREGROUND_BLUE;
    SetConsoleTextAttribute(hCons, attr);
}

//テキストデータを読み取る関数loadText
void loadText(){
	FILE *fp = fopen("dat_prog3_15.dat", "rb" );
    fread( &idoltext, sizeof(idoltext), 1, fp );
    fclose(fp);
}

//ゲーム開始時の選択を行う関数modeSelect
void modeSelect(){
	setColor(COL_WHITE);
	system("cls");
	printf("|-----------------------------------------------------------------------------|\n");
	printf("|\t\t\tアイドルプロデュースゲーム(仮)\t\t\t      |\n");
	printf("|-----------------------------------------------------------------------------|\n");
	Sleep(1000);
	loadText();
    setColor(COL_CYAN);
	printf("\t\t\tモードを選んでください\n");
	setColor(COL_WHITE);
	printf("\t\t\t1:はじめから\n");
	printf("\t\t\t2:つづきから\n");
	printf("\t\t\t3:おわる\n");
}

//modeSelect関数で操作し行動を分岐する関数start
int start(){
	modeSelect();
	char text;
	int a = 0;
	while(a==0){
		fflush(stdin);
		scanf("%c",&text);
		if(text=='1'){
			printf("ゲームを開始します\n");
			a=1;
		}else if(text=='2'){
			printf("ファイル名を入力してください(ファイル名の最後は.datです)\n");
			char fileName[60];
			fflush(stdin);
			scanf("%s",fileName);
			FILE *fp = fopen( fileName, "rb" );//バイナリファイルを開く
      		if( fp == NULL ){
       	    	return 0;
       	 	}
       	 	fread( &Data, sizeof(Data), 1, fp );
        	fclose( fp );
			Sleep(1000);
			//system("cls");
			//printf("%d %d %d\n%s %d %d %d %d %d %d %d\n",Data.play_days,Data.play_idol,Data.money,Data.idol.name,Data.idol.rank,Data.idol.fun,Data.idol.tension,Data.idol.fatigue,Data.idol.status[0],Data.idol.status[1],Data.idol.status[2]);
			p_idol=Data.idol;
			a=2;
		}else if(text=='3'){
			a=3;
		}else{
			//printf("正しい数値を入れてください！\n");
			a=0;
		}

	}
	return a;
}

//文字列を再び表示するための関数reTry
void reTry(){
	printf("\t\tあなたはどんなアイドルがお好きですか？\n\n");
	setColor(COL_RED);
	printf("\t\t1:明るく前向きなアイドル\n");
	setColor(COL_CYAN);
	printf("\t\t2:クールでストイックなアイドル(未実装)\n");
	setColor(COL_YELLOW);
	printf("\t\t3:個性的でマイペースなアイドル(未実装)\n");
	setColor(COL_LIGHT_GRAY);
	printf("\t\t4:自分のアイドルは自分で見つける(未実装)\n");
	setColor(COL_WHITE);
}

//アイドルを選択する関数idol_Select
void idol_Select(){
	reTry();
	char text1,text2;
	int a = 0;
	while(1){
		fflush(stdin);
		scanf("%c",&text1);
		if(text1=='1'){
			
			printf("アイドル名：%s\n",idoltext.text[1][0][0]);
			printf("%s\n",idoltext.text[1][0][1]);
			printf("このアイドルではじめますか？\n");
			printf("1:yes\t0:no\n");
			fflush(stdin);
			scanf("%c",&text2);
			if(text2=='1'){
				//キャラクターの個人データを設定
				strcpy(p_idol.name,idoltext.text[1][0][0]);
				Data.play_idol=IDOL_1;
				p_idol.status[0]=30;
				p_idol.status[1]=20;
				p_idol.status[2]=40;
				break;
			}else{
				reTry();
			}
			
		}else{
			
		}
	}
	printf("アイドルを登録します！\n");
	//初期ステータスを決定
	p_idol.rank=1;
	p_idol.fun=1;
	p_idol.tension=1;
	p_idol.fatigue=0;
	Data.play_days=1;
	Data.money=100000;
	
	printf("===============================================================================\n");
	printf("\t\t\tオープニング挿入予定\n");
	printf("===============================================================================\n");
	Sleep(1000);
	printf("\n\n\n\n\n");

}

//データをセーブする関数save
void save(){
	printf("セーブするファイル名を入力してください(ファイル名の最後は.datにしてください)\n");
	Data.idol=p_idol;
	//printf("%d %d %d\n%s %d %d %d %d %d %d %d\n",Data.play_days,Data.play_idol,Data.money,Data.idol.name,Data.idol.rank,Data.idol.fun,Data.idol.tension,Data.idol.fatigue,Data.idol.status[0],Data.idol.status[1],Data.idol.status[2]);
	fflush(stdin);
	char savefile[60];
    scanf("%s",savefile);
    FILE *fp = fopen( savefile, "wb" );//バイナリファイルを開く
    fwrite( &Data, sizeof(Data), 1, fp ); // SaveData_t構造体の中身を出力
    fclose( fp );//ファイルを閉じる
	printf("セーブしました！\n");
	Sleep(1000);
}

//"ふれあい"を実行する関数friendship
void friendShip(){
	char c;
	printf("%s\n",idoltext.text[0][4][0]);
	printf("%s\n",idoltext.text[Data.play_idol][4][0]);
	//getchar();
	Data.play_days++;
	p_idol.status[0]+=1;
	Sleep(1000);
}

//メニュー画面を表示する関数menu
void menu(){
	int r = rand()%3;
	char text1;
	printf("===============================================================================\n");
	printf("\t\t\t\t\t\t\tプロデュース%d日目\n\n",Data.play_days);
	printf(" アイドル名:%s\t",p_idol.name);
	printf("テンション:");
	setColor(COL_YELLOW);
	printf("◎\t");
	setColor(COL_WHITE);
	printf("ファン数:%d\t疲労度:\n",p_idol.fun);
	printf("\n");
	printf("\t\t%s\n",idoltext.text[Data.play_idol][p_idol.tension][r]);
	printf("-------------------------------------------------------------------------------\n");
	printf("\t\t\t今日の予定はとくにありません\n");
	printf("\n");
	setColor(COL_LIGHT_GRAY);
	printf("\t\t1:イベント");
	printf("\t2:カスタム");
	printf("\t3:レッスン\n");
	printf("\t\t4:お仕事");
	setColor(COL_WHITE);
	printf("\t5:ふれあい");
	setColor(COL_LIGHT_GRAY);
	printf("\t6:ガシャ\n");
	printf("\t\t7:アイテム");
	printf("\t8:データ");
	setColor(COL_WHITE);
	printf("\t9:セーブ\n");
	printf("-------------------------------------------------------------------------------\n");
	printf("コマンドを入力してください\n");
	while(1){
		fflush(stdin);
		scanf("%c",&text1);
		if(text1=='1'){
			printf("未実装です\n");
		}else if(text1=='2'){
			printf("未実装です\n");
		}else if(text1=='2'){
			printf("未実装です\n");
		}else if(text1=='3'){
			printf("未実装です\n");
		}else if(text1=='4'){
			printf("未実装です\n");
		}else if(text1=='5'){
			friendShip();
			break;
		}else if(text1=='6'){
			printf("未実装です\n");
		}else if(text1=='7'){
			printf("未実装です\n");
		}else if(text1=='8'){
			printf("未実装です\n");
		}else if(text1=='9'){
			save();
			break;
		}else{
			
		}
	}
}

//関数main
int main(void){
	srand(time(NULL));
	int number = start();
	if(number==1){
		printf("................................................................................\n");
		idol_Select();
	}else if(number==3){
		return 0;
	}
	while(1){
		menu();
	}
}