#pragma once

#include "../common/parameters.h"
#include "../common/common.h"
#include "../common/etlbase.h"

#include "sinks/MainWindowPropertySink.h"
#include "sinks/MainWindowCommandSink.h"

#include <fstream>
#include <QDialog>
#include <QDebug>
#include <QApplication>
#include <QStyleFactory>
#include <QComboBox>
#include <QLabel>
#include <QSpinBox>
#include <QGroupBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFileDialog>


#include <iostream>
#include <string>
#include <memory>

class QCheckBox;
class QComboBox;
class QDateTimeEdit;
class QDial;
class QGroupBox;
class QLabel;
class QLineEdit;
class QProgressBar;
class QPushButton;
class QRadioButton;
class QScrollBar;
class QSlider;
class QSpinBox;
class QTabWidget;
class QTableWidget;
class QTextEdit;


class ViewClass: public QDialog
{
    Q_OBJECT

    public:
        explicit ViewClass(QWidget *parent = nullptr);
        void set_InsertCommand(const std::shared_ptr<ICommandBase>& cmd) throw();
        void set_DeleteCommand(const std::shared_ptr<ICommandBase>& cmd) throw();
        void set_FindCommand(const std::shared_ptr<ICommandBase>& cmd) throw();
        void set_PreOrderCommand(const std::shared_ptr<ICommandBase>& cmd) throw();
        void set_InOrderCommand(const std::shared_ptr<ICommandBase>& cmd) throw();
        void set_PostOrderCommand(const std::shared_ptr<ICommandBase>& cmd) throw();
        void set_ChangeStyleCommand(const std::shared_ptr<ICommandBase>& cmd) throw();

        std::shared_ptr<IPropertyNotification> get_PropertySink() throw();
        std::shared_ptr<ICommandNotification> get_CommandSink() throw();

        void changeNodeFunction();
        void RotateFunction();
        void HideAllFunction();
        void SetChangeNode(const std::shared_ptr<NodeState>& Node) throw();

    private slots:
        void ClickDeleteAction(int i);
        void changeStyle(const QString &styleName);
        void InsertAction();
        void DeleteAction();
        void FindAction();
        void PreOrderAction();
        void InOrderAction();
        void PostOrderAction();
        void ChooseFileAction();


    public:

        std::shared_ptr<NodeState> ChangeNode;

        std::shared_ptr<ICommandBase> m_cmdInsert;
        std::shared_ptr<ICommandBase> m_cmdDelete;
        std::shared_ptr<ICommandBase> m_cmdFind;
        std::shared_ptr<ICommandBase> m_cmdPreOrder;
        std::shared_ptr<ICommandBase> m_cmdInOrder;
        std::shared_ptr<ICommandBase> m_cmdPostOrder;
        std::shared_ptr<ICommandBase> m_cmdChangeStyle;

        std::shared_ptr<MainWindowPropertySink> m_sinkProperty;
        std::shared_ptr<MainWindowCommandSink> m_sinkCommand;

        void createDataBox();
        QPalette originalPalette;
        QLabel *styleLabel;
        QComboBox *structureComboBox;
        QGroupBox *DataBox;
        QPushButton *node[64];
        QPushButton *placeholder[44];
        QLabel *line[64];
        QLabel *RightRotate;
        QLabel *LeftRotate;
        QPushButton *DeleteButton;
        QPushButton *ChooseFileButton;
        QPushButton *InsertButton;
        QPushButton *FindButton;
        QPushButton *PreOrderButton;
        QPushButton *InOrderButton;
        QPushButton *PostOrderButton;
        QSpinBox *spinBox;

};

