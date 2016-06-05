// In main programm

#ifndef SERIALCOMMUNICATION_H
#define SERIALCOMMUNICATION_H

#include <QtSerialPort>
#include <QWidget>

class SerialCommunication : public QWidget
{
	// Comment this when on release, uncomment when debug
    Q_OBJECT

	// All static functions below return true if everything went good

private:
    QString         m_serialPortName; // utile ???
    QSerialPort     *m_serialPort;
    QByteArray      m_writeData;
    QByteArray      m_readData;
    QTextStream     m_standardOutput;
    qint64          m_bytesWritten;
    //QTimer          m_timer; // utile ???

	// Low-level communication
    bool connectSerialPort();
    bool sendMessage(QByteArray);
    bool read(); // reads an "a"

public slots:
    // Lecture
    void handleReadyRead(); // low-level

    // Ecriture
    void moveCameraToNextPosition(); // after picture has been taken: tell elec to move camera (over serial port)
    // "o"
    void moveCameraTo(int, int);
    // ex: "b 30 50"
    void emergencyStop();
    // "s"
    void startCycle(); // start the cycle to take a (global) picture
    // "a"
    // > utile ?

public:

	SerialCommunication();
    virtual ~SerialCommunication();

signals:
	void MvtFinished();
    void CycleFinished();

};

#endif // SERIALCOMMUNICATION_H
