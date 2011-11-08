/*
        e-mo-tion
        Copyright (C) 2008-2010:

                Alexandre Habersaat <alexandre dot habersaat at gmail dot com>
                Antoine Beyeler <antoine dot beyeler at sensefly dot com>
                        (http://www.sensefly.com)
        All rights reserved.

        e-mo-tion is free software: you can redistribute it and/or modify
        it under the terms of the GNU Lesser General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        (at your option) any later version.

        e-mo-tion is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU Lesser General Public License
        along with e-mo-tion. If not, see <http://www.gnu.org/licenses/>.
*/

/*!
*	\file ConnectDialog.cpp
*	\brief Source file of the connection dialog widget class.
*/

#include "ConnectDialog.h"

#include <QFileDialog>
#include <QFileInfo>
#include <QDirIterator>

//#include <dashel/dashel.h>
#include <map>
#include <string>

#include "../../MainWindow.h"

/*!
*	Constructor.
*
*	Creates the dialog window and loads the existing profiles from the settings file.
*/
ConnectDialog::ConnectDialog(QWidget * parent) : QDialog(parent)
{
        ui_.setupUi(this);

        // By default, the whole GUI is visible
        setAllVisible();

        // connections
      /*  connect(ui_.browseConfigFileBtn, SIGNAL(clicked()), this, SLOT(browseForConfigFile()));
        connect(ui_.buttonBox, SIGNAL(accepted()), this, SLOT(saveAsDefault()));
        connect(ui_.profileCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(currentProfileChanged(int)));
        connect(ui_.connectionTypeCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(currentConnectionTypeChanged(int)));
        connect(ui_.saveProfileBtn, SIGNAL(clicked()), this, SLOT(saveCurrentAsProfile()));
*/

        // populate the profile combo
        populateProfileCombo();

        // populate serial port menu -- the user data is used to save the dashel port number
    //    std::map<int, std::pair<std::string, std::string> > ports = Dashel::SerialPortEnumerator::getPorts();
      /*  for(std::map<int, std::pair<std::string, std::string> >::iterator it = ports.begin(); it != ports.end(); ++it)
        {
#ifdef Q_WS_WIN
  //              ui_.serialPortCombo->addItem(QString(it->second.second.c_str()), QVariant(it->first));
#else
                ui_.serialPortCombo->addItem(QString(it->second.second.c_str()), QVariant(QString(it->second.first.c_str())));
#endif
        }*/

        // read previous settings
        QSettings settings;
        settings.beginGroup("connectDlg");
        readFromSettings(settings);
        settings.endGroup();
}

/*!
*	Ask the user for a config file
*/
void ConnectDialog::browseForConfigFile()
{
        QString fileName = QFileDialog::getOpenFileName(this, tr("Choose a config file"), tr("./config"), tr("Config file (*.cfg)"));
        QFileInfo fi(fileName);
    //    ui_.configFileEdit->setText(fi.canonicalFilePath());
}


/*!
*	Populate the profile combo based on available profile files.
*/
void ConnectDialog::populateProfileCombo()
{
        // Search for profile file in every path entry.
        QStringList paths = QDir::searchPaths("profiles");
        QSet<QString> profiles;
        for (int i = 0; i < paths.size(); i++)
        {
                QDir dir(paths.at(i));
                QDirIterator iter(dir.path(), QStringList("*.ini"));

                while (iter.hasNext())
                {
                        iter.next();
                        profiles.insert(iter.fileName());
                }
        }

        // Populate the profile combo
        QSetIterator<QString> iter(profiles);
        while (iter.hasNext())
        {
                QString s = iter.next();
             //   ui_.profileCombo->addItem(QFileInfo(s).baseName(), QString("profiles:%1").arg(s));
        }

        // default entries
    /*    if (ui_.profileCombo->count() > 0)
                ui_.profileCombo->insertSeparator(ui_.profileCombo->count());
        ui_.profileCombo->addItem("Manual");*/
}


/*!
*	Refresh the UI to reflect a profile.
*	@param index index within the profile combo box
*/
void ConnectDialog::currentProfileChanged(int index)
{
        QString profile = "error";// ui_.profileCombo->itemData(index).toString();

        if (profile == "")
                // we are in manual mode, let's show everything and leave the current values as is.
                setAllVisible();
        else
        {
                // read from a profile file
                QFileInfo fileInfo(profile);
                QString path = fileInfo.absoluteFilePath();
                QSettings settings(path, QSettings::IniFormat);
                readFromSettings(settings);
                updateVisibility();
        }
}


