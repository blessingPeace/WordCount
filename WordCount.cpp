#include<bits/stdc++.h>

using namespace std;

const int MAX_NUM = 1e6+7;

int counterChar(char* PATh){	//ͳ���ļ��ַ��� 
	char buff[MAX_NUM];	//�ַ������� 
	FILE* fp;
	int lenChar, totalChar = 0; //ÿ�к��ܹ����ַ���
	if((fp = fopen(PATh, "r")) == NULL){
		perror("the file fail to read");
		exit(1);
	} 
	while(!feof(fp) && !ferror(fp)){	//�ļ���ȡ�������߳������˳� 
		fgets(buff, MAX_NUM, fp);	//ÿ�ζ�ȡһ�л�MAX_NUM���ַ�
		lenChar = strlen(buff);
		if(lenChar == 0) {	//�����հ��� 
			continue;
		}
		totalChar += lenChar; 
	}
	fclose(fp);
	return totalChar;
}

int counterWord(char input[]){	//�ж��ַ����е��ʸ��� 
	int now_input = 0;	//��¼��ǰ����������
	int count = 0;	//��¼��ǰ������
	bool isWord = false;	//�жϵ�ǰ�Ƿ��ǵ�������
	char word;	//��ǰ���ַ� 
	int total = strlen(input);
	while(now_input < total){	//ͨ���ո�ָ���ѭ���жϵ�����
		word = input[now_input];
		if(word == ' ' || now_input == total-1 || word == ','){
			if(isWord){
				count ++;
				isWord = false;
			}
		}
		else{
			isWord = true;
		}		
		now_input ++;
	} 
	return count;
}

void addDocument(char** input, char* PATH, int totalLength){	//���ļ���ȡ��input�ַ�����
	*input = (char*) malloc(sizeof(char)*totalLength);	//�����õ��ַ���
	FILE* fp = fopen(PATH, "r");
	fgets(*input, totalLength, fp);
	fclose(fp); 
}

int main(int argc, char* argv[])	//argv[0]�ǳ�������argv[1]�ǵ�һ������ 
{
	char* input;
	char* choice = argv[1];
	char* PATH = argv[2];
	// char PATH[] = {"test.txt"};
	int totalNum = counterChar(PATH);
	int wordNum = 0;
	
	if(strcmp(choice, "-c")){
		printf("�ļ��ַ���Ϊ��%d",totalNum);
	}
	else if(!strcmp(choice, "-w")){
		addDocument(&input, PATH, totalNum);
		wordNum = counterWord(input);
		printf("�ļ�������Ϊ��%d",wordNum);
	}
	
	return 0;
} 
