// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�:

#include <comdef.h>
#include <windows.h>
#include <windowsx.h>
#include <ShellAPI.h>
#include <iostream>
#include <process.h> 
#include <gdiplus.h>
#include <wingdi.h>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>  
#include <windows.h>
#include <math.h>
#include <string>
#include <locale>
#include <codecvt>
#include <mbctype.h>
#include <tchar.h>
#include <string>

#pragma  comment(lib, "gdiplus.lib")
#pragma  comment(lib, "gdi32.lib")
#pragma comment(lib,"msimg32.lib")
using namespace std; 
using namespace Gdiplus;
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

#ifndef SEAUI_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif



