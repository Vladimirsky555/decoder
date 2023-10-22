#include "mainwindow.h"
#include "ui_mainwindow.h"

#define nkey 78
#define swww "WWW"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	setWindowTitle("Кодер-декодер base64");
}

MainWindow::~MainWindow()
{
	delete ui;
}

QString MainWindow::pass_encode(QString spass)
{
	QString epass = "";
	QByteArray barr(spass.toUtf8());

	for (qint32 i = 0; i < barr.size(); i++) {
		barr[i] = barr[i] ^ nkey;	// xor-им каждый символ пароля с ключом
	}

	epass = QString::fromUtf8(barr.toBase64());
	epass.replace("=","");		// уберем признак base64
	epass.replace("/",swww);	// заменим слэш

	return epass;
}

QString MainWindow::pass_decode(QString spass)
{
	QString dpass = "";
	spass.replace(swww,"/");	// вернем слэш обратно

	QByteArray barr = QByteArray::fromBase64(spass.toUtf8());
	for (qint32 i = 0; i < barr.size(); i++) {
		barr[i] = barr[i] ^ nkey;
	}

	dpass = QString::fromUtf8(barr);

	return dpass;
}

void MainWindow::on_btnSave_clicked()
{
	ui->edtCode->clear();
	ui->edtCode->setText(pass_encode(ui->edtPassword->text().trimmed()));
}

void MainWindow::on_btnDecode_clicked()
{
	ui->edtPassword->clear();
	ui->edtPassword->setText(pass_decode(ui->edtCode->text().trimmed()));
}



void MainWindow::on_btnClearPassword_clicked()
{
	ui->edtPassword->clear();
}

void MainWindow::on_btnClearCode_clicked()
{
	ui->edtCode->clear();
}
