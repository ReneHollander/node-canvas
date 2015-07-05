#include "Backends.h"

#include "backend/ImageBackend.h"
#include "backend/FBDevBackend.h"
#include "backend/X11Backend.h"

void Backends::Initialize(Handle<Object> target) {
  NanScope();

  Local<Object> obj = NanNew<Object>();
  ImageBackend::Initialize(obj);
  FBDevBackend::Initialize(obj);
  X11Backend::Initialize(obj);

  target->Set(NanNew("Backends"), obj);
}
