#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(250, 450);
    this->setWindowTitle("HUFFMAN CODE");

    this->initialMainWidget();
    this->initialHead();
    this->initialChooseLayout();
    this->initialCodeLayout();

    this->set_blackground(":/Icons/2");

    this->initialConnect();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initialMainWidget()
{
    //生成布局
    this->main_layout = new QVBoxLayout();

    this->cenWidget = new QWidget();
    this->cenWidget->setFixedSize(250, 450);
    this->cenWidget->setLayout(this->main_layout);

    //添加centralWidget
    this->setCentralWidget(this->cenWidget);
}

void MainWindow::initialHead()
{
    this->head_label = new QLabel("<h2>Huffman压缩工具</h2>");
    this->head_label->setAlignment(Qt::AlignCenter);
    this->head_label->setFixedHeight(60);
    this->head_label->setParent(this);
    //添加标题label
    this->main_layout->addWidget(this->head_label);
}

void MainWindow::set_blackground(QString icon_path)
{
    QPalette pal = this->palette();
    this->setAutoFillBackground(true);
    pal.setBrush(QPalette::Window, QBrush(QPixmap(icon_path).scaled(this->size(), Qt::IgnoreAspectRatio,
                                                                      Qt::SmoothTransformation)));
    this->setPalette(pal);
}

void MainWindow::initialConnect()
{
    QObject::connect(this->file_path_Button1, &QPushButton::clicked, this, &MainWindow::openfile);
    QObject::connect(this->file_path_Button2, &QPushButton::clicked, this, &MainWindow::savefile);
    QObject::connect(this->file_path_Button3, &QPushButton::clicked, this, &MainWindow::frefileAddress);
    QObject::connect(this->file_path_lineEdit1, &QLineEdit::textChanged, [=](const QString &str)
    {
        this->sor_file_path.clear();
        this->sor_file_path = str;
        string s = str.toStdString();
        int pos;
        if((pos = s.find_last_of('/')) != string::npos)
        {
            s.erase(pos+1);
            this->dst_file_path.clear();
            this->dst_file_path = QString::fromStdString(s+"dst");
            this->fre_file_path.clear();
            this->fre_file_path = QString::fromStdString(s+"frefile");
            this->file_path_lineEdit2->setText(this->dst_file_path);
            this->file_path_lineEdit3->setText(this->fre_file_path);
        }
    });
    QObject::connect(this->file_path_lineEdit2, &QLineEdit::textChanged, [=](const QString &str)
    {
        this->dst_file_path.clear();
        this->dst_file_path = str;
    });
    QObject::connect(this->file_path_lineEdit3, &QLineEdit::textChanged, [=](const QString &str)
    {
        this->fre_file_path.clear();
        this->fre_file_path = str;
    });
    QObject::connect(this->encode_button, &QPushButton::clicked, this, &MainWindow::receiveEncode);
    QObject::connect(this->decode_button, &QPushButton::clicked, this, &MainWindow::receiveDecode);
}

void MainWindow::openfile()
{
    this->sor_file_path = QFileDialog::getOpenFileName(this, tr("OpenFile"), ".", tr("Text files(*)"));
    this->file_path_lineEdit1->setText(this->sor_file_path);
}

void MainWindow::savefile()
{
    this->dst_file_path = QFileDialog::getOpenFileName(this, tr("SaveFile"), ".", tr("Text files(*)"));
    this->file_path_lineEdit2->setText(this->dst_file_path);
}

void MainWindow::frefileAddress()
{
    this->fre_file_path = QFileDialog::getOpenFileName(this, tr("FreFile"), ".", tr("Text Files(*)"));
    this->file_path_lineEdit3->setText(this->fre_file_path);
}

void MainWindow::receiveEncode()
{
    h = new Huffman(this->sor_file_path.toStdString(), this->fre_file_path.toStdString());
    h->huffmanEncode(this->sor_file_path.toStdString(), this->dst_file_path.toStdString());
    QMessageBox::about(this, "Encode", "编码成功");
}

void MainWindow::receiveDecode()
{
    if(!h)
        h = new Huffman(this->fre_file_path.toStdString());
    h->huffmanDecode(this->sor_file_path.toStdString(), this->dst_file_path.toStdString());
    QMessageBox::about(this, "Decode", "解码成功");
}

void MainWindow::initialChooseLayout()
{
    this->file_path_layout = new QVBoxLayout;

    this->file_path_lineEdit1 = new QLineEdit;
    this->file_path_lineEdit2 = new QLineEdit;
    this->file_path_lineEdit3 = new QLineEdit;
    this->file_path_Button1 = new QPushButton("...");
    this->file_path_Button2 = new QPushButton("...");
    this->file_path_Button3 = new QPushButton("...");
    this->file_path_Button1->setFixedSize(20, 20);
    this->file_path_Button2->setFixedSize(20, 20);
    this->file_path_Button3->setFixedSize(20, 20);

    this->file_path_lineEdit1->setPlaceholderText("源文件地址");
    this->file_path_lineEdit2->setPlaceholderText("目标文件地址");
    this->file_path_lineEdit3->setPlaceholderText("字符频度文件地址");

    QHBoxLayout *qh1 = new QHBoxLayout;
    QHBoxLayout *qh2 = new QHBoxLayout;
    QHBoxLayout *qh3 = new QHBoxLayout;
    qh1->addWidget(this->file_path_lineEdit1);
    qh1->addWidget(this->file_path_Button1);
    qh2->addWidget(this->file_path_lineEdit2);
    qh2->addWidget(this->file_path_Button2);
    qh3->addWidget(this->file_path_lineEdit3);
    qh3->addWidget(this->file_path_Button3);

    this->file_path_layout->addLayout(qh1);
    this->file_path_layout->addLayout(qh2);
    this->file_path_layout->addLayout(qh3);

    this->main_layout->addLayout(this->file_path_layout);

}

void MainWindow::initialCodeLayout()
{
    this->code_layout = new QHBoxLayout;
    this->encode_button = new QPushButton("编码");
    this->decode_button = new QPushButton("解码");

    this->code_layout->addWidget(this->encode_button);
    this->code_layout->addWidget(this->decode_button);

    this->main_layout->addLayout(this->code_layout);
}
