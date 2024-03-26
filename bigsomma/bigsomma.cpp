#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
class FileReader {
	private:
	FileReader(const FileReader&fr){}	
	int maxBufferSize,bufferSize,bufferPointer;int fileNo;char*buffer;
	void loadBuffer(){bufferSize=read(fileNo,buffer,maxBufferSize);bufferPointer=0;}
	inline char nextChar(){if(bufferPointer>=bufferSize)loadBuffer();return buffer[bufferPointer++];}
	bool skipSpaces(){char c;while(((c=nextChar())==' '||c=='\n'||c=='\t')&&c!='\0');if(c=='\0')return 0;bufferPointer--;return 1;}	
	public:
	FileReader(FILE *f,int _bufferSize=150000){buffer=(char*)malloc(_bufferSize);fileNo=0;maxBufferSize=_bufferSize;loadBuffer();}
	FileReader(int _fileNo,int _bufferSize=150000){buffer=(char*)malloc(_bufferSize);fileNo=_fileNo;maxBufferSize=_bufferSize;loadBuffer();}
	~FileReader(){free(buffer);close(fileNo);} 
	int readInt(){return(int)readLongLong();}
	long long readLongLong(){long long n=0;int mul=1;char c;if(!skipSpaces())abort();c=nextChar();if(c=='+'||c=='-')mul=(c=='+')?1:-1;else bufferPointer--;do{c=nextChar();if(c>='0'&&c<='9')n=n*10+(c-'0');}while(c>='0'&&c<='9');return n*mul;}
	double readDouble(){double n=0;int mul=1,i=0,dotpos=0;char c;if(!skipSpaces())abort();c=nextChar();if(c=='+'||c=='-')mul=(c=='+')?1:-1;else bufferPointer--;do{i++;c=nextChar();if(c>='0'&&c<='9')n=n*10.0+(c-'0');if(c=='.')dotpos=i;}while((c>='0'&&c<= '9')||c=='.');if(dotpos>0)for(;dotpos<i-1;dotpos++)n/=10.0;return n*mul;}
	int readString(char*str){if(!skipSpaces())return str[0]=0;char c;int l=0;do{c=nextChar();str[l++]=c;}while(c!=' '&&c!='\n'&&c!='\t'&&c!='\0');str[--l]='\0';return l;}
	char readChar(){if(!skipSpaces())return'\0';return nextChar();}
};

long long somma(FILE *f){
	FileReader fr(f);

	int N = fr.readInt();

	long long sum = 0;
	for (int i = 0; i < N; ++i){
		sum += fr.readInt();
	}

	return sum;
}