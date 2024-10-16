#include "delegateField.hpp"
#include <QLineEdit>
#include <QDebug>
#include <QDoubleValidator>
#include <QLocale>

QWidget *DelegateField::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
	auto editor = new QLineEdit(parent);
	auto validator = new QDoubleValidator(0, 1, 4);
	validator->setLocale(QLocale::C);
	editor->setValidator(validator);
    return editor;
}

void DelegateField::setEditorData(QWidget *editor, const QModelIndex &index) const {
    QLineEdit *edit = static_cast<QLineEdit*>(editor);

	QString value = index.model()->data(index, Qt::EditRole).toString();
	qDebug() << value;
	edit->setText(value);
}

void DelegateField::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) {
	QLineEdit *edit = static_cast<QLineEdit*>(editor);
    QString value = edit->text();
    model->setData(index, value, Qt::EditRole);
}
