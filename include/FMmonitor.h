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
	QTime baseTime;//��ʱʱ��
	QTimer* ptimer;//��ʱ��
	QTime vaildmoveTime;//��Ч������ʱ��
	int clickcount;//�������
	int calcucount;//��Ч����
private slots :
	void on_start_btn_clicked();
	void on_stop_btn_clicked();
	void on_countbtn_clicked();
	void updateTimeAndDisplay();
	void hisDisplay();
};

#endif // FMMONITOR_H