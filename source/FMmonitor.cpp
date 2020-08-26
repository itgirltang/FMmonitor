#include "FMmonitor.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
CFMmonitor::CFMmonitor(QWidget* parent) :QFMmonitorDlg(parent)
{
	connect(start_btn, &QPushButton::clicked, this, &CFMmonitor::on_start_btn_clicked);
	connect(stop_btn, &QPushButton::clicked, this, &CFMmonitor::on_stop_btn_clicked);
	connect(countbtn, &QPushButton::clicked, this, &CFMmonitor::on_countbtn_clicked);
	QTime showTime( 60, 0);                        //设置显示时间初值
	QString showStr = showTime.toString("mm:ss");    //设置显示时间的格式
	//lcdNumber->display(showStr);          //LCD按要求显示时间
	lcdNumber->display("00:00");
	ptimer = new QTimer;
	connect(ptimer, SIGNAL(timeout()), this, SLOT(updateTimeAndDisplay()));
	connect(hisbtn, SIGNAL(clicked()), this, SLOT(hisDisplay()));
	stop_btn->setEnabled(false);
}

CFMmonitor::~CFMmonitor()
{
}
void CFMmonitor::on_start_btn_clicked()
{
	ptimer->start(100);
	baseTime = QTime::currentTime();           //获取开始时间
	lcdNumber->display("60:00");
	clickcount = 0;
	calcucount = 0;
	vaildmoveTime = QTime(0, 0, 0, 0);
	cliknum->setText(QString::number(clickcount));
	valnum->setText(QString::number(calcucount));
}
void CFMmonitor::on_stop_btn_clicked()
{
	QFile redBoxsize("record.txt");
	if (!redBoxsize.open(QIODevice::Append | QIODevice::Text))
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("保存记录失败！"));
		return;
	}
	QDate date = QDate::currentDate();
	QTextStream output(&redBoxsize);
	QString datestr = QString("%1-%2-%3 ").arg(date.year()).arg(date.month()).arg(date.day());
	output<< datestr <<baseTime.toString()
		<<"::"<<clickcount << "::" << calcucount<<endl;
	redBoxsize.close();
	QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("保存记录成功！"));
}
void CFMmonitor::on_countbtn_clicked()
{
	QTime currenttime = QTime::currentTime();
	if (vaildmoveTime.msec() == 0) {//首次有效点击时间
		vaildmoveTime = currenttime;
		calcucount = 1;
	}
	clickcount = clickcount + 1;
	cliknum->setText(QString::number(clickcount));
	int submin = vaildmoveTime.msecsTo(currenttime) / 60000;
	if (submin >= 5) {
		vaildmoveTime = currenttime;
		calcucount = calcucount + 1;
	}
	valnum->setText(QString::number(calcucount));
}
void CFMmonitor::updateTimeAndDisplay()
{
	QTime current = QTime::currentTime();//获取当前时间
	int min= 59-(baseTime.msecsTo(current) / 60000);//分钟时间差值
	int sec = 59 - (baseTime.msecsTo(current) / 1000) % 60;//秒钟时间差值
	QString showStr = QString::number(min) + ":" + QString("%1").arg(sec, 2, 10, QLatin1Char('0'));
	if (min <= 0 && sec <= 0) {
		lcdNumber->display("00:00");
		ptimer->stop();
		stop_btn->setEnabled(true);
	}
	else
		lcdNumber->display(showStr);
}
void CFMmonitor::hisDisplay()
{
	hisrecord->clear();
	QFile redBoxsize("record.txt");
	if (!redBoxsize.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	while (!redBoxsize.atEnd()) {
		QByteArray line = redBoxsize.readLine();
		QString strLine(line);
		QStringList arPart = strLine.split("::");
		if (arPart.length() != 3)
			break;
		hisrecord->append(QString::fromLocal8Bit("时间：") + arPart.at(0)
			+ QString::fromLocal8Bit("点击次数：") + arPart.at(1) +
			QString::fromLocal8Bit("有效胎动：") + arPart.at(2) + "\n");
		//hisrecord->append("\n");
	}
	redBoxsize.close();
}