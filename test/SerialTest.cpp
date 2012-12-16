// SerialTest.cpp : 定义控制台应用程序的入口点。
//

#ifdef _WIN32
#include "stdafx.h"
#include <Windows.h>
std::string path = "COM2";
#else
#include <iostream>
#include <cstdio>
std::string path = "/dev/ttyUSB0";
#endif

#include "serial/serial.h"
#ifdef _WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
int main(int argc, const char* argv[])
#endif
{
	printf("hello\n");
	
	serial::Serial port1;

	port1.setPort(path);
	
	port1.open();

	port1.write("hello world");
	unsigned char buf[32]={0,};
	size_t size = 0;
	port1.setReadTimeout(1000);
	//port1.setTimeout(1000);
	while((size = port1.available()) < 10)
	{
		//Sleep(1000);
		port1.read(buf,10);
		printf("size=%d\n",size);
	}
	

	
	
	printf("recv %s\n",buf);
	return 0;
}

