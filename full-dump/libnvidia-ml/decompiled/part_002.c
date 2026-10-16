// ===== 00150550 nvmlDeviceSetPowerMizerMode_v1 =====

int nvmlDeviceSetPowerMizerMode_v1(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0xec,"nvmlDeviceSetPowerMizerMode_v1",
                 "(nvmlDevice_t device, nvmlDevicePowerMizerModes_v1_t *powerMizerMode)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00150510(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xec,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xec,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00150730 FUN_00150730 =====

undefined8 FUN_00150730(long param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x80),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0015075d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 00150770 nvmlDeviceGetPerformanceModes =====

int nvmlDeviceGetPerformanceModes(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x5d5,"nvmlDeviceGetPerformanceModes",
                 "(nvmlDevice_t device, nvmlDevicePerfModes_t *perfModes)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00150730(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5d5,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5d5,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00150950 FUN_00150950 =====

undefined8 FUN_00150950(long param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x88),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0015097d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 00150990 nvmlDeviceGetCurrentClockFreqs =====

int nvmlDeviceGetCurrentClockFreqs(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x5da,"nvmlDeviceGetCurrentClockFreqs",
                 "(nvmlDevice_t device, nvmlDeviceCurrentClockFreqs_t *currentClockFreqs)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00150950(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5da,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5da,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00150b70 FUN_00150b70 =====

undefined8 FUN_00150b70(char *param_1,int *param_2)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((uVar3 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (param_2 == (int *)0x0) {
      return 2;
    }
    uVar3 = 0x19;
    if (*param_2 == 0x1000018) {
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x170) + 0x30), pcVar2 != (code *)0x0)) {
        uVar3 = (*pcVar2)(lVar1,param_1,param_2[1],param_2[2],param_2 + 3,param_2 + 4,param_2 + 5,0,
                          0);
        return uVar3;
      }
      return 3;
    }
  }
  return uVar3;
}


// ===== 00150c20 nvmlDeviceGetClockOffsets =====

int nvmlDeviceGetClockOffsets(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x5cb,"nvmlDeviceGetClockOffsets",
                 "(nvmlDevice_t device, nvmlClockOffset_t *info)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00150b70(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5cb,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5cb,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00150e00 FUN_00150e00 =====

undefined8 FUN_00150e00(char *param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if ((param_1 == (char *)0x0) ||
     (((*param_1 != '\x01' &&
       ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
         (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) || (param_2 == 0)))
     ) {
    uVar2 = 2;
  }
  else {
    iVar1 = FUN_00236dd0();
    if (iVar1 != 0) {
      lVar3 = *(long *)(param_1 + 0x256d8);
      if (((lVar3 != 0) && (*(long *)(lVar3 + 0x170) != 0)) &&
         (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar3 + 0x170) + 0x38),
         UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00150e77. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar3,param_1,param_2);
        return uVar2;
      }
      return 3;
    }
    uVar2 = 4;
    if (1 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                   lVar3,"api.c",0x1bc0);
    }
  }
  return uVar2;
}


// ===== 00150f20 nvmlDeviceSetClockOffsets =====

int nvmlDeviceSetClockOffsets(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x5d0,"nvmlDeviceSetClockOffsets",
                 "(nvmlDevice_t device, nvmlClockOffset_t *info)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00150e00(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5d0,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5d0,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00151100 FUN_00151100 =====

undefined8 FUN_00151100(char *param_1)

{
  undefined8 uVar1;
  
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    uVar1 = FUN_00138c80();
    return uVar1;
  }
  return 2;
}


// ===== 00151140 FUN_00151140 =====

int FUN_00151140(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u, %u)\n",
                 "DEBUG",lVar3,"entry_points.h",0x845,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00151100(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x845,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00151280 FUN_00151280 =====

undefined8 FUN_00151280(char *param_1,undefined4 param_2,long param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_3 != 0)))
     ) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x110),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001512da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00151300 FUN_00151300 =====

int FUN_00151300(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x849,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00151280(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x849,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00151440 FUN_00151440 =====

undefined8 FUN_00151440(char *param_1)

{
  undefined8 uVar1;
  
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    uVar1 = FUN_00138de0();
    return uVar1;
  }
  return 2;
}


// ===== 00151480 FUN_00151480 =====

int FUN_00151480(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u, %u)\n",
                 "DEBUG",lVar3,"entry_points.h",0x84d,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00151440(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x84d,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001515c0 FUN_001515c0 =====

undefined8 FUN_001515c0(char *param_1,undefined4 param_2,long param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_3 != 0)))
     ) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x118),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0015161a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00151640 FUN_00151640 =====

int FUN_00151640(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x851,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001515c0(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x851,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00151780 FUN_00151780 =====

undefined8 FUN_00151780(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0x58),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001517d5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00151800 FUN_00151800 =====

int FUN_00151800(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x855,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00151780(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x855,iVar1,uVar2);
  return iVar1;
}


// ===== 00151940 FUN_00151940 =====

undefined8 FUN_00151940(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = DAT_0038088c;
    return 0;
  }
  return 2;
}


// ===== 00151970 FUN_00151970 =====

int FUN_00151970(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0x861,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00151940(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x861,iVar1,uVar2);
  return iVar1;
}


// ===== 00151aa0 FUN_00151aa0 =====

undefined8
FUN_00151aa0(uint param_1,long param_2,long param_3,undefined4 *param_4,undefined4 param_5)

{
  char *pcVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  if ((param_2 == 0 || param_3 == 0) || (param_1 == 0)) {
LAB_00151b50:
    uVar3 = 2;
  }
  else {
    lVar4 = 0;
    do {
      pcVar1 = *(char **)(param_2 + lVar4 * 8);
      if ((pcVar1 == (char *)0x0) ||
         ((*pcVar1 != '\x01' &&
          ((((*(int *)(pcVar1 + 0x14) == 0 || (*(int *)(pcVar1 + 0x1c) != 0)) ||
            (*(int *)(pcVar1 + 0x10) == 0)) || (*(long *)(pcVar1 + 0x20) == 0))))))
      goto LAB_00151b50;
      lVar4 = lVar4 + 1;
    } while ((uint)lVar4 < param_1);
    iVar2 = FUN_00236dd0();
    if (iVar2 != 0) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = 0;
      }
      uVar3 = FUN_00123110(param_1,param_2,param_3,0,param_4,param_5);
      return uVar3;
    }
    uVar3 = 4;
  }
  return uVar3;
}


// ===== 00151b70 FUN_00151b70 =====

int FUN_00151b70(undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined4 param_5)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%u, %p, %p, %p, %u)\n","DEBUG",lVar3,
                 "entry_points.h",0x997,param_1,param_2,param_3,param_4,param_5);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00151aa0(param_1,param_2,param_3,param_4,param_5);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x997,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00151cd0 FUN_00151cd0 =====

undefined8 FUN_00151cd0(char *param_1)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    if (((*(long *)(param_1 + 0x256d8) != 0) &&
        (lVar1 = *(long *)(*(long *)(param_1 + 0x256d8) + 0x160), lVar1 != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(lVar1 + 0x40), UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00151d1d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)();
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00151d40 FUN_00151d40 =====

int FUN_00151d40(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0x869,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00151cd0(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x869,iVar1,uVar2);
  return iVar1;
}


// ===== 00151e70 FUN_00151e70 =====

undefined8 FUN_00151e70(char *param_1,undefined4 param_2,long param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_3 != 0)))
     ) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0x50) != (undefined8 *)0x0)) &&
       (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar1 + 0x50),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00151ec3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00151ee0 FUN_00151ee0 =====

int FUN_00151ee0(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x871,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00151e70(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x871,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00152020 FUN_00152020 =====

undefined8 FUN_00152020(undefined4 *param_1)

{
  long lVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    lVar1 = strtol("13.595.71.05",(char **)0x0,10);
    *param_1 = (int)lVar1;
    return 0;
  }
  return 2;
}


// ===== 00152060 FUN_00152060 =====

int FUN_00152060(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0x880,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00152020(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x880,iVar1,uVar2);
  return iVar1;
}


// ===== 00152190 FUN_00152190 =====

undefined8 FUN_00152190(char *param_1,long param_2)

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
    if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0x90) != (undefined8 *)0x0)) &&
       (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar1 + 0x90),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001521e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00152210 FUN_00152210 =====

int FUN_00152210(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x884,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00152190(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x884,iVar1,uVar2);
  return iVar1;
}


// ===== 00152350 FUN_00152350 =====

undefined8 FUN_00152350(char *param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  
  if ((param_1 == (char *)0x0) || (param_2 == (undefined4 *)0x0)) {
    return 2;
  }
  if (*param_1 != '\x01') {
    if (*(long *)(param_1 + 0x20) == 0) {
      uVar1 = FUN_001374d0();
      return uVar1;
    }
    if (((*(int *)(param_1 + 0x14) == 0) || (*(int *)(param_1 + 0x1c) != 0)) ||
       (*(int *)(param_1 + 0x10) == 0)) {
      return 2;
    }
  }
  *param_2 = *(undefined4 *)(param_1 + 4);
  return 0;
}


// ===== 001523b0 nvmlDeviceGetIndex =====

int nvmlDeviceGetIndex(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x274,"nvmlDeviceGetIndex",
                 "(nvmlDevice_t device, unsigned int *index)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00152350(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x274,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x274,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00152590 FUN_00152590 =====

undefined8 FUN_00152590(uint param_1,undefined4 *param_2,uint *param_3,uint *param_4)

{
  ulong uVar1;
  
  if (((param_2 != (undefined4 *)0x0 && param_3 != (uint *)0x0) && (param_4 != (uint *)0x0)) &&
     (param_1 < DAT_01214898)) {
    uVar1 = (ulong)param_1;
    *param_2 = (&DAT_003808a0)[uVar1 * 0x1d280];
    *param_3 = (uint)(ushort)(&DAT_003808a4)[uVar1 * 0x3a500];
    *param_4 = (uint)(ushort)(&DAT_003808a6)[uVar1 * 0x3a500];
    return 0;
  }
  return 2;
}


// ===== 001525f0 FUN_001525f0 =====

int FUN_001525f0(undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%u, %p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x875,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00152590(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x875,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00152740 FUN_00152740 =====

undefined8 FUN_00152740(uint param_1,char *param_2,uint param_3)

{
  uint uVar1;
  ulong uVar2;
  
  if ((param_2 == (char *)0x0) || (DAT_01214898 <= param_1)) {
    return 2;
  }
  uVar2 = (ulong)param_1;
  uVar1 = snprintf(param_2,(ulong)param_3,"%04X:%02X:%02X.0",
                   (ulong)(uint)(&DAT_003808a0)[uVar2 * 0x1d280],
                   (ulong)(ushort)(&DAT_003808a4)[uVar2 * 0x3a500],
                   (ulong)(ushort)(&DAT_003808a6)[uVar2 * 0x3a500]);
  if ((uVar1 != 0xffffffff) && (uVar1 < param_3)) {
    return 0;
  }
  return 7;
}


// ===== 001527e0 FUN_001527e0 =====

int FUN_001527e0(undefined4 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%u, %p, %u)\n",
                 "DEBUG",lVar3,"entry_points.h",0x879,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00152740(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x879,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00152920 FUN_00152920 =====

undefined8 FUN_00152920(long param_1,long param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined4 local_28;
  undefined2 local_24 [2];
  undefined2 local_20 [2];
  int local_1c [3];
  
  if ((param_2 == 0) || (param_1 == 0)) {
    return 2;
  }
  uVar2 = FUN_0013a210(param_1,&local_28,local_24,local_20,local_1c);
  if (((int)uVar2 == 0) && (uVar2 = 2, local_1c[0] == 0)) {
    if ((DAT_012164a0 == 0) ||
       ((*(undefined8 **)(DAT_012164a0 + 0x20) == (undefined8 *)0x0 ||
        (pcVar1 = (code *)**(undefined8 **)(DAT_012164a0 + 0x20), pcVar1 == (code *)0x0)))) {
      return 3;
    }
    uVar2 = (*pcVar1)(DAT_012164a0,local_28,local_24[0],local_20[0],param_2);
  }
  return uVar2;
}


// ===== 001529b0 FUN_001529b0 =====

int FUN_001529b0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x87d,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00152920(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x87d,iVar1,uVar2);
  return iVar1;
}


// ===== 00152af0 FUN_00152af0 =====

undefined8 FUN_00152af0(uint param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  uVar1 = 2;
  if (param_1 < 2) {
    uVar1 = 0;
    DAT_012148d8 = param_1;
    DAT_012148dc = param_2;
  }
  return uVar1;
}


// ===== 00152b10 FUN_00152b10 =====

int FUN_00152b10(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%u, %u)\n",
                 "DEBUG",lVar3,"entry_points.h",0x888,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00152af0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x888,iVar1,uVar2);
  return iVar1;
}


// ===== 00152c50 FUN_00152c50 =====

undefined8 FUN_00152c50(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    return 0;
  }
  return 2;
}


// ===== 00152c70 FUN_00152c70 =====

int FUN_00152c70(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0x88c,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00152c50(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x88c,iVar1,uVar2);
  return iVar1;
}


// ===== 00152da0 FUN_00152da0 =====

undefined8 FUN_00152da0(uint param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  if ((param_3 == (int *)0x0) || (param_2 == (undefined4 *)0x0)) {
    return 2;
  }
  uVar3 = 2;
  if (param_1 < DAT_01214898) {
    uVar2 = (ulong)param_1;
    if ((&DAT_003808ac)[uVar2 * 0x1d280] == 0) {
      *param_2 = 0;
      return 0;
    }
    *param_2 = 1;
    iVar1 = (&DAT_003808b4)[uVar2 * 0x1d280];
    *param_3 = iVar1;
    if (iVar1 != 0) {
      return 0;
    }
    uVar3 = 0;
    if ((&DAT_003808a8)[uVar2 * 0x1d280] == 0) {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00152e30 FUN_00152e30 =====

int FUN_00152e30(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%u %p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x88f,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00152da0(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x88f,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00152f70 thunk_FUN_00236fb0 =====

undefined4 thunk_FUN_00236fb0(void)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined4 uVar4;
  float fVar5;
  
  do {
    iVar2 = FUN_00291820(&DAT_01216a9c,1,0);
  } while (iVar2 != 0);
  do {
    iVar2 = FUN_00291820(&DAT_01216a98,1,0);
  } while (iVar2 != 0);
  if (DAT_01216aa0 != 0) {
    uVar4 = 0;
    if (DAT_01216a78 < 5) {
      DAT_01216aa0 = DAT_01216aa0 + 1;
    }
    else {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                   lVar3,"unix.c",0xbd);
      DAT_01216aa0 = DAT_01216aa0 + 1;
    }
    goto LAB_00237055;
  }
  if (DAT_01216a78 < 5) {
    iVar2 = FUN_0028e660();
    if (4 < DAT_01216a78) goto LAB_002371b0;
LAB_00237032:
    uVar4 = 4;
    iVar1 = iVar2 + -0xd;
    if (iVar2 == 0xd) goto LAB_00237055;
  }
  else {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                 lVar3,"unix.c",0x9d);
    iVar2 = FUN_0028e660();
    if (DAT_01216a78 < 5) goto LAB_00237032;
LAB_002371b0:
    uVar4 = 4;
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","DEBUG",
                 lVar3,"unix.c",0x9f,iVar2);
    iVar1 = iVar2 + -0xd;
    if (iVar1 == 0) goto LAB_00237055;
  }
  if (SBORROW4(iVar2,0xd) == iVar1 < 0) {
    uVar4 = 999;
    if (iVar2 == 0x14) {
      uVar4 = 3;
    }
  }
  else if (iVar2 == 0) {
    uVar4 = 0;
    DAT_01216aa0 = DAT_01216aa0 + 1;
  }
  else {
    uVar4 = 999;
    if (iVar2 == 2) {
      uVar4 = 3;
    }
  }
LAB_00237055:
  FUN_00291830(&DAT_01216a98,0);
  FUN_00291830(&DAT_01216a9c,0);
  return uVar4;
}


// ===== 00152f80 FUN_00152f80 =====

int FUN_00152f80(void)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t()\n","DEBUG",
                 lVar3,"entry_points.h",0x893);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_00236fb0();
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x893,iVar1,uVar2);
  return iVar1;
}


// ===== 001530a0 thunk_FUN_00237220 =====

undefined8 thunk_FUN_00237220(void)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  do {
    iVar1 = FUN_00291820(&DAT_01216a9c,1,0);
  } while (iVar1 != 0);
  do {
    iVar1 = FUN_00291820(&DAT_01216a98,1,0);
  } while (iVar1 != 0);
  if (DAT_01216aa0 == 0) {
    if (2 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","WARNING",
                   lVar2,"unix.c",0xd3);
    }
  }
  else {
    DAT_01216aa0 = DAT_01216aa0 + -1;
    if (DAT_01216aa0 == 0) {
      if (4 < DAT_01216a78) {
        fVar3 = (float)FUN_002917b0(&DAT_01216a60);
        lVar2 = syscall(0xba);
        FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                     lVar2,"unix.c",0xe3);
      }
      FUN_00291830(&DAT_01216a98,0);
      do {
      } while (DAT_01216a94 != 0);
      do {
        iVar1 = FUN_00291820(&DAT_01216a98,1,0);
      } while (iVar1 != 0);
      FUN_0028e6a0();
    }
    else if (4 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                   lVar2,"unix.c",0xfc);
    }
  }
  FUN_00291830(&DAT_01216a98,0);
  FUN_00291830(&DAT_01216a9c,0);
  return 0;
}


// ===== 001530b0 FUN_001530b0 =====

int FUN_001530b0(void)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t()\n","DEBUG",
                 lVar3,"entry_points.h",0x894);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_00237220();
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x894,iVar1,uVar2);
  return iVar1;
}


// ===== 001531d0 thunk_FUN_00237700 =====

int thunk_FUN_00237700(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  iVar1 = FUN_00236c60();
  if (iVar1 == 0) {
    if ((param_1 == 0) || (param_2 == 0)) {
      iVar1 = 2;
    }
    else {
      iVar1 = FUN_00236b30(param_1,param_2);
    }
    if (4 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                   lVar2,"unix.c",0x1ab,iVar1);
    }
    FUN_00236ba0();
    return iVar1;
  }
  return iVar1;
}


// ===== 001531e0 FUN_001531e0 =====

int FUN_001531e0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x89c,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_00237700(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x89c,iVar1,uVar2);
  return iVar1;
}


// ===== 00153320 thunk_FUN_002378a0 =====

int thunk_FUN_002378a0(undefined8 param_1,undefined4 *param_2)

{
  int iVar1;
  long lVar2;
  float fVar3;
  uint auStack_2c [3];
  
  iVar1 = FUN_00236c60();
  if (iVar1 == 0) {
    iVar1 = FUN_00236540(param_1,0xc,auStack_2c,0);
    if (iVar1 == 0) {
      switch(auStack_2c[0] >> 4 & 0x3f) {
      default:
        iVar1 = 3;
        break;
      case 1:
        *param_2 = 1;
        break;
      case 2:
        *param_2 = 2;
        break;
      case 4:
        *param_2 = 4;
        break;
      case 8:
        *param_2 = 8;
        break;
      case 0xc:
        *param_2 = 0xc;
        break;
      case 0x10:
        *param_2 = 0x10;
        break;
      case 0x20:
        *param_2 = 0x20;
      }
    }
    if (4 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                   lVar2,"unix.c",0x217,iVar1);
    }
    FUN_00236ba0();
    return iVar1;
  }
  return iVar1;
}


// ===== 00153330 FUN_00153330 =====

int FUN_00153330(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x89e,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_002378a0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x89e,iVar1,uVar2);
  return iVar1;
}


// ===== 00153470 thunk_FUN_00237450 =====

int thunk_FUN_00237450(int *param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  float fVar4;
  
  iVar1 = FUN_00236c60();
  if (iVar1 != 0) {
    return iVar1;
  }
  lVar2 = FUN_0028e3d0(0);
  if (lVar2 == 0) {
    iVar1 = 999;
  }
  else {
    *param_1 = 0;
    while( true ) {
      lVar3 = FUN_0028e4d0(lVar2);
      if (lVar3 == 0) break;
      *param_1 = *param_1 + 1;
    }
    FUN_0028e4b0(lVar2);
    iVar1 = 0;
  }
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                 lVar2,"unix.c",0x112,iVar1);
  }
  FUN_00236ba0();
  return iVar1;
}


// ===== 00153480 FUN_00153480 =====

int FUN_00153480(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0x895,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_00237450(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x895,iVar1,uVar2);
  return iVar1;
}


// ===== 001535b0 thunk_FUN_00237550 =====

int thunk_FUN_00237550(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      long *param_5)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  float fVar5;
  
  iVar1 = FUN_00236c60();
  if (iVar1 == 0) {
    if (param_5 == (long *)0x0) {
      iVar1 = 2;
    }
    else {
      lVar3 = FUN_0028e630(param_1,param_2,param_3,param_4);
      if (lVar3 == 0) {
        iVar1 = 6;
      }
      else {
        uVar2 = FUN_0028e880(lVar3);
        if (4 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",
                       "DEBUG",lVar4,"unix.c",0x13c,(ulong)uVar2);
        }
        if (uVar2 == 0) {
          *param_5 = lVar3;
        }
        else {
          iVar1 = 999;
          if (uVar2 < 0xe) {
            iVar1 = *(int *)(&DAT_002dc220 + (ulong)uVar2 * 4);
          }
        }
      }
    }
    if (4 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                   lVar3,"unix.c",0x127,iVar1);
    }
    FUN_00236ba0();
  }
  return iVar1;
}


// ===== 001535c0 FUN_001535c0 =====

int FUN_001535c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%u, %u, %u, %u, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x897,param_1,param_2,param_3,param_4,param_5);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_00237550(param_1,param_2,param_3,param_4,param_5);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x897,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00153720 thunk_FUN_00237fe0 =====

int thunk_FUN_00237fe0(long param_1,long *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  float fVar10;
  int iStack_44;
  int iStack_40;
  undefined1 auStack_3c [12];
  
  iVar6 = FUN_00236c60();
  if (iVar6 == 0) {
    if ((param_2 == (long *)0x0) || (param_1 == 0)) {
      iVar6 = 2;
    }
    else {
      if (3 < DAT_01216a78) {
        uVar1 = *(undefined1 *)(param_1 + 4);
        uVar2 = *(undefined1 *)(param_1 + 3);
        uVar3 = *(undefined1 *)(param_1 + 2);
        uVar5 = *(undefined4 *)(param_1 + 0x124);
        fVar10 = (float)FUN_002917b0(&DAT_01216a60);
        lVar7 = syscall(0xba);
        FUN_002340f0((double)(fVar10 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%02x %02x %02x %x\n",&DAT_002983c2,lVar7,
                     "unix.c",0x2d6,uVar5,uVar3,uVar2,uVar1);
      }
      lVar7 = FUN_0028e440(0);
      if (lVar7 != 0) {
LAB_00238060:
        do {
          lVar8 = FUN_0028e4d0(lVar7);
          while( true ) {
            if (lVar8 == 0) {
              iVar6 = 6;
              FUN_0028e4b0(lVar7);
              if (DAT_01216a78 < 4) goto LAB_00238106;
              iVar6 = 6;
              fVar10 = (float)FUN_002917b0(&DAT_01216a60);
              lVar7 = syscall(0xba);
              FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                           &DAT_002983c2,lVar7,"unix.c",0x33d);
              goto LAB_002380fd;
            }
            iVar6 = *(int *)(lVar8 + 0x124);
            if (DAT_01216a78 < 4) break;
            uVar1 = *(undefined1 *)(lVar8 + 4);
            uVar2 = *(undefined1 *)(lVar8 + 3);
            uVar3 = *(undefined1 *)(lVar8 + 2);
            fVar10 = (float)FUN_002917b0(&DAT_01216a60);
            lVar9 = syscall(0xba);
            FUN_002340f0((double)(fVar10 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%02x %02x %02x %x\n",&DAT_002983c2,
                         lVar9,"unix.c",0x2e9,iVar6,uVar3,uVar2,uVar1);
            iVar6 = *(int *)(lVar8 + 0x124);
            iVar4 = *(int *)(param_1 + 0x124);
            if (iVar6 == iVar4) goto LAB_0023808f;
            if (DAT_01216a78 < 4) goto LAB_00238060;
            fVar10 = (float)FUN_002917b0(&DAT_01216a60);
            lVar8 = syscall(0xba);
            FUN_002340f0((double)(fVar10 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u\n",&DAT_002983c2,lVar8,"unix.c",
                         0x2f2,iVar6,iVar4);
            lVar8 = FUN_0028e4d0(lVar7);
          }
          if (*(int *)(param_1 + 0x124) == iVar6) {
LAB_0023808f:
            iVar6 = FUN_00235db0(lVar8,&iStack_44,&iStack_40,auStack_3c);
            if (iVar6 != 0) {
              FUN_0028e4b0(lVar7);
              break;
            }
            if ((((iStack_44 == 0) || ((iStack_44 == 6 && ((iStack_40 == 4 || (iStack_40 == 9))))))
                && (lVar9 = FUN_0028e180(lVar8), lVar9 != 0)) &&
               (*(char *)(param_1 + 2) == *(char *)(lVar9 + 1))) {
              FUN_0028e4b0(lVar7);
              *param_2 = lVar8;
              iVar6 = 0;
              goto LAB_002380fd;
            }
          }
        } while( true );
      }
      iVar6 = 999;
    }
LAB_002380fd:
    if (DAT_01216a78 < 5) {
LAB_00238106:
      FUN_00236ba0();
    }
    else {
      fVar10 = (float)FUN_002917b0(&DAT_01216a60);
      lVar7 = syscall(0xba);
      FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG"
                   ,lVar7,"unix.c",0x2c8,iVar6);
      FUN_00236ba0();
    }
  }
  return iVar6;
}


// ===== 00153730 FUN_00153730 =====

int FUN_00153730(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x8a4,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_00237fe0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x8a4,iVar1,uVar2);
  return iVar1;
}


// ===== 00153870 thunk_FUN_002383e0 =====

int thunk_FUN_002383e0(long param_1,undefined4 *param_2,uint *param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  iVar1 = FUN_00236c60();
  if (iVar1 == 0) {
    if ((((param_1 == 0) || (param_2 == (undefined4 *)0x0)) ||
        (param_3 == (uint *)0x0 || param_4 == (uint *)0x0)) || (param_5 == (uint *)0x0)) {
      iVar1 = 2;
    }
    else {
      *param_2 = *(undefined4 *)(param_1 + 0x124);
      *param_3 = (uint)*(byte *)(param_1 + 2);
      *param_4 = (uint)*(byte *)(param_1 + 3);
      *param_5 = (uint)*(byte *)(param_1 + 4);
    }
    if (4 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                   lVar2,"unix.c",0x345,iVar1);
    }
    FUN_00236ba0();
  }
  return iVar1;
}


// ===== 00153880 FUN_00153880 =====

int FUN_00153880(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
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
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p, %p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x8a6,param_1,param_2,param_3,param_4,param_5);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_002383e0(param_1,param_2,param_3,param_4,param_5);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x8a6,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001539e0 thunk_FUN_00237ef0 =====

int thunk_FUN_00237ef0(long param_1,long param_2,long param_3,long param_4)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  iVar1 = FUN_00236c60();
  if (iVar1 == 0) {
    if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) || (param_4 == 0)) {
      iVar1 = 2;
    }
    else {
      iVar1 = FUN_00235db0(param_1,param_2,param_3,param_4);
    }
    if (4 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                   lVar2,"unix.c",0x2af,iVar1);
    }
    FUN_00236ba0();
  }
  return iVar1;
}


// ===== 001539f0 FUN_001539f0 =====

int FUN_001539f0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

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
                 "entry_points.h",0x8aa,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_00237ef0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x8aa,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00153b40 FUN_00153b40 =====

