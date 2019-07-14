#include "view.h"


ViewClass::ViewClass(QWidget *parent)
    : QDialog(parent), m_sinkProperty(std::make_shared<MainWindowPropertySink>(this)),
      m_sinkCommand(std::make_shared<MainWindowCommandSink>(this))
{
    this->resize( QSize( 1200, 800 ));
    originalPalette = QApplication::palette();
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    structureComboBox = new QComboBox;
    structureComboBox->addItem("Binary Search Tree");
    structureComboBox->addItem("AVL Tree");
    structureComboBox->addItem("Splay Tree");
    structureComboBox->setStyleSheet("QComboBox{font: large \"Calibri\";font-size:25px; height:30px; width:200px}");


    styleLabel = new QLabel(tr("Data structure:"));
    styleLabel->setBuddy(structureComboBox);
    styleLabel->setStyleSheet("QLabel{font: large \"Calibri\";font-size:30px;color:white;}");

    spinBox = new QSpinBox(this);
    spinBox->setStyleSheet("QSpinBox{font: large \"Calibri\";font-size:25px; height:30px; width:80px}");
    spinBox->setValue(10);

    InsertButton = new QPushButton(tr("Insert"));
    InsertButton->setDefault(false);
    connect(InsertButton, SIGNAL(clicked()),this, SLOT(InsertAction()));
    InsertButton->setStyleSheet("QPushButton{font: large \"Calibri\";font-size:25px; height:35px;width:100px;background:qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #00ffff, stop:0.5 #505050, stop:0.98 #00ffff);border:0px;border-radius:4px;color:white;}QPushButton:hover{background:qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #00FFCC, stop:0.5 #505050, stop:0.98 #00FFCC);}");
    InsertButton->move(120, 44);


    DeleteButton = new QPushButton(tr("Delete"));
    DeleteButton->setDefault(false);
    connect(DeleteButton, SIGNAL(clicked()),this, SLOT(DeleteAction()));
    DeleteButton->setStyleSheet("QPushButton{font: large \"Calibri\";font-size:25px; height:35px;width:100px;background:qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #33FF33, stop:0.5 #505050, stop:0.98 #33FF33);border:0px;border-radius:4px;color:white;}QPushButton:hover{background:qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #BBFF66, stop:0.5 #505050, stop:0.98 #BBFF66);}");
    DeleteButton->move(240, 44);

    FindButton = new QPushButton(tr("Find"));
    FindButton->setDefault(false);
    connect(FindButton, SIGNAL(clicked()),this, SLOT(FindAction()));
    FindButton->setStyleSheet("QPushButton{font: large \"Calibri\";font-size:25px; height:35px;width:100px;background:qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #FFFF00, stop:0.5 #505050, stop:0.98 #FFFF00);border:0px;border-radius:4px;color:white;}QPushButton:hover{background:qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #FFCC22, stop:0.5 #505050, stop:0.98 #FFCC22);}");
    FindButton->move(360, 44);

    PreOrderButton = new QPushButton(tr("PreOrder"));
    PreOrderButton->setDefault(false);
    connect(PreOrderButton, SIGNAL(clicked()),this, SLOT(PreOrderAction()));
    PreOrderButton->setStyleSheet("QPushButton{font: large \"Calibri\";font-size:25px; height:35px;width:100px;background:qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #9999FF, stop:0.5 #505050, stop:0.98 #9999FF);border:0px;border-radius:4px;color:white;}QPushButton:hover{background:qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #CCDDFF, stop:0.5 #505050, stop:0.98 #CCDDFF);}");
    PreOrderButton->move(480, 44);

    InOrderButton = new QPushButton(tr("InOrder"));
    InOrderButton->setDefault(false);
    connect(InOrderButton, SIGNAL(clicked()),this, SLOT(InOrderAction()));
    InOrderButton->setStyleSheet("QPushButton{font: large \"Calibri\";font-size:25px; height:35px;width:100px;background:qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #77DDFF, stop:0.5 #505050, stop:0.98 #77DDFF);border:0px;border-radius:4px;color:white;}QPushButton:hover{background:qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #33FFDD, stop:0.5 #505050, stop:0.98 #33FFDD);}");


    PostOrderButton = new QPushButton(tr("PostOrder"));
    PostOrderButton->setDefault(false);
    connect(PostOrderButton, SIGNAL(clicked()),this, SLOT(PostOrderAction()));
    PostOrderButton->setStyleSheet("QPushButton{font: large \"Calibri\";font-size:25px; height:35px;width:120px;background:qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #F0BBFF, stop:0.5 #505050, stop:0.98 #F0BBFF);border:0px;border-radius:4px;color:white;}QPushButton:hover{background:qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #B088FF, stop:0.5 #505050, stop:0.98 #B088FF);}");

    ChooseFileButton = new QPushButton(tr("ChooseFile"));
    ChooseFileButton->setDefault(false);
    connect(ChooseFileButton, SIGNAL(clicked()),this, SLOT(ChooseFileAction()));
    ChooseFileButton->setStyleSheet("QPushButton{font: large \"Calibri\";font-size:25px; height:35px;width:140px;background:qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #FFB7DD, stop:0.5 #505050, stop:0.98 #FFB7DD);border:0px;border-radius:4px;color:white;}QPushButton:hover{background:qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #FF88C2, stop:0.5 #505050, stop:0.98 #FF88C2);}");

    createDataBox();

    connect(structureComboBox, SIGNAL(activated(QString)),
            this, SLOT(changeStyle(QString)));

    QHBoxLayout *topLayout = new QHBoxLayout;

    topLayout->addWidget(styleLabel);
    topLayout->addWidget(structureComboBox);
    topLayout->addStretch(1);

    QHBoxLayout *optionLayout = new QHBoxLayout;
    optionLayout->addWidget(spinBox);
    optionLayout->addWidget(InsertButton);
    optionLayout->addWidget(DeleteButton);
    optionLayout->addWidget(FindButton);
    optionLayout->addWidget(PreOrderButton);
    optionLayout->addWidget(InOrderButton);
    optionLayout->addWidget(PostOrderButton);
    optionLayout->addWidget(ChooseFileButton);
    optionLayout->addStretch(1);


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(optionLayout);
    mainLayout->addWidget(DataBox);

    setLayout(mainLayout);

    LeftRotate = new QLabel(this);
    LeftRotate->setFixedSize(80, 100);
    LeftRotate->setStyleSheet("QLabel{border-image:url(:/view/images/LeftRotate.png);}");
    LeftRotate->setHidden(true);


    RightRotate = new QLabel(this);
    RightRotate->setFixedSize(80, 100);
    RightRotate->setStyleSheet("QLabel{border-image:url(:/view/images/RightRotate.png);}");
    RightRotate->setHidden(true);

    setWindowTitle(tr("Styles"));

    this->setStyleSheet("QDialog{border-image:url(:/view/images/bg4.jpeg)}");
}

