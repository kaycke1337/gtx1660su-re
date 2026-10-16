// ===== 0016d870 nvmlDeviceGetGpuInstanceId =====

int nvmlDeviceGetGpuInstanceId(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x55b,"nvmlDeviceGetGpuInstanceId",
                 "(nvmlDevice_t device, unsigned int *id)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016d830(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x55b,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x55b,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0016da50 FUN_0016da50 =====

undefined8 FUN_0016da50(char *param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((((param_1 != (char *)0x0) && (param_2 != 0)) && (*param_1 != '\x01')) &&
     (((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
      ((*(int *)(param_1 + 0x10) == 0 || (*(long *)(param_1 + 0x20) == 0)))))) {
    uVar1 = FUN_00137150();
    return uVar1;
  }
  return 2;
}


// ===== 0016da90 nvmlDeviceGetComputeInstanceId =====

int nvmlDeviceGetComputeInstanceId(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x560,"nvmlDeviceGetComputeInstanceId",
                 "(nvmlDevice_t device, unsigned int *id)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016da50(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x560,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x560,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0016dc70 FUN_0016dc70 =====

undefined8 FUN_0016dc70(char *param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_2 != 0)))
     ) {
    uVar1 = FUN_001371f0();
    return uVar1;
  }
  return 2;
}


// ===== 0016dcb0 nvmlDeviceGetMaxMigDeviceCount =====

int nvmlDeviceGetMaxMigDeviceCount(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x565,"nvmlDeviceGetMaxMigDeviceCount",
                 "(nvmlDevice_t device, unsigned int *migDeviceCount)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016dc70(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x565,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x565,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0016de90 FUN_0016de90 =====

undefined8 FUN_0016de90(char *param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_3 != 0)))
     ) {
    uVar1 = FUN_00137280();
    return uVar1;
  }
  return 2;
}


// ===== 0016ded0 nvmlDeviceGetMigDeviceHandleByIndex =====

int nvmlDeviceGetMigDeviceHandleByIndex(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %u, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x56a,"nvmlDeviceGetMigDeviceHandleByIndex",
                 "(nvmlDevice_t device, unsigned int index, nvmlDevice_t *migDevice)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016de90(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x56a,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x56a,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016e0a0 FUN_0016e0a0 =====

undefined8 FUN_0016e0a0(char *param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((((param_1 != (char *)0x0) && (param_2 != 0)) && (*param_1 != '\x01')) &&
     (((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
      ((*(int *)(param_1 + 0x10) == 0 || (*(long *)(param_1 + 0x20) == 0)))))) {
    uVar1 = FUN_00137430();
    return uVar1;
  }
  return 2;
}


// ===== 0016e0e0 nvmlDeviceGetDeviceHandleFromMigDeviceHandle =====

int nvmlDeviceGetDeviceHandleFromMigDeviceHandle(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x56f,"nvmlDeviceGetDeviceHandleFromMigDeviceHandle",
                 "(nvmlDevice_t migDevice, nvmlDevice_t *device)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016e0a0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x56f,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x56f,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0016e2c0 FUN_0016e2c0 =====

ulong FUN_0016e2c0(char *param_1,long param_2)

{
  ulong uVar1;
  
  if ((param_2 == 0) || (param_1 == (char *)0x0)) {
    return 2;
  }
  if (*param_1 == '\x01') {
    return 3;
  }
  if (*(long *)(param_1 + 0x20) != 0) {
    if ((*(int *)(param_1 + 0x14) != 0) && (*(int *)(param_1 + 0x1c) == 0)) {
      return (ulong)(3 - (*(int *)(param_1 + 0x10) == 0));
    }
    return 2;
  }
  uVar1 = FUN_00137670(1,param_1,param_2);
  return uVar1;
}


// ===== 0016e320 nvmlDeviceGetAttributes =====

int nvmlDeviceGetAttributes(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x574,"nvmlDeviceGetAttributes",
                 "(nvmlDevice_t device, nvmlDeviceAttributes_t *attributes)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016e2c0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x574,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x574,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0016e500 FUN_0016e500 =====

ulong FUN_0016e500(char *param_1,long param_2)

{
  ulong uVar1;
  
  if ((param_2 == 0) || (param_1 == (char *)0x0)) {
    return 2;
  }
  if (*param_1 == '\x01') {
    return 3;
  }
  if (*(long *)(param_1 + 0x20) != 0) {
    if ((*(int *)(param_1 + 0x14) != 0) && (*(int *)(param_1 + 0x1c) == 0)) {
      return (ulong)(3 - (*(int *)(param_1 + 0x10) == 0));
    }
    return 2;
  }
  uVar1 = FUN_00137670(2,param_1,param_2);
  return uVar1;
}


// ===== 0016e560 nvmlDeviceGetAttributes_v2 =====

int nvmlDeviceGetAttributes_v2(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x579,"nvmlDeviceGetAttributes_v2",
                 "(nvmlDevice_t device, nvmlDeviceAttributes_t *attributes)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016e500(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x579,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x579,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0016e740 FUN_0016e740 =====

undefined8 FUN_0016e740(long param_1,long param_2,long param_3,long param_4,undefined8 param_5)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_3 == 0 || param_4 == 0) || (param_2 == 0)) {
    return 2;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x140) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x140) + 0xe0),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0016e799. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3,param_4,param_5);
    return uVar2;
  }
  return 3;
}


// ===== 0016e7c0 nvmlDeviceGetRemappedRows =====

int nvmlDeviceGetRemappedRows
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p, %p, %p)\n","DEBUG",
                 lVar3,"entry_points.h",0x57e,"nvmlDeviceGetRemappedRows",
                 "(nvmlDevice_t device, unsigned int *corrRows, unsigned int *uncRows, unsigned int *isPending, unsigned int *failureOccurred)"
                 ,param_1,param_2,param_3,param_4,param_5);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016e740(param_1,param_2,param_3,param_4,param_5);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x57e,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x57e,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016e9b0 FUN_0016e9b0 =====

undefined8 FUN_0016e9b0(long param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (param_2 == 0) {
    return 2;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x140) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x140) + 0xe8),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0016e9e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 0016ea00 nvmlDeviceGetRemappedRows_v2 =====

int nvmlDeviceGetRemappedRows_v2(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x584,"nvmlDeviceGetRemappedRows_v2",
                 "(nvmlDevice_t device, nvmlRemappedRowsInfo_v2_t *info)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016e9b0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x584,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x584,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0016ebe0 FUN_0016ebe0 =====

undefined8 FUN_0016ebe0(long param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (param_2 == 0) {
    return 2;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x140) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x140) + 0xf0),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0016ec12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 0016ec30 nvmlDeviceGetRowRemapperHistogram =====

int nvmlDeviceGetRowRemapperHistogram(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x589,"nvmlDeviceGetRowRemapperHistogram",
                 "(nvmlDevice_t device, nvmlRowRemapperHistogramValues_t *values)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016ebe0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x589,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x589,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0016ee10 FUN_0016ee10 =====

undefined8 FUN_0016ee10(char *param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_2 != 0)))
     ) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0x170) != (undefined8 *)0x0)) &&
       (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar1 + 0x170),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0016ee64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0016ee90 nvmlDeviceGetClkMonStatus =====

int nvmlDeviceGetClkMonStatus(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0xa45,"nvmlDeviceGetClkMonStatus",
                 "(nvmlDevice_t device, nvmlClkMonStatus_t *status)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016ee10(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xa45,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xa45,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0016f070 FUN_0016f070 =====

undefined8 FUN_0016f070(char *param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x1c0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0016f0c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0016f0e0 nvmlDeviceGetGpcClkVfOffset =====

int nvmlDeviceGetGpcClkVfOffset(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x5e4,"nvmlDeviceGetGpcClkVfOffset",
                 "(nvmlDevice_t device, int *offset)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016f070(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5e4,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5e4,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0016f2c0 FUN_0016f2c0 =====

undefined8 FUN_0016f2c0(char *param_1,undefined4 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x1c8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0016f312. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0016f330 nvmlDeviceSetGpcClkVfOffset =====

int nvmlDeviceSetGpcClkVfOffset(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x5e9,"nvmlDeviceSetGpcClkVfOffset",
                 "(nvmlDevice_t device, int offset)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016f2c0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5e9,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5e9,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0016f510 FUN_0016f510 =====

undefined8 FUN_0016f510(char *param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x1d0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0016f568. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,0,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0016f590 nvmlDeviceGetGpcClkMinMaxVfOffset =====

int nvmlDeviceGetGpcClkMinMaxVfOffset(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x5fd,"nvmlDeviceGetGpcClkMinMaxVfOffset",
                 "(nvmlDevice_t device, int *minOffset, int *maxOffset)",param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016f510(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5fd,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5fd,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016f760 FUN_0016f760 =====

undefined8 FUN_0016f760(char *param_1,long param_2,long param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (((param_1 != (char *)0x0) &&
      ((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) &&
     ((param_2 != 0 && (param_3 != 0)))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x1d0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0016f7c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,2,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0016f7f0 nvmlDeviceGetMemClkMinMaxVfOffset =====

int nvmlDeviceGetMemClkMinMaxVfOffset(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x602,"nvmlDeviceGetMemClkMinMaxVfOffset",
                 "(nvmlDevice_t device, int *minOffset, int *maxOffset)",param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016f760(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x602,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x602,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016f9c0 FUN_0016f9c0 =====

undefined8 FUN_0016f9c0(char *param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_2 != 0)))
     ) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x1d8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0016fa18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0016fa40 nvmlDeviceGetMemClkVfOffset =====

int nvmlDeviceGetMemClkVfOffset(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x5ee,"nvmlDeviceGetMemClkVfOffset",
                 "(nvmlDevice_t device, int *offset)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016f9c0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5ee,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5ee,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0016fc20 FUN_0016fc20 =====

undefined8 FUN_0016fc20(char *param_1,undefined4 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x1e0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0016fc72. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0016fc90 nvmlDeviceSetMemClkVfOffset =====

int nvmlDeviceSetMemClkVfOffset(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x5f3,"nvmlDeviceSetMemClkVfOffset",
                 "(nvmlDevice_t device, int offset)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016fc20(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5f3,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5f3,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0016fe70 FUN_0016fe70 =====

undefined8 FUN_0016fe70(char *param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x1f8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0016fec3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0016fee0 FUN_0016fee0 =====

int FUN_0016fee0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa12,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016fe70(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xa12,iVar1,uVar2);
  return iVar1;
}


// ===== 00170020 FUN_00170020 =====

undefined8 FUN_00170020(char *param_1,uint param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_2 < 2))))
  {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x200),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00170077. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 001700a0 FUN_001700a0 =====

int FUN_001700a0(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa17,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00170020(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xa17,iVar1,uVar2);
  return iVar1;
}


// ===== 001701e0 FUN_001701e0 =====

int FUN_001701e0(char *param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  float fVar5;
  undefined8 local_428;
  undefined4 local_420;
  
  puVar4 = &local_428;
  for (lVar3 = 0x82; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((iVar2 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    lVar3 = *(long *)(param_1 + 0x256d8);
    local_428._0_4_ = 0x1000410;
    if (((lVar3 == 0) || (*(long *)(lVar3 + 0x158) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(lVar3 + 0x158) + 0x70), pcVar1 == (code *)0x0)) {
      iVar2 = 3;
    }
    else {
      iVar2 = (*pcVar1)(lVar3,param_1);
      if (iVar2 == 0) {
        *param_2 = local_420;
        return 0;
      }
    }
    if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar3,"api.c",0x3522,"tsapiDeviceGetNvLinkDisableMask",0x3522,iVar2);
      return iVar2;
    }
  }
  return iVar2;
}


// ===== 00170340 FUN_00170340 =====

int FUN_00170340(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa1c,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001701e0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xa1c,iVar1,uVar2);
  return iVar1;
}


// ===== 00170480 FUN_00170480 =====

undefined8 FUN_00170480(char *param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_2 != 0)))
     ) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x158) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x158) + 0x70),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001704d5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00170500 FUN_00170500 =====

int FUN_00170500(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa26,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00170480(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xa26,iVar1,uVar2);
  return iVar1;
}


// ===== 00170640 FUN_00170640 =====

int FUN_00170640(uint *param_1,undefined8 *param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  void *__ptr;
  undefined8 *__ptr_00;
  int *piVar5;
  long lVar6;
  long lVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  byte bVar11;
  float fVar12;
  code *local_48;
  undefined8 *local_40;
  
  bVar11 = 0;
  if (param_1 == (uint *)0x0) {
    return 2;
  }
  if (param_1[0x262] == 0) {
    return 2;
  }
  if (param_1[0x263] != 2) {
    return 2;
  }
  iVar4 = 2;
  if (param_2 == (undefined8 *)0x0) {
    return 2;
  }
  if (param_3 == (int *)0x0) {
    return 2;
  }
  iVar3 = FUN_00236dd0();
  if (iVar3 == 0) {
    return 4;
  }
  uVar2 = *param_1;
  __ptr = malloc((ulong)uVar2 * 8);
  __ptr_00 = malloc((ulong)uVar2 * 0x418);
  if ((__ptr == (void *)0x0) || (__ptr_00 == (undefined8 *)0x0)) {
    if (1 < DAT_01216a78) {
      fVar12 = (float)FUN_002917b0(&DAT_01216a60);
      lVar7 = syscall(0xba);
      FUN_002340f0((double)(fVar12 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                   lVar7,"api.c",0x3587);
    }
    iVar4 = 0x14;
    if (__ptr == (void *)0x0) goto LAB_001707b8;
  }
  else if (uVar2 == 0) {
    local_48 = FUN_00138870;
    local_40 = __ptr_00;
    iVar4 = FUN_00123110(0,__ptr,param_3,&local_48,0,1);
  }
  else {
    lVar7 = 1;
    puVar10 = __ptr_00;
    do {
      if (*(long *)(param_1 + lVar7 * 2) == 0) {
        if (1 < DAT_01216a78) {
          fVar12 = (float)FUN_002917b0(&DAT_01216a60);
          lVar7 = syscall(0xba);
          FUN_002340f0((double)(fVar12 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       "ERROR",lVar7,"api.c",0x3590);
        }
        goto LAB_001707b0;
      }
      *(long *)((long)__ptr + lVar7 * 8 + -8) = *(long *)(param_1 + lVar7 * 2);
      lVar7 = lVar7 + 1;
      puVar8 = param_2;
      puVar9 = puVar10;
      for (lVar6 = 0x82; lVar6 != 0; lVar6 = lVar6 + -1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + (ulong)bVar11 * -2 + 1;
        puVar9 = puVar9 + (ulong)bVar11 * -2 + 1;
      }
      *(undefined4 *)(puVar10 + 0x82) = 0;
      param_2 = param_2 + 0x82;
      puVar10 = puVar10 + 0x83;
    } while (lVar7 != (ulong)(uVar2 - 1) + 2);
    local_48 = FUN_00138870;
    local_40 = __ptr_00;
    iVar4 = FUN_00123110(uVar2,__ptr,param_3,&local_48,0,1);
    if (iVar4 == 0) {
      piVar5 = (int *)(__ptr_00 + 0x82);
      piVar1 = param_3 + (ulong)(uVar2 - 1) + 1;
      do {
        iVar3 = *piVar5;
        *param_3 = iVar3;
        if (iVar3 != 0) {
          iVar4 = 999;
        }
        param_3 = param_3 + 1;
        piVar5 = piVar5 + 0x106;
      } while (param_3 != piVar1);
    }
  }
LAB_001707b0:
  free(__ptr);
LAB_001707b8:
  if (__ptr_00 != (undefined8 *)0x0) {
    free(__ptr_00);
  }
  return iVar4;
}


// ===== 00170920 FUN_00170920 =====

int FUN_00170920(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa2b,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00170640(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xa2b,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00170a60 FUN_00170a60 =====

undefined4 FUN_00170a60(uint *param_1,uint *param_2,long param_3)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *__ptr;
  undefined4 *puVar4;
  long lVar5;
  float fVar6;
  
  if (param_1 != (uint *)0x0) {
    if (param_1[0x262] == 0) {
      return 2;
    }
    if (param_1[0x263] == 2) {
      if (param_2 == (uint *)0x0) {
        return 2;
      }
      if (param_3 == 0) {
        return 2;
      }
      uVar2 = *param_1;
      __ptr = malloc((ulong)uVar2 * 0x410);
      if (__ptr != (undefined4 *)0x0) {
        if (uVar2 != 0) {
          puVar1 = param_2 + (ulong)(uVar2 - 1) + 1;
          puVar4 = __ptr;
          do {
            uVar2 = *param_2;
            param_2 = param_2 + 1;
            *puVar4 = 0x1000410;
            puVar4[0x102] = 1;
            *(ulong *)(puVar4 + 2) = (ulong)uVar2;
            puVar4 = puVar4 + 0x104;
          } while (param_2 != puVar1);
        }
        uVar3 = FUN_00170640(param_1,__ptr,param_3);
        free(__ptr);
        return uVar3;
      }
      if (DAT_01216a78 < 2) {
        return 0x14;
      }
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                   lVar5,"api.c",0x3540);
      return 0x14;
    }
  }
  return 2;
}


// ===== 00170bc0 FUN_00170bc0 =====

int FUN_00170bc0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa21,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00170a60(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xa21,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00170d00 FUN_00170d00 =====

undefined8 FUN_00170d00(void)

{
  return 3;
}


// ===== 00170d10 FUN_00170d10 =====

int FUN_00170d10(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa31,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00170d00(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xa31,iVar1,uVar2);
  return iVar1;
}


// ===== 00170e50 FUN_00170e50 =====

undefined8 FUN_00170e50(void)

{
  return 3;
}


// ===== 00170e60 FUN_00170e60 =====

int FUN_00170e60(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa35,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00170e50(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xa35,iVar1,uVar2);
  return iVar1;
}


// ===== 00170fa0 FUN_00170fa0 =====

undefined8 FUN_00170fa0(char *param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_2 != 0)))
     ) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0xd8) != (undefined8 *)0x0)) &&
       (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar1 + 0xd8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00170ff4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00171020 FUN_00171020 =====

int FUN_00171020(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa3b,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00170fa0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xa3b,iVar1,uVar2);
  return iVar1;
}


// ===== 00171160 FUN_00171160 =====

undefined8 FUN_00171160(char *param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_2 != 0)))
     ) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x48) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x48) + 0xa0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001711b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 001711e0 nvmlDeviceGetIrqNum =====

int nvmlDeviceGetIrqNum(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x593,"nvmlDeviceGetIrqNum",
                 "(nvmlDevice_t device, unsigned int *irqNum)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00171160(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x593,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x593,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001713c0 FUN_001713c0 =====

undefined8 FUN_001713c0(char *param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  int local_20;
  undefined1 local_1c [4];
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((uVar4 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (param_2 == 0) {
      return 2;
    }
    iVar3 = FUN_0016a2b0(param_1,&local_20,local_1c);
    if (((iVar3 == 0) && (local_20 == 1)) ||
       ((lVar1 = *(long *)(param_1 + 0x256d8), lVar1 == 0 ||
        ((*(long *)(lVar1 + 0x20) == 0 ||
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x20) + 0x48), pcVar2 == (code *)0x0)))))) {
      return 3;
    }
    uVar4 = (*pcVar2)(lVar1,param_1,param_2);
  }
  return uVar4;
}


// ===== 00171490 nvmlDeviceGetNumGpuCores =====

int nvmlDeviceGetNumGpuCores(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x598,"nvmlDeviceGetNumGpuCores",
                 "(nvmlDevice_t device, unsigned int *numCores)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001713c0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x598,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x598,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00171670 FUN_00171670 =====

undefined8 FUN_00171670(char *param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_2 != 0)))
     ) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x160) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0xe8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001716c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 001716f0 nvmlDeviceGetPowerSource =====

int nvmlDeviceGetPowerSource(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x59d,"nvmlDeviceGetPowerSource",
                 "(nvmlDevice_t device, nvmlPowerSource_t *powerSource)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00171670(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x59d,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x59d,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001718d0 FUN_001718d0 =====

undefined8 FUN_001718d0(char *param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_2 != 0)))
     ) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x68) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x68) + 0x20),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00171922. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00171940 nvmlDeviceGetMemoryBusWidth =====

int nvmlDeviceGetMemoryBusWidth(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x5a2,"nvmlDeviceGetMemoryBusWidth",
                 "(nvmlDevice_t device, unsigned int *busWidth)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001718d0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5a2,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5a2,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00171b20 FUN_00171b20 =====

undefined8 FUN_00171b20(char *param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_2 != 0)))
     ) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x48) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x48) + 0xa8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00171b75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00171ba0 nvmlDeviceGetPcieLinkMaxSpeed =====

int nvmlDeviceGetPcieLinkMaxSpeed(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x5a7,"nvmlDeviceGetPcieLinkMaxSpeed",
                 "(nvmlDevice_t device, unsigned int *maxSpeed)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00171b20(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5a7,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5a7,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00171d80 FUN_00171d80 =====

undefined8 FUN_00171d80(char *param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_2 != 0)))
     ) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x208),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00171dd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00171e00 nvmlDeviceGetAdaptiveClockInfoStatus =====

int nvmlDeviceGetAdaptiveClockInfoStatus(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x5ac,"nvmlDeviceGetAdaptiveClockInfoStatus",
                 "(nvmlDevice_t device, unsigned int *adaptiveClockStatus)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00171d80(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5ac,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5ac,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00171fe0 FUN_00171fe0 =====

/* WARNING: Type propagation algorithm not settling */

undefined8 FUN_00171fe0(ulong param_1,uint *param_2)

{
  ulong uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  
  if (param_2 == (uint *)0x0) {
    return 2;
  }
  uVar3 = 1;
  *param_2 = 0;
  if (param_1 != 0) {
    do {
      while ((param_1 & uVar3) != 0) {
        if (uVar3 != 0x2000000) {
          if (uVar3 < 0x2000001) {
            if (uVar3 != 0x8000) {
              if (uVar3 < 0x8001) {
                if (uVar3 < 0x21) {
                  if ((0x100010016U >> (uVar3 & 0x3f) & 1) == 0) {
LAB_00172070:
                    if (3 < DAT_01216a78) {
                      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
                      lVar2 = syscall(0xba);
                      FUN_002340f0((double)(fVar4 * DAT_00298548),
                                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%llu\n",&DAT_002983c2,lVar2,
                                   "api.c",0x37a5,uVar3);
                    }
                    break;
                  }
                }
                else if (uVar3 != 0x800) goto LAB_00172070;
              }
              else if (uVar3 != 0x80000) {
                if (uVar3 < 0x80001) {
                  uVar1 = uVar3 - 0x10000 & 0xfffffffffffeffff;
                }
                else {
                  uVar1 = uVar3 - 0x400000 & 0xffffffffffbfffff;
                }
                goto joined_r0x00172121;
              }
            }
          }
          else if (uVar3 != 0x100000000) {
            if (uVar3 < 0x100000001) {
              if (uVar3 != 0x20000000) {
                if (0x20000000 < uVar3) {
                  uVar1 = uVar3 - 0x40000000 & 0xffffffffbfffffff;
                  goto joined_r0x00172121;
                }
                if ((uVar3 != 0x4000000) && (uVar3 != 0x10000000)) goto LAB_00172070;
              }
            }
            else if (uVar3 != 0x800000000) {
              if (uVar3 < 0x800000001) {
                uVar1 = uVar3 - 0x200000000 & 0xfffffffdffffffff;
              }
              else {
                uVar1 = uVar3 - 0x1000000000 & 0xffffffefffffffff;
              }
joined_r0x00172121:
              if (uVar1 != 0) goto LAB_00172070;
            }
          }
        }
        uVar3 = uVar3 * 2;
        *param_2 = *param_2 | 1;
        if (param_1 < uVar3) {
          return 0;
        }
      }
      uVar3 = uVar3 * 2;
    } while (uVar3 <= param_1);
  }
  return 0;
}


// ===== 00172210 FUN_00172210 =====

int FUN_00172210(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%llu, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa70,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00171fe0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xa70,iVar1,uVar2);
  return iVar1;
}


// ===== 00172350 FUN_00172350 =====

undefined8 FUN_00172350(char *param_1,undefined4 *param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_24 = 0;
  iVar3 = FUN_00139230(param_1,&local_24,0xc);
  uVar4 = 999;
  if ((iVar3 == 0) && (uVar4 = 3, local_24 != 0)) {
    iVar3 = FUN_00236dd0();
    uVar4 = 4;
    if (iVar3 != 0) {
      if (param_1 != (char *)0x0) {
        if (*param_1 != '\x01') {
          if (*(int *)(param_1 + 0x14) == 0) {
            return 2;
          }
          if (*(int *)(param_1 + 0x1c) != 0) {
            return 2;
          }
          if (*(int *)(param_1 + 0x10) == 0) {
            return 2;
          }
          if (*(long *)(param_1 + 0x20) == 0) {
            return 2;
          }
        }
        if (param_2 != (undefined4 *)0x0) {
          local_20 = *param_2;
          lVar1 = *(long *)(param_1 + 0x256d8);
          local_1c = 0xffffffff;
          if (((lVar1 != 0) && (*(long *)(lVar1 + 0x158) != 0)) &&
             (pcVar2 = *(code **)(*(long *)(lVar1 + 0x158) + 0x98), pcVar2 != (code *)0x0)) {
            uVar4 = (*pcVar2)(lVar1,param_1,&local_20);
            return uVar4;
          }
          return 3;
        }
      }
      uVar4 = 2;
    }
  }
  return uVar4;
}


// ===== 00172440 nvmlDeviceSetNvLinkDeviceLowPowerThreshold =====

int nvmlDeviceSetNvLinkDeviceLowPowerThreshold(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x683,"nvmlDeviceSetNvLinkDeviceLowPowerThreshold",
                 "(nvmlDevice_t device, nvmlNvLinkPowerThres_t *info)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00172350(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x683,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x683,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00172620 FUN_00172620 =====

undefined8 FUN_00172620(char *param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  int local_1c;
  
  local_1c = 0;
  iVar3 = FUN_00139230(param_1,&local_1c,0xc);
  if (iVar3 != 0) {
    return 999;
  }
  if (local_1c == 0) {
    return 3;
  }
  iVar3 = FUN_00236dd0();
  if (iVar3 == 0) {
    return 4;
  }
  if (param_1 != (char *)0x0) {
    if (*param_1 != '\x01') {
      if (*(int *)(param_1 + 0x14) == 0) {
        return 2;
      }
      if (*(int *)(param_1 + 0x1c) != 0) {
        return 2;
      }
      if (*(int *)(param_1 + 0x10) == 0) {
        return 2;
      }
      if (*(long *)(param_1 + 0x20) == 0) {
        return 2;
      }
    }
    if (param_2 != 0) {
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (lVar1 == 0) {
        return 3;
      }
      if (*(long *)(lVar1 + 0x158) != 0) {
        pcVar2 = *(code **)(*(long *)(lVar1 + 0x158) + 0x98);
        if (pcVar2 != (code *)0x0) {
          uVar4 = (*pcVar2)(lVar1,param_1,param_2);
          return uVar4;
        }
        return 3;
      }
      return 3;
    }
  }
  return 2;
}


// ===== 00172710 FUN_00172710 =====

int FUN_00172710(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xb2f,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00172620(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xb2f,iVar1,uVar2);
  return iVar1;
}


// ===== 00172850 FUN_00172850 =====

undefined8 FUN_00172850(char *param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  int local_1c;
  
  local_1c = 0;
  iVar3 = FUN_00139230(param_1,&local_1c,0xd);
  uVar4 = 999;
  if ((iVar3 == 0) && (uVar4 = 3, local_1c != 0)) {
    if (param_1 == (char *)0x0) {
      return 2;
    }
    if ((*param_1 == '\x01') ||
       ((((uVar4 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
      if (param_2 == 0) {
        return 2;
      }
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (((lVar1 == 0) || (*(long *)(lVar1 + 0x158) == 0)) ||
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x158) + 0xa0), pcVar2 == (code *)0x0)) {
        return 3;
      }
      uVar4 = (*pcVar2)(lVar1,param_1,param_2);
    }
  }
  return uVar4;
}


// ===== 00172920 FUN_00172920 =====

int FUN_00172920(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xb35,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00172850(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xb35,iVar1,uVar2);
  return iVar1;
}


// ===== 00172a60 FUN_00172a60 =====

undefined8 FUN_00172a60(char *param_1,uint *param_2)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  if (param_1 != (char *)0x0) {
    if ((*param_1 == '\x01') ||
       ((((uVar3 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
      if (param_2 == (uint *)0x0) {
        uVar3 = 2;
      }
      else {
        lVar1 = *(long *)(param_1 + 0x256d8);
        if (((lVar1 == 0) || (*(undefined8 **)(lVar1 + 0x140) == (undefined8 *)0x0)) ||
           (pcVar2 = (code *)**(undefined8 **)(lVar1 + 0x140), pcVar2 == (code *)0x0)) {
          uVar3 = 3;
          *param_2 = 0;
        }
        else {
          uVar3 = (*pcVar2)(lVar1,param_1);
          *param_2 = (uint)((int)uVar3 == 0);
        }
      }
    }
    return uVar3;
  }
  return 2;
}


// ===== 00172b10 FUN_00172b10 =====

int FUN_00172b10(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa75,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00172a60(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xa75,iVar1,uVar2);
  return iVar1;
}


// ===== 00172c50 FUN_00172c50 =====

undefined8 FUN_00172c50(undefined8 *param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (param_1 == (undefined8 *)0x0) {
    return 2;
  }
  *param_1 = 0;
  if (((DAT_012164a0 != 0) && (*(undefined8 **)(DAT_012164a0 + 0x108) != (undefined8 *)0x0)) &&
     (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(DAT_012164a0 + 0x108),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00172c86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar1;
  }
  return 3;
}


// ===== 00172cb0 nvmlSystemGetConfComputeCapabilities =====

int nvmlSystemGetConfComputeCapabilities(char *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  char *pcVar5;
  
  pcVar5 = param_1;
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    pcVar5 = "(nvmlConfComputeSystemCaps_t *caps)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x612,"nvmlSystemGetConfComputeCapabilities");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_00172c50(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x612,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x612,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00172e80 FUN_00172e80 =====

undefined8 FUN_00172e80(long param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x108) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x108) + 8),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00172eb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar1;
  }
  return 3;
}


// ===== 00172ed0 nvmlSystemGetConfComputeState =====

int nvmlSystemGetConfComputeState(char *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  char *pcVar5;
  
  pcVar5 = param_1;
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    pcVar5 = "(nvmlConfComputeSystemState_t *state)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x618,"nvmlSystemGetConfComputeState");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_00172e80(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x618,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x618,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001730a0 FUN_001730a0 =====

undefined8 FUN_001730a0(undefined8 param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x108) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x108) + 0x50),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001730cb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar1;
  }
  return 3;
}


// ===== 001730e0 nvmlSystemGetConfComputeSettings =====

int nvmlSystemGetConfComputeSettings(char *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  char *pcVar5;
  
  pcVar5 = param_1;
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    pcVar5 = "(nvmlSystemConfComputeSettings_t *settings)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x653,"nvmlSystemGetConfComputeSettings");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_001730a0(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x653,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x653,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001732b0 FUN_001732b0 =====

undefined8 FUN_001732b0(char *param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (9 < *(uint *)(param_1 + 0x708)) {
    if (((*param_1 != '\x01') &&
        ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
          (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) || (param_2 == 0))
    {
      return 2;
    }
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x108) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x108) + 0x20),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00173309. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
  }
  return 3;
}


// ===== 00173330 nvmlDeviceGetConfComputeMemSizeInfo =====

int nvmlDeviceGetConfComputeMemSizeInfo(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x61e,"nvmlDeviceGetConfComputeMemSizeInfo",
                 "(nvmlDevice_t device, nvmlConfComputeMemSizeInfo_t *memInfo)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001732b0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x61e,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x61e,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00173510 FUN_00173510 =====

undefined8 FUN_00173510(char *param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (9 < *(uint *)(param_1 + 0x708)) {
    if ((*param_1 != '\x01') &&
       ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
         (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) {
      return 2;
    }
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x108) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x108) + 0x28),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00173564. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
  }
  return 3;
}


// ===== 00173590 nvmlDeviceSetConfComputeUnprotectedMemSize =====

int nvmlDeviceSetConfComputeUnprotectedMemSize(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %llu)\n","DEBUG",lVar3,
                 "entry_points.h",0x624,"nvmlDeviceSetConfComputeUnprotectedMemSize",
                 "(nvmlDevice_t device, unsigned long long sizeKiB)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00173510(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x624,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x624,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00173770 FUN_00173770 =====

undefined8 FUN_00173770(uint param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (1 < param_1) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x108) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x108) + 0x10),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0017379f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar1;
  }
  return 3;
}


// ===== 001737c0 nvmlSystemSetConfComputeGpusReadyState =====

int nvmlSystemSetConfComputeGpusReadyState(char *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  ulong uVar4;
  float fVar5;
  
  uVar4 = (ulong)param_1 & 0xffffffff;
  if (4 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    param_1 = "(unsigned int isAcceptingWork)";
    FUN_002340f0((double)(fVar5 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%u)\n","DEBUG",lVar3,
                 "entry_points.h",0x62a,"nvmlSystemSetConfComputeGpusReadyState");
  }
  iVar1 = FUN_0011fea0(param_1);
  if (iVar1 == 0) {
    iVar1 = FUN_00173770(uVar4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x62a,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x62a,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00173990 FUN_00173990 =====

undefined8 FUN_00173990(long param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x108) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x108) + 0x18),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001739c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar1;
  }
  return 3;
}


// ===== 001739e0 nvmlSystemGetConfComputeGpusReadyState =====

int nvmlSystemGetConfComputeGpusReadyState(char *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  char *pcVar5;
  
  pcVar5 = param_1;
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    pcVar5 = "(unsigned int *isAcceptingWork)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x630,"nvmlSystemGetConfComputeGpusReadyState");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_00173990(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x630,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x630,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00173bb0 FUN_00173bb0 =====

undefined8 FUN_00173bb0(char *param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (((param_1 != (char *)0x0) && (param_2 != 0)) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x68) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x68) + 0x18),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00173c02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00173c20 nvmlDeviceGetConfComputeProtectedMemoryUsage =====

int nvmlDeviceGetConfComputeProtectedMemoryUsage(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x636,"nvmlDeviceGetConfComputeProtectedMemoryUsage",
                 "(nvmlDevice_t device, nvmlMemory_t *memory)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00173bb0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x636,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x636,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00173e00 FUN_00173e00 =====

undefined8 FUN_00173e00(char *param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (((param_2 != 0) && (param_1 != (char *)0x0)) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x108) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x108) + 0x30),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00173e55. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00173e80 nvmlDeviceGetConfComputeGpuCertificate =====

int nvmlDeviceGetConfComputeGpuCertificate(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x63b,"nvmlDeviceGetConfComputeGpuCertificate",
                 "(nvmlDevice_t device, nvmlConfComputeGpuCertificate_t *gpuCert)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00173e00(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x63b,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x63b,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00174060 FUN_00174060 =====

undefined8 FUN_00174060(char *param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (((param_2 != 0) && (param_1 != (char *)0x0)) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x108) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x108) + 0x38),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001740b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 001740e0 nvmlDeviceGetConfComputeGpuAttestationReport =====

int nvmlDeviceGetConfComputeGpuAttestationReport(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x641,"nvmlDeviceGetConfComputeGpuAttestationReport",
                 "(nvmlDevice_t device, nvmlConfComputeGpuAttestationReport_t *gpuAtstReport)",
                 param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00174060(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x641,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x641,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001742c0 FUN_001742c0 =====

undefined8 FUN_001742c0(int *param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (param_1 == (int *)0x0) {
    return 2;
  }
  if (*param_1 == 0x1000010) {
    if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x108) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x108) + 0x40),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001742f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
      return uVar1;
    }
    return 3;
  }
  return 0x19;
}


// ===== 00174330 nvmlSystemSetConfComputeKeyRotationThresholdInfo =====

int nvmlSystemSetConfComputeKeyRotationThresholdInfo(char *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  char *pcVar5;
  
  pcVar5 = param_1;
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    pcVar5 = "(nvmlConfComputeSetKeyRotationThresholdInfo_t *pKeyRotationThrInfo)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x647,"nvmlSystemSetConfComputeKeyRotationThresholdInfo");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_001742c0(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x647,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x647,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00174500 FUN_00174500 =====

undefined8 FUN_00174500(int *param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (param_1 == (int *)0x0) {
    return 2;
  }
  if (*param_1 == 0x1000010) {
    if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x108) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x108) + 0x48),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00174538. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
      return uVar1;
    }
    return 3;
  }
  return 0x19;
}


// ===== 00174570 nvmlSystemGetConfComputeKeyRotationThresholdInfo =====

int nvmlSystemGetConfComputeKeyRotationThresholdInfo(char *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  char *pcVar5;
  
  pcVar5 = param_1;
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    pcVar5 = "(nvmlConfComputeGetKeyRotationThresholdInfo_t *pKeyRotationThrInfo)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x64d,"nvmlSystemGetConfComputeKeyRotationThresholdInfo");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_00174500(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x64d,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x64d,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00174740 thunk_FUN_0012c920 =====

undefined8 thunk_FUN_0012c920(int *param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  char *pcVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  uint uVar8;
  undefined *puVar9;
  float fVar10;
  
  if (param_1 == (int *)0x0) {
    if (DAT_01216a78 < 2) {
      return 2;
    }
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    uVar7 = 0x80a;
    fVar10 = fVar10 * DAT_00298548;
LAB_0012ca59:
    FUN_002340f0((double)fVar10,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar5,"nvml_gpm.c",
                 uVar7);
    return 2;
  }
  if (*param_1 != 1) {
    return 0x19;
  }
  if ((((0x14c < param_1[1] - 1U) ||
       (puVar2 = *(undefined8 **)(param_1 + 2), puVar2 == (undefined8 *)0x0)) ||
      (puVar3 = *(undefined8 **)(param_1 + 4), puVar3 == (undefined8 *)0x0)) || (puVar2 == puVar3))
  {
    if (DAT_01216a78 < 2) {
      return 2;
    }
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    uVar7 = 0x816;
    fVar10 = fVar10 * DAT_00298548;
    goto LAB_0012ca59;
  }
  pcVar4 = (char *)*puVar2;
  if (pcVar4 != (char *)*puVar3) {
    return 2;
  }
  if (pcVar4 != (char *)0x0) {
    if (*(long *)(pcVar4 + 0x70508) == 0) {
      return 3;
    }
    iVar1 = *(int *)(*(long *)(pcVar4 + 0x70508) + 0xb0);
    if (iVar1 == 0) {
      return 3;
    }
    if (((*pcVar4 != '\x01') && (*(long *)(pcVar4 + 0x20) == 0)) || (*(char *)(puVar2 + 2) != '\0'))
    {
      if (iVar1 == 1) {
        puVar9 = &DAT_00369f40;
      }
      else if (iVar1 == 2) {
        puVar9 = &DAT_00356700;
      }
      else if (iVar1 == 3) {
        puVar9 = &DAT_00342ec0;
      }
      else {
        if (iVar1 != 4) {
          return 3;
        }
        puVar9 = &DAT_0032f680;
      }
      goto LAB_0012cb17;
    }
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        puVar9 = &DAT_00360320;
      }
      else if (iVar1 == 3) {
        puVar9 = &DAT_0034cae0;
      }
      else {
        if (iVar1 != 4) {
          return 3;
        }
        puVar9 = &DAT_003392a0;
      }
      goto LAB_0012cb17;
    }
  }
  puVar9 = &DAT_00373b60;
