#ifndef OPENPROJECTACTION_H
#define OPENPROJECTACTION_H

#include <QAction>
#include <QKeySequence>

class OpenProjectAction : public QAction {
	Q_OBJECT
public:
	explicit OpenProjectAction(const QKeySequence & _shortcut = QKeySequence());

private slots:
	static void openProject();
};

#endif // OPENPROJECTACTION_H
