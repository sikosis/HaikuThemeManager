#include "ThemesWindow.h"

#include <Application.h>
#include <Menu.h>
#include <MenuBar.h>
#include <MenuItem.h>
#include <Message.h>
#include <Screen.h>

#include "ThemeInterfaceView.h"

static const uint32 kAboutRequested = 'abou';


ThemesWindow::ThemesWindow():
	BWindow(BRect(0, 0, 700, 440), "Haiku Theme Manager", B_TITLED_WINDOW,
		B_NOT_RESIZABLE | B_NOT_ZOOMABLE | B_AUTO_UPDATE_SIZE_LIMITS
			| B_QUIT_ON_WINDOW_CLOSE) {
	BMenuBar *menu_bar = new BMenuBar(BRect(0, 0, Bounds().Width(), 1), "menu bar");

	BMenu *application_menu = new BMenu("Theme Manager");
	application_menu->AddItem(new BMenuItem("About Haiku Theme Manager\xE2\x80\xA6",
		new BMessage(kAboutRequested)));
	application_menu->AddSeparatorItem();
	application_menu->AddItem(new BMenuItem("Quit", new BMessage(B_QUIT_REQUESTED), 'Q'));
	menu_bar->AddItem(application_menu);
	AddChild(menu_bar);

	BRect content_frame = Bounds();
	content_frame.top = menu_bar->Frame().bottom + 1.0f;
	AddChild(new ThemeInterfaceView(content_frame));

	BScreen screen(this);
	BRect screen_frame = screen.Frame();
	MoveTo(screen_frame.left + (screen_frame.Width() - Frame().Width()) / 2.0f,
		screen_frame.top + (screen_frame.Height() - Frame().Height()) / 2.0f);
}
//---------------------------------------------------------------------------------------------------------------------------------//


void ThemesWindow::MessageReceived(BMessage *message) {
	switch (message->what) {
		case kAboutRequested:
			be_app->PostMessage(B_ABOUT_REQUESTED);
			break;

		default:
			BWindow::MessageReceived(message);
			break;
	}
}
//---------------------------------------------------------------------------------------------------------------------------------//
