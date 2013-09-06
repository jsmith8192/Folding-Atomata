
/******************************************************************************\
                     This file is part of Folding Atomata,
          a program that displays 3D views of Folding@home proteins.

                      Copyright (c) 2013, Jesse Victors

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see http://www.gnu.org/licenses/

                For information regarding this software email:
                                Jesse Victors
                         jvictors@jessevictors.com
\******************************************************************************/
                         
#ifndef OPTIONS
#define OPTIONS

#include <vector>
#include <string>

typedef std::vector<std::string> StringList;

class Options
{
    public:

        static Options& getInstance();
        static bool handleFlags(int argc, char** argv); //should only call once!
        
        std::string getHost();
        int getPort();
        std::string getPassword();
        //bool slotIDisSet();
        //int getSlotID();

        bool highVerbosity();
        bool bounceSnapshots();
        bool cycleSnapshots();
        bool usesPassword();
        //int renderMode();

    private:
        std::size_t handle(const StringList& options, std::size_t index);
        bool verbose1(const std::string& flag);
        bool connect1(const std::string& flag);
        bool connect2(const std::string& flag, const std::string& arg);
        bool bounceSnapshots1(const std::string& flag);
        bool bounceSnapshots2(const std::string& flag, const std::string& arg);
        bool cycleSnapshots1(const std::string& flag);
        bool cycleSnapshots2(const std::string& flag, const std::string& arg);
        bool password1(const std::string& flag);
        bool password2(const std::string& flag, const std::string& arg);
        //bool slotID1(const std::string& flag);
        //bool slotID2(const std::string& flag, const std::string& arg);
        bool confirm(bool condition, const std::string& flag);

    private:
        static Options* singleton_;

        bool highVerbosity_, bounceSnapshots_, cycleSnapshots_;//, slotIDisSet_;
        int connectionPort_, usesPassword_; //slotID_, renderMode_;
        std::string connectionHost_;
        std::string authPassword_;
};

#endif

/*
The CLI options should be implemented:
--help [string] Print help screen or help on a particular option and exit.
--license Print license information and quit.
-v or --verbose Increase verbosity level
--version Print application version and exit.

Configuration options in the format "--< option > < value >" or "--< option >=< value >" or "--< option >"
--connect < string=127.0.0.1:36330 > An address and port to connect to in the form :
--bounce-snapshots < boolean=false > When the last snapshot is reached, should the animation run backwards or not.
--cycle-snapshots < boolean=true > Iterate through all available snapshots.
--mode < integer=4 > Render mode.
--password < string= > A password for accessing the remote client.*/