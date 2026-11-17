#include "ThemeAboutWindow.h"

#include <AppFileInfo.h>
#include <Application.h>
#include <Button.h>
#include <File.h>
#include <Font.h>
#include <LayoutBuilder.h>
#include <Message.h>
#include <Roster.h>
#include <String.h>
#include <StringView.h>

static BString appVersion() {
	BString version("Version 0.2");
	app_info application_info;
	if (be_app->GetAppInfo(&application_info) != B_OK)
		return version;

	BFile application_file(&application_info.ref, B_READ_ONLY);
	BAppFileInfo file_info(&application_file);
	version_info application_version;
	if (file_info.GetVersionInfo(&application_version, B_APP_VERSION_KIND) == B_OK) {
		version.SetToFormat("Version %lu.%lu", (unsigned long)application_version.major,
			(unsigned long)application_version.middle);
	}

	return version;
}
//---------------------------------------------------------------------------------------------------------------------------------//


ThemeAboutWindow::ThemeAboutWindow():
	BWindow(BRect(0, 0, 520, 320), "About Haiku Theme Manager",
		B_TITLED_WINDOW, B_NOT_RESIZABLE | B_NOT_ZOOMABLE
			| B_AUTO_UPDATE_SIZE_LIMITS | B_CLOSE_ON_ESCAPE) {
	BStringView *title = new BStringView("title", "Haiku Theme Manager");
	BFont title_font(*be_bold_font);
	title_font.SetSize(be_plain_font->Size() * 1.7f);
	title->SetFont(&title_font);

	BString version_text = appVersion();
	BButton *close_button = new BButton("close", "Close",
		new BMessage(B_QUIT_REQUESTED));
	close_button->MakeDefault(true);

	BLayoutBuilder::Group<>(this, B_VERTICAL, 8.0f)
		.SetInsets(20.0f)
		.Add(title)
		.Add(new BStringView("version", version_text.String()))
		.AddStrut(6.0f)
		.Add(new BStringView("description",
			"Create, save and apply complete desktop themes using native Haiku settings."))
		.AddStrut(10.0f)
		.Add(new BStringView("original author",
			"Original Theme Manager by Francois Revol (2000-2012)"))
		.Add(new BStringView("maintainer", "Modernised and maintained by Sikosis"))
		.Add(new BStringView("licence", "Distributed under the MIT License"))
		.Add(new BStringView("thanks",
			"With thanks to the Haiku project and HaikuArchives community"))
		.AddGlue()
		.AddGroup(B_HORIZONTAL)
			.AddGlue()
			.Add(close_button)
		.End();

	CenterOnScreen();
}
//---------------------------------------------------------------------------------------------------------------------------------//
