#ifndef VRABAPP_H
#define VRABAPP_H

#include "MooseApp.h"

class VrabApp;

template<>
InputParameters validParams<VrabApp>();

class VrabApp : public MooseApp
{
public:
  VrabApp(InputParameters parameters);
  virtual ~VrabApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* VRABAPP_H */
