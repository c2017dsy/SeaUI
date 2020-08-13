/* Dome.hpp  (C) CopyRight SIyuan Deng 2020 -forever,
SeaUI is a free software that can be edited as needed.
The program is based on Win32, so it can only run in a window system.
There must be some errors in my program that I don��t know about,
Therefore, please use it with caution. */

#include <iostream>
#include "SeaUI.hpp"


HWND hwnd;
LRESULT CALLBACK MyWndProc( HWND, UINT, WPARAM, LPARAM ) ;
//LRESULT CALLBACK *******( HWND, UINT, WPARAM, LPARAM ) ;

_SEAUIWINDOW*Textbox_example=Initialization(SUS_TEXTBOX);//��ʼ��Ϊ�ı��� 
_SEAUIWINDOW*MaskWindow_example=Initialization(SUS_MASK);//��ʼ��Ϊ���ִ��� 
_SEAUIWINDOW*LayeredWindow_example=Initialization(SUS_LAYER);//��ʼ��Ϊ�ֲ㴰�� 
_SEAUIWINDOW*NormalWindow_example=Initialization(SUS_NORMAL);//��ʼ��Ϊ��׼�Ӵ��� 
_SEAUIWINDOW*ProgressBar_example=Initialization(SUS_PROGRESSBAR);//��ʼ��Ϊ��׼�Ӵ��� 
         
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow )
{
	RegWindow("���Դ���",MyWndProc,hwnd, hInstance); 
 	MSG          msg ;
    while( GetMessage(&msg, NULL, 0, 0) )
    {
        TranslateMessage( &msg ) ;
        DispatchMessage( &msg ) ;
    } 
    return msg.wParam ;
}


static void OnButtonUp(){
	printf("�����mask Window(���ִ���)\n");
	MessageBox(NULL,"�����mask Window(���ִ���)","Example",MB_OK); 
	return;
}


static void OnButtonUp1(){
	printf("�����LAYERED Window(�ֲ㴰��)\n");
	MessageBox(NULL,"�����LAYERED Window(�ֲ㴰��)","Example",MB_OK); 
	return;
}

static void OnButtonUp2(){
	printf("�����Normal Window(��׼����)\n");
	MessageBox(NULL,"�����Normal Window(��׼����)","Example",MB_OK); 
	return;
}

static void OnButtonUp3(){
	printf("�����Progress Bar\n");
	ProgressBar_example->SetPercentage(ProgressBar_example->GetClickPosition());//���ݵ��λ�����ðٷֱ� 
	//float num=ProgressBar_example->GetPercentage();//��ȡ��ǰ�ٷֱ� 
	return;
}



