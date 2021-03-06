#include "../headers/actor_ou_matrix.h"
#include <QTableView>
#include <QVBoxLayout>
#include <QtSql>
#include <QDebug>
#include <QDialogButtonBox>

ActorOuMatrix::ActorOuMatrix(QWidget* parent) : QDialog(parent)
{
	QVBoxLayout* mainlayout = new QVBoxLayout;
	ActorOuMatrixTable = new QTableView;
	
	QSqlQueryModel* ouActorMatrixModel = new QSqlQueryModel();
	ouActorMatrixModel->setQuery("SELECT name, lastName, (SELECT name FROM OrganizationalUnits WHERE OrganizationalUnits.ou_id = Actors.ou_id) AS 'Organizational Unit' FROM Actors");
	ActorOuMatrixTable->setModel(ouActorMatrixModel);
	
	QDialogButtonBox* actorOuMatrixButtonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox:: Cancel);
	

	mainlayout->addWidget(ActorOuMatrixTable);
	mainlayout->addWidget(actorOuMatrixButtonBox);
	this->setLayout(mainlayout);
	
	connect(actorOuMatrixButtonBox, SIGNAL(accepted()),
			this,SLOT(accept()));
	connect(actorOuMatrixButtonBox, SIGNAL(rejected()),
			this,SLOT(reject()));

	
}
