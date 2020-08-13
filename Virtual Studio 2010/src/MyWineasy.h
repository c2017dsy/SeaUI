
#pragma   once  
#ifndef MYWINEASY_H
#define MYWINEASY_H
#include <windows.h>
#include <iostream>

using namespace std;


class MyWinEasy
{
	public:
		bool MyRegWindowClass(TCHAR szAppName[],WNDPROC WndProc);
		void LockWindowsSystem(); 
		
	private:
	protected:
}*MyWinC,MyWinCS;


void MyWinEasy::LockWindowsSystem()
{
	//ShellExecute(NULL,"open","rundll32.exe","USER32,LockWorkStation","",SW_SHOW);
}

bool MyWinEasy::MyRegWindowClass(TCHAR szAppName[],WNDPROC WndProc)
{
	WNDCLASS wndclass ;//wndclass�����ô�����ʽ
	wndclass.style = CS_HREDRAW | CS_VREDRAW ;// ������ʽ
	wndclass.lpfnWndProc = WndProc ;//���ڻص�
	wndclass.cbClsExtra = 0 ;
	wndclass.cbWndExtra = 0 ;
	wndclass.hInstance = GetModuleHandle (NULL); 
	wndclass.hIcon = LoadIcon (NULL, IDI_APPLICATION) ;//ͼ��
	wndclass.hCursor = LoadCursor (NULL, IDC_ARROW) ;//���
	wndclass.hbrBackground = (HBRUSH)GetSysColorBrush(COLOR_BTNHIGHLIGHT|COLOR_BTNSHADOW);// ������ɫ��ʽ 
	wndclass.lpszMenuName = NULL ;//�˵�
	wndclass.lpszClassName = szAppName;//��������
	if (!RegisterClass (&wndclass)){
		MessageBox(0,"Fail to register Windows Class","ERROR",MB_ICONERROR);
		return false;
	}else return true;
}

#endif
