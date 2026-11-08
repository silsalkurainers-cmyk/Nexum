// SPDX-License-Identifier: GPL-3.0-only
#include "Windows9xBlackTheme.h"

#include <QObject>

QString Windows9xBlackTheme::id()
{
    return QStringLiteral("windows9x-black");
}

QString Windows9xBlackTheme::name()
{
    return QObject::tr("Windows 9x Black");
}

QString Windows9xBlackTheme::appStyleSheet()
{
    return QStringLiteral(R"(
        QWidget {
            background-color: #000000;
            color: #f4f4f4;
            selection-background-color: #b8c7d9;
            selection-color: #000000;
        }
        QGroupBox {
            background: #080808;
            border: 2px solid #777777;
            border-top-color: #bcbcbc;
            border-left-color: #bcbcbc;
            border-radius: 0px;
            margin-top: 12px;
            padding: 10px 7px 7px 7px;
        }
        QGroupBox::title {
            subcontrol-origin: margin;
            left: 8px;
            padding: 0 4px;
            color: #ffffff;
        }
        QPushButton, QToolButton, QComboBox, QLineEdit, QSpinBox, QDoubleSpinBox {
            color: #ffffff;
            background: #171717;
            border: 2px solid #777777;
            border-top-color: #c0c0c0;
            border-left-color: #c0c0c0;
            border-radius: 0px;
            padding: 5px 9px;
        }
        QPushButton:pressed, QToolButton:pressed {
            border-top-color: #555555;
            border-left-color: #555555;
            border-right-color: #c0c0c0;
            border-bottom-color: #c0c0c0;
            background: #242424;
        }
        QTabWidget::pane {
            border: 2px solid #777777;
            border-top-color: #bcbcbc;
            border-left-color: #bcbcbc;
            background: #050505;
        }
        QTabBar::tab {
            color: #eeeeee;
            background: #151515;
            border: 2px solid #777777;
            border-bottom: none;
            border-radius: 0px;
            padding: 6px 10px;
            margin-right: 2px;
        }
        QTabBar::tab:selected {
            background: #303030;
            color: #ffffff;
            border-top-color: #dddddd;
            border-left-color: #dddddd;
        }
        QTreeView, QListView, QTableView, QPlainTextEdit, QTextEdit {
            color: #eeeeee;
            background: #030303;
            alternate-background-color: #151515;
            border: 2px solid #666666;
            border-radius: 0px;
        }
        QMenu {
            color: #ffffff;
            background: #080808;
            border: 2px solid #999999;
            border-radius: 0px;
            padding: 3px;
        }
        QMenu::item { padding: 5px 22px 5px 8px; }
        QMenu::item:selected { background: #343434; }
        QHeaderView::section {
            color: #ffffff;
            background: #202020;
            border: 1px solid #777777;
            padding: 5px;
        }
        QCheckBox, QRadioButton { spacing: 7px; color: #eeeeee; }
        QCheckBox::indicator, QRadioButton::indicator {
            width: 15px; height: 15px;
            background: #080808;
            border: 2px solid #a0a0a0;
        }
        QCheckBox::indicator:checked, QRadioButton::indicator:checked {
            background: #d0d0d0;
            border-color: #ffffff;
        }
        QProgressBar {
            color: #ffffff;
            background: #080808;
            border: 2px solid #888888;
            text-align: center;
        }
        QProgressBar::chunk { background: #bdbdbd; }
        QScrollBar:vertical, QScrollBar:horizontal {
            background: #090909;
            border: 1px solid #666666;
            width: 14px; height: 14px;
            margin: 0;
        }
        QScrollBar::handle:vertical, QScrollBar::handle:horizontal {
            background: #555555;
            border: 1px solid #c0c0c0;
            min-height: 24px; min-width: 24px;
        }
        QScrollBar::add-line, QScrollBar::sub-line { background: #222222; }
        QComboBox QAbstractItemView {
            color: #ffffff;
            background: #080808;
            selection-background-color: #404040;
            border: 2px solid #888888;
        }
        QLineEdit:focus, QSpinBox:focus, QDoubleSpinBox:focus, QComboBox:focus {
            border-color: #eeeeee;
        }
        QToolTip {
            color: #ffffff;
            background: #080808;
            border: 1px solid #bcbcbc;
            border-radius: 0px;
            padding: 4px;
        }
    )");
}
