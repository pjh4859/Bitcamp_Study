#if 1
#include"videoshop.h"
//비디오를 등록
Video* Video::registerVideo()
{
	cout << "registerVideo" << endl;
	return 0;
}
//비디오 목록을 출력합니다
void Video::listVideo() 
{
	cout << "listVideo" << endl;
}
//비디오를 검색합니다.(일련번호로..)
Video* Video::findVideo(int id) 
{
	cout << "findVideo" << endl;
	return 0;
}
// 비디오를 삭제합니다
void Video::removeVideo(int id) 
{
	cout << "removeVideo" << endl;
}
// 비디오를 모두 삭제합니다
void Video::removeAllVideo() 
{
	cout << "removeAllVideo" << endl;
}
// 비디오를 대여합니다.
void Video::lendVideo(int vid) 
{
	cout << "lendVideo" << endl;
}
//비디오를 반납합니다.
void Video::restoreVideo()
{
	cout << "restoreVideo" << endl;
}
// 신규 회원을 등록합니다.
void Customer::registerCustomer()
{
	cout << "registerCustomer" << endl;
}
//회원 목록을 출력합니다
void Customer::listCustomer() 
{
	cout << "listCustomer" << endl;
}
//회원을 검색합니다.(이름으로 검색..)
Customer* Customer::findCustomer(int id)
{
	cout << "fineCustomer" << endl;
	return 0;
}
//해당 회원의 정보를 화면에 출력합니다.
void Customer::showCustomerInfo(Customer* person) 
{
	cout << "showCustomerInfo" << endl;
}
//회원을 삭제합니다.
void Customer::removeCustomer(int id)
{
	cout << "removeCustomer" << endl;
}
// 회원를 모두 삭제합니다
void Customer::removeAllCustomer() 
{
	cout << "removeAllCustomer" << endl;
}
#endif