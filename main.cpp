#include "model/contactsfilteringproxy.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>
#include <QtSql>

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView* view = new QQuickView();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("contacts.db");
    if (!db.open()) {
        qFatal("unable to open database");
    }

    qmlRegisterAnonymousType<ContactsModel>("ContactsModel", 1);

    ContactsFilteringProxy* proxy = new ContactsFilteringProxy(&app, std::move(db));

    view->rootContext()->setContextProperty("cppModel", proxy);

    view->setSource(QUrl("qrc:/main.qml"));
    view->show();

    return app.exec();
}
