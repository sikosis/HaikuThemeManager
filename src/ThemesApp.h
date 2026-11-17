/*
 * Copyright 2000-2008, François Revol, <revol@free.fr>. All rights reserved.
 * Distributed under the terms of the MIT License.
 */
#ifndef THEMES_APP_H
#define THEMES_APP_H

#include <Application.h>

class ThemesApp : public BApplication {
public:
	ThemesApp();

	void AboutRequested();
	void ReadyToRun();
	void RefsReceived(BMessage *message);
};

#endif
