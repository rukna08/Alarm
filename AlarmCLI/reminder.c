#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#include <string.h>

int main(void) {
    int hours, minutes, seconds;
    time_t now;



    char* sfxArr[] = {
        "../sfx/doraemon.wav",
        "../sfx/mission.wav",
        "../sfx/shinchan.wav",
        "../sfx/walter.wav"
    };

    srand((unsigned) time(&now));
    int randomIndex = rand() % sizeof(sfxArr) / sizeof(sfxArr[0]);

    int inHours, inMinutes;

    FILE* info = fopen("../info.txt", "r");
    
    char information[6];

    char c;
    int i = 0;
    while((c = fgetc(info)) != EOF) {
        information[i] = c;
        i++;
    }

    if(information[0] - '0' == 0) {
        inHours = information[1] - '0';
    } else {
        inHours = ((information[0] - '0') * 10) + (information[1] - '0');
    }

    if(information[2] - '0' == 0) {
        inMinutes = information[3] - '0';
    } else {
        inMinutes = ((information[2] - '0') * 10) + (information[3] - '0');
    }

    char state[3];

    if(information[4] == 'P') {
        strncpy(state, "PM", 3);
    } else {
        strncpy(state, "AM", 3);
    }

    if(strcmp(state, "PM") == 0) {
        inHours += 12;
    }

    for(;;) {
        time(&now);
        
        struct tm *local = localtime(&now);
        hours = local->tm_hour;
        minutes = local->tm_min;
        seconds = local->tm_sec;
        
        if(strcmp(state, "AM") == 0) {
            if(hours > 10 && minutes > 10 && seconds > 10) printf("\rcurrent time: %d:%d:%d AM", hours, minutes, seconds);
            else if(hours > 10 && minutes > 10 && seconds < 10) printf("\rcurrent time: %d:%d:0%d AM", hours, minutes, seconds);
            else if(hours > 10 && minutes < 10 && seconds > 10) printf("\rcurrent time: %d:0%d:%d AM", hours, minutes, seconds);
            else if(hours > 10 && minutes < 10 && seconds < 10) printf("\rcurrent time: %d:0%d:0%d AM", hours, minutes, seconds);
            else if(hours < 10 && minutes > 10 && seconds > 10) printf("\rcurrent time: 0%d:%d:%d AM", hours, minutes, seconds);
            else if(hours < 10 && minutes > 10 && seconds < 10) printf("\rcurrent time: 0%d:%d:0%d AM", hours, minutes, seconds);
            else if(hours < 10 && minutes < 10 && seconds > 10) printf("\rcurrent time: 0%d:0%d:%d AM", hours, minutes, seconds);
            else if(hours < 10 && minutes < 10 && seconds < 10) printf("\rcurrent time: 0%d:0%d:0%d AM", hours, minutes, seconds);
        } else {
            if(hours > 10 && minutes > 10 && seconds > 10) printf("\rcurrent time: %d:%d:%d PM", hours - 12, minutes, seconds);
            else if(hours > 10 && minutes > 10 && seconds < 10) printf("\rcurrent time: %d:%d:0%d PM", hours - 12, minutes, seconds);
            else if(hours > 10 && minutes < 10 && seconds > 10) printf("\rcurrent time: %d:0%d:%d PM", hours - 12, minutes, seconds);
            else if(hours > 10 && minutes < 10 && seconds < 10) printf("\rcurrent time: %d:0%d:0%d PM", hours - 12, minutes, seconds);
            else if(hours < 10 && minutes > 10 && seconds > 10) printf("\rcurrent time: 0%d:%d:%d PM", hours - 12, minutes, seconds);
            else if(hours < 10 && minutes > 10 && seconds < 10) printf("\rcurrent time: 0%d:%d:0%d PM", hours - 12, minutes, seconds);
            else if(hours < 10 && minutes < 10 && seconds > 10) printf("\rcurrent time: 0%d:0%d:%d PM", hours - 12, minutes, seconds);
            else if(hours < 10 && minutes < 10 && seconds < 10) printf("\rcurrent time: 0%d:0%d:0%d PM", hours - 12, minutes, seconds);
        }

        if(hours == inHours && minutes == inMinutes) {
            break;
        }

        Sleep(1000);
    }

    fclose(info);

    PlaySound(sfxArr[randomIndex], NULL, SND_FILENAME);

    return 0;
}