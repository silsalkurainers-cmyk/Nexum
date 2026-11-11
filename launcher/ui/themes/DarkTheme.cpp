// SPDX-License-Identifier: GPL-3.0-only
/*
 *  Prism Launcher - Minecraft Launcher
 *  Copyright (C) 2024 Tayou <git@tayou.org>
 *  Copyright (C) 2024 TheKodeToad <TheKodeToad@proton.me>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 3.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * This file incorporates work covered by the following copyright and
 * permission notice:
 *
 *      Copyright 2013-2021 MultiMC Contributors
 *
 *      Licensed under the Apache License, Version 2.0 (the "License");
 *      you may not use this file except in compliance with the License.
 *      You may obtain a copy of the License at
 *
 *          http://www.apache.org/licenses/LICENSE-2.0
 *
 *      Unless required by applicable law or agreed to in writing, software
 *      distributed under the License is distributed on an "AS IS" BASIS,
 *      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *      See the License for the specific language governing permissions and
 *      limitations under the License.
 */
#include "DarkTheme.h"

#include <QObject>

QString DarkTheme::id()
{
    return "dark";
}

QString DarkTheme::name()
{
    return QObject::tr("Nexum Black");
}

QPalette DarkTheme::colorScheme()
{
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(0, 0, 0));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(0, 0, 0));
    darkPalette.setColor(QPalette::AlternateBase, QColor(12, 12, 12));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(16, 16, 16));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(190, 190, 190));
    darkPalette.setColor(QPalette::Highlight, QColor(190, 190, 190));
    darkPalette.setColor(QPalette::HighlightedText, QColor(0, 0, 0));
    darkPalette.setColor(QPalette::PlaceholderText, Qt::darkGray);
    return fadeInactive(darkPalette, fadeAmount(), fadeColor());
}

double DarkTheme::fadeAmount()
{
    return 0.5;
}

QColor DarkTheme::fadeColor()
{
    return QColor(32, 32, 32);
}

bool DarkTheme::hasStyleSheet()
{
    return true;
}

QString DarkTheme::appStyleSheet()
{
    return R"(
        QWidget {
            selection-background-color: #bdbdbd;
            selection-color: #050505;
        }
        QToolBar {
            background: #080808;
            border: none;
            border-bottom: 1px solid #252525;
            spacing: 7px;
            padding: 5px 8px;
        }
        QToolBar::separator {
            background: #303030;
            width: 1px;
            margin: 4px 5px;
        }
        QToolBar QToolButton {
            color: #e8e8e8;
            background: transparent;
            border: 1px solid transparent;
            border-radius: 8px;
            padding: 7px 10px;
        }
        QToolBar QToolButton:hover {
            background: #191919;
            border-color: #343434;
        }
        QToolBar QToolButton:pressed, QToolBar QToolButton:checked {
            background: #242424;
            border-color: #4a4a4a;
        }
        QToolTip {
            color: #f0f0f0;
            background-color: #080808;
            border: 1px solid #555555;
            border-radius: 8px;
            padding: 6px;
        }
        QGroupBox {
            border: 1px solid #292929;
            border-radius: 10px;
            margin-top: 12px;
            padding: 12px 9px 9px 9px;
            font-weight: 600;
        }
        QGroupBox::title {
            subcontrol-origin: margin;
            left: 12px;
            padding: 0 5px;
            color: #dddddd;
        }
        QTabWidget::pane {
            border: 1px solid #292929;
            border-radius: 9px;
            top: -1px;
            background: #050505;
        }
        QTabBar::tab {
            background: #111111;
            color: #bdbdbd;
            border: 1px solid #292929;
            border-bottom: none;
            border-top-left-radius: 7px;
            border-top-right-radius: 7px;
            padding: 7px 12px;
            margin-right: 3px;
        }
        QTabBar::tab:selected {
            color: #ffffff;
            background: #202020;
            border-color: #555555;
        }
        QTreeView, QListView, QTableView, QPlainTextEdit, QTextEdit {
            background: #050505;
            alternate-background-color: #101010;
            color: #eeeeee;
            border: 1px solid #292929;
            border-radius: 8px;
            gridline-color: #242424;
        }
        QHeaderView::section {
            background: #141414;
            color: #dddddd;
            border: none;
            border-right: 1px solid #292929;
            border-bottom: 1px solid #292929;
            padding: 6px 8px;
            font-weight: 600;
        }
        QMenu {
            background: #090909;
            color: #eeeeee;
            border: 1px solid #333333;
            border-radius: 8px;
            padding: 5px;
        }
        QMenu::item {
            padding: 6px 24px 6px 10px;
            border-radius: 5px;
        }
        QMenu::item:selected {
            background: #252525;
            color: #ffffff;
        }
        QCheckBox, QRadioButton {
            spacing: 7px;
            color: #e5e5e5;
        }
        QPushButton, QToolButton, QComboBox, QLineEdit, QSpinBox, QDoubleSpinBox {
            border: 1px solid #303030;
            border-radius: 8px;
            padding: 6px 10px;
            background: #101010;
            color: #f0f0f0;
        }
        QPushButton:hover, QToolButton:hover, QComboBox:hover, QLineEdit:hover,
        QSpinBox:hover, QDoubleSpinBox:hover {
            border-color: #bdbdbd;
        }
        QPushButton:pressed, QToolButton:pressed {
            background-color: #242424;
        }
        QScrollBar::handle {
            border-radius: 5px;
            background: #505050;
        }
        QScrollBar::handle:hover {
            background: #bdbdbd;
        }
    )";
}

QString DarkTheme::tooltip()
{
    return "";
}
