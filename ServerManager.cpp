#if 0
#include<iostream>
#include"ServerManager.h"
using namespace std;

ServerManager::ServerManager(int age, char* Name, int nComputer, int nManagedComputer) :ComputerEngineer(age, Name, nComputer)
{
	m_nManagedComputer = nManagedComputer;
	cout << "ServerMAnager ������ȣ��" << endl;
}
ServerManager::~ServerManager()
{
	cout << "ServerManager �Ҹ��� ȣ��" << endl;
}
void ServerManager::Work()
{
	cout << m_strName << "�� ���� �ҽÿ� ���ϱ�" << endl;
}
void ServerManager::Info()
{
	ComputerEngineer::Info();
	cout << m_strName << "�� �����ϴ� ��ǻ�� ����" << m_nManagedComputer << "���̴�" << endl;
}
void ServerManager::Play()
{
	cout << "ServerManager Play()" << endl;
}
#endif // 1