undefined1  [16] FUN_00153b40(char *param_1,int *param_2,undefined8 param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  undefined8 uVar4;
  ulong uVar5;
  float fVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined8 uVar9;
  int local_8c;
  int local_88;
  undefined1 local_84 [4];
  undefined8 local_80;
  undefined1 local_78 [16];
  uint local_68;
  uint uStack_64;
  uint local_60;
  undefined4 uStack_5c;
  int local_58;
  
  if (param_1 != (char *)0x0) {
    if ((*param_1 != '\x01') &&
       ((((uVar5 = 2, *(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
         (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) goto LAB_00153ca6;
    if (param_2 != (int *)0x0) {
      uVar5 = 0x19;
      if (*param_2 != 0x1000040) goto LAB_00153ca6;
      lVar3 = *(long *)(param_1 + 0x256d8);
      if (((lVar3 == 0) || (*(long *)(lVar3 + 0x48) == 0)) ||
         (pcVar1 = *(code **)(*(long *)(lVar3 + 0x48) + 0xc0), pcVar1 == (code *)0x0)) {
        uVar5 = 3;
      }
      else {
        uVar2 = (*pcVar1)(lVar3,param_1,3,local_78);
        uVar5 = (ulong)uVar2;
        param_3 = extraout_RDX;
        if (uVar2 == 0) {
          *(ulong *)(param_2 + 1) = CONCAT44(uStack_64,local_68);
          *(ulong *)(param_2 + 3) = CONCAT44(uStack_5c,local_60);
          param_2[5] = local_58;
          snprintf((char *)(param_2 + 8),0x20,"%08X:%02X:%02X.0",(ulong)local_68,(ulong)uStack_64,
                   (ulong)local_60);
          uVar2 = thunk_FUN_00236fb0();
          uVar5 = (ulong)uVar2;
          if (uVar2 == 0) {
            uVar2 = thunk_FUN_00237550(*(undefined4 *)(param_1 + 8),*(undefined2 *)(param_1 + 0xc),
                                       *(undefined2 *)(param_1 + 0xe),0,&local_80);
            uVar5 = (ulong)uVar2;
            if (uVar2 == 0) {
              uVar2 = thunk_FUN_00237ef0(local_80,&local_8c,&local_88,local_84);
              uVar5 = (ulong)uVar2;
              if (uVar2 == 0) {
                param_2[6] = local_8c;
                param_2[7] = local_88;
              }
            }
            thunk_FUN_00237220();
            param_3 = extraout_RDX_01;
            goto LAB_00153ca6;
          }
          param_3 = extraout_RDX_00;
          if (DAT_01216a78 < 2) goto LAB_00153ca6;
          fVar6 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          fVar6 = fVar6 * DAT_00298548;
          uVar9 = 0xc12;
          uVar4 = 0xc12;
          goto LAB_00153d15;
        }
      }
      if (1 < DAT_01216a78) {
        fVar6 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        fVar6 = fVar6 * DAT_00298548;
        uVar9 = 0xc04;
        uVar4 = 0xc04;
LAB_00153d15:
        FUN_002340f0((double)fVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
                     "api.c",uVar4,"tsapiDeviceGetPciInfoExt",uVar9);
        auVar8._8_8_ = uVar5;
        auVar8._0_8_ = uVar5;
        return auVar8;
      }
      goto LAB_00153ca6;
    }
  }
  uVar5 = 2;
LAB_00153ca6:
  auVar7._8_8_ = param_3;
  auVar7._0_8_ = uVar5;
  return auVar7;
}


// ===== 00153db0 nvmlDeviceGetPciInfoExt =====

int nvmlDeviceGetPciInfoExt(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0xb6,"nvmlDeviceGetPciInfoExt",
                 "(nvmlDevice_t device, nvmlPciInfoExt_t *pci)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00153b40(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xb6,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xb6,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00153f90 thunk_FUN_00237a10 =====

int thunk_FUN_00237a10(long param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int iVar5;
  long lVar6;
  int iVar7;
  float fVar8;
  uint auStack_3c [3];
  
  iVar5 = FUN_00236c60();
  if (iVar5 == 0) {
    if (3 < DAT_01216a78) {
      uVar1 = *(undefined1 *)(param_1 + 4);
      uVar2 = *(undefined1 *)(param_1 + 3);
      uVar3 = *(undefined1 *)(param_1 + 2);
      uVar4 = *(undefined4 *)(param_1 + 0x124);
      fVar8 = (float)FUN_002917b0(&DAT_01216a60);
      lVar6 = syscall(0xba);
      FUN_002340f0((double)(fVar8 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%02x %02x %02x %x\n",&DAT_002983c2,lVar6,
                   "unix.c",0x256,uVar4,uVar3,uVar2,uVar1);
    }
    iVar7 = 0xb;
    while (iVar5 = FUN_00236540(param_1,0x12,auStack_3c,0), iVar5 == 0) {
      if ((auStack_3c[0] & 0x800) == 0) {
        iVar5 = 0;
        switch(auStack_3c[0] >> 4 & 0x3f) {
        default:
          iVar5 = 3;
          break;
        case 1:
          *param_2 = 1;
          break;
        case 2:
          *param_2 = 2;
          break;
        case 4:
          *param_2 = 4;
          break;
        case 8:
          *param_2 = 8;
          break;
        case 0xc:
          *param_2 = 0xc;
          break;
        case 0x10:
          *param_2 = 0x10;
          break;
        case 0x20:
          *param_2 = 0x20;
        }
        break;
      }
      if (3 < DAT_01216a78) {
        fVar8 = (float)FUN_002917b0(&DAT_01216a60);
        lVar6 = syscall(0xba);
        FUN_002340f0((double)(fVar8 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                     &DAT_002983c2,lVar6,"unix.c",0x26c);
      }
      iVar7 = iVar7 + -1;
      if (iVar7 == 0) {
        iVar5 = 999;
        if (DAT_01216a78 < 2) goto LAB_00237ab8;
        iVar5 = 999;
        fVar8 = (float)FUN_002917b0(&DAT_01216a60);
        lVar6 = syscall(0xba);
        FUN_002340f0((double)(fVar8 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                     lVar6,"unix.c",0x274);
        break;
      }
      sleep(0x32);
    }
    if (DAT_01216a78 < 5) {
LAB_00237ab8:
      FUN_00236ba0();
    }
    else {
      fVar8 = (float)FUN_002917b0(&DAT_01216a60);
      lVar6 = syscall(0xba);
      FUN_002340f0((double)(fVar8 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                   lVar6,"unix.c",0x24a,iVar5);
      FUN_00236ba0();
    }
  }
  return iVar5;
}


// ===== 00153fa0 FUN_00153fa0 =====

int FUN_00153fa0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x8b4,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_00237a10(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x8b4,iVar1,uVar2);
  return iVar1;
}


// ===== 001540e0 thunk_FUN_002377e0 =====

int thunk_FUN_002377e0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  iVar1 = FUN_00236c60();
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = FUN_00236950(param_1,param_2);
  if (4 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                 lVar2,"unix.c",0x1d5,iVar1);
  }
  FUN_00236ba0();
  return iVar1;
}


// ===== 001540f0 FUN_001540f0 =====

int FUN_001540f0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x8b2,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_002377e0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x8b2,iVar1,uVar2);
  return iVar1;
}


// ===== 00154230 thunk_FUN_00237d50 =====

int thunk_FUN_00237d50(long param_1,uint *param_2)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  iVar1 = FUN_00236c60();
  if (iVar1 == 0) {
    if ((param_1 == 0) || (param_2 == (uint *)0x0)) {
      iVar1 = 2;
    }
    else {
      *param_2 = (uint)*(ushort *)(param_1 + 6);
    }
    if (4 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                   lVar2,"unix.c",0x29b,iVar1);
    }
    FUN_00236ba0();
  }
  return iVar1;
}


// ===== 00154240 FUN_00154240 =====

int FUN_00154240(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x8a0,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_00237d50(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x8a0,iVar1,uVar2);
  return iVar1;
}


// ===== 00154380 thunk_FUN_00237e20 =====

int thunk_FUN_00237e20(long param_1,uint *param_2)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  iVar1 = FUN_00236c60();
  if (iVar1 == 0) {
    if ((param_1 == 0) || (param_2 == (uint *)0x0)) {
      iVar1 = 2;
    }
    else {
      *param_2 = (uint)*(ushort *)(param_1 + 8);
    }
    if (4 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                   lVar2,"unix.c",0x2a5,iVar1);
    }
    FUN_00236ba0();
  }
  return iVar1;
}


// ===== 00154390 FUN_00154390 =====

int FUN_00154390(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x8a2,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_00237e20(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x8a2,iVar1,uVar2);
  return iVar1;
}


// ===== 001544d0 thunk_FUN_002384f0 =====

int thunk_FUN_002384f0(long param_1,uint *param_2)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  iVar1 = FUN_00236c60();
  if (iVar1 == 0) {
    if ((param_1 == 0) || (param_2 == (uint *)0x0)) {
      iVar1 = 2;
    }
    else {
      *param_2 = (uint)*(ushort *)(param_1 + 0xc);
    }
    if (4 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                   lVar2,"unix.c",0x358,iVar1);
    }
    FUN_00236ba0();
  }
  return iVar1;
}


// ===== 001544e0 FUN_001544e0 =====

int FUN_001544e0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x8ae,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_002384f0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x8ae,iVar1,uVar2);
  return iVar1;
}


// ===== 00154620 thunk_FUN_002385c0 =====

int thunk_FUN_002385c0(long param_1,uint *param_2)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  iVar1 = FUN_00236c60();
  if (iVar1 == 0) {
    if ((param_1 == 0) || (param_2 == (uint *)0x0)) {
      iVar1 = 2;
    }
    else {
      *param_2 = (uint)*(ushort *)(param_1 + 10);
    }
    if (4 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                   lVar2,"unix.c",0x362,iVar1);
    }
    FUN_00236ba0();
  }
  return iVar1;
}


// ===== 00154630 FUN_00154630 =====

int FUN_00154630(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x8b0,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_002385c0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x8b0,iVar1,uVar2);
  return iVar1;
}


// ===== 00154770 thunk_FUN_00238690 =====

int thunk_FUN_00238690(long param_1,undefined4 *param_2)

{
  int iVar1;
  long lVar2;
  float fVar3;
  int aiStack_2c [3];
  
  iVar1 = FUN_00236c60();
  if (iVar1 != 0) {
    return iVar1;
  }
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    iVar1 = 2;
  }
  else {
    iVar1 = FUN_00236b30(param_1,aiStack_2c);
    if (iVar1 == 0) {
      if (aiStack_2c[0] == 5000) {
        *param_2 = 2;
      }
      else if (aiStack_2c[0] == 8000) {
        *param_2 = 3;
      }
      else if (aiStack_2c[0] == 0x9c4) {
        *param_2 = 1;
      }
      else {
        iVar1 = 3;
      }
    }
  }
  if (4 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                 lVar2,"unix.c",0x386,iVar1);
  }
  FUN_00236ba0();
  return iVar1;
}


// ===== 00154780 FUN_00154780 =====

int FUN_00154780(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x8b6,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_00238690(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x8b6,iVar1,uVar2);
  return iVar1;
}


// ===== 001548c0 thunk_FUN_002387c0 =====

int thunk_FUN_002387c0(long param_1,undefined4 *param_2)

{
  int iVar1;
  long lVar2;
  float fVar3;
  int aiStack_2c [3];
  
  iVar1 = FUN_00236c60();
  if (iVar1 != 0) {
    return iVar1;
  }
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    iVar1 = 2;
  }
  else {
    iVar1 = FUN_00236950(param_1,aiStack_2c);
    if (iVar1 == 0) {
      if (aiStack_2c[0] == 5000) {
        *param_2 = 2;
      }
      else if (aiStack_2c[0] == 8000) {
        *param_2 = 3;
      }
      else if (aiStack_2c[0] == 0x9c4) {
        *param_2 = 1;
      }
      else {
        iVar1 = 3;
      }
    }
  }
  if (4 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                 lVar2,"unix.c",0x397,iVar1);
  }
  FUN_00236ba0();
  return iVar1;
}


// ===== 001548d0 FUN_001548d0 =====

int FUN_001548d0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x8b8,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_002387c0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x8b8,iVar1,uVar2);
  return iVar1;
}


// ===== 00154a10 FUN_00154a10 =====

undefined8 FUN_00154a10(uint param_1,uint param_2,uint param_3,char *param_4,uint param_5)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  char *pcVar4;
  float fVar5;
  
  if (param_4 == (char *)0x0) {
    return 2;
  }
  if (((param_5 == 0) || (0xff < param_1 || 0xff < param_2)) || (0xff < param_3)) {
    uVar3 = 2;
  }
  else {
    switch(param_1) {
    case 0:
      pcVar4 = "None";
      break;
    case 1:
      pcVar4 = "Mass storage controller";
      break;
    case 2:
      pcVar4 = "Network controller";
      break;
    case 3:
      pcVar4 = "Display controller";
      break;
    case 4:
      pcVar4 = "Multimedia controller";
      break;
    case 5:
      pcVar4 = "Memory controller";
      break;
    case 6:
      switch(param_2) {
      case 0:
        pcVar4 = "Host bridge";
        break;
      case 1:
        pcVar4 = "ISA bridge";
        break;
      case 2:
        pcVar4 = "EISA bridge";
        break;
      case 3:
        pcVar4 = "MCA bridge";
        break;
      case 4:
        pcVar4 = "PCI-to-PCI bridge";
        break;
      case 5:
        pcVar4 = "PCMCIA bridge";
        break;
      case 6:
        pcVar4 = "NuBus bridge";
        break;
      case 7:
        pcVar4 = "CardBus bridge";
        break;
      case 8:
        pcVar4 = "RACEway bridge";
        break;
      case 9:
        pcVar4 = "Semi-transparent PCI-to-PCI bridge";
        break;
      case 10:
        pcVar4 = "InfiniBand-to-PCI host bridge";
        break;
      default:
        pcVar4 = "Other bridge";
        if (param_2 != 0x80) {
          pcVar4 = "Bridge";
        }
      }
      break;
    case 7:
      pcVar4 = "Simple Communication controllers";
      break;
    case 8:
      pcVar4 = "Base system peripherals";
      break;
    case 9:
      pcVar4 = "Input devices";
      break;
    case 10:
      pcVar4 = "Docking stations";
      break;
    case 0xb:
      pcVar4 = "Processors";
      break;
    case 0xc:
      pcVar4 = "Serial bus controllers";
      break;
    case 0xd:
      pcVar4 = "Wireless controller";
      break;
    case 0xe:
      pcVar4 = "Intelligent I/O controllers";
      break;
    case 0xf:
      pcVar4 = "Satellite communication controllers";
      break;
    case 0x10:
      pcVar4 = "Encryption/Decryption controllers";
      break;
    case 0x11:
      pcVar4 = "Data acquisition and signal processing controllers";
      break;
    default:
      pcVar4 = "Other";
      if (param_1 != 0xff) {
        return 6;
      }
    }
    if (3 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t0x%02x%02x%02x %s\n",&DAT_002983c2,lVar2,
                   "api.c",0x1ec4,param_1,param_2,param_3,pcVar4);
    }
    uVar1 = snprintf(param_4,(ulong)param_5,"%s",pcVar4);
    if ((uVar1 == 0xffffffff) || (uVar3 = 0, param_5 <= uVar1)) {
      uVar3 = 7;
    }
  }
  return uVar3;
}


// ===== 00154d40 FUN_00154d40 =====

int FUN_00154d40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                undefined4 param_5)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%u, %u, %u, %p, %u)\n","DEBUG",lVar3,
                 "entry_points.h",0x8ba,param_1,param_2,param_3,param_4,param_5);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00154a10(param_1,param_2,param_3,param_4,param_5);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x8ba,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00154ea0 FUN_00154ea0 =====

undefined8 FUN_00154ea0(char *param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined8 uVar3;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if (((*param_1 == '\x01') ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) &&
     ((param_2 < 2 || (param_2 == 500)))) {
    iVar2 = FUN_00236dd0();
    if (iVar2 != 0) {
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (((lVar1 != 0) && (*(long *)(lVar1 + 0x140) != 0)) &&
         (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x140) + 0xa8),
         UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00154f32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3,param_4);
        return uVar3;
      }
      return 3;
    }
    uVar3 = 4;
  }
  else {
    uVar3 = 2;
  }
  return uVar3;
}


// ===== 00154f80 FUN_00154f80 =====

int FUN_00154f80(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u, %llu, %llu)\n","DEBUG",lVar3,
                 "entry_points.h",0x8be,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00154ea0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x8be,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001550d0 FUN_001550d0 =====

undefined8 FUN_001550d0(char *param_1,uint param_2,long param_3,long param_4)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined8 uVar3;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if (((*param_1 == '\x01') ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) &&
     (((param_3 != 0 && (param_4 != 0)) && ((param_2 < 2 || (param_2 == 500)))))) {
    iVar2 = FUN_00236dd0();
    if (iVar2 != 0) {
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (((lVar1 != 0) && (*(long *)(lVar1 + 0x140) != 0)) &&
         (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x140) + 0xb0),
         UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0015516c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3,param_4);
        return uVar3;
      }
      return 3;
    }
    uVar3 = 4;
  }
  else {
    uVar3 = 2;
  }
  return uVar3;
}


// ===== 001551b0 FUN_001551b0 =====

int FUN_001551b0(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x8c1,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001550d0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x8c1,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00155300 FUN_00155300 =====

undefined8 FUN_00155300(char *param_1,uint param_2,long param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (((param_1 != (char *)0x0) &&
      ((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) &&
     ((param_3 != 0 && (param_2 < 3)))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x160) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0x18),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0015535c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00155380 FUN_00155380 =====

int FUN_00155380(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x8c4,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00155300(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x8c4,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001554c0 FUN_001554c0 =====

undefined8 FUN_001554c0(char *param_1,uint param_2,undefined4 param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined8 uVar3;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if (((*param_1 == '\x01') ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_2 < 3)) {
    iVar2 = FUN_00236dd0();
    if (iVar2 != 0) {
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (((lVar1 != 0) && (*(long *)(lVar1 + 0x160) != 0)) &&
         (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0x20),
         UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00155558. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,0,param_2,param_3);
        return uVar3;
      }
      return 3;
    }
    uVar3 = 4;
  }
  else {
    uVar3 = 2;
  }
  return uVar3;
}


// ===== 00155590 FUN_00155590 =====

int FUN_00155590(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d, %d)\n",
                 "DEBUG",lVar3,"entry_points.h",0x8c8,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001554c0(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x8c8,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001556d0 FUN_001556d0 =====

undefined8 FUN_001556d0(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0xd8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00155728. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00155750 FUN_00155750 =====

int FUN_00155750(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa08,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001556d0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xa08,iVar1,uVar2);
  return iVar1;
}


// ===== 00155890 FUN_00155890 =====

undefined8 FUN_00155890(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0xe0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001558e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00155910 FUN_00155910 =====

int FUN_00155910(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa0d,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00155890(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xa0d,iVar1,uVar2);
  return iVar1;
}


// ===== 00155a50 FUN_00155a50 =====

undefined8 FUN_00155a50(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0xd;
    return 0;
  }
  return 2;
}


// ===== 00155a70 FUN_00155a70 =====

int FUN_00155a70(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0x8cc,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00155a50(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x8cc,iVar1,uVar2);
  return iVar1;
}


// ===== 00155ba0 FUN_00155ba0 =====

int FUN_00155ba0(char *param_1,int param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  int local_2c [3];
  
  if (param_1 != (char *)0x0) {
    if (((*param_1 == '\x01') ||
        ((((iVar2 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
          (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) &&
       ((iVar2 = 3, param_2 != 0 && (iVar2 = 2, param_2 == 1)))) {
      local_2c[0] = 0;
      iVar2 = FUN_00139230(param_1,local_2c,7);
      if (iVar2 == 0) {
        if (local_2c[0] == 0) {
          lVar3 = *(long *)(param_1 + 0x256d8);
          iVar2 = 3;
          if (((lVar3 != 0) && (*(long *)(lVar3 + 0x170) != 0)) &&
             (pcVar1 = *(code **)(*(long *)(lVar3 + 0x170) + 0x168), pcVar1 != (code *)0x0)) {
            iVar2 = (*pcVar1)(lVar3,param_1,param_3);
          }
        }
        else {
          iVar2 = 3;
          if (4 < DAT_01216a78) {
            fVar4 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                         "DEBUG",lVar3,"api.c",0x1fd5);
          }
        }
      }
    }
    return iVar2;
  }
  return 2;
}


// ===== 00155d00 nvmlDeviceSetAPIRestriction =====

int nvmlDeviceSetAPIRestriction(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d, %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x29c,"nvmlDeviceSetAPIRestriction",
                 "(nvmlDevice_t device, nvmlRestrictedAPI_t apiType, nvmlEnableState_t isRestricted)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00155ba0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x29c,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x29c,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00155ed0 FUN_00155ed0 =====

undefined8 FUN_00155ed0(char *param_1,int param_2,long param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 == (char *)0x0) ||
     (((*param_1 != '\x01' &&
       ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
         (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) || (param_3 == 0)))
     ) {
    return 2;
  }
  if (param_2 != 0) {
    if (param_2 != 1) {
      return 2;
    }
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x160),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00155f2e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1);
      return uVar2;
    }
  }
  return 3;
}


// ===== 00155f50 nvmlDeviceGetAPIRestriction =====

int nvmlDeviceGetAPIRestriction(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x2a0,"nvmlDeviceGetAPIRestriction",
                 "(nvmlDevice_t device, nvmlRestrictedAPI_t apiType, nvmlEnableState_t *isRestricted)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00155ed0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2a0,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2a0,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00156120 FUN_00156120 =====

undefined8 FUN_00156120(char *param_1,long param_2)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 200) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 200) + 0x20),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00156175. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 001561a0 nvmlDeviceGetMinorNumber =====

int nvmlDeviceGetMinorNumber(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x2a4,"nvmlDeviceGetMinorNumber",
                 "(nvmlDevice_t device, unsigned int *minorNumber)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00156120(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2a4,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2a4,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00156380 FUN_00156380 =====

undefined8 FUN_00156380(char *param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_2 != 0)))
     ) {
    uVar1 = FUN_00139230(param_1,param_2,6);
    return uVar1;
  }
  return 2;
}


// ===== 001563c0 FUN_001563c0 =====

int FUN_001563c0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x952,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00156380(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x952,iVar1,uVar2);
  return iVar1;
}


// ===== 00156500 FUN_00156500 =====

int FUN_00156500(char *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int local_80;
  int local_7c;
  undefined1 local_78 [28];
  uint local_5c;
  
  local_80 = 0;
  local_7c = 0;
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((iVar1 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (param_2 == (undefined4 *)0x0) {
      return 2;
    }
    iVar1 = FUN_0014b320(param_1,&local_80);
    if ((iVar1 == 0) && ((local_80 == 5 || (iVar1 = 3, local_80 == 0xf)))) {
      *param_2 = 0;
      iVar2 = FUN_00156380(param_1,&local_7c);
      iVar1 = iVar2;
      if ((iVar2 == 0) &&
         ((local_7c != 0 ||
          ((iVar1 = FUN_0013eca0(param_1,local_78), iVar1 == 0 &&
           ((local_5c == 0x17c210de || local_5c == 0x100c10de ||
            (iVar1 = iVar2, (local_5c & 0xfffbffff) == 0x100110de)))))))) {
        *param_2 = 1;
        iVar1 = iVar2;
      }
    }
  }
  return iVar1;
}


// ===== 00156620 FUN_00156620 =====

int FUN_00156620(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x95e,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00156500(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x95e,iVar1,uVar2);
  return iVar1;
}


// ===== 00156760 FUN_00156760 =====

undefined8 FUN_00156760(char *param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  int local_1c [3];
  
  local_1c[0] = 0;
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((uVar1 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (param_2 == (undefined4 *)0x0) {
      return 2;
    }
    uVar1 = FUN_0014b320(param_1,local_1c);
    if ((int)uVar1 == 0) {
      if (local_1c[0] != 6) {
        return 3;
      }
      *param_2 = 1;
    }
  }
  return uVar1;
}


// ===== 001567f0 FUN_001567f0 =====

int FUN_001567f0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x992,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00156760(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x992,iVar1,uVar2);
  return iVar1;
}


// ===== 00156930 FUN_00156930 =====

undefined8 FUN_00156930(char *param_1,long param_2)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x118) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x118) + 0x98),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00156988. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 001569b0 FUN_001569b0 =====

int FUN_001569b0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x95a,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00156930(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x95a,iVar1,uVar2);
  return iVar1;
}


// ===== 00156af0 FUN_00156af0 =====

undefined8 FUN_00156af0(char *param_1,undefined4 param_2,long param_3)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  int local_2c [3];
  
  uVar3 = FUN_00139230(param_1,local_2c,7);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  if (local_2c[0] == 0) {
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
    if (param_3 != 0) {
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (((lVar1 != 0) && (*(long *)(lVar1 + 0x158) != 0)) &&
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x158) + 8), pcVar2 != (code *)0x0)) {
        uVar3 = (*pcVar2)(lVar1,param_1,param_2,param_3);
        return uVar3;
      }
      return 3;
    }
  }
  return 2;
}


// ===== 00156bc0 nvmlDeviceGetNvLinkState =====

int nvmlDeviceGetNvLinkState(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x2cd,"nvmlDeviceGetNvLinkState",
                 "(nvmlDevice_t device, unsigned int link, nvmlEnableState_t *isActive)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00156af0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2cd,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2cd,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00156d90 FUN_00156d90 =====

undefined8 FUN_00156d90(char *param_1,undefined4 param_2,long param_3)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  int local_2c [3];
  
  uVar3 = FUN_00139230(param_1,local_2c,7);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  if (local_2c[0] == 0) {
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
    if (param_3 != 0) {
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (((lVar1 != 0) && (*(long *)(lVar1 + 0x158) != 0)) &&
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x158) + 0x10), pcVar2 != (code *)0x0)) {
        uVar3 = (*pcVar2)(lVar1,param_1,param_2,param_3);
        return uVar3;
      }
      return 3;
    }
  }
  return 2;
}


// ===== 00156e60 nvmlDeviceGetNvLinkVersion =====

int nvmlDeviceGetNvLinkVersion(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x2d7,"nvmlDeviceGetNvLinkVersion",
                 "(nvmlDevice_t device, unsigned int link, unsigned int *version)",param_1,param_2,
                 param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00156d90(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2d7,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2d7,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00157030 FUN_00157030 =====

undefined8 FUN_00157030(char *param_1,undefined4 param_2,undefined4 param_3,long param_4)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  int local_2c;
  
  uVar3 = FUN_00139230(param_1,&local_2c,7);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  if (local_2c == 0) {
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
    if (param_4 != 0) {
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (((lVar1 != 0) && (*(long *)(lVar1 + 0x158) != 0)) &&
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x158) + 0x18), pcVar2 != (code *)0x0)) {
        uVar3 = (*pcVar2)(lVar1,param_1,param_2,param_3,param_4);
        return uVar3;
      }
      return 3;
    }
  }
  return 2;
}


// ===== 00157100 nvmlDeviceGetNvLinkCapability =====

int nvmlDeviceGetNvLinkCapability
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
                 ,"entry_points.h",0x2eb,"nvmlDeviceGetNvLinkCapability",
                 "(nvmlDevice_t device, unsigned int link, nvmlNvLinkCapability_t capability, unsigned int *capResult)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00157030(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2eb,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2eb,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001572f0 FUN_001572f0 =====

int FUN_001572f0(uint param_1,char *param_2,undefined4 param_3,long param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  int local_58;
  undefined4 local_54;
  ushort local_50;
  ushort local_4e;
  undefined4 local_48 [6];
  
  iVar2 = FUN_00139230(param_2,&local_58,7);
  if (iVar2 != 0) {
    return iVar2;
  }
  if (local_58 == 0) {
    return 3;
  }
  if (param_2 != (char *)0x0) {
    if (*param_2 != '\x01') {
      if (*(int *)(param_2 + 0x14) == 0) {
        return 2;
      }
      if (*(int *)(param_2 + 0x1c) != 0) {
        return 2;
      }
      if (*(int *)(param_2 + 0x10) == 0) {
        return 2;
      }
      if (*(long *)(param_2 + 0x20) == 0) {
        return 2;
      }
    }
    if (param_4 != 0) {
      lVar3 = *(long *)(param_2 + 0x256d8);
      if (((lVar3 == 0) || (*(long *)(lVar3 + 0x158) == 0)) ||
         (pcVar1 = *(code **)(*(long *)(lVar3 + 0x158) + 0x20), pcVar1 == (code *)0x0)) {
        iVar2 = 3;
      }
      else {
        iVar2 = (*pcVar1)(lVar3,param_2,param_3,&local_54,local_48);
        if (iVar2 == 0) {
          *(undefined4 *)(param_4 + 0x10) = local_54;
          *(uint *)(param_4 + 0x14) = (uint)local_50;
          *(uint *)(param_4 + 0x18) = (uint)local_4e;
          *(undefined4 *)(param_4 + 0x1c) = local_48[0];
          if (param_1 == 1) {
            FUN_0013ace0(2,param_4);
            return 0;
          }
          if (param_1 < 2) {
            return 0;
          }
          FUN_0013ace0(3,param_4);
          return 0;
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar3,"api.c",0x214c,"tsapiDeviceGetNvLinkRemotePciInfoInternal",0x214c,
                   iVar2);
      return iVar2;
    }
  }
  return 2;
}


// ===== 001574c0 FUN_001574c0 =====

void FUN_001574c0(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  FUN_001572f0(1,param_1,param_2,param_3);
  return;
}


// ===== 001574e0 nvmlDeviceGetNvLinkRemotePciInfo =====

int nvmlDeviceGetNvLinkRemotePciInfo(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x2dc,"nvmlDeviceGetNvLinkRemotePciInfo",
                 "(nvmlDevice_t device, unsigned int link, nvmlPciInfo_t *pci)",param_1,param_2,
                 param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001574c0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2dc,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2dc,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001576b0 FUN_001576b0 =====

void FUN_001576b0(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  FUN_001572f0(2,param_1,param_2,param_3);
  return;
}


// ===== 001576d0 nvmlDeviceGetNvLinkRemotePciInfo_v2 =====

int nvmlDeviceGetNvLinkRemotePciInfo_v2(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x2e1,"nvmlDeviceGetNvLinkRemotePciInfo_v2",
                 "(nvmlDevice_t device, unsigned int link, nvmlPciInfo_t *pci)",param_1,param_2,
                 param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001576b0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2e1,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2e1,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001578a0 FUN_001578a0 =====

undefined8 FUN_001578a0(char *param_1,undefined4 param_2,long param_3)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  int local_2c [3];
  
  uVar3 = FUN_00139230(param_1,local_2c,7);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  if (local_2c[0] == 0) {
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
    if (param_3 != 0) {
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (((lVar1 != 0) && (*(long *)(lVar1 + 0x158) != 0)) &&
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x158) + 0x28), pcVar2 != (code *)0x0)) {
        uVar3 = (*pcVar2)(lVar1,param_1,param_2,param_3);
        return uVar3;
      }
      return 3;
    }
  }
  return 2;
}


// ===== 00157970 nvmlDeviceGetNvLinkRemoteDeviceType =====

