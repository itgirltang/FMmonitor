#ifndef QFMMONITOR_H
#define QFMMONITOR_H

#include <QWidget>
#include "ui_FMmonitor.h"

class QFMmonitorDlg : public QWidget, public Ui::FMmonitorDlg
{
	Q_OBJECT
public:
	QFMmonitorDlg(QWidget* parent = 0);
	~QFMmonitorDlg();
};

#endif // QFMMONITOR_H