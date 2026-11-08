#include "PerformancePage.h"

#include "Application.h"
#include "settings/SettingsObject.h"

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
    m_stringDeduplication->setChecked(settings->get("UseStringDeduplication").toBool());
    m_disableExplicitGc->setChecked(settings->get("DisableExplicitGC").toBool());
    m_alwaysPreTouch->setChecked(settings->get("AlwaysPreTouch").toBool());
    m_stringDeduplication->setEnabled(settings->get("UseG1GC").toBool());
}

void PerformancePage::retranslate()
{
}

bool PerformancePage::apply()
{
    auto* settings = APPLICATION->settings();
    settings->set("UseStringDeduplication", m_stringDeduplication->isChecked());
    settings->set("DisableExplicitGC", m_disableExplicitGc->isChecked());
    settings->set("AlwaysPreTouch", m_alwaysPreTouch->isChecked());
    return true;
}
