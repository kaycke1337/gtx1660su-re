// ===== 00219e00 FUN_00219e00 =====

undefined4 FUN_00219e00(long param_1,long param_2,void *param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined4 local_13c;
  char local_138 [128];
  undefined8 local_b8 [8];
  char local_71 [73];
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  puVar7 = local_b8;
  for (lVar6 = 0x11; lVar6 != 0; lVar6 = lVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  lVar6 = *(long *)(param_2 + 0x256d8);
  if (((lVar6 != 0) && (*(undefined8 **)(lVar6 + 0x50) != (undefined8 *)0x0)) &&
     (pcVar2 = (code *)**(undefined8 **)(lVar6 + 0x50), pcVar2 != (code *)0x0)) {
    iVar3 = (*pcVar2)(lVar6,param_2,0x2080,&local_13c);
    if (iVar3 == 0) {
      uVar4 = FUN_0019c780(uVar1,DAT_0038088c,local_13c,0x2080013f,local_b8,0x88,0);
      switch(uVar4) {
      case 0:
        pcVar5 = stpcpy(local_138,local_71);
        memcpy(param_3,local_138,(size_t)(pcVar5 + (1 - (long)local_138)));
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
    else if (iVar3 == 0xf) {
      return 0xf;
    }
  }
  return 999;
}


// ===== 00219f70 FUN_00219f70 =====

undefined4 FUN_00219f70(undefined8 param_1,long param_2,char *param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 *puVar5;
  float fVar6;
  undefined4 local_13c;
  undefined8 local_138;
  uint local_130;
  char local_12c [260];
  
  puVar5 = &local_138;
  for (lVar4 = 0x21; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined4 *)puVar5 = 0;
  *param_3 = '\0';
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0))
  goto switchD_0021a05b_caseD_1;
  iVar2 = (*pcVar1)(lVar4,param_2,0x2080,&local_13c);
  if (iVar2 != 0) {
    if (iVar2 == 0xf) {
      return 0xf;
    }
    goto switchD_0021a05b_caseD_1;
  }
  uVar3 = FUN_0019c780(param_1,DAT_0038088c,local_13c,0x2080014a,&local_138,0x10c,0);
  switch(uVar3) {
  case 0:
    if (4 < DAT_01216a78) {
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n","DEBUG",
                   lVar4,"dmal/common/common_ids.c",0x166,local_12c);
    }
    if ((local_130 < 0x100) && (strncpy(param_3,local_12c,0x100), *param_3 != '\0')) {
      return uVar3;
    }
  default:
switchD_0021a05b_caseD_1:
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


// ===== 0021a170 FUN_0021a170 =====

undefined4 FUN_0021a170(long param_1,long param_2,char *param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  undefined8 *puVar6;
  float fVar7;
  undefined4 local_bc;
  undefined8 local_b8 [3];
  char local_9c [116];
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  puVar6 = local_b8;
  for (lVar5 = 0x11; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  lVar5 = *(long *)(param_2 + 0x256d8);
  if (((lVar5 != 0) && (*(undefined8 **)(lVar5 + 0x50) != (undefined8 *)0x0)) &&
     (pcVar2 = (code *)**(undefined8 **)(lVar5 + 0x50), pcVar2 != (code *)0x0)) {
    iVar3 = (*pcVar2)(lVar5,param_2,0x2080,&local_bc);
    if (iVar3 == 0) {
      uVar4 = FUN_0019c780(uVar1,DAT_0038088c,local_bc,0x2080013f,local_b8,0x88,0);
      switch(uVar4) {
      case 0:
        if (4 < DAT_01216a78) {
          fVar7 = (float)FUN_002917b0(&DAT_01216a60);
          lVar5 = syscall(0xba);
          FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n",
                       "DEBUG",lVar5,"dmal/common/common_ids.c",0x13c,local_9c);
        }
        strncpy(param_3,local_9c,0x11);
        if (*param_3 != '\0') {
          return uVar4;
        }
        return 3;
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
    else if (iVar3 == 0xf) {
      return 0xf;
    }
  }
  return 999;
}


// ===== 0021a350 FUN_0021a350 =====

undefined4 FUN_0021a350(long param_1,long param_2,char *param_3,uint param_4)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  undefined8 *puVar6;
  float fVar7;
  undefined4 local_bc;
  undefined8 local_b8 [14];
  char local_45 [29];
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  puVar6 = local_b8;
  for (lVar5 = 0x11; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  if (0x13 < param_4) {
    lVar5 = *(long *)(param_2 + 0x256d8);
    if (((lVar5 != 0) && (*(undefined8 **)(lVar5 + 0x50) != (undefined8 *)0x0)) &&
       (pcVar2 = (code *)**(undefined8 **)(lVar5 + 0x50), pcVar2 != (code *)0x0)) {
      iVar3 = (*pcVar2)(lVar5,param_2,0x2080,&local_bc);
      if (iVar3 == 0) {
        uVar4 = FUN_0019c780(uVar1,DAT_0038088c,local_bc,0x2080013f,local_b8,0x88,0);
        switch(uVar4) {
        case 0:
          if (4 < DAT_01216a78) {
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar5 = syscall(0xba);
            FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n",
                         "DEBUG",lVar5,"dmal/common/common_ids.c",0xcf,local_45);
          }
          strncpy(param_3,local_45,0x14);
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
      else if (iVar3 == 0xf) {
        return 0xf;
      }
    }
    return 999;
  }
  return 7;
}


// ===== 0021a530 FUN_0021a530 =====

undefined8 FUN_0021a530(undefined8 param_1,int param_2,undefined4 *param_3)

{
  uint uVar1;
  ulong uVar2;
  int *piVar3;
  
  if (param_3 == (undefined4 *)0x0) {
    return 2;
  }
  uVar2 = 0;
  piVar3 = &DAT_003a5f78;
  if (DAT_01214898 != 0) {
    do {
      if (param_2 == *piVar3) {
        *param_3 = (&DAT_0038089c)[uVar2 * 0x1d280];
        return 0;
      }
      uVar1 = (int)uVar2 + 1;
      uVar2 = (ulong)uVar1;
      piVar3 = piVar3 + 0x1d280;
    } while (uVar1 != DAT_01214898);
  }
  return 6;
}


// ===== 0021a590 FUN_0021a590 =====

undefined4 FUN_0021a590(long param_1,long param_2,char *param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  size_t sVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined4 local_13c;
  undefined4 local_138 [32];
  undefined8 local_b8 [3];
  char acStack_a0 [4];
  char local_9c [43];
  char local_71 [5];
  undefined4 local_6c;
  char local_5d [3];
  byte local_5a;
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  puVar7 = local_b8;
  for (lVar6 = 0x11; lVar6 != 0; lVar6 = lVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  lVar6 = *(long *)(param_2 + 0x256d8);
  if (((lVar6 == 0) || (*(undefined8 **)(lVar6 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar6 + 0x50), pcVar2 == (code *)0x0)) {
switchD_0021a669_caseD_1:
    uVar4 = 999;
  }
  else {
    iVar3 = (*pcVar2)(lVar6,param_2,0x2080,&local_13c);
    if (iVar3 != 0) {
      if (iVar3 == 0xf) {
        return 0xf;
      }
      goto switchD_0021a669_caseD_1;
    }
    uVar4 = FUN_0019c780(uVar1,DAT_0038088c,local_13c,0x2080013f,local_b8,0x88,0);
    switch(uVar4) {
    case 0:
      iVar3 = isalpha((uint)local_5a);
      if ((iVar3 != 0) && (sVar5 = strlen(local_71), 10 < sVar5)) {
        local_138[0] = local_6c;
        sVar5 = strlen((char *)local_138);
        *(undefined2 *)((long)local_138 + sVar5) = 0x2d;
        sVar5 = strlen(local_5d);
        if (3 < sVar5) {
          strncat((char *)local_138,local_5d,3);
          sVar5 = strlen((char *)local_138);
          *(undefined2 *)((long)local_138 + sVar5) = 0x2d;
          sVar5 = strlen(local_9c);
          if (3 < sVar5) {
            strncat((char *)local_138,acStack_a0 + sVar5,4);
            strcpy(param_3,(char *)local_138);
            return uVar4;
          }
        }
      }
    case 0x56:
      uVar4 = 3;
      break;
    default:
      goto switchD_0021a669_caseD_1;
    case 3:
    case 0x66:
      uVar4 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      uVar4 = 0x13;
      break;
    case 0x1a:
      uVar4 = 0x17;
      break;
    case 0x1b:
      uVar4 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
      uVar4 = 2;
      break;
    case 0x51:
      uVar4 = 0x14;
      break;
    case 0x55:
      uVar4 = 0x1b;
      break;
    case 0x59:
      uVar4 = 0x11;
      break;
    case 0x62:
      uVar4 = 0x10;
    }
  }
  return uVar4;
}


// ===== 0021a790 FUN_0021a790 =====

int FUN_0021a790(long param_1,char *param_2,int *param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  float fVar7;
  double dVar8;
  undefined8 uVar9;
  char local_27d;
  undefined4 local_27c;
  undefined8 local_278;
  undefined4 local_270;
  undefined4 local_26c;
  undefined4 local_268;
  
  puVar5 = &local_278;
  for (lVar4 = 0x46; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined4 *)puVar5 = 0;
  if ((param_2 == (char *)0x0) ||
     ((*param_2 != '\x01' &&
      ((((*(int *)(param_2 + 0x14) == 0 || (*(int *)(param_2 + 0x1c) != 0)) ||
        (*(int *)(param_2 + 0x10) == 0)) || (*(long *)(param_2 + 0x20) == 0)))))) {
    iVar2 = 2;
LAB_0021a957:
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    uVar9 = 0x2cd;
    uVar6 = 0x2cd;
    dVar8 = (double)(fVar7 * DAT_00298548);
LAB_0021a9a7:
    FUN_002340f0(dVar8,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
                 "dmal/common/common_ids.c",uVar6,"cDeviceGetPdi",uVar9,iVar2);
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
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar7 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tisArchOrNewer called: %d %d\n","DEBUG",
                     lVar4,"/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h",0x3d,7,
                     uVar3);
      }
      if (*param_3 == 0x1000010) {
        if (*(uint *)(param_2 + 0x708) < 7) {
switchD_0021acc7_caseD_56:
          return 3;
        }
        lVar4 = *(long *)(param_2 + 0x256d8);
        if (((lVar4 == 0) || (*(long *)(lVar4 + 0x38) == 0)) ||
           (pcVar1 = *(code **)(*(long *)(lVar4 + 0x38) + 0x88), pcVar1 == (code *)0x0)) {
          iVar2 = 3;
        }
        else {
          iVar2 = (*pcVar1)(lVar4,param_2,&local_27d);
          if (iVar2 == 0) {
            if (local_27d != '\0') {
              return 3;
            }
            lVar4 = *(long *)(param_2 + 0x256d8);
            if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
               (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)) {
              iVar2 = 3;
            }
            else {
              iVar2 = (*pcVar1)(lVar4,param_2,0x2080,&local_27c);
              if (iVar2 == 0) {
                local_26c = 0x24;
                local_278 = 0x2300000002;
                iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_27c,
                                     0x20800102,&local_278,0x234,0);
                switch(iVar2) {
                case 0:
                  *(ulong *)(param_3 + 2) = CONCAT44(local_268,local_270);
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
                  goto switchD_0021acc7_caseD_56;
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
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            uVar9 = 0x2e2;
            uVar6 = 0x2e2;
            dVar8 = (double)(fVar7 * DAT_00298548);
            goto LAB_0021a9a7;
          }
        }
        if (DAT_01216a78 < 2) {
          return iVar2;
        }
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        uVar9 = 0x2db;
        uVar6 = 0x2db;
        dVar8 = (double)(fVar7 * DAT_00298548);
        goto LAB_0021a9a7;
      }
    }
    else {
      if (*(int *)(param_2 + 0x724) == 0xf) {
        iVar2 = 0xf;
        if (4 < DAT_01216a78) {
          fVar7 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar7 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tisArchOrNewer error: %d\n","DEBUG",lVar4,
                       "/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h",0x42,7);
        }
        goto LAB_0021a957;
      }
      if (1 < DAT_01216a78) {
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar7 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tFailure to determine Architecture\n",
                     "ERROR",lVar4,"/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h"
                     ,0x46);
      }
      if (*param_3 == 0x1000010) {
        return 3;
      }
    }
    iVar2 = 0x19;
  }
  return iVar2;
}


// ===== 0021ad70 FUN_0021ad70 =====

int FUN_0021ad70(long param_1,long param_2,void *param_3,uint param_4)

{
  undefined8 uVar1;
  code *pcVar2;
  undefined1 auVar3 [16];
  int iVar4;
  size_t sVar5;
  long lVar6;
  undefined4 uVar7;
  float fVar8;
  undefined4 local_8c;
  undefined1 local_88 [16];
  undefined1 local_78 [16];
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined4 local_48;
  
  if (*(int *)(param_2 + 0x78) != 0) goto LAB_0021adc7;
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  do {
    iVar4 = FUN_00291820(param_2 + 0x7c,1,0);
  } while (iVar4 != 0);
  if (*(int *)(param_2 + 0x78) == 0) {
    local_48 = 0;
    local_88 = (undefined1  [16])0x0;
    local_78 = (undefined1  [16])0x0;
    local_68 = (undefined1  [16])0x0;
    local_58 = (undefined1  [16])0x0;
    lVar6 = *(long *)(param_2 + 0x256d8);
    if (((lVar6 == 0) || (*(undefined8 **)(lVar6 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar2 = (code *)**(undefined8 **)(lVar6 + 0x50), pcVar2 == (code *)0x0)) {
LAB_0021aed0:
      uVar7 = 999;
    }
    else {
      iVar4 = (*pcVar2)(lVar6,param_2,0x2080,&local_8c);
      if (iVar4 == 0) {
        auVar3._12_4_ = 0;
        auVar3._0_12_ = local_88._4_12_;
        local_88 = auVar3 << 0x20;
        iVar4 = FUN_0019c780(uVar1,DAT_0038088c,local_8c,0x20800110,local_88,0x44,0);
        if (iVar4 == 0) {
          if (4 < DAT_01216a78) {
            fVar8 = (float)FUN_002917b0(&DAT_01216a60);
            lVar6 = syscall(0xba);
            FUN_002340f0((double)(fVar8 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n",
                         "DEBUG",lVar6,"dmal/common/common_ids.c",0x2b);
          }
          strcpy((char *)(param_2 + 0x38),local_88 + 4);
          uVar7 = 0;
          if (*(char *)(param_2 + 0x38) != '\0') goto LAB_0021aed6;
        }
        else if (iVar4 == 0xf) goto LAB_0021ae7e;
        goto LAB_0021aed0;
      }
      if (iVar4 != 0xf) goto LAB_0021aed0;
LAB_0021ae7e:
      uVar7 = 0xf;
    }
LAB_0021aed6:
    *(undefined4 *)(param_2 + 0x80) = uVar7;
    *(undefined4 *)(param_2 + 0x78) = 1;
  }
  FUN_00291830(param_2 + 0x7c,0);
LAB_0021adc7:
  iVar4 = *(int *)(param_2 + 0x80);
  if (iVar4 == 0) {
    sVar5 = strlen((char *)(param_2 + 0x38));
    if ((ulong)param_4 < sVar5 + 1) {
      iVar4 = 7;
    }
    else {
      memcpy(param_3,(char *)(param_2 + 0x38),sVar5 + 1);
    }
  }
  return iVar4;
}


// ===== 0021af90 FUN_0021af90 =====

undefined8 FUN_0021af90(undefined8 param_1,long param_2,undefined1 *param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  
  if (*(int *)(param_2 + 0x70534) == 0) {
    do {
      iVar3 = FUN_00291820(param_2 + 0x70538,1,0);
    } while (iVar3 != 0);
    if (*(int *)(param_2 + 0x70534) == 0) {
      lVar1 = *(long *)(param_2 + 0x256d8);
      uVar4 = 3;
      if (((lVar1 != 0) && (*(long *)(lVar1 + 0x38) != 0)) &&
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x38) + 8), pcVar2 != (code *)0x0)) {
        uVar4 = (*pcVar2)(lVar1,param_2,param_2 + 0x70530);
      }
      *(undefined4 *)(param_2 + 0x7053c) = uVar4;
      *(undefined4 *)(param_2 + 0x70534) = 1;
    }
    FUN_00291830(param_2 + 0x70538,0);
  }
  bVar5 = false;
  if (*(int *)(param_2 + 0x7053c) == 0) {
    bVar5 = *(int *)(param_2 + 0x70530) == 3;
  }
  *param_3 = bVar5;
  return 0;
}


// ===== 0021b060 FUN_0021b060 =====

undefined8 FUN_0021b060(undefined8 param_1,long param_2,undefined1 *param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  
  if (*(int *)(param_2 + 0x70534) == 0) {
    do {
      iVar3 = FUN_00291820(param_2 + 0x70538,1,0);
    } while (iVar3 != 0);
    if (*(int *)(param_2 + 0x70534) == 0) {
      lVar1 = *(long *)(param_2 + 0x256d8);
      uVar4 = 3;
      if (((lVar1 != 0) && (*(long *)(lVar1 + 0x38) != 0)) &&
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x38) + 8), pcVar2 != (code *)0x0)) {
        uVar4 = (*pcVar2)(lVar1,param_2,param_2 + 0x70530);
      }
      *(undefined4 *)(param_2 + 0x7053c) = uVar4;
      *(undefined4 *)(param_2 + 0x70534) = 1;
    }
    FUN_00291830(param_2 + 0x70538,0);
  }
  bVar5 = false;
  if (*(int *)(param_2 + 0x7053c) == 0) {
    bVar5 = *(int *)(param_2 + 0x70530) == 2;
  }
  *param_3 = bVar5;
  return 0;
}


// ===== 0021b130 FUN_0021b130 =====

int FUN_0021b130(long param_1,long param_2,void *param_3,uint param_4)

{
  undefined8 uVar1;
  int iVar2;
  undefined4 uVar3;
  size_t sVar4;
  long lVar5;
  float fVar6;
  
  if (*(int *)(param_2 + 0x374) == 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x10);
    do {
      iVar2 = FUN_00291820(param_2 + 0x378,1,0);
    } while (iVar2 != 0);
    if (*(int *)(param_2 + 0x374) == 0) {
      uVar3 = FUN_00219f70(uVar1,param_2,param_2 + 0x274);
      *(undefined4 *)(param_2 + 0x374) = 1;
      *(undefined4 *)(param_2 + 0x37c) = uVar3;
    }
    FUN_00291830(param_2 + 0x378,0);
  }
  iVar2 = *(int *)(param_2 + 0x37c);
  if (iVar2 == 0) {
    sVar4 = strlen((char *)(param_2 + 0x274));
    if ((ulong)param_4 < sVar4 + 1) {
      iVar2 = 7;
    }
    else {
      memcpy(param_3,(char *)(param_2 + 0x274),sVar4 + 1);
    }
  }
  else if (1 < DAT_01216a78) {
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar5,"dmal/common/common_ids.c",0x182,"cDeviceGetUUID",0x182,iVar2);
  }
  return iVar2;
}


// ===== 0021b290 FUN_0021b290 =====

int FUN_0021b290(undefined8 param_1,long param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  float fVar5;
  
  if (param_3 == (undefined8 *)0x0) {
    return 2;
  }
  if (*(int *)(param_2 + 0x390) == 0) {
    do {
      iVar2 = FUN_00291820(param_2 + 0x394,1,0);
    } while (iVar2 != 0);
    if (*(int *)(param_2 + 0x390) == 0) {
      uVar3 = FUN_00219630(param_1,param_2,param_2 + 0x380);
      *(undefined4 *)(param_2 + 0x390) = 1;
      *(undefined4 *)(param_2 + 0x398) = uVar3;
    }
    FUN_00291830(param_2 + 0x394,0);
    iVar2 = *(int *)(param_2 + 0x398);
  }
  else {
    iVar2 = *(int *)(param_2 + 0x398);
  }
  if (iVar2 == 0) {
    uVar1 = *(undefined8 *)(param_2 + 0x388);
    *param_3 = *(undefined8 *)(param_2 + 0x380);
    param_3[1] = uVar1;
  }
  else if (1 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_ids.c",0x1ba,"cDeviceGetUUIDBin",0x1ba,iVar2);
    return iVar2;
  }
  return iVar2;
}


// ===== 0021b410 FUN_0021b410 =====

int FUN_0021b410(long param_1,long param_2,int *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  char local_35;
  undefined4 local_34;
  undefined8 local_30;
  
  local_30 = 0;
  local_34 = 0;
  if (param_3 == (int *)0x0) {
switchD_0021b522_caseD_1f:
    return 2;
  }
  if (*param_3 != 0x1000008) {
    return 0x19;
  }
  lVar3 = *(long *)(param_2 + 0x256d8);
  local_35 = '\0';
  if (lVar3 != 0) {
    if ((*(long *)(lVar3 + 0x30) != 0) &&
       (pcVar1 = *(code **)(*(long *)(lVar3 + 0x30) + 0x148), pcVar1 != (code *)0x0)) {
      (*pcVar1)(lVar3,param_2,&local_35);
      if (local_35 != '\0') {
        return 3;
      }
      lVar3 = *(long *)(param_2 + 0x256d8);
    }
    if (((lVar3 != 0) && (*(undefined8 **)(lVar3 + 0x50) != (undefined8 *)0x0)) &&
       (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 != (code *)0x0)) {
      iVar2 = (*pcVar1)(lVar3,param_2,0x80,&local_34);
      if (iVar2 == 0) {
        local_30 = CONCAT44(0xffffffff,(undefined4)local_30);
        iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_34,&DAT_00800298,
                             &local_30,8,0);
        switch(iVar2) {
        case 0:
          param_3[1] = (uint)(byte)local_30;
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
          goto switchD_0021b522_caseD_1f;
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
      goto LAB_0021b52e;
    }
  }
  iVar2 = 3;
LAB_0021b52e:
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_ids.c",0x28e,"cDeviceGetGpuHeterogeneousMode",0x28e
               ,iVar2);
  return iVar2;
}


// ===== 0021b650 FUN_0021b650 =====

/* WARNING: Type propagation algorithm not settling */

uint FUN_0021b650(long param_1,long param_2,uint *param_3,void *param_4)

{
  undefined4 uVar1;
  undefined8 uVar2;
  code *pcVar3;
  uint uVar4;
  long lVar5;
  uint *puVar6;
  uint uVar7;
  float fVar8;
  undefined4 local_36c;
  uint local_368;
  undefined1 local_364 [820];
  
  uVar2 = *(undefined8 *)(param_1 + 0x10);
  puVar6 = &local_368;
  for (lVar5 = 100; lVar5 != 0; lVar5 = lVar5 + -1) {
    puVar6[0] = 0;
    puVar6[1] = 0;
    puVar6 = puVar6 + 2;
  }
  *puVar6 = 0;
  lVar5 = *(long *)(param_2 + 0x256d8);
  if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar3 = (code *)**(undefined8 **)(lVar5 + 0x50), pcVar3 == (code *)0x0)) {
switchD_0021b739_caseD_1:
    uVar4 = 999;
  }
  else {
    uVar4 = (*pcVar3)(lVar5,param_2,0x80,&local_36c);
    if (uVar4 != 0) {
      if (uVar4 == 0xf) {
        return 0xf;
      }
      goto switchD_0021b739_caseD_1;
    }
    uVar4 = FUN_0019c780(uVar2,DAT_0038088c,local_36c,&DAT_00800292,&local_368,0x324,0);
    switch(uVar4) {
    case 0:
      if (param_4 == (void *)0x0) {
        *param_3 = local_368;
        if (DAT_01216a78 < 4) {
          return uVar4;
        }
        fVar8 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        FUN_002340f0((double)(fVar8 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n",
                     &DAT_002983c2,lVar5,"dmal/common/common_interface.c",0xe7,local_368);
        return uVar4;
      }
      if (local_368 <= *param_3) {
        *param_3 = local_368;
        memcpy(param_4,local_364,(ulong)local_368 << 2);
        if (3 < DAT_01216a78) {
          uVar7 = *param_3;
          fVar8 = (float)FUN_002917b0(&DAT_01216a60);
          lVar5 = syscall(0xba);
          FUN_002340f0((double)(fVar8 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n",
                       &DAT_002983c2,lVar5,"dmal/common/common_interface.c",0xe7,uVar7);
        }
        uVar7 = uVar4;
        if (*param_3 == 0) {
          return uVar4;
        }
        do {
          if (3 < DAT_01216a78) {
            uVar1 = *(undefined4 *)((long)param_4 + (ulong)uVar7 * 4);
            fVar8 = (float)FUN_002917b0(&DAT_01216a60);
            lVar5 = syscall(0xba);
            FUN_002340f0((double)(fVar8 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04X\n",
                         &DAT_002983c2,lVar5,"dmal/common/common_interface.c",0xed,uVar1);
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < *param_3);
        return uVar4;
      }
    case 0x1f:
    case 0x3b:
    case 0x54:
      uVar4 = 2;
      break;
    default:
      goto switchD_0021b739_caseD_1;
    case 3:
    case 0x66:
      uVar4 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      uVar4 = 0x13;
      break;
    case 0x1a:
      uVar4 = 0x17;
      break;
    case 0x1b:
      uVar4 = 4;
      break;
    case 0x51:
      uVar4 = 0x14;
      break;
    case 0x55:
      uVar4 = 0x1b;
      break;
    case 0x56:
      uVar4 = 3;
      break;
    case 0x59:
      uVar4 = 0x11;
      break;
    case 0x62:
      uVar4 = 0x10;
    }
  }
  return uVar4;
}


// ===== 0021b970 FUN_0021b970 =====

void FUN_0021b970(long param_1,long param_2,ulong param_3,uint *param_4)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  undefined8 uVar4;
  int iVar5;
  uint *__ptr;
  long lVar6;
  uint *puVar7;
  float fVar8;
  uint local_3c [3];
  
  if (*(int *)(param_2 + 0x25718) == 0) {
    lVar1 = param_2 + 0x2571c;
    do {
      iVar5 = FUN_00291820(lVar1,1,0);
    } while (iVar5 != 0);
    if (*(int *)(param_2 + 0x25718) == 0) {
      local_3c[0] = 0;
      if (((param_1 == 0) || (*(long *)(param_1 + 0x58) == 0)) ||
         (pcVar3 = *(code **)(*(long *)(param_1 + 0x58) + 8), pcVar3 == (code *)0x0)) {
        iVar5 = 3;
      }
      else {
        iVar5 = (*pcVar3)(param_1,param_2,local_3c,0);
        if (iVar5 == 0) {
          __ptr = calloc((ulong)local_3c[0],4);
          if (__ptr == (uint *)0x0) {
            iVar5 = 0x14;
          }
          else {
            if ((*(long *)(param_1 + 0x58) == 0) ||
               (pcVar3 = *(code **)(*(long *)(param_1 + 0x58) + 8), pcVar3 == (code *)0x0)) {
              iVar5 = 3;
            }
            else {
              iVar5 = (*pcVar3)(param_1,param_2,local_3c,__ptr);
              if (iVar5 == 0) {
                *(undefined8 *)(param_2 + 0x25710) = 0;
                if (local_3c[0] != 0) {
                  puVar7 = __ptr;
                  do {
                    uVar2 = *puVar7;
                    if (uVar2 == 0xc3e0) {
                      *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 0x800;
                    }
                    else if (uVar2 < 0xc3e1) {
                      if (uVar2 == 0xa0e1) {
                        *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 8;
                      }
                      else if (uVar2 < 0xa0e2) {
                        if (uVar2 == 0x90e1) {
                          *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 2;
                        }
                        else if (uVar2 < 0x90e2) {
                          if (uVar2 == 0x2081) {
                            *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 0x200000
                            ;
                          }
                          else if (uVar2 == 0x90e0) {
                            *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 1;
                          }
                        }
                        else if (uVar2 == 0x90e7) {
                          *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 0x100000;
                        }
                        else if (uVar2 == 0xa0e0) {
                          *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 4;
                        }
                      }
                      else if (uVar2 == 0xc0e1) {
                        *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 0x20;
                      }
                      else if (uVar2 < 0xc0e2) {
                        if (uVar2 == 0xc0c0) {
                          *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 0x40;
                        }
                        else if (uVar2 == 0xc0e0) {
                          *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 0x10;
                        }
                      }
                      else if (uVar2 == 0xc1c0) {
                        *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 0x80;
                      }
                      else if (uVar2 == 0xc3c0) {
                        *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 0x100;
                      }
                    }
                    else if (uVar2 == 0xc9c0) {
                      *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 0x40000;
                    }
                    else if (uVar2 < 0xc9c1) {
                      if (uVar2 == 0xc5c0) {
                        *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 0x2000;
                      }
                      else if (uVar2 < 0xc5c1) {
                        if (uVar2 == 0xc3e1) {
                          *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 0x1000;
                        }
                        else if (uVar2 == 0xc4c0) {
                          *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 0x200;
                        }
                      }
                      else if (uVar2 == 0xc6c0) {
                        *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 0x4000;
                      }
                      else if (uVar2 == 0xc7c0) {
                        *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 0x8000;
                      }
                    }
                    else if (uVar2 == 0xcdc0) {
                      *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 0x80000;
                    }
                    else if (uVar2 < 0xcdc1) {
                      if (uVar2 == 0xcbc0) {
                        *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 0x10000;
                      }
                      else if (uVar2 == 0xccc0) {
                        *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 0x20000;
                      }
                    }
                    else if (uVar2 == 0xcec0) {
                      *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 0x400000;
                    }
                    else if (uVar2 == 0xd0c0) {
                      *(ulong *)(param_2 + 0x25710) = *(ulong *)(param_2 + 0x25710) | 0x800000;
                    }
                    puVar7 = puVar7 + 1;
                  } while (__ptr + local_3c[0] != puVar7);
                }
                if (4 < DAT_01216a78) {
                  uVar4 = *(undefined8 *)(param_2 + 0x25710);
                  fVar8 = (float)FUN_002917b0(&DAT_01216a60);
                  lVar6 = syscall(0xba);
                  FUN_002340f0((double)(fVar8 * DAT_00298548),
                               "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%llX\n","DEBUG",lVar6,
                               "dmal/common/common_interface.c",0x99,uVar4);
                }
              }
            }
            free(__ptr);
          }
        }
      }
      *(undefined4 *)(param_2 + 0x25718) = 1;
      *(int *)(param_2 + 0x25720) = iVar5;
      FUN_00291830(lVar1,0);
    }
    else {
      FUN_00291830(lVar1,0);
    }
  }
  if (*(int *)(param_2 + 0x25720) == 0) {
    *param_4 = (uint)((param_3 & *(ulong *)(param_2 + 0x25710)) != 0);
  }
  return;
}


// ===== 0021be40 FUN_0021be40 =====

int FUN_0021be40(long param_1,long param_2)

{
  if (*(int *)(param_1 + 8) != *(int *)(param_2 + 8)) {
    return *(int *)(param_1 + 8) - *(int *)(param_2 + 8);
  }
  return *(int *)(param_1 + 0x10) - *(int *)(param_2 + 0x10);
}


// ===== 0021be60 FUN_0021be60 =====

int FUN_0021be60(int *param_1,int *param_2)

{
  return *param_1 - *param_2;
}


// ===== 0021be70 FUN_0021be70 =====

undefined8 FUN_0021be70(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *param_2;
  (**(code **)(*(long *)(param_1 + 0x10) + 0x28))(uVar1,uVar1,uVar1);
  return 0;
}


// ===== 0021be90 FUN_0021be90 =====

undefined8 FUN_0021be90(undefined8 param_1,long param_2,undefined1 *param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  int local_20;
  undefined1 local_1c [12];
  
  lVar1 = *(long *)(param_2 + 0x256d8);
  if ((((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0x30) != (undefined8 *)0x0)) &&
      (pcVar2 = (code *)**(undefined8 **)(lVar1 + 0x30), pcVar2 != (code *)0x0)) &&
     (iVar3 = (*pcVar2)(lVar1,param_2,&local_20,local_1c), iVar3 == 0)) {
    *param_3 = local_20 == 1;
    return 0;
  }
  *param_3 = 0;
  return 0;
}


// ===== 0021bf00 FUN_0021bf00 =====

uint FUN_0021bf00(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long lVar2;
  code *pcVar3;
  uint uVar4;
  long lVar5;
  undefined8 extraout_RDX;
  ulong uVar6;
  float fVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  undefined8 local_38;
  
  lVar5 = *(long *)(param_1 + 0x256d8);
  local_74 = 0;
  lVar2 = *(long *)(lVar5 + 0x10);
  local_38 = 0;
  local_68 = (undefined1  [16])0x0;
  local_58 = (undefined1  [16])0x0;
  local_48 = (undefined1  [16])0x0;
  if ((*(long *)(lVar5 + 0x60) == 0) ||
     (pcVar3 = *(code **)(*(long *)(lVar5 + 0x60) + 0x18), pcVar3 == (code *)0x0)) {
    uVar4 = 3;
LAB_0021bfde:
    if (1 < DAT_01216a78) {
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      fVar7 = fVar7 * DAT_00298548;
      uVar8 = 0xa4;
      uVar9 = 0xa4;
LAB_0021c045:
      FUN_002340f0((double)fVar7,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,
                   "dmal/common/common_mig.c",uVar9,"cAllocateMigClient",uVar8,uVar4);
      return uVar4;
    }
  }
  else {
    uVar4 = (*pcVar3)(lVar5,param_1,&local_70);
    if (uVar4 != 0) goto LAB_0021bfde;
    lVar5 = *(long *)(param_1 + 0x256d8);
    if (((lVar5 == 0) || (*(long *)(lVar5 + 0x60) == 0)) ||
       (pcVar3 = *(code **)(*(long *)(lVar5 + 0x60) + 0x10), pcVar3 == (code *)0x0)) {
      uVar4 = 3;
LAB_0021c086:
      if (DAT_01216a78 < 2) {
        return uVar4;
      }
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      fVar7 = fVar7 * DAT_00298548;
      uVar8 = 0xa7;
      uVar9 = 0xa7;
      goto LAB_0021c045;
    }
    uVar4 = (*pcVar3)(lVar5,param_1,&local_6c);
    if (uVar4 != 0) goto LAB_0021c086;
    uVar9 = 0x21bfb7;
    uVar4 = (**(code **)(lVar2 + 8))(param_2);
    switch(uVar4) {
    case 0:
      uVar1 = *param_2;
      local_68._4_4_ = uVar1;
      local_68._0_4_ = local_70;
      local_38 = CONCAT44(local_38._4_4_,2);
      uVar4 = (**(code **)(lVar2 + 0x10))(param_1,uVar1,uVar1,1,0x80,local_68,0x38);
      uVar6 = (ulong)uVar4;
      if (uVar4 == 0) {
        uVar8 = 4;
        local_74 = local_6c;
        uVar4 = (**(code **)(lVar2 + 0x10))(param_1,*param_2,1,2,0x2080,&local_74);
        uVar6 = (ulong)uVar4;
        if (uVar4 == 0) {
          return 0;
        }
        if (1 < DAT_01216a78) {
          fVar7 = (float)FUN_002917b0(&DAT_01216a60,uVar9,extraout_RDX,uVar8);
          lVar5 = syscall(0xba);
          fVar7 = fVar7 * DAT_00298548;
          uVar9 = 0xbe;
LAB_0021c254:
          FUN_002340f0((double)fVar7,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %x\n","ERROR",lVar5,
                       "dmal/common/common_mig.c",uVar9,local_6c,uVar6);
        }
      }
      else if (1 < DAT_01216a78) {
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        fVar7 = fVar7 * DAT_00298548;
        uVar9 = 0xb4;
        local_6c = local_70;
        goto LAB_0021c254;
      }
      uVar1 = *param_2;
      (**(code **)(lVar2 + 0x28))(uVar1,uVar1,uVar1);
      if ((uint)uVar6 < 0x67) {
        return (uint)*(ushort *)(&DAT_002d4b40 + uVar6 * 2);
      }
    default:
      uVar4 = 999;
      break;
    case 3:
    case 0x66:
      uVar4 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      uVar4 = 0x13;
      break;
    case 0x1a:
      uVar4 = 0x17;
      break;
    case 0x1b:
      uVar4 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
      uVar4 = 2;
      break;
    case 0x51:
      uVar4 = 0x14;
      break;
    case 0x55:
      uVar4 = 0x1b;
      break;
    case 0x56:
      uVar4 = 3;
      break;
    case 0x59:
      uVar4 = 0x11;
      break;
    case 0x62:
      uVar4 = 0x10;
    }
  }
  return uVar4;
}


// ===== 0021c2c0 FUN_0021c2c0 =====

undefined8 FUN_0021c2c0(long param_1,ulong param_2,undefined4 param_3)

{
  int iVar1;
  long lVar2;
  float fVar3;
  undefined8 local_20 [2];
  
  local_20[0] = 0;
  iVar1 = (**(code **)(*(long *)(param_1 + 0x10) + 0x10))
                    (&DAT_00380898,param_2,param_2 & 0xffffffff,param_3,0xc640,local_20);
  if ((iVar1 != 0) && (4 < DAT_01216a78)) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n","DEBUG",
                 lVar2,"dmal/common/common_mig.c",0xbe3,iVar1);
    return 0;
  }
  return 0;
}


// ===== 0021c380 FUN_0021c380 =====

undefined8 FUN_0021c380(long param_1,ulong param_2,undefined4 param_3)

{
  int iVar1;
  long lVar2;
  float fVar3;
  undefined8 local_20 [2];
  
  local_20[0] = 0;
  iVar1 = (**(code **)(*(long *)(param_1 + 0x10) + 0x10))
                    (&DAT_00380898,param_2,param_2 & 0xffffffff,param_3,0xc639,local_20);
  if ((iVar1 != 0) && (4 < DAT_01216a78)) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n","DEBUG",
                 lVar2,"dmal/common/common_mig.c",0xbc9,iVar1);
    return 0;
  }
  return 0;
}


// ===== 0021c440 FUN_0021c440 =====

uint FUN_0021c440(long param_1,long param_2,undefined8 param_3)

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
      uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_2c[0],0x20800185,
                           param_3,0x1688,0);
      if (0x66 < uVar2) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002d4c20 + (ulong)uVar2 * 2);
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar2;
  }
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_mig.c",0x1e1,
               "cDeviceGetGpuInstanceProfilesUncached",0x1e1,uVar2);
  return uVar2;
}


// ===== 0021c5b0 FUN_0021c5b0 =====

uint FUN_0021c5b0(long param_1,long param_2,undefined4 param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  undefined8 *puVar4;
  float fVar5;
  undefined4 local_1bc;
  undefined8 local_1b8;
  undefined4 local_1b0;
  undefined1 local_198;
  
  local_1bc = 0;
  puVar4 = &local_1b8;
  for (lVar3 = 0x31; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    uVar2 = 3;
  }
  else {
    uVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_1bc);
    if (uVar2 == 0) {
      local_1b8._0_4_ = 1;
      local_198 = 0;
      local_1b0 = param_3;
      uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_1bc,0x20800174,
                           &local_1b8,0x188,0);
      if (0x66 < uVar2) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002d4c20 + (ulong)uVar2 * 2);
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_mig.c",0x5ff,"cDeviceDestroyGpuInstance",0x5ff,
               uVar2);
  return uVar2;
}


// ===== 0021c760 FUN_0021c760 =====

int FUN_0021c760(long param_1,long param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  float fVar5;
  undefined4 local_14c;
  undefined8 local_148 [17];
  int local_bc;
  undefined4 local_b8;
  
  local_14c = 0;
  puVar4 = local_148;
  for (lVar3 = 0x23; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_14c);
    if (iVar2 == 0) {
      local_148[0]._0_4_ = 5;
      iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_14c,0x20800181,
                           local_148,0x118,0);
      if (iVar2 != 0x56) {
        switch(iVar2) {
        case 0:
          if (local_bc != 1) break;
          *param_3 = local_b8;
switchD_0021c8ce_caseD_f:
          return iVar2;
        default:
          return 999;
        case 3:
        case 0x66:
          return 10;
        case 0xf:
          goto switchD_0021c8ce_caseD_f;
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
      *param_3 = 0;
      return 0;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_mig.c",0x4cd,
               "cDeviceGetGpuInstancePlacementStartAdjustUncached",0x4cd,iVar2);
  return iVar2;
}


// ===== 0021c990 FUN_0021c990 =====

uint FUN_0021c990(long param_1,long param_2,int param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  float fVar4;
  undefined4 local_30;
  int local_2c [3];
  
  local_2c[0] = 0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    uVar2 = 3;
  }
  else {
    uVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_30);
    if (uVar2 == 0) {
      local_2c[0] = (uint)(param_3 == 1) * 2;
      uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_30,0x20800183,local_2c
                           ,4,0);
      if (uVar2 == 0x10006) {
        return 0;
      }
      if (0x66 < uVar2) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002d4c20 + (ulong)uVar2 * 2);
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar2;
  }
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_mig.c",0x11e,"cDeviceSetMigMode",0x11e,uVar2);
  return uVar2;
}


// ===== 0021cb00 FUN_0021cb00 =====

int FUN_0021cb00(long param_1,char *param_2,undefined4 *param_3,undefined4 *param_4)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined8 *puVar5;
  float fVar6;
  undefined4 local_27c;
  undefined8 local_278;
  undefined4 local_270;
  
  cVar1 = *param_2;
  puVar5 = &local_278;
  for (lVar4 = 0x46; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined4 *)puVar5 = 0;
  if (cVar1 == '\x01') {
    *param_3 = 0;
    *param_4 = 0;
    return 0;
  }
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    iVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_27c);
    if (iVar3 == 0) {
      local_278 = 0x2a00000001;
      iVar3 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_27c,0x20800102,
                           &local_278,0x234,0);
      switch(iVar3) {
      case 0:
        goto code_r0x0021ccb9;
      default:
switchD_0021cbde_caseD_f:
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
switchD_0021cbde_caseD_f:
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
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_mig.c",0xb96,"cDeviceGetMigMode",0xb96,iVar3);
  }
  return iVar3;
code_r0x0021ccb9:
  switch(local_270) {
  case 0:
    goto switchD_0021cbde_caseD_f;
  case 1:
    *param_3 = 1;
    *param_4 = 1;
    return iVar3;
  case 2:
    *param_3 = 0;
    *param_4 = 0;
    return iVar3;
  case 3:
    *param_3 = 0;
    *param_4 = 1;
    return iVar3;
  case 4:
    *param_3 = 1;
    *param_4 = 0;
    return iVar3;
  default:
    goto switchD_0021cbde_caseD_f;
  }
}


// ===== 0021cd60 FUN_0021cd60 =====

uint FUN_0021cd60(long param_1,long param_2,undefined8 *param_3,uint *param_4)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  void *pvVar5;
  ulong uVar6;
  int *piVar7;
  uint uVar8;
  float fVar9;
  undefined4 local_6c;
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined8 local_48;
  
  local_48 = 0;
  local_68 = (undefined1  [16])0x0;
  local_58 = (undefined1  [16])0x0;
  if ((param_3 != (undefined8 *)0x0) && (param_4 != (uint *)0x0)) {
    lVar4 = *(long *)(param_2 + 0x256d8);
    if ((lVar4 == 0) ||
       ((*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0 ||
        (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)))) {
      uVar3 = 3;
    }
    else {
      uVar3 = (*pcVar1)(lVar4,param_2,0x2080,&local_6c);
      if (uVar3 == 0) {
        piVar7 = (int *)local_68;
        uVar3 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_6c,0x2080018b,piVar7
                             ,0x28,0);
        switch(uVar3) {
        case 0:
          iVar2 = local_48._4_4_;
          pvVar5 = malloc((ulong)(uint)(local_48._4_4_ * 4));
          if (pvVar5 == (void *)0x0) {
            return 0x14;
          }
          uVar8 = 0;
          if (iVar2 != 0) {
            uVar8 = uVar3;
            do {
              if (*piVar7 != -2) {
                uVar6 = (ulong)uVar8;
                uVar8 = uVar8 + 1;
                *(int *)((long)pvVar5 + uVar6 * 4) = *piVar7;
              }
              piVar7 = piVar7 + 1;
            } while (piVar7 != (int *)(local_68 + (ulong)(iVar2 - 1) * 4 + 4));
          }
          *param_3 = pvVar5;
          *param_4 = uVar8;
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
          goto switchD_0021ce2d_caseD_1f;
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
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"dmal/common/common_mig.c",0x7b3,"cDeviceGetActiveGpuInstances",
                   0x7b3,uVar3);
    }
    return uVar3;
  }
switchD_0021ce2d_caseD_1f:
  return 2;
}


// ===== 0021cf90 FUN_0021cf90 =====

int FUN_0021cf90(undefined8 param_1,undefined8 param_2,undefined4 param_3,uint *param_4,long param_5
                )

{
  code *pcVar1;
  undefined8 uVar2;
  int iVar3;
  undefined4 *__ptr;
  undefined8 *puVar4;
  void *pvVar5;
  undefined8 *puVar6;
  uint uVar7;
  
  __ptr = malloc(0x18);
  if (__ptr == (undefined4 *)0x0) {
    return 0x14;
  }
  __ptr[1] = param_3;
  *__ptr = 0x1000018;
  __ptr[2] = 0;
  *(undefined8 *)(__ptr + 4) = 0;
  if (param_4 != (uint *)0x0) {
    uVar7 = *param_4;
    if (uVar7 != 0) {
      __ptr[2] = uVar7;
      pvVar5 = calloc((ulong)uVar7,0x20);
      *(void **)(__ptr + 4) = pvVar5;
      if (pvVar5 == (void *)0x0) {
        iVar3 = 0x14;
        goto LAB_0021d0eb;
      }
    }
  }
  if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x30) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0xf8), pcVar1 == (code *)0x0)) {
    pvVar5 = *(void **)(__ptr + 4);
    iVar3 = 3;
    *param_4 = __ptr[2];
  }
  else {
    iVar3 = (*pcVar1)(DAT_012164a0,param_2,__ptr);
    pvVar5 = *(void **)(__ptr + 4);
    uVar7 = __ptr[2];
    *param_4 = uVar7;
    if ((iVar3 == 0) && (uVar7 != 0)) {
      uVar7 = 0;
      do {
        puVar6 = (undefined8 *)((ulong)uVar7 * 0x20 + (long)pvVar5);
        uVar2 = puVar6[1];
        puVar4 = (undefined8 *)((ulong)uVar7 * 0x1020 + param_5);
        *puVar4 = *puVar6;
        puVar4[1] = uVar2;
        uVar2 = puVar6[3];
        puVar4[2] = puVar6[2];
        puVar4[3] = uVar2;
        if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0xc0) != 0)) &&
           (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0xc0) + 0x10), pcVar1 != (code *)0x0)) {
          (*pcVar1)(DAT_012164a0,*(undefined4 *)puVar4,puVar4 + 4,0x1000);
          pvVar5 = *(void **)(__ptr + 4);
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *param_4);
    }
  }
  if (pvVar5 != (void *)0x0) {
    free(pvVar5);
  }
LAB_0021d0eb:
  free(__ptr);
  return iVar3;
}


// ===== 0021d140 FUN_0021d140 =====

uint FUN_0021d140(long param_1,long param_2,undefined4 param_3,long param_4,uint *param_5)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  float fVar7;
  undefined8 uVar8;
  undefined4 local_790;
  int local_78c;
  undefined4 local_788 [58];
  undefined4 auStack_6a0 [406];
  int local_48;
  undefined1 local_44;
  
  lVar4 = *(long *)(param_2 + 0x256d8);
  local_790 = 0;
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)) {
    uVar2 = 3;
  }
  else {
    uVar2 = (*pcVar1)(lVar4,param_2,0x2080,&local_790);
    if (uVar2 == 0) {
      uVar2 = FUN_00133b70(param_3,&local_78c);
      if (uVar2 == 0) {
        local_44 = 1;
        puVar6 = local_788;
        uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_790,0x20800175,
                             puVar6,0x748,0);
        switch(uVar2) {
        case 0:
          goto switchD_0021d33f_caseD_0;
        default:
          return 999;
        case 3:
        case 0x66:
          return 10;
        case 0xf:
          return uVar2;
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
        return uVar2;
      }
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      fVar7 = fVar7 * DAT_00298548;
      uVar8 = 0x61e;
      uVar5 = 0x61e;
      goto LAB_0021d21b;
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar2;
  }
  fVar7 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  fVar7 = fVar7 * DAT_00298548;
  uVar8 = 0x61b;
  uVar5 = 0x61b;
LAB_0021d21b:
  FUN_002340f0((double)fVar7,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
               "dmal/common/common_mig.c",uVar5,"cDeviceGetGpuInstances",uVar8,uVar2);
  return uVar2;
switchD_0021d33f_caseD_0:
  uVar3 = 0;
  if (local_48 != 0) {
    uVar3 = uVar2;
    do {
      if ((*(char *)(puVar6 + 0x34) != '\0') && (puVar6[1] == local_78c)) {
        if (param_4 != 0) {
          *(undefined4 *)(param_4 + (ulong)uVar3 * 4) = *puVar6;
        }
        uVar3 = uVar3 + 1;
      }
      puVar6 = puVar6 + 0x3a;
    } while (puVar6 != auStack_6a0 + (ulong)(local_48 - 1) * 0x3a);
  }
  *param_5 = uVar3;
  return uVar2;
}


// ===== 0021d420 FUN_0021d420 =====

int FUN_0021d420(long param_1,long param_2,undefined4 param_3,int *param_4,uint *param_5)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  float fVar7;
  double dVar8;
  undefined8 uVar9;
  undefined4 local_164;
  undefined1 local_160 [3];
  byte local_15d;
  int local_15c;
  undefined8 local_158;
  uint local_cc;
  
  puVar5 = &local_158;
  for (lVar4 = 0x23; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  lVar4 = *(long *)(param_2 + 0x256d8);
  local_164 = 0;
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar4,param_2,0x2080,&local_164);
    if (iVar2 == 0) {
      uVar6 = 0x21d553;
      iVar2 = FUN_00133b70(param_3,&local_158);
      if (iVar2 == 0) {
        iVar3 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_164,0x20800181,
                             &local_158,0x118,0);
        switch(iVar3) {
        case 0:
          goto switchD_0021d62b_caseD_0;
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
        return iVar2;
      }
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      uVar9 = 0x4ab;
      uVar6 = 0x4ab;
      dVar8 = (double)(fVar7 * DAT_00298548);
      goto LAB_0021d51b;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar7 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  uVar9 = 0x4a8;
  uVar6 = 0x4a8;
  dVar8 = (double)(fVar7 * DAT_00298548);
LAB_0021d51b:
  FUN_002340f0(dVar8,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
               "dmal/common/common_mig.c",uVar6,"cDeviceGetGpuInstanceCapacity",uVar9,iVar2);
  return iVar2;
switchD_0021d62b_caseD_0:
  if (param_4 == (int *)0x0) goto LAB_0021d69f;
  *param_4 = local_158._4_4_;
  iVar2 = FUN_00133b70(param_3,local_160,iVar3,&switchD_0021d62b::switchdataD_002d3fa0,uVar6);
  if (iVar2 == 0) {
    if ((local_15d & 0x40) == 0) {
LAB_0021d69f:
      if (param_5 == (uint *)0x0) {
        return iVar3;
      }
      *param_5 = local_cc;
      if ((local_158._3_1_ & 0x40) == 0) {
        return iVar3;
      }
      *param_5 = (uint)(local_cc != 0);
      return iVar3;
    }
    iVar2 = FUN_0021d140(param_1,param_2,param_3,0,&local_15c);
    if (iVar2 == 0) {
      iVar2 = 0;
      if (local_15c == 0) {
        iVar2 = 1;
        if (*param_4 == 0) {
          iVar2 = *param_4;
        }
      }
      *param_4 = iVar2;
      goto LAB_0021d69f;
    }
    if (1 < DAT_01216a78) {
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"dmal/common/common_mig.c",0x1a0,"cAdjustProfileCurrentCapacity",
                   0x1a0);
    }
  }
  else if (1 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_mig.c",0x197,"cAdjustProfileCurrentCapacity",
                 0x197,iVar2);
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar7 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  uVar9 = 0x4b7;
  uVar6 = 0x4b7;
  dVar8 = (double)(fVar7 * DAT_00298548);
  goto LAB_0021d51b;
}


// ===== 0021d8c0 FUN_0021d8c0 =====

int FUN_0021d8c0(long param_1,long param_2,uint param_3,uint *param_4,undefined1 param_5,
                undefined8 *param_6)

{
  undefined8 *puVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  long lVar8;
  char *pcVar9;
  undefined8 uVar10;
  uint uVar11;
  byte bVar13;
  float fVar14;
  double dVar15;
  undefined8 uVar16;
  undefined4 local_164;
  uint local_160 [2];
  uint local_158 [35];
  uint local_cc;
  undefined1 local_44;
  ulong uVar12;
  
  bVar13 = 0;
  uVar6 = *param_4;
  puVar7 = local_158;
  for (lVar8 = 0x23; lVar8 != 0; lVar8 = lVar8 + -1) {
    puVar7[0] = 0;
    puVar7[1] = 0;
    puVar7 = puVar7 + 2;
  }
  local_164 = 0;
  if ((uVar6 & 0xfeffffff) != 0x2000098) {
    return 2;
  }
  if (((*(long *)(param_2 + 0x256d8) == 0) ||
      (puVar1 = *(undefined8 **)(*(long *)(param_2 + 0x256d8) + 0x30), puVar1 == (undefined8 *)0x0))
     || (pcVar2 = (code *)*puVar1, pcVar2 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    iVar3 = (*pcVar2)();
    if (iVar3 == 0) {
      iVar3 = FUN_00133b70(param_3,local_160);
      if (iVar3 == 0) {
        if (*(int *)(param_2 + 0x27af8) == 0) {
          do {
            iVar3 = FUN_00291820(param_2 + 0x27afc,1,0);
          } while (iVar3 != 0);
          if (*(int *)(param_2 + 0x27af8) == 0) {
            uVar4 = FUN_0021c440(param_1,param_2,param_2 + 0x26470);
            *(undefined4 *)(param_2 + 0x27af8) = 1;
            *(undefined4 *)(param_2 + 0x27b00) = uVar4;
          }
          FUN_00291830(param_2 + 0x27afc,0);
        }
        uVar5 = local_160[0];
        iVar3 = *(int *)(param_2 + 0x27b00);
        if (iVar3 == 0) {
          puVar7 = (uint *)(param_2 + 0x26478);
          uVar12 = 0;
          if (*(uint *)(param_2 + 0x26470) != 0) {
            do {
              if (*puVar7 == local_160[0]) {
                lVar8 = *(long *)(param_2 + 0x256d8);
                if (((lVar8 == 0) || (*(undefined8 **)(lVar8 + 0x50) == (undefined8 *)0x0)) ||
                   (pcVar2 = (code *)**(undefined8 **)(lVar8 + 0x50), pcVar2 == (code *)0x0)) {
                  iVar3 = 3;
                }
                else {
                  iVar3 = (*pcVar2)(lVar8,param_2,0x2080,&local_164);
                  if (iVar3 == 0) {
                    local_158[0] = local_160[0];
                    local_44 = param_5;
                    iVar3 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_164,
                                         0x20800181,local_158,0x118,0);
                    switch(iVar3) {
                    case 0:
                      uVar11 = local_cc;
                      if (((local_160[0] & 0x40000000) != 0) && (uVar11 = 1, local_cc == 0)) {
                        uVar11 = local_cc;
                      }
                      local_cc = uVar11;
                      if (param_6 != (undefined8 *)0x0) {
                        pcVar9 = "+gfx";
                        if (((uVar5 & 0xe0) == 0) && (pcVar9 = "+me", (uVar5 & 0x40000000) == 0)) {
                          pcVar9 = "+me.all";
                          uVar5 = uVar5 >> 0x1c & 3;
                          if ((uVar5 != 2) && (pcVar9 = "", uVar5 == 1)) {
                            pcVar9 = "-me";
                          }
                        }
                        *param_6 = pcVar9;
                      }
                      if (uVar6 != 0x2000098) {
                        if (uVar6 != 0x3000098) {
                          return 2;
                        }
                        puVar7 = param_4;
                        for (lVar8 = 0x26; lVar8 != 0; lVar8 = lVar8 + -1) {
                          *puVar7 = 0;
                          puVar7 = puVar7 + (ulong)bVar13 * -2 + 1;
                        }
                        param_4[3] = local_cc;
                        param_4[1] = param_3;
                        param_2 = param_2 + uVar12 * 0x40;
                        param_4[4] = *(uint *)(param_2 + 0x26494);
                        param_4[5] = *(uint *)(param_2 + 0x26498);
                        param_4[6] = *(uint *)(param_2 + 0x264a0);
                        param_4[7] = *(uint *)(param_2 + 0x2649c);
                        param_4[8] = *(uint *)(param_2 + 0x264a4);
                        param_4[9] = *(uint *)(param_2 + 0x264a8);
                        param_4[2] = *(uint *)(param_2 + 0x26488);
                        *(ulong *)(param_4 + 10) = *(ulong *)(param_2 + 0x264b0) >> 0x14;
                        uVar6 = 0;
                        if (*(int *)(param_2 + 0x2648c) != 0) {
                          uVar6 = 2;
                        }
                        param_4[0x24] = uVar6;
                        return iVar3;
                      }
                      puVar7 = param_4;
                      for (lVar8 = 0x26; lVar8 != 0; lVar8 = lVar8 + -1) {
                        *puVar7 = 0;
                        puVar7 = puVar7 + (ulong)bVar13 * -2 + 1;
                      }
                      param_4[4] = local_cc;
                      param_4[1] = param_3;
                      param_2 = param_2 + uVar12 * 0x40;
                      param_4[5] = *(uint *)(param_2 + 0x26494);
                      param_4[6] = *(uint *)(param_2 + 0x26498);
                      param_4[7] = *(uint *)(param_2 + 0x264a0);
                      param_4[8] = *(uint *)(param_2 + 0x2649c);
                      param_4[9] = *(uint *)(param_2 + 0x264a4);
                      param_4[10] = *(uint *)(param_2 + 0x264a8);
                      param_4[3] = *(uint *)(param_2 + 0x26488);
                      *(ulong *)(param_4 + 0xc) = *(ulong *)(param_2 + 0x264b0) >> 0x14;
switchD_0021dd14_caseD_f:
                      return iVar3;
                    default:
                      return 999;
                    case 3:
                    case 0x66:
                      return 10;
                    case 0xf:
                      goto switchD_0021dd14_caseD_f;
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
                fVar14 = (float)FUN_002917b0(&DAT_01216a60);
                lVar8 = syscall(0xba);
                uVar16 = 0x336;
                uVar10 = 0x336;
                dVar15 = (double)(fVar14 * DAT_00298548);
                goto LAB_0021db4b;
              }
              uVar11 = (int)uVar12 + 1;
              uVar12 = (ulong)uVar11;
              puVar7 = puVar7 + 0x10;
            } while (uVar11 != *(uint *)(param_2 + 0x26470));
          }
          return 6;
        }
        if (DAT_01216a78 < 2) {
          return iVar3;
        }
        fVar14 = (float)FUN_002917b0(&DAT_01216a60);
        lVar8 = syscall(0xba);
        uVar16 = 0x31e;
        uVar10 = 0x31e;
        dVar15 = (double)(fVar14 * DAT_00298548);
      }
      else {
        if (DAT_01216a78 < 2) {
          return iVar3;
        }
        fVar14 = (float)FUN_002917b0(&DAT_01216a60);
        lVar8 = syscall(0xba);
        uVar16 = 0x319;
        uVar10 = 0x319;
        dVar15 = (double)(fVar14 * DAT_00298548);
      }
      goto LAB_0021db4b;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar3;
  }
  fVar14 = (float)FUN_002917b0(&DAT_01216a60);
  lVar8 = syscall(0xba);
  uVar16 = 0x316;
  uVar10 = 0x316;
  dVar15 = (double)(fVar14 * DAT_00298548);
LAB_0021db4b:
  FUN_002340f0(dVar15,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar8,
               "dmal/common/common_mig.c",uVar10,"cDeviceGetGpuInstanceProfileInfo",uVar16,iVar3);
  return iVar3;
}


// ===== 0021df50 FUN_0021df50 =====

undefined2 FUN_0021df50(code *param_1,undefined8 param_2,undefined8 param_3,uint param_4)

{
  uint uVar1;
  long lVar2;
  undefined8 extraout_RDX;
  float fVar3;
  undefined8 uVar4;
  undefined8 uStack_40;
  undefined1 local_28 [16];
  
  uVar4 = 0x10;
  local_28 = ZEXT416(param_4) << 0x40;
  uVar1 = (*param_1)(param_3,param_2,3,4,0xc638,local_28);
  if (uVar1 != 0) {
    if (1 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60,uStack_40,extraout_RDX,uVar4);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %x\n",
                   "ERROR",lVar2,"dmal/common/common_mig.c",0x51,param_4,(ulong)uVar1);
    }
    if (0x66 < uVar1) {
      return 999;
    }
  }
  return *(undefined2 *)(&DAT_002d4c20 + (ulong)uVar1 * 2);
}


// ===== 0021e040 FUN_0021e040 =====

undefined2 FUN_0021e040(code *param_1,undefined8 param_2,undefined8 param_3,uint param_4)

{
  uint uVar1;
  long lVar2;
  undefined8 extraout_RDX;
  float fVar3;
  undefined8 uVar4;
  undefined8 uStack_40;
  undefined1 local_28 [16];
  
  uVar4 = 0x10;
  local_28 = ZEXT416(param_4) << 0x40;
  uVar1 = (*param_1)(param_3,param_2,2,3,0xc637,local_28);
  if (uVar1 != 0) {
    if (1 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60,uStack_40,extraout_RDX,uVar4);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %x\n",
                   "ERROR",lVar2,"dmal/common/common_mig.c",0x3c,param_4,(ulong)uVar1);
    }
    if (0x66 < uVar1) {
      return 999;
    }
  }
  return *(undefined2 *)(&DAT_002d4c20 + (ulong)uVar1 * 2);
}


// ===== 0021e130 FUN_0021e130 =====

int FUN_0021e130(long param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
                undefined8 param_5,undefined4 param_6,undefined4 param_7)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined8 extraout_RDX;
  float fVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined4 local_3c [3];
  
  iVar2 = FUN_0021bf00(param_2,local_3c);
  if (iVar2 == 0) {
    if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x30) != 0)) &&
       (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0xb8), pcVar1 != (code *)0x0)) {
      (*pcVar1)(DAT_012164a0,local_3c[0],5);
    }
    uVar7 = 0x21e1ad;
    iVar2 = FUN_0021e040(*(undefined8 *)(param_1 + 0x10),local_3c[0],param_2,param_3);
    if (iVar2 == 0) {
      uVar6 = 0;
      iVar3 = FUN_0019c780(param_1,local_3c[0],param_7,param_4,param_5,param_6);
      iVar2 = 0;
      if (iVar3 != 0) {
        if (1 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60,uVar7,extraout_RDX,uVar6);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %x\n",
                       "ERROR",lVar4,"dmal/common/common_mig.c",0xea,param_4,iVar3);
        }
        (**(code **)(param_1 + 0x28))(local_3c[0],local_3c[0],local_3c[0]);
        switch(iVar3) {
        case 3:
        case 0x66:
          return 10;
        default:
          return 999;
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
    (**(code **)(param_1 + 0x28))(local_3c[0],local_3c[0],local_3c[0]);
  }
  else if (1 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_mig.c",0xdd,"cDeviceScopeRmControl",0xdd,iVar2);
  }
  return iVar2;
}


// ===== 0021e3a0 FUN_0021e3a0 =====

int FUN_0021e3a0(long param_1,long param_2,undefined4 param_3,long param_4,uint *param_5)

{
  uint *puVar1;
  code *pcVar2;
  undefined8 uVar3;
  int iVar4;
  char *pcVar5;
  long lVar6;
  ulong uVar7;
  undefined8 extraout_RDX;
  uint uVar8;
  char cVar9;
  float fVar10;
  undefined8 uVar11;
  undefined8 in_stack_fffffffffffffef0;
  uint local_e8;
  int iStack_e4;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  lVar6 = *(long *)(param_2 + 0x256d8);
  uVar8 = *(uint *)(param_4 + 0x38);
  local_e8 = local_e8 & 0xffffff00;
  if (((lVar6 == 0) || (*(long *)(lVar6 + 0x38) == 0)) ||
     (pcVar2 = *(code **)(*(long *)(lVar6 + 0x38) + 0x88), pcVar2 == (code *)0x0)) {
    cVar9 = '\0';
  }
  else {
    in_stack_fffffffffffffef0 = 0x21e40d;
    (*pcVar2)(lVar6,param_2,&local_e8);
    cVar9 = (char)local_e8;
  }
  local_e8 = *param_5;
  uVar11 = 2;
  iVar4 = FUN_0021e130(*(undefined8 *)(param_1 + 0x10),param_2,param_3,0x208001a2,&local_e8,0xa8);
  if (iVar4 != 0) {
    if (DAT_01216a78 < 2) {
      return iVar4;
    }
    fVar10 = (float)FUN_002917b0(&DAT_01216a60,in_stack_fffffffffffffef0,extraout_RDX,uVar11);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar6,"dmal/common/common_mig.c",0x3fb,"cGetComputeProfilesForGpuInstance",
                 0x3fb,iVar4);
    return iVar4;
  }
  uVar8 = uVar8 >> 2 & 7;
  if (*(int *)(param_4 + 8) == 1) {
    if (1 < uVar8 - 1) goto LAB_0021e48f;
  }
  else if ((uVar8 != 0) || (*(int *)(param_4 + 8) != 2)) goto LAB_0021e48f;
  if (cVar9 == '\0') {
    uVar8 = 0;
    if (iStack_e4 != 0) {
      pcVar5 = (char *)&uStack_e0;
      uVar8 = 0;
      do {
        if (*pcVar5 != '\x03') {
          uVar7 = (ulong)uVar8;
          uVar11 = *(undefined8 *)pcVar5;
          uVar3 = *(undefined8 *)(pcVar5 + 8);
          uVar8 = uVar8 + 1;
          puVar1 = param_5 + uVar7 * 5 + 2;
          puVar1[4] = *(uint *)(pcVar5 + 0x10);
          *(undefined8 *)puVar1 = uVar11;
          *(undefined8 *)(puVar1 + 2) = uVar3;
        }
        pcVar5 = pcVar5 + 0x14;
      } while (pcVar5 != (char *)((long)&uStack_d0 + (ulong)(iStack_e4 - 1) * 0x14 + 4));
    }
    param_5[1] = uVar8;
    return 0;
  }
LAB_0021e48f:
  *(ulong *)param_5 = CONCAT44(iStack_e4,local_e8);
  *(undefined8 *)(param_5 + 2) = uStack_e0;
  *(undefined8 *)(param_5 + 4) = local_d8;
  *(undefined8 *)(param_5 + 6) = uStack_d0;
  *(undefined8 *)(param_5 + 8) = local_c8;
  *(undefined8 *)(param_5 + 10) = uStack_c0;
  *(undefined8 *)(param_5 + 0x28) = local_48;
  *(undefined8 *)(param_5 + 0xc) = local_b8;
  *(undefined8 *)(param_5 + 0xe) = uStack_b0;
  *(undefined8 *)(param_5 + 0x10) = local_a8;
  *(undefined8 *)(param_5 + 0x12) = uStack_a0;
  *(undefined8 *)(param_5 + 0x14) = local_98;
  *(undefined8 *)(param_5 + 0x16) = uStack_90;
  *(undefined8 *)(param_5 + 0x18) = local_88;
  *(undefined8 *)(param_5 + 0x1a) = uStack_80;
  *(undefined8 *)(param_5 + 0x1c) = local_78;
  *(undefined8 *)(param_5 + 0x1e) = uStack_70;
  *(undefined8 *)(param_5 + 0x20) = local_68;
  *(undefined8 *)(param_5 + 0x22) = uStack_60;
  *(undefined8 *)(param_5 + 0x24) = local_58;
  *(undefined8 *)(param_5 + 0x26) = uStack_50;
  return 0;
}


// ===== 0021e620 FUN_0021e620 =====

int FUN_0021e620(long param_1,undefined8 param_2,undefined4 param_3,long param_4,int param_5,
                undefined8 param_6,int *param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  byte *pbVar5;
  long lVar6;
  int *piVar7;
  ulong uVar8;
  uint uVar9;
  int *piVar10;
  uint *puVar11;
  undefined8 *puVar12;
  undefined8 uVar13;
  uint uVar14;
  byte bVar15;
  float fVar16;
  undefined8 uVar17;
  int local_268 [2];
  undefined1 local_260;
  undefined8 local_25c;
  undefined1 local_254;
  undefined8 local_250;
  undefined1 local_248;
  undefined8 local_244;
  undefined1 local_23c;
  undefined8 local_238;
  undefined1 local_230;
  undefined8 local_22c;
  undefined1 local_224;
  undefined8 local_220;
  undefined1 local_218;
  undefined8 local_214;
  undefined1 local_20c;
  int local_208 [2];
  byte local_200 [8];
  int local_1f8 [40];
  uint local_158 [35];
  int local_cc;
  
  bVar15 = 0;
  piVar7 = local_208;
  for (lVar6 = 0x15; lVar6 != 0; lVar6 = lVar6 + -1) {
    piVar7[0] = 0;
    piVar7[1] = 0;
    piVar7 = piVar7 + 2;
  }
  puVar11 = local_158;
  for (lVar6 = 0x23; lVar6 != 0; lVar6 = lVar6 + -1) {
    puVar11[0] = 0;
    puVar11[1] = 0;
    puVar11 = puVar11 + 2;
  }
  iVar1 = *param_7;
  if ((iVar1 != 0x2000088) && (iVar1 != 0x300008c)) {
    return 2;
  }
  iVar2 = FUN_0021e3a0(param_1,param_2,param_3,param_4,local_208);
  if (iVar2 != 0) {
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar16 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    fVar16 = fVar16 * DAT_00298548;
    uVar17 = 0x439;
    uVar13 = 0x439;
LAB_0021e74f:
    FUN_002340f0((double)fVar16,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar6,
                 "dmal/common/common_mig.c",uVar13,"cDeviceGetComputeInstanceProfileInfo",uVar17,
                 iVar2);
    return iVar2;
  }
  switch(param_5) {
  case 0:
  case 7:
    if (*(int *)(param_4 + 8) == 0) {
      return 3;
    }
    break;
  case 1:
    if (*(uint *)(param_4 + 8) < 2) {
      return 3;
    }
    break;
  case 2:
    if ((*(uint *)(param_4 + 8) - 4 & 0xfffffffb) == 0) {
      return 3;
    }
    if (*(uint *)(param_4 + 8) < 3) {
      return 3;
    }
    break;
  case 3:
    if (*(uint *)(param_4 + 8) < 4) {
      return 3;
    }
    if (*(uint *)(param_4 + 8) == 6) {
      return 3;
    }
    break;
  case 4:
    if (*(uint *)(param_4 + 8) < 7) {
      return 3;
    }
    if (*(uint *)(param_4 + 8) == 8) {
      return 3;
    }
    break;
  case 5:
    if (*(uint *)(param_4 + 8) < 8) {
      return 3;
    }
    break;
  case 6:
    if (*(int *)(param_4 + 8) != 6) {
      return 3;
    }
    break;
  default:
    return 3;
  }
  uVar14 = *(uint *)(param_4 + 0x3c);
  if (uVar14 == 0) {
    local_25c = 0x700000001;
    uVar9 = 0;
    local_250 = 0x100000002;
    local_244 = 0x200000003;
    local_238 = 0x300000004;
    local_22c = 0x600000006;
    local_220 = 0x400000007;
    local_268[0] = 1;
    local_268[1] = 0;
    local_260 = 0;
    local_254 = 1;
    local_248 = 1;
    local_23c = 1;
    local_230 = 1;
    local_224 = 1;
    local_218 = 1;
    local_214 = 0x500000008;
    local_20c = 1;
    qsort(local_200,(ulong)(uint)local_208[1],0x14,FUN_0021be40);
    piVar7 = local_268;
    do {
      if (uVar9 < (uint)local_208[1]) {
        piVar10 = local_208 + (ulong)uVar9 * 5;
        uVar3 = uVar9;
        do {
          if (((((char)piVar7[2] == '\0') || (local_208[1] - 1U <= uVar3)) ||
              (piVar10[4] != piVar10[(ulong)uVar9 * -5 + (ulong)(uVar9 + 1) * 5 + 4])) &&
             (*piVar7 == piVar10[4])) {
            uVar4 = (ulong)uVar14;
            uVar9 = uVar3 + 1;
            uVar14 = uVar14 + 1;
            *(int *)(param_4 + (uVar4 + 8) * 8) = piVar7[1];
            *(uint *)(param_4 + 4 + (uVar4 + 8) * 8) = (uint)local_200[(ulong)uVar3 * 0x14];
            break;
          }
          uVar3 = uVar3 + 1;
          piVar10 = piVar10 + 5;
        } while (uVar3 < (uint)local_208[1]);
      }
      piVar7 = piVar7 + 3;
    } while (local_208 != piVar7);
    *(uint *)(param_4 + 0x3c) = uVar14;
    if (uVar14 == 0) goto LAB_0021ea70;
  }
  uVar4 = 0;
  do {
    if (param_5 == *(int *)(param_4 + 0x40 + uVar4 * 8)) {
      uVar14 = *(uint *)(param_4 + 0x44 + (uVar4 & 0xffffffff) * 8);
      local_158[0] = uVar14;
      iVar2 = FUN_0021e130(*(undefined8 *)(param_1 + 0x10),param_2,param_3,0xc63701a9,local_158,
                           0x118);
      if (iVar2 == 0) {
        pbVar5 = local_200;
        uVar4 = 0;
        if (local_208[1] == 0) {
          return 3;
        }
        while (*pbVar5 != uVar14) {
          uVar9 = (int)uVar4 + 1;
          uVar4 = (ulong)uVar9;
          pbVar5 = pbVar5 + 0x14;
          if (local_208[1] == uVar9) {
            return 3;
          }
        }
        if (local_cc == 0) {
          return 3;
        }
        if (iVar1 != 0x2000088) {
          if (iVar1 != 0x300008c) {
            return 2;
          }
          param_7[0] = 0;
          param_7[1] = 0;
          param_7[0x21] = 0;
          param_7[0x22] = 0;
          puVar12 = (undefined8 *)((ulong)(param_7 + 2) & 0xfffffffffffffff8);
          for (uVar8 = (ulong)(((int)param_7 -
                               (int)(undefined8 *)((ulong)(param_7 + 2) & 0xfffffffffffffff8)) +
                               0x8cU >> 3); uVar8 != 0; uVar8 = uVar8 - 1) {
            *puVar12 = 0;
            puVar12 = puVar12 + (ulong)bVar15 * -2 + 1;
          }
          param_7[1] = param_5;
          param_7[3] = local_cc;
          iVar1 = local_1f8[uVar4 * 5];
          iVar2 = local_1f8[uVar4 * 5 + 2];
          param_7[2] = iVar1;
          param_7[4] = iVar2;
          param_7[5] = *(int *)(param_4 + 0x10);
          param_7[6] = *(int *)(param_4 + 0x14);
          param_7[7] = *(int *)(param_4 + 0x18);
          param_7[8] = *(int *)(param_4 + 0x1c);
          param_7[9] = *(int *)(param_4 + 0x20);
          if (iVar1 == *(int *)(param_4 + 8)) {
            param_7[0x22] = (uint)(*(int *)(param_4 + 0x30) != 0);
            return 0;
          }
          return 0;
        }
        param_7[0] = 0;
        param_7[1] = 0;
        param_7[0x20] = 0;
        param_7[0x21] = 0;
        puVar12 = (undefined8 *)((ulong)(param_7 + 2) & 0xfffffffffffffff8);
        for (uVar8 = (ulong)(((int)param_7 -
                             (int)(undefined8 *)((ulong)(param_7 + 2) & 0xfffffffffffffff8)) + 0x88U
                            >> 3); uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar12 = 0;
          puVar12 = puVar12 + (ulong)bVar15 * -2 + 1;
        }
        param_7[1] = param_5;
        param_7[3] = local_cc;
        iVar1 = local_1f8[uVar4 * 5 + 2];
        param_7[2] = local_1f8[uVar4 * 5];
        param_7[4] = iVar1;
        param_7[5] = *(int *)(param_4 + 0x10);
        param_7[6] = *(int *)(param_4 + 0x14);
        param_7[7] = *(int *)(param_4 + 0x18);
        param_7[8] = *(int *)(param_4 + 0x1c);
        param_7[9] = *(int *)(param_4 + 0x20);
        return 0;
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar16 = (float)FUN_002917b0(&DAT_01216a60);
      lVar6 = syscall(0xba);
      fVar16 = fVar16 * DAT_00298548;
      uVar17 = 0x487;
      uVar13 = 0x487;
      goto LAB_0021e74f;
    }
    uVar4 = uVar4 + 1;
  } while ((uint)uVar4 < uVar14);
LAB_0021ea70:
  if (1 < DAT_01216a78) {
    fVar16 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar16 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar6,"dmal/common/common_mig.c",0x480,
                 "cDeviceGetComputeInstanceProfileInfo",0x480,3);
  }
  return 3;
}


// ===== 0021ec80 FUN_0021ec80 =====

/* WARNING: Type propagation algorithm not settling */

int FUN_0021ec80(long param_1,long param_2,undefined8 param_3,undefined8 *param_4,int *param_5)

{
  int iVar1;
  void *__dest;
  long lVar2;
  undefined8 extraout_RDX;
  int *piVar3;
  float fVar4;
  undefined8 uVar5;
  undefined8 in_stack_fffffffffffffe40;
  int local_1a8;
  undefined1 local_1a4 [372];
  
  piVar3 = &local_1a8;
  for (lVar2 = 0x2d; lVar2 != 0; lVar2 = lVar2 + -1) {
    piVar3[0] = 0;
    piVar3[1] = 0;
    piVar3 = piVar3 + 2;
  }
  *piVar3 = 0;
  uVar5 = 3;
  iVar1 = FUN_0021e130(*(undefined8 *)(param_1 + 0x10),param_2,param_3,0xc6370104,&local_1a8,0x16c);
  if (iVar1 == 0) {
    __dest = malloc((ulong)(uint)(local_1a8 * 4));
    *param_4 = __dest;
    if (__dest == (void *)0x0) {
      iVar1 = 0x14;
    }
    else {
      memcpy(__dest,local_1a4,(ulong)(uint)(local_1a8 * 4));
      *param_5 = local_1a8;
    }
  }
  else if (1 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60,in_stack_fffffffffffffe40,extraout_RDX,uVar5);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar2,"dmal/common/common_mig.c",0x82c,"cDeviceGetActiveComputeInstances",
                 0x82c,iVar1);
  }
  return iVar1;
}


// ===== 0021edd0 FUN_0021edd0 =====

int FUN_0021edd0(long param_1,long *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 extraout_RDX;
  int *piVar7;
  float fVar8;
  double dVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  int local_5e2c;
  uint local_5e1c;
  undefined4 local_5e18;
  int local_5e14;
  undefined8 local_5e10 [15];
  undefined8 auStack_5d98 [2985];
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
  int iStack_44;
  
  memset(&local_5e18,0,0x5dd8);
  local_5e1c = local_5e1c & 0xffffff00;
  lVar4 = *(long *)(*param_2 + 0x256d8);
  if (((lVar4 != 0) && (*(long *)(lVar4 + 0x38) != 0)) &&
     (pcVar3 = *(code **)(*(long *)(lVar4 + 0x38) + 0x80), pcVar3 != (code *)0x0)) {
    (*pcVar3)(lVar4,*param_2,&local_5e1c);
    if ((char)local_5e1c != '\0') {
      local_5e1c = local_5e1c & 0xffffff00;
      lVar4 = *(long *)(*param_2 + 0x256d8);
      if (((lVar4 != 0) && (*(long *)(lVar4 + 0x30) != 0)) &&
         (pcVar3 = *(code **)(*(long *)(lVar4 + 0x30) + 0x148), pcVar3 != (code *)0x0)) {
        (*pcVar3)(lVar4,*param_2,&local_5e1c);
        if ((char)local_5e1c != '\0') {
          if (*param_3 != 0x10025a0) {
            return 0x19;
          }
          if ((int)param_2[1] != -1) {
            uVar11 = 0x21eeda;
            local_5e2c = FUN_00133c90(param_3[1],&local_5e18);
            if (local_5e2c == 0) {
              uVar10 = 2;
              local_5e2c = FUN_0021e130(*(undefined8 *)(param_1 + 0x10),*param_2,(int)param_2[1],
                                        0x2080110e,&local_5e18,0x5dd8);
              if (local_5e2c == 0) {
                local_5e2c = FUN_00133bf0(local_50,&local_5e1c,extraout_RDX,uVar10);
                if (local_5e2c == 0) {
                  local_5e2c = FUN_00133ce0(local_5e18,param_3 + 1);
                  if (local_5e2c == 0) {
                    param_3[2] = local_5e1c;
                    param_3[6] = local_5e14;
                    param_3[3] = local_4c;
                    if (local_4c == 2) {
                      *(ulong *)(param_3 + 4) = CONCAT44(iStack_44,local_48);
                    }
                    else if (local_4c == 1) {
                      param_3[4] = iStack_44;
                    }
                    if (local_5e14 == 0) {
                      return 0;
                    }
                    puVar5 = local_5e10;
                    piVar7 = param_3 + 8;
                    do {
                      uVar1 = *(uint *)(puVar5 + 2);
                      puVar6 = puVar5 + 0xf;
                      *(undefined8 *)piVar7 = *puVar5;
                      uVar11 = puVar5[1];
                      *(ulong *)(piVar7 + 4) = (ulong)uVar1;
                      uVar1 = *(uint *)(puVar5 + 3);
                      *(undefined8 *)(piVar7 + 2) = uVar11;
                      iVar2 = *(int *)((long)puVar5 + 0x14);
                      *(ulong *)(piVar7 + 8) = (ulong)uVar1;
                      piVar7[6] = iVar2;
                      *(undefined8 *)(piVar7 + 10) = puVar5[4];
                      puVar5 = puVar6;
                      piVar7 = piVar7 + 0xc;
                    } while (puVar6 != auStack_5d98 + (ulong)(local_5e14 - 1) * 0xf);
                    return 0;
                  }
                  if (DAT_01216a78 < 2) {
                    return local_5e2c;
                  }
                  fVar8 = (float)FUN_002917b0(&DAT_01216a60);
                  lVar4 = syscall(0xba);
                  uVar11 = 0xa25;
                  uVar10 = 0xa25;
                  dVar9 = (double)(fVar8 * DAT_00298548);
                }
                else {
                  if (DAT_01216a78 < 2) {
                    return local_5e2c;
                  }
                  fVar8 = (float)FUN_002917b0(&DAT_01216a60);
                  lVar4 = syscall(0xba);
                  uVar11 = 0xa22;
                  uVar10 = 0xa22;
                  dVar9 = (double)(fVar8 * DAT_00298548);
                }
              }
              else {
                if (DAT_01216a78 < 2) {
                  return local_5e2c;
                }
                fVar8 = (float)FUN_002917b0(&DAT_01216a60,uVar11);
                lVar4 = syscall(0xba);
                uVar11 = 0xa1f;
                uVar10 = 0xa1f;
                dVar9 = (double)(fVar8 * DAT_00298548);
              }
            }
            else {
              if (DAT_01216a78 < 2) {
                return local_5e2c;
              }
              fVar8 = (float)FUN_002917b0(&DAT_01216a60);
              lVar4 = syscall(0xba);
              uVar11 = 0xa1a;
              uVar10 = 0xa1a;
              dVar9 = (double)(fVar8 * DAT_00298548);
            }
            FUN_002340f0(dVar9,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
                         "dmal/common/common_mig.c",uVar11,"cGpuInstanceGetVgpuSchedulerLog",uVar10,
                         local_5e2c);
            return local_5e2c;
          }
          return 2;
        }
      }
    }
  }
  return 3;
}


// ===== 0021f220 FUN_0021f220 =====

int FUN_0021f220(long param_1,undefined8 param_2,undefined4 param_3,long param_4,int param_5,
                undefined4 *param_6)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  undefined8 extraout_RDX;
  undefined8 *puVar4;
  float fVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 in_stack_fffffffffffffeb0;
  undefined8 local_138;
  
  uVar2 = 0;
  puVar4 = &local_138;
  for (lVar3 = 0x23; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  if (*(uint *)(param_4 + 0x3c) != 0) {
    do {
      if (param_5 == *(int *)(param_4 + 0x40 + uVar2 * 8)) {
        local_138._0_4_ = *(undefined4 *)(param_4 + 0x44 + (uVar2 & 0xffffffff) * 8);
        uVar6 = 3;
        iVar1 = FUN_0021e130(*(undefined8 *)(param_1 + 0x10),param_2,param_3,0xc63701a9,&local_138,
                             0x118);
        if (iVar1 == 0) {
          *param_6 = local_138._4_4_;
          return 0;
        }
        if (DAT_01216a78 < 2) {
          return iVar1;
        }
        fVar5 = (float)FUN_002917b0(&DAT_01216a60,in_stack_fffffffffffffeb0,extraout_RDX,uVar6);
        lVar3 = syscall(0xba);
        fVar5 = fVar5 * DAT_00298548;
        uVar7 = 0x64d;
        uVar6 = 0x64d;
        goto LAB_0021f31d;
      }
      uVar2 = uVar2 + 1;
    } while ((uint)uVar2 < *(uint *)(param_4 + 0x3c));
  }
  if (DAT_01216a78 < 2) {
    return 3;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  iVar1 = 3;
  fVar5 = fVar5 * DAT_00298548;
  uVar7 = 0x648;
  uVar6 = 0x648;
LAB_0021f31d:
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
               "dmal/common/common_mig.c",uVar6,"cDeviceGetAvailableComputeInstances",uVar7,iVar1);
  return iVar1;
}


// ===== 0021f3b0 FUN_0021f3b0 =====

int FUN_0021f3b0(long param_1,undefined8 param_2,undefined4 param_3,long param_4,int param_5,
                long param_6,uint *param_7)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 extraout_RDX;
  float fVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 in_stack_fffffffffffffea0;
  undefined8 local_148 [18];
  undefined8 local_b8;
  int local_b0 [30];
  uint local_38;
  
  uVar2 = 0;
  puVar4 = local_148;
  for (lVar3 = 0x23; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  if (*(uint *)(param_4 + 0x3c) != 0) {
    do {
      if (param_5 == *(int *)(param_4 + 0x40 + uVar2 * 8)) {
        local_148[0]._0_4_ = *(undefined4 *)(param_4 + 0x44 + (uVar2 & 0xffffffff) * 8);
        uVar6 = 3;
        iVar1 = FUN_0021e130(*(undefined8 *)(param_1 + 0x10),param_2,param_3,0xc63701a9,local_148,
                             0x118);
        if (iVar1 == 0) {
          *param_7 = local_38;
          if (param_6 == 0) {
            return 0;
          }
          if (local_38 == 0) {
            return 0;
          }
          puVar4 = &local_b8;
          lVar3 = 0;
          do {
            iVar1 = *(int *)(puVar4 + 1);
            uVar6 = *puVar4;
            puVar4 = puVar4 + 2;
            *(int *)(param_6 + lVar3 * 8) = (int)uVar6;
            *(int *)(param_6 + 4 + lVar3 * 8) = (iVar1 + 1) - (int)uVar6;
            lVar3 = lVar3 + 1;
          } while ((uint)lVar3 < *param_7);
          return 0;
        }
        if (DAT_01216a78 < 2) {
          return iVar1;
        }
        fVar5 = (float)FUN_002917b0(&DAT_01216a60,in_stack_fffffffffffffea0,extraout_RDX,uVar6);
        lVar3 = syscall(0xba);
        fVar5 = fVar5 * DAT_00298548;
        uVar7 = 0x668;
        uVar6 = 0x668;
        goto LAB_0021f4fd;
      }
      uVar2 = uVar2 + 1;
    } while ((uint)uVar2 < *(uint *)(param_4 + 0x3c));
  }
  if (DAT_01216a78 < 2) {
    return 3;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  iVar1 = 3;
  fVar5 = fVar5 * DAT_00298548;
  uVar7 = 0x663;
  uVar6 = 0x663;
LAB_0021f4fd:
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
               "dmal/common/common_mig.c",uVar6,"cDeviceGetComputeInstancePossiblePlacements",uVar7,
               iVar1);
  return iVar1;
}


// ===== 0021f590 FUN_0021f590 =====

int FUN_0021f590(long param_1,undefined8 param_2,ulong param_3,uint param_4,long param_5)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  undefined8 extraout_RDX;
  uint *puVar4;
  undefined8 *puVar5;
  byte bVar6;
  float fVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 in_stack_fffffffffffffcc0;
  undefined4 local_328 [36];
  int local_298;
  int local_290;
  uint local_208 [20];
  undefined4 auStack_1b8 [98];
  
  bVar6 = 0;
  puVar4 = local_208;
  for (lVar3 = 0x38; lVar3 != 0; lVar3 = lVar3 + -1) {
    puVar4[0] = 0;
    puVar4[1] = 0;
    puVar4 = puVar4 + 2;
  }
  *puVar4 = 0;
  iVar1 = FUN_0021e130(*(undefined8 *)(param_1 + 0x10),param_2,param_3,0xc6370103,local_208,0x1c4,3)
  ;
  if (iVar1 == 0) {
    uVar2 = 0;
    if (local_208[0] != 0) {
LAB_0021f61c:
      if (local_208[uVar2 + 1] != param_4) goto LAB_0021f610;
      puVar5 = (undefined8 *)local_328;
      for (lVar3 = 0x23; lVar3 != 0; lVar3 = lVar3 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + (ulong)bVar6 * -2 + 1;
      }
      uVar8 = 3;
      local_328[0] = auStack_1b8[(uVar2 & 0xffffffff) * 0xd + 1];
      iVar1 = FUN_0021e130(*(undefined8 *)(param_1 + 0x10),param_2,param_3 & 0xffffffff,0xc63701a9,
                           local_328,0x118);
      if (iVar1 == 0) {
        *(undefined4 *)(param_5 + 0x20) = auStack_1b8[(uVar2 & 0xffffffff) * 0xd];
        *(int *)(param_5 + 0x24) = (local_290 + 1) - local_298;
        return 0;
      }
      if (DAT_01216a78 < 2) {
        return iVar1;
      }
      fVar7 = (float)FUN_002917b0(&DAT_01216a60,in_stack_fffffffffffffcc0,extraout_RDX,uVar8);
      lVar3 = syscall(0xba);
      fVar7 = fVar7 * DAT_00298548;
      uVar8 = 0x695;
      uVar9 = 0x695;
      goto LAB_0021f6f3;
    }
LAB_0021f7a8:
    iVar1 = 6;
  }
  else if (1 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    fVar7 = fVar7 * DAT_00298548;
    uVar8 = 0x689;
    uVar9 = 0x689;
LAB_0021f6f3:
    FUN_002340f0((double)fVar7,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
                 "dmal/common/common_mig.c",uVar8,"cDeviceGetComputeInstanceInfo",uVar9,iVar1);
  }
  return iVar1;
LAB_0021f610:
  uVar2 = uVar2 + 1;
  if (local_208[0] <= (uint)uVar2) goto LAB_0021f7a8;
  goto LAB_0021f61c;
}


// ===== 0021f7e0 FUN_0021f7e0 =====

void FUN_0021f7e0(long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30 [16];
  undefined8 local_20;
  undefined4 local_18;
  
  local_20 = 0;
  local_18 = 0;
  local_38 = 1;
  local_30 = (undefined1  [16])0x0;
  local_34 = param_4;
  FUN_0021e130(*(undefined8 *)(param_1 + 0x10),param_2,param_3,0xc6370102,&local_38,0x24,3);
  return;
}


// ===== 0021f830 FUN_0021f830 =====

int FUN_0021f830(long param_1,undefined8 param_2,ulong param_3,long param_4,int param_5,long param_6
                ,uint *param_7)

{
  int iVar1;
  ulong uVar2;
  int *piVar3;
  uint uVar4;
  long lVar5;
  undefined8 extraout_RDX;
  byte *pbVar6;
  int *piVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  float fVar10;
  double dVar11;
  undefined8 uVar12;
  ulong uVar13;
  undefined8 in_stack_fffffffffffffd20;
  undefined8 local_2b8;
  byte local_2b0 [16];
  int aiStack_2a0 [38];
  int local_208 [19];
  int local_1bc [99];
  
  piVar7 = local_208;
  for (lVar5 = 0x38; lVar5 != 0; lVar5 = lVar5 + -1) {
    piVar7[0] = 0;
    piVar7[1] = 0;
    piVar7 = piVar7 + 2;
  }
  *piVar7 = 0;
  puVar8 = &local_2b8;
  for (lVar5 = 0x15; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  iVar1 = FUN_0021e130(*(undefined8 *)(param_1 + 0x10),param_2,param_3,0xc6370103,local_208,0x1c4,3)
  ;
  if (iVar1 == 0) {
    uVar13 = 2;
    iVar1 = FUN_0021e130(*(undefined8 *)(param_1 + 0x10),param_2,param_3 & 0xffffffff,0x208001a2,
                         &local_2b8,0xa8);
    if (iVar1 == 0) {
      uVar4 = *(uint *)(param_4 + 0x3c);
      uVar2 = 0;
      if (uVar4 != 0) {
        do {
          uVar13 = uVar2 & 0xffffffff;
          if (param_5 == *(int *)(param_4 + 0x40 + uVar2 * 8)) {
            pbVar6 = local_2b0;
            uVar2 = 0;
            if (local_2b8._4_4_ != 0) {
              do {
                if ((uint)*pbVar6 == *(uint *)(param_4 + 0x44 + uVar13 * 8)) {
                  uVar4 = 0;
                  if (local_208[0] != 0) {
                    piVar7 = local_1bc;
                    iVar1 = aiStack_2a0[uVar2 * 5];
                    uVar4 = 0;
                    piVar3 = local_208 + 1;
                    do {
                      if (*piVar7 == iVar1) {
                        uVar13 = (ulong)uVar4;
                        uVar4 = uVar4 + 1;
                        *(int *)(param_6 + uVar13 * 4) = *piVar3;
                      }
                      piVar3 = piVar3 + 1;
                      piVar7 = piVar7 + 0xd;
                    } while (piVar3 != local_208 + (ulong)(local_208[0] - 1) + 2);
                  }
                  *param_7 = uVar4;
                  return 0;
                }
                uVar4 = (int)uVar2 + 1;
                uVar2 = (ulong)uVar4;
                pbVar6 = pbVar6 + 0x14;
              } while (local_2b8._4_4_ != uVar4);
            }
            return 3;
          }
          uVar2 = uVar2 + 1;
        } while ((uint)uVar2 < uVar4);
      }
      if (DAT_01216a78 < 2) {
        return 3;
      }
      fVar10 = (float)FUN_002917b0(&DAT_01216a60,in_stack_fffffffffffffd20,uVar4,uVar13);
      lVar5 = syscall(0xba);
      iVar1 = 3;
      uVar12 = 0x71f;
      uVar9 = 0x71f;
      dVar11 = (double)(fVar10 * DAT_00298548);
    }
    else {
      if (DAT_01216a78 < 2) {
        return iVar1;
      }
      fVar10 = (float)FUN_002917b0(&DAT_01216a60,in_stack_fffffffffffffd20,extraout_RDX,uVar13);
      lVar5 = syscall(0xba);
      uVar12 = 0x71c;
      uVar9 = 0x71c;
      dVar11 = (double)(fVar10 * DAT_00298548);
    }
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar1;
    }
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    uVar12 = 0x717;
    uVar9 = 0x717;
    dVar11 = (double)(fVar10 * DAT_00298548);
  }
  FUN_002340f0(dVar11,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,
               "dmal/common/common_mig.c",uVar9,"cDeviceGetComputeInstances",uVar12,iVar1);
  return iVar1;
}


// ===== 0021fb40 FUN_0021fb40 =====

int FUN_0021fb40(long param_1,undefined8 *param_2,int *param_3)

{
  uint uVar1;
  undefined1 auVar2 [16];
  int iVar3;
  long lVar4;
  undefined8 extraout_RDX;
  char *pcVar5;
  float fVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined1 local_88 [16];
  undefined8 local_78;
  int local_68;
  undefined1 auStack_64 [12];
  undefined1 local_58 [16];
  undefined8 local_48;
  uint local_40;
  
  local_78 = 0;
  local_88 = (undefined1  [16])0x0;
  if (*param_3 != 0x1000018) {
    return 0x19;
  }
  local_48 = 0;
  local_40 = 0;
  local_58 = (undefined1  [16])0x0;
  if ((param_3[2] == 1) && (((param_3[3] != 0 || (param_3[5] != 0)) || (param_3[4] != 0))))
  goto LAB_0021fd30;
  auStack_64 = SUB1612((undefined1  [16])0x0,4);
  local_68 = param_3[1];
  iVar3 = FUN_0021e130(*(undefined8 *)(param_1 + 0x10),*param_2,*(undefined4 *)(param_2 + 1),
                       0x20801122,&local_68,0x2c,2);
  if (iVar3 == 0) {
    if (param_3[3] == 2) {
      uVar1 = param_3[5];
      if (((uVar1 == 0) || (((uint)local_48 <= uVar1 && (uVar1 <= (uint)local_58._12_4_)))) &&
         ((uVar1 = param_3[4], uVar1 == 0 || ((local_40 <= uVar1 && (uVar1 <= local_48._4_4_))))))
      goto LAB_0021fc27;
    }
    else if (((param_3[3] != 1) || (uVar1 = param_3[4], uVar1 == 0)) ||
            (((uint)local_58._8_4_ <= uVar1 && (uVar1 <= (uint)local_58._4_4_)))) {
LAB_0021fc27:
      uVar8 = 0x21fc32;
      iVar3 = FUN_00133c40(param_3[2],&local_68);
      auVar2 = local_88;
      if (iVar3 != 0) {
        return iVar3;
      }
      local_88._4_4_ = local_68;
      local_88._0_4_ = param_3[1];
      local_88._8_4_ = param_3[3];
      local_88._12_4_ = auVar2._12_4_;
      if (local_88._8_4_ == 1) {
        if (DAT_01216a78 < 4) {
          return 0;
        }
        fVar6 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                     &DAT_002983c2,lVar4,"dmal/common/common_mig.c",0x9ab);
        return 0;
      }
      if (local_88._8_4_ == 2) {
        local_78 = CONCAT44(param_3[4],param_3[5]);
      }
      uVar7 = 2;
      iVar3 = FUN_0021e130(*(undefined8 *)(param_1 + 0x10),*param_2,*(undefined4 *)(param_2 + 1),
                           0x20801121,local_88,0x18);
      if (iVar3 == 0) {
        return 0;
      }
      if (DAT_01216a78 < 2) {
        return iVar3;
      }
      fVar6 = (float)FUN_002917b0(&DAT_01216a60,uVar8,extraout_RDX,uVar7);
      lVar4 = syscall(0xba);
      pcVar5 = "cGpuInstanceSetVgpuSchedulerState";
      fVar6 = fVar6 * DAT_00298548;
      uVar7 = 0x9be;
      uVar8 = 0x9be;
      goto LAB_0021fd9b;
    }
LAB_0021fd30:
    iVar3 = 2;
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar3;
    }
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    pcVar5 = "cValidateClientSchedState";
    fVar6 = fVar6 * DAT_00298548;
    uVar7 = 0x96f;
    uVar8 = 0x96f;
LAB_0021fd9b:
    FUN_002340f0((double)fVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
                 "dmal/common/common_mig.c",uVar8,pcVar5,uVar7,iVar3);
  }
  return iVar3;
}


// ===== 0021fe70 FUN_0021fe70 =====

int FUN_0021fe70(long param_1,undefined8 *param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined8 extraout_RDX;
  char *pcVar4;
  float fVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined1 local_88 [16];
  undefined8 local_78;
  undefined4 local_68;
  undefined1 auStack_64 [12];
  undefined1 local_58 [16];
  undefined8 local_48;
  uint local_40;
  
  local_78 = 0;
  local_88 = (undefined1  [16])0x0;
  if (*(int *)(param_2 + 1) == -1) {
    return 2;
  }
  local_48 = 0;
  local_40 = 0;
  local_58 = (undefined1  [16])0x0;
  if ((param_3[1] == 1) && ((param_3[3] != 0 || (param_3[2] != 0)))) {
LAB_00220010:
    iVar2 = 2;
  }
  else {
    auStack_64 = SUB1612((undefined1  [16])0x0,4);
    local_68 = *param_3;
    iVar2 = FUN_0021e130(*(undefined8 *)(param_1 + 0x10),*param_2,*(int *)(param_2 + 1),0x20801122,
                         &local_68,0x2c,2);
    if (iVar2 == 0) {
      uVar1 = param_3[3];
      if (((uVar1 != 0) && ((uVar1 < (uint)local_48 || ((uint)local_58._12_4_ < uVar1)))) ||
         ((uVar1 = param_3[2], uVar1 != 0 && ((uVar1 < local_40 || (local_48._4_4_ < uVar1))))))
      goto LAB_00220010;
      uVar7 = 0x21ff6c;
      iVar2 = FUN_00133c40(param_3[1],local_88 + 4);
      if (iVar2 != 0) {
        return iVar2;
      }
      uVar6 = 2;
      local_88._0_4_ = *param_3;
      local_78 = CONCAT44(param_3[2],param_3[3]);
      iVar2 = FUN_0021e130(*(undefined8 *)(param_1 + 0x10),*param_2,*(undefined4 *)(param_2 + 1),
                           0x20801121,local_88,0x18);
      if (iVar2 == 0) {
        return 0;
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60,uVar7,extraout_RDX,uVar6);
      lVar3 = syscall(0xba);
      pcVar4 = "cGpuInstanceSetVgpuSchedulerState_v2";
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0xae8;
      uVar7 = 0xae8;
    }
    else {
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      pcVar4 = "cValidateClientSchedState_v2";
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0xab6;
      uVar7 = 0xab6;
    }
    FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
                 "dmal/common/common_mig.c",uVar7,pcVar4,uVar6,iVar2);
  }
  return iVar2;
}


// ===== 002200d0 FUN_002200d0 =====

int FUN_002200d0(long param_1,long param_2,uint param_3,undefined4 param_4,undefined8 *param_5)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  undefined8 *puVar6;
  float fVar7;
  undefined4 local_dc;
  undefined1 local_d8 [16];
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined1 local_a0;
  undefined1 local_98 [104];
  
  lVar3 = *(long *)(param_1 + 0x10);
  *param_5 = 0;
  param_5[0x13] = 0;
  puVar6 = (undefined8 *)((ulong)(param_5 + 1) & 0xfffffffffffffff8);
  for (uVar5 = (ulong)(((int)param_5 -
                       (int)(undefined8 *)((ulong)(param_5 + 1) & 0xfffffffffffffff8)) + 0xa0U >> 3)
      ; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  iVar2 = FUN_0021bf00(param_2,&local_dc);
  if (iVar2 == 0) {
    iVar2 = FUN_0021e040(*(undefined8 *)(lVar3 + 0x10),local_dc,param_2,param_3);
    if ((iVar2 == 0) &&
       (iVar2 = FUN_0021df50(*(undefined8 *)(lVar3 + 0x10),local_dc,param_2,param_4), iVar2 == 0)) {
      iVar2 = FUN_0019c780(lVar3,local_dc,4,0xc6380101,local_d8,0x39,0);
      if (iVar2 != 0) {
        if (1 < DAT_01216a78) {
          fVar7 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n",
                       "ERROR",lVar4,"dmal/common/common_mig.c",0x773,iVar2);
        }
        (**(code **)(lVar3 + 0x28))(local_dc,local_dc,local_dc);
        switch(iVar2) {
        case 3:
        case 0x66:
          return 10;
        default:
          return 999;
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
      lVar4 = *(long *)(param_2 + 0x256d8);
      if (((lVar4 == 0) || (*(long *)(lVar4 + 0x38) == 0)) ||
         (pcVar1 = *(code **)(*(long *)(lVar4 + 0x38) + 0x38), pcVar1 == (code *)0x0)) {
        iVar2 = 3;
      }
      else {
        iVar2 = (*pcVar1)(lVar4,param_2,local_98,0x60);
        if (iVar2 == 0) {
          (**(code **)(lVar3 + 0x28))(local_dc,3,4);
          (**(code **)(lVar3 + 0x28))(local_dc,2,3);
          *(uint *)((long)param_5 + 4) = param_3;
          param_5[0x13] = param_2;
          *(undefined4 *)param_5 = local_dc;
          *(undefined4 *)(param_5 + 1) = param_4;
          *(undefined8 *)((long)param_5 + 0x2c) = local_a8;
          *(undefined8 *)((long)param_5 + 0xc) = local_c8;
          *(undefined8 *)((long)param_5 + 0x14) = uStack_c0;
          *(undefined1 *)((long)param_5 + 0x34) = local_a0;
          *(undefined8 *)((long)param_5 + 0x1c) = local_b8;
          *(undefined8 *)((long)param_5 + 0x24) = uStack_b0;
          snprintf((char *)((long)param_5 + 0x35),0x60,"MIG-%s/%u/%u",local_98,(ulong)param_3);
          *(undefined1 *)((long)param_5 + 0x94) = 0;
          return 0;
        }
      }
      if (1 < DAT_01216a78) {
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n",
                     "ERROR",lVar4,"dmal/common/common_mig.c",0x77a,0);
      }
    }
    (**(code **)(lVar3 + 0x28))(local_dc,local_dc,local_dc);
  }
  else if (1 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar3,"dmal/common/common_mig.c",0x75d,"cDeviceCreateMigDeviceClient",0x75d
                 ,iVar2);
  }
  return iVar2;
}


// ===== 00220520 FUN_00220520 =====

void FUN_00220520(long param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  float fVar5;
  undefined4 local_3c [3];
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x256d8) + 0x10);
  iVar2 = FUN_0021bf00(param_1,local_3c);
  if (iVar2 == 0) {
    iVar2 = FUN_0021e040(*(undefined8 *)(lVar3 + 0x10),local_3c[0],param_1,param_2);
    if (iVar2 == 0) {
      if (((param_3 != (undefined4 *)0x0) &&
          (iVar2 = FUN_0021df50(*(undefined8 *)(lVar3 + 0x10),local_3c[0],param_1,*param_3),
          iVar2 != 0)) && (2 < DAT_01216a78)) {
        uVar1 = *param_3;
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u %u\n",
                     "WARNING",lVar4,"dmal/common/common_mig.c",0x5a8,iVar2,uVar1,param_2);
      }
    }
    else if (2 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u\n",
                   "WARNING",lVar4,"dmal/common/common_mig.c",0x59e,iVar2,param_2);
    }
    (**(code **)(lVar3 + 0x28))(local_3c[0],local_3c[0],local_3c[0]);
    return;
  }
  if (DAT_01216a78 < 3) {
    return;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","WARNING",
               lVar3,"dmal/common/common_mig.c",0x596,iVar2);
  return;
}


// ===== 00220740 FUN_00220740 =====

int FUN_00220740(long param_1,undefined8 param_2,ulong param_3,long param_4,int param_5,
                undefined4 *param_6,undefined4 *param_7)

{
  int iVar1;
  ulong uVar2;
  byte *pbVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  uint uVar7;
  float fVar8;
  double dVar9;
  undefined8 uVar10;
  undefined8 local_2b8;
  byte local_2b0 [4];
  int aiStack_2ac [41];
  undefined8 local_208;
  undefined4 local_200;
  int local_1fc;
  int local_1f8;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined8 local_1e4;
  undefined4 local_1dc;
  int local_1d4;
  undefined4 local_1d0;
  uint local_1cc;
  undefined4 local_5c;
  
  puVar5 = &local_208;
  for (lVar4 = 0x39; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined4 *)puVar5 = 0;
  puVar5 = &local_2b8;
  for (lVar4 = 0x15; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  iVar1 = FUN_0021e3a0(param_1,param_2,param_3,param_4,&local_2b8);
  if (iVar1 == 0) {
    uVar2 = 0;
    if (*(uint *)(param_4 + 0x3c) != 0) {
      do {
        if (param_5 == *(int *)(param_4 + 0x40 + uVar2 * 8)) {
          local_1cc = *(uint *)(param_4 + 0x44 + (uVar2 & 0xffffffff) * 8);
          pbVar3 = local_2b0;
          uVar2 = 0;
          if (local_2b8._4_4_ == 0) {
            return 3;
          }
          while (*pbVar3 != local_1cc) {
            uVar7 = (int)uVar2 + 1;
            uVar2 = (ulong)uVar7;
            pbVar3 = pbVar3 + 0x14;
            if (local_2b8._4_4_ == uVar7) {
              return 3;
            }
          }
          local_200 = 1;
          local_1fc = aiStack_2ac[uVar2 * 5 + 1];
          if ((*(int *)(param_4 + 0x30) != 0) &&
             ((aiStack_2ac[uVar2 * 5 + 1] == *(int *)(param_4 + 8) ||
              (*(int *)(param_4 + 0x30) == *(int *)(param_4 + 0x34))))) {
            local_1f8 = aiStack_2ac[uVar2 * 5];
          }
          local_1d4 = aiStack_2ac[uVar2 * 5 + 3];
          if (param_6 != (undefined4 *)0x0) {
            local_1d0 = *param_6;
            local_208._4_4_ = local_208._4_4_ | 2;
          }
          local_1f0 = *(undefined4 *)(param_4 + 0x10);
          local_1ec = *(undefined4 *)(param_4 + 0x18);
          local_1e8 = *(undefined4 *)(param_4 + 0x14);
          local_1dc = 0x1f;
          local_1e4 = *(undefined8 *)(param_4 + 0x1c);
          iVar1 = FUN_0021e130(*(undefined8 *)(param_1 + 0x10),param_2,param_3 & 0xffffffff,
                               0xc6370101,&local_208,0x1cc,3);
          if (iVar1 == 0) {
            *param_7 = local_5c;
            FUN_00220520(param_2,param_3 & 0xffffffff,param_7);
            return 0;
          }
          if (DAT_01216a78 < 2) {
            return iVar1;
          }
          fVar8 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          uVar10 = 0x6e8;
          uVar6 = 0x6e8;
          dVar9 = (double)(fVar8 * DAT_00298548);
          goto LAB_00220940;
        }
        uVar2 = uVar2 + 1;
      } while ((uint)uVar2 < *(uint *)(param_4 + 0x3c));
    }
    if (DAT_01216a78 < 2) {
      return 3;
    }
    fVar8 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    iVar1 = 3;
    uVar10 = 0x6b4;
    uVar6 = 0x6b4;
    dVar9 = (double)(fVar8 * DAT_00298548);
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar1;
    }
    fVar8 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    uVar10 = 0x6b1;
    uVar6 = 0x6b1;
    dVar9 = (double)(fVar8 * DAT_00298548);
  }
LAB_00220940:
  FUN_002340f0(dVar9,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
               "dmal/common/common_mig.c",uVar6,"cDeviceCreateComputeInstanceWithPlacement",uVar10,
               iVar1);
  return iVar1;
}


// ===== 00220aa0 FUN_00220aa0 =====

int FUN_00220aa0(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  
  lVar4 = *(long *)(param_1 + 0x10);
  uVar1 = *param_2;
  uVar2 = param_2[2];
  iVar3 = FUN_0021e040(*(undefined8 *)(lVar4 + 0x10),uVar1,*(undefined8 *)(param_2 + 0x26),
                       param_2[1]);
  if (iVar3 == 0) {
    iVar3 = FUN_0021df50(*(undefined8 *)(lVar4 + 0x10),uVar1,*(undefined8 *)(param_2 + 0x26),uVar2);
    if (iVar3 != 0) {
      (**(code **)(lVar4 + 0x28))(uVar1,2,3);
    }
  }
  else if (1 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_mig.c",0x67,"cMigDeviceSubscribe",0x67,iVar3);
  }
  return iVar3;
}


// ===== 00220ba0 thunk_FUN_00220aa0 =====

int thunk_FUN_00220aa0(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  
  lVar4 = *(long *)(param_1 + 0x10);
  uVar1 = *param_2;
  uVar2 = param_2[2];
  iVar3 = FUN_0021e040(*(undefined8 *)(lVar4 + 0x10),uVar1,*(undefined8 *)(param_2 + 0x26),
                       param_2[1]);
  if (iVar3 == 0) {
    iVar3 = FUN_0021df50(*(undefined8 *)(lVar4 + 0x10),uVar1,*(undefined8 *)(param_2 + 0x26),uVar2);
    if (iVar3 != 0) {
      (**(code **)(lVar4 + 0x28))(uVar1,2,3);
    }
  }
  else if (1 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_mig.c",0x67,"cMigDeviceSubscribe",0x67,iVar3);
  }
  return iVar3;
}


// ===== 00220bb0 FUN_00220bb0 =====

int FUN_00220bb0(undefined8 param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  float fVar4;
  
  if (*(int *)(param_2 + 0x26464) == 0) {
    do {
      iVar1 = FUN_00291820(param_2 + 0x26468,1,0);
    } while (iVar1 != 0);
    if (*(int *)(param_2 + 0x26464) == 0) {
      uVar2 = FUN_0021c760(param_1,param_2,param_2 + 0x26460);
      *(undefined4 *)(param_2 + 0x26464) = 1;
      *(undefined4 *)(param_2 + 0x2646c) = uVar2;
    }
    FUN_00291830(param_2 + 0x26468,0);
  }
  iVar1 = *(int *)(param_2 + 0x2646c);
  if (iVar1 == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x26460);
  }
  else if (1 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar3,"dmal/common/common_mig.c",0x4f5,
                 "cDeviceGetGpuInstancePlacementStartAdjust",0x4f5,iVar1);
    return iVar1;
  }
  return iVar1;
}


// ===== 00220cf0 FUN_00220cf0 =====

ulong FUN_00220cf0(long param_1,long param_2,int param_3,uint *param_4)

{
  code *pcVar1;
  ulong uVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  uint uVar6;
  undefined8 uVar7;
  int *piVar8;
  ulong uVar9;
  float fVar10;
  undefined8 uVar11;
  undefined4 local_790;
  uint local_78c;
  int local_788;
  uint auStack_784 [3];
  undefined8 uStack_778;
  uint auStack_770 [2];
  undefined8 uStack_768;
  uint auStack_760 [36];
  ulong auStack_6d0 [209];
  uint local_48;
  undefined1 local_44;
  
  lVar4 = *(long *)(param_2 + 0x256d8);
  local_790 = 0;
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)) {
    uVar9 = 3;
  }
  else {
    uVar3 = (*pcVar1)(lVar4,param_2,0x2080,&local_790);
    uVar9 = (ulong)uVar3;
    if (uVar3 == 0) {
      uVar3 = FUN_00220bb0(param_1,param_2,&local_78c);
      uVar9 = (ulong)uVar3;
      if (uVar3 == 0) {
        local_44 = 1;
        piVar8 = &local_788;
        uVar3 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_790,0x20800175,
                             piVar8,0x748,0);
        uVar9 = (ulong)uVar3;
        switch(uVar3) {
        case 0:
          goto switchD_00220eef_caseD_0;
        default:
          return 999;
        case 3:
        case 0x66:
          return 10;
        case 0xf:
          return uVar9;
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
        return uVar9;
      }
      fVar10 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      fVar10 = fVar10 * DAT_00298548;
      uVar11 = 0x55f;
      uVar7 = 0x55f;
      goto LAB_00220dcb;
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar9;
  }
  fVar10 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  fVar10 = fVar10 * DAT_00298548;
  uVar11 = 0x55c;
  uVar7 = 0x55c;
LAB_00220dcb:
  FUN_002340f0((double)fVar10,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
               "dmal/common/common_mig.c",uVar7,"cDeviceGetGpuInstanceInfo",uVar11,uVar9);
  return uVar9;
switchD_00220eef_caseD_0:
  uVar5 = uVar9;
  if (local_48 != 0) {
    do {
      if (((char)piVar8[0x34] != '\0') && (*piVar8 == param_3)) {
        uVar2 = auStack_6d0[uVar5 * 0x1d + 2];
        uVar3 = (uint)auStack_6d0[uVar5 * 0x1d + 1];
        *param_4 = uVar3;
        uVar6 = ((int)uVar2 + 1) - uVar3;
        param_4[1] = uVar6;
        if (uVar6 <= local_78c) {
          if (local_78c <= uVar3) {
            local_78c = -local_78c;
          }
          *param_4 = local_78c + uVar3;
        }
        param_4[2] = auStack_760[uVar5 * 0x3a + 1];
        param_4[0xd] = auStack_760[uVar5 * 0x3a];
        param_4[0xc] = auStack_760[uVar5 * 0x3a + 2];
        *(undefined8 *)(param_4 + 3) = (&uStack_778)[uVar5 * 0x1d];
        param_4[6] = auStack_770[uVar5 * 0x3a];
        param_4[5] = auStack_770[uVar5 * 0x3a + 1];
        *(undefined8 *)(param_4 + 7) = (&uStack_768)[uVar5 * 0x1d];
        param_4[9] = auStack_784[uVar5 * 0x3a + 2];
        uVar3 = auStack_784[uVar5 * 0x3a];
        *(ulong *)(param_4 + 10) = auStack_6d0[uVar5 * 0x1d] >> 0x14;
        param_4[0xe] = uVar3;
        return uVar9;
      }
      uVar3 = (int)uVar5 + 1;
      uVar5 = (ulong)uVar3;
      piVar8 = piVar8 + 0x3a;
    } while (local_48 != uVar3);
  }
  return 6;
}


// ===== 00221070 FUN_00221070 =====

int FUN_00221070(long param_1,long param_2,undefined4 param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  uint *puVar7;
  int *piVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  bool bVar11;
  float fVar12;
  double dVar13;
  undefined8 uVar14;
  undefined4 local_160;
  uint local_15c;
  undefined8 local_158 [18];
  undefined8 local_c8;
  int local_c0 [30];
  uint local_48;
  
  puVar9 = local_158;
  for (lVar6 = 0x23; lVar6 != 0; lVar6 = lVar6 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  lVar6 = *(long *)(param_2 + 0x256d8);
  local_160 = 0;
  if (((lVar6 == 0) || (*(undefined8 **)(lVar6 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar6 + 0x50), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    iVar3 = (*pcVar2)(lVar6,param_2,0x2080,&local_160);
    if (iVar3 == 0) {
      iVar3 = FUN_00220bb0(param_1,param_2,&local_15c);
      if (iVar3 == 0) {
        iVar3 = FUN_00133b70(param_3,local_158);
        if (iVar3 == 0) {
          iVar3 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_160,0x20800181,
                               local_158,0x118,0);
          switch(iVar3) {
          case 0:
            goto switchD_00221304_caseD_0;
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
        fVar12 = (float)FUN_002917b0(&DAT_01216a60);
        lVar6 = syscall(0xba);
        uVar14 = 0x534;
        uVar10 = 0x534;
        dVar13 = (double)(fVar12 * DAT_00298548);
      }
      else {
        if (DAT_01216a78 < 2) {
          return iVar3;
        }
        fVar12 = (float)FUN_002917b0(&DAT_01216a60);
        lVar6 = syscall(0xba);
        uVar14 = 0x531;
        uVar10 = 0x531;
        dVar13 = (double)(fVar12 * DAT_00298548);
      }
      goto LAB_0022116b;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar3;
  }
  fVar12 = (float)FUN_002917b0(&DAT_01216a60);
  lVar6 = syscall(0xba);
  uVar14 = 0x52e;
  uVar10 = 0x52e;
  dVar13 = (double)(fVar12 * DAT_00298548);
LAB_0022116b:
  FUN_002340f0(dVar13,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar6,
               "dmal/common/common_mig.c",uVar10,"cDeviceGetGpuInstancePossiblePlacements",uVar14,
               iVar3);
  return iVar3;
switchD_00221304_caseD_0:
  *param_5 = local_48;
  if (param_4 == (uint *)0x0) {
    return iVar3;
  }
  if (local_48 != 0) {
    piVar8 = local_c0;
    puVar7 = param_4;
    do {
      iVar1 = *piVar8;
      uVar5 = (uint)*(undefined8 *)(piVar8 + -2);
      *puVar7 = uVar5;
      uVar4 = (iVar1 + 1) - uVar5;
      puVar7[1] = uVar4;
      if (uVar4 <= local_15c) {
        uVar4 = local_15c;
        if (local_15c <= uVar5) {
          uVar4 = -local_15c;
        }
        *puVar7 = uVar4 + uVar5;
      }
      piVar8 = piVar8 + 4;
      bVar11 = param_4 + (ulong)(local_48 - 1) * 2 != puVar7;
      puVar7 = puVar7 + 2;
    } while (bVar11);
  }
  qsort(param_4,(ulong)*param_5,8,FUN_0021be60);
  return iVar3;
}


// ===== 00221420 FUN_00221420 =====

int FUN_00221420(long param_1,long param_2,undefined4 param_3,uint *param_4,undefined4 *param_5)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  uint uVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  float fVar9;
  double dVar10;
  undefined8 uVar11;
  undefined4 local_1d0;
  uint local_1cc;
  undefined8 local_1c8;
  undefined4 local_1c0;
  uint local_1ac;
  undefined1 local_1a8;
  ulong local_1a0;
  ulong local_198;
  
  puVar7 = &local_1c8;
  for (lVar5 = 0x31; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  lVar5 = *(long *)(param_2 + 0x256d8);
  local_1d0 = 0;
  if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar5 + 0x50), pcVar2 == (code *)0x0)) {
    iVar4 = 3;
  }
  else {
    iVar4 = (*pcVar2)(lVar5,param_2,0x2080,&local_1d0);
    if (iVar4 == 0) {
      local_1c8._0_4_ = 1;
      iVar4 = FUN_00133b70(param_3,&local_1ac);
      if (iVar4 == 0) {
        if ((local_1ac & 0x40000000) != 0) {
          iVar4 = FUN_0021d420(param_1,param_2,param_3,&local_1cc,0);
          if (iVar4 != 0) {
            if (DAT_01216a78 < 2) {
              return iVar4;
            }
            fVar9 = (float)FUN_002917b0(&DAT_01216a60);
            lVar5 = syscall(0xba);
            uVar11 = 0x5cc;
            uVar8 = 0x5cc;
            dVar10 = (double)(fVar9 * DAT_00298548);
            goto LAB_0022151b;
          }
          if (local_1cc == 0) {
            return 0x17;
          }
        }
        if (param_4 != (uint *)0x0) {
          uVar6 = *param_4;
          local_1cc = 0;
          uVar1 = param_4[1];
          iVar4 = FUN_00220bb0(param_1,param_2,&local_1cc);
          if (iVar4 != 0) {
            if (DAT_01216a78 < 2) {
              return iVar4;
            }
            fVar9 = (float)FUN_002917b0(&DAT_01216a60);
            lVar5 = syscall(0xba);
            uVar11 = 0x5dd;
            uVar8 = 0x5dd;
            dVar10 = (double)(fVar9 * DAT_00298548);
            goto LAB_0022151b;
          }
          if (uVar1 <= local_1cc) {
            uVar3 = -local_1cc;
            if (uVar6 < local_1cc) {
              uVar3 = local_1cc;
            }
            uVar6 = uVar6 + uVar3;
          }
          local_1ac = local_1ac | 0x80000000;
          local_1a0 = (ulong)uVar6;
          local_198 = (ulong)((uVar6 - 1) + uVar1);
        }
        local_1a8 = 1;
        iVar4 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_1d0,0x20800174,
                             &local_1c8,0x188,0);
        switch(iVar4) {
        case 0:
          *param_5 = local_1c0;
          FUN_00220520(param_2,local_1c0,0);
          return iVar4;
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
      lVar5 = syscall(0xba);
      uVar11 = 0x5c1;
      uVar8 = 0x5c1;
      dVar10 = (double)(fVar9 * DAT_00298548);
      goto LAB_0022151b;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar4;
  }
  fVar9 = (float)FUN_002917b0(&DAT_01216a60);
  lVar5 = syscall(0xba);
  uVar11 = 0x5bc;
  uVar8 = 0x5bc;
  dVar10 = (double)(fVar9 * DAT_00298548);
LAB_0022151b:
  FUN_002340f0(dVar10,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,
               "dmal/common/common_mig.c",uVar8,"cDeviceCreateGpuInstanceWithPlacement",uVar11,iVar4
              );
  return iVar4;
}


// ===== 00221870 FUN_00221870 =====

uint FUN_00221870(long param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint *puVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  undefined4 *puVar11;
  ulong uVar12;
  byte *pbVar13;
  undefined8 *puVar14;
  undefined8 uVar15;
  uint uVar16;
  byte bVar17;
  float fVar18;
  undefined8 uVar19;
  uint local_97c;
  undefined4 local_95c;
  uint local_958 [12];
  undefined4 auStack_928 [3];
  undefined8 auStack_91c [2];
  uint auStack_90c [97];
  undefined8 local_788 [5];
  undefined4 local_75c;
  ulong local_6d0;
  
  bVar17 = 0;
  puVar7 = local_958;
  for (lVar9 = 0x38; lVar9 != 0; lVar9 = lVar9 + -1) {
    puVar7[0] = 0;
    puVar7[1] = 0;
    puVar7 = puVar7 + 2;
  }
  *puVar7 = 0;
  puVar14 = local_788;
  for (lVar9 = 0xe9; lVar9 != 0; lVar9 = lVar9 + -1) {
    *puVar14 = 0;
    puVar14 = puVar14 + 1;
  }
  if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x30) == 0)) ||
     (pcVar3 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0x140), pcVar3 == (code *)0x0)) {
    uVar4 = 3;
joined_r0x00221ba0:
    if (1 < DAT_01216a78) {
      fVar18 = (float)FUN_002917b0(&DAT_01216a60);
      lVar9 = syscall(0xba);
      FUN_002340f0((double)(fVar18 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar9,"dmal/common/common_mig.c",0xb4c,
                   "cMigDeviceGetComputeInstanceAttributes",0xb4c,uVar4);
    }
    return uVar4;
  }
  uVar1 = param_2[2];
  uVar4 = (*pcVar3)();
  if (uVar4 != 0) goto joined_r0x00221ba0;
  uVar4 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),*param_2,2,0x20800175,local_788,0x748,0);
  if (uVar4 < 0x67) {
    uVar6 = *param_2;
    uVar16 = (uint)*(ushort *)(&DAT_002d4c20 + (ulong)uVar4 * 2);
    if (*(ushort *)(&DAT_002d4c20 + (ulong)uVar4 * 2) != 0) goto LAB_00221bba;
    uVar4 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),uVar6,3,0xc6370103,local_958,0x1c4,0);
    if (uVar4 < 0x67) {
      uVar16 = (uint)*(ushort *)(&DAT_002d4c20 + (ulong)uVar4 * 2);
      if (*(ushort *)(&DAT_002d4c20 + (ulong)uVar4 * 2) == 0) {
        uVar10 = 0;
        if (local_958[0] != 0) {
LAB_00221a64:
          uVar12 = uVar10 & 0xffffffff;
          if (local_958[uVar10 + 1] != uVar1) goto LAB_00221a58;
          uVar15 = *(undefined8 *)((long)auStack_91c + uVar12 * 0x34);
          uVar6 = auStack_928[uVar12 * 0xd + 1];
          uVar2 = auStack_928[uVar12 * 0xd + 2];
          uVar4 = auStack_90c[uVar12 * 0xd];
          uVar1 = auStack_90c[uVar12 * 0xd + 2];
          param_3[3] = auStack_928[uVar12 * 0xd];
          param_3[4] = uVar2;
          param_3[2] = uVar4;
          param_3[1] = local_75c;
          param_3[5] = uVar6;
          *(undefined8 *)(param_3 + 6) = uVar15;
          *(ulong *)(param_3 + 10) = local_6d0 >> 0x14;
          lVar9 = *(long *)(param_2 + 0x26);
          if (*(int *)(lVar9 + 0x27bac) == 0) {
            do {
              iVar5 = FUN_00291820(lVar9 + 0x27bb0,1,0);
            } while (iVar5 != 0);
            if (*(int *)(lVar9 + 0x27bac) == 0) {
              if (*(int *)(lVar9 + 0x27af8) == 0) {
                do {
                  iVar5 = FUN_00291820(lVar9 + 0x27afc,1,0);
                } while (iVar5 != 0);
                if (*(int *)(lVar9 + 0x27af8) == 0) {
                  uVar6 = FUN_0021c440(param_1,lVar9,lVar9 + 0x26470);
                  *(undefined4 *)(lVar9 + 0x27af8) = 1;
                  *(undefined4 *)(lVar9 + 0x27b00) = uVar6;
                }
                FUN_00291830(lVar9 + 0x27afc,0);
              }
              local_97c = *(uint *)(lVar9 + 0x27b00);
              if (local_97c == 0) {
                puVar7 = (uint *)(lVar9 + 0x26478);
                iVar5 = 0;
                if (*(int *)(lVar9 + 0x26470) == 0) {
LAB_00221f26:
                  if (4 < DAT_01216a78) {
                    fVar18 = (float)FUN_002917b0(&DAT_01216a60);
                    lVar8 = syscall(0xba);
                    FUN_002340f0((double)(fVar18 * DAT_00298548),
                                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",lVar8,
                                 "dmal/common/common_mig.c",0xb0c);
                  }
                }
                else {
                  while (uVar4 = *puVar7, (uVar4 & 0x1c) != 0) {
                    iVar5 = iVar5 + 1;
                    puVar7 = puVar7 + 0x10;
                    if (iVar5 == *(int *)(lVar9 + 0x26470)) goto LAB_00221f26;
                  }
                  *(undefined8 *)(lVar9 + 0x27b04) = 0;
                  puVar14 = (undefined8 *)(lVar9 + 0x27b0cU & 0xfffffffffffffff8);
                  *(undefined8 *)(lVar9 + 0x27ba4) = 0;
                  uVar10 = (ulong)(((int)(lVar9 + 0x27b04) - (int)puVar14) + 0xa8U >> 3);
                  for (; uVar10 != 0; uVar10 = uVar10 - 1) {
                    *puVar14 = 0;
                    puVar14 = puVar14 + (ulong)bVar17 * -2 + 1;
                  }
                  *(uint *)(lVar9 + 0x27b04) = uVar4;
                  lVar8 = *(long *)(lVar9 + 0x256d8);
                  if (((lVar8 == 0) || (*(undefined8 **)(lVar8 + 0x50) == (undefined8 *)0x0)) ||
                     (pcVar3 = (code *)**(undefined8 **)(lVar8 + 0x50), pcVar3 == (code *)0x0)) {
                    local_97c = 3;
LAB_00221e16:
                    if (1 < DAT_01216a78) {
                      fVar18 = (float)FUN_002917b0(&DAT_01216a60);
                      lVar8 = syscall(0xba);
                      fVar18 = fVar18 * DAT_00298548;
                      uVar15 = 0xb15;
                      uVar19 = 0xb15;
                      goto LAB_00221e82;
                    }
                    goto LAB_00221df9;
                  }
                  puVar11 = &local_95c;
                  local_97c = (*pcVar3)(lVar8,lVar9,0x2080);
                  if (local_97c != 0) goto LAB_00221e16;
                  uVar4 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_95c,
                                       0x208001a2,lVar9 + 0x27b04,0xa8,0,puVar11);
                  if (uVar4 < 0x67) {
                    local_97c = (uint)*(ushort *)(&DAT_002d4c20 + (ulong)uVar4 * 2);
                    goto LAB_00221df9;
                  }
                }
                local_97c = 999;
              }
              else if (1 < DAT_01216a78) {
                fVar18 = (float)FUN_002917b0(&DAT_01216a60);
                lVar8 = syscall(0xba);
                fVar18 = fVar18 * DAT_00298548;
                uVar15 = 0xafd;
                uVar19 = 0xafd;
LAB_00221e82:
                FUN_002340f0((double)fVar18,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",
                             lVar8,"dmal/common/common_mig.c",uVar15,
                             "cDeviceGetComputeInstanceProfilesUncached",uVar19,local_97c);
              }
LAB_00221df9:
              *(uint *)(lVar9 + 0x27bb4) = local_97c;
              *(undefined4 *)(lVar9 + 0x27bac) = 1;
            }
            FUN_00291830(lVar9 + 0x27bb0,0);
          }
          uVar16 = *(uint *)(lVar9 + 0x27bb4);
          if (uVar16 == 0) {
            pbVar13 = (byte *)(lVar9 + 0x27b0c);
            uVar10 = 0;
            if (*(uint *)(lVar9 + 0x27b08) != 0) {
              do {
                if (uVar1 == *pbVar13) {
                  *param_3 = *(undefined4 *)(lVar9 + uVar10 * 0x14 + 0x27b14);
                  uVar6 = *param_2;
                  goto LAB_00221bba;
                }
                uVar4 = (int)uVar10 + 1;
                uVar10 = (ulong)uVar4;
                pbVar13 = pbVar13 + 0x14;
              } while (uVar4 != *(uint *)(lVar9 + 0x27b08));
            }
            goto LAB_00221bf0;
          }
          if (1 < DAT_01216a78) {
            fVar18 = (float)FUN_002917b0(&DAT_01216a60);
            lVar9 = syscall(0xba);
            FUN_002340f0((double)(fVar18 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar9,
                         "dmal/common/common_mig.c",0xb28,"cDeviceGetComputeProfileSliceCount",0xb28
                         ,uVar16);
            uVar6 = *param_2;
            goto LAB_00221bba;
          }
          goto LAB_00221bf6;
        }
LAB_00221bf0:
        uVar16 = 6;
      }
LAB_00221bf6:
      uVar6 = *param_2;
      goto LAB_00221bba;
    }
  }
  uVar6 = *param_2;
  uVar16 = 999;
LAB_00221bba:
  lVar9 = *(long *)(param_1 + 0x10);
  (**(code **)(lVar9 + 0x28))(uVar6,3,4);
  (**(code **)(lVar9 + 0x28))(uVar6,2,3);
  return uVar16;
LAB_00221a58:
  uVar10 = uVar10 + 1;
  if (local_958[0] <= (uint)uVar10) goto LAB_00221bf0;
  goto LAB_00221a64;
}


// ===== 00221fd0 FUN_00221fd0 =====

int FUN_00221fd0(undefined8 param_1,long param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  byte bVar5;
  float fVar6;
  char local_dd;
  undefined4 local_dc;
  undefined4 local_d8 [4];
  int local_c8;
  
  bVar5 = 0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  if ((((lVar3 == 0) || (*(long *)(lVar3 + 0x30) == 0)) ||
      (pcVar1 = *(code **)(*(long *)(lVar3 + 0x30) + 0x148), pcVar1 == (code *)0x0)) ||
     ((iVar2 = (*pcVar1)(lVar3,param_2,&local_dd), iVar2 != 0 || (local_dd == '\0')))) {
    *param_3 = 0;
    return 0;
  }
  if (*(int *)(param_2 + 0x26444) != 0) goto LAB_00222074;
  do {
    iVar2 = FUN_00291820(param_2 + 0x26448,1,0);
  } while (iVar2 != 0);
  if (*(int *)(param_2 + 0x26444) == 0) {
    puVar4 = (undefined8 *)local_d8;
    for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + (ulong)bVar5 * -2 + 1;
    }
    lVar3 = *(long *)(param_2 + 0x256d8);
    if (((lVar3 == 0) || (*(long *)(lVar3 + 0x30) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(lVar3 + 0x30) + 0x10), pcVar1 == (code *)0x0)) {
      iVar2 = 1;
LAB_002221e8:
      *(int *)(param_2 + 0x26440) = iVar2;
      iVar2 = 0;
    }
    else {
      iVar2 = (*pcVar1)(lVar3,param_2,0,&local_dc);
      if (iVar2 == 0) {
        lVar3 = *(long *)(param_2 + 0x256d8);
        local_d8[0] = 0x2000098;
        if (((lVar3 == 0) || (*(long *)(lVar3 + 0x30) == 0)) ||
           (pcVar1 = *(code **)(*(long *)(lVar3 + 0x30) + 0x18), pcVar1 == (code *)0x0)) {
          iVar2 = 3;
        }
        else {
          iVar2 = (*pcVar1)(lVar3,param_2,local_dc,local_d8,1,0);
          if (iVar2 == 0) goto LAB_002221d0;
        }
      }
      else if (iVar2 == 3) {
LAB_002221d0:
        iVar2 = 1;
        if (local_c8 != 0) {
          iVar2 = local_c8;
        }
        goto LAB_002221e8;
      }
    }
    *(int *)(param_2 + 0x2644c) = iVar2;
    *(undefined4 *)(param_2 + 0x26444) = 1;
  }
  FUN_00291830(param_2 + 0x26448,0);
LAB_00222074:
  iVar2 = *(int *)(param_2 + 0x2644c);
  if (iVar2 == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x26440);
  }
  else if (1 < DAT_01216a78) {
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar3,"dmal/common/common_mig.c",0x80b,"cDeviceGetMaximumGpuInstanceCount",
                 0x80b,iVar2);
  }
  return iVar2;
}


// ===== 00222220 FUN_00222220 =====

int FUN_00222220(undefined8 param_1,long param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  uint *puVar5;
  uint uVar6;
  float fVar7;
  char local_39 [9];
  
  lVar4 = *(long *)(param_2 + 0x256d8);
  if ((((lVar4 == 0) || (*(long *)(lVar4 + 0x30) == 0)) ||
      (pcVar1 = *(code **)(*(long *)(lVar4 + 0x30) + 0x148), pcVar1 == (code *)0x0)) ||
     ((iVar2 = (*pcVar1)(lVar4,param_2,local_39), iVar2 != 0 || (local_39[0] == '\0')))) {
    *param_3 = 0;
    return 0;
  }
  if (*(int *)(param_2 + 0x26454) == 0) {
    do {
      iVar2 = FUN_00291820(param_2 + 0x26458,1,0);
    } while (iVar2 != 0);
    if (*(int *)(param_2 + 0x26454) == 0) {
      if (*(int *)(param_2 + 0x27af8) == 0) {
        do {
          iVar2 = FUN_00291820(param_2 + 0x27afc,1,0);
        } while (iVar2 != 0);
        if (*(int *)(param_2 + 0x27af8) == 0) {
          uVar3 = FUN_0021c440(param_1,param_2,param_2 + 0x26470);
          *(undefined4 *)(param_2 + 0x27af8) = 1;
          *(undefined4 *)(param_2 + 0x27b00) = uVar3;
        }
        FUN_00291830(param_2 + 0x27afc,0);
      }
      iVar2 = *(int *)(param_2 + 0x27b00);
      if (iVar2 == 0) {
        *(undefined4 *)(param_2 + 0x26450) = 0;
        if (*(int *)(param_2 + 0x26470) != 0) {
          puVar5 = (uint *)(param_2 + 0x26488);
          uVar6 = 0;
          do {
            if (uVar6 < *puVar5) {
              uVar6 = *puVar5;
            }
            puVar5 = puVar5 + 0x10;
          } while ((uint *)(param_2 + 0x264c8 + (ulong)(*(int *)(param_2 + 0x26470) - 1) * 0x40) !=
                   puVar5);
          *(uint *)(param_2 + 0x26450) = uVar6;
        }
      }
      else if (1 < DAT_01216a78) {
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                     "ERROR",lVar4,"dmal/common/common_mig.c",0x846,
                     "cDeviceGetMaximumComputeInstanceCountUncached",0x846,iVar2);
      }
      *(int *)(param_2 + 0x2645c) = iVar2;
      *(undefined4 *)(param_2 + 0x26454) = 1;
    }
    FUN_00291830(param_2 + 0x26458,0);
  }
  iVar2 = *(int *)(param_2 + 0x2645c);
  if (iVar2 == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x26450);
    return 0;
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar7 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar4,"dmal/common/common_mig.c",0x868,
               "cDeviceGetMaximumComputeInstanceCount",0x868,iVar2);
  return iVar2;
}


// ===== 002224d0 FUN_002224d0 =====

int FUN_002224d0(undefined8 param_1,long param_2,uint param_3,long param_4)

{
  uint uVar1;
  undefined8 *puVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  long lVar10;
  undefined8 uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  float fVar16;
  double dVar17;
  undefined8 uVar18;
  
  if (param_4 == 0) {
    return 2;
  }
  if (((*(long *)(param_2 + 0x256d8) == 0) ||
      (puVar2 = *(undefined8 **)(*(long *)(param_2 + 0x256d8) + 0x30), puVar2 == (undefined8 *)0x0))
     || (pcVar3 = (code *)*puVar2, pcVar3 == (code *)0x0)) {
    iVar4 = 3;
  }
  else {
    iVar4 = (*pcVar3)();
    if (iVar4 == 0) {
      if (*(int *)(param_2 + 0x27af8) == 0) {
        do {
          iVar4 = FUN_00291820(param_2 + 0x27afc,1,0);
        } while (iVar4 != 0);
        if (*(int *)(param_2 + 0x27af8) == 0) {
          uVar6 = FUN_0021c440(param_1,param_2,param_2 + 0x26470);
          *(undefined4 *)(param_2 + 0x27af8) = 1;
          *(undefined4 *)(param_2 + 0x27b00) = uVar6;
        }
        FUN_00291830(param_2 + 0x27afc,0);
        iVar4 = *(int *)(param_2 + 0x27b00);
      }
      else {
        iVar4 = *(int *)(param_2 + 0x27b00);
      }
      if (iVar4 == 0) {
        uVar14 = 0;
        if (*(int *)(param_2 + 0x26470) != 0) {
          puVar7 = (uint *)(param_2 + 0x26488);
          lVar10 = (ulong)(*(int *)(param_2 + 0x26470) - 1) * 0x40;
          do {
            if (uVar14 < *puVar7) {
              uVar14 = *puVar7;
            }
            puVar7 = puVar7 + 0x10;
          } while (puVar7 != (uint *)(param_2 + 0x264c8 + lVar10));
          puVar7 = (uint *)(param_2 + 0x26478);
          uVar15 = uVar14 - 1 & uVar14;
          do {
            uVar1 = *puVar7;
            uVar12 = uVar1 & 3;
            uVar13 = uVar1 & 0x40000000;
            uVar8 = uVar1 >> 0x1c & 3;
            uVar5 = uVar1 >> 5 & 7;
            switch(puVar7[4]) {
            case 1:
              if (uVar14 < 3) {
                if (uVar12 != 2) goto LAB_00222794;
              }
              else {
                uVar9 = uVar1 >> 2 & 7;
                if (((uVar9 != 4) || (uVar12 != 2)) && ((uVar9 != 2 || (uVar12 != 1)))) {
LAB_00222794:
                  if (uVar13 == 0) {
                    if (uVar5 == 0) {
                      if (uVar8 == 2) {
                        uVar12 = 0xf;
                      }
                      else {
                        uVar12 = 0;
                        if (uVar8 == 1) {
                          uVar12 = 0xd;
                        }
                      }
                    }
                    else {
                      uVar12 = (-(uint)(uVar8 - 1 < 2) & 8) + 10;
                    }
                  }
                  else {
                    if (uVar5 != 0) break;
                    uVar12 = (-(uint)(uVar8 - 1 < 2) & 0xb) + 7;
                  }
                  goto joined_r0x002228e0;
                }
                if (uVar15 != 0) {
                  uVar12 = 0x12;
                  if (uVar13 == 0 && uVar5 == 0) {
                    uVar12 = (-(uint)(uVar8 - 1 < 2) & 9) + 9;
                  }
                  goto joined_r0x002228e0;
                }
              }
              break;
            case 2:
              if (uVar14 < 3) {
                if (uVar12 == 2) break;
                if (uVar13 != 0) goto LAB_002229d0;
                if (uVar5 != 0) goto LAB_00222960;
                if (uVar8 != 2) goto LAB_002227e9;
                uVar12 = 0x10;
              }
              else if (uVar13 == 0) {
                if (uVar5 == 0) {
                  uVar12 = 0x10;
                  if (uVar8 != 2) {
LAB_002227e9:
                    uVar12 = 1;
                    if (uVar8 == 1) {
                      uVar12 = 0xe;
                    }
                  }
                }
                else {
LAB_00222960:
                  uVar12 = (-(uint)(uVar8 - 1 < 2) & 7) + 0xb;
                }
              }
              else {
LAB_002229d0:
                if (uVar5 != 0) break;
                uVar12 = (-(uint)(uVar8 - 1 < 2) & 10) + 8;
              }
              goto joined_r0x002228e0;
            case 3:
              if (uVar15 != 0) {
                if (uVar14 < 3) {
                  if ((uVar12 != 2) && (uVar13 == 0)) {
                    if (uVar5 != 0) goto LAB_00222b14;
                    if (uVar8 != 2) goto LAB_00222ac0;
                  }
                }
                else if (uVar13 == 0) {
                  if (uVar5 == 0) {
                    uVar12 = 0x12;
                    if (uVar8 != 2) {
LAB_00222ac0:
                      uVar12 = 2;
                      if (uVar8 == 1) {
                        uVar12 = 0x12;
                      }
                    }
                    goto joined_r0x002228e0;
                  }
LAB_00222b14:
                  uVar12 = (uVar8 - 1 < 2) + 0x11;
                  goto joined_r0x002228e0;
                }
              }
              break;
            case 4:
              if (((uVar14 < 3) && (uVar12 == 2)) || (uVar13 != 0)) break;
              if (uVar5 == 0) {
                uVar12 = 0x12;
                if ((uVar8 != 2) && (uVar12 = 3, uVar8 == 1)) {
                  uVar12 = 0x12;
                }
              }
              else {
                uVar12 = (-(uint)(uVar8 - 1 < 2) & 6) + 0xc;
              }
              goto joined_r0x002228e0;
            case 6:
              if (((uVar14 < 3) && (uVar12 == 2)) ||
                 ((uVar13 != 0 || ((uVar5 != 0 || (uVar8 == 2)))))) break;
              uVar12 = 0x12;
              if (uVar8 != 1) {
                uVar12 = puVar7[4];
              }
              goto joined_r0x002228e0;
            case 7:
              if (uVar14 < 3) {
                if ((((uVar12 != 2) && (uVar13 == 0)) && (uVar5 == 0)) && (uVar8 != 2))
                goto LAB_002226bd;
              }
              else if (uVar13 == 0) {
                uVar12 = 0x12;
                if ((uVar5 != 0) || (uVar8 == 2)) goto joined_r0x002228e0;
LAB_002226bd:
                uVar12 = 4;
                if (uVar8 == 1) {
                  uVar12 = 0x12;
                }
                goto joined_r0x002228e0;
              }
              break;
            case 8:
              if (uVar14 < 3) {
                if (((uVar12 != 2) && (uVar13 == 0)) && (uVar5 == 0)) goto LAB_00222a70;
              }
              else if (uVar13 == 0) {
                uVar12 = 0x12;
                if (uVar5 != 0) goto joined_r0x002228e0;
LAB_00222a70:
                uVar12 = 0x12;
                if ((uVar8 != 2) && (uVar12 = 5, uVar8 == 1)) {
                  uVar12 = 0x12;
                }
                goto joined_r0x002228e0;
              }
            }
            uVar12 = 0x12;
joined_r0x002228e0:
            if (uVar12 == param_3) {
              iVar4 = FUN_00133bb0(uVar1,param_4);
              if (iVar4 == 0) {
                return 0;
              }
              if (DAT_01216a78 < 2) {
                return iVar4;
              }
              fVar16 = (float)FUN_002917b0(&DAT_01216a60);
              lVar10 = syscall(0xba);
              uVar18 = 0x2f1;
              uVar11 = 0x2f1;
              dVar17 = (double)(fVar16 * DAT_00298548);
              goto LAB_0022265d;
            }
            puVar7 = puVar7 + 0x10;
          } while ((uint *)(param_2 + 0x264b8 + lVar10) != puVar7);
        }
        return 3;
      }
      if (DAT_01216a78 < 2) {
        return iVar4;
      }
      fVar16 = (float)FUN_002917b0(&DAT_01216a60);
      lVar10 = syscall(0xba);
      uVar18 = 0x224;
      uVar11 = 0x224;
      dVar17 = (double)(fVar16 * DAT_00298548);
      goto LAB_0022265d;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar4;
  }
  fVar16 = (float)FUN_002917b0(&DAT_01216a60);
  lVar10 = syscall(0xba);
  uVar18 = 0x21f;
  uVar11 = 0x21f;
  dVar17 = (double)(fVar16 * DAT_00298548);
LAB_0022265d:
  FUN_002340f0(dVar17,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar10,
               "dmal/common/common_mig.c",uVar11,"cDeviceGetGpuInstanceProfileId",uVar18,iVar4);
  return iVar4;
}


// ===== 00222b70 FUN_00222b70 =====

int FUN_00222b70(long param_1,long *param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 extraout_RDX;
  float fVar4;
  double dVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  char local_59;
  undefined1 local_58 [16];
  undefined4 local_48;
  
  local_48 = 0;
  local_58 = (undefined1  [16])0x0;
  local_59 = '\0';
  lVar3 = *(long *)(*param_2 + 0x256d8);
  if (((lVar3 != 0) && (*(long *)(lVar3 + 0x38) != 0)) &&
     (pcVar1 = *(code **)(*(long *)(lVar3 + 0x38) + 0x80), pcVar1 != (code *)0x0)) {
    (*pcVar1)(lVar3,*param_2,&local_59);
    if (local_59 != '\0') {
      local_59 = '\0';
      lVar3 = *(long *)(*param_2 + 0x256d8);
      if (((lVar3 != 0) && (*(long *)(lVar3 + 0x30) != 0)) &&
         ((pcVar1 = *(code **)(*(long *)(lVar3 + 0x30) + 0x148), pcVar1 != (code *)0x0 &&
          ((*pcVar1)(lVar3,*param_2,&local_59), local_59 != '\0')))) {
        if ((int)param_2[1] == -1) {
          return 2;
        }
        uVar7 = 0x222c50;
        iVar2 = FUN_00133c90(*param_3,local_58);
        if (iVar2 == 0) {
          uVar6 = 2;
          iVar2 = FUN_0021e130(*(undefined8 *)(param_1 + 0x10),*param_2,(int)param_2[1],0x20801120,
                               local_58,0x14);
          if (iVar2 == 0) {
            iVar2 = FUN_00133bf0(local_58._4_4_,param_3 + 1,extraout_RDX,uVar6);
            if (iVar2 == 0) {
              if (local_58._4_4_ != 2) {
                param_3[2] = local_48;
                param_3[3] = local_58._12_4_;
                return 0;
              }
              *(undefined8 *)(param_3 + 2) = 0;
              return 0;
            }
            if (DAT_01216a78 < 2) {
              return iVar2;
            }
            fVar4 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            uVar6 = 0xa60;
            uVar7 = 0xa60;
            dVar5 = (double)(fVar4 * DAT_00298548);
          }
          else {
            if (DAT_01216a78 < 2) {
              return iVar2;
            }
            fVar4 = (float)FUN_002917b0(&DAT_01216a60,uVar7);
            lVar3 = syscall(0xba);
            uVar6 = 0xa5d;
            uVar7 = 0xa5d;
            dVar5 = (double)(fVar4 * DAT_00298548);
          }
        }
        else {
          if (DAT_01216a78 < 2) {
            return iVar2;
          }
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          uVar6 = 0xa58;
          uVar7 = 0xa58;
          dVar5 = (double)(fVar4 * DAT_00298548);
        }
        FUN_002340f0(dVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
                     "dmal/common/common_mig.c",uVar7,"cGpuInstanceGetVgpuSchedulerState_v2",uVar6,
                     iVar2);
        return iVar2;
      }
    }
  }
  return 3;
}


// ===== 00222e20 FUN_00222e20 =====

int FUN_00222e20(long param_1,long *param_2,int *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 extraout_RDX;
  float fVar4;
  double dVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  uint local_5c;
  undefined1 local_58 [16];
  int local_48;
  
  local_48 = 0;
  local_58 = (undefined1  [16])0x0;
  local_5c = local_5c & 0xffffff00;
  lVar3 = *(long *)(*param_2 + 0x256d8);
  if (((lVar3 != 0) && (*(long *)(lVar3 + 0x38) != 0)) &&
     (pcVar1 = *(code **)(*(long *)(lVar3 + 0x38) + 0x80), pcVar1 != (code *)0x0)) {
    (*pcVar1)(lVar3,*param_2,&local_5c);
    if ((char)local_5c != '\0') {
      local_5c = local_5c & 0xffffff00;
      lVar3 = *(long *)(*param_2 + 0x256d8);
      if (((lVar3 != 0) && (*(long *)(lVar3 + 0x30) != 0)) &&
         (pcVar1 = *(code **)(*(long *)(lVar3 + 0x30) + 0x148), pcVar1 != (code *)0x0)) {
        (*pcVar1)(lVar3,*param_2,&local_5c);
        if ((char)local_5c != '\0') {
          if (*param_3 != 0x1000018) {
            return 0x19;
          }
          if ((int)param_2[1] == -1) {
            return 2;
          }
          uVar7 = 0x222f19;
          iVar2 = FUN_00133c90(param_3[1],local_58);
          if (iVar2 == 0) {
            uVar6 = 2;
            iVar2 = FUN_0021e130(*(undefined8 *)(param_1 + 0x10),*param_2,(int)param_2[1],0x20801120
                                 ,local_58,0x14);
            if (iVar2 == 0) {
              iVar2 = FUN_00133bf0(local_58._4_4_,&local_5c,extraout_RDX,uVar6);
              if (iVar2 == 0) {
                param_3[2] = local_5c;
                if (local_58._4_4_ == 2) {
                  param_3[3] = 0;
                  param_3[4] = 0;
                  param_3[5] = 0;
                  return 0;
                }
                param_3[3] = local_58._8_4_;
                if (local_58._8_4_ != 2) {
                  if (local_58._8_4_ != 1) {
                    return 0;
                  }
                  param_3[4] = local_58._12_4_;
                  return 0;
                }
                param_3[4] = local_48;
                param_3[5] = local_58._12_4_;
                return 0;
              }
              if (DAT_01216a78 < 2) {
                return iVar2;
              }
              fVar4 = (float)FUN_002917b0(&DAT_01216a60);
              lVar3 = syscall(0xba);
              uVar6 = 0x9e5;
              uVar7 = 0x9e5;
              dVar5 = (double)(fVar4 * DAT_00298548);
            }
            else {
              if (DAT_01216a78 < 2) {
                return iVar2;
              }
              fVar4 = (float)FUN_002917b0(&DAT_01216a60,uVar7);
              lVar3 = syscall(0xba);
              uVar6 = 0x9e2;
              uVar7 = 0x9e2;
              dVar5 = (double)(fVar4 * DAT_00298548);
            }
          }
          else {
            if (DAT_01216a78 < 2) {
              return iVar2;
            }
            fVar4 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            uVar6 = 0x9dd;
            uVar7 = 0x9dd;
            dVar5 = (double)(fVar4 * DAT_00298548);
          }
          FUN_002340f0(dVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
                       "dmal/common/common_mig.c",uVar7,"cGpuInstanceGetVgpuSchedulerState",uVar6,
                       iVar2);
          return iVar2;
        }
      }
    }
  }
  return 3;
}


// ===== 00223120 FUN_00223120 =====

undefined8 FUN_00223120(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long lVar2;
  
  uVar1 = *param_2;
  lVar2 = *(long *)(param_1 + 0x10);
  (**(code **)(lVar2 + 0x28))(uVar1,3,4);
  (**(code **)(lVar2 + 0x28))(uVar1,2,3);
  return 0;
}


// ===== 00223160 FUN_00223160 =====

int FUN_00223160(long param_1,long *param_2,undefined4 *param_3)

{
  code *pcVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 extraout_RDX;
  undefined8 *puVar5;
  float fVar6;
  double dVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  int local_5e2c;
  uint local_5e1c;
  undefined4 local_5e18;
  int local_5e14;
  undefined8 local_5e10 [15];
  undefined8 auStack_5d98 [2985];
  undefined4 local_50;
  undefined8 local_48;
  
  memset(&local_5e18,0,0x5dd8);
  local_5e1c = local_5e1c & 0xffffff00;
  lVar2 = *(long *)(*param_2 + 0x256d8);
  if (((lVar2 != 0) && (*(long *)(lVar2 + 0x38) != 0)) &&
     (pcVar1 = *(code **)(*(long *)(lVar2 + 0x38) + 0x80), pcVar1 != (code *)0x0)) {
    (*pcVar1)(lVar2,*param_2,&local_5e1c);
    if ((char)local_5e1c != '\0') {
      local_5e1c = local_5e1c & 0xffffff00;
      lVar2 = *(long *)(*param_2 + 0x256d8);
      if (((lVar2 != 0) && (*(long *)(lVar2 + 0x30) != 0)) &&
         (pcVar1 = *(code **)(*(long *)(lVar2 + 0x30) + 0x148), pcVar1 != (code *)0x0)) {
        (*pcVar1)(lVar2,*param_2,&local_5e1c);
        if ((char)local_5e1c != '\0') {
          if ((int)param_2[1] == -1) {
            return 2;
          }
          uVar9 = 0x223257;
          local_5e2c = FUN_00133c90(*param_3,&local_5e18);
          if (local_5e2c == 0) {
            uVar8 = 2;
            local_5e2c = FUN_0021e130(*(undefined8 *)(param_1 + 0x10),*param_2,(int)param_2[1],
                                      0x2080110e,&local_5e18,0x5dd8);
            if (local_5e2c == 0) {
              local_5e2c = FUN_00133bf0(local_50,&local_5e1c,extraout_RDX,uVar8);
              if (local_5e2c == 0) {
                local_5e2c = FUN_00133ce0(local_5e18,param_3);
                if (local_5e2c == 0) {
                  param_3[1] = local_5e1c;
                  param_3[4] = local_5e14;
                  *(undefined8 *)(param_3 + 2) = local_48;
                  if (local_5e14 == 0) {
                    return 0;
                  }
                  puVar3 = local_5e10;
                  puVar5 = (undefined8 *)(param_3 + 6);
                  do {
                    puVar4 = puVar3 + 0xf;
                    *puVar5 = *puVar3;
                    puVar5[1] = puVar3[1];
                    puVar5[2] = (ulong)*(uint *)(puVar3 + 2);
                    *(undefined4 *)(puVar5 + 3) = *(undefined4 *)((long)puVar3 + 0x14);
                    puVar5[4] = (ulong)*(uint *)(puVar3 + 3);
                    puVar5[5] = puVar3[4];
                    *(undefined4 *)(puVar5 + 6) = *(undefined4 *)(puVar3 + 6);
                    puVar3 = puVar4;
                    puVar5 = puVar5 + 7;
                  } while (puVar4 != auStack_5d98 + (ulong)(local_5e14 - 1) * 0xf);
                  return 0;
                }
                if (DAT_01216a78 < 2) {
                  return local_5e2c;
                }
                fVar6 = (float)FUN_002917b0(&DAT_01216a60);
                lVar2 = syscall(0xba);
                uVar9 = 0xa90;
                uVar8 = 0xa90;
                dVar7 = (double)(fVar6 * DAT_00298548);
              }
              else {
                if (DAT_01216a78 < 2) {
                  return local_5e2c;
                }
                fVar6 = (float)FUN_002917b0(&DAT_01216a60);
                lVar2 = syscall(0xba);
                uVar9 = 0xa8d;
                uVar8 = 0xa8d;
                dVar7 = (double)(fVar6 * DAT_00298548);
              }
            }
            else {
              if (DAT_01216a78 < 2) {
                return local_5e2c;
              }
              fVar6 = (float)FUN_002917b0(&DAT_01216a60,uVar9);
              lVar2 = syscall(0xba);
              uVar9 = 0xa8a;
              uVar8 = 0xa8a;
              dVar7 = (double)(fVar6 * DAT_00298548);
            }
          }
          else {
            if (DAT_01216a78 < 2) {
              return local_5e2c;
            }
            fVar6 = (float)FUN_002917b0(&DAT_01216a60);
            lVar2 = syscall(0xba);
            uVar9 = 0xa85;
            uVar8 = 0xa85;
            dVar7 = (double)(fVar6 * DAT_00298548);
          }
          FUN_002340f0(dVar7,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
                       "dmal/common/common_mig.c",uVar9,"cGpuInstanceGetVgpuSchedulerLog_v2",uVar8,
                       local_5e2c);
          return local_5e2c;
        }
      }
    }
  }
  return 3;
}


// ===== 00223570 FUN_00223570 =====

int FUN_00223570(long param_1,undefined4 *param_2,int param_3,int param_4,int param_5,
                undefined8 param_6)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  
  if ((param_5 == 2 || param_4 != 1) || (param_3 != 0)) {
    iVar3 = 3;
  }
  else {
    if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x30) == 0)) ||
       (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0x140), pcVar2 == (code *)0x0)) {
      iVar3 = 3;
    }
    else {
      iVar3 = (*pcVar2)();
      if (iVar3 == 0) {
        iVar3 = 3;
        if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x140) != 0)) &&
           (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x140) + 0x38), pcVar2 != (code *)0x0)) {
          iVar3 = (*pcVar2)(DAT_012164a0,*param_2,2,param_6);
        }
        uVar1 = *param_2;
        lVar4 = *(long *)(param_1 + 0x10);
        (**(code **)(lVar4 + 0x28))(uVar1,3,4);
        (**(code **)(lVar4 + 0x28))(uVar1,2,3);
        return iVar3;
      }
    }
    if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"dmal/common/common_mig.c",0x923,
                   "cMigDeviceGetTotalVolatileEccErrors",0x923,iVar3);
    }
  }
  return iVar3;
}


// ===== 002236f0 FUN_002236f0 =====

int FUN_002236f0(long param_1,undefined4 *param_2,undefined8 param_3)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  
  if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x30) == 0)) ||
     (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0x140), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    iVar3 = (*pcVar2)();
    if (iVar3 == 0) {
      iVar3 = 3;
      if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x68) != 0)) &&
         (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x68) + 0x28), pcVar2 != (code *)0x0)) {
        iVar3 = (*pcVar2)(DAT_012164a0,*param_2,2,param_3);
      }
      uVar1 = *param_2;
      lVar4 = *(long *)(param_1 + 0x10);
      (**(code **)(lVar4 + 0x28))(uVar1,3,4);
      (**(code **)(lVar4 + 0x28))(uVar1,2,3);
      return iVar3;
    }
  }
  if (1 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_mig.c",0x876,"cMigDeviceGetMemoryInfo",0x876,
                 iVar3);
  }
  return iVar3;
}


// ===== 00223840 FUN_00223840 =====

int FUN_00223840(long param_1,undefined4 *param_2,long *param_3)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  
  if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x30) == 0)) ||
     (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0x140), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
  }
  else {
    iVar3 = (*pcVar2)();
    if (iVar3 == 0) {
      if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x68) == 0)) ||
         ((pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x68) + 0x30), pcVar2 == (code *)0x0 ||
          ((iVar3 = (*pcVar2)(DAT_012164a0,*param_2,2,param_3), iVar3 == 0 && (*param_3 == 0)))))) {
        iVar3 = 3;
      }
      uVar1 = *param_2;
      lVar4 = *(long *)(param_1 + 0x10);
      (**(code **)(lVar4 + 0x28))(uVar1,3,4);
      (**(code **)(lVar4 + 0x28))(uVar1,2,3);
      return iVar3;
    }
  }
  if (1 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_mig.c",0x935,"cMigDeviceGetBAR1MemoryInfo",0x935,
                 iVar3);
  }
  return iVar3;
}


// ===== 002239a0 FUN_002239a0 =====

int FUN_002239a0(long param_1,undefined4 *param_2,long param_3)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x30) == 0)) ||
     (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0x140), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
LAB_00223aa6:
    if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"dmal/common/common_mig.c",0x8ab,
                   "cMigDeviceGetRunningProcessDetailList",0x8ab,iVar3);
    }
    return iVar3;
  }
  iVar3 = (*pcVar2)();
  if (iVar3 != 0) goto LAB_00223aa6;
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0xc0) != 0)) &&
     (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0xc0) + 0x18), pcVar2 != (code *)0x0)) {
    iVar3 = (*pcVar2)(DAT_012164a0,*(undefined8 *)(param_2 + 0x26),*(undefined4 *)(param_3 + 4),
                      local_3c,&local_40);
    if (iVar3 != 0) goto LAB_00223b36;
    if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0xc0) != 0)) &&
       (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0xc0) + 0x30), pcVar2 != (code *)0x0)) {
      iVar3 = (*pcVar2)(DAT_012164a0,*param_2,2,local_3c[0],local_40,param_3,0);
      goto LAB_00223b36;
    }
  }
  iVar3 = 3;
LAB_00223b36:
  uVar1 = *param_2;
  lVar4 = *(long *)(param_1 + 0x10);
  (**(code **)(lVar4 + 0x28))(uVar1,3,4);
  (**(code **)(lVar4 + 0x28))(uVar1,2,3);
  return iVar3;
}


// ===== 00223b70 FUN_00223b70 =====

int FUN_00223b70(long param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                undefined8 param_5,undefined8 param_6)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x30) == 0)) ||
     (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0x140), pcVar2 == (code *)0x0)) {
    iVar3 = 3;
LAB_00223c96:
    if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"dmal/common/common_mig.c",0x88c,"cMigDeviceGetRunningProcesses",
                   0x88c,iVar3);
    }
    return iVar3;
  }
  iVar3 = (*pcVar2)(DAT_012164a0,param_3);
  if (iVar3 != 0) goto LAB_00223c96;
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0xc0) != 0)) &&
     (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0xc0) + 0x18), pcVar2 != (code *)0x0)) {
    iVar3 = (*pcVar2)(DAT_012164a0,*(undefined8 *)(param_3 + 0x26),param_4,local_3c,&local_40);
    if (iVar3 != 0) goto LAB_00223d26;
    if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0xc0) != 0)) &&
       (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0xc0) + 0x20), pcVar2 != (code *)0x0)) {
      iVar3 = (*pcVar2)(DAT_012164a0,param_2,*param_3,2,local_3c[0],local_40,param_5,param_6,0);
      goto LAB_00223d26;
    }
  }
  iVar3 = 3;
LAB_00223d26:
  uVar1 = *param_3;
  lVar4 = *(long *)(param_1 + 0x10);
  (**(code **)(lVar4 + 0x28))(uVar1,3,4);
  (**(code **)(lVar4 + 0x28))(uVar1,2,3);
  return iVar3;
}


// ===== 00223d60 FUN_00223d60 =====

undefined8 FUN_00223d60(undefined8 param_1,char *param_2,int param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  int *piVar4;
  
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
    piVar4 = &DAT_003248f0;
    iVar3 = 0x80;
    uVar1 = 0;
    while( true ) {
      if (param_3 == iVar3) {
                    /* WARNING: Could not recover jumptable at 0x00223de6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*(code *)(&PTR_FUN_003248e8)[(ulong)uVar1 * 2])(param_1,param_2,param_4);
        return uVar2;
      }
      uVar1 = uVar1 + 1;
      if (uVar1 == 0x11) break;
      iVar3 = *piVar4;
      piVar4 = piVar4 + 4;
    }
  }
  return 3;
}


// ===== 00223df0 FUN_00223df0 =====

undefined4 FUN_00223df0(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 local_c;
  
  local_c = 0;
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x20) != 0)) &&
     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0x80), pcVar1 != (code *)0x0)) {
    iVar2 = (*pcVar1)(DAT_012164a0,&local_c);
    if (iVar2 == 0) {
      return local_c;
    }
  }
  return 0;
}


// ===== 00223e50 FUN_00223e50 =====

undefined4
FUN_00223e50(long param_1,long param_2,undefined4 param_3,undefined4 *param_4,undefined8 param_5,
            uint param_6)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  ulong uVar4;
  long lVar5;
  float fVar6;
  undefined4 local_3c [3];
  
  lVar5 = *(long *)(param_1 + 0x10);
  iVar2 = FUN_00223d60(param_1,param_2,0x2080,local_3c);
  if (iVar2 == 0) {
    uVar3 = FUN_00223df0();
    *param_4 = uVar3;
    uVar4 = (ulong)param_6;
    iVar2 = (**(code **)(lVar5 + 0x10))(param_2,DAT_0038088c,local_3c[0],uVar3,param_3,param_5);
    if (iVar2 == 0) {
      if (DAT_01216a78 < 4) {
        return 0;
      }
      uVar3 = *(undefined4 *)(param_2 + 4);
      uVar1 = *param_4;
      fVar6 = (float)FUN_002917b0(&DAT_01216a60,uVar4);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %x\n",
                   &DAT_002983c2,lVar5,"dmal/common/common_objects.c",0xe4,uVar1,uVar3);
      return 0;
    }
    if (0 < DAT_01216a78) {
      fVar6 = (float)FUN_002917b0(&DAT_01216a60,uVar4);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t0x%x\n",
                   "CRITICAL",lVar5,"dmal/common/common_objects.c",0xe0,iVar2);
    }
  }
  if (iVar2 == 0xf) {
    uVar3 = 0xf;
  }
  else {
    uVar3 = 999;
  }
  return uVar3;
}


// ===== 00224000 FUN_00224000 =====

undefined4 FUN_00224000(long param_1,long param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  float fVar5;
  undefined8 uVar6;
  undefined4 local_2c;
  
  lVar4 = *(long *)(param_1 + 0x10);
  iVar2 = FUN_00223d60(param_1,param_2,0x80,&local_2c);
  if (iVar2 == 0) {
    uVar3 = FUN_00223df0();
    *param_4 = uVar3;
    uVar6 = 0;
    iVar2 = (**(code **)(lVar4 + 0x10))(param_2,DAT_0038088c,local_2c,uVar3,param_3,0);
    if (iVar2 == 0) {
      if (DAT_01216a78 < 4) {
        return 0;
      }
      uVar3 = *(undefined4 *)(param_2 + 4);
      uVar1 = *param_4;
      fVar5 = (float)FUN_002917b0(&DAT_01216a60,uVar6);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %x\n",
                   &DAT_002983c2,lVar4,"dmal/common/common_objects.c",0xc2,uVar1,uVar3);
      return 0;
    }
    if (0 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60,uVar6);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t0x%x\n",
                   "CRITICAL",lVar4,"dmal/common/common_objects.c",0xbd,iVar2);
    }
  }
  if (iVar2 != 0xf) {
    return 999;
  }
  return 0xf;
}


// ===== 002241b0 FUN_002241b0 =====

undefined4
FUN_002241b0(undefined8 param_1,long param_2,undefined8 param_3,undefined4 param_4,
            undefined8 param_5)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  float fVar5;
  int local_3c [3];
  
  local_3c[0] = 0;
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x58) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x58), pcVar1 == (code *)0x0)) {
    if (DAT_01216a78 < 1) {
      return 999;
    }
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar4,param_2,param_3,local_3c);
    if (iVar2 == 0) {
      if (local_3c[0] != 0) {
        uVar3 = FUN_00223e50(param_1,param_2,param_4,param_5,0,0);
        return uVar3;
      }
      if (1 < DAT_01216a78) {
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                     lVar4,"dmal/common/common_objects.c",0x100);
        return 3;
      }
      return 3;
    }
    if (DAT_01216a78 < 1) goto LAB_00224275;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","CRITICAL",
               lVar4,"dmal/common/common_objects.c",0xfa);
LAB_00224275:
  if (iVar2 != 0xf) {
    return 999;
  }
  return 0xf;
}


// ===== 00224360 FUN_00224360 =====

void FUN_00224360(undefined8 param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 local_30;
  
  if (*(int *)(param_2 + 0x25818) == 0) {
    do {
      iVar1 = FUN_00291820(param_2 + 0x2581c,1,0);
    } while (iVar1 != 0);
    if (*(int *)(param_2 + 0x25818) == 0) {
      local_30 = 0;
      uVar2 = FUN_00223e50(param_1,param_2,0xde,param_2 + 0x25814,&local_30,8);
      *(undefined4 *)(param_2 + 0x25818) = 1;
      *(undefined4 *)(param_2 + 0x25820) = uVar2;
    }
    FUN_00291830(param_2 + 0x2581c,0);
  }
  if (*(int *)(param_2 + 0x25820) == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x25814);
  }
  return;
}


// ===== 00224420 FUN_00224420 =====

void FUN_00224420(long param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  float fVar4;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  if (*(int *)(param_2 + 0x25838) != 0) goto LAB_0022447d;
  do {
    iVar1 = FUN_00291820(param_2 + 0x2583c,1,0);
  } while (iVar1 != 0);
  if (*(int *)(param_2 + 0x25838) == 0) {
    lVar3 = *(long *)(param_1 + 0x10);
    local_3c[0] = 0;
    iVar1 = FUN_00223d60(param_1,param_2,0x2080,&local_40);
    if (iVar1 == 0) {
      uVar2 = FUN_00223df0();
      *(undefined4 *)(param_2 + 0x25834) = uVar2;
      iVar1 = (**(code **)(lVar3 + 0x10))(param_2,DAT_0038088c,local_40,uVar2,0x2081,local_3c);
      uVar2 = 0;
      if (iVar1 != 0) {
        if (0 < DAT_01216a78) {
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t0x%x\n",
                       "CRITICAL",lVar3,"dmal/common/common_objects.c",0x169,iVar1);
        }
        goto joined_r0x00224599;
      }
    }
    else {
joined_r0x00224599:
      if (iVar1 == 0xf) {
        uVar2 = 0xf;
      }
      else {
        uVar2 = 999;
      }
    }
    *(undefined4 *)(param_2 + 0x25840) = uVar2;
    *(undefined4 *)(param_2 + 0x25838) = 1;
  }
  FUN_00291830(param_2 + 0x2583c,0);
LAB_0022447d:
  if (*(int *)(param_2 + 0x25840) == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x25834);
  }
  return;
}


// ===== 002245b0 FUN_002245b0 =====

void FUN_002245b0(long param_1,long param_2,undefined4 *param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  long lVar6;
  float fVar7;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  if (*(int *)(param_2 + 0x25738) != 0) goto LAB_0022460d;
  do {
    iVar3 = FUN_00291820(param_2 + 0x2573c,1,0);
  } while (iVar3 != 0);
  if (*(int *)(param_2 + 0x25738) == 0) {
    lVar6 = *(long *)(param_1 + 0x10);
    local_3c[0] = 0;
    iVar3 = FUN_00223d60(param_1,param_2,0x80,&local_40);
    if (iVar3 == 0) {
      uVar4 = FUN_00223df0();
      lVar1 = *(long *)(param_2 + 0x256d8);
      *(undefined4 *)(param_2 + 0x25734) = uVar4;
      if (((lVar1 == 0) || (*(long *)(lVar1 + 0x60) == 0)) ||
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x60) + 0x10), pcVar2 == (code *)0x0)) {
        iVar5 = 3;
      }
      else {
        iVar5 = (*pcVar2)(lVar1,param_2,local_3c);
        if (iVar5 == 0) {
          iVar3 = (**(code **)(lVar6 + 0x10))
                            (param_2,DAT_0038088c,local_40,*(undefined4 *)(param_2 + 0x25734),0x2080
                             ,local_3c);
          iVar5 = 0;
          if (iVar3 != 0) {
            if (0 < DAT_01216a78) {
              fVar7 = (float)FUN_002917b0(&DAT_01216a60);
              lVar6 = syscall(0xba);
              FUN_002340f0((double)(fVar7 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t0x%x\n","CRITICAL",lVar6,
                           "dmal/common/common_objects.c",0x148,iVar3);
            }
            goto joined_r0x00224776;
          }
          goto LAB_0022466a;
        }
      }
      if (1 < DAT_01216a78) {
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar6 = syscall(0xba);
        FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                     "ERROR",lVar6,"dmal/common/common_objects.c",0x142,"cAllocateNV2080handle",
                     0x142,iVar5);
      }
    }
    else {
joined_r0x00224776:
      if (iVar3 == 0xf) {
        iVar5 = 0xf;
      }
      else {
        iVar5 = 999;
      }
    }
LAB_0022466a:
    *(int *)(param_2 + 0x25740) = iVar5;
    *(undefined4 *)(param_2 + 0x25738) = 1;
  }
  FUN_00291830(param_2 + 0x2573c,0);
LAB_0022460d:
  if (*(int *)(param_2 + 0x25740) == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x25734);
  }
  return;
}


// ===== 00224810 FUN_00224810 =====

void FUN_00224810(long param_1,undefined1 *param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  undefined1 *puVar6;
  uint uVar7;
  float fVar9;
  int local_7c;
  undefined1 local_78 [16];
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined8 local_48;
  ulong uVar8;
  
  if (*(int *)(param_2 + 0x25728) != 0) goto LAB_0022486d;
  do {
    iVar2 = FUN_00291820(param_2 + 0x2572c,1,0);
  } while (iVar2 != 0);
  if (*(int *)(param_2 + 0x25728) == 0) {
    local_48 = 0;
    lVar4 = *(long *)(param_1 + 0x10);
    local_78 = (undefined1  [16])0x0;
    local_68 = (undefined1  [16])0x0;
    local_58 = (undefined1  [16])0x0;
    if (3 < DAT_01216a78) {
      fVar9 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar5,"dmal/common/common_objects.c",0x112);
    }
    lVar5 = *(long *)(param_2 + 0x256d8);
    if (((lVar5 == 0) || (*(long *)(lVar5 + 0x60) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(lVar5 + 0x60) + 0x18), pcVar1 == (code *)0x0)) {
      iVar2 = 3;
LAB_00224902:
      if (1 < DAT_01216a78) {
        fVar9 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                     "ERROR",lVar4,"dmal/common/common_objects.c",0x115,"cAllocateNV0080handle",
                     0x115,iVar2);
      }
    }
    else {
      iVar2 = (*pcVar1)(lVar5,param_2,&local_7c);
      if (iVar2 != 0) goto LAB_00224902;
      if (DAT_01214898 != 0) {
        puVar6 = &DAT_00380898;
        uVar8 = 0;
        do {
          if (((param_2 != puVar6) && (local_7c == *(int *)(puVar6 + 0x256e4))) &&
             ((*(int *)(&DAT_003a5fc0 + uVar8 * 0x74a00) != 0 && (*(int *)(puVar6 + 0x25730) == 0)))
             ) {
            iVar2 = 0;
            *(undefined4 *)(param_2 + 0x25724) = *(undefined4 *)(&DAT_003a5fbc + uVar8 * 0x74a00);
            goto LAB_0022497c;
          }
          uVar7 = (int)uVar8 + 1;
          uVar8 = (ulong)uVar7;
          puVar6 = puVar6 + 0x74a00;
        } while (DAT_01214898 != uVar7);
      }
      uVar3 = FUN_00223df0();
      *(undefined4 *)(param_2 + 0x25724) = uVar3;
      local_78._0_4_ = local_7c;
      iVar2 = (**(code **)(lVar4 + 0x10))(param_2,DAT_0038088c,DAT_0038088c,uVar3,0x80,local_78);
      if (iVar2 != 0) {
        if (0 < DAT_01216a78) {
          fVar9 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t0x%x\n",
                       "CRITICAL",lVar4,"dmal/common/common_objects.c",0x125,iVar2);
        }
        if (iVar2 != 0xf) {
          iVar2 = 999;
        }
      }
    }
LAB_0022497c:
    *(int *)(param_2 + 0x25730) = iVar2;
    *(undefined4 *)(param_2 + 0x25728) = 1;
  }
  FUN_00291830(param_2 + 0x2572c,0);
LAB_0022486d:
  if (*(int *)(param_2 + 0x25730) == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x25724);
  }
  return;
}


// ===== 00224b50 FUN_00224b50 =====

void FUN_00224b50(undefined8 param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_2 + 0x257b8) == 0) {
    do {
      iVar1 = FUN_00291820(param_2 + 0x257bc,1,0);
    } while (iVar1 != 0);
    if (*(int *)(param_2 + 0x257b8) == 0) {
      uVar2 = FUN_00224000(param_1,param_2,0xa083,param_2 + 0x257b4);
      *(undefined4 *)(param_2 + 0x257b8) = 1;
      *(undefined4 *)(param_2 + 0x257c0) = uVar2;
    }
    FUN_00291830(param_2 + 0x257bc,0);
  }
  if (*(int *)(param_2 + 0x257c0) == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x257b4);
  }
  return;
}


// ===== 00224c00 FUN_00224c00 =====

void FUN_00224c00(undefined8 param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_2 + 0x25798) == 0) {
    do {
      iVar1 = FUN_00291820(param_2 + 0x2579c,1,0);
    } while (iVar1 != 0);
    if (*(int *)(param_2 + 0x25798) == 0) {
      uVar2 = FUN_00223e50(param_1,param_2,0x208f,param_2 + 0x25794,0,0);
      *(undefined4 *)(param_2 + 0x25798) = 1;
      *(undefined4 *)(param_2 + 0x257a0) = uVar2;
    }
    FUN_00291830(param_2 + 0x2579c,0);
  }
  if (*(int *)(param_2 + 0x257a0) == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x25794);
  }
  return;
}


// ===== 00224cb0 FUN_00224cb0 =====

void FUN_00224cb0(undefined8 param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_2 + 0x257a8) == 0) {
    do {
      iVar1 = FUN_00291820(param_2 + 0x257ac,1,0);
    } while (iVar1 != 0);
    if (*(int *)(param_2 + 0x257a8) == 0) {
      uVar2 = FUN_00223e50(param_1,param_2,0xa081,param_2 + 0x257a4,0,0);
      *(undefined4 *)(param_2 + 0x257a8) = 1;
      *(undefined4 *)(param_2 + 0x257b0) = uVar2;
    }
    FUN_00291830(param_2 + 0x257ac,0);
  }
  if (*(int *)(param_2 + 0x257b0) == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x257a4);
  }
  return;
}


// ===== 00224d60 FUN_00224d60 =====

void FUN_00224d60(undefined8 param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_2 + 0x25788) == 0) {
    do {
      iVar1 = FUN_00291820(param_2 + 0x2578c,1,0);
    } while (iVar1 != 0);
    if (*(int *)(param_2 + 0x25788) == 0) {
      uVar2 = FUN_00224000(param_1,param_2,0x73,param_2 + 0x25784);
      *(undefined4 *)(param_2 + 0x25788) = 1;
      *(undefined4 *)(param_2 + 0x25790) = uVar2;
    }
    FUN_00291830(param_2 + 0x2578c,0);
  }
  if (*(int *)(param_2 + 0x25790) == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x25784);
  }
  return;
}


// ===== 00224e10 FUN_00224e10 =====

void FUN_00224e10(undefined8 param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_2 + 0x257e8) == 0) {
    do {
      iVar1 = FUN_00291820(param_2 + 0x257ec,1,0);
    } while (iVar1 != 0);
    if (*(int *)(param_2 + 0x257e8) == 0) {
      uVar2 = FUN_002241b0(param_1,param_2,0x20,0xc0e1,param_2 + 0x257e4);
      *(undefined4 *)(param_2 + 0x257e8) = 1;
      *(undefined4 *)(param_2 + 0x257f0) = uVar2;
    }
    FUN_00291830(param_2 + 0x257ec,0);
  }
  if (*(int *)(param_2 + 0x257f0) == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x257e4);
  }
  return;
}


// ===== 00224ec0 FUN_00224ec0 =====

void FUN_00224ec0(undefined8 param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_2 + 0x25748) == 0) {
    do {
      iVar1 = FUN_00291820(param_2 + 0x2574c,1,0);
    } while (iVar1 != 0);
    if (*(int *)(param_2 + 0x25748) == 0) {
      uVar2 = FUN_002241b0(param_1,param_2,1,0x90e0,param_2 + 0x25744);
      *(undefined4 *)(param_2 + 0x25748) = 1;
      *(undefined4 *)(param_2 + 0x25750) = uVar2;
    }
    FUN_00291830(param_2 + 0x2574c,0);
  }
  if (*(int *)(param_2 + 0x25750) == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x25744);
  }
  return;
}


// ===== 00224f70 FUN_00224f70 =====

void FUN_00224f70(undefined8 param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_2 + 0x25758) == 0) {
    do {
      iVar1 = FUN_00291820(param_2 + 0x2575c,1,0);
    } while (iVar1 != 0);
    if (*(int *)(param_2 + 0x25758) == 0) {
      uVar2 = FUN_002241b0(param_1,param_2,2,0x90e1,param_2 + 0x25754);
      *(undefined4 *)(param_2 + 0x25758) = 1;
      *(undefined4 *)(param_2 + 0x25760) = uVar2;
    }
    FUN_00291830(param_2 + 0x2575c,0);
  }
  if (*(int *)(param_2 + 0x25760) == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x25754);
  }
  return;
}


// ===== 00225020 FUN_00225020 =====

void FUN_00225020(undefined8 param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_2 + 0x25808) == 0) {
    do {
      iVar1 = FUN_00291820(param_2 + 0x2580c,1,0);
    } while (iVar1 != 0);
    if (*(int *)(param_2 + 0x25808) == 0) {
      uVar2 = FUN_002241b0(param_1,param_2,0x1000,0xc3e1,param_2 + 0x25804);
      *(undefined4 *)(param_2 + 0x25808) = 1;
      *(undefined4 *)(param_2 + 0x25810) = uVar2;
    }
    FUN_00291830(param_2 + 0x2580c,0);
  }
  if (*(int *)(param_2 + 0x25810) == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x25804);
  }
  return;
}


// ===== 002250d0 FUN_002250d0 =====

void FUN_002250d0(undefined8 param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_2 + 0x25768) == 0) {
    do {
      iVar1 = FUN_00291820(param_2 + 0x2576c,1,0);
    } while (iVar1 != 0);
    if (*(int *)(param_2 + 0x25768) == 0) {
      uVar2 = FUN_002241b0(param_1,param_2,4,0xa0e0,param_2 + 0x25764);
      *(undefined4 *)(param_2 + 0x25768) = 1;
      *(undefined4 *)(param_2 + 0x25770) = uVar2;
    }
    FUN_00291830(param_2 + 0x2576c,0);
  }
  if (*(int *)(param_2 + 0x25770) == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x25764);
  }
  return;
}


// ===== 00225180 FUN_00225180 =====

void FUN_00225180(undefined8 param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_2 + 0x257d8) == 0) {
    do {
      iVar1 = FUN_00291820(param_2 + 0x257dc,1,0);
    } while (iVar1 != 0);
    if (*(int *)(param_2 + 0x257d8) == 0) {
      uVar2 = FUN_002241b0(param_1,param_2,0x10,0xc0e0,param_2 + 0x257d4);
      *(undefined4 *)(param_2 + 0x257d8) = 1;
      *(undefined4 *)(param_2 + 0x257e0) = uVar2;
    }
    FUN_00291830(param_2 + 0x257dc,0);
  }
  if (*(int *)(param_2 + 0x257e0) == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x257d4);
  }
  return;
}


// ===== 00225230 FUN_00225230 =====

void FUN_00225230(undefined8 param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_2 + 0x25778) == 0) {
    do {
      iVar1 = FUN_00291820(param_2 + 0x2577c,1,0);
    } while (iVar1 != 0);
    if (*(int *)(param_2 + 0x25778) == 0) {
      uVar2 = FUN_002241b0(param_1,param_2,8,0xa0e1,param_2 + 0x25774);
      *(undefined4 *)(param_2 + 0x25778) = 1;
      *(undefined4 *)(param_2 + 0x25780) = uVar2;
    }
    FUN_00291830(param_2 + 0x2577c,0);
  }
  if (*(int *)(param_2 + 0x25780) == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x25774);
  }
  return;
}


// ===== 002252e0 FUN_002252e0 =====

void FUN_002252e0(undefined8 param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_2 + 0x25828) == 0) {
    do {
      iVar1 = FUN_00291820(param_2 + 0x2582c,1,0);
    } while (iVar1 != 0);
    if (*(int *)(param_2 + 0x25828) == 0) {
      uVar2 = FUN_002241b0(param_1,param_2,0x100000,0x90e7,param_2 + 0x25824);
      *(undefined4 *)(param_2 + 0x25828) = 1;
      *(undefined4 *)(param_2 + 0x25830) = uVar2;
    }
    FUN_00291830(param_2 + 0x2582c,0);
  }
  if (*(int *)(param_2 + 0x25830) == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x25824);
  }
  return;
}


// ===== 00225390 FUN_00225390 =====

void FUN_00225390(undefined8 param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_2 + 0x257f8) == 0) {
    do {
      iVar1 = FUN_00291820(param_2 + 0x257fc,1,0);
    } while (iVar1 != 0);
    if (*(int *)(param_2 + 0x257f8) == 0) {
      uVar2 = FUN_002241b0(param_1,param_2,0x800,0xc3e0,param_2 + 0x257f4);
      *(undefined4 *)(param_2 + 0x257f8) = 1;
      *(undefined4 *)(param_2 + 0x25800) = uVar2;
    }
    FUN_00291830(param_2 + 0x257fc,0);
  }
  if (*(int *)(param_2 + 0x25800) == 0) {
    *param_3 = *(undefined4 *)(param_2 + 0x257f4);
  }
  return;
}


// ===== 00225440 FUN_00225440 =====

undefined8 FUN_00225440(undefined4 param_1,undefined4 *param_2)

{
  switch(param_1) {
  case 0x5e:
    *param_2 = 2;
    return 0;
  case 0x5f:
    *param_2 = 4;
    return 0;
  default:
    return 3;
  case 0xa9:
    *param_2 = 0x2000;
    return 0;
  case 0xad:
    *param_2 = 0x400000;
    return 0;
  case 0xae:
    *param_2 = 0x400;
    return 0;
  case 0xaf:
    *param_2 = 1;
    return 0;
  case 0xb0:
    *param_2 = 0x10;
    return 0;
  case 0xb1:
    *param_2 = 0x200;
    return 0;
  case 0xb2:
    *param_2 = 8;
    return 0;
  case 0xb3:
    *param_2 = 0x800000;
    return 0;
  case 0xb4:
    *param_2 = 0x1000000;
    return 0;
  case 0xb5:
    *param_2 = 0x2000000;
    return 0;
  case 0xb6:
    *param_2 = 0x80;
    return 0;
  case 0xb7:
    *param_2 = 0x800;
    return 0;
  }
}


// ===== 00225550 FUN_00225550 =====

int FUN_00225550(undefined8 param_1,long param_2,undefined4 param_3,undefined4 *param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  uint local_30;
  uint local_2c;
  
  if (((*(long *)(param_2 + 0x256d8) == 0) ||
      (lVar3 = *(long *)(*(long *)(param_2 + 0x256d8) + 0x48), lVar3 == 0)) ||
     (pcVar1 = *(code **)(lVar3 + 0x90), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      FUN_00292f00(0x14);
      lVar3 = *(long *)(param_2 + 0x256d8);
      if (((lVar3 == 0) || (*(long *)(lVar3 + 0x48) == 0)) ||
         (pcVar1 = *(code **)(*(long *)(lVar3 + 0x48) + 0x90), pcVar1 == (code *)0x0)) {
        iVar2 = 3;
      }
      else {
        iVar2 = (*pcVar1)(lVar3,param_2,param_3,&local_2c);
        if (iVar2 == 0) {
          if (local_2c < local_30) {
            local_2c = local_2c - 1;
          }
          *param_4 = (int)(((ulong)(local_2c - local_30) * 1000) / 0x5000);
          return 0;
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0x6ee;
      uVar4 = 0x6ee;
      goto LAB_0022560d;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  fVar5 = fVar5 * DAT_00298548;
  uVar6 = 0x6ea;
  uVar4 = 0x6ea;
LAB_0022560d:
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
               "dmal/common/common_pci.c",uVar4,"cDeviceGetPcieThroughput",uVar6,iVar2);
  return iVar2;
}


// ===== 00225750 FUN_00225750 =====

uint FUN_00225750(long param_1,long param_2,long param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  undefined8 *puVar4;
  float fVar5;
  undefined4 local_2bc;
  undefined1 local_2b8 [16];
  undefined8 local_2a8;
  undefined4 local_29c;
  undefined4 local_298;
  undefined8 local_16c;
  undefined4 local_160;
  undefined4 local_15c;
  
  local_2b8 = (undefined1  [16])0x0;
  puVar4 = &local_2a8;
  for (lVar3 = 0x4f; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    uVar2 = 3;
  }
  else {
    uVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_2bc);
    if (uVar2 == 0) {
      local_2a8 = 0x20000009f;
      local_29c = *(undefined4 *)(param_3 + 4);
      local_16c = 0x20000009e;
      local_298 = 0x200000;
      local_15c = 0x200000;
      local_2b8._0_4_ = 2;
      local_2b8._8_8_ = &local_2a8;
      local_160 = local_29c;
      uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_2bc,0x2080e078,
                           local_2b8,0x10,0);
      if (0x66 < uVar2) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002d7580 + (ulong)uVar2 * 2);
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_pci.c",0x657,"cDeviceSetPciGen_v1",0x657,uVar2);
  return uVar2;
}


// ===== 00225950 FUN_00225950 =====

int FUN_00225950(long param_1,long param_2,uint param_3,undefined4 *param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  float fVar5;
  undefined4 local_1ec;
  undefined8 local_1e8;
  undefined4 local_1e0;
  
  puVar4 = &local_1e8;
  for (lVar3 = 0x34; lVar3 != 0; lVar3 = lVar3 + -1) {
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
    iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_1ec);
    if (iVar2 == 0) {
      local_1e8._0_4_ = 1;
      if ((param_3 & 0xfffffffd) != 0) {
        local_1e8._4_4_ = param_3;
        iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_1ec,0x20801823,
                             &local_1e8,0x1a4,0);
        switch(iVar2) {
        case 0:
          *param_4 = local_1e0;
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
        return 2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n","DEBUG",
                   lVar3,"dmal/common/common_pci.c",0x54a,2);
      return 2;
    }
  }
  if (1 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar3,"dmal/common/common_pci.c",0x53d,"cDeviceGetBusInfo",0x53d,iVar2);
  }
  return iVar2;
}


// ===== 00225be0 FUN_00225be0 =====

int FUN_00225be0(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  float fVar4;
  undefined8 uVar5;
  uint local_2c;
  
  iVar1 = FUN_00225950(param_1,param_2,3,&local_2c);
  if (iVar1 == 0) {
    switch(local_2c & 0xf) {
    default:
      if (4 < DAT_01216a78) {
        fVar4 = (float)FUN_002917b0(&DAT_01216a60);
        lVar2 = syscall(0xba);
        FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n",
                     "DEBUG",lVar2,"dmal/common/common_pci.c",0x591,local_2c & 0xf);
      }
      *param_3 = 0;
      iVar1 = 2;
      if (1 < DAT_01216a78) {
        fVar4 = (float)FUN_002917b0(&DAT_01216a60);
        lVar2 = syscall(0xba);
        iVar1 = 2;
        fVar4 = fVar4 * DAT_00298548;
        uVar5 = 0x5a8;
        uVar3 = 0x5a8;
        goto LAB_00225c75;
      }
      break;
    case 1:
      *param_3 = 1;
      break;
    case 2:
      *param_3 = 2;
      break;
    case 3:
      *param_3 = 3;
      break;
    case 4:
      *param_3 = 4;
      break;
    case 5:
      *param_3 = 5;
      break;
    case 6:
      *param_3 = 6;
    }
  }
  else if (1 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    fVar4 = fVar4 * DAT_00298548;
    uVar5 = 0x5a5;
    uVar3 = 0x5a5;
LAB_00225c75:
    FUN_002340f0((double)fVar4,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
                 "dmal/common/common_pci.c",uVar3,"cDeviceGetPcieLinkMaxSpeed",uVar5,iVar1);
    return iVar1;
  }
  return iVar1;
}


// ===== 00225e00 FUN_00225e00 =====

int FUN_00225e00(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  iVar1 = FUN_00225950(param_1,param_2,1,param_3);
  if ((iVar1 != 0) && (1 < DAT_01216a78)) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar2,"dmal/common/common_pci.c",0x564,"cDeviceGetIrqNum",0x564,iVar1);
    return iVar1;
  }
  return iVar1;
}


// ===== 00225eb0 FUN_00225eb0 =====

uint FUN_00225eb0(long param_1,long param_2,undefined4 param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  float fVar4;
  undefined4 local_30;
  undefined4 local_2c [3];
  
  local_2c[0] = 0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    uVar2 = 3;
  }
  else {
    uVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_30);
    if (uVar2 == 0) {
      switch(param_3) {
      case 0:
        local_2c[0] = 1;
        break;
      case 1:
        local_2c[0] = 2;
        break;
      case 2:
        local_2c[0] = 4;
        break;
      case 3:
        local_2c[0] = 8;
        break;
      case 4:
        local_2c[0] = 0x10;
        break;
      case 5:
        local_2c[0] = 0x20;
        break;
      case 6:
        local_2c[0] = 0x40;
        break;
      default:
        return 2;
      }
      uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_30,0x20801820,local_2c
                           ,4,0);
      if (0x66 < uVar2) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002d7580 + (ulong)uVar2 * 2);
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar2;
  }
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_pci.c",0x50a,"cDeviceClearPcieUtil",0x50a,uVar2);
  return uVar2;
}


// ===== 00226080 FUN_00226080 =====

uint FUN_00226080(long param_1,long param_2,undefined4 param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_24 = 0;
  uVar2 = FUN_00225440(param_3,&local_1c);
  if (uVar2 == 0) {
    lVar3 = *(long *)(param_2 + 0x256d8);
    if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
      uVar2 = 3;
    }
    else {
      uVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_20);
      if (uVar2 == 0) {
        local_24 = local_1c;
        uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_20,0x20801814,
                             &local_24,4,0);
        if (0x66 < uVar2) {
          return 999;
        }
        return (uint)*(ushort *)(&DAT_002d7580 + (ulong)uVar2 * 2);
      }
    }
    if (DAT_01216a78 < 2) {
      return uVar2;
    }
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    fVar5 = fVar5 * DAT_00298548;
    uVar6 = 0x4b3;
    uVar4 = 0x4b3;
  }
  else {
    if (DAT_01216a78 < 2) {
      return uVar2;
    }
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    fVar5 = fVar5 * DAT_00298548;
    uVar6 = 0x4af;
    uVar4 = 0x4af;
  }
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
               "dmal/common/common_pci.c",uVar4,"cDeviceClearPciePexCnt",uVar6,uVar2);
  return uVar2;
}


// ===== 00226250 FUN_00226250 =====

int FUN_00226250(long param_1,long param_2,int param_3,uint param_4,uint *param_5)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  uint uVar6;
  undefined8 *puVar7;
  uint uVar8;
  undefined8 uVar9;
  char *pcVar10;
  float fVar11;
  double dVar12;
  undefined8 uVar13;
  undefined4 local_ac;
  undefined1 local_a8 [16];
  undefined2 local_98;
  undefined8 local_88;
  ushort auStack_7a [37];
  
  puVar7 = &local_88;
  for (lVar4 = 9; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined4 *)puVar7 = 0;
  if (param_3 == 0xb7) {
    local_98 = 0;
    local_a8 = (undefined1  [16])0x0;
    if (0xf < param_4) {
      return 2;
    }
    lVar4 = *(long *)(param_2 + 0x256d8);
    if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)) {
      iVar2 = 3;
    }
    else {
      iVar2 = (*pcVar1)(lVar4,param_2,0x2080,&local_ac);
      if (iVar2 == 0) {
        iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_ac,0x20801816,
                             local_a8,0x12,0);
        switch(iVar2) {
        case 0:
          *param_5 = (uint)(byte)local_a8[(ulong)param_4 + 2];
          return iVar2;
        default:
          return 999;
        case 3:
        case 0x66:
          goto switchD_00226515_caseD_3;
        case 0xf:
          return iVar2;
        case 0x17:
        case 99:
switchD_00226515_caseD_17:
          return 0x13;
        case 0x1a:
switchD_00226515_caseD_1a:
          return 0x17;
        case 0x1b:
switchD_00226515_caseD_1b:
          return 4;
        case 0x1f:
        case 0x3b:
        case 0x54:
switchD_00226515_caseD_1f:
          return 2;
        case 0x51:
switchD_00226515_caseD_51:
          return 0x14;
        case 0x55:
switchD_00226515_caseD_55:
          return 0x1b;
        case 0x56:
switchD_00226515_caseD_56:
          return 3;
        case 0x59:
switchD_00226515_caseD_59:
          return 0x11;
        case 0x62:
switchD_00226515_caseD_62:
          return 0x10;
        }
      }
    }
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar11 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    pcVar10 = "cDeviceGetPciPexLaneErrorCnt";
    uVar13 = 0x432;
    uVar9 = 0x432;
    dVar12 = (double)(fVar11 * DAT_00298548);
  }
  else {
    iVar2 = FUN_00225440(param_3,local_a8);
    if (iVar2 == 0) {
      lVar4 = *(long *)(param_2 + 0x256d8);
      if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
         (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)) {
        iVar2 = 3;
      }
      else {
        iVar2 = (*pcVar1)(lVar4,param_2,0x2080,&local_ac);
        if (iVar2 == 0) {
          local_88._0_4_ = local_a8._0_4_;
          iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_ac,0x20801813,
                               &local_88,0x4c,0);
          switch(iVar2) {
          case 0:
            uVar8 = 0;
            if ((local_a8._0_4_ & 0xffff0000) != 0) {
              uVar8 = 0x10;
            }
            uVar6 = 0;
            if ((local_a8._0_4_ & 0xff00ff00) != 0) {
              uVar6 = 8;
            }
            uVar5 = 0;
            if ((local_a8._0_4_ & 0xf0f0f0f0) != 0) {
              uVar5 = 4;
            }
            uVar3 = 0;
            if ((local_a8._0_4_ & 0xcccccccc) != 0) {
              uVar3 = 2;
            }
            *param_5 = (uint)auStack_7a
                             [(local_a8._0_4_ & 0xaaaaaaaa) != 0 | uVar8 | uVar6 | uVar5 | uVar3];
            return iVar2;
          default:
            return 999;
          case 3:
          case 0x66:
switchD_00226515_caseD_3:
            return 10;
          case 0xf:
            return iVar2;
          case 0x17:
          case 99:
            goto switchD_00226515_caseD_17;
          case 0x1a:
            goto switchD_00226515_caseD_1a;
          case 0x1b:
            goto switchD_00226515_caseD_1b;
          case 0x1f:
          case 0x3b:
          case 0x54:
            goto switchD_00226515_caseD_1f;
          case 0x51:
            goto switchD_00226515_caseD_51;
          case 0x55:
            goto switchD_00226515_caseD_55;
          case 0x56:
            goto switchD_00226515_caseD_56;
          case 0x59:
            goto switchD_00226515_caseD_59;
          case 0x62:
            goto switchD_00226515_caseD_62;
          }
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar11 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      pcVar10 = "cDeviceGetPciePexCnt";
      uVar13 = 0x496;
      uVar9 = 0x496;
      dVar12 = (double)(fVar11 * DAT_00298548);
    }
    else {
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar11 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      pcVar10 = "cDeviceGetPciePexCnt";
      uVar13 = 0x492;
      uVar9 = 0x492;
      dVar12 = (double)(fVar11 * DAT_00298548);
    }
  }
  FUN_002340f0(dVar12,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
               "dmal/common/common_pci.c",uVar9,pcVar10,uVar13,iVar2);
  return iVar2;
}


// ===== 00226680 FUN_00226680 =====

int FUN_00226680(long param_1,long param_2,uint *param_3,uint param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  undefined4 local_44;
  undefined8 local_40;
  undefined1 local_38 [16];
  
  local_40 = 0;
  local_38 = (undefined1  [16])0x0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_44);
    if (iVar2 == 0) {
      local_38._8_8_ = &local_40;
      local_38._0_4_ = 1;
      local_40._0_4_ = 0x12;
      iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_44,0x20801802,local_38
                           ,0x10,0);
      switch(iVar2) {
      case 0:
        goto switchD_002267f0_caseD_0;
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
               "ERROR",lVar3,"dmal/common/common_pci.c",0x3a1,"cDeviceClearPcieLinkRootError",0x3a1,
               iVar2);
  return iVar2;
switchD_002267f0_caseD_0:
  if (((local_40._4_4_ & 1) == 0) || (((local_40._4_4_ & 0x10) != 0 && ((param_4 & 1) != 0)))) {
    *param_3 = 0;
  }
  else {
    *param_3 = 1;
  }
  if ((local_40._4_4_ & 2) != 0) {
    *param_3 = *param_3 | 2;
  }
  if ((local_40._4_4_ & 4) != 0) {
    *param_3 = *param_3 | 4;
  }
  if ((local_40._4_4_ & 8) != 0) {
    *param_3 = *param_3 | 8;
    return iVar2;
  }
  return 0;
}


// ===== 002268e0 FUN_002268e0 =====

int FUN_002268e0(long param_1,long param_2,uint *param_3,uint param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  undefined4 local_44;
  undefined8 local_40;
  undefined1 local_38 [16];
  
  local_40 = 0;
  local_38 = (undefined1  [16])0x0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_44);
    if (iVar2 == 0) {
      local_38._8_8_ = &local_40;
      local_38._0_4_ = 1;
      local_40._0_4_ = 0x11;
      iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_44,0x20801802,local_38
                           ,0x10,0);
      switch(iVar2) {
      case 0:
        goto switchD_00226a50_caseD_0;
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
               "ERROR",lVar3,"dmal/common/common_pci.c",0x368,"cDeviceClearPcieLinkGpuError",0x368,
               iVar2);
  return iVar2;
switchD_00226a50_caseD_0:
  if (((local_40._4_4_ & 1) == 0) || (((local_40._4_4_ & 0x10) != 0 && ((param_4 & 1) != 0)))) {
    *param_3 = 0;
  }
  else {
    *param_3 = 1;
  }
  if ((local_40._4_4_ & 2) != 0) {
    *param_3 = *param_3 | 2;
  }
  if ((local_40._4_4_ & 4) != 0) {
    *param_3 = *param_3 | 4;
  }
  if ((local_40._4_4_ & 8) != 0) {
    *param_3 = *param_3 | 8;
    return iVar2;
  }
  return 0;
}


// ===== 00226b40 FUN_00226b40 =====

int FUN_00226b40(long param_1,long param_2,uint *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  float fVar5;
  undefined4 local_44;
  undefined8 local_40;
  undefined1 local_38 [24];
  
  local_40 = 0;
  local_38._0_16_ = (undefined1  [16])0x0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_44);
    if (iVar2 == 0) {
      local_38._8_8_ = &local_40;
      local_38._0_4_ = 1;
      local_40._0_4_ = 0x15;
      iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_44,0x20801802,local_38
                           ,0x10,0);
      switch(iVar2) {
      case 0:
        goto switchD_00226ca8_caseD_0;
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
               "ERROR",lVar3,"dmal/common/common_pci.c",0x301,"cDeviceClearPcieLinkAERInfo",0x301,
               iVar2);
  return iVar2;
switchD_00226ca8_caseD_0:
  uVar4 = local_40._4_4_ & 1;
  if ((local_40._4_4_ & 2) != 0) {
    uVar4 = uVar4 | 2;
  }
  *param_3 = uVar4;
  if ((local_40._4_4_ & 4) != 0) {
    *param_3 = *param_3 | 4;
  }
  if ((local_40._4_4_ & 8) != 0) {
    *param_3 = *param_3 | 8;
  }
  if ((local_40._4_4_ & 0x10) != 0) {
    *param_3 = *param_3 | 0x10;
  }
  if ((local_40._4_4_ & 0x20) != 0) {
    *param_3 = *param_3 | 0x20;
  }
  if ((local_40._4_4_ & 0x40) != 0) {
    *param_3 = *param_3 | 0x40;
  }
  if ((local_40._4_4_ & 0x80) != 0) {
    *param_3 = *param_3 | 0x80;
  }
  if ((local_40._4_4_ & 0x100) != 0) {
    *param_3 = *param_3 | 0x100;
  }
  if ((local_40._4_4_ & 0x200) != 0) {
    *param_3 = *param_3 | 0x200;
  }
  if ((local_40._4_4_ & 0x400) != 0) {
    *param_3 = *param_3 | 0x400;
  }
  if ((local_40._4_4_ & 0x10000) != 0) {
    *param_3 = *param_3 | 0x10000;
  }
  if ((local_40._4_4_ & 0x20000) != 0) {
    *param_3 = *param_3 | 0x20000;
  }
  if ((local_40._4_4_ & 0x40000) != 0) {
    *param_3 = *param_3 | 0x40000;
  }
  if ((local_40._4_4_ & 0x80000) != 0) {
    *param_3 = *param_3 | 0x80000;
  }
  if ((local_40._4_4_ & 0x100000) != 0) {
    *param_3 = *param_3 | 0x100000;
  }
  if ((local_40._4_4_ & 0x200000) != 0) {
    *param_3 = *param_3 | 0x200000;
    return iVar2;
  }
  return 0;
}


// ===== 00226e10 FUN_00226e10 =====

int FUN_00226e10(long param_1,long param_2,uint *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  float fVar5;
  undefined4 local_44;
  undefined8 local_40;
  undefined1 local_38 [24];
  
  local_40 = 0;
  local_38._0_16_ = (undefined1  [16])0x0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_44);
    if (iVar2 == 0) {
      local_38._8_8_ = &local_40;
      local_38._0_4_ = 1;
      local_40._0_4_ = 10;
      iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_44,0x20801802,local_38
                           ,0x10,0);
      switch(iVar2) {
      case 0:
        goto switchD_00226f78_caseD_0;
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
               "ERROR",lVar3,"dmal/common/common_pci.c",0x2d5,
               "cDeviceGetCurrentPcieDownstreamLinkWidth",0x2d5,iVar2);
  return iVar2;
switchD_00226f78_caseD_0:
  uVar4 = local_40._4_4_ >> 0x14 & 0x3f;
  *param_3 = uVar4;
  if (uVar4 - 1 < 0x20) {
    return iVar2;
  }
  if (DAT_01216a78 < 2) {
    return 999;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","ERROR",
               lVar3,"dmal/common/common_pci.c",0x2e9,uVar4);
  return 999;
}


// ===== 002270c0 FUN_002270c0 =====

uint FUN_002270c0(long param_1,long param_2,uint param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  float fVar4;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (param_3 == 16000) {
    local_20 = 4;
  }
  else if (param_3 < 0x3e81) {
    if (param_3 == 5000) {
      local_20 = 2;
    }
    else {
      if (param_3 != 8000) {
        if (param_3 != 0x9c4) {
          return 2;
        }
        lVar3 = *(long *)(param_2 + 0x256d8);
        local_20 = 1;
        goto joined_r0x00227116;
      }
      local_20 = 3;
    }
  }
  else if (param_3 == 32000) {
    local_20 = 5;
  }
  else {
    if (param_3 != 64000) {
      return 2;
    }
    local_20 = 6;
  }
  lVar3 = *(long *)(param_2 + 0x256d8);
joined_r0x00227116:
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    uVar2 = 3;
  }
  else {
    uVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_1c);
    if (uVar2 == 0) {
      uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_1c,0x20801805,
                           &local_20,4,0);
      if (uVar2 < 0x67) {
        return (uint)*(ushort *)(&DAT_002d7580 + (ulong)uVar2 * 2);
      }
      return 999;
    }
  }
  if (1 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar3,"dmal/common/common_pci.c",700,"cDeviceSetPcieSpeed",700,uVar2);
    return uVar2;
  }
  return uVar2;
}


// ===== 002272d0 FUN_002272d0 =====

ulong FUN_002272d0(long param_1,long param_2)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  float fVar5;
  undefined4 local_44;
  undefined8 local_40;
  undefined1 local_38 [24];
  
  local_40 = 0;
  local_38._0_16_ = (undefined1  [16])0x0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    uVar4 = 3;
  }
  else {
    uVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_44);
    uVar4 = (ulong)uVar2;
    if (uVar2 == 0) {
      local_38._8_8_ = &local_40;
      local_38._0_4_ = 1;
      local_40 = CONCAT44(local_40._4_4_,7);
      uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_44,0x20801802,local_38
                           ,0x10,0);
      switch(uVar2) {
      case 0:
        if ((local_40._6_2_ & 0xf) < 7) {
                    /* WARNING: Could not recover jumptable at 0x002274b1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar4 = (*(code *)(&DAT_002d64c4 +
                            *(int *)(&DAT_002d64c4 + (ulong)(local_40._6_2_ & 0xf) * 4)))();
          return uVar4;
        }
        break;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return (ulong)uVar2;
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
    return uVar4;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_pci.c",0x26f,"cDeviceGetPcieSpeed",0x26f,uVar4);
  return uVar4;
}


// ===== 00227540 FUN_00227540 =====

uint FUN_00227540(long param_1,long param_2,undefined4 param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  uint uVar3;
  long lVar4;
  float fVar5;
  undefined4 local_34;
  undefined8 local_30;
  
  lVar4 = *(long *)(param_2 + 0x256d8);
  local_30 = 0;
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)) {
    uVar3 = 3;
  }
  else {
    uVar3 = (*pcVar1)(lVar4,param_2,0x2080,&local_34);
    if (uVar3 == 0) {
      local_30._0_4_ = param_3;
      uVar3 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_34,0x20801804,
                           &local_30,8,0);
      uVar2 = local_30._4_4_;
      if (4 < DAT_01216a78) {
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n",
                     "DEBUG",lVar4,"dmal/common/common_pci.c",600,uVar2);
      }
      if (0x66 < uVar3) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002d7580 + (ulong)uVar3 * 2);
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar3;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar4,"dmal/common/common_pci.c",0x250,"cDeviceSetPcieLinkWidth",0x250,uVar3)
  ;
  return uVar3;
}


// ===== 00227730 FUN_00227730 =====

int FUN_00227730(long param_1,long param_2,uint *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  float fVar5;
  undefined4 local_44;
  undefined8 local_40;
  undefined1 local_38 [24];
  
  local_40 = 0;
  local_38._0_16_ = (undefined1  [16])0x0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_44);
    if (iVar2 == 0) {
      local_38._8_8_ = &local_40;
      local_38._0_4_ = 1;
      local_40._0_4_ = 7;
      iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_44,0x20801802,local_38
                           ,0x10,0);
      switch(iVar2) {
      case 0:
        goto switchD_00227898_caseD_0;
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
               "ERROR",lVar3,"dmal/common/common_pci.c",0x227,"cDeviceGetCurrentPcieLinkWidth",0x227
               ,iVar2);
  return iVar2;
switchD_00227898_caseD_0:
  uVar4 = local_40._4_4_ >> 0x14 & 0x3f;
  *param_3 = uVar4;
  if (uVar4 - 1 < 0x20) {
    return iVar2;
  }
  if (DAT_01216a78 < 2) {
    return 999;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","ERROR",
               lVar3,"dmal/common/common_pci.c",0x23b,uVar4);
  return 999;
}


// ===== 002279e0 FUN_002279e0 =====

int FUN_002279e0(long param_1,long param_2,uint *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  float fVar5;
  undefined4 local_44;
  undefined8 local_40;
  undefined1 local_38 [24];
  
  local_40 = 0;
  local_38._0_16_ = (undefined1  [16])0x0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_44);
    if (iVar2 == 0) {
      local_38._8_8_ = &local_40;
      local_38._0_4_ = 1;
      local_40._0_4_ = 3;
      iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_44,0x20801802,local_38
                           ,0x10,0);
      switch(iVar2) {
      case 0:
        goto switchD_00227b48_caseD_0;
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
               "ERROR",lVar3,"dmal/common/common_pci.c",0x1cc,"cDeviceGetMaxPcieWidth",0x1cc,iVar2);
  return iVar2;
switchD_00227b48_caseD_0:
  uVar4 = local_40._4_4_ >> 4 & 0x3f;
  *param_3 = uVar4;
  if (uVar4 - 1 < 0x20) {
    return iVar2;
  }
  if (DAT_01216a78 < 2) {
    return 999;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","ERROR",
               lVar3,"dmal/common/common_pci.c",0x1de,uVar4);
  return 999;
}


// ===== 00227c90 FUN_00227c90 =====

int FUN_00227c90(long param_1,long param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  undefined4 local_44;
  undefined8 local_40;
  undefined1 local_38 [24];
  
  local_40 = 0;
  local_38._0_16_ = (undefined1  [16])0x0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_44);
    if (iVar2 == 0) {
      local_38._8_8_ = &local_40;
      local_38._0_4_ = 1;
      local_40 = local_40 & 0xffffffff00000000;
      iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_44,0x20801802,local_38
                           ,0x10,0);
      switch(iVar2) {
      case 0:
        goto switchD_00227df8_caseD_0;
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
               "ERROR",lVar3,"dmal/common/common_pci.c",0x82,"cDeviceGetPciBusType",0x82,iVar2);
  return iVar2;
switchD_00227df8_caseD_0:
  if (local_40._4_4_ == 4) {
    *param_3 = 3;
    return iVar2;
  }
  if (local_40._4_4_ < 5) {
    if (local_40._4_4_ == 1) {
      *param_3 = 1;
      return iVar2;
    }
    if (local_40._4_4_ == 3) {
      *param_3 = 2;
      return iVar2;
    }
  }
  else if (local_40._4_4_ == 8) {
    *param_3 = 5;
    return iVar2;
  }
  *param_3 = 0;
  return iVar2;
}


// ===== 00227ef0 FUN_00227ef0 =====

ulong FUN_00227ef0(long param_1,long param_2)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  float fVar8;
  undefined8 uVar9;
  undefined4 local_44;
  undefined8 local_40;
  undefined1 local_38 [16];
  
  local_40 = 0;
  local_38 = (undefined1  [16])0x0;
  lVar5 = *(long *)(param_2 + 0x256d8);
  if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar5 + 0x50), pcVar1 == (code *)0x0)) {
    uVar7 = 3;
  }
  else {
    uVar2 = (*pcVar1)(lVar5,param_2,0x2080,&local_44);
    uVar7 = (ulong)uVar2;
    if (uVar2 == 0) {
      if (*(int *)(param_2 + 0x70534) == 0) {
        do {
          iVar3 = FUN_00291820(param_2 + 0x70538,1,0);
        } while (iVar3 != 0);
        if (*(int *)(param_2 + 0x70534) == 0) {
          lVar5 = *(long *)(param_2 + 0x256d8);
          uVar4 = 3;
          if (((lVar5 != 0) && (*(long *)(lVar5 + 0x38) != 0)) &&
             (pcVar1 = *(code **)(*(long *)(lVar5 + 0x38) + 8), pcVar1 != (code *)0x0)) {
            uVar4 = (*pcVar1)(lVar5,param_2,param_2 + 0x70530);
          }
          *(undefined4 *)(param_2 + 0x7053c) = uVar4;
          *(undefined4 *)(param_2 + 0x70534) = 1;
        }
        FUN_00291830(param_2 + 0x70538,0);
        uVar2 = *(uint *)(param_2 + 0x7053c);
      }
      else {
        uVar2 = *(uint *)(param_2 + 0x7053c);
      }
      if (uVar2 == 0) {
        if (*(int *)(param_2 + 0x70530) != 0) {
          return 3;
        }
        local_38._8_8_ = &local_40;
        local_38._0_4_ = 1;
        local_40._4_4_ = (uint)((ulong)local_40 >> 0x20);
        local_40._0_4_ = 4;
        uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_44,0x20801802,
                             local_38,0x10,0);
        switch(uVar2) {
        case 0:
          goto switchD_00227ff9_caseD_0;
        default:
          return 999;
        case 3:
        case 0x66:
          return 10;
        case 0xf:
          return (ulong)uVar2;
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
      uVar7 = (ulong)uVar2;
      if (DAT_01216a78 < 2) {
        return uVar7;
      }
      fVar8 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      fVar8 = fVar8 * DAT_00298548;
      uVar9 = 0x13a;
      uVar6 = 0x13a;
      goto LAB_0022806d;
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar7;
  }
  fVar8 = (float)FUN_002917b0(&DAT_01216a60);
  lVar5 = syscall(0xba);
  fVar8 = fVar8 * DAT_00298548;
  uVar9 = 0x12f;
  uVar6 = 0x12f;
LAB_0022806d:
  FUN_002340f0((double)fVar8,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,
               "dmal/common/common_pci.c",uVar6,"cDeviceGetHostMaxPcieGen",uVar9,uVar7);
  return uVar7;
switchD_00227ff9_caseD_0:
  if ((local_40._4_4_ & 0xf) < 7) {
                    /* WARNING: Could not recover jumptable at 0x002281d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar7 = (*(code *)(&DAT_002d6b50 + *(int *)(&DAT_002d6b50 + (ulong)(local_40._4_4_ & 0xf) * 4)))
                      ();
    return uVar7;
  }
  if (DAT_01216a78 < 5) {
    return 999;
  }
  uVar4 = *(undefined4 *)(param_2 + 4);
  fVar8 = (float)FUN_002917b0(&DAT_01216a60);
  lVar5 = syscall(0xba);
  FUN_002340f0((double)(fVar8 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
               lVar5,"dmal/common/common_pci.c",0x174,uVar4);
  return 999;
}


// ===== 002282f0 FUN_002282f0 =====

undefined4 FUN_002282f0(long param_1,long param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  code *pcVar5;
  int iVar6;
  long lVar7;
  uint *extraout_RDX;
  uint *extraout_RDX_00;
  uint *extraout_RDX_01;
  uint *puVar8;
  float fVar9;
  undefined4 local_4c;
  undefined1 local_48 [16];
  
  if (*(int *)(param_2 + 0x730) != 0) {
    uVar1 = *(undefined4 *)(param_2 + 0x738);
    goto LAB_0022831f;
  }
  do {
    iVar6 = FUN_00291820(param_2 + 0x734,1,0);
  } while (iVar6 != 0);
  puVar8 = extraout_RDX;
  if (*(int *)(param_2 + 0x730) == 0) {
    local_48 = (undefined1  [16])0x0;
    lVar7 = *(long *)(param_2 + 0x256d8);
    if (((lVar7 == 0) || (*(undefined8 **)(lVar7 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar5 = (code *)**(undefined8 **)(lVar7 + 0x50), pcVar5 == (code *)0x0)) {
      iVar6 = 3;
LAB_00228472:
      if (1 < DAT_01216a78) {
        fVar9 = (float)FUN_002917b0(&DAT_01216a60);
        lVar7 = syscall(0xba);
        FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                     "ERROR",lVar7,"dmal/common/common_pci.c",0x13,"cDeviceGetPciDeviceIdUncached",
                     0x13,iVar6);
        puVar8 = extraout_RDX_01;
      }
    }
    else {
      iVar6 = (*pcVar5)(lVar7,param_2,0x2080,&local_4c);
      puVar8 = extraout_RDX_00;
      if (iVar6 != 0) goto LAB_00228472;
      iVar6 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_4c,0x20801801,local_48
                           ,0x10,0);
      puVar8 = &switchD_00228555::switchdataD_002d6b6c;
      switch(iVar6) {
      case 0:
        *(undefined8 *)(param_2 + 0x728) = local_48._0_8_;
        break;
      default:
        iVar6 = 999;
        break;
      case 3:
      case 0x66:
        iVar6 = 10;
        break;
      case 0x17:
      case 99:
        iVar6 = 0x13;
        break;
      case 0x1a:
        iVar6 = 0x17;
        break;
      case 0x1b:
        iVar6 = 4;
        break;
      case 0x1f:
      case 0x3b:
      case 0x54:
        iVar6 = 2;
        break;
      case 0x51:
        iVar6 = 0x14;
        break;
      case 0x55:
        iVar6 = 0x1b;
        break;
      case 0x56:
        iVar6 = 3;
      case 0xf:
        break;
      case 0x59:
        iVar6 = 0x11;
        break;
      case 0x62:
        iVar6 = 0x10;
      }
    }
    *(int *)(param_2 + 0x738) = iVar6;
    *(undefined4 *)(param_2 + 0x730) = 1;
  }
  FUN_00291830(param_2 + 0x734,0,puVar8);
  uVar1 = *(undefined4 *)(param_2 + 0x738);
LAB_0022831f:
  *param_3 = *(undefined8 *)(param_2 + 0x728);
  if (4 < DAT_01216a78) {
    uVar2 = *(undefined4 *)((long)param_3 + 4);
    uVar3 = *(undefined4 *)(param_2 + 4);
    uVar4 = *(undefined4 *)param_3;
    fVar9 = (float)FUN_002917b0(&DAT_01216a60);
    lVar7 = syscall(0xba);
    FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u %u %d\n",
                 "DEBUG",lVar7,"dmal/common/common_pci.c",0x2e,uVar3,uVar4,uVar2,uVar1);
  }
  return uVar1;
}


// ===== 00228640 FUN_00228640 =====

int FUN_00228640(undefined8 param_1,long param_2,int param_3,long param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 uVar5;
  float fVar6;
  undefined8 uVar7;
  undefined4 local_30;
  undefined4 local_2c;
  
  if (*(int *)(param_2 + 0x648) == 0) {
    do {
      iVar2 = FUN_00291820(param_2 + 0x64c,1,0);
    } while (iVar2 != 0);
    if (*(int *)(param_2 + 0x648) == 0) {
      lVar4 = *(long *)(param_2 + 0x256d8);
      uVar3 = 3;
      if (((lVar4 != 0) && (*(long *)(lVar4 + 0x48) != 0)) &&
         (pcVar1 = *(code **)(*(long *)(lVar4 + 0x48) + 8), pcVar1 != (code *)0x0)) {
        uVar3 = (*pcVar1)(lVar4,param_2,param_2 + 0x644);
      }
      *(undefined4 *)(param_2 + 0x650) = uVar3;
      *(undefined4 *)(param_2 + 0x648) = 1;
    }
    FUN_00291830(param_2 + 0x64c,0);
  }
  iVar2 = *(int *)(param_2 + 0x650);
  if (iVar2 == 0) {
    iVar2 = 3;
    if (*(int *)(param_2 + 0x644) != 5) {
      *(uint *)(param_4 + 0x14) = (uint)*(ushort *)(param_2 + 0xc);
      *(uint *)(param_4 + 0x18) = (uint)*(ushort *)(param_2 + 0xe);
      *(undefined4 *)(param_4 + 0x10) = *(undefined4 *)(param_2 + 8);
      FUN_0013ace0(param_3,param_4);
      lVar4 = *(long *)(param_2 + 0x256d8);
      if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x48) == (undefined8 *)0x0)) ||
         ((pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x48), pcVar1 == (code *)0x0 ||
          (iVar2 = (*pcVar1)(lVar4,param_2,&local_30), iVar2 != 0)))) {
        if (1 < DAT_01216a78) {
          fVar6 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          fVar6 = fVar6 * DAT_00298548;
          uVar7 = 0x6c4;
          uVar5 = 0x6c4;
          goto LAB_0022885d;
        }
      }
      else {
        *(undefined4 *)(param_4 + 0x1c) = local_30;
        if (param_3 != 1) {
          *(undefined4 *)(param_4 + 0x20) = local_2c;
        }
      }
    }
  }
  else if (1 < DAT_01216a78) {
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    fVar6 = fVar6 * DAT_00298548;
    uVar7 = 0x6b5;
    uVar5 = 0x6b5;
LAB_0022885d:
    FUN_002340f0((double)fVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
                 "dmal/common/common_pci.c",uVar5,"cDeviceGetGenericPciInfo",uVar7,iVar2);
    return iVar2;
  }
  return iVar2;
}


// ===== 00228890 FUN_00228890 =====

undefined4 FUN_00228890(long param_1,long param_2,int param_3,uint *param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  uint *extraout_RDX;
  uint *extraout_RDX_00;
  uint *puVar5;
  uint *extraout_RDX_01;
  float fVar6;
  uint local_48;
  ulong local_44;
  uint local_3c;
  
  if (param_3 != 0xe4) {
    if (param_3 != 0xe5) {
      return 2;
    }
    if (*(int *)(param_2 + 0x70524) != 0) goto LAB_00228901;
    do {
      iVar2 = FUN_00291820(param_2 + 0x70528,1,0);
    } while (iVar2 != 0);
    puVar5 = extraout_RDX;
    if (*(int *)(param_2 + 0x70524) == 0) {
      local_48 = 0;
      lVar3 = *(long *)(param_2 + 0x256d8);
      if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
         (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
        iVar2 = 3;
LAB_00228b76:
        if (1 < DAT_01216a78) {
          fVar6 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar6 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
                       "dmal/common/common_pci.c",0x5f9,"cDeviceGetInboundPcieAtomicsCapsUncached",
                       0x5f9,iVar2);
          puVar5 = extraout_RDX_01;
        }
      }
      else {
        iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_44);
        puVar5 = extraout_RDX_00;
        if (iVar2 != 0) goto LAB_00228b76;
        iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_44 & 0xffffffff,
                             0x20801830,&local_48,4,0);
        puVar5 = &switchD_00228acf::switchdataD_002d6ea4;
        switch(iVar2) {
        case 0:
          uVar4 = local_48 & 1;
          if ((local_48 & 2) != 0) {
            uVar4 = uVar4 | 2;
          }
          puVar5 = (uint *)(ulong)uVar4;
          *param_4 = uVar4;
          if ((local_48 & 4) != 0) {
            *param_4 = *param_4 | 4;
          }
          if ((local_48 & 8) != 0) {
            *param_4 = *param_4 | 8;
          }
          if ((local_48 & 0x10) != 0) {
            *param_4 = *param_4 | 0x10;
          }
          if ((local_48 & 0x20) != 0) {
            *param_4 = *param_4 | 0x20;
          }
          if ((local_48 & 0x40) == 0) {
            iVar2 = 0;
          }
          else {
            *param_4 = *param_4 | 0x40;
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
      }
      *(int *)(param_2 + 0x7052c) = iVar2;
      *(undefined4 *)(param_2 + 0x70524) = 1;
    }
    FUN_00291830(param_2 + 0x70528,0,puVar5);
LAB_00228901:
    return *(undefined4 *)(param_2 + 0x7052c);
  }
  if (*(int *)(param_2 + 0x70514) != 0) goto LAB_00228965;
  do {
    iVar2 = FUN_00291820(param_2 + 0x70518,1,0);
  } while (iVar2 != 0);
  if (*(int *)(param_2 + 0x70514) == 0) {
    local_44 = 0;
    local_3c = 0;
    lVar3 = *(long *)(param_2 + 0x256d8);
    if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
      iVar2 = 3;
LAB_00228ade:
      if (1 < DAT_01216a78) {
        fVar6 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                     "ERROR",lVar3,"dmal/common/common_pci.c",0x5ba,
                     "cDeviceGetOutboundPcieAtomicsCapsUncached",0x5ba,iVar2);
      }
    }
    else {
      iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_48);
      if (iVar2 != 0) goto LAB_00228ade;
      local_44 = CONCAT44(local_44._4_4_,1);
      iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_48,0x20801829,
                           &local_44,0xc,0);
      switch(iVar2) {
      case 0:
        uVar4 = local_3c & 1;
        if ((local_3c & 2) != 0) {
          uVar4 = uVar4 | 2;
        }
        *param_4 = uVar4;
        if ((local_3c & 4) != 0) {
          *param_4 = *param_4 | 4;
        }
        if ((local_3c & 8) != 0) {
          *param_4 = *param_4 | 8;
        }
        if ((local_3c & 0x10) != 0) {
          *param_4 = *param_4 | 0x10;
        }
        if ((local_3c & 0x20) != 0) {
          *param_4 = *param_4 | 0x20;
        }
        if ((local_3c & 0x40) == 0) {
          iVar2 = 0;
        }
        else {
          *param_4 = *param_4 | 0x40;
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
    }
    *(int *)(param_2 + 0x7051c) = iVar2;
    *(undefined4 *)(param_2 + 0x70514) = 1;
  }
  FUN_00291830(param_2 + 0x70518,0);
LAB_00228965:
  return *(undefined4 *)(param_2 + 0x7051c);
}


// ===== 00228d90 FUN_00228d90 =====

int FUN_00228d90(long param_1,long param_2,undefined4 param_3,undefined4 *param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  float fVar10;
  undefined8 uVar11;
  undefined4 local_5c;
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  
  local_58 = (undefined1  [16])0x0;
  local_48 = (undefined1  [16])0x0;
  if (*(int *)(param_2 + 0x70534) == 0) {
    do {
      iVar2 = FUN_00291820(param_2 + 0x70538,1,0);
    } while (iVar2 != 0);
    if (*(int *)(param_2 + 0x70534) == 0) {
      lVar4 = *(long *)(param_2 + 0x256d8);
      uVar3 = 3;
      if (((lVar4 != 0) && (*(long *)(lVar4 + 0x38) != 0)) &&
         (pcVar1 = *(code **)(*(long *)(lVar4 + 0x38) + 8), pcVar1 != (code *)0x0)) {
        uVar3 = (*pcVar1)(lVar4,param_2,param_2 + 0x70530);
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
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    fVar10 = fVar10 * DAT_00298548;
    uVar11 = 0x4cf;
    uVar9 = 0x4cf;
    goto LAB_00228f61;
  }
  if (*(int *)(param_2 + 0x70530) == 2) {
switchD_0022904a_caseD_56:
    iVar2 = 3;
  }
  else {
    lVar4 = *(long *)(param_2 + 0x256d8);
    if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)) {
      iVar2 = 3;
LAB_00228ee6:
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar10 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      fVar10 = fVar10 * DAT_00298548;
      uVar11 = 0x4d8;
      uVar9 = 0x4d8;
LAB_00228f61:
      FUN_002340f0((double)fVar10,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
                   "dmal/common/common_pci.c",uVar9,"cDeviceGetPcieUtil",uVar11,iVar2);
      return iVar2;
    }
    iVar2 = (*pcVar1)(lVar4,param_2,0x2080,&local_5c);
    if (iVar2 != 0) goto LAB_00228ee6;
    switch(param_3) {
    case 0:
      local_58._0_4_ = 1;
      break;
    case 1:
      local_58._0_4_ = 2;
      break;
    case 2:
      local_58._0_4_ = 4;
      break;
    case 3:
      local_58._0_4_ = 8;
      break;
    case 4:
      local_58._0_4_ = 0x10;
      break;
    case 5:
      local_58._0_4_ = 0x20;
      break;
    case 6:
      local_58._0_4_ = 0x40;
      break;
    default:
      goto switchD_00228e8d_default;
    }
    iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_5c,0x20801819,local_58,
                         0x20,0);
    switch(iVar2) {
    case 0:
      uVar8 = 0;
      if ((local_58._0_4_ & 0xffff0000) != 0) {
        uVar8 = 0x10;
      }
      uVar7 = 0;
      if ((local_58._0_4_ & 0xff00ff00) != 0) {
        uVar7 = 8;
      }
      uVar6 = 0;
      if ((local_58._0_4_ & 0xf0f0f0f0) != 0) {
        uVar6 = 4;
      }
      uVar5 = 0;
      if ((local_58._0_4_ & 0xcccccccc) != 0) {
        uVar5 = 2;
      }
      *param_4 = *(undefined4 *)
                  (local_58 +
                  (ulong)((local_58._0_4_ & 0xaaaaaaaa) != 0 | uVar8 | uVar7 | uVar6 | uVar5) * 4 +
                  4);
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
switchD_00228e8d_default:
      iVar2 = 2;
      break;
    case 0x51:
      iVar2 = 0x14;
      break;
    case 0x55:
      iVar2 = 0x1b;
      break;
    case 0x56:
      goto switchD_0022904a_caseD_56;
    case 0x59:
      iVar2 = 0x11;
      break;
    case 0x62:
      iVar2 = 0x10;
    }
  }
  return iVar2;
}


// ===== 00229160 FUN_00229160 =====

int FUN_00229160(char *param_1,uint *param_2,uint param_3)

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


// ===== 002293f0 FUN_002293f0 =====

undefined8 FUN_002293f0(char *param_1,undefined8 param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  char local_1d;
  int local_1c;
  
  if (DAT_0032f668 != 0) {
    local_1c = 0;
    iVar1 = FUN_00229160(param_1,&local_1c,10);
    if (((iVar1 == 0) && (local_1c != 0)) &&
       ((param_1 == (char *)0x0 || ((*param_1 == '\x01' || (*(long *)(param_1 + 0x20) != 0)))))) {
      lVar3 = *(long *)(param_1 + 0x256d8);
      local_1d = '\0';
      if ((lVar3 != 0) &&
         ((*(long *)(lVar3 + 0x38) != 0 &&
          (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar3 + 0x38) + 0x80),
          UNRECOVERED_JUMPTABLE != (code *)0x0)))) {
        (*UNRECOVERED_JUMPTABLE)(lVar3,param_1,&local_1d);
        if (local_1d != '\0') {
          return 3;
        }
        lVar3 = *(long *)(param_1 + 0x256d8);
      }
      local_1d = '\0';
      if (lVar3 != 0) {
        if ((*(long *)(lVar3 + 0x38) != 0) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar3 + 0x38) + 0x88),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
          (*UNRECOVERED_JUMPTABLE)(lVar3,param_1,&local_1d);
          if (local_1d != '\0') {
            return 3;
          }
          lVar3 = *(long *)(param_1 + 0x256d8);
        }
        if (((lVar3 != 0) && (*(long *)(lVar3 + 0x120) != 0)) &&
           (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar3 + 0x120) + 0x78),
           UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00229501. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar3,param_1,param_2);
          return uVar2;
        }
      }
    }
  }
  return 3;
}


// ===== 00229510 FUN_00229510 =====

int FUN_00229510(long param_1,long param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  undefined4 local_38;
  
  local_38 = 0;
  local_58 = (undefined1  [16])0x0;
  local_48 = (undefined1  [16])0x0;
  if (param_2 == 0) {
    iVar2 = FUN_002293f0(0,local_58);
  }
  else {
    iVar2 = FUN_002293f0(param_2,local_58);
  }
  if (iVar2 == 0) {
    *param_3 = local_58._0_4_;
    return 0;
  }
  local_68 = (undefined1  [16])0x0;
  local_70 = 0;
  uStack_6c = 0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_74);
    if (iVar2 == 0) {
      local_68._8_8_ = &local_70;
      local_68._0_4_ = 1;
      local_70 = 0x2d;
      iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_74,0x20801802,local_68
                           ,0x10,0);
      switch(iVar2) {
      case 0:
        *param_3 = uStack_6c;
        return iVar2;
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
      goto LAB_002296df;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_pci.c",0xc4,"cDeviceGetPciInfoRM",0xc4,iVar2);
LAB_002296df:
  if (1 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar3,"dmal/common/common_pci.c",0xe4,"cDeviceGetPcieGenInfo",0xe4,iVar2);
  }
  return iVar2;
}


// ===== 00229850 FUN_00229850 =====

uint FUN_00229850(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  float fVar4;
  undefined1 local_1c [2];
  ushort local_1a;
  
  uVar1 = FUN_00229510(param_1,param_2,local_1c);
  if (uVar1 == 0) {
    uVar2 = local_1a & 0xf;
    switch(uVar2) {
    case 0:
      *param_3 = 1;
      break;
    case 1:
      *param_3 = 2;
      uVar2 = uVar1;
      break;
    case 2:
      *param_3 = 3;
      uVar2 = uVar1;
      break;
    case 3:
      *param_3 = 4;
      uVar2 = uVar1;
      break;
    case 4:
      *param_3 = 5;
      uVar2 = uVar1;
      break;
    case 5:
      *param_3 = 6;
      uVar2 = uVar1;
      break;
    default:
      uVar2 = 999;
    }
  }
  else {
    uVar2 = uVar1;
    if (1 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar3,"dmal/common/common_pci.c",499,"cDeviceGetCurrentPcieLinkGen",499,
                   uVar1);
      return uVar1;
    }
  }
  return uVar2;
}


// ===== 002299a0 FUN_002299a0 =====

uint FUN_002299a0(undefined8 param_1,long param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  float fVar5;
  uint local_2c [3];
  
  uVar2 = FUN_00229510(param_1,param_2,local_2c);
  if (uVar2 == 0) {
    uVar3 = local_2c[0] >> 0x14 & 0xf;
    switch(uVar3) {
    case 0:
      *param_3 = 1;
      break;
    case 1:
      *param_3 = 2;
      uVar3 = uVar2;
      break;
    case 2:
      *param_3 = 3;
      uVar3 = uVar2;
      break;
    case 3:
      *param_3 = 4;
      uVar3 = uVar2;
      break;
    case 4:
      *param_3 = 5;
      uVar3 = uVar2;
      break;
    case 5:
      *param_3 = 6;
      uVar3 = uVar2;
      break;
    default:
      uVar3 = 999;
      if (4 < DAT_01216a78) {
        uVar1 = *(undefined4 *)(param_2 + 4);
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n",
                     "DEBUG",lVar4,"dmal/common/common_pci.c",0x1b4,uVar1);
      }
    }
  }
  else {
    uVar3 = uVar2;
    if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"dmal/common/common_pci.c",0x189,"cDeviceGetGpuMaxPcieGen",0x189,
                   uVar2);
      return uVar2;
    }
  }
  return uVar3;
}


// ===== 00229b80 FUN_00229b80 =====

uint FUN_00229b80(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  float fVar4;
  uint local_1c;
  
  uVar1 = FUN_00229510(param_1,param_2,&local_1c);
  if (uVar1 == 0) {
    uVar2 = local_1c >> 0xc & 0xf;
    switch(uVar2) {
    case 0:
      *param_3 = 1;
      break;
    case 1:
      *param_3 = 2;
      uVar2 = uVar1;
      break;
    case 2:
      *param_3 = 3;
      uVar2 = uVar1;
      break;
    case 3:
      *param_3 = 4;
      uVar2 = uVar1;
      break;
    case 4:
      *param_3 = 5;
      uVar2 = uVar1;
      break;
    case 5:
      *param_3 = 6;
      uVar2 = uVar1;
      break;
    default:
      uVar2 = 999;
    }
  }
  else {
    uVar2 = uVar1;
    if (1 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar3,"dmal/common/common_pci.c",0xfa,"cDeviceGetMaxPcieGen",0xfa,uVar1);
      return uVar1;
    }
  }
  return uVar2;
}


// ===== 00229cd0 FUN_00229cd0 =====

int FUN_00229cd0(long param_1,long param_2,uint param_3,undefined4 *param_4,int param_5)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  ulong uVar6;
  float fVar7;
  undefined8 uVar8;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined1 local_78 [16];
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined4 local_48;
  
  local_48 = 0;
  local_68 = (undefined1  [16])0x0;
  local_58 = (undefined1  [16])0x0;
  if ((param_3 < 8) && (lVar4 = (ulong)param_3 * 0x10, param_3 == *(uint *)(&DAT_00380120 + lVar4)))
  {
    uVar6 = (ulong)*(uint *)(&DAT_00380128 + lVar4);
    uVar1 = *(undefined4 *)(&DAT_00380124 + lVar4);
    if (param_5 != 0) {
      uVar6 = 0;
      uVar1 = *(undefined4 *)(&DAT_0038012c + lVar4);
    }
    iVar3 = FUN_002293f0(param_2,local_68);
    if (iVar3 == 0) {
      local_7c = *(undefined4 *)(local_68 + uVar6 * 4);
LAB_00229e55:
      if (param_5 != 0) {
        return 0;
      }
      *param_4 = local_7c;
      return 0;
    }
    lVar4 = *(long *)(param_2 + 0x256d8);
    local_7c = 0;
    local_78 = (undefined1  [16])0x0;
    local_80 = uVar1;
    if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
      iVar3 = 3;
    }
    else {
      iVar3 = (*pcVar2)(lVar4,param_2,0x2080,&local_84);
      if (iVar3 == 0) {
        local_78._8_8_ = &local_80;
        local_78._0_4_ = 1;
        iVar3 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_84,0x20801802,
                             local_78,0x10,0);
        switch(iVar3) {
        case 0:
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
        goto LAB_00229e55;
      }
    }
    if (DAT_01216a78 < 2) {
      return iVar3;
    }
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    fVar7 = fVar7 * DAT_00298548;
    uVar8 = 0x40b;
    uVar5 = 0x40b;
  }
  else {
    if (DAT_01216a78 < 2) {
      return 2;
    }
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    iVar3 = 2;
    fVar7 = fVar7 * DAT_00298548;
    uVar8 = 0x3fd;
    uVar5 = 0x3fd;
  }
  FUN_002340f0((double)fVar7,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
               "dmal/common/common_pci.c",uVar5,"cDevicePcieQuery",uVar8,iVar3);
  return iVar3;
}


// ===== 00229fe0 FUN_00229fe0 =====

int FUN_00229fe0(undefined8 param_1,char *param_2,int *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  int *piVar4;
  float fVar5;
  uint local_30;
  int local_2c;
  
  local_2c = 0;
  if (*param_2 == '\x01') {
    piVar4 = param_3;
    if (*(int *)(param_2 + 0x70530) == 2) {
      return 3;
    }
  }
  else {
    if (*(int *)(param_2 + 0x70530) == 2) {
      return 3;
    }
    piVar4 = (int *)(ulong)*(uint *)(param_2 + 0x14);
    if (*(long *)(param_2 + 0x20) == 0) {
      return 3;
    }
  }
  iVar2 = FUN_00236dd0(param_1,param_2,piVar4);
  if (iVar2 == 0) {
    return 4;
  }
  iVar2 = FUN_00229160(param_2,&local_2c,0xd);
  if ((iVar2 == 0) && (local_2c != 0)) {
    lVar3 = *(long *)(param_2 + 0x256d8);
    if ((lVar3 == 0) ||
       ((*(long *)(lVar3 + 0x48) == 0 ||
        (pcVar1 = *(code **)(*(long *)(lVar3 + 0x48) + 0x20), pcVar1 == (code *)0x0)))) {
      iVar2 = 3;
    }
    else {
      iVar2 = (*pcVar1)(lVar3,param_2,&local_30);
      if (iVar2 == 0) {
        if (local_30 < (uint)param_3[1]) {
          return 2;
        }
        if (*param_3 == 0x1000008) {
          iVar2 = FUN_00225750(param_1,param_2,param_3);
          return iVar2;
        }
        return 0x19;
      }
    }
    if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar3,"dmal/common/common_pci.c",0x692,"cDeviceSetPciGen",0x692,iVar2);
      return iVar2;
    }
    return iVar2;
  }
  return 3;
}


// ===== 0022a170 FUN_0022a170 =====

undefined8
FUN_0022a170(undefined8 param_1,long param_2,int param_3,uint param_4,uint param_5,uint *param_6,
            long param_7,ulong param_8)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong *puVar3;
  ulong uVar4;
  ulong uVar5;
  ulong *puVar6;
  uint uVar7;
  
  if (param_3 - 5U < 2) {
    uVar4 = (ulong)param_4 % (ulong)param_5;
  }
  else {
    uVar4 = (ulong)(param_4 + 1) % (ulong)param_5;
  }
  uVar7 = 0;
  do {
    puVar3 = (ulong *)(uVar4 * 0x10 + param_2);
    uVar1 = *puVar3;
    if ((param_8 < uVar1) && (100 < uVar1 - param_8)) {
      if (*param_6 <= uVar7) break;
      uVar5 = (ulong)uVar7;
      uVar7 = uVar7 + 1;
      puVar6 = (ulong *)(uVar5 * 0x10 + param_7);
      *puVar6 = uVar1;
      puVar6[1] = puVar3[1];
    }
    uVar4 = (ulong)((int)uVar4 + 1) % (ulong)param_5;
  } while (param_4 != (uint)uVar4);
  uVar2 = 6;
  if ((uVar7 != 0) && (uVar2 = 0, uVar7 < *param_6)) {
    *param_6 = uVar7;
  }
  return uVar2;
}


// ===== 0022a210 FUN_0022a210 =====

int FUN_0022a210(undefined8 param_1,long param_2,long param_3,int param_4,ulong param_5,
                uint *param_6,long param_7,ulong param_8)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  ulong uVar5;
  ulong *puVar6;
  ulong *puVar7;
  uint uVar8;
  byte bVar9;
  float fVar10;
  char local_39 [9];
  
  bVar9 = 0;
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(long *)(lVar4 + 0x20) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(lVar4 + 0x20) + 0xd0), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar4,param_2,local_39);
    if (iVar2 == 0) {
      uVar8 = 0;
      uVar5 = (ulong)(param_4 + 1) % (param_5 & 0xffffffff);
      do {
        puVar6 = (ulong *)(uVar5 * 0x1e8 + param_3);
        if (((int)puVar6[2] != -1) &&
           ((local_39[0] != '\0' || ((param_8 <= *puVar6 && (99 < *puVar6 - param_8)))))) {
          if (*param_6 <= uVar8) break;
          uVar3 = (ulong)uVar8;
          uVar8 = uVar8 + 1;
          puVar7 = (ulong *)(uVar3 * 0x1e8 + param_7);
          for (lVar4 = 0x3d; lVar4 != 0; lVar4 = lVar4 + -1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + (ulong)bVar9 * -2 + 1;
            puVar7 = puVar7 + (ulong)bVar9 * -2 + 1;
          }
        }
        uVar5 = (ulong)((int)uVar5 + 1) % (param_5 & 0xffffffff);
      } while (param_4 != (int)uVar5);
      if (uVar8 == 0) {
        return 6;
      }
      if (*param_6 <= uVar8) {
        return 0;
      }
      *param_6 = uVar8;
      return 0;
    }
  }
  if (1 < DAT_01216a78) {
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"dmal/common/common_util.c",0xbe,"cGetPerProcessSampleEntries",0xbe,
                 iVar2);
  }
  return iVar2;
}


// ===== 0022a390 FUN_0022a390 =====

undefined8 FUN_0022a390(undefined8 param_1,long param_2,ulong param_3,long *param_4)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  double dVar5;
  
  if (param_3 == 0) {
    *param_4 = 0;
    return 0;
  }
  lVar1 = *(long *)(param_2 + 0x25d30);
  uVar2 = *(ulong *)(param_2 + 0x25d38);
  uVar3 = *(long *)(param_2 + 0x25d40) - lVar1;
  if ((long)uVar3 < 0) {
    uVar4 = *(long *)(param_2 + 0x25d48) - uVar2;
  }
  else {
    uVar4 = *(long *)(param_2 + 0x25d48) - uVar2;
  }
  dVar5 = (double)uVar3 / (double)uVar4;
  if (uVar2 < param_3) {
    dVar5 = dVar5 * (double)(param_3 - uVar2);
    if (DAT_00298b48 <= dVar5) {
      uVar2 = (long)(dVar5 - DAT_00298b48) ^ 0x8000000000000000;
    }
    else {
      uVar2 = (ulong)dVar5;
    }
    *param_4 = uVar2 + lVar1;
    return 0;
  }
  dVar5 = dVar5 * (double)(uVar2 - param_3);
  if (DAT_00298b48 <= dVar5) {
    uVar2 = (long)(dVar5 - DAT_00298b48) ^ 0x8000000000000000;
  }
  else {
    uVar2 = (ulong)dVar5;
  }
  *param_4 = lVar1 - uVar2;
  return 0;
}


// ===== 0022a520 FUN_0022a520 =====

ulong FUN_0022a520(long param_1,char *param_2,ulong *param_3,ulong *param_4)

{
  undefined8 uVar1;
  code *pcVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  long *plVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  long *plVar13;
  float fVar14;
  undefined4 local_14c;
  long local_148 [4];
  long local_128;
  long local_118 [29];
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  if ((param_2 == (char *)0x0) || (*param_2 == '\x01')) {
    plVar9 = local_148;
    for (lVar7 = 0x21; lVar7 != 0; lVar7 = lVar7 + -1) {
      *plVar9 = 0;
      plVar9 = plVar9 + 1;
    }
    lVar7 = *(long *)(param_2 + 0x256d8);
    if (lVar7 != 0) goto LAB_0022a5b8;
switchD_0022a6c1_caseD_1:
    uVar12 = 999;
  }
  else {
    plVar9 = local_148;
    for (lVar7 = 0x21; lVar7 != 0; lVar7 = lVar7 + -1) {
      *plVar9 = 0;
      plVar9 = plVar9 + 1;
    }
    lVar7 = *(long *)(param_2 + 0x256d8);
    if (lVar7 == 0) goto switchD_0022a6c1_caseD_1;
LAB_0022a5b8:
    plVar9 = local_148;
    if ((*(undefined8 **)(lVar7 + 0x50) == (undefined8 *)0x0) ||
       (pcVar2 = (code *)**(undefined8 **)(lVar7 + 0x50), pcVar2 == (code *)0x0))
    goto switchD_0022a6c1_caseD_1;
    iVar4 = (*pcVar2)(lVar7,param_2,0x2080,&local_14c);
    if (iVar4 != 0) {
      if (iVar4 == 0xf) {
        uVar12 = 0xf;
        goto joined_r0x0022a5f1;
      }
      goto switchD_0022a6c1_caseD_1;
    }
    local_148[0]._0_2_ = 0x501;
    uVar5 = FUN_0019c780(uVar1,DAT_0038088c,local_14c,0x20800406,plVar9,0x108,0);
    uVar12 = (ulong)uVar5;
    switch(uVar5) {
    case 0:
      uVar6 = (ulong)uVar5;
      uVar5 = uVar5 + 1;
      uVar10 = local_128 - local_148[2];
      lVar7 = local_128;
      uVar8 = uVar12;
      uVar11 = local_128 - local_148[2];
      plVar13 = plVar9;
      if ((ulong)(local_128 - local_148[2]) <= uVar10) goto LAB_0022a727;
      do {
        uVar6 = uVar8;
        lVar7 = local_128;
        uVar11 = uVar10;
        plVar13 = plVar9;
LAB_0022a727:
        do {
          plVar9 = plVar13 + 2;
          if (uVar5 == 4) {
            uVar8 = (ulong)((int)uVar6 + 1);
            lVar7 = local_148[uVar8 * 2 + 1];
            lVar3 = local_148[uVar6 * 2 + 1];
            *param_4 = (ulong)(local_148[uVar8 * 2 + 2] + local_148[uVar6 * 2 + 2]) >> 1;
            *param_3 = (ulong)(lVar7 + lVar3) >> 1;
            return uVar12;
          }
          local_128 = plVar13[6];
          uVar8 = (ulong)uVar5;
          uVar5 = uVar5 + 1;
          uVar10 = local_128 - lVar7;
          lVar7 = local_128;
          plVar13 = plVar9;
        } while (uVar11 <= uVar10);
      } while( true );
    default:
      goto switchD_0022a6c1_caseD_1;
    case 3:
    case 0x66:
      uVar12 = 10;
      break;
    case 0xf:
      break;
    case 0x17:
    case 99:
      uVar12 = 0x13;
      break;
    case 0x1a:
      uVar12 = 0x17;
      break;
    case 0x1b:
      uVar12 = 4;
      break;
    case 0x1f:
    case 0x3b:
    case 0x54:
      uVar12 = 2;
      break;
    case 0x51:
      uVar12 = 0x14;
      break;
    case 0x55:
      uVar12 = 0x1b;
      break;
    case 0x56:
      uVar12 = 3;
      break;
    case 0x59:
      uVar12 = 0x11;
      break;
    case 0x62:
      uVar12 = 0x10;
    }
  }
joined_r0x0022a5f1:
  if (1 < DAT_01216a78) {
    fVar14 = (float)FUN_002917b0(&DAT_01216a60);
    lVar7 = syscall(0xba);
    FUN_002340f0((double)(fVar14 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar7,"dmal/common/common_util.c",0x7a,"cUpdateDeviceTimeStampDataPoint",
                 0x7a,uVar12);
  }
  return uVar12;
}


// ===== 0022a7c0 FUN_0022a7c0 =====

int FUN_0022a7c0(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  float fVar4;
  
  iVar1 = 0;
  puVar2 = (undefined *)FUN_00234e30();
  if (&DAT_004c4b40 + *(long *)(param_2 + 0x25d50) < puVar2) {
    iVar1 = FUN_0022a520(param_1,param_2,param_2 + 0x25d40,param_2 + 0x25d48);
    if (iVar1 == 0) {
      *(undefined **)(param_2 + 0x25d50) = puVar2;
      return 0;
    }
    if (1 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar3,"dmal/common/common_util.c",0x168,
                   "cCheckAndUpdateDeviceTimeStampDataPoint",0x168,iVar1);
    }
  }
  return iVar1;
}


// ===== 0022a8c0 FUN_0022a8c0 =====

int FUN_0022a8c0(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  float fVar4;
  undefined8 uVar5;
  undefined8 local_50;
  ulong local_48;
  undefined8 local_40;
  timespec local_38;
  
  if (*(long *)(param_2 + 0x25d30) != 0) {
    return 0;
  }
  if (*(long *)(param_2 + 0x25d38) != 0) {
    return 0;
  }
  iVar1 = FUN_0022a520(param_1,param_2,&local_50,&local_48);
  if (iVar1 == 0) {
    local_38.tv_sec = 0;
    local_38.tv_nsec = (long)&DAT_004c4b40;
    nanosleep(&local_38,(timespec *)0x0);
    iVar1 = FUN_0022a520(param_1,param_2,&local_40,&local_38);
    if (iVar1 == 0) {
      if (local_48 < (ulong)local_38.tv_sec) {
        *(undefined8 *)(param_2 + 0x25d30) = local_50;
        *(ulong *)(param_2 + 0x25d38) = local_48;
        *(undefined8 *)(param_2 + 0x25d40) = local_40;
        *(__time_t *)(param_2 + 0x25d48) = local_38.tv_sec;
        return 0;
      }
      *(undefined8 *)(param_2 + 0x25d30) = local_40;
      *(__time_t *)(param_2 + 0x25d38) = local_38.tv_sec;
      *(undefined8 *)(param_2 + 0x25d40) = local_50;
      *(ulong *)(param_2 + 0x25d48) = local_48;
      return 0;
    }
    if (DAT_01216a78 < 2) {
      return iVar1;
    }
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    fVar4 = fVar4 * DAT_00298548;
    uVar5 = 0x96;
    uVar3 = 0x96;
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar1;
    }
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    fVar4 = fVar4 * DAT_00298548;
    uVar5 = 0x91;
    uVar3 = 0x91;
  }
  FUN_002340f0((double)fVar4,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
               "dmal/common/common_util.c",uVar3,"cInitTimeStampDataPoints",uVar5,iVar1);
  return iVar1;
}


// ===== 0022aa90 FUN_0022aa90 =====

undefined8 FUN_0022aa90(undefined8 param_1,int param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  
  puVar1 = DAT_012148a8;
  if ((undefined8 **)DAT_012148a8 != &DAT_012148a8) {
    do {
      if (*(int *)(puVar1 + -99) == param_2) {
        *param_3 = puVar1 + -100;
        return 0;
      }
      puVar1 = (undefined8 *)*puVar1;
    } while ((undefined8 **)puVar1 != &DAT_012148a8);
  }
  return 2;
}


// ===== 0022aaf0 FUN_0022aaf0 =====

int FUN_0022aaf0(long param_1,long param_2,long param_3,int *param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  undefined4 local_7c;
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
  if (param_4 == (int *)0x0) {
switchD_0022ac7a_caseD_1f:
    return 2;
  }
  iVar2 = 0x19;
  if (*param_4 == 0x1000010) {
    lVar3 = *(long *)(param_2 + 0x256d8);
    if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
      iVar2 = 3;
    }
    else {
      iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_7c);
      if (iVar2 == 0) {
        iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_7c,0x20803601,
                             local_78,0x48,0);
        switch(iVar2) {
        case 0:
          if (local_78[4] != '\0') {
            *(undefined8 *)(param_4 + 2) = *(undefined8 *)(param_3 + 0x2f0);
            return iVar2;
          }
          *(undefined8 *)(param_4 + 2) = *(undefined8 *)(param_3 + 0x2f8);
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
          goto switchD_0022ac7a_caseD_1f;
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
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar3,"dmal/common/common_vgpu.c",0x89b,"cDeviceGetVgpuRuntimeState",
                   0x89b,iVar2);
      return iVar2;
    }
  }
  return iVar2;
}


// ===== 0022ad40 FUN_0022ad40 =====

uint FUN_0022ad40(long param_1,long param_2,int param_3,uint param_4)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  float fVar4;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_2c;
  
  uVar2 = 2;
  if (param_4 < 2) {
    if (param_3 == 7) {
      local_30 = 1;
    }
    else if (param_3 == 0xb) {
      local_30 = 0xb;
    }
    else {
      if (param_3 != 6) {
        return 2;
      }
      local_30 = 0;
    }
    lVar3 = *(long *)(param_2 + 0x256d8);
    if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
      uVar2 = 3;
    }
    else {
      uVar2 = (*pcVar1)(lVar3,param_2,0xa081,&local_34);
      if (uVar2 == 0) {
        local_2c = (undefined1)param_4;
        uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_34,0xa081011e,
                             &local_30,8,0);
        if (0x66 < uVar2) {
          return 999;
        }
        return (uint)*(ushort *)(&DAT_002da0e0 + (ulong)uVar2 * 2);
      }
    }
    if (1 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar3,"dmal/common/common_vgpu.c",0x398,"cDeviceSetVgpuCapabilities",
                   0x398,uVar2);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 0022aed0 FUN_0022aed0 =====

undefined8 FUN_0022aed0(void)

{
  code *pcVar1;
  void *__ptr;
  uint uVar2;
  ulong uVar3;
  
  __ptr = DAT_012148b8;
  if (DAT_012148b8 != (void *)0x0) {
    if (DAT_01214898 != 0) {
      uVar3 = 0;
      do {
        if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x28) != 0)) &&
           (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0x118), pcVar1 != (code *)0x0)) {
          (*pcVar1)(DAT_012164a0,&DAT_00380898 + uVar3 * 0x74a00);
        }
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulong)uVar2;
      } while (uVar2 < DAT_01214898);
    }
    free(__ptr);
    DAT_012148b8 = (void *)0x0;
  }
  return 0;
}


// ===== 0022af70 FUN_0022af70 =====

undefined8 FUN_0022af70(undefined8 param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  
  lVar1 = *(long *)(param_2 + 0x25d60);
  plVar2 = *(long **)(lVar1 + 0x618);
  while ((long *)(lVar1 + 0x618) != plVar2) {
    plVar3 = (long *)plVar2[1];
    *(long **)(*plVar2 + 8) = plVar3;
    *plVar3 = *plVar2;
    free(plVar2 + -0x43);
    plVar2 = *(long **)(lVar1 + 0x618);
  }
  return 0;
}


// ===== 0022afe0 FUN_0022afe0 =====

int FUN_0022afe0(undefined8 param_1,long param_2,undefined8 *param_3)

{
  int iVar1;
  long lVar2;
  float fVar3;
  int local_2c [3];
  
  iVar1 = FUN_00175bd0(param_2,local_2c);
  if (iVar1 == 0) {
    *param_3 = 0;
    if ((local_2c[0] != 0) && (*(long *)(param_2 + 0x25d60) != 0)) {
      *param_3 = 0x1f;
    }
  }
  else if (1 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar2,"dmal/common/common_vgpu.c",0x910,"cDeviceGetSupportedVgpuEventTypes"
                 ,0x910,iVar1);
    return iVar1;
  }
  return iVar1;
}


// ===== 0022b0d0 FUN_0022b0d0 =====

uint FUN_0022b0d0(undefined8 param_1,undefined8 *param_2)

{
  void *pvVar1;
  
  pvVar1 = calloc(0x608,1);
  *param_2 = pvVar1;
  return -(uint)(pvVar1 == (void *)0x0) & 999;
}


// ===== 0022b100 FUN_0022b100 =====

int FUN_0022b100(undefined8 param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  long *plVar3;
  int iVar4;
  undefined8 *__ptr;
  long lVar5;
  uint uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  byte bVar9;
  float fVar10;
  int local_67d4;
  long *local_67c0;
  undefined8 local_67b8 [3313];
  
  bVar9 = 0;
  memset(local_67b8,0,0x6780);
  local_67c0 = (long *)0x0;
  lVar5 = *(long *)(param_2 + 0x256d8);
  if (((lVar5 == 0) || (*(long *)(lVar5 + 0x28) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(lVar5 + 0x28) + 0x38), pcVar1 == (code *)0x0)) {
    local_67d4 = 3;
  }
  else {
    lVar2 = *(long *)(param_2 + 0x25d60);
    local_67d4 = (*pcVar1)(lVar5,param_2,lVar2 + 4,local_67b8);
    if (local_67d4 == 0) {
      if (*(int *)(lVar2 + 4) == 0) {
        return 0;
      }
      uVar6 = 0;
      while( true ) {
        __ptr = malloc(0x228);
        if (__ptr == (undefined8 *)0x0) {
          if (DAT_01216a78 < 2) {
            return 999;
          }
          fVar10 = (float)FUN_002917b0(&DAT_01216a60);
          lVar5 = syscall(0xba);
          FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       "ERROR",lVar5,"dmal/common/common_vgpu.c",0x33d);
          return 999;
        }
        puVar7 = local_67b8 + (ulong)uVar6 * 0x45;
        puVar8 = __ptr;
        for (lVar5 = 0x45; lVar5 != 0; lVar5 = lVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + (ulong)bVar9 * -2 + 1;
          puVar8 = puVar8 + (ulong)bVar9 * -2 + 1;
        }
        if ((DAT_012164a0 == 0) || (lVar5 = *(long *)(DAT_012164a0 + 0x28), lVar5 == 0)) break;
        if (*(code **)(lVar5 + 0xb8) == (code *)0x0) {
LAB_0022b20a:
          if (*(code **)(lVar5 + 0xc0) == (code *)0x0) break;
          local_67d4 = (**(code **)(lVar5 + 0xc0))
                                 (DAT_012164a0,*(undefined4 *)((long)__ptr + 4),&local_67c0);
          if (local_67d4 != 0) goto LAB_0022b2ce;
          *local_67c0 = param_2;
        }
        else {
          iVar4 = (**(code **)(lVar5 + 0xb8))
                            (DAT_012164a0,*(undefined4 *)((long)__ptr + 4),&local_67c0);
          if (iVar4 != 0) {
            if ((DAT_012164a0 == 0) || (lVar5 = *(long *)(DAT_012164a0 + 0x28), lVar5 == 0)) break;
            goto LAB_0022b20a;
          }
        }
        __ptr[0x3c] = param_2;
        uVar6 = uVar6 + 1;
        __ptr[0x3b] = local_67c0;
        plVar3 = *(long **)(lVar2 + 0x620);
        lVar5 = *plVar3;
        __ptr[0x44] = plVar3;
        __ptr[0x43] = lVar5;
        *(undefined8 **)(*plVar3 + 8) = __ptr + 0x43;
        *plVar3 = (long)(__ptr + 0x43);
        if (*(uint *)(lVar2 + 4) <= uVar6) {
          return 0;
        }
      }
      local_67d4 = 3;
LAB_0022b2ce:
      free(__ptr);
      return local_67d4;
    }
  }
  if (1 < DAT_01216a78) {
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar5,"dmal/common/common_vgpu.c",0x336,"cDeviceGetVgpuGuestInstancesInfo",
                 0x336,local_67d4);
  }
  return local_67d4;
}


// ===== 0022b410 FUN_0022b410 =====

undefined8 FUN_0022b410(undefined8 param_1,undefined8 param_2,long param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  
  if (*param_4 == 0x1000018) {
    iVar1 = *(int *)(param_3 + 0x228);
    param_4[2] = iVar1;
    param_4[1] = *(int *)(param_3 + 0x160);
    lVar4 = 0;
    if (iVar1 != 0) {
      do {
        *(undefined4 *)(*(long *)(param_4 + 4) + lVar4 * 4) =
             *(undefined4 *)(param_3 + 0x22c + lVar4 * 4);
        lVar4 = lVar4 + 1;
      } while ((uint)lVar4 < (uint)param_4[2]);
      return 0;
    }
  }
  else {
    if (*param_4 != 0x2000020) {
      return 0x19;
    }
    param_4[1] = *(int *)(param_3 + 0x160);
    if (param_4[6] == 0) {
      iVar1 = *(int *)(param_3 + 0x228);
      uVar2 = *(uint *)(param_3 + 0x118);
      uVar3 = param_4[2];
      param_4[2] = iVar1;
      if (uVar3 < uVar2) {
        return 7;
      }
      if (iVar1 != 0) {
        lVar4 = 0;
        do {
          *(undefined4 *)(*(long *)(param_4 + 4) + lVar4 * 4) =
               *(undefined4 *)(param_3 + 0x22c + lVar4 * 4);
          lVar4 = lVar4 + 1;
        } while ((uint)lVar4 < (uint)param_4[2]);
      }
    }
    else {
      if (param_4[6] != 1) {
        return 2;
      }
      iVar1 = *(int *)(param_3 + 0x164);
      uVar2 = *(uint *)(param_3 + 0x118);
      uVar3 = param_4[2];
      param_4[2] = iVar1;
      if (uVar3 < uVar2) {
        return 7;
      }
      if (iVar1 != 0) {
        lVar4 = 0;
        do {
          *(undefined4 *)(*(long *)(param_4 + 4) + lVar4 * 4) =
               *(undefined4 *)(param_3 + 0x168 + lVar4 * 4);
          lVar4 = lVar4 + 1;
        } while ((uint)lVar4 < (uint)param_4[2]);
      }
    }
  }
  return 0;
}


// ===== 0022b520 FUN_0022b520 =====

undefined8 FUN_0022b520(undefined8 param_1,int param_2,undefined8 *param_3)

{
  long *plVar1;
  void *pvVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  
  if (param_2 != 0) {
    pvVar2 = calloc(0x330,1);
    if (pvVar2 == (void *)0x0) {
      if (1 < DAT_01216a78) {
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                     lVar3,"dmal/common/common_vgpu.c",0x514);
      }
      *param_3 = 0;
      uVar4 = 999;
    }
    else {
      *(int *)((long)pvVar2 + 8) = param_2;
      plVar1 = DAT_012148b0;
      lVar3 = *DAT_012148b0;
      *(long **)((long)pvVar2 + 0x328) = DAT_012148b0;
      *(long *)((long)pvVar2 + 800) = lVar3;
      *(long *)(*plVar1 + 8) = (long)pvVar2 + 800;
      *plVar1 = (long)pvVar2 + 800;
      *param_3 = pvVar2;
      uVar4 = 0;
    }
    return uVar4;
  }
  return 2;
}


// ===== 0022b610 FUN_0022b610 =====

int FUN_0022b610(char *param_1,uint *param_2,uint param_3)

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


// ===== 0022b8a0 FUN_0022b8a0 =====

ulong FUN_0022b8a0(long param_1,uint *param_2,long *param_3,uint param_4)

{
  uint *puVar1;
  char *pcVar2;
  long *plVar3;
  code *pcVar4;
  undefined1 *puVar5;
  uint uVar6;
  ulong uVar7;
  int *piVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  uint uVar12;
  ulong uVar13;
  ulong uVar14;
  uint uVar15;
  char *pcVar16;
  int iVar17;
  nfds_t __nfds;
  ulong uVar18;
  nfds_t nVar19;
  undefined4 uVar20;
  float fVar21;
  ulong auStack_d0 [5];
  pollfd pStack_a8;
  uint local_9c;
  uint local_98;
  uint local_94;
  long local_90;
  float local_88;
  float local_84;
  undefined1 *local_80;
  long *local_78;
  ulong local_70;
  undefined1 *local_68;
  long local_60;
  uint local_4c;
  undefined1 local_48 [16];
  
  local_60 = *(long *)(param_1 + 0x10);
  local_4c = 0;
  local_48 = (undefined1  [16])0x0;
  uVar7 = (ulong)*param_2 * 8 + 0xf & 0xfffffffffffffff0;
  lVar10 = -uVar7;
  local_68 = (undefined1 *)((long)&pStack_a8 + uVar7 * -2);
  pcVar16 = (char *)((long)&pStack_a8 + uVar7 * -2);
  local_78 = param_3;
  if (DAT_01214898 == 0) {
    uVar6 = 0;
    __nfds = 0;
    local_68 = (undefined1 *)((long)&pStack_a8 + uVar7 * -2);
  }
  else {
    uVar12 = param_2[1];
    uVar15 = uVar12 + DAT_01214898;
    nVar19 = 0;
    do {
      uVar18 = (ulong)uVar12 % (ulong)DAT_01214898;
      pcVar2 = *(char **)(param_2 + uVar18 * 0xc + 2);
      __nfds = nVar19;
      if (((pcVar2 != (char *)0x0) &&
          ((*pcVar2 == '\x01' ||
           ((((*(int *)(pcVar2 + 0x14) != 0 && (*(int *)(pcVar2 + 0x1c) == 0)) &&
             (*(int *)(pcVar2 + 0x10) != 0)) && (*(long *)(pcVar2 + 0x20) != 0)))))) &&
         (*(long *)(pcVar2 + 0x25d60) != 0)) {
        uVar6 = param_2[uVar18 * 0xc + 4];
        __nfds = (nfds_t)((int)nVar19 + 1);
        puVar1 = (uint *)((long)&pStack_a8 + nVar19 * 8 + lVar10);
        *(uint **)((long)&pStack_a8 + nVar19 * 8 + uVar7 * -2) = param_2 + uVar18 * 0xc + 2;
        *puVar1 = uVar6;
        puVar1[1] = 3;
      }
      uVar6 = (uint)__nfds;
      uVar12 = uVar12 + 1;
      nVar19 = __nfds;
    } while (uVar15 != uVar12);
  }
  if (4 < DAT_01216a78) {
    *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22bb4c;
    uVar20 = FUN_002917b0(&DAT_01216a60);
    local_70 = CONCAT44(local_70._4_4_,uVar20);
    *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22bb5d;
    lVar9 = syscall(0xba);
    fVar21 = (float)local_70 * DAT_00298548;
    *(ulong *)((long)auStack_d0 + uVar7 * -2 + 0x18) = (ulong)param_4;
    *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x10) = 0x22bb9f;
    FUN_002340f0((double)fVar21,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %d\n","DEBUG",lVar9,
                 "dmal/common/common_vgpu.c",0x592,uVar6);
    pcVar16 = *(char **)((long)auStack_d0 + uVar7 * -2 + 0x18);
  }
  *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22b9af;
  uVar12 = poll((pollfd *)((long)&pStack_a8 + lVar10),__nfds,param_4);
  *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22b9b7;
  piVar8 = __errno_location();
  iVar17 = *piVar8;
  if (4 < DAT_01216a78) {
    local_80 = (undefined1 *)CONCAT44(local_80._4_4_,*piVar8);
    *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22bad0;
    fVar21 = (float)FUN_002917b0(&DAT_01216a60);
    local_70._0_4_ = fVar21;
    *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22bae1;
    lVar9 = syscall(0xba);
    uVar20 = local_80._0_4_;
    pcVar16 = (char *)(ulong)uVar6;
    fVar21 = (float)local_70 * DAT_00298548;
    *(ulong *)((long)auStack_d0 + uVar7 * -2 + 0x18) = (ulong)local_80 & 0xffffffff;
    *(ulong *)((long)auStack_d0 + uVar7 * -2 + 0x10) = (ulong)uVar12;
    *(ulong *)((long)auStack_d0 + uVar7 * -2 + 8) = (ulong)param_4;
    local_70 = CONCAT44(local_70._4_4_,uVar20);
    *(undefined8 *)((long)auStack_d0 + uVar7 * -2) = 0x22bb2f;
    FUN_002340f0((double)fVar21,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %d %d %d\n","DEBUG",lVar9,
                 "dmal/common/common_vgpu.c",0x595);
    iVar17 = (int)(float)local_70;
  }
  uVar18 = 10;
  if (uVar12 == 0xffffffff) {
    if (iVar17 != 4) {
switchD_0022baa0_caseD_1:
      uVar18 = 999;
    }
  }
  else if (uVar12 != 0) {
    param_2[1] = param_2[1] + 1;
    if (uVar6 != 0) {
      uVar14 = 0;
      local_70 = (ulong)uVar6;
LAB_0022b9f1:
      if (*(short *)((long)&pStack_a8 + uVar14 * 8 + lVar10 + 6) != 0) {
        local_84 = 0.0;
        plVar3 = *(long **)(local_68 + uVar14 * 8);
        local_90 = *plVar3;
        local_80 = local_48;
LAB_0022ba46:
        uVar6 = DAT_0038088c;
        if (4 < DAT_01216a78) {
          local_94 = *(uint *)(plVar3 + 1);
          *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22bbdd;
          local_88 = (float)FUN_002917b0(&DAT_01216a60);
          *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22bbee;
          lVar9 = syscall(0xba);
          fVar21 = local_88 * DAT_00298548;
          pcVar16 = (char *)(ulong)uVar6;
          *(ulong *)((long)auStack_d0 + uVar7 * -2 + 0x18) = (ulong)local_94;
          *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x10) = 0x22bc35;
          FUN_002340f0((double)fVar21,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %d\n","DEBUG",lVar9,
                       "dmal/common/common_vgpu.c",0x5b8);
        }
        puVar5 = local_80;
        lVar9 = plVar3[1];
        pcVar4 = *(code **)(local_60 + 0x48);
        *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22ba76;
        uVar6 = (*pcVar4)(DAT_0038088c,(int)lVar9,puVar5,&local_4c);
        uVar18 = (ulong)uVar6;
        if (4 < DAT_01216a78) {
          local_98 = *(uint *)(plVar3 + 1);
          local_94 = DAT_0038088c;
          *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22bc6f;
          local_88 = (float)FUN_002917b0(&DAT_01216a60);
          *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22bc80;
          lVar9 = syscall(0xba);
          uVar13 = (ulong)local_98;
          *(ulong *)((long)auStack_d0 + uVar7 * -2 + 0x20) = uVar18;
          pcVar16 = (char *)(ulong)local_94;
          fVar21 = local_88 * DAT_00298548;
          *(ulong *)((long)auStack_d0 + uVar7 * -2 + 0x18) = uVar13;
          *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x10) = 0x22bcc9;
          FUN_002340f0((double)fVar21,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %d %x\n","DEBUG",lVar9,
                       "dmal/common/common_vgpu.c",0x5ba);
          if (4 < DAT_01216a78) {
            local_9c = local_4c;
            local_98 = local_48._4_4_;
            local_94 = local_48._0_4_;
            *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22bd07;
            local_88 = (float)FUN_002917b0(&DAT_01216a60);
            *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22bd18;
            lVar9 = syscall(0xba);
            uVar13 = (ulong)local_98;
            fVar21 = local_88 * DAT_00298548;
            *(ulong *)((long)auStack_d0 + uVar7 * -2 + 0x20) = (ulong)local_9c;
            pcVar16 = (char *)(ulong)local_94;
            *(ulong *)((long)auStack_d0 + uVar7 * -2 + 0x18) = uVar13;
            *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x10) = 0x22bd66;
            FUN_002340f0((double)fVar21,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %d %d\n","DEBUG",
                         lVar9,"dmal/common/common_vgpu.c",0x5bc);
          }
        }
        switch(uVar6) {
        case 0:
          goto switchD_0022baa0_caseD_0;
        default:
          goto switchD_0022baa0_caseD_1;
        case 3:
        case 0x66:
          return 10;
        case 0xf:
          goto switchD_0022baa0_caseD_f;
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
          goto switchD_0022baa0_caseD_1f;
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
      goto LAB_0022b9fa;
    }
LAB_0022ba04:
    uVar18 = 0;
  }
switchD_0022baa0_caseD_f:
  return uVar18;
switchD_0022baa0_caseD_0:
  if (4 < (uint)local_48._4_4_) {
    uVar13 = 0;
    local_78[1] = 0;
    *local_78 = *plVar3;
    uVar18 = plVar3[2];
LAB_0022bdc3:
    if (1 < DAT_01216a78) {
      local_68 = (undefined1 *)uVar18;
      *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22bde3;
      uVar20 = FUN_002917b0(&DAT_01216a60);
      local_60 = CONCAT44(local_60._4_4_,uVar20);
      *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22bdf4;
      lVar10 = syscall(0xba);
      puVar5 = local_68;
      fVar21 = (float)local_60;
      *(char **)((long)auStack_d0 + uVar7 * -2 + 0x20) = pcVar16;
      *(undefined1 **)((long)auStack_d0 + uVar7 * -2 + 0x18) = puVar5;
      *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x10) = 0x22be3d;
      FUN_002340f0((double)(fVar21 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%llu %llu\n",
                   "ERROR",lVar10,"dmal/common/common_vgpu.c",0x5cc,uVar13);
      return 999;
    }
    goto switchD_0022baa0_caseD_1;
  }
  uVar13 = *(ulong *)(&DAT_002da2a0 + (ulong)(uint)local_48._4_4_ * 8);
  local_78[1] = uVar13;
  pcVar2 = (char *)*plVar3;
  *local_78 = (long)pcVar2;
  uVar18 = plVar3[2];
  if ((uVar18 & uVar13) == 0) goto LAB_0022bdc3;
  if ((0x10 < uVar13) || ((1L << ((byte)uVar13 & 0x3f) & 0x10116U) == 0)) {
    if (2 < DAT_01216a78) {
      *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22beee;
      uVar20 = FUN_002917b0(&DAT_01216a60);
      local_60 = CONCAT44(local_60._4_4_,uVar20);
      *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22beff;
      lVar10 = syscall(0xba);
      fVar21 = (float)local_60 * DAT_00298548;
      *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22bf3b;
      FUN_002340f0((double)fVar21,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","WARNING",lVar10,
                   "dmal/common/common_vgpu.c",0x5eb,uVar13 & 0xffffffff);
    }
    goto switchD_0022baa0_caseD_1;
  }
  if ((((pcVar2 != (char *)0x0) && (local_84 == 0.0)) &&
      ((*pcVar2 == '\x01' ||
       ((((*(int *)(pcVar2 + 0x14) != 0 && (*(int *)(pcVar2 + 0x1c) == 0)) &&
         (*(int *)(pcVar2 + 0x10) != 0)) && (*(long *)(pcVar2 + 0x20) != 0)))))) &&
     (lVar9 = *(long *)(pcVar2 + 0x25d60), lVar9 != 0)) {
    if (*(long *)(lVar9 + 0x618) == lVar9 + 0x618) {
LAB_0022c000:
      lVar9 = *(long *)(pcVar2 + 0x256d8);
      if ((lVar9 == 0) || (lVar11 = *(long *)(lVar9 + 0x28), lVar11 == 0)) goto LAB_0022c0b5;
LAB_0022c01d:
      pcVar4 = *(code **)(lVar11 + 0x48);
      if (pcVar4 == (code *)0x0) goto LAB_0022c0b5;
      *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22c02f;
      uVar6 = (*pcVar4)(lVar9,pcVar2);
      uVar18 = (ulong)uVar6;
      if (uVar6 == 0) goto LAB_0022bf4e;
    }
    else {
      lVar9 = *(long *)(pcVar2 + 0x256d8);
      if ((lVar9 != 0) && (lVar11 = *(long *)(lVar9 + 0x28), lVar11 != 0)) {
        pcVar4 = *(code **)(lVar11 + 0xf8);
        if (pcVar4 != (code *)0x0) {
          *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22c000;
          (*pcVar4)(lVar9,pcVar2);
          goto LAB_0022c000;
        }
        goto LAB_0022c01d;
      }
LAB_0022c0b5:
      uVar18 = 3;
    }
    if (1 < DAT_01216a78) {
      *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22c056;
      local_84 = (float)FUN_002917b0(&DAT_01216a60);
      *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x20) = 0x22c067;
      lVar9 = syscall(0xba);
      fVar21 = local_84;
      *(ulong *)((long)auStack_d0 + uVar7 * -2 + 0x20) = uVar18;
      *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x18) = 0x553;
      pcVar16 = "cHandleVgpuEvents";
      *(undefined8 *)((long)auStack_d0 + uVar7 * -2 + 0x10) = 0x22c0ae;
      FUN_002340f0((double)(fVar21 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar9,"dmal/common/common_vgpu.c",0x553);
    }
  }
LAB_0022bf4e:
  local_84 = 1.4013e-45;
  if (local_4c == 0) goto code_r0x0022bf60;
  goto LAB_0022ba46;
code_r0x0022bf60:
  if (*(long *)(local_90 + 0x25d60) == 0) {
switchD_0022baa0_caseD_1f:
    return 2;
  }
  *(undefined4 *)(*(long *)(local_90 + 0x25d60) + 0x62c) = 1;
LAB_0022b9fa:
  uVar14 = uVar14 + 1;
  if (local_70 == uVar14) goto LAB_0022ba04;
  goto LAB_0022b9f1;
}


// ===== 0022c0d0 FUN_0022c0d0 =====

undefined8 FUN_0022c0d0(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  float fVar4;
  undefined1 local_38 [16];
  undefined1 local_28 [16];
  
  uVar3 = 0;
  local_38 = (undefined1  [16])0x0;
  local_28 = (undefined1  [16])0x0;
  iVar1 = FUN_0022b8a0(param_1,DAT_012148b8,local_38,0);
  if (((iVar1 == 0) && (*(int *)(*(long *)(param_2 + 0x25d60) + 0x62c) == 1)) &&
     (uVar3 = 1, 3 < DAT_01216a78)) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar2,"dmal/common/common_vgpu.c",0x695);
  }
  return uVar3;
}


// ===== 0022c1a0 FUN_0022c1a0 =====

uint FUN_0022c1a0(long param_1,long param_2)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  float fVar4;
  undefined4 local_30;
  uint local_2c [3];
  
  local_30 = 0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  local_2c[0] = local_2c[0] & 0xffffff00;
  if (((lVar3 != 0) && (*(long *)(lVar3 + 0x38) != 0)) &&
     (pcVar1 = *(code **)(*(long *)(lVar3 + 0x38) + 0x80), pcVar1 != (code *)0x0)) {
    (*pcVar1)(lVar3,param_2,local_2c);
    if ((char)local_2c[0] != '\0') {
      lVar3 = *(long *)(param_2 + 0x256d8);
      if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
         (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
        uVar2 = 3;
      }
      else {
        uVar2 = (*pcVar1)(lVar3,param_2,0x2080,local_2c);
        if (uVar2 == 0) {
          uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_2c[0],0x208001ec,
                               &local_30,4,0);
          if (0x66 < uVar2) {
            return 999;
          }
          return (uint)*(ushort *)(&DAT_002da0e0 + (ulong)uVar2 * 2);
        }
      }
      if (DAT_01216a78 < 2) {
        return uVar2;
      }
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar3,"dmal/common/common_vgpu.c",0x3af,"cDeviceVgpuForceGspUnload",0x3af
                   ,uVar2);
      return uVar2;
    }
  }
  return 3;
}


// ===== 0022c350 FUN_0022c350 =====

int FUN_0022c350(long param_1,long param_2,int param_3,int *param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  float fVar5;
  undefined4 local_fc;
  uint local_f8;
  int local_f4;
  undefined4 local_f0;
  uint uStack_ec;
  undefined4 auStack_e8 [48];
  
  if ((param_4 == (int *)0x0) || (param_3 == 0)) {
switchD_0022c474_caseD_1f:
    return 2;
  }
  lVar3 = *(long *)(param_2 + 0x256d8);
  local_f8 = local_f8 & 0xffffff00;
  if (lVar3 != 0) {
    if ((*(long *)(lVar3 + 0x30) != 0) &&
       (pcVar1 = *(code **)(*(long *)(lVar3 + 0x30) + 0x148), pcVar1 != (code *)0x0)) {
      (*pcVar1)(lVar3,param_2,&local_f8);
      if ((char)local_f8 != '\0') {
        return 3;
      }
      lVar3 = *(long *)(param_2 + 0x256d8);
    }
    if (((lVar3 != 0) && (*(undefined8 **)(lVar3 + 0x50) != (undefined8 *)0x0)) &&
       (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 != (code *)0x0)) {
      iVar2 = (*pcVar1)(lVar3,param_2,0xa081,&local_fc);
      if (iVar2 == 0) {
        local_f8 = 0xffffffff;
        local_f4 = param_3;
        iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_fc,0xa081011c,
                             &local_f8,0xd0,0);
        switch(iVar2) {
        case 0:
          if (*param_4 == 0x1000018) {
            *(ulong *)(param_4 + 1) = CONCAT44(uStack_ec,local_f0);
            lVar3 = 0;
            if (uStack_ec == 0) {
              return iVar2;
            }
            do {
              *(undefined4 *)(*(long *)(param_4 + 4) + lVar3 * 4) = auStack_e8[lVar3];
              lVar3 = lVar3 + 1;
            } while ((uint)lVar3 < uStack_ec);
            return iVar2;
          }
          if (*param_4 == 0x2000020) {
            lVar3 = *(long *)(param_4 + 4);
            if ((lVar3 != 0) && (uStack_ec <= (uint)param_4[2])) {
              *(ulong *)(param_4 + 1) = CONCAT44(uStack_ec,local_f0);
              if (uStack_ec == 0) {
                return iVar2;
              }
              lVar4 = 0;
              while( true ) {
                *(undefined4 *)(lVar3 + lVar4 * 4) = auStack_e8[lVar4];
                lVar4 = lVar4 + 1;
                if (uStack_ec <= (uint)lVar4) break;
                lVar3 = *(long *)(param_4 + 4);
              }
              return iVar2;
            }
            param_4[2] = uStack_ec;
            return 7;
          }
          return 0x19;
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
          goto switchD_0022c474_caseD_1f;
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
      goto LAB_0022c486;
    }
  }
  iVar2 = 3;
LAB_0022c486:
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_vgpu.c",0x45e,
               "cDeviceGetVgpuTypeCreatablePlacements",0x45e,iVar2);
  return iVar2;
}


// ===== 0022c680 FUN_0022c680 =====

int FUN_0022c680(long param_1,long *param_2,int *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  float fVar5;
  undefined4 local_10c;
  uint local_108;
  int local_104;
  int local_100;
  uint local_fc;
  undefined4 auStack_f8 [50];
  
  local_108 = local_108 & 0xffffff00;
  lVar3 = *(long *)(*param_2 + 0x256d8);
  if (((lVar3 != 0) && (*(long *)(lVar3 + 0x38) != 0)) &&
     (pcVar1 = *(code **)(*(long *)(lVar3 + 0x38) + 0x80), pcVar1 != (code *)0x0)) {
    (*pcVar1)(lVar3,*param_2,&local_108);
    if ((char)local_108 != '\0') {
      local_108 = local_108 & 0xffffff00;
      lVar3 = *(long *)(*param_2 + 0x256d8);
      if (((lVar3 != 0) && (*(long *)(lVar3 + 0x30) != 0)) &&
         (pcVar1 = *(code **)(*(long *)(lVar3 + 0x30) + 0x148), pcVar1 != (code *)0x0)) {
        (*pcVar1)(lVar3,*param_2,&local_108);
        if ((char)local_108 != '\0') {
          if (*param_3 != 0x1000020) {
            return 0x19;
          }
          if ((int)param_2[1] != -1) {
            if (param_3[1] == 0) {
              return 2;
            }
            lVar3 = *(long *)(*param_2 + 0x256d8);
            if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
               (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
              iVar2 = 3;
            }
            else {
              iVar2 = (*pcVar1)(lVar3,*param_2,0xa081,&local_10c);
              if (iVar2 == 0) {
                local_108 = *(uint *)(param_2 + 1);
                local_104 = param_3[1];
                iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_10c,
                                     0xa081011c,&local_108,0xd0,0);
                switch(iVar2) {
                case 0:
                  lVar3 = *(long *)(param_3 + 4);
                  if ((lVar3 != 0) && (local_fc <= (uint)param_3[2])) {
                    param_3[2] = local_fc;
                    param_3[6] = local_100;
                    lVar4 = 0;
                    if (local_fc == 0) {
                      return iVar2;
                    }
                    while( true ) {
                      *(undefined4 *)(lVar3 + lVar4 * 4) = auStack_f8[lVar4];
                      lVar4 = lVar4 + 1;
                      if (local_fc <= (uint)lVar4) break;
                      lVar3 = *(long *)(param_3 + 4);
                    }
                    return iVar2;
                  }
                  param_3[2] = local_fc;
                  return 7;
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
                  goto switchD_0022c81d_caseD_56;
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
            FUN_002340f0((double)(fVar5 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
                         "dmal/common/common_vgpu.c",0x1e8,
                         "cGpuInstanceGetVgpuTypeCreatablePlacements",0x1e8,iVar2);
            return iVar2;
          }
          return 2;
        }
      }
    }
  }
switchD_0022c81d_caseD_56:
  return 3;
}


// ===== 0022c9a0 FUN_0022c9a0 =====

int FUN_0022c9a0(long param_1,long *param_2,int *param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  uint local_7c;
  undefined1 local_78 [16];
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined8 local_48;
  
  local_48 = 0;
  local_78 = (undefined1  [16])0x0;
  local_68 = (undefined1  [16])0x0;
  local_58 = (undefined1  [16])0x0;
  local_7c = local_7c & 0xffffff00;
  lVar4 = *(long *)(*param_2 + 0x256d8);
  if (((lVar4 != 0) && (*(long *)(lVar4 + 0x38) != 0)) &&
     (pcVar2 = *(code **)(*(long *)(lVar4 + 0x38) + 0x80), pcVar2 != (code *)0x0)) {
    (*pcVar2)(lVar4,*param_2,&local_7c);
    if ((char)local_7c != '\0') {
      local_7c = local_7c & 0xffffff00;
      lVar4 = *(long *)(*param_2 + 0x256d8);
      if (((lVar4 != 0) && (*(long *)(lVar4 + 0x30) != 0)) &&
         (pcVar2 = *(code **)(*(long *)(lVar4 + 0x30) + 0x148), pcVar2 != (code *)0x0)) {
        (*pcVar2)(lVar4,*param_2,&local_7c);
        if ((char)local_7c != '\0') {
          if (*param_3 != 0x1000010) {
            return 0x19;
          }
          if (((param_3[1] == 0) || (*(long *)(param_3 + 2) != 0)) && ((int)param_2[1] != -1)) {
            lVar4 = *(long *)(*param_2 + 0x256d8);
            if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
               (pcVar2 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar2 == (code *)0x0)) {
              iVar3 = 3;
            }
            else {
              iVar3 = (*pcVar2)(lVar4,*param_2,0xa081,&local_7c);
              if (iVar3 == 0) {
                local_78._0_4_ = (int)param_2[1];
                iVar3 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_7c,
                                     0xa0810124,local_78,0x38,0);
                switch(iVar3) {
                case 0:
                  if (local_78._4_4_ == 0) {
                    param_3[1] = 0;
                    return 0;
                  }
                  uVar1 = param_3[1];
                  param_3[1] = local_78._4_4_;
                  if ((uint)local_78._4_4_ <= uVar1) {
                    lVar4 = 0;
                    do {
                      *(undefined4 *)(*(long *)(param_3 + 2) + lVar4) =
                           *(undefined4 *)(local_78 + lVar4 + 8);
                      lVar4 = lVar4 + 4;
                    } while ((ulong)(uint)local_78._4_4_ * 4 - lVar4 != 0);
                    return iVar3;
                  }
                  return 7;
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
                  goto switchD_0022cb29_caseD_1f;
                case 0x51:
                  return 0x14;
                case 0x55:
                  return 0x1b;
                case 0x56:
                  goto switchD_0022cb29_caseD_56;
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
            FUN_002340f0((double)(fVar5 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
                         "dmal/common/common_vgpu.c",0x1ae,"cGpuInstanceGetVgpuInstancesInfo",0x1ae,
                         iVar3);
            return iVar3;
          }
switchD_0022cb29_caseD_1f:
          return 2;
        }
      }
    }
  }
switchD_0022cb29_caseD_56:
  return 3;
}


// ===== 0022ccc0 FUN_0022ccc0 =====

int FUN_0022ccc0(long param_1,long param_2,undefined4 param_3,undefined4 *param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  uint local_48;
  int local_44;
  undefined8 local_40;
  
  local_40 = 0;
  local_44 = 0;
  if (param_4 == (undefined4 *)0x0) {
switchD_0022cdc6_default:
    return 2;
  }
  iVar2 = FUN_0022b610(param_2,&local_44,6);
  if (iVar2 == 0) {
    if (local_44 != 0) {
      lVar3 = *(long *)(param_2 + 0x256d8);
      local_48 = local_48 & 0xffffff00;
      if (((lVar3 != 0) && (*(long *)(lVar3 + 0x38) != 0)) &&
         (pcVar1 = *(code **)(*(long *)(lVar3 + 0x38) + 0x80), pcVar1 != (code *)0x0)) {
        (*pcVar1)(lVar3,param_2,&local_48);
        if ((char)local_48 != '\0') {
          lVar3 = *(long *)(param_2 + 0x256d8);
          if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
             (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
            iVar2 = 3;
          }
          else {
            iVar2 = (*pcVar1)(lVar3,param_2,0xa081,&local_48);
            if (iVar2 == 0) {
              switch(param_3) {
              case 0:
                local_40._0_4_ = 8;
                break;
              case 1:
                local_40._0_4_ = 7;
                break;
              case 2:
                local_40._0_4_ = 6;
                break;
              case 3:
              case 4:
                local_40._0_4_ = 5;
                break;
              case 5:
                local_40._0_4_ = 3;
                break;
              case 6:
                local_40._0_4_ = 0;
                break;
              case 7:
                local_40._0_4_ = 1;
                break;
              case 8:
                local_40._0_4_ = 2;
                break;
              case 9:
                local_40._0_4_ = 9;
                break;
              case 10:
                local_40._0_4_ = 10;
                break;
              case 0xb:
                local_40._0_4_ = 0xb;
                break;
              default:
                goto switchD_0022cdc6_default;
              }
              iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_48,0xa081011f,
                                   &local_40,8,0);
              switch(iVar2) {
              case 0:
                *param_4 = local_40._4_4_;
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
                goto switchD_0022cdc6_default;
              case 0x51:
                return 0x14;
              case 0x55:
                return 0x1b;
              case 0x56:
                goto switchD_0022cf3a_caseD_56;
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
          uVar6 = 0x3ce;
          uVar4 = 0x3ce;
          goto LAB_0022ce41;
        }
      }
    }
switchD_0022cf3a_caseD_56:
    iVar2 = 3;
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    fVar5 = fVar5 * DAT_00298548;
    uVar6 = 0x3c6;
    uVar4 = 0x3c6;
LAB_0022ce41:
    FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
                 "dmal/common/common_vgpu.c",uVar4,"cDeviceGetVgpuCapabilities",uVar6,iVar2);
  }
  return iVar2;
}


// ===== 0022d020 FUN_0022d020 =====

uint FUN_0022d020(long param_1,long *param_2,int *param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  float fVar4;
  uint local_44;
  undefined8 local_40;
  
  local_40 = 0;
  if (((param_2 == (long *)0x0) || (param_3 == (int *)0x0)) || ((int)param_2[1] == -1)) {
    return 2;
  }
  local_44 = local_44 & 0xffffff00;
  lVar3 = *(long *)(*param_2 + 0x256d8);
  if (((lVar3 != 0) && (*(long *)(lVar3 + 0x38) != 0)) &&
     (pcVar1 = *(code **)(*(long *)(lVar3 + 0x38) + 0x80), pcVar1 != (code *)0x0)) {
    (*pcVar1)(lVar3,*param_2,&local_44);
    if ((char)local_44 != '\0') {
      local_44 = local_44 & 0xffffff00;
      lVar3 = *(long *)(*param_2 + 0x256d8);
      if (((lVar3 != 0) && (*(long *)(lVar3 + 0x30) != 0)) &&
         (pcVar1 = *(code **)(*(long *)(lVar3 + 0x30) + 0x148), pcVar1 != (code *)0x0)) {
        (*pcVar1)(lVar3,*param_2,&local_44);
        if ((char)local_44 != '\0') {
          if (*param_3 != 0x1000008) {
            return 0x19;
          }
          if (1 < (uint)param_3[1]) {
            return 2;
          }
          lVar3 = *(long *)(*param_2 + 0x256d8);
          if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
             (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
            uVar2 = 3;
          }
          else {
            uVar2 = (*pcVar1)(lVar3,*param_2,0x80,&local_44);
            if (uVar2 == 0) {
              local_40 = CONCAT71(local_40._1_7_,(char)param_3[1]);
              local_40 = CONCAT44((int)param_2[1],(undefined4)local_40);
              uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_44,
                                   &DAT_00800297,&local_40,8,0);
              if (uVar2 == 0x5b) {
                return 3;
              }
              if (uVar2 < 0x67) {
                return (uint)*(ushort *)(&DAT_002da0e0 + (ulong)uVar2 * 2);
              }
              return 999;
            }
          }
          if (1 < DAT_01216a78) {
            fVar4 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            FUN_002340f0((double)(fVar4 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
                         "dmal/common/common_vgpu.c",0x224,"cGpuInstanceSetVgpuHeterogeneousMode",
                         0x224,uVar2);
            return uVar2;
          }
          return uVar2;
        }
      }
    }
  }
  return 3;
}


// ===== 0022d280 FUN_0022d280 =====

undefined4 FUN_0022d280(undefined8 param_1,long param_2,undefined1 *param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  void *__ptr;
  uint uVar4;
  uint local_50;
  int local_4c;
  undefined4 local_48;
  uint local_44;
  undefined4 local_40;
  uint local_3c;
  
  *param_3 = 0;
  lVar1 = *(long *)(param_2 + 0x256d8);
  local_50 = 0;
  local_48 = 0;
  local_44 = local_44 & 0xffffff00;
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x38) != 0)) &&
     (pcVar2 = *(code **)(*(long *)(lVar1 + 0x38) + 0x80), pcVar2 != (code *)0x0)) {
    (*pcVar2)(lVar1,param_2,&local_44);
    if ((char)local_44 != '\0') {
      lVar1 = *(long *)(param_2 + 0x256d8);
      local_44 = local_44 & 0xffffff00;
      if (((lVar1 != 0) && (*(long *)(lVar1 + 0x30) != 0)) &&
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x30) + 0x148), pcVar2 != (code *)0x0)) {
        (*pcVar2)(lVar1,param_2,&local_44);
        if ((((char)local_44 != '\0') && (iVar3 = FUN_0015ba80(param_2,0xb,&local_4c), iVar3 == 0))
           && (local_4c == 1)) {
          iVar3 = FUN_0018a480(param_2,&local_50,0);
          if ((iVar3 == 7) && (local_50 != 0)) {
            __ptr = malloc((ulong)local_50 * 4);
            if (__ptr == (void *)0x0) {
              return 999;
            }
            iVar3 = FUN_0018a480(param_2,&local_50,__ptr);
            if (iVar3 != 0) {
              free(__ptr);
              return 999;
            }
            uVar4 = 0;
            if (local_50 != 0) {
              do {
                iVar3 = FUN_0015f7a0(*(undefined4 *)((long)__ptr + (ulong)uVar4 * 4),&local_48);
                if (iVar3 != 0) {
LAB_0022d3f8:
                  free(__ptr);
                  return 999;
                }
                local_3c = 0;
                local_44 = 0x100000c;
                local_40 = local_48;
                iVar3 = FUN_00164990(&local_44);
                if (iVar3 != 0) goto LAB_0022d3f8;
                if (local_3c < 2) {
                  *param_3 = 0;
                  free(__ptr);
                  return 0;
                }
                *param_3 = 1;
                uVar4 = uVar4 + 1;
              } while (uVar4 < local_50);
            }
            free(__ptr);
            return 0;
          }
        }
      }
    }
  }
  return 0;
}


// ===== 0022d450 FUN_0022d450 =====

int FUN_0022d450(long param_1,long *param_2,int *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  char local_35;
  undefined4 local_34;
  undefined8 local_30;
  
  local_30 = 0;
  local_34 = 0;
  if (((param_2 == (long *)0x0) || (param_3 == (int *)0x0)) || ((int)param_2[1] == -1)) {
switchD_0022d5da_caseD_1f:
    return 2;
  }
  local_35 = '\0';
  lVar3 = *(long *)(*param_2 + 0x256d8);
  if (((lVar3 != 0) && (*(long *)(lVar3 + 0x38) != 0)) &&
     (pcVar1 = *(code **)(*(long *)(lVar3 + 0x38) + 0x80), pcVar1 != (code *)0x0)) {
    (*pcVar1)(lVar3,*param_2,&local_35);
    if (local_35 != '\0') {
      local_35 = '\0';
      lVar3 = *(long *)(*param_2 + 0x256d8);
      if (((lVar3 != 0) && (*(long *)(lVar3 + 0x30) != 0)) &&
         ((pcVar1 = *(code **)(*(long *)(lVar3 + 0x30) + 0x148), pcVar1 != (code *)0x0 &&
          ((*pcVar1)(lVar3,*param_2,&local_35), local_35 != '\0')))) {
        if (*param_3 != 0x1000008) {
          return 0x19;
        }
        lVar3 = *(long *)(*param_2 + 0x256d8);
        if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
           (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
          iVar2 = 3;
        }
        else {
          iVar2 = (*pcVar1)(lVar3,*param_2,0x80,&local_34);
          if (iVar2 == 0) {
            local_30 = CONCAT44((int)param_2[1],(undefined4)local_30);
            iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_34,&DAT_00800298
                                 ,&local_30,8,0);
            if (iVar2 == 0x5b) {
              return 3;
            }
            switch(iVar2) {
            case 0:
              param_3[1] = (uint)(byte)local_30;
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
              goto switchD_0022d5da_caseD_1f;
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
          fVar4 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar4 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
                       "dmal/common/common_vgpu.c",0x252,"cGpuInstanceGetVgpuHeterogeneousMode",
                       0x252,iVar2);
          return iVar2;
        }
        return iVar2;
      }
    }
  }
  return 3;
}


// ===== 0022d710 FUN_0022d710 =====

uint FUN_0022d710(long param_1,long param_2,long param_3,undefined4 param_4)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  float fVar4;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    uVar2 = 3;
  }
  else {
    uVar2 = (*pcVar1)(lVar3,param_2,0xa081,&local_4c);
    if (uVar2 == 0) {
      local_48 = *(undefined8 *)(param_3 + 0xb0);
      uStack_40 = *(undefined8 *)(param_3 + 0xb8);
      local_38 = param_4;
      uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_4c,0xa0810110,
                           &local_48,0x14,0);
      if (0x66 < uVar2) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002da0e0 + (ulong)uVar2 * 2);
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar2;
  }
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/common/common_vgpu.c",0x315,
               "cDeviceSetVgpuInstanceEncoderCapacity",0x315,uVar2);
  return uVar2;
}


// ===== 0022d880 FUN_0022d880 =====

uint FUN_0022d880(long param_1,long param_2,uint *param_3)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  byte local_2d;
  undefined4 local_2c [3];
  
  local_2d = 0;
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)) {
    uVar2 = 3;
  }
  else {
    uVar2 = (*pcVar1)(lVar4,param_2,0xa081,local_2c);
    if (uVar2 == 0) {
      iVar3 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_2c[0],0xa0810112,
                           &local_2d,1,0);
      if (iVar3 == 0) {
        *param_3 = (uint)local_2d;
        return 0;
      }
      *param_3 = 0;
      if (99 < iVar3 - 3U) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002da1c0 + (ulong)(iVar3 - 3U) * 2);
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar4,"dmal/common/common_vgpu.c",0x368,"cVgpuGetMigrationCap",0x368,uVar2);
  return uVar2;
}


// ===== 0022da10 FUN_0022da10 =====

int FUN_0022da10(long param_1,long param_2,undefined8 *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  undefined4 local_34;
  undefined8 local_30 [2];
  
  local_30[0] = 0;
  *param_3 = 0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,0xa081,&local_34);
    if (iVar2 == 0) {
      iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_34,0xa0810118,local_30
                           ,8,0);
      switch(iVar2) {
      case 0:
        *param_3 = local_30[0];
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
               "ERROR",lVar3,"dmal/common/common_vgpu.c",0xff,"cDeviceGetVgpuDriverCaps",0xff,iVar2)
  ;
  return iVar2;
}


// ===== 0022dbf0 FUN_0022dbf0 =====

int FUN_0022dbf0(long param_1,long param_2,undefined8 *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  undefined4 local_12c;
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
  undefined1 local_88 [16];
  undefined1 local_78 [16];
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  undefined1 local_38 [16];
  
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
  local_88 = (undefined1  [16])0x0;
  local_78 = (undefined1  [16])0x0;
  local_68 = (undefined1  [16])0x0;
  local_58 = (undefined1  [16])0x0;
  local_48 = (undefined1  [16])0x0;
  local_38 = (undefined1  [16])0x0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,0xa081,&local_12c);
    if (iVar2 == 0) {
      iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_12c,0xa0810114,
                           local_128,0x100,0);
      switch(iVar2) {
      case 0:
        *param_3 = local_128._0_8_;
        param_3[1] = local_128._8_8_;
        param_3[2] = local_118._0_8_;
        param_3[3] = local_118._8_8_;
        param_3[4] = local_108._0_8_;
        param_3[5] = local_108._8_8_;
        param_3[6] = local_f8._0_8_;
        param_3[7] = local_f8._8_8_;
        param_3[8] = local_e8._0_8_;
        param_3[9] = local_e8._8_8_;
        param_3[10] = local_d8._0_8_;
        param_3[0xb] = local_d8._8_8_;
        param_3[0xc] = local_c8._0_8_;
        param_3[0xd] = local_c8._8_8_;
        param_3[0xe] = local_b8._0_8_;
        param_3[0xf] = local_b8._8_8_;
        param_3[0x10] = local_a8._0_8_;
        param_3[0x11] = local_a8._8_8_;
        param_3[0x12] = local_98._0_8_;
        param_3[0x13] = local_98._8_8_;
        param_3[0x14] = local_88._0_8_;
        param_3[0x15] = local_88._8_8_;
        param_3[0x16] = local_78._0_8_;
        param_3[0x17] = local_78._8_8_;
        param_3[0x18] = local_68._0_8_;
        param_3[0x19] = local_68._8_8_;
        param_3[0x1a] = local_58._0_8_;
        param_3[0x1b] = local_58._8_8_;
        param_3[0x1c] = local_48._0_8_;
        param_3[0x1d] = local_48._8_8_;
        param_3[0x1e] = local_38._0_8_;
        param_3[0x1f] = local_38._8_8_;
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
               "ERROR",lVar3,"dmal/common/common_vgpu.c",0x497,"cVgpuDeviceGetPgpuMetadataString",
               0x497,iVar2);
  return iVar2;
}


// ===== 0022def0 FUN_0022def0 =====

int FUN_0022def0(long param_1,long param_2,uint *param_3,void *param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  float fVar5;
  undefined4 local_24c;
  undefined8 local_248;
  uint local_240;
  undefined1 local_23c [524];
  
  puVar4 = &local_248;
  for (lVar3 = 0x41; lVar3 != 0; lVar3 = lVar3 + -1) {
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
    iVar2 = (*pcVar1)(lVar3,param_2,0xa081,&local_24c);
    if (iVar2 == 0) {
      iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_24c,0xa0810104,
                           &local_248,0x20c,0);
      switch(iVar2) {
      case 0:
        goto switchD_0022dfba_caseD_0;
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
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar3,"dmal/common/common_vgpu.c",0x117,"cDeviceGetSupportedVgpus",0x117,
                 iVar2);
  }
  return iVar2;
switchD_0022dfba_caseD_0:
  *param_3 = local_240;
  if (local_240 == 0) {
    return iVar2;
  }
  memcpy(param_4,local_23c,(ulong)local_240 * 4);
  return iVar2;
}


// ===== 0022e110 FUN_0022e110 =====

uint FUN_0022e110(long param_1,long param_2,long param_3)

{
  code *pcVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  uint uVar4;
  long lVar5;
  undefined8 uVar6;
  char *pcVar7;
  float fVar8;
  undefined8 uVar9;
  int local_90;
  undefined4 local_8c;
  undefined1 local_88 [16];
  undefined8 local_78;
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined8 local_48;
  uint local_40;
  
  local_78 = 0;
  local_90 = 0;
  local_88 = (undefined1  [16])0x0;
  if (param_2 == 0) {
    return 2;
  }
  if (param_3 == 0) {
    return 2;
  }
  uVar4 = FUN_0022b610(param_2,&local_90,7);
  if (uVar4 != 0) {
    if (DAT_01216a78 < 2) {
      return uVar4;
    }
    fVar8 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    pcVar7 = "cDeviceSetVgpuObjschedState_v2";
    fVar8 = fVar8 * DAT_00298548;
    uVar9 = 0x79a;
    uVar6 = 0x79a;
    goto LAB_0022e277;
  }
  if (local_90 == 0) goto switchD_0022e391_caseD_56;
  lVar5 = *(long *)(param_2 + 0x256d8);
  auVar2[0xf] = 0;
  auVar2._0_15_ = local_68._1_15_;
  local_68 = auVar2 << 8;
  if (((lVar5 == 0) || (*(long *)(lVar5 + 0x38) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(lVar5 + 0x38) + 0x80), pcVar1 == (code *)0x0))
  goto switchD_0022e391_caseD_56;
  (*pcVar1)(lVar5,param_2,local_68);
  if (local_68[0] == '\0') goto switchD_0022e391_caseD_56;
  lVar5 = *(long *)(param_2 + 0x256d8);
  auVar3[0xf] = 0;
  auVar3._0_15_ = local_68._1_15_;
  local_68 = auVar3 << 8;
  if (((lVar5 != 0) && (*(long *)(lVar5 + 0x30) != 0)) &&
     (pcVar1 = *(code **)(*(long *)(lVar5 + 0x30) + 0x148), pcVar1 != (code *)0x0)) {
    (*pcVar1)(lVar5,param_2,local_68);
    if (local_68[0] != '\0') goto switchD_0022e391_caseD_56;
    lVar5 = *(long *)(param_2 + 0x256d8);
  }
  local_48 = 0;
  local_40 = 0;
  local_68 = (undefined1  [16])0x0;
  local_58 = (undefined1  [16])0x0;
  if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar5 + 0x50), pcVar1 == (code *)0x0)) {
    uVar4 = 3;
LAB_0022e39e:
    if (DAT_01216a78 < 2) {
      return uVar4;
    }
    fVar8 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    pcVar7 = "cValidateClientSetSchedState_v2";
    fVar8 = fVar8 * DAT_00298548;
    uVar9 = 0x76a;
    uVar6 = 0x76a;
LAB_0022e277:
    FUN_002340f0((double)fVar8,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,
                 "dmal/common/common_vgpu.c",uVar6,pcVar7,uVar9,uVar4);
    return uVar4;
  }
  uVar4 = (*pcVar1)(lVar5,param_2,0x2080);
  if (uVar4 != 0) goto LAB_0022e39e;
  if ((*(int *)(param_3 + 4) == 1) &&
     ((*(int *)(param_3 + 0xc) != 0 || (*(int *)(param_3 + 8) != 0)))) {
switchD_0022e391_caseD_1f:
    return 2;
  }
  local_68._0_4_ = 1;
  uVar4 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_8c,0x20801122,local_68,
                       0x2c,0);
  switch(uVar4) {
  case 0:
    uVar4 = *(uint *)(param_3 + 0xc);
    if (uVar4 != 0) {
      if (uVar4 < (uint)local_48) {
        return 2;
      }
      if ((uint)local_58._12_4_ < uVar4) {
        return 2;
      }
    }
    uVar4 = *(uint *)(param_3 + 8);
    if (uVar4 != 0) {
      if (uVar4 < local_40) {
        return 2;
      }
      if (local_48._4_4_ < uVar4) {
        return 2;
      }
    }
    uVar4 = FUN_00133c40(*(undefined4 *)(param_3 + 4),local_68);
    if (uVar4 != 0) {
      return uVar4;
    }
    lVar5 = *(long *)(param_2 + 0x256d8);
    if (((lVar5 != 0) && (*(undefined8 **)(lVar5 + 0x50) != (undefined8 *)0x0)) &&
       (pcVar1 = (code *)**(undefined8 **)(lVar5 + 0x50), pcVar1 != (code *)0x0)) {
      uVar4 = (*pcVar1)(lVar5,param_2,0x2080,&local_8c);
      if (uVar4 != 0) {
        return uVar4;
      }
      local_88._4_4_ = local_68._0_4_;
      local_88._0_4_ = 1;
      local_78 = CONCAT44(*(undefined4 *)(param_3 + 8),*(undefined4 *)(param_3 + 0xc));
      uVar4 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_8c,0x20801121,local_88
                           ,0x18,0);
      if (uVar4 < 0x67) {
        return (uint)*(ushort *)(&DAT_002da0e0 + (ulong)uVar4 * 2);
      }
      return 999;
    }
  case 0x56:
switchD_0022e391_caseD_56:
    uVar4 = 3;
    break;
  default:
    uVar4 = 999;
    break;
  case 3:
  case 0x66:
    uVar4 = 10;
    break;
  case 0xf:
    break;
  case 0x17:
  case 99:
    uVar4 = 0x13;
    break;
  case 0x1a:
    uVar4 = 0x17;
    break;
  case 0x1b:
    uVar4 = 4;
    break;
  case 0x1f:
  case 0x3b:
  case 0x54:
    goto switchD_0022e391_caseD_1f;
  case 0x51:
    uVar4 = 0x14;
    break;
  case 0x55:
    uVar4 = 0x1b;
    break;
  case 0x59:
    uVar4 = 0x11;
    break;
  case 0x62:
    uVar4 = 0x10;
  }
  return uVar4;
}


// ===== 0022e560 FUN_0022e560 =====

ulong FUN_0022e560(long param_1,long param_2,int param_3,long *param_4)

{
  long lVar1;
  code *pcVar2;
  undefined8 *puVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  long *plVar7;
  ulong uVar8;
  float fVar9;
  undefined4 local_4cc;
  uint local_4c8 [2];
  long local_4c0 [2];
  long alStack_4b0 [144];
  
  lVar5 = *(long *)(param_2 + 0x25d60);
  *param_4 = 0;
  lVar1 = *(long *)(param_2 + 0x256d8);
  if (((lVar1 == 0) || (*(undefined8 **)(lVar1 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar1 + 0x50), pcVar2 == (code *)0x0)) {
    uVar8 = 3;
  }
  else {
    uVar4 = (*pcVar2)(lVar1,param_2,0xa081,&local_4cc);
    uVar8 = (ulong)uVar4;
    if (uVar4 == 0) {
      uVar4 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_4cc,0xa0810111,
                           local_4c8,0x488,0);
      uVar8 = (ulong)uVar4;
      switch(uVar4) {
      case 0:
        puVar3 = *(undefined8 **)(lVar5 + 0x618);
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
        if ((undefined8 *)(lVar5 + 0x618) == puVar3) {
          return uVar8;
        }
        plVar7 = local_4c0;
        uVar6 = uVar8;
        if (local_4c8[0] != 0) {
          do {
            if (plVar7[1] == puVar3[-0x2c] && *plVar7 == puVar3[-0x2d]) {
              lVar1 = alStack_4b0[uVar6 * 3];
              puVar3[-0x3e] = lVar1;
              if (*(int *)(puVar3 + -0x43) == param_3) {
                *param_4 = lVar1;
              }
              break;
            }
            uVar4 = (int)uVar6 + 1;
            plVar7 = plVar7 + 3;
            uVar6 = (ulong)uVar4;
          } while (uVar4 != local_4c8[0]);
        }
        puVar3 = (undefined8 *)*puVar3;
      } while( true );
    }
  }
  if (1 < DAT_01216a78) {
    fVar9 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar5,"dmal/common/common_vgpu.c",0x276,"cDeviceGetVgpuInstanceFbUsage",
                 0x276,uVar8);
  }
  return uVar8;
}


// ===== 0022e7e0 FUN_0022e7e0 =====

int FUN_0022e7e0(long param_1,long param_2,uint *param_3,void *param_4,int param_5)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  int *piVar4;
  float fVar5;
  char local_24d;
  undefined4 local_24c;
  int local_248 [3];
  undefined1 local_23c [524];
  
  piVar4 = local_248;
  for (lVar3 = 0x41; lVar3 != 0; lVar3 = lVar3 + -1) {
    piVar4[0] = 0;
    piVar4[1] = 0;
    piVar4 = piVar4 + 2;
  }
  *piVar4 = 0;
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_2,0xa081,&local_24c);
    if (iVar2 == 0) {
      if (param_5 != -1) {
        lVar3 = *(long *)(param_2 + 0x256d8);
        local_24d = '\0';
        if (((lVar3 == 0) || (*(long *)(lVar3 + 0x30) == 0)) ||
           ((pcVar1 = *(code **)(*(long *)(lVar3 + 0x30) + 0x148), pcVar1 == (code *)0x0 ||
            ((*pcVar1)(lVar3,param_2,&local_24d), local_24d == '\0')))) {
switchD_0022e923_caseD_56:
          return 3;
        }
      }
      local_248[0] = param_5;
      iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_24c,0xa0810105,
                           local_248,0x20c,0);
      switch(iVar2) {
      case 0:
        *param_3 = local_248[2];
        if (local_248[2] == 0) {
          return iVar2;
        }
        memcpy(param_4,local_23c,(ulong)(uint)local_248[2] * 4);
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
        goto switchD_0022e923_caseD_56;
      case 0x59:
        return 0x11;
      case 0x62:
        return 0x10;
      }
    }
  }
  if (1 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar3,"dmal/common/common_vgpu.c",0x133,"cDeviceGetCreatableVgpus",0x133,
                 iVar2);
  }
  return iVar2;
}


// ===== 0022ea90 FUN_0022ea90 =====

uint FUN_0022ea90(long param_1,long param_2,ulong param_3,int *param_4)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  code *pcVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  ulong uVar13;
  undefined8 uVar14;
  ulong uVar15;
  int *piVar16;
  int *piVar17;
  float fVar18;
  undefined8 uVar19;
  int local_48;
  undefined4 local_44;
  undefined8 local_40;
  
  uVar10 = (ulong)*(uint *)(param_2 + 4);
  if (*(long *)(param_4 + uVar10 * 0xc + 2) == 0) {
    *(long *)(param_4 + uVar10 * 0xc + 2) = param_2;
    lVar11 = *(long *)(param_2 + 0x256d8);
    if ((*(undefined8 **)(lVar11 + 0x50) == (undefined8 *)0x0) ||
       (pcVar5 = (code *)**(undefined8 **)(lVar11 + 0x50), pcVar5 == (code *)0x0)) {
      uVar7 = 3;
LAB_0022ef16:
      if (1 < DAT_01216a78) {
        fVar18 = (float)FUN_002917b0(&DAT_01216a60);
        lVar11 = syscall(0xba);
        FUN_002340f0((double)(fVar18 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n"
                     ,"ERROR",lVar11,"dmal/common/common_vgpu.c",0x8be,"cDeviceCreateOsEvent",0x8be,
                     uVar7);
      }
    }
    else {
      lVar12 = *(long *)(lVar11 + 0x10);
      uVar7 = (*pcVar5)(lVar11,param_2,0x80,&local_40);
      uVar15 = local_40;
      if (uVar7 != 0) goto LAB_0022ef16;
      if (4 < DAT_01216a78) {
        fVar18 = (float)FUN_002917b0(&DAT_01216a60);
        lVar11 = syscall(0xba);
        FUN_002340f0((double)(fVar18 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n",
                     "DEBUG",lVar11,"dmal/common/common_vgpu.c",0x8bf,uVar15 & 0xffffffff);
      }
      uVar7 = (**(code **)(lVar12 + 0x30))
                        (DAT_0038088c,local_40 & 0xffffffff,0,param_4 + uVar10 * 0xc + 4);
      uVar15 = local_40;
      if (4 < DAT_01216a78) {
        iVar9 = param_4[uVar10 * 0xc + 4];
        fVar18 = (float)FUN_002917b0(&DAT_01216a60);
        lVar11 = syscall(0xba);
        FUN_002340f0((double)(fVar18 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %x %d\n"
                     ,"DEBUG",lVar11,"dmal/common/common_vgpu.c",0x8c1,uVar15 & 0xffffffff,uVar7,
                     iVar9);
      }
      switch(uVar7) {
      case 0:
        *param_4 = *param_4 + 1;
        goto LAB_0022ead2;
      default:
        uVar7 = 999;
        break;
      case 3:
      case 0x66:
        uVar7 = 10;
        break;
      case 0xf:
        break;
      case 0x17:
      case 99:
        uVar7 = 0x13;
        break;
      case 0x1a:
        uVar7 = 0x17;
        break;
      case 0x1b:
        uVar7 = 4;
        break;
      case 0x1f:
      case 0x3b:
      case 0x54:
        uVar7 = 2;
        break;
      case 0x51:
        uVar7 = 0x14;
        break;
      case 0x55:
        uVar7 = 0x1b;
        break;
      case 0x56:
        uVar7 = 3;
        break;
      case 0x59:
        uVar7 = 0x11;
        break;
      case 0x62:
        uVar7 = 0x10;
      }
    }
    if (DAT_01216a78 < 2) {
      return uVar7;
    }
    fVar18 = (float)FUN_002917b0(&DAT_01216a60);
    lVar11 = syscall(0xba);
    fVar18 = fVar18 * DAT_00298548;
    uVar19 = 0x93d;
    uVar14 = 0x93d;
    goto LAB_0022ef7c;
  }
LAB_0022ead2:
  piVar16 = param_4 + uVar10 * 0xc + 8;
  uVar15 = 0;
  piVar17 = param_4 + uVar10 * 0xc + 8;
  while( true ) {
    uVar4 = *(ulong *)(param_4 + uVar10 * 0xc + 6);
    uVar13 = 1L << ((byte)uVar15 & 0x3f);
    if (((uVar4 & uVar13) == 0) && ((param_3 & uVar13) != 0)) break;
LAB_0022ecf0:
    uVar7 = (int)uVar15 + 1;
    uVar15 = (ulong)uVar7;
    piVar16 = piVar16 + 1;
    piVar17 = piVar17 + 1;
    if (uVar7 == 5) {
      return 0;
    }
  }
  uVar2 = *(uint *)(&DAT_002da2dc + uVar13 * 4);
  if (uVar2 < 5) {
    if ((uVar4 & *(ulong *)(&DAT_002da2a0 + (ulong)uVar2 * 8)) != 0) {
      *(ulong *)(param_4 + uVar10 * 0xc + 6) = uVar4 | uVar13;
      goto LAB_0022ecf0;
    }
  }
  else if (uVar2 == 0xffffffff) {
    return 999;
  }
  local_40 = 0;
  iVar9 = param_4[uVar10 * 0xc + 4];
  lVar11 = *(long *)(param_1 + 0x10);
  local_48 = iVar9;
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x20) != 0)) &&
     (pcVar5 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0x80), pcVar5 != (code *)0x0)) {
    (*pcVar5)(DAT_012164a0,piVar17);
  }
  lVar12 = *(long *)(param_2 + 0x256d8);
  if (((lVar12 == 0) || (*(undefined8 **)(lVar12 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar5 = (code *)**(undefined8 **)(lVar12 + 0x50), pcVar5 == (code *)0x0)) {
    uVar7 = 3;
LAB_0022ed56:
    if (1 < DAT_01216a78) {
      fVar18 = (float)FUN_002917b0(&DAT_01216a60);
      lVar11 = syscall(0xba);
      FUN_002340f0((double)(fVar18 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar11,"dmal/common/common_vgpu.c",0x62,"cVgpuDeviceCreateNvEvent",0x62,
                   uVar7);
    }
  }
  else {
    uVar7 = (*pcVar5)(lVar12,param_2,0xa081,&local_44);
    uVar6 = local_44;
    if (uVar7 != 0) goto LAB_0022ed56;
    if (4 < DAT_01216a78) {
      iVar8 = *piVar16;
      fVar18 = (float)FUN_002917b0(&DAT_01216a60);
      lVar12 = syscall(0xba);
      FUN_002340f0((double)(fVar18 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %x %x %p\n","DEBUG",lVar12,
                   "dmal/common/common_vgpu.c",100,uVar6,iVar8,uVar2,&local_48);
    }
    iVar8 = (**(code **)(lVar11 + 0x40))(DAT_0038088c,local_44,*piVar16,0x79,uVar2,&local_48);
    uVar6 = local_44;
    if (4 < DAT_01216a78) {
      iVar3 = *piVar16;
      fVar18 = (float)FUN_002917b0(&DAT_01216a60);
      lVar12 = syscall(0xba);
      FUN_002340f0((double)(fVar18 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %x %x %p %x\n","DEBUG",lVar12,
                   "dmal/common/common_vgpu.c",0x6d,uVar6,iVar3,uVar2,&local_48,iVar8);
    }
    if (iVar8 == 0) {
      if (iVar9 == local_48) {
        uVar14 = 0;
        local_40 = CONCAT44(2,uVar2);
        iVar9 = FUN_0019c780(lVar11,DAT_0038088c,local_44,0xa0810106,&local_40,8);
        if (iVar9 == 0) goto LAB_0022ece0;
        (**(code **)(lVar11 + 0x28))(DAT_0038088c,local_44,*piVar16,uVar14);
        if (1 < DAT_01216a78) {
          fVar18 = (float)FUN_002917b0(&DAT_01216a60);
          lVar11 = syscall(0xba);
          FUN_002340f0((double)(fVar18 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       "ERROR",lVar11,"dmal/common/common_vgpu.c",0x87);
        }
        if (iVar9 - 3U < 100) {
          uVar1 = *(ushort *)(&DAT_002da1c0 + (ulong)(iVar9 - 3U) * 2);
          goto LAB_0022ecd8;
        }
      }
      else {
        (**(code **)(lVar11 + 0x28))(DAT_0038088c,local_44,param_4[uVar15 + uVar10 * 0xc + 8]);
      }
LAB_0022ee10:
      uVar7 = 999;
    }
    else {
      if (1 < DAT_01216a78) {
        fVar18 = (float)FUN_002917b0(&DAT_01216a60);
        lVar11 = syscall(0xba);
        FUN_002340f0((double)(fVar18 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR"
                     ,lVar11,"dmal/common/common_vgpu.c",0x72);
      }
      if (99 < iVar8 - 3U) goto LAB_0022ee10;
      uVar1 = *(ushort *)(&DAT_002da1c0 + (ulong)(iVar8 - 3U) * 2);
LAB_0022ecd8:
      uVar7 = (uint)uVar1;
      if (uVar7 == 0) {
LAB_0022ece0:
        *(ulong *)(param_4 + uVar10 * 0xc + 6) = *(ulong *)(param_4 + uVar10 * 0xc + 6) | uVar13;
        goto LAB_0022ecf0;
      }
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar7;
  }
  fVar18 = (float)FUN_002917b0(&DAT_01216a60);
  lVar11 = syscall(0xba);
  fVar18 = fVar18 * DAT_00298548;
  uVar19 = 0x961;
  uVar14 = 0x961;
LAB_0022ef7c:
  FUN_002340f0((double)fVar18,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar11,
               "dmal/common/common_vgpu.c",uVar14,"cDeviceRegisterVgpuEvents",uVar19,uVar7);
  return uVar7;
}


// ===== 0022f3e0 FUN_0022f3e0 =====

uint FUN_0022f3e0(long param_1,long param_2,uint *param_3,long param_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  uint uVar17;
  long lVar18;
  tm *ptVar19;
  undefined8 *puVar20;
  undefined1 (*pauVar21) [16];
  uint uVar22;
  float fVar23;
  undefined4 local_4d14;
  ulong local_4d10;
  undefined8 local_4d08;
  undefined8 uStack_4d00;
  undefined8 local_4cf8;
  undefined8 uStack_4cf0;
  undefined8 local_4ce8;
  long lStack_4ce0;
  char *local_4cd8;
  undefined1 local_4cc8 [4];
  uint local_4cc4;
  undefined8 local_4c98 [2445];
  
  lVar18 = *(long *)(param_2 + 0x256d8);
  if (((lVar18 == 0) || (*(undefined8 **)(lVar18 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar4 = (code *)**(undefined8 **)(lVar18 + 0x50), pcVar4 == (code *)0x0)) {
    uVar17 = 3;
  }
  else {
    lVar5 = *(long *)(param_2 + 0x25d60);
    uVar17 = (*pcVar4)(lVar18,param_2,0xa081,&local_4d14);
    if (uVar17 == 0) {
      uVar17 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_4d14,0xa0810102,
                            local_4cc8,0x4c88,0);
      switch(uVar17) {
      case 0:
        goto switchD_0022f499_caseD_0;
      default:
        return 999;
      case 3:
      case 0x66:
        return 10;
      case 0xf:
        return uVar17;
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
    fVar23 = (float)FUN_002917b0(&DAT_01216a60);
    lVar18 = syscall(0xba);
    FUN_002340f0((double)(fVar23 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar18,"dmal/common/common_vgpu.c",0x2a2,"cDeviceGetVgpuGuestInstances",
                 0x2a2,uVar17);
  }
  return uVar17;
switchD_0022f499_caseD_0:
  pauVar21 = (undefined1 (*) [16])(param_4 + 0x3c);
  *param_3 = local_4cc4;
  puVar20 = local_4c98;
  uVar22 = uVar17;
  if (local_4cc4 != 0) {
    do {
      uVar2 = *(undefined4 *)(puVar20 + -5);
      *pauVar21 = (undefined1  [16])0x0;
      *(undefined4 *)pauVar21[-3] = uVar2;
      *(undefined4 *)(pauVar21[-3] + 4) = *(undefined4 *)((long)puVar20 + -0x24);
      *(undefined4 *)(pauVar21[-4] + 4) = *(undefined4 *)((long)puVar20 + 0x11c);
      *(undefined4 *)(pauVar21[-4] + 8) = *(undefined4 *)(puVar20 + 0x23);
      *(undefined4 *)(pauVar21[-4] + 0xc) = *(undefined4 *)(puVar20 + 0x2d);
      *(undefined4 *)(pauVar21[-3] + 8) = *(undefined4 *)(puVar20 + -4);
      *(undefined4 *)(pauVar21[-3] + 0xc) = *(undefined4 *)((long)puVar20 + -0x1c);
      *(undefined4 *)pauVar21[-2] = *(undefined4 *)(puVar20 + -3);
      *(undefined4 *)(pauVar21[-1] + 4) = *(undefined4 *)(puVar20 + 0x29);
      *(undefined8 *)(pauVar21[-2] + 0xc) = puVar20[0x2a];
      *(uint *)pauVar21[4] = (uint)(*(char *)((long)puVar20 + 0x15c) == '\x01');
      *(undefined4 *)(pauVar21[3] + 0xc) = *(undefined4 *)(puVar20 + 0x2c);
      *(undefined4 *)(pauVar21[-2] + 4) = *(undefined4 *)((long)puVar20 + -0x14);
      *(uint *)(pauVar21[-1] + 8) = (uint)*(byte *)(puVar20 + -2);
      *(undefined4 *)(pauVar21[-1] + 0xc) = *(undefined4 *)((long)puVar20 + -0xc);
      (*pauVar21)[0xe] = *(undefined1 *)((long)puVar20 + -4);
      *(undefined4 *)(pauVar21[0x1d] + 4) = *(undefined4 *)((long)puVar20 + 0x164);
      uVar6 = puVar20[0x24];
      snprintf(pauVar21[1] + 4,0x20,"%08x:%02x:%02x.0",uVar6 >> 0x10,uVar6 >> 8 & 0xff,uVar6 & 0xff)
      ;
      uVar7 = puVar20[0x29];
      uVar8 = puVar20[0x2a];
      uVar9 = puVar20[0x27];
      uVar10 = puVar20[0x28];
      uVar11 = puVar20[0x2b];
      uVar12 = puVar20[0x2c];
      uVar13 = puVar20[0x2d];
      uVar14 = puVar20[0x2e];
      uVar15 = puVar20[0x25];
      uVar16 = puVar20[0x26];
      *(undefined8 *)(pauVar21[9] + 4) = uVar7;
      *(undefined8 *)(pauVar21[9] + 0xc) = uVar8;
      *(undefined8 *)(pauVar21[0xd] + 4) = uVar7;
      *(undefined8 *)(pauVar21[0xd] + 0xc) = uVar8;
      uVar7 = puVar20[0x2f];
      uVar8 = puVar20[0x30];
      *(undefined8 *)(pauVar21[7] + 4) = uVar15;
      *(undefined8 *)(pauVar21[7] + 0xc) = uVar16;
      *(undefined8 *)(pauVar21[8] + 4) = uVar9;
      *(undefined8 *)(pauVar21[8] + 0xc) = uVar10;
      *(undefined8 *)(pauVar21[10] + 4) = uVar11;
      *(undefined8 *)(pauVar21[10] + 0xc) = uVar12;
      *(undefined8 *)(pauVar21[0xb] + 4) = uVar13;
      *(undefined8 *)(pauVar21[0xb] + 0xc) = uVar14;
      *(undefined8 *)(pauVar21[0xc] + 4) = uVar9;
      *(undefined8 *)(pauVar21[0xc] + 0xc) = uVar10;
      *(undefined8 *)(pauVar21[0xe] + 4) = uVar11;
      *(undefined8 *)(pauVar21[0xe] + 0xc) = uVar12;
      *(undefined8 *)(pauVar21[0xf] + 4) = uVar13;
      *(undefined8 *)(pauVar21[0xf] + 0xc) = uVar14;
      *(undefined8 *)(pauVar21[0x10] + 4) = uVar7;
      *(undefined8 *)(pauVar21[0x10] + 0xc) = uVar8;
      strncpy(pauVar21[4] + 4,(char *)(puVar20 + 2),0xf);
      strncpy(pauVar21[5] + 4,(char *)(puVar20 + 10),0x1f);
      strncpy(pauVar21[0x11] + 4,(char *)(puVar20 + 0x12),0x7f);
      *(uint *)(pauVar21[0x19] + 4) = (uint)(*(int *)(puVar20 + 0x22) == 1);
      if (*(int *)((long)puVar20 + -0x24) == 0) {
        *(undefined8 *)(pauVar21[0x1a] + 0xc) = *puVar20;
      }
      else {
        uVar7 = *puVar20;
        uVar8 = puVar20[1];
        uVar9 = puVar20[2];
        uVar10 = puVar20[3];
        *(undefined4 *)(pauVar21[0x1c] + 0xc) = *(undefined4 *)(puVar20 + 4);
        uVar1 = *(undefined1 *)((long)puVar20 + 0x24);
        *(undefined8 *)(pauVar21[0x1a] + 0xc) = uVar7;
        *(undefined8 *)(pauVar21[0x1b] + 4) = uVar8;
        pauVar21[0x1d][0] = uVar1;
        *(undefined8 *)(pauVar21[0x1b] + 0xc) = uVar9;
        *(undefined8 *)(pauVar21[0x1c] + 4) = uVar10;
      }
      iVar3 = *(int *)(puVar20 + 0x2b);
      if (iVar3 == 2) {
        *(undefined4 *)pauVar21[1] = 2;
      }
      else if (iVar3 == 3) {
        *(undefined4 *)pauVar21[1] = 3;
      }
      else {
        *(uint *)pauVar21[1] = (uint)(iVar3 == 1);
      }
      if (*(char *)((long)puVar20 + -4) == '\x02') {
        local_4d10 = (ulong)*(uint *)(puVar20 + -1);
        ptVar19 = localtime((time_t *)&local_4d10);
        local_4d08._0_4_ = ptVar19->tm_sec;
        local_4d08._4_4_ = ptVar19->tm_min;
        uStack_4d00._0_4_ = ptVar19->tm_hour;
        uStack_4d00._4_4_ = ptVar19->tm_mday;
        uVar7._0_4_ = ptVar19->tm_mon;
        uVar7._4_4_ = ptVar19->tm_year;
        uStack_4cf0._0_4_ = ptVar19->tm_wday;
        uStack_4cf0._4_4_ = ptVar19->tm_yday;
        local_4ce8 = *(undefined8 *)&ptVar19->tm_isdst;
        lStack_4ce0 = ptVar19->tm_gmtoff;
        local_4cd8 = ptVar19->tm_zone;
        *(int *)*pauVar21 = uVar7._4_4_ + 0x76c;
        local_4cf8._0_2_ = (short)(undefined4)uVar7;
        *(short *)(*pauVar21 + 4) = (short)local_4cf8 + 1;
        *(short *)(*pauVar21 + 6) = (short)uStack_4d00._4_4_;
        *(short *)(*pauVar21 + 8) = (short)(undefined4)uStack_4d00;
        *(short *)(*pauVar21 + 10) = (short)local_4d08._4_4_;
        *(short *)(*pauVar21 + 0xc) = (short)(undefined4)local_4d08;
        local_4cf8 = uVar7;
      }
      uVar22 = uVar22 + 1;
      pauVar21 = (undefined1 (*) [16])(pauVar21[0x22] + 8);
      puVar20 = puVar20 + 0x33;
    } while (uVar22 < local_4cc4);
  }
  *(undefined4 *)(lVar5 + 0x628) = 1;
  return uVar17;
}


// ===== 0022f920 FUN_0022f920 =====

undefined8 FUN_0022f920(long param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  code *pcVar4;
  long lVar5;
  int iVar6;
  long lVar7;
  char *pcVar8;
  long lVar9;
  int iVar10;
  long lVar11;
  float fVar12;
  undefined4 local_44;
  ulong local_40 [2];
  
  if (param_2 != (char *)0x0) {
    if (((*param_2 == '\x01') ||
        ((((*(int *)(param_2 + 0x14) != 0 && (*(int *)(param_2 + 0x1c) == 0)) &&
          (*(int *)(param_2 + 0x10) != 0)) && (*(long *)(param_2 + 0x20) != 0)))) &&
       (DAT_012148b8 != 0)) {
      lVar9 = (ulong)*(uint *)(param_2 + 4) * 0x30 + DAT_012148b8;
      pcVar8 = *(char **)(lVar9 + 8);
      if ((pcVar8 != (char *)0x0) &&
         (((*pcVar8 == '\x01' ||
           (((*(int *)(pcVar8 + 0x14) != 0 && (*(int *)(pcVar8 + 0x1c) == 0)) &&
            ((*(int *)(pcVar8 + 0x10) != 0 && (*(long *)(pcVar8 + 0x20) != 0)))))) &&
          (*(long *)(pcVar8 + 0x25d60) != 0)))) {
        iVar10 = 0;
        lVar11 = lVar9;
        do {
          iVar1 = *(int *)(lVar11 + 0x20);
          if (iVar1 != 0) {
            lVar5 = *(long *)(param_1 + 0x10);
            lVar7 = *(long *)(pcVar8 + 0x256d8);
            local_40[0] = 0;
            uVar3 = *(uint *)(&DAT_002da2dc + (1L << ((byte)iVar10 & 0x3f)) * 4);
            if (((lVar7 != 0) && (*(undefined8 **)(lVar7 + 0x50) != (undefined8 *)0x0)) &&
               (pcVar4 = (code *)**(undefined8 **)(lVar7 + 0x50), pcVar4 != (code *)0x0)) {
              iVar6 = (*pcVar4)(lVar7,pcVar8,0xa081,&local_44);
              if (iVar6 == 0) {
                local_40[0] = (ulong)uVar3;
                iVar6 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_44,
                                     0xa0810106,local_40,8);
                if ((iVar6 != 0) && (1 < DAT_01216a78)) {
                  fVar12 = (float)FUN_002917b0(&DAT_01216a60);
                  lVar7 = syscall(0xba);
                  FUN_002340f0((double)(fVar12 * DAT_00298548),
                               "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar7,
                               "dmal/common/common_vgpu.c",0xa6);
                }
                (**(code **)(lVar5 + 0x28))(DAT_0038088c,local_44,iVar1);
              }
            }
            *(undefined4 *)(lVar11 + 0x20) = 0;
            pcVar8 = *(char **)(lVar9 + 8);
          }
          iVar10 = iVar10 + 1;
          lVar11 = lVar11 + 4;
        } while (iVar10 != 5);
        lVar11 = *(long *)(pcVar8 + 0x256d8);
        if ((*(undefined8 **)(lVar11 + 0x50) != (undefined8 *)0x0) &&
           (pcVar4 = (code *)**(undefined8 **)(lVar11 + 0x50), pcVar4 != (code *)0x0)) {
          uVar2 = *(undefined4 *)(lVar9 + 0x10);
          lVar9 = *(long *)(lVar11 + 0x10);
          iVar10 = (*pcVar4)(lVar11,pcVar8,0x80,local_40);
          if (iVar10 == 0) {
            (**(code **)(lVar9 + 0x38))(DAT_0038088c,local_40[0] & 0xffffffff,uVar2);
          }
        }
      }
    }
    return 0;
  }
  return 0;
}


// ===== 0022fbb0 FUN_0022fbb0 =====

int FUN_0022fbb0(long param_1,long param_2,int param_3,char *param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  int *piVar5;
  undefined8 uVar6;
  float fVar7;
  undefined8 uVar8;
  undefined4 local_157c;
  int local_1578 [3];
  char local_156c [64];
  char local_152c [192];
  char local_146c [128];
  undefined8 local_13ec;
  undefined8 local_13e4;
  undefined4 local_13d8;
  undefined4 local_13c4;
  undefined8 local_13c0;
  undefined8 local_13b8;
  undefined8 local_13b0;
  undefined8 local_13a0;
  undefined8 local_1398;
  undefined8 local_1380;
  undefined4 local_1378;
  ushort local_1374;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined8 local_1dc;
  int local_1d4;
  undefined4 local_1d0;
  uint local_1cc;
  undefined1 local_1c8 [192];
  uint local_108;
  undefined1 local_104 [212];
  
  piVar5 = local_1578;
  for (lVar4 = 0x2a7; lVar4 != 0; lVar4 = lVar4 + -1) {
    piVar5[0] = 0;
    piVar5[1] = 0;
    piVar5 = piVar5 + 2;
  }
  if (param_3 == 0) {
    return 2;
  }
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
LAB_0022fc96:
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    fVar7 = fVar7 * DAT_00298548;
    uVar8 = 0x4b3;
    uVar6 = 0x4b3;
LAB_0022fd03:
    FUN_002340f0((double)fVar7,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
                 "dmal/common/common_vgpu.c",uVar6,"cVgpuTypeGetStaticInfo",uVar8,iVar2);
  }
  else {
    iVar2 = (*pcVar1)(lVar4,param_2,0xa081,&local_157c);
    if (iVar2 != 0) goto LAB_0022fc96;
    local_1578[0] = param_3;
    iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_157c,0xa0810103,
                         local_1578,0x1538,0);
    switch(iVar2) {
    case 0:
      strncpy(param_4,local_156c,0x40);
      strncpy(param_4 + 0x40,local_152c,0x40);
      strncpy(param_4 + 0x80,local_146c,0x80);
      *(undefined8 *)(param_4 + 0x108) = local_13ec;
      *(undefined8 *)(param_4 + 0x110) = local_13e4;
      *(undefined8 *)(param_4 + 0x120) = local_13c0;
      *(uint *)(param_4 + 0x104) = (uint)local_1374;
      *(undefined8 *)(param_4 + 0x128) = local_13b8;
      *(undefined4 *)(param_4 + 0x138) = local_13c4;
      *(undefined4 *)(param_4 + 0x140) = local_1ec;
      *(undefined4 *)(param_4 + 0x13c) = local_1e8;
      *(undefined4 *)(param_4 + 0x118) = local_1378;
      *(undefined4 *)(param_4 + 0x11c) = local_13d8;
      *(undefined8 *)(param_4 + 0x130) = local_13b0;
      *(undefined4 *)(param_4 + 0x144) = local_1e0;
      *(undefined8 *)(param_4 + 0x148) = local_1dc;
      *(undefined8 *)(param_4 + 0x2e0) = local_13a0;
      *(undefined8 *)(param_4 + 0x2e8) = local_1398;
      *(undefined8 *)(param_4 + 0x2f0) = local_1380;
      if (local_1d4 == -1) {
        param_4[0x100] = -1;
        param_4[0x101] = -1;
        param_4[0x102] = -1;
        param_4[0x103] = -1;
LAB_0022fe9c:
        *(undefined4 *)(param_4 + 0x150) = local_1d0;
        *(uint *)(param_4 + 0x218) = local_108;
        if (local_108 != 0) {
          memcpy(param_4 + 0x21c,local_104,(ulong)local_108 * 4);
        }
        *(uint *)(param_4 + 0x154) = local_1cc;
        if (local_1cc != 0) {
          memcpy(param_4 + 0x158,local_1c8,(ulong)local_1cc * 4);
        }
        *(undefined4 *)(param_4 + 0x2f8) = local_1e4;
        return iVar2;
      }
      iVar3 = FUN_00133bb0(local_1d4,param_4 + 0x100);
      if (iVar3 == 0) goto LAB_0022fe9c;
      if (DAT_01216a78 < 2) {
        return iVar3;
      }
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      fVar7 = fVar7 * DAT_00298548;
      uVar8 = 0x4dc;
      uVar6 = 0x4dc;
      iVar2 = iVar3;
      goto LAB_0022fd03;
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
  return iVar2;
}


// ===== 0022ffd0 FUN_0022ffd0 =====

int FUN_0022ffd0(long param_1,long param_2,long param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  undefined4 local_74;
  int local_70;
  undefined4 local_6c;
  undefined1 local_68 [16];
  uint local_58;
  undefined8 uStack_54;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 local_40;
  
  uStack_48 = 0;
  uStack_44 = 0;
  local_40 = 0;
  local_70 = 0;
  local_68 = (undefined1  [16])0x0;
  local_58 = 0;
  uStack_54 = 0;
  uStack_4c = 0;
  iVar2 = FUN_0022b610(param_2,&local_70,7);
  if (iVar2 == 0) {
    iVar2 = 3;
    if (local_70 == 0) {
      return 3;
    }
    lVar3 = *(long *)(param_2 + 0x256d8);
    if ((((lVar3 != 0) && (*(undefined8 **)(lVar3 + 0x50) != (undefined8 *)0x0)) &&
        (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 != (code *)0x0)) &&
       (iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_74), iVar2 == 0)) {
      local_68._0_4_ = 1;
      iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_74,0x20801122,local_68
                           ,0x2c,0);
      switch(iVar2) {
      case 0:
        lVar3 = 0;
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
        iVar2 = FUN_00133bf0(*(undefined4 *)(local_68 + lVar3 + 4),&local_6c);
        if (iVar2 != 0) {
          if (DAT_01216a78 < 2) {
            return iVar2;
          }
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",
                       "ERROR",lVar3,"dmal/common/common_vgpu.c",0x827,iVar2);
          return iVar2;
        }
        *(undefined4 *)(param_3 + lVar3) = local_6c;
        lVar3 = lVar3 + 4;
      } while (lVar3 != 0xc);
      *(undefined8 *)(param_3 + 0xc) = uStack_54;
      *(uint *)(param_3 + 0x14) = local_58 & 0xff;
      *(ulong *)(param_3 + 0x18) = CONCAT44(uStack_48,uStack_4c);
      *(ulong *)(param_3 + 0x20) = CONCAT44(local_40,uStack_44);
      return 0;
    }
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    fVar5 = fVar5 * DAT_00298548;
    uVar6 = 0x81a;
    uVar4 = 0x81a;
  }
  else {
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    fVar5 = fVar5 * DAT_00298548;
    uVar6 = 0x812;
    uVar4 = 0x812;
  }
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
               "dmal/common/common_vgpu.c",uVar4,"cDeviceGetVgpuObjschedCapabilities",uVar6,iVar2);
  return iVar2;
}


// ===== 00230300 FUN_00230300 =====

int FUN_00230300(long param_1,long param_2,uint *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  double dVar6;
  undefined8 uVar7;
  undefined4 local_54;
  int local_50;
  uint local_4c;
  undefined1 local_48 [16];
  uint local_38;
  
  local_38 = 0;
  local_50 = 0;
  local_48 = (undefined1  [16])0x0;
  iVar2 = FUN_0022b610(param_2,&local_50,7);
  if (iVar2 != 0) {
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    uVar7 = 0x7d2;
    uVar4 = 0x7d2;
    dVar6 = (double)(fVar5 * DAT_00298548);
    goto LAB_00230409;
  }
  if (local_50 == 0) {
switchD_002304c8_caseD_56:
    return 3;
  }
  lVar3 = *(long *)(param_2 + 0x256d8);
  local_4c = local_4c & 0xffffff00;
  if (lVar3 == 0) {
LAB_002304d0:
    iVar2 = 3;
  }
  else {
    if ((*(long *)(lVar3 + 0x30) != 0) &&
       (pcVar1 = *(code **)(*(long *)(lVar3 + 0x30) + 0x148), pcVar1 != (code *)0x0)) {
      (*pcVar1)(lVar3,param_2,&local_4c);
      if ((char)local_4c != '\0') {
        return 3;
      }
      lVar3 = *(long *)(param_2 + 0x256d8);
    }
    if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) goto LAB_002304d0;
    iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_54);
    if (iVar2 == 0) {
      local_48._0_4_ = 1;
      iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_54,0x20801120,local_48
                           ,0x14,0);
      switch(iVar2) {
      case 0:
        iVar2 = FUN_00133bf0(local_48._4_4_,&local_4c);
        if (iVar2 == 0) {
          *param_3 = local_4c;
          if (local_48._4_4_ == 2) {
            param_3[1] = 0;
            param_3[2] = 0;
            param_3[3] = 0;
            return 0;
          }
          param_3[1] = local_48._8_4_;
          if (local_48._8_4_ == 2) {
            param_3[2] = local_38;
            param_3[3] = local_48._12_4_;
            return 0;
          }
          if (local_48._8_4_ == 1) {
            param_3[2] = local_48._12_4_;
            return 0;
          }
          return 0;
        }
        if (DAT_01216a78 < 2) {
          return iVar2;
        }
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        uVar7 = 0x7ea;
        uVar4 = 0x7ea;
        dVar6 = (double)(fVar5 * DAT_00298548);
        goto LAB_00230409;
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
        goto switchD_002304c8_caseD_56;
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
  uVar7 = 0x7e1;
  uVar4 = 0x7e1;
  dVar6 = (double)(fVar5 * DAT_00298548);
LAB_00230409:
  FUN_002340f0(dVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
               "dmal/common/common_vgpu.c",uVar4,"cDeviceGetVgpuObjschedState",uVar7,iVar2);
  return iVar2;
}


// ===== 00230670 FUN_00230670 =====

int FUN_00230670(long param_1,long param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  float fVar8;
  double dVar9;
  undefined8 uVar10;
  undefined4 local_5e24;
  int local_5e20;
  uint local_5e1c;
  undefined4 local_5e18;
  int local_5e14;
  undefined8 local_5e10 [15];
  undefined8 auStack_5d98 [2985];
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  
  memset(&local_5e18,0,0x5dd8);
  local_5e20 = 0;
  iVar2 = FUN_0022b610(param_2,&local_5e20,7);
  if (iVar2 != 0) {
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar8 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    uVar10 = 0x6aa;
    uVar7 = 0x6aa;
    dVar9 = (double)(fVar8 * DAT_00298548);
    goto LAB_002307a7;
  }
  if (local_5e20 == 0) {
switchD_0023094a_caseD_56:
    return 3;
  }
  lVar3 = *(long *)(param_2 + 0x256d8);
  local_5e1c = local_5e1c & 0xffffff00;
  if (lVar3 == 0) {
LAB_00230890:
    iVar2 = 3;
  }
  else {
    if ((*(long *)(lVar3 + 0x30) != 0) &&
       (pcVar1 = *(code **)(*(long *)(lVar3 + 0x30) + 0x148), pcVar1 != (code *)0x0)) {
      (*pcVar1)(lVar3,param_2,&local_5e1c);
      if ((char)local_5e1c != '\0') {
        return 3;
      }
      lVar3 = *(long *)(param_2 + 0x256d8);
    }
    if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) goto LAB_00230890;
    iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_5e24);
    if (iVar2 == 0) {
      iVar2 = FUN_00133c90(*param_3,&local_5e18);
      if (iVar2 == 0) {
        iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_5e24,0x2080110e,
                             &local_5e18,0x5dd8,0);
        switch(iVar2) {
        case 0:
          iVar2 = FUN_00133bf0(local_50,&local_5e1c);
          if (iVar2 == 0) {
            iVar2 = FUN_00133ce0(local_5e18,param_3);
            if (iVar2 == 0) {
              param_3[1] = local_5e1c;
              param_3[5] = local_5e14;
              param_3[2] = local_4c;
              if (local_4c == 2) {
                *(ulong *)(param_3 + 3) = CONCAT44(uStack_44,local_48);
              }
              else if (local_4c == 1) {
                param_3[3] = uStack_44;
              }
              if (local_5e14 != 0) {
                puVar4 = local_5e10;
                puVar6 = (undefined8 *)(param_3 + 6);
                do {
                  puVar5 = puVar4 + 0xf;
                  *puVar6 = *puVar4;
                  puVar6[1] = puVar4[1];
                  puVar6[2] = (ulong)*(uint *)(puVar4 + 2);
                  *(undefined4 *)(puVar6 + 3) = *(undefined4 *)((long)puVar4 + 0x14);
                  puVar6[4] = (ulong)*(uint *)(puVar4 + 3);
                  puVar6[5] = puVar4[4];
                  puVar4 = puVar5;
                  puVar6 = puVar6 + 6;
                } while (auStack_5d98 + (ulong)(local_5e14 - 1) * 0xf != puVar5);
                return 0;
              }
              return 0;
            }
            if (DAT_01216a78 < 2) {
              return iVar2;
            }
            fVar8 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            uVar10 = 0x6c7;
            uVar7 = 0x6c7;
            dVar9 = (double)(fVar8 * DAT_00298548);
          }
          else {
            if (DAT_01216a78 < 2) {
              return iVar2;
            }
            fVar8 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            uVar10 = 0x6c4;
            uVar7 = 0x6c4;
            dVar9 = (double)(fVar8 * DAT_00298548);
          }
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
          goto switchD_0023094a_caseD_56;
        case 0x59:
          return 0x11;
        case 0x62:
          return 0x10;
        }
      }
      else {
        if (DAT_01216a78 < 2) {
          return iVar2;
        }
        fVar8 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        uVar10 = 0x6bc;
        uVar7 = 0x6bc;
        dVar9 = (double)(fVar8 * DAT_00298548);
      }
      goto LAB_002307a7;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar8 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  uVar10 = 0x6b9;
  uVar7 = 0x6b9;
  dVar9 = (double)(fVar8 * DAT_00298548);
LAB_002307a7:
  FUN_002340f0(dVar9,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
               "dmal/common/common_vgpu.c",uVar7,"cDeviceGetVgpuObjschedLog",uVar10,iVar2);
  return iVar2;
}


// ===== 00230b60 FUN_00230b60 =====

int FUN_00230b60(long param_1,long param_2,long param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  double dVar6;
  undefined8 uVar7;
  uint local_50;
  int local_4c;
  undefined1 local_48 [16];
  undefined4 local_38;
  
  local_38 = 0;
  local_4c = 0;
  local_48 = (undefined1  [16])0x0;
  if (param_2 == 0) {
    return 2;
  }
  if (param_3 == 0) {
    return 2;
  }
  iVar2 = FUN_0022b610(param_2,&local_4c,7);
  if (iVar2 != 0) {
    if (DAT_01216a78 < 2) {
      return iVar2;
    }
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    uVar7 = 0x6f5;
    uVar4 = 0x6f5;
    dVar6 = (double)(fVar5 * DAT_00298548);
    goto LAB_00230cc1;
  }
  if (local_4c == 0) {
switchD_00230d9b_caseD_56:
    return 3;
  }
  lVar3 = *(long *)(param_2 + 0x256d8);
  local_50 = local_50 & 0xffffff00;
  if (lVar3 == 0) {
    return 3;
  }
  if (*(long *)(lVar3 + 0x38) == 0) {
    return 3;
  }
  pcVar1 = *(code **)(*(long *)(lVar3 + 0x38) + 0x80);
  if (pcVar1 == (code *)0x0) {
    return 3;
  }
  (*pcVar1)(lVar3,param_2,&local_50);
  if ((char)local_50 == '\0') {
    return 3;
  }
  lVar3 = *(long *)(param_2 + 0x256d8);
  local_50 = local_50 & 0xffffff00;
  if (lVar3 == 0) {
LAB_00230da0:
    iVar2 = 3;
  }
  else {
    if ((*(long *)(lVar3 + 0x30) != 0) &&
       (pcVar1 = *(code **)(*(long *)(lVar3 + 0x30) + 0x148), pcVar1 != (code *)0x0)) {
      (*pcVar1)(lVar3,param_2,&local_50);
      if ((char)local_50 != '\0') {
        return 3;
      }
      lVar3 = *(long *)(param_2 + 0x256d8);
    }
    if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) goto LAB_00230da0;
    iVar2 = (*pcVar1)(lVar3,param_2,0x2080,&local_50);
    if (iVar2 == 0) {
      local_48._0_4_ = 1;
      iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_50,0x20801120,local_48
                           ,0x14,0);
      switch(iVar2) {
      case 0:
        iVar2 = FUN_00133bf0(local_48._4_4_,param_3 + 4);
        if (iVar2 == 0) {
          if (local_48._4_4_ == 2) {
            *(undefined8 *)(param_3 + 8) = 0;
            return 0;
          }
          *(undefined4 *)(param_3 + 8) = local_38;
          *(undefined4 *)(param_3 + 0xc) = local_48._12_4_;
          return 0;
        }
        if (DAT_01216a78 < 2) {
          return iVar2;
        }
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        uVar7 = 0x70a;
        uVar4 = 0x70a;
        dVar6 = (double)(fVar5 * DAT_00298548);
        goto LAB_00230cc1;
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
        goto switchD_00230d9b_caseD_56;
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
  uVar7 = 0x701;
  uVar4 = 0x701;
  dVar6 = (double)(fVar5 * DAT_00298548);
LAB_00230cc1:
  FUN_002340f0(dVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
               "dmal/common/common_vgpu.c",uVar4,"cDeviceGetVgpuObjschedState_v2",uVar7,iVar2);
  return iVar2;
}


// ===== 00230f00 FUN_00230f00 =====

int FUN_00230f00(long param_1,long param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  float fVar8;
  double dVar9;
  undefined8 uVar10;
  int local_5e2c;
  undefined4 local_5e24;
  int local_5e20;
  uint local_5e1c;
  undefined4 local_5e18;
  int local_5e14;
  undefined8 local_5e10 [15];
  undefined8 auStack_5d98 [2985];
  undefined4 local_50;
  undefined8 local_48;
  
  memset(&local_5e18,0,0x5dd8);
  local_5e20 = 0;
  if ((param_2 == 0) || (param_3 == (undefined4 *)0x0)) {
switchD_0023127c_caseD_1f:
    return 2;
  }
  local_5e2c = FUN_0022b610(param_2,&local_5e20,7);
  if (local_5e2c != 0) {
    if (DAT_01216a78 < 2) {
      return local_5e2c;
    }
    fVar8 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    uVar7 = 0x72b;
    uVar10 = 0x72b;
    dVar9 = (double)(fVar8 * DAT_00298548);
    goto LAB_0023109c;
  }
  if (local_5e20 == 0) {
switchD_0023127c_caseD_56:
    return 3;
  }
  lVar3 = *(long *)(param_2 + 0x256d8);
  local_5e1c = local_5e1c & 0xffffff00;
  if (lVar3 == 0) {
    return 3;
  }
  if (*(long *)(lVar3 + 0x38) == 0) {
    return 3;
  }
  pcVar1 = *(code **)(*(long *)(lVar3 + 0x38) + 0x80);
  if (pcVar1 == (code *)0x0) {
    return 3;
  }
  (*pcVar1)(lVar3,param_2,&local_5e1c);
  if ((char)local_5e1c == '\0') {
    return 3;
  }
  lVar3 = *(long *)(param_2 + 0x256d8);
  local_5e1c = local_5e1c & 0xffffff00;
  if (lVar3 == 0) {
LAB_002311b0:
    local_5e2c = 3;
  }
  else {
    if ((*(long *)(lVar3 + 0x30) != 0) &&
       (pcVar1 = *(code **)(*(long *)(lVar3 + 0x30) + 0x148), pcVar1 != (code *)0x0)) {
      (*pcVar1)(lVar3,param_2,&local_5e1c);
      if ((char)local_5e1c != '\0') {
        return 3;
      }
      lVar3 = *(long *)(param_2 + 0x256d8);
    }
    if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) goto LAB_002311b0;
    local_5e2c = (*pcVar1)(lVar3,param_2,0x2080,&local_5e24);
    if (local_5e2c == 0) {
      local_5e2c = FUN_00133c90(*param_3,&local_5e18);
      if (local_5e2c == 0) {
        iVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_5e24,0x2080110e,
                             &local_5e18,0x5dd8,0);
        switch(iVar2) {
        case 0:
          local_5e2c = FUN_00133bf0(local_50,&local_5e1c);
          if (local_5e2c == 0) {
            local_5e2c = FUN_00133ce0(local_5e18,param_3);
            if (local_5e2c == 0) {
              param_3[1] = local_5e1c;
              param_3[4] = local_5e14;
              *(undefined8 *)(param_3 + 2) = local_48;
              if (local_5e14 != 0) {
                puVar4 = local_5e10;
                puVar6 = (undefined8 *)(param_3 + 6);
                do {
                  puVar5 = puVar4 + 0xf;
                  *puVar6 = *puVar4;
                  puVar6[1] = puVar4[1];
                  puVar6[2] = (ulong)*(uint *)(puVar4 + 2);
                  *(undefined4 *)(puVar6 + 3) = *(undefined4 *)((long)puVar4 + 0x14);
                  puVar6[4] = (ulong)*(uint *)(puVar4 + 3);
                  puVar6[5] = puVar4[4];
                  *(undefined4 *)(puVar6 + 6) = *(undefined4 *)(puVar4 + 6);
                  puVar4 = puVar5;
                  puVar6 = puVar6 + 7;
                } while (puVar5 != auStack_5d98 + (ulong)(local_5e14 - 1) * 0xf);
                return 0;
              }
              return 0;
            }
            if (DAT_01216a78 < 2) {
              return local_5e2c;
            }
            fVar8 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            uVar7 = 0x74d;
            uVar10 = 0x74d;
            dVar9 = (double)(fVar8 * DAT_00298548);
          }
          else {
            if (DAT_01216a78 < 2) {
              return local_5e2c;
            }
            fVar8 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            uVar7 = 0x74a;
            uVar10 = 0x74a;
            dVar9 = (double)(fVar8 * DAT_00298548);
          }
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
          goto switchD_0023127c_caseD_1f;
        case 0x51:
          return 0x14;
        case 0x55:
          return 0x1b;
        case 0x56:
          goto switchD_0023127c_caseD_56;
        case 0x59:
          return 0x11;
        case 0x62:
          return 0x10;
        }
      }
      else {
        if (DAT_01216a78 < 2) {
          return local_5e2c;
        }
        fVar8 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        uVar7 = 0x742;
        uVar10 = 0x742;
        dVar9 = (double)(fVar8 * DAT_00298548);
      }
      goto LAB_0023109c;
    }
  }
  if (DAT_01216a78 < 2) {
    return local_5e2c;
  }
  fVar8 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  uVar7 = 0x73f;
  uVar10 = 0x73f;
  dVar9 = (double)(fVar8 * DAT_00298548);
LAB_0023109c:
  FUN_002340f0(dVar9,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
               "dmal/common/common_vgpu.c",uVar7,"cDeviceGetVgpuObjschedLog_v2",uVar10,local_5e2c);
  return local_5e2c;
}


// ===== 00231480 FUN_00231480 =====

uint FUN_00231480(long param_1,long param_2,int *param_3)

{
  code *pcVar1;
  undefined1 auVar2 [16];
  uint uVar3;
  long lVar4;
  float fVar5;
  int local_90;
  undefined4 local_8c;
  undefined1 local_88 [16];
  undefined8 local_78;
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined8 local_48;
  uint local_40;
  
  local_78 = 0;
  local_90 = 0;
  local_88 = (undefined1  [16])0x0;
  uVar3 = FUN_0022b610(param_2,&local_90,7);
  if (uVar3 != 0) {
    return uVar3;
  }
  if (local_90 == 0) {
    return 3;
  }
  lVar4 = *(long *)(param_2 + 0x256d8);
  auVar2[0xf] = 0;
  auVar2._0_15_ = local_68._1_15_;
  local_68 = auVar2 << 8;
  if (((lVar4 != 0) && (*(long *)(lVar4 + 0x30) != 0)) &&
     (pcVar1 = *(code **)(*(long *)(lVar4 + 0x30) + 0x148), pcVar1 != (code *)0x0)) {
    (*pcVar1)(lVar4,param_2,local_68);
    if (local_68[0] != '\0') {
      return 3;
    }
    lVar4 = *(long *)(param_2 + 0x256d8);
  }
  local_48 = 0;
  local_40 = 0;
  local_68 = (undefined1  [16])0x0;
  local_58 = (undefined1  [16])0x0;
  if (((lVar4 == 0) || (*(undefined8 **)(lVar4 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 == (code *)0x0)) {
    uVar3 = 3;
LAB_00231636:
    if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"dmal/common/common_vgpu.c",0xb8,"cValidateClientSetSchedState",
                   0xb8,uVar3);
    }
  }
  else {
    uVar3 = (*pcVar1)(lVar4,param_2,0x2080,&local_8c);
    if (uVar3 != 0) goto LAB_00231636;
    if ((*param_3 == 1) && (((param_3[1] != 0 || (param_3[3] != 0)) || (param_3[2] != 0))))
    goto switchD_0023162c_caseD_1f;
    local_68._0_4_ = 1;
    uVar3 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_8c,0x20801122,local_68,
                         0x2c,0);
    switch(uVar3) {
    case 0:
      if (param_3[1] == 2) {
        uVar3 = param_3[3];
        if (((uVar3 == 0) || (((uint)local_48 <= uVar3 && (uVar3 <= (uint)local_58._12_4_)))) &&
           ((uVar3 = param_3[2], uVar3 == 0 || ((local_40 <= uVar3 && (uVar3 <= local_48._4_4_))))))
        goto LAB_00231722;
      }
      else if (((param_3[1] != 1) || (uVar3 = param_3[2], uVar3 == 0)) ||
              (((uint)local_58._8_4_ <= uVar3 && (uVar3 <= (uint)local_58._4_4_)))) {
LAB_00231722:
        uVar3 = FUN_00133c40(*param_3,local_68);
        if (uVar3 != 0) {
          return uVar3;
        }
        if (param_3[1] == 1) {
          if (3 < DAT_01216a78) {
            fVar5 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                         &DAT_002983c2,lVar4,"dmal/common/common_vgpu.c",0x864);
            return 0;
          }
          return 0;
        }
        lVar4 = *(long *)(param_2 + 0x256d8);
        if (((lVar4 != 0) && (*(undefined8 **)(lVar4 + 0x50) != (undefined8 *)0x0)) &&
           (pcVar1 = (code *)**(undefined8 **)(lVar4 + 0x50), pcVar1 != (code *)0x0)) {
          uVar3 = (*pcVar1)(lVar4,param_2,0x2080,&local_8c);
          auVar2 = local_88;
          if (uVar3 != 0) {
            return uVar3;
          }
          local_88._4_4_ = local_68._0_4_;
          local_88._0_4_ = 1;
          local_88._8_4_ = param_3[1];
          local_88._12_4_ = auVar2._12_4_;
          if (local_88._8_4_ == 2) {
            local_78 = CONCAT44(param_3[2],param_3[3]);
          }
          else if (local_88._8_4_ == 1) {
            local_88._12_4_ = param_3[2];
          }
          uVar3 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_8c,0x20801121,
                               local_88,0x18,0);
          if (uVar3 < 0x67) {
            return (uint)*(ushort *)(&DAT_002da0e0 + (ulong)uVar3 * 2);
          }
          return 999;
        }
switchD_0023162c_caseD_56:
        return 3;
      }
    case 0x1f:
    case 0x3b:
    case 0x54:
switchD_0023162c_caseD_1f:
      uVar3 = 2;
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
    case 0x51:
      uVar3 = 0x14;
      break;
    case 0x55:
      uVar3 = 0x1b;
      break;
    case 0x56:
      goto switchD_0023162c_caseD_56;
    case 0x59:
      uVar3 = 0x11;
      break;
    case 0x62:
      uVar3 = 0x10;
    }
  }
  return uVar3;
}


// ===== 002318f0 FUN_002318f0 =====

ulong FUN_002318f0(long param_1,long param_2,undefined4 *param_3)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  ulong uVar5;
  int local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  lVar1 = *(long *)(param_1 + 0x10);
  lVar2 = *(long *)(param_2 + 0x256d8);
  if ((((lVar2 == 0) || (*(undefined8 **)(lVar2 + 0x50) == (undefined8 *)0x0)) ||
      (pcVar3 = (code *)**(undefined8 **)(lVar2 + 0x50), pcVar3 == (code *)0x0)) ||
     (iVar4 = (*pcVar3)(lVar2,param_2,0x2080,&local_1c), iVar4 != 0)) goto switchD_0023197b_caseD_1;
  uVar5 = (**(code **)(lVar1 + 0x20))(DAT_0038088c,local_1c,0x20800144,&local_20,4);
  switch(uVar5 & 0xffffffff) {
  case 0:
    if (local_20 == 2) {
      *param_3 = 0;
      return uVar5;
    }
    if (local_20 == 1) {
      *param_3 = 1;
      return uVar5;
    }
  default:
switchD_0023197b_caseD_1:
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


// ===== 00231a10 FUN_00231a10 =====

uint FUN_00231a10(long param_1,long param_2,int param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  local_3c = 0;
  uVar4 = *(undefined8 *)(param_1 + 0x10);
  lVar3 = *(long *)(param_2 + 0x256d8);
  if (((lVar3 == 0) || (*(long *)(lVar3 + 0x60) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(lVar3 + 0x60) + 0x20), pcVar1 == (code *)0x0)) {
    uVar2 = 3;
  }
  else {
    uVar2 = (*pcVar1)(lVar3,param_2,&local_34);
    if (uVar2 == 0) {
      if (local_34 != 0) {
        return 1000;
      }
      lVar3 = *(long *)(param_2 + 0x256d8);
      if (((lVar3 != 0) && (*(long *)(lVar3 + 0x160) != 0)) &&
         (pcVar1 = *(code **)(*(long *)(lVar3 + 0x160) + 0x38), pcVar1 != (code *)0x0)) {
        uVar2 = (*pcVar1)(lVar3,param_2,&local_30,&local_2c);
        if (uVar2 == 0) {
          if (local_30 != local_2c) {
            if (DAT_01216a78 < 5) {
              return 999;
            }
            fVar5 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                         "DEBUG",lVar3,"dmal/rm/rm_reset.c",0x22);
            return 999;
          }
        }
        else if (uVar2 != 3) {
          if (1 < DAT_01216a78) {
            fVar5 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n",
                         "ERROR",lVar3,"dmal/rm/rm_reset.c",0x28,uVar2);
            return uVar2;
          }
          return uVar2;
        }
      }
      if (param_3 == 0) {
        local_3c = 1;
      }
      else {
        if (param_3 != 1) {
          return 999;
        }
        local_3c = 2;
      }
      lVar3 = *(long *)(param_2 + 0x256d8);
      if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
         (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
        uVar2 = 3;
      }
      else {
        uVar2 = (*pcVar1)(lVar3,param_2,0x80,&local_38);
        if (uVar2 == 0) {
          uVar2 = FUN_0019c780(uVar4,DAT_0038088c,local_38,&DAT_00800102,&local_3c,4,0);
          if (0x66 < uVar2) {
            return 999;
          }
          return (uint)*(ushort *)(&DAT_002daa00 + (ulong)uVar2 * 2);
        }
      }
      if (DAT_01216a78 < 2) {
        return uVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0x44;
      uVar4 = 0x44;
      goto LAB_00231bb4;
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  fVar5 = fVar5 * DAT_00298548;
  uVar6 = 0x14;
  uVar4 = 0x14;
LAB_00231bb4:
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
               "dmal/rm/rm_reset.c",uVar4,"rDeviceReset",uVar6,uVar2);
  return uVar2;
}


// ===== 00231d80 FUN_00231d80 =====

int FUN_00231d80(long param_1,long param_2,int *param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  uint *puVar7;
  ulong uVar8;
  int *piVar9;
  float fVar10;
  undefined4 local_14c;
  uint local_148 [70];
  
  lVar5 = *(long *)(param_1 + 0x10);
  puVar7 = local_148;
  for (lVar6 = 0x20; lVar6 != 0; lVar6 = lVar6 + -1) {
    puVar7[0] = 0;
    puVar7[1] = 0;
    puVar7 = puVar7 + 2;
  }
  *puVar7 = 0;
  lVar6 = *(long *)(param_2 + 0x256d8);
  if (((lVar6 == 0) || (*(undefined8 **)(lVar6 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar6 + 0x50), pcVar2 == (code *)0x0)) {
switchD_00231e24_caseD_56:
    iVar3 = 3;
  }
  else {
    iVar3 = (*pcVar2)(lVar6,param_2,0x2080,&local_14c);
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(lVar5 + 0x20))(DAT_0038088c,local_14c,0x20800195,local_148,0x104);
    switch(iVar3) {
    case 0:
      if (local_148[0] < 0x21) {
        *param_3 = 0;
        piVar9 = param_3 + 1;
        uVar8 = 0;
        if (local_148[0] != 0) {
          do {
            iVar4 = FUN_00133a70(local_148[uVar8 * 2 + 1],piVar9);
            if (iVar4 != 0) {
              if (1 < DAT_01216a78) {
                uVar1 = local_148[(uVar8 & 0xffffffff) * 2 + 1];
                fVar10 = (float)FUN_002917b0(&DAT_01216a60);
                lVar5 = syscall(0xba);
                FUN_002340f0((double)(fVar10 * DAT_00298548),
                             "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","ERROR",lVar5,
                             "dmal/rm/rm_compute_policy.c",0x6a,uVar1);
              }
              *param_3 = 0;
              return iVar4;
            }
            if (*piVar9 == 0) {
              piVar9[1] = local_148[uVar8 * 2 + 2];
              *param_3 = *param_3 + 1;
            }
            uVar8 = uVar8 + 1;
            piVar9 = piVar9 + 2;
          } while ((uint)uVar8 < local_148[0]);
        }
      }
      else {
        iVar3 = 0x17;
        if (1 < DAT_01216a78) {
          fVar10 = (float)FUN_002917b0(&DAT_01216a60);
          lVar5 = syscall(0xba);
          FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u\n",
                       "ERROR",lVar5,"dmal/rm/rm_compute_policy.c",0x5b,local_148[0],0x20);
        }
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
      goto switchD_00231e24_caseD_56;
    case 0x59:
      iVar3 = 0x11;
      break;
    case 0x62:
      iVar3 = 0x10;
    }
  }
  return iVar3;
}


// ===== 00232050 FUN_00232050 =====

uint FUN_00232050(long param_1,long param_2,int *param_3)

{
  int iVar1;
  long lVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  float fVar7;
  undefined4 local_44;
  undefined8 local_40;
  
  lVar6 = *(long *)(param_1 + 0x10);
  local_40 = 0;
  uVar4 = FUN_00133a50(*param_3,&local_40);
  if (uVar4 == 0) {
    if (*param_3 == 0) {
      lVar2 = *(long *)(param_2 + 0x256d8);
      local_40 = CONCAT44(param_3[1],(undefined4)local_40);
    }
    else {
      lVar2 = *(long *)(param_2 + 0x256d8);
    }
    if (((lVar2 == 0) || (*(undefined8 **)(lVar2 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar3 = (code *)**(undefined8 **)(lVar2 + 0x50), pcVar3 == (code *)0x0)) {
      uVar4 = 3;
    }
    else {
      uVar4 = (*pcVar3)(lVar2,param_2,0x2080,&local_44);
      if (uVar4 == 0) {
        uVar4 = 999;
        uVar5 = (**(code **)(lVar6 + 0x20))(DAT_0038088c,local_44,0x20800194,&local_40,8);
        if (uVar5 < 0x67) {
          uVar4 = (uint)*(ushort *)(&DAT_002daca0 + (ulong)uVar5 * 2);
        }
      }
    }
  }
  else if (1 < DAT_01216a78) {
    iVar1 = *param_3;
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","ERROR",
                 lVar6,"dmal/rm/rm_compute_policy.c",0x14,iVar1);
  }
  return uVar4;
}


// ===== 002321c0 FUN_002321c0 =====

undefined4 FUN_002321c0(long param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  
  if (param_3 == 0) {
    if (4 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                   lVar3,"dmal/rm/rm_persistence.c",0xc0);
    }
    iVar2 = FUN_002487b0(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
                         *(undefined4 *)(param_1 + 0x18),0,param_2);
    if (DAT_01216a78 < 5) goto joined_r0x002322d1;
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    uVar4 = 0xc6;
    fVar5 = fVar5 * DAT_00298548;
  }
  else {
    if (4 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                   lVar3,"dmal/rm/rm_persistence.c",0xb5);
    }
    iVar2 = FUN_00248550(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
                         *(undefined4 *)(param_1 + 0x18),0,param_2);
    if (DAT_01216a78 < 5) goto joined_r0x002322d1;
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    uVar4 = 0xbb;
    fVar5 = fVar5 * DAT_00298548;
  }
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",lVar3,
               "dmal/rm/rm_persistence.c",uVar4,iVar2);
joined_r0x002322d1:
  if (iVar2 == 1) {
    return 6;
  }
  if ((iVar2 == 10) && ((param_2 & 1) == 0)) {
    return 0x13;
  }
  uVar1 = 0;
  if (iVar2 != 0) {
    uVar1 = 999;
  }
  return uVar1;
}


// ===== 00232410 FUN_00232410 =====

uint FUN_00232410(undefined8 param_1,long param_2,uint param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  float fVar4;
  undefined4 local_30;
  uint local_2c [3];
  
  lVar3 = *(long *)(param_2 + 0x256d8);
  local_2c[0] = 0;
  if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x50), pcVar1 == (code *)0x0)) {
    uVar2 = 3;
  }
  else {
    uVar2 = (*pcVar1)(lVar3,param_2,0x80,&local_30);
    if (uVar2 == 0) {
      local_2c[0] = param_3 ^ 1;
      uVar2 = FUN_0019c780(param_1,DAT_0038088c,local_30,&DAT_00800287,local_2c,4,0);
      if (0x66 < uVar2) {
        return 999;
      }
      return (uint)*(ushort *)(&DAT_002daf40 + (ulong)uVar2 * 2);
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar2;
  }
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar3,"dmal/rm/rm_persistence.c",0x99,"rDeviceSetLegacyPersistenceMode",0x99,
               uVar2);
  return uVar2;
}


// ===== 00232580 FUN_00232580 =====

int FUN_00232580(long param_1,long param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  undefined1 local_a8 [16];
  int local_98;
  undefined1 local_88 [16];
  undefined4 local_78;
  uint local_74;
  uint local_70;
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  if (param_3 != 0) {
    if (param_3 != 1) {
      return 2;
    }
    local_78 = *(undefined4 *)(param_2 + 8);
    local_74 = (uint)*(ushort *)(param_2 + 0xc);
    local_70 = (uint)*(ushort *)(param_2 + 0xe);
    iVar3 = FUN_002321c0(local_88,1,param_4);
    if ((iVar3 == 0) && (param_5 != (undefined4 *)0x0)) {
      *param_5 = 1;
      return 0;
    }
    if (iVar3 != 6) {
      return iVar3;
    }
    if (DAT_0121489c != 0) {
      return 6;
    }
    iVar3 = FUN_00232410(uVar1,param_2,1);
    if (iVar3 != 0) {
      return iVar3;
    }
    if (param_5 == (undefined4 *)0x0) {
      return 0;
    }
    *param_5 = 0;
    return 0;
  }
  local_78 = *(undefined4 *)(param_2 + 8);
  local_a8._0_12_ = ZEXT812(0);
  local_74 = (uint)*(ushort *)(param_2 + 0xc);
  local_70 = (uint)*(ushort *)(param_2 + 0xe);
  if (DAT_012164a0 == 0) {
LAB_00232760:
    lVar4 = *(long *)(param_2 + 0x256d8);
    if (((lVar4 == 0) || (*(long *)(lVar4 + 0x60) == 0)) ||
       (pcVar2 = *(code **)(*(long *)(lVar4 + 0x60) + 0x28), pcVar2 == (code *)0x0)) {
      iVar3 = 3;
    }
    else {
      iVar3 = (*pcVar2)(lVar4,param_2,local_a8);
      if (iVar3 == 0) {
        if (DAT_0121489c == 0) {
          FUN_00232410(uVar1,param_2,0);
        }
        iVar3 = FUN_002321c0(local_88,0,param_4);
        if (iVar3 != 6) {
          return iVar3;
        }
        return 0;
      }
    }
    if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"dmal/rm/rm_persistence.c",0x13d,"rDeviceDisablePersistenceMode",
                   0x13d,iVar3);
    }
  }
  else {
    if ((*(long *)(DAT_012164a0 + 0x108) == 0) ||
       (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x108) + 8), pcVar2 == (code *)0x0)) {
      local_a8._4_12_ = SUB1612((undefined1  [16])0x0,4);
      local_a8._0_4_ = 0x1000014;
LAB_0023272f:
      local_98 = 0;
      if ((((*(long *)(DAT_012164a0 + 0x108) == 0) ||
           (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x108) + 0x50), pcVar2 == (code *)0x0)) ||
          (iVar3 = (*pcVar2)(DAT_012164a0,local_a8), iVar3 != 0)) || (local_98 != 1))
      goto LAB_00232760;
    }
    else {
      iVar3 = (*pcVar2)(DAT_012164a0,local_a8);
      if ((iVar3 != 0) || (local_a8._4_4_ != 1)) {
        local_98 = 0;
        local_a8._4_12_ = SUB1612((undefined1  [16])0x0,4);
        local_a8._0_4_ = 0x1000014;
        if (DAT_012164a0 == 0) goto LAB_00232760;
        goto LAB_0023272f;
      }
    }
    if (4 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                   lVar4,"dmal/rm/rm_persistence.c",0x138);
    }
    iVar3 = 3;
  }
  return iVar3;
}


// ===== 00232910 FUN_00232910 =====

undefined4 FUN_00232910(undefined8 param_1,long param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_002488e0(*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),
                       *(undefined4 *)(param_2 + 0x18),0,param_3 == 1);
  if (iVar1 == 1) {
    return 6;
  }
  if ((iVar1 == 10) && (param_3 == 0)) {
    return 0x13;
  }
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 999;
  }
  return uVar2;
}


// ===== 00232980 FUN_00232980 =====

int FUN_00232980(long param_1,long param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  float fVar6;
  int local_40;
  int local_3c [3];
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  local_40 = 0;
  if (param_4 != (undefined1 *)0x0) {
    *param_4 = 0;
  }
  if (4 < DAT_01216a78) {
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                 lVar5,"dmal/rm/rm_persistence.c",0x3f);
  }
  iVar3 = FUN_00248680(*(undefined4 *)(param_2 + 8),*(undefined2 *)(param_2 + 0xc),
                       *(undefined2 *)(param_2 + 0xe),0,local_3c);
  iVar4 = local_3c[0];
  if (4 < DAT_01216a78) {
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u\n","DEBUG"
                 ,lVar5,"dmal/rm/rm_persistence.c",0x44,iVar3,iVar4);
  }
  if (iVar3 == 0) {
    iVar4 = 0;
    if (local_3c[0] != 0) {
      if (local_3c[0] == 1) {
        if (param_4 != (undefined1 *)0x0) {
          *param_4 = 1;
        }
        *param_3 = 1;
        return 0;
      }
      return 999;
    }
    if (DAT_0121489c != 0) goto LAB_00232c07;
  }
  else if (DAT_0121489c != 0) {
    return 999;
  }
  lVar5 = *(long *)(param_2 + 0x256d8);
  if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar2 = (code *)**(undefined8 **)(lVar5 + 0x50), pcVar2 == (code *)0x0)) {
    iVar4 = 3;
  }
  else {
    iVar4 = (*pcVar2)(lVar5,param_2,0x80,local_3c);
    if (iVar4 == 0) {
      iVar4 = FUN_0019c780(uVar1,DAT_0038088c,local_3c[0],&DAT_00800288,&local_40,4,0);
      iVar3 = local_40;
      switch(iVar4) {
      case 0:
        goto switchD_00232c63_caseD_0;
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
  fVar6 = (float)FUN_002917b0(&DAT_01216a60);
  lVar5 = syscall(0xba);
  FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar5,"dmal/rm/rm_persistence.c",0x77,"rDeviceGetPersistenceMode",0x77,iVar4)
  ;
  return iVar4;
switchD_00232c63_caseD_0:
  if (local_40 == 0) {
    *param_3 = 1;
    return 0;
  }
  if (local_40 != 1) {
    if (DAT_01216a78 < 2) {
      return 999;
    }
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","ERROR",
                 lVar5,"dmal/rm/rm_persistence.c",0x88,iVar3);
    return 999;
  }
LAB_00232c07:
  *param_3 = 0;
  return iVar4;
}


// ===== 00232d80 FUN_00232d80 =====

int FUN_00232d80(long param_1,long param_2,uint *param_3,void *param_4)

{
  uint uVar1;
  long lVar2;
  uint *puVar3;
  bool bVar4;
  int iVar5;
  undefined4 *puVar6;
  long lVar7;
  long lVar8;
  short sVar9;
  short sVar10;
  uint uVar11;
  short *psVar12;
  uint uVar13;
  ulong uVar14;
  uint uVar15;
  uint uVar16;
  ulong uVar17;
  float fVar18;
  int local_50;
  undefined8 local_40 [2];
  
  lVar2 = *(long *)(param_2 + 0x70560);
  local_40[0] = 0;
  if (lVar2 == 0) {
switchD_00232f9c_caseD_55:
    return 0x1b;
  }
  if (param_4 == (void *)0x0) {
switchD_00232f9c_caseD_1f:
    return 2;
  }
  uVar1 = *param_3;
  memset(param_4,0,(ulong)uVar1 << 5);
  puVar3 = *(uint **)(lVar2 + 0x18);
  lVar8 = *(long *)(lVar2 + 0x28);
  if ((puVar3 != (uint *)0x0) && (lVar8 != 0)) {
    uVar11 = *puVar3;
    uVar14 = (ulong)uVar11;
    if (uVar11 == puVar3[1]) {
      *param_3 = 0;
      return 0;
    }
    uVar13 = *(uint *)(lVar2 + 8) >> 5;
    uVar11 = ((puVar3[1] + uVar13) - uVar11) % uVar13;
    if (uVar1 == 0) {
      *param_3 = uVar11;
      return 7;
    }
    uVar16 = 0;
    local_50 = 0;
    if (uVar11 != 0) {
      uVar15 = 0;
      uVar17 = 0;
      local_50 = 0;
      bVar4 = true;
      sVar9 = 0;
      do {
        psVar12 = (short *)(uVar14 * 0x20 + lVar8);
        sVar10 = sVar9;
        if (*psVar12 == 0x86) {
          sVar10 = psVar12[5];
          if (((!bVar4) && ((sVar10 - sVar9 & 0xfffeU) != 0)) && (local_50 = 999, 1 < DAT_01216a78))
          {
            fVar18 = (float)FUN_002917b0(&DAT_01216a60);
            lVar7 = syscall(0xba);
            FUN_002340f0((double)(fVar18 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %d %d %d %x\n","ERROR",lVar7,
                         "dmal/rm/rm_context_buffer.c",0x1b4,sVar10 - sVar9,sVar9,sVar10,1,uVar14);
            sVar10 = psVar12[5];
          }
          if ((char)psVar12[4] == '\x06') {
            puVar6 = (undefined4 *)(uVar17 * 0x20 + (long)param_4);
            *puVar6 = 0;
LAB_00232ec9:
            uVar17 = (ulong)((int)uVar17 + 1);
            puVar6[1] = *(undefined4 *)(psVar12 + 6);
            puVar6[2] = *(undefined4 *)(psVar12 + 8);
            puVar6[3] = (uint)*(byte *)(psVar12 + 0xb);
            puVar6[4] = (uint)*(byte *)((long)psVar12 + 0x17);
            *(undefined8 *)(puVar6 + 6) = *(undefined8 *)(psVar12 + 0xc);
          }
          else if ((char)psVar12[4] == '\a') {
            puVar6 = (undefined4 *)(uVar17 * 0x20 + (long)param_4);
            *puVar6 = 1;
            goto LAB_00232ec9;
          }
          bVar4 = false;
        }
        uVar15 = uVar15 + 1;
        uVar14 = (ulong)((int)uVar14 + 1) % (ulong)uVar13;
        uVar16 = (uint)uVar17;
      } while ((uVar16 < uVar1) && (sVar9 = sVar10, uVar15 < uVar11));
      if (local_50 != 0) {
        if (local_50 != 999) {
          return local_50;
        }
        if (1 < DAT_01216a78) {
          fVar18 = (float)FUN_002917b0(&DAT_01216a60);
          lVar8 = syscall(0xba);
          FUN_002340f0((double)(fVar18 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       "ERROR",lVar8,"dmal/rm/rm_context_buffer.c",0x21e);
        }
      }
      if (*param_3 < uVar11) {
        local_50 = 7;
      }
      if (*puVar3 != (uint)uVar14) {
        local_40[0] = CONCAT44(local_40[0]._4_4_,(uint)uVar14);
        iVar5 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,*(undefined4 *)(lVar2 + 4)
                             ,0x90cd0102,local_40,8,0);
        switch(iVar5) {
        case 0:
          break;
        default:
          goto switchD_00232f9c_caseD_1;
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
          goto switchD_00232f9c_caseD_1f;
        case 0x51:
          return 0x14;
        case 0x55:
          goto switchD_00232f9c_caseD_55;
        case 0x56:
          return 3;
        case 0x59:
          return 0x11;
        case 0x62:
          return 0x10;
        }
      }
    }
    *param_3 = uVar16;
    return local_50;
  }
switchD_00232f9c_caseD_1:
  return 999;
}


// ===== 002331c0 FUN_002331c0 =====

undefined2 FUN_002331c0(long param_1,int *param_2)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  
  iVar1 = *param_2;
  if (iVar1 == 0) {
    return 0;
  }
  if (*(long *)(param_2 + 2) != 0) {
    uVar3 = (**(code **)(param_1 + 0x68))(DAT_0038088c,DAT_0038088c,iVar1,*(long *)(param_2 + 2),0);
    param_2[2] = 0;
    param_2[3] = 0;
    (**(code **)(param_1 + 0x28))(DAT_0038088c,DAT_0038088c,*param_2);
    *param_2 = 0;
    uVar2 = 999;
    if (uVar3 < 0x67) {
      uVar2 = *(undefined2 *)(&DAT_002dba80 + (ulong)uVar3 * 2);
    }
    return uVar2;
  }
  (**(code **)(param_1 + 0x28))(DAT_0038088c,DAT_0038088c,iVar1);
  *param_2 = 0;
  return 0;
}


// ===== 00233270 FUN_00233270 =====

void FUN_00233270(long param_1,long param_2,void *param_3)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  if (param_3 != (void *)0x0) {
    iVar1 = FUN_002331c0(param_1,(long)param_3 + 0x20);
    if ((iVar1 != 0) && (1 < DAT_01216a78)) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n","ERROR",
                   lVar2,"dmal/rm/rm_context_buffer.c",0x14b,iVar1);
    }
    *(undefined4 *)((long)param_3 + 8) = 0;
    iVar1 = FUN_002331c0(param_1,(long)param_3 + 0x10);
    if ((iVar1 == 0) || (DAT_01216a78 < 2)) {
      iVar1 = *(int *)((long)param_3 + 4);
    }
    else {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n","ERROR",
                   lVar2,"dmal/rm/rm_context_buffer.c",0x153,iVar1);
      iVar1 = *(int *)((long)param_3 + 4);
    }
    if (iVar1 != 0) {
      (**(code **)(param_1 + 0x28))(DAT_0038088c,DAT_0038088c);
    }
    free(param_3);
    *(undefined8 *)(param_2 + 0x70560) = 0;
    return;
  }
  return;
}


// ===== 002333f0 FUN_002333f0 =====

ulong FUN_002333f0(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_30 [2];
  
  uVar2 = 0;
  lVar1 = *(long *)(param_2 + 0x70560);
  local_30[0] = 0;
  if (lVar1 != 0) {
    uVar2 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,*(undefined4 *)(lVar1 + 4),
                         0x90cd0101,local_30,8,0);
    switch(uVar2 & 0xffffffff) {
    case 0:
      FUN_00233270(*(undefined8 *)(param_1 + 0x10),param_2,lVar1);
      uVar2 = uVar2 & 0xffffffff;
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
  return uVar2;
}


// ===== 00233500 FUN_00233500 =====

void FUN_00233500(long param_1,undefined4 *param_2,long param_3,ulong param_4)

{
  code *pcVar1;
  
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x20) != 0)) &&
     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0x80), pcVar1 != (code *)0x0)) {
    (*pcVar1)();
  }
  *(ulong *)(param_3 + 0x40) = param_4 & 0xffffffff;
  (**(code **)(param_1 + 0x10))(0,DAT_0038088c,DAT_0038088c,*param_2,0x90ce,param_3,0);
  return;
}


// ===== 00233580 FUN_00233580 =====

uint FUN_00233580(long param_1,long param_2,uint *param_3)

{
  code *pcVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined3 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  uint uVar13;
  byte bVar14;
  float fVar15;
  uint local_13c;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined8 local_118;
  undefined8 local_110;
  undefined1 local_108 [16];
  undefined1 local_f8 [16];
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  undefined8 local_c8;
  undefined1 local_b8 [8];
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined4 local_9c;
  
  bVar14 = 0;
  if (*(long *)(param_2 + 0x70560) != 0) {
    return 0;
  }
  local_c8 = 0;
  *(uint *)(param_2 + 0x70554) = *param_3;
  local_108 = (undefined1  [16])0x0;
  *(uint *)(param_2 + 0x70558) = param_3[1];
  lVar8 = *(long *)(param_1 + 0x10);
  lVar9 = *(long *)(param_2 + 0x256d8);
  local_f8 = (undefined1  [16])0x0;
  local_e8 = (undefined1  [16])0x0;
  local_d8 = (undefined1  [16])0x0;
  if (((lVar9 == 0) || (*(undefined8 **)(lVar9 + 0x50) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(lVar9 + 0x50), pcVar1 == (code *)0x0)) {
    uVar5 = 3;
  }
  else {
    uVar5 = (*pcVar1)(lVar9,param_2,0x2080,&local_124);
    if (uVar5 == 0) {
      puVar7 = malloc(0x30);
      if (puVar7 == (undefined4 *)0x0) {
        uVar5 = 0x14;
        goto LAB_00233793;
      }
      uVar13 = *param_3;
      *puVar7 = local_124;
      if (uVar13 == 0) {
        local_13c = 0x80000;
        uVar13 = 0x4000;
      }
      else {
        local_13c = uVar13 << 5;
      }
      puVar11 = (undefined8 *)local_b8;
      for (lVar9 = 0x10; lVar9 != 0; lVar9 = lVar9 + -1) {
        *puVar11 = 0;
        puVar11 = puVar11 + (ulong)bVar14 * -2 + 1;
      }
      local_118 = 0;
      local_110 = 0;
      local_9c = 0x400000;
      uVar5 = FUN_00233500(*(undefined8 *)(param_1 + 0x10),&local_120,local_b8,0x20);
      switch(uVar5) {
      case 0:
        uVar10 = (ulong)local_13c;
        uVar5 = FUN_00233500(*(undefined8 *)(param_1 + 0x10),&local_11c,local_b8);
        switch(uVar5) {
        case 0:
          uVar5 = (**(code **)(*(long *)(param_1 + 0x10) + 0x58))
                            (DAT_0038088c,DAT_0038088c,local_120,0,0x20,&local_118,1,uVar10);
          switch(uVar5) {
          case 0:
            uVar5 = (**(code **)(*(long *)(param_1 + 0x10) + 0x58))
                              (DAT_0038088c,DAT_0038088c,local_11c,0,local_13c,&local_110,1);
            auVar3 = local_d8;
            switch(uVar5) {
            case 0:
              local_f8._4_4_ = uVar13;
              local_f8._0_4_ = 0x20;
              puVar7[2] = local_13c;
              puVar7[4] = local_120;
              *(undefined8 *)(puVar7 + 6) = local_118;
              *(undefined8 *)(puVar7 + 10) = local_110;
              puVar7[8] = local_11c;
              local_c8 = CONCAT44(local_c8._4_4_,local_11c);
              local_d8._12_4_ = local_120;
              local_e8._4_4_ = uVar13 >> 1;
              local_d8._0_4_ = auVar3._0_4_;
              local_d8._4_4_ = local_124;
              if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x20) != 0)) &&
                 (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0x80), pcVar1 != (code *)0x0)
                 ) {
                (*pcVar1)(DAT_012164a0,local_b8);
              }
              iVar6 = (**(code **)(lVar8 + 0x10))
                                (0,DAT_0038088c,DAT_0038088c,local_b8._0_4_,0x90cd,local_108,0x48);
              if (iVar6 != 0) {
                if (DAT_01216a78 < 2) {
                  uVar12 = *(undefined8 *)(param_1 + 0x10);
                }
                else {
                  fVar15 = (float)FUN_002917b0(&DAT_01216a60);
                  lVar8 = syscall(0xba);
                  FUN_002340f0((double)(fVar15 * DAT_00298548),
                               "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n","ERROR",lVar8,
                               "dmal/rm/rm_context_buffer.c",0x9f,iVar6);
                  uVar12 = *(undefined8 *)(param_1 + 0x10);
                }
                uVar5 = 0x14;
                FUN_00233270(uVar12,param_2,puVar7);
                goto LAB_00233793;
              }
              iVar6 = mprotect(*(void **)(puVar7 + 6),0x20,1);
              if ((iVar6 == -1) ||
                 (iVar6 = mprotect(*(void **)(puVar7 + 10),(ulong)(uint)puVar7[2],1), iVar6 == -1))
              {
                if (DAT_01216a78 < 2) {
                  uVar12 = *(undefined8 *)(param_1 + 0x10);
                }
                else {
                  fVar15 = (float)FUN_002917b0(&DAT_01216a60);
                  lVar8 = syscall(0xba);
                  FUN_002340f0((double)(fVar15 * DAT_00298548),
                               "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar8,
                               "dmal/rm/rm_context_buffer.c",0xab);
                  uVar12 = *(undefined8 *)(param_1 + 0x10);
                }
                uVar5 = 999;
                FUN_00233270(uVar12,param_2,puVar7);
                goto LAB_00233793;
              }
              *(undefined4 **)(param_2 + 0x70560) = puVar7;
              puVar7[1] = local_b8._0_4_;
              stack0xffffffffffffff4c = SUB1612((undefined1  [16])0x0,4);
              auVar3 = _local_b8;
              local_a8 = 0;
              if (param_3[1] == 0) {
LAB_00233c57:
                local_b8 = auVar3._0_8_;
                uStack_b0 = 1;
                uVar13 = 999;
                uVar5 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,*puVar7,0x20801231
                                     ,local_b8,0x14,0);
                auVar3 = _local_b8;
                if ((0x66 < uVar5) ||
                   (uVar13 = (uint)*(ushort *)(&DAT_002dba80 + (ulong)uVar5 * 2),
                   *(ushort *)(&DAT_002dba80 + (ulong)uVar5 * 2) != 0)) goto LAB_00233c22;
                uVar4 = local_b8._0_3_;
                auVar2._12_4_ = 0;
                auVar2._0_12_ = stack0xffffffffffffff4c;
                _local_b8 = auVar2 << 0x20;
                uVar13 = 6;
                local_b8._0_3_ = uVar4 & 0xff;
                if (*(long *)(param_2 + 0x70560) != 0) {
                  local_b8[0] = 1;
                  auVar2 = _local_b8;
                  uVar13 = 999;
                  _uStack_b0 = auVar3._8_8_;
                  local_b8._0_4_ = auVar2._0_4_;
                  local_b8._4_4_ = 1;
                  uVar5 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,
                                       *(undefined4 *)(*(long *)(param_2 + 0x70560) + 4),0x90cd0101,
                                       local_b8,8);
                  if ((uVar5 < 0x67) &&
                     (uVar13 = (uint)*(ushort *)(&DAT_002dba80 + (ulong)uVar5 * 2),
                     *(ushort *)(&DAT_002dba80 + (ulong)uVar5 * 2) == 0)) {
                    return 0;
                  }
                }
                if (DAT_01216a78 < 2) goto LAB_00233c32;
                fVar15 = (float)FUN_002917b0(&DAT_01216a60);
                lVar8 = syscall(0xba);
                uVar12 = 0x118;
                fVar15 = fVar15 * DAT_00298548;
              }
              else {
                if (param_3[1] == 1) {
                  local_a8 = 1;
                  goto LAB_00233c57;
                }
                uVar13 = 2;
LAB_00233c22:
                if (DAT_01216a78 < 2) goto LAB_00233c32;
                fVar15 = (float)FUN_002917b0(&DAT_01216a60);
                lVar8 = syscall(0xba);
                uVar12 = 0x111;
                fVar15 = fVar15 * DAT_00298548;
              }
              FUN_002340f0((double)fVar15,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n","ERROR",lVar8,
                           "dmal/rm/rm_context_buffer.c",uVar12,uVar13);
LAB_00233c32:
              FUN_00233270(*(undefined8 *)(param_1 + 0x10),param_2,
                           *(undefined8 *)(param_2 + 0x70560));
              return uVar13;
            default:
              goto switchD_0023370d_caseD_1;
            case 3:
            case 0x66:
              goto switchD_0023370d_caseD_3;
            case 0xf:
              break;
            case 0x17:
            case 99:
              goto switchD_0023370d_caseD_17;
            case 0x1a:
              goto switchD_0023370d_caseD_1a;
            case 0x1b:
              goto switchD_0023370d_caseD_1b;
            case 0x1f:
            case 0x3b:
            case 0x54:
              goto switchD_0023370d_caseD_1f;
            case 0x51:
              goto switchD_0023370d_caseD_51;
            case 0x55:
              goto switchD_0023370d_caseD_55;
            case 0x56:
              goto switchD_0023370d_caseD_56;
            case 0x59:
              goto switchD_0023370d_caseD_59;
            case 0x62:
              goto switchD_0023370d_caseD_62;
            }
          default:
            goto switchD_0023370d_caseD_1;
          case 3:
          case 0x66:
            goto switchD_0023370d_caseD_3;
          case 0xf:
            break;
          case 0x17:
          case 99:
            goto switchD_0023370d_caseD_17;
          case 0x1a:
            goto switchD_0023370d_caseD_1a;
          case 0x1b:
            goto switchD_0023370d_caseD_1b;
          case 0x1f:
          case 0x3b:
          case 0x54:
            goto switchD_0023370d_caseD_1f;
          case 0x51:
            goto switchD_0023370d_caseD_51;
          case 0x55:
            goto switchD_0023370d_caseD_55;
          case 0x56:
            goto switchD_0023370d_caseD_56;
          case 0x59:
            goto switchD_0023370d_caseD_59;
          case 0x62:
            goto switchD_0023370d_caseD_62;
          }
        default:
          goto switchD_0023370d_caseD_1;
        case 3:
        case 0x66:
          goto switchD_0023370d_caseD_3;
        case 0xf:
          break;
        case 0x17:
        case 99:
          goto switchD_0023370d_caseD_17;
        case 0x1a:
          goto switchD_0023370d_caseD_1a;
        case 0x1b:
          goto switchD_0023370d_caseD_1b;
        case 0x1f:
        case 0x3b:
        case 0x54:
          goto switchD_0023370d_caseD_1f;
        case 0x51:
          goto switchD_0023370d_caseD_51;
        case 0x55:
          goto switchD_0023370d_caseD_55;
        case 0x56:
          goto switchD_0023370d_caseD_56;
        case 0x59:
          goto switchD_0023370d_caseD_59;
        case 0x62:
          goto switchD_0023370d_caseD_62;
        }
      default:
switchD_0023370d_caseD_1:
        uVar5 = 999;
        break;
      case 3:
      case 0x66:
switchD_0023370d_caseD_3:
        uVar5 = 10;
        break;
      case 0xf:
        break;
      case 0x17:
      case 99:
switchD_0023370d_caseD_17:
        uVar5 = 0x13;
        break;
      case 0x1a:
switchD_0023370d_caseD_1a:
        uVar5 = 0x17;
        break;
      case 0x1b:
switchD_0023370d_caseD_1b:
        uVar5 = 4;
        break;
      case 0x1f:
      case 0x3b:
      case 0x54:
switchD_0023370d_caseD_1f:
        uVar5 = 2;
        break;
      case 0x51:
switchD_0023370d_caseD_51:
        uVar5 = 0x14;
        break;
      case 0x55:
switchD_0023370d_caseD_55:
        uVar5 = 0x1b;
        break;
      case 0x56:
switchD_0023370d_caseD_56:
        uVar5 = 3;
        break;
      case 0x59:
switchD_0023370d_caseD_59:
        uVar5 = 0x11;
        break;
      case 0x62:
switchD_0023370d_caseD_62:
        uVar5 = 0x10;
      }
      if (1 < DAT_01216a78) {
        fVar15 = (float)FUN_002917b0(&DAT_01216a60);
        lVar8 = syscall(0xba);
        FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n",
                     "ERROR",lVar8,"dmal/rm/rm_context_buffer.c",0x8d,uVar5);
      }
      FUN_00233270(*(undefined8 *)(param_1 + 0x10),param_2,puVar7);
      goto LAB_00233793;
    }
  }
  if (DAT_01216a78 < 2) {
    return uVar5;
  }
  fVar15 = (float)FUN_002917b0(&DAT_01216a60);
  lVar8 = syscall(0xba);
  FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
               "ERROR",lVar8,"dmal/rm/rm_context_buffer.c",0x7a,"rDeviceContextBufferAllocBuffer",
               0x7a,uVar5);
LAB_00233793:
  if (1 < DAT_01216a78) {
    fVar15 = (float)FUN_002917b0(&DAT_01216a60);
    lVar8 = syscall(0xba);
    FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar8,"dmal/rm/rm_context_buffer.c",0x10c,"rDeviceContextBufferEnableTrace"
                 ,0x10c,uVar5);
  }
  return uVar5;
}


// ===== 00233f20 FUN_00233f20 =====

undefined8 FUN_00233f20(char *param_1,__gnuc_va_list param_2)

{
  uint uVar1;
  int iVar2;
  size_t __n;
  char local_828 [2047];
  undefined1 local_29;
  
  uVar1 = vsnprintf(local_828,0x800,param_1,param_2);
  __n = (size_t)(int)uVar1;
  if (0x7ff < uVar1) {
    local_29 = 10;
    __n = 0x800;
  }
  do {
    iVar2 = FUN_00291820(&DAT_01216a44,1,0);
  } while (iVar2 != 0);
  FUN_002347d0(local_828,__n);
  fwrite(local_828,1,__n,DAT_01216a70);
  FUN_00291830(&DAT_01216a44,0);
  fflush(DAT_01216a70);
  return 0;
}


// ===== 00233fd0 FUN_00233fd0 =====

void FUN_00233fd0(void)

{
  int iVar1;
  
  do {
    iVar1 = FUN_00291820(&DAT_01216a50,1,0);
  } while (iVar1 != 0);
  DAT_01216a54 = DAT_01216a54 + -1;
  if (DAT_01216a54 == 0) {
    if ((DAT_01216a70 != (FILE *)0x0) && (DAT_01216a70 != *(FILE **)PTR_stderr_0032efe0)) {
      FUN_00293480();
      fclose(DAT_01216a70);
    }
    DAT_01216a70 = (FILE *)0x0;
  }
  FUN_00291830(&DAT_01216a50,0);
  return;
}


// ===== 00234050 FUN_00234050 =====

bool FUN_00234050(int param_1,char *param_2,uint param_3)

{
  bool bVar1;
  char *__s;
  size_t sVar2;
  
  __s = strerror(param_1);
  sVar2 = strlen(__s);
  bVar1 = param_3 < (int)sVar2 + 1U;
  if (!bVar1) {
    strncpy(param_2,__s,(long)(int)param_3);
  }
  return bVar1;
}


// ===== 002340a0 FUN_002340a0 =====

undefined8 FUN_002340a0(void)

{
  undefined8 uVar1;
  
  while( true ) {
    if (DAT_01216a54 == 0) {
      return 1;
    }
    if (DAT_01216a78 == 0) break;
    if (DAT_01216a48 == 0) {
      if (DAT_01216a70 == 0) {
        return 1;
      }
      uVar1 = FUN_00233f20();
      return uVar1;
    }
  }
  return 0;
}


// ===== 002340f0 FUN_002340f0 =====

void FUN_002340f0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                 undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
                 undefined8 param_13,undefined8 param_14)

{
  char in_AL;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined1 *local_c8;
  undefined1 *local_c0;
  undefined1 local_b8 [8];
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 local_38;
  undefined8 local_28;
  undefined8 local_18;
  
  if (in_AL != '\0') {
    local_88 = param_1;
    local_78 = param_2;
    local_68 = param_3;
    local_58 = param_4;
    local_48 = param_5;
    local_38 = param_6;
    local_28 = param_7;
    local_18 = param_8;
  }
  if (DAT_01216a78 == 0) {
    return;
  }
  local_c8 = &stack0x00000008;
  local_d0 = 8;
  local_c0 = local_b8;
  local_cc = 0x30;
  local_b0 = param_10;
  local_a8 = param_11;
  local_a0 = param_12;
  local_98 = param_13;
  local_90 = param_14;
  FUN_002340a0(param_9,&local_d0);
  return;
}


// ===== 002341a0 FUN_002341a0 =====

void FUN_002341a0(long param_1,long param_2,long param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  __off_t _Var5;
  stat local_4c8;
  char local_438;
  char cStack_437;
  undefined2 uStack_436;
  char cStack_434;
  undefined1 uStack_433;
  undefined2 uStack_432;
  char local_430;
  
  if ((param_2 == 0 || param_3 == 0) || (param_1 == 0)) {
    fwrite("loggingInit null parameter\n",1,0x1b,*(FILE **)PTR_stderr_0032efe0);
    return;
  }
  do {
    iVar2 = FUN_00291820(&DAT_01216a50,1,0);
  } while (iVar2 != 0);
  DAT_01216a54 = DAT_01216a54 + 1;
  if (1 < DAT_01216a54) {
    FUN_00291830(&DAT_01216a50,0);
    return;
  }
  DAT_01216a78 = 0;
  iVar2 = FUN_00292de0(param_1,&local_438,0x10);
  if (iVar2 == 0) {
    if ((CONCAT26(uStack_432,
                  CONCAT15(uStack_433,
                           CONCAT14(cStack_434,CONCAT22(uStack_436,CONCAT11(cStack_437,local_438))))
                 ) == 0x44454c4241534944) && (local_430 == '\0')) {
      DAT_01216a78 = 0;
    }
    else if ((CONCAT26(uStack_432,
                       CONCAT15(uStack_433,
                                CONCAT14(cStack_434,
                                         CONCAT22(uStack_436,CONCAT11(cStack_437,local_438))))) ==
              0x4c41434954495243) && (local_430 == '\0')) {
      DAT_01216a78 = 1;
    }
    else if ((CONCAT22(uStack_436,CONCAT11(cStack_437,local_438)) == 0x4f525245) &&
            (CONCAT11(uStack_433,cStack_434) == 0x52)) {
      DAT_01216a78 = 2;
    }
    else if (CONCAT26(uStack_432,
                      CONCAT15(uStack_433,
                               CONCAT14(cStack_434,
                                        CONCAT22(uStack_436,CONCAT11(cStack_437,local_438))))) ==
             0x474e494e524157) {
      DAT_01216a78 = 3;
    }
    else if ((CONCAT22(uStack_436,CONCAT11(cStack_437,local_438)) == 0x4f464e49) &&
            (cStack_434 == '\0')) {
      DAT_01216a78 = 4;
    }
    else if ((CONCAT22(uStack_436,CONCAT11(cStack_437,local_438)) == 0x55424544) &&
            (CONCAT11(uStack_433,cStack_434) == 0x47)) {
      DAT_01216a78 = 5;
    }
  }
  iVar2 = FUN_00292de0(param_2,&local_438,0x10);
  if (iVar2 == 0) {
    if (local_438 == '0') {
      if (cStack_437 != '\0') goto LAB_00234535;
      goto LAB_00234301;
    }
    if ((local_438 != '1') || (cStack_437 != '\0')) {
LAB_00234535:
      fprintf(*(FILE **)PTR_stderr_0032efe0,"WARNING: Wrong value of %s\n",param_2);
      goto LAB_00234301;
    }
    bVar1 = true;
    iVar2 = FUN_00292de0(param_3,&local_438,0x400);
    if (iVar2 == 0) {
      DAT_01216a70 = fopen(&local_438,"ab");
      if (DAT_01216a70 == (FILE *)0x0) goto LAB_0023468a;
      if (DAT_01216a58 != 0) goto LAB_00234427;
      iVar2 = __xstat(1,&local_438,&local_4c8);
      if (iVar2 == 0) goto LAB_002345d8;
      piVar3 = __errno_location();
      _Var5 = 0;
      pcVar4 = strerror(*piVar3);
      fprintf(*(FILE **)PTR_stderr_0032efe0,"WARNING: Failed to stat log file errno = %s\n",pcVar4);
      fclose(DAT_01216a70);
      DAT_01216a70 = (FILE *)0x0;
      goto LAB_0023433b;
    }
LAB_0023431c:
    DAT_01216a70 = (FILE *)0x0;
    if (DAT_01216a48 == 0) {
      if (DAT_01216a78 != 0) {
        fprintf(*(FILE **)PTR_stderr_0032efe0,"WARNING: You must also provide env %s=\n",param_3);
      }
      if (bVar1) {
        fprintf(*(FILE **)PTR_stderr_0032efe0,"WARNING: %s has no effect with no %s\n",param_2,
                param_3);
      }
    }
    _Var5 = 0;
  }
  else {
LAB_00234301:
    bVar1 = false;
    iVar2 = FUN_00292de0(param_3,&local_438,0x400);
    if (iVar2 != 0) goto LAB_0023431c;
    pcVar4 = "ab";
    if (DAT_01216a58 == 0) {
      pcVar4 = "wb";
    }
    DAT_01216a70 = fopen(&local_438,pcVar4);
    if (DAT_01216a70 == (FILE *)0x0) {
LAB_0023468a:
      piVar3 = __errno_location();
      pcVar4 = strerror(*piVar3);
      fprintf(*(FILE **)PTR_stderr_0032efe0,
              "WARNING: Failed to open log file %s=\'%s\'. errno = %s\n",param_3,&local_438,pcVar4);
      local_4c8.st_size = 0;
LAB_002345d8:
      _Var5 = local_4c8.st_size;
      if (DAT_01216a70 != (FILE *)0x0) goto LAB_0023442a;
    }
    else {
LAB_00234427:
      _Var5 = 0;
LAB_0023442a:
      iVar2 = thunk_FUN_00293460(DAT_01216a70,10);
      if (iVar2 != 0) {
        fwrite("WARNING: Failed to acquire log file lock. File is in use by a different instance\n",
               1,0x51,*(FILE **)PTR_stderr_0032efe0);
        fclose(DAT_01216a70);
        DAT_01216a70 = (FILE *)0x0;
      }
    }
  }
LAB_0023433b:
  if ((DAT_01216a58 == 0) && (FUN_00291790(&DAT_01216a60), DAT_01216a58 == 0)) {
    FUN_00234790();
    FUN_002348a0(_Var5);
    if (DAT_01216a58 != 0) goto LAB_00234354;
    if (DAT_01216a78 == 0) goto LAB_0023435c;
    if (param_4 == 1) {
      FUN_002340f0(
                  "NVML LOG\n\nBuild branch : r596_25\nBuild date   : Apr 24 2026 06:27:04\nBuild CL     : 37855471\nBuild Type   : Local build\n"
                  );
      goto LAB_00234354;
    }
    if (param_4 == 2) {
      FUN_002340f0(
                  "NVHCA LOG\n\nBuild branch : r596_25\nBuild date   : Apr 24 2026 06:27:04\nBuild CL     : 37855471\nBuild Type   : Local build\n"
                  );
      goto LAB_00234354;
    }
  }
  else {
LAB_00234354:
    if (DAT_01216a78 == 0) goto LAB_0023435c;
  }
  FUN_00292d50(&local_4c8);
  FUN_002340f0("NVML Log %d/%d/%d %02d:%02d:%02d.%03d\n",local_4c8.st_dev._4_4_,
               (undefined4)local_4c8.st_ino,(undefined4)local_4c8.st_dev,
               (undefined4)local_4c8.st_nlink,local_4c8.st_nlink._4_4_,local_4c8.st_mode,
               local_4c8.st_uid);
LAB_0023435c:
  DAT_01216a58 = 1;
  FUN_00291830(&DAT_01216a50,0);
  return;
}


// ===== 00234790 FUN_00234790 =====

void FUN_00234790(void)

{
  DAT_01216a90 = 0xd3daecb8;
  DAT_01216a8c = 0x1d4d4848;
  DAT_01216a88 = 0xaa7b8e81;
  DAT_01216a84 = 0x23cc0ec3;
  DAT_01216a80 = 0x7645f3ed;
  DAT_01216a7c = 0xe44a4f49;
  return;
}


// ===== 002347d0 FUN_002347d0 =====

void FUN_002347d0(char *param_1,long param_2)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_2 == 0) {
    return;
  }
  pcVar1 = param_1 + param_2;
  iVar3 = DAT_01216a7c;
  do {
    uVar2 = DAT_01216a80;
    uVar6 = DAT_01216a84;
    uVar5 = DAT_01216a8c;
    DAT_01216a8c = DAT_01216a88;
    iVar3 = iVar3 + 0x587c5;
    uVar4 = DAT_01216a90 >> 2 ^ DAT_01216a90;
    DAT_01216a80 = uVar2 << 4 ^ uVar4 ^ uVar2 ^ uVar4 * 2;
    *param_1 = *param_1 + (char)DAT_01216a80 + (char)iVar3;
    param_1 = param_1 + 1;
    DAT_01216a88 = uVar6;
    DAT_01216a84 = uVar2;
    DAT_01216a90 = uVar5;
  } while (pcVar1 != param_1);
  DAT_01216a7c = DAT_01216a7c + 0x587c5 + ((int)param_2 + -1) * 0x587c5;
  return;
}


// ===== 002348a0 FUN_002348a0 =====

void FUN_002348a0(long param_1)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  if (param_1 == 0) {
    return;
  }
  lVar3 = 0;
  do {
    uVar4 = DAT_01216a80;
    uVar6 = DAT_01216a84;
    uVar7 = DAT_01216a88;
    uVar5 = DAT_01216a8c;
    lVar2 = lVar3;
    lVar3 = lVar2 + 1;
    uVar1 = DAT_01216a90 >> 2 ^ DAT_01216a90;
    DAT_01216a80 = uVar1 * 2 ^ uVar4 << 4 ^ uVar1 ^ uVar4;
    DAT_01216a90 = uVar5;
    DAT_01216a8c = uVar7;
    DAT_01216a88 = uVar6;
    DAT_01216a84 = uVar4;
  } while (param_1 != lVar3);
  DAT_01216a7c = DAT_01216a7c + 0x587c5 + (int)lVar2 * 0x587c5;
  return;
}


// ===== 00234960 FUN_00234960 =====

long FUN_00234960(long param_1,long *param_2,undefined8 param_3,int param_4)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *param_2;
  if ((lVar2 != param_1 + 0x18) || (lVar2 != param_2[1])) {
    while( true ) {
      if (*(int *)(lVar2 + -8) == param_4) {
        iVar1 = (**(code **)(param_1 + 0x30))(*(undefined8 *)(lVar2 + -0x18),param_3);
        if (iVar1 != 0) {
          return lVar2 + -0x18;
        }
      }
      if (param_2[1] == lVar2) break;
      lVar2 = *(long *)(lVar2 + 8);
    }
  }
  return 0;
}


// ===== 002349e0 FUN_002349e0 =====

void FUN_002349e0(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20);
  while (lVar2 != param_1 + 0x18) {
    lVar1 = *(long *)(lVar2 + 8);
    if (*(code **)(param_1 + 0x38) != (code *)0x0) {
      (**(code **)(param_1 + 0x38))(*(undefined8 *)(lVar2 + -0x18));
    }
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      (**(code **)(param_1 + 0x40))(*(undefined8 *)(lVar2 + -0x10));
    }
    free((void *)(lVar2 + -0x18));
    lVar2 = lVar1;
  }
  return;
}


// ===== 00234a50 FUN_00234a50 =====

undefined8 FUN_00234a50(int *param_1,undefined8 param_2,uint param_3)

{
  undefined8 *puVar1;
  undefined8 *__ptr;
  undefined8 uVar2;
  long *plVar3;
  
  plVar3 = (long *)(((ulong)param_3 % (ulong)*(uint *)(&DAT_002dbe20 + (ulong)(uint)param_1[4] * 4))
                    * 0x10 + *(long *)(param_1 + 2));
  __ptr = (undefined8 *)FUN_00234960(param_1,plVar3,param_2,param_3);
  if (__ptr == (undefined8 *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    puVar1 = __ptr + 3;
    if (puVar1 == (undefined8 *)*plVar3) {
      if (puVar1 == (undefined8 *)plVar3[1]) {
        plVar3[1] = (long)(param_1 + 6);
        *plVar3 = (long)(param_1 + 6);
      }
      else {
        *plVar3 = __ptr[4];
      }
    }
    else if (puVar1 == (undefined8 *)plVar3[1]) {
      plVar3[1] = __ptr[3];
    }
    puVar1 = (undefined8 *)__ptr[4];
    *(undefined8 **)(__ptr[3] + 8) = puVar1;
    *puVar1 = __ptr[3];
    if (*(code **)(param_1 + 0xe) != (code *)0x0) {
      (**(code **)(param_1 + 0xe))(*__ptr);
    }
    if (*(code **)(param_1 + 0x10) != (code *)0x0) {
      (**(code **)(param_1 + 0x10))(__ptr[1]);
    }
    free(__ptr);
    *param_1 = *param_1 + -1;
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 00234b40 FUN_00234b40 =====

undefined8
FUN_00234b40(undefined4 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined8 uVar3;
  uint uVar4;
  ulong uVar5;
  
  *param_1 = 0;
  param_1[4] = 0;
  pvVar2 = malloc(0x50);
  *(void **)(param_1 + 2) = pvVar2;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0xffffffff;
  }
  else {
    puVar1 = param_1 + 6;
    *(undefined8 *)(param_1 + 10) = param_2;
    *(undefined4 **)(param_1 + 8) = puVar1;
    *(undefined4 **)(param_1 + 6) = puVar1;
    *(undefined8 *)(param_1 + 0xc) = param_3;
    *(undefined8 *)(param_1 + 0xe) = param_4;
    *(undefined8 *)(param_1 + 0x10) = param_5;
    uVar5 = 0;
    while( true ) {
      uVar4 = (int)uVar5 + 1;
      *(undefined4 **)((long)pvVar2 + uVar5 * 0x10 + 8) = puVar1;
      *(undefined4 **)(*(long *)(param_1 + 2) + uVar5 * 0x10) = puVar1;
      if (*(uint *)(&DAT_002dbe20 + (ulong)(uint)param_1[4] * 4) <= uVar4) break;
      pvVar2 = *(void **)(param_1 + 2);
      uVar5 = (ulong)uVar4;
    }
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 00234bf0 FUN_00234bf0 =====

void FUN_00234bf0(long param_1)

{
  FUN_002349e0();
  free(*(void **)(param_1 + 8));
  return;
}


// ===== 00234c10 FUN_00234c10 =====

undefined8 FUN_00234c10(uint *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  uint *puVar3;
  long lVar4;
  uint *puVar5;
  uint uVar6;
  void *pvVar7;
  uint uVar8;
  ulong uVar9;
  undefined8 *puVar10;
  long *plVar11;
  uint *puVar12;
  uint *puVar13;
  
  uVar6 = (**(code **)(param_1 + 10))(param_2);
  FUN_00234a50(param_1,param_2,uVar6);
  if (*(uint *)(&DAT_002dbe20 + (ulong)param_1[4] * 4) <= *param_1) {
    free(*(void **)(param_1 + 2));
    uVar2 = *(uint *)(&DAT_002dbe20 + (ulong)(param_1[4] + 1) * 4);
    param_1[4] = param_1[4] + 1;
    pvVar7 = malloc((ulong)uVar2 << 4);
    *(void **)(param_1 + 2) = pvVar7;
    if (pvVar7 == (void *)0x0) {
      return 0xffffffff;
    }
    puVar5 = param_1 + 6;
    if (uVar2 != 0) {
      uVar9 = 0;
      while( true ) {
        uVar8 = (int)uVar9 + 1;
        *(uint **)((long)pvVar7 + uVar9 * 0x10 + 8) = puVar5;
        *(uint **)(*(long *)(param_1 + 2) + uVar9 * 0x10) = puVar5;
        if (*(uint *)(&DAT_002dbe20 + (ulong)param_1[4] * 4) <= uVar8) break;
        pvVar7 = *(void **)(param_1 + 2);
        uVar9 = (ulong)uVar8;
      }
    }
    puVar12 = *(uint **)(param_1 + 8);
    *(uint **)(param_1 + 6) = puVar5;
    *(uint **)(param_1 + 8) = puVar5;
    while (puVar13 = puVar12, puVar12 != puVar5) {
      while( true ) {
        puVar12 = *(uint **)(puVar13 + 2);
        puVar10 = (undefined8 *)
                  (((ulong)puVar13[-2] % (ulong)uVar2) * 0x10 + *(long *)(param_1 + 2));
        puVar3 = (uint *)*puVar10;
        if ((puVar3 != puVar5) || ((uint *)puVar10[1] != puVar5)) break;
        *(uint **)(puVar13 + 2) = puVar5;
        lVar4 = *(long *)(param_1 + 6);
        *(long *)puVar13 = lVar4;
        *(uint **)(lVar4 + 8) = puVar13;
        *(uint **)(param_1 + 6) = puVar13;
        puVar10[1] = puVar13;
        *puVar10 = puVar13;
        puVar13 = puVar12;
        if (puVar12 == puVar5) goto LAB_00234d38;
      }
      *(uint **)(puVar13 + 2) = puVar3;
      lVar4 = *(long *)puVar3;
      *(long *)puVar13 = lVar4;
      *(uint **)(lVar4 + 8) = puVar13;
      *(uint **)puVar3 = puVar13;
      *puVar10 = puVar13;
    }
  }
LAB_00234d38:
  puVar10 = malloc(0x28);
  if (puVar10 == (undefined8 *)0x0) {
    return 0xffffffff;
  }
  *puVar10 = param_2;
  puVar1 = puVar10 + 3;
  uVar2 = param_1[4];
  *(uint *)(puVar10 + 2) = uVar6;
  puVar10[1] = param_3;
  uVar2 = *(uint *)(&DAT_002dbe20 + (ulong)uVar2 * 4);
  puVar10[4] = puVar1;
  puVar10[3] = puVar1;
  plVar11 = (long *)(((ulong)uVar6 % (ulong)uVar2) * 0x10 + *(long *)(param_1 + 2));
  puVar5 = (uint *)*plVar11;
  if ((puVar5 == param_1 + 6) && (puVar5 == (uint *)plVar11[1])) {
    puVar10[4] = puVar5;
    lVar4 = *(long *)(param_1 + 6);
    puVar10[3] = lVar4;
    *(undefined8 **)(lVar4 + 8) = puVar1;
    *(undefined8 **)(param_1 + 6) = puVar1;
    plVar11[1] = (long)puVar1;
    *plVar11 = (long)puVar1;
  }
  else {
    puVar10[4] = puVar5;
    lVar4 = *(long *)puVar5;
    puVar10[3] = lVar4;
    *(undefined8 **)(lVar4 + 8) = puVar1;
    *(undefined8 **)puVar5 = puVar1;
    *plVar11 = (long)puVar1;
  }
  *param_1 = *param_1 + 1;
  return 0;
}


// ===== 00234de0 FUN_00234de0 =====

undefined8 FUN_00234de0(long param_1,undefined8 param_2)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  
  uVar1 = (**(code **)(param_1 + 0x28))(param_2);
  lVar2 = FUN_00234960(param_1,*(long *)(param_1 + 8) +
                               ((ulong)uVar1 %
                               (ulong)*(uint *)(&DAT_002dbe20 + (ulong)*(uint *)(param_1 + 0x10) * 4
                                               )) * 0x10,param_2,uVar1);
  uVar3 = 0;
  if (lVar2 != 0) {
    uVar3 = *(undefined8 *)(lVar2 + 8);
  }
  return uVar3;
}


// ===== 00234e30 FUN_00234e30 =====

long FUN_00234e30(void)

{
  timeval local_18;
  
  gettimeofday(&local_18,(__timezone_ptr_t)0x0);
  return local_18.tv_sec * 1000000 + local_18.tv_usec;
}


// ===== 00234e60 FUN_00234e60 =====

undefined8 * FUN_00234e60(ulong param_1,long param_2,undefined8 param_3)

{
  undefined8 *__ptr;
  void *pvVar1;
  
  if ((param_2 - 1U < 0x40000000) && (param_1 < 0x40000001)) {
    if (param_1 == 0) {
      param_1 = 8;
    }
    __ptr = malloc(0x28);
    if (__ptr != (undefined8 *)0x0) {
      pvVar1 = malloc(param_1 * param_2);
      *__ptr = pvVar1;
      if (pvVar1 != (void *)0x0) {
        __ptr[3] = param_1;
        __ptr[1] = 0;
        __ptr[2] = param_2;
        __ptr[4] = param_3;
        return __ptr;
      }
      free(__ptr);
    }
  }
  return (undefined8 *)0x0;
}


// ===== 00234f00 FUN_00234f00 =====

undefined8 FUN_00234f00(undefined8 *param_1,void *param_2)

{
  long lVar1;
  void *__ptr;
  ulong uVar2;
  undefined8 uVar3;
  
  if (param_1 == (undefined8 *)0x0) {
    return 0xffffffff;
  }
  if (param_2 == (void *)0x0) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar2 = param_1[1];
    __ptr = (void *)*param_1;
    if ((ulong)param_1[3] <= uVar2) {
      lVar1 = param_1[3] * 2;
      param_1[3] = lVar1;
      __ptr = realloc(__ptr,lVar1 * param_1[2]);
      *param_1 = __ptr;
      if (__ptr == (void *)0x0) {
        return 0xfffffffe;
      }
      uVar2 = param_1[1];
    }
    memcpy((void *)((long)__ptr + uVar2 * param_1[2]),param_2,param_1[2]);
    param_1[1] = param_1[1] + 1;
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 00234f80 FUN_00234f80 =====

long FUN_00234f80(long *param_1,undefined8 *param_2)

{
  if ((((param_1 != (long *)0x0) && (param_2 != (undefined8 *)0x0)) && (*param_1 != 0)) &&
     (param_1[1] != 0)) {
    *param_2 = 0;
    return *param_1;
  }
  return 0;
}


// ===== 00234fb0 FUN_00234fb0 =====

long FUN_00234fb0(long *param_1,ulong *param_2)

{
  ulong uVar1;
  
  if (((param_1 != (long *)0x0) && (param_2 != (ulong *)0x0)) &&
     (uVar1 = *param_2 + 1, uVar1 < (ulong)param_1[1])) {
    *param_2 = uVar1;
    return uVar1 * param_1[2] + *param_1;
  }
  return 0;
}


// ===== 00234fe0 FUN_00234fe0 =====

void FUN_00234fe0(undefined8 *param_1)

{
  long lVar1;
  undefined1 local_20 [8];
  
  if (param_1 == (undefined8 *)0x0) {
    return;
  }
  if (param_1[4] != 0) {
    lVar1 = FUN_00234f80(param_1,local_20);
    while (lVar1 != 0) {
      (*(code *)param_1[4])(lVar1);
      lVar1 = FUN_00234fb0(param_1,local_20);
    }
  }
  free((void *)*param_1);
  free(param_1);
  return;
}


// ===== 00235050 FUN_00235050 =====

int FUN_00235050(long param_1,ushort param_2)

{
  if (param_1 != 0) {
    return ((int)(param_2 - 1) >> 6) * 8 + 8;
  }
  return 0;
}


// ===== 00235080 FUN_00235080 =====

undefined8 FUN_00235080(undefined8 *param_1,ushort param_2)

{
  uint uVar1;
  ulong uVar2;
  undefined8 *puVar3;
  
  uVar1 = (((int)(param_2 - 1) >> 6) + 1) * 8;
  if (param_1 == (undefined8 *)0x0) {
    return 0x1f;
  }
  if (uVar1 < 8) {
    if (uVar1 != 0) {
      *(undefined1 *)param_1 = 0;
      return 0;
    }
  }
  else {
    *param_1 = 0;
    *(undefined8 *)((long)param_1 + ((ulong)uVar1 - 8)) = 0;
    puVar3 = (undefined8 *)((ulong)(param_1 + 1) & 0xfffffffffffffff8);
    for (uVar2 = (ulong)(uVar1 + ((int)param_1 -
                                 (int)(undefined8 *)((ulong)(param_1 + 1) & 0xfffffffffffffff8)) >>
                        3); uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
  }
  return 0;
}


// ===== 002350f0 FUN_002350f0 =====

undefined8 FUN_002350f0(long param_1,uint param_2,uint param_3)

{
  ulong *puVar1;
  
  if ((param_3 < param_2) && (param_1 != 0)) {
    puVar1 = (ulong *)(param_1 + (ulong)(param_3 >> 6) * 8);
    *puVar1 = *puVar1 & ~(1L << ((byte)param_3 & 0x3f));
    return 0;
  }
  return 0x1f;
}


// ===== 00235120 FUN_00235120 =====

undefined8 FUN_00235120(long param_1,uint param_2,uint param_3)

{
  ulong *puVar1;
  
  if ((param_3 < param_2) && (param_1 != 0)) {
    puVar1 = (ulong *)(param_1 + (ulong)(param_3 >> 6) * 8);
    *puVar1 = *puVar1 | 1L << ((byte)param_3 & 0x3f);
    return 0;
  }
  return 0x1f;
}


// ===== 00235150 FUN_00235150 =====

undefined8 FUN_00235150(long param_1,ushort param_2)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  bool bVar4;
  
  uVar3 = (int)(param_2 - 1) >> 6;
  if (param_1 == 0) {
    return 0;
  }
  if (uVar3 != 0xffffffff) {
    uVar1 = 0;
    do {
      uVar2 = 0xffffffffffffffff;
      if (uVar3 <= (uint)uVar1) {
        uVar2 = 0xffffffffffffffff >> (-(char)param_2 & 0x3fU);
      }
      if ((uVar2 & *(ulong *)(param_1 + uVar1 * 8)) != 0) {
        return 0;
      }
      bVar4 = uVar1 != uVar3;
      uVar1 = uVar1 + 1;
    } while (bVar4);
  }
  return 1;
}


// ===== 002351b0 FUN_002351b0 =====

undefined8 FUN_002351b0(long param_1,ushort param_2,long param_3,ushort param_4)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  bool bVar4;
  
  if ((param_3 == 0 || param_1 == 0) || (param_2 != param_4)) {
    return 0x1f;
  }
  uVar3 = (int)(param_2 - 1) >> 6;
  if (uVar3 != 0xffffffff) {
    uVar1 = 0;
    do {
      uVar2 = 0xffffffffffffffff;
      if (uVar3 <= (uint)uVar1) {
        uVar2 = 0xffffffffffffffff >> (-(char)param_2 & 0x3fU);
      }
      if (((*(ulong *)(param_1 + uVar1 * 8) ^ *(ulong *)(param_3 + uVar1 * 8)) & uVar2) != 0) {
        return 0;
      }
      bVar4 = uVar1 != uVar3;
      uVar1 = uVar1 + 1;
    } while (bVar4);
  }
  return 1;
}


// ===== 00235250 FUN_00235250 =====

uint FUN_00235250(long param_1,uint param_2,uint param_3)

{
  if ((param_3 < param_2) && (param_1 != 0)) {
    return (uint)(*(ulong *)(param_1 + (ulong)(param_3 >> 6) * 8) >> ((byte)param_3 & 0x3f)) & 1;
  }
  return 0;
}


// ===== 00235280 FUN_00235280 =====

undefined8
FUN_00235280(long param_1,ushort param_2,long param_3,ushort param_4,long param_5,ushort param_6)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  bool bVar4;
  
  if ((((param_3 != 0 && param_1 != 0) && (param_5 != 0)) && (param_2 == param_4)) &&
     (param_4 == param_6)) {
    uVar3 = (int)(param_2 - 1) >> 6;
    if (uVar3 == 0xffffffff) {
      return 0;
    }
    uVar1 = 0;
    do {
      uVar2 = 0xffffffffffffffff;
      if (uVar3 <= (uint)uVar1) {
        uVar2 = 0xffffffffffffffff >> (-(char)param_2 & 0x3fU);
      }
      *(ulong *)(param_1 + uVar1 * 8) =
           *(ulong *)(param_3 + uVar1 * 8) & *(ulong *)(param_5 + uVar1 * 8) & uVar2;
      bVar4 = uVar1 != uVar3;
      uVar1 = uVar1 + 1;
    } while (bVar4);
    return 0;
  }
  return 0x1f;
}


// ===== 00235330 FUN_00235330 =====

undefined8
FUN_00235330(long param_1,ushort param_2,long param_3,ushort param_4,long param_5,ushort param_6)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  bool bVar4;
  
  if ((((param_3 != 0 && param_1 != 0) && (param_5 != 0)) && (param_2 == param_4)) &&
     (param_4 == param_6)) {
    uVar3 = (int)(param_2 - 1) >> 6;
    if (uVar3 == 0xffffffff) {
      return 0;
    }
    uVar1 = 0;
    do {
      uVar2 = 0xffffffffffffffff;
      if (uVar3 <= (uint)uVar1) {
        uVar2 = 0xffffffffffffffff >> (-(char)param_2 & 0x3fU);
      }
      *(ulong *)(param_1 + uVar1 * 8) =
           (*(ulong *)(param_3 + uVar1 * 8) | *(ulong *)(param_5 + uVar1 * 8)) & uVar2;
      bVar4 = uVar1 != uVar3;
      uVar1 = uVar1 + 1;
    } while (bVar4);
    return 0;
  }
  return 0x1f;
}


// ===== 002353e0 FUN_002353e0 =====

undefined8 FUN_002353e0(undefined8 *param_1,ushort param_2,undefined8 *param_3,ushort param_4)

{
  uint uVar1;
  ulong uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  long lVar5;
  undefined8 uVar6;
  
  if ((param_3 != (undefined8 *)0x0 && param_1 != (undefined8 *)0x0) && (param_2 == param_4)) {
    if (param_1 == param_3) {
      uVar6 = 0x10006;
    }
    else {
      uVar6 = 0x1f;
      uVar2 = (long)(((int)(param_4 - 1) >> 6) + 1) << 3;
      if (uVar2 <= (ulong)((long)(((int)(param_2 - 1) >> 6) + 1) << 3)) {
        uVar1 = (uint)uVar2;
        if (uVar1 < 8) {
          if (uVar1 != 0) {
            *(undefined1 *)param_1 = *(undefined1 *)param_3;
          }
        }
        else {
          *param_1 = *param_3;
          *(undefined8 *)((long)param_1 + ((uVar2 & 0xffffffff) - 8)) =
               *(undefined8 *)((long)param_3 + ((uVar2 & 0xffffffff) - 8));
          lVar5 = (long)param_1 - (long)((ulong)(param_1 + 1) & 0xfffffffffffffff8);
          puVar3 = (undefined8 *)((long)param_3 - lVar5);
          puVar4 = (undefined8 *)((ulong)(param_1 + 1) & 0xfffffffffffffff8);
          for (uVar2 = (ulong)((int)lVar5 + uVar1 >> 3); uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar4 = *puVar3;
            puVar3 = puVar3 + 1;
            puVar4 = puVar4 + 1;
          }
        }
        uVar6 = 0;
      }
    }
    return uVar6;
  }
  return 0x1f;
}


// ===== 002354a0 FUN_002354a0 =====

uint FUN_002354a0(long param_1,ushort param_2)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  bool bVar4;
  
  uVar3 = (int)(param_2 - 1) >> 6;
  if (param_1 == 0) {
    return 0;
  }
  if (uVar3 != 0xffffffff) {
    uVar1 = 0;
    do {
      uVar2 = 0xffffffffffffffff;
      if (uVar3 <= (uint)uVar1) {
        uVar2 = 0xffffffffffffffff >> (-(char)param_2 & 0x3fU);
      }
      uVar2 = uVar2 & *(ulong *)(param_1 + uVar1 * 8);
      if (uVar2 != 0) {
        uVar2 = uVar2 & -uVar2;
        return (uint)uVar1 * 0x40 + (uint)(uVar2 == 0) + (uint)((uVar2 & 0x5555555555555555) == 0) +
               (uint)((int)uVar2 == 0) * 0x20 + (uint)((uVar2 & 0xffff0000ffff) == 0) * 0x10 +
               (uint)((uVar2 & 0xff00ff00ff00ff) == 0) * 8 +
               (uint)((uVar2 & 0xf0f0f0f0f0f0f0f) == 0) * 4 +
               (uint)((uVar2 & 0x3333333333333333) == 0) * 2;
      }
      bVar4 = uVar1 != uVar3;
      uVar1 = uVar1 + 1;
    } while (bVar4);
  }
  return (uint)param_2;
}


// ===== 002355b0 FUN_002355b0 =====

int FUN_002355b0(long param_1,ushort param_2)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  
  uVar3 = (int)(param_2 - 1) >> 6;
  if ((param_1 != 0) && (uVar3 != 0xffffffff)) {
    iVar4 = 0;
    uVar2 = 0;
    do {
      uVar1 = 0xffffffffffffffff;
      if (uVar3 <= (uint)uVar2) {
        uVar1 = 0xffffffffffffffff >> (-(char)param_2 & 0x3fU);
      }
      uVar1 = uVar1 & *(ulong *)(param_1 + uVar2 * 8);
      uVar1 = uVar1 - (uVar1 >> 1 & 0x5555555555555555);
      uVar1 = (uVar1 & 0x3333333333333333) + (uVar1 >> 2 & 0x3333333333333333);
      iVar4 = iVar4 + (uint)(byte)(((uVar1 >> 4) + uVar1 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >>
                                  0x38);
      bVar5 = uVar3 != uVar2;
      uVar2 = uVar2 + 1;
    } while (bVar5);
    return iVar4;
  }
  return 0;
}


// ===== 00235690 FUN_00235690 =====

undefined8 FUN_00235690(undefined8 *param_1,ushort param_2,undefined8 *param_3,uint param_4)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  
  uVar2 = (long)(((int)(param_2 - 1) >> 6) + 1) << 3;
  if ((param_3 != (undefined8 *)0x0) && (param_1 != (undefined8 *)0x0)) {
    uVar6 = 2;
    if (uVar2 <= param_4) {
      uVar1 = (uint)uVar2;
      if (uVar1 < 8) {
        if (uVar1 != 0) {
          *(undefined1 *)param_3 = *(undefined1 *)param_1;
        }
      }
      else {
        *param_3 = *param_1;
        *(undefined8 *)((long)param_3 + ((uVar2 & 0xffffffff) - 8)) =
             *(undefined8 *)((long)param_1 + ((uVar2 & 0xffffffff) - 8));
        lVar3 = (long)param_3 - (long)((ulong)(param_3 + 1) & 0xfffffffffffffff8);
        puVar4 = (undefined8 *)((long)param_1 - lVar3);
        puVar5 = (undefined8 *)((ulong)(param_3 + 1) & 0xfffffffffffffff8);
        for (uVar2 = (ulong)(uVar1 + (int)lVar3 >> 3); uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
      }
      uVar6 = 0;
    }
    return uVar6;
  }
  return 0x1f;
}


// ===== 00235720 FUN_00235720 =====

undefined8 FUN_00235720(undefined8 *param_1,ushort param_2,undefined8 *param_3,uint param_4)

{
  uint uVar1;
  ulong uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  long lVar5;
  undefined8 uVar6;
  
  uVar2 = (long)(((int)(param_2 - 1) >> 6) + 1) << 3;
  if ((param_3 != (undefined8 *)0x0) && (param_1 != (undefined8 *)0x0)) {
    uVar6 = 2;
    if (uVar2 <= param_4) {
      uVar1 = (uint)uVar2;
      if (uVar1 < 8) {
        if (uVar1 != 0) {
          *(undefined1 *)param_1 = *(undefined1 *)param_3;
        }
      }
      else {
        *param_1 = *param_3;
        *(undefined8 *)((long)param_1 + ((uVar2 & 0xffffffff) - 8)) =
             *(undefined8 *)((long)param_3 + ((uVar2 & 0xffffffff) - 8));
        lVar5 = (long)param_1 - (long)((ulong)(param_1 + 1) & 0xfffffffffffffff8);
        puVar3 = (undefined8 *)((long)param_3 - lVar5);
        puVar4 = (undefined8 *)((ulong)(param_1 + 1) & 0xfffffffffffffff8);
        for (uVar2 = (ulong)(uVar1 + (int)lVar5 >> 3); uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
        }
      }
      uVar6 = 0;
    }
    return uVar6;
  }
  return 0x1f;
}


// ===== 002357b0 FUN_002357b0 =====

char * FUN_002357b0(char *param_1,undefined8 *param_2)

{
  uint uVar1;
  char *pcVar2;
  uint uVar3;
  size_t __maxlen;
  char *__s;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  
  pcVar2 = malloc(100);
  if (pcVar2 != (char *)0x0) {
    uVar3 = 100;
    __maxlen = 100;
    do {
      __s = pcVar2;
      local_50 = *param_2;
      uStack_48 = param_2[1];
      local_40 = param_2[2];
      uVar1 = vsnprintf(__s,__maxlen,param_1,&local_50);
      if (uVar1 < uVar3) {
        return __s;
      }
      uVar3 = uVar3 * 2;
      if (-1 < (int)uVar1) {
        uVar3 = uVar1 + 1;
      }
      __maxlen = (size_t)(int)uVar3;
      pcVar2 = realloc(__s,__maxlen);
    } while (pcVar2 != (char *)0x0);
    free(__s);
  }
  return (char *)0x0;
}


// ===== 00235860 FUN_00235860 =====

void FUN_00235860(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                 undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
                 undefined8 param_13,undefined8 param_14)

{
  char in_AL;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined1 *local_c8;
  undefined1 *local_c0;
  undefined1 local_b8 [8];
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 local_38;
  undefined8 local_28;
  undefined8 local_18;
  
  if (in_AL != '\0') {
    local_88 = param_1;
    local_78 = param_2;
    local_68 = param_3;
    local_58 = param_4;
    local_48 = param_5;
    local_38 = param_6;
    local_28 = param_7;
    local_18 = param_8;
  }
  local_c8 = &stack0x00000008;
  local_d0 = 8;
  local_c0 = local_b8;
  local_cc = 0x30;
  local_b0 = param_10;
  local_a8 = param_11;
  local_a0 = param_12;
  local_98 = param_13;
  local_90 = param_14;
  FUN_002357b0(param_9,&local_d0);
  return;
}


// ===== 002358f0 FUN_002358f0 =====

byte FUN_002358f0(long param_1)

{
  int iVar1;
  char *__name;
  
  __name = (char *)FUN_00235860("/sys/bus/pci/devices/%04x:%02x:%02x.%x/reset",
                                *(undefined4 *)(param_1 + 0x124),*(undefined1 *)(param_1 + 2),
                                *(undefined1 *)(param_1 + 3),*(undefined1 *)(param_1 + 4));
  if (__name != (char *)0x0) {
    iVar1 = access(__name,2);
    free(__name);
    return ~-(iVar1 == 0) & 3;
  }
  return 0x11;
}


// ===== 00235960 FUN_00235960 =====

byte FUN_00235960(long param_1)

{
  int iVar1;
  char *__name;
  
  __name = (char *)FUN_00235860("/sys/bus/pci/devices/%04x:%02x:%02x.%x/reset_method",
                                *(undefined4 *)(param_1 + 0x124),*(undefined1 *)(param_1 + 2),
                                *(undefined1 *)(param_1 + 3),*(undefined1 *)(param_1 + 4));
  if (__name != (char *)0x0) {
    iVar1 = access(__name,2);
    free(__name);
    return ~-(iVar1 == 0) & 3;
  }
  return 3;
}


// ===== 002359d0 FUN_002359d0 =====

undefined8
FUN_002359d0(undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
            char *param_9,char *param_10,undefined8 param_11,undefined8 param_12,undefined8 param_13
            ,undefined8 param_14)

{
  char in_AL;
  int iVar1;
  FILE *__s;
  int *piVar2;
  char *pcVar3;
  long lVar4;
  undefined8 uVar5;
  float fVar6;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined1 *local_e8;
  undefined1 *local_e0;
  undefined1 local_d8 [16];
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined4 local_a8;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 local_38;
  
  if (in_AL != '\0') {
    local_a8 = param_1;
    local_98 = param_2;
    local_88 = param_3;
    local_78 = param_4;
    local_68 = param_5;
    local_58 = param_6;
    local_48 = param_7;
    local_38 = param_8;
  }
  local_c8 = param_11;
  local_c0 = param_12;
  local_b8 = param_13;
  local_b0 = param_14;
  __s = fopen(param_9,"w");
  if (__s == (FILE *)0x0) {
    if (DAT_01216a78 < 2) {
      return 0x11;
    }
    piVar2 = __errno_location();
    pcVar3 = strerror(*piVar2);
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0(SUB84((double)(fVar6 * DAT_00298548),0),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s: %s\n","ERROR",lVar4,"unix.c",0x3b0,param_9,
                 pcVar3);
    uVar5 = 0x11;
  }
  else {
    local_e8 = &stack0x00000008;
    local_e0 = local_d8;
    local_f0 = 0x10;
    local_ec = 0x30;
    iVar1 = vfprintf(__s,param_10,&local_f0);
    fclose(__s);
    uVar5 = 0;
    if (iVar1 < 0) {
      if (1 < DAT_01216a78) {
        piVar2 = __errno_location();
        pcVar3 = strerror(*piVar2);
        fVar6 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0(SUB84((double)(fVar6 * DAT_00298548),0),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s > %s: %s\n","ERROR",lVar4,"unix.c",0x3bd
                     ,param_10,param_9,pcVar3);
      }
      return 0x11;
    }
  }
  return uVar5;
}


// ===== 00235be0 FUN_00235be0 =====

int FUN_00235be0(long param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int iVar5;
  void *__ptr;
  long lVar6;
  float fVar7;
  
  if (param_1 == 0) {
    iVar5 = 2;
  }
  else {
    __ptr = (void *)FUN_00235860("/sys/bus/pci/devices/%04x:%02x:%02x.%x/reset",
                                 *(undefined4 *)(param_1 + 0x124),*(undefined1 *)(param_1 + 2),
                                 *(undefined1 *)(param_1 + 3),*(undefined1 *)(param_1 + 4));
    if (__ptr == (void *)0x0) {
      iVar5 = 0x11;
    }
    else {
      iVar5 = FUN_002359d0(__ptr,"1");
      free(__ptr);
      if (iVar5 == 0) {
        if (3 < DAT_01216a78) {
          uVar1 = *(undefined1 *)(param_1 + 4);
          uVar2 = *(undefined1 *)(param_1 + 3);
          uVar3 = *(undefined1 *)(param_1 + 2);
          uVar4 = *(undefined4 *)(param_1 + 0x124);
          fVar7 = (float)FUN_002917b0(&DAT_01216a60);
          lVar6 = syscall(0xba);
          FUN_002340f0((double)(fVar7 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n",&DAT_002983c2,lVar6,
                       "unix.c",0x429,uVar4,uVar3,uVar2,uVar1);
        }
      }
      else if (1 < DAT_01216a78) {
        uVar1 = *(undefined1 *)(param_1 + 4);
        uVar2 = *(undefined1 *)(param_1 + 3);
        uVar3 = *(undefined1 *)(param_1 + 2);
        uVar4 = *(undefined4 *)(param_1 + 0x124);
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar6 = syscall(0xba);
        FUN_002340f0((double)(fVar7 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n","ERROR",lVar6,"unix.c"
                     ,0x42f,uVar4,uVar3,uVar2,uVar1);
      }
    }
  }
  return iVar5;
}


// ===== 00235db0 FUN_00235db0 =====

undefined8 FUN_00235db0(long param_1,uint *param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  float fVar5;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  *param_2 = uVar1 >> 0x10 & 0xff;
  *param_3 = uVar1 >> 8 & 0xff;
  *param_4 = uVar1 & 0xff;
  if (DAT_01216a78 < 4) {
    return 0;
  }
  uVar2 = *param_3;
  uVar3 = *param_2;
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * DAT_00298548),
               "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%06x %02x %02x %02x\n",&DAT_002983c2,lVar4,
               "unix.c",0x2c2,uVar1,uVar3,uVar2,uVar1 & 0xff);
  return 0;
}


// ===== 00235e80 FUN_00235e80 =====

int FUN_00235e80(long param_1,undefined8 param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int iVar5;
  void *__ptr;
  long lVar6;
  float fVar7;
  
  __ptr = (void *)FUN_00235860("/sys/bus/pci/devices/%04x:%02x:%02x.%x/reset_method",
                               *(undefined4 *)(param_1 + 0x124),*(undefined1 *)(param_1 + 2),
                               *(undefined1 *)(param_1 + 3),*(undefined1 *)(param_1 + 4));
  if (__ptr == (void *)0x0) {
    iVar5 = 3;
  }
  else {
    iVar5 = FUN_002359d0(__ptr,param_2);
    free(__ptr);
    if (iVar5 == 0) {
      if (3 < DAT_01216a78) {
        uVar1 = *(undefined1 *)(param_1 + 4);
        uVar2 = *(undefined1 *)(param_1 + 3);
        uVar3 = *(undefined1 *)(param_1 + 2);
        uVar4 = *(undefined4 *)(param_1 + 0x124);
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar6 = syscall(0xba);
        FUN_002340f0((double)(fVar7 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n",&DAT_002983c2,lVar6,
                     "unix.c",0x466,uVar4,uVar3,uVar2,uVar1);
      }
    }
    else if (1 < DAT_01216a78) {
      uVar1 = *(undefined1 *)(param_1 + 4);
      uVar2 = *(undefined1 *)(param_1 + 3);
      uVar3 = *(undefined1 *)(param_1 + 2);
      uVar4 = *(undefined4 *)(param_1 + 0x124);
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar6 = syscall(0xba);
      FUN_002340f0((double)(fVar7 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n","ERROR",lVar6,"unix.c",
                   0x46c,uVar4,uVar3,uVar2,uVar1);
    }
  }
  return iVar5;
}


// ===== 00236030 FUN_00236030 =====

undefined8 FUN_00236030(long param_1,char *param_2,uint param_3)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  uint uVar6;
  char *pcVar7;
  FILE *__stream;
  size_t sVar8;
  char *pcVar9;
  int *piVar10;
  long lVar11;
  undefined8 uVar12;
  float fVar13;
  double dVar14;
  float local_3c;
  
  pcVar7 = (char *)FUN_00235860("/sys/bus/pci/devices/%04x:%02x:%02x.%x/reset_method",
                                *(undefined4 *)(param_1 + 0x124),*(undefined1 *)(param_1 + 2),
                                *(undefined1 *)(param_1 + 3),*(undefined1 *)(param_1 + 4));
  if (pcVar7 == (char *)0x0) {
    return 3;
  }
  __stream = fopen(pcVar7,"r");
  if (__stream == (FILE *)0x0) {
    if (DAT_01216a78 < 2) {
      return 0x11;
    }
    piVar10 = __errno_location();
    pcVar9 = strerror(*piVar10);
    fVar13 = (float)FUN_002917b0(&DAT_01216a60);
    lVar11 = syscall(0xba);
    local_3c = DAT_00298548;
    FUN_002340f0((double)(fVar13 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s: %s\n",
                 "ERROR",lVar11,"unix.c",0x3d0,pcVar7,pcVar9);
  }
  else {
    pcVar7 = fgets(param_2,param_3,__stream);
    fclose(__stream);
    if (pcVar7 == (char *)0x0) {
      if (DAT_01216a78 < 2) {
        return 0x11;
      }
      fVar13 = (float)FUN_002917b0(&DAT_01216a60);
      lVar11 = syscall(0xba);
      uVar12 = 0x3db;
      local_3c = DAT_00298548;
      dVar14 = (double)(fVar13 * DAT_00298548);
    }
    else if (param_2 == pcVar7) {
      sVar8 = strnlen(param_2,(ulong)param_3);
      uVar6 = (uint)sVar8;
      if (param_3 == uVar6) {
        if (DAT_01216a78 < 2) {
          return 0x11;
        }
        fVar13 = (float)FUN_002917b0(&DAT_01216a60);
        lVar11 = syscall(0xba);
        uVar12 = 1000;
        local_3c = DAT_00298548;
        dVar14 = (double)(fVar13 * DAT_00298548);
      }
      else {
        if (uVar6 != 0) {
          cVar1 = pcVar7[uVar6 - 1];
          if (cVar1 == '\n') {
            pcVar7[uVar6 - 1] = '\0';
            if (3 < DAT_01216a78) {
              uVar2 = *(undefined1 *)(param_1 + 4);
              uVar3 = *(undefined1 *)(param_1 + 3);
              uVar4 = *(undefined1 *)(param_1 + 2);
              uVar5 = *(undefined4 *)(param_1 + 0x124);
              fVar13 = (float)FUN_002917b0(&DAT_01216a60);
              lVar11 = syscall(0xba);
              FUN_002340f0((double)(fVar13 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n",&DAT_002983c2,
                           lVar11,"unix.c",0x492,uVar5,uVar4,uVar3,uVar2);
            }
            pcVar9 = strchr(pcVar7,0x20);
            if (pcVar9 != (char *)0x0) {
              builtin_strncpy(pcVar7,"default",8);
            }
            return 0;
          }
          if (DAT_01216a78 < 2) {
            return 0x11;
          }
          fVar13 = (float)FUN_002917b0(&DAT_01216a60);
          lVar11 = syscall(0xba);
          local_3c = DAT_00298548;
          FUN_002340f0((double)(fVar13 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u == %c\n","ERROR",lVar11,"unix.c",0x3f8
                       ,(ulong)(uVar6 - 1),(int)cVar1);
          goto LAB_002361c2;
        }
        if (DAT_01216a78 < 2) {
          return 0x11;
        }
        fVar13 = (float)FUN_002917b0(&DAT_01216a60);
        lVar11 = syscall(0xba);
        local_3c = DAT_00298548;
        uVar12 = 0x3ee;
        dVar14 = (double)(fVar13 * DAT_00298548);
      }
    }
    else {
      if (DAT_01216a78 < 2) {
        return 0x11;
      }
      fVar13 = (float)FUN_002917b0(&DAT_01216a60);
      lVar11 = syscall(0xba);
      uVar12 = 0x3e1;
      local_3c = DAT_00298548;
      dVar14 = (double)(fVar13 * DAT_00298548);
    }
    DAT_00298548 = local_3c;
    FUN_002340f0(dVar14,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar11,"unix.c",uVar12);
  }
LAB_002361c2:
  if (DAT_01216a78 < 2) {
    return 0x11;
  }
  uVar2 = *(undefined1 *)(param_1 + 4);
  uVar3 = *(undefined1 *)(param_1 + 3);
  uVar4 = *(undefined1 *)(param_1 + 2);
  uVar5 = *(undefined4 *)(param_1 + 0x124);
  fVar13 = (float)FUN_002917b0(&DAT_01216a60);
  lVar11 = syscall(0xba);
  FUN_002340f0((double)(fVar13 * local_3c),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n",
               "ERROR",lVar11,"unix.c",0x49f,uVar5,uVar4,uVar3,uVar2);
  return 0x11;
}


// ===== 00236540 FUN_00236540 =====

undefined4 FUN_00236540(undefined8 param_1,int param_2,undefined4 *param_3,int param_4)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  float fVar5;
  byte local_3c;
  char local_3b;
  byte local_3a [10];
  
  uVar1 = FUN_0028ecf0(param_1,local_3a,6);
  if (4 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","DEBUG",
                 lVar2,"unix.c",0x14d,(ulong)uVar1);
  }
  if (uVar1 != 0) {
    if (0xd < uVar1) {
      return 999;
    }
    return *(undefined4 *)(&DAT_002dc220 + (ulong)uVar1 * 4);
  }
  if ((local_3a[0] & 0x10) != 0) {
    uVar1 = FUN_0028ecc0(param_1,&local_3c,0x34);
    if (4 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","DEBUG",
                   lVar2,"unix.c",0x157,(ulong)uVar1);
    }
    if (uVar1 != 0) {
      if (uVar1 < 0xe) {
        return *(undefined4 *)(&DAT_002dc220 + (ulong)uVar1 * 4);
      }
      return 999;
    }
    local_3c = local_3c & 0xfc;
    if (local_3c != 0) {
      do {
        uVar1 = FUN_0028ecc0(param_1,&local_3b,local_3c);
        if (4 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",
                       "DEBUG",lVar2,"unix.c",0x165,uVar1);
        }
        if (uVar1 != 0) {
LAB_00236830:
          if (uVar1 < 0xe) {
            return *(undefined4 *)(&DAT_002dc220 + (ulong)uVar1 * 4);
          }
          return 999;
        }
        if (local_3b == '\x10') {
          if (param_4 == 0) {
            uVar3 = FUN_0028ed20(param_1,param_3);
            uVar3 = uVar3 & 0xffffffff;
            if (DAT_01216a78 < 5) goto LAB_00236875;
            fVar5 = (float)FUN_002917b0(&DAT_01216a60);
            lVar2 = syscall(0xba);
            uVar4 = 0x172;
            fVar5 = fVar5 * DAT_00298548;
          }
          else {
            uVar1 = FUN_0028ee10(param_1,*param_3,(uint)local_3c + param_2);
            uVar3 = (ulong)uVar1;
            if (DAT_01216a78 < 5) goto LAB_00236875;
            fVar5 = (float)FUN_002917b0(&DAT_01216a60);
            lVar2 = syscall(0xba);
            uVar4 = 0x16d;
            fVar5 = fVar5 * DAT_00298548;
          }
          FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","DEBUG",lVar2,
                       "unix.c",uVar4,uVar3);
LAB_00236875:
          if ((uint)uVar3 == 0) {
            return 0;
          }
          if ((uint)uVar3 < 0xe) {
            return *(undefined4 *)(&DAT_002dc220 + uVar3 * 4);
          }
          return 999;
        }
        uVar1 = FUN_0028ecc0(param_1,&local_3c,(ulong)local_3c + 1);
        if (4 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",
                       "DEBUG",lVar2,"unix.c",0x179,uVar1);
        }
        if (uVar1 != 0) goto LAB_00236830;
        local_3c = local_3c & 0xfc;
      } while (local_3c != 0);
    }
  }
  return 3;
}


// ===== 00236950 FUN_00236950 =====

ulong FUN_00236950(undefined8 param_1,undefined4 *param_2)

{
  ulong uVar1;
  long lVar2;
  int iVar3;
  float fVar4;
  uint local_3c [3];
  
  iVar3 = 0xb;
  while( true ) {
    uVar1 = FUN_00236540(param_1,0x12,local_3c,0);
    if ((int)uVar1 != 0) {
      return uVar1;
    }
    uVar1 = (ulong)(local_3c[0] & 0x800);
    if ((local_3c[0] & 0x800) == 0) break;
    if (3 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar2,"unix.c",500);
    }
    if (iVar3 == 1) {
      if (DAT_01216a78 < 2) {
        return 999;
      }
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                   lVar2,"unix.c",0x1fc);
      return 999;
    }
    iVar3 = iVar3 + -1;
    sleep(0x32);
  }
  local_3c[0] = local_3c[0] & 0xf;
  if (local_3c[0] == 2) {
    *param_2 = 5000;
    return uVar1;
  }
  if (local_3c[0] == 4) {
    *param_2 = 8000;
    return uVar1;
  }
  if (local_3c[0] == 1) {
    *param_2 = 0x9c4;
    return uVar1;
  }
  return 3;
}


// ===== 00236b30 FUN_00236b30 =====

undefined8 FUN_00236b30(undefined8 param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  uint local_1c [3];
  
  uVar1 = FUN_00236540(param_1,0xc,local_1c,0);
  if ((int)uVar1 == 0) {
    local_1c[0] = local_1c[0] & 0xf;
    if (local_1c[0] == 2) {
      *param_2 = 5000;
      return uVar1;
    }
    if (local_1c[0] == 4) {
      *param_2 = 8000;
      return uVar1;
    }
    if (local_1c[0] == 1) {
      *param_2 = 0x9c4;
      return uVar1;
    }
    uVar1 = 3;
  }
  return uVar1;
}


// ===== 00236ba0 FUN_00236ba0 =====

void FUN_00236ba0(void)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  do {
    iVar1 = FUN_00291820(&DAT_01216a98,1,0);
  } while (iVar1 != 0);
  if (4 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                 lVar2,"unix.c",0x8c);
  }
  DAT_01216a94 = DAT_01216a94 + -1;
  FUN_00291830(&DAT_01216a98,0);
  return;
}


// ===== 00236c60 FUN_00236c60 =====

undefined8 FUN_00236c60(void)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  do {
    iVar1 = FUN_00291820(&DAT_01216a98,1,0);
  } while (iVar1 != 0);
  if (DAT_01216aa0 != 0) {
    if (4 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                   lVar2,"unix.c",0x7e);
    }
    DAT_01216a94 = DAT_01216a94 + 1;
    FUN_00291830(&DAT_01216a98,0);
    return 0;
  }
  if (1 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                 lVar2,"unix.c",0x7a);
  }
  FUN_00291830(&DAT_01216a98,0);
  return 0x3e9;
}


// ===== 00236dd0 FUN_00236dd0 =====

bool FUN_00236dd0(void)

{
  __uid_t _Var1;
  __uid_t _Var2;
  long lVar3;
  float fVar4;
  
  if (3 < DAT_01216a78) {
    _Var1 = getuid();
    _Var2 = geteuid();
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %d\n",
                 &DAT_002983c2,lVar3,"unix.c",0x15,_Var2,_Var1);
  }
  _Var1 = geteuid();
  return _Var1 == 0;
}


// ===== 00236e80 FUN_00236e80 =====

undefined8 FUN_00236e80(void)

{
  uint __errnum;
  int iVar1;
  FILE *__stream;
  uint *puVar2;
  undefined8 uVar3;
  char *pcVar4;
  long lVar5;
  float fVar6;
  char local_37 [15];
  
  builtin_strncpy(local_37,"/dev/nvidiactl",0xf);
  __stream = fopen(local_37,"r");
  iVar1 = DAT_01216a78;
  if (__stream == (FILE *)0x0) {
    puVar2 = (uint *)__errno_location();
    if (0 < iVar1) {
      __errnum = *puVar2;
      pcVar4 = strerror(__errnum);
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %s %d\n",
                   "CRITICAL",lVar5,"unix.c",0x25,local_37,pcVar4,__errnum);
    }
    if (*puVar2 == 0xd) {
      uVar3 = 4;
    }
    else {
      uVar3 = 999;
      if ((*puVar2 & 0xfffffffb) == 2) {
        uVar3 = 9;
      }
    }
    return uVar3;
  }
  fclose(__stream);
  return 0;
}


// ===== 00236fb0 FUN_00236fb0 =====

undefined4 FUN_00236fb0(void)

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


// ===== 00237220 FUN_00237220 =====

undefined8 FUN_00237220(void)

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


// ===== 00237450 FUN_00237450 =====

int FUN_00237450(int *param_1)

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


// ===== 00237550 FUN_00237550 =====

int FUN_00237550(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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


// ===== 00237700 FUN_00237700 =====

int FUN_00237700(long param_1,long param_2)

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


// ===== 002377e0 FUN_002377e0 =====

int FUN_002377e0(undefined8 param_1,undefined8 param_2)

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


// ===== 002378a0 FUN_002378a0 =====

int FUN_002378a0(undefined8 param_1,undefined4 *param_2)

{
  int iVar1;
  long lVar2;
  float fVar3;
  uint local_2c [3];
  
  iVar1 = FUN_00236c60();
  if (iVar1 == 0) {
    iVar1 = FUN_00236540(param_1,0xc,local_2c,0);
    if (iVar1 == 0) {
      switch(local_2c[0] >> 4 & 0x3f) {
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


// ===== 00237a10 FUN_00237a10 =====

int FUN_00237a10(long param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int iVar5;
  long lVar6;
  int iVar7;
  float fVar8;
  uint local_3c [3];
  
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
    while (iVar5 = FUN_00236540(param_1,0x12,local_3c,0), iVar5 == 0) {
      if ((local_3c[0] & 0x800) == 0) {
        iVar5 = 0;
        switch(local_3c[0] >> 4 & 0x3f) {
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


// ===== 00237d50 FUN_00237d50 =====

int FUN_00237d50(long param_1,uint *param_2)

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


// ===== 00237e20 FUN_00237e20 =====

int FUN_00237e20(long param_1,uint *param_2)

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


// ===== 00237ef0 FUN_00237ef0 =====

int FUN_00237ef0(long param_1,long param_2,long param_3,long param_4)

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


// ===== 00237fe0 FUN_00237fe0 =====

int FUN_00237fe0(long param_1,long *param_2)

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
  int local_44;
  int local_40;
  undefined1 local_3c [12];
  
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
            iVar6 = FUN_00235db0(lVar8,&local_44,&local_40,local_3c);
            if (iVar6 != 0) {
              FUN_0028e4b0(lVar7);
              break;
            }
            if ((((local_44 == 0) || ((local_44 == 6 && ((local_40 == 4 || (local_40 == 9)))))) &&
                (lVar9 = FUN_0028e180(lVar8), lVar9 != 0)) &&
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


// ===== 002383e0 FUN_002383e0 =====

int FUN_002383e0(long param_1,undefined4 *param_2,uint *param_3,uint *param_4,uint *param_5)

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


// ===== 002384f0 FUN_002384f0 =====

int FUN_002384f0(long param_1,uint *param_2)

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


// ===== 002385c0 FUN_002385c0 =====

int FUN_002385c0(long param_1,uint *param_2)

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


// ===== 00238690 FUN_00238690 =====

int FUN_00238690(long param_1,undefined4 *param_2)

{
  int iVar1;
  long lVar2;
  float fVar3;
  int local_2c [3];
  
  iVar1 = FUN_00236c60();
  if (iVar1 != 0) {
    return iVar1;
  }
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    iVar1 = 2;
  }
  else {
    iVar1 = FUN_00236b30(param_1,local_2c);
    if (iVar1 == 0) {
      if (local_2c[0] == 5000) {
        *param_2 = 2;
      }
      else if (local_2c[0] == 8000) {
        *param_2 = 3;
      }
      else if (local_2c[0] == 0x9c4) {
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


// ===== 002387c0 FUN_002387c0 =====

int FUN_002387c0(long param_1,undefined4 *param_2)

{
  int iVar1;
  long lVar2;
  float fVar3;
  int local_2c [3];
  
  iVar1 = FUN_00236c60();
  if (iVar1 != 0) {
    return iVar1;
  }
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    iVar1 = 2;
  }
  else {
    iVar1 = FUN_00236950(param_1,local_2c);
    if (iVar1 == 0) {
      if (local_2c[0] == 5000) {
        *param_2 = 2;
      }
      else if (local_2c[0] == 8000) {
        *param_2 = 3;
      }
      else if (local_2c[0] == 0x9c4) {
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


// ===== 002388f0 FUN_002388f0 =====

int FUN_002388f0(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  iVar1 = FUN_00236c60();
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = FUN_002358f0(param_1);
  if (4 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                 lVar2,"unix.c",0x401,iVar1);
  }
  FUN_00236ba0();
  return iVar1;
}


// ===== 002389b0 FUN_002389b0 =====

int FUN_002389b0(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  iVar1 = FUN_00236c60();
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = FUN_00235be0(param_1);
  if (4 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                 lVar2,"unix.c",0x414,iVar1);
  }
  FUN_00236ba0();
  return iVar1;
}


// ===== 00238a70 FUN_00238a70 =====

int FUN_00238a70(long param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int iVar5;
  char *__resolved;
  char *__name;
  long lVar6;
  int *piVar7;
  char *pcVar8;
  undefined8 uVar9;
  float fVar10;
  
  iVar5 = FUN_00236c60();
  if (iVar5 != 0) {
    return iVar5;
  }
  if (param_1 == 0) {
    iVar5 = 2;
    goto LAB_00238b89;
  }
  __resolved = malloc(0x1000);
  if (__resolved == (char *)0x0) {
    iVar5 = 0x14;
    if (1 < DAT_01216a78) {
      uVar1 = *(undefined1 *)(param_1 + 4);
      uVar2 = *(undefined1 *)(param_1 + 3);
      uVar3 = *(undefined1 *)(param_1 + 2);
      uVar4 = *(undefined4 *)(param_1 + 0x124);
      fVar10 = (float)FUN_002917b0(&DAT_01216a60);
      lVar6 = syscall(0xba);
      FUN_002340f0((double)(fVar10 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n","ERROR",lVar6,"unix.c",
                   0x4b7,uVar4,uVar3,uVar2,uVar1,param_4);
    }
    goto LAB_00238b89;
  }
  __name = (char *)FUN_00235860("/sys/bus/pci/devices/%04x:%02x:%02x.%x/driver",
                                *(undefined4 *)(param_1 + 0x124),*(undefined1 *)(param_1 + 2),
                                *(undefined1 *)(param_1 + 3),*(undefined1 *)(param_1 + 4));
  if (__name == (char *)0x0) {
    iVar5 = 0x11;
    if (1 < DAT_01216a78) {
      uVar1 = *(undefined1 *)(param_1 + 4);
      uVar2 = *(undefined1 *)(param_1 + 3);
      uVar3 = *(undefined1 *)(param_1 + 2);
      uVar4 = *(undefined4 *)(param_1 + 0x124);
      fVar10 = (float)FUN_002917b0(&DAT_01216a60);
      lVar6 = syscall(0xba);
      uVar9 = 0x4c1;
      fVar10 = fVar10 * DAT_00298548;
LAB_00238cbc:
      FUN_002340f0((double)fVar10,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n","ERROR",
                   lVar6,"unix.c",uVar9,uVar4,uVar3,uVar2,uVar1);
    }
LAB_00238bc0:
    free(__resolved);
  }
  else {
    __resolved = realpath(__name,__resolved);
    if (__resolved == (char *)0x0) {
      iVar5 = 0x11;
      if (1 < DAT_01216a78) {
        piVar7 = __errno_location();
        pcVar8 = strerror(*piVar7);
        fVar10 = (float)FUN_002917b0(&DAT_01216a60);
        lVar6 = syscall(0xba);
        FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s: %s\n",
                     "ERROR",lVar6,"unix.c",0x4cb,__name,pcVar8);
      }
      goto LAB_00238bc0;
    }
    free(__name);
    __name = (char *)FUN_00235860("%s/unbind",__resolved);
    if (__name == (char *)0x0) {
      iVar5 = 0x11;
      if (1 < DAT_01216a78) {
        fVar10 = (float)FUN_002917b0(&DAT_01216a60);
        lVar6 = syscall(0xba);
        FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n",
                     "ERROR",lVar6,"unix.c",0x4d5,__resolved);
      }
      goto LAB_00238bc0;
    }
    iVar5 = FUN_002359d0(__name,"%04x:%02x:%02x.%x",*(undefined4 *)(param_1 + 0x124),
                         *(undefined1 *)(param_1 + 2),*(undefined1 *)(param_1 + 3),
                         *(undefined1 *)(param_1 + 4));
    if (iVar5 != 0) {
      if (1 < DAT_01216a78) {
        uVar1 = *(undefined1 *)(param_1 + 4);
        uVar2 = *(undefined1 *)(param_1 + 3);
        uVar3 = *(undefined1 *)(param_1 + 2);
        uVar4 = *(undefined4 *)(param_1 + 0x124);
        fVar10 = (float)FUN_002917b0(&DAT_01216a60);
        lVar6 = syscall(0xba);
        uVar9 = 0x4de;
        fVar10 = fVar10 * DAT_00298548;
        goto LAB_00238cbc;
      }
      goto LAB_00238bc0;
    }
    if (3 < DAT_01216a78) {
      uVar1 = *(undefined1 *)(param_1 + 4);
      uVar2 = *(undefined1 *)(param_1 + 3);
      uVar3 = *(undefined1 *)(param_1 + 2);
      uVar4 = *(undefined4 *)(param_1 + 0x124);
      fVar10 = (float)FUN_002917b0(&DAT_01216a60);
      lVar6 = syscall(0xba);
      FUN_002340f0((double)(fVar10 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x %s\n",&DAT_002983c2,lVar6,
                   "unix.c",0x4e4,uVar4,uVar3,uVar2,uVar1,__resolved);
    }
    if (param_2 == (undefined8 *)0x0) goto LAB_00238bc0;
    *param_2 = __resolved;
  }
  free(__name);
LAB_00238b89:
  if (4 < DAT_01216a78) {
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                 lVar6,"unix.c",0x4a7,iVar5);
  }
  FUN_00236ba0();
  return iVar5;
}


// ===== 00238fc0 FUN_00238fc0 =====

int FUN_00238fc0(long param_1,long param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int iVar5;
  void *__ptr;
  long lVar6;
  float fVar7;
  
  iVar5 = FUN_00236c60();
  if (iVar5 == 0) {
    if ((param_1 == 0) || (param_2 == 0)) {
      iVar5 = 2;
    }
    else {
      __ptr = (void *)FUN_00235860("%s/bind",param_2);
      if (__ptr == (void *)0x0) {
        iVar5 = 0x11;
        if (1 < DAT_01216a78) {
          fVar7 = (float)FUN_002917b0(&DAT_01216a60);
          lVar6 = syscall(0xba);
          FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n",
                       "ERROR",lVar6,"unix.c",0x501,param_2);
        }
      }
      else {
        iVar5 = FUN_002359d0(__ptr,"%04x:%02x:%02x.%x",*(undefined4 *)(param_1 + 0x124),
                             *(undefined1 *)(param_1 + 2),*(undefined1 *)(param_1 + 3),
                             *(undefined1 *)(param_1 + 4));
        if (iVar5 == 0) {
          if (3 < DAT_01216a78) {
            uVar1 = *(undefined1 *)(param_1 + 4);
            uVar2 = *(undefined1 *)(param_1 + 3);
            uVar3 = *(undefined1 *)(param_1 + 2);
            uVar4 = *(undefined4 *)(param_1 + 0x124);
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar6 = syscall(0xba);
            FUN_002340f0((double)(fVar7 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x %s\n",&DAT_002983c2,
                         lVar6,"unix.c",0x510,uVar4,uVar3,uVar2,uVar1,param_2);
          }
        }
        else if (1 < DAT_01216a78) {
          uVar1 = *(undefined1 *)(param_1 + 4);
          uVar2 = *(undefined1 *)(param_1 + 3);
          uVar3 = *(undefined1 *)(param_1 + 2);
          uVar4 = *(undefined4 *)(param_1 + 0x124);
          fVar7 = (float)FUN_002917b0(&DAT_01216a60);
          lVar6 = syscall(0xba);
          FUN_002340f0((double)(fVar7 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n","ERROR",lVar6,
                       "unix.c",0x50a,uVar4,uVar3,uVar2,uVar1);
        }
      }
      free(__ptr);
    }
    if (4 < DAT_01216a78) {
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar6 = syscall(0xba);
      FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                   lVar6,"unix.c",0x4f2,iVar5);
    }
    FUN_00236ba0();
  }
  return iVar5;
}


// ===== 00239290 FUN_00239290 =====

int FUN_00239290(long param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int iVar5;
  void *__ptr;
  long lVar6;
  char *pcVar7;
  undefined8 uVar8;
  float fVar9;
  
  iVar5 = FUN_00236c60();
  if (iVar5 != 0) {
    return iVar5;
  }
  if (param_1 == 0) {
    iVar5 = 2;
  }
  else {
    __ptr = (void *)FUN_00235860("/sys/bus/pci/devices/%04x:%02x:%02x.%x/remove",
                                 *(undefined4 *)(param_1 + 0x124),*(undefined1 *)(param_1 + 2),
                                 *(undefined1 *)(param_1 + 3),*(undefined1 *)(param_1 + 4));
    if (__ptr == (void *)0x0) {
      iVar5 = 0x11;
    }
    else {
      iVar5 = FUN_002359d0(__ptr,"1");
      free(__ptr);
      if (iVar5 == 0) {
        if (DAT_01216a78 < 4) goto LAB_0023932f;
        uVar1 = *(undefined1 *)(param_1 + 4);
        uVar2 = *(undefined1 *)(param_1 + 3);
        uVar3 = *(undefined1 *)(param_1 + 2);
        uVar4 = *(undefined4 *)(param_1 + 0x124);
        fVar9 = (float)FUN_002917b0(&DAT_01216a60);
        lVar6 = syscall(0xba);
        fVar9 = fVar9 * DAT_00298548;
        uVar8 = 0x536;
        pcVar7 = "INFO";
      }
      else {
        if (DAT_01216a78 < 2) goto LAB_0023932f;
        uVar1 = *(undefined1 *)(param_1 + 4);
        uVar2 = *(undefined1 *)(param_1 + 3);
        uVar3 = *(undefined1 *)(param_1 + 2);
        uVar4 = *(undefined4 *)(param_1 + 0x124);
        fVar9 = (float)FUN_002917b0(&DAT_01216a60);
        lVar6 = syscall(0xba);
        fVar9 = fVar9 * DAT_00298548;
        uVar8 = 0x530;
        pcVar7 = "ERROR";
      }
      FUN_002340f0((double)fVar9,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n",pcVar7,
                   lVar6,"unix.c",uVar8,uVar4,uVar3,uVar2,uVar1);
    }
  }
  if (4 < DAT_01216a78) {
    fVar9 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                 lVar6,"unix.c",0x51a,iVar5);
    FUN_00236ba0();
    return iVar5;
  }
LAB_0023932f:
  FUN_00236ba0();
  return iVar5;
}


// ===== 002394e0 FUN_002394e0 =====

int FUN_002394e0(long param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int iVar5;
  void *__ptr;
  long lVar6;
  char *pcVar7;
  undefined8 uVar8;
  float fVar9;
  
  iVar5 = FUN_00236c60();
  if (iVar5 != 0) {
    return iVar5;
  }
  if (param_1 == 0) {
    iVar5 = 2;
  }
  else {
    __ptr = (void *)FUN_00235860("/sys/bus/pci/devices/%04x:%02x:%02x.%x/rescan",
                                 *(undefined4 *)(param_1 + 0x124),*(undefined1 *)(param_1 + 2),
                                 *(undefined1 *)(param_1 + 3),*(undefined1 *)(param_1 + 4));
    if (__ptr == (void *)0x0) {
      iVar5 = 0x11;
    }
    else {
      iVar5 = FUN_002359d0(__ptr,"1");
      free(__ptr);
      if (iVar5 == 0) {
        if (DAT_01216a78 < 4) goto LAB_0023957f;
        uVar1 = *(undefined1 *)(param_1 + 4);
        uVar2 = *(undefined1 *)(param_1 + 3);
        uVar3 = *(undefined1 *)(param_1 + 2);
        uVar4 = *(undefined4 *)(param_1 + 0x124);
        fVar9 = (float)FUN_002917b0(&DAT_01216a60);
        lVar6 = syscall(0xba);
        fVar9 = fVar9 * DAT_00298548;
        uVar8 = 0x557;
        pcVar7 = "INFO";
      }
      else {
        if (DAT_01216a78 < 2) goto LAB_0023957f;
        uVar1 = *(undefined1 *)(param_1 + 4);
        uVar2 = *(undefined1 *)(param_1 + 3);
        uVar3 = *(undefined1 *)(param_1 + 2);
        uVar4 = *(undefined4 *)(param_1 + 0x124);
        fVar9 = (float)FUN_002917b0(&DAT_01216a60);
        lVar6 = syscall(0xba);
        fVar9 = fVar9 * DAT_00298548;
        uVar8 = 0x551;
        pcVar7 = "ERROR";
      }
      FUN_002340f0((double)fVar9,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n",pcVar7,
                   lVar6,"unix.c",uVar8,uVar4,uVar3,uVar2,uVar1);
    }
  }
  if (4 < DAT_01216a78) {
    fVar9 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                 lVar6,"unix.c",0x53d,iVar5);
    FUN_00236ba0();
    return iVar5;
  }
LAB_0023957f:
  FUN_00236ba0();
  return iVar5;
}


// ===== 00239730 FUN_00239730 =====

int FUN_00239730(void *param_1)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  iVar1 = FUN_00236c60();
  if (iVar1 == 0) {
    if (param_1 != (void *)0x0) {
      free(param_1);
    }
    if (4 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                   lVar2,"unix.c",0x55e,0);
    }
    FUN_00236ba0();
  }
  return iVar1;
}


// ===== 002397e0 FUN_002397e0 =====

int FUN_002397e0(long param_1,int param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  float fVar7;
  double dVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined1 local_64 [2];
  byte local_62;
  uint local_60;
  undefined1 local_5c;
  byte local_5b;
  timeval local_58;
  timeval local_48;
  
  iVar1 = FUN_00236c60();
  if (iVar1 != 0) {
    return iVar1;
  }
  if (param_1 == 0) {
    iVar1 = 2;
  }
  else {
    iVar1 = FUN_00236540(param_1,0x10,&local_60,0);
    if (iVar1 == 0) {
      if (param_2 == 0) {
        local_60 = local_60 | 0x10;
        local_48.tv_sec._0_4_ = local_60;
        iVar1 = FUN_00236540(param_1,0x10,&local_48,1);
        if (iVar1 == 0) goto LAB_0023987e;
      }
      else {
        local_60 = local_60 & 0xffffffef;
        local_48.tv_sec._0_4_ = local_60;
        iVar1 = FUN_00236540(param_1,0x10,&local_48,1);
        if (iVar1 == 0) {
          iVar1 = FUN_00236540(param_1,0xc,local_64,0);
          if (iVar1 == 0) {
            if ((local_62 & 0x10) == 0) {
              usleep(30000);
LAB_00239bca:
              usleep(100000);
              goto LAB_0023987e;
            }
            gettimeofday(&local_58,(__timezone_ptr_t)0x0);
            do {
              iVar2 = FUN_00236540(param_1,0x12,&local_5c,0);
              if (iVar2 != 0) {
                iVar1 = iVar2;
                if (DAT_01216a78 < 2) goto LAB_002398dc;
                uVar11 = *(undefined1 *)(param_1 + 4);
                uVar10 = *(undefined1 *)(param_1 + 3);
                uVar9 = *(undefined1 *)(param_1 + 2);
                uVar6 = *(undefined4 *)(param_1 + 0x124);
                fVar7 = (float)FUN_002917b0(&DAT_01216a60);
                lVar3 = syscall(0xba);
                uVar5 = 0x5bc;
                dVar8 = (double)(fVar7 * DAT_00298548);
                goto LAB_002399f1;
              }
              if ((local_5b & 0x20) != 0) goto LAB_00239bca;
              gettimeofday(&local_48,(__timezone_ptr_t)0x0);
              lVar4 = CONCAT44(local_48.tv_sec._4_4_,(uint)local_48.tv_sec) - local_58.tv_sec;
              lVar3 = local_48.tv_usec - local_58.tv_usec;
              if (lVar3 < 0) {
                lVar4 = lVar4 + -1;
                lVar3 = lVar3 + 1000000;
              }
            } while ((lVar3 < 200000) && (lVar4 < 1));
            iVar1 = 10;
            if (DAT_01216a78 < 2) goto LAB_002398dc;
            uVar11 = *(undefined1 *)(param_1 + 4);
            uVar10 = *(undefined1 *)(param_1 + 3);
            uVar9 = *(undefined1 *)(param_1 + 2);
            uVar6 = *(undefined4 *)(param_1 + 0x124);
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            uVar5 = 0x5cd;
            dVar8 = (double)(fVar7 * DAT_00298548);
          }
          else {
            if (DAT_01216a78 < 2) goto LAB_002398dc;
            uVar11 = *(undefined1 *)(param_1 + 4);
            uVar10 = *(undefined1 *)(param_1 + 3);
            uVar9 = *(undefined1 *)(param_1 + 2);
            uVar6 = *(undefined4 *)(param_1 + 0x124);
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            uVar5 = 0x5aa;
            dVar8 = (double)(fVar7 * DAT_00298548);
          }
          goto LAB_002399f1;
        }
      }
      if (DAT_01216a78 < 2) goto LAB_002398dc;
      uVar11 = *(undefined1 *)(param_1 + 4);
      uVar10 = *(undefined1 *)(param_1 + 3);
      uVar9 = *(undefined1 *)(param_1 + 2);
      uVar6 = *(undefined4 *)(param_1 + 0x124);
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      uVar5 = 0x599;
      dVar8 = (double)(fVar7 * DAT_00298548);
    }
    else {
      if (DAT_01216a78 < 2) goto LAB_002398dc;
      uVar11 = *(undefined1 *)(param_1 + 4);
      uVar10 = *(undefined1 *)(param_1 + 3);
      uVar9 = *(undefined1 *)(param_1 + 2);
      uVar6 = *(undefined4 *)(param_1 + 0x124);
      fVar7 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      uVar5 = 0x584;
      dVar8 = (double)(fVar7 * DAT_00298548);
    }
LAB_002399f1:
    FUN_002340f0(dVar8,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n","ERROR",lVar3,
                 "unix.c",uVar5,uVar6,uVar9,uVar10,uVar11);
  }
LAB_0023987e:
  if (4 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG",
                 lVar3,"unix.c",0x570,iVar1);
  }
LAB_002398dc:
  FUN_00236ba0();
  return iVar1;
}


// ===== 00239c50 FUN_00239c50 =====

float FUN_00239c50(long param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  long lVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined8 uVar9;
  undefined4 uVar10;
  float fVar11;
  bool bVar12;
  bool bVar13;
  byte bVar14;
  double dVar15;
  byte abStack_138 [112];
  undefined1 auStack_c8 [104];
  undefined8 uStack_60;
  float local_50;
  float local_4c;
  float local_48;
  uint local_44;
  uint local_40;
  float local_3c;
  
  bVar14 = 0;
  uStack_60 = 0x239c69;
  fVar3 = (float)FUN_00236c60();
  if (fVar3 != 0.0) {
    return fVar3;
  }
  if (param_1 == 0) {
    fVar3 = 2.8026e-45;
    if (1 < DAT_01216a78) {
      local_3c = (float)FUN_002917b0(&DAT_01216a60);
      lVar6 = syscall(0xba);
      FUN_002340f0((double)(local_3c * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR"
                   ,lVar6,"unix.c",0x70b);
    }
    goto LAB_00239e30;
  }
  iVar4 = FUN_002358f0(param_1);
  if (iVar4 == 0) {
    iVar4 = FUN_00235960(param_1);
    if (iVar4 == 0) {
      iVar4 = FUN_00236030(param_1,auStack_c8,100);
      if (iVar4 != 0) {
        fVar3 = 2.38221e-44;
        if (1 < DAT_01216a78) {
          uVar1 = *(undefined1 *)(param_1 + 2);
          local_44 = (uint)*(byte *)(param_1 + 4);
          uVar10 = *(undefined4 *)(param_1 + 0x124);
          local_40 = (uint)*(byte *)(param_1 + 3);
          local_3c = (float)FUN_002917b0(&DAT_01216a60);
          lVar6 = syscall(0xba);
          FUN_002340f0((double)(local_3c * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n","ERROR",lVar6,
                       "unix.c",0x729,uVar10,uVar1,local_40,local_44);
        }
        goto LAB_00239e30;
      }
      local_3c = (float)FUN_00235e80(param_1,&DAT_002dc1d6);
      if (local_3c == 0.0) {
        local_3c = (float)FUN_00236030(param_1,abStack_138,100);
        bVar12 = false;
        if (local_3c == 0.0) {
          lVar6 = 4;
          bVar13 = true;
          pbVar7 = &DAT_002dc1d6;
          pbVar8 = abStack_138;
          do {
            if (lVar6 == 0) break;
            lVar6 = lVar6 + -1;
            bVar12 = *pbVar7 < *pbVar8;
            bVar13 = *pbVar7 == *pbVar8;
            pbVar7 = pbVar7 + (ulong)bVar14 * -2 + 1;
            pbVar8 = pbVar8 + (ulong)bVar14 * -2 + 1;
          } while (bVar13);
          if ((!bVar12 && !bVar13) == bVar12) {
            local_3c = (float)FUN_00235be0(param_1);
            if ((local_3c != 0.0) && (1 < DAT_01216a78)) {
              local_48 = (float)(uint)*(byte *)(param_1 + 4);
              uVar10 = *(undefined4 *)(param_1 + 0x124);
              local_44 = (uint)*(byte *)(param_1 + 3);
              local_40 = (uint)*(byte *)(param_1 + 2);
              local_4c = local_3c;
              local_3c = (float)FUN_002917b0(&DAT_01216a60);
              lVar6 = syscall(0xba);
              uVar9 = 0x750;
              dVar15 = (double)(local_3c * DAT_00298548);
              goto LAB_0023a0df;
            }
          }
          else {
            local_3c = 2.38221e-44;
            if (1 < DAT_01216a78) {
              local_50 = 2.38221e-44;
              local_40 = *(uint *)(param_1 + 0x124);
              local_4c = (float)(uint)*(byte *)(param_1 + 4);
              local_48 = (float)(uint)*(byte *)(param_1 + 3);
              local_44 = (uint)*(byte *)(param_1 + 2);
              local_3c = (float)FUN_002917b0(&DAT_01216a60);
              lVar6 = syscall(0xba);
              FUN_002340f0((double)(local_3c * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x : %s!=%s\n","ERROR"
                           ,lVar6,"unix.c",0x744,local_40,local_44,local_48,local_4c,abStack_138,
                           &DAT_002dc1d6);
              local_3c = local_50;
            }
          }
        }
        else if (1 < DAT_01216a78) {
          local_48 = (float)(uint)*(byte *)(param_1 + 4);
          uVar10 = *(undefined4 *)(param_1 + 0x124);
          local_44 = (uint)*(byte *)(param_1 + 3);
          local_40 = (uint)*(byte *)(param_1 + 2);
          local_4c = local_3c;
          local_3c = (float)FUN_002917b0(&DAT_01216a60);
          lVar6 = syscall(0xba);
          uVar9 = 0x73c;
          dVar15 = (double)(local_3c * DAT_00298548);
          goto LAB_0023a0df;
        }
      }
      else if (1 < DAT_01216a78) {
        local_48 = (float)(uint)*(byte *)(param_1 + 4);
        uVar10 = *(undefined4 *)(param_1 + 0x124);
        local_44 = (uint)*(byte *)(param_1 + 3);
        local_40 = (uint)*(byte *)(param_1 + 2);
        local_4c = local_3c;
        local_3c = (float)FUN_002917b0(&DAT_01216a60);
        lVar6 = syscall(0xba);
        uVar9 = 0x732;
        dVar15 = (double)(local_3c * DAT_00298548);
LAB_0023a0df:
        FUN_002340f0(dVar15,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n","ERROR",lVar6,
                     "unix.c",uVar9,uVar10,local_40,local_44,local_48);
        local_3c = local_4c;
      }
      fVar5 = (float)FUN_00235e80(param_1,auStack_c8);
      fVar3 = local_3c;
      if (fVar5 != 0.0) {
        fVar11 = local_3c;
        if (1 < DAT_01216a78) {
          local_48 = local_3c;
          uVar1 = *(undefined1 *)(param_1 + 2);
          local_44 = (uint)*(byte *)(param_1 + 4);
          uVar10 = *(undefined4 *)(param_1 + 0x124);
          local_40 = (uint)*(byte *)(param_1 + 3);
          local_3c = (float)FUN_002917b0(&DAT_01216a60);
          lVar6 = syscall(0xba);
          FUN_002340f0((double)(local_3c * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n","ERROR",lVar6,
                       "unix.c",0x75c,uVar10,uVar1,local_40,local_44);
          fVar11 = local_48;
        }
        fVar3 = fVar5;
        if (fVar11 != 0.0) {
          fVar3 = fVar11;
        }
      }
      goto LAB_00239e30;
    }
    if (1 < DAT_01216a78) {
      uVar1 = *(undefined1 *)(param_1 + 3);
      uVar2 = *(undefined1 *)(param_1 + 2);
      local_40 = (uint)*(byte *)(param_1 + 4);
      uVar10 = *(undefined4 *)(param_1 + 0x124);
      local_3c = (float)FUN_002917b0(&DAT_01216a60);
      lVar6 = syscall(0xba);
      fVar3 = local_3c * DAT_00298548;
      uVar9 = 0x71e;
      goto LAB_00239f17;
    }
  }
  else if (1 < DAT_01216a78) {
    uVar1 = *(undefined1 *)(param_1 + 3);
    uVar2 = *(undefined1 *)(param_1 + 2);
    local_40 = (uint)*(byte *)(param_1 + 4);
    uVar10 = *(undefined4 *)(param_1 + 0x124);
    local_3c = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    fVar3 = local_3c * DAT_00298548;
    uVar9 = 0x715;
LAB_00239f17:
    FUN_002340f0((double)fVar3,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n","ERROR",
                 lVar6,"unix.c",uVar9,uVar10,uVar2,uVar1,local_40);
  }
  fVar3 = 4.2039e-45;
LAB_00239e30:
  if (4 < DAT_01216a78) {
    uStack_60 = 0x239e54;
    local_3c = (float)FUN_002917b0(&DAT_01216a60);
    uStack_60 = 0x239e65;
    lVar6 = syscall(0xba);
    uStack_60 = 0x239ea1;
    FUN_002340f0((double)(local_3c * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","DEBUG"
                 ,lVar6,"unix.c",0x6fe,fVar3);
  }
  uStack_60 = 0x239e3f;
  FUN_00236ba0();
  return fVar3;
}


// ===== 0023a340 FUN_0023a340 =====

undefined1  [16] FUN_0023a340(long param_1,long param_2,uint *param_3)

{
  ulong uVar1;
  ulong uVar2;
  undefined1 auVar3 [16];
  undefined4 local_38;
  undefined1 auStack_34 [12];
  undefined1 local_28 [16];
  
  local_28 = (undefined1  [16])0x0;
  auStack_34 = SUB1612((undefined1  [16])0x0,4);
  local_38 = *(undefined4 *)(param_2 + 0x256e0);
  uVar1 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,DAT_0038088c,0x205,&local_38,
                       0x20);
  uVar2 = 0;
  if ((uint)uVar1 < 0x67) {
    uVar2 = (long)&switchD_0023a3a1::switchdataD_002dc258 +
            (long)(int)(&switchD_0023a3a1::switchdataD_002dc258)[uVar1 & 0xffffffff];
    switch(uVar1 & 0xffffffff) {
    case 0:
      uVar2 = (ulong)(uint)local_28._12_4_;
      if (local_28._12_4_ != 0xffffffff) {
        *param_3 = local_28._12_4_;
        break;
      }
    case 0x56:
      uVar1 = 3;
      break;
    default:
      goto switchD_0023a3a1_caseD_1;
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
    case 0x59:
      uVar1 = 0x11;
      break;
    case 0x62:
      uVar1 = 0x10;
    }
  }
  else {
switchD_0023a3a1_caseD_1:
    uVar1 = 999;
  }
  auVar3._8_8_ = uVar2;
  auVar3._0_8_ = uVar1;
  return auVar3;
}


// ===== 0023a420 FUN_0023a420 =====

undefined4 FUN_0023a420(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 local_c;
  
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x20) != 0)) &&
     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0x80), pcVar1 != (code *)0x0)) {
    iVar2 = (*pcVar1)(DAT_012164a0,&local_c);
    if (iVar2 == 0) {
      return local_c;
    }
    return 0;
  }
  return 0;
}


// ===== 0023a470 FUN_0023a470 =====

undefined4 FUN_0023a470(long param_1,undefined8 param_2)

{
  int iVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  code *pcVar8;
  undefined *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined8 *puVar12;
  ulong uVar13;
  long lVar14;
  undefined8 *puVar15;
  undefined **ppuVar16;
  uint uVar17;
  byte bVar18;
  float fVar19;
  uint local_23c;
  undefined8 local_238;
  ushort local_230 [2];
  byte abStack_22c [508];
  
  bVar18 = 0;
  puVar15 = &local_238;
  puVar12 = puVar15;
  for (lVar14 = 0x40; lVar14 != 0; lVar14 = lVar14 + -1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  uVar10 = FUN_0019d9d0(*(undefined8 *)(param_1 + 0x10),param_2,puVar15);
  local_23c = 0;
  if (DAT_01214898 != 0) {
    uVar17 = 0;
    local_23c = 0;
    do {
      if (4 < DAT_01216a78) {
        uVar3 = *(undefined2 *)((long)puVar15 + 10);
        uVar4 = *(undefined2 *)(puVar15 + 1);
        uVar11 = *(undefined4 *)puVar15;
        bVar2 = abStack_22c[(ulong)uVar17 * 0x10];
        fVar19 = (float)FUN_002917b0(&DAT_01216a60);
        lVar14 = syscall(0xba);
        FUN_002340f0((double)(fVar19 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %d %d %d %x %x\n","DEBUG",lVar14,
                     "dmal/rm/rm_nvml.c",0x33,uVar17,bVar2 & 1,bVar2 >> 1 & 1,uVar11,uVar4,uVar3);
      }
      if ((abStack_22c[(ulong)uVar17 * 0x10] & 1) == 0) {
        puVar12 = malloc(0x1a0);
        puVar9 = PTR_DAT_0032ef90;
        *(undefined8 **)(PTR_DAT_0032ef90 + (ulong)local_23c * 0x74a00 + 0x25770) = puVar12;
        if (puVar12 == (undefined8 *)0x0) {
          return 0x14;
        }
        uVar11 = *(undefined4 *)puVar15;
        uVar5 = *(undefined4 *)((long)puVar15 + 4);
        *(uint *)(puVar9 + (ulong)local_23c * 0x74a00 + 0x9c) = local_23c;
        uVar3 = *(undefined2 *)(puVar15 + 1);
        uVar4 = *(undefined2 *)((long)puVar15 + 10);
        *(undefined4 *)(puVar9 + (ulong)local_23c * 0x74a00 + 0x25778) = uVar11;
        ppuVar16 = &PTR_s_RMFunctions_0037ed00;
        for (lVar14 = 0x34; lVar14 != 0; lVar14 = lVar14 + -1) {
          *puVar12 = *ppuVar16;
          ppuVar16 = ppuVar16 + (ulong)bVar18 * -2 + 1;
          puVar12 = puVar12 + (ulong)bVar18 * -2 + 1;
        }
        *(undefined4 *)(puVar9 + (ulong)local_23c * 0x74a00 + 0xa0) = uVar5;
        *(undefined2 *)(puVar9 + (ulong)local_23c * 0x74a00 + 0xa4) = uVar3;
        *(undefined2 *)(puVar9 + (ulong)local_23c * 0x74a00 + 0xa6) = uVar4;
        if (4 < DAT_01216a78) {
          fVar19 = (float)FUN_002917b0(&DAT_01216a60);
          lVar14 = syscall(0xba);
          FUN_002340f0((double)(fVar19 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u 0x%X %u %u %u\n","DEBUG",lVar14,
                       "dmal/rm/rm_nvml.c",0x6d,local_23c,uVar11,uVar5,uVar3,uVar4);
        }
        local_23c = local_23c + 1;
      }
      else if ((abStack_22c[(ulong)uVar17 * 0x10] & 2) != 0) {
        uVar13 = (ulong)DAT_01215b90;
        DAT_01215b90 = DAT_01215b90 + 1;
        lVar14 = uVar13 * 0x48;
        *(undefined4 *)(&DAT_01215b94 + lVar14) = *(undefined4 *)puVar15;
        (&DAT_01215ba8)[uVar13 * 0x12] = *(undefined4 *)((long)puVar15 + 4);
        (&DAT_01215bac)[uVar13 * 0x12] = (uint)*(ushort *)(puVar15 + 1);
        (&DAT_01215bb0)[uVar13 * 0x12] = (uint)*(ushort *)((long)puVar15 + 10);
        FUN_0013ace0(3,&DAT_01215b98 + lVar14);
        if (4 < DAT_01216a78) {
          uVar11 = (&DAT_01215bb0)[uVar13 * 0x12];
          uVar5 = *(undefined4 *)(&DAT_01215b94 + lVar14);
          uVar6 = (&DAT_01215bac)[uVar13 * 0x12];
          uVar7 = (&DAT_01215ba8)[uVar13 * 0x12];
          iVar1 = DAT_01215b90 - 1;
          fVar19 = (float)FUN_002917b0(&DAT_01216a60);
          lVar14 = syscall(0xba);
          FUN_002340f0((double)(fVar19 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u 0x%X %u %u %u\n","DEBUG",lVar14,
                       "dmal/rm/rm_nvml.c",0x48,iVar1,uVar5,uVar7,uVar6,uVar11);
        }
      }
      uVar17 = uVar17 + 1;
      puVar15 = puVar15 + 2;
    } while (uVar17 < DAT_01214898);
  }
  pcVar8 = *(code **)(*(long *)(param_1 + 0x30) + 0xb8);
  DAT_01214898 = local_23c;
  uVar11 = FUN_0023a420();
  (*pcVar8)(param_1,DAT_0038088c,uVar11);
  pcVar8 = *(code **)(*(long *)(param_1 + 0x30) + 0xc0);
  uVar11 = FUN_0023a420();
  (*pcVar8)(param_1,DAT_0038088c,uVar11);
  FUN_001a23c0(param_1);
  FUN_001353b0();
  return uVar10;
}


// ===== 0023a8e0 FUN_0023a8e0 =====

bool FUN_0023a8e0(long *param_1,long param_2,long param_3)

{
  if (param_1 == (long *)0x0 || param_2 == 0) {
    return false;
  }
  if (*param_1 != param_3) {
    return false;
  }
  return (int)param_1[1] == *(int *)(param_2 + 4);
}


// ===== 0023a920 FUN_0023a920 =====

void FUN_0023a920(uint *param_1,long param_2)

{
  uint uVar1;
  undefined1 auVar2 [16];
  uint *puVar3;
  undefined1 local_38 [16];
  undefined1 local_28 [16];
  undefined4 local_18;
  uint local_14 [3];
  uint *puVar4;
  
  local_18 = 0;
  local_28 = (undefined1  [16])0x0;
  local_38._3_13_ = SUB1613((undefined1  [16])0x0,3);
  auVar2._1_13_ = local_38._3_13_;
  auVar2[0] = (char)*(undefined4 *)(param_2 + 8);
  auVar2._14_2_ = 0;
  local_38 = auVar2 << 0x10;
  puVar3 = (uint *)local_38;
  do {
    puVar4 = puVar3 + 1;
    uVar1 = *puVar3;
    *param_1 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    puVar3 = puVar4;
    param_1 = param_1 + 1;
  } while (puVar4 != local_14);
  return;
}


// ===== 0023a960 FUN_0023a960 =====

uint FUN_0023a960(int param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6)

{
  int iVar1;
  ulong uVar2;
  uint *puVar3;
  uint uVar4;
  uint local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = param_6;
  local_30 = param_2;
  local_20 = param_4;
  local_18 = param_5;
  uVar4 = 0;
  iVar1 = 0;
  local_28 = param_3;
  uVar2 = 8;
  puVar3 = (uint *)&stack0x00000008;
  do {
    while (0x2f < (uint)uVar2) {
      iVar1 = iVar1 + 1;
      uVar4 = uVar4 ^ *puVar3;
      puVar3 = puVar3 + 2;
      if (param_1 == iVar1) {
        return uVar4;
      }
    }
    iVar1 = iVar1 + 1;
    uVar4 = uVar4 ^ *(uint *)((long)local_38 + uVar2);
    uVar2 = (ulong)((uint)uVar2 + 8);
  } while (param_1 != iVar1);
  return uVar4;
}


// ===== 0023a9e0 FUN_0023a9e0 =====

void FUN_0023a9e0(long param_1)

{
  FUN_0023a960(1,*(undefined4 *)(param_1 + 4));
  return;
}


// ===== 0023a9f0 FUN_0023a9f0 =====

void FUN_0023a9f0(long *param_1)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  
  plVar1 = (long *)*param_1;
  plVar4 = (long *)*plVar1;
  if (param_1 != plVar1) {
    do {
      plVar2 = plVar4;
      plVar3 = *(long **)plVar1[-2];
      plVar4 = (long *)plVar1[-2];
      while (plVar5 = plVar3, plVar1 + -2 != plVar4) {
        plVar3 = (long *)plVar4[1];
        plVar5[1] = (long)plVar3;
        *plVar3 = *plVar4;
        free(plVar4 + -1);
        plVar3 = (long *)*plVar5;
        plVar4 = plVar5;
      }
      plVar4 = (long *)plVar1[1];
      *(long **)(*plVar1 + 8) = plVar4;
      *plVar4 = *plVar1;
      free(plVar1 + -4);
      plVar4 = (long *)*plVar2;
      plVar1 = plVar2;
    } while (param_1 != plVar2);
    return;
  }
  return;
}


// ===== 0023aab0 FUN_0023aab0 =====

void FUN_0023aab0(uint *param_1,long param_2)

{
  int iVar1;
  uint uVar2;
  long *plVar3;
  code *pcVar4;
  byte bVar5;
  long lVar6;
  uint *puVar7;
  uint *puVar8;
  undefined4 local_108;
  
  puVar8 = &local_108;
  puVar7 = puVar8;
  for (lVar6 = 0x20; lVar6 != 0; lVar6 = lVar6 + -1) {
    puVar7[0] = 0;
    puVar7[1] = 0;
    puVar7 = puVar7 + 2;
  }
  local_108._2_1_ = (char)*(undefined4 *)(param_2 + 8);
  plVar3 = *(long **)(param_2 + 0x10);
  if (plVar3 != (long *)(param_2 + 0x10)) {
    iVar1 = *(int *)plVar3[-1];
    bVar5 = 0x22;
    if (((6 < iVar1 - 0x12dU) && (bVar5 = 0x12, 1 < iVar1 - 1U)) &&
       (bVar5 = 0x1a, 2 < iVar1 - 0x65U)) {
      bVar5 = 0x20;
      if (iVar1 != 0xc9) {
        bVar5 = 0x3f;
      }
    }
    local_108._0_1_ = (byte)local_108 & 0xc0 | bVar5;
    do {
      uVar2 = *puVar8;
      puVar8 = puVar8 + 1;
      *param_1 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      param_1 = param_1 + 1;
    } while (puVar8 != (uint *)&stack0xfffffffffffffff8);
    return;
  }
                    /* WARNING: Does not return */
  pcVar4 = (code *)invalidInstructionException();
  (*pcVar4)();
}


// ===== 0023ab60 FUN_0023ab60 =====

uint FUN_0023ab60(long param_1,long param_2,uint *param_3)

{
  uint *__src;
  code *pcVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  ushort uVar6;
  undefined8 *puVar7;
  undefined **ppuVar8;
  uint uVar9;
  uint *puVar10;
  float fVar11;
  undefined4 local_25c;
  undefined *local_258 [3];
  undefined4 local_240 [2];
  undefined *local_238;
  undefined4 local_230;
  undefined *local_228 [63];
  
  uVar3 = 2;
  uVar4 = *param_3;
  local_25c = 0;
  puVar7 = &DAT_002dc500;
  ppuVar8 = local_228;
  for (lVar5 = 0x3e; lVar5 != 0; lVar5 = lVar5 + -1) {
    *ppuVar8 = (undefined *)*puVar7;
    puVar7 = puVar7 + 1;
    ppuVar8 = ppuVar8 + 1;
  }
  if (uVar4 < 0x1f0) {
    __src = param_3 + 2;
    local_258[0] = &DAT_002dc472;
    local_258[2] = &DAT_002dc475;
    local_240[0] = 3;
    local_230 = 0;
    local_238 = &DAT_002dc479;
    uVar4 = 1;
    ppuVar8 = local_258;
    puVar10 = __src;
    while( true ) {
      uVar3 = *puVar10;
      uVar9 = (uVar3 & 0xff) >> 3;
      uVar6 = (ushort)(uVar3 >> 8) & 0xff | (ushort)((uVar3 << 0x18) >> 0x10) & 0x7ff;
      if (3 < DAT_01216a78) {
        fVar11 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        FUN_002340f0((double)(fVar11 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t0x%x 0x%x 0x%x\n",&DAT_002983c2,lVar5,
                     "dmal/rm/rm_prm.c",0x13c,uVar9,uVar6,uVar4);
      }
      if ((uVar4 != uVar9) && (2 < DAT_01216a78)) {
        puVar2 = *ppuVar8;
        fVar11 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        FUN_002340f0((double)(fVar11 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t0x%x %s 0x%x\n","WARNING",lVar5,
                     "dmal/rm/rm_prm.c",0x141,uVar4,puVar2,uVar9);
      }
      if (local_228 == ppuVar8 + 2) break;
      uVar4 = *(uint *)(ppuVar8 + 3);
      puVar10 = puVar10 + uVar6;
      ppuVar8 = ppuVar8 + 2;
    }
    memcpy(local_228,__src,(ulong)*param_3);
    lVar5 = *(long *)(param_2 + 0x256d8);
    if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x50) == (undefined8 *)0x0)) ||
       (pcVar1 = (code *)**(undefined8 **)(lVar5 + 0x50), pcVar1 == (code *)0x0)) {
      uVar3 = 3;
    }
    else {
      uVar3 = (*pcVar1)(lVar5,param_2,0x2080,&local_25c);
      if (uVar3 == 0) {
        uVar4 = FUN_0019c780(*(undefined8 *)(param_1 + 0x10),DAT_0038088c,local_25c,0x20803095,
                             local_228,0x1f0,0);
        uVar3 = 0x70;
        if (uVar4 < 0x4e) {
          uVar3 = (uint)(byte)(&DAT_002dca60)[uVar4];
        }
        param_3[1] = uVar3;
        switch(uVar4) {
        case 0:
          goto switchD_0023adf9_caseD_0;
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
      fVar11 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar5,"dmal/rm/rm_prm.c",0x15a,"cDeviceReadWritePRM_v1",0x15a,uVar3);
    }
  }
  return uVar3;
switchD_0023adf9_caseD_0:
  memcpy(__src,local_228,(ulong)*param_3);
  if (DAT_01216a78 < 5) {
    return uVar4;
  }
  fVar11 = (float)FUN_002917b0(&DAT_01216a60);
  lVar5 = syscall(0xba);
  FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",lVar5
               ,"dmal/rm/rm_prm.c",0x166);
  return uVar4;
}


// ===== 0023b010 FUN_0023b010 =====

undefined8 FUN_0023b010(int *param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = *param_1;
  if (iVar1 - 0x12dU < 7) {
    uVar2 = 0x22;
  }
  else {
    if (iVar1 - 1U < 2) {
      uVar2 = FUN_0023a960(2,0x12,param_1[1]);
      return uVar2;
    }
    if (iVar1 - 0x65U < 3) {
      uVar2 = FUN_0023a960(2,0x1a,param_1[1]);
      return uVar2;
    }
    uVar2 = 0x20;
    if (iVar1 != 0xc9) {
      return 0;
    }
  }
  uVar2 = FUN_0023a960(2,uVar2,param_1[1]);
  return uVar2;
}


// ===== 0023b090 FUN_0023b090 =====

void FUN_0023b090(long *param_1,long param_2)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  
  if (*param_1 == 0) {
    return;
  }
  uVar7 = 0;
  uVar4 = 0xffffffff;
  do {
    uVar2 = *(uint *)((long)param_1 + 0xc);
    if (uVar2 == 0) {
      return;
    }
    puVar3 = (uint *)param_1[2];
    uVar6 = *(uint *)(param_1 + 1) >> 5;
    puVar1 = (uint *)(param_2 + (ulong)uVar6 * 4);
    if (uVar2 < 0x21) {
      if (uVar4 != uVar6) {
        uVar7 = *puVar1;
        uVar7 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
      }
      uVar4 = (int)(1L << ((byte)uVar2 & 0x3f)) - 1U &
              uVar7 >> ((byte)*(uint *)(param_1 + 1) & 0x1f);
      *(uint *)(param_1 + 3) = uVar4;
      if (puVar3 == (uint *)0x0) goto LAB_0023b0d6;
      *puVar3 = uVar4;
      lVar5 = param_1[4];
    }
    else {
      uVar4 = *puVar1;
      uVar2 = puVar1[1];
      lVar5 = CONCAT44(uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 |
                       uVar4 << 0x18,
                       uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 |
                       uVar2 << 0x18);
      param_1[3] = lVar5;
      if (puVar3 != (uint *)0x0) {
        *(long *)puVar3 = lVar5;
      }
LAB_0023b0d6:
      lVar5 = param_1[4];
    }
    if (lVar5 == 0) {
      return;
    }
    param_1 = param_1 + 4;
    uVar4 = uVar6;
  } while( true );
}


// ===== 0023b140 FUN_0023b140 =====

undefined8 FUN_0023b140(undefined8 param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  int *piVar3;
  undefined8 *puVar4;
  uint local_5c;
  char *local_58;
  undefined8 local_50;
  uint *local_48;
  undefined1 local_40 [16];
  undefined1 local_30 [16];
  undefined8 local_20;
  
  local_58 = "oper_recovery";
  local_50 = 0x8000000c0;
  local_48 = &local_5c;
  local_5c = 0;
  local_20 = 0;
  local_40 = (undefined1  [16])0x0;
  local_30 = (undefined1  [16])0x0;
  FUN_0023b090(&local_58,param_1);
  lVar1 = param_2 + 0x10;
  if (lVar1 != *(long *)(param_2 + 0x10)) {
    puVar4 = (undefined8 *)(*(long *)(param_2 + 0x10) + -8);
    do {
      while( true ) {
        piVar3 = (int *)*puVar4;
        piVar3[2] = 0;
        piVar3[3] = 1;
        if (*piVar3 != 0x3e9) break;
        piVar3[4] = local_5c >> 1 & 1;
        plVar2 = puVar4 + 1;
        puVar4 = (undefined8 *)(*plVar2 + -8);
        if (lVar1 == *plVar2) {
          return 0;
        }
      }
      piVar3[2] = 3;
      plVar2 = puVar4 + 1;
      puVar4 = (undefined8 *)(*plVar2 + -8);
    } while (lVar1 != *plVar2);
  }
  return 0;
}


// ===== 0023b200 FUN_0023b200 =====

undefined8 FUN_0023b200(uint *param_1,long param_2)

{
  uint *puVar1;
  long *plVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined1 auVar6 [16];
  int *piVar7;
  long lVar8;
  byte bVar9;
  undefined8 *puVar10;
  long *plVar11;
  long *plVar12;
  byte bVar13;
  float fVar14;
  undefined8 local_260;
  undefined8 local_258;
  undefined8 local_250;
  undefined8 local_248;
  undefined8 local_240;
  undefined8 local_238;
  undefined8 local_230;
  uint local_228;
  char *local_128;
  undefined8 local_120;
  undefined8 *local_118;
  undefined1 local_110 [16];
  undefined1 local_100 [16];
  undefined1 local_f0 [16];
  undefined1 local_e0 [16];
  undefined8 local_d0;
  char *local_c8;
  undefined8 local_c0;
  undefined8 *local_b8;
  char *local_a8;
  undefined8 local_a0;
  undefined8 *local_98;
  char *local_88;
  undefined8 local_80;
  undefined8 *local_78;
  char *local_68;
  undefined8 local_60;
  undefined8 *local_58;
  
  bVar13 = 0;
  puVar1 = param_1 + 2;
  uVar3 = *param_1;
  local_228 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar3 = uVar3 >> 0x18 & 0x3f;
  bVar9 = (byte)uVar3;
  if (3 < DAT_01216a78) {
    fVar14 = (float)FUN_002917b0(&DAT_01216a60);
    lVar8 = syscall(0xba);
    FUN_002340f0((double)(fVar14 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n",
                 &DAT_002983c2,lVar8,"dmal/rm/rm_prm.c",799,uVar3);
  }
  if (bVar9 == 0x20) {
    local_230 = (ulong)local_230._4_4_ << 0x20;
    local_128 = "port_xmit_wait";
    plVar12 = (long *)(param_2 + 0x10);
    local_120 = 0x2000000024;
    local_118 = &local_230;
    auVar6._8_8_ = 0;
    auVar6._0_8_ = local_f0._8_8_;
    local_f0 = auVar6 << 0x40;
    local_110 = (undefined1  [16])0x0;
    local_100 = (undefined1  [16])0x0;
    FUN_0023b090(&local_128,puVar1);
    plVar11 = (long *)*plVar12 + -1;
    if (plVar12 != (long *)*plVar12) {
      piVar7 = (int *)*plVar11;
      piVar7[2] = 0;
      piVar7[3] = 3;
      if (*piVar7 == 0xc9) goto LAB_0023b6ef;
      do {
        piVar7[2] = 3;
        while( true ) {
          plVar2 = plVar11 + 1;
          plVar11 = (long *)*plVar2 + -1;
          if (plVar12 == (long *)*plVar2) {
            return 0;
          }
          piVar7 = (int *)*plVar11;
          piVar7[2] = 0;
          piVar7[3] = 3;
          if (*piVar7 != 0xc9) break;
LAB_0023b6ef:
          piVar7[4] = (int)local_230;
        }
      } while( true );
    }
  }
  else if (bVar9 < 0x21) {
    if (bVar9 == 0x12) {
      plVar12 = (long *)(param_2 + 0x10);
      local_128 = "link_down_events";
      local_120 = 0x2000000600;
      local_118 = &local_238;
      local_110 = ZEXT816(0x2dc8fa) << 0x40;
      local_100._8_8_ = &local_230;
      local_100._0_8_ = 0x2000000620;
      local_238 = (ulong)local_238._4_4_ << 0x20;
      local_230 = (ulong)local_230._4_4_ << 0x20;
      local_d0 = 0;
      local_f0 = (undefined1  [16])0x0;
      local_e0 = (undefined1  [16])0x0;
      FUN_0023b090(&local_128,puVar1);
      plVar11 = (long *)*plVar12;
      if (plVar12 != plVar11) {
        do {
          piVar7 = (int *)plVar11[-1];
          piVar7[2] = 0;
          piVar7[3] = 1;
          if (*piVar7 == 1) {
            piVar7[4] = (int)local_238;
          }
          else if (*piVar7 == 2) {
            piVar7[4] = (int)local_230;
          }
          else {
            piVar7[2] = 3;
          }
          plVar11 = (long *)*plVar11;
        } while (plVar12 != plVar11);
      }
    }
    else if (bVar9 == 0x1a) {
      plVar11 = (long *)(param_2 + 0x10);
      local_240 = (ulong)local_240._4_4_ << 0x20;
      puVar10 = &local_120;
      for (lVar8 = 0xf; lVar8 != 0; lVar8 = lVar8 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + (ulong)bVar13 * -2 + 1;
      }
      local_238 = (ulong)local_238._4_4_ << 0x20;
      local_128 = "total_successful_recovery_events";
      local_118 = &local_240;
      local_110._8_8_ = "time_since_last_recovery";
      local_100._8_8_ = &local_238;
      local_100._0_8_ = 0x2000000260;
      local_f0._8_8_ = "time_between_last_two_recoveries";
      local_e0._8_8_ = &local_230;
      local_e0._0_8_ = 0x10000002c0;
      local_230 = (ulong)local_230._4_4_ << 0x20;
      local_120 = CONCAT44(0x20,(undefined4)local_120);
      FUN_0023b090(&local_128,puVar1);
      plVar12 = (long *)*plVar11 + -1;
      if (plVar11 != (long *)*plVar11) {
        do {
          while( true ) {
            piVar7 = (int *)*plVar12;
            iVar4 = *piVar7;
            piVar7[2] = 0;
            piVar7[3] = 1;
            if (iVar4 != 0x66) break;
            piVar7[4] = (int)local_238;
LAB_0023b360:
            plVar2 = plVar12 + 1;
            plVar12 = (long *)*plVar2 + -1;
            if (plVar11 == (long *)*plVar2) {
              return 0;
            }
          }
          if (iVar4 != 0x67) {
            if (iVar4 == 0x65) {
              piVar7[4] = (int)local_240;
            }
            else {
              piVar7[2] = 3;
            }
            goto LAB_0023b360;
          }
          piVar7[4] = (int)local_230;
          plVar2 = plVar12 + 1;
          plVar12 = (long *)*plVar2 + -1;
        } while (plVar11 != (long *)*plVar2);
      }
    }
  }
  else if (bVar9 == 0x22) {
    local_260 = 0;
    puVar10 = &local_120;
    for (lVar8 = 0x1f; lVar8 != 0; lVar8 = lVar8 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + (ulong)bVar13 * -2 + 1;
    }
    local_258 = 0;
    local_128 = "plr_rcv_codes";
    local_118 = &local_260;
    local_110._8_8_ = "plr_rcv_code_err";
    local_100._8_8_ = &local_258;
    local_100._0_8_ = 0x4000000040;
    local_f0._8_8_ = "plr_rcv_uncorrectable_code";
    local_e0._8_8_ = &local_250;
    local_e0._0_8_ = 0x4000000080;
    local_c8 = "plr_xmit_codes";
    local_c0 = 0x40000000c0;
    local_b8 = &local_248;
    local_a8 = "plr_xmit_retry_codes";
    local_a0 = 0x4000000100;
    local_98 = &local_240;
    local_88 = "plr_xmit_retry_events";
    local_80 = 0x4000000140;
    local_78 = &local_238;
    local_68 = "plr_sync_events";
    local_60 = 0x4000000180;
    local_58 = &local_230;
    local_250 = 0;
    local_248 = 0;
    local_240 = 0;
    local_238 = 0;
    local_230 = 0;
    local_120 = CONCAT44(0x40,(undefined4)local_120);
    FUN_0023b090(&local_128,puVar1);
    for (puVar10 = *(undefined8 **)(param_2 + 0x10); (undefined8 *)(param_2 + 0x10) != puVar10;
        puVar10 = (undefined8 *)*puVar10) {
      puVar5 = (undefined4 *)puVar10[-1];
      *(undefined8 *)(puVar5 + 2) = 0x300000000;
      switch(*puVar5) {
      case 0x12d:
        *(undefined8 *)(puVar5 + 4) = local_260;
        break;
      case 0x12e:
        *(undefined8 *)(puVar5 + 4) = local_258;
        break;
      case 0x12f:
        *(undefined8 *)(puVar5 + 4) = local_250;
        break;
      case 0x130:
        *(undefined8 *)(puVar5 + 4) = local_248;
        break;
      case 0x131:
        *(long *)(puVar5 + 4) = local_240;
        break;
      case 0x132:
        *(long *)(puVar5 + 4) = local_238;
        break;
      case 0x133:
        *(long *)(puVar5 + 4) = local_230;
        break;
      default:
        puVar5[2] = 3;
      }
    }
  }
  return 0;
}


// ===== 0023b8d0 FUN_0023b8d0 =====

/* WARNING: Removing unreachable block (ram,0x0023ba59) */
/* WARNING: Removing unreachable block (ram,0x0023ba61) */
/* WARNING: Removing unreachable block (ram,0x0023bba5) */
/* WARNING: Removing unreachable block (ram,0x0023ba79) */
/* WARNING: Removing unreachable block (ram,0x0023ba8d) */
/* WARNING: Removing unreachable block (ram,0x0023ba9f) */

long * FUN_0023b8d0(undefined8 param_1,undefined8 param_2,long param_3,ushort *param_4)

{
  uint uVar1;
  long *plVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  uint *puVar6;
  uint *puVar7;
  float fVar9;
  long *plVar10;
  undefined1 local_248 [16];
  uint local_238 [2];
  uint local_230 [4];
  uint local_220;
  undefined1 local_21c [492];
  uint *puVar8;
  
  puVar6 = local_238;
  for (lVar5 = 0x3f; lVar5 != 0; lVar5 = lVar5 + -1) {
    puVar6[0] = 0;
    puVar6[1] = 0;
    puVar6 = puVar6 + 2;
  }
  local_248._8_8_ = 0;
  local_248._0_8_ = (ulong)*param_4 << 0x30 | 0x10108040000;
  uVar3 = (*(uint *)(param_4 + 2) >> 2) + 1;
  puVar6 = local_230;
  puVar7 = (uint *)local_248;
  do {
    puVar8 = puVar7 + 1;
    uVar1 = *puVar7;
    *puVar6 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    puVar6 = puVar6 + 1;
    puVar7 = puVar8;
  } while (puVar8 != local_238);
  local_220 = (uVar3 & 0x7ff | 0x1800 | (uVar3 & 0xff) << 0x10) >> 8;
  (**(code **)(param_4 + 0xc))(local_21c,param_3);
  local_238[0] = *(int *)(param_4 + 2) + 0x14;
  iVar4 = FUN_0023ab60(param_1,param_2,local_238);
  if (iVar4 == 0) {
    local_248 = (undefined1  [16])0x0;
    puVar6 = (uint *)local_248;
    puVar7 = local_230;
    do {
      puVar8 = puVar6 + 1;
      uVar3 = *puVar7;
      *puVar6 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      puVar6 = puVar8;
      puVar7 = puVar7 + 1;
    } while (puVar8 != local_238);
    printf("ERROR: OpTLV status: expected 0x0 got 0x%x\n",0);
    plVar10 = (long *)(ulong)DAT_01216a78;
    if (1 < (int)DAT_01216a78) {
      fVar9 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      plVar10 = (long *)0x40c;
      FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar5,"dmal/rm/rm_prm.c",0x40c,"handlePRMList_i",0x40c,999);
    }
  }
  else {
    for (plVar2 = *(long **)(param_3 + 0x10); plVar10 = plVar2 + -1,
        (long *)(param_3 + 0x10) != plVar2; plVar2 = (long *)*plVar2) {
      *(int *)(*plVar10 + 8) = iVar4;
    }
  }
  return plVar10;
}


// ===== 0023bbc0 FUN_0023bbc0 =====

undefined8 FUN_0023bbc0(undefined8 param_1,undefined8 param_2,uint *param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  long *plVar4;
  long *****ppppplVar5;
  char cVar6;
  long lVar7;
  undefined8 uVar8;
  long *__ptr;
  undefined8 *puVar9;
  undefined8 *puVar10;
  float fVar11;
  uint local_bc;
  undefined8 local_b8;
  code *local_b0;
  code *local_a8;
  code *local_a0;
  code *local_98;
  long ****local_90;
  long ****local_88;
  undefined8 local_78;
  code *local_70;
  code *local_68;
  code *local_60;
  code *local_58;
  long ****local_50;
  long ****local_48;
  
  local_b8 = 0x10000005008;
  local_b0 = FUN_0023b010;
  local_a8 = FUN_0023a8e0;
  local_68 = FUN_0023a8e0;
  local_60 = FUN_0023a920;
  local_58 = FUN_0023b140;
  local_a0 = FUN_0023aab0;
  local_98 = FUN_0023b200;
  local_78 = 0x2400005059;
  local_70 = FUN_0023a9e0;
  local_90 = (long ****)&local_90;
  local_88 = (long ****)&local_90;
  local_50 = (long ****)&local_50;
  local_48 = (long ****)&local_50;
  if (*param_3 != 0) {
    local_bc = 0;
    do {
      piVar1 = (int *)(*(long *)(param_3 + 2) + (ulong)local_bc * 0x18);
      iVar2 = *piVar1;
      puVar10 = &local_b8;
      if ((((iVar2 - 0x12dU < 7) || (iVar2 - 1U < 2)) || (iVar2 - 0x65U < 3)) ||
         ((iVar2 == 0xc9 || (puVar10 = &local_78, iVar2 == 0x3e9)))) {
        uVar8 = (*(code *)puVar10[1])(piVar1);
        __ptr = malloc(0x18);
        if (__ptr != (long *)0x0) {
          *__ptr = (long)piVar1;
          for (puVar3 = (undefined8 *)puVar10[5]; puVar10 + 5 != puVar3;
              puVar3 = (undefined8 *)*puVar3) {
            puVar9 = puVar3 + -4;
            cVar6 = (*(code *)puVar10[2])(puVar9,piVar1,uVar8);
            if (cVar6 != '\0') goto LAB_0023be25;
          }
          puVar9 = malloc(0x30);
          if (puVar9 != (undefined8 *)0x0) {
            *puVar9 = uVar8;
            *(int *)(puVar9 + 1) = piVar1[1];
            puVar9[2] = puVar9 + 2;
            puVar9[3] = puVar9 + 2;
            plVar4 = (long *)puVar10[6];
            lVar7 = *plVar4;
            puVar9[5] = plVar4;
            puVar9[4] = lVar7;
            *(undefined8 **)(*plVar4 + 8) = puVar9 + 4;
            *plVar4 = (long)(puVar9 + 4);
LAB_0023be25:
            plVar4 = (long *)puVar9[3];
            lVar7 = *plVar4;
            __ptr[2] = (long)plVar4;
            __ptr[1] = lVar7;
            *(long **)(*plVar4 + 8) = __ptr + 1;
            *plVar4 = (long)(__ptr + 1);
            goto LAB_0023bd78;
          }
          puts("ERROR creating hash list");
          free(__ptr);
        }
        uVar8 = 0x14;
        goto LAB_0023bf42;
      }
      if (1 < DAT_01216a78) {
        fVar11 = (float)FUN_002917b0(&DAT_01216a60);
        lVar7 = syscall(0xba);
        FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",
                     "ERROR",lVar7,"dmal/rm/rm_prm.c",0x467,iVar2);
      }
      piVar1[2] = 2;
LAB_0023bd78:
      local_bc = local_bc + 1;
    } while (local_bc < *param_3);
  }
  for (ppppplVar5 = (long *****)local_90; &local_90 != ppppplVar5;
      ppppplVar5 = (long *****)*ppppplVar5) {
    FUN_0023b8d0(param_1,param_2,ppppplVar5 + -4,&local_b8);
  }
  for (ppppplVar5 = (long *****)local_50; &local_50 != ppppplVar5;
      ppppplVar5 = (long *****)*ppppplVar5) {
    FUN_0023b8d0(param_1,param_2,ppppplVar5 + -4,&local_78);
  }
  uVar8 = 0;
LAB_0023bf42:
  FUN_0023a9f0(&local_90);
  FUN_0023a9f0(&local_50);
  return uVar8;
}


// ===== 0023bfa0 thunk_FUN_0023c060 =====

int thunk_FUN_0023c060(int *param_1,char *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = open64(param_2,2);
  if (iVar1 < 0) {
    piVar2 = __errno_location();
    *param_1 = *piVar2;
  }
  return iVar1;
}


// ===== 0023bfb0 thunk_FUN_0023c0a0 =====

void thunk_FUN_0023c0a0(int param_1)

{
  if (param_1 < 0) {
    return;
  }
  close(param_1);
  return;
}


// ===== 0023bfc0 thunk_FUN_0023c0b0 =====

void thunk_FUN_0023c0b0(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 < 0) {
    return;
  }
  iVar1 = fcntl(param_1,2,1);
  if (iVar1 < 0) {
    piVar2 = __errno_location();
    *param_2 = *piVar2;
  }
  return;
}


// ===== 0023bfd0 thunk_FUN_0023c0f0 =====

undefined8
thunk_FUN_0023c0f0(int param_1,undefined4 param_2,ulong param_3,ulong param_4,undefined8 param_5)

{
  int iVar1;
  int *piVar2;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined8 uStack_40;
  
  while( true ) {
    if (param_3 < 0x1001) {
      iVar1 = ioctl(param_1,param_4,param_5);
    }
    else {
      uStack_44 = (undefined4)param_3;
      uStack_48 = param_2;
      uStack_40 = param_5;
      iVar1 = ioctl(param_1,0xc01046d3,&uStack_48);
    }
    if (-1 < iVar1) break;
    piVar2 = __errno_location();
    if ((*piVar2 != 4) && (*piVar2 != 0xb)) {
      return 0xffffffff;
    }
  }
  return 1;
}


// ===== 0023bfe0 thunk_FUN_0023c1a0 =====

undefined8 thunk_FUN_0023c1a0(uint param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  char *pcVar4;
  undefined8 uVar5;
  bool bVar6;
  char acStack_48 [31];
  undefined1 uStack_29;
  
  iVar1 = FUN_00241ef0();
  if (iVar1 != 1) {
    piVar3 = __errno_location();
    iVar1 = *piVar3;
    snprintf(acStack_48,0x20,"-c=%d",(ulong)param_1);
    uStack_29 = 0;
    pcVar4 = getenv("__RM_ENABLE_VERBOSE_OUTPUT");
    bVar6 = false;
    if (pcVar4 != (char *)0x0) {
      bVar6 = *pcVar4 == '1';
    }
    FUN_00242530(acStack_48,0,bVar6);
    uVar2 = FUN_00241e00(param_1);
    if ((uVar2 & 3) != 3) {
      uVar5 = FUN_0023d5d0(iVar1);
      return uVar5;
    }
  }
  return 0;
}


// ===== 0023bff0 FUN_0023bff0 =====

void FUN_0023bff0(char *param_1,uint param_2)

{
  if (param_2 < 0x100) {
    if (param_2 == 0xff) {
      builtin_strncpy(param_1,"/dev/nvidiactl",0xf);
    }
    else {
      snprintf(param_1,0x80,"/dev/nvidia%d",(ulong)param_2);
    }
    param_1[0x7f] = '\0';
    return;
  }
  *param_1 = '\0';
  return;
}


// ===== 0023c060 FUN_0023c060 =====

int FUN_0023c060(int *param_1,char *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = open64(param_2,2);
  if (iVar1 < 0) {
    piVar2 = __errno_location();
    *param_1 = *piVar2;
  }
  return iVar1;
}


// ===== 0023c0a0 FUN_0023c0a0 =====

void FUN_0023c0a0(int param_1)

{
  if (param_1 < 0) {
    return;
  }
  close(param_1);
  return;
}


// ===== 0023c0b0 FUN_0023c0b0 =====

void FUN_0023c0b0(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 < 0) {
    return;
  }
  iVar1 = fcntl(param_1,2,1);
  if (iVar1 < 0) {
    piVar2 = __errno_location();
    *param_2 = *piVar2;
  }
  return;
}


// ===== 0023c0f0 FUN_0023c0f0 =====

undefined8
FUN_0023c0f0(int param_1,undefined4 param_2,ulong param_3,ulong param_4,undefined8 param_5)

{
  int iVar1;
  int *piVar2;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  
  while( true ) {
    if (param_3 < 0x1001) {
      iVar1 = ioctl(param_1,param_4,param_5);
    }
    else {
      local_44 = (undefined4)param_3;
      local_48 = param_2;
      local_40 = param_5;
      iVar1 = ioctl(param_1,0xc01046d3,&local_48);
    }
    if (-1 < iVar1) break;
    piVar2 = __errno_location();
    if ((*piVar2 != 4) && (*piVar2 != 0xb)) {
      return 0xffffffff;
    }
  }
  return 1;
}


// ===== 0023c1a0 FUN_0023c1a0 =====

undefined8 FUN_0023c1a0(uint param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  char *pcVar4;
  undefined8 uVar5;
  bool bVar6;
  char local_48 [31];
  undefined1 local_29;
  
  iVar1 = FUN_00241ef0();
  if (iVar1 != 1) {
    piVar3 = __errno_location();
    iVar1 = *piVar3;
    snprintf(local_48,0x20,"-c=%d",(ulong)param_1);
    local_29 = 0;
    pcVar4 = getenv("__RM_ENABLE_VERBOSE_OUTPUT");
    bVar6 = false;
    if (pcVar4 != (char *)0x0) {
      bVar6 = *pcVar4 == '1';
    }
    FUN_00242530(local_48,0,bVar6);
    uVar2 = FUN_00241e00(param_1);
    if ((uVar2 & 3) != 3) {
      uVar5 = FUN_0023d5d0(iVar1);
      return uVar5;
    }
  }
  return 0;
}


// ===== 0023c240 FUN_0023c240 =====

ulong FUN_0023c240(ulong *param_1,ulong *param_2)

{
  ulong *puVar1;
  ulong uVar2;
  long lVar3;
  ulong extraout_RAX;
  char cVar4;
  bool bVar5;
  timespec local_38;
  
  cVar4 = '\x01';
  while( true ) {
    LOCK();
    bVar5 = DAT_01216aa4 == 0;
    if (bVar5) {
      DAT_01216aa4 = 1;
      uVar2 = 0;
    }
    else {
      uVar2 = (ulong)DAT_01216aa4;
    }
    UNLOCK();
    if (bVar5) break;
    cVar4 = cVar4 + '\x01';
    if (cVar4 == '\0') {
      local_38.tv_sec = 0;
      local_38.tv_nsec = 2000000;
      nanosleep(&local_38,(timespec *)0x0);
    }
  }
  puVar1 = param_2 + 5;
  *(int *)puVar1 = (int)*puVar1 + -1;
  if ((int)*puVar1 == 0) {
    if (param_2[6] != 0) {
      *(ulong *)(param_2[6] + 0x38) = param_2[7];
    }
    if ((ulong *)*param_1 == param_2) {
      *param_1 = param_2[7];
    }
    if (param_2[7] != 0) {
      *(ulong *)(param_2[7] + 0x30) = param_2[6];
    }
    DAT_01216aa4 = 0;
    uVar2 = *param_2;
    lVar3 = sysconf(0x1e);
    if (*(int *)((long)param_2 + 0x2c) == 0) {
      munmap((void *)(-lVar3 & uVar2),param_2[1]);
    }
    else {
      mmap64((void *)(-lVar3 & uVar2),param_2[1],0,0x32,0,0);
    }
    free(param_2);
    return extraout_RAX;
  }
  DAT_01216aa4 = 0;
  return uVar2;
}


// ===== 0023c370 FUN_0023c370 =====

undefined8 *
FUN_0023c370(int param_1,long *param_2,long param_3,ulong param_4,ulong param_5,int param_6,
            int param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10)

{
  long lVar1;
  long lVar2;
  long lVar3;
  void *pvVar4;
  undefined8 *puVar5;
  int __flags;
  char cVar6;
  ulong __len;
  bool bVar7;
  timespec local_48;
  
  if (param_5 == 0) {
    __flags = 1;
  }
  else {
    lVar1 = sysconf(0x1e);
    lVar2 = sysconf(0x1e);
    __flags = 0x11;
    if ((lVar1 - 1U & param_4) != (lVar2 - 1U & param_5)) {
      return (undefined8 *)0x0;
    }
  }
  lVar1 = sysconf(0x1e);
  lVar2 = sysconf(0x1e);
  lVar3 = sysconf(0x1e);
  __len = (lVar1 - 1U & param_4) + param_3 + -1 + lVar2 & -lVar3;
  lVar1 = sysconf(0x1e);
  pvVar4 = mmap64((void *)(-lVar1 & param_5),__len,param_7,__flags,param_1,0);
  if (pvVar4 == (void *)0xffffffffffffffff) {
    return (undefined8 *)0x0;
  }
  lVar1 = sysconf(0x1e);
  pvVar4 = (void *)(lVar1 - 1U & param_4 | (ulong)pvVar4);
  puVar5 = malloc(0x48);
  if (puVar5 != (undefined8 *)0x0) {
    *puVar5 = pvVar4;
    puVar5[2] = param_3;
    *(undefined4 *)(puVar5 + 4) = param_8;
    *(undefined4 *)(puVar5 + 5) = 1;
    *(undefined4 *)((long)puVar5 + 0x24) = param_9;
    puVar5[1] = __len;
    cVar6 = '\x01';
    *(int *)((long)puVar5 + 0x2c) = param_6;
    puVar5[3] = param_4;
    *(undefined4 *)(puVar5 + 8) = param_10;
    while( true ) {
      LOCK();
      bVar7 = DAT_01216aa4 == 0;
      if (bVar7) {
        DAT_01216aa4 = 1;
      }
      UNLOCK();
      if (bVar7) break;
      cVar6 = cVar6 + '\x01';
      if (cVar6 == '\0') {
        local_48.tv_sec = 0;
        local_48.tv_nsec = 2000000;
        nanosleep(&local_48,(timespec *)0x0);
      }
    }
    lVar1 = *param_2;
    if (lVar1 != 0) {
      *(undefined8 **)(lVar1 + 0x30) = puVar5;
    }
    puVar5[7] = lVar1;
    puVar5[6] = 0;
    *param_2 = (long)puVar5;
    DAT_01216aa4 = 0;
    return puVar5;
  }
  if (param_6 == 0) {
    munmap(pvVar4,__len);
    return (undefined8 *)0x0;
  }
  mmap64(pvVar4,__len,0,0x32,0,0);
  return (undefined8 *)0x0;
}


// ===== 0023c570 FUN_0023c570 =====

void FUN_0023c570(long param_1,int param_2)

{
  long lVar1;
  char cVar2;
  bool bVar3;
  timespec local_38;
  
  cVar2 = '\x01';
  while( true ) {
    LOCK();
    bVar3 = DAT_01216aa4 == 0;
    if (bVar3) {
      DAT_01216aa4 = 1;
    }
    UNLOCK();
    if (bVar3) break;
    cVar2 = cVar2 + '\x01';
    if (cVar2 == '\0') {
      local_38.tv_sec = 0;
      local_38.tv_nsec = 2000000;
      nanosleep(&local_38,(timespec *)0x0);
    }
  }
  for (lVar1 = *(long *)(param_1 + 0x20); (lVar1 != 0 && (*(int *)(lVar1 + 0x24) != param_2));
      lVar1 = *(long *)(lVar1 + 0x38)) {
  }
  DAT_01216aa4 = 0;
  return;
}


// ===== 0023c600 FUN_0023c600 =====

void FUN_0023c600(undefined8 *param_1)

{
  size_t __len;
  ulong uVar1;
  ulong *puVar2;
  ulong *__ptr;
  long lVar3;
  char cVar4;
  bool bVar5;
  timespec local_38;
  
  cVar4 = '\x01';
  while( true ) {
    LOCK();
    bVar5 = DAT_01216aa4 == 0;
    if (bVar5) {
      DAT_01216aa4 = 1;
    }
    UNLOCK();
    if (bVar5) break;
    cVar4 = cVar4 + '\x01';
    if (cVar4 == '\0') {
      local_38.tv_sec = 0;
      local_38.tv_nsec = 2000000;
      nanosleep(&local_38,(timespec *)0x0);
    }
  }
  __ptr = (ulong *)*param_1;
  while (__ptr != (ulong *)0x0) {
    __len = __ptr[1];
    uVar1 = *__ptr;
    lVar3 = sysconf(0x1e);
    munmap((void *)(-lVar3 & uVar1),__len);
    puVar2 = (ulong *)__ptr[7];
    free(__ptr);
    __ptr = puVar2;
  }
  *param_1 = 0;
  DAT_01216aa4 = 0;
  return;
}


// ===== 0023c6c0 FUN_0023c6c0 =====

bool FUN_0023c6c0(void *param_1,size_t param_2)

{
  int iVar1;
  
  iVar1 = mlock(param_1,param_2);
  return iVar1 == 0;
}


// ===== 0023c6d0 munlock =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int munlock(void *__addr,size_t __len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_munlock_0032f018)();
  return iVar1;
}


// ===== 0023c6e0 FUN_0023c6e0 =====

undefined4
FUN_0023c6e0(ulong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
            long param_6)

{
  undefined8 *puVar1;
  undefined8 in_stack_00000020;
  long in_stack_00000028;
  undefined4 in_stack_00000030;
  undefined8 *in_stack_00000038;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  if (param_5 == 0x3e) {
    puVar1 = (undefined8 *)
             FUN_0023c370(param_1,param_6 + 0x20,in_stack_00000028 + 1,in_stack_00000020,0,0,3,
                          param_3,param_4,1);
    if (puVar1 == (undefined8 *)0x0) {
      local_3c[0] = 0;
      local_48 = param_2;
      local_44 = param_3;
      local_40 = param_4;
      FUN_0023d7d0(param_1 & 0xffffffff,0x29,0x10,0xc0104629,&local_48,local_3c);
      return 0x59;
    }
    in_stack_00000020 = *puVar1;
  }
  else if (param_5 == 0x40) {
    in_stack_00000020 = 0;
  }
  if (in_stack_00000038 != (undefined8 *)0x0) {
    *in_stack_00000038 = in_stack_00000020;
  }
  return in_stack_00000030;
}


// ===== 0023c7b0 FUN_0023c7b0 =====

ulong FUN_0023c7b0(ulong param_1,undefined4 param_2,int param_3,int *param_4)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  char cVar4;
  bool bVar5;
  timespec local_48;
  
  if ((int)param_1 == param_3) {
    cVar4 = '\x01';
    while( true ) {
      LOCK();
      bVar5 = DAT_01217e20 == 0;
      if (bVar5) {
        DAT_01217e20 = 1;
        uVar2 = 0;
      }
      else {
        uVar2 = (ulong)DAT_01217e20;
      }
      UNLOCK();
      if (bVar5) break;
      cVar4 = cVar4 + '\x01';
      if (cVar4 == '\0') {
        local_48.tv_sec = 0;
        local_48.tv_nsec = 2000000;
        nanosleep(&local_48,(timespec *)0x0);
      }
    }
    for (; param_4 != (int *)0x0; param_4 = *(int **)(param_4 + 0xc)) {
      if ((int)param_1 == *param_4) {
        uVar2 = FUN_0023c600(param_4 + 8);
      }
    }
    DAT_01217e20 = 0;
  }
  else {
    lVar1 = FUN_0023d8e0(param_1,param_3);
    if (lVar1 == 0) {
      lVar1 = FUN_0023d8e0(param_1 & 0xffffffff,param_2);
      if (lVar1 != 0) {
        while( true ) {
          lVar3 = FUN_0023c570(lVar1,param_3);
          if (lVar3 == 0) break;
          FUN_0023c240(lVar1 + 0x20,lVar3);
        }
        return 0;
      }
      uVar2 = 0;
    }
    else {
      lVar1 = FUN_0023d8e0(param_1 & 0xffffffff,param_3);
      uVar2 = 0;
      if (lVar1 != 0) {
        uVar2 = FUN_0023c600(lVar1 + 0x20);
        return uVar2;
      }
    }
  }
  return uVar2;
}


// ===== 0023c8e0 FUN_0023c8e0 =====

ulong FUN_0023c8e0(undefined4 param_1,ulong param_2,undefined4 param_3,undefined4 param_4,
                  ulong param_5,undefined8 param_6,ulong *param_7,uint param_8)

{
  undefined4 uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  int iVar5;
  int iVar6;
  ulong uVar7;
  undefined *puVar8;
  ulong *puVar9;
  char cVar10;
  bool bVar11;
  uint local_b8;
  undefined4 local_b4;
  uint local_b0;
  int local_ac;
  __time_t local_a8;
  undefined4 local_a0;
  undefined1 auStack_9c [12];
  undefined1 local_90 [16];
  undefined1 local_78 [24];
  undefined8 local_60;
  undefined8 uStack_58;
  undefined1 local_50 [2] [16];
  
  local_ac = 0;
  local_b0 = param_8;
  local_b4 = param_4;
  uVar7 = FUN_0023e7b0(param_2 & 0xffffffff,param_2,0xd01,&local_b4,0xc);
  iVar5 = local_ac;
  local_b8 = (uint)uVar7;
  if (local_b8 == 0) {
    puVar8 = (undefined *)FUN_0023d8e0(param_2 & 0xffffffff,param_3);
    if (puVar8 == (undefined *)0x0) {
      if (iVar5 != 1) {
        return 0x22;
      }
      puVar8 = &DAT_012173c0;
    }
    uVar7 = 0x29;
    if ((param_8 & 3) != 3) {
      uVar1 = *(undefined4 *)(&DAT_002dcb08 + (ulong)(param_8 & 3) * 4);
      if ((param_8 & 0x40000) == 0) {
        *param_7 = 0;
      }
      cVar10 = '\x01';
      while( true ) {
        LOCK();
        bVar11 = DAT_01217e20 == 0;
        if (bVar11) {
          DAT_01217e20 = 1;
        }
        UNLOCK();
        if (bVar11) break;
        cVar10 = cVar10 + '\x01';
        if (cVar10 == '\0') {
          local_78._0_8_ = 0;
          local_78._8_8_ = 2000000;
          nanosleep((timespec *)local_78,(timespec *)0x0);
        }
      }
      if (iVar5 == 1) {
        iVar6 = FUN_0023da00(0xff,&local_b8);
      }
      else {
        if (1 < iVar5 - 2U) {
          DAT_01217e20 = 0;
          return 0x1f;
        }
        iVar6 = FUN_0023d9b0(*(undefined8 *)(puVar8 + 0x28));
        if (iVar6 < 0) {
          DAT_01217e20 = 0;
          return 0x22;
        }
        iVar6 = FUN_0023d9f0(iVar6,&local_b8);
      }
      if (-1 < iVar6) {
        auVar2._8_8_ = 0;
        auVar2._0_8_ = param_5;
        local_78._8_16_ = auVar2 << 0x40;
        uStack_58 = 0;
        local_78._0_8_ = CONCAT44(param_3,(int)param_2);
        local_78._8_4_ = param_4;
        auVar4._4_4_ = iVar6;
        auVar4._0_4_ = param_8;
        auVar4._8_8_ = 0;
        local_50[0] = auVar4 << 0x20;
        local_60 = param_6;
        local_b8 = FUN_0023d7d0(param_1,0x4e,0x38,0xc038464e,local_78,local_50);
        if (local_b8 == 0) {
          if (local_50[0]._0_4_ != 0) {
            close(iVar6);
            DAT_01217e20 = 0;
            return (ulong)(uint)local_50[0]._0_4_;
          }
          puVar9 = (ulong *)FUN_0023c370(iVar6,puVar8 + 0x20,param_6,uStack_58,*param_7,
                                         param_8 >> 0x13 & 1,uVar1,param_3,param_4,iVar5);
          if (puVar9 != (ulong *)0x0) {
            if (iVar5 == 2) {
              local_a8 = local_78._0_8_;
              auStack_9c = SUB1612((undefined1  [16])0x0,4);
              local_a0 = local_78._8_4_;
              auStack_9c._4_8_ = uStack_58;
              local_90._8_8_ = 0;
              local_90._0_8_ = *puVar9;
              local_b8 = FUN_0023d7d0(param_1,0x5e,0x28,0xc028465e,&local_a8,local_90 + 8);
            }
            close(iVar6);
            DAT_01217e20 = 0;
            *param_7 = *puVar9;
            return (ulong)(uint)local_50[0]._0_4_;
          }
          local_a8 = local_78._0_8_;
          auStack_9c = SUB1612((undefined1  [16])0x0,4);
          local_a0 = local_78._8_4_;
          auStack_9c._4_8_ = uStack_58;
          auVar3._4_8_ = local_90._8_8_;
          auVar3._0_4_ = local_50[0]._4_4_;
          auVar3._12_4_ = 0;
          local_90 = auVar3 << 0x20;
          local_b8 = FUN_0023d7d0(param_1,0x4f,0x20,0xc020464f,&local_a8,local_90);
          close(iVar6);
          DAT_01217e20 = 0;
          return 0x1a;
        }
        close(iVar6);
      }
      DAT_01217e20 = 0;
      uVar7 = (ulong)local_b8;
    }
  }
  return uVar7;
}


// ===== 0023cd30 FUN_0023cd30 =====

ulong FUN_0023cd30(undefined4 param_1,int param_2,int param_3,undefined4 param_4,long param_5,
                  uint param_6)

{
  long *plVar1;
  undefined *puVar2;
  ulong uVar3;
  char cVar4;
  bool bVar5;
  undefined1 local_58 [16];
  long lStack_48;
  uint local_40;
  uint local_3c;
  
  puVar2 = (undefined *)FUN_0023d8e0(param_2);
  if (puVar2 == (undefined *)0x0) {
    if (param_2 != param_3) {
      return 0x59;
    }
    puVar2 = &DAT_012173c0;
  }
  cVar4 = '\x01';
  while( true ) {
    LOCK();
    bVar5 = DAT_01216aa4 == 0;
    if (bVar5) {
      DAT_01216aa4 = 1;
    }
    UNLOCK();
    if (bVar5) break;
    cVar4 = cVar4 + '\x01';
    if (cVar4 == '\0') {
      local_58._0_8_ = 0;
      local_58._8_8_ = 2000000;
      nanosleep((timespec *)local_58,(timespec *)0x0);
    }
  }
  plVar1 = *(long **)(puVar2 + 0x20);
  while( true ) {
    if (plVar1 == (long *)0x0) {
      DAT_01216aa4 = 0;
      return 0x59;
    }
    if (param_5 == *plVar1) break;
    plVar1 = (long *)plVar1[7];
  }
  DAT_01216aa4 = 0;
  local_40 = 0;
  local_58._4_4_ = param_3;
  local_58._0_4_ = param_2;
  stack0xffffffffffffffb4 = SUB1612((undefined1  [16])0x0,4);
  local_58._8_4_ = param_4;
  if ((int)plVar1[8] != 2) {
    param_5 = plVar1[3];
  }
  lStack_48 = param_5;
  local_3c = param_6;
  uVar3 = FUN_0023d7d0(param_1,0x4f,0x20,0xc020464f,local_58,&local_40);
  if (((int)uVar3 == 0) && (uVar3 = (ulong)local_40, local_40 == 0)) {
    if ((param_6 & 0x80000) == 0) {
      FUN_0023c240(puVar2 + 0x20,plVar1);
      uVar3 = (ulong)local_40;
    }
    else {
      *(undefined4 *)((long)plVar1 + 0x2c) = 1;
      FUN_0023c240(puVar2 + 0x20,plVar1);
      uVar3 = (ulong)local_40;
    }
  }
  return uVar3;
}


// ===== 0023cee0 FUN_0023cee0 =====

undefined8 FUN_0023cee0(undefined4 param_1,long param_2)

{
  int iVar1;
  int *piVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 local_248 [70];
  
  uVar5 = 0;
  if (*(int *)(param_2 + 0x40) == 0) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
    puVar4 = local_248;
    for (lVar3 = 0x46; lVar3 != 0; lVar3 = lVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    iVar1 = thunk_FUN_0023c0f0(param_1,0xd7,0x230,0xc23046d7);
    if (-1 < iVar1) {
      *(undefined4 *)(param_2 + 0x40) = 1;
      *(undefined4 *)(param_2 + 0x44) = (undefined4)local_248[0];
      return 0;
    }
    piVar2 = __errno_location();
    uVar5 = 0x59;
    if (*piVar2 == 0x16) {
      *(undefined4 *)(param_2 + 0x40) = 1;
      uVar5 = 0;
    }
  }
  return uVar5;
}


// ===== 0023cfa0 FUN_0023cfa0 =====

int * FUN_0023cfa0(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  bool bVar4;
  timespec local_48;
  
  cVar3 = '\x01';
  while( true ) {
    LOCK();
    bVar4 = DAT_01217e20 == 0;
    if (bVar4) {
      DAT_01217e20 = 1;
    }
    UNLOCK();
    piVar2 = DAT_01217408;
    if (bVar4) break;
    cVar3 = cVar3 + '\x01';
    if (cVar3 == '\0') {
      local_48.tv_sec = 0;
      local_48.tv_nsec = 2000000;
      nanosleep(&local_48,(timespec *)0x0);
    }
  }
  for (; piVar2 != (int *)0x0; piVar2 = *(int **)(piVar2 + 0xc)) {
    if (*piVar2 == param_1) {
      for (piVar1 = *(int **)(piVar2 + 4); piVar1 != (int *)0x0; piVar1 = *(int **)(piVar1 + 4)) {
        if (*piVar1 == param_2) {
          DAT_01217e20 = 0;
          return piVar1;
        }
      }
    }
  }
  piVar2 = (int *)&DAT_012173c0;
  do {
    piVar2 = *(int **)(piVar2 + 4);
    if (piVar2 == (int *)0x0) {
      DAT_01217e20 = 0;
      return (int *)0x0;
    }
  } while (*piVar2 != param_2);
  DAT_01217e20 = 0;
  return piVar2;
}


// ===== 0023d0a0 FUN_0023d0a0 =====

void FUN_0023d0a0(void)

{
  long lVar1;
  undefined4 *puVar2;
  undefined8 *puVar3;
  int *piVar4;
  byte bVar5;
  
  bVar5 = 0;
  puVar2 = &DAT_01217420;
  piVar4 = &DAT_01217420;
  do {
    if (-1 < *piVar4) {
      close(*piVar4);
    }
    piVar4 = piVar4 + 0x14;
  } while (piVar4 != &DAT_01217e20);
  puVar3 = (undefined8 *)&DAT_01217420;
  for (lVar1 = 0x140; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + (ulong)bVar5 * -2 + 1;
  }
  do {
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + 0x14;
  } while (puVar2 != &DAT_01217e20);
  return;
}


// ===== 0023d100 FUN_0023d100 =====

ulong FUN_0023d100(void)

{
  ulong uVar1;
  char cVar2;
  bool bVar3;
  timespec local_38;
  
  cVar2 = '\x01';
  while( true ) {
    LOCK();
    bVar3 = DAT_01217e20 == 0;
    if (bVar3) {
      DAT_01217e20 = 1;
      uVar1 = 0;
    }
    else {
      uVar1 = (ulong)DAT_01217e20;
    }
    UNLOCK();
    if (bVar3) break;
    cVar2 = cVar2 + '\x01';
    if (cVar2 == '\0') {
      local_38.tv_sec = 0;
      local_38.tv_nsec = 2000000;
      nanosleep(&local_38,(timespec *)0x0);
    }
  }
  DAT_01216aa8 = DAT_01216aa8 + -1;
  if (DAT_01216aa8 == 0) {
    if (DAT_00380490 != -1) {
      thunk_FUN_0023c0a0();
    }
    DAT_00380490 = -1;
    DAT_012173cc = 0xffffffff;
    uVar1 = FUN_0023d0a0();
  }
  DAT_01217e20 = 0;
  return uVar1;
}


// ===== 0023d1a0 FUN_0023d1a0 =====

void FUN_0023d1a0(long *param_1,void *param_2)

{
  void *pvVar1;
  void *__ptr;
  
  __ptr = (void *)*param_1;
  if ((void *)*param_1 == (void *)0x0) {
    return;
  }
  do {
    pvVar1 = *(void **)((long)__ptr + 0x10);
    if (__ptr == param_2) {
      if (*(long *)((long)param_2 + 8) == 0) {
        *param_1 = (long)pvVar1;
      }
      else {
        *(void **)(*(long *)((long)param_2 + 8) + 0x10) = pvVar1;
      }
      if (*(long *)((long)__ptr + 0x10) != 0) {
        *(undefined8 *)(*(long *)((long)__ptr + 0x10) + 8) = *(undefined8 *)((long)__ptr + 8);
      }
      free(__ptr);
      return;
    }
    __ptr = pvVar1;
  } while (pvVar1 != (void *)0x0);
  return;
}


// ===== 0023d200 FUN_0023d200 =====

void FUN_0023d200(long param_1,int param_2)

{
  int *piVar1;
  undefined1 (*pauVar2) [16];
  
  if (param_1 != 0) {
    for (piVar1 = *(int **)(param_1 + 0x10); piVar1 != (int *)0x0; piVar1 = *(int **)(piVar1 + 4)) {
      if (*piVar1 == param_2) {
        FUN_0023d1a0(param_1 + 0x10);
        goto LAB_0023d237;
      }
    }
    if ((*(int *)(param_1 + 0xc) != param_2) || (param_2 < 0)) {
      return;
    }
    FUN_0023c600(param_1 + 0x20);
    if (*(long *)(param_1 + 0x28) != 0) {
      piVar1 = (int *)(*(long *)(param_1 + 0x28) + 8);
      *piVar1 = *piVar1 + -1;
      pauVar2 = *(undefined1 (**) [16])(param_1 + 0x28);
      if (*(int *)(*pauVar2 + 8) == 0) {
        *pauVar2 = (undefined1  [16])0x0;
        pauVar2[1] = (undefined1  [16])0x0;
        *(undefined4 *)*pauVar2 = *(undefined4 *)*pauVar2;
        pauVar2[2] = (undefined1  [16])0x0;
        pauVar2[3] = (undefined1  [16])0x0;
        pauVar2[4] = (undefined1  [16])0x0;
      }
    }
  }
LAB_0023d237:
  close(param_2);
  return;
}


// ===== 0023d2a0 FUN_0023d2a0 =====

void FUN_0023d2a0(void *param_1)

{
  void *pvVar1;
  void *pvVar2;
  char cVar3;
  bool bVar4;
  timespec local_38;
  
  cVar3 = '\x01';
  while( true ) {
    LOCK();
    bVar4 = DAT_01217e20 == 0;
    if (bVar4) {
      DAT_01217e20 = 1;
    }
    UNLOCK();
    if (bVar4) break;
    cVar3 = cVar3 + '\x01';
    if (cVar3 == '\0') {
      local_38.tv_sec = 0;
      local_38.tv_nsec = 2000000;
      nanosleep(&local_38,(timespec *)0x0);
    }
  }
  pvVar1 = DAT_01217408;
  if (DAT_01217408 == param_1) {
    DAT_01217408 = *(void **)((long)param_1 + 0x30);
  }
  else {
    do {
      pvVar2 = pvVar1;
      if (pvVar2 == (void *)0x0) goto LAB_0023d2f9;
      pvVar1 = *(void **)((long)pvVar2 + 0x30);
    } while (*(void **)((long)pvVar2 + 0x30) != param_1);
    *(undefined8 *)((long)pvVar2 + 0x30) = *(undefined8 *)((long)param_1 + 0x30);
  }
LAB_0023d2f9:
  FUN_0023d200(param_1,*(undefined4 *)((long)param_1 + 0xc));
  free(param_1);
  DAT_01217e20 = 0;
  return;
}


// ===== 0023d370 FUN_0023d370 =====

void FUN_0023d370(int param_1)

{
  int *piVar1;
  
  for (piVar1 = DAT_012173d0; piVar1 != (int *)0x0; piVar1 = *(int **)(piVar1 + 4)) {
    if (*piVar1 == param_1) {
      FUN_0023d1a0(&DAT_012173d0);
      thunk_FUN_0023c0a0(param_1);
      return;
    }
  }
  if ((DAT_012173cc == param_1) && (-1 < param_1)) {
    thunk_FUN_0023c0a0(param_1);
    return;
  }
  return;
}


// ===== 0023d3e0 FUN_0023d3e0 =====

void FUN_0023d3e0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                 FILE *param_9,char *param_10,undefined8 param_11,undefined8 param_12,
                 undefined8 param_13,undefined8 param_14)

{
  char in_AL;
  char *pcVar1;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined1 *local_d8;
  undefined1 *local_d0;
  undefined1 local_c8 [16];
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 local_38;
  undefined8 local_28;
  
  if (in_AL != '\0') {
    local_98 = param_1;
    local_88 = param_2;
    local_78 = param_3;
    local_68 = param_4;
    local_58 = param_5;
    local_48 = param_6;
    local_38 = param_7;
    local_28 = param_8;
  }
  local_b8 = param_11;
  local_b0 = param_12;
  local_a8 = param_13;
  local_a0 = param_14;
  pcVar1 = getenv("__RM_ENABLE_VERBOSE_OUTPUT");
  if ((pcVar1 != (char *)0x0) && (*pcVar1 == '1')) {
    local_d8 = &stack0x00000008;
    local_d0 = local_c8;
    local_e0 = 0x10;
    local_dc = 0x30;
    vfprintf(param_9,param_10,&local_e0);
  }
  return;
}


// ===== 0023d4a0 FUN_0023d4a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0023d4a0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined8 uVar4;
  undefined4 local_68;
  int iStack_64;
  char local_60 [8];
  undefined8 uStack_58;
  undefined1 local_50 [16];
  undefined1 local_40 [16];
  undefined8 local_30;
  undefined4 local_28;
  undefined2 local_24;
  undefined1 local_22;
  undefined1 local_21;
  
  local_24 = 0;
  local_68 = 0;
  iStack_64 = 0;
  local_60 = (char  [8])s_595_71_05_002dd080._0_8_;
  uStack_58 = ram0x002dd088;
  local_30 = 0;
  local_28 = 0;
  local_22 = 0;
  local_21 = 0;
  local_50 = (undefined1  [16])0x0;
  local_40 = (undefined1  [16])0x0;
  pcVar3 = getenv("__RM_NO_VERSION_CHECK");
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    if (cVar1 == '1') {
      local_68 = 0x31;
    }
    else {
      if (cVar1 == '2') {
        return 1;
      }
      if (cVar1 != '\0') {
        FUN_0023d3e0(*(undefined8 *)PTR_stderr_0032efe0,
                     "NVIDIA: Unknown \'%s\' override value \'%c\'\n","__RM_NO_VERSION_CHECK");
      }
    }
  }
  iVar2 = thunk_FUN_0023c0f0(param_1,0xd2,0x48,0xc04846d2,&local_68);
  uVar4 = 1;
  if (iVar2 < 0) {
    if (iStack_64 == 1) {
      FUN_0023d3e0(*(undefined8 *)PTR_stderr_0032efe0,
                   "NVIDIA: API mismatch: the NVIDIA kernel module has version %s,\nbut this NVIDIA driver component has version %s.  Please make\nsure that the kernel module and all NVIDIA driver components\nhave the same version.\n"
                   ,local_60,"595.71.05");
      uVar4 = 0;
    }
    else {
      FUN_0023d3e0(*(undefined8 *)PTR_stderr_0032efe0,
                   "NVIDIA: API mismatch: this NVIDIA driver component has version\n%s, but the NVIDIA kernel module\'s version does not match.\nPlease make sure that the kernel module and all NVIDIA driver\ncomponents have the same version.\n"
                   ,"595.71.05");
      uVar4 = 0;
    }
  }
  return uVar4;
}


// ===== 0023d5d0 FUN_0023d5d0 =====

undefined4 FUN_0023d5d0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x59;
  if (param_1 - 1U < 0x17) {
    uVar1 = *(undefined4 *)(&DAT_002dd020 + (ulong)(param_1 - 1U) * 4);
  }
  return uVar1;
}


// ===== 0023d5f0 FUN_0023d5f0 =====

int FUN_0023d5f0(uint param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  int *piVar4;
  char *pcVar5;
  int iVar6;
  undefined4 local_c4;
  undefined2 local_c0;
  undefined2 local_be;
  undefined2 uStack_bc;
  undefined2 local_ba;
  char local_b8 [136];
  
  *param_2 = 0x59;
  if (0x1f < param_1) {
    return -1;
  }
  lVar3 = (ulong)param_1 * 0x48;
  FUN_0023bff0(local_b8,*(undefined4 *)(&DAT_01216af8 + lVar3),lVar3 + 0x1216afc);
  do {
    iVar1 = open64(local_b8,param_3 | 0x80000,0);
    if (-1 < iVar1) {
      *param_2 = 0;
      return iVar1;
    }
    piVar4 = __errno_location();
    iVar1 = *piVar4;
  } while ((iVar1 == 4) || (iVar1 == 0xb));
  if (iVar1 < 1) {
    *piVar4 = 1;
    pcVar5 = strerror(1);
    FUN_0023d3e0(*(undefined8 *)PTR_stderr_0032efe0,
                 "NVIDIA: could not open the device file %s (%s).\n",local_b8,pcVar5);
    iVar1 = 1;
    iVar6 = -1;
  }
  else {
    iVar6 = -iVar1;
    pcVar5 = strerror(iVar1);
    FUN_0023d3e0(*(undefined8 *)PTR_stderr_0032efe0,
                 "NVIDIA: could not open the device file %s (%s).\n",local_b8,pcVar5);
    if (iVar1 == 5) {
      local_be = 0;
      uStack_bc = 0;
      local_ba = 0;
      lVar3 = (ulong)param_1 * 0x48;
      local_c4 = *(undefined4 *)((long)&DAT_01216ac0 + lVar3 + 4);
      local_c0 = *(undefined2 *)(&DAT_01216ac8 + lVar3);
      iVar1 = thunk_FUN_0023c0f0(DAT_00380490,0xd1,0xc,0xc00c46d1,&local_c4);
      if (iVar1 < 0) {
        return -5;
      }
      *param_2 = CONCAT22(local_ba,uStack_bc);
      return -5;
    }
  }
  uVar2 = FUN_0023d5d0(iVar1);
  *param_2 = uVar2;
  return iVar6;
}


// ===== 0023d7d0 FUN_0023d7d0 =====

undefined8
FUN_0023d7d0(undefined4 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5,int *param_6)

{
  int iVar1;
  time_t tVar2;
  time_t tVar3;
  long lVar4;
  timespec local_48;
  
  tVar2 = time((time_t *)0x0);
  local_48.tv_sec = 0;
  local_48.tv_nsec = 0;
  while( true ) {
    iVar1 = thunk_FUN_0023c0f0(param_1,param_2,param_3,param_4,param_5);
    if (iVar1 < 0) {
      return 0x59;
    }
    if (*param_6 != 3) break;
    tVar3 = time((time_t *)0x0);
    lVar4 = tVar3 - tVar2;
    if (lVar4 < 4) {
      local_48 = (timespec)(ZEXT816(100000000) << 0x40);
    }
    else if (lVar4 < 0x3c) {
      local_48 = (timespec)ZEXT816(1);
    }
    else {
      if (0x1517f < lVar4) {
        return 0x65;
      }
      local_48 = (timespec)ZEXT816(10);
    }
    nanosleep(&local_48,(timespec *)0x0);
  }
  return 0;
}


// ===== 0023d8e0 FUN_0023d8e0 =====

int * FUN_0023d8e0(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  timespec local_48;
  
  cVar2 = '\x01';
  while( true ) {
    LOCK();
    bVar3 = DAT_01217e20 == 0;
    if (bVar3) {
      DAT_01217e20 = 1;
    }
    UNLOCK();
    piVar1 = DAT_01217408;
    if (bVar3) break;
    cVar2 = cVar2 + '\x01';
    if (cVar2 == '\0') {
      local_48.tv_sec = 0;
      local_48.tv_nsec = 2000000;
      nanosleep(&local_48,(timespec *)0x0);
    }
  }
  while( true ) {
    if (piVar1 == (int *)0x0) {
      DAT_01217e20 = 0;
      return (int *)0x0;
    }
    if ((*piVar1 == param_1) && (piVar1[1] == param_2)) break;
    piVar1 = *(int **)(piVar1 + 0xc);
  }
  DAT_01217e20 = 0;
  return piVar1;
}


// ===== 0023d9b0 FUN_0023d9b0 =====

int FUN_0023d9b0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (DAT_01216aa8 != 0) {
    puVar2 = &DAT_01217420;
    iVar1 = 0;
    do {
      if (param_1 == puVar2) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 0x14;
    } while (iVar1 != 0x20);
  }
  return -1;
}


// ===== 0023d9f0 FUN_0023d9f0 =====

void FUN_0023d9f0(undefined8 param_1,undefined8 param_2)

{
  FUN_0023d5f0(param_1,param_2,2);
  return;
}


// ===== 0023da00 FUN_0023da00 =====

int FUN_0023da00(undefined8 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  char *pcVar4;
  char local_a8 [136];
  
  *param_2 = 0x59;
  FUN_0023bff0(local_a8,0xff,0);
  do {
    iVar1 = open64(local_a8,0x80002,0);
    if (-1 < iVar1) {
      *param_2 = 0;
      return iVar1;
    }
    piVar3 = __errno_location();
    iVar1 = *piVar3;
  } while ((iVar1 == 4) || (iVar1 == 0xb));
  if (iVar1 < 1) {
    *piVar3 = 1;
    iVar1 = 1;
  }
  pcVar4 = strerror(iVar1);
  FUN_0023d3e0(*(undefined8 *)PTR_stderr_0032efe0,
               "NVIDIA: could not open the device file %s (%s).\n",local_a8,pcVar4);
  uVar2 = FUN_0023d5d0(iVar1);
  *param_2 = uVar2;
  return -1;
}


// ===== 0023dac0 FUN_0023dac0 =====

void FUN_0023dac0(void)

{
  void *pvVar1;
  void *__ptr;
  long lVar2;
  undefined8 *puVar3;
  char cVar4;
  bool bVar5;
  byte bVar6;
  timespec local_38;
  
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
      local_38.tv_sec = 0;
      local_38.tv_nsec = 2000000;
      nanosleep(&local_38,(timespec *)0x0);
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


// ===== 0023dbf0 FUN_0023dbf0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0023dbf0(undefined4 *param_1,ulong param_2)

{
  int iVar1;
  undefined8 *puVar2;
  char *pcVar3;
  long lVar4;
  undefined8 *puVar5;
  char *pcVar6;
  char cVar7;
  bool bVar8;
  byte bVar9;
  char local_24d;
  int local_24c;
  undefined1 local_248 [128];
  stat64 local_1c8;
  timespec local_138;
  undefined1 local_128 [16];
  undefined1 local_118 [16];
  
  bVar9 = 0;
  if (param_1 == (undefined4 *)0x0) {
    return 0x3d;
  }
  cVar7 = '\x01';
  while( true ) {
    LOCK();
    bVar8 = DAT_01217e20 == 0;
    if (bVar8) {
      DAT_01217e20 = 1;
    }
    UNLOCK();
    if (bVar8) break;
    cVar7 = cVar7 + '\x01';
    if (cVar7 == '\0') {
      local_138 = (timespec)(ZEXT816(2000000) << 0x40);
      nanosleep(&local_138,(timespec *)0x0);
    }
  }
  if (DAT_01216aa8 == 0) {
    puVar5 = (undefined8 *)&DAT_01217420;
    for (lVar4 = 0x140; lVar4 != 0; lVar4 = lVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + (ulong)bVar9 * -2 + 1;
    }
    puVar2 = (undefined8 *)&DAT_01217420;
    do {
      *(undefined4 *)puVar2 = 0xffffffff;
      puVar2 = puVar2 + 10;
    } while (puVar2 != puVar5);
    pcVar3 = getenv("__RM_ENABLE_VERBOSE_OUTPUT");
    bVar8 = false;
    if (pcVar3 != (char *)0x0) {
      bVar8 = *pcVar3 == '1';
    }
    iVar1 = FUN_00241df0(bVar8);
    if (iVar1 != 1) {
      pcVar3 = getenv("__RM_ENABLE_VERBOSE_OUTPUT");
      bVar8 = false;
      if (pcVar3 != (char *)0x0) {
        bVar8 = *pcVar3 == '1';
      }
      iVar1 = FUN_00242530(0,0,bVar8);
      if (iVar1 != 0) {
        FUN_0023d3e0(*(undefined8 *)PTR_stderr_0032efe0,
                     "NVIDIA: failed to load the NVIDIA kernel module.\n");
        DAT_01217e20 = 0;
        return 0x59;
      }
    }
    FUN_0023bff0(local_248,0xff,0);
    iVar1 = thunk_FUN_0023c1a0(0xff);
    if (iVar1 != 0) {
      FUN_0023d3e0(*(undefined8 *)PTR_stderr_0032efe0,
                   "NVIDIA: could not create the device file %s\n",local_248);
      DAT_01217e20 = 0;
      return iVar1;
    }
    local_24c = 0;
    DAT_00380490 = thunk_FUN_0023c060(&local_24c,local_248);
    thunk_FUN_0023c0b0(DAT_00380490,&local_24c);
    if ((DAT_00380490 < 0) || (local_24c != 0)) {
      pcVar3 = strerror(local_24c);
      FUN_0023d3e0(*(undefined8 *)PTR_stderr_0032efe0,
                   "NVIDIA: could not open the device file %s (%s).\n",local_248,pcVar3);
      iVar1 = FUN_0023d5d0(local_24c);
      thunk_FUN_0023c0a0(DAT_00380490);
      DAT_01217e20 = 0;
      return iVar1;
    }
    iVar1 = FUN_0023d4a0();
    if (iVar1 == 0) {
      thunk_FUN_0023c0a0(DAT_00380490);
      DAT_01217e20 = 0;
      return 0x6a;
    }
    iVar1 = FUN_00243190(&local_138);
    if (-1 < iVar1) {
      local_1c8.st_dev = local_138.tv_sec;
      thunk_FUN_0023c0f0(DAT_00380490,0xd6,8,0xc00846d6,&local_1c8);
    }
    pcVar3 = (char *)&DAT_01216ac0;
    for (lVar4 = 0x120; lVar4 != 0; lVar4 = lVar4 + -1) {
      pcVar3[0] = '\0';
      pcVar3[1] = '\0';
      pcVar3[2] = '\0';
      pcVar3[3] = '\0';
      pcVar3[4] = '\0';
      pcVar3[5] = '\0';
      pcVar3[6] = '\0';
      pcVar3[7] = '\0';
      pcVar3 = pcVar3 + (ulong)bVar9 * -0x10 + 8;
    }
    iVar1 = thunk_FUN_0023c0f0(DAT_00380490,200,0x900,0xc90046c8,&DAT_01216ac0);
    if (iVar1 < 0) {
      thunk_FUN_0023c0a0(DAT_00380490);
      DAT_01217e20 = 0;
      return 0x59;
    }
    pcVar6 = (char *)&DAT_01216ac0;
    local_24d = '\0';
    do {
      if (*pcVar6 != '\0') {
        snprintf((char *)&local_138,0xff,"/proc/driver/nvidia/gpus/%04x:%02x:%02x.%1u/numa_status",
                 (ulong)*(uint *)(pcVar6 + 4),(ulong)(byte)pcVar6[8],(ulong)(byte)pcVar6[9]);
        iVar1 = __xstat64(1,(char *)&local_138,&local_1c8);
        if ((iVar1 == 0) && ((local_1c8.st_mode & 0xf000) == 0x8000)) {
          iVar1 = FUN_00243260(&local_24d);
          if ((iVar1 == 0) && (local_24d == '\0')) {
            pcVar3 = getenv("__RM_ENABLE_VERBOSE_OUTPUT");
            bVar8 = false;
            if (pcVar3 != (char *)0x0) {
              bVar8 = *pcVar3 == '1';
            }
            iVar1 = FUN_002423e0(bVar8);
            if (iVar1 != 1) {
              pcVar3 = getenv("__RM_ENABLE_VERBOSE_OUTPUT");
              bVar8 = false;
              if (pcVar3 != (char *)0x0) {
                bVar8 = *pcVar3 == '1';
              }
              FUN_00242530(&DAT_002dcdf0,0,bVar8);
            }
          }
          break;
        }
      }
      pcVar6 = pcVar6 + 0x48;
    } while (pcVar3 != pcVar6);
    DAT_01217400 = 0;
    _DAT_012173c0 = SUB1612((undefined1  [16])0x0,0);
    DAT_012173cc = DAT_00380490;
    _DAT_012173d0 = (undefined1  [16])0x0;
    _DAT_012173e0 = (undefined1  [16])0x0;
    _DAT_012173f0 = (undefined1  [16])0x0;
  }
  DAT_01216aa8 = DAT_01216aa8 + 1;
  DAT_01217e20 = 0;
  *param_1 = 0;
  local_138.tv_sec = 0;
  local_138.tv_nsec = 0;
  local_128._8_8_ = 0;
  local_128._0_8_ = param_2;
  local_128 = local_128 << 0x40;
  local_118 = (undefined1  [16])0x0;
  iVar1 = FUN_0023d7d0(DAT_00380490,0x2b,0x30,0xc030462b,&local_138,local_118 + 8);
  if (iVar1 == 0) {
    if (local_118._8_4_ == 0) {
      *param_1 = (undefined4)local_138.tv_nsec;
      iVar1 = 0;
    }
    else {
      FUN_0023d100();
      iVar1 = local_118._8_4_;
    }
  }
  else {
    FUN_0023d100();
  }
  return iVar1;
}


// ===== 0023e130 FUN_0023e130 =====

void FUN_0023e130(undefined8 param_1)

{
  FUN_0023dbf0(param_1,0);
  return;
}


// ===== 0023e140 FUN_0023e140 =====

int FUN_0023e140(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,uint param_5,
                undefined8 *param_6,ulong *param_7)

{
  void *__addr;
  uint __fd;
  size_t __len;
  long lVar1;
  char local_98;
  int local_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 local_70;
  int iStack_6c;
  undefined1 local_68 [8];
  undefined8 uStack_60;
  undefined1 local_58 [16];
  ulong local_48;
  
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
  local_78 = param_1;
  uStack_74 = param_2;
  local_70 = param_3;
  if (param_4 == 0x3e) {
    if ((param_5 >> 0x10 & 3) == 1) {
      __fd = 0xffffffff;
    }
    else {
      __fd = 0xffffffff;
      if ((param_5 >> 0x1e != 1) && (__fd = FUN_0023da00(0xff,&local_7c), (int)__fd < 0)) {
        return local_7c;
      }
    }
    iStack_6c = 0x3e;
    stack0xffffffffffffff9c = SUB1612((undefined1  [16])0x0,4);
    local_68._0_4_ = param_5;
    local_48 = (ulong)__fd;
LAB_0023e260:
    uStack_60 = 0;
    local_58._8_8_ = 0;
    local_58._0_8_ = *param_7;
    local_7c = FUN_0023d7d0(*(undefined4 *)(lVar1 + 0xc),0x27,0x38,0xc0384627,&local_78,local_58 + 8
                           );
    local_98 = '\0';
    if (local_7c != 0) {
      if (__fd == 0xffffffff) {
        return local_7c;
      }
      close(__fd);
      return local_7c;
    }
    local_7c = local_58._8_4_;
  }
  else {
    stack0xffffffffffffff9c = SUB1612((undefined1  [16])0x0,4);
    local_68._0_4_ = param_5;
    local_48 = 0xffffffff;
    local_58 = (undefined1  [16])0x0;
    iStack_6c = param_4;
    if (param_4 == 0x71) {
      local_98 = '\0';
      if ((*(long *)(lVar1 + 0x28) != 0) &&
         (local_98 = '\0', *(char *)(*(long *)(lVar1 + 0x28) + 0x49) != '\0')) {
        local_98 = FUN_0023c6c0(__addr,__len);
        if (local_98 == '\0') {
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
      local_98 = '\0';
    }
    uStack_60 = *param_6;
    local_58._0_8_ = *param_7;
    local_7c = FUN_0023d7d0(*(undefined4 *)(lVar1 + 0xc),0x27,0x38,0xc0384627,&local_78,local_58 + 8
                           );
    if (local_7c != 0) goto LAB_0023e353;
    __fd = 0xffffffff;
    local_7c = local_58._8_4_;
  }
  if (local_7c == 0) {
    local_7c = 0;
    *param_7 = local_58._0_8_;
    if ((param_4 == 0x71) || (((param_5 >> 0x10 & 3) != 1 && (param_5 >> 0x1e != 1)))) {
      local_7c = FUN_0023c6e0(__fd,param_1,param_2,param_3,param_4,lVar1,
                              CONCAT44(uStack_74,local_78),CONCAT44(iStack_6c,local_70),local_68,
                              uStack_60,local_58._0_8_,local_58._8_8_,param_6);
    }
    else {
      *param_6 = 0;
      local_7c = 0;
    }
  }
  if (__fd != 0xffffffff) {
    close(__fd);
  }
LAB_0023e353:
  if (local_98 != '\0') {
    munlock(__addr,__len);
  }
  return local_7c;
}


// ===== 0023e540 FUN_0023e540 =====

ulong FUN_0023e540(int param_1,undefined4 param_2,int param_3)

{
  int *__ptr;
  ulong uVar1;
  long lVar2;
  int *piVar3;
  int *piVar4;
  int *__ptr_00;
  char cVar5;
  bool bVar6;
  int local_58;
  undefined4 local_54;
  int local_50;
  uint local_4c;
  timespec local_48;
  
  local_4c = 0;
  local_58 = param_1;
  local_54 = param_2;
  local_50 = param_3;
  FUN_0023c7b0();
  uVar1 = FUN_0023d7d0(DAT_00380490,0x29,0x10,0xc0104629,&local_58,&local_4c);
  if (((int)uVar1 == 0) && (uVar1 = (ulong)local_4c, local_4c == 0)) {
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
          local_48.tv_sec = 0;
          local_48.tv_nsec = 2000000;
          nanosleep(&local_48,(timespec *)0x0);
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
      uVar1 = (ulong)local_4c;
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
            local_48.tv_sec = 0;
            local_48.tv_nsec = 2000000;
            nanosleep(&local_48,(timespec *)0x0);
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
      uVar1 = (ulong)local_4c;
    }
  }
  return uVar1;
}


// ===== 0023e7b0 FUN_0023e7b0 =====

/* WARNING: Type propagation algorithm not settling */

ulong FUN_0023e7b0(int param_1,undefined4 param_2,uint param_3,ulong *param_4,uint param_5)

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
  char *local_ac0;
  int *local_ab8;
  uint local_a90;
  uint local_a8c;
  undefined1 local_a88 [16];
  timespec local_a78;
  undefined1 local_a68 [16];
  ulong *puStack_a58;
  undefined8 local_a50;
  undefined1 local_a48;
  undefined1 local_a47;
  int local_a44 [129];
  ulong local_840 [128];
  ulong local_440 [128];
  uint local_40;
  
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
        local_a90 = 0;
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
            local_a68._0_8_ = 0;
            local_a68._8_8_ = 2000000;
            nanosleep((timespec *)local_a68,(timespec *)0x0);
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
              uVar23 = scandir64("/dev/nvidia-caps-imex-channels",(dirent64 ***)&local_a78,
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
                pvVar19 = (void *)local_a78.tv_sec;
                do {
                  lVar12 = *(long *)((long)pvVar19 + uVar11 * 8);
                  uVar24 = (uint)uVar11;
                  if (((*(char *)(lVar12 + 0x13) != '.') ||
                      ((*(char *)(lVar12 + 0x14) != '\0' &&
                       ((*(char *)(lVar12 + 0x14) != '.' || (*(char *)(lVar12 + 0x15) != '\0'))))))
                     && (iVar7 = __isoc99_sscanf(lVar12 + 0x13,"channel%d",&local_a8c),
                        pvVar19 = (void *)local_a78.tv_sec, iVar7 == 1)) {
                    snprintf(local_a68,0x80,"/dev/nvidia-caps-imex-channels/channel%d",
                             (ulong)local_a8c);
                    iVar7 = access(local_a68,4);
                    pvVar19 = (void *)local_a78.tv_sec;
                    if (iVar7 == 0) break;
                  }
                  uVar11 = uVar11 + 1;
                  uVar24 = uVar24 + 1;
                } while (uVar11 != uVar23);
                for (lVar12 = 0; free(*(void **)((long)pvVar19 + lVar12)),
                    (ulong)(uVar23 - 1) << 3 != lVar12; lVar12 = lVar12 + 8) {
                  pvVar19 = (void *)local_a78.tv_sec;
                }
              }
              free((void *)local_a78.tv_sec);
              if (uVar23 == uVar24) {
                return 0x1b;
              }
            }
            else {
              snprintf(local_a68,0x80,"/dev/nvidia-caps-imex-channels/channel%d");
              param_3 = 0xd08;
            }
            do {
              iVar7 = open64(local_a68,0x80000,0);
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
      local_a68._0_8_ = 0;
      local_40 = FUN_0023d7d0(*(undefined4 *)(lVar12 + 0xc),0xd5,8,0xc00846d5,local_a68,
                              local_a68 + 4);
      *(int *)param_4 = 0;
joined_r0x0023e92b:
      if (local_40 == 0) {
        *(undefined4 *)param_4 = local_a68._0_4_;
        return 0;
      }
      return (ulong)local_40;
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
      puVar21 = (undefined8 *)local_a68;
      for (lVar16 = 0x146; lVar16 != 0; lVar16 = lVar16 + -1) {
        *puVar21 = 0;
        puVar21 = puVar21 + (ulong)bVar27 * -2 + 1;
      }
      local_a68._4_4_ = param_1;
      local_a68._0_4_ = (int)*param_4;
      puStack_a58._0_4_ = *(int *)((long)param_4 + 0xc);
      local_a68._8_8_ = uVar1;
      local_a50 = param_4[2];
      local_a47 = *(undefined1 *)((long)param_4 + 0x19);
      if ((char)param_4[3] != '\0') {
        if ((char)param_4[3] != '\x01') {
          return 0x1f;
        }
        local_a48 = 1;
      }
      if ((int)uVar11 != 0) {
        puVar13 = param_4 + 4;
        piVar10 = local_a44;
        puVar18 = local_840;
        do {
          piVar22 = piVar10 + 1;
          *piVar10 = (int)*puVar13;
          *puVar18 = puVar13[1];
          puVar18[0x80] = puVar13[2];
          puVar13 = puVar13 + 3;
          piVar10 = piVar22;
          puVar18 = puVar18 + 1;
        } while (piVar22 != local_a44 + (ulong)((int)uVar11 - 1) + 1);
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
          local_a68._0_8_ = 0;
          local_a68._8_8_ = 2000000;
          nanosleep((timespec *)local_a68,(timespec *)0x0);
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
          local_a68._0_8_ = 0;
          local_a68._8_8_ = 2000000;
          nanosleep((timespec *)local_a68,(timespec *)0x0);
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
      local_a68._0_8_ = 0;
      iVar7 = thunk_FUN_0023c0f0((&DAT_01217420)[uVar11 * 0x14],0xda,8,0xc00846da,local_a68);
      DAT_01217e20 = 0;
      if (-1 < iVar7) {
        if (local_a68._0_4_ == 0) {
          DAT_01217e20 = 0;
          return 0;
        }
        if (local_a68._0_4_ != -5) {
          uVar23 = FUN_0023d5d0(-local_a68._0_4_);
          return (ulong)uVar23;
        }
        DAT_01217e20 = 0;
        return (ulong)local_a68._0_8_ >> 0x20;
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
        local_a68._5_3_ = 0;
        local_a68._0_5_ = *(uint5 *)(pcVar25 + 4);
        local_a68._9_3_ = 0;
        local_a68[8] = pcVar25[9];
        local_a88 = (undefined1  [16])0x0;
        puStack_a58 = auVar5._8_8_;
        local_a68[0xc] = pcVar25[10];
        local_a68._13_3_ = 0;
        iVar7 = FUN_00242b00(local_a68,local_a88);
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
        local_a90 = 0;
        if ((*(byte *)((long)param_4 + 0x14) & 1) != 0) {
          return 0;
        }
      }
      else {
        if (param_3 != 0x3d0a) goto LAB_0023e96c;
        local_a90 = FUN_00240930(param_1,(int)*param_4,param_4 + 9);
        if (local_a90 != 0) {
          return (ulong)local_a90;
        }
      }
      bVar26 = false;
    }
LAB_0023ee38:
    bVar3 = false;
  }
LAB_0023e9e4:
  local_a68._4_4_ = param_2;
  local_a68._0_4_ = param_1;
  stack0xfffffffffffff5a4 = SUB1612((undefined1  [16])0x0,4);
  local_a68._8_4_ = param_3;
  puStack_a58 = param_4;
  local_a50 = (ulong)param_5;
  cVar6 = FUN_00247da0(local_a68);
  if (cVar6 == '\0') {
    local_a90 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,local_a68,(long)&local_a50 + 4);
  }
  if (local_a90 == 0) {
    if (local_a50._4_4_ != 0) goto LAB_0023ea56;
    if (param_3 == 0x278) {
      if (!bVar26) {
        return 0;
      }
      iVar7 = FUN_00242be0(local_a88._0_4_,local_a88[4],local_a88[8],local_a88[0xc],0);
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
            local_a78.tv_sec = 0;
            local_a78.tv_nsec = 2000000;
            nanosleep(&local_a78,(timespec *)0x0);
          }
        }
        local_ac0 = (char *)&DAT_01216ac0;
        pcVar25 = (char *)&DAT_01216ac0;
        local_ab8 = &DAT_01217420;
        piVar10 = &DAT_01217420;
        uVar11 = 0;
        while (iVar7 = (int)uVar11, *pcVar25 == '\0') {
LAB_0023f3c8:
          uVar11 = (ulong)(iVar7 + 1U);
          pcVar25 = pcVar25 + 0x48;
          piVar10 = piVar10 + 0x14;
          if (iVar7 + 1U == 0x20) {
            DAT_01217e20 = 0;
            return local_a50 >> 0x20;
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
        local_a50 = CONCAT44(iVar8,(undefined4)local_a50);
        if (iVar8 == 0) {
          iVar8 = FUN_0023d9f0(uVar11,(long)&local_a50 + 4);
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
            if (*local_ac0 != '\0') {
              iVar8 = (int)*param_4;
              piVar10 = (int *)0x0;
              if (DAT_01216aa8 != 0) {
                piVar10 = local_ab8;
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
                  if (iVar8 == *(int *)(local_ac0 + 0x10)) goto LAB_0023f4d4;
                  if (puVar13 == param_4 + 0x10) break;
                  iVar8 = *(int *)puVar13;
                }
              }
            }
            local_ac0 = local_ac0 + 0x48;
            local_ab8 = local_ab8 + 0x14;
          } while (local_ac0 != &DAT_01216b08 + (ulong)(iVar7 - 1) * 0x48);
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
            local_a78.tv_sec = 0;
            local_a78.tv_nsec = 2000000;
            nanosleep(&local_a78,(timespec *)0x0);
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
          local_a78.tv_sec = 0;
          local_a78.tv_nsec = 2000000;
          nanosleep(&local_a78,(timespec *)0x0);
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
        local_a50 = CONCAT44(iVar7,(undefined4)local_a50);
        if (iVar7 != 0) {
          FUN_0023d3e0(*(undefined8 *)PTR_stderr_0032efe0,
                       "NVIDIA: could not create file for device %u\n",
                       *(undefined4 *)(&DAT_01216af8 + uVar11 * 0x48));
          DAT_01217e20 = 0;
          return local_a50 >> 0x20;
        }
        iVar8 = FUN_0023d5f0((int)uVar11,(long)&local_a50 + 4,0x802);
        iVar7 = iVar8;
        if ((-1 < iVar8) &&
           ((uVar23 = fcntl(iVar8,3,0), (int)uVar23 < 0 ||
            (iVar9 = fcntl(iVar8,4,(ulong)(uVar23 & 0xfffff7ff)), iVar9 < 0)))) {
          piVar10 = __errno_location();
          iVar7 = -1;
          iVar9 = *piVar10;
          close(iVar8);
          uVar23 = FUN_0023d5d0(iVar9);
          local_a50 = (ulong)uVar23 << 0x20;
        }
        (&DAT_01217420)[uVar11 * 0x14] = iVar7;
      }
      DAT_01217e20 = 0;
      return local_a50 >> 0x20;
    }
    if (param_3 != 0xd08) {
      return 0;
    }
    uVar11 = *param_4;
    if (uVar11 == 0xffffffffffffffff) {
      return 0;
    }
    uVar4 = local_a68._0_4_;
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
          local_a78.tv_sec = 0;
          local_a78.tv_nsec = 2000000;
          nanosleep(&local_a78,(timespec *)0x0);
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
    local_a50 = CONCAT44(0x51,(undefined4)local_a50);
    uVar11 = uVar11 & 0xffffffff;
  }
  else {
    local_a50 = CONCAT44(local_a90,(undefined4)local_a50);
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
          local_a78.tv_sec = 0;
          local_a78.tv_nsec = 2000000;
          nanosleep(&local_a78,(timespec *)0x0);
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
          local_a78.tv_sec = 0;
          local_a78.tv_nsec = 2000000;
          nanosleep(&local_a78,(timespec *)0x0);
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
          local_a78.tv_sec = 0;
          local_a78.tv_nsec = 2000000;
          nanosleep(&local_a78,(timespec *)0x0);
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
  return local_a50 >> 0x20;
}


// ===== 0023fc90 FUN_0023fc90 =====

int FUN_0023fc90(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  long lVar4;
  int *piVar5;
  int local_e8;
  undefined1 auStack_e4 [12];
  undefined1 local_d8 [16];
  undefined8 local_c8;
  int local_b8 [32];
  int local_38 [2];
  
  piVar5 = local_b8;
  for (lVar4 = 0x10; lVar4 != 0; lVar4 = lVar4 + -1) {
    piVar5[0] = 0;
    piVar5[1] = 0;
    piVar5 = piVar5 + 2;
  }
  iVar1 = FUN_0023e7b0(param_1,param_1,0x201,local_b8,0x80);
  if (iVar1 == 0) {
    piVar5 = &DAT_01216ad0;
    iVar1 = 0;
    do {
      local_c8 = 0;
      auStack_e4 = SUB1612((undefined1  [16])0x0,4);
      local_e8 = *piVar5;
      local_d8 = (undefined1  [16])0x0;
      piVar3 = local_b8;
      do {
        if (*piVar5 == *piVar3) {
          iVar2 = FUN_0023e7b0(param_1,param_1,0x202,&local_e8,0x28);
          if (((iVar2 == 0) && (auStack_e4._4_4_ == param_2)) && (auStack_e4._8_4_ == param_3)) {
            return iVar1;
          }
          break;
        }
        piVar3 = piVar3 + 1;
      } while (piVar3 != local_38);
      iVar1 = iVar1 + 1;
      piVar5 = piVar5 + 0x12;
    } while (iVar1 != 0x20);
    iVar1 = 0x20;
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


// ===== 0023fdb0 FUN_0023fdb0 =====

ulong FUN_0023fdb0(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  long lVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  ulong uVar5;
  ulong uVar6;
  char cVar7;
  bool bVar8;
  uint local_5c;
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  
  cVar7 = '\x01';
  while( true ) {
    LOCK();
    bVar8 = DAT_01217e20 == 0;
    if (bVar8) {
      DAT_01217e20 = 1;
    }
    UNLOCK();
    if (bVar8) break;
    cVar7 = cVar7 + '\x01';
    if (cVar7 == '\0') {
      local_58 = ZEXT816(2000000) << 0x40;
      nanosleep((timespec *)local_58,(timespec *)0x0);
    }
  }
  puVar4 = malloc(0x48);
  if (puVar4 == (undefined4 *)0x0) {
    DAT_01217e20 = 0;
    return 0x1a;
  }
  *puVar4 = param_1;
  puVar4[1] = param_3;
  *(undefined8 *)(puVar4 + 0x10) = 0;
  puVar4[3] = 0xffffffff;
  puVar4[2] = param_2;
  *(undefined1 (*) [16])(puVar4 + 4) = (undefined1  [16])0x0;
  *(undefined1 (*) [16])(puVar4 + 8) = (undefined1  [16])0x0;
  *(undefined1 (*) [16])(puVar4 + 0xc) = (undefined1  [16])0x0;
  puVar2 = puVar4;
  *(undefined4 **)(puVar4 + 0xc) = DAT_01217408;
  DAT_01217408 = puVar2;
  DAT_01217e20 = 0;
  if ((DAT_01216aa8 == 0) || (0x1f < param_4)) {
    *(undefined8 *)(puVar4 + 10) = 0;
    FUN_0023d2a0(puVar4);
    return 0x1f;
  }
  uVar6 = (ulong)param_4;
  *(undefined4 **)(puVar4 + 10) = &DAT_01217420 + uVar6 * 0x14;
  lVar1 = uVar6 * 0x48;
  local_5c = thunk_FUN_0023c1a0(*(undefined4 *)(&DAT_01216af8 + lVar1));
  if (local_5c != 0) {
    FUN_0023d3e0(*(undefined8 *)PTR_stderr_0032efe0,"NVIDIA: could not create file for device %u\n",
                 *(undefined4 *)(&DAT_01216af8 + lVar1));
    FUN_0023d2a0(puVar4);
    return (ulong)local_5c;
  }
  iVar3 = FUN_0023d9f0(param_4,&local_5c);
  puVar4[3] = iVar3;
  if (-1 < iVar3) {
    local_58._0_4_ = DAT_00380490;
    iVar3 = thunk_FUN_0023c0f0(iVar3,0xc9,4,0xc00446c9,local_58);
    if (iVar3 < 0) {
      FUN_0023d2a0(puVar4);
      return 0xffff;
    }
    *(undefined8 *)(*(long *)(puVar4 + 10) + 0x10) = *(undefined8 *)(&DAT_01216ad8 + lVar1);
    *(undefined8 *)(*(long *)(puVar4 + 10) + 0x18) = *(undefined8 *)(&DAT_01216ae0 + lVar1);
    *(undefined8 *)(*(long *)(puVar4 + 10) + 0x28) = *(undefined8 *)(&DAT_01216ae8 + lVar1);
    *(undefined8 *)(*(long *)(puVar4 + 10) + 0x30) = *(undefined8 *)(&DAT_01216af0 + lVar1);
    *(undefined4 *)(*(long *)(puVar4 + 10) + 4) = *(undefined4 *)(&DAT_01216af8 + lVar1);
    *(int *)(*(long *)(puVar4 + 10) + 8) = *(int *)(*(long *)(puVar4 + 10) + 8) + 1;
    uVar5 = FUN_0023cee0(puVar4[3],*(undefined8 *)(puVar4 + 10));
    local_5c = (uint)uVar5;
    if (local_5c == 0) {
      lVar1 = *(long *)(puVar4 + 10);
      if (*(char *)(lVar1 + 0x48) != '\0') {
        return uVar5;
      }
      local_48 = (undefined1  [16])0x0;
      local_58._4_12_ = SUB1612((undefined1  [16])0x0,4);
      local_58._0_4_ = (&DAT_01216ad0)[uVar6 * 0x12];
      uVar6 = FUN_0023e7b0(param_1,param_1,0x205,local_58,0x20);
      local_5c = (uint)uVar6;
      if (local_5c == 0) {
        *(undefined1 *)(lVar1 + 0x48) = 1;
        *(byte *)(lVar1 + 0x49) = (byte)((uint)local_58._4_4_ >> 5) & 1;
        return uVar6;
      }
    }
  }
  FUN_0023d2a0(puVar4);
  return (ulong)local_5c;
}


// ===== 00240080 FUN_00240080 =====

undefined8 FUN_00240080(ulong param_1,uint param_2,uint param_3,long *param_4,int *param_5)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  int *piVar4;
  undefined8 uVar5;
  uint local_898 [4];
  char local_888 [255];
  undefined1 local_789;
  uint local_788 [63];
  undefined1 local_689;
  undefined1 local_685;
  int local_48;
  undefined1 local_44;
  
  if (param_3 == 0xc638) {
    local_898[1] = 1;
    local_898[0] = param_2;
    uVar5 = FUN_0023e7b0(param_1,param_1 & 0xffffffff,0xd02,local_898,0x10);
    if ((int)uVar5 != 0) {
      return uVar5;
    }
    lVar2 = FUN_0023d8e0(param_1 & 0xffffffff);
    if (lVar2 == 0) {
      return 0x40;
    }
    local_788[0] = 0xffffffff;
    local_44 = 0;
    uVar5 = FUN_0023e7b0(param_1 & 0xffffffff,local_898[2],0x20800175,local_788,0x748);
    if ((int)uVar5 != 0) {
      return uVar5;
    }
    if (local_48 != 1) {
      return 0x40;
    }
    snprintf(local_888,0x100,"/proc/driver/nvidia/capabilities/gpu%u/mig/gi%u/ci%u/access",
             (ulong)*(uint *)(*(long *)(lVar2 + 0x28) + 4),(ulong)local_788[0],
             (ulong)*(uint *)(param_4 + 1));
  }
  else if (param_3 < 0xc639) {
    if (param_3 == 0xf1) {
      strncpy(local_888,"/proc/driver/nvidia/capabilities/fabric-imex-mgmt",0xff);
    }
    else if (param_3 == 0xc637) {
      if ((int)param_4[1] == -2) {
        return 0;
      }
      lVar2 = FUN_0023d8e0();
      if (lVar2 == 0) {
        return 0x40;
      }
      snprintf(local_888,0x100,"/proc/driver/nvidia/capabilities/gpu%u/mig/gi%u/access",
               (ulong)*(uint *)(*(long *)(lVar2 + 0x28) + 4),(ulong)*(uint *)(param_4 + 1));
    }
    else {
      if (param_3 != 0xf) {
        return 0;
      }
      strncpy(local_888,"/proc/driver/nvidia-nvlink/capabilities/fabric-mgmt",0xff);
    }
  }
  else if (param_3 == 0xc639) {
    strncpy(local_888,"/proc/driver/nvidia/capabilities/mig/config",0xff);
  }
  else {
    if (param_3 != 0xc640) {
      return 0;
    }
    strncpy(local_888,"/proc/driver/nvidia/capabilities/mig/monitor",0xff);
  }
  local_789 = 0;
  local_898[0] = 0xffffffff;
  iVar1 = FUN_00242220(local_888,local_898);
  if (iVar1 != 1) {
    snprintf((char *)local_788,0x104,"-f=%s",local_888);
    local_685 = 0;
    FUN_00242530(&DAT_002dd00e,local_788,0);
    uVar3 = FUN_00242330(local_888);
    if (((uVar3 & 1) == 0) || ((uVar3 & 2) == 0)) {
      return 0x1b;
    }
  }
  snprintf((char *)local_788,0x100,"/dev/nvidia-caps/nvidia-cap%d",(ulong)local_898[0]);
  local_689 = 0;
  iVar1 = access((char *)local_788,4);
  if (iVar1 != 0) {
    return 0x1b;
  }
  do {
    iVar1 = open64((char *)local_788,0x80000,0);
    if (-1 < iVar1) {
      *param_5 = iVar1;
      goto LAB_002402cf;
    }
    piVar4 = __errno_location();
    iVar1 = *piVar4;
  } while ((iVar1 == 4) || (iVar1 == 0xb));
  if (iVar1 < 1) {
    *piVar4 = 1;
    *param_5 = -1;
  }
  else {
    *param_5 = -iVar1;
  }
  uVar5 = FUN_0023d5d0(*piVar4);
  if ((int)uVar5 != 0) {
    return uVar5;
  }
LAB_002402cf:
  if (param_3 != 0xc638) {
    if (param_3 < 0xc639) {
      if (((param_3 != 0xf1) && (param_3 != 0xc637)) && (param_3 != 0xf)) {
        return 0x22;
      }
    }
    else if ((param_3 != 0xc639) && (param_3 != 0xc640)) {
      return 0x22;
    }
  }
  *param_4 = (long)*param_5;
  return 0;
}


// ===== 002404a0 FUN_002404a0 =====

int FUN_002404a0(ulong param_1,undefined4 param_2,int *param_3,uint param_4,uint *param_5,
                undefined8 param_6)

{
  int *piVar1;
  undefined1 auVar2 [16];
  int iVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  int local_9c;
  undefined4 local_98;
  undefined1 auStack_94 [12];
  undefined1 local_88 [16];
  undefined8 local_78;
  undefined4 local_68;
  undefined4 local_64;
  int local_60;
  uint local_5c;
  uint *local_58;
  undefined8 local_50;
  undefined1 local_48 [16];
  
  local_9c = -1;
  if (param_3 == (int *)0x0) {
    return 0x3d;
  }
  uVar6 = param_1 & 0xffffffff;
  local_68 = (undefined4)param_1;
  local_64 = param_2;
  local_58 = param_5;
  local_50 = param_6;
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
    local_60 = *param_3;
    local_5c = 0x80;
    local_48 = (undefined1  [16])0x0;
    iVar3 = FUN_0023d7d0(DAT_00380490,0x2b,0x30,0xc030462b,&local_68,local_48 + 8);
    if (iVar3 != 0) {
LAB_00240903:
      FUN_0023d2a0(lVar5);
      return iVar3;
    }
    if (local_48._8_4_ == 0) {
      *param_3 = local_60;
      return 0;
    }
LAB_0024074e:
    FUN_0023d2a0(lVar5);
    return local_48._8_4_;
  }
  local_5c = param_4;
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
    local_60 = *param_3;
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
      local_78 = 0;
      auStack_94 = SUB1612((undefined1  [16])0x0,4);
      local_98 = (&DAT_01216ad0)[(long)iVar4 * 0x12];
      local_88 = (undefined1  [16])0x0;
      iVar4 = FUN_0023e7b0(uVar6,uVar6,0x202,&local_98,0x28);
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
      local_5c = 0x2080;
      local_48 = (undefined1  [16])0x0;
      local_60 = iVar3;
      iVar3 = FUN_0023d7d0(DAT_00380490,0x2b,0x30,0xc030462b,&local_68,local_48 + 8);
      if (iVar3 != 0) goto LAB_00240903;
      if (local_48._8_4_ == 0) {
        return 0;
      }
      goto LAB_0024074e;
    }
LAB_00240760:
    local_60 = *param_3;
    local_48 = (undefined1  [16])0x0;
    if (param_5 == (uint *)0x0) goto LAB_0024058a;
  }
  local_48 = (undefined1  [16])0x0;
  iVar3 = FUN_00240080(uVar6,param_2,param_4,param_5,&local_9c);
  if (iVar3 != 0) {
    return iVar3;
  }
LAB_0024058a:
  iVar3 = FUN_0023d7d0(DAT_00380490,0x2b,0x30,0xc030462b,&local_68,local_48 + 8);
  auVar2 = local_48;
  if (local_9c != -1) {
    close(local_9c);
    auVar2 = local_48;
  }
  local_48._8_4_ = iVar3;
  if (iVar3 == 0) {
    local_48._8_4_ = auVar2._8_4_;
    *param_3 = local_60;
  }
  return local_48._8_4_;
}


// ===== 00240910 FUN_00240910 =====

void FUN_00240910(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  undefined4 local_c;
  
  local_c = param_3;
  FUN_002404a0(param_1,param_2,&local_c,param_4,param_5,0);
  return;
}


// ===== 00240930 FUN_00240930 =====

int FUN_00240930(int param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  int *piVar6;
  byte bVar7;
  int *local_198;
  uint local_188;
  int local_16c;
  int local_168;
  undefined1 auStack_164 [12];
  undefined1 local_158 [16];
  undefined8 local_148;
  int local_138 [32];
  int local_b8 [34];
  
  bVar7 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    iVar2 = FUN_0023da00(0xff,&local_16c);
    if (iVar2 < 0) {
      return local_16c;
    }
    if ((param_1 == 0) || (param_2 == 0)) goto LAB_00240a29;
  }
  else {
    lVar4 = FUN_0023d8e0();
    if ((lVar4 == 0) || (iVar2 = FUN_0023d9b0(*(undefined8 *)(lVar4 + 0x28)), iVar2 == -1)) {
      return 0x22;
    }
    local_148 = 0;
    auStack_164 = SUB1612((undefined1  [16])0x0,4);
    local_168 = (&DAT_01216ad0)[(long)iVar2 * 0x12];
    local_158 = (undefined1  [16])0x0;
    local_16c = FUN_0023e7b0(param_1,param_1,0x202,&local_168,0x28);
    if (local_16c != 0) {
      return local_16c;
    }
    uVar1 = auStack_164._4_4_;
    piVar6 = local_b8;
    for (lVar4 = 0x10; lVar4 != 0; lVar4 = lVar4 + -1) {
      piVar6[0] = 0;
      piVar6[1] = 0;
      piVar6 = piVar6 + ((ulong)bVar7 * -2 + 1) * 2;
    }
    iVar2 = FUN_0023e7b0(param_1,param_1,0x201,local_b8,0x80);
    if (iVar2 != 0) {
      return iVar2;
    }
    piVar6 = local_138;
    for (lVar4 = 0x10; lVar4 != 0; lVar4 = lVar4 + -1) {
      piVar6[0] = 0;
      piVar6[1] = 0;
      piVar6 = piVar6 + ((ulong)bVar7 * -2 + 1) * 2;
    }
    piVar6 = &DAT_01216ad0;
    local_188 = 0;
    local_16c = 0;
    do {
      local_148 = 0;
      uVar5 = 0;
      local_158 = (undefined1  [16])0x0;
      auStack_164 = SUB1612((undefined1  [16])0x0,4);
      local_168 = *piVar6;
      do {
        if (*piVar6 == local_b8[uVar5]) {
          local_16c = FUN_0023e7b0(param_1,param_1,0x202,&local_168,0x28);
          if ((local_16c == 0) && (auStack_164._4_4_ == uVar1)) {
            local_138[local_188] = local_b8[uVar5 & 0xffffffff];
            local_188 = local_188 + 1;
          }
          break;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 != 0x20);
      piVar6 = piVar6 + 0x12;
    } while (piVar6 != (int *)&DAT_012173d0);
    iVar2 = FUN_0023da00(0xff,&local_16c);
    if (iVar2 < 0) {
      return local_16c;
    }
  }
  local_198 = local_138;
  iVar3 = thunk_FUN_0023c0f0(iVar2,0xd4,0x80,0xc08046d4,local_198);
  if (iVar3 < 0) {
    return 0x59;
  }
LAB_00240a29:
  *param_3 = iVar2;
  return 0;
}


// ===== 00240be0 FUN_00240be0 =====

int FUN_00240be0(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  int *piVar4;
  long lVar5;
  char cVar6;
  bool bVar7;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  int local_50;
  int local_4c;
  timespec local_48;
  
  if (param_4 == (int *)0x0) {
    return 0x3d;
  }
  puVar3 = (undefined *)FUN_0023d8e0();
  if (puVar3 == (undefined *)0x0) {
    iVar2 = FUN_0023da00(0xff,&local_5c);
    puVar3 = &DAT_012173c0;
    *param_4 = iVar2;
  }
  else {
    iVar2 = FUN_0023d9b0(*(undefined8 *)(puVar3 + 0x28));
    if (iVar2 < 0) {
      return 0x59;
    }
    iVar2 = FUN_0023d9f0(iVar2,&local_5c);
    *param_4 = iVar2;
  }
  if (-1 < iVar2) {
    local_48.tv_sec = CONCAT44(local_48.tv_sec._4_4_,DAT_00380490);
    iVar2 = thunk_FUN_0023c0f0(iVar2,0xc9,4,0xc00446c9,&local_48);
    if (iVar2 < 0) {
      FUN_0023d200(puVar3,*param_4);
      local_5c = 0xffff;
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
            local_48.tv_sec = 0;
            local_48.tv_nsec = 2000000;
            nanosleep(&local_48,(timespec *)0x0);
          }
        }
        if (puVar3 == PTR_DAT_0032ef60) {
          FUN_0023d370(*param_4);
        }
        else {
          FUN_0023d200(puVar3);
        }
        local_5c = 0x59;
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
            local_48.tv_sec = 0;
            local_48.tv_nsec = 2000000;
            nanosleep(&local_48,(timespec *)0x0);
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
        local_4c = 0;
        local_50 = *param_4;
        *piVar4 = local_50;
        local_58 = param_1;
        local_54 = param_2;
        iVar2 = thunk_FUN_0023c0f0(local_50,0xce,0x10,0xc01046ce,&local_58);
        if (iVar2 < 1) {
          local_4c = 0x59;
        }
        else if (local_4c == 0) {
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
            local_48.tv_sec = 0;
            local_48.tv_nsec = 2000000;
            nanosleep(&local_48,(timespec *)0x0);
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
        local_5c = local_4c;
      }
    }
  }
  return local_5c;
}


// ===== 00240f20 FUN_00240f20 =====

int FUN_00240f20(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined *puVar3;
  char cVar4;
  bool bVar5;
  timespec local_48;
  
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
      local_48.tv_sec = 0;
      local_48.tv_nsec = 2000000;
      nanosleep(&local_48,(timespec *)0x0);
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
  local_48.tv_sec = CONCAT44(param_2,param_1);
  local_48.tv_nsec._4_4_ = 0;
  local_48.tv_nsec._0_4_ = param_3;
  iVar2 = thunk_FUN_0023c0f0(param_3,0xcf,0x10,0xc01046cf,&local_48);
  if (iVar2 < 0) {
    DAT_01217e20 = 0;
    return 0x59;
  }
  if (local_48.tv_nsec._4_4_ != 0) {
    DAT_01217e20 = 0;
    return local_48.tv_nsec._4_4_;
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


// ===== 00241080 FUN_00241080 =====

int FUN_00241080(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int *param_6)

{
  int iVar1;
  long lVar2;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  long local_78;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 *local_58;
  undefined1 local_50 [16];
  undefined8 local_40 [2];
  
  if (param_6 == (int *)0x0) {
    return 0x3d;
  }
  iVar1 = 0x59;
  if (-1 < *param_6) {
    lVar2 = FUN_0023cfa0();
    if (lVar2 == 0) {
      return 0x36;
    }
    local_78 = (long)*param_6;
    local_58 = &local_88;
    local_84 = 0;
    local_40[0] = 0;
    local_50 = (undefined1  [16])0x0;
    local_88 = param_1;
    local_80 = param_4;
    local_7c = param_5;
    local_68 = param_1;
    local_64 = param_2;
    local_60 = param_3;
    local_5c = param_4;
    iVar1 = FUN_0023d7d0(local_78,0x2b,0x30,0xc030462b,&local_68,local_40);
    if (iVar1 == 0) {
      iVar1 = (int)local_40[0];
    }
  }
  return iVar1;
}


// ===== 00241180 FUN_00241180 =====

ulong FUN_00241180(undefined8 param_1,undefined8 param_2,long param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  ulong uVar2;
  long local_28;
  undefined8 local_20;
  
  if (param_3 == 0) {
    return 0x3d;
  }
  puVar1 = (undefined4 *)FUN_0023cfa0();
  if (puVar1 != (undefined4 *)0x0) {
    local_20 = 0;
    local_28 = param_3;
    uVar2 = FUN_0023d7d0(*puVar1,0x52,0x10,0xc0104652,&local_28,(long)&local_20 + 4);
    if ((int)uVar2 == 0) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = (undefined4)local_20;
      }
      uVar2 = local_20 >> 0x20;
    }
    return uVar2;
  }
  return 0x36;
}


// ===== 00241210 FUN_00241210 =====

int FUN_00241210(long param_1)

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


// ===== 00241280 FUN_00241280 =====

void FUN_00241280(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6,undefined4 param_7)

{
  FUN_0023c8e0(DAT_00380490,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}


// ===== 002412b0 FUN_002412b0 =====

void FUN_002412b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                 undefined4 param_5)

{
  FUN_0023cd30(DAT_00380490,param_1,param_2,param_3,param_4,param_5);
  return;
}


// ===== 002412e0 FUN_002412e0 =====

ulong FUN_002412e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined8 param_5,undefined8 param_6,undefined4 param_7,ulong *param_8)

{
  ulong uVar1;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined1 auStack_34 [12];
  undefined1 local_28 [16];
  
  if (param_8 != (ulong *)0x0) {
    auStack_34 = SUB1612((undefined1  [16])0x0,4);
    local_38 = param_7;
    local_28._8_8_ = 0;
    local_28._0_8_ = *param_8;
    local_58 = param_1;
    local_54 = param_2;
    local_50 = param_3;
    local_4c = param_4;
    local_48 = param_5;
    local_40 = param_6;
    uVar1 = FUN_0023d7d0(DAT_00380490,0x57,0x40,0xc0404657,&local_58,local_28 + 8);
    if (((int)uVar1 == 0) && (uVar1 = (ulong)(uint)local_28._8_4_, local_28._8_4_ == 0)) {
      *param_8 = local_28._0_8_;
    }
    return uVar1;
  }
  return 0x3d;
}


// ===== 00241370 FUN_00241370 =====

int FUN_00241370(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                undefined4 param_5,ulong param_6)

{
  undefined1 auVar1 [16];
  int iVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 auStack_2c [12];
  undefined1 local_20 [16];
  undefined8 local_10;
  
  auStack_2c = SUB1612((undefined1  [16])0x0,4);
  local_30 = param_3;
  auVar1 = _local_30;
  _local_30 = auVar1._0_8_;
  auStack_2c._4_4_ = param_5;
  local_20._8_8_ = 0;
  local_20._0_8_ = param_6;
  local_10 = 0;
  local_38 = param_1;
  local_34 = param_2;
  iVar2 = FUN_0023d7d0(DAT_00380490,0x58,0x30,0xc0304658,&local_38,&local_10);
  if (iVar2 == 0) {
    iVar2 = (int)local_10;
  }
  return iVar2;
}


// ===== 002413d0 FUN_002413d0 =====

bool FUN_002413d0(undefined8 param_1)

{
  int iVar1;
  char *pcVar2;
  char local_118 [12];
  char local_10c [252];
  
  snprintf(local_118,0x100,"/sys/module/%s/initstate",param_1);
  if ((local_10c[0] != '\0') && (local_10c[0] != '/')) {
    pcVar2 = local_10c;
    do {
      if (local_10c[0] == '-') {
        *pcVar2 = '_';
      }
      local_10c[0] = pcVar2[1];
      pcVar2 = pcVar2 + 1;
    } while ((local_10c[0] != '\0') && (local_10c[0] != '/'));
  }
  iVar1 = access(local_118,4);
  return iVar1 == 0;
}


// ===== 00241450 FUN_00241450 =====

undefined4 FUN_00241450(int param_1,char *param_2,char param_3)

{
  byte bVar1;
  int iVar2;
  __uid_t _Var3;
  undefined4 uVar4;
  FILE *pFVar5;
  size_t sVar6;
  char *pcVar7;
  posix_spawn_file_actions_t *__file_actions;
  long lVar8;
  stat *psVar9;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  byte bVar13;
  __pid_t local_50c;
  char *local_508;
  char *local_500;
  undefined8 local_4f8;
  undefined8 local_4e8;
  undefined8 local_4e0;
  undefined4 local_4d8;
  short local_4d4;
  stat local_4c8;
  ulong local_438;
  undefined4 local_430;
  undefined2 local_42c;
  undefined1 local_42a;
  
  bVar13 = 0;
  local_508 = "modprobe";
  local_4f8 = 0;
  local_4e8 = 0xffffffff000010de;
  local_4e0 = 0xffffffffffffffff;
  local_4d8 = 0xff000300;
  local_4d4 = 0;
  local_438 = local_438 & 0xffffffffffffff00;
  if (*param_2 == '\0') {
    return 0;
  }
  local_500 = param_2;
  iVar2 = FUN_002413d0(param_2);
  if (iVar2 != 0) {
    return 1;
  }
  _Var3 = geteuid();
  if (_Var3 != 0) {
    return 0;
  }
  iVar2 = FUN_00242810(&local_4e8);
  if ((iVar2 == 0) && (local_4d4 == 0)) {
    if ((param_3 != '\0') && (pFVar5 = fopen("/sys/devices/soc0/family","r"), pFVar5 != (FILE *)0x0)
       ) {
      sVar6 = fread(&local_4c8,1,6,pFVar5);
      fclose(pFVar5);
      lVar8 = 6;
      bVar11 = sVar6 < 5;
      bVar12 = sVar6 == 5;
      if (5 < sVar6) {
        sVar6 = 5;
      }
      *(undefined1 *)((long)local_4c8.__unused + (sVar6 - 0x78)) = 0;
      psVar9 = &local_4c8;
      pbVar10 = (byte *)"Tegra";
      do {
        if (lVar8 == 0) break;
        lVar8 = lVar8 + -1;
        bVar1 = (byte)psVar9->st_dev;
        bVar11 = bVar1 < *pbVar10;
        bVar12 = bVar1 == *pbVar10;
        psVar9 = (stat *)((long)psVar9 + (ulong)bVar13 * -2 + 1);
        pbVar10 = pbVar10 + (ulong)bVar13 * -2 + 1;
      } while (bVar12);
      if ((!bVar11 && !bVar12) == bVar11) goto LAB_002415e7;
    }
    if (param_1 != 0) {
      fwrite("NVIDIA: no NVIDIA devices found\n",1,0x20,*(FILE **)PTR_stderr_0032efe0);
      return 0;
    }
  }
  else {
LAB_002415e7:
    pFVar5 = fopen("/proc/sys/kernel/modprobe","r");
    if (pFVar5 != (FILE *)0x0) {
      sVar6 = fread(&local_438,1,0x400,pFVar5);
      if (0x3ff < sVar6) {
        sVar6 = 0x3ff;
      }
      *(undefined1 *)((long)&local_438 + sVar6) = 0;
      pcVar7 = strchr((char *)&local_438,10);
      if (pcVar7 != (char *)0x0) {
        *pcVar7 = '\0';
      }
      fclose(pFVar5);
    }
    if ((char)local_438 == '\0') {
      local_42a = 0;
      local_438 = 0x6f6d2f6e6962732f;
      local_430 = 0x6f727064;
      local_42c = 0x6562;
    }
    iVar2 = __xstat(1,(char *)&local_438,&local_4c8);
    if ((iVar2 == 0) && ((local_4c8.st_mode & 0xf040) == 0x8040)) {
      __file_actions = malloc(0x50);
      if ((__file_actions == (posix_spawn_file_actions_t *)0x0) ||
         (iVar2 = posix_spawn_file_actions_init(__file_actions), iVar2 != 0)) {
        free(__file_actions);
        iVar2 = posix_spawn(&local_50c,(char *)&local_438,(posix_spawn_file_actions_t *)0x0,
                            (posix_spawnattr_t *)0x0,&local_508,&PTR_s_PATH__sbin_003804a0);
      }
      else {
        posix_spawn_file_actions_addopen(__file_actions,1,"/dev/null",2,0);
        posix_spawn_file_actions_adddup2(__file_actions,1,2);
        iVar2 = posix_spawn(&local_50c,(char *)&local_438,__file_actions,(posix_spawnattr_t *)0x0,
                            &local_508,&PTR_s_PATH__sbin_003804a0);
        posix_spawn_file_actions_destroy(__file_actions);
        free(__file_actions);
      }
      if (iVar2 == 0) {
        waitpid(local_50c,(int *)0x0,0);
        uVar4 = FUN_002413d0(param_2);
        return uVar4;
      }
      if (param_1 != 0) {
        pcVar7 = strerror(iVar2);
        fprintf(*(FILE **)PTR_stderr_0032efe0,"NVIDIA: failed to execute `%s`: %s.\n",&local_438,
                pcVar7);
        return 0;
      }
    }
  }
  return 0;
}


// ===== 002417f0 FUN_002417f0 =====

void FUN_002417f0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 char *param_5)

{
  int iVar1;
  FILE *__stream;
  undefined4 local_5c;
  long local_58;
  int local_50;
  short sStack_4c;
  char cStack_4a;
  undefined1 uStack_49;
  short local_48;
  undefined1 local_39;
  
  *param_3 = 0x1b6;
  *param_1 = 0;
  *param_2 = 0;
  *param_4 = 1;
  if ((param_5 != (char *)0x0) && (*param_5 != '\0')) {
    __stream = fopen(param_5,"r");
    if (__stream != (FILE *)0x0) {
      while( true ) {
        iVar1 = __isoc99_fscanf(__stream,"%31[^:]: %u\n",&local_58,&local_5c);
        if (iVar1 != 2) break;
        local_39 = 0;
        if (((local_58 == 0x6946656369766544) && (local_50 == 0x4955656c)) && (sStack_4c == 0x44)) {
          *param_1 = local_5c;
        }
        if (((local_58 == 0x6946656369766544) && (local_50 == 0x4947656c)) && (sStack_4c == 0x44)) {
          *param_2 = local_5c;
        }
        if (((local_58 == 0x6946656369766544) && (local_50 == 0x6f4d656c)) &&
           ((sStack_4c == 0x6564 && (cStack_4a == '\0')))) {
          *param_3 = local_5c;
        }
        if (((CONCAT17(uStack_49,CONCAT16(cStack_4a,CONCAT24(sStack_4c,local_50))) ==
              0x656c694665636976 && local_58 == 0x6544796669646f4d) && (local_48 == 0x73)) ||
           ((CONCAT17(uStack_49,CONCAT16(cStack_4a,CONCAT24(sStack_4c,local_50))) ==
             0x796669646f4d656c && local_58 == 0x6946656369766544 && ((char)local_48 == '\0')))) {
          *param_4 = local_5c;
        }
      }
      fclose(__stream);
      return;
    }
  }
  return;
}


// ===== 002419b0 FUN_002419b0 =====

undefined8 FUN_002419b0(ulong param_1,uint param_2,byte *param_3)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  bool bVar7;
  byte bVar8;
  char local_238 [128];
  char local_1b8 [128];
  stat local_138;
  stat local_a8;
  
  bVar8 = 0;
  snprintf(local_238,0x80,"/dev/char/%d:%d",param_1 & 0xffffffff,(ulong)param_2);
  iVar1 = __xstat(1,(char *)param_3,&local_a8);
  if ((iVar1 == 0) && ((local_a8.st_mode & 0xf000) == 0x2000)) {
    lVar3 = 5;
    bVar7 = true;
    bVar6 = false;
    pbVar4 = param_3;
    pbVar5 = &DAT_002dd1a8;
    do {
      if (lVar3 == 0) break;
      lVar3 = lVar3 + -1;
      bVar6 = *pbVar4 < *pbVar5;
      bVar7 = *pbVar4 == *pbVar5;
      pbVar4 = pbVar4 + (ulong)bVar8 * -2 + 1;
      pbVar5 = pbVar5 + (ulong)bVar8 * -2 + 1;
    } while (bVar7);
    if ((!bVar6 && !bVar7) == bVar6) {
      uVar2 = snprintf(local_1b8,0x80,"../%s",param_3 + 5);
      if (uVar2 < 0x80) {
        remove(local_238);
        iVar1 = symlink(local_1b8,local_238);
        if ((-1 < iVar1) ||
           ((iVar1 = __xstat(1,local_238,&local_138), iVar1 == 0 &&
            (local_138.st_ino == local_a8.st_ino)))) {
          return 1;
        }
      }
    }
  }
  return 0;
}


// ===== 00241ab0 FUN_00241ab0 =====

undefined8 FUN_00241ab0(char *param_1,int *param_2,char *param_3)

{
  int iVar1;
  FILE *__stream;
  int local_5c;
  long local_58;
  long local_50;
  undefined1 local_39;
  
  __stream = fopen(param_1,"r");
  if (__stream != (FILE *)0x0) {
    *param_2 = -1;
    do {
      iVar1 = __isoc99_fscanf(__stream,"%31[^:]: %d\n",&local_58,&local_5c);
      if (iVar1 != 2) goto LAB_00241b4d;
      local_39 = 0;
    } while (local_50 != 0x726f6e694d656c || local_58 != 0x6946656369766544);
    *param_2 = local_5c;
LAB_00241b4d:
    fclose(__stream);
    if (-1 < *param_2) {
      snprintf(param_3,0x80,"/dev/nvidia-caps/nvidia-cap%d");
      return 1;
    }
  }
  return 0;
}


// ===== 00241bb0 FUN_00241bb0 =====

byte FUN_00241bb0(char *param_1,int param_2,uint param_3,__uid_t param_4,__gid_t param_5,
                 uint param_6)

{
  byte bVar1;
  int iVar2;
  stat local_c8;
  
  iVar2 = __xstat(1,param_1,&local_c8);
  bVar1 = 0;
  if (iVar2 == 0) {
    bVar1 = 1;
    if ((local_c8.st_mode & 0xf000) == 0x2000) {
      bVar1 = ((long)(int)((param_3 & 0xfff00) << 0xc | param_2 << 8 | param_3 & 0xff) ==
              local_c8.st_rdev) * '\x02' + 1;
    }
    if ((((local_c8.st_mode & 0x1ff) == param_6) && (local_c8.st_uid == param_4)) &&
       (local_c8.st_gid == param_5)) {
      bVar1 = bVar1 | 4;
    }
  }
  return bVar1;
}


// ===== 00241c90 FUN_00241c90 =====

undefined4 FUN_00241c90(int param_1,uint param_2,char *param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  __mode_t local_40;
  __uid_t local_3c;
  __gid_t local_38;
  int local_34;
  __dev_t local_30;
  
  if (*param_3 == '\0') {
    return 0;
  }
  FUN_002417f0(&local_3c,&local_38,&local_40,&local_34,param_4);
  if (local_34 != 1) goto LAB_00241d48;
  uVar1 = FUN_00241bb0(param_3,param_1,param_2,local_3c,local_38,local_40);
  if ((uVar1 & 1) != 0) {
    if ((uVar1 & 6) == 6) goto LAB_00241d48;
    if (((int)uVar1 >> 1 & 1U) != 0) {
      iVar2 = chmod(param_3,local_40);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = chown(param_3,local_3c,local_38);
      if (iVar2 != 0) {
        return 0;
      }
      goto LAB_00241d48;
    }
    iVar2 = remove(param_3);
    if (iVar2 != 0) {
      return 0;
    }
  }
  local_30 = (__dev_t)(int)(param_2 & 0xff | param_1 << 8 | (param_2 & 0xfff00) << 0xc);
  iVar2 = __xmknod(0,param_3,local_40 | 0x2000,&local_30);
  if (iVar2 != 0) {
    return 0;
  }
  iVar2 = chmod(param_3,local_40);
  if ((iVar2 != 0) || (iVar2 = chown(param_3,local_3c,local_38), iVar2 != 0)) {
    remove(param_3);
    return 0;
  }
LAB_00241d48:
  uVar3 = FUN_002419b0(param_1,param_2,param_3);
  return uVar3;
}


// ===== 00241df0 FUN_00241df0 =====

void FUN_00241df0(undefined8 param_1)

{
  FUN_00241450(param_1,"nvidia",0);
  return;
}


// ===== 00241e00 FUN_00241e00 =====

void FUN_00241e00(uint param_1)

{
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined1 local_9c [4];
  ulong local_98;
  undefined4 local_90;
  undefined2 local_8c;
  undefined1 local_8a;
  undefined1 local_19;
  
  if (param_1 < 0x100) {
    if (param_1 == 0xff) {
      local_8a = 0;
      local_98 = 0x69766e2f7665642f;
      local_90 = 0x63616964;
      local_8c = 0x6c74;
    }
    else {
      snprintf((char *)&local_98,0x80,"/dev/nvidia%d",(ulong)param_1);
    }
    local_19 = 0;
  }
  else {
    local_98 = local_98 & 0xffffffffffffff00;
  }
  FUN_002417f0(&local_a4,&local_a0,&local_a8,local_9c,"/proc/driver/nvidia/params");
  FUN_00241bb0(&local_98,0xc3,param_1,local_a4,local_a0,local_a8);
  return;
}


// ===== 00241ef0 FUN_00241ef0 =====

void FUN_00241ef0(uint param_1)

{
  ulong local_98;
  undefined4 local_90;
  undefined2 local_8c;
  undefined1 local_8a;
  undefined1 local_19;
  
  if (param_1 < 0x100) {
    if (param_1 == 0xff) {
      local_8a = 0;
      local_98 = 0x69766e2f7665642f;
      local_90 = 0x63616964;
      local_8c = 0x6c74;
    }
    else {
      snprintf((char *)&local_98,0x80,"/dev/nvidia%d",(ulong)param_1);
    }
    local_19 = 0;
  }
  else {
    local_98 = local_98 & 0xffffffffffffff00;
  }
  FUN_00241c90(0xc3,param_1,&local_98,"/proc/driver/nvidia/params");
  return;
}


// ===== 00241fa0 FUN_00241fa0 =====

undefined4 FUN_00241fa0(char *param_1)

{
  int iVar1;
  FILE *__stream;
  char *pcVar2;
  size_t sVar3;
  undefined4 uVar4;
  undefined4 local_13c;
  char local_138;
  char cStack_137;
  undefined6 uStack_136;
  long local_130;
  int local_128;
  undefined1 local_39;
  
  local_39 = 0;
  __stream = fopen("/proc/devices","r");
  if (__stream == (FILE *)0x0) {
    uVar4 = 0xffffffff;
  }
  else {
    do {
      pcVar2 = fgets(&local_138,0xff,__stream);
      if (pcVar2 == (char *)0x0) break;
    } while ((local_130 != 0x6563697665642072 ||
              CONCAT62(uStack_136,CONCAT11(cStack_137,local_138)) != 0x6574636172616843) ||
            (local_128 != 0xa3a73));
    iVar1 = ferror(__stream);
    if (iVar1 == 0) {
      do {
        pcVar2 = fgets(&local_138,0xff,__stream);
        if ((pcVar2 == (char *)0x0) || ((local_138 == '\n' && (cStack_137 == '\0'))))
        goto LAB_002420b8;
        pcVar2 = strstr(&local_138,param_1);
      } while ((pcVar2 == (char *)0x0) || (sVar3 = strlen(param_1), pcVar2[sVar3] != '\n'));
      iVar1 = __isoc99_sscanf(&local_138," %d %*s",&local_13c);
      uVar4 = 0xffffffff;
      if (iVar1 == 1) {
        uVar4 = local_13c;
      }
    }
    else {
LAB_002420b8:
      uVar4 = 0xffffffff;
    }
    fclose(__stream);
  }
  return uVar4;
}


// ===== 002420f0 FUN_002420f0 =====

bool FUN_002420f0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00241fa0("nvidia-uvm");
  if (-1 < iVar1) {
    iVar2 = FUN_00241c90(iVar1,param_1,"/dev/nvidia-uvm",0);
    if (iVar2 != 0) {
      iVar1 = FUN_00241c90(iVar1,param_1 + 1,"/dev/nvidia-uvm-tools",0);
      return iVar1 != 0;
    }
  }
  return false;
}


// ===== 00242160 FUN_00242160 =====

void FUN_00242160(void)

{
  FUN_00241450(0,"nvidia-uvm",0);
  return;
}


// ===== 00242170 FUN_00242170 =====

undefined8 FUN_00242170(uint param_1)

{
  int iVar1;
  undefined8 uVar2;
  char local_a8 [8];
  char acStack_a0 [8];
  undefined8 local_98;
  
  iVar1 = FUN_00241fa0("nvidia-nvswitch");
  uVar2 = 0;
  if (-1 < iVar1) {
    if (param_1 == 0xff) {
      local_a8[0] = s__dev_nvidia_nvli_dev_nvidia_nvsw_002dd320[0x10];
      local_a8[1] = s__dev_nvidia_nvli_dev_nvidia_nvsw_002dd320[0x11];
      local_a8[2] = s__dev_nvidia_nvli_dev_nvidia_nvsw_002dd320[0x12];
      local_a8[3] = s__dev_nvidia_nvli_dev_nvidia_nvsw_002dd320[0x13];
      local_a8[4] = s__dev_nvidia_nvli_dev_nvidia_nvsw_002dd320[0x14];
      local_a8[5] = s__dev_nvidia_nvli_dev_nvidia_nvsw_002dd320[0x15];
      local_a8[6] = s__dev_nvidia_nvli_dev_nvidia_nvsw_002dd320[0x16];
      local_a8[7] = s__dev_nvidia_nvli_dev_nvidia_nvsw_002dd320[0x17];
      acStack_a0[0] = s__dev_nvidia_nvli_dev_nvidia_nvsw_002dd320[0x18];
      acStack_a0[1] = s__dev_nvidia_nvli_dev_nvidia_nvsw_002dd320[0x19];
      acStack_a0[2] = s__dev_nvidia_nvli_dev_nvidia_nvsw_002dd320[0x1a];
      acStack_a0[3] = s__dev_nvidia_nvli_dev_nvidia_nvsw_002dd320[0x1b];
      acStack_a0[4] = s__dev_nvidia_nvli_dev_nvidia_nvsw_002dd320[0x1c];
      acStack_a0[5] = s__dev_nvidia_nvli_dev_nvidia_nvsw_002dd320[0x1d];
      acStack_a0[6] = s__dev_nvidia_nvli_dev_nvidia_nvsw_002dd320[0x1e];
      acStack_a0[7] = s__dev_nvidia_nvli_dev_nvidia_nvsw_002dd320[0x1f];
      local_98 = 0x6c746368637469;
    }
    else {
      snprintf(local_a8,0x80,"/dev/nvidia-nvswitch%d",(ulong)param_1);
    }
    uVar2 = FUN_00241c90(iVar1,param_1,local_a8,"/proc/driver/nvidia-nvswitch/permissions");
  }
  return uVar2;
}


// ===== 00242220 FUN_00242220 =====

undefined8 FUN_00242220(byte *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  undefined8 uVar5;
  long lVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  undefined1 local_a8 [128];
  
  lVar6 = 0x13;
  bVar9 = (undefined1 *)0x7f < &stack0xffffffffffffffd8;
  bVar10 = &stack0x00000000 == (undefined1 *)0xa8;
  pbVar7 = param_1;
  pbVar8 = (byte *)"/proc/driver/nvidia";
  do {
    if (lVar6 == 0) break;
    lVar6 = lVar6 + -1;
    bVar9 = *pbVar7 < *pbVar8;
    bVar10 = *pbVar7 == *pbVar8;
    pbVar7 = pbVar7 + 1;
    pbVar8 = pbVar8 + 1;
  } while (bVar10);
  if (((((!bVar9 && !bVar10) == bVar9) &&
       (pcVar3 = strstr((char *)param_1,"./"), pcVar3 == (char *)0x0)) &&
      (iVar1 = access((char *)param_1,4), iVar1 == 0)) &&
     (iVar1 = FUN_00241fa0("nvidia-caps"), -1 < iVar1)) {
    iVar2 = FUN_00241ab0(param_1,param_2,local_a8);
    if (iVar2 != 0) {
      iVar2 = mkdir("/dev/nvidia-caps",0x1ed);
      if (iVar2 == 0) {
        iVar2 = chmod("/dev/nvidia-caps",0x1ed);
        if ((iVar2 == 0) && (iVar2 = chown("/dev/nvidia-caps",0,0), iVar2 == 0)) goto LAB_002422d4;
      }
      else {
        piVar4 = __errno_location();
        if (*piVar4 == 0x11) {
LAB_002422d4:
          uVar5 = FUN_00241c90(iVar1,*param_2,local_a8,param_1);
          return uVar5;
        }
      }
    }
  }
  return 0;
}


// ===== 00242330 FUN_00242330 =====

void FUN_00242330(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined1 local_b0 [4];
  undefined4 local_ac;
  undefined1 local_a8 [136];
  
  iVar1 = FUN_00241fa0("nvidia-caps");
  if (-1 < iVar1) {
    iVar2 = FUN_00241ab0(param_1,&local_ac,local_a8);
    if (iVar2 != 0) goto LAB_00242373;
  }
  local_a8[0] = 0;
LAB_00242373:
  FUN_002417f0(&local_b8,&local_b4,&local_bc,local_b0,param_1);
  FUN_00241bb0(local_a8,iVar1,local_ac,local_b8,local_b4,local_bc);
  return;
}


// ===== 002423e0 FUN_002423e0 =====

undefined8 FUN_002423e0(int param_1)

{
  int __fd;
  ssize_t sVar1;
  int *piVar2;
  char *pcVar3;
  undefined8 local_67;
  undefined4 local_5f;
  undefined2 local_5b;
  undefined1 local_59;
  char local_58 [8];
  char acStack_50 [8];
  char local_48 [8];
  char acStack_40 [8];
  undefined8 local_38;
  undefined4 local_30;
  undefined2 local_2c;
  
  local_38 = 0x625f656e696c6e6f;
  local_2c = 0x73;
  local_58 = (char  [8])s__dev_nvidia_nvli_dev_nvidia_nvsw_002dd320._48_8_;
  acStack_50 = (char  [8])s__dev_nvidia_nvli_dev_nvidia_nvsw_002dd320._56_8_;
  local_67 = 0x6d5f656e696c6e6f;
  local_5b = 0x656c;
  local_30 = 0x6b636f6c;
  local_5f = 0x6261766f;
  local_59 = 0;
  local_48 = (char  [8])s__dev_nvidia_nvli_dev_nvidia_nvsw_002dd320._64_8_;
  acStack_40 = (char  [8])s__dev_nvidia_nvli_dev_nvidia_nvsw_002dd320._72_8_;
  __fd = open(local_58,2,0);
  if (__fd < 0) {
    if (param_1 != 0) {
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      fprintf(*(FILE **)PTR_stderr_0032efe0,"NVIDIA: failed to open `%s`: %s.\n",local_58,pcVar3);
      return 0;
    }
  }
  else {
    sVar1 = write(__fd,&local_67,0xf);
    if (sVar1 == 0xf) {
      close(__fd);
      return 1;
    }
    if (param_1 != 0) {
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      fprintf(*(FILE **)PTR_stderr_0032efe0,"NVIDIA: unable to write to `%s`: %s.\n",local_58,pcVar3
             );
    }
    close(__fd);
  }
  return 0;
}


// ===== 00242530 FUN_00242530 =====

undefined8 FUN_00242530(undefined *param_1,undefined *param_2,int param_3)

{
  int iVar1;
  __uid_t _Var2;
  __pid_t _Var3;
  undefined8 uVar4;
  char *pcVar5;
  undefined *puVar6;
  undefined *puVar7;
  uint local_e0;
  __pid_t local_dc;
  char *local_d8;
  undefined *local_d0;
  undefined *local_c8;
  undefined8 local_c0;
  stat local_b8;
  
  local_d8 = "/usr/bin/nvidia-modprobe";
  local_c0 = 0;
  local_e0 = 1;
  local_d0 = param_1;
  local_c8 = param_2;
  iVar1 = __xstat(1,"/usr/bin/nvidia-modprobe",&local_b8);
  if ((iVar1 == 0) && ((local_b8.st_mode & 0xf040) == 0x8040)) {
    _Var2 = geteuid();
    if (_Var2 != 0) {
      iVar1 = posix_spawn(&local_dc,"/usr/bin/nvidia-modprobe",(posix_spawn_file_actions_t *)0x0,
                          (posix_spawnattr_t *)0x0,&local_d8,(char **)&DAT_002dd410);
      if (iVar1 == 0) {
        _Var3 = waitpid(local_dc,(int *)&local_e0,0);
        if (_Var3 < 0) {
          if (param_3 != 0) {
            pcVar5 = strerror(0);
            fprintf(*(FILE **)PTR_stderr_0032efe0,"NVIDIA: %s: waitpid failed: %s.\n",
                    "/usr/bin/nvidia-modprobe",pcVar5);
            return 0xffffffff;
          }
        }
        else {
          if ((local_e0 >> 8 & 0xff) == 0 && (local_e0 & 0x7f) == 0) goto LAB_002425a6;
          if (param_3 != 0) {
            fprintf(*(FILE **)PTR_stderr_0032efe0,"NVIDIA: %s failed with exit status %d.\n",
                    "/usr/bin/nvidia-modprobe");
          }
        }
      }
      else if (param_3 != 0) {
        pcVar5 = strerror(iVar1);
        puVar7 = &DAT_002e8ec4;
        if (param_2 == (undefined *)0x0) {
          puVar7 = &DAT_002dd473;
          param_2 = puVar7;
        }
        puVar6 = &DAT_002e8ec4;
        if (param_1 == (undefined *)0x0) {
          puVar6 = &DAT_002dd473;
          param_1 = puVar6;
        }
        fprintf(*(FILE **)PTR_stderr_0032efe0,"NVIDIA: failed to execute `%s%s%s%s%s`: %s.\n",
                "/usr/bin/nvidia-modprobe",puVar6,param_1,puVar7,param_2,pcVar5);
        return 0xffffffff;
      }
    }
    uVar4 = 0xffffffff;
  }
  else {
LAB_002425a6:
    uVar4 = 0;
  }
  return uVar4;
}


// ===== 00242700 FUN_00242700 =====

int FUN_00242700(uint param_1,ushort param_2,ushort param_3,ushort param_4,ushort param_5,
                void *param_6,ushort param_7,ushort *param_8)

{
  int __fd;
  ssize_t sVar1;
  __off_t _Var2;
  int *piVar3;
  ushort uVar4;
  int iVar5;
  char local_138 [264];
  
  *param_8 = 0;
  snprintf(local_138,0xff,"%s/%04x:%02x:%02x.%1u/config","/sys/bus/pci/devices",(ulong)param_1,
           (ulong)param_2,(ulong)param_3,(ulong)param_4);
  __fd = open(local_138,0);
  if (-1 < __fd) {
    uVar4 = param_7;
    if ((param_5 == 0) || (_Var2 = lseek(__fd,(ulong)param_5,0), -1 < _Var2)) {
      do {
        sVar1 = read(__fd,param_6,(ulong)uVar4);
        if (sVar1 < 1) {
          piVar3 = __errno_location();
          iVar5 = *piVar3;
          param_7 = param_7 - uVar4;
          goto LAB_002427a0;
        }
        param_6 = (void *)((long)param_6 + sVar1);
        uVar4 = uVar4 - (short)sVar1;
      } while (uVar4 != 0);
      iVar5 = 0;
LAB_002427a0:
      *param_8 = param_7;
      close(__fd);
      return iVar5;
    }
    close(__fd);
  }
  piVar3 = __errno_location();
  return *piVar3;
}


// ===== 00242810 FUN_00242810 =====

int FUN_00242810(int *param_1)

{
  int iVar1;
  int *piVar2;
  DIR *__dirp;
  dirent *pdVar3;
  short local_fa;
  undefined4 local_f8;
  undefined2 local_f4 [2];
  undefined2 local_f0 [2];
  undefined2 local_ec [2];
  byte local_e8;
  byte local_e7;
  byte local_e6;
  byte local_e5;
  byte local_de;
  byte local_dd;
  byte local_bc;
  byte local_bb;
  byte local_ba;
  byte local_b9;
  stat local_b8;
  
  *(undefined2 *)(param_1 + 5) = 0;
  iVar1 = __xstat(1,"/sys/bus/pci/devices",&local_b8);
  if (iVar1 == 0) {
    __dirp = opendir("/sys/bus/pci/devices");
    if (__dirp != (DIR *)0x0) {
LAB_00242880:
      do {
        pdVar3 = readdir(__dirp);
        while( true ) {
          iVar1 = 0;
          if (pdVar3 == (dirent *)0x0) goto LAB_0024291a;
          if ((pdVar3->d_name[0] == '.') &&
             ((pdVar3->d_name[1] == '\0' ||
              ((pdVar3->d_name[1] == '.' && (pdVar3->d_name[2] == '\0')))))) goto LAB_00242880;
          __isoc99_sscanf(pdVar3->d_name,"%04x:%02x:%02x.%1u",&local_f8,local_f4,local_f0,local_ec);
          iVar1 = FUN_00242700(local_f8,local_f4[0],local_f0[0],local_ec[0],0,&local_e8,0x30,
                               &local_fa);
          if (local_fa == 0x30) break;
          if (iVar1 != 0) goto LAB_0024291a;
          pdVar3 = readdir(__dirp);
        }
        if (iVar1 != 0) {
LAB_0024291a:
          closedir(__dirp);
          return iVar1;
        }
        if ((((((*param_1 == -1) || (*param_1 == (uint)local_e7 * 0x100 + (uint)local_e8)) &&
              ((param_1[1] == -1 || (param_1[1] == (uint)local_e5 * 0x100 + (uint)local_e6)))) &&
             ((param_1[2] == -1 || (param_1[2] == (uint)local_bb * 0x100 + (uint)local_bc)))) &&
            ((param_1[3] == -1 || (param_1[3] == (uint)local_b9 * 0x100 + (uint)local_ba)))) &&
           (((ushort)local_dd * 0x100 + (ushort)local_de & *(ushort *)((long)param_1 + 0x12)) ==
            *(ushort *)(param_1 + 4))) {
          *(short *)(param_1 + 5) = (short)param_1[5] + 1;
        }
      } while( true );
    }
  }
  piVar2 = __errno_location();
  return *piVar2;
}


// ===== 00242a40 FUN_00242a40 =====

int FUN_00242a40(uint param_1,byte param_2,ulong param_3,byte param_4)

{
  int __fd;
  ssize_t sVar1;
  int *piVar2;
  char *__s;
  ulong uStack_120;
  char local_118 [256];
  
  if ((((int)(param_3 & 0xff) == 0 && param_1 == 0) && param_4 == 0) && param_2 == 0) {
    __s = "/sys/bus/pci/rescan";
  }
  else {
    __s = local_118;
    snprintf(__s,0xff,"/sys/bus/pci/devices/%04x:%02x:%02x.%1u/rescan",(ulong)param_1,(ulong)param_2
             ,param_3 & 0xff,(ulong)param_4);
    param_3 = uStack_120;
  }
  __fd = open(__s,1,param_3);
  if (-1 < __fd) {
    sVar1 = write(__fd,&DAT_002dd471,2);
    close(__fd);
    return (uint)(sVar1 != 2) * 5;
  }
  piVar2 = __errno_location();
  return *piVar2;
}


// ===== 00242b00 FUN_00242b00 =====

int FUN_00242b00(uint *param_1,long param_2)

{
  int iVar1;
  char *pcVar2;
  int *piVar3;
  char local_1128 [256];
  char local_1028 [4104];
  
  snprintf(local_1128,0xff,"%s/%04x:%02x:%02x.%1u/..","/sys/bus/pci/devices",(ulong)*param_1,
           (ulong)param_1[1],(ulong)param_1[2],(ulong)param_1[3]);
  pcVar2 = realpath(local_1128,local_1028);
  if (pcVar2 == (char *)0x0) {
    piVar3 = __errno_location();
    return *piVar3;
  }
  pcVar2 = strrchr(local_1028,0x2f);
  if (pcVar2 != (char *)0x0) {
    iVar1 = __isoc99_sscanf(pcVar2 + 1,"%04x:%02x:%02x.%1u",param_2,param_2 + 4,param_2 + 8,
                            param_2 + 0xc);
    if (iVar1 == 4) {
      return 0;
    }
  }
  return 2;
}


// ===== 00242be0 FUN_00242be0 =====

int FUN_00242be0(uint param_1,byte param_2,byte param_3,byte param_4,int param_5)

{
  int iVar1;
  __off_t _Var2;
  ssize_t sVar3;
  long lVar4;
  int *piVar5;
  ushort uVar6;
  long lVar7;
  int iVar8;
  short sVar9;
  ushort uVar10;
  ulong uVar11;
  ushort *__buf;
  ulong uVar12;
  ushort local_196;
  int local_188;
  ushort local_170;
  ushort local_16e;
  byte local_16c [2];
  byte local_16a;
  timeval local_168;
  timespec local_158;
  timespec local_148;
  timeval local_138 [16];
  size_t __n;
  
  uVar12 = (ulong)param_4;
  uVar11 = (ulong)param_3;
  local_158.tv_sec = 0;
  local_158.tv_nsec = 100000000;
  local_148.tv_sec = 0;
  local_148.tv_nsec = 30000000;
  local_16c[0] = 0x34;
  local_188 = 0x14;
  do {
    iVar1 = FUN_00242700(param_1,param_2,uVar11,uVar12,local_16c[0],local_16c,1,local_138);
    if ((iVar1 == 0) && ((short)local_138[0].tv_sec == 0)) {
      iVar1 = 5;
    }
    if (0xbe < (byte)(local_16c[0] - 0x40)) break;
    local_16c[0] = local_16c[0] & 0xfc;
    iVar1 = FUN_00242700(param_1,param_2,param_3,param_4,local_16c[0],&local_168,1,local_138);
    if ((iVar1 == 0) && ((short)local_138[0].tv_sec == 0)) {
      iVar1 = 5;
    }
    if ((char)local_168.tv_sec == '\x10') {
      uVar10 = local_16c[0] + 0x10;
      local_196 = (ushort)local_16c[0];
      goto LAB_00242d5c;
    }
    if ((char)local_168.tv_sec == -1) break;
    local_188 = local_188 + -1;
    local_16c[0] = local_16c[0] + 1;
  } while (local_188 != 0);
  if (iVar1 != 0) {
    return iVar1;
  }
  uVar10 = 0x10;
  local_196 = 0;
LAB_00242d5c:
  iVar1 = FUN_00242700(param_1,param_2,uVar11,uVar12,uVar10,&local_170,2,&local_16e);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (local_16e < 2) {
    return 5;
  }
  uVar6 = local_170 & 0xffef;
  local_170 = local_170 | 0x10;
  if (param_5 != 0) {
    local_170 = uVar6;
  }
  local_16e = 0;
  snprintf((char *)local_138,0xff,"%s/%04x:%02x:%02x.%1u/config","/sys/bus/pci/devices",
           (ulong)param_1,(ulong)param_2,uVar11,uVar12);
  iVar1 = open((char *)local_138,1);
  if (-1 < iVar1) {
    _Var2 = lseek(iVar1,(ulong)uVar10,0);
    if (-1 < _Var2) {
      __n = 2;
      __buf = &local_170;
      do {
        sVar9 = (short)__n;
        sVar3 = write(iVar1,__buf,__n);
        if (sVar3 < 0) {
          piVar5 = __errno_location();
          iVar8 = *piVar5;
          local_16e = 2 - sVar9;
          goto LAB_00242eca;
        }
        if (sVar3 == 0) {
          local_16e = 2 - sVar9;
          uVar11 = (ulong)(uint)param_3;
          close(iVar1);
          goto LAB_00242f20;
        }
        __buf = (ushort *)((long)__buf + sVar3);
        uVar10 = sVar9 - (short)sVar3;
        __n = (size_t)uVar10;
      } while (uVar10 != 0);
      local_16e = 2;
      iVar8 = 0;
LAB_00242eca:
      uVar11 = (ulong)(uint)param_3;
      close(iVar1);
      goto LAB_00242f17;
    }
    close(iVar1);
  }
  piVar5 = __errno_location();
  iVar8 = *piVar5;
LAB_00242f17:
  if (iVar8 != 0) {
    return iVar8;
  }
LAB_00242f20:
  if (1 < local_16e) {
    if (param_5 == 0) {
      return 0;
    }
    iVar1 = FUN_00242700(param_1,param_2,uVar11,param_4,local_196 + 0xc,local_16c,4,&local_16e);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (3 < local_16e) {
      if ((local_16a & 0x10) == 0) {
        nanosleep(&local_148,(timespec *)0x0);
LAB_002430d4:
        nanosleep(&local_158,(timespec *)0x0);
        return 0;
      }
      gettimeofday(&local_168,(__timezone_ptr_t)0x0);
      while( true ) {
        iVar1 = FUN_00242700(param_1,param_2,uVar11,param_4,local_196 + 0x12,&local_170,2,&local_16e
                            );
        if (iVar1 != 0) {
          return iVar1;
        }
        if (local_16e < 2) break;
        if ((local_170 & 0x2000) != 0) goto LAB_002430d4;
        gettimeofday(local_138,(__timezone_ptr_t)0x0);
        lVar7 = CONCAT62(local_138[0].tv_sec._2_6_,(short)local_138[0].tv_sec) -
                CONCAT71(local_168.tv_sec._1_7_,(char)local_168.tv_sec);
        lVar4 = local_138[0].tv_usec - local_168.tv_usec;
        if (lVar4 < 0) {
          lVar7 = lVar7 + -1;
          lVar4 = lVar4 + 1000000;
        }
        if ((199999 < lVar4) || (0 < lVar7)) {
          return 0x3e;
        }
      }
    }
  }
  return 5;
}


// ===== 00243110 FUN_00243110 =====

int FUN_00243110(char *param_1,void *param_2,ssize_t *param_3)

{
  int __fd;
  ssize_t sVar1;
  int *piVar2;
  
  __fd = open(param_1,0,0);
  if (-1 < __fd) {
    sVar1 = read(__fd,param_2,99);
    close(__fd);
    if (0 < sVar1) {
      *(undefined1 *)((long)param_2 + sVar1) = 0;
      *param_3 = sVar1;
      return 0;
    }
  }
  piVar2 = __errno_location();
  return -*piVar2;
}


// ===== 00243190 FUN_00243190 =====

undefined8 FUN_00243190(ulonglong *param_1)

{
  long lVar1;
  bool bVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  long lVar5;
  char *pcVar6;
  char *local_98;
  undefined8 local_90;
  char local_88 [112];
  
  local_90 = 0;
  pcVar6 = local_88;
  for (lVar5 = 0xc; lVar5 != 0; lVar5 = lVar5 + -1) {
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    pcVar6[4] = '\0';
    pcVar6[5] = '\0';
    pcVar6[6] = '\0';
    pcVar6[7] = '\0';
    pcVar6 = pcVar6 + 8;
  }
  pcVar6[0] = '\0';
  pcVar6[1] = '\0';
  pcVar6[2] = '\0';
  pcVar6[3] = '\0';
  uVar3 = FUN_00243110("/sys/devices/system/memory/block_size_bytes",local_88,&local_90);
  if (-1 < (int)uVar3) {
    bVar2 = false;
    lVar5 = local_90;
    if (0 < local_90) {
      do {
        lVar1 = lVar5 + -1;
        if (local_88[lVar5 + -1] != '\n') {
          if (bVar2) {
            local_90 = lVar5;
          }
          local_88[lVar5] = '\0';
          uVar4 = strtoull(local_88,&local_98,0x10);
          *param_1 = uVar4;
          if (*local_98 != '\0') {
            return 0xffffffea;
          }
          return 0;
        }
        bVar2 = true;
        lVar5 = lVar1;
      } while (lVar1 != 0);
    }
    return 0xffffffea;
  }
  return uVar3;
}


// ===== 00243260 FUN_00243260 =====

undefined8 FUN_00243260(undefined1 *param_1)

{
  undefined8 uVar1;
  long lVar2;
  long *plVar3;
  undefined8 local_90;
  long local_88;
  int local_80;
  short local_7c;
  char local_7a;
  
  local_90 = 0;
  plVar3 = &local_88;
  for (lVar2 = 0xc; lVar2 != 0; lVar2 = lVar2 + -1) {
    *plVar3 = 0;
    plVar3 = plVar3 + 1;
  }
  *(undefined4 *)plVar3 = 0;
  uVar1 = FUN_00243110("/sys/devices/system/memory/auto_online_blocks",&local_88,&local_90);
  if (-1 < (int)uVar1) {
    if (0 < local_90) {
      do {
        lVar2 = local_90 + -1;
        if (*(char *)((long)&local_90 + local_90 + 7) != '\n') {
          *(undefined1 *)((long)&local_88 + local_90) = 0;
          if ((((local_88 == 0x6d5f656e696c6e6f) && (local_80 == 0x6261766f)) &&
              (local_7c == 0x656c)) && (local_7a == '\0')) {
            *param_1 = 1;
            return 0;
          }
          *param_1 = 0;
          return 0;
        }
        local_90 = lVar2;
      } while (lVar2 != 0);
    }
    return 0xffffffea;
  }
  return uVar1;
}


// ===== 00243340 FUN_00243340 =====

int FUN_00243340(undefined8 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *__ptr;
  undefined8 local_48;
  undefined4 local_40;
  undefined1 auStack_3c [12];
  undefined8 local_30;
  
  puVar2 = (undefined4 *)param_1[2];
  __ptr = calloc(0x10c,1);
  if (__ptr == (undefined4 *)0x0) {
    iVar3 = 0x51;
  }
  else {
    iVar3 = 0x1a;
    *__ptr = *puVar2;
    __ptr[1] = puVar2[1];
    iVar1 = puVar2[4];
    __ptr[0x42] = iVar1;
    if ((uint)(iVar1 << 3) < 5) {
      local_48 = *param_1;
      auStack_3c = SUB1612((undefined1  [16])0x0,4);
      local_40 = 0x2080a00c;
      auStack_3c._4_8_ = __ptr;
      local_30 = 0x10c;
      iVar3 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_48,(long)&local_30 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_30._4_4_;
      if (iVar3 == 0) {
        *puVar2 = *__ptr;
        puVar2[1] = __ptr[1];
        puVar2[4] = __ptr[0x42];
      }
    }
    free(__ptr);
  }
  return iVar3;
}


// ===== 00243440 FUN_00243440 =====

int FUN_00243440(undefined8 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *__ptr;
  long lVar4;
  ulong uVar5;
  uint uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  byte bVar9;
  undefined8 local_58;
  undefined4 local_50;
  undefined1 auStack_4c [12];
  undefined8 local_40;
  
  bVar9 = 0;
  puVar2 = (undefined4 *)param_1[2];
  __ptr = calloc(0x30c,1);
  if (__ptr == (undefined4 *)0x0) {
    iVar3 = 0x51;
  }
  else {
    iVar3 = 0x1a;
    *__ptr = *puVar2;
    __ptr[1] = puVar2[1];
    iVar1 = puVar2[4];
    __ptr[0xc2] = iVar1;
    uVar6 = iVar1 * 0x18;
    if (uVar6 < 0x301) {
      if (uVar6 != 0) {
        puVar7 = *(undefined8 **)(puVar2 + 2);
        if (uVar6 < 8) {
          if (uVar6 != 0) {
            *(undefined1 *)(__ptr + 2) = *(undefined1 *)puVar7;
          }
        }
        else {
          *(undefined8 *)((long)__ptr + (ulong)uVar6) =
               *(undefined8 *)((long)puVar7 + ((ulong)uVar6 - 8));
          puVar8 = (undefined8 *)(__ptr + 2);
          for (uVar5 = (ulong)(uVar6 - 1 >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + (ulong)bVar9 * -2 + 1;
            puVar8 = puVar8 + (ulong)bVar9 * -2 + 1;
          }
        }
      }
      local_58 = *param_1;
      auStack_4c = SUB1612((undefined1  [16])0x0,4);
      local_50 = 0x2080200b;
      auStack_4c._4_8_ = __ptr;
      local_40 = 0x30c;
      iVar3 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_58,(long)&local_40 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_40._4_4_;
      if (iVar3 == 0) {
        *puVar2 = *__ptr;
        puVar2[1] = __ptr[1];
        puVar2[4] = __ptr[0xc2];
        if (uVar6 != 0) {
          puVar7 = *(undefined8 **)(puVar2 + 2);
          if (uVar6 < 8) {
            if (uVar6 != 0) {
              *(undefined1 *)puVar7 = *(undefined1 *)(__ptr + 2);
            }
          }
          else {
            *puVar7 = *(undefined8 *)(__ptr + 2);
            *(undefined8 *)((long)puVar7 + ((ulong)uVar6 - 8)) =
                 *(undefined8 *)((long)__ptr + (ulong)uVar6);
            lVar4 = (long)puVar7 - (long)((ulong)(puVar7 + 1) & 0xfffffffffffffff8);
            puVar8 = (undefined8 *)((long)__ptr + (8 - lVar4));
            puVar7 = (undefined8 *)((ulong)(puVar7 + 1) & 0xfffffffffffffff8);
            for (uVar5 = (ulong)((int)lVar4 + uVar6 >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
              *puVar7 = *puVar8;
              puVar8 = puVar8 + (ulong)bVar9 * -2 + 1;
              puVar7 = puVar7 + (ulong)bVar9 * -2 + 1;
            }
          }
        }
      }
    }
    free(__ptr);
  }
  return iVar3;
}


// ===== 002435f0 FUN_002435f0 =====

/* WARNING: Removing unreachable block (ram,0x00243761) */
/* WARNING: Removing unreachable block (ram,0x002437ce) */

int FUN_002435f0(undefined8 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *__ptr;
  undefined8 *puVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  undefined4 *puVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  uint uVar12;
  ulong uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined4 *__src;
  byte bVar17;
  uint local_68;
  uint local_60;
  undefined8 local_58;
  undefined1 local_50 [8];
  undefined4 *puStack_48;
  undefined8 local_40;
  
  bVar17 = 0;
  puVar2 = (undefined4 *)param_1[2];
  if (0x10 < (uint)puVar2[1]) {
    return 0x1f;
  }
  __ptr = calloc(0xa518,1);
  if (__ptr == (undefined4 *)0x0) {
    return 0x51;
  }
  *__ptr = *puVar2;
  __ptr[1] = puVar2[1];
  iVar3 = puVar2[2];
  __ptr[2] = iVar3;
  iVar4 = puVar2[3];
  __ptr[3] = iVar4;
  __ptr[0x2824] = puVar2[100];
  iVar1 = puVar2[0x65];
  __ptr[0x2825] = iVar1;
  uVar14 = iVar1 * 0x24;
  if (uVar14 < 0x481) {
    if (uVar14 != 0) {
      puVar5 = *(undefined8 **)(puVar2 + 0x66);
      if (uVar14 < 8) {
        if ((uVar14 & 4) == 0) {
          if (uVar14 != 0) {
            *(undefined1 *)(__ptr + 0x2826) = *(undefined1 *)puVar5;
          }
        }
        else {
          __ptr[0x2826] = *(undefined4 *)puVar5;
          *(undefined4 *)((long)__ptr + (ulong)uVar14 + 0xa094) =
               *(undefined4 *)((long)puVar5 + ((ulong)uVar14 - 4));
        }
      }
      else {
        *(undefined8 *)((long)__ptr + (ulong)uVar14 + 0xa090) =
             *(undefined8 *)((long)puVar5 + ((ulong)uVar14 - 8));
        puVar10 = (undefined8 *)(__ptr + 0x2826);
        for (uVar8 = (ulong)(uVar14 - 1 >> 3); uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar10 = *puVar5;
          puVar5 = puVar5 + (ulong)bVar17 * -2 + 1;
          puVar10 = puVar10 + (ulong)bVar17 * -2 + 1;
        }
      }
    }
    uVar15 = iVar3 * 0x2c;
    uVar16 = iVar4 * 0x24;
    if (puVar2[1] != 0) {
      if ((0x580 < uVar15) || (0x480 < uVar16)) goto LAB_00243770;
      puVar9 = puVar2 + 4;
      uVar12 = 0;
      uVar8 = (ulong)uVar15;
      puVar5 = (undefined8 *)(__ptr + 0x166);
      uVar13 = (ulong)uVar16;
      local_60 = uVar15 & 4;
      local_68 = uVar16 & 4;
      do {
        *(undefined4 *)(puVar5 + -0xb1) = *puVar9;
        *(undefined4 *)((long)puVar5 + -0x584) = puVar9[1];
        if (uVar15 != 0) {
          puVar11 = *(undefined8 **)(puVar9 + 2);
          puVar10 = puVar5 + -0xb0;
          if (uVar15 < 8) {
            if (local_60 == 0) {
              if (uVar15 != 0) {
                *(undefined1 *)puVar10 = *(undefined1 *)puVar11;
              }
            }
            else {
              *(undefined4 *)puVar10 = *(undefined4 *)puVar11;
              *(undefined4 *)((long)puVar5 + (uVar8 - 0x584)) =
                   *(undefined4 *)((long)puVar11 + (uVar8 - 4));
            }
          }
          else {
            puVar5[-0xb0] = *puVar11;
            *(undefined8 *)((long)puVar5 + (uVar8 - 0x588)) =
                 *(undefined8 *)((long)puVar11 + (uVar8 - 8));
            lVar7 = (long)puVar10 - (long)((ulong)(puVar5 + -0xaf) & 0xfffffffffffffff8);
            puVar10 = (undefined8 *)((long)puVar11 - lVar7);
            puVar11 = (undefined8 *)((ulong)(puVar5 + -0xaf) & 0xfffffffffffffff8);
            for (uVar6 = (ulong)((int)lVar7 + uVar15 >> 3); uVar6 != 0; uVar6 = uVar6 - 1) {
              *puVar11 = *puVar10;
              puVar10 = puVar10 + (ulong)bVar17 * -2 + 1;
              puVar11 = puVar11 + (ulong)bVar17 * -2 + 1;
            }
          }
        }
        if (uVar16 != 0) {
          puVar10 = *(undefined8 **)(puVar9 + 4);
          if (uVar16 < 8) {
            if (local_68 == 0) {
              if (uVar16 != 0) {
                *(undefined1 *)puVar5 = *(undefined1 *)puVar10;
              }
            }
            else {
              *(undefined4 *)puVar5 = *(undefined4 *)puVar10;
              *(undefined4 *)((long)puVar5 + (uVar13 - 4)) =
                   *(undefined4 *)((long)puVar10 + (uVar13 - 4));
            }
          }
          else {
            *puVar5 = *puVar10;
            *(undefined8 *)((long)puVar5 + (uVar13 - 8)) =
                 *(undefined8 *)((long)puVar10 + (uVar13 - 8));
            lVar7 = (long)puVar5 - (long)((ulong)(puVar5 + 1) & 0xfffffffffffffff8);
            puVar10 = (undefined8 *)((long)puVar10 - lVar7);
            puVar11 = (undefined8 *)((ulong)(puVar5 + 1) & 0xfffffffffffffff8);
            for (uVar6 = (ulong)((int)lVar7 + uVar16 >> 3); uVar6 != 0; uVar6 = uVar6 - 1) {
              *puVar11 = *puVar10;
              puVar10 = puVar10 + (ulong)bVar17 * -2 + 1;
              puVar11 = puVar11 + (ulong)bVar17 * -2 + 1;
            }
          }
        }
        uVar12 = uVar12 + 1;
        puVar9 = puVar9 + 6;
        puVar5 = puVar5 + 0x141;
      } while (uVar12 < (uint)puVar2[1]);
    }
    local_58 = *param_1;
    stack0xffffffffffffffb4 = SUB1612((undefined1  [16])0x0,4);
    local_50._0_4_ = 0x2080a06b;
    puStack_48 = __ptr;
    local_40 = 0xa518;
    iVar3 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_58,(long)&local_40 + 4);
    *(undefined4 *)((long)param_1 + 0x1c) = local_40._4_4_;
    if (iVar3 == 0) {
      *puVar2 = *__ptr;
      iVar4 = __ptr[1];
      puVar2[1] = iVar4;
      puVar2[2] = __ptr[2];
      puVar2[3] = __ptr[3];
      puVar2[100] = __ptr[0x2824];
      puVar2[0x65] = __ptr[0x2825];
      if (uVar14 != 0) {
        puVar5 = *(undefined8 **)(puVar2 + 0x66);
        if (uVar14 < 8) {
          if ((uVar14 & 4) == 0) {
            if (uVar14 != 0) {
              *(undefined1 *)puVar5 = *(undefined1 *)(__ptr + 0x2826);
            }
          }
          else {
            *(undefined4 *)puVar5 = __ptr[0x2826];
            *(undefined4 *)((long)puVar5 + ((ulong)uVar14 - 4)) =
                 *(undefined4 *)((long)__ptr + (ulong)uVar14 + 0xa094);
          }
        }
        else {
          *puVar5 = *(undefined8 *)(__ptr + 0x2826);
          *(undefined8 *)((long)puVar5 + ((ulong)uVar14 - 8)) =
               *(undefined8 *)((long)__ptr + (ulong)uVar14 + 0xa090);
          lVar7 = (long)puVar5 - (long)((ulong)(puVar5 + 1) & 0xfffffffffffffff8);
          puVar10 = (undefined8 *)((long)__ptr + (0xa098 - lVar7));
          puVar5 = (undefined8 *)((ulong)(puVar5 + 1) & 0xfffffffffffffff8);
          for (uVar8 = (ulong)((int)lVar7 + uVar14 >> 3); uVar8 != 0; uVar8 = uVar8 - 1) {
            *puVar5 = *puVar10;
            puVar10 = puVar10 + (ulong)bVar17 * -2 + 1;
            puVar5 = puVar5 + (ulong)bVar17 * -2 + 1;
          }
        }
        iVar4 = puVar2[1];
      }
      puVar9 = puVar2 + 4;
      __src = __ptr + 0x166;
      if (iVar4 != 0) {
        uVar14 = 0;
        do {
          *puVar9 = __src[-0x162];
          puVar9[1] = __src[-0x161];
          if (uVar15 != 0) {
            memcpy(*(void **)(puVar9 + 2),__src + -0x160,(ulong)uVar15);
          }
          if (uVar16 != 0) {
            memcpy(*(void **)(puVar9 + 4),__src,(ulong)uVar16);
          }
          uVar14 = uVar14 + 1;
          puVar9 = puVar9 + 6;
          __src = __src + 0x282;
        } while (uVar14 < (uint)puVar2[1]);
      }
    }
  }
  else {
LAB_00243770:
    iVar3 = 0x1a;
  }
  free(__ptr);
  return iVar3;
}


// ===== 00243ad0 FUN_00243ad0 =====

/* WARNING: Removing unreachable block (ram,0x00243c49) */
/* WARNING: Removing unreachable block (ram,0x00243cbe) */

int FUN_00243ad0(undefined8 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *__ptr;
  undefined8 *puVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  undefined4 *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  uint uVar11;
  ulong uVar12;
  uint uVar13;
  uint uVar14;
  undefined4 *__src;
  uint uVar15;
  byte bVar16;
  uint local_68;
  uint local_60;
  undefined8 local_58;
  undefined1 local_50 [8];
  undefined4 *puStack_48;
  undefined8 local_40;
  
  bVar16 = 0;
  puVar1 = (undefined4 *)param_1[2];
  if (0x10 < (uint)puVar1[1]) {
    return 0x1f;
  }
  __ptr = calloc(0xa518,1);
  if (__ptr == (undefined4 *)0x0) {
    return 0x51;
  }
  *__ptr = *puVar1;
  __ptr[1] = puVar1[1];
  __ptr[2] = puVar1[2];
  __ptr[3] = puVar1[3];
  __ptr[0x2824] = puVar1[100];
  iVar2 = puVar1[0x65];
  __ptr[0x2825] = iVar2;
  uVar13 = iVar2 * 0x24;
  if (uVar13 < 0x481) {
    iVar2 = puVar1[2];
    iVar3 = puVar1[3];
    if (uVar13 != 0) {
      puVar4 = *(undefined8 **)(puVar1 + 0x66);
      if (uVar13 < 8) {
        if ((uVar13 & 4) == 0) {
          if (uVar13 != 0) {
            *(undefined1 *)(__ptr + 0x2826) = *(undefined1 *)puVar4;
          }
        }
        else {
          __ptr[0x2826] = *(undefined4 *)puVar4;
          *(undefined4 *)((long)__ptr + (ulong)uVar13 + 0xa094) =
               *(undefined4 *)((long)puVar4 + ((ulong)uVar13 - 4));
        }
      }
      else {
        *(undefined8 *)((long)__ptr + (ulong)uVar13 + 0xa090) =
             *(undefined8 *)((long)puVar4 + ((ulong)uVar13 - 8));
        puVar9 = (undefined8 *)(__ptr + 0x2826);
        for (uVar7 = (ulong)(uVar13 - 1 >> 3); uVar7 != 0; uVar7 = uVar7 - 1) {
          *puVar9 = *puVar4;
          puVar4 = puVar4 + (ulong)bVar16 * -2 + 1;
          puVar9 = puVar9 + (ulong)bVar16 * -2 + 1;
        }
      }
    }
    uVar15 = iVar2 * 0x2c;
    uVar14 = iVar3 * 0x24;
    if (puVar1[1] != 0) {
      if ((0x580 < uVar15) || (0x480 < uVar14)) goto LAB_00243c60;
      puVar8 = puVar1 + 4;
      uVar11 = 0;
      uVar7 = (ulong)uVar15;
      puVar4 = (undefined8 *)(__ptr + 0x166);
      uVar12 = (ulong)uVar14;
      local_60 = uVar15 & 4;
      local_68 = uVar14 & 4;
      do {
        *(undefined4 *)(puVar4 + -0xb1) = *puVar8;
        *(undefined4 *)((long)puVar4 + -0x584) = puVar8[1];
        if (uVar15 != 0) {
          puVar10 = *(undefined8 **)(puVar8 + 2);
          puVar9 = puVar4 + -0xb0;
          if (uVar15 < 8) {
            if (local_60 == 0) {
              if (uVar15 != 0) {
                *(undefined1 *)puVar9 = *(undefined1 *)puVar10;
              }
            }
            else {
              *(undefined4 *)puVar9 = *(undefined4 *)puVar10;
              *(undefined4 *)((long)puVar4 + (uVar7 - 0x584)) =
                   *(undefined4 *)((long)puVar10 + (uVar7 - 4));
            }
          }
          else {
            puVar4[-0xb0] = *puVar10;
            *(undefined8 *)((long)puVar4 + (uVar7 - 0x588)) =
                 *(undefined8 *)((long)puVar10 + (uVar7 - 8));
            lVar6 = (long)puVar9 - (long)((ulong)(puVar4 + -0xaf) & 0xfffffffffffffff8);
            puVar9 = (undefined8 *)((long)puVar10 - lVar6);
            puVar10 = (undefined8 *)((ulong)(puVar4 + -0xaf) & 0xfffffffffffffff8);
            for (uVar5 = (ulong)((int)lVar6 + uVar15 >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
              *puVar10 = *puVar9;
              puVar9 = puVar9 + (ulong)bVar16 * -2 + 1;
              puVar10 = puVar10 + (ulong)bVar16 * -2 + 1;
            }
          }
        }
        if (uVar14 != 0) {
          puVar9 = *(undefined8 **)(puVar8 + 4);
          if (uVar14 < 8) {
            if (local_68 == 0) {
              if (uVar14 != 0) {
                *(undefined1 *)puVar4 = *(undefined1 *)puVar9;
              }
            }
            else {
              *(undefined4 *)puVar4 = *(undefined4 *)puVar9;
              *(undefined4 *)((long)puVar4 + (uVar12 - 4)) =
                   *(undefined4 *)((long)puVar9 + (uVar12 - 4));
            }
          }
          else {
            *puVar4 = *puVar9;
            *(undefined8 *)((long)puVar4 + (uVar12 - 8)) =
                 *(undefined8 *)((long)puVar9 + (uVar12 - 8));
            lVar6 = (long)puVar4 - (long)((ulong)(puVar4 + 1) & 0xfffffffffffffff8);
            puVar9 = (undefined8 *)((long)puVar9 - lVar6);
            puVar10 = (undefined8 *)((ulong)(puVar4 + 1) & 0xfffffffffffffff8);
            for (uVar5 = (ulong)((int)lVar6 + uVar14 >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
              *puVar10 = *puVar9;
              puVar9 = puVar9 + (ulong)bVar16 * -2 + 1;
              puVar10 = puVar10 + (ulong)bVar16 * -2 + 1;
            }
          }
        }
        uVar11 = uVar11 + 1;
        puVar8 = puVar8 + 6;
        puVar4 = puVar4 + 0x141;
      } while (uVar11 < (uint)puVar1[1]);
    }
    local_58 = *param_1;
    stack0xffffffffffffffb4 = SUB1612((undefined1  [16])0x0,4);
    local_50._0_4_ = 0x2080e06c;
    puStack_48 = __ptr;
    local_40 = 0xa518;
    iVar2 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_58,(long)&local_40 + 4);
    *(undefined4 *)((long)param_1 + 0x1c) = local_40._4_4_;
    if (iVar2 == 0) {
      *puVar1 = *__ptr;
      iVar3 = __ptr[1];
      puVar1[1] = iVar3;
      puVar1[2] = __ptr[2];
      puVar1[3] = __ptr[3];
      puVar1[100] = __ptr[0x2824];
      puVar1[0x65] = __ptr[0x2825];
      if (uVar13 != 0) {
        puVar4 = *(undefined8 **)(puVar1 + 0x66);
        if (uVar13 < 8) {
          if ((uVar13 & 4) == 0) {
            if (uVar13 != 0) {
              *(undefined1 *)puVar4 = *(undefined1 *)(__ptr + 0x2826);
            }
          }
          else {
            *(undefined4 *)puVar4 = __ptr[0x2826];
            *(undefined4 *)((long)puVar4 + ((ulong)uVar13 - 4)) =
                 *(undefined4 *)((long)__ptr + (ulong)uVar13 + 0xa094);
          }
        }
        else {
          *puVar4 = *(undefined8 *)(__ptr + 0x2826);
          *(undefined8 *)((long)puVar4 + ((ulong)uVar13 - 8)) =
               *(undefined8 *)((long)__ptr + (ulong)uVar13 + 0xa090);
          lVar6 = (long)puVar4 - (long)((ulong)(puVar4 + 1) & 0xfffffffffffffff8);
          puVar9 = (undefined8 *)((long)__ptr + (0xa098 - lVar6));
          puVar4 = (undefined8 *)((ulong)(puVar4 + 1) & 0xfffffffffffffff8);
          for (uVar7 = (ulong)((int)lVar6 + uVar13 >> 3); uVar7 != 0; uVar7 = uVar7 - 1) {
            *puVar4 = *puVar9;
            puVar9 = puVar9 + (ulong)bVar16 * -2 + 1;
            puVar4 = puVar4 + (ulong)bVar16 * -2 + 1;
          }
        }
        iVar3 = puVar1[1];
      }
      puVar8 = puVar1 + 4;
      __src = __ptr + 0x166;
      if (iVar3 != 0) {
        uVar13 = 0;
        do {
          *puVar8 = __src[-0x162];
          puVar8[1] = __src[-0x161];
          if (uVar15 != 0) {
            memcpy(*(void **)(puVar8 + 2),__src + -0x160,(ulong)uVar15);
          }
          if (uVar14 != 0) {
            memcpy(*(void **)(puVar8 + 4),__src,(ulong)uVar14);
          }
          uVar13 = uVar13 + 1;
          puVar8 = puVar8 + 6;
          __src = __src + 0x282;
        } while (uVar13 < (uint)puVar1[1]);
      }
    }
  }
  else {
LAB_00243c60:
    iVar2 = 0x1a;
  }
  free(__ptr);
  return iVar2;
}


// ===== 00243fd0 FUN_00243fd0 =====

undefined8 FUN_00243fd0(void *param_1,uint param_2,undefined8 *param_3)

{
  void *__ptr;
  undefined8 uVar1;
  
  __ptr = malloc((ulong)param_2);
  *param_3 = __ptr;
  if (__ptr == (void *)0x0) {
    uVar1 = 0x51;
  }
  else {
    if ((param_2 == 0) || (param_1 == (void *)0x0)) {
      free(__ptr);
      *param_3 = 0;
      return 0x1f;
    }
    uVar1 = 0;
    if (__ptr != param_1) {
      memcpy(__ptr,param_1,(ulong)param_2);
    }
  }
  return uVar1;
}


// ===== 00244050 FUN_00244050 =====

undefined8 FUN_00244050(long *param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long *plVar4;
  undefined8 uVar5;
  long lVar6;
  long *plVar7;
  uint uVar8;
  uint uVar9;
  
  lVar6 = *param_1;
  *(long *)(param_2 + 0x10) = lVar6;
  if (*(uint *)(param_1 + 0x10) < 2) {
    return 0;
  }
  uVar9 = 1;
  plVar4 = param_1;
  do {
    plVar7 = plVar4 + 4;
    uVar2 = *(uint *)((long)plVar4 + 0x34);
    if (*(uint *)(plVar4 + 7) == 0xffffffff) {
      uVar8 = *(uint *)(plVar4 + 6);
LAB_002440a9:
      lVar6 = *(long *)(lVar6 + (ulong)uVar2);
      plVar4[5] = lVar6;
      uVar5 = FUN_00243fd0(lVar6,uVar8,plVar7);
      if ((int)uVar5 != 0) {
        return uVar5;
      }
      *(long *)(*(long *)(param_2 + 0x10) + (ulong)uVar2) = *plVar7;
    }
    else {
      uVar3 = *(uint *)((ulong)*(uint *)(plVar4 + 7) + lVar6);
      if (uVar3 != 0) {
        if (*(char *)((long)plVar4 + 0x3c) == '\0') {
          *(uint *)(plVar4 + 6) = uVar3;
          lVar6 = *(long *)(param_2 + 0x10);
          uVar8 = uVar3;
        }
        else {
          uVar1 = *(uint *)(plVar4 + 6);
          uVar8 = uVar1 * uVar3;
          *(uint *)(plVar4 + 6) = uVar8;
          if (uVar3 != uVar8 / uVar1) {
            return 0x1f;
          }
          lVar6 = *(long *)(param_2 + 0x10);
        }
        goto LAB_002440a9;
      }
    }
    uVar9 = uVar9 + 1;
    if (*(uint *)(param_1 + 0x10) <= uVar9) {
      return 0;
    }
    lVar6 = *(long *)(param_2 + 0x10);
    plVar4 = plVar7;
  } while( true );
}


// ===== 00244140 FUN_00244140 =====

void FUN_00244140(long *param_1,long param_2)

{
  long *plVar1;
  void *pvVar2;
  void *pvVar3;
  uint uVar4;
  
  pvVar3 = (void *)*param_1;
  if (pvVar3 != (void *)0x0) {
    uVar4 = (int)param_1[0x10] - 1;
    if (uVar4 != 0) {
      plVar1 = param_1 + (ulong)uVar4 * 4;
      do {
        if ((*(int *)((ulong)*(uint *)(plVar1 + 3) + *(long *)(param_2 + 0x10)) != 0) &&
           (*plVar1 != 0)) {
          pvVar3 = (void *)plVar1[1];
          *(void **)((ulong)*(uint *)((long)plVar1 + 0x14) + *(long *)(param_2 + 0x10)) = pvVar3;
          pvVar2 = (void *)*plVar1;
          if (((*(uint *)(plVar1 + 2) != 0 && pvVar2 != (void *)0x0) && pvVar3 != (void *)0x0) &&
             (pvVar3 != pvVar2)) {
            memcpy(pvVar3,pvVar2,(ulong)*(uint *)(plVar1 + 2));
            pvVar2 = (void *)*plVar1;
          }
          free(pvVar2);
          *plVar1 = 0;
        }
        plVar1 = plVar1 + -4;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
      pvVar3 = (void *)*param_1;
    }
    pvVar2 = (void *)param_1[1];
    if (((pvVar2 != (void *)0x0 && *(uint *)(param_1 + 2) != 0) && pvVar3 != (void *)0x0) &&
       (pvVar2 != pvVar3)) {
      memcpy(pvVar2,pvVar3,(ulong)*(uint *)(param_1 + 2));
      pvVar3 = (void *)*param_1;
    }
    free(pvVar3);
    *param_1 = 0;
    *(long *)(param_2 + 0x10) = param_1[1];
  }
  return;
}


// ===== 00244230 FUN_00244230 =====

int FUN_00244230(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *__ptr;
  long lVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  uint uVar8;
  uint uVar9;
  byte bVar10;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined1 auStack_dc [12];
  undefined8 local_d0;
  undefined8 local_c8 [2];
  undefined4 local_b8;
  undefined4 local_b0;
  undefined8 local_98;
  undefined4 local_90;
  undefined1 local_8c;
  undefined8 local_78;
  undefined4 local_70;
  undefined1 local_6c;
  undefined4 local_48;
  
  bVar10 = 0;
  uVar1 = param_1[2];
  puVar6 = local_c8;
  for (lVar4 = 0x11; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  local_8c = 1;
  local_98 = 0x1000000010;
  local_b8 = 0x28;
  local_b0 = 0xffffffff;
  local_90 = 8;
  local_78 = 0x2000000024;
  local_70 = 0x18;
  local_6c = 1;
  local_48 = 3;
  local_c8[1] = uVar1;
  iVar3 = FUN_00243fd0(uVar1,0x28,local_c8);
  if ((iVar3 == 0) && (iVar3 = FUN_00244050(local_c8,param_1), iVar3 == 0)) {
    puVar2 = (undefined4 *)param_1[2];
    uVar9 = puVar2[2] * 0x10;
    uVar8 = puVar2[6] * 0x24;
    __ptr = calloc(0x690,1);
    if (__ptr == (undefined4 *)0x0) {
      FUN_00244140(local_c8,param_1);
      return 0x51;
    }
    if ((0x200 < uVar9) || (0x480 < uVar8)) {
      free(__ptr);
      FUN_00244140(local_c8,param_1);
      return 0x1a;
    }
    *__ptr = *puVar2;
    __ptr[1] = puVar2[1];
    __ptr[2] = puVar2[2];
    __ptr[0x83] = puVar2[6];
    if (uVar9 != 0) {
      puVar6 = *(undefined8 **)(puVar2 + 4);
      if (uVar9 < 8) {
        if (uVar9 != 0) {
          *(undefined1 *)(__ptr + 3) = *(undefined1 *)puVar6;
        }
      }
      else {
        *(undefined8 *)(__ptr + 3) = *puVar6;
        *(undefined8 *)((long)__ptr + (ulong)uVar9 + 4) =
             *(undefined8 *)((long)puVar6 + ((ulong)uVar9 - 8));
        lVar4 = (long)__ptr + (0xc - (long)((ulong)(__ptr + 5) & 0xfffffffffffffff8));
        puVar6 = (undefined8 *)((long)puVar6 - lVar4);
        puVar7 = (undefined8 *)((ulong)(__ptr + 5) & 0xfffffffffffffff8);
        for (uVar5 = (ulong)((int)lVar4 + uVar9 >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + (ulong)bVar10 * -2 + 1;
          puVar7 = puVar7 + (ulong)bVar10 * -2 + 1;
        }
      }
    }
    if (uVar8 != 0) {
      puVar6 = *(undefined8 **)(puVar2 + 8);
      if (uVar8 < 8) {
        if ((uVar8 & 4) == 0) {
          if (uVar8 != 0) {
            *(undefined1 *)(__ptr + 0x84) = *(undefined1 *)puVar6;
          }
        }
        else {
          __ptr[0x84] = *(undefined4 *)puVar6;
          *(undefined4 *)((long)__ptr + (ulong)uVar8 + 0x20c) =
               *(undefined4 *)((long)puVar6 + ((ulong)uVar8 - 4));
        }
      }
      else {
        *(undefined8 *)((long)__ptr + (ulong)uVar8 + 0x208) =
             *(undefined8 *)((long)puVar6 + ((ulong)uVar8 - 8));
        puVar7 = (undefined8 *)(__ptr + 0x84);
        for (uVar5 = (ulong)(uVar8 - 1 >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + (ulong)bVar10 * -2 + 1;
          puVar7 = puVar7 + (ulong)bVar10 * -2 + 1;
        }
      }
    }
    local_e8 = *param_1;
    auStack_dc = SUB1612((undefined1  [16])0x0,4);
    local_e0 = 0x2080a09f;
    auStack_dc._4_8_ = __ptr;
    local_d0 = 0x690;
    iVar3 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
    *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
    if (iVar3 == 0) {
      *puVar2 = *__ptr;
      puVar2[1] = __ptr[1];
      puVar2[2] = __ptr[2];
      puVar2[6] = __ptr[0x83];
      if (uVar9 != 0) {
        puVar6 = *(undefined8 **)(puVar2 + 4);
        if (uVar9 < 8) {
          if (uVar9 != 0) {
            *(undefined1 *)puVar6 = *(undefined1 *)(__ptr + 3);
          }
        }
        else {
          *puVar6 = *(undefined8 *)(__ptr + 3);
          *(undefined8 *)((long)puVar6 + ((ulong)uVar9 - 8)) =
               *(undefined8 *)((long)__ptr + (ulong)uVar9 + 4);
          lVar4 = (long)puVar6 - (long)((ulong)(puVar6 + 1) & 0xfffffffffffffff8);
          puVar7 = (undefined8 *)((long)__ptr + (0xc - lVar4));
          puVar6 = (undefined8 *)((ulong)(puVar6 + 1) & 0xfffffffffffffff8);
          for (uVar5 = (ulong)((int)lVar4 + uVar9 >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar6 = *puVar7;
            puVar7 = puVar7 + (ulong)bVar10 * -2 + 1;
            puVar6 = puVar6 + (ulong)bVar10 * -2 + 1;
          }
        }
      }
      if (uVar8 != 0) {
        puVar6 = *(undefined8 **)(puVar2 + 8);
        if (uVar8 < 8) {
          if ((uVar8 & 4) == 0) {
            if (uVar8 != 0) {
              *(undefined1 *)puVar6 = *(undefined1 *)(__ptr + 0x84);
            }
          }
          else {
            *(undefined4 *)puVar6 = __ptr[0x84];
            *(undefined4 *)((long)puVar6 + ((ulong)uVar8 - 4)) =
                 *(undefined4 *)((long)__ptr + (ulong)uVar8 + 0x20c);
          }
        }
        else {
          *puVar6 = *(undefined8 *)(__ptr + 0x84);
          *(undefined8 *)((long)puVar6 + ((ulong)uVar8 - 8)) =
               *(undefined8 *)((long)__ptr + (ulong)uVar8 + 0x208);
          lVar4 = (long)puVar6 - (long)((ulong)(puVar6 + 1) & 0xfffffffffffffff8);
          puVar7 = (undefined8 *)((long)(__ptr + 0x84) - lVar4);
          puVar6 = (undefined8 *)((ulong)(puVar6 + 1) & 0xfffffffffffffff8);
          for (uVar5 = (ulong)((int)lVar4 + uVar8 >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar6 = *puVar7;
            puVar7 = puVar7 + (ulong)bVar10 * -2 + 1;
            puVar6 = puVar6 + (ulong)bVar10 * -2 + 1;
          }
        }
      }
    }
    free(__ptr);
  }
  FUN_00244140(local_c8,param_1);
  return iVar3;
}


// ===== 00244690 FUN_00244690 =====

int FUN_00244690(undefined8 *param_1)

{
  undefined8 uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 *puVar5;
  long lVar6;
  uint uVar7;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined1 auStack_dc [12];
  undefined8 local_d0;
  undefined8 local_c8 [2];
  undefined4 local_b8;
  undefined4 local_b0;
  undefined8 local_98;
  undefined1 local_8c;
  undefined4 local_48;
  
  uVar1 = param_1[2];
  puVar5 = local_c8;
  for (lVar6 = 0x11; lVar6 != 0; lVar6 = lVar6 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  local_8c = 1;
  local_b8 = 0x10;
  local_b0 = 0xffffffff;
  local_98 = 0x800000148;
  local_48 = 2;
  local_c8[1] = uVar1;
  iVar4 = FUN_00243fd0(uVar1,0x10,local_c8);
  if ((iVar4 == 0) && (iVar4 = FUN_00244050(local_c8,param_1), iVar4 == 0)) {
    piVar2 = (int *)param_1[2];
    uVar7 = *piVar2 * 0x148;
    puVar5 = malloc(0x14804);
    if (puVar5 == (undefined8 *)0x0) {
      FUN_00244140(local_c8,param_1);
      return 0x51;
    }
    if (0x14800 < uVar7) {
      free(puVar5);
      FUN_00244140(local_c8,param_1);
      return 0x1a;
    }
    uVar1 = *(undefined8 *)(piVar2 + 2);
    *puVar5 = *(undefined8 *)piVar2;
    puVar5[1] = uVar1;
    uVar3 = DAT_00380490;
    if (uVar7 == 0) {
      local_e8 = *param_1;
      auStack_dc = SUB1612((undefined1  [16])0x0,4);
      local_e0 = 0x2080a079;
      auStack_dc._4_8_ = puVar5;
      local_d0 = 0x14804;
      iVar4 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
      free(puVar5);
    }
    else {
      memcpy((void *)((long)puVar5 + 4),*(void **)(piVar2 + 2),(ulong)uVar7);
      local_e8 = *param_1;
      auStack_dc = SUB1612((undefined1  [16])0x0,4);
      local_e0 = 0x2080a079;
      auStack_dc._4_8_ = puVar5;
      local_d0 = 0x14804;
      iVar4 = FUN_0023d7d0(uVar3,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
      if (iVar4 == 0) {
        memcpy(*(void **)(piVar2 + 2),(void *)((long)puVar5 + 4),(ulong)uVar7);
      }
      free(puVar5);
    }
  }
  FUN_00244140(local_c8,param_1);
  return iVar4;
}


// ===== 00244920 FUN_00244920 =====

int FUN_00244920(undefined8 *param_1)

{
  undefined8 uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 *puVar5;
  long lVar6;
  uint uVar7;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined1 auStack_dc [12];
  undefined8 local_d0;
  undefined8 local_c8 [2];
  undefined4 local_b8;
  undefined4 local_b0;
  undefined8 local_98;
  undefined1 local_8c;
  undefined4 local_48;
  
  uVar1 = param_1[2];
  puVar5 = local_c8;
  for (lVar6 = 0x11; lVar6 != 0; lVar6 = lVar6 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  local_8c = 1;
  local_b8 = 0x10;
  local_b0 = 0xffffffff;
  local_98 = 0x80000013c;
  local_48 = 2;
  local_c8[1] = uVar1;
  iVar4 = FUN_00243fd0(uVar1,0x10,local_c8);
  if ((iVar4 == 0) && (iVar4 = FUN_00244050(local_c8,param_1), iVar4 == 0)) {
    piVar2 = (int *)param_1[2];
    uVar7 = *piVar2 * 0x13c;
    puVar5 = malloc(0x13c08);
    if (puVar5 == (undefined8 *)0x0) {
      FUN_00244140(local_c8,param_1);
      return 0x51;
    }
    if (0x13c00 < uVar7) {
      free(puVar5);
      FUN_00244140(local_c8,param_1);
      return 0x1a;
    }
    uVar1 = *(undefined8 *)(piVar2 + 2);
    *puVar5 = *(undefined8 *)piVar2;
    puVar5[1] = uVar1;
    uVar3 = DAT_00380490;
    if (uVar7 == 0) {
      local_e8 = *param_1;
      auStack_dc = SUB1612((undefined1  [16])0x0,4);
      local_e0 = 0x2080e0af;
      auStack_dc._4_8_ = puVar5;
      local_d0 = 0x13c08;
      iVar4 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
      free(puVar5);
    }
    else {
      memcpy(puVar5 + 1,*(void **)(piVar2 + 2),(ulong)uVar7);
      local_e8 = *param_1;
      auStack_dc = SUB1612((undefined1  [16])0x0,4);
      local_e0 = 0x2080e0af;
      auStack_dc._4_8_ = puVar5;
      local_d0 = 0x13c08;
      iVar4 = FUN_0023d7d0(uVar3,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
      if (iVar4 == 0) {
        memcpy(*(void **)(piVar2 + 2),puVar5 + 1,(ulong)uVar7);
      }
      free(puVar5);
    }
  }
  FUN_00244140(local_c8,param_1);
  return iVar4;
}


// ===== 00244bb0 FUN_00244bb0 =====

int FUN_00244bb0(undefined8 *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 *__ptr;
  long lVar5;
  ulong uVar6;
  uint uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  byte bVar11;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined1 auStack_dc [12];
  undefined8 local_d0;
  undefined8 local_c8 [2];
  undefined4 local_b8;
  undefined4 local_b0;
  undefined8 local_98;
  undefined4 local_90;
  undefined1 local_8c;
  undefined4 local_48;
  
  bVar11 = 0;
  uVar2 = param_1[2];
  puVar10 = local_c8;
  for (lVar5 = 0x11; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  local_8c = 1;
  local_b8 = 0x10;
  local_b0 = 0xffffffff;
  local_98 = 0x800000010;
  local_90 = 4;
  local_48 = 2;
  local_c8[1] = uVar2;
  iVar4 = FUN_00243fd0(uVar2,0x10,local_c8);
  if ((iVar4 == 0) && (iVar4 = FUN_00244050(local_c8,param_1), iVar4 == 0)) {
    puVar10 = (undefined8 *)param_1[2];
    uVar1 = *(uint *)((long)puVar10 + 4);
    __ptr = malloc(0x208);
    uVar7 = uVar1 * 0x10;
    if (__ptr == (undefined8 *)0x0) {
      FUN_00244140(local_c8,param_1);
      return 0x51;
    }
    if (0x200 < uVar7) {
      free(__ptr);
      FUN_00244140(local_c8,param_1);
      return 0x1a;
    }
    uVar2 = puVar10[1];
    *__ptr = *puVar10;
    __ptr[1] = uVar2;
    uVar3 = DAT_00380490;
    if ((uVar1 & 0xfffffff) == 0) {
      local_e8 = *param_1;
      auStack_dc = SUB1612((undefined1  [16])0x0,4);
      local_e0 = 0x20809064;
      auStack_dc._4_8_ = __ptr;
      local_d0 = 0x208;
      iVar4 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
      free(__ptr);
    }
    else {
      puVar8 = (undefined8 *)puVar10[1];
      if (uVar7 < 8) {
        if ((uVar1 & 0xfffffff) != 0) {
          *(undefined1 *)(__ptr + 1) = *(undefined1 *)puVar8;
        }
      }
      else {
        *(undefined8 *)((long)__ptr + (ulong)uVar7) =
             *(undefined8 *)((long)puVar8 + ((ulong)uVar7 - 8));
        puVar9 = __ptr + 1;
        for (uVar6 = (ulong)(uVar7 - 1 >> 3); uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + (ulong)bVar11 * -2 + 1;
          puVar9 = puVar9 + (ulong)bVar11 * -2 + 1;
        }
      }
      local_e8 = *param_1;
      auStack_dc = SUB1612((undefined1  [16])0x0,4);
      local_e0 = 0x20809064;
      auStack_dc._4_8_ = __ptr;
      local_d0 = 0x208;
      iVar4 = FUN_0023d7d0(uVar3,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
      if (iVar4 == 0) {
        puVar10 = (undefined8 *)puVar10[1];
        if (uVar7 < 8) {
          if ((uVar1 & 0xfffffff) != 0) {
            *(undefined1 *)puVar10 = *(undefined1 *)(__ptr + 1);
          }
        }
        else {
          *puVar10 = __ptr[1];
          *(undefined8 *)((long)puVar10 + ((ulong)uVar7 - 8)) =
               *(undefined8 *)((long)__ptr + (ulong)uVar7);
          lVar5 = (long)puVar10 - (long)((ulong)(puVar10 + 1) & 0xfffffffffffffff8);
          puVar8 = (undefined8 *)((long)(__ptr + 1) - lVar5);
          puVar10 = (undefined8 *)((ulong)(puVar10 + 1) & 0xfffffffffffffff8);
          for (uVar6 = (ulong)((int)lVar5 + uVar7 >> 3); uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar10 = *puVar8;
            puVar8 = puVar8 + (ulong)bVar11 * -2 + 1;
            puVar10 = puVar10 + (ulong)bVar11 * -2 + 1;
          }
        }
      }
      free(__ptr);
    }
  }
  FUN_00244140(local_c8,param_1);
  return iVar4;
}


// ===== 00244ed0 FUN_00244ed0 =====

int FUN_00244ed0(undefined8 *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 *__ptr;
  long lVar5;
  ulong uVar6;
  uint uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  byte bVar11;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined1 auStack_dc [12];
  undefined8 local_d0;
  undefined8 local_c8 [2];
  undefined4 local_b8;
  undefined4 local_b0;
  undefined8 local_98;
  undefined4 local_90;
  undefined1 local_8c;
  undefined4 local_48;
  
  bVar11 = 0;
  uVar2 = param_1[2];
  puVar10 = local_c8;
  for (lVar5 = 0x11; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  local_8c = 1;
  local_b8 = 0x10;
  local_b0 = 0xffffffff;
  local_98 = 0x800000010;
  local_90 = 4;
  local_48 = 2;
  local_c8[1] = uVar2;
  iVar4 = FUN_00243fd0(uVar2,0x10,local_c8);
  if ((iVar4 == 0) && (iVar4 = FUN_00244050(local_c8,param_1), iVar4 == 0)) {
    puVar10 = (undefined8 *)param_1[2];
    uVar1 = *(uint *)((long)puVar10 + 4);
    __ptr = malloc(0x208);
    uVar7 = uVar1 * 0x10;
    if (__ptr == (undefined8 *)0x0) {
      FUN_00244140(local_c8,param_1);
      return 0x51;
    }
    if (0x200 < uVar7) {
      free(__ptr);
      FUN_00244140(local_c8,param_1);
      return 0x1a;
    }
    uVar2 = puVar10[1];
    *__ptr = *puVar10;
    __ptr[1] = uVar2;
    uVar3 = DAT_00380490;
    if ((uVar1 & 0xfffffff) == 0) {
      local_e8 = *param_1;
      auStack_dc = SUB1612((undefined1  [16])0x0,4);
      local_e0 = 0x20809063;
      auStack_dc._4_8_ = __ptr;
      local_d0 = 0x208;
      iVar4 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
      free(__ptr);
    }
    else {
      puVar8 = (undefined8 *)puVar10[1];
      if (uVar7 < 8) {
        if ((uVar1 & 0xfffffff) != 0) {
          *(undefined1 *)(__ptr + 1) = *(undefined1 *)puVar8;
        }
      }
      else {
        *(undefined8 *)((long)__ptr + (ulong)uVar7) =
             *(undefined8 *)((long)puVar8 + ((ulong)uVar7 - 8));
        puVar9 = __ptr + 1;
        for (uVar6 = (ulong)(uVar7 - 1 >> 3); uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + (ulong)bVar11 * -2 + 1;
          puVar9 = puVar9 + (ulong)bVar11 * -2 + 1;
        }
      }
      local_e8 = *param_1;
      auStack_dc = SUB1612((undefined1  [16])0x0,4);
      local_e0 = 0x20809063;
      auStack_dc._4_8_ = __ptr;
      local_d0 = 0x208;
      iVar4 = FUN_0023d7d0(uVar3,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
      if (iVar4 == 0) {
        puVar10 = (undefined8 *)puVar10[1];
        if (uVar7 < 8) {
          if ((uVar1 & 0xfffffff) != 0) {
            *(undefined1 *)puVar10 = *(undefined1 *)(__ptr + 1);
          }
        }
        else {
          *puVar10 = __ptr[1];
          *(undefined8 *)((long)puVar10 + ((ulong)uVar7 - 8)) =
               *(undefined8 *)((long)__ptr + (ulong)uVar7);
          lVar5 = (long)puVar10 - (long)((ulong)(puVar10 + 1) & 0xfffffffffffffff8);
          puVar8 = (undefined8 *)((long)(__ptr + 1) - lVar5);
          puVar10 = (undefined8 *)((ulong)(puVar10 + 1) & 0xfffffffffffffff8);
          for (uVar6 = (ulong)((int)lVar5 + uVar7 >> 3); uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar10 = *puVar8;
            puVar8 = puVar8 + (ulong)bVar11 * -2 + 1;
            puVar10 = puVar10 + (ulong)bVar11 * -2 + 1;
          }
        }
      }
      free(__ptr);
    }
  }
  FUN_00244140(local_c8,param_1);
  return iVar4;
}


// ===== 002451f0 FUN_002451f0 =====

int FUN_002451f0(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 *__ptr;
  long lVar4;
  ulong uVar5;
  uint uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  byte bVar10;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined1 auStack_dc [12];
  undefined8 local_d0;
  undefined8 local_c8 [2];
  undefined4 local_b8;
  undefined4 local_b0;
  undefined8 local_98;
  undefined4 local_90;
  undefined1 local_8c;
  undefined4 local_48;
  
  bVar10 = 0;
  uVar1 = param_1[2];
  puVar9 = local_c8;
  for (lVar4 = 0x11; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  local_8c = 1;
  local_b8 = 0x10;
  local_b0 = 0xffffffff;
  local_98 = 0x800000014;
  local_90 = 4;
  local_48 = 2;
  local_c8[1] = uVar1;
  iVar3 = FUN_00243fd0(uVar1,0x10,local_c8);
  if ((iVar3 == 0) && (iVar3 = FUN_00244050(local_c8,param_1), iVar3 == 0)) {
    puVar9 = (undefined8 *)param_1[2];
    uVar6 = *(int *)((long)puVar9 + 4) * 0x14;
    __ptr = malloc(0x288);
    if (__ptr == (undefined8 *)0x0) {
      FUN_00244140(local_c8,param_1);
      return 0x51;
    }
    if (0x280 < uVar6) {
      free(__ptr);
      FUN_00244140(local_c8,param_1);
      return 0x1a;
    }
    uVar1 = puVar9[1];
    *__ptr = *puVar9;
    __ptr[1] = uVar1;
    uVar2 = DAT_00380490;
    if (uVar6 == 0) {
      local_e8 = *param_1;
      auStack_dc = SUB1612((undefined1  [16])0x0,4);
      local_e0 = 0x2080d041;
      auStack_dc._4_8_ = __ptr;
      local_d0 = 0x288;
      iVar3 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
      free(__ptr);
    }
    else {
      puVar7 = (undefined8 *)puVar9[1];
      if (uVar6 < 8) {
        if ((uVar6 & 4) == 0) {
          if (uVar6 != 0) {
            *(undefined1 *)(__ptr + 1) = *(undefined1 *)puVar7;
          }
        }
        else {
          *(undefined4 *)(__ptr + 1) = *(undefined4 *)puVar7;
          *(undefined4 *)((long)__ptr + (ulong)uVar6 + 4) =
               *(undefined4 *)((long)puVar7 + ((ulong)uVar6 - 4));
        }
      }
      else {
        *(undefined8 *)((long)__ptr + (ulong)uVar6) =
             *(undefined8 *)((long)puVar7 + ((ulong)uVar6 - 8));
        puVar8 = __ptr + 1;
        for (uVar5 = (ulong)(uVar6 - 1 >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + (ulong)bVar10 * -2 + 1;
          puVar8 = puVar8 + (ulong)bVar10 * -2 + 1;
        }
      }
      local_e8 = *param_1;
      auStack_dc = SUB1612((undefined1  [16])0x0,4);
      local_e0 = 0x2080d041;
      auStack_dc._4_8_ = __ptr;
      local_d0 = 0x288;
      iVar3 = FUN_0023d7d0(uVar2,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
      if (iVar3 == 0) {
        puVar9 = (undefined8 *)puVar9[1];
        if (uVar6 < 8) {
          if ((uVar6 & 4) == 0) {
            if (uVar6 != 0) {
              *(undefined1 *)puVar9 = *(undefined1 *)(__ptr + 1);
            }
          }
          else {
            *(undefined4 *)puVar9 = *(undefined4 *)(__ptr + 1);
            *(undefined4 *)((long)puVar9 + ((ulong)uVar6 - 4)) =
                 *(undefined4 *)((long)__ptr + (ulong)uVar6 + 4);
          }
        }
        else {
          *puVar9 = __ptr[1];
          *(undefined8 *)((long)puVar9 + ((ulong)uVar6 - 8)) =
               *(undefined8 *)((long)__ptr + (ulong)uVar6);
          lVar4 = (long)puVar9 - (long)((ulong)(puVar9 + 1) & 0xfffffffffffffff8);
          puVar7 = (undefined8 *)((long)(__ptr + 1) - lVar4);
          puVar9 = (undefined8 *)((ulong)(puVar9 + 1) & 0xfffffffffffffff8);
          for (uVar5 = (ulong)((int)lVar4 + uVar6 >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar9 = *puVar7;
            puVar7 = puVar7 + (ulong)bVar10 * -2 + 1;
            puVar9 = puVar9 + (ulong)bVar10 * -2 + 1;
          }
        }
      }
      free(__ptr);
    }
  }
  FUN_00244140(local_c8,param_1);
  return iVar3;
}


// ===== 00245540 FUN_00245540 =====

int FUN_00245540(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 *__ptr;
  long lVar4;
  ulong uVar5;
  uint uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  byte bVar10;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined1 auStack_dc [12];
  undefined8 local_d0;
  undefined8 local_c8 [2];
  undefined4 local_b8;
  undefined4 local_b0;
  undefined8 local_98;
  undefined4 local_90;
  undefined1 local_8c;
  undefined4 local_48;
  
  bVar10 = 0;
  uVar1 = param_1[2];
  puVar9 = local_c8;
  for (lVar4 = 0x11; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  local_8c = 1;
  local_b8 = 0x10;
  local_b0 = 0xffffffff;
  local_98 = 0x800000014;
  local_90 = 4;
  local_48 = 2;
  local_c8[1] = uVar1;
  iVar3 = FUN_00243fd0(uVar1,0x10,local_c8);
  if ((iVar3 == 0) && (iVar3 = FUN_00244050(local_c8,param_1), iVar3 == 0)) {
    puVar9 = (undefined8 *)param_1[2];
    uVar6 = *(int *)((long)puVar9 + 4) * 0x14;
    __ptr = malloc(0x288);
    if (__ptr == (undefined8 *)0x0) {
      FUN_00244140(local_c8,param_1);
      return 0x51;
    }
    if (0x280 < uVar6) {
      free(__ptr);
      FUN_00244140(local_c8,param_1);
      return 0x1a;
    }
    uVar1 = puVar9[1];
    *__ptr = *puVar9;
    __ptr[1] = uVar1;
    uVar2 = DAT_00380490;
    if (uVar6 == 0) {
      local_e8 = *param_1;
      auStack_dc = SUB1612((undefined1  [16])0x0,4);
      local_e0 = 0x20809062;
      auStack_dc._4_8_ = __ptr;
      local_d0 = 0x288;
      iVar3 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
      free(__ptr);
    }
    else {
      puVar7 = (undefined8 *)puVar9[1];
      if (uVar6 < 8) {
        if ((uVar6 & 4) == 0) {
          if (uVar6 != 0) {
            *(undefined1 *)(__ptr + 1) = *(undefined1 *)puVar7;
          }
        }
        else {
          *(undefined4 *)(__ptr + 1) = *(undefined4 *)puVar7;
          *(undefined4 *)((long)__ptr + (ulong)uVar6 + 4) =
               *(undefined4 *)((long)puVar7 + ((ulong)uVar6 - 4));
        }
      }
      else {
        *(undefined8 *)((long)__ptr + (ulong)uVar6) =
             *(undefined8 *)((long)puVar7 + ((ulong)uVar6 - 8));
        puVar8 = __ptr + 1;
        for (uVar5 = (ulong)(uVar6 - 1 >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + (ulong)bVar10 * -2 + 1;
          puVar8 = puVar8 + (ulong)bVar10 * -2 + 1;
        }
      }
      local_e8 = *param_1;
      auStack_dc = SUB1612((undefined1  [16])0x0,4);
      local_e0 = 0x20809062;
      auStack_dc._4_8_ = __ptr;
      local_d0 = 0x288;
      iVar3 = FUN_0023d7d0(uVar2,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
      if (iVar3 == 0) {
        puVar9 = (undefined8 *)puVar9[1];
        if (uVar6 < 8) {
          if ((uVar6 & 4) == 0) {
            if (uVar6 != 0) {
              *(undefined1 *)puVar9 = *(undefined1 *)(__ptr + 1);
            }
          }
          else {
            *(undefined4 *)puVar9 = *(undefined4 *)(__ptr + 1);
            *(undefined4 *)((long)puVar9 + ((ulong)uVar6 - 4)) =
                 *(undefined4 *)((long)__ptr + (ulong)uVar6 + 4);
          }
        }
        else {
          *puVar9 = __ptr[1];
          *(undefined8 *)((long)puVar9 + ((ulong)uVar6 - 8)) =
               *(undefined8 *)((long)__ptr + (ulong)uVar6);
          lVar4 = (long)puVar9 - (long)((ulong)(puVar9 + 1) & 0xfffffffffffffff8);
          puVar7 = (undefined8 *)((long)(__ptr + 1) - lVar4);
          puVar9 = (undefined8 *)((ulong)(puVar9 + 1) & 0xfffffffffffffff8);
          for (uVar5 = (ulong)((int)lVar4 + uVar6 >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar9 = *puVar7;
            puVar7 = puVar7 + (ulong)bVar10 * -2 + 1;
            puVar9 = puVar9 + (ulong)bVar10 * -2 + 1;
          }
        }
      }
      free(__ptr);
    }
  }
  FUN_00244140(local_c8,param_1);
  return iVar3;
}


// ===== 00245890 FUN_00245890 =====

int FUN_00245890(undefined8 *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 *__ptr;
  long lVar5;
  undefined8 *puVar6;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined1 auStack_dc [12];
  undefined8 local_d0;
  undefined8 local_c8 [2];
  undefined4 local_b8;
  undefined4 local_b0;
  undefined8 local_98;
  undefined4 local_90;
  undefined4 local_48;
  
  uVar2 = param_1[2];
  puVar6 = local_c8;
  for (lVar5 = 0x11; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  local_48 = 2;
  local_b8 = 0x18;
  local_b0 = 0xffffffff;
  local_98 = 0x1000000308;
  local_90 = 4;
  local_c8[1] = uVar2;
  iVar4 = FUN_00243fd0(uVar2,0x18,local_c8);
  if ((iVar4 == 0) && (iVar4 = FUN_00244050(local_c8,param_1), iVar4 == 0)) {
    puVar6 = (undefined8 *)param_1[2];
    uVar1 = *(uint *)((long)puVar6 + 4);
    __ptr = malloc(0xda50);
    if (__ptr == (undefined8 *)0x0) {
      FUN_00244140(local_c8,param_1);
      return 0x51;
    }
    if (0xda40 < uVar1) {
      free(__ptr);
      FUN_00244140(local_c8,param_1);
      return 0x1a;
    }
    uVar2 = puVar6[1];
    *__ptr = *puVar6;
    __ptr[1] = uVar2;
    __ptr[2] = puVar6[2];
    uVar3 = DAT_00380490;
    if (uVar1 == 0) {
      local_e8 = *param_1;
      auStack_dc = SUB1612((undefined1  [16])0x0,4);
      local_e0 = 0x20802096;
      auStack_dc._4_8_ = __ptr;
      local_d0 = 0xda50;
      iVar4 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
    }
    else {
      memcpy(__ptr + 2,(void *)puVar6[2],(ulong)uVar1);
      local_e8 = *param_1;
      auStack_dc = SUB1612((undefined1  [16])0x0,4);
      local_e0 = 0x20802096;
      auStack_dc._4_8_ = __ptr;
      local_d0 = 0xda50;
      iVar4 = FUN_0023d7d0(uVar3,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
      if (iVar4 == 0) {
        memcpy((void *)puVar6[2],__ptr + 2,(ulong)uVar1);
      }
    }
    free(__ptr);
  }
  FUN_00244140(local_c8,param_1);
  return iVar4;
}


// ===== 00245b10 FUN_00245b10 =====

int FUN_00245b10(undefined8 *param_1)

{
  undefined8 uVar1;
  int *piVar2;
  int iVar3;
  int *__ptr;
  long lVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  uint uVar8;
  byte bVar9;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined1 auStack_dc [12];
  undefined8 local_d0;
  undefined8 local_c8 [2];
  undefined4 local_b8;
  undefined4 local_b0;
  undefined8 local_98;
  undefined1 local_8c;
  undefined4 local_48;
  
  bVar9 = 0;
  uVar1 = param_1[2];
  puVar6 = local_c8;
  for (lVar4 = 0x11; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  local_8c = 1;
  local_b8 = 0x18;
  local_b0 = 0xffffffff;
  local_98 = 0x800000010;
  local_48 = 2;
  local_c8[1] = uVar1;
  iVar3 = FUN_00243fd0(uVar1,0x18,local_c8);
  if ((iVar3 == 0) && (iVar3 = FUN_00244050(local_c8,param_1), iVar3 == 0)) {
    piVar2 = (int *)param_1[2];
    iVar3 = *piVar2;
    uVar8 = iVar3 * 0x10;
    __ptr = malloc(0xff8);
    if (__ptr == (int *)0x0) {
      FUN_00244140(local_c8,param_1);
      return 0x51;
    }
    if (0xff0 < uVar8) {
      free(__ptr);
      FUN_00244140(local_c8,param_1);
      return 0x1a;
    }
    *__ptr = iVar3;
    if (uVar8 == 0) {
      local_e8 = *param_1;
      auStack_dc = SUB1612((undefined1  [16])0x0,4);
      local_e0 = 0x2080a043;
      auStack_dc._4_8_ = __ptr;
      local_d0 = 0xff8;
      iVar3 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
      if (iVar3 == 0) {
        piVar2[4] = __ptr[0x3fd];
      }
    }
    else {
      puVar6 = *(undefined8 **)(piVar2 + 2);
      if (uVar8 < 8) {
        if (uVar8 != 0) {
          *(undefined1 *)(__ptr + 1) = *(undefined1 *)puVar6;
        }
      }
      else {
        *(undefined8 *)(__ptr + 1) = *puVar6;
        lVar4 = (long)__ptr + (4 - (long)((ulong)(__ptr + 3) & 0xfffffffffffffff8));
        *(undefined8 *)((long)__ptr + ((ulong)uVar8 - 4)) =
             *(undefined8 *)((long)puVar6 + ((ulong)uVar8 - 8));
        puVar6 = (undefined8 *)((long)puVar6 - lVar4);
        puVar7 = (undefined8 *)((ulong)(__ptr + 3) & 0xfffffffffffffff8);
        for (uVar5 = (ulong)((int)lVar4 + uVar8 >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + (ulong)bVar9 * -2 + 1;
          puVar7 = puVar7 + (ulong)bVar9 * -2 + 1;
        }
      }
      local_e8 = *param_1;
      auStack_dc = SUB1612((undefined1  [16])0x0,4);
      local_e0 = 0x2080a043;
      auStack_dc._4_8_ = __ptr;
      local_d0 = 0xff8;
      iVar3 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
      if (iVar3 == 0) {
        puVar6 = *(undefined8 **)(piVar2 + 2);
        piVar2[4] = __ptr[0x3fd];
        if (uVar8 < 8) {
          if (uVar8 != 0) {
            *(char *)puVar6 = (char)__ptr[1];
          }
        }
        else {
          *puVar6 = *(undefined8 *)(__ptr + 1);
          *(undefined8 *)((long)puVar6 + ((ulong)uVar8 - 8)) =
               *(undefined8 *)((long)__ptr + ((ulong)uVar8 - 4));
          lVar4 = (long)puVar6 - (long)((ulong)(puVar6 + 1) & 0xfffffffffffffff8);
          puVar7 = (undefined8 *)((long)__ptr + (4 - lVar4));
          puVar6 = (undefined8 *)((ulong)(puVar6 + 1) & 0xfffffffffffffff8);
          for (uVar5 = (ulong)((int)lVar4 + uVar8 >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar6 = *puVar7;
            puVar7 = puVar7 + (ulong)bVar9 * -2 + 1;
            puVar6 = puVar6 + (ulong)bVar9 * -2 + 1;
          }
        }
      }
    }
    free(__ptr);
  }
  FUN_00244140(local_c8,param_1);
  return iVar3;
}


// ===== 00245e50 FUN_00245e50 =====

int FUN_00245e50(undefined8 *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 *__ptr;
  long lVar5;
  ulong uVar6;
  uint uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  byte bVar11;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined1 auStack_dc [12];
  undefined8 local_d0;
  undefined8 local_c8 [2];
  undefined4 local_b8;
  undefined4 local_b0;
  undefined8 local_98;
  undefined4 local_90;
  undefined1 local_8c;
  undefined4 local_48;
  
  bVar11 = 0;
  uVar2 = param_1[2];
  puVar10 = local_c8;
  for (lVar5 = 0x11; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  local_8c = 1;
  local_b8 = 0x20;
  local_b0 = 0xffffffff;
  local_98 = 0x1800000010;
  local_90 = 0x10;
  local_48 = 2;
  local_c8[1] = uVar2;
  iVar4 = FUN_00243fd0(uVar2,0x20,local_c8);
  if ((iVar4 == 0) && (iVar4 = FUN_00244050(local_c8,param_1), iVar4 == 0)) {
    puVar10 = (undefined8 *)param_1[2];
    uVar1 = *(uint *)(puVar10 + 2);
    __ptr = malloc(0x214);
    uVar7 = uVar1 * 0x10;
    if (__ptr == (undefined8 *)0x0) {
      FUN_00244140(local_c8,param_1);
      return 0x51;
    }
    if (0x200 < uVar7) {
      free(__ptr);
      FUN_00244140(local_c8,param_1);
      return 0x1a;
    }
    uVar2 = puVar10[1];
    *__ptr = *puVar10;
    __ptr[1] = uVar2;
    uVar2 = puVar10[3];
    __ptr[2] = puVar10[2];
    __ptr[3] = uVar2;
    uVar3 = DAT_00380490;
    if ((uVar1 & 0xfffffff) == 0) {
      local_e8 = *param_1;
      auStack_dc = SUB1612((undefined1  [16])0x0,4);
      local_e0 = 0x2080a00d;
      auStack_dc._4_8_ = __ptr;
      local_d0 = 0x214;
      iVar4 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
    }
    else {
      puVar8 = (undefined8 *)puVar10[3];
      if (uVar7 < 8) {
        if ((uVar1 & 0xfffffff) != 0) {
          *(undefined1 *)((long)__ptr + 0x14) = *(undefined1 *)puVar8;
        }
      }
      else {
        puVar9 = (undefined8 *)((long)__ptr + 0x1cU & 0xfffffffffffffff8);
        *(undefined8 *)((long)__ptr + 0x14) = *puVar8;
        lVar5 = (long)__ptr + (0x14 - (long)puVar9);
        *(undefined8 *)((long)__ptr + (ulong)uVar7 + 0xc) =
             *(undefined8 *)((long)puVar8 + ((ulong)uVar7 - 8));
        puVar8 = (undefined8 *)((long)puVar8 - lVar5);
        for (uVar6 = (ulong)((int)lVar5 + uVar7 >> 3); uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + (ulong)bVar11 * -2 + 1;
          puVar9 = puVar9 + (ulong)bVar11 * -2 + 1;
        }
      }
      local_e8 = *param_1;
      auStack_dc = SUB1612((undefined1  [16])0x0,4);
      local_e0 = 0x2080a00d;
      auStack_dc._4_8_ = __ptr;
      local_d0 = 0x214;
      iVar4 = FUN_0023d7d0(uVar3,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
      if (iVar4 == 0) {
        puVar10 = (undefined8 *)puVar10[3];
        if (uVar7 < 8) {
          if ((uVar1 & 0xfffffff) != 0) {
            *(undefined1 *)puVar10 = *(undefined1 *)((long)__ptr + 0x14);
          }
        }
        else {
          *puVar10 = *(undefined8 *)((long)__ptr + 0x14);
          *(undefined8 *)((long)puVar10 + ((ulong)uVar7 - 8)) =
               *(undefined8 *)((long)__ptr + (ulong)uVar7 + 0xc);
          lVar5 = (long)puVar10 - (long)((ulong)(puVar10 + 1) & 0xfffffffffffffff8);
          puVar8 = (undefined8 *)((long)__ptr + (0x14 - lVar5));
          puVar10 = (undefined8 *)((ulong)(puVar10 + 1) & 0xfffffffffffffff8);
          for (uVar6 = (ulong)((int)lVar5 + uVar7 >> 3); uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar10 = *puVar8;
            puVar8 = puVar8 + (ulong)bVar11 * -2 + 1;
            puVar10 = puVar10 + (ulong)bVar11 * -2 + 1;
          }
        }
      }
    }
    free(__ptr);
  }
  FUN_00244140(local_c8,param_1);
  return iVar4;
}


// ===== 00246180 FUN_00246180 =====

int FUN_00246180(undefined8 *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 *__ptr;
  long lVar5;
  ulong uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  byte bVar10;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined1 auStack_dc [12];
  undefined8 local_d0;
  undefined8 local_c8 [2];
  undefined4 local_b8;
  undefined4 local_b0;
  undefined8 local_98;
  undefined4 local_90;
  undefined1 local_8c;
  undefined4 local_48;
  
  bVar10 = 0;
  uVar2 = param_1[2];
  puVar9 = local_c8;
  for (lVar5 = 0x11; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  local_8c = 1;
  local_b8 = 0x18;
  local_b0 = 0xffffffff;
  local_98 = 0x1000000004;
  local_90 = 8;
  local_48 = 2;
  local_c8[1] = uVar2;
  iVar4 = FUN_00243fd0(uVar2,0x18,local_c8);
  if ((iVar4 == 0) && (iVar4 = FUN_00244050(local_c8,param_1), iVar4 == 0)) {
    puVar9 = (undefined8 *)param_1[2];
    uVar1 = *(int *)(puVar9 + 1) * 4;
    __ptr = malloc(0x408);
    if (__ptr == (undefined8 *)0x0) {
      FUN_00244140(local_c8,param_1);
      return 0x51;
    }
    if (0x3fc < uVar1) {
      free(__ptr);
      FUN_00244140(local_c8,param_1);
      return 0x1a;
    }
    uVar2 = puVar9[1];
    *__ptr = *puVar9;
    __ptr[1] = uVar2;
    __ptr[2] = puVar9[2];
    uVar3 = DAT_00380490;
    if (uVar1 == 0) {
      local_e8 = *param_1;
      auStack_dc = SUB1612((undefined1  [16])0x0,4);
      local_e0 = 0x2080a07f;
      auStack_dc._4_8_ = __ptr;
      local_d0 = 0x408;
      iVar4 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
    }
    else {
      puVar7 = (undefined8 *)puVar9[2];
      if (uVar1 < 8) {
        if ((uVar1 & 4) == 0) {
          if (uVar1 != 0) {
            *(undefined1 *)((long)__ptr + 0xc) = *(undefined1 *)puVar7;
          }
        }
        else {
          *(undefined4 *)((long)__ptr + 0xc) = *(undefined4 *)puVar7;
          *(undefined4 *)((long)__ptr + (ulong)uVar1 + 8) =
               *(undefined4 *)((long)puVar7 + ((ulong)uVar1 - 4));
        }
      }
      else {
        puVar8 = (undefined8 *)((long)__ptr + 0x14U & 0xfffffffffffffff8);
        *(undefined8 *)((long)__ptr + 0xc) = *puVar7;
        lVar5 = (long)__ptr + (0xc - (long)puVar8);
        *(undefined8 *)((long)__ptr + (ulong)uVar1 + 4) =
             *(undefined8 *)((long)puVar7 + ((ulong)uVar1 - 8));
        puVar7 = (undefined8 *)((long)puVar7 - lVar5);
        for (uVar6 = (ulong)((int)lVar5 + uVar1 >> 3); uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + (ulong)bVar10 * -2 + 1;
          puVar8 = puVar8 + (ulong)bVar10 * -2 + 1;
        }
      }
      local_e8 = *param_1;
      auStack_dc = SUB1612((undefined1  [16])0x0,4);
      local_e0 = 0x2080a07f;
      auStack_dc._4_8_ = __ptr;
      local_d0 = 0x408;
      iVar4 = FUN_0023d7d0(uVar3,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
      *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
      if (iVar4 == 0) {
        puVar9 = (undefined8 *)puVar9[2];
        if (uVar1 < 8) {
          if ((uVar1 & 4) == 0) {
            if (uVar1 != 0) {
              *(undefined1 *)puVar9 = *(undefined1 *)((long)__ptr + 0xc);
            }
          }
          else {
            *(undefined4 *)puVar9 = *(undefined4 *)((long)__ptr + 0xc);
            *(undefined4 *)((long)puVar9 + ((ulong)uVar1 - 4)) =
                 *(undefined4 *)((long)__ptr + (ulong)uVar1 + 8);
          }
        }
        else {
          *puVar9 = *(undefined8 *)((long)__ptr + 0xc);
          *(undefined8 *)((long)puVar9 + ((ulong)uVar1 - 8)) =
               *(undefined8 *)((long)__ptr + (ulong)uVar1 + 4);
          lVar5 = (long)puVar9 - (long)((ulong)(puVar9 + 1) & 0xfffffffffffffff8);
          puVar7 = (undefined8 *)((long)__ptr + (0xc - lVar5));
          puVar9 = (undefined8 *)((ulong)(puVar9 + 1) & 0xfffffffffffffff8);
          for (uVar6 = (ulong)((int)lVar5 + uVar1 >> 3); uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar9 = *puVar7;
            puVar7 = puVar7 + (ulong)bVar10 * -2 + 1;
            puVar9 = puVar9 + (ulong)bVar10 * -2 + 1;
          }
        }
      }
    }
    free(__ptr);
  }
  FUN_00244140(local_c8,param_1);
  return iVar4;
}


// ===== 002464f0 FUN_002464f0 =====

int FUN_002464f0(undefined8 *param_1)

{
  undefined8 uVar1;
  int *piVar2;
  int iVar3;
  int *__ptr;
  long lVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  uint uVar8;
  byte bVar9;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined1 auStack_dc [12];
  undefined8 local_d0;
  undefined8 local_c8 [2];
  undefined4 local_b8;
  undefined4 local_b0;
  undefined8 local_98;
  undefined1 local_8c;
  undefined4 local_48;
  
  bVar9 = 0;
  uVar1 = param_1[2];
  puVar6 = local_c8;
  for (lVar4 = 0x11; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  local_8c = 1;
  local_b8 = 0x28;
  local_b0 = 0xffffffff;
  local_98 = 0x800000010;
  local_48 = 2;
  local_c8[1] = uVar1;
  iVar3 = FUN_00243fd0(uVar1,0x28,local_c8);
  if ((iVar3 == 0) && (iVar3 = FUN_00244050(local_c8,param_1), iVar3 == 0)) {
    piVar2 = (int *)param_1[2];
    iVar3 = *piVar2;
    uVar8 = iVar3 * 0x10;
    __ptr = malloc(0x490);
    if (__ptr == (int *)0x0) {
      FUN_00244140(local_c8,param_1);
      return 0x51;
    }
    if (0x200 < uVar8) {
      free(__ptr);
      FUN_00244140(local_c8,param_1);
      return 0x1a;
    }
    *__ptr = iVar3;
    __ptr[0x81] = 0;
    if (uVar8 != 0) {
      puVar6 = *(undefined8 **)(piVar2 + 2);
      if (uVar8 < 8) {
        if (uVar8 != 0) {
          *(undefined1 *)(__ptr + 1) = *(undefined1 *)puVar6;
        }
      }
      else {
        *(undefined8 *)(__ptr + 1) = *puVar6;
        lVar4 = (long)__ptr + (4 - (long)((ulong)(__ptr + 3) & 0xfffffffffffffff8));
        *(undefined8 *)((long)__ptr + ((ulong)uVar8 - 4)) =
             *(undefined8 *)((long)puVar6 + ((ulong)uVar8 - 8));
        puVar6 = (undefined8 *)((long)puVar6 - lVar4);
        puVar7 = (undefined8 *)((ulong)(__ptr + 3) & 0xfffffffffffffff8);
        for (uVar5 = (ulong)((int)lVar4 + uVar8 >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + (ulong)bVar9 * -2 + 1;
          puVar7 = puVar7 + (ulong)bVar9 * -2 + 1;
        }
      }
    }
    local_e8 = *param_1;
    auStack_dc = SUB1612((undefined1  [16])0x0,4);
    local_e0 = 0x2080a097;
    auStack_dc._4_8_ = __ptr;
    local_d0 = 0x490;
    iVar3 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
    *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
    if (iVar3 == 0) {
      *piVar2 = *__ptr;
      piVar2[4] = __ptr[0x81];
      piVar2[8] = __ptr[0x122];
      piVar2[9] = __ptr[0x123];
      if (uVar8 != 0) {
        puVar6 = *(undefined8 **)(piVar2 + 2);
        if (uVar8 < 8) {
          if (uVar8 != 0) {
            *(char *)puVar6 = (char)__ptr[1];
          }
        }
        else {
          *puVar6 = *(undefined8 *)(__ptr + 1);
          *(undefined8 *)((long)puVar6 + ((ulong)uVar8 - 8)) =
               *(undefined8 *)((long)__ptr + ((ulong)uVar8 - 4));
          lVar4 = (long)puVar6 - (long)((ulong)(puVar6 + 1) & 0xfffffffffffffff8);
          puVar7 = (undefined8 *)((long)__ptr + (4 - lVar4));
          puVar6 = (undefined8 *)((ulong)(puVar6 + 1) & 0xfffffffffffffff8);
          for (uVar5 = (ulong)((int)lVar4 + uVar8 >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar6 = *puVar7;
            puVar7 = puVar7 + (ulong)bVar9 * -2 + 1;
            puVar6 = puVar6 + (ulong)bVar9 * -2 + 1;
          }
        }
      }
    }
    free(__ptr);
  }
  FUN_00244140(local_c8,param_1);
  return iVar3;
}


// ===== 002467d0 FUN_002467d0 =====

int FUN_002467d0(undefined8 *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *__ptr;
  long lVar5;
  ulong uVar6;
  uint uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  byte bVar10;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined1 auStack_dc [12];
  undefined8 local_d0;
  undefined8 local_c8 [2];
  undefined4 local_b8;
  undefined4 local_b0;
  undefined8 local_98;
  undefined4 local_90;
  undefined1 local_8c;
  undefined4 local_48;
  
  bVar10 = 0;
  uVar2 = param_1[2];
  puVar8 = local_c8;
  for (lVar5 = 0x11; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  local_8c = 1;
  local_b8 = 0x20;
  local_b0 = 0xffffffff;
  local_98 = 0x1800000010;
  local_90 = 0x10;
  local_48 = 2;
  local_c8[1] = uVar2;
  iVar4 = FUN_00243fd0(uVar2,0x20,local_c8);
  if ((iVar4 == 0) && (iVar4 = FUN_00244050(local_c8,param_1), iVar4 == 0)) {
    puVar3 = (undefined4 *)param_1[2];
    uVar1 = puVar3[4];
    __ptr = malloc(0x214);
    uVar7 = uVar1 * 0x10;
    if (__ptr == (undefined4 *)0x0) {
      FUN_00244140(local_c8,param_1);
      return 0x51;
    }
    if (0x200 < uVar7) {
      free(__ptr);
      FUN_00244140(local_c8,param_1);
      return 0x1a;
    }
    *__ptr = *puVar3;
    *(undefined1 *)(__ptr + 1) = *(undefined1 *)(puVar3 + 1);
    __ptr[2] = puVar3[2];
    __ptr[4] = puVar3[4];
    if ((uVar1 & 0xfffffff) != 0) {
      puVar8 = *(undefined8 **)(puVar3 + 6);
      if (uVar7 < 8) {
        if ((uVar1 & 0xfffffff) != 0) {
          *(undefined1 *)(__ptr + 5) = *(undefined1 *)puVar8;
        }
      }
      else {
        *(undefined8 *)(__ptr + 5) = *puVar8;
        *(undefined8 *)((long)__ptr + (ulong)uVar7 + 0xc) =
             *(undefined8 *)((long)puVar8 + ((ulong)uVar7 - 8));
        lVar5 = (long)__ptr + (0x14 - (long)((ulong)(__ptr + 7) & 0xfffffffffffffff8));
        puVar8 = (undefined8 *)((long)puVar8 - lVar5);
        puVar9 = (undefined8 *)((ulong)(__ptr + 7) & 0xfffffffffffffff8);
        for (uVar6 = (ulong)((int)lVar5 + uVar7 >> 3); uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + (ulong)bVar10 * -2 + 1;
          puVar9 = puVar9 + (ulong)bVar10 * -2 + 1;
        }
      }
    }
    local_e8 = *param_1;
    auStack_dc = SUB1612((undefined1  [16])0x0,4);
    local_e0 = 0x2080a026;
    auStack_dc._4_8_ = __ptr;
    local_d0 = 0x214;
    iVar4 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
    *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
    if (iVar4 == 0) {
      *(undefined1 *)(puVar3 + 1) = *(undefined1 *)(__ptr + 1);
      puVar3[2] = __ptr[2];
      puVar3[3] = __ptr[3];
      if ((uVar1 & 0xfffffff) != 0) {
        puVar8 = *(undefined8 **)(puVar3 + 6);
        if (uVar7 < 8) {
          if ((uVar1 & 0xfffffff) != 0) {
            *(undefined1 *)puVar8 = *(undefined1 *)(__ptr + 5);
          }
        }
        else {
          *puVar8 = *(undefined8 *)(__ptr + 5);
          *(undefined8 *)((long)puVar8 + ((ulong)uVar7 - 8)) =
               *(undefined8 *)((long)__ptr + (ulong)uVar7 + 0xc);
          lVar5 = (long)puVar8 - (long)((ulong)(puVar8 + 1) & 0xfffffffffffffff8);
          puVar9 = (undefined8 *)((long)__ptr + (0x14 - lVar5));
          puVar8 = (undefined8 *)((ulong)(puVar8 + 1) & 0xfffffffffffffff8);
          for (uVar6 = (ulong)((int)lVar5 + uVar7 >> 3); uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar8 = *puVar9;
            puVar9 = puVar9 + (ulong)bVar10 * -2 + 1;
            puVar8 = puVar8 + (ulong)bVar10 * -2 + 1;
          }
        }
      }
    }
    free(__ptr);
  }
  FUN_00244140(local_c8,param_1);
  return iVar4;
}


// ===== 00246aa0 FUN_00246aa0 =====

int FUN_00246aa0(undefined8 *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *__ptr;
  long lVar5;
  ulong uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  uint uVar9;
  uint uVar10;
  byte bVar11;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined1 auStack_dc [12];
  undefined8 local_d0;
  undefined8 local_c8 [2];
  undefined4 local_b8;
  undefined4 local_b0;
  undefined8 local_98;
  undefined4 local_90;
  undefined1 local_8c;
  undefined8 local_78;
  undefined4 local_70;
  undefined1 local_6c;
  undefined8 local_58;
  undefined4 local_50;
  undefined1 local_4c;
  undefined4 local_48;
  
  bVar11 = 0;
  uVar2 = param_1[2];
  puVar7 = local_c8;
  for (lVar5 = 0x11; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  local_8c = 1;
  local_98 = 0x1000000010;
  local_78 = 0x1800000010;
  local_b8 = 0x30;
  local_b0 = 0xffffffff;
  local_90 = 8;
  local_70 = 8;
  local_6c = 1;
  local_58 = 0x2800000024;
  local_50 = 0x20;
  local_4c = 1;
  local_48 = 4;
  local_c8[1] = uVar2;
  iVar4 = FUN_00243fd0(uVar2,0x30,local_c8);
  if ((iVar4 == 0) && (iVar4 = FUN_00244050(local_c8,param_1), iVar4 == 0)) {
    puVar3 = (undefined4 *)param_1[2];
    uVar1 = puVar3[2];
    uVar10 = uVar1 * 0x10;
    uVar9 = puVar3[8] * 0x24;
    __ptr = malloc(0x890);
    if (__ptr == (undefined4 *)0x0) {
      FUN_00244140(local_c8,param_1);
      return 0x51;
    }
    if ((0x480 < uVar9) || (0x200 < uVar10)) {
      free(__ptr);
      FUN_00244140(local_c8,param_1);
      return 0x1a;
    }
    *__ptr = *puVar3;
    __ptr[1] = puVar3[1];
    __ptr[2] = puVar3[2];
    __ptr[0x103] = puVar3[8];
    if ((uVar1 & 0xfffffff) != 0) {
      puVar7 = *(undefined8 **)(puVar3 + 4);
      if (uVar10 < 8) {
        if ((uVar1 & 0xfffffff) != 0) {
          *(undefined1 *)(__ptr + 3) = *(undefined1 *)puVar7;
        }
      }
      else {
        *(undefined8 *)(__ptr + 3) = *puVar7;
        *(undefined8 *)((long)__ptr + (ulong)uVar10 + 4) =
             *(undefined8 *)((long)puVar7 + ((ulong)uVar10 - 8));
        lVar5 = (long)__ptr + (0xc - (long)((ulong)(__ptr + 5) & 0xfffffffffffffff8));
        puVar7 = (undefined8 *)((long)puVar7 - lVar5);
        puVar8 = (undefined8 *)((ulong)(__ptr + 5) & 0xfffffffffffffff8);
        for (uVar6 = (ulong)((int)lVar5 + uVar10 >> 3); uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + (ulong)bVar11 * -2 + 1;
          puVar8 = puVar8 + (ulong)bVar11 * -2 + 1;
        }
      }
      puVar7 = *(undefined8 **)(puVar3 + 6);
      if (uVar10 < 8) {
        if ((uVar1 & 0xfffffff) != 0) {
          *(undefined1 *)(__ptr + 0x83) = *(undefined1 *)puVar7;
        }
      }
      else {
        *(undefined8 *)(__ptr + 0x83) = *puVar7;
        lVar5 = (long)__ptr + (0x20c - (long)((ulong)(__ptr + 0x85) & 0xfffffffffffffff8));
        *(undefined8 *)((long)__ptr + (ulong)uVar10 + 0x204) =
             *(undefined8 *)((long)puVar7 + ((ulong)uVar10 - 8));
        puVar7 = (undefined8 *)((long)puVar7 - lVar5);
        puVar8 = (undefined8 *)((ulong)(__ptr + 0x85) & 0xfffffffffffffff8);
        for (uVar6 = (ulong)((int)lVar5 + uVar10 >> 3); uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + (ulong)bVar11 * -2 + 1;
          puVar8 = puVar8 + (ulong)bVar11 * -2 + 1;
        }
      }
    }
    if (uVar9 != 0) {
      puVar7 = *(undefined8 **)(puVar3 + 10);
      if (uVar9 < 8) {
        if ((uVar9 & 4) == 0) {
          if (uVar9 != 0) {
            *(undefined1 *)(__ptr + 0x104) = *(undefined1 *)puVar7;
          }
        }
        else {
          __ptr[0x104] = *(undefined4 *)puVar7;
          *(undefined4 *)((long)__ptr + (ulong)uVar9 + 0x40c) =
               *(undefined4 *)((long)puVar7 + ((ulong)uVar9 - 4));
        }
      }
      else {
        *(undefined8 *)((long)__ptr + (ulong)uVar9 + 0x408) =
             *(undefined8 *)((long)puVar7 + ((ulong)uVar9 - 8));
        puVar8 = (undefined8 *)(__ptr + 0x104);
        for (uVar6 = (ulong)(uVar9 - 1 >> 3); uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + (ulong)bVar11 * -2 + 1;
          puVar8 = puVar8 + (ulong)bVar11 * -2 + 1;
        }
      }
    }
    local_e8 = *param_1;
    auStack_dc = SUB1612((undefined1  [16])0x0,4);
    local_e0 = 0x2080a028;
    auStack_dc._4_8_ = __ptr;
    local_d0 = 0x890;
    iVar4 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
    *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
    if (iVar4 == 0) {
      *puVar3 = *__ptr;
      puVar3[1] = __ptr[1];
      puVar3[2] = __ptr[2];
      puVar3[8] = __ptr[0x103];
      if ((uVar1 & 0xfffffff) != 0) {
        puVar7 = *(undefined8 **)(puVar3 + 4);
        if (uVar10 < 8) {
          if ((uVar1 & 0xfffffff) != 0) {
            *(undefined1 *)puVar7 = *(undefined1 *)(__ptr + 3);
          }
        }
        else {
          *puVar7 = *(undefined8 *)(__ptr + 3);
          *(undefined8 *)((long)puVar7 + ((ulong)uVar10 - 8)) =
               *(undefined8 *)((long)__ptr + (ulong)uVar10 + 4);
          lVar5 = (long)puVar7 - (long)((ulong)(puVar7 + 1) & 0xfffffffffffffff8);
          puVar8 = (undefined8 *)((long)__ptr + (0xc - lVar5));
          puVar7 = (undefined8 *)((ulong)(puVar7 + 1) & 0xfffffffffffffff8);
          for (uVar6 = (ulong)((int)lVar5 + uVar10 >> 3); uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar7 = *puVar8;
            puVar8 = puVar8 + (ulong)bVar11 * -2 + 1;
            puVar7 = puVar7 + (ulong)bVar11 * -2 + 1;
          }
        }
        puVar7 = *(undefined8 **)(puVar3 + 6);
        if (uVar10 < 8) {
          if ((uVar1 & 0xfffffff) != 0) {
            *(undefined1 *)puVar7 = *(undefined1 *)(__ptr + 0x83);
          }
        }
        else {
          *puVar7 = *(undefined8 *)(__ptr + 0x83);
          *(undefined8 *)((long)puVar7 + ((ulong)uVar10 - 8)) =
               *(undefined8 *)((long)__ptr + (ulong)uVar10 + 0x204);
          lVar5 = (long)puVar7 - (long)((ulong)(puVar7 + 1) & 0xfffffffffffffff8);
          puVar8 = (undefined8 *)((long)__ptr + (0x20c - lVar5));
          puVar7 = (undefined8 *)((ulong)(puVar7 + 1) & 0xfffffffffffffff8);
          for (uVar6 = (ulong)((int)lVar5 + uVar10 >> 3); uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar7 = *puVar8;
            puVar8 = puVar8 + (ulong)bVar11 * -2 + 1;
            puVar7 = puVar7 + (ulong)bVar11 * -2 + 1;
          }
        }
      }
      if (uVar9 != 0) {
        puVar7 = *(undefined8 **)(puVar3 + 10);
        if (uVar9 < 8) {
          if ((uVar9 & 4) == 0) {
            if (uVar9 != 0) {
              *(undefined1 *)puVar7 = *(undefined1 *)(__ptr + 0x104);
            }
          }
          else {
            *(undefined4 *)puVar7 = __ptr[0x104];
            *(undefined4 *)((long)puVar7 + ((ulong)uVar9 - 4)) =
                 *(undefined4 *)((long)__ptr + (ulong)uVar9 + 0x40c);
          }
        }
        else {
          *puVar7 = *(undefined8 *)(__ptr + 0x104);
          *(undefined8 *)((long)puVar7 + ((ulong)uVar9 - 8)) =
               *(undefined8 *)((long)__ptr + (ulong)uVar9 + 0x408);
          lVar5 = (long)puVar7 - (long)((ulong)(puVar7 + 1) & 0xfffffffffffffff8);
          puVar8 = (undefined8 *)((long)(__ptr + 0x104) - lVar5);
          puVar7 = (undefined8 *)((ulong)(puVar7 + 1) & 0xfffffffffffffff8);
          for (uVar6 = (ulong)((int)lVar5 + uVar9 >> 3); uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar7 = *puVar8;
            puVar8 = puVar8 + (ulong)bVar11 * -2 + 1;
            puVar7 = puVar7 + (ulong)bVar11 * -2 + 1;
          }
        }
      }
    }
    free(__ptr);
  }
  FUN_00244140(local_c8,param_1);
  return iVar4;
}


// ===== 00246fd0 FUN_00246fd0 =====

int FUN_00246fd0(undefined8 *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 *__ptr;
  long lVar6;
  ulong uVar7;
  uint uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  uint uVar11;
  byte bVar12;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined1 auStack_dc [12];
  undefined8 local_d0;
  undefined8 local_c8 [2];
  undefined4 local_b8;
  undefined4 local_b0;
  undefined8 local_98;
  undefined4 local_90;
  undefined1 local_8c;
  undefined8 local_78;
  undefined4 local_70;
  undefined1 local_6c;
  undefined4 local_48;
  
  bVar12 = 0;
  uVar2 = param_1[2];
  puVar9 = local_c8;
  for (lVar6 = 0x11; lVar6 != 0; lVar6 = lVar6 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  local_8c = 1;
  local_98 = 0x1000000010;
  local_b8 = 0x28;
  local_b0 = 0xffffffff;
  local_90 = 8;
  local_78 = 0x2000000024;
  local_70 = 0x18;
  local_6c = 1;
  local_48 = 3;
  local_c8[1] = uVar2;
  iVar5 = FUN_00243fd0(uVar2,0x28,local_c8);
  if ((iVar5 == 0) && (iVar5 = FUN_00244050(local_c8,param_1), iVar5 == 0)) {
    puVar3 = (undefined4 *)param_1[2];
    iVar5 = puVar3[6];
    uVar1 = puVar3[2];
    uVar4 = iVar5 * 9;
    uVar8 = uVar1 * 0x10;
    __ptr = malloc(0x690);
    uVar11 = iVar5 * 0x24;
    if (__ptr == (undefined4 *)0x0) {
      FUN_00244140(local_c8,param_1);
      return 0x51;
    }
    if ((0x200 < uVar8) || (0x480 < uVar11)) {
      free(__ptr);
      FUN_00244140(local_c8,param_1);
      return 0x1a;
    }
    *__ptr = *puVar3;
    __ptr[1] = puVar3[1];
    __ptr[2] = puVar3[2];
    __ptr[0x83] = puVar3[6];
    local_e8 = *param_1;
    auStack_dc = SUB1612((undefined1  [16])0x0,4);
    local_e0 = 0x2080a027;
    auStack_dc._4_8_ = __ptr;
    local_d0 = 0x690;
    if ((uVar1 & 0xfffffff) != 0) {
      puVar9 = *(undefined8 **)(puVar3 + 4);
      if (uVar8 < 8) {
        if ((uVar1 & 0xfffffff) != 0) {
          *(undefined1 *)(__ptr + 3) = *(undefined1 *)puVar9;
        }
      }
      else {
        *(undefined8 *)(__ptr + 3) = *puVar9;
        *(undefined8 *)((long)__ptr + (ulong)uVar8 + 4) =
             *(undefined8 *)((long)puVar9 + ((ulong)uVar8 - 8));
        lVar6 = (long)__ptr + (0xc - (long)((ulong)(__ptr + 5) & 0xfffffffffffffff8));
        puVar9 = (undefined8 *)((long)puVar9 - lVar6);
        puVar10 = (undefined8 *)((ulong)(__ptr + 5) & 0xfffffffffffffff8);
        for (uVar7 = (ulong)((int)lVar6 + uVar8 >> 3); uVar7 != 0; uVar7 = uVar7 - 1) {
          *puVar10 = *puVar9;
          puVar9 = puVar9 + (ulong)bVar12 * -2 + 1;
          puVar10 = puVar10 + (ulong)bVar12 * -2 + 1;
        }
      }
    }
    if ((uVar4 & 0x3fffffff) != 0) {
      puVar9 = *(undefined8 **)(puVar3 + 8);
      if (uVar11 < 8) {
        if ((uVar11 & 4) == 0) {
          if ((uVar4 & 0x3fffffff) != 0) {
            *(undefined1 *)(__ptr + 0x84) = *(undefined1 *)puVar9;
          }
        }
        else {
          __ptr[0x84] = *(undefined4 *)puVar9;
          *(undefined4 *)((long)__ptr + (ulong)uVar11 + 0x20c) =
               *(undefined4 *)((long)puVar9 + ((ulong)uVar11 - 4));
        }
      }
      else {
        *(undefined8 *)((long)__ptr + (ulong)uVar11 + 0x208) =
             *(undefined8 *)((long)puVar9 + ((ulong)uVar11 - 8));
        puVar10 = (undefined8 *)(__ptr + 0x84);
        for (uVar7 = (ulong)(uVar11 - 1 >> 3); uVar7 != 0; uVar7 = uVar7 - 1) {
          *puVar10 = *puVar9;
          puVar9 = puVar9 + (ulong)bVar12 * -2 + 1;
          puVar10 = puVar10 + (ulong)bVar12 * -2 + 1;
        }
      }
    }
    iVar5 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
    *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
    free(__ptr);
  }
  FUN_00244140(local_c8,param_1);
  return iVar5;
}


// ===== 002472c0 FUN_002472c0 =====

int FUN_002472c0(undefined8 *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  uint *puVar3;
  undefined1 auVar4 [16];
  int iVar5;
  uint uVar6;
  uint *__ptr;
  long lVar7;
  ulong uVar8;
  uint uVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  byte bVar12;
  undefined8 local_e8;
  undefined1 local_e0 [16];
  undefined8 local_d0;
  undefined8 local_c8 [2];
  undefined4 local_b8;
  undefined4 local_b0;
  undefined8 local_98;
  undefined1 local_8c;
  undefined8 local_78;
  undefined4 local_70;
  undefined1 local_6c;
  undefined4 local_48;
  
  bVar12 = 0;
  uVar2 = param_1[2];
  puVar10 = local_c8;
  for (lVar7 = 0x11; lVar7 != 0; lVar7 = lVar7 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  local_8c = 1;
  local_98 = 0x800000010;
  local_b8 = 0x20;
  local_b0 = 0xffffffff;
  local_78 = 0x1800000034;
  local_70 = 0x10;
  local_6c = 1;
  local_48 = 3;
  local_c8[1] = uVar2;
  iVar5 = FUN_00243fd0(uVar2,0x20,local_c8);
  if ((iVar5 == 0) && (iVar5 = FUN_00244050(local_c8,param_1), iVar5 == 0)) {
    puVar3 = (uint *)param_1[2];
    uVar6 = puVar3[4] * 0x34;
    uVar1 = *puVar3;
    uVar9 = uVar1 * 0x10;
    __ptr = malloc(0x43c4);
    if (__ptr == (uint *)0x0) {
      FUN_00244140(local_c8,param_1);
      return 0x51;
    }
    if ((0xff0 < uVar9) || (0x33cc < uVar6)) {
      free(__ptr);
      FUN_00244140(local_c8,param_1);
      return 0x1a;
    }
    *__ptr = uVar1;
    __ptr[0x3fd] = puVar3[4];
    if ((uVar1 & 0xfffffff) != 0) {
      puVar10 = *(undefined8 **)(puVar3 + 2);
      if (uVar9 < 8) {
        if ((uVar1 & 0xfffffff) != 0) {
          *(undefined1 *)(__ptr + 1) = *(undefined1 *)puVar10;
        }
      }
      else {
        *(undefined8 *)(__ptr + 1) = *puVar10;
        *(undefined8 *)((long)__ptr + ((ulong)uVar9 - 4)) =
             *(undefined8 *)((long)puVar10 + ((ulong)uVar9 - 8));
        lVar7 = (long)__ptr + (4 - (long)((ulong)(__ptr + 3) & 0xfffffffffffffff8));
        puVar10 = (undefined8 *)((long)puVar10 - lVar7);
        puVar11 = (undefined8 *)((ulong)(__ptr + 3) & 0xfffffffffffffff8);
        for (uVar8 = (ulong)((int)lVar7 + uVar9 >> 3); uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar11 = *puVar10;
          puVar10 = puVar10 + (ulong)bVar12 * -2 + 1;
          puVar11 = puVar11 + (ulong)bVar12 * -2 + 1;
        }
      }
    }
    if (uVar6 != 0) {
      memcpy(__ptr + 0x3fe,*(void **)(puVar3 + 6),(ulong)uVar6);
    }
    local_e8 = *param_1;
    auVar4._8_8_ = 0;
    auVar4._0_8_ = __ptr;
    local_e0 = auVar4 << 0x40;
    local_e0._0_4_ = 0x2080a0bf;
    local_d0 = 0x43c4;
    iVar5 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
    *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
    if (iVar5 == 0) {
      *puVar3 = *__ptr;
      puVar3[4] = __ptr[0x3fd];
      if ((uVar1 & 0xfffffff) != 0) {
        puVar10 = *(undefined8 **)(puVar3 + 2);
        if (uVar9 < 8) {
          if ((uVar1 & 0xfffffff) != 0) {
            *(char *)puVar10 = (char)__ptr[1];
          }
        }
        else {
          *puVar10 = *(undefined8 *)(__ptr + 1);
          *(undefined8 *)((long)puVar10 + ((ulong)uVar9 - 8)) =
               *(undefined8 *)((long)__ptr + ((ulong)uVar9 - 4));
          lVar7 = (long)puVar10 - (long)((ulong)(puVar10 + 1) & 0xfffffffffffffff8);
          puVar11 = (undefined8 *)((long)__ptr + (4 - lVar7));
          puVar10 = (undefined8 *)((ulong)(puVar10 + 1) & 0xfffffffffffffff8);
          for (uVar8 = (ulong)((int)lVar7 + uVar9 >> 3); uVar8 != 0; uVar8 = uVar8 - 1) {
            *puVar10 = *puVar11;
            puVar11 = puVar11 + (ulong)bVar12 * -2 + 1;
            puVar10 = puVar10 + (ulong)bVar12 * -2 + 1;
          }
        }
      }
      if (uVar6 != 0) {
        memcpy(*(void **)(puVar3 + 6),__ptr + 0x3fe,(ulong)uVar6);
      }
    }
    free(__ptr);
  }
  FUN_00244140(local_c8,param_1);
  return iVar5;
}


// ===== 00247600 FUN_00247600 =====

int FUN_00247600(undefined8 *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  uint *puVar3;
  undefined1 auVar4 [16];
  int iVar5;
  uint uVar6;
  uint *__ptr;
  long lVar7;
  ulong uVar8;
  uint uVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  byte bVar12;
  undefined8 local_e8;
  undefined1 local_e0 [16];
  undefined8 local_d0;
  undefined8 local_c8 [2];
  undefined4 local_b8;
  undefined4 local_b0;
  undefined8 local_98;
  undefined1 local_8c;
  undefined8 local_78;
  undefined4 local_70;
  undefined1 local_6c;
  undefined4 local_48;
  
  bVar12 = 0;
  uVar2 = param_1[2];
  puVar10 = local_c8;
  for (lVar7 = 0x11; lVar7 != 0; lVar7 = lVar7 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  local_8c = 1;
  local_98 = 0x800000010;
  local_b8 = 0x20;
  local_b0 = 0xffffffff;
  local_78 = 0x1800000034;
  local_70 = 0x10;
  local_6c = 1;
  local_48 = 3;
  local_c8[1] = uVar2;
  iVar5 = FUN_00243fd0(uVar2,0x20,local_c8);
  if ((iVar5 == 0) && (iVar5 = FUN_00244050(local_c8,param_1), iVar5 == 0)) {
    puVar3 = (uint *)param_1[2];
    uVar6 = puVar3[4] * 0x34;
    uVar1 = *puVar3;
    uVar9 = uVar1 * 0x10;
    __ptr = calloc(0x43c4,1);
    if (__ptr == (uint *)0x0) {
      FUN_00244140(local_c8,param_1);
      return 0x51;
    }
    if ((0xff0 < uVar9) || (0x33cc < uVar6)) {
      free(__ptr);
      FUN_00244140(local_c8,param_1);
      return 0x1a;
    }
    *__ptr = *puVar3;
    __ptr[0x3fd] = puVar3[4];
    if ((uVar1 & 0xfffffff) != 0) {
      puVar10 = *(undefined8 **)(puVar3 + 2);
      if (uVar9 < 8) {
        if ((uVar1 & 0xfffffff) != 0) {
          *(undefined1 *)(__ptr + 1) = *(undefined1 *)puVar10;
        }
      }
      else {
        *(undefined8 *)(__ptr + 1) = *puVar10;
        *(undefined8 *)((long)__ptr + ((ulong)uVar9 - 4)) =
             *(undefined8 *)((long)puVar10 + ((ulong)uVar9 - 8));
        lVar7 = (long)__ptr + (4 - (long)((ulong)(__ptr + 3) & 0xfffffffffffffff8));
        puVar10 = (undefined8 *)((long)puVar10 - lVar7);
        puVar11 = (undefined8 *)((ulong)(__ptr + 3) & 0xfffffffffffffff8);
        for (uVar8 = (ulong)((int)lVar7 + uVar9 >> 3); uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar11 = *puVar10;
          puVar10 = puVar10 + (ulong)bVar12 * -2 + 1;
          puVar11 = puVar11 + (ulong)bVar12 * -2 + 1;
        }
      }
    }
    if (uVar6 != 0) {
      memcpy(__ptr + 0x3fe,*(void **)(puVar3 + 6),(ulong)uVar6);
    }
    local_e8 = *param_1;
    auVar4._8_8_ = 0;
    auVar4._0_8_ = __ptr;
    local_e0 = auVar4 << 0x40;
    local_e0._0_4_ = 0x2080a0be;
    local_d0 = 0x43c4;
    iVar5 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
    *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
    if (iVar5 == 0) {
      *puVar3 = *__ptr;
      puVar3[4] = __ptr[0x3fd];
      if ((uVar1 & 0xfffffff) != 0) {
        puVar10 = *(undefined8 **)(puVar3 + 2);
        if (uVar9 < 8) {
          if ((uVar1 & 0xfffffff) != 0) {
            *(char *)puVar10 = (char)__ptr[1];
          }
        }
        else {
          *puVar10 = *(undefined8 *)(__ptr + 1);
          *(undefined8 *)((long)puVar10 + ((ulong)uVar9 - 8)) =
               *(undefined8 *)((long)__ptr + ((ulong)uVar9 - 4));
          lVar7 = (long)puVar10 - (long)((ulong)(puVar10 + 1) & 0xfffffffffffffff8);
          puVar11 = (undefined8 *)((long)__ptr + (4 - lVar7));
          puVar10 = (undefined8 *)((ulong)(puVar10 + 1) & 0xfffffffffffffff8);
          for (uVar8 = (ulong)((int)lVar7 + uVar9 >> 3); uVar8 != 0; uVar8 = uVar8 - 1) {
            *puVar10 = *puVar11;
            puVar11 = puVar11 + (ulong)bVar12 * -2 + 1;
            puVar10 = puVar10 + (ulong)bVar12 * -2 + 1;
          }
        }
      }
      if (uVar6 != 0) {
        memcpy(*(void **)(puVar3 + 6),__ptr + 0x3fe,(ulong)uVar6);
      }
    }
    free(__ptr);
  }
  FUN_00244140(local_c8,param_1);
  return iVar5;
}


// ===== 00247940 FUN_00247940 =====

int FUN_00247940(undefined8 *param_1)

{
  undefined8 uVar1;
  int *piVar2;
  int iVar3;
  int *__ptr;
  long lVar4;
  ulong uVar5;
  int *piVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  byte bVar12;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined1 auStack_dc [12];
  undefined8 local_d0;
  undefined8 local_c8 [2];
  undefined4 local_b8;
  undefined4 local_b0;
  undefined8 local_98;
  undefined1 local_8c;
  undefined8 local_78;
  undefined4 local_70;
  undefined1 local_6c;
  undefined4 local_48;
  
  bVar12 = 0;
  uVar1 = param_1[2];
  puVar8 = local_c8;
  for (lVar4 = 0x11; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  local_8c = 1;
  local_98 = 0x800000010;
  local_b8 = 0x28;
  local_b0 = 0xffffffff;
  local_78 = 0x1800000014;
  local_70 = 0x10;
  local_6c = 1;
  local_48 = 3;
  local_c8[1] = uVar1;
  iVar3 = FUN_00243fd0(uVar1,0x28,local_c8);
  if ((iVar3 == 0) && (iVar3 = FUN_00244050(local_c8,param_1), iVar3 == 0)) {
    piVar2 = (int *)param_1[2];
    iVar3 = *piVar2;
    uVar11 = iVar3 * 0x10;
    uVar10 = piVar2[4] * 0x14;
    __ptr = malloc(0x490);
    if (__ptr == (int *)0x0) {
      FUN_00244140(local_c8,param_1);
      return 0x51;
    }
    if ((0x200 < uVar11) || (0x280 < uVar10)) {
      free(__ptr);
      FUN_00244140(local_c8,param_1);
      return 0x1a;
    }
    *__ptr = iVar3;
    __ptr[0x81] = piVar2[4];
    __ptr[0x122] = piVar2[8];
    __ptr[0x123] = piVar2[9];
    if (uVar11 != 0) {
      puVar8 = *(undefined8 **)(piVar2 + 2);
      if (uVar11 < 8) {
        if (uVar11 != 0) {
          *(undefined1 *)(__ptr + 1) = *(undefined1 *)puVar8;
        }
      }
      else {
        *(undefined8 *)(__ptr + 1) = *puVar8;
        *(undefined8 *)((long)__ptr + ((ulong)uVar11 - 4)) =
             *(undefined8 *)((long)puVar8 + ((ulong)uVar11 - 8));
        lVar4 = (long)__ptr + (4 - (long)((ulong)(__ptr + 3) & 0xfffffffffffffff8));
        puVar8 = (undefined8 *)((long)puVar8 - lVar4);
        puVar7 = (undefined8 *)((ulong)(__ptr + 3) & 0xfffffffffffffff8);
        for (uVar5 = (ulong)((int)lVar4 + uVar11 >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar7 = *puVar8;
          puVar8 = puVar8 + (ulong)bVar12 * -2 + 1;
          puVar7 = puVar7 + (ulong)bVar12 * -2 + 1;
        }
      }
    }
    if (uVar10 != 0) {
      piVar6 = *(int **)(piVar2 + 6);
      if (uVar10 < 8) {
        if ((uVar10 & 4) == 0) {
          if (uVar10 != 0) {
            *(char *)(__ptr + 0x82) = (char)*piVar6;
          }
        }
        else {
          __ptr[0x82] = *piVar6;
          *(undefined4 *)((long)__ptr + (ulong)uVar10 + 0x204) =
               *(undefined4 *)((long)piVar6 + ((ulong)uVar10 - 4));
        }
      }
      else {
        *(undefined8 *)((long)__ptr + (ulong)uVar10 + 0x200) =
             *(undefined8 *)((long)piVar6 + ((ulong)uVar10 - 8));
        piVar9 = __ptr + 0x82;
        for (uVar5 = (ulong)(uVar10 - 1 >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined8 *)piVar9 = *(undefined8 *)piVar6;
          piVar6 = piVar6 + (ulong)bVar12 * -4 + 2;
          piVar9 = piVar9 + (ulong)bVar12 * -4 + 2;
        }
      }
    }
    local_e8 = *param_1;
    auStack_dc = SUB1612((undefined1  [16])0x0,4);
    local_e0 = 0x2080a097;
    auStack_dc._4_8_ = __ptr;
    local_d0 = 0x490;
    iVar3 = FUN_0023d7d0(DAT_00380490,0x2a,0x20,0xc020462a,&local_e8,(long)&local_d0 + 4);
    *(undefined4 *)((long)param_1 + 0x1c) = local_d0._4_4_;
    if (iVar3 == 0) {
      *piVar2 = *__ptr;
      piVar2[4] = __ptr[0x81];
      piVar2[8] = __ptr[0x122];
      piVar2[9] = __ptr[0x123];
      if (uVar11 != 0) {
        puVar8 = *(undefined8 **)(piVar2 + 2);
        if (uVar11 < 8) {
          if (uVar11 != 0) {
            *(char *)puVar8 = (char)__ptr[1];
          }
        }
        else {
          *puVar8 = *(undefined8 *)(__ptr + 1);
          *(undefined8 *)((long)puVar8 + ((ulong)uVar11 - 8)) =
               *(undefined8 *)((long)__ptr + ((ulong)uVar11 - 4));
          lVar4 = (long)puVar8 - (long)((ulong)(puVar8 + 1) & 0xfffffffffffffff8);
          puVar7 = (undefined8 *)((long)__ptr + (4 - lVar4));
          puVar8 = (undefined8 *)((ulong)(puVar8 + 1) & 0xfffffffffffffff8);
          for (uVar5 = (ulong)((int)lVar4 + uVar11 >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + (ulong)bVar12 * -2 + 1;
            puVar8 = puVar8 + (ulong)bVar12 * -2 + 1;
          }
        }
      }
      if (uVar10 != 0) {
        piVar2 = *(int **)(piVar2 + 6);
        if (uVar10 < 8) {
          if ((uVar10 & 4) == 0) {
            if (uVar10 != 0) {
              *(char *)piVar2 = (char)__ptr[0x82];
            }
          }
          else {
            *piVar2 = __ptr[0x82];
            *(undefined4 *)((long)piVar2 + ((ulong)uVar10 - 4)) =
                 *(undefined4 *)((long)__ptr + (ulong)uVar10 + 0x204);
          }
        }
        else {
          *(undefined8 *)piVar2 = *(undefined8 *)(__ptr + 0x82);
          *(undefined8 *)((long)piVar2 + ((ulong)uVar10 - 8)) =
               *(undefined8 *)((long)__ptr + (ulong)uVar10 + 0x200);
          lVar4 = (long)piVar2 - (long)((ulong)(piVar2 + 2) & 0xfffffffffffffff8);
          puVar8 = (undefined8 *)((long)(__ptr + 0x82) - lVar4);
          puVar7 = (undefined8 *)((ulong)(piVar2 + 2) & 0xfffffffffffffff8);
          for (uVar5 = (ulong)((int)lVar4 + uVar10 >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar7 = *puVar8;
            puVar8 = puVar8 + (ulong)bVar12 * -2 + 1;
            puVar7 = puVar7 + (ulong)bVar12 * -2 + 1;
          }
        }
      }
    }
    free(__ptr);
  }
  FUN_00244140(local_c8,param_1);
  return iVar3;
}


// ===== 00247da0 FUN_00247da0 =====

undefined4 FUN_00247da0(long param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  ulong uVar3;
  int *piVar4;
  
  piVar4 = &DAT_00324a10;
  uVar3 = 0;
  iVar1 = 0x20809002;
  do {
    if (*(int *)(param_1 + 8) == iVar1) {
      uVar2 = (*(code *)(&PTR_FUN_00324a08)[uVar3 * 2])();
      *param_2 = uVar2;
      return 1;
    }
    iVar1 = *piVar4;
    piVar4 = piVar4 + 4;
    uVar3 = (ulong)((int)uVar3 + 1);
  } while (iVar1 != 0);
  return 0;
}


// ===== 00247df0 FUN_00247df0 =====

undefined8 FUN_00247df0(uint *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  ulong uVar4;
  long lVar5;
  undefined8 *puVar6;
  uint uVar7;
  undefined8 uVar8;
  byte bVar9;
  undefined8 local_b8;
  undefined1 local_b0 [120];
  char local_38;
  
  bVar9 = 0;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[0x13f] = 0;
  param_1[0x140] = 0;
  puVar6 = (undefined8 *)((ulong)(param_1 + 2) & 0xfffffffffffffff8);
  for (uVar4 = (ulong)(((int)param_1 -
                       (int)(undefined8 *)((ulong)(param_1 + 2) & 0xfffffffffffffff8)) + 0x504U >> 3
                      ); uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  pthread_mutex_lock((pthread_mutex_t *)&DAT_01217e40);
  if (DAT_01217e24 == '\0') {
    iVar1 = FUN_00242170(0xff);
    if (iVar1 == 1) {
LAB_00247ed0:
      iVar1 = open("/dev/nvidia-nvswitchctl",0x80002,0);
      if (iVar1 < 0) goto code_r0x00247eec;
      puVar6 = (undefined8 *)local_b0;
      for (lVar5 = 0xf; lVar5 != 0; lVar5 = lVar5 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + (ulong)bVar9 * -2 + 1;
      }
      local_b0[0] = 0x35;
      local_b8 = 0x302e31372e353935;
      *(undefined1 *)puVar6 = 0;
      iVar2 = ioctl(iVar1,0xc0816302,&local_b8);
      if ((iVar2 != 0) || (local_38 == '\0')) {
        uVar8 = 0x6a;
        close(iVar1);
        goto LAB_00247e8b;
      }
      DAT_01217e24 = '\x01';
      close(iVar1);
      goto LAB_00247e50;
    }
  }
  else {
LAB_00247e50:
    do {
      iVar1 = open("/dev/nvidia-nvswitchctl",0x80002,0);
      if (-1 < iVar1) {
        iVar2 = ioctl(iVar1,0x85046301,param_1);
        uVar8 = 0xffff;
        if (iVar2 != 0) goto LAB_00247f2b;
        uVar4 = 0;
        if (*param_1 == 0) goto LAB_00248015;
        goto LAB_00247f5d;
      }
      piVar3 = __errno_location();
      iVar1 = *piVar3;
    } while ((iVar1 == 4) || (iVar1 == 0xb));
    if (iVar1 < 1) {
      *piVar3 = 1;
    }
  }
  uVar8 = 0x4b;
  goto LAB_00247e8b;
code_r0x00247eec:
  piVar3 = __errno_location();
  iVar1 = *piVar3;
  if ((iVar1 == 4) || (iVar1 == 0xb)) goto LAB_00247ed0;
  if (iVar1 < 1) {
    *piVar3 = 1;
  }
  uVar8 = 0x59;
  goto LAB_00247e8b;
  while (uVar7 = (int)uVar4 + 1, uVar4 = (ulong)uVar7, uVar7 < *param_1) {
LAB_00247f5d:
    iVar2 = FUN_00242170(param_1[uVar4 * 5 + 1]);
    if (iVar2 != 1) {
      uVar8 = 0x4b;
      goto LAB_00247f2b;
    }
  }
LAB_00248015:
  uVar8 = 0;
LAB_00247f2b:
  close(iVar1);
LAB_00247e8b:
  pthread_mutex_unlock((pthread_mutex_t *)&DAT_01217e40);
  return uVar8;
}


// ===== 00248030 FUN_00248030 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00248030(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined *puVar2;
  
  _DAT_01217e78 = 0;
  iVar1 = (*(code *)**(undefined8 **)(param_2 + 8))
                    (param_2,1,FUN_00248250,param_1,FUN_002481b0,&DAT_01217e78,DAT_002dd540,
                     DAT_002dd548);
  puVar2 = &DAT_01217e78;
  if (iVar1 != 0) {
    puVar2 = (undefined *)0x0;
  }
  return puVar2;
}


// ===== 00248090 FUN_00248090 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00248090(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined *puVar2;
  
  _DAT_01217e70 = 0;
  iVar1 = (*(code *)**(undefined8 **)(param_2 + 8))
                    (param_2,2,FUN_00248280,param_1,FUN_002482a0,&DAT_01217e70,DAT_002dd540,
                     DAT_002dd548);
  puVar2 = &DAT_01217e70;
  if (iVar1 != 0) {
    puVar2 = (undefined *)0x0;
  }
  return puVar2;
}


// ===== 002480f0 FUN_002480f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_002480f0(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined *puVar2;
  
  _DAT_01217e6c = 0;
  iVar1 = (*(code *)**(undefined8 **)(param_2 + 8))
                    (param_2,1,FUN_00248250,param_1,FUN_002481b0,&DAT_01217e6c,DAT_002dd540,
                     DAT_002dd548);
  puVar2 = &DAT_01217e6c;
  if (iVar1 != 0) {
    puVar2 = (undefined *)0x0;
  }
  return puVar2;
}


// ===== 00248150 FUN_00248150 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00248150(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined *puVar2;
  
  _DAT_01217e68 = 0;
  iVar1 = (*(code *)**(undefined8 **)(param_2 + 8))
                    (param_2,2,FUN_00248310,param_1,FUN_002481b0,&DAT_01217e68,DAT_002dd540,
                     DAT_002dd548);
  puVar2 = &DAT_01217e68;
  if (iVar1 != 0) {
    puVar2 = (undefined *)0x0;
  }
  return puVar2;
}


// ===== 002481b0 FUN_002481b0 =====

bool FUN_002481b0(void)

{
  int iVar1;
  
  iVar1 = FUN_002961d1();
  return iVar1 != 0;
}


// ===== 002481d0 FUN_002481d0 =====

bool FUN_002481d0(undefined8 param_1,long param_2)

{
  int iVar1;
  
  iVar1 = FUN_00296009();
  if (iVar1 != 0) {
    iVar1 = FUN_00296009(param_1,param_2 + 4);
    if (iVar1 != 0) {
      iVar1 = FUN_00296009(param_1,param_2 + 8);
      if (iVar1 != 0) {
        iVar1 = FUN_00296009(param_1,param_2 + 0xc);
        return iVar1 != 0;
      }
    }
  }
  return false;
}


// ===== 00248230 FUN_00248230 =====

bool FUN_00248230(void)

{
  int iVar1;
  
  iVar1 = FUN_002961d1();
  return iVar1 != 0;
}


// ===== 00248250 FUN_00248250 =====

ulong FUN_00248250(undefined8 param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = FUN_002481d0();
  if ((int)uVar2 != 0) {
    iVar1 = FUN_00248230(param_1,param_2 + 0x10);
    uVar2 = (ulong)(iVar1 != 0);
  }
  return uVar2;
}


// ===== 00248280 FUN_00248280 =====

bool FUN_00248280(void)

{
  int iVar1;
  
  iVar1 = FUN_002481d0();
  return iVar1 != 0;
}


// ===== 002482a0 FUN_002482a0 =====

ulong FUN_002482a0(undefined8 param_1,int *param_2)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = FUN_002481b0();
  if ((int)uVar2 != 0) {
    uVar2 = 1;
    if (*param_2 == 0) {
      iVar1 = FUN_00248230(param_1,param_2 + 1);
      return (ulong)(iVar1 != 0);
    }
  }
  return uVar2;
}


// ===== 002482f0 FUN_002482f0 =====

bool FUN_002482f0(void)

{
  int iVar1;
  
  iVar1 = FUN_002961d1();
  return iVar1 != 0;
}


// ===== 00248310 FUN_00248310 =====

ulong FUN_00248310(undefined8 param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = FUN_002481d0();
  if ((int)uVar2 != 0) {
    iVar1 = FUN_002482f0(param_1,param_2 + 0x10);
    uVar2 = (ulong)(iVar1 != 0);
  }
  return uVar2;
}


