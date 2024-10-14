#ifndef __DELEGATE_FIELD_HPP__
#define __DELEGATE_FIELD_HPP__

#include <QWidget>
#include <QScopedPointer>
#include <QItemDelegate>
#include <QTableWidget>


class DelegateField : public QItemDelegate {
    Q_OBJECT

public:
    DelegateField(QObject *parent = 0) :QItemDelegate(parent){}
    virtual ~DelegateField(){}

	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
private:
};

#endif
