#include "Application/Abstract/AbstractWindow.h"

AbstractWindow::AbstractWindow()
{

}

void AbstractWindow::SetPosition(int32 x, int32 y)
{
}

void AbstractWindow::Minimalize()
{
}

void AbstractWindow::Maximalize()
{
}

void AbstractWindow::ChangeSize()
{
}

void AbstractWindow::Restore()
{
}

void AbstractWindow::Show()
{
}

void AbstractWindow::Hide()
{
}

bool AbstractWindow::IsMaximized() const
{
	return false;
}

bool AbstractWindow::isMinimized() const
{
	return false;
}

void AbstractWindow::SetWindowFocus()
{
}