int nvmlDeviceGetNvLinkRemoteDeviceType(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x2e6,"nvmlDeviceGetNvLinkRemoteDeviceType",
                 "(nvmlDevice_t device, unsigned int link, nvmlIntNvLinkDeviceType_t *pNvLinkDeviceType)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001578a0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2e6,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2e6,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00157b40 FUN_00157b40 =====

undefined8 FUN_00157b40(char *param_1,undefined4 param_2,int param_3,int param_4,long param_5)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  int local_40;
  int local_3c [3];
  
  uVar3 = FUN_00139230(param_1,&local_40,7);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  if (local_40 == 0) {
    return 3;
  }
  uVar3 = FUN_00139230(param_1,local_3c,0xd);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  if (local_3c[0] != 0) {
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
    if (param_5 != 0) {
      if ((param_3 == 8) && (param_4 != 8)) {
        return 2;
      }
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (((lVar1 != 0) && (*(long *)(lVar1 + 0x158) != 0)) &&
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x158) + 0x30), pcVar2 != (code *)0x0)) {
        uVar3 = (*pcVar2)(lVar1,param_1,param_2,param_3,param_4,param_5);
        return uVar3;
      }
      return 3;
    }
  }
  return 2;
}


// ===== 00157c60 FUN_00157c60 =====

int FUN_00157c60(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d, %d, %d, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x97c,param_1,param_2,param_3,param_4,param_5);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00157b40(param_1,param_2,param_3,param_4,param_5);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x97c,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00157dc0 FUN_00157dc0 =====

undefined8 FUN_00157dc0(char *param_1,undefined4 param_2,int param_3,uint param_4,long param_5)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  int local_40;
  int local_3c [3];
  
  uVar3 = FUN_00139230(param_1,&local_40,10);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  if (local_40 == 0) {
    return 3;
  }
  uVar3 = FUN_00139230(param_1,local_3c,0xd);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  if (local_3c[0] != 0) {
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
    if (param_5 != 0) {
      if ((param_3 == 4) && (param_4 < 4)) {
        return 2;
      }
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (((lVar1 != 0) && (*(long *)(lVar1 + 0x158) != 0)) &&
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x158) + 0x38), pcVar2 != (code *)0x0)) {
        uVar3 = (*pcVar2)(lVar1,param_1,param_2,param_3,param_4,param_5);
        return uVar3;
      }
      return 3;
    }
  }
  return 2;
}


// ===== 00157ee0 FUN_00157ee0 =====

int FUN_00157ee0(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d, %d, %d, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x982,param_1,param_2,param_3,param_4,param_5);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00157dc0(param_1,param_2,param_3,param_4,param_5);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x982,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00158040 FUN_00158040 =====

ulong FUN_00158040(char *param_1,undefined4 param_2,int param_3,long *param_4)

{
  code *pcVar1;
  uint uVar2;
  ulong uVar3;
  long *__ptr;
  long lVar4;
  long *plVar5;
  int local_30;
  int local_2c;
  
  uVar3 = FUN_00139230(param_1,&local_30,7);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  if (local_30 == 0) {
    return 3;
  }
  uVar3 = FUN_00139230(param_1,&local_2c,0xd);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  if (local_2c != 0) {
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
    if (param_4 != (long *)0x0) {
      if (param_3 == 3) {
        __ptr = malloc(0x40);
        uVar2 = FUN_00157b40(param_1,param_2,8,8,__ptr);
        if (uVar2 == 0) {
          lVar4 = 0;
          plVar5 = __ptr;
          do {
            lVar4 = lVar4 + *plVar5;
            plVar5 = plVar5 + 1;
          } while (plVar5 != __ptr + 8);
          *param_4 = lVar4;
          free(__ptr);
          return 0;
        }
      }
      else {
        if (param_3 != 4) {
          lVar4 = *(long *)(param_1 + 0x256d8);
          if (((lVar4 != 0) && (*(long *)(lVar4 + 0x158) != 0)) &&
             (pcVar1 = *(code **)(*(long *)(lVar4 + 0x158) + 0x40), pcVar1 != (code *)0x0)) {
            uVar3 = (*pcVar1)(lVar4,param_1,param_2,param_3,param_4);
            return uVar3;
          }
          return 3;
        }
        __ptr = malloc(0x20);
        uVar2 = FUN_00157dc0(param_1,param_2,4,4,__ptr);
        if (uVar2 == 0) {
          *param_4 = *__ptr + __ptr[1] + __ptr[2] + __ptr[3];
        }
      }
      free(__ptr);
      return (ulong)uVar2;
    }
  }
  return 2;
}


// ===== 00158200 nvmlDeviceGetNvLinkErrorCounter =====

int nvmlDeviceGetNvLinkErrorCounter
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
                 ,"entry_points.h",0x2f0,"nvmlDeviceGetNvLinkErrorCounter",
                 "(nvmlDevice_t device, unsigned int link, nvmlNvLinkErrorCounter_t counter, unsigned long long *counterValue)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00158040(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2f0,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2f0,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001583f0 FUN_001583f0 =====

undefined8 FUN_001583f0(char *param_1,undefined4 param_2)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  int local_1c;
  
  uVar3 = FUN_00139230(param_1,&local_1c,7);
  if (((int)uVar3 == 0) && (uVar3 = 3, local_1c != 0)) {
    if (param_1 == (char *)0x0) {
      uVar3 = 2;
    }
    else if ((*param_1 == '\x01') ||
            ((((uVar3 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
              (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (((lVar1 == 0) || (*(long *)(lVar1 + 0x158) == 0)) ||
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x158) + 0x48), pcVar2 == (code *)0x0)) {
        return 3;
      }
      uVar3 = (*pcVar2)(lVar1,param_1,param_2);
    }
  }
  return uVar3;
}


// ===== 001584b0 nvmlDeviceResetNvLinkErrorCounters =====

int nvmlDeviceResetNvLinkErrorCounters(undefined8 param_1,undefined4 param_2)

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
                 "entry_points.h",0x2f5,"nvmlDeviceResetNvLinkErrorCounters",
                 "(nvmlDevice_t device, unsigned int link)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001583f0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2f5,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2f5,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00158690 FUN_00158690 =====

undefined8 FUN_00158690(void)

{
  return 3;
}


// ===== 001586a0 nvmlDeviceSetNvLinkUtilizationControl =====

int nvmlDeviceSetNvLinkUtilizationControl
              (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
              undefined4 param_5)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d, %d, %p, %d)\n","DEBUG",
                 lVar3,"entry_points.h",0x2fa,"nvmlDeviceSetNvLinkUtilizationControl",
                 "(nvmlDevice_t device, unsigned int link, unsigned int counter, nvmlNvLinkUtilizationControl_t *control, unsigned int reset)"
                 ,param_1,param_2,param_3,param_4,param_5);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00158690(param_1,param_2,param_3,param_4,param_5);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2fa,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2fa,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00158890 FUN_00158890 =====

undefined8 FUN_00158890(void)

{
  return 3;
}


// ===== 001588a0 nvmlDeviceGetNvLinkUtilizationControl =====

int nvmlDeviceGetNvLinkUtilizationControl
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
                 ,"entry_points.h",0x2ff,"nvmlDeviceGetNvLinkUtilizationControl",
                 "(nvmlDevice_t device, unsigned int link, unsigned int counter, nvmlNvLinkUtilizationControl_t *control)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00158890(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2ff,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2ff,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00158a90 FUN_00158a90 =====

undefined8 FUN_00158a90(void)

{
  return 3;
}


// ===== 00158aa0 nvmlDeviceGetNvLinkUtilizationCounter =====

int nvmlDeviceGetNvLinkUtilizationCounter
              (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
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
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d, %d, %p, %p)\n","DEBUG",
                 lVar3,"entry_points.h",0x304,"nvmlDeviceGetNvLinkUtilizationCounter",
                 "(nvmlDevice_t device, unsigned int link, unsigned int counter, unsigned long long *rxcounter, unsigned long long *txcounter)"
                 ,param_1,param_2,param_3,param_4,param_5);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00158a90(param_1,param_2,param_3,param_4,param_5);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x304,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x304,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00158c90 FUN_00158c90 =====

undefined8 FUN_00158c90(void)

{
  return 3;
}


// ===== 00158ca0 nvmlDeviceFreezeNvLinkUtilizationCounter =====

int nvmlDeviceFreezeNvLinkUtilizationCounter
              (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d, %d, %d)\n","DEBUG",lVar3
                 ,"entry_points.h",0x309,"nvmlDeviceFreezeNvLinkUtilizationCounter",
                 "(nvmlDevice_t device, unsigned int link, unsigned int counter, nvmlEnableState_t freeze)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00158c90(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x309,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x309,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00158e90 FUN_00158e90 =====

undefined8 FUN_00158e90(void)

{
  return 3;
}


// ===== 00158ea0 nvmlDeviceResetNvLinkUtilizationCounter =====

int nvmlDeviceResetNvLinkUtilizationCounter
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
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d, %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x30e,"nvmlDeviceResetNvLinkUtilizationCounter",
                 "(nvmlDevice_t device, unsigned int link, unsigned int counter)",param_1,param_2,
                 param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00158e90(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x30e,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x30e,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00159070 FUN_00159070 =====

undefined8 FUN_00159070(undefined8 param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x170) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x170) + 0x1a8),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0015909e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar1;
  }
  return 3;
}


// ===== 001590b0 FUN_001590b0 =====

int FUN_001590b0(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0x968,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00159070(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x968,iVar1,uVar2);
  return iVar1;
}


// ===== 001591e0 FUN_001591e0 =====

undefined8 FUN_001591e0(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x170) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x170) + 0x1b8),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00159216. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1,param_2,param_3);
    return uVar1;
  }
  return 3;
}


// ===== 00159230 FUN_00159230 =====

int FUN_00159230(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %d %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x96d,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001591e0(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x96d,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00159370 FUN_00159370 =====

undefined8 FUN_00159370(undefined4 param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x170) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x170) + 0x1b0),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0015939d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar1;
  }
  return 3;
}


// ===== 001593b0 FUN_001593b0 =====

int FUN_001593b0(undefined4 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%u)\n","DEBUG",
                 lVar3,"entry_points.h",0x972,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00159370(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x972,iVar1,uVar2);
  return iVar1;
}


// ===== 001594e0 FUN_001594e0 =====

undefined8 FUN_001594e0(undefined8 param_1,undefined4 param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (((DAT_012164a0 != 0) && (*(undefined8 **)(DAT_012164a0 + 0x138) != (undefined8 *)0x0)) &&
     (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(DAT_012164a0 + 0x138),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0015950f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1,param_2);
    return uVar1;
  }
  return 3;
}


// ===== 00159520 nvmlDeviceModifyDrainState =====

int nvmlDeviceModifyDrainState(undefined8 param_1,undefined4 param_2)

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
                 "entry_points.h",0x447,"nvmlDeviceModifyDrainState",
                 "(nvmlPciInfo_t *pciInfo, nvmlEnableState_t newState)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001594e0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x447,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x447,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00159700 FUN_00159700 =====

undefined8 FUN_00159700(undefined8 param_1,long param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined1 local_c [4];
  
  if (param_2 == 0) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x138) != 0)) &&
     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x138) + 8), pcVar1 != (code *)0x0)) {
    uVar2 = (*pcVar1)(DAT_012164a0,param_1,param_2,local_c);
    return uVar2;
  }
  return 3;
}


// ===== 00159770 nvmlDeviceQueryDrainState =====

int nvmlDeviceQueryDrainState(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x44c,"nvmlDeviceQueryDrainState",
                 "(nvmlPciInfo_t *pciInfo, nvmlEnableState_t *newState)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00159700(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x44c,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x44c,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00159950 FUN_00159950 =====

undefined8 FUN_00159950(undefined8 param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x138) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x138) + 0x10),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0015997f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1,0,0);
    return uVar1;
  }
  return 3;
}


// ===== 00159990 nvmlDeviceRemoveGpu =====

int nvmlDeviceRemoveGpu(char *param_1)

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
    pcVar5 = "(nvmlPciInfo_t *pciInfo)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x451,"nvmlDeviceRemoveGpu");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_00159950(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x451,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x451,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00159b60 FUN_00159b60 =====

undefined8 FUN_00159b60(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x138) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x138) + 0x10),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00159b92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1,param_2,param_3);
    return uVar1;
  }
  return 3;
}


// ===== 00159ba0 nvmlDeviceRemoveGpu_v2 =====

int nvmlDeviceRemoveGpu_v2(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d, %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x456,"nvmlDeviceRemoveGpu_v2",
                 "(nvmlPciInfo_t *pciInfo, nvmlDetachGpuState_t gpuState, nvmlPcieLinkState_t linkState)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00159b60(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x456,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x456,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00159d70 FUN_00159d70 =====

undefined8 FUN_00159d70(long param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x138) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x138) + 0x18),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00159da0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar1;
  }
  return 3;
}


// ===== 00159dc0 nvmlDeviceDiscoverGpus =====

int nvmlDeviceDiscoverGpus(char *param_1)

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
    pcVar5 = "(nvmlPciInfo_t *pciInfo)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x45b,"nvmlDeviceDiscoverGpus");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_00159d70(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x45b,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x45b,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00159f90 FUN_00159f90 =====

int FUN_00159f90(char *param_1,int param_2,long param_3)

{
  undefined1 uVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  long lVar7;
  long lVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  float fVar11;
  undefined8 uVar12;
  undefined8 local_d8;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_58;
  int local_54;
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  undefined8 local_48;
  undefined8 local_40;
  
  local_58 = 0;
  local_54 = 0;
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
    if ((0 < param_2) && (param_3 != 0)) {
      iVar4 = FUN_00139230(param_1,&local_58,0xc);
      if (iVar4 == 0) {
        iVar4 = FUN_00139230(param_1,&local_54,0xd);
        if (iVar4 == 0) {
          local_90 = 0;
          iVar4 = 0;
          local_d0 = -1;
          puVar9 = (undefined8 *)(param_3 + 0x20);
          local_b0 = -1;
          local_b8 = -1;
          local_98 = -1;
          local_78 = 0;
          local_cc = -1;
          local_ac = -1;
          local_88 = 0;
          local_c8 = -1;
          local_a8 = -1;
          local_84 = 0;
          local_c4 = -1;
          local_a4 = -1;
          local_8c = 0;
          local_c0 = -1;
          local_a0 = -1;
          local_80 = 0;
          local_bc = -1;
          local_9c = -1;
          local_74 = 0;
          local_6c = -1;
          local_64 = -1;
          local_68 = 0;
          local_b4 = -1;
          local_94 = -1;
          local_70 = 0;
LAB_0015a1f0:
          iVar5 = *(int *)(puVar9 + -4);
          switch(iVar5) {
          default:
            *(undefined4 *)((long)puVar9 + -4) = 2;
            if (1 < DAT_01216a78) {
              fVar11 = (float)FUN_002917b0(&DAT_01216a60);
              lVar7 = syscall(0xba);
              FUN_002340f0((double)(fVar11 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %d %d\n","ERROR",lVar7,"api.c",
                           0x2583,iVar5,iVar4,param_2);
            }
            break;
          case 1:
          case 2:
          case 3:
          case 4:
          case 5:
          case 6:
          case 7:
          case 8:
          case 9:
          case 10:
          case 0xb:
          case 0xc:
          case 0xd:
          case 0xe:
          case 0xf:
          case 0x10:
          case 0x11:
          case 0x12:
          case 0x13:
          case 0x14:
          case 0x15:
          case 0x16:
          case 0x17:
          case 0x18:
          case 0x19:
          case 0x1a:
          case 0x1b:
          case 0x1c:
          case 0x1d:
          case 0x1e:
          case 0x1f:
          case 0x5c:
          case 0x5d:
          case 0x8e:
          case 0x8f:
          case 0x90:
          case 0x91:
          case 0x12d:
          case 0x12e:
            if (local_94 == -1) {
              local_94 = iVar4;
            }
            local_70 = local_70 + 1;
            local_b4 = iVar4;
            break;
          case 0x20:
          case 0x21:
          case 0x22:
          case 0x23:
          case 0x24:
          case 0x25:
          case 0x26:
          case 0x27:
          case 0x28:
          case 0x29:
          case 0x2a:
          case 0x2b:
          case 0x2c:
          case 0x2d:
          case 0x2e:
          case 0x2f:
          case 0x30:
          case 0x31:
          case 0x32:
          case 0x33:
          case 0x34:
          case 0x35:
          case 0x36:
          case 0x37:
          case 0x38:
          case 0x39:
          case 0x3a:
          case 0x3b:
          case 0x54:
          case 0x55:
          case 0x56:
          case 0x57:
          case 0x58:
          case 0x59:
          case 0x5a:
          case 0x60:
          case 0x61:
          case 0x62:
          case 99:
          case 100:
          case 0x65:
          case 0x66:
          case 0x67:
          case 0x68:
          case 0x69:
          case 0x6a:
          case 0x6b:
          case 0x6c:
          case 0x6d:
          case 0x6e:
          case 0x6f:
          case 0x70:
          case 0x71:
          case 0x72:
          case 0x73:
          case 0x74:
          case 0x75:
          case 0x76:
          case 0x77:
          case 0x84:
          case 0x85:
          case 0x86:
          case 0x87:
          case 0x88:
          case 0x89:
          case 0x94:
          case 0x95:
          case 0x96:
          case 0x97:
          case 0x98:
          case 0x99:
          case 0x9a:
          case 0x9b:
          case 0x9c:
          case 0x9d:
          case 0x9e:
          case 0x9f:
          case 0xa0:
            if (local_58 == 0) goto switchD_0015a20f_caseD_5b;
          case 0x3c:
          case 0x3d:
          case 0x3e:
          case 0x3f:
          case 0x40:
          case 0x41:
          case 0x42:
          case 0x43:
          case 0x44:
          case 0x45:
          case 0x46:
          case 0x47:
          case 0x48:
          case 0x49:
          case 0x78:
          case 0x79:
          case 0x7a:
          case 0x7b:
          case 0x7c:
          case 0x7d:
          case 0x7e:
          case 0x7f:
          case 0x80:
          case 0x81:
          case 0x82:
          case 0x83:
switchD_0015a20f_caseD_3c:
            *(undefined4 *)((long)puVar9 + -4) = 3;
            break;
          case 0x4a:
          case 0x4c:
          case 0x4d:
          case 0x4e:
          case 0x4f:
          case 0x50:
          case 0x51:
          case 0x10d:
            if (local_98 == -1) {
              local_98 = iVar4;
            }
            local_78 = local_78 + 1;
            local_b8 = iVar4;
            break;
          case 0x4b:
            lVar8 = FUN_00234e30();
            lVar7 = *(long *)(param_1 + 0x256d8);
            uVar6 = 3;
            if (((lVar7 != 0) && (*(long *)(lVar7 + 0x148) != 0)) &&
               (pcVar3 = *(code **)(*(long *)(lVar7 + 0x148) + 0x10), pcVar3 != (code *)0x0)) {
              uVar6 = (*pcVar3)(lVar7,param_1,1,&local_48);
            }
            *(undefined4 *)((long)puVar9 + -4) = uVar6;
            lVar7 = FUN_00234e30();
            *(undefined4 *)(puVar9 + -1) = 3;
            puVar9[-2] = lVar7 - lVar8;
            *puVar9 = local_40;
            puVar9[-3] = local_48;
            break;
          case 0x52:
            lVar7 = *(long *)(param_1 + 0x256d8);
            if ((lVar7 != 0) && (*(long *)(lVar7 + 0x148) != 0)) {
              pcVar3 = *(code **)(*(long *)(lVar7 + 0x148) + 0x28);
joined_r0x0015ac2f:
              if (pcVar3 != (code *)0x0) {
                (*pcVar3)(lVar7,param_1);
              }
            }
            break;
          case 0x53:
          case 0xbf:
            uVar1 = 0;
            if (iVar5 != 0x53) {
              uVar1 = *(undefined1 *)((long)puVar9 + -0x1c);
            }
            lVar8 = FUN_00234e30();
            lVar7 = *(long *)(param_1 + 0x256d8);
            uVar6 = 3;
            if (((lVar7 != 0) && (*(undefined8 **)(lVar7 + 0x160) != (undefined8 *)0x0)) &&
               (pcVar3 = (code *)**(undefined8 **)(lVar7 + 0x160), pcVar3 != (code *)0x0)) {
              uVar6 = (*pcVar3)(lVar7,param_1,uVar1,puVar9);
            }
            *(undefined4 *)((long)puVar9 + -4) = uVar6;
            lVar7 = FUN_00234e30();
            *(undefined4 *)(puVar9 + -1) = 3;
            puVar9[-3] = lVar7;
            puVar9[-2] = lVar7 - lVar8;
            break;
          case 0x5b:
          case 0x8a:
          case 0x8b:
          case 0x8c:
          case 0x8d:
          case 0x92:
          case 0xa4:
          case 0xa5:
          case 0xa6:
            goto switchD_0015a20f_caseD_5b;
          case 0x5e:
          case 0x5f:
          case 0xa9:
          case 0xad:
          case 0xae:
          case 0xaf:
          case 0xb0:
          case 0xb1:
          case 0xb2:
          case 0xb3:
          case 0xb4:
          case 0xb5:
          case 0xb6:
          case 0xb7:
            lVar8 = FUN_00234e30();
            lVar7 = *(long *)(param_1 + 0x256d8);
            uVar6 = 3;
            if (((lVar7 != 0) && (*(long *)(lVar7 + 0x48) != 0)) &&
               (pcVar3 = *(code **)(*(long *)(lVar7 + 0x48) + 0x80), pcVar3 != (code *)0x0)) {
              uVar6 = (*pcVar3)(lVar7,param_1,*(undefined4 *)(puVar9 + -4),
                                *(undefined4 *)((long)puVar9 + -0x1c),puVar9);
            }
            *(undefined4 *)((long)puVar9 + -4) = uVar6;
            goto LAB_0015a608;
          case 0x93:
            lVar7 = *(long *)(param_1 + 0x256d8);
            if ((lVar7 != 0) && (*(long *)(lVar7 + 0x158) != 0)) {
              pcVar3 = *(code **)(*(long *)(lVar7 + 0x158) + 0x60);
              goto joined_r0x0015ac2f;
            }
            break;
          case 0xa1:
          case 0xa2:
          case 0xa3:
            if (local_54 != 0) goto switchD_0015a20f_caseD_cd;
            goto switchD_0015a20f_caseD_5b;
          case 0xa7:
          case 0xa8:
          case 200:
          case 0xdf:
          case 0xe0:
          case 0xe1:
            iVar5 = local_58;
            goto joined_r0x0015a4e5;
          case 0xaa:
          case 0xab:
          case 0xac:
          case 0xe7:
          case 0xe8:
          case 0xe9:
          case 0xea:
            if (local_9c == -1) {
              local_9c = iVar4;
            }
            local_74 = local_74 + 1;
            local_bc = iVar4;
            break;
          case 0xb8:
            lVar8 = FUN_00234e30();
            lVar7 = *(long *)(param_1 + 0x256d8);
            if (((lVar7 == 0) || (*(undefined8 **)(lVar7 + 0x30) == (undefined8 *)0x0)) ||
               ((pcVar3 = (code *)**(undefined8 **)(lVar7 + 0x30), pcVar3 == (code *)0x0 ||
                (iVar5 = (*pcVar3)(lVar7,param_1,local_50,local_4c), iVar5 == 3)))) {
              *(undefined4 *)puVar9 = 0;
              *(undefined4 *)((long)puVar9 + -4) = 3;
            }
            else if (iVar5 == 0) {
              lVar7 = *(long *)(param_1 + 0x256d8);
              if (((lVar7 == 0) || (*(long *)(lVar7 + 0x20) == 0)) ||
                 (pcVar3 = *(code **)(*(long *)(lVar7 + 0x20) + 0x68), pcVar3 == (code *)0x0)) {
                *(undefined4 *)((long)puVar9 + -4) = 3;
              }
              else {
                iVar5 = (*pcVar3)(lVar7,param_1,puVar9);
                *(int *)((long)puVar9 + -4) = iVar5;
                if (iVar5 == 0) goto LAB_0015a608;
              }
LAB_0015ac77:
              *(undefined4 *)puVar9 = 0;
            }
            else {
              *(undefined4 *)puVar9 = 0;
              *(int *)((long)puVar9 + -4) = iVar5;
            }
            goto LAB_0015a608;
          case 0xb9:
          case 0xba:
            uVar2 = *(uint *)((long)puVar9 + -0x1c);
            if (iVar5 == 0xba) {
              if (uVar2 < 3) {
                if (uVar2 != 2) {
                  local_d8 = 2;
                  goto LAB_0015a8a7;
                }
                goto switchD_0015a20f_caseD_3c;
              }
            }
            else if (uVar2 < 3) {
              local_d8 = 1;
LAB_0015a8a7:
              lVar8 = FUN_00234e30();
              lVar7 = *(long *)(param_1 + 0x256d8);
              uVar6 = 3;
              if (((lVar7 != 0) && (*(long *)(lVar7 + 0x160) != 0)) &&
                 (pcVar3 = *(code **)(*(long *)(lVar7 + 0x160) + 8), pcVar3 != (code *)0x0)) {
                uVar6 = (*pcVar3)(lVar7,param_1,*(undefined1 *)((long)puVar9 + -0x1c),puVar9,
                                  local_d8);
              }
              goto LAB_0015a828;
            }
            *(undefined4 *)((long)puVar9 + -4) = 2;
            break;
          case 0xbb:
          case 0xbc:
          case 0xbd:
          case 0xbe:
          case 0xc0:
            if (local_a0 == -1) {
              local_a0 = iVar4;
            }
            local_80 = local_80 + 1;
            local_c0 = iVar4;
            break;
          case 0xc1:
          case 0xc2:
          case 0xc3:
          case 0xc4:
            if (local_a4 == -1) {
              local_a4 = iVar4;
            }
            local_8c = local_8c + 1;
            local_c4 = iVar4;
            break;
          case 0xc5:
          case 0xc6:
            lVar7 = FUN_00234e30();
            uVar6 = FUN_0013e010(param_1,iVar5 != 0xc5,puVar9);
            *(undefined4 *)((long)puVar9 + -4) = uVar6;
            lVar8 = FUN_00234e30();
            *(undefined4 *)(puVar9 + -1) = 1;
            puVar9[-3] = lVar8;
            puVar9[-2] = lVar8 - lVar7;
            break;
          case 199:
            lVar8 = FUN_00234e30();
            lVar7 = *(long *)(param_1 + 0x256d8);
            if (((lVar7 == 0) || (*(undefined8 **)(lVar7 + 0x30) == (undefined8 *)0x0)) ||
               (pcVar3 = (code *)**(undefined8 **)(lVar7 + 0x30), pcVar3 == (code *)0x0)) {
              *(undefined4 *)((long)puVar9 + -4) = 0;
            }
            else {
              iVar5 = (*pcVar3)(lVar7,param_1,local_50,local_4c);
              *(undefined4 *)((long)puVar9 + -4) = 0;
              if (iVar5 != 3) {
                if (iVar5 == 0) {
                  *(undefined4 *)puVar9 = 1;
                  goto LAB_0015a608;
                }
                *(int *)((long)puVar9 + -4) = iVar5;
              }
            }
            goto LAB_0015ac77;
          case 0xc9:
          case 0xca:
          case 0xcb:
          case 0xcc:
          case 0xce:
          case 0xcf:
          case 0xd0:
          case 0xd1:
          case 0xd2:
          case 0xd3:
          case 0xd4:
          case 0xd5:
          case 0xd6:
          case 0xd7:
          case 0xdb:
          case 0xdc:
          case 0xdd:
          case 0xde:
          case 0xeb:
          case 0xec:
          case 0xed:
          case 0xee:
          case 0xef:
          case 0xf0:
          case 0xf1:
          case 0xf2:
          case 0xf3:
          case 0xf4:
          case 0xf5:
          case 0xf6:
          case 0xf7:
          case 0xf8:
          case 0xf9:
          case 0xfa:
          case 0x121:
          case 0x122:
          case 0x123:
          case 0x124:
          case 0x125:
          case 0x126:
          case 0x127:
            iVar5 = local_54;
joined_r0x0015a4e5:
            if (iVar5 != 0) goto switchD_0015a20f_caseD_5b;
switchD_0015a20f_caseD_cd:
            uVar10 = FUN_00234e30();
            *(undefined4 *)((long)puVar9 + -4) = 3;
            puVar9[-3] = uVar10;
            break;
          case 0xcd:
          case 0xd8:
          case 0xd9:
          case 0xda:
            goto switchD_0015a20f_caseD_cd;
          case 0xe2:
            lVar7 = *(long *)(param_1 + 0x256d8);
            if ((lVar7 != 0) && (*(long *)(lVar7 + 0xb0) != 0)) {
              pcVar3 = *(code **)(*(long *)(lVar7 + 0xb0) + 8);
              goto joined_r0x0015ac2f;
            }
            break;
          case 0xe3:
            lVar7 = *(long *)(param_1 + 0x256d8);
            if ((lVar7 != 0) && (*(long *)(lVar7 + 0xb0) != 0)) {
              pcVar3 = *(code **)(*(long *)(lVar7 + 0xb0) + 0x10);
              goto joined_r0x0015ac2f;
            }
            break;
          case 0xe4:
          case 0xe5:
            lVar8 = FUN_00234e30();
            lVar7 = *(long *)(param_1 + 0x256d8);
            uVar6 = 3;
            if (((lVar7 != 0) && (*(long *)(lVar7 + 0x48) != 0)) &&
               (pcVar3 = *(code **)(*(long *)(lVar7 + 0x48) + 0xb0), pcVar3 != (code *)0x0)) {
              uVar6 = (*pcVar3)(lVar7,param_1,*(undefined4 *)(puVar9 + -4),puVar9);
            }
            goto LAB_0015a828;
          case 0xe6:
            lVar8 = FUN_00234e30();
            lVar7 = *(long *)(param_1 + 0x256d8);
            uVar6 = 3;
            if (((lVar7 != 0) && (*(long *)(lVar7 + 0xb8) != 0)) &&
               (pcVar3 = *(code **)(*(long *)(lVar7 + 0xb8) + 0x48), pcVar3 != (code *)0x0)) {
              uVar6 = (*pcVar3)(lVar7,param_1,puVar9);
            }
LAB_0015a828:
            *(undefined4 *)((long)puVar9 + -4) = uVar6;
LAB_0015a608:
            lVar7 = FUN_00234e30();
            *(undefined4 *)(puVar9 + -1) = 1;
            puVar9[-3] = lVar7;
            puVar9[-2] = lVar7 - lVar8;
            break;
          case 0xfb:
          case 0xfc:
          case 0xfd:
          case 0xfe:
          case 0xff:
          case 0x100:
          case 0x101:
          case 0x102:
          case 0x103:
          case 0x104:
          case 0x105:
          case 0x106:
          case 0x107:
          case 0x108:
          case 0x109:
          case 0x10a:
          case 0x10b:
          case 0x10c:
          case 0x113:
          case 0x114:
          case 0x115:
          case 0x116:
          case 0x117:
          case 0x118:
          case 0x119:
          case 0x11a:
          case 0x11b:
          case 0x11c:
          case 0x11d:
          case 0x11e:
          case 0x11f:
          case 0x120:
            if (local_b0 == -1) {
              local_b0 = iVar4;
            }
            local_90 = local_90 + 1;
            local_d0 = iVar4;
            break;
          case 0x10e:
          case 0x10f:
            if (local_a8 == -1) {
              local_a8 = iVar4;
            }
            local_84 = local_84 + 1;
            local_c8 = iVar4;
            break;
          case 0x110:
          case 0x111:
            if (local_ac == -1) {
              local_ac = iVar4;
            }
            local_88 = local_88 + 1;
            local_cc = iVar4;
            break;
          case 0x112:
            lVar8 = FUN_00234e30();
            lVar7 = *(long *)(param_1 + 0x256d8);
            uVar6 = 3;
            if (((lVar7 != 0) && (*(long *)(lVar7 + 0x160) != 0)) &&
               (pcVar3 = *(code **)(*(long *)(lVar7 + 0x160) + 0x148), pcVar3 != (code *)0x0)) {
              uVar6 = (*pcVar3)(lVar7,param_1,puVar9);
            }
            *(undefined4 *)((long)puVar9 + -4) = uVar6;
            lVar7 = FUN_00234e30();
            *(undefined4 *)(puVar9 + -1) = 0;
            puVar9[-3] = lVar7;
            puVar9[-2] = lVar7 - lVar8;
          }
          goto LAB_0015a230;
        }
        if (DAT_01216a78 < 2) {
          return iVar4;
        }
        fVar11 = (float)FUN_002917b0(&DAT_01216a60);
        lVar7 = syscall(0xba);
        fVar11 = fVar11 * DAT_00298548;
        uVar12 = 0x22cf;
        uVar10 = 0x22cf;
      }
      else {
        if (DAT_01216a78 < 2) {
          return iVar4;
        }
        fVar11 = (float)FUN_002917b0(&DAT_01216a60);
        lVar7 = syscall(0xba);
        fVar11 = fVar11 * DAT_00298548;
        uVar12 = 0x22cd;
        uVar10 = 0x22cd;
      }
      FUN_002340f0((double)fVar11,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar7,
                   "api.c",uVar10,"tsapiDeviceGetFieldValues",uVar12,iVar4);
      return iVar4;
    }
  }
  return 2;
switchD_0015a20f_caseD_5b:
  if (local_64 == -1) {
    local_64 = iVar4;
  }
  local_68 = local_68 + 1;
  local_6c = iVar4;
LAB_0015a230:
  iVar4 = iVar4 + 1;
  puVar9 = puVar9 + 5;
  if (param_2 <= iVar4) goto code_r0x0015a23d;
  goto LAB_0015a1f0;
code_r0x0015a23d:
  if (local_70 == 0) {
LAB_0015a28b:
    if ((local_68 == 0) || (lVar7 = *(long *)(param_1 + 0x256d8), lVar7 == 0)) goto LAB_0015a2cc;
LAB_0015a29f:
    if ((*(long *)(lVar7 + 0x158) != 0) &&
       (pcVar3 = *(code **)(*(long *)(lVar7 + 0x158) + 0x58), pcVar3 != (code *)0x0)) {
      (*pcVar3)(lVar7,param_1,param_3,local_64,local_6c);
      goto LAB_0015a2cc;
    }
    if (local_78 != 0) goto LAB_0015a2e4;
LAB_0015a317:
    if (local_74 != 0) {
      lVar7 = *(long *)(param_1 + 0x256d8);
      if (lVar7 == 0) {
        return 3;
      }
LAB_0015a641:
      if ((*(undefined8 **)(lVar7 + 0x110) != (undefined8 *)0x0) &&
         (pcVar3 = (code *)**(undefined8 **)(lVar7 + 0x110), pcVar3 != (code *)0x0)) {
        iVar4 = (*pcVar3)(lVar7,param_1,param_3,local_9c,local_bc);
        return iVar4;
      }
      return 3;
    }
  }
  else {
    lVar7 = *(long *)(param_1 + 0x256d8);
    if (lVar7 != 0) {
      if ((*(long *)(lVar7 + 0x140) != 0) &&
         (pcVar3 = *(code **)(*(long *)(lVar7 + 0x140) + 0xb8), pcVar3 != (code *)0x0)) {
        (*pcVar3)(lVar7,param_1,param_3,local_94,local_b4);
        goto LAB_0015a28b;
      }
      if (local_68 == 0) goto LAB_0015a2cc;
      goto LAB_0015a29f;
    }
LAB_0015a2cc:
    if (local_78 == 0) goto LAB_0015a317;
    lVar7 = *(long *)(param_1 + 0x256d8);
    if (lVar7 == 0) {
      if (local_74 != 0) {
        return 3;
      }
    }
    else {
LAB_0015a2e4:
      if ((*(long *)(lVar7 + 0x148) != 0) &&
         (pcVar3 = *(code **)(*(long *)(lVar7 + 0x148) + 0x18), pcVar3 != (code *)0x0)) {
        (*pcVar3)(lVar7,param_1,param_3,local_98,local_b8);
        goto LAB_0015a317;
      }
      if (local_74 != 0) goto LAB_0015a641;
    }
  }
  if (local_80 == 0) {
LAB_0015a370:
    if ((local_8c == 0) || (lVar7 = *(long *)(param_1 + 0x256d8), lVar7 == 0)) goto LAB_0015a3bd;
LAB_0015a387:
    if ((*(long *)(lVar7 + 0x118) != 0) &&
       (pcVar3 = *(code **)(*(long *)(lVar7 + 0x118) + 0xb8), pcVar3 != (code *)0x0)) {
      (*pcVar3)(lVar7,param_1,param_3,local_a4,local_c4);
      goto LAB_0015a3bd;
    }
    if (local_84 != 0) goto LAB_0015a3d3;
LAB_0015a406:
    if (local_88 != 0) {
      lVar7 = *(long *)(param_1 + 0x256d8);
      if (lVar7 == 0) {
        return 0;
      }
LAB_0015a420:
      if ((*(long *)(lVar7 + 0x160) == 0) ||
         (pcVar3 = *(code **)(*(long *)(lVar7 + 0x160) + 0x140), pcVar3 == (code *)0x0)) {
        if (local_90 == 0) {
          return 0;
        }
        goto LAB_0015a475;
      }
      (*pcVar3)(lVar7,param_1,param_3,local_ac,local_cc);
    }
  }
  else {
    lVar7 = *(long *)(param_1 + 0x256d8);
    if (lVar7 != 0) {
      if ((*(long *)(lVar7 + 0x160) != 0) &&
         (pcVar3 = *(code **)(*(long *)(lVar7 + 0x160) + 0xf0), pcVar3 != (code *)0x0)) {
        (*pcVar3)(lVar7,param_1,param_3,local_a0,local_c0);
        goto LAB_0015a370;
      }
      if (local_8c == 0) goto LAB_0015a3bd;
      goto LAB_0015a387;
    }
LAB_0015a3bd:
    if ((local_84 == 0) || (lVar7 = *(long *)(param_1 + 0x256d8), lVar7 == 0)) goto LAB_0015a406;
LAB_0015a3d3:
    if ((*(long *)(lVar7 + 0x148) != 0) &&
       (pcVar3 = *(code **)(*(long *)(lVar7 + 0x148) + 0x30), pcVar3 != (code *)0x0)) {
      (*pcVar3)(lVar7,param_1,param_3,local_a8,local_c8);
      goto LAB_0015a406;
    }
    if (local_88 != 0) goto LAB_0015a420;
  }
  if (local_90 == 0) {
    return 0;
  }
  lVar7 = *(long *)(param_1 + 0x256d8);
  if (lVar7 == 0) {
    return 0;
  }
LAB_0015a475:
  if ((*(long *)(lVar7 + 0x160) != 0) &&
     (pcVar3 = *(code **)(*(long *)(lVar7 + 0x160) + 0xf8), pcVar3 != (code *)0x0)) {
    (*pcVar3)(lVar7,param_1,param_3,local_b0,local_d0);
  }
  return 0;
}


