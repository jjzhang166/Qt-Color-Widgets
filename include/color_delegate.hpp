/**
 * \file
 *
 * \author Mattia Basaglia
 *
 * \copyright Copyright (C) 2012-2015 Mattia Basaglia
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef COLOR_DELEGATE_HPP
#define COLOR_DELEGATE_HPP

#include "colorwidgets_global.hpp"

#include <QStyledItemDelegate>

namespace color_widgets {

/**
    Delegate to use a ColorSelector in a color list
*/
class QCP_EXPORT ColorDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ColorDelegate(QWidget *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
                    const QModelIndex &index) const;

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                               const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    void setModelData(QWidget *editor, QAbstractItemModel *model,
                        const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

private slots:
    void color_changed();
    void close_editor();
};

} // namespace color_widgets

#endif // COLOR_DELEGATE_HPP
