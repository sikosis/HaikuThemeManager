NAME := ThemeManager
TYPE := APP

SRCS := \
	src/ThemeAboutWindow.cpp \
	src/BeThemeImporter.cpp \
	src/CompareMessages.cpp \
	src/DumpMessage.cpp \
	src/MakeScreenshot.cpp \
	src/MSThemeImporter.cpp \
	src/ParseMessage.cpp \
	src/ScreenshotView.cpp \
	src/ThemeAddonItem.cpp \
	src/ThemesApp.cpp \
	src/ThemesWindow.cpp \
	src/ThemeImporter.cpp \
	src/ThemeInterfaceView.cpp \
	src/ThemeItem.cpp \
	src/ThemeManager.cpp \
	src/ThemesAddon.cpp \
	src/Utils.cpp \
	src/ViewItem.cpp \
	src/addons/BackgroundsAddon.cpp \
	src/addons/BeIDEAddon.cpp \
	src/addons/DeskbarAddon.cpp \
	src/addons/EddieAddon.cpp \
	src/addons/HaikuUISettingsAddon.cpp \
	src/addons/HaikuWindowDecorAddon.cpp \
	src/addons/PeAddon.cpp \
	src/addons/ScreensaverAddon.cpp \
	src/addons/SoundplayColorAddon.cpp \
	src/addons/SoundsAddon.cpp \
	src/addons/TerminalAddon.cpp \
	src/addons/WinampSkinAddon.cpp

RDEFS := resources/ThemeManager.rdef
RSRCS :=

STDCPPLIBS ?= stdc++
LIBS := be media textencoding translation localestub $(STDCPPLIBS)
LIBPATHS :=
SYSTEM_INCLUDE_PATHS :=
LOCAL_INCLUDE_PATHS := src

OPTIMIZE := SOME
DEFINES := SINGLE_BINARY
WARNINGS := ALL
SYMBOLS :=
DEBUGGER :=
COMPILER_FLAGS := -std=c++17
LINKER_FLAGS :=
APP_VERSION :=
EXTRA_DEPS := resources/DarkMode.theme resources/DarkMode.png
DRIVER_PATH :=
OBJ_DIR :=
TARGET_DIR :=
INSTALL_DIR :=
MAKEFILE := Makefile
MENU_LINKS := TRUE
APP_MENU := Preferences
DODEPS := TRUE
BUILD_PROFILE :=
BUILD_DEBUG :=
CHECK_MEM :=
CHATTY :=

APP_MIME_SIG := application/x-vnd.mmu_man-ThemeManager
LOCALES := ca cs de en en_GB es fr fur hr id it pt ro sv tr uk

include $(BUILDHOME)/etc/makefile-engine