// ===== 0015adc0 nvmlDeviceGetFieldValues =====

int nvmlDeviceGetFieldValues(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x460,"nvmlDeviceGetFieldValues",
                 "(nvmlDevice_t device, int valuesCount, nvmlFieldValue_t *values)",param_1,param_2,
                 param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00159f90(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x460,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x460,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0015af90 FUN_0015af90 =====

undefined8 FUN_0015af90(long param_1,int param_2,uint *param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  float fVar6;
  
  if (param_2 < 1) {
    return 0;
  }
  iVar5 = 0;
  do {
    while (uVar2 = *param_3, uVar2 == 0xa9) {
LAB_0015b074:
      lVar3 = FUN_00234e30();
      lVar4 = *(long *)(param_1 + 0x256d8);
      uVar2 = 3;
      if (((lVar4 != 0) && (*(long *)(lVar4 + 0x48) != 0)) &&
         (pcVar1 = *(code **)(*(long *)(lVar4 + 0x48) + 0x88), pcVar1 != (code *)0x0)) {
        uVar2 = (*pcVar1)(lVar4,param_1,*param_3);
      }
      param_3[7] = uVar2;
      iVar5 = iVar5 + 1;
      lVar4 = FUN_00234e30();
      param_3[6] = 1;
      *(long *)(param_3 + 2) = lVar4;
      *(long *)(param_3 + 4) = lVar4 - lVar3;
      param_3 = param_3 + 10;
      if (param_2 == iVar5) {
        return 0;
      }
    }
    if (uVar2 < 0xaa) {
      if (1 < uVar2 - 0x5e) goto LAB_0015afce;
      goto LAB_0015b074;
    }
    if (uVar2 - 0xad < 0xb) goto LAB_0015b074;
LAB_0015afce:
    param_3[7] = 2;
    if (1 < DAT_01216a78) {
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %d %d\n",
                   "ERROR",lVar4,"api.c",0x25f0,uVar2,iVar5,param_2);
    }
    iVar5 = iVar5 + 1;
    param_3 = param_3 + 10;
    if (param_2 == iVar5) {
      return 0;
    }
  } while( true );
}


// ===== 0015b100 nvmlDeviceClearFieldValues =====

int nvmlDeviceClearFieldValues(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x465,"nvmlDeviceClearFieldValues",
                 "(nvmlDevice_t device, int valuesCount, nvmlFieldValue_t *values)",param_1,param_2,
                 param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015af90(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x465,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x465,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0015b2d0 FUN_0015b2d0 =====

undefined8 FUN_0015b2d0(long param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  int *piVar4;
  code *pcVar5;
  int iVar6;
  float fVar7;
  
  if (param_2 < 1 || param_3 == (int *)0x0) {
    return 2;
  }
  if (param_1 == 0) {
    return 2;
  }
  iVar6 = 0;
  piVar4 = param_3;
  do {
    iVar2 = *piVar4;
    iVar1 = iVar2 + 0x4000;
    *piVar4 = iVar1;
    if (iVar1 == 0x4002) {
      lVar3 = *(long *)(param_1 + 0x256d8);
      iVar2 = 2;
      if (((lVar3 == 0) || (*(long *)(lVar3 + 0x158) == 0)) ||
         (pcVar5 = *(code **)(*(long *)(lVar3 + 0x158) + 0x58), pcVar5 == (code *)0x0))
      goto LAB_0015b3a0;
LAB_0015b3f7:
      (*pcVar5)(lVar3,param_1,param_3,iVar6,iVar6);
      *piVar4 = *piVar4 + -0x4000;
    }
    else {
      if (iVar1 == 0x4003) {
        lVar3 = *(long *)(param_1 + 0x256d8);
        iVar2 = 3;
        if (((lVar3 != 0) && (*(long *)(lVar3 + 0x158) != 0)) &&
           (pcVar5 = *(code **)(*(long *)(lVar3 + 0x158) + 0x50), pcVar5 != (code *)0x0))
        goto LAB_0015b3f7;
      }
      else {
        piVar4[7] = 2;
        if (1 < DAT_01216a78) {
          fVar7 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar7 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %d %d\n","ERROR",lVar3,"api.c",0x2618,
                       iVar1,iVar6,param_2);
          iVar2 = *piVar4 + -0x4000;
        }
      }
LAB_0015b3a0:
      *piVar4 = iVar2;
    }
    iVar6 = iVar6 + 1;
    piVar4 = piVar4 + 10;
    if (param_2 <= iVar6) {
      return 0;
    }
  } while( true );
}


// ===== 0015b4a0 FUN_0015b4a0 =====

int FUN_0015b4a0(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x98d,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015b2d0(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x98d,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0015b5e0 FUN_0015b5e0 =====

int FUN_0015b5e0(int param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  ulong uVar5;
  uint uVar6;
  uint uVar7;
  float fVar8;
  char local_3d;
  int local_3c [3];
  
  local_3c[0] = 0;
  if (param_2 == (undefined4 *)0x0) {
LAB_0015b7f0:
    iVar2 = 2;
  }
  else {
    uVar7 = 0xffffffff;
    uVar5 = 0;
    pcVar4 = &DAT_00380898;
    if (DAT_01214898 != 0) {
      do {
        if ((*pcVar4 == '\x01') ||
           (((((&DAT_003808ac)[uVar5 * 0x1d280] != 0 && (*(int *)(pcVar4 + 0x1c) == 0)) &&
             (*(int *)(pcVar4 + 0x10) != 0)) && (*(long *)(pcVar4 + 0x20) != 0)))) {
          if (uVar7 == 0xffffffff) {
            uVar7 = (uint)uVar5;
          }
          iVar2 = FUN_00156380(pcVar4,local_3c);
          if (iVar2 != 0) {
            return iVar2;
          }
          if (local_3c[0] == 0) {
            return 3;
          }
        }
        uVar6 = (uint)uVar5 + 1;
        uVar5 = (ulong)uVar6;
        pcVar4 = pcVar4 + 0x74a00;
      } while (uVar6 < DAT_01214898);
      if (uVar7 != 0xffffffff) {
        uVar5 = (ulong)uVar7;
        local_3d = '\0';
        lVar3 = (&DAT_003a5f70)[uVar5 * 0xe940];
        if (((lVar3 == 0) || (*(long *)(lVar3 + 0x38) == 0)) ||
           ((pcVar1 = *(code **)(*(long *)(lVar3 + 0x38) + 0x80), pcVar1 == (code *)0x0 ||
            ((*pcVar1)(lVar3,&DAT_00380898 + uVar5 * 0x74a00,&local_3d), local_3d == '\0')))) {
          return 3;
        }
        if (DAT_012148c8 == 0) {
          do {
            iVar2 = FUN_00291820(&DAT_012148cc,1,0);
          } while (iVar2 != 0);
          if (DAT_012148c8 == 0) {
            iVar2 = 3;
            lVar3 = (&DAT_003a5f70)[uVar5 * 0xe940];
            if (((lVar3 != 0) && (*(undefined8 **)(lVar3 + 0x28) != (undefined8 *)0x0)) &&
               (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x28), pcVar1 != (code *)0x0)) {
              iVar2 = (*pcVar1)(lVar3,&DAT_00380898 + uVar5 * 0x74a00,&DAT_012148c0);
            }
            DAT_012148c8 = 1;
            DAT_012148d0 = iVar2;
          }
          FUN_00291830(&DAT_012148cc,0);
        }
        iVar2 = DAT_012148d0;
        if (DAT_012148d0 != 0) {
          if (1 < DAT_01216a78) {
            fVar8 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            FUN_002340f0((double)(fVar8 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,"api.c",
                         0x2663,"tsapiGetVgpuDriverCapabilities",0x2663,iVar2);
            return iVar2;
          }
          return DAT_012148d0;
        }
        if (param_1 == 0) {
          *param_2 = DAT_012148c0;
          return 0;
        }
        if (param_1 == 1) {
          *param_2 = DAT_012148c4;
          return 0;
        }
        goto LAB_0015b7f0;
      }
    }
    iVar2 = 999;
  }
  return iVar2;
}


// ===== 0015b8a0 nvmlGetVgpuDriverCapabilities =====

int nvmlGetVgpuDriverCapabilities(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x31d,"nvmlGetVgpuDriverCapabilities",
                 "(nvmlVgpuDriverCapability_t capability, unsigned int *capResult)",param_1,param_2)
    ;
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015b5e0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x31d,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x31d,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0015ba80 FUN_0015ba80 =====

undefined8 FUN_0015ba80(long param_1,undefined4 param_2,undefined8 param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x28) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x28) + 0x18),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0015baa9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
    return uVar2;
  }
  return 3;
}


// ===== 0015bac0 nvmlDeviceGetVgpuCapabilities =====

int nvmlDeviceGetVgpuCapabilities(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x322,"nvmlDeviceGetVgpuCapabilities",
                 "(nvmlDevice_t device, nvmlDeviceVgpuCapability_t capability, unsigned int *capResult)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015ba80(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x322,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x322,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0015bc90 FUN_0015bc90 =====

undefined8 FUN_0015bc90(long param_1)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x28) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x28) + 0x10),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0015bcb1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1);
    return uVar2;
  }
  return 3;
}


// ===== 0015bcc0 nvmlDeviceVgpuForceGspUnload =====

int nvmlDeviceVgpuForceGspUnload(char *param_1)

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
                 "entry_points.h",0x32c,"nvmlDeviceVgpuForceGspUnload");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_0015bc90(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x32c,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x32c,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0015be90 FUN_0015be90 =====

undefined1  [16] FUN_0015be90(int param_1,char *param_2,uint *param_3)

{
  code *pcVar1;
  undefined1 auVar2 [16];
  uint *puVar3;
  uint uVar4;
  long lVar5;
  uint *extraout_RDX;
  uint *extraout_RDX_00;
  ulong extraout_RDX_01;
  undefined8 uVar6;
  ulong uVar7;
  float fVar8;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined8 uVar12;
  long local_30;
  
  local_30 = 0;
  if ((param_3 == (uint *)0x0) || (param_1 == 0)) {
LAB_0015bfb8:
    auVar10._8_8_ = param_3;
    auVar10._0_8_ = 2;
    return auVar10;
  }
  if (*param_3 != 0) {
    if (param_2 == (char *)0x0) goto LAB_0015bfb8;
    if (0x3f < *param_3) {
      if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x28) == 0)) ||
         (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0xb8), pcVar1 == (code *)0x0)) {
        uVar7 = 3;
        puVar3 = param_3;
      }
      else {
        uVar4 = (*pcVar1)(DAT_012164a0,param_1,&local_30);
        uVar7 = (ulong)uVar4;
        puVar3 = extraout_RDX;
        if (uVar4 == 0) {
          uVar4 = FUN_00138f40(param_1,local_30);
          uVar7 = (ulong)uVar4;
          if (uVar4 == 0) {
            *param_3 = 0x40;
            strncpy(param_2,(char *)(local_30 + 0x50),0x40);
            auVar2._8_8_ = 0;
            auVar2._0_8_ = extraout_RDX_01;
            return auVar2 << 0x40;
          }
          param_3 = extraout_RDX_00;
          if (DAT_01216a78 < 2) goto LAB_0015bfa4;
          fVar8 = (float)FUN_002917b0(&DAT_01216a60);
          lVar5 = syscall(0xba);
          fVar8 = fVar8 * DAT_00298548;
          uVar12 = 0x275c;
          uVar6 = 0x275c;
          goto LAB_0015c027;
        }
      }
      param_3 = puVar3;
      if (1 < DAT_01216a78) {
        fVar8 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        fVar8 = fVar8 * DAT_00298548;
        uVar12 = 0x2759;
        uVar6 = 0x2759;
LAB_0015c027:
        FUN_002340f0((double)fVar8,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,
                     "api.c",uVar6,"tsapiVgpuTypeGetClass",uVar12);
        auVar11._8_8_ = uVar7;
        auVar11._0_8_ = uVar7;
        return auVar11;
      }
      goto LAB_0015bfa4;
    }
  }
  *param_3 = 0x40;
  uVar7 = 7;
LAB_0015bfa4:
  auVar9._8_8_ = param_3;
  auVar9._0_8_ = uVar7;
  return auVar9;
}


// ===== 0015c090 nvmlVgpuTypeGetClass =====

int nvmlVgpuTypeGetClass(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x33b,"nvmlVgpuTypeGetClass",
                 "(nvmlVgpuTypeId_t vgpuTypeId, char *vgpuTypeClass, unsigned int *size)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015be90(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x33b,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x33b,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0015c260 FUN_0015c260 =====

undefined1  [16] FUN_0015c260(int param_1,char *param_2,uint *param_3)

{
  code *pcVar1;
  undefined1 auVar2 [16];
  uint *puVar3;
  uint uVar4;
  long lVar5;
  uint *extraout_RDX;
  uint *extraout_RDX_00;
  ulong extraout_RDX_01;
  undefined8 uVar6;
  ulong uVar7;
  float fVar8;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined8 uVar12;
  long local_30;
  
  local_30 = 0;
  if ((param_3 == (uint *)0x0) || (param_1 == 0)) {
LAB_0015c388:
    auVar10._8_8_ = param_3;
    auVar10._0_8_ = 2;
    return auVar10;
  }
  if (*param_3 != 0) {
    if (param_2 == (char *)0x0) goto LAB_0015c388;
    if (0x3f < *param_3) {
      if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x28) == 0)) ||
         (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0xb8), pcVar1 == (code *)0x0)) {
        uVar7 = 3;
        puVar3 = param_3;
      }
      else {
        uVar4 = (*pcVar1)(DAT_012164a0,param_1,&local_30);
        uVar7 = (ulong)uVar4;
        puVar3 = extraout_RDX;
        if (uVar4 == 0) {
          uVar4 = FUN_00138f40(param_1,local_30);
          uVar7 = (ulong)uVar4;
          if (uVar4 == 0) {
            *param_3 = 0x40;
            strncpy(param_2,(char *)(local_30 + 0x10),0x40);
            auVar2._8_8_ = 0;
            auVar2._0_8_ = extraout_RDX_01;
            return auVar2 << 0x40;
          }
          param_3 = extraout_RDX_00;
          if (DAT_01216a78 < 2) goto LAB_0015c374;
          fVar8 = (float)FUN_002917b0(&DAT_01216a60);
          lVar5 = syscall(0xba);
          fVar8 = fVar8 * DAT_00298548;
          uVar12 = 0x2783;
          uVar6 = 0x2783;
          goto LAB_0015c3f7;
        }
      }
      param_3 = puVar3;
      if (1 < DAT_01216a78) {
        fVar8 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        fVar8 = fVar8 * DAT_00298548;
        uVar12 = 0x2780;
        uVar6 = 0x2780;
LAB_0015c3f7:
        FUN_002340f0((double)fVar8,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,
                     "api.c",uVar6,"tsapiVgpuTypeGetName",uVar12);
        auVar11._8_8_ = uVar7;
        auVar11._0_8_ = uVar7;
        return auVar11;
      }
      goto LAB_0015c374;
    }
  }
  *param_3 = 0x40;
  uVar7 = 7;
LAB_0015c374:
  auVar9._8_8_ = param_3;
  auVar9._0_8_ = uVar7;
  return auVar9;
}


// ===== 0015c460 nvmlVgpuTypeGetName =====

int nvmlVgpuTypeGetName(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x340,"nvmlVgpuTypeGetName",
                 "(nvmlVgpuTypeId_t vgpuTypeId, char *vgpuTypeName, unsigned int *size)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015c260(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x340,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x340,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0015c630 FUN_0015c630 =====

int FUN_0015c630(int param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  long local_30 [2];
  
  local_30[0] = 0;
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    return 2;
  }
  if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x28) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0xb8), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(DAT_012164a0,param_1,local_30);
    if (iVar2 == 0) {
      iVar2 = FUN_00138f40(param_1,local_30[0]);
      if (iVar2 == 0) {
        *param_2 = *(undefined4 *)(local_30[0] + 0x110);
        return 0;
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0x279b;
      uVar4 = 0x279b;
      goto LAB_0015c71f;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  fVar5 = fVar5 * DAT_00298548;
  uVar6 = 0x2798;
  uVar4 = 0x2798;
LAB_0015c71f:
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,"api.c",
               uVar4,"tsapiVgpuTypeGetGpuInstanceProfileId",uVar6,iVar2);
  return iVar2;
}


// ===== 0015c7d0 nvmlVgpuTypeGetGpuInstanceProfileId =====

int nvmlVgpuTypeGetGpuInstanceProfileId(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x345,"nvmlVgpuTypeGetGpuInstanceProfileId",
                 "(nvmlVgpuTypeId_t vgpuTypeId, unsigned int *gpuInstanceProfileId)",param_1,param_2
                );
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015c630(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x345,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x345,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0015c9b0 FUN_0015c9b0 =====

int FUN_0015c9b0(int param_1,ulong *param_2,ulong *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  long local_30;
  
  local_30 = 0;
  if ((param_2 == (ulong *)0x0 || param_3 == (ulong *)0x0) || (param_1 == 0)) {
    return 2;
  }
  if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x28) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0xb8), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(DAT_012164a0,param_1,&local_30);
    if (iVar2 == 0) {
      iVar2 = FUN_00138f40(param_1,local_30);
      if (iVar2 == 0) {
        *param_2 = (*(ulong *)(local_30 + 0x138) & 0xffff) << 0x10 | 0x10de;
        *param_3 = (*(ulong *)(local_30 + 0x130) & 0xffff) << 0x10 |
                   (ulong)*(uint *)(local_30 + 0x114);
        return 0;
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0x27b8;
      uVar4 = 0x27b8;
      goto LAB_0015cadf;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  fVar5 = fVar5 * DAT_00298548;
  uVar6 = 0x27b5;
  uVar4 = 0x27b5;
LAB_0015cadf:
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,"api.c",
               uVar4,"tsapiVgpuTypeGetDeviceID",uVar6,iVar2);
  return iVar2;
}


// ===== 0015cb90 nvmlVgpuTypeGetDeviceID =====

int nvmlVgpuTypeGetDeviceID(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x34a,"nvmlVgpuTypeGetDeviceID",
                 "(nvmlVgpuTypeId_t vgpuTypeId, unsigned long long *deviceID, unsigned long long *subsystemID)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015c9b0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x34a,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x34a,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0015cd60 FUN_0015cd60 =====

int FUN_0015cd60(int param_1,undefined8 *param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  long local_30 [2];
  
  local_30[0] = 0;
  if ((param_2 == (undefined8 *)0x0) || (param_1 == 0)) {
    return 2;
  }
  if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x28) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0xb8), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(DAT_012164a0,param_1,local_30);
    if (iVar2 == 0) {
      iVar2 = FUN_00138f40(param_1,local_30[0]);
      if (iVar2 == 0) {
        *param_2 = *(undefined8 *)(local_30[0] + 0x140);
        return 0;
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0x27d4;
      uVar4 = 0x27d4;
      goto LAB_0015ce57;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  fVar5 = fVar5 * DAT_00298548;
  uVar6 = 0x27d1;
  uVar4 = 0x27d1;
LAB_0015ce57:
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,"api.c",
               uVar4,"tsapiVgpuTypeGetFramebufferSize",uVar6,iVar2);
  return iVar2;
}


// ===== 0015cf10 nvmlVgpuTypeGetFramebufferSize =====

int nvmlVgpuTypeGetFramebufferSize(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x34f,"nvmlVgpuTypeGetFramebufferSize",
                 "(nvmlVgpuTypeId_t vgpuTypeId, unsigned long long *fbSize)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015cd60(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x34f,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x34f,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0015d0f0 FUN_0015d0f0 =====

int FUN_0015d0f0(int param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  long local_30 [2];
  
  local_30[0] = 0;
  if ((param_2 == (undefined4 *)0x0) || (param_1 == 0)) {
    return 2;
  }
  if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x28) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0xb8), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(DAT_012164a0,param_1,local_30);
    if (iVar2 == 0) {
      iVar2 = FUN_00138f40(param_1,local_30[0]);
      if (iVar2 == 0) {
        *param_2 = *(undefined4 *)(local_30[0] + 0x11c);
        return 0;
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0x27ef;
      uVar4 = 0x27ef;
      goto LAB_0015d1df;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  fVar5 = fVar5 * DAT_00298548;
  uVar6 = 0x27ec;
  uVar4 = 0x27ec;
LAB_0015d1df:
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,"api.c",
               uVar4,"tsapiVgpuTypeGetNumDisplayHeads",uVar6,iVar2);
  return iVar2;
}


