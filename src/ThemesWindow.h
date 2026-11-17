#ifndef THEMES_WINDOW_H
#define THEMES_WINDOW_H

#include <Window.h>

class ThemesWindow : public BWindow {
public:
	ThemesWindow();

	void MessageReceived(BMessage *message);
};

#endif
