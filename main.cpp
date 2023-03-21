#include <QTimer>
#include <iostream>

using namespace std;

int main()
{
    FileMonitor monitor;
    monitor.AddFile('a.txt');
    monitor.AddFile('b.txt');
    monitor.AddFile('c.txt');
    monitor.AddFile('d.txt');

}
