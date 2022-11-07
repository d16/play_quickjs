#include "quickjs-libc.h"

extern const uint32_t qjsc_tsc_size;

extern const uint8_t qjsc_tsc[];

static JSContext *JS_NewCustomContext(JSRuntime *rt)
{
  JSContext *ctx = JS_NewContextRaw(rt);
  if (!ctx)
    return NULL;
  JS_AddIntrinsicBaseObjects(ctx);
  JS_AddIntrinsicDate(ctx);
  JS_AddIntrinsicEval(ctx);
  JS_AddIntrinsicStringNormalize(ctx);
  JS_AddIntrinsicRegExp(ctx);
  JS_AddIntrinsicJSON(ctx);
  JS_AddIntrinsicProxy(ctx);
  JS_AddIntrinsicMapSet(ctx);
  JS_AddIntrinsicTypedArrays(ctx);
  JS_AddIntrinsicPromise(ctx);
  JS_AddIntrinsicBigInt(ctx);
  {
    extern JSModuleDef *js_init_module_os(JSContext *ctx, const char *name);
    js_init_module_os(ctx, "os");
  }
  {
    extern JSModuleDef *js_init_module_std(JSContext *ctx, const char *name);
    js_init_module_std(ctx, "std");
  }
  return ctx;
}

int main(int argc, char **argv)
{
  JSRuntime *rt;
  JSContext *ctx;
  rt = JS_NewRuntime();
  js_std_set_worker_new_context_func(JS_NewCustomContext);
  js_std_init_handlers(rt);
  JS_SetMaxStackSize(rt, 2097152);
  JS_SetModuleLoaderFunc(rt, NULL, js_module_loader, NULL);
  ctx = JS_NewCustomContext(rt);
  js_std_add_helpers(ctx, argc, argv);
  js_std_eval_binary(ctx, qjsc_tsc, qjsc_tsc_size, 0);
  js_std_loop(ctx);
  JS_FreeContext(ctx);
  JS_FreeRuntime(rt);
  return 0;
}
