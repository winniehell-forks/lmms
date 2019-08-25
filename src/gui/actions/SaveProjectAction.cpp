#include "SaveProjectAction.h"

#include "Engine.h"
#include "Song.h"

#include "embed.h"
#include "FileDialog.h"
#include "GuiApplication.h"
#include "MainWindow.h"

SaveProjectAction::SaveProjectAction(const QKeySequence & _shortcut) :
	QAction(embed::getIconPixmap( "project_save" ), tr( "&Save" ))
{
	setShortcut(_shortcut);
	setToolTip(tr( "Save current project" ));

	// TODO: this is ugly but extracting saveProject() requires a lot of work
	auto mainWindow = gui->mainWindow();
	connect(this, SIGNAL(triggered()), mainWindow, SLOT(saveProject()));
}