// ===== 0015d290 nvmlVgpuTypeGetNumDisplayHeads =====

int nvmlVgpuTypeGetNumDisplayHeads(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x354,"nvmlVgpuTypeGetNumDisplayHeads",
                 "(nvmlVgpuTypeId_t vgpuTypeId, unsigned int *numDisplayHeads)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015d0f0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x354,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x354,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0015d470 FUN_0015d470 =====

int FUN_0015d470(int param_1,uint param_2,undefined4 *param_3,undefined4 *param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  long local_40 [2];
  
  local_40[0] = 0;
  if ((param_3 == (undefined4 *)0x0 || param_4 == (undefined4 *)0x0) || (param_1 == 0)) {
    return 2;
  }
  if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x28) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0xb8), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(DAT_012164a0,param_1,local_40);
    if (iVar2 == 0) {
      iVar2 = FUN_00138f40(param_1,local_40[0]);
      if (iVar2 == 0) {
        if (*(uint *)(local_40[0] + 0x11c) <= param_2) {
          return 2;
        }
        *param_3 = *(undefined4 *)(local_40[0] + 0x120);
        *param_4 = *(undefined4 *)(local_40[0] + 0x124);
        return 0;
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0x280d;
      uVar4 = 0x280d;
      goto LAB_0015d58f;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  fVar5 = fVar5 * DAT_00298548;
  uVar6 = 0x280a;
  uVar4 = 0x280a;
LAB_0015d58f:
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,"api.c",
               uVar4,"tsapiVgpuTypeGetResolution",uVar6,iVar2);
  return iVar2;
}


// ===== 0015d630 nvmlVgpuTypeGetResolution =====

int nvmlVgpuTypeGetResolution
              (undefined4 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %d %p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x359,"nvmlVgpuTypeGetResolution",
                 "(nvmlVgpuTypeId_t vgpuTypeId, unsigned int displayIndex, unsigned int *xdim, unsigned int *ydim)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015d470(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x359,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x359,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0015d820 FUN_0015d820 =====

int FUN_0015d820(int param_1,char *param_2,uint param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  long local_30 [2];
  
  local_30[0] = 0;
  if ((param_2 == (char *)0x0) || (param_1 == 0)) {
    return 2;
  }
  iVar2 = 7;
  if (0x7f < param_3) {
    if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x28) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0xb8), pcVar1 == (code *)0x0)) {
      iVar2 = 3;
    }
    else {
      iVar2 = (*pcVar1)(DAT_012164a0,param_1,local_30);
      if (iVar2 == 0) {
        iVar2 = FUN_00138f40(param_1,local_30[0]);
        if (iVar2 == 0) {
          strncpy(param_2,(char *)(local_30[0] + 0x90),0x80);
          return 0;
        }
        if (DAT_01216a78 < 2) {
          return iVar2;
        }
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        fVar5 = fVar5 * DAT_00298548;
        uVar6 = 0x282f;
        uVar4 = 0x282f;
        goto LAB_0015d93f;
      }
    }
    if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0x282c;
      uVar4 = 0x282c;
LAB_0015d93f:
      FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
                   "api.c",uVar4,"tsapiVgpuTypeGetLicense",uVar6,iVar2);
      return iVar2;
    }
  }
  return iVar2;
}


// ===== 0015d9f0 nvmlVgpuTypeGetLicense =====

int nvmlVgpuTypeGetLicense(undefined4 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x35e,"nvmlVgpuTypeGetLicense",
                 "(nvmlVgpuTypeId_t vgpuTypeId, char *vgpuTypeLicenseString, unsigned int size)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015d820(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x35e,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x35e,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0015dbc0 FUN_0015dbc0 =====

int FUN_0015dbc0(int param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  long local_30 [2];
  
  local_30[0] = 0;
  if ((param_2 == (undefined4 *)0x0) || (param_1 == 0)) {
    return 2;
  }
  if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x28) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0xb8), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(DAT_012164a0,param_1,local_30);
    if (iVar2 == 0) {
      iVar2 = FUN_00138f40(param_1,local_30[0]);
      if (iVar2 == 0) {
        if (*(int *)(local_30[0] + 0x128) != 0) {
          *param_2 = *(undefined4 *)(local_30[0] + 300);
          return 0;
        }
        return 3;
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0x2846;
      uVar4 = 0x2846;
      goto LAB_0015dcbf;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  fVar5 = fVar5 * DAT_00298548;
  uVar6 = 0x2843;
  uVar4 = 0x2843;
LAB_0015dcbf:
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,"api.c",
               uVar4,"tsapiVgpuTypeGetFrameRateLimit",uVar6,iVar2);
  return iVar2;
}


// ===== 0015dd80 nvmlVgpuTypeGetFrameRateLimit =====

int nvmlVgpuTypeGetFrameRateLimit(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x363,"nvmlVgpuTypeGetFrameRateLimit",
                 "(nvmlVgpuTypeId_t vgpuTypeId, unsigned int *frameRateLimit)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015dbc0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x363,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x363,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0015df60 FUN_0015df60 =====

int FUN_0015df60(int param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  long local_30 [2];
  
  local_30[0] = 0;
  if ((param_2 == (int *)0x0) || (param_1 == 0)) {
    return 2;
  }
  if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x28) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0xb8), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(DAT_012164a0,param_1,local_30);
    if (iVar2 == 0) {
      iVar2 = FUN_00138f40(param_1,local_30[0]);
      if (iVar2 == 0) {
        *param_2 = (-(uint)(*(int *)(local_30[0] + 0x148) == 0) & 0xfffffff1) + 0x10;
        return 0;
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0x288f;
      uVar4 = 0x288f;
      goto LAB_0015e057;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  fVar5 = fVar5 * DAT_00298548;
  uVar6 = 0x288c;
  uVar4 = 0x288c;
LAB_0015e057:
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,"api.c",
               uVar4,"tsapiVgpuTypeGetMaxInstancesPerVm",uVar6,iVar2);
  return iVar2;
}


// ===== 0015e110 nvmlVgpuTypeGetMaxInstancesPerVm =====

int nvmlVgpuTypeGetMaxInstancesPerVm(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x37c,"nvmlVgpuTypeGetMaxInstancesPerVm",
                 "(nvmlVgpuTypeId_t vgpuTypeId, unsigned int *vgpuInstanceCountPerVm)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015df60(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x37c,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x37c,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0015e2f0 FUN_0015e2f0 =====

int FUN_0015e2f0(int param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  long local_30 [2];
  
  local_30[0] = 0;
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    return 2;
  }
  iVar2 = 0x19;
  if (*param_2 == 0x1000010) {
    if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x28) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0xb8), pcVar1 == (code *)0x0)) {
      iVar2 = 3;
    }
    else {
      iVar2 = (*pcVar1)(DAT_012164a0,param_1,local_30);
      if (iVar2 == 0) {
        iVar2 = FUN_00138f40(param_1,local_30[0]);
        if (iVar2 == 0) {
          *(undefined8 *)(param_2 + 2) = *(undefined8 *)(local_30[0] + 0x300);
          return 0;
        }
        if (DAT_01216a78 < 2) {
          return iVar2;
        }
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        fVar5 = fVar5 * DAT_00298548;
        uVar6 = 0x28ac;
        uVar4 = 0x28ac;
        goto LAB_0015e423;
      }
    }
    if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0x28aa;
      uVar4 = 0x28aa;
LAB_0015e423:
      FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
                   "api.c",uVar4,"tsapiVgpuTypeGetBAR1Info",uVar6,iVar2);
      return iVar2;
    }
  }
  return iVar2;
}


// ===== 0015e4c0 nvmlVgpuTypeGetBAR1Info =====

