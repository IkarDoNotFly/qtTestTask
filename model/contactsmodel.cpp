#include "contactsmodel.h"

ContactsModel::ContactsModel(QObject* parent, QSqlDatabase&& db)
    : QSqlTableModel(parent, std::move(db))
{
    setTable("contact");

    if (!select()) {
        qDebug() << lastError().text();
        throw lastError();
    }
}

QHash<int, QByteArray> ContactsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ImagePath] = "image_path";
    roles[Number] = "number";
    roles[Name] = "name";
    return roles;
}

QVariant ContactsModel::data(const QModelIndex& index, int role) const
{
    QVariant value;
    if (role < Qt::UserRole) {
        value = QSqlTableModel::data(index, role);
    } else {
        int columnIdx = role - Qt::UserRole - 1;
        QModelIndex modelIndex = this->index(index.row(), columnIdx);
        value = QSqlTableModel::data(modelIndex, Qt::DisplayRole);
    }
    return value;
}
