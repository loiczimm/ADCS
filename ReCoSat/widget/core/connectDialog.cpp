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
#include <QString>

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
        connect(ui_.buttonBox, SIGNAL(accepted()), this, SLOT(saveAsDefault()));



        // populate serial port menu -- the user data is used to save the dashel port number
 /*       std::map<int, std::pair<std::string, std::string> > ports = Dashel::SerialPortEnumerator::getPorts();
        for(std::map<int, std::pair<std::string, std::string> >::iterator it = ports.begin(); it != ports.end(); ++it)
        {
#ifdef Q_WS_WIN
                ui_.serialPortCombo->addItem(QString(it->second.second.c_str()), QVariant(it->first));
#else
                ui_.serialPortCombo->addItem(QString(it->second.second.c_str()), QVariant(QString(it->second.first.c_str())));
#endif
        }*/

        //set to common values
        //read value from file
        FILE* in;
        int arg1, arg2, arg3, arg4, s_port;
        char* s_ip;
        s_ip = (char*)malloc(100*sizeof(char));
        in = fopen("login","r");
        fscanf(in,"tcp:%d.%d.%d.%d;port=%d",&arg1, &arg2, &arg3, &arg4, &s_port);
        sprintf(s_ip,"%d.%d.%d.%d",arg1, arg2, arg3, arg4);
        ui_.tcpAddressEdit->setText(s_ip);
        ui_.tcpPortEdit->setText(QString::number(s_port));
        fclose(in);

        // read previous settings
        QSettings settings;
        settings.beginGroup("connectDlg");
        readFromSettings(settings);
        settings.endGroup();
}



/*!
*	Read from a QSetting (can be either a connection profile or the defaults).
*/
void ConnectDialog::readFromSettings(QSettings &settings)
{

        if (settings.contains("connectionTypeVisible"))
                connectionTypeVisible_ = settings.value("connectionTypeVisible").toBool();

        if (settings.contains("stopBitsVisible"))
                stopBitsVisible_ = settings.value("stopBitsVisible").toBool();

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

        if (settings.contains("configFileVisible"))
                configFileVisible_ = settings.value("configFileVisible").toBool();

        if (settings.contains("enableAdvancedFunctions"))
                ui_.enabledAdvancedFunctionCheck->setCheckState(static_cast<Qt::CheckState>(settings.value("enableAdvancedFunctions").toInt()));

        if (settings.contains("enableAdvancedFunctionsVisible"))
                enableAdvancedFunctionsVisible_ = settings.value("enableAdvancedFunctionsVisible").toBool();
}

/*!
*	Save to a QSetting. Visiblity settings are not saved.
*/
void ConnectDialog::saveToSettings(QSettings &settings, bool isProfile)
{
        settings.setValue("address", ui_.tcpAddressEdit->text());
        settings.setValue("port", ui_.tcpPortEdit->text());

        settings.setValue("enableAdvancedFunctions", ui_.enabledAdvancedFunctionCheck->checkState());

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
        FILE *out;
        out = fopen("login","w");
        fprintf(out,connectionTarget().toStdString().c_str());
        fclose(out);
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

                setAllVisible();
        }
}

/*!
*	Update the visibility of the GUI based on the visibility flags.
*/
void ConnectDialog::updateVisibility()
{
        ui_.tcpAddressLabel->setEnabled(true);
        ui_.tcpAddressEdit->setEnabled(true);

        ui_.tcpPortLabel->setEnabled(true);
        ui_.tcpPortEdit->setEnabled(true);

        ui_.enabledAdvancedFunctionCheck->setEnabled(enableAdvancedFunctionsVisible_);
}

/*!
*	Set all to visible.
*/
void ConnectDialog::setAllVisible()
{
        connectionTypeVisible_ = true;
        serialPortVisible_ = true;
        baudRateVisible_ = true;
        stopBitsVisible_ = true;
        flowControlVisible_ = true;
        tcpAddressVisible_ = true;
        tcpPortVisible_ = true;
        configFileVisible_ = true;
        enableAdvancedFunctionsVisible_ = true;
        updateVisibility();
}



//! Return if advanced function should be enabled.
bool ConnectDialog::enableAdvancedFunctions()
{
        return ui_.enabledAdvancedFunctionCheck->checkState() == Qt::Checked;
}

//! Return the compatible target string
QString ConnectDialog::connectionTarget()
{
        QString target;
        /*target = ui_.tcpAddressEdit->text();

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
        }*/

        target.append("tcp:");
        target.append(ui_.tcpAddressEdit->text());
        target.append(";port=");
        target.append(ui_.tcpPortEdit->text());

        return target;
}


