#include "interface/CategoriesInteface.h"
#include "ui_CategoriesInteface.h"

#include <QTreeView>
#include <QStandardItem>
#include <QMenu>
#include <QMessageBox>

/* Show Category Constructor */
CategoriesInteface::CategoriesInteface(QWidget *parent) : QWidget(parent), ui(new Ui::CategoriesInteface) {
    ui->setupUi(this);

    itemName = "";

    model = new QStandardItemModel;

    connect(ui->categorize, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(onCustomContextMenu(const QPoint&)));
    connect(model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(handleItemChanged(QStandardItem*)));
    connect(ui->categorize->itemDelegate(), SIGNAL(closeEditor(QWidget*,QAbstractItemDelegate::EndEditHint)), this, SLOT(detectEmptyRow(void)));
    connect(ui->addButton, SIGNAL(clicked(bool)), this, SLOT(addButtonClicked()));
    connect(ui->deleteButton, SIGNAL(clicked(bool)), this, SLOT(removeButtonClicked()));
    connect(ui->editButton, SIGNAL(clicked(bool)), this, SLOT(editButtonCLicked()));
}

/* Show Category Destructor */
CategoriesInteface::~CategoriesInteface() {
    delete ui;
    delete model;
}

/* Set Category Class */
void CategoriesInteface::setCategory(CategoryClass *category) {
    this->category = category;

    buildCategoriesTree();
}

/* Displaty Categories in Tree View */
void CategoriesInteface::buildCategoriesTree(void) {
    QStandardItem *rootNode = model->invisibleRootItem();

    QStandardItem *expense = new QStandardItem("Despesa");
    expense->setWhatsThis("root");
    expense->setEditable(false);

    QStandardItem *income = new QStandardItem("Receita");
    income->setWhatsThis("root");
    income->setEditable(false);

    QStandardItem *investment = new QStandardItem("Investimento");
    investment->setWhatsThis("root");
    investment->setEditable(false);

    rootNode->appendRow(expense);
    rootNode->appendRow(income);
    rootNode->appendRow(investment);

    QStandardItem *categoryName;
    QStandardItem *subcategoryName;

    QStringList categories;
    QStringList subCategories;
    for(int z = 0; z < rootNode->rowCount(); z++) {
        categories = this->category->getCategories(rootNode->child(z)->text());
        for(int y = 0; y < categories.count(); y++) {
            categoryName = new QStandardItem(categories.value(y));
            categoryName->setWhatsThis("category");
            rootNode->child(z)->appendRow(categoryName);
            subCategories = category->getSubCategories(rootNode->child(z)->text(), categories.value(y));
            for(int x = 0; x < subCategories.count(); x++) {
                if(subCategories.value(x) != "-") {
                    subcategoryName =new QStandardItem(subCategories.value(x));
                    subcategoryName->setWhatsThis("subcategory");
                    categoryName->appendRow(subcategoryName);
                }
            }
        }
    }
    ui->categorize->setModel(model);
    ui->categorize->expandAll();

    connect(ui->categorize->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)), this, SLOT(handleItemSelectionChanged(QModelIndex)));
}

/* Display Context Menu */
void CategoriesInteface::onCustomContextMenu(const QPoint &point) {
    QMenu *contextMenu = new QMenu(ui->categorize);
    index = ui->categorize->indexAt(point);

    if (index.isValid()) {
        if(model->itemFromIndex(index)->whatsThis() == "root")
            contextMenu->addAction("Adicionar Categoria", this, SLOT(addCategory()));

        else if(model->itemFromIndex(index)->whatsThis() == "category") {
            contextMenu->addAction("Editar Categoria", this, SLOT(updateCategory()));
            contextMenu->addAction("Remover Categoria", this, SLOT(removeCategory()));
            contextMenu->addAction("Adicionar Subcategoria", this, SLOT(addSubcategory()));
        }
        else if(model->itemFromIndex(index)->whatsThis() == "subcategory") {
            contextMenu->addAction("Editar Subcategoria", this, SLOT(updateSubcategory()));
            contextMenu->addAction("Remover Subcategoria", this, SLOT(removeSubcategory()));
        }
        contextMenu->exec(ui->categorize->mapToGlobal(point));
    }
}

/* Add Category Slot */
void CategoriesInteface::addCategory(void) {
    QStandardItem *newCategory = new QStandardItem();
    newCategory->setWhatsThis("category");

    model->itemFromIndex(index)->appendRow(newCategory);
    itemName = "";

    ui->categorize->expand(index);
    ui->categorize->edit(newCategory->index());
}

