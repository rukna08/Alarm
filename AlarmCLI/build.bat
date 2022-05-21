@echo off

mkdir build
pushd build
cl -Zi ..\reminder.c Winmm.lib
popd