LRESULT CALLBACK MyWndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam ) 
{
	PAINTSTRUCT ps;
	
	
    switch(message)
    {
    case WM_CREATE:{        //�ڽ��յ� WM_CREATE ��Ϣʱ����һ���Ӵ���
    
    
    	AllocConsole();//��ʾ����̨���� 
 		freopen("CONOUT$", "w", stdout);//��ʾ����̨���� 
    	
    	/***************TextBox�༭��******************/
    	//ʵ��ԭ����ǰѱ༭���ٷ�װ������������win32�༭���api�˴������� 
		Textbox_example->Create(hWnd,"textbox",0,40,200,25,(HMENU)0);//����TextBox(�༭��) 
		Textbox_example->Roundrect(25,1);//����Բ�� 
		Textbox_example->SetTextSize(10,18);//������ʾ�����С 
		
		//strcpy(str,Textbox_example->GetText());����������� 
		//Textbox_example->SetTextBoxLong( �˴���дWindows�༭�����ʽ��ʶ�������� ES_NUMBER��ֻ���������ֵ���ʽ )
		//Textbox_example->Password(true);��Ϊ�����������*�������� 
		//���⻹����ͨ����׼API :SetWindowText�������ı������� 
		
		 /*����Create�������β�1 HWNDΪ�����ڵľ������ʶ�������β�2λ�Զ������֣��β�3��4Ϊ*�ֱ�Ϊ����ڸ�����
		 ��X��Y���꣬����β�1HWND��ֵΪ�㣬��ô�β�3,4���������Ļ���Ͻ����괴����
		 �β�5,6Ϊ�����Ĵ��ڵĳ����β�7ΪHMENU�����û������Ҫ��Ϊ��/ 
		 
		 
		/***************Mask Window���ִ���******************/
		MaskWindow_example->Create(hWnd,"MaskWindow",0,90,200,200,(HMENU)0);//�������ִ��� 
		MaskWindow_example->SetAlphaValue(0);//����͸���ȣ��˴���͸��ֵ�������ǰ��ͼƬ�� 
		MaskWindow_example->Roundrect(25,1);//����Բ�� 
		MaskWindow_example->SetBackgroundImage("res/Pavarotti.bmp",200,200,0,0);//���ñ���ͼƬ��ǰ���������ǳ���������Ϊxy���� ,ע���ʽΪBMP 
		MaskWindow_example->SetForegroundBitmap("res/black.bmp",200,200);//����ǰ��ͼƬ,ע���ʽΪBMP 
		//���������ǵ������ͣ���������� 
		MaskWindow_example->ButtonAnimationInitialize(0,70);//����͸���仯�̶ȣ�����1Ϊ��ʼ͸���ȣ�����2Ϊ����͸���ȣ����û�г�ʼ�����������Ķ���������Ч�� 
		MaskWindow_example->ButtonHitAnimation(SEA_UI_ON);//����������� 
		MaskWindow_example->MouseHoverAnimation(SEA_UI_ON);//������ͣ���� 
		MaskWindow_example->SetCallback(WM_LBUTTONUP,OnButtonUp);
		/*���ûص���WM_LBUTTONUPΪ����ڴ�����̧��ı�ʶ����OnButtonUpΪ�ص���������ע��ص��������β�Ϊ����Ϊ��̬��static��
		��ʽΪ static void XXXX(){  }
		���������ûص�����  WM_PAINT,WM_LBUTTONDOWN,WM_MOUSEHOVER,WM_MOUSELEAVE. 
		*/ 
		
		/***************Layer Window�ֲ㴰��******************/
		//ע�⣬�ֲ㴰�ڴ���Ϊ�����ߴ��� 
		LayeredWindow_example->Create(hWnd,"Layer Window",0,310,100,100,(HMENU)0);
		LayeredWindow_example->SetImage("res/karajan.bmp",0,0);//ע���ʽΪBMP 
		LayeredWindow_example->SetAlphaValue(200);//����͸���� 
		LayeredWindow_example->SetFrameInfo(2,0,1,0);
		/*���ñ߿򣬲���һΪ�߿�Ĵ�ϸ�����أ���������Ϊ�߿����ɫCOLOREF����RGB(,,)����ʾ��
		������Ϊboolֵ��Ϊ1ʱ����Զ�ʶ��������ɫ�����Ʊ߿����ô�ֵ�����Բ�������������Ϊ�Ƿ�Ϊ3D��ʽ�ı߿� 
		*/ 
	     //���������ǵ������ͣ���������� 
		LayeredWindow_example->ButtonAnimationInitialize(200,100);//ͬ�� 
		LayeredWindow_example->ButtonHitAnimation(SEA_UI_ON);
		LayeredWindow_example->MouseHoverAnimation(SEA_UI_ON);
		LayeredWindow_example->SetCallback(WM_LBUTTONUP,OnButtonUp1);//���ûص� 
		
		
		/***************Layer Window�ֲ㴰��******************/
		NormalWindow_example->Create(hWnd,"Normal Window",0,430,100,100,(HMENU)0);
		NormalWindow_example->SetImage("res/black.bmp",0,0);//����ͼƬ��ע��Ϊbmp 
		NormalWindow_example->Transform(RGB(0,0,0),RGB(100,100,100));//����һ����ͼС����������һΪ��ͼѡ������ɫ������2ΪҪ�ٳɵ���ɫ��������ʾ������һ�� 
		NormalWindow_example->ButtonHitAnimation(SEA_UI_ON);//�������� 
		NormalWindow_example->SetCallback(WM_LBUTTONUP,OnButtonUp2);//���ûص� 
		//�˴�ʡ����һЩ���ܣ�����������漸���ؼ� 
		
		/***************Progress Bar������******************/
		ProgressBar_example->Create(hWnd,"Progress Bar",0,0,150,10,(HMENU)0);
		ProgressBar_example->SetBackgroundImage("res/black.bmp",0,0,0,0);//���ñ���ͼƬ��ǰ���������ǳ���������Ϊxy���� ,ע���ʽΪBMP 
		ProgressBar_example->SetForegroundBitmap("res/progress.bmp",0,0);//����ǰ��ͼƬ,ע���ʽΪBMP 
		ProgressBar_example->SetPercentage(0.7f);//���ðٷֱ�
		ProgressBar_example->SetProgressBarDirection(SUD_RIGHT);//���÷������δ����,��Ĭ�Ͻ����������� 
		ProgressBar_example->SetCallback(WM_LBUTTONDOWN,OnButtonUp3);//���ûص� 
		//�˴�ʡ����һЩ���ܣ�����������漸���ؼ� 
		
		return 0 ;}
	case WM_COMMAND:{
	
			break;}
					
			case WM_PAINT:{
				HDC hdc = BeginPaint(hWnd, &ps);
				DrawPicture(hdc,"res/a.bmp",500,500);
				// TODO: �ڴ���������������ͼ����...
				EndPaint(hWnd, &ps);
				break;
						  }
		
    case WM_DESTROY:
        PostQuitMessage( 0 ) ;
        RemoveWindow(Textbox_example);
        RemoveWindow(MaskWindow_example);
        RemoveWindow(LayeredWindow_example);
        RemoveWindow(NormalWindow_example);
        RemoveWindow(ProgressBar_example);
        return 0 ;
    }
    return DefWindowProc( hWnd, message, wParam, lParam ) ;
}

