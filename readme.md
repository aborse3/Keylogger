# Keylogger C++ 11
  This is a windows process which works on Windows 7,8,8.1 and 10.

## Features
  This Keylogger runs on bare minimum resources. (only needs c++ 11 which is installed on all versions of windows by default).
  Capture all keystrokes using system hooks.
  Creates log files with time and date.
  Uses Base64 encoding to make logfiles unreadable.
  Emails the recording of the keystrokes using widows Powershell.

## Prerequisites
  C++ 11 is the only prerequisite.

## Changes to make
  In sendMail.h
  Edit line 16 for where the log should be sent from (default: gmail only)
  ```pyhton
  #define X_EM_TO "our.destination@email.address" // change the string to source email
  ```

  Edit line 17 for where the log should be sent to (can be same as above or any other email is fine)
  ```python
  #define X_EM_FROM "Address of sender" // change the string to destination email
  ```

  Edit line 18 for powershell to login to source email (required for email to be sent)
  ```python
  #define X_EM_PASS "password" // change the string to password of source email
  ```

  Allowing less secure apps for gmail.
  Google "less secure apps" and allow less secure apps for above mentioned addresses.

  Setting interval time.<br/>
  the user can set the interval at which each log file is created and sent.
  Open KeybHook.h.
  Edit line 36 with the desired time (default is 30 seconds)
  ```python
  Timer MailTimer(TimerSendMail, 500 * 60, Timer::Infinite); // change the second argument to desired time (milliseconds)
  ```

## Installing
  After making the above changes clone this repository on your local machine and open the project in your favorite IDE. Compile and run the executable. You would get an email of recordings after a particular interval.

## Desclaimer
  Use at your own resposibilty and risk. I am not responsible for any outcome of the usage of this software.
