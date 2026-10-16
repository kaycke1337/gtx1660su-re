// ===== 00193c20 FUN_00193c20 =====

int FUN_00193c20(char *param_1,int *param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  
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
    if (param_2 != (int *)0x0) {
      lVar4 = *(long *)(param_1 + 0x256d8);
      if (((lVar4 == 0) || (*(long *)(lVar4 + 0x170) == 0)) ||
         (pcVar2 = *(code **)(*(long *)(lVar4 + 0x170) + 0x48), pcVar2 == (code *)0x0)) {
        iVar3 = 3;
      }
      else {
        iVar3 = (*pcVar2)(lVar4,param_1,param_2);
        if (iVar3 == 0) {
          iVar3 = FUN_00193b60(param_1);
          if (iVar3 == 0) {
            return 0;
          }
          if (4 < DAT_01216a78) {
            iVar3 = *param_2;
            fVar5 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",
                         "DEBUG",lVar4,"api.c",0xd96,iVar3);
          }
          if (*param_2 != 0) {
            return 0;
          }
          iVar3 = FUN_001385a0(param_1,param_2);
          if (DAT_01216a78 < 5) {
            return iVar3;
          }
          iVar1 = *param_2;
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",
                       "DEBUG",lVar4,"api.c",0xd9b,iVar1);
          return iVar3;
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar3;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"api.c",0xd92,"tsapiDeviceGetPerformanceState",0xd92,iVar3);
      return iVar3;
    }
  }
  return 2;
}


// ===== 00193e70 nvmlDeviceGetPowerState =====

int nvmlDeviceGetPowerState(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0xd9,"nvmlDeviceGetPowerState",
                 "(nvmlDevice_t device, nvmlPstates_t *pState)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00193c20(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xd9,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xd9,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00194050 nvmlDeviceGetPerformanceState =====

int nvmlDeviceGetPerformanceState(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0xdd,"nvmlDeviceGetPerformanceState",
                 "(nvmlDevice_t device, nvmlPstates_t *pState)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00193c20(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xdd,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xdd,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00194230 FUN_00194230 =====

int FUN_00194230(long param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  float fVar5;
  int local_3c [3];
  
  iVar2 = FUN_00175bd0(param_1,local_3c);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_3c[0] == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar4,"api.c",0x1c21);
        }
      }
      else {
        iVar2 = FUN_00193b60(param_1);
        if (iVar2 != 0) {
          iVar2 = FUN_00192940(param_1,local_3c);
          if (iVar2 != 0) {
            return 0;
          }
          uVar3 = 0x99520;
          if (local_3c[0] == 4) {
            uVar3 = 1500000;
          }
          if (uVar3 < param_4) {
            return 2;
          }
          iVar2 = FUN_00236dd0();
          if (iVar2 == 0) {
            return 4;
          }
          lVar4 = *(long *)(param_1 + 0x256d8);
          if (((lVar4 != 0) && (*(long *)(lVar4 + 0x150) != 0)) &&
             (pcVar1 = *(code **)(*(long *)(lVar4 + 0x150) + 8), pcVar1 != (code *)0x0)) {
            iVar2 = (*pcVar1)(lVar4,param_1,param_2,param_3,param_4);
            return iVar2;
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


// ===== 001943a0 FUN_001943a0 =====

int FUN_001943a0(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d, %d, %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x859,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00194230(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x859,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001944f0 FUN_001944f0 =====

int FUN_001944f0(long param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  float fVar5;
  int local_3c [3];
  
  iVar2 = FUN_00175bd0(param_1,local_3c);
  if ((iVar2 != 2) && (iVar2 != 0xf)) {
    if (iVar2 == 0) {
      if (local_3c[0] == 0) {
        iVar2 = 3;
        if (3 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar4,"api.c",0x1c47);
        }
      }
      else {
        iVar2 = FUN_00193b60(param_1);
        if (iVar2 != 0) {
          iVar2 = FUN_00192940(param_1,local_3c);
          if (iVar2 != 0) {
            return 0;
          }
          uVar3 = 0x4ca90;
          if (local_3c[0] == 4) {
            uVar3 = 750000;
          }
          if (uVar3 < param_4) {
            return 2;
          }
          iVar2 = FUN_00236dd0();
          if (iVar2 == 0) {
            return 4;
          }
          lVar4 = *(long *)(param_1 + 0x256d8);
          if (((lVar4 != 0) && (*(long *)(lVar4 + 0x150) != 0)) &&
             (pcVar1 = *(code **)(*(long *)(lVar4 + 0x150) + 0x10), pcVar1 != (code *)0x0)) {
            iVar2 = (*pcVar1)(lVar4,param_1,param_2,param_3,param_4);
            return iVar2;
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


// ===== 00194660 FUN_00194660 =====

int FUN_00194660(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d, %d, %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x85d,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001944f0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x85d,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001947b0 FUN_001947b0 =====

undefined8 FUN_001947b0(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x210),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00194808. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00194830 FUN_00194830 =====

int FUN_00194830(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xabb,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001947b0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xabb,iVar1,uVar2);
  return iVar1;
}


// ===== 00194970 FUN_00194970 =====

undefined8 FUN_00194970(char *param_1,undefined4 param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x218),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001949c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 001949e0 FUN_001949e0 =====

int FUN_001949e0(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u)\n",
                 "DEBUG",lVar3,"entry_points.h",0xac0,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00194970(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xac0,iVar1,uVar2);
  return iVar1;
}


// ===== 00194b20 FUN_00194b20 =====

undefined8 FUN_00194b20(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x158) + 0xa8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00194b78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00194ba0 nvmlDeviceGetGpuFabricInfoV =====

int nvmlDeviceGetGpuFabricInfoV(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x68f,"nvmlDeviceGetGpuFabricInfoV",
                 "(nvmlDevice_t device, nvmlGpuFabricInfoV_t *gpuFabricInfo)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00194b20(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x68f,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x68f,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00194d80 FUN_00194d80 =====

undefined8 FUN_00194d80(char *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined4 local_48;
  undefined8 local_44;
  undefined8 uStack_3c;
  undefined8 local_34;
  undefined1 local_2c;
  
  if ((param_2 != (undefined8 *)0x0) && (param_1 != (char *)0x0)) {
    if ((*param_1 == '\x01') ||
       ((((uVar1 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
      local_48 = 0x2000024;
      uVar1 = FUN_00194b20(param_1,&local_48);
      if ((int)uVar1 == 0) {
        param_2[2] = local_34;
        *param_2 = local_44;
        param_2[1] = uStack_3c;
        *(undefined1 *)(param_2 + 3) = local_2c;
      }
    }
    return uVar1;
  }
  return 2;
}


// ===== 00194e00 nvmlDeviceGetGpuFabricInfo =====

int nvmlDeviceGetGpuFabricInfo(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x689,"nvmlDeviceGetGpuFabricInfo",
                 "(nvmlDevice_t device, nvmlGpuFabricInfo_t *gpuFabricInfo)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00194d80(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x689,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x689,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00194fe0 FUN_00194fe0 =====

undefined8 FUN_00194fe0(char *param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x118) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x118) + 0xb0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00195033. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00195050 nvmlDeviceGetMarginTemperature =====

int nvmlDeviceGetMarginTemperature(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x11f,"nvmlDeviceGetMarginTemperature",
                 "(nvmlDevice_t device, nvmlMarginTemperature_t *marginTempInfo)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00194fe0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x11f,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x11f,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00195230 FUN_00195230 =====

undefined8 FUN_00195230(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x20) + 0x70),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00195282. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 001952a0 nvmlDeviceGetNumaNodeId =====

int nvmlDeviceGetNumaNodeId(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x6a3,"nvmlDeviceGetNumaNodeId",
                 "(nvmlDevice_t device, unsigned int *node)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00195230(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x6a3,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x6a3,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00195480 FUN_00195480 =====

undefined8 FUN_00195480(undefined4 param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_001394e0();
  if (iVar1 == 0) {
    iVar1 = FUN_00236dd0();
    if (iVar1 == 0) {
      return 4;
    }
    if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x158) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x158) + 0xb0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001954d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
      return uVar2;
    }
  }
  return 3;
}


// ===== 00195500 nvmlSystemSetNvlinkBwMode =====

int nvmlSystemSetNvlinkBwMode(char *param_1)

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
    param_1 = "(unsigned int nvlinkBwMode)";
    FUN_002340f0((double)(fVar5 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%u)\n","DEBUG",lVar3,
                 "entry_points.h",0x694,"nvmlSystemSetNvlinkBwMode");
  }
  iVar1 = FUN_0011fea0(param_1);
  if (iVar1 == 0) {
    iVar1 = FUN_00195480(uVar4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x694,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x694,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001956d0 FUN_001956d0 =====

undefined8 FUN_001956d0(undefined8 param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_001394e0();
  if (iVar1 == 0) {
    iVar1 = FUN_00236dd0();
    if (iVar1 == 0) {
      return 4;
    }
    if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x158) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x158) + 0xb8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00195724. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
      return uVar2;
    }
  }
  return 3;
}


// ===== 00195750 nvmlSystemGetNvlinkBwMode =====

int nvmlSystemGetNvlinkBwMode(char *param_1)

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
    pcVar5 = "(unsigned int *nvlinkBwMode)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x698,"nvmlSystemGetNvlinkBwMode");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_001956d0(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x698,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x698,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00195920 FUN_00195920 =====

undefined8 FUN_00195920(char *param_1,undefined8 param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  int local_1c;
  
  local_1c = 0;
  if (param_1 != (char *)0x0) {
    if ((*param_1 == '\x01') ||
       ((((uVar4 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
      iVar3 = FUN_00139230(param_1,&local_1c,0xc);
      uVar4 = 3;
      if ((((iVar3 == 0) && (local_1c != 0)) && (lVar1 = *(long *)(param_1 + 0x256d8), lVar1 != 0))
         && ((*(long *)(lVar1 + 0x170) != 0 &&
             (pcVar2 = *(code **)(*(long *)(lVar1 + 0x170) + 0x228), pcVar2 != (code *)0x0)))) {
        uVar4 = (*pcVar2)(lVar1,param_1,param_2);
      }
    }
    return uVar4;
  }
  return 2;
}


// ===== 001959e0 FUN_001959e0 =====

int FUN_001959e0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xac5,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00195920(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xac5,iVar1,uVar2);
  return iVar1;
}


// ===== 00195b20 thunk_FUN_001395d0 =====

undefined8 thunk_FUN_001395d0(char *param_1,undefined4 param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  int iStack_1c;
  
  iStack_1c = 0;
  if (param_1 != (char *)0x0) {
    if ((*param_1 == '\x01') ||
       ((((uVar4 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
      iVar3 = FUN_00139230(param_1,&iStack_1c,0xc);
      uVar4 = 3;
      if ((((iVar3 == 0) && (iStack_1c != 0)) && (lVar1 = *(long *)(param_1 + 0x256d8), lVar1 != 0))
         && ((*(long *)(lVar1 + 0x170) != 0 &&
             (pcVar2 = *(code **)(*(long *)(lVar1 + 0x170) + 0x230), pcVar2 != (code *)0x0)))) {
        uVar4 = (*pcVar2)(lVar1,param_1,param_2);
      }
    }
    return uVar4;
  }
  return 2;
}


// ===== 00195b30 FUN_00195b30 =====

int FUN_00195b30(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u)\n",
                 "DEBUG",lVar3,"entry_points.h",0xaca,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_001395d0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xaca,iVar1,uVar2);
  return iVar1;
}


// ===== 00195c70 FUN_00195c70 =====

void FUN_00195c70(undefined8 param_1)

{
  FUN_001395d0(param_1,0);
  return;
}


// ===== 00195c80 FUN_00195c80 =====

int FUN_00195c80(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0xacf,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00195c70(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xacf,iVar1,uVar2);
  return iVar1;
}


// ===== 00195db0 FUN_00195db0 =====

int FUN_00195db0(char *param_1,void *param_2,ulong param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  size_t sVar4;
  long lVar5;
  float fVar6;
  
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
      if (*(int *)(param_1 + 0x268) == 0) {
        do {
          iVar2 = FUN_00291820(param_1 + 0x26c,1,0);
        } while (iVar2 != 0);
        if (*(int *)(param_1 + 0x268) == 0) {
          lVar5 = *(long *)(param_1 + 0x256d8);
          uVar3 = 3;
          if (((lVar5 != 0) && (*(long *)(lVar5 + 0x38) != 0)) &&
             (pcVar1 = *(code **)(*(long *)(lVar5 + 0x38) + 0x20), pcVar1 != (code *)0x0)) {
            uVar3 = (*pcVar1)(lVar5,param_1,param_1 + 0x254,0x14);
          }
          *(undefined4 *)(param_1 + 0x270) = uVar3;
          param_1[0x268] = '\x01';
          param_1[0x269] = '\0';
          param_1[0x26a] = '\0';
          param_1[0x26b] = '\0';
        }
        FUN_00291830(param_1 + 0x26c,0);
      }
      iVar2 = *(int *)(param_1 + 0x270);
      if (iVar2 == 0) {
        sVar4 = strlen(param_1 + 0x254);
        if (sVar4 + 1 <= (param_3 & 0xffffffff)) {
          memcpy(param_2,param_1 + 0x254,sVar4 + 1);
          return 0;
        }
        return 7;
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar5,"api.c",0x3b0e,"tsapiDeviceGetGpuFruPartNumber",0x3b0e,iVar2);
      return iVar2;
    }
  }
  return 2;
}


// ===== 00195f90 FUN_00195f90 =====

int FUN_00195f90(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p %d)\n",
                 "DEBUG",lVar3,"entry_points.h",0x92e,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00195db0(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x92e,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001960d0 FUN_001960d0 =====

undefined8 FUN_001960d0(long param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x220),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001960fd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 00196110 FUN_00196110 =====

int FUN_00196110(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xad4,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001960d0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xad4,iVar1,uVar2);
  return iVar1;
}


// ===== 00196250 FUN_00196250 =====

undefined8 FUN_00196250(long param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x158) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x158) + 0xc0),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0019627d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 00196290 FUN_00196290 =====

int FUN_00196290(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa9d,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00196250(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xa9d,iVar1,uVar2);
  return iVar1;
}


// ===== 001963d0 FUN_001963d0 =====

undefined8 FUN_001963d0(long param_1,int *param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (*param_2 != 0x200000c) {
    return 2;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x160) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0x20),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00196409. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,(char)param_2[1],0,param_2[2]);
    return uVar2;
  }
  return 3;
}


// ===== 00196430 nvmlDeviceSetPowerManagementLimit_v2 =====

int nvmlDeviceSetPowerManagementLimit_v2(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x69d,"nvmlDeviceSetPowerManagementLimit_v2",
                 "(nvmlDevice_t device, nvmlPowerValue_v2_t *powerValue)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001963d0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x69d,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x69d,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00196610 FUN_00196610 =====

undefined8 FUN_00196610(char *param_1,long param_2)

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
    if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0x178) != (undefined8 *)0x0)) &&
       (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar1 + 0x178),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00196664. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00196690 nvmlDeviceGetAddressingMode =====

int nvmlDeviceGetAddressingMode(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x6aa,"nvmlDeviceGetAddressingMode",
                 "(nvmlDevice_t device, nvmlDeviceAddressingMode_t *mode)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00196610(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x6aa,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x6aa,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00196870 FUN_00196870 =====

undefined8 FUN_00196870(char *param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  char *local_20 [2];
  
  if ((param_1 == (char *)0x0) || (param_2 == 0)) {
    return 2;
  }
  local_20[0] = param_1;
  if (*param_1 != '\x01') {
    if (*(long *)(param_1 + 0x20) == 0) {
      uVar3 = FUN_0016e0a0(param_1,local_20);
      if ((int)uVar3 != 0) {
        return uVar3;
      }
      if (local_20[0] == (char *)0x0) {
        return 2;
      }
      if (*local_20[0] == '\x01') goto LAB_001968b3;
    }
    if (*(int *)(local_20[0] + 0x14) == 0) {
      return 2;
    }
    if (*(int *)(local_20[0] + 0x1c) != 0) {
      return 2;
    }
    if (*(int *)(local_20[0] + 0x10) == 0) {
      return 2;
    }
    if (*(long *)(local_20[0] + 0x20) == 0) {
      return 2;
    }
  }
LAB_001968b3:
  lVar1 = *(long *)(local_20[0] + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x110) != 0)) &&
     (pcVar2 = *(code **)(*(long *)(lVar1 + 0x110) + 8), pcVar2 != (code *)0x0)) {
    uVar3 = (*pcVar2)(lVar1,local_20[0],param_2);
    return uVar3;
  }
  return 3;
}


// ===== 00196930 nvmlDeviceGetC2cModeInfoV =====

int nvmlDeviceGetC2cModeInfoV(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x91,"nvmlDeviceGetC2cModeInfoV",
                 "(nvmlDevice_t device, nvmlC2cModeInfo_v1_t *c2cModeInfo)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00196870(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x91,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x91,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00196b10 FUN_00196b10 =====

undefined8 FUN_00196b10(char *param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  int local_1c;
  
  local_1c = 0;
  if ((param_1 == (char *)0x0) || (param_2 == 0)) {
    return 2;
  }
  if (((*(int *)(param_1 + 0x70530) != 2) &&
      ((iVar3 = FUN_00139230(param_1,&local_1c,10), iVar3 == 0 && (local_1c != 0)))) &&
     ((*param_1 == '\x01' || (*(long *)(param_1 + 0x20) != 0)))) {
    if (1 < *(uint *)(param_2 + 4)) {
      return 2;
    }
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0x180) != (undefined8 *)0x0)) &&
       (pcVar2 = (code *)**(undefined8 **)(lVar1 + 0x180), pcVar2 != (code *)0x0)) {
      uVar4 = (*pcVar2)(lVar1,param_1,param_2);
      return uVar4;
    }
  }
  return 3;
}


// ===== 00196bd0 FUN_00196bd0 =====

int FUN_00196bd0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xaf8,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00196b10(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xaf8,iVar1,uVar2);
  return iVar1;
}


// ===== 00196d10 FUN_00196d10 =====

undefined8 FUN_00196d10(char *param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  int local_1c [3];
  
  local_1c[0] = 0;
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if (*(int *)(param_1 + 0x70530) != 2) {
    iVar3 = FUN_00139230(param_1,local_1c,10);
    if ((((iVar3 == 0) && (local_1c[0] != 0)) &&
        ((*param_1 == '\x01' || (*(long *)(param_1 + 0x20) != 0)))) &&
       (((lVar1 = *(long *)(param_1 + 0x256d8), lVar1 != 0 && (*(long *)(lVar1 + 0x180) != 0)) &&
        (pcVar2 = *(code **)(*(long *)(lVar1 + 0x180) + 8), pcVar2 != (code *)0x0)))) {
      uVar4 = (*pcVar2)(lVar1,param_1);
      return uVar4;
    }
  }
  return 3;
}


// ===== 00196db0 FUN_00196db0 =====

int FUN_00196db0(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0xafd,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00196d10(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xafd,iVar1,uVar2);
  return iVar1;
}


// ===== 00196ee0 FUN_00196ee0 =====

undefined8 FUN_00196ee0(char *param_1,long param_2,long param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  int local_2c [3];
  
  local_2c[0] = 0;
  if ((param_2 == 0 || param_3 == 0) || (param_1 == (char *)0x0)) {
    return 2;
  }
  if (*(int *)(param_1 + 0x70530) != 2) {
    iVar3 = FUN_00139230(param_1,local_2c,10);
    if ((((iVar3 == 0) && (local_2c[0] != 0)) &&
        ((*param_1 == '\x01' || (*(long *)(param_1 + 0x20) != 0)))) &&
       (((lVar1 = *(long *)(param_1 + 0x256d8), lVar1 != 0 && (*(long *)(lVar1 + 0x180) != 0)) &&
        (pcVar2 = *(code **)(*(long *)(lVar1 + 0x180) + 0x10), pcVar2 != (code *)0x0)))) {
      uVar4 = (*pcVar2)(lVar1,param_1,param_2,param_3);
      return uVar4;
    }
  }
  return 3;
}


// ===== 00196fc0 FUN_00196fc0 =====

int FUN_00196fc0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xb02,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00196ee0(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xb02,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00197100 FUN_00197100 =====

undefined8 FUN_00197100(char *param_1,long param_2)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0xb8) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0xb8) + 0x40),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00197155. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00197180 FUN_00197180 =====

int FUN_00197180(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xb09,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00197100(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xb09,iVar1,uVar2);
  return iVar1;
}


// ===== 001972c0 FUN_001972c0 =====

int FUN_001972c0(char *param_1,undefined4 *param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 != (char *)0x0) {
    if ((*param_1 == '\x01') ||
       ((((iVar3 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
      if (param_2 == (undefined4 *)0x0) {
        iVar3 = 2;
      }
      else {
        if (*(int *)(param_1 + 0x71c) == 0) {
          do {
            iVar3 = FUN_00291820(param_1 + 0x720,1,0);
          } while (iVar3 != 0);
          if (*(int *)(param_1 + 0x71c) == 0) {
            lVar1 = *(long *)(param_1 + 0x256d8);
            uVar4 = 3;
            if (((lVar1 != 0) && (*(long *)(lVar1 + 0x20) != 0)) &&
               (pcVar2 = *(code **)(*(long *)(lVar1 + 0x20) + 0x98), pcVar2 != (code *)0x0)) {
              uVar4 = (*pcVar2)(lVar1,param_1,param_1 + 0x708);
            }
            *(undefined4 *)(param_1 + 0x724) = uVar4;
            param_1[0x71c] = '\x01';
            param_1[0x71d] = '\0';
            param_1[0x71e] = '\0';
            param_1[0x71f] = '\0';
          }
          FUN_00291830(param_1 + 0x720,0);
        }
        iVar3 = *(int *)(param_1 + 0x724);
        if (iVar3 == 0) {
          *param_2 = *(undefined4 *)(param_1 + 0x710);
        }
      }
    }
    return iVar3;
  }
  return 2;
}


// ===== 001973e0 FUN_001973e0 =====

int FUN_001973e0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xb0e,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001972c0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xb0e,iVar1,uVar2);
  return iVar1;
}


// ===== 00197520 FUN_00197520 =====

int FUN_00197520(char *param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 uVar5;
  float fVar6;
  undefined8 uVar7;
  
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
  if (param_2 == 0) {
    return 2;
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
  if (iVar2 == 0) {
    if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x20) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0xa0), pcVar1 == (code *)0x0)) {
      iVar2 = 3;
    }
    else {
      iVar2 = (*pcVar1)(DAT_012164a0,*(undefined4 *)(param_1 + 0x70c),
                        *(undefined4 *)(param_1 + 0x710),param_2);
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
    uVar7 = 0x3c07;
    uVar5 = 0x3c07;
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    fVar6 = fVar6 * DAT_00298548;
    uVar7 = 0x3c02;
    uVar5 = 0x3c02;
  }
  FUN_002340f0((double)fVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,"api.c",
               uVar5,"tsapiDeviceGetChipArchitectureID",uVar7,iVar2);
  return iVar2;
}


// ===== 00197780 FUN_00197780 =====

int FUN_00197780(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xb48,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00197520(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xb48,iVar1,uVar2);
  return iVar1;
}


// ===== 001978c0 FUN_001978c0 =====

int FUN_001978c0(char *param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  float fVar5;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((iVar2 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (param_2 == (undefined4 *)0x0) {
      return 2;
    }
    if (*(int *)(param_1 + 0x7056c) == 0) {
      do {
        iVar2 = FUN_00291820(param_1 + 0x70570,1,0);
      } while (iVar2 != 0);
      if (*(int *)(param_1 + 0x7056c) == 0) {
        lVar4 = *(long *)(param_1 + 0x256d8);
        uVar3 = 3;
        if (((lVar4 != 0) && (*(long *)(lVar4 + 0x20) != 0)) &&
           (pcVar1 = *(code **)(*(long *)(lVar4 + 0x20) + 0x78), pcVar1 != (code *)0x0)) {
          uVar3 = (*pcVar1)(lVar4,param_1,param_1 + 0x70568);
        }
        *(undefined4 *)(param_1 + 0x70574) = uVar3;
        param_1[0x7056c] = '\x01';
        param_1[0x7056d] = '\0';
        param_1[0x7056e] = '\0';
        param_1[0x7056f] = '\0';
      }
      FUN_00291830(param_1 + 0x70570,0);
    }
    iVar2 = *(int *)(param_1 + 0x70574);
    if (iVar2 == 0) {
      *param_2 = *(undefined4 *)(param_1 + 0x70568);
    }
    else if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"api.c",0x3c19,"tsapiDeviceGetSimulationInfo",0x3c19,iVar2);
    }
  }
  return iVar2;
}


// ===== 00197a50 FUN_00197a50 =====

int FUN_00197a50(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xb13,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001978c0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xb13,iVar1,uVar2);
  return iVar1;
}


// ===== 00197b90 FUN_00197b90 =====

undefined8 FUN_00197b90(long param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x140) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x140) + 0x108),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00197bbd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 00197bd0 nvmlDeviceGetSramEccErrorStatus =====

int nvmlDeviceGetSramEccErrorStatus(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x6b0,"nvmlDeviceGetSramEccErrorStatus",
                 "(nvmlDevice_t device, nvmlEccSramErrorStatus_t *status)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00197b90(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x6b0,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x6b0,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00197db0 FUN_00197db0 =====

undefined8 FUN_00197db0(long param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x78) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x78) + 0x20),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00197dd7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 00197df0 nvmlDeviceGetCapabilities =====

int nvmlDeviceGetCapabilities(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x6b5,"nvmlDeviceGetCapabilities",
                 "(nvmlDevice_t device, nvmlDeviceCapabilities_t *caps)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00197db0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x6b5,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x6b5,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00197fd0 FUN_00197fd0 =====

undefined8 FUN_00197fd0(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x238),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00198028. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00198050 FUN_00198050 =====

int FUN_00198050(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xb18,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00197fd0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xb18,iVar1,uVar2);
  return iVar1;
}


// ===== 00198190 FUN_00198190 =====

undefined8 FUN_00198190(char *param_1,undefined4 param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x240),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001981e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00198200 FUN_00198200 =====

int FUN_00198200(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d)\n",
                 "DEBUG",lVar3,"entry_points.h",0xb1d,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00198190(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xb1d,iVar1,uVar2);
  return iVar1;
}


// ===== 00198340 FUN_00198340 =====

ulong FUN_00198340(undefined8 param_1,long param_2)

{
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
                       &DAT_002983c2,lVar2,"api.c",0x3c44);
        }
      }
      else {
        if (param_2 != 0) {
          uVar3 = FUN_0012d8d0(param_1,param_2);
          return uVar3;
        }
        uVar3 = 2;
      }
    }
    else {
      uVar3 = 999;
    }
  }
  return uVar3;
}


// ===== 00198430 FUN_00198430 =====

int FUN_00198430(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xb28,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00198340(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xb28,iVar1,uVar2);
  return iVar1;
}


// ===== 00198570 FUN_00198570 =====

int FUN_00198570(char *param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  undefined1 local_48 [8];
  undefined8 uStack_40;
  undefined1 local_38 [16];
  undefined8 local_28;
  int local_20;
  
  local_28 = 0;
  local_20 = 0;
  local_38 = (undefined1  [16])0x0;
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((iVar2 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (param_2 == (int *)0x0) {
      return 2;
    }
    lVar3 = *(long *)(param_1 + 0x256d8);
    stack0xffffffffffffffbc = SUB1612((undefined1  [16])0x0,4);
    local_48._0_4_ = 0x200002c;
    if (((lVar3 == 0) || (*(long *)(lVar3 + 0x78) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(lVar3 + 0x78) + 0x28), pcVar1 == (code *)0x0)) {
      iVar2 = 3;
    }
    else {
      iVar2 = (*pcVar1)(lVar3,param_1,local_48);
      if (iVar2 == 0) {
        if (*param_2 == 0x100002c) {
          local_48._0_4_ = 0x100002c;
        }
        *(undefined8 *)(param_2 + 8) = local_28;
        *(undefined1 (*) [8])param_2 = local_48;
        *(undefined8 *)(param_2 + 2) = uStack_40;
        param_2[10] = local_20;
        *(undefined8 *)(param_2 + 4) = local_38._0_8_;
        *(undefined8 *)(param_2 + 6) = local_38._8_8_;
        return 0;
      }
    }
    if (1 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar3,"api.c",0x3c5c,"tsapiDeviceGetPlatformInfo",0x3c5c,iVar2);
      return iVar2;
    }
  }
  return iVar2;
}


// ===== 001986f0 nvmlDeviceGetPlatformInfo =====

int nvmlDeviceGetPlatformInfo(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x6ba,"nvmlDeviceGetPlatformInfo",
                 "(nvmlDevice_t device, nvmlPlatformInfo_t *platformInfo)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00198570(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x6ba,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x6ba,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001988d0 FUN_001988d0 =====

undefined8 FUN_001988d0(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x78) + 0x30),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00198922. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00198940 nvmlDeviceSetHostname_v1 =====

int nvmlDeviceSetHostname_v1(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x6bf,"nvmlDeviceSetHostname_v1",
                 "(nvmlDevice_t device, nvmlHostname_v1_t *hostname)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001988d0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x6bf,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x6bf,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00198b20 FUN_00198b20 =====

undefined8 FUN_00198b20(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x78) + 0x38),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00198b72. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00198b90 nvmlDeviceGetHostname_v1 =====

int nvmlDeviceGetHostname_v1(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x6c4,"nvmlDeviceGetHostname_v1",
                 "(nvmlDevice_t device, nvmlHostname_v1_t *hostname)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00198b20(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x6c4,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x6c4,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00198d70 FUN_00198d70 =====

undefined8 FUN_00198d70(char *param_1,long param_2)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x38) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x38) + 0x90),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00198dc5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00198df0 nvmlDeviceGetPdi =====

int nvmlDeviceGetPdi(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x75d,"nvmlDeviceGetPdi","(nvmlDevice_t device, nvmlPdi_t *pdi)",
                 param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00198d70(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x75d,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x75d,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00198fd0 FUN_00198fd0 =====

undefined8 FUN_00198fd0(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x158) + 0xe0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00199028. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00199050 nvmlDeviceGetNvLinkInfo =====

int nvmlDeviceGetNvLinkInfo(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x761,"nvmlDeviceGetNvLinkInfo",
                 "(nvmlDevice_t device, nvmlNvLinkInfo_t *info)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00198fd0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x761,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x761,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00199230 FUN_00199230 =====

undefined8 FUN_00199230(long param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return 2;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x188) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x188) + 8),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00199264. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 00199290 FUN_00199290 =====

int FUN_00199290(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xb3c,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00199230(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xb3c,iVar1,uVar2);
  return iVar1;
}


// ===== 001993d0 FUN_001993d0 =====

undefined8 FUN_001993d0(long param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return 2;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x188) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x188) + 0x10),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00199404. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 00199430 FUN_00199430 =====

int FUN_00199430(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xb42,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001993d0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xb42,iVar1,uVar2);
  return iVar1;
}


// ===== 00199570 FUN_00199570 =====

undefined8 FUN_00199570(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0x100),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001995c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 001995f0 nvmlDevicePowerSmoothingActivatePresetProfile =====

int nvmlDevicePowerSmoothingActivatePresetProfile(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x749,"nvmlDevicePowerSmoothingActivatePresetProfile",
                 "(nvmlDevice_t device, nvmlPowerSmoothingProfile_t *profile)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00199570(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x749,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x749,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001997d0 FUN_001997d0 =====

undefined8 FUN_001997d0(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0x108),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00199828. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00199850 nvmlDevicePowerSmoothingUpdatePresetProfileParam =====

int nvmlDevicePowerSmoothingUpdatePresetProfileParam(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x74f,"nvmlDevicePowerSmoothingUpdatePresetProfileParam",
                 "(nvmlDevice_t device, nvmlPowerSmoothingProfile_t *profile)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001997d0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x74f,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x74f,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00199a30 FUN_00199a30 =====

undefined8 FUN_00199a30(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0x110),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00199a88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00199ab0 nvmlDevicePowerSmoothingSetState =====

int nvmlDevicePowerSmoothingSetState(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x755,"nvmlDevicePowerSmoothingSetState",
                 "(nvmlDevice_t device, nvmlPowerSmoothingState_t *state)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00199a30(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x755,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x755,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00199c90 FUN_00199c90 =====

undefined8 FUN_00199c90(char *param_1,long param_2)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x98) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x98) + 0x10),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00199ce5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00199d10 FUN_00199d10 =====

int FUN_00199d10(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xb4e,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00199c90(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xb4e,iVar1,uVar2);
  return iVar1;
}


// ===== 00199e50 FUN_00199e50 =====

undefined8 FUN_00199e50(char *param_1,undefined4 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x98) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x98) + 0x18),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00199e9f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00199ec0 FUN_00199ec0 =====

int FUN_00199ec0(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d)\n",
                 "DEBUG",lVar3,"entry_points.h",0xb53,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00199e50(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xb53,iVar1,uVar2);
  return iVar1;
}


// ===== 0019a000 FUN_0019a000 =====

undefined8 FUN_0019a000(char *param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x48) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x48) + 0xb8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0019a050. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0019a070 FUN_0019a070 =====

int FUN_0019a070(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xb58,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0019a000(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xb58,iVar1,uVar2);
  return iVar1;
}


// ===== 0019a1b0 FUN_0019a1b0 =====

undefined8 FUN_0019a1b0(char *param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x160) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0x118),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0019a203. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0019a220 nvmlDeviceWorkloadPowerProfileGetProfilesInfo =====

int nvmlDeviceWorkloadPowerProfileGetProfilesInfo(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x6cb,"nvmlDeviceWorkloadPowerProfileGetProfilesInfo",
                 "(nvmlDevice_t device, nvmlWorkloadPowerProfileProfilesInfo_t *profilesInfo)",
                 param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0019a1b0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x6cb,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x6cb,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0019a400 FUN_0019a400 =====

undefined8 FUN_0019a400(char *param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x160) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0x120),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0019a453. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0019a470 nvmlDeviceWorkloadPowerProfileGetCurrentProfiles =====

int nvmlDeviceWorkloadPowerProfileGetCurrentProfiles(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x6d0,"nvmlDeviceWorkloadPowerProfileGetCurrentProfiles",
                 "(nvmlDevice_t device, nvmlWorkloadPowerProfileCurrentProfiles_t *currentProfiles)"
                 ,param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0019a400(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x6d0,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x6d0,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0019a650 FUN_0019a650 =====

undefined8 FUN_0019a650(char *param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x160) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0x128),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0019a6a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0019a6c0 nvmlDeviceWorkloadPowerProfileSetRequestedProfiles =====

int nvmlDeviceWorkloadPowerProfileSetRequestedProfiles(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x6d5,"nvmlDeviceWorkloadPowerProfileSetRequestedProfiles",
                 "(nvmlDevice_t device, nvmlWorkloadPowerProfileRequestedProfiles_t *requestedProfiles)"
                 ,param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0019a650(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x6d5,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x6d5,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0019a8a0 FUN_0019a8a0 =====

undefined8 FUN_0019a8a0(char *param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x160) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0x130),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0019a8f3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0019a910 nvmlDeviceWorkloadPowerProfileClearRequestedProfiles =====

int nvmlDeviceWorkloadPowerProfileClearRequestedProfiles(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x6da,"nvmlDeviceWorkloadPowerProfileClearRequestedProfiles",
                 "(nvmlDevice_t device, nvmlWorkloadPowerProfileRequestedProfiles_t *requestedProfiles)"
                 ,param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0019a8a0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x6da,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x6da,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0019aaf0 FUN_0019aaf0 =====

undefined8 FUN_0019aaf0(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0x138),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0019ab48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0019ab70 nvmlDeviceWorkloadPowerProfileUpdateProfiles_v1 =====

int nvmlDeviceWorkloadPowerProfileUpdateProfiles_v1(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x6e0,"nvmlDeviceWorkloadPowerProfileUpdateProfiles_v1",
                 "(nvmlDevice_t device, nvmlWorkloadPowerProfileUpdateProfiles_v1_t *updateProfiles)"
                 ,param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0019aaf0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x6e0,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x6e0,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0019ad50 FUN_0019ad50 =====

undefined8 FUN_0019ad50(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x158) + 200),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0019ada8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0019add0 nvmlDeviceGetNvlinkSupportedBwModes =====

int nvmlDeviceGetNvlinkSupportedBwModes(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x6e9,"nvmlDeviceGetNvlinkSupportedBwModes",
                 "(nvmlDevice_t device, nvmlNvlinkSupportedBwModes_t *supportedBwModes)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0019ad50(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x6e9,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x6e9,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0019afb0 FUN_0019afb0 =====

undefined8 FUN_0019afb0(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x158) + 0xd0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0019b008. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0019b030 nvmlDeviceGetNvlinkBwMode =====

int nvmlDeviceGetNvlinkBwMode(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x6ee,"nvmlDeviceGetNvlinkBwMode",
                 "(nvmlDevice_t device, nvmlNvlinkGetBwMode_t *getBwMode)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0019afb0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x6ee,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x6ee,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0019b210 FUN_0019b210 =====

undefined8 FUN_0019b210(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x158) + 0xd8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0019b268. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0019b290 nvmlDeviceSetNvlinkBwMode =====

int nvmlDeviceSetNvlinkBwMode(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x6f3,"nvmlDeviceSetNvlinkBwMode",
                 "(nvmlDevice_t device, nvmlNvlinkSetBwMode_t *setBwMode)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0019b210(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x6f3,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x6f3,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0019b470 FUN_0019b470 =====

undefined8 FUN_0019b470(long param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x140) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x140) + 0x110),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0019b49d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 0019b4b0 nvmlDeviceGetSramUniqueUncorrectedEccErrorCounts =====

int nvmlDeviceGetSramUniqueUncorrectedEccErrorCounts(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0xb7b,"nvmlDeviceGetSramUniqueUncorrectedEccErrorCounts",
                 "(nvmlDevice_t device, nvmlEccSramUniqueUncorrectedErrorCounts_t *counts)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0019b470(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xb7b,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xb7b,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0019b690 FUN_0019b690 =====

undefined8 FUN_0019b690(char *param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x140) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x140) + 0x118),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0019b6e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0019b700 nvmlDeviceGetRepairStatus =====

int nvmlDeviceGetRepairStatus(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0xb82,"nvmlDeviceGetRepairStatus",
                 "(nvmlDevice_t device, nvmlRepairStatus_t *repairStatus)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0019b690(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xb82,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xb82,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0019b8e0 FUN_0019b8e0 =====

undefined8 FUN_0019b8e0(long param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x120) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x120) + 0x88),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0019b90d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 0019b920 nvmlDeviceSetRusdSettings_v1 =====

int nvmlDeviceSetRusdSettings_v1(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0xb88,"nvmlDeviceSetRusdSettings_v1",
                 "(nvmlDevice_t device, nvmlRusdSettings_v1_t *settings)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0019b8e0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xb88,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xb88,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0019bb00 FUN_0019bb00 =====

undefined8 FUN_0019bb00(char *param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x140) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x140) + 0x120),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0019bb53. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0019bb70 nvmlDeviceGetUnrepairableMemoryFlag_v1 =====

int nvmlDeviceGetUnrepairableMemoryFlag_v1(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0xb8f,"nvmlDeviceGetUnrepairableMemoryFlag_v1",
                 "(nvmlDevice_t device, nvmlUnrepairableMemoryStatus_v1_t *unrepairableMemoryStatus)"
                 ,param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0019bb00(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xb8f,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xb8f,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0019bd50 FUN_0019bd50 =====

undefined8 FUN_0019bd50(long param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0xb8) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0xb8) + 0x50),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0019bd80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar1;
  }
  return 3;
}


// ===== 0019bda0 FUN_0019bda0 =====

int FUN_0019bda0(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0xb5e,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0019bd50(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xb5e,iVar1,uVar2);
  return iVar1;
}


// ===== 0019bed0 FUN_0019bed0 =====

undefined8 FUN_0019bed0(undefined4 param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (param_2 == 0) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0xb8) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0xb8) + 0x58),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0019bf05. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1,param_2);
    return uVar1;
  }
  return 3;
}


// ===== 0019bf30 FUN_0019bf30 =====

int FUN_0019bf30(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%u %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xb63,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0019bed0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xb63,iVar1,uVar2);
  return iVar1;
}


// ===== 0019c070 FUN_0019c070 =====

undefined8 FUN_0019c070(undefined8 param_1,long param_2,int param_3,int param_4)

{
  undefined8 uVar1;
  
  if ((param_3 != 0 && param_4 != 0) && (param_2 != 0)) {
    uVar1 = FUN_001279a0();
    return uVar1;
  }
  return 2;
}


// ===== 0019c0a0 FUN_0019c0a0 =====

int FUN_0019c0a0(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p %u %u)\n"
                 ,"DEBUG",lVar3,"entry_points.h",0xb69,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0019c070(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xb69,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0019c1f0 FUN_0019c1f0 =====

undefined8 FUN_0019c1f0(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
    return 2;
  }
  iVar1 = FUN_00236dd0();
  if (iVar1 != 0) {
    uVar2 = FUN_001236d0(param_1,0);
    return uVar2;
  }
  return 4;
}


// ===== 0019c240 FUN_0019c240 =====

int FUN_0019c240(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0xb6e,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0019c1f0(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xb6e,iVar1,uVar2);
  return iVar1;
}


// ===== 0019c370 FUN_0019c370 =====

int FUN_0019c370(void)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  iVar1 = (*(code *)PTR_FUN_0037ed18)();
  if ((iVar1 != 0) && (2 < DAT_01216a78)) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n","WARNING",
                 lVar2,"dmal/dmal_init.c",0x39,"rmDMALLayer.init");
    return iVar1;
  }
  return iVar1;
}


// ===== 0019c410 thunk_FUN_0023e130 =====

void thunk_FUN_0023e130(undefined8 param_1)

{
  FUN_0023dbf0(param_1,0);
  return;
}


// ===== 0019c420 FUN_0019c420 =====

void FUN_0019c420(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined8 param_6)

{
  FUN_00240910(param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 0019c440 thunk_FUN_0023dac0 =====

void thunk_FUN_0023dac0(void)

{
  void *pvVar1;
  void *__ptr;
  long lVar2;
  undefined8 *puVar3;
  char cVar4;
  bool bVar5;
  byte bVar6;
  timespec tStack_38;
  
  bVar6 = 0;
  cVar4 = '\x01';
  DAT_01217e20 = 0;
  while( true ) {
    LOCK();
    bVar5 = DAT_01217e20 == 0;
    if (bVar5) {
      DAT_01217e20 = 1;
    }
    UNLOCK();
    __ptr = DAT_01217408;
    if (bVar5) break;
    cVar4 = cVar4 + '\x01';
    if (cVar4 == '\0') {
      tStack_38.tv_sec = 0;
      tStack_38.tv_nsec = 2000000;
      nanosleep(&tStack_38,(timespec *)0x0);
    }
  }
  while (__ptr != (void *)0x0) {
    pvVar1 = *(void **)((long)__ptr + 0x30);
    FUN_0023c600((long)__ptr + 0x20);
    if (-1 < *(int *)((long)__ptr + 0xc)) {
      FUN_0023d200(__ptr);
    }
    free(__ptr);
    __ptr = pvVar1;
  }
  DAT_01217408 = (void *)0x0;
  if (DAT_01216aa8 != 0) {
    FUN_0023d0a0();
  }
  if (DAT_00380490 != -1) {
    thunk_FUN_0023c0a0();
  }
  DAT_00380490 = 0xffffffff;
  DAT_01216aa8 = 0;
  DAT_012173cc = 0xffffffff;
  puVar3 = &DAT_01216ac0;
  for (lVar2 = 0x120; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + (ulong)bVar6 * -2 + 1;
  }
  DAT_01217e20 = 0;
  return;
}


// ===== 0019c450 thunk_FUN_00241210 =====

int thunk_FUN_00241210(long param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 0x3d;
  }
  iVar1 = FUN_0023d7d0(DAT_00380490,0x4a,0xb8,0xc0b8464a,param_1,param_1 + 0x14);
  if (iVar1 == 0) {
    return *(int *)(param_1 + 0x14);
  }
  if (iVar1 == 0x59) {
    iVar1 = 0x1a;
  }
  return iVar1;
}


// ===== 0019c460 thunk_FUN_00241370 =====

int thunk_FUN_00241370(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                      undefined4 param_5,ulong param_6)

{
  undefined1 auVar1 [16];
  int iVar2;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_2c [12];
  undefined1 auStack_20 [16];
  undefined8 uStack_10;
  
  auStack_2c = SUB1612((undefined1  [16])0x0,4);
  uStack_30 = param_3;
  auVar1 = _uStack_30;
  _uStack_30 = auVar1._0_8_;
  auStack_2c._4_4_ = param_5;
  auStack_20._8_8_ = 0;
  auStack_20._0_8_ = param_6;
  uStack_10 = 0;
  uStack_38 = param_1;
  uStack_34 = param_2;
  iVar2 = FUN_0023d7d0(DAT_00380490,0x58,0x30,0xc0304658,&uStack_38,&uStack_10);
  if (iVar2 == 0) {
    iVar2 = (int)uStack_10;
  }
  return iVar2;
}


// ===== 0019c470 thunk_FUN_002412b0 =====

void thunk_FUN_002412b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                       undefined4 param_5)

{
  FUN_0023cd30(DAT_00380490,param_1,param_2,param_3,param_4,param_5);
  return;
}


// ===== 0019c480 thunk_FUN_002412e0 =====

ulong thunk_FUN_002412e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        ,undefined8 param_5,undefined8 param_6,undefined4 param_7,ulong *param_8)

{
  ulong uVar1;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined4 uStack_38;
  undefined1 auStack_34 [12];
  undefined1 auStack_28 [16];
  
  if (param_8 != (ulong *)0x0) {
    auStack_34 = SUB1612((undefined1  [16])0x0,4);
    uStack_38 = param_7;
    auStack_28._8_8_ = 0;
    auStack_28._0_8_ = *param_8;
    uStack_58 = param_1;
    uStack_54 = param_2;
    uStack_50 = param_3;
    uStack_4c = param_4;
    uStack_48 = param_5;
    uStack_40 = param_6;
    uVar1 = FUN_0023d7d0(DAT_00380490,0x57,0x40,0xc0404657,&uStack_58,auStack_28 + 8);
    if (((int)uVar1 == 0) && (uVar1 = (ulong)(uint)auStack_28._8_4_, auStack_28._8_4_ == 0)) {
      *param_8 = auStack_28._0_8_;
    }
    return uVar1;
  }
  return 0x3d;
}


// ===== 0019c490 thunk_FUN_00241280 =====

void thunk_FUN_00241280(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                       undefined8 param_5,undefined8 param_6,undefined4 param_7)

{
  FUN_0023c8e0(DAT_00380490,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}


// ===== 0019c4a0 thunk_FUN_0023e140 =====

int thunk_FUN_0023e140(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                      uint param_5,undefined8 *param_6,ulong *param_7)

{
  void *__addr;
  uint __fd;
  size_t __len;
  long lVar1;
  char cStack_98;
  int iStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  int iStack_6c;
  undefined1 auStack_68 [8];
  undefined8 uStack_60;
  undefined1 auStack_58 [16];
  ulong uStack_48;
  
  if (param_7 == (ulong *)0x0) {
    return 0x3d;
  }
  if ((param_6 == (undefined8 *)0x0) && (param_4 != 0x40)) {
    return 0x3d;
  }
  __addr = (void *)*param_6;
  __len = *param_7 + 1;
  lVar1 = FUN_0023d8e0(param_1,param_2);
  if (lVar1 == 0) {
    return 0x22;
  }
  uStack_78 = param_1;
  uStack_74 = param_2;
  uStack_70 = param_3;
  if (param_4 == 0x3e) {
    if ((param_5 >> 0x10 & 3) == 1) {
      __fd = 0xffffffff;
    }
    else {
      __fd = 0xffffffff;
      if ((param_5 >> 0x1e != 1) && (__fd = FUN_0023da00(0xff,&iStack_7c), (int)__fd < 0)) {
        return iStack_7c;
      }
    }
    iStack_6c = 0x3e;
    stack0xffffffffffffff9c = SUB1612((undefined1  [16])0x0,4);
    auStack_68._0_4_ = param_5;
    uStack_48 = (ulong)__fd;
LAB_0023e260:
    uStack_60 = 0;
    auStack_58._8_8_ = 0;
    auStack_58._0_8_ = *param_7;
    iStack_7c = FUN_0023d7d0(*(undefined4 *)(lVar1 + 0xc),0x27,0x38,0xc0384627,&uStack_78,
                             auStack_58 + 8);
    cStack_98 = '\0';
    if (iStack_7c != 0) {
      if (__fd == 0xffffffff) {
        return iStack_7c;
      }
      close(__fd);
      return iStack_7c;
    }
    iStack_7c = auStack_58._8_4_;
  }
  else {
    stack0xffffffffffffff9c = SUB1612((undefined1  [16])0x0,4);
    auStack_68._0_4_ = param_5;
    uStack_48 = 0xffffffff;
    auStack_58 = (undefined1  [16])0x0;
    iStack_6c = param_4;
    if (param_4 == 0x71) {
      cStack_98 = '\0';
      if ((*(long *)(lVar1 + 0x28) != 0) &&
         (cStack_98 = '\0', *(char *)(*(long *)(lVar1 + 0x28) + 0x49) != '\0')) {
        cStack_98 = FUN_0023c6c0(__addr,__len);
        if (cStack_98 == '\0') {
          FUN_0023d3e0(*(undefined8 *)PTR_stderr_0032efe0,"NVIDIA: mlock failed (size=0x%llx)\n",
                       __len);
        }
      }
    }
    else {
      if (2 < param_4 - 0x81U) {
        __fd = 0xffffffff;
        goto LAB_0023e260;
      }
      cStack_98 = '\0';
    }
    uStack_60 = *param_6;
    auStack_58._0_8_ = *param_7;
    iStack_7c = FUN_0023d7d0(*(undefined4 *)(lVar1 + 0xc),0x27,0x38,0xc0384627,&uStack_78,
                             auStack_58 + 8);
    if (iStack_7c != 0) goto LAB_0023e353;
    __fd = 0xffffffff;
    iStack_7c = auStack_58._8_4_;
  }
  if (iStack_7c == 0) {
    iStack_7c = 0;
    *param_7 = auStack_58._0_8_;
    if ((param_4 == 0x71) || (((param_5 >> 0x10 & 3) != 1 && (param_5 >> 0x1e != 1)))) {
      iStack_7c = FUN_0023c6e0(__fd,param_1,param_2,param_3,param_4,lVar1,
                               CONCAT44(uStack_74,uStack_78),CONCAT44(iStack_6c,uStack_70),
                               auStack_68,uStack_60,auStack_58._0_8_,auStack_58._8_8_,param_6);
    }
    else {
      *param_6 = 0;
      iStack_7c = 0;
    }
  }
  if (__fd != 0xffffffff) {
    close(__fd);
  }
LAB_0023e353:
  if (cStack_98 != '\0') {
    munlock(__addr,__len);
  }
  return iStack_7c;
}


// ===== 0019c4b0 thunk_FUN_00241180 =====

ulong thunk_FUN_00241180(undefined8 param_1,undefined8 param_2,long param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  ulong uVar2;
  long lStack_28;
  undefined8 uStack_20;
  
  if (param_3 == 0) {
    return 0x3d;
  }
  puVar1 = (undefined4 *)FUN_0023cfa0();
  if (puVar1 != (undefined4 *)0x0) {
    uStack_20 = 0;
    lStack_28 = param_3;
    uVar2 = FUN_0023d7d0(*puVar1,0x52,0x10,0xc0104652,&lStack_28,(long)&uStack_20 + 4);
    if ((int)uVar2 == 0) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = (undefined4)uStack_20;
      }
      uVar2 = uStack_20 >> 0x20;
    }
    return uVar2;
  }
  return 0x36;
}


// ===== 0019c4c0 thunk_FUN_00241080 =====

int thunk_FUN_00241080(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,int *param_6)

{
  int iVar1;
  long lVar2;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  long lStack_78;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 *puStack_58;
  undefined1 auStack_50 [16];
  undefined8 auStack_40 [2];
  
  if (param_6 == (int *)0x0) {
    return 0x3d;
  }
  iVar1 = 0x59;
  if (-1 < *param_6) {
    lVar2 = FUN_0023cfa0();
    if (lVar2 == 0) {
      return 0x36;
    }
    lStack_78 = (long)*param_6;
    puStack_58 = &uStack_88;
    uStack_84 = 0;
    auStack_40[0] = 0;
    auStack_50 = (undefined1  [16])0x0;
    uStack_88 = param_1;
    uStack_80 = param_4;
    uStack_7c = param_5;
    uStack_68 = param_1;
    uStack_64 = param_2;
    uStack_60 = param_3;
    uStack_5c = param_4;
    iVar1 = FUN_0023d7d0(lStack_78,0x2b,0x30,0xc030462b,&uStack_68,auStack_40);
    if (iVar1 == 0) {
      iVar1 = (int)auStack_40[0];
    }
  }
  return iVar1;
}


// ===== 0019c4d0 thunk_FUN_00240f20 =====

int thunk_FUN_00240f20(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined *puVar3;
  char cVar4;
  bool bVar5;
  timespec tStack_48;
  
  puVar3 = (undefined *)FUN_0023d8e0();
  if (puVar3 == (undefined *)0x0) {
    puVar3 = &DAT_012173c0;
  }
  cVar4 = '\x01';
  while( true ) {
    LOCK();
    bVar5 = DAT_01217e20 == 0;
    if (bVar5) {
      DAT_01217e20 = 1;
    }
    UNLOCK();
    if (bVar5) break;
    cVar4 = cVar4 + '\x01';
    if (cVar4 == '\0') {
      tStack_48.tv_sec = 0;
      tStack_48.tv_nsec = 2000000;
      nanosleep(&tStack_48,(timespec *)0x0);
    }
  }
  piVar1 = *(int **)(puVar3 + 0x10);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      DAT_01217e20 = 0;
      return 0x28;
    }
    if (*piVar1 == param_3) break;
    piVar1 = *(int **)(piVar1 + 4);
  }
  tStack_48.tv_sec = CONCAT44(param_2,param_1);
  tStack_48.tv_nsec._4_4_ = 0;
  tStack_48.tv_nsec._0_4_ = param_3;
  iVar2 = thunk_FUN_0023c0f0(param_3,0xcf,0x10,0xc01046cf,&tStack_48);
  if (iVar2 < 0) {
    DAT_01217e20 = 0;
    return 0x59;
  }
  if (tStack_48.tv_nsec._4_4_ != 0) {
    DAT_01217e20 = 0;
    return tStack_48.tv_nsec._4_4_;
  }
  if (puVar3 != PTR_DAT_0032ef60) {
    FUN_0023d200(puVar3,param_3);
    DAT_01217e20 = 0;
    return 0;
  }
  FUN_0023d370(param_3);
  DAT_01217e20 = 0;
  return 0;
}


// ===== 0019c4e0 thunk_FUN_00240be0 =====

int thunk_FUN_00240be0(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  int *piVar4;
  long lVar5;
  char cVar6;
  bool bVar7;
  int iStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  int iStack_50;
  int iStack_4c;
  timespec tStack_48;
  
  if (param_4 == (int *)0x0) {
    return 0x3d;
  }
  puVar3 = (undefined *)FUN_0023d8e0();
  if (puVar3 == (undefined *)0x0) {
    iVar2 = FUN_0023da00(0xff,&iStack_5c);
    puVar3 = &DAT_012173c0;
    *param_4 = iVar2;
  }
  else {
    iVar2 = FUN_0023d9b0(*(undefined8 *)(puVar3 + 0x28));
    if (iVar2 < 0) {
      return 0x59;
    }
    iVar2 = FUN_0023d9f0(iVar2,&iStack_5c);
    *param_4 = iVar2;
  }
  if (-1 < iVar2) {
    tStack_48.tv_sec = CONCAT44(tStack_48.tv_sec._4_4_,DAT_00380490);
    iVar2 = thunk_FUN_0023c0f0(iVar2,0xc9,4,0xc00446c9,&tStack_48);
    if (iVar2 < 0) {
      FUN_0023d200(puVar3,*param_4);
      iStack_5c = 0xffff;
    }
    else {
      piVar4 = malloc(0x18);
      if (piVar4 == (int *)0x0) {
        cVar6 = '\x01';
        while( true ) {
          LOCK();
          bVar7 = DAT_01217e20 == 0;
          if (bVar7) {
            DAT_01217e20 = 1;
          }
          UNLOCK();
          if (bVar7) break;
          cVar6 = cVar6 + '\x01';
          if (cVar6 == '\0') {
            tStack_48.tv_sec = 0;
            tStack_48.tv_nsec = 2000000;
            nanosleep(&tStack_48,(timespec *)0x0);
          }
        }
        if (puVar3 == PTR_DAT_0032ef60) {
          FUN_0023d370(*param_4);
        }
        else {
          FUN_0023d200(puVar3);
        }
        iStack_5c = 0x59;
        DAT_01217e20 = 0;
        *param_4 = -1;
      }
      else {
        piVar4[4] = 0;
        piVar4[5] = 0;
        cVar6 = '\x01';
        *piVar4 = -1;
        while( true ) {
          LOCK();
          bVar7 = DAT_01217e20 == 0;
          if (bVar7) {
            DAT_01217e20 = 1;
          }
          UNLOCK();
          if (bVar7) break;
          cVar6 = cVar6 + '\x01';
          if (cVar6 == '\0') {
            tStack_48.tv_sec = 0;
            tStack_48.tv_nsec = 2000000;
            nanosleep(&tStack_48,(timespec *)0x0);
          }
        }
        lVar1 = *(long *)(puVar3 + 0x10);
        if (*(long *)(puVar3 + 0x10) == 0) {
          piVar4[2] = 0;
          piVar4[3] = 0;
          *(int **)(puVar3 + 0x10) = piVar4;
        }
        else {
          do {
            lVar5 = lVar1;
            lVar1 = *(long *)(lVar5 + 0x10);
          } while (*(long *)(lVar5 + 0x10) != 0);
          *(long *)(piVar4 + 2) = lVar5;
          *(int **)(lVar5 + 0x10) = piVar4;
        }
        DAT_01217e20 = 0;
        iStack_4c = 0;
        iStack_50 = *param_4;
        *piVar4 = iStack_50;
        uStack_58 = param_1;
        uStack_54 = param_2;
        iVar2 = thunk_FUN_0023c0f0(iStack_50,0xce,0x10,0xc01046ce,&uStack_58);
        if (iVar2 < 1) {
          iStack_4c = 0x59;
        }
        else if (iStack_4c == 0) {
          if (param_3 == (int *)0x0) {
            return 0;
          }
          *param_3 = *param_4;
          return 0;
        }
        cVar6 = '\0';
        do {
          cVar6 = cVar6 + '\x01';
          if (cVar6 == '\0') {
            tStack_48.tv_sec = 0;
            tStack_48.tv_nsec = 2000000;
            nanosleep(&tStack_48,(timespec *)0x0);
          }
          LOCK();
          bVar7 = DAT_01217e20 == 0;
          if (bVar7) {
            DAT_01217e20 = 1;
          }
          UNLOCK();
        } while (!bVar7);
        if (puVar3 == PTR_DAT_0032ef60) {
          FUN_0023d370(*param_4);
        }
        else {
          FUN_0023d200(puVar3);
        }
        DAT_01217e20 = 0;
        *param_4 = -1;
        iStack_5c = iStack_4c;
      }
    }
  }
  return iStack_5c;
}


// ===== 0019c4f0 thunk_FUN_0023e540 =====

ulong thunk_FUN_0023e540(int param_1,undefined4 param_2,int param_3)

{
  int *__ptr;
  ulong uVar1;
  long lVar2;
  int *piVar3;
  int *piVar4;
  int *__ptr_00;
  char cVar5;
  bool bVar6;
  int iStack_58;
  undefined4 uStack_54;
  int iStack_50;
  uint uStack_4c;
  timespec tStack_48;
  
  uStack_4c = 0;
  iStack_58 = param_1;
  uStack_54 = param_2;
  iStack_50 = param_3;
  FUN_0023c7b0();
  uVar1 = FUN_0023d7d0(DAT_00380490,0x29,0x10,0xc0104629,&iStack_58,&uStack_4c);
  if (((int)uVar1 == 0) && (uVar1 = (ulong)uStack_4c, uStack_4c == 0)) {
    if (param_1 == param_3) {
      cVar5 = '\x01';
      while( true ) {
        piVar3 = DAT_01217408;
        LOCK();
        bVar6 = DAT_01217e20 == 0;
        if (bVar6) {
          DAT_01217e20 = 1;
        }
        UNLOCK();
        if (bVar6) break;
        cVar5 = cVar5 + '\x01';
        if (cVar5 == '\0') {
          tStack_48.tv_sec = 0;
          tStack_48.tv_nsec = 2000000;
          nanosleep(&tStack_48,(timespec *)0x0);
        }
      }
      DAT_01217408 = (int *)0x0;
      while (__ptr_00 = piVar3, piVar4 = DAT_01217400, __ptr = DAT_01217400, piVar3 != (int *)0x0) {
        while (piVar3 = *(int **)(__ptr_00 + 0xc), param_1 != *__ptr_00) {
          *(int **)(__ptr_00 + 0xc) = DAT_01217408;
          DAT_01217408 = __ptr_00;
          __ptr_00 = piVar3;
          piVar4 = DAT_01217400;
          __ptr = DAT_01217400;
          if (piVar3 == (int *)0x0) goto joined_r0x0023e6c6;
        }
        FUN_0023d200(__ptr_00,__ptr_00[3]);
        free(__ptr_00);
      }
joined_r0x0023e6c6:
      while (piVar3 = __ptr, __ptr = piVar4, __ptr != (int *)0x0) {
        piVar4 = *(int **)(__ptr + 2);
        if (param_1 == *__ptr) {
          *(int **)(piVar3 + 2) = piVar4;
          if (DAT_01217400 == __ptr) {
            DAT_01217400 = piVar4;
          }
          close(__ptr[1]);
          free(__ptr);
          __ptr = piVar3;
        }
      }
      DAT_01217e20 = 0;
      FUN_0023d100();
      uVar1 = (ulong)uStack_4c;
    }
    else {
      lVar2 = FUN_0023d8e0(param_1);
      if (lVar2 != 0) {
        cVar5 = '\x01';
        while( true ) {
          piVar3 = DAT_01217408;
          LOCK();
          bVar6 = DAT_01217e20 == 0;
          if (bVar6) {
            DAT_01217e20 = 1;
          }
          UNLOCK();
          if (bVar6) break;
          cVar5 = cVar5 + '\x01';
          if (cVar5 == '\0') {
            tStack_48.tv_sec = 0;
            tStack_48.tv_nsec = 2000000;
            nanosleep(&tStack_48,(timespec *)0x0);
          }
        }
        DAT_01217408 = (int *)0x0;
        while (piVar4 = piVar3, piVar3 != (int *)0x0) {
          while ((piVar3 = *(int **)(piVar4 + 0xc), param_1 != *piVar4 ||
                 ((param_3 != piVar4[1] && (param_3 != piVar4[2]))))) {
            *(int **)(piVar4 + 0xc) = DAT_01217408;
            DAT_01217408 = piVar4;
            piVar4 = piVar3;
            if (piVar3 == (int *)0x0) goto LAB_0023e614;
          }
          FUN_0023d200(piVar4,piVar4[3]);
          free(piVar4);
        }
LAB_0023e614:
        DAT_01217e20 = 0;
      }
      uVar1 = (ulong)uStack_4c;
    }
  }
  return uVar1;
}


// ===== 0019c500 thunk_FUN_0023e7b0 =====

/* WARNING: Type propagation algorithm not settling */

ulong thunk_FUN_0023e7b0(int param_1,undefined4 param_2,uint param_3,ulong *param_4,uint param_5)

{
  undefined8 uVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined1 auVar5 [16];
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  ulong uVar11;
  long lVar12;
  ulong *puVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  long lVar16;
  undefined1 uVar17;
  ulong *puVar18;
  void *pvVar19;
  undefined1 uVar20;
  undefined8 *puVar21;
  int *piVar22;
  uint uVar23;
  uint uVar24;
  char *pcVar25;
  bool bVar26;
  byte bVar27;
  char *pcStack_ac0;
  int *piStack_ab8;
  uint uStack_a90;
  uint uStack_a8c;
  undefined1 auStack_a88 [16];
  timespec tStack_a78;
  undefined1 auStack_a68 [16];
  ulong *puStack_a58;
  undefined8 uStack_a50;
  undefined1 uStack_a48;
  undefined1 uStack_a47;
  int aiStack_a44 [129];
  ulong auStack_840 [128];
  ulong auStack_440 [128];
  uint uStack_40;
  
  auVar5 = stack0xfffffffffffff5a0;
  bVar27 = 0;
  if (param_3 == 0x3d02) {
    param_4[4] = 0;
    lVar12 = FUN_0023d8e0();
    if ((lVar12 != 0) && (puVar13 = (ulong *)FUN_0023c570(lVar12), puVar13 != (ulong *)0x0)) {
      param_4[4] = *puVar13;
    }
LAB_0023e96c:
    bVar26 = false;
    if (param_3 == 0x3d0b) {
      bVar3 = false;
      if ((int)*param_4 == -1) {
        uVar23 = FUN_00240930(param_1,*(int *)((long)param_4 + 4),param_4);
        if (uVar23 != 0) {
          return (ulong)uVar23;
        }
        bVar3 = true;
        uStack_a90 = 0;
      }
    }
    else {
      if (param_3 == 0x3d09) {
        cVar6 = '\x01';
        while( true ) {
          LOCK();
          bVar26 = DAT_01217e20 == 0;
          if (bVar26) {
            DAT_01217e20 = 1;
          }
          UNLOCK();
          if (bVar26) break;
          cVar6 = cVar6 + '\x01';
          if (cVar6 == '\0') {
            auStack_a68._0_8_ = 0;
            auStack_a68._8_8_ = 2000000;
            nanosleep((timespec *)auStack_a68,(timespec *)0x0);
          }
        }
        if (DAT_01216aa8 != 0) {
          FUN_0023d0a0();
          puVar21 = &DAT_01216ac0;
          for (lVar12 = 0x120; lVar12 != 0; lVar12 = lVar12 + -1) {
            *puVar21 = 0;
            puVar21 = puVar21 + (ulong)bVar27 * -2 + 1;
          }
          iVar7 = thunk_FUN_0023c0f0(DAT_00380490,200,0x900,0xc90046c8);
          if (-1 < iVar7) {
            DAT_01217e20 = 0;
            return 0;
          }
          DAT_01217e20 = 0;
          return 0x59;
        }
        DAT_01217e20 = 0;
        return 0x40;
      }
      if (param_3 == 0xfd0104) {
        lVar12 = FUN_0023d8e0(param_1,(int)*param_4);
        if (lVar12 == 0) {
          return 0x26;
        }
        if (**(int **)(lVar12 + 0x28) < 0) {
          return 0x26;
        }
        param_4[1] = (long)**(int **)(lVar12 + 0x28);
        bVar3 = false;
      }
      else {
        if (param_3 != 0xe00101) {
          if (param_3 == 0xd08) {
            *param_4 = 0xffffffffffffffff;
            if ((int)param_4[1] == -1) {
              uVar23 = scandir64("/dev/nvidia-caps-imex-channels",(dirent64 ***)&tStack_a78,
                                 (__selector *)0x0,(__cmp *)PTR_alphasort64_0032efc0);
              if ((int)uVar23 < 0) {
                return 0x59;
              }
              if (uVar23 == 0) {
                uVar24 = 0;
                param_3 = 0xd08;
              }
              else {
                uVar11 = 0;
                pvVar19 = (void *)tStack_a78.tv_sec;
                do {
                  lVar12 = *(long *)((long)pvVar19 + uVar11 * 8);
                  uVar24 = (uint)uVar11;
                  if (((*(char *)(lVar12 + 0x13) != '.') ||
                      ((*(char *)(lVar12 + 0x14) != '\0' &&
                       ((*(char *)(lVar12 + 0x14) != '.' || (*(char *)(lVar12 + 0x15) != '\0'))))))
                     && (iVar7 = __isoc99_sscanf(lVar12 + 0x13,"channel%d",&uStack_a8c),
                        pvVar19 = (void *)tStack_a78.tv_sec, iVar7 == 1)) {
                    snprintf(auStack_a68,0x80,"/dev/nvidia-caps-imex-channels/channel%d",
                             (ulong)uStack_a8c);
                    iVar7 = access(auStack_a68,4);
                    pvVar19 = (void *)tStack_a78.tv_sec;
                    if (iVar7 == 0) break;
                  }
                  uVar11 = uVar11 + 1;
                  uVar24 = uVar24 + 1;
                } while (uVar11 != uVar23);
                for (lVar12 = 0; free(*(void **)((long)pvVar19 + lVar12)),
                    (ulong)(uVar23 - 1) << 3 != lVar12; lVar12 = lVar12 + 8) {
                  pvVar19 = (void *)tStack_a78.tv_sec;
                }
              }
              free((void *)tStack_a78.tv_sec);
              if (uVar23 == uVar24) {
                return 0x1b;
              }
            }
            else {
              snprintf(auStack_a68,0x80,"/dev/nvidia-caps-imex-channels/channel%d");
              param_3 = 0xd08;
            }
            do {
              iVar7 = open64(auStack_a68,0x80000,0);
              if (-1 < iVar7) {
                bVar3 = false;
                *param_4 = (long)iVar7;
                goto LAB_0023e9e4;
              }
              piVar10 = __errno_location();
              iVar7 = *piVar10;
            } while ((iVar7 == 4) || (iVar7 == 0xb));
            if (iVar7 < 1) {
              *piVar10 = 1;
              iVar7 = 1;
            }
            goto LAB_0023ef69;
          }
          goto LAB_0023ee38;
        }
        if (*(int *)((long)param_4 + 4) != param_1) {
          lVar12 = FUN_0023d8e0(param_1);
          if (lVar12 == 0) {
            return 0x26;
          }
          if (**(int **)(lVar12 + 0x28) < 0) {
            return 0x26;
          }
          param_4[0x82] = (long)**(int **)(lVar12 + 0x28);
        }
        bVar3 = false;
      }
    }
  }
  else {
    if (param_3 == 0x2080012e) {
      lVar12 = FUN_0023d8e0();
      if (lVar12 == 0) {
        return 0x22;
      }
      auStack_a68._0_8_ = 0;
      uStack_40 = FUN_0023d7d0(*(undefined4 *)(lVar12 + 0xc),0xd5,8,0xc00846d5,auStack_a68,
                               auStack_a68 + 4);
      *(int *)param_4 = 0;
joined_r0x0023e92b:
      if (uStack_40 == 0) {
        *(undefined4 *)param_4 = auStack_a68._0_4_;
        return 0;
      }
      return (ulong)uStack_40;
    }
    if (param_3 == 0x20803a01) {
      if (0x80 < (uint)param_4[1]) {
        return 0x1f;
      }
      lVar12 = FUN_0023d8e0();
      if (lVar12 == 0) {
        return 0x22;
      }
      uVar1 = *(undefined8 *)((long)param_4 + 4);
      uVar11 = param_4[1];
      puVar21 = (undefined8 *)auStack_a68;
      for (lVar16 = 0x146; lVar16 != 0; lVar16 = lVar16 + -1) {
        *puVar21 = 0;
        puVar21 = puVar21 + (ulong)bVar27 * -2 + 1;
      }
      auStack_a68._4_4_ = param_1;
      auStack_a68._0_4_ = (int)*param_4;
      puStack_a58._0_4_ = *(int *)((long)param_4 + 0xc);
      auStack_a68._8_8_ = uVar1;
      uStack_a50 = param_4[2];
      uStack_a47 = *(undefined1 *)((long)param_4 + 0x19);
      if ((char)param_4[3] != '\0') {
        if ((char)param_4[3] != '\x01') {
          return 0x1f;
        }
        uStack_a48 = 1;
      }
      if ((int)uVar11 != 0) {
        puVar13 = param_4 + 4;
        piVar10 = aiStack_a44;
        puVar18 = auStack_840;
        do {
          piVar22 = piVar10 + 1;
          *piVar10 = (int)*puVar13;
          *puVar18 = puVar13[1];
          puVar18[0x80] = puVar13[2];
          puVar13 = puVar13 + 3;
          piVar10 = piVar22;
          puVar18 = puVar18 + 1;
        } while (piVar22 != aiStack_a44 + (ulong)((int)uVar11 - 1) + 1);
      }
      iVar7 = thunk_FUN_0023c0f0(*(undefined4 *)(lVar12 + 0xc),0xd9,0xa30,0xca3046d9);
      if (-1 < iVar7) goto joined_r0x0023e92b;
LAB_0023f296:
      piVar10 = __errno_location();
      uVar23 = FUN_0023d5d0(*piVar10);
      return (ulong)uVar23;
    }
    if (param_3 == 0x3d07) {
      if (param_5 != 8) {
        return 0x1f;
      }
      cVar6 = '\x01';
      while( true ) {
        LOCK();
        bVar26 = DAT_01217e20 == 0;
        if (bVar26) {
          DAT_01217e20 = 1;
        }
        UNLOCK();
        if (bVar26) break;
        cVar6 = cVar6 + '\x01';
        if (cVar6 == '\0') {
          auStack_a68._0_8_ = 0;
          auStack_a68._8_8_ = 2000000;
          nanosleep((timespec *)auStack_a68,(timespec *)0x0);
        }
      }
      if (DAT_01216aa8 != 0) {
        iVar7 = 0;
        pcVar25 = (char *)&DAT_01216ac0;
        do {
          if ((*pcVar25 != '\0') && (*(int *)(pcVar25 + 0x10) == (int)*param_4)) {
            *(int *)((long)param_4 + 4) = *(int *)(&DAT_01216af8 + (long)iVar7 * 0x48);
            DAT_01217e20 = 0;
            return 0;
          }
          iVar7 = iVar7 + 1;
          pcVar25 = pcVar25 + 0x48;
        } while (iVar7 != 0x20);
      }
      DAT_01217e20 = 0;
      return 0x1f;
    }
    if (param_3 == 0x290) {
      if (param_5 != 4) {
        return 0x1f;
      }
      cVar6 = '\x01';
      while( true ) {
        LOCK();
        bVar26 = DAT_01217e20 == 0;
        if (bVar26) {
          DAT_01217e20 = 1;
        }
        UNLOCK();
        if (bVar26) break;
        cVar6 = cVar6 + '\x01';
        if (cVar6 == '\0') {
          auStack_a68._0_8_ = 0;
          auStack_a68._8_8_ = 2000000;
          nanosleep((timespec *)auStack_a68,(timespec *)0x0);
        }
      }
      pcVar25 = (char *)&DAT_01216ac0;
      uVar11 = 0;
      if (DAT_01216aa8 == 0) {
        DAT_01217e20 = 0;
        return 0x1f;
      }
      while ((*pcVar25 == '\0' || (*(int *)(pcVar25 + 0x10) != (int)*param_4))) {
        uVar23 = (int)uVar11 + 1;
        uVar11 = (ulong)uVar23;
        pcVar25 = pcVar25 + 0x48;
        if (uVar23 == 0x20) {
          DAT_01217e20 = 0;
          return 0x1f;
        }
      }
      if ((int)(&DAT_01217420)[uVar11 * 0x14] < 0) {
        DAT_01217e20 = 0;
        return 0x1f;
      }
      auStack_a68._0_8_ = 0;
      iVar7 = thunk_FUN_0023c0f0((&DAT_01217420)[uVar11 * 0x14],0xda,8,0xc00846da,auStack_a68);
      DAT_01217e20 = 0;
      if (-1 < iVar7) {
        if (auStack_a68._0_4_ == 0) {
          DAT_01217e20 = 0;
          return 0;
        }
        if (auStack_a68._0_4_ != -5) {
          uVar23 = FUN_0023d5d0(-auStack_a68._0_4_);
          return (ulong)uVar23;
        }
        DAT_01217e20 = 0;
        return (ulong)auStack_a68._0_8_ >> 0x20;
      }
      goto LAB_0023f296;
    }
    if (param_3 == 0x3d04) {
      *(int *)param_4 = DAT_00380490;
      return 0;
    }
    if (param_3 == 0x27a) {
      if (param_5 != 8) {
        return 0x1f;
      }
      if ((*(char *)((long)param_4 + 4) == '\0' && *(char *)((long)param_4 + 5) == '\0') &&
          (int)*param_4 == 0) {
        uVar20 = 0;
        uVar17 = 0;
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_00242be0((int)*param_4,*(char *)((long)param_4 + 4),*(char *)((long)param_4 + 5)
                             ,*(undefined1 *)((long)param_4 + 6),1);
        if (iVar7 != 0) goto LAB_0023e881;
        uVar17 = *(undefined1 *)((long)param_4 + 5);
        uVar20 = *(undefined1 *)((long)param_4 + 4);
        iVar7 = (int)*param_4;
      }
      iVar7 = FUN_00242a40(iVar7,uVar20,uVar17,*(undefined1 *)((long)param_4 + 6));
      if (iVar7 == 0) {
        return 0;
      }
LAB_0023e881:
      if (iVar7 == 2) {
        return 0x26;
      }
      piVar10 = __errno_location();
      uVar11 = FUN_0023d5d0(*piVar10);
      return uVar11;
    }
    if (param_3 == 0x278) {
      if (param_5 != 0xc) {
        return 0x1f;
      }
      bVar26 = false;
      if ((*(int *)((long)param_4 + 4) == 1) && ((param_4[1] & 3) == 3)) {
        pcVar25 = (char *)&DAT_01216ac0;
        while ((*pcVar25 == '\0' || ((int)*param_4 != *(int *)(pcVar25 + 0x10)))) {
          pcVar25 = pcVar25 + 0x48;
          if (pcVar25 == &DAT_012173c0) {
            return 0x1f;
          }
        }
        auStack_a68._5_3_ = 0;
        auStack_a68._0_5_ = *(uint5 *)(pcVar25 + 4);
        auStack_a68._9_3_ = 0;
        auStack_a68[8] = pcVar25[9];
        auStack_a88 = (undefined1  [16])0x0;
        puStack_a58 = auVar5._8_8_;
        auStack_a68[0xc] = pcVar25[10];
        auStack_a68._13_3_ = 0;
        iVar7 = FUN_00242b00(auStack_a68,auStack_a88);
        if (iVar7 != 0) goto LAB_0023ef69;
        bVar26 = true;
      }
    }
    else {
      if (param_3 == 0x3d05) {
        if ((int)*param_4 != 1) {
          return 0x3b;
        }
        uVar23 = FUN_00240930(param_1,*(int *)((long)param_4 + 4),param_4 + 2);
        if (uVar23 != 0) {
          return (ulong)uVar23;
        }
        uStack_a90 = 0;
        if ((*(byte *)((long)param_4 + 0x14) & 1) != 0) {
          return 0;
        }
      }
      else {
        if (param_3 != 0x3d0a) goto LAB_0023e96c;
        uStack_a90 = FUN_00240930(param_1,(int)*param_4,param_4 + 9);
        if (uStack_a90 != 0) {
          return (ulong)uStack_a90;
        }
      }
      bVar26 = false;
    }
LAB_0023ee38:
    bVar3 = false;
  }
LAB_0023e9e4:
  auStack_a68._4_4_ = param_2;
  auStack_a68._0_4_ = param_1;
  stack0xfffffffffffff5a4 = SUB1612((undefined1  [16])0x0,4);
  auStack_a68._8_4_ = param_3;
  puStack_a58 = param_4;
  uStack_a50 = (ulong)param_5;
  cVar6 = FUN_00247da0(auStack_a68);
  if (cVar6 == '\0') {
    uStack_a90 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,auStack_a68,(long)&uStack_a50 + 4);
  }
  if (uStack_a90 == 0) {
    if (uStack_a50._4_4_ != 0) goto LAB_0023ea56;
    if (param_3 == 0x278) {
      if (!bVar26) {
        return 0;
      }
      iVar7 = FUN_00242be0(auStack_a88._0_4_,auStack_a88[4],auStack_a88[8],auStack_a88[0xc],0);
      if (iVar7 != 0) {
LAB_0023ef69:
        uVar23 = FUN_0023d5d0(iVar7);
        return (ulong)uVar23;
      }
      goto LAB_0023eab0;
    }
    if (param_3 < 0x279) {
      if (param_3 == 0x215) {
        cVar6 = '\x01';
        while( true ) {
          LOCK();
          bVar26 = DAT_01217e20 == 0;
          if (bVar26) {
            DAT_01217e20 = 1;
          }
          UNLOCK();
          if (bVar26) break;
          cVar6 = cVar6 + '\x01';
          if (cVar6 == '\0') {
            tStack_a78.tv_sec = 0;
            tStack_a78.tv_nsec = 2000000;
            nanosleep(&tStack_a78,(timespec *)0x0);
          }
        }
        pcStack_ac0 = (char *)&DAT_01216ac0;
        pcVar25 = (char *)&DAT_01216ac0;
        piStack_ab8 = &DAT_01217420;
        piVar10 = &DAT_01217420;
        uVar11 = 0;
        while (iVar7 = (int)uVar11, *pcVar25 == '\0') {
LAB_0023f3c8:
          uVar11 = (ulong)(iVar7 + 1U);
          pcVar25 = pcVar25 + 0x48;
          piVar10 = piVar10 + 0x14;
          if (iVar7 + 1U == 0x20) {
            DAT_01217e20 = 0;
            return uStack_a50 >> 0x20;
          }
        }
        iVar8 = (int)*param_4;
        piVar22 = (int *)0x0;
        if (DAT_01216aa8 != 0) {
          piVar22 = piVar10;
        }
        puVar13 = param_4;
        if (iVar8 != 0xffff) {
          while (puVar13 = (ulong *)((long)puVar13 + 4), iVar8 != -1) {
            if (*(int *)(pcVar25 + 0x10) == iVar8) goto LAB_0023f3c0;
            if (puVar13 == param_4 + 0x10) break;
            iVar8 = *(int *)puVar13;
          }
          goto LAB_0023f3c8;
        }
LAB_0023f3c0:
        if (-1 < *piVar22) goto LAB_0023f3c8;
        iVar8 = thunk_FUN_0023c1a0(*(undefined4 *)(pcVar25 + 0x38));
        uStack_a50 = CONCAT44(iVar8,(undefined4)uStack_a50);
        if (iVar8 == 0) {
          iVar8 = FUN_0023d9f0(uVar11,(long)&uStack_a50 + 4);
          *piVar22 = iVar8;
          if (-1 < iVar8) goto LAB_0023f3c8;
        }
        else {
          FUN_0023d3e0(*(undefined8 *)PTR_stderr_0032efe0,
                       "NVIDIA: could not create file for device %u\n",
                       *(undefined4 *)(&DAT_01216af8 + uVar11 * 0x48));
        }
        if (iVar7 != 0) {
          do {
            if (*pcStack_ac0 != '\0') {
              iVar8 = (int)*param_4;
              piVar10 = (int *)0x0;
              if (DAT_01216aa8 != 0) {
                piVar10 = piStack_ab8;
              }
              puVar13 = param_4;
              if (iVar8 == 0xffff) {
LAB_0023f4d4:
                if (-1 < *piVar10) {
                  close(*piVar10);
                  *piVar10 = -1;
                }
              }
              else {
                while (puVar13 = (ulong *)((long)puVar13 + 4), iVar8 != -1) {
                  if (iVar8 == *(int *)(pcStack_ac0 + 0x10)) goto LAB_0023f4d4;
                  if (puVar13 == param_4 + 0x10) break;
                  iVar8 = *(int *)puVar13;
                }
              }
            }
            pcStack_ac0 = pcStack_ac0 + 0x48;
            piStack_ab8 = piStack_ab8 + 0x14;
          } while (pcStack_ac0 != &DAT_01216b08 + (ulong)(iVar7 - 1) * 0x48);
        }
        *(undefined4 *)(param_4 + 0x10) = (&DAT_01216ad0)[uVar11 * 0x12];
      }
      else {
        if (param_3 != 0x216) {
          return 0;
        }
        cVar6 = '\x01';
        while( true ) {
          LOCK();
          bVar26 = DAT_01217e20 == 0;
          if (bVar26) {
            DAT_01217e20 = 1;
          }
          UNLOCK();
          if (bVar26) break;
          cVar6 = cVar6 + '\x01';
          if (cVar6 == '\0') {
            tStack_a78.tv_sec = 0;
            tStack_a78.tv_nsec = 2000000;
            nanosleep(&tStack_a78,(timespec *)0x0);
          }
        }
        pcVar25 = (char *)&DAT_01216ac0;
        piVar10 = &DAT_01217420;
        do {
          if (*pcVar25 != '\0') {
            iVar7 = (int)*param_4;
            piVar22 = (int *)0x0;
            if (DAT_01216aa8 != 0) {
              piVar22 = piVar10;
            }
            puVar13 = param_4;
            if (iVar7 == 0xffff) {
LAB_0023f000:
              if ((piVar22[2] == 0) && (-1 < *piVar22)) {
                close(*piVar22);
                *piVar22 = -1;
              }
            }
            else {
              while (puVar13 = (ulong *)((long)puVar13 + 4), iVar7 != -1) {
                if (*(int *)(pcVar25 + 0x10) == iVar7) goto LAB_0023f000;
                if (puVar13 == param_4 + 0x10) break;
                iVar7 = *(int *)puVar13;
              }
            }
          }
          pcVar25 = pcVar25 + 0x48;
          piVar10 = piVar10 + 0x14;
        } while (pcVar25 != &DAT_012173c0);
      }
      DAT_01217e20 = 0;
      goto LAB_0023eab0;
    }
    if (param_3 == 0x289) {
      cVar6 = '\x01';
      while( true ) {
        LOCK();
        bVar26 = DAT_01217e20 == 0;
        if (bVar26) {
          DAT_01217e20 = 1;
        }
        UNLOCK();
        if (bVar26) break;
        cVar6 = cVar6 + '\x01';
        if (cVar6 == '\0') {
          tStack_a78.tv_sec = 0;
          tStack_a78.tv_nsec = 2000000;
          nanosleep(&tStack_a78,(timespec *)0x0);
        }
      }
      pcVar25 = (char *)&DAT_01216ac0;
      uVar11 = 0;
      while ((*pcVar25 == '\0' || (*(int *)(pcVar25 + 0x10) != (int)*param_4))) {
        uVar23 = (int)uVar11 + 1;
        uVar11 = (ulong)uVar23;
        pcVar25 = pcVar25 + 0x48;
        if (uVar23 == 0x20) {
          DAT_01217e20 = 0;
          return 0x1f;
        }
      }
      if (DAT_01216aa8 == 0) {
        DAT_01217e20 = 0;
        return 0x1f;
      }
      if ((int)(&DAT_01217420)[uVar11 * 0x14] < 0) {
        iVar7 = thunk_FUN_0023c1a0(*(undefined4 *)(&DAT_01216af8 + uVar11 * 0x48));
        uStack_a50 = CONCAT44(iVar7,(undefined4)uStack_a50);
        if (iVar7 != 0) {
          FUN_0023d3e0(*(undefined8 *)PTR_stderr_0032efe0,
                       "NVIDIA: could not create file for device %u\n",
                       *(undefined4 *)(&DAT_01216af8 + uVar11 * 0x48));
          DAT_01217e20 = 0;
          return uStack_a50 >> 0x20;
        }
        iVar8 = FUN_0023d5f0((int)uVar11,(long)&uStack_a50 + 4,0x802);
        iVar7 = iVar8;
        if ((-1 < iVar8) &&
           ((uVar23 = fcntl(iVar8,3,0), (int)uVar23 < 0 ||
            (iVar9 = fcntl(iVar8,4,(ulong)(uVar23 & 0xfffff7ff)), iVar9 < 0)))) {
          piVar10 = __errno_location();
          iVar7 = -1;
          iVar9 = *piVar10;
          close(iVar8);
          uVar23 = FUN_0023d5d0(iVar9);
          uStack_a50 = (ulong)uVar23 << 0x20;
        }
        (&DAT_01217420)[uVar11 * 0x14] = iVar7;
      }
      DAT_01217e20 = 0;
      return uStack_a50 >> 0x20;
    }
    if (param_3 != 0xd08) {
      return 0;
    }
    uVar11 = *param_4;
    if (uVar11 == 0xffffffffffffffff) {
      return 0;
    }
    uVar4 = auStack_a68._0_4_;
    puVar14 = malloc(0x10);
    if (puVar14 != (undefined4 *)0x0) {
      *(undefined8 *)(puVar14 + 2) = 0;
      cVar6 = '\x01';
      puVar14[1] = (int)uVar11;
      *puVar14 = uVar4;
      while( true ) {
        LOCK();
        bVar26 = DAT_01217e20 == 0;
        if (bVar26) {
          DAT_01217e20 = 1;
        }
        UNLOCK();
        if (bVar26) break;
        cVar6 = cVar6 + '\x01';
        if (cVar6 == '\0') {
          tStack_a78.tv_sec = 0;
          tStack_a78.tv_nsec = 2000000;
          nanosleep(&tStack_a78,(timespec *)0x0);
        }
      }
      puVar2 = DAT_01217400;
      if (DAT_01217400 != (undefined4 *)0x0) {
        do {
          puVar15 = puVar2;
          puVar2 = *(undefined4 **)(puVar15 + 2);
        } while (puVar2 != (undefined4 *)0x0);
        *(undefined4 **)(puVar15 + 2) = puVar14;
        puVar14 = DAT_01217400;
      }
      DAT_01217400 = puVar14;
      DAT_01217e20 = 0;
      return 0;
    }
    uStack_a50 = CONCAT44(0x51,(undefined4)uStack_a50);
    uVar11 = uVar11 & 0xffffffff;
  }
  else {
    uStack_a50 = CONCAT44(uStack_a90,(undefined4)uStack_a50);
LAB_0023ea56:
    if (param_3 == 0x3d05) {
      cVar6 = '\x01';
      while( true ) {
        LOCK();
        bVar26 = DAT_01217e20 == 0;
        if (bVar26) {
          DAT_01217e20 = 1;
        }
        UNLOCK();
        if (bVar26) break;
        cVar6 = cVar6 + '\x01';
        if (cVar6 == '\0') {
          tStack_a78.tv_sec = 0;
          tStack_a78.tv_nsec = 2000000;
          nanosleep(&tStack_a78,(timespec *)0x0);
        }
      }
      FUN_0023d370((int)param_4[2]);
      DAT_01217e20 = 0;
      *(int *)(param_4 + 2) = -1;
      goto LAB_0023eab0;
    }
    if (param_3 == 0x3d0a) {
      cVar6 = '\x01';
      while( true ) {
        LOCK();
        bVar26 = DAT_01217e20 == 0;
        if (bVar26) {
          DAT_01217e20 = 1;
        }
        UNLOCK();
        if (bVar26) break;
        cVar6 = cVar6 + '\x01';
        if (cVar6 == '\0') {
          tStack_a78.tv_sec = 0;
          tStack_a78.tv_nsec = 2000000;
          nanosleep(&tStack_a78,(timespec *)0x0);
        }
      }
      FUN_0023d370((int)param_4[9]);
      DAT_01217e20 = 0;
      *(int *)(param_4 + 9) = -1;
      goto LAB_0023eab0;
    }
    if ((param_3 == 0x3d0b) && (bVar3)) {
      cVar6 = '\x01';
      while( true ) {
        LOCK();
        bVar26 = DAT_01217e20 == 0;
        if (bVar26) {
          DAT_01217e20 = 1;
        }
        UNLOCK();
        if (bVar26) break;
        cVar6 = cVar6 + '\x01';
        if (cVar6 == '\0') {
          tStack_a78.tv_sec = 0;
          tStack_a78.tv_nsec = 2000000;
          nanosleep(&tStack_a78,(timespec *)0x0);
        }
      }
      FUN_0023d370((int)*param_4);
      DAT_01217e20 = 0;
      *(int *)param_4 = -1;
      goto LAB_0023eab0;
    }
    if ((param_3 != 0xd08) || (uVar11 = *param_4, uVar11 == 0xffffffffffffffff)) goto LAB_0023eab0;
  }
  close((int)uVar11);
  *param_4 = 0xffffffffffffffff;
LAB_0023eab0:
  return uStack_a50 >> 0x20;
}


// ===== 0019c510 thunk_FUN_002404a0 =====

int thunk_FUN_002404a0(ulong param_1,undefined4 param_2,int *param_3,uint param_4,uint *param_5,
                      undefined8 param_6)

{
  int *piVar1;
  undefined1 auVar2 [16];
  int iVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  int iStack_9c;
  undefined4 uStack_98;
  undefined1 auStack_94 [12];
  undefined1 auStack_88 [16];
  undefined8 uStack_78;
  undefined4 uStack_68;
  undefined4 uStack_64;
  int iStack_60;
  uint uStack_5c;
  uint *puStack_58;
  undefined8 uStack_50;
  undefined1 auStack_48 [16];
  
  iStack_9c = -1;
  if (param_3 == (int *)0x0) {
    return 0x3d;
  }
  uVar6 = param_1 & 0xffffffff;
  uStack_68 = (undefined4)param_1;
  uStack_64 = param_2;
  puStack_58 = param_5;
  uStack_50 = param_6;
  if (param_4 == 0x80) {
    if (param_5 == (uint *)0x0) {
      return 0x1f;
    }
    iVar3 = FUN_0023fc90(param_1,*param_5,0);
    if ((iVar3 < 0) || (iVar3 == 0x20)) {
      return 0x59;
    }
    iVar4 = *param_3;
    if (iVar4 == 0) {
      return 0x56;
    }
    iVar3 = FUN_0023fdb0(uVar6,iVar4,iVar4,iVar3);
    if (iVar3 != 0) {
      return iVar3;
    }
    lVar5 = FUN_0023d8e0(uVar6,*param_3);
    if (lVar5 == 0) {
      return 0x22;
    }
    iStack_60 = *param_3;
    uStack_5c = 0x80;
    auStack_48 = (undefined1  [16])0x0;
    iVar3 = FUN_0023d7d0(DAT_00380490,0x2b,0x30,0xc030462b,&uStack_68,auStack_48 + 8);
    if (iVar3 != 0) {
LAB_00240903:
      FUN_0023d2a0(lVar5);
      return iVar3;
    }
    if (auStack_48._8_4_ == 0) {
      *param_3 = iStack_60;
      return 0;
    }
LAB_0024074e:
    FUN_0023d2a0(lVar5);
    return auStack_48._8_4_;
  }
  uStack_5c = param_4;
  if (param_4 < 0x81) {
    if ((param_4 != 5) && (param_4 != 0x79)) goto LAB_00240760;
    if (param_5 == (uint *)0x0) {
      return 0x1f;
    }
    piVar1 = *(int **)(param_5 + 4);
    if (piVar1 == (int *)0x0) {
      return 0x3d;
    }
    if (*piVar1 < 0) {
      return 0x59;
    }
    lVar5 = FUN_0023cfa0(uVar6);
    if (lVar5 == 0) {
      return 0x36;
    }
    *(long *)(param_5 + 4) = (long)*piVar1;
    iStack_60 = *param_3;
  }
  else {
    if (param_4 == 0x2080) {
      iVar3 = *param_3;
      if (iVar3 == 0) {
        return 0x56;
      }
      lVar5 = FUN_0023d8e0();
      if (lVar5 == 0) {
        return 0x36;
      }
      iVar4 = FUN_0023d9b0(*(undefined8 *)(lVar5 + 0x28));
      if (iVar4 == -1) {
        return 0x26;
      }
      if (param_5 == (uint *)0x0) {
        return 0x1f;
      }
      if (7 < *param_5) {
        return 0x3b;
      }
      uStack_78 = 0;
      auStack_94 = SUB1612((undefined1  [16])0x0,4);
      uStack_98 = (&DAT_01216ad0)[(long)iVar4 * 0x12];
      auStack_88 = (undefined1  [16])0x0;
      iVar4 = FUN_0023e7b0(uVar6,uVar6,0x202,&uStack_98,0x28);
      if (iVar4 != 0) {
        return iVar4;
      }
      iVar4 = FUN_0023fc90(uVar6,auStack_94._4_4_,*param_5);
      if (iVar4 < 0) {
        return 0x59;
      }
      if (iVar4 == 0x20) {
        return 0x59;
      }
      iVar4 = FUN_0023fdb0(uVar6,param_2,iVar3,iVar4);
      if (iVar4 != 0) {
        return iVar4;
      }
      lVar5 = FUN_0023d8e0(uVar6,iVar3);
      if (lVar5 == 0) {
        return 0x22;
      }
      uStack_5c = 0x2080;
      auStack_48 = (undefined1  [16])0x0;
      iStack_60 = iVar3;
      iVar3 = FUN_0023d7d0(DAT_00380490,0x2b,0x30,0xc030462b,&uStack_68,auStack_48 + 8);
      if (iVar3 != 0) goto LAB_00240903;
      if (auStack_48._8_4_ == 0) {
        return 0;
      }
      goto LAB_0024074e;
    }
LAB_00240760:
    iStack_60 = *param_3;
    auStack_48 = (undefined1  [16])0x0;
    if (param_5 == (uint *)0x0) goto LAB_0024058a;
  }
  auStack_48 = (undefined1  [16])0x0;
  iVar3 = FUN_00240080(uVar6,param_2,param_4,param_5,&iStack_9c);
  if (iVar3 != 0) {
    return iVar3;
  }
LAB_0024058a:
  iVar3 = FUN_0023d7d0(DAT_00380490,0x2b,0x30,0xc030462b,&uStack_68,auStack_48 + 8);
  auVar2 = auStack_48;
  if (iStack_9c != -1) {
    close(iStack_9c);
    auVar2 = auStack_48;
  }
  auStack_48._8_4_ = iVar3;
  if (iVar3 == 0) {
    auStack_48._8_4_ = auVar2._8_4_;
    *param_3 = iStack_60;
  }
  return auStack_48._8_4_;
}


// ===== 0019c520 FUN_0019c520 =====

void FUN_0019c520(void)

{
  int iVar1;
  DIR *__dirp;
  byte *__buf;
  dirent *pdVar2;
  ulong uVar3;
  long lVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  byte bVar9;
  int local_2c;
  
  bVar9 = 0;
  FUN_0023dac0();
  do {
    local_2c = -1;
    __dirp = opendir("/proc/self/fd");
    if (__dirp == (DIR *)0x0) {
      return;
    }
    __buf = malloc(0x1000);
    if (__buf == (byte *)0x0) {
      closedir(__dirp);
      return;
    }
    do {
      do {
        pdVar2 = readdir(__dirp);
        if (pdVar2 == (dirent *)0x0) goto LAB_0019c5e8;
        iVar1 = dirfd(__dirp);
        uVar3 = readlinkat(iVar1,pdVar2->d_name,(char *)__buf,0x1000);
      } while (((long)uVar3 < 1) || (bVar7 = uVar3 < 0x1000, uVar3 == 0x1000));
      __buf[uVar3] = 0;
      lVar4 = 0x1b;
      bVar8 = false;
      pbVar5 = __buf;
      pbVar6 = (byte *)"/dev/nvidia-caps/nvidia-cap";
      do {
        if (lVar4 == 0) break;
        lVar4 = lVar4 + -1;
        bVar7 = *pbVar5 < *pbVar6;
        bVar8 = *pbVar5 == *pbVar6;
        pbVar5 = pbVar5 + (ulong)bVar9 * -2 + 1;
        pbVar6 = pbVar6 + (ulong)bVar9 * -2 + 1;
      } while (bVar8);
    } while (((!bVar7 && !bVar8) != bVar7) ||
            (iVar1 = __isoc99_sscanf(pdVar2->d_name,&DAT_002a5e35,&local_2c), iVar1 == -1));
LAB_0019c5e8:
    free(__buf);
    closedir(__dirp);
    if (local_2c < 0) {
      return;
    }
    close(local_2c);
  } while( true );
}


// ===== 0019c620 FUN_0019c620 =====

undefined8 FUN_0019c620(undefined4 param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  long lVar3;
  long *plVar4;
  undefined **ppuVar5;
  uint uVar6;
  byte bVar7;
  float fVar8;
  
  bVar7 = 0;
  if (DAT_012164a0 == (undefined **)0x0) {
    DAT_012164a0 = &PTR_s_RMFunctions_0037ed00;
  }
  if (DAT_01214898 == 0) {
    uVar1 = (**(code **)(PTR_PTR_0037ed20 + 0xa8))(&PTR_s_RMFunctions_0037ed00,param_1);
    if ((int)uVar1 != 0) {
      return uVar1;
    }
    if (DAT_01214898 == 0) {
      return 0;
    }
  }
  plVar4 = &DAT_003a5f70;
  uVar6 = 0;
  do {
    if (*plVar4 == 0) {
      if (4 < DAT_01216a78) {
        fVar8 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        FUN_002340f0((double)(fVar8 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n",
                     "DEBUG",lVar3,"dmal/rm/rm_layer.c",0x6e,uVar6);
      }
      puVar2 = malloc(0x1a0);
      *plVar4 = (long)puVar2;
      if (puVar2 == (undefined8 *)0x0) {
        return 0x14;
      }
      ppuVar5 = &PTR_s_RMFunctions_0037ed00;
      for (lVar3 = 0x34; lVar3 != 0; lVar3 = lVar3 + -1) {
        *puVar2 = *ppuVar5;
        ppuVar5 = ppuVar5 + (ulong)bVar7 * -2 + 1;
        puVar2 = puVar2 + (ulong)bVar7 * -2 + 1;
      }
    }
    uVar6 = uVar6 + 1;
    plVar4 = plVar4 + 0xe940;
    if (DAT_01214898 <= uVar6) {
      return 0;
    }
  } while( true );
}


// ===== 0019c760 FUN_0019c760 =====

undefined2 FUN_0019c760(uint param_1)

{
  undefined2 uVar1;
  
  uVar1 = 999;
  if (param_1 < 0x67) {
    uVar1 = *(undefined2 *)(&DAT_002a7be0 + (ulong)param_1 * 2);
  }
  return uVar1;
}


// ===== 0019c780 FUN_0019c780 =====

int FUN_0019c780(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined8 param_5,undefined4 param_6,undefined8 param_7)

{
  int iVar1;
  long lVar2;
  float fVar3;
  int local_48;
  
  if (DAT_012148d8 != 0) {
    if (DAT_012148dc == 0) {
      return 0xf;
    }
    DAT_012148dc = DAT_012148dc + -1;
  }
  local_48 = 3;
  while( true ) {
    if (4 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%08x %08x\n",
                   "DEBUG",lVar2,"dmal/common/common_ops.c",0x30,param_3,param_4);
    }
    iVar1 = (**(code **)(param_1 + 0x20))(param_2,param_3,param_4,param_5,param_6);
    if (4 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%08x %08x ## 0x%x\n","DEBUG",lVar2,
                   "dmal/common/common_ops.c",0x32,param_3,param_4,iVar1);
    }
    if ((iVar1 != 3) && (iVar1 != 0x66)) break;
    local_48 = local_48 + -1;
    if (local_48 == 0) {
      if (1 < DAT_01216a78) {
        fVar3 = (float)FUN_002917b0(&DAT_01216a60);
        lVar2 = syscall(0xba);
        FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%p\n",
                     "ERROR",lVar2,"dmal/common/common_ops.c",0x46,param_7);
      }
      return iVar1;
    }
    if (2 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%p %x\n",
                   "WARNING",lVar2,"dmal/common/common_ops.c",0x3b,param_7,iVar1);
    }
    FUN_00292f00(100);
  }
  return iVar1;
}


// ===== 0019ca10 FUN_0019ca10 =====

/* WARNING: Restarted to delay deadcode elimination for space: ram */

ulong FUN_0019ca10(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  undefined8 extraout_RDX;
  uint uVar8;
  undefined *puVar9;
  undefined8 *puVar10;
  int *piVar11;
  uint uVar12;
  ulong uVar13;
  ulong __nmemb;
  int *__base;
  int *__s;
  float fVar14;
  undefined8 uVar15;
  undefined8 uStack_24f0;
  undefined8 local_24b8 [16];
  int local_2438 [32];
  int local_23b8 [32];
  int local_2338 [96];
  int local_21b8 [2146];
  
  __base = local_2338;
  __s = local_21b8;
  puVar10 = local_24b8;
  for (lVar7 = 0x30; lVar7 != 0; lVar7 = lVar7 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  piVar11 = __base;
  for (lVar7 = 0x30; lVar7 != 0; lVar7 = lVar7 + -1) {
    piVar11[0] = 0;
    piVar11[1] = 0;
    piVar11 = piVar11 + 2;
  }
  memset(__s,0,0x2180);
  uVar5 = FUN_0019c780(param_1,DAT_0038088c,DAT_0038088c,0x214,local_24b8,0x180,0);
  if (uVar5 < 0x67) {
    uVar13 = (ulong)uVar5;
    switch(uVar5) {
    case 0:
      piVar11 = local_2438;
      __nmemb = uVar13;
      do {
        uVar8 = (uint)uVar13;
        if (*piVar11 == -1) break;
        local_2338[__nmemb * 3] = *piVar11;
        iVar6 = FUN_0019c780(param_1,DAT_0038088c,DAT_0038088c,0x21b,__base + __nmemb * 3,0xc,0);
        if (iVar6 == 0) {
          uVar13 = (ulong)(uVar8 + 1);
          __nmemb = uVar13;
        }
        else if (iVar6 == 0x57) {
          if (2 < DAT_01216a78) {
            iVar6 = local_2338[__nmemb * 3];
            fVar14 = (float)FUN_002917b0(&DAT_01216a60);
            lVar7 = syscall(0xba);
            FUN_002340f0((double)(fVar14 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n",
                         "WARNING",lVar7,"dmal/common/common_nvml.c",0x56,iVar6);
          }
        }
        else if (2 < DAT_01216a78) {
          iVar1 = local_2338[__nmemb * 3];
          fVar14 = (float)FUN_002917b0(&DAT_01216a60);
          lVar7 = syscall(0xba);
          FUN_002340f0((double)(fVar14 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %x\n",
                       "WARNING",lVar7,"dmal/common/common_nvml.c",0x5b,iVar6,iVar1);
        }
        uVar8 = (uint)uVar13;
        piVar11 = piVar11 + 1;
      } while (piVar11 != local_23b8);
      uStack_24f0 = 0x19cd58;
      DAT_01215b68 = uVar8;
      qsort(__base,__nmemb,0xc,FUN_0019d070);
      uVar8 = 0;
      if (DAT_01215b68 != 0) {
        puVar9 = &DAT_0121492c;
        uVar12 = uVar5;
        uVar8 = uVar5;
        do {
          uVar2 = DAT_0038088c;
          iVar6 = *__base;
          __s[1] = 0;
          *__s = iVar6;
          uVar15 = 0;
          iVar6 = FUN_0019c780(param_1,uVar2,uVar2,0x275,__s,0x10c);
          if (iVar6 == 0) {
            uVar13 = (ulong)uVar8;
            (&DAT_012148f8)[uVar13 * 0x25] = __base[1];
            (&DAT_012148fc)[uVar13 * 0x25] = (uint)*(ushort *)(__base + 2);
            (&DAT_01214900)[uVar13 * 0x25] = (uint)*(ushort *)((long)__base + 10);
            uStack_24f0 = 0x19ce6c;
            strncpy(&DAT_0121492c + uVar13 * 0x94,(char *)(__s + 2),0x50);
            if (4 < DAT_01216a78) {
              uVar2 = *(undefined4 *)(puVar9 + -0x2c);
              uVar3 = *(undefined4 *)(puVar9 + -0x30);
              uVar4 = *(undefined4 *)(puVar9 + -0x34);
              fVar14 = (float)FUN_002917b0(&DAT_01216a60);
              uStack_24f0 = 0x19cf4d;
              lVar7 = syscall(0xba);
              FUN_002340f0((double)(fVar14 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u %u %s\n","DEBUG",lVar7,
                           "dmal/common/common_nvml.c",0x8b,uVar4,uVar3,uVar2,puVar9);
            }
            uVar8 = uVar8 + 1;
          }
          else if (iVar6 == 0x57) {
            if (2 < DAT_01216a78) {
              iVar6 = *__s;
              fVar14 = (float)FUN_002917b0(&DAT_01216a60,uStack_24f0,extraout_RDX,uVar15);
              lVar7 = syscall(0xba);
              uStack_24f0 = 0x19cf06;
              FUN_002340f0((double)(fVar14 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n"
                           ,"WARNING",lVar7,"dmal/common/common_nvml.c",0x7b,iVar6);
            }
          }
          else if (2 < DAT_01216a78) {
            iVar1 = *__s;
            fVar14 = (float)FUN_002917b0(&DAT_01216a60,uStack_24f0);
            uStack_24f0 = 0x19d000;
            lVar7 = syscall(0xba);
            FUN_002340f0((double)(fVar14 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %x\n","WARNING",lVar7,
                         "dmal/common/common_nvml.c",0x7f,iVar6,iVar1);
          }
          uVar12 = uVar12 + 1;
          __base = __base + 3;
          __s = __s + 0x43;
          puVar9 = puVar9 + 0x94;
        } while (uVar12 < DAT_01215b68);
      }
      DAT_01215b68 = uVar8;
      uVar13 = (ulong)uVar5;
      break;
    default:
      goto switchD_0019caab_caseD_1;
    case 3:
    case 0x66:
      uVar13 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      uVar13 = 0x13;
      break;
    case 0x1a:
      uVar13 = 0x17;
      break;
    case 0x1b:
      uVar13 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
      uVar13 = 2;
      break;
    case 0x51:
      uVar13 = 0x14;
      break;
    case 0x55:
      uVar13 = 0x1b;
      break;
    case 0x56:
      uVar13 = 3;
      break;
    case 0x59:
      uVar13 = 0x11;
      break;
    case 0x62:
      uVar13 = 0x10;
    }
  }
  else {
switchD_0019caab_caseD_1:
    uVar13 = 999;
  }
  return uVar13;
}


// ===== 0019d070 FUN_0019d070 =====

int FUN_0019d070(long param_1,long param_2)

{
  if (*(int *)(param_1 + 4) != *(int *)(param_2 + 4)) {
    return *(int *)(param_1 + 4) - *(int *)(param_2 + 4);
  }
  if (*(ushort *)(param_1 + 8) != *(ushort *)(param_2 + 8)) {
    return (uint)*(ushort *)(param_1 + 8) - (uint)*(ushort *)(param_2 + 8);
  }
  return (uint)*(ushort *)(param_1 + 10) - (uint)*(ushort *)(param_2 + 10);
}


// ===== 0019d0a0 FUN_0019d0a0 =====

uint FUN_0019d0a0(undefined8 param_1,long param_2,undefined8 param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  float fVar4;
  undefined4 local_2c [3];
  
  lVar3 = *(long *)(param_2 + 0x256d8);
  local_2c[0] = 0;
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    uVar2 = 3;
  }
  else {
    uVar2 = (*pcVar1)(lVar3,param_2,0x2080,local_2c);
    if (uVar2 == 0) {
      uVar2 = FUN_0019c780(param_1,DAT_0038088c,local_2c[0],0x20803601,param_3,0x48,0);
      if (0x66 < uVar2) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002a98a0 + (ulong)uVar2 * 2);
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar2;
  }
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_nvml.c",0x734,"cDeviceGspFirmwareHelper",0x734,
               uVar2);
  return uVar2;
}


// ===== 0019d210 FUN_0019d210 =====

int FUN_0019d210(long param_1,long param_2,undefined4 *param_3)

{
  char *__s1;
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  byte bVar10;
  float fVar11;
  double dVar12;
  undefined8 uVar13;
  char local_3a9;
  undefined4 local_3a8;
  undefined4 local_3a4;
  int local_3a0;
  uint local_39c;
  undefined8 local_398;
  int local_390;
  char local_308 [728];
  
  bVar10 = 0;
  uVar9 = *(undefined8 *)(param_1 + 0x10);
  *param_3 = 0;
  local_3a8 = 0;
  local_3a4 = 0;
  local_3a0 = 0;
  if (*(int *)(param_2 + 0x71c) == 0) {
    do {
      iVar2 = FUN_00291820(param_2 + 0x720,1,0);
    } while (iVar2 != 0);
    if (*(int *)(param_2 + 0x71c) == 0) {
      lVar6 = *(long *)(param_2 + 0x256d8);
      uVar3 = 3;
      if (((lVar6 != 0) && (*(long *)(lVar6 + 0x20) != 0)) &&
         (pcVar1 = *(code **)(*(long *)(lVar6 + 0x20) + 0x98), pcVar1 != (code *)0x0)) {
        uVar3 = (*pcVar1)(lVar6,param_2,param_2 + 0x708);
      }
      *(undefined4 *)(param_2 + 0x724) = uVar3;
      *(undefined4 *)(param_2 + 0x71c) = 1;
    }
    FUN_00291830(param_2 + 0x720,0);
  }
  iVar2 = *(int *)(param_2 + 0x724);
  if (iVar2 == 0) {
    if (*(int *)(param_2 + 0x70534) == 0) {
      do {
        iVar2 = FUN_00291820(param_2 + 0x70538,1,0);
      } while (iVar2 != 0);
      if (*(int *)(param_2 + 0x70534) == 0) {
        lVar6 = *(long *)(param_2 + 0x256d8);
        uVar3 = 3;
        if (((lVar6 != 0) && (*(long *)(lVar6 + 0x38) != 0)) &&
           (pcVar1 = *(code **)(*(long *)(lVar6 + 0x38) + 8), pcVar1 != (code *)0x0)) {
          uVar3 = (*pcVar1)(lVar6,param_2,param_2 + 0x70530);
        }
        *(undefined4 *)(param_2 + 0x7053c) = uVar3;
        *(undefined4 *)(param_2 + 0x70534) = 1;
      }
      FUN_00291830(param_2 + 0x70538,0);
    }
    iVar2 = *(int *)(param_2 + 0x7053c);
    if (iVar2 != 0) {
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar11 = (float)FUN_002917b0(&DAT_01216a60);
      lVar6 = syscall(0xba);
      uVar13 = 0x225;
      uVar9 = 0x225;
      dVar12 = (double)(fVar11 * DAT_00298548);
      goto LAB_0019d59b;
    }
    lVar6 = *(long *)(param_2 + 0x256d8);
    if (((lVar6 == 0) || (*(undefined8 **)(lVar6 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar1 = (code *)**(undefined8 **)(lVar6 + 0x50), pcVar1 == (code *)0x0)) {
      iVar2 = 3;
    }
    else {
      iVar2 = (*pcVar1)(lVar6,param_2,0x2080,&local_3a8);
      if (iVar2 == 0) {
        lVar6 = *(long *)(param_2 + 0x256d8);
        if (((lVar6 == 0) || (*(undefined8 **)(lVar6 + 0x50) == (undefined8 *)0x0)) ||
           (pcVar1 = (code *)**(undefined8 **)(lVar6 + 0x50), pcVar1 == (code *)0x0)) {
          iVar2 = 3;
        }
        else {
          iVar2 = (*pcVar1)(lVar6,param_2,0x80,&local_3a4);
          if (iVar2 == 0) {
            if (*(int *)(param_2 + 0x70530) != 2) {
              puVar7 = &local_398;
              for (lVar6 = 0x46; lVar6 != 0; lVar6 = lVar6 + -1) {
                *puVar7 = 0;
                puVar7 = puVar7 + (ulong)bVar10 * -2 + 1;
              }
              *(undefined4 *)puVar7 = 0;
              local_398 = 0x1100000001;
              iVar2 = FUN_0019c780(uVar9,DAT_0038088c,local_3a8,0x20800102,&local_398,0x234,0);
              switch(iVar2) {
              case 0:
                if (local_390 != 0) {
                  if (*(uint *)(param_2 + 0x708) < 9) {
                    *param_3 = 2;
                    return iVar2;
                  }
                  *param_3 = 0xe;
                  return iVar2;
                }
                break;
              default:
                goto switchD_0019d462_caseD_1;
              case 3:
              case 0x66:
                goto switchD_0019d462_caseD_3;
              case 0xf:
                goto switchD_0019d462_caseD_f;
              case 0x17:
              case 99:
                goto switchD_0019d462_caseD_17;
              case 0x1a:
                goto switchD_0019d462_caseD_1a;
              case 0x1b:
                goto switchD_0019d462_caseD_1b;
              case 0x1f:
              case 0x3b:
              case 0x54:
                goto switchD_0019d462_caseD_1f;
              case 0x51:
                goto switchD_0019d462_caseD_51;
              case 0x55:
                goto switchD_0019d462_caseD_55;
              case 0x56:
                return 3;
              case 0x59:
                goto switchD_0019d462_caseD_59;
              case 0x62:
                goto switchD_0019d462_caseD_62;
              }
            }
            local_39c = 0;
            local_3a9 = '\0';
            iVar2 = FUN_0019c780(uVar9,DAT_0038088c,local_3a4,&DAT_0080028e,&local_3a9,1,0);
            if (iVar2 == 0x56) {
switchD_0019d6ea_caseD_0:
              iVar2 = FUN_0019c780(uVar9,DAT_0038088c,local_3a4,&DAT_00800294,&local_39c,4,0);
              if (iVar2 == 0x56) {
switchD_0019d7eb_caseD_0:
                puVar7 = &local_398;
                puVar8 = puVar7;
                for (lVar6 = 0x6b; lVar6 != 0; lVar6 = lVar6 + -1) {
                  *puVar8 = 0;
                  puVar8 = puVar8 + (ulong)bVar10 * -2 + 1;
                }
                lVar6 = *(long *)(param_1 + 0x20);
                *(undefined4 *)puVar8 = 0;
                iVar2 = (**(code **)(lVar6 + 0xc0))(param_1,param_2,4,&local_3a0,puVar7);
                if ((iVar2 == 0) || (iVar2 == 3)) {
                  if ((local_3a0 == 1) && (local_3a9 != '\0')) {
                    *param_3 = 0;
                    if (local_398._4_4_ != 0) {
                      uVar5 = 0;
                      do {
                        if (*(int *)(puVar7 + 1) == 1) {
                          __s1 = local_308 + uVar5 * 0x11c;
                          iVar2 = strcmp(__s1,"NVIDIA Virtual Applications");
                          if (iVar2 == 0) {
                            *param_3 = 7;
                            return 0;
                          }
                          iVar2 = strcmp(__s1,"NVIDIA Virtual PC");
                          if (iVar2 == 0) {
                            *param_3 = 8;
                            return 0;
                          }
                          iVar2 = strcmp(__s1,"NVIDIA vGPU for Compute");
                          if (iVar2 == 0) {
                            *param_3 = 9;
                            return 0;
                          }
                          iVar2 = strcmp(__s1,"NVIDIA RTX Virtual Workstation");
                          if (iVar2 == 0) {
                            *param_3 = 10;
                            return 0;
                          }
                          iVar2 = strcmp(__s1,"NVIDIA Cloud Gaming");
                          if (iVar2 == 0) {
                            *param_3 = 0xb;
                            return 0;
                          }
                          break;
                        }
                        uVar4 = (int)uVar5 + 1;
                        uVar5 = (ulong)uVar4;
                        puVar7 = (undefined8 *)((long)puVar7 + 0x11c);
                      } while (uVar4 != local_398._4_4_);
                    }
                  }
                  if (((local_39c & 4) != 0) && (6 < *(uint *)(param_2 + 0x708))) {
                    *param_3 = 6;
                    return 0;
                  }
                  if ((local_39c & 1) == 0) {
                    if ((local_39c & 2) == 0) {
                      *param_3 = 5;
                      return 0;
                    }
                    *param_3 = 3;
                    return 0;
                  }
                  if (*(uint *)(param_2 + 0x708) < 9) {
                    *param_3 = 1;
                    return 0;
                  }
                  if (*(uint *)(param_2 + 0x708) != 9) {
                    *param_3 = 0xd;
                    return 0;
                  }
                  *param_3 = 0xc;
                  return 0;
                }
switchD_0019d462_caseD_f:
                return iVar2;
              }
              switch(iVar2) {
              case 0:
                goto switchD_0019d7eb_caseD_0;
              default:
switchD_0019d462_caseD_1:
                return 999;
              case 3:
              case 0x66:
switchD_0019d462_caseD_3:
                return 10;
              case 0xf:
switchD_0019d6ea_caseD_f:
                return 0xf;
              case 0x17:
              case 99:
switchD_0019d462_caseD_17:
                return 0x13;
              case 0x1a:
switchD_0019d462_caseD_1a:
                return 0x17;
              case 0x1b:
switchD_0019d462_caseD_1b:
                return 4;
              case 0x1f:
              case 0x3b:
              case 0x54:
switchD_0019d462_caseD_1f:
                return 2;
              case 0x51:
switchD_0019d462_caseD_51:
                return 0x14;
              case 0x55:
switchD_0019d462_caseD_55:
                return 0x1b;
              case 0x59:
switchD_0019d462_caseD_59:
                return 0x11;
              case 0x62:
switchD_0019d462_caseD_62:
                return 0x10;
              }
            }
            switch(iVar2) {
            case 0:
              goto switchD_0019d6ea_caseD_0;
            default:
              goto switchD_0019d462_caseD_1;
            case 3:
            case 0x66:
              goto switchD_0019d462_caseD_3;
            case 0xf:
              goto switchD_0019d6ea_caseD_f;
            case 0x17:
            case 99:
              goto switchD_0019d462_caseD_17;
            case 0x1a:
              goto switchD_0019d462_caseD_1a;
            case 0x1b:
              goto switchD_0019d462_caseD_1b;
            case 0x1f:
            case 0x3b:
            case 0x54:
              goto switchD_0019d462_caseD_1f;
            case 0x51:
              goto switchD_0019d462_caseD_51;
            case 0x55:
              goto switchD_0019d462_caseD_55;
            case 0x59:
              goto switchD_0019d462_caseD_59;
            case 0x62:
              goto switchD_0019d462_caseD_62;
            }
          }
        }
        if (DAT_01216a78 < 2) {
          return iVar2;
        }
        fVar11 = (float)FUN_002917b0(&DAT_01216a60);
        lVar6 = syscall(0xba);
        uVar13 = 0x22b;
        uVar9 = 0x22b;
        dVar12 = (double)(fVar11 * DAT_00298548);
        goto LAB_0019d59b;
      }
    }
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar11 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    uVar13 = 0x228;
    uVar9 = 0x228;
    dVar12 = (double)(fVar11 * DAT_00298548);
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar11 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    uVar13 = 0x216;
    uVar9 = 0x216;
    dVar12 = (double)(fVar11 * DAT_00298548);
  }
LAB_0019d59b:
  FUN_002340f0(dVar12,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar6,
               "dmal/common/common_nvml.c",uVar9,"cDeviceGetBrandInformationUncached",uVar13,iVar2);
  return iVar2;
}


// ===== 0019d9d0 FUN_0019d9d0 =====

uint FUN_0019d9d0(long param_1,uint param_2,undefined4 *param_3,char param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  char cVar6;
  int *piVar7;
  ulong uVar8;
  undefined8 *puVar9;
  int *piVar10;
  undefined4 *puVar11;
  ulong uVar12;
  undefined4 *puVar13;
  bool bVar14;
  float fVar15;
  undefined1 auVar16 [16];
  undefined8 uVar17;
  undefined8 uStack_2e0;
  undefined4 local_27c;
  undefined4 local_278;
  undefined8 local_274;
  undefined4 local_26c;
  undefined1 local_268 [16];
  undefined1 local_258 [16];
  undefined8 local_248;
  int local_1b8;
  int local_1b4 [31];
  int local_138 [32];
  int local_b8 [34];
  
  piVar7 = &local_1b8;
  for (lVar5 = 0x30; lVar5 != 0; lVar5 = lVar5 + -1) {
    piVar7[0] = 0;
    piVar7[1] = 0;
    piVar7 = piVar7 + 2;
  }
  puVar9 = &local_248;
  for (lVar5 = 0x10; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  local_274 = 0;
  local_26c = 0;
  local_27c = 0;
  local_278 = 0;
  local_268 = (undefined1  [16])0x0;
  *(undefined4 *)puVar9 = 0;
  local_258 = (undefined1  [16])0x0;
  iVar3 = (**(code **)(param_1 + 8))(&DAT_0038088c);
  if (iVar3 == 0) {
    iVar3 = FUN_0019c780(param_1,DAT_0038088c,DAT_0038088c,0x214,&local_1b8,0x180,0);
    if (iVar3 == 0) {
      if (local_1b8 == -1) {
        uVar8 = 0;
        uVar4 = 0;
        if ((local_138[0] == -1) && ((param_2 & 1) == 0)) {
          (**(code **)(param_1 + 0x28))(DAT_0038088c,0,DAT_0038088c);
          if (DAT_01216a78 < 1) {
            return 0x1c;
          }
          fVar15 = (float)FUN_002917b0(&DAT_01216a60);
          lVar5 = syscall(0xba);
          FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       "CRITICAL",lVar5,"dmal/common/common_nvml.c",0xf5);
          return 0x1c;
        }
      }
      else {
        uVar8 = 0;
        uVar4 = 0;
        piVar7 = local_1b4;
        while (local_1b8 != -1) {
          if (piVar7[0x3f] != 1) {
            piVar10 = param_3 + uVar8 * 4;
            *piVar10 = local_1b8;
            iVar3 = FUN_0019c780(param_1,DAT_0038088c,DAT_0038088c,0x21b,piVar10,0xc,0);
            if ((iVar3 == 0) || (iVar3 == 0x56)) {
              uVar4 = uVar4 + 1;
              uVar8 = (ulong)uVar4;
            }
            else if (iVar3 == 0x57) {
              if (2 < DAT_01216a78) {
                iVar3 = *piVar10;
                fVar15 = (float)FUN_002917b0(&DAT_01216a60);
                lVar5 = syscall(0xba);
                FUN_002340f0((double)(fVar15 * DAT_00298548),
                             "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n","WARNING",lVar5,
                             "dmal/common/common_nvml.c",0x118,iVar3);
              }
            }
            else if (2 < DAT_01216a78) {
              iVar2 = *piVar10;
              fVar15 = (float)FUN_002917b0(&DAT_01216a60);
              lVar5 = syscall(0xba);
              FUN_002340f0((double)(fVar15 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %x\n","WARNING",lVar5,
                           "dmal/common/common_nvml.c",0x11d,iVar3,iVar2);
            }
          }
          if (piVar7 == local_138) break;
          local_1b8 = *piVar7;
          piVar7 = piVar7 + 1;
        }
      }
      DAT_01214898 = uVar4;
      uStack_2e0 = 0x19dd82;
      qsort(param_3,uVar8,0x10,FUN_0019d070);
      uVar8 = 0;
      if (DAT_01214898 != 0) {
        do {
          while ((param_2 & 2) != 0) {
LAB_0019dda0:
            bVar14 = true;
LAB_0019dda5:
            (&DAT_003a65f0)[uVar8 * 0x1d280] = 0xffffffff;
            *(byte *)(param_3 + uVar8 * 4 + 3) =
                 bVar14 * '\x02' + 1U | *(byte *)(param_3 + uVar8 * 4 + 3) & 0xfc;
LAB_0019ddd3:
            uVar4 = (int)uVar8 + 1;
            uVar8 = (ulong)uVar4;
            if (DAT_01214898 <= uVar4) goto LAB_0019dfbc;
          }
          puVar11 = param_3 + uVar8 * 4;
          local_274 = CONCAT44(local_274._4_4_,*puVar11);
          iVar3 = FUN_0019c780(param_1,DAT_0038088c,DAT_0038088c,0x279,&local_274,0xc,0);
          uVar12 = local_274;
          if (iVar3 != 0) {
            if (iVar3 == 0x57) {
              if (DAT_01216a78 < 3) goto LAB_0019dda0;
              fVar15 = (float)FUN_002917b0(&DAT_01216a60);
              lVar5 = syscall(0xba);
              uStack_2e0 = 0x19e382;
              FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n"
                           ,"WARNING",lVar5,"dmal/common/common_nvml.c",0x13e,uVar12 & 0xffffffff);
              bVar14 = true;
            }
            else {
              if (DAT_01216a78 < 2) goto LAB_0019dda0;
              fVar15 = (float)FUN_002917b0(&DAT_01216a60);
              uStack_2e0 = 0x19de99;
              lVar5 = syscall(0xba);
              FUN_002340f0((double)(fVar15 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %x\n","ERROR",lVar5,
                           "dmal/common/common_nvml.c",0x143,uVar12 & 0xffffffff,iVar3);
              bVar14 = true;
            }
            goto LAB_0019dda5;
          }
          if (local_274._4_4_ == 1) {
            if (3 < DAT_01216a78) {
              uVar1 = *puVar11;
              fVar15 = (float)FUN_002917b0(&DAT_01216a60);
              lVar5 = syscall(0xba);
              uStack_2e0 = 0x19e2fd;
              FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n"
                           ,&DAT_002983c2,lVar5,"dmal/common/common_nvml.c",0x14c,uVar1);
            }
            goto LAB_0019dda0;
          }
          if (param_4 == '\x01') {
            local_248._4_4_ = 0xffffffff;
            local_248._0_4_ = *puVar11;
            iVar3 = FUN_0019c780(param_1,DAT_0038088c,DAT_0038088c,0x215,&local_248,0x84,0);
            if (iVar3 != 0) {
LAB_0019df5d:
              bVar14 = iVar3 == 0x59 || iVar3 == 0x1b;
              if (DAT_01216a78 < 4) {
                if (bVar14) {
LAB_0019df90:
                  bVar14 = iVar3 != 0x1b;
                  goto LAB_0019dda5;
                }
              }
              else {
                uVar1 = *puVar11;
                fVar15 = (float)FUN_002917b0(&DAT_01216a60);
                uStack_2e0 = 0x19e508;
                lVar5 = syscall(0xba);
                FUN_002340f0((double)(fVar15 * DAT_00298548),
                             "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %x\n",&DAT_002983c2,lVar5,
                             "dmal/common/common_nvml.c",0x16d,uVar1,iVar3);
                if (bVar14) {
                  if (3 < DAT_01216a78) {
                    uVar1 = *puVar11;
                    fVar15 = (float)FUN_002917b0(&DAT_01216a60);
                    lVar5 = syscall(0xba);
                    uStack_2e0 = 0x19e601;
                    FUN_002340f0((double)(fVar15 * DAT_00298548),
                                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n",&DAT_002983c2,lVar5,
                                 "dmal/common/common_nvml.c",0x172,uVar1);
                  }
                  goto LAB_0019df90;
                }
              }
              goto LAB_0019dda0;
            }
            (&DAT_003a65f0)[uVar8 * 0x1d280] = 1;
            goto LAB_0019ddd3;
          }
          local_27c = *puVar11;
          iVar3 = FUN_0019c780(param_1,DAT_0038088c,DAT_0038088c,0x289,&local_27c,4,0);
          if (iVar3 != 0) goto LAB_0019df5d;
          uVar4 = (int)uVar8 + 1;
          local_268[uVar8] = 1;
          uVar8 = (ulong)uVar4;
        } while (uVar4 < DAT_01214898);
LAB_0019dfbc:
        if ((param_4 == '\0') && (DAT_01214898 != 0)) {
          uVar8 = 0;
          puVar11 = &DAT_003a65f0;
          puVar13 = param_3;
          do {
            uVar12 = uVar8 & 0xffffffff;
            if (local_268[uVar8] != '\0') {
              local_278 = *puVar13;
              uVar17 = 0;
              auVar16 = FUN_0019c780(param_1,DAT_0038088c,DAT_0038088c,0x290,&local_278,4);
              iVar3 = auVar16._0_4_;
              if (iVar3 == 0) {
                *puVar11 = 1;
              }
              else {
                uVar4 = (uint)CONCAT71(auVar16._9_7_,iVar3 == 0x1b) |
                        (uint)CONCAT71(auVar16._1_7_,iVar3 == 0x59);
                cVar6 = (char)uVar4;
                if (DAT_01216a78 < 4) {
                  if (cVar6 != '\0') goto LAB_0019e026;
LAB_0019e1aa:
                  *puVar11 = 0xffffffff;
                  *(byte *)(param_3 + uVar12 * 4 + 3) = *(byte *)(param_3 + uVar12 * 4 + 3) | 1;
                }
                else {
                  uVar1 = *puVar13;
                  fVar15 = (float)FUN_002917b0(&DAT_01216a60,uStack_2e0,uVar4,uVar17);
                  uStack_2e0 = 0x19e147;
                  lVar5 = syscall(0xba);
                  FUN_002340f0((double)(fVar15 * DAT_00298548),
                               "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %x\n",&DAT_002983c2,lVar5,
                               "dmal/common/common_nvml.c",0x1aa,uVar1,auVar16._0_8_ & 0xffffffff);
                  if (cVar6 == '\0') goto LAB_0019e1aa;
                  if (3 < DAT_01216a78) {
                    uVar1 = *puVar13;
                    fVar15 = (float)FUN_002917b0(&DAT_01216a60);
                    lVar5 = syscall(0xba);
                    uStack_2e0 = 0x19e4c4;
                    FUN_002340f0((double)(fVar15 * DAT_00298548),
                                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n",&DAT_002983c2,lVar5,
                                 "dmal/common/common_nvml.c",0x1af,uVar1);
                  }
LAB_0019e026:
                  *puVar11 = 0xffffffff;
                  *(byte *)(param_3 + uVar12 * 4 + 3) = *(byte *)(param_3 + uVar12 * 4 + 3) | 1;
                  if (iVar3 == 0x1b) goto LAB_0019e050;
                }
                *(byte *)(param_3 + uVar12 * 4 + 3) = *(byte *)(param_3 + uVar12 * 4 + 3) | 2;
              }
            }
LAB_0019e050:
            uVar8 = uVar8 + 1;
            puVar11 = puVar11 + 0x1d280;
            puVar13 = puVar13 + 4;
          } while ((uint)uVar8 < DAT_01214898);
        }
      }
      uVar4 = FUN_0019ca10(param_1);
      if (uVar4 == 0) {
        return 0;
      }
      (**(code **)(param_1 + 0x28))(DAT_0038088c,0,DAT_0038088c);
      return uVar4;
    }
    (**(code **)(param_1 + 0x28))(DAT_0038088c,0,DAT_0038088c);
    if (iVar3 - 3U < 100) {
      return (uint)*(ushort *)(&DAT_002a97c0 + (ulong)(iVar3 - 3U) * 2);
    }
  }
  else {
    if (0 < DAT_01216a78) {
      fVar15 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n",
                   "CRITICAL",lVar5,"dmal/common/common_nvml.c",0xab,iVar3);
    }
    if (iVar3 == 0xf) {
      return 0xf;
    }
    if (iVar3 == 0x6a) {
      return 0x12;
    }
    uVar4 = FUN_00236e80();
    if ((uVar4 != 0) && (uVar4 != 999)) {
      return uVar4;
    }
    if (iVar3 == 0x59) {
      if (0 < DAT_01216a78) {
        fVar15 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                     "CRITICAL",lVar5,"dmal/common/common_nvml.c",0xc1);
        if (0 < DAT_01216a78) {
          fVar15 = (float)FUN_002917b0(&DAT_01216a60);
          lVar5 = syscall(0xba);
          FUN_002340f0((double)(DAT_00298548 * fVar15),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       "CRITICAL",lVar5,"dmal/common/common_nvml.c",0xc2);
        }
      }
      return 0x11;
    }
  }
  return 999;
}


// ===== 0019e750 FUN_0019e750 =====

undefined2 FUN_0019e750(uint param_1)

{
  undefined2 uVar1;
  
  uVar1 = 999;
  if (param_1 < 0x67) {
    uVar1 = *(undefined2 *)(&DAT_002a98a0 + (ulong)param_1 * 2);
  }
  return uVar1;
}


// ===== 0019e770 FUN_0019e770 =====

undefined4 FUN_0019e770(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x10);
  if ((((*(int *)(param_2 + 0x25728) != 0) && (*(int *)(param_2 + 0x25730) == 0)) &&
      (*(int *)(param_2 + 0x25738) != 0)) && (*(int *)(param_2 + 0x25740) == 0)) {
    if ((*(int *)(param_2 + 0x25798) != 0) && (*(int *)(param_2 + 0x257a0) == 0)) {
      (**(code **)(lVar1 + 0x28))
                (DAT_0038088c,*(undefined4 *)(param_2 + 0x25734),*(undefined4 *)(param_2 + 0x25794))
      ;
    }
    if ((*(int *)(param_2 + 0x25748) != 0) && (*(int *)(param_2 + 0x25750) == 0)) {
      (**(code **)(lVar1 + 0x28))
                (DAT_0038088c,*(undefined4 *)(param_2 + 0x25734),*(undefined4 *)(param_2 + 0x25744))
      ;
    }
    if ((*(int *)(param_2 + 0x25758) != 0) && (*(int *)(param_2 + 0x25760) == 0)) {
      (**(code **)(lVar1 + 0x28))
                (DAT_0038088c,*(undefined4 *)(param_2 + 0x25734),*(undefined4 *)(param_2 + 0x25754))
      ;
    }
    if ((*(int *)(param_2 + 0x25768) != 0) && (*(int *)(param_2 + 0x25770) == 0)) {
      (**(code **)(lVar1 + 0x28))
                (DAT_0038088c,*(undefined4 *)(param_2 + 0x25734),*(undefined4 *)(param_2 + 0x25764))
      ;
    }
    if ((*(int *)(param_2 + 0x25778) != 0) && (*(int *)(param_2 + 0x25780) == 0)) {
      (**(code **)(lVar1 + 0x28))
                (DAT_0038088c,*(undefined4 *)(param_2 + 0x25734),*(undefined4 *)(param_2 + 0x25774))
      ;
    }
    if ((*(int *)(param_2 + 0x257a8) != 0) && (*(int *)(param_2 + 0x257b0) == 0)) {
      (**(code **)(lVar1 + 0x28))
                (DAT_0038088c,*(undefined4 *)(param_2 + 0x25734),*(undefined4 *)(param_2 + 0x257a4))
      ;
    }
  }
  *(undefined4 *)(param_2 + 0x25798) = 0;
  *(undefined4 *)(param_2 + 0x25748) = 0;
  *(undefined4 *)(param_2 + 0x25758) = 0;
  *(undefined4 *)(param_2 + 0x25768) = 0;
  *(undefined4 *)(param_2 + 0x25778) = 0;
  *(undefined4 *)(param_2 + 0x257a8) = 0;
  if ((*(int *)(param_2 + 0x25728) != 0) && (*(int *)(param_2 + 0x25730) == 0)) {
    if ((*(int *)(param_2 + 0x25788) != 0) && (*(int *)(param_2 + 0x25790) == 0)) {
      (**(code **)(lVar1 + 0x28))
                (DAT_0038088c,*(undefined4 *)(param_2 + 0x25724),*(undefined4 *)(param_2 + 0x25784))
      ;
    }
    if ((*(int *)(param_2 + 0x25738) != 0) && (*(int *)(param_2 + 0x25740) == 0)) {
      (**(code **)(lVar1 + 0x28))
                (DAT_0038088c,*(undefined4 *)(param_2 + 0x25724),*(undefined4 *)(param_2 + 0x25734))
      ;
    }
    if ((*(int *)(param_2 + 0x258b8) != 0) && (*(int *)(param_2 + 0x258c0) == 0)) {
      (**(code **)(lVar1 + 0x28))
                (DAT_0038088c,*(undefined4 *)(param_2 + 0x25724),*(undefined4 *)(param_2 + 0x25860))
      ;
    }
  }
  *(undefined4 *)(param_2 + 0x25788) = 0;
  *(undefined4 *)(param_2 + 0x25738) = 0;
  *(undefined4 *)(param_2 + 0x258b8) = 0;
  if ((*(int *)(param_2 + 0x25728) != 0) && (*(int *)(param_2 + 0x25730) == 0)) {
    (**(code **)(lVar1 + 0x28))(DAT_0038088c,DAT_0038088c,*(undefined4 *)(param_2 + 0x25724));
  }
  *(undefined4 *)(param_2 + 0x25728) = 0;
  return *(undefined4 *)(param_2 + 0x25728);
}


// ===== 0019ea90 FUN_0019ea90 =====

void FUN_0019ea90(undefined8 param_1,char *param_2)

{
  void *__ptr;
  long lVar1;
  code *pcVar2;
  
  __ptr = *(void **)(param_2 + 0x25d60);
  if (__ptr != (void *)0x0) {
    if ((*(long *)((long)__ptr + 0x618) != (long)__ptr + 0x618) &&
       (((*param_2 == '\x01' ||
         ((((*(int *)(param_2 + 0x14) != 0 && (*(int *)(param_2 + 0x1c) == 0)) &&
           (*(int *)(param_2 + 0x10) != 0)) && (*(long *)(param_2 + 0x20) != 0)))) &&
        (((lVar1 = *(long *)(param_2 + 0x256d8), lVar1 != 0 && (*(long *)(lVar1 + 0x28) != 0)) &&
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x28) + 0xf8), pcVar2 != (code *)0x0)))))) {
      (*pcVar2)(lVar1,param_2);
    }
    free(__ptr);
    param_2[0x25d60] = '\0';
    param_2[0x25d61] = '\0';
    param_2[0x25d62] = '\0';
    param_2[0x25d63] = '\0';
    param_2[0x25d64] = '\0';
    param_2[0x25d65] = '\0';
    param_2[0x25d66] = '\0';
    param_2[0x25d67] = '\0';
  }
  return;
}


// ===== 0019eb30 FUN_0019eb30 =====

undefined8 FUN_0019eb30(undefined8 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  do {
    iVar2 = FUN_00291820(&DAT_012169a0,1,0);
    iVar1 = DAT_0037eea0;
  } while (iVar2 != 0);
  DAT_0037eea0 = DAT_0037eea0 + 0x10;
  FUN_00291830(&DAT_012169a0,0);
  *param_2 = iVar1;
  return 0;
}


// ===== 0019eb90 FUN_0019eb90 =====

int FUN_0019eb90(undefined8 param_1,long param_2,undefined4 *param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  float fVar6;
  double dVar7;
  undefined8 uVar8;
  int local_3c [3];
  
  local_3c[0] = 0;
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(long *)(lVar4 + 0x20) == 0)) ||
     (pcVar2 = *(code **)(*(long *)(lVar4 + 0x20) + 0x90), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    iVar3 = (*pcVar2)(lVar4,param_2,local_3c);
    if (iVar3 == 0) {
      if (local_3c[0] == 2) {
        if (3 < DAT_01216a78) {
          fVar6 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          uVar5 = 0x42b;
          dVar7 = (double)(fVar6 * DAT_00298548);
          goto LAB_0019eda3;
        }
LAB_0019ed51:
        *param_3 = 1;
        return 0;
      }
      lVar4 = *(long *)(param_2 + 0x256d8);
      if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x48) == (undefined8 *)0x0)) ||
         ((pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x48), pcVar2 == (code *)0x0 ||
          ((iVar3 = (*pcVar2)(lVar4,param_2,param_2 + 0x728), iVar3 == 3 || (iVar3 == 0)))))) {
        if (local_3c[0] == 1) {
          if (3 < DAT_01216a78) {
            fVar6 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            uVar5 = 0x43a;
            dVar7 = (double)(fVar6 * DAT_00298548);
            goto LAB_0019eda3;
          }
        }
        else if (local_3c[0] - 7U < 5) {
          if (3 < DAT_01216a78) {
            fVar6 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                         &DAT_002983c2,lVar4,"dmal/common/common_nvml.c",0x443);
            if (3 < DAT_01216a78) {
              fVar6 = (float)FUN_002917b0(&DAT_01216a60);
              lVar4 = syscall(0xba);
              uVar5 = 0x444;
              dVar7 = (double)(DAT_00298548 * fVar6);
              goto LAB_0019eda3;
            }
          }
        }
        else if (local_3c[0] == 6) {
          if (3 < DAT_01216a78) {
            fVar6 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            uVar5 = 0x44c;
            dVar7 = (double)(fVar6 * DAT_00298548);
            goto LAB_0019eda3;
          }
        }
        else if (local_3c[0] == 5) {
          if (*(uint *)(param_2 + 0x708) < 6) {
            uVar1 = *(uint *)(param_2 + 0x728);
            if ((uVar1 != 0x100c10de && uVar1 != 0x17c210de) && ((uVar1 & 0xfffbffff) != 0x100110de)
               ) {
LAB_0019ec9f:
              if (3 < DAT_01216a78) {
                fVar6 = (float)FUN_002917b0(&DAT_01216a60);
                lVar4 = syscall(0xba);
                FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                             &DAT_002983c2,lVar4,"dmal/common/common_nvml.c",0x485);
              }
              *param_3 = 0;
              return 0;
            }
            if (3 < DAT_01216a78) {
              fVar6 = (float)FUN_002917b0(&DAT_01216a60);
              lVar4 = syscall(0xba);
              uVar5 = 0x45b;
              dVar7 = (double)(fVar6 * DAT_00298548);
              goto LAB_0019eda3;
            }
          }
          else if (3 < DAT_01216a78) {
            fVar6 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            uVar5 = 0x455;
            dVar7 = (double)(fVar6 * DAT_00298548);
            goto LAB_0019eda3;
          }
        }
        else if (local_3c[0] == 0xc) {
          if (3 < DAT_01216a78) {
            fVar6 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            uVar5 = 0x463;
            dVar7 = (double)(fVar6 * DAT_00298548);
LAB_0019eda3:
            FUN_002340f0(dVar7,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",&DAT_002983c2,lVar4,
                         "dmal/common/common_nvml.c",uVar5);
            *param_3 = 1;
            return 0;
          }
        }
        else if (local_3c[0] == 0xd) {
          if (3 < DAT_01216a78) {
            fVar6 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            uVar5 = 0x46a;
            dVar7 = (double)(fVar6 * DAT_00298548);
            goto LAB_0019eda3;
          }
        }
        else if (local_3c[0] == 0xe) {
          if (3 < DAT_01216a78) {
            fVar6 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            uVar5 = 0x471;
            dVar7 = (double)(fVar6 * DAT_00298548);
            goto LAB_0019eda3;
          }
        }
        else if (local_3c[0] == 0xf) {
          if (3 < DAT_01216a78) {
            fVar6 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            uVar5 = 0x478;
            dVar7 = (double)(fVar6 * DAT_00298548);
            goto LAB_0019eda3;
          }
        }
        else {
          if (local_3c[0] != 0x10) goto LAB_0019ec9f;
          if (3 < DAT_01216a78) {
            fVar6 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            uVar5 = 0x47f;
            dVar7 = (double)(fVar6 * DAT_00298548);
            goto LAB_0019eda3;
          }
        }
        goto LAB_0019ed51;
      }
      if (DAT_01216a78 < 2) {
        return iVar3;
      }
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      fVar6 = fVar6 * DAT_00298548;
      uVar8 = 0x435;
      uVar5 = 0x435;
      goto LAB_0019ed1f;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar3;
  }
  fVar6 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  fVar6 = fVar6 * DAT_00298548;
  uVar8 = 0x427;
  uVar5 = 0x427;
LAB_0019ed1f:
  FUN_002340f0((double)fVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
               "dmal/common/common_nvml.c",uVar5,"cIsDeviceSupported",uVar8,iVar3);
  return iVar3;
}


// ===== 0019f200 FUN_0019f200 =====

undefined4 FUN_0019f200(undefined8 param_1,long param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  float fVar6;
  
  if (*(int *)(param_2 + 0x6fc) == 0) {
    do {
      iVar3 = FUN_00291820(param_2 + 0x700,1,0);
    } while (iVar3 != 0);
    if (*(int *)(param_2 + 0x6fc) == 0) {
      uVar4 = FUN_0019d210(param_1,param_2,param_2 + 0x6f8);
      *(undefined4 *)(param_2 + 0x6fc) = 1;
      *(undefined4 *)(param_2 + 0x704) = uVar4;
    }
    FUN_00291830(param_2 + 0x700,0);
  }
  uVar4 = *(undefined4 *)(param_2 + 0x6f8);
  uVar1 = *(undefined4 *)(param_2 + 0x704);
  *param_3 = uVar4;
  if (DAT_01216a78 < 5) {
    return uVar1;
  }
  uVar2 = *(undefined4 *)(param_2 + 4);
  fVar6 = (float)FUN_002917b0(&DAT_01216a60);
  lVar5 = syscall(0xba);
  FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %d %d\n",
               "DEBUG",lVar5,"dmal/common/common_nvml.c",0x494,uVar2,uVar4,uVar1);
  return uVar1;
}


// ===== 0019f330 FUN_0019f330 =====

int FUN_0019f330(long param_1,long param_2,undefined4 *param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  float fVar7;
  undefined8 uVar8;
  undefined4 local_6c;
  undefined1 local_68 [16];
  undefined1 local_58 [8];
  undefined8 local_50;
  
  lVar6 = *(long *)(param_2 + 0x256d8);
  local_68 = (undefined1  [16])0x0;
  if (((lVar6 == 0) || (*(undefined8 **)(lVar6 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar6 + 0x50), pcVar1 == (code *)0x0)) {
    iVar4 = 3;
  }
  else {
    uVar2 = *(undefined8 *)(param_1 + 0x10);
    iVar4 = (*pcVar1)(lVar6,param_2,0x2080,&local_6c);
    if (iVar4 == 0) {
      uVar8 = 0;
      iVar5 = FUN_0019c780(uVar2,DAT_0038088c,local_6c,0x20801701,local_68,0x10);
      iVar4 = DAT_01216a78;
      switch(iVar5) {
      case 0:
        goto switchD_0019f467_caseD_0;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar5;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (1 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar6,"dmal/common/common_nvml.c",0x4a7,"cDeviceGetChipInformation",0x4a7,
                 iVar4);
  }
  return iVar4;
switchD_0019f467_caseD_0:
  uVar3 = local_68._0_4_;
  param_3[1] = local_68._0_4_;
  param_3[2] = local_68._4_4_;
  if (4 < iVar4) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60,uVar8);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %x\n","DEBUG"
                 ,lVar6,"dmal/common/common_nvml.c",0x4af,uVar3);
  }
  if (local_68._0_4_ == 0x170) {
    *param_3 = 10;
    goto LAB_0019f588;
  }
  if ((uint)local_68._0_4_ < 0x171) {
    if (local_68._0_4_ == 0x130) {
      *param_3 = 7;
      goto LAB_0019f588;
    }
    if ((uint)local_68._0_4_ < 0x131) {
      if (local_68._0_4_ == 0x110) {
LAB_0019f628:
        *param_3 = 6;
        goto LAB_0019f588;
      }
      if ((uint)local_68._0_4_ < 0x111) {
        if ((local_68._0_4_ == 0x100) || ((local_68._0_4_ & 0xffffffef) == 0xe0)) {
          *param_3 = 5;
          goto LAB_0019f588;
        }
      }
      else if (local_68._0_4_ == 0x120) goto LAB_0019f628;
    }
    else {
      if (local_68._0_4_ == 0x160) {
        *param_3 = 9;
        goto LAB_0019f588;
      }
      if (((uint)local_68._0_4_ < 0x161) && ((local_68._0_4_ & 0xffffffef) == 0x140)) {
        *param_3 = 8;
        goto LAB_0019f588;
      }
    }
  }
  else {
    if (local_68._0_4_ == 0x1a0) {
LAB_0019f752:
      *param_3 = 0xd;
      goto LAB_0019f588;
    }
    if ((uint)local_68._0_4_ < 0x1a1) {
      if (local_68._0_4_ == 0x180) {
        *param_3 = 0xc;
        goto LAB_0019f588;
      }
      if (local_68._0_4_ == 400) {
        *param_3 = 0xb;
        goto LAB_0019f588;
      }
    }
    else {
      if (local_68._0_4_ == 0x1b0) goto LAB_0019f752;
      if (local_68._0_4_ == 0xe0000023) {
        *param_3 = 0xe;
        goto LAB_0019f588;
      }
    }
  }
  if (0 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","CRITICAL",
                 lVar6,"dmal/common/common_nvml.c",0x4ff);
  }
  *param_3 = 0xffffffff;
LAB_0019f588:
  iVar4 = FUN_0024a160(param_3[1],param_3[2],local_58);
  if (iVar4 == 0) {
    *(undefined8 *)(param_3 + 3) = local_50;
    return 0;
  }
  *(undefined8 *)(param_3 + 3) = 0xffffffffffffffff;
  return iVar5;
}


// ===== 0019f780 FUN_0019f780 =====

undefined8 FUN_0019f780(undefined8 param_1,int param_2,int param_3,undefined4 *param_4)

{
  int *piVar1;
  long lVar2;
  int iVar3;
  undefined8 *puVar4;
  int *piVar5;
  int local_368 [2];
  undefined4 auStack_360 [214];
  
  iVar3 = 0;
  piVar1 = local_368;
  puVar4 = &DAT_002a8580;
  piVar5 = local_368;
  for (lVar2 = 0x6c; lVar2 != 0; lVar2 = lVar2 + -1) {
    *(undefined8 *)piVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    piVar5 = piVar5 + 2;
  }
  while ((*piVar1 != param_2 || (piVar1[1] != param_3))) {
    iVar3 = iVar3 + 1;
    piVar1 = piVar1 + 3;
    if (iVar3 == 0x48) {
      *param_4 = 0xffffffff;
      return 0;
    }
  }
  *param_4 = auStack_360[(long)iVar3 * 3];
  return 0;
}


// ===== 0019f800 FUN_0019f800 =====

int FUN_0019f800(undefined8 param_1,long param_2,undefined1 *param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  float fVar5;
  
  if (*(int *)(param_2 + 0x71c) == 0) {
    do {
      iVar2 = FUN_00291820(param_2 + 0x720,1,0);
    } while (iVar2 != 0);
    if (*(int *)(param_2 + 0x71c) == 0) {
      lVar4 = *(long *)(param_2 + 0x256d8);
      uVar3 = 3;
      if (((lVar4 != 0) && (*(long *)(lVar4 + 0x20) != 0)) &&
         (pcVar1 = *(code **)(*(long *)(lVar4 + 0x20) + 0x98), pcVar1 != (code *)0x0)) {
        uVar3 = (*pcVar1)(lVar4,param_2,param_2 + 0x708);
      }
      *(undefined4 *)(param_2 + 0x724) = uVar3;
      *(undefined4 *)(param_2 + 0x71c) = 1;
    }
    FUN_00291830(param_2 + 0x720,0);
  }
  iVar2 = *(int *)(param_2 + 0x724);
  if (iVar2 == 0) {
    if (((*(uint *)(param_2 + 0x70c) & 0xffffffef) == 0x1a0) && (*(int *)(param_2 + 0x710) == 0xb))
    {
      *param_3 = 1;
    }
    else {
      *param_3 = 0;
    }
  }
  else if (1 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_nvml.c",0x594,"cIsDeviceIGPU",0x594,iVar2);
    return iVar2;
  }
  return iVar2;
}


// ===== 0019f970 FUN_0019f970 =====

uint FUN_0019f970(long param_1)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  undefined8 *puVar4;
  uint uVar5;
  uint uVar6;
  float fVar7;
  undefined8 local_b8 [17];
  
  lVar1 = *(long *)(param_1 + 0x10);
  puVar4 = local_b8;
  for (lVar3 = 0x10; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  if (DAT_01214898 != 0) {
    uVar2 = 0;
    do {
      uVar5 = (int)uVar2 + 1;
      FUN_001354b0(&DAT_00380898 + uVar2 * 0x74a00,1);
      uVar2 = (ulong)uVar5;
    } while (uVar5 < DAT_01214898);
    if (DAT_01214898 != 0) {
      uVar2 = 0;
      do {
        uVar5 = (int)uVar2 + 1;
        FUN_0019e770(param_1,&DAT_00380898 + uVar2 * 0x74a00);
        uVar2 = (ulong)uVar5;
      } while (uVar5 < DAT_01214898);
      if (DAT_01214898 != 0) {
        uVar5 = 0;
        do {
          uVar2 = (ulong)uVar5;
          uVar5 = uVar5 + 1;
          FUN_0019ea90(param_1,&DAT_00380898 + uVar2 * 0x74a00);
        } while (uVar5 < DAT_01214898);
      }
    }
  }
  local_b8[0] = 0xffffffff0000ffff;
  if (4 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                 lVar3,"dmal/common/common_nvml.c",0x5c1);
  }
  uVar5 = FUN_0019c780(lVar1,DAT_0038088c,DAT_0038088c,0x216,local_b8,0x80,0);
  switch(uVar5) {
  case 0:
    puVar4 = &DAT_003a5f70;
    uVar6 = uVar5;
    if (DAT_01214898 != 0) {
      do {
        if ((void *)puVar4[-0x205c] != (void *)0x0) {
          free((void *)puVar4[-0x205c]);
        }
        uVar6 = uVar6 + 1;
        free((void *)*puVar4);
        *puVar4 = 0;
        puVar4 = puVar4 + 0xe940;
      } while (uVar6 < DAT_01214898);
    }
    DAT_01214898 = 0;
    (**(code **)(lVar1 + 0x28))(DAT_0038088c,DAT_0038088c,DAT_0038088c);
    break;
  default:
    uVar5 = 999;
    break;
  case 3:
  case 0x66:
    uVar5 = 10;
    break;
  case 0xf:
    break;
  case 0x17:
  case 99:
    uVar5 = 0x13;
    break;
  case 0x1a:
    uVar5 = 0x17;
    break;
  case 0x1b:
    uVar5 = 4;
    break;
  case 0x1f:
  case 0x3b:
  case 0x54:
    uVar5 = 2;
    break;
  case 0x51:
    uVar5 = 0x14;
    break;
  case 0x55:
    uVar5 = 0x1b;
    break;
  case 0x56:
    uVar5 = 3;
    break;
  case 0x59:
    uVar5 = 0x11;
    break;
  case 0x62:
    uVar5 = 0x10;
  }
  return uVar5;
}


// ===== 0019fc20 FUN_0019fc20 =====

int FUN_0019fc20(long param_1,char *param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  long lVar6;
  void *pvVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  byte bVar10;
  float fVar11;
  double dVar12;
  undefined8 uVar13;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined8 local_c0 [18];
  
  bVar10 = 0;
  if (*param_2 == '\x01') {
    return 0;
  }
  iVar3 = FUN_00135420(param_2);
  if (iVar3 != 0) {
    if (DAT_01216a78 < 2) {
      return iVar3;
    }
    fVar11 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    uVar13 = 0x5e6;
    uVar9 = 0x5e6;
    dVar12 = (double)(fVar11 * DAT_00298548);
    goto LAB_0019fd17;
  }
  if (*(int *)(param_2 + 0x14) == 0) {
    do {
      iVar3 = FUN_00291820(param_2 + 0x18,1,0);
    } while (iVar3 != 0);
    if (*(int *)(param_2 + 0x14) == 0) {
      puVar8 = local_c0;
      for (lVar6 = 0xf; lVar6 != 0; lVar6 = lVar6 + -1) {
        *puVar8 = 0;
        puVar8 = puVar8 + (ulong)bVar10 * -2 + 1;
      }
      local_c8 = *(undefined4 *)(param_2 + 0x256e0);
      param_2[0x10] = '\x01';
      param_2[0x11] = '\0';
      param_2[0x12] = '\0';
      param_2[0x13] = '\0';
      uVar9 = *(undefined8 *)(param_1 + 0x10);
      local_d0 = 0;
      *(undefined4 *)puVar8 = 0;
      uStack_c4 = 0xffffffff;
      uVar5 = FUN_0019c780(uVar9,DAT_0038088c,DAT_0038088c,0x215,&local_c8,0x84,0);
      if (uVar5 == 0) {
        uVar4 = 0;
        if (3 < DAT_01216a78) {
          fVar11 = (float)FUN_002917b0(&DAT_01216a60);
          lVar6 = syscall(0xba);
          FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar6,"dmal/common/common_nvml.c",0x36e);
        }
      }
      else {
        local_d0 = CONCAT44(local_d0._4_4_,*(undefined4 *)(param_2 + 0x256e0));
        iVar3 = FUN_0019c780(uVar9,DAT_0038088c,DAT_0038088c,0x203,&local_d0,8,0);
        if ((iVar3 == 0) && (local_d0._4_4_ != 0)) {
          uVar5 = local_d0._4_4_;
        }
        if (uVar5 < 0x47) {
          if (uVar5 < 0x45) {
            if (uVar5 == 0x1b) {
              uVar4 = 4;
              if (2 < DAT_01216a78) {
                fVar11 = (float)FUN_002917b0(&DAT_01216a60);
                lVar6 = syscall(0xba);
                FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n"
                             ,"WARNING",lVar6,"dmal/common/common_nvml.c",0x372);
              }
            }
            else if (uVar5 < 0x1c) {
              if (uVar5 != 0xf) goto LAB_001a0718;
              uVar4 = 0xf;
              if (1 < DAT_01216a78) {
                fVar11 = (float)FUN_002917b0(&DAT_01216a60);
                lVar6 = syscall(0xba);
                uVar9 = 900;
                dVar12 = (double)(fVar11 * DAT_00298548);
                goto LAB_001a03a8;
              }
            }
            else if (uVar5 == 0x1c) {
              uVar4 = 8;
              if (0 < DAT_01216a78) {
                fVar11 = (float)FUN_002917b0(&DAT_01216a60);
                lVar6 = syscall(0xba);
                uVar9 = 0x376;
                dVar12 = (double)(fVar11 * DAT_00298548);
                uVar4 = 8;
                goto LAB_001a0321;
              }
            }
            else {
LAB_001a0718:
              uVar4 = 999;
              if (1 < DAT_01216a78) {
                fVar11 = (float)FUN_002917b0(&DAT_01216a60);
                lVar6 = syscall(0xba);
                uVar9 = 0x38c;
                dVar12 = (double)(fVar11 * DAT_00298548);
                goto LAB_001a03a8;
              }
            }
          }
          else {
            uVar4 = 0xb;
            if (0 < DAT_01216a78) {
              fVar11 = (float)FUN_002917b0(&DAT_01216a60);
              lVar6 = syscall(0xba);
              uVar9 = 0x37f;
              dVar12 = (double)(fVar11 * DAT_00298548);
LAB_001a0321:
              FUN_002340f0(dVar12,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","CRITICAL",lVar6,
                           "dmal/common/common_nvml.c",uVar9);
            }
          }
        }
        else if (uVar5 == 0x59) {
          uVar4 = 9;
          if (0 < DAT_01216a78) {
            fVar11 = (float)FUN_002917b0(&DAT_01216a60);
            lVar6 = syscall(0xba);
            uVar9 = 0x37a;
            dVar12 = (double)(fVar11 * DAT_00298548);
            goto LAB_001a0321;
          }
        }
        else {
          if (uVar5 != 0x62) goto LAB_001a0718;
          uVar4 = 0x10;
          if (1 < DAT_01216a78) {
            fVar11 = (float)FUN_002917b0(&DAT_01216a60);
            lVar6 = syscall(0xba);
            uVar9 = 0x388;
            dVar12 = (double)(fVar11 * DAT_00298548);
            uVar4 = 0x10;
LAB_001a03a8:
            FUN_002340f0(dVar12,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar6,
                         "dmal/common/common_nvml.c",uVar9);
          }
        }
      }
      *(undefined4 *)(param_2 + 0x1c) = uVar4;
      param_2[0x14] = '\x01';
      param_2[0x15] = '\0';
      param_2[0x16] = '\0';
      param_2[0x17] = '\0';
    }
    FUN_00291830(param_2 + 0x18,0);
  }
  iVar3 = *(int *)(param_2 + 0x1c);
  if (iVar3 != 0) {
    if (DAT_01216a78 < 2) {
      return iVar3;
    }
    fVar11 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    uVar13 = 0x5eb;
    uVar9 = 0x5eb;
    dVar12 = (double)(fVar11 * DAT_00298548);
    goto LAB_0019fd17;
  }
  if (*(int *)(param_2 + 0x70534) == 0) {
    do {
      iVar3 = FUN_00291820(param_2 + 0x70538,1,0);
    } while (iVar3 != 0);
    if (*(int *)(param_2 + 0x70534) == 0) {
      uVar4 = (**(code **)(*(long *)(param_1 + 0x38) + 8))(param_1,param_2,param_2 + 0x70530);
      param_2[0x70534] = '\x01';
      param_2[0x70535] = '\0';
      param_2[0x70536] = '\0';
      param_2[0x70537] = '\0';
      *(undefined4 *)(param_2 + 0x7053c) = uVar4;
    }
    FUN_00291830(param_2 + 0x70538,0);
  }
  iVar3 = *(int *)(param_2 + 0x7053c);
  if (iVar3 == 0) {
    if ((*(int *)(param_2 + 0x70530) != 3) || (*(long *)(param_2 + 0x25d60) != 0)) {
LAB_0019fdda:
      lVar6 = *(long *)(param_2 + 0x256d8);
      if (((lVar6 == 0) || (*(undefined8 **)(lVar6 + 0x40) == (undefined8 *)0x0)) ||
         (pcVar1 = (code *)**(undefined8 **)(lVar6 + 0x40), pcVar1 == (code *)0x0)) {
        iVar3 = 3;
LAB_001a0176:
        if (DAT_01216a78 < 2) {
          return iVar3;
        }
        fVar11 = (float)FUN_002917b0(&DAT_01216a60);
        lVar6 = syscall(0xba);
        FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n"
                     ,"ERROR",lVar6,"dmal/common/common_nvml.c",0x3c7,"cDmalDeviceInit",0x3c7,iVar3)
        ;
      }
      else {
        iVar3 = (*pcVar1)(lVar6,param_2);
        if (iVar3 != 0) goto LAB_001a0176;
        if (*(int *)(param_2 + 0x71c) == 0) {
          do {
            iVar3 = FUN_00291820(param_2 + 0x720,1,0);
          } while (iVar3 != 0);
          if (*(int *)(param_2 + 0x71c) == 0) {
            lVar6 = *(long *)(param_2 + 0x256d8);
            uVar4 = 3;
            if (((lVar6 != 0) && (*(long *)(lVar6 + 0x20) != 0)) &&
               (pcVar1 = *(code **)(*(long *)(lVar6 + 0x20) + 0x98), pcVar1 != (code *)0x0)) {
              uVar4 = (*pcVar1)(lVar6,param_2,param_2 + 0x708);
            }
            *(undefined4 *)(param_2 + 0x724) = uVar4;
            param_2[0x71c] = '\x01';
            param_2[0x71d] = '\0';
            param_2[0x71e] = '\0';
            param_2[0x71f] = '\0';
          }
          FUN_00291830(param_2 + 0x720,0);
        }
        iVar3 = *(int *)(param_2 + 0x724);
        if (iVar3 == 0) {
          lVar6 = *(long *)(param_2 + 0x256d8);
          if (((lVar6 == 0) || (*(long *)(lVar6 + 0x38) == 0)) ||
             (pcVar1 = *(code **)(*(long *)(lVar6 + 0x38) + 0x40), pcVar1 == (code *)0x0)) {
            iVar3 = 3;
          }
          else {
            iVar3 = (*pcVar1)(lVar6,param_2,param_2 + 0x380);
            if (iVar3 == 0) {
              param_2[0x580] = '\0';
              if (((*(int *)(param_2 + 0x70c) == 0x1a0) && (*(int *)(param_2 + 0x710) == 0xb)) &&
                 ((iVar3 = FUN_00132ff0(*(undefined8 *)(param_2 + 0x256d8)), iVar3 != 0 &&
                  (1 < DAT_01216a78)))) {
                fVar11 = (float)FUN_002917b0(&DAT_01216a60);
                lVar6 = syscall(0xba);
                FUN_002340f0((double)(fVar11 * DAT_00298548),
                             "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","ERROR",lVar6,
                             "dmal/common/common_nvml.c",0x3eb,iVar3);
                return 0;
              }
              return 0;
            }
          }
          if (4 < DAT_01216a78) {
            fVar11 = (float)FUN_002917b0(&DAT_01216a60);
            lVar6 = syscall(0xba);
            FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",
                         "DEBUG",lVar6,"dmal/common/common_nvml.c",0x3d5,iVar3);
          }
        }
        else {
          if (DAT_01216a78 < 2) {
            return iVar3;
          }
          fVar11 = (float)FUN_002917b0(&DAT_01216a60);
          lVar6 = syscall(0xba);
          FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",
                       "ERROR",lVar6,"dmal/common/common_nvml.c",0x3cd,iVar3);
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar3;
      }
      fVar11 = (float)FUN_002917b0(&DAT_01216a60);
      lVar6 = syscall(0xba);
      uVar13 = 0x5f1;
      uVar9 = 0x5f1;
      dVar12 = (double)(fVar11 * DAT_00298548);
      goto LAB_0019fd17;
    }
    pvVar7 = calloc(0x640,1);
    *(void **)(param_2 + 0x25d60) = pvVar7;
    if (pvVar7 == (void *)0x0) {
      if (DAT_01216a78 < 2) {
        return 999;
      }
      iVar3 = 999;
      fVar11 = (float)FUN_002917b0(&DAT_01216a60);
      lVar6 = syscall(0xba);
      FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                   lVar6,"dmal/common/common_nvml.c",0x3a3);
    }
    else {
      lVar6 = *(long *)(param_2 + 0x256d8);
      *(long *)((long)pvVar7 + 0x618) = (long)pvVar7 + 0x618;
      *(long *)((long)pvVar7 + 0x620) = (long)pvVar7 + 0x618;
      iVar2 = 3;
      iVar3 = iVar2;
      if ((((lVar6 == 0) || (*(long *)(lVar6 + 0x28) == 0)) ||
          (pcVar1 = *(code **)(*(long *)(lVar6 + 0x28) + 0x108), pcVar1 == (code *)0x0)) ||
         (iVar3 = (*pcVar1)(lVar6,param_2,&local_c8), iVar3 != 0)) {
        if (4 < DAT_01216a78) {
          fVar11 = (float)FUN_002917b0(&DAT_01216a60);
          lVar6 = syscall(0xba);
          fVar11 = fVar11 * DAT_00298548;
          uVar9 = 0x3af;
LAB_001a0538:
          FUN_002340f0((double)fVar11,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",lVar6,
                       "dmal/common/common_nvml.c",uVar9);
        }
      }
      else {
        lVar6 = *(long *)(param_2 + 0x256d8);
        iVar3 = iVar2;
        if (((lVar6 != 0) && (*(long *)(lVar6 + 0x28) != 0)) &&
           ((pcVar1 = *(code **)(*(long *)(lVar6 + 0x28) + 0x110), pcVar1 != (code *)0x0 &&
            (iVar3 = (*pcVar1)(lVar6,param_2,CONCAT44(uStack_c4,local_c8),DAT_012148b8), iVar3 == 0)
            ))) goto LAB_0019fdda;
        if (4 < DAT_01216a78) {
          fVar11 = (float)FUN_002917b0(&DAT_01216a60);
          lVar6 = syscall(0xba);
          fVar11 = fVar11 * DAT_00298548;
          uVar9 = 0x3b7;
          goto LAB_001a0538;
        }
      }
    }
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar3;
    }
    fVar11 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar6,"dmal/common/common_nvml.c",0x39c,"cDmalAllocateVgpuDevice",0x39c,
                 iVar3);
  }
  if (DAT_01216a78 < 2) {
    return iVar3;
  }
  fVar11 = (float)FUN_002917b0(&DAT_01216a60);
  lVar6 = syscall(0xba);
  uVar13 = 0x5ee;
  uVar9 = 0x5ee;
  dVar12 = (double)(fVar11 * DAT_00298548);
LAB_0019fd17:
  FUN_002340f0(dVar12,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar6,
               "dmal/common/common_nvml.c",uVar9,"cDmalCachedAllocateDevice",uVar13,iVar3);
  return iVar3;
}


// ===== 001a0900 FUN_001a0900 =====

uint FUN_001a0900(long param_1,long param_2,uint param_3,uint *param_4,uint *param_5)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  code *pcVar4;
  undefined8 uVar5;
  uint uVar6;
  tm *ptVar7;
  long lVar8;
  uint *puVar9;
  undefined1 (*pauVar10) [16];
  byte *pbVar11;
  undefined8 *puVar12;
  char *pcVar13;
  undefined8 *puVar14;
  uint uVar15;
  byte bVar16;
  float fVar17;
  undefined4 local_844;
  time_t local_840;
  undefined8 local_838;
  undefined8 uStack_830;
  undefined8 local_828;
  undefined8 uStack_820;
  undefined8 local_818;
  long lStack_810;
  char *local_808;
  byte local_7f8 [132];
  uint local_774;
  char local_6ea [722];
  undefined8 local_418 [125];
  
  bVar16 = 0;
  pbVar11 = local_7f8;
  for (lVar8 = 0x7c; lVar8 != 0; lVar8 = lVar8 + -1) {
    pbVar11[0] = 0;
    pbVar11[1] = 0;
    pbVar11[2] = 0;
    pbVar11[3] = 0;
    pbVar11[4] = 0;
    pbVar11[5] = 0;
    pbVar11[6] = 0;
    pbVar11[7] = 0;
    pbVar11 = pbVar11 + 8;
  }
  lVar8 = *(long *)(param_2 + 0x256d8);
  local_844 = 0;
  if (((lVar8 == 0) || (*(undefined8 **)(lVar8 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar4 = (code *)**(undefined8 **)(lVar8 + 0x50), pcVar4 == (code *)0x0)) {
    uVar6 = 3;
  }
  else {
    uVar6 = (*pcVar4)(lVar8,param_2,0x2081,&local_844);
    if (uVar6 == 0) {
      uVar6 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_844,0x20810108,
                           local_7f8,0x3e0,0);
      switch(uVar6) {
      case 0:
        goto switchD_001a0a6c_caseD_0;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return uVar6;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (1 < DAT_01216a78) {
    fVar17 = (float)FUN_002917b0(&DAT_01216a60);
    lVar8 = syscall(0xba);
    FUN_002340f0((double)(fVar17 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar8,"dmal/common/common_nvml.c",0x60b,"cDeviceGetLicensableFeatures",
                 0x60b,uVar6);
  }
  return uVar6;
switchD_001a0a6c_caseD_0:
  *param_4 = (uint)(local_7f8[0] == 1);
  if (param_5 == (uint *)0x0) {
    return uVar6;
  }
  uVar15 = (uint)local_7f8[0];
  if (param_3 == 3) {
    *param_5 = uVar15;
    param_5[1] = local_774;
    if (local_774 == 0) {
      return uVar6;
    }
    puVar9 = param_5 + 0x24;
    pcVar13 = local_6ea;
    uVar15 = uVar6;
    do {
      *(undefined1 *)(puVar9 + -0x20) = 0;
      uVar15 = uVar15 + 1;
      puVar9[-0x22] = *(uint *)(pcVar13 + -0x86);
      puVar9[0x20] = (uint)(byte)pcVar13[-0x82];
      puVar9[-0x21] = (uint)(byte)pcVar13[-0x81];
      strncpy((char *)puVar9,pcVar13,0x80);
      if (uVar15 == 3) {
        return uVar6;
      }
      puVar9 = puVar9 + 0x43;
      pcVar13 = pcVar13 + 0x118;
    } while (uVar15 < local_774);
    return uVar6;
  }
  if (param_3 < 4) {
    if (param_3 == 1) {
      *param_5 = uVar15;
      param_5[1] = local_774;
      if (local_774 == 0) {
        return uVar6;
      }
      puVar9 = param_5 + 2;
      pbVar11 = local_7f8;
      uVar15 = uVar6;
      do {
        uVar3 = *(uint *)(pbVar11 + 0x88);
        uVar15 = uVar15 + 1;
        *(undefined1 *)(puVar9 + 2) = 0;
        *puVar9 = uVar3;
        puVar9[1] = (uint)pbVar11[0x8d];
        if (uVar15 == 3) {
          return uVar6;
        }
        puVar9 = puVar9 + 0x22;
        pbVar11 = pbVar11 + 0x118;
      } while (uVar15 < local_774);
      return uVar6;
    }
    if (param_3 != 2) {
      return uVar6;
    }
    *param_5 = uVar15;
    param_5[1] = local_774;
    if (local_774 == 0) {
      return uVar6;
    }
    puVar9 = param_5 + 0x24;
    pcVar13 = local_6ea;
    uVar15 = uVar6;
    do {
      *(undefined1 *)(puVar9 + -0x20) = 0;
      uVar15 = uVar15 + 1;
      puVar9[-0x22] = *(uint *)(pcVar13 + -0x86);
      puVar9[-0x21] = (uint)(byte)pcVar13[-0x81];
      strncpy((char *)puVar9,pcVar13,0x80);
      if (uVar15 == 3) {
        return uVar6;
      }
      puVar9 = puVar9 + 0x42;
      pcVar13 = pcVar13 + 0x118;
    } while (uVar15 < local_774);
    return uVar6;
  }
  if (param_3 != 4) {
    return uVar6;
  }
  *param_5 = uVar15;
  param_5[1] = local_774;
  if (local_774 == 0) {
    return uVar6;
  }
  pcVar13 = local_6ea;
  pauVar10 = (undefined1 (*) [16])(param_5 + 0x45);
  puVar14 = local_418;
  uVar15 = uVar6;
  while( true ) {
    uVar2 = *(undefined4 *)(pcVar13 + -0x86);
    pauVar10[-0x11][0xc] = 0;
    *(undefined4 *)(pauVar10[-0x11] + 4) = uVar2;
    *(uint *)(pauVar10[-1] + 0xc) = (uint)(byte)pcVar13[-0x82];
    *(uint *)(pauVar10[-0x11] + 8) = (uint)(byte)pcVar13[-0x81];
    strncpy(pauVar10[-9] + 0xc,pcVar13,0x80);
    *pauVar10 = (undefined1  [16])0x0;
    pbVar11 = local_7f8;
    puVar12 = local_418;
    for (lVar8 = 0x7c; lVar8 != 0; lVar8 = lVar8 + -1) {
      *puVar12 = *(undefined8 *)pbVar11;
      pbVar11 = pbVar11 + ((ulong)bVar16 * -2 + 1) * 8;
      puVar12 = puVar12 + (ulong)bVar16 * -2 + 1;
    }
    cVar1 = *(char *)(puVar14 + 0x33);
    if (cVar1 == '\x02') {
      local_840 = puVar14[0x32];
      ptVar7 = localtime(&local_840);
      local_838._0_4_ = ptVar7->tm_sec;
      local_838._4_4_ = ptVar7->tm_min;
      uStack_830._0_4_ = ptVar7->tm_hour;
      uStack_830._4_4_ = ptVar7->tm_mday;
      uVar5._0_4_ = ptVar7->tm_mon;
      uVar5._4_4_ = ptVar7->tm_year;
      uStack_820._0_4_ = ptVar7->tm_wday;
      uStack_820._4_4_ = ptVar7->tm_yday;
      local_818 = *(undefined8 *)&ptVar7->tm_isdst;
      lStack_810 = ptVar7->tm_gmtoff;
      local_808 = ptVar7->tm_zone;
      *(int *)*pauVar10 = uVar5._4_4_ + 0x76c;
      local_828._0_2_ = (short)(undefined4)uVar5;
      *(short *)(*pauVar10 + 4) = (short)local_828 + 1;
      *(short *)(*pauVar10 + 6) = (short)uStack_830._4_4_;
      *(short *)(*pauVar10 + 8) = (short)(undefined4)uStack_830;
      *(short *)(*pauVar10 + 10) = (short)local_838._4_4_;
      *(short *)(*pauVar10 + 0xc) = (short)(undefined4)local_838;
      local_828 = uVar5;
    }
    (*pauVar10)[0xe] = cVar1;
    uVar15 = uVar15 + 1;
    pcVar13 = pcVar13 + 0x118;
    pauVar10 = (undefined1 (*) [16])(pauVar10[0x11] + 0xc);
    puVar14 = puVar14 + 0x23;
    if (local_774 <= uVar15) break;
    if (uVar15 == 3) {
      return uVar6;
    }
  }
  return uVar6;
}


// ===== 001a0e60 FUN_001a0e60 =====

undefined4 FUN_001a0e60(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 9;
  if (param_1 < 5) {
    uVar1 = *(undefined4 *)(&DAT_002a9790 + (ulong)param_1 * 4);
  }
  return uVar1;
}


// ===== 001a0e80 FUN_001a0e80 =====

undefined1  [16]
FUN_001a0e80(long param_1,long param_2,long param_3,undefined4 param_4,uint *param_5)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  undefined1 auVar5 [16];
  undefined4 local_20d8;
  undefined4 local_20d4;
  undefined4 local_2058;
  byte abStack_2048 [8216];
  
  memset(&local_20d8,0,0x209c);
  uVar2 = FUN_001a0e60(param_4);
  local_20d8 = *(undefined4 *)(param_2 + 0x256e0);
  local_2058 = 2;
  local_20d4 = *(undefined4 *)(param_3 + 0x256e0);
  uVar3 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,299,&local_20d8,
                       0x209c);
  uVar4 = 0;
  if ((uint)uVar3 < 0x67) {
    uVar4 = (long)&switchD_001a0f2e::switchdataD_002a8c18 +
            (long)(int)(&switchD_001a0f2e::switchdataD_002a8c18)[uVar3 & 0xffffffff];
    switch(uVar3 & 0xffffffff) {
    case 0:
      uVar1 = (uint)abStack_2048[uVar2];
      if (5 < abStack_2048[uVar2]) {
        uVar1 = 6;
      }
      uVar4 = (ulong)uVar1;
      *param_5 = uVar1;
      break;
    default:
      goto switchD_001a0f2e_caseD_1;
    case 3:
    case 0x66:
      uVar3 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      uVar3 = 0x13;
      break;
    case 0x1a:
      uVar3 = 0x17;
      break;
    case 0x1b:
      uVar3 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
      uVar3 = 2;
      break;
    case 0x51:
      uVar3 = 0x14;
      break;
    case 0x55:
      uVar3 = 0x1b;
      break;
    case 0x56:
      uVar3 = 3;
      break;
    case 0x59:
      uVar3 = 0x11;
      break;
    case 0x62:
      uVar3 = 0x10;
    }
  }
  else {
switchD_001a0f2e_caseD_1:
    uVar3 = 999;
  }
  auVar5._8_8_ = uVar4;
  auVar5._0_8_ = uVar3;
  return auVar5;
}


// ===== 001a0fc0 FUN_001a0fc0 =====

undefined8 FUN_001a0fc0(undefined8 param_1,int param_2,short param_3,short param_4,int *param_5)

{
  int *piVar1;
  long lVar2;
  int iVar3;
  float fVar4;
  
  if (param_5 == (int *)0x0) {
    return 2;
  }
  if (DAT_01214898 != 0) {
    piVar1 = &DAT_003808a0;
    iVar3 = 0;
    do {
      if (((*piVar1 == param_2) && ((short)piVar1[1] == param_3)) &&
         (*(short *)((long)piVar1 + 6) == param_4)) {
        *param_5 = iVar3;
        return 0;
      }
      iVar3 = iVar3 + 1;
      piVar1 = piVar1 + 0x1d280;
    } while (iVar3 != DAT_01214898);
  }
  if (DAT_01216a78 < 2) {
    return 6;
  }
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar2 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar2,
               "dmal/common/common_nvml.c",0x6ca);
  return 6;
}


// ===== 001a10b0 FUN_001a10b0 =====

undefined8 FUN_001a10b0(undefined8 param_1,int param_2,uint param_3,ushort param_4,int *param_5)

{
  int *piVar1;
  long lVar2;
  int iVar3;
  float fVar4;
  
  if (param_5 == (int *)0x0) {
    return 2;
  }
  if (DAT_01215b90 != 0) {
    piVar1 = &DAT_01215ba8;
    iVar3 = 0;
    do {
      if (((*piVar1 == param_2) && ((param_3 & 0xffff) == piVar1[1])) &&
         ((uint)param_4 == piVar1[2])) {
        *param_5 = iVar3;
        return 0;
      }
      iVar3 = iVar3 + 1;
      piVar1 = piVar1 + 0x12;
    } while (iVar3 != DAT_01215b90);
  }
  if (DAT_01216a78 < 2) {
    return 0x1c;
  }
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar2 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar2,
               "dmal/common/common_nvml.c",0x6e9);
  return 0x1c;
}


// ===== 001a11a0 FUN_001a11a0 =====

int FUN_001a11a0(long param_1,undefined8 param_2,undefined2 param_3,undefined2 param_4,
                undefined8 *param_5)

{
  int iVar1;
  long lVar2;
  float fVar3;
  uint local_1c;
  
  if (param_5 == (undefined8 *)0x0) {
    return 2;
  }
  iVar1 = (*(code *)**(undefined8 **)(param_1 + 0x20))(param_1,param_2,param_3,param_4,&local_1c);
  if (iVar1 == 0) {
    *param_5 = &DAT_00380898 + (ulong)local_1c * 0x74a00;
  }
  else if (1 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar2,"dmal/common/common_nvml.c",0x6fd,"cDmalFindHandleByBusId",0x6fd,
                 iVar1);
    return iVar1;
  }
  return iVar1;
}


// ===== 001a12a0 FUN_001a12a0 =====

undefined8 FUN_001a12a0(long param_1,char *param_2)

{
  char cVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  undefined8 *puVar6;
  float fVar7;
  undefined8 local_b8;
  
  cVar1 = *param_2;
  puVar6 = &local_b8;
  for (lVar5 = 0x10; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  if (cVar1 != '\x01') {
    if (((*(long *)(param_2 + 0x256d8) != 0) &&
        (lVar5 = *(long *)(*(long *)(param_2 + 0x256d8) + 0x28), lVar5 != 0)) &&
       (pcVar3 = *(code **)(lVar5 + 0x118), pcVar3 != (code *)0x0)) {
      (*pcVar3)();
    }
    FUN_001354b0(param_2,0);
    FUN_0019e770(param_1,param_2);
    FUN_0019ea90(param_1,param_2);
    uVar2 = *(undefined4 *)(param_2 + 0x256e0);
    local_b8._4_4_ = 0xffffffff;
    local_b8._0_4_ = uVar2;
    if (4 < DAT_01216a78) {
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n","DEBUG",
                   lVar5,"dmal/common/common_nvml.c",0x71a,uVar2);
    }
    iVar4 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0x216,&local_b8,
                         0x80,0);
    if ((iVar4 != 0) && (2 < DAT_01216a78)) {
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n",
                   "WARNING",lVar5,"dmal/common/common_nvml.c",0x720,iVar4);
    }
    do {
      iVar4 = FUN_00291820(param_2 + 0x18,1,0);
    } while (iVar4 != 0);
    param_2[0x14] = '\0';
    param_2[0x15] = '\0';
    param_2[0x16] = '\0';
    param_2[0x17] = '\0';
    FUN_00291830(param_2 + 0x18,0);
  }
  return 0;
}


// ===== 001a14a0 FUN_001a14a0 =====

int FUN_001a14a0(long param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  long lVar2;
  float fVar3;
  undefined4 local_68;
  char cStack_64;
  undefined1 uStack_63;
  undefined8 uStack_62;
  undefined2 uStack_5a;
  undefined6 local_58;
  undefined8 uStack_52;
  undefined2 uStack_4a;
  undefined6 local_48;
  undefined8 uStack_42;
  undefined2 uStack_3a;
  undefined6 local_38;
  undefined8 uStack_32;
  undefined2 uStack_2a;
  undefined6 local_28;
  undefined2 uStack_22;
  
  local_28 = 0;
  uStack_22 = 0;
  local_68 = 0;
  cStack_64 = '\0';
  uStack_63 = 0;
  uStack_62 = 0;
  uStack_5a = 0;
  local_58 = 0;
  uStack_52 = 0;
  uStack_4a = 0;
  local_48 = 0;
  uStack_42 = 0;
  uStack_3a = 0;
  local_38 = 0;
  uStack_32 = 0;
  uStack_2a = 0;
  iVar1 = FUN_0019d0a0(*(undefined8 *)(param_1 + 0x10),param_2,&local_68);
  if (iVar1 == 0) {
    if (cStack_64 == '\0') {
      return 3;
    }
    *param_3 = uStack_62;
    param_3[1] = CONCAT62(local_58,uStack_5a);
    param_3[2] = uStack_52;
    param_3[3] = CONCAT62(local_48,uStack_4a);
    param_3[4] = uStack_42;
    param_3[5] = CONCAT62(local_38,uStack_3a);
    param_3[6] = uStack_32;
    param_3[7] = CONCAT62(local_28,uStack_2a);
  }
  else if (1 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar2,"dmal/common/common_nvml.c",0x749,"cDeviceGetGspFirmwareVersion",
                 0x749,iVar1);
    return iVar1;
  }
  return iVar1;
}


// ===== 001a15d0 FUN_001a15d0 =====

int FUN_001a15d0(long param_1,undefined8 param_2,uint *param_3,uint *param_4)

{
  int iVar1;
  long lVar2;
  float fVar3;
  undefined1 local_78 [16];
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  undefined8 local_38;
  
  local_38 = 0;
  local_78 = (undefined1  [16])0x0;
  local_68 = (undefined1  [16])0x0;
  local_58 = (undefined1  [16])0x0;
  local_48 = (undefined1  [16])0x0;
  iVar1 = FUN_0019d0a0(*(undefined8 *)(param_1 + 0x10),param_2,local_78);
  if (iVar1 == 0) {
    if (local_78[4] == 0) {
      return 3;
    }
    *param_3 = (uint)local_78[4];
    *param_4 = (uint)local_78[5];
  }
  else if (1 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar2,"dmal/common/common_nvml.c",0x761,"cDeviceGetGspFirmwareMode",0x761,
                 iVar1);
    return iVar1;
  }
  return iVar1;
}


// ===== 001a16f0 FUN_001a16f0 =====

int FUN_001a16f0(long param_1,long param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 *puVar5;
  float fVar6;
  undefined4 local_dc;
  undefined8 local_d8 [22];
  
  local_dc = 0;
  puVar5 = local_d8;
  for (lVar4 = 0x16; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *param_3 = 0;
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar4,param_2,0x2081,&local_dc);
    if (iVar2 == 0) {
      iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_dc,0x20810109,local_d8
                           ,0xb0,0);
      switch(iVar2) {
      case 0:
        uVar3 = FUN_00133a10((undefined4)local_d8[0]);
        *param_3 = uVar3;
        return iVar2;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar2;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar6 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar4,"dmal/common/common_nvml.c",0x784,"cDeviceGetGridLicenseStateInfo",
               0x784,iVar2);
  return iVar2;
}


// ===== 001a1920 FUN_001a1920 =====

int FUN_001a1920(long param_1,char *param_2,int *param_3)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  int *piVar6;
  int local_2c8 [2];
  char local_2c0 [264];
  int local_1b8 [64];
  int aiStack_b8 [34];
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  piVar6 = local_1b8;
  for (lVar4 = 0x30; lVar4 != 0; lVar4 = lVar4 + -1) {
    piVar6[0] = 0;
    piVar6[1] = 0;
    piVar6 = piVar6 + 2;
  }
  piVar6 = local_2c8;
  for (lVar4 = 0x21; lVar4 != 0; lVar4 = lVar4 + -1) {
    piVar6[0] = 0;
    piVar6[1] = 0;
    piVar6 = piVar6 + 2;
  }
  *piVar6 = 0;
  iVar2 = FUN_0019c780(uVar1,DAT_0038088c,DAT_0038088c,0x214,local_1b8,0x180,0);
  switch(iVar2) {
  case 0:
    uVar5 = 0;
    do {
      if ((aiStack_b8[uVar5] != 1) && (local_2c8[0] = local_1b8[uVar5], local_2c8[0] != -1)) {
        local_2c8[1] = 0;
        iVar2 = FUN_0019c780(uVar1,DAT_0038088c,DAT_0038088c,0x275,local_2c8,0x10c,0);
        if (iVar2 != 0x57) {
          switch(iVar2) {
          case 0:
            iVar3 = strncmp(param_2,local_2c0,0x50);
            if (iVar3 == 0) {
              *param_3 = local_1b8[uVar5 & 0xffffffff];
              return iVar2;
            }
            break;
          default:
            goto switchD_001a19b2_caseD_1;
          case 3:
          case 0x66:
            goto switchD_001a19b2_caseD_3;
          case 0xf:
            return iVar2;
          case 0x17:
          case 99:
            goto switchD_001a19b2_caseD_17;
          case 0x1a:
            goto switchD_001a19b2_caseD_1a;
          case 0x1b:
            goto switchD_001a19b2_caseD_1b;
          case 0x1f:
          case 0x3b:
          case 0x54:
            goto switchD_001a19b2_caseD_1f;
          case 0x51:
            goto switchD_001a19b2_caseD_51;
          case 0x55:
            goto switchD_001a19b2_caseD_55;
          case 0x56:
            goto switchD_001a19b2_caseD_56;
          case 0x59:
            goto switchD_001a19b2_caseD_59;
          case 0x62:
            goto switchD_001a19b2_caseD_62;
          }
        }
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 != 0x20);
    iVar2 = 6;
    break;
  default:
switchD_001a19b2_caseD_1:
    iVar2 = 999;
    break;
  case 3:
  case 0x66:
switchD_001a19b2_caseD_3:
    iVar2 = 10;
    break;
  case 0xf:
    break;
  case 0x17:
  case 99:
switchD_001a19b2_caseD_17:
    iVar2 = 0x13;
    break;
  case 0x1a:
switchD_001a19b2_caseD_1a:
    iVar2 = 0x17;
    break;
  case 0x1b:
switchD_001a19b2_caseD_1b:
    iVar2 = 4;
    break;
  case 0x1f:
  case 0x3b:
  case 0x54:
switchD_001a19b2_caseD_1f:
    iVar2 = 2;
    break;
  case 0x51:
switchD_001a19b2_caseD_51:
    iVar2 = 0x14;
    break;
  case 0x55:
switchD_001a19b2_caseD_55:
    iVar2 = 0x1b;
    break;
  case 0x56:
switchD_001a19b2_caseD_56:
    iVar2 = 3;
    break;
  case 0x59:
switchD_001a19b2_caseD_59:
    iVar2 = 0x11;
    break;
  case 0x62:
switchD_001a19b2_caseD_62:
    iVar2 = 0x10;
  }
  return iVar2;
}


// ===== 001a1b80 FUN_001a1b80 =====

undefined1  [16] FUN_001a1b80(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  float fVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  
  if (1 < DAT_01216a78) {
    fVar2 = (float)FUN_002917b0(&DAT_01216a60);
    lVar1 = syscall(0xba);
    FUN_002340f0((double)(fVar2 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar1,"dmal/common/common_nvml.c",0x7e4,"cDeviceGetDriverModel",0x7e4);
    auVar4._8_8_ = 3;
    auVar4._0_8_ = 3;
    return auVar4;
  }
  auVar3._8_8_ = param_3;
  auVar3._0_8_ = 3;
  return auVar3;
}


// ===== 001a1c20 FUN_001a1c20 =====

int FUN_001a1c20(long param_1,long param_2,undefined4 *param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  undefined4 local_54;
  undefined8 local_50;
  undefined1 local_48 [16];
  undefined1 local_38 [16];
  
  local_50 = 0;
  local_48 = (undefined1  [16])0x0;
  local_38 = (undefined1  [16])0x0;
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    uVar2 = *(undefined8 *)(param_1 + 0x10);
    iVar3 = (*pcVar1)(lVar4,param_2,0x2080,&local_54);
    if (iVar3 == 0) {
      local_48._8_8_ = &local_50;
      local_50._0_4_ = 0x1d;
      local_48._0_4_ = 1;
      iVar3 = FUN_0019c780(uVar2,DAT_0038088c,local_54,0x20801201,local_48,0x20,0);
      switch(iVar3) {
      case 0:
        *param_3 = local_50._4_4_;
        return iVar3;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar3;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar3;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar4,"dmal/common/common_nvml.c",0x803,"cDeviceGetNumGpuCores",0x803,iVar3);
  return iVar3;
}


// ===== 001a1e40 FUN_001a1e40 =====

uint FUN_001a1e40(long param_1,long param_2,ulong param_3,undefined8 param_4,undefined4 param_5)

{
  code *pcVar1;
  undefined8 uVar2;
  uint uVar3;
  long lVar4;
  float fVar5;
  undefined4 local_3c [3];
  
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)) {
    uVar3 = 3;
  }
  else {
    uVar2 = *(undefined8 *)(param_1 + 0x10);
    uVar3 = (*pcVar1)(lVar4,param_2,(param_3 & 0xffffffff) >> 0x10,local_3c);
    if (uVar3 == 0) {
      uVar3 = FUN_0019c780(uVar2,DAT_0038088c,local_3c[0],param_3 & 0xffffffff,param_4,param_5,0);
      if (0x66 < uVar3) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002a98a0 + (ulong)uVar3 * 2);
    }
  }
  if (1 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_nvml.c",0x822,"cDeviceRmCall",0x822,uVar3);
  }
  return uVar3;
}


// ===== 001a1fb0 FUN_001a1fb0 =====

undefined2 FUN_001a1fb0(long param_1,uint param_2,undefined8 param_3,undefined4 param_4)

{
  uint uVar1;
  long lVar2;
  undefined2 uVar3;
  float fVar4;
  
  if (param_2 >> 0x10 == 0) {
    uVar3 = 999;
    uVar1 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,param_2,param_3,
                         param_4);
    if (uVar1 < 0x67) {
      return *(undefined2 *)(&DAT_002a98a0 + (ulong)uVar1 * 2);
    }
  }
  else {
    uVar3 = 3;
    if (2 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%X\n",
                   "WARNING",lVar2,"dmal/common/common_nvml.c",0x83b,param_2 >> 0x10);
      return 3;
    }
  }
  return uVar3;
}


// ===== 001a20b0 FUN_001a20b0 =====

int FUN_001a20b0(long param_1,long param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 uVar5;
  float fVar6;
  undefined8 uVar7;
  undefined4 local_8c;
  undefined1 local_88 [16];
  undefined1 local_78 [16];
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  
  local_88 = (undefined1  [16])0x0;
  uVar5 = *(undefined8 *)(param_1 + 0x10);
  local_8c = 0;
  local_78 = (undefined1  [16])0x0;
  local_68 = (undefined1  [16])0x0;
  local_58 = (undefined1  [16])0x0;
  local_48 = (undefined1  [16])0x0;
  if (*(int *)(param_2 + 0x70534) == 0) {
    do {
      iVar2 = FUN_00291820(param_2 + 0x70538,1,0);
    } while (iVar2 != 0);
    if (*(int *)(param_2 + 0x70534) == 0) {
      uVar3 = (**(code **)(*(long *)(param_1 + 0x38) + 8))(param_1,param_2,param_2 + 0x70530);
      *(undefined4 *)(param_2 + 0x70534) = 1;
      *(undefined4 *)(param_2 + 0x7053c) = uVar3;
    }
    FUN_00291830(param_2 + 0x70538,0);
  }
  iVar2 = *(int *)(param_2 + 0x7053c);
  if (iVar2 == 0) {
    if (*(int *)(param_2 + 0x70530) != 3) {
      return 3;
    }
    lVar4 = *(long *)(param_2 + 0x256d8);
    iVar2 = 3;
    if ((((lVar4 != 0) && (*(undefined8 **)(lVar4 + 0x50) != (undefined8 *)0x0)) &&
        (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 != (code *)0x0)) &&
       (iVar2 = (*pcVar1)(lVar4,param_2,0x80,&local_8c), iVar2 == 0)) {
      iVar2 = FUN_0019c780(uVar5,DAT_0038088c,local_8c,&DAT_00800291,local_88,0x50,0);
      switch(iVar2) {
      case 0:
        if (local_48[3] != '\x01') {
          *param_3 = 0;
          return iVar2;
        }
        *param_3 = 1;
switchD_001a2327_caseD_f:
        return iVar2;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        goto switchD_001a2327_caseD_f;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    fVar6 = fVar6 * DAT_00298548;
    uVar7 = 0x85c;
    uVar5 = 0x85c;
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    fVar6 = fVar6 * DAT_00298548;
    uVar7 = 0x854;
    uVar5 = 0x854;
  }
  FUN_002340f0((double)fVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
               "dmal/common/common_nvml.c",uVar5,"cDeviceGetHostVgpuMode",uVar7,iVar2);
  return iVar2;
}


// ===== 001a23c0 FUN_001a23c0 =====

void FUN_001a23c0(long param_1)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  uint local_4c;
  undefined1 local_3c [12];
  
  local_4c = 0;
  uVar1 = DAT_01214898;
  do {
    if (uVar1 == 0) {
      return;
    }
    uVar3 = 0;
    while (uVar2 = (int)uVar3 + 1, uVar2 < uVar1) {
      while (uVar3 = (ulong)uVar2, local_4c < uVar2) {
        uVar2 = uVar2 + 1;
        (**(code **)(*(long *)(param_1 + 0x20) + 200))
                  (param_1,&DAT_00380898 + (ulong)local_4c * 0x74a00,&DAT_00380898 + uVar3 * 0x74a00
                   ,2,local_3c);
        uVar1 = DAT_01214898;
        if (DAT_01214898 <= uVar2) goto LAB_001a2450;
      }
    }
LAB_001a2450:
    local_4c = local_4c + 1;
    if (uVar1 <= local_4c) {
      return;
    }
  } while( true );
}


// ===== 001a2470 FUN_001a2470 =====

int FUN_001a2470(long param_1,long param_2,undefined4 *param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  undefined8 *puVar6;
  float fVar7;
  undefined4 local_26c;
  undefined8 local_268;
  undefined4 local_260;
  
  puVar6 = &local_268;
  for (lVar5 = 0x46; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *(undefined4 *)puVar6 = 0;
  lVar5 = *(long *)(param_2 + 0x256d8);
  if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar5 + 0x50), pcVar1 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    uVar2 = *(undefined8 *)(param_1 + 0x10);
    iVar3 = (*pcVar1)(lVar5,param_2,0x2080,&local_26c);
    if (iVar3 == 0) {
      local_268 = 0x3f00000001;
      uVar4 = FUN_0019c780(uVar2,DAT_0038088c,local_26c,0x20800102,&local_268,0x234,0);
      iVar3 = FUN_0019e750(uVar4);
      *param_3 = local_260;
      return iVar3;
    }
  }
  if (1 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar5,"dmal/common/common_nvml.c",0x897,"cDeviceGetResetlessMigFieldValues"
                 ,0x897,iVar3);
    return iVar3;
  }
  return iVar3;
}


// ===== 001a2610 FUN_001a2610 =====

uint FUN_001a2610(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 < 10) {
    uVar1 = param_1;
  }
  return uVar1;
}


// ===== 001a2620 FUN_001a2620 =====

int FUN_001a2620(long param_1,char *param_2,int *param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  float fVar6;
  undefined4 local_30;
  undefined4 local_2c [3];
  
  local_30 = 0;
  if (*param_2 == '\x01') {
    *param_3 = 0;
    return 0;
  }
  lVar5 = *(long *)(param_2 + 0x256d8);
  if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar5 + 0x50), pcVar1 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    uVar2 = *(undefined8 *)(param_1 + 0x10);
    iVar3 = (*pcVar1)(lVar5,param_2,0x2080,local_2c);
    if (iVar3 == 0) {
      iVar3 = FUN_0019c780(uVar2,DAT_0038088c,local_2c[0],0x20800119,&local_30,4,0);
      switch(iVar3) {
      case 0:
        goto switchD_001a26c1_caseD_0;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar3;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (1 < DAT_01216a78) {
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar5,"dmal/common/common_nvml.c",0x8d8,"cDeviceGetSimulationInfo",0x8d8,
                 iVar3);
  }
  return iVar3;
switchD_001a26c1_caseD_0:
  iVar4 = FUN_001a2610(local_30);
  *param_3 = iVar4;
  if (iVar4 != -1) {
    return iVar3;
  }
  if (DAT_01216a78 < 1) {
    return 999;
  }
  fVar6 = (float)FUN_002917b0(&DAT_01216a60);
  lVar5 = syscall(0xba);
  FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","CRITICAL",
               lVar5,"dmal/common/common_nvml.c",0x8e3);
  return 999;
}


// ===== 001a2860 FUN_001a2860 =====

undefined8 FUN_001a2860(undefined8 param_1,char *param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  
  uVar1 = 3;
  if (*param_2 != '\x01') {
    *param_3 = 4000;
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 001a2880 FUN_001a2880 =====

undefined2 FUN_001a2880(long param_1,char *param_2,undefined4 param_3)

{
  uint uVar1;
  undefined2 uVar2;
  undefined8 local_10;
  
  uVar2 = 3;
  if (*param_2 != '\x01') {
    local_10 = CONCAT44(param_3,*(undefined4 *)(param_2 + 0x256e0));
    uVar1 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0xb05,&local_10,8
                        );
    uVar2 = 999;
    if (uVar1 < 0x67) {
      return *(undefined2 *)(&DAT_002aa2e0 + (ulong)uVar1 * 2);
    }
  }
  return uVar2;
}


// ===== 001a2910 FUN_001a2910 =====

ulong FUN_001a2910(long param_1,char *param_2,undefined4 param_3,uint *param_4,void *param_5)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  uint uVar4;
  void *pvVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  float fVar10;
  undefined8 uVar11;
  undefined4 local_3ec8;
  undefined4 local_3ec4;
  undefined4 local_3ec0 [4000];
  uint local_40;
  
  uVar3 = *(undefined8 *)(param_1 + 0x10);
  pvVar5 = memset(&local_3ec8,0,0x3e8c);
  uVar8 = 3;
  if (*param_2 != '\x01') {
    uVar1 = *param_4;
    local_3ec8 = *(undefined4 *)(param_2 + 0x256e0);
    uVar11 = 0;
    local_3ec4 = param_3;
    uVar4 = FUN_0019c780(uVar3,DAT_0038088c,DAT_0038088c,0xb04,pvVar5,0x3e8c);
    uVar9 = local_40;
    uVar8 = (ulong)uVar4;
    switch(uVar4) {
    case 0:
      uVar7 = (ulong)local_40;
      if (4 < DAT_01216a78) {
        fVar10 = (float)FUN_002917b0(&DAT_01216a60,uVar11);
        lVar6 = syscall(0xba);
        FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n",
                     "DEBUG",lVar6,"dmal/common/common_accounting.c",0xa9,uVar9);
        uVar8 = (ulong)uVar4;
        if (DAT_01216a78 < 5) {
          uVar7 = (ulong)local_40;
        }
        else {
          if (local_40 == 0) {
            *param_4 = 0;
            if (param_5 != (void *)0x0) {
              return uVar8;
            }
            return 7;
          }
          do {
            if (4 < DAT_01216a78) {
              uVar2 = local_3ec0[uVar8];
              fVar10 = (float)FUN_002917b0(&DAT_01216a60);
              lVar6 = syscall(0xba);
              FUN_002340f0((double)(fVar10 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u\n","DEBUG",lVar6,
                           "dmal/common/common_accounting.c",0xae,uVar8,uVar2);
            }
            uVar7 = (ulong)local_40;
            uVar9 = (int)uVar8 + 1;
            uVar8 = (ulong)uVar9;
          } while (uVar9 < local_40);
        }
      }
      uVar8 = (ulong)uVar4;
      uVar9 = (uint)uVar7;
      *param_4 = uVar9;
      if ((param_5 == (void *)0x0) || (uVar1 < uVar9)) {
        uVar8 = 7;
      }
      else if (uVar9 != 0) {
        memcpy(param_5,local_3ec0,uVar7 << 2);
      }
      break;
    default:
      uVar8 = 999;
      break;
    case 3:
    case 0x66:
      uVar8 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      uVar8 = 0x13;
      break;
    case 0x1a:
      uVar8 = 0x17;
      break;
    case 0x1b:
      uVar8 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
      uVar8 = 2;
      break;
    case 0x51:
      uVar8 = 0x14;
      break;
    case 0x55:
      uVar8 = 0x1b;
      break;
    case 0x56:
      uVar8 = 3;
      break;
    case 0x59:
      uVar8 = 0x11;
      break;
    case 0x62:
      uVar8 = 0x10;
    }
  }
  return uVar8;
}


// ===== 001a2c30 FUN_001a2c30 =====

ulong FUN_001a2c30(long param_1,char *param_2,int param_3)

{
  uint uVar1;
  undefined8 uVar2;
  code *pcVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  float fVar7;
  ulong local_44;
  uint local_3c;
  
  uVar2 = *(undefined8 *)(param_1 + 0x10);
  if (*param_2 == '\x01') goto switchD_001a2ccc_caseD_56;
  uVar1 = *(uint *)(param_2 + 0x256e0);
  uVar4 = (uint)(param_3 == 0);
  local_44 = (ulong)uVar1;
  local_3c = uVar4;
  if (4 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t0x%X %u\n",
                 "DEBUG",lVar6,"dmal/common/common_accounting.c",0x35,uVar1,uVar4);
  }
  uVar5 = FUN_0019c780(uVar2,DAT_0038088c,DAT_0038088c,0xb01,&local_44,0xc,0);
  switch(uVar5 & 0xffffffff) {
  case 0:
    if (param_3 != 0) {
      return uVar5;
    }
    pcVar3 = *(code **)(*(long *)(param_1 + 0x70) + 0x28);
    if (pcVar3 != (code *)0x0) {
      uVar5 = (*pcVar3)(param_1,param_2,0);
      return uVar5;
    }
  case 0x56:
switchD_001a2ccc_caseD_56:
    uVar5 = 3;
    break;
  default:
    uVar5 = 999;
    break;
  case 3:
  case 0x66:
    uVar5 = 10;
    break;
  case 0xf:
    break;
  case 0x17:
  case 99:
    uVar5 = 0x13;
    break;
  case 0x1a:
    uVar5 = 0x17;
    break;
  case 0x1b:
    uVar5 = 4;
    break;
  case 0x1f:
  case 0x3b:
  case 0x54:
    return 2;
  case 0x51:
    uVar5 = 0x14;
    break;
  case 0x55:
    uVar5 = 0x1b;
    break;
  case 0x59:
    uVar5 = 0x11;
    break;
  case 0x62:
    uVar5 = 0x10;
  }
  return uVar5;
}


// ===== 001a2e00 FUN_001a2e00 =====

undefined4 FUN_001a2e00(long param_1,char *param_2,undefined4 param_3,uint *param_4)

{
  ulong uVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  float fVar5;
  undefined8 local_34;
  int local_2c;
  
  uVar3 = 3;
  local_2c = 0;
  if (*param_2 != '\x01') {
    local_34 = CONCAT44(param_3,*(undefined4 *)(param_2 + 0x256e0));
    uVar3 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0xb02,&local_34,
                         0xc,0);
    iVar2 = local_2c;
    uVar1 = local_34;
    switch(uVar3) {
    case 0:
      if (4 < DAT_01216a78) {
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t0x%X %u\n",
                     "DEBUG",lVar4,"dmal/common/common_accounting.c",0x1e,uVar1 & 0xffffffff,iVar2);
      }
      *param_4 = (uint)(local_2c == 0);
      break;
    default:
      uVar3 = 999;
      break;
    case 3:
    case 0x66:
      uVar3 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      uVar3 = 0x13;
      break;
    case 0x1a:
      uVar3 = 0x17;
      break;
    case 0x1b:
      uVar3 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
      uVar3 = 2;
      break;
    case 0x51:
      uVar3 = 0x14;
      break;
    case 0x55:
      uVar3 = 0x1b;
      break;
    case 0x56:
      uVar3 = 3;
      break;
    case 0x59:
      uVar3 = 0x11;
      break;
    case 0x62:
      uVar3 = 0x10;
    }
  }
  return uVar3;
}


// ===== 001a2fa0 FUN_001a2fa0 =====

int FUN_001a2fa0(long param_1,char *param_2,int param_3,int param_4,undefined8 *param_5)

{
  undefined8 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  int iVar8;
  int iVar9;
  long lVar10;
  float fVar11;
  undefined4 local_68;
  int iStack_64;
  int iStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined8 uStack_50;
  undefined1 local_48 [16];
  
  iStack_60 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  local_48 = (undefined1  [16])0x0;
  if (*param_2 == '\x01') {
switchD_001a302f_caseD_56:
    iVar9 = 3;
  }
  else {
    iStack_64 = param_3;
    iVar8 = param_4;
    if (param_3 == 0) {
      iStack_64 = param_4;
      iVar8 = iStack_60;
    }
    iStack_60 = iVar8;
    local_68 = *(undefined4 *)(param_2 + 0x256e0);
    iVar9 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0xb03,&local_68,
                         0x30,0);
    uVar5 = uStack_50;
    uVar4 = uStack_5c;
    iVar8 = iStack_64;
    uVar3 = local_68;
    if (iVar9 == 0x57) {
      return 6;
    }
    switch(iVar9) {
    case 0:
      uVar7 = local_48._8_8_;
      *param_5 = CONCAT44(uStack_58,uStack_5c);
      uVar6 = local_48._0_8_;
      param_5[1] = uStack_50;
      if (local_48._8_8_ == 0) {
        param_5[2] = 0;
        *(undefined4 *)(param_5 + 4) = 1;
      }
      else {
        *(undefined4 *)(param_5 + 4) = 0;
        param_5[2] = (ulong)(local_48._8_8_ - local_48._0_8_) / 1000;
      }
      param_5[3] = local_48._0_8_;
      *(undefined4 *)((long)param_5 + 0x34) = 0;
      iVar2 = DAT_01216a78;
      *(undefined1 (*) [16])((long)param_5 + 0x24) = (undefined1  [16])0x0;
      if (4 < iVar2) {
        uVar1 = param_5[2];
        fVar11 = (float)FUN_002917b0(&DAT_01216a60);
        lVar10 = syscall(0xba);
        FUN_002340f0((double)(fVar11 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u 0x%X %u %llu %llu %llu %llu\n","DEBUG",
                     lVar10,"dmal/common/common_accounting.c",0x86,iVar8,uVar3,uVar4,uVar5,uVar6,
                     uVar7,uVar1);
      }
      break;
    default:
      iVar9 = 999;
      break;
    case 3:
    case 0x66:
      iVar9 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      iVar9 = 0x13;
      break;
    case 0x1a:
      iVar9 = 0x17;
      break;
    case 0x1b:
      iVar9 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
      iVar9 = 2;
      break;
    case 0x51:
      iVar9 = 0x14;
      break;
    case 0x55:
      iVar9 = 0x1b;
      break;
    case 0x56:
      goto switchD_001a302f_caseD_56;
    case 0x59:
      iVar9 = 0x11;
      break;
    case 0x62:
      iVar9 = 0x10;
    }
  }
  return iVar9;
}


// ===== 001a3200 FUN_001a3200 =====

int FUN_001a3200(undefined8 param_1,long param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  undefined1 local_38 [16];
  undefined4 local_28;
  
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x60) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x60), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,local_38);
    if (iVar2 == 0) {
      *param_3 = local_28;
      return 0;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_board.c",0x14,"cDeviceGetBoardId",0x14,iVar2);
  return iVar2;
}


// ===== 001a32f0 FUN_001a32f0 =====

int FUN_001a32f0(long param_1,char *param_2,int *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  undefined4 local_5c;
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  undefined4 local_38;
  undefined2 local_34;
  undefined1 local_32;
  
  local_38 = 0;
  local_34 = 0;
  local_32 = 0;
  local_58 = (undefined1  [16])0x0;
  local_48 = (undefined1  [16])0x0;
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
    if (param_3 != (int *)0x0) {
      if (*param_3 != 0x200002c) {
        return 0x19;
      }
      lVar3 = *(long *)(param_2 + 0x256d8);
      if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
         (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
        iVar2 = 3;
      }
      else {
        iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_5c);
        if (iVar2 == 0) {
          iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_5c,0x20803083,
                               local_58,0x27,0);
          switch(iVar2) {
          case 0:
            *(undefined2 *)(param_3 + 9) = (undefined2)local_38;
            *(undefined8 *)(param_3 + 1) = local_58._0_8_;
            *(undefined8 *)(param_3 + 3) = local_58._8_8_;
            *(undefined1 *)((long)param_3 + 0x27) = local_38._3_1_;
            *(undefined8 *)(param_3 + 5) = local_48._0_8_;
            *(undefined8 *)(param_3 + 7) = local_48._8_8_;
            *(char *)((long)param_3 + 0x26) = local_38._2_1_ + '\x01';
            *(char *)(param_3 + 10) = (char)local_34 + '\x01';
            return iVar2;
          default:
            return 999;
          case 3:
          case 0x66:
            return 10;
          case 0xf:
            return iVar2;
          case 0x17:
          case 99:
            return 0x13;
          case 0x1a:
            return 0x17;
          case 0x1b:
            return 4;
          case 0x1f:
          case 0x3b:
          case 0x54:
            goto switchD_001a3408_caseD_1f;
          case 0x51:
            return 0x14;
          case 0x55:
            return 0x1b;
          case 0x56:
            return 3;
          case 0x59:
            return 0x11;
          case 0x62:
            return 0x10;
          }
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar3,"dmal/common/common_board.c",0xa2,"cDeviceGetPlatformInfo",0xa2,
                   iVar2);
      return iVar2;
    }
  }
switchD_001a3408_caseD_1f:
  return 2;
}


// ===== 001a3550 FUN_001a3550 =====

int FUN_001a3550(long param_1,long param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  float fVar5;
  undefined4 local_26c;
  undefined8 local_268;
  byte local_260;
  
  puVar4 = &local_268;
  for (lVar3 = 0x46; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined4 *)puVar4 = 0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_26c);
    if (iVar2 == 0) {
      local_268 = 0x3a00000001;
      iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_26c,0x20800102,
                           &local_268,0x234,0);
      switch(iVar2) {
      case 0:
        goto switchD_001a36cd_caseD_0;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar2;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_board.c",0x59,"cDeviceGetCapsUncached",0x59,iVar2);
  return iVar2;
switchD_001a36cd_caseD_0:
  *param_3 = 0;
  if ((local_260 & 1) != 0) {
    *param_3 = 1;
    return iVar2;
  }
  return 0;
}


// ===== 001a3790 FUN_001a3790 =====

int FUN_001a3790(long param_1,long param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  undefined4 local_5c;
  undefined1 local_58 [16];
  undefined8 local_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 uStack_38;
  undefined1 uStack_37;
  undefined1 auStack_36 [14];
  
  local_58 = (undefined1  [16])0x0;
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  local_48 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_37 = 0;
  auStack_36 = SUB1614((undefined1  [16])0x0,2);
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    iVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_5c);
    if (iVar3 == 0) {
      iVar3 = FUN_0019c780(uVar1,DAT_0038088c,local_5c,0x20800808,local_58,0x30,0);
      switch(iVar3) {
      case 0:
        *param_3 = local_58._4_4_;
        param_3[1] = uStack_40;
        *(undefined1 *)(param_3 + 2) = (undefined1)uStack_3c;
        *(uint *)((long)param_3 + 9) = CONCAT13(uStack_38,uStack_3c._1_3_);
        *(undefined1 *)((long)param_3 + 0xd) = uStack_37;
        return iVar3;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar3;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar3;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar4,"dmal/common/common_board.c",0x40,"cDeviceGetSkuInfo",0x40,iVar3);
  return iVar3;
}


// ===== 001a39b0 FUN_001a39b0 =====

int FUN_001a39b0(long param_1,long param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined8 *puVar5;
  float fVar6;
  undefined4 local_26c;
  undefined8 local_268;
  undefined4 local_260;
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  puVar5 = &local_268;
  for (lVar4 = 0x46; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined4 *)puVar5 = 0;
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    iVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_26c);
    if (iVar3 == 0) {
      local_268 = 0x2200000001;
      iVar3 = FUN_0019c780(uVar1,DAT_0038088c,local_26c,0x20800102,&local_268,0x234,0);
      switch(iVar3) {
      case 0:
        *param_3 = local_260;
        return iVar3;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar3;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar3;
  }
  fVar6 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar4,"dmal/common/common_board.c",0x26,"cDeviceGetMultiGpuBoard",0x26,iVar3)
  ;
  return iVar3;
}


// ===== 001a3be0 FUN_001a3be0 =====

int FUN_001a3be0(undefined8 param_1,long param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  float fVar4;
  int local_2c;
  
  iVar1 = FUN_00175bd0(param_2,&local_2c);
  if ((iVar1 != 2) && (iVar1 != 0xf)) {
    if (iVar1 == 0) {
      if (local_2c == 0) {
        iVar1 = 3;
        if (3 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar3,"dmal/common/common_board.c",0x73);
        }
      }
      else if (param_3 == (int *)0x0) {
        iVar1 = 2;
      }
      else {
        iVar1 = 0x19;
        if (*param_3 == 0x1000008) {
          if (*(int *)(param_2 + 0x7057c) == 0) {
            do {
              iVar1 = FUN_00291820(param_2 + 0x70580,1,0);
            } while (iVar1 != 0);
            if (*(int *)(param_2 + 0x7057c) == 0) {
              uVar2 = FUN_001a3550(param_1,param_2,param_2 + 0x70578);
              *(undefined4 *)(param_2 + 0x7057c) = 1;
              *(undefined4 *)(param_2 + 0x70584) = uVar2;
            }
            FUN_00291830(param_2 + 0x70580,0);
          }
          iVar1 = *(int *)(param_2 + 0x70584);
          if (iVar1 == 0) {
            param_3[1] = *(int *)(param_2 + 0x70578);
          }
          else if (1 < DAT_01216a78) {
            fVar4 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            FUN_002340f0((double)(fVar4 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
                         "dmal/common/common_board.c",0x88,"cDeviceGetCapabilities",0x88,iVar1);
          }
        }
      }
    }
    else {
      iVar1 = 999;
    }
  }
  return iVar1;
}


// ===== 001a3e00 FUN_001a3e00 =====

void FUN_001a3e00(undefined8 param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  ulong extraout_RDX;
  ulong extraout_RDX_00;
  ulong uVar4;
  float fVar5;
  undefined4 local_58;
  undefined1 auStack_54 [12];
  undefined1 local_48 [16];
  undefined8 local_38;
  uint local_30;
  
  if (*(int *)(param_2 + 0x255d8) == 0) {
    do {
      iVar1 = FUN_00291820(param_2 + 0x255dc,1,0);
    } while (iVar1 != 0);
    uVar4 = extraout_RDX;
    if (*(int *)(param_2 + 0x255d8) == 0) {
      local_38 = 0;
      local_30 = 0;
      local_48 = (undefined1  [16])0x0;
      auStack_54 = SUB1612((undefined1  [16])0x0,4);
      local_58 = 0x200002c;
      uVar2 = FUN_001a32f0(param_1,param_2,&local_58);
      if (uVar2 == 0) {
        *(uint *)(param_2 + 0x255d4) = local_30 & 0xff;
        uVar4 = extraout_RDX_00;
      }
      else {
        uVar4 = extraout_RDX_00;
        if (1 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
                       "dmal/common/common_board.c",0xcd,"cDeviceGetModuleIdUncached",0xcd);
          uVar4 = (ulong)uVar2;
        }
      }
      *(uint *)(param_2 + 0x255e0) = uVar2;
      *(undefined4 *)(param_2 + 0x255d8) = 1;
    }
    FUN_00291830(param_2 + 0x255dc,0,uVar4);
  }
  if (*(int *)(param_2 + 0x255e0) == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x255d4);
  }
  return;
}


// ===== 001a3f60 FUN_001a3f60 =====

undefined4 FUN_001a3f60(char *param_1,uint *param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined4 uVar4;
  float fVar5;
  
  uVar4 = 2;
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    if (*(int *)(param_1 + 0x71c) == 0) {
      do {
        iVar2 = FUN_00291820(param_1 + 0x720,1,0);
      } while (iVar2 != 0);
      if (*(int *)(param_1 + 0x71c) == 0) {
        lVar3 = *(long *)(param_1 + 0x256d8);
        uVar4 = 3;
        if (((lVar3 != 0) && (*(long *)(lVar3 + 0x20) != 0)) &&
           (pcVar1 = *(code **)(*(long *)(lVar3 + 0x20) + 0x98), pcVar1 != (code *)0x0)) {
          uVar4 = (*pcVar1)(lVar3,param_1,param_1 + 0x708);
        }
        *(undefined4 *)(param_1 + 0x724) = uVar4;
        param_1[0x71c] = '\x01';
        param_1[0x71d] = '\0';
        param_1[0x71e] = '\0';
        param_1[0x71f] = '\0';
      }
      FUN_00291830(param_1 + 0x720,0);
    }
    if (*(int *)(param_1 + 0x724) == 0) {
      if (4 < DAT_01216a78) {
        uVar4 = *(undefined4 *)(param_1 + 0x708);
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tisArchOrNewer called: %d %d\n","DEBUG",
                     lVar3,"/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h",0x3d,
                     0xd,uVar4);
      }
      *param_2 = (uint)(0xc < *(uint *)(param_1 + 0x708));
      return 0;
    }
    if (*(int *)(param_1 + 0x724) == 0xf) {
      uVar4 = 0xf;
      if (4 < DAT_01216a78) {
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tisArchOrNewer error: %d\n","DEBUG",lVar3,
                     "/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h",0x42,0xd);
      }
    }
    else {
      if (1 < DAT_01216a78) {
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tFailure to determine Architecture\n",
                     "ERROR",lVar3,"/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h"
                     ,0x46);
      }
      *param_2 = 0;
      uVar4 = 0;
    }
  }
  return uVar4;
}


// ===== 001a4200 FUN_001a4200 =====

uint FUN_001a4200(long param_1,long param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  float fVar6;
  undefined8 uVar7;
  int local_80;
  undefined4 local_7c;
  undefined1 local_78 [16];
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  
  local_80 = 0;
  local_78 = (undefined1  [16])0x0;
  local_68 = (undefined1  [16])0x0;
  local_58 = (undefined1  [16])0x0;
  local_48 = (undefined1  [16])0x0;
  iVar2 = FUN_00236dd0();
  if (iVar2 == 0) {
    return 4;
  }
  uVar3 = FUN_001a3f60(param_2,&local_80);
  if (uVar3 == 0) {
    uVar3 = 3;
    if (local_80 == 0) {
      return 3;
    }
    snprintf(local_78,0x40,"%s",param_3);
    lVar4 = *(long *)(param_2 + 0x256d8);
    if ((((lVar4 != 0) && (*(undefined8 **)(lVar4 + 0x50) != (undefined8 *)0x0)) &&
        (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 != (code *)0x0)) &&
       (uVar3 = (*pcVar1)(lVar4,param_2,0x2080,&local_7c), uVar3 == 0)) {
      uVar3 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_7c,0x2080309a,local_78
                           ,0x40,0);
      if (0x66 < uVar3) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002aabe0 + (ulong)uVar3 * 2);
    }
    if (DAT_01216a78 < 2) {
      return uVar3;
    }
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    fVar6 = fVar6 * DAT_00298548;
    uVar7 = 0xfa;
    uVar5 = 0xfa;
  }
  else {
    if (DAT_01216a78 < 2) {
      return uVar3;
    }
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    fVar6 = fVar6 * DAT_00298548;
    uVar7 = 0xf0;
    uVar5 = 0xf0;
  }
  FUN_002340f0((double)fVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
               "dmal/common/common_board.c",uVar5,"cDeviceSetHostname",uVar7,uVar3);
  return uVar3;
}


// ===== 001a4430 FUN_001a4430 =====

int FUN_001a4430(long param_1,long param_2,char *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  int local_70;
  undefined4 local_6c;
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  undefined1 local_38 [16];
  
  local_70 = 0;
  local_68 = (undefined1  [16])0x0;
  local_58 = (undefined1  [16])0x0;
  local_48 = (undefined1  [16])0x0;
  local_38 = (undefined1  [16])0x0;
  iVar2 = FUN_001a3f60(param_2,&local_70);
  if (iVar2 == 0) {
    iVar2 = 3;
    if (local_70 != 0) {
      lVar3 = *(long *)(param_2 + 0x256d8);
      if ((((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
          (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) ||
         (iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_6c), iVar2 != 0)) {
        if (1 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          fVar5 = fVar5 * DAT_00298548;
          uVar6 = 0x116;
          uVar4 = 0x116;
          goto LAB_001a4575;
        }
      }
      else {
        iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_6c,0x2080309b,
                             local_68,0x40,0);
        switch(iVar2) {
        case 0:
          snprintf(param_3,0x40,"%s",local_68);
          break;
        default:
          iVar2 = 999;
          break;
        case 3:
        case 0x66:
          iVar2 = 10;
          break;
        case 0xf:
          break;
        case 0x17:
        case 99:
          iVar2 = 0x13;
          break;
        case 0x1a:
          iVar2 = 0x17;
          break;
        case 0x1b:
          iVar2 = 4;
          break;
        case 0x1f:
        case 0x3b:
        case 0x54:
          iVar2 = 2;
          break;
        case 0x51:
          iVar2 = 0x14;
          break;
        case 0x55:
          iVar2 = 0x1b;
          break;
        case 0x56:
          iVar2 = 3;
          break;
        case 0x59:
          iVar2 = 0x11;
          break;
        case 0x62:
          iVar2 = 0x10;
        }
      }
    }
  }
  else if (1 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    fVar5 = fVar5 * DAT_00298548;
    uVar6 = 0x10e;
    uVar4 = 0x10e;
LAB_001a4575:
    FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
                 "dmal/common/common_board.c",uVar4,"cDeviceGetHostname",uVar6,iVar2);
    return iVar2;
  }
  return iVar2;
}


// ===== 001a46a0 FUN_001a46a0 =====

undefined8 FUN_001a46a0(long param_1,long param_2,uint param_3)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 local_24;
  ulong local_20;
  
  local_20 = 0;
  uVar5 = *(undefined8 *)(param_1 + 0x10);
  lVar1 = *(long *)(param_2 + 0x256d8);
  if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0x50) != (undefined8 *)0x0)) &&
     (pcVar2 = (code *)**(undefined8 **)(lVar1 + 0x50), pcVar2 != (code *)0x0)) {
    uVar4 = (*pcVar2)(lVar1,param_2,0x2080,&local_24);
    if ((int)uVar4 == 0) {
      local_20 = (ulong)param_3;
      uVar4 = FUN_0019c780(uVar5,DAT_0038088c,local_24,0x20800130,&local_20,8,0);
      uVar3 = (uint)uVar4;
      if (uVar3 == 0x1b) {
        return 4;
      }
      if (0x1b < uVar3) {
        uVar5 = 999;
        if (uVar3 == 0x56) {
          uVar5 = 3;
        }
        return uVar5;
      }
      if (uVar3 == 0) {
        return uVar4;
      }
    }
    if ((int)uVar4 == 0xf) {
      return uVar4;
    }
  }
  return 999;
}


// ===== 001a4790 FUN_001a4790 =====

ulong FUN_001a4790(long param_1,long param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  ulong uVar4;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  lVar2 = *(long *)(param_2 + 0x256d8);
  if (((lVar2 != 0) && (*(undefined8 **)(lVar2 + 0x50) != (undefined8 *)0x0)) &&
     (pcVar3 = (code *)**(undefined8 **)(lVar2 + 0x50), pcVar3 != (code *)0x0)) {
    uVar4 = (*pcVar3)(lVar2,param_2,0x2080,&local_1c);
    if ((int)uVar4 == 0) {
      uVar4 = FUN_0019c780(uVar1,DAT_0038088c,local_1c,0x20800131,&local_20,4,0);
      switch(uVar4 & 0xffffffff) {
      case 0:
        *param_3 = local_20;
        return uVar4;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return uVar4;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
    else if ((int)uVar4 == 0xf) {
      return uVar4;
    }
  }
  return 999;
}


// ===== 001a48b0 FUN_001a48b0 =====

int FUN_001a48b0(long param_1,long param_2,uint *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  int local_34;
  undefined8 local_30 [2];
  
  local_30[0] = 0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,0x90e7,&local_34);
    if (iVar2 == 0) {
      if (local_34 == 0) {
        return 3;
      }
      iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_34,0x90e70119,local_30
                           ,8,0);
      switch(iVar2) {
      case 0:
        *param_3 = (uint)((char)local_30[0] != '\0');
        return iVar2;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar2;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_diagnostic.c",0x6e,"cDeviceGetBBXFlushStatus",0x6e,
               iVar2);
  return iVar2;
}


// ===== 001a4aa0 FUN_001a4aa0 =====

uint FUN_001a4aa0(long param_1,long param_2,int param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  float fVar4;
  undefined1 local_2d;
  int local_2c [3];
  
  local_2d = 0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    uVar2 = 3;
  }
  else {
    uVar2 = (*pcVar1)(lVar3,param_2,0x90e7,local_2c);
    if (uVar2 == 0) {
      if (local_2c[0] == 0) {
        return 3;
      }
      local_2d = param_3 == 1;
      uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_2c[0],0x90e7c119,
                           &local_2d,1,0);
      if (0x66 < uVar2) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002ab480 + (ulong)uVar2 * 2);
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar2;
  }
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_diagnostic.c",0x8e,"cDeviceDisableBBXFlush",0x8e,
               uVar2);
  return uVar2;
}


// ===== 001a4c00 FUN_001a4c00 =====

int FUN_001a4c00(long param_1,long param_2,undefined8 *param_3,ulong *param_4)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  int local_3c;
  undefined1 local_38 [16];
  
  local_38 = (undefined1  [16])0x0;
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    iVar3 = (*pcVar2)(lVar4,param_2,0x90e7,&local_3c);
    if (iVar3 == 0) {
      if (local_3c == 0) {
        return 3;
      }
      iVar3 = FUN_0019c780(uVar1,DAT_0038088c,local_3c,0x90e70113,local_38,0x10,0);
      switch(iVar3) {
      case 0:
        *param_3 = local_38._0_8_;
        *param_4 = (ulong)(uint)local_38._8_4_;
        return iVar3;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar3;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar3;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar4,"dmal/common/common_diagnostic.c",0x51,"cDeviceGetLastBBXFlushTime",
               0x51,iVar3);
  return iVar3;
}


// ===== 001a4df0 FUN_001a4df0 =====

undefined4 FUN_001a4df0(long param_1,long param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  code *pcVar2;
  ulong uVar3;
  ulong uVar4;
  int iVar5;
  undefined4 uVar6;
  long lVar7;
  float fVar8;
  int local_44;
  undefined8 local_40;
  
  local_40 = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  lVar7 = *(long *)(param_2 + 0x256d8);
  if (((lVar7 == 0) || (*(undefined8 **)(lVar7 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar7 + 0x50), pcVar2 == (code *)0x0))
  goto switchD_001a4ea4_caseD_1;
  iVar5 = (*pcVar2)(lVar7,param_2,0x208f,&local_44);
  if (iVar5 != 0) {
    if (iVar5 == 0xf) {
      return 0xf;
    }
    goto switchD_001a4ea4_caseD_1;
  }
  if (local_44 == 0) {
    return 3;
  }
  uVar6 = FUN_0019c780(uVar1,DAT_0038088c,local_44,0x208f1105,&local_40,8,0);
  uVar4 = local_40;
  switch(uVar6) {
  case 0:
    if (4 < DAT_01216a78) {
      uVar3 = local_40 >> 0x20;
      fVar8 = (float)FUN_002917b0(&DAT_01216a60,0x1a4e4c);
      lVar7 = syscall(0xba);
      FUN_002340f0((double)(fVar8 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%X %X\n",
                   "DEBUG",lVar7,"dmal/common/common_diagnostic.c",0x26,uVar4 & 0xffffffff,uVar3);
    }
    if ((int)local_40 == 2) {
      *param_4 = local_40._4_4_;
      *param_3 = 1;
      return uVar6;
    }
    if ((int)local_40 == 3) {
      *param_4 = 0;
      *param_3 = 0;
      return uVar6;
    }
  default:
switchD_001a4ea4_caseD_1:
    uVar6 = 999;
    break;
  case 3:
  case 0x66:
    uVar6 = 10;
    break;
  case 0xf:
    break;
  case 0x17:
  case 99:
    uVar6 = 0x13;
    break;
  case 0x1a:
    uVar6 = 0x17;
    break;
  case 0x1b:
    uVar6 = 4;
    break;
  case 0x1f:
  case 0x3b:
  case 0x54:
    uVar6 = 2;
    break;
  case 0x51:
    uVar6 = 0x14;
    break;
  case 0x55:
    uVar6 = 0x1b;
    break;
  case 0x56:
    uVar6 = 3;
    break;
  case 0x59:
    uVar6 = 0x11;
    break;
  case 0x62:
    uVar6 = 0x10;
  }
  return uVar6;
}


// ===== 001a4fd0 FUN_001a4fd0 =====

int FUN_001a4fd0(long param_1,long param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined8 *puVar5;
  float fVar6;
  undefined4 local_26c;
  undefined8 local_268;
  int local_260;
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  puVar5 = &local_268;
  for (lVar4 = 0x46; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined4 *)puVar5 = 0;
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    iVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_26c);
    if (iVar3 == 0) {
      local_268 = 0x3400000001;
      iVar3 = FUN_0019c780(uVar1,DAT_0038088c,local_26c,0x20800102,&local_268,0x234,0);
      switch(iVar3) {
      case 0:
        if (local_260 == 0) {
          *param_3 = 0;
          return 0;
        }
        if (local_260 == 1) {
          *param_3 = 1;
          return iVar3;
        }
        break;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar3;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
      return 999;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar3;
  }
  fVar6 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar4,"dmal/common/common_display.c",0xd5,"cDeviceGetDisplayEnabled",0xd5,
               iVar3);
  return iVar3;
}


// ===== 001a5220 FUN_001a5220 =====

undefined4 FUN_001a5220(long param_1,long param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  ulong uVar2;
  undefined1 auVar3 [16];
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 *puVar7;
  long lVar8;
  float fVar9;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined8 local_54;
  undefined4 local_4c;
  undefined1 local_48 [16];
  
  local_54 = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  local_4c = 0;
  local_48 = (undefined1  [16])0x0;
  lVar8 = *(long *)(param_2 + 0x256d8);
  if ((lVar8 != 0) && (puVar7 = *(undefined8 **)(lVar8 + 0x50), puVar7 != (undefined8 *)0x0)) {
    if ((code *)*puVar7 != (code *)0x0) {
      iVar4 = (*(code *)*puVar7)(lVar8,param_2,0x73,&local_60);
      if (iVar4 == 0) {
        local_54 = local_54 & 0xffffffff00000000;
        uVar5 = FUN_0019c780(uVar1,DAT_0038088c,local_60,&DAT_00730107,&local_54,0xc,0);
        uVar6 = local_4c;
        switch(uVar5) {
        case 0:
          if (4 < DAT_01216a78) {
            uVar2 = local_54 >> 0x20;
            fVar9 = (float)FUN_002917b0(&DAT_01216a60);
            lVar8 = syscall(0xba);
            FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %x\n"
                         ,"DEBUG",lVar8,"dmal/common/common_display.c",0xad,uVar6,uVar2);
          }
          auVar3._4_4_ = local_48._12_4_;
          auVar3._0_4_ = local_54._4_4_;
          auVar3._8_8_ = 0;
          local_48 = auVar3 << 0x40;
          uVar6 = FUN_0019c780(uVar1,DAT_0038088c,local_60,&DAT_00730108,local_48,0x10,0);
          switch(uVar6) {
          case 0:
            if (4 < DAT_01216a78) {
              uVar5 = local_48._8_4_;
              fVar9 = (float)FUN_002917b0(&DAT_01216a60);
              lVar8 = syscall(0xba);
              FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n",
                           "DEBUG",lVar8,"dmal/common/common_display.c",0xba,uVar5);
            }
            if (local_48._8_4_ != 0) {
              *param_3 = 1;
              return uVar6;
            }
            goto LAB_001a52cc;
          case 3:
          case 0x66:
            goto switchD_001a5391_caseD_3;
          case 0xf:
            return uVar6;
          case 0x17:
          case 99:
            goto switchD_001a5391_caseD_17;
          case 0x1a:
            goto switchD_001a5391_caseD_1a;
          case 0x1b:
            goto switchD_001a5391_caseD_1b;
          case 0x1f:
          case 0x3b:
          case 0x54:
            goto switchD_001a5391_caseD_1f;
          case 0x51:
            goto switchD_001a5391_caseD_51;
          case 0x55:
            goto switchD_001a5391_caseD_55;
          case 0x56:
            goto switchD_001a5391_caseD_56;
          case 0x59:
            goto switchD_001a5391_caseD_59;
          case 0x62:
            goto switchD_001a5391_caseD_62;
          }
          break;
        case 3:
        case 0x66:
switchD_001a5391_caseD_3:
          return 10;
        case 0xf:
          return uVar5;
        case 0x17:
        case 99:
switchD_001a5391_caseD_17:
          return 0x13;
        case 0x1a:
switchD_001a5391_caseD_1a:
          return 0x17;
        case 0x1b:
switchD_001a5391_caseD_1b:
          return 4;
        case 0x1f:
        case 0x3b:
        case 0x54:
switchD_001a5391_caseD_1f:
          return 2;
        case 0x51:
switchD_001a5391_caseD_51:
          return 0x14;
        case 0x55:
switchD_001a5391_caseD_55:
          return 0x1b;
        case 0x56:
switchD_001a5391_caseD_56:
          return 3;
        case 0x59:
switchD_001a5391_caseD_59:
          return 0x11;
        case 0x62:
switchD_001a5391_caseD_62:
          return 0x10;
        }
        return 999;
      }
      if (iVar4 == 0xf) {
        return 0xf;
      }
      lVar8 = *(long *)(param_2 + 0x256d8);
      if ((lVar8 == 0) || (puVar7 = *(undefined8 **)(lVar8 + 0x50), puVar7 == (undefined8 *)0x0))
      goto LAB_001a52cc;
    }
    if (((code *)*puVar7 != (code *)0x0) &&
       (iVar4 = (*(code *)*puVar7)(lVar8,param_2,0x2081,&local_5c), iVar4 == 0)) {
      local_58 = 0;
      iVar4 = FUN_0019c780(uVar1,DAT_0038088c,local_5c,0x20810111,&local_58,4,0);
      if (iVar4 == 0) {
        *param_3 = local_58;
        return 0;
      }
    }
  }
LAB_001a52cc:
  *param_3 = 0;
  return 0;
}


// ===== 001a5570 FUN_001a5570 =====

uint FUN_001a5570(long param_1,long param_2,uint *param_3)

{
  undefined8 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined8 *puVar6;
  long lVar7;
  uint uVar8;
  float fVar9;
  byte local_59;
  undefined4 local_58;
  undefined8 local_54;
  uint local_4c;
  undefined1 local_48 [16];
  
  local_54 = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  local_4c = 0;
  lVar7 = *(long *)(param_2 + 0x256d8);
  if ((lVar7 != 0) && (puVar6 = *(undefined8 **)(lVar7 + 0x50), puVar6 != (undefined8 *)0x0)) {
    if ((code *)*puVar6 != (code *)0x0) {
      iVar3 = (*(code *)*puVar6)(lVar7,param_2,0x73,&local_58);
      if (iVar3 == 0) {
        local_54 = 0;
        uVar4 = FUN_0019c780(uVar1,DAT_0038088c,local_58,&DAT_00730102,&local_54,0xc,0);
        switch(uVar4) {
        case 0:
          goto switchD_001a56c7_caseD_0;
        default:
switchD_001a56c7_caseD_1:
          return 999;
        case 3:
        case 0x66:
switchD_001a56c7_caseD_3:
          return 10;
        case 0xf:
          return uVar4;
        case 0x17:
        case 99:
switchD_001a56c7_caseD_17:
          return 0x13;
        case 0x1a:
switchD_001a56c7_caseD_1a:
          return 0x17;
        case 0x1b:
switchD_001a56c7_caseD_1b:
          return 4;
        case 0x1f:
        case 0x3b:
        case 0x54:
switchD_001a56c7_caseD_1f:
          return 2;
        case 0x51:
switchD_001a56c7_caseD_51:
          return 0x14;
        case 0x55:
switchD_001a56c7_caseD_55:
          return 0x1b;
        case 0x56:
switchD_001a56c7_caseD_56:
          return 3;
        case 0x59:
switchD_001a56c7_caseD_59:
          return 0x11;
        case 0x62:
switchD_001a56c7_caseD_62:
          return 0x10;
        }
      }
      if (iVar3 == 0xf) {
        return 0xf;
      }
      lVar7 = *(long *)(param_2 + 0x256d8);
      if ((lVar7 == 0) || (puVar6 = *(undefined8 **)(lVar7 + 0x50), puVar6 == (undefined8 *)0x0))
      goto LAB_001a5614;
    }
    if (((code *)*puVar6 != (code *)0x0) &&
       (iVar3 = (*(code *)*puVar6)(lVar7,param_2,0x2081,local_48), iVar3 == 0)) {
      local_59 = 0;
      iVar3 = FUN_0019c780(uVar1,DAT_0038088c,local_48._0_4_,0x20810110,&local_59,1,0);
      if (iVar3 == 0) {
        *param_3 = (uint)local_59;
        return 0;
      }
    }
  }
LAB_001a5614:
  *param_3 = 0;
  return 0;
switchD_001a56c7_caseD_0:
  if (local_4c == 0) {
LAB_001a57d1:
    if (4 < DAT_01216a78) {
      fVar9 = (float)FUN_002917b0(&DAT_01216a60);
      lVar7 = syscall(0xba);
      FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","DEBUG",
                   lVar7,"dmal/common/common_display.c",0x5e,0);
    }
    *param_3 = 0;
    return uVar4;
  }
  uVar8 = uVar4;
LAB_001a5745:
  local_48._0_8_ = (ulong)uVar8 << 0x20;
  local_48._8_4_ = 1;
  local_48._12_4_ = 0;
  uVar5 = FUN_0019c780(uVar1,DAT_0038088c,local_58,&DAT_0073010c,local_48,0x10);
  switch(uVar5) {
  case 0:
    break;
  default:
    goto switchD_001a56c7_caseD_1;
  case 3:
  case 0x66:
    goto switchD_001a56c7_caseD_3;
  case 0xf:
    return uVar5;
  case 0x17:
  case 99:
    goto switchD_001a56c7_caseD_17;
  case 0x1a:
    goto switchD_001a56c7_caseD_1a;
  case 0x1b:
    goto switchD_001a56c7_caseD_1b;
  case 0x1f:
  case 0x3b:
  case 0x54:
    goto switchD_001a56c7_caseD_1f;
  case 0x51:
    goto switchD_001a56c7_caseD_51;
  case 0x55:
    goto switchD_001a56c7_caseD_55;
  case 0x56:
    goto switchD_001a56c7_caseD_56;
  case 0x59:
    goto switchD_001a56c7_caseD_59;
  case 0x62:
    goto switchD_001a56c7_caseD_62;
  }
  uVar2 = local_48._12_4_;
  if (local_48._12_4_ != 0) {
    if (4 < DAT_01216a78) {
      fVar9 = (float)FUN_002917b0(&DAT_01216a60);
      lVar7 = syscall(0xba);
      FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","DEBUG",
                   lVar7,"dmal/common/common_display.c",0x5e,uVar2);
    }
    *param_3 = 1;
    return uVar5;
  }
  uVar8 = uVar8 + 1;
  if (local_4c <= uVar8) goto LAB_001a57d1;
  goto LAB_001a5745;
}


// ===== 001a58d0 FUN_001a58d0 =====

undefined8 FUN_001a58d0(undefined8 param_1,long param_2,ulong *param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  
  *param_3 = 0;
  if (((*(long *)(param_2 + 0x256d8) != 0) &&
      (lVar1 = *(long *)(*(long *)(param_2 + 0x256d8) + 0x120), lVar1 != 0)) &&
     (pcVar2 = *(code **)(lVar1 + 0x68), pcVar2 != (code *)0x0)) {
    iVar3 = (*pcVar2)();
    if (iVar3 == 0) {
      *param_3 = *param_3 | 1;
    }
    return 0;
  }
  return 0;
}


// ===== 001a5930 FUN_001a5930 =====

undefined8 FUN_001a5930(undefined8 param_1,int *param_2)

{
  if (*param_2 != 0x1000008) {
    return 0x19;
  }
  param_2[1] = DAT_01215b90;
  return 0;
}


// ===== 001a5960 FUN_001a5960 =====

undefined1  [16] FUN_001a5960(long param_1,long *param_2,long *param_3)

{
  ulong uVar1;
  long lVar2;
  undefined1 auVar3 [16];
  undefined1 local_28 [16];
  
  local_28 = (undefined1  [16])0x0;
  uVar1 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0x137,local_28,0x10
                      );
  lVar2 = 0;
  if ((uint)uVar1 < 0x67) {
    lVar2 = (long)&switchD_001a59b9::switchdataD_002abdfc +
            (long)(int)(&switchD_001a59b9::switchdataD_002abdfc)[uVar1 & 0xffffffff];
    switch(uVar1 & 0xffffffff) {
    case 0:
      if (param_2 != (long *)0x0) {
        *param_2 = local_28._0_8_;
        lVar2 = local_28._0_8_;
      }
      if (param_3 != (long *)0x0) {
        *param_3 = local_28._8_8_;
        lVar2 = local_28._8_8_;
      }
      break;
    default:
      goto switchD_001a59b9_caseD_1;
    case 3:
    case 0x66:
      uVar1 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      uVar1 = 0x13;
      break;
    case 0x1a:
      uVar1 = 0x17;
      break;
    case 0x1b:
      uVar1 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
      uVar1 = 2;
      break;
    case 0x51:
      uVar1 = 0x14;
      break;
    case 0x55:
      uVar1 = 0x1b;
      break;
    case 0x56:
      uVar1 = 3;
      break;
    case 0x59:
      uVar1 = 0x11;
      break;
    case 0x62:
      uVar1 = 0x10;
    }
  }
  else {
switchD_001a59b9_caseD_1:
    uVar1 = 999;
  }
  auVar3._8_8_ = lVar2;
  auVar3._0_8_ = uVar1;
  return auVar3;
}


// ===== 001a5a50 FUN_001a5a50 =====

undefined2 FUN_001a5a50(long param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined2 uVar2;
  undefined8 local_10;
  
  local_10 = *param_2;
  uVar1 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0x138,&local_10,8);
  uVar2 = 999;
  if (uVar1 < 0x67) {
    uVar2 = *(undefined2 *)(&DAT_002ac960 + (ulong)uVar1 * 2);
  }
  return uVar2;
}


// ===== 001a5ab0 FUN_001a5ab0 =====

int FUN_001a5ab0(long param_1,long param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  undefined4 local_30;
  uint local_2c [3];
  
  local_2c[0] = 0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_30);
    if (iVar2 == 0) {
      iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_30,0x208001b2,local_2c
                           ,4,0);
      switch(iVar2) {
      case 0:
        goto switchD_001a5bf2_caseD_0;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar2;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_system.c",0x14b,"cDeviceGetRecoveryAction",0x14b,
               iVar2);
  return iVar2;
switchD_001a5bf2_caseD_0:
  if (local_2c[0] == 3) {
    *param_3 = 3;
    return iVar2;
  }
  if (local_2c[0] < 4) {
    if (local_2c[0] == 1) {
      *param_3 = 1;
      return iVar2;
    }
    if (local_2c[0] == 2) {
      *param_3 = 2;
      return iVar2;
    }
  }
  else if (local_2c[0] == 4) {
    *param_3 = 4;
    return iVar2;
  }
  *param_3 = 0;
  return iVar2;
}


// ===== 001a5cf0 FUN_001a5cf0 =====

undefined1  [16] FUN_001a5cf0(long param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong uVar2;
  undefined1 auVar3 [16];
  uint local_1c [3];
  
  local_1c[0] = 0;
  uVar1 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0x136,local_1c,4);
  uVar2 = 0;
  if ((uint)uVar1 < 0x67) {
    uVar2 = (long)&switchD_001a5d43::switchdataD_002ac150 +
            (long)(int)(&switchD_001a5d43::switchdataD_002ac150)[uVar1 & 0xffffffff];
    switch(uVar1 & 0xffffffff) {
    case 0:
      uVar2 = (ulong)local_1c[0];
      *param_2 = 2;
      if (local_1c[0] == 1) {
        *param_2 = 1;
      }
      else if (local_1c[0] == 2) {
        *param_2 = 3;
      }
      break;
    default:
      goto switchD_001a5d43_caseD_1;
    case 3:
    case 0x66:
      uVar1 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      uVar1 = 0x13;
      break;
    case 0x1a:
      uVar1 = 0x17;
      break;
    case 0x1b:
      uVar1 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
      uVar1 = 2;
      break;
    case 0x51:
      uVar1 = 0x14;
      break;
    case 0x55:
      uVar1 = 0x1b;
      break;
    case 0x56:
      uVar1 = 3;
      break;
    case 0x59:
      uVar1 = 0x11;
      break;
    case 0x62:
      uVar1 = 0x10;
    }
  }
  else {
switchD_001a5d43_caseD_1:
    uVar1 = 999;
  }
  auVar3._8_8_ = uVar2;
  auVar3._0_8_ = uVar1;
  return auVar3;
}


// ===== 001a5de0 FUN_001a5de0 =====

undefined1  [16] FUN_001a5de0(long param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  uint *puVar5;
  undefined1 auVar6 [16];
  undefined4 local_b8;
  uint local_b4;
  undefined8 local_b0;
  uint local_a8;
  undefined8 local_a4;
  undefined8 uStack_9c;
  undefined8 local_94;
  undefined8 uStack_8c;
  undefined8 local_84;
  undefined8 uStack_7c;
  undefined8 local_74;
  undefined8 uStack_6c;
  undefined8 local_64;
  undefined8 uStack_5c;
  undefined8 local_54;
  undefined8 uStack_4c;
  undefined8 local_44;
  undefined8 uStack_3c;
  undefined8 local_34;
  undefined8 uStack_2c;
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  puVar5 = &local_a8;
  for (lVar3 = 0x10; lVar3 != 0; lVar3 = lVar3 + -1) {
    puVar5[0] = 0;
    puVar5[1] = 0;
    puVar5 = puVar5 + 2;
  }
  local_b8 = *param_2;
  local_b4 = (uint)*(ushort *)(param_2 + 1);
  local_b0 = *(undefined8 *)(param_2 + 2);
  *puVar5 = 0;
  uVar2 = FUN_0019c780(uVar1,DAT_0038088c,DAT_0038088c,0x12e,&local_b8,0x94);
  uVar4 = 0;
  if ((uint)uVar2 < 0x67) {
    uVar4 = (long)&switchD_001a5e6c::switchdataD_002ac2ec +
            (long)(int)(&switchD_001a5e6c::switchdataD_002ac2ec)[uVar2 & 0xffffffff];
    switch(uVar2 & 0xffffffff) {
    case 0:
      uVar4 = (ulong)local_a8;
      param_2[4] = local_a8;
      *(undefined8 *)(param_2 + 5) = local_a4;
      *(undefined8 *)(param_2 + 7) = uStack_9c;
      *(undefined8 *)(param_2 + 9) = local_94;
      *(undefined8 *)(param_2 + 0xb) = uStack_8c;
      *(undefined8 *)(param_2 + 0xd) = local_84;
      *(undefined8 *)(param_2 + 0xf) = uStack_7c;
      *(undefined8 *)(param_2 + 0x11) = local_74;
      *(undefined8 *)(param_2 + 0x13) = uStack_6c;
      *(undefined8 *)(param_2 + 0x15) = local_64;
      *(undefined8 *)(param_2 + 0x17) = uStack_5c;
      *(undefined8 *)(param_2 + 0x19) = local_54;
      *(undefined8 *)(param_2 + 0x1b) = uStack_4c;
      *(undefined8 *)(param_2 + 0x1d) = local_44;
      *(undefined8 *)(param_2 + 0x1f) = uStack_3c;
      *(undefined8 *)(param_2 + 0x21) = local_34;
      *(undefined8 *)(param_2 + 0x23) = uStack_2c;
      break;
    default:
      goto switchD_001a5e6c_caseD_1;
    case 3:
    case 0x66:
      uVar2 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      uVar2 = 0x13;
      break;
    case 0x1a:
      uVar2 = 0x17;
      break;
    case 0x1b:
      uVar2 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
      uVar2 = 2;
      break;
    case 0x51:
      uVar2 = 0x14;
      break;
    case 0x55:
      uVar2 = 0x1b;
      break;
    case 0x56:
      uVar2 = 3;
      break;
    case 0x59:
      uVar2 = 0x11;
      break;
    case 0x62:
      uVar2 = 0x10;
    }
  }
  else {
switchD_001a5e6c_caseD_1:
    uVar2 = 999;
  }
  auVar6._8_8_ = uVar4;
  auVar6._0_8_ = uVar2;
  return auVar6;
}


// ===== 001a5f30 FUN_001a5f30 =====

undefined1  [16] FUN_001a5f30(long param_1,byte *param_2)

{
  undefined8 uVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  byte bVar7;
  undefined1 auVar8 [16];
  undefined8 local_228 [63];
  undefined8 local_30;
  byte local_28;
  
  bVar7 = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  puVar5 = local_228;
  for (lVar3 = 0x40; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0;
  uVar2 = FUN_0019c780(uVar1,DAT_0038088c,DAT_0038088c,0x12f,local_228,0x202);
  uVar4 = 0;
  if ((uint)uVar2 < 0x67) {
    uVar4 = (long)&switchD_001a5f9c::switchdataD_002ac488 +
            (long)(int)(&switchD_001a5f9c::switchdataD_002ac488)[uVar2 & 0xffffffff];
    switch(uVar2 & 0xffffffff) {
    case 0:
      *(undefined8 *)(param_2 + 2) = local_228[0];
      *(undefined8 *)(param_2 + 0x1fa) = local_30;
      puVar5 = (undefined8 *)
               ((long)local_228 -
               (long)(param_2 + (2 - (long)((ulong)(param_2 + 10) & 0xfffffffffffffff8))));
      puVar6 = (undefined8 *)((ulong)(param_2 + 10) & 0xfffffffffffffff8);
      for (uVar4 = (ulong)((int)(param_2 + (2 - (long)((ulong)(param_2 + 10) & 0xfffffffffffffff8)))
                           + 0x200U >> 3); uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + (ulong)bVar7 * -2 + 1;
        puVar6 = puVar6 + (ulong)bVar7 * -2 + 1;
      }
      uVar4 = (ulong)local_28;
      *param_2 = local_28;
      break;
    default:
      goto switchD_001a5f9c_caseD_1;
    case 3:
    case 0x66:
      uVar2 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      uVar2 = 0x13;
      break;
    case 0x1a:
      uVar2 = 0x17;
      break;
    case 0x1b:
      uVar2 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
      uVar2 = 2;
      break;
    case 0x51:
      uVar2 = 0x14;
      break;
    case 0x55:
      uVar2 = 0x1b;
      break;
    case 0x56:
      uVar2 = 3;
      break;
    case 0x59:
      uVar2 = 0x11;
      break;
    case 0x62:
      uVar2 = 0x10;
    }
  }
  else {
switchD_001a5f9c_caseD_1:
    uVar2 = 999;
  }
  auVar8._8_8_ = uVar4;
  auVar8._0_8_ = uVar2;
  return auVar8;
}


// ===== 001a6050 FUN_001a6050 =====

undefined8 FUN_001a6050(long param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_38;
  undefined4 local_30;
  undefined8 uStack_2c;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  local_30 = *(undefined4 *)(param_2 + 1);
  uStack_2c = 0;
  uStack_24 = 0;
  local_38 = *param_2;
  uStack_20 = 0;
  iVar1 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0x12a,&local_38,
                       0x1c);
  if (iVar1 == 0x25) {
    uVar2 = 3;
  }
  else {
    uVar2 = FUN_0019e750(iVar1);
    if (((int)uVar2 != 0) && ((int)uVar2 != 3)) {
      return uVar2;
    }
  }
  *(undefined8 *)((long)param_2 + 0xc) = uStack_2c;
  *(ulong *)((long)param_2 + 0x14) = CONCAT44(uStack_20,uStack_24);
  return uVar2;
}


// ===== 001a60e0 FUN_001a60e0 =====

undefined8 FUN_001a60e0(undefined8 param_1,uint param_2,int *param_3)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  uVar2 = 2;
  if ((param_2 < DAT_01215b90) && (uVar2 = 0x19, *param_3 == 0x1000048)) {
    uVar3 = (ulong)param_2;
    lVar1 = uVar3 * 0x48;
    uVar2 = *(undefined8 *)(lVar1 + 0x1215ba0);
    *(undefined8 *)(param_3 + 1) = *(undefined8 *)(&DAT_01215b98 + lVar1);
    *(undefined8 *)(param_3 + 3) = uVar2;
    uVar2 = *(undefined8 *)(&DAT_01215bb0 + uVar3 * 0x12);
    *(undefined8 *)(param_3 + 5) = *(undefined8 *)(&DAT_01215ba8 + uVar3 * 0x12);
    *(undefined8 *)(param_3 + 7) = uVar2;
    uVar2 = *(undefined8 *)(lVar1 + 0x1215bc0);
    *(undefined8 *)(param_3 + 9) = *(undefined8 *)(&DAT_01215bb8 + lVar1);
    *(undefined8 *)(param_3 + 0xb) = uVar2;
    uVar2 = *(undefined8 *)(lVar1 + 0x1215bd0);
    *(undefined8 *)(param_3 + 0xd) = *(undefined8 *)(&DAT_01215bc8 + lVar1);
    *(undefined8 *)(param_3 + 0xf) = uVar2;
    param_3[0x11] = *(int *)(&DAT_01215bd8 + lVar1);
    return 0;
  }
  return uVar2;
}


// ===== 001a6150 FUN_001a6150 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_001a6150(undefined8 param_1)

{
  undefined4 uVar1;
  size_t sVar2;
  long lVar3;
  undefined8 *puVar4;
  bool bVar5;
  float fVar6;
  undefined8 local_438 [64];
  undefined8 local_238;
  undefined8 uStack_230;
  undefined8 local_228;
  undefined8 uStack_220;
  undefined8 local_218;
  undefined8 uStack_210;
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  
  puVar4 = local_438;
  for (lVar3 = 0x81; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  uVar1 = FUN_0019c780(param_1,DAT_0038088c,DAT_0038088c,0x13e,local_438,0x408,0);
  switch(uVar1) {
  case 0:
    sVar2 = strlen((char *)&local_238);
    if (sVar2 + 1 < 0x51) {
      if (4 < DAT_01216a78) {
        fVar6 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n",
                     "DEBUG",lVar3,"dmal/common/common_system.c",0x3e,&local_238);
      }
      uRam0000000000380834 = uStack_230;
      _DAT_0038083c = local_228;
      uRam0000000000380844 = uStack_220;
      _DAT_0038084c = local_218;
      uRam0000000000380854 = uStack_210;
      _DAT_0038085c = local_208;
      uRam0000000000380864 = uStack_200;
      _DAT_0038086c = local_1f8;
      uRam0000000000380874 = uStack_1f0;
      DAT_0038082c = (char)local_238;
      bVar5 = DAT_0038082c == '\0';
      _DAT_0038082c = local_238;
      if (bVar5) {
        uVar1 = 999;
      }
    }
    else {
      uVar1 = 7;
    }
    break;
  default:
    uVar1 = 999;
    break;
  case 3:
  case 0x66:
    uVar1 = 10;
    break;
  case 0xf:
    break;
  case 0x17:
  case 99:
    uVar1 = 0x13;
    break;
  case 0x1a:
    uVar1 = 0x17;
    break;
  case 0x1b:
    uVar1 = 4;
    break;
  case 0x1f:
  case 0x3b:
  case 0x54:
    uVar1 = 2;
    break;
  case 0x51:
    uVar1 = 0x14;
    break;
  case 0x55:
    uVar1 = 0x1b;
    break;
  case 0x56:
    uVar1 = 3;
    break;
  case 0x59:
    uVar1 = 0x11;
    break;
  case 0x62:
    uVar1 = 0x10;
  }
  return uVar1;
}


// ===== 001a6330 FUN_001a6330 =====

int FUN_001a6330(long param_1,int *param_2,ulong param_3)

{
  undefined8 uVar1;
  int iVar2;
  size_t sVar3;
  long lVar4;
  float fVar5;
  
  if (param_2 == (int *)0x0) {
    iVar2 = 2;
  }
  else {
    iVar2 = 0x19;
    if (*param_2 == 0x1000054) {
      if (DAT_0038087c == 0) {
        uVar1 = *(undefined8 *)(param_1 + 0x10);
        do {
          iVar2 = FUN_00291820(&DAT_00380880,1,0);
        } while (iVar2 != 0);
        if (DAT_0038087c == 0) {
          DAT_00380884 = FUN_001a6150(uVar1);
          DAT_0038087c = 1;
        }
        FUN_00291830(&DAT_00380880,0);
      }
      iVar2 = DAT_00380884;
      if (DAT_00380884 == 0) {
        sVar3 = strlen(&DAT_0038082c);
        if ((param_3 & 0xffffffff) < sVar3 + 1) {
          iVar2 = 7;
        }
        else {
          memcpy(param_2 + 1,&DAT_0038082c,sVar3 + 1);
        }
      }
      else if (1 < DAT_01216a78) {
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                     "ERROR",lVar4,"dmal/common/common_system.c",0x74,"cSystemGetDriverBranch",0x74,
                     iVar2);
      }
    }
  }
  return iVar2;
}


// ===== 001a64c0 FUN_001a64c0 =====

undefined4 FUN_001a64c0(undefined8 param_1)

{
  undefined1 auVar1 [16];
  undefined8 uVar2;
  undefined4 uVar3;
  long lVar4;
  float fVar5;
  undefined1 local_148 [16];
  undefined1 *local_138;
  undefined1 *local_130;
  undefined8 local_128;
  undefined1 local_118 [16];
  undefined1 local_108 [16];
  undefined1 local_f8 [16];
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  undefined1 local_c8 [16];
  undefined1 local_b8 [16];
  undefined1 local_a8 [16];
  undefined1 local_98 [16];
  undefined1 local_88 [16];
  undefined1 local_78 [16];
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  undefined1 local_38 [16];
  
  local_138 = local_118;
  local_130 = local_c8;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = local_78;
  local_148 = auVar1 << 0x40;
  local_128 = 0;
  local_148._0_4_ = 0x50;
  local_118 = (undefined1  [16])0x0;
  local_108 = (undefined1  [16])0x0;
  local_f8 = (undefined1  [16])0x0;
  local_e8 = (undefined1  [16])0x0;
  local_d8 = (undefined1  [16])0x0;
  local_c8 = (undefined1  [16])0x0;
  local_b8 = (undefined1  [16])0x0;
  local_a8 = (undefined1  [16])0x0;
  local_98 = (undefined1  [16])0x0;
  local_88 = (undefined1  [16])0x0;
  local_78 = (undefined1  [16])0x0;
  local_68 = (undefined1  [16])0x0;
  local_58 = (undefined1  [16])0x0;
  local_48 = (undefined1  [16])0x0;
  local_38 = (undefined1  [16])0x0;
  uVar3 = FUN_0019c780(param_1,DAT_0038088c,DAT_0038088c,0x101,local_148,0x28,0);
  switch(uVar3) {
  case 0:
    if (4 < DAT_01216a78) {
      uVar2 = local_148._8_8_;
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n","DEBUG",
                   lVar4,"dmal/common/common_system.c",0x1a,uVar2);
    }
    strncpy(&DAT_00380800,(char *)local_148._8_8_,0x1f);
    DAT_0038081f = 0;
    if (DAT_00380800 == '\0') {
      uVar3 = 999;
    }
    break;
  default:
    uVar3 = 999;
    break;
  case 3:
  case 0x66:
    uVar3 = 10;
    break;
  case 0xf:
    break;
  case 0x17:
  case 99:
    uVar3 = 0x13;
    break;
  case 0x1a:
    uVar3 = 0x17;
    break;
  case 0x1b:
    uVar3 = 4;
    break;
  case 0x1f:
  case 0x3b:
  case 0x54:
    uVar3 = 2;
    break;
  case 0x51:
    uVar3 = 0x14;
    break;
  case 0x55:
    uVar3 = 0x1b;
    break;
  case 0x56:
    uVar3 = 3;
    break;
  case 0x59:
    uVar3 = 0x11;
    break;
  case 0x62:
    uVar3 = 0x10;
  }
  return uVar3;
}


// ===== 001a66e0 FUN_001a66e0 =====

int FUN_001a66e0(long param_1,void *param_2,ulong param_3)

{
  undefined8 uVar1;
  int iVar2;
  size_t sVar3;
  long lVar4;
  float fVar5;
  
  if (DAT_00380820 == 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x10);
    do {
      iVar2 = FUN_00291820(&DAT_00380824,1,0);
    } while (iVar2 != 0);
    if (DAT_00380820 == 0) {
      DAT_00380828 = FUN_001a64c0(uVar1);
      DAT_00380820 = 1;
    }
    FUN_00291830(&DAT_00380824,0);
  }
  iVar2 = DAT_00380828;
  if (DAT_00380828 == 0) {
    sVar3 = strlen(&DAT_00380800);
    if ((param_3 & 0xffffffff) < sVar3 + 1) {
      iVar2 = 7;
    }
    else {
      memcpy(param_2,&DAT_00380800,sVar3 + 1);
    }
  }
  else if (1 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_system.c",0x53,"cSystemGetDriverVersion",0x53,
                 iVar2);
  }
  return iVar2;
}


// ===== 001a6830 FUN_001a6830 =====

ulong FUN_001a6830(long param_1,long param_2,undefined8 *param_3)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulong uVar4;
  int iVar5;
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined4 local_48;
  
  lVar1 = *(long *)(param_2 + 0x256d8);
  if (((lVar1 == 0) || (*(undefined8 **)(lVar1 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar1 + 0x50), pcVar2 == (code *)0x0)) {
switchD_001a6907_caseD_1:
    uVar4 = 999;
  }
  else {
    uVar3 = *(undefined8 *)(param_1 + 0x10);
    uVar4 = (*pcVar2)(lVar1,param_2,0x2080,&local_6c);
    if ((int)uVar4 != 0) {
      if ((int)uVar4 == 0xf) {
        return uVar4;
      }
      goto switchD_001a6907_caseD_1;
    }
    local_70 = 0;
    local_48 = 0;
    local_68 = (undefined1  [16])0x0;
    local_58 = (undefined1  [16])0x0;
    uVar4 = FUN_0019c780(uVar3,DAT_0038088c,local_6c,0x2080013c,&local_70,4,0);
    switch(uVar4 & 0xffffffff) {
    case 0:
      iVar5 = 0x21;
      do {
        uVar4 = FUN_0019c780(uVar3,DAT_0038088c,local_6c,0x2080013d,local_68,0x24,0);
        if ((int)uVar4 != 0x55) {
          switch(uVar4 & 0xffffffff) {
          case 0:
            *param_3 = local_68._0_8_;
            param_3[1] = local_68._8_8_;
            param_3[2] = local_58._0_8_;
            param_3[3] = local_58._8_8_;
            *(undefined4 *)(param_3 + 4) = local_48;
            return uVar4;
          default:
            goto switchD_001a6907_caseD_1;
          case 3:
          case 0x66:
            goto switchD_001a6907_caseD_3;
          case 0xf:
            return uVar4;
          case 0x17:
          case 99:
            goto switchD_001a6907_caseD_17;
          case 0x1a:
            goto switchD_001a6907_caseD_1a;
          case 0x1b:
            goto switchD_001a6907_caseD_1b;
          case 0x1f:
          case 0x3b:
          case 0x54:
            goto switchD_001a6907_caseD_1f;
          case 0x51:
            goto switchD_001a6907_caseD_51;
          case 0x56:
            goto switchD_001a6907_caseD_56;
          case 0x59:
            goto switchD_001a6907_caseD_59;
          case 0x62:
            goto switchD_001a6907_caseD_62;
          }
        }
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    case 0x55:
      uVar4 = 0x1b;
      break;
    default:
      goto switchD_001a6907_caseD_1;
    case 3:
    case 0x66:
switchD_001a6907_caseD_3:
      uVar4 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
switchD_001a6907_caseD_17:
      uVar4 = 0x13;
      break;
    case 0x1a:
switchD_001a6907_caseD_1a:
      uVar4 = 0x17;
      break;
    case 0x1b:
switchD_001a6907_caseD_1b:
      uVar4 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
switchD_001a6907_caseD_1f:
      uVar4 = 2;
      break;
    case 0x51:
switchD_001a6907_caseD_51:
      uVar4 = 0x14;
      break;
    case 0x56:
switchD_001a6907_caseD_56:
      uVar4 = 3;
      break;
    case 0x59:
switchD_001a6907_caseD_59:
      uVar4 = 0x11;
      break;
    case 0x62:
switchD_001a6907_caseD_62:
      uVar4 = 0x10;
    }
  }
  return uVar4;
}


// ===== 001a6a00 FUN_001a6a00 =====

ulong FUN_001a6a00(long param_1,long param_2,uint param_3,undefined4 param_4)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  uint uVar4;
  ulong uVar5;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  
  lVar1 = *(long *)(param_2 + 0x256d8);
  if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0x50) != (undefined8 *)0x0)) &&
     (pcVar2 = (code *)**(undefined8 **)(lVar1 + 0x50), pcVar2 != (code *)0x0)) {
    uVar3 = *(undefined8 *)(param_1 + 0x10);
    uVar5 = (*pcVar2)(lVar1,param_2,0x2080,&local_34);
    if ((int)uVar5 == 0) {
      if (param_3 == 2) {
        local_30 = 8;
      }
      else if (param_3 < 3) {
        local_30 = (-(uint)(param_3 == 0) & 0xfffffffe) + 4;
      }
      else {
        if (param_3 != 3) {
          return 3;
        }
        local_30 = 1;
      }
      local_2c = param_4;
      uVar4 = FUN_0019c780(uVar3,DAT_0038088c,local_34,0x2080013b,&local_30,8,0);
      if (uVar4 < 0x67) {
        return (ulong)*(ushort *)(&DAT_002acdc0 + (ulong)uVar4 * 2);
      }
    }
    else if ((int)uVar5 == 0xf) {
      return uVar5;
    }
  }
  return 999;
}


// ===== 001a6b00 FUN_001a6b00 =====

/* WARNING: Type propagation algorithm not settling */

ulong FUN_001a6b00(long param_1,char *param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  undefined8 uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  long lVar7;
  ulong uVar8;
  char *pcVar9;
  undefined8 *puVar10;
  ulong uVar11;
  byte bVar12;
  float fVar13;
  undefined4 local_166c;
  undefined8 local_1668 [7];
  char local_1629 [2385];
  undefined8 local_cd8;
  undefined4 auStack_cb4 [801];
  
  bVar12 = 0;
  if (param_2 == (char *)0x0) {
    return 2;
  }
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
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  if (*(int *)(param_2 + 0x71c) == 0) {
    do {
      iVar4 = FUN_00291820(param_2 + 0x720,1,0);
    } while (iVar4 != 0);
    if (*(int *)(param_2 + 0x71c) == 0) {
      lVar7 = *(long *)(param_2 + 0x256d8);
      uVar5 = 3;
      if (((lVar7 != 0) && (*(long *)(lVar7 + 0x20) != 0)) &&
         (pcVar2 = *(code **)(*(long *)(lVar7 + 0x20) + 0x98), pcVar2 != (code *)0x0)) {
        uVar5 = (*pcVar2)(lVar7,param_2,param_2 + 0x708);
      }
      *(undefined4 *)(param_2 + 0x724) = uVar5;
      param_2[0x71c] = '\x01';
      param_2[0x71d] = '\0';
      param_2[0x71e] = '\0';
      param_2[0x71f] = '\0';
    }
    FUN_00291830(param_2 + 0x720,0);
  }
  if (*(int *)(param_2 + 0x724) != 0) {
    if (*(int *)(param_2 + 0x724) == 0xf) {
      if (4 < DAT_01216a78) {
        fVar13 = (float)FUN_002917b0(&DAT_01216a60);
        lVar7 = syscall(0xba);
        FUN_002340f0((double)(fVar13 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tisArchOrNewer error: %d\n","DEBUG",lVar7,
                     "/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h",0x42,10);
        return 0xf;
      }
      return 0xf;
    }
    if (DAT_01216a78 < 2) {
      return 3;
    }
    fVar13 = (float)FUN_002917b0(&DAT_01216a60);
    lVar7 = syscall(0xba);
    FUN_002340f0((double)(fVar13 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tFailure to determine Architecture\n","ERROR",
                 lVar7,"/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h",0x46);
    return 3;
  }
  if (4 < DAT_01216a78) {
    uVar5 = *(undefined4 *)(param_2 + 0x708);
    fVar13 = (float)FUN_002917b0(&DAT_01216a60);
    lVar7 = syscall(0xba);
    FUN_002340f0((double)(fVar13 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tisArchOrNewer called: %d %d\n","DEBUG",lVar7,
                 "/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h",0x3d,10,uVar5);
  }
  if (*(uint *)(param_2 + 0x708) < 10) {
    return 3;
  }
  lVar7 = *(long *)(param_2 + 0x256d8);
  if (((lVar7 == 0) || (*(undefined8 **)(lVar7 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar7 + 0x50), pcVar2 == (code *)0x0)) {
    uVar11 = 3;
LAB_001a6dc6:
    if (1 < DAT_01216a78) {
      fVar13 = (float)FUN_002917b0(&DAT_01216a60);
      lVar7 = syscall(0xba);
      FUN_002340f0((double)(fVar13 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar7,"dmal/common/common_volt.c",0x3e,"cDeviceGetVoltageMicrovolts",0x3e
                   ,uVar11);
      return uVar11;
    }
    return uVar11;
  }
  uVar6 = (*pcVar2)(lVar7,param_2,0x2080,&local_166c);
  uVar11 = (ulong)uVar6;
  if (uVar6 != 0) goto LAB_001a6dc6;
  if (*(int *)(param_2 + 0x25564) == 0) {
    do {
      iVar4 = FUN_00291820(param_2 + 0x25568,1,0);
    } while (iVar4 != 0);
    if (*(int *)(param_2 + 0x25564) == 0) {
      lVar7 = *(long *)(param_2 + 0x256d8);
      if (((lVar7 == 0) || (*(undefined8 **)(lVar7 + 0x50) == (undefined8 *)0x0)) ||
         (pcVar2 = (code *)**(undefined8 **)(lVar7 + 0x50), pcVar2 == (code *)0x0)) {
        iVar4 = 3;
LAB_001a7116:
        if (1 < DAT_01216a78) {
          fVar13 = (float)FUN_002917b0(&DAT_01216a60);
          lVar7 = syscall(0xba);
          FUN_002340f0((double)(fVar13 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar7,
                       "dmal/common/common_volt.c",0x13,"deviceGetVoltRailsInfoUncached",0x13,iVar4)
          ;
        }
      }
      else {
        uVar3 = *(undefined8 *)(param_1 + 0x10);
        iVar4 = (*pcVar2)(lVar7,param_2,0x2080,local_1668);
        if (iVar4 != 0) goto LAB_001a7116;
        puVar10 = &local_cd8;
        for (lVar7 = 0x131; lVar7 != 0; lVar7 = lVar7 + -1) {
          *puVar10 = 0;
          puVar10 = puVar10 + (ulong)bVar12 * -2 + 1;
        }
        *(undefined4 *)puVar10 = 0;
        iVar4 = FUN_0019c780(uVar3,DAT_0038088c,(undefined4)local_1668[0],0x2080b201,&local_cd8,
                             0x98c,0);
        switch(iVar4) {
        case 0:
          *(uint *)(param_2 + 0x25560) = local_cd8._4_4_;
          break;
        default:
          iVar4 = 999;
          break;
        case 3:
        case 0x66:
          iVar4 = 10;
          break;
        case 0xf:
          break;
        case 0x17:
        case 99:
          iVar4 = 0x13;
          break;
        case 0x1a:
          iVar4 = 0x17;
          break;
        case 0x1b:
          iVar4 = 4;
          break;
        case 0x1f:
        case 0x3b:
        case 0x54:
          iVar4 = 2;
          break;
        case 0x51:
          iVar4 = 0x14;
          break;
        case 0x55:
          iVar4 = 0x1b;
          break;
        case 0x56:
          iVar4 = 3;
          break;
        case 0x59:
          iVar4 = 0x11;
          break;
        case 0x62:
          iVar4 = 0x10;
        }
      }
      *(int *)(param_2 + 0x2556c) = iVar4;
      param_2[0x25564] = '\x01';
      param_2[0x25565] = '\0';
      param_2[0x25566] = '\0';
      param_2[0x25567] = '\0';
    }
    FUN_00291830(param_2 + 0x25568,0);
  }
  if (*(uint *)(param_2 + 0x2556c) != 0) {
    return (ulong)*(uint *)(param_2 + 0x2556c);
  }
  puVar10 = local_1668;
  for (lVar7 = 0x131; lVar7 != 0; lVar7 = lVar7 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + (ulong)bVar12 * -2 + 1;
  }
  *(undefined4 *)puVar10 = 0;
  uVar6 = FUN_0019c780(uVar1,DAT_0038088c,local_166c,0x2080b201,local_1668,0x98c,0);
  switch(uVar6) {
  case 0:
    puVar10 = &local_cd8;
    for (lVar7 = 0x194; lVar7 != 0; lVar7 = lVar7 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + (ulong)bVar12 * -2 + 1;
    }
    local_cd8._4_4_ = *(uint *)(param_2 + 0x25560);
    uVar6 = FUN_0019c780(uVar1,DAT_0038088c,local_166c,0x2080b202,&local_cd8,0xca0,0);
    uVar11 = (ulong)uVar6;
    switch(uVar6) {
    case 0:
      pcVar9 = local_1629;
      uVar8 = uVar11;
      do {
        if (((local_cd8._4_4_ >> ((uint)uVar8 & 0x1f) & 1) != 0) && (*pcVar9 == '\x01')) {
          uVar5 = auStack_cb4[uVar8 * 0x19];
          *param_3 = uVar5;
          if (4 < DAT_01216a78) {
            fVar13 = (float)FUN_002917b0(&DAT_01216a60);
            lVar7 = syscall(0xba);
            FUN_002340f0((double)(fVar13 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n",
                         "DEBUG",lVar7,"dmal/common/common_volt.c",0x5c,uVar5);
            return uVar11;
          }
          return uVar11;
        }
        uVar6 = (uint)uVar8 + 1;
        uVar8 = (ulong)uVar6;
        pcVar9 = pcVar9 + 0x4c;
      } while (uVar6 != 0x20);
      break;
    default:
      goto switchD_001a6db7_caseD_1;
    case 3:
    case 0x66:
      goto switchD_001a6db7_caseD_3;
    case 0xf:
      return uVar11;
    case 0x17:
    case 99:
      goto switchD_001a6db7_caseD_17;
    case 0x1a:
      goto switchD_001a6db7_caseD_1a;
    case 0x1b:
      goto switchD_001a6db7_caseD_1b;
    case 0x1f:
    case 0x3b:
    case 0x54:
      goto switchD_001a6db7_caseD_1f;
    case 0x51:
      goto switchD_001a6db7_caseD_51;
    case 0x55:
      goto switchD_001a6db7_caseD_55;
    case 0x56:
      break;
    case 0x59:
      goto switchD_001a6db7_caseD_59;
    case 0x62:
      goto switchD_001a6db7_caseD_62;
    }
switchD_001a6db7_caseD_56:
    return 3;
  default:
switchD_001a6db7_caseD_1:
    return 999;
  case 3:
  case 0x66:
switchD_001a6db7_caseD_3:
    return 10;
  case 0xf:
    return (ulong)uVar6;
  case 0x17:
  case 99:
switchD_001a6db7_caseD_17:
    return 0x13;
  case 0x1a:
switchD_001a6db7_caseD_1a:
    return 0x17;
  case 0x1b:
switchD_001a6db7_caseD_1b:
    return 4;
  case 0x1f:
  case 0x3b:
  case 0x54:
switchD_001a6db7_caseD_1f:
    return 2;
  case 0x51:
switchD_001a6db7_caseD_51:
    return 0x14;
  case 0x55:
switchD_001a6db7_caseD_55:
    return 0x1b;
  case 0x56:
    goto switchD_001a6db7_caseD_56;
  case 0x59:
switchD_001a6db7_caseD_59:
    return 0x11;
  case 0x62:
switchD_001a6db7_caseD_62:
    return 0x10;
  }
}


// ===== 001a72b0 FUN_001a72b0 =====

uint FUN_001a72b0(long param_1,long param_2,uint *param_3,int *param_4)

{
  undefined8 uVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  int *piVar6;
  float fVar7;
  undefined4 local_404c;
  uint local_4048;
  int local_4044 [4101];
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  memset(&local_4048,0,0x4004);
  lVar5 = *(long *)(param_2 + 0x256d8);
  if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar5 + 0x50), pcVar2 == (code *)0x0)) {
    uVar3 = 3;
  }
  else {
    uVar3 = (*pcVar2)(lVar5,param_2,0x2080,&local_404c);
    if (uVar3 == 0) {
      if ((*param_3 == 0) || (param_4 == (int *)0x0)) {
        uVar3 = FUN_0019c780(uVar1,DAT_0038088c,local_404c,0x208001af,&local_4048,0x4004,0);
        switch(uVar3) {
        case 0:
          *param_3 = local_4048;
          return uVar3;
        default:
          return 999;
        case 3:
        case 0x66:
          return 10;
        case 0xf:
          return uVar3;
        case 0x17:
        case 99:
          return 0x13;
        case 0x1a:
          return 0x17;
        case 0x1b:
          return 4;
        case 0x1f:
        case 0x3b:
        case 0x54:
          return 2;
        case 0x51:
          return 0x14;
        case 0x55:
          return 0x1b;
        case 0x56:
          return 3;
        case 0x59:
          return 0x11;
        case 0x62:
          return 0x10;
        }
      }
      local_4048 = 0x200;
      iVar4 = FUN_0019c780(uVar1,DAT_0038088c,local_404c,0x208001af,&local_4048,0x4004,0);
      if (iVar4 != 0) {
        if (99 < iVar4 - 3U) {
          return 999;
        }
        return (uint)*(ushort *)(&DAT_002ada60 + (ulong)(iVar4 - 3U) * 2);
      }
      uVar3 = *param_3;
      *param_3 = local_4048;
      if (uVar3 < local_4048) {
        return 7;
      }
      uVar3 = 0;
      piVar6 = local_4044;
      if (local_4048 == 0) {
        return 0;
      }
      do {
        iVar4 = *piVar6;
        *param_4 = piVar6[2];
        if (piVar6[1] == 0) {
          param_4[1] = iVar4;
          param_4[2] = 0;
        }
        else {
          param_4[1] = piVar6[1];
          param_4[2] = iVar4;
        }
        uVar3 = uVar3 + 1;
        param_4[3] = piVar6[3];
        param_4[4] = piVar6[4];
        param_4[5] = piVar6[5];
        param_4[6] = piVar6[6];
        param_4[7] = piVar6[7];
        piVar6 = piVar6 + 8;
        param_4 = param_4 + 8;
      } while (uVar3 < *param_3);
      return 0;
    }
  }
  if (1 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar5,"dmal/common/common_encode.c",0x56,"cDeviceGetEncoderSessionsV2",0x56
                 ,uVar3);
  }
  return uVar3;
}


// ===== 001a75c0 FUN_001a75c0 =====

int FUN_001a75c0(long param_1,long param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 *param_5)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  undefined4 local_48;
  undefined8 local_44;
  undefined4 local_3c;
  
  local_44 = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  local_3c = 0;
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    iVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_48);
    if (iVar3 == 0) {
      iVar3 = FUN_0019c780(uVar1,DAT_0038088c,local_48,0x2080016d,&local_44,0xc,0);
      switch(iVar3) {
      case 0:
        *param_3 = (undefined4)local_44;
        *param_4 = local_44._4_4_;
        *param_5 = local_3c;
        return iVar3;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar3;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (1 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_encode.c",0x35,"cDeviceGetEncoderStats",0x35,
                 iVar3);
  }
  return iVar3;
}


// ===== 001a77d0 FUN_001a77d0 =====

int FUN_001a77d0(long param_1,long param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  undefined4 local_34;
  undefined8 local_30;
  
  local_30 = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    iVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_34);
    if (iVar3 == 0) {
      local_30._0_4_ = param_3;
      iVar3 = FUN_0019c780(uVar1,DAT_0038088c,local_34,0x2080016c,&local_30,8,0);
      switch(iVar3) {
      case 0:
        *param_4 = local_30._4_4_;
        return iVar3;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar3;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar3;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar4,"dmal/common/common_encode.c",0x15,"cDeviceGetGpuEncoderCapacity",0x15,
               iVar3);
  return iVar3;
}


// ===== 001a79e0 FUN_001a79e0 =====

uint FUN_001a79e0(long param_1,long param_2,uint *param_3,long param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  void *__ptr;
  undefined4 *puVar7;
  long lVar8;
  float fVar9;
  undefined4 local_4c;
  undefined1 local_48 [24];
  
  local_48._0_16_ = (undefined1  [16])0x0;
  uVar3 = *(undefined8 *)(param_1 + 0x10);
  lVar8 = *(long *)(param_2 + 0x256d8);
  if (((lVar8 == 0) || (*(undefined8 **)(lVar8 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar4 = (code *)**(undefined8 **)(lVar8 + 0x50), pcVar4 == (code *)0x0)) {
    uVar5 = 3;
  }
  else {
    uVar5 = (*pcVar4)(lVar8,param_2,0x2080,&local_4c);
    if (uVar5 == 0) {
      if ((*param_3 == 0) || (param_4 == 0)) {
        local_48._8_8_ = 0;
        uVar5 = FUN_0019c780(uVar3,DAT_0038088c,local_4c,0x2080016e,local_48,0x10,0);
        switch(uVar5) {
        case 0:
          *param_3 = local_48._0_4_;
          return uVar5;
        default:
          return 999;
        case 3:
        case 0x66:
          return 10;
        case 0xf:
          return uVar5;
        case 0x17:
        case 99:
          return 0x13;
        case 0x1a:
          return 0x17;
        case 0x1b:
          return 4;
        case 0x1f:
        case 0x3b:
        case 0x54:
          return 2;
        case 0x51:
          goto switchD_001a7c17_caseD_51;
        case 0x55:
          return 0x1b;
        case 0x56:
          return 3;
        case 0x59:
          return 0x11;
        case 0x62:
          return 0x10;
        }
      }
      __ptr = malloc(0x4000);
      if (__ptr == (void *)0x0) {
switchD_001a7c17_caseD_51:
        return 0x14;
      }
      local_48._8_8_ = __ptr;
      local_48._0_4_ = 0x200;
      iVar6 = FUN_0019c780(uVar3,DAT_0038088c,local_4c,0x2080016e,local_48,0x10,0);
      if (iVar6 == 0) {
        uVar5 = *param_3;
        *param_3 = local_48._0_4_;
        if ((uint)local_48._0_4_ <= uVar5) {
          uVar5 = 0;
          if (local_48._0_4_ != 0) {
            do {
              puVar1 = (undefined4 *)((long)__ptr + (ulong)uVar5 * 0x20);
              puVar7 = (undefined4 *)((ulong)uVar5 * 0x20 + param_4);
              uVar2 = *puVar1;
              *puVar7 = puVar1[2];
              if (puVar1[1] == 0) {
                puVar7[1] = uVar2;
                puVar7[2] = 0;
              }
              else {
                puVar7[1] = puVar1[1];
                puVar7[2] = uVar2;
              }
              uVar2 = puVar1[7];
              uVar5 = uVar5 + 1;
              uVar3 = *(undefined8 *)(puVar1 + 5);
              *(undefined8 *)(puVar7 + 3) = *(undefined8 *)(puVar1 + 3);
              *(undefined8 *)(puVar7 + 5) = uVar3;
              puVar7[7] = uVar2;
            } while (uVar5 < *param_3);
          }
          free(__ptr);
          return 0;
        }
        free(__ptr);
        return 7;
      }
      free(__ptr);
      if (99 < iVar6 - 3U) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002ada60 + (ulong)(iVar6 - 3U) * 2);
    }
  }
  if (1 < DAT_01216a78) {
    fVar9 = (float)FUN_002917b0(&DAT_01216a60);
    lVar8 = syscall(0xba);
    FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar8,"dmal/common/common_encode.c",0xa4,"cDeviceGetEncoderSessions",0xa4,
                 uVar5);
  }
  return uVar5;
}


// ===== 001a7d00 FUN_001a7d00 =====

int FUN_001a7d00(undefined8 param_1,long param_2,long param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c [3];
  
  if (param_3 == 0) {
    return 2;
  }
  if ((*(long *)(param_2 + 0x25d60) != 0) && (*(int *)(param_3 + 4) == 2)) {
    *(undefined4 *)(param_3 + 8) = 0;
    return 0;
  }
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,0x2080,local_2c);
    if (iVar2 == 0) {
      lVar3 = *(long *)(param_2 + 0x256d8);
      if (((lVar3 == 0) || (*(long *)(lVar3 + 0xc0) == 0)) ||
         (pcVar1 = *(code **)(*(long *)(lVar3 + 0xc0) + 0x18), pcVar1 == (code *)0x0)) {
        iVar2 = 3;
      }
      else {
        iVar2 = (*pcVar1)(lVar3,param_2,*(undefined4 *)(param_3 + 4),&local_34,&local_30);
        if (iVar2 == 0) {
          if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0xc0) != 0)) &&
             (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0xc0) + 0x30), pcVar1 != (code *)0x0)) {
            iVar2 = (*pcVar1)(DAT_012164a0,DAT_0038088c,local_2c[0],local_34,local_30,param_3,0);
            return iVar2;
          }
          return 3;
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0x2fb;
      uVar4 = 0x2fb;
      goto LAB_001a7e95;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  fVar5 = fVar5 * DAT_00298548;
  uVar6 = 0x2f6;
  uVar4 = 0x2f6;
LAB_001a7e95:
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
               "dmal/common/common_pids.c",uVar4,"cDeviceGetRunningProcessDetailList",uVar6,iVar2);
  return iVar2;
}


// ===== 001a7f70 FUN_001a7f70 =====

undefined8 FUN_001a7f70(char *param_1,void *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  FILE *__stream;
  size_t sVar3;
  undefined8 uVar4;
  int *piVar5;
  long lVar6;
  char *pcVar7;
  uint uVar8;
  float fVar9;
  float local_440;
  undefined1 local_438 [1032];
  
  __stream = fopen(param_1,"r");
  if (__stream != (FILE *)0x0) {
    sVar3 = fread(param_2,1,(ulong)param_3,__stream);
    iVar1 = ferror(__stream);
    if (iVar1 == 0) {
      fclose(__stream);
      uVar4 = 0x15;
      uVar8 = (uint)sVar3;
      if (uVar8 != 0) {
        pcVar7 = (char *)((ulong)(uVar8 - 1) + (long)param_2);
        if (param_3 == uVar8) {
          *pcVar7 = '\0';
          uVar4 = 0;
        }
        else {
          uVar4 = 0;
          *(undefined1 *)((long)param_2 + (sVar3 & 0xffffffff)) = 0;
          if (*pcVar7 == '\n') {
            *pcVar7 = '\0';
          }
        }
      }
      return uVar4;
    }
    if (1 < DAT_01216a78) {
      iVar1 = ferror(__stream);
      fVar9 = (float)FUN_002917b0(&DAT_01216a60);
      lVar6 = syscall(0xba);
      FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","ERROR",
                   lVar6,"dmal/common/common_pids.c",0x335,iVar1);
    }
    fclose(__stream);
    return 999;
  }
  piVar5 = __errno_location();
  iVar1 = *piVar5;
  if (1 < DAT_01216a78) {
    iVar2 = FUN_00234050(iVar1,local_438,0x400);
    if (iVar2 == 0) {
      if (DAT_01216a78 < 2) goto LAB_001a8029;
      fVar9 = (float)FUN_002917b0(&DAT_01216a60);
      lVar6 = syscall(0xba);
      local_440 = DAT_00298548;
      FUN_002340f0((double)(fVar9 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tOS error: %d %s\n\n","ERROR",lVar6,
                   "dmal/common/common_pids.c",0x317,iVar1,local_438);
    }
    else {
      if (DAT_01216a78 < 2) goto LAB_001a8029;
      fVar9 = (float)FUN_002917b0(&DAT_01216a60);
      lVar6 = syscall(0xba);
      local_440 = DAT_00298548;
      FUN_002340f0((double)(fVar9 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tOS error %d\n\n","ERROR",lVar6,
                   "dmal/common/common_pids.c",0x317,iVar1);
    }
    if (1 < DAT_01216a78) {
      fVar9 = (float)FUN_002917b0(&DAT_01216a60);
      lVar6 = syscall(0xba);
      FUN_002340f0((double)(fVar9 * local_440),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\'%s\'\n","ERROR"
                   ,lVar6,"dmal/common/common_pids.c",0x317,param_1);
    }
  }
LAB_001a8029:
  uVar4 = 6;
  if (iVar1 != 2) {
    uVar4 = 999;
  }
  return uVar4;
}


// ===== 001a8290 FUN_001a8290 =====

void FUN_001a8290(undefined8 param_1,ulong param_2,undefined8 param_3,undefined4 param_4)

{
  char local_a8 [136];
  
  snprintf(local_a8,0x80,"/proc/%u/cmdline",param_2 & 0xffffffff);
  FUN_001a7f70(local_a8,param_3,param_4);
  return;
}


// ===== 001a82f0 FUN_001a82f0 =====

int FUN_001a82f0(undefined8 param_1,long param_2,undefined4 param_3,int param_4,undefined4 *param_5,
                undefined8 param_6)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  if ((*(long *)(param_2 + 0x25d60) != 0) && (param_4 == 2)) {
    *param_5 = 0;
    return 0;
  }
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,0x2080,local_3c);
    if (iVar2 == 0) {
      lVar3 = *(long *)(param_2 + 0x256d8);
      if (((lVar3 == 0) || (*(long *)(lVar3 + 0xc0) == 0)) ||
         (pcVar1 = *(code **)(*(long *)(lVar3 + 0xc0) + 0x18), pcVar1 == (code *)0x0)) {
        iVar2 = 3;
      }
      else {
        iVar2 = (*pcVar1)(lVar3,param_2,param_4,&local_44,&local_40);
        if (iVar2 == 0) {
          if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0xc0) != 0)) &&
             (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0xc0) + 0x20), pcVar1 != (code *)0x0)) {
            iVar2 = (*pcVar1)(DAT_012164a0,param_3,DAT_0038088c,local_3c[0],local_44,local_40,
                              param_5,param_6,0);
            return iVar2;
          }
          return 3;
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0x254;
      uVar4 = 0x254;
      goto LAB_001a8495;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  fVar5 = fVar5 * DAT_00298548;
  uVar6 = 0x24f;
  uVar4 = 0x24f;
LAB_001a8495:
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
               "dmal/common/common_pids.c",uVar4,"_cDeviceGetRunningProcesses",uVar6,iVar2);
  return iVar2;
}


// ===== 001a8540 FUN_001a8540 =====

undefined2
FUN_001a8540(undefined8 param_1,int *param_2,undefined4 param_3,undefined4 param_4,uint param_5,
            uint param_6,long param_7)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  int *piVar4;
  undefined2 uVar5;
  uint *puVar6;
  float fVar7;
  
  *param_2 = param_6 - param_5;
  if (param_5 < param_6) {
    puVar6 = (uint *)(param_2 + 2);
    uVar3 = 0;
    piVar4 = param_2;
    while( true ) {
      uVar1 = *(uint *)(param_7 + (ulong)param_5 * 4 + uVar3 * 4);
      puVar6[1] = 0;
      *puVar6 = uVar1;
      if (4 < DAT_01216a78) {
        fVar7 = (float)FUN_002917b0(&DAT_01216a60,piVar4);
        lVar2 = syscall(0xba);
        piVar4 = (int *)(ulong)uVar1;
        FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u\n",
                     "DEBUG",lVar2,"dmal/common/common_pids.c",0x1b7,uVar3 & 0xffffffff);
      }
      if (uVar3 == (param_6 - param_5) - 1) break;
      uVar3 = uVar3 + 1;
      puVar6 = puVar6 + 0x12;
    }
  }
  uVar1 = FUN_0019c780(param_1,param_3,param_4,0x2080018e,param_2,0x3848);
  uVar5 = 999;
  if (uVar1 < 0x67) {
    uVar5 = *(undefined2 *)(&DAT_002adec0 + (ulong)uVar1 * 2);
  }
  return uVar5;
}


// ===== 001a8690 FUN_001a8690 =====

undefined1  [16]
FUN_001a8690(undefined8 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,uint *param_7)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  undefined1 auVar4 [16];
  
  param_2[1] = param_5;
  *param_2 = param_6;
  uVar2 = FUN_0019c780(param_1,param_3,param_4,0x2080018d,param_2,0xee4);
  uVar3 = 0;
  if ((uint)uVar2 < 0x67) {
    uVar3 = (long)&switchD_001a86d3::switchdataD_002adc68 +
            (long)(int)(&switchD_001a86d3::switchdataD_002adc68)[uVar2 & 0xffffffff];
    switch(uVar2 & 0xffffffff) {
    case 0:
      uVar1 = param_2[2];
      uVar3 = (ulong)uVar1;
      if (*param_7 < uVar1) {
        *param_7 = uVar1;
        uVar2 = 7;
      }
      else {
        *param_7 = uVar1;
      }
      break;
    default:
      goto switchD_001a86d3_caseD_1;
    case 3:
    case 0x66:
      uVar2 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      uVar2 = 0x13;
      break;
    case 0x1a:
      uVar2 = 0x17;
      break;
    case 0x1b:
      uVar2 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
      uVar2 = 2;
      break;
    case 0x51:
      uVar2 = 0x14;
      break;
    case 0x55:
      uVar2 = 0x1b;
      break;
    case 0x56:
      uVar2 = 3;
      break;
    case 0x59:
      uVar2 = 0x11;
      break;
    case 0x62:
      uVar2 = 0x10;
    }
  }
  else {
switchD_001a86d3_caseD_1:
    uVar2 = 999;
  }
  auVar4._8_8_ = uVar3;
  auVar4._0_8_ = uVar2;
  return auVar4;
}


// ===== 001a8760 FUN_001a8760 =====

int FUN_001a8760(long param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,uint *param_7,long param_8,char param_9)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined8 *puVar9;
  uint uVar10;
  undefined8 uVar11;
  ulong uVar12;
  undefined4 *puVar13;
  uint uVar14;
  float fVar15;
  undefined8 uVar16;
  undefined8 local_4778;
  uint local_4770;
  uint local_3888 [2];
  undefined4 local_3880 [3604];
  
  puVar9 = &local_4778;
  for (lVar6 = 0x1dc; lVar6 != 0; lVar6 = lVar6 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  *(undefined4 *)puVar9 = 0;
  memset(local_3888,0,0x3848);
  iVar5 = FUN_001a8690(*(undefined8 *)(param_1 + 0x10),&local_4778,param_3,param_4,param_5,param_6,
                       param_7);
  if (iVar5 == 0) {
    if (*param_7 != 0) {
      if (param_8 == 0) {
        iVar5 = 2;
      }
      else {
        uVar8 = 0;
        if (local_4770 != 0) {
          uVar8 = 0;
          uVar10 = 0;
          do {
            uVar14 = uVar10 + 200;
            uVar4 = local_4770;
            if (uVar14 <= local_4770) {
              uVar4 = uVar14;
            }
            iVar5 = FUN_001a8540(*(undefined8 *)(param_1 + 0x10),local_3888,param_3,param_4,uVar10,
                                 uVar4);
            if (iVar5 != 0) {
              if (DAT_01216a78 < 2) {
                return iVar5;
              }
              fVar15 = (float)FUN_002917b0(&DAT_01216a60);
              lVar6 = syscall(0xba);
              fVar15 = fVar15 * DAT_00298548;
              uVar16 = 0x1ec;
              uVar11 = 0x1ec;
              goto LAB_001a8b6b;
            }
            puVar13 = local_3880;
            if (local_3888[0] != 0) {
              uVar12 = (ulong)uVar8;
              uVar8 = 0;
              do {
                iVar5 = puVar13[2];
                if (iVar5 == 0) {
                  uVar1 = *puVar13;
                  lVar6 = -1;
                  if (param_9 == '\0') {
                    lVar6 = *(long *)(puVar13 + 6) + *(long *)(puVar13 + 4);
                  }
                  if (param_2 == 1) {
                    puVar7 = (undefined4 *)(uVar12 * 0x10 + param_8);
                    *(long *)(puVar7 + 2) = lVar6;
                    *puVar7 = uVar1;
                  }
                  else {
                    if (param_2 != 2) {
                      return 6;
                    }
                    puVar7 = (undefined4 *)(param_8 + uVar12 * 0x18);
                    *(long *)(puVar7 + 2) = lVar6;
                    uVar2 = puVar13[0x10];
                    *puVar7 = uVar1;
                    puVar7[5] = uVar2;
                    puVar7[4] = puVar13[0x11];
                  }
                  if (4 < DAT_01216a78) {
                    uVar11 = *(undefined8 *)(puVar13 + 8);
                    uVar16 = *(undefined8 *)(puVar13 + 6);
                    uVar3 = *(undefined8 *)(puVar13 + 4);
                    fVar15 = (float)FUN_002917b0(&DAT_01216a60);
                    lVar6 = syscall(0xba);
                    FUN_002340f0((double)(fVar15 * DAT_00298548),
                                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u (%llu %llu %llu) %u\n",
                                 "DEBUG",lVar6,"dmal/common/common_pids.c",0x223,uVar8,uVar1,uVar3,
                                 uVar16,uVar11,0);
                  }
                  uVar12 = (ulong)((int)uVar12 + 1);
                }
                else if (4 < DAT_01216a78) {
                  uVar1 = *puVar13;
                  fVar15 = (float)FUN_002917b0(&DAT_01216a60);
                  lVar6 = syscall(0xba);
                  FUN_002340f0((double)(fVar15 * DAT_00298548),
                               "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u %u\n","DEBUG",lVar6,
                               "dmal/common/common_pids.c",0x1f7,uVar8,uVar1,iVar5);
                }
                uVar8 = uVar8 + 1;
                puVar13 = puVar13 + 0x12;
              } while (uVar8 < local_3888[0]);
              uVar8 = (uint)uVar12;
            }
            uVar10 = uVar14;
          } while (uVar14 < local_4770);
        }
        iVar5 = 0;
        *param_7 = uVar8;
      }
    }
  }
  else if (1 < DAT_01216a78) {
    fVar15 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    fVar15 = fVar15 * DAT_00298548;
    uVar16 = 0x1d4;
    uVar11 = 0x1d4;
LAB_001a8b6b:
    FUN_002340f0((double)fVar15,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar6,
                 "dmal/common/common_pids.c",uVar11,"cGetRunningProcesses",uVar16,iVar5);
  }
  return iVar5;
}


// ===== 001a8c30 FUN_001a8c30 =====

int FUN_001a8c30(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int *param_6,char param_7)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  undefined4 *puVar12;
  undefined8 *puVar13;
  undefined8 uVar14;
  uint uVar15;
  ulong uVar16;
  float fVar17;
  undefined8 uVar18;
  int local_47bc;
  uint local_47b8;
  undefined8 local_4778;
  uint local_4770;
  uint local_3888 [2];
  undefined4 local_3880 [3604];
  
  puVar13 = &local_4778;
  for (lVar10 = 0x1dc; lVar10 != 0; lVar10 = lVar10 + -1) {
    *puVar13 = 0;
    puVar13 = puVar13 + 1;
  }
  *(undefined4 *)puVar13 = 0;
  memset(local_3888,0,0x3848);
  local_47bc = FUN_001a8690(*(undefined8 *)(param_1 + 0x10),&local_4778,param_2,param_3,param_4,
                            param_5,param_6 + 2);
  if (local_47bc == 0) {
    if (param_6[2] != 0) {
      if (*(long *)(param_6 + 4) == 0) {
        local_47bc = 2;
      }
      else {
        if (local_4770 == 0) {
          uVar15 = 0;
        }
        else {
          uVar15 = 0;
          local_47b8 = 0;
          do {
            uVar7 = local_47b8 + 200;
            uVar6 = local_4770;
            if (uVar7 <= local_4770) {
              uVar6 = uVar7;
            }
            iVar8 = FUN_001a8540(*(undefined8 *)(param_1 + 0x10),local_3888,param_2,param_3,
                                 local_47b8,uVar6);
            if (iVar8 != 0) {
              if (DAT_01216a78 < 2) {
                return iVar8;
              }
              fVar17 = (float)FUN_002917b0(&DAT_01216a60);
              lVar10 = syscall(0xba);
              fVar17 = fVar17 * DAT_00298548;
              uVar18 = 0x291;
              uVar14 = 0x291;
              local_47bc = iVar8;
              goto LAB_001a9088;
            }
            puVar12 = local_3880;
            if (local_3888[0] != 0) {
              uVar16 = (ulong)uVar15;
              uVar15 = 0;
              do {
                iVar8 = puVar12[2];
                if (iVar8 == 0) {
                  if (param_7 == '\0') {
                    lVar10 = *(long *)(puVar12 + 6) + *(long *)(puVar12 + 4);
                    lVar11 = *(long *)(puVar12 + 0xc) + *(long *)(puVar12 + 10);
                    iVar8 = *param_6;
                  }
                  else {
                    iVar8 = *param_6;
                    lVar11 = -1;
                    lVar10 = -1;
                  }
                  if (iVar8 != 0x1000018) {
                    return 0x19;
                  }
                  lVar9 = uVar16 * 0x20;
                  *(undefined4 *)(*(long *)(param_6 + 4) + lVar9) = *puVar12;
                  *(long *)(*(long *)(param_6 + 4) + 8 + lVar9) = lVar10;
                  *(undefined4 *)(*(long *)(param_6 + 4) + 0x14 + lVar9) = puVar12[0x10];
                  *(undefined4 *)(*(long *)(param_6 + 4) + 0x10 + lVar9) = puVar12[0x11];
                  *(long *)(*(long *)(param_6 + 4) + 0x18 + lVar9) = lVar11;
                  if (4 < DAT_01216a78) {
                    uVar1 = puVar12[2];
                    uVar14 = *(undefined8 *)(puVar12 + 0xc);
                    uVar18 = *(undefined8 *)(puVar12 + 10);
                    uVar3 = *(undefined8 *)(puVar12 + 8);
                    uVar4 = *(undefined8 *)(puVar12 + 6);
                    uVar5 = *(undefined8 *)(puVar12 + 4);
                    uVar2 = *puVar12;
                    fVar17 = (float)FUN_002917b0(&DAT_01216a60);
                    lVar10 = syscall(0xba);
                    FUN_002340f0((double)(fVar17 * DAT_00298548),
                                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u (%llu %llu %llu %llu %llu) %u\n"
                                 ,"DEBUG",lVar10,"dmal/common/common_pids.c",0x2c4,uVar15,uVar2,
                                 uVar5,uVar4,uVar3,uVar18,uVar14,uVar1);
                  }
                  uVar16 = (ulong)((int)uVar16 + 1);
                }
                else if (4 < DAT_01216a78) {
                  uVar1 = *puVar12;
                  fVar17 = (float)FUN_002917b0(&DAT_01216a60);
                  lVar10 = syscall(0xba);
                  FUN_002340f0((double)(fVar17 * DAT_00298548),
                               "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u %u\n","DEBUG",lVar10,
                               "dmal/common/common_pids.c",0x29c,uVar15,uVar1,iVar8);
                }
                uVar15 = uVar15 + 1;
                puVar12 = puVar12 + 0x12;
              } while (uVar15 < local_3888[0]);
              uVar15 = (uint)uVar16;
            }
            local_47b8 = uVar7;
          } while (uVar7 < local_4770);
        }
        param_6[2] = uVar15;
      }
    }
  }
  else if (1 < DAT_01216a78) {
    fVar17 = (float)FUN_002917b0(&DAT_01216a60);
    lVar10 = syscall(0xba);
    fVar17 = fVar17 * DAT_00298548;
    uVar14 = 0x27a;
    uVar18 = 0x27a;
LAB_001a9088:
    FUN_002340f0((double)fVar17,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar10,
                 "dmal/common/common_pids.c",uVar14,"cGetRunningProcessDetailList",uVar18,local_47bc
                );
  }
  return local_47bc;
}


// ===== 001a9130 FUN_001a9130 =====

int FUN_001a9130(undefined8 param_1,undefined8 param_2,undefined4 param_3,uint *param_4,long param_5
                )

{
  uint *puVar1;
  undefined8 uVar2;
  undefined4 *__ptr;
  undefined8 *puVar3;
  void *pvVar4;
  uint uVar5;
  ulong uVar6;
  int local_cc;
  char local_b8 [136];
  
  __ptr = malloc(0x18);
  if (__ptr == (undefined4 *)0x0) {
    return 0x14;
  }
  __ptr[1] = param_3;
  *__ptr = 0x1000018;
  __ptr[2] = 0;
  *(undefined8 *)(__ptr + 4) = 0;
  if (param_4 != (uint *)0x0) {
    uVar5 = *param_4;
    if (uVar5 != 0) {
      __ptr[2] = uVar5;
      pvVar4 = calloc((ulong)uVar5,0x20);
      *(void **)(__ptr + 4) = pvVar4;
      if (pvVar4 == (void *)0x0) {
        local_cc = 0x14;
        goto LAB_001a9266;
      }
    }
  }
  local_cc = FUN_001a7d00(param_1,param_2,__ptr);
  uVar5 = __ptr[2];
  *param_4 = uVar5;
  if (local_cc == 0) {
    uVar6 = 0;
    if (uVar5 != 0) {
      do {
        uVar5 = (int)uVar6 + 1;
        puVar3 = (undefined8 *)(uVar6 * 0x20 + *(long *)(__ptr + 4));
        uVar2 = puVar3[1];
        puVar1 = (uint *)(param_5 + uVar6 * 0x1020);
        *(undefined8 *)puVar1 = *puVar3;
        *(undefined8 *)(puVar1 + 2) = uVar2;
        uVar2 = puVar3[3];
        *(undefined8 *)(puVar1 + 4) = puVar3[2];
        *(undefined8 *)(puVar1 + 6) = uVar2;
        snprintf(local_b8,0x80,"/proc/%u/cmdline",(ulong)*puVar1);
        FUN_001a7f70(local_b8,puVar1 + 8,0x1000);
        uVar6 = (ulong)uVar5;
      } while (uVar5 < *param_4);
    }
  }
  if (*(void **)(__ptr + 4) != (void *)0x0) {
    free(*(void **)(__ptr + 4));
  }
LAB_001a9266:
  free(__ptr);
  return local_cc;
}


// ===== 001a92d0 FUN_001a92d0 =====

int FUN_001a92d0(undefined8 param_1,long param_2,int param_3,int *param_4,undefined4 *param_5)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  undefined8 uVar6;
  float fVar7;
  double dVar8;
  undefined8 uVar9;
  int local_40;
  int local_3c [3];
  
  if (*(int *)(param_2 + 0x71c) == 0) {
    do {
      iVar3 = FUN_00291820(param_2 + 0x720,1,0);
    } while (iVar3 != 0);
    if (*(int *)(param_2 + 0x71c) == 0) {
      lVar5 = *(long *)(param_2 + 0x256d8);
      uVar4 = 3;
      if (((lVar5 != 0) && (*(long *)(lVar5 + 0x20) != 0)) &&
         (pcVar2 = *(code **)(*(long *)(lVar5 + 0x20) + 0x98), pcVar2 != (code *)0x0)) {
        uVar4 = (*pcVar2)(lVar5,param_2,param_2 + 0x708);
      }
      *(undefined4 *)(param_2 + 0x724) = uVar4;
      *(undefined4 *)(param_2 + 0x71c) = 1;
    }
    FUN_00291830(param_2 + 0x720,0);
  }
  iVar3 = *(int *)(param_2 + 0x724);
  if (iVar3 != 0) {
    if (DAT_01216a78 < 2) {
      return iVar3;
    }
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    uVar9 = 0x7f;
    uVar6 = 0x7f;
    dVar8 = (double)(fVar7 * DAT_00298548);
    goto LAB_001a955a;
  }
  if (*(long *)(param_2 + 0x25d60) != 0) {
    *param_5 = 1;
    *param_4 = 0xa082;
    return 0;
  }
  *param_5 = 0;
  if (param_3 == 2) {
    *param_4 = 0x900e;
    return 0;
  }
  iVar1 = *(int *)(param_2 + 0x708);
  iVar3 = *(int *)(param_2 + 0x70c);
  if (iVar1 == 5) {
    if (iVar3 == 0xe0) {
      *param_4 = (-(uint)(param_3 == 0) & 0x29) + 0xa097;
      return 0;
    }
    if (iVar3 == 0xf0) {
      *param_4 = (-(uint)(param_3 == 0) & 0x29) + 0xa197;
      return 0;
    }
    if (DAT_01216a78 < 2) {
      return 3;
    }
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    uVar6 = 0xa0;
    dVar8 = (double)(fVar7 * DAT_00298548);
  }
  else {
    if (iVar1 != 6) {
      if (iVar1 == 7) {
        lVar5 = *(long *)(param_2 + 0x256d8);
        local_40 = 0;
        local_3c[0] = 0;
        if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x58) == (undefined8 *)0x0)) ||
           (pcVar2 = (code *)**(undefined8 **)(lVar5 + 0x58), pcVar2 == (code *)0x0)) {
          iVar3 = 3;
        }
        else {
          iVar3 = (*pcVar2)(lVar5,param_2,0x40,&local_40);
          if (iVar3 == 0) {
            lVar5 = *(long *)(param_2 + 0x256d8);
            if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x58) == (undefined8 *)0x0)) ||
               (pcVar2 = (code *)**(undefined8 **)(lVar5 + 0x58), pcVar2 == (code *)0x0)) {
              iVar3 = 3;
            }
            else {
              iVar3 = (*pcVar2)(lVar5,param_2,0x80,local_3c);
              if (iVar3 == 0) {
                if (local_40 != 0) {
                  *param_4 = (-(uint)(param_3 == 0) & 0x29) + 0xc097;
                  return 0;
                }
                if (local_3c[0] != 0) {
                  *param_4 = (-(uint)(param_3 == 0) & 0x29) + 0xc197;
                  return 0;
                }
                if (DAT_01216a78 < 2) {
                  return 3;
                }
                fVar7 = (float)FUN_002917b0(&DAT_01216a60);
                lVar5 = syscall(0xba);
                uVar6 = 0xcb;
                dVar8 = (double)(fVar7 * DAT_00298548);
                goto LAB_001a963c;
              }
            }
            if (DAT_01216a78 < 2) {
              return iVar3;
            }
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar5 = syscall(0xba);
            uVar9 = 0xbf;
            uVar6 = 0xbf;
            dVar8 = (double)(fVar7 * DAT_00298548);
            goto LAB_001a955a;
          }
        }
        if (DAT_01216a78 < 2) {
          return iVar3;
        }
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        uVar9 = 0xbb;
        uVar6 = 0xbb;
        dVar8 = (double)(fVar7 * DAT_00298548);
      }
      else if (iVar1 == 8) {
        lVar5 = *(long *)(param_2 + 0x256d8);
        local_40 = 0;
        local_3c[0] = 0;
        if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x58) == (undefined8 *)0x0)) ||
           (pcVar2 = (code *)**(undefined8 **)(lVar5 + 0x58), pcVar2 == (code *)0x0)) {
          iVar3 = 3;
        }
        else {
          iVar3 = (*pcVar2)(lVar5,param_2,0x100,&local_40);
          if (iVar3 == 0) {
            lVar5 = *(long *)(param_2 + 0x256d8);
            if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x58) == (undefined8 *)0x0)) ||
               (pcVar2 = (code *)**(undefined8 **)(lVar5 + 0x58), pcVar2 == (code *)0x0)) {
              iVar3 = 3;
            }
            else {
              iVar3 = (*pcVar2)(lVar5,param_2,0x200,local_3c);
              if (iVar3 == 0) {
                if (local_40 != 0) {
                  *param_4 = (-(uint)(param_3 == 0) & 0x29) + 0xc397;
                  return 0;
                }
                if (local_3c[0] != 0) {
                  *param_4 = (-(uint)(param_3 == 0) & 0x29) + 0xc497;
                  return 0;
                }
                if (DAT_01216a78 < 2) {
                  return 3;
                }
                fVar7 = (float)FUN_002917b0(&DAT_01216a60);
                lVar5 = syscall(0xba);
                uVar6 = 0xe6;
                dVar8 = (double)(fVar7 * DAT_00298548);
                goto LAB_001a963c;
              }
            }
            if (DAT_01216a78 < 2) {
              return iVar3;
            }
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar5 = syscall(0xba);
            uVar9 = 0xda;
            uVar6 = 0xda;
            dVar8 = (double)(fVar7 * DAT_00298548);
            goto LAB_001a955a;
          }
        }
        if (DAT_01216a78 < 2) {
          return iVar3;
        }
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        uVar9 = 0xd6;
        uVar6 = 0xd6;
        dVar8 = (double)(fVar7 * DAT_00298548);
      }
      else if (iVar1 == 9) {
        lVar5 = *(long *)(param_2 + 0x256d8);
        local_3c[0] = 0;
        if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x58) == (undefined8 *)0x0)) ||
           (pcVar2 = (code *)**(undefined8 **)(lVar5 + 0x58), pcVar2 == (code *)0x0)) {
          iVar3 = 3;
        }
        else {
          iVar3 = (*pcVar2)(lVar5,param_2,0x2000,local_3c);
          if (iVar3 == 0) {
            if (local_3c[0] != 0) {
              *param_4 = (-(uint)(param_3 == 0) & 0x29) + 0xc597;
              return 0;
            }
            if (DAT_01216a78 < 2) {
              return 3;
            }
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar5 = syscall(0xba);
            uVar6 = 0xf8;
            dVar8 = (double)(fVar7 * DAT_00298548);
            goto LAB_001a963c;
          }
        }
        if (DAT_01216a78 < 2) {
          return iVar3;
        }
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        uVar9 = 0xf0;
        uVar6 = 0xf0;
        dVar8 = (double)(fVar7 * DAT_00298548);
      }
      else if (iVar1 == 10) {
        lVar5 = *(long *)(param_2 + 0x256d8);
        local_40 = 0;
        local_3c[0] = 0;
        if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x58) == (undefined8 *)0x0)) ||
           (pcVar2 = (code *)**(undefined8 **)(lVar5 + 0x58), pcVar2 == (code *)0x0)) {
          iVar3 = 3;
        }
        else {
          iVar3 = (*pcVar2)(lVar5,param_2,0x4000,&local_40);
          if (iVar3 == 0) {
            lVar5 = *(long *)(param_2 + 0x256d8);
            if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x58) == (undefined8 *)0x0)) ||
               (pcVar2 = (code *)**(undefined8 **)(lVar5 + 0x58), pcVar2 == (code *)0x0)) {
              iVar3 = 3;
            }
            else {
              iVar3 = (*pcVar2)(lVar5,param_2,0x8000,local_3c);
              if (iVar3 == 0) {
                if (local_40 != 0) {
                  *param_4 = (-(uint)(param_3 == 0) & 0x29) + 0xc697;
                  return 0;
                }
                if (local_3c[0] != 0) {
                  *param_4 = (-(uint)(param_3 == 0) & 0x29) + 0xc797;
                  return 0;
                }
                if (DAT_01216a78 < 2) {
                  return 3;
                }
                fVar7 = (float)FUN_002917b0(&DAT_01216a60);
                lVar5 = syscall(0xba);
                uVar6 = 0x113;
                dVar8 = (double)(fVar7 * DAT_00298548);
                goto LAB_001a963c;
              }
            }
            if (DAT_01216a78 < 2) {
              return iVar3;
            }
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar5 = syscall(0xba);
            uVar9 = 0x107;
            uVar6 = 0x107;
            dVar8 = (double)(fVar7 * DAT_00298548);
            goto LAB_001a955a;
          }
        }
        if (DAT_01216a78 < 2) {
          return iVar3;
        }
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        uVar9 = 0x103;
        uVar6 = 0x103;
        dVar8 = (double)(fVar7 * DAT_00298548);
      }
      else if (iVar1 == 0xc) {
        lVar5 = *(long *)(param_2 + 0x256d8);
        local_40 = 0;
        local_3c[0] = 0;
        if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x58) == (undefined8 *)0x0)) ||
           (pcVar2 = (code *)**(undefined8 **)(lVar5 + 0x58), pcVar2 == (code *)0x0)) {
          iVar3 = 3;
        }
        else {
          iVar3 = (*pcVar2)(lVar5,param_2,0x10000,&local_40);
          if (iVar3 == 0) {
            lVar5 = *(long *)(param_2 + 0x256d8);
            if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x58) == (undefined8 *)0x0)) ||
               (pcVar2 = (code *)**(undefined8 **)(lVar5 + 0x58), pcVar2 == (code *)0x0)) {
              iVar3 = 3;
            }
            else {
              iVar3 = (*pcVar2)(lVar5,param_2,0x20000,local_3c);
              if (iVar3 == 0) {
                if (local_40 != 0) {
                  *param_4 = (-(uint)(param_3 == 0) & 0x29) + 0xcb97;
                  return 0;
                }
                if (local_3c[0] != 0) {
                  *param_4 = (-(uint)(param_3 == 0) & 0x29) + 0xcc97;
                  return 0;
                }
                if (DAT_01216a78 < 2) {
                  return 3;
                }
                fVar7 = (float)FUN_002917b0(&DAT_01216a60);
                lVar5 = syscall(0xba);
                uVar6 = 0x12e;
                dVar8 = (double)(fVar7 * DAT_00298548);
                goto LAB_001a963c;
              }
            }
            if (DAT_01216a78 < 2) {
              return iVar3;
            }
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar5 = syscall(0xba);
            uVar9 = 0x122;
            uVar6 = 0x122;
            dVar8 = (double)(fVar7 * DAT_00298548);
            goto LAB_001a955a;
          }
        }
        if (DAT_01216a78 < 2) {
          return iVar3;
        }
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        uVar9 = 0x11e;
        uVar6 = 0x11e;
        dVar8 = (double)(fVar7 * DAT_00298548);
      }
      else if (iVar1 == 0xb) {
        lVar5 = *(long *)(param_2 + 0x256d8);
        local_3c[0] = 0;
        if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x58) == (undefined8 *)0x0)) ||
           (pcVar2 = (code *)**(undefined8 **)(lVar5 + 0x58), pcVar2 == (code *)0x0)) {
          iVar3 = 3;
        }
        else {
          iVar3 = (*pcVar2)(lVar5,param_2,0x40000,local_3c);
          if (iVar3 == 0) {
            if (local_3c[0] != 0) {
              *param_4 = (-(uint)(param_3 == 0) & 0x29) + 0xc997;
              return 0;
            }
            if (DAT_01216a78 < 2) {
              return 3;
            }
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar5 = syscall(0xba);
            uVar6 = 0x140;
            dVar8 = (double)(fVar7 * DAT_00298548);
            goto LAB_001a963c;
          }
        }
        if (DAT_01216a78 < 2) {
          return iVar3;
        }
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        uVar9 = 0x138;
        uVar6 = 0x138;
        dVar8 = (double)(fVar7 * DAT_00298548);
      }
      else {
        iVar3 = 3;
        if (iVar1 != 0xd) {
          return 3;
        }
        lVar5 = *(long *)(param_2 + 0x256d8);
        local_40 = 0;
        local_3c[0] = 0;
        if ((((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x58) == (undefined8 *)0x0)) ||
            (pcVar2 = (code *)**(undefined8 **)(lVar5 + 0x58), pcVar2 == (code *)0x0)) ||
           (iVar3 = (*pcVar2)(lVar5,param_2,0x80000,&local_40), iVar3 != 0)) {
          if (DAT_01216a78 < 2) {
            return iVar3;
          }
          fVar7 = (float)FUN_002917b0(&DAT_01216a60);
          lVar5 = syscall(0xba);
          uVar9 = 0x14c;
          uVar6 = 0x14c;
          dVar8 = (double)(fVar7 * DAT_00298548);
          goto LAB_001a955a;
        }
        lVar5 = *(long *)(param_2 + 0x256d8);
        if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x58) == (undefined8 *)0x0)) ||
           (pcVar2 = (code *)**(undefined8 **)(lVar5 + 0x58), pcVar2 == (code *)0x0)) {
          iVar3 = 3;
        }
        else {
          iVar3 = (*pcVar2)(lVar5,param_2,0x400000,local_3c);
          if (iVar3 == 0) {
            if (local_40 != 0) {
              *param_4 = (-(uint)(param_3 == 0) & 0x29) + 0xcd97;
              return 0;
            }
            if (local_3c[0] != 0) {
              *param_4 = (-(uint)(param_3 == 0) & 0x29) + 0xce97;
              return 0;
            }
            if (DAT_01216a78 < 2) {
              return 3;
            }
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar5 = syscall(0xba);
            uVar6 = 0x15c;
            dVar8 = (double)(fVar7 * DAT_00298548);
            goto LAB_001a963c;
          }
        }
        if (DAT_01216a78 < 2) {
          return iVar3;
        }
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        uVar9 = 0x150;
        uVar6 = 0x150;
        dVar8 = (double)(fVar7 * DAT_00298548);
      }
LAB_001a955a:
      FUN_002340f0(dVar8,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,
                   "dmal/common/common_pids.c",uVar6,"cConvertNvmlProcessInfoModeToRmId",uVar9,iVar3
                  );
      return iVar3;
    }
    if (iVar3 == 0x110) {
      *param_4 = (-(uint)(param_3 == 0) & 0x29) + 0xb097;
      return 0;
    }
    if (iVar3 == 0x120) {
      *param_4 = (-(uint)(param_3 == 0) & 0x29) + 0xb197;
      return 0;
    }
    if (DAT_01216a78 < 2) {
      return 3;
    }
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    uVar6 = 0xb0;
    dVar8 = (double)(fVar7 * DAT_00298548);
  }
LAB_001a963c:
  FUN_002340f0(dVar8,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar5,
               "dmal/common/common_pids.c",uVar6);
  return 3;
}


// ===== 001aa200 FUN_001aa200 =====

int FUN_001aa200(byte *param_1,byte *param_2)

{
  int iVar1;
  
  iVar1 = 1;
  if (*param_2 <= *param_1) {
    iVar1 = -(uint)(*param_1 != *param_2);
  }
  return iVar1;
}


// ===== 001aa220 FUN_001aa220 =====

undefined2 FUN_001aa220(long param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined2 uVar2;
  undefined8 local_10;
  
  local_10 = *param_2;
  uVar1 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0x138,&local_10,8);
  uVar2 = 999;
  if (uVar1 < 0x67) {
    uVar2 = *(undefined2 *)(&DAT_002aea80 + (ulong)uVar1 * 2);
  }
  return uVar2;
}


// ===== 001aa280 FUN_001aa280 =====

undefined1  [16] FUN_001aa280(long param_1,long *param_2,long *param_3)

{
  ulong uVar1;
  long lVar2;
  undefined1 auVar3 [16];
  undefined1 local_28 [16];
  
  local_28 = (undefined1  [16])0x0;
  uVar1 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0x137,local_28,0x10
                      );
  lVar2 = 0;
  if ((uint)uVar1 < 0x67) {
    lVar2 = (long)&switchD_001aa2d9::switchdataD_002ae064 +
            (long)(int)(&switchD_001aa2d9::switchdataD_002ae064)[uVar1 & 0xffffffff];
    switch(uVar1 & 0xffffffff) {
    case 0:
      if (param_2 != (long *)0x0) {
        *param_2 = local_28._0_8_;
        lVar2 = local_28._0_8_;
      }
      if (param_3 != (long *)0x0) {
        *param_3 = local_28._8_8_;
        lVar2 = local_28._8_8_;
      }
      break;
    default:
      goto switchD_001aa2d9_caseD_1;
    case 3:
    case 0x66:
      uVar1 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      uVar1 = 0x13;
      break;
    case 0x1a:
      uVar1 = 0x17;
      break;
    case 0x1b:
      uVar1 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
      uVar1 = 2;
      break;
    case 0x51:
      uVar1 = 0x14;
      break;
    case 0x55:
      uVar1 = 0x1b;
      break;
    case 0x56:
      uVar1 = 3;
      break;
    case 0x59:
      uVar1 = 0x11;
      break;
    case 0x62:
      uVar1 = 0x10;
    }
  }
  else {
switchD_001aa2d9_caseD_1:
    uVar1 = 999;
  }
  auVar3._8_8_ = lVar2;
  auVar3._0_8_ = uVar1;
  return auVar3;
}


// ===== 001aa370 FUN_001aa370 =====

int FUN_001aa370(long param_1,long param_2,byte *param_3)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined8 uVar3;
  int iVar4;
  undefined4 *puVar5;
  long lVar6;
  ulong uVar7;
  byte *pbVar8;
  byte *pbVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  ulong __nmemb;
  byte bVar12;
  float fVar13;
  undefined4 local_e5c;
  undefined1 local_e58 [4];
  int local_e54;
  undefined8 local_e50;
  undefined1 local_e43 [7];
  undefined4 local_e3c [397];
  byte local_808 [396];
  undefined8 auStack_67c [202];
  
  bVar12 = 0;
  local_e54 = 0;
  pbVar8 = local_808;
  for (lVar6 = 0xfa; lVar6 != 0; lVar6 = lVar6 + -1) {
    pbVar8[0] = 0;
    pbVar8[1] = 0;
    pbVar8[2] = 0;
    pbVar8[3] = 0;
    pbVar8[4] = 0;
    pbVar8[5] = 0;
    pbVar8[6] = 0;
    pbVar8[7] = 0;
    pbVar8 = pbVar8 + 8;
  }
  pbVar8[0] = 0;
  pbVar8[1] = 0;
  pbVar8[2] = 0;
  pbVar8[3] = 0;
  lVar6 = *(long *)(param_2 + 0x256d8);
  if (((lVar6 == 0) || (*(long *)(lVar6 + 0x20) == 0)) ||
     (pcVar2 = *(code **)(*(long *)(lVar6 + 0x20) + 0x90), pcVar2 == (code *)0x0))
  goto switchD_001aa5cb_caseD_56;
  uVar3 = *(undefined8 *)(param_1 + 0x10);
  iVar4 = (*pcVar2)(lVar6,param_2,local_e58);
  if (((((iVar4 != 0) || (lVar6 = *(long *)(param_2 + 0x256d8), lVar6 == 0)) ||
       ((*(undefined8 **)(lVar6 + 0x48) == (undefined8 *)0x0 ||
        ((pcVar2 = (code *)**(undefined8 **)(lVar6 + 0x48), pcVar2 == (code *)0x0 ||
         (iVar4 = (*pcVar2)(lVar6,param_2,&local_e50), iVar4 != 0)))))) ||
      (lVar6 = *(long *)(param_2 + 0x256d8), lVar6 == 0)) ||
     ((((*(long *)(lVar6 + 0x78) == 0 ||
        (pcVar2 = *(code **)(*(long *)(lVar6 + 0x78) + 8), pcVar2 == (code *)0x0)) ||
       (iVar4 = (*pcVar2)(lVar6,param_2,&local_e54), iVar4 != 0)) || (local_e54 == 0))))
  goto switchD_001aa5cb_caseD_56;
  lVar6 = *(long *)(param_2 + 0x256d8);
  if (((lVar6 == 0) || (*(undefined8 **)(lVar6 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar6 + 0x50), pcVar2 == (code *)0x0)) {
    iVar4 = 3;
LAB_001aa4d3:
    if (DAT_01216a78 < 2) {
      return iVar4;
    }
    fVar13 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar13 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar6,"dmal/common/common_version.c",0x15c,"cDeviceGetBridgeChipInfo",0x15c
                 ,iVar4);
    return iVar4;
  }
  iVar4 = (*pcVar2)(lVar6,param_2,0x2080,&local_e5c);
  if (iVar4 != 0) goto LAB_001aa4d3;
  iVar4 = FUN_0019c780(uVar3,DAT_0038088c,local_e5c,0x2080015b,local_808,0x7d4,0);
  switch(iVar4) {
  case 0:
    __nmemb = (ulong)local_808[0];
    if (local_808[0] != 0) {
      (&local_e50)[__nmemb * 2] = auStack_67c[__nmemb * 2];
      puVar10 = auStack_67c + 1;
      puVar11 = (undefined8 *)&stack0xfffffffffffff1b8;
      for (uVar7 = (ulong)((uint)local_808[0] * 0x10 - 1 >> 3); uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar11 = *puVar10;
        puVar10 = puVar10 + (ulong)bVar12 * -2 + 1;
        puVar11 = puVar11 + (ulong)bVar12 * -2 + 1;
      }
      qsort(&stack0xfffffffffffff1b8,__nmemb,0x10,FUN_001aa200);
      *param_3 = local_808[0];
      puVar5 = local_e3c;
      pbVar8 = param_3 + 4;
      do {
        switch(*(undefined1 *)((long)puVar5 + -7)) {
        default:
          goto switchD_001aa5cb_caseD_1;
        case 1:
        case 3:
        case 4:
        case 6:
        case 7:
          goto switchD_001aa5cb_caseD_56;
        case 5:
          pbVar8[0] = 1;
          pbVar8[1] = 0;
          pbVar8[2] = 0;
          pbVar8[3] = 0;
          break;
        case 8:
          pbVar8[0] = 0;
          pbVar8[1] = 0;
          pbVar8[2] = 0;
          pbVar8[3] = 0;
        }
        uVar1 = *puVar5;
        pbVar9 = pbVar8 + 8;
        puVar5 = puVar5 + 4;
        *(undefined4 *)(pbVar8 + 4) = uVar1;
        pbVar8 = pbVar9;
        if (param_3 + (ulong)(local_808[0] - 1) * 8 + 0xc == pbVar9) {
          return iVar4;
        }
      } while( true );
    }
  case 0x56:
switchD_001aa5cb_caseD_56:
    iVar4 = 3;
    break;
  default:
switchD_001aa5cb_caseD_1:
    iVar4 = 999;
    break;
  case 3:
  case 0x66:
    iVar4 = 10;
    break;
  case 0xf:
    break;
  case 0x17:
  case 99:
    iVar4 = 0x13;
    break;
  case 0x1a:
    iVar4 = 0x17;
    break;
  case 0x1b:
    iVar4 = 4;
    break;
  case 0x1f:
  case 0x3b:
  case 0x54:
    iVar4 = 2;
    break;
  case 0x51:
    iVar4 = 0x14;
    break;
  case 0x55:
    iVar4 = 0x1b;
    break;
  case 0x59:
    iVar4 = 0x11;
    break;
  case 0x62:
    iVar4 = 0x10;
  }
  return iVar4;
}


// ===== 001aa700 FUN_001aa700 =====

int FUN_001aa700(long param_1,long param_2,char *param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  int iVar5;
  long lVar6;
  float fVar7;
  undefined4 local_4c;
  undefined1 local_48 [16];
  undefined1 local_38 [16];
  
  lVar6 = *(long *)(param_2 + 0x256d8);
  local_48 = (undefined1  [16])0x0;
  local_38 = (undefined1  [16])0x0;
  if (((lVar6 == 0) || (*(undefined8 **)(lVar6 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar6 + 0x50), pcVar1 == (code *)0x0)) {
    iVar5 = 3;
  }
  else {
    uVar2 = *(undefined8 *)(param_1 + 0x10);
    iVar5 = (*pcVar1)(lVar6,param_2,0x2080,&local_4c);
    auVar3 = local_38;
    if (iVar5 == 0) {
      local_48._8_8_ = local_38;
      local_38._0_4_ = 1;
      auVar4 = local_38;
      local_38._12_4_ = auVar3._12_4_;
      local_38._0_8_ = auVar4._0_8_;
      local_38._8_4_ = 0;
      local_48._0_4_ = 2;
      iVar5 = FUN_0019c780(uVar2,DAT_0038088c,local_4c,0x20800802,local_48,0x10,0);
      switch(iVar5) {
      case 0:
        sprintf(param_3,"%02X.%02X.%02X.%02X.%02X",(ulong)((uint)local_38._12_4_ >> 0x18),
                (ulong)((uint)local_38._12_4_ >> 0x10 & 0xff),
                (ulong)((uint)local_38._12_4_ >> 8 & 0xff),(ulong)(local_38._12_4_ & 0xff),
                (ulong)local_38[4]);
        return iVar5;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar5;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar5;
  }
  fVar7 = (float)FUN_002917b0(&DAT_01216a60);
  lVar6 = syscall(0xba);
  FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar6,"dmal/common/common_version.c",0xf3,"cDeviceGetVbiosVersion",0xf3,iVar5
              );
  return iVar5;
}


// ===== 001aa950 FUN_001aa950 =====

int FUN_001aa950(long param_1,long param_2,char *param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  undefined4 local_3c;
  undefined1 local_38 [16];
  
  lVar4 = *(long *)(param_2 + 0x256d8);
  local_38 = (undefined1  [16])0x0;
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    uVar2 = *(undefined8 *)(param_1 + 0x10);
    iVar3 = (*pcVar1)(lVar4,param_2,0x2080,&local_3c);
    if (iVar3 == 0) {
      iVar3 = FUN_0019c780(uVar2,DAT_0038088c,local_3c,0x20800156,local_38,0x10,0);
      switch(iVar3) {
      case 0:
        if (4 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n",
                       "DEBUG",lVar4,"dmal/common/common_version.c",0x2c,local_38);
        }
        if (local_38[0] != '\0') {
          strcpy(param_3,local_38);
          return iVar3;
        }
switchD_001aaa84_caseD_56:
        return 3;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar3;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        goto switchD_001aaa84_caseD_56;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (1 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_version.c",0x25,"cDeviceGetInforomImageVersion",
                 0x25,iVar3);
  }
  return iVar3;
}


// ===== 001aabb0 FUN_001aabb0 =====

int FUN_001aabb0(long param_1,long param_2,int param_3,char *param_4)

{
  char *pcVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  code *pcVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  ulong uVar9;
  long lVar10;
  int *piVar11;
  undefined8 uVar12;
  uint *puVar13;
  char *__dest;
  float fVar14;
  undefined8 uVar15;
  undefined4 local_64;
  undefined4 local_5d;
  char local_59;
  uint local_54 [9];
  
  if (4 < DAT_01216a78) {
    fVar14 = (float)FUN_002917b0(&DAT_01216a60);
    lVar10 = syscall(0xba);
    FUN_002340f0((double)(fVar14 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","DEBUG",
                 lVar10,"dmal/common/common_version.c",200,param_3);
  }
  if (*(int *)(param_2 + 0x5f4) != 0) goto LAB_001aac2f;
  pcVar1 = (char *)(param_2 + 0x5f8);
  do {
    iVar7 = FUN_00291820(pcVar1,1,0);
  } while (iVar7 != 0);
  if (*(int *)(param_2 + 0x5f4) == 0) {
    local_54[0] = 1;
    local_54[1] = 2;
    local_54[2] = 100;
    local_54[3] = 0x65;
    local_54[4] = 0x66;
    local_54[5] = 3;
    puVar13 = local_54;
    __dest = (char *)(param_2 + 0x588);
    *(undefined4 *)(param_2 + 0x600) = 0;
    uVar8 = 0;
    do {
      lVar10 = *(long *)(param_2 + 0x256d8);
      local_5d = 0;
      local_59 = '\0';
      uVar12 = *(undefined8 *)(param_1 + 0x10);
      if (((lVar10 == 0) || (*(undefined8 **)(lVar10 + 0x50) == (undefined8 *)0x0)) ||
         (pcVar4 = (code *)**(undefined8 **)(lVar10 + 0x50), pcVar4 == (code *)0x0)) {
        iVar7 = 3;
LAB_001aaed6:
        if (1 < DAT_01216a78) {
          fVar14 = (float)FUN_002917b0(&DAT_01216a60);
          lVar10 = syscall(0xba);
          fVar14 = fVar14 * DAT_00298548;
          uVar12 = 0x4a;
          uVar15 = 0x4a;
LAB_001aafd4:
          FUN_002340f0((double)fVar14,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar10
                       ,"dmal/common/common_version.c",uVar12,"cGetInforomObjVersion",uVar15,iVar7);
        }
LAB_001aaee6:
        *(uint *)(__dest + -4) = uVar8;
        *(int *)(__dest + 8) = iVar7;
        goto LAB_001aaeee;
      }
      iVar7 = (*pcVar4)(lVar10,param_2,0x2080,&local_64);
      if (iVar7 != 0) goto LAB_001aaed6;
      if (uVar8 == 3) {
        lVar10 = *(long *)(param_2 + 0x256d8);
        if (((lVar10 != 0) && (*(long *)(lVar10 + 0x68) != 0)) &&
           (pcVar4 = *(code **)(*(long *)(lVar10 + 0x68) + 0x38), pcVar4 != (code *)0x0)) {
          iVar7 = (*pcVar4)(lVar10,param_2);
          if (iVar7 != 0) goto LAB_001ab036;
          local_5d = CONCAT13(local_5d._3_1_,0x4e0000);
          local_5d = CONCAT22(local_5d._2_2_,0x4544);
          goto LAB_001aae58;
        }
LAB_001ab235:
        iVar7 = 3;
LAB_001ab036:
        if (1 < DAT_01216a78) {
          fVar14 = (float)FUN_002917b0(&DAT_01216a60);
          lVar10 = syscall(0xba);
          fVar14 = fVar14 * DAT_00298548;
          uVar12 = 0x76;
          uVar15 = 0x76;
          goto LAB_001aafd4;
        }
        goto LAB_001aaee6;
      }
      if (uVar8 < 4) {
        if (uVar8 == 1) {
          lVar10 = *(long *)(param_2 + 0x256d8);
          if (((lVar10 == 0) || (*(undefined8 **)(lVar10 + 0x140) == (undefined8 *)0x0)) ||
             (pcVar4 = (code *)**(undefined8 **)(lVar10 + 0x140), pcVar4 == (code *)0x0))
          goto LAB_001ab235;
          iVar7 = (*pcVar4)(lVar10,param_2);
          if (iVar7 != 0) goto LAB_001ab036;
          local_5d = CONCAT13(local_5d._3_1_,0x430000);
          local_5d = CONCAT22(local_5d._2_2_,0x4345);
        }
        else if (uVar8 == 2) {
          local_5d = CONCAT13(local_5d._3_1_,0x520000);
          local_5d = CONCAT22(local_5d._2_2_,0x5750);
        }
        else {
          if (uVar8 != 0) {
LAB_001ab030:
            iVar7 = 2;
            goto LAB_001ab036;
          }
          local_5d = CONCAT13(local_5d._3_1_,0x440000);
          local_5d = CONCAT22(local_5d._2_2_,0x424f);
        }
      }
      else if (uVar8 == 0x65) {
        local_5d = CONCAT13(local_5d._3_1_,0x4e0000);
        local_5d = CONCAT22(local_5d._2_2_,0x4545);
      }
      else if (uVar8 == 0x66) {
        local_5d = CONCAT13(local_5d._3_1_,0x4c0000);
        local_5d = CONCAT22(local_5d._2_2_,0x4250);
      }
      else {
        if (uVar8 != 100) goto LAB_001ab030;
        local_5d = CONCAT13(local_5d._3_1_,0x470000);
        local_5d = CONCAT22(local_5d._2_2_,0x4643);
      }
LAB_001aae58:
      if (4 < DAT_01216a78) {
        fVar14 = (float)FUN_002917b0(&DAT_01216a60);
        lVar10 = syscall(0xba);
        FUN_002340f0((double)(fVar14 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n",
                     "DEBUG",lVar10,"dmal/common/common_version.c",0x78,&local_5d);
      }
      iVar7 = FUN_0019c780(uVar12,DAT_0038088c,local_64,0x2080014b,&local_5d,5,0);
      cVar6 = local_59;
      if (iVar7 == 0x57) {
switchD_001aaec6_caseD_56:
        *(uint *)(__dest + -4) = uVar8;
        __dest[8] = '\x03';
        __dest[9] = '\0';
        __dest[10] = '\0';
        __dest[0xb] = '\0';
        goto LAB_001aaeee;
      }
      switch(iVar7) {
      case 0:
        cVar5 = local_5d._3_1_;
        strncpy(__dest,(char *)&local_5d,3);
        if (DAT_01216a78 < 5) {
          *(uint *)(__dest + -4) = uVar8;
          __dest[8] = '\0';
          __dest[9] = '\0';
          __dest[10] = '\0';
          __dest[0xb] = '\0';
        }
        else {
          fVar14 = (float)FUN_002917b0(&DAT_01216a60);
          lVar10 = syscall(0xba);
          FUN_002340f0((double)(fVar14 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u\n",
                       "DEBUG",lVar10,"dmal/common/common_version.c",0x86,cVar5,cVar6);
          *(uint *)(__dest + -4) = uVar8;
          __dest[8] = '\0';
          __dest[9] = '\0';
          __dest[10] = '\0';
          __dest[0xb] = '\0';
        }
        __dest[3] = cVar5;
        __dest[4] = cVar6;
        goto LAB_001aaef8;
      default:
        *(uint *)(__dest + -4) = uVar8;
        __dest[8] = -0x19;
        __dest[9] = '\x03';
        __dest[10] = '\0';
        __dest[0xb] = '\0';
        break;
      case 3:
      case 0x66:
        *(uint *)(__dest + -4) = uVar8;
        __dest[8] = '\n';
        __dest[9] = '\0';
        __dest[10] = '\0';
        __dest[0xb] = '\0';
        break;
      case 0xf:
        *(uint *)(__dest + -4) = uVar8;
        __dest[8] = '\x0f';
        __dest[9] = '\0';
        __dest[10] = '\0';
        __dest[0xb] = '\0';
        break;
      case 0x17:
      case 99:
        *(uint *)(__dest + -4) = uVar8;
        __dest[8] = '\x13';
        __dest[9] = '\0';
        __dest[10] = '\0';
        __dest[0xb] = '\0';
        break;
      case 0x1a:
        *(uint *)(__dest + -4) = uVar8;
        __dest[8] = '\x17';
        __dest[9] = '\0';
        __dest[10] = '\0';
        __dest[0xb] = '\0';
        break;
      case 0x1b:
        *(uint *)(__dest + -4) = uVar8;
        __dest[8] = '\x04';
        __dest[9] = '\0';
        __dest[10] = '\0';
        __dest[0xb] = '\0';
        break;
      case 0x1f:
      case 0x3b:
      case 0x54:
        *(uint *)(__dest + -4) = uVar8;
        __dest[8] = '\x02';
        __dest[9] = '\0';
        __dest[10] = '\0';
        __dest[0xb] = '\0';
        break;
      case 0x51:
        *(uint *)(__dest + -4) = uVar8;
        __dest[8] = '\x14';
        __dest[9] = '\0';
        __dest[10] = '\0';
        __dest[0xb] = '\0';
        break;
      case 0x55:
        *(uint *)(__dest + -4) = uVar8;
        __dest[8] = '\x1b';
        __dest[9] = '\0';
        __dest[10] = '\0';
        __dest[0xb] = '\0';
        break;
      case 0x56:
        goto switchD_001aaec6_caseD_56;
      case 0x59:
        *(uint *)(__dest + -4) = uVar8;
        __dest[8] = '\x11';
        __dest[9] = '\0';
        __dest[10] = '\0';
        __dest[0xb] = '\0';
        break;
      case 0x62:
        *(uint *)(__dest + -4) = uVar8;
        __dest[8] = '\x10';
        __dest[9] = '\0';
        __dest[10] = '\0';
        __dest[0xb] = '\0';
      }
LAB_001aaeee:
      __dest[3] = '\0';
      __dest[4] = '\0';
LAB_001aaef8:
      __dest = __dest + 0x10;
      if (pcVar1 == __dest) goto LAB_001ab000;
      uVar8 = *puVar13;
      puVar13 = puVar13 + 1;
    } while( true );
  }
LAB_001aac1d:
  FUN_00291830(pcVar1,0);
LAB_001aac2f:
  iVar7 = *(int *)(param_2 + 0x5fc);
  if (iVar7 == 0) {
    piVar11 = (int *)(param_2 + 0x584);
    uVar9 = 0;
    if (*(uint *)(param_2 + 0x600) != 0) {
      do {
        if (*piVar11 == param_3) {
          iVar7 = *(int *)(param_2 + uVar9 * 0x10 + 0x590);
          if (iVar7 != 0) {
            return iVar7;
          }
          snprintf(param_4,0x10,"%u.%u",(ulong)*(byte *)(param_2 + uVar9 * 0x10 + 0x58b),
                   (ulong)*(byte *)(param_2 + uVar9 * 0x10 + 0x58c));
          if (DAT_01216a78 < 5) {
            return 0;
          }
          uVar2 = *(undefined1 *)(param_2 + uVar9 * 0x10 + 0x58c);
          uVar3 = *(undefined1 *)(param_2 + uVar9 * 0x10 + 0x58b);
          fVar14 = (float)FUN_002917b0(&DAT_01216a60);
          lVar10 = syscall(0xba);
          FUN_002340f0((double)(fVar14 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u\n",
                       "DEBUG",lVar10,"dmal/common/common_version.c",0xde,uVar3,uVar2);
          return 0;
        }
        uVar8 = (int)uVar9 + 1;
        uVar9 = (ulong)uVar8;
        piVar11 = piVar11 + 4;
      } while (uVar8 != *(uint *)(param_2 + 0x600));
    }
  }
  else if (1 < DAT_01216a78) {
    fVar14 = (float)FUN_002917b0(&DAT_01216a60);
    lVar10 = syscall(0xba);
    FUN_002340f0((double)(fVar14 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar10,"dmal/common/common_version.c",0xcd,"cDeviceGetInforomVersion",0xcd,
                 iVar7);
  }
  return iVar7;
LAB_001ab000:
  *(undefined4 *)(param_2 + 0x5f4) = 1;
  *(undefined8 *)(param_2 + 0x5fc) = 0x700000000;
  goto LAB_001aac1d;
}


// ===== 001ab420 FUN_001ab420 =====

int FUN_001ab420(long param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  float fVar4;
  undefined4 local_30;
  undefined4 local_2c;
  
  if (*(int *)(param_2 + 0x2c) == 0) {
    do {
      iVar1 = FUN_00291820(param_2 + 0x30,1,0);
    } while (iVar1 != 0);
    if (*(int *)(param_2 + 0x2c) == 0) {
      local_2c = 0;
      local_30 = *(undefined4 *)(param_2 + 0x256e0);
      uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0x3d07,
                           &local_30,8,0);
      switch(uVar2) {
      case 0:
        *(undefined4 *)(param_2 + 0x28) = local_2c;
        break;
      default:
        uVar2 = 999;
        break;
      case 3:
      case 0x66:
        uVar2 = 10;
        break;
      case 0xf:
        break;
      case 0x17:
      case 99:
        uVar2 = 0x13;
        break;
      case 0x1a:
        uVar2 = 0x17;
        break;
      case 0x1b:
        uVar2 = 4;
        break;
      case 0x1f:
      case 0x3b:
      case 0x54:
        uVar2 = 2;
        break;
      case 0x51:
        uVar2 = 0x14;
        break;
      case 0x55:
        uVar2 = 0x1b;
        break;
      case 0x56:
        uVar2 = 3;
        break;
      case 0x59:
        uVar2 = 0x11;
        break;
      case 0x62:
        uVar2 = 0x10;
      }
      *(undefined4 *)(param_2 + 0x34) = uVar2;
      *(undefined4 *)(param_2 + 0x2c) = 1;
    }
    FUN_00291830(param_2 + 0x30,0);
  }
  iVar1 = *(int *)(param_2 + 0x34);
  if (iVar1 == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x28);
  }
  else if (1 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar3,"dmal/common/common_version.c",0x1b7,"cDeviceGetMinorNumber",0x1b7,
                 iVar1);
    return iVar1;
  }
  return iVar1;
}


// ===== 001ab5f0 FUN_001ab5f0 =====

undefined1  [16]
FUN_001ab5f0(long param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined4 *param_5,undefined4 *param_6,undefined4 *param_7,undefined4 *param_8)

{
  ulong uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined1 auStack_3c [12];
  undefined4 local_30;
  
  auStack_3c = SUB1612((undefined1  [16])0x0,4);
  local_40 = *param_4;
  auVar3 = _local_40;
  _local_40 = auVar3._0_8_;
  auStack_3c._4_4_ = *param_6;
  local_30 = 0;
  local_48 = param_2;
  local_44 = param_3;
  uVar1 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0x605,&local_48,
                       0x1c);
  auVar3._8_8_ = (undefined4 *)0x0;
  if ((uint)uVar1 == 0x1f) {
switchD_001ab66b_caseD_56:
    uVar1 = 3;
    goto switchD_001ab66b_caseD_f;
  }
  if ((uint)uVar1 < 0x67) {
    auVar3._8_8_ = (undefined4 *)
                   ((long)&switchD_001ab66b::switchdataD_002aec08 +
                   (long)(int)(&switchD_001ab66b::switchdataD_002aec08)[uVar1 & 0xffffffff]);
    switch(uVar1 & 0xffffffff) {
    case 0:
      *param_4 = local_40;
      *param_5 = auStack_3c._0_4_;
      *param_6 = auStack_3c._4_4_;
      *param_7 = auStack_3c._8_4_;
      *param_8 = local_30;
      auVar3._8_8_ = param_8;
      break;
    default:
      goto switchD_001ab66b_caseD_1;
    case 3:
    case 0x66:
      uVar1 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      uVar1 = 0x13;
      break;
    case 0x1a:
      uVar1 = 0x17;
      break;
    case 0x1b:
      uVar1 = 4;
      break;
    case 0x3b:
    case 0x54:
      auVar3._0_8_ = 2;
      return auVar3;
    case 0x51:
      uVar1 = 0x14;
      break;
    case 0x55:
      uVar1 = 0x1b;
      break;
    case 0x56:
      goto switchD_001ab66b_caseD_56;
    case 0x59:
      uVar1 = 0x11;
      break;
    case 0x62:
      uVar1 = 0x10;
    }
  }
  else {
switchD_001ab66b_caseD_1:
    uVar1 = 999;
  }
switchD_001ab66b_caseD_f:
  auVar2._8_8_ = auVar3._8_8_;
  auVar2._0_8_ = uVar1;
  return auVar2;
}


// ===== 001ab720 FUN_001ab720 =====

int FUN_001ab720(long param_1,undefined4 param_2,undefined4 *param_3,undefined8 *param_4,
                undefined8 param_5,undefined4 *param_6,undefined8 *param_7,undefined8 param_8,
                void *param_9)

{
  int iVar1;
  void *pvVar2;
  undefined4 local_3c68;
  undefined4 local_3c64;
  undefined8 local_3c60;
  undefined8 uStack_3c58;
  undefined4 local_3c50;
  undefined8 local_3c4c;
  undefined8 uStack_3c44;
  undefined1 local_3c3c [15372];
  
  pvVar2 = memset(&local_3c68,0,0x3c2c);
  local_3c68 = param_2;
  iVar1 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0x604,pvVar2,0x3c2c
                       ,0);
  if (iVar1 == 0x1f) {
switchD_001ab7ab_caseD_56:
    iVar1 = 3;
  }
  else {
    switch(iVar1) {
    case 0:
      *param_4 = local_3c60;
      param_4[1] = uStack_3c58;
      *param_7 = local_3c4c;
      param_7[1] = uStack_3c44;
      memcpy(param_9,local_3c3c,0x3c00);
      *param_3 = local_3c64;
      *param_6 = local_3c50;
      break;
    default:
      iVar1 = 999;
      break;
    case 3:
    case 0x66:
      iVar1 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      iVar1 = 0x13;
      break;
    case 0x1a:
      iVar1 = 0x17;
      break;
    case 0x1b:
      iVar1 = 4;
      break;
    case 0x3b:
    case 0x54:
      iVar1 = 2;
      break;
    case 0x51:
      iVar1 = 0x14;
      break;
    case 0x55:
      iVar1 = 0x1b;
      break;
    case 0x56:
      goto switchD_001ab7ab_caseD_56;
    case 0x59:
      iVar1 = 0x11;
      break;
    case 0x62:
      iVar1 = 0x10;
    }
  }
  return iVar1;
}


// ===== 001ab890 FUN_001ab890 =====

int FUN_001ab890(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,void *param_5
                ,uint *param_6)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 local_fd8;
  undefined4 local_fd0;
  uint local_fcc;
  undefined1 local_fc8 [4000];
  
  puVar4 = &local_fd8;
  for (lVar3 = 0x1f6; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_fcc = *param_6;
  local_fd8._0_4_ = param_2;
  local_fd8._4_4_ = param_3;
  local_fd0 = param_4;
  iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0x606,&local_fd8,
                       0xfb0,0);
  uVar1 = local_fcc;
  if (iVar2 == 0x1f) {
switchD_001ab926_caseD_56:
    iVar2 = 3;
  }
  else {
    switch(iVar2) {
    case 0:
      if (*param_6 < local_fcc) {
        iVar2 = 7;
      }
      else {
        memcpy(param_5,local_fc8,(ulong)local_fcc);
        *param_6 = uVar1;
      }
      break;
    default:
      iVar2 = 999;
      break;
    case 3:
    case 0x66:
      iVar2 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      iVar2 = 0x13;
      break;
    case 0x1a:
      iVar2 = 0x17;
      break;
    case 0x1b:
      iVar2 = 4;
      break;
    case 0x3b:
    case 0x54:
      return 2;
    case 0x51:
      iVar2 = 0x14;
      break;
    case 0x55:
      iVar2 = 0x1b;
      break;
    case 0x56:
      goto switchD_001ab926_caseD_56;
    case 0x59:
      iVar2 = 0x11;
      break;
    case 0x62:
      iVar2 = 0x10;
    }
  }
  return iVar2;
}


// ===== 001aba10 FUN_001aba10 =====

int FUN_001aba10(undefined8 param_1,long param_2,undefined4 param_3,undefined4 *param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  undefined4 local_34;
  undefined8 local_30;
  
  lVar3 = *(long *)(param_2 + 0x256d8);
  local_30 = 0;
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_34);
    if (iVar2 == 0) {
      local_30._0_4_ = param_3;
      iVar2 = FUN_0019c780(param_1,DAT_0038088c,local_34,0x20802401,&local_30,8,0);
      if (iVar2 != 0x1f) {
        switch(iVar2) {
        case 0:
          *param_4 = local_30._4_4_;
          return iVar2;
        default:
          return 999;
        case 3:
        case 0x66:
          return 10;
        case 0xf:
          return iVar2;
        case 0x17:
        case 99:
          return 0x13;
        case 0x1a:
          return 0x17;
        case 0x1b:
          return 4;
        case 0x3b:
        case 0x54:
          return 2;
        case 0x51:
          return 0x14;
        case 0x55:
          return 0x1b;
        case 0x56:
          break;
        case 0x59:
          return 0x11;
        case 0x62:
          return 0x10;
        }
      }
      return 3;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_capture_buffer.c",0x2b,
               "cGetDeviceCaptureBufferSizeInternal",0x2b,iVar2);
  return iVar2;
}


// ===== 001abc10 FUN_001abc10 =====

int FUN_001abc10(long param_1,long param_2,undefined4 param_3,undefined8 param_4,uint *param_5)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  float fVar6;
  undefined8 uVar7;
  undefined4 local_50;
  uint local_4c;
  undefined1 local_48 [16];
  
  lVar4 = *(long *)(param_2 + 0x256d8);
  local_48 = (undefined1  [16])0x0;
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
joined_r0x001abd90:
    if (DAT_01216a78 < 2) {
      return iVar3;
    }
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    fVar6 = fVar6 * DAT_00298548;
    uVar7 = 0x4e;
    uVar5 = 0x4e;
LAB_001abcf2:
    FUN_002340f0((double)fVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
                 "dmal/common/common_capture_buffer.c",uVar5,"cDeviceGetCaptureBuffer",uVar7,iVar3);
  }
  else {
    uVar5 = *(undefined8 *)(param_1 + 0x10);
    uVar1 = *param_5;
    iVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_50);
    if (iVar3 != 0) goto joined_r0x001abd90;
    local_48._8_4_ = param_3;
    local_48._12_4_ = uVar1;
    local_48._0_8_ = param_4;
    iVar3 = FUN_0019c780(uVar5,DAT_0038088c,local_50,0x20802402,local_48,0x10,0);
    if (iVar3 == 0x1f) {
switchD_001abd77_caseD_f:
      return 3;
    }
    switch(iVar3) {
    case 0:
      iVar3 = FUN_001aba10(*(undefined8 *)(param_1 + 0x10),param_2,param_3,&local_4c);
      if (iVar3 == 0) {
        if (local_4c <= uVar1) {
          *param_5 = local_48._12_4_;
          return 0;
        }
        return 7;
      }
      if (DAT_01216a78 < 2) {
        return iVar3;
      }
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      fVar6 = fVar6 * DAT_00298548;
      uVar7 = 0x60;
      uVar5 = 0x60;
      goto LAB_001abcf2;
    default:
      iVar3 = 999;
      break;
    case 3:
    case 0x66:
      iVar3 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      iVar3 = 0x13;
      break;
    case 0x1a:
      iVar3 = 0x17;
      break;
    case 0x1b:
      iVar3 = 4;
      break;
    case 0x3b:
    case 0x54:
      iVar3 = 2;
      break;
    case 0x51:
      iVar3 = 0x14;
      break;
    case 0x55:
      iVar3 = 0x1b;
      break;
    case 0x56:
      goto switchD_001abd77_caseD_f;
    case 0x59:
      iVar3 = 0x11;
      break;
    case 0x62:
      iVar3 = 0x10;
    }
  }
  return iVar3;
}


// ===== 001abec0 FUN_001abec0 =====

int FUN_001abec0(long param_1,undefined8 param_2,undefined8 param_3,uint *param_4)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  iVar1 = FUN_001aba10(*(undefined8 *)(param_1 + 0x10));
  if (iVar1 == 0) {
    *param_4 = *param_4 + 0x20 + *param_4 / 10;
  }
  else if (1 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar2,"dmal/common/common_capture_buffer.c",0xaf,
                 "cDeviceGetCaptureBufferSize",0xaf,iVar1);
    return iVar1;
  }
  return iVar1;
}


// ===== 001abf90 FUN_001abf90 =====

undefined1  [16] FUN_001abf90(undefined8 param_1,undefined4 param_2,uint *param_3)

{
  ulong uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined4 local_20;
  uint local_1c;
  
  local_1c = 0;
  local_20 = param_2;
  uVar1 = FUN_0019c780(param_1,DAT_0038088c,DAT_0038088c,0x601,&local_20,8);
  auVar3._8_8_ = 0;
  if ((uint)uVar1 == 0x1f) {
switchD_001abfe7_caseD_56:
    uVar1 = 3;
    goto switchD_001abfe7_caseD_f;
  }
  if ((uint)uVar1 < 0x67) {
    auVar3._8_8_ = (long)&switchD_001abfe7::switchdataD_002af43c +
                   (long)(int)(&switchD_001abfe7::switchdataD_002af43c)[uVar1 & 0xffffffff];
    switch(uVar1 & 0xffffffff) {
    case 0:
      auVar3._8_8_ = (ulong)local_1c;
      *param_3 = local_1c;
      break;
    default:
      goto switchD_001abfe7_caseD_1;
    case 3:
    case 0x66:
      uVar1 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      uVar1 = 0x13;
      break;
    case 0x1a:
      uVar1 = 0x17;
      break;
    case 0x1b:
      uVar1 = 4;
      break;
    case 0x3b:
    case 0x54:
      auVar3._0_8_ = 2;
      return auVar3;
    case 0x51:
      uVar1 = 0x14;
      break;
    case 0x55:
      uVar1 = 0x1b;
      break;
    case 0x56:
      goto switchD_001abfe7_caseD_56;
    case 0x59:
      uVar1 = 0x11;
      break;
    case 0x62:
      uVar1 = 0x10;
    }
  }
  else {
switchD_001abfe7_caseD_1:
    uVar1 = 999;
  }
switchD_001abfe7_caseD_f:
  auVar2._8_8_ = auVar3._8_8_;
  auVar2._0_8_ = uVar1;
  return auVar2;
}


// ===== 001ac070 FUN_001ac070 =====

int FUN_001ac070(long param_1,undefined4 param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  uint local_4c;
  undefined8 local_48;
  undefined4 local_40;
  uint local_3c;
  
  uVar1 = *param_4;
  local_48 = param_3;
  local_40 = param_2;
  local_3c = uVar1;
  iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0x602,&local_48,
                       0x10,0);
  switch(iVar2) {
  case 0:
    iVar2 = FUN_001abf90(*(undefined8 *)(param_1 + 0x10),param_2,&local_4c);
    if (iVar2 == 0) {
      if (uVar1 < local_4c) {
        iVar2 = 7;
      }
      else {
        *param_4 = local_3c;
      }
    }
    else if (1 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar3,"dmal/common/common_capture_buffer.c",0x88,
                   "cSystemGetCaptureBuffer",0x88,iVar2);
    }
    break;
  default:
    iVar2 = 999;
    break;
  case 3:
  case 0x66:
    iVar2 = 10;
    break;
  case 0xf:
    break;
  case 0x17:
  case 99:
    iVar2 = 0x13;
    break;
  case 0x1a:
    iVar2 = 0x17;
    break;
  case 0x1b:
    iVar2 = 4;
    break;
  case 0x1f:
  case 0x3b:
  case 0x54:
    iVar2 = 2;
    break;
  case 0x51:
    iVar2 = 0x14;
    break;
  case 0x55:
    iVar2 = 0x1b;
    break;
  case 0x56:
    iVar2 = 3;
    break;
  case 0x59:
    iVar2 = 0x11;
    break;
  case 0x62:
    iVar2 = 0x10;
  }
  return iVar2;
}


// ===== 001ac230 FUN_001ac230 =====

int FUN_001ac230(long param_1,undefined8 param_2,uint *param_3)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  iVar1 = FUN_001abf90(*(undefined8 *)(param_1 + 0x10));
  if (iVar1 == 0) {
    *param_3 = *param_3 + 0x20 + *param_3 / 10;
  }
  else if (1 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar2,"dmal/common/common_capture_buffer.c",0x9e,
                 "cSystemGetCaptureBufferSize",0x9e,iVar1);
    return iVar1;
  }
  return iVar1;
}


// ===== 001ac300 FUN_001ac300 =====

uint FUN_001ac300(long param_1)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  undefined4 local_2c [3];
  
  uVar2 = 3;
  if (DAT_01214898 != 0) {
    if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x20) != 0)) &&
       (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0xb8), pcVar1 != (code *)0x0)) {
      uVar4 = *(undefined8 *)(param_1 + 0x10);
      uVar2 = (*pcVar1)(DAT_012164a0,&DAT_00380898);
      if (uVar2 == 0) {
        if (((DAT_003a5f70 == 0) || (*(undefined8 **)(DAT_003a5f70 + 0x50) == (undefined8 *)0x0)) ||
           (pcVar1 = (code *)**(undefined8 **)(DAT_003a5f70 + 0x50), pcVar1 == (code *)0x0)) {
          uVar2 = 3;
        }
        else {
          uVar2 = (*pcVar1)(DAT_003a5f70,&DAT_00380898,0x2080,local_2c);
          if (uVar2 == 0) {
            uVar2 = FUN_0019c780(uVar4,DAT_0038088c,local_2c[0],0x20802207,0,0,0);
            if (0x66 < uVar2) {
              return 999;
            }
            return (uint)*(ushort *)(&DAT_002afc00 + (ulong)uVar2 * 2);
          }
        }
        if (DAT_01216a78 < 2) {
          return uVar2;
        }
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        fVar5 = fVar5 * DAT_00298548;
        uVar6 = 0x155;
        uVar4 = 0x155;
        goto LAB_001ac451;
      }
    }
    if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0x151;
      uVar4 = 0x151;
LAB_001ac451:
      FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
                   "dmal/common/common_xids.c",uVar4,"cSystemClearXid",uVar6,uVar2);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 001ac500 FUN_001ac500 =====

int FUN_001ac500(long param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar2 = 3;
  if (DAT_01214898 == 0) {
    return 3;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x20) != 0)) &&
     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0xb8), pcVar1 != (code *)0x0)) {
    uVar4 = *(undefined8 *)(param_1 + 0x10);
    iVar2 = (*pcVar1)(DAT_012164a0,&DAT_00380898);
    if (iVar2 == 0) {
      if (((DAT_003a5f70 == 0) || (*(undefined8 **)(DAT_003a5f70 + 0x50) == (undefined8 *)0x0)) ||
         (pcVar1 = (code *)**(undefined8 **)(DAT_003a5f70 + 0x50), pcVar1 == (code *)0x0)) {
        iVar2 = 3;
      }
      else {
        iVar2 = (*pcVar1)(DAT_003a5f70,&DAT_00380898,0x2080,&local_2c);
        if (iVar2 == 0) {
          iVar2 = FUN_0019c780(uVar4,DAT_0038088c,local_2c,0x20802205,&local_30,4,0);
          switch(iVar2) {
          case 0:
            *param_2 = local_30;
            return iVar2;
          default:
            return 999;
          case 3:
          case 0x66:
            return 10;
          case 0xf:
            return iVar2;
          case 0x17:
          case 99:
            return 0x13;
          case 0x1a:
            return 0x17;
          case 0x1b:
            return 4;
          case 0x1f:
          case 0x3b:
          case 0x54:
            return 2;
          case 0x51:
            return 0x14;
          case 0x55:
            return 0x1b;
          case 0x56:
            return 3;
          case 0x59:
            return 0x11;
          case 0x62:
            return 0x10;
          }
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0x2f;
      uVar4 = 0x2f;
      goto LAB_001ac656;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  fVar5 = fVar5 * DAT_00298548;
  uVar6 = 0x2b;
  uVar4 = 0x2b;
LAB_001ac656:
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
               "dmal/common/common_xids.c",uVar4,"cSystemGetXidCount",uVar6,iVar2);
  return iVar2;
}


// ===== 001ac780 FUN_001ac780 =====

int FUN_001ac780(long param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 *param_5,undefined8 *param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  long *plVar10;
  char *pcVar11;
  char *pcVar12;
  undefined8 uVar13;
  float fVar14;
  double dVar15;
  undefined8 uVar16;
  char *local_2098;
  undefined4 local_206c;
  undefined1 local_2068 [32];
  undefined4 local_2048;
  int local_2044;
  char local_2040;
  char local_203f;
  undefined4 local_203c;
  undefined1 local_2038 [8200];
  
  if (DAT_01214898 == 0) {
    return 3;
  }
  if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x20) == 0)) ||
     (pcVar5 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0xb8), pcVar5 == (code *)0x0)) {
    iVar6 = 3;
  }
  else {
    uVar13 = *(undefined8 *)(param_1 + 0x10);
    iVar6 = (*pcVar5)(DAT_012164a0,&DAT_00380898);
    if (iVar6 == 0) {
      if (((DAT_003a5f70 == 0) || (*(undefined8 **)(DAT_003a5f70 + 0x50) == (undefined8 *)0x0)) ||
         (pcVar5 = (code *)**(undefined8 **)(DAT_003a5f70 + 0x50), pcVar5 == (code *)0x0)) {
        iVar6 = 3;
      }
      else {
        iVar6 = (*pcVar5)(DAT_003a5f70,&DAT_00380898,0x2080,&local_206c);
        if (iVar6 == 0) {
          pcVar12 = (char *)(ulong)DAT_0038088c;
          local_2048 = param_2;
          iVar7 = FUN_0019c780(uVar13,pcVar12,local_206c,0x20802213,&local_2048,0x2008,0);
          iVar6 = local_2044;
          switch(iVar7) {
          case 0:
            goto switchD_001ac8b0_caseD_0;
          default:
            goto switchD_001ac8b0_caseD_1;
          case 3:
          case 0x66:
            return 10;
          case 0xf:
            return iVar7;
          case 0x17:
          case 99:
            return 0x13;
          case 0x1a:
            return 0x17;
          case 0x1b:
            return 4;
          case 0x1f:
          case 0x3b:
          case 0x54:
            return 2;
          case 0x51:
            return 0x14;
          case 0x55:
            return 0x1b;
          case 0x56:
            return 3;
          case 0x59:
            return 0x11;
          case 0x62:
            return 0x10;
          }
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar6;
      }
      fVar14 = (float)FUN_002917b0(&DAT_01216a60);
      lVar8 = syscall(0xba);
      fVar14 = fVar14 * DAT_00298548;
      uVar16 = 0x60;
      uVar13 = 0x60;
      goto LAB_001ac938;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar6;
  }
  fVar14 = (float)FUN_002917b0(&DAT_01216a60);
  lVar8 = syscall(0xba);
  fVar14 = fVar14 * DAT_00298548;
  uVar16 = 0x5c;
  uVar13 = 0x5c;
LAB_001ac938:
  FUN_002340f0((double)fVar14,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar8,
               "dmal/common/common_xids.c",uVar13,"cSystemGetXidByIndex",uVar16,iVar6);
  return iVar6;
switchD_001ac8b0_caseD_0:
  pcVar11 = (char *)&switchD_001ac8b0::switchdataD_002afa58;
  if (4 < DAT_01216a78) {
    fVar14 = (float)FUN_002917b0(&DAT_01216a60);
    lVar8 = syscall(0xba);
    pcVar11 = "dmal/common/common_xids.c";
    pcVar12 = "DEBUG";
    FUN_002340f0((double)(fVar14 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","DEBUG",
                 lVar8,"dmal/common/common_xids.c",0x6e,iVar6);
  }
  uVar1 = local_203c;
  if (local_2044 == 0) {
    return 2;
  }
  if (local_2040 != '\x01') {
    if (DAT_01216a78 < 5) {
      return 3;
    }
    fVar14 = (float)FUN_002917b0(&DAT_01216a60);
    lVar8 = syscall(0xba);
    uVar13 = 0x88;
    fVar14 = fVar14 * DAT_00298548;
    local_203f = local_2040;
LAB_001acc87:
    FUN_002340f0((double)fVar14,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","DEBUG",lVar8,
                 "dmal/common/common_xids.c",uVar13,local_203f);
    return 3;
  }
  if (local_203f != -0x7d) {
    if (DAT_01216a78 < 5) {
      return 3;
    }
    fVar14 = (float)FUN_002917b0(&DAT_01216a60);
    lVar8 = syscall(0xba);
    uVar13 = 0x94;
    fVar14 = fVar14 * DAT_00298548;
    goto LAB_001acc87;
  }
  if (4 < DAT_01216a78) {
    fVar14 = (float)FUN_002917b0(&DAT_01216a60);
    lVar8 = syscall(0xba);
    pcVar11 = "dmal/common/common_xids.c";
    FUN_002340f0((double)(fVar14 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %d\n",
                 "DEBUG",lVar8,"dmal/common/common_xids.c",0xa4,8,uVar1,pcVar12);
  }
  iVar6 = FUN_0024b9d0(local_2068,&DAT_0032a2f0);
  if (iVar6 != 0) {
    if (1 < DAT_01216a78) {
      fVar14 = (float)FUN_002917b0(&DAT_01216a60);
      lVar8 = syscall(0xba);
      FUN_002340f0((double)(fVar14 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","ERROR"
                   ,lVar8,"dmal/common/common_xids.c",0xb7,iVar6);
      return 999;
    }
    return 999;
  }
  iVar6 = FUN_0024bbb0(local_2068,local_2038,local_203c);
  if (iVar6 == 0) {
    lVar8 = FUN_0024c790(local_2068,&DAT_0032e300);
    if (lVar8 == 0) {
      if (1 < DAT_01216a78) {
        fVar14 = (float)FUN_002917b0(&DAT_01216a60);
        lVar8 = syscall(0xba);
        uVar13 = 0xcf;
        dVar15 = (double)(fVar14 * DAT_00298548);
LAB_001acf00:
        FUN_002340f0(dVar15,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar8,
                     "dmal/common/common_xids.c",uVar13);
      }
    }
    else {
      lVar9 = FUN_0024c670(lVar8,&DAT_0032e6c0);
      if (lVar9 == 0) {
        if (1 < DAT_01216a78) {
          fVar14 = (float)FUN_002917b0(&DAT_01216a60);
          lVar8 = syscall(0xba);
          uVar13 = 0xdd;
          dVar15 = (double)(fVar14 * DAT_00298548);
          goto LAB_001acf00;
        }
      }
      else {
        uVar1 = **(undefined4 **)(lVar9 + 8);
        plVar10 = (long *)FUN_0024c670(lVar8,&DAT_0032e660);
        if (plVar10 == (long *)0x0) {
          if (1 < DAT_01216a78) {
            fVar14 = (float)FUN_002917b0(&DAT_01216a60);
            lVar8 = syscall(0xba);
            uVar13 = 0xe6;
            dVar15 = (double)(fVar14 * DAT_00298548);
            goto LAB_001acf00;
          }
        }
        else {
          *param_3 = *(undefined4 *)plVar10[1];
          local_2098 = (char *)FUN_0024c6c0(*(undefined8 *)(*plVar10 + 0x10),
                                            *(undefined4 *)plVar10[1]);
          if (local_2098 == (char *)0x0) {
            local_2098 = "unknown";
          }
          lVar9 = FUN_0024c670(lVar8,&DAT_0032e640);
          if (lVar9 == 0) {
            if (1 < DAT_01216a78) {
              fVar14 = (float)FUN_002917b0(&DAT_01216a60);
              lVar8 = syscall(0xba);
              uVar13 = 0xf9;
              dVar15 = (double)(fVar14 * DAT_00298548);
              goto LAB_001acf00;
            }
          }
          else {
            *param_5 = **(undefined4 **)(lVar9 + 8);
            lVar8 = FUN_0024c670(lVar8,&DAT_0032e700);
            if (lVar8 != 0) {
              *param_6 = **(undefined8 **)(lVar8 + 8);
              if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x38) == 0)) ||
                 (pcVar5 = *(code **)(*(long *)(DAT_012164a0 + 0x38) + 0x58), pcVar5 == (code *)0x0)
                 ) {
                iVar6 = 3;
              }
              else {
                iVar6 = (*pcVar5)(DAT_012164a0,uVar1,param_4);
                if (iVar6 == 0) {
                  if (4 < DAT_01216a78) {
                    uVar2 = *param_5;
                    uVar3 = *param_3;
                    uVar13 = *param_6;
                    uVar4 = *param_4;
                    fVar14 = (float)FUN_002917b0(&DAT_01216a60);
                    lVar8 = syscall(0xba);
                    FUN_002340f0((double)(fVar14 * DAT_00298548),
                                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s %d %d %d %llu\n","DEBUG",
                                 lVar8,"dmal/common/common_xids.c",0x11c,uVar3,local_2098,uVar4,
                                 uVar1,uVar2,uVar13,lVar8);
                  }
                  goto LAB_001acea9;
                }
              }
              if (4 < DAT_01216a78) {
                uVar2 = *param_5;
                uVar3 = *param_3;
                fVar14 = (float)FUN_002917b0(&DAT_01216a60);
                lVar8 = syscall(0xba);
                FUN_002340f0((double)(fVar14 * DAT_00298548),
                             "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s %d %d\n","DEBUG",lVar8,
                             "dmal/common/common_xids.c",0x115,uVar3,local_2098,uVar1,uVar2,pcVar11)
                ;
              }
LAB_001acea9:
              FUN_0024ba60(local_2068);
              return iVar6;
            }
            if (1 < DAT_01216a78) {
              fVar14 = (float)FUN_002917b0(&DAT_01216a60);
              lVar8 = syscall(0xba);
              uVar13 = 0x105;
              dVar15 = (double)(fVar14 * DAT_00298548);
              goto LAB_001acf00;
            }
          }
        }
      }
    }
  }
  else if (1 < DAT_01216a78) {
    fVar14 = (float)FUN_002917b0(&DAT_01216a60);
    lVar8 = syscall(0xba);
    FUN_002340f0((double)(fVar14 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","ERROR",
                 lVar8,"dmal/common/common_xids.c",0xc5,iVar6);
  }
  FUN_0024ba60(local_2068);
switchD_001ac8b0_caseD_1:
  return 999;
}


// ===== 001ad190 FUN_001ad190 =====

uint FUN_001ad190(long param_1,long param_2,uint *param_3,undefined4 *param_4)

{
  uint uVar1;
  undefined8 uVar2;
  code *pcVar3;
  uint uVar4;
  long lVar5;
  undefined4 *puVar6;
  uint uVar7;
  float fVar8;
  undefined4 local_344c;
  uint local_3448;
  undefined4 local_3444 [3333];
  
  uVar2 = *(undefined8 *)(param_1 + 0x10);
  memset(&local_3448,0,0x3404);
  lVar5 = *(long *)(param_2 + 0x256d8);
  if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar3 = (code *)**(undefined8 **)(lVar5 + 0x50), pcVar3 == (code *)0x0)) {
    uVar4 = 3;
  }
  else {
    uVar4 = (*pcVar3)(lVar5,param_2,0x2080,&local_344c);
    if (uVar4 == 0) {
      uVar4 = FUN_0019c780(uVar2,DAT_0038088c,local_344c,0x2080017c,&local_3448,0x3404,0);
      switch(uVar4) {
      case 0:
        goto switchD_001ad2fb_caseD_0;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return uVar4;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (1 < DAT_01216a78) {
    fVar8 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar8 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar5,"dmal/common/common_fbc.c",0x36,"cDeviceGetFBCSessions",0x36,uVar4);
  }
  return uVar4;
switchD_001ad2fb_caseD_0:
  uVar7 = *param_3;
  *param_3 = local_3448;
  if (param_4 == (undefined4 *)0x0) {
    return uVar4;
  }
  if (uVar7 == 0) {
    return uVar4;
  }
  if (uVar7 < local_3448) {
    return 7;
  }
  puVar6 = local_3444;
  uVar7 = uVar4;
  if (local_3448 == 0) {
    return uVar4;
  }
  do {
    *param_4 = puVar6[3];
    param_4[1] = *puVar6;
    param_4[2] = puVar6[2];
    param_4[3] = puVar6[5];
    param_4[4] = puVar6[4];
    uVar1 = puVar6[6];
    param_4[5] = uVar1 & 1;
    if ((uVar1 & 2) != 0) {
      param_4[5] = param_4[5] | 2;
    }
    if ((uVar1 & 4) == 0) {
      if ((uVar1 & 8) == 0) {
        if ((uVar1 & 0x10) != 0) {
          param_4[5] = param_4[5] | 0x10;
        }
      }
      else {
        param_4[5] = param_4[5] | 8;
      }
    }
    else {
      param_4[5] = param_4[5] | 4;
    }
    uVar7 = uVar7 + 1;
    param_4[6] = puVar6[7];
    param_4[7] = puVar6[8];
    param_4[8] = puVar6[9];
    param_4[9] = puVar6[10];
    param_4[10] = puVar6[0xb];
    param_4[0xb] = puVar6[0xc];
    puVar6 = puVar6 + 0xd;
    param_4 = param_4 + 0xc;
  } while (uVar7 < *param_3);
  return uVar4;
}


// ===== 001ad480 FUN_001ad480 =====

int FUN_001ad480(long param_1,long param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  undefined4 local_38;
  undefined8 local_34;
  undefined4 local_2c;
  
  local_34 = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  local_2c = 0;
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    iVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_38);
    if (iVar3 == 0) {
      iVar3 = FUN_0019c780(uVar1,DAT_0038088c,local_38,0x2080017b,&local_34,0xc,0);
      switch(iVar3) {
      case 0:
        *param_3 = local_34;
        *(undefined4 *)(param_3 + 1) = local_2c;
        return iVar3;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar3;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar3;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar4,"dmal/common/common_fbc.c",0x16,"cDeviceGetFBCStats",0x16,iVar3);
  return iVar3;
}


// ===== 001ad690 FUN_001ad690 =====

uint FUN_001ad690(long param_1,long param_2,uint *param_3)

{
  long lVar1;
  code *pcVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  float fVar7;
  undefined8 uVar8;
  byte local_3d;
  undefined4 local_3c [3];
  
  local_3d = 0;
  lVar6 = *(long *)(param_1 + 0x10);
  if (param_3 == (uint *)0x0) {
switchD_001ad881_caseD_1f:
    uVar4 = 2;
  }
  else {
    uVar3 = FUN_0023a420();
    lVar1 = *(long *)(param_2 + 0x256d8);
    if (((lVar1 == 0) || (*(undefined8 **)(lVar1 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar2 = (code *)**(undefined8 **)(lVar1 + 0x50), pcVar2 == (code *)0x0)) {
      uVar4 = 3;
    }
    else {
      uVar4 = (*pcVar2)(lVar1,param_2,0x2080,local_3c);
      if (uVar4 == 0) {
        uVar8 = 0;
        iVar5 = (**(code **)(lVar6 + 0x10))(param_2,DAT_0038088c,local_3c[0],uVar3,0xcbca,0);
        if (iVar5 == 0) {
          uVar4 = FUN_0019c780(lVar6,DAT_0038088c,uVar3,0xcbca0104,&local_3d,1,0);
          (**(code **)(lVar6 + 0x28))(DAT_0038088c,local_3c[0],uVar3);
          switch(uVar4) {
          case 0:
            *param_3 = (uint)local_3d;
            return uVar4;
          default:
            return 999;
          case 3:
          case 0x66:
            return 10;
          case 0xf:
            return uVar4;
          case 0x17:
          case 99:
            return 0x13;
          case 0x1a:
            return 0x17;
          case 0x1b:
            return 4;
          case 0x1f:
          case 0x3b:
          case 0x54:
            goto switchD_001ad881_caseD_1f;
          case 0x51:
            return 0x14;
          case 0x55:
            return 0x1b;
          case 0x56:
            return 3;
          case 0x59:
            return 0x11;
          case 0x62:
            return 0x10;
          }
        }
        (**(code **)(lVar6 + 0x28))(DAT_0038088c,local_3c[0],uVar3,uVar8);
        if (99 < iVar5 - 3U) {
          return 999;
        }
        return (uint)*(ushort *)(&DAT_002b0540 + (ulong)(iVar5 - 3U) * 2);
      }
    }
    if (1 < DAT_01216a78) {
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar6 = syscall(0xba);
      FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar6,"dmal/common/common_ccu.c",0x14f,"cDeviceCcuGetStreamState",0x14f,
                   uVar4);
    }
  }
  return uVar4;
}


// ===== 001ad910 FUN_001ad910 =====

uint FUN_001ad910(long param_1,long param_2,uint param_3)

{
  long lVar1;
  code *pcVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  float fVar7;
  undefined8 uVar8;
  undefined1 local_3d;
  undefined4 local_3c [3];
  
  local_3d = 0;
  if (1 < param_3) {
    return 2;
  }
  lVar6 = *(long *)(param_1 + 0x10);
  uVar3 = FUN_0023a420();
  lVar1 = *(long *)(param_2 + 0x256d8);
  if (((lVar1 == 0) || (*(undefined8 **)(lVar1 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar1 + 0x50), pcVar2 == (code *)0x0)) {
    uVar4 = 3;
  }
  else {
    uVar4 = (*pcVar2)(lVar1,param_2,0x2080,local_3c);
    if (uVar4 == 0) {
      uVar8 = 0;
      iVar5 = (**(code **)(lVar6 + 0x10))(param_2,DAT_0038088c,local_3c[0],uVar3,0xcbca,0);
      if (iVar5 == 0) {
        local_3d = (char)param_3;
        uVar4 = FUN_0019c780(lVar6,DAT_0038088c,uVar3,0xcbca0103,&local_3d,1,0);
        (**(code **)(lVar6 + 0x28))(DAT_0038088c,local_3c[0],uVar3);
        if (uVar4 < 0x67) {
          return (uint)*(ushort *)(&DAT_002b0620 + (ulong)uVar4 * 2);
        }
      }
      else {
        (**(code **)(lVar6 + 0x28))(DAT_0038088c,local_3c[0],uVar3,uVar8);
        if (iVar5 - 3U < 100) {
          return (uint)*(ushort *)(&DAT_002b0540 + (ulong)(iVar5 - 3U) * 2);
        }
      }
      return 999;
    }
  }
  if (1 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar6,"dmal/common/common_ccu.c",0x121,"cDeviceCcuSetStreamState",0x121,
                 uVar4);
  }
  return uVar4;
}


// ===== 001adb00 FUN_001adb00 =====

uint FUN_001adb00(long param_1,char *param_2,ulong *param_3)

{
  long lVar1;
  code *pcVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  long lVar7;
  undefined8 uVar8;
  char *pcVar9;
  float fVar10;
  double dVar11;
  undefined8 uVar12;
  undefined4 *local_58;
  ulong local_50;
  undefined1 local_48 [16];
  
  if ((param_3 == (ulong *)0x0) || (param_2 == (char *)0x0)) {
    return 2;
  }
  if (*param_2 == '\x01') {
    lVar7 = *(long *)(param_1 + 0x10);
    if (*(int *)(param_2 + 0x70534) != 0) goto LAB_001adb8b;
LAB_001adc90:
    local_48 = (undefined1  [16])0x0;
    local_50 = 0;
    do {
      iVar5 = FUN_00291820(param_2 + 0x70538,1,0);
    } while (iVar5 != 0);
    if (*(int *)(param_2 + 0x70534) == 0) {
      lVar1 = *(long *)(param_2 + 0x256d8);
      uVar3 = 3;
      if (((lVar1 != 0) && (*(long *)(lVar1 + 0x38) != 0)) &&
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x38) + 8), pcVar2 != (code *)0x0)) {
        uVar3 = (*pcVar2)(lVar1,param_2,param_2 + 0x70530);
      }
      *(undefined4 *)(param_2 + 0x7053c) = uVar3;
      param_2[0x70534] = '\x01';
      param_2[0x70535] = '\0';
      param_2[0x70536] = '\0';
      param_2[0x70537] = '\0';
    }
    FUN_00291830(param_2 + 0x70538,0);
    uVar4 = *(uint *)(param_2 + 0x7053c);
  }
  else {
    if (*(long *)(param_2 + 0x20) == 0) {
      local_58 = (undefined4 *)0x0;
      iVar5 = FUN_001384c0(param_2,&local_58);
      if (iVar5 != 0) {
        return 999;
      }
      local_50 = 0;
      uVar3 = *local_58;
      uVar6 = FUN_0023a420();
      lVar7 = *(long *)(param_1 + 0x10);
      iVar5 = (**(code **)(lVar7 + 0x10))(param_2,uVar3,2,uVar6,0xcbca,0,0);
      if (iVar5 != 0) {
        (**(code **)(lVar7 + 0x28))(uVar3,2,uVar6);
        if (99 < iVar5 - 3U) {
          return 999;
        }
        return (uint)*(ushort *)(&DAT_002b0540 + (ulong)(iVar5 - 3U) * 2);
      }
      if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x30) == 0)) ||
         (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0x100), pcVar2 == (code *)0x0)) {
        uVar4 = 3;
      }
      else {
        uVar4 = (*pcVar2)(DAT_012164a0,local_58);
        if (uVar4 == 0) {
          local_48 = (undefined1  [16])0x0;
          iVar5 = FUN_0019c780(lVar7,uVar3,uVar6,0xcbca0101,local_48,0x10,0);
          if (iVar5 != 0) {
            (**(code **)(lVar7 + 0x28))(uVar3,2,uVar6);
            if (99 < iVar5 - 3U) {
              return 999;
            }
            return (uint)*(ushort *)(&DAT_002b0540 + (ulong)(iVar5 - 3U) * 2);
          }
          iVar5 = (**(code **)(lVar7 + 0x58))(uVar3,2,uVar6,0,local_48._0_8_,&local_50,1);
          if (iVar5 == 0) {
            if (local_50 != 0) {
              param_3[1] = local_50;
              *(undefined4 *)(param_3 + 2) = 2;
              *param_3 = (ulong)(uint)local_48._8_4_;
              *(undefined4 *)((long)param_3 + 0x14) = uVar6;
              *(undefined4 *)(param_3 + 3) = uVar3;
              return 0;
            }
            return 0;
          }
          (**(code **)(lVar7 + 0x28))(uVar3,2,uVar6);
          if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x30) != 0)) &&
             (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0x108), pcVar2 != (code *)0x0)) {
            (*pcVar2)(DAT_012164a0,local_58);
          }
          if (99 < iVar5 - 3U) {
            return 999;
          }
          return (uint)*(ushort *)(&DAT_002b0540 + (ulong)(iVar5 - 3U) * 2);
        }
      }
      if (DAT_01216a78 < 2) {
        return uVar4;
      }
      fVar10 = (float)FUN_002917b0(&DAT_01216a60);
      lVar7 = syscall(0xba);
      pcVar9 = "helperMigdeviceSubscribeCcu";
      uVar12 = 0x9b;
      uVar8 = 0x9b;
      dVar11 = (double)(fVar10 * DAT_00298548);
      goto LAB_001add79;
    }
    lVar7 = *(long *)(param_1 + 0x10);
    if (*(int *)(param_2 + 0x14) == 0) {
      return 2;
    }
    if (*(int *)(param_2 + 0x1c) != 0) {
      return 2;
    }
    if (*(int *)(param_2 + 0x10) == 0) {
      return 2;
    }
    if (*(int *)(param_2 + 0x70534) == 0) goto LAB_001adc90;
LAB_001adb8b:
    local_48 = (undefined1  [16])0x0;
    local_50 = 0;
    uVar4 = *(uint *)(param_2 + 0x7053c);
  }
  if (uVar4 == 0) {
    uVar4 = 3;
    if (*(int *)(param_2 + 0x70530) == 2) {
      return 3;
    }
    uVar3 = FUN_0023a420();
    lVar1 = *(long *)(param_2 + 0x256d8);
    if ((((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0x50) != (undefined8 *)0x0)) &&
        (pcVar2 = (code *)**(undefined8 **)(lVar1 + 0x50), pcVar2 != (code *)0x0)) &&
       (uVar4 = (*pcVar2)(lVar1,param_2,0x2080,&local_58), uVar4 == 0)) {
      iVar5 = (**(code **)(lVar7 + 0x10))
                        (param_2,DAT_0038088c,(ulong)local_58 & 0xffffffff,uVar3,0xcbca,0,0);
      if (iVar5 == 0) {
        iVar5 = FUN_0019c780(lVar7,DAT_0038088c,uVar3,0xcbca0101,local_48,0x10,0);
        if (iVar5 == 0) {
          uVar4 = (**(code **)(lVar7 + 0x58))
                            (DAT_0038088c,(ulong)local_58 & 0xffffffff,uVar3,0,local_48._0_8_,
                             &local_50,1);
          if (uVar4 == 0) {
            if (local_50 != 0) {
              param_3[1] = local_50;
              *(undefined4 *)(param_3 + 2) = local_58._0_4_;
              *param_3 = (ulong)(uint)local_48._8_4_;
              *(undefined4 *)((long)param_3 + 0x14) = uVar3;
              return 0;
            }
            (**(code **)(lVar7 + 0x28))(DAT_0038088c,(ulong)local_58 & 0xffffffff,uVar3);
          }
          else {
            (**(code **)(lVar7 + 0x28))(DAT_0038088c,(ulong)local_58 & 0xffffffff,uVar3);
            if (0x66 < uVar4) {
              return 999;
            }
          }
          return (uint)*(ushort *)(&DAT_002b0460 + (ulong)uVar4 * 2);
        }
        (**(code **)(lVar7 + 0x28))(DAT_0038088c,(ulong)local_58 & 0xffffffff,uVar3);
        if (iVar5 - 3U < 100) {
          return (uint)*(ushort *)(&DAT_002b0540 + (ulong)(iVar5 - 3U) * 2);
        }
      }
      else {
        (**(code **)(lVar7 + 0x28))(DAT_0038088c,(ulong)local_58 & 0xffffffff,uVar3);
        if (iVar5 - 3U < 100) {
          return (uint)*(ushort *)(&DAT_002b0540 + (ulong)(iVar5 - 3U) * 2);
        }
      }
      return 999;
    }
    if (DAT_01216a78 < 2) {
      return uVar4;
    }
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar7 = syscall(0xba);
    pcVar9 = "helperDeviceSubscribeCcu";
    uVar12 = 0x2e;
    uVar8 = 0x2e;
    dVar11 = (double)(fVar10 * DAT_00298548);
  }
  else {
    if (DAT_01216a78 < 2) {
      return uVar4;
    }
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar7 = syscall(0xba);
    pcVar9 = "helperDeviceSubscribeCcu";
    uVar12 = 0x1f;
    uVar8 = 0x1f;
    dVar11 = (double)(fVar10 * DAT_00298548);
  }
LAB_001add79:
  FUN_002340f0(dVar11,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar7,
               "dmal/common/common_ccu.c",uVar8,pcVar9,uVar12,uVar4);
  return uVar4;
}


// ===== 001ae1c0 FUN_001ae1c0 =====

int FUN_001ae1c0(long param_1,char *param_2,undefined4 *param_3)

{
  code *pcVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  long lVar14;
  undefined8 uVar15;
  float fVar16;
  undefined8 uVar17;
  undefined4 local_5c;
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  
  *param_3 = 0;
  lVar14 = *(long *)(param_2 + 0x256d8);
  local_58 = (undefined1  [16])0x0;
  local_48 = (undefined1  [16])0x0;
  if (((lVar14 == 0) || (*(undefined8 **)(lVar14 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar14 + 0x50), pcVar1 == (code *)0x0)) {
    iVar11 = 3;
joined_r0x001ae330:
    if (DAT_01216a78 < 2) {
      return iVar11;
    }
    fVar16 = (float)FUN_002917b0(&DAT_01216a60);
    lVar14 = syscall(0xba);
    fVar16 = fVar16 * DAT_00298548;
    uVar17 = 0x177;
    uVar15 = 0x177;
LAB_001ae2a5:
    FUN_002340f0((double)fVar16,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar14,
                 "dmal/common/common_ccu.c",uVar15,"cDeviceIdentifyChipPerfFuses",uVar17,iVar11);
  }
  else {
    iVar11 = (*pcVar1)(lVar14,param_2,0x2080,&local_5c);
    if (iVar11 != 0) goto joined_r0x001ae330;
    iVar11 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_5c,0x20801230,local_58,
                          0x20,0);
    switch(iVar11) {
    case 0:
      if (4 < DAT_01216a78) {
        uVar10 = local_48[8];
        uVar9 = local_48[7];
        uVar8 = local_48[6];
        uVar7 = local_48[5];
        uVar2 = local_48[0];
        uVar5 = local_48[3];
        uVar6 = local_48[4];
        uVar3 = local_48[1];
        uVar4 = local_48[2];
        fVar16 = (float)FUN_002917b0(&DAT_01216a60);
        lVar14 = syscall(0xba);
        FUN_002340f0((double)(fVar16 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tGpmAdjData: %d %d %d %d %d %d %d %d %d\n",
                     "DEBUG",lVar14,"dmal/common/common_ccu.c",0x17e,uVar4,uVar6,uVar3,uVar5,uVar2,
                     uVar7,uVar8,uVar9,uVar10);
      }
      if ((*param_2 == '\x01') ||
         (((*(int *)(param_2 + 0x14) != 0 && (*(int *)(param_2 + 0x1c) == 0)) &&
          ((*(int *)(param_2 + 0x10) != 0 && (*(long *)(param_2 + 0x20) != 0)))))) {
        if (*(int *)(param_2 + 0x71c) == 0) {
          do {
            iVar12 = FUN_00291820(param_2 + 0x720,1,0);
          } while (iVar12 != 0);
          if (*(int *)(param_2 + 0x71c) == 0) {
            lVar14 = *(long *)(param_2 + 0x256d8);
            uVar13 = 3;
            if (((lVar14 != 0) && (*(long *)(lVar14 + 0x20) != 0)) &&
               (pcVar1 = *(code **)(*(long *)(lVar14 + 0x20) + 0x98), pcVar1 != (code *)0x0)) {
              uVar13 = (*pcVar1)(lVar14,param_2,param_2 + 0x708);
            }
            *(undefined4 *)(param_2 + 0x724) = uVar13;
            param_2[0x71c] = '\x01';
            param_2[0x71d] = '\0';
            param_2[0x71e] = '\0';
            param_2[0x71f] = '\0';
          }
          FUN_00291830(param_2 + 0x720,0);
        }
        if (*(int *)(param_2 + 0x724) == 0) {
          if (*(int *)(param_2 + 0x708) != 0xc) {
            return 0;
          }
          if ((local_48._0_8_ & 0xff0000ffffffff) != 0x2000002010202) {
            return 0;
          }
          if (local_48[8] != '\x02') {
            return 0;
          }
          *param_3 = 1;
          return 0;
        }
        if (*(int *)(param_2 + 0x724) != 0xf) {
          if (DAT_01216a78 < 2) {
            return iVar11;
          }
          fVar16 = (float)FUN_002917b0(&DAT_01216a60);
          lVar14 = syscall(0xba);
          FUN_002340f0((double)(fVar16 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       "ERROR",lVar14,
                       "/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h",0x27);
          return iVar11;
        }
        iVar11 = 0xf;
      }
      else {
        iVar11 = 2;
      }
      if (DAT_01216a78 < 2) {
        return iVar11;
      }
      fVar16 = (float)FUN_002917b0(&DAT_01216a60);
      lVar14 = syscall(0xba);
      fVar16 = fVar16 * DAT_00298548;
      uVar17 = 0x184;
      uVar15 = 0x184;
      goto LAB_001ae2a5;
    default:
      iVar11 = 999;
      break;
    case 3:
    case 0x66:
      iVar11 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      iVar11 = 0x13;
      break;
    case 0x1a:
      iVar11 = 0x17;
      break;
    case 0x1b:
      iVar11 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
      iVar11 = 2;
      break;
    case 0x51:
      iVar11 = 0x14;
      break;
    case 0x55:
      iVar11 = 0x1b;
      break;
    case 0x56:
      iVar11 = 3;
      break;
    case 0x59:
      iVar11 = 0x11;
      break;
    case 0x62:
      iVar11 = 0x10;
    }
  }
  return iVar11;
}


// ===== 001ae690 FUN_001ae690 =====

uint FUN_001ae690(long param_1,char *param_2,long param_3)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  long lVar6;
  undefined8 uVar7;
  char *pcVar8;
  float fVar9;
  undefined8 uVar10;
  undefined8 local_30;
  
  if ((param_2 == (char *)0x0) || (param_3 == 0)) {
    return 2;
  }
  lVar6 = *(long *)(param_1 + 0x10);
  if (*param_2 != '\x01') {
    if (*(long *)(param_2 + 0x20) == 0) {
      local_30 = 0;
      uVar3 = FUN_001384c0(param_2,&local_30);
      if (uVar3 == 0) {
        uVar3 = (**(code **)(lVar6 + 0x68))
                          (*(undefined4 *)(param_3 + 0x18),*(undefined4 *)(param_3 + 0x10),
                           *(undefined4 *)(param_3 + 0x14),*(undefined8 *)(param_3 + 8),1);
        if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x30) != 0)) &&
           (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0x108), pcVar2 != (code *)0x0)) {
          (*pcVar2)(DAT_012164a0,local_30);
        }
        (**(code **)(lVar6 + 0x28))
                  (*(undefined4 *)(param_3 + 0x18),*(undefined4 *)(param_3 + 0x10),
                   *(undefined4 *)(param_3 + 0x14));
        if (0x66 < uVar3) {
          return 999;
        }
        return (uint)*(ushort *)(&DAT_002b0620 + (ulong)uVar3 * 2);
      }
      if (DAT_01216a78 < 2) {
        return uVar3;
      }
      fVar9 = (float)FUN_002917b0(&DAT_01216a60);
      lVar6 = syscall(0xba);
      pcVar8 = "helperMigdeviceUnsubscribeCcu";
      fVar9 = fVar9 * DAT_00298548;
      uVar10 = 0xca;
      uVar7 = 0xca;
      goto LAB_001ae859;
    }
    if (*(int *)(param_2 + 0x14) == 0) {
      return 2;
    }
    if (*(int *)(param_2 + 0x1c) != 0) {
      return 2;
    }
    if (*(int *)(param_2 + 0x10) == 0) {
      return 2;
    }
  }
  if (*(int *)(param_2 + 0x70534) == 0) {
    do {
      iVar4 = FUN_00291820(param_2 + 0x70538,1,0);
    } while (iVar4 != 0);
    if (*(int *)(param_2 + 0x70534) == 0) {
      lVar1 = *(long *)(param_2 + 0x256d8);
      uVar5 = 3;
      if (((lVar1 != 0) && (*(long *)(lVar1 + 0x38) != 0)) &&
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x38) + 8), pcVar2 != (code *)0x0)) {
        uVar5 = (*pcVar2)(lVar1,param_2,param_2 + 0x70530);
      }
      *(undefined4 *)(param_2 + 0x7053c) = uVar5;
      param_2[0x70534] = '\x01';
      param_2[0x70535] = '\0';
      param_2[0x70536] = '\0';
      param_2[0x70537] = '\0';
    }
    FUN_00291830(param_2 + 0x70538,0);
    uVar3 = *(uint *)(param_2 + 0x7053c);
  }
  else {
    uVar3 = *(uint *)(param_2 + 0x7053c);
  }
  if (uVar3 == 0) {
    if (*(int *)(param_2 + 0x70530) == 2) {
      return 3;
    }
    uVar3 = (**(code **)(lVar6 + 0x68))
                      (DAT_0038088c,*(undefined4 *)(param_3 + 0x10),*(undefined4 *)(param_3 + 0x14),
                       *(undefined8 *)(param_3 + 8),1);
    (**(code **)(lVar6 + 0x28))
              (DAT_0038088c,*(undefined4 *)(param_3 + 0x10),*(undefined4 *)(param_3 + 0x14));
    if (0x66 < uVar3) {
      return 999;
    }
    return (uint)*(ushort *)(&DAT_002b0620 + (ulong)uVar3 * 2);
  }
  if (DAT_01216a78 < 2) {
    return uVar3;
  }
  fVar9 = (float)FUN_002917b0(&DAT_01216a60);
  lVar6 = syscall(0xba);
  pcVar8 = "helperDeviceUnsubscribeCcu";
  fVar9 = fVar9 * DAT_00298548;
  uVar10 = 100;
  uVar7 = 100;
LAB_001ae859:
  FUN_002340f0((double)fVar9,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar6,
               "dmal/common/common_ccu.c",uVar7,pcVar8,uVar10,uVar3);
  return uVar3;
}


// ===== 001ae9c0 FUN_001ae9c0 =====

void FUN_001ae9c0(long param_1,undefined4 *param_2,undefined4 *param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x20) != 0)) &&
     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0x80), pcVar1 != (code *)0x0)) {
    (*pcVar1)();
  }
  uVar2 = DAT_0038088c;
  *param_3 = DAT_0038088c;
  (**(code **)(param_1 + 0x10))(0,uVar2,uVar2,*param_2,0xcb33,param_3,8);
  return;
}


// ===== 001aea30 FUN_001aea30 =====

undefined4 FUN_001aea30(long param_1,long param_2)

{
  long lVar1;
  undefined4 uVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  
  lVar1 = *(long *)(param_1 + 0x10);
  local_30 = 0;
  local_38 = 0;
  uVar2 = FUN_001ae9c0(lVar1,&local_34,&local_38);
  switch(uVar2) {
  case 0:
    uVar2 = FUN_0019c780(lVar1,DAT_0038088c,local_34,0xc56f010e,&local_30,8,0);
    (**(code **)(lVar1 + 0x28))(DAT_0038088c,DAT_0038088c,local_34);
    switch(uVar2) {
    case 0:
      *(undefined8 *)(param_2 + 8) = local_30;
      break;
    default:
      goto switchD_001aea7d_caseD_1;
    case 3:
    case 0x66:
      goto switchD_001aea7d_caseD_3;
    case 0xf:
      break;
    case 0x17:
    case 99:
      goto switchD_001aea7d_caseD_17;
    case 0x1a:
      goto switchD_001aea7d_caseD_1a;
    case 0x1b:
      goto switchD_001aea7d_caseD_1b;
    case 0x1f:
    case 0x3b:
    case 0x54:
      goto switchD_001aea7d_caseD_1f;
    case 0x51:
      goto switchD_001aea7d_caseD_51;
    case 0x55:
      goto switchD_001aea7d_caseD_55;
    case 0x56:
      goto switchD_001aea7d_caseD_56;
    case 0x59:
      goto switchD_001aea7d_caseD_59;
    case 0x62:
      goto switchD_001aea7d_caseD_62;
    }
    break;
  default:
switchD_001aea7d_caseD_1:
    uVar2 = 999;
    break;
  case 3:
  case 0x66:
switchD_001aea7d_caseD_3:
    return 10;
  case 0xf:
    break;
  case 0x17:
  case 99:
switchD_001aea7d_caseD_17:
    return 0x13;
  case 0x1a:
switchD_001aea7d_caseD_1a:
    return 0x17;
  case 0x1b:
switchD_001aea7d_caseD_1b:
    return 4;
  case 0x1f:
  case 0x3b:
  case 0x54:
switchD_001aea7d_caseD_1f:
    return 2;
  case 0x51:
switchD_001aea7d_caseD_51:
    return 0x14;
  case 0x55:
switchD_001aea7d_caseD_55:
    return 0x1b;
  case 0x56:
switchD_001aea7d_caseD_56:
    return 3;
  case 0x59:
switchD_001aea7d_caseD_59:
    return 0x11;
  case 0x62:
switchD_001aea7d_caseD_62:
    uVar2 = 0x10;
  }
  return uVar2;
}


// ===== 001aeba0 FUN_001aeba0 =====

ulong FUN_001aeba0(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 local_38;
  undefined4 local_34;
  long local_30 [2];
  
  lVar1 = *(long *)(param_1 + 0x10);
  local_30[0] = 0;
  local_38 = 0;
  uVar3 = FUN_001ae9c0(lVar1,&local_34,&local_38);
  switch(uVar3 & 0xffffffff) {
  case 0:
    local_30[0] = *(long *)(param_2 + 8);
    uVar3 = 2;
    if (local_30[0] - 0x32U < 0x10) {
      uVar2 = FUN_0019c780(lVar1,DAT_0038088c,local_34,0xc56f010d,local_30,8,0);
      (**(code **)(lVar1 + 0x28))(DAT_0038088c,DAT_0038088c,local_34);
      uVar3 = 999;
      if (uVar2 < 0x67) {
        uVar3 = (ulong)*(ushort *)(&DAT_002b2020 + (ulong)uVar2 * 2);
      }
    }
    break;
  default:
    uVar3 = 999;
    break;
  case 3:
  case 0x66:
    uVar3 = 10;
    break;
  case 0xf:
    break;
  case 0x17:
  case 99:
    uVar3 = 0x13;
    break;
  case 0x1a:
    uVar3 = 0x17;
    break;
  case 0x1b:
    uVar3 = 4;
    break;
  case 0x1f:
  case 0x3b:
  case 0x54:
    uVar3 = 2;
    break;
  case 0x51:
    uVar3 = 0x14;
    break;
  case 0x55:
    uVar3 = 0x1b;
    break;
  case 0x56:
    uVar3 = 3;
    break;
  case 0x59:
    uVar3 = 0x11;
    break;
  case 0x62:
    uVar3 = 0x10;
  }
  return uVar3;
}


// ===== 001aece0 FUN_001aece0 =====

int FUN_001aece0(long param_1,long param_2,uint *param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  byte bVar8;
  float fVar9;
  undefined4 local_3074;
  undefined4 local_3070;
  undefined4 local_306c;
  undefined4 local_3068;
  undefined8 local_3064;
  undefined8 uStack_305c;
  undefined8 local_3054;
  undefined8 uStack_304c;
  undefined8 local_3044 [1023];
  undefined8 local_104c;
  uint local_1044;
  byte local_1040;
  undefined8 local_103f [511];
  undefined8 local_47;
  uint local_3c;
  
  bVar8 = 0;
  lVar4 = *(long *)(param_1 + 0x10);
  memset(&local_3068,0,0x3030);
  local_3074 = 0;
  iVar3 = FUN_001ae9c0(lVar4,&local_3070,&local_3074);
  switch(iVar3) {
  case 0:
    lVar1 = *(long *)(param_2 + 0x256d8);
    if (((lVar1 == 0) || (*(undefined8 **)(lVar1 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar2 = (code *)**(undefined8 **)(lVar1 + 0x50), pcVar2 == (code *)0x0)) {
      iVar3 = 3;
    }
    else {
      iVar3 = (*pcVar2)(lVar1,param_2,0x2080,&local_306c);
      if (iVar3 == 0) {
        local_3064 = *(undefined8 *)(param_3 + 3);
        uStack_305c = *(undefined8 *)(param_3 + 5);
        local_3054 = *(undefined8 *)(param_3 + 7);
        uStack_304c = *(undefined8 *)(param_3 + 9);
        local_3068 = local_306c;
        iVar3 = FUN_0019c780(lVar4,DAT_0038088c,local_3070,0xcb33010a,&local_3068,0x3030,0);
        (**(code **)(lVar4 + 0x28))(DAT_0038088c,DAT_0038088c,local_3070);
        switch(iVar3) {
        case 0:
          *param_3 = (uint)local_1040;
          lVar4 = (long)param_3 + (0x2c - (long)((ulong)(param_3 + 0xd) & 0xfffffffffffffff8));
          *(undefined8 *)(param_3 + 0x809) = local_104c;
          param_3[1] = local_1044;
          param_3[2] = local_3c;
          *(undefined8 *)(param_3 + 0xb) = local_3044[0];
          puVar6 = (undefined8 *)((long)local_3044 - lVar4);
          puVar7 = (undefined8 *)((ulong)(param_3 + 0xd) & 0xfffffffffffffff8);
          for (uVar5 = (ulong)((int)lVar4 + 0x2000U >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + (ulong)bVar8 * -2 + 1;
            puVar7 = puVar7 + (ulong)bVar8 * -2 + 1;
          }
          lVar4 = (long)param_3 + (0x202c - (long)((ulong)(param_3 + 0x80d) & 0xfffffffffffffff8));
          *(undefined8 *)(param_3 + 0x80b) = local_103f[0];
          *(undefined8 *)(param_3 + 0xc09) = local_47;
          puVar6 = (undefined8 *)((long)local_103f - lVar4);
          puVar7 = (undefined8 *)((ulong)(param_3 + 0x80d) & 0xfffffffffffffff8);
          for (uVar5 = (ulong)((int)lVar4 + 0x1000U >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + (ulong)bVar8 * -2 + 1;
            puVar7 = puVar7 + (ulong)bVar8 * -2 + 1;
          }
          return iVar3;
        case 3:
        case 0x66:
          goto switchD_001aed4c_caseD_3;
        case 0xf:
          return iVar3;
        case 0x17:
        case 99:
          goto switchD_001aed4c_caseD_17;
        case 0x1a:
          goto switchD_001aed4c_caseD_1a;
        case 0x1b:
          goto switchD_001aed4c_caseD_1b;
        case 0x1f:
        case 0x3b:
        case 0x54:
          goto switchD_001aed4c_caseD_1f;
        case 0x51:
          goto switchD_001aed4c_caseD_51;
        case 0x55:
          goto switchD_001aed4c_caseD_55;
        case 0x56:
          goto switchD_001aed4c_caseD_56;
        case 0x59:
          goto switchD_001aed4c_caseD_59;
        case 0x62:
          goto switchD_001aed4c_caseD_62;
        }
        goto switchD_001aed4c_caseD_1;
      }
    }
    (**(code **)(lVar4 + 0x28))(DAT_0038088c,DAT_0038088c,local_3070);
    if (1 < DAT_01216a78) {
      fVar9 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"dmal/common/common_cc.c",0x1b0,
                   "cDeviceGetConfComputeGpuAttestationReport",0x1b0,iVar3);
    }
    break;
  default:
switchD_001aed4c_caseD_1:
    iVar3 = 999;
    break;
  case 3:
  case 0x66:
switchD_001aed4c_caseD_3:
    return 10;
  case 0xf:
    break;
  case 0x17:
  case 99:
switchD_001aed4c_caseD_17:
    return 0x13;
  case 0x1a:
switchD_001aed4c_caseD_1a:
    return 0x17;
  case 0x1b:
switchD_001aed4c_caseD_1b:
    return 4;
  case 0x1f:
  case 0x3b:
  case 0x54:
switchD_001aed4c_caseD_1f:
    return 2;
  case 0x51:
switchD_001aed4c_caseD_51:
    return 0x14;
  case 0x55:
switchD_001aed4c_caseD_55:
    return 0x1b;
  case 0x56:
switchD_001aed4c_caseD_56:
    return 3;
  case 0x59:
switchD_001aed4c_caseD_59:
    return 0x11;
  case 0x62:
switchD_001aed4c_caseD_62:
    iVar3 = 0x10;
  }
  return iVar3;
}


// ===== 001af030 FUN_001af030 =====

int FUN_001af030(long param_1,long param_2,undefined4 *param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  byte bVar8;
  float fVar9;
  undefined4 local_2454;
  undefined4 local_2450;
  undefined4 local_244c;
  undefined4 local_2448;
  undefined8 local_2444 [511];
  undefined8 local_144c;
  undefined4 local_1444;
  undefined8 local_1440 [639];
  undefined8 local_48;
  undefined4 local_40;
  
  bVar8 = 0;
  lVar4 = *(long *)(param_1 + 0x10);
  memset(&local_2448,0,0x240c);
  local_2454 = 0;
  iVar3 = FUN_001ae9c0(lVar4,&local_2450,&local_2454);
  switch(iVar3) {
  case 0:
    lVar1 = *(long *)(param_2 + 0x256d8);
    if (((lVar1 == 0) || (*(undefined8 **)(lVar1 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar2 = (code *)**(undefined8 **)(lVar1 + 0x50), pcVar2 == (code *)0x0)) {
      iVar3 = 3;
    }
    else {
      iVar3 = (*pcVar2)(lVar1,param_2,0x2080,&local_244c);
      if (iVar3 == 0) {
        local_2448 = local_244c;
        iVar3 = FUN_0019c780(lVar4,DAT_0038088c,local_2450,0xcb330109,&local_2448,0x240c,0);
        (**(code **)(lVar4 + 0x28))(DAT_0038088c,DAT_0038088c,local_2450);
        switch(iVar3) {
        case 0:
          *param_3 = local_1444;
          lVar4 = (long)param_3 + (8 - (long)((ulong)(param_3 + 4) & 0xfffffffffffffff8));
          *(undefined8 *)(param_3 + 0x400) = local_144c;
          param_3[1] = local_40;
          *(undefined8 *)(param_3 + 2) = local_2444[0];
          puVar6 = (undefined8 *)((long)local_2444 - lVar4);
          puVar7 = (undefined8 *)((ulong)(param_3 + 4) & 0xfffffffffffffff8);
          for (uVar5 = (ulong)((int)lVar4 + 0x1000U >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + (ulong)bVar8 * -2 + 1;
            puVar7 = puVar7 + (ulong)bVar8 * -2 + 1;
          }
          lVar4 = (long)param_3 + (0x1008 - (long)((ulong)(param_3 + 0x404) & 0xfffffffffffffff8));
          *(undefined8 *)(param_3 + 0x402) = local_1440[0];
          *(undefined8 *)(param_3 + 0x900) = local_48;
          puVar6 = (undefined8 *)((long)local_1440 - lVar4);
          puVar7 = (undefined8 *)((ulong)(param_3 + 0x404) & 0xfffffffffffffff8);
          for (uVar5 = (ulong)((int)lVar4 + 0x1400U >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + (ulong)bVar8 * -2 + 1;
            puVar7 = puVar7 + (ulong)bVar8 * -2 + 1;
          }
          return iVar3;
        case 3:
        case 0x66:
          goto switchD_001af09c_caseD_3;
        case 0xf:
          return iVar3;
        case 0x17:
        case 99:
          goto switchD_001af09c_caseD_17;
        case 0x1a:
          goto switchD_001af09c_caseD_1a;
        case 0x1b:
          goto switchD_001af09c_caseD_1b;
        case 0x1f:
        case 0x3b:
        case 0x54:
          goto switchD_001af09c_caseD_1f;
        case 0x51:
          goto switchD_001af09c_caseD_51;
        case 0x55:
          goto switchD_001af09c_caseD_55;
        case 0x56:
          goto switchD_001af09c_caseD_56;
        case 0x59:
          goto switchD_001af09c_caseD_59;
        case 0x62:
          goto switchD_001af09c_caseD_62;
        }
        goto switchD_001af09c_caseD_1;
      }
    }
    (**(code **)(lVar4 + 0x28))(DAT_0038088c,DAT_0038088c,local_2450);
    if (1 < DAT_01216a78) {
      fVar9 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"dmal/common/common_cc.c",0x183,
                   "cDeviceGetConfComputeGpuCertificate",0x183,iVar3);
    }
    break;
  default:
switchD_001af09c_caseD_1:
    iVar3 = 999;
    break;
  case 3:
  case 0x66:
switchD_001af09c_caseD_3:
    return 10;
  case 0xf:
    break;
  case 0x17:
  case 99:
switchD_001af09c_caseD_17:
    return 0x13;
  case 0x1a:
switchD_001af09c_caseD_1a:
    return 0x17;
  case 0x1b:
switchD_001af09c_caseD_1b:
    return 4;
  case 0x1f:
  case 0x3b:
  case 0x54:
switchD_001af09c_caseD_1f:
    return 2;
  case 0x51:
switchD_001af09c_caseD_51:
    return 0x14;
  case 0x55:
switchD_001af09c_caseD_55:
    return 0x1b;
  case 0x56:
switchD_001af09c_caseD_56:
    return 3;
  case 0x59:
switchD_001af09c_caseD_59:
    return 0x11;
  case 0x62:
switchD_001af09c_caseD_62:
    iVar3 = 0x10;
  }
  return iVar3;
}


// ===== 001af360 FUN_001af360 =====

uint FUN_001af360(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  long lVar4;
  float fVar5;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 local_48 [16];
  undefined8 local_38;
  
  lVar4 = *(long *)(param_1 + 0x10);
  local_38 = 0;
  local_54 = 0;
  local_48 = (undefined1  [16])0x0;
  uVar3 = FUN_001ae9c0(lVar4,&local_50,&local_54);
  switch(uVar3) {
  case 0:
    lVar1 = *(long *)(param_2 + 0x256d8);
    if (((lVar1 == 0) || (*(undefined8 **)(lVar1 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar2 = (code *)**(undefined8 **)(lVar1 + 0x50), pcVar2 == (code *)0x0)) {
      uVar3 = 3;
    }
    else {
      uVar3 = (*pcVar2)(lVar1,param_2,0x2080,&local_4c);
      if (uVar3 == 0) {
        local_48._0_4_ = local_4c;
        local_38 = param_3;
        uVar3 = FUN_0019c780(lVar4,DAT_0038088c,local_50,0xcb330107,local_48,0x18,0);
        (**(code **)(lVar4 + 0x28))(DAT_0038088c,DAT_0038088c,local_50);
        if (0x66 < uVar3) {
          return 999;
        }
        return (uint)*(ushort *)(&DAT_002b2020 + (ulong)uVar3 * 2);
      }
    }
    (**(code **)(lVar4 + 0x28))(DAT_0038088c,DAT_0038088c,local_50);
    if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"dmal/common/common_cc.c",0x15c,
                   "cDeviceSetConfComputeUnprotectedMemSize",0x15c,uVar3);
    }
    break;
  default:
    uVar3 = 999;
    break;
  case 3:
  case 0x66:
    uVar3 = 10;
    break;
  case 0xf:
    break;
  case 0x17:
  case 99:
    uVar3 = 0x13;
    break;
  case 0x1a:
    uVar3 = 0x17;
    break;
  case 0x1b:
    uVar3 = 4;
    break;
  case 0x1f:
  case 0x3b:
  case 0x54:
    uVar3 = 2;
    break;
  case 0x51:
    uVar3 = 0x14;
    break;
  case 0x55:
    uVar3 = 0x1b;
    break;
  case 0x56:
    uVar3 = 3;
    break;
  case 0x59:
    uVar3 = 0x11;
    break;
  case 0x62:
    uVar3 = 0x10;
  }
  return uVar3;
}


// ===== 001af5a0 FUN_001af5a0 =====

int FUN_001af5a0(long param_1,long param_2,undefined8 *param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 local_48 [16];
  undefined8 local_38;
  
  lVar4 = *(long *)(param_1 + 0x10);
  local_38 = 0;
  local_54 = 0;
  local_48 = (undefined1  [16])0x0;
  iVar3 = FUN_001ae9c0(lVar4,&local_50,&local_54);
  switch(iVar3) {
  case 0:
    lVar1 = *(long *)(param_2 + 0x256d8);
    if (((lVar1 == 0) || (*(undefined8 **)(lVar1 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar2 = (code *)**(undefined8 **)(lVar1 + 0x50), pcVar2 == (code *)0x0)) {
      iVar3 = 3;
    }
    else {
      iVar3 = (*pcVar2)(lVar1,param_2,0x2080,&local_4c);
      if (iVar3 == 0) {
        local_48._0_4_ = local_4c;
        iVar3 = FUN_0019c780(lVar4,DAT_0038088c,local_50,0xcb330106,local_48,0x18,0);
        (**(code **)(lVar4 + 0x28))(DAT_0038088c,DAT_0038088c,local_50);
        switch(iVar3) {
        case 0:
          *param_3 = local_48._8_8_;
          param_3[1] = local_38;
          return iVar3;
        case 3:
        case 0x66:
          goto switchD_001af5f8_caseD_3;
        case 0xf:
          return iVar3;
        case 0x17:
        case 99:
          goto switchD_001af5f8_caseD_17;
        case 0x1a:
          goto switchD_001af5f8_caseD_1a;
        case 0x1b:
          goto switchD_001af5f8_caseD_1b;
        case 0x1f:
        case 0x3b:
        case 0x54:
          goto switchD_001af5f8_caseD_1f;
        case 0x51:
          goto switchD_001af5f8_caseD_51;
        case 0x55:
          goto switchD_001af5f8_caseD_55;
        case 0x56:
          goto switchD_001af5f8_caseD_56;
        case 0x59:
          goto switchD_001af5f8_caseD_59;
        case 0x62:
          goto switchD_001af5f8_caseD_62;
        }
        goto switchD_001af5f8_caseD_1;
      }
    }
    (**(code **)(lVar4 + 0x28))(DAT_0038088c,DAT_0038088c,local_50);
    if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"dmal/common/common_cc.c",0x134,"cDeviceGetConfComputeMemSizeInfo",
                   0x134,iVar3);
    }
    break;
  default:
switchD_001af5f8_caseD_1:
    iVar3 = 999;
    break;
  case 3:
  case 0x66:
switchD_001af5f8_caseD_3:
    return 10;
  case 0xf:
    break;
  case 0x17:
  case 99:
switchD_001af5f8_caseD_17:
    return 0x13;
  case 0x1a:
switchD_001af5f8_caseD_1a:
    return 0x17;
  case 0x1b:
switchD_001af5f8_caseD_1b:
    return 4;
  case 0x1f:
  case 0x3b:
  case 0x54:
switchD_001af5f8_caseD_1f:
    return 2;
  case 0x51:
switchD_001af5f8_caseD_51:
    return 0x14;
  case 0x55:
switchD_001af5f8_caseD_55:
    return 0x1b;
  case 0x56:
switchD_001af5f8_caseD_56:
    return 3;
  case 0x59:
switchD_001af5f8_caseD_59:
    return 0x11;
  case 0x62:
switchD_001af5f8_caseD_62:
    iVar3 = 0x10;
  }
  return iVar3;
}


// ===== 001af820 FUN_001af820 =====

undefined4 FUN_001af820(long param_1,uint *param_2)

{
  long lVar1;
  undefined4 uVar2;
  byte local_31;
  undefined4 local_30;
  undefined4 local_2c;
  
  lVar1 = *(long *)(param_1 + 0x10);
  local_31 = 0;
  local_30 = 0;
  uVar2 = FUN_001ae9c0(lVar1,&local_2c,&local_30);
  switch(uVar2) {
  case 0:
    uVar2 = FUN_0019c780(lVar1,DAT_0038088c,local_2c,0xcb330104,&local_31,1,0);
    (**(code **)(lVar1 + 0x28))(DAT_0038088c,DAT_0038088c,local_2c);
    switch(uVar2) {
    case 0:
      *param_2 = (uint)local_31;
      break;
    default:
      goto switchD_001af86d_caseD_1;
    case 3:
    case 0x66:
      goto switchD_001af86d_caseD_3;
    case 0xf:
      break;
    case 0x17:
    case 99:
      goto switchD_001af86d_caseD_17;
    case 0x1a:
      goto switchD_001af86d_caseD_1a;
    case 0x1b:
      goto switchD_001af86d_caseD_1b;
    case 0x1f:
    case 0x3b:
    case 0x54:
      goto switchD_001af86d_caseD_1f;
    case 0x51:
      goto switchD_001af86d_caseD_51;
    case 0x55:
      goto switchD_001af86d_caseD_55;
    case 0x56:
      goto switchD_001af86d_caseD_56;
    case 0x59:
      goto switchD_001af86d_caseD_59;
    case 0x62:
      goto switchD_001af86d_caseD_62;
    }
    break;
  default:
switchD_001af86d_caseD_1:
    uVar2 = 999;
    break;
  case 3:
  case 0x66:
switchD_001af86d_caseD_3:
    return 10;
  case 0xf:
    break;
  case 0x17:
  case 99:
switchD_001af86d_caseD_17:
    return 0x13;
  case 0x1a:
switchD_001af86d_caseD_1a:
    return 0x17;
  case 0x1b:
switchD_001af86d_caseD_1b:
    return 4;
  case 0x1f:
  case 0x3b:
  case 0x54:
switchD_001af86d_caseD_1f:
    return 2;
  case 0x51:
switchD_001af86d_caseD_51:
    return 0x14;
  case 0x55:
switchD_001af86d_caseD_55:
    return 0x1b;
  case 0x56:
switchD_001af86d_caseD_56:
    return 3;
  case 0x59:
switchD_001af86d_caseD_59:
    return 0x11;
  case 0x62:
switchD_001af86d_caseD_62:
    uVar2 = 0x10;
  }
  return uVar2;
}


// ===== 001af990 FUN_001af990 =====

ulong FUN_001af990(long param_1,undefined1 param_2)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  undefined1 local_31;
  undefined4 local_30;
  undefined4 local_2c [3];
  
  lVar1 = *(long *)(param_1 + 0x10);
  local_31 = 0;
  local_30 = 0;
  uVar3 = FUN_001ae9c0(lVar1,local_2c,&local_30);
  switch(uVar3 & 0xffffffff) {
  case 0:
    local_31 = param_2;
    uVar2 = FUN_0019c780(lVar1,DAT_0038088c,local_2c[0],0xcb330105,&local_31,1,0);
    (**(code **)(lVar1 + 0x28))(DAT_0038088c,DAT_0038088c,local_2c[0]);
    uVar3 = 999;
    if (uVar2 < 0x67) {
      uVar3 = (ulong)*(ushort *)(&DAT_002b2020 + (ulong)uVar2 * 2);
    }
    break;
  default:
    uVar3 = 999;
    break;
  case 3:
  case 0x66:
    uVar3 = 10;
    break;
  case 0xf:
    break;
  case 0x17:
  case 99:
    uVar3 = 0x13;
    break;
  case 0x1a:
    uVar3 = 0x17;
    break;
  case 0x1b:
    uVar3 = 4;
    break;
  case 0x1f:
  case 0x3b:
  case 0x54:
    uVar3 = 2;
    break;
  case 0x51:
    uVar3 = 0x14;
    break;
  case 0x55:
    uVar3 = 0x1b;
    break;
  case 0x56:
    uVar3 = 3;
    break;
  case 0x59:
    uVar3 = 0x11;
    break;
  case 0x62:
    uVar3 = 0x10;
  }
  return uVar3;
}


// ===== 001afac0 FUN_001afac0 =====

ulong FUN_001afac0(long param_1)

{
  uint uVar1;
  ulong uVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_2e;
  undefined2 local_2a;
  
  local_2e = 0;
  local_2a = 0;
  local_38 = 0;
  uVar1 = FUN_001ae9c0(param_1,&local_34,&local_38);
  if (uVar1 < 0x67) {
    uVar2 = (ulong)uVar1;
    switch(uVar1) {
    case 0:
      uVar1 = FUN_0019c780(param_1,DAT_0038088c,local_34,0xcb330101,&local_2e,6,0);
      uVar2 = (ulong)uVar1;
      (**(code **)(param_1 + 0x28))(DAT_0038088c,DAT_0038088c,local_34);
      switch(uVar1) {
      case 0:
        if ((byte)local_2e < 5) {
                    /* WARNING: Could not recover jumptable at 0x001afc3f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar2 = (*(code *)((long)&switchD_001afc3f::switchdataD_002b200c +
                            (long)(int)(&switchD_001afc3f::switchdataD_002b200c)[(byte)local_2e]))()
          ;
          return uVar2;
        }
        break;
      default:
        goto switchD_001afb09_caseD_1;
      case 3:
      case 0x66:
        goto switchD_001afb09_caseD_3;
      case 0xf:
        goto switchD_001afb09_caseD_f;
      case 0x17:
      case 99:
        goto switchD_001afb09_caseD_17;
      case 0x1a:
        goto switchD_001afb09_caseD_1a;
      case 0x1b:
        goto switchD_001afb09_caseD_1b;
      case 0x1f:
      case 0x3b:
      case 0x54:
        goto switchD_001afb09_caseD_1f;
      case 0x51:
        goto switchD_001afb09_caseD_51;
      case 0x55:
        goto switchD_001afb09_caseD_55;
      case 0x56:
        break;
      case 0x59:
        goto switchD_001afb09_caseD_59;
      case 0x62:
        goto switchD_001afb09_caseD_62;
      }
    case 0x56:
      uVar2 = 3;
      break;
    default:
      goto switchD_001afb09_caseD_1;
    case 3:
    case 0x66:
switchD_001afb09_caseD_3:
      return 10;
    case 0xf:
      break;
    case 0x17:
    case 99:
switchD_001afb09_caseD_17:
      return 0x13;
    case 0x1a:
switchD_001afb09_caseD_1a:
      return 0x17;
    case 0x1b:
switchD_001afb09_caseD_1b:
      return 4;
    case 0x1f:
    case 0x3b:
    case 0x54:
switchD_001afb09_caseD_1f:
      return 2;
    case 0x51:
switchD_001afb09_caseD_51:
      return 0x14;
    case 0x55:
switchD_001afb09_caseD_55:
      return 0x1b;
    case 0x59:
switchD_001afb09_caseD_59:
      return 0x11;
    case 0x62:
switchD_001afb09_caseD_62:
      uVar2 = 0x10;
    }
  }
  else {
switchD_001afb09_caseD_1:
    uVar2 = 999;
  }
switchD_001afb09_caseD_f:
  return uVar2;
}


// ===== 001afdb0 FUN_001afdb0 =====

int FUN_001afdb0(long param_1,int *param_2)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  if (param_2 == (int *)0x0) {
    return 2;
  }
  iVar1 = 0x19;
  if (*param_2 == 0x1000014) {
    if (DAT_01215b84 == 0) {
      do {
        iVar1 = FUN_00291820(&DAT_01215b88,1,0);
      } while (iVar1 != 0);
      if (DAT_01215b84 == 0) {
        DAT_01215b8c = FUN_001afac0(*(undefined8 *)(param_1 + 0x10));
        DAT_01215b84 = 1;
      }
      FUN_00291830(&DAT_01215b88,0);
    }
    iVar1 = DAT_01215b8c;
    if (DAT_01215b8c == 0) {
      param_2[1] = DAT_01215b74;
      param_2[2] = DAT_01215b78;
      param_2[3] = DAT_01215b7c;
      param_2[4] = DAT_01215b80;
    }
    else if (1 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar2,"dmal/common/common_cc.c",0xdc,"cGetSystemConfComputeSettings",0xdc
                   ,iVar1);
    }
  }
  return iVar1;
}


// ===== 001aff40 FUN_001aff40 =====

int FUN_001aff40(long param_1,undefined4 *param_2)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  if (DAT_01215b84 == 0) {
    do {
      iVar1 = FUN_00291820(&DAT_01215b88,1,0);
    } while (iVar1 != 0);
    if (DAT_01215b84 == 0) {
      DAT_01215b8c = FUN_001afac0(*(undefined8 *)(param_1 + 0x10));
      DAT_01215b84 = 1;
    }
    FUN_00291830(&DAT_01215b88,0);
  }
  iVar1 = DAT_01215b8c;
  if (DAT_01215b8c == 0) {
    *param_2 = DAT_01215b74;
    param_2[1] = DAT_01215b78;
    param_2[2] = DAT_01215b7c;
  }
  else if (1 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar2,"dmal/common/common_cc.c",0xb7,"cSystemGetConfComputeState",0xb7,
                 iVar1);
    return iVar1;
  }
  return iVar1;
}


// ===== 001b0090 FUN_001b0090 =====

int FUN_001b0090(long param_1,undefined4 *param_2)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  if (DAT_01215b84 == 0) {
    do {
      iVar1 = FUN_00291820(&DAT_01215b88,1,0);
    } while (iVar1 != 0);
    if (DAT_01215b84 == 0) {
      DAT_01215b8c = FUN_001afac0(*(undefined8 *)(param_1 + 0x10));
      DAT_01215b84 = 1;
    }
    FUN_00291830(&DAT_01215b88,0);
  }
  iVar1 = DAT_01215b8c;
  if (DAT_01215b8c == 3) {
    return 0;
  }
  if (DAT_01215b8c == 0) {
    *param_2 = DAT_01215b6c;
    param_2[1] = DAT_01215b70;
  }
  else if (1 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar2,"dmal/common/common_cc.c",0xa3,"cSystemGetConfComputeCapabilities",
                 0xa3,iVar1);
    return iVar1;
  }
  return iVar1;
}


// ===== 001b01f0 FUN_001b01f0 =====

int FUN_001b01f0(uint param_1,long param_2,int param_3,int param_4)

{
  uint *puVar1;
  uint uVar2;
  undefined8 uVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  
  uVar3 = FUN_00234e30();
  if (param_4 < param_3) {
    return 0;
  }
  iVar6 = 0;
  puVar1 = (uint *)(param_2 + 0x28 + ((ulong)(uint)(param_4 - param_3) + (long)param_3) * 0x28);
  puVar4 = (uint *)(param_2 + (long)param_3 * 0x28);
  do {
    while (uVar2 = *puVar4, uVar2 < 0xad) {
      if (0xa9 < uVar2) goto LAB_001b0266;
LAB_001b0248:
      puVar4 = puVar4 + 10;
      if (puVar4 == puVar1) {
        return iVar6;
      }
    }
    if (3 < uVar2 - 0xe7) goto LAB_001b0248;
LAB_001b0266:
    *(undefined8 *)(puVar4 + 2) = uVar3;
    puVar5 = puVar4 + 10;
    iVar6 = iVar6 + 1;
    puVar4[4] = 0;
    puVar4[5] = 0;
    puVar4[8] = 0;
    puVar4[6] = 1;
    puVar4[7] = param_1;
    puVar4 = puVar5;
    if (puVar5 == puVar1) {
      return iVar6;
    }
  } while( true );
}


// ===== 001b02b0 FUN_001b02b0 =====

int FUN_001b02b0(long param_1,long param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  undefined4 local_4c;
  undefined4 local_48;
  undefined8 uStack_44;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  
  if (*(int *)(param_2 + 0x25d24) != 0) goto LAB_001b0319;
  do {
    iVar3 = FUN_00291820(param_2 + 0x25d28,1,0);
  } while (iVar3 != 0);
  if (*(int *)(param_2 + 0x25d24) == 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x10);
    uStack_38 = 0;
    uStack_34 = 0;
    local_30 = 0;
    local_48 = 0;
    uStack_44 = 0;
    uStack_3c = 0;
    lVar4 = *(long *)(param_2 + 0x256d8);
    *(undefined8 *)(param_2 + 0x25d18) = 0;
    *(undefined4 *)(param_2 + 0x25d20) = 0;
    *(undefined1 (*) [16])(param_2 + 0x25d08) = (undefined1  [16])0x0;
    if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
      iVar3 = 3;
LAB_001b0445:
      if (1 < DAT_01216a78) {
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                     "ERROR",lVar4,"dmal/common/common_c2c.c",0x1a,
                     "deviceGetC2cLinkStaticInfoUncached",0x1a,iVar3);
      }
    }
    else {
      iVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_4c);
      if (iVar3 != 0) goto LAB_001b0445;
      iVar3 = FUN_0019c780(uVar1,DAT_0038088c,local_4c,0x2080182b,&local_48,0x1c,0);
      switch(iVar3) {
      case 0:
        *(char *)(param_2 + 0x25d08) = (char)local_48;
        if ((char)local_48 != '\0') {
          *(undefined8 *)(param_2 + 0x25d0c) = uStack_44;
          *(ulong *)(param_2 + 0x25d14) = CONCAT44(uStack_38,uStack_3c);
          *(ulong *)(param_2 + 0x25d1c) = CONCAT44(local_30,uStack_34);
        }
        break;
      default:
        iVar3 = 999;
        break;
      case 3:
      case 0x66:
        iVar3 = 10;
        break;
      case 0xf:
        break;
      case 0x17:
      case 99:
        iVar3 = 0x13;
        break;
      case 0x1a:
        iVar3 = 0x17;
        break;
      case 0x1b:
        iVar3 = 4;
        break;
      case 0x1f:
      case 0x3b:
      case 0x54:
        iVar3 = 2;
        break;
      case 0x51:
        iVar3 = 0x14;
        break;
      case 0x55:
        iVar3 = 0x1b;
        break;
      case 0x56:
        iVar3 = 3;
        break;
      case 0x59:
        iVar3 = 0x11;
        break;
      case 0x62:
        iVar3 = 0x10;
      }
    }
    *(int *)(param_2 + 0x25d2c) = iVar3;
    *(undefined4 *)(param_2 + 0x25d24) = 1;
  }
  FUN_00291830(param_2 + 0x25d28,0);
LAB_001b0319:
  iVar3 = *(int *)(param_2 + 0x25d2c);
  if ((iVar3 != 0) && (1 < DAT_01216a78)) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_c2c.c",0x38,"deviceGetC2cLinkStaticInfo",0x38,
                 iVar3);
    return iVar3;
  }
  return iVar3;
}


// ===== 001b05d0 FUN_001b05d0 =====

int FUN_001b05d0(undefined8 param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  iVar1 = FUN_001b02b0(param_1,param_2);
  if (iVar1 == 0) {
    *param_3 = 0;
    if (*(char *)(param_2 + 0x25d08) != '\0') {
      *param_3 = *(undefined4 *)(param_2 + 0x25d10);
    }
  }
  else if (1 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar2,"dmal/common/common_c2c.c",0x5b,"deviceGetC2cMaxLinkCount",0x5b,iVar1
                );
    return iVar1;
  }
  return iVar1;
}


// ===== 001b06b0 FUN_001b06b0 =====

int FUN_001b06b0(undefined8 param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  float fVar6;
  uint local_2c;
  
  iVar2 = FUN_001b05d0(param_1,param_2,&local_2c);
  if (iVar2 == 0) {
    if (local_2c <= param_3) {
      return 2;
    }
    uVar5 = 0;
    uVar1 = 0;
    do {
      uVar4 = uVar1;
      uVar5 = (uVar5 + 1) - (uint)((1 << ((byte)uVar4 & 0x1f) & *(uint *)(param_2 + 0x25d14)) == 0);
      if (0x1f < uVar4 + 1) {
        if (uVar5 <= param_3) {
          return 3;
        }
        break;
      }
      uVar1 = uVar4 + 1;
    } while (uVar5 <= param_3);
    *param_4 = uVar4;
  }
  else if (1 < DAT_01216a78) {
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar3,"dmal/common/common_c2c.c",0x86,
                 "deviceConvertC2cApiLinkIndexToRmLinkIndex",0x86,iVar2);
    return iVar2;
  }
  return iVar2;
}


// ===== 001b0800 FUN_001b0800 =====

int FUN_001b0800(undefined8 param_1,char *param_2,uint *param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 uVar5;
  float fVar6;
  undefined8 uVar7;
  
  if ((param_2 == (char *)0x0) ||
     ((*param_2 != '\x01' &&
      ((((*(int *)(param_2 + 0x14) == 0 || (*(int *)(param_2 + 0x1c) != 0)) ||
        (*(int *)(param_2 + 0x10) == 0)) || (*(long *)(param_2 + 0x20) == 0)))))) {
    iVar2 = 2;
LAB_001b098f:
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    fVar6 = fVar6 * DAT_00298548;
    uVar7 = 0x27f;
    uVar5 = 0x27f;
LAB_001b09d9:
    FUN_002340f0((double)fVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
                 "dmal/common/common_c2c.c",uVar5,"cDeviceGetC2cModeInfo",uVar7,iVar2);
  }
  else {
    if (*(int *)(param_2 + 0x71c) == 0) {
      do {
        iVar2 = FUN_00291820(param_2 + 0x720,1,0);
      } while (iVar2 != 0);
      if (*(int *)(param_2 + 0x71c) == 0) {
        lVar4 = *(long *)(param_2 + 0x256d8);
        uVar3 = 3;
        if (((lVar4 != 0) && (*(long *)(lVar4 + 0x20) != 0)) &&
           (pcVar1 = *(code **)(*(long *)(lVar4 + 0x20) + 0x98), pcVar1 != (code *)0x0)) {
          uVar3 = (*pcVar1)(lVar4,param_2,param_2 + 0x708);
        }
        *(undefined4 *)(param_2 + 0x724) = uVar3;
        param_2[0x71c] = '\x01';
        param_2[0x71d] = '\0';
        param_2[0x71e] = '\0';
        param_2[0x71f] = '\0';
      }
      FUN_00291830(param_2 + 0x720,0);
    }
    if (*(int *)(param_2 + 0x724) == 0) {
      if (4 < DAT_01216a78) {
        uVar3 = *(undefined4 *)(param_2 + 0x708);
        fVar6 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar6 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tisArchOrNewer called: %d %d\n","DEBUG",
                     lVar4,"/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h",0x3d,
                     0xc,uVar3);
      }
      if (0xb < *(uint *)(param_2 + 0x708)) {
        iVar2 = FUN_001b02b0(param_1,param_2);
        if (iVar2 == 0) {
          *param_3 = (uint)(byte)param_2[0x25d08];
          return 0;
        }
        if (DAT_01216a78 < 2) {
          return iVar2;
        }
        fVar6 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        fVar6 = fVar6 * DAT_00298548;
        uVar7 = 0x286;
        uVar5 = 0x286;
        goto LAB_001b09d9;
      }
    }
    else {
      if (*(int *)(param_2 + 0x724) == 0xf) {
        iVar2 = 0xf;
        if (4 < DAT_01216a78) {
          fVar6 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar6 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tisArchOrNewer error: %d\n","DEBUG",lVar4,
                       "/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h",0x42,0xc);
        }
        goto LAB_001b098f;
      }
      if (1 < DAT_01216a78) {
        fVar6 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar6 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tFailure to determine Architecture\n",
                     "ERROR",lVar4,"/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h"
                     ,0x46);
      }
    }
    iVar2 = 3;
  }
  return iVar2;
}


// ===== 001b0b80 FUN_001b0b80 =====

int FUN_001b0b80(undefined8 param_1,long param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  byte bVar4;
  float fVar5;
  
  *param_3 = 0;
  iVar1 = FUN_001b02b0(param_1,param_2);
  if (iVar1 == 0) {
    bVar4 = 0;
    for (uVar2 = *(uint *)(param_2 + 0x25d14); uVar2 != 0; uVar2 = uVar2 >> 1) {
      if ((uVar2 & 1) != 0) {
        *param_3 = *param_3 | 1 << (bVar4 & 0x1f);
      }
      bVar4 = bVar4 + 1;
    }
  }
  else if (1 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar3,"dmal/common/common_c2c.c",0x72,"deviceGetC2cLinkActiveMask",0x72,
                 iVar1);
    return iVar1;
  }
  return iVar1;
}


// ===== 001b0c70 FUN_001b0c70 =====

undefined8 FUN_001b0c70(long param_1,long param_2,long param_3,int param_4,int param_5)

{
  uint uVar1;
  code *pcVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  long lVar10;
  long lVar11;
  uint *puVar12;
  long lVar13;
  ulong uVar14;
  ulong *puVar15;
  undefined8 *puVar16;
  undefined8 uVar17;
  char *pcVar18;
  uint *puVar19;
  byte bVar20;
  float fVar21;
  double dVar22;
  undefined8 uVar23;
  long local_120;
  uint local_114;
  uint local_110;
  uint local_f0;
  uint local_ec;
  ulong local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined1 local_a8 [16];
  undefined1 local_98 [16];
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  bVar20 = 0;
  local_f0 = 0;
  if (param_5 < param_4) {
    bVar3 = false;
  }
  else {
    bVar3 = false;
    piVar9 = (int *)(param_3 + (long)param_4 * 0x28);
    do {
      if (*piVar9 == 0xea) {
        bVar3 = true;
      }
      piVar9 = piVar9 + 10;
    } while (piVar9 != (int *)(param_3 + 0x28 +
                              ((ulong)(uint)(param_5 - param_4) + (long)param_4) * 0x28));
  }
  lVar10 = FUN_00234e30();
  iVar5 = FUN_001b02b0(param_1,param_2);
  if (iVar5 == 0) {
    if ((*(char *)(param_2 + 0x25d08) == '\0') || (uVar1 = *(uint *)(param_2 + 0x25d0c), uVar1 == 0)
       ) goto joined_r0x001b0e99;
    iVar5 = FUN_001b05d0(param_1,param_2,&local_f0);
    uVar7 = local_f0;
    if ((iVar5 == 0) && (local_f0 != 0)) {
      local_114 = 3;
      local_110 = 0;
      if (bVar3) {
        puVar15 = &local_e8;
        for (lVar11 = 0xb; lVar11 != 0; lVar11 = lVar11 + -1) {
          *puVar15 = 0;
          puVar15 = puVar15 + (ulong)bVar20 * -2 + 1;
        }
        lVar11 = *(long *)(param_2 + 0x256d8);
        if (((lVar11 == 0) || (*(undefined8 **)(lVar11 + 0x50) == (undefined8 *)0x0)) ||
           (pcVar2 = (code *)**(undefined8 **)(lVar11 + 0x50), pcVar2 == (code *)0x0)) {
          local_114 = 3;
        }
        else {
          local_114 = (*pcVar2)(lVar11,param_2,0x2080);
          if (local_114 == 0) {
            uVar7 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_ec,0x20801831,
                                 &local_e8,0x58,0);
            switch(uVar7) {
            case 0:
              local_114 = local_a8._8_4_;
              if (local_a8._8_4_ == 0) {
                local_110 = 0;
              }
              else if (local_a8._8_4_ - 1 < 2) {
                local_110 = 1;
                local_114 = uVar7;
              }
              else {
                local_114 = 2;
                local_110 = uVar7;
              }
              break;
            default:
              local_110 = 0;
              local_114 = 999;
              break;
            case 3:
            case 0x66:
              local_110 = 0;
              local_114 = 10;
              break;
            case 0xf:
              local_110 = 0;
              local_114 = uVar7;
              break;
            case 0x17:
            case 99:
              local_110 = 0;
              local_114 = 0x13;
              break;
            case 0x1a:
              local_110 = 0;
              local_114 = 0x17;
              break;
            case 0x1b:
              local_110 = 0;
              local_114 = 4;
              break;
            case 0x1f:
            case 0x3b:
            case 0x54:
              local_110 = 0;
              local_114 = 2;
              break;
            case 0x51:
              local_110 = 0;
              local_114 = 0x14;
              break;
            case 0x55:
              local_110 = 0;
              local_114 = 0x1b;
              break;
            case 0x56:
              local_110 = 0;
              local_114 = 3;
              break;
            case 0x59:
              local_110 = 0;
              local_114 = 0x11;
              break;
            case 0x62:
              local_110 = 0;
              local_114 = 0x10;
            }
            goto LAB_001b0db7;
          }
        }
        if (1 < DAT_01216a78) {
          fVar21 = (float)FUN_002917b0(&DAT_01216a60);
          lVar11 = syscall(0xba);
          FUN_002340f0((double)(fVar21 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar11,
                       "dmal/common/common_c2c.c",0x18b,"cDeviceGetC2cLinkPowerState",0x18b,
                       local_114);
        }
      }
LAB_001b0db7:
      lVar11 = FUN_00234e30();
      uVar7 = local_f0;
      if (local_f0 < uVar1) {
        if (4 < DAT_01216a78) {
          fVar21 = (float)FUN_002917b0(&DAT_01216a60);
          lVar10 = syscall(0xba);
          FUN_002340f0((double)(fVar21 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %x\n",
                       "DEBUG",lVar10,"dmal/common/common_c2c.c",0x1f0,uVar1,uVar7);
        }
        FUN_001b01f0(999,param_3,param_4,param_5);
        return 0;
      }
      uVar17 = FUN_00234e30();
      if (param_5 < param_4) {
        return 0;
      }
      iVar5 = 0;
      puVar19 = (uint *)(param_3 + (long)param_4 * 0x28);
      puVar12 = puVar19;
      do {
        uVar7 = *puVar12;
        if (uVar7 < 0xad) {
          if (0xa9 < uVar7) goto LAB_001b0ff6;
        }
        else if (uVar7 - 0xe7 < 4) {
LAB_001b0ff6:
          *(undefined8 *)(puVar12 + 2) = uVar17;
          iVar5 = iVar5 + 1;
          puVar12[4] = 0;
          puVar12[5] = 0;
          puVar12[8] = 0;
          puVar12[6] = 1;
          puVar12[7] = 0;
        }
        puVar12 = puVar12 + 10;
      } while (puVar12 !=
               (uint *)(param_3 + 0x28 + ((ulong)(uint)(param_5 - param_4) + (long)param_4) * 0x28))
      ;
      lVar10 = (lVar11 - lVar10) / (long)iVar5;
      do {
        uVar7 = *puVar19;
        lVar13 = lVar10;
        if (uVar7 == 0xac) {
          if (puVar19[1] < uVar1) {
            local_120 = FUN_00234e30();
            local_ec = 0;
            uVar7 = puVar19[1];
            local_e8 = local_e8 & 0xffffffff00000000;
            uVar8 = FUN_001b0b80(param_1,param_2,&local_ec);
            if (uVar8 == 0) {
              uVar8 = FUN_001b06b0(param_1,param_2,uVar7,&local_e8);
              uVar14 = local_e8;
              if (uVar8 == 0) {
                if (4 < DAT_01216a78) {
                  fVar21 = (float)FUN_002917b0(&DAT_01216a60);
                  lVar11 = syscall(0xba);
                  FUN_002340f0((double)(fVar21 * DAT_00298548),
                               "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u\n","DEBUG",lVar11,
                               "dmal/common/common_c2c.c",0xdb,uVar7,uVar14 & 0xffffffff);
                }
                uVar14 = local_e8;
                if ((local_ec >> ((uint)local_e8 & 0x1f) & 1) == 0) {
                  uVar8 = 3;
                }
                else {
                  uVar7 = *(uint *)(param_2 + 0x25d18);
                  puVar19[8] = uVar7;
                  if (4 < DAT_01216a78) {
                    fVar21 = (float)FUN_002917b0(&DAT_01216a60);
                    lVar11 = syscall(0xba);
                    FUN_002340f0((double)(fVar21 * DAT_00298548),
                                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u\n","DEBUG",lVar11,
                                 "dmal/common/common_c2c.c",0xe5,uVar14 & 0xffffffff,uVar7);
                  }
                }
              }
              else if (1 < DAT_01216a78) {
                fVar21 = (float)FUN_002917b0(&DAT_01216a60);
                lVar11 = syscall(0xba);
                pcVar18 = "deviceGetC2cLinkMaxSpeed";
                uVar23 = 0xd9;
                uVar17 = 0xd9;
                dVar22 = (double)(fVar21 * DAT_00298548);
                goto LAB_001b15ac;
              }
            }
            else if (1 < DAT_01216a78) {
              fVar21 = (float)FUN_002917b0(&DAT_01216a60);
              lVar11 = syscall(0xba);
              pcVar18 = "deviceGetC2cLinkMaxSpeed";
              uVar23 = 0xd3;
              uVar17 = 0xd3;
              dVar22 = (double)(fVar21 * DAT_00298548);
LAB_001b15ac:
              FUN_002340f0(dVar22,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar11,
                           "dmal/common/common_c2c.c",uVar17,pcVar18,uVar23,uVar8);
            }
LAB_001b12f7:
            puVar19[7] = uVar8;
            lVar11 = FUN_00234e30();
            lVar13 = (lVar11 - local_120) + lVar10;
          }
          else {
LAB_001b1062:
            puVar19[7] = 3;
          }
LAB_001b1071:
          *(long *)(puVar19 + 4) = lVar13;
          *(long *)(puVar19 + 2) = lVar11;
        }
        else if (uVar7 < 0xad) {
          if (uVar7 == 0xaa) {
            *(long *)(puVar19 + 2) = lVar11;
            puVar19[8] = uVar1;
            *(long *)(puVar19 + 4) = lVar10;
          }
          else if (uVar7 == 0xab) {
            if (uVar1 <= puVar19[1]) goto LAB_001b1062;
            local_120 = FUN_00234e30();
            local_ec = 0;
            uVar7 = puVar19[1];
            local_e8 = local_e8 & 0xffffffff00000000;
            uVar8 = FUN_001b0b80(param_1,param_2,&local_ec);
            if (uVar8 == 0) {
              uVar8 = FUN_001b06b0(param_1,param_2,uVar7,&local_e8);
              uVar14 = local_e8;
              if (uVar8 == 0) {
                if (DAT_01216a78 < 5) {
                  puVar19[8] = local_ec >> ((byte)local_e8 & 0x1f) & 1;
                }
                else {
                  fVar21 = (float)FUN_002917b0(&DAT_01216a60);
                  uVar17 = 0x1b1c96;
                  lVar11 = syscall(0xba);
                  FUN_002340f0((double)(fVar21 * DAT_00298548),
                               "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u\n","DEBUG",lVar11,
                               "dmal/common/common_c2c.c",0xb5,uVar7,uVar14 & 0xffffffff);
                  uVar14 = local_e8;
                  uVar7 = local_ec;
                  iVar5 = DAT_01216a78;
                  uVar6 = local_ec >> ((byte)local_e8 & 0x1f) & 1;
                  puVar19[8] = uVar6;
                  if (4 < iVar5) {
                    fVar21 = (float)FUN_002917b0(&DAT_01216a60,local_ec,uVar17);
                    lVar11 = syscall(0xba);
                    FUN_002340f0((double)(DAT_00298548 * fVar21),
                                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u %x\n","DEBUG",lVar11,
                                 "dmal/common/common_c2c.c",0xc0,uVar14 & 0xffffffff,uVar6,uVar7);
                  }
                }
              }
              else if (1 < DAT_01216a78) {
                fVar21 = (float)FUN_002917b0(&DAT_01216a60);
                lVar11 = syscall(0xba);
                pcVar18 = "deviceGetC2cLinkState";
                uVar23 = 0xb3;
                uVar17 = 0xb3;
                dVar22 = (double)(fVar21 * DAT_00298548);
                goto LAB_001b15ac;
              }
            }
            else if (1 < DAT_01216a78) {
              fVar21 = (float)FUN_002917b0(&DAT_01216a60);
              lVar11 = syscall(0xba);
              pcVar18 = "deviceGetC2cLinkState";
              uVar23 = 0xad;
              uVar17 = 0xad;
              dVar22 = (double)(fVar21 * DAT_00298548);
              goto LAB_001b15ac;
            }
            goto LAB_001b12f7;
          }
        }
        else if (uVar7 < 0xea) {
          if (0xe6 < uVar7) {
            if (uVar1 <= puVar19[1]) goto LAB_001b1062;
            lVar13 = FUN_00234e30();
            uVar7 = *puVar19;
            uVar8 = puVar19[1];
            lVar11 = FUN_00234e30();
            if (lVar11 - *(long *)(param_2 + 0x74808) < 10000) {
LAB_001b10fe:
              local_e8 = *(ulong *)(param_2 + 0x74808);
              uStack_e0 = *(undefined8 *)(param_2 + 0x74810);
              local_d8 = *(undefined8 *)(param_2 + 0x74818);
              uStack_d0 = *(undefined8 *)(param_2 + 0x74820);
              local_c8 = *(undefined8 *)(param_2 + 0x74828);
              uStack_c0 = *(undefined8 *)(param_2 + 0x74830);
              local_b8 = *(undefined8 *)(param_2 + 0x74838);
              uStack_b0 = *(undefined8 *)(param_2 + 0x74840);
              local_a8 = *(undefined1 (*) [16])(param_2 + 0x74848);
              local_98 = *(undefined1 (*) [16])(param_2 + 0x74858);
              local_88 = *(undefined8 *)(param_2 + 0x74868);
              uStack_80 = *(undefined8 *)(param_2 + 0x74870);
              local_78 = *(undefined8 *)(param_2 + 0x74878);
              uStack_70 = *(undefined8 *)(param_2 + 0x74880);
              local_68 = *(undefined8 *)(param_2 + 0x74888);
              uStack_60 = *(undefined8 *)(param_2 + 0x74890);
              local_58 = *(undefined8 *)(param_2 + 0x74898);
              uStack_50 = *(undefined8 *)(param_2 + 0x748a0);
              local_48 = *(undefined8 *)(param_2 + 0x748a8);
              uStack_40 = *(undefined8 *)(param_2 + 0x748b0);
              uVar6 = FUN_001b06b0(param_1,param_2,uVar8,&local_ec);
              uVar4 = local_ec;
              uVar14 = (ulong)uVar6;
              if (uVar6 == 0) {
                if (4 < DAT_01216a78) {
                  fVar21 = (float)FUN_002917b0(&DAT_01216a60);
                  lVar11 = syscall(0xba);
                  FUN_002340f0((double)(fVar21 * DAT_00298548),
                               "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u\n","DEBUG",lVar11,
                               "dmal/common/common_c2c.c",0x164,uVar8,uVar4);
                }
                if (uVar7 == 0xe8) {
                  puVar19[8] = *(uint *)((long)&uStack_e0 + (ulong)local_ec * 0xc + 4);
                }
                else if (uVar7 == 0xe9) {
                  puVar19[8] = *(uint *)((long)&local_d8 + (ulong)local_ec * 0xc);
                }
                else if (uVar7 == 0xe7) {
                  puVar19[8] = *(uint *)((long)&uStack_e0 + (ulong)local_ec * 0xc);
                }
                else {
                  uVar6 = 2;
                }
              }
              else if (1 < DAT_01216a78) {
                fVar21 = (float)FUN_002917b0(&DAT_01216a60);
                lVar11 = syscall(0xba);
                fVar21 = fVar21 * DAT_00298548;
                uVar23 = 0x162;
                uVar17 = 0x162;
LAB_001b193b:
                uVar6 = (uint)uVar14;
                FUN_002340f0((double)fVar21,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",
                             lVar11,"dmal/common/common_c2c.c",uVar17,"cDeviceGetC2cLinkError",
                             uVar23,uVar14);
              }
            }
            else {
              puVar15 = &local_e8;
              for (lVar11 = 0x15; lVar11 != 0; lVar11 = lVar11 + -1) {
                *puVar15 = 0;
                puVar15 = puVar15 + (ulong)bVar20 * -2 + 1;
              }
              puVar16 = (undefined8 *)(param_2 + 0x74810U & 0xfffffffffffffff8);
              *(undefined8 *)(param_2 + 0x74808) = 0;
              *(undefined8 *)(param_2 + 0x748b0) = 0;
              uVar14 = (ulong)(((int)param_2 - (int)puVar16) + 0x748b8U >> 3);
              for (; uVar14 != 0; uVar14 = uVar14 - 1) {
                *puVar16 = 0;
                puVar16 = puVar16 + (ulong)bVar20 * -2 + 1;
              }
              uVar6 = FUN_001b02b0(param_1,param_2);
              uVar14 = (ulong)uVar6;
              if (uVar6 == 0) {
                if (0xe < *(uint *)(param_2 + 0x25d10)) {
switchD_001b1848_caseD_56:
                  uVar14 = 3;
                  goto switchD_001b1848_caseD_f;
                }
                lVar11 = *(long *)(param_2 + 0x256d8);
                if (((lVar11 == 0) || (*(undefined8 **)(lVar11 + 0x50) == (undefined8 *)0x0)) ||
                   (pcVar2 = (code *)**(undefined8 **)(lVar11 + 0x50), pcVar2 == (code *)0x0)) {
                  uVar14 = 3;
                }
                else {
                  uVar6 = (*pcVar2)(lVar11,param_2,0x2080,&local_ec);
                  uVar14 = (ulong)uVar6;
                  if (uVar6 == 0) {
                    uVar6 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_ec,
                                         0x2080182d,&local_e8,0xa8);
                    uVar14 = (ulong)uVar6;
                    switch(uVar6) {
                    case 0:
                      for (uVar6 = *(uint *)(param_2 + 0x25d14); uVar6 != 0; uVar6 = uVar6 >> 1) {
                        if ((uVar6 & 1) != 0) {
                          lVar11 = uVar14 * 0xc;
                          uVar17 = *(undefined8 *)((long)&local_e8 + lVar11);
                          *(undefined4 *)(param_2 + lVar11 + 0x74818) =
                               *(undefined4 *)((long)&uStack_e0 + lVar11);
                          *(undefined8 *)(param_2 + lVar11 + 0x74810) = uVar17;
                        }
                        uVar14 = (ulong)((int)uVar14 + 1);
                      }
                      uVar17 = FUN_00234e30();
                      *(undefined8 *)(param_2 + 0x74808) = uVar17;
                      goto LAB_001b10fe;
                    default:
                      uVar14 = 999;
                      break;
                    case 3:
                    case 0x66:
                      uVar14 = 10;
                      break;
                    case 0xf:
switchD_001b1848_caseD_f:
                      break;
                    case 0x17:
                    case 99:
                      uVar14 = 0x13;
                      break;
                    case 0x1a:
                      uVar14 = 0x17;
                      break;
                    case 0x1b:
                      uVar14 = 4;
                      break;
                    case 0x1f:
                    case 0x3b:
                    case 0x54:
                      uVar14 = 2;
                      break;
                    case 0x51:
                      uVar14 = 0x14;
                      break;
                    case 0x55:
                      uVar14 = 0x1b;
                      break;
                    case 0x56:
                      goto switchD_001b1848_caseD_56;
                    case 0x59:
                      uVar14 = 0x11;
                      break;
                    case 0x62:
                      uVar14 = 0x10;
                    }
                    goto LAB_001b1857;
                  }
                }
                if (1 < DAT_01216a78) {
                  fVar21 = (float)FUN_002917b0(&DAT_01216a60);
                  lVar11 = syscall(0xba);
                  fVar21 = fVar21 * DAT_00298548;
                  uVar23 = 0x127;
                  uVar17 = 0x127;
LAB_001b1bb1:
                  FUN_002340f0((double)fVar21,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                               "ERROR",lVar11,"dmal/common/common_c2c.c",uVar17,
                               "cDeviceGetC2cLinkErrorInfoUncached",uVar23,uVar14);
                }
              }
              else if (1 < DAT_01216a78) {
                fVar21 = (float)FUN_002917b0(&DAT_01216a60);
                lVar11 = syscall(0xba);
                fVar21 = fVar21 * DAT_00298548;
                uVar23 = 0x11f;
                uVar17 = 0x11f;
                goto LAB_001b1bb1;
              }
LAB_001b1857:
              uVar6 = (uint)uVar14;
              if (1 < DAT_01216a78) {
                fVar21 = (float)FUN_002917b0(&DAT_01216a60);
                lVar11 = syscall(0xba);
                FUN_002340f0((double)(fVar21 * DAT_00298548),
                             "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar11,
                             "dmal/common/common_c2c.c",0x149,"cDeviceGetC2cLinkErrorInfo",0x149);
                if (1 < DAT_01216a78) {
                  fVar21 = (float)FUN_002917b0(&DAT_01216a60);
                  lVar11 = syscall(0xba);
                  fVar21 = DAT_00298548 * fVar21;
                  uVar23 = 0x15c;
                  uVar17 = 0x15c;
                  goto LAB_001b193b;
                }
              }
            }
            puVar19[7] = uVar6;
            lVar11 = FUN_00234e30();
            lVar13 = (lVar11 - lVar13) + lVar10;
            goto LAB_001b1071;
          }
        }
        else if (uVar7 == 0xea) {
          if (puVar19[1] < uVar1) {
            puVar19[7] = local_114;
            puVar19[8] = local_110;
          }
          else {
            puVar19[7] = 3;
          }
          goto LAB_001b1071;
        }
        param_4 = param_4 + 1;
        puVar19 = puVar19 + 10;
        if (param_5 < param_4) {
          return 0;
        }
      } while( true );
    }
    if (DAT_01216a78 < 5) goto LAB_001b0d38;
    fVar21 = (float)FUN_002917b0(&DAT_01216a60);
    lVar10 = syscall(0xba);
    fVar21 = fVar21 * DAT_00298548;
    uVar17 = 0x1dc;
  }
  else {
    if (DAT_01216a78 < 2) goto LAB_001b0d38;
    fVar21 = (float)FUN_002917b0(&DAT_01216a60);
    lVar10 = syscall(0xba);
    FUN_002340f0((double)(fVar21 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar10,"dmal/common/common_c2c.c",0x46,"deviceGetC2cLinkCount",0x46,iVar5);
joined_r0x001b0e99:
    if (DAT_01216a78 < 5) goto LAB_001b0d38;
    fVar21 = (float)FUN_002917b0(&DAT_01216a60);
    lVar10 = syscall(0xba);
    fVar21 = fVar21 * DAT_00298548;
    uVar7 = 0;
    uVar17 = 0x1d1;
  }
  FUN_002340f0((double)fVar21,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %x\n","DEBUG",lVar10,
               "dmal/common/common_c2c.c",uVar17,iVar5,uVar7);
LAB_001b0d38:
  FUN_001b01f0(3,param_3,param_4,param_5);
  return 0;
}


// ===== 001b20f0 FUN_001b20f0 =====

undefined8 FUN_001b20f0(undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x118) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x118) + 0x48),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001b211b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_2,0,0,param_3,param_4);
    return uVar2;
  }
  return 3;
}


// ===== 001b2130 FUN_001b2130 =====

ulong FUN_001b2130(long param_1,long param_2,uint param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined8 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  long lVar9;
  undefined8 *puVar10;
  ulong uVar11;
  uint uVar12;
  ulong uVar13;
  ulong uVar14;
  undefined8 uVar15;
  undefined8 *puVar16;
  ulong uVar17;
  byte bVar18;
  float fVar19;
  uint local_5fc;
  undefined4 local_5f4;
  undefined8 local_5f0;
  undefined4 local_5e8;
  undefined8 local_5e4;
  undefined4 local_5dc;
  undefined8 local_5d8;
  undefined8 local_5d0;
  int local_5c4;
  undefined4 local_5b8;
  uint local_5b4;
  
  bVar18 = 0;
  uVar14 = (ulong)param_3;
  lVar9 = *(long *)(param_2 + 0x256d8);
  if (((lVar9 == 0) || (*(undefined8 **)(lVar9 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar3 = (code *)**(undefined8 **)(lVar9 + 0x50), pcVar3 == (code *)0x0)) {
    uVar17 = 3;
joined_r0x001b2308:
    if (1 < DAT_01216a78) {
      fVar19 = (float)FUN_002917b0(&DAT_01216a60);
      lVar9 = syscall(0xba);
      FUN_002340f0((double)(fVar19 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar9,"dmal/common/common_thermal.c",0x843,"cDeviceGetThermalSettings",
                   0x843,uVar17);
    }
    return uVar17;
  }
  uVar4 = *(undefined8 *)(param_1 + 0x10);
  uVar5 = (*pcVar3)(lVar9,param_2,0x2080,&local_5f4);
  uVar17 = (ulong)uVar5;
  if (uVar5 != 0) goto joined_r0x001b2308;
  puVar10 = &local_5d8;
  for (lVar9 = 0xb3; lVar9 != 0; lVar9 = lVar9 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + (ulong)bVar18 * -2 + 1;
  }
  local_5d0 = 0x10000002c;
  local_5f0 = 0;
  local_5e8 = 0;
  local_5e4 = 0;
  local_5dc = 0;
  local_5b8 = 0x500;
  local_5d8 = CONCAT44(local_5d8._4_4_,1);
  local_5c4 = 1;
  uVar5 = FUN_0019c780(uVar4,DAT_0038088c,local_5f4,0x20800513,&local_5d8,0x598,0);
  uVar17 = (ulong)uVar5;
  switch(uVar5) {
  case 0:
    *param_4 = local_5b4;
    if (local_5b4 == 0) {
      return uVar17;
    }
    if (param_3 == 0xf) {
      uVar5 = uVar5 + 1;
      local_5fc = 3;
      uVar14 = uVar17;
      if (local_5b4 < 4) {
        local_5fc = local_5b4;
      }
    }
    else {
      uVar5 = param_3 + 1;
      local_5fc = 3;
      if (uVar5 < 4) {
        local_5fc = uVar5;
      }
      if (local_5fc <= param_3) {
        local_5d8 = 1;
        local_5d0 = 0x10000002c;
        local_5c4 = 0;
        uVar15 = uVar4;
        local_5c4 = FUN_0019c780(uVar4,DAT_0038088c,local_5f4,0x20800513,&local_5d8,0x598,0);
        switch(local_5c4) {
        case 0:
          goto switchD_001b2669_caseD_0;
        default:
          goto switchD_001b22f0_caseD_1;
        case 3:
        case 0x66:
          goto switchD_001b22f0_caseD_3;
        case 0xf:
          goto switchD_001b24b3_caseD_f;
        case 0x17:
        case 99:
          goto switchD_001b22f0_caseD_17;
        case 0x1a:
          goto switchD_001b22f0_caseD_1a;
        case 0x1b:
          goto switchD_001b22f0_caseD_1b;
        case 0x1f:
        case 0x3b:
        case 0x54:
          goto switchD_001b22f0_caseD_1f;
        case 0x51:
          goto switchD_001b22f0_caseD_51;
        case 0x55:
          goto switchD_001b22f0_caseD_55;
        case 0x56:
          goto switchD_001b22f0_caseD_56;
        case 0x59:
          goto switchD_001b22f0_caseD_59;
        case 0x62:
          goto switchD_001b22f0_caseD_62;
        }
      }
    }
    puVar10 = &local_5d8;
    uVar13 = uVar14;
    do {
      iVar6 = (int)uVar13;
      *(int *)((long)puVar10 + 0x24) = iVar6;
      *(int *)(puVar10 + 10) = iVar6;
      *(int *)((long)puVar10 + 0x7c) = iVar6;
      *(int *)(puVar10 + 0x15) = iVar6;
      uVar13 = (ulong)(iVar6 + 1U);
      *(undefined4 *)(puVar10 + 4) = 0x540;
      *(undefined4 *)((long)puVar10 + 0x4c) = 0x1500;
      *(undefined4 *)(puVar10 + 0xf) = 0x510;
      *(undefined4 *)((long)puVar10 + 0xa4) = 0x520;
      puVar10 = puVar10 + 0x16;
    } while (iVar6 + 1U < local_5fc);
    local_5d0 = 0x10000002c;
    iVar6 = local_5fc - (int)uVar14;
    local_5c4 = iVar6 * 4;
    local_5d8 = 1;
    if (local_5fc < uVar5) {
      local_5c4 = 4;
    }
    break;
  default:
    goto switchD_001b22f0_caseD_1;
  case 3:
  case 0x66:
    goto switchD_001b22f0_caseD_3;
  case 0xf:
    return uVar17;
  case 0x17:
  case 99:
    goto switchD_001b22f0_caseD_17;
  case 0x1a:
    goto switchD_001b22f0_caseD_1a;
  case 0x1b:
    goto switchD_001b22f0_caseD_1b;
  case 0x1f:
  case 0x3b:
  case 0x54:
    goto switchD_001b22f0_caseD_1f;
  case 0x51:
    goto switchD_001b22f0_caseD_51;
  case 0x55:
    goto switchD_001b22f0_caseD_55;
  case 0x56:
    goto switchD_001b22f0_caseD_56;
  case 0x59:
    goto switchD_001b22f0_caseD_59;
  case 0x62:
    goto switchD_001b22f0_caseD_62;
  }
  uVar7 = FUN_0019c780(uVar4,DAT_0038088c,local_5f4,0x20800513,&local_5d8,0x598,0);
  switch(uVar7) {
  case 0:
    uVar15 = 0;
    puVar10 = &local_5d8;
    uVar13 = uVar14;
    do {
      iVar1 = *(int *)((long)puVar10 + 0x2c);
      uVar8 = 0;
      if (-1 < *(int *)(puVar10 + 5)) {
        uVar8 = *(uint *)(puVar10 + 5);
      }
      param_4[uVar13 * 5 + 2] = uVar8;
      uVar8 = 0;
      if (-1 < iVar1) {
        uVar8 = *(uint *)((long)puVar10 + 0x2c);
      }
      uVar12 = (int)uVar13 + 1;
      param_4[uVar13 * 5 + 3] = uVar8;
      param_4[uVar13 * 5 + 4] = *(uint *)((long)puVar10 + 0x54);
      *(undefined4 *)((long)&local_5f0 + uVar13 * 4) = *(undefined4 *)(puVar10 + 0x10);
      *(undefined4 *)((long)&local_5e4 + uVar13 * 4) = *(undefined4 *)((long)puVar10 + 0xac);
      uVar11 = uVar14;
      puVar10 = puVar10 + 0x16;
      uVar13 = (ulong)uVar12;
      puVar16 = &local_5d8;
    } while (uVar12 < local_5fc);
    do {
      *(undefined4 *)(puVar16 + 4) = 0x301;
      uVar8 = (int)uVar11 + 1;
      uVar7 = *(undefined4 *)((long)&local_5f0 + uVar11 * 4);
      uVar2 = *(undefined4 *)((long)&local_5e4 + uVar11 * 4);
      *(undefined4 *)((long)puVar16 + 0x4c) = 0x101;
      *(undefined4 *)((long)puVar16 + 0x24) = uVar7;
      *(undefined4 *)(puVar16 + 10) = uVar2;
      uVar11 = (ulong)uVar8;
      puVar16 = puVar16 + 0xb;
    } while (uVar8 < local_5fc);
    local_5c4 = iVar6 * 2;
    if (local_5fc < uVar5) {
      local_5c4 = 2;
    }
switchD_001b2669_caseD_0:
    local_5d8 = 1;
    local_5d0 = 0x10000002c;
    uVar5 = FUN_0019c780(uVar4,DAT_0038088c,local_5f4,0x20800513,&local_5d8,0x598,0,uVar15);
    switch(uVar5) {
    case 0:
      lVar9 = uVar14 * 0x14;
      puVar10 = &local_5d8;
      while( true ) {
        if (local_5fc <= (uint)uVar14) break;
        uVar14 = (ulong)((uint)uVar14 + 1);
        *(undefined4 *)((long)param_4 + lVar9 + 4) = *(undefined4 *)(puVar10 + 5);
        *(undefined4 *)((long)param_4 + lVar9 + 0x14) = *(undefined4 *)((long)puVar10 + 0x54);
        lVar9 = lVar9 + 0x14;
        puVar10 = puVar10 + 0xb;
      }
      return uVar17;
    case 3:
    case 0x66:
switchD_001b22f0_caseD_3:
      return 10;
    case 0xf:
      return (ulong)uVar5;
    case 0x17:
    case 99:
switchD_001b22f0_caseD_17:
      return 0x13;
    case 0x1a:
switchD_001b22f0_caseD_1a:
      return 0x17;
    case 0x1b:
switchD_001b22f0_caseD_1b:
      return 4;
    case 0x1f:
    case 0x3b:
    case 0x54:
switchD_001b22f0_caseD_1f:
      return 2;
    case 0x51:
switchD_001b22f0_caseD_51:
      return 0x14;
    case 0x55:
switchD_001b22f0_caseD_55:
      return 0x1b;
    case 0x56:
switchD_001b22f0_caseD_56:
      return 3;
    case 0x59:
switchD_001b22f0_caseD_59:
      return 0x11;
    case 0x62:
switchD_001b22f0_caseD_62:
      return 0x10;
    }
    break;
  case 3:
  case 0x66:
    goto switchD_001b22f0_caseD_3;
  case 0xf:
switchD_001b24b3_caseD_f:
    return 0xf;
  case 0x17:
  case 99:
    goto switchD_001b22f0_caseD_17;
  case 0x1a:
    goto switchD_001b22f0_caseD_1a;
  case 0x1b:
    goto switchD_001b22f0_caseD_1b;
  case 0x1f:
  case 0x3b:
  case 0x54:
    goto switchD_001b22f0_caseD_1f;
  case 0x51:
    goto switchD_001b22f0_caseD_51;
  case 0x55:
    goto switchD_001b22f0_caseD_55;
  case 0x56:
    goto switchD_001b22f0_caseD_56;
  case 0x59:
    goto switchD_001b22f0_caseD_59;
  case 0x62:
    goto switchD_001b22f0_caseD_62;
  }
switchD_001b22f0_caseD_1:
  return 999;
}


// ===== 001b26b0 FUN_001b26b0 =====

int FUN_001b26b0(long param_1,long param_2,uint *param_3)

{
  byte bVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  long lVar13;
  void *__ptr;
  void *__ptr_00;
  void *__ptr_01;
  ulong uVar14;
  uint *puVar15;
  uint *puVar16;
  char *pcVar17;
  uint uVar18;
  byte bVar19;
  char *pcVar20;
  byte bVar21;
  float fVar22;
  undefined4 local_43c;
  uint local_438 [258];
  
  bVar21 = 0;
  lVar13 = *(long *)(param_2 + 0x256d8);
  if (((lVar13 == 0) || (*(undefined8 **)(lVar13 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar13 + 0x50), pcVar2 == (code *)0x0)) {
    iVar8 = 3;
  }
  else {
    uVar3 = *(undefined8 *)(param_1 + 0x10);
    iVar8 = (*pcVar2)(lVar13,param_2,0x2080,&local_43c);
    if (iVar8 == 0) {
      __ptr = calloc(0x3bf8,1);
      __ptr_00 = calloc(0x37f0,1);
      __ptr_01 = calloc(0x63d0,1);
      if ((__ptr == (void *)0x0 || __ptr_00 == (void *)0x0) || (__ptr_01 == (void *)0x0)) {
        iVar8 = 0x14;
        if (1 < DAT_01216a78) {
          fVar22 = (float)FUN_002917b0(&DAT_01216a60);
          lVar13 = syscall(0xba);
          FUN_002340f0((double)(fVar22 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       "ERROR",lVar13,"dmal/common/common_thermal.c",0x8fa);
        }
      }
      else {
        puVar15 = local_438;
        puVar16 = puVar15;
        for (lVar13 = 0x7f; lVar13 != 0; lVar13 = lVar13 + -1) {
          puVar16[0] = 0;
          puVar16[1] = 0;
          puVar16 = puVar16 + (ulong)bVar21 * -4 + 2;
        }
        *puVar16 = 0;
        iVar8 = FUN_0019c780(uVar3,DAT_0038088c,local_43c,0x2080853a,__ptr,0x3bf8);
        if (iVar8 == 0) {
          iVar8 = 0;
          puVar16 = (uint *)((long)__ptr + 4);
          do {
            uVar18 = *puVar16;
            puVar16 = puVar16 + 1;
            uVar18 = uVar18 - (uVar18 >> 1 & 0x55555555);
            uVar18 = (uVar18 >> 2 & 0x33333333) + (uVar18 & 0x33333333);
            iVar8 = iVar8 + (((uVar18 >> 4) + uVar18 & 0xf0f0f0f) * 0x1010101 >> 0x18);
          } while ((uint *)((long)__ptr + 0x24) != puVar16);
          if ((short)iVar8 == 0) {
            iVar8 = 3;
          }
          else {
            uVar14 = 0;
            pcVar20 = (char *)((long)__ptr + 0x34);
            pcVar17 = pcVar20;
            bVar21 = 0;
            do {
              while (((uVar18 = (uint)uVar14,
                      (((uint *)((long)__ptr + 4))[(ushort)(uVar14 >> 5) & 0x7ff] >> (uVar18 & 0x1f)
                      & 1) == 0 || ((pcVar17[0x21] & 0x40U) == 0)) || (*pcVar17 != '\x01'))) {
                uVar14 = (ulong)(uVar18 + 1);
                pcVar17 = pcVar17 + 0x3c;
                if ((short)(uVar18 + 1) == 0xff) goto LAB_001b29e7;
              }
              uVar9 = FUN_00133980(pcVar17[1]);
              uVar11 = *(uint *)(pcVar17 + 8);
              uVar10 = uVar11 >> 8;
              param_3[(ulong)bVar21 * 6 + 1] = uVar9;
              uVar9 = *(uint *)(pcVar17 + 0xc);
              if ((int)uVar11 < 0) {
                uVar10 = uVar10 | 0xff000000;
              }
              param_3[(ulong)bVar21 * 6 + 3] = uVar10;
              uVar11 = uVar9 >> 8;
              bVar1 = pcVar17[0x20];
              if ((int)uVar9 < 0) {
                uVar11 = uVar11 | 0xff000000;
              }
              uVar14 = (ulong)(uVar18 + 1);
              bVar19 = bVar21 + 1;
              param_3[(ulong)bVar21 * 6 + 4] = uVar11;
              param_3[(long)(int)(uint)bVar21 * 6 + 6] = (uint)bVar1;
              local_438[(int)(uint)bVar21] = (uint)(byte)pcVar17[0x25];
              pcVar17 = pcVar17 + 0x3c;
              bVar21 = bVar19;
            } while ((short)(uVar18 + 1) != 0xff);
LAB_001b29e7:
            iVar8 = 0;
            *param_3 = (uint)bVar21;
            if (bVar21 != 0) {
              iVar12 = FUN_0019c780(uVar3,DAT_0038088c,local_43c,0x20808536,__ptr_01,0x63d0,0);
              if (iVar12 == 0) {
                puVar16 = param_3 + 2;
                do {
                  *puVar16 = 0xffffffff;
                  uVar14 = 0;
                  do {
                    uVar18 = (uint)uVar14;
                    if (((*(uint *)((long)__ptr_01 + (ulong)((ushort)(uVar14 >> 5) & 0x7ff) * 4 + 4)
                          >> (uVar18 & 0x1f) & 1) != 0) && (*puVar15 == uVar18)) {
                      uVar18 = FUN_001339d0(*(undefined1 *)
                                             ((long)__ptr_01 + (long)(int)uVar18 * 100 + 0x34));
                      *puVar16 = uVar18;
                      break;
                    }
                    uVar14 = (ulong)(uVar18 + 1);
                  } while (uVar18 + 1 != 0xff);
                  puVar15 = puVar15 + 1;
                  puVar16 = puVar16 + 6;
                } while (local_438 + (ulong)(byte)(bVar21 - 1) + 1 != puVar15);
                uVar4 = *(undefined8 *)((long)__ptr + 0xc);
                uVar5 = *(undefined8 *)((long)__ptr + 0x14);
                uVar6 = *(undefined8 *)((long)__ptr + 0x1c);
                *(undefined8 *)((long)__ptr_00 + 4) = *(undefined8 *)((long)__ptr + 4);
                *(undefined8 *)((long)__ptr_00 + 0xc) = uVar4;
                uVar7 = DAT_0038088c;
                iVar8 = 0;
                *(undefined8 *)((long)__ptr_00 + 0x14) = uVar5;
                *(undefined8 *)((long)__ptr_00 + 0x1c) = uVar6;
                iVar12 = FUN_0019c780(uVar3,uVar7,local_43c,0x2080853b,__ptr_00,0x37f0);
                if (iVar12 == 0) {
                  bVar21 = 0;
                  puVar15 = (uint *)((long)__ptr_00 + 0x2c);
                  uVar18 = 0;
                  do {
                    if ((((*(uint *)((long)__ptr_00 + (ulong)(ushort)((ushort)uVar18 >> 5) * 4 + 4)
                           >> (uVar18 & 0x1f) & 1) != 0) && ((pcVar20[0x21] & 0x40U) != 0)) &&
                       (*pcVar20 == '\x01')) {
                      uVar11 = *puVar15 >> 8;
                      uVar14 = (ulong)bVar21;
                      if ((int)*puVar15 < 0) {
                        uVar11 = uVar11 | 0xff000000;
                      }
                      bVar21 = bVar21 + 1;
                      param_3[uVar14 * 6 + 5] = uVar11;
                    }
                    uVar18 = uVar18 + 1;
                    pcVar20 = pcVar20 + 0x3c;
                    puVar15 = puVar15 + 0xe;
                  } while ((short)uVar18 != 0xff);
                  goto LAB_001b2c29;
                }
              }
              iVar8 = FUN_0019c760(iVar12);
            }
          }
        }
        else {
          iVar8 = FUN_0019c760(iVar8);
        }
      }
LAB_001b2c29:
      free(__ptr);
      free(__ptr_00);
      free(__ptr_01);
      return iVar8;
    }
  }
  if (1 < DAT_01216a78) {
    fVar22 = (float)FUN_002917b0(&DAT_01216a60);
    lVar13 = syscall(0xba);
    FUN_002340f0((double)(fVar22 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar13,"dmal/common/common_thermal.c",0x8f2,
                 "cDeviceGetThermalChannelSettings",0x8f2,iVar8);
  }
  return iVar8;
}


// ===== 001b2ce0 FUN_001b2ce0 =====

undefined4 FUN_001b2ce0(long param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  uint uVar6;
  float fVar7;
  undefined8 local_cd8 [3];
  uint local_cc0;
  uint local_cbc;
  undefined8 local_738 [6];
  char local_704;
  
  puVar4 = local_cd8;
  for (lVar3 = 0xb4; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = local_738;
  for (lVar3 = 0xdf; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,param_2,0x2080852a,local_738,
                       0x6f8,0);
  switch(uVar2) {
  case 0:
    if (local_704 != '\0') {
      uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,param_2,0x2080852c,local_cd8
                           ,0x5a0,0);
      iVar1 = DAT_01216a78;
      switch(uVar2) {
      case 0:
        if (*param_3 == 0xc1) {
          if (local_cbc != 0xff00) {
            uVar6 = 0;
            if ((int)local_cbc < 0) {
              uVar6 = 0xff000000;
            }
            uVar6 = local_cbc >> 8 | uVar6;
            param_3[8] = uVar6;
            if (iVar1 < 5) {
              return uVar2;
            }
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            uVar5 = 0x378;
            fVar7 = fVar7 * DAT_00298548;
LAB_001b2f16:
            FUN_002340f0((double)fVar7,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","DEBUG",lVar3,
                         "dmal/common/common_thermal.c",uVar5,uVar6);
            return uVar2;
          }
          if (4 < DAT_01216a78) {
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            fVar7 = fVar7 * DAT_00298548;
            uVar5 = 0x373;
LAB_001b2ffc:
            FUN_002340f0((double)fVar7,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",lVar3,
                         "dmal/common/common_thermal.c",uVar5);
            return 3;
          }
        }
        else {
          if (*param_3 != 0xc2) goto switchD_001b2d67_caseD_1f;
          if (local_cc0 != 0xff00) {
            uVar6 = 0;
            if ((int)local_cc0 < 0) {
              uVar6 = 0xff000000;
            }
            uVar6 = local_cc0 >> 8 | uVar6;
            param_3[8] = uVar6;
            if (iVar1 < 5) {
              return uVar2;
            }
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            uVar5 = 0x385;
            fVar7 = fVar7 * DAT_00298548;
            goto LAB_001b2f16;
          }
          if (4 < DAT_01216a78) {
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            fVar7 = fVar7 * DAT_00298548;
            uVar5 = 0x380;
            goto LAB_001b2ffc;
          }
        }
        break;
      default:
        goto switchD_001b2d67_caseD_1;
      case 3:
      case 0x66:
        goto switchD_001b2d67_caseD_3;
      case 0xf:
        goto switchD_001b2d67_caseD_f;
      case 0x17:
      case 99:
        goto switchD_001b2d67_caseD_17;
      case 0x1a:
        goto switchD_001b2d67_caseD_1a;
      case 0x1b:
        goto switchD_001b2d67_caseD_1b;
      case 0x1f:
      case 0x3b:
      case 0x54:
        goto switchD_001b2d67_caseD_1f;
      case 0x51:
        goto switchD_001b2d67_caseD_51;
      case 0x55:
        goto switchD_001b2d67_caseD_55;
      case 0x56:
        break;
      case 0x59:
        goto switchD_001b2d67_caseD_59;
      case 0x62:
        goto switchD_001b2d67_caseD_62;
      }
    }
  case 0x56:
    uVar2 = 3;
    break;
  default:
switchD_001b2d67_caseD_1:
    return 999;
  case 3:
  case 0x66:
switchD_001b2d67_caseD_3:
    return 10;
  case 0xf:
    break;
  case 0x17:
  case 99:
switchD_001b2d67_caseD_17:
    return 0x13;
  case 0x1a:
switchD_001b2d67_caseD_1a:
    return 0x17;
  case 0x1b:
switchD_001b2d67_caseD_1b:
    return 4;
  case 0x1f:
  case 0x3b:
  case 0x54:
switchD_001b2d67_caseD_1f:
    uVar2 = 2;
    break;
  case 0x51:
switchD_001b2d67_caseD_51:
    return 0x14;
  case 0x55:
switchD_001b2d67_caseD_55:
    return 0x1b;
  case 0x59:
switchD_001b2d67_caseD_59:
    return 0x11;
  case 0x62:
switchD_001b2d67_caseD_62:
    uVar2 = 0x10;
  }
switchD_001b2d67_caseD_f:
  return uVar2;
}


// ===== 001b3070 FUN_001b3070 =====

int FUN_001b3070(undefined8 param_1,long param_2,int *param_3)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined8 *puVar5;
  int iVar6;
  float fVar7;
  undefined4 local_5cc;
  undefined8 local_5c8 [2];
  undefined4 local_5b4;
  undefined8 local_5b0;
  undefined8 uStack_5a8;
  undefined8 local_5a0;
  undefined8 uStack_598;
  undefined8 local_590;
  int local_588;
  
  puVar5 = local_5c8;
  for (lVar4 = 0xb3; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
LAB_001b3196:
    if (1 < DAT_01216a78) {
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"dmal/common/common_thermal.c",0x28,
                   "cDeviceMakeThermalSystemExecuteRMCall",0x28,iVar3);
      return iVar3;
    }
  }
  else {
    iVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_5cc);
    if (iVar3 != 0) goto LAB_001b3196;
    local_5b0 = *(undefined8 *)param_3;
    uStack_5a8 = *(undefined8 *)(param_3 + 2);
    local_5a0 = *(undefined8 *)(param_3 + 4);
    uStack_598 = *(undefined8 *)(param_3 + 6);
    local_5c8[1] = 0x30000002c;
    local_590 = *(undefined8 *)(param_3 + 8);
    local_5c8[0] = 1;
    local_588 = param_3[10];
    local_5b4 = 1;
    iVar3 = FUN_0019c780(param_1,DAT_0038088c,local_5cc,0x20800513,local_5c8,0x598,0);
    switch(iVar3) {
    case 0:
      *(undefined8 *)(param_3 + 8) = local_590;
      *(undefined8 *)param_3 = local_5b0;
      *(undefined8 *)(param_3 + 2) = uStack_5a8;
      iVar3 = param_3[1];
      param_3[10] = local_588;
      *(undefined8 *)(param_3 + 4) = local_5a0;
      *(undefined8 *)(param_3 + 6) = uStack_598;
      if (iVar3 == 0) {
        if (4 < DAT_01216a78) {
          iVar6 = *param_3;
          goto LAB_001b3322;
        }
      }
      else {
        iVar6 = *param_3;
        if (iVar6 == 0) {
          return 0;
        }
        if (4 < DAT_01216a78) {
LAB_001b3322:
          iVar1 = param_3[2];
          fVar7 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar7 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %X %X %X\n","DEBUG",lVar4,
                       "dmal/common/common_thermal.c",0x48,0,iVar1,iVar3,iVar6);
          if (param_3[1] == 0) goto switchD_001b3189_caseD_1;
          iVar6 = *param_3;
        }
        if (iVar6 == 0x56) goto switchD_001b3189_caseD_56;
      }
    default:
switchD_001b3189_caseD_1:
      iVar3 = 999;
      break;
    case 3:
    case 0x66:
      iVar3 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      iVar3 = 0x13;
      break;
    case 0x1a:
      iVar3 = 0x17;
      break;
    case 0x1b:
      iVar3 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
      iVar3 = 2;
      break;
    case 0x51:
      iVar3 = 0x14;
      break;
    case 0x55:
      iVar3 = 0x1b;
      break;
    case 0x56:
switchD_001b3189_caseD_56:
      iVar3 = 3;
      break;
    case 0x59:
      iVar3 = 0x11;
      break;
    case 0x62:
      iVar3 = 0x10;
    }
  }
  return iVar3;
}


// ===== 001b33b0 FUN_001b33b0 =====

uint FUN_001b33b0(undefined8 param_1,long param_2,undefined8 param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  float fVar4;
  undefined4 local_2c [3];
  
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    uVar2 = 3;
  }
  else {
    uVar2 = (*pcVar1)(lVar3,param_2,0x2080,local_2c);
    if (uVar2 == 0) {
      uVar2 = FUN_0019c780(param_1,DAT_0038088c,local_2c[0],0x2080852f,param_3,0x34c,0);
      if (0x66 < uVar2) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002b4720 + (ulong)uVar2 * 2);
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar2;
  }
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_thermal.c",0x5a1,"cDeviceFanCoolerGetStatus",0x5a1,
               uVar2);
  return uVar2;
}


// ===== 001b3530 FUN_001b3530 =====

uint FUN_001b3530(undefined8 param_1,long param_2,undefined8 param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  float fVar4;
  undefined4 local_2c [3];
  
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    uVar2 = 3;
  }
  else {
    uVar2 = (*pcVar1)(lVar3,param_2,0x2080,local_2c);
    if (uVar2 == 0) {
      uVar2 = FUN_0019c780(param_1,DAT_0038088c,local_2c[0],0x20808530,param_3,0x3d4,0);
      if (0x66 < uVar2) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002b4720 + (ulong)uVar2 * 2);
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar2;
  }
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_thermal.c",0x58d,"cDeviceFanCoolerGetControl",0x58d
               ,uVar2);
  return uVar2;
}


// ===== 001b36b0 FUN_001b36b0 =====

uint FUN_001b36b0(undefined8 param_1,long param_2,undefined8 param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  float fVar4;
  undefined4 local_2c [3];
  
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    uVar2 = 3;
  }
  else {
    uVar2 = (*pcVar1)(lVar3,param_2,0x2080,local_2c);
    if (uVar2 == 0) {
      uVar2 = FUN_0019c780(param_1,DAT_0038088c,local_2c[0],0x2080c531,param_3,0x3d4,0);
      if (0x66 < uVar2) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002b4720 + (ulong)uVar2 * 2);
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar2;
  }
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_thermal.c",0x578,"cDeviceFanCoolerSetControl",0x578
               ,uVar2);
  return uVar2;
}


// ===== 001b3830 FUN_001b3830 =====

uint FUN_001b3830(undefined8 param_1,long param_2,undefined8 param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  float fVar4;
  undefined4 local_2c [3];
  
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    uVar2 = 3;
  }
  else {
    uVar2 = (*pcVar1)(lVar3,param_2,0x2080,local_2c);
    if (uVar2 == 0) {
      uVar2 = FUN_0019c780(param_1,DAT_0038088c,local_2c[0],0x2080852e,param_3,0x254,0);
      if (0x66 < uVar2) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002b4720 + (ulong)uVar2 * 2);
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar2;
  }
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_thermal.c",0x565,"cDeviceFanCoolerGetInfo",0x565,
               uVar2);
  return uVar2;
}


// ===== 001b39b0 FUN_001b39b0 =====

int FUN_001b39b0(undefined8 param_1,long param_2,int *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  float fVar7;
  undefined4 local_5c;
  undefined1 local_58 [16];
  undefined1 local_48 [24];
  
  local_58 = (undefined1  [16])0x0;
  local_48._0_16_ = (undefined1  [16])0x0;
  lVar5 = *(long *)(param_2 + 0x256d8);
  if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar3 = (code *)**(undefined8 **)(lVar5 + 0x50), pcVar3 == (code *)0x0)) {
    iVar4 = 3;
  }
  else {
    iVar4 = (*pcVar3)(lVar5,param_2,0x2080,&local_5c);
    if (iVar4 == 0) {
      local_58._8_8_ = 0x30;
      local_58._0_8_ = 1;
      local_48._4_4_ = param_4;
      local_48._8_8_ = param_3;
      iVar4 = FUN_0019c780(param_1,DAT_0038088c,local_5c,0x20800522,local_58,0x20,0);
      switch(iVar4) {
      case 0:
        uVar6 = 0;
        while( true ) {
          if (4 < DAT_01216a78) {
            iVar4 = param_3[1];
            iVar1 = *param_3;
            iVar2 = param_3[2];
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar5 = syscall(0xba);
            FUN_002340f0((double)(fVar7 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %X %X %X\n","DEBUG",lVar5,
                         "dmal/common/common_thermal.c",0x54e,uVar6 & 0xffffffff,iVar2,iVar4,iVar1);
          }
          if ((param_3[1] == 0) || (*param_3 != 0)) break;
          uVar6 = uVar6 + 1;
          param_3 = param_3 + 0xc;
          if (param_4 == uVar6) {
            return 0;
          }
        }
        break;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar4;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
      return 999;
    }
  }
  if (1 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar5,"dmal/common/common_thermal.c",0x53b,
                 "cDeviceMakeThermalCoolerExecuteRMCall",0x53b,iVar4);
  }
  return iVar4;
}


// ===== 001b3c70 FUN_001b3c70 =====

undefined4 FUN_001b3c70(undefined8 param_1,long param_2,undefined8 param_3)

{
  undefined4 uVar1;
  long lVar2;
  ulong uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  byte bVar6;
  float fVar7;
  undefined8 local_738;
  undefined4 local_730;
  undefined1 local_728;
  undefined1 local_727;
  undefined1 local_726;
  undefined1 local_725;
  undefined1 local_704;
  undefined8 local_700 [215];
  undefined8 local_48;
  
  bVar6 = 0;
  puVar4 = &local_738;
  for (lVar2 = 0xdf; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  uVar1 = FUN_0019c780(param_1,DAT_0038088c,param_3,0x2080852a,&local_738,0x6f8,0);
  switch(uVar1) {
  case 0:
    puVar5 = (undefined8 *)(param_2 + 0x25d7cU & 0xfffffffffffffff8);
    lVar2 = (param_2 + 0x25d74) - (long)puVar5;
    *(undefined8 *)(param_2 + 0x25d74) = local_700[0];
    *(undefined4 *)(param_2 + 0x25d68) = local_730;
    *(undefined8 *)(param_2 + 0x2642c) = local_48;
    *(undefined1 *)(param_2 + 0x25d6c) = local_725;
    *(undefined1 *)(param_2 + 0x25d6d) = local_728;
    *(undefined1 *)(param_2 + 0x25d6e) = local_727;
    *(undefined1 *)(param_2 + 0x25d6f) = local_726;
    *(undefined1 *)(param_2 + 0x25d70) = local_704;
    puVar4 = (undefined8 *)((long)local_700 - lVar2);
    for (uVar3 = (ulong)((int)lVar2 + 0x6c0U >> 3); uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + (ulong)bVar6 * -2 + 1;
      puVar5 = puVar5 + (ulong)bVar6 * -2 + 1;
    }
    if (4 < DAT_01216a78) {
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar7 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%X %d %d %d %d %u\n","DEBUG",lVar2,
                   "dmal/common/common_thermal.c",0x20c,local_730,local_725,local_728,local_727,
                   local_726,local_704);
    }
    break;
  default:
    uVar1 = 999;
    break;
  case 3:
  case 0x66:
    uVar1 = 10;
    break;
  case 0xf:
    break;
  case 0x17:
  case 99:
    uVar1 = 0x13;
    break;
  case 0x1a:
    uVar1 = 0x17;
    break;
  case 0x1b:
    uVar1 = 4;
    break;
  case 0x1f:
  case 0x3b:
  case 0x54:
    uVar1 = 2;
    break;
  case 0x51:
    uVar1 = 0x14;
    break;
  case 0x55:
    uVar1 = 0x1b;
    break;
  case 0x56:
    uVar1 = 3;
    break;
  case 0x59:
    uVar1 = 0x11;
    break;
  case 0x62:
    uVar1 = 0x10;
  }
  return uVar1;
}


// ===== 001b3eb0 FUN_001b3eb0 =====

uint FUN_001b3eb0(undefined8 param_1,long param_2,char param_3)

{
  code *pcVar1;
  bool bVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined4 uVar5;
  undefined1 uVar6;
  uint uVar7;
  int iVar8;
  long lVar9;
  undefined1 *puVar10;
  float fVar11;
  uint local_7c;
  int local_78;
  undefined4 local_68;
  undefined8 local_64;
  undefined4 local_5c;
  undefined1 local_58 [16];
  undefined8 local_48;
  
  lVar9 = *(long *)(param_2 + 0x256d8);
  local_48 = 0;
  local_64 = 0x100f0e0d0c0b0a09;
  local_5c = 0x14131211;
  local_58 = (undefined1  [16])0x0;
  if (((lVar9 == 0) || (*(undefined8 **)(lVar9 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar9 + 0x50), pcVar1 == (code *)0x0)) {
    uVar7 = 3;
  }
  else {
    uVar7 = (*pcVar1)(lVar9,param_2,0x2080,&local_68);
    if (uVar7 == 0) {
      local_7c = 0;
      puVar10 = (undefined1 *)((long)&local_64 + 1);
      local_78 = 0;
      bVar2 = false;
      uVar6 = 9;
      while( true ) {
        auVar4 = local_58;
        local_58[0] = uVar6;
        auVar3 = local_58;
        local_58._9_7_ = auVar4._9_7_;
        local_58._0_8_ = auVar3._0_8_;
        local_58[8] = param_3;
        iVar8 = FUN_0019c780(param_1,DAT_0038088c,local_68,0x20808546,local_58,0x18,0);
        uVar6 = local_58[0];
        if (iVar8 == 0) {
          if (4 < DAT_01216a78) {
            uVar5 = local_58._4_4_;
            fVar11 = (float)FUN_002917b0(&DAT_01216a60);
            lVar9 = syscall(0xba);
            FUN_002340f0((double)(fVar11 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %u\n","DEBUG",lVar9,
                         "dmal/common/common_thermal.c",0x1af,uVar5,uVar6);
          }
          if (local_58._4_4_ - 1 < 0x95ff) {
            if (bVar2) {
              if ((int)local_58._4_4_ <= local_78) {
                local_78 = local_58._4_4_;
                local_7c = (uint)local_58[0];
              }
            }
            else {
              bVar2 = true;
              local_7c = (uint)local_58[0];
              local_78 = local_58._4_4_;
            }
          }
          else if (2 < DAT_01216a78) {
            fVar11 = (float)FUN_002917b0(&DAT_01216a60);
            lVar9 = syscall(0xba);
            FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                         "WARNING",lVar9,"dmal/common/common_thermal.c",0x1b4);
          }
        }
        else {
          if (iVar8 != 0x56) {
            if (99 < iVar8 - 3U) {
              return 999;
            }
            return (uint)*(ushort *)(&DAT_002b4800 + (ulong)(iVar8 - 3U) * 2);
          }
          if (4 < DAT_01216a78) {
            fVar11 = (float)FUN_002917b0(&DAT_01216a60);
            lVar9 = syscall(0xba);
            FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n",
                         "DEBUG",lVar9,"dmal/common/common_thermal.c",0x1a7,uVar6);
          }
        }
        iVar8 = DAT_01216a78;
        if (local_58 == puVar10) break;
        uVar6 = *puVar10;
        puVar10 = puVar10 + 1;
      }
      if (bVar2) {
        local_78 = local_78 >> 8;
        if (param_3 == '\0') {
          *(int *)(param_2 + 0x748c8) = local_78;
        }
        else {
          *(int *)(param_2 + 0x748b8) = local_78;
        }
        *(uint *)(param_2 + 0x748d8) = local_7c;
        if (iVar8 < 5) {
          return 0;
        }
        fVar11 = (float)FUN_002917b0(&DAT_01216a60);
        lVar9 = syscall(0xba);
        FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u\n",
                     "DEBUG",lVar9,"dmal/common/common_thermal.c",0x1d9,local_78,local_7c);
        return 0;
      }
      if (DAT_01216a78 < 5) {
        return 3;
      }
      fVar11 = (float)FUN_002917b0(&DAT_01216a60);
      lVar9 = syscall(0xba);
      FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                   lVar9,"dmal/common/common_thermal.c",0x1c8);
      return 3;
    }
  }
  if (1 < DAT_01216a78) {
    fVar11 = (float)FUN_002917b0(&DAT_01216a60);
    lVar9 = syscall(0xba);
    FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar9,"dmal/common/common_thermal.c",0x195,
                 "cDeviceGetSlowdownTemperatureThresholdInternalUncached",0x195,uVar7);
  }
  return uVar7;
}


// ===== 001b4390 FUN_001b4390 =====

int FUN_001b4390(undefined8 param_1,long param_2,int *param_3,uint *param_4,int param_5,
                undefined1 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  uint uVar6;
  float fVar7;
  undefined8 uVar8;
  undefined4 local_5c;
  undefined1 local_58 [16];
  undefined8 local_48;
  
  lVar4 = *(long *)(param_2 + 0x256d8);
  local_48 = 0;
  local_58 = (undefined1  [16])0x0;
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    uVar8 = 0x1b43f5;
    iVar3 = (*pcVar1)(lVar4,param_2,0x2080,&local_5c);
    if (iVar3 == 0) {
      local_58[8] = param_6;
      local_58[0] = (-(param_5 == 0) & 0xeeU) + 0x15;
      iVar3 = FUN_0019c780(param_1,DAT_0038088c,local_5c,0x20808546,local_58,0x18,0);
      switch(iVar3) {
      case 0:
        goto switchD_001b445e_caseD_0;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar3;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (1 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_thermal.c",0x160,
                 "cDeviceGetShutdownTemperatureThresholdInternal",0x160,iVar3);
  }
  return iVar3;
switchD_001b445e_caseD_0:
  uVar2 = local_58._4_4_;
  uVar6 = (uint)local_58[0];
  *param_4 = uVar6;
  iVar5 = (int)local_58._4_4_ >> 8;
  *param_3 = iVar5;
  if (DAT_01216a78 < 5) {
    return iVar3;
  }
  fVar7 = (float)FUN_002917b0(&DAT_01216a60,uVar8);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u %d\n",
               "DEBUG",lVar4,"dmal/common/common_thermal.c",0x176,uVar6,iVar5,uVar2);
  return iVar3;
}


// ===== 001b4610 FUN_001b4610 =====

int FUN_001b4610(long param_1,long param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  float fVar4;
  
  if (*(int *)(param_2 + 0x26434) == 0) {
    do {
      iVar1 = FUN_00291820(param_2 + 0x26438,1,0);
    } while (iVar1 != 0);
    if (*(int *)(param_2 + 0x26434) == 0) {
      uVar2 = FUN_001b3c70(*(undefined8 *)(param_1 + 0x10),param_2,param_3);
      *(undefined4 *)(param_2 + 0x26434) = 1;
      *(undefined4 *)(param_2 + 0x2643c) = uVar2;
    }
    FUN_00291830(param_2 + 0x26438,0);
  }
  iVar1 = *(int *)(param_2 + 0x2643c);
  if ((iVar1 != 0) && (1 < DAT_01216a78)) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar3,"dmal/common/common_thermal.c",0x21c,"cDeviceGetThermalPolicyInfo",
                 0x21c,iVar1);
    return iVar1;
  }
  return iVar1;
}


// ===== 001b4740 FUN_001b4740 =====

uint FUN_001b4740(undefined8 param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  float fVar3;
  
  uVar1 = FUN_001b4610();
  if (uVar1 != 0) {
    if (1 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar2,"dmal/common/common_thermal.c",0x2dd,"cIsTlimitReportingSupported",
                   0x2dd,uVar1);
    }
    return uVar1;
  }
  return (uint)*(byte *)(param_2 + 0x25d70);
}


// ===== 001b4800 FUN_001b4800 =====

int FUN_001b4800(long param_1,long param_2,int *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  float fVar6;
  double dVar7;
  undefined8 uVar8;
  undefined4 local_5dc;
  undefined8 local_5d8;
  undefined4 local_5d0;
  int aiStack_5b4 [353];
  
  puVar4 = &local_5d8;
  for (lVar3 = 0xb4; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    uVar5 = *(undefined8 *)(param_1 + 0x10);
    iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_5dc);
    if (iVar2 == 0) {
      lVar3 = *(long *)(param_2 + 0x256d8);
      if (((lVar3 == 0) || (*(long *)(lVar3 + 0x148) == 0)) ||
         (pcVar1 = *(code **)(*(long *)(lVar3 + 0x148) + 0x20), pcVar1 == (code *)0x0)) {
        iVar2 = 3;
      }
      else {
        iVar2 = (*pcVar1)(lVar3,param_2);
        if (iVar2 == 0) {
          iVar2 = FUN_001b4610(param_1,param_2,local_5dc);
          if (iVar2 == 0) {
            if (*(char *)(param_2 + 0x25d6f) != -1) {
              local_5d0 = *(undefined4 *)(param_2 + 0x25d68);
              iVar2 = FUN_0019c780(uVar5,DAT_0038088c,local_5dc,0x2080852c,&local_5d8,0x5a0,0);
              switch(iVar2) {
              case 0:
                *param_3 = aiStack_5b4[(ulong)*(byte *)(param_2 + 0x25d6f) * 0x16] >> 8;
                return iVar2;
              default:
                return 999;
              case 3:
              case 0x66:
                return 10;
              case 0xf:
                return iVar2;
              case 0x17:
              case 99:
                return 0x13;
              case 0x1a:
                return 0x17;
              case 0x1b:
                return 4;
              case 0x1f:
              case 0x3b:
              case 0x54:
                return 2;
              case 0x51:
                return 0x14;
              case 0x55:
                return 0x1b;
              case 0x56:
                return 3;
              case 0x59:
                return 0x11;
              case 0x62:
                return 0x10;
              }
            }
            if (DAT_01216a78 < 5) {
              return 3;
            }
            fVar6 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                         "DEBUG",lVar3,"dmal/common/common_thermal.c",0x236);
            return 3;
          }
          if (DAT_01216a78 < 2) {
            return iVar2;
          }
          fVar6 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          uVar8 = 0x232;
          uVar5 = 0x232;
          dVar7 = (double)(fVar6 * DAT_00298548);
          goto LAB_001b49bb;
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      uVar8 = 0x22f;
      uVar5 = 0x22f;
      dVar7 = (double)(fVar6 * DAT_00298548);
      goto LAB_001b49bb;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar6 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  uVar8 = 0x22b;
  uVar5 = 0x22b;
  dVar7 = (double)(fVar6 * DAT_00298548);
LAB_001b49bb:
  FUN_002340f0(dVar7,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
               "dmal/common/common_thermal.c",uVar5,
               "cDeviceGetMemMaxOperatingTemperatureThresholdInternal",uVar8,iVar2);
  return iVar2;
}


// ===== 001b4bd0 FUN_001b4bd0 =====

int FUN_001b4bd0(long param_1,long param_2,int *param_3)

{
  byte bVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  float fVar7;
  undefined8 uVar8;
  undefined4 local_5dc;
  undefined8 local_5d8;
  undefined4 local_5d0;
  int aiStack_5b4 [353];
  
  puVar5 = &local_5d8;
  for (lVar4 = 0xb4; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    uVar6 = *(undefined8 *)(param_1 + 0x10);
    iVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_5dc);
    if (iVar3 == 0) {
      iVar3 = FUN_001b4610(param_1,param_2,local_5dc);
      if (iVar3 == 0) {
        bVar1 = *(byte *)(param_2 + 0x25d6c);
        if (bVar1 != 0xff) {
          local_5d0 = *(undefined4 *)(param_2 + 0x25d68);
          iVar3 = FUN_0019c780(uVar6,DAT_0038088c,local_5dc,0x2080852c,&local_5d8,0x5a0,0);
          switch(iVar3) {
          case 0:
            *param_3 = aiStack_5b4[(ulong)bVar1 * 0x16] >> 8;
            return iVar3;
          default:
            return 999;
          case 3:
          case 0x66:
            return 10;
          case 0xf:
            return iVar3;
          case 0x17:
          case 99:
            return 0x13;
          case 0x1a:
            return 0x17;
          case 0x1b:
            return 4;
          case 0x1f:
          case 0x3b:
          case 0x54:
            return 2;
          case 0x51:
            return 0x14;
          case 0x55:
            return 0x1b;
          case 0x56:
            return 3;
          case 0x59:
            return 0x11;
          case 0x62:
            return 0x10;
          }
        }
        if (DAT_01216a78 < 5) {
          return 3;
        }
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                     lVar4,"dmal/common/common_thermal.c",0x259);
        return 3;
      }
      if (DAT_01216a78 < 2) {
        return iVar3;
      }
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      fVar7 = fVar7 * DAT_00298548;
      uVar8 = 0x255;
      uVar6 = 0x255;
      goto LAB_001b4cbb;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar3;
  }
  fVar7 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  fVar7 = fVar7 * DAT_00298548;
  uVar8 = 0x252;
  uVar6 = 0x252;
LAB_001b4cbb:
  FUN_002340f0((double)fVar7,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
               "dmal/common/common_thermal.c",uVar6,
               "cDeviceGetGpuMaxOperatingTempereatureThresholdInternal",uVar8,iVar3);
  return iVar3;
}


// ===== 001b4f10 FUN_001b4f10 =====

int FUN_001b4f10(long param_1,long param_2,uint *param_3)

{
  code *pcVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  float fVar9;
  undefined8 uVar10;
  undefined4 local_143c;
  undefined8 local_1438 [224];
  undefined8 local_d38;
  undefined4 local_d30;
  uint local_a58;
  
  uVar8 = *(undefined8 *)(param_1 + 0x10);
  puVar7 = local_1438;
  for (lVar6 = 0xdf; lVar6 != 0; lVar6 = lVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  puVar7 = &local_d38;
  for (lVar6 = 0x19f; lVar6 != 0; lVar6 = lVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined4 *)puVar7 = 0;
  lVar6 = *(long *)(param_2 + 0x256d8);
  if (((lVar6 == 0) || (*(undefined8 **)(lVar6 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar6 + 0x50), pcVar1 == (code *)0x0)) {
    iVar4 = 3;
  }
  else {
    iVar4 = (*pcVar1)(lVar6,param_2,0x2080,&local_143c);
    if (iVar4 == 0) {
      cVar3 = FUN_001b4740(param_1,param_2,local_143c);
      if (cVar3 == '\0') {
        return 3;
      }
      iVar4 = FUN_001b4610(param_1,param_2,local_143c);
      if (iVar4 == 0) {
        local_d30 = *(undefined4 *)(param_2 + 0x25d68);
        iVar4 = FUN_0019c780(uVar8,DAT_0038088c,local_143c,0x2080852b,&local_d38,0xcfc,0);
        switch(iVar4) {
        case 0:
          goto switchD_001b5157_caseD_0;
        default:
          return 999;
        case 3:
        case 0x66:
          return 10;
        case 0xf:
          return iVar4;
        case 0x17:
        case 99:
          return 0x13;
        case 0x1a:
          return 0x17;
        case 0x1b:
          return 4;
        case 0x1f:
        case 0x3b:
        case 0x54:
          return 2;
        case 0x51:
          return 0x14;
        case 0x55:
          return 0x1b;
        case 0x56:
          return 3;
        case 0x59:
          return 0x11;
        case 0x62:
          return 0x10;
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar4;
      }
      fVar9 = (float)FUN_002917b0(&DAT_01216a60);
      lVar6 = syscall(0xba);
      fVar9 = fVar9 * DAT_00298548;
      uVar10 = 0xa15;
      uVar8 = 0xa15;
      goto LAB_001b5013;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar4;
  }
  fVar9 = (float)FUN_002917b0(&DAT_01216a60);
  lVar6 = syscall(0xba);
  fVar9 = fVar9 * DAT_00298548;
  uVar10 = 0xa0d;
  uVar8 = 0xa0d;
LAB_001b5013:
  FUN_002340f0((double)fVar9,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar6,
               "dmal/common/common_thermal.c",uVar8,"cDeviceGetMarginTemperatureHelper_v1",uVar10,
               iVar4);
  return iVar4;
switchD_001b5157_caseD_0:
  uVar2 = local_a58 >> 8 | 0xff000000;
  if (-1 < (int)local_a58) {
    uVar2 = local_a58 >> 8;
  }
  uVar5 = uVar2;
  if ((local_a58 & 0x80) != 0) {
    uVar5 = uVar2 - 1;
    if (-1 < (int)local_a58) {
      uVar5 = uVar2 + 1;
    }
  }
  *param_3 = uVar5;
  return iVar4;
}


// ===== 001b5210 FUN_001b5210 =====

int FUN_001b5210(undefined8 param_1,undefined8 param_2,int *param_3)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  iVar1 = 0x19;
  if (((*param_3 == 0x1000008) && (iVar1 = FUN_001b4f10(param_1,param_2,param_3 + 1), iVar1 != 0))
     && (1 < DAT_01216a78)) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar2,"dmal/common/common_thermal.c",0xa2e,"cDeviceGetGlobalLimitCountdown"
                 ,0xa2e,iVar1);
  }
  return iVar1;
}


// ===== 001b52d0 FUN_001b52d0 =====

/* WARNING: Removing unreachable block (ram,0x001b5630) */
/* WARNING: Removing unreachable block (ram,0x001b5650) */
/* WARNING: Removing unreachable block (ram,0x001b5635) */
/* WARNING: Removing unreachable block (ram,0x001b5640) */
/* WARNING: Removing unreachable block (ram,0x001b5510) */
/* WARNING: Removing unreachable block (ram,0x001b5583) */
/* WARNING: Removing unreachable block (ram,0x001b5588) */
/* WARNING: Removing unreachable block (ram,0x001b55d1) */
/* WARNING: Removing unreachable block (ram,0x001b5606) */
/* WARNING: Removing unreachable block (ram,0x001b560f) */
/* WARNING: Removing unreachable block (ram,0x001b5618) */
/* WARNING: Removing unreachable block (ram,0x001b5621) */
/* WARNING: Removing unreachable block (ram,0x001b55e0) */
/* WARNING: Removing unreachable block (ram,0x001b5520) */
/* WARNING: Removing unreachable block (ram,0x001b56d6) */
/* WARNING: Removing unreachable block (ram,0x001b56ec) */
/* WARNING: Removing unreachable block (ram,0x001b5569) */
/* WARNING: Removing unreachable block (ram,0x001b5572) */
/* WARNING: Removing unreachable block (ram,0x001b5576) */
/* WARNING: Removing unreachable block (ram,0x001b557f) */
/* WARNING: Removing unreachable block (ram,0x001b55a0) */
/* WARNING: Removing unreachable block (ram,0x001b5736) */
/* WARNING: Recovered jumptable eliminated as dead code */

int FUN_001b52d0(long param_1,long param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  int *piVar4;
  float fVar5;
  
  if (*(int *)(param_2 + 0x6e0) == 0) {
    do {
      iVar1 = FUN_00291820(param_2 + 0x6e4,1,0);
    } while (iVar1 != 0);
    if (*(int *)(param_2 + 0x6e0) == 0) {
      *(undefined8 *)(param_2 + 0x6f0) = 0;
      iVar1 = FUN_001b3070(*(undefined8 *)(param_1 + 0x10),param_2);
      if (iVar1 == 0) {
        *(undefined8 *)(param_2 + 0x6f0) = 0;
      }
      else if (1 < DAT_01216a78) {
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                     "ERROR",lVar3,"dmal/common/common_thermal.c",0xc5,
                     "cCreateNvmlTempSensorToRmSensorIndexCache",0xc5,iVar1);
      }
      *(undefined4 *)(param_2 + 0x6e0) = 1;
      *(int *)(param_2 + 0x6e8) = iVar1;
    }
    FUN_00291830(param_2 + 0x6e4,0);
  }
  iVar1 = *(int *)(param_2 + 0x6e8);
  if (iVar1 == 0) {
    piVar4 = (int *)(param_2 + 0x68c);
    uVar2 = 0;
    if (*(ulong *)(param_2 + 0x6f0) != 0) {
      do {
        if (*piVar4 == param_3) {
          *param_4 = *(undefined4 *)(param_2 + (uVar2 & 0xffffffff) * 0xc + 0x694);
          return 0;
        }
        uVar2 = uVar2 + 1;
        piVar4 = piVar4 + 3;
      } while (*(ulong *)(param_2 + 0x6f0) != uVar2);
    }
    iVar1 = 3;
    if (4 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                   lVar3,"dmal/common/common_thermal.c",0x100,param_3);
    }
  }
  else if (1 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar3,"dmal/common/common_thermal.c",0xef,
                 "cConvertNvmlTemperatureSensorToRmSensorIndex",0xef,iVar1);
  }
  return iVar1;
}


// ===== 001b5780 FUN_001b5780 =====

int FUN_001b5780(long param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  double dVar6;
  undefined8 uVar7;
  undefined4 local_6c;
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined8 local_48;
  undefined4 local_40;
  
  local_48 = 0;
  local_40 = 0;
  local_68 = (undefined1  [16])0x0;
  local_58 = (undefined1  [16])0x0;
  iVar2 = FUN_001b52d0(param_1,param_2,param_3,&local_6c);
  if (iVar2 == 0) {
    local_48 = 0;
    local_40 = 0;
    local_68._0_12_ = ZEXT412(0x555) << 0x40;
    local_68._12_4_ = local_6c;
    local_58 = (undefined1  [16])0x0;
    iVar2 = FUN_001b3070(*(undefined8 *)(param_1 + 0x10),param_2,local_68);
    if (iVar2 == 0) {
      if (4 < DAT_01216a78) {
        uVar1 = local_58._0_4_;
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%X\n",
                     "DEBUG",lVar3,"dmal/common/common_thermal.c",0x509,uVar1);
      }
      if (local_58._0_4_ == 0) {
        return 3;
      }
      if (local_58._0_4_ == 1) {
        local_48 = 0;
        local_40 = 0;
        local_68._0_12_ = ZEXT412(0x556) << 0x40;
        local_68._12_4_ = local_6c;
        local_58 = (undefined1  [16])0x0;
        iVar2 = FUN_001b3070(*(undefined8 *)(param_1 + 0x10),param_2,local_68);
        if (iVar2 != 0) {
          if (DAT_01216a78 < 2) {
            return iVar2;
          }
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          uVar7 = 0x51b;
          uVar4 = 0x51b;
          dVar6 = (double)(fVar5 * DAT_00298548);
          goto LAB_001b5845;
        }
        if (4 < DAT_01216a78) {
          uVar1 = local_58._0_4_;
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%X\n",
                       "DEBUG",lVar3,"dmal/common/common_thermal.c",0x51d,uVar1);
        }
        if (local_58._0_4_ == 0) {
          *param_4 = 0;
          return 0;
        }
        if (local_58._0_4_ == 1) {
          *param_4 = 1;
          return 0;
        }
      }
      return 999;
    }
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    uVar7 = 0x507;
    uVar4 = 0x507;
    dVar6 = (double)(fVar5 * DAT_00298548);
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    uVar7 = 0x4ff;
    uVar4 = 0x4ff;
    dVar6 = (double)(fVar5 * DAT_00298548);
  }
LAB_001b5845:
  FUN_002340f0(dVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
               "dmal/common/common_thermal.c",uVar4,"cDeviceGetSimulationTemperatureState",uVar7,
               iVar2);
  return iVar2;
}


// ===== 001b5b00 FUN_001b5b00 =====

int FUN_001b5b00(long param_1,undefined8 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  double dVar6;
  undefined8 uVar7;
  undefined4 local_6c;
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined8 local_48;
  undefined4 local_40;
  
  local_48 = 0;
  local_40 = 0;
  local_68 = (undefined1  [16])0x0;
  local_58 = (undefined1  [16])0x0;
  iVar2 = FUN_00236dd0();
  if (iVar2 == 0) {
    return 4;
  }
  iVar2 = FUN_001b52d0(param_1,param_2,param_3,&local_6c);
  if (iVar2 == 0) {
    local_48 = 0;
    local_40 = 0;
    local_68._0_12_ = ZEXT412(0x555) << 0x40;
    local_68._12_4_ = local_6c;
    local_58 = (undefined1  [16])0x0;
    iVar2 = FUN_001b3070(*(undefined8 *)(param_1 + 0x10),param_2,local_68);
    if (iVar2 == 0) {
      if (4 < DAT_01216a78) {
        uVar1 = local_58._0_4_;
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%X\n",
                     "DEBUG",lVar3,"dmal/common/common_thermal.c",0x4db,uVar1);
      }
      if (local_58._0_4_ == 0) {
        return 3;
      }
      if (local_58._0_4_ != 1) {
        return 999;
      }
      local_48 = 0;
      local_40 = 0;
      local_68._0_12_ = ZEXT412(0x559) << 0x40;
      local_68._12_4_ = local_6c;
      local_58 = (undefined1  [16])0x0;
      iVar2 = FUN_001b3070(*(undefined8 *)(param_1 + 0x10),param_2,local_68);
      if (iVar2 == 0) {
        return 0;
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      uVar7 = 0x4ee;
      uVar4 = 0x4ee;
      dVar6 = (double)(fVar5 * DAT_00298548);
    }
    else {
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      uVar7 = 0x4d9;
      uVar4 = 0x4d9;
      dVar6 = (double)(fVar5 * DAT_00298548);
    }
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    uVar7 = 0x4d1;
    uVar4 = 0x4d1;
    dVar6 = (double)(fVar5 * DAT_00298548);
  }
  FUN_002340f0(dVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
               "dmal/common/common_thermal.c",uVar4,"cDeviceClearSimulationTemperature",uVar7,iVar2)
  ;
  return iVar2;
}


// ===== 001b5de0 FUN_001b5de0 =====

int FUN_001b5de0(long param_1,undefined8 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  double dVar6;
  undefined8 uVar7;
  undefined4 local_6c;
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined8 local_48;
  undefined4 local_40;
  
  local_48 = 0;
  local_40 = 0;
  local_68 = (undefined1  [16])0x0;
  local_58 = (undefined1  [16])0x0;
  iVar2 = FUN_00236dd0();
  if (iVar2 == 0) {
    return 4;
  }
  iVar2 = FUN_001b52d0(param_1,param_2,param_3,&local_6c);
  if (iVar2 == 0) {
    local_48 = 0;
    local_40 = 0;
    local_68._0_12_ = ZEXT412(0x555) << 0x40;
    local_68._12_4_ = local_6c;
    local_58 = (undefined1  [16])0x0;
    iVar2 = FUN_001b3070(*(undefined8 *)(param_1 + 0x10),param_2,local_68);
    if (iVar2 == 0) {
      if (4 < DAT_01216a78) {
        uVar1 = local_58._0_4_;
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%X\n",
                     "DEBUG",lVar3,"dmal/common/common_thermal.c",0x4a7,uVar1);
      }
      if (local_58._0_4_ == 0) {
        return 3;
      }
      if (local_58._0_4_ != 1) {
        return 999;
      }
      local_48 = 0;
      local_40 = 0;
      local_68._0_12_ = ZEXT412(0x559) << 0x40;
      local_68._12_4_ = local_6c;
      local_58._8_8_ = 0;
      local_58._4_4_ = param_4;
      local_58._0_4_ = 1;
      iVar2 = FUN_001b3070(*(undefined8 *)(param_1 + 0x10),param_2,local_68);
      if (iVar2 == 0) {
        return 0;
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      uVar7 = 0x4bb;
      uVar4 = 0x4bb;
      dVar6 = (double)(fVar5 * DAT_00298548);
    }
    else {
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      uVar7 = 0x4a5;
      uVar4 = 0x4a5;
      dVar6 = (double)(fVar5 * DAT_00298548);
    }
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    uVar7 = 0x49e;
    uVar4 = 0x49e;
    dVar6 = (double)(fVar5 * DAT_00298548);
  }
  FUN_002340f0(dVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
               "dmal/common/common_thermal.c",uVar4,"cDeviceSetSimulationTemperature",uVar7,iVar2);
  return iVar2;
}


// ===== 001b60c0 FUN_001b60c0 =====

undefined4
FUN_001b60c0(long param_1,long param_2,undefined4 *param_3,undefined4 *param_4,char param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_5 == '\0') {
    if (*(int *)(param_2 + 0x748cc) == 0) {
      do {
        iVar1 = FUN_00291820(param_2 + 0x748d0,1,0);
      } while (iVar1 != 0);
      if (*(int *)(param_2 + 0x748cc) == 0) {
        uVar2 = FUN_001b3eb0(*(undefined8 *)(param_1 + 0x10),param_2,0);
        *(undefined4 *)(param_2 + 0x748cc) = 1;
        *(undefined4 *)(param_2 + 0x748d4) = uVar2;
      }
      FUN_00291830(param_2 + 0x748d0,0);
    }
    uVar2 = *(undefined4 *)(param_2 + 0x748d4);
    *param_3 = *(undefined4 *)(param_2 + 0x748c8);
  }
  else {
    if (*(int *)(param_2 + 0x748bc) == 0) {
      do {
        iVar1 = FUN_00291820(param_2 + 0x748c0,1,0);
      } while (iVar1 != 0);
      if (*(int *)(param_2 + 0x748bc) == 0) {
        uVar2 = FUN_001b3eb0(*(undefined8 *)(param_1 + 0x10),param_2,1);
        *(undefined4 *)(param_2 + 0x748bc) = 1;
        *(undefined4 *)(param_2 + 0x748c4) = uVar2;
      }
      FUN_00291830(param_2 + 0x748c0,0);
    }
    uVar2 = *(undefined4 *)(param_2 + 0x748c4);
    *param_3 = *(undefined4 *)(param_2 + 0x748b8);
  }
  *param_4 = *(undefined4 *)(param_2 + 0x748d8);
  return uVar2;
}


// ===== 001b6220 FUN_001b6220 =====

int FUN_001b6220(char *param_1,uint *param_2,uint param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  float fVar5;
  
  iVar2 = 2;
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
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
    if (iVar2 == 0) {
      if (4 < DAT_01216a78) {
        uVar3 = *(undefined4 *)(param_1 + 0x708);
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tisArchOrNewer called: %d %d\n","DEBUG",
                     lVar4,"/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h",0x3d,
                     param_3,uVar3);
      }
      *param_2 = (uint)(param_3 <= *(uint *)(param_1 + 0x708));
    }
    else if (iVar2 == 0xf) {
      if (4 < DAT_01216a78) {
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tisArchOrNewer error: %d\n","DEBUG",lVar4,
                     "/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h",0x42,param_3)
        ;
      }
    }
    else {
      if (1 < DAT_01216a78) {
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tFailure to determine Architecture\n",
                     "ERROR",lVar4,"/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h"
                     ,0x46);
      }
      *param_2 = 0;
      iVar2 = 0;
    }
  }
  return iVar2;
}


// ===== 001b64b0 FUN_001b64b0 =====

int FUN_001b64b0(long param_1,undefined8 param_2,undefined4 *param_3)

{
  int iVar1;
  long lVar2;
  undefined8 *puVar3;
  float fVar4;
  int local_29c;
  undefined8 local_298;
  undefined4 local_28c;
  
  puVar3 = &local_298;
  for (lVar2 = 0x4a; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)puVar3 = 0;
  iVar1 = FUN_001b6220(param_2,&local_29c,6);
  if (iVar1 == 0) {
    iVar1 = 3;
    if (local_29c != 0) {
      iVar1 = FUN_001b3830(*(undefined8 *)(param_1 + 0x10),param_2,&local_298);
      if (iVar1 == 0) {
        *param_3 = local_28c;
      }
      else if (1 < DAT_01216a78) {
        fVar4 = (float)FUN_002917b0(&DAT_01216a60);
        lVar2 = syscall(0xba);
        FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                     "ERROR",lVar2,"dmal/common/common_thermal.c",0x5b5,
                     "cDeviceGetCoolerMaskUncached",0x5b5,iVar1);
      }
    }
  }
  return iVar1;
}


// ===== 001b65d0 FUN_001b65d0 =====

int FUN_001b65d0(undefined8 param_1,long param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  float fVar5;
  
  if (*(int *)(param_2 + 0x680) == 0) {
    do {
      iVar2 = FUN_00291820(param_2 + 0x684,1,0);
    } while (iVar2 != 0);
    if (*(int *)(param_2 + 0x680) == 0) {
      uVar3 = FUN_001b64b0(param_1,param_2,param_2 + 0x67c);
      *(undefined4 *)(param_2 + 0x680) = 1;
      *(undefined4 *)(param_2 + 0x688) = uVar3;
    }
    FUN_00291830(param_2 + 0x684,0);
  }
  iVar2 = *(int *)(param_2 + 0x688);
  if (iVar2 == 0) {
    uVar3 = *(undefined4 *)(param_2 + 0x67c);
    *param_3 = uVar3;
    if (4 < DAT_01216a78) {
      uVar1 = *(undefined4 *)(param_2 + 4);
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %x %d\n",
                   "DEBUG",lVar4,"dmal/common/common_thermal.c",0x5c8,uVar1,uVar3,0);
      return 0;
    }
  }
  else if (1 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_thermal.c",0x5c4,"cDeviceGetCoolerMask",0x5c4,
                 iVar2);
    return iVar2;
  }
  return iVar2;
}


// ===== 001b67a0 FUN_001b67a0 =====

int FUN_001b67a0(long param_1,long param_2,int *param_3,uint param_4)

{
  byte bVar1;
  char cVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  ulong uVar8;
  float fVar9;
  undefined8 uVar10;
  int local_5dc;
  undefined8 local_5d8;
  undefined4 local_5d0;
  int aiStack_5b4 [353];
  
  puVar6 = &local_5d8;
  for (lVar5 = 0xb4; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  uVar7 = *(undefined8 *)(param_1 + 0x10);
  iVar4 = FUN_001b6220(param_2,&local_5dc,6);
  if (iVar4 != 0) {
    return iVar4;
  }
  iVar4 = 3;
  if (local_5dc == 0) {
    return 3;
  }
  lVar5 = *(long *)(param_2 + 0x256d8);
  if ((((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x50) == (undefined8 *)0x0)) ||
      (pcVar3 = (code *)**(undefined8 **)(lVar5 + 0x50), pcVar3 == (code *)0x0)) ||
     (iVar4 = (*pcVar3)(lVar5,param_2,0x2080,&local_5dc), iVar4 != 0)) {
    if (DAT_01216a78 < 2) {
      return iVar4;
    }
    fVar9 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    fVar9 = fVar9 * DAT_00298548;
    uVar7 = 0x278;
    uVar10 = 0x278;
LAB_001b68d0:
    FUN_002340f0((double)fVar9,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,
                 "dmal/common/common_thermal.c",uVar7,
                 "cDeviceGetGpuTargetTemperatureThresholdInternal",uVar10,iVar4);
    return iVar4;
  }
  iVar4 = FUN_001b4610(param_1,param_2,local_5dc);
  if (iVar4 != 0) {
    if (DAT_01216a78 < 2) {
      return iVar4;
    }
    fVar9 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    fVar9 = fVar9 * DAT_00298548;
    uVar7 = 0x27b;
    uVar10 = 0x27b;
    goto LAB_001b68d0;
  }
  bVar1 = *(byte *)(param_2 + 0x25d6e);
  uVar8 = (ulong)bVar1;
  if (bVar1 == 0xff) {
    if ((param_4 != 7) ||
       (uVar8 = (ulong)*(byte *)(param_2 + 0x25d6d), *(byte *)(param_2 + 0x25d6d) == 0xff)) {
LAB_001b6bc5:
      if (4 < DAT_01216a78) {
        fVar9 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                     lVar5,"dmal/common/common_thermal.c",0x28e);
        return 3;
      }
      return 3;
    }
  }
  else {
    cVar2 = *(char *)(param_2 + 0x25d6d);
    if (cVar2 != -1) {
      if (4 < DAT_01216a78) {
        fVar9 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %d\n",
                     "DEBUG",lVar5,"dmal/common/common_thermal.c",0x281,bVar1,cVar2);
        return 3;
      }
      return 3;
    }
    if (param_4 == 7) goto LAB_001b6bc5;
    if (param_4 == 6) {
      iVar4 = *(int *)(param_2 + 0x25d84 + uVar8 * 0x6c);
      goto LAB_001b696c;
    }
    if (6 < param_4) {
      return 2;
    }
    if (param_4 == 4) {
      iVar4 = *(int *)(param_2 + 0x25d7c + uVar8 * 0x6c);
      goto LAB_001b696c;
    }
    if (param_4 != 5) {
      return 2;
    }
  }
  local_5d0 = *(undefined4 *)(param_2 + 0x25d68);
  iVar4 = FUN_0019c780(uVar7,DAT_0038088c,local_5dc,0x2080852c,&local_5d8,0x5a0,0);
  switch(iVar4) {
  case 0:
    iVar4 = aiStack_5b4[uVar8 * 0x16];
    break;
  default:
    return 999;
  case 3:
  case 0x66:
    return 10;
  case 0xf:
    return iVar4;
  case 0x17:
  case 99:
    return 0x13;
  case 0x1a:
    return 0x17;
  case 0x1b:
    return 4;
  case 0x1f:
  case 0x3b:
  case 0x54:
    return 2;
  case 0x51:
    return 0x14;
  case 0x55:
    return 0x1b;
  case 0x56:
    return 3;
  case 0x59:
    return 0x11;
  case 0x62:
    return 0x10;
  }
LAB_001b696c:
  *param_3 = iVar4 >> 8;
  return 0;
}


// ===== 001b6c50 FUN_001b6c50 =====

int FUN_001b6c50(long param_1,char *param_2,undefined4 param_3,int *param_4)

{
  code *pcVar1;
  undefined1 auVar2 [16];
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  float fVar7;
  uint local_6c;
  undefined1 local_68 [12];
  uint uStack_5c;
  undefined1 local_58 [16];
  undefined8 local_48;
  undefined4 local_40;
  
  if (DAT_0032f668 != 0) {
    auVar2._12_4_ = 0;
    auVar2._0_12_ = stack0xffffffffffffff9c;
    _local_68 = auVar2 << 0x20;
    iVar4 = FUN_001b6220(param_2,local_68,10);
    if (((iVar4 == 0) && (local_68._0_4_ != 0)) &&
       ((param_2 == (char *)0x0 || ((*param_2 == '\x01' || (*(long *)(param_2 + 0x20) != 0)))))) {
      lVar5 = *(long *)(param_2 + 0x256d8);
      local_6c = local_6c & 0xffffff00;
      if ((lVar5 != 0) &&
         ((*(long *)(lVar5 + 0x38) != 0 &&
          (pcVar1 = *(code **)(*(long *)(lVar5 + 0x38) + 0x80), pcVar1 != (code *)0x0)))) {
        (*pcVar1)(lVar5,param_2,&local_6c);
        if ((char)local_6c != '\0') goto LAB_001b6d40;
        lVar5 = *(long *)(param_2 + 0x256d8);
      }
      local_6c = local_6c & 0xffffff00;
      if (lVar5 != 0) {
        if ((*(long *)(lVar5 + 0x38) != 0) &&
           (pcVar1 = *(code **)(*(long *)(lVar5 + 0x38) + 0x88), pcVar1 != (code *)0x0)) {
          (*pcVar1)(lVar5,param_2,&local_6c);
          if ((char)local_6c != '\0') goto LAB_001b6d40;
          lVar5 = *(long *)(param_2 + 0x256d8);
        }
        if ((((lVar5 != 0) && (*(long *)(lVar5 + 0x120) != 0)) &&
            (pcVar1 = *(code **)(*(long *)(lVar5 + 0x120) + 0x40), pcVar1 != (code *)0x0)) &&
           (iVar4 = (*pcVar1)(lVar5,param_2,param_3,param_4), iVar4 == 0)) {
          return 0;
        }
      }
    }
  }
LAB_001b6d40:
  local_40 = 0;
  local_48 = 0;
  local_58 = (undefined1  [16])0x0;
  _local_68 = (undefined1  [16])0x0;
  iVar6 = 5;
  iVar4 = FUN_001b52d0(param_1,param_2,param_3,&local_6c);
  if (iVar4 == 0) {
    do {
      local_48 = 0;
      local_40 = 0;
      local_58 = (undefined1  [16])0x0;
      local_68 = ZEXT412(0x1500) << 0x40;
      uStack_5c = local_6c;
      iVar4 = FUN_001b3070(*(undefined8 *)(param_1 + 0x10),param_2,local_68);
      if (iVar4 == 0) {
        uVar3 = local_58._0_4_;
        if (0 < (int)local_58._0_4_) {
          *param_4 = local_58._0_4_;
          if ((int)local_58._0_4_ < 0xfb) {
            return 0;
          }
          if (DAT_01216a78 < 2) {
            return 999;
          }
          fVar7 = (float)FUN_002917b0(&DAT_01216a60);
          lVar5 = syscall(0xba);
          FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n",
                       "ERROR",lVar5,"dmal/common/common_thermal.c",0x143,uVar3);
          goto LAB_001b6e4f;
        }
      }
      else if (iVar4 == 0xf) goto LAB_001b6e55;
      FUN_00292f00(10);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    if (DAT_01216a78 < 5) {
LAB_001b6e4f:
      iVar4 = 999;
    }
    else {
      iVar4 = 999;
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                   lVar5,"dmal/common/common_thermal.c",0x13a);
    }
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar4;
    }
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar5,"dmal/common/common_thermal.c",0x112,"cDeviceGetTemperatureRmApi",
                 0x112,iVar4);
  }
LAB_001b6e55:
  if (1 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar5,"dmal/common/common_thermal.c",0x14f,"cDeviceGetTemperature",0x14f,
                 iVar4);
  }
  return iVar4;
}


// ===== 001b70f0 FUN_001b70f0 =====

int FUN_001b70f0(long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                undefined8 param_5)

{
  int iVar1;
  long lVar2;
  float fVar3;
  undefined4 local_3c [3];
  
  local_3c[0] = 0;
  iVar1 = FUN_001b6220(param_2,local_3c,7);
  if (iVar1 == 0) {
    switch(param_3) {
    case 0:
      iVar1 = FUN_001b4390(*(undefined8 *)(param_1 + 0x10),param_2,param_4,param_5,local_3c[0],0);
      break;
    case 1:
      iVar1 = FUN_001b60c0(param_1,param_2,param_4,param_5,0);
      break;
    case 2:
      iVar1 = FUN_001b4800(param_1,param_2,param_4);
      break;
    case 3:
      iVar1 = FUN_001b4bd0(param_1,param_2,param_4);
      break;
    case 4:
    case 5:
    case 6:
    case 7:
      iVar1 = FUN_001b67a0(param_1,param_2,param_4,param_3);
      break;
    default:
      iVar1 = 2;
    }
  }
  else if (1 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar2,"dmal/common/common_thermal.c",0x2b9,
                 "cDeviceGetTemperatureThresholdInternal",0x2b9,iVar1);
  }
  return iVar1;
}


// ===== 001b7290 FUN_001b7290 =====

int FUN_001b7290(void)

{
  int iVar1;
  long lVar2;
  int *in_RCX;
  float fVar3;
  int local_1c;
  
  iVar1 = FUN_001b70f0();
  if (iVar1 == 0) {
    if (local_1c < 0) {
      return 999;
    }
    *in_RCX = local_1c;
  }
  else if (1 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar2,"dmal/common/common_thermal.c",0x42e,"cDeviceGetTemperatureThreshold"
                 ,0x42e,iVar1);
    return iVar1;
  }
  return iVar1;
}


// ===== 001b7370 FUN_001b7370 =====

int FUN_001b7370(long param_1,long param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  byte bVar7;
  float fVar8;
  double dVar9;
  undefined8 uVar10;
  int local_420;
  uint local_41c;
  undefined1 local_418 [16];
  undefined1 local_408 [16];
  undefined1 local_3f8 [16];
  char acStack_3e4 [20];
  char acStack_3d0 [928];
  
  bVar7 = 0;
  iVar2 = FUN_001b6220(param_2,&local_420,6);
  if (iVar2 == 0) {
    if (local_420 != 0) {
      puVar5 = (undefined8 *)local_418;
      for (lVar4 = 0x7a; lVar4 != 0; lVar4 = lVar4 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + (ulong)bVar7 * -2 + 1;
      }
      *(undefined4 *)puVar5 = 0;
      iVar2 = FUN_001b65d0(param_1,param_2,&local_41c);
      if (iVar2 == 0) {
        return 0;
      }
      local_418._12_4_ = local_41c;
      iVar2 = FUN_001b3530(*(undefined8 *)(param_1 + 0x10),param_2,local_418);
      if (iVar2 == 0) {
        return 0;
      }
      if (local_41c == 0) {
        return 0;
      }
      uVar3 = 0;
      if ((local_41c & 1) == 0) {
        do {
          uVar3 = (ulong)((int)uVar3 + 1);
          local_41c = local_41c >> 1;
          if (local_41c == 0) {
            return 0;
          }
        } while ((local_41c & 1) == 0);
      }
      else {
        uVar3 = 0;
      }
      if (((local_3f8[uVar3 * 0x3c + 4] == '\0') && (acStack_3e4[uVar3 * 0x3c] == '\0')) &&
         (acStack_3d0[uVar3 * 0x3c] == '\0')) {
switchD_001b7487_caseD_10:
        *param_3 = 5;
        return 0;
      }
switchD_001b7487_caseD_1:
      *param_3 = 1;
      return 0;
    }
    lVar4 = *(long *)(param_2 + 0x256d8);
    local_418 = (undefined1  [16])0x0;
    local_408 = (undefined1  [16])0x0;
    local_3f8 = (undefined1  [16])0x0;
    if (((lVar4 == 0) || (*(long *)(lVar4 + 0x118) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(lVar4 + 0x118) + 0x38), pcVar1 == (code *)0x0)) {
      iVar2 = 3;
    }
    else {
      iVar2 = (*pcVar1)(lVar4,param_2,&local_41c);
      if (iVar2 == 0) {
        if (local_41c != 1) {
          return 3;
        }
        local_418._8_8_ = 0x2010;
        iVar2 = FUN_001b39b0(*(undefined8 *)(param_1 + 0x10),param_2,local_418,1);
        if (iVar2 == 0) {
          switch(local_408._0_4_) {
          case 0:
            *param_3 = 0;
            return 0;
          case 1:
            goto switchD_001b7487_caseD_1;
          case 2:
            *param_3 = 2;
            return 0;
          default:
            if (DAT_01216a78 < 2) {
              return 999;
            }
            fVar8 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            FUN_002340f0((double)(fVar8 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                         "ERROR",lVar4,"dmal/common/common_thermal.c",0x9d5);
            return 999;
          case 4:
            *param_3 = 3;
            return 0;
          case 8:
            *param_3 = 4;
            return 0;
          case 0x10:
            goto switchD_001b7487_caseD_10;
          }
        }
        if (DAT_01216a78 < 2) {
          return iVar2;
        }
        fVar8 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        uVar10 = 0x9b8;
        uVar6 = 0x9b8;
        dVar9 = (double)(fVar8 * DAT_00298548);
        goto LAB_001b759b;
      }
    }
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar8 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    uVar10 = 0x9ab;
    uVar6 = 0x9ab;
    dVar9 = (double)(fVar8 * DAT_00298548);
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar8 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    uVar10 = 0x986;
    uVar6 = 0x986;
    dVar9 = (double)(fVar8 * DAT_00298548);
  }
LAB_001b759b:
  FUN_002340f0(dVar9,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
               "dmal/common/common_thermal.c",uVar6,"cDeviceGetFanControlPolicy",uVar10,iVar2);
  return iVar2;
}


// ===== 001b77a0 FUN_001b77a0 =====

int FUN_001b77a0(long param_1,long param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  undefined8 uVar6;
  float fVar7;
  double dVar8;
  undefined8 uVar9;
  int local_6c;
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  
  if (*(int *)(param_2 + 0x670) != 0) {
    iVar3 = *(int *)(param_2 + 0x678);
    goto joined_r0x001b7852;
  }
  do {
    iVar3 = FUN_00291820(param_2 + 0x674,1,0);
  } while (iVar3 != 0);
  if (*(int *)(param_2 + 0x670) == 0) {
    iVar3 = FUN_001b6220(param_2,&local_6c,6);
    if (iVar3 == 0) {
      if (local_6c == 0) {
        local_58 = (undefined1  [16])0x0;
        local_68._0_12_ = ZEXT412(0x1000) << 0x40;
        local_68._12_4_ = 0;
        local_48 = (undefined1  [16])0x0;
        iVar3 = FUN_001b39b0(*(undefined8 *)(param_1 + 0x10),param_2,local_68,1);
        if (iVar3 == 0) {
          *(undefined4 *)(param_2 + 0x66c) = local_68._12_4_;
        }
        else if (1 < DAT_01216a78) {
          fVar7 = (float)FUN_002917b0(&DAT_01216a60);
          lVar5 = syscall(0xba);
          uVar9 = 0x5e8;
          uVar6 = 0x5e8;
          dVar8 = (double)(fVar7 * DAT_00298548);
          goto LAB_001b7a22;
        }
      }
      else {
        iVar3 = FUN_001b65d0(param_1,param_2,local_68);
        if (iVar3 == 0) {
          uVar4 = local_68._0_4_ - ((uint)local_68._0_4_ >> 1 & 0x55555555);
          uVar4 = (uVar4 & 0x33333333) + (uVar4 >> 2 & 0x33333333);
          *(uint *)(param_2 + 0x66c) = ((uVar4 >> 4) + uVar4 & 0xf0f0f0f) * 0x1010101 >> 0x18;
        }
        else if (1 < DAT_01216a78) {
          fVar7 = (float)FUN_002917b0(&DAT_01216a60);
          lVar5 = syscall(0xba);
          uVar9 = 0x5dd;
          uVar6 = 0x5dd;
          dVar8 = (double)(fVar7 * DAT_00298548);
          goto LAB_001b7a22;
        }
      }
    }
    else if (1 < DAT_01216a78) {
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      uVar9 = 0x5d6;
      uVar6 = 0x5d6;
      dVar8 = (double)(fVar7 * DAT_00298548);
LAB_001b7a22:
      FUN_002340f0(dVar8,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,
                   "dmal/common/common_thermal.c",uVar6,"cDeviceGetNumberOfFansUncached",uVar9,iVar3
                  );
    }
    *(int *)(param_2 + 0x678) = iVar3;
    *(undefined4 *)(param_2 + 0x670) = 1;
  }
  FUN_00291830(param_2 + 0x674,0);
  iVar3 = *(int *)(param_2 + 0x678);
joined_r0x001b7852:
  if (iVar3 == 0) {
    uVar1 = *(undefined4 *)(param_2 + 0x66c);
    *param_3 = uVar1;
    if (4 < DAT_01216a78) {
      uVar2 = *(undefined4 *)(param_2 + 4);
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u %d\n",
                   "DEBUG",lVar5,"dmal/common/common_thermal.c",0x5fa,uVar2,uVar1,0);
    }
  }
  else if (1 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar5,"dmal/common/common_thermal.c",0x5f6,"cDeviceGetNumberOfFans",0x5f6,
                 iVar3);
  }
  return iVar3;
}


// ===== 001b7b50 FUN_001b7b50 =====

int FUN_001b7b50(undefined8 param_1,undefined8 param_2,uint param_3,int *param_4)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  uint local_40;
  uint local_3c [3];
  
  iVar1 = FUN_001b77a0(param_1,param_2,&local_40);
  if (iVar1 == 0) {
    if (param_3 < local_40) {
      iVar1 = FUN_001b65d0(param_1,param_2,local_3c);
      if (iVar1 != 0) {
        if (DAT_01216a78 < 2) {
          return iVar1;
        }
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar2 = syscall(0xba);
        fVar5 = fVar5 * DAT_00298548;
        uVar6 = 0x621;
        uVar4 = 0x621;
        goto LAB_001b7c49;
      }
      *param_4 = 0;
      for (; local_3c[0] != 0; local_3c[0] = local_3c[0] >> 1) {
        uVar3 = param_3;
        if (((local_3c[0] & 1) != 0) && (uVar3 = param_3 - 1, param_3 == 0)) {
          return 0;
        }
        *param_4 = *param_4 + 1;
        param_3 = uVar3;
      }
    }
    iVar1 = 2;
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar1;
    }
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    fVar5 = fVar5 * DAT_00298548;
    uVar6 = 0x619;
    uVar4 = 0x619;
LAB_001b7c49:
    FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
                 "dmal/common/common_thermal.c",uVar4,"cConvertFanApiIndexToRmIndex",uVar6,iVar1);
  }
  return iVar1;
}


// ===== 001b7ce0 FUN_001b7ce0 =====

int FUN_001b7ce0(long param_1,undefined8 param_2,undefined8 param_3,int *param_4,int *param_5,
                int *param_6,int *param_7)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  float fVar4;
  undefined8 uVar5;
  uint local_38c;
  undefined1 local_388 [4];
  int local_384;
  int aiStack_374 [209];
  
  iVar1 = FUN_001b7b50();
  if (iVar1 == 0) {
    local_384 = 1 << ((byte)local_38c & 0x1f);
    iVar1 = FUN_001b33b0(*(undefined8 *)(param_1 + 0x10),param_2,local_388);
    if (iVar1 == 0) {
      if (param_5 != (int *)0x0) {
        *param_5 = aiStack_374[(ulong)local_38c * 0xd];
      }
      if (param_4 != (int *)0x0) {
        *param_4 = ((uint)(aiStack_374[(ulong)local_38c * 0xd + 3] * 100) >> 0x10) +
                   ((uint)(aiStack_374[(ulong)local_38c * 0xd + 3] * 100) >> 0xf & 1);
      }
      if (param_6 != (int *)0x0) {
        *param_6 = ((uint)(aiStack_374[(ulong)local_38c * 0xd + 1] * 100) >> 0x10) +
                   ((uint)(aiStack_374[(ulong)local_38c * 0xd + 1] * 100) >> 0xf & 1);
      }
      if (param_7 == (int *)0x0) {
        return 0;
      }
      *param_7 = ((uint)(aiStack_374[(ulong)local_38c * 0xd + 2] * 100) >> 0x10) +
                 ((uint)(aiStack_374[(ulong)local_38c * 0xd + 2] * 100) >> 0xf & 1);
      return 0;
    }
    if (DAT_01216a78 < 2) {
      return iVar1;
    }
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    fVar4 = fVar4 * DAT_00298548;
    uVar5 = 0x68a;
    uVar3 = 0x68a;
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar1;
    }
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    fVar4 = fVar4 * DAT_00298548;
    uVar5 = 0x686;
    uVar3 = 0x686;
  }
  FUN_002340f0((double)fVar4,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
               "dmal/common/common_thermal.c",uVar3,"cDeviceGetFanSpeedHelper",uVar5,iVar1);
  return iVar1;
}


// ===== 001b7f00 FUN_001b7f00 =====

int FUN_001b7f00(long param_1,char *param_2,int *param_3)

{
  int iVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  byte bVar5;
  float fVar6;
  undefined8 uVar7;
  int local_2fc;
  undefined8 local_2f8;
  undefined4 local_2f0;
  int local_2ec;
  undefined4 local_2e8;
  undefined4 local_2c0;
  int local_2bc;
  int local_2b8;
  undefined8 local_298;
  int local_28c;
  
  bVar5 = 0;
  puVar3 = &local_298;
  for (lVar2 = 0x4a; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)puVar3 = 0;
  if ((param_2 == (char *)0x0) ||
     (((*param_2 != '\x01' &&
       ((((*(int *)(param_2 + 0x14) == 0 || (*(int *)(param_2 + 0x1c) != 0)) ||
         (*(int *)(param_2 + 0x10) == 0)) || (*(long *)(param_2 + 0x20) == 0)))) ||
      (param_3 == (int *)0x0)))) {
LAB_001b8070:
    iVar1 = 2;
  }
  else {
    if (*param_3 != 0x1000010) {
      return 0x19;
    }
    iVar1 = FUN_001b77a0(param_1,param_2,&local_2fc);
    if (iVar1 != 0) {
      if (DAT_01216a78 < 2) {
        return iVar1;
      }
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar2,"dmal/common/common_thermal.c",0x6fc,"cDeviceGetCoolerInfo",0x6fc,
                   iVar1);
      return iVar1;
    }
    if (local_2fc == 0) {
      return 3;
    }
    iVar1 = FUN_001b3830(*(undefined8 *)(param_1 + 0x10),param_2,&local_298);
    if ((iVar1 == 0) && (local_28c != 0)) {
      param_3[3] = 0xe;
    }
    else {
      puVar3 = &local_2f8;
      for (lVar2 = 0xc; lVar2 != 0; lVar2 = lVar2 + -1) {
        *puVar3 = 0;
        puVar3 = puVar3 + (ulong)bVar5 * -2 + 1;
      }
      local_2ec = param_3[1];
      local_2f0 = 0x1010;
      local_2c0 = 0x1040;
      local_2bc = local_2ec;
      iVar1 = FUN_001b39b0(*(undefined8 *)(param_1 + 0x10),param_2,&local_2f8,2);
      if (iVar1 != 0) {
        if (DAT_01216a78 < 2) {
          return iVar1;
        }
        fVar6 = (float)FUN_002917b0(&DAT_01216a60);
        lVar2 = syscall(0xba);
        FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                     "ERROR",lVar2,"dmal/common/common_thermal.c",0x721,"cDeviceGetCoolerInfo",0x721
                     ,iVar1);
        return iVar1;
      }
      switch(local_2e8) {
      case 0:
        param_3[3] = 1;
        break;
      case 1:
        param_3[3] = 2;
        break;
      case 2:
        param_3[3] = 4;
        break;
      default:
        if (DAT_01216a78 < 2) goto LAB_001b8070;
        fVar6 = (float)FUN_002917b0(&DAT_01216a60);
        lVar2 = syscall(0xba);
        fVar6 = fVar6 * DAT_00298548;
        uVar7 = 0x726;
        uVar4 = 0x726;
        goto LAB_001b804f;
      case 4:
        param_3[3] = 8;
        break;
      case 7:
        param_3[3] = 0xe;
      }
      if (local_2b8 == 1) {
        param_3[2] = 1;
        return 0;
      }
      if (local_2b8 != 2) {
        if (local_2b8 == 0) {
          param_3[2] = 0;
          return 0;
        }
        if (1 < DAT_01216a78) {
          fVar6 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          fVar6 = fVar6 * DAT_00298548;
          uVar7 = 0x727;
          uVar4 = 0x727;
LAB_001b804f:
          FUN_002340f0((double)fVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
                       "dmal/common/common_thermal.c",uVar4,"cDeviceGetCoolerInfo",uVar7,2);
        }
        goto LAB_001b8070;
      }
    }
    param_3[2] = 2;
    iVar1 = 0;
  }
  return iVar1;
}


// ===== 001b8300 FUN_001b8300 =====

int FUN_001b8300(long param_1,undefined8 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  uint local_41c;
  undefined8 local_418;
  int local_40c;
  char acStack_3f4 [16];
  char acStack_3e4 [20];
  char acStack_3d0 [928];
  
  puVar3 = &local_418;
  for (lVar2 = 0x7a; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)puVar3 = 0;
  iVar1 = FUN_001b6220(param_2,&local_41c,6);
  if (iVar1 == 0) {
    if (local_41c == 0) {
      return 3;
    }
    iVar1 = FUN_001b7b50(param_1,param_2,param_3,&local_41c);
    if (iVar1 == 0) {
      local_40c = 1 << ((byte)local_41c & 0x1f);
      iVar1 = FUN_001b3530(*(undefined8 *)(param_1 + 0x10),param_2,&local_418);
      if (iVar1 == 0) {
        lVar2 = (ulong)local_41c * 0x3c;
        if (((acStack_3f4[(ulong)local_41c * 0x3c] == '\0') && (acStack_3e4[lVar2] == '\0')) &&
           (acStack_3d0[lVar2] == '\0')) {
          *param_4 = 0;
          return 0;
        }
        *param_4 = 1;
        return 0;
      }
      if (DAT_01216a78 < 2) {
        return iVar1;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0x9ef;
      uVar4 = 0x9ef;
    }
    else {
      if (DAT_01216a78 < 2) {
        return iVar1;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0x9eb;
      uVar4 = 0x9eb;
    }
    FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
                 "dmal/common/common_thermal.c",uVar4,"cDeviceGetFanControlPolicy_v2",uVar6,iVar1);
    return iVar1;
  }
  return iVar1;
}


// ===== 001b8520 FUN_001b8520 =====

int FUN_001b8520(long param_1,undefined8 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  float fVar5;
  double dVar6;
  undefined8 uVar7;
  uint local_41c;
  undefined8 local_418;
  int local_40c;
  undefined1 local_408;
  undefined1 auStack_3f4 [964];
  
  puVar3 = &local_418;
  for (lVar2 = 0x7a; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)puVar3 = 0;
  iVar1 = FUN_001b6220(param_2,&local_41c,6);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (local_41c == 0) {
    return 3;
  }
  iVar1 = FUN_001b7b50(param_1,param_2,param_3,&local_41c);
  if (iVar1 != 0) {
    if (DAT_01216a78 < 2) {
      return iVar1;
    }
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    uVar7 = 0x815;
    uVar4 = 0x815;
    dVar6 = (double)(fVar5 * DAT_00298548);
    goto LAB_001b8686;
  }
  local_40c = 1 << ((byte)local_41c & 0x1f);
  if (param_4 == 0) {
    local_408 = 1;
    iVar1 = FUN_001b3530(*(undefined8 *)(param_1 + 0x10),param_2,&local_418);
    if (iVar1 != 0) {
LAB_001b8750:
      if (DAT_01216a78 < 2) {
        return iVar1;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      uVar7 = 0x81e;
      uVar4 = 0x81e;
      dVar6 = (double)(fVar5 * DAT_00298548);
      goto LAB_001b8686;
    }
  }
  else {
    iVar1 = FUN_001b3530(*(undefined8 *)(param_1 + 0x10),param_2,&local_418);
    if (iVar1 != 0) goto LAB_001b8750;
    if (param_4 == 1) {
      auStack_3f4[(ulong)local_41c * 0x3c] = 1;
    }
  }
  iVar1 = FUN_001b36b0(*(undefined8 *)(param_1 + 0x10),param_2,&local_418);
  if (iVar1 == 0) {
    return 0;
  }
  if (DAT_01216a78 < 2) {
    return iVar1;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar2 = syscall(0xba);
  uVar7 = 0x827;
  uVar4 = 0x827;
  dVar6 = (double)(fVar5 * DAT_00298548);
LAB_001b8686:
  FUN_002340f0(dVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
               "dmal/common/common_thermal.c",uVar4,"cDeviceSetDefaultFanSpeed_v2",uVar7,iVar1);
  return iVar1;
}


// ===== 001b87b0 FUN_001b87b0 =====

int FUN_001b87b0(long param_1,long param_2,undefined4 param_3,int *param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  float fVar6;
  double dVar7;
  undefined8 uVar8;
  uint local_424;
  int local_420;
  int local_41c;
  undefined8 local_418;
  undefined1 local_40c [28];
  int aiStack_3f0 [240];
  
  puVar4 = &local_418;
  for (lVar3 = 0x7a; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined4 *)puVar4 = 0;
  iVar2 = FUN_001b6220(param_2,&local_41c,6);
  if (iVar2 != 0) {
    return iVar2;
  }
  if (local_41c == 0) {
    return 3;
  }
  iVar2 = FUN_001b7b50(param_1,param_2,param_3,&local_424);
  if (iVar2 == 0) {
    iVar2 = FUN_001b65d0(param_1,param_2,local_40c);
    if (iVar2 == 0) {
      iVar2 = FUN_001b3530(*(undefined8 *)(param_1 + 0x10),param_2,&local_418);
      if (iVar2 == 0) {
        iVar2 = ((uint)(aiStack_3f0[(ulong)local_424 * 0xf] * 100) >> 0xf & 1) +
                ((uint)(aiStack_3f0[(ulong)local_424 * 0xf] * 100) >> 0x10);
        *param_4 = iVar2;
        if (iVar2 != 0) {
          return 0;
        }
        lVar3 = *(long *)(param_2 + 0x256d8);
        if (((lVar3 == 0) || (*(long *)(lVar3 + 0x118) == 0)) ||
           (pcVar1 = *(code **)(*(long *)(lVar3 + 0x118) + 0x70), pcVar1 == (code *)0x0)) {
          iVar2 = 3;
        }
        else {
          iVar2 = (*pcVar1)(lVar3,param_2,&local_420,&local_41c);
          if (iVar2 == 0) {
            *param_4 = local_420;
            return 0;
          }
        }
        if (DAT_01216a78 < 2) {
          return iVar2;
        }
        fVar6 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        uVar5 = 0x7c0;
        uVar8 = 0x7c0;
        dVar7 = (double)(fVar6 * DAT_00298548);
      }
      else {
        if (DAT_01216a78 < 2) {
          return iVar2;
        }
        fVar6 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        uVar5 = 0x7b2;
        uVar8 = 0x7b2;
        dVar7 = (double)(fVar6 * DAT_00298548);
      }
    }
    else {
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      uVar5 = 0x7af;
      uVar8 = 0x7af;
      dVar7 = (double)(fVar6 * DAT_00298548);
    }
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    uVar5 = 0x7ac;
    uVar8 = 0x7ac;
    dVar7 = (double)(fVar6 * DAT_00298548);
  }
  FUN_002340f0(dVar7,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
               "dmal/common/common_thermal.c",uVar5,"cDeviceGetTargetFanSpeed",uVar8,iVar2);
  return iVar2;
}


// ===== 001b8b40 FUN_001b8b40 =====

int FUN_001b8b40(long param_1,undefined8 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  float fVar5;
  double dVar6;
  undefined8 uVar7;
  uint local_41c;
  undefined8 local_418;
  undefined1 local_40c [24];
  undefined1 auStack_3f4 [4];
  int aiStack_3f0 [240];
  
  puVar3 = &local_418;
  for (lVar2 = 0x7a; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)puVar3 = 0;
  iVar1 = 2;
  if (param_4 < 0x65) {
    iVar1 = FUN_001b6220(param_2,&local_41c,6);
    if ((iVar1 == 0) && (iVar1 = 3, local_41c != 0)) {
      iVar1 = FUN_001b7b50(param_1,param_2,param_3,&local_41c);
      if (iVar1 == 0) {
        iVar1 = FUN_001b65d0(param_1,param_2,local_40c);
        if (iVar1 == 0) {
          iVar1 = FUN_001b3530(*(undefined8 *)(param_1 + 0x10),param_2,&local_418);
          if (iVar1 == 0) {
            uVar4 = *(undefined8 *)(param_1 + 0x10);
            auStack_3f4[(ulong)local_41c * 0x3c] = 1;
            aiStack_3f0[(ulong)local_41c * 0xf] =
                 (param_4 * 0x10000) / 100 + (uint)(0x32 < (param_4 * 0x10000) % 100);
            iVar1 = FUN_001b36b0(uVar4,param_2,&local_418);
            if (iVar1 == 0) {
              return 0;
            }
            if (DAT_01216a78 < 2) {
              return iVar1;
            }
            fVar5 = (float)FUN_002917b0(&DAT_01216a60);
            lVar2 = syscall(0xba);
            uVar7 = 0x798;
            uVar4 = 0x798;
            dVar6 = (double)(fVar5 * DAT_00298548);
          }
          else {
            if (DAT_01216a78 < 2) {
              return iVar1;
            }
            fVar5 = (float)FUN_002917b0(&DAT_01216a60);
            lVar2 = syscall(0xba);
            uVar7 = 0x791;
            uVar4 = 0x791;
            dVar6 = (double)(fVar5 * DAT_00298548);
          }
        }
        else {
          if (DAT_01216a78 < 2) {
            return iVar1;
          }
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          uVar7 = 0x78e;
          uVar4 = 0x78e;
          dVar6 = (double)(fVar5 * DAT_00298548);
        }
      }
      else {
        if (DAT_01216a78 < 2) {
          return iVar1;
        }
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar2 = syscall(0xba);
        uVar7 = 0x78b;
        uVar4 = 0x78b;
        dVar6 = (double)(fVar5 * DAT_00298548);
      }
      FUN_002340f0(dVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
                   "dmal/common/common_thermal.c",uVar4,"cDeviceSetFanSpeed_v2",uVar7,iVar1);
    }
  }
  return iVar1;
}


// ===== 001b8e40 FUN_001b8e40 =====

int FUN_001b8e40(undefined8 param_1,char *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  int local_3c [3];
  
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
    if (param_3 != (int *)0x0) {
      if (*param_3 != 0x100000c) {
        return 0x19;
      }
      iVar1 = param_3[1];
      iVar2 = FUN_001b6220(param_2,local_3c,6);
      if (((iVar2 == 0) && (iVar2 = 3, local_3c[0] != 0)) &&
         (iVar2 = FUN_001b7ce0(param_1,param_2,iVar1,0,param_3 + 2,0,0), iVar2 == 0)) {
        return 0;
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar3,"dmal/common/common_thermal.c",0x6af,"cDeviceGetFanSpeedRPM",0x6af,
                   iVar2);
      return iVar2;
    }
  }
  return 2;
}


// ===== 001b8fa0 FUN_001b8fa0 =====

int FUN_001b8fa0(long param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  byte bVar5;
  float fVar6;
  double dVar7;
  undefined8 uVar8;
  int local_410;
  int local_40c;
  undefined1 local_408 [16];
  undefined1 local_3f8 [16];
  undefined1 local_3e8 [16];
  
  bVar5 = 0;
  iVar1 = FUN_001b6220(param_2,&local_410,6);
  if (iVar1 == 0) {
    if (local_410 == 0) {
      local_408 = (undefined1  [16])0x0;
      local_3f8 = (undefined1  [16])0x0;
      local_3e8 = (undefined1  [16])0x0;
      iVar1 = FUN_001b77a0(param_1,param_2,&local_40c);
      if (iVar1 == 0) {
        iVar1 = 3;
        if (local_40c == 1) {
          local_408._8_8_ = 0x3080;
          local_3f8._0_4_ = 0xffffffff;
          iVar1 = FUN_001b39b0(*(undefined8 *)(param_1 + 0x10),param_2,local_408,1);
          if ((iVar1 != 0) && (1 < DAT_01216a78)) {
            fVar6 = (float)FUN_002917b0(&DAT_01216a60);
            lVar2 = syscall(0xba);
            uVar8 = 0x801;
            uVar4 = 0x801;
            dVar7 = (double)(fVar6 * DAT_00298548);
            goto LAB_001b90e2;
          }
        }
      }
      else if (1 < DAT_01216a78) {
        fVar6 = (float)FUN_002917b0(&DAT_01216a60);
        lVar2 = syscall(0xba);
        uVar8 = 0x7f2;
        uVar4 = 0x7f2;
        dVar7 = (double)(fVar6 * DAT_00298548);
        goto LAB_001b90e2;
      }
    }
    else {
      puVar3 = (undefined8 *)local_408;
      for (lVar2 = 0x7a; lVar2 != 0; lVar2 = lVar2 + -1) {
        *puVar3 = 0;
        puVar3 = puVar3 + (ulong)bVar5 * -2 + 1;
      }
      *(undefined4 *)puVar3 = 0;
      iVar1 = FUN_001b65d0(param_1,param_2,local_408 + 0xc);
      if (iVar1 == 0) {
        local_3f8[0] = 1;
        iVar1 = FUN_001b3530(*(undefined8 *)(param_1 + 0x10),param_2,local_408);
        if (iVar1 == 0) {
          iVar1 = FUN_001b36b0(*(undefined8 *)(param_1 + 0x10),param_2,local_408);
          if ((iVar1 != 0) && (1 < DAT_01216a78)) {
            fVar6 = (float)FUN_002917b0(&DAT_01216a60);
            lVar2 = syscall(0xba);
            uVar8 = 0x7e9;
            uVar4 = 0x7e9;
            dVar7 = (double)(fVar6 * DAT_00298548);
            goto LAB_001b90e2;
          }
        }
        else if (1 < DAT_01216a78) {
          fVar6 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          uVar8 = 0x7e6;
          uVar4 = 0x7e6;
          dVar7 = (double)(fVar6 * DAT_00298548);
LAB_001b90e2:
          FUN_002340f0(dVar7,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
                       "dmal/common/common_thermal.c",uVar4,"cDeviceSetDefaultFanSpeed",uVar8,iVar1)
          ;
          return iVar1;
        }
      }
      else if (1 < DAT_01216a78) {
        fVar6 = (float)FUN_002917b0(&DAT_01216a60);
        lVar2 = syscall(0xba);
        uVar8 = 0x7e1;
        uVar4 = 0x7e1;
        dVar7 = (double)(fVar6 * DAT_00298548);
        goto LAB_001b90e2;
      }
    }
  }
  else if (1 < DAT_01216a78) {
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    uVar8 = 0x7da;
    uVar4 = 0x7da;
    dVar7 = (double)(fVar6 * DAT_00298548);
    goto LAB_001b90e2;
  }
  return iVar1;
}


// ===== 001b9380 FUN_001b9380 =====

int FUN_001b9380(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  ulong uVar6;
  uint uVar7;
  byte bVar8;
  float fVar9;
  double dVar10;
  undefined8 uVar11;
  int local_420;
  uint local_41c;
  undefined8 local_418;
  undefined8 local_410;
  uint local_408;
  undefined1 auStack_3f4 [4];
  int aiStack_3f0 [4];
  undefined8 local_3e0;
  int local_3d8;
  
  bVar8 = 0;
  iVar1 = FUN_001b6220(param_2,&local_420,6);
  if (iVar1 == 0) {
    if (local_420 == 0) {
      puVar4 = &local_418;
      for (lVar2 = 0xc; lVar2 != 0; lVar2 = lVar2 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + (ulong)bVar8 * -2 + 1;
      }
      iVar1 = FUN_001b77a0(param_1,param_2,&local_41c);
      if (iVar1 == 0) {
        if (local_41c != 1) {
          return 3;
        }
        local_410 = 0x3010;
        local_408 = 1;
        local_3e0 = 0x3020;
        local_3d8 = param_3;
        iVar1 = FUN_001b39b0(*(undefined8 *)(param_1 + 0x10),param_2,&local_418,2);
        if (iVar1 == 0) {
          return 0;
        }
        if (DAT_01216a78 < 2) {
          return iVar1;
        }
        fVar9 = (float)FUN_002917b0(&DAT_01216a60);
        lVar2 = syscall(0xba);
        uVar11 = 0x773;
        uVar5 = 0x773;
        dVar10 = (double)(fVar9 * DAT_00298548);
      }
      else {
        if (DAT_01216a78 < 2) {
          return iVar1;
        }
        fVar9 = (float)FUN_002917b0(&DAT_01216a60);
        lVar2 = syscall(0xba);
        uVar11 = 0x760;
        uVar5 = 0x760;
        dVar10 = (double)(fVar9 * DAT_00298548);
      }
    }
    else {
      puVar4 = &local_418;
      for (lVar2 = 0x7a; lVar2 != 0; lVar2 = lVar2 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + (ulong)bVar8 * -2 + 1;
      }
      local_41c = 0;
      *(undefined4 *)puVar4 = 0;
      iVar1 = FUN_001b65d0(param_1,param_2,&local_41c);
      if (iVar1 == 0) {
        local_410 = CONCAT44(local_41c,(undefined4)local_410);
        iVar1 = FUN_001b3530(*(undefined8 *)(param_1 + 0x10),param_2,&local_418);
        if (iVar1 == 0) {
          local_408 = local_408 & 0xffffff00;
          if (local_41c != 0) {
            uVar7 = param_3 * 0x10000;
            uVar6 = 0;
            uVar3 = local_41c;
            do {
              if ((uVar3 & 1) != 0) {
                auStack_3f4[uVar6 * 0x3c] = 1;
                aiStack_3f0[uVar6 * 0xf] =
                     CONCAT31((uint3)(uVar7 / 100 >> 8) ^ (uint3)(uVar7 / 100 >> 8),
                              0x32 < uVar7 % 100) + uVar7 / 100;
              }
              uVar6 = (ulong)((int)uVar6 + 1);
              uVar3 = uVar3 >> 1;
            } while (uVar3 != 0);
          }
          iVar1 = FUN_001b36b0(*(undefined8 *)(param_1 + 0x10),param_2,&local_418);
          if (iVar1 == 0) {
            return 0;
          }
          if (DAT_01216a78 < 2) {
            return iVar1;
          }
          fVar9 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          uVar11 = 0x758;
          uVar5 = 0x758;
          dVar10 = (double)(fVar9 * DAT_00298548);
        }
        else {
          if (DAT_01216a78 < 2) {
            return iVar1;
          }
          fVar9 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          uVar11 = 0x74b;
          uVar5 = 0x74b;
          dVar10 = (double)(fVar9 * DAT_00298548);
        }
      }
      else {
        if (DAT_01216a78 < 2) {
          return iVar1;
        }
        fVar9 = (float)FUN_002917b0(&DAT_01216a60);
        lVar2 = syscall(0xba);
        uVar11 = 0x746;
        uVar5 = 0x746;
        dVar10 = (double)(fVar9 * DAT_00298548);
      }
    }
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar1;
    }
    fVar9 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    uVar11 = 0x73d;
    uVar5 = 0x73d;
    dVar10 = (double)(fVar9 * DAT_00298548);
  }
  FUN_002340f0(dVar10,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
               "dmal/common/common_thermal.c",uVar5,"cDeviceSetFanSpeed",uVar11,iVar1);
  return iVar1;
}


// ===== 001b97d0 FUN_001b97d0 =====

undefined8 FUN_001b97d0(undefined8 param_1,undefined8 param_2,uint param_3)

{
  undefined8 uVar1;
  
  if (100 < param_3) {
    return 2;
  }
  uVar1 = FUN_001b9380();
  return uVar1;
}


// ===== 001b9800 FUN_001b9800 =====

int FUN_001b9800(long param_1,undefined8 param_2,int *param_3)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  uint uVar4;
  undefined8 uVar5;
  float fVar6;
  double dVar7;
  undefined8 uVar8;
  int local_380;
  uint local_37c;
  undefined1 local_378 [16];
  undefined1 local_368 [16];
  undefined1 local_358 [51] [16];
  
  iVar1 = FUN_001b6220(param_2,&local_380,6);
  if (iVar1 == 0) {
    if (local_380 == 0) {
      local_378 = (undefined1  [16])0x0;
      local_368 = (undefined1  [16])0x0;
      local_358[0] = (undefined1  [16])0x0;
      iVar1 = FUN_001b77a0(param_1,param_2,&local_37c);
      if (iVar1 == 0) {
        iVar1 = 3;
        if (local_37c == 1) {
          local_378._8_8_ = 0x2020;
          iVar1 = FUN_001b39b0(*(undefined8 *)(param_1 + 0x10),param_2,local_378,1);
          if (iVar1 == 0) {
            *param_3 = local_368._0_4_;
          }
          else if (1 < DAT_01216a78) {
            fVar6 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            uVar8 = 0x666;
            uVar5 = 0x666;
            dVar7 = (double)(fVar6 * DAT_00298548);
            goto LAB_001b992e;
          }
        }
      }
      else if (1 < DAT_01216a78) {
        fVar6 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        uVar8 = 0x659;
        uVar5 = 0x659;
        dVar7 = (double)(fVar6 * DAT_00298548);
        goto LAB_001b992e;
      }
    }
    else {
      local_37c = 0;
      iVar1 = FUN_001b65d0(param_1,param_2,&local_37c);
      if (iVar1 == 0) {
        local_378._4_4_ = local_37c;
        iVar1 = FUN_001b33b0(*(undefined8 *)(param_1 + 0x10),param_2,local_378);
        if (iVar1 == 0) {
          if (local_37c != 0) {
            uVar2 = 0;
            if ((local_37c & 1) == 0) {
              do {
                uVar2 = (ulong)((int)uVar2 + 1);
                local_37c = local_37c >> 1;
                if (local_37c == 0) {
                  return 0;
                }
              } while ((local_37c & 1) == 0);
            }
            else {
              uVar2 = 0;
            }
            uVar4 = *(int *)((long)local_358 + uVar2 * 0x34) * 100;
            *param_3 = (uVar4 >> 0xf & 1) + (uVar4 >> 0x10);
          }
        }
        else if (1 < DAT_01216a78) {
          fVar6 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          uVar8 = 0x649;
          uVar5 = 0x649;
          dVar7 = (double)(fVar6 * DAT_00298548);
          goto LAB_001b992e;
        }
      }
      else if (1 < DAT_01216a78) {
        fVar6 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        uVar8 = 0x644;
        uVar5 = 0x644;
        dVar7 = (double)(fVar6 * DAT_00298548);
LAB_001b992e:
        FUN_002340f0(dVar7,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
                     "dmal/common/common_thermal.c",uVar5,"cDeviceGetFanSpeed",uVar8,iVar1);
        return iVar1;
      }
    }
  }
  else if (1 < DAT_01216a78) {
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    uVar8 = 0x63b;
    uVar5 = 0x63b;
    dVar7 = (double)(fVar6 * DAT_00298548);
    goto LAB_001b992e;
  }
  return iVar1;
}


// ===== 001b9bb0 FUN_001b9bb0 =====

undefined8 FUN_001b9bb0(long param_1,long param_2,long param_3,int param_4,int param_5)

{
  code *pcVar1;
  void **ppvVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  long lVar8;
  int *piVar9;
  void *pvVar10;
  uint *puVar11;
  undefined8 extraout_RDX;
  undefined1 *puVar12;
  void **ppvVar13;
  char *pcVar14;
  uint *puVar15;
  ulong uVar16;
  bool bVar17;
  undefined4 uVar18;
  float fVar19;
  float fVar20;
  double dVar21;
  void *local_68;
  void *local_60;
  float local_54;
  long local_50;
  float local_48;
  undefined1 local_44 [4];
  int local_40;
  undefined4 local_3c [3];
  
  ppvVar13 = &local_68;
  lVar8 = *(long *)(param_2 + 0x256d8);
  local_50 = param_1;
  if (((lVar8 == 0) || (*(undefined8 **)(lVar8 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar8 + 0x50), pcVar1 == (code *)0x0)) {
    iVar4 = 3;
  }
  else {
    iVar4 = (*pcVar1)(lVar8,param_2,0x2080,&local_48);
    if (iVar4 == 0) {
      cVar3 = FUN_001b4740(local_50,param_2,local_48);
      if (cVar3 == '\0') {
        uVar7 = FUN_00234e30();
        if (param_5 < param_4) {
          return 0;
        }
        piVar9 = (int *)(param_3 + (long)param_4 * 0x28);
        do {
          if (*piVar9 - 0xc1U < 4) {
            *(undefined8 *)(piVar9 + 2) = uVar7;
            piVar9[4] = 0;
            piVar9[5] = 0;
            piVar9[6] = 5;
            piVar9[8] = 0;
            piVar9[7] = 3;
          }
          piVar9 = piVar9 + 10;
        } while ((int *)(param_3 + 0x28 + ((long)param_4 + (ulong)(uint)(param_5 - param_4)) * 0x28)
                 != piVar9);
        return 0;
      }
      if (param_5 < param_4) {
        return 0;
      }
      puVar15 = (uint *)(param_3 + (long)param_4 * 0x28);
      uVar5 = *puVar15;
      ppvVar2 = &local_68;
      if (uVar5 == 0xc3) goto LAB_001b9e1a;
      bVar17 = false;
LAB_001b9cd0:
      if (0xc2 < uVar5 && !bVar17) {
        if (uVar5 != 0xc4) goto LAB_001b9dfb;
        puVar15[8] = 0;
        uVar16 = 0;
        goto LAB_001b9de3;
      }
      if (1 < uVar5 - 0xc1) goto LAB_001b9dfb;
      local_3c[0] = 0;
      local_54 = local_48;
      if (*(int *)(param_2 + 0x71c) == 0) {
        do {
          *(undefined8 *)((long)ppvVar13 + -8) = 0x1b9d17;
          iVar4 = FUN_00291820(param_2 + 0x720,1,0);
        } while (iVar4 != 0);
        if (*(int *)(param_2 + 0x71c) == 0) {
          lVar8 = *(long *)(param_2 + 0x256d8);
          uVar18 = 3;
          if (((lVar8 != 0) && (*(long *)(lVar8 + 0x20) != 0)) &&
             (pcVar1 = *(code **)(*(long *)(lVar8 + 0x20) + 0x98), pcVar1 != (code *)0x0)) {
            *(undefined8 *)((long)ppvVar13 + -8) = 0x1b9f22;
            uVar18 = (*pcVar1)(lVar8,param_2,param_2 + 0x708);
          }
          *(undefined4 *)(param_2 + 0x724) = uVar18;
          *(undefined4 *)(param_2 + 0x71c) = 1;
        }
        *(undefined8 *)((long)ppvVar13 + -8) = 0x1b9d3b;
        FUN_00291830(param_2 + 0x720,0);
      }
      lVar8 = local_50;
      fVar20 = local_54;
      uVar16 = (ulong)*(uint *)(param_2 + 0x724);
      if (*(uint *)(param_2 + 0x724) != 0) {
        if (DAT_01216a78 < 2) goto LAB_001b9de3;
        *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba01c;
        local_54 = (float)FUN_002917b0(&DAT_01216a60);
        *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba02d;
        lVar8 = syscall(0xba);
        fVar20 = local_54;
        *(ulong *)((long)ppvVar13 + -8) = uVar16;
        pcVar14 = "cDeviceGetHwThermalTlimitThreshold";
        puVar12 = (undefined1 *)((long)ppvVar13 + -0x10);
        *(undefined8 *)((long)ppvVar13 + -0x10) = 0x39e;
        uVar7 = 0x39e;
        dVar21 = (double)(fVar20 * DAT_00298548);
        goto LAB_001b9eb3;
      }
      if (0xc < *(uint *)(param_2 + 0x708)) {
        *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba06f;
        uVar5 = FUN_001b2ce0(lVar8,fVar20,puVar15);
        uVar16 = (ulong)uVar5;
        goto LAB_001b9de3;
      }
      *(undefined8 *)((long)ppvVar13 + -8) = 0x1b9d6a;
      uVar5 = FUN_001b6220(param_2,local_3c,7);
      uVar16 = (ulong)uVar5;
      if (uVar5 != 0) {
        if (DAT_01216a78 < 2) goto LAB_001b9de3;
        *(undefined8 *)((long)ppvVar13 + -8) = 0x1b9d8d;
        local_54 = (float)FUN_002917b0(&DAT_01216a60);
        *(undefined8 *)((long)ppvVar13 + -8) = 0x1b9d9e;
        lVar8 = syscall(0xba);
        fVar20 = local_54;
        *(ulong *)((long)ppvVar13 + -8) = uVar16;
        pcVar14 = "cDeviceGetHwThermalTlimitThreshold";
        puVar12 = (undefined1 *)((long)ppvVar13 + -0x10);
        *(undefined8 *)((long)ppvVar13 + -0x10) = 0x3ae;
        uVar7 = 0x3ae;
        dVar21 = (double)(fVar20 * DAT_00298548);
        goto LAB_001b9eb3;
      }
      if (*(int *)(param_2 + 0x255e8) == 0) {
        do {
          *(undefined8 *)((long)ppvVar13 + -8) = 0x1b9f67;
          iVar4 = FUN_00291820(param_2 + 0x255ec,1,0);
        } while (iVar4 != 0);
        if (*(int *)(param_2 + 0x255e8) == 0) {
          *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba18d;
          pvVar10 = calloc(0x3bf8,1);
          fVar20 = local_54;
          if (pvVar10 == (void *)0x0) {
            local_54 = 2.8026e-44;
            if (1 < DAT_01216a78) {
              *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba4bb;
              uVar18 = FUN_002917b0(&DAT_01216a60);
              local_60 = (void *)CONCAT44(local_60._4_4_,uVar18);
              *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba4cc;
              lVar8 = syscall(0xba);
              fVar20 = local_60._0_4_ * DAT_00298548;
              *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba505;
              FUN_002340f0((double)fVar20,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar8,
                           "dmal/common/common_thermal.c",0x2f0);
            }
          }
          else {
            uVar7 = *(undefined8 *)(local_50 + 0x10);
            local_60 = pvVar10;
            *(undefined8 *)((long)ppvVar13 + -0x10) = 0;
            *(undefined8 *)((long)ppvVar13 + -0x18) = 0x1ba1ce;
            iVar4 = FUN_0019c780(uVar7,DAT_0038088c,fVar20,0x2080853a,pvVar10,0x3bf8);
            lVar8 = local_50;
            fVar20 = local_54;
            if (iVar4 == 0) {
              puVar11 = (uint *)((long)local_60 + 4);
              iVar4 = 0;
              do {
                uVar5 = *puVar11;
                puVar11 = puVar11 + 1;
                uVar5 = uVar5 - (uVar5 >> 1 & 0x55555555);
                uVar5 = (uVar5 >> 2 & 0x33333333) + (uVar5 & 0x33333333);
                iVar4 = iVar4 + (((uVar5 >> 4) + uVar5 & 0xf0f0f0f) * 0x1010101 >> 0x18);
              } while (puVar11 != (uint *)((long)local_60 + 0x24));
              if ((short)iVar4 != 0) {
                local_68 = (void *)CONCAT71(local_68._1_7_,*(char *)((long)local_60 + 0x25));
                if (*(char *)((long)local_60 + 0x25) != -1) {
                  *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba254;
                  local_54 = (float)FUN_001b4610(lVar8,param_2,fVar20);
                  pcVar14 = (char *)(param_2 + 0x25d75);
                  uVar16 = 0;
                  pvVar10 = local_60;
                  if (local_54 != 0.0) {
                    if (1 < DAT_01216a78) {
                      local_68 = local_60;
                      *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba441;
                      uVar18 = FUN_002917b0(&DAT_01216a60);
                      local_60 = (void *)CONCAT44(local_60._4_4_,uVar18);
                      *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba452;
                      lVar8 = syscall(0xba);
                      fVar20 = local_54;
                      fVar19 = local_60._0_4_ * DAT_00298548;
                      *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba48f;
                      FUN_002340f0((double)fVar19,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n","ERROR",
                                   lVar8,"dmal/common/common_thermal.c",0x310,fVar20);
                      pvVar10 = local_68;
                    }
                    goto LAB_001ba28d;
                  }
                  do {
                    if ((char)local_68 == *pcVar14) {
                      uVar5 = *(uint *)(param_2 + uVar16 * 0x6c + 0x25d80);
                      uVar6 = uVar5 >> 8;
                      if ((int)uVar5 < 0) {
                        uVar6 = uVar6 | 0xff000000;
                      }
                      *(uint *)(param_2 + 0x255e4) = uVar6;
                      goto LAB_001ba28d;
                    }
                    uVar5 = (int)uVar16 + 1;
                    uVar16 = (ulong)uVar5;
                    pcVar14 = pcVar14 + 0x6c;
                  } while (uVar5 != 0x10);
                }
              }
              local_54 = 4.2039e-45;
              pvVar10 = local_60;
            }
            else {
              *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba3e7;
              local_54 = (float)FUN_0019c760(iVar4);
              pvVar10 = local_60;
            }
LAB_001ba28d:
            *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba295;
            free(pvVar10);
          }
          *(undefined4 *)(param_2 + 0x255e8) = 1;
          *(float *)(param_2 + 0x255f0) = local_54;
        }
        *(undefined8 *)((long)ppvVar13 + -8) = 0x1b9f8b;
        FUN_00291830(param_2 + 0x255ec,0);
      }
      uVar18 = local_3c[0];
      lVar8 = local_50;
      uVar16 = (ulong)*(uint *)(param_2 + 0x255f0);
      if (*(uint *)(param_2 + 0x255f0) == 0) {
        if (*puVar15 == 0xc1) {
          uVar7 = *(undefined8 *)(local_50 + 0x10);
          local_54 = *(float *)(param_2 + 0x255e4);
          *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba10a;
          uVar5 = FUN_001b4390(uVar7,param_2,&local_40,local_44,uVar18,1);
          if (uVar5 == 0) goto LAB_001b9fe6;
          uVar16 = (ulong)uVar5;
          if (DAT_01216a78 < 2) goto LAB_001b9de3;
          *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba135;
          local_54 = (float)FUN_002917b0(&DAT_01216a60);
          *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba146;
          lVar8 = syscall(0xba);
          fVar20 = local_54;
          *(ulong *)((long)ppvVar13 + -8) = uVar16;
          pcVar14 = "cDeviceGetHwThermalTlimitThreshold";
          puVar12 = (undefined1 *)((long)ppvVar13 + -0x10);
          *(undefined8 *)((long)ppvVar13 + -0x10) = 0x3b9;
          uVar7 = 0x3b9;
          dVar21 = (double)(fVar20 * DAT_00298548);
        }
        else {
          if (*puVar15 != 0xc2) goto LAB_001b9de3;
          local_54 = *(float *)(param_2 + 0x255e4);
          *(undefined8 *)((long)ppvVar13 + -8) = 0x1b9fda;
          uVar5 = FUN_001b60c0(lVar8,param_2,&local_40,local_44,1);
          if (uVar5 == 0) {
LAB_001b9fe6:
            puVar15[8] = (int)local_54 - local_40;
            goto LAB_001b9de3;
          }
          uVar16 = (ulong)uVar5;
          if (DAT_01216a78 < 2) goto LAB_001b9de3;
          *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba3a4;
          local_54 = (float)FUN_002917b0(&DAT_01216a60);
          *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba3b5;
          lVar8 = syscall(0xba);
          fVar20 = local_54;
          *(ulong *)((long)ppvVar13 + -8) = uVar16;
          pcVar14 = "cDeviceGetHwThermalTlimitThreshold";
          puVar12 = (undefined1 *)((long)ppvVar13 + -0x10);
          *(undefined8 *)((long)ppvVar13 + -0x10) = 0x3c0;
          uVar7 = 0x3c0;
          dVar21 = (double)(fVar20 * DAT_00298548);
        }
      }
      else {
        if (DAT_01216a78 < 2) goto LAB_001b9de3;
        *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba2ce;
        local_54 = (float)FUN_002917b0(&DAT_01216a60);
        *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba2df;
        lVar8 = syscall(0xba);
        fVar20 = local_54;
        *(ulong *)((long)ppvVar13 + -8) = uVar16;
        *(undefined8 *)((long)ppvVar13 + -0x10) = 0x32d;
        *(undefined8 *)((long)ppvVar13 + -0x18) = 0x1ba326;
        FUN_002340f0((double)(fVar20 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n"
                     ,"ERROR",lVar8,"dmal/common/common_thermal.c",0x32d,
                     "cDeviceGetRatedGpuMaxLimit");
        uVar7 = *(undefined8 *)((long)ppvVar13 + -8);
        if (DAT_01216a78 < 2) goto LAB_001b9de3;
        *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba347;
        local_54 = (float)FUN_002917b0(&DAT_01216a60,uVar7,extraout_RDX,
                                       *(undefined8 *)((long)ppvVar13 + -0x10));
        *(undefined8 *)((long)ppvVar13 + -8) = 0x1ba358;
        lVar8 = syscall(0xba);
        fVar20 = local_54;
        *(ulong *)((long)ppvVar13 + -8) = uVar16;
        pcVar14 = "cDeviceGetHwThermalTlimitThreshold";
        puVar12 = (undefined1 *)((long)ppvVar13 + -0x10);
        *(undefined8 *)((long)ppvVar13 + -0x10) = 0x3b1;
        uVar7 = 0x3b1;
        dVar21 = (double)(fVar20 * DAT_00298548);
      }
LAB_001b9eb3:
      do {
        *(undefined8 *)(puVar12 + -8) = 0x1b9ed2;
        FUN_002340f0(dVar21,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar8,
                     "dmal/common/common_thermal.c",uVar7,pcVar14);
        ppvVar13 = (void **)(puVar12 + 0x10);
LAB_001b9de3:
        do {
          puVar15[7] = (uint)uVar16;
          puVar15[6] = 5;
          *(undefined8 *)((long)ppvVar13 + -8) = 0x1b9df6;
          uVar7 = FUN_00234e30();
          *(undefined8 *)(puVar15 + 2) = uVar7;
LAB_001b9dfb:
          param_4 = param_4 + 1;
          puVar15 = puVar15 + 10;
          if (param_5 < param_4) {
            return 0;
          }
          uVar5 = *puVar15;
          bVar17 = uVar5 == 0xc3;
          ppvVar2 = ppvVar13;
          if (!bVar17) goto LAB_001b9cd0;
LAB_001b9e1a:
          ppvVar13 = ppvVar2;
          lVar8 = *(long *)(param_2 + 0x256d8);
          if (((lVar8 == 0) || (*(long *)(lVar8 + 0x148) == 0)) ||
             (pcVar1 = *(code **)(*(long *)(lVar8 + 0x148) + 0x20), pcVar1 == (code *)0x0)) {
            uVar16 = 3;
          }
          else {
            *(undefined8 *)((long)ppvVar13 + -8) = 0x1b9e40;
            uVar5 = (*pcVar1)(lVar8,param_2);
            uVar16 = (ulong)uVar5;
            if (uVar5 == 0) {
              puVar15[8] = 0;
              goto LAB_001b9de3;
            }
          }
        } while (DAT_01216a78 < 2);
        *(undefined8 *)((long)ppvVar13 + -8) = 0x1b9e7a;
        local_54 = (float)FUN_002917b0(&DAT_01216a60);
        *(undefined8 *)((long)ppvVar13 + -8) = 0x1b9e8b;
        lVar8 = syscall(0xba);
        fVar20 = local_54;
        *(ulong *)((long)ppvVar13 + -8) = uVar16;
        pcVar14 = "cDeviceGetMemoryMaxTlimitThreshold";
        puVar12 = (undefined1 *)((long)ppvVar13 + -0x10);
        *(undefined8 *)((long)ppvVar13 + -0x10) = 0x3d6;
        uVar7 = 0x3d6;
        dVar21 = (double)(fVar20 * DAT_00298548);
      } while( true );
    }
  }
  uVar7 = FUN_00234e30();
  if (param_4 <= param_5) {
    piVar9 = (int *)(param_3 + (long)param_4 * 0x28);
    do {
      if (*piVar9 - 0xc1U < 4) {
        *(undefined8 *)(piVar9 + 2) = uVar7;
        piVar9[4] = 0;
        piVar9[5] = 0;
        piVar9[6] = 5;
        piVar9[8] = 0;
        piVar9[7] = iVar4;
      }
      piVar9 = piVar9 + 10;
    } while ((int *)(param_3 + 0x28 + ((ulong)(uint)(param_5 - param_4) + (long)param_4) * 0x28) !=
             piVar9);
  }
  return 0;
}


// ===== 001ba510 FUN_001ba510 =====

int FUN_001ba510(long param_1,long param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  uint uVar6;
  ulong uVar7;
  byte bVar8;
  float fVar9;
  undefined8 uVar10;
  int local_5dc;
  undefined8 local_5d8;
  undefined4 local_5d0;
  uint auStack_5b4 [353];
  
  bVar8 = 0;
  puVar4 = &local_5d8;
  for (lVar3 = 0xb4; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  uVar5 = *(undefined8 *)(param_1 + 0x10);
  iVar2 = FUN_001b6220(param_2,&local_5dc,6);
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = 3;
  if (local_5dc == 0) {
    return 3;
  }
  lVar3 = *(long *)(param_2 + 0x256d8);
  if ((((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
      (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) ||
     (iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_5dc), iVar2 != 0)) {
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar9 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    fVar9 = fVar9 * DAT_00298548;
    uVar10 = 0x448;
    uVar5 = 0x448;
  }
  else {
    iVar2 = FUN_001b4610(param_1,param_2,local_5dc);
    if (iVar2 == 0) {
      uVar7 = (ulong)*(byte *)(param_2 + 0x25d6e);
      if (*(byte *)(param_2 + 0x25d6e) == 0xff) {
        iVar2 = 3;
        if (DAT_01216a78 < 5) {
          return 3;
        }
        fVar9 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        fVar9 = fVar9 * DAT_00298548;
        uVar5 = 0x450;
LAB_001ba8b3:
        FUN_002340f0((double)fVar9,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",lVar3,
                     "dmal/common/common_thermal.c",uVar5);
        return iVar2;
      }
      local_5d0 = *(undefined4 *)(param_2 + 0x25d68);
      iVar2 = FUN_0019c780(uVar5,DAT_0038088c,local_5dc,0x2080852c,&local_5d8,0x5a0,0);
      switch(iVar2) {
      case 0:
        uVar6 = auStack_5b4[uVar7 * 0x16] >> 8;
        if ((int)auStack_5b4[uVar7 * 0x16] < 0) {
          uVar6 = uVar6 | 0xff000000;
        }
        if (4 < DAT_01216a78) {
          fVar9 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %d\n",
                       "DEBUG",lVar3,"dmal/common/common_thermal.c",0x45e,uVar6,param_3);
        }
        auStack_5b4[uVar7 * 0x16] = param_3 << 8;
        iVar2 = FUN_0019c780(uVar5,DAT_0038088c,local_5dc,0x2080c52d,&local_5d8,0x5a0,0);
        switch(iVar2) {
        case 0:
          puVar4 = &local_5d8;
          for (lVar3 = 0xb4; lVar3 != 0; lVar3 = lVar3 + -1) {
            *puVar4 = 0;
            puVar4 = puVar4 + (ulong)bVar8 * -2 + 1;
          }
          local_5d0 = *(undefined4 *)(param_2 + 0x25d68);
          iVar2 = FUN_0019c780(uVar5,DAT_0038088c,local_5dc,0x2080852c,&local_5d8,0x5a0,0);
          switch(iVar2) {
          case 0:
            if (param_3 << 8 == auStack_5b4[uVar7 * 0x16]) {
              return iVar2;
            }
            iVar2 = 999;
            if (DAT_01216a78 < 5) {
              return 999;
            }
            fVar9 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            fVar9 = fVar9 * DAT_00298548;
            uVar5 = 0x47a;
            goto LAB_001ba8b3;
          case 3:
          case 0x66:
            goto switchD_001ba6d4_caseD_3;
          case 0xf:
            return iVar2;
          case 0x17:
          case 99:
            goto switchD_001ba6d4_caseD_17;
          case 0x1a:
            goto switchD_001ba6d4_caseD_1a;
          case 0x1b:
            goto switchD_001ba6d4_caseD_1b;
          case 0x1f:
          case 0x3b:
          case 0x54:
            goto switchD_001ba6d4_caseD_1f;
          case 0x51:
            goto switchD_001ba6d4_caseD_51;
          case 0x55:
            goto switchD_001ba6d4_caseD_55;
          case 0x56:
            goto switchD_001ba6d4_caseD_56;
          case 0x59:
            goto switchD_001ba6d4_caseD_59;
          case 0x62:
            goto switchD_001ba6d4_caseD_62;
          }
          break;
        case 3:
        case 0x66:
          goto switchD_001ba6d4_caseD_3;
        case 0xf:
          return iVar2;
        case 0x17:
        case 99:
          goto switchD_001ba6d4_caseD_17;
        case 0x1a:
          goto switchD_001ba6d4_caseD_1a;
        case 0x1b:
          goto switchD_001ba6d4_caseD_1b;
        case 0x1f:
        case 0x3b:
        case 0x54:
          goto switchD_001ba6d4_caseD_1f;
        case 0x51:
          goto switchD_001ba6d4_caseD_51;
        case 0x55:
          goto switchD_001ba6d4_caseD_55;
        case 0x56:
          goto switchD_001ba6d4_caseD_56;
        case 0x59:
          goto switchD_001ba6d4_caseD_59;
        case 0x62:
          goto switchD_001ba6d4_caseD_62;
        }
        break;
      case 3:
      case 0x66:
switchD_001ba6d4_caseD_3:
        return 10;
      case 0xf:
        return iVar2;
      case 0x17:
      case 99:
switchD_001ba6d4_caseD_17:
        return 0x13;
      case 0x1a:
switchD_001ba6d4_caseD_1a:
        return 0x17;
      case 0x1b:
switchD_001ba6d4_caseD_1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
switchD_001ba6d4_caseD_1f:
        return 2;
      case 0x51:
switchD_001ba6d4_caseD_51:
        return 0x14;
      case 0x55:
switchD_001ba6d4_caseD_55:
        return 0x1b;
      case 0x56:
switchD_001ba6d4_caseD_56:
        return 3;
      case 0x59:
switchD_001ba6d4_caseD_59:
        return 0x11;
      case 0x62:
switchD_001ba6d4_caseD_62:
        return 0x10;
      }
      return 999;
    }
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar9 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    fVar9 = fVar9 * DAT_00298548;
    uVar10 = 1099;
    uVar5 = 1099;
  }
  FUN_002340f0((double)fVar9,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
               "dmal/common/common_thermal.c",uVar5,"cDeviceSetGpuAcousticTemperatureThreshold",
               uVar10,iVar2);
  return iVar2;
}


// ===== 001baa20 FUN_001baa20 =====

undefined8 FUN_001baa20(undefined8 param_1,undefined8 param_2,int param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  
  if (param_3 == 5) {
    uVar1 = FUN_001ba510(param_1,param_2,*param_4);
    return uVar1;
  }
  return 2;
}


// ===== 001baa50 FUN_001baa50 =====

int FUN_001baa50(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                undefined8 param_5,undefined8 param_6)

{
  int iVar1;
  long lVar2;
  float fVar3;
  int local_3c [3];
  
  iVar1 = FUN_001b6220(param_2,local_3c,6);
  if ((((iVar1 != 0) || (iVar1 = 3, local_3c[0] == 0)) ||
      (iVar1 = FUN_001b7ce0(param_1,param_2,param_3,param_4,0,param_5,param_6), iVar1 != 0)) &&
     (1 < DAT_01216a78)) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar2,"dmal/common/common_thermal.c",0x675,"cDeviceGetFanSpeed_v2",0x675,
                 iVar1);
  }
  return iVar1;
}


// ===== 001bab60 FUN_001bab60 =====

int FUN_001bab60(char *param_1,uint *param_2,uint param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  float fVar5;
  
  iVar2 = 2;
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
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
    if (iVar2 == 0) {
      if (4 < DAT_01216a78) {
        uVar3 = *(undefined4 *)(param_1 + 0x708);
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tisArchOrNewer called: %d %d\n","DEBUG",
                     lVar4,"/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h",0x3d,
                     param_3,uVar3);
      }
      *param_2 = (uint)(param_3 <= *(uint *)(param_1 + 0x708));
    }
    else if (iVar2 == 0xf) {
      if (4 < DAT_01216a78) {
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tisArchOrNewer error: %d\n","DEBUG",lVar4,
                     "/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h",0x42,param_3)
        ;
      }
    }
    else {
      if (1 < DAT_01216a78) {
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tFailure to determine Architecture\n",
                     "ERROR",lVar4,"/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h"
                     ,0x46);
      }
      *param_2 = 0;
      iVar2 = 0;
    }
  }
  return iVar2;
}


// ===== 001badf0 FUN_001badf0 =====

int FUN_001badf0(long param_1,long param_2,undefined4 param_3,undefined8 param_4,undefined4 *param_5
                ,long param_6)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined8 *puVar8;
  undefined1 *puVar9;
  float fVar10;
  double dVar11;
  undefined8 uVar12;
  uint local_df30;
  undefined4 local_df0c;
  undefined1 local_df08 [8];
  uint local_df00 [286];
  undefined1 local_da88 [4];
  uint local_da84;
  uint local_da7c;
  undefined8 local_da78 [6985];
  
  memset(local_da88,0,0xda50);
  if (param_6 == 0) {
    *param_5 = 0x48;
    return 0;
  }
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)) {
    iVar3 = 3;
LAB_001baf16:
    if (DAT_01216a78 < 2) {
      return iVar3;
    }
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    uVar12 = 0x1e0;
    uVar6 = 0x1e0;
    dVar11 = (double)(fVar10 * DAT_00298548);
LAB_001baf83:
    FUN_002340f0(dVar11,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
                 "dmal/common/common_utilization.c",uVar6,"cDeviceGetUtilizationSamples",uVar12,
                 iVar3);
  }
  else {
    uVar6 = *(undefined8 *)(param_1 + 0x10);
    uVar12 = 0x1bae90;
    iVar3 = (*pcVar1)(lVar4,param_2,0x2080,&local_df0c);
    if (iVar3 != 0) goto LAB_001baf16;
    local_da88[0] = 2;
    local_da84 = 0xda40;
    local_da7c = 0;
    iVar3 = FUN_0019c780(uVar6,DAT_0038088c,local_df0c,0x20802096,local_da88,0xda50,0);
    uVar2 = local_da7c;
    uVar7 = local_da84;
    switch(iVar3) {
    case 0:
      lVar4 = *(long *)(param_2 + 0x256d8);
      if (((lVar4 == 0) || (*(long *)(lVar4 + 0x40) == 0)) ||
         (pcVar1 = *(code **)(*(long *)(lVar4 + 0x40) + 0x18), pcVar1 == (code *)0x0)) {
        iVar3 = 3;
      }
      else {
        iVar3 = (*pcVar1)(lVar4,param_2,iVar3,&switchD_001baf04::switchdataD_002b50f4,uVar12);
        if (iVar3 == 0) {
          uVar5 = (ulong)(uVar7 >> 3) / 0x61;
          if (0x307 < uVar7) {
            puVar8 = local_da78;
            puVar9 = local_df08;
            uVar7 = 0;
            do {
              lVar4 = *(long *)(param_2 + 0x256d8);
              if (((lVar4 == 0) || (*(long *)(lVar4 + 0x40) == 0)) ||
                 (pcVar1 = *(code **)(*(long *)(lVar4 + 0x40) + 0x20), pcVar1 == (code *)0x0)) {
                iVar3 = 3;
LAB_001bb2e2:
                if (DAT_01216a78 < 2) {
                  return iVar3;
                }
                fVar10 = (float)FUN_002917b0(&DAT_01216a60);
                lVar4 = syscall(0xba);
                uVar12 = 0x1f7;
                uVar6 = 0x1f7;
                dVar11 = (double)(fVar10 * DAT_00298548);
                goto LAB_001baf83;
              }
              iVar3 = (*pcVar1)(lVar4,param_2,*puVar8,puVar9);
              if (iVar3 != 0) goto LAB_001bb2e2;
              switch(param_3) {
              default:
                goto switchD_001baf04_caseD_1f;
              case 1:
                *(uint *)(puVar9 + 8) = *(uint *)(puVar8 + 0x11) / 100;
                break;
              case 2:
                *(uint *)(puVar9 + 8) = *(uint *)(puVar8 + 1) / 100;
                break;
              case 3:
                *(uint *)(puVar9 + 8) = *(uint *)(puVar8 + 0x21) / 100;
                break;
              case 4:
                *(uint *)(puVar9 + 8) = *(uint *)(puVar8 + 0x31) / 100;
                break;
              case 8:
                *(uint *)(puVar9 + 8) = *(uint *)(puVar8 + 0x41) / 100;
                break;
              case 9:
                *(uint *)(puVar9 + 8) = *(uint *)(puVar8 + 0x51) / 100;
              }
              uVar7 = uVar7 + 1;
              puVar8 = puVar8 + 0x61;
              puVar9 = puVar9 + 0x10;
              local_df30 = (uint)uVar5;
            } while (uVar7 < local_df30);
          }
          if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x40) != 0)) &&
             (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x40) + 0x10), pcVar1 != (code *)0x0)) {
            iVar3 = (*pcVar1)(DAT_012164a0,local_df08,param_3,(ulong)uVar2 / 0x308,uVar5,param_5,
                              param_6,param_4);
            return iVar3;
          }
          goto switchD_001baf04_caseD_56;
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar3;
      }
      fVar10 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      uVar12 = 0x1f2;
      uVar6 = 0x1f2;
      dVar11 = (double)(fVar10 * DAT_00298548);
      goto LAB_001baf83;
    default:
      iVar3 = 999;
      break;
    case 3:
    case 0x66:
      iVar3 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      iVar3 = 0x13;
      break;
    case 0x1a:
      iVar3 = 0x17;
      break;
    case 0x1b:
      iVar3 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
switchD_001baf04_caseD_1f:
      iVar3 = 2;
      break;
    case 0x51:
      iVar3 = 0x14;
      break;
    case 0x55:
      iVar3 = 0x1b;
      break;
    case 0x56:
switchD_001baf04_caseD_56:
      iVar3 = 3;
      break;
    case 0x59:
      iVar3 = 0x11;
      break;
    case 0x62:
      iVar3 = 0x10;
    }
  }
  return iVar3;
}


// ===== 001bb350 FUN_001bb350 =====

int FUN_001bb350(long param_1,long param_2,undefined8 param_3,undefined4 *param_4,long param_5,
                int param_6)

{
  undefined4 uVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  uint uVar9;
  char *__src;
  uint uVar10;
  float fVar11;
  double dVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined4 uStack_163cc;
  undefined1 auStack_163c8 [35136];
  undefined1 local_da88 [4];
  uint local_da84;
  uint local_da7c;
  char local_d9e0 [55728];
  
  memset(local_da88,0,0xda50);
  memset(auStack_163c8,0,0x8940);
  if (param_5 == 0) {
    *param_4 = 0x48;
    return 0;
  }
  lVar6 = *(long *)(param_2 + 0x256d8);
  if (((lVar6 == 0) || (*(undefined8 **)(lVar6 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar6 + 0x50), pcVar2 == (code *)0x0)) {
    iVar5 = 3;
LAB_001bb48e:
    if (DAT_01216a78 < 2) {
      return iVar5;
    }
    fVar11 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    uVar14 = 0x10a;
    uVar8 = 0x10a;
    dVar12 = (double)(fVar11 * DAT_00298548);
LAB_001bb4fb:
    FUN_002340f0(dVar12,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar6,
                 "dmal/common/common_utilization.c",uVar8,"cDeviceGetPerProcessUtilizationSamples",
                 uVar14,iVar5);
  }
  else {
    uVar8 = *(undefined8 *)(param_1 + 0x10);
    uVar14 = 0x1bb40c;
    iVar5 = (*pcVar2)(lVar6,param_2,0x2080,&uStack_163cc);
    if (iVar5 != 0) goto LAB_001bb48e;
    local_da88[0] = 2;
    local_da84 = 0xda40;
    uVar13 = 0;
    local_da7c = 0;
    iVar5 = FUN_0019c780(uVar8,DAT_0038088c,uStack_163cc,0x20802096,local_da88,0xda50);
    uVar4 = local_da7c;
    uVar3 = local_da84;
    switch(iVar5) {
    case 0:
      lVar6 = *(long *)(param_2 + 0x256d8);
      if (((lVar6 == 0) || (*(long *)(lVar6 + 0x40) == 0)) ||
         (pcVar2 = *(code **)(*(long *)(lVar6 + 0x40) + 0x18), pcVar2 == (code *)0x0)) {
        iVar5 = 3;
      }
      else {
        iVar5 = (*pcVar2)(lVar6,param_2,iVar5,local_da7c,uVar13,uVar14);
        if (iVar5 == 0) {
          if (uVar3 < 0x308) {
            *param_4 = 0;
            return 6;
          }
          __src = local_d9e0;
          uVar10 = 0;
          puVar7 = auStack_163c8;
          do {
            lVar6 = *(long *)(param_2 + 0x256d8);
            uVar10 = uVar10 + 1;
            if (((lVar6 == 0) || (*(long *)(lVar6 + 0x40) == 0)) ||
               (pcVar2 = *(code **)(*(long *)(lVar6 + 0x40) + 0x20), pcVar2 == (code *)0x0)) {
              iVar5 = 3;
LAB_001bb98d:
              if (DAT_01216a78 < 2) {
                return iVar5;
              }
              fVar11 = (float)FUN_002917b0(&DAT_01216a60);
              lVar6 = syscall(0xba);
              uVar14 = 0x125;
              uVar8 = 0x125;
              dVar12 = (double)(fVar11 * DAT_00298548);
              goto LAB_001bb4fb;
            }
            iVar5 = (*pcVar2)(lVar6,param_2,*(undefined8 *)(__src + -0x98),puVar7);
            if (iVar5 != 0) goto LAB_001bb98d;
            *(undefined4 *)(puVar7 + 0x10) = *(undefined4 *)(__src + -8);
            *(uint *)(puVar7 + 8) = *(uint *)(__src + -0x10) / 100;
            if (param_6 == 0) {
              *(undefined4 *)(puVar7 + 0x60) = *(undefined4 *)(__src + -0x88);
              *(uint *)(puVar7 + 0x58) = *(uint *)(__src + -0x90) / 100;
              *(undefined4 *)(puVar7 + 0xb0) = *(undefined4 *)(__src + 0x78);
              *(uint *)(puVar7 + 0xa8) = *(uint *)(__src + 0x70) / 100;
              *(undefined4 *)(puVar7 + 0x100) = *(undefined4 *)(__src + 0xf8);
              *(uint *)(puVar7 + 0xf8) = *(uint *)(__src + 0xf0) / 100;
              *(undefined4 *)(puVar7 + 0x150) = *(undefined4 *)(__src + 0x178);
              *(uint *)(puVar7 + 0x148) = *(uint *)(__src + 0x170) / 100;
              *(undefined4 *)(puVar7 + 0x1a0) = *(undefined4 *)(__src + 0x1f8);
              *(uint *)(puVar7 + 0x198) = *(uint *)(__src + 0x1f0) / 100;
            }
            else {
              *(undefined4 *)(puVar7 + 0x14) = *(undefined4 *)(__src + -4);
              strncpy(puVar7 + 0x18,__src,0x3f);
              uVar1 = *(undefined4 *)(__src + -0x88);
              puVar7[0x57] = 0;
              *(undefined4 *)(puVar7 + 0x60) = uVar1;
              *(uint *)(puVar7 + 0x58) = *(uint *)(__src + -0x90) / 100;
              *(undefined4 *)(puVar7 + 100) = *(undefined4 *)(__src + -0x84);
              strncpy(puVar7 + 0x68,__src + -0x80,0x3f);
              uVar1 = *(undefined4 *)(__src + 0x78);
              puVar7[0xa7] = 0;
              *(undefined4 *)(puVar7 + 0xb0) = uVar1;
              *(uint *)(puVar7 + 0xa8) = *(uint *)(__src + 0x70) / 100;
              *(undefined4 *)(puVar7 + 0xb4) = *(undefined4 *)(__src + 0x7c);
              strncpy(puVar7 + 0xb8,__src + 0x80,0x3f);
              uVar1 = *(undefined4 *)(__src + 0xf8);
              puVar7[0xf7] = 0;
              *(undefined4 *)(puVar7 + 0x100) = uVar1;
              *(uint *)(puVar7 + 0xf8) = *(uint *)(__src + 0xf0) / 100;
              *(undefined4 *)(puVar7 + 0x104) = *(undefined4 *)(__src + 0xfc);
              strncpy(puVar7 + 0x108,__src + 0x100,0x3f);
              uVar1 = *(undefined4 *)(__src + 0x178);
              puVar7[0x147] = 0;
              *(undefined4 *)(puVar7 + 0x150) = uVar1;
              *(uint *)(puVar7 + 0x148) = *(uint *)(__src + 0x170) / 100;
              *(undefined4 *)(puVar7 + 0x154) = *(undefined4 *)(__src + 0x17c);
              strncpy(puVar7 + 0x158,__src + 0x180,0x3f);
              uVar1 = *(undefined4 *)(__src + 0x1f8);
              puVar7[0x197] = 0;
              *(undefined4 *)(puVar7 + 0x1a0) = uVar1;
              *(uint *)(puVar7 + 0x198) = *(uint *)(__src + 0x1f0) / 100;
              *(undefined4 *)(puVar7 + 0x1a4) = *(undefined4 *)(__src + 0x1fc);
              strncpy(puVar7 + 0x1a8,__src + 0x200,0x3f);
              puVar7[0x1e7] = 0;
            }
            puVar7 = puVar7 + 0x1e8;
            __src = __src + 0x308;
            uVar9 = uVar3 / 0x308;
          } while (uVar10 < uVar9);
          lVar6 = *(long *)(param_2 + 0x256d8);
          if (((lVar6 != 0) && (*(long *)(lVar6 + 0x40) != 0)) &&
             (pcVar2 = *(code **)(*(long *)(lVar6 + 0x40) + 8), pcVar2 != (code *)0x0)) {
            iVar5 = (*pcVar2)(lVar6,param_2,auStack_163c8,uVar4 / 0x308,uVar9,param_4,param_5,
                              param_3);
            return iVar5;
          }
          goto switchD_001bb481_caseD_56;
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar5;
      }
      fVar11 = (float)FUN_002917b0(&DAT_01216a60);
      lVar6 = syscall(0xba);
      uVar14 = 0x11c;
      uVar8 = 0x11c;
      dVar12 = (double)(fVar11 * DAT_00298548);
      goto LAB_001bb4fb;
    default:
      iVar5 = 999;
      break;
    case 3:
    case 0x66:
      iVar5 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      iVar5 = 0x13;
      break;
    case 0x1a:
      iVar5 = 0x17;
      break;
    case 0x1b:
      iVar5 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
      iVar5 = 2;
      break;
    case 0x51:
      iVar5 = 0x14;
      break;
    case 0x55:
      iVar5 = 0x1b;
      break;
    case 0x56:
switchD_001bb481_caseD_56:
      iVar5 = 3;
      break;
    case 0x59:
      iVar5 = 0x11;
      break;
    case 0x62:
      iVar5 = 0x10;
    }
  }
  return iVar5;
}


// ===== 001bba80 FUN_001bba80 =====

int FUN_001bba80(undefined8 param_1,long param_2,int *param_3)

{
  code *pcVar1;
  undefined8 *puVar2;
  ulong uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  undefined8 *puVar7;
  uint uVar8;
  undefined8 uVar9;
  float fVar10;
  double dVar11;
  undefined8 uVar12;
  undefined4 uStack_1e890;
  int iStack_1e88c;
  int aiStack_1e888 [20];
  undefined1 auStack_1e838 [124936];
  
  memset(auStack_1e838,0,0x1e800);
  uStack_1e890 = 0x100;
  iStack_1e88c = 0;
  iVar4 = FUN_00175bd0(param_2,aiStack_1e888);
  if (iVar4 == 2) {
    return 2;
  }
  if (iVar4 == 0xf) {
    return 0xf;
  }
  if (iVar4 != 0) {
    return 999;
  }
  if (aiStack_1e888[0] == 0) {
    if (DAT_01216a78 < 4) {
      return 3;
    }
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar5,"dmal/common/common_utilization.c",0x24f);
    return 3;
  }
  if (param_3 == (int *)0x0) {
    return 2;
  }
  if (*param_3 != 0x1000020) {
    return 0x19;
  }
  lVar5 = *(long *)(param_2 + 0x25d60);
  if (lVar5 == 0) {
    return 3;
  }
  if ((*(long *)(param_3 + 6) != 0) && (param_3[2] == 0)) {
    return 2;
  }
  lVar6 = *(long *)(param_2 + 0x256d8);
  if ((((lVar6 == 0) || (*(long *)(lVar6 + 0x28) == 0)) ||
      (pcVar1 = *(code **)(*(long *)(lVar6 + 0x28) + 0x128), pcVar1 == (code *)0x0)) ||
     ((iVar4 = (*pcVar1)(lVar6,param_2), iVar4 != 0 || (*(int *)(lVar5 + 0x628) != 0)))) {
LAB_001bbcf0:
    uVar8 = *(uint *)(lVar5 + 4);
    if (uVar8 == 0) {
      param_3[2] = 0;
      return 0;
    }
    if ((*(long *)(param_3 + 6) == 0) || ((uint)param_3[2] < uVar8)) {
      param_3[2] = uVar8;
      return 7;
    }
    iVar4 = FUN_001bab60(param_2,&iStack_1e88c,6);
    if (iVar4 == 0) {
      if (iStack_1e88c == 0) {
        uVar8 = 0;
        uVar3 = 0;
        for (puVar2 = *(undefined8 **)(lVar5 + 0x618); (undefined8 *)(lVar5 + 0x618) != puVar2;
            puVar2 = (undefined8 *)*puVar2) {
          uVar8 = (int)uVar3 + 1;
          lVar6 = uVar3 * 0x40;
          *(undefined4 *)(*(long *)(param_3 + 6) + 0x10 + lVar6) = 0;
          *(undefined4 *)(*(long *)(param_3 + 6) + 0x18 + lVar6) = 0;
          *(undefined4 *)(*(long *)(param_3 + 6) + 0x20 + lVar6) = 0;
          *(undefined4 *)(*(long *)(param_3 + 6) + 0x28 + lVar6) = 0;
          *(undefined4 *)(*(long *)(param_3 + 6) + 0x30 + lVar6) = 0;
          *(undefined4 *)(*(long *)(param_3 + 6) + 0x38 + lVar6) = 0;
          *(undefined4 *)(*(long *)(param_3 + 6) + 8 + lVar6) = *(undefined4 *)(puVar2 + -0x43);
          *(undefined8 *)(*(long *)(param_3 + 6) + lVar6) = *(undefined8 *)(param_3 + 4);
          uVar3 = (ulong)uVar8;
        }
        param_3[2] = uVar8;
        param_3[1] = 1;
        return 0;
      }
      iVar4 = FUN_001bb350(param_1,param_2,*(undefined8 *)(param_3 + 4),&uStack_1e890,auStack_1e838,
                           0);
      if (iVar4 == 6) {
        uVar8 = 0;
        uVar3 = 0;
        for (puVar2 = *(undefined8 **)(lVar5 + 0x618); (undefined8 *)(lVar5 + 0x618) != puVar2;
            puVar2 = (undefined8 *)*puVar2) {
          uVar8 = (int)uVar3 + 1;
          lVar6 = uVar3 * 0x40;
          *(undefined4 *)(*(long *)(param_3 + 6) + 0x10 + lVar6) = 0;
          *(undefined4 *)(*(long *)(param_3 + 6) + 0x18 + lVar6) = 0;
          *(undefined4 *)(*(long *)(param_3 + 6) + 0x20 + lVar6) = 0;
          *(undefined4 *)(*(long *)(param_3 + 6) + 0x28 + lVar6) = 0;
          *(undefined4 *)(*(long *)(param_3 + 6) + 0x30 + lVar6) = 0;
          *(undefined4 *)(*(long *)(param_3 + 6) + 0x38 + lVar6) = 0;
          *(undefined4 *)(*(long *)(param_3 + 6) + 8 + lVar6) = *(undefined4 *)(puVar2 + -0x43);
          *(undefined8 *)(*(long *)(param_3 + 6) + lVar6) = *(undefined8 *)(param_3 + 4);
          uVar3 = (ulong)uVar8;
        }
        param_3[2] = uVar8;
        param_3[1] = 1;
        return 0;
      }
      if (iVar4 == 0) {
        iVar4 = FUN_00234b40(aiStack_1e888,FUN_00121360,FUN_00121370,free,free);
        if (iVar4 == 0) {
          iVar4 = FUN_00121460(aiStack_1e888,auStack_1e838,uStack_1e890);
          if (iVar4 == 0) {
            uVar8 = 0;
            for (puVar2 = *(undefined8 **)(lVar5 + 0x618); (undefined8 *)(lVar5 + 0x618) != puVar2;
                puVar2 = (undefined8 *)*puVar2) {
              puVar7 = (undefined8 *)FUN_00234de0(aiStack_1e888,puVar2 + -0x42);
              lVar6 = (ulong)uVar8 * 0x40;
              if (puVar7 == (undefined8 *)0x0) {
                *(undefined4 *)(*(long *)(param_3 + 6) + 0x10 + lVar6) = 0;
                *(undefined4 *)(*(long *)(param_3 + 6) + 0x18 + lVar6) = 0;
                *(undefined4 *)(*(long *)(param_3 + 6) + 0x20 + lVar6) = 0;
                *(undefined4 *)(*(long *)(param_3 + 6) + 0x28 + lVar6) = 0;
                *(undefined4 *)(*(long *)(param_3 + 6) + 0x30 + lVar6) = 0;
                *(undefined4 *)(*(long *)(param_3 + 6) + 0x38 + lVar6) = 0;
                *(undefined4 *)(*(long *)(param_3 + 6) + 8 + lVar6) =
                     *(undefined4 *)(puVar2 + -0x43);
                *(undefined8 *)(*(long *)(param_3 + 6) + lVar6) = *(undefined8 *)(param_3 + 4);
              }
              else {
                *(int *)(*(long *)(param_3 + 6) + 0x10 + lVar6) = (int)(long)(double)puVar7[2];
                *(int *)(*(long *)(param_3 + 6) + 0x18 + lVar6) = (int)(long)(double)puVar7[3];
                *(int *)(*(long *)(param_3 + 6) + 0x20 + lVar6) = (int)(long)(double)puVar7[4];
                *(int *)(*(long *)(param_3 + 6) + 0x28 + lVar6) = (int)(long)(double)puVar7[5];
                *(int *)(*(long *)(param_3 + 6) + 0x30 + lVar6) = (int)(long)(double)puVar7[6];
                *(int *)(*(long *)(param_3 + 6) + 0x38 + lVar6) = (int)(long)(double)puVar7[7];
                *(undefined4 *)(*(long *)(param_3 + 6) + 8 + lVar6) =
                     *(undefined4 *)(puVar2 + -0x43);
                *(undefined8 *)(*(long *)(param_3 + 6) + lVar6) = *puVar7;
              }
              uVar8 = uVar8 + 1;
            }
            param_3[2] = uVar8;
            param_3[1] = 1;
          }
          FUN_00234bf0(aiStack_1e888);
          return iVar4;
        }
        if (DAT_01216a78 < 2) {
          return 0x14;
        }
        fVar10 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR"
                     ,lVar5,"dmal/common/common_utilization.c",0x2b9);
        return 0x14;
      }
      if (DAT_01216a78 < 2) {
        return iVar4;
      }
      fVar10 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      uVar12 = 0x2b3;
      uVar9 = 0x2b3;
      dVar11 = (double)(fVar10 * DAT_00298548);
    }
    else {
      if (DAT_01216a78 < 2) {
        return iVar4;
      }
      fVar10 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      uVar12 = 0x280;
      uVar9 = 0x280;
      dVar11 = (double)(fVar10 * DAT_00298548);
    }
  }
  else {
    lVar6 = *(long *)(param_2 + 0x256d8);
    if ((lVar6 == 0) ||
       ((*(long *)(lVar6 + 0x28) == 0 ||
        (pcVar1 = *(code **)(*(long *)(lVar6 + 0x28) + 0x48), pcVar1 == (code *)0x0)))) {
      iVar4 = 3;
    }
    else {
      iVar4 = (*pcVar1)(lVar6,param_2);
      if (iVar4 == 0) goto LAB_001bbcf0;
    }
    if (DAT_01216a78 < 2) {
      return iVar4;
    }
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    uVar12 = 0x26c;
    uVar9 = 0x26c;
    dVar11 = (double)(fVar10 * DAT_00298548);
  }
  FUN_002340f0(dVar11,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,
               "dmal/common/common_utilization.c",uVar9,"cDeviceGetVgpuInstancesUtilizationInfo",
               uVar12,iVar4);
  return iVar4;
}


// ===== 001bc220 FUN_001bc220 =====

int FUN_001bc220(undefined8 param_1,undefined8 param_2,int *param_3)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
  undefined4 *puVar9;
  float fVar10;
  undefined8 uVar11;
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
  iVar3 = FUN_00175bd0(param_2,local_89c8);
  if ((iVar3 != 2) && (iVar3 != 0xf)) {
    if (iVar3 == 0) {
      if (local_89c8[0] == 0) {
        iVar3 = 3;
        if (3 < DAT_01216a78) {
          fVar10 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       &DAT_002983c2,lVar4,"dmal/common/common_utilization.c",0x177);
        }
      }
      else if (param_3 == (int *)0x0) {
        iVar3 = 2;
      }
      else {
        iVar3 = 0x19;
        if (*param_3 == 0x1000018) {
          if ((*(long *)(param_3 + 4) == 0) || ((uint)param_3[1] < 0x48)) {
            param_3[1] = 0x48;
            iVar3 = 7;
          }
          else {
            iVar3 = FUN_001bab60(param_2,&local_89d8,6);
            if (iVar3 == 0) {
              if (local_89d8 == 0) {
                param_3[1] = 0;
                return 0;
              }
              iVar3 = FUN_001bb350(param_1,param_2,*(undefined8 *)(param_3 + 2),&local_89dc,
                                   local_8978,0);
              if (iVar3 == 0) {
                iVar3 = FUN_00234b40(local_89c8,FUN_0012f5d0,FUN_0012f5e0,free,free);
                if (iVar3 != 0) {
                  return 999;
                }
                iVar3 = FUN_0012f700(local_89c8,local_8978,local_89dc,&local_89d0);
                if (iVar3 == 0) {
                  iVar6 = 0;
                  if (local_89d0 != (undefined4 *)0x0) {
                    uVar7 = 0;
                    puVar9 = local_89d0;
                    do {
                      uVar2 = *puVar9;
                      local_89d4 = uVar2;
                      lVar4 = FUN_00234de0(local_89c8,&local_89d4);
                      uVar8 = uVar7;
                      if (lVar4 != 0) {
                        uVar8 = (ulong)((int)uVar7 + 1);
                        lVar1 = uVar7 * 0x28;
                        *(int *)(*(long *)(param_3 + 4) + 0xc + lVar1) =
                             (int)(long)*(double *)(lVar4 + 0x10);
                        *(int *)(*(long *)(param_3 + 4) + 0x10 + lVar1) =
                             (int)(long)*(double *)(lVar4 + 0x18);
                        *(int *)(*(long *)(param_3 + 4) + 0x14 + lVar1) =
                             (int)(long)*(double *)(lVar4 + 0x20);
                        *(int *)(*(long *)(param_3 + 4) + 0x18 + lVar1) =
                             (int)(long)*(double *)(lVar4 + 0x28);
                        *(int *)(*(long *)(param_3 + 4) + 0x1c + lVar1) =
                             (int)(long)*(double *)(lVar4 + 0x30);
                        *(int *)(*(long *)(param_3 + 4) + 0x20 + lVar1) =
                             (int)(long)*(double *)(lVar4 + 0x38);
                        *(undefined4 *)(*(long *)(param_3 + 4) + 8 + lVar1) = uVar2;
                        *(undefined8 *)(*(long *)(param_3 + 4) + uVar7 * 0x28) =
                             *(undefined8 *)(lVar4 + 8);
                      }
                      iVar6 = (int)uVar8;
                      puVar9 = *(undefined4 **)(puVar9 + 2);
                      uVar7 = uVar8;
                    } while (puVar9 != (undefined4 *)0x0);
                  }
                  param_3[1] = iVar6;
                }
                FUN_00234bf0(local_89c8);
                FUN_0012fe20(&local_89d0);
                return iVar3;
              }
              if (DAT_01216a78 < 2) {
                return iVar3;
              }
              fVar10 = (float)FUN_002917b0(&DAT_01216a60);
              lVar4 = syscall(0xba);
              fVar10 = fVar10 * DAT_00298548;
              uVar11 = 0x198;
              uVar5 = 0x198;
            }
            else {
              if (DAT_01216a78 < 2) {
                return iVar3;
              }
              fVar10 = (float)FUN_002917b0(&DAT_01216a60);
              lVar4 = syscall(0xba);
              fVar10 = fVar10 * DAT_00298548;
              uVar11 = 0x18e;
              uVar5 = 0x18e;
            }
            FUN_002340f0((double)fVar10,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",
                         lVar4,"dmal/common/common_utilization.c",uVar5,
                         "cDeviceGetProcessesUtilizationInfo",uVar11,iVar3);
          }
        }
      }
    }
    else {
      iVar3 = 999;
    }
  }
  return iVar3;
}


// ===== 001bc650 FUN_001bc650 =====

int FUN_001bc650(long param_1,long param_2,undefined4 param_3,uint *param_4)

{
  code *pcVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  undefined8 *puVar5;
  byte bVar6;
  float fVar7;
  undefined4 local_4cc;
  undefined8 local_4c8;
  uint local_4c0;
  
  bVar6 = 0;
  puVar5 = &local_4c8;
  for (lVar4 = 0x92; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    uVar2 = *(undefined8 *)(param_1 + 0x10);
    iVar3 = (*pcVar1)(lVar4,param_2,0x2080,&local_4cc);
    if (iVar3 == 0) {
      puVar5 = &local_4c8;
      for (lVar4 = 0x92; lVar4 != 0; lVar4 = lVar4 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + (ulong)bVar6 * -2 + 1;
      }
      iVar3 = FUN_00133750(param_3,(long)&local_4c8 + 4);
      if (iVar3 == 0) {
        local_4c8._0_4_ = 1;
        iVar3 = FUN_0019c780(uVar2,DAT_0038088c,local_4cc,0x2080a097,&local_4c8,0x490);
        switch(iVar3) {
        case 0:
          goto switchD_001bc88d_caseD_0;
        default:
          return 999;
        case 3:
        case 0x66:
          return 10;
        case 0xf:
          return iVar3;
        case 0x17:
        case 99:
          return 0x13;
        case 0x1a:
          return 0x17;
        case 0x1b:
          return 4;
        case 0x1f:
        case 0x3b:
        case 0x54:
          return 2;
        case 0x51:
          return 0x14;
        case 0x55:
          return 0x1b;
        case 0x56:
          return 3;
        case 0x59:
          return 0x11;
        case 0x62:
          return 0x10;
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar3;
      }
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %x\n",
                   "ERROR",lVar4,"dmal/common/common_utilization.c",0xd4,iVar3,param_3);
      return iVar3;
    }
  }
  if (1 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_utilization.c",0xca,"cDeviceGetUtilizationRate",
                 0xca,iVar3);
  }
  return iVar3;
switchD_001bc88d_caseD_0:
  *param_4 = local_4c0;
  if (4 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %d\n","DEBUG"
                 ,lVar4,"dmal/common/common_utilization.c",0xe3,param_3,local_4c0);
    local_4c0 = *param_4;
  }
  if (local_4c0 < 0x65) {
    return iVar3;
  }
  if (DAT_01216a78 < 2) {
    return 999;
  }
  fVar7 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %u\n","ERROR",
               lVar4,"dmal/common/common_utilization.c",0xe7,param_3,local_4c0,lVar4);
  return 999;
}


// ===== 001bca30 FUN_001bca30 =====

int FUN_001bca30(undefined8 param_1,long param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  uint *puVar7;
  byte bVar8;
  float fVar9;
  uint local_4dc;
  undefined4 local_4d8;
  undefined4 local_4d4;
  undefined8 local_4d0;
  uint local_4c8;
  uint local_4c4 [293];
  
  bVar8 = 0;
  local_4d4 = 0;
  puVar7 = &local_4c8;
  for (lVar6 = 0x92; lVar6 != 0; lVar6 = lVar6 + -1) {
    puVar7[0] = 0;
    puVar7[1] = 0;
    puVar7 = puVar7 + 2;
  }
  local_4d0 = 0x200000000;
  param_3[0] = 0;
  param_3[1] = 0;
  lVar6 = *(long *)(param_2 + 0x256d8);
  if (((lVar6 == 0) || (*(undefined8 **)(lVar6 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar3 = (code *)**(undefined8 **)(lVar6 + 0x50), pcVar3 == (code *)0x0)) {
    iVar4 = 3;
  }
  else {
    iVar4 = (*pcVar3)(lVar6,param_2,0x2080,&local_4d8);
    if (iVar4 == 0) {
      puVar7 = &local_4c8;
      for (lVar6 = 0x92; lVar6 != 0; lVar6 = lVar6 + -1) {
        puVar7[0] = 0;
        puVar7[1] = 0;
        puVar7 = puVar7 + ((ulong)bVar8 * -2 + 1) * 2;
      }
      local_4dc = 0;
      puVar7 = (uint *)&local_4d0;
      do {
        lVar6 = *(long *)(param_2 + 0x256d8);
        if (((lVar6 == 0) || (*(long *)(lVar6 + 0x170) == 0)) ||
           (pcVar3 = *(code **)(*(long *)(lVar6 + 0x170) + 0x18), pcVar3 == (code *)0x0)) {
          iVar4 = 3;
LAB_001bcc96:
          if (1 < DAT_01216a78) {
            uVar1 = *puVar7;
            fVar9 = (float)FUN_002917b0(&DAT_01216a60);
            lVar6 = syscall(0xba);
            FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %d\n"
                         ,"ERROR",lVar6,"dmal/common/common_utilization.c",0x6d,iVar4,uVar1);
          }
        }
        else {
          iVar4 = (*pcVar3)(lVar6,param_2,*(undefined4 *)((long)&local_4d0 + (ulong)local_4dc * 4),
                            local_4c4 + (ulong)local_4dc * 4,&local_4d4);
          if (iVar4 != 0) goto LAB_001bcc96;
          local_4dc = local_4dc + 1;
        }
        puVar7 = puVar7 + 1;
        if (&local_4c8 == puVar7) {
          if (local_4dc == 0) {
            return iVar4;
          }
          local_4c8 = local_4dc;
          iVar4 = FUN_0019c780(param_1,DAT_0038088c,local_4d8,0x2080a097,&local_4c8,0x490,0);
          switch(iVar4) {
          case 0:
            lVar6 = 0;
            puVar7 = local_4c4;
            break;
          default:
            return 999;
          case 3:
          case 0x66:
            return 10;
          case 0xf:
            return iVar4;
          case 0x17:
          case 99:
            return 0x13;
          case 0x1a:
            return 0x17;
          case 0x1b:
            return 4;
          case 0x1f:
          case 0x3b:
          case 0x54:
            return 2;
          case 0x51:
            return 0x14;
          case 0x55:
            return 0x1b;
          case 0x56:
            return 3;
          case 0x59:
            return 0x11;
          case 0x62:
            return 0x10;
          }
          do {
            uVar1 = puVar7[1];
            if (100 < uVar1) {
              if (DAT_01216a78 < 2) {
                return 999;
              }
              uVar2 = *puVar7;
              fVar9 = (float)FUN_002917b0(&DAT_01216a60);
              lVar6 = syscall(0xba);
              FUN_002340f0((double)(fVar9 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %u\n","ERROR",lVar6,
                           "dmal/common/common_utilization.c",0x89,uVar2,uVar1);
              return 999;
            }
            uVar2 = *(uint *)((long)&local_4d0 + lVar6 * 4);
            if (uVar2 == 0) {
              *param_3 = uVar1;
            }
            else {
              if (uVar2 != 2) {
                if (DAT_01216a78 < 2) {
                  return 999;
                }
                uVar1 = *puVar7;
                fVar9 = (float)FUN_002917b0(&DAT_01216a60);
                lVar6 = syscall(0xba);
                FUN_002340f0((double)(fVar9 * DAT_00298548),
                             "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","ERROR",lVar6,
                             "dmal/common/common_utilization.c",0x99,uVar1);
                return 999;
              }
              param_3[1] = uVar1;
            }
            if (4 < DAT_01216a78) {
              uVar2 = *puVar7;
              fVar9 = (float)FUN_002917b0(&DAT_01216a60);
              lVar5 = syscall(0xba);
              FUN_002340f0((double)(fVar9 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %d\n","DEBUG",lVar5,
                           "dmal/common/common_utilization.c",0x9e,uVar2,uVar1);
            }
            lVar6 = lVar6 + 1;
            puVar7 = puVar7 + 4;
          } while ((uint)lVar6 < local_4dc);
          return iVar4;
        }
      } while( true );
    }
  }
  if (1 < DAT_01216a78) {
    fVar9 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar6,"dmal/common/common_utilization.c",0x5f,
                 "cDeviceGetUtilizationRatesRmApi",0x5f,iVar4);
  }
  return iVar4;
}


// ===== 001bcfe0 FUN_001bcfe0 =====

ulong FUN_001bcfe0(long param_1,char *param_2,undefined8 param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  float fVar5;
  char local_2d;
  int local_2c [3];
  
  if (*param_2 == '\x01') {
    if (((*(long *)(param_2 + 0x256d8) != 0) &&
        (lVar3 = *(long *)(*(long *)(param_2 + 0x256d8) + 0x188), lVar3 != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(lVar3 + 0x28), UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001bd15b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar4 = (*UNRECOVERED_JUMPTABLE)();
      return uVar4;
    }
    return 3;
  }
  if (DAT_0032f668 != 0) {
    local_2c[0] = 0;
    iVar1 = FUN_001bab60(param_2,local_2c,10);
    if (((iVar1 == 0) && (local_2c[0] != 0)) &&
       ((*param_2 == '\x01' || (*(long *)(param_2 + 0x20) != 0)))) {
      lVar3 = *(long *)(param_2 + 0x256d8);
      local_2d = '\0';
      if (((lVar3 != 0) && (*(long *)(lVar3 + 0x38) != 0)) &&
         (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar3 + 0x38) + 0x80),
         UNRECOVERED_JUMPTABLE != (code *)0x0)) {
        (*UNRECOVERED_JUMPTABLE)(lVar3,param_2,&local_2d);
        if (local_2d != '\0') goto LAB_001bd088;
        lVar3 = *(long *)(param_2 + 0x256d8);
      }
      local_2d = '\0';
      if (lVar3 != 0) {
        if ((*(long *)(lVar3 + 0x38) != 0) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar3 + 0x38) + 0x88),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
          (*UNRECOVERED_JUMPTABLE)(lVar3,param_2,&local_2d);
          if (local_2d != '\0') goto LAB_001bd088;
          lVar3 = *(long *)(param_2 + 0x256d8);
        }
        if ((((lVar3 != 0) && (*(long *)(lVar3 + 0x120) != 0)) &&
            (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar3 + 0x120) + 0x10),
            UNRECOVERED_JUMPTABLE != (code *)0x0)) &&
           (iVar1 = (*UNRECOVERED_JUMPTABLE)(lVar3,param_2,param_3), iVar1 == 0)) {
          return 0;
        }
      }
    }
  }
LAB_001bd088:
  uVar2 = FUN_001bca30(*(undefined8 *)(param_1 + 0x10),param_2,param_3);
  uVar4 = (ulong)uVar2;
  if (uVar2 == 0) {
    return 0;
  }
  if (1 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar3,"dmal/common/common_utilization.c",0xae,"cDeviceGetUtilizationRates",
                 0xae,uVar4);
    return uVar4;
  }
  return uVar4;
}


// ===== 001bd200 FUN_001bd200 =====

int FUN_001bd200(long param_1,char *param_2,uint *param_3,int *param_4,undefined4 *param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  float fVar8;
  undefined8 uVar9;
  char local_3d;
  int local_3c [3];
  
  if (DAT_0032f668 == 0) {
LAB_001bd2b8:
    lVar6 = *(long *)(param_2 + 0x256d8);
    uVar7 = *(undefined8 *)(param_1 + 0x10);
    if (lVar6 != 0) {
LAB_001bd2cd:
      if ((*(undefined8 **)(lVar6 + 0x50) != (undefined8 *)0x0) &&
         (pcVar4 = (code *)**(undefined8 **)(lVar6 + 0x50), pcVar4 != (code *)0x0)) {
        uVar9 = 0x1bd2f8;
        iVar5 = (*pcVar4)(lVar6,param_2,0x2080,local_3c);
        if (iVar5 == 0) {
          iVar5 = FUN_0019c780(uVar7,DAT_0038088c,local_3c[0],0x20802087,param_5,0xc,0);
          switch(iVar5) {
          case 0:
            goto switchD_001bd3da_caseD_0;
          default:
            return 999;
          case 3:
          case 0x66:
            return 10;
          case 0xf:
            return iVar5;
          case 0x17:
          case 99:
            return 0x13;
          case 0x1a:
            return 0x17;
          case 0x1b:
            return 4;
          case 0x1f:
          case 0x3b:
          case 0x54:
            return 2;
          case 0x51:
            return 0x14;
          case 0x55:
            return 0x1b;
          case 0x56:
            return 3;
          case 0x59:
            return 0x11;
          case 0x62:
            return 0x10;
          }
        }
        goto joined_r0x001bd311;
      }
    }
  }
  else {
    local_3c[0] = 0;
    iVar5 = FUN_001bab60(param_2,local_3c,10);
    if (((iVar5 != 0) || (local_3c[0] == 0)) ||
       ((param_2 != (char *)0x0 && ((*param_2 != '\x01' && (*(long *)(param_2 + 0x20) == 0))))))
    goto LAB_001bd2b8;
    lVar6 = *(long *)(param_2 + 0x256d8);
    local_3d = '\0';
    if ((lVar6 != 0) &&
       ((*(long *)(lVar6 + 0x38) != 0 &&
        (pcVar4 = *(code **)(*(long *)(lVar6 + 0x38) + 0x80), pcVar4 != (code *)0x0)))) {
      (*pcVar4)(lVar6,param_2,&local_3d);
      if (local_3d != '\0') goto LAB_001bd2b8;
      lVar6 = *(long *)(param_2 + 0x256d8);
    }
    local_3d = '\0';
    if (lVar6 != 0) {
      if ((*(long *)(lVar6 + 0x38) != 0) &&
         (pcVar4 = *(code **)(*(long *)(lVar6 + 0x38) + 0x88), pcVar4 != (code *)0x0)) {
        (*pcVar4)(lVar6,param_2,&local_3d);
        if (local_3d != '\0') goto LAB_001bd2b8;
        lVar6 = *(long *)(param_2 + 0x256d8);
      }
      if (lVar6 == 0) goto LAB_001bd3e0;
      if ((*(long *)(lVar6 + 0x120) != 0) &&
         (pcVar4 = *(code **)(*(long *)(lVar6 + 0x120) + 0x70), pcVar4 != (code *)0x0)) {
        iVar5 = (*pcVar4)(lVar6,param_2,*(undefined1 *)param_5,param_3,param_4);
        if (iVar5 == 0) {
          return 0;
        }
        goto LAB_001bd2b8;
      }
      uVar7 = *(undefined8 *)(param_1 + 0x10);
      goto LAB_001bd2cd;
    }
  }
LAB_001bd3e0:
  iVar5 = 3;
joined_r0x001bd311:
  if (1 < DAT_01216a78) {
    fVar8 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar8 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar6,"dmal/common/common_utilization.c",0x1a,
                 "_deviceGetVidEngUtilizationRmApi",0x1a,iVar5);
  }
  return iVar5;
switchD_001bd3da_caseD_0:
  *param_3 = param_5[1];
  iVar1 = param_5[2];
  *param_4 = iVar1;
  uVar2 = *param_3;
  if ((iVar1 != 0) && (uVar2 < 0x65)) {
    return iVar5;
  }
  if (DAT_01216a78 < 2) {
    return 999;
  }
  uVar3 = *param_5;
  fVar8 = (float)FUN_002917b0(&DAT_01216a60,uVar9);
  lVar6 = syscall(0xba);
  FUN_002340f0((double)(fVar8 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %u %u\n",
               "ERROR",lVar6,"dmal/common/common_utilization.c",0x24,uVar3,uVar2,iVar1);
  return 999;
}


// ===== 001bd5b0 FUN_001bd5b0 =====

void FUN_001bd5b0(void)

{
  FUN_001bd200();
  return;
}


// ===== 001bd5e0 FUN_001bd5e0 =====

void FUN_001bd5e0(void)

{
  FUN_001bd200();
  return;
}


// ===== 001bd610 FUN_001bd610 =====

void FUN_001bd610(void)

{
  FUN_001bd200();
  return;
}


// ===== 001bd640 FUN_001bd640 =====

void FUN_001bd640(void)

{
  FUN_001bd200();
  return;
}


// ===== 001bd670 FUN_001bd670 =====

int FUN_001bd670(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  long *plVar4;
  int *piVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  long lVar11;
  float fVar12;
  double dVar13;
  undefined8 uVar14;
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
  iVar6 = FUN_00175bd0(param_2,local_89c8);
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
    if (DAT_01216a78 < 4) {
      return 3;
    }
    fVar12 = (float)FUN_002917b0(&DAT_01216a60);
    lVar7 = syscall(0xba);
    FUN_002340f0((double)(fVar12 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar7,"dmal/common/common_utilization.c",0x2ff);
    return 3;
  }
  if (param_3 == 0) {
    return 2;
  }
  lVar7 = *(long *)(param_2 + 0x25d60);
  if (lVar7 == 0) {
    return 3;
  }
  lVar8 = *(long *)(param_2 + 0x256d8);
  if ((((lVar8 == 0) || (*(long *)(lVar8 + 0x28) == 0)) ||
      (pcVar3 = *(code **)(*(long *)(lVar8 + 0x28) + 0x128), pcVar3 == (code *)0x0)) ||
     ((iVar6 = (*pcVar3)(lVar8,param_2), iVar6 != 0 || (*(int *)(lVar7 + 0x628) != 0)))) {
LAB_001bd8b0:
    if (*(int *)(lVar7 + 4) == 0) {
LAB_001bd9d0:
      *(undefined4 *)(param_3 + 4) = 0;
      return 0;
    }
    if ((*(long *)(param_3 + 0x10) == 0) || (*(uint *)(param_3 + 4) < 0x48)) {
      *(undefined4 *)(param_3 + 4) = 0x48;
      return 7;
    }
    iVar6 = FUN_001bab60(param_2,&local_89d8,6);
    if (iVar6 == 0) {
      if ((local_89d8 == 0) ||
         (iVar6 = FUN_001bb350(param_1,param_2,*(undefined8 *)(param_3 + 8),&local_89dc,local_8978,1
                              ), iVar6 == 6)) goto LAB_001bd9d0;
      if (iVar6 == 0) {
        iVar6 = FUN_00234b40(local_89c8,FUN_00121360,FUN_00121370,free,free);
        if (iVar6 == 0) {
          iVar6 = FUN_00121820(local_89c8,local_8978,local_89dc,&local_89d0);
          if (iVar6 == 0) {
            plVar4 = *(long **)(lVar7 + 0x618);
            uVar1 = 0;
            if ((long *)(lVar7 + 0x618) != plVar4) {
              do {
                lVar8 = thunk_FUN_00121800(local_89d0,(int)plVar4[-0x42]);
                if (lVar8 != 0) {
                  for (piVar5 = *(int **)(lVar8 + 0x10); piVar5 != (int *)0x0;
                      piVar5 = *(int **)(piVar5 + 0x12)) {
                    iVar2 = *piVar5;
                    local_89d4 = iVar2 * 100 + *(int *)(lVar8 + 4);
                    puVar9 = (undefined8 *)FUN_00234de0(local_89c8,&local_89d4);
                    if (puVar9 != (undefined8 *)0x0) {
                      lVar11 = (ulong)uVar1 * 0x68;
                      *(int *)(*(long *)(param_3 + 0x10) + 0x50 + lVar11) =
                           (int)(long)(double)puVar9[2];
                      *(int *)(*(long *)(param_3 + 0x10) + 0x54 + lVar11) =
                           (int)(long)(double)puVar9[3];
                      *(int *)(*(long *)(param_3 + 0x10) + 0x58 + lVar11) =
                           (int)(long)(double)puVar9[4];
                      *(int *)(*(long *)(param_3 + 0x10) + 0x5c + lVar11) =
                           (int)(long)(double)puVar9[5];
                      *(int *)(*(long *)(param_3 + 0x10) + 0x60 + lVar11) =
                           (int)(long)(double)puVar9[6];
                      *(int *)(*(long *)(param_3 + 0x10) + 100 + lVar11) =
                           (int)(long)(double)puVar9[7];
                      *(int *)(*(long *)(param_3 + 0x10) + 0x4c + lVar11) = iVar2;
                      strncpy((char *)(lVar11 + *(long *)(param_3 + 0x10)),(char *)(piVar5 + 1),0x40
                             );
                      uVar1 = uVar1 + 1;
                      *(int *)(*(long *)(param_3 + 0x10) + 0x48 + lVar11) = (int)plVar4[-0x43];
                      *(undefined8 *)(*(long *)(param_3 + 0x10) + 0x40 + lVar11) = *puVar9;
                    }
                  }
                }
                plVar4 = (long *)*plVar4;
              } while ((long *)(lVar7 + 0x618) != plVar4);
            }
            *(uint *)(param_3 + 4) = uVar1;
          }
          FUN_00234bf0(local_89c8);
          FUN_00121ff0(&local_89d0);
          return iVar6;
        }
        if (DAT_01216a78 < 2) {
          return 0x14;
        }
        fVar12 = (float)FUN_002917b0(&DAT_01216a60);
        lVar7 = syscall(0xba);
        FUN_002340f0((double)(fVar12 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR"
                     ,lVar7,"dmal/common/common_utilization.c",0x33e);
        return 0x14;
      }
      if (DAT_01216a78 < 2) {
        return iVar6;
      }
      fVar12 = (float)FUN_002917b0(&DAT_01216a60);
      lVar7 = syscall(0xba);
      uVar14 = 0x338;
      uVar10 = 0x338;
      dVar13 = (double)(fVar12 * DAT_00298548);
    }
    else {
      if (DAT_01216a78 < 2) {
        return iVar6;
      }
      fVar12 = (float)FUN_002917b0(&DAT_01216a60);
      lVar7 = syscall(0xba);
      uVar14 = 0x324;
      uVar10 = 0x324;
      dVar13 = (double)(fVar12 * DAT_00298548);
    }
  }
  else {
    lVar8 = *(long *)(param_2 + 0x256d8);
    if ((lVar8 == 0) ||
       ((*(long *)(lVar8 + 0x28) == 0 ||
        (pcVar3 = *(code **)(*(long *)(lVar8 + 0x28) + 0x48), pcVar3 == (code *)0x0)))) {
      iVar6 = 3;
    }
    else {
      iVar6 = (*pcVar3)(lVar8,param_2);
      if (iVar6 == 0) goto LAB_001bd8b0;
    }
    if (DAT_01216a78 < 2) {
      return iVar6;
    }
    fVar12 = (float)FUN_002917b0(&DAT_01216a60);
    lVar7 = syscall(0xba);
    uVar14 = 0x310;
    uVar10 = 0x310;
    dVar13 = (double)(fVar12 * DAT_00298548);
  }
  FUN_002340f0(dVar13,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar7,
               "dmal/common/common_utilization.c",uVar10,"cDeviceGetVgpuProcessesUtilizationInfo",
               uVar14,iVar6);
  return iVar6;
}


// ===== 001bdd70 FUN_001bdd70 =====

undefined8 FUN_001bdd70(ulong param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 0x100) {
    return 0x9f;
  }
  if (param_1 < 0x101) {
    if (param_1 < 0x21) {
      uVar1 = 0xffffffff;
      if (param_1 != 0) {
        switch(param_1) {
        case 1:
          return 0x6f;
        case 2:
          return 0x70;
        default:
          return 0xffffffff;
        case 4:
          return 0x21;
        case 8:
          return 0x25;
        case 0x10:
          return 0x77;
        case 0x20:
          return 0x7d;
        }
      }
    }
    else {
      uVar1 = 0x7b;
      if (param_1 != 0x40) {
        uVar1 = 0xffffffff;
        if (param_1 == 0x80) {
          uVar1 = 0x76;
        }
        return uVar1;
      }
    }
  }
  else {
    if (param_1 == 0x1000) {
      return 0x9b;
    }
    if (param_1 < 0x1001) {
      uVar1 = 0xbc;
      if (param_1 != 0x400) {
        if (param_1 == 0x800) {
          return 0xbd;
        }
        uVar1 = 0xffffffff;
        if (param_1 == 0x200) {
          uVar1 = 0xbb;
        }
        return uVar1;
      }
    }
    else {
      uVar1 = 0xbf;
      if (param_1 != 0x4000) {
        if (param_1 != 0x8000) {
          uVar1 = 0xffffffff;
          if (param_1 == 0x2000) {
            uVar1 = 0x9c;
          }
          return uVar1;
        }
        uVar1 = 0xc0;
      }
    }
  }
  return uVar1;
}


// ===== 001bded0 FUN_001bded0 =====

long FUN_001bded0(uint param_1)

{
  long lVar1;
  
  if (0xc0 < param_1) {
switchD_001bdef3_caseD_71:
    return 0;
  }
  if (param_1 < 0x6f) {
    lVar1 = 4;
    if (param_1 != 0x21) {
      return (ulong)(param_1 == 0x25) << 3;
    }
  }
  else {
    switch(param_1) {
    case 0x6f:
      lVar1 = 1;
      break;
    case 0x70:
      return 2;
    default:
      goto switchD_001bdef3_caseD_71;
    case 0x76:
      return 0x80;
    case 0x77:
      return 0x10;
    case 0x7b:
      return 0x40;
    case 0x7d:
      return 0x20;
    case 0x9b:
      return 0x1000;
    case 0x9c:
      return 0x2000;
    case 0x9f:
      return 0x100;
    case 0xbb:
      return 0x200;
    case 0xbc:
      return 0x400;
    case 0xbd:
      return 0x800;
    case 0xbf:
      return 0x4000;
    case 0xc0:
      return 0x8000;
    }
  }
  return lVar1;
}


// ===== 001be000 FUN_001be000 =====

undefined8
FUN_001be000(long param_1,undefined4 param_2,long param_3,uint param_4,uint *param_5,ulong param_6)

{
  uint uVar1;
  int iVar2;
  undefined8 *puVar3;
  long *plVar4;
  undefined8 local_44;
  undefined4 local_3c;
  
  *param_5 = 0;
  while( true ) {
    local_44 = 0;
    local_3c = 0;
    iVar2 = (**(code **)(param_1 + 0x20))(param_2,param_2,0x502,&local_44,0xc);
    if (iVar2 == 0x57) {
      return 0;
    }
    if ((int)local_44 != 3) break;
    puVar3 = (undefined8 *)((ulong)*param_5 * 0x10 + param_3);
    if ((char)local_3c == '\x01') {
      if ((param_6 & 2) != 0) {
        *puVar3 = 2;
      }
    }
    else if (((char)local_3c == '\0') && ((param_6 & 1) != 0)) {
      *puVar3 = 1;
    }
    uVar1 = *param_5;
    plVar4 = (long *)((ulong)uVar1 * 0x10 + param_3);
    if (*plVar4 != 0) {
      *(undefined4 *)(plVar4 + 1) = local_44._4_4_;
      uVar1 = *param_5;
    }
    *param_5 = uVar1 + 1;
    if (param_4 <= uVar1 + 1) {
      return 0;
    }
  }
  return 2;
}


// ===== 001be100 FUN_001be100 =====

ulong FUN_001be100(long param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  code *pcVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  ulong extraout_RDX;
  ulong extraout_RDX_00;
  ulong uVar12;
  ulong extraout_RDX_01;
  ulong extraout_RDX_02;
  ulong extraout_RDX_03;
  ulong uVar13;
  ulong uVar14;
  float fVar15;
  ulong local_58 [5];
  
  do {
    iVar7 = FUN_00291820(&DAT_012169a4,1,0);
  } while (iVar7 != 0);
  uVar12 = extraout_RDX;
  if (param_2 != (int *)0x0) {
    if (*param_2 != 0x1000018) {
      uVar14 = 0x19;
      goto LAB_001be21e;
    }
    uVar14 = *(ulong *)(param_2 + 2);
    lVar10 = *(long *)(param_2 + 4);
    if ((uVar14 != 0) && (lVar10 != 0)) {
      lVar3 = *(long *)(param_1 + 0x10);
      bVar5 = false;
      do {
        uVar9 = *(ulong *)(lVar10 + 0x30);
        uVar13 = 1L << bVar5;
        if (((uVar13 & uVar9) == 0) && ((uVar14 & uVar13) != 0)) {
          iVar7 = *(int *)(lVar10 + 0x2c);
          if (iVar7 != 0) {
LAB_001be268:
            uVar12 = (ulong)(iVar7 + 1U);
            *(uint *)(lVar10 + 0x2c) = iVar7 + 1U;
            *(ulong *)(lVar10 + 0x30) = uVar9 | uVar13;
            goto LAB_001be276;
          }
          if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x20) != 0)) &&
             (pcVar4 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0x80), pcVar4 != (code *)0x0)) {
            (*pcVar4)(DAT_012164a0,lVar10 + 0x28);
          }
          uVar6 = DAT_0038088c;
          uVar1 = *(undefined4 *)(lVar10 + 0x28);
          uVar8 = (**(code **)(lVar3 + 0x30))(DAT_0038088c,DAT_0038088c,0);
          uVar12 = extraout_RDX_00;
          if (0x66 < uVar8) {
switchD_001be212_caseD_1:
            uVar14 = 999;
            goto LAB_001be2c8;
          }
          uVar12 = (long)&switchD_001be212::switchdataD_002b5cec +
                   (long)(int)(&switchD_001be212::switchdataD_002b5cec)[uVar8];
          switch(uVar8) {
          case 0:
            local_58[1] = 0x1000000300000079;
            local_58[0] = (ulong)uVar6;
            local_58[2] = lVar10 + 0x24;
            iVar7 = (**(code **)(lVar3 + 0x10))(0,uVar6,uVar6,uVar1,5,local_58,0x18);
            if (iVar7 != 0) {
              if (1 < DAT_01216a78) {
                fVar15 = (float)FUN_002917b0(&DAT_01216a60);
                lVar11 = syscall(0xba);
                FUN_002340f0((double)(fVar15 * DAT_00298548),
                             "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n","ERROR",lVar11,
                             "dmal/common/common_event.c",0xae);
              }
              (**(code **)(lVar3 + 0x38))(uVar6,uVar6,*(undefined4 *)(lVar10 + 0x24));
              uVar12 = extraout_RDX_02;
              if (iVar7 - 3U < 100) {
                if (*(ushort *)(&DAT_002b6340 + (ulong)(iVar7 - 3U) * 2) == 0) goto LAB_001be5a3;
                uVar14 = (ulong)*(ushort *)(&DAT_002b6340 + (ulong)(iVar7 - 3U) * 2);
              }
              else {
                uVar14 = 999;
              }
              break;
            }
LAB_001be5a3:
            local_58[0] = 0x200000003;
            uVar8 = (**(code **)(lVar3 + 0x20))(uVar6,uVar6,0x501,local_58,8);
            if (uVar8 < 0x67) {
              if (*(ushort *)(&DAT_002b6420 + (ulong)uVar8 * 2) == 0) {
                iVar7 = *(int *)(lVar10 + 0x2c);
                uVar9 = *(ulong *)(lVar10 + 0x30);
                goto LAB_001be268;
              }
              uVar14 = (ulong)*(ushort *)(&DAT_002b6420 + (ulong)uVar8 * 2);
            }
            else {
              uVar14 = 999;
            }
            uVar2 = *(undefined4 *)(lVar10 + 0x24);
            (**(code **)(lVar3 + 0x28))(uVar6,uVar6,uVar1);
            (**(code **)(lVar3 + 0x38))(uVar6,uVar6,uVar2);
            uVar12 = extraout_RDX_03;
            goto LAB_001be33e;
          default:
            goto switchD_001be212_caseD_1;
          case 3:
          case 0x66:
            uVar14 = 10;
            break;
          case 0xf:
            uVar14 = (ulong)uVar8;
            break;
          case 0x17:
          case 99:
            uVar14 = 0x13;
            break;
          case 0x1a:
            uVar14 = 0x17;
            break;
          case 0x1b:
            uVar14 = 4;
            break;
          case 0x1f:
          case 0x3b:
          case 0x54:
            uVar14 = 2;
            break;
          case 0x51:
            uVar14 = 0x14;
            break;
          case 0x55:
            uVar14 = 0x1b;
            break;
          case 0x56:
            uVar14 = 3;
            break;
          case 0x59:
            uVar14 = 0x11;
            break;
          case 0x62:
            uVar14 = 0x10;
          }
LAB_001be2c8:
          if (1 < DAT_01216a78) {
            fVar15 = (float)FUN_002917b0(&DAT_01216a60);
            lVar10 = syscall(0xba);
            FUN_002340f0((double)(fVar15 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar10,
                         "dmal/common/common_event.c",0x10b,"cSystemEventInitHelper",0x10b,uVar14);
            uVar12 = extraout_RDX_01;
LAB_001be33e:
            if (1 < DAT_01216a78) {
              fVar15 = (float)FUN_002917b0(&DAT_01216a60);
              lVar10 = syscall(0xba);
              uVar12 = uVar14;
              FUN_002340f0((double)(fVar15 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar10,
                           "dmal/common/common_event.c",0x529,"cSystemRegisterEventsLocked",0x529);
            }
          }
          goto LAB_001be21e;
        }
LAB_001be276:
        if (bVar5) goto LAB_001be290;
        bVar5 = true;
      } while( true );
    }
  }
  uVar14 = 2;
LAB_001be21e:
  FUN_00291830(&DAT_012169a4,0,uVar12);
  return uVar14;
LAB_001be290:
  uVar14 = 0;
  goto LAB_001be21e;
}


// ===== 001be650 FUN_001be650 =====

ulong FUN_001be650(long param_1,int param_2,uint *param_3,long *param_4,uint param_5)

{
  uint *puVar1;
  char *pcVar2;
  long *plVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  int *piVar8;
  long lVar9;
  long lVar10;
  ulong uVar11;
  ulong uVar12;
  uint uVar13;
  uint uVar14;
  undefined1 *puVar15;
  nfds_t __nfds;
  ulong uVar16;
  nfds_t nVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  float fVar20;
  ulong auStack_c0 [5];
  pollfd pStack_98;
  undefined1 *local_90;
  undefined1 *local_88;
  int local_7c;
  long *local_78;
  ulong local_70;
  undefined1 *local_68;
  undefined1 *local_60;
  int local_50;
  undefined1 local_4c [4];
  undefined1 local_48 [16];
  
  local_7c = param_2;
  local_78 = param_4;
  do {
    auStack_c0[4] = 0x1be68f;
    iVar5 = FUN_00291820(&DAT_012169a8,1,0);
  } while (iVar5 != 0);
  local_48 = (undefined1  [16])0x0;
  uVar7 = (ulong)*param_3 * 8 + 0xf & 0xfffffffffffffff0;
  lVar10 = -uVar7;
  local_70 = *(ulong *)(param_1 + 0x10);
  if (DAT_01214898 == 0) {
    __nfds = 0;
    uVar6 = 0;
    local_60 = (undefined1 *)&pStack_98;
  }
  else {
    uVar13 = param_3[1];
    uVar14 = uVar13 + DAT_01214898;
    nVar17 = 0;
    local_60 = (undefined1 *)&pStack_98;
    do {
      uVar16 = (ulong)uVar13 % (ulong)DAT_01214898;
      pcVar2 = *(char **)(param_3 + uVar16 * 0x16 + 2);
      __nfds = nVar17;
      if ((pcVar2 != (char *)0x0) &&
         ((*pcVar2 == '\x01' ||
          ((((*(int *)(pcVar2 + 0x14) != 0 && (*(int *)(pcVar2 + 0x1c) == 0)) &&
            (*(int *)(pcVar2 + 0x10) != 0)) && (*(long *)(pcVar2 + 0x20) != 0)))))) {
        uVar6 = param_3[uVar16 * 0x16 + 4];
        __nfds = (nfds_t)((int)nVar17 + 1);
        puVar1 = (uint *)((long)&pStack_98 + nVar17 * 8 + lVar10);
        *(uint **)((long)&pStack_98 + nVar17 * 8 + uVar7 * -2) = param_3 + uVar16 * 0x16 + 2;
        *puVar1 = uVar6;
        puVar1[1] = 3;
      }
      uVar6 = (uint)__nfds;
      uVar13 = uVar13 + 1;
      nVar17 = __nfds;
    } while (uVar14 != uVar13);
  }
  puVar15 = (undefined1 *)((long)&pStack_98 + uVar7 * -2);
  if (4 < DAT_01216a78) {
    local_88 = (undefined1 *)((long)&pStack_98 + uVar7 * -2);
    *(undefined8 *)((long)auStack_c0 + uVar7 * -2 + 0x20) = 0x1be910;
    uVar18 = FUN_002917b0(&DAT_01216a60);
    local_68 = (undefined1 *)CONCAT44(local_68._4_4_,uVar18);
    *(undefined8 *)((long)auStack_c0 + uVar7 * -2 + 0x20) = 0x1be921;
    lVar9 = syscall(0xba);
    fVar20 = local_68._0_4_ * DAT_00298548;
    *(ulong *)((long)auStack_c0 + uVar7 * -2 + 0x18) = (ulong)param_5;
    *(undefined8 *)((long)auStack_c0 + uVar7 * -2 + 0x10) = 0x1be963;
    FUN_002340f0((double)fVar20,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %d\n","DEBUG",lVar9,
                 "dmal/common/common_event.c",0x35d,uVar6);
    puVar15 = local_88;
  }
  local_68 = puVar15;
  *(undefined8 *)((long)auStack_c0 + uVar7 * -2 + 0x20) = 0x1be77d;
  uVar13 = poll((pollfd *)((long)&pStack_98 + lVar10),__nfds,param_5);
  *(undefined8 *)((long)auStack_c0 + uVar7 * -2 + 0x20) = 0x1be785;
  piVar8 = __errno_location();
  puVar15 = local_68;
  iVar5 = *piVar8;
  if (4 < DAT_01216a78) {
    local_90 = local_68;
    local_88 = (undefined1 *)CONCAT44(local_88._4_4_,*piVar8);
    *(undefined8 *)((long)auStack_c0 + uVar7 * -2 + 0x20) = 0x1be887;
    fVar20 = (float)FUN_002917b0(&DAT_01216a60);
    local_68._0_4_ = fVar20;
    *(undefined8 *)((long)auStack_c0 + uVar7 * -2 + 0x20) = 0x1be898;
    lVar9 = syscall(0xba);
    uVar18 = local_88._0_4_;
    fVar20 = local_68._0_4_ * DAT_00298548;
    *(ulong *)((long)auStack_c0 + uVar7 * -2 + 0x18) = (ulong)local_88 & 0xffffffff;
    local_68 = (undefined1 *)CONCAT44(local_68._4_4_,uVar18);
    *(ulong *)((long)auStack_c0 + uVar7 * -2 + 0x10) = (ulong)uVar13;
    *(ulong *)((long)auStack_c0 + uVar7 * -2 + 8) = (ulong)param_5;
    *(undefined8 *)((long)auStack_c0 + uVar7 * -2) = 0x1be8e6;
    FUN_002340f0((double)fVar20,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %d %d %d\n","DEBUG",lVar9,
                 "dmal/common/common_event.c",0x360,uVar6);
    puVar15 = local_90;
    iVar5 = (int)local_68._0_4_;
  }
  uVar16 = 10;
  if (uVar13 == 0xffffffff) {
    if (iVar5 == 4) goto switchD_001be82d_caseD_f;
  }
  else {
    if (uVar13 == 0) goto switchD_001be82d_caseD_f;
    param_3[1] = param_3[1] + 1;
    uVar18 = DAT_0038088c;
    if (uVar6 != 0) {
      uVar16 = 0;
      do {
        if (*(short *)((long)&pStack_98 + uVar16 * 8 + lVar10 + 6) != 0) {
          plVar3 = *(long **)(puVar15 + (uVar16 & 0xffffffff) * 8);
          if (4 < DAT_01216a78) {
            uVar6 = *(uint *)(plVar3 + 1);
            *(undefined8 *)((long)auStack_c0 + uVar7 * -2 + 0x20) = 0x1beace;
            uVar19 = FUN_002917b0(&DAT_01216a60);
            local_68 = (undefined1 *)CONCAT44(local_68._4_4_,uVar19);
            *(undefined8 *)((long)auStack_c0 + uVar7 * -2 + 0x20) = 0x1beadf;
            lVar10 = syscall(0xba);
            fVar20 = local_68._0_4_ * DAT_00298548;
            *(ulong *)((long)auStack_c0 + uVar7 * -2 + 0x18) = (ulong)uVar6;
            *(undefined8 *)((long)auStack_c0 + uVar7 * -2 + 0x10) = 0x1beb21;
            FUN_002340f0((double)fVar20,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %d\n","DEBUG",lVar10,
                         "dmal/common/common_event.c",0x37f,uVar18);
          }
          lVar10 = plVar3[1];
          pcVar4 = *(code **)(local_70 + 0x48);
          *(undefined8 *)((long)auStack_c0 + uVar7 * -2 + 0x20) = 0x1be803;
          uVar6 = (*pcVar4)(DAT_0038088c,(int)lVar10,local_48,0);
          uVar18 = DAT_0038088c;
          uVar16 = (ulong)uVar6;
          if (4 < DAT_01216a78) {
            local_70 = CONCAT44(local_70._4_4_,(int)plVar3[1]);
            *(undefined8 *)((long)auStack_c0 + uVar7 * -2 + 0x20) = 0x1be9b3;
            uVar19 = FUN_002917b0(&DAT_01216a60);
            local_68 = (undefined1 *)CONCAT44(local_68._4_4_,uVar19);
            *(undefined8 *)((long)auStack_c0 + uVar7 * -2 + 0x20) = 0x1be9c4;
            lVar10 = syscall(0xba);
            fVar20 = local_68._0_4_;
            *(ulong *)((long)auStack_c0 + uVar7 * -2 + 0x20) = uVar16;
            *(ulong *)((long)auStack_c0 + uVar7 * -2 + 0x18) = local_70 & 0xffffffff;
            *(undefined8 *)((long)auStack_c0 + uVar7 * -2 + 0x10) = 0x1bea06;
            FUN_002340f0((double)(fVar20 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %d %x\n","DEBUG",lVar10,
                         "dmal/common/common_event.c",0x381,uVar18);
            if (4 < DAT_01216a78) {
              uVar18 = local_48._0_4_;
              local_90 = (undefined1 *)CONCAT44(local_90._4_4_,(uint)(ushort)local_48._12_2_);
              local_88 = (undefined1 *)CONCAT44(local_88._4_4_,local_48._8_4_);
              local_70 = CONCAT44(local_70._4_4_,local_48._4_4_);
              *(undefined8 *)((long)auStack_c0 + uVar7 * -2 + 0x20) = 0x1bea3c;
              uVar19 = FUN_002917b0(&DAT_01216a60);
              local_68 = (undefined1 *)CONCAT44(local_68._4_4_,uVar19);
              *(undefined8 *)((long)auStack_c0 + uVar7 * -2 + 0x20) = 0x1bea4d;
              lVar10 = syscall(0xba);
              fVar20 = DAT_00298548 * local_68._0_4_;
              *(ulong *)((long)auStack_c0 + uVar7 * -2 + 0x18) = (ulong)local_90 & 0xffffffff;
              *(ulong *)((long)auStack_c0 + uVar7 * -2 + 0x10) = (ulong)local_88 & 0xffffffff;
              *(ulong *)((long)auStack_c0 + uVar7 * -2 + 8) = local_70 & 0xffffffff;
              *(undefined8 *)((long)auStack_c0 + uVar7 * -2) = 0x1beaa2;
              FUN_002340f0((double)fVar20,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %d %d %d\n","DEBUG"
                           ,lVar10,"dmal/common/common_event.c",899,uVar18);
            }
          }
          switch(uVar6) {
          case 0:
            uVar18 = local_48._4_4_;
            *(undefined8 *)((long)auStack_c0 + uVar7 * -2 + 0x20) = 0x1beb56;
            uVar11 = FUN_001bded0(uVar18);
            local_78[1] = uVar11;
            if (uVar11 != 0xffffffffffffffff) {
              uVar12 = plVar3[2];
              if ((uVar11 & uVar12) != 0) {
                uVar12 = 0;
                if (uVar11 == 8) {
                  uVar12 = (ulong)(uint)local_48._8_4_;
                }
                local_78[2] = uVar12;
                lVar10 = *plVar3;
                *local_78 = lVar10;
                if (local_7c == 2) {
                  local_78[3] = -1;
                  lVar9 = *(long *)(lVar10 + 0x256d8);
                  if (((lVar9 != 0) && (*(undefined8 **)(lVar9 + 0x30) != (undefined8 *)0x0)) &&
                     (pcVar4 = (code *)**(undefined8 **)(lVar9 + 0x30), pcVar4 != (code *)0x0)) {
                    *(undefined8 *)((long)auStack_c0 + uVar7 * -2 + 0x20) = 0x1bebd6;
                    iVar5 = (*pcVar4)(lVar9,lVar10,&local_50,local_4c);
                    if ((iVar5 == 0) && (local_50 == 1)) {
                      uVar6 = (uint)(ushort)local_48._12_2_ % 0xf;
                      *(uint *)(local_78 + 3) = (ushort)local_48._12_2_ / 0xf;
                      if (7 < uVar6) {
                        uVar6 = 0xffffffff;
                      }
                      *(uint *)((long)local_78 + 0x1c) = uVar6;
                      if (0xe0 < (ushort)local_48._12_2_) {
                        *(undefined4 *)(local_78 + 3) = 0xffffffff;
                        uVar16 = 0;
                      }
                    }
                  }
                }
                goto switchD_001be82d_caseD_f;
              }
              if (1 < DAT_01216a78) {
                *(undefined8 *)((long)auStack_c0 + uVar7 * -2 + 0x20) = 0x1bec99;
                uVar18 = FUN_002917b0(&DAT_01216a60);
                local_68 = (undefined1 *)CONCAT44(local_68._4_4_,uVar18);
                *(undefined8 *)((long)auStack_c0 + uVar7 * -2 + 0x20) = 0x1becaa;
                lVar10 = syscall(0xba);
                fVar20 = local_68._0_4_ * DAT_00298548;
                *(ulong *)((long)auStack_c0 + uVar7 * -2 + 0x18) = uVar12;
                *(undefined8 *)((long)auStack_c0 + uVar7 * -2 + 0x10) = 0x1becec;
                FUN_002340f0((double)fVar20,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%llu %llu\n","ERROR"
                             ,lVar10,"dmal/common/common_event.c",0x392,uVar11);
              }
            }
            break;
          case 3:
          case 0x66:
            uVar16 = 10;
          case 0xf:
            goto switchD_001be82d_caseD_f;
          case 0x17:
          case 99:
            uVar16 = 0x13;
            goto switchD_001be82d_caseD_f;
          case 0x1a:
            uVar16 = 0x17;
            goto switchD_001be82d_caseD_f;
          case 0x1b:
            uVar16 = 4;
            goto switchD_001be82d_caseD_f;
          case 0x1f:
          case 0x3b:
          case 0x54:
            uVar16 = 2;
            goto switchD_001be82d_caseD_f;
          case 0x51:
            uVar16 = 0x14;
            goto switchD_001be82d_caseD_f;
          case 0x55:
            uVar16 = 0x1b;
            goto switchD_001be82d_caseD_f;
          case 0x56:
            uVar16 = 3;
            goto switchD_001be82d_caseD_f;
          case 0x59:
            uVar16 = 0x11;
            goto switchD_001be82d_caseD_f;
          case 0x62:
            uVar16 = 0x10;
            goto switchD_001be82d_caseD_f;
          }
          break;
        }
        uVar16 = uVar16 + 1;
      } while (uVar6 != uVar16);
    }
  }
  uVar16 = 999;
switchD_001be82d_caseD_f:
  *(undefined8 *)(local_60 + -8) = 0x1be854;
  FUN_00291830(&DAT_012169a8,0);
  return uVar16;
}


// ===== 001bed00 FUN_001bed00 =====

undefined4 FUN_001bed00(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  
  do {
    iVar1 = FUN_00291820(&DAT_012169a8,1,0);
  } while (iVar1 != 0);
  pvVar2 = calloc(0xb08,1);
  *param_2 = pvVar2;
  uVar3 = 0;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0x14;
  }
  FUN_00291830(&DAT_012169a8,0);
  return uVar3;
}


// ===== 001bed80 FUN_001bed80 =====

undefined4 FUN_001bed80(undefined8 param_1,int *param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  
  do {
    iVar1 = FUN_00291820(&DAT_012169a4,1,0);
  } while (iVar1 != 0);
  if (param_2 == (int *)0x0) {
    uVar3 = 2;
  }
  else if (*param_2 == 0x1000010) {
    pvVar2 = calloc(0x38,1);
    *(void **)(param_2 + 2) = pvVar2;
    uVar3 = 0;
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0x14;
    }
  }
  else {
    uVar3 = 0x19;
  }
  FUN_00291830(&DAT_012169a4,0);
  return uVar3;
}


// ===== 001bee20 FUN_001bee20 =====

undefined4 FUN_001bee20(long param_1,int *param_2)

{
  int *piVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  long lVar7;
  long lVar8;
  int iVar9;
  float fVar10;
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  
  do {
    iVar3 = FUN_00291820(&DAT_012169a4,1,0);
  } while (iVar3 != 0);
  if (param_2 != (int *)0x0) {
    uVar5 = 0x19;
    if (*param_2 != 0x1000020) goto LAB_001bef18;
    piVar1 = *(int **)(param_2 + 2);
    lVar7 = *(long *)(param_2 + 4);
    iVar3 = param_2[6];
    if ((piVar1 != (int *)0x0 && lVar7 != 0) && (iVar3 != 0)) {
      iVar4 = param_2[1];
      uVar2 = *(undefined8 *)(param_1 + 0x10);
      local_58 = (undefined1  [16])0x0;
      local_48 = (undefined1  [16])0x0;
      if (iVar4 != 0) {
        iVar9 = 0;
        piVar6 = piVar1;
        do {
          if (*piVar6 != 0) {
            lVar8 = (long)iVar9;
            iVar9 = iVar9 + 1;
            *(int *)(local_58 + lVar8 * 8) = *piVar6;
            *(undefined4 *)(local_58 + lVar8 * 8 + 4) = 3;
          }
          piVar6 = piVar6 + 3;
        } while (piVar1 + 0xc != piVar6);
        iVar4 = poll((pollfd *)local_58,(long)iVar9,iVar4);
        if (iVar4 < 1) {
          uVar5 = 10;
          if ((iVar4 != 0) && (uVar5 = 999, 1 < DAT_01216a78)) {
            fVar10 = (float)FUN_002917b0(&DAT_01216a60);
            lVar7 = syscall(0xba);
            FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",
                         "ERROR",lVar7,"dmal/common/common_event.c",0x8d,iVar4);
          }
          goto LAB_001bef18;
        }
      }
      uVar5 = FUN_001be000(uVar2,DAT_0038088c,lVar7,iVar3,param_2 + 7,*(undefined8 *)(piVar1 + 0xc))
      ;
      goto LAB_001bef18;
    }
  }
  uVar5 = 2;
LAB_001bef18:
  FUN_00291830(&DAT_012169a4,0);
  return uVar5;
}


// ===== 001befe0 FUN_001befe0 =====

undefined4 FUN_001befe0(long param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  long lVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  
  do {
    iVar5 = FUN_00291820(&DAT_012169a4,1,0);
  } while (iVar5 != 0);
  if (param_2 == (int *)0x0) {
    uVar7 = 2;
  }
  else if (*param_2 == 0x1000010) {
    puVar2 = *(undefined4 **)(param_2 + 2);
    uVar7 = 0;
    if (puVar2 != (undefined4 *)0x0) {
      lVar3 = *(long *)(param_1 + 0x10);
      puVar6 = puVar2;
      do {
        uVar4 = DAT_0038088c;
        if (puVar6[2] != 0) {
          uVar1 = *puVar6;
          (**(code **)(lVar3 + 0x28))(DAT_0038088c,DAT_0038088c,puVar6[1]);
          (**(code **)(lVar3 + 0x38))(uVar4,uVar4,uVar1);
          puVar6[1] = 0;
          *puVar6 = 0;
          puVar6[2] = 0;
        }
        puVar6 = puVar6 + 3;
      } while (puVar6 != puVar2 + 0xc);
      *(undefined8 *)(puVar2 + 0xc) = 0;
      free(*(void **)(param_2 + 2));
    }
  }
  else {
    uVar7 = 0x19;
  }
  FUN_00291830(&DAT_012169a4,0);
  return uVar7;
}


// ===== 001bf0f0 FUN_001bf0f0 =====

int FUN_001bf0f0(long param_1,long *param_2)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  if (*(int *)(param_1 + 0x258b8) == 0) {
    do {
      iVar1 = FUN_00291820(param_1 + 0x258bc,1,0);
    } while (iVar1 != 0);
    if (*(int *)(param_1 + 0x258b8) == 0) {
      *(undefined4 *)(param_1 + 0x25860) = 0;
      *(undefined4 *)(param_1 + 0x258c0) = 0;
      *(undefined4 *)(param_1 + 0x258b8) = 1;
    }
    FUN_00291830(param_1 + 0x258bc,0);
  }
  iVar1 = *(int *)(param_1 + 0x258c0);
  if (iVar1 == 0) {
    *param_2 = param_1 + 0x25860;
  }
  else if (1 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar2,"dmal/common/common_event.c",0x2a6,"cCachedAllocateNotifierHandle",
                 0x2a6,iVar1);
    return iVar1;
  }
  return iVar1;
}


// ===== 001bf210 FUN_001bf210 =====

undefined4 FUN_001bf210(long param_1,void *param_2)

{
  char *pcVar1;
  long lVar2;
  long lVar3;
  code *pcVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  long lVar9;
  uint uVar10;
  ulong uVar11;
  long lVar12;
  int *piVar13;
  uint uVar14;
  float fVar15;
  undefined4 local_90;
  undefined4 local_64;
  long local_60;
  undefined1 local_58 [16];
  undefined4 local_48;
  
  do {
    iVar6 = FUN_00291820(&DAT_012169a8,1,0);
  } while (iVar6 != 0);
  uVar14 = 0;
  if (DAT_01214898 != 0) {
    do {
      lVar12 = (ulong)uVar14 * 0x58;
      pcVar1 = *(char **)((long)param_2 + lVar12 + 8);
      if ((pcVar1 != (char *)0x0) &&
         ((*pcVar1 == '\x01' ||
          ((((*(int *)(pcVar1 + 0x14) != 0 && (*(int *)(pcVar1 + 0x1c) == 0)) &&
            (*(int *)(pcVar1 + 0x10) != 0)) && (*(long *)(pcVar1 + 0x20) != 0)))))) {
        iVar6 = FUN_001bf0f0(&DAT_00380898 + (ulong)uVar14 * 0x74a00,&local_60);
        if (iVar6 != 0) {
          local_90 = 999;
          goto LAB_001bf459;
        }
        piVar13 = (int *)((long)param_2 + lVar12 + 0x20);
        uVar11 = 0;
        do {
          while( true ) {
            lVar9 = local_60;
            iVar6 = *piVar13;
            if (iVar6 == 0) break;
            lVar2 = *(long *)((long)param_2 + lVar12 + 8);
            lVar3 = *(long *)(lVar2 + 0x256d8);
            if (((lVar3 != 0) && (*(undefined8 **)(lVar3 + 0x50) != (undefined8 *)0x0)) &&
               (pcVar4 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar4 != (code *)0x0)) {
              lVar5 = *(long *)(param_1 + 0x10);
              iVar7 = (*pcVar4)(lVar3,lVar2,0x2080,&local_64);
              if (iVar7 == 0) {
                lVar2 = lVar9 + 0x10;
                do {
                  iVar7 = FUN_00291820(lVar2,1,0);
                } while (iVar7 != 0);
                lVar9 = lVar9 + uVar11 * 4;
                if (*(int *)(lVar9 + 0x14) == 1) {
                  local_58 = (undefined1  [16])0x0;
                  local_48 = 0;
                  uVar8 = FUN_001bdd70(1L << ((byte)uVar11 & 0x3f));
                  local_58._0_4_ = uVar8;
                  iVar7 = FUN_0019c780(lVar5,DAT_0038088c,local_64);
                  if (iVar7 == 0) {
                    *(int *)(lVar9 + 0x14) = *(int *)(lVar9 + 0x14) + -1;
                  }
                  else if (1 < DAT_01216a78) {
                    fVar15 = (float)FUN_002917b0(&DAT_01216a60);
                    lVar9 = syscall(0xba);
                    FUN_002340f0((double)(fVar15 * DAT_00298548),
                                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar9,
                                 "dmal/common/common_event.c",0x24e);
                  }
                }
                FUN_00291830(lVar2,0);
                (**(code **)(lVar5 + 0x28))(DAT_0038088c,local_64,iVar6);
              }
            }
            uVar10 = (int)uVar11 + 1;
            uVar11 = (ulong)uVar10;
            *piVar13 = 0;
            piVar13 = piVar13 + 1;
            if (uVar10 == 0x10) goto LAB_001bf3d6;
          }
          uVar10 = (int)uVar11 + 1;
          uVar11 = (ulong)uVar10;
          piVar13 = piVar13 + 1;
        } while (uVar10 != 0x10);
LAB_001bf3d6:
        lVar9 = *(long *)((long)param_2 + lVar12 + 8);
        lVar2 = *(long *)(lVar9 + 0x256d8);
        if (((lVar2 != 0) && (*(undefined8 **)(lVar2 + 0x50) != (undefined8 *)0x0)) &&
           (pcVar4 = (code *)**(undefined8 **)(lVar2 + 0x50), pcVar4 != (code *)0x0)) {
          uVar8 = *(undefined4 *)((long)param_2 + lVar12 + 0x10);
          lVar12 = *(long *)(param_1 + 0x10);
          iVar6 = (*pcVar4)(lVar2,lVar9,0x80,local_58);
          if (iVar6 == 0) {
            (**(code **)(lVar12 + 0x38))(DAT_0038088c,local_58._0_4_,uVar8);
          }
        }
      }
      uVar14 = uVar14 + 1;
    } while (uVar14 < DAT_01214898);
  }
  free(param_2);
  local_90 = 0;
LAB_001bf459:
  FUN_00291830(&DAT_012169a8,0);
  return local_90;
}


// ===== 001bf580 FUN_001bf580 =====

uint FUN_001bf580(uint *param_1,long param_2,ulong param_3,uint *param_4)

{
  ushort uVar1;
  uint uVar2;
  long lVar3;
  code *pcVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  uint *extraout_RDX;
  uint *puVar13;
  undefined8 extraout_RDX_00;
  uint *extraout_RDX_01;
  uint *extraout_RDX_02;
  uint *extraout_RDX_03;
  uint *extraout_RDX_04;
  uint *extraout_RDX_05;
  uint *extraout_RDX_06;
  uint *extraout_RDX_07;
  uint *extraout_RDX_08;
  uint *puVar14;
  uint *extraout_RDX_09;
  uint *extraout_RDX_10;
  uint *extraout_RDX_11;
  ulong uVar15;
  undefined8 uVar16;
  uint uVar17;
  ulong uVar18;
  uint *puVar19;
  float fVar20;
  double dVar21;
  undefined1 auVar22 [16];
  undefined8 uVar23;
  uint local_7c;
  uint local_68;
  undefined4 local_64;
  long local_60;
  int local_58 [10];
  
  do {
    iVar6 = FUN_00291820(&DAT_012169a8,1,0);
  } while (iVar6 != 0);
  uVar7 = FUN_001bf0f0(param_2,&local_60);
  local_7c = uVar7;
  if (uVar7 == 0) {
    puVar13 = (uint *)(ulong)*(uint *)(param_2 + 4);
    puVar9 = param_4 + (long)puVar13 * 0x16;
    if (*(long *)(puVar9 + 2) != 0) {
LAB_001bf60e:
      uVar18 = 0;
      puVar14 = param_4;
      puVar19 = puVar9;
      do {
        uVar15 = 1L << ((byte)uVar18 & 0x3f);
        uVar12 = *(ulong *)(param_4 + (long)puVar13 * 0x16 + 6);
        if (((uVar15 & uVar12) == 0) && ((param_3 & uVar15) != 0)) {
          iVar6 = FUN_001bdd70(uVar15);
          if (iVar6 == 0x21) {
            auVar22._8_8_ = extraout_RDX_00;
            auVar22._0_8_ = 0x14;
          }
          else {
            auVar22 = FUN_001bded0(iVar6);
            puVar14 = auVar22._8_8_;
            if (iVar6 == -1) {
              local_7c = 999;
              break;
            }
          }
          lVar10 = local_60;
          puVar14 = auVar22._8_8_;
          if ((uVar12 & auVar22._0_8_) != 0) goto LAB_001bf638;
          uVar17 = puVar9[4];
          lVar3 = *(long *)(param_1 + 4);
          puVar14 = param_1;
          local_68 = uVar17;
          if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x20) != 0)) &&
             (pcVar4 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0x80), pcVar4 != (code *)0x0)) {
            (*pcVar4)(DAT_012164a0,puVar19 + 8);
            puVar14 = extraout_RDX_01;
          }
          lVar11 = *(long *)(param_2 + 0x256d8);
          if (((lVar11 == 0) || (*(undefined8 **)(lVar11 + 0x50) == (undefined8 *)0x0)) ||
             (pcVar4 = (code *)**(undefined8 **)(lVar11 + 0x50), pcVar4 == (code *)0x0)) {
            local_7c = 3;
LAB_001bf896:
            if (1 < DAT_01216a78) {
              fVar20 = (float)FUN_002917b0(&DAT_01216a60);
              lVar10 = syscall(0xba);
              FUN_002340f0((double)(fVar20 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar10,
                           "dmal/common/common_event.c",0x1fe,"cDeviceCreateNvEvent",0x1fe,local_7c)
              ;
              puVar14 = extraout_RDX_05;
            }
          }
          else {
            local_7c = (*pcVar4)(lVar11,param_2,0x2080,&local_64);
            uVar5 = local_64;
            puVar14 = extraout_RDX_02;
            if (local_7c != 0) goto LAB_001bf896;
            if (4 < DAT_01216a78) {
              uVar2 = puVar19[8];
              fVar20 = (float)FUN_002917b0(&DAT_01216a60);
              lVar11 = syscall(0xba);
              FUN_002340f0((double)(fVar20 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %x %x %p\n","DEBUG",lVar11,
                           "dmal/common/common_event.c",0x200,uVar5,uVar2,iVar6,&local_68);
            }
            iVar8 = (**(code **)(lVar3 + 0x40))
                              (DAT_0038088c,local_64,puVar19[8],0x79,iVar6,&local_68);
            uVar5 = local_64;
            puVar14 = extraout_RDX_03;
            if (4 < DAT_01216a78) {
              uVar2 = puVar19[8];
              fVar20 = (float)FUN_002917b0(&DAT_01216a60);
              lVar11 = syscall(0xba);
              FUN_002340f0((double)(fVar20 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %x %x %p %x\n","DEBUG",lVar11,
                           "dmal/common/common_event.c",0x209,uVar5,uVar2,iVar6,&local_68,iVar8);
              puVar14 = extraout_RDX_09;
            }
            if (iVar8 == 0) {
              if (uVar17 == local_68) {
                lVar11 = lVar10 + 0x10;
                do {
                  iVar8 = FUN_00291820(lVar11,1,0);
                } while (iVar8 != 0);
                lVar10 = lVar10 + uVar18 * 4;
                if (*(int *)(lVar10 + 0x14) == 0) {
                  uVar16 = 0;
                  local_58[2] = 0;
                  local_58[3] = 0;
                  local_58[4] = 0;
                  local_58[1] = 2;
                  local_58[0] = iVar6;
                  iVar6 = FUN_0019c780(lVar3,DAT_0038088c,local_64,0x20800301,local_58,0x14);
                  if (iVar6 != 0) {
                    (**(code **)(lVar3 + 0x28))(DAT_0038088c,local_64,puVar19[8],uVar16);
                    if (1 < DAT_01216a78) {
                      fVar20 = (float)FUN_002917b0(&DAT_01216a60);
                      lVar10 = syscall(0xba);
                      FUN_002340f0((double)(fVar20 * DAT_00298548),
                                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar10,
                                   "dmal/common/common_event.c",0x226);
                    }
                    FUN_00291830(lVar11,0);
                    puVar14 = extraout_RDX_06;
                    if (99 < iVar6 - 3U) goto LAB_001bfe04;
                    uVar1 = *(ushort *)(&DAT_002b6340 + (ulong)(iVar6 - 3U) * 2);
                    goto LAB_001bf82c;
                  }
                }
                *(int *)(lVar10 + 0x14) = *(int *)(lVar10 + 0x14) + 1;
                FUN_00291830(lVar11,0);
                uVar12 = *(ulong *)(param_4 + (long)puVar13 * 0x16 + 6);
                puVar14 = extraout_RDX_07;
LAB_001bf638:
                *(ulong *)(param_4 + (long)puVar13 * 0x16 + 6) = uVar15 | uVar12;
                goto LAB_001bf63f;
              }
              (**(code **)(lVar3 + 0x28))
                        (DAT_0038088c,local_64,param_4[uVar18 + (long)puVar13 * 0x16 + 8]);
              local_7c = 999;
              puVar14 = extraout_RDX_10;
            }
            else {
              if (1 < DAT_01216a78) {
                fVar20 = (float)FUN_002917b0(&DAT_01216a60);
                lVar10 = syscall(0xba);
                FUN_002340f0((double)(fVar20 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n"
                             ,"ERROR",lVar10,"dmal/common/common_event.c",0x20e);
                puVar14 = extraout_RDX_04;
              }
              if (iVar8 - 3U < 100) {
                uVar1 = *(ushort *)(&DAT_002b6340 + (ulong)(iVar8 - 3U) * 2);
LAB_001bf82c:
                local_7c = (uint)uVar1;
                if (local_7c == 0) {
                  uVar12 = *(ulong *)(param_4 + (long)puVar13 * 0x16 + 6);
                  goto LAB_001bf638;
                }
              }
              else {
LAB_001bfe04:
                local_7c = 999;
              }
            }
          }
          if (1 < DAT_01216a78) {
            fVar20 = (float)FUN_002917b0(&DAT_01216a60);
            lVar10 = syscall(0xba);
            puVar14 = (uint *)(ulong)local_7c;
            uVar16 = 0x2e8;
            uVar23 = 0x2e8;
            dVar21 = (double)(fVar20 * DAT_00298548);
            goto LAB_001bfb37;
          }
          break;
        }
LAB_001bf63f:
        uVar17 = (int)uVar18 + 1;
        uVar18 = (ulong)uVar17;
        puVar19 = puVar19 + 1;
        local_7c = uVar7;
      } while (uVar17 != 0x10);
      goto LAB_001bf850;
    }
    *(long *)(puVar9 + 2) = param_2;
    lVar10 = *(long *)(param_2 + 0x256d8);
    if (((lVar10 == 0) || (*(undefined8 **)(lVar10 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar4 = (code *)**(undefined8 **)(lVar10 + 0x50), pcVar4 == (code *)0x0)) {
      local_7c = 3;
      puVar14 = puVar13;
LAB_001bfc42:
      if (1 < DAT_01216a78) {
        fVar20 = (float)FUN_002917b0(&DAT_01216a60);
        lVar10 = syscall(0xba);
        FUN_002340f0((double)(fVar20 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n"
                     ,"ERROR",lVar10,"dmal/common/common_event.c",0x1a7,"cDeviceCreateOsEvent",0x1a7
                     ,local_7c);
        puVar14 = extraout_RDX_11;
      }
    }
    else {
      lVar3 = *(long *)(param_1 + 4);
      local_7c = (*pcVar4)(lVar10,param_2,0x80,local_58);
      iVar6 = local_58[0];
      puVar14 = extraout_RDX_08;
      if (local_7c != 0) goto LAB_001bfc42;
      if (4 < DAT_01216a78) {
        fVar20 = (float)FUN_002917b0(&DAT_01216a60);
        lVar10 = syscall(0xba);
        FUN_002340f0((double)(fVar20 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n",
                     "DEBUG",lVar10,"dmal/common/common_event.c",0x1a9,iVar6);
      }
      local_7c = (**(code **)(lVar3 + 0x30))
                           (DAT_0038088c,local_58[0],0,param_4 + (long)puVar13 * 0x16 + 4);
      iVar6 = local_58[0];
      if (4 < DAT_01216a78) {
        uVar17 = puVar9[4];
        fVar20 = (float)FUN_002917b0(&DAT_01216a60);
        lVar10 = syscall(0xba);
        FUN_002340f0((double)(fVar20 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %x %d\n"
                     ,"DEBUG",lVar10,"dmal/common/common_event.c",0x1ab,iVar6,local_7c,uVar17);
      }
      puVar14 = &switchD_001bfc3a::switchdataD_002b6198;
      switch(local_7c) {
      case 0:
        *param_4 = *param_4 + 1;
        goto LAB_001bf60e;
      default:
        local_7c = 999;
        break;
      case 3:
      case 0x66:
        local_7c = 10;
        break;
      case 0xf:
        break;
      case 0x17:
      case 99:
        local_7c = 0x13;
        break;
      case 0x1a:
        local_7c = 0x17;
        break;
      case 0x1b:
        local_7c = 4;
        break;
      case 0x1f:
      case 0x3b:
      case 0x54:
        local_7c = 2;
        break;
      case 0x51:
        local_7c = 0x14;
        break;
      case 0x55:
        local_7c = 0x1b;
        break;
      case 0x56:
        local_7c = 3;
        break;
      case 0x59:
        local_7c = 0x11;
        break;
      case 0x62:
        local_7c = 0x10;
      }
    }
    if (DAT_01216a78 < 2) goto LAB_001bf850;
    fVar20 = (float)FUN_002917b0(&DAT_01216a60);
    lVar10 = syscall(0xba);
    puVar14 = (uint *)(ulong)local_7c;
    uVar16 = 0x2c5;
    uVar23 = 0x2c5;
    dVar21 = (double)(fVar20 * DAT_00298548);
  }
  else {
    puVar14 = extraout_RDX;
    if (DAT_01216a78 < 2) goto LAB_001bf850;
    fVar20 = (float)FUN_002917b0(&DAT_01216a60);
    lVar10 = syscall(0xba);
    puVar14 = (uint *)(ulong)uVar7;
    uVar16 = 699;
    uVar23 = 699;
    dVar21 = (double)(fVar20 * DAT_00298548);
  }
LAB_001bfb37:
  FUN_002340f0(dVar21,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar10,
               "dmal/common/common_event.c",uVar16,"cDeviceRegisterEventsLocked",uVar23);
LAB_001bf850:
  FUN_00291830(&DAT_012169a8,0,puVar14);
  return local_7c;
}


// ===== 001c00a0 FUN_001c00a0 =====

undefined2 FUN_001c00a0(long param_1,long param_2)

{
  uint uVar1;
  undefined2 uVar2;
  undefined4 local_10;
  undefined1 local_c;
  undefined1 local_b;
  undefined2 local_a;
  
  local_a = 0;
  local_10 = *(undefined4 *)(param_2 + 0x10);
  local_c = (undefined1)*(undefined4 *)(param_2 + 0x14);
  local_b = (undefined1)*(undefined4 *)(param_2 + 0x18);
  uVar1 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0x27a,&local_10,8);
  uVar2 = 999;
  if (uVar1 < 0x67) {
    uVar2 = *(undefined2 *)(&DAT_002b6c40 + (ulong)uVar1 * 2);
  }
  return uVar2;
}


// ===== 001c0110 FUN_001c0110 =====

ulong FUN_001c0110(long param_1,long param_2,int *param_3)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  int *piVar5;
  int *piVar6;
  int local_338 [96];
  int local_1b8 [98];
  
  piVar6 = local_1b8;
  piVar5 = local_338;
  for (lVar3 = 0x30; lVar3 != 0; lVar3 = lVar3 + -1) {
    piVar5[0] = 0;
    piVar5[1] = 0;
    piVar5 = piVar5 + 2;
  }
  piVar5 = piVar6;
  for (lVar3 = 0x30; lVar3 != 0; lVar3 = lVar3 + -1) {
    piVar5[0] = 0;
    piVar5[1] = 0;
    piVar5 = piVar5 + 2;
  }
  uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0x214,local_338,
                       0x180,0);
  switch(uVar2 & 0xffffffff) {
  case 0:
    uVar4 = 0;
    do {
      iVar1 = local_338[uVar4];
      if (iVar1 == -1) {
        return 6;
      }
      *piVar6 = iVar1;
      uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0x21b,piVar6,
                           0xc,0);
      switch(uVar2 & 0xffffffff) {
      case 0:
        if (((*(int *)(param_2 + 0x10) == piVar6[1]) &&
            (*(uint *)(param_2 + 0x14) == (uint)*(ushort *)(piVar6 + 2))) &&
           (*(uint *)(param_2 + 0x18) == (uint)*(ushort *)((long)piVar6 + 10))) {
          *param_3 = local_1b8[(uVar4 & 0xffffffff) * 3];
          return uVar2;
        }
        uVar4 = uVar4 + 1;
        piVar6 = piVar6 + 3;
        if (uVar4 == 0x20) {
          return 6;
        }
        break;
      default:
        goto switchD_001c019a_caseD_1;
      case 3:
      case 0x66:
        goto switchD_001c019a_caseD_3;
      case 0xf:
        goto switchD_001c019a_caseD_f;
      case 0x17:
      case 99:
        goto switchD_001c019a_caseD_17;
      case 0x1a:
        goto switchD_001c019a_caseD_1a;
      case 0x1b:
        goto switchD_001c019a_caseD_1b;
      case 0x1f:
      case 0x3b:
      case 0x54:
        goto switchD_001c019a_caseD_1f;
      case 0x51:
        goto switchD_001c019a_caseD_51;
      case 0x55:
        goto switchD_001c019a_caseD_55;
      case 0x56:
        goto switchD_001c019a_caseD_56;
      case 0x59:
        goto switchD_001c019a_caseD_59;
      case 0x62:
        goto switchD_001c019a_caseD_62;
      }
    } while( true );
  default:
switchD_001c019a_caseD_1:
    uVar2 = 999;
    break;
  case 3:
  case 0x66:
switchD_001c019a_caseD_3:
    uVar2 = 10;
    break;
  case 0xf:
    break;
  case 0x17:
  case 99:
switchD_001c019a_caseD_17:
    uVar2 = 0x13;
    break;
  case 0x1a:
switchD_001c019a_caseD_1a:
    uVar2 = 0x17;
    break;
  case 0x1b:
switchD_001c019a_caseD_1b:
    uVar2 = 4;
    break;
  case 0x1f:
  case 0x3b:
  case 0x54:
switchD_001c019a_caseD_1f:
    uVar2 = 2;
    break;
  case 0x51:
switchD_001c019a_caseD_51:
    uVar2 = 0x14;
    break;
  case 0x55:
switchD_001c019a_caseD_55:
    uVar2 = 0x1b;
    break;
  case 0x56:
switchD_001c019a_caseD_56:
    uVar2 = 3;
    break;
  case 0x59:
switchD_001c019a_caseD_59:
    uVar2 = 0x11;
    break;
  case 0x62:
switchD_001c019a_caseD_62:
    uVar2 = 0x10;
  }
switchD_001c019a_caseD_f:
  return uVar2;
}


// ===== 001c0350 FUN_001c0350 =====

int FUN_001c0350(long param_1,undefined8 param_2,uint *param_3,undefined4 *param_4)

{
  int iVar1;
  long lVar2;
  float fVar3;
  undefined1 local_38 [4];
  undefined8 local_34;
  undefined4 local_2c;
  
  local_34 = 0;
  local_2c = 0;
  iVar1 = FUN_001c0110(param_1,param_2,local_38);
  if (iVar1 == 0) {
    iVar1 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0x279,&local_34,
                         0xc,0);
    switch(iVar1) {
    case 0:
      *param_3 = (uint)(local_34._4_4_ == 1);
      *param_4 = local_2c;
      break;
    default:
      iVar1 = 999;
      break;
    case 3:
    case 0x66:
      iVar1 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      iVar1 = 0x13;
      break;
    case 0x1a:
      iVar1 = 0x17;
      break;
    case 0x1b:
      iVar1 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
      iVar1 = 2;
      break;
    case 0x51:
      iVar1 = 0x14;
      break;
    case 0x55:
      iVar1 = 0x1b;
      break;
    case 0x56:
      iVar1 = 3;
      break;
    case 0x59:
      iVar1 = 0x11;
      break;
    case 0x62:
      iVar1 = 0x10;
    }
  }
  else if (1 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar2,"dmal/common/common_zpi.c",0x70,"cDeviceQueryDrainState",0x70,iVar1);
    return iVar1;
  }
  return iVar1;
}


// ===== 001c0520 FUN_001c0520 =====

uint FUN_001c0520(long param_1,undefined8 param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  int *piVar5;
  undefined8 uVar6;
  int *piVar7;
  float fVar8;
  int local_150;
  int local_14c;
  undefined1 local_148 [4];
  undefined8 local_144;
  int local_13c;
  int local_138 [32];
  int local_b8 [34];
  
  piVar7 = local_138;
  piVar5 = piVar7;
  for (lVar4 = 0x10; lVar4 != 0; lVar4 = lVar4 + -1) {
    piVar5[0] = 0;
    piVar5[1] = 0;
    piVar5 = piVar5 + 2;
  }
  piVar5 = local_b8;
  for (lVar4 = 0x10; lVar4 != 0; lVar4 = lVar4 + -1) {
    piVar5[0] = 0;
    piVar5[1] = 0;
    piVar5 = piVar5 + 2;
  }
  local_144 = 0;
  local_13c = 0;
  uVar2 = FUN_001c0110(param_1,param_2,&local_14c);
  if (uVar2 == 0) {
    FUN_001c0350(param_1,param_2,&local_150,local_148);
    iVar1 = local_14c;
    if (local_150 == 1) {
      local_b8[1] = 0xffffffff;
      local_b8[0] = local_14c;
      FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0x216,local_b8,0x80,0);
      uVar6 = 0;
      uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0x201,piVar7,
                           0x80);
      switch(uVar2) {
      case 0:
        do {
          if (*piVar7 == iVar1) {
            uVar2 = 0x13;
            if (DAT_01216a78 < 2) {
              return 0x13;
            }
            fVar8 = (float)FUN_002917b0(&DAT_01216a60,uVar6);
            lVar4 = syscall(0xba);
            uVar6 = 0xb4;
            fVar8 = fVar8 * DAT_00298548;
            goto LAB_001c06b7;
          }
          piVar7 = piVar7 + 1;
        } while (piVar7 != local_b8);
        if (param_3 == 1) {
          local_13c = (param_4 == 1) + 1 + (uint)(param_4 == 1);
          local_144 = CONCAT44(1,iVar1);
          uVar2 = 999;
          uVar3 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0x278,
                               &local_144,0xc,0);
          if (uVar3 < 0x67) {
            uVar2 = (uint)*(ushort *)(&DAT_002b6c40 + (ulong)uVar3 * 2);
          }
        }
        break;
      default:
        uVar2 = 999;
        break;
      case 3:
      case 0x66:
        uVar2 = 10;
        break;
      case 0xf:
        break;
      case 0x17:
      case 99:
        uVar2 = 0x13;
        break;
      case 0x1a:
        uVar2 = 0x17;
        break;
      case 0x1b:
        uVar2 = 4;
        break;
      case 0x1f:
      case 0x3b:
      case 0x54:
        uVar2 = 2;
        break;
      case 0x51:
        uVar2 = 0x14;
        break;
      case 0x55:
        uVar2 = 0x1b;
        break;
      case 0x56:
        uVar2 = 3;
        break;
      case 0x59:
        uVar2 = 0x11;
        break;
      case 0x62:
        uVar2 = 0x10;
      }
    }
    else {
      uVar2 = 3;
      if (1 < DAT_01216a78) {
        fVar8 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        uVar6 = 0x97;
        fVar8 = fVar8 * DAT_00298548;
LAB_001c06b7:
        FUN_002340f0((double)fVar8,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","ERROR",lVar4,
                     "dmal/common/common_zpi.c",uVar6,local_14c);
      }
    }
  }
  else if (1 < DAT_01216a78) {
    fVar8 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar8 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_zpi.c",0x91,"cDeviceRmDetachGpu",0x91,uVar2);
  }
  return uVar2;
}


// ===== 001c0900 FUN_001c0900 =====

uint FUN_001c0900(long param_1,undefined8 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  float fVar4;
  undefined4 local_38;
  ulong local_34;
  undefined4 local_2c;
  
  local_34 = 0;
  local_2c = 0;
  uVar1 = FUN_001c0110(param_1,param_2,&local_38);
  if (uVar1 == 0) {
    local_2c = 0;
    uVar1 = 999;
    local_34 = (ulong)CONCAT14(param_3 == 1,local_38);
    uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0x278,&local_34,
                         0xc,0);
    if (uVar2 < 0x67) {
      return (uint)*(ushort *)(&DAT_002b6c40 + (ulong)uVar2 * 2);
    }
  }
  else if (1 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar3,"dmal/common/common_zpi.c",0x55,"cDeviceModifyDrainState",0x55,uVar1)
    ;
    return uVar1;
  }
  return uVar1;
}


// ===== 001c0a40 FUN_001c0a40 =====

int FUN_001c0a40(undefined8 param_1,long param_2,undefined4 param_3,long *param_4,long *param_5)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  
  lVar4 = 0;
  do {
    *param_4 = lVar4;
    *param_5 = lVar4 + 1;
    lVar1 = *(long *)(param_2 + 0x256d8);
    if (((lVar1 == 0) || (*(long *)(lVar1 + 0x140) == 0)) ||
       (pcVar2 = *(code **)(*(long *)(lVar1 + 0x140) + 0xa8), pcVar2 == (code *)0x0)) {
      return 3;
    }
    iVar3 = (*pcVar2)(lVar1,param_2,param_3,*param_4);
    if (iVar3 != 0x3eb) {
      return iVar3;
    }
    lVar4 = lVar4 + 2;
  } while (lVar4 != 0x80);
  if (4 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                 lVar4,"dmal/common/common_ecc.c",0x7e6);
  }
  return 0x3ec;
}


// ===== 001c0b60 FUN_001c0b60 =====

int FUN_001c0b60(long param_1,long param_2,int *param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  undefined2 local_2e;
  undefined4 local_2c [3];
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  local_2e = 0;
  if (param_3 == (int *)0x0) {
switchD_001c0cc9_caseD_1f:
    return 2;
  }
  iVar3 = 0x19;
  if (*param_3 == 0x100000c) {
    lVar4 = *(long *)(param_2 + 0x256d8);
    if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
      iVar3 = 3;
    }
    else {
      iVar3 = (*pcVar2)(lVar4,param_2,0x2080,local_2c);
      if (iVar3 == 0) {
        iVar3 = FUN_0019c780(uVar1,DAT_0038088c,local_2c[0],0x20803404,&local_2e,2,0);
        switch(iVar3) {
        case 0:
          param_3[1] = (uint)local_2e._1_1_;
          param_3[2] = (uint)(byte)local_2e;
          return iVar3;
        default:
          return 999;
        case 3:
        case 0x66:
          return 10;
        case 0xf:
          return iVar3;
        case 0x17:
        case 99:
          return 0x13;
        case 0x1a:
          return 0x17;
        case 0x1b:
          return 4;
        case 0x1f:
        case 0x3b:
        case 0x54:
          goto switchD_001c0cc9_caseD_1f;
        case 0x51:
          return 0x14;
        case 0x55:
          return 0x1b;
        case 0x56:
          return 3;
        case 0x59:
          return 0x11;
        case 0x62:
          return 0x10;
        }
      }
    }
    if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"dmal/common/common_ecc.c",0xda2,"cDeviceGetEccRepairStatus",0xda2,
                   iVar3);
      return iVar3;
    }
  }
  return iVar3;
}


// ===== 001c0d70 FUN_001c0d70 =====

uint FUN_001c0d70(long param_1,long param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  uint uVar3;
  long lVar4;
  float fVar5;
  undefined4 local_24;
  undefined8 local_20;
  
  local_20 = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
    uVar3 = 3;
  }
  else {
    uVar3 = (*pcVar2)(lVar4,param_2,0x208f,&local_24);
    if (uVar3 == 0) {
      local_20 = CONCAT44(local_20._4_4_,0xc);
      uVar3 = FUN_0019c780(uVar1,DAT_0038088c,local_24,0x208f0515,&local_20,8,0);
      if (0x66 < uVar3) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002b9ae0 + (ulong)uVar3 * 2);
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar3;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar4,"dmal/common/common_ecc.c",0xbbc,"cDeviceClearRemappedRows",0xbbc,uVar3
              );
  return uVar3;
}


// ===== 001c0ef0 FUN_001c0ef0 =====

uint FUN_001c0ef0(long param_1,long param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  uint uVar3;
  long lVar4;
  float fVar5;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
    uVar3 = 3;
  }
  else {
    uVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_1c);
    if (uVar3 == 0) {
      local_20 = 0x14;
      uVar3 = FUN_0019c780(uVar1,DAT_0038088c,local_1c,0x20801326,&local_20,4,0);
      if (0x66 < uVar3) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002b9ae0 + (ulong)uVar3 * 2);
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar3;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar4,"dmal/common/common_ecc.c",0xba5,"cDeviceClearDynamicPageRetirement",
               0xba5,uVar3);
  return uVar3;
}


// ===== 001c1070 FUN_001c1070 =====

int FUN_001c1070(long param_1,long param_2,long param_3)

{
  long *plVar1;
  code *pcVar2;
  long lVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  long *plVar9;
  int iVar10;
  float fVar11;
  undefined4 local_6c0;
  uint local_6bc;
  long local_6b8 [209];
  
  plVar9 = local_6b8;
  for (lVar8 = 0xd0; lVar8 != 0; lVar8 = lVar8 + -1) {
    *plVar9 = 0;
    plVar9 = plVar9 + 1;
  }
  lVar8 = *(long *)(param_2 + 0x256d8);
  if (((lVar8 == 0) || (*(undefined8 **)(lVar8 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar8 + 0x50), pcVar2 == (code *)0x0)) {
    iVar5 = 3;
  }
  else {
    iVar5 = (*pcVar2)(lVar8,param_2,0x2080,&local_6c0);
    if (iVar5 == 0) {
      iVar5 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_6c0,0x2080012f,
                           local_6b8,0x680,0);
      switch(iVar5) {
      case 0:
        plVar9 = local_6b8 + 1;
        iVar10 = iVar5;
        break;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar5;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
      do {
        lVar8 = *(long *)(param_2 + 0x256d8);
        if (((lVar8 != 0) && (*(long *)(lVar8 + 0x140) != 0)) &&
           (pcVar2 = *(code **)(*(long *)(lVar8 + 0x140) + 0x100), pcVar2 != (code *)0x0)) {
          (*pcVar2)(lVar8,param_2,iVar10,&local_6bc);
        }
        uVar4 = local_6bc;
        if (local_6bc != 8) {
          if (DAT_01216a78 < 5) {
            uVar6 = (ulong)local_6bc;
            if (*(int *)(param_2 + uVar6 * 8 + 0x4ac) != 0) {
LAB_001c12eb:
              plVar1 = (long *)(param_3 + 8 + uVar6 * 0x10);
              *plVar1 = *plVar1 + plVar9[2];
              goto LAB_001c12fb;
            }
LAB_001c1260:
            if (*(int *)(param_2 + uVar6 * 8 + 0x4b0) == 0) goto LAB_001c1278;
          }
          else {
            lVar8 = *plVar9;
            lVar3 = plVar9[2];
            fVar11 = (float)FUN_002917b0(&DAT_01216a60);
            lVar7 = syscall(0xba);
            FUN_002340f0((double)(fVar11 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u %llu %llu\n","DEBUG",lVar7,
                         "dmal/common/common_ecc.c",0x23e,iVar10,uVar4,lVar3,lVar8);
            uVar4 = local_6bc;
            uVar6 = (ulong)local_6bc;
            if (*(int *)(param_2 + uVar6 * 8 + 0x4ac) != 0) goto LAB_001c12eb;
            if (DAT_01216a78 < 5) goto LAB_001c1260;
            fVar11 = (float)FUN_002917b0(&DAT_01216a60);
            lVar8 = syscall(0xba);
            FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n",
                         "DEBUG",lVar8,"dmal/common/common_ecc.c",0x24a,uVar4);
            uVar6 = (ulong)local_6bc;
LAB_001c12fb:
            uVar4 = local_6bc;
            if (*(int *)(param_2 + uVar6 * 8 + 0x4b0) == 0) {
              if (4 < DAT_01216a78) {
                fVar11 = (float)FUN_002917b0(&DAT_01216a60);
                lVar8 = syscall(0xba);
                FUN_002340f0((double)(fVar11 * DAT_00298548),
                             "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",lVar8,
                             "dmal/common/common_ecc.c",0x254,uVar4);
              }
              goto LAB_001c1278;
            }
          }
          plVar1 = (long *)(param_3 + 0x10 + uVar6 * 0x10);
          *plVar1 = *plVar1 + *plVar9;
        }
LAB_001c1278:
        iVar10 = iVar10 + 1;
        plVar9 = plVar9 + 5;
        if (iVar10 == 0x29) {
          return iVar5;
        }
      } while( true );
    }
  }
  if (1 < DAT_01216a78) {
    fVar11 = (float)FUN_002917b0(&DAT_01216a60);
    lVar8 = syscall(0xba);
    FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar8,"dmal/common/common_ecc.c",0x22c,
                 "cVgpuGetDetailedVolatileEccErrorsTuringOrAbove",0x22c,iVar5);
  }
  return iVar5;
}


// ===== 001c1500 FUN_001c1500 =====

int FUN_001c1500(long param_1,long param_2,long param_3)

{
  long *plVar1;
  code *pcVar2;
  long lVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  long *plVar9;
  int iVar10;
  float fVar11;
  undefined4 local_6c0;
  uint local_6bc;
  long local_6b8 [209];
  
  plVar9 = local_6b8;
  for (lVar8 = 0xd0; lVar8 != 0; lVar8 = lVar8 + -1) {
    *plVar9 = 0;
    plVar9 = plVar9 + 1;
  }
  lVar8 = *(long *)(param_2 + 0x256d8);
  if (((lVar8 == 0) || (*(undefined8 **)(lVar8 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar8 + 0x50), pcVar2 == (code *)0x0)) {
    iVar5 = 3;
  }
  else {
    iVar5 = (*pcVar2)(lVar8,param_2,0x2080,&local_6c0);
    if (iVar5 == 0) {
      iVar5 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_6c0,0x2080012f,
                           local_6b8,0x680,0);
      switch(iVar5) {
      case 0:
        plVar9 = local_6b8 + 2;
        iVar10 = iVar5;
        break;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar5;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
      do {
        lVar8 = *(long *)(param_2 + 0x256d8);
        if (((lVar8 != 0) && (*(long *)(lVar8 + 0x140) != 0)) &&
           (pcVar2 = *(code **)(*(long *)(lVar8 + 0x140) + 0x100), pcVar2 != (code *)0x0)) {
          (*pcVar2)(lVar8,param_2,iVar10,&local_6bc);
        }
        uVar4 = local_6bc;
        if (local_6bc != 8) {
          if (DAT_01216a78 < 5) {
            uVar6 = (ulong)local_6bc;
            if (*(int *)(param_2 + uVar6 * 8 + 0x4ac) != 0) {
LAB_001c177e:
              plVar1 = (long *)(param_3 + 0x88 + uVar6 * 0x10);
              *plVar1 = *plVar1 + plVar9[2];
              goto LAB_001c1791;
            }
LAB_001c16f0:
            if (*(int *)(param_2 + uVar6 * 8 + 0x4b0) == 0) goto LAB_001c170b;
          }
          else {
            lVar8 = *plVar9;
            lVar3 = plVar9[2];
            fVar11 = (float)FUN_002917b0(&DAT_01216a60);
            lVar7 = syscall(0xba);
            FUN_002340f0((double)(fVar11 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u %llu %llu\n","DEBUG",lVar7,
                         "dmal/common/common_ecc.c",0x27a,iVar10,uVar4,lVar3,lVar8);
            uVar4 = local_6bc;
            uVar6 = (ulong)local_6bc;
            if (*(int *)(param_2 + uVar6 * 8 + 0x4ac) != 0) goto LAB_001c177e;
            if (DAT_01216a78 < 5) goto LAB_001c16f0;
            fVar11 = (float)FUN_002917b0(&DAT_01216a60);
            lVar8 = syscall(0xba);
            FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n",
                         "DEBUG",lVar8,"dmal/common/common_ecc.c",0x286,uVar4);
            uVar6 = (ulong)local_6bc;
LAB_001c1791:
            uVar4 = local_6bc;
            if (*(int *)(param_2 + uVar6 * 8 + 0x4b0) == 0) {
              if (4 < DAT_01216a78) {
                fVar11 = (float)FUN_002917b0(&DAT_01216a60);
                lVar8 = syscall(0xba);
                FUN_002340f0((double)(fVar11 * DAT_00298548),
                             "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",lVar8,
                             "dmal/common/common_ecc.c",0x290,uVar4);
              }
              goto LAB_001c170b;
            }
          }
          plVar1 = (long *)(param_3 + 0x90 + uVar6 * 0x10);
          *plVar1 = *plVar1 + *plVar9;
        }
LAB_001c170b:
        iVar10 = iVar10 + 1;
        plVar9 = plVar9 + 5;
        if (iVar10 == 0x29) {
          return iVar5;
        }
      } while( true );
    }
  }
  if (1 < DAT_01216a78) {
    fVar11 = (float)FUN_002917b0(&DAT_01216a60);
    lVar8 = syscall(0xba);
    FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar8,"dmal/common/common_ecc.c",0x268,
                 "cVgpuGetDetailedAggregateEccErrorsTuringOrAbove",0x268,iVar5);
  }
  return iVar5;
}


// ===== 001c19a0 FUN_001c19a0 =====

int FUN_001c19a0(long param_1,long param_2,long param_3)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  int iVar6;
  float fVar7;
  undefined4 local_6c0;
  uint local_6bc;
  long local_6b8 [209];
  
  plVar5 = local_6b8;
  for (lVar4 = 0xd0; lVar4 != 0; lVar4 = lVar4 + -1) {
    *plVar5 = 0;
    plVar5 = plVar5 + 1;
  }
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    iVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_6c0);
    if (iVar3 == 0) {
      iVar3 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_6c0,0x2080012f,
                           local_6b8,0x680,0);
      switch(iVar3) {
      case 0:
        plVar5 = local_6b8 + 1;
        iVar6 = iVar3;
        break;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar3;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
      do {
        lVar4 = *(long *)(param_2 + 0x256d8);
        if (((lVar4 != 0) && (*(long *)(lVar4 + 0x140) != 0)) &&
           (pcVar2 = *(code **)(*(long *)(lVar4 + 0x140) + 0x100), pcVar2 != (code *)0x0)) {
          (*pcVar2)(lVar4,param_2,iVar6,&local_6bc);
        }
        if (local_6bc != 8) {
          lVar4 = (ulong)local_6bc * 0x10 + param_3;
          plVar1 = (long *)(lVar4 + 8);
          *plVar1 = *plVar1 + plVar5[2];
          plVar1 = (long *)(lVar4 + 0x10);
          *plVar1 = *plVar1 + *plVar5;
        }
        iVar6 = iVar6 + 1;
        plVar5 = plVar5 + 5;
      } while (iVar6 != 0x29);
      return iVar3;
    }
  }
  if (1 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_ecc.c",0x1de,
                 "cVgpuGetDetailedVolatileEccErrorsPreTuring",0x1de,iVar3);
  }
  return iVar3;
}


// ===== 001c1c30 FUN_001c1c30 =====

int FUN_001c1c30(long param_1,long param_2,long param_3)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  int iVar6;
  float fVar7;
  undefined4 local_6c0;
  uint local_6bc;
  long local_6b8 [209];
  
  plVar5 = local_6b8;
  for (lVar4 = 0xd0; lVar4 != 0; lVar4 = lVar4 + -1) {
    *plVar5 = 0;
    plVar5 = plVar5 + 1;
  }
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    iVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_6c0);
    if (iVar3 == 0) {
      iVar3 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_6c0,0x2080012f,
                           local_6b8,0x680,0);
      switch(iVar3) {
      case 0:
        plVar5 = local_6b8 + 2;
        iVar6 = iVar3;
        break;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar3;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
      do {
        lVar4 = *(long *)(param_2 + 0x256d8);
        if (((lVar4 != 0) && (*(long *)(lVar4 + 0x140) != 0)) &&
           (pcVar2 = *(code **)(*(long *)(lVar4 + 0x140) + 0x100), pcVar2 != (code *)0x0)) {
          (*pcVar2)(lVar4,param_2,iVar6,&local_6bc);
        }
        if (local_6bc != 8) {
          lVar4 = (ulong)local_6bc * 0x10 + param_3;
          plVar1 = (long *)(lVar4 + 0x88);
          *plVar1 = *plVar1 + plVar5[2];
          plVar1 = (long *)(lVar4 + 0x90);
          *plVar1 = *plVar1 + *plVar5;
        }
        iVar6 = iVar6 + 1;
        plVar5 = plVar5 + 5;
      } while (iVar6 != 0x29);
      return iVar3;
    }
  }
  if (1 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_ecc.c",0x204,
                 "cVgpuGetDetailedAggregateEccErrorsPreTuring",0x204,iVar3);
  }
  return iVar3;
}


// ===== 001c1ec0 FUN_001c1ec0 =====

int FUN_001c1ec0(long param_1,long param_2,uint *param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  float fVar8;
  undefined8 uVar9;
  undefined4 local_850;
  int local_84c;
  undefined8 local_848 [2];
  int local_834 [3];
  undefined8 auStack_828 [252];
  int local_48;
  
  puVar7 = local_848;
  uVar6 = *(undefined8 *)(param_1 + 0x10);
  puVar5 = puVar7;
  for (lVar4 = 0x101; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  iVar3 = 3;
  if (*(char *)(param_2 + 0x580) != '\0') {
    return 3;
  }
  lVar4 = *(long *)(param_2 + 0x256d8);
  if ((((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
      (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) ||
     (iVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_850), iVar3 != 0)) {
    if (DAT_01216a78 < 2) {
      return iVar3;
    }
    fVar8 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    fVar8 = fVar8 * DAT_00298548;
    uVar9 = 0x600;
    uVar6 = 0x600;
LAB_001c201b:
    FUN_002340f0((double)fVar8,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
                 "dmal/common/common_ecc.c",uVar6,"cDeviceGetBlacklistedAddresses",uVar9,iVar3);
  }
  else {
    iVar3 = FUN_0019c780(uVar6,DAT_0038088c,local_850,0x20801322,puVar7,0x808,0);
    if (iVar3 == 0x56) {
      *(undefined1 *)(param_2 + 0x580) = 1;
      return 3;
    }
    switch(iVar3) {
    case 0:
      lVar4 = *(long *)(param_2 + 0x256d8);
      if (((lVar4 == 0) || (*(long *)(lVar4 + 0x140) == 0)) ||
         (pcVar2 = *(code **)(*(long *)(lVar4 + 0x140) + 8), pcVar2 == (code *)0x0)) {
        iVar3 = 3;
      }
      else {
        iVar3 = (*pcVar2)(lVar4,param_2,&local_84c);
        if (iVar3 == 0) {
          *param_3 = 0;
          if (local_48 == 0) {
            return 0;
          }
          do {
            if (*(int *)((long)puVar7 + 0x14) == 0) {
              uVar1 = *param_3;
              uVar6 = puVar7[1];
              if (local_84c != 0) {
                uVar6 = *puVar7;
              }
              *param_3 = uVar1 + 1;
              *(undefined8 *)(param_3 + (ulong)uVar1 * 2 + 2) = uVar6;
            }
            puVar7 = puVar7 + 4;
          } while (puVar7 != auStack_828 + (ulong)(local_48 - 1) * 4);
          return 0;
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar3;
      }
      fVar8 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      fVar8 = fVar8 * DAT_00298548;
      uVar9 = 0x610;
      uVar6 = 0x610;
      goto LAB_001c201b;
    default:
      iVar3 = 999;
      break;
    case 3:
    case 0x66:
      iVar3 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      iVar3 = 0x13;
      break;
    case 0x1a:
      iVar3 = 0x17;
      break;
    case 0x1b:
      iVar3 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
      iVar3 = 2;
      break;
    case 0x51:
      iVar3 = 0x14;
      break;
    case 0x55:
      iVar3 = 0x1b;
      break;
    case 0x59:
      iVar3 = 0x11;
      break;
    case 0x62:
      iVar3 = 0x10;
    }
  }
  return iVar3;
}


// ===== 001c21e0 FUN_001c21e0 =====

uint FUN_001c21e0(long param_1,long param_2,int param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  uint uVar3;
  long lVar4;
  float fVar5;
  undefined4 local_34;
  undefined8 local_30 [2];
  
  local_30[0] = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
    uVar3 = 3;
  }
  else {
    uVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_34);
    if (uVar3 == 0) {
      local_30[0] = CONCAT44(local_30[0]._4_4_,(param_3 == 1) + 1);
      uVar3 = FUN_0019c780(uVar1,DAT_0038088c,local_34,0x20800136,local_30,8);
      if (uVar3 == 0x57) {
        if (DAT_01216a78 < 3) {
          return 6;
        }
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                     "WARNING",lVar4,"dmal/common/common_ecc.c",0x558);
        return 6;
      }
      if (0x66 < uVar3) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002b9ae0 + (ulong)uVar3 * 2);
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar3;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar4,"dmal/common/common_ecc.c",0x54a,"cDeviceClearEccErrorCounts",0x54a,
               uVar3);
  return uVar3;
}


// ===== 001c23d0 FUN_001c23d0 =====

uint FUN_001c23d0(long param_1,long param_2,int param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  uint uVar3;
  long lVar4;
  float fVar5;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  if (param_3 != 0) {
    if (param_3 != 1) {
      return 999;
    }
    local_20 = 1;
  }
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
    uVar3 = 3;
  }
  else {
    uVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_1c);
    if (uVar3 == 0) {
      uVar3 = FUN_0019c780(uVar1,DAT_0038088c,local_1c,0x20800134,&local_20,4,0);
      if (0x66 < uVar3) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002b9ae0 + (ulong)uVar3 * 2);
    }
  }
  if (1 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_ecc.c",0x535,"cDeviceSetEccMode",0x535,uVar3);
  }
  return uVar3;
}


// ===== 001c2530 FUN_001c2530 =====

int FUN_001c2530(long param_1,long param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  float fVar6;
  undefined8 uVar7;
  char local_44d;
  undefined4 local_44c;
  undefined8 local_448;
  undefined4 local_440;
  undefined4 local_43c;
  undefined4 local_438;
  undefined4 local_434;
  undefined4 local_430;
  
  uVar5 = *(undefined8 *)(param_1 + 0x10);
  puVar4 = &local_448;
  for (lVar3 = 0x80; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined4 *)puVar4 = 0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(long *)(lVar3 + 0x30) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(lVar3 + 0x30) + 0x148), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,&local_44d);
    if (iVar2 == 0) {
      iVar2 = 3;
      if (local_44d != '\0') {
        return 3;
      }
      lVar3 = *(long *)(param_2 + 0x256d8);
      if (((lVar3 != 0) && (*(undefined8 **)(lVar3 + 0x50) != (undefined8 *)0x0)) &&
         ((pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 != (code *)0x0 &&
          (iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_44c), iVar2 == 0)))) {
        local_43c = 0x22;
        local_448 = 0x400000003;
        local_434 = 0x23;
        iVar2 = FUN_0019c780(uVar5,DAT_0038088c,local_44c,0x20801303,&local_448,0x404,0);
        switch(iVar2) {
        case 0:
          *param_3 = local_440;
          param_3[1] = local_438;
          param_3[2] = local_430;
          return iVar2;
        default:
          return 999;
        case 3:
        case 0x66:
          return 10;
        case 0xf:
          return iVar2;
        case 0x17:
        case 99:
          return 0x13;
        case 0x1a:
          return 0x17;
        case 0x1b:
          return 4;
        case 0x1f:
        case 0x3b:
        case 0x54:
          return 2;
        case 0x51:
          return 0x14;
        case 0x55:
          return 0x1b;
        case 0x56:
          return 3;
        case 0x59:
          return 0x11;
        case 0x62:
          return 0x10;
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar6 = fVar6 * DAT_00298548;
      uVar7 = 0x50c;
      uVar5 = 0x50c;
      goto LAB_001c26f3;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar6 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  fVar6 = fVar6 * DAT_00298548;
  uVar7 = 0x505;
  uVar5 = 0x505;
LAB_001c26f3:
  FUN_002340f0((double)fVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
               "dmal/common/common_ecc.c",uVar5,"cDeviceGetFBInfo",uVar7,iVar2);
  return iVar2;
}


// ===== 001c2820 FUN_001c2820 =====

int FUN_001c2820(long param_1,long param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  undefined4 local_34;
  undefined8 local_30;
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  lVar4 = *(long *)(param_2 + 0x256d8);
  local_30 = 0;
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    iVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_34);
    if (iVar3 == 0) {
      local_30._0_4_ = param_3;
      iVar3 = FUN_0019c780(uVar1,DAT_0038088c,local_34,0x20801234,&local_30,8,0);
      switch(iVar3) {
      case 0:
        *param_4 = local_30._4_4_;
        return iVar3;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar3;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar3;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar4,"dmal/common/common_ecc.c",0x4e9,"cDeviceGetGRTpcCount",0x4e9,iVar3);
  return iVar3;
}


// ===== 001c2a20 FUN_001c2a20 =====

int FUN_001c2a20(long param_1,long param_2,uint *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  undefined8 uVar5;
  float fVar6;
  undefined8 uVar7;
  char local_31;
  undefined4 local_30;
  uint local_2c;
  
  uVar5 = *(undefined8 *)(param_1 + 0x10);
  lVar3 = *(long *)(param_2 + 0x256d8);
  local_2c = 0;
  if (((lVar3 == 0) || (*(long *)(lVar3 + 0x30) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(lVar3 + 0x30) + 0x148), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,&local_31);
    if (iVar2 == 0) {
      iVar2 = 3;
      if (local_31 != '\0') {
        return 3;
      }
      lVar3 = *(long *)(param_2 + 0x256d8);
      if (((lVar3 != 0) && (*(undefined8 **)(lVar3 + 0x50) != (undefined8 *)0x0)) &&
         ((pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 != (code *)0x0 &&
          (iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_30), iVar2 == 0)))) {
        iVar2 = FUN_0019c780(uVar5,DAT_0038088c,local_30,0x20800137,&local_2c,4,0);
        switch(iVar2) {
        case 0:
          local_2c = local_2c - (local_2c >> 1 & 0x55555555);
          uVar4 = (local_2c & 0x33333333) + (local_2c >> 2 & 0x33333333);
          *param_3 = ((uVar4 >> 4) + uVar4 & 0xf0f0f0f) * 0x1010101 >> 0x18;
          return iVar2;
        default:
          return 999;
        case 3:
        case 0x66:
          return 10;
        case 0xf:
          return iVar2;
        case 0x17:
        case 99:
          return 0x13;
        case 0x1a:
          return 0x17;
        case 0x1b:
          return 4;
        case 0x1f:
        case 0x3b:
        case 0x54:
          return 2;
        case 0x51:
          return 0x14;
        case 0x55:
          return 0x1b;
        case 0x56:
          return 3;
        case 0x59:
          return 0x11;
        case 0x62:
          return 0x10;
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar6 = fVar6 * DAT_00298548;
      uVar7 = 0x4cf;
      uVar5 = 0x4cf;
      goto LAB_001c2b8d;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar6 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  fVar6 = fVar6 * DAT_00298548;
  uVar7 = 0x4c8;
  uVar5 = 0x4c8;
LAB_001c2b8d:
  FUN_002340f0((double)fVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
               "dmal/common/common_ecc.c",uVar5,"cDeviceGetGRGpcCount",uVar7,iVar2);
  return iVar2;
}


// ===== 001c2ce0 FUN_001c2ce0 =====

undefined1  [16] FUN_001c2ce0(long param_1,undefined8 param_2,undefined8 param_3,ulong *param_4)

{
  undefined8 uVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  undefined8 *puVar5;
  undefined1 auVar6 [16];
  undefined8 local_698 [205];
  char local_2f;
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  puVar5 = local_698;
  for (lVar3 = 0xd0; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  uVar2 = FUN_0019c780(uVar1,param_2,param_3,0x2080012f,local_698,0x680);
  uVar4 = 0;
  if ((uint)uVar2 < 0x67) {
    uVar4 = (long)&switchD_001c2d37::switchdataD_002b7c2c +
            (long)(int)(&switchD_001c2d37::switchdataD_002b7c2c)[uVar2 & 0xffffffff];
    switch(uVar2 & 0xffffffff) {
    case 0:
      uVar4 = (ulong)(local_2f == '\x01');
      *param_4 = uVar4;
      break;
    default:
      goto switchD_001c2d37_caseD_1;
    case 3:
    case 0x66:
      uVar2 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      uVar2 = 0x13;
      break;
    case 0x1a:
      uVar2 = 0x17;
      break;
    case 0x1b:
      uVar2 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
      uVar2 = 2;
      break;
    case 0x51:
      uVar2 = 0x14;
      break;
    case 0x55:
      uVar2 = 0x1b;
      break;
    case 0x56:
      uVar2 = 3;
      break;
    case 0x59:
      uVar2 = 0x11;
      break;
    case 0x62:
      uVar2 = 0x10;
    }
  }
  else {
switchD_001c2d37_caseD_1:
    uVar2 = 999;
  }
  auVar6._8_8_ = uVar4;
  auVar6._0_8_ = uVar2;
  return auVar6;
}


// ===== 001c2dc0 FUN_001c2dc0 =====

ulong FUN_001c2dc0(long param_1,long param_2,undefined8 *param_3)

{
  char cVar1;
  undefined8 uVar2;
  code *pcVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  char *pcVar7;
  ulong uVar8;
  int iVar9;
  float fVar10;
  undefined4 local_6bc;
  char local_6b8 [8];
  undefined8 auStack_6b0 [199];
  char local_78;
  uint local_4c;
  
  uVar2 = *(undefined8 *)(param_1 + 0x10);
  pcVar7 = local_6b8;
  for (lVar6 = 0xd0; lVar6 != 0; lVar6 = lVar6 + -1) {
    pcVar7[0] = '\0';
    pcVar7[1] = '\0';
    pcVar7[2] = '\0';
    pcVar7[3] = '\0';
    pcVar7[4] = '\0';
    pcVar7[5] = '\0';
    pcVar7[6] = '\0';
    pcVar7[7] = '\0';
    pcVar7 = pcVar7 + 8;
  }
  lVar6 = *(long *)(param_2 + 0x256d8);
  if (((lVar6 == 0) || (*(undefined8 **)(lVar6 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar3 = (code *)**(undefined8 **)(lVar6 + 0x50), pcVar3 == (code *)0x0)) {
    uVar8 = 3;
  }
  else {
    uVar4 = (*pcVar3)(lVar6,param_2,0x2080,&local_6bc);
    uVar8 = (ulong)uVar4;
    if (uVar4 == 0) {
      local_4c = local_4c | 1;
      uVar4 = FUN_0019c780(uVar2,DAT_0038088c,local_6bc,0x2080012f,local_6b8,0x680,0);
      uVar8 = (ulong)uVar4;
      switch(uVar4) {
      case 0:
        iVar9 = 1;
        break;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return uVar8;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
      do {
        uVar4 = iVar9 - 1;
        if (uVar4 < 0x29) {
          uVar5 = (ulong)uVar4;
          switch(uVar5) {
          case 0:
            uVar5 = 3;
            break;
          case 1:
            uVar5 = 6;
            break;
          case 3:
            uVar5 = 4;
            break;
          case 4:
            uVar5 = 5;
            break;
          case 5:
            uVar5 = 7;
            break;
          case 6:
            uVar5 = 8;
            break;
          case 7:
            uVar5 = 9;
            break;
          case 8:
            uVar5 = 1;
            break;
          case 9:
            uVar5 = uVar8;
            cVar1 = local_6b8[0];
            goto joined_r0x001c30e1;
          case 0x19:
          case 0x1a:
          case 0x1c:
            goto switchD_001c2fac_caseD_19;
          case 0x28:
            if (local_78 == '\0') {
              return uVar8;
            }
            goto LAB_001c2fc6;
          }
          cVar1 = *(char *)(auStack_6b0 + uVar5 * 5 + -1);
joined_r0x001c30e1:
          if (cVar1 != '\0') {
LAB_001c2fc6:
            uVar2 = auStack_6b0[uVar5 * 5];
            *param_3 = auStack_6b0[uVar5 * 5 + 2];
            param_3[1] = uVar2;
            goto LAB_001c2fe5;
          }
        }
        else {
switchD_001c2fac_caseD_19:
          if (2 < DAT_01216a78) {
            fVar10 = (float)FUN_002917b0(&DAT_01216a60);
            lVar6 = syscall(0xba);
            FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",
                         "WARNING",lVar6,"dmal/common/common_ecc.c",0x3dd,uVar4);
          }
LAB_001c2fe5:
          if (iVar9 == 0x29) {
            return uVar8;
          }
        }
        iVar9 = iVar9 + 1;
        param_3 = param_3 + 2;
      } while( true );
    }
  }
  if (1 < DAT_01216a78) {
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar6,"dmal/common/common_ecc.c",0x4a2,
                 "cDeviceGetTotalVolatileEccErrorsPerUnit",0x4a2,uVar8);
  }
  return uVar8;
}


// ===== 001c3150 FUN_001c3150 =====

int FUN_001c3150(long param_1,long param_2,uint *param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  undefined4 local_34;
  undefined8 local_30;
  
  local_30 = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    iVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_34);
    if (iVar3 == 0) {
      iVar3 = FUN_0019c780(uVar1,DAT_0038088c,local_34,0x20800133,&local_30,8,0);
      switch(iVar3) {
      case 0:
        *param_3 = (uint)(local_30._4_4_ == 1);
        return iVar3;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar3;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar3;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar4,"dmal/common/common_ecc.c",0x10c,"cDeviceGetDefaultEccMode",0x10c,iVar3
              );
  return iVar3;
}


// ===== 001c3350 FUN_001c3350 =====

int FUN_001c3350(long param_1,long param_2,uint *param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  undefined4 local_34;
  undefined8 local_30 [2];
  
  local_30[0] = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    iVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_34);
    if (iVar3 == 0) {
      iVar3 = FUN_0019c780(uVar1,DAT_0038088c,local_34,0x20800133,local_30,8,0);
      switch(iVar3) {
      case 0:
        *param_3 = (uint)((int)local_30[0] == 1);
        return iVar3;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar3;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar3;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar4,"dmal/common/common_ecc.c",0xec,"cDeviceGetEccPendingMode",0xec,iVar3);
  return iVar3;
}


// ===== 001c3550 FUN_001c3550 =====

uint FUN_001c3550(long param_1,long param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  uint uVar3;
  long lVar4;
  float fVar5;
  undefined4 local_1c;
  
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)) {
    uVar3 = 3;
  }
  else {
    uVar2 = *(undefined8 *)(param_1 + 0x10);
    uVar3 = (*pcVar1)(lVar4,param_2,0x2080,&local_1c);
    if (uVar3 == 0) {
      uVar3 = FUN_0019c780(uVar2,DAT_0038088c,local_1c,0x20800157,0,0,0);
      if (0x66 < uVar3) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002b9ae0 + (ulong)uVar3 * 2);
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar3;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar4,"dmal/common/common_ecc.c",0x9a,"cDeviceIsEccSupportedByInfoROM",0x9a,
               uVar3);
  return uVar3;
}


// ===== 001c36b0 FUN_001c36b0 =====

int FUN_001c36b0(long param_1,long param_2,undefined8 *param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  byte bVar7;
  float fVar8;
  undefined4 local_69c;
  undefined8 local_698;
  undefined8 local_690 [205];
  undefined8 local_28;
  
  bVar7 = 0;
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    uVar2 = *(undefined8 *)(param_1 + 0x10);
    iVar3 = (*pcVar1)(lVar4,param_2,0x2080,&local_69c);
    if (iVar3 == 0) {
      puVar5 = &local_698;
      for (lVar4 = 0xcd; lVar4 != 0; lVar4 = lVar4 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + (ulong)bVar7 * -2 + 1;
      }
      iVar3 = FUN_0019c780(uVar2,DAT_0038088c,local_69c,0x2080b400,&local_698,0x668,0);
      switch(iVar3) {
      case 0:
        puVar5 = local_690;
        do {
          puVar6 = puVar5 + 5;
          *param_3 = *puVar5;
          param_3[1] = puVar5[2];
          puVar5 = puVar6;
          param_3 = param_3 + 2;
        } while (&local_28 != puVar6);
        return iVar3;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar3;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar3;
  }
  fVar8 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar8 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar4,"dmal/common/common_ecc.c",0x3f7,
               "cDeviceGetTotalAggregateEccErrorsPerUnit",0x3f7,iVar3);
  return iVar3;
}


// ===== 001c38f0 FUN_001c38f0 =====

undefined8
FUN_001c38f0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  switch(param_1) {
  case 3:
    *param_2 = 0;
    *param_3 = 0;
    *param_4 = 8;
    return 0;
  case 4:
    *param_2 = 1;
    *param_3 = 0;
    *param_4 = 8;
    return 0;
  case 5:
    *param_2 = 0;
    *param_3 = 1;
    *param_4 = 8;
    return 0;
  case 6:
    *param_2 = 1;
    *param_3 = 1;
    *param_4 = 8;
    return 0;
  case 7:
    *param_2 = 0;
    *param_3 = 0;
    *param_4 = 0;
    return 0;
  case 8:
    *param_2 = 1;
    *param_3 = 0;
    *param_4 = 0;
    return 0;
  case 9:
    *param_2 = 0;
    *param_3 = 0;
    *param_4 = 1;
    return 0;
  case 10:
    *param_2 = 1;
    *param_3 = 0;
    *param_4 = 1;
    return 0;
  case 0xb:
    *param_2 = 0;
    *param_3 = 0;
    *param_4 = 2;
    return 0;
  case 0xc:
    *param_2 = 1;
    *param_3 = 0;
    *param_4 = 2;
    return 0;
  case 0xd:
    *param_2 = 0;
    *param_3 = 0;
    *param_4 = 3;
    return 0;
  case 0xe:
    *param_2 = 1;
    *param_3 = 0;
    *param_4 = 3;
    return 0;
  case 0xf:
    *param_2 = 0;
    *param_3 = 0;
    *param_4 = 4;
    return 0;
  case 0x10:
    *param_2 = 1;
    *param_3 = 0;
    *param_4 = 4;
    return 0;
  case 0x11:
    *param_2 = 1;
    *param_3 = 0;
    *param_4 = 6;
    return 0;
  case 0x12:
    *param_2 = 0;
    *param_3 = 1;
    *param_4 = 0;
    return 0;
  case 0x13:
    *param_2 = 1;
    *param_3 = 1;
    *param_4 = 0;
    return 0;
  case 0x14:
    *param_2 = 0;
    *param_3 = 1;
    *param_4 = 1;
    return 0;
  case 0x15:
    *param_2 = 1;
    *param_3 = 1;
    *param_4 = 1;
    return 0;
  case 0x16:
    *param_2 = 0;
    *param_3 = 1;
    *param_4 = 2;
    return 0;
  case 0x17:
    *param_2 = 1;
    *param_3 = 1;
    *param_4 = 2;
    return 0;
  case 0x18:
    *param_2 = 0;
    *param_3 = 1;
    *param_4 = 3;
    return 0;
  case 0x19:
    *param_2 = 1;
    *param_3 = 1;
    *param_4 = 3;
    return 0;
  case 0x1a:
    *param_2 = 0;
    *param_3 = 1;
    *param_4 = 4;
    return 0;
  case 0x1b:
    *param_2 = 1;
    *param_3 = 1;
    *param_4 = 4;
    return 0;
  case 0x1c:
    *param_2 = 1;
    *param_3 = 1;
    *param_4 = 6;
    return 0;
  default:
    return 2;
  }
}


// ===== 001c3b80 FUN_001c3b80 =====

int FUN_001c3b80(undefined4 *param_1,code *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  iVar1 = (*param_2)(param_3,param_4);
  if (iVar1 == 3) {
    if (4 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                   lVar2,"dmal/common/common_ecc.c",0x926);
    }
    *param_1 = 3;
    return 0;
  }
  if (iVar1 == 0) {
    *param_1 = 2;
  }
  else if (1 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","ERROR",
                 lVar2,"dmal/common/common_ecc.c",0x930,iVar1);
    return iVar1;
  }
  return iVar1;
}


// ===== 001c3cc0 FUN_001c3cc0 =====

int FUN_001c3cc0(long param_1,undefined8 param_2,int *param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  float fVar4;
  undefined8 uVar5;
  
  uVar3 = *(undefined8 *)(param_1 + 0x256d8);
  if ((*param_3 == 0) || (param_3[1] == 0)) {
    iVar1 = FUN_001c19a0(uVar3,param_1,param_2);
    if (iVar1 != 0) {
      if (DAT_01216a78 < 2) {
        return iVar1;
      }
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      fVar4 = fVar4 * DAT_00298548;
      uVar5 = 0x97f;
      uVar3 = 0x97f;
      goto LAB_001c3e15;
    }
    param_3[0] = 2;
    param_3[1] = 2;
  }
  if ((param_3[2] != 0) && (param_3[3] != 0)) {
    return 0;
  }
  iVar1 = FUN_001c1c30(uVar3,param_1,param_2);
  if (iVar1 == 0) {
    param_3[2] = 2;
    param_3[3] = 2;
    return 0;
  }
  if (DAT_01216a78 < 2) {
    return iVar1;
  }
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar2 = syscall(0xba);
  fVar4 = fVar4 * DAT_00298548;
  uVar5 = 0x989;
  uVar3 = 0x989;
LAB_001c3e15:
  FUN_002340f0((double)fVar4,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
               "dmal/common/common_ecc.c",uVar3,"cVgpuGetCachedEccCountsPreTuring",uVar5,iVar1);
  return iVar1;
}


// ===== 001c3e40 FUN_001c3e40 =====

int FUN_001c3e40(undefined8 param_1,long param_2,undefined1 (*param_3) [16])

{
  byte bVar1;
  code *pcVar2;
  byte bVar3;
  int iVar4;
  long lVar5;
  byte *pbVar6;
  int *piVar7;
  float fVar8;
  undefined4 local_183c;
  int local_1838;
  byte local_1834;
  byte local_1826 [12];
  byte abStack_181a [6130];
  
  piVar7 = &local_1838;
  for (lVar5 = 0x301; lVar5 != 0; lVar5 = lVar5 + -1) {
    piVar7[0] = 0;
    piVar7[1] = 0;
    piVar7 = piVar7 + 2;
  }
  lVar5 = *(long *)(param_2 + 0x256d8);
  if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar5 + 0x50), pcVar2 == (code *)0x0)) {
    iVar4 = 3;
  }
  else {
    iVar4 = (*pcVar2)(lVar5,param_2,0x2080,&local_183c);
    if (iVar4 == 0) {
      iVar4 = FUN_0019c780(param_1,DAT_0038088c,local_183c,0x20801344,&local_1838,0x1808,0);
      switch(iVar4) {
      case 0:
        goto switchD_001c3fab_caseD_0;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar4;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar4;
  }
  fVar8 = (float)FUN_002917b0(&DAT_01216a60);
  lVar5 = syscall(0xba);
  FUN_002340f0((double)(fVar8 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar5,"dmal/common/common_ecc.c",0xc8f,"cDeviceGetRemappedRowsV2RmApi",0xc8f,
               iVar4);
  return iVar4;
switchD_001c3fab_caseD_0:
  *(undefined8 *)param_3[1] = 0;
  *param_3 = (undefined1  [16])0x0;
  if (local_1838 != 0) {
    pbVar6 = local_1826;
    do {
      bVar1 = *pbVar6;
      bVar3 = pbVar6[1] >> 1 & 1;
      if (bVar1 == 2) {
LAB_001c40c0:
        if (bVar3 == 0) {
          *(int *)(*param_3 + 4) = *(int *)(*param_3 + 4) + 1;
        }
        else {
          *(int *)*param_3 = *(int *)*param_3 + 1;
        }
      }
      else {
        if (bVar1 < 3) {
          if (bVar1 == 0) goto LAB_001c40c0;
        }
        else if (bVar1 != 3) goto LAB_001c4050;
        if (bVar3 == 0) {
          *(int *)(*param_3 + 0xc) = *(int *)(*param_3 + 0xc) + 1;
        }
        else {
          *(int *)(*param_3 + 8) = *(int *)(*param_3 + 8) + 1;
        }
      }
LAB_001c4050:
      pbVar6 = pbVar6 + 0xc;
    } while (abStack_181a + (ulong)(local_1838 - 1) * 0xc != pbVar6);
  }
  *(uint *)param_3[1] = local_1834 & 1;
  *(uint *)(param_3[1] + 4) = local_1834 >> 1 & 1;
  return iVar4;
}


// ===== 001c4110 FUN_001c4110 =====

int FUN_001c4110(undefined8 param_1,long param_2,int *param_3,int *param_4,uint *param_5,
                uint *param_6)

{
  byte bVar1;
  code *pcVar2;
  int iVar3;
  byte *pbVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  float fVar9;
  undefined4 local_184c;
  int local_1848;
  byte local_1844;
  byte local_1836 [12];
  byte abStack_182a [6138];
  
  piVar8 = &local_1848;
  for (lVar5 = 0x301; lVar5 != 0; lVar5 = lVar5 + -1) {
    piVar8[0] = 0;
    piVar8[1] = 0;
    piVar8 = piVar8 + 2;
  }
  lVar5 = *(long *)(param_2 + 0x256d8);
  if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar5 + 0x50), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    iVar3 = (*pcVar2)(lVar5,param_2,0x2080,&local_184c);
    if (iVar3 == 0) {
      iVar3 = FUN_0019c780(param_1,DAT_0038088c,local_184c,0x20801344,&local_1848,0x1808,0);
      switch(iVar3) {
      case 0:
        goto switchD_001c4287_caseD_0;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar3;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (1 < DAT_01216a78) {
    fVar9 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar5,"dmal/common/common_ecc.c",0xc5e,"cDeviceGetRemappedRowsRmApi",0xc5e,
                 iVar3);
  }
  return iVar3;
switchD_001c4287_caseD_0:
  iVar7 = 0;
  iVar6 = 0;
  if (local_1848 != 0) {
    pbVar4 = local_1836;
    iVar6 = iVar3;
    iVar7 = iVar3;
    do {
      if ((pbVar4[1] & 2) != 0) {
        bVar1 = *pbVar4;
        if (bVar1 == 2) {
LAB_001c4388:
          iVar6 = iVar6 + 1;
        }
        else {
          if (bVar1 < 3) {
            if (bVar1 == 0) goto LAB_001c4388;
          }
          else if (bVar1 != 3) goto LAB_001c431f;
          iVar7 = iVar7 + 1;
        }
      }
LAB_001c431f:
      pbVar4 = pbVar4 + 0xc;
    } while (pbVar4 != abStack_182a + (ulong)(local_1848 - 1) * 0xc);
  }
  *param_3 = iVar6;
  *param_4 = iVar7;
  *param_5 = local_1844 & 1;
  *param_6 = local_1844 >> 1 & 1;
  return iVar3;
}


// ===== 001c43c0 FUN_001c43c0 =====

uint FUN_001c43c0(undefined8 param_1,long param_2)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  undefined8 *puVar4;
  float fVar5;
  undefined4 local_1ec;
  undefined8 local_1e8 [57];
  
  puVar4 = local_1e8;
  for (lVar3 = 0x36; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined4 *)puVar4 = 0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    uVar2 = 3;
  }
  else {
    uVar2 = (*pcVar1)(lVar3,param_2,0x90e7,&local_1ec);
    if (uVar2 == 0) {
      uVar2 = FUN_0019c780(param_1,DAT_0038088c,local_1ec,0x90e70201,local_1e8,0x1b4,0);
      if (0x66 < uVar2) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002b9ae0 + (ulong)uVar2 * 2);
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_ecc.c",0xbd0,"cDeviceClearRprObject",0xbd0,uVar2);
  return uVar2;
}


// ===== 001c4550 FUN_001c4550 =====

int FUN_001c4550(long param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  float fVar7;
  undefined4 local_44;
  ulong local_40 [2];
  
  local_40[0] = 0;
  uVar6 = *(undefined8 *)(param_1 + 0x10);
  lVar5 = *(long *)(param_2 + 0x256d8);
  if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar5 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar5,param_2,0x2080,&local_44);
    if (iVar2 == 0) {
      local_40[0] = CONCAT44((int)(local_40[0] >> 0x20),3) | 0x100000000;
      iVar2 = FUN_0019c780(uVar6,DAT_0038088c,local_44,0x20800136,local_40,8,0);
      switch(iVar2) {
      case 0:
        goto switchD_001c46ac_caseD_0;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar2;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (1 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar5,"dmal/common/common_ecc.c",0xbe4,"cDeviceClearEccHistory",0xbe4,iVar2
                );
  }
  return iVar2;
switchD_001c46ac_caseD_0:
  iVar3 = FUN_001c0ef0(param_1,param_2);
  if (iVar3 == 3) {
    iVar3 = iVar2;
    if (3 < DAT_01216a78) {
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar5,"dmal/common/common_ecc.c",0xbf9);
    }
  }
  else if ((iVar3 != 0) && (1 < DAT_01216a78)) {
    uVar6 = nvmlErrorString(iVar3);
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n","ERROR",
                 lVar5,"dmal/common/common_ecc.c",0xbfe,uVar6);
  }
  iVar4 = FUN_001c0d70(param_1,param_2);
  if (iVar4 == 3) {
    if (1 < DAT_01216a78) {
      uVar6 = nvmlErrorString(3);
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n","ERROR",
                   lVar5,"dmal/common/common_ecc.c",0xc0a,uVar6);
    }
  }
  else if (3 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar5,"dmal/common/common_ecc.c",0xc06);
  }
  if (iVar3 == 0) {
    iVar3 = iVar4;
  }
  iVar4 = FUN_001c43c0(*(undefined8 *)(param_1 + 0x10),param_2);
  if (iVar4 == 3) {
    if (3 < DAT_01216a78) {
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar5,"dmal/common/common_ecc.c",0xc12);
    }
  }
  else {
    iVar2 = iVar4;
    if ((iVar4 != 0) && (1 < DAT_01216a78)) {
      uVar6 = nvmlErrorString(iVar4);
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n","ERROR",
                   lVar5,"dmal/common/common_ecc.c",0xc17,uVar6);
    }
  }
  if (iVar3 != 0) {
    return iVar3;
  }
  return iVar2;
}


// ===== 001c4a50 FUN_001c4a50 =====

int FUN_001c4a50(undefined8 param_1,undefined8 param_2,int param_3,int *param_4)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  float fVar7;
  double dVar8;
  undefined8 uVar9;
  uint local_40;
  uint local_3c;
  
  uVar3 = (ulong)(param_3 - 3U);
  if (param_3 - 3U < 0x1a) {
    uVar5 = *(uint *)(&DAT_002b9d80 + uVar3 * 4);
    local_3c = *(uint *)(&DAT_002b9d00 + uVar3 * 4);
    uVar6 = *(uint *)(&DAT_002b9c80 + uVar3 * 4);
    local_40 = *(uint *)(&DAT_002b9c00 + uVar3 * 4);
  }
  else {
    local_40 = 0;
    uVar6 = 0;
    uVar5 = 0;
    local_3c = 0;
  }
  if ((*param_4 == 0) && (iVar1 = FUN_001c3b80(param_4,FUN_001c8430,param_1,param_2), iVar1 != 0)) {
    if (DAT_01216a78 < 2) {
      return iVar1;
    }
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    uVar4 = 0x941;
    uVar9 = 0x941;
    dVar8 = (double)(fVar7 * DAT_00298548);
    local_3c = iVar1;
  }
  else if ((param_4[1] == 0) &&
          (iVar1 = FUN_001c3b80(param_4 + 1,FUN_001c7a60,param_1,param_2), iVar1 != 0)) {
    if (DAT_01216a78 < 2) {
      return iVar1;
    }
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    uVar4 = 0x946;
    uVar9 = 0x946;
    dVar8 = (double)(fVar7 * DAT_00298548);
    local_3c = iVar1;
  }
  else if ((param_4[2] == 0) &&
          (iVar1 = FUN_001c3b80(param_4 + 2,FUN_001c84a0,param_1,param_2), iVar1 != 0)) {
    if (DAT_01216a78 < 2) {
      return iVar1;
    }
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    uVar4 = 0x94b;
    uVar9 = 0x94b;
    dVar8 = (double)(fVar7 * DAT_00298548);
    local_3c = iVar1;
  }
  else {
    if ((param_4[3] != 0) ||
       (iVar1 = FUN_001c3b80(param_4 + 3,FUN_001c8510,param_1,param_2), iVar1 == 0)) {
      if (((*param_4 == 3) && (param_4[1] == 3)) || ((param_4[2] == 3 && (param_4[3] == 3)))) {
        if (DAT_01216a78 < 2) {
          return 3;
        }
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar2 = syscall(0xba);
        FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                     lVar2,"dmal/common/common_ecc.c",0x95c);
        return 3;
      }
      if ((((uVar5 ^ 1) & local_3c & 1) == 0) || (param_4[1] != 3)) {
        if (((uVar6 ^ 1) & local_40 & 1) == 0) {
          return 0;
        }
        if (param_4[3] != 3) {
          return 0;
        }
      }
      if (DAT_01216a78 < 5) {
        return 3;
      }
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d, %d\n",
                   "DEBUG",lVar2,"dmal/common/common_ecc.c",0x96b,local_3c,local_40);
      return 3;
    }
    if (DAT_01216a78 < 2) {
      return iVar1;
    }
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    uVar4 = 0x950;
    uVar9 = 0x950;
    dVar8 = (double)(fVar7 * DAT_00298548);
    local_3c = iVar1;
  }
  FUN_002340f0(dVar8,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
               "dmal/common/common_ecc.c",uVar4,"cGetCachedEccCountsPreTuring",uVar9,local_3c);
  return local_3c;
}


// ===== 001c4ee0 FUN_001c4ee0 =====

int FUN_001c4ee0(undefined8 param_1,long param_2,long param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  float fVar6;
  undefined4 local_3c [3];
  
  if (*(char *)(param_2 + 0x580) == '\0') {
    lVar5 = *(long *)(param_2 + 0x256d8);
    if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar3 = (code *)**(undefined8 **)(lVar5 + 0x50), pcVar3 == (code *)0x0)) {
      iVar4 = 3;
    }
    else {
      iVar4 = (*pcVar3)(lVar5,param_2,0x2080,local_3c);
      if (iVar4 == 0) {
        iVar4 = FUN_0019c780(param_1,DAT_0038088c,local_3c[0],0x20801322,param_3,0x808,0);
        if (iVar4 != 0x57) {
          if (iVar4 != 0x56) {
            switch(iVar4) {
            case 0:
              goto switchD_001c4fae_caseD_0;
            default:
              return 999;
            case 3:
            case 0x66:
              return 10;
            case 0xf:
              return iVar4;
            case 0x17:
            case 99:
              return 0x13;
            case 0x1a:
              return 0x17;
            case 0x1b:
              return 4;
            case 0x1f:
            case 0x3b:
            case 0x54:
              return 2;
            case 0x51:
              return 0x14;
            case 0x55:
              return 0x1b;
            case 0x59:
              return 0x11;
            case 0x62:
              return 0x10;
            }
          }
          *(undefined1 *)(param_2 + 0x580) = 1;
        }
        goto LAB_001c5047;
      }
    }
    if (1 < DAT_01216a78) {
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar5,"dmal/common/common_ecc.c",0x68c,"cDeviceGetRmBlacklistInfo",0x68c,
                   iVar4);
    }
  }
  else {
LAB_001c5047:
    iVar4 = 3;
  }
  return iVar4;
switchD_001c4fae_caseD_0:
  if (DAT_01216a78 < 5) {
    return iVar4;
  }
  uVar2 = *(undefined4 *)(param_3 + 0x800);
  fVar6 = (float)FUN_002917b0(&DAT_01216a60);
  lVar5 = syscall(0xba);
  FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
               lVar5,"dmal/common/common_ecc.c",0x69c,uVar2);
  if (DAT_01216a78 < 5) {
    return iVar4;
  }
  uVar1 = *(undefined1 *)(param_3 + 0x804);
  fVar6 = (float)FUN_002917b0(&DAT_01216a60);
  lVar5 = syscall(0xba);
  FUN_002340f0((double)(DAT_00298548 * fVar6),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
               lVar5,"dmal/common/common_ecc.c",0x69e,uVar1);
  return iVar4;
}


// ===== 001c51a0 FUN_001c51a0 =====

int FUN_001c51a0(long param_1,long param_2,int param_3,uint *param_4,long param_5,long param_6)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  long lVar5;
  int iVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  uint uVar9;
  ulong uVar10;
  uint uVar11;
  undefined8 *puVar12;
  float fVar13;
  undefined8 uVar14;
  int local_84c;
  undefined8 local_848 [2];
  int local_834 [8];
  int aiStack_814 [499];
  uint local_48;
  
  puVar12 = local_848;
  puVar7 = puVar12;
  for (lVar5 = 0x101; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  iVar6 = 2;
  if (param_3 != 0) {
    iVar6 = (uint)(param_3 == 1) << 2;
  }
  uVar9 = *param_4;
  iVar3 = FUN_001c4ee0(*(undefined8 *)(param_1 + 0x10),param_2,puVar12);
  if (iVar3 == 0) {
    bVar2 = false;
    uVar11 = 0;
    if (local_48 != 0) {
      piVar4 = local_834;
      uVar11 = 0;
      do {
        iVar3 = *piVar4;
        piVar4 = piVar4 + 8;
        uVar11 = uVar11 + (iVar3 == iVar6);
      } while (piVar4 != aiStack_814 + (ulong)(local_48 - 1) * 8);
      bVar2 = uVar9 < uVar11;
    }
    *param_4 = uVar11;
    if ((uVar9 == 0) || (bVar2)) {
      if (DAT_01216a78 < 5) {
        return 7;
      }
      fVar13 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar13 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u\n",
                   "DEBUG",lVar5,"dmal/common/common_ecc.c",0x72a,uVar9,uVar11);
      return 7;
    }
    if (param_5 == 0) {
      if (DAT_01216a78 < 5) {
        return 2;
      }
      fVar13 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar13 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                   lVar5,"dmal/common/common_ecc.c",0x731);
      return 2;
    }
    lVar5 = *(long *)(param_2 + 0x256d8);
    if (((lVar5 == 0) || (*(long *)(lVar5 + 0x140) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(lVar5 + 0x140) + 8), pcVar1 == (code *)0x0)) {
      iVar3 = 3;
    }
    else {
      iVar3 = (*pcVar1)(lVar5,param_2,&local_84c);
      if (iVar3 == 0) {
        uVar9 = 0;
        uVar10 = 0;
        if (local_48 == 0) {
          return 0;
        }
LAB_001c52f2:
        do {
          if (*(int *)((long)puVar12 + 0x14) == iVar6) {
            uVar8 = puVar12[1];
            if (local_84c == 1) {
              uVar8 = *puVar12;
            }
            if (param_6 != 0) {
              *(ulong *)(param_6 + uVar10 * 8) = (ulong)*(uint *)((long)puVar12 + 0x1c);
            }
            uVar11 = (int)uVar10 + 1;
            *(undefined8 *)(param_5 + uVar10 * 8) = uVar8;
            uVar10 = (ulong)uVar11;
            if (4 < DAT_01216a78) {
              puVar12 = puVar12 + 4;
              fVar13 = (float)FUN_002917b0(&DAT_01216a60);
              lVar5 = syscall(0xba);
              FUN_002340f0((double)(fVar13 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%llu\n","DEBUG",lVar5,
                           "dmal/common/common_ecc.c",0x751,uVar8);
              uVar10 = (ulong)uVar11;
              uVar9 = uVar9 + 1;
              if (local_48 <= uVar9) {
                return 0;
              }
              goto LAB_001c52f2;
            }
          }
          uVar9 = uVar9 + 1;
          puVar12 = puVar12 + 4;
          if (local_48 <= uVar9) {
            return 0;
          }
        } while( true );
      }
    }
    if (DAT_01216a78 < 2) {
      return iVar3;
    }
    fVar13 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    fVar13 = fVar13 * DAT_00298548;
    uVar14 = 0x73a;
    uVar8 = 0x73a;
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar3;
    }
    fVar13 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    fVar13 = fVar13 * DAT_00298548;
    uVar14 = 0x719;
    uVar8 = 0x719;
  }
  FUN_002340f0((double)fVar13,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,
               "dmal/common/common_ecc.c",uVar8,"cDeviceGetRetiredPages",uVar14,iVar3);
  return iVar3;
}


// ===== 001c55d0 FUN_001c55d0 =====

int FUN_001c55d0(long param_1,undefined8 param_2,uint *param_3)

{
  int iVar1;
  long lVar2;
  undefined8 *puVar3;
  float fVar4;
  undefined8 local_828 [256];
  char local_24;
  
  puVar3 = local_828;
  for (lVar2 = 0x101; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  iVar1 = FUN_001c4ee0(*(undefined8 *)(param_1 + 0x10));
  if (iVar1 == 0) {
    *param_3 = (uint)(local_24 != '\0');
  }
  else if (1 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar2,"dmal/common/common_ecc.c",0x765,
                 "cDeviceGetRetiredPagesPendingStatus",0x765,iVar1);
    return iVar1;
  }
  return iVar1;
}


// ===== 001c56c0 FUN_001c56c0 =====

int FUN_001c56c0(long param_1,char *param_2,int param_3,long param_4,long param_5)

{
  code *pcVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  undefined8 uVar5;
  float fVar6;
  undefined8 uVar7;
  long local_1058 [4];
  long alStack_1038 [252];
  int local_858;
  long local_848 [256];
  undefined8 local_48;
  int local_40;
  
  uVar5 = *(undefined8 *)(param_1 + 0x10);
  plVar3 = local_848;
  for (lVar4 = 0x102; lVar4 != 0; lVar4 = lVar4 + -1) {
    *plVar3 = 0;
    plVar3 = plVar3 + 1;
  }
  if ((param_2 == (char *)0x0) || (*param_2 == '\x01')) {
    if (param_3 != 500) {
      return 3;
    }
    plVar3 = local_1058;
    for (lVar4 = 0x101; lVar4 != 0; lVar4 = lVar4 + -1) {
      *plVar3 = 0;
      plVar3 = plVar3 + 1;
    }
  }
  else {
    if (param_3 != 500) {
      return 3;
    }
    plVar3 = local_1058;
    for (lVar4 = 0x101; lVar4 != 0; lVar4 = lVar4 + -1) {
      *plVar3 = 0;
      plVar3 = plVar3 + 1;
    }
  }
  iVar2 = FUN_001c4ee0(uVar5,param_2,local_1058);
  if (iVar2 == 0) {
    if (local_858 != 0) {
      plVar3 = local_1058;
      do {
        if ((param_4 == *plVar3) && (param_5 == plVar3[1])) {
          return 0x3eb;
        }
        plVar3 = plVar3 + 4;
      } while (plVar3 != alStack_1038 + (ulong)(local_858 - 1) * 4);
    }
    lVar4 = *(long *)(param_2 + 0x256d8);
    if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)) {
      iVar2 = 3;
    }
    else {
      iVar2 = (*pcVar1)(lVar4,param_2,0x2080,local_1058);
      if (iVar2 == 0) {
        local_48 = 0x100000000;
        local_848[0] = param_4;
        local_848[1] = param_5;
        iVar2 = FUN_0019c780(uVar5,DAT_0038088c,(undefined4)local_1058[0],0x20801321,local_848,0x810
                             ,0);
        switch(iVar2) {
        case 0:
          goto switchD_001c5892_caseD_0;
        default:
          return 999;
        case 3:
        case 0x66:
          return 10;
        case 0xf:
          return iVar2;
        case 0x17:
        case 99:
          return 0x13;
        case 0x1a:
          return 0x17;
        case 0x1b:
          return 4;
        case 0x1f:
        case 0x3b:
        case 0x54:
          return 2;
        case 0x51:
          return 0x14;
        case 0x55:
          return 0x1b;
        case 0x56:
          return 3;
        case 0x59:
          return 0x11;
        case 0x62:
          return 0x10;
        }
      }
    }
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    fVar6 = fVar6 * DAT_00298548;
    uVar7 = 0x7b2;
    uVar5 = 0x7b2;
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_ecc.c",0x77d,"cDeviceCheckIfPageIsRetired");
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    fVar6 = DAT_00298548 * fVar6;
    uVar7 = 0x7aa;
    uVar5 = 0x7aa;
  }
  FUN_002340f0((double)fVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
               "dmal/common/common_ecc.c",uVar5,"cDeviceRetirePage",uVar7,iVar2);
  return iVar2;
switchD_001c5892_caseD_0:
  if (local_40 != 0) {
    return iVar2;
  }
  if (DAT_01216a78 < 5) {
    return 0x3ec;
  }
  fVar6 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",lVar4,
               "dmal/common/common_ecc.c",0x7bf);
  return 0x3ec;
}


// ===== 001c5b10 FUN_001c5b10 =====

int FUN_001c5b10(undefined8 param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  float fVar7;
  undefined4 local_6ac;
  char local_6a8 [1640];
  char local_40 [24];
  
  pcVar4 = local_6a8;
  for (lVar3 = 0xd0; lVar3 != 0; lVar3 = lVar3 + -1) {
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4[2] = '\0';
    pcVar4[3] = '\0';
    pcVar4[4] = '\0';
    pcVar4[5] = '\0';
    pcVar4[6] = '\0';
    pcVar4[7] = '\0';
    pcVar4 = pcVar4 + 8;
  }
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_6ac);
    if (iVar2 == 0) {
      iVar2 = FUN_0019c780(param_1,DAT_0038088c,local_6ac,0x2080012f,local_6a8,0x680,0);
      switch(iVar2) {
      case 0:
        pcVar4 = (char *)(param_2 + 0x520);
        pcVar5 = local_6a8;
        break;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return iVar2;
      case 0x17:
      case 99:
        return 0x13;
      case 0x1a:
        return 0x17;
      case 0x1b:
        return 4;
      case 0x1f:
      case 0x3b:
      case 0x54:
        return 2;
      case 0x51:
        return 0x14;
      case 0x55:
        return 0x1b;
      case 0x56:
        return 3;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
      do {
        pcVar6 = pcVar5 + 0x28;
        *pcVar4 = *pcVar5;
        pcVar4[1] = pcVar5[2];
        pcVar4 = pcVar4 + 2;
        pcVar5 = pcVar6;
      } while (pcVar6 != local_40);
      return iVar2;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar7 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_ecc.c",0xb0,"cDeviceEccCurrentModeUncached",0xb0,
               iVar2);
  return iVar2;
}


// ===== 001c5d50 FUN_001c5d50 =====

int FUN_001c5d50(long param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  long lVar4;
  float fVar5;
  
  if (*(int *)(param_2 + 0x574) == 0) {
    do {
      iVar1 = FUN_00291820(param_2 + 0x578,1,0);
    } while (iVar1 != 0);
    if (*(int *)(param_2 + 0x574) == 0) {
      uVar2 = FUN_001c5b10(*(undefined8 *)(param_1 + 0x10),param_2);
      *(undefined4 *)(param_2 + 0x574) = 1;
      *(undefined4 *)(param_2 + 0x57c) = uVar2;
    }
    FUN_00291830(param_2 + 0x578,0);
  }
  iVar1 = *(int *)(param_2 + 0x57c);
  if (iVar1 == 0) {
    *param_3 = 0;
    pcVar3 = (char *)(param_2 + 0x520);
    do {
      if (*pcVar3 != '\0') {
        *param_3 = 1;
        return 0;
      }
      pcVar3 = pcVar3 + 2;
    } while (pcVar3 != (char *)(param_2 + 0x572));
  }
  else if (1 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_ecc.c",0xcf,"cDeviceGetEccCurrentMode",0xcf,iVar1
                );
    return iVar1;
  }
  return iVar1;
}


// ===== 001c5ec0 FUN_001c5ec0 =====

int FUN_001c5ec0(long param_1,long param_2,uint *param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  byte local_31;
  undefined4 local_30;
  int local_2c;
  
  local_31 = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  if (param_3 == (uint *)0x0) {
switchD_001c60d1_caseD_1f:
    return 2;
  }
  iVar3 = FUN_001c5d50(param_1,param_2,&local_2c);
  if (iVar3 == 0) {
    if (local_2c == 0) {
      iVar3 = 3;
      if (4 < DAT_01216a78) {
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                     lVar4,"dmal/common/common_ecc.c",0xdca);
      }
    }
    else {
      lVar4 = *(long *)(param_2 + 0x256d8);
      if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
         (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
        iVar3 = 3;
      }
      else {
        iVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_30);
        if (iVar3 == 0) {
          iVar3 = FUN_0019c780(uVar1,DAT_0038088c,local_30,0x20803406,&local_31,1,0);
          switch(iVar3) {
          case 0:
            *param_3 = (uint)local_31;
            return iVar3;
          default:
            return 999;
          case 3:
          case 0x66:
            return 10;
          case 0xf:
            return iVar3;
          case 0x17:
          case 99:
            return 0x13;
          case 0x1a:
            return 0x17;
          case 0x1b:
            return 4;
          case 0x1f:
          case 0x3b:
          case 0x54:
            goto switchD_001c60d1_caseD_1f;
          case 0x51:
            return 0x14;
          case 0x55:
            return 0x1b;
          case 0x56:
            return 3;
          case 0x59:
            return 0x11;
          case 0x62:
            return 0x10;
          }
        }
      }
      if (1 < DAT_01216a78) {
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                     "ERROR",lVar4,"dmal/common/common_ecc.c",0xdcf,
                     "cDeviceGetUnrepairableMemoryFlag",0xdcf,iVar3);
        return iVar3;
      }
    }
  }
  return iVar3;
}


// ===== 001c6180 FUN_001c6180 =====

int FUN_001c6180(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  int local_3c [3];
  
  uVar1 = *(uint *)(param_3 + 4);
  if (uVar1 < 2) {
    iVar2 = FUN_001c5d50(param_1,param_2,local_3c);
    if (iVar2 == 0) {
      if (local_3c[0] == 0) {
        iVar2 = 3;
        if (1 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       "ERROR",lVar3,"dmal/common/common_ecc.c",0xb64);
        }
      }
      else {
        uVar1 = *(uint *)(param_3 + 8);
        if (uVar1 == 9) {
          iVar2 = FUN_001ce460(param_1,param_2,*(undefined4 *)(param_3 + 4),
                               *(undefined8 *)(param_3 + 0x10),*(undefined4 *)(param_3 + 0x18),
                               *(undefined4 *)(param_3 + 0x1c));
        }
        else if ((uVar1 < 10) || (iVar2 = 3, uVar1 - 10 < 0x1f)) {
          iVar2 = FUN_001cfd70(param_1,param_2,*(undefined4 *)(param_3 + 4));
        }
      }
    }
  }
  else {
    iVar2 = 2;
    if (1 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","ERROR",
                   lVar3,"dmal/common/common_ecc.c",0xb58,uVar1);
    }
  }
  return iVar2;
}


// ===== 001c6310 FUN_001c6310 =====

undefined8 FUN_001c6310(undefined8 param_1,long param_2,uint param_3,undefined4 *param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 uVar5;
  float fVar6;
  
  *param_4 = 8;
  if (*(int *)(param_2 + 0x71c) == 0) {
    do {
      iVar2 = FUN_00291820(param_2 + 0x720,1,0);
    } while (iVar2 != 0);
    if (*(int *)(param_2 + 0x71c) == 0) {
      lVar4 = *(long *)(param_2 + 0x256d8);
      uVar3 = 3;
      if (((lVar4 != 0) && (*(long *)(lVar4 + 0x20) != 0)) &&
         (pcVar1 = *(code **)(*(long *)(lVar4 + 0x20) + 0x98), pcVar1 != (code *)0x0)) {
        uVar3 = (*pcVar1)(lVar4,param_2,param_2 + 0x708);
      }
      *(undefined4 *)(param_2 + 0x724) = uVar3;
      *(undefined4 *)(param_2 + 0x71c) = 1;
    }
    FUN_00291830(param_2 + 0x720,0);
  }
  if (*(int *)(param_2 + 0x724) != 0) {
    return 0;
  }
  if (*(uint *)(param_2 + 0x708) < 9) {
    if (param_3 < 9) {
      *param_4 = *(undefined4 *)(&DAT_002b9bc0 + (ulong)param_3 * 4);
      return 0;
    }
    uVar3 = 8;
    if (DAT_01216a78 < 1) goto LAB_001c6401;
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    uVar5 = 0x1a4;
    fVar6 = fVar6 * DAT_00298548;
  }
  else {
    uVar3 = 2;
    if (((param_3 == 0) || (uVar3 = 7, param_3 < 0x29)) || (uVar3 = 8, DAT_01216a78 < 1))
    goto LAB_001c6401;
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    uVar5 = 0x1b3;
    fVar6 = fVar6 * DAT_00298548;
  }
  uVar3 = 8;
  FUN_002340f0((double)fVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","CRITICAL",lVar4,
               "dmal/common/common_ecc.c",uVar5,param_3);
LAB_001c6401:
  *param_4 = uVar3;
  return 0;
}


