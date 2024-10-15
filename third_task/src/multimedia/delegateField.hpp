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
	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index);

private:
};

#endif
