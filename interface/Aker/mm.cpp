#include "mm.h"
#include <QTimer>
#include "ui_mm.h"
#include <stdio.h>

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <QCloseEvent>

#define portname "/dev/ttyUSB0"

MM::MM(QWidget *parent):QMainWindow(parent), ui(new Ui::MM){

	QTimer *mainTimer = new QTimer(this);
	connect(mainTimer, &QTimer::timeout, [=]() {
		int fd = ::open(portname, O_RDWR | O_NOCTTY | O_SYNC);
		set_interface_attribs (fd, B115200, 0);
		printf("Updating...\n");
		// set no blocking
		//set_blocking (fd, 0);
		if(fd>=0){
			QTimer::singleShot(1000,this,[=](){
				updateVals(fd);
				::close(fd);
			});
		}else{
			//printf("error %d opening\n", errno);
		}
	});
	mainTimer->start(2000);



	ui->setupUi(this);
	connect(ui->actionBack, &QAction::triggered, [=]() {
		parentWidget()->show();
		this->close();
	});
}

void MM::updateVals(int fd){
	//package data;
	char buff[21];
	char data[4][6];

	memset(buff,0,sizeof(buff));
	memset(data,0,sizeof(data));

	::read(fd,&buff,20);

	if(buff[0]!='\0'){
		printf("\n|%s|\n",buff);
		for(int i=0;i<4;i++){
			::memcpy(data[i],&buff[5*i],5);
			//printf("-%s-",data[i]);
		}

		ui->val0->display(data[0]);
		ui->val1->display(data[1]);
		ui->val2->display(data[2]);
		ui->val3->display(data[3]);
	}
}

int MM::set_interface_attribs (int fd, int speed, int parity){
	struct termios tty;
	memset (&tty, 0, sizeof tty);
	if (tcgetattr (fd, &tty) != 0){
		return -1;
	}

	cfsetospeed (&tty, speed);
	cfsetispeed (&tty, speed);

	tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;	 // 8-bit chars
	// disable IGNBRK for mismatched speed tests; otherwise receive break
	// as \000 chars
	tty.c_iflag &= ~IGNBRK;		 // disable break processing
	tty.c_lflag = 0;				// no signaling chars, no echo,
									// no canonical processing
	tty.c_oflag = 0;				// no remapping, no delays
	tty.c_cc[VMIN]  = 0;			// read doesn't block
	tty.c_cc[VTIME] = 5;			// 0.5 seconds read timeout

	tty.c_iflag &= ~(IXON | IXOFF | IXANY);// shut off xon/xoff ctrl

	tty.c_cflag |= (CLOCAL | CREAD);  // ignore modem controls,
									  // enable reading
	tty.c_cflag &= ~(PARENB | PARODD);// shut off parity
	tty.c_cflag |= parity;
	tty.c_cflag &= ~CSTOPB;
	tty.c_cflag &= ~CRTSCTS;

	if (tcsetattr (fd, TCSANOW, &tty) != 0){
		return -1;
	}
	return 0;
}

void MM::set_blocking (int fd, int should_block){
	struct termios tty;
	memset (&tty, 0, sizeof tty);
	if (tcgetattr (fd, &tty) != 0){
		return;
	}

	tty.c_cc[VMIN]  = should_block ? 1 : 0;
	// 0.5 seconds read timeout
	tty.c_cc[VTIME] = 5;

	if (tcsetattr (fd, TCSANOW, &tty) != 0){
		return;
	}
}

MM::~MM(){
	delete ui;
}

void MM::on_sendComm_clicked(bool checked){
	QList<QRadioButton *> allButtons = ui->comandos->findChildren<QRadioButton *>();
	char comm[4];

	memset(comm,255,sizeof(comm)-1);
	comm[3]='\0';
	printf("%s\n",comm);

	int n;

	for(n=0;n<allButtons.size();n++){
		if(allButtons[n]->isChecked()){
			break;
		}
	}

	if(n!=allButtons.size()){
		printf("Button: %d\n",n);
		int fd = ::open(portname, O_RDWR | O_NOCTTY | O_SYNC);
		comm[0]=('\0'+n);
		printf("%s\n",comm);
		::write(fd,comm,sizeof(comm));
		::close(fd);
	}
	if(n==1){
		system("python ../get_adc.py");
	}else if(n==3){
	}if(n==5){
		system("python ../get_img.py");
		system("python ../interface.py");
		});
	}


}