/* Remove Category SLot */
void CategoriesInteface::removeCategory(void) {
    QString type = model->itemFromIndex(index)->parent()->text();
    QString category = model->itemFromIndex(index)->text();

    if(this->category->getSubCategories(type, category).count() != 1) {
        QMessageBox *message = new QMessageBox(QMessageBox::Warning, "Remover Categoria", "Deseja remover a categoria e todas as subcategorias?");
        message->addButton(("Sim"), QMessageBox::YesRole);
        QAbstractButton *noButton = message->addButton("Não", QMessageBox::NoRole);

        message->exec();

        if(message->clickedButton() == noButton)
            return;
    }

    this->category->removeCategory(type, category);

    model->itemFromIndex(index)->parent()->removeRow(index.row());

    emit categoriesEdited(model->itemFromIndex(index)->parent()->text());
}

/* Edit Category Slot */
void CategoriesInteface::updateCategory(void) {
    itemName = model->itemFromIndex(index)->text();
    ui->categorize->edit(index);
}

/* Add Subcategory Slot */
void CategoriesInteface::addSubcategory(void) {
    QStandardItem *newSubcategory = new QStandardItem();
    newSubcategory->setWhatsThis("subcategory");

    model->itemFromIndex(index)->appendRow(newSubcategory);
    itemName = "";

    ui->categorize->expand(index);
    ui->categorize->edit(newSubcategory->index());
}

/* Remove Subcategory Slot */
void CategoriesInteface::removeSubcategory(void) {
    QString type = model->itemFromIndex(index)->parent()->parent()->text();
    QString category = model->itemFromIndex(index)->parent()->text();
    QString subcategory = model->itemFromIndex(index)->text();

    this->category->removeSubcategory(type, category, subcategory);

    model->itemFromIndex(index)->parent()->removeRow(index.row());

    emit categoriesEdited(model->itemFromIndex(index)->parent()->parent()->text());
}

/* Edit Subcategory Slot */
void CategoriesInteface::updateSubcategory(void) {
    itemName = model->itemFromIndex(index)->text();
    ui->categorize->edit(index);
}

/* Handle Empty Row after Editing */
void CategoriesInteface::detectEmptyRow(void) {
    if(model->itemFromIndex(index)->text().isEmpty())
        model->removeRow(index.row(), index.parent());
}

/* Handle Item Changes */
void CategoriesInteface::handleItemChanged(QStandardItem *newItem) {
    try {
        if(newItem->text().isEmpty())
            model->removeRow(newItem->row(), newItem->index().parent());
        else if(newItem->text().length() > 30)
            throw BudgetProgException("Tamanho inválido: Tamanho máximo é de 30 caracteres.");
        else {
            if(newItem->whatsThis() == "category") {
                if(itemName.isEmpty())
                    this->category->addCategory(newItem->parent()->text(), newItem->text());
                else
                    this->category->updateCategory(newItem->parent()->text(), itemName, newItem->text());

                emit categoriesEdited(newItem->parent()->text());
            }
            else if(newItem->whatsThis() == "subcategory") {
                if(itemName.isEmpty())
                    this->category->addSubcategory(newItem->parent()->parent()->text(), newItem->parent()->text(), newItem->text());
                else
                    this->category->updateSubcategory(newItem->parent()->parent()->text(), newItem->parent()->text(), itemName, newItem->text());

                emit categoriesEdited(newItem->parent()->parent()->text());
            }

        }
        ui->categorize->sortByColumn(0, Qt::AscendingOrder);
    }
    catch (BudgetProgException &e) {
        model->removeRow(newItem->row(), newItem->index().parent());
        QMessageBox::warning(0, QObject::tr("Problema ao Adicionar Categoria"), QString::fromStdString(e.showError()));
    }
}

/* Handle Item Selection Changes */
void CategoriesInteface::handleItemSelectionChanged(QModelIndex current) {
    index = current;
}

/* Handle Add Button Clicked */
void CategoriesInteface::addButtonClicked(void) {
    if(model->itemFromIndex(index)->whatsThis() == "root")
        addCategory();
    else if(model->itemFromIndex(index)->whatsThis() == "category")
        addSubcategory();
    else if(model->itemFromIndex(index)->whatsThis() == "subcategory") {
        index = index.parent();
        addSubcategory();
    }
}

/* Handle Remove Button Clicked */
void CategoriesInteface::removeButtonClicked(void) {
    if(model->itemFromIndex(index)->whatsThis() == "category")
        removeCategory();
    else if(model->itemFromIndex(index)->whatsThis() == "subcategory")
        removeSubcategory();
}

/* Handle Edit Button Clicked */
void CategoriesInteface::editButtonCLicked(void) {
    if(model->itemFromIndex(index)->whatsThis() == "category")
        updateCategory();
    else if(model->itemFromIndex(index)->whatsThis() == "subcategory")
        updateSubcategory();
}
