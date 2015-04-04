#include <seed.h>

SeedObject maleo_namespace;

SeedValue
seed_maleo_version (
  SeedContext ctx,
  SeedObject function,
  SeedObject this_object,
  size_t argc,
  const SeedValue args[],
  SeedException * exception
) 
{ 
  SeedValue version;
  version = seed_value_from_string(ctx, "2.0.0", exception); 
  return version;
}

seed_static_function maleo_funcs[] = {
  {"version", seed_maleo_version, 0},
  {NULL, NULL, 0}
};

SeedObject
seed_module_init(SeedEngine * engine)
{
  SeedClass maleo_namespace_class;
  seed_class_definition maleo_namespace_class_definition = seed_empty_class;
  maleo_namespace_class_definition.static_functions = maleo_funcs;
  maleo_namespace_class = seed_create_class (&maleo_namespace_class_definition);
  maleo_namespace = seed_make_object (engine->context, maleo_namespace_class, NULL);
  return maleo_namespace;
}