/*!
*	Read from a QSetting (can be either a connection profile or the defaults).
*/
void ConnectDialog::readFromSettings(QSettings &settings)
{/*
        if (settings.contains("profile"))
        {
                QString profile = settings.value("profile").toString();
                int idx = ui_.profileCombo->findText(profile);
                if (idx != -1)
                        ui_.profileCombo->setCurrentIndex(idx);
                else
                        ui_.profileCombo->setCurrentIndex(0);
        }

        if (settings.contains("connectionType"))
                ui_.connectionTypeCombo->setCurrentIndex(settings.value("connectionType").toInt());
        if (settings.contains("connectionTypeVisible"))
                connectionTypeVisible_ = settings.value("connectionTypeVisible").toBool();

        if (settings.contains("serialPort"))
                ui_.serialPortCombo->setCurrentIndex(ui_.serialPortCombo->findText(settings.value("serialPort").toString()));
        if (settings.contains("serialPortVisible"))
                serialPortVisible_ = settings.value("serialPortVisible").toBool();


        if (settings.contains("baudRate"))
                ui_.baudRateCombo->setCurrentIndex(ui_.baudRateCombo->findText(settings.value("baudRate").toString()));
        if (settings.contains("baudRateVisible"))
                baudRateVisible_ = settings.value("baudRateVisible").toBool();

        if (settings.contains("stopBits"))
                ui_.stopBitsCombo->setCurrentIndex(settings.value("stopBits").toInt());
        if (settings.contains("stopBitsVisible"))
                stopBitsVisible_ = settings.value("stopBitsVisible").toBool();

        if (settings.contains("flowControl"))
                ui_.flowControlCheck->setCheckState(static_cast<Qt::CheckState>(settings.value("flowControl").toInt()));
        if (settings.contains("flowControlVisible"))
                flowControlVisible_ = settings.value("flowControlVisible").toBool();


        if (settings.contains("address"))
                ui_.tcpAddressEdit->setText(settings.value("address").toString());
        if (settings.contains("addressVisible"))
                tcpAddressVisible_ = settings.value("addressVisible").toBool();

        if (settings.contains("port"))
                ui_.tcpPortEdit->setText(settings.value("port").toString());
        if (settings.contains("portVisible"))
                tcpPortVisible_ = settings.value("portVisible").toBool();

        if (settings.contains("configFile"))
        {
                // Make sure we have a full path.
                QFileInfo fileInfo(settings.value("configFile").toString());
                ui_.configFileEdit->setText(fileInfo.absoluteFilePath());
        }
        if (settings.contains("configFileVisible"))
                configFileVisible_ = settings.value("configFileVisible").toBool();

        if (settings.contains("enableAdvancedFunctions"))
                ui_.enabledAdvancedFunctionCheck->setCheckState(static_cast<Qt::CheckState>(settings.value("enableAdvancedFunctions").toInt()));

        if (settings.contains("enableAdvancedFunctionsVisible"))
                enableAdvancedFunctionsVisible_ = settings.value("enableAdvancedFunctionsVisible").toBool();*/
}

/*!
*	Save to a QSetting. Visiblity settings are not saved.
*/
void ConnectDialog::saveToSettings(QSettings &settings, bool isProfile)
{
   /*     if (!isProfile)
                settings.setValue("profile", ui_.profileCombo->currentText());

        settings.setValue("connectionType", ui_.connectionTypeCombo->currentIndex());

        settings.setValue("serialPort", ui_.serialPortCombo->currentText());
        settings.setValue("baudRate", ui_.baudRateCombo->currentText());
        settings.setValue("stopBits", ui_.stopBitsCombo->currentIndex());
        settings.setValue("flowControl", ui_.flowControlCheck->checkState());

        settings.setValue("address", ui_.tcpAddressEdit->text());
        settings.setValue("port", ui_.tcpPortEdit->text());

        settings.setValue("configFile", ui_.configFileEdit->text());

        settings.setValue("enableAdvancedFunctions", ui_.enabledAdvancedFunctionCheck->checkState());
*/
        if (isProfile)
        {
                settings.setValue("connectionTypeVisible", true);
                settings.setValue("serialPortVisible", true);
                settings.setValue("baudRateVisible", true);
                settings.setValue("stopBitsVisible", true);
                settings.setValue("flowControlVisible", true);
                settings.setValue("addressVisible", true);
                settings.setValue("portVisible", true);
                settings.setValue("configFileVisible", true);
                settings.setValue("enableAdvancedFunctionsVisible", true);
        }
}

/*!
*	Save current configuration as default for future use.
*/
void ConnectDialog::saveAsDefault()
{
        QSettings settings;
        settings.beginGroup("connectDlg");
        saveToSettings(settings);
        settings.endGroup();
}

