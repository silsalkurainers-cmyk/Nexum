#pragma once

#include "BaseWizardPage.h"

#include "Application.h"
#include "settings/SettingsObject.h"

#include <QCheckBox>
#include <QLabel>
#include <QVBoxLayout>

class NexumPerformanceWizardPage final : public BaseWizardPage {
public:
    explicit NexumPerformanceWizardPage(QWidget* parent = nullptr) : BaseWizardPage(parent)
    {
        auto* layout = new QVBoxLayout(this);
        layout->setContentsMargins(24, 24, 24, 24);
        layout->setSpacing(14);

        auto* description = new QLabel(
            tr("Choose optional Java runtime tuning. These settings can change memory use and garbage collection behaviour; "
               "they are not guaranteed to increase FPS. You can change them later in Settings → Performance."),
            this);
        description->setWordWrap(true);
        layout->addWidget(description);

        auto* settings = APPLICATION->settings();
        m_g1gc = new QCheckBox(tr("Use the G1 garbage collector"), this);
        m_g1gc->setToolTip(tr("G1 is already the default on most modern Java versions."));
        m_g1gc->setChecked(settings->get("UseG1GC").toBool());
        layout->addWidget(m_g1gc);

        m_parallelReferenceProcessing = new QCheckBox(tr("Enable parallel reference processing"), this);
        m_parallelReferenceProcessing->setToolTip(tr("Lets the JVM process references in parallel; results vary by workload."));
        m_parallelReferenceProcessing->setChecked(settings->get("ParallelReferenceProcessing").toBool());
        layout->addWidget(m_parallelReferenceProcessing);

        m_gcPauseTarget = new QCheckBox(tr("Use a 100 ms garbage-collection pause target"), this);
        m_gcPauseTarget->setToolTip(tr("A tuning goal, not a guaranteed pause limit."));
        m_gcPauseTarget->setChecked(settings->get("GcPauseTarget").toBool());
        layout->addWidget(m_gcPauseTarget);

        m_stringDeduplication = new QCheckBox(tr("Enable G1 string deduplication"), this);
        m_stringDeduplication->setToolTip(tr("Can reduce memory use by merging identical strings, with some extra CPU work."));
        m_stringDeduplication->setChecked(settings->get("UseStringDeduplication").toBool());
        m_stringDeduplication->setEnabled(m_g1gc->isChecked());
        layout->addWidget(m_stringDeduplication);
        connect(m_g1gc, &QCheckBox::toggled, m_stringDeduplication, &QWidget::setEnabled);

        m_disableExplicitGc = new QCheckBox(tr("Ignore explicit garbage-collection requests"), this);
        m_disableExplicitGc->setToolTip(tr("May avoid disruptive full collections, but some applications may rely on explicit collection."));
        m_disableExplicitGc->setChecked(settings->get("DisableExplicitGC").toBool());
        layout->addWidget(m_disableExplicitGc);

        m_alwaysPreTouch = new QCheckBox(tr("Pre-touch the Java heap at startup"), this);
        m_alwaysPreTouch->setToolTip(tr("Makes memory allocation more predictable but increases startup time and initial memory commitment."));
        m_alwaysPreTouch->setChecked(settings->get("AlwaysPreTouch").toBool());
        layout->addWidget(m_alwaysPreTouch);

        layout->addStretch(1);
        setTitle(tr("Performance"));
        setSubTitle(tr("Optional JVM tuning for your Minecraft instances."));
    }

    bool validatePage() override
    {
        auto* settings = APPLICATION->settings();
        settings->set("UseG1GC", m_g1gc->isChecked());
        settings->set("ParallelReferenceProcessing", m_parallelReferenceProcessing->isChecked());
        settings->set("GcPauseTarget", m_gcPauseTarget->isChecked());
        settings->set("UseStringDeduplication", m_stringDeduplication->isChecked());
        settings->set("DisableExplicitGC", m_disableExplicitGc->isChecked());
        settings->set("AlwaysPreTouch", m_alwaysPreTouch->isChecked());
        return true;
    }

protected:
    void retranslate() override {}

private:
    QCheckBox* m_g1gc = nullptr;
    QCheckBox* m_parallelReferenceProcessing = nullptr;
    QCheckBox* m_gcPauseTarget = nullptr;
    QCheckBox* m_stringDeduplication = nullptr;
    QCheckBox* m_disableExplicitGc = nullptr;
    QCheckBox* m_alwaysPreTouch = nullptr;
};
