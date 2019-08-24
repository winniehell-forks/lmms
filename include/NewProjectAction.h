#ifndef NEWPROJECTACTION_H
#define NEWPROJECTACTION_H

#include <QAction>
#include <QKeySequence>

class NewProjectAction : public QAction {
	Q_OBJECT
public:
	explicit NewProjectAction(const QKeySequence & _shortcut = QKeySequence());

private slots:
	static void createNewProject();
};

#endif // NEWPROJECTACTION_H
