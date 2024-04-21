#pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <assert.h>

const int buffSize = 1024 * 1024 * 16;
char* buffer;
int bufferPointer = -1;
int fd;
off_t f_offset = 0;

inline void loadBuffer(){
	buffer = (char*) mmap(0, buffSize, PROT_READ, MAP_SHARED | MAP_ANONYMOUS, fd, f_offset);
	if (buffer == MAP_FAILED){
		if (errno == 19)
			exit(1);
		std::cout << "mmap failed\n";
		std::cout << "error: " << errno << "\n";
		throw errno;
	}
	f_offset += buffSize;
	bufferPointer = 0;
}

void initBuffer(FILE* f){
	fd = fileno(f);
	if (fd == -1){
		std::cout << "Failed to read file\n" << fileno(f) << "\n";
		exit(1);
	}
	loadBuffer();
}

inline char nextChar(){
	if (bufferPointer >= buffSize)
		loadBuffer();
	bufferPointer++;
	return buffer[bufferPointer-1];
}

inline bool is_EOF(){
	return buffer[bufferPointer] == '\0';
}

int read_int(){
	char c;
	int ret = 0;
	int mul = 1;
	// if (buffer[bufferPointer] == '\0')
	// 	exit(1);
	std::cout << "aaa" << (buffer[bufferPointer] == '\0') << "aaa\n";
	while ((c = buffer[bufferPointer]) && (c == ' ' || c == '\n') && (c != '\0')){
		std::cout << c << "aaa\n";
		++bufferPointer;
		if (bufferPointer == buffSize){
			loadBuffer();
		}
	}

	while ((c = buffer[bufferPointer]) && (c != ' ' && c != '\0' && c != '\n')){
		std::cout << c << "\n";
		if ('0' <= c && c <= '9')
			ret = (ret << 3) + (ret << 1) + c - '0';
		if (c == '-')
			mul = -1;
		++bufferPointer;
		if (bufferPointer == buffSize){
			loadBuffer();
		}
	}
	
	return ret * mul;
}

long long somma(FILE *f){

	initBuffer(f);

	int N = read_int();
	std::cout << N << "yes\n";
	
	long long sum = 0;
	for (int i = 0; i < N; ++i){
		sum += read_int();
	}

	return sum;
}
