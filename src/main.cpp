#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <iostream>
#include <QString>
#include "translation.h"
#include "stringparser.h"
#include "parser.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<Translation>();
    qRegisterMetaType<Parser::ParsingErrors>();
    qRegisterMetaType<StringParser::TranslationParsingModes>();

    QTranslator tr;

    // Check user local language
    QString locale = QLocale::system().name();
    if(locale.startsWith("fr"))
        tr.load(":/lang/fr");
    else if(locale.startsWith("es"))
        tr.load(":/lang/es");
    else if(locale.startsWith("zh"))
        tr.load(":/lang/zh");


    a.installTranslator(&tr);

    MainWindow w;
    w.show();

    return a.exec();
}
