#ifndef CONTACTSFILTERINGPROXY_H
#define CONTACTSFILTERINGPROXY_H

#include "contactsmodel.h"

class ContactsFilteringProxy : public QSortFilterProxyModel {
    Q_OBJECT

    ContactsModel* m_model;

public:
    ContactsFilteringProxy(QObject* parent, QSqlDatabase&& db);

    Q_INVOKABLE void updateWildcard(QString str);
};

#endif // CONTACTSFILTERINGPROXY_H
