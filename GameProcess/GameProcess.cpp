#include "GameProcess.h"
#include "../ShoebillEngine/ShoebillEngine.h"

/// <summary>
/// gameprocess 본체 완성
/// 2024.01.02
/// </summary>

GameProcess::GameProcess()
	:msg(),
	hWnd(0),
	shoebill(nullptr)

{

}

GameProcess::~GameProcess()
{

}

void GameProcess::Initalize(HINSTANCE hInstance)
{
	///윈도우 초기화
	wchar_t szAppName[] = L"shoebillEngine";
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = GameProcess::WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = szAppName;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	RegisterClassExW(&wcex);

	hWnd = CreateWindowW(szAppName, szAppName, WS_OVERLAPPEDWINDOW,
		300, 300, 1024, 768, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return;
	}

	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);

	//엔진
	shoebill = new ShoebillEngine();
	shoebill->Initalize();

}

void GameProcess::Update()
{
	///메인 루프
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			DispatchMessage(&msg);
		}
		else
		{
			shoebill->Update();
		}
	}
}

void GameProcess::Render()
{

}

void GameProcess::Finalize()
{
	delete shoebill;
}

LRESULT CALLBACK GameProcess::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		//case WM_COMMAND:
		//    {
		//        int wmId = LOWORD(wParam);
		//        // 메뉴 선택을 구문 분석합니다:
		//        switch (wmId)
		//        {
		//        case IDM_EXIT:
		//            DestroyWindow(hWnd);
		//            break;
		//        default:
		//            return DefWindowProc(hWnd, message, wParam, lParam);
		//        }
		//    }
		//    break;
		//case WM_PAINT:
		//    {
		//        PAINTSTRUCT ps;
		//        HDC hdc = BeginPaint(hWnd, &ps);
		//        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		//        EndPaint(hWnd, &ps);
		//    }
		//    break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