void ViewClass::createDataBox()
{
    DataBox = new QGroupBox();
    QGridLayout *layout = new QGridLayout ;
    DataBox->setStyleSheet("QGroupBox{background:rgba(255,255,255,50)}");

    int i, j;
    int n = 1;
    for(i = 0; i < 11; i++)
    {
        placeholder[i] = new QPushButton(tr(""));
        placeholder[i]->setStyleSheet("QPushButton{height:40px;width:30px;border-image:url(:/view/images/white.png)}");
        layout->addWidget(placeholder[i], i, 33, 1, 1);
    }
    for(i = 0; i < 32; i++)
    {
        placeholder[i+11] = new QPushButton(tr(""));
        placeholder[i+11]->setStyleSheet("QPushButton{height:10px;width:30px;border-image:url(:/view/images/white.png)}");
        layout->addWidget(placeholder[i+11], 11, i, 1, 1);
    }
    for(i = 0; i < 6; i++)
    {
        for(j = 0; j < n; j++)
        {
            node[n-1+j] = new QPushButton(tr(""));
            node[n-1+j]->setStyleSheet("QPushButton{font: large \"Calibri\";font-size:25px;height:50px;width:50px;border-image:url(:/view/images/node.png);}");
            node[n-1+j]->setHidden(true);

            layout->addWidget(node[n-1+j], i*2, j*intpow(2,(5-i)), 1, intpow(2,(5-i)), Qt::AlignHCenter);
            if( i!= 0 )
            {
                if((n-1+j)%2==1)
                {
                    line[n-1+j] = new QLabel(this);
                    line[n-1+j]->setScaledContents(true);
                    if(i<3) line[n-1+j]->setStyleSheet("QLabel{border-image:url(:/view/images/line2__.png);}");
                    else line[n-1+j]->setStyleSheet("QLabel{border-image:url(:/view/images/line2_.png);}");
                    line[n-1+j]->setHidden(true);
                    layout->addWidget(line[n-1+j], i*2-1, j*intpow(2,(5-i)), 1, intpow(2,(5-i)));
                }
                else
                {
                    line[n-1+j] = new QLabel(this);
                    line[n-1+j]->setScaledContents(true);
                    if(i<3) line[n-1+j]->setStyleSheet("QLabel{border-image:url(:/view/images/line1__.png);}");
                    else line[n-1+j]->setStyleSheet("QLabel{border-image:url(:/view/images/line1_.png);}");
                    line[n-1+j]->setHidden(true);
                    layout->addWidget(line[n-1+j], i*2-1, (j)*intpow(2,(5-i)), 1, intpow(2,(5-i)));

                }
            }
        }
        n *= 2;
    }
    for(int i = 0; i < 63; ++i)
    {
        connect(node[i], &QPushButton::clicked, this, [=]{ClickDeleteAction(i);});
    }
    DataBox->setLayout(layout);
}

