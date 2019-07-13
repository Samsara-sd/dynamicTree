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

    styleLabel = new QLabel(tr("&Data structure:"));
    styleLabel->setBuddy(structureComboBox);
    styleLabel->setStyleSheet("QLabel{color:white}");

    spinBox = new QSpinBox(this);
    spinBox->setStyleSheet("QSpinBox{width:60px;hight:50px}");
    spinBox->setValue(10);

    InsertButton = new QPushButton(tr("Insert"));
    InsertButton->setDefault(false);
    connect(InsertButton, SIGNAL(clicked()),this, SLOT(InsertAction()));

    DeleteButton = new QPushButton(tr("Delete"));
    DeleteButton->setDefault(false);
    connect(DeleteButton, SIGNAL(clicked()),this, SLOT(DeleteAction()));

    FindButton = new QPushButton(tr("Find"));
    FindButton->setDefault(false);
    connect(FindButton, SIGNAL(clicked()),this, SLOT(FindAction()));

    PreOrderButton = new QPushButton(tr("PreOrder"));
    PreOrderButton->setDefault(false);
    connect(PreOrderButton, SIGNAL(clicked()),this, SLOT(PreOrderAction()));

    InOrderButton = new QPushButton(tr("InOrder"));
    InOrderButton->setDefault(false);
    connect(InOrderButton, SIGNAL(clicked()),this, SLOT(InOrderAction()));

    PostOrderButton = new QPushButton(tr("PostOrder"));
    PostOrderButton->setDefault(false);
    connect(PostOrderButton, SIGNAL(clicked()),this, SLOT(PostOrderAction()));

    createDataBox();

   // connect(structureComboBox, SIGNAL(activated(QString)),
   //         this, SLOT(changeStyle(QString)));


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
    optionLayout->addStretch(1);


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(optionLayout);
    mainLayout->addWidget(DataBox);

    setLayout(mainLayout);

    LeftRotate = new QLabel(this);
    LeftRotate->setFixedSize(80, 100);
    LeftRotate->setStyleSheet("QLabel{border-image:url(D:/vscpath/cpp/Test/dynamicTree/view/images/LeftRotate.png);}");
    LeftRotate->setHidden(true);


    RightRotate = new QLabel(this);
    RightRotate->setFixedSize(80, 100);
    RightRotate->setStyleSheet("QLabel{border-image:url(D:/vscpath/cpp/Test/dynamicTree/view/images/RightRotate.png);}");
    RightRotate->setHidden(true);

    setWindowTitle(tr("Styles"));

    this->setStyleSheet("QDialog{border-image:url(D:/vscpath/cpp/Test/dynamicTree/view/images/bg4.jpeg)}");
}

void ViewClass::createDataBox()
{
    DataBox = new QGroupBox();
    QGridLayout *layout = new QGridLayout ;

    int i, j;
    int n = 1;
    for(i = 0; i < 11; i++)
    {
        placeholder[i] = new QPushButton(tr(""));
        placeholder[i]->setStyleSheet("QPushButton{height:40px;width:30px;border-image:url(D:/vscpath/cpp/Test/dynamicTree/view/images/white.png)}");
        layout->addWidget(placeholder[i], i, 33, 1, 1);
    }
    for(i = 0; i < 32; i++)
    {
        placeholder[i+11] = new QPushButton(tr(""));
        placeholder[i+11]->setStyleSheet("QPushButton{height:10px;width:30px;border-image:url(D:/vscpath/cpp/Test/dynamicTree/view/images/white.png)}");
        layout->addWidget(placeholder[i+11], 11, i, 1, 1);
    }
    for(i = 0; i < 6; i++)
    {
        for(j = 0; j < n; j++)
        {
            node[n-1+j] = new QPushButton(tr(""));
            node[n-1+j]->setHidden(true);
            layout->addWidget(node[n-1+j], i*2, j*intpow(2,(5-i)), 1, intpow(2,(5-i)), Qt::AlignHCenter);
            if( i!= 0 )
            {
                if((n-1+j)%2==1)
                {
                    line[n-1+j] = new QLabel(this);
                    line[n-1+j]->setScaledContents(true);
                    if(i<3) line[n-1+j]->setStyleSheet("QLabel{border-image:url(D:/vscpath/cpp/Test/dynamicTree/view/images/line2__.png);}");
                    else line[n-1+j]->setStyleSheet("QLabel{border-image:url(D:/vscpath/cpp/Test/dynamicTree/view/images/line2_.png);}");
                    line[n-1+j]->setHidden(true);
                    layout->addWidget(line[n-1+j], i*2-1, j*intpow(2,(5-i)), 1, intpow(2,(5-i)));
                }
                else
                {
                    line[n-1+j] = new QLabel(this);
                    line[n-1+j]->setScaledContents(true);
                    if(i<3) line[n-1+j]->setStyleSheet("QLabel{border-image:url(D:/vscpath/cpp/Test/dynamicTree/view/images/line1__.png);}");
                    else line[n-1+j]->setStyleSheet("QLabel{border-image:url(D:/vscpath/cpp/Test/dynamicTree/view/images/line1_.png);}");
                    line[n-1+j]->setHidden(true);
                    layout->addWidget(line[n-1+j], i*2-1, (j)*intpow(2,(5-i)), 1, intpow(2,(5-i)));

                }
            }
        }
        n *= 2;
    }
    DataBox->setLayout(layout);
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
        node[num]->setStyleSheet("QPushButton{font: large \"Calibri\";font-size:25px;height:50px;width:50px;border-image:url(D:/vscpath/cpp/Test/dynamicTree/view/images/node.png);}");
        node[num]->repaint();
    }
    else if (color == 2)
    {
        node[num]->setHidden(false);
        node[num]->setStyleSheet("QPushButton{font: large \"Calibri\";font-size:25px;height:50px;width:50px;border-image:url(D:/vscpath/cpp/Test/dynamicTree/view/images/nodeflash.png);}");
        node[num]->repaint();
    }
    else if (color == 3 )
    {
        node[num]->setHidden(false);
        node[num]->setStyleSheet("QPushButton{font: large \"Calibri\";font-size:25px;height:50px;width:50px;border-image:url(D:/vscpath/cpp/Test/dynamicTree/view/images/nodeinsert.png);}");
        node[num]->repaint();
    }
    else if (color == 4)
    {
        node[num]->setHidden(false);
        node[num]->setStyleSheet("QPushButton{font: large \"Calibri\";font-size:25px;height:50px;width:50px;border-image:url(D:/vscpath/cpp/Test/dynamicTree/view/images/nodedelete.png);}");
        node[num]->repaint();
    }
    else if (color == 5)
    {
        node[num]->setHidden(false);
        node[num]->setStyleSheet("QPushButton{font: large \"Calibri\";font-size:25px;height:50px;width:50px;border-image:url(D:/vscpath/cpp/Test/dynamicTree/view/images/nodefind.png);}");
        node[num]->repaint();
    }
    if(color != 0 && num != 0)
    {
        line[num]->setHidden(false);
        line[num]->repaint();
    }
}
