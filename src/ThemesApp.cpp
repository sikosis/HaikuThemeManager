/*
 * Copyright 2000-2008, Francois Revol. All rights reserved.
 * Copyright 2026, Sikosis.
 * Distributed under the terms of the MIT License.
 */

#include "ThemesApp.h"

#include <Entry.h>
#include <Message.h>

#include "ThemeAboutWindow.h"
#include "ThemesWindow.h"

const char *kThemesAppSignature = "application/x-vnd.mmu_man-ThemeManager";


ThemesApp::ThemesApp():
	BApplication(kThemesAppSignature) {
}
//---------------------------------------------------------------------------------------------------------------------------------//


void ThemesApp::AboutRequested() {
	for (int32 index = 0; index < CountWindows(); index++) {
		BWindow *window = WindowAt(index);
		if (dynamic_cast<ThemeAboutWindow *>(window) != NULL) {
			window->Activate();
			return;
		}
	}

	(new ThemeAboutWindow())->Show();
}
//---------------------------------------------------------------------------------------------------------------------------------//


void ThemesApp::ReadyToRun() {
	ThemesWindow *window = new ThemesWindow();
	window->Show();
}
//---------------------------------------------------------------------------------------------------------------------------------//


void ThemesApp::RefsReceived(BMessage *message) {
	if (message == NULL)
		return;

	entry_ref ref;
	if (message->FindRef("refs", &ref) != B_OK)
		return;

	// Theme installation remains owned by ThemeManager. Keep ref delivery
	// explicit so importing can be added without changing the app contract.
}
//---------------------------------------------------------------------------------------------------------------------------------//


int main() {
	ThemesApp application;
	application.Run();
	return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------//