void ViewClass::ChooseFileAction()
{
    QFileDialog fileDialog;
    fileDialog.setWindowTitle("Select File");
    fileDialog.setFileMode(QFileDialog::ExistingFile);
    fileDialog.setViewMode(QFileDialog::Detail);
    if(fileDialog.exec())
    {
        QStringList fileNames = fileDialog.selectedFiles();
        std::fstream fin;
        fin.open(fileNames.at(0).toStdString());
        int num;
        while(fin >> num)
        {
            m_cmdInsert->SetParameter(num);
            m_cmdInsert->Exec();
            //Sleep(600);
        }
    }
}

void ViewClass::ClickDeleteAction(int i)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Delete warning");
    msgBox.setText("Are you sure to delete the node " + node[i]->text() + " ?");
    msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
    int res = msgBox.exec();
    switch(res)
    {
        case QMessageBox::Yes:
        {
            int num = node[i]->text().toInt();
            m_cmdDelete->SetParameter(num);
            m_cmdDelete->Exec();
        }
        default:
        {
            break;
        }
    }
}

void ViewClass::InsertAction()
{
    std::any param(std::make_any<int>());
    param = spinBox->value();
    m_cmdInsert->SetParameter(param);
    m_cmdInsert->Exec();
}

void ViewClass::set_InsertCommand(const std::shared_ptr<ICommandBase>& cmd) throw()
{
    m_cmdInsert = cmd;
}

void ViewClass::DeleteAction()
{
    std::any param(std::make_any<int>());
    param = spinBox->value();
    m_cmdDelete->SetParameter(param);
    m_cmdDelete->Exec();
}

void ViewClass::set_DeleteCommand(const std::shared_ptr<ICommandBase>& cmd) throw()
{
    m_cmdDelete = cmd;
}

void ViewClass::FindAction()
{
    std::any param(std::make_any<int>());
    param = spinBox->value();
    m_cmdFind->SetParameter(param);
    m_cmdFind->Exec();
}

void ViewClass::set_FindCommand(const std::shared_ptr<ICommandBase>& cmd) throw()
{
    m_cmdFind = cmd;
}

void ViewClass::PreOrderAction()
{
    m_cmdPreOrder->Exec();
}

void ViewClass::set_PreOrderCommand(const std::shared_ptr<ICommandBase>& cmd) throw()
{
    m_cmdPreOrder = cmd;
}

void ViewClass::InOrderAction()
{
    m_cmdInOrder->Exec();
}

void ViewClass::set_InOrderCommand(const std::shared_ptr<ICommandBase>& cmd) throw()
{
    m_cmdInOrder = cmd;
}

