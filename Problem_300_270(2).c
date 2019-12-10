#if 0 //270(2) TCP/IP 클라이언트 프로그램
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<stdio.h>
#include<WinSock2.h>
#pragma comment(lib,"wsock32.lib")

void main()
{
	SOCKET s;
	WSADATA wsaData;
	struct sockaddr_in sin;
	char data[10] = "abcc";

	if (WSAStartup(WINSOCK_VERSION, &wsaData) != 0)
	{
		printf("WSAStartup 실패,에러코드=%d\n", WSAGetLastError());
		return;
	}	
	
	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (s == INVALID_SOCKET)
	{
		printf("소켓 생성 실패,에러코드:%d\n", WSAGetLastError());
		WSACleanup(); return;
	}

	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr("127.0.0.1");
	sin.sin_port = htons(10000);

	if (connect(s, (struct sockaddr*) & sin, sizeof(sin)) != 0)
	{
		printf("접속 실패,에러 코드=%u\n", WSAGetLastError());
		closesocket(s); WSACleanup(); return;
	}

	if (send(s, data, 3, 0) < 3)
	{
		printf("데이터 전송 실패,에러 코드=%u\n", WSAGetLastError());
		closesocket(s); WSACleanup(); return;
	}
	puts("abcc를 서버 프로그램에 전송하였습니다.");

	if (closesocket(s) != 0)
	{
		printf("소켓 제거 실패,에러 코드=%u\n", WSAGetLastError());
		WSACleanup(); return;
	}

	if (WSACleanup() != 0)
	{
		printf("WSACleanup 실패,에러 코드=%u\n", WSAGetLastError());
		return;
	}
}




#endif