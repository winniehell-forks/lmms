#include "NewProjectAction.h"

#include "Engine.h"
#include "Song.h"

#include "embed.h"
#include "GuiApplication.h"
#include "MainWindow.h"

NewProjectAction::NewProjectAction(const QKeySequence & _shortcut) :
	QAction(embed::getIconPixmap( "project_new" ), tr( "&New" ))
{
	setShortcut(_shortcut);
	setToolTip(tr( "Create new project" ));

	connect(this, SIGNAL(triggered()), SLOT(createNewProject()));
}




void NewProjectAction::createNewProject()
{
	if( gui->mainWindow()->mayChangeProject(true) )
	{
		Engine::getSong()->createNewProject();
	}
}
