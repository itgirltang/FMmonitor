#include <QApplication>
#include "FMmonitor.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CFMmonitor* m_monitor = new CFMmonitor(NULL);
	m_monitor->show();
	return a.exec();
}