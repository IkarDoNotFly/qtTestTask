#ifndef CONTACTSMODEL_H
#define CONTACTSMODEL_H

#include <QtSql>

class ContactsModel : public QSqlTableModel {
    Q_OBJECT

public:
    enum Roles {
        ImagePath = Qt::UserRole + 1,
        Number,
        Name,
    };
    explicit ContactsModel(QObject* parent, QSqlDatabase&& db);
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE QVariant data(const QModelIndex& index, int role) const override;
};

#endif // CONTACTSMODEL_H
