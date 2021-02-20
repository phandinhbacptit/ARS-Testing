#ifndef LOGUTILS_H
#define LOGUTILS_H

#define LOGSIZE 1024 * 100 //log size in bytes
#define LOGFILES 100

#include <QObject>
#include <QString>
#include <QDebug>
#include <QDate>
#include <QTime>
#include <userconfig.h>


namespace LOGUTILS
{
bool initLogging(QString logFolder);
void stopLogging();
void myMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString& msg);

}

#endif // LOGUTILS_H