int nvmlVgpuTypeGetBAR1Info(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x381,"nvmlVgpuTypeGetBAR1Info",
                 "(nvmlVgpuTypeId_t vgpuTypeId, nvmlVgpuTypeBar1Info_t *bar1Info)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015e2f0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x381,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x381,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0015e6a0 FUN_0015e6a0 =====

int FUN_0015e6a0(undefined8 param_1,char *param_2,uint param_3,int *param_4)

{
  int iVar1;
  long local_30;
  
  iVar1 = 7;
  local_30 = 0;
  if (0x4f < param_3) {
    if ((param_4 == (int *)0x0 || (int)param_1 == 0) || (param_2 == (char *)0x0)) {
      return 2;
    }
    iVar1 = FUN_001390b0(param_1,&local_30);
    if (iVar1 == 0) {
      iVar1 = *(int *)(local_30 + 0x10);
      *param_4 = iVar1;
      if (iVar1 == 0) {
        snprintf(param_2,(ulong)param_3,"%llu",*(undefined8 *)(local_30 + 0x1e8));
        iVar1 = 0;
      }
      else {
        if (iVar1 != 1) {
          return 2;
        }
        iVar1 = FUN_00138ad0(local_30 + 0x1e8,param_2,(ulong)param_3);
      }
    }
  }
  return iVar1;
}


// ===== 0015e770 nvmlVgpuInstanceGetVmID =====

int nvmlVgpuInstanceGetVmID
              (undefined4 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p %d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x38b,"nvmlVgpuInstanceGetVmID",
                 "(nvmlVgpuInstance_t vgpuInstance, char *vmId, unsigned int size, nvmlVgpuVmIdType_t *vmIdType)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015e6a0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x38b,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x38b,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0015e960 FUN_0015e960 =====

undefined8 FUN_0015e960(undefined8 param_1,long param_2,undefined4 param_3)

{
  undefined8 uVar1;
  long local_20;
  
  local_20 = 0;
  if (((int)param_1 != 0) && (param_2 != 0)) {
    uVar1 = FUN_001390b0(param_1,&local_20);
    if ((int)uVar1 != 0) {
      return uVar1;
    }
    uVar1 = FUN_00138ad0(local_20 + 0xb0,param_2,param_3);
    return uVar1;
  }
  return 2;
}


// ===== 0015e9d0 nvmlVgpuInstanceGetUUID =====

int nvmlVgpuInstanceGetUUID(undefined4 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x390,"nvmlVgpuInstanceGetUUID",
                 "(nvmlVgpuInstance_t vgpuInstance, char *uuid, unsigned int size)",param_1,param_2,
                 param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015e960(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x390,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x390,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0015eba0 FUN_0015eba0 =====

int FUN_0015eba0(undefined8 param_1,long param_2,undefined4 param_3)

{
  int iVar1;
  long local_40;
  undefined1 local_38 [16];
  
  local_40 = 0;
  local_38 = (undefined1  [16])0x0;
  if (((int)param_1 != 0) && (param_2 != 0)) {
    iVar1 = FUN_001390b0(param_1,&local_40);
    if (iVar1 == 0) {
      if (*(long *)(local_40 + 0x108) != local_38._8_8_ ||
          *(long *)(local_40 + 0x100) != local_38._0_8_) {
        FUN_00138ad0(local_40 + 0x100,param_2,param_3);
        return 0;
      }
      iVar1 = 3;
    }
    return iVar1;
  }
  return 2;
}


// ===== 0015ec50 nvmlVgpuInstanceGetMdevUUID =====

int nvmlVgpuInstanceGetMdevUUID(undefined4 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x395,"nvmlVgpuInstanceGetMdevUUID",
                 "(nvmlVgpuInstance_t vgpuInstance, char *mdevUuid, unsigned int size)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015eba0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x395,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x395,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0015ee20 FUN_0015ee20 =====

int FUN_0015ee20(undefined8 param_1,char *param_2,ulong param_3)

{
  int iVar1;
  ulong uVar2;
  size_t sVar3;
  char *__s;
  long local_30;
  
  local_30 = 0;
  if ((param_2 == (char *)0x0) || ((int)param_1 == 0)) {
    return 2;
  }
  iVar1 = FUN_001390b0(param_1,&local_30);
  if (iVar1 == 0) {
    uVar2 = 0xe;
    __s = "Not Available";
    if (*(int *)(local_30 + 0x7c) != 0) {
      __s = (char *)(local_30 + 0x80);
      sVar3 = strlen(__s);
      uVar2 = sVar3 + 1;
    }
    if ((param_3 & 0xffffffff) < uVar2) {
      return 7;
    }
    strcpy(param_2,__s);
  }
  return iVar1;
}


// ===== 0015eee0 nvmlVgpuInstanceGetVmDriverVersion =====

int nvmlVgpuInstanceGetVmDriverVersion(undefined4 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x39a,"nvmlVgpuInstanceGetVmDriverVersion",
                 "(nvmlVgpuInstance_t vgpuInstance, char *version, unsigned int length)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015ee20(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x39a,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x39a,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0015f0b0 FUN_0015f0b0 =====

undefined8 FUN_0015f0b0(int param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  long local_20 [2];
  
  local_20[0] = 0;
  if ((param_2 == (undefined4 *)0x0) || (*param_2 = 0, param_1 == 0)) {
    return 2;
  }
  uVar1 = FUN_001390b0(param_1,local_20);
  if ((int)uVar1 == 0) {
    if ((*(int *)(local_20[0] + 0x38) == 5) ||
       ((*(int *)(local_20[0] + 0x38) == 0 && (*(int *)(local_20[0] + 0x34) == 1)))) {
      *param_2 = 1;
      return uVar1;
    }
  }
  return uVar1;
}


// ===== 0015f120 nvmlVgpuInstanceGetLicenseStatus =====

int nvmlVgpuInstanceGetLicenseStatus(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x3a4,"nvmlVgpuInstanceGetLicenseStatus",
                 "(nvmlVgpuInstance_t vgpuInstance, unsigned int *licensed)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015f0b0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x3a4,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x3a4,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0015f300 FUN_0015f300 =====

undefined8 FUN_0015f300(int param_1,int param_2,long param_3)

{
  undefined8 uVar1;
  long local_20;
  
  local_20 = 0;
  if ((param_2 == 0) || (param_3 == 0)) {
    return 2;
  }
  uVar1 = FUN_001390b0(param_2,&local_20);
  if ((int)uVar1 == 0) {
    if (*(int *)(local_20 + 0x7c) == 0) {
      return 9;
    }
    *(bool *)param_3 = *(int *)(local_20 + 0x38) == 5;
    *(undefined4 *)(param_3 + 4) = *(undefined4 *)(local_20 + 0x3c);
    *(undefined2 *)(param_3 + 8) = *(undefined2 *)(local_20 + 0x40);
    *(undefined2 *)(param_3 + 10) = *(undefined2 *)(local_20 + 0x42);
    *(undefined2 *)(param_3 + 0xc) = *(undefined2 *)(local_20 + 0x44);
    *(undefined2 *)(param_3 + 0xe) = *(undefined2 *)(local_20 + 0x46);
    *(undefined2 *)(param_3 + 0x10) = *(undefined2 *)(local_20 + 0x48);
    *(undefined1 *)(param_3 + 0x12) = *(undefined1 *)(local_20 + 0x4a);
    if (param_1 == 2) {
      *(undefined4 *)(param_3 + 0x14) = *(undefined4 *)(local_20 + 0x38);
      return uVar1;
    }
  }
  return uVar1;
}


// ===== 0015f3c0 FUN_0015f3c0 =====

void FUN_0015f3c0(undefined4 param_1,undefined8 param_2)

{
  FUN_0015f300(1,param_1,param_2);
  return;
}


// ===== 0015f3d0 nvmlVgpuInstanceGetLicenseInfo =====

int nvmlVgpuInstanceGetLicenseInfo(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x3a9,"nvmlVgpuInstanceGetLicenseInfo",
                 "(nvmlVgpuInstance_t vgpuInstance, nvmlVgpuLicenseInfo_t *licenseInfo)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015f3c0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x3a9,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x3a9,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0015f5b0 FUN_0015f5b0 =====

void FUN_0015f5b0(undefined4 param_1,undefined8 param_2)

{
  FUN_0015f300(2,param_1,param_2);
  return;
}


// ===== 0015f5c0 nvmlVgpuInstanceGetLicenseInfo_v2 =====

int nvmlVgpuInstanceGetLicenseInfo_v2(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x3ae,"nvmlVgpuInstanceGetLicenseInfo_v2",
                 "(nvmlVgpuInstance_t vgpuInstance, nvmlVgpuLicenseInfo_t *licenseInfo)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015f5b0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x3ae,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x3ae,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0015f7a0 FUN_0015f7a0 =====

undefined8 FUN_0015f7a0(int param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  long local_20 [2];
  
  local_20[0] = 0;
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    uVar1 = FUN_001390b0(param_1,local_20);
    if ((int)uVar1 == 0) {
      *param_2 = *(undefined4 *)(local_20[0] + 4);
    }
    return uVar1;
  }
  return 2;
}


// ===== 0015f7f0 nvmlVgpuInstanceGetType =====

int nvmlVgpuInstanceGetType(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x3b3,"nvmlVgpuInstanceGetType",
                 "(nvmlVgpuInstance_t vgpuInstance, unsigned int *vgpuTypeId)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015f7a0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x3b3,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x3b3,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0015f9d0 FUN_0015f9d0 =====

undefined8 FUN_0015f9d0(undefined8 param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  long local_20 [2];
  
  local_20[0] = 0;
  if (((int)param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    uVar1 = FUN_001390b0(param_1,local_20);
    if ((int)uVar1 == 0) {
      if (*(int *)(local_20[0] + 4) == 0) {
        return 2;
      }
      uVar1 = FUN_00138f40(*(int *)(local_20[0] + 4),*(undefined8 *)(local_20[0] + 0x1d8));
      if ((int)uVar1 == 0) {
        if (*(int *)(*(long *)(local_20[0] + 0x1d8) + 0x128) == 0) {
          uVar1 = 3;
        }
        else {
          *param_2 = *(undefined4 *)(local_20[0] + 0x20);
        }
      }
    }
    return uVar1;
  }
  return 2;
}


// ===== 0015fa50 nvmlVgpuInstanceGetFrameRateLimit =====

int nvmlVgpuInstanceGetFrameRateLimit(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x3b8,"nvmlVgpuInstanceGetFrameRateLimit",
                 "(nvmlVgpuInstance_t vgpuInstance, unsigned int *frameRateLimit)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015f9d0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x3b8,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x3b8,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0015fc30 FUN_0015fc30 =====

undefined8 FUN_0015fc30(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  long local_20 [2];
  
  local_20[0] = 0;
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    uVar2 = FUN_001390b0(param_1,local_20);
    if ((int)uVar2 == 0) {
      *param_2 = 0;
      iVar1 = *(int *)(local_20[0] + 0x4c);
      if (iVar1 != 2) {
        if (iVar1 == 3) {
          *param_2 = 1;
          return uVar2;
        }
        uVar2 = 999;
        if (iVar1 == 1) {
          uVar2 = 3;
        }
      }
    }
    return uVar2;
  }
  return 2;
}


// ===== 0015fcb0 nvmlVgpuInstanceGetEccMode =====

int nvmlVgpuInstanceGetEccMode(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x3bd,"nvmlVgpuInstanceGetEccMode",
                 "(nvmlVgpuInstance_t vgpuInstance, nvmlEnableState_t *eccMode)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015fc30(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x3bd,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x3bd,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0015fe90 FUN_0015fe90 =====

undefined8 FUN_0015fe90(int param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  long local_20 [2];
  
  local_20[0] = 0;
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    uVar1 = FUN_001390b0(param_1,local_20);
    if ((int)uVar1 == 0) {
      *param_2 = *(undefined4 *)(local_20[0] + 0x30);
    }
    return uVar1;
  }
  return 2;
}


// ===== 0015fee0 nvmlVgpuInstanceGetEncoderCapacity =====

int nvmlVgpuInstanceGetEncoderCapacity(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x3c2,"nvmlVgpuInstanceGetEncoderCapacity",
                 "(nvmlVgpuInstance_t vgpuInstance, unsigned int *encoderCapacity)",param_1,param_2)
    ;
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0015fe90(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x3c2,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x3c2,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001600c0 FUN_001600c0 =====

int FUN_001600c0(undefined8 param_1,uint param_2)

{
  undefined8 *puVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined1 *puVar5;
  uint uVar6;
  float fVar7;
  long local_40 [2];
  
  local_40[0] = 0;
  if ((int)param_1 != 0) {
    iVar3 = FUN_001390b0(param_1,local_40);
    if (iVar3 != 0) {
      return iVar3;
    }
    if (*(uint *)(local_40[0] + 0x30) == param_2) {
      return 0;
    }
    if (param_2 < 0x65) {
      if (DAT_01214898 == 0) {
        return 0;
      }
      puVar5 = &DAT_00380898;
      uVar6 = 0;
      do {
        lVar4 = *(long *)(puVar5 + 0x25d60);
        if (lVar4 != 0) {
          for (puVar1 = *(undefined8 **)(lVar4 + 0x618); (undefined8 *)(lVar4 + 0x618) != puVar1;
              puVar1 = (undefined8 *)*puVar1) {
            if (*(int *)(puVar1 + -0x43) == (int)param_1) {
              lVar4 = *(long *)(puVar5 + 0x256d8);
              if (((lVar4 == 0) || (*(long *)(lVar4 + 0x28) == 0)) ||
                 (pcVar2 = *(code **)(*(long *)(lVar4 + 0x28) + 0x40), pcVar2 == (code *)0x0)) {
                iVar3 = 3;
              }
              else {
                iVar3 = (*pcVar2)(lVar4,puVar5,puVar1 + -0x43,param_2);
                if (iVar3 == 0) {
                  *(uint *)(local_40[0] + 0x30) = param_2;
                  break;
                }
              }
              if (DAT_01216a78 < 2) {
                return iVar3;
              }
              fVar7 = (float)FUN_002917b0(&DAT_01216a60);
              lVar4 = syscall(0xba);
              FUN_002340f0((double)(fVar7 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,"api.c",
                           0x2a26,"tsapiVgpuInstanceSetEncoderCapacity",0x2a26,iVar3);
              return iVar3;
            }
          }
        }
        uVar6 = uVar6 + 1;
        puVar5 = puVar5 + 0x74a00;
        if (DAT_01214898 <= uVar6) {
          return 0;
        }
      } while( true );
    }
  }
  return 2;
}


// ===== 00160290 nvmlVgpuInstanceSetEncoderCapacity =====

int nvmlVgpuInstanceSetEncoderCapacity(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x3c7,"nvmlVgpuInstanceSetEncoderCapacity",
                 "(nvmlVgpuInstance_t vgpuInstance, unsigned int encoderCapacity)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001600c0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x3c7,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x3c7,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00160470 FUN_00160470 =====

int FUN_00160470(ulong param_1,undefined8 *param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  float fVar6;
  long local_30;
  
  if (param_2 == (undefined8 *)0x0) {
    iVar2 = 2;
  }
  else {
    local_30 = 0;
    iVar2 = 2;
    if (((int)param_1 != 0) && (iVar2 = FUN_001390b0(param_1,&local_30), iVar2 == 0)) {
      lVar5 = *(long *)(local_30 + 0x1e0);
      lVar3 = FUN_00234e30();
      if ((ulong)(lVar3 - *(long *)(local_30 + 0x70)) < 1000000) {
        *param_2 = *(undefined8 *)(local_30 + 0x28);
      }
      else {
        lVar3 = *(long *)(lVar5 + 0x256d8);
        if (((lVar3 == 0) || (*(long *)(lVar3 + 0x28) == 0)) ||
           (pcVar1 = *(code **)(*(long *)(lVar3 + 0x28) + 0x30), pcVar1 == (code *)0x0)) {
          iVar2 = 3;
        }
        else {
          iVar2 = (*pcVar1)(lVar3,lVar5,param_1 & 0xffffffff,param_2);
          if (iVar2 == 0) {
            uVar4 = FUN_00234e30();
            *(undefined8 *)(local_30 + 0x70) = uVar4;
            return 0;
          }
        }
        if (1 < DAT_01216a78) {
          fVar6 = (float)FUN_002917b0(&DAT_01216a60);
          lVar5 = syscall(0xba);
          FUN_002340f0((double)(fVar6 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,"api.c",0x1b1,
                       "vgpuInstanceGetFbUsage",0x1b1,iVar2);
        }
      }
    }
  }
  return iVar2;
}


// ===== 001605e0 nvmlVgpuInstanceGetFbUsage =====

int nvmlVgpuInstanceGetFbUsage(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x39f,"nvmlVgpuInstanceGetFbUsage",
                 "(nvmlVgpuInstance_t vgpuInstance, unsigned long long *fbUsage)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00160470(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x39f,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x39f,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001607c0 FUN_001607c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_001607c0(undefined8 param_1,undefined8 *param_2,uint *param_3)

{
  char *__s;
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  size_t sVar4;
  long local_30;
  
  local_30 = 0;
  if ((param_3 != (uint *)0x0 && (int)param_1 != 0) && (param_2 != (undefined8 *)0x0)) {
    iVar3 = FUN_001390b0(param_1,&local_30);
    uVar2 = _UNK_002a7a78;
    uVar1 = _DAT_002a7a70;
    if (iVar3 == 0) {
      if (*(int *)(local_30 + 0x7c) == 0) {
        *(undefined1 *)(param_2 + 2) = 0;
        iVar3 = 9;
        *param_2 = uVar1;
        param_2[1] = uVar2;
      }
      else {
        __s = (char *)(local_30 + 0x50);
        sVar4 = strlen(__s);
        if ((ulong)*param_3 < sVar4 + 1) {
          *param_3 = 0x20;
          return 7;
        }
        memcpy(param_2,__s,sVar4 + 1);
      }
    }
    return iVar3;
  }
  return 2;
}


// ===== 001608a0 nvmlVgpuInstanceGetGpuPciId =====

int nvmlVgpuInstanceGetGpuPciId(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x3dd,"nvmlVgpuInstanceGetGpuPciId",
                 "(nvmlVgpuInstance_t vgpuInstance, char *vgpuPciId, unsigned int *length)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001607c0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x3dd,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x3dd,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00160a70 FUN_00160a70 =====

int FUN_00160a70(int param_1,int param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  long local_30;
  
  local_30 = 0;
  if ((param_1 == 0) || (param_3 == (undefined4 *)0x0)) {
    return 2;
  }
  if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x28) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0xb8), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(DAT_012164a0,param_1,&local_30);
    if (iVar2 == 0) {
      iVar2 = FUN_00138f40(param_1,local_30);
      if (iVar2 == 0) {
        if (param_2 == 0) {
          *param_3 = *(undefined4 *)(local_30 + 0x14c);
          return 0;
        }
        if (param_2 == 1) {
          *param_3 = *(undefined4 *)(local_30 + 0x150);
          return 0;
        }
        if (param_2 == 2) {
          *param_3 = *(undefined4 *)(local_30 + 0x154);
          return 0;
        }
        if (param_2 != 3) {
          if (param_2 == 4) {
            *param_3 = *(undefined4 *)(local_30 + 0x15c);
            return 0;
          }
          return 2;
        }
        *param_3 = *(undefined4 *)(local_30 + 0x158);
        return 0;
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0x2a6e;
      uVar4 = 0x2a6e;
      goto LAB_00160b9f;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  fVar5 = fVar5 * DAT_00298548;
  uVar6 = 0x2a6b;
  uVar4 = 0x2a6b;
LAB_00160b9f:
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,"api.c",
               uVar4,"tsapiVgpuTypeGetCapabilities",uVar6,iVar2);
  return iVar2;
}


// ===== 00160cc0 nvmlVgpuTypeGetCapabilities =====

int nvmlVgpuTypeGetCapabilities(undefined4 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x3e2,"nvmlVgpuTypeGetCapabilities",
                 "(nvmlVgpuTypeId_t vgpuTypeId, nvmlVgpuCapability_t capability, unsigned int *capResult)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00160a70(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x3e2,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x3e2,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00160e90 FUN_00160e90 =====

undefined8 FUN_00160e90(char *param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (((param_2 != 0) && (param_1 != (char *)0x0)) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x20) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x20) + 0x20),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00160ee2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00160f00 nvmlDeviceGetGspFirmwareVersion =====

int nvmlDeviceGetGspFirmwareVersion(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",999,"nvmlDeviceGetGspFirmwareVersion",
                 "(nvmlDevice_t device, char *version)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00160e90(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",999,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",999,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001610e0 FUN_001610e0 =====

undefined8 FUN_001610e0(char *param_1,long param_2,long param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (((param_3 != 0 && param_1 != (char *)0x0) && (param_2 != 0)) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x20) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x20) + 0x28),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00161140. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00161160 nvmlDeviceGetGspFirmwareMode =====

int nvmlDeviceGetGspFirmwareMode(undefined8 param_1,undefined8 param_2,undefined8 param_3)

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
                 "entry_points.h",0x3ec,"nvmlDeviceGetGspFirmwareMode",
                 "(nvmlDevice_t device, unsigned int *isEnabled, unsigned int *defaultMode)",param_1
                 ,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001610e0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x3ec,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x3ec,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00161330 FUN_00161330 =====

undefined8 FUN_00161330(int param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  long local_20 [2];
  
  local_20[0] = 0;
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    uVar1 = FUN_001390b0(param_1,local_20);
    if ((int)uVar1 == 0) {
      *param_2 = *(undefined4 *)(local_20[0] + 0x78);
    }
    return uVar1;
  }
  return 2;
}


// ===== 00161380 nvmlVgpuInstanceGetGpuInstanceId =====

int nvmlVgpuInstanceGetGpuInstanceId(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x3f1,"nvmlVgpuInstanceGetGpuInstanceId",
                 "(nvmlVgpuInstance_t vgpuInstance, unsigned int *gpuInstanceId)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00161330(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x3f1,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x3f1,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00161560 FUN_00161560 =====

int FUN_00161560(ulong param_1,undefined8 *param_2,uint *param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 *puVar4;
  char *pcVar5;
  uint uVar6;
  int local_34;
  long local_30;
  ulong uVar7;
  
  local_30 = 0;
  local_34 = 0;
  if (param_3 == (uint *)0x0) {
    return 2;
  }
  if (param_2 == (undefined8 *)0x0) {
    iVar3 = 2;
    if (*param_3 == 0) goto LAB_0016168a;
  }
  else {
    if (*param_3 < 0x1d4) {
LAB_0016168a:
      *param_3 = 0x1d4;
      return 7;
    }
    iVar3 = 2;
    if (((int)param_1 != 0) && (iVar3 = FUN_001390b0(param_1,&local_30), iVar3 == 0)) {
      if (DAT_01214898 != 0) {
        pcVar5 = &DAT_00380898;
        uVar7 = 0;
        do {
          if (((*pcVar5 == '\x01') ||
              (((((&DAT_003808ac)[uVar7 * 0x1d280] != 0 && (*(int *)(pcVar5 + 0x1c) == 0)) &&
                (*(int *)(pcVar5 + 0x10) != 0)) && (*(long *)(pcVar5 + 0x20) != 0)))) &&
             (lVar1 = *(long *)(pcVar5 + 0x25d60), lVar1 != 0)) {
            puVar4 = *(undefined8 **)(lVar1 + 0x618);
            if (puVar4 != (undefined8 *)(lVar1 + 0x618)) {
              for (; (undefined8 *)(lVar1 + 0x618) != puVar4; puVar4 = (undefined8 *)*puVar4) {
                if ((int)param_1 == *(int *)(puVar4 + -0x43)) {
                  *param_2 = 0x100000003;
                  *(undefined4 *)(param_2 + 1) = *(undefined4 *)(local_30 + 0x1d0);
                  iVar3 = FUN_00145ab0((long)param_2 + 0x5c,0x50);
                  if ((iVar3 == 0) &&
                     (iVar3 = FUN_0015ee20(param_1 & 0xffffffff,(long)param_2 + 0xc,0x50),
                     iVar3 == 0)) {
                    *(undefined4 *)((long)param_2 + 0xcc) = 0x104;
                    *(undefined4 *)(param_2 + 0x1a) = *(undefined4 *)(local_30 + 4);
                    lVar1 = (&DAT_003a5f70)[uVar7 * 0xe940];
                    if ((lVar1 != 0) &&
                       ((*(long *)(lVar1 + 0x28) != 0 &&
                        (pcVar2 = *(code **)(*(long *)(lVar1 + 0x28) + 0x58), pcVar2 != (code *)0x0)
                        ))) {
                      iVar3 = (*pcVar2)(lVar1,&DAT_00380898 + uVar7 * 0x74a00,&local_34);
                      if (iVar3 == 0) {
                        *(uint *)((long)param_2 + 0xc4) = (uint)(local_34 == 1);
                        if (*(int *)(local_30 + 0x18) == 1) {
                          *(undefined4 *)((long)param_2 + 0xc4) = 0;
                        }
                        lVar1 = (&DAT_003a5f70)[uVar7 * 0xe940];
                        if ((((lVar1 != 0) && (*(long *)(lVar1 + 0x28) != 0)) &&
                            (pcVar2 = *(code **)(*(long *)(lVar1 + 0x28) + 0xb0),
                            pcVar2 != (code *)0x0)) &&
                           (iVar3 = (*pcVar2)(lVar1,&DAT_00380898 + uVar7 * 0x74a00,
                                              (long)param_2 + 0xd4), iVar3 == 0)) {
                          *(undefined4 *)(param_2 + 0x19) = *(undefined4 *)(local_30 + 0x1c);
                          return 0;
                        }
                      }
                    }
                  }
                  return 999;
                }
              }
            }
          }
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulong)uVar6;
          pcVar5 = pcVar5 + 0x74a00;
        } while (DAT_01214898 != uVar6);
      }
      iVar3 = 6;
    }
  }
  return iVar3;
}


// ===== 00161810 nvmlVgpuInstanceGetMetadata =====

int nvmlVgpuInstanceGetMetadata(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x3d8,"nvmlVgpuInstanceGetMetadata",
                 "(nvmlVgpuInstance_t vgpuInstance, nvmlVgpuMetadata_t *vgpuMetadata, unsigned int *bufferSize)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00161560(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x3d8,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x3d8,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001619e0 FUN_001619e0 =====

undefined8 FUN_001619e0(char *param_1,undefined8 *param_2,uint *param_3)

{
  code *pcVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  int local_1c;
  
  local_1c = 0;
  if ((param_3 == (uint *)0x0) || (param_1 == (char *)0x0)) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((uVar4 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (*(long *)(param_1 + 0x25d60) == 0) {
      uVar4 = 3;
    }
    else {
      if (param_2 == (undefined8 *)0x0) {
        if (*param_3 != 0) {
          return 2;
        }
      }
      else if (0x17b < *param_3) {
        *param_2 = 0x100000003;
        iVar3 = FUN_00145ab0(param_2 + 1,0x50);
        if (((iVar3 == 0) && (DAT_012164a0 != 0)) &&
           ((*(long *)(DAT_012164a0 + 200) != 0 &&
            ((pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 200) + 0x28), pcVar1 != (code *)0x0 &&
             (iVar3 = (*pcVar1)(DAT_012164a0,0,param_2 + 0xe), iVar3 == 0)))))) {
          *(undefined4 *)(param_2 + 0xf) = 0x100;
          lVar2 = *(long *)(param_1 + 0x256d8);
          if ((lVar2 != 0) &&
             (((*(long *)(lVar2 + 0x28) != 0 &&
               (pcVar1 = *(code **)(*(long *)(lVar2 + 0x28) + 0x58), pcVar1 != (code *)0x0)) &&
              (iVar3 = (*pcVar1)(lVar2,param_1,&local_1c), iVar3 == 0)))) {
            *(uint *)(param_2 + 0xb) = (uint)(local_1c == 1);
            lVar2 = *(long *)(param_1 + 0x256d8);
            if (((lVar2 != 0) && (*(long *)(lVar2 + 0x28) != 0)) &&
               ((pcVar1 = *(code **)(*(long *)(lVar2 + 0x28) + 0xb0), pcVar1 != (code *)0x0 &&
                (uVar4 = (*pcVar1)(lVar2,param_1,(long)param_2 + 0x7c), (int)uVar4 == 0)))) {
              return uVar4;
            }
          }
        }
        return 999;
      }
      *param_3 = 0x17c;
      uVar4 = 7;
    }
  }
  return uVar4;
}


// ===== 00161b90 nvmlDeviceGetVgpuMetadata =====

int nvmlDeviceGetVgpuMetadata(undefined8 param_1,undefined8 param_2,undefined8 param_3)

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
                 "entry_points.h",0x3f6,"nvmlDeviceGetVgpuMetadata",
                 "(nvmlDevice_t device, nvmlVgpuPgpuMetadata_t *pgpuMetadata, unsigned int *bufferSize)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001619e0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x3f6,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x3f6,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00161d60 FUN_00161d60 =====

undefined8 FUN_00161d60(uint *param_1,uint *param_2,undefined8 *param_3)

{
  uint uVar1;
  int iVar2;
  
  if ((param_2 == (uint *)0x0 || param_3 == (undefined8 *)0x0) || (param_1 == (uint *)0x0)) {
    return 2;
  }
  if ((2 < *param_2) && (2 < *param_1)) {
    if (((param_2[0x16] & 1) == 0) || ((param_1[0x31] & 1) == 0)) {
      *param_3 = 0x500000000;
      return 0;
    }
    uVar1 = param_1[0x32];
    if ((uVar1 == 0) || ((param_2[0x1c] <= uVar1 && (uVar1 <= param_2[0x1d])))) {
      iVar2 = strcmp((char *)(param_1 + 0x35),(char *)(param_2 + 0x1f));
      if (iVar2 == 0) {
        *param_3 = 9;
        return 0;
      }
      *param_3 = 0x400000000;
      return 0;
    }
  }
  *param_3 = 0x100000000;
  return 0;
}


// ===== 00161e30 nvmlGetVgpuCompatibility =====

int nvmlGetVgpuCompatibility(undefined8 param_1,undefined8 param_2,undefined8 param_3)

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
                 "entry_points.h",0x3fb,"nvmlGetVgpuCompatibility",
                 "(nvmlVgpuMetadata_t *vgpuMetadata, nvmlVgpuPgpuMetadata_t *pgpuMetadata, nvmlVgpuPgpuCompatibility_t *compatibilityInfo)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00161d60(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x3fb,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x3fb,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00162000 FUN_00162000 =====

int FUN_00162000(char *param_1,char *param_2,uint *param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  size_t sVar4;
  long lVar5;
  float fVar6;
  
  if (((param_3 == (uint *)0x0) || (param_1 == (char *)0x0)) ||
     ((*param_1 != '\x01' &&
      ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
        (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))))) {
LAB_00162140:
    iVar2 = 2;
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
           (pcVar1 = *(code **)(*(long *)(lVar5 + 0x38) + 8), pcVar1 != (code *)0x0)) {
          uVar3 = (*pcVar1)(lVar5,param_1,param_1 + 0x70530);
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
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar5,"api.c",0x2c40,"tsapiDeviceGetPgpuMetadataString",0x2c40,iVar2);
      return iVar2;
    }
    if (*(int *)(param_1 + 0x70530) != 3) {
      return 3;
    }
    if (param_2 == (char *)0x0) {
      if (*param_3 != 0) goto LAB_00162140;
    }
    else if (0xff < *param_3) {
      lVar5 = *(long *)(param_1 + 0x256d8);
      if (((lVar5 != 0) && (*(long *)(lVar5 + 0x28) != 0)) &&
         ((pcVar1 = *(code **)(*(long *)(lVar5 + 0x28) + 0xb0), pcVar1 != (code *)0x0 &&
          (iVar2 = (*pcVar1)(lVar5,param_1,param_2), iVar2 == 0)))) {
        sVar4 = strlen(param_2);
        *param_3 = (uint)sVar4;
        return 0;
      }
      return 999;
    }
    *param_3 = 0x100;
    iVar2 = 7;
  }
  return iVar2;
}


// ===== 00162260 nvmlDeviceGetPgpuMetadataString =====

int nvmlDeviceGetPgpuMetadataString(undefined8 param_1,undefined8 param_2,undefined8 param_3)

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
                 "entry_points.h",0x414,"nvmlDeviceGetPgpuMetadataString",
                 "(nvmlDevice_t device, char *pgpuMetadata, unsigned int *bufferSize)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00162000(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x414,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x414,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00162430 FUN_00162430 =====

void FUN_00162430(undefined8 param_1,undefined8 param_2)

{
  FUN_00138510(param_1,1,param_2);
  return;
}


// ===== 00162440 nvmlDeviceGetGridLicensableFeatures =====

int nvmlDeviceGetGridLicensableFeatures(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x419,"nvmlDeviceGetGridLicensableFeatures",
                 "(nvmlDevice_t device, nvmlGridLicensableFeatures_t *pGridLicensableFeatures)",
                 param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00162430(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x419,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x419,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00162620 FUN_00162620 =====

void FUN_00162620(undefined8 param_1,undefined8 param_2)

{
  FUN_00138510(param_1,2,param_2);
  return;
}


// ===== 00162630 nvmlDeviceGetGridLicensableFeatures_v2 =====

int nvmlDeviceGetGridLicensableFeatures_v2(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x41e,"nvmlDeviceGetGridLicensableFeatures_v2",
                 "(nvmlDevice_t device, nvmlGridLicensableFeatures_t *pGridLicensableFeatures)",
                 param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00162620(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x41e,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x41e,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00162810 FUN_00162810 =====

void FUN_00162810(undefined8 param_1,undefined8 param_2)

{
  FUN_00138510(param_1,3,param_2);
  return;
}


// ===== 00162820 nvmlDeviceGetGridLicensableFeatures_v3 =====

int nvmlDeviceGetGridLicensableFeatures_v3(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x423,"nvmlDeviceGetGridLicensableFeatures_v3",
                 "(nvmlDevice_t device, nvmlGridLicensableFeatures_t *pGridLicensableFeatures)",
                 param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00162810(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x423,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x423,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00162a00 FUN_00162a00 =====

void FUN_00162a00(undefined8 param_1,undefined8 param_2)

{
  FUN_00138510(param_1,4,param_2);
  return;
}


// ===== 00162a10 nvmlDeviceGetGridLicensableFeatures_v4 =====

int nvmlDeviceGetGridLicensableFeatures_v4(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x428,"nvmlDeviceGetGridLicensableFeatures_v4",
                 "(nvmlDevice_t device, nvmlGridLicensableFeatures_t *pGridLicensableFeatures)",
                 param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00162a00(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x428,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x428,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00162bf0 FUN_00162bf0 =====

int FUN_00162bf0(undefined8 param_1,uint *param_2,uint *param_3,uint *param_4)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  void *__ptr;
  int *piVar4;
  long lVar5;
  uint uVar6;
  float fVar7;
  uint local_44;
  long local_40 [2];
  
  local_40[0] = 0;
  local_44 = 0;
  if (((param_4 == (uint *)0x0 || (int)param_1 == 0) || param_3 == (uint *)0x0) ||
     (param_2 == (uint *)0x0)) {
    iVar3 = 2;
  }
  else {
    iVar3 = FUN_001390b0(param_1,local_40);
    if (iVar3 == 0) {
      lVar5 = *(long *)(local_40[0] + 0x1e0);
      lVar1 = *(long *)(lVar5 + 0x256d8);
      if (((lVar1 == 0) || (*(long *)(lVar1 + 0xe0) == 0)) ||
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0xe0) + 0x18), pcVar2 == (code *)0x0)) {
        iVar3 = 3;
      }
      else {
        iVar3 = (*pcVar2)(lVar1,lVar5,&local_44,0);
        if (iVar3 == 0) {
          __ptr = malloc((ulong)local_44 << 5);
          if (__ptr != (void *)0x0) {
            lVar1 = *(long *)(lVar5 + 0x256d8);
            if (((lVar1 == 0) || (*(long *)(lVar1 + 0xe0) == 0)) ||
               (pcVar2 = *(code **)(*(long *)(lVar1 + 0xe0) + 0x18), pcVar2 == (code *)0x0)) {
              iVar3 = 3;
            }
            else {
              iVar3 = (*pcVar2)(lVar1,lVar5,&local_44,__ptr);
              if (iVar3 == 0) {
                *param_3 = 0;
                *param_4 = 0;
                uVar6 = 0;
                if (local_44 != 0) {
                  piVar4 = (int *)((long)__ptr + 8);
                  uVar6 = 0;
                  do {
                    if (*piVar4 == *(int *)(local_40[0] + 8)) {
                      *param_3 = *param_3 + piVar4[4];
                      uVar6 = uVar6 + 1;
                      *param_4 = *param_4 + piVar4[5];
                    }
                    piVar4 = piVar4 + 8;
                  } while (piVar4 != (int *)((long)__ptr + (ulong)(local_44 - 1) * 0x20 + 0x28));
                  if (uVar6 != 0) {
                    *param_3 = *param_3 / uVar6;
                    *param_4 = *param_4 / uVar6;
                  }
                }
                *param_2 = uVar6;
              }
            }
            free(__ptr);
            return iVar3;
          }
          return 0x14;
        }
      }
      if (1 < DAT_01216a78) {
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                     "ERROR",lVar5,"api.c",0x2dce,"tsapiVgpuInstanceGetEncoderStats",0x2dce,iVar3);
      }
    }
  }
  return iVar3;
}


// ===== 00162e30 nvmlVgpuInstanceGetEncoderStats =====

int nvmlVgpuInstanceGetEncoderStats
              (undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p %p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x476,"nvmlVgpuInstanceGetEncoderStats",
                 "(nvmlVgpuInstance_t vgpuInstance, unsigned int *sessionCount, unsigned int *averageFps, unsigned int *averageLatency)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00162bf0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x476,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x476,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00163020 FUN_00163020 =====

int FUN_00163020(int param_1,uint *param_2,long param_3)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  undefined4 *__ptr;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  ulong uVar11;
  ulong uVar12;
  int iVar13;
  float fVar14;
  uint local_44;
  long local_40 [2];
  
  local_40[0] = 0;
  local_44 = 0;
  if (param_2 == (uint *)0x0) {
    return 2;
  }
  if ((*param_2 != 0) && (param_3 == 0)) {
    return 2;
  }
  if (param_1 == 0) {
    return 2;
  }
  iVar5 = FUN_001390b0(param_1,local_40);
  if (iVar5 != 0) {
    return iVar5;
  }
  lVar6 = *(long *)(local_40[0] + 0x1e0);
  if (((*(long *)(lVar6 + 0x256d8) == 0) ||
      (lVar3 = *(long *)(*(long *)(lVar6 + 0x256d8) + 0xe0), lVar3 == 0)) ||
     (pcVar4 = *(code **)(lVar3 + 0x18), pcVar4 == (code *)0x0)) {
    iVar5 = 3;
  }
  else {
    iVar5 = (*pcVar4)();
    if (iVar5 == 0) {
      if (local_44 == 0) {
        *param_2 = 0;
        return 0;
      }
      __ptr = malloc((ulong)local_44 << 5);
      if (__ptr == (undefined4 *)0x0) {
        return 0x14;
      }
      lVar3 = *(long *)(lVar6 + 0x256d8);
      if (((lVar3 == 0) || (*(long *)(lVar3 + 0xe0) == 0)) ||
         (pcVar4 = *(code **)(*(long *)(lVar3 + 0xe0) + 0x18), pcVar4 == (code *)0x0)) {
        iVar5 = 3;
      }
      else {
        iVar5 = (*pcVar4)(lVar3,lVar6,&local_44,__ptr);
        if (iVar5 == 0) {
          uVar10 = 0;
          if (local_44 != 0) {
            piVar7 = __ptr + 2;
            uVar10 = 0;
            iVar13 = *(int *)(local_40[0] + 8);
            do {
              iVar1 = *piVar7;
              piVar7 = piVar7 + 8;
              uVar10 = uVar10 + (iVar1 == iVar13);
            } while (piVar7 != __ptr + (ulong)(local_44 - 1) * 8 + 10);
            if (*param_2 != 0 && param_3 != 0) {
              if (*param_2 < uVar10) {
                *param_2 = uVar10;
                iVar5 = 7;
                goto LAB_001632b6;
              }
              puVar9 = __ptr;
              uVar11 = 0;
              while( true ) {
                uVar12 = uVar11;
                if (puVar9[2] == iVar13) {
                  uVar12 = (ulong)((int)uVar11 + 1);
                  puVar8 = (undefined4 *)(uVar11 * 0x20 + param_3);
                  *puVar8 = *puVar9;
                  uVar2 = puVar9[1];
                  puVar8[2] = param_1;
                  puVar8[1] = uVar2;
                  puVar8[3] = puVar9[3];
                  puVar8[4] = puVar9[4];
                  puVar8[5] = puVar9[5];
                  puVar8[6] = puVar9[6];
                  puVar8[7] = puVar9[7];
                }
                puVar9 = puVar9 + 8;
                if (__ptr + (ulong)(local_44 - 1) * 8 + 8 == puVar9) break;
                iVar13 = *(int *)(local_40[0] + 8);
                uVar11 = uVar12;
              }
            }
          }
          *param_2 = uVar10;
        }
      }
LAB_001632b6:
      free(__ptr);
      return iVar5;
    }
  }
  if (1 < DAT_01216a78) {
    fVar14 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar14 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar6,"api.c",0x2e14,"tsapiVgpuInstanceGetEncoderSessions",0x2e14,iVar5);
  }
  return iVar5;
}


// ===== 001632e0 nvmlVgpuInstanceGetEncoderSessions =====

int nvmlVgpuInstanceGetEncoderSessions(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x47c,"nvmlVgpuInstanceGetEncoderSessions",
                 "(nvmlVgpuInstance_t vgpuInstance, unsigned int *sessionCount, nvmlEncoderSessionInfo_t *sessionInfo)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00163020(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x47c,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x47c,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001634b0 FUN_001634b0 =====

int FUN_001634b0(undefined8 param_1,uint *param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  void *__ptr;
  int *piVar5;
  uint uVar6;
  float fVar7;
  uint local_44;
  long local_40 [2];
  
  local_40[0] = 0;
  local_44 = 0;
  if (((int)param_1 == 0) || (param_2 == (uint *)0x0)) {
    iVar3 = 2;
  }
  else {
    iVar3 = FUN_001390b0(param_1,local_40);
    if (iVar3 == 0) {
      lVar4 = *(long *)(local_40[0] + 0x1e0);
      lVar1 = *(long *)(lVar4 + 0x256d8);
      if (((lVar1 == 0) || (*(long *)(lVar1 + 0xf8) == 0)) ||
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0xf8) + 8), pcVar2 == (code *)0x0)) {
        iVar3 = 3;
      }
      else {
        iVar3 = (*pcVar2)(lVar1,lVar4,&local_44,0);
        if (iVar3 == 0) {
          __ptr = malloc((ulong)local_44 * 0x30);
          if (__ptr != (void *)0x0) {
            lVar1 = *(long *)(lVar4 + 0x256d8);
            if (((lVar1 == 0) || (*(long *)(lVar1 + 0xf8) == 0)) ||
               (pcVar2 = *(code **)(*(long *)(lVar1 + 0xf8) + 8), pcVar2 == (code *)0x0)) {
              iVar3 = 3;
            }
            else {
              iVar3 = (*pcVar2)(lVar1,lVar4,&local_44,__ptr);
              if (iVar3 == 0) {
                param_2[1] = 0;
                param_2[2] = 0;
                uVar6 = 0;
                if (local_44 != 0) {
                  piVar5 = (int *)((long)__ptr + 8);
                  uVar6 = 0;
                  do {
                    if (*piVar5 == (int)param_1) {
                      param_2[1] = param_2[1] + piVar5[8];
                      uVar6 = uVar6 + 1;
                      param_2[2] = param_2[2] + piVar5[9];
                    }
                    piVar5 = piVar5 + 0xc;
                  } while (piVar5 != (int *)((long)__ptr + (ulong)(local_44 - 1) * 0x30 + 0x38));
                  if (uVar6 != 0) {
                    param_2[1] = param_2[1] / uVar6;
                    param_2[2] = param_2[2] / uVar6;
                  }
                }
                *param_2 = uVar6;
              }
            }
            free(__ptr);
            return iVar3;
          }
          return 0x14;
        }
      }
      if (1 < DAT_01216a78) {
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                     "ERROR",lVar4,"api.c",0x2e75,"tsapiVgpuInstanceGetFBCStats",0x2e75,iVar3);
      }
    }
  }
  return iVar3;
}


// ===== 001636e0 nvmlVgpuInstanceGetFBCStats =====

int nvmlVgpuInstanceGetFBCStats(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x481,"nvmlVgpuInstanceGetFBCStats",
                 "(nvmlVgpuInstance_t vgpuInstance, nvmlFBCStats_t *fbcStats)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001634b0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x481,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x481,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001638c0 FUN_001638c0 =====

int FUN_001638c0(int param_1,uint *param_2,long param_3)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  undefined4 *__ptr;
  int *piVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  ulong uVar11;
  ulong uVar12;
  float fVar13;
  uint local_44;
  long local_40 [2];
  
  local_40[0] = 0;
  local_44 = 0;
  if (param_2 == (uint *)0x0) {
    return 2;
  }
  if ((*param_2 != 0) && (param_3 == 0)) {
    return 2;
  }
  if (param_1 == 0) {
    return 2;
  }
  iVar5 = FUN_001390b0(param_1,local_40);
  if (iVar5 != 0) {
    return iVar5;
  }
  lVar6 = *(long *)(local_40[0] + 0x1e0);
  if (((*(long *)(lVar6 + 0x256d8) == 0) ||
      (lVar3 = *(long *)(*(long *)(lVar6 + 0x256d8) + 0xf8), lVar3 == 0)) ||
     (pcVar4 = *(code **)(lVar3 + 8), pcVar4 == (code *)0x0)) {
    iVar5 = 3;
  }
  else {
    iVar5 = (*pcVar4)();
    if (iVar5 == 0) {
      if (local_44 == 0) {
        *param_2 = 0;
        return 0;
      }
      __ptr = malloc((ulong)local_44 * 0x30);
      if (__ptr == (undefined4 *)0x0) {
        return 0x14;
      }
      lVar3 = *(long *)(lVar6 + 0x256d8);
      if (((lVar3 == 0) || (*(long *)(lVar3 + 0xf8) == 0)) ||
         (pcVar4 = *(code **)(*(long *)(lVar3 + 0xf8) + 8), pcVar4 == (code *)0x0)) {
        iVar5 = 3;
      }
      else {
        iVar5 = (*pcVar4)(lVar3,lVar6,&local_44,__ptr);
        if (iVar5 == 0) {
          uVar9 = 0;
          if (local_44 != 0) {
            piVar7 = __ptr + 2;
            uVar9 = 0;
            do {
              iVar1 = *piVar7;
              piVar7 = piVar7 + 0xc;
              uVar9 = uVar9 + (iVar1 == param_1);
            } while (piVar7 != __ptr + (ulong)(local_44 - 1) * 0xc + 0xe);
            if (param_3 != 0 && *param_2 != 0) {
              puVar10 = __ptr;
              uVar11 = 0;
              if (*param_2 < uVar9) {
                *param_2 = uVar9;
                iVar5 = 7;
                goto LAB_00163b86;
              }
              do {
                uVar12 = uVar11;
                if (puVar10[2] == param_1) {
                  uVar12 = (ulong)((int)uVar11 + 1);
                  puVar8 = (undefined4 *)(uVar11 * 0x30 + param_3);
                  puVar8[1] = puVar10[1];
                  uVar2 = *puVar10;
                  puVar8[2] = param_1;
                  *puVar8 = uVar2;
                  puVar8[3] = puVar10[3];
                  puVar8[4] = puVar10[4];
                  puVar8[5] = puVar10[5];
                  puVar8[6] = puVar10[6];
                  puVar8[7] = puVar10[7];
                  puVar8[8] = puVar10[8];
                  puVar8[9] = puVar10[9];
                  puVar8[10] = puVar10[10];
                  puVar8[0xb] = puVar10[0xb];
                }
                puVar10 = puVar10 + 0xc;
                uVar11 = uVar12;
              } while (puVar10 != __ptr + (ulong)(local_44 - 1) * 0xc + 0xc);
            }
          }
          *param_2 = uVar9;
        }
      }
LAB_00163b86:
      free(__ptr);
      return iVar5;
    }
  }
  if (1 < DAT_01216a78) {
    fVar13 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar13 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar6,"api.c",0x2eb7,"tsapiVgpuInstanceGetFBCSessions",0x2eb7,iVar5);
  }
  return iVar5;
}


// ===== 00163bb0 nvmlVgpuInstanceGetFBCSessions =====

int nvmlVgpuInstanceGetFBCSessions(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d %p %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x486,"nvmlVgpuInstanceGetFBCSessions",
                 "(nvmlVgpuInstance_t vgpuInstance, unsigned int *sessionCount, nvmlFBCSessionInfo_t *sessionInfo)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001638c0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x486,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x486,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00163d80 FUN_00163d80 =====

undefined8 FUN_00163d80(char *param_1,long param_2)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x20) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x20) + 0x60),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00163dd2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00163df0 nvmlDeviceGetHostVgpuMode =====

int nvmlDeviceGetHostVgpuMode(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x4d4,"nvmlDeviceGetHostVgpuMode",
                 "(nvmlDevice_t device, nvmlHostVgpuMode_t *pHostVgpuMode)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00163d80(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x4d4,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x4d4,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00163fd0 FUN_00163fd0 =====

undefined8 FUN_00163fd0(undefined8 param_1,undefined4 *param_2)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  long local_20 [2];
  
  local_20[0] = 0;
  if ((param_2 == (undefined4 *)0x0) || ((int)param_1 == 0)) {
    return 2;
  }
  uVar3 = FUN_001390b0(param_1,local_20);
  if ((int)uVar3 == 0) {
    if (*(int *)(local_20[0] + 0x7c) == 0) {
      *param_2 = 0xffffffff;
      return 9;
    }
    lVar1 = *(long *)(*(long *)(local_20[0] + 0x1e0) + 0x256d8);
    if (((lVar1 == 0) || (*(undefined8 **)(lVar1 + 0x70) == (undefined8 *)0x0)) ||
       (pcVar2 = (code *)**(undefined8 **)(lVar1 + 0x70), pcVar2 == (code *)0x0)) {
      return 3;
    }
    uVar3 = (*pcVar2)(lVar1,*(long *)(local_20[0] + 0x1e0),*(undefined4 *)(local_20[0] + 0xc),
                      param_2);
  }
  return uVar3;
}


// ===== 00164080 nvmlVgpuInstanceGetAccountingMode =====

int nvmlVgpuInstanceGetAccountingMode(undefined4 param_1,undefined8 param_2)

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
                 "entry_points.h",0x496,"nvmlVgpuInstanceGetAccountingMode",
                 "(nvmlVgpuInstance_t vgpuInstance, nvmlEnableState_t *mode)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00163fd0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x496,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x496,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00164260 FUN_00164260 =====

undefined8 FUN_00164260(undefined8 param_1,int *param_2,long param_3)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  long local_20;
  
  local_20 = 0;
  if (param_2 == (int *)0x0) {
    return 2;
  }
  if (*param_2 == 0) {
    if (param_3 == 0) {
      *param_2 = 4000;
      return 7;
    }
  }
  else if (param_3 == 0) {
    return 2;
  }
  uVar3 = 2;
  if (((int)param_1 != 0) && (uVar3 = FUN_001390b0(param_1,&local_20), (int)uVar3 == 0)) {
    lVar1 = *(long *)(*(long *)(local_20 + 0x1e0) + 0x256d8);
    if ((lVar1 == 0) ||
       ((*(long *)(lVar1 + 0x70) == 0 ||
        (pcVar2 = *(code **)(*(long *)(lVar1 + 0x70) + 0x18), pcVar2 == (code *)0x0)))) {
      return 3;
    }
    uVar3 = (*pcVar2)(lVar1,*(long *)(local_20 + 0x1e0),*(undefined4 *)(local_20 + 0xc),param_2,
                      param_3);
  }
  return uVar3;
}


// ===== 00164320 nvmlVgpuInstanceGetAccountingPids =====

int nvmlVgpuInstanceGetAccountingPids(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x49b,"nvmlVgpuInstanceGetAccountingPids",
                 "(nvmlVgpuInstance_t vgpuInstance, unsigned int *count, unsigned int *pids)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00164260(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x49b,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x49b,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001644f0 FUN_001644f0 =====

undefined8 FUN_001644f0(undefined8 param_1,undefined4 param_2,long param_3)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  long local_20;
  
  local_20 = 0;
  if ((param_3 == 0) || ((int)param_1 == 0)) {
    return 2;
  }
  uVar3 = FUN_001390b0(param_1,&local_20);
  if ((int)uVar3 == 0) {
    lVar1 = *(long *)(*(long *)(local_20 + 0x1e0) + 0x256d8);
    if (((lVar1 == 0) || (*(long *)(lVar1 + 0x70) == 0)) ||
       (pcVar2 = *(code **)(*(long *)(lVar1 + 0x70) + 0x10), pcVar2 == (code *)0x0)) {
      return 3;
    }
    uVar3 = (*pcVar2)(lVar1,*(long *)(local_20 + 0x1e0),*(undefined4 *)(local_20 + 0xc),param_2,
                      param_3);
  }
  return uVar3;
}


// ===== 00164580 nvmlVgpuInstanceGetAccountingStats =====

int nvmlVgpuInstanceGetAccountingStats(undefined4 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d, %d, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x4a0,"nvmlVgpuInstanceGetAccountingStats",
                 "(nvmlVgpuInstance_t vgpuInstance, unsigned int pid, nvmlAccountingStats_t *stats)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001644f0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x4a0,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x4a0,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00164750 FUN_00164750 =====

undefined8 FUN_00164750(undefined8 param_1)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  long local_10;
  
  uVar3 = 2;
  local_10 = 0;
  if ((int)param_1 != 0) {
    uVar3 = FUN_001390b0(param_1,&local_10);
    if ((int)uVar3 == 0) {
      lVar1 = *(long *)(*(long *)(local_10 + 0x1e0) + 0x256d8);
      if (((lVar1 == 0) || (*(long *)(lVar1 + 0x70) == 0)) ||
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x70) + 0x28), pcVar2 == (code *)0x0)) {
        return 3;
      }
      uVar3 = (*pcVar2)(lVar1,*(long *)(local_10 + 0x1e0),*(undefined4 *)(local_10 + 0xc));
    }
  }
  return uVar3;
}


// ===== 001647c0 nvmlVgpuInstanceClearAccountingPids =====

int nvmlVgpuInstanceClearAccountingPids(char *param_1)

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
    param_1 = "(nvmlVgpuInstance_t vgpuInstance)";
    FUN_002340f0((double)(fVar5 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%d)\n","DEBUG",lVar3,
                 "entry_points.h",0x4a5,"nvmlVgpuInstanceClearAccountingPids");
  }
  iVar1 = FUN_0011fea0(param_1);
  if (iVar1 == 0) {
    iVar1 = FUN_00164750(uVar4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x4a5,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x4a5,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00164990 FUN_00164990 =====

int FUN_00164990(int *param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  long local_20;
  
  local_20 = 0;
  if (param_1 == (int *)0x0) {
    return 2;
  }
  if (param_1[1] == 0) {
    return 2;
  }
  if (*param_1 != 0x100000c) {
    return 0x19;
  }
  if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x28) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0xb8), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(DAT_012164a0,param_1[1],&local_20);
    if (iVar2 == 0) {
      if (param_1[1] == 0) {
        iVar2 = 2;
      }
      else {
        iVar2 = FUN_00138f40(param_1[1],local_20);
        if (iVar2 == 0) {
          if (*(int *)(local_20 + 0x308) != 0) {
            param_1[2] = *(int *)(local_20 + 0x308);
            return 0;
          }
          param_1[2] = -1;
          return 3;
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0x2ff6;
      uVar4 = 0x2ff6;
      goto LAB_00164aab;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  fVar5 = fVar5 * DAT_00298548;
  uVar6 = 0x2ff4;
  uVar4 = 0x2ff4;
LAB_00164aab:
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,"api.c",
               uVar4,"tsapiVgpuTypeGetMaxInstancesPerGpuInstance",uVar6,iVar2);
  return iVar2;
}


// ===== 00164b70 nvmlVgpuTypeGetMaxInstancesPerGpuInstance =====

int nvmlVgpuTypeGetMaxInstancesPerGpuInstance(char *param_1)

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
    pcVar5 = "(nvmlVgpuTypeMaxInstance_t *maxInstance)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x6ff,"nvmlVgpuTypeGetMaxInstancesPerGpuInstance");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_00164990(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x6ff,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x6ff,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00164d40 FUN_00164d40 =====

undefined8 FUN_00164d40(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x28) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0x70),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00164d78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1,param_2);
    return uVar1;
  }
  return 3;
}


