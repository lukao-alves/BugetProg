#ifndef CATEGORIESINTERFACE_H
#define CATEGORIESINTERFACE_H

#include <QWidget>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QCloseEvent>

#include "CategoryClass.h"

namespace Ui {
    class CategoriesInteface;
}

class CategoriesInteface : public QWidget {
    Q_OBJECT

private:
    Ui::CategoriesInteface *ui;
    CategoryClass *category;
    QStandardItemModel *model;
    QModelIndex index;
    QString itemName;

public:
    /* Show Category Constructor */
    explicit CategoriesInteface(QWidget *parent = 0);

    /* Show Category Destructor */
    ~CategoriesInteface();

    /* Set Category Class */
    void setCategory(CategoryClass* category);

    /* Displaty Categories in Tree View */
    void buildCategoriesTree(void);

signals:
    /* Categories Edited Signal */
    void categoriesEdited(QString type);

private slots:
    /* Display Context Menu */
    void onCustomContextMenu(const QPoint &point);

    /* Handle Item Changes */
    void handleItemChanged(QStandardItem *newItem);

    /* Handle Item Selection Changes */
    void handleItemSelectionChanged(QModelIndex current);

    /* Handle Empty Row after Editing */
    void detectEmptyRow(void);

    /* Handle Add Button Clicked */
    void addButtonClicked(void);

    /* Handle Remove Button Clicked */
    void removeButtonClicked(void);

    /* Handle Edit Button Clicked */
    void editButtonCLicked(void);

    /* Add Category Slot */
    void addCategory(void);

    /* Add Subcategory Slot */
    void addSubcategory(void);

    /* Remove Category SLot */
    void removeCategory(void);

    /* Remove Subcategory SLot */
    void removeSubcategory(void);

    /* Edit Category Slot */
    void updateCategory(void);

    /* Edit Subcategory Slot */
    void updateSubcategory(void);

};

#endif // CATEGORIESINTERFACE_H
