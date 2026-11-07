#pragma once
#include "BaseWizardPage.h"
#include <QLabel>
#include <QVBoxLayout>

class NexumWelcomeWizardPage final : public BaseWizardPage {
public:
    explicit NexumWelcomeWizardPage(QWidget* parent = nullptr) : BaseWizardPage(parent)
    {
        auto* layout = new QVBoxLayout(this);
        layout->setContentsMargins(24, 24, 24, 24);
        layout->setSpacing(18);
        auto* heading = new QLabel(tr("Welcome to Nexum"), this);
        QFont headingFont = heading->font();
        headingFont.setPointSize(22);
        headingFont.setBold(true);
        heading->setFont(headingFont);
        auto* intro = new QLabel(
            tr("Your Minecraft setup, your way. Nexum keeps instances, modpacks, accounts, Java and appearance settings together in one portable-friendly launcher."), this);
        intro->setWordWrap(true);
        auto* steps = new QLabel(
            tr("<b>In this setup</b><br>• Choose your language and Java configuration<br>• Pick the look and icon style you want<br>• Add a Microsoft account or continue with a local offline profile<br><br><b>You stay in control</b><br>Your existing instances and custom settings are kept. You can revisit launcher settings at any time."), this);
        steps->setWordWrap(true);
        steps->setTextFormat(Qt::RichText);
        auto* note = new QLabel(
            tr("Microsoft sign-in is used for authenticated Minecraft services. A local offline profile does not require a Microsoft account."), this);
        note->setWordWrap(true);
        layout->addWidget(heading);
        layout->addWidget(intro);
        layout->addWidget(steps);
        layout->addWidget(note);
        layout->addStretch(1);
        setTitle(tr("Welcome"));
        setSubTitle(tr("Let's get Nexum ready for your Minecraft setup."));
    }
protected:
    void retranslate() override {}
};
