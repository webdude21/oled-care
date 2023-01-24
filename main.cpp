#include <iostream>
#include <windows.h>

int main()
{
    Sleep(5000); // sleep for 5 seconds to allow user to select the window to move
    RECT rs, rd;
    HWND hw;
    HWND hwnd;

    for (hwnd = GetTopWindow(NULL); hwnd != NULL; hwnd = GetNextWindow(hwnd, GW_HWNDNEXT))
    {
        if (!IsWindowVisible(hwnd) || GetWindowTextLength(hwnd) == 0)
        {
            continue;
        }
        else
        {
            break;
        }
    }

    while (true)
    {

        int minOffset = 50;
        int maxOffset = 100;
        srand(time(NULL));
        int offset = minOffset + (std::rand() % (maxOffset - minOffset + 1));
        int percentage = 1 + (std::rand() % (100 - 1));

        if (percentage > 50)
        {
            offset = offset * -1;
        }

        hw = GetDesktopWindow();
        if (GetWindowRect(hw, &rs) && GetWindowRect(hwnd, &rd))
            MoveWindow(hwnd,
                       ((rs.right + rs.left + rd.left - rd.right) / 2) + offset,
                       ((rs.bottom + rs.top + rd.top - rd.bottom) / 2) + offset,
                       rd.right - rd.left, rd.bottom - rd.top, TRUE);

        printf("Moving window with an offset: %d\n", offset);
        printf("rs.right is %d, rs.left is %d, rd.left is %d, rd.right is %d\n", rs.right, rs.left, rd.left, rd.right);
        printf("rs.bottom is %d, rs.top is %d, rd.top is %d, rd.bottom is %d\n", rs.bottom, rs.top, rd.top, rd.bottom);
        Sleep(60 * 1000);
    }
}