// ===== 00164da0 nvmlGpuInstanceGetActiveVgpus =====

int nvmlGpuInstanceGetActiveVgpus(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x704,"nvmlGpuInstanceGetActiveVgpus",
                 "(nvmlGpuInstance_t gpuInstance, nvmlActiveVgpuInstanceInfo_t *pVgpuInstanceInfo)",
                 param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00164d40(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x704,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x704,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00164f80 FUN_00164f80 =====

undefined8 FUN_00164f80(undefined8 *param_1,long param_2)

{
  char *pcVar1;
  undefined8 uVar2;
  
  if (((((param_1 != (undefined8 *)0x0) && (param_2 != 0)) &&
       (pcVar1 = (char *)*param_1, pcVar1 != (char *)0x0)) &&
      ((*pcVar1 == '\x01' ||
       (((*(int *)(pcVar1 + 0x14) != 0 && (*(int *)(pcVar1 + 0x1c) == 0)) &&
        ((*(int *)(pcVar1 + 0x10) != 0 && (*(long *)(pcVar1 + 0x20) != 0)))))))) &&
     (*(int *)(param_1 + 1) != -1)) {
    uVar2 = FUN_00137e30();
    return uVar2;
  }
  return 2;
}


// ===== 00164fd0 nvmlGpuInstanceSetVgpuSchedulerState =====

int nvmlGpuInstanceSetVgpuSchedulerState(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x709,"nvmlGpuInstanceSetVgpuSchedulerState",
                 "(nvmlGpuInstance_t gpuInstance, nvmlVgpuSchedulerState_t *pSchedulerState)",
                 param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00164f80(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x709,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x709,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001651b0 FUN_001651b0 =====

undefined8 FUN_001651b0(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = FUN_00137f40();
    return uVar1;
  }
  return 2;
}


// ===== 001651d0 nvmlGpuInstanceGetVgpuSchedulerState =====

int nvmlGpuInstanceGetVgpuSchedulerState(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x70e,"nvmlGpuInstanceGetVgpuSchedulerState",
                 "(nvmlGpuInstance_t gpuInstance, nvmlVgpuSchedulerStateInfo_t *pSchedulerStateInfo)"
                 ,param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001651b0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x70e,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x70e,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001653b0 FUN_001653b0 =====

undefined8 FUN_001653b0(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = FUN_00138050();
    return uVar1;
  }
  return 2;
}


// ===== 001653d0 nvmlGpuInstanceGetVgpuSchedulerLog =====

int nvmlGpuInstanceGetVgpuSchedulerLog(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x713,"nvmlGpuInstanceGetVgpuSchedulerLog",
                 "(nvmlGpuInstance_t gpuInstance, nvmlVgpuSchedulerLogInfo_t *pSchedulerLogInfo)",
                 param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001653b0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x713,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x713,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001655b0 FUN_001655b0 =====

undefined8 FUN_001655b0(long param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x28) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0x78),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001655e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1,param_2);
    return uVar1;
  }
  return 3;
}


// ===== 00165610 nvmlGpuInstanceGetVgpuTypeCreatablePlacements =====

int nvmlGpuInstanceGetVgpuTypeCreatablePlacements(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x718,"nvmlGpuInstanceGetVgpuTypeCreatablePlacements",
                 "(nvmlGpuInstance_t gpuInstance, nvmlVgpuCreatablePlacementInfo_t *pCreatablePlacementInfo)"
                 ,param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001655b0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x718,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x718,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001657f0 FUN_001657f0 =====

undefined8 FUN_001657f0(undefined8 param_1,undefined8 param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x28) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0x80),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00165821. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1,param_2);
    return uVar1;
  }
  return 3;
}


// ===== 00165830 nvmlGpuInstanceSetVgpuHeterogeneousMode =====

int nvmlGpuInstanceSetVgpuHeterogeneousMode(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x71d,"nvmlGpuInstanceSetVgpuHeterogeneousMode",
                 "(nvmlGpuInstance_t gpuInstance, const nvmlVgpuHeterogeneousMode_t *pHeterogeneousMode)"
                 ,param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001657f0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x71d,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x71d,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00165a10 FUN_00165a10 =====

undefined8 FUN_00165a10(undefined8 param_1,undefined8 param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x28) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0x88),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00165a41. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1,param_2);
    return uVar1;
  }
  return 3;
}


// ===== 00165a50 nvmlGpuInstanceGetVgpuHeterogeneousMode =====

int nvmlGpuInstanceGetVgpuHeterogeneousMode(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x722,"nvmlGpuInstanceGetVgpuHeterogeneousMode",
                 "(nvmlGpuInstance_t gpuInstance, nvmlVgpuHeterogeneousMode_t *pHeterogeneousMode)",
                 param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00165a10(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x722,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x722,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00165c30 FUN_00165c30 =====

undefined8 FUN_00165c30(long param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x28) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x28) + 0x90),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00165c5a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 00165c70 nvmlDeviceGetVgpuSchedulerState_v2 =====

int nvmlDeviceGetVgpuSchedulerState_v2(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x729,"nvmlDeviceGetVgpuSchedulerState_v2",
                 "(nvmlDevice_t device, nvmlVgpuSchedulerStateInfo_v2_t *pSchedulerStateInfo)",
                 param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00165c30(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x729,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x729,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00165e50 thunk_FUN_00138160 =====

undefined4 thunk_FUN_00138160(undefined8 *param_1,long param_2)

{
  char *pcVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  
  do {
    iVar3 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar3 != 0);
  if (((param_1 != (undefined8 *)0x0) && (param_2 != 0)) &&
     (puVar5 = DAT_01216970, (undefined8 **)DAT_01216970 != &DAT_01216970)) {
    do {
      if (param_1 == puVar5 + -0x12) {
        pcVar1 = (char *)*param_1;
        if (pcVar1 != (char *)0x0) {
          if ((*pcVar1 == '\x01') ||
             (((uVar4 = 2, *(int *)(pcVar1 + 0x14) != 0 && (*(int *)(pcVar1 + 0x1c) == 0)) &&
              ((*(int *)(pcVar1 + 0x10) != 0 && (*(long *)(pcVar1 + 0x20) != 0)))))) {
            if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x30) == 0)) ||
               (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0x128), pcVar2 == (code *)0x0))
            {
              uVar4 = 3;
            }
            else {
              uVar4 = (*pcVar2)(DAT_012164a0,param_1,param_2);
            }
          }
          goto LAB_0013824e;
        }
        break;
      }
      puVar5 = (undefined8 *)*puVar5;
    } while ((undefined8 **)puVar5 != &DAT_01216970);
  }
  uVar4 = 2;
LAB_0013824e:
  FUN_00291830(&DAT_01216990,0);
  return uVar4;
}


// ===== 00165e60 nvmlGpuInstanceGetVgpuSchedulerState_v2 =====

int nvmlGpuInstanceGetVgpuSchedulerState_v2(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x72e,"nvmlGpuInstanceGetVgpuSchedulerState_v2",
                 "(nvmlGpuInstance_t gpuInstance, nvmlVgpuSchedulerStateInfo_v2_t *pSchedulerStateInfo)"
                 ,param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_00138160(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x72e,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x72e,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00166040 FUN_00166040 =====

undefined8 FUN_00166040(long param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x28) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x28) + 0x98),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0016606a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 00166080 nvmlDeviceGetVgpuSchedulerLog_v2 =====

int nvmlDeviceGetVgpuSchedulerLog_v2(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x733,"nvmlDeviceGetVgpuSchedulerLog_v2",
                 "(nvmlDevice_t device, nvmlVgpuSchedulerLogInfo_v2_t *pSchedulerLogInfo)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00166040(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x733,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x733,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00166260 thunk_FUN_00138280 =====

undefined4 thunk_FUN_00138280(undefined8 *param_1,long param_2)

{
  char *pcVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  
  do {
    iVar3 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar3 != 0);
  if (((param_1 != (undefined8 *)0x0) && (param_2 != 0)) &&
     (puVar5 = DAT_01216970, (undefined8 **)DAT_01216970 != &DAT_01216970)) {
    do {
      if (param_1 == puVar5 + -0x12) {
        pcVar1 = (char *)*param_1;
        if (pcVar1 != (char *)0x0) {
          if ((*pcVar1 == '\x01') ||
             (((uVar4 = 2, *(int *)(pcVar1 + 0x14) != 0 && (*(int *)(pcVar1 + 0x1c) == 0)) &&
              ((*(int *)(pcVar1 + 0x10) != 0 && (*(long *)(pcVar1 + 0x20) != 0)))))) {
            if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x30) == 0)) ||
               (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0x130), pcVar2 == (code *)0x0))
            {
              uVar4 = 3;
            }
            else {
              uVar4 = (*pcVar2)(DAT_012164a0,param_1,param_2);
            }
          }
          goto LAB_0013836e;
        }
        break;
      }
      puVar5 = (undefined8 *)*puVar5;
    } while ((undefined8 **)puVar5 != &DAT_01216970);
  }
  uVar4 = 2;
LAB_0013836e:
  FUN_00291830(&DAT_01216990,0);
  return uVar4;
}


// ===== 00166270 nvmlGpuInstanceGetVgpuSchedulerLog_v2 =====

int nvmlGpuInstanceGetVgpuSchedulerLog_v2(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x738,"nvmlGpuInstanceGetVgpuSchedulerLog_v2",
                 "(nvmlGpuInstance_t gpuInstance, nvmlVgpuSchedulerLogInfo_v2_t *pSchedulerLogInfo)"
                 ,param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_00138280(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x738,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x738,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00166450 FUN_00166450 =====

undefined8 FUN_00166450(long param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x28) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x28) + 0xa0),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0016647a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 00166490 nvmlDeviceSetVgpuSchedulerState_v2 =====

int nvmlDeviceSetVgpuSchedulerState_v2(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x73d,"nvmlDeviceSetVgpuSchedulerState_v2",
                 "(nvmlDevice_t device, nvmlVgpuSchedulerState_v2_t *pSchedulerState)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00166450(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x73d,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x73d,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00166670 thunk_FUN_001383a0 =====

undefined4 thunk_FUN_001383a0(undefined8 *param_1,long param_2)

{
  char *pcVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  
  do {
    iVar3 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar3 != 0);
  if (((param_1 != (undefined8 *)0x0) && (param_2 != 0)) &&
     (puVar5 = DAT_01216970, (undefined8 **)DAT_01216970 != &DAT_01216970)) {
    do {
      if (param_1 == puVar5 + -0x12) {
        pcVar1 = (char *)*param_1;
        if (pcVar1 != (char *)0x0) {
          if ((*pcVar1 == '\x01') ||
             (((uVar4 = 2, *(int *)(pcVar1 + 0x14) != 0 && (*(int *)(pcVar1 + 0x1c) == 0)) &&
              ((*(int *)(pcVar1 + 0x10) != 0 && (*(long *)(pcVar1 + 0x20) != 0)))))) {
            if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x30) == 0)) ||
               (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0x138), pcVar2 == (code *)0x0))
            {
              uVar4 = 3;
            }
            else {
              uVar4 = (*pcVar2)(DAT_012164a0,param_1,param_2);
            }
          }
          goto LAB_0013848e;
        }
        break;
      }
      puVar5 = (undefined8 *)*puVar5;
    } while ((undefined8 **)puVar5 != &DAT_01216970);
  }
  uVar4 = 2;
LAB_0013848e:
  FUN_00291830(&DAT_01216990,0);
  return uVar4;
}


// ===== 00166680 nvmlGpuInstanceSetVgpuSchedulerState_v2 =====

int nvmlGpuInstanceSetVgpuSchedulerState_v2(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x742,"nvmlGpuInstanceSetVgpuSchedulerState_v2",
                 "(nvmlGpuInstance_t gpuInstance, nvmlVgpuSchedulerState_v2_t *pSchedulerState)",
                 param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_001383a0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x742,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x742,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00166860 FUN_00166860 =====

undefined8 FUN_00166860(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = DAT_01215b68;
    return 0;
  }
  return 2;
}


// ===== 00166890 nvmlGetExcludedDeviceCount =====

int nvmlGetExcludedDeviceCount(char *param_1)

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
                 "entry_points.h",0x4b4,"nvmlGetExcludedDeviceCount");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_00166860(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x4b4,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x4b4,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00166a60 FUN_00166a60 =====

undefined8 FUN_00166a60(uint param_1,undefined8 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  if ((param_1 < DAT_01215b68) && (param_2 != (undefined8 *)0x0)) {
    uVar3 = (ulong)param_1;
    lVar1 = uVar3 * 0x94;
    uVar2 = *(undefined8 *)(lVar1 + 0x12148f0);
    *param_2 = *(undefined8 *)(&DAT_012148e8 + lVar1);
    param_2[1] = uVar2;
    uVar2 = *(undefined8 *)(&DAT_01214900 + uVar3 * 0x25);
    param_2[2] = *(undefined8 *)(&DAT_012148f8 + uVar3 * 0x25);
    param_2[3] = uVar2;
    uVar2 = *(undefined8 *)(lVar1 + 0x1214910);
    param_2[4] = *(undefined8 *)(&DAT_01214908 + lVar1);
    param_2[5] = uVar2;
    uVar2 = *(undefined8 *)(lVar1 + 0x1214920);
    param_2[6] = *(undefined8 *)(&DAT_01214918 + lVar1);
    param_2[7] = uVar2;
    uVar2 = *(undefined8 *)(lVar1 + 0x1214930);
    param_2[8] = *(undefined8 *)(&DAT_01214928 + lVar1);
    param_2[9] = uVar2;
    uVar2 = *(undefined8 *)(lVar1 + 0x1214940);
    param_2[10] = *(undefined8 *)(&DAT_01214938 + lVar1);
    param_2[0xb] = uVar2;
    uVar2 = *(undefined8 *)(lVar1 + 0x1214950);
    param_2[0xc] = *(undefined8 *)(&DAT_01214948 + lVar1);
    param_2[0xd] = uVar2;
    uVar2 = *(undefined8 *)(lVar1 + 0x1214960);
    param_2[0xe] = *(undefined8 *)(&DAT_01214958 + lVar1);
    param_2[0xf] = uVar2;
    uVar2 = *(undefined8 *)(lVar1 + 0x1214970);
    param_2[0x10] = *(undefined8 *)(&DAT_01214968 + lVar1);
    param_2[0x11] = uVar2;
    *(undefined4 *)(param_2 + 0x12) = *(undefined4 *)(&DAT_01214978 + lVar1);
    return 0;
  }
  return 2;
}


// ===== 00166b00 nvmlGetExcludedDeviceInfoByIndex =====

int nvmlGetExcludedDeviceInfoByIndex(undefined4 param_1,undefined8 param_2)

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
                 "entry_points.h",0x4b9,"nvmlGetExcludedDeviceInfoByIndex",
                 "(unsigned int index, nvmlExcludedDeviceInfo_t *info)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00166a60(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x4b9,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x4b9,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00166ce0 FUN_00166ce0 =====

undefined8 FUN_00166ce0(char *param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (((param_2 != 0) && (param_1 != (char *)0x0)) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 400) != (undefined8 *)0x0)) &&
       (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar1 + 400),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00166d34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00166d60 nvmlDeviceReadWritePRM_v1 =====

int nvmlDeviceReadWritePRM_v1(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x4bf,"nvmlDeviceReadWritePRM_v1",
                 "(nvmlDevice_t device, nvmlPRMTLV_v1_t *buffer)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00166ce0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x4bf,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x4bf,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00166f40 FUN_00166f40 =====

undefined8 FUN_00166f40(char *param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (((param_2 != 0) && (param_1 != (char *)0x0)) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 400) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 400) + 8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00166f95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00166fc0 nvmlDeviceReadPRMCounters_v1 =====

int nvmlDeviceReadPRMCounters_v1(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x4c5,"nvmlDeviceReadPRMCounters_v1",
                 "(nvmlDevice_t device, nvmlPRMCounterList_v1_t *counterList)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00166f40(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x4c5,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x4c5,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001671a0 thunk_FUN_00166860 =====

undefined8 thunk_FUN_00166860(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = DAT_01215b68;
    return 0;
  }
  return 2;
}


// ===== 001671b0 nvmlGetBlacklistDeviceCount =====

int nvmlGetBlacklistDeviceCount(char *param_1)

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
                 "entry_points.h",0x4aa,"nvmlGetBlacklistDeviceCount");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_00166860(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x4aa,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x4aa,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00167380 FUN_00167380 =====

undefined8 FUN_00167380(uint param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  long lVar2;
  ulong uVar3;
  
  if (param_1 < DAT_01215b68) {
    uVar1 = 2;
    if (param_2 != (undefined8 *)0x0) {
      uVar3 = (ulong)param_1;
      lVar2 = uVar3 * 0x94;
      uVar1 = *(undefined8 *)(lVar2 + 0x12148f0);
      *param_2 = *(undefined8 *)(&DAT_012148e8 + lVar2);
      param_2[1] = uVar1;
      uVar1 = *(undefined8 *)(&DAT_01214900 + uVar3 * 0x25);
      param_2[2] = *(undefined8 *)(&DAT_012148f8 + uVar3 * 0x25);
      param_2[3] = uVar1;
      uVar1 = *(undefined8 *)(lVar2 + 0x1214910);
      param_2[4] = *(undefined8 *)(&DAT_01214908 + lVar2);
      param_2[5] = uVar1;
      uVar1 = *(undefined8 *)(lVar2 + 0x1214920);
      param_2[6] = *(undefined8 *)(&DAT_01214918 + lVar2);
      param_2[7] = uVar1;
      *(undefined4 *)(param_2 + 8) = *(undefined4 *)(&DAT_01214928 + lVar2);
      strncpy((char *)((long)param_2 + 0x44),&DAT_0121492c + lVar2,0x4f);
      *(undefined1 *)((long)param_2 + 0x93) = 0;
      uVar1 = 0;
    }
    return uVar1;
  }
  return 2;
}


// ===== 00167420 nvmlGetBlacklistDeviceInfoByIndex =====

int nvmlGetBlacklistDeviceInfoByIndex(undefined4 param_1,undefined8 param_2)

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
                 "entry_points.h",0x4af,"nvmlGetBlacklistDeviceInfoByIndex",
                 "(unsigned int index, nvmlBlacklistDeviceInfo_t *info)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00167380(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x4af,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x4af,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00167600 FUN_00167600 =====

undefined8 FUN_00167600(undefined8 param_1,undefined8 param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 200) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 200) + 0x28),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00167631. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1,param_2);
    return uVar1;
  }
  return 3;
}


// ===== 00167640 nvmlGetVgpuVersion =====

int nvmlGetVgpuVersion(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x4ca,"nvmlGetVgpuVersion",
                 "(nvmlVgpuVersion_t *supported, nvmlVgpuVersion_t * current)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00167600(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x4ca,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x4ca,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00167820 FUN_00167820 =====

undefined8 FUN_00167820(long param_1)

{
  long lVar1;
  long lVar2;
  code *UNRECOVERED_JUMPTABLE;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  uint uVar6;
  
  if (param_1 == 0) {
    return 2;
  }
  if (DAT_01214898 != 0) {
    pcVar5 = &DAT_00380898;
    uVar6 = 0;
    do {
      if (((*pcVar5 == '\x01') ||
          (((((&DAT_003808ac)[(ulong)uVar6 * 0x1d280] != 0 && (*(int *)(pcVar5 + 0x1c) == 0)) &&
            (*(int *)(pcVar5 + 0x10) != 0)) && (*(long *)(pcVar5 + 0x20) != 0)))) &&
         (lVar1 = *(long *)(pcVar5 + 0x25d60), lVar1 != 0)) {
        iVar3 = FUN_00138b90(pcVar5);
        if ((iVar3 == 0) && (*(int *)(lVar1 + 0x628) == 0)) {
          lVar2 = *(long *)(pcVar5 + 0x256d8);
          if (lVar2 == 0) {
            return 3;
          }
          if (*(long *)(lVar2 + 0x28) == 0) {
            return 3;
          }
          UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x28) + 0x48);
          if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
            return 3;
          }
          uVar4 = (*UNRECOVERED_JUMPTABLE)(lVar2,pcVar5);
          if ((int)uVar4 != 0) {
            return uVar4;
          }
          iVar3 = *(int *)(lVar1 + 4);
        }
        else {
          iVar3 = *(int *)(lVar1 + 4);
        }
        if (iVar3 != 0) {
          return 0x13;
        }
      }
      uVar6 = uVar6 + 1;
      pcVar5 = pcVar5 + 0x74a00;
    } while (uVar6 < DAT_01214898);
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 200) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 200) + 0x30),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00167972. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar4 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar4;
  }
  return 3;
}


// ===== 00167980 nvmlSetVgpuVersion =====

int nvmlSetVgpuVersion(char *param_1)

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
    pcVar5 = "(nvmlVgpuVersion_t *vgpuVersion)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x4cf,"nvmlSetVgpuVersion");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_00167820(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x4cf,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x4cf,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00167b50 FUN_00167b50 =====

undefined8 FUN_00167b50(long param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x140) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x140) + 0x48),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00167b7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 00167b90 FUN_00167b90 =====

int FUN_00167b90(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x9a6,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00167b50(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x9a6,iVar1,uVar2);
  return iVar1;
}


// ===== 00167cd0 FUN_00167cd0 =====

undefined8 FUN_00167cd0(long param_1,undefined4 param_2,undefined8 param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x140) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x140) + 0x50),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00167cfc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
    return uVar2;
  }
  return 3;
}


// ===== 00167d10 FUN_00167d10 =====

int FUN_00167d10(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x9ab,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00167cd0(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x9ab,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00167e50 FUN_00167e50 =====

undefined8 FUN_00167e50(long param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x140) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x140) + 0x58),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00167e7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 00167e90 FUN_00167e90 =====

int FUN_00167e90(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x9b0,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00167e50(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x9b0,iVar1,uVar2);
  return iVar1;
}


// ===== 00167fd0 FUN_00167fd0 =====

undefined8 FUN_00167fd0(long param_1)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x140) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x140) + 200),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00167ff7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1);
    return uVar2;
  }
  return 3;
}


// ===== 00168010 FUN_00168010 =====

int FUN_00168010(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0x9ba,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00167fd0(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x9ba,iVar1,uVar2);
  return iVar1;
}


// ===== 00168140 FUN_00168140 =====

undefined8 FUN_00168140(long param_1)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x140) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x140) + 0xd0),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00168167. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1);
    return uVar2;
  }
  return 3;
}


// ===== 00168180 FUN_00168180 =====

int FUN_00168180(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0x9bf,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00168140(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x9bf,iVar1,uVar2);
  return iVar1;
}


// ===== 001682b0 FUN_001682b0 =====

undefined8 FUN_001682b0(char *param_1,undefined4 param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0xb0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00168302. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00168320 FUN_00168320 =====

int FUN_00168320(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u)\n",
                 "DEBUG",lVar3,"entry_points.h",0x9c4,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001682b0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x9c4,iVar1,uVar2);
  return iVar1;
}


// ===== 00168460 FUN_00168460 =====

undefined8 FUN_00168460(undefined8 param_1,long param_2,uint param_3,int param_4)

{
  char *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  if ((param_3 != 0 && param_4 != 0) && (param_2 != 0)) {
    lVar3 = 0;
    while ((pcVar1 = *(char **)(param_2 + lVar3 * 8), pcVar1 != (char *)0x0 &&
           ((*pcVar1 == '\x01' ||
            ((((*(int *)(pcVar1 + 0x14) != 0 && (*(int *)(pcVar1 + 0x1c) == 0)) &&
              (*(int *)(pcVar1 + 0x10) != 0)) && (*(long *)(pcVar1 + 0x20) != 0))))))) {
      lVar3 = lVar3 + 1;
      if (param_3 <= (uint)lVar3) {
        uVar2 = FUN_001278d0(param_1,param_2,param_3,param_4);
        return uVar2;
      }
    }
  }
  return 2;
}


// ===== 001684d0 FUN_001684d0 =====

