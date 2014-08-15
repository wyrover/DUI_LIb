#include "stdafx.h"
#include "DefaultFeatures.h"

DWORD g_dwDefaultHeight = 30;
DWORD g_dwDefaultWidth = 80;

LPCTSTR g_lpszDefaultLabelFeature = _T("pos=\"%d,%d,%d,%d\" text=\"%s\" float=\"true\" align=\"left\" bkcolor=\"#FFB9D1EF\" textcolor=\"#FF000000\";");
LPCTSTR g_lpszDefaultButtonFeature = _T("pos=\"%d,%d,%d,%d\" text=\"%s\" float=\"true\" bkcolor2=\"#FF757676\" bkcolor=\"#FFB9D1EF\" bordercolor=\"#FF000000\" bordersize=\"1\";");
LPCTSTR g_lpszDefaultCheckBoxFeature = _T("pos=\"%d,%d,%d,%d\" text=\"{x 5}%s\" float=\"true\" showhtml=\"true\" fitallArea=\"false\" selectedimage=\"%scheckbox_checked.png\" normalimage=\"%scheckbox_unchecked.png\" bordercolor=\"#FF000000\" bkcolor=\"#FFB9D1EF\" bordersize=\"1\";");
LPCTSTR g_lpszDefaultRadioBoxFeature = _T("pos=\"%d,%d,%d,%d\" text=\"{x 5}%s\" float=\"true\" showhtml=\"true\" fitallArea=\"false\" selectedimage=\"%sradio_checked.png\" normalimage=\"%sradio_unchecked.png\" bordercolor=\"#FF000000\" bkcolor=\"#FFB9D1EF\" bordersize=\"1\";");
LPCTSTR g_lpszDefaultListFeature = _T("pos=\"%d,%d,%d,%d\" float=\"true\" header=\"hidden\" bkcolor=\"#FFE0F0FE\" inset=\"1,0,1,0\" bordercolor=\"#FF1B4876\" bordersize=\"1\" vscrollbar=\"true\" hscrollbar=\"true\"");
LPCTSTR g_lpszDefaultComboxFeature = _T("pos=\"%d,%d,%d,%d\" text=\"%s\" float=\"true\" bordercolor=\"#FF000000\" bordersize=\"1\" dropboxsize=\"0, 150\" droptype=\"dropdown\" dropbtnimage=\"file='%slist_down.png'';\"");
LPCTSTR g_lpszDefaultEditFeature = _T("pos=\"%d,%d,%d,%d\" text=\"%s\" float=\"true\" bordercolor=\"#FF000000\" bordersize=\"1\";");
LPCTSTR g_lpszDefaultProgressFeature = _T("pos=\"%d,%d,%d,%d\" float=\"true\" fgimage=\"file='%sprogress.png' corner='2,2,2,2'\" min=\"0\" max=\"100\" value=\"15\" bordercolor=\"#FF0000FF\" bkcolor=\"#FFB9D1EF\";");

