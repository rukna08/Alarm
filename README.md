# Alarm

Simple alarm clock application with a GUI layer made with .NET Winforms (C#) and the CLI layer made with raw C (though the PlaySound function is of Win32 API)

It uses 12-hr format.

![demo](https://user-images.githubusercontent.com/46285633/169649351-da34bc07-35dc-401b-993d-fec7a3516559.PNG)

After clicking the START button, a CLI (Command Line Interface) opens up and waits for the alarm time, when the current time is equal to the alarm time,
it plays a random music from a folder where all the music or sfx are stored. Any number of music or sfx can be added in that folder freely.

## Instructions

1. Open the AlarmCLI directory, press build.bat or opening command prompt and executing build will both result in a build directory with the required files.
2. Navigate back to the Alarm directory and open the AlarmGUI directory, double-click to open AlarmGUI.sln (This part needs Microsoft Visual Studio) and build the project.
3. Be sure to double click the START button which will take you to the C# (c-sharp) script of the button and change the path according to your working directory. Sorry, its absolute path, relative path is coming in future.
4. Close Visual Studio and go to bin/Debug and open the AlarmGUI.exe (executable) file and enjoy!
