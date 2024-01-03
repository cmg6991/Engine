#pragma once
#include <windows.h>

/// <summary>
/// 엔진 만들기 시작 
/// 2023.12.29
/// 최명기
/// </summary>

class ShoebillEngine;

class GameProcess
{
public:
	GameProcess();
	~GameProcess();

	void Initalize(HINSTANCE hInstance);
	void Update();
	void Render();
	void Finalize();

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	HWND hWnd;
	MSG msg;
	ShoebillEngine* shoebill;

};  
