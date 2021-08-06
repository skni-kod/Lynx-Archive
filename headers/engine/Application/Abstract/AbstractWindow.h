#pragma once

#include "Core/BaseTypes.h"

//TODO think about some defines for that?
//TODO Add window type (Windowed/Fullscreen)
//TODO (Minus): Add documentation for methods, at least informing what given method is suspposed to do based on WinAPI functionality.
//AbstractWindow is based mostly on abilities of WinAPI windows. Other native platforms should implement mentioned WinAPI functionality.
class __declspec(dllexport) AbstractWindow
{
public:

	AbstractWindow();

	virtual void SetPosition(int32 x, int32 y);
	virtual void Minimalize();
	virtual void Maximalize();
	virtual void ChangeSize();
	virtual void Restore();
	virtual void Show();
	virtual void Hide();
	virtual bool IsMaximized() const;
	virtual bool isMinimized() const;
	virtual void SetWindowFocus();
};