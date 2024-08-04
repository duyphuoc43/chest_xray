#include <windows.h>
#include <iostream>
#include <chrono>
#include <iomanip>  // Để sử dụng std::put_time

void MoveMouse(int x, int y) {
    // Di chuyển chuột đến tọa độ (x, y)
    SetCursorPos(x, y);
}

void ClickMouseLeft() {
    // Mô phỏng nhấn chuột trái
    INPUT input = { 0 };
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN; // Nhấn chuột trái
    SendInput(1, &input, sizeof(INPUT));

    // Mô phỏng thả chuột trái
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP; // Thả chuột trái
    SendInput(1, &input, sizeof(INPUT));
}
void DoubleClickMouseLeft() {
    ClickMouseLeft(); // Nhấp chuột trái lần 1
    Sleep(50);        // Đợi 50ms giữa các lần nhấp (có thể điều chỉnh)
    ClickMouseLeft(); // Nhấp chuột trái lần 2
}

// Mô phỏng gõ một phím
void SendKey(WORD key) {
    INPUT input = { 0 };
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key; // Mã phím
    input.ki.dwFlags = 0; // Nhấn phím
    SendInput(1, &input, sizeof(INPUT));

    // Thả phím
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}

// Gõ dãy số từ bàn phím
void TypeNumber(const std::string& number) {
    for (char digit : number) {
        SendKey(VK_NUMPAD0 + (digit - '0')); // Gửi mã phím cho các số từ 0-9
        Sleep(50); // Đợi một chút giữa các phím (có thể điều chỉnh)
    }
}


int main() {
    Sleep(3000);
    int x = 380;
    int y = 380;
    while (true) {
        SYSTEMTIME st;
        GetLocalTime(&st);
        std::cout << "Current time: "
            << st.wYear << "-" << st.wMonth << "-" << st.wDay << " "
            << st.wHour << ":" << st.wMinute << ":" << st.wSecond << std::endl;

        int phut = st.wMinute % 5;
        std::cout << phut;
        //if (1) {
        if (st.wHour == 23 && st.wMinute >= 50) {
            Sleep(1200000);
        }
        //else if (1) {
        else if (1 <= phut && phut <= 1) {
            MoveMouse(x + 200, y + 390);
            ClickMouseLeft();
            Sleep(500);
            MoveMouse(x, y);
            ClickMouseLeft();
            Sleep(500);
            MoveMouse(x + 120, y + 320);
            DoubleClickMouseLeft();
            Sleep(500);
            TypeNumber("518");
            Sleep(500);
            MoveMouse(x + 20, y + 390);
            ClickMouseLeft();
            Sleep(2000);
            MoveMouse(x + 350, y + 270);
            ClickMouseLeft();

            std::cout << "------------------Tai----------------" << std::endl;
            Sleep(500);

            MoveMouse(x + 200, y + 390);
            ClickMouseLeft();
            Sleep(500);
            MoveMouse(x + 70, y);
            ClickMouseLeft();
            Sleep(500);
            MoveMouse(x + 120, y + 320);
            DoubleClickMouseLeft();
            Sleep(500);
            TypeNumber("582");
            Sleep(500);
            MoveMouse(x + 20, y + 390);
            ClickMouseLeft();
            Sleep(2000);
            MoveMouse(x + 350, y + 270);
            ClickMouseLeft();
            std::cout << "------------------Xiu----------------" << std::endl;

            std::cout << "Runed" << std::endl;
            std::cout << "Current time: "
                << st.wHour << ":" << st.wMinute << ":" << st.wSecond << std::endl;
            std::cout << "_______________________DONE_____________________";
            Sleep(250000); //5 phút
            //Sleep(50000); //1 phút

        }
        else {
            std::cout << "Don't Run" << std::endl;
            std::cout << "Current time: "
                << st.wHour << ":" << st.wMinute << ":" << st.wSecond << std::endl;
            Sleep(5000); // Chờ 10 giây trước khi kiểm tra lại
        }
        std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    }
    return 0;
}
