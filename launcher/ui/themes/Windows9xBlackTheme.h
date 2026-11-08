// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include "DarkTheme.h"

// A black, high-contrast take on the classic Windows 9x beveled widget style.
class Windows9xBlackTheme : public DarkTheme {
   public:
    QString id() override;
    QString name() override;
    QString appStyleSheet() override;
};