int FUN_001684d0(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p, %u, %u)\n","DEBUG",lVar3,
                 "entry_points.h",0x9c9,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00168460(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x9c9,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00168620 FUN_00168620 =====

undefined8 FUN_00168620(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = FUN_00127e80();
    return uVar1;
  }
  return 2;
}


// ===== 00168640 FUN_00168640 =====

int FUN_00168640(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x9ce,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00168620(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x9ce,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00168780 FUN_00168780 =====

undefined8 FUN_00168780(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    uVar1 = FUN_00127f20();
    return uVar1;
  }
  return 2;
}


// ===== 001687a0 FUN_001687a0 =====

int FUN_001687a0(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0x9d3,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00168780(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x9d3,iVar1,uVar2);
  return iVar1;
}


// ===== 001688d0 FUN_001688d0 =====

undefined8 FUN_001688d0(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
    return 2;
  }
  if (param_2 != 0) {
    iVar1 = FUN_00236dd0();
    if (iVar1 != 0) {
      uVar2 = FUN_00126080(param_1,param_2);
      return uVar2;
    }
    return 4;
  }
  return 2;
}


// ===== 00168930 FUN_00168930 =====

int FUN_00168930(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x9d8,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001688d0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x9d8,iVar1,uVar2);
  return iVar1;
}


// ===== 00168a70 FUN_00168a70 =====

undefined8 FUN_00168a70(long param_1,int param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
    return 2;
  }
  if (param_2 != 0) {
    iVar1 = FUN_00236dd0();
    if (iVar1 != 0) {
      uVar2 = FUN_001265f0(param_1,param_2);
      return uVar2;
    }
    return 4;
  }
  return 2;
}


// ===== 00168ad0 FUN_00168ad0 =====

int FUN_00168ad0(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d)\n",
                 "DEBUG",lVar3,"entry_points.h",0x9dd,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00168a70(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x9dd,iVar1,uVar2);
  return iVar1;
}


// ===== 00168c10 FUN_00168c10 =====

int FUN_00168c10(undefined8 param_1,char *param_2)

{
  int iVar1;
  long local_20;
  
  local_20 = 0;
  if (((int)param_1 != 0) && (param_2 != (char *)0x0)) {
    iVar1 = FUN_001390b0(param_1,&local_20);
    if (iVar1 == 0) {
      if (*(char *)(local_20 + 0x150) == '\0') {
        return 6;
      }
      strncpy(param_2,(char *)(local_20 + 0x150),0x80);
      param_2[0x7f] = '\0';
    }
    return iVar1;
  }
  return 2;
}


// ===== 00168ca0 FUN_00168ca0 =====

int FUN_00168ca0(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%d, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x777,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00168c10(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x777,iVar1,uVar2);
  return iVar1;
}


// ===== 00168de0 FUN_00168de0 =====

undefined8 FUN_00168de0(char *param_1,long param_2)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x20) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x20) + 0x30),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00168e32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00168e50 FUN_00168e50 =====

int FUN_00168e50(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x9e2,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00168de0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x9e2,iVar1,uVar2);
  return iVar1;
}


// ===== 00168f90 FUN_00168f90 =====

undefined8 FUN_00168f90(char *param_1,long param_2)

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
    if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0x88) != (undefined8 *)0x0)) &&
       (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar1 + 0x88),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00168fe4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00169010 FUN_00169010 =====

int FUN_00169010(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x9e7,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00168f90(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x9e7,iVar1,uVar2);
  return iVar1;
}


// ===== 00169150 FUN_00169150 =====

undefined8 FUN_00169150(char *param_1,long param_2)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x88) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x88) + 8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001691a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 001691d0 FUN_001691d0 =====

int FUN_001691d0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x9ec,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00169150(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x9ec,iVar1,uVar2);
  return iVar1;
}


// ===== 00169310 FUN_00169310 =====

int FUN_00169310(char *param_1,undefined8 *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  ulong uVar4;
  char *pcVar5;
  undefined8 *puVar6;
  long lVar7;
  byte bVar8;
  float fVar9;
  
  bVar8 = 0;
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((iVar2 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (param_2 == (undefined8 *)0x0) {
      return 2;
    }
    if (*(int *)(param_1 + 0x25554) == 0) {
      do {
        iVar2 = FUN_00291820(param_1 + 0x25558,1,0);
      } while (iVar2 != 0);
      if (*(int *)(param_1 + 0x25554) == 0) {
        lVar7 = *(long *)(param_1 + 0x256d8);
        uVar3 = 3;
        if (((lVar7 != 0) && (*(undefined8 **)(lVar7 + 0x168) != (undefined8 *)0x0)) &&
           (pcVar1 = (code *)**(undefined8 **)(lVar7 + 0x168), pcVar1 != (code *)0x0)) {
          uVar3 = (*pcVar1)(lVar7,param_1,param_1 + 0x253d0);
        }
        *(undefined4 *)(param_1 + 0x2555c) = uVar3;
        param_1[0x25554] = '\x01';
        param_1[0x25555] = '\0';
        param_1[0x25556] = '\0';
        param_1[0x25557] = '\0';
      }
      FUN_00291830(param_1 + 0x25558,0);
    }
    iVar2 = *(int *)(param_1 + 0x2555c);
    if (iVar2 == 0) {
      *param_2 = *(undefined8 *)(param_1 + 0x253d0);
      *(undefined8 *)((long)param_2 + 0x17c) = *(undefined8 *)(param_1 + 0x2554c);
      lVar7 = (long)param_2 - (long)((ulong)(param_2 + 1) & 0xfffffffffffffff8);
      pcVar5 = param_1 + (0x253d0 - lVar7);
      puVar6 = (undefined8 *)((ulong)(param_2 + 1) & 0xfffffffffffffff8);
      for (uVar4 = (ulong)((int)lVar7 + 0x184U >> 3); uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar6 = *(undefined8 *)pcVar5;
        pcVar5 = pcVar5 + ((ulong)bVar8 * -2 + 1) * 8;
        puVar6 = puVar6 + (ulong)bVar8 * -2 + 1;
      }
    }
    else if (1 < DAT_01216a78) {
      fVar9 = (float)FUN_002917b0(&DAT_01216a60);
      lVar7 = syscall(0xba);
      FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar7,"api.c",0x31e9,"tsapiDeviceGetClockSlidersInfo",0x31e9,iVar2);
    }
  }
  return iVar2;
}


// ===== 001694e0 FUN_001694e0 =====

int FUN_001694e0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x9f1,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00169310(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x9f1,iVar1,uVar2);
  return iVar1;
}


// ===== 00169620 FUN_00169620 =====

undefined8 FUN_00169620(char *param_1,long param_2)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x168) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x168) + 8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00169675. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 001696a0 FUN_001696a0 =====

int FUN_001696a0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x9f5,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00169620(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x9f5,iVar1,uVar2);
  return iVar1;
}


// ===== 001697e0 FUN_001697e0 =====

undefined8 FUN_001697e0(char *param_1,long param_2)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x168) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x168) + 0x10),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00169835. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00169860 FUN_00169860 =====

int FUN_00169860(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x9f9,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001697e0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x9f9,iVar1,uVar2);
  return iVar1;
}


// ===== 001699a0 FUN_001699a0 =====

undefined8 FUN_001699a0(char *param_1,long param_2)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x78) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x78) + 0x10),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001699f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00169a10 nvmlDeviceGetModuleId =====

int nvmlDeviceGetModuleId(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x89,"nvmlDeviceGetModuleId",
                 "(nvmlDevice_t device, unsigned int *moduleId)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001699a0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x89,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x89,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00169bf0 FUN_00169bf0 =====

undefined8 FUN_00169bf0(long param_1)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x140) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x140) + 0xf8),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00169c17. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1);
    return uVar2;
  }
  return 3;
}


// ===== 00169c30 FUN_00169c30 =====

int FUN_00169c30(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0xa03,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00169bf0(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xa03,iVar1,uVar2);
  return iVar1;
}


// ===== 00169d60 FUN_00169d60 =====

int FUN_00169d60(char *param_1,uint param_2,int *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  float fVar6;
  undefined8 uVar7;
  char *local_50 [2];
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined4 uStack_2c;
  
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
  if (param_3 == (int *)0x0) {
    return 2;
  }
  lVar4 = *(long *)(param_1 + 0x256d8);
  local_50[0] = param_1;
  if (((lVar4 == 0) || (*(long *)(lVar4 + 0x30) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(lVar4 + 0x30) + 8), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar4,param_1,param_2);
    if (iVar2 == 0) {
      lVar4 = *(long *)(local_50[0] + 0x256d8);
      if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x30) == (undefined8 *)0x0)) ||
         (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x30), pcVar1 == (code *)0x0)) {
        iVar2 = 3;
      }
      else {
        iVar2 = (*pcVar1)(lVar4,local_50[0],&local_38,&local_34);
        if (iVar2 == 0) {
          if (local_38 != local_34) {
            iVar2 = FUN_00168460(&local_30,local_50,1,1);
            if (iVar2 == 0) {
              if (*(int *)CONCAT44(uStack_2c,local_30) == 1) {
                FUN_00168780();
                iVar2 = FUN_00151aa0(1,local_50,&local_3c,0,1);
                if (iVar2 == 999) {
                  iVar2 = local_3c;
                }
                *param_3 = iVar2;
                return 0;
              }
              if (1 < DAT_01216a78) {
                fVar6 = (float)FUN_002917b0(&DAT_01216a60);
                lVar4 = syscall(0xba);
                FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                             "ERROR",lVar4,"api.c",0x3251);
                FUN_00168780(CONCAT44(uStack_2c,local_30));
                *param_3 = 10;
                return 0;
              }
              FUN_00168780();
              iVar2 = 10;
            }
            *param_3 = iVar2;
            return 0;
          }
          iVar2 = FUN_0013f160(local_50[0],&local_30);
          if (((iVar2 == 0) && (local_30 == 1)) &&
             ((lVar4 = *(long *)(local_50[0] + 0x256d8), lVar4 != 0 &&
              (lVar3 = *(long *)(lVar4 + 0xa8), lVar3 != 0)))) {
            if (*(code **)(lVar3 + 0x10) != (code *)0x0) {
              (**(code **)(lVar3 + 0x10))(lVar4,local_50[0],0,0,0);
              lVar4 = *(long *)(local_50[0] + 0x256d8);
              if ((lVar4 == 0) || (lVar3 = *(long *)(lVar4 + 0xa8), lVar3 == 0)) goto LAB_00169fc9;
            }
            if (*(code **)(lVar3 + 0x10) != (code *)0x0) {
              (**(code **)(lVar3 + 0x10))(lVar4,local_50[0],1,0,0);
            }
          }
LAB_00169fc9:
          *param_3 = 0;
          return 0;
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      fVar6 = fVar6 * DAT_00298548;
      uVar7 = 0x323f;
      uVar5 = 0x323f;
      goto LAB_00169f1f;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar6 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  fVar6 = fVar6 * DAT_00298548;
  uVar7 = 0x323a;
  uVar5 = 0x323a;
LAB_00169f1f:
  FUN_002340f0((double)fVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,"api.c",
               uVar5,"tsapiDeviceSetMigMode",uVar7,iVar2);
  return iVar2;
}


// ===== 0016a0e0 nvmlDeviceSetMigMode =====

int nvmlDeviceSetMigMode(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x4d9,"nvmlDeviceSetMigMode",
                 "(nvmlDevice_t device, unsigned int mode, nvmlReturn_t *activationStatus)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00169d60(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x4d9,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x4d9,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016a2b0 FUN_0016a2b0 =====

undefined8 FUN_0016a2b0(char *param_1,long param_2,long param_3)

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
    if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0x30) != (undefined8 *)0x0)) &&
       (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar1 + 0x30),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0016a309. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0016a330 nvmlDeviceGetMigMode =====

int nvmlDeviceGetMigMode(undefined8 param_1,undefined8 param_2,undefined8 param_3)

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
                 "entry_points.h",0x4de,"nvmlDeviceGetMigMode",
                 "(nvmlDevice_t device, unsigned int *currentMode, unsigned int *pendingMode)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016a2b0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x4de,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x4de,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016a500 FUN_0016a500 =====

undefined8 FUN_0016a500(char *param_1,uint param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined4 local_b8;
  undefined8 local_b4;
  undefined8 local_ac;
  undefined8 local_a4;
  undefined8 local_9c;
  undefined8 local_94;
  undefined8 local_88;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((uVar1 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if ((param_3 == (undefined8 *)0x0) || (0x11 < param_2)) {
      return 2;
    }
    local_b8 = 0x2000098;
    uVar1 = FUN_001358e0(param_1,param_2,&local_b8);
    if ((int)uVar1 == 0) {
      *param_3 = local_b4;
      param_3[1] = local_ac;
      param_3[2] = local_a4;
      param_3[3] = local_9c;
      param_3[4] = local_94;
      param_3[5] = local_88;
    }
  }
  return uVar1;
}


// ===== 0016a5d0 nvmlDeviceGetGpuInstanceProfileInfo =====

int nvmlDeviceGetGpuInstanceProfileInfo(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x4e3,"nvmlDeviceGetGpuInstanceProfileInfo",
                 "(nvmlDevice_t device, unsigned int profile, nvmlGpuInstanceProfileInfo_t *info)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016a500(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x4e3,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x4e3,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016a7a0 FUN_0016a7a0 =====

undefined8 FUN_0016a7a0(char *param_1,uint param_2,uint *param_3)

{
  undefined8 uVar1;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) &&
      (((param_3 != (uint *)0x0 && (param_2 < 0x12)) && ((*param_3 & 0xfeffffff) == 0x2000098))))))
  {
    uVar1 = FUN_001358e0();
    return uVar1;
  }
  return 2;
}


// ===== 0016a7f0 nvmlDeviceGetGpuInstanceProfileInfoV =====

int nvmlDeviceGetGpuInstanceProfileInfoV(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x4e8,"nvmlDeviceGetGpuInstanceProfileInfoV",
                 "(nvmlDevice_t device, unsigned int profile, nvmlGpuInstanceProfileInfo_v2_t *info)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016a7a0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x4e8,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x4e8,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016a9c0 FUN_0016a9c0 =====

undefined8 FUN_0016a9c0(char *param_1,undefined8 param_2,uint *param_3)

{
  undefined8 uVar1;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) &&
      ((param_3 != (uint *)0x0 && ((*param_3 & 0xfeffffff) == 0x2000098)))))) {
    uVar1 = FUN_00135950();
    return uVar1;
  }
  return 2;
}


// ===== 0016aa10 nvmlDeviceGetGpuInstanceProfileInfoByIdV =====

int nvmlDeviceGetGpuInstanceProfileInfoByIdV
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
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %u, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x4ed,"nvmlDeviceGetGpuInstanceProfileInfoByIdV",
                 "(nvmlDevice_t device, unsigned int profileId, nvmlGpuInstanceProfileInfo_v2_t *info)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016a9c0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x4ed,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x4ed,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016abe0 FUN_0016abe0 =====

undefined8 FUN_0016abe0(char *param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_3 != 0)))
     ) {
    uVar1 = FUN_001359c0();
    return uVar1;
  }
  return 2;
}


// ===== 0016ac20 nvmlDeviceGetGpuInstanceRemainingCapacity =====

int nvmlDeviceGetGpuInstanceRemainingCapacity
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
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %u, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x4f2,"nvmlDeviceGetGpuInstanceRemainingCapacity",
                 "(nvmlDevice_t device, unsigned int profileId, unsigned int *count)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016abe0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x4f2,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x4f2,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016adf0 FUN_0016adf0 =====

undefined8 FUN_0016adf0(char *param_1,undefined4 param_2,long param_3,long param_4)

{
  undefined8 uVar1;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) &&
      ((param_3 != 0 && (param_4 != 0)))))) {
    uVar1 = FUN_00135a50(1,param_1,param_2,param_3,param_4);
    return uVar1;
  }
  return 2;
}


// ===== 0016ae50 nvmlDeviceGetGpuInstancePossiblePlacements =====

int nvmlDeviceGetGpuInstancePossiblePlacements
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
                 ,"entry_points.h",0x4f7,"nvmlDeviceGetGpuInstancePossiblePlacements",
                 "(nvmlDevice_t device, unsigned int profileId, nvmlGpuInstancePlacement_t *placements, unsigned int *count)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016adf0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x4f7,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x4f7,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016b040 FUN_0016b040 =====

undefined8 FUN_0016b040(char *param_1,undefined4 param_2,undefined8 param_3,long param_4)

{
  undefined8 uVar1;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_4 != 0)))
     ) {
    uVar1 = FUN_00135a50(2,param_1,param_2,param_3,param_4);
    return uVar1;
  }
  return 2;
}


// ===== 0016b090 nvmlDeviceGetGpuInstancePossiblePlacements_v2 =====

int nvmlDeviceGetGpuInstancePossiblePlacements_v2
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
                 ,"entry_points.h",0x4fc,"nvmlDeviceGetGpuInstancePossiblePlacements_v2",
                 "(nvmlDevice_t device, unsigned int profileId, nvmlGpuInstancePlacement_t *placements, unsigned int *count)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016b040(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x4fc,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x4fc,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016b280 FUN_0016b280 =====

undefined8 FUN_0016b280(char *param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_3 != 0)))
     ) {
    uVar1 = FUN_00135c90(param_1,param_2,0);
    return uVar1;
  }
  return 2;
}


// ===== 0016b2c0 nvmlDeviceCreateGpuInstance =====

int nvmlDeviceCreateGpuInstance(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x501,"nvmlDeviceCreateGpuInstance",
                 "(nvmlDevice_t device, unsigned int profileId, nvmlGpuInstance_t *gpuInstance)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016b280(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x501,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x501,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016b490 FUN_0016b490 =====

undefined8 FUN_0016b490(char *param_1,undefined8 param_2,long param_3,long param_4)

{
  undefined8 uVar1;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) &&
      ((param_3 != 0 && (param_4 != 0)))))) {
    uVar1 = FUN_00135c90();
    return uVar1;
  }
  return 2;
}


// ===== 0016b4e0 nvmlDeviceCreateGpuInstanceWithPlacement =====

int nvmlDeviceCreateGpuInstanceWithPlacement
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
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %d, %p, %p)\n","DEBUG",lVar3
                 ,"entry_points.h",0x506,"nvmlDeviceCreateGpuInstanceWithPlacement",
                 "(nvmlDevice_t device, unsigned int profileId, const nvmlGpuInstancePlacement_t *placement, nvmlGpuInstance_t *gpuInstance)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016b490(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x506,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x506,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016b6d0 FUN_0016b6d0 =====

undefined8 FUN_0016b6d0(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    uVar1 = FUN_00135e30();
    return uVar1;
  }
  return 2;
}


// ===== 0016b6f0 nvmlGpuInstanceDestroy =====

int nvmlGpuInstanceDestroy(char *param_1)

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
    pcVar5 = "(nvmlGpuInstance_t gpuInstance)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x50b,"nvmlGpuInstanceDestroy");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_0016b6d0(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x50b,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x50b,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0016b8c0 FUN_0016b8c0 =====

undefined8 FUN_0016b8c0(char *param_1,undefined8 param_2,long param_3,long param_4)

{
  undefined8 uVar1;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) &&
      ((param_3 != 0 && (param_4 != 0)))))) {
    uVar1 = FUN_001360a0();
    return uVar1;
  }
  return 2;
}


// ===== 0016b910 nvmlDeviceGetGpuInstances =====

int nvmlDeviceGetGpuInstances
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
                 ,"entry_points.h",0x510,"nvmlDeviceGetGpuInstances",
                 "(nvmlDevice_t device, unsigned int profileId, nvmlGpuInstance_t *instances, unsigned int *count)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016b8c0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x510,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x510,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016bb00 FUN_0016bb00 =====

undefined8 FUN_0016bb00(char *param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_3 != 0)))
     ) {
    uVar1 = FUN_00136210();
    return uVar1;
  }
  return 2;
}


// ===== 0016bb40 nvmlDeviceGetGpuInstanceById =====

int nvmlDeviceGetGpuInstanceById(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x51a,"nvmlDeviceGetGpuInstanceById",
                 "(nvmlDevice_t device, unsigned int id, nvmlGpuInstance_t *gpuInstance)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016bb00(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x51a,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x51a,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016bd10 FUN_0016bd10 =====

undefined8 FUN_0016bd10(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = FUN_00136120();
    return uVar1;
  }
  return 2;
}


// ===== 0016bd30 nvmlGpuInstanceGetInfo =====

int nvmlGpuInstanceGetInfo(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x515,"nvmlGpuInstanceGetInfo",
                 "(nvmlGpuInstance_t gpuInstance, nvmlGpuInstanceInfo_t *info)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016bd10(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x515,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x515,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0016bf10 FUN_0016bf10 =====

undefined8 FUN_0016bf10(long param_1,uint param_2,int param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  undefined8 local_a4;
  undefined8 local_9c;
  undefined8 local_94;
  undefined8 local_8c;
  undefined4 local_84;
  
  if (param_1 == 0) {
    return 2;
  }
  if (((param_4 != (undefined8 *)0x0) && (param_2 < 8)) && (param_3 == 0)) {
    uVar1 = FUN_001363a0();
    if ((int)uVar1 == 0) {
      *param_4 = local_a4;
      param_4[1] = local_9c;
      param_4[2] = local_94;
      param_4[3] = local_8c;
      *(undefined4 *)(param_4 + 4) = local_84;
    }
    return uVar1;
  }
  return 2;
}


// ===== 0016bfb0 nvmlGpuInstanceGetComputeInstanceProfileInfo =====

int nvmlGpuInstanceGetComputeInstanceProfileInfo
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
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %u, %u, %p)\n","DEBUG",lVar3
                 ,"entry_points.h",0x51f,"nvmlGpuInstanceGetComputeInstanceProfileInfo",
                 "(nvmlGpuInstance_t gpuInstance, unsigned int profile, unsigned int engProfile, nvmlComputeInstanceProfileInfo_t *info)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016bf10(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x51f,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x51f,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016c1a0 FUN_0016c1a0 =====

undefined8 FUN_0016c1a0(long param_1,uint param_2,int param_3,int *param_4)

{
  undefined8 uVar1;
  
  if ((((param_1 != 0) && (param_4 != (int *)0x0)) && (param_2 < 8)) &&
     ((param_3 == 0 && ((*param_4 == 0x2000088 || (*param_4 == 0x300008c)))))) {
    uVar1 = FUN_001363a0(param_1,param_2,0);
    return uVar1;
  }
  return 2;
}


// ===== 0016c1e0 nvmlGpuInstanceGetComputeInstanceProfileInfoV =====

int nvmlGpuInstanceGetComputeInstanceProfileInfoV
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
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %u, %u, %p)\n","DEBUG",lVar3
                 ,"entry_points.h",0x524,"nvmlGpuInstanceGetComputeInstanceProfileInfoV",
                 "(nvmlGpuInstance_t gpuInstance, unsigned int profile, unsigned int engProfile, nvmlComputeInstanceProfileInfo_v2_t *info)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016c1a0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x524,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x524,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016c3d0 FUN_0016c3d0 =====

undefined8 FUN_0016c3d0(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (param_3 != 0)) {
    uVar1 = FUN_00136420();
    return uVar1;
  }
  return 2;
}


// ===== 0016c3f0 nvmlGpuInstanceGetComputeInstanceRemainingCapacity =====

int nvmlGpuInstanceGetComputeInstanceRemainingCapacity
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
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %u, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x529,"nvmlGpuInstanceGetComputeInstanceRemainingCapacity",
                 "(nvmlGpuInstance_t gpuInstance, unsigned int profileId, unsigned int *count)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016c3d0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x529,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x529,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016c5c0 FUN_0016c5c0 =====

undefined8 FUN_0016c5c0(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (param_4 != 0)) {
    uVar1 = FUN_00136530();
    return uVar1;
  }
  return 2;
}


// ===== 0016c5e0 nvmlGpuInstanceGetComputeInstancePossiblePlacements =====

int nvmlGpuInstanceGetComputeInstancePossiblePlacements
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
                 ,"entry_points.h",0x52e,"nvmlGpuInstanceGetComputeInstancePossiblePlacements",
                 "(nvmlGpuInstance_t gpuInstance, unsigned int profileId, nvmlComputeInstancePlacement_t *placements, unsigned int *count)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016c5c0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x52e,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x52e,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016c7d0 FUN_0016c7d0 =====

undefined8 FUN_0016c7d0(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (param_3 != 0)) {
    uVar1 = FUN_00136650(param_1,param_2,0,param_3);
    return uVar1;
  }
  return 2;
}


// ===== 0016c7f0 nvmlGpuInstanceCreateComputeInstance =====

int nvmlGpuInstanceCreateComputeInstance(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x533,"nvmlGpuInstanceCreateComputeInstance",
                 "(nvmlGpuInstance_t gpuInstance, unsigned int profileId, nvmlComputeInstance_t *computeInstance)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016c7d0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x533,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x533,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016c9c0 FUN_0016c9c0 =====

undefined8 FUN_0016c9c0(long param_1,undefined8 param_2,long param_3,long param_4)

{
  undefined8 uVar1;
  
  if ((param_4 != 0 && param_3 != 0) && (param_1 != 0)) {
    uVar1 = FUN_00136650();
    return uVar1;
  }
  return 2;
}


// ===== 0016c9f0 nvmlGpuInstanceCreateComputeInstanceWithPlacement =====

int nvmlGpuInstanceCreateComputeInstanceWithPlacement
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
                 ,"entry_points.h",0x538,"nvmlGpuInstanceCreateComputeInstanceWithPlacement",
                 "(nvmlGpuInstance_t gpuInstance, unsigned int profileId, const nvmlComputeInstancePlacement_t *placement, nvmlComputeInstance_t *computeInstance)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016c9c0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x538,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x538,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016cbe0 FUN_0016cbe0 =====

undefined8 FUN_0016cbe0(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    uVar1 = FUN_00136960();
    return uVar1;
  }
  return 2;
}


// ===== 0016cc00 nvmlComputeInstanceDestroy =====

int nvmlComputeInstanceDestroy(char *param_1)

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
    pcVar5 = "(nvmlComputeInstance_t computeInstance)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x53d,"nvmlComputeInstanceDestroy");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_0016cbe0(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x53d,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x53d,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0016cdd0 FUN_0016cdd0 =====

undefined8 FUN_0016cdd0(long param_1,undefined8 param_2,long param_3,long param_4)

{
  undefined8 uVar1;
  
  if ((param_3 != 0 && param_4 != 0) && (param_1 != 0)) {
    uVar1 = FUN_00136bd0();
    return uVar1;
  }
  return 2;
}


// ===== 0016ce00 nvmlGpuInstanceGetComputeInstances =====

int nvmlGpuInstanceGetComputeInstances
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
                 ,"entry_points.h",0x542,"nvmlGpuInstanceGetComputeInstances",
                 "(nvmlGpuInstance_t gpuInstance, unsigned int profileId, nvmlComputeInstance_t *computeInstances, unsigned int *count)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016cdd0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x542,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x542,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016cff0 FUN_0016cff0 =====

undefined8 FUN_0016cff0(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (param_3 != 0)) {
    uVar1 = FUN_00136c50();
    return uVar1;
  }
  return 2;
}


// ===== 0016d010 nvmlGpuInstanceGetComputeInstanceById =====

int nvmlGpuInstanceGetComputeInstanceById(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x547,"nvmlGpuInstanceGetComputeInstanceById",
                 "(nvmlGpuInstance_t gpuInstance, unsigned int id, nvmlComputeInstance_t *computeInstance)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016cff0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x547,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x547,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0016d1e0 FUN_0016d1e0 =====

undefined8 FUN_0016d1e0(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = FUN_00136e50(1,param_1,param_2);
    return uVar1;
  }
  return 2;
}


// ===== 0016d210 nvmlComputeInstanceGetInfo =====

int nvmlComputeInstanceGetInfo(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x54c,"nvmlComputeInstanceGetInfo",
                 "(nvmlComputeInstance_t computeInstance, nvmlComputeInstanceInfo_t *info)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016d1e0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x54c,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x54c,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0016d3f0 FUN_0016d3f0 =====

undefined8 FUN_0016d3f0(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = FUN_00136e50(2,param_1,param_2);
    return uVar1;
  }
  return 2;
}


// ===== 0016d420 nvmlComputeInstanceGetInfo_v2 =====

int nvmlComputeInstanceGetInfo_v2(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x551,"nvmlComputeInstanceGetInfo_v2",
                 "(nvmlComputeInstance_t computeInstance, nvmlComputeInstanceInfo_t *info)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016d3f0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x551,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x551,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0016d600 FUN_0016d600 =====

undefined8 FUN_0016d600(char *param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  
  if ((param_1 == (char *)0x0) || (param_2 == (undefined4 *)0x0)) {
    return 2;
  }
  if ((*param_1 != '\x01') &&
     ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
       (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) {
    uVar1 = FUN_00137020();
    return uVar1;
  }
  *param_2 = 0;
  return 0;
}


// ===== 0016d650 nvmlDeviceIsMigDeviceHandle =====

int nvmlDeviceIsMigDeviceHandle(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x556,"nvmlDeviceIsMigDeviceHandle",
                 "(nvmlDevice_t device, unsigned int *isMigDevice)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0016d600(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x556,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x556,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0016d830 FUN_0016d830 =====

undefined8 FUN_0016d830(char *param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((((param_1 != (char *)0x0) && (param_2 != 0)) && (*param_1 != '\x01')) &&
     (((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
      ((*(int *)(param_1 + 0x10) == 0 || (*(long *)(param_1 + 0x20) == 0)))))) {
    uVar1 = FUN_001370b0();
    return uVar1;
  }
  return 2;
}


