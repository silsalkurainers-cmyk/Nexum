#include "PerformancePage.h"

#include "Application.h"
#include "settings/SettingsObject.h"
#include "settings/Setting.h"

#include <QLabel>
#include <QVBoxLayout>

PerformancePage::PerformancePage(QWidget* parent) : QWidget(parent)
{
    auto* layout = new QVBoxLayout(this);
    auto* description = new QLabel(
        tr("Optional Java runtime tuning. These switches change JVM behaviour and are not guaranteed to increase FPS. "
           "Leave them disabled unless you understand the trade-offs."),
        this);
    description->setWordWrap(true);
    layout->addWidget(description);

    m_g1gc = new QCheckBox(tr("Use the G1 garbage collector"), this);
    m_g1gc->setToolTip(tr("G1 is already the default on most modern Java versions."));
    layout->addWidget(m_g1gc);

    m_parallelReferenceProcessing = new QCheckBox(tr("Enable parallel reference processing"), this);
    m_parallelReferenceProcessing->setToolTip(tr("Adds -XX:+ParallelRefProcEnabled. The JVM can process references in parallel; results vary by workload."));
    layout->addWidget(m_parallelReferenceProcessing);

    m_gcPauseTarget = new QCheckBox(tr("Use a 100 ms garbage-collection pause target"), this);
    m_gcPauseTarget->setToolTip(tr("Adds -XX:MaxGCPauseMillis=100. This is a tuning goal, not a guaranteed pause limit."));
    layout->addWidget(m_gcPauseTarget);

    m_stringDeduplication = new QCheckBox(tr("Enable G1 string deduplication"), this);
    m_stringDeduplication->setToolTip(
        tr("Let G1 merge identical strings to reduce memory use. Requires G1 garbage collection and may add CPU work."));
    layout->addWidget(m_stringDeduplication);

    m_disableExplicitGc = new QCheckBox(tr("Ignore explicit garbage-collection requests"), this);
    m_disableExplicitGc->setToolTip(
        tr("Adds -XX:+DisableExplicitGC. This can avoid disruptive full collections, but some applications may rely on explicit collection."));
    layout->addWidget(m_disableExplicitGc);

    m_alwaysPreTouch = new QCheckBox(tr("Pre-touch the Java heap at startup"), this);
    m_alwaysPreTouch->setToolTip(
        tr("Adds -XX:+AlwaysPreTouch. Memory allocation can be more predictable, but startup takes longer and commits the heap earlier."));
    layout->addWidget(m_alwaysPreTouch);

    layout->addStretch(1);

    auto* settings = APPLICATION->settings();
    m_g1gc->setChecked(settings->get("UseG1GC").toBool());
    m_parallelReferenceProcessing->setChecked(settings->get("ParallelReferenceProcessing").toBool());
    m_gcPauseTarget->setChecked(settings->get("GcPauseTarget").toBool());
    m_stringDeduplication->setChecked(settings->get("UseStringDeduplication").toBool());
    m_disableExplicitGc->setChecked(settings->get("DisableExplicitGC").toBool());
    m_alwaysPreTouch->setChecked(settings->get("AlwaysPreTouch").toBool());
    m_stringDeduplication->setEnabled(m_g1gc->isChecked());
    connect(m_g1gc, &QCheckBox::toggled, m_stringDeduplication, &QWidget::setEnabled);
}

void PerformancePage::retranslate()
{
}

bool PerformancePage::apply()
{
    auto* settings = APPLICATION->settings();
    settings->set("UseG1GC", m_g1gc->isChecked());
    settings->set("UseStringDeduplication", m_stringDeduplication->isChecked());
    settings->set("DisableExplicitGC", m_disableExplicitGc->isChecked());
    settings->set("AlwaysPreTouch", m_alwaysPreTouch->isChecked());
    return true;
}
