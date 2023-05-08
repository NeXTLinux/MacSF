#!/bin/bash

#
#  file: configure.sh
#  project: macsf (configure)
#  description: install/uninstall
#
#  created by Patrick Wardle
#  copyright (c) 2017 NeXTLinux. All rights reserved.
#

#where MacSF goes
INSTALL_DIRECTORY="/Library/NeXTLinux/MacSF"

#OS version check
# only support 10.15+
OSVers="$(sw_vers -productVersion)"

if [[ ("${OSVers:0:2}" -eq 10) ]]; then
    if [[ "$OSVers" != 10.15.* ]]; then
        printf "\nERROR: ${OSVers} is currently unsupported\n"
        printf "      MacSF requires macOS 10.15+\n\n"
        exit -1
    fi
fi

#auth check
# gotta be root
if [ "${EUID}" -ne 0 ]; then
    printf "\nERROR: must be run as root\n\n"
    exit -1
fi

#uninstall logic
if [ "${1}" == "-uninstall" ]; then

    printf "uninstalling\n"

    #change into dir
    cd "$(dirname "${0}")"

    #kill main app
    # ...it might be open
    killall "MacSF" 2> /dev/null

    #unload launch daemon & remove its plist
    launchctl unload "/Library/LaunchDaemons/com.nextlinux.macsf.plist"
    rm "/Library/LaunchDaemons/com.nextlinux.macsf.plist"

    printf "unloaded launch daemon\n"

    #full uninstall?
    # delete app & MacSF's folder w/ everything
    if [[ "${2}" -eq "1" ]]; then
    
        #remove main app/helper app
        rm -rf "/Applications/MacSF.app"
    
        rm -rf $INSTALL_DIRECTORY

        #no other NeXTLinux tools?
        # then delete that directory too
        baseDir=$(dirname $INSTALL_DIRECTORY)

        if [ ! "$(ls -A $baseDir)" ]; then
            rm -rf $baseDir
        fi

    #partial
    # move rules, delete v1 daemon, etc
    else
    
        #move v1.0 rules
        mv "$INSTALL_DIRECTORY/rules.plist" "$INSTALL_DIRECTORY/rules_v1.plist"
    
        #delete v1.0 files
        rm -rf "$INSTALL_DIRECTORY/MacSF.log"
        rm -rf "$INSTALL_DIRECTORY/MacSF.bundle"
        rm -rf "$INSTALL_DIRECTORY/installedApps.plist"
        
    fi

    #kill
    killall MacSF 2> /dev/null
    killall com.nextlinux.macsf.helper 2> /dev/null
    killall "MacSF Helper" 2> /dev/null

    #remove kext
    # note: will be unloaded on reboot
    rm -rf /Library/Extensions/MacSF.kext

    printf "kext removed\n"

    #rebuild cache, full path
    printf "rebuilding kernel cache\n"
    /usr/sbin/kextcache -invalidate / &

    printf "uninstall complete\n\n"
    exit 0
fi

#invalid args
printf "\nERROR: run w/ '-install' or '-uninstall'\n\n"
exit -1