/*!
*	Save the current configuration as a new profile file.
*/
void ConnectDialog::saveCurrentAsProfile()
{
        // First path item is the user folder.
        QString path;
        QStringList paths = QDir::searchPaths("profiles");
        if (paths.count() > 0)
                path = paths[0];


        // Ask destination
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save connection profile"), path + QDir::separator() + "untitled.ini", tr("Connection profile file (*.ini)"));
        if (fileName != "")
        {
                QSettings settings(fileName, QSettings::IniFormat);
                saveToSettings(settings, true);

                // refresh profile menu and set all to visible
                QFileInfo fi(fileName);
          //      ui_.profileCombo->insertItem(0, fi.baseName(), fi.filePath());
            //    ui_.profileCombo->setCurrentIndex(0);
                setAllVisible();
        }
}

/*!
*	Update the visibility of the GUI based on the visibility flags.
*/
void ConnectDialog::updateVisibility()
{
        bool serial = false;//ui_.connectionTypeCombo->currentIndex() == 0;
/*
        ui_.connectionTypeLabel->setEnabled(connectionTypeVisible_);
        ui_.connectionTypeCombo->setEnabled(connectionTypeVisible_);


        ui_.serialPortLabel->setEnabled(serialPortVisible_ && serial);
        ui_.serialPortCombo->setEnabled(serialPortVisible_ && serial);

        ui_.baudRateLabel->setEnabled(baudRateVisible_ && serial);
        ui_.baudRateCombo->setEnabled(baudRateVisible_ && serial);

        ui_.stopBitsLabel->setEnabled(stopBitsVisible_ && serial);
        ui_.stopBitsCombo->setEnabled(stopBitsVisible_ && serial);

        ui_.flowControlCheck->setEnabled(flowControlVisible_ && serial);

        ui_.tcpAddressLabel->setEnabled(tcpAddressVisible_ && !serial);
        ui_.tcpAddressEdit->setEnabled(tcpAddressVisible_ && !serial);

        ui_.tcpPortLabel->setEnabled(tcpPortVisible_ && !serial);
        ui_.tcpPortEdit->setEnabled(tcpPortVisible_ && !serial);

        ui_.configFileLabel->setEnabled(configFileVisible_);
        ui_.configFileEdit->setEnabled(configFileVisible_);
        ui_.browseConfigFileBtn->setEnabled(configFileVisible_);
*/
        //ui_.enabledAdvancedFunctionCheck->setEnabled(enableAdvancedFunctionsVisible_);
}

/*!
*	Set all to visible.
*/
void ConnectDialog::setAllVisible()
{/*
        connectionTypeVisible_ = true;
        serialPortVisible_ = true;
        baudRateVisible_ = true;
        stopBitsVisible_ = true;
        flowControlVisible_ = true;
        tcpAddressVisible_ = true;
        tcpPortVisible_ = true;
        configFileVisible_ = true;
        enableAdvancedFunctionsVisible_ = true;
        updateVisibility();*/
}



//! Return the Dashel compatible target string
QString ConnectDialog::connectionTarget()
{
        QString target;/*
        if (ui_.connectionTypeCombo->currentIndex() == 0)
        {
                target.append("ser:");
#ifndef Q_WS_WIN
                target.append("device=");
#endif
                target.append(ui_.serialPortCombo->itemData(ui_.serialPortCombo->currentIndex()).toString());
                target.append(";");
                target.append(ui_.baudRateCombo->currentText());
                target.append(";");
                target.append(ui_.stopBitsCombo->currentText());
                if (ui_.flowControlCheck->checkState() == Qt::Checked)
                        target.append(";fc=hard");
        }
        else
        {
                target.append("tcp:");
                target.append(ui_.tcpAddressEdit->text());
                target.append(";port=");
                target.append(ui_.tcpPortEdit->text());
        }

        MainWindow::printDebug(target);*/
        return target;
}

//! Return the ishtar variable root
QString ConnectDialog::variableRoot()
{
        //TODO: restore functionality
        return "";
}

//! Return the config file path.
QString ConnectDialog::configPath()
{
        return "error";// ui_.configFileEdit->text();
}

//! Return the number of robot to connect to.
unsigned int ConnectDialog::robotCount()
{
        //TODO: restore functionality
        return 1;
}

//! Return if advanced function should be enabled.
bool ConnectDialog::enableAdvancedFunctions()
{
        return true;//ui_.enabledAdvancedFunctionCheck->checkState() == Qt::Checked;
}

