#pragma once

#include "BasePage.h"

class Generator;
class EuclideanGenerator;

class GeneratorPage : public BasePage {
public:
    GeneratorPage(PageManager &manager, PageContext &context);

    using BasePage::show;
    void show(Generator *generator);

    virtual void enter() override;
    virtual void exit() override;

    virtual void draw(Canvas &canvas) override;
    virtual void updateLeds(Leds &leds) override;

    virtual void keyDown(KeyEvent &event) override;
    virtual void keyUp(KeyEvent &event) override;
    virtual void keyPress(KeyPressEvent &event) override;
    virtual void encoder(EncoderEvent &event) override;

    void contextShow();
    void contextAction(int index);
    bool contextActionEnabled(int index) const;
    void commit();
    void revert();

private:
    void drawEuclideanGenerator(Canvas &canvas, const EuclideanGenerator &generator) const;

    Generator *_generator;
};
