#include "cooking_meemaw_app.h"

using cookingmeemaw::CookingMeemawApp;

void prepareSettings(CookingMeemawApp::Settings* settings) {
    settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(CookingMeemawApp, ci::app::RendererGl, prepareSettings);
