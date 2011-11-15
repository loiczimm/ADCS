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
    //    setAllVisible();

        // connections
        connect(ui_.buttonBox, SIGNAL(accepted()), this, SLOT());



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


}



