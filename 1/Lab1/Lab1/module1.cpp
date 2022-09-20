#include "framework.h"
#include "module1.rh"

int pos = 1;


static int CALLBACK Number(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_INITDIALOG:
		SetScrollRange(GetDlgItem(hDlg, IDC_SCROLLBAR2), SB_CTL, 1, 100, FALSE);
		return 1;
	case WM_HSCROLL:
		 pos = GetScrollPos(GetDlgItem(hDlg, IDC_SCROLLBAR2), SB_CTL);
		switch (LOWORD(wParam))
		{
		case SB_LINELEFT: 
			pos--;
			break;
		case SB_LINERIGHT: 
			pos++;
			break;
		case SB_THUMBPOSITION: 
		case SB_THUMBTRACK: 
			pos = HIWORD(wParam);
			break;
		default: break;
		}
			SetScrollPos(GetDlgItem(hDlg, IDC_SCROLLBAR2), SB_CTL, pos, TRUE);

		break;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, 0);
			return 1;
		}
		else if (LOWORD(wParam) == IDOK)
		{
			EndDialog(hDlg, pos);
			pos = 1;
			return 1;
		}
		break;

	default: break;
	}
	return 0;
}

int Func_MOD1(HWND hWnd, HINSTANCE hInst)
{
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_LAB1_DIALOG), hWnd, Number);
}
