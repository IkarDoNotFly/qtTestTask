#include "contactsfilteringproxy.h"

ContactsFilteringProxy::ContactsFilteringProxy(QObject* parent, QSqlDatabase&& db)
    : QSortFilterProxyModel(parent)
{
    m_model = new ContactsModel(this, std::move(db));
    setFilterRole(ContactsModel::Name);
    setFilterCaseSensitivity(Qt::CaseSensitive);
    setFilterFixedString(QString());
    setSourceModel(m_model);
}

void ContactsFilteringProxy::updateWildcard(QString str)
{
    qDebug() << "Setting wildcard to " << str;
    setFilterWildcard(str);
}
