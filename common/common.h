#ifndef COMMON_H
#define COMMON_H

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

QT_BEGIN_NAMESPACE
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
QT_END_NAMESPACE

using ElementType = int;

typedef enum {BST, AVL, Splay, MinH, MaxH} controlMode;

int intpow(int N, int k);

#endif
