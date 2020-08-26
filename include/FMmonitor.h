#ifndef FMMONITOR_H
#define FMMONITOR_H
#include "qFMmonitor.h"
#include <QTime>
#include <QTimer>
class CFMmonitor : public QFMmonitorDlg
{
	Q_OBJECT

public:
	CFMmonitor(QWidget* parent = 0);
	~CFMmonitor();

public:
	
protected:
	
private:
	QTime baseTime;//计时时间
	QTimer* ptimer;//计时器
	QTime vaildmoveTime;//有效次数的时间
	int clickcount;//点击次数
	int calcucount;//有效次数
private slots :
	void on_start_btn_clicked();
	void on_stop_btn_clicked();
	void on_countbtn_clicked();
	void updateTimeAndDisplay();
	void hisDisplay();
};

#endif // FMMONITOR_H