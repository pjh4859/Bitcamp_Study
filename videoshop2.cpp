#if 1
#include"videoshop.h"
//������ ���
Video* Video::registerVideo()
{
	cout << "registerVideo" << endl;
	return 0;
}
//���� ����� ����մϴ�
void Video::listVideo() 
{
	cout << "listVideo" << endl;
}
//������ �˻��մϴ�.(�Ϸù�ȣ��..)
Video* Video::findVideo(int id) 
{
	cout << "findVideo" << endl;
	return 0;
}
// ������ �����մϴ�
void Video::removeVideo(int id) 
{
	cout << "removeVideo" << endl;
}
// ������ ��� �����մϴ�
void Video::removeAllVideo() 
{
	cout << "removeAllVideo" << endl;
}
// ������ �뿩�մϴ�.
void Video::lendVideo(int vid) 
{
	cout << "lendVideo" << endl;
}
//������ �ݳ��մϴ�.
void Video::restoreVideo()
{
	cout << "restoreVideo" << endl;
}
// �ű� ȸ���� ����մϴ�.
void Customer::registerCustomer()
{
	cout << "registerCustomer" << endl;
}
//ȸ�� ����� ����մϴ�
void Customer::listCustomer() 
{
	cout << "listCustomer" << endl;
}
//ȸ���� �˻��մϴ�.(�̸����� �˻�..)
Customer* Customer::findCustomer(int id)
{
	cout << "fineCustomer" << endl;
	return 0;
}
//�ش� ȸ���� ������ ȭ�鿡 ����մϴ�.
void Customer::showCustomerInfo(Customer* person) 
{
	cout << "showCustomerInfo" << endl;
}
//ȸ���� �����մϴ�.
void Customer::removeCustomer(int id)
{
	cout << "removeCustomer" << endl;
}
// ȸ���� ��� �����մϴ�
void Customer::removeAllCustomer() 
{
	cout << "removeAllCustomer" << endl;
}
#endif