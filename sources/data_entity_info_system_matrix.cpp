#include "../headers/data_entity_info_system_matrix.h"
#include <QTableView>
#include <QVBoxLayout>
#include <QtSql>
#include <QDebug>
#include <QDialogButtonBox>
#include <QHeaderView>

DataEntityInfoSystemMatrix::DataEntityInfoSystemMatrix(QWidget* parent) : QDialog(parent)
{
	QVBoxLayout* mainlayout = new QVBoxLayout;
	DataEntityInfoSystemMatrixTable = new QTableView;
	
	QSqlQueryModel* dataEntityInfoSystemMatrixModel = new QSqlQueryModel();
	dataEntityInfoSystemMatrixModel->setQuery("SELECT name as Nombre, (SELECT name FROM InformationSystemServices WHERE InformationSystemServices.information_service_id = DataEntity.information_service_id ) AS 'Procesado Por' FROM DataEntity");
    DataEntityInfoSystemMatrixTable->verticalHeader()->setVisible(false);
	DataEntityInfoSystemMatrixTable->setModel(dataEntityInfoSystemMatrixModel);

	qDebug()<<dataEntityInfoSystemMatrixModel->lastError();
	
	QDialogButtonBox* dataEntityInfoSystemMatrixButtonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
	

	mainlayout->addWidget(DataEntityInfoSystemMatrixTable);
	mainlayout->addWidget(dataEntityInfoSystemMatrixButtonBox);
	this->setLayout(mainlayout);

	connect(dataEntityInfoSystemMatrixButtonBox, SIGNAL(accepted()),
			this,SLOT(accept()));
	connect(dataEntityInfoSystemMatrixButtonBox, SIGNAL(rejected()),
			this,SLOT(reject()));
}
