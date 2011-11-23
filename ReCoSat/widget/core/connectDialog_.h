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
*	\file ConnectDialog.h
*	\brief Header file of the connection dialog widget class.
*/

#ifndef CONNECT_DIALOG_H
#define CONNECT_DIALOG_H

#include <QDialog>
#include <QSettings>
#include "ui_ConnectDlg.h"

/*!
*	\brief This class represents a dialog window with options to create a connection to a host.
*/
class ConnectDialog : public QDialog
{
        Q_OBJECT

public:
        //! Constructor
        ConnectDialog(QWidget* parent);
        //! Destructor
        virtual ~ConnectDialog() { }


        //! Return the Dashel compatible target string
        QString connectionTarget();

        //! Return the ishtar variable root
        QString variableRoot();

        //! Return the config file path.
        QString configPath();

        //! Return the number of robot to connect to.
        unsigned int robotCount();

        //! Return if advanced function should be enabled.
        bool enableAdvancedFunctions();


public slots:

        //! Ask the user for a config file
        void browseForConfigFile();

        //! Refresh the UI to reflect a profile.
        //! @param index index within the profile combo box
        void currentProfileChanged(int index);

        //! Deals with change of connection type.
        void currentConnectionTypeChanged(int) { updateVisibility(); }

        //! Update the visibility of the GUI based on the visibility flags.
        void updateVisibility();

        //! Save current configuration as default for future use.
        void saveAsDefault();

        //! Save the current configuration as a new profile file.
        void saveCurrentAsProfile();


protected:

        //! Populate the profile combo based on available profile files.
        void populateProfileCombo();

        //! Read from a QSetting (can be either a connection profile or the defaults).
        void readFromSettings(QSettings &settings);

        //! Save to a QSetting.
        void saveToSettings(QSettings &settings, bool isProfile = false);

        //! Set all to visible.
        void setAllVisible();


private:
        Ui::ConnectDlg ui_;

        // visibility
        bool connectionTypeVisible_;
        bool serialPortVisible_;
        bool baudRateVisible_;
        bool stopBitsVisible_;
        bool flowControlVisible_;
        bool tcpAddressVisible_;
        bool tcpPortVisible_;
        bool configFileVisible_;
        bool enableAdvancedFunctionsVisible_;

};

#endif

