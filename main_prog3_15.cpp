#include "h_prog3_15.h"

IDOL p_idol;		//IDOL�^��錾 �A�C�h���̊e�p�����[�^���i�[����
SaveData Data;		//SaveData�^��錾 �Z�[�u�f�[�^���i�[����
IDOL_TEXT idoltext;	//IDOL_TEXT�^��錾 �e�L�X�g�f�[�^���i�[����

//�����F�ω����s���֐�setColor
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

//�e�L�X�g�f�[�^��ǂݎ��֐�loadText
void loadText(){
	FILE *fp = fopen("dat_prog3_15.dat", "rb" );
    fread( &idoltext, sizeof(idoltext), 1, fp );
    fclose(fp);
}

//�Q�[���J�n���̑I�����s���֐�modeSelect
void modeSelect(){
	setColor(COL_WHITE);
	system("cls");
	printf("|-----------------------------------------------------------------------------|\n");
	printf("|\t\t\t�A�C�h���v���f���[�X�Q�[��(��)\t\t\t      |\n");
	printf("|-----------------------------------------------------------------------------|\n");
	Sleep(1000);
	loadText();
    setColor(COL_CYAN);
	printf("\t\t\t���[�h��I��ł�������\n");
	setColor(COL_WHITE);
	printf("\t\t\t1:�͂��߂���\n");
	printf("\t\t\t2:�Â�����\n");
	printf("\t\t\t3:�����\n");
}

//modeSelect�֐��ő��삵�s���𕪊򂷂�֐�start
int start(){
	modeSelect();
	char text;
	int a = 0;
	while(a==0){
		fflush(stdin);
		scanf("%c",&text);
		if(text=='1'){
			printf("�Q�[�����J�n���܂�\n");
			a=1;
		}else if(text=='2'){
			printf("�t�@�C��������͂��Ă�������(�t�@�C�����̍Ō��.dat�ł�)\n");
			char fileName[60];
			fflush(stdin);
			scanf("%s",fileName);
			FILE *fp = fopen( fileName, "rb" );//�o�C�i���t�@�C�����J��
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
			//printf("���������l�����Ă��������I\n");
			a=0;
		}

	}
	return a;
}

//��������Ăѕ\�����邽�߂̊֐�reTry
void reTry(){
	printf("\t\t���Ȃ��͂ǂ�ȃA�C�h�������D���ł����H\n\n");
	setColor(COL_RED);
	printf("\t\t1:���邭�O�����ȃA�C�h��\n");
	setColor(COL_CYAN);
	printf("\t\t2:�N�[���ŃX�g�C�b�N�ȃA�C�h��(������)\n");
	setColor(COL_YELLOW);
	printf("\t\t3:���I�Ń}�C�y�[�X�ȃA�C�h��(������)\n");
	setColor(COL_LIGHT_GRAY);
	printf("\t\t4:�����̃A�C�h���͎����Ō�����(������)\n");
	setColor(COL_WHITE);
}

//�A�C�h����I������֐�idol_Select
void idol_Select(){
	reTry();
	char text1,text2;
	int a = 0;
	while(1){
		fflush(stdin);
		scanf("%c",&text1);
		if(text1=='1'){
			
			printf("�A�C�h�����F%s\n",idoltext.text[1][0][0]);
			printf("%s\n",idoltext.text[1][0][1]);
			printf("���̃A�C�h���ł͂��߂܂����H\n");
			printf("1:yes\t0:no\n");
			fflush(stdin);
			scanf("%c",&text2);
			if(text2=='1'){
				//�L�����N�^�[�̌l�f�[�^��ݒ�
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
	printf("�A�C�h����o�^���܂��I\n");
	//�����X�e�[�^�X������
	p_idol.rank=1;
	p_idol.fun=1;
	p_idol.tension=1;
	p_idol.fatigue=0;
	Data.play_days=1;
	Data.money=100000;
	
	printf("===============================================================================\n");
	printf("\t\t\t�I�[�v�j���O�}���\��\n");
	printf("===============================================================================\n");
	Sleep(1000);
	printf("\n\n\n\n\n");

}

//�f�[�^���Z�[�u����֐�save
void save(){
	printf("�Z�[�u����t�@�C��������͂��Ă�������(�t�@�C�����̍Ō��.dat�ɂ��Ă�������)\n");
	Data.idol=p_idol;
	//printf("%d %d %d\n%s %d %d %d %d %d %d %d\n",Data.play_days,Data.play_idol,Data.money,Data.idol.name,Data.idol.rank,Data.idol.fun,Data.idol.tension,Data.idol.fatigue,Data.idol.status[0],Data.idol.status[1],Data.idol.status[2]);
	fflush(stdin);
	char savefile[60];
    scanf("%s",savefile);
    FILE *fp = fopen( savefile, "wb" );//�o�C�i���t�@�C�����J��
    fwrite( &Data, sizeof(Data), 1, fp ); // SaveData_t�\���̂̒��g���o��
    fclose( fp );//�t�@�C�������
	printf("�Z�[�u���܂����I\n");
	Sleep(1000);
}

//"�ӂꂠ��"�����s����֐�friendship
void friendShip(){
	char c;
	printf("%s\n",idoltext.text[0][4][0]);
	printf("%s\n",idoltext.text[Data.play_idol][4][0]);
	//getchar();
	Data.play_days++;
	p_idol.status[0]+=1;
	Sleep(1000);
}

//���j���[��ʂ�\������֐�menu
void menu(){
	int r = rand()%3;
	char text1;
	printf("===============================================================================\n");
	printf("\t\t\t\t\t\t\t�v���f���[�X%d����\n\n",Data.play_days);
	printf(" �A�C�h����:%s\t",p_idol.name);
	printf("�e���V����:");
	setColor(COL_YELLOW);
	printf("��\t");
	setColor(COL_WHITE);
	printf("�t�@����:%d\t��J�x:\n",p_idol.fun);
	printf("\n");
	printf("\t\t%s\n",idoltext.text[Data.play_idol][p_idol.tension][r]);
	printf("-------------------------------------------------------------------------------\n");
	printf("\t\t\t�����̗\��͂Ƃ��ɂ���܂���\n");
	printf("\n");
	setColor(COL_LIGHT_GRAY);
	printf("\t\t1:�C�x���g");
	printf("\t2:�J�X�^��");
	printf("\t3:���b�X��\n");
	printf("\t\t4:���d��");
	setColor(COL_WHITE);
	printf("\t5:�ӂꂠ��");
	setColor(COL_LIGHT_GRAY);
	printf("\t6:�K�V��\n");
	printf("\t\t7:�A�C�e��");
	printf("\t8:�f�[�^");
	setColor(COL_WHITE);
	printf("\t9:�Z�[�u\n");
	printf("-------------------------------------------------------------------------------\n");
	printf("�R�}���h����͂��Ă�������\n");
	while(1){
		fflush(stdin);
		scanf("%c",&text1);
		if(text1=='1'){
			printf("�������ł�\n");
		}else if(text1=='2'){
			printf("�������ł�\n");
		}else if(text1=='2'){
			printf("�������ł�\n");
		}else if(text1=='3'){
			printf("�������ł�\n");
		}else if(text1=='4'){
			printf("�������ł�\n");
		}else if(text1=='5'){
			friendShip();
			break;
		}else if(text1=='6'){
			printf("�������ł�\n");
		}else if(text1=='7'){
			printf("�������ł�\n");
		}else if(text1=='8'){
			printf("�������ł�\n");
		}else if(text1=='9'){
			save();
			break;
		}else{
			
		}
	}
}

//�֐�main
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