// Wizard to use the GigaProxyPhoto system

#ifndef GPPWIZARD_H
#define GPPWIZARD_H

#include <QWidget>
#include <QWizard>

class GPPWizard : public QWizard
{
    Q_OBJECT

public:
    GPPWizard();

public slots:
    bool goUp();
    bool goDown();
    bool goLeft();
    bool goRight();
    void openCameraSettings();

private:
    // functions to create the 4 pages of the wizard
    QWizardPage *createIntroPage();
    QWizardPage *createFramingPage();
    QWizardPage *createSettingsPage();
    QWizardPage *createInProcessPage();
};

#endif // GPPWIZARD_H
