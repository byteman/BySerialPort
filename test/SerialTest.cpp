// SerialTest.cpp : 定义控制台应用程序的入口点。
//test

#ifdef _WIN32
#include <Windows.h>
#include <iostream>
std::string path = "COM2";

#else
#include <iostream>
#include <cstdio>
std::string path = "/dev/ttyUSB0";
#endif
//#include <Poco/Thread.h>

#define MAX_BUF 128
unsigned char buf[MAX_BUF+1]={0,};
#include "serial/serial.h"

int main(int argc, const char* argv[])
{

	serial::Serial port1;

	port1.setPort(path);
    port1.setBaudrate (115200);
	port1.open();

	size_t size = 0;

	port1.setReadTimeout(1000);
    port1.setWriteTimeout(1000);

    while(1)
    {
        size = port1.available();
        if(size > 0)
        {
            memset(buf,0,MAX_BUF);
            if(port1.read(buf,size>MAX_BUF?MAX_BUF:size))
            {
                buf[size] = '\0';
                printf("received: %s\n",buf);
                port1.write (buf,size);
            }
        }
        else
        {
            printf("wait receive ....\n");
#ifdef _WIN32
            Sleep(1000);
#else
			sleep(1);
#endif
        }

    }

    return 0;
}

