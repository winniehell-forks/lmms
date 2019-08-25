#ifndef SAVEPROJECTACTION_H
#define SAVEPROJECTACTION_H

#include <QAction>
#include <QKeySequence>

class SaveProjectAction : public QAction {
Q_OBJECT
public:
	explicit SaveProjectAction(const QKeySequence & _shortcut = QKeySequence());

};

#endif // SAVEPROJECTACTION_H
