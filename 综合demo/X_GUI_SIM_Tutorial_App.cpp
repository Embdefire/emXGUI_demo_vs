//============================================================================
// Name        : VC_Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include <iostream>
#include <stdio.h>
//#include <stdint.h>

// Windows Header Files:
#include <windows.h>
#include <winbase.h>
#include <winuser.h>
#include <wingdi.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>



#include "gui_drv_cfg.h"

//#pragma comment(lib, "gdi32.lib")


extern "C"{


  void	GUI_DEMO_RotateIcon(void);

}

/*
* LED对话框
*/
extern "C" void App_GUI_Tutorial_DEMO(void)
{
  static int thread = 0;
  static int app = 0;

  if (thread == 0)
  {
    //创建一个独立线程来运行自已...
    CreateThread(NULL, 256 * 1024, (LPTHREAD_START_ROUTINE)App_GUI_Tutorial_DEMO, NULL, 0, NULL);

    thread = 1;
    return;
  }

  if (thread == 1) //线程已创建了?
  {
    if (app == 0)
    {
      app = 1;
      GUI_DEMO_RotateIcon();

      app = 0;
      thread = 0;
    }
    else
    {
      //			MSGBOX(hwnd,L"程序已在运行中...",L"消息提示!");
    }
  }
}

