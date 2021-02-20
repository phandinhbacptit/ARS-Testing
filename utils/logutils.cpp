#include "logutils.h"

#include <QTime>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QDir>
#include <QFileInfoList>
#include <iostream>

namespace LOGUTILS
{
  static QString logFileName;
  static QString _logfolder;
  static int stateWrite;

  void initLogFileName(QString nameFolder)
  {
    logFileName = QString(nameFolder + "/Log__%1__%2.txt")
                  .arg(QDate::currentDate().toString("yyyy_MM_dd"))
                  .arg(QTime::currentTime().toString("hh_mm_ss_zzz"));
  }

  /**
    * @brief  Deletes old log files if number of logfile > 100 file. Note -> quantity 100 logfile is temporary set!
    * @note
    * @retval None
  ***/
  void deleteOldLogs(QString namelogFolder)
  {
    QDir dir;
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir.setSorting(QDir::Time | QDir::Reversed);
    dir.setPath(namelogFolder);

    QFileInfoList list = dir.entryInfoList();
    if (list.size() <= LOGFILES) {
      return; //no files to delete
    }
    else {
      for (int i = 0; i < (list.size() - LOGFILES); i++) {
        QString path = list.at(i).absoluteFilePath();
        QFile file(path);
        file.remove();
      }
    }
  }

  /**
    * @brief  This function is used to initilaze process logging file
    * @note
    * @retval true - logging file successfull
    *         false - can'tlogging file
  ***/
  bool initLogging(QString logFolder)
  {
      _logfolder = logFolder;
      stateWrite = true;
      // Create folder for logfiles if not exists
      if (!QDir(logFolder).exists()) {
        QDir().mkdir(logFolder);
      }

      deleteOldLogs(logFolder); //delete old log files
      initLogFileName(logFolder); //create the logfile name

      QFile outFile(logFileName);
      if (outFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
        qInstallMessageHandler(LOGUTILS::myMessageHandler);
        return true;
      }
      else {
        return false;
      }
  }

  /**
    * @brief  This function is used to stop process logging file
    * @note
    * @retval None
  ***/
  void stopLogging()
  {
    qDebug() << "Stop logging";
    stateWrite = false;
  }

  /**
    * @brief  This function is used to handle write log into file when logButton pressed/release
    * @note
    * @param  type -
    *         context -
    *         txt -
    * @retval None
  ***/
  void myMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString& txt)
  {
    //check file size and if needed create new log!
    QFile outFileCheck(logFileName);
    int size = outFileCheck.size();
    //check current log size
    if (size > LOGSIZE) {
        deleteOldLogs(_logfolder);
        initLogFileName(_logfolder);
    }

    if (stateWrite == true) {
        QFile outFile(logFileName);
        outFile.open(QIODevice::WriteOnly | QIODevice::Append);
        QTextStream ts(&outFile);
        ts << txt << endl;
    }
    else {
        // Do nothing
    }
  }
}
