#include "OpenProjectAction.h"

#include "Engine.h"
#include "Song.h"

#include "embed.h"
#include "FileDialog.h"
#include "GuiApplication.h"
#include "MainWindow.h"

OpenProjectAction::OpenProjectAction(const QKeySequence & _shortcut) :
	QAction(embed::getIconPixmap( "project_open" ), tr( "&Open..." ))
{
	setShortcut(_shortcut);
	setToolTip(tr("Open existing project"));

	connect(this, SIGNAL(triggered()), SLOT(openProject()));
}




void OpenProjectAction::openProject()
{
	auto mainWindow = gui->mainWindow();
	if(mainWindow->mayChangeProject(false))
	{
		FileDialog ofd(mainWindow, tr( "Open Project" ), "", tr( "LMMS (*.mmp *.mmpz)" ));

		ofd.setDirectory( ConfigManager::inst()->userProjectsDir() );
		ofd.setFileMode( FileDialog::ExistingFiles );
		if( ofd.exec () == QDialog::Accepted &&
			!ofd.selectedFiles().isEmpty() )
		{
			Song *song = Engine::getSong();

			song->stop();
			mainWindow->setCursor( Qt::WaitCursor );
			song->loadProject( ofd.selectedFiles()[0] );
			mainWindow->setCursor( Qt::ArrowCursor );
		}
	}
}