LAB_0012cb17:
  uVar8 = 0;
  do {
    while (uVar6 = (ulong)uVar8, 0x14b < param_1[uVar6 * 10 + 6] - 1U) {
      param_1[uVar6 * 10 + 7] = 2;
      uVar8 = uVar8 + 1;
      if ((uint)param_1[1] <= uVar8) {
        return 0;
      }
    }
    FUN_00129850(param_1 + uVar6 * 10 + 6,puVar9,puVar2,puVar3);
    uVar8 = uVar8 + 1;
  } while (uVar8 < (uint)param_1[1]);
  return 0;
}


// ===== 00174750 nvmlGpmMetricsGet =====

int nvmlGpmMetricsGet(char *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  char *pcVar5;
  
  pcVar5 = param_1;
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    pcVar5 = "(nvmlGpmMetricsGet_t *metricsGet)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x65b,"nvmlGpmMetricsGet");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_0012c920(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x65b,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x65b,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00174920 FUN_00174920 =====

undefined8 FUN_00174920(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    uVar1 = FUN_0012c010();
    return uVar1;
  }
  return 2;
}


// ===== 00174940 nvmlGpmSampleAlloc =====

int nvmlGpmSampleAlloc(char *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  char *pcVar5;
  
  pcVar5 = param_1;
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    pcVar5 = "(nvmlGpmSample_t *gpmSample)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x660,"nvmlGpmSampleAlloc");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_00174920(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x660,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x660,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00174b10 thunk_FUN_0012c040 =====

undefined8 thunk_FUN_0012c040(void *param_1)

{
  free(param_1);
  return 0;
}


// ===== 00174b20 nvmlGpmSampleFree =====

int nvmlGpmSampleFree(char *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  char *pcVar5;
  
  pcVar5 = param_1;
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    pcVar5 = "(nvmlGpmSample_t gpmSample)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x665,"nvmlGpmSampleFree");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_0012c040(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x665,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x665,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00174cf0 thunk_FUN_0012ce30 =====

undefined8 thunk_FUN_0012ce30(char *param_1,undefined8 *param_2)

{
  undefined8 *__dest;
  void *__src;
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  ulong __n;
  ulong uVar5;
  int iVar6;
  undefined8 *puVar7;
  long *plVar8;
  float fVar9;
  ulong uStack_68;
  ulong uStack_60;
  long *plStack_50;
  long *plStack_40;
  
  __dest = param_2 + 0x15;
  param_2[2] = 0;
  param_2[0x13] = 0;
  puVar7 = (undefined8 *)((ulong)(param_2 + 3) & 0xfffffffffffffff8);
  for (uVar4 = (ulong)(((int)param_2 -
                       (int)(undefined8 *)((ulong)(param_2 + 3) & 0xfffffffffffffff8)) + 0xa0U >> 3)
      ; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  uVar1 = FUN_0012c050(param_1);
  if (((int)uVar1 != 0) && ((int)uVar1 != 5)) {
    return uVar1;
  }
  uVar1 = FUN_0012ccf0(param_1);
  if (((int)uVar1 != 0) && ((int)uVar1 != 5)) {
    return uVar1;
  }
  lVar3 = *(long *)(param_1 + 0x70508);
  uVar4 = *(ulong *)(lVar3 + 0x10);
  if (*(int *)(lVar3 + 0xb0) != 1) {
    if ((*param_1 == '\x01') || (*(long *)(param_1 + 0x20) != 0)) {
      uStack_60 = uVar4 - 0x880;
    }
    else {
      uStack_60 = uVar4 - 0x438;
    }
    if (0x8010 < uStack_60) {
LAB_0012d0e8:
      if (1 < DAT_01216a78) {
        fVar9 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%zu %zu\n",
                     "ERROR",lVar3,"nvml_gpm.c",0x47e,uStack_60,0x8010);
      }
      FUN_00128790(param_1);
      return 0x17;
    }
    plStack_40 = *(long **)(lVar3 + 0x18);
    plVar8 = (long *)((long)plStack_40 + (uVar4 & 0xfffffffffffffff8) + 8);
    __n = uStack_60 >> 1;
    plStack_50 = (long *)((long)param_2 + (uStack_60 & 0xfffffffffffffff8) + 0xa0);
    uVar5 = __n & 0xfffffffffffffff8;
    uStack_68 = __n + 0x448 & 0xfffffffffffffff8;
    goto LAB_0012cf3b;
  }
  if (*param_1 == '\x01') {
    uStack_60 = uVar4 + 0x10;
    if (0x8010 < uStack_60) goto LAB_0012d0e8;
    plStack_40 = *(long **)(lVar3 + 0x18);
    lVar2 = (uVar4 & 0xfffffffffffffff8) + 8;
    __n = uStack_60 >> 1;
    plVar8 = (long *)((long)plStack_40 + lVar2);
    uStack_68 = __n + 0x448 & 0xfffffffffffffff8;
    uVar5 = __n & 0xfffffffffffffff8;
LAB_0012d0d6:
    uStack_60 = uVar4 + 0x10;
    plStack_50 = (long *)(lVar2 + (long)__dest);
  }
  else {
    if (*(long *)(param_1 + 0x20) == 0) {
      plStack_40 = *(long **)(lVar3 + 0x18);
      uVar5 = 0x408;
      __n = 0x408;
      uStack_68 = 0x850;
      uStack_60 = 0x810;
    }
    else {
      uStack_60 = uVar4 + 0x10;
      if (0x8010 < uStack_60) goto LAB_0012d0e8;
      plStack_40 = *(long **)(lVar3 + 0x18);
      lVar2 = (uVar4 & 0xfffffffffffffff8) + 8;
      __n = uStack_60 >> 1;
      plVar8 = (long *)((long)plStack_40 + lVar2);
      uStack_68 = __n + 0x448 & 0xfffffffffffffff8;
      uVar5 = __n & 0xfffffffffffffff8;
      if (*(long *)(param_1 + 0x20) != 0) goto LAB_0012d0d6;
    }
    plStack_50 = param_2 + 0x116;
    plVar8 = plStack_40 + 0x101;
  }
LAB_0012cf3b:
  *(int *)(param_2 + 0x1017) = (int)plVar8[1];
  iVar6 = 10;
  do {
    while (*plStack_40 == *plVar8) {
      __src = *(void **)(lVar3 + 0x18);
      if (*(int *)(lVar3 + 0xb0) == 1) {
        memcpy(__dest,__src,uStack_60);
      }
      else if ((*param_1 == '\x01') || (*(long *)(param_1 + 0x20) != 0)) {
        memcpy(__dest,__src,__n);
        memcpy((void *)((long)__dest + uVar5),(void *)(uStack_68 + *(long *)(lVar3 + 0x18)),__n);
        *(long *)((long)param_2 + (uStack_60 & 0xfffffffffffffff8) + 0xa0) = *plVar8;
      }
      else {
        memcpy(__dest,__src,uStack_60 - 8);
        *(long *)((long)__dest + (uStack_60 - 8 & 0xfffffffffffffff8)) = *plVar8;
      }
      if (param_2[0x15] == *plStack_50) {
        param_2[1] = param_2[0x15];
        param_2[0x14] = param_2 + 0x16;
        *param_2 = param_1;
        FUN_00128790(param_1);
        return 0;
      }
      iVar6 = iVar6 + -1;
      if (iVar6 == 0) goto LAB_0012d013;
    }
    FUN_00292f00(1);
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
LAB_0012d013:
  FUN_00128790(param_1);
  return 10;
}


// ===== 00174d00 nvmlGpmSampleGet =====

int nvmlGpmSampleGet(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x66a,"nvmlGpmSampleGet",
                 "(nvmlDevice_t device, nvmlGpmSample_t gpmSample)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_0012ce30(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x66a,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x66a,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00174ee0 thunk_FUN_0012d250 =====

int thunk_FUN_0012d250(long param_1,int param_2,long *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  ulong uVar8;
  undefined8 uVar9;
  uint uVar10;
  float fVar12;
  undefined8 uVar13;
  uint uStack_48;
  int iStack_44;
  long alStack_40 [2];
  ulong uVar11;
  
  if ((param_1 == 0) || (param_3 == (long *)0x0)) {
LAB_0012d640:
    iVar3 = 2;
  }
  else {
    iVar3 = FUN_00128810();
    if (iVar3 == 4) {
      if (DAT_01216a78 < 2) {
        return 4;
      }
      fVar12 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar12 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                   lVar5,"nvml_gpm.c",0x527);
    }
    else if (iVar3 == 0) {
      lVar5 = *(long *)(param_1 + 0x70508);
      if (lVar5 == 0) {
        if (DAT_01216a78 < 2) {
          return 0;
        }
        fVar12 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        FUN_002340f0((double)(fVar12 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR"
                     ,lVar5,"nvml_gpm.c",0x532);
        return 0;
      }
      iVar3 = FUN_0012bd20(param_1);
      if (iVar3 != 0) {
        if (DAT_01216a78 < 2) {
          return iVar3;
        }
        fVar12 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        fVar12 = fVar12 * DAT_00298548;
        uVar13 = 0x537;
        uVar9 = 0x537;
LAB_0012d6a5:
        FUN_002340f0((double)fVar12,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,
                     "nvml_gpm.c",uVar9,"gpmMigSampleGet",uVar13,iVar3);
        return iVar3;
      }
      if (*(int *)(lVar5 + 0xb0) == 0) {
        return 3;
      }
      if (((*param_3 == param_1) && ((char)param_3[2] != '\0')) &&
         (*(int *)((long)param_3 + 0x14) == param_2)) {
LAB_0012d3ba:
        if ((int)param_3[3] != 0) {
          iVar3 = FUN_0012c010(alStack_40);
          param_3[1] = 0;
          param_3[0x14] = (long)(param_3 + 0x16);
          memset(param_3 + 0x15,0,0x8010);
          if ((int)param_3[3] != 0) {
            uVar11 = 0;
            do {
              iVar3 = FUN_0012ce30(param_3[uVar11 * 2 + 5],alStack_40[0]);
              if ((iVar3 != 0) ||
                 (uVar10 = *(uint *)((long)param_3 + uVar11 * 0x10 + 0x24), 7 < uVar10)) break;
              uVar2 = *(uint *)(lVar5 + 0xb0);
              lVar4 = 0xb0;
              uVar6 = 0xffffff90;
              uVar8 = (ulong)*(uint *)(lVar5 + 100 + (ulong)uVar10 * 4);
              do {
                lVar7 = *(long *)(alStack_40[0] + lVar4);
                if (uVar2 == 3) goto LAB_0012d477;
                if (3 < uVar2) goto LAB_0012d499;
LAB_0012d465:
                if (uVar2 != 1) {
                  if (uVar2 == 2) {
LAB_0012d477:
                    while ((uVar6 & 0xffffffbf) == 0) {
                      while( true ) {
                        *(long *)((long)param_3 + lVar4) =
                             *(long *)((long)param_3 + lVar4) + lVar7 * uVar8;
                        lVar4 = lVar4 + 8;
                        uVar6 = uVar6 + 1;
                        lVar7 = *(long *)(alStack_40[0] + lVar4);
                        if (uVar2 == 3) break;
                        if (uVar2 < 4) goto LAB_0012d465;
LAB_0012d499:
                        if (uVar2 != 4) goto LAB_0012d760;
                        if ((uVar6 & 0xffffffef) != 0) goto LAB_0012d4aa;
                      }
                    }
                    goto LAB_0012d4aa;
                  }
LAB_0012d760:
                  iVar3 = 3;
                  goto LAB_0012d4d8;
                }
                if ((uVar6 + 0x20 & 0xffffffbf) == 0) {
                  lVar7 = lVar7 * uVar8;
                }
LAB_0012d4aa:
                uVar6 = uVar6 + 1;
                *(long *)((long)param_3 + lVar4) = *(long *)((long)param_3 + lVar4) + lVar7;
                lVar4 = lVar4 + 8;
              } while (uVar6 != 0xf91);
              uVar10 = (int)uVar11 + 1;
              uVar11 = (ulong)uVar10;
              param_3[1] = param_3[1] + *(long *)(alStack_40[0] + 8);
            } while (uVar10 < *(uint *)(param_3 + 3));
          }
LAB_0012d4d8:
          FUN_0012c040(alStack_40[0]);
          return iVar3;
        }
      }
      else {
        uStack_48 = 0;
        iVar3 = FUN_0016dc70(param_1,&uStack_48);
        if (iVar3 != 0) {
          if (DAT_01216a78 < 2) {
            return iVar3;
          }
          fVar12 = (float)FUN_002917b0(&DAT_01216a60);
          lVar5 = syscall(0xba);
          fVar12 = fVar12 * DAT_00298548;
          uVar13 = 0x543;
          uVar9 = 0x543;
          goto LAB_0012d6a5;
        }
        if (8 < uStack_48) {
          return 7;
        }
        *param_3 = param_1;
        *(undefined1 *)(param_3 + 2) = 1;
        *(int *)((long)param_3 + 0x14) = param_2;
        *(undefined4 *)(param_3 + 3) = 0;
        if (uStack_48 != 0) {
          uVar11 = 0;
          do {
            iVar3 = FUN_0016de90(param_1,uVar11,alStack_40);
            if (iVar3 == 0) {
              iStack_44 = 0;
              iVar3 = FUN_0016d830(alStack_40[0]);
              if ((iVar3 == 0) && (iStack_44 == param_2)) {
                uVar10 = *(uint *)(param_3 + 3);
                param_3[(ulong)uVar10 * 2 + 5] = alStack_40[0];
                *(int *)((long)param_3 + (ulong)uVar10 * 0x10 + 0x24) = (int)uVar11;
                *(undefined4 *)(param_3 + (ulong)uVar10 * 2 + 4) =
                     *(undefined4 *)(lVar5 + 100 + uVar11 * 4);
                uVar1 = *(undefined4 *)(lVar5 + 0x84 + uVar11 * 4);
                *(uint *)(param_3 + 3) = uVar10 + 1;
                *(undefined4 *)((long)param_3 + 0x1c) = uVar1;
              }
            }
            uVar10 = (int)uVar11 + 1;
            uVar11 = (ulong)uVar10;
          } while (uVar10 < uStack_48);
          goto LAB_0012d3ba;
        }
      }
      if (2 < DAT_01216a78) {
        fVar12 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        FUN_002340f0((double)(fVar12 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %p\n",
                     "WARNING",lVar5,"nvml_gpm.c",0x56b,param_2,param_1);
      }
      goto LAB_0012d640;
    }
    if (1 < DAT_01216a78) {
      uVar9 = nvmlErrorString(iVar3);
      fVar12 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar12 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n","ERROR"
                   ,lVar5,"nvml_gpm.c",0x52b,uVar9);
    }
  }
  return iVar3;
}


// ===== 00174ef0 nvmlGpmMigSampleGet =====

int nvmlGpmMigSampleGet(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x66f,"nvmlGpmMigSampleGet",
                 "(nvmlDevice_t device, unsigned int gpuInstanceId, nvmlGpmSample_t gpmSample)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_0012d250(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x66f,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x66f,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001750c0 thunk_FUN_0012cbd0 =====

undefined8 thunk_FUN_0012cbd0(char *param_1,int *param_2)

{
  undefined1 auVar1 [16];
  int iVar2;
  undefined8 uVar3;
  undefined1 auStack_48 [8];
  ulong uStack_40;
  int iStack_38;
  
  if (param_2 == (int *)0x0) {
    return 2;
  }
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if (*param_1 != '\x01') {
    if (((*(int *)(param_1 + 0x14) == 0) || (*(int *)(param_1 + 0x1c) != 0)) ||
       (*(int *)(param_1 + 0x10) == 0)) {
      if (*(long *)(param_1 + 0x20) != 0) {
        return 2;
      }
    }
    else if (*(long *)(param_1 + 0x20) != 0) goto LAB_0012cc28;
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uStack_40;
    _auStack_48 = auVar1 << 0x40;
    iVar2 = FUN_001384c0(param_1,auStack_48);
    if (iVar2 == 0) {
      param_1 = *(char **)((long)auStack_48 + 0x98);
    }
  }
LAB_0012cc28:
  uVar3 = 0x19;
  if (*param_2 == 1) {
    iStack_38 = 0;
    stack0xffffffffffffffbc = SUB1612((undefined1  [16])0x0,4);
    auStack_48._0_4_ = 0x1000014;
    iVar2 = FUN_001730a0(auStack_48);
    if (((iVar2 == 3) || (((iVar2 == 0 && ((int)uStack_40 != 1)) && (iStack_38 != 1)))) &&
       ((uVar3 = FUN_0012bd20(param_1,auStack_48), (int)uVar3 == 0 && (auStack_48._0_4_ != 0)))) {
      param_2[1] = 1;
      return uVar3;
    }
    param_2[1] = 0;
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 001750d0 nvmlGpmQueryDeviceSupport =====

int nvmlGpmQueryDeviceSupport(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x674,"nvmlGpmQueryDeviceSupport",
                 "(nvmlDevice_t device, nvmlGpmSupport_t *gpmSupport)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_0012cbd0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x674,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x674,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001752b0 thunk_FUN_0012c590 =====

int thunk_FUN_0012c590(char *param_1)

{
  long *plVar1;
  int iVar2;
  int iVar3;
  undefined8 *__ptr;
  void *pvVar4;
  long lVar5;
  undefined8 uVar6;
  float fVar7;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if (((*param_1 == '\x01') ||
      ((((iVar2 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) &&
     ((iVar2 = FUN_0012c050(param_1), iVar2 == 0 || (iVar2 == 5)))) {
    plVar1 = *(long **)(param_1 + 0x70508);
    if ((int)plVar1[0x16] - 1U < 2) {
      iVar2 = 5;
      if (*plVar1 == 0) {
        __ptr = calloc(0x20,1);
        if (__ptr == (undefined8 *)0x0) {
          iVar2 = 0x14;
        }
        else {
          *__ptr = param_1;
          __ptr[1] = plVar1 + 2;
          if ((int)plVar1[0x16] == 2) {
            pvVar4 = calloc(8,0x1114);
            plVar1[3] = (long)pvVar4;
          }
          else {
            pvVar4 = calloc(8,0x1002);
            plVar1[3] = (long)pvVar4;
          }
          if (pvVar4 == (void *)0x0) {
            iVar2 = 0x14;
          }
          else {
            *(undefined1 *)(__ptr + 3) = 1;
            if ((int)plVar1[0x16] == 2) {
              iVar3 = FUN_00293340(__ptr + 2,FUN_00129450,__ptr);
            }
            else {
              iVar3 = FUN_00293340(__ptr + 2,FUN_00129660,__ptr);
            }
            if (iVar3 == 0) {
              if (plVar1[3] != 0) {
                *plVar1 = (long)__ptr;
                *(undefined4 *)(plVar1 + 1) = 2;
                return 0;
              }
              iVar2 = 5000;
              do {
                FUN_00292f00(1);
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
              if (1 < DAT_01216a78) {
                uVar6 = nvmlErrorString(10);
                fVar7 = (float)FUN_002917b0(&DAT_01216a60);
                lVar5 = syscall(0xba);
                FUN_002340f0((double)(fVar7 * DAT_00298548),
                             "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n","ERROR",lVar5,"nvml_gpm.c",
                             0x3a3,uVar6);
              }
              iVar2 = 10;
              if (__ptr[2] != 0) {
                FUN_002933f0(__ptr[2],0);
              }
            }
            else {
              iVar2 = 0x11;
              if (1 < DAT_01216a78) {
                fVar7 = (float)FUN_002917b0(&DAT_01216a60);
                lVar5 = syscall(0xba);
                FUN_002340f0((double)(fVar7 * DAT_00298548),
                             "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","ERROR",lVar5,"nvml_gpm.c",
                             0x395,iVar3);
              }
            }
          }
          free(__ptr);
        }
      }
    }
    else {
      iVar2 = 3;
    }
    if ((void *)plVar1[3] != (void *)0x0) {
      free((void *)plVar1[3]);
      plVar1[3] = 0;
      return iVar2;
    }
  }
  return iVar2;
}


// ===== 001752c0 FUN_001752c0 =====

int FUN_001752c0(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0xa66,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_0012c590(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xa66,iVar1,uVar2);
  return iVar1;
}


// ===== 001753f0 thunk_FUN_0012c890 =====

undefined8 thunk_FUN_0012c890(char *param_1)

{
  long *plVar1;
  long lVar2;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 != '\x01') &&
     ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
       (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) {
    return 2;
  }
  plVar1 = *(long **)(param_1 + 0x70508);
  if ((int)plVar1[1] != 2) {
    return 1;
  }
  lVar2 = *plVar1;
  *(undefined1 *)(lVar2 + 0x18) = 0;
  FUN_002933f0(*(undefined8 *)(lVar2 + 0x10),0);
  free((void *)plVar1[3]);
  plVar1[3] = 0;
  return 0;
}


// ===== 00175400 FUN_00175400 =====

int FUN_00175400(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0xa6b,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_0012c890(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xa6b,iVar1,uVar2);
  return iVar1;
}


// ===== 00175530 FUN_00175530 =====

undefined8 FUN_00175530(char *param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  long lVar2;
  char local_19;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if (((*param_1 != '\x01') &&
      ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
        (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) || (param_2 == 0)) {
    return 2;
  }
  lVar2 = *(long *)(param_1 + 0x256d8);
  local_19 = '\0';
  if (lVar2 != 0) {
    if ((*(long *)(lVar2 + 0x38) != 0) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x38) + 0x88),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
      (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,&local_19);
      if (local_19 != '\0') {
        return 3;
      }
      lVar2 = *(long *)(param_1 + 0x256d8);
    }
    if (((lVar2 != 0) && (*(long *)(lVar2 + 0x100) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x100) + 0x18),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001755db. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
      return uVar1;
    }
  }
  return 3;
}


// ===== 00175610 nvmlGpmQueryIfStreamingEnabled =====

int nvmlGpmQueryIfStreamingEnabled(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x679,"nvmlGpmQueryIfStreamingEnabled",
                 "(nvmlDevice_t device, unsigned int *state)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00175530(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x679,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x679,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001757f0 FUN_001757f0 =====

ulong FUN_001757f0(char *param_1,uint param_2)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined4 uVar3;
  ulong uVar4;
  long lVar5;
  float fVar6;
  
  if (((param_1 == (char *)0x0) ||
      ((*param_1 != '\x01' &&
       ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
         (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))))) || (1 < param_2))
  {
    uVar4 = 2;
  }
  else {
    if (*(int *)(param_1 + 0x70534) == 0) {
      do {
        iVar2 = FUN_00291820(param_1 + 0x70538,1,0);
      } while (iVar2 != 0);
      if (*(int *)(param_1 + 0x70534) == 0) {
        lVar5 = *(long *)(param_1 + 0x256d8);
        uVar3 = 3;
        if (((lVar5 != 0) && (*(long *)(lVar5 + 0x38) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar5 + 0x38) + 8),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar5,param_1,param_1 + 0x70530);
        }
        *(undefined4 *)(param_1 + 0x7053c) = uVar3;
        param_1[0x70534] = '\x01';
        param_1[0x70535] = '\0';
        param_1[0x70536] = '\0';
        param_1[0x70537] = '\0';
      }
      FUN_00291830(param_1 + 0x70538,0);
      uVar1 = *(uint *)(param_1 + 0x7053c);
    }
    else {
      uVar1 = *(uint *)(param_1 + 0x7053c);
    }
    if (uVar1 == 0) {
      if (((*(int *)(param_1 + 0x70530) != 2) && (lVar5 = *(long *)(param_1 + 0x256d8), lVar5 != 0))
         && ((*(long *)(lVar5 + 0x100) != 0 &&
             (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar5 + 0x100) + 0x10),
             UNRECOVERED_JUMPTABLE != (code *)0x0)))) {
                    /* WARNING: Could not recover jumptable at 0x001758ab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar4 = (*UNRECOVERED_JUMPTABLE)(lVar5,param_1,param_2);
        return uVar4;
      }
      return 3;
    }
    uVar4 = (ulong)uVar1;
    if (1 < DAT_01216a78) {
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar5,"api.c",0x395a,"tsapiGpmSetStreamingEnabled",0x395a,uVar4);
    }
  }
  return uVar4;
}


// ===== 001759f0 nvmlGpmSetStreamingEnabled =====

int nvmlGpmSetStreamingEnabled(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %u)\n","DEBUG",lVar3,
                 "entry_points.h",0x67e,"nvmlGpmSetStreamingEnabled",
                 "(nvmlDevice_t device, unsigned int state)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001757f0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x67e,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x67e,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00175bd0 FUN_00175bd0 =====

undefined8 FUN_00175bd0(char *param_1,undefined4 *param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 local_1c;
  
  if ((*param_1 == '\x01') || (*(long *)(param_1 + 0x20) == 0)) {
    *param_2 = 1;
    return 0;
  }
  uVar4 = 2;
  if (*(int *)(param_1 + 0x14) != 0) {
    if (((*(int *)(param_1 + 0x1c) != 0) || (*(int *)(param_1 + 0x10) == 0)) ||
       (*(long *)(param_1 + 0x20) == 0)) {
      return 2;
    }
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 == 0) || (*(long *)(lVar1 + 0x20) == 0)) ||
       (pcVar2 = *(code **)(*(long *)(lVar1 + 0x20) + 0x88), pcVar2 == (code *)0x0)) {
LAB_00175c90:
      *param_2 = 0;
      return 0;
    }
    iVar3 = (*pcVar2)(lVar1,param_1,&local_1c);
    if (iVar3 == 0) {
      uVar4 = 0;
      *param_2 = local_1c;
    }
    else {
      if (iVar3 != 0xf) goto LAB_00175c90;
      uVar4 = 0xf;
    }
  }
  return uVar4;
}


// ===== 00175cc0 FUN_00175cc0 =====

ulong FUN_00175cc0(long param_1,undefined4 param_2,long param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c;
  
  uVar1 = FUN_00175bd0(param_1,&local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x3f2);
        }
      }
      else if (param_3 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x170) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x170) + 0x20),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00175d63. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2,param_3);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00175e00 nvmlDeviceGetClockInfo =====

int nvmlDeviceGetClockInfo(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d, %p)\n","DEBUG",lVar3,
                 "entry_points.h",9,"nvmlDeviceGetClockInfo",
                 "(nvmlDevice_t device, nvmlClockType_t type, unsigned int* clock)",param_1,param_2,
                 param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00175cc0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",9,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",9,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00175fd0 FUN_00175fd0 =====

ulong FUN_00175fd0(long param_1,uint param_2,long param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c;
  
  uVar1 = FUN_00175bd0(param_1,&local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x401);
        }
      }
      else if ((param_3 == 0) || (3 < param_2)) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x170) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x170) + 0x40),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0017607d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2,param_3);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00176120 nvmlDeviceGetMaxClockInfo =====

int nvmlDeviceGetMaxClockInfo(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0xd,"nvmlDeviceGetMaxClockInfo",
                 "(nvmlDevice_t device, nvmlClockType_t type, unsigned int* clock)",param_1,param_2,
                 param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00175fd0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xd,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xd,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001762f0 FUN_001762f0 =====

ulong FUN_001762f0(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x5e5);
        }
      }
      else if (param_2 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0xa0) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0xa0) + 8),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00176386. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00176420 nvmlDeviceGetDisplayMode =====

int nvmlDeviceGetDisplayMode(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x51,"nvmlDeviceGetDisplayMode",
                 "(nvmlDevice_t device, nvmlEnableState_t *mode)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001762f0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x51,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x51,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00176600 FUN_00176600 =====

ulong FUN_00176600(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x5f4);
        }
      }
      else if (param_2 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(undefined8 **)(lVar2 + 0xa0) != (undefined8 *)0x0)) &&
           (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar2 + 0xa0),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00176695. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00176730 nvmlDeviceGetDisplayActive =====

int nvmlDeviceGetDisplayActive(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x213,"nvmlDeviceGetDisplayActive",
                 "(nvmlDevice_t device, nvmlEnableState_t *isActive)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00176600(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x213,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x213,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00176910 FUN_00176910 =====

ulong FUN_00176910(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x680);
        }
      }
      else if (param_2 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(undefined8 **)(lVar2 + 0x78) != (undefined8 *)0x0)) &&
           (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar2 + 0x78),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001769a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00176a40 nvmlDeviceGetBoardId =====

int nvmlDeviceGetBoardId(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x67,"nvmlDeviceGetBoardId",
                 "(nvmlDevice_t device, unsigned int *boardId)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00176910(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x67,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x67,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00176c20 FUN_00176c20 =====

ulong FUN_00176c20(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x68d);
        }
      }
      else if (param_2 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x78) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x78) + 8),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00176cb3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00176d50 nvmlDeviceGetMultiGpuBoard =====

int nvmlDeviceGetMultiGpuBoard(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x6b,"nvmlDeviceGetMultiGpuBoard",
                 "(nvmlDevice_t device, unsigned int *multiGpuBool)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00176c20(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x6b,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x6b,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00176f30 FUN_00176f30 =====

ulong FUN_00176f30(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c;
  
  uVar1 = FUN_00175bd0(param_1,&local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x7b4);
        }
      }
      else if (param_2 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 == 0) || (*(long *)(lVar2 + 0x140) == 0)) ||
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x140) + 8),
           UNRECOVERED_JUMPTABLE == (code *)0x0)) {
          uVar3 = 3;
        }
        else {
          uVar1 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,&local_2c);
          uVar3 = (ulong)uVar1;
          if (uVar1 == 0) {
            if (((local_2c == 1) && (lVar2 = *(long *)(param_1 + 0x256d8), lVar2 != 0)) &&
               ((*(long *)(lVar2 + 0x140) != 0 &&
                (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x140) + 0x28),
                UNRECOVERED_JUMPTABLE != (code *)0x0)))) {
                    /* WARNING: Could not recover jumptable at 0x0017701e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
              return uVar3;
            }
            return 3;
          }
        }
        if (1 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,"api.c",0x7bc,
                       "tsapiDeviceGetTotalAggregateEccErrorsPerUnit",0x7bc,uVar3);
        }
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00177140 FUN_00177140 =====

int FUN_00177140(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x9b5,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00176f30(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x9b5,iVar1,uVar2);
  return iVar1;
}


// ===== 00177280 FUN_00177280 =====

int FUN_00177280(long param_1,uint param_2,uint param_3,undefined8 *param_4)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  float fVar5;
  int local_6c;
  int local_68;
  undefined1 auStack_64 [12];
  undefined1 local_58 [16];
  undefined8 local_48;
  
  iVar2 = FUN_00175bd0(param_1,&local_68);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_68 == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar4,"api.c",0x7d1);
        }
      }
      else if ((param_3 < 2 && param_4 != (undefined8 *)0x0) && (param_2 < 2)) {
        lVar4 = *(long *)(param_1 + 0x256d8);
        if (((lVar4 == 0) || (*(long *)(lVar4 + 0x140) == 0)) ||
           (pcVar1 = *(code **)(*(long *)(lVar4 + 0x140) + 8), pcVar1 == (code *)0x0)) {
          iVar2 = 3;
        }
        else {
          iVar2 = (*pcVar1)(lVar4,param_1,&local_6c);
          if (iVar2 == 0) {
            if (local_6c != 1) {
              return 3;
            }
            *param_4 = 0;
            local_48 = 0;
            uVar3 = -(uint)(param_3 == 0) & 0xfffffffe;
            local_58 = (undefined1  [16])0x0;
            auStack_64 = SUB1612((undefined1  [16])0x0,4);
            if (param_2 == 0) {
              local_68 = uVar3 + 5;
            }
            else {
              local_68 = uVar3 + 6;
            }
            iVar2 = FUN_00159f90(param_1,1,&local_68);
            if (iVar2 != 0) {
              return iVar2;
            }
            if (local_58._12_4_ != 0) {
              return local_58._12_4_;
            }
            *param_4 = local_48;
            return 0;
          }
        }
        if (1 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,"api.c",0x7e1,
                       "tsapiDeviceGetTotalEccErrors",0x7e1,iVar2);
        }
      }
      else {
        iVar2 = 2;
      }
    }
    else {
      iVar2 = 999;
    }
  }
  return iVar2;
}


// ===== 001774e0 nvmlDeviceGetTotalEccErrors =====

int nvmlDeviceGetTotalEccErrors
              (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d, %d, %p)\n","DEBUG",lVar3
                 ,"entry_points.h",0x74,"nvmlDeviceGetTotalEccErrors",
                 "(nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, unsigned long long *eccCounts)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00177280(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x74,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x74,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001776d0 FUN_001776d0 =====

ulong FUN_001776d0(long param_1,undefined4 param_2,undefined4 param_3,long param_4)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_3c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_3c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_3c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x80d);
        }
      }
      else if (param_4 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x140) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x140) + 0x78),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00177777. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2,param_3,param_4);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00177820 FUN_00177820 =====

int FUN_00177820(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d, %d, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x771,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001776d0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x771,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00177970 FUN_00177970 =====

ulong FUN_00177970(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x81d);
        }
      }
      else if (param_2 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x140) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x140) + 0x80),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00177a09. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00177aa0 FUN_00177aa0 =====

int FUN_00177aa0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x77c,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00177970(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x77c,iVar1,uVar2);
  return iVar1;
}


// ===== 00177be0 FUN_00177be0 =====

ulong FUN_00177be0(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x82b);
        }
      }
      else if (param_2 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x140) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x140) + 0x90),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00177c79. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00177d10 FUN_00177d10 =====

int FUN_00177d10(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x780,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00177be0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x780,iVar1,uVar2);
  return iVar1;
}


// ===== 00177e50 FUN_00177e50 =====

ulong FUN_00177e50(long param_1,long param_2,undefined4 param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c;
  
  uVar1 = FUN_00175bd0(param_1,&local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x83a);
        }
      }
      else if (param_2 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x140) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x140) + 0x88),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00177ef6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2,param_3);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00177fa0 FUN_00177fa0 =====

int FUN_00177fa0(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p, %d)\n",
                 "DEBUG",lVar3,"entry_points.h",0x784,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00177e50(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x784,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001780e0 FUN_001780e0 =====

int FUN_001780e0(long param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  int local_2c;
  
  iVar2 = FUN_00175bd0(param_1,&local_2c);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_2c == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar4,"api.c",0x86d);
        }
      }
      else {
        iVar3 = FUN_00236dd0();
        iVar2 = 4;
        if (iVar3 != 0) {
          lVar4 = *(long *)(param_1 + 0x256d8);
          if (((lVar4 == 0) || (*(long *)(lVar4 + 0x140) == 0)) ||
             (pcVar1 = *(code **)(*(long *)(lVar4 + 0x140) + 8), pcVar1 == (code *)0x0)) {
            iVar2 = 3;
          }
          else {
            iVar2 = (*pcVar1)(lVar4,param_1,&local_2c);
            if (iVar2 == 0) {
              if (local_2c != 1) {
                return 3;
              }
              lVar4 = *(long *)(param_1 + 0x256d8);
              if (((lVar4 != 0) && (*(long *)(lVar4 + 0x140) != 0)) &&
                 (pcVar1 = *(code **)(*(long *)(lVar4 + 0x140) + 0x68), pcVar1 != (code *)0x0)) {
                iVar2 = (*pcVar1)(lVar4,param_1,param_2);
                return iVar2;
              }
              return 3;
            }
          }
          if (1 < DAT_01216a78) {
            fVar5 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            FUN_002340f0((double)(fVar5 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,"api.c",0x874
                         ,"tsapiDeviceClearEccErrorCounts",0x874,iVar2);
          }
        }
      }
    }
    else {
      iVar2 = 999;
    }
  }
  return iVar2;
}


// ===== 001782e0 nvmlDeviceClearEccErrorCounts =====

int nvmlDeviceClearEccErrorCounts(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x7d,"nvmlDeviceClearEccErrorCounts",
                 "(nvmlDevice_t device, nvmlEccCounterType_t counterType)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001780e0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x7d,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x7d,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001784c0 FUN_001784c0 =====

ulong FUN_001784c0(char *param_1,int *param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  undefined4 uVar2;
  ulong uVar3;
  long lVar4;
  float fVar5;
  int local_2c [3];
  
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    if (*param_2 != 1) {
      return 0x19;
    }
    if (((uint)param_2[1] < 2) && ((uint)param_2[2] < 0x29)) {
      iVar1 = FUN_00175bd0(param_1,local_2c);
      if (iVar1 == 2) {
        return 2;
      }
      if (iVar1 == 0xf) {
        return 0xf;
      }
      if (iVar1 != 0) {
        return 999;
      }
      if (local_2c[0] != 0) {
        if (*(int *)(param_1 + 0x70534) == 0) {
          do {
            iVar1 = FUN_00291820(param_1 + 0x70538,1,0);
          } while (iVar1 != 0);
          if (*(int *)(param_1 + 0x70534) == 0) {
            lVar4 = *(long *)(param_1 + 0x256d8);
            uVar2 = 3;
            if (((lVar4 != 0) && (*(long *)(lVar4 + 0x38) != 0)) &&
               (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar4 + 0x38) + 8),
               UNRECOVERED_JUMPTABLE != (code *)0x0)) {
              uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar4,param_1,param_1 + 0x70530);
            }
            *(undefined4 *)(param_1 + 0x7053c) = uVar2;
            param_1[0x70534] = '\x01';
            param_1[0x70535] = '\0';
            param_1[0x70536] = '\0';
            param_1[0x70537] = '\0';
          }
          FUN_00291830(param_1 + 0x70538,0);
        }
        uVar3 = (ulong)*(uint *)(param_1 + 0x7053c);
        if (*(uint *)(param_1 + 0x7053c) == 0) {
          if ((((*(int *)(param_1 + 0x70530) != 2) &&
               (lVar4 = *(long *)(param_1 + 0x256d8), lVar4 != 0)) &&
              (*(long *)(lVar4 + 0x140) != 0)) &&
             (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar4 + 0x140) + 0xc0),
             UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00178678. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar4,param_1,param_2);
            return uVar3;
          }
          return 3;
        }
        if (DAT_01216a78 < 2) {
          return uVar3;
        }
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                     "ERROR",lVar4,"api.c",0x895,"tsapiDeviceInjectEccError",0x895,uVar3);
        return uVar3;
      }
      if (DAT_01216a78 < 4) {
        return 3;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar4,"api.c",0x88f);
      return 3;
    }
  }
  return 2;
}


// ===== 00178780 FUN_00178780 =====

int FUN_00178780(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x9a1,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001784c0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x9a1,iVar1,uVar2);
  return iVar1;
}


// ===== 001788c0 FUN_001788c0 =====

int FUN_001788c0(char *param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  float fVar5;
  int local_2c [3];
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((iVar2 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (param_2 == (undefined4 *)0x0) {
      return 2;
    }
    iVar2 = FUN_00175bd0(param_1,local_2c);
    if ((iVar2 != 2) && (iVar2 != 0xf)) {
      if (iVar2 == 0) {
        if (local_2c[0] == 0) {
          iVar2 = 3;
          if (3 < DAT_01216a78) {
            fVar5 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                         &DAT_002983c2,lVar4,"api.c",0x9a3);
          }
        }
        else {
          if (*(int *)(param_1 + 0x70534) == 0) {
            do {
              iVar2 = FUN_00291820(param_1 + 0x70538,1,0);
            } while (iVar2 != 0);
            if (*(int *)(param_1 + 0x70534) == 0) {
              lVar4 = *(long *)(param_1 + 0x256d8);
              uVar3 = 3;
              if (((lVar4 != 0) && (*(long *)(lVar4 + 0x38) != 0)) &&
                 (pcVar1 = *(code **)(*(long *)(lVar4 + 0x38) + 8), pcVar1 != (code *)0x0)) {
                uVar3 = (*pcVar1)(lVar4,param_1,param_1 + 0x70530);
              }
              *(undefined4 *)(param_1 + 0x7053c) = uVar3;
              param_1[0x70534] = '\x01';
              param_1[0x70535] = '\0';
              param_1[0x70536] = '\0';
              param_1[0x70537] = '\0';
            }
            FUN_00291830(param_1 + 0x70538,0);
          }
          iVar2 = *(int *)(param_1 + 0x7053c);
          if (iVar2 == 0) {
            *param_2 = *(undefined4 *)(param_1 + 0x70530);
          }
          else if (1 < DAT_01216a78) {
            fVar5 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            FUN_002340f0((double)(fVar5 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,"api.c",0x9a9
                         ,"tsapiDeviceGetVirtualizationMode",0x9a9,iVar2);
          }
        }
      }
      else {
        iVar2 = 999;
      }
    }
  }
  return iVar2;
}


// ===== 00178b00 nvmlDeviceGetVirtualizationMode =====

int nvmlDeviceGetVirtualizationMode(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x313,"nvmlDeviceGetVirtualizationMode",
                 "(nvmlDevice_t device, nvmlGpuVirtualizationMode_t *pVirtualMode)",param_1,param_2)
    ;
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001788c0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x313,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x313,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00178ce0 FUN_00178ce0 =====

ulong FUN_00178ce0(char *param_1,undefined4 param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  ulong uVar2;
  long lVar3;
  float fVar4;
  int local_2c [3];
  
  if ((param_1 == (char *)0x0) ||
     ((*param_1 != '\x01' &&
      ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
        (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))))) {
    uVar2 = 2;
  }
  else {
    uVar1 = FUN_00175bd0(param_1,local_2c);
    uVar2 = (ulong)uVar1;
    if ((uVar1 != 2) && (uVar1 != 0xf)) {
      if (uVar1 != 0) {
        return 999;
      }
      if (local_2c[0] == 0) {
        uVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar3,"api.c",0x9b7);
        }
      }
      else {
        lVar3 = *(long *)(param_1 + 0x256d8);
        if (((lVar3 != 0) && (*(long *)(lVar3 + 0x38) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar3 + 0x38) + 0x68),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00178d9f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar3,param_1,param_2);
          return uVar2;
        }
        uVar2 = 3;
      }
    }
  }
  return uVar2;
}


// ===== 00178e20 nvmlDeviceSetVirtualizationMode =====

int nvmlDeviceSetVirtualizationMode(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x318,"nvmlDeviceSetVirtualizationMode",
                 "(nvmlDevice_t device, nvmlGpuVirtualizationMode_t virtualMode)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00178ce0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x318,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x318,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00179000 FUN_00179000 =====

ulong FUN_00179000(long param_1,undefined8 param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  uint local_2c;
  
  uVar1 = FUN_00175bd0(param_1,&local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x9c1);
        }
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        local_2c = local_2c & 0xffffff00;
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x38) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x38) + 0x80),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
          (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,&local_2c);
          if ((((char)local_2c != '\0') && (lVar2 = *(long *)(param_1 + 0x256d8), lVar2 != 0)) &&
             ((*(long *)(lVar2 + 0x38) != 0 &&
              (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x38) + 0x70),
              UNRECOVERED_JUMPTABLE != (code *)0x0)))) {
                    /* WARNING: Could not recover jumptable at 0x0017912c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
            return uVar3;
          }
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00179140 nvmlDeviceSetVgpuHeterogeneousMode =====

int nvmlDeviceSetVgpuHeterogeneousMode(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0xade,"nvmlDeviceSetVgpuHeterogeneousMode",
                 "(nvmlDevice_t device, const nvmlVgpuHeterogeneousMode_t *pHeterogeneousMode)",
                 param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00179000(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xade,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xade,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00179320 FUN_00179320 =====

ulong FUN_00179320(long param_1,undefined8 param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  uint local_2c;
  
  uVar1 = FUN_00175bd0(param_1,&local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x9d0);
        }
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        local_2c = local_2c & 0xffffff00;
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x38) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x38) + 0x80),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
          (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,&local_2c);
          if ((((char)local_2c != '\0') && (lVar2 = *(long *)(param_1 + 0x256d8), lVar2 != 0)) &&
             ((*(long *)(lVar2 + 0x38) != 0 &&
              (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x38) + 0x78),
              UNRECOVERED_JUMPTABLE != (code *)0x0)))) {
                    /* WARNING: Could not recover jumptable at 0x0017944c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
            return uVar3;
          }
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00179460 nvmlDeviceGetVgpuHeterogeneousMode =====

int nvmlDeviceGetVgpuHeterogeneousMode(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0xae3,"nvmlDeviceGetVgpuHeterogeneousMode",
                 "(nvmlDevice_t device, nvmlVgpuHeterogeneousMode_t *pHeterogeneousMode)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00179320(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xae3,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xae3,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00179640 FUN_00179640 =====

int FUN_00179640(long param_1,int param_2,long param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  uint local_44;
  undefined8 local_40 [2];
  
  local_40[0] = 0;
  iVar2 = FUN_00175bd0(param_1,&local_44);
  if (iVar2 == 2) {
    return 2;
  }
  if (iVar2 == 0xf) {
    return 0xf;
  }
  if (iVar2 != 0) {
    return 999;
  }
  if (local_44 == 0) {
    if (3 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar3,"api.c",0x9f9);
      return 3;
    }
    return 3;
  }
  lVar3 = *(long *)(param_1 + 0x256d8);
  local_44 = local_44 & 0xffffff00;
  if (((lVar3 == 0) || (*(long *)(lVar3 + 0x38) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(lVar3 + 0x38) + 0x80), pcVar1 == (code *)0x0)) {
    return 3;
  }
  (*pcVar1)(lVar3,param_1,&local_44);
  if ((char)local_44 == '\0') {
    return 3;
  }
  if (((param_2 == 0) || (param_3 == 0)) || (*(long *)(param_3 + 0x10) == 0)) {
    return 2;
  }
  if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x28) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0xb8), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(DAT_012164a0,param_2,local_40);
    if (iVar2 == 0) {
      iVar2 = FUN_00138f40(param_2,local_40[0]);
      if (iVar2 == 0) {
        lVar3 = *(long *)(param_1 + 0x256d8);
        if (lVar3 == 0) {
          return 3;
        }
        if (*(long *)(lVar3 + 0x28) == 0) {
          return 3;
        }
        pcVar1 = *(code **)(*(long *)(lVar3 + 0x28) + 0x60);
        if (pcVar1 == (code *)0x0) {
          return 3;
        }
        iVar2 = (*pcVar1)(lVar3,param_1,local_40[0],param_3);
        return iVar2;
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0xa07;
      uVar4 = 0xa07;
      goto LAB_0017986b;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  fVar5 = fVar5 * DAT_00298548;
  uVar6 = 0xa05;
  uVar4 = 0xa05;
LAB_0017986b:
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,"api.c",
               uVar4,"tsapiDeviceGetVgpuTypeSupportedPlacements",uVar6,iVar2);
  return iVar2;
}


// ===== 00179910 nvmlDeviceGetVgpuTypeSupportedPlacements =====

int nvmlDeviceGetVgpuTypeSupportedPlacements
              (undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0xaed,"nvmlDeviceGetVgpuTypeSupportedPlacements",
                 "(nvmlDevice_t device, nvmlVgpuTypeId_t vgpuTypeId, nvmlVgpuPlacementList_t *pPlacements)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00179640(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xaed,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xaed,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00179ae0 FUN_00179ae0 =====

ulong FUN_00179ae0(long param_1,undefined4 param_2,undefined8 param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  uint local_3c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_3c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_3c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0xa11);
        }
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        local_3c[0] = local_3c[0] & 0xffffff00;
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x38) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x38) + 0x80),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
          (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,local_3c);
          if ((((char)local_3c[0] != '\0') && (lVar2 = *(long *)(param_1 + 0x256d8), lVar2 != 0)) &&
             ((*(long *)(lVar2 + 0x28) != 0 &&
              (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x28) + 0xa8),
              UNRECOVERED_JUMPTABLE != (code *)0x0)))) {
                    /* WARNING: Could not recover jumptable at 0x00179c13. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2,param_3);
            return uVar3;
          }
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00179c30 nvmlDeviceGetVgpuTypeCreatablePlacements =====

int nvmlDeviceGetVgpuTypeCreatablePlacements
              (undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0xaf2,"nvmlDeviceGetVgpuTypeCreatablePlacements",
                 "(nvmlDevice_t device, nvmlVgpuTypeId_t vgpuTypeId, nvmlVgpuPlacementList_t *pPlacements)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00179ae0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xaf2,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xaf2,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00179e00 FUN_00179e00 =====

int FUN_00179e00(long param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  float fVar5;
  int local_2c;
  
  iVar2 = FUN_00175bd0(param_1,&local_2c);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_2c == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar4,"api.c",0xafc);
        }
      }
      else if (param_2 == (undefined4 *)0x0) {
        iVar2 = 2;
      }
      else {
        iVar2 = FUN_0014b580(param_1,&local_2c);
        if ((iVar2 == 0) && (iVar2 = 3, local_2c == 2)) {
          if (*(int *)(param_1 + 0x628) == 0) {
            do {
              iVar2 = FUN_00291820(param_1 + 0x62c,1,0);
            } while (iVar2 != 0);
            if (*(int *)(param_1 + 0x628) == 0) {
              lVar4 = *(long *)(param_1 + 0x256d8);
              uVar3 = 3;
              if (((lVar4 != 0) && (*(long *)(lVar4 + 0x48) != 0)) &&
                 (pcVar1 = *(code **)(*(long *)(lVar4 + 0x48) + 0x18), pcVar1 != (code *)0x0)) {
                uVar3 = (*pcVar1)(lVar4,param_1,param_1 + 0x624);
              }
              *(undefined4 *)(param_1 + 0x630) = uVar3;
              *(undefined4 *)(param_1 + 0x628) = 1;
            }
            FUN_00291830(param_1 + 0x62c,0);
          }
          iVar2 = *(int *)(param_1 + 0x630);
          if (iVar2 == 0) {
            *param_2 = *(undefined4 *)(param_1 + 0x624);
          }
        }
      }
    }
    else {
      iVar2 = 999;
    }
  }
  return iVar2;
}


// ===== 00179fb0 FUN_00179fb0 =====

int FUN_00179fb0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa80,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00179e00(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xa80,iVar1,uVar2);
  return iVar1;
}


// ===== 0017a0f0 FUN_0017a0f0 =====

int FUN_0017a0f0(long param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  float fVar5;
  int local_2c;
  
  iVar2 = FUN_00175bd0(param_1,&local_2c);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_2c == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar4,"api.c",0xc30);
        }
      }
      else if (param_2 == (undefined4 *)0x0) {
        iVar2 = 2;
      }
      else {
        iVar2 = FUN_0014b580(param_1,&local_2c);
        if ((iVar2 == 0) && (iVar2 = 3, local_2c == 2)) {
          if (*(int *)(param_1 + 0x608) == 0) {
            do {
              iVar2 = FUN_00291820(param_1 + 0x60c,1,0);
            } while (iVar2 != 0);
            if (*(int *)(param_1 + 0x608) == 0) {
              lVar4 = *(long *)(param_1 + 0x256d8);
              uVar3 = 3;
              if (((lVar4 != 0) && (*(long *)(lVar4 + 0x48) != 0)) &&
                 (pcVar1 = *(code **)(*(long *)(lVar4 + 0x48) + 0x10), pcVar1 != (code *)0x0)) {
                uVar3 = (*pcVar1)(lVar4,param_1,param_1 + 0x604);
              }
              *(undefined4 *)(param_1 + 0x610) = uVar3;
              *(undefined4 *)(param_1 + 0x608) = 1;
            }
            FUN_00291830(param_1 + 0x60c,0);
          }
          iVar2 = *(int *)(param_1 + 0x610);
          if (iVar2 == 0) {
            *param_2 = *(undefined4 *)(param_1 + 0x604);
          }
        }
      }
    }
    else {
      iVar2 = 999;
    }
  }
  return iVar2;
}


// ===== 0017a2a0 nvmlDeviceGetMaxPcieLinkGeneration =====

int nvmlDeviceGetMaxPcieLinkGeneration(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x14f,"nvmlDeviceGetMaxPcieLinkGeneration",
                 "(nvmlDevice_t device, unsigned int *maxLinkGen)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017a0f0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x14f,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x14f,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0017a480 FUN_0017a480 =====

int FUN_0017a480(long param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  float fVar5;
  int local_2c;
  
  iVar2 = FUN_00175bd0(param_1,&local_2c);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_2c == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar4,"api.c",0xc54);
        }
      }
      else if (param_2 == (undefined4 *)0x0) {
        iVar2 = 2;
      }
      else {
        iVar2 = FUN_0014b580(param_1,&local_2c);
        if ((iVar2 == 0) && (iVar2 = 3, local_2c == 2)) {
          if (*(int *)(param_1 + 0x618) == 0) {
            do {
              iVar2 = FUN_00291820(param_1 + 0x61c,1,0);
            } while (iVar2 != 0);
            if (*(int *)(param_1 + 0x618) == 0) {
              lVar4 = *(long *)(param_1 + 0x256d8);
              uVar3 = 3;
              if (((lVar4 != 0) && (*(long *)(lVar4 + 0x48) != 0)) &&
                 (pcVar1 = *(code **)(*(long *)(lVar4 + 0x48) + 0x20), pcVar1 != (code *)0x0)) {
                uVar3 = (*pcVar1)(lVar4,param_1,param_1 + 0x614);
              }
              *(undefined4 *)(param_1 + 0x620) = uVar3;
              *(undefined4 *)(param_1 + 0x618) = 1;
            }
            FUN_00291830(param_1 + 0x61c,0);
          }
          iVar2 = *(int *)(param_1 + 0x620);
          if (iVar2 == 0) {
            *param_2 = *(undefined4 *)(param_1 + 0x614);
          }
        }
      }
    }
    else {
      iVar2 = 999;
    }
  }
  return iVar2;
}


// ===== 0017a630 nvmlDeviceGetGpuMaxPcieLinkGeneration =====

int nvmlDeviceGetGpuMaxPcieLinkGeneration(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x153,"nvmlDeviceGetGpuMaxPcieLinkGeneration",
                 "(nvmlDevice_t device, unsigned int *maxLinkGen)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017a480(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x153,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x153,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0017a810 FUN_0017a810 =====

int FUN_0017a810(long param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  float fVar5;
  int local_2c;
  
  iVar2 = FUN_00175bd0(param_1,&local_2c);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_2c == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar4,"api.c",0xc79);
        }
      }
      else if (param_2 == (undefined4 *)0x0) {
        iVar2 = 2;
      }
      else {
        iVar2 = FUN_0014b580(param_1,&local_2c);
        if ((iVar2 == 0) && (iVar2 = 3, local_2c == 2)) {
          if (*(int *)(param_1 + 0x638) == 0) {
            do {
              iVar2 = FUN_00291820(param_1 + 0x63c,1,0);
            } while (iVar2 != 0);
            if (*(int *)(param_1 + 0x638) == 0) {
              lVar4 = *(long *)(param_1 + 0x256d8);
              uVar3 = 3;
              if (((lVar4 != 0) && (*(long *)(lVar4 + 0x48) != 0)) &&
                 (pcVar1 = *(code **)(*(long *)(lVar4 + 0x48) + 0x28), pcVar1 != (code *)0x0)) {
                uVar3 = (*pcVar1)(lVar4,param_1,param_1 + 0x634);
              }
              *(undefined4 *)(param_1 + 0x640) = uVar3;
              *(undefined4 *)(param_1 + 0x638) = 1;
            }
            FUN_00291830(param_1 + 0x63c,0);
          }
          iVar2 = *(int *)(param_1 + 0x640);
          if (iVar2 == 0) {
            *param_2 = *(undefined4 *)(param_1 + 0x634);
          }
        }
      }
    }
    else {
      iVar2 = 999;
    }
  }
  return iVar2;
}


// ===== 0017a9c0 nvmlDeviceGetMaxPcieLinkWidth =====

int nvmlDeviceGetMaxPcieLinkWidth(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x157,"nvmlDeviceGetMaxPcieLinkWidth",
                 "(nvmlDevice_t device, unsigned int *maxLinkWidth)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017a810(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x157,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x157,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0017aba0 FUN_0017aba0 =====

int FUN_0017aba0(long param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  int local_2c;
  
  iVar2 = FUN_00175bd0(param_1,&local_2c);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_2c == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar3,"api.c",0xc9d);
        }
      }
      else if (param_2 == 0) {
        iVar2 = 2;
      }
      else {
        iVar2 = FUN_0014b580(param_1,&local_2c);
        if ((((iVar2 == 0) && (iVar2 = 3, local_2c == 2)) &&
            (lVar3 = *(long *)(param_1 + 0x256d8), lVar3 != 0)) && (*(long *)(lVar3 + 0x48) != 0)) {
          pcVar1 = *(code **)(*(long *)(lVar3 + 0x48) + 0x30);
          if (pcVar1 == (code *)0x0) {
            iVar2 = 3;
          }
          else {
            iVar2 = (*pcVar1)(lVar3,param_1,param_2);
          }
        }
      }
    }
    else {
      iVar2 = 999;
    }
  }
  return iVar2;
}


// ===== 0017ace0 nvmlDeviceGetCurrPcieLinkGeneration =====

int nvmlDeviceGetCurrPcieLinkGeneration(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x15b,"nvmlDeviceGetCurrPcieLinkGeneration",
                 "(nvmlDevice_t device, unsigned int *currLinkGen)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017aba0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x15b,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x15b,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0017aec0 FUN_0017aec0 =====

int FUN_0017aec0(long param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  int local_2c;
  
  iVar2 = FUN_00175bd0(param_1,&local_2c);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_2c == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar3,"api.c",0xcb8);
        }
      }
      else if (param_2 == 0) {
        iVar2 = 2;
      }
      else {
        iVar2 = FUN_0014b580(param_1,&local_2c);
        if ((((iVar2 == 0) && (iVar2 = 3, local_2c == 2)) &&
            (lVar3 = *(long *)(param_1 + 0x256d8), lVar3 != 0)) && (*(long *)(lVar3 + 0x48) != 0)) {
          pcVar1 = *(code **)(*(long *)(lVar3 + 0x48) + 0x38);
          if (pcVar1 == (code *)0x0) {
            iVar2 = 3;
          }
          else {
            iVar2 = (*pcVar1)(lVar3,param_1,param_2);
          }
        }
      }
    }
    else {
      iVar2 = 999;
    }
  }
  return iVar2;
}


// ===== 0017b000 nvmlDeviceGetCurrPcieLinkWidth =====

int nvmlDeviceGetCurrPcieLinkWidth(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x15f,"nvmlDeviceGetCurrPcieLinkWidth",
                 "(nvmlDevice_t device, unsigned int *currLinkWidth)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017aec0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x15f,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x15f,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0017b1e0 FUN_0017b1e0 =====

ulong FUN_0017b1e0(long param_1,undefined4 param_2,long param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c;
  
  uVar1 = FUN_00175bd0(param_1,&local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0xddf);
        }
      }
      else if (param_3 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x170) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x170) + 0x70),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0017b283. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2,param_3);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 0017b320 FUN_0017b320 =====

int FUN_0017b320(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x7f2,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017b1e0(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x7f2,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0017b460 FUN_0017b460 =====

ulong FUN_0017b460(long param_1,undefined4 param_2,undefined4 param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  float fVar5;
  int local_2c;
  
  uVar1 = FUN_00175bd0(param_1,&local_2c);
  uVar4 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c == 0) {
        uVar4 = 3;
        if (3 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar3,"api.c",0xdef);
        }
      }
      else {
        iVar2 = FUN_00236dd0();
        if (iVar2 == 0) {
          uVar4 = 4;
        }
        else {
          lVar3 = *(long *)(param_1 + 0x256d8);
          if (((lVar3 != 0) && (*(long *)(lVar3 + 0x170) != 0)) &&
             (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar3 + 0x170) + 0x68),
             UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0017b568. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar4 = (*UNRECOVERED_JUMPTABLE)(lVar3,param_1,param_2,param_3);
            return uVar4;
          }
          uVar4 = 3;
        }
      }
    }
    else {
      uVar4 = 999;
    }
  }
  return uVar4;
}


// ===== 0017b590 FUN_0017b590 =====

int FUN_0017b590(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d, %d)\n",
                 "DEBUG",lVar3,"entry_points.h",0x7ee,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017b460(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x7ee,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0017b6d0 FUN_0017b6d0 =====

ulong FUN_0017b6d0(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0xfac);
        }
      }
      else if (param_2 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x160) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x160) + 8),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0017b76b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,0,param_2,0);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 0017b800 nvmlDeviceGetPowerUsage =====

int nvmlDeviceGetPowerUsage(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0xe2,"nvmlDeviceGetPowerUsage",
                 "(nvmlDevice_t device, unsigned int *power)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017b6d0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xe2,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xe2,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0017b9e0 FUN_0017b9e0 =====

ulong FUN_0017b9e0(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c [3];
  
  if (param_2 == 0) {
    return 2;
  }
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0xffb);
        }
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(undefined8 **)(lVar2 + 0x160) != (undefined8 *)0x0)) &&
           (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar2 + 0x160),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0017ba76. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,0,param_2);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 0017bb20 nvmlDeviceGetTotalEnergyConsumption =====

int nvmlDeviceGetTotalEnergyConsumption(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x102,"nvmlDeviceGetTotalEnergyConsumption",
                 "(nvmlDevice_t device, unsigned long long *energy)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017b9e0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x102,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x102,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0017bd00 FUN_0017bd00 =====

ulong FUN_0017bd00(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x1006);
        }
      }
      else if (param_2 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x160) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x160) + 0x10),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0017bd96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 0017be30 nvmlDeviceGetPowerManagementMode =====

int nvmlDeviceGetPowerManagementMode(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x107,"nvmlDeviceGetPowerManagementMode",
                 "(nvmlDevice_t device, nvmlEnableState_t *mode)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017bd00(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x107,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x107,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0017c010 FUN_0017c010 =====

ulong FUN_0017c010(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x1014);
        }
      }
      else if (param_2 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x160) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x160) + 0x28),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0017c0a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 0017c140 nvmlDeviceGetPowerManagementLimit =====

int nvmlDeviceGetPowerManagementLimit(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x10b,"nvmlDeviceGetPowerManagementLimit",
                 "(nvmlDevice_t device, unsigned int *limit)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017c010(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x10b,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x10b,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0017c320 FUN_0017c320 =====

int FUN_0017c320(long param_1,long param_2,long param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  int local_2c;
  
  iVar2 = FUN_00175bd0(param_1,&local_2c);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_2c == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar3,"api.c",0x1025);
        }
      }
      else if ((param_2 == 0) || (param_3 == 0)) {
        iVar2 = 2;
      }
      else {
        lVar3 = *(long *)(param_1 + 0x256d8);
        if (((lVar3 == 0) || (*(long *)(lVar3 + 0x160) == 0)) ||
           (pcVar1 = *(code **)(*(long *)(lVar3 + 0x160) + 0x30), pcVar1 == (code *)0x0)) {
          iVar2 = 3;
        }
        else {
          iVar2 = (*pcVar1)(lVar3,param_1,0,0,0,param_2,param_3,0);
        }
      }
    }
    else {
      iVar2 = 999;
    }
  }
  return iVar2;
}


// ===== 0017c470 nvmlDeviceGetPowerManagementLimitConstraints =====

int nvmlDeviceGetPowerManagementLimitConstraints
              (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",600,"nvmlDeviceGetPowerManagementLimitConstraints",
                 "(nvmlDevice_t device, unsigned int *minLimit, unsigned int *maxLimit)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017c320(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",600,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",600,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0017c640 FUN_0017c640 =====

int FUN_0017c640(long param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  int local_2c [3];
  
  iVar2 = FUN_00175bd0(param_1,local_2c);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_2c[0] == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar3,"api.c",0x1037);
        }
      }
      else if (param_2 == 0) {
        iVar2 = 2;
      }
      else {
        lVar3 = *(long *)(param_1 + 0x256d8);
        if (((lVar3 == 0) || (*(long *)(lVar3 + 0x160) == 0)) ||
           (pcVar1 = *(code **)(*(long *)(lVar3 + 0x160) + 0x30), pcVar1 == (code *)0x0)) {
          iVar2 = 3;
        }
        else {
          iVar2 = (*pcVar1)(lVar3,param_1,0,param_2,0,0,0,0);
        }
      }
    }
    else {
      iVar2 = 999;
    }
  }
  return iVar2;
}


// ===== 0017c770 nvmlDeviceGetPowerManagementDefaultLimit =====

int nvmlDeviceGetPowerManagementDefaultLimit(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x25c,"nvmlDeviceGetPowerManagementDefaultLimit",
                 "(nvmlDevice_t device, unsigned int *defaultLimit)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017c640(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x25c,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x25c,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0017c950 FUN_0017c950 =====

ulong FUN_0017c950(long param_1,undefined4 param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  float fVar5;
  int local_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar4 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar4 = 3;
        if (3 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar3,"api.c",0x1048);
        }
      }
      else {
        iVar2 = FUN_00236dd0();
        if (iVar2 == 0) {
          uVar4 = 4;
        }
        else {
          lVar3 = *(long *)(param_1 + 0x256d8);
          if (((lVar3 != 0) && (*(long *)(lVar3 + 0x160) != 0)) &&
             (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar3 + 0x160) + 0x20),
             UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0017ca46. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar4 = (*UNRECOVERED_JUMPTABLE)(lVar3,param_1,0,0,param_2);
            return uVar4;
          }
          uVar4 = 3;
        }
      }
    }
    else {
      uVar4 = 999;
    }
  }
  return uVar4;
}


// ===== 0017ca70 nvmlDeviceSetPowerManagementLimit =====

int nvmlDeviceSetPowerManagementLimit(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %u)\n","DEBUG",lVar3,
                 "entry_points.h",0x260,"nvmlDeviceSetPowerManagementLimit",
                 "(nvmlDevice_t device, unsigned int limit)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017c950(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x260,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x260,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0017cc50 FUN_0017cc50 =====

ulong FUN_0017cc50(char *param_1,uint param_2,long param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c;
  
  uVar1 = FUN_00175bd0(param_1,&local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x108f);
        }
      }
      else if (((param_1 == (char *)0x0) ||
               ((*param_1 != '\x01' &&
                ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
                  (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))))) ||
              ((param_3 == 0 || (7 < param_2)))) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x118) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x118) + 0x10),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0017cd40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2,param_3);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 0017cde0 nvmlDeviceGetTemperatureThreshold =====

int nvmlDeviceGetTemperatureThreshold(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x117,"nvmlDeviceGetTemperatureThreshold",
                 "(nvmlDevice_t device, nvmlTemperatureThresholds_t thresholdType, unsigned int *temp)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017cc50(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x117,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x117,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0017cfb0 FUN_0017cfb0 =====

ulong FUN_0017cfb0(char *param_1,int param_2,long param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  float fVar5;
  int local_2c;
  
  uVar1 = FUN_00175bd0(param_1,&local_2c);
  uVar4 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c == 0) {
        uVar4 = 3;
        if (3 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar3,"api.c",0x10a4);
        }
      }
      else {
        iVar2 = FUN_00236dd0();
        if (iVar2 == 0) {
          uVar4 = 4;
          if (1 < DAT_01216a78) {
            fVar5 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                         "ERROR",lVar3,"api.c",0x10ad);
          }
        }
        else if (((param_1 == (char *)0x0) ||
                 ((*param_1 != '\x01' &&
                  ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
                    (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))))) ||
                ((param_3 == 0 || (param_2 != 5)))) {
          uVar4 = 2;
        }
        else {
          lVar3 = *(long *)(param_1 + 0x256d8);
          if (((lVar3 != 0) && (*(long *)(lVar3 + 0x118) != 0)) &&
             (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar3 + 0x118) + 0x18),
             UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0017d0fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar4 = (*UNRECOVERED_JUMPTABLE)(lVar3,param_1,5,param_3);
            return uVar4;
          }
          uVar4 = 3;
        }
      }
    }
    else {
      uVar4 = 999;
    }
  }
  return uVar4;
}


// ===== 0017d1a0 nvmlDeviceSetTemperatureThreshold =====

int nvmlDeviceSetTemperatureThreshold(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x11b,"nvmlDeviceSetTemperatureThreshold",
                 "(nvmlDevice_t device, nvmlTemperatureThresholds_t thresholdType, int *temp)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017cfb0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x11b,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x11b,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0017d370 FUN_0017d370 =====

ulong FUN_0017d370(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x1197);
        }
      }
      else if (param_2 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(undefined8 **)(lVar2 + 0x128) != (undefined8 *)0x0)) &&
           (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar2 + 0x128),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0017d405. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 0017d4a0 nvmlDeviceGetUtilizationRates =====

int nvmlDeviceGetUtilizationRates(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x13b,"nvmlDeviceGetUtilizationRates",
                 "(nvmlDevice_t device, nvmlUtilization_t *utilization)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017d370(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x13b,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x13b,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0017d680 FUN_0017d680 =====

ulong FUN_0017d680(char *param_1,long param_2,long param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c;
  
  if ((param_1 == (char *)0x0) ||
     (((*param_1 != '\x01' &&
       ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
         (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) ||
      ((param_2 == 0 || (param_3 == 0)))))) {
    uVar3 = 2;
  }
  else {
    uVar1 = FUN_00175bd0(param_1,&local_2c);
    uVar3 = (ulong)uVar1;
    if ((uVar1 != 2) && (uVar1 != 0xf)) {
      if (uVar1 == 0) {
        if (local_2c == 0) {
          uVar3 = 3;
          if (3 < DAT_01216a78) {
            fVar4 = (float)FUN_002917b0(&DAT_01216a60);
            lVar2 = syscall(0xba);
            FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                         &DAT_002983c2,lVar2,"api.c",0x11ac);
          }
        }
        else {
          lVar2 = *(long *)(param_1 + 0x256d8);
          if (((lVar2 != 0) && (*(long *)(lVar2 + 0x128) != 0)) &&
             (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x128) + 0x28),
             UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0017d74f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2,param_3);
            return uVar3;
          }
          uVar3 = 3;
        }
      }
      else {
        uVar3 = 999;
      }
    }
  }
  return uVar3;
}


// ===== 0017d7d0 nvmlDeviceGetEncoderUtilization =====

int nvmlDeviceGetEncoderUtilization(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x13f,"nvmlDeviceGetEncoderUtilization",
                 "(nvmlDevice_t device, unsigned int *utilization, unsigned int *samplingPeriodUs)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017d680(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x13f,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x13f,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0017d9a0 FUN_0017d9a0 =====

ulong FUN_0017d9a0(char *param_1,long param_2,long param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c;
  
  if ((param_1 == (char *)0x0) ||
     (((*param_1 != '\x01' &&
       ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
         (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) ||
      ((param_2 == 0 || (param_3 == 0)))))) {
    uVar3 = 2;
  }
  else {
    uVar1 = FUN_00175bd0(param_1,&local_2c);
    uVar3 = (ulong)uVar1;
    if ((uVar1 != 2) && (uVar1 != 0xf)) {
      if (uVar1 == 0) {
        if (local_2c == 0) {
          uVar3 = 3;
          if (3 < DAT_01216a78) {
            fVar4 = (float)FUN_002917b0(&DAT_01216a60);
            lVar2 = syscall(0xba);
            FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                         &DAT_002983c2,lVar2,"api.c",0x11bd);
          }
        }
        else {
          lVar2 = *(long *)(param_1 + 0x256d8);
          if (((lVar2 != 0) && (*(long *)(lVar2 + 0x128) != 0)) &&
             (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x128) + 0x30),
             UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0017da6f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2,param_3);
            return uVar3;
          }
          uVar3 = 3;
        }
      }
      else {
        uVar3 = 999;
      }
    }
  }
  return uVar3;
}


// ===== 0017daf0 nvmlDeviceGetDecoderUtilization =====

int nvmlDeviceGetDecoderUtilization(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x143,"nvmlDeviceGetDecoderUtilization",
                 "(nvmlDevice_t device, unsigned int *utilization, unsigned int *samplingPeriodUs)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017d9a0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x143,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x143,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0017dcc0 FUN_0017dcc0 =====

int FUN_0017dcc0(char *param_1,long param_2,long param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  float fVar5;
  int local_30;
  int local_2c;
  
  local_30 = 0;
  if (param_1 != (char *)0x0) {
    if (*param_1 != '\x01') {
      if (*(int *)(param_1 + 0x14) == 0) {
        return 2;
      }
      if (*(int *)(param_1 + 0x1c) != 0) {
        return 2;
      }
      if (*(int *)(param_1 + 0x10) == 0) {
        return 2;
      }
      if (*(long *)(param_1 + 0x20) == 0) {
        return 2;
      }
    }
    if ((param_2 != 0) && (param_3 != 0)) {
      iVar2 = FUN_00175bd0(param_1,&local_2c);
      if (iVar2 == 2) {
        return 2;
      }
      if (iVar2 == 0xf) {
        return 0xf;
      }
      if (iVar2 != 0) {
        return 999;
      }
      if (local_2c == 0) {
        if (DAT_01216a78 < 4) {
          return 3;
        }
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                     &DAT_002983c2,lVar4,"api.c",0x11d3);
        return 3;
      }
      iVar2 = FUN_00139230(param_1,&local_30,9);
      if (iVar2 != 0) {
        return iVar2;
      }
      if (local_30 != 0) {
        if (*(int *)(param_1 + 0x70534) == 0) {
          do {
            iVar2 = FUN_00291820(param_1 + 0x70538,1,0);
          } while (iVar2 != 0);
          if (*(int *)(param_1 + 0x70534) == 0) {
            lVar4 = *(long *)(param_1 + 0x256d8);
            uVar3 = 3;
            if (((lVar4 != 0) && (*(long *)(lVar4 + 0x38) != 0)) &&
               (pcVar1 = *(code **)(*(long *)(lVar4 + 0x38) + 8), pcVar1 != (code *)0x0)) {
              uVar3 = (*pcVar1)(lVar4,param_1,param_1 + 0x70530);
            }
            *(undefined4 *)(param_1 + 0x7053c) = uVar3;
            param_1[0x70534] = '\x01';
            param_1[0x70535] = '\0';
            param_1[0x70536] = '\0';
            param_1[0x70537] = '\0';
          }
          FUN_00291830(param_1 + 0x70538,0);
        }
        iVar2 = *(int *)(param_1 + 0x7053c);
        if (iVar2 != 0) {
          if (DAT_01216a78 < 2) {
            return iVar2;
          }
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,"api.c",0x11e5,
                       "tsapiDeviceGetJpgUtilization",0x11e5,iVar2);
          return iVar2;
        }
        if (((*(int *)(param_1 + 0x70530) != 2) &&
            (lVar4 = *(long *)(param_1 + 0x256d8), lVar4 != 0)) &&
           ((*(long *)(lVar4 + 0x128) != 0 &&
            (pcVar1 = *(code **)(*(long *)(lVar4 + 0x128) + 0x38), pcVar1 != (code *)0x0)))) {
          iVar2 = (*pcVar1)(lVar4,param_1,param_2,param_3);
          return iVar2;
        }
      }
      return 3;
    }
  }
  return 2;
}


// ===== 0017df70 nvmlDeviceGetJpgUtilization =====

int nvmlDeviceGetJpgUtilization(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x147,"nvmlDeviceGetJpgUtilization",
                 "(nvmlDevice_t device, unsigned int *utilization, unsigned int *samplingPeriodUs)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017dcc0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x147,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x147,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0017e140 FUN_0017e140 =====

int FUN_0017e140(char *param_1,long param_2,long param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  float fVar5;
  int local_30;
  int local_2c;
  
  local_30 = 0;
  if (param_1 != (char *)0x0) {
    if (*param_1 != '\x01') {
      if (*(int *)(param_1 + 0x14) == 0) {
        return 2;
      }
      if (*(int *)(param_1 + 0x1c) != 0) {
        return 2;
      }
      if (*(int *)(param_1 + 0x10) == 0) {
        return 2;
      }
      if (*(long *)(param_1 + 0x20) == 0) {
        return 2;
      }
    }
    if ((param_2 != 0) && (param_3 != 0)) {
      iVar2 = FUN_00175bd0(param_1,&local_2c);
      if (iVar2 == 2) {
        return 2;
      }
      if (iVar2 == 0xf) {
        return 0xf;
      }
      if (iVar2 != 0) {
        return 999;
      }
      if (local_2c == 0) {
        if (DAT_01216a78 < 4) {
          return 3;
        }
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                     &DAT_002983c2,lVar4,"api.c",0x1205);
        return 3;
      }
      iVar2 = FUN_00139230(param_1,&local_30,9);
      if (iVar2 != 0) {
        return iVar2;
      }
      if (local_30 != 0) {
        if (*(int *)(param_1 + 0x70534) == 0) {
          do {
            iVar2 = FUN_00291820(param_1 + 0x70538,1,0);
          } while (iVar2 != 0);
          if (*(int *)(param_1 + 0x70534) == 0) {
            lVar4 = *(long *)(param_1 + 0x256d8);
            uVar3 = 3;
            if (((lVar4 != 0) && (*(long *)(lVar4 + 0x38) != 0)) &&
               (pcVar1 = *(code **)(*(long *)(lVar4 + 0x38) + 8), pcVar1 != (code *)0x0)) {
              uVar3 = (*pcVar1)(lVar4,param_1,param_1 + 0x70530);
            }
            *(undefined4 *)(param_1 + 0x7053c) = uVar3;
            param_1[0x70534] = '\x01';
            param_1[0x70535] = '\0';
            param_1[0x70536] = '\0';
            param_1[0x70537] = '\0';
          }
          FUN_00291830(param_1 + 0x70538,0);
        }
        iVar2 = *(int *)(param_1 + 0x7053c);
        if (iVar2 != 0) {
          if (DAT_01216a78 < 2) {
            return iVar2;
          }
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,"api.c",0x1217,
                       "tsapiDeviceGetOfaUtilization",0x1217,iVar2);
          return iVar2;
        }
        if (((*(int *)(param_1 + 0x70530) != 2) &&
            (lVar4 = *(long *)(param_1 + 0x256d8), lVar4 != 0)) &&
           ((*(long *)(lVar4 + 0x128) != 0 &&
            (pcVar1 = *(code **)(*(long *)(lVar4 + 0x128) + 0x40), pcVar1 != (code *)0x0)))) {
          iVar2 = (*pcVar1)(lVar4,param_1,param_2,param_3);
          return iVar2;
        }
      }
      return 3;
    }
  }
  return 2;
}


// ===== 0017e3f0 nvmlDeviceGetOfaUtilization =====

int nvmlDeviceGetOfaUtilization(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x14b,"nvmlDeviceGetOfaUtilization",
                 "(nvmlDevice_t device, unsigned int *utilization, unsigned int *samplingPeriodUs)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017e140(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x14b,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x14b,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0017e5c0 FUN_0017e5c0 =====

int FUN_0017e5c0(long param_1,uint param_2,void *param_3,ulong param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  size_t sVar4;
  long lVar5;
  float fVar6;
  char *local_50;
  int local_3c [3];
  
  iVar2 = FUN_00175bd0(param_1,local_3c);
  if (iVar2 == 2) {
    return 2;
  }
  if (iVar2 == 0xf) {
    return 0xf;
  }
  if (iVar2 != 0) {
    return 999;
  }
  if (local_3c[0] == 0) {
    if (DAT_01216a78 < 4) {
      return 3;
    }
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar5,"api.c",0x12ce);
    return 3;
  }
  if (param_3 == (void *)0x0) {
LAB_0017e7b0:
    iVar2 = 2;
  }
  else {
    if (param_2 == 2) {
      local_50 = (char *)(param_1 + 0x3f0);
      if (*(int *)(param_1 + 0x400) == 0) {
        do {
          iVar2 = FUN_00291820(param_1 + 0x404,1,0);
        } while (iVar2 != 0);
        if (*(int *)(param_1 + 0x400) == 0) {
          lVar5 = *(long *)(param_1 + 0x256d8);
          uVar3 = 3;
          if (((lVar5 != 0) && (*(long *)(lVar5 + 200) != 0)) &&
             (pcVar1 = *(code **)(*(long *)(lVar5 + 200) + 8), pcVar1 != (code *)0x0)) {
            uVar3 = (*pcVar1)(lVar5,param_1,2,local_50);
          }
          *(undefined4 *)(param_1 + 0x408) = uVar3;
          *(undefined4 *)(param_1 + 0x400) = 1;
        }
        FUN_00291830(param_1 + 0x404,0);
      }
      iVar2 = *(int *)(param_1 + 0x408);
    }
    else if (param_2 < 3) {
      if (param_2 == 0) {
        local_50 = (char *)(param_1 + 0x3b8);
        if (*(int *)(param_1 + 0x3c8) == 0) {
          do {
            iVar2 = FUN_00291820(param_1 + 0x3cc,1,0);
          } while (iVar2 != 0);
          if (*(int *)(param_1 + 0x3c8) == 0) {
            lVar5 = *(long *)(param_1 + 0x256d8);
            uVar3 = 3;
            if (((lVar5 != 0) && (*(long *)(lVar5 + 200) != 0)) &&
               (pcVar1 = *(code **)(*(long *)(lVar5 + 200) + 8), pcVar1 != (code *)0x0)) {
              uVar3 = (*pcVar1)(lVar5,param_1,0,local_50);
            }
            *(undefined4 *)(param_1 + 0x3d0) = uVar3;
            *(undefined4 *)(param_1 + 0x3c8) = 1;
          }
          FUN_00291830(param_1 + 0x3cc,0);
        }
        iVar2 = *(int *)(param_1 + 0x3d0);
      }
      else {
        local_50 = (char *)(param_1 + 0x3d4);
        if (*(int *)(param_1 + 0x3e4) == 0) {
          do {
            iVar2 = FUN_00291820(param_1 + 1000,1,0);
          } while (iVar2 != 0);
          if (*(int *)(param_1 + 0x3e4) == 0) {
            lVar5 = *(long *)(param_1 + 0x256d8);
            uVar3 = 3;
            if (((lVar5 != 0) && (*(long *)(lVar5 + 200) != 0)) &&
               (pcVar1 = *(code **)(*(long *)(lVar5 + 200) + 8), pcVar1 != (code *)0x0)) {
              uVar3 = (*pcVar1)(lVar5,param_1,1,local_50);
            }
            *(undefined4 *)(param_1 + 0x3ec) = uVar3;
            *(undefined4 *)(param_1 + 0x3e4) = 1;
          }
          FUN_00291830(param_1 + 1000,0);
        }
        iVar2 = *(int *)(param_1 + 0x3ec);
      }
    }
    else {
      if (param_2 != 3) goto LAB_0017e7b0;
      local_50 = (char *)(param_1 + 0x40c);
      if (*(int *)(param_1 + 0x41c) == 0) {
        do {
          iVar2 = FUN_00291820(param_1 + 0x420,1,0);
        } while (iVar2 != 0);
        if (*(int *)(param_1 + 0x41c) == 0) {
          lVar5 = *(long *)(param_1 + 0x256d8);
          uVar3 = 3;
          if (((lVar5 != 0) && (*(long *)(lVar5 + 200) != 0)) &&
             (pcVar1 = *(code **)(*(long *)(lVar5 + 200) + 8), pcVar1 != (code *)0x0)) {
            uVar3 = (*pcVar1)(lVar5,param_1,3,local_50);
          }
          *(undefined4 *)(param_1 + 0x424) = uVar3;
          *(undefined4 *)(param_1 + 0x41c) = 1;
        }
        FUN_00291830(param_1 + 0x420,0);
      }
      iVar2 = *(int *)(param_1 + 0x424);
    }
    if (iVar2 == 0) {
      sVar4 = strlen(local_50);
      if ((param_4 & 0xffffffff) < sVar4 + 1) {
        iVar2 = 7;
      }
      else {
        memcpy(param_3,local_50,sVar4 + 1);
      }
    }
  }
  return iVar2;
}


// ===== 0017e9b0 nvmlDeviceGetInforomVersion =====

int nvmlDeviceGetInforomVersion
              (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d, %p, %d)\n","DEBUG",lVar3
                 ,"entry_points.h",0x49,"nvmlDeviceGetInforomVersion",
                 "(nvmlDevice_t device, nvmlInforomObject_t object, char *version, unsigned int length)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017e5c0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x49,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x49,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0017eba0 FUN_0017eba0 =====

void FUN_0017eba0(long param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  float fVar5;
  undefined1 local_48 [16];
  undefined1 local_38 [16];
  
  if (*(int *)(param_1 + 0x70534) == 0) {
    do {
      iVar2 = FUN_00291820(param_1 + 0x70538,1,0);
    } while (iVar2 != 0);
    if (*(int *)(param_1 + 0x70534) == 0) {
      lVar4 = *(long *)(param_1 + 0x256d8);
      uVar3 = 3;
      if (((lVar4 != 0) && (*(long *)(lVar4 + 0x38) != 0)) &&
         (pcVar1 = *(code **)(*(long *)(lVar4 + 0x38) + 8), pcVar1 != (code *)0x0)) {
        uVar3 = (*pcVar1)(lVar4,param_1,param_1 + 0x70530);
      }
      *(undefined4 *)(param_1 + 0x7053c) = uVar3;
      *(undefined4 *)(param_1 + 0x70534) = 1;
    }
    FUN_00291830(param_1 + 0x70538,0);
  }
  if ((*(int *)(param_1 + 0x7053c) == 0) && (*(int *)(param_1 + 0x70530) == 2)) {
    return;
  }
  lVar4 = *(long *)(param_1 + 0x256d8);
  local_48 = (undefined1  [16])0x0;
  local_38 = (undefined1  [16])0x0;
  if (((lVar4 == 0) || (*(long *)(lVar4 + 200) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(lVar4 + 200) + 8), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar4,param_1,0x66,local_48);
    if (iVar2 == 0) {
      if (4 < DAT_01216a78) {
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n",
                     "DEBUG",lVar4,"api.c",0x1cf,local_48);
      }
      goto LAB_0017ec70;
    }
  }
  if (2 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","WARNING",
                 lVar4,"api.c",0x1d3,iVar2);
  }
LAB_0017ec70:
  local_48 = (undefined1  [16])0x0;
  local_38 = (undefined1  [16])0x0;
  FUN_0017e5c0(param_1,3,local_48,0x20);
  return;
}


// ===== 0017edc0 FUN_0017edc0 =====

void FUN_0017edc0(long param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  float fVar5;
  undefined1 local_48 [16];
  undefined1 local_38 [16];
  
  if (*(int *)(param_1 + 0x70534) == 0) {
    do {
      iVar2 = FUN_00291820(param_1 + 0x70538,1,0);
    } while (iVar2 != 0);
    if (*(int *)(param_1 + 0x70534) == 0) {
      lVar4 = *(long *)(param_1 + 0x256d8);
      uVar3 = 3;
      if (((lVar4 != 0) && (*(long *)(lVar4 + 0x38) != 0)) &&
         (pcVar1 = *(code **)(*(long *)(lVar4 + 0x38) + 8), pcVar1 != (code *)0x0)) {
        uVar3 = (*pcVar1)(lVar4,param_1,param_1 + 0x70530);
      }
      *(undefined4 *)(param_1 + 0x7053c) = uVar3;
      *(undefined4 *)(param_1 + 0x70534) = 1;
    }
    FUN_00291830(param_1 + 0x70538,0);
  }
  if ((*(int *)(param_1 + 0x7053c) == 0) && (*(int *)(param_1 + 0x70530) == 2)) {
    return;
  }
  lVar4 = *(long *)(param_1 + 0x256d8);
  local_48 = (undefined1  [16])0x0;
  local_38 = (undefined1  [16])0x0;
  if (((lVar4 == 0) || (*(long *)(lVar4 + 200) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(lVar4 + 200) + 8), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar4,param_1,0x66,local_48);
    if (iVar2 == 0) {
      if (4 < DAT_01216a78) {
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n",
                     "DEBUG",lVar4,"api.c",0x1f7,local_48);
      }
      goto LAB_0017ee90;
    }
  }
  if (2 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","WARNING",
                 lVar4,"api.c",0x1fb,iVar2);
  }
LAB_0017ee90:
  local_48 = (undefined1  [16])0x0;
  local_38 = (undefined1  [16])0x0;
  FUN_0017e5c0(param_1,1,local_48,0x20);
  return;
}


// ===== 0017efe0 FUN_0017efe0 =====

int FUN_0017efe0(long param_1,long param_2,long param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  double dVar6;
  undefined8 uVar7;
  int local_2c;
  
  iVar2 = FUN_00175bd0(param_1,&local_2c);
  if (iVar2 == 2) {
    return 2;
  }
  if (iVar2 == 0xf) {
    return 0xf;
  }
  if (iVar2 != 0) {
    return 999;
  }
  if (local_2c == 0) {
    if (DAT_01216a78 < 4) {
      return 3;
    }
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar3,"api.c",0x608);
    return 3;
  }
  if ((param_2 == 0) || (param_3 == 0)) {
    return 2;
  }
  iVar2 = FUN_0017eba0(param_1);
  if (iVar2 == 0) {
    lVar3 = *(long *)(param_1 + 0x256d8);
    if (((lVar3 == 0) || (*(long *)(lVar3 + 0x68) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(lVar3 + 0x68) + 0x48), pcVar1 == (code *)0x0)) {
      iVar2 = 3;
    }
    else {
      iVar2 = (*pcVar1)(lVar3,param_1,param_3 + 4);
      if (iVar2 == 0) {
        lVar3 = *(long *)(param_1 + 0x256d8);
        if (((lVar3 == 0) || (*(long *)(lVar3 + 0x68) == 0)) ||
           (pcVar1 = *(code **)(*(long *)(lVar3 + 0x68) + 0x40), pcVar1 == (code *)0x0)) {
          iVar2 = 3;
        }
        else {
          iVar2 = (*pcVar1)(lVar3,param_1,param_2 + 4);
          if (iVar2 == 0) {
            return 0;
          }
        }
        if (DAT_01216a78 < 2) {
          return iVar2;
        }
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        uVar7 = 0x61c;
        uVar4 = 0x61c;
        dVar6 = (double)(fVar5 * DAT_00298548);
        goto LAB_0017f138;
      }
    }
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    uVar7 = 0x617;
    uVar4 = 0x617;
    dVar6 = (double)(fVar5 * DAT_00298548);
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    uVar7 = 0x612;
    uVar4 = 0x612;
    dVar6 = (double)(fVar5 * DAT_00298548);
  }
LAB_0017f138:
  FUN_002340f0(dVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,"api.c",uVar4,
               "tsapiDeviceGetDramEncryptionMode",uVar7,iVar2);
  return iVar2;
}


// ===== 0017f2c0 nvmlDeviceGetDramEncryptionMode =====

int nvmlDeviceGetDramEncryptionMode(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x56,"nvmlDeviceGetDramEncryptionMode",
                 "(nvmlDevice_t device, nvmlDramEncryptionInfo_t *current, nvmlDramEncryptionInfo_t *pending)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017efe0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x56,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x56,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0017f490 FUN_0017f490 =====

int FUN_0017f490(long param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  float fVar6;
  undefined8 uVar7;
  int local_2c [3];
  
  iVar2 = FUN_00175bd0(param_1,local_2c);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_2c[0] == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar6 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar4,"api.c",0x629);
        }
      }
      else {
        iVar3 = FUN_00236dd0();
        iVar2 = 4;
        if (iVar3 != 0) {
          iVar2 = FUN_0017eba0(param_1);
          if (iVar2 == 0) {
            lVar4 = *(long *)(param_1 + 0x256d8);
            if (((lVar4 == 0) || (*(long *)(lVar4 + 0x68) == 0)) ||
               (pcVar1 = *(code **)(*(long *)(lVar4 + 0x68) + 0x50), pcVar1 == (code *)0x0)) {
              iVar2 = 3;
            }
            else {
              iVar2 = (*pcVar1)(lVar4,param_1,*(undefined4 *)(param_2 + 4));
              if (iVar2 == 0) {
                return 0;
              }
            }
            if (DAT_01216a78 < 2) {
              return iVar2;
            }
            fVar6 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            fVar6 = fVar6 * DAT_00298548;
            uVar7 = 0x636;
            uVar5 = 0x636;
          }
          else {
            if (DAT_01216a78 < 2) {
              return iVar2;
            }
            fVar6 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            fVar6 = fVar6 * DAT_00298548;
            uVar7 = 0x633;
            uVar5 = 0x633;
          }
          FUN_002340f0((double)fVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
                       "api.c",uVar5,"tsapiDeviceSetDramEncryptionMode",uVar7,iVar2);
        }
      }
    }
    else {
      iVar2 = 999;
    }
  }
  return iVar2;
}


// ===== 0017f6a0 nvmlDeviceSetDramEncryptionMode =====

int nvmlDeviceSetDramEncryptionMode(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x5a,"nvmlDeviceSetDramEncryptionMode",
                 "(nvmlDevice_t device, const nvmlDramEncryptionInfo_t *dramEncryption)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017f490(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5a,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5a,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0017f880 FUN_0017f880 =====

int FUN_0017f880(long param_1,long param_2,long param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  int local_2c;
  
  iVar2 = FUN_00175bd0(param_1,&local_2c);
  if (iVar2 == 2) {
    return 2;
  }
  if (iVar2 == 0xf) {
    return 0xf;
  }
  if (iVar2 != 0) {
    return 999;
  }
  if (local_2c == 0) {
    if (DAT_01216a78 < 4) {
      return 3;
    }
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar3,"api.c",0x646);
    return 3;
  }
  if ((param_2 == 0) || (param_3 == 0)) {
    return 2;
  }
  iVar2 = FUN_0017edc0(param_1);
  if (iVar2 != 0) {
    return iVar2;
  }
  lVar3 = *(long *)(param_1 + 0x256d8);
  if (((lVar3 == 0) || (*(long *)(lVar3 + 0x140) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(lVar3 + 0x140) + 0x10), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_1,param_3);
    if (iVar2 == 0) {
      lVar3 = *(long *)(param_1 + 0x256d8);
      if (((lVar3 == 0) || (*(long *)(lVar3 + 0x140) == 0)) ||
         (pcVar1 = *(code **)(*(long *)(lVar3 + 0x140) + 8), pcVar1 == (code *)0x0)) {
        iVar2 = 3;
      }
      else {
        iVar2 = (*pcVar1)(lVar3,param_1,param_2);
        if (iVar2 == 0) {
          return 0;
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0x659;
      uVar4 = 0x659;
      goto LAB_0017f9d1;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  fVar5 = fVar5 * DAT_00298548;
  uVar6 = 0x655;
  uVar4 = 0x655;
LAB_0017f9d1:
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,"api.c",
               uVar4,"tsapiDeviceGetEccMode",uVar6,iVar2);
  return iVar2;
}


// ===== 0017fb00 nvmlDeviceGetEccMode =====

int nvmlDeviceGetEccMode(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x5f,"nvmlDeviceGetEccMode",
                 "(nvmlDevice_t device, nvmlEnableState_t *current, nvmlEnableState_t *pending)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017f880(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5f,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5f,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0017fcd0 FUN_0017fcd0 =====

ulong FUN_0017fcd0(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x666);
        }
      }
      else if (param_2 == 0) {
        uVar3 = 2;
      }
      else {
        uVar1 = FUN_0017edc0(param_1);
        uVar3 = (ulong)uVar1;
        if (uVar1 == 0) {
          lVar2 = *(long *)(param_1 + 0x256d8);
          if (((lVar2 != 0) && (*(long *)(lVar2 + 0x140) != 0)) &&
             (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x140) + 0x18),
             UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0017fd75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
            return uVar3;
          }
          uVar3 = 3;
        }
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 0017fe20 nvmlDeviceGetDefaultEccMode =====

int nvmlDeviceGetDefaultEccMode(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",99,"nvmlDeviceGetDefaultEccMode",
                 "(nvmlDevice_t device, nvmlEnableState_t *defaultMode)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0017fcd0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",99,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",99,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00180000 FUN_00180000 =====

int FUN_00180000(long param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  float fVar6;
  int local_48 [8];
  
  iVar2 = FUN_00175bd0(param_1,local_48);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_48[0] == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar6 = (float)FUN_002917b0(&DAT_01216a60);
          lVar5 = syscall(0xba);
          FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar5,"api.c",0x84c);
        }
      }
      else {
        iVar3 = FUN_00236dd0();
        iVar2 = 4;
        if (iVar3 != 0) {
          if (*(int *)(param_1 + 0x70534) == 0) {
            do {
              iVar2 = FUN_00291820(param_1 + 0x70538,1,0);
            } while (iVar2 != 0);
            if (*(int *)(param_1 + 0x70534) == 0) {
              lVar5 = *(long *)(param_1 + 0x256d8);
              uVar4 = 3;
              if (((lVar5 != 0) && (*(long *)(lVar5 + 0x38) != 0)) &&
                 (pcVar1 = *(code **)(*(long *)(lVar5 + 0x38) + 8), pcVar1 != (code *)0x0)) {
                uVar4 = (*pcVar1)(lVar5,param_1,param_1 + 0x70530);
              }
              *(undefined4 *)(param_1 + 0x7053c) = uVar4;
              *(undefined4 *)(param_1 + 0x70534) = 1;
            }
            FUN_00291830(param_1 + 0x70538,0);
          }
          if (((*(int *)(param_1 + 0x7053c) != 0) || (*(int *)(param_1 + 0x70530) != 2)) &&
             (iVar2 = FUN_0017e5c0(param_1,1,local_48,0x20), iVar2 != 0)) {
            return iVar2;
          }
          lVar5 = *(long *)(param_1 + 0x256d8);
          if (((lVar5 == 0) || (*(long *)(lVar5 + 0x140) == 0)) ||
             (pcVar1 = *(code **)(*(long *)(lVar5 + 0x140) + 0x60), pcVar1 == (code *)0x0)) {
            iVar2 = 3;
          }
          else {
            iVar2 = (*pcVar1)(lVar5,param_1,param_2);
          }
        }
      }
    }
    else {
      iVar2 = 999;
    }
  }
  return iVar2;
}


// ===== 00180200 nvmlDeviceSetEccMode =====

int nvmlDeviceSetEccMode(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x79,"nvmlDeviceSetEccMode",
                 "(nvmlDevice_t device, nvmlEnableState_t ecc)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00180000(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x79,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x79,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001803e0 FUN_001803e0 =====

int FUN_001803e0(long param_1,void *param_2,ulong param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  size_t sVar4;
  long lVar5;
  float fVar6;
  int local_2c;
  
  iVar2 = FUN_00175bd0(param_1,&local_2c);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_2c == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar6 = (float)FUN_002917b0(&DAT_01216a60);
          lVar5 = syscall(0xba);
          FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar5,"api.c",0x12e0);
        }
      }
      else if (param_2 == (void *)0x0) {
        iVar2 = 2;
      }
      else {
        if (*(int *)(param_1 + 0x3ac) == 0) {
          do {
            iVar2 = FUN_00291820(param_1 + 0x3b0,1,0);
          } while (iVar2 != 0);
          if (*(int *)(param_1 + 0x3ac) == 0) {
            lVar5 = *(long *)(param_1 + 0x256d8);
            uVar3 = 3;
            if (((lVar5 != 0) && (*(undefined8 **)(lVar5 + 200) != (undefined8 *)0x0)) &&
               (pcVar1 = (code *)**(undefined8 **)(lVar5 + 200), pcVar1 != (code *)0x0)) {
              uVar3 = (*pcVar1)(lVar5,param_1,param_1 + 0x39c);
            }
            *(undefined4 *)(param_1 + 0x3b4) = uVar3;
            *(undefined4 *)(param_1 + 0x3ac) = 1;
          }
          FUN_00291830(param_1 + 0x3b0,0);
        }
        iVar2 = *(int *)(param_1 + 0x3b4);
        if (iVar2 == 0) {
          sVar4 = strlen((char *)(param_1 + 0x39c));
          if ((param_3 & 0xffffffff) < sVar4 + 1) {
            iVar2 = 7;
          }
          else {
            memcpy(param_2,(char *)(param_1 + 0x39c),sVar4 + 1);
          }
        }
        else if (1 < DAT_01216a78) {
          fVar6 = (float)FUN_002917b0(&DAT_01216a60);
          lVar5 = syscall(0xba);
          FUN_002340f0((double)(fVar6 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,"api.c",0x12ed,
                       "tsapiDeviceGetInforomImageVersion",0x12ed,iVar2);
        }
      }
    }
    else {
      iVar2 = 999;
    }
  }
  return iVar2;
}


// ===== 00180630 nvmlDeviceGetInforomImageVersion =====

int nvmlDeviceGetInforomImageVersion(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x4d,"nvmlDeviceGetInforomImageVersion",
                 "(nvmlDevice_t device, char *version, unsigned int length)",param_1,param_2,param_3
                );
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001803e0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x4d,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x4d,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00180800 FUN_00180800 =====

int FUN_00180800(char *param_1,byte *param_2)

{
  byte bVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  float fVar6;
  int local_2c [3];
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((iVar3 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (param_2 == (byte *)0x0) {
      return 2;
    }
    iVar3 = FUN_00175bd0(param_1,local_2c);
    if ((iVar3 != 2) && (iVar3 != 0xf)) {
      if (iVar3 == 0) {
        if (local_2c[0] == 0) {
          iVar3 = 3;
          if (3 < DAT_01216a78) {
            fVar6 = (float)FUN_002917b0(&DAT_01216a60);
            lVar5 = syscall(0xba);
            FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                         &DAT_002983c2,lVar5,"api.c",0x1419);
          }
        }
        else {
          if (*(int *)(param_1 + 0x25cfc) == 0) {
            do {
              iVar3 = FUN_00291820(param_1 + 0x25d00,1,0);
            } while (iVar3 != 0);
            if (*(int *)(param_1 + 0x25cfc) == 0) {
              lVar5 = *(long *)(param_1 + 0x256d8);
              uVar4 = 3;
              if (((lVar5 != 0) && (*(long *)(lVar5 + 200) != 0)) &&
                 (pcVar2 = *(code **)(*(long *)(lVar5 + 200) + 0x18), pcVar2 != (code *)0x0)) {
                uVar4 = (*pcVar2)(lVar5,param_1,param_1 + 0x258f8);
              }
              *(undefined4 *)(param_1 + 0x25d04) = uVar4;
              param_1[0x25cfc] = '\x01';
              param_1[0x25cfd] = '\0';
              param_1[0x25cfe] = '\0';
              param_1[0x25cff] = '\0';
            }
            FUN_00291830(param_1 + 0x25d00,0);
          }
          iVar3 = *(int *)(param_1 + 0x25d04);
          if (iVar3 == 0) {
            bVar1 = param_1[0x258f8];
            *param_2 = bVar1;
            memmove(param_2 + 4,param_1 + 0x258fc,(ulong)bVar1 * 8);
          }
          else if (1 < DAT_01216a78) {
            fVar6 = (float)FUN_002917b0(&DAT_01216a60);
            lVar5 = syscall(0xba);
            FUN_002340f0((double)(fVar6 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,"api.c",
                         0x141d,"tsapiDeviceGetBridgeChipInfo",0x141d,iVar3);
          }
        }
      }
      else {
        iVar3 = 999;
      }
    }
  }
  return iVar3;
}


// ===== 00180a60 nvmlDeviceGetBridgeChipInfo =====

int nvmlDeviceGetBridgeChipInfo(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x19b,"nvmlDeviceGetBridgeChipInfo",
                 "(nvmlDevice_t device, nvmlBridgeChipHierarchy_t *bridgeHierarchy)",param_1,param_2
                );
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00180800(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x19b,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x19b,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00180c40 FUN_00180c40 =====

int FUN_00180c40(long param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  int local_30;
  int local_2c [3];
  
  local_30 = 0;
  iVar2 = FUN_00175bd0(param_1,local_2c);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_2c[0] == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar3,"api.c",0x14f6);
        }
      }
      else if (param_2 == 0) {
        iVar2 = 2;
      }
      else {
        lVar3 = *(long *)(param_1 + 0x256d8);
        if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x98) == (undefined8 *)0x0)) ||
           (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x98), pcVar1 == (code *)0x0)) {
          iVar2 = 3;
        }
        else {
          iVar2 = (*pcVar1)(lVar3,param_1,&local_30,param_2);
          if (iVar2 == 0) {
            if (local_30 != 0) {
              return 0;
            }
            return 0xe;
          }
        }
        if (1 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,"api.c",0x14fd,
                       "tsapiDeviceGetInforomConfigurationChecksum",0x14fd,iVar2);
        }
      }
    }
    else {
      iVar2 = 999;
    }
  }
  return iVar2;
}


// ===== 00180e10 nvmlDeviceGetInforomConfigurationChecksum =====

int nvmlDeviceGetInforomConfigurationChecksum(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x1f9,"nvmlDeviceGetInforomConfigurationChecksum",
                 "(nvmlDevice_t device, unsigned int *checksum)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00180c40(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1f9,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1f9,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00180ff0 FUN_00180ff0 =====

int FUN_00180ff0(long param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  int local_30;
  int local_2c [3];
  
  local_30 = 0;
  iVar2 = FUN_00175bd0(param_1,local_2c);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_2c[0] == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar3,"api.c",0x150f);
        }
      }
      else {
        lVar3 = *(long *)(param_1 + 0x256d8);
        if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x98) == (undefined8 *)0x0)) ||
           (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x98), pcVar1 == (code *)0x0)) {
          iVar2 = 3;
        }
        else {
          iVar2 = (*pcVar1)(lVar3,param_1,&local_30,local_2c);
          if (iVar2 == 0) {
            if (local_30 != 0) {
              return 0;
            }
            return 0xe;
          }
        }
        if (1 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,"api.c",0x1512,
                       "tsapiDeviceValidateInforom",0x1512,iVar2);
        }
      }
    }
    else {
      iVar2 = 999;
    }
  }
  return iVar2;
}


// ===== 001811a0 nvmlDeviceValidateInforom =====

int nvmlDeviceValidateInforom(char *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  char *pcVar5;
  
  pcVar5 = param_1;
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    pcVar5 = "(nvmlDevice_t device)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x1fd,"nvmlDeviceValidateInforom");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_00180ff0(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1fd,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1fd,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00181370 FUN_00181370 =====

ulong FUN_00181370(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c;
  
  uVar1 = FUN_00175bd0(param_1,&local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x1523);
        }
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x98) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x98) + 8),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0018140a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2,param_3);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00181490 nvmlDeviceGetLastBBXFlushTime =====

int nvmlDeviceGetLastBBXFlushTime(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x201,"nvmlDeviceGetLastBBXFlushTime",
                 "(nvmlDevice_t device, unsigned long long *timestamp, unsigned long *durationUs)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00181370(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x201,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x201,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00181660 FUN_00181660 =====

ulong FUN_00181660(long param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  float fVar5;
  int local_1c;
  
  uVar1 = FUN_00175bd0(param_1,&local_1c);
  uVar4 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_1c == 0) {
        uVar4 = 3;
        if (3 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar3,"api.c",0x1547);
        }
      }
      else {
        iVar2 = FUN_00236dd0();
        if (iVar2 == 0) {
          uVar4 = 4;
        }
        else {
          lVar3 = *(long *)(param_1 + 0x256d8);
          if (((lVar3 != 0) && (*(undefined8 **)(lVar3 + 0xb0) != (undefined8 *)0x0)) &&
             (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar3 + 0xb0),
             UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0018175f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar4 = (*UNRECOVERED_JUMPTABLE)(lVar3,param_1,0);
            return uVar4;
          }
          uVar4 = 3;
        }
      }
    }
    else {
      uVar4 = 999;
    }
  }
  return uVar4;
}


// ===== 00181790 FUN_00181790 =====

int FUN_00181790(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0x7ca,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00181660(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x7ca,iVar1,uVar2);
  return iVar1;
}


// ===== 001818c0 FUN_001818c0 =====

int FUN_001818c0(char *param_1,ulong *param_2)

{
  long lVar1;
  code *pcVar2;
  ulong uVar3;
  int iVar4;
  undefined4 uVar5;
  int local_30;
  int local_2c [3];
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if (*param_1 != '\x01') {
    if (*(int *)(param_1 + 0x14) == 0) {
      return 2;
    }
    if (*(int *)(param_1 + 0x1c) != 0) {
      return 2;
    }
    if (*(int *)(param_1 + 0x10) == 0) {
      return 2;
    }
    if (*(long *)(param_1 + 0x20) == 0) {
      return 2;
    }
  }
  if (param_2 == (ulong *)0x0) {
    return 2;
  }
  iVar4 = FUN_00175bd0(param_1,&local_30);
  if (iVar4 == 0) {
    if (local_30 == 0) {
      *param_2 = 0;
      return 0;
    }
    if (*(int *)(param_1 + 0x71c) == 0) {
      do {
        iVar4 = FUN_00291820(param_1 + 0x720,1,0);
      } while (iVar4 != 0);
      if (*(int *)(param_1 + 0x71c) == 0) {
        lVar1 = *(long *)(param_1 + 0x256d8);
        uVar5 = 3;
        if (((lVar1 != 0) && (*(long *)(lVar1 + 0x20) != 0)) &&
           (pcVar2 = *(code **)(*(long *)(lVar1 + 0x20) + 0x98), pcVar2 != (code *)0x0)) {
          uVar5 = (*pcVar2)(lVar1,param_1,param_1 + 0x708);
        }
        *(undefined4 *)(param_1 + 0x724) = uVar5;
        param_1[0x71c] = '\x01';
        param_1[0x71d] = '\0';
        param_1[0x71e] = '\0';
        param_1[0x71f] = '\0';
      }
      FUN_00291830(param_1 + 0x720,0);
    }
    iVar4 = *(int *)(param_1 + 0x724);
    if (iVar4 == 0) {
      *param_2 = 0xc18c;
      *param_2 = (-(ulong)(*(uint *)(param_1 + 0x708) < 5) & 0xfffffffffffffff0) + 0xc19c;
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (((lVar1 != 0) && (*(long *)(lVar1 + 0x140) != 0)) &&
         ((pcVar2 = *(code **)(*(long *)(lVar1 + 0x140) + 8), pcVar2 != (code *)0x0 &&
          ((iVar4 = (*pcVar2)(lVar1,param_1,local_2c), iVar4 == 0 && (local_2c[0] == 1)))))) {
        uVar3 = *param_2;
        *param_2 = uVar3 | 0x203;
        if (*(uint *)(param_1 + 0x708) < 10) {
          return 0;
        }
        *param_2 = uVar3 | 0xe03;
      }
      if (*(uint *)(param_1 + 0x708) < 10) {
        return 0;
      }
      *param_2 = *param_2 | 0x3000;
      return 0;
    }
  }
  if (iVar4 != 0xf) {
    iVar4 = 999;
  }
  return iVar4;
}


// ===== 00181ab0 nvmlDeviceGetSupportedEventTypes =====

int nvmlDeviceGetSupportedEventTypes(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x1ab,"nvmlDeviceGetSupportedEventTypes",
                 "(nvmlDevice_t device, unsigned long long *eventTypes)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001818c0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1ab,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1ab,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00181c90 FUN_00181c90 =====

undefined8 FUN_00181c90(char *param_1,ulong param_2,long param_3)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulong local_30 [2];
  
  if (param_3 == 0) {
    return 2;
  }
  if (param_1 != (char *)0x0) {
    if (((*param_1 == '\x01') ||
        ((((uVar3 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
          (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) &&
       (uVar3 = 0, param_2 != 0)) {
      uVar3 = FUN_001818c0(param_1,local_30);
      if ((int)uVar3 == 0) {
        local_30[0] = ~-(uint)(*(uint *)(param_1 + 0x708) < 8) & 0x60 | local_30[0];
        uVar3 = 3;
        if ((((~local_30[0] & param_2) == 0) && (lVar1 = *(long *)(param_1 + 0x256d8), lVar1 != 0))
           && ((*(long *)(lVar1 + 0x130) != 0 &&
               (pcVar2 = *(code **)(*(long *)(lVar1 + 0x130) + 8), pcVar2 != (code *)0x0)))) {
          uVar3 = (*pcVar2)(lVar1,param_1,param_2,param_3);
        }
      }
    }
    return uVar3;
  }
  return 2;
}


// ===== 00181d80 nvmlDeviceRegisterEvents =====

int nvmlDeviceRegisterEvents(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %llu, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x1a7,"nvmlDeviceRegisterEvents",
                 "(nvmlDevice_t device, unsigned long long eventTypes, nvmlEventSet_t set)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00181c90(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1a7,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1a7,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00181f50 FUN_00181f50 =====

ulong FUN_00181f50(char *param_1,long param_2,long param_3,long param_4)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_3c [3];
  
  if ((param_1 == (char *)0x0) ||
     (((*param_1 != '\x01' &&
       ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
         (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) ||
      ((param_3 == 0 || param_4 == 0 || (param_2 == 0)))))) {
    uVar3 = 2;
  }
  else {
    uVar1 = FUN_00175bd0(param_1,local_3c);
    uVar3 = (ulong)uVar1;
    if ((uVar1 != 2) && (uVar1 != 0xf)) {
      if (uVar1 == 0) {
        if (local_3c[0] != 0) {
          uVar3 = FUN_0014a800(param_1,param_2,param_3,param_4);
          return uVar3;
        }
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x169a);
        }
      }
      else {
        uVar3 = 999;
      }
    }
  }
  return uVar3;
}


// ===== 00182090 FUN_00182090 =====

int FUN_00182090(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x8d2,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00181f50(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x8d2,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001821e0 FUN_001821e0 =====

undefined8
FUN_001821e0(undefined4 param_1,char *param_2,undefined4 param_3,long param_4,undefined8 param_5)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  int local_3c [3];
  
  iVar1 = FUN_00175bd0(param_2,local_3c);
  if (iVar1 == 2) {
    return 2;
  }
  if (iVar1 == 0xf) {
    return 0xf;
  }
  if (iVar1 != 0) {
    return 999;
  }
  if (local_3c[0] == 0) {
    if (DAT_01216a78 < 4) {
      return 3;
    }
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar3,"api.c",0x16c2);
    return 3;
  }
  if ((param_2 == (char *)0x0) || (param_4 == 0)) {
LAB_00182350:
    uVar2 = 2;
  }
  else {
    if (*param_2 != '\x01') {
      if (*(long *)(param_2 + 0x20) == 0) {
        uVar2 = FUN_001377c0(param_1,param_2,param_3,param_4,param_5);
        return uVar2;
      }
      if (((*(int *)(param_2 + 0x14) == 0) || (*(int *)(param_2 + 0x1c) != 0)) ||
         (*(int *)(param_2 + 0x10) == 0)) goto LAB_00182350;
    }
    lVar3 = *(long *)(param_2 + 0x256d8);
    if (((lVar3 != 0) && (*(undefined8 **)(lVar3 + 0xc0) != (undefined8 *)0x0)) &&
       (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar3 + 0xc0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001822d3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar3,param_2,param_1,param_3,param_4,param_5);
      return uVar2;
    }
    uVar2 = 3;
  }
  return uVar2;
}


// ===== 00182390 FUN_00182390 =====

void FUN_00182390(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_001821e0(1,param_1,0,param_2,param_3);
  return;
}


// ===== 001823b0 nvmlDeviceGetComputeRunningProcesses =====

int nvmlDeviceGetComputeRunningProcesses(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x1cd,"nvmlDeviceGetComputeRunningProcesses",
                 "(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_v1_t *infos)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00182390(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1cd,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1cd,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00182580 FUN_00182580 =====

void FUN_00182580(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_001821e0(2,param_1,0,param_2,param_3);
  return;
}


// ===== 001825a0 nvmlDeviceGetComputeRunningProcesses_v2 =====

int nvmlDeviceGetComputeRunningProcesses_v2
              (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x1d1,"nvmlDeviceGetComputeRunningProcesses_v2",
                 "(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_t *infos)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00182580(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1d1,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1d1,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00182770 FUN_00182770 =====

void FUN_00182770(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_001821e0(1,param_1,1,param_2,param_3);
  return;
}


// ===== 00182790 nvmlDeviceGetGraphicsRunningProcesses =====

int nvmlDeviceGetGraphicsRunningProcesses(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x1d9,"nvmlDeviceGetGraphicsRunningProcesses",
                 "(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_v1_t *infos)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00182770(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1d9,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1d9,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00182960 FUN_00182960 =====

void FUN_00182960(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_001821e0(2,param_1,1,param_2,param_3);
  return;
}


// ===== 00182980 nvmlDeviceGetGraphicsRunningProcesses_v2 =====

int nvmlDeviceGetGraphicsRunningProcesses_v2
              (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x1dd,"nvmlDeviceGetGraphicsRunningProcesses_v2",
                 "(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_t *infos)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00182960(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1dd,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1dd,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00182b50 FUN_00182b50 =====

void FUN_00182b50(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_001821e0(1,param_1,2,param_2,param_3);
  return;
}


// ===== 00182b70 nvmlDeviceGetMPSComputeRunningProcesses =====

int nvmlDeviceGetMPSComputeRunningProcesses
              (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x1e5,"nvmlDeviceGetMPSComputeRunningProcesses",
                 "(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_v1_t *infos)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00182b50(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1e5,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1e5,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00182d40 FUN_00182d40 =====

void FUN_00182d40(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_001821e0(2,param_1,2,param_2,param_3);
  return;
}


// ===== 00182d60 nvmlDeviceGetMPSComputeRunningProcesses_v2 =====

int nvmlDeviceGetMPSComputeRunningProcesses_v2
              (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x1e9,"nvmlDeviceGetMPSComputeRunningProcesses_v2",
                 "(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_t *infos)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00182d40(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1e9,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1e9,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00182f30 FUN_00182f30 =====

void FUN_00182f30(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_001821e0(2,param_1,0,param_2,param_3);
  return;
}


// ===== 00182f50 nvmlDeviceGetComputeRunningProcesses_v3 =====

int nvmlDeviceGetComputeRunningProcesses_v3
              (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x1d5,"nvmlDeviceGetComputeRunningProcesses_v3",
                 "(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_t *infos)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00182f30(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1d5,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1d5,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00183120 FUN_00183120 =====

void FUN_00183120(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_001821e0(2,param_1,1,param_2,param_3);
  return;
}


// ===== 00183140 nvmlDeviceGetGraphicsRunningProcesses_v3 =====

int nvmlDeviceGetGraphicsRunningProcesses_v3
              (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x1e1,"nvmlDeviceGetGraphicsRunningProcesses_v3",
                 "(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_t *infos)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00183120(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1e1,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1e1,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00183310 FUN_00183310 =====

void FUN_00183310(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_001821e0(2,param_1,2,param_2,param_3);
  return;
}


// ===== 00183330 nvmlDeviceGetMPSComputeRunningProcesses_v3 =====

int nvmlDeviceGetMPSComputeRunningProcesses_v3
              (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x1ed,"nvmlDeviceGetMPSComputeRunningProcesses_v3",
                 "(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_t *infos)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00183310(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1ed,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1ed,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00183500 FUN_00183500 =====

undefined8 FUN_00183500(char *param_1,int *param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  int local_2c [3];
  
  iVar1 = FUN_00175bd0(param_1,local_2c);
  if (iVar1 == 2) {
    return 2;
  }
  if (iVar1 == 0xf) {
    return 0xf;
  }
  if (iVar1 != 0) {
    return 999;
  }
  if (local_2c[0] == 0) {
    if (3 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar3,"api.c",0x1724);
      return 3;
    }
    return 3;
  }
  if ((param_2 != (int *)0x0) && ((uint)param_2[1] < 3)) {
    if (*param_2 != 0x1000018) {
      return 0x19;
    }
    if (param_1 != (char *)0x0) {
      if (*param_1 != '\x01') {
        if (*(long *)(param_1 + 0x20) == 0) {
          uVar2 = FUN_001378e0(param_1,param_2);
          return uVar2;
        }
        if (*(int *)(param_1 + 0x14) == 0) {
          return 2;
        }
        if (*(int *)(param_1 + 0x1c) != 0) {
          return 2;
        }
        if (*(int *)(param_1 + 0x10) == 0) {
          return 2;
        }
      }
      lVar3 = *(long *)(param_1 + 0x256d8);
      if (((lVar3 != 0) && (*(long *)(lVar3 + 0xc0) != 0)) &&
         (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar3 + 0xc0) + 0x28),
         UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001835f3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar3,param_1,param_2);
        return uVar2;
      }
      return 3;
    }
  }
  return 2;
}


// ===== 001836b0 nvmlDeviceGetRunningProcessDetailList =====

int nvmlDeviceGetRunningProcessDetailList(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0xad9,"nvmlDeviceGetRunningProcessDetailList",
                 "(nvmlDevice_t device, nvmlProcessDetailList_t *plist)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00183500(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xad9,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xad9,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00183890 FUN_00183890 =====

ulong FUN_00183890(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c;
  
  uVar1 = FUN_00175bd0(param_1,&local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x17b4);
        }
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x160) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x160) + 0x38),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0018392a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2,param_3);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 001839b0 nvmlDeviceGetGpuOperationMode =====

int nvmlDeviceGetGpuOperationMode(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x205,"nvmlDeviceGetGpuOperationMode",
                 "(nvmlDevice_t device, nvmlGpuOperationMode_t *current, nvmlGpuOperationMode_t *pending)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00183890(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x205,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x205,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00183b80 FUN_00183b80 =====

int FUN_00183b80(long param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  int local_34;
  int local_30;
  int local_2c [3];
  
  local_34 = 0;
  local_30 = 0;
  iVar2 = FUN_00175bd0(param_1,local_2c);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_2c[0] == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar4,"api.c",0x17c1);
        }
      }
      else {
        iVar3 = FUN_00156500(param_1,&local_34);
        if (((iVar3 == 0) || (iVar2 = iVar3, iVar3 == 3)) &&
           ((iVar2 = FUN_00156760(param_1,&local_30), iVar2 == 0 || (iVar2 == 3)))) {
          if ((((iVar3 != 0) || (local_34 == 0)) && ((iVar2 != 0 || (local_30 == 0)))) ||
             ((param_2 & 0xfffffffd) == 0)) {
            iVar2 = FUN_00236dd0();
            if (iVar2 == 0) {
              return 4;
            }
            lVar4 = *(long *)(param_1 + 0x256d8);
            if (((lVar4 != 0) && (*(long *)(lVar4 + 0x160) != 0)) &&
               (pcVar1 = *(code **)(*(long *)(lVar4 + 0x160) + 0x48), pcVar1 != (code *)0x0)) {
              iVar2 = (*pcVar1)(lVar4,param_1,param_2);
              return iVar2;
            }
          }
          iVar2 = 3;
        }
      }
    }
    else {
      iVar2 = 999;
    }
  }
  return iVar2;
}


// ===== 00183d10 nvmlDeviceSetGpuOperationMode =====

int nvmlDeviceSetGpuOperationMode(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x20f,"nvmlDeviceSetGpuOperationMode",
                 "(nvmlDevice_t device, nvmlGpuOperationMode_t mode)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00183b80(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x20f,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x20f,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00183ef0 FUN_00183ef0 =====

int FUN_00183ef0(char *param_1,long param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  int local_30;
  int local_2c;
  
  local_30 = 0;
  iVar2 = FUN_00175bd0(param_1,&local_2c);
  if (iVar2 == 2) {
    return 2;
  }
  if (iVar2 == 0xf) {
    return 0xf;
  }
  if (iVar2 != 0) {
    return 999;
  }
  if (local_2c == 0) {
    if (3 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar3,"api.c",0x19fa);
      return 3;
    }
    return 3;
  }
  if (param_1 != (char *)0x0) {
    if (*param_1 != '\x01') {
      if (*(int *)(param_1 + 0x14) == 0) {
        return 2;
      }
      if (*(int *)(param_1 + 0x1c) != 0) {
        return 2;
      }
      if (*(int *)(param_1 + 0x10) == 0) {
        return 2;
      }
      if (*(long *)(param_1 + 0x20) == 0) {
        return 2;
      }
    }
    if (param_2 != 0) {
      iVar2 = FUN_00139230(param_1,&local_30,7);
      if (iVar2 != 0) {
        return iVar2;
      }
      if (local_30 != 0) {
        if (4 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       "DEBUG",lVar3,"api.c",0x1a09);
          return 3;
        }
        return 3;
      }
      lVar3 = *(long *)(param_1 + 0x256d8);
      if (((lVar3 != 0) && (*(long *)(lVar3 + 0x170) != 0)) &&
         (pcVar1 = *(code **)(*(long *)(lVar3 + 0x170) + 0x170), pcVar1 != (code *)0x0)) {
        iVar2 = (*pcVar1)(lVar3,param_1,param_2,param_3);
        return iVar2;
      }
      return 3;
    }
  }
  return 2;
}


// ===== 001840f0 nvmlDeviceGetAutoBoostedClocksEnabled =====

int nvmlDeviceGetAutoBoostedClocksEnabled(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x24c,"nvmlDeviceGetAutoBoostedClocksEnabled",
                 "(nvmlDevice_t device, nvmlEnableState_t *isEnabled, nvmlEnableState_t *defaultIsEnabled)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00183ef0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x24c,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x24c,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001842c0 FUN_001842c0 =====

int FUN_001842c0(char *param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  int local_38;
  int local_34;
  int local_30;
  int local_2c [3];
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  iVar2 = FUN_00175bd0(param_1,local_2c);
  if (iVar2 == 2) {
    return 2;
  }
  if (iVar2 == 0xf) {
    return 0xf;
  }
  if (iVar2 != 0) {
    return 999;
  }
  if (local_2c[0] == 0) {
    if (3 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar3,"api.c",0x1a1c);
      return 3;
    }
    return 3;
  }
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if (*param_1 != '\x01') {
    if (*(int *)(param_1 + 0x14) == 0) {
      return 2;
    }
    if (*(int *)(param_1 + 0x1c) != 0) {
      return 2;
    }
    if (*(int *)(param_1 + 0x10) == 0) {
      return 2;
    }
    if (*(long *)(param_1 + 0x20) == 0) {
      return 2;
    }
  }
  if (1 < param_2) {
    return 2;
  }
  iVar2 = FUN_00139230(param_1,&local_30,7);
  if (iVar2 != 0) {
    return iVar2;
  }
  if (local_30 != 0) {
    if (DAT_01216a78 < 5) {
      return 3;
    }
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                 lVar3,"api.c",0x1a2b);
    return 3;
  }
  iVar2 = FUN_00156500(param_1,&local_38);
  if (iVar2 == 0) {
    if (local_38 == 0) {
      return 3;
    }
    iVar2 = FUN_00156380(param_1,&local_34);
    if (iVar2 != 0) {
      return iVar2;
    }
    if (local_34 == 0) {
      return 3;
    }
  }
  else if (iVar2 != 3) {
    return iVar2;
  }
  lVar3 = *(long *)(param_1 + 0x256d8);
  if (((lVar3 != 0) && (*(long *)(lVar3 + 0x170) != 0)) &&
     (pcVar1 = *(code **)(*(long *)(lVar3 + 0x170) + 0x178), pcVar1 != (code *)0x0)) {
    iVar2 = (*pcVar1)(lVar3,param_1,param_2);
    return iVar2;
  }
  return 3;
}


// ===== 00184520 nvmlDeviceSetAutoBoostedClocksEnabled =====

int nvmlDeviceSetAutoBoostedClocksEnabled(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x250,"nvmlDeviceSetAutoBoostedClocksEnabled",
                 "(nvmlDevice_t device, nvmlEnableState_t enabled)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001842c0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x250,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x250,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00184700 FUN_00184700 =====

int FUN_00184700(char *param_1,uint param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  iVar2 = FUN_00175bd0(param_1,&local_2c);
  if (iVar2 == 2) {
    return 2;
  }
  if (iVar2 == 0xf) {
    return 0xf;
  }
  if (iVar2 != 0) {
    return 999;
  }
  if (local_2c == 0) {
    if (3 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar3,"api.c",0x1a53);
      return 3;
    }
    return 3;
  }
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if (*param_1 != '\x01') {
    if (*(int *)(param_1 + 0x14) == 0) {
      return 2;
    }
    if (*(int *)(param_1 + 0x1c) != 0) {
      return 2;
    }
    if (*(int *)(param_1 + 0x10) == 0) {
      return 2;
    }
    if (*(long *)(param_1 + 0x20) == 0) {
      return 2;
    }
  }
  if (1 < param_2) {
    return 2;
  }
  iVar2 = FUN_00139230(param_1,&local_30,7);
  if (iVar2 != 0) {
    return iVar2;
  }
  if (local_30 != 0) {
    if (DAT_01216a78 < 5) {
      return 3;
    }
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                 lVar3,"api.c",0x1a62);
    return 3;
  }
  iVar2 = FUN_00156500(param_1,&local_38);
  if (iVar2 == 0) {
    if (local_38 == 0) {
      return 3;
    }
    iVar2 = FUN_00156380(param_1,&local_34);
    if (iVar2 != 0) {
      return iVar2;
    }
    if (local_34 == 0) {
      return 3;
    }
  }
  else if (iVar2 != 3) {
    return iVar2;
  }
  lVar3 = *(long *)(param_1 + 0x256d8);
  if (((lVar3 != 0) && (*(long *)(lVar3 + 0x170) != 0)) &&
     (pcVar1 = *(code **)(*(long *)(lVar3 + 0x170) + 0x180), pcVar1 != (code *)0x0)) {
    iVar2 = (*pcVar1)(lVar3,param_1,param_2,param_3);
    return iVar2;
  }
  return 3;
}


// ===== 00184960 nvmlDeviceSetDefaultAutoBoostedClocksEnabled =====

int nvmlDeviceSetDefaultAutoBoostedClocksEnabled
              (undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d, 0x%x)\n","DEBUG",lVar3,
                 "entry_points.h",0x254,"nvmlDeviceSetDefaultAutoBoostedClocksEnabled",
                 "(nvmlDevice_t device, nvmlEnableState_t enabled, unsigned int flags)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00184700(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x254,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x254,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00184b30 FUN_00184b30 =====

ulong FUN_00184b30(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x1b1b);
        }
      }
      else if (param_2 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x148) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x148) + 8),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00184bc6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00184c60 nvmlDeviceGetCurrentClocksEventReasons =====

int nvmlDeviceGetCurrentClocksEventReasons(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x268,"nvmlDeviceGetCurrentClocksEventReasons",
                 "(nvmlDevice_t device, unsigned long long *clocksEventReasons)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00184b30(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x268,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x268,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00184e40 thunk_FUN_00184b30 =====

ulong thunk_FUN_00184b30(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int aiStack_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,aiStack_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (aiStack_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x1b1b);
        }
      }
      else if (param_2 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x148) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x148) + 8),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00184bc6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00184e50 nvmlDeviceGetCurrentClocksThrottleReasons =====

int nvmlDeviceGetCurrentClocksThrottleReasons(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x264,"nvmlDeviceGetCurrentClocksThrottleReasons",
                 "(nvmlDevice_t device, unsigned long long *clocksThrottleReasons)",param_1,param_2)
    ;
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_00184b30(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x264,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x264,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00185030 FUN_00185030 =====

ulong FUN_00185030(long param_1,undefined8 *param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  ulong uVar5;
  int local_2c [3];
  
  if (param_2 == (undefined8 *)0x0) {
    return 2;
  }
  uVar5 = FUN_00175bd0(param_1,local_2c);
  if ((int)uVar5 == 0) {
    if (local_2c[0] == 0) {
      *param_2 = 0;
      return 0;
    }
    if (*(int *)(param_1 + 0x660) == 0) {
      do {
        iVar3 = FUN_00291820(param_1 + 0x664,1,0);
      } while (iVar3 != 0);
      if (*(int *)(param_1 + 0x660) == 0) {
        lVar1 = *(long *)(param_1 + 0x256d8);
        uVar4 = 3;
        if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0x148) != (undefined8 *)0x0)) &&
           (pcVar2 = (code *)**(undefined8 **)(lVar1 + 0x148), pcVar2 != (code *)0x0)) {
          uVar4 = (*pcVar2)(lVar1,param_1,param_1 + 0x658);
        }
        *(undefined4 *)(param_1 + 0x668) = uVar4;
        *(undefined4 *)(param_1 + 0x660) = 1;
      }
      FUN_00291830(param_1 + 0x664,0);
    }
    uVar5 = (ulong)*(uint *)(param_1 + 0x668);
    *param_2 = *(undefined8 *)(param_1 + 0x658);
  }
  return uVar5;
}


// ===== 00185140 nvmlDeviceGetSupportedClocksEventReasons =====

int nvmlDeviceGetSupportedClocksEventReasons(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x270,"nvmlDeviceGetSupportedClocksEventReasons",
                 "(nvmlDevice_t device, unsigned long long *supportedClocksEventReasons)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00185030(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x270,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x270,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00185320 thunk_FUN_00185030 =====

ulong thunk_FUN_00185030(long param_1,undefined8 *param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  ulong uVar5;
  int aiStack_2c [3];
  
  if (param_2 == (undefined8 *)0x0) {
    return 2;
  }
  uVar5 = FUN_00175bd0(param_1,aiStack_2c);
  if ((int)uVar5 == 0) {
    if (aiStack_2c[0] == 0) {
      *param_2 = 0;
      return 0;
    }
    if (*(int *)(param_1 + 0x660) == 0) {
      do {
        iVar3 = FUN_00291820(param_1 + 0x664,1,0);
      } while (iVar3 != 0);
      if (*(int *)(param_1 + 0x660) == 0) {
        lVar1 = *(long *)(param_1 + 0x256d8);
        uVar4 = 3;
        if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0x148) != (undefined8 *)0x0)) &&
           (pcVar2 = (code *)**(undefined8 **)(lVar1 + 0x148), pcVar2 != (code *)0x0)) {
          uVar4 = (*pcVar2)(lVar1,param_1,param_1 + 0x658);
        }
        *(undefined4 *)(param_1 + 0x668) = uVar4;
        *(undefined4 *)(param_1 + 0x660) = 1;
      }
      FUN_00291830(param_1 + 0x664,0);
    }
    uVar5 = (ulong)*(uint *)(param_1 + 0x668);
    *param_2 = *(undefined8 *)(param_1 + 0x658);
  }
  return uVar5;
}


// ===== 00185330 nvmlDeviceGetSupportedClocksThrottleReasons =====

int nvmlDeviceGetSupportedClocksThrottleReasons(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x26c,"nvmlDeviceGetSupportedClocksThrottleReasons",
                 "(nvmlDevice_t device, unsigned long long *supportedClocksThrottleReasons)",param_1
                 ,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_00185030(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x26c,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x26c,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00185510 FUN_00185510 =====

int FUN_00185510(long param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  undefined8 local_80;
  int local_78 [20];
  
  iVar2 = FUN_00175bd0(param_1,local_78);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_78[0] == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar4,"api.c",0x1c79);
        }
      }
      else {
        iVar3 = FUN_00236dd0();
        iVar2 = 4;
        if (iVar3 != 0) {
          iVar2 = thunk_FUN_00236fb0();
          if (iVar2 == 0) {
            iVar2 = thunk_FUN_00237550(*(undefined4 *)(param_1 + 8),*(undefined2 *)(param_1 + 0xc),
                                       *(undefined2 *)(param_1 + 0xe),0,&local_80);
            if (iVar2 == 0) {
              iVar2 = FUN_0013ea40(param_1,local_78);
              if (iVar2 == 0) {
                if (((DAT_012164a0 == 0) ||
                    (*(undefined8 **)(DAT_012164a0 + 0x138) == (undefined8 *)0x0)) ||
                   (pcVar1 = (code *)**(undefined8 **)(DAT_012164a0 + 0x138), pcVar1 == (code *)0x0)
                   ) {
                  iVar2 = 3;
                }
                else {
                  iVar2 = (*pcVar1)(DAT_012164a0,local_78,1);
                  if (iVar2 == 0) {
                    lVar4 = *(long *)(param_1 + 0x256d8);
                    if (((lVar4 != 0) && (*(long *)(lVar4 + 0x20) != 0)) &&
                       (pcVar1 = *(code **)(*(long *)(lVar4 + 0x20) + 0x18), pcVar1 != (code *)0x0))
                    {
                      (*pcVar1)(lVar4,param_1);
                    }
                    iVar2 = FUN_002389b0(local_80);
                    if (iVar2 == 0) {
                      usleep(150000);
                    }
                    if (((DAT_012164a0 != 0) &&
                        (*(undefined8 **)(DAT_012164a0 + 0x138) != (undefined8 *)0x0)) &&
                       (pcVar1 = (code *)**(undefined8 **)(DAT_012164a0 + 0x138),
                       pcVar1 != (code *)0x0)) {
                      (*pcVar1)(DAT_012164a0,local_78,0);
                    }
                  }
                }
              }
            }
            thunk_FUN_00237220();
          }
        }
      }
    }
    else {
      iVar2 = 999;
    }
  }
  return iVar2;
}


// ===== 001856f0 FUN_001856f0 =====

int FUN_001856f0(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0x865,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00185510(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x865,iVar1,uVar2);
  return iVar1;
}


// ===== 00185820 FUN_00185820 =====

undefined8 FUN_00185820(char *param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_2 != 0)))
     ) {
    uVar1 = FUN_00175bd0();
    return uVar1;
  }
  return 2;
}


// ===== 00185860 FUN_00185860 =====

int FUN_00185860(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x86d,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00185820(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x86d,iVar1,uVar2);
  return iVar1;
}


// ===== 001859a0 FUN_001859a0 =====

ulong FUN_001859a0(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x1d81);
        }
      }
      else if (param_2 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(undefined8 **)(lVar2 + 0x70) != (undefined8 *)0x0)) &&
           (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar2 + 0x70),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00185a34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,0,param_2);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00185ad0 nvmlDeviceGetAccountingMode =====

int nvmlDeviceGetAccountingMode(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x278,"nvmlDeviceGetAccountingMode",
                 "(nvmlDevice_t device, nvmlEnableState_t * mode)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001859a0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x278,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x278,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00185cb0 FUN_00185cb0 =====

ulong FUN_00185cb0(long param_1,undefined4 param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x1d91);
        }
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x70) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x70) + 8),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00185d3a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00185dc0 nvmlDeviceSetAccountingMode =====

int nvmlDeviceSetAccountingMode(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x27c,"nvmlDeviceSetAccountingMode",
                 "(nvmlDevice_t device, nvmlEnableState_t mode)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00185cb0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x27c,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x27c,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00185fa0 FUN_00185fa0 =====

undefined8 FUN_00185fa0(long param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  float fVar4;
  uint local_2c [3];
  
  iVar1 = FUN_00175bd0(param_1,local_2c);
  if (iVar1 == 2) {
    return 2;
  }
  if (iVar1 == 0xf) {
    return 0xf;
  }
  if (iVar1 != 0) {
    return 999;
  }
  if (local_2c[0] != 0) {
    lVar2 = *(long *)(param_1 + 0x256d8);
    local_2c[0] = local_2c[0] & 0xffffff00;
    if (lVar2 != 0) {
      if ((*(long *)(lVar2 + 0x38) != 0) &&
         (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x38) + 0x80),
         UNRECOVERED_JUMPTABLE != (code *)0x0)) {
        (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,local_2c);
        if ((char)local_2c[0] != '\0') {
          return 3;
        }
        lVar2 = *(long *)(param_1 + 0x256d8);
      }
      if (((lVar2 != 0) && (*(long *)(lVar2 + 0x70) != 0)) &&
         (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x70) + 0x28),
         UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001860c1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,0);
        return uVar3;
      }
    }
    return 3;
  }
  if (3 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar2,"api.c",0x1d98);
    return 3;
  }
  return 3;
}


// ===== 001860e0 nvmlDeviceClearAccountingPids =====

int nvmlDeviceClearAccountingPids(char *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  char *pcVar5;
  
  pcVar5 = param_1;
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    pcVar5 = "(nvmlDevice_t device)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x280,"nvmlDeviceClearAccountingPids");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_00185fa0(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x280,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x280,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001862b0 FUN_001862b0 =====

undefined8 FUN_001862b0(long param_1,undefined4 param_2,long param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  uint local_3c [3];
  
  iVar1 = FUN_00175bd0(param_1,local_3c);
  if (iVar1 == 2) {
    return 2;
  }
  if (iVar1 == 0xf) {
    return 0xf;
  }
  if (iVar1 != 0) {
    return 999;
  }
  if (local_3c[0] != 0) {
    if (param_3 == 0) {
      return 2;
    }
    lVar3 = *(long *)(param_1 + 0x256d8);
    local_3c[0] = local_3c[0] & 0xffffff00;
    if (lVar3 != 0) {
      if ((*(long *)(lVar3 + 0x38) != 0) &&
         (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar3 + 0x38) + 0x80),
         UNRECOVERED_JUMPTABLE != (code *)0x0)) {
        (*UNRECOVERED_JUMPTABLE)(lVar3,param_1,local_3c);
        if ((char)local_3c[0] != '\0') {
          return 3;
        }
        lVar3 = *(long *)(param_1 + 0x256d8);
      }
      if (((lVar3 != 0) && (*(long *)(lVar3 + 0x70) != 0)) &&
         (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar3 + 0x70) + 0x10),
         UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00186392. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar3,param_1,0,param_2,param_3);
        return uVar2;
      }
    }
    return 3;
  }
  if (3 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar3,"api.c",0x1da4);
    return 3;
  }
  return 3;
}


// ===== 00186430 nvmlDeviceGetAccountingStats =====

int nvmlDeviceGetAccountingStats(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x284,"nvmlDeviceGetAccountingStats",
                 "(nvmlDevice_t device, unsigned int pid, nvmlAccountingStats_t * stats)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001862b0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x284,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x284,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00186600 FUN_00186600 =====

undefined8 FUN_00186600(long param_1,long param_2,undefined8 param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  uint local_3c [3];
  
  iVar1 = FUN_00175bd0(param_1,local_3c);
  if (iVar1 == 2) {
    return 2;
  }
  if (iVar1 == 0xf) {
    return 0xf;
  }
  if (iVar1 != 0) {
    return 999;
  }
  if (local_3c[0] != 0) {
    if (param_2 == 0) {
      return 2;
    }
    lVar3 = *(long *)(param_1 + 0x256d8);
    local_3c[0] = local_3c[0] & 0xffffff00;
    if (lVar3 != 0) {
      if ((*(long *)(lVar3 + 0x38) != 0) &&
         (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar3 + 0x38) + 0x80),
         UNRECOVERED_JUMPTABLE != (code *)0x0)) {
        (*UNRECOVERED_JUMPTABLE)(lVar3,param_1,local_3c);
        if ((char)local_3c[0] != '\0') {
          return 3;
        }
        lVar3 = *(long *)(param_1 + 0x256d8);
      }
      if (((lVar3 != 0) && (*(long *)(lVar3 + 0x70) != 0)) &&
         (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar3 + 0x70) + 0x18),
         UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001866e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar3,param_1,0,param_2,param_3);
        return uVar2;
      }
    }
    return 3;
  }
  if (3 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar3,"api.c",0x1db3);
    return 3;
  }
  return 3;
}


// ===== 00186780 nvmlDeviceGetAccountingPids =====

int nvmlDeviceGetAccountingPids(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x288,"nvmlDeviceGetAccountingPids",
                 "(nvmlDevice_t device, unsigned int *count, unsigned int *pids)",param_1,param_2,
                 param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00186600(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x288,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x288,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00186950 FUN_00186950 =====

ulong FUN_00186950(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x1dc2);
        }
      }
      else if (param_2 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x70) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x70) + 0x20),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001869e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00186a80 nvmlDeviceGetAccountingBufferSize =====

int nvmlDeviceGetAccountingBufferSize(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x28c,"nvmlDeviceGetAccountingBufferSize",
                 "(nvmlDevice_t device, unsigned int *bufferSize)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00186950(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x28c,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x28c,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00186c60 FUN_00186c60 =====

ulong FUN_00186c60(long param_1,uint param_2,long param_3,undefined8 param_4,undefined8 param_5)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_3c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_3c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_3c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x1f1b);
        }
      }
      else if ((param_2 < 2) && (param_3 != 0)) {
        uVar1 = FUN_00139690(param_1,local_3c);
        uVar3 = (ulong)uVar1;
        if (uVar1 == 0) {
          if ((((local_3c[0] != 0) && (lVar2 = *(long *)(param_1 + 0x256d8), lVar2 != 0)) &&
              (*(long *)(lVar2 + 0x140) != 0)) &&
             (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x140) + 0x98),
             UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00186d4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2,param_3,param_4,param_5);
            return uVar3;
          }
          uVar3 = 3;
        }
      }
      else {
        uVar3 = 2;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00186df0 nvmlDeviceGetRetiredPages_v2 =====

int nvmlDeviceGetRetiredPages_v2
              (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %u, %p, %p, %p)\n","DEBUG",
                 lVar3,"entry_points.h",0x294,"nvmlDeviceGetRetiredPages_v2",
                 "(nvmlDevice_t device, nvmlPageRetirementCause_t sourceFilter, unsigned int *count, unsigned long long *addresses, unsigned long long *timestamps)"
                 ,param_1,param_2,param_3,param_4,param_5);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00186c60(param_1,param_2,param_3,param_4,param_5);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x294,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x294,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00186fe0 FUN_00186fe0 =====

void FUN_00186fe0(void)

{
  FUN_00186c60();
  return;
}


// ===== 00186ff0 nvmlDeviceGetRetiredPages =====

int nvmlDeviceGetRetiredPages
              (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %u, %p, %p)\n","DEBUG",lVar3
                 ,"entry_points.h",0x290,"nvmlDeviceGetRetiredPages",
                 "(nvmlDevice_t device, nvmlPageRetirementCause_t sourceFilter, unsigned int *count, unsigned long long *addresses)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00186fe0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x290,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x290,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001871e0 FUN_001871e0 =====

ulong FUN_001871e0(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c;
  
  uVar1 = FUN_00175bd0(param_1,&local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x1f2d);
        }
      }
      else if (param_2 == 0) {
        uVar3 = 2;
      }
      else {
        uVar1 = FUN_00139690(param_1,&local_2c);
        uVar3 = (ulong)uVar1;
        if (uVar1 == 0) {
          if ((((local_2c != 0) && (lVar2 = *(long *)(param_1 + 0x256d8), lVar2 != 0)) &&
              (*(long *)(lVar2 + 0x140) != 0)) &&
             (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x140) + 0xa0),
             UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001872a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
            return uVar3;
          }
          uVar3 = 3;
        }
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00187340 nvmlDeviceGetRetiredPagesPendingStatus =====

int nvmlDeviceGetRetiredPagesPendingStatus(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x298,"nvmlDeviceGetRetiredPagesPendingStatus",
                 "(nvmlDevice_t device, nvmlEnableState_t *isPending)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001871e0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x298,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x298,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00187520 FUN_00187520 =====

int FUN_00187520(long param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  int local_2c [3];
  
  iVar2 = FUN_00175bd0(param_1,local_2c);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_2c[0] == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar3,"api.c",0x1f5c);
        }
      }
      else if (param_2 == 0) {
        iVar2 = 2;
      }
      else {
        lVar3 = *(long *)(param_1 + 0x256d8);
        if (((lVar3 == 0) || (*(long *)(lVar3 + 0x160) == 0)) ||
           (pcVar1 = *(code **)(*(long *)(lVar3 + 0x160) + 0x30), pcVar1 == (code *)0x0)) {
          iVar2 = 3;
        }
        else {
          iVar2 = (*pcVar1)(lVar3,param_1,0,0,0,0,0,param_2);
        }
      }
    }
    else {
      iVar2 = 999;
    }
  }
  return iVar2;
}


// ===== 00187650 nvmlDeviceGetEnforcedPowerLimit =====

int nvmlDeviceGetEnforcedPowerLimit(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x2a9,"nvmlDeviceGetEnforcedPowerLimit",
                 "(nvmlDevice_t device, unsigned int *limit)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00187520(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2a9,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2a9,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00187830 FUN_00187830 =====

ulong FUN_00187830(char *param_1,uint param_2,undefined8 param_3,undefined4 *param_4,int *param_5,
                  long param_6)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  float fVar5;
  int local_3c [3];
  
  if ((param_1 == (char *)0x0) ||
     ((*param_1 != '\x01' &&
      ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
        (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))))) {
    return 2;
  }
  iVar1 = FUN_00175bd0(param_1,local_3c);
  if (iVar1 == 2) {
    return 2;
  }
  if (iVar1 == 0xf) {
    return 0xf;
  }
  if (iVar1 != 0) {
    return 999;
  }
  if (local_3c[0] == 0) {
    if (DAT_01216a78 < 4) {
      return 3;
    }
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar4,"api.c",0x2006);
    return 3;
  }
  if (param_5 == (int *)0x0) {
    return 2;
  }
  if ((param_6 != 0) && (*param_5 == 0)) {
    return 2;
  }
  if (param_2 < 7) {
    if (4 < param_2) {
      *param_4 = 1;
      lVar4 = *(long *)(param_1 + 0x256d8);
      if (lVar4 == 0) {
        return 3;
      }
      if (*(long *)(lVar4 + 0x170) == 0) {
        return 3;
      }
      UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar4 + 0x170) + 0x188);
      goto joined_r0x001879d9;
    }
    if (param_2 == 0) {
      *param_4 = 1;
      lVar4 = *(long *)(param_1 + 0x256d8);
      if (lVar4 == 0) {
        return 3;
      }
      if (*(long *)(lVar4 + 0x160) == 0) {
        return 3;
      }
      UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar4 + 0x160) + 0xd0);
      if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
        return 3;
      }
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar4,param_1,0,0,param_3,param_5,param_6);
      return (ulong)uVar2;
    }
  }
  else if (1 < param_2 - 8) {
    return 2;
  }
  *param_4 = 1;
  lVar4 = *(long *)(param_1 + 0x256d8);
  if (lVar4 == 0) {
    return 3;
  }
  if (*(long *)(lVar4 + 0x128) == 0) {
    return 3;
  }
  UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar4 + 0x128) + 0x20);
joined_r0x001879d9:
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    return 3;
  }
                    /* WARNING: Could not recover jumptable at 0x0018795d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar4,param_1,param_2,param_3,param_5,param_6);
  return uVar3;
}


// ===== 00187a70 nvmlDeviceGetSamples =====

int nvmlDeviceGetSamples
              (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5,undefined8 param_6)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %u, %llu, %p, %p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x2ae,"nvmlDeviceGetSamples",
                 "(nvmlDevice_t device, nvmlSamplingType_t type, unsigned long long lastSeenTimeStamp, nvmlValueType_t *sampleValType, unsigned int *sampleCount, nvmlSample_t *samples)"
                 ,param_1,param_2,param_3,param_4,param_5,param_6);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00187830(param_1,param_2,param_3,param_4,param_5,param_6);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2ae,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2ae,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00187c70 FUN_00187c70 =====

undefined8
FUN_00187c70(char *param_1,undefined8 param_2,undefined4 *param_3,int *param_4,long param_5)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  int local_3c [3];
  
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    iVar1 = FUN_00175bd0(param_1,local_3c);
    if (iVar1 == 2) {
      return 2;
    }
    if (iVar1 == 0xf) {
      return 0xf;
    }
    if (iVar1 != 0) {
      return 999;
    }
    if (local_3c[0] == 0) {
      if (DAT_01216a78 < 4) {
        return 3;
      }
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar3,"api.c",0x2035);
      return 3;
    }
    if ((param_4 != (int *)0x0) && ((param_5 == 0 || (*param_4 != 0)))) {
      *param_3 = 1;
      lVar3 = *(long *)(param_1 + 0x256d8);
      if ((lVar3 != 0) &&
         ((*(long *)(lVar3 + 0x128) != 0 &&
          (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar3 + 0x128) + 0x10),
          UNRECOVERED_JUMPTABLE != (code *)0x0)))) {
                    /* WARNING: Could not recover jumptable at 0x00187d62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar3,param_1,param_2,param_4,param_5,0);
        return uVar2;
      }
      return 3;
    }
  }
  return 2;
}


// ===== 00187de0 FUN_00187de0 =====

int FUN_00187de0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %llu, %p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x955,param_1,param_2,param_3,param_4,param_5);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00187c70(param_1,param_2,param_3,param_4,param_5);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x955,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00187f40 FUN_00187f40 =====

ulong FUN_00187f40(char *param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x204c);
        }
      }
      else {
        if ((param_1 == (char *)0x0) || (param_2 == 0)) {
          return 2;
        }
        if (*param_1 != '\x01') {
          if (*(long *)(param_1 + 0x20) == 0) {
            uVar3 = FUN_00137bf0(param_1,param_2);
            return uVar3;
          }
          if (*(int *)(param_1 + 0x14) == 0) {
            return 2;
          }
          if (*(int *)(param_1 + 0x1c) != 0) {
            return 2;
          }
          if (*(int *)(param_1 + 0x10) == 0) {
            return 2;
          }
        }
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x68) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x68) + 0x10),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00188016. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 001880e0 nvmlDeviceGetBAR1MemoryInfo =====

int nvmlDeviceGetBAR1MemoryInfo(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0xcf,"nvmlDeviceGetBAR1MemoryInfo",
                 "(nvmlDevice_t device, nvmlBAR1Memory_t *bar1Memory)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00187f40(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xcf,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xcf,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001882c0 FUN_001882c0 =====

int FUN_001882c0(char *param_1,undefined4 param_2,long param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  float fVar5;
  int local_3c;
  undefined1 local_38 [16];
  
  local_38 = (undefined1  [16])0x0;
  if (param_1 == (char *)0x0) {
switchD_00188429_caseD_6:
    return 2;
  }
  if (*param_1 != '\x01') {
    if (*(int *)(param_1 + 0x14) == 0) {
      return 2;
    }
    if (*(int *)(param_1 + 0x1c) != 0) {
      return 2;
    }
    if (*(int *)(param_1 + 0x10) == 0) {
      return 2;
    }
    if (*(long *)(param_1 + 0x20) == 0) {
      return 2;
    }
  }
  if (param_3 == 0) {
    return 2;
  }
  iVar2 = FUN_00175bd0(param_1,&local_3c);
  if (iVar2 == 2) {
    return 2;
  }
  if (iVar2 == 0xf) {
    return 0xf;
  }
  if (iVar2 != 0) {
    return 999;
  }
  if (local_3c == 0) {
    if (3 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar4,"api.c",0x207a);
      return 3;
    }
    return 3;
  }
  if (*(int *)(param_1 + 0x71c) == 0) {
    do {
      iVar2 = FUN_00291820(param_1 + 0x720,1,0);
    } while (iVar2 != 0);
    if (*(int *)(param_1 + 0x71c) == 0) {
      lVar4 = *(long *)(param_1 + 0x256d8);
      uVar3 = 3;
      if (((lVar4 != 0) && (*(long *)(lVar4 + 0x20) != 0)) &&
         (pcVar1 = *(code **)(*(long *)(lVar4 + 0x20) + 0x98), pcVar1 != (code *)0x0)) {
        uVar3 = (*pcVar1)(lVar4,param_1,param_1 + 0x708);
      }
      *(undefined4 *)(param_1 + 0x724) = uVar3;
      param_1[0x71c] = '\x01';
      param_1[0x71d] = '\0';
      param_1[0x71e] = '\0';
      param_1[0x71f] = '\0';
    }
    FUN_00291830(param_1 + 0x720,0);
  }
  iVar2 = *(int *)(param_1 + 0x724);
  if (iVar2 != 0) {
    if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"api.c",0x207e,"tsapiDeviceGetViolationStatus",0x207e,iVar2);
      return iVar2;
    }
    return iVar2;
  }
  switch(param_2) {
  case 0:
  case 2:
    goto switchD_00188429_caseD_0;
  case 1:
    if ((0x12f < *(uint *)(param_1 + 0x70c)) ||
       (((iVar2 = FUN_00292de0("__NVML_THERMAL_VIOLATION",local_38,0x10), iVar2 == 0 &&
         (local_38[0] == '1')) && (local_38[1] == '\0')))) goto switchD_00188429_caseD_0;
    if (4 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                   lVar4,"api.c",0x209f);
      return 3;
    }
    goto LAB_001884d0;
  case 3:
  case 4:
  case 5:
  case 10:
  case 0xb:
    if (*(uint *)(param_1 + 0x70c) < 0x140) {
      if (4 < DAT_01216a78) {
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",
                     "DEBUG",lVar4,"api.c",0x2092,param_2);
      }
      goto LAB_001884d0;
    }
switchD_00188429_caseD_0:
    lVar4 = *(long *)(param_1 + 0x256d8);
    if (((lVar4 == 0) || (*(long *)(lVar4 + 0x148) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(lVar4 + 0x148) + 0x10), pcVar1 == (code *)0x0)) {
LAB_001884d0:
      iVar2 = 3;
    }
    else {
      iVar2 = (*pcVar1)(lVar4,param_1,param_2,param_3);
    }
    return iVar2;
  default:
    goto switchD_00188429_caseD_6;
  }
}


// ===== 00188690 nvmlDeviceGetViolationStatus =====

int nvmlDeviceGetViolationStatus(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0xd3,"nvmlDeviceGetViolationStatus",
                 "(nvmlDevice_t device, nvmlPerfPolicyType_t perfPolicyType, nvmlViolationTime_t *violTime)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001882c0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xd3,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xd3,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00188860 FUN_00188860 =====

ulong FUN_00188860(char *param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  ulong uVar2;
  long lVar3;
  float fVar4;
  int local_2c [3];
  
  if (((param_1 == (char *)0x0) ||
      ((*param_1 != '\x01' &&
       ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
         (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))))) || (param_2 == 0)
     ) {
    uVar2 = 2;
  }
  else {
    uVar1 = FUN_00175bd0(param_1,local_2c);
    uVar2 = (ulong)uVar1;
    if ((uVar1 != 2) && (uVar1 != 0xf)) {
      if (uVar1 != 0) {
        return 999;
      }
      if (local_2c[0] == 0) {
        uVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar3,"api.c",0x20b5);
        }
      }
      else {
        lVar3 = *(long *)(param_1 + 0x256d8);
        if (((lVar3 != 0) && (*(long *)(lVar3 + 0x148) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar3 + 0x148) + 0x10),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0018892f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar3,param_1,1,param_2);
          return uVar2;
        }
        uVar2 = 3;
      }
    }
  }
  return uVar2;
}


// ===== 001889b0 FUN_001889b0 =====

int FUN_001889b0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x8d6,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00188860(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x8d6,iVar1,uVar2);
  return iVar1;
}


// ===== 00188af0 FUN_00188af0 =====

ulong FUN_00188af0(long param_1,undefined4 param_2,undefined4 param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  uint local_3c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_3c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_3c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x2684);
        }
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        local_3c[0] = local_3c[0] & 0xffffff00;
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x38) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x38) + 0x80),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
          (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,local_3c);
          if ((((char)local_3c[0] != '\0') && (lVar2 = *(long *)(param_1 + 0x256d8), lVar2 != 0)) &&
             ((*(long *)(lVar2 + 0x28) != 0 &&
              (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x28) + 8),
              UNRECOVERED_JUMPTABLE != (code *)0x0)))) {
                    /* WARNING: Could not recover jumptable at 0x00188c20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2,param_3);
            return uVar3;
          }
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00188c40 nvmlDeviceSetVgpuCapabilities =====

int nvmlDeviceSetVgpuCapabilities(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %d %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x327,"nvmlDeviceSetVgpuCapabilities",
                 "(nvmlDevice_t device, nvmlDeviceVgpuCapability_t capability, nvmlEnableState_t state)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00188af0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x327,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x327,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00188e10 FUN_00188e10 =====

int FUN_00188e10(long param_1,uint *param_2,undefined8 *param_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined8 uVar11;
  long lVar12;
  byte bVar13;
  float fVar14;
  double dVar15;
  undefined8 uVar16;
  int local_5c;
  int local_44;
  long *local_40 [2];
  
  bVar13 = 0;
  local_40[0] = (long *)0x0;
  iVar2 = FUN_00175bd0(param_1,&local_44);
  if (iVar2 == 2) {
    return 2;
  }
  if (iVar2 == 0xf) {
    return 0xf;
  }
  if (iVar2 != 0) {
    return 999;
  }
  if (local_44 == 0) {
    if (DAT_01216a78 < 4) {
      return 3;
    }
    fVar14 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar14 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar6,"api.c",0x26a1);
    return 3;
  }
  if (*(int *)(param_1 + 0x70534) == 0) {
    do {
      iVar2 = FUN_00291820(param_1 + 0x70538,1,0);
    } while (iVar2 != 0);
    if (*(int *)(param_1 + 0x70534) == 0) {
      lVar6 = *(long *)(param_1 + 0x256d8);
      uVar5 = 3;
      if (((lVar6 != 0) && (*(long *)(lVar6 + 0x38) != 0)) &&
         (pcVar1 = *(code **)(*(long *)(lVar6 + 0x38) + 8), pcVar1 != (code *)0x0)) {
        uVar5 = (*pcVar1)(lVar6,param_1,param_1 + 0x70530);
      }
      *(undefined4 *)(param_1 + 0x7053c) = uVar5;
      *(undefined4 *)(param_1 + 0x70534) = 1;
    }
    FUN_00291830(param_1 + 0x70538,0);
  }
  local_5c = *(int *)(param_1 + 0x7053c);
  if (local_5c != 0) {
    if (DAT_01216a78 < 2) {
      return local_5c;
    }
    fVar14 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    uVar16 = 0x26a8;
    uVar11 = 0x26a8;
    dVar15 = (double)(fVar14 * DAT_00298548);
    goto LAB_00189180;
  }
  if (*(int *)(param_1 + 0x70530) != 3) {
    return 3;
  }
  lVar6 = *(long *)(param_1 + 0x25d60);
  if (lVar6 == 0) {
    return 3;
  }
  if ((param_2 == (uint *)0x0) || ((*param_2 != 0 && (param_3 == (undefined8 *)0x0)))) {
    return 2;
  }
  if (*(int *)(lVar6 + 0x638) != 1) {
    if (*(int *)(lVar6 + 0x630) == 0) {
      lVar12 = *(long *)(param_1 + 0x256d8);
      local_44 = 0;
      if (((lVar12 == 0) || (*(long *)(lVar12 + 0x28) == 0)) ||
         ((pcVar1 = *(code **)(*(long *)(lVar12 + 0x28) + 0x18), pcVar1 == (code *)0x0 ||
          (iVar2 = (*pcVar1)(lVar12,param_1,10,&local_44), iVar2 != 0)))) {
        *(undefined8 *)(lVar6 + 0x630) = 1;
        goto LAB_00189040;
      }
      *(undefined4 *)(lVar6 + 0x630) = 1;
      uVar4 = (uint)(local_44 == 1);
      *(uint *)(lVar6 + 0x634) = uVar4;
    }
    else {
      uVar4 = *(uint *)(lVar6 + 0x634);
    }
    if (uVar4 == 1) {
      lVar12 = *(long *)(param_1 + 0x256d8);
      local_44 = 0;
      if ((((lVar12 != 0) && (*(long *)(lVar12 + 0x28) != 0)) &&
          (pcVar1 = *(code **)(*(long *)(lVar12 + 0x28) + 0x18), pcVar1 != (code *)0x0)) &&
         ((iVar2 = (*pcVar1)(lVar12,param_1,0xb,&local_44), iVar2 == 0 && (local_44 == 1)))) {
        do {
          iVar2 = FUN_00291820(lVar6 + 0x210,1,0);
        } while (iVar2 != 0);
        *(undefined4 *)(lVar6 + 0x20c) = 0;
        FUN_00291830(lVar6 + 0x210,0);
        *(undefined4 *)(lVar6 + 0x638) = 1;
      }
    }
  }
LAB_00189040:
  if (*(int *)(lVar6 + 0x20c) == 0) {
    do {
      iVar2 = FUN_00291820(lVar6 + 0x210,1,0);
    } while (iVar2 != 0);
    if (*(int *)(lVar6 + 0x20c) == 0) {
      lVar12 = *(long *)(param_1 + 0x256d8);
      if (((lVar12 == 0) || (*(long *)(lVar12 + 0x28) == 0)) ||
         (pcVar1 = *(code **)(*(long *)(lVar12 + 0x28) + 0x20), pcVar1 == (code *)0x0)) {
        uVar5 = 3;
      }
      else {
        uVar5 = (*pcVar1)(lVar12,param_1,lVar6 + 8,lVar6 + 0xc);
      }
      *(undefined4 *)(lVar6 + 0x214) = uVar5;
      *(undefined4 *)(lVar6 + 0x20c) = 1;
    }
    FUN_00291830(lVar6 + 0x210,0);
  }
  local_5c = *(int *)(lVar6 + 0x214);
  if (local_5c == 0) {
    uVar4 = *(uint *)(lVar6 + 8);
    if (*param_2 < uVar4) {
      *param_2 = uVar4;
      return 7;
    }
    uVar3 = 0;
    if (uVar4 != 0) {
      lVar12 = 0;
      do {
        local_5c = 3;
        if (DAT_012164a0 == 0) {
LAB_0018911d:
          if (DAT_01216a78 < 2) {
            return local_5c;
          }
          fVar14 = (float)FUN_002917b0(&DAT_01216a60);
          lVar6 = syscall(0xba);
          uVar16 = 0x26ef;
          uVar11 = 0x26ef;
          dVar15 = (double)(fVar14 * DAT_00298548);
          goto LAB_00189180;
        }
        lVar7 = *(long *)(DAT_012164a0 + 0x28);
        uVar5 = *(undefined4 *)(lVar6 + 0xc + lVar12 * 4);
        if (lVar7 == 0) goto LAB_0018911d;
        if (*(code **)(lVar7 + 0xb8) == (code *)0x0) {
LAB_001892db:
          if ((*(code **)(lVar7 + 0xc0) == (code *)0x0) ||
             (local_5c = (**(code **)(lVar7 + 0xc0))(DAT_012164a0,uVar5,local_40), local_5c != 0))
          goto LAB_0018911d;
          *local_40[0] = param_1;
        }
        else {
          iVar2 = (**(code **)(lVar7 + 0xb8))(DAT_012164a0,uVar5,local_40);
          if (iVar2 != 0) {
            uVar5 = *(undefined4 *)(lVar6 + 0xc + lVar12 * 4);
            if ((DAT_012164a0 == 0) || (lVar7 = *(long *)(DAT_012164a0 + 0x28), lVar7 == 0))
            goto LAB_0018911d;
            goto LAB_001892db;
          }
        }
        *(long **)(lVar6 + 0x218 + lVar12 * 8) = local_40[0];
        uVar3 = *(uint *)(lVar6 + 8);
        lVar12 = lVar12 + 1;
      } while ((uint)lVar12 < uVar3);
    }
    *param_2 = uVar3;
    uVar3 = uVar3 * 4;
    if (7 < uVar3) {
      *param_3 = *(undefined8 *)(lVar6 + 0xc);
      *(undefined8 *)((long)param_3 + ((ulong)uVar3 - 8)) =
           *(undefined8 *)(lVar6 + 4 + (ulong)uVar3);
      lVar12 = (long)param_3 - (long)((ulong)(param_3 + 1) & 0xfffffffffffffff8);
      puVar9 = (undefined8 *)((lVar6 + 0xc) - lVar12);
      puVar10 = (undefined8 *)((ulong)(param_3 + 1) & 0xfffffffffffffff8);
      for (uVar8 = (ulong)((int)lVar12 + uVar3 >> 3); uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + (ulong)bVar13 * -2 + 1;
        puVar10 = puVar10 + (ulong)bVar13 * -2 + 1;
      }
      return 0;
    }
    if ((uVar3 & 4) == 0) {
      if (uVar3 == 0) {
        return 0;
      }
      *(undefined1 *)param_3 = *(undefined1 *)(lVar6 + 0xc);
      return 0;
    }
    *(undefined4 *)param_3 = *(undefined4 *)(lVar6 + 0xc);
    *(undefined4 *)((long)param_3 + ((ulong)uVar3 - 4)) = *(undefined4 *)(lVar6 + 8 + (ulong)uVar3);
    return 0;
  }
  if (DAT_01216a78 < 2) {
    return local_5c;
  }
  fVar14 = (float)FUN_002917b0(&DAT_01216a60);
  lVar6 = syscall(0xba);
  uVar16 = 0x26dd;
  uVar11 = 0x26dd;
  dVar15 = (double)(fVar14 * DAT_00298548);
LAB_00189180:
  FUN_002340f0(dVar15,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar6,"api.c",uVar11,
               "tsapiDeviceGetSupportedVgpus",uVar16,local_5c);
  return local_5c;
}


// ===== 00189470 nvmlDeviceGetSupportedVgpus =====

int nvmlDeviceGetSupportedVgpus(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x331,"nvmlDeviceGetSupportedVgpus",
                 "(nvmlDevice_t device, unsigned int *vgpuCount, nvmlVgpuTypeId_t *vgpuTypeIds)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00188e10(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x331,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x331,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00189640 FUN_00189640 =====

int FUN_00189640(long param_1,undefined4 param_2,uint *param_3,uint *param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  uint uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  long lVar10;
  byte bVar11;
  float fVar12;
  undefined8 uVar13;
  uint local_244;
  undefined8 local_240;
  uint local_238 [130];
  
  bVar11 = 0;
  local_240 = (long *)0x0;
  iVar2 = FUN_00175bd0(param_1,local_238);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_238[0] == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar12 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar12 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar3,"api.c",0x2708);
        }
      }
      else {
        lVar3 = *(long *)(param_1 + 0x25d60);
        if (lVar3 != 0) {
          lVar10 = *(long *)(param_1 + 0x256d8);
          local_238[0] = local_238[0] & 0xffffff00;
          if (((lVar10 != 0) && (*(long *)(lVar10 + 0x38) != 0)) &&
             (pcVar1 = *(code **)(*(long *)(lVar10 + 0x38) + 0x80), pcVar1 != (code *)0x0)) {
            (*pcVar1)(lVar10,param_1,local_238);
            if ((char)local_238[0] != '\0') {
              if ((param_3 == (uint *)0x0) || ((*param_3 != 0 && (param_4 == (uint *)0x0)))) {
                return 2;
              }
              lVar10 = *(long *)(param_1 + 0x256d8);
              if (((lVar10 == 0) || (*(long *)(lVar10 + 0x28) == 0)) ||
                 (pcVar1 = *(code **)(*(long *)(lVar10 + 0x28) + 0x28), pcVar1 == (code *)0x0)) {
                iVar2 = 3;
              }
              else {
                iVar2 = (*pcVar1)(lVar10,param_1,&local_244,local_238,param_2);
                if (iVar2 == 0) {
                  if (*param_3 < local_244) {
                    *param_3 = local_244;
                    return 7;
                  }
                  if (local_244 != 0) {
                    lVar10 = 0;
                    do {
                      if (DAT_012164a0 == 0) {
LAB_001898b3:
                        iVar2 = 3;
LAB_001898b9:
                        if (DAT_01216a78 < 2) {
                          return iVar2;
                        }
                        fVar12 = (float)FUN_002917b0(&DAT_01216a60);
                        lVar3 = syscall(0xba);
                        fVar12 = fVar12 * DAT_00298548;
                        uVar13 = 0x2729;
                        uVar9 = 0x2729;
                        goto LAB_00189918;
                      }
                      lVar5 = *(long *)(DAT_012164a0 + 0x28);
                      uVar6 = local_238[lVar10];
                      if (lVar5 == 0) goto LAB_001898b3;
                      if (*(code **)(lVar5 + 0xb8) == (code *)0x0) {
LAB_001899df:
                        if (*(code **)(lVar5 + 0xc0) == (code *)0x0) goto LAB_001898b3;
                        iVar2 = (**(code **)(lVar5 + 0xc0))(DAT_012164a0,uVar6,&local_240);
                        if (iVar2 == 0) {
                          *local_240 = param_1;
                          goto LAB_00189877;
                        }
                        goto LAB_001898b9;
                      }
                      iVar2 = (**(code **)(lVar5 + 0xb8))(DAT_012164a0,uVar6,&local_240);
                      if (iVar2 != 0) {
                        uVar6 = local_238[lVar10];
                        if ((DAT_012164a0 == 0) ||
                           (lVar5 = *(long *)(DAT_012164a0 + 0x28), lVar5 == 0)) goto LAB_001898b3;
                        goto LAB_001899df;
                      }
LAB_00189877:
                      *(long **)(lVar3 + 0x218 + lVar10 * 8) = local_240;
                      lVar10 = lVar10 + 1;
                    } while ((uint)lVar10 < local_244);
                  }
                  *param_3 = local_244;
                  local_244 = local_244 * 4;
                  if (7 < local_244) {
                    *(ulong *)param_4 = CONCAT44(local_238[1],local_238[0]);
                    *(undefined8 *)((long)param_4 + ((ulong)local_244 - 8)) =
                         *(undefined8 *)((long)local_238 + ((ulong)local_244 - 8));
                    lVar3 = (long)param_4 - (long)((ulong)(param_4 + 2) & 0xfffffffffffffff8);
                    puVar7 = (undefined8 *)((long)local_238 - lVar3);
                    puVar8 = (undefined8 *)((ulong)(param_4 + 2) & 0xfffffffffffffff8);
                    for (uVar4 = (ulong)((int)lVar3 + local_244 >> 3); uVar4 != 0; uVar4 = uVar4 - 1
                        ) {
                      *puVar8 = *puVar7;
                      puVar7 = puVar7 + (ulong)bVar11 * -2 + 1;
                      puVar8 = puVar8 + (ulong)bVar11 * -2 + 1;
                    }
                    return 0;
                  }
                  if ((local_244 & 4) == 0) {
                    if (local_244 == 0) {
                      return 0;
                    }
                    *(char *)param_4 = (char)local_238[0];
                    return 0;
                  }
                  *param_4 = local_238[0];
                  *(undefined4 *)((long)param_4 + ((ulong)local_244 - 4)) =
                       *(undefined4 *)((long)local_238 + ((ulong)local_244 - 4));
                  return 0;
                }
              }
              if (DAT_01216a78 < 2) {
                return iVar2;
              }
              fVar12 = (float)FUN_002917b0(&DAT_01216a60);
              lVar3 = syscall(0xba);
              fVar12 = fVar12 * DAT_00298548;
              uVar13 = 0x271b;
              uVar9 = 0x271b;
LAB_00189918:
              FUN_002340f0((double)fVar12,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",
                           lVar3,"api.c",uVar9,"_getCreatableVgpus",uVar13,iVar2);
              return iVar2;
            }
          }
        }
        iVar2 = 3;
      }
    }
    else {
      iVar2 = 999;
    }
  }
  return iVar2;
}


// ===== 00189ab0 FUN_00189ab0 =====

void FUN_00189ab0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00189640(param_1,0xffffffff,param_2,param_3);
  return;
}


// ===== 00189ac0 nvmlDeviceGetCreatableVgpus =====

int nvmlDeviceGetCreatableVgpus(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x336,"nvmlDeviceGetCreatableVgpus",
                 "(nvmlDevice_t device, unsigned int *vgpuCount, nvmlVgpuTypeId_t *vgpuTypeIds)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00189ab0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x336,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x336,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00189c90 FUN_00189c90 =====

undefined8 FUN_00189c90(undefined8 *param_1,int *param_2)

{
  char *pcVar1;
  undefined8 uVar2;
  
  if ((((param_1 != (undefined8 *)0x0) && (param_2 != (int *)0x0)) &&
      (pcVar1 = (char *)*param_1, pcVar1 != (char *)0x0)) &&
     ((*pcVar1 == '\x01' ||
      (((*(int *)(pcVar1 + 0x14) != 0 && (*(int *)(pcVar1 + 0x1c) == 0)) &&
       ((*(int *)(pcVar1 + 0x10) != 0 && (*(long *)(pcVar1 + 0x20) != 0)))))))) {
    if (*(int *)(param_1 + 1) != -1) {
      if (*param_2 != 0x1000010) {
        return 0x19;
      }
      uVar2 = FUN_00189640(pcVar1,*(int *)(param_1 + 1),param_2 + 1,*(undefined8 *)(param_2 + 2));
      return uVar2;
    }
  }
  return 2;
}


// ===== 00189d10 nvmlGpuInstanceGetCreatableVgpus =====

int nvmlGpuInstanceGetCreatableVgpus(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x6fa,"nvmlGpuInstanceGetCreatableVgpus",
                 "(nvmlGpuInstance_t gpuInstance, nvmlVgpuTypeIdInfo_t *vgpus)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00189c90(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x6fa,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x6fa,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00189ef0 FUN_00189ef0 =====

int FUN_00189ef0(long param_1,int param_2,undefined4 *param_3)

{
  code *pcVar1;
  long lVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  long lVar6;
  undefined8 uVar7;
  float fVar8;
  double dVar9;
  undefined8 uVar10;
  int local_44;
  long local_40 [2];
  
  local_40[0] = 0;
  iVar3 = FUN_00175bd0(param_1,&local_44);
  if ((iVar3 != 2) && (iVar3 != 0xf)) {
    if (iVar3 == 0) {
      if (local_44 == 0) {
        iVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar8 = (float)FUN_002917b0(&DAT_01216a60);
          lVar6 = syscall(0xba);
          FUN_002340f0((double)(fVar8 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar6,"api.c",0x2859);
        }
      }
      else {
        lVar6 = *(long *)(param_1 + 0x25d60);
        if (lVar6 == 0) {
          iVar3 = 3;
        }
        else {
          if ((param_2 != 0) && (param_3 != (undefined4 *)0x0)) {
            if (*(int *)(lVar6 + 0x20c) == 0) {
              do {
                iVar3 = FUN_00291820(lVar6 + 0x210,1,0);
              } while (iVar3 != 0);
              if (*(int *)(lVar6 + 0x20c) == 0) {
                lVar2 = *(long *)(param_1 + 0x256d8);
                if (((lVar2 == 0) || (*(long *)(lVar2 + 0x28) == 0)) ||
                   (pcVar1 = *(code **)(*(long *)(lVar2 + 0x28) + 0x20), pcVar1 == (code *)0x0)) {
                  uVar4 = 3;
                }
                else {
                  uVar4 = (*pcVar1)(lVar2,param_1,lVar6 + 8,lVar6 + 0xc);
                }
                *(undefined4 *)(lVar6 + 0x214) = uVar4;
                *(undefined4 *)(lVar6 + 0x20c) = 1;
              }
              FUN_00291830(lVar6 + 0x210,0);
            }
            iVar3 = *(int *)(lVar6 + 0x214);
            if (iVar3 != 0) {
              if (DAT_01216a78 < 2) {
                return iVar3;
              }
              fVar8 = (float)FUN_002917b0(&DAT_01216a60);
              lVar6 = syscall(0xba);
              uVar10 = 0x2868;
              uVar7 = 0x2868;
              dVar9 = (double)(fVar8 * DAT_00298548);
LAB_0018a1ab:
              FUN_002340f0(dVar9,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar6,
                           "api.c",uVar7,"tsapiVgpuTypeGetMaxInstances",uVar10,iVar3);
              return iVar3;
            }
            if (*(int *)(lVar6 + 8) != 0) {
              piVar5 = (int *)(lVar6 + 0xc);
              iVar3 = 0;
              do {
                if (*piVar5 == param_2) {
                  if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x28) == 0)) ||
                     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0xb8),
                     pcVar1 == (code *)0x0)) {
                    iVar3 = 3;
                  }
                  else {
                    iVar3 = (*pcVar1)(DAT_012164a0,param_2,local_40);
                    if (iVar3 == 0) {
                      iVar3 = FUN_00138f40(param_2,local_40[0]);
                      if (iVar3 == 0) {
                        *param_3 = *(undefined4 *)(local_40[0] + 0x118);
                        return 0;
                      }
                      if (DAT_01216a78 < 2) {
                        return iVar3;
                      }
                      fVar8 = (float)FUN_002917b0(&DAT_01216a60);
                      lVar6 = syscall(0xba);
                      uVar10 = 0x2878;
                      uVar7 = 0x2878;
                      dVar9 = (double)(fVar8 * DAT_00298548);
                      goto LAB_0018a1ab;
                    }
                  }
                  if (DAT_01216a78 < 2) {
                    return iVar3;
                  }
                  fVar8 = (float)FUN_002917b0(&DAT_01216a60);
                  lVar6 = syscall(0xba);
                  uVar10 = 0x2875;
                  uVar7 = 0x2875;
                  dVar9 = (double)(fVar8 * DAT_00298548);
                  goto LAB_0018a1ab;
                }
                iVar3 = iVar3 + 1;
                piVar5 = piVar5 + 1;
              } while (iVar3 != *(int *)(lVar6 + 8));
            }
          }
          iVar3 = 2;
        }
      }
    }
    else {
      iVar3 = 999;
    }
  }
  return iVar3;
}


// ===== 0018a2b0 nvmlVgpuTypeGetMaxInstances =====

int nvmlVgpuTypeGetMaxInstances(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x377,"nvmlVgpuTypeGetMaxInstances",
                 "(nvmlDevice_t device, nvmlVgpuTypeId_t vgpuTypeId, unsigned int *vgpuInstanceCount)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00189ef0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x377,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x377,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0018a480 FUN_0018a480 =====

int FUN_0018a480(long param_1,uint *param_2,long param_3)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  long lVar4;
  code *pcVar5;
  ulong uVar6;
  int iVar7;
  long lVar8;
  float fVar9;
  int local_3c [3];
  
  iVar7 = FUN_00175bd0(param_1,local_3c);
  if (iVar7 == 2) {
    return 2;
  }
  if (iVar7 == 0xf) {
    return 0xf;
  }
  if (iVar7 != 0) {
    return 999;
  }
  if (local_3c[0] == 0) {
    if (DAT_01216a78 < 4) {
      return 3;
    }
    fVar9 = (float)FUN_002917b0(&DAT_01216a60);
    lVar8 = syscall(0xba);
    FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar8,"api.c",0x28bc);
    return 3;
  }
  lVar8 = *(long *)(param_1 + 0x25d60);
  if (lVar8 == 0) {
LAB_0018a650:
    iVar7 = 3;
  }
  else {
    if ((param_2 == (uint *)0x0) || ((*param_2 != 0 && (param_3 == 0)))) {
      return 2;
    }
    iVar7 = FUN_00138b90(param_1);
    if ((iVar7 == 0) && (*(int *)(lVar8 + 0x628) == 0)) {
      lVar4 = *(long *)(param_1 + 0x256d8);
      if ((lVar4 == 0) ||
         ((*(long *)(lVar4 + 0x28) == 0 ||
          (pcVar5 = *(code **)(*(long *)(lVar4 + 0x28) + 0x48), pcVar5 == (code *)0x0))))
      goto LAB_0018a650;
      iVar7 = (*pcVar5)(lVar4,param_1);
      if (iVar7 != 0) {
        return iVar7;
      }
    }
    uVar1 = *(uint *)(lVar8 + 4);
    if (uVar1 == 0) {
      *param_2 = 0;
      iVar7 = 0;
    }
    else {
      uVar2 = *param_2;
      *param_2 = uVar1;
      if (uVar2 < uVar1) {
        iVar7 = 7;
      }
      else {
        uVar6 = 0;
        for (puVar3 = *(undefined8 **)(lVar8 + 0x618); iVar7 = 0,
            (undefined8 *)(lVar8 + 0x618) != puVar3; puVar3 = (undefined8 *)*puVar3) {
          *(undefined4 *)(param_3 + uVar6 * 4) = *(undefined4 *)(puVar3 + -0x43);
          uVar6 = (ulong)((int)uVar6 + 1);
        }
      }
    }
  }
  return iVar7;
}


// ===== 0018a680 nvmlDeviceGetActiveVgpus =====

int nvmlDeviceGetActiveVgpus(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x386,"nvmlDeviceGetActiveVgpus",
                 "(nvmlDevice_t device, unsigned int *vgpuCount, nvmlVgpuInstance_t *vgpuInstances)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018a480(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x386,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x386,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0018a850 FUN_0018a850 =====

int FUN_0018a850(long param_1,undefined8 param_2,undefined4 *param_3,uint *param_4,long param_5)

{
  undefined4 uVar1;
  code *pcVar2;
  long *plVar3;
  undefined8 *puVar4;
  ulong uVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  uint uVar11;
  float fVar12;
  undefined8 uVar13;
  undefined4 uStack_1e890;
  int iStack_1e88c;
  int aiStack_1e888 [20];
  undefined1 auStack_1e838 [124936];
  
  memset(auStack_1e838,0,0x1e800);
  uStack_1e890 = 0x100;
  iStack_1e88c = 0;
  iVar6 = FUN_00175bd0(param_1,aiStack_1e888);
  if (iVar6 == 2) {
    return 2;
  }
  if (iVar6 == 0xf) {
    return 0xf;
  }
  if (iVar6 == 0) {
    if (aiStack_1e888[0] == 0) {
      if (DAT_01216a78 < 4) {
        return 3;
      }
      fVar12 = (float)FUN_002917b0(&DAT_01216a60);
      lVar7 = syscall(0xba);
      FUN_002340f0((double)(fVar12 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar7,"api.c",0x2ac2);
      return 3;
    }
    lVar7 = *(long *)(param_1 + 0x25d60);
    if (lVar7 == 0) {
      return 3;
    }
    if ((param_4 == (uint *)0x0) || (param_3 == (undefined4 *)0x0)) {
      return 2;
    }
    if ((param_5 != 0) && (*param_4 == 0)) {
      return 2;
    }
    iVar6 = FUN_00138b90(param_1);
    if ((iVar6 == 0) && (*(int *)(lVar7 + 0x628) == 0)) {
      lVar8 = *(long *)(param_1 + 0x256d8);
      if ((lVar8 == 0) ||
         ((*(long *)(lVar8 + 0x28) == 0 ||
          (pcVar2 = *(code **)(*(long *)(lVar8 + 0x28) + 0x48), pcVar2 == (code *)0x0)))) {
        iVar6 = 3;
      }
      else {
        iVar6 = (*pcVar2)(lVar8,param_1);
        if (iVar6 == 0) goto LAB_0018aaa0;
      }
      if (DAT_01216a78 < 2) {
        return iVar6;
      }
      fVar12 = (float)FUN_002917b0(&DAT_01216a60);
      lVar7 = syscall(0xba);
      fVar12 = fVar12 * DAT_00298548;
      uVar13 = 0x2ad2;
      uVar10 = 0x2ad2;
    }
    else {
LAB_0018aaa0:
      uVar11 = *(uint *)(lVar7 + 4);
      if (uVar11 == 0) {
        *param_4 = 0;
        return 0;
      }
      if ((param_5 == 0) || (*param_4 < uVar11)) {
        *param_4 = uVar11;
        return 7;
      }
      iVar6 = FUN_00156380(param_1,&iStack_1e88c);
      if (iVar6 != 0) {
        return iVar6;
      }
      if (iStack_1e88c == 0) {
        uVar11 = 0;
        uVar5 = 0;
        for (puVar4 = *(undefined8 **)(lVar7 + 0x618); (undefined8 *)(lVar7 + 0x618) != puVar4;
            puVar4 = (undefined8 *)*puVar4) {
          uVar11 = (int)uVar5 + 1;
          puVar9 = (undefined4 *)(uVar5 * 0x30 + param_5);
          puVar9[4] = 0;
          puVar9[6] = 0;
          puVar9[8] = 0;
          puVar9[10] = 0;
          uVar1 = *(undefined4 *)(puVar4 + -0x43);
          *(undefined8 *)(puVar9 + 2) = param_2;
          *puVar9 = uVar1;
          uVar5 = (ulong)uVar11;
        }
        *param_4 = uVar11;
        *param_3 = 1;
        return 0;
      }
      lVar8 = *(long *)(param_1 + 0x256d8);
      if (((lVar8 == 0) || (*(long *)(lVar8 + 0x128) == 0)) ||
         (pcVar2 = *(code **)(*(long *)(lVar8 + 0x128) + 0x10), pcVar2 == (code *)0x0)) {
        iVar6 = 3;
      }
      else {
        iVar6 = (*pcVar2)(lVar8,param_1,param_2,&uStack_1e890,auStack_1e838,0);
        if (iVar6 == 6) {
          uVar11 = 0;
          uVar5 = 0;
          for (puVar4 = *(undefined8 **)(lVar7 + 0x618); (undefined8 *)(lVar7 + 0x618) != puVar4;
              puVar4 = (undefined8 *)*puVar4) {
            uVar11 = (int)uVar5 + 1;
            puVar9 = (undefined4 *)(uVar5 * 0x30 + param_5);
            puVar9[4] = 0;
            puVar9[6] = 0;
            puVar9[8] = 0;
            puVar9[10] = 0;
            uVar1 = *(undefined4 *)(puVar4 + -0x43);
            *(undefined8 *)(puVar9 + 2) = param_2;
            *puVar9 = uVar1;
            uVar5 = (ulong)uVar11;
          }
          *param_4 = uVar11;
          *param_3 = 1;
          return 0;
        }
        if (iVar6 == 0) {
          iVar6 = FUN_00234b40(aiStack_1e888,FUN_00121360,FUN_00121370,free,free);
          if (iVar6 != 0) {
            return 999;
          }
          iVar6 = FUN_00121460(aiStack_1e888,auStack_1e838,uStack_1e890);
          if (iVar6 == 0) {
            plVar3 = *(long **)(lVar7 + 0x618);
            uVar11 = 0;
            if ((long *)(lVar7 + 0x618) != plVar3) {
              uVar11 = 0;
              do {
                lVar8 = FUN_00234de0(aiStack_1e888,(long)plVar3 + -0x20c);
                puVar9 = (undefined4 *)((ulong)uVar11 * 0x30 + param_5);
                if (lVar8 == 0) {
                  puVar9[4] = 0;
                  puVar9[6] = 0;
                  puVar9[8] = 0;
                  puVar9[10] = 0;
                  *puVar9 = (int)plVar3[-0x43];
                  *(undefined8 *)(puVar9 + 2) = param_2;
                }
                else {
                  puVar9[4] = (int)(long)*(double *)(lVar8 + 0x10);
                  puVar9[6] = (int)(long)*(double *)(lVar8 + 0x18);
                  puVar9[8] = (int)(long)*(double *)(lVar8 + 0x20);
                  puVar9[10] = (int)(long)*(double *)(lVar8 + 0x28);
                  *puVar9 = (int)plVar3[-0x43];
                  *(undefined8 *)(puVar9 + 2) = *(undefined8 *)(lVar8 + 8);
                }
                plVar3 = (long *)*plVar3;
                uVar11 = uVar11 + 1;
              } while ((long *)(lVar7 + 0x618) != plVar3);
            }
            *param_4 = uVar11;
            *param_3 = 1;
            FUN_00234bf0(aiStack_1e888);
            return 0;
          }
          FUN_00234bf0(aiStack_1e888);
          goto LAB_0018a8cc;
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar6;
      }
      fVar12 = (float)FUN_002917b0(&DAT_01216a60);
      lVar7 = syscall(0xba);
      fVar12 = fVar12 * DAT_00298548;
      uVar13 = 0x2b18;
      uVar10 = 0x2b18;
    }
    FUN_002340f0((double)fVar12,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar7,
                 "api.c",uVar10,"tsapiDeviceGetVgpuUtilization",uVar13,iVar6);
  }
  else {
LAB_0018a8cc:
    iVar6 = 999;
  }
  return iVar6;
}


// ===== 0018aeb0 nvmlDeviceGetVgpuUtilization =====

int nvmlDeviceGetVgpuUtilization
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %llu %p %p %p)\n","DEBUG",
                 lVar3,"entry_points.h",0x3cc,"nvmlDeviceGetVgpuUtilization",
                 "(nvmlDevice_t device, unsigned long long lastSeenTimeStamp, nvmlValueType_t *sampleValType, unsigned int *vgpuInstanceSamplesCount, nvmlVgpuInstanceUtilizationSample_t *utilizationSamples)"
                 ,param_1,param_2,param_3,param_4,param_5);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018a850(param_1,param_2,param_3,param_4,param_5);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x3cc,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x3cc,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0018b0a0 FUN_0018b0a0 =====

ulong FUN_0018b0a0(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x2b50);
        }
      }
      else if (param_2 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x128) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x128) + 0x48),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0018b136. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 0018b1d0 nvmlDeviceGetVgpuInstancesUtilizationInfo =====

int nvmlDeviceGetVgpuInstancesUtilizationInfo(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x3d3,"nvmlDeviceGetVgpuInstancesUtilizationInfo",
                 "(nvmlDevice_t device, nvmlVgpuInstancesUtilizationInfo_t *vgpuUtilInfo)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018b0a0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x3d3,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x3d3,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0018b3b0 FUN_0018b3b0 =====

ulong FUN_0018b3b0(char *param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  uint local_2c;
  
  uVar1 = FUN_00175bd0(param_1,&local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x2c63);
        }
      }
      else if (((param_1 == (char *)0x0) ||
               ((*param_1 != '\x01' &&
                ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
                  (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))))) ||
              (param_2 == 0)) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        local_2c = local_2c & 0xffffff00;
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x38) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x38) + 0x80),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
          (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,&local_2c);
          if ((((char)local_2c != '\0') && (lVar2 = *(long *)(param_1 + 0x256d8), lVar2 != 0)) &&
             ((*(long *)(lVar2 + 0x28) != 0 &&
              (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x28) + 0xd0),
              UNRECOVERED_JUMPTABLE != (code *)0x0)))) {
                    /* WARNING: Could not recover jumptable at 0x0018b4d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
            return uVar3;
          }
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 0018b580 nvmlDeviceGetVgpuSchedulerLog =====

int nvmlDeviceGetVgpuSchedulerLog(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x400,"nvmlDeviceGetVgpuSchedulerLog",
                 "(nvmlDevice_t device, nvmlVgpuSchedulerLog_t *pSchedulerLog)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018b3b0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x400,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x400,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0018b760 FUN_0018b760 =====

ulong FUN_0018b760(char *param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  uint local_2c;
  
  uVar1 = FUN_00175bd0(param_1,&local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x2c75);
        }
      }
      else if (((param_1 == (char *)0x0) ||
               ((*param_1 != '\x01' &&
                ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
                  (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))))) ||
              (param_2 == 0)) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        local_2c = local_2c & 0xffffff00;
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x38) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x38) + 0x80),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
          (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,&local_2c);
          if ((((char)local_2c != '\0') && (lVar2 = *(long *)(param_1 + 0x256d8), lVar2 != 0)) &&
             ((*(long *)(lVar2 + 0x28) != 0 &&
              (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x28) + 0xd8),
              UNRECOVERED_JUMPTABLE != (code *)0x0)))) {
                    /* WARNING: Could not recover jumptable at 0x0018b886. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
            return uVar3;
          }
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 0018b930 nvmlDeviceGetVgpuSchedulerState =====

int nvmlDeviceGetVgpuSchedulerState(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x405,"nvmlDeviceGetVgpuSchedulerState",
                 "(nvmlDevice_t device, nvmlVgpuSchedulerGetState_t *pSchedulerState)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018b760(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x405,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x405,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0018bb10 FUN_0018bb10 =====

ulong FUN_0018bb10(char *param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  uint local_2c;
  
  uVar1 = FUN_00175bd0(param_1,&local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x2c87);
        }
      }
      else if (((param_1 == (char *)0x0) ||
               ((*param_1 != '\x01' &&
                ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
                  (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))))) ||
              (param_2 == 0)) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        local_2c = local_2c & 0xffffff00;
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x38) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x38) + 0x80),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
          (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,&local_2c);
          if ((((char)local_2c != '\0') && (lVar2 = *(long *)(param_1 + 0x256d8), lVar2 != 0)) &&
             ((*(long *)(lVar2 + 0x28) != 0 &&
              (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x28) + 0xe0),
              UNRECOVERED_JUMPTABLE != (code *)0x0)))) {
                    /* WARNING: Could not recover jumptable at 0x0018bc36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
            return uVar3;
          }
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 0018bce0 nvmlDeviceGetVgpuSchedulerCapabilities =====

int nvmlDeviceGetVgpuSchedulerCapabilities(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x40a,"nvmlDeviceGetVgpuSchedulerCapabilities",
                 "(nvmlDevice_t device, nvmlVgpuSchedulerCapabilities_t *pCapabilities)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018bb10(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x40a,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x40a,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0018bec0 FUN_0018bec0 =====

ulong FUN_0018bec0(char *param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  uint local_2c;
  
  uVar1 = FUN_00175bd0(param_1,&local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x2c9b);
        }
      }
      else if ((param_1 == (char *)0x0) ||
              (((*param_1 != '\x01' &&
                ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
                  (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) ||
               (param_2 == 0)))) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        local_2c = local_2c & 0xffffff00;
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x38) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x38) + 0x80),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
          (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,&local_2c);
          if ((((char)local_2c != '\0') && (*(long *)(param_1 + 0x25d60) != 0)) &&
             ((*(int *)(*(long *)(param_1 + 0x25d60) + 4) == 0 &&
              (((lVar2 = *(long *)(param_1 + 0x256d8), lVar2 != 0 && (*(long *)(lVar2 + 0x28) != 0))
               && (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x28) + 0xe8),
                  UNRECOVERED_JUMPTABLE != (code *)0x0)))))) {
                    /* WARNING: Could not recover jumptable at 0x0018c001. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
            return uVar3;
          }
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 0018c0a0 nvmlDeviceSetVgpuSchedulerState =====

int nvmlDeviceSetVgpuSchedulerState(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x40f,"nvmlDeviceSetVgpuSchedulerState",
                 "(nvmlDevice_t device, nvmlVgpuSchedulerSetState_t *pSchedulerState)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018bec0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x40f,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x40f,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0018c280 FUN_0018c280 =====

undefined8 FUN_0018c280(char *param_1,uint param_2,long param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  int local_2c;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_3 != 0)))
     ) {
    iVar1 = FUN_00175bd0(param_1,&local_2c);
    if (iVar1 == 2) {
      return 2;
    }
    if (iVar1 == 0xf) {
      return 0xf;
    }
    if (iVar1 != 0) {
      return 999;
    }
    if (local_2c == 0) {
      if (DAT_01216a78 < 4) {
        return 3;
      }
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar3,"api.c",0x2cdd);
      return 3;
    }
    if (param_2 < 3) {
      lVar3 = *(long *)(param_1 + 0x256d8);
      if (((lVar3 != 0) && (*(undefined8 **)(lVar3 + 0xe0) != (undefined8 *)0x0)) &&
         (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar3 + 0xe0),
         UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0018c363. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar3,param_1,param_2,param_3);
        return uVar2;
      }
      return 3;
    }
  }
  return 2;
}


// ===== 0018c3f0 nvmlDeviceGetEncoderCapacity =====

int nvmlDeviceGetEncoderCapacity(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x42d,"nvmlDeviceGetEncoderCapacity",
                 "(nvmlDevice_t device, nvmlEncoderType_t encoderQueryType, unsigned int *pEncoderCapacity)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018c280(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x42d,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x42d,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0018c5c0 FUN_0018c5c0 =====

int FUN_0018c5c0(long param_1,undefined8 param_2,uint *param_3,long param_4)

{
  uint uVar1;
  double dVar2;
  code *pcVar3;
  long *plVar4;
  int *piVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  undefined4 *puVar10;
  float fVar11;
  undefined4 local_89dc;
  int local_89d8;
  int local_89d4;
  undefined8 local_89d0;
  int local_89c8 [20];
  undefined1 local_8978 [35144];
  
  memset(local_8978,0,0x8940);
  local_89dc = 0x48;
  local_89d8 = 0;
  local_89d0 = 0;
  iVar6 = FUN_00175bd0(param_1,local_89c8);
  if (iVar6 == 2) {
    return 2;
  }
  if (iVar6 == 0xf) {
    return 0xf;
  }
  if (iVar6 != 0) {
    return 999;
  }
  if (local_89c8[0] == 0) {
    if (3 < DAT_01216a78) {
      fVar11 = (float)FUN_002917b0(&DAT_01216a60);
      lVar9 = syscall(0xba);
      FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar9,"api.c",0x2cfb);
      return 3;
    }
    return 3;
  }
  lVar9 = *(long *)(param_1 + 0x25d60);
  if (lVar9 == 0) {
    return 3;
  }
  if (param_3 == (uint *)0x0) {
    return 2;
  }
  iVar6 = FUN_00138b90(param_1);
  if ((iVar6 == 0) && (*(int *)(lVar9 + 0x628) == 0)) {
    lVar7 = *(long *)(param_1 + 0x256d8);
    if (lVar7 == 0) {
      return 3;
    }
    if (*(long *)(lVar7 + 0x28) == 0) {
      return 3;
    }
    pcVar3 = *(code **)(*(long *)(lVar7 + 0x28) + 0x48);
    if (pcVar3 == (code *)0x0) {
      return 3;
    }
    iVar6 = (*pcVar3)(lVar7,param_1);
    if (iVar6 != 0) {
      return iVar6;
    }
  }
  if (*(int *)(lVar9 + 4) != 0) {
    if ((param_4 == 0) || (*param_3 < 0x48)) {
      *param_3 = 0x48;
      return 7;
    }
    iVar6 = FUN_00156380(param_1,&local_89d8);
    if (iVar6 != 0) {
      return iVar6;
    }
    if (local_89d8 != 0) {
      lVar7 = *(long *)(param_1 + 0x256d8);
      if (((lVar7 == 0) || (*(long *)(lVar7 + 0x128) == 0)) ||
         (pcVar3 = *(code **)(*(long *)(lVar7 + 0x128) + 0x10), pcVar3 == (code *)0x0)) {
        iVar6 = 3;
      }
      else {
        iVar6 = (*pcVar3)(lVar7,param_1,param_2,&local_89dc,local_8978,1);
        if (iVar6 == 6) goto LAB_0018ca10;
        if (iVar6 == 0) {
          iVar6 = FUN_00234b40(local_89c8,FUN_00121360,FUN_00121370,free,free);
          if (iVar6 != 0) {
            return 999;
          }
          iVar6 = FUN_00121820(local_89c8,local_8978,local_89dc,&local_89d0);
          if (iVar6 != 0) {
            FUN_00234bf0(local_89c8);
            FUN_00121ff0(&local_89d0);
            return 999;
          }
          plVar4 = *(long **)(lVar9 + 0x618);
          uVar1 = 0;
          if ((long *)(lVar9 + 0x618) != plVar4) {
            do {
              lVar7 = thunk_FUN_00121800(local_89d0,*(undefined4 *)((long)plVar4 + -0x20c));
              if (lVar7 != 0) {
                for (piVar5 = *(int **)(lVar7 + 0x10); piVar5 != (int *)0x0;
                    piVar5 = *(int **)(piVar5 + 0x12)) {
                  iVar6 = *piVar5;
                  local_89d4 = iVar6 * 100 + *(int *)(lVar7 + 4);
                  lVar8 = FUN_00234de0(local_89c8,&local_89d4);
                  if (lVar8 != 0) {
                    puVar10 = (undefined4 *)((ulong)uVar1 * 0x60 + param_4);
                    puVar10[0x14] = (int)(long)*(double *)(lVar8 + 0x10);
                    puVar10[0x15] = (int)(long)*(double *)(lVar8 + 0x18);
                    puVar10[0x16] = (int)(long)*(double *)(lVar8 + 0x20);
                    dVar2 = *(double *)(lVar8 + 0x28);
                    puVar10[1] = iVar6;
                    puVar10[0x17] = (int)(long)dVar2;
                    strncpy((char *)(puVar10 + 2),(char *)(piVar5 + 1),0x40);
                    uVar1 = uVar1 + 1;
                    *puVar10 = (int)plVar4[-0x43];
                    *(undefined8 *)(puVar10 + 0x12) = *(undefined8 *)(lVar8 + 8);
                  }
                }
              }
              plVar4 = (long *)*plVar4;
            } while ((long *)(lVar9 + 0x618) != plVar4);
          }
          *param_3 = uVar1;
          FUN_00234bf0(local_89c8);
          FUN_00121ff0(&local_89d0);
          return 0;
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar6;
      }
      fVar11 = (float)FUN_002917b0(&DAT_01216a60);
      lVar9 = syscall(0xba);
      FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar9,"api.c",0x2d35,"tsapiDeviceGetVgpuProcessUtilization",0x2d35,iVar6)
      ;
      return iVar6;
    }
  }
LAB_0018ca10:
  *param_3 = 0;
  return 0;
}


// ===== 0018cb20 nvmlDeviceGetVgpuProcessUtilization =====

int nvmlDeviceGetVgpuProcessUtilization
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %llu %p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x46a,"nvmlDeviceGetVgpuProcessUtilization",
                 "(nvmlDevice_t device, unsigned long long lastSeenTimeStamp, unsigned int *vgpuProcessSamplesCount, nvmlVgpuProcessUtilizationSample_t *utilizationSamples)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018c5c0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x46a,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x46a,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0018cd10 FUN_0018cd10 =====

ulong FUN_0018cd10(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x2d73);
        }
      }
      else if (param_2 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x128) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x128) + 0x50),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0018cda6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 0018ce40 nvmlDeviceGetVgpuProcessesUtilizationInfo =====

int nvmlDeviceGetVgpuProcessesUtilizationInfo(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x471,"nvmlDeviceGetVgpuProcessesUtilizationInfo",
                 "(nvmlDevice_t device, nvmlVgpuProcessesUtilizationInfo_t *vgpuProcUtilInfo)",
                 param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018cd10(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x471,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x471,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0018d020 FUN_0018d020 =====

ulong FUN_0018d020(char *param_1,long param_2,long param_3,long param_4)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_3c [3];
  
  if ((param_1 == (char *)0x0) ||
     (((*param_1 != '\x01' &&
       ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
         (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) ||
      ((param_3 == 0 || param_4 == 0 || (param_2 == 0)))))) {
    uVar3 = 2;
  }
  else {
    uVar1 = FUN_00175bd0(param_1,local_3c);
    uVar3 = (ulong)uVar1;
    if ((uVar1 != 2) && (uVar1 != 0xf)) {
      if (uVar1 == 0) {
        if (local_3c[0] == 0) {
          uVar3 = 3;
          if (3 < DAT_01216a78) {
            fVar4 = (float)FUN_002917b0(&DAT_01216a60);
            lVar2 = syscall(0xba);
            FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                         &DAT_002983c2,lVar2,"api.c",0x2d83);
          }
        }
        else {
          lVar2 = *(long *)(param_1 + 0x256d8);
          if (((lVar2 != 0) && (*(long *)(lVar2 + 0xe0) != 0)) &&
             (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0xe0) + 8),
             UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0018d103. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2,param_3,param_4);
            return uVar3;
          }
          uVar3 = 3;
        }
      }
      else {
        uVar3 = 999;
      }
    }
  }
  return uVar3;
}


// ===== 0018d180 nvmlDeviceGetEncoderStats =====

int nvmlDeviceGetEncoderStats
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %p %p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x432,"nvmlDeviceGetEncoderStats",
                 "(nvmlDevice_t device, unsigned int *sessionCount, unsigned int *averageFps, unsigned int *averageLatency)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018d020(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x432,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x432,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0018d370 FUN_0018d370 =====

undefined8 FUN_0018d370(char *param_1,int *param_2,long param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  float fVar4;
  uint local_3c [3];
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) &&
      (param_2 != (int *)0x0)))) {
    iVar1 = FUN_00175bd0(param_1,local_3c);
    if (iVar1 == 2) {
      return 2;
    }
    if (iVar1 == 0xf) {
      return 0xf;
    }
    if (iVar1 != 0) {
      return 999;
    }
    if (local_3c[0] == 0) {
      if (3 < DAT_01216a78) {
        fVar4 = (float)FUN_002917b0(&DAT_01216a60);
        lVar2 = syscall(0xba);
        FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                     &DAT_002983c2,lVar2,"api.c",0x2d8e);
        return 3;
      }
      return 3;
    }
    if ((*param_2 == 0) || (param_3 != 0)) {
      lVar2 = *(long *)(param_1 + 0x256d8);
      local_3c[0] = local_3c[0] & 0xffffff00;
      if (lVar2 != 0) {
        if ((*(long *)(lVar2 + 0x38) != 0) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x38) + 0x80),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
          (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,local_3c);
          if ((char)local_3c[0] != '\0') {
            return 3;
          }
          lVar2 = *(long *)(param_1 + 0x256d8);
        }
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0xe0) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0xe0) + 0x10),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0018d50a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2,param_3);
          return uVar3;
        }
      }
      return 3;
    }
  }
  return 2;
}


// ===== 0018d510 nvmlDeviceGetEncoderSessions =====

int nvmlDeviceGetEncoderSessions(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x438,"nvmlDeviceGetEncoderSessions",
                 "(nvmlDevice_t device, unsigned int *sessionCount, nvmlEncoderSessionInfo_t *sessionInfos)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018d370(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x438,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x438,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0018d6e0 FUN_0018d6e0 =====

ulong FUN_0018d6e0(char *param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  ulong uVar2;
  long lVar3;
  float fVar4;
  int local_2c [3];
  
  if (((param_1 == (char *)0x0) ||
      ((*param_1 != '\x01' &&
       ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
         (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))))) || (param_2 == 0)
     ) {
    uVar2 = 2;
  }
  else {
    uVar1 = FUN_00175bd0(param_1,local_2c);
    uVar2 = (ulong)uVar1;
    if ((uVar1 != 2) && (uVar1 != 0xf)) {
      if (uVar1 != 0) {
        return 999;
      }
      if (local_2c[0] == 0) {
        uVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar3,"api.c",0x2da3);
        }
      }
      else {
        lVar3 = *(long *)(param_1 + 0x256d8);
        if (((lVar3 != 0) && (*(undefined8 **)(lVar3 + 0xf8) != (undefined8 *)0x0)) &&
           (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar3 + 0xf8),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0018d7a9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar3,param_1,param_2);
          return uVar2;
        }
        uVar2 = 3;
      }
    }
  }
  return uVar2;
}


// ===== 0018d830 nvmlDeviceGetFBCStats =====

int nvmlDeviceGetFBCStats(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x43d,"nvmlDeviceGetFBCStats",
                 "(nvmlDevice_t device, nvmlFBCStats_t *fbcStats)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018d6e0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x43d,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x43d,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0018da10 FUN_0018da10 =====

undefined8 FUN_0018da10(char *param_1,int *param_2,long param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  int local_2c;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) &&
      (param_2 != (int *)0x0)))) {
    iVar1 = FUN_00175bd0(param_1,&local_2c);
    if (iVar1 == 2) {
      return 2;
    }
    if (iVar1 == 0xf) {
      return 0xf;
    }
    if (iVar1 != 0) {
      return 999;
    }
    if (local_2c == 0) {
      if (DAT_01216a78 < 4) {
        return 3;
      }
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar3,"api.c",0x2dae);
      return 3;
    }
    if ((*param_2 == 0) || (param_3 != 0)) {
      lVar3 = *(long *)(param_1 + 0x256d8);
      if ((lVar3 != 0) &&
         ((*(long *)(lVar3 + 0xf8) != 0 &&
          (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar3 + 0xf8) + 8),
          UNRECOVERED_JUMPTABLE != (code *)0x0)))) {
                    /* WARNING: Could not recover jumptable at 0x0018dae8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar3,param_1,param_2,param_3);
        return uVar2;
      }
      return 3;
    }
  }
  return 2;
}


// ===== 0018db70 nvmlDeviceGetFBCSessions =====

int nvmlDeviceGetFBCSessions(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x442,"nvmlDeviceGetFBCSessions",
                 "(nvmlDevice_t device, unsigned int *sessionCount, nvmlFBCSessionInfo_t *sessionInfo)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018da10(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x442,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x442,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0018dd40 FUN_0018dd40 =====

int FUN_0018dd40(long param_1,long param_2,uint *param_3,undefined8 param_4)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  ulong uVar7;
  ulong uVar8;
  float fVar9;
  double dVar10;
  undefined4 local_89dc;
  int local_89d8;
  undefined4 local_89d4;
  undefined4 *local_89d0;
  int local_89c8 [20];
  undefined1 local_8978 [35144];
  
  memset(local_8978,0,0x8940);
  local_89dc = 0x48;
  local_89d8 = 0;
  local_89d0 = (undefined4 *)0x0;
  iVar3 = FUN_00175bd0(param_1,local_89c8);
  if (iVar3 == 2) {
    return 2;
  }
  if (iVar3 == 0xf) {
    return 0xf;
  }
  if (iVar3 == 0) {
    if (local_89c8[0] == 0) {
      if (DAT_01216a78 < 4) {
        return 3;
      }
      fVar9 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar4,"api.c",0x2f18);
      return 3;
    }
    if (param_3 == (uint *)0x0) {
      return 2;
    }
    if ((param_2 == 0) || (*param_3 < 0x48)) {
      *param_3 = 0x48;
      return 7;
    }
    iVar3 = FUN_00156380(param_1,&local_89d8);
    if (iVar3 != 0) {
      return iVar3;
    }
    if (local_89d8 == 0) {
      *param_3 = 0;
      return 0;
    }
    lVar4 = *(long *)(param_1 + 0x256d8);
    if (((lVar4 == 0) || (*(long *)(lVar4 + 0x128) == 0)) ||
       (pcVar2 = *(code **)(*(long *)(lVar4 + 0x128) + 0x10), pcVar2 == (code *)0x0)) {
      iVar3 = 3;
    }
    else {
      iVar3 = (*pcVar2)(lVar4,param_1,param_4,&local_89dc,local_8978,0);
      if (iVar3 == 0) {
        iVar3 = FUN_00234b40(local_89c8,FUN_0012f5d0,FUN_0012f5e0,free,free);
        if (iVar3 != 0) {
          return 999;
        }
        iVar3 = FUN_0012f700(local_89c8,local_8978,local_89dc,&local_89d0);
        if (iVar3 == 0) {
          if (local_89d0 != (undefined4 *)0x0) {
            puVar6 = local_89d0;
            uVar7 = 0;
            do {
              uVar1 = *puVar6;
              local_89d4 = uVar1;
              lVar4 = FUN_00234de0(local_89c8,&local_89d4);
              uVar8 = uVar7;
              if (lVar4 != 0) {
                dVar10 = *(double *)(lVar4 + 0x10);
                if ((double)(DAT_002a7a80 & (ulong)dVar10) < DAT_0029b9f8) {
                  dVar10 = (double)((ulong)((double)(long)dVar10 +
                                           (double)(-(ulong)((double)(long)dVar10 < dVar10) &
                                                   DAT_00298b60)) | ~DAT_002a7a80 & (ulong)dVar10);
                }
                uVar8 = (ulong)((int)uVar7 + 1);
                puVar5 = (undefined4 *)(uVar7 * 0x20 + param_2);
                puVar5[4] = (int)(long)dVar10;
                puVar5[5] = (int)(long)*(double *)(lVar4 + 0x18);
                puVar5[6] = (int)(long)*(double *)(lVar4 + 0x20);
                dVar10 = *(double *)(lVar4 + 0x28);
                *puVar5 = uVar1;
                puVar5[7] = (int)(long)dVar10;
                *(undefined8 *)(puVar5 + 2) = *(undefined8 *)(lVar4 + 8);
              }
              puVar6 = *(undefined4 **)(puVar6 + 2);
              *param_3 = (uint)uVar8;
              uVar7 = uVar8;
            } while (puVar6 != (undefined4 *)0x0);
          }
          FUN_00234bf0(local_89c8);
          FUN_0012fe20(&local_89d0);
          return 0;
        }
        FUN_00234bf0(local_89c8);
        FUN_0012fe20(&local_89d0);
        goto LAB_0018ddc0;
      }
    }
    if (1 < DAT_01216a78) {
      fVar9 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"api.c",0x2f36,"tsapiDeviceGetProcessUtilization",0x2f36,iVar3);
    }
  }
  else {
LAB_0018ddc0:
    iVar3 = 999;
  }
  return iVar3;
}


// ===== 0018e160 nvmlDeviceGetProcessUtilization =====

int nvmlDeviceGetProcessUtilization
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p, %llu)\n","DEBUG",
                 lVar3,"entry_points.h",0x48b,"nvmlDeviceGetProcessUtilization",
                 "(nvmlDevice_t device, nvmlProcessUtilizationSample_t *utilization, unsigned int *processSamplesCount, unsigned long long lastSeenTimeStamp)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018dd40(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x48b,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x48b,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0018e350 FUN_0018e350 =====

ulong FUN_0018e350(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x2f69);
        }
      }
      else if (param_2 == 0) {
        uVar3 = 2;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x128) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x128) + 0x18),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0018e3e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 0018e480 nvmlDeviceGetProcessesUtilizationInfo =====

int nvmlDeviceGetProcessesUtilizationInfo(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x491,"nvmlDeviceGetProcessesUtilizationInfo",
                 "(nvmlDevice_t device, nvmlProcessesUtilizationInfo_t *procesesUtilInfo)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018e350(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x491,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x491,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0018e660 FUN_0018e660 =====

undefined8 FUN_0018e660(char *param_1,undefined4 param_2,long param_3,undefined8 param_4)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  int local_3c [3];
  
  iVar1 = FUN_00175bd0(param_1,local_3c);
  if (iVar1 == 2) {
    return 2;
  }
  if (iVar1 == 0xf) {
    return 0xf;
  }
  if (iVar1 != 0) {
    return 999;
  }
  if (local_3c[0] == 0) {
    if (DAT_01216a78 < 4) {
      return 3;
    }
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar3,"api.c",0x36b7);
    return 3;
  }
  if ((param_1 == (char *)0x0) || (param_3 == 0)) {
LAB_0018e7c8:
    uVar2 = 2;
  }
  else {
    if (*param_1 != '\x01') {
      if (*(long *)(param_1 + 0x20) == 0) {
        uVar2 = FUN_001379e0(param_1,param_2,param_3,param_4);
        return uVar2;
      }
      if (((*(int *)(param_1 + 0x14) == 0) || (*(int *)(param_1 + 0x1c) != 0)) ||
         (*(int *)(param_1 + 0x10) == 0)) goto LAB_0018e7c8;
    }
    lVar3 = *(long *)(param_1 + 0x256d8);
    if (((lVar3 != 0) && (*(long *)(lVar3 + 0xc0) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar3 + 0xc0) + 8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0018e745. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar3,param_1,param_2,param_3,param_4);
      return uVar2;
    }
    uVar2 = 3;
  }
  return uVar2;
}


// ===== 0018e810 FUN_0018e810 =====

void FUN_0018e810(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_0018e660(param_1,0,param_2,param_3);
  return;
}


// ===== 0018e820 FUN_0018e820 =====

int FUN_0018e820(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa4a,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018e810(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xa4a,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0018e960 FUN_0018e960 =====

void FUN_0018e960(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_0018e660(param_1,2,param_2,param_3);
  return;
}


// ===== 0018e970 FUN_0018e970 =====

int FUN_0018e970(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa4f,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018e960(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xa4f,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0018eab0 FUN_0018eab0 =====

void FUN_0018eab0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_0018e660(param_1,1,param_2,param_3);
  return;
}


// ===== 0018eac0 FUN_0018eac0 =====

int FUN_0018eac0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa54,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018eab0(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xa54,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0018ec00 FUN_0018ec00 =====

ulong FUN_0018ec00(long param_1,undefined8 param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  float fVar4;
  int local_2c [3];
  
  uVar1 = FUN_00175bd0(param_1,local_2c);
  uVar3 = (ulong)uVar1;
  if ((uVar1 != 2) && (uVar1 != 0xf)) {
    if (uVar1 == 0) {
      if (local_2c[0] == 0) {
        uVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar2,"api.c",0x36ef);
        }
      }
      else {
        lVar2 = *(long *)(param_1 + 0x256d8);
        if (((lVar2 != 0) && (*(long *)(lVar2 + 0x78) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x78) + 0x18),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0018ec8a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
          return uVar3;
        }
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 0018ed10 FUN_0018ed10 =====

int FUN_0018ed10(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa59,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018ec00(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xa59,iVar1,uVar2);
  return iVar1;
}


// ===== 0018ee50 FUN_0018ee50 =====

int FUN_0018ee50(long param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 uVar5;
  uint uVar6;
  float fVar7;
  double dVar8;
  undefined8 uVar9;
  undefined4 local_38;
  int local_34;
  uint local_30 [2];
  
  local_38 = 0;
  iVar2 = FUN_0014b320(param_1,&local_38);
  if (iVar2 != 0) {
    return iVar2;
  }
  lVar4 = *(long *)(param_1 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x48) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x48), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar4,param_1,local_30);
    if (iVar2 == 0) {
      switch(local_38) {
      default:
        return 3;
      case 1:
      case 0xc:
      case 0xd:
        if (*(int *)(param_1 + 0x71c) == 0) {
          do {
            iVar2 = FUN_00291820(param_1 + 0x720,1,0);
          } while (iVar2 != 0);
          if (*(int *)(param_1 + 0x71c) == 0) {
            lVar4 = *(long *)(param_1 + 0x256d8);
            uVar3 = 3;
            if (((lVar4 != 0) && (*(long *)(lVar4 + 0x20) != 0)) &&
               (pcVar1 = *(code **)(*(long *)(lVar4 + 0x20) + 0x98), pcVar1 != (code *)0x0)) {
              uVar3 = (*pcVar1)(lVar4,param_1,param_1 + 0x708);
            }
            *(undefined4 *)(param_1 + 0x724) = uVar3;
            *(undefined4 *)(param_1 + 0x71c) = 1;
          }
          FUN_00291830(param_1 + 0x720,0);
        }
        iVar2 = *(int *)(param_1 + 0x724);
        if (iVar2 == 0) {
          uVar6 = *(uint *)(param_1 + 0x708);
          if (uVar6 < 7) {
            if (((local_30[0] & 0xfffeffff) == 0x13ba10de) || (local_30[0] == 0x13bc10de)) {
              if (DAT_01216a78 < 5) {
                return 0;
              }
              iVar2 = *(int *)(param_1 + 0x710);
              fVar7 = (float)FUN_002917b0(&DAT_01216a60);
              lVar4 = syscall(0xba);
              fVar7 = fVar7 * DAT_00298548;
              uVar5 = 0x24c;
            }
            else {
              if ((uVar6 != 6) || (iVar2 = *(int *)(param_1 + 0x710), iVar2 - 7U < 2)) {
                if (DAT_01216a78 < 5) {
                  return 3;
                }
                uVar3 = *(undefined4 *)(param_1 + 0x710);
                fVar7 = (float)FUN_002917b0(&DAT_01216a60);
                lVar4 = syscall(0xba);
                FUN_002340f0((double)(fVar7 * DAT_00298548),
                             "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u\n","DEBUG",lVar4,"api.c",
                             0x25a,uVar6,uVar3);
                return 3;
              }
              if (DAT_01216a78 < 5) {
                return 0;
              }
              fVar7 = (float)FUN_002917b0(&DAT_01216a60);
              lVar4 = syscall(0xba);
              uVar6 = 6;
              fVar7 = fVar7 * DAT_00298548;
              uVar5 = 0x25f;
            }
            FUN_002340f0((double)fVar7,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u\n","DEBUG",lVar4,
                         "api.c",uVar5,uVar6,iVar2);
            return 0;
          }
          if (DAT_01216a78 < 5) {
            return 0;
          }
          fVar7 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          uVar5 = 0x243;
          dVar8 = (double)(fVar7 * DAT_00298548);
LAB_0018f32d:
          FUN_002340f0(dVar8,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",lVar4,"api.c",uVar5);
          return 0;
        }
        if (DAT_01216a78 < 2) {
          return iVar2;
        }
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        uVar9 = 0x23f;
        uVar5 = 0x23f;
        dVar8 = (double)(fVar7 * DAT_00298548);
        break;
      case 2:
      case 7:
      case 8:
      case 9:
      case 10:
      case 0xb:
      case 0xe:
        iVar2 = FUN_00175bd0(param_1,&local_34);
        if (iVar2 == 2) {
          return 2;
        }
        if (iVar2 == 0xf) {
          return 0xf;
        }
        if (iVar2 != 0) {
          return 999;
        }
        if (local_34 == 0) {
          if (3 < DAT_01216a78) {
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                         &DAT_002983c2,lVar4,"api.c",0x235);
            return 3;
          }
          return 3;
        }
        return 0;
      case 5:
      case 6:
      case 0xf:
      case 0x10:
        if (*(int *)(param_1 + 0x71c) == 0) {
          do {
            iVar2 = FUN_00291820(param_1 + 0x720,1,0);
          } while (iVar2 != 0);
          if (*(int *)(param_1 + 0x71c) == 0) {
            lVar4 = *(long *)(param_1 + 0x256d8);
            uVar3 = 3;
            if (((lVar4 != 0) && (*(long *)(lVar4 + 0x20) != 0)) &&
               (pcVar1 = *(code **)(*(long *)(lVar4 + 0x20) + 0x98), pcVar1 != (code *)0x0)) {
              uVar3 = (*pcVar1)(lVar4,param_1,param_1 + 0x708);
            }
            *(undefined4 *)(param_1 + 0x724) = uVar3;
            *(undefined4 *)(param_1 + 0x71c) = 1;
          }
          FUN_00291830(param_1 + 0x720,0);
        }
        iVar2 = *(int *)(param_1 + 0x724);
        if (iVar2 == 0) {
          iVar2 = FUN_00139690(param_1,&local_34);
          if (iVar2 != 0) {
            return iVar2;
          }
          if (local_34 == 0) {
            return 3;
          }
          if (*(uint *)(param_1 + 0x708) < 7) {
            if (DAT_01216a78 < 5) {
              return 0;
            }
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            uVar5 = 0x277;
            dVar8 = (double)(fVar7 * DAT_00298548);
          }
          else {
            if (*(int *)(param_1 + 0x25374) == 0) {
              do {
                iVar2 = FUN_00291820(param_1 + 0x25378,1,0);
              } while (iVar2 != 0);
              if (*(int *)(param_1 + 0x25374) == 0) {
                lVar4 = *(long *)(param_1 + 0x256d8);
                uVar3 = 3;
                if (((lVar4 != 0) && (*(long *)(lVar4 + 0x170) != 0)) &&
                   (pcVar1 = *(code **)(*(long *)(lVar4 + 0x170) + 0x158), pcVar1 != (code *)0x0)) {
                  uVar3 = (*pcVar1)(lVar4,param_1,param_1 + 0x25370);
                }
                *(undefined4 *)(param_1 + 0x2537c) = uVar3;
                *(undefined4 *)(param_1 + 0x25374) = 1;
              }
              FUN_00291830(param_1 + 0x25378,0);
            }
            iVar2 = *(int *)(param_1 + 0x2537c);
            if (iVar2 != 0) {
              if (1 < DAT_01216a78) {
                fVar7 = (float)FUN_002917b0(&DAT_01216a60);
                lVar4 = syscall(0xba);
                FUN_002340f0((double)(fVar7 * DAT_00298548),
                             "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","ERROR",lVar4,"api.c",0x282,
                             iVar2);
                return iVar2;
              }
              return iVar2;
            }
            if (*(int *)(param_1 + 0x25370) == 0) {
              if (DAT_01216a78 < 5) {
                return 3;
              }
              fVar7 = (float)FUN_002917b0(&DAT_01216a60);
              lVar4 = syscall(0xba);
              FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                           "DEBUG",lVar4,"api.c",0x288);
              return 3;
            }
            if (DAT_01216a78 < 5) {
              return 0;
            }
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            uVar5 = 0x28c;
            dVar8 = (double)(fVar7 * DAT_00298548);
          }
          goto LAB_0018f32d;
        }
        if (DAT_01216a78 < 2) {
          return iVar2;
        }
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        uVar9 = 0x26d;
        uVar5 = 0x26d;
        dVar8 = (double)(fVar7 * DAT_00298548);
      }
      goto LAB_0018ef35;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar7 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  uVar9 = 0x221;
  uVar5 = 0x221;
  dVar8 = (double)(fVar7 * DAT_00298548);
LAB_0018ef35:
  FUN_002340f0(dVar8,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,"api.c",uVar5,
               "deviceSupportsApplicationClocks",uVar9,iVar2);
  return iVar2;
}


// ===== 0018f690 FUN_0018f690 =====

ulong FUN_0018f690(char *param_1,undefined4 param_2,int param_3,long param_4)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  ulong uVar2;
  long lVar3;
  float fVar4;
  
  if ((param_1 == (char *)0x0) ||
     (((*param_1 != '\x01' &&
       ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
         (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) || (param_4 == 0)))
     ) {
    return 2;
  }
  if (param_3 - 1U < 2) {
    uVar1 = FUN_0018ee50(param_1);
    if (uVar1 != 0) {
      if (DAT_01216a78 < 2) {
        return (ulong)uVar1;
      }
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","ERROR",
                   lVar3,"api.c",0x197e,param_3);
      return (ulong)uVar1;
    }
  }
  lVar3 = *(long *)(param_1 + 0x256d8);
  if (((lVar3 != 0) && (*(long *)(lVar3 + 0x170) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar3 + 0x170) + 0x108),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0018f713. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar3,param_1,param_2,param_3,param_4);
    return uVar2;
  }
  return 3;
}


// ===== 0018f7e0 nvmlDeviceGetClock =====

int nvmlDeviceGetClock(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d, %d, %p)\n","DEBUG",lVar3
                 ,"entry_points.h",0x238,"nvmlDeviceGetClock",
                 "(nvmlDevice_t device, nvmlClockType_t clockType, nvmlClockId_t clockId, unsigned int *clockMHz)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018f690(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x238,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x238,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0018f9d0 FUN_0018f9d0 =====

undefined8 FUN_0018f9d0(char *param_1)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    uVar2 = FUN_0018ee50(param_1);
    if ((int)uVar2 == 0) {
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
         (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0xf8),
         UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0018fa40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1);
        return uVar2;
      }
      return 3;
    }
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}


// ===== 0018fa70 nvmlDeviceResetApplicationsClocks =====

int nvmlDeviceResetApplicationsClocks(char *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  char *pcVar5;
  
  pcVar5 = param_1;
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    pcVar5 = "(nvmlDevice_t device)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x240,"nvmlDeviceResetApplicationsClocks");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_0018f9d0(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x240,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x240,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0018fc40 FUN_0018fc40 =====

undefined8 FUN_0018fc40(char *param_1,undefined4 param_2,long param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if (((*param_1 == '\x01') ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_3 != 0)) {
    uVar2 = FUN_0018ee50(param_1);
    if ((int)uVar2 == 0) {
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
         (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0xe8),
         UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0018fcce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,1,param_3);
        return uVar2;
      }
      return 3;
    }
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}


// ===== 0018fd00 nvmlDeviceGetDefaultApplicationsClock =====

int nvmlDeviceGetDefaultApplicationsClock(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x23c,"nvmlDeviceGetDefaultApplicationsClock",
                 "(nvmlDevice_t device, nvmlClockType_t clockType, unsigned int *clockMHz)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018fc40(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x23c,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x23c,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0018fed0 FUN_0018fed0 =====

undefined8 FUN_0018fed0(char *param_1,uint param_2,long param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if (((*param_1 == '\x01') ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) &&
     ((param_2 < 5 && (param_3 != 0)))) {
    uVar2 = FUN_0018ee50(param_1);
    if ((int)uVar2 == 0) {
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
         (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0xe8),
         UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0018ff61. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,0,param_3);
        return uVar2;
      }
      return 3;
    }
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}


// ===== 0018ffa0 nvmlDeviceGetApplicationsClock =====

int nvmlDeviceGetApplicationsClock(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x230,"nvmlDeviceGetApplicationsClock",
                 "(nvmlDevice_t device, nvmlClockType_t clockType, unsigned int *clockMHz)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0018fed0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x230,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x230,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00190170 FUN_00190170 =====

int FUN_00190170(long param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  undefined1 local_43c8 [17304];
  
  iVar2 = FUN_0018ee50();
  if (iVar2 == 0) {
    lVar3 = *(long *)(param_1 + 0x256d8);
    if (((lVar3 == 0) || (*(long *)(lVar3 + 0x170) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(lVar3 + 0x170) + 0x140), pcVar1 == (code *)0x0)) {
      iVar2 = 3;
    }
    else {
      iVar2 = (*pcVar1)(lVar3,param_1,local_43c8);
      if (iVar2 == 0) {
        lVar3 = *(long *)(param_1 + 0x256d8);
        if (((lVar3 != 0) && (*(long *)(lVar3 + 0x170) != 0)) &&
           (pcVar1 = *(code **)(*(long *)(lVar3 + 0x170) + 0xa0), pcVar1 != (code *)0x0)) {
          iVar2 = (*pcVar1)(lVar3,param_1,param_2,param_3,local_43c8);
          return iVar2;
        }
        return 3;
      }
    }
    if (1 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar3,"api.c",0x1919,"tsapiDeviceSetApplicationsClocks",0x1919,iVar2);
    }
  }
  return iVar2;
}


// ===== 001902d0 FUN_001902d0 =====

undefined8 FUN_001902d0(char *param_1)

{
  undefined8 uVar1;
  
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    uVar1 = FUN_00190170();
    return uVar1;
  }
  return 2;
}


// ===== 00190310 nvmlDeviceSetApplicationsClocks =====

int nvmlDeviceSetApplicationsClocks(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %u, %u)\n","DEBUG",lVar3,
                 "entry_points.h",0x22c,"nvmlDeviceSetApplicationsClocks",
                 "(nvmlDevice_t device, unsigned int memClockMHz, unsigned int graphicsClockMHz)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001902d0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x22c,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x22c,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001904e0 FUN_001904e0 =====

undefined8 FUN_001904e0(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = DAT_01214898;
    return 0;
  }
  return 2;
}


// ===== 00190510 nvmlDeviceGetCount_v2 =====

int nvmlDeviceGetCount_v2(char *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  char *pcVar5;
  
  pcVar5 = param_1;
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    pcVar5 = "(unsigned int *deviceCount)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0xaa9,"nvmlDeviceGetCount_v2");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_001904e0(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xaa9,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xaa9,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001906e0 FUN_001906e0 =====

uint FUN_001906e0(void)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint local_2c [3];
  
  uVar2 = FUN_001904e0(local_2c);
  if ((uVar2 == 0) && (local_2c[0] != 0)) {
    uVar4 = 0;
    do {
      if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x20) == 0)) ||
         (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0xb8), pcVar1 == (code *)0x0)) {
        return 3;
      }
      uVar3 = (*pcVar1)(DAT_012164a0,&DAT_00380898 + (ulong)uVar4 * 0x74a00);
      if ((uVar3 & 0xfffffffb) != 0) {
        return uVar3;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < local_2c[0]);
  }
  return uVar2;
}


// ===== 00190770 FUN_00190770 =====

int FUN_00190770(uint param_1,undefined8 *param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  
  if ((DAT_01214898 <= param_1) || (param_2 == (undefined8 *)0x0)) {
    return 2;
  }
  *param_2 = &DAT_00380898 + (ulong)param_1 * 0x74a00;
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x20) != 0)) &&
     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0xb8), pcVar1 != (code *)0x0)) {
    iVar2 = (*pcVar1)(DAT_012164a0,&DAT_00380898 + (ulong)param_1 * 0x74a00);
    if ((iVar2 == 9) && (iVar2 = 999, 4 < DAT_01216a78)) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                   lVar3,"api.c",0x39ae);
    }
    return iVar2;
  }
  return 3;
}


// ===== 00190870 nvmlDeviceGetHandleByIndex_v2 =====

int nvmlDeviceGetHandleByIndex_v2(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0xaad,"nvmlDeviceGetHandleByIndex_v2",
                 "(unsigned int index, nvmlDevice_t *device)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00190770(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xaad,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xaad,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00190a50 FUN_00190a50 =====

undefined8 FUN_00190a50(int *param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 local_30 [8];
  
  if (param_1 == (int *)0x0) {
    return 2;
  }
  uVar2 = 0;
  *param_1 = 0;
  if (DAT_01214898 != 0) {
    do {
      iVar1 = FUN_00190770(uVar2,local_30);
      if (iVar1 == 0) {
        *param_1 = *param_1 + 1;
      }
      else if (iVar1 != 4) {
        return 999;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < DAT_01214898);
  }
  return 0;
}


// ===== 00190af0 nvmlDeviceGetCount =====

int nvmlDeviceGetCount(char *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  char *pcVar5;
  
  pcVar5 = param_1;
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    pcVar5 = "(unsigned int *deviceCount)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x2b,"nvmlDeviceGetCount");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_00190a50(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2b,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2b,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00190cc0 FUN_00190cc0 =====

undefined8 FUN_00190cc0(int param_1,long param_2)

{
  undefined8 uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_2 == 0) {
    return 2;
  }
  if (DAT_01214898 != 0) {
    iVar2 = 0;
    uVar3 = 0;
    do {
      uVar1 = FUN_00190770(uVar3,param_2);
      if ((int)uVar1 == 0) {
        if (iVar2 == param_1) {
          return uVar1;
        }
        iVar2 = iVar2 + 1;
      }
      else if ((int)uVar1 != 4) {
        return uVar1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < DAT_01214898);
  }
  return 2;
}


// ===== 00190d50 nvmlDeviceGetHandleByIndex =====

int nvmlDeviceGetHandleByIndex(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x2f,"nvmlDeviceGetHandleByIndex",
                 "(unsigned int index, nvmlDevice_t *device)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00190cc0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2f,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2f,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00190f30 FUN_00190f30 =====

undefined4 FUN_00190f30(byte *param_1,undefined8 *param_2)

{
  int iVar1;
  long lVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  float fVar9;
  undefined1 *local_150;
  char *local_148;
  undefined8 local_138;
  undefined8 local_130;
  undefined1 local_128 [16];
  undefined1 local_118 [16];
  undefined1 local_108 [16];
  undefined1 local_f8 [16];
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  undefined1 local_c8 [16];
  undefined1 local_b8 [16];
  undefined1 local_a8 [16];
  undefined1 local_98 [16];
  char local_88 [88];
  
  local_128 = (undefined1  [16])0x0;
  local_118 = (undefined1  [16])0x0;
  local_108 = (undefined1  [16])0x0;
  local_f8 = (undefined1  [16])0x0;
  local_e8 = (undefined1  [16])0x0;
  local_d8 = (undefined1  [16])0x0;
  local_c8 = (undefined1  [16])0x0;
  local_b8 = (undefined1  [16])0x0;
  local_a8 = (undefined1  [16])0x0;
  local_98 = (undefined1  [16])0x0;
  if (param_1 == (byte *)0x0) {
    return 2;
  }
  bVar6 = false;
  if (param_2 == (undefined8 *)0x0) {
    return 2;
  }
  lVar2 = 4;
  bVar8 = false;
  pbVar3 = param_1;
  pbVar4 = &DAT_002a5d79;
  do {
    if (lVar2 == 0) break;
    lVar2 = lVar2 + -1;
    bVar6 = *pbVar3 < *pbVar4;
    bVar8 = *pbVar3 == *pbVar4;
    pbVar3 = pbVar3 + 1;
    pbVar4 = pbVar4 + 1;
  } while (bVar8);
  bVar7 = false;
  if ((!bVar6 && !bVar8) != bVar6) {
    lVar2 = 4;
    bVar6 = false;
    pbVar3 = param_1;
    pbVar4 = &DAT_002a5d7e;
    do {
      if (lVar2 == 0) break;
      lVar2 = lVar2 + -1;
      bVar7 = *pbVar3 < *pbVar4;
      bVar6 = *pbVar3 == *pbVar4;
      pbVar3 = pbVar3 + 1;
      pbVar4 = pbVar4 + 1;
    } while (bVar6);
    bVar8 = false;
    if ((!bVar7 && !bVar6) != bVar7) {
      lVar2 = 4;
      bVar6 = false;
      pbVar3 = param_1;
      pbVar4 = &DAT_002a5d83;
      do {
        if (lVar2 == 0) break;
        lVar2 = lVar2 + -1;
        bVar8 = *pbVar3 < *pbVar4;
        bVar6 = *pbVar3 == *pbVar4;
        pbVar3 = pbVar3 + 1;
        pbVar4 = pbVar4 + 1;
      } while (bVar6);
      if ((!bVar8 && !bVar6) != bVar8) {
        snprintf(local_128,0x50,"%s%s",&DAT_002a5d79,param_1);
        snprintf(local_d8,0x50,"%s%s",&DAT_002a5d7e,param_1);
        goto joined_r0x00191047;
      }
    }
  }
  snprintf(local_128,0x50,"%s",param_1);
  snprintf(local_d8,0x50,"%s",param_1);
joined_r0x00191047:
  if (DAT_01214898 != 0) {
    local_148 = local_128;
    local_150 = local_d8;
    bVar6 = false;
    uVar5 = 0;
    bVar8 = false;
LAB_00191096:
    do {
      iVar1 = FUN_00190770(uVar5,&local_138);
      if (iVar1 == 0) {
        iVar1 = FUN_0013e340(local_138,local_88,0x50);
        if (iVar1 != 3) {
          if (iVar1 == 0) {
            iVar1 = strcmp(local_88,local_148);
            if (iVar1 == 0) {
              *param_2 = local_138;
              return 0;
            }
            iVar1 = FUN_00137350(local_138,local_150,&local_130);
            if (iVar1 == 0) {
              *param_2 = local_130;
              return 0;
            }
          }
          else {
            bVar6 = true;
            if (iVar1 == 0xf) {
              if (DAT_01216a78 < 2) goto LAB_00191150;
              fVar9 = (float)FUN_002917b0(&DAT_01216a60);
              lVar2 = syscall(0xba);
              FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n",
                           "ERROR",lVar2,"api.c",0x53c,uVar5);
              bVar8 = true;
            }
          }
        }
      }
      else if (iVar1 == 0xf) {
        if (DAT_01216a78 < 2) {
LAB_00191150:
          bVar8 = true;
          bVar6 = true;
          uVar5 = uVar5 + 1;
          if (DAT_01214898 <= uVar5) break;
          goto LAB_00191096;
        }
        bVar6 = true;
        fVar9 = (float)FUN_002917b0(&DAT_01216a60);
        lVar2 = syscall(0xba);
        FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n",
                     "ERROR",lVar2,"api.c",0x526,uVar5);
        bVar8 = true;
      }
      else if (iVar1 != 4) {
        bVar6 = true;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < DAT_01214898);
    if (bVar8) {
      return 0xf;
    }
    if (bVar6) {
      return 999;
    }
  }
  return 6;
}


// ===== 00191360 nvmlDeviceGetHandleByUUID =====

int nvmlDeviceGetHandleByUUID(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x37,"nvmlDeviceGetHandleByUUID",
                 "(const char *uuid, nvmlDevice_t *device)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00190f30(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x37,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x37,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00191540 FUN_00191540 =====

undefined8 FUN_00191540(int *param_1,long param_2)

{
  undefined8 uVar1;
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  undefined1 local_38 [16];
  undefined1 local_28 [16];
  
  local_68 = (undefined1  [16])0x0;
  local_58 = (undefined1  [16])0x0;
  local_48 = (undefined1  [16])0x0;
  local_38 = (undefined1  [16])0x0;
  local_28 = (undefined1  [16])0x0;
  if ((param_1 != (int *)0x0) && (param_2 != 0)) {
    if (*param_1 != 0x1000034) {
      return 0x19;
    }
    if (param_1[1] == 2) {
      snprintf(local_68,0x29,"%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x",
               (ulong)*(byte *)(param_1 + 2),(ulong)*(byte *)((long)param_1 + 9),
               (ulong)*(byte *)((long)param_1 + 10),(ulong)*(byte *)((long)param_1 + 0xb),
               (ulong)*(byte *)(param_1 + 3),(ulong)*(byte *)((long)param_1 + 0xd),
               (ulong)*(byte *)((long)param_1 + 0xe),(ulong)*(byte *)((long)param_1 + 0xf),
               (ulong)*(byte *)(param_1 + 4),(ulong)*(byte *)((long)param_1 + 0x11),
               (ulong)*(byte *)((long)param_1 + 0x12),(ulong)*(byte *)((long)param_1 + 0x13),
               (ulong)*(byte *)(param_1 + 5),(ulong)*(byte *)((long)param_1 + 0x15),
               (ulong)*(byte *)((long)param_1 + 0x16),(ulong)*(byte *)((long)param_1 + 0x17));
    }
    else {
      if (param_1[1] != 1) {
        return 2;
      }
      snprintf(local_68,0x29,"%s",param_1 + 2);
    }
    uVar1 = FUN_00190f30(local_68,param_2);
    return uVar1;
  }
  return 2;
}


// ===== 00191660 nvmlDeviceGetHandleByUUIDV =====

int nvmlDeviceGetHandleByUUIDV(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x3c,"nvmlDeviceGetHandleByUUIDV",
                 "(const nvmlUUID_t *uuid, nvmlDevice_t *device)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00191540(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x3c,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x3c,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00191840 FUN_00191840 =====

/* WARNING: Type propagation algorithm not settling */

ulong FUN_00191840(void)

{
  long *plVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  ulong uVar7;
  uint uVar8;
  long lVar9;
  uint uVar10;
  long *plVar11;
  ulong uVar12;
  ulong uVar13;
  float fVar14;
  long local_1e0;
  long local_1d8;
  long local_1d0;
  ulong local_1c0;
  ulong local_1b8;
  long local_1a0;
  undefined1 local_198 [96];
  char local_138;
  char cStack_137;
  undefined6 uStack_136;
  
  do {
    iVar4 = FUN_00291820(&DAT_01216994,1,0);
  } while (iVar4 != 0);
  if ((DAT_0121699c == 0) && (DAT_01214898 != 1)) {
    iVar4 = FUN_00292de0("__NVML_UNIQUE_SERIAL",&local_138,0x10);
    if ((iVar4 == 0) && ((local_138 == '1' && (cStack_137 == '\0')))) {
      if (4 < DAT_01216a78) {
        fVar14 = (float)FUN_002917b0(&DAT_01216a60);
        lVar9 = syscall(0xba);
        FUN_002340f0((double)(fVar14 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG"
                     ,lVar9,"api.c",0x8ed);
      }
      if (DAT_01214898 != 0) {
        uVar10 = 0;
        uVar12 = 0;
        do {
          uVar7 = FUN_00190770(uVar10,&local_1a0);
          uVar13 = uVar12;
          if ((int)uVar7 == 0) {
            if (*(int *)(local_1a0 + 0xa4) == 0) {
              lVar9 = local_1a0 + 0xa8;
              do {
                iVar4 = FUN_00291820(lVar9,1,0);
              } while (iVar4 != 0);
              if (*(int *)(local_1a0 + 0xa4) == 0) {
                lVar9 = *(long *)(local_1a0 + 0x256d8);
                uVar5 = 3;
                if (((lVar9 != 0) && (*(long *)(lVar9 + 0x38) != 0)) &&
                   (pcVar3 = *(code **)(*(long *)(lVar9 + 0x38) + 0x30), pcVar3 != (code *)0x0)) {
                  uVar5 = (*pcVar3)(lVar9,local_1a0,local_1a0 + 0x84,0x20);
                }
                *(undefined4 *)(local_1a0 + 0xac) = uVar5;
                *(undefined4 *)(local_1a0 + 0xa4) = 1;
              }
              FUN_00291830(local_1a0 + 0xa8,0);
            }
            if (*(int *)(local_1a0 + 0xac) == 0) {
              lVar9 = *(long *)(local_1a0 + 0x256d8);
              if (((lVar9 == 0) || (*(long *)(lVar9 + 0x38) == 0)) ||
                 ((pcVar3 = *(code **)(*(long *)(lVar9 + 0x38) + 0x38), pcVar3 == (code *)0x0 ||
                  (iVar4 = (*pcVar3)(lVar9,local_1a0,local_198,0x60), iVar4 != 0)))) {
                DAT_01216998 = 999;
                if (1 < DAT_01216a78) {
                  fVar14 = (float)FUN_002917b0(&DAT_01216a60);
                  lVar9 = syscall(0xba);
                  FUN_002340f0((double)(fVar14 * DAT_00298548),
                               "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar9,"api.c",0x916);
                }
                goto LAB_00191af0;
              }
              uVar13 = (ulong)((int)uVar12 + 1);
              *(long *)((long)&local_138 + uVar12 * 8) = local_1a0;
            }
          }
          else if ((int)uVar7 != 4) {
            return uVar7;
          }
          uVar10 = uVar10 + 1;
          uVar12 = uVar13;
        } while (uVar10 < DAT_01214898);
        lVar9 = 0;
        uVar10 = (uint)uVar13;
        if (uVar10 != 0) {
          local_1d0 = CONCAT62(uStack_136,CONCAT11(cStack_137,local_138));
          local_1e0 = 0;
          local_1d8 = -8;
          for (local_1c0 = 1; *(long *)((long)&local_138 + lVar9 * 8) = local_1d0,
              local_1c0 != uVar13; local_1c0 = local_1c0 + 1) {
            local_1d0 = *(long *)((long)&local_138 + local_1c0 * 8);
            uVar12 = local_1c0;
            do {
              lVar9 = (long)(int)uVar12;
              lVar2 = *(long *)((long)&local_138 + uVar12 * 8 + local_1d8 + local_1e0);
              iVar4 = strcmp((char *)(local_1d0 + 0x84),(char *)(lVar2 + 0x84));
              if ((-1 < iVar4) &&
                 ((iVar4 != 0 ||
                  (iVar4 = strcmp((char *)(local_1d0 + 0x274),(char *)(lVar2 + 0x274)), -1 < iVar4))
                 )) break;
              *(long *)((long)&local_138 + uVar12 * 8) = lVar2;
              uVar12 = uVar12 - 1;
              lVar9 = (long)(int)uVar12;
            } while ((int)uVar12 != 0);
            local_1d8 = local_1d8 + -8;
            local_1e0 = local_1e0 + 8;
          }
          if (uVar10 != 1) {
            local_1b8 = 1;
            do {
              uVar6 = (uint)local_1b8 - 1;
              iVar4 = strcmp((char *)(*(long *)((long)&local_138 + (ulong)uVar6 * 8) + 0x84),
                             (char *)(*(long *)((long)&local_138 + local_1b8 * 8) + 0x84));
              uVar8 = (uint)local_1b8;
              if (iVar4 == 0) {
                if ((uint)local_1b8 < uVar10) {
                  plVar11 = (long *)((long)&local_138 + local_1b8 * 8);
                  uVar12 = local_1b8;
                  do {
                    uVar8 = (int)uVar12 + 1;
                    uVar12 = (ulong)uVar8;
                    if (uVar8 == uVar10) break;
                    lVar9 = *plVar11;
                    plVar1 = plVar11 + (((uint)local_1b8 + 1) - local_1b8);
                    plVar11 = plVar11 + 1;
                    iVar4 = strcmp((char *)(lVar9 + 0x84),(char *)(*plVar1 + 0x84));
                  } while (iVar4 == 0);
                }
                if ((int)uVar6 < (int)uVar8) {
                  lVar9 = (long)(int)uVar6;
                  do {
                    snprintf((char *)&local_1a0,3,"-%d",(ulong)((1 - (uint)local_1b8) + (int)lVar9))
                    ;
                    plVar11 = (long *)((long)&local_138 + lVar9 * 8);
                    lVar9 = lVar9 + 1;
                    strcat((char *)(*plVar11 + 0x84),(char *)&local_1a0);
                  } while ((int)lVar9 < (int)uVar8);
                }
              }
              local_1b8._0_4_ = uVar8;
              uVar8 = (uint)local_1b8 + 1;
              local_1b8 = (ulong)uVar8;
            } while (uVar8 < uVar10);
          }
        }
      }
    }
  }
LAB_00191af0:
  DAT_0121699c = 1;
  FUN_00291830(&DAT_01216994,0);
  return (ulong)DAT_01216998;
}


// ===== 00191e00 FUN_00191e00 =====

ulong FUN_00191e00(void)

{
  ulong uVar1;
  
  if (DAT_0121699c == 0) {
    uVar1 = FUN_00191840();
    return uVar1;
  }
  return (ulong)DAT_01216998;
}


// ===== 00191e20 FUN_00191e20 =====

int FUN_00191e20(char *param_1,void *param_2,ulong param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  size_t sVar5;
  
  if (param_1 != (char *)0x0) {
    if (*param_1 != '\x01') {
      if (*(int *)(param_1 + 0x14) == 0) {
        return 2;
      }
      if (*(int *)(param_1 + 0x1c) != 0) {
        return 2;
      }
      if (*(int *)(param_1 + 0x10) == 0) {
        return 2;
      }
      if (*(long *)(param_1 + 0x20) == 0) {
        return 2;
      }
    }
    if (param_2 != (void *)0x0) {
      iVar3 = FUN_00191e00();
      if (iVar3 != 0) {
        return iVar3;
      }
      if (*(int *)(param_1 + 0xa4) == 0) {
        do {
          iVar3 = FUN_00291820(param_1 + 0xa8,1,0);
        } while (iVar3 != 0);
        if (*(int *)(param_1 + 0xa4) == 0) {
          lVar1 = *(long *)(param_1 + 0x256d8);
          uVar4 = 3;
          if (((lVar1 != 0) && (*(long *)(lVar1 + 0x38) != 0)) &&
             (pcVar2 = *(code **)(*(long *)(lVar1 + 0x38) + 0x30), pcVar2 != (code *)0x0)) {
            uVar4 = (*pcVar2)(lVar1,param_1,param_1 + 0x84,0x20);
          }
          *(undefined4 *)(param_1 + 0xac) = uVar4;
          param_1[0xa4] = '\x01';
          param_1[0xa5] = '\0';
          param_1[0xa6] = '\0';
          param_1[0xa7] = '\0';
        }
        FUN_00291830(param_1 + 0xa8,0);
      }
      if (*(int *)(param_1 + 0xac) != 0) {
        return *(int *)(param_1 + 0xac);
      }
      sVar5 = strlen(param_1 + 0x84);
      if (sVar5 + 1 <= (param_3 & 0xffffffff)) {
        memcpy(param_2,param_1 + 0x84,sVar5 + 1);
        return 0;
      }
      return 7;
    }
  }
  return 2;
}


// ===== 00191f80 nvmlDeviceGetSerial =====

int nvmlDeviceGetSerial(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x85,"nvmlDeviceGetSerial",
                 "(nvmlDevice_t device, char* serial, unsigned int length)",param_1,param_2,param_3)
    ;
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00191e20(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x85,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x85,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00192150 FUN_00192150 =====

undefined8 FUN_00192150(undefined8 param_1,undefined8 param_2,uint *param_3)

{
  int iVar1;
  char local_68 [32];
  char local_48 [32];
  
  if (param_3 == (uint *)0x0) {
    return 2;
  }
  iVar1 = FUN_00191e20(param_1,local_68,0x1e);
  if (iVar1 == 0) {
    iVar1 = FUN_00191e20(param_2,local_48,0x1e);
    if (iVar1 == 0) {
      iVar1 = strcmp(local_68,local_48);
      *param_3 = (uint)(iVar1 == 0);
      return 0;
    }
  }
  if (iVar1 == 0xf) {
    return 0xf;
  }
  return 3;
}


// ===== 00192220 nvmlDeviceOnSameBoard =====

int nvmlDeviceOnSameBoard(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x1f5,"nvmlDeviceOnSameBoard",
                 "(nvmlDevice_t dev1, nvmlDevice_t dev2, int *onSameBoard)",param_1,param_2,param_3)
    ;
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00192150(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1f5,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1f5,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001923f0 FUN_001923f0 =====

undefined8 FUN_001923f0(char *param_1,undefined8 *param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  uint uVar6;
  float fVar7;
  uint local_6c;
  undefined8 local_60;
  char local_58 [40];
  
  if ((param_1 == (char *)0x0) || (param_2 == (undefined8 *)0x0)) {
    return 2;
  }
  if (DAT_01214898 != 0) {
    bVar2 = false;
    bVar1 = false;
    uVar6 = 0;
    local_6c = 0;
LAB_00192475:
    do {
      iVar3 = FUN_00190770(uVar6,&local_60);
      if (iVar3 == 0) {
        iVar3 = FUN_00191e20(local_60,local_58,0x1e);
        if (iVar3 != 3) {
          if (iVar3 == 0) {
            iVar3 = strcmp(local_58,param_1);
            if (iVar3 == 0) {
              uVar6 = uVar6 + 1;
              local_6c = local_6c + 1;
              *param_2 = local_60;
              if (DAT_01214898 <= uVar6) break;
              goto LAB_00192475;
            }
          }
          else {
            bVar1 = true;
            if (iVar3 == 0xf) {
              if (DAT_01216a78 < 2) goto LAB_00192580;
              fVar7 = (float)FUN_002917b0(&DAT_01216a60);
              lVar4 = syscall(0xba);
              FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n",
                           "ERROR",lVar4,"api.c",0x4d0,uVar6);
              bVar2 = true;
            }
          }
        }
      }
      else if (iVar3 == 0xf) {
        if (DAT_01216a78 < 2) {
LAB_00192580:
          bVar2 = true;
          bVar1 = true;
        }
        else {
          bVar1 = true;
          fVar7 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n",
                       "ERROR",lVar4,"api.c",0x4ba,uVar6);
          bVar2 = true;
        }
      }
      else if (iVar3 == 4) {
        if (2 < DAT_01216a78) {
          fVar7 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n",
                       "WARNING",lVar4,"api.c",0x4c1,uVar6);
        }
      }
      else {
        bVar1 = true;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < DAT_01214898);
    if (1 < local_6c) {
      if (DAT_01216a78 < 2) {
        return 2;
      }
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","ERROR",
                   lVar4,"api.c",0x4e3,local_6c);
      return 2;
    }
    uVar5 = 0;
    if (((local_6c != 0) || (uVar5 = 0xf, bVar2)) || (uVar5 = 999, bVar1)) {
      return uVar5;
    }
  }
  return 6;
}


// ===== 00192760 nvmlDeviceGetHandleBySerial =====

int nvmlDeviceGetHandleBySerial(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x33,"nvmlDeviceGetHandleBySerial",
                 "(const char *serial, nvmlDevice_t *device)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001923f0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x33,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x33,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00192940 FUN_00192940 =====

int FUN_00192940(char *param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  float fVar6;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((iVar2 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (param_2 == (int *)0x0) {
      return 2;
    }
    if (*(int *)(param_1 + 0x71c) == 0) {
      do {
        iVar2 = FUN_00291820(param_1 + 0x720,1,0);
      } while (iVar2 != 0);
      if (*(int *)(param_1 + 0x71c) == 0) {
        lVar5 = *(long *)(param_1 + 0x256d8);
        uVar3 = 3;
        if (((lVar5 != 0) && (*(long *)(lVar5 + 0x20) != 0)) &&
           (pcVar1 = *(code **)(*(long *)(lVar5 + 0x20) + 0x98), pcVar1 != (code *)0x0)) {
          uVar3 = (*pcVar1)(lVar5,param_1,param_1 + 0x708);
        }
        *(undefined4 *)(param_1 + 0x724) = uVar3;
        param_1[0x71c] = '\x01';
        param_1[0x71d] = '\0';
        param_1[0x71e] = '\0';
        param_1[0x71f] = '\0';
      }
      FUN_00291830(param_1 + 0x720,0);
    }
    iVar2 = *(int *)(param_1 + 0x724);
    if (iVar2 == 0) {
      iVar4 = *(int *)(param_1 + 0x708) + -3;
      if (8 < *(int *)(param_1 + 0x708) - 5U) {
        iVar4 = -1;
      }
      *param_2 = iVar4;
    }
    else if (1 < DAT_01216a78) {
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar5,"api.c",0x3a19,"tsapiDeviceGetArchitecture",0x3a19,iVar2);
    }
  }
  return iVar2;
}


// ===== 00192af0 nvmlDeviceGetArchitecture =====

int nvmlDeviceGetArchitecture(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0xab1,"nvmlDeviceGetArchitecture",
                 "(nvmlDevice_t device, nvmlDeviceArchitecture_t *arch)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00192940(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xab1,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xab1,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00192cd0 FUN_00192cd0 =====

int FUN_00192cd0(long param_1,int param_2,int param_3,int param_4,long *param_5)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  undefined8 uVar7;
  long *plVar8;
  float fVar9;
  double dVar10;
  undefined8 uVar11;
  int local_2ec;
  uint local_2dc;
  long local_2d8;
  long local_2d0;
  long local_2c8 [18];
  long local_238;
  long local_230;
  
  plVar8 = local_2c8;
  plVar6 = plVar8;
  for (lVar5 = 0x52; lVar5 != 0; lVar5 = lVar5 + -1) {
    *plVar6 = 0;
    plVar6 = plVar6 + 1;
  }
  iVar1 = FUN_00192940(param_1,&local_2dc);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (local_2dc < 6) {
    if (*(int *)(param_1 + 0x4ec) == 0) {
      do {
        iVar1 = FUN_00291820(param_1 + 0x4f0,1,0);
      } while (iVar1 != 0);
      if (*(int *)(param_1 + 0x4ec) == 0) {
        lVar5 = *(long *)(param_1 + 0x256d8);
        uVar2 = 3;
        if (((lVar5 != 0) && (*(long *)(lVar5 + 0x140) != 0)) &&
           (pcVar3 = *(code **)(*(long *)(lVar5 + 0x140) + 0x70), pcVar3 != (code *)0x0)) {
          uVar2 = (*pcVar3)(lVar5,param_1,param_1 + 0x494);
        }
        *(undefined4 *)(param_1 + 0x4f4) = uVar2;
        *(undefined4 *)(param_1 + 0x4ec) = 1;
      }
      FUN_00291830(param_1 + 0x4f0,0);
      local_2ec = *(int *)(param_1 + 0x4f4);
    }
    else {
      local_2ec = *(int *)(param_1 + 0x4f4);
    }
    if (local_2ec == 0) {
      if (param_4 == 7) {
        return 3;
      }
      lVar5 = *(long *)(param_1 + 0x256d8);
      if (lVar5 == 0) {
        return 3;
      }
      if (*(long *)(lVar5 + 0x140) == 0) {
        return 3;
      }
      pcVar3 = *(code **)(*(long *)(lVar5 + 0x140) + 0x20);
      if (pcVar3 == (code *)0x0) {
        return 3;
      }
LAB_00192daf:
      iVar1 = (*pcVar3)(lVar5,param_1,param_2,param_3,param_4,param_5,param_1 + 0x494);
      return iVar1;
    }
    if (DAT_01216a78 < 2) {
      return local_2ec;
    }
    fVar9 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    uVar7 = 0x72e;
    uVar11 = 0x72e;
    dVar10 = (double)(fVar9 * DAT_00298548);
    goto LAB_0019303a;
  }
  if ((param_4 != 2) && (param_4 != 7)) {
    return 3;
  }
  if (*(int *)(param_1 + 0x70534) == 0) {
    do {
      iVar1 = FUN_00291820(param_1 + 0x70538,1,0);
    } while (iVar1 != 0);
    if (*(int *)(param_1 + 0x70534) == 0) {
      lVar5 = *(long *)(param_1 + 0x256d8);
      uVar2 = 3;
      if (((lVar5 != 0) && (*(long *)(lVar5 + 0x38) != 0)) &&
         (pcVar3 = *(code **)(*(long *)(lVar5 + 0x38) + 8), pcVar3 != (code *)0x0)) {
        uVar2 = (*pcVar3)(lVar5,param_1,param_1 + 0x70530);
      }
      *(undefined4 *)(param_1 + 0x7053c) = uVar2;
      *(undefined4 *)(param_1 + 0x70534) = 1;
    }
    FUN_00291830(param_1 + 0x70538,0);
  }
  local_2ec = *(int *)(param_1 + 0x7053c);
  if (local_2ec != 0) {
    if (DAT_01216a78 < 2) {
      return local_2ec;
    }
    fVar9 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    uVar7 = 0x747;
    uVar11 = 0x747;
    dVar10 = (double)(fVar9 * DAT_00298548);
    goto LAB_0019303a;
  }
  lVar5 = *(long *)(param_1 + 0x256d8);
  if (*(int *)(param_1 + 0x70530) == 2) {
    if (lVar5 == 0) {
      return 3;
    }
    if (*(long *)(lVar5 + 0x140) == 0) {
      return 3;
    }
    pcVar3 = *(code **)(*(long *)(lVar5 + 0x140) + 0x20);
    if (pcVar3 == (code *)0x0) {
      return 3;
    }
    goto LAB_00192daf;
  }
  if (local_2dc < 7) {
    if (param_3 == 1) {
      if (((lVar5 != 0) && (*(long *)(lVar5 + 0x140) != 0)) &&
         (pcVar3 = *(code **)(*(long *)(lVar5 + 0x140) + 0x28), pcVar3 != (code *)0x0))
      goto LAB_0019311a;
LAB_00193190:
      local_2ec = 3;
    }
    else {
      if (((lVar5 == 0) || (*(long *)(lVar5 + 0x140) == 0)) ||
         (pcVar3 = *(code **)(*(long *)(lVar5 + 0x140) + 0x30), pcVar3 == (code *)0x0))
      goto LAB_00193190;
LAB_0019311a:
      local_2ec = (*pcVar3)(lVar5,param_1,plVar8);
      if (local_2ec == 0) {
        lVar5 = 0;
        iVar1 = 0;
        if (param_4 != 2) {
          do {
            if (iVar1 != 9) {
              if (param_2 == 0) {
                lVar4 = *plVar8;
              }
              else {
                lVar4 = plVar8[1];
              }
              lVar5 = lVar5 + lVar4;
              if (iVar1 + 1 == 0x29) goto LAB_001932f0;
            }
            plVar8 = plVar8 + 2;
            iVar1 = iVar1 + 1;
          } while( true );
        }
        lVar5 = local_230;
        if (param_2 == 0) {
          lVar5 = local_238;
        }
LAB_001932f0:
        *param_5 = lVar5;
        return 0;
      }
    }
    if (DAT_01216a78 < 2) {
      return local_2ec;
    }
    fVar9 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    uVar7 = 0x76a;
    uVar11 = 0x76a;
    dVar10 = (double)(fVar9 * DAT_00298548);
    goto LAB_0019303a;
  }
  if (param_3 == 1) {
    if (((lVar5 != 0) && (*(long *)(lVar5 + 0x140) != 0)) &&
       (pcVar3 = *(code **)(*(long *)(lVar5 + 0x140) + 0xd8), pcVar3 != (code *)0x0))
    goto LAB_00192ee5;
LAB_00193238:
    local_2ec = 3;
  }
  else {
    if (((lVar5 == 0) || (*(long *)(lVar5 + 0x140) == 0)) ||
       (pcVar3 = *(code **)(*(long *)(lVar5 + 0x140) + 0x40), pcVar3 == (code *)0x0))
    goto LAB_00193238;
LAB_00192ee5:
    local_2ec = (*pcVar3)(lVar5,param_1,param_4,&local_2d8,&local_2d0);
    if (local_2ec == 0) {
      if (param_2 == 0) {
        local_2d0 = local_2d8;
      }
      *param_5 = local_2d0;
      return 0;
    }
  }
  if (DAT_01216a78 < 2) {
    return local_2ec;
  }
  fVar9 = (float)FUN_002917b0(&DAT_01216a60);
  lVar5 = syscall(0xba);
  uVar7 = 0x75c;
  uVar11 = 0x75c;
  dVar10 = (double)(fVar9 * DAT_00298548);
LAB_0019303a:
  FUN_002340f0(dVar10,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,"api.c",uVar7,
               "_deviceGetMemoryErrorCounter",uVar11,local_2ec);
  return local_2ec;
}


// ===== 00193330 FUN_00193330 =====

int FUN_00193330(char *param_1,uint param_2,uint param_3,uint param_4,long param_5)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  int local_44;
  char *local_40 [2];
  
  local_40[0] = param_1;
  iVar2 = FUN_00175bd0(param_1,&local_44);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_44 == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar3,"api.c",0x781);
        }
      }
      else if (((param_5 == 0 || 7 < param_4) || 1 < param_3) || (1 < param_2)) {
        iVar2 = 2;
      }
      else if ((((param_1 == (char *)0x0) || (*param_1 == '\x01')) ||
               (*(long *)(param_1 + 0x20) != 0)) ||
              (iVar2 = FUN_0016e0a0(param_1,local_40), iVar2 == 0)) {
        lVar3 = *(long *)(local_40[0] + 0x256d8);
        if (((lVar3 == 0) || (*(long *)(lVar3 + 0x140) == 0)) ||
           (pcVar1 = *(code **)(*(long *)(lVar3 + 0x140) + 8), pcVar1 == (code *)0x0)) {
          iVar2 = 3;
        }
        else {
          iVar2 = (*pcVar1)(lVar3,local_40[0],&local_44);
          if (iVar2 == 0) {
            if (local_44 != 1) {
              return 3;
            }
            if (((param_1 != (char *)0x0) && (*param_1 != '\x01')) &&
               (*(long *)(param_1 + 0x20) == 0)) {
              iVar2 = FUN_00137af0(param_1,param_3,param_2,param_4,param_5);
              return iVar2;
            }
            iVar2 = FUN_00192cd0(local_40[0],param_2,param_3,param_4,param_5);
            return iVar2;
          }
        }
        if (1 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,"api.c",0x799,
                       "tsapiDeviceGetMemoryErrorCounter",0x799,iVar2);
        }
      }
    }
    else {
      iVar2 = 999;
    }
  }
  return iVar2;
}


// ===== 001935a0 nvmlDeviceGetMemoryErrorCounter =====

int nvmlDeviceGetMemoryErrorCounter
              (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined8 param_5)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d, %d, %d, %p)\n","DEBUG",
                 lVar3,"entry_points.h",0x217,"nvmlDeviceGetMemoryErrorCounter",
                 "(nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, nvmlMemoryLocation_t locationType, unsigned long long *count)"
                 ,param_1,param_2,param_3,param_4,param_5);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00193330(param_1,param_2,param_3,param_4,param_5);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x217,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x217,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00193790 FUN_00193790 =====

int FUN_00193790(char *param_1,uint param_2,uint param_3,undefined8 *param_4)

{
  bool bVar1;
  int iVar2;
  
  if (param_1 != (char *)0x0) {
    if (*param_1 != '\x01') {
      if (*(int *)(param_1 + 0x14) == 0) {
        return 2;
      }
      if (*(int *)(param_1 + 0x1c) != 0) {
        return 2;
      }
      if (*(int *)(param_1 + 0x10) == 0) {
        return 2;
      }
      if (*(long *)(param_1 + 0x20) == 0) {
        return 2;
      }
    }
    if ((param_2 < 2 && param_3 < 2) && (param_4 != (undefined8 *)0x0)) {
      iVar2 = FUN_00193330(param_1,param_2,param_3,0,param_4);
      if (iVar2 == 0) {
        bVar1 = false;
      }
      else {
        if (iVar2 != 3) {
          return iVar2;
        }
        *param_4 = 0;
        bVar1 = true;
      }
      iVar2 = FUN_00193330(param_1,param_2,param_3,1,param_4 + 1);
      if (iVar2 == 0) {
        bVar1 = false;
      }
      else {
        if (iVar2 != 3) {
          return iVar2;
        }
        param_4[1] = 0;
      }
      iVar2 = FUN_00193330(param_1,param_2,param_3,2,param_4 + 2);
      if (iVar2 == 0) {
        iVar2 = FUN_00193330(param_1,param_2,param_3,3,param_4 + 3);
        if (iVar2 != 0) {
          if (iVar2 != 3) {
            return iVar2;
          }
          param_4[3] = 0;
          return 0;
        }
      }
      else {
        if (iVar2 != 3) {
          return iVar2;
        }
        param_4[2] = 0;
        iVar2 = FUN_00193330(param_1,param_2,param_3,3,param_4 + 3);
        if (iVar2 != 0) {
          if (iVar2 != 3) {
            return iVar2;
          }
          param_4[3] = 0;
          if (bVar1) {
            return 3;
          }
          return 0;
        }
      }
      return 0;
    }
  }
  return 2;
}


// ===== 00193970 nvmlDeviceGetDetailedEccErrors =====

int nvmlDeviceGetDetailedEccErrors
              (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d, %d, %p)\n","DEBUG",lVar3
                 ,"entry_points.h",0x6f,"nvmlDeviceGetDetailedEccErrors",
                 "(nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, nvmlEccErrorCounts_t *eccCounts)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00193790(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x6f,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x6f,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00193b60 FUN_00193b60 =====

undefined8 FUN_00193b60(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  float fVar3;
  int local_c;
  
  if (DAT_003807b4 == 0) {
    return 0;
  }
  iVar1 = FUN_00192940(param_1,&local_c);
  if (iVar1 == 0) {
    if (local_c - 2U < 4) {
      return 1;
    }
    if (2 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","WARNING",
                   lVar2,"api.c",0xe1);
      return 0;
    }
  }
  return 0;
}