void ViewClass::PostOrderAction()
{
    m_cmdPostOrder->Exec();
}

void ViewClass::set_PostOrderCommand(const std::shared_ptr<ICommandBase>& cmd) throw()
{
    m_cmdPostOrder = cmd;
}

void ViewClass::changeStyle(const QString &styleName)
{
    HideAllFunction();
    m_cmdChangeStyle->SetParameter(styleName.toStdString());
    m_cmdChangeStyle->Exec();
}

void ViewClass::set_ChangeStyleCommand(const std::shared_ptr<ICommandBase>& cmd) throw()
{
    m_cmdChangeStyle = cmd;
}

std::shared_ptr<IPropertyNotification> ViewClass::get_PropertySink() throw()
{
    return std::static_pointer_cast<IPropertyNotification>(m_sinkProperty);
}
std::shared_ptr<ICommandNotification> ViewClass::get_CommandSink() throw()
{
    return std::static_pointer_cast<ICommandNotification>(m_sinkCommand);
}

void ViewClass::SetChangeNode(const std::shared_ptr<NodeState>& Node) throw()
{
    ChangeNode = Node;
}

void ViewClass::changeNodeFunction()
{
    int row = ChangeNode->get_row();
    int order = ChangeNode->get_order();
    int value = ChangeNode->get_num();
    int color = ChangeNode->get_state();

    int num = intpow(2, row - 1) + order - 2;
    QString str =  QString::number(value, 10);
    node[num]->setText(str);

    if (color == 0)
    {
        node[num]->setHidden(true);
        if(num != 0) line[num]->setHidden(true);
    }
    else if (color == 1)
    {
        node[num]->setHidden(false);
        node[num]->setStyleSheet("QPushButton{font: large \"Calibri\";font-size:25px;height:50px;width:50px;border-image:url(:/view/images/node.png);}");
        node[num]->repaint();
    }
    else if (color == 2)
    {
        node[num]->setHidden(false);
        node[num]->setStyleSheet("QPushButton{font: large \"Calibri\";font-size:25px;height:50px;width:50px;border-image:url(:/view/images/nodeflash.png);}");
        node[num]->repaint();
    }
    else if (color == 3 )
    {
        node[num]->setHidden(false);
        node[num]->setStyleSheet("QPushButton{font: large \"Calibri\";font-size:25px;height:50px;width:50px;border-image:url(:/view/images/nodeinsert.png);}");
        node[num]->repaint();
    }
    else if (color == 4)
    {
        node[num]->setHidden(false);
        node[num]->setStyleSheet("QPushButton{font: large \"Calibri\";font-size:25px;height:50px;width:50px;border-image:url(:/view/images/nodedelete.png);}");
        node[num]->repaint();
    }
    else if (color == 5)
    {
        node[num]->setHidden(false);
        node[num]->setStyleSheet("QPushButton{font: large \"Calibri\";font-size:25px;height:50px;width:50px;border-image:url(:/view/images/nodefind.png);}");
        node[num]->repaint();
    }
    if(color != 0 && num != 0)
    {
        line[num]->setHidden(false);
        line[num]->repaint();
    }
}

void ViewClass::RotateFunction()
{
    int row = ChangeNode->get_row();
    int order = ChangeNode->get_order();
    int direction = ChangeNode->get_state();

    if(direction == 0)
    {
        RightRotate->setHidden(true);
        LeftRotate->setHidden(true);
    }
    else if(direction == 1)
    {
        RightRotate->setHidden(false);
        RightRotate->move(20*(2*order-1)*intpow(2,(6-row))+(20*(6-row)), 110*row);
        RightRotate->repaint();
    }
    else if(direction == 2)
    {
        LeftRotate->setHidden(false);
        LeftRotate->move(20*(2*order-1)*intpow(2,(6-row))-190+(row+20), 110*row);
        LeftRotate->repaint();
    }
}

void ViewClass::HideAllFunction()
{
    node[0]->setHidden(true);
    for(int i = 1; i < 63; i++)
    {
        node[i]->setHidden(true);
        line[i]->setHidden(true);
    }
    RightRotate->setHidden(true);
    LeftRotate->setHidden(true);
}
