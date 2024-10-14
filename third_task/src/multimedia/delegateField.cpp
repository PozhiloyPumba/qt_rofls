#include "delegateField.hpp"
#include <QLineEdit>
#include <iostream>
#include <QDoubleValidator>

QWidget *DelegateField::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
	auto editor = new QLineEdit(parent);
	editor->setValidator(new QDoubleValidator(0, 1, 4));
    return editor;
}
