#include <windows.h>
#include <windowsX.h>
#include <ctime>
#include <tchar.h>
#include <commctrl.h>
#include "resource.h"

#pragma comment(lib,"comctl32")

int num = 0, maxAns=15;
HWND  b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13,b14,b15,edit1,edit2,edit3, hprogress, hDialog;
TCHAR perc[] = TEXT("%"), editc1[20],editc2[20],editc3[20];

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	INITCOMMONCONTROLSEX icc = { sizeof(INITCOMMONCONTROLSEX) };
	icc.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&icc);
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), NULL, (DLGPROC)DlgProc);
}

void Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	
	switch (id)
	{
	case IDD_ABOUTBOX:
	{
		LRESULT Res1 = SendMessage(b1, BM_GETCHECK, 0, 0);
		LRESULT Res2 = SendMessage(b2, BM_GETCHECK, 0, 0);
		LRESULT Res3 = SendMessage(b3, BM_GETCHECK, 0, 0);
		LRESULT Res4 = SendMessage(b4, BM_GETCHECK, 0, 0);
		LRESULT Res5 = SendMessage(b5, BM_GETCHECK, 0, 0);
		LRESULT Res6 = SendMessage(b6, BM_GETCHECK, 0, 0);
		LRESULT Res7 = SendMessage(b7, BM_GETCHECK, 0, 0);
		LRESULT Res8 = SendMessage(b8, BM_GETCHECK, 0, 0);
		LRESULT Res9 = SendMessage(b9, BM_GETCHECK, 0, 0);
		LRESULT Res10 = SendMessage(b10, BM_GETCHECK, 0, 0);
		LRESULT Res11 = SendMessage(b11, BM_GETCHECK, 0, 0);
		LRESULT Res12 = SendMessage(b12, BM_GETCHECK, 0, 0);
		LRESULT Res13 = SendMessage(b13, BM_GETCHECK, 0, 0);
		LRESULT Res14 = SendMessage(b14, BM_GETCHECK, 0, 0);
		LRESULT Res15 = SendMessage(b15, BM_GETCHECK, 0, 0);
		GetWindowText(edit1, editc1, 50);
		GetWindowText(edit2, editc2, 50);
		GetWindowText(edit3, editc3, 50);
		if (Res1 == BST_CHECKED)
		{
			num++;
		}
		if (Res2 == BST_CHECKED)
		{
			num++;
		}
		if (Res3 == BST_CHECKED)
		{
			num++;
		}
		if (Res4 == BST_CHECKED)
		{
			num++;
		}
		if (Res5 == BST_CHECKED)
		{
			num++;
		}
		if (Res6 == BST_CHECKED)
		{
			num++;
		}
		if (Res7 == BST_CHECKED)
		{
			num++;
		}
		if (Res8 == BST_CHECKED)
		{

			num++;
		}
		if (Res9 == BST_CHECKED)
		{
			num++;
		}
		else if (Res10 == BST_CHECKED)
		{
			num++;
		}
		else if (Res11 == BST_CHECKED)
		{
			num++;
		}
		else if (Res12 == BST_CHECKED)
		{
			num++;
		}
		else if (Res13 == BST_CHECKED)
		{
			num++;
		}
		else if (Res14 == BST_CHECKED)
		{
			num++;
		}
		else if (Res15 == BST_CHECKED)
		{
			num++;
		}
		else
		{
			num--;
		}
		if (lstrcmp(editc1, TEXT(" ËÂ‚")))
		{
			num++;
		}
		if (lstrcmp(editc2, TEXT("ÿ¿√")))
		{
			num++;
		}
		if (lstrcmp(editc3, TEXT("30")))
		{
			num++;
		}
	}
	case IDC_BUTTON1:
		{
		   SetTimer(hwnd, 1, 100, NULL);
			num = (double(num) / maxAns) * 100;
			TCHAR buff[50];
			wsprintf(buff, TEXT("Result:%d"), num);
			MessageBox(hwnd, buff, TEXT("Game over"), MB_OKCANCEL);

		}
		
	}
}

BOOL Cls_OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam)
{
	b1 = GetDlgItem(hWnd, IDC_RADIO2);
	b2 = GetDlgItem(hWnd, IDC_RADIO5);
	b3 = GetDlgItem(hWnd, IDC_RADIO10);
	b4 = GetDlgItem(hWnd, IDC_RADIO12);
	b5 = GetDlgItem(hWnd, IDC_RADIO15);
	b6 = GetDlgItem(hWnd, IDC_RADIO17);
	b7 = GetDlgItem(hWnd, IDC_RADIO19);
	b8 = GetDlgItem(hWnd, IDC_RADIO14);
	b9 = GetDlgItem(hWnd, IDC_RADIO19);
	b10 = GetDlgItem(hWnd, IDC_CHECK1);
	b11 = GetDlgItem(hWnd, IDC_CHECK2);
	b12 = GetDlgItem(hWnd, IDC_CHECK8);
	b13 = GetDlgItem(hWnd, IDC_CHECK9);
	b14 = GetDlgItem(hWnd, IDC_CHECK10);
	b15 = GetDlgItem(hWnd, IDC_CHECK13);
	edit1 = GetDlgItem(hWnd, IDC_EDIT1);
	edit2 = GetDlgItem(hWnd, IDC_EDIT2);
	edit3 = GetDlgItem(hWnd, IDC_EDIT3);
	hDialog = hWnd;
	srand(time(0));
	hprogress = GetDlgItem(hWnd, IDC_PROGRESS1);
	SendMessage(hprogress, PBM_SETRANGE, 0, MAKELPARAM(0, 60));
	SendMessage(hprogress, PBM_SETSTEP, 1, 0);
	SendMessage(hprogress, PBM_SETPOS, 0, 0);
	SendMessage(hprogress, PBM_SETBKCOLOR, 0, LPARAM(RGB(0, 255, 0)));
	SendMessage(hprogress, PBM_SETBARCOLOR, 0, LPARAM(RGB(255, 0, 255)));
	return TRUE;
}

void Cls_OnTimer(HWND hwnd, UINT id)
{
	SendMessage(hprogress, PBM_SETPOS, WPARAM(num), 0);
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, Cls_OnClose);
		HANDLE_MSG(hwnd, WM_INITDIALOG, Cls_OnInitDialog);
		HANDLE_MSG(hwnd, WM_COMMAND, Cls_OnCommand);
		HANDLE_MSG(hwnd, WM_TIMER, Cls_OnTimer);
	}
	return FALSE;
}



