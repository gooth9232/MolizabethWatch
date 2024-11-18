#include "Watchy_Molizabeth.h"
#include "Molizabeth.h"

#ifdef WATCHY_SIM
bool NTP_SYNC;
#else
RTC_DATA_ATTR bool NTP_SYNC;
#endif

void WatchyMolizabeth::drawWatchFace(){

#ifdef WATCHY_SIM
    srand(currentTime.Hour + currentTime.Minute + currentTime.Wday);
#else
    randomSeed(currentTime.Hour + currentTime.Minute + currentTime.Wday);
#endif
    display.fillScreen(GxEPD_WHITE);

    for (int roop = 0; roop < 4; roop++) {
        for (int film_index = 0; film_index < 4; film_index++) {
            display.fillScreen(GxEPD_WHITE);

            if (roop >=2 && film_index == 3) {
                //Hour
                drawSeg(currentTime.Hour / 10, 12, 11);
                drawSeg(currentTime.Hour % 10, 19, 11);

                //Minute
                drawSeg(currentTime.Minute / 10, 16, 20);
                drawSeg(currentTime.Minute % 10, 23, 20);
            }

            drawBack(film_index);
            for (int member_index = 0; member_index < 11; member_index++) {
                drawOneMember(member_index, film_index);
            }

            // Battery Level
            drawMic();

#ifdef WATCHY_SIM
            Sleep(200);
#else
            display.display(true);
            delay(100);
#endif
        }
    }

    // NTP
    drawQoo();

}

void WatchyMolizabeth::drawOneMember(const int& target, const int& film_index) {
    int index_x = drawIndex[target][0];
    int index_y = drawIndex[target][1];

    // Mask
    display.drawBitmap(INDEX_SIZE * index_x, INDEX_SIZE * index_y, grap_member_Array[target][1][film_index], 60, 60, GxEPD_WHITE);

    // Draw
    display.drawBitmap(INDEX_SIZE * index_x, INDEX_SIZE * index_y, grap_member_Array[target][0][film_index], 60, 60, GxEPD_BLACK);
}

void WatchyMolizabeth::drawBack(const int& film_index) {
    switch (film_index) {
    case 0:
        display.drawBitmap(0, 0, grap_Back_Array[0], 200, 200, GxEPD_BLACK);
        break;
    case 1:
        display.drawBitmap(0, 0, grap_Back_Array[1], 200, 200, GxEPD_BLACK);
        break;
    case 2:
        display.drawBitmap(0, 0, grap_Back_Array[0], 200, 200, GxEPD_BLACK);
        display.drawBitmap(0, 0, grap_Back_Array[1], 200, 200, GxEPD_BLACK);
        break;
    case 3:
        break;
    }
}

void WatchyMolizabeth::drawSeg(const int& num, int index_x, int index_y)
{
    display.drawBitmap(INDEX_SIZE * index_x, INDEX_SIZE * index_y, grap_Number_Array[num], INDEX_SIZE * 7, INDEX_SIZE * 9, GxEPD_BLACK);
}

void WatchyMolizabeth::drawMic()
{
    float VBAT = getBatteryVoltage();
    if (VBAT > 4.00) { VBAT = 4.00; };
    float VLevel = VBAT - 3.0; // meter:3.99Å`3.00

    display.drawBitmap(INDEX_SIZE * (drawIndex[10][0] + 7) , INDEX_SIZE * (drawIndex[10][1] + 8 - int(VLevel * 8)), grap_Mic_mask, INDEX_SIZE * 6, INDEX_SIZE * 12, GxEPD_WHITE);
    display.drawBitmap(INDEX_SIZE * (drawIndex[10][0] + 7) , INDEX_SIZE * (drawIndex[10][1] + 8 - int(VLevel * 8)), grap_Mic, INDEX_SIZE * 6, INDEX_SIZE * 12, GxEPD_BLACK);
}

void WatchyMolizabeth::drawQoo()
{
    if (currentTime.Minute == 0) {
        NTP_SYNC = false;
#ifndef WATCHY_SIM
        connectWiFi();
#endif
        if (WIFI_CONFIGURED) {
#ifdef WATCHY_SIM
            NTP_SYNC = true;
#else
            NTP_SYNC = syncNTP();
#endif
        }
    }

    if (NTP_SYNC) {
        display.drawBitmap(INDEX_SIZE * (drawIndex[0][0] + 5), INDEX_SIZE * (drawIndex[0][1] + 8)+3, grap_Qoo, INDEX_SIZE * 3, INDEX_SIZE * 3, GxEPD_BLACK);
    }

#ifndef WATCHY_SIM
    WiFi.mode(WIFI_OFF);
    btStop();
#endif

}