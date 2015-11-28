#include <QApplication>
#include "mainwindow.h"

// Tests
#include <QDebug>
#include <omp.h>
void testLang()
{
    #pragma omp parallel // OpenMp Test
    {
        int th_id = omp_get_thread_num();

        // C++11 and C++14 Test
        auto testLamda = [](auto id) {
            auto binary = 0b1001;
            qDebug() << "Hello world" << id << "Binary value " << binary;
            return binary;
        };
        testLamda(th_id);
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    testLang();

    MainWindow window;
    window.show();
    return app.exec();
}
