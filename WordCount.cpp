#include<bits/stdc++.h>

using namespace std;

const int MAX_NUM = 1e6+7;

int counterChar(char* PATh){	//统计文件字符数 
	char buff[MAX_NUM];	//字符缓存区 
	FILE* fp;
	int lenChar, totalChar = 0; //每行和总共的字符数
	if((fp = fopen(PATh, "r")) == NULL){
		perror("the file fail to read");
		exit(1);
	} 
	while(!feof(fp) && !ferror(fp)){	//文件读取结束或者出错则退出 
		fgets(buff, MAX_NUM, fp);	//每次读取一行或MAX_NUM个字符
		lenChar = strlen(buff);
		if(lenChar == 0) {	//消除空白行 
			continue;
		}
		totalChar += lenChar; 
	}
	fclose(fp);
	return totalChar;
}

int counterWord(char input[]){	//判断字符串中单词个数 
	int now_input = 0;	//记录当前数到了哪里
	int count = 0;	//记录当前单次数
	bool isWord = false;	//判断当前是否是单词内容
	char word;	//当前的字符 
	int total = strlen(input);
	while(now_input < total){	//通过空格分隔来循环判断单次数
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

void addDocument(char** input, char* PATH, int totalLength){	//将文件读取到input字符串中
	*input = (char*) malloc(sizeof(char)*totalLength);	//收纳用的字符串
	FILE* fp = fopen(PATH, "r");
	fgets(*input, totalLength, fp);
	fclose(fp); 
}

int main(int argc, char* argv[])	//argv[0]是程序名，argv[1]是第一个参数 
{
	char* input;
	char* choice = argv[1];
	char* PATH = argv[2];
	// char PATH[] = {"test.txt"};
	int totalNum = counterChar(PATH);
	int wordNum = 0;
	
	if(strcmp(choice, "-c")){
		printf("文件字符数为：%d",totalNum);
	}
	else if(!strcmp(choice, "-w")){
		addDocument(&input, PATH, totalNum);
		wordNum = counterWord(input);
		printf("文件单词数为：%d",wordNum);
	}
	
	return 0;
} 
