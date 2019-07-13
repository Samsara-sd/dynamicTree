#pragma once

#include "common/parameters.h"
#include "common/common.h"

#include "sinks/MainWindowPropertySink.h"
#include "sinks/MainWindowCommandSink.h"

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

        std::shared_ptr<IPropertyNotification> get_PropertySink() throw();
        std::shared_ptr<ICommandNotification> get_CommandSink() throw();
        void changeNodeFunction();
        void SetChangeNode(const std::shared_ptr<NodeState>& Node) throw();

    private slots:
//        void changeStyle(const QString &styleName);
        void InsertAction();
        void DeleteAction();
        void FindAction();
        void PreOrderAction();
        void InOrderAction();
        void PostOrderAction();


    private:

        std::shared_ptr<NodeState> ChangeNode;

        std::shared_ptr<ICommandBase> m_cmdInsert;
        std::shared_ptr<ICommandBase> m_cmdDelete;
        std::shared_ptr<ICommandBase> m_cmdFind;
        std::shared_ptr<ICommandBase> m_cmdPreOrder;
        std::shared_ptr<ICommandBase> m_cmdInOrder;
        std::shared_ptr<ICommandBase> m_cmdPostOrder;

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
        QPushButton *InsertButton;
        QPushButton *FindButton;
        QPushButton *PreOrderButton;
        QPushButton *InOrderButton;
        QPushButton *PostOrderButton;
        QSpinBox *spinBox;

};

