#include "VrabApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<VrabApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

VrabApp::VrabApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  VrabApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  VrabApp::associateSyntax(_syntax, _action_factory);
}

VrabApp::~VrabApp()
{
}

// External entry point for dynamic application loading
extern "C" void VrabApp__registerApps() { VrabApp::registerApps(); }
void
VrabApp::registerApps()
{
  registerApp(VrabApp);
}

// External entry point for dynamic object registration
extern "C" void VrabApp__registerObjects(Factory & factory) { VrabApp::registerObjects(factory); }
void
VrabApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void VrabApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { VrabApp::associateSyntax(syntax, action_factory); }
void
VrabApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
