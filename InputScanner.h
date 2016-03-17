#ifndef InputScanner_h
#define InputScanner_h

class InputScanner
{

 public:

    static void* InputScannerThread(void* arg);
    void alertOvercurrent();
    void alertbeam();
    void alertbutton();


    //GarageDoorOpener *myGarageDoorOpener;
};

#endif // InputScanner_h
