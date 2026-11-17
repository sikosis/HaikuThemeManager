<p align="center">
  <img src="Screenshot.png" width="680" alt="Haiku Theme Manager">
</p>

# Haiku Theme Manager

Haiku Theme Manager is a native Haiku application for saving and applying a
coordinated desktop theme. A theme can include backgrounds, Deskbar settings,
interface colours and fonts, window decorators, sounds, Terminal colours,
screen savers and supported third-party application settings.

This project modernises Francois Revol's Theme Manager while retaining its
theme format, application signature, add-on model and BeTheme/MS Plus
importers. The untouched historical project is preserved in
[`HaikuThemeManager-Original`](HaikuThemeManager-Original).

## Build

Build on Haiku with the standard development tools installed:

```sh
make
```

The resulting `ThemeManager` executable is created by Haiku's standard
`makefile-engine`. Run it directly or install it in the Preferences menu.

## Using Theme Manager

Select a theme and choose **Apply** to activate the enabled parts of it. The
**Options** tab controls which setting groups are applied or captured. Use
**New** to capture the current desktop as a new theme, **Save** to update the
selected theme, and **Defaults** to restore Haiku's default theme values.

Theme Manager stores its preferences in
`~/config/settings/x-vnd.yT-ThemeManager` and themes in the standard Haiku
settings hierarchy. Existing settings and themes remain compatible with the
historical application.

## Included themes

**Default** is a read-only system theme that restores the standard values
provided by Haiku. **Dark Mode** is a read-only theme compiled into the
application from the supplied Haiku configuration and screenshot. It does not
depend on a theme already being present in the user's settings directory.

The application also embeds the Haiku-compatible **Champion**, **Haiku**,
**Roired**, **RoiredDark**, **Stargate Atlantis**, **Stargate Atlantis
Ancient**, **gonxish** and **redmond** definitions from
[mmuman/HaikuThemes](https://github.com/mmuman/HaikuThemes). Historical themes
containing ZETA references or `/boot/beos` paths are intentionally excluded.
Some upstream themes refer to wallpapers that are not supplied by that
repository; their remaining colours and settings are still available.

The imported repository does not state a licence. See
[`resources/ImportedThemes/UPSTREAM.md`](resources/ImportedThemes/UPSTREAM.md)
before redistributing a packaged build.

The application MIME signature is `application/x-vnd.hThemeManager`.

## Heritage and licence

Theme Manager was created by Francois Revol and distributed under the MIT
License. The original application credits and localisation catalogues are
retained. The modernised shell and ongoing maintenance are by Sikosis.