LPCTSTR g_lpszDefaultVScrollbarFeature = _T("pos=\"%d,%d,%d,%d\" float=\"true\" button1normalimage=\"file='%svscroll.png' source='0,0,16,16'\" button1hotimage=\"file='%svscroll.png' source='0,0,16,16' mask='#FFFF00FF'\" button1pushedimage=\"file='%svscroll.png' source='0,16,16,32' mask='#FFFF00FF'\" button1disabledimage=\"file='%svscroll.png' source='0,0,16,16' mask='#FFFF00FF'\" button2normalimage=\"file='%svscroll.png' source='0,32,16,48' mask='#FFFF00FF'\" button2hotimage=\"file='%svscroll.png' source='0,32,16,48' mask='#FFFF00FF'\" button2pushedimage=\"file='%svscroll.png' source='0,48,16,64' mask='#FFFF00FF'\" button2disabledimage=\"file='%svscroll.png' source='0,32,16,48' mask='#FFFF00FF'\" thumbnormalimage=\"file='%svscroll.png' source='0,64,16,80' corner='2,2,2,2' mask='#FFFF00FF'\" thumbhotimage=\"file='%svscroll.png' source='0,64,16,80' corner='2,2,2,2' mask='#FFFF00FF'\" thumbpushedimage=\"ffile='%svscroll.png' source='0,64,16,80' corner='2,2,2,2' mask='#FFFF00FF'\" thumbdisabledimage=\"file='%svscroll.png' source='0,64,16,80' corner='2,2,2,2' mask='#FFFF00FF'\" railnormalimage=\"file='%svscroll.png' source='0,80,16,96' corner='2,2,2,2' mask='#FFFF00FF'\" railhotimage=\"file='%svscroll.png' source='0,80,16,96' corner='2,2,2,2' mask='#FFFF00FF'\" railpushedimage=\"file='%svscroll.png' source='0,96,16,112' corner='2,2,2,2' mask='#FFFF00FF'\" raildisabledimage=\"file='%svscroll.png' source='0,80,16,96' corner='2,2,2,2' mask='#FFFF00FF'\" bknormalimage=\"file='%svscroll.png' source='0,128,16,146' corner='2,2,2,2' mask='#FFFF00FF'\" bkhotimage=\"file='%svscroll.png' source='0,128,16,146' corner='2,2,2,2' mask='#FFFF00FF'\" bkpushedimage=\"file='%svscroll.png' source='0,128,16,146' corner='2,2,2,2' mask='#FFFF00FF'\" bkdisabledimage=\"file='%svscroll.png' source='0,128,16,146' corner='2,2,2,2' mask='#FFFF00FF'\"");
LPCTSTR g_lpszDefaultHScrollbarFeature = _T("pos=\"%d,%d,%d,%d\" float=\"true\" button1normalimage=\"file='%shscroll.png' source='0,0,16,16'\" button1hotimage=\"file='%shscroll.png' source='0,0,16,16' mask='#FFFF00FF'\" button1pushedimage=\"file='%shscroll.png' source='0,16,32,16' mask='#FFFF00FF'\" button1disabledimage=\"file='%shscroll.png' source='0,0,16,16' mask='#FFFF00FF'\" button2normalimage=\"file='%shscroll.png' source='32,0,48,16' mask='#FFFF00FF'\" button2hotimage=\"file='%shscroll.png' source='32,0,48,16' mask='#FFFF00FF'\" button2pushedimage=\"file='%svscroll.png' source='48,0,64,16' mask='#FFFF00FF'\" button2disabledimage=\"file='%shscroll.png' source='32,0,48,16' mask='#FFFF00FF'\" thumbnormalimage=\"file='%shscroll.png' source='64,0,80,16' corner='2,2,2,2' mask='#FFFF00FF'\" thumbhotimage=\"file='%shscroll.png' source='64,0,80,16' corner='2,2,2,2' mask='#FFFF00FF'\" thumbpushedimage=\"ffile='%shscroll.png' source='64,0,80,16' corner='2,2,2,2' mask='#FFFF00FF'\" thumbdisabledimage=\"file='%shscroll.png' source='64,0,80,16' corner='2,2,2,2' mask='#FFFF00FF'\" railnormalimage=\"file='%shscroll.png' source='80,0,96,16' corner='2,2,2,2' mask='#FFFF00FF'\" railhotimage=\"file='%shscroll.png' source='80,0,96,16' corner='2,2,2,2' mask='#FFFF00FF'\" railpushedimage=\"file='%shscroll.png' source='96,0,112,16' corner='2,2,2,2' mask='#FFFF00FF'\" raildisabledimage=\"file='%shscroll.png' source='80,0,96,16' corner='2,2,2,2' mask='#FFFF00FF'\" bknormalimage=\"file='%shscroll.png' source='128,0,146,16' corner='2,2,2,2' mask='#FFFF00FF'\" bkhotimage=\"file='%shscroll.png' source='128,0,146,16' corner='2,2,2,2' mask='#FFFF00FF'\" bkpushedimage=\"file='%shscroll.png' source='128,0,146,16' corner='2,2,2,2' mask='#FFFF00FF'\" bkdisabledimage=\"file='%shscroll.png' source='128,0,146,16' corner='2,2,2,2' mask='#FFFF00FF'\"");

LPCTSTR g_lpszDefaultContainerFeature = _T("pos=\"%d,%d,%d,%d\" float=\"true\" bkcolor=\"#FF757676\" vscrollbar=\"true\";");

LPCTSTR g_lpszDefaultHSliderFeature = _T("pos=\"%d,%d,%d,%d\" float=\"true\" inset=\"0,2,0,2\" bordersize=\"0\" height=\"18\" thumbimage=\"%shslider.png\" thumbhotimage=\"%shslider.png\" thumbpushedimage=\"%shslider.png\" bkimage=\"file='%shadj_hue.png' source='0,0,124,6' dest='1,6,120,12' mask='#FFFF00FF'\"  thumbsize=\"12,18\";");
LPCTSTR g_lpszDefaultVSliderFeature = _T("pos=\"%d,%d,%d,%d\" float=\"true\" inset=\"2,0,2,0\" bordersize=\"0\" width=\"18\" thumbimage=\"%svslider.png\" thumbhotimage=\"%svslider.png\" thumbpushedimage=\"%svslider.png\" bkimage=\"file='%svadj_hue.png' source='0,0,6,124' dest='6,1,12,120' mask='#FFFF00FF'\"  thumbsize=\"18,12\";");