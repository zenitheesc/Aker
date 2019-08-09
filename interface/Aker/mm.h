#ifndef MM_H
#define MM_H

#include <QMainWindow>

namespace Ui {
class MM;
}

class MM : public QMainWindow
{
	Q_OBJECT

public:
	void on_sendComm_clicked();
	int set_interface_attribs (int fd, int speed, int parity);
	void set_blocking (int fd, int should_block);
	explicit MM(QWidget *parent = nullptr);
	~MM();
public slots:
	void updateVals(int fd);

private slots:
	void on_sendComm_clicked(bool checked);

private:
	Ui::MM *ui;

};

#endif // MM_H
