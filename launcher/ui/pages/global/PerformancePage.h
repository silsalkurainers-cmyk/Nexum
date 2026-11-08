#pragma once

#include "ui/pages/BasePage.h"

#include <QCheckBox>
#include <QWidget>

class PerformancePage final : public QWidget, public BasePage {
    Q_OBJECT

public:
    explicit PerformancePage(QWidget* parent = nullptr);

    QString displayName() const override { return tr("Performance"); }
    QIcon icon() const override { return QIcon::fromTheme("settings"); }
    QString id() const override { return "performance-settings"; }
    QString helpPage() const override { return "Minecraft-settings"; }
    void retranslate() override;
    bool apply() override;

private:
    QCheckBox* m_stringDeduplication = nullptr;
    QCheckBox* m_disableExplicitGc = nullptr;
    QCheckBox* m_alwaysPreTouch = nullptr;
};
