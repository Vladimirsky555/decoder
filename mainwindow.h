#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	QString pass_encode(QString spass);
	QString pass_decode(QString spass);

private slots:
	void on_btnSave_clicked();
	void on_btnDecode_clicked();
	void on_btnClearPassword_clicked();
	void on_btnClearCode_clicked();

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
