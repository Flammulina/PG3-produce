#include "h_prog3_15.h"

int main(){
	IDOL_TEXT idoltext;
	//char�^�|�C���^�O�����z���錾���A����������
	char *setText[MAX_IDOL][EVENT][RANDOM]={""};
	for(int i=0;i<MAX_IDOL;i++){
		for(int j=0;j<EVENT;j++){
			for(int k=0;k<RANDOM;k++){
				setText[i][j][k]="";
			}
		}
	}
	
	/*
	�A�C�h���̃e�L�X�g��ݒ肵�܂�
	[X][ ][ ] �e�A�C�h���̔ԍ��ł� 0�Ԃ̓V�X�e���p�ł�
	[ ][X][ ] �e�C�x���g���ɐU�蕪�����Ă��܂�
	[ ][ ][X] ��{��0�Ԃŕ\�����܂�
			  1�C�x���g���ŕ����̃e�L�X�g�̏ꍇ�A�܂������_���ɕω�����ꍇ�ɂ͂��̕������g�p���܂�
	
	�e�C�x���g
	0:0/���O 1/���ȏЉ� 2/
	1:���A�E�e���V������
	2:���A�E�e���V������
	3:���A�E�e���V������
	4:�ӂꂠ��
	*/
	//�V�X�e�����Ŏg�p
	setText[0][0][0]="����ɂ��́I";
	setText[0][0][1]="����΂�́I";
	//1�Ԗڂ̃A�C�h���̃e�L�X�g
	setText[1][0][0]="���䌋��";
	setText[1][0][1]="�u�����ƁA�͂��߂܂��āI���͓��䌋���Ɛ\���܂��I\n  �܂��܂��E������������Ȃ����n�҂ł����A�ǂ�����낵�����肢���܂��I�v";
	setText[1][1][0]="�u���͂悤�������܂��I�������ǂ��V�C�ł��ˁ�v";
	setText[1][1][1]="�u�����̂������т͉��ɂ��悤���ȁ`�v";
	setText[1][1][2]="�u�痢�̓����������I�������撣��܂��I�v";
	setText[0][4][0]="�ޏ��ɖڕW�𕷂��Ă݂�";
	setText[1][4][0]="�u���̖ڕW�ł����H�������A�������H�蒅����Ƃ���܂Ńg�b�v��ڎw�����Ƃł��I�v";

	//��������R�s�[����
	for(int i=0;i<MAX_IDOL;i++){
		for(int j=0;j<EVENT;j++){
			for(int k=0;k<RANDOM;k++){
				strcpy(idoltext.text[i][j][k],setText[i][j][k]);
			}
		}
	}
	
	//printf("%s\n",idoltext.text[1][0][1]);
	//�t�@�C������������
	FILE *fp = fopen("dat_prog3_15.dat", "wb" );
    if( fp == NULL ){
                return 0;
        }
    fwrite( &idoltext, sizeof(idoltext), 1, fp );
    fclose(fp);
    return 0;
}