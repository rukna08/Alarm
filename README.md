# Alarm

Simple alarm clock application with a GUI layer made with .NET Winforms (C#) and the CLI layer made with raw C (though the PlaySound function is of Win32 API)

It uses 12-hr format.

![demo](https://user-images.githubusercontent.com/46285633/169649351-da34bc07-35dc-401b-993d-fec7a3516559.PNG)

After clicking the START button, a CLI (Command Line Interface) opens up and waits for the alarm time, when the current time is equal to the alarm time,
it plays a random music from a folder where all the music or sfx are stored. Any number of music or sfx can be added in that folder freely.
