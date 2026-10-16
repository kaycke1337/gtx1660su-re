// ===== 00135a50 FUN_00135a50 =====

ulong FUN_00135a50(int param_1,long param_2,undefined4 param_3,undefined8 param_4,undefined8 param_5
                  )

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  ulong extraout_RDX;
  ulong extraout_RDX_00;
  ulong extraout_RDX_01;
  ulong extraout_RDX_02;
  ulong uVar5;
  undefined8 uVar6;
  ulong uVar7;
  float fVar8;
  undefined8 uVar9;
  uint local_40;
  uint local_3c [3];
  
  do {
    iVar2 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar2 != 0);
  uVar5 = extraout_RDX;
  if (param_1 != 1) {
LAB_00135a99:
    lVar4 = *(long *)(param_2 + 0x256d8);
    if (((lVar4 != 0) && (*(long *)(lVar4 + 0x30) != 0)) &&
       (pcVar1 = *(code **)(*(long *)(lVar4 + 0x30) + 0x28), pcVar1 != (code *)0x0)) {
      uVar3 = (*pcVar1)(lVar4,param_2,param_3,param_4,param_5);
      uVar5 = extraout_RDX_00;
      uVar7 = (ulong)uVar3;
      goto LAB_00135ad6;
    }
LAB_00135b90:
    uVar7 = 3;
    goto LAB_00135ad6;
  }
  lVar4 = *(long *)(param_2 + 0x256d8);
  if (((lVar4 == 0) || (*(long *)(lVar4 + 0x30) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(lVar4 + 0x30) + 0x20), pcVar1 == (code *)0x0)) {
    uVar7 = 3;
LAB_00135ba6:
    if (DAT_01216a78 < 2) goto LAB_00135ad6;
    fVar8 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    fVar8 = fVar8 * DAT_00298548;
    uVar9 = 0x408;
    uVar6 = 0x408;
    uVar5 = uVar7;
  }
  else {
    uVar3 = (*pcVar1)(lVar4,param_2,param_3,0,local_3c);
    uVar7 = (ulong)uVar3;
    uVar5 = extraout_RDX_01;
    if (uVar3 != 0) goto LAB_00135ba6;
    lVar4 = *(long *)(param_2 + 0x256d8);
    if (((lVar4 == 0) || (*(long *)(lVar4 + 0x30) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(lVar4 + 0x30) + 0x28), pcVar1 == (code *)0x0)) {
      uVar7 = 3;
    }
    else {
      uVar3 = (*pcVar1)(lVar4,param_2,param_3,0,&local_40);
      uVar7 = (ulong)uVar3;
      uVar5 = extraout_RDX_02;
      if (uVar3 == 0) {
        if (local_40 <= local_3c[0]) goto LAB_00135a99;
        goto LAB_00135b90;
      }
    }
    if (DAT_01216a78 < 2) goto LAB_00135ad6;
    fVar8 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    fVar8 = fVar8 * DAT_00298548;
    uVar9 = 0x40c;
    uVar6 = 0x40c;
    uVar5 = uVar7;
  }
  FUN_002340f0((double)fVar8,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
               "nvml_mig.c",uVar6,"tsmigDeviceGetGpuInstancePossiblePlacements",uVar9);
  uVar7 = uVar5;
LAB_00135ad6:
  FUN_00291830(&DAT_01216990,0,uVar5);
  return uVar7;
}


// ===== 00135c90 FUN_00135c90 =====

ulong FUN_00135c90(long param_1,undefined4 param_2,undefined8 param_3,long *param_4)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  ulong extraout_RDX;
  ulong extraout_RDX_00;
  ulong uVar5;
  ulong extraout_RDX_01;
  ulong uVar6;
  float fVar7;
  undefined1 auVar8 [16];
  undefined4 local_3c [3];
  
  do {
    iVar2 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar2 != 0);
  lVar4 = *(long *)(param_1 + 0x256d8);
  if (((lVar4 == 0) || (*(long *)(lVar4 + 0x30) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(lVar4 + 0x30) + 0x38), pcVar1 == (code *)0x0)) {
    uVar6 = 3;
    uVar5 = extraout_RDX;
  }
  else {
    uVar3 = (*pcVar1)(lVar4,param_1,param_2,param_3,local_3c);
    uVar6 = (ulong)uVar3;
    uVar5 = extraout_RDX_00;
    if (uVar3 == 0) {
      auVar8 = FUN_00133d60(param_1,local_3c[0],param_2);
      uVar5 = auVar8._8_8_;
      *param_4 = auVar8._0_8_;
      if (auVar8._0_8_ == 0) {
        lVar4 = *(long *)(param_1 + 0x256d8);
        uVar6 = 0x14;
        if (((lVar4 != 0) && (*(long *)(lVar4 + 0x30) != 0)) &&
           (pcVar1 = *(code **)(*(long *)(lVar4 + 0x30) + 0x40), pcVar1 != (code *)0x0)) {
          (*pcVar1)(lVar4,param_1,local_3c[0]);
          uVar5 = extraout_RDX_01;
        }
      }
      goto LAB_00135d1c;
    }
  }
  if (1 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar4,"nvml_mig.c",0x422,"tsmigDeviceCreateGpuInstanceWithPlacement",0x422)
    ;
    uVar5 = uVar6;
  }
LAB_00135d1c:
  FUN_00291830(&DAT_01216990,0,uVar5);
  return uVar6;
}


// ===== 00135e30 FUN_00135e30 =====

int FUN_00135e30(undefined8 *param_1)

{
  int iVar1;
  char *pcVar2;
  code *pcVar3;
  undefined8 *puVar4;
  int iVar5;
  long lVar6;
  undefined8 *puVar7;
  float fVar8;
  
  do {
    iVar5 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar5 != 0);
  puVar7 = DAT_01216970;
  if ((undefined8 **)DAT_01216970 != &DAT_01216970) {
    do {
      if (param_1 == puVar7 + -0x12) {
        pcVar2 = (char *)*param_1;
        if (pcVar2 != (char *)0x0) {
          if ((*pcVar2 == '\x01') ||
             ((((iVar5 = 2, *(int *)(pcVar2 + 0x14) != 0 && (*(int *)(pcVar2 + 0x1c) == 0)) &&
               (*(int *)(pcVar2 + 0x10) != 0)) && (*(long *)(pcVar2 + 0x20) != 0)))) {
            lVar6 = *(long *)(pcVar2 + 0x256d8);
            if (((lVar6 == 0) || (*(long *)(lVar6 + 0x30) == 0)) ||
               (pcVar3 = *(code **)(*(long *)(lVar6 + 0x30) + 0x40), pcVar3 == (code *)0x0)) {
              iVar5 = 3;
            }
            else {
              iVar5 = (*pcVar3)(lVar6,pcVar2,*(undefined4 *)(param_1 + 1));
              if (iVar5 == 0) {
                puVar7 = *(undefined8 **)(pcVar2 + 0x20);
                iVar1 = *(int *)(param_1 + 1);
                for (puVar4 = (undefined8 *)*puVar7; puVar7 != puVar4;
                    puVar4 = (undefined8 *)*puVar4) {
                  if (iVar1 == *(int *)((long)puVar4 + -0xa4)) {
                    if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x30) != 0)) &&
                       (pcVar3 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0xb0),
                       pcVar3 != (code *)0x0)) {
                      (*pcVar3)(DAT_012164a0,puVar4 + -0x15);
                    }
                    *(undefined1 *)(puVar4 + -0xe956) = 0;
                  }
                }
                FUN_00134d20(param_1);
                puVar7 = (undefined8 *)param_1[0x13];
                *(undefined8 **)(param_1[0x12] + 8) = puVar7;
                *puVar7 = param_1[0x12];
                free(param_1);
                goto LAB_00135fa6;
              }
            }
            if (1 < DAT_01216a78) {
              fVar8 = (float)FUN_002917b0(&DAT_01216a60);
              lVar6 = syscall(0xba);
              FUN_002340f0((double)(fVar8 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar6,
                           "nvml_mig.c",0x43c,"tsmigGpuInstanceDestroy",0x43c,iVar5);
            }
          }
          goto LAB_00135fa6;
        }
        break;
      }
      puVar7 = (undefined8 *)*puVar7;
    } while ((undefined8 **)puVar7 != &DAT_01216970);
  }
  iVar5 = 2;
LAB_00135fa6:
  FUN_00291830(&DAT_01216990,0);
  return iVar5;
}


// ===== 001360a0 FUN_001360a0 =====

undefined4 FUN_001360a0(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  do {
    iVar1 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar1 != 0);
  uVar2 = FUN_00134020(param_1,param_2,param_3,param_4);
  FUN_00291830(&DAT_01216990,0);
  return uVar2;
}


// ===== 00136120 FUN_00136120 =====

undefined4 FUN_00136120(undefined8 *param_1,undefined8 *param_2)

{
  char *pcVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined4 uVar4;
  
  do {
    iVar2 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar2 != 0);
  puVar3 = DAT_01216970;
  if ((undefined8 **)DAT_01216970 != &DAT_01216970) {
    do {
      if (param_1 == puVar3 + -0x12) {
        pcVar1 = (char *)*param_1;
        if ((pcVar1 != (char *)0x0) &&
           ((*pcVar1 == '\x01' ||
            ((((*(int *)(pcVar1 + 0x14) != 0 && (*(int *)(pcVar1 + 0x1c) == 0)) &&
              (*(int *)(pcVar1 + 0x10) != 0)) && (*(long *)(pcVar1 + 0x20) != 0)))))) {
          param_2[2] = param_1[2];
          *(undefined4 *)(param_2 + 1) = *(undefined4 *)(param_1 + 1);
          *param_2 = *param_1;
          *(undefined4 *)((long)param_2 + 0xc) = *(undefined4 *)((long)param_1 + 0xc);
          uVar4 = 0;
          goto LAB_001361e6;
        }
        break;
      }
      puVar3 = (undefined8 *)*puVar3;
    } while ((undefined8 **)puVar3 != &DAT_01216970);
  }
  uVar4 = 2;
LAB_001361e6:
  FUN_00291830(&DAT_01216990,0);
  return uVar4;
}


// ===== 00136210 FUN_00136210 =====

int FUN_00136210(long param_1,int param_2,undefined8 *param_3)

{
  int iVar1;
  int iVar2;
  void *__ptr;
  long lVar3;
  undefined8 *puVar4;
  byte bVar5;
  undefined1 local_dc [4];
  undefined4 local_d8;
  undefined4 local_d4;
  uint local_c8;
  
  bVar5 = 0;
  do {
    iVar1 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar1 != 0);
  puVar4 = (undefined8 *)&local_d8;
  for (lVar3 = 0x13; iVar1 = 0, lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + (ulong)bVar5 * -2 + 1;
  }
  do {
    local_d8 = 0x2000098;
    iVar2 = FUN_00134630(param_1,iVar1,&local_d8);
    if (iVar2 == 0) {
      __ptr = malloc((ulong)local_c8 << 3);
      if (__ptr == (void *)0x0) {
        iVar2 = 0x14;
        goto LAB_0013635a;
      }
      iVar2 = FUN_00134020(param_1,local_d4,__ptr,local_dc);
      free(__ptr);
      if (iVar2 != 0) goto LAB_0013635a;
      puVar4 = DAT_01216970;
      if ((undefined8 **)DAT_01216970 != &DAT_01216970) {
        do {
          if ((param_2 == *(int *)(puVar4 + -0x11)) && (param_1 == puVar4[-0x12])) {
            *param_3 = puVar4 + -0x12;
            goto LAB_0013635a;
          }
          puVar4 = (undefined8 *)*puVar4;
        } while ((undefined8 **)puVar4 != &DAT_01216970);
      }
      *param_3 = 0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x12);
  iVar2 = 6;
LAB_0013635a:
  FUN_00291830(&DAT_01216990,0);
  return iVar2;
}


// ===== 001363a0 FUN_001363a0 =====

undefined4 FUN_001363a0(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  do {
    iVar1 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar1 != 0);
  uVar2 = FUN_00134770(param_1,param_2,param_3,param_4);
  FUN_00291830(&DAT_01216990,0);
  return uVar2;
}


// ===== 00136420 FUN_00136420 =====

undefined4 FUN_00136420(undefined8 *param_1,undefined4 param_2,undefined8 param_3)

{
  char *pcVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  
  do {
    iVar4 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar4 != 0);
  puVar6 = DAT_01216970;
  if ((undefined8 **)DAT_01216970 != &DAT_01216970) {
    do {
      if (param_1 == puVar6 + -0x12) {
        pcVar1 = (char *)*param_1;
        if (pcVar1 != (char *)0x0) {
          if ((*pcVar1 == '\x01') ||
             ((((uVar5 = 2, *(int *)(pcVar1 + 0x14) != 0 && (*(int *)(pcVar1 + 0x1c) == 0)) &&
               (*(int *)(pcVar1 + 0x10) != 0)) && (*(long *)(pcVar1 + 0x20) != 0)))) {
            lVar2 = *(long *)(pcVar1 + 0x256d8);
            if (((lVar2 == 0) || (*(long *)(lVar2 + 0x30) == 0)) ||
               (pcVar3 = *(code **)(*(long *)(lVar2 + 0x30) + 0x50), pcVar3 == (code *)0x0)) {
              uVar5 = 3;
            }
            else {
              uVar5 = (*pcVar3)(lVar2,pcVar1,*(undefined4 *)(param_1 + 1),param_1 + 2,param_2,
                                param_3);
            }
          }
          goto LAB_001364fe;
        }
        break;
      }
      puVar6 = (undefined8 *)*puVar6;
    } while ((undefined8 **)puVar6 != &DAT_01216970);
  }
  uVar5 = 2;
LAB_001364fe:
  FUN_00291830(&DAT_01216990,0);
  return uVar5;
}


// ===== 00136530 FUN_00136530 =====

undefined4
FUN_00136530(undefined8 *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  char *pcVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  
  do {
    iVar4 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar4 != 0);
  puVar6 = DAT_01216970;
  if ((undefined8 **)DAT_01216970 != &DAT_01216970) {
    do {
      if (param_1 == puVar6 + -0x12) {
        pcVar1 = (char *)*param_1;
        if (pcVar1 != (char *)0x0) {
          if ((*pcVar1 == '\x01') ||
             ((((uVar5 = 2, *(int *)(pcVar1 + 0x14) != 0 && (*(int *)(pcVar1 + 0x1c) == 0)) &&
               (*(int *)(pcVar1 + 0x10) != 0)) && (*(long *)(pcVar1 + 0x20) != 0)))) {
            lVar2 = *(long *)(pcVar1 + 0x256d8);
            if (((lVar2 == 0) || (*(long *)(lVar2 + 0x30) == 0)) ||
               (pcVar3 = *(code **)(*(long *)(lVar2 + 0x30) + 0x60), pcVar3 == (code *)0x0)) {
              uVar5 = 3;
            }
            else {
              uVar5 = (*pcVar3)(lVar2,pcVar1,*(undefined4 *)(param_1 + 1),param_1 + 2,param_2,
                                param_3,param_4);
              puVar6 = (undefined8 *)0x136567;
            }
          }
          goto LAB_0013661e;
        }
        break;
      }
      puVar6 = (undefined8 *)*puVar6;
    } while ((undefined8 **)puVar6 != &DAT_01216970);
  }
  uVar5 = 2;
LAB_0013661e:
  FUN_00291830(&DAT_01216990,0,puVar6);
  return uVar5;
}


// ===== 00136650 FUN_00136650 =====

undefined8 * FUN_00136650(undefined8 *param_1,undefined4 param_2,undefined8 param_3,long *param_4)

{
  char *pcVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  undefined8 *extraout_RDX;
  undefined8 *extraout_RDX_00;
  undefined8 *puVar6;
  undefined8 *extraout_RDX_01;
  undefined8 uVar7;
  undefined8 *puVar8;
  float fVar9;
  undefined1 auVar10 [16];
  undefined8 uVar11;
  undefined4 local_7c;
  undefined1 local_78 [16];
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined8 local_48;
  
  do {
    iVar3 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar3 != 0);
  local_48 = 0;
  local_78 = (undefined1  [16])0x0;
  local_68 = (undefined1  [16])0x0;
  local_58 = (undefined1  [16])0x0;
  puVar6 = DAT_01216970;
  if ((undefined8 **)DAT_01216970 != &DAT_01216970) {
    do {
      if (param_1 == puVar6 + -0x12) {
        pcVar1 = (char *)*param_1;
        if (pcVar1 != (char *)0x0) {
          if ((*pcVar1 != '\x01') &&
             ((((puVar8 = (undefined8 *)0x2, *(int *)(pcVar1 + 0x14) == 0 ||
                (*(int *)(pcVar1 + 0x1c) != 0)) || (*(int *)(pcVar1 + 0x10) == 0)) ||
              (*(long *)(pcVar1 + 0x20) == 0)))) goto LAB_00136836;
          lVar5 = *(long *)(pcVar1 + 0x256d8);
          if (((lVar5 == 0) || (*(long *)(lVar5 + 0x30) == 0)) ||
             (pcVar2 = *(code **)(*(long *)(lVar5 + 0x30) + 0x70), pcVar2 == (code *)0x0)) {
            puVar8 = (undefined8 *)0x3;
LAB_00136866:
            if (DAT_01216a78 < 2) goto LAB_00136836;
            fVar9 = (float)FUN_002917b0(&DAT_01216a60);
            lVar5 = syscall(0xba);
            fVar9 = fVar9 * DAT_00298548;
            uVar11 = 0x500;
            uVar7 = 0x500;
            puVar6 = puVar8;
          }
          else {
            uVar4 = (*pcVar2)(lVar5,pcVar1,*(undefined4 *)(param_1 + 1),param_1 + 2,param_2,param_3)
            ;
            puVar8 = (undefined8 *)(ulong)uVar4;
            puVar6 = extraout_RDX;
            if (uVar4 != 0) goto LAB_00136866;
            lVar5 = *(long *)(pcVar1 + 0x256d8);
            if (((lVar5 == 0) || (*(long *)(lVar5 + 0x30) == 0)) ||
               (pcVar2 = *(code **)(*(long *)(lVar5 + 0x30) + 0x68), pcVar2 == (code *)0x0)) {
              puVar8 = (undefined8 *)0x3;
            }
            else {
              uVar4 = (*pcVar2)(lVar5,pcVar1,*(undefined4 *)(param_1 + 1),local_7c,local_78);
              puVar8 = (undefined8 *)(ulong)uVar4;
              puVar6 = extraout_RDX_00;
              if (uVar4 == 0) {
                auVar10 = FUN_00134940(param_1,local_7c,param_2,local_78);
                puVar6 = auVar10._8_8_;
                *param_4 = auVar10._0_8_;
                if (auVar10._0_8_ == 0) {
                  lVar5 = *(long *)(pcVar1 + 0x256d8);
                  puVar8 = (undefined8 *)0x14;
                  if (((lVar5 != 0) && (*(long *)(lVar5 + 0x30) != 0)) &&
                     (pcVar2 = *(code **)(*(long *)(lVar5 + 0x30) + 0x78), pcVar2 != (code *)0x0)) {
                    (*pcVar2)(lVar5,pcVar1,*(undefined4 *)(param_1 + 1),local_7c);
                    puVar6 = extraout_RDX_01;
                  }
                }
                goto LAB_00136836;
              }
            }
            if (DAT_01216a78 < 2) goto LAB_00136836;
            fVar9 = (float)FUN_002917b0(&DAT_01216a60);
            lVar5 = syscall(0xba);
            fVar9 = fVar9 * DAT_00298548;
            uVar11 = 0x506;
            uVar7 = 0x506;
            puVar6 = puVar8;
          }
          FUN_002340f0((double)fVar9,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,
                       "nvml_mig.c",uVar7,"tsmigGpuInstanceCreateComputeInstanceWithPlacement",
                       uVar11);
          puVar8 = puVar6;
          goto LAB_00136836;
        }
        break;
      }
      puVar6 = (undefined8 *)*puVar6;
    } while ((undefined8 **)puVar6 != &DAT_01216970);
  }
  puVar8 = (undefined8 *)0x2;
LAB_00136836:
  FUN_00291830(&DAT_01216990,0,puVar6);
  return puVar8;
}


// ===== 00136960 FUN_00136960 =====

int FUN_00136960(undefined8 *param_1)

{
  char *pcVar1;
  code *pcVar2;
  undefined8 *puVar3;
  int iVar4;
  long lVar5;
  undefined8 *puVar6;
  float fVar7;
  
  do {
    iVar4 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar4 != 0);
  puVar6 = DAT_01216980;
  if ((undefined8 **)DAT_01216980 != &DAT_01216980) {
    do {
      if (param_1 == puVar6 + -10) {
        puVar6 = (undefined8 *)param_1[1];
        pcVar1 = (char *)*puVar6;
        if (pcVar1 != (char *)0x0) {
          if ((*pcVar1 != '\x01') &&
             ((((iVar4 = 2, *(int *)(pcVar1 + 0x14) == 0 || (*(int *)(pcVar1 + 0x1c) != 0)) ||
               (*(int *)(pcVar1 + 0x10) == 0)) || (*(long *)(pcVar1 + 0x20) == 0))))
          goto LAB_00136ad6;
          lVar5 = *(long *)(pcVar1 + 0x256d8);
          if (((lVar5 == 0) || (*(long *)(lVar5 + 0x30) == 0)) ||
             (pcVar2 = *(code **)(*(long *)(lVar5 + 0x30) + 0x78), pcVar2 == (code *)0x0)) {
            iVar4 = 3;
          }
          else {
            iVar4 = (*pcVar2)(lVar5,pcVar1,*(undefined4 *)(puVar6 + 1),*(undefined4 *)(param_1 + 2))
            ;
            if (iVar4 == 0) {
              puVar3 = (undefined8 *)**(undefined8 **)(pcVar1 + 0x20);
              goto joined_r0x00136b19;
            }
          }
          if (1 < DAT_01216a78) {
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar5 = syscall(0xba);
            FUN_002340f0((double)(fVar7 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,"nvml_mig.c",
                         0x526,"tsmigComputeInstanceDestroy",0x526,iVar4);
          }
          goto LAB_00136ad6;
        }
        break;
      }
      puVar6 = (undefined8 *)*puVar6;
    } while ((undefined8 **)puVar6 != &DAT_01216980);
  }
  iVar4 = 2;
LAB_00136ad6:
  FUN_00291830(&DAT_01216990,0);
  return iVar4;
joined_r0x00136b19:
  if (*(undefined8 **)(pcVar1 + 0x20) == puVar3) goto LAB_00136b80;
  if (((pcVar1 == (char *)puVar3[-2]) && (*(int *)(puVar6 + 1) == *(int *)((long)puVar3 + -0xa4)))
     && (*(int *)(param_1 + 2) == *(int *)(puVar3 + -0x14))) {
    if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x30) != 0)) &&
       (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0xb0), pcVar2 != (code *)0x0)) {
      (*pcVar2)(DAT_012164a0,puVar3 + -0x15);
    }
    *(undefined1 *)(puVar3 + -0xe956) = 0;
    goto LAB_00136b80;
  }
  puVar3 = (undefined8 *)*puVar3;
  goto joined_r0x00136b19;
LAB_00136b80:
  puVar6 = (undefined8 *)param_1[0xb];
  *(undefined8 **)(param_1[10] + 8) = puVar6;
  *puVar6 = param_1[10];
  free(param_1);
  goto LAB_00136ad6;
}


// ===== 00136bd0 FUN_00136bd0 =====

undefined4 FUN_00136bd0(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  do {
    iVar1 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar1 != 0);
  uVar2 = FUN_00134a10(param_1,param_2,param_3,param_4);
  FUN_00291830(&DAT_01216990,0);
  return uVar2;
}


// ===== 00136c50 FUN_00136c50 =====

int FUN_00136c50(undefined8 *param_1,int param_2,undefined8 *param_3)

{
  char *pcVar1;
  int iVar2;
  void *__ptr;
  undefined8 *puVar3;
  int iVar4;
  undefined1 local_cc [4];
  undefined4 local_c8;
  undefined4 local_c4;
  uint local_bc;
  
  do {
    iVar2 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar2 != 0);
  puVar3 = DAT_01216970;
  if ((undefined8 **)DAT_01216970 != &DAT_01216970) {
    do {
      if (param_1 == puVar3 + -0x12) {
        pcVar1 = (char *)*param_1;
        if (pcVar1 != (char *)0x0) {
          if ((*pcVar1 != '\x01') &&
             ((((iVar2 = 2, *(int *)(pcVar1 + 0x14) == 0 || (*(int *)(pcVar1 + 0x1c) != 0)) ||
               (*(int *)(pcVar1 + 0x10) == 0)) || (*(long *)(pcVar1 + 0x20) == 0))))
          goto LAB_00136deb;
          iVar4 = 0;
          goto LAB_00136d2d;
        }
        break;
      }
      puVar3 = (undefined8 *)*puVar3;
    } while ((undefined8 **)puVar3 != &DAT_01216970);
  }
  iVar2 = 2;
  goto LAB_00136deb;
LAB_00136d2d:
  do {
    local_c8 = 0x2000088;
    iVar2 = FUN_00134770(param_1,iVar4,0,&local_c8);
    if (iVar2 != 3) {
      if (iVar2 != 0) goto LAB_00136deb;
      __ptr = malloc((ulong)local_bc << 3);
      if (__ptr == (void *)0x0) {
        iVar2 = 0x14;
        goto LAB_00136deb;
      }
      iVar2 = FUN_00134a10(param_1,local_c4,__ptr,local_cc);
      free(__ptr);
      if (iVar2 != 0) goto LAB_00136deb;
      puVar3 = DAT_01216980;
      if ((undefined8 **)DAT_01216980 != &DAT_01216980) {
        do {
          if ((param_2 == *(int *)(puVar3 + -8)) && (param_1 == (undefined8 *)puVar3[-9])) {
            *param_3 = puVar3 + -10;
            goto LAB_00136deb;
          }
          puVar3 = (undefined8 *)*puVar3;
        } while ((undefined8 **)puVar3 != &DAT_01216980);
      }
      *param_3 = 0;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 != 8);
  iVar2 = 6;
LAB_00136deb:
  FUN_00291830(&DAT_01216990,0);
  return iVar2;
}


// ===== 00136e50 FUN_00136e50 =====

undefined8 * FUN_00136e50(uint param_1,long *param_2,long *param_3)

{
  char *pcVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 *extraout_RDX;
  undefined8 *puVar7;
  float fVar8;
  
  do {
    iVar3 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar3 != 0);
  puVar6 = DAT_01216980;
  if ((undefined8 **)DAT_01216980 != &DAT_01216980) {
    do {
      if (param_2 == puVar6 + -10) {
        pcVar1 = *(char **)param_2[1];
        if ((pcVar1 != (char *)0x0) &&
           ((*pcVar1 == '\x01' ||
            ((((puVar6 = (undefined8 *)(ulong)*(uint *)(pcVar1 + 0x14),
               *(uint *)(pcVar1 + 0x14) != 0 && (*(int *)(pcVar1 + 0x1c) == 0)) &&
              (*(int *)(pcVar1 + 0x10) != 0)) && (*(long *)(pcVar1 + 0x20) != 0)))))) {
          *(int *)(param_3 + 2) = (int)param_2[2];
          *param_3 = *param_2;
          param_3[1] = param_2[1];
          *(undefined4 *)((long)param_3 + 0x14) = *(undefined4 *)((long)param_2 + 0x14);
          puVar7 = (undefined8 *)0x0;
          if (param_1 < 2) goto LAB_00136f76;
          lVar5 = *(long *)(*param_2 + 0x256d8);
          if (((lVar5 == 0) || (*(long *)(lVar5 + 0x30) == 0)) ||
             (pcVar2 = *(code **)(*(long *)(lVar5 + 0x30) + 0x68), pcVar2 == (code *)0x0)) {
            puVar7 = (undefined8 *)0x3;
          }
          else {
            uVar4 = (*pcVar2)(lVar5,*param_2,*(undefined4 *)(param_2[1] + 8),(int)param_2[2],
                              param_2 + 3);
            puVar7 = (undefined8 *)(ulong)uVar4;
            puVar6 = extraout_RDX;
            if (uVar4 == 0) {
              *(int *)(param_3 + 3) = (int)param_2[7];
              *(undefined4 *)((long)param_3 + 0x1c) = *(undefined4 *)((long)param_2 + 0x3c);
              puVar6 = extraout_RDX;
              goto LAB_00136f76;
            }
          }
          if (1 < DAT_01216a78) {
            fVar8 = (float)FUN_002917b0(&DAT_01216a60);
            lVar5 = syscall(0xba);
            FUN_002340f0((double)(fVar8 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,"nvml_mig.c",
                         0x5c9,"tsmigComputeInstanceGetInfo",0x5c9);
            puVar6 = puVar7;
          }
          goto LAB_00136f76;
        }
        break;
      }
      puVar6 = (undefined8 *)*puVar6;
    } while ((undefined8 **)puVar6 != &DAT_01216980);
  }
  puVar7 = (undefined8 *)0x2;
LAB_00136f76:
  FUN_00291830(&DAT_01216990,0,puVar6);
  return puVar7;
}


// ===== 00137020 FUN_00137020 =====

undefined8 FUN_00137020(char *param_1,uint *param_2)

{
  byte bVar1;
  int iVar2;
  
  do {
    iVar2 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar2 != 0);
  if (param_1 != (char *)0x0) {
    if ((*param_1 == '\x01') || (*(long *)(param_1 + 0x20) != 0)) {
      param_1 = (char *)0x0;
    }
    else {
      param_1 = param_1 + -8;
    }
  }
  bVar1 = FUN_00133d10(param_1);
  *param_2 = (uint)bVar1;
  FUN_00291830(&DAT_01216990,0);
  return 0;
}


// ===== 001370b0 FUN_001370b0 =====

undefined4 FUN_001370b0(char *param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  do {
    iVar2 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar2 != 0);
  if (param_1 != (char *)0x0) {
    if ((*param_1 == '\x01') || (*(long *)(param_1 + 0x20) != 0)) {
      param_1 = (char *)0x0;
      cVar1 = FUN_00133d10(0);
      goto joined_r0x00137145;
    }
    param_1 = param_1 + -8;
  }
  cVar1 = FUN_00133d10(param_1);
joined_r0x00137145:
  if (cVar1 == '\0') {
    uVar3 = 2;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x74a0c);
    uVar3 = 0;
  }
  FUN_00291830(&DAT_01216990,0);
  return uVar3;
}


// ===== 00137150 FUN_00137150 =====

undefined4 FUN_00137150(char *param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  do {
    iVar2 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar2 != 0);
  if (param_1 != (char *)0x0) {
    if ((*param_1 == '\x01') || (*(long *)(param_1 + 0x20) != 0)) {
      param_1 = (char *)0x0;
      cVar1 = FUN_00133d10(0);
      goto joined_r0x001371e5;
    }
    param_1 = param_1 + -8;
  }
  cVar1 = FUN_00133d10(param_1);
joined_r0x001371e5:
  if (cVar1 == '\0') {
    uVar3 = 2;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x74a10);
    uVar3 = 0;
  }
  FUN_00291830(&DAT_01216990,0);
  return uVar3;
}


// ===== 001371f0 FUN_001371f0 =====

undefined4 FUN_001371f0(long param_1,undefined8 param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  
  do {
    iVar3 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar3 != 0);
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 == 0) || (*(long *)(lVar1 + 0x30) == 0)) ||
     (pcVar2 = *(code **)(*(long *)(lVar1 + 0x30) + 0xa8), pcVar2 == (code *)0x0)) {
    uVar4 = 3;
  }
  else {
    uVar4 = (*pcVar2)(lVar1,param_1,param_2);
  }
  FUN_00291830(&DAT_01216990,0);
  return uVar4;
}


// ===== 00137280 FUN_00137280 =====

undefined4 FUN_00137280(long param_1,int param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  char cVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined4 uVar5;
  
  do {
    iVar3 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar3 != 0);
  FUN_00134da0(param_1);
  puVar1 = (undefined8 *)**(undefined8 **)(param_1 + 0x20);
  do {
    if (*(undefined8 **)(param_1 + 0x20) == puVar1) {
      puVar4 = (undefined8 *)0x0;
      cVar2 = FUN_00133d10();
joined_r0x00137300:
      if (cVar2 == '\0') {
        uVar5 = 6;
      }
      else {
        *param_3 = puVar4 + 1;
        uVar5 = 0;
      }
      FUN_00291830(&DAT_01216990,0);
      return uVar5;
    }
    puVar4 = puVar1 + -0xe956;
    if (param_2 == *(int *)((long)puVar1 + -0x74aac)) {
      cVar2 = FUN_00133d10();
      goto joined_r0x00137300;
    }
    puVar1 = (undefined8 *)*puVar1;
  } while( true );
}


// ===== 00137350 FUN_00137350 =====

undefined4 FUN_00137350(long param_1,char *param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  
  do {
    iVar4 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar4 != 0);
  FUN_00134da0(param_1);
  puVar1 = *(undefined8 **)(param_1 + 0x20);
  puVar2 = (undefined8 *)*puVar1;
  do {
    if (puVar1 == puVar2) {
      uVar5 = 6;
LAB_001373e2:
      FUN_00291830(&DAT_01216990,0);
      return uVar5;
    }
    iVar4 = strcmp((char *)((long)puVar2 + -0x9c),param_2);
    if (((iVar4 == 0) || (iVar4 = strcmp((char *)((long)puVar2 + -0x73),param_2), iVar4 == 0)) &&
       (cVar3 = FUN_00133d10(puVar2 + -0xe956), cVar3 != '\0')) {
      *param_3 = puVar2 + -0xe955;
      uVar5 = 0;
      goto LAB_001373e2;
    }
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}


// ===== 00137430 FUN_00137430 =====

undefined4 FUN_00137430(char *param_1,undefined8 *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  do {
    iVar2 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar2 != 0);
  if (param_1 != (char *)0x0) {
    if ((*param_1 == '\x01') || (*(long *)(param_1 + 0x20) != 0)) {
      param_1 = (char *)0x0;
      cVar1 = FUN_00133d10(0);
      goto joined_r0x001374c5;
    }
    param_1 = param_1 + -8;
  }
  cVar1 = FUN_00133d10(param_1);
joined_r0x001374c5:
  if (cVar1 == '\0') {
    uVar3 = 2;
  }
  else {
    *param_2 = *(undefined8 *)(param_1 + 0x74aa0);
    uVar3 = 0;
  }
  FUN_00291830(&DAT_01216990,0);
  return uVar3;
}


// ===== 001374d0 FUN_001374d0 =====

undefined4 FUN_001374d0(char *param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  do {
    iVar2 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar2 != 0);
  if (param_1 != (char *)0x0) {
    if ((*param_1 == '\x01') || (*(long *)(param_1 + 0x20) != 0)) {
      param_1 = (char *)0x0;
      cVar1 = FUN_00133d10(0);
      goto joined_r0x00137528;
    }
    param_1 = param_1 + -8;
  }
  cVar1 = FUN_00133d10(param_1);
joined_r0x00137528:
  if ((param_2 == (undefined4 *)0x0) || (cVar1 == '\0')) {
    uVar3 = 2;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 4);
    uVar3 = 0;
  }
  FUN_00291830(&DAT_01216990,0);
  return uVar3;
}


// ===== 00137580 FUN_00137580 =====

undefined4 FUN_00137580(char *param_1,undefined8 *param_2,uint param_3)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  do {
    iVar3 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar3 != 0);
  if (param_3 < 0x60) {
    uVar4 = 7;
    goto LAB_0013761d;
  }
  if (param_1 == (char *)0x0) {
LAB_001375df:
    cVar2 = FUN_00133d10(param_1);
  }
  else {
    if ((*param_1 != '\x01') && (*(long *)(param_1 + 0x20) == 0)) {
      param_1 = param_1 + -8;
      goto LAB_001375df;
    }
    param_1 = (char *)0x0;
    cVar2 = FUN_00133d10(0);
  }
  if (cVar2 == '\0') {
    uVar4 = 2;
  }
  else {
    uVar1 = *(undefined8 *)(param_1 + 0x74a1c);
    *param_2 = *(undefined8 *)(param_1 + 0x74a14);
    param_2[1] = uVar1;
    uVar1 = *(undefined8 *)(param_1 + 0x74a2c);
    param_2[2] = *(undefined8 *)(param_1 + 0x74a24);
    param_2[3] = uVar1;
    param_2[4] = *(undefined8 *)(param_1 + 0x74a34);
    *(char *)(param_2 + 5) = param_1[0x74a3c];
    uVar4 = 0;
  }
LAB_0013761d:
  FUN_00291830(&DAT_01216990,0);
  return uVar4;
}


// ===== 00137670 FUN_00137670 =====

undefined4 FUN_00137670(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  do {
    iVar1 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar1 != 0);
  uVar2 = FUN_00133ed0(param_1,param_2,param_3);
  FUN_00291830(&DAT_01216990,0);
  return uVar2;
}


// ===== 001376e0 FUN_001376e0 =====

undefined4 FUN_001376e0(char *param_1,undefined8 param_2)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  do {
    iVar3 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar3 != 0);
  if (param_1 != (char *)0x0) {
    if ((*param_1 == '\x01') || (*(long *)(param_1 + 0x20) != 0)) {
      param_1 = (char *)0x0;
    }
    else {
      param_1 = param_1 + -8;
    }
  }
  uVar4 = 2;
  cVar2 = FUN_00133d10(param_1);
  if (cVar2 != '\0') {
    if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x30) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0xd0), pcVar1 == (code *)0x0)) {
      uVar4 = 3;
    }
    else {
      uVar4 = (*pcVar1)(DAT_012164a0,param_1 + 0x74a08,param_2);
    }
  }
  FUN_00291830(&DAT_01216990,0);
  return uVar4;
}


// ===== 001377c0 FUN_001377c0 =====

undefined4
FUN_001377c0(undefined4 param_1,char *param_2,undefined4 param_3,undefined8 param_4,
            undefined8 param_5)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  char local_39 [9];
  
  do {
    iVar4 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar4 != 0);
  pcVar6 = (char *)0x0;
  if (((param_2 != (char *)0x0) && (*param_2 != '\x01')) && (*(long *)(param_2 + 0x20) == 0)) {
    pcVar6 = param_2 + -8;
  }
  uVar5 = 2;
  cVar3 = FUN_00133d10(pcVar6);
  if (cVar3 == '\0') goto LAB_0013786b;
  lVar1 = *(long *)(param_2 + 0x256d8);
  local_39[0] = '\0';
  if (((lVar1 == 0) || (*(long *)(lVar1 + 0x38) == 0)) ||
     (pcVar2 = *(code **)(*(long *)(lVar1 + 0x38) + 0x80), pcVar2 == (code *)0x0)) {
LAB_00137898:
    if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x30) != 0)) &&
       (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0xd8), pcVar2 != (code *)0x0)) {
      uVar5 = (*pcVar2)(DAT_012164a0,param_1,pcVar6 + 0x74a08,param_3,param_4,param_5);
      goto LAB_0013786b;
    }
  }
  else {
    (*pcVar2)(lVar1,param_2,local_39);
    if (local_39[0] == '\0') goto LAB_00137898;
  }
  uVar5 = 3;
LAB_0013786b:
  FUN_00291830(&DAT_01216990,0);
  return uVar5;
}


// ===== 001378e0 FUN_001378e0 =====

undefined4 FUN_001378e0(char *param_1,undefined8 param_2)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  char local_29;
  
  do {
    iVar4 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar4 != 0);
  pcVar6 = (char *)0x0;
  if (((param_1 != (char *)0x0) && (*param_1 != '\x01')) && (*(long *)(param_1 + 0x20) == 0)) {
    pcVar6 = param_1 + -8;
  }
  uVar5 = 2;
  cVar3 = FUN_00133d10(pcVar6);
  if (cVar3 == '\0') goto LAB_0013797b;
  lVar1 = *(long *)(param_1 + 0x256d8);
  local_29 = '\0';
  if (((lVar1 == 0) || (*(long *)(lVar1 + 0x38) == 0)) ||
     (pcVar2 = *(code **)(*(long *)(lVar1 + 0x38) + 0x80), pcVar2 == (code *)0x0)) {
LAB_001379a0:
    if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x30) != 0)) &&
       (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0xf8), pcVar2 != (code *)0x0)) {
      uVar5 = (*pcVar2)(DAT_012164a0,pcVar6 + 0x74a08,param_2);
      goto LAB_0013797b;
    }
  }
  else {
    (*pcVar2)(lVar1,param_1,&local_29);
    if (local_29 == '\0') goto LAB_001379a0;
  }
  uVar5 = 3;
LAB_0013797b:
  FUN_00291830(&DAT_01216990,0);
  return uVar5;
}


// ===== 001379e0 FUN_001379e0 =====

undefined4 FUN_001379e0(char *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  char local_39 [9];
  
  do {
    iVar4 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar4 != 0);
  pcVar6 = (char *)0x0;
  if (((param_1 != (char *)0x0) && (*param_1 != '\x01')) && (*(long *)(param_1 + 0x20) == 0)) {
    pcVar6 = param_1 + -8;
  }
  uVar5 = 2;
  cVar3 = FUN_00133d10(pcVar6);
  if (cVar3 == '\0') goto LAB_00137a83;
  lVar1 = *(long *)(param_1 + 0x256d8);
  local_39[0] = '\0';
  if (((lVar1 == 0) || (*(long *)(lVar1 + 0x38) == 0)) ||
     (pcVar2 = *(code **)(*(long *)(lVar1 + 0x38) + 0x80), pcVar2 == (code *)0x0)) {
LAB_00137ab0:
    if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x30) != 0)) &&
       (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0xe0), pcVar2 != (code *)0x0)) {
      uVar5 = (*pcVar2)(DAT_012164a0,pcVar6 + 0x74a08,param_2,param_3,param_4);
      goto LAB_00137a83;
    }
  }
  else {
    (*pcVar2)(lVar1,param_1,local_39);
    if (local_39[0] == '\0') goto LAB_00137ab0;
  }
  uVar5 = 3;
LAB_00137a83:
  FUN_00291830(&DAT_01216990,0);
  return uVar5;
}


// ===== 00137af0 FUN_00137af0 =====

undefined4
FUN_00137af0(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined8 param_5)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  do {
    iVar3 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar3 != 0);
  if (param_1 != (char *)0x0) {
    if ((*param_1 == '\x01') || (*(long *)(param_1 + 0x20) != 0)) {
      param_1 = (char *)0x0;
    }
    else {
      param_1 = param_1 + -8;
    }
  }
  uVar4 = 2;
  cVar2 = FUN_00133d10(param_1);
  if (cVar2 != '\0') {
    if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x30) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0xe8), pcVar1 == (code *)0x0)) {
      uVar4 = 3;
    }
    else {
      uVar4 = (*pcVar1)(DAT_012164a0,param_1 + 0x74a08,param_2,param_3,param_4,param_5);
    }
  }
  FUN_00291830(&DAT_01216990,0);
  return uVar4;
}


// ===== 00137bf0 FUN_00137bf0 =====

undefined4 FUN_00137bf0(char *param_1,undefined8 param_2)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  do {
    iVar3 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar3 != 0);
  if (param_1 != (char *)0x0) {
    if ((*param_1 == '\x01') || (*(long *)(param_1 + 0x20) != 0)) {
      param_1 = (char *)0x0;
    }
    else {
      param_1 = param_1 + -8;
    }
  }
  uVar4 = 2;
  cVar2 = FUN_00133d10(param_1);
  if (cVar2 != '\0') {
    if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x30) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0xf0), pcVar1 == (code *)0x0)) {
      uVar4 = 3;
    }
    else {
      uVar4 = (*pcVar1)(DAT_012164a0,param_1 + 0x74a08,param_2);
    }
  }
  FUN_00291830(&DAT_01216990,0);
  return uVar4;
}


// ===== 00137cd0 FUN_00137cd0 =====

undefined4 FUN_00137cd0(char *param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  do {
    iVar2 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar2 != 0);
  uVar3 = 2;
  if (((param_1 != (char *)0x0) && (*param_1 != '\x01')) && (*(long *)(param_1 + 0x20) == 0)) {
    if (((DAT_012164a0 == 0) || (*(undefined8 **)(DAT_012164a0 + 0x100) == (undefined8 *)0x0)) ||
       (pcVar1 = (code *)**(undefined8 **)(DAT_012164a0 + 0x100), pcVar1 == (code *)0x0)) {
      uVar3 = 3;
    }
    else {
      uVar3 = (*pcVar1)(DAT_012164a0,param_1,param_2);
    }
  }
  FUN_00291830(&DAT_01216990,0);
  return uVar3;
}


// ===== 00137d80 FUN_00137d80 =====

undefined4 FUN_00137d80(char *param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  do {
    iVar2 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar2 != 0);
  uVar3 = 2;
  if (((param_1 != (char *)0x0) && (*param_1 != '\x01')) && (*(long *)(param_1 + 0x20) == 0)) {
    if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x100) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x100) + 8), pcVar1 == (code *)0x0)) {
      uVar3 = 3;
    }
    else {
      uVar3 = (*pcVar1)(DAT_012164a0,param_1,param_2);
    }
  }
  FUN_00291830(&DAT_01216990,0);
  return uVar3;
}


// ===== 00137e30 FUN_00137e30 =====

undefined4 FUN_00137e30(undefined8 *param_1,undefined8 param_2)

{
  char *pcVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  
  do {
    iVar3 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar3 != 0);
  puVar5 = DAT_01216970;
  if ((undefined8 **)DAT_01216970 != &DAT_01216970) {
    do {
      if (param_1 == puVar5 + -0x12) {
        pcVar1 = (char *)*param_1;
        if (pcVar1 != (char *)0x0) {
          if ((*pcVar1 == '\x01') ||
             ((((uVar4 = 2, *(int *)(pcVar1 + 0x14) != 0 && (*(int *)(pcVar1 + 0x1c) == 0)) &&
               (*(int *)(pcVar1 + 0x10) != 0)) && (*(long *)(pcVar1 + 0x20) != 0)))) {
            if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x30) == 0)) ||
               (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0x110), pcVar2 == (code *)0x0))
            {
              uVar4 = 3;
            }
            else {
              uVar4 = (*pcVar2)(DAT_012164a0,param_1,param_2);
            }
          }
          goto LAB_00137f0e;
        }
        break;
      }
      puVar5 = (undefined8 *)*puVar5;
    } while ((undefined8 **)puVar5 != &DAT_01216970);
  }
  uVar4 = 2;
LAB_00137f0e:
  FUN_00291830(&DAT_01216990,0);
  return uVar4;
}


// ===== 00137f40 FUN_00137f40 =====

undefined4 FUN_00137f40(undefined8 *param_1,undefined8 param_2)

{
  char *pcVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  
  do {
    iVar3 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar3 != 0);
  puVar5 = DAT_01216970;
  if ((undefined8 **)DAT_01216970 != &DAT_01216970) {
    do {
      if (param_1 == puVar5 + -0x12) {
        pcVar1 = (char *)*param_1;
        if (pcVar1 != (char *)0x0) {
          if ((*pcVar1 == '\x01') ||
             ((((uVar4 = 2, *(int *)(pcVar1 + 0x14) != 0 && (*(int *)(pcVar1 + 0x1c) == 0)) &&
               (*(int *)(pcVar1 + 0x10) != 0)) && (*(long *)(pcVar1 + 0x20) != 0)))) {
            if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x30) == 0)) ||
               (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0x118), pcVar2 == (code *)0x0))
            {
              uVar4 = 3;
            }
            else {
              uVar4 = (*pcVar2)(DAT_012164a0,param_1,param_2);
            }
          }
          goto LAB_0013801e;
        }
        break;
      }
      puVar5 = (undefined8 *)*puVar5;
    } while ((undefined8 **)puVar5 != &DAT_01216970);
  }
  uVar4 = 2;
LAB_0013801e:
  FUN_00291830(&DAT_01216990,0);
  return uVar4;
}


// ===== 00138050 FUN_00138050 =====

undefined4 FUN_00138050(undefined8 *param_1,undefined8 param_2)

{
  char *pcVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  
  do {
    iVar3 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar3 != 0);
  puVar5 = DAT_01216970;
  if ((undefined8 **)DAT_01216970 != &DAT_01216970) {
    do {
      if (param_1 == puVar5 + -0x12) {
        pcVar1 = (char *)*param_1;
        if (pcVar1 != (char *)0x0) {
          if ((*pcVar1 == '\x01') ||
             ((((uVar4 = 2, *(int *)(pcVar1 + 0x14) != 0 && (*(int *)(pcVar1 + 0x1c) == 0)) &&
               (*(int *)(pcVar1 + 0x10) != 0)) && (*(long *)(pcVar1 + 0x20) != 0)))) {
            if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x30) == 0)) ||
               (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0x120), pcVar2 == (code *)0x0))
            {
              uVar4 = 3;
            }
            else {
              uVar4 = (*pcVar2)(DAT_012164a0,param_1,param_2);
            }
          }
          goto LAB_0013812e;
        }
        break;
      }
      puVar5 = (undefined8 *)*puVar5;
    } while ((undefined8 **)puVar5 != &DAT_01216970);
  }
  uVar4 = 2;
LAB_0013812e:
  FUN_00291830(&DAT_01216990,0);
  return uVar4;
}


// ===== 00138160 FUN_00138160 =====

undefined4 FUN_00138160(undefined8 *param_1,long param_2)

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


// ===== 00138280 FUN_00138280 =====

undefined4 FUN_00138280(undefined8 *param_1,long param_2)

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


// ===== 001383a0 FUN_001383a0 =====

undefined4 FUN_001383a0(undefined8 *param_1,long param_2)

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


// ===== 001384c0 FUN_001384c0 =====

undefined8 FUN_001384c0(char *param_1,undefined8 *param_2)

{
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 != '\x01') && (*(long *)(param_1 + 0x20) == 0)) {
    *param_2 = param_1 + 0x74a00;
    return 0;
  }
  return 2;
}


// ===== 00138500 FUN_00138500 =====

undefined8 FUN_00138500(undefined8 param_1)

{
  DAT_01216a48 = param_1;
  return 0;
}


// ===== 00138510 FUN_00138510 =====

undefined8 FUN_00138510(char *param_1,undefined4 param_2,long param_3)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined4 local_c;
  
  local_c = 0;
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((uVar3 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (param_3 == 0) {
      return 2;
    }
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 == 0) || (*(long *)(lVar1 + 0x20) == 0)) ||
       (pcVar2 = *(code **)(*(long *)(lVar1 + 0x20) + 0xc0), pcVar2 == (code *)0x0)) {
      return 3;
    }
    uVar3 = (*pcVar2)(lVar1,param_1,param_2,&local_c,param_3);
  }
  return uVar3;
}


// ===== 001385a0 FUN_001385a0 =====

int FUN_001385a0(long param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  long *plVar6;
  int *piVar7;
  float fVar8;
  undefined8 uVar9;
  int local_43c0;
  int local_43bc;
  undefined1 local_43b8 [4];
  int local_43b4;
  int local_43b0 [64];
  int local_42b0 [32];
  long local_4230 [2113];
  
  lVar4 = *(long *)(param_1 + 0x256d8);
  if (((lVar4 == 0) || (*(long *)(lVar4 + 0x170) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(lVar4 + 0x170) + 0x28), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar4,param_1,2,&local_43c0,0,&local_43bc);
    if (iVar2 == 0) {
      lVar4 = *(long *)(param_1 + 0x256d8);
      if (((lVar4 == 0) || (*(long *)(lVar4 + 0x170) == 0)) ||
         (pcVar1 = *(code **)(*(long *)(lVar4 + 0x170) + 0x140), pcVar1 == (code *)0x0)) {
        iVar2 = 3;
      }
      else {
        iVar2 = (*pcVar1)(lVar4,param_1,local_43b8);
        if (iVar2 == 0) {
          if (local_43b4 != 0) {
            piVar7 = local_43b0;
            plVar6 = local_4230;
            iVar2 = 0;
            do {
              if (piVar7[0x40] != 0) {
                iVar3 = piVar7[0x40] + iVar2;
                lVar4 = 0;
                do {
                  if ((*piVar7 == local_43c0) && (*(int *)(*plVar6 + lVar4) == local_43bc)) {
                    *param_2 = iVar2;
                    return 0;
                  }
                  iVar2 = iVar2 + 1;
                  lVar4 = lVar4 + 4;
                } while (iVar3 != iVar2);
              }
              plVar6 = plVar6 + 1;
              piVar7 = piVar7 + 1;
            } while (plVar6 != local_4230 + (ulong)(local_43b4 - 1) + 1);
          }
          if (1 < DAT_01216a78) {
            fVar8 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            FUN_002340f0((double)(fVar8 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u\n"
                         ,"ERROR",lVar4,"api.c",0xd7f,local_43c0,local_43bc);
          }
          *param_2 = 0x20;
          return 0;
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar8 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      fVar8 = fVar8 * DAT_00298548;
      uVar9 = 0xd6c;
      uVar5 = 0xd6c;
      goto LAB_0013872d;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar8 = (float)FUN_002917b0(&DAT_01216a60);
  lVar4 = syscall(0xba);
  fVar8 = fVar8 * DAT_00298548;
  uVar9 = 0xd68;
  uVar5 = 0xd68;
LAB_0013872d:
  FUN_002340f0((double)fVar8,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,"api.c",
               uVar5,"deviceGetClockRemappedFakePerformanceState",uVar9,iVar2);
  return iVar2;
}


// ===== 00138870 FUN_00138870 =====

undefined8 FUN_00138870(int param_1,long *param_2,undefined8 param_3,long param_4)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  int *piVar6;
  undefined8 *puVar7;
  int *piVar8;
  int iVar9;
  byte bVar10;
  float fVar11;
  undefined8 local_448 [131];
  
  bVar10 = 0;
  if (param_1 == 0) {
    return 0;
  }
  plVar1 = param_2 + (ulong)(param_1 - 1) + 1;
  piVar8 = (int *)(param_4 + 0x410);
  do {
    piVar6 = piVar8 + -0x104;
    puVar7 = local_448;
    for (lVar5 = 0x82; lVar5 != 0; lVar5 = lVar5 + -1) {
      *puVar7 = *(undefined8 *)piVar6;
      piVar6 = piVar6 + ((ulong)bVar10 * -2 + 1) * 2;
      puVar7 = puVar7 + (ulong)bVar10 * -2 + 1;
    }
    lVar5 = *(long *)(*param_2 + 0x256d8);
    if (((lVar5 == 0) || (*(long *)(lVar5 + 0x158) == 0)) ||
       (pcVar2 = *(code **)(*(long *)(lVar5 + 0x158) + 0x78), pcVar2 == (code *)0x0)) {
      iVar3 = 3;
LAB_001388d9:
      iVar9 = iVar3;
      if (1 < DAT_01216a78) {
        uVar4 = nvmlErrorString(iVar9);
        fVar11 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n",
                     "ERROR",lVar5,"api.c",0x3507,uVar4);
      }
    }
    else {
      iVar3 = (*pcVar2)(lVar5,*param_2,local_448);
      iVar9 = 0;
      if (iVar3 != 0) goto LAB_001388d9;
    }
    param_2 = param_2 + 1;
    *piVar8 = iVar9;
    piVar8 = piVar8 + 0x106;
    if (param_2 == plVar1) {
      return 0;
    }
  } while( true );
}


// ===== 001389c0 FUN_001389c0 =====

undefined8 FUN_001389c0(void)

{
  DAT_01216a48 = 0;
  FUN_00233fd0();
  return 0;
}


// ===== 001389e0 FUN_001389e0 =====

undefined8 FUN_001389e0(void)

{
  FUN_002341a0("__NVML_DBG_LVL","__NVML_DBG_APPEND","__NVML_DBG_FILE",1);
  return 0;
}


// ===== 00138a10 FUN_00138a10 =====

uint FUN_00138a10(void)

{
  int iVar1;
  
  iVar1 = FUN_002340a0();
  return ~-(uint)(iVar1 == 0) & 999;
}


// ===== 00138a30 FUN_00138a30 =====

uint FUN_00138a30(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                 undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
                 undefined8 param_13,undefined8 param_14)

{
  char in_AL;
  int iVar1;
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
  iVar1 = FUN_002340a0(param_9,&local_d0);
  return ~-(uint)(iVar1 == 0) & 999;
}


// ===== 00138ad0 FUN_00138ad0 =====

undefined8 FUN_00138ad0(byte *param_1,char *param_2,uint param_3)

{
  size_t sVar1;
  undefined8 uVar2;
  
  if (param_2 != (char *)0x0) {
    sVar1 = strlen((char *)param_1);
    uVar2 = 7;
    if (sVar1 + 1 <= (ulong)param_3) {
      snprintf(param_2,(ulong)param_3,
               "%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x",
               (ulong)*param_1,(ulong)param_1[1],(ulong)param_1[2],(ulong)param_1[3],
               (ulong)param_1[4],(ulong)param_1[5],(ulong)param_1[6],(ulong)param_1[7],
               (ulong)param_1[8],(ulong)param_1[9],(ulong)param_1[10],(ulong)param_1[0xb],
               (ulong)param_1[0xc],(ulong)param_1[0xd],(ulong)param_1[0xe],(ulong)param_1[0xf]);
      uVar2 = 0;
    }
    return uVar2;
  }
  return 2;
}


// ===== 00138b90 FUN_00138b90 =====

undefined8 FUN_00138b90(long param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  undefined1 local_38 [16];
  undefined1 local_28 [16];
  
  local_38 = (undefined1  [16])0x0;
  local_28 = (undefined1  [16])0x0;
  if ((((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x28) != 0)) &&
      (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 200), pcVar1 != (code *)0x0)) &&
     ((iVar2 = (*pcVar1)(DAT_012164a0,DAT_012148b8,local_38,0), iVar2 == 0 &&
      (*(int *)(*(long *)(param_1 + 0x25d60) + 0x62c) == 1)))) {
    if (DAT_01216a78 < 4) {
      return 1;
    }
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar3,"api.c",0x136);
    return 1;
  }
  return 0;
}


// ===== 00138c80 FUN_00138c80 =====

int FUN_00138c80(long param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  undefined1 local_43c8 [17304];
  
  iVar3 = 4;
  iVar2 = FUN_00236dd0();
  if (iVar2 != 0) {
    lVar4 = *(long *)(param_1 + 0x256d8);
    if (((lVar4 == 0) || (*(long *)(lVar4 + 0x170) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(lVar4 + 0x170) + 0x140), pcVar1 == (code *)0x0)) {
      iVar3 = 3;
    }
    else {
      iVar3 = (*pcVar1)(lVar4,param_1,local_43c8);
      if (iVar3 == 0) {
        lVar4 = *(long *)(param_1 + 0x256d8);
        if (((lVar4 != 0) && (*(long *)(lVar4 + 0x170) != 0)) &&
           (pcVar1 = *(code **)(*(long *)(lVar4 + 0x170) + 0xd0), pcVar1 != (code *)0x0)) {
          iVar2 = (*pcVar1)(lVar4,param_1,param_2,param_3,local_43c8);
          return iVar2;
        }
        return 3;
      }
    }
    if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"api.c",0x1bd7,"tsapiDeviceSetMinClientClocks",0x1bd7,iVar3);
    }
  }
  return iVar3;
}


// ===== 00138de0 FUN_00138de0 =====

int FUN_00138de0(long param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  undefined1 local_43c8 [17304];
  
  iVar3 = 4;
  iVar2 = FUN_00236dd0();
  if (iVar2 != 0) {
    lVar4 = *(long *)(param_1 + 0x256d8);
    if (((lVar4 == 0) || (*(long *)(lVar4 + 0x170) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(lVar4 + 0x170) + 0x140), pcVar1 == (code *)0x0)) {
      iVar3 = 3;
    }
    else {
      iVar3 = (*pcVar1)(lVar4,param_1,local_43c8);
      if (iVar3 == 0) {
        lVar4 = *(long *)(param_1 + 0x256d8);
        if (((lVar4 != 0) && (*(long *)(lVar4 + 0x170) != 0)) &&
           (pcVar1 = *(code **)(*(long *)(lVar4 + 0x170) + 0xd8), pcVar1 != (code *)0x0)) {
          iVar2 = (*pcVar1)(lVar4,param_1,param_2,param_3,local_43c8);
          return iVar2;
        }
        return 3;
      }
    }
    if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"api.c",0x1bf9,"tsapiDeviceSetMaxClientClocks",0x1bf9,iVar3);
    }
  }
  return iVar3;
}


// ===== 00138f40 FUN_00138f40 =====

int FUN_00138f40(undefined4 param_1,undefined8 *param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  uint uVar6;
  
  if (DAT_01214898 == 0) {
    iVar3 = 2;
  }
  else {
    pcVar5 = &DAT_00380898;
    iVar3 = 2;
    uVar6 = 0;
    do {
      if (((*pcVar5 == '\x01') ||
          (((((&DAT_003808ac)[(ulong)uVar6 * 0x1d280] != 0 && (*(int *)(pcVar5 + 0x1c) == 0)) &&
            (*(int *)(pcVar5 + 0x10) != 0)) && (*(long *)(pcVar5 + 0x20) != 0)))) &&
         ((char *)*param_2 == pcVar5)) {
        if (*(int *)(param_2 + 0x62) == 0) {
          do {
            iVar3 = FUN_00291820((long)param_2 + 0x314,1,0);
          } while (iVar3 != 0);
          if (*(int *)(param_2 + 0x62) == 0) {
            lVar1 = *(long *)(pcVar5 + 0x256d8);
            uVar4 = 3;
            if (((lVar1 != 0) && (*(long *)(lVar1 + 0x28) != 0)) &&
               (pcVar2 = *(code **)(*(long *)(lVar1 + 0x28) + 0x50), pcVar2 != (code *)0x0)) {
              uVar4 = (*pcVar2)(lVar1,pcVar5,param_1,param_2 + 2);
            }
            *(undefined4 *)(param_2 + 99) = uVar4;
            *(undefined4 *)(param_2 + 0x62) = 1;
          }
          FUN_00291830((long)param_2 + 0x314,0);
          iVar3 = *(int *)(param_2 + 99);
        }
        else {
          iVar3 = *(int *)(param_2 + 99);
        }
        if (iVar3 == 0) {
          return 0;
        }
        *(undefined4 *)(param_2 + 0x62) = 0;
      }
      uVar6 = uVar6 + 1;
      pcVar5 = pcVar5 + 0x74a00;
    } while (uVar6 < DAT_01214898);
  }
  return iVar3;
}


// ===== 001390b0 FUN_001390b0 =====

undefined8 FUN_001390b0(int param_1,undefined8 *param_2)

{
  long lVar1;
  undefined8 *puVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  char *pcVar7;
  uint uVar8;
  ulong uVar9;
  
  if (DAT_01214898 != 0) {
    pcVar7 = &DAT_00380898;
    uVar9 = 0;
    do {
      if (((*pcVar7 == '\x01') ||
          (((((&DAT_003808ac)[uVar9 * 0x1d280] != 0 && (*(int *)(pcVar7 + 0x1c) == 0)) &&
            (*(int *)(pcVar7 + 0x10) != 0)) && (*(long *)(pcVar7 + 0x20) != 0)))) &&
         ((lVar1 = *(long *)(pcVar7 + 0x25d60), lVar1 != 0 &&
          (*(undefined8 **)(lVar1 + 0x618) != (undefined8 *)(lVar1 + 0x618))))) {
        iVar5 = FUN_00138b90(pcVar7);
        if ((iVar5 == 0) && (*(int *)(lVar1 + 0x628) == 0)) {
          lVar3 = *(long *)(pcVar7 + 0x256d8);
          if (((lVar3 == 0) || (*(long *)(lVar3 + 0x28) == 0)) ||
             (pcVar4 = *(code **)(*(long *)(lVar3 + 0x28) + 0x48), pcVar4 == (code *)0x0)) {
            return 3;
          }
          uVar6 = (*pcVar4)(lVar3,pcVar7);
          if ((int)uVar6 != 0) {
            return uVar6;
          }
        }
        for (puVar2 = *(undefined8 **)(lVar1 + 0x618); (undefined8 *)(lVar1 + 0x618) != puVar2;
            puVar2 = (undefined8 *)*puVar2) {
          if (*(int *)(puVar2 + -0x43) == param_1) {
            *param_2 = puVar2 + -0x43;
            return 0;
          }
        }
      }
      uVar8 = (int)uVar9 + 1;
      uVar9 = (ulong)uVar8;
      pcVar7 = pcVar7 + 0x74a00;
    } while (uVar8 < DAT_01214898);
  }
  return 6;
}


// ===== 00139230 FUN_00139230 =====

int FUN_00139230(char *param_1,uint *param_2,uint param_3)

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
    if (param_2 == (uint *)0x0) {
      iVar2 = 2;
    }
    else {
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
                       "/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h",0x42,
                       param_3);
        }
      }
      else {
        if (1 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tFailure to determine Architecture\n",
                       "ERROR",lVar4,
                       "/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h",0x46);
        }
        *param_2 = 0;
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}


// ===== 001394e0 FUN_001394e0 =====

undefined8 FUN_001394e0(void)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  ulong uVar4;
  int local_30;
  int local_2c;
  
  local_30 = 0;
  local_2c = 0;
  if (DAT_01214898 != 0) {
    pcVar2 = &DAT_00380898;
    uVar4 = 0;
    do {
      if ((*pcVar2 == '\x01') ||
         (((((&DAT_003808ac)[uVar4 * 0x1d280] != 0 && (*(int *)(pcVar2 + 0x1c) == 0)) &&
           (*(int *)(pcVar2 + 0x10) != 0)) && (*(long *)(pcVar2 + 0x20) != 0)))) {
        iVar1 = FUN_00139230(pcVar2,&local_30,0xc);
        if ((iVar1 != 0) || (local_30 == 0)) {
          return 3;
        }
        iVar1 = FUN_00139230(pcVar2,&local_2c,0xd);
        if (iVar1 != 0) {
          return 3;
        }
        if (local_2c == 1) {
          return 3;
        }
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulong)uVar3;
      pcVar2 = pcVar2 + 0x74a00;
    } while (uVar3 < DAT_01214898);
  }
  return 0;
}


// ===== 001395d0 FUN_001395d0 =====

undefined8 FUN_001395d0(char *param_1,undefined4 param_2)

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
             (pcVar2 = *(code **)(*(long *)(lVar1 + 0x170) + 0x230), pcVar2 != (code *)0x0)))) {
        uVar4 = (*pcVar2)(lVar1,param_1,param_2);
      }
    }
    return uVar4;
  }
  return 2;
}


// ===== 00139690 FUN_00139690 =====

int FUN_00139690(char *param_1,undefined4 *param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  float fVar6;
  int local_2c [3];
  
  iVar3 = 2;
  local_2c[0] = 0;
  if (((param_1 != (char *)0x0) &&
      ((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) &&
     (iVar3 = FUN_00139230(param_1,local_2c,6), iVar3 == 0)) {
    if (local_2c[0] != 0) {
      if (4 < DAT_01216a78) {
        fVar6 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                     lVar5,"/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h",0x77);
      }
LAB_001397e0:
      *param_2 = 1;
      return 0;
    }
    if (*(int *)(param_1 + 0x71c) == 0) {
      do {
        iVar3 = FUN_00291820(param_1 + 0x720,1,0);
      } while (iVar3 != 0);
      if (*(int *)(param_1 + 0x71c) == 0) {
        lVar5 = *(long *)(param_1 + 0x256d8);
        uVar4 = 3;
        if (((lVar5 != 0) && (*(long *)(lVar5 + 0x20) != 0)) &&
           (pcVar2 = *(code **)(*(long *)(lVar5 + 0x20) + 0x98), pcVar2 != (code *)0x0)) {
          uVar4 = (*pcVar2)(lVar5,param_1,param_1 + 0x708);
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
      iVar1 = *(int *)(param_1 + 0x70c);
      if ((iVar1 - 0xf0U & 0xffffffef) == 0) goto LAB_001397e0;
      if ((iVar1 != 0xe0) && (1 < DAT_01216a78)) {
        fVar6 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n",
                     "ERROR",lVar5,"/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h"
                     ,0x8f,iVar1);
      }
    }
    else {
      if (iVar3 == 0xf) {
        return 0xf;
      }
      if (1 < DAT_01216a78) {
        fVar6 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",
                     "ERROR",lVar5,"/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h"
                     ,0x9a,iVar3);
      }
    }
    *param_2 = 0;
  }
  return iVar3;
}


// ===== 00139950 FUN_00139950 =====

undefined8 FUN_00139950(char *param_1,long param_2)

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
    if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0x80) != (undefined8 *)0x0)) &&
       (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar1 + 0x80),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001399a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 001399d0 nvmlDeviceGetComputeMode =====

int nvmlDeviceGetComputeMode(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x11,"nvmlDeviceGetComputeMode",
                 "(nvmlDevice_t device, nvmlComputeMode_t *mode)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00139950(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x11,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x11,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00139bb0 FUN_00139bb0 =====

undefined8 FUN_00139bb0(char *param_1,int param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined8 uVar3;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 != '\x01') &&
     ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
       (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) {
    return 2;
  }
  if (param_2 != 1) {
    iVar2 = FUN_00236dd0();
    if (iVar2 == 0) {
      return 4;
    }
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x80) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x80) + 8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00139c24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar3;
    }
  }
  return 3;
}


// ===== 00139c70 nvmlDeviceSetComputeMode =====

int nvmlDeviceSetComputeMode(undefined8 param_1,undefined4 param_2)

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
                 "entry_points.h",0x15,"nvmlDeviceSetComputeMode",
                 "(nvmlDevice_t device, nvmlComputeMode_t mode)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00139bb0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x15,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x15,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00139e50 FUN_00139e50 =====

int FUN_00139e50(char *param_1,int *param_2,undefined4 *param_3)

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
    if (param_3 == (undefined4 *)0x0) {
      return 2;
    }
    if (param_2 == (int *)0x0) {
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
      if (*(int *)(param_1 + 0x714) == -1) {
        iVar2 = 3;
      }
      else {
        *param_2 = *(int *)(param_1 + 0x714);
        *param_3 = *(undefined4 *)(param_1 + 0x718);
      }
    }
    else if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"api.c",0x457,"tsapiDeviceGetCudaComputeCapability",0x457,iVar2);
    }
  }
  return iVar2;
}


// ===== 0013a040 nvmlDeviceGetCudaComputeCapability =====

int nvmlDeviceGetCudaComputeCapability(undefined8 param_1,undefined8 param_2,undefined8 param_3)

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
                 "entry_points.h",0x19,"nvmlDeviceGetCudaComputeCapability",
                 "(nvmlDevice_t device, int *major, int *minor)",param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00139e50(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x19,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x19,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0013a210 FUN_0013a210 =====

undefined4
FUN_0013a210(long param_1,undefined4 *param_2,long param_3,long param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_39 [9];
  
  if (param_1 != 0) {
    if (((param_2 == (undefined4 *)0x0) || (param_3 == 0 || param_4 == 0)) ||
       (param_5 == (undefined4 *)0x0)) {
      uVar2 = 2;
    }
    else {
      iVar1 = __isoc99_sscanf(param_1,&DAT_0029bc2e,param_2,param_3,param_4,param_5,local_39);
      uVar2 = 0;
      if (iVar1 != 4) {
        iVar1 = __isoc99_sscanf(param_1,"%x:%x:%x%c",param_2,param_3,param_4,local_39);
        uVar2 = 0;
        if (iVar1 == 3) {
          *param_5 = 0;
        }
        else {
          iVar1 = __isoc99_sscanf(param_1,"%x:%x.%x%c",param_3,param_4,param_5,local_39);
          uVar2 = 2;
          if (iVar1 == 3) {
            *param_2 = 0;
            uVar2 = 0;
          }
        }
      }
    }
    return uVar2;
  }
  return 2;
}


// ===== 0013a340 FUN_0013a340 =====

int FUN_0013a340(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
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
                 "entry_points.h",0x7c5,param_1,param_2,param_3,param_4,param_5);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013a210(param_1,param_2,param_3,param_4,param_5);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x7c5,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0013a4a0 FUN_0013a4a0 =====

int FUN_0013a4a0(long param_1,undefined8 *param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  undefined2 local_38 [2];
  undefined4 local_34;
  undefined2 local_30 [2];
  int local_2c [3];
  
  if ((param_1 == 0) || (param_2 == (undefined8 *)0x0)) {
    return 2;
  }
  iVar2 = FUN_0013a210(param_1,&local_34,local_38,local_30,local_2c);
  if ((iVar2 == 0) && (iVar2 = 2, local_2c[0] == 0)) {
    if ((DAT_012164a0 == 0) ||
       ((*(long *)(DAT_012164a0 + 0x20) == 0 ||
        (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0x10), pcVar1 == (code *)0x0)))) {
      iVar2 = 3;
    }
    else {
      iVar2 = (*pcVar1)(DAT_012164a0,local_34,local_38[0],local_30[0],param_2);
      if (iVar2 == 0) {
        if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x20) == 0)) ||
           (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0xb8), pcVar1 == (code *)0x0)) {
          return 3;
        }
        iVar2 = (*pcVar1)(DAT_012164a0,*param_2);
        if (iVar2 != 9) {
          return iVar2;
        }
        if (DAT_01216a78 < 5) {
          return 999;
        }
        fVar4 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                     lVar3,"api.c",0x5ce);
        return 999;
      }
    }
    if (1 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar3,"api.c",0x5c9,"tsapiDeviceGetHandleByPciBusId_v2",0x5c9,iVar2);
    }
  }
  return iVar2;
}


// ===== 0013a6b0 nvmlDeviceGetHandleByPciBusId_v2 =====

int nvmlDeviceGetHandleByPciBusId_v2(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x45,"nvmlDeviceGetHandleByPciBusId_v2",
                 "(const char *pciBusId, nvmlDevice_t *device)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013a4a0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x45,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x45,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0013a890 FUN_0013a890 =====

int FUN_0013a890(void)

{
  int iVar1;
  
  iVar1 = FUN_0013a4a0();
  if (iVar1 == 4) {
    iVar1 = 6;
  }
  return iVar1;
}


// ===== 0013a8b0 nvmlDeviceGetHandleByPciBusId =====

int nvmlDeviceGetHandleByPciBusId(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x41,"nvmlDeviceGetHandleByPciBusId",
                 "(const char *pciBusId, nvmlDevice_t *device)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013a890(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x41,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x41,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0013aa90 FUN_0013aa90 =====

undefined8 FUN_0013aa90(char *param_1,long param_2,undefined4 param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_2 == 0) || (param_1 == (char *)0x0)) {
    return 2;
  }
  if (*param_1 != '\x01') {
    if (*(long *)(param_1 + 0x20) == 0) {
      uVar2 = FUN_001356a0();
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
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0x38) != (undefined8 *)0x0)) &&
     (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar1 + 0x38),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0013aae3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
    return uVar2;
  }
  return 3;
}


// ===== 0013ab10 nvmlDeviceGetName =====

int nvmlDeviceGetName(undefined8 param_1,undefined8 param_2,undefined4 param_3)

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
                 "entry_points.h",0xab5,"nvmlDeviceGetName",
                 "(nvmlDevice_t device, char* name, unsigned int length)",param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013aa90(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xab5,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xab5,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0013ace0 FUN_0013ace0 =====

void FUN_0013ace0(uint param_1,char *param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x10);
  if (uVar1 >> 0x1c != 0) {
    uVar1 = uVar1 & 0xfffffff;
  }
  snprintf(param_2,0x10,"%04X:%02X:%02X.0",(ulong)uVar1,(ulong)*(uint *)(param_2 + 0x14),
           (ulong)*(uint *)(param_2 + 0x18));
  if (param_1 < 3) {
    return;
  }
  snprintf(param_2 + 0x24,0x20,"%08X:%02X:%02X.0",(ulong)*(uint *)(param_2 + 0x10),
           (ulong)*(uint *)(param_2 + 0x14),(ulong)*(uint *)(param_2 + 0x18));
  return;
}


// ===== 0013ad60 FUN_0013ad60 =====

int FUN_0013ad60(char *param_1,void *param_2,ulong param_3)

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
      if (*(int *)(param_1 + 0x1bc) == 0) {
        do {
          iVar2 = FUN_00291820(param_1 + 0x1c0,1,0);
        } while (iVar2 != 0);
        if (*(int *)(param_1 + 0x1bc) == 0) {
          lVar5 = *(long *)(param_1 + 0x256d8);
          uVar3 = 3;
          if (((lVar5 != 0) && (*(long *)(lVar5 + 0x38) != 0)) &&
             (pcVar1 = *(code **)(*(long *)(lVar5 + 0x38) + 0x10), pcVar1 != (code *)0x0)) {
            uVar3 = (*pcVar1)(lVar5,param_1,param_1 + 0x13c,0x80);
          }
          *(undefined4 *)(param_1 + 0x1c4) = uVar3;
          param_1[0x1bc] = '\x01';
          param_1[0x1bd] = '\0';
          param_1[0x1be] = '\0';
          param_1[0x1bf] = '\0';
        }
        FUN_00291830(param_1 + 0x1c0,0);
      }
      iVar2 = *(int *)(param_1 + 0x1c4);
      if (iVar2 == 0) {
        sVar4 = strlen(param_1 + 0x13c);
        if (sVar4 + 1 <= (param_3 & 0xffffffff)) {
          memcpy(param_2,param_1 + 0x13c,sVar4 + 1);
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
                   "ERROR",lVar5,"api.c",0x96f,"tsapiDeviceGetBoardPartNumber",0x96f,iVar2);
      return iVar2;
    }
  }
  return 2;
}


// ===== 0013af40 nvmlDeviceGetBoardPartNumber =====

int nvmlDeviceGetBoardPartNumber(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %p %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x8d,"nvmlDeviceGetBoardPartNumber",
                 "(nvmlDevice_t device, char * partNumber, unsigned int length)",param_1,param_2,
                 param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013ad60(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x8d,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x8d,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0013b110 FUN_0013b110 =====

int FUN_0013b110(char *param_1,void *param_2,ulong param_3)

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
      if (*(int *)(param_1 + 0x248) == 0) {
        do {
          iVar2 = FUN_00291820(param_1 + 0x24c,1,0);
        } while (iVar2 != 0);
        if (*(int *)(param_1 + 0x248) == 0) {
          lVar5 = *(long *)(param_1 + 0x256d8);
          uVar3 = 3;
          if (((lVar5 != 0) && (*(long *)(lVar5 + 0x38) != 0)) &&
             (pcVar1 = *(code **)(*(long *)(lVar5 + 0x38) + 0x18), pcVar1 != (code *)0x0)) {
            uVar3 = (*pcVar1)(lVar5,param_1,param_1 + 0x1c8,0x80);
          }
          *(undefined4 *)(param_1 + 0x250) = uVar3;
          param_1[0x248] = '\x01';
          param_1[0x249] = '\0';
          param_1[0x24a] = '\0';
          param_1[0x24b] = '\0';
        }
        FUN_00291830(param_1 + 0x24c,0);
      }
      iVar2 = *(int *)(param_1 + 0x250);
      if (iVar2 == 0) {
        sVar4 = strlen(param_1 + 0x1c8);
        if (sVar4 + 1 <= (param_3 & 0xffffffff)) {
          memcpy(param_2,param_1 + 0x1c8,sVar4 + 1);
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
                   "ERROR",lVar5,"api.c",0x98a,"tsapiDeviceGetGpuPartNumber",0x98a,iVar2);
      return iVar2;
    }
  }
  return 2;
}


// ===== 0013b2f0 FUN_0013b2f0 =====

int FUN_0013b2f0(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p %d)\n",
                 "DEBUG",lVar3,"entry_points.h",0x92a,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013b110(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x92a,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0013b430 FUN_0013b430 =====

int FUN_0013b430(undefined8 param_1,int *param_2)

{
  int iVar1;
  long lVar2;
  float fVar3;
  long local_20;
  
  local_20 = 0;
  if (param_2 == (int *)0x0) {
    return 2;
  }
  iVar1 = 0x19;
  if (*param_2 == 0x1000008) {
    if ((int)param_1 == 0) {
      iVar1 = 2;
    }
    else {
      iVar1 = FUN_001390b0(param_1,&local_20);
      if (iVar1 == 0) {
        param_2[1] = *(int *)(local_20 + 0x210);
        return 0;
      }
    }
    if (1 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar2,"api.c",0x9eb,"tsapiVgpuInstanceGetPlacementId",0x9eb,iVar1);
      return iVar1;
    }
  }
  return iVar1;
}


// ===== 0013b530 nvmlVgpuInstanceGetPlacementId =====

int nvmlVgpuInstanceGetPlacementId(undefined4 param_1,undefined8 param_2)

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
                 "entry_points.h",0xae8,"nvmlVgpuInstanceGetPlacementId",
                 "(nvmlVgpuInstance_t vgpuInstance, nvmlVgpuPlacementId_t *pPlacement)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013b430(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xae8,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xae8,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0013b710 FUN_0013b710 =====

int FUN_0013b710(int param_1,undefined8 *param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  long local_30 [2];
  
  local_30[0] = 0;
  if ((param_1 == 0) || (param_2 == (undefined8 *)0x0)) {
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
        *param_2 = *(undefined8 *)(local_30[0] + 0x2f0);
        return 0;
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0xa29;
      uVar4 = 0xa29;
      goto LAB_0013b807;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  fVar5 = fVar5 * DAT_00298548;
  uVar6 = 0xa27;
  uVar4 = 0xa27;
LAB_0013b807:
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,"api.c",
               uVar4,"tsapiVgpuTypeGetGspHeapSize",uVar6,iVar2);
  return iVar2;
}


// ===== 0013b8c0 nvmlVgpuTypeGetGspHeapSize =====

int nvmlVgpuTypeGetGspHeapSize(undefined4 param_1,undefined8 param_2)

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
                 "entry_points.h",0x368,"nvmlVgpuTypeGetGspHeapSize",
                 "(nvmlVgpuTypeId_t vgpuTypeId, unsigned long long *gspHeapSize)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013b710(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x368,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x368,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0013baa0 FUN_0013baa0 =====

int FUN_0013baa0(int param_1,undefined8 *param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  undefined8 uVar6;
  long local_30 [2];
  
  local_30[0] = 0;
  if ((param_1 == 0) || (param_2 == (undefined8 *)0x0)) {
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
        *param_2 = *(undefined8 *)(local_30[0] + 0x2f8);
        return 0;
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      fVar5 = fVar5 * DAT_00298548;
      uVar6 = 0xa3e;
      uVar4 = 0xa3e;
      goto LAB_0013bb97;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  fVar5 = fVar5 * DAT_00298548;
  uVar6 = 0xa3c;
  uVar4 = 0xa3c;
LAB_0013bb97:
  FUN_002340f0((double)fVar5,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,"api.c",
               uVar4,"tsapiVgpuTypeGetFbReservation",uVar6,iVar2);
  return iVar2;
}


// ===== 0013bc50 nvmlVgpuTypeGetFbReservation =====

int nvmlVgpuTypeGetFbReservation(undefined4 param_1,undefined8 param_2)

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
                 "entry_points.h",0x36d,"nvmlVgpuTypeGetFbReservation",
                 "(nvmlVgpuTypeId_t vgpuTypeId, unsigned long long *fbReservation)",param_1,param_2)
    ;
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013baa0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x36d,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x36d,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0013be30 FUN_0013be30 =====

int FUN_0013be30(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  float fVar5;
  double dVar6;
  undefined8 uVar7;
  undefined8 local_28;
  long local_20;
  
  local_28 = 0;
  local_20 = 0;
  if ((int)param_1 == 0) {
    iVar2 = 2;
  }
  else {
    iVar2 = FUN_001390b0(param_1,&local_20);
    if (iVar2 == 0) {
      if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x28) == 0)) ||
         (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0xb8), pcVar1 == (code *)0x0)) {
        iVar2 = 3;
      }
      else {
        iVar2 = (*pcVar1)(DAT_012164a0,*(undefined4 *)(local_20 + 4),&local_28);
        if (iVar2 == 0) {
          if (*(int *)(local_20 + 4) == 0) {
            iVar2 = 2;
          }
          else {
            iVar2 = FUN_00138f40(*(int *)(local_20 + 4),local_28);
            if (iVar2 == 0) {
              lVar3 = *(long *)(*(long *)(local_20 + 0x1e0) + 0x256d8);
              if (((lVar3 != 0) && (*(long *)(lVar3 + 0x28) != 0)) &&
                 (pcVar1 = *(code **)(*(long *)(lVar3 + 0x28) + 0xf0), pcVar1 != (code *)0x0)) {
                iVar2 = (*pcVar1)(lVar3,*(long *)(local_20 + 0x1e0),local_28,param_2);
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
          uVar7 = 0xa4f;
          uVar4 = 0xa4f;
          dVar6 = (double)(fVar5 * DAT_00298548);
          goto LAB_0013bf85;
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar2;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      uVar7 = 0xa4e;
      uVar4 = 0xa4e;
      dVar6 = (double)(fVar5 * DAT_00298548);
      goto LAB_0013bf85;
    }
  }
  if (DAT_01216a78 < 2) {
    return iVar2;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  uVar7 = 0xa4d;
  uVar4 = 0xa4d;
  dVar6 = (double)(fVar5 * DAT_00298548);
LAB_0013bf85:
  FUN_002340f0(dVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,"api.c",uVar4,
               "tsapiVgpuInstanceGetRuntimeStateSize",uVar7,iVar2);
  return iVar2;
}


// ===== 0013c0b0 nvmlVgpuInstanceGetRuntimeStateSize =====

int nvmlVgpuInstanceGetRuntimeStateSize(undefined4 param_1,undefined8 param_2)

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
                 "entry_points.h",0x372,"nvmlVgpuInstanceGetRuntimeStateSize",
                 "(nvmlVgpuInstance_t vgpuInstance, nvmlVgpuRuntimeState_t *pRuntimeState)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013be30(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x372,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x372,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0013c290 FUN_0013c290 =====

int FUN_0013c290(long param_1,char *param_2,uint param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  
  if ((param_2 == (char *)0x0) || (0x80 < param_3)) {
    return 2;
  }
  if (*(int *)(param_1 + 0x130) == 0) {
    do {
      iVar3 = FUN_00291820(param_1 + 0x134,1,0);
    } while (iVar3 != 0);
    if (*(int *)(param_1 + 0x130) == 0) {
      lVar1 = *(long *)(param_1 + 0x256d8);
      uVar4 = 3;
      if (((lVar1 != 0) && (*(long *)(lVar1 + 0x38) != 0)) &&
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x38) + 0x28), pcVar2 != (code *)0x0)) {
        uVar4 = (*pcVar2)(lVar1,param_1,param_1 + 0xb0,0x80);
      }
      *(undefined4 *)(param_1 + 0x138) = uVar4;
      *(undefined4 *)(param_1 + 0x130) = 1;
    }
    FUN_00291830(param_1 + 0x134,0);
  }
  if (*(int *)(param_1 + 0x138) != 0) {
    return *(int *)(param_1 + 0x138);
  }
  strcpy(param_2,(char *)(param_1 + 0xb0));
  return 0;
}


// ===== 0013c3a0 FUN_0013c3a0 =====

int FUN_0013c3a0(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p %d)\n",
                 "DEBUG",lVar3,"entry_points.h",0x963,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013c290(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x963,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0013c4e0 thunk_FUN_001302d0 =====

ulong thunk_FUN_001302d0(undefined4 param_1,uint *param_2,long param_3)

{
  long *plVar1;
  ushort *puVar2;
  undefined8 uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  float fVar11;
  uint uStack_cc;
  undefined1 auStack_c0 [8];
  char acStack_b8 [136];
  
  iVar4 = FUN_001335a0();
  if (iVar4 != 0) {
    if (1 < DAT_01216a78) {
      uVar5 = FUN_001335a0();
      fVar11 = (float)FUN_002917b0(&DAT_01216a60);
      lVar8 = syscall(0xba);
      FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar8,"common/nvhwloc.c",0x69,"nvhwlocSystemGetTopologyGpuSet",0x69,uVar5
                  );
      return 3;
    }
    return 3;
  }
  if (*param_2 == 0) {
    if (param_3 != 0) {
      return 2;
    }
    uVar7 = FUN_00260eab();
    FUN_0026197d(uVar7,param_1);
    uVar3 = DAT_01216968;
    iVar4 = FUN_00257fb0(DAT_01216968,0xf);
    if ((iVar4 + 2U < 2) || (lVar8 = FUN_002580d2(uVar3,iVar4,0), lVar8 == 0)) {
      FUN_00260f71(uVar7);
      uStack_cc = 0;
      goto LAB_001303fd;
    }
    uVar10 = 1;
  }
  else {
    if (param_3 == 0) {
      return 2;
    }
    uVar7 = FUN_00260eab();
    FUN_0026197d(uVar7,param_1);
    uVar3 = DAT_01216968;
    iVar4 = FUN_00257fb0(DAT_01216968,0xf);
    if ((iVar4 + 2U < 2) || (lVar8 = FUN_002580d2(uVar3,iVar4,0), lVar8 == 0)) {
      FUN_00260f71(uVar7);
      return 0;
    }
    uVar10 = 0;
  }
  uStack_cc = 0;
  do {
    puVar2 = *(ushort **)(lVar8 + 0x28);
    if ((((char)puVar2[2] == '\0') &&
        (sprintf(acStack_b8,"%04x:%02x:%02x.%x",(ulong)*puVar2,(ulong)(byte)puVar2[1],
                 (ulong)*(byte *)((long)puVar2 + 3),0),
        *(short *)(*(long *)(lVar8 + 0x28) + 8) == 0x10de)) &&
       (iVar4 = FUN_0013a4a0(acStack_b8,auStack_c0), lVar9 = lVar8, iVar4 != 6)) {
      while (*(long *)(lVar9 + 0xb8) == 0) {
        plVar1 = (long *)(lVar9 + 0x48);
        lVar9 = *plVar1;
        if (*plVar1 == 0) {
          uVar10 = FUN_0011fcd8();
          return uVar10;
        }
      }
      iVar4 = FUN_002623d5(uVar7);
      if (iVar4 != 0) {
        if (((int)uVar10 == 0) &&
           (uVar6 = FUN_0013a4a0(acStack_b8,param_3 + (ulong)uStack_cc * 8), uVar6 != 0)) {
          FUN_00260f71(uVar7);
          return (ulong)uVar6;
        }
        uStack_cc = uStack_cc + 1;
      }
    }
    iVar4 = FUN_00257fb0(DAT_01216968,0xf);
  } while (((1 < iVar4 + 2U) && (iVar4 == *(int *)(lVar8 + 0x30))) &&
          (lVar8 = *(long *)(lVar8 + 0x38), lVar8 != 0));
  FUN_00260f71(uVar7);
  if ((int)uVar10 == 0) {
    return uVar10;
  }
LAB_001303fd:
  *param_2 = uStack_cc;
  return 0;
}


// ===== 0013c4f0 nvmlSystemGetTopologyGpuSet =====

int nvmlSystemGetTopologyGpuSet(undefined4 param_1,undefined8 param_2,undefined8 param_3)

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
                 "entry_points.h",0x2c8,"nvmlSystemGetTopologyGpuSet",
                 "(unsigned int cpuNumber, unsigned int *count, nvmlDevice_t *deviceArray)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_001302d0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2c8,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2c8,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0013c6c0 thunk_FUN_001305f0 =====

ulong thunk_FUN_001305f0(long param_1,uint param_2,uint *param_3,long param_4)

{
  ushort *puVar1;
  code *pcVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  undefined8 uVar13;
  uint uVar14;
  uint uVar15;
  float fVar16;
  double dVar17;
  undefined8 uVar18;
  uint uStack_ec;
  uint uStack_e8;
  uint uStack_e4;
  undefined8 uStack_e0;
  undefined1 auStack_d8 [16];
  uint uStack_c8;
  uint uStack_c4;
  uint uStack_c0;
  undefined1 auStack_88 [16];
  uint uStack_78;
  uint uStack_74;
  uint uStack_70;
  
  if ((param_1 == 0) || (param_3 == (uint *)0x0)) {
LAB_001308a0:
    uStack_ec = 2;
  }
  else {
    if (*param_3 == 0) {
      if (param_4 != 0) goto LAB_001308a0;
      bVar3 = true;
    }
    else {
      if (param_4 == 0) goto LAB_001308a0;
      bVar3 = false;
    }
    uVar7 = FUN_001904e0(&uStack_e4);
    uStack_ec = uVar7;
    if (uVar7 == 0) {
      uVar14 = 0;
      if (uStack_e4 != 0) {
        uVar14 = 0;
        uVar15 = 0;
LAB_00130688:
        do {
          if (*(uint *)(param_1 + 4) == uVar15) goto LAB_00130747;
          uStack_ec = FUN_00190770(uVar15,&uStack_e0);
          if (uStack_ec != 0) {
            if (DAT_01216a78 < 2) goto LAB_00130762;
            fVar16 = (float)FUN_002917b0(&DAT_01216a60);
            lVar10 = syscall(0xba);
            uVar18 = 0xd1;
            uVar13 = 0xd1;
            dVar17 = (double)(fVar16 * DAT_00298548);
            goto LAB_001309e0;
          }
          uStack_ec = thunk_FUN_00131ff0(param_1,uStack_e0,&uStack_e8);
          uVar13 = uStack_e0;
          uVar4 = uStack_e8;
          if (uStack_ec != 0) {
            if (DAT_01216a78 < 2) goto LAB_00130762;
            fVar16 = (float)FUN_002917b0(&DAT_01216a60);
            lVar10 = syscall(0xba);
            uVar18 = 0xd2;
            uVar13 = 0xd2;
            dVar17 = (double)(fVar16 * DAT_00298548);
            goto LAB_001309e0;
          }
          iVar8 = FUN_001335a0();
          if (iVar8 != 0) {
            if (DAT_01216a78 < 2) {
              uStack_ec = 3;
              goto LAB_00130762;
            }
            uVar9 = FUN_001335a0();
            fVar16 = (float)FUN_002917b0(&DAT_01216a60);
            lVar10 = syscall(0xba);
            FUN_002340f0((double)(fVar16 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar10,
                         "common/nvhwloc.c",0x1b,"compareLevels",0x1b,uVar9);
            uStack_ec = 3;
LAB_001307ba:
            if (DAT_01216a78 < 2) goto LAB_00130762;
            fVar16 = (float)FUN_002917b0(&DAT_01216a60);
            lVar10 = syscall(0xba);
            uVar13 = 0xd3;
            uVar18 = 0xd3;
            dVar17 = (double)(fVar16 * DAT_00298548);
            goto LAB_001309e0;
          }
          if (uVar4 == 0x1e) {
            if (0x1d < param_2) goto LAB_00130718;
            uVar15 = uVar15 + 1;
            if (uStack_e4 <= uVar15) break;
            goto LAB_00130688;
          }
          if (0x1e < uVar4) {
            if (uVar4 != 0x28) {
              if (uVar4 != 0x32) {
LAB_001307a9:
                uStack_ec = 999;
                goto LAB_001307ba;
              }
              goto LAB_00130718;
            }
            if (param_2 == 0x32) goto LAB_00130718;
            if (param_2 == 0x28) {
              uStack_ec = FUN_0013ef00(param_1,auStack_d8);
              if (uStack_ec == 0) {
                uStack_ec = FUN_0013ef00(uVar13,auStack_88);
                uVar6 = uStack_c0;
                uVar5 = uStack_c4;
                uVar4 = uStack_c8;
                uVar13 = DAT_01216968;
                if (uStack_ec == 0) {
                  lVar10 = 0;
                  while( true ) {
                    iVar8 = FUN_00257fb0(uVar13,0xf);
                    if (iVar8 + 2U < 2) break;
                    if (lVar10 == 0) {
                      lVar10 = FUN_002580d2(uVar13,iVar8,0);
                    }
                    else {
                      if (iVar8 != *(int *)(lVar10 + 0x30)) break;
                      lVar10 = *(long *)(lVar10 + 0x38);
                    }
                    if ((lVar10 == 0) ||
                       ((((puVar1 = *(ushort **)(lVar10 + 0x28), uVar4 == *puVar1 &&
                          (uVar5 == (byte)puVar1[1])) && (uVar6 == *(byte *)((long)puVar1 + 3))) &&
                        ((char)puVar1[2] == '\0')))) goto LAB_00130c40;
                  }
                  lVar10 = 0;
LAB_00130c40:
                  uVar6 = uStack_70;
                  uVar5 = uStack_74;
                  uVar4 = uStack_78;
                  uVar13 = DAT_01216968;
                  lVar11 = 0;
                  do {
                    iVar8 = FUN_00257fb0(uVar13,0xf);
                    if (iVar8 + 2U < 2) {
LAB_00130d50:
                      if (lVar10 == 0) {
                        uVar12 = FUN_0011fce2();
                        return uVar12;
                      }
                      lVar11 = 0;
                      goto LAB_00130d09;
                    }
                    if (lVar11 == 0) {
                      lVar11 = FUN_002580d2(uVar13,iVar8,0);
                    }
                    else {
                      if (iVar8 != *(int *)(lVar11 + 0x30)) goto LAB_00130d50;
                      lVar11 = *(long *)(lVar11 + 0x38);
                    }
                    if (lVar11 == 0) goto LAB_00130d50;
                    puVar1 = *(ushort **)(lVar11 + 0x28);
                  } while (((uVar4 != *puVar1) || (uVar5 != (byte)puVar1[1])) ||
                          ((uVar6 != *(byte *)((long)puVar1 + 3) || ((char)puVar1[2] != '\0'))));
                  if (lVar10 != 0) {
LAB_00130d09:
                    do {
                      if (*(long *)(lVar10 + 0xb8) != 0) goto LAB_00130d1c;
                      lVar10 = *(long *)(lVar10 + 0x48);
                      if (lVar10 == 0) goto LAB_00130d1c;
                    } while( true );
                  }
                  while (*(long *)(lVar11 + 0xb8) == 0) {
                    lVar11 = *(long *)(lVar11 + 0x48);
LAB_00130d1c:
                    if (lVar11 == 0) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)invalidInstructionException();
                      (*pcVar2)();
                    }
                  }
                  iVar8 = FUN_00262158(*(undefined8 *)(lVar10 + 0xb8));
                  if (iVar8 != 0) goto LAB_00130718;
                  goto LAB_00130747;
                }
                if (DAT_01216a78 < 2) goto LAB_00130762;
                fVar16 = (float)FUN_002917b0(&DAT_01216a60);
                lVar10 = syscall(0xba);
                fVar16 = fVar16 * DAT_00298548;
                uVar18 = 0x44;
                uVar13 = 0x44;
              }
              else {
                if (DAT_01216a78 < 2) goto LAB_00130762;
                fVar16 = (float)FUN_002917b0(&DAT_01216a60);
                lVar10 = syscall(0xba);
                fVar16 = fVar16 * DAT_00298548;
                uVar18 = 0x43;
                uVar13 = 0x43;
              }
              FUN_002340f0((double)fVar16,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",
                           lVar10,"common/nvhwloc.c",uVar13,"compareLevels",uVar18,uStack_ec);
              goto LAB_001307ba;
            }
LAB_00130747:
            uVar15 = uVar15 + 1;
            if (uStack_e4 <= uVar15) break;
            goto LAB_00130688;
          }
          if (uVar4 != 10) {
            if (uVar4 == 0x14) {
              if (param_2 < 0x14) goto LAB_00130747;
            }
            else if (uVar4 != 0) goto LAB_001307a9;
LAB_00130718:
            if ((!bVar3) && (uVar14 < *param_3)) {
              *(undefined8 *)(param_4 + (ulong)uVar14 * 8) = uStack_e0;
            }
            uVar14 = uVar14 + 1;
            goto LAB_00130747;
          }
          if (9 < param_2) goto LAB_00130718;
          uVar15 = uVar15 + 1;
        } while (uVar15 < uStack_e4);
      }
      *param_3 = uVar14;
      uStack_ec = uVar7;
    }
    else if (1 < DAT_01216a78) {
      fVar16 = (float)FUN_002917b0(&DAT_01216a60);
      lVar10 = syscall(0xba);
      uVar13 = 0xc6;
      uVar18 = 0xc6;
      dVar17 = (double)(fVar16 * DAT_00298548);
LAB_001309e0:
      FUN_002340f0(dVar17,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar10,
                   "common/nvhwloc.c",uVar13,"nvhwlocDeviceGetTopologyNearestGpus",uVar18,uStack_ec)
      ;
    }
  }
LAB_00130762:
  return (ulong)uStack_ec;
}


// ===== 0013c6d0 nvmlDeviceGetTopologyNearestGpus =====

int nvmlDeviceGetTopologyNearestGpus
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
                 ,"entry_points.h",0x2c3,"nvmlDeviceGetTopologyNearestGpus",
                 "(nvmlDevice_t device, nvmlGpuTopologyLevel_t level, unsigned int *count, nvmlDevice_t *deviceArray)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_001305f0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2c3,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2c3,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0013c8c0 thunk_FUN_00131ff0 =====

int thunk_FUN_00131ff0(char *param_1,char *param_2,uint *param_3)

{
  int iVar1;
  long lVar2;
  float fVar3;
  undefined4 uStack_d0;
  int iStack_cc;
  undefined1 auStack_c8 [36];
  undefined1 auStack_a4 [44];
  undefined1 auStack_78 [36];
  undefined1 auStack_54 [44];
  
  iStack_cc = 0;
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((iVar1 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (param_2 == (char *)0x0) {
      iVar1 = 2;
    }
    else if ((*param_2 == '\x01') ||
            (((iVar1 = 2, *(int *)(param_2 + 0x14) != 0 && (*(int *)(param_2 + 0x1c) == 0)) &&
             ((*(int *)(param_2 + 0x10) != 0 && (*(long *)(param_2 + 0x20) != 0)))))) {
      if (param_3 == (uint *)0x0) {
        iVar1 = 2;
      }
      else {
        iVar1 = FUN_0013ef00(param_1,auStack_c8);
        if (iVar1 == 0) {
          iVar1 = FUN_0013ef00(param_2,auStack_78);
          if (iVar1 == 0) {
            iVar1 = FUN_001317e0(auStack_a4,auStack_54,&uStack_d0);
            if (iVar1 == 0) {
              switch(uStack_d0) {
              case 0:
                iVar1 = FUN_00176c20(param_1,&iStack_cc);
                if (iVar1 == 0) {
                  *param_3 = -(uint)(iStack_cc == 0) & 10;
                }
                else if (1 < DAT_01216a78) {
                  fVar3 = (float)FUN_002917b0(&DAT_01216a60);
                  lVar2 = syscall(0xba);
                  FUN_002340f0((double)(fVar3 * DAT_00298548),
                               "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
                               "common/nvhwloc.c",0xfa,"nvhwlocDeviceGetTopologyCommonAncestor",0xfa
                               ,iVar1);
                }
                break;
              case 1:
                *param_3 = 0x14;
                break;
              case 2:
                *param_3 = 0x1e;
                break;
              case 3:
                *param_3 = 0x28;
                break;
              case 4:
                *param_3 = 0x32;
                break;
              default:
                iVar1 = 999;
              }
            }
            else if (1 < DAT_01216a78) {
              fVar3 = (float)FUN_002917b0(&DAT_01216a60);
              lVar2 = syscall(0xba);
              FUN_002340f0((double)(fVar3 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
                           "common/nvhwloc.c",0xf5,"nvhwlocDeviceGetTopologyCommonAncestor",0xf5,
                           iVar1);
            }
          }
          else if (1 < DAT_01216a78) {
            fVar3 = (float)FUN_002917b0(&DAT_01216a60);
            lVar2 = syscall(0xba);
            FUN_002340f0((double)(fVar3 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
                         "common/nvhwloc.c",0xf4,"nvhwlocDeviceGetTopologyCommonAncestor",0xf4,iVar1
                        );
          }
        }
        else if (1 < DAT_01216a78) {
          fVar3 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar3 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
                       "common/nvhwloc.c",0xf3,"nvhwlocDeviceGetTopologyCommonAncestor",0xf3,iVar1);
        }
      }
    }
  }
  return iVar1;
}


// ===== 0013c8d0 nvmlDeviceGetTopologyCommonAncestor =====

int nvmlDeviceGetTopologyCommonAncestor(undefined8 param_1,undefined8 param_2,undefined8 param_3)

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
                 "entry_points.h",0x2be,"nvmlDeviceGetTopologyCommonAncestor",
                 "(nvmlDevice_t device1, nvmlDevice_t device2, nvmlGpuTopologyLevel_t *pathInfo)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_00131ff0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2be,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2be,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0013caa0 FUN_0013caa0 =====

undefined8 FUN_0013caa0(char *param_1,char *param_2,undefined4 param_3,long param_4)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((((param_1 != (char *)0x0) &&
       (((*param_1 == '\x01' ||
         ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
           (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) &&
        (param_2 != (char *)0x0)))) &&
      ((*param_2 == '\x01' ||
       (((*(int *)(param_2 + 0x14) != 0 && (*(int *)(param_2 + 0x1c) == 0)) &&
        ((*(int *)(param_2 + 0x10) != 0 && (*(long *)(param_2 + 0x20) != 0)))))))) && (param_4 != 0)
     ) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x20) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x20) + 200),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0013cb2a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3,param_4);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0013cb50 nvmlDeviceGetP2PStatus =====

int nvmlDeviceGetP2PStatus
              (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %d %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x2d2,"nvmlDeviceGetP2PStatus",
                 "(nvmlDevice_t device1, nvmlDevice_t device2, nvmlGpuP2PCapsIndex_t p2pIndex, nvmlGpuP2PStatus_t *p2pStatus)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013caa0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2d2,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2d2,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0013cd40 thunk_FUN_00130e00 =====

undefined8 thunk_FUN_00130e00(void)

{
  undefined8 uVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 uVar5;
  float fVar6;
  
  iVar2 = FUN_001335a0();
  uVar1 = DAT_01216968;
  if (iVar2 == 0) {
    lVar4 = FUN_002580d2(DAT_01216968,0,0);
    uVar5 = 0;
    FUN_002600fa(uVar1,*(undefined8 *)(lVar4 + 0xb8),2);
  }
  else {
    uVar5 = 3;
    if (1 < DAT_01216a78) {
      uVar3 = FUN_001335a0();
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"common/nvhwloc.c",0x11f,"nvhwlocDeviceClearCpuAffinity",0x11f,
                   uVar3);
      return 3;
    }
  }
  return uVar5;
}


// ===== 0013cd50 nvmlDeviceClearCpuAffinity =====

int nvmlDeviceClearCpuAffinity(char *param_1)

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
                 "entry_points.h",0xa5,"nvmlDeviceClearCpuAffinity");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_00130e00(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xa5,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xa5,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0013cf20 thunk_FUN_00130ee0 =====

undefined8 thunk_FUN_00130ee0(long param_1)

{
  undefined8 *puVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 uVar8;
  float fVar9;
  undefined8 auStack_a8 [17];
  
  if (param_1 == 0) {
    return 2;
  }
  FUN_0013d100(param_1,0x10,auStack_a8);
  iVar2 = FUN_001335a0();
  if (iVar2 == 0) {
    lVar4 = FUN_00260eab();
    if (lVar4 == 0) {
      uVar8 = 999;
      if (1 < DAT_01216a78) {
        fVar9 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                     lVar4,"common/nvhwloc.c",0x141);
      }
    }
    else {
      uVar6 = 0;
      do {
        puVar1 = auStack_a8 + uVar6;
        uVar7 = uVar6 & 0xffffffff;
        uVar6 = uVar6 + 1;
        FUN_00261c9e(lVar4,uVar7,*puVar1);
      } while (uVar6 != 0x10);
      iVar2 = FUN_002600fa(DAT_01216968,lVar4,2);
      if (iVar2 != 0) {
        if (DAT_01216a78 < 2) {
          FUN_00260f71(lVar4);
        }
        else {
          fVar9 = (float)FUN_002917b0(&DAT_01216a60);
          lVar5 = syscall(0xba);
          FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       "ERROR",lVar5,"common/nvhwloc.c",0x14d);
          FUN_00260f71(lVar4);
        }
        return 999;
      }
      uVar8 = 0;
      FUN_00260f71(lVar4);
    }
  }
  else {
    uVar8 = 3;
    if (1 < DAT_01216a78) {
      uVar3 = FUN_001335a0();
      fVar9 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"common/nvhwloc.c",0x13c,"nvhwlocDeviceSetCpuAffinity",0x13c,uVar3)
      ;
      return 3;
    }
  }
  return uVar8;
}


// ===== 0013cf30 nvmlDeviceSetCpuAffinity =====

int nvmlDeviceSetCpuAffinity(char *param_1)

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
                 "entry_points.h",0xa1,"nvmlDeviceSetCpuAffinity");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_00130ee0(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xa1,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xa1,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0013d100 FUN_0013d100 =====

void FUN_0013d100(void)

{
  FUN_00131150();
  return;
}


// ===== 0013d110 nvmlDeviceGetCpuAffinity =====

int nvmlDeviceGetCpuAffinity(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x9d,"nvmlDeviceGetCpuAffinity",
                 "(nvmlDevice_t device, unsigned int cpuSetSize, unsigned long *cpuSet)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013d100(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x9d,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x9d,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0013d2e0 thunk_FUN_00131150 =====

int thunk_FUN_00131150(long param_1,uint param_2,long param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  ulong uVar4;
  float fVar5;
  long alStack_40 [2];
  
  if ((param_3 == 0 || param_2 == 0) || (param_1 == 0)) {
    iVar1 = 2;
  }
  else {
    iVar1 = FUN_0012ff60(param_1,param_4,alStack_40);
    if (iVar1 == 0) {
      uVar4 = 0;
      lVar3 = *(long *)(alStack_40[0] + 0xb8);
      if (lVar3 == 0) {
        iVar1 = 999;
        if (1 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       "ERROR",lVar3,"common/nvhwloc.c",0x1a3);
        }
      }
      else {
        while( true ) {
          uVar2 = FUN_002618ab(lVar3,uVar4 & 0xffffffff);
          *(undefined8 *)(param_3 + uVar4 * 8) = uVar2;
          uVar4 = uVar4 + 1;
          if (param_2 <= (uint)uVar4) break;
          lVar3 = *(long *)(alStack_40[0] + 0xb8);
        }
      }
    }
    else if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar3,"common/nvhwloc.c",0x19e,"nvhwlocDeviceGetCpuAffinity",0x19e,iVar1)
      ;
    }
  }
  return iVar1;
}


// ===== 0013d2f0 nvmlDeviceGetCpuAffinityWithinScope =====

int nvmlDeviceGetCpuAffinityWithinScope
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
                 ,"entry_points.h",0x99,"nvmlDeviceGetCpuAffinityWithinScope",
                 "(nvmlDevice_t device, unsigned int cpuSetSize, unsigned long *cpuSet, nvmlAffinityScope_t scope)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_00131150(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x99,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x99,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0013d4e0 thunk_FUN_00131640 =====

int thunk_FUN_00131640(long param_1,uint param_2,long param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  ulong uVar4;
  float fVar5;
  long alStack_40 [2];
  
  if ((param_3 == 0 || param_2 == 0) || (param_1 == 0)) {
    iVar1 = 2;
  }
  else {
    iVar1 = FUN_0012ff60(param_1,param_4,alStack_40);
    if (iVar1 == 0) {
      uVar4 = 0;
      lVar3 = *(long *)(alStack_40[0] + 200);
      if (lVar3 == 0) {
        iVar1 = 999;
        if (1 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       "ERROR",lVar3,"common/nvhwloc.c",0x1ef);
        }
      }
      else {
        while( true ) {
          uVar2 = FUN_002618ab(lVar3,uVar4 & 0xffffffff);
          *(undefined8 *)(param_3 + uVar4 * 8) = uVar2;
          uVar4 = uVar4 + 1;
          if (param_2 <= (uint)uVar4) break;
          lVar3 = *(long *)(alStack_40[0] + 200);
        }
      }
    }
    else if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar3,"common/nvhwloc.c",0x1ea,"nvhwlocDeviceGetMemoryAffinity",0x1ea,
                   iVar1);
    }
  }
  return iVar1;
}


// ===== 0013d4f0 nvmlDeviceGetMemoryAffinity =====

int nvmlDeviceGetMemoryAffinity
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
                 ,"entry_points.h",0x95,"nvmlDeviceGetMemoryAffinity",
                 "(nvmlDevice_t device, unsigned int nodeSetSize, unsigned long *nodeSet, nvmlAffinityScope_t scope)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_00131640(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x95,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x95,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0013d6e0 thunk_FUN_001312f0 =====

int thunk_FUN_001312f0(char *param_1,uint param_2,long param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  float fVar7;
  undefined8 uVar8;
  long alStack_40 [2];
  
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
    if ((param_3 != 0) && (param_2 != 0)) {
      iVar1 = FUN_001335a0();
      if (iVar1 == 0) {
        iVar1 = FUN_0012ff60(param_1,param_4,alStack_40);
        if (iVar1 == 0) {
          if (*(long *)(alStack_40[0] + 0xb8) == 0) {
            iVar1 = 999;
            if (DAT_01216a78 < 2) {
              return 999;
            }
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            uVar4 = 0x1c6;
            fVar7 = fVar7 * DAT_00298548;
          }
          else {
            lVar3 = FUN_00260eab();
            uVar4 = DAT_01216968;
            if (lVar3 != 0) {
              uVar8 = *(undefined8 *)(alStack_40[0] + 0xb8);
              iVar1 = FUN_00257fb0(DAT_01216968,0xd);
              FUN_0026180c(lVar3);
LAB_001314dd:
              lVar5 = FUN_002580d2(uVar4,iVar1,0);
              do {
                if (lVar5 == 0) goto LAB_00131420;
                iVar2 = FUN_002622a3(uVar8,*(undefined8 *)(lVar5 + 0xb8));
                if (iVar2 != 0) {
                  iVar2 = FUN_0026197d(lVar3,*(undefined4 *)(lVar5 + 0x10));
                  if (iVar2 < 0) {
LAB_00131420:
                    uVar6 = 0;
                    do {
                      uVar4 = FUN_002618ab(lVar3,uVar6 & 0xffffffff);
                      *(undefined8 *)(param_3 + uVar6 * 8) = uVar4;
                      uVar6 = uVar6 + 1;
                    } while ((uint)uVar6 < param_2);
                    FUN_00260f71(lVar3);
                    return 0;
                  }
                  if (lVar5 == 0) goto LAB_001314dd;
                  if (iVar1 != *(int *)(lVar5 + 0x30)) goto LAB_00131420;
                }
                lVar5 = *(long *)(lVar5 + 0x38);
              } while( true );
            }
            iVar1 = 0x14;
            if (DAT_01216a78 < 2) {
              return 0x14;
            }
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            uVar4 = 0x1cd;
            fVar7 = fVar7 * DAT_00298548;
          }
          FUN_002340f0((double)fVar7,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar3,
                       "common/nvhwloc.c",uVar4);
          return iVar1;
        }
        if (DAT_01216a78 < 2) {
          return iVar1;
        }
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        fVar7 = fVar7 * DAT_00298548;
        uVar8 = 0x1c1;
        uVar4 = 0x1c1;
        iVar2 = iVar1;
      }
      else {
        iVar1 = 3;
        if (DAT_01216a78 < 2) {
          return 3;
        }
        iVar2 = FUN_001335a0();
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        fVar7 = fVar7 * DAT_00298548;
        uVar8 = 0x1bf;
        uVar4 = 0x1bf;
      }
      FUN_002340f0((double)fVar7,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
                   "common/nvhwloc.c",uVar4,"nvhwlocDeviceGetNumaIdByCpuAffinity",uVar8,iVar2);
      return iVar1;
    }
  }
  return 2;
}


// ===== 0013d6f0 FUN_0013d6f0 =====

int FUN_0013d6f0(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u, %p, %u)\n","DEBUG",lVar3,
                 "entry_points.h",0xa7a,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_001312f0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xa7a,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0013d840 FUN_0013d840 =====

undefined8 FUN_0013d840(long param_1,uint param_2,long param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_3 == 0 || 8 < param_2) || (param_1 == 0)) {
    return 2;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x48) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x48) + 0x78),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0013d881. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3,0);
    return uVar2;
  }
  return 3;
}


// ===== 0013d8a0 FUN_0013d8a0 =====

int FUN_0013d8a0(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x942,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013d840(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x942,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0013d9e0 FUN_0013d9e0 =====

undefined8 FUN_0013d9e0(long param_1,uint param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 == 0) || (8 < param_2)) {
    return 2;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x48) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x48) + 0x78),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0013da18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,0,1);
    return uVar2;
  }
  return 3;
}


// ===== 0013da40 FUN_0013da40 =====

int FUN_0013da40(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d)\n",
                 "DEBUG",lVar3,"entry_points.h",0x946,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013d9e0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x946,iVar1,uVar2);
  return iVar1;
}


// ===== 0013db80 FUN_0013db80 =====

undefined8 FUN_0013db80(long param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return 2;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x48) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x48) + 0x80),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0013dbbb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,0x5e,0,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 0013dbe0 nvmlDeviceGetPcieReplayCounter =====

int nvmlDeviceGetPcieReplayCounter(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x2b9,"nvmlDeviceGetPcieReplayCounter",
                 "(nvmlDevice_t device, unsigned int *value)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013db80(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2b9,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2b9,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0013ddc0 FUN_0013ddc0 =====

undefined8 FUN_0013ddc0(char *param_1,uint param_2,long param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (((param_1 != (char *)0x0) &&
      ((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) &&
     ((param_2 < 2 && (param_3 != 0)))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x48) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x48) + 200),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0013de1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0013de40 nvmlDeviceGetPcieThroughput =====

int nvmlDeviceGetPcieThroughput(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x2b4,"nvmlDeviceGetPcieThroughput",
                 "(nvmlDevice_t device, nvmlPcieUtilCounter_t counter, unsigned int *value)",param_1
                 ,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013ddc0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x2b4,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x2b4,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0013e010 FUN_0013e010 =====

undefined8 FUN_0013e010(long param_1,uint param_2,long param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_3 == 0 || 7 < param_2) || (param_1 == 0)) {
    return 2;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x48) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x48) + 0x90),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0013e051. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
    return uVar2;
  }
  return 3;
}


// ===== 0013e070 FUN_0013e070 =====

int FUN_0013e070(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x94a,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013e010(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x94a,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0013e1b0 FUN_0013e1b0 =====

undefined8 FUN_0013e1b0(long param_1,uint param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 == 0) || (7 < param_2)) {
    return 2;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x48) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x48) + 0x98),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0013e1e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 0013e200 FUN_0013e200 =====

int FUN_0013e200(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d)\n",
                 "DEBUG",lVar3,"entry_points.h",0x94e,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013e1b0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x94e,iVar1,uVar2);
  return iVar1;
}


// ===== 0013e340 FUN_0013e340 =====

undefined8 FUN_0013e340(char *param_1,long param_2,undefined4 param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_2 == 0) || (param_1 == (char *)0x0)) {
    return 2;
  }
  if (*param_1 != '\x01') {
    if (*(long *)(param_1 + 0x20) == 0) {
      uVar2 = FUN_00137580();
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
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x38) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x38) + 0x38),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0013e394. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
    return uVar2;
  }
  return 3;
}


// ===== 0013e3d0 nvmlDeviceGetUUID =====

int nvmlDeviceGetUUID(undefined8 param_1,undefined8 param_2,undefined4 param_3)

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
                 "entry_points.h",0xa9,"nvmlDeviceGetUUID",
                 "(nvmlDevice_t device, char *uuid, unsigned int length)",param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013e340(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xa9,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xa9,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0013e5a0 FUN_0013e5a0 =====

undefined8 FUN_0013e5a0(char *param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 == (char *)0x0) || (param_2 == 0)) {
    return 2;
  }
  if (*param_1 != '\x01') {
    if (*(long *)(param_1 + 0x20) == 0) {
      uVar2 = FUN_001376e0();
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
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0x68) != (undefined8 *)0x0)) &&
     (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar1 + 0x68),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0013e5f1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 0013e620 nvmlDeviceGetMemoryInfo_v2 =====

int nvmlDeviceGetMemoryInfo_v2(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0xb1,"nvmlDeviceGetMemoryInfo_v2",
                 "(nvmlDevice_t device, nvmlMemory_v2_t *memory)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013e5a0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xb1,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xb1,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0013e800 FUN_0013e800 =====

undefined8 FUN_0013e800(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined4 local_48 [2];
  undefined8 local_40;
  long local_38;
  undefined8 local_30;
  long local_28;
  
  if (param_1 != 0) {
    uVar1 = 2;
    if (param_2 != (undefined8 *)0x0) {
      local_48[0] = 0x2000028;
      uVar1 = FUN_0013e5a0(param_1,local_48);
      if ((int)uVar1 == 0) {
        *param_2 = local_40;
        param_2[1] = local_30;
        param_2[2] = local_38 + local_28;
      }
    }
    return uVar1;
  }
  return 2;
}


// ===== 0013e860 nvmlDeviceGetMemoryInfo =====

int nvmlDeviceGetMemoryInfo(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0xad,"nvmlDeviceGetMemoryInfo",
                 "(nvmlDevice_t device, nvmlMemory_t *memory)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013e800(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xad,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xad,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0013ea40 FUN_0013ea40 =====

undefined8 FUN_0013ea40(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x48) + 0xc0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0013ea9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0013eac0 nvmlDeviceGetPciInfo =====

int nvmlDeviceGetPciInfo(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0xbb,"nvmlDeviceGetPciInfo",
                 "(nvmlDevice_t device, nvmlPciInfo_t *pci)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013ea40(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xbb,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xbb,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0013eca0 FUN_0013eca0 =====

undefined8 FUN_0013eca0(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x48) + 0xc0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0013ecfa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,2,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0013ed20 nvmlDeviceGetPciInfo_v2 =====

int nvmlDeviceGetPciInfo_v2(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0xbf,"nvmlDeviceGetPciInfo_v2",
                 "(nvmlDevice_t device, nvmlPciInfo_t *pci)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013eca0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xbf,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xbf,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0013ef00 FUN_0013ef00 =====

undefined8 FUN_0013ef00(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x48) + 0xc0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0013ef5a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,3,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0013ef80 nvmlDeviceGetPciInfo_v3 =====

int nvmlDeviceGetPciInfo_v3(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0xc3,"nvmlDeviceGetPciInfo_v3",
                 "(nvmlDevice_t device, nvmlPciInfo_t *pci)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013ef00(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xc3,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xc3,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0013f160 FUN_0013f160 =====

undefined8 FUN_0013f160(char *param_1,long param_2)

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
    if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0xa8) != (undefined8 *)0x0)) &&
       (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar1 + 0xa8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0013f1b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,0);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0013f1e0 nvmlDeviceGetPersistenceMode =====

int nvmlDeviceGetPersistenceMode(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",199,"nvmlDeviceGetPersistenceMode",
                 "(nvmlDevice_t device, nvmlEnableState_t *mode)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013f160(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",199,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",199,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0013f3c0 FUN_0013f3c0 =====

undefined8 FUN_0013f3c0(char *param_1,undefined4 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined8 uVar3;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 != '\x01') &&
     ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
       (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) {
    return 2;
  }
  iVar2 = FUN_00236dd0();
  if (iVar2 == 0) {
    return 4;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0xa8) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0xa8) + 0x10),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0013f436. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,1,0);
    return uVar3;
  }
  return 3;
}


// ===== 0013f480 nvmlDeviceSetPersistenceMode =====

int nvmlDeviceSetPersistenceMode(undefined8 param_1,undefined4 param_2)

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
                 "entry_points.h",0xcb,"nvmlDeviceSetPersistenceMode",
                 "(nvmlDevice_t device, nvmlEnableState_t mode)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013f3c0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xcb,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xcb,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0013f660 FUN_0013f660 =====

undefined8 FUN_0013f660(char *param_1,undefined4 param_2,long param_3)

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
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) && (param_3 != 0)) {
    iVar2 = FUN_00236dd0();
    if (iVar2 != 0) {
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (((lVar1 != 0) && (*(long *)(lVar1 + 0xa8) != 0)) &&
         (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0xa8) + 0x10),
         UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0013f6e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,1,param_3);
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


// ===== 0013f730 FUN_0013f730 =====

int FUN_0013f730(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xb22,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013f660(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xb22,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0013f870 FUN_0013f870 =====

int FUN_0013f870(long param_1)

{
  int iVar1;
  undefined8 local_20;
  
  iVar1 = FUN_00236fb0();
  if (iVar1 == 0) {
    iVar1 = FUN_00237550(*(undefined4 *)(param_1 + 8),*(undefined2 *)(param_1 + 0xc),
                         *(undefined2 *)(param_1 + 0xe),0,&local_20);
    if (iVar1 == 0) {
      iVar1 = FUN_002388f0(local_20);
    }
  }
  FUN_00237220();
  return iVar1;
}


// ===== 0013f8d0 FUN_0013f8d0 =====

int FUN_0013f8d0(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0x9fe,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013f870(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x9fe,iVar1,uVar2);
  return iVar1;
}


// ===== 0013fa00 FUN_0013fa00 =====

undefined8 FUN_0013fa00(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x48),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0013fa55. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0013fa80 FUN_0013fa80 =====

int FUN_0013fa80(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x7ce,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013fa00(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x7ce,iVar1,uVar2);
  return iVar1;
}


// ===== 0013fbc0 FUN_0013fbc0 =====

undefined8 FUN_0013fbc0(char *param_1,undefined4 param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  char *__nptr;
  long lVar2;
  undefined8 uVar3;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 != '\x01') &&
     ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
       (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) {
    return 2;
  }
  iVar1 = FUN_00236dd0();
  if (iVar1 == 0) {
    return 4;
  }
  __nptr = getenv("NVSMI_PSTATE_LOCK");
  if ((__nptr != (char *)0x0) && (lVar2 = strtol(__nptr,(char **)0x0,10), (int)lVar2 == 1)) {
    lVar2 = *(long *)(param_1 + 0x256d8);
    if ((lVar2 != 0) &&
       ((*(long *)(lVar2 + 0x170) != 0 &&
        (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar2 + 0x170) + 0x58),
        UNRECOVERED_JUMPTABLE != (code *)0x0)))) {
                    /* WARNING: Could not recover jumptable at 0x0013fc75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar2,param_1,param_2);
      return uVar3;
    }
    return 3;
  }
  return 999;
}


// ===== 0013fcb0 FUN_0013fcb0 =====

int FUN_0013fcb0(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u)\n",
                 "DEBUG",lVar3,"entry_points.h",0x7d2,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013fbc0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x7d2,iVar1,uVar2);
  return iVar1;
}


// ===== 0013fdf0 FUN_0013fdf0 =====

undefined8 FUN_0013fdf0(char *param_1)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined8 uVar3;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 != '\x01') &&
     ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
       (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) {
    return 2;
  }
  iVar2 = FUN_00236dd0();
  if (iVar2 == 0) {
    return 4;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x60),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0013fe5a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1);
    return uVar3;
  }
  return 3;
}


// ===== 0013fea0 FUN_0013fea0 =====

int FUN_0013fea0(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0x7d6,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013fdf0(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x7d6,iVar1,uVar2);
  return iVar1;
}


// ===== 0013ffd0 FUN_0013ffd0 =====

undefined8 FUN_0013ffd0(char *param_1,undefined4 param_2,long param_3)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x78),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00140027. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00140050 FUN_00140050 =====

int FUN_00140050(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x7da,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0013ffd0(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x7da,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00140190 FUN_00140190 =====

undefined8 FUN_00140190(char *param_1,undefined4 param_2,long param_3)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x90),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001401ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00140210 FUN_00140210 =====

int FUN_00140210(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x7de,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00140190(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x7de,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00140350 FUN_00140350 =====

undefined8 FUN_00140350(char *param_1,undefined4 param_2,undefined4 param_3)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x98),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001403a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 001403d0 FUN_001403d0 =====

int FUN_001403d0(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u, %u)\n",
                 "DEBUG",lVar3,"entry_points.h",0x7e2,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00140350(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x7e2,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00140510 FUN_00140510 =====

undefined8 FUN_00140510(long param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (param_2 == 0) {
    return 2;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x150) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x150) + 0x18),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014053f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 00140560 FUN_00140560 =====

int FUN_00140560(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x8da,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00140510(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x8da,iVar1,uVar2);
  return iVar1;
}


// ===== 001406a0 FUN_001406a0 =====

undefined8 FUN_001406a0(long param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (param_2 == 0) {
    return 2;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x150) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x150) + 0x30),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001406cf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 001406f0 FUN_001406f0 =====

int FUN_001406f0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x8de,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001406a0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x8de,iVar1,uVar2);
  return iVar1;
}


// ===== 00140830 FUN_00140830 =====

undefined8 FUN_00140830(long param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (param_2 == 0) {
    return 2;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x150) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x150) + 0x20),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014085f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 00140880 FUN_00140880 =====

int FUN_00140880(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x8e2,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00140830(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x8e2,iVar1,uVar2);
  return iVar1;
}


// ===== 001409c0 FUN_001409c0 =====

undefined8 FUN_001409c0(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 400),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00140a18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00140a40 FUN_00140a40 =====

int FUN_00140a40(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x8e6,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001409c0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x8e6,iVar1,uVar2);
  return iVar1;
}


// ===== 00140b80 FUN_00140b80 =====

undefined8 FUN_00140b80(long param_1,long param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (param_2 == 0) {
    return 2;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x150) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x150) + 0x28),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00140baf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 00140bd0 FUN_00140bd0 =====

int FUN_00140bd0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x8ea,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00140b80(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x8ea,iVar1,uVar2);
  return iVar1;
}


// ===== 00140d10 FUN_00140d10 =====

undefined8 FUN_00140d10(long param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0xb8) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0xb8) + 0x20),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00140d40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar1;
  }
  return 3;
}


// ===== 00140d60 FUN_00140d60 =====

int FUN_00140d60(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0x8ee,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00140d10(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x8ee,iVar1,uVar2);
  return iVar1;
}


// ===== 00140e90 FUN_00140e90 =====

undefined8 FUN_00140e90(long param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0xb8) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0xb8) + 0x28),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00140ec0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar1;
  }
  return 3;
}


// ===== 00140ee0 FUN_00140ee0 =====

int FUN_00140ee0(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0x8f2,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00140e90(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x8f2,iVar1,uVar2);
  return iVar1;
}


// ===== 00141010 FUN_00141010 =====

undefined8 FUN_00141010(long param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0xb8) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0xb8) + 0x30),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00141040. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar1;
  }
  return 3;
}


// ===== 00141060 FUN_00141060 =====

int FUN_00141060(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0x8f6,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00141010(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x8f6,iVar1,uVar2);
  return iVar1;
}


// ===== 00141190 FUN_00141190 =====

undefined8 FUN_00141190(long param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0xb8) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0xb8) + 0x38),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001411c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar1;
  }
  return 3;
}


// ===== 001411e0 FUN_001411e0 =====

int FUN_001411e0(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0x99c,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00141190(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x99c,iVar1,uVar2);
  return iVar1;
}


// ===== 00141310 FUN_00141310 =====

undefined8 FUN_00141310(char *param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0xd0) != (undefined8 *)0x0)) &&
       (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar1 + 0xd0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00141360. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00141380 FUN_00141380 =====

int FUN_00141380(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %d %d)\n",
                 "DEBUG",lVar3,"entry_points.h",0x8fa,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00141310(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x8fa,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001414c0 FUN_001414c0 =====

undefined8 FUN_001414c0(char *param_1,long param_2)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0xd0) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0xd0) + 8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00141515. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00141540 FUN_00141540 =====

int FUN_00141540(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x8fe,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001414c0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x8fe,iVar1,uVar2);
  return iVar1;
}


// ===== 00141680 FUN_00141680 =====

undefined8 FUN_00141680(char *param_1,undefined4 param_2,long param_3)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x118) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x118) + 0x90),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001416da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00141700 nvmlDeviceGetThermalSettings =====

int nvmlDeviceGetThermalSettings(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p %u %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x5c2,"nvmlDeviceGetThermalSettings",
                 "(nvmlDevice_t device, unsigned int sensorIndex, nvmlGpuThermalSettings_t *pThermalSettings)"
                 ,param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00141680(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5c2,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5c2,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001418d0 FUN_001418d0 =====

undefined8 FUN_001418d0(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x50),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00141925. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00141950 nvmlDeviceGetDynamicPstatesInfo =====

int nvmlDeviceGetDynamicPstatesInfo(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x5b5,"nvmlDeviceGetDynamicPstatesInfo",
                 "(nvmlDevice_t device, nvmlGpuDynamicPstatesInfo_t *pDynamicPstatesInfo)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001418d0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5b5,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5b5,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00141b30 FUN_00141b30 =====

undefined8 FUN_00141b30(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0x60),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00141b85. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00141bb0 FUN_00141bb0 =====

int FUN_00141bb0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x902,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00141b30(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x902,iVar1,uVar2);
  return iVar1;
}


// ===== 00141cf0 FUN_00141cf0 =====

undefined8 FUN_00141cf0(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0x68),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00141d45. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00141d70 FUN_00141d70 =====

int FUN_00141d70(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x906,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00141cf0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x906,iVar1,uVar2);
  return iVar1;
}


// ===== 00141eb0 FUN_00141eb0 =====

undefined8 FUN_00141eb0(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0x70),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00141f05. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00141f30 FUN_00141f30 =====

int FUN_00141f30(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x90a,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00141eb0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x90a,iVar1,uVar2);
  return iVar1;
}


// ===== 00142070 FUN_00142070 =====

undefined8 FUN_00142070(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0x78),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001420c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 001420f0 FUN_001420f0 =====

int FUN_001420f0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x90e,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00142070(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x90e,iVar1,uVar2);
  return iVar1;
}


// ===== 00142230 FUN_00142230 =====

undefined8 FUN_00142230(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0x80),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00142288. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 001422b0 FUN_001422b0 =====

int FUN_001422b0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x912,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00142230(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x912,iVar1,uVar2);
  return iVar1;
}


// ===== 001423f0 FUN_001423f0 =====

undefined8 FUN_001423f0(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0x88),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00142448. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00142470 FUN_00142470 =====

int FUN_00142470(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x916,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001423f0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x916,iVar1,uVar2);
  return iVar1;
}


// ===== 001425b0 FUN_001425b0 =====

undefined8 FUN_001425b0(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0x90),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00142608. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00142630 FUN_00142630 =====

int FUN_00142630(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x91a,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001425b0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x91a,iVar1,uVar2);
  return iVar1;
}


// ===== 00142770 FUN_00142770 =====

undefined8 FUN_00142770(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0x98),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001427c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 001427f0 FUN_001427f0 =====

int FUN_001427f0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x91e,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00142770(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x91e,iVar1,uVar2);
  return iVar1;
}


// ===== 00142930 FUN_00142930 =====

undefined8 FUN_00142930(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0xa0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00142988. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 001429b0 FUN_001429b0 =====

int FUN_001429b0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x922,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00142930(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x922,iVar1,uVar2);
  return iVar1;
}


// ===== 00142af0 FUN_00142af0 =====

undefined8 FUN_00142af0(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0xa8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00142b48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00142b70 FUN_00142b70 =====

int FUN_00142b70(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x926,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00142af0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x926,iVar1,uVar2);
  return iVar1;
}


// ===== 00142cb0 FUN_00142cb0 =====

undefined8 FUN_00142cb0(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0xb0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00142d08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00142d30 FUN_00142d30 =====

int FUN_00142d30(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x932,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00142cb0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x932,iVar1,uVar2);
  return iVar1;
}


// ===== 00142e70 FUN_00142e70 =====

undefined8 FUN_00142e70(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0xb8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00142ec8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00142ef0 FUN_00142ef0 =====

int FUN_00142ef0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x936,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00142e70(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x936,iVar1,uVar2);
  return iVar1;
}


// ===== 00143030 FUN_00143030 =====

undefined8 FUN_00143030(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 0xc0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00143088. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 001430b0 FUN_001430b0 =====

int FUN_001430b0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x93a,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00143030(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x93a,iVar1,uVar2);
  return iVar1;
}


// ===== 001431f0 FUN_001431f0 =====

undefined8 FUN_001431f0(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x160) + 200),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00143248. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00143270 FUN_00143270 =====

int FUN_00143270(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x93e,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001431f0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x93e,iVar1,uVar2);
  return iVar1;
}


// ===== 001433b0 FUN_001433b0 =====

int FUN_001433b0(char *param_1,int param_2,int *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  int local_1c;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((iVar2 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (param_3 == (int *)0x0) {
      return 2;
    }
    if (param_2 != 0) {
      return 2;
    }
    lVar3 = *(long *)(param_1 + 0x256d8);
    local_1c = 0;
    if (((lVar3 == 0) || (*(undefined8 **)(lVar3 + 0x118) == (undefined8 *)0x0)) ||
       (pcVar1 = (code *)**(undefined8 **)(lVar3 + 0x118), pcVar1 == (code *)0x0)) {
      iVar2 = 3;
    }
    else {
      iVar2 = (*pcVar1)(lVar3,param_1,0,&local_1c);
      if (iVar2 == 0) {
        iVar2 = 0;
        if (-1 < local_1c) {
          iVar2 = local_1c;
        }
        *param_3 = iVar2;
        return 0;
      }
    }
    if (1 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar3,"api.c",0x106e,"tsapiDeviceGetTemperature",0x106e,iVar2);
    }
  }
  return iVar2;
}


// ===== 001434f0 nvmlDeviceGetTemperature =====

int nvmlDeviceGetTemperature(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x10f,"nvmlDeviceGetTemperature",
                 "(nvmlDevice_t device, nvmlTemperatureSensors_t sensorType, unsigned int *temp)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001433b0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x10f,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x10f,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001436c0 FUN_001436c0 =====

undefined8 FUN_001436c0(char *param_1,int *param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (((param_1 == (char *)0x0) ||
      ((*param_1 != '\x01' &&
       ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
         (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))))) ||
     ((param_2 == (int *)0x0 || (param_2[1] != 0)))) {
    return 2;
  }
  if (*param_2 != 0x100000c) {
    return 0x19;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0x118) != (undefined8 *)0x0)) &&
     (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar1 + 0x118),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014373c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,0,param_2 + 2);
    return uVar2;
  }
  return 3;
}


// ===== 00143750 nvmlDeviceGetTemperatureV =====

int nvmlDeviceGetTemperatureV(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x113,"nvmlDeviceGetTemperatureV",
                 "(nvmlDevice_t device, nvmlTemperature_t *param)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001436c0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x113,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x113,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00143930 FUN_00143930 =====

undefined8 FUN_00143930(char *param_1,undefined4 param_2,long param_3)

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
    if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0x118) != (undefined8 *)0x0)) &&
       (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar1 + 0x118),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00143986. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 001439b0 FUN_001439b0 =====

int FUN_001439b0(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x788,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00143930(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x788,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00143af0 FUN_00143af0 =====

undefined8 FUN_00143af0(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x118) + 0x40),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00143b45. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00143b70 nvmlDeviceGetFanSpeed =====

int nvmlDeviceGetFanSpeed(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x123,"nvmlDeviceGetFanSpeed",
                 "(nvmlDevice_t device, unsigned int *speed)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00143af0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x123,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x123,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00143d50 FUN_00143d50 =====

undefined8 FUN_00143d50(char *param_1,undefined4 param_2,long param_3)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x118) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x118) + 0x48),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00143dad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3,0,0);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00143dd0 nvmlDeviceGetFanSpeed_v2 =====

int nvmlDeviceGetFanSpeed_v2(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x127,"nvmlDeviceGetFanSpeed_v2",
                 "(nvmlDevice_t device, unsigned int fan, unsigned int * speed)",param_1,param_2,
                 param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00143d50(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x127,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x127,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00143fa0 FUN_00143fa0 =====

undefined8 FUN_00143fa0(long param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x118) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x118) + 0x50),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00143fca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 00143fe0 nvmlDeviceGetFanSpeedRPM =====

int nvmlDeviceGetFanSpeedRPM(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",299,"nvmlDeviceGetFanSpeedRPM",
                 "(nvmlDevice_t device, nvmlFanSpeedInfo_t *fanSpeed)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00143fa0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",299,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",299,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001441c0 FUN_001441c0 =====

undefined8 FUN_001441c0(char *param_1,undefined4 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined8 uVar3;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 != '\x01') &&
     ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
       (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) {
    return 2;
  }
  iVar2 = FUN_00236dd0();
  if (iVar2 == 0) {
    return 4;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x118) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x118) + 0x58),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014422e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar3;
  }
  return 3;
}


// ===== 00144270 FUN_00144270 =====

int FUN_00144270(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d)\n",
                 "DEBUG",lVar3,"entry_points.h",0x78c,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001441c0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x78c,iVar1,uVar2);
  return iVar1;
}


// ===== 001443b0 FUN_001443b0 =====

undefined8 FUN_001443b0(char *param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined8 uVar3;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 != '\x01') &&
     ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
       (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) {
    return 2;
  }
  iVar2 = FUN_00236dd0();
  if (iVar2 == 0) {
    return 4;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x118) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x118) + 0x60),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00144430. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
    return uVar3;
  }
  return 3;
}


// ===== 00144490 nvmlDeviceSetFanSpeed_v2 =====

int nvmlDeviceSetFanSpeed_v2(undefined8 param_1,undefined4 param_2,undefined4 param_3)

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
                 "entry_points.h",0x5b9,"nvmlDeviceSetFanSpeed_v2",
                 "(nvmlDevice_t device, unsigned int fan, unsigned int speed)",param_1,param_2,
                 param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001443b0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5b9,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5b9,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00144660 FUN_00144660 =====

undefined8 FUN_00144660(char *param_1)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined8 uVar3;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 != '\x01') &&
     ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
       (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) {
    return 2;
  }
  iVar2 = FUN_00236dd0();
  if (iVar2 == 0) {
    return 4;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x118) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x118) + 0x78),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001446cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,0);
    return uVar3;
  }
  return 3;
}


// ===== 00144710 FUN_00144710 =====

int FUN_00144710(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0x790,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00144660(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x790,iVar1,uVar2);
  return iVar1;
}


// ===== 00144840 FUN_00144840 =====

undefined8 FUN_00144840(char *param_1,undefined4 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined8 uVar3;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 != '\x01') &&
     ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
       (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) {
    return 2;
  }
  iVar2 = FUN_00236dd0();
  if (iVar2 == 0) {
    return 4;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x118) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x118) + 0x80),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001448b3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,0);
    return uVar3;
  }
  return 3;
}


// ===== 001448f0 nvmlDeviceSetDefaultFanSpeed_v2 =====

int nvmlDeviceSetDefaultFanSpeed_v2(undefined8 param_1,undefined4 param_2)

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
                 "entry_points.h",0x5be,"nvmlDeviceSetDefaultFanSpeed_v2",
                 "(nvmlDevice_t device, unsigned int fan)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00144840(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5be,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5be,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00144ad0 FUN_00144ad0 =====

undefined8 FUN_00144ad0(char *param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined8 uVar3;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 != '\x01') &&
     ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
       (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) {
    return 2;
  }
  iVar2 = FUN_00236dd0();
  if (iVar2 == 0) {
    return 4;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x118) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x118) + 0x80),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00144b53. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
    return uVar3;
  }
  return 3;
}


// ===== 00144bb0 nvmlDeviceSetFanControlPolicy =====

int nvmlDeviceSetFanControlPolicy(undefined8 param_1,undefined4 param_2,undefined4 param_3)

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
                 "entry_points.h",0x60c,"nvmlDeviceSetFanControlPolicy",
                 "(nvmlDevice_t device, unsigned int fan, nvmlFanControlPolicy_t policy)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00144ad0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x60c,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x60c,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00144d80 FUN_00144d80 =====

undefined8 FUN_00144d80(char *param_1,long param_2,long param_3)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x118) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x118) + 0x70),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00144ddd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00144e00 nvmlDeviceGetMinMaxFanSpeed =====

int nvmlDeviceGetMinMaxFanSpeed(undefined8 param_1,undefined8 param_2,undefined8 param_3)

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
                 "entry_points.h",0x5f8,"nvmlDeviceGetMinMaxFanSpeed",
                 "(nvmlDevice_t device, unsigned int *min, unsigned int * max)",param_1,param_2,
                 param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00144d80(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5f8,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5f8,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00144fd0 FUN_00144fd0 =====

undefined8 FUN_00144fd0(char *param_1,undefined4 param_2,long param_3)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x118) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x118) + 0x68),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00145027. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00145050 nvmlDeviceGetTargetFanSpeed =====

int nvmlDeviceGetTargetFanSpeed(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x12f,"nvmlDeviceGetTargetFanSpeed",
                 "(nvmlDevice_t device, unsigned int fan, unsigned int * targetSpeed)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00144fd0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x12f,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x12f,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00145220 FUN_00145220 =====

undefined8 FUN_00145220(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x118) + 0xa0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00145278. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 001452a0 FUN_001452a0 =====

int FUN_001452a0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x794,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00145220(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x794,iVar1,uVar2);
  return iVar1;
}


// ===== 001453e0 FUN_001453e0 =====

undefined8 FUN_001453e0(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x118) + 0x38),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00145435. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00145460 nvmlDeviceGetNumFans =====

int nvmlDeviceGetNumFans(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x133,"nvmlDeviceGetNumFans",
                 "(nvmlDevice_t device, unsigned int *numFans)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001453e0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x133,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x133,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00145640 FUN_00145640 =====

undefined8 FUN_00145640(char *param_1,undefined4 param_2,long param_3)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x118) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x118) + 0xa8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014569a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 001456c0 nvmlDeviceGetFanControlPolicy_v2 =====

int nvmlDeviceGetFanControlPolicy_v2(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x607,"nvmlDeviceGetFanControlPolicy_v2",
                 "(nvmlDevice_t device, unsigned int fan, nvmlFanControlPolicy_t *policy)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00145640(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x607,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x607,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00145890 FUN_00145890 =====

undefined8 FUN_00145890(long param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x118) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x118) + 0x88),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001458bd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 001458d0 nvmlDeviceGetCoolerInfo =====

int nvmlDeviceGetCoolerInfo(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x137,"nvmlDeviceGetCoolerInfo",
                 "(nvmlDevice_t device, nvmlCoolerInfo_t *coolerInfo)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00145890(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x137,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x137,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00145ab0 FUN_00145ab0 =====

undefined8 FUN_00145ab0(long param_1,undefined4 param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(undefined8 **)(DAT_012164a0 + 0xb8) != (undefined8 *)0x0)) &&
     (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(DAT_012164a0 + 0xb8),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00145ae4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1,param_2);
    return uVar1;
  }
  return 3;
}


// ===== 00145b10 nvmlSystemGetDriverVersion =====

int nvmlSystemGetDriverVersion(undefined8 param_1,undefined4 param_2)

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
                 "entry_points.h",0x163,"nvmlSystemGetDriverVersion",
                 "(char* version, unsigned int length)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00145ab0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x163,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x163,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00145cf0 FUN_00145cf0 =====

uint FUN_00145cf0(long param_1)

{
  int iVar1;
  long lVar2;
  code *pcVar3;
  long lVar4;
  uint uVar5;
  float fVar6;
  
  if (param_1 != 0) {
    lVar2 = FUN_00292ea0("libcuda.so.1");
    if (lVar2 == 0) {
      uVar5 = 6;
      if (4 < DAT_01216a78) {
        fVar6 = (float)FUN_002917b0(&DAT_01216a60);
        lVar2 = syscall(0xba);
        FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                     lVar2,"api.c",0x1271);
      }
    }
    else {
      pcVar3 = (code *)dlsym(lVar2,"cuDriverGetVersion");
      if (pcVar3 == (code *)0x0) {
        if (4 < DAT_01216a78) {
          fVar6 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       "DEBUG",lVar4,"api.c",0x1277);
        }
        uVar5 = 6;
        FUN_00292ed0(lVar2);
      }
      else {
        iVar1 = (*pcVar3)(param_1);
        uVar5 = ~-(uint)(iVar1 == 0) & 999;
        FUN_00292ed0(lVar2);
      }
    }
    return uVar5;
  }
  return 2;
}


// ===== 00145e70 nvmlSystemGetCudaDriverVersion_v2 =====

int nvmlSystemGetCudaDriverVersion_v2(char *param_1)

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
    pcVar5 = "(int* cudaDriverVersion)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x16b,"nvmlSystemGetCudaDriverVersion_v2");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_00145cf0(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x16b,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x16b,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00146040 FUN_00146040 =====

undefined8 FUN_00146040(undefined4 *param_1)

{
  undefined8 uVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    uVar1 = FUN_00145cf0();
    if ((int)uVar1 != 0) {
      *param_1 = 0x32dc;
      uVar1 = 0;
    }
    return uVar1;
  }
  return 2;
}


// ===== 00146080 nvmlSystemGetCudaDriverVersion =====

int nvmlSystemGetCudaDriverVersion(char *param_1)

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
    pcVar5 = "(int* cudaDriverVersion)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x167,"nvmlSystemGetCudaDriverVersion");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_00146040(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x167,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x167,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00146250 FUN_00146250 =====

undefined8 FUN_00146250(undefined8 param_1,undefined4 param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0xb8) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0xb8) + 0x18),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00146280. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1,param_2);
    return uVar1;
  }
  return 3;
}


// ===== 00146290 nvmlSystemGetDriverBranch =====

int nvmlSystemGetDriverBranch(undefined8 param_1,undefined4 param_2)

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
                 "entry_points.h",0x16f,"nvmlSystemGetDriverBranch",
                 "(nvmlSystemDriverBranchInfo_t *branchInfo, unsigned int length)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00146250(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x16f,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x16f,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00146470 FUN_00146470 =====

undefined8 FUN_00146470(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    return 0;
  }
  return 2;
}


// ===== 00146490 nvmlUnitGetCount =====

int nvmlUnitGetCount(char *param_1)

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
    pcVar5 = "(unsigned int *unitCount)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x173,"nvmlUnitGetCount");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_00146470(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x173,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x173,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00146660 FUN_00146660 =====

undefined8 FUN_00146660(void)

{
  return 2;
}


// ===== 00146670 nvmlUnitGetHandleByIndex =====

int nvmlUnitGetHandleByIndex(undefined4 param_1,undefined8 param_2)

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
                 "entry_points.h",0x17b,"nvmlUnitGetHandleByIndex",
                 "(unsigned int index, nvmlUnit_t *unit)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00146660(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x17b,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x17b,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00146850 FUN_00146850 =====

undefined8 FUN_00146850(void)

{
  return 2;
}


// ===== 00146860 nvmlUnitGetLedState =====

int nvmlUnitGetLedState(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x17f,"nvmlUnitGetLedState",
                 "(nvmlUnit_t unit, nvmlLedState_t *state)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00146850(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x17f,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x17f,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00146a40 FUN_00146a40 =====

undefined8 FUN_00146a40(void)

{
  return 2;
}


// ===== 00146a50 nvmlUnitGetPsuInfo =====

int nvmlUnitGetPsuInfo(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x187,"nvmlUnitGetPsuInfo","(nvmlUnit_t unit, nvmlPSUInfo_t *psu)"
                 ,param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00146a40(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x187,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x187,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00146c30 FUN_00146c30 =====

undefined8 FUN_00146c30(void)

{
  return 2;
}


// ===== 00146c40 nvmlUnitGetUnitInfo =====

int nvmlUnitGetUnitInfo(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",399,"nvmlUnitGetUnitInfo",
                 "(nvmlUnit_t unit, nvmlUnitInfo_t *info)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00146c30(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",399,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",399,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00146e20 FUN_00146e20 =====

undefined8 FUN_00146e20(void)

{
  return 2;
}


// ===== 00146e30 nvmlUnitGetTemperature =====

int nvmlUnitGetTemperature(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x18b,"nvmlUnitGetTemperature",
                 "(nvmlUnit_t unit, unsigned int type, unsigned int *temp)",param_1,param_2,param_3)
    ;
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00146e20(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x18b,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x18b,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00147000 FUN_00147000 =====

undefined8 FUN_00147000(void)

{
  return 2;
}


// ===== 00147010 nvmlUnitGetFanSpeedInfo =====

int nvmlUnitGetFanSpeedInfo(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x177,"nvmlUnitGetFanSpeedInfo",
                 "(nvmlUnit_t unit, nvmlUnitFanSpeeds_t *fanSpeeds)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00147000(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x177,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x177,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001471f0 FUN_001471f0 =====

undefined8 FUN_001471f0(void)

{
  return 2;
}


// ===== 00147200 nvmlUnitSetLedState =====

int nvmlUnitSetLedState(undefined8 param_1,undefined4 param_2)

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
                 "entry_points.h",0x183,"nvmlUnitSetLedState",
                 "(nvmlUnit_t unit, nvmlLedColor_t color)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001471f0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x183,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x183,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001473e0 FUN_001473e0 =====

undefined8 FUN_001473e0(void)

{
  return 2;
}


// ===== 001473f0 nvmlUnitGetDevices =====

int nvmlUnitGetDevices(undefined8 param_1,undefined8 param_2,undefined8 param_3)

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
                 "entry_points.h",0x193,"nvmlUnitGetDevices",
                 "(nvmlUnit_t unit, unsigned int *deviceCount, nvmlDevice_t *devices)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001473e0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x193,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x193,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001475c0 FUN_001475c0 =====

undefined8 FUN_001475c0(char *param_1,long param_2,long param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) &&
      (param_2 != 0 || param_3 != 0)))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x20) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x20) + 0x40),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00147621. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3,1);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00147640 nvmlDeviceGetDriverModel =====

int nvmlDeviceGetDriverModel(undefined8 param_1,undefined8 param_2,undefined8 param_3)

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
                 "entry_points.h",0x21,"nvmlDeviceGetDriverModel",
                 "(nvmlDevice_t device, nvmlDriverModel_t *current, nvmlDriverModel_t *pending)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001475c0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x21,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x21,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00147810 FUN_00147810 =====

undefined8 FUN_00147810(char *param_1,long param_2,long param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if ((param_1 != (char *)0x0) &&
     (((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) &&
      (param_2 != 0 || param_3 != 0)))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x20) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x20) + 0x40),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00147871. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3,2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00147890 nvmlDeviceGetDriverModel_v2 =====

int nvmlDeviceGetDriverModel_v2(undefined8 param_1,undefined8 param_2,undefined8 param_3)

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
                 "entry_points.h",0x26,"nvmlDeviceGetDriverModel_v2",
                 "(nvmlDevice_t device, nvmlDriverModel_t *current, nvmlDriverModel_t *pending)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00147810(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x26,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x26,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00147a60 FUN_00147a60 =====

undefined8 FUN_00147a60(void)

{
  return 3;
}


// ===== 00147a70 nvmlDeviceSetDriverModel =====

int nvmlDeviceSetDriverModel(undefined8 param_1,undefined4 param_2,undefined4 param_3)

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
                 "entry_points.h",0x1d,"nvmlDeviceSetDriverModel",
                 "(nvmlDevice_t device, nvmlDriverModel_t driverModel, unsigned int flags)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00147a60(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1d,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1d,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00147c40 FUN_00147c40 =====

int FUN_00147c40(char *param_1,void *param_2,ulong param_3)

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
      if (*(int *)(param_1 + 0x488) == 0) {
        do {
          iVar2 = FUN_00291820(param_1 + 0x48c,1,0);
        } while (iVar2 != 0);
        if (*(int *)(param_1 + 0x488) == 0) {
          lVar5 = *(long *)(param_1 + 0x256d8);
          uVar3 = 3;
          if (((lVar5 != 0) && (*(long *)(lVar5 + 200) != 0)) &&
             (pcVar1 = *(code **)(*(long *)(lVar5 + 200) + 0x10), pcVar1 != (code *)0x0)) {
            uVar3 = (*pcVar1)(lVar5,param_1,param_1 + 0x478,0x10);
          }
          *(undefined4 *)(param_1 + 0x490) = uVar3;
          param_1[0x488] = '\x01';
          param_1[0x489] = '\0';
          param_1[0x48a] = '\0';
          param_1[0x48b] = '\0';
        }
        FUN_00291830(param_1 + 0x48c,0);
      }
      iVar2 = *(int *)(param_1 + 0x490);
      if (iVar2 == 0) {
        sVar4 = strlen(param_1 + 0x478);
        if (sVar4 + 1 <= (param_3 & 0xffffffff)) {
          memcpy(param_2,param_1 + 0x478,sVar4 + 1);
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
                   "ERROR",lVar5,"api.c",0x1402,"tsapiDeviceGetVbiosVersion",0x1402,iVar2);
      return iVar2;
    }
  }
  return 2;
}


// ===== 00147e20 nvmlDeviceGetVbiosVersion =====

int nvmlDeviceGetVbiosVersion(undefined8 param_1,undefined8 param_2,undefined4 param_3)

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
                 "entry_points.h",0x197,"nvmlDeviceGetVbiosVersion",
                 "(nvmlDevice_t device, char * version, unsigned int length)",param_1,param_2,
                 param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00147c40(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x197,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x197,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00147ff0 FUN_00147ff0 =====

undefined8 FUN_00147ff0(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    return 0;
  }
  return 2;
}


// ===== 00148010 nvmlSystemGetHicVersion =====

int nvmlSystemGetHicVersion(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x19f,"nvmlSystemGetHicVersion",
                 "(unsigned int *hwbcCount, nvmlHwbcEntry_t *hwbcEntries)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00147ff0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x19f,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x19f,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 001481f0 FUN_001481f0 =====

undefined8 FUN_001481f0(char *param_1,uint param_2,long param_3,long param_4)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (((param_1 != (char *)0x0) &&
      ((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) &&
     ((param_4 != 0 && param_2 < 0x400 && (param_3 != 0)))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0xe8) != (undefined8 *)0x0)) &&
       (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar1 + 0xe8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00148260. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3,param_4);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00148280 FUN_00148280 =====

int FUN_00148280(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x7a0,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001481f0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x7a0,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001483d0 FUN_001483d0 =====

undefined8 FUN_001483d0(char *param_1,uint param_2,long param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (((param_1 != (char *)0x0) &&
      ((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) &&
     ((param_3 != 0 && (param_2 < 0x400)))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0xe8) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0xe8) + 0x18),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014842f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00148450 FUN_00148450 =====

int FUN_00148450(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x7a4,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001483d0(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x7a4,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00148590 FUN_00148590 =====

undefined8 FUN_00148590(int param_1,long param_2,long param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (((param_2 == 0) || (param_3 == 0)) || (0x3ff < param_1 - 0x400U)) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0xe8) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0xe8) + 8),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001485db. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1,param_2,param_3);
    return uVar1;
  }
  return 3;
}


// ===== 00148600 FUN_00148600 =====

int FUN_00148600(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%d, %p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x798,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00148590(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x798,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00148740 FUN_00148740 =====

undefined8 FUN_00148740(int param_1,long param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if ((param_2 == 0) || (0x3ff < param_1 - 0x400U)) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0xe8) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0xe8) + 0x10),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00148783. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1,param_2);
    return uVar1;
  }
  return 3;
}


// ===== 001487a0 FUN_001487a0 =====

int FUN_001487a0(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%d, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x79c,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00148740(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x79c,iVar1,uVar2);
  return iVar1;
}


// ===== 001488e0 FUN_001488e0 =====

undefined8
FUN_001488e0(int param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,int *param_5)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if ((param_5 == (int *)0x0) || (0x2ff < param_1 - 0x800U)) {
    return 2;
  }
  if (*param_5 != 4000) {
    return 7;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0xe8) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0xe8) + 0x20),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00148932. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1,param_2,param_3,param_4,param_5);
    return uVar1;
  }
  return 3;
}


// ===== 00148960 FUN_00148960 =====

int FUN_00148960(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
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
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%d, %d, %d, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x7a8,param_1,param_2,param_3,param_4,param_5);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001488e0(param_1,param_2,param_3,param_4,param_5);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x7a8,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00148ac0 FUN_00148ac0 =====

undefined8
FUN_00148ac0(int param_1,long param_2,long param_3,int param_4,long param_5,long param_6,int param_7
            ,long param_8,int param_9)

{
  code *pcVar1;
  undefined8 uVar2;
  
  if (((param_2 == 0) || (param_5 == 0)) || (param_3 == 0 || param_6 == 0)) {
    return 2;
  }
  if (param_8 == 0) {
    return 2;
  }
  uVar2 = 2;
  if (param_1 - 0x800U < 0x300) {
    if ((param_7 != 0x10 || param_9 != 0x3c00) || (param_4 != 0x10)) {
      return 7;
    }
    if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0xe8) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0xe8) + 0x28), pcVar1 == (code *)0x0)) {
      return 3;
    }
    uVar2 = (*pcVar1)(DAT_012164a0,param_1,param_2,param_3,0x10,param_5,param_6,0x10,param_8,0x3c00)
    ;
  }
  return uVar2;
}


// ===== 00148bc0 FUN_00148bc0 =====

int FUN_00148bc0(undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined8 param_5,undefined8 param_6,undefined4 param_7,undefined8 param_8,
                undefined4 param_9)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%d, %p, %p, %d, %p, %p, %d, %p, %d)\n","DEBUG"
                 ,lVar3,"entry_points.h",0x7ad,param_1,param_2,param_3,param_4,param_5,param_6,
                 param_7,param_8,param_9);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00148ac0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x7ad,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00148d40 FUN_00148d40 =====

undefined1  [16]
FUN_00148d40(int param_1,undefined4 param_2,long param_3,long param_4,long param_5,long param_6,
            long param_7)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  
  if (((param_3 == 0) || (param_4 == 0)) || (param_5 == 0 || param_6 == 0)) {
    auVar4._8_8_ = param_3;
    auVar4._0_8_ = 2;
    return auVar4;
  }
  if (param_7 == 0) {
    auVar5._8_8_ = param_3;
    auVar5._0_8_ = 2;
    return auVar5;
  }
  uVar2 = 2;
  if (param_1 - 0x800U < 0x300) {
    if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0xe8) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0xe8) + 0x30), pcVar1 == (code *)0x0)) {
      auVar6._8_8_ = param_3;
      auVar6._0_8_ = 3;
      return auVar6;
    }
    uVar2 = (*pcVar1)(DAT_012164a0,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    param_3 = param_6;
  }
  auVar3._8_8_ = param_3;
  auVar3._0_8_ = uVar2;
  return auVar3;
}


// ===== 00148df0 FUN_00148df0 =====

int FUN_00148df0(undefined4 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%d, %d, %p, %p, %p, %p, %p)\n","DEBUG",lVar3,
                 "entry_points.h",0x7b4,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00148d40(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x7b4,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00148f70 FUN_00148f70 =====

undefined8 FUN_00148f70(char *param_1,undefined4 *param_2)

{
  if (((param_2 != (undefined4 *)0x0) && (param_1 != (char *)0x0)) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    *param_2 = 0;
    return 0;
  }
  return 2;
}


// ===== 00148fc0 FUN_00148fc0 =====

int FUN_00148fc0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x7b9,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00148f70(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x7b9,iVar1,uVar2);
  return iVar1;
}


// ===== 00149100 FUN_00149100 =====

undefined8 FUN_00149100(char *param_1,long param_2,long param_3)

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
    if (((lVar1 != 0) && (*(undefined8 **)(lVar1 + 0x98) != (undefined8 *)0x0)) &&
       (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(lVar1 + 0x98),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014915c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00149180 FUN_00149180 =====

int FUN_00149180(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x7c1,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00149100(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x7c1,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001492c0 FUN_001492c0 =====

void FUN_001492c0(undefined8 param_1,undefined8 param_2)

{
  undefined4 local_c;
  
  local_c = 0;
  FUN_00149100(param_1,param_2,&local_c);
  return;
}


// ===== 001492e0 FUN_001492e0 =====

int FUN_001492e0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x7bd,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001492c0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x7bd,iVar1,uVar2);
  return iVar1;
}


// ===== 00149420 FUN_00149420 =====

undefined8 FUN_00149420(char *param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  int local_1c;
  
  local_1c = 0;
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((uVar4 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (param_2 == 0) {
      return 2;
    }
    iVar3 = FUN_00139230(param_1,&local_1c,0xc);
    uVar4 = 3;
    if (((iVar3 == 0) && (local_1c != 0)) &&
       ((lVar1 = *(long *)(param_1 + 0x256d8), lVar1 != 0 &&
        ((*(long *)(lVar1 + 0x158) != 0 &&
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x158) + 0x80), pcVar2 != (code *)0x0)))))) {
      uVar4 = (*pcVar2)(lVar1,param_1,param_2);
    }
  }
  return uVar4;
}


// ===== 001494e0 FUN_001494e0 =====

int FUN_001494e0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa86,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00149420(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0xa86,iVar1,uVar2);
  return iVar1;
}


// ===== 00149620 FUN_00149620 =====

undefined8 FUN_00149620(long param_1,undefined8 param_2,undefined4 param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  int local_2c [3];
  
  local_2c[0] = 0;
  iVar3 = FUN_00139230(param_1,local_2c,0xc);
  uVar4 = 3;
  if ((((iVar3 == 0) && (local_2c[0] != 0)) && (lVar1 = *(long *)(param_1 + 0x256d8), lVar1 != 0))
     && ((*(long *)(lVar1 + 0x158) != 0 &&
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x158) + 0x88), pcVar2 != (code *)0x0)))) {
    uVar4 = (*pcVar2)(lVar1,param_1,param_2,param_3);
  }
  return uVar4;
}


// ===== 001496b0 FUN_001496b0 =====

int FUN_001496b0(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p, %u)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa91,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00149620(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xa91,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001497f0 FUN_001497f0 =====

undefined8 FUN_001497f0(long param_1,long param_2,undefined4 param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  int local_2c [3];
  
  local_2c[0] = 0;
  iVar3 = FUN_00139230(param_1,local_2c,0xc);
  if ((iVar3 != 0) || (local_2c[0] == 0)) {
    return 3;
  }
  iVar3 = FUN_00236dd0();
  uVar4 = 4;
  if (iVar3 != 0) {
    if (param_2 == 0) {
      uVar4 = 2;
    }
    else {
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (lVar1 == 0) {
        return 3;
      }
      if (*(long *)(lVar1 + 0x158) == 0) {
        return 3;
      }
      pcVar2 = *(code **)(*(long *)(lVar1 + 0x158) + 0x90);
      if (pcVar2 == (code *)0x0) {
        return 3;
      }
      uVar4 = (*pcVar2)(lVar1,param_1,param_2,param_3,0);
    }
  }
  return uVar4;
}


// ===== 001498b0 FUN_001498b0 =====

int FUN_001498b0(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p, %u)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa8b,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001497f0(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xa8b,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001499f0 FUN_001499f0 =====

undefined8 FUN_001499f0(long param_1,long param_2,undefined4 param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  int local_2c [3];
  
  local_2c[0] = 0;
  iVar3 = FUN_00139230(param_1,local_2c,0xc);
  if ((iVar3 != 0) || (local_2c[0] == 0)) {
    return 3;
  }
  iVar3 = FUN_00236dd0();
  uVar4 = 4;
  if (iVar3 != 0) {
    if (param_2 == 0) {
      uVar4 = 2;
    }
    else {
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (lVar1 == 0) {
        return 3;
      }
      if (*(long *)(lVar1 + 0x158) == 0) {
        return 3;
      }
      pcVar2 = *(code **)(*(long *)(lVar1 + 0x158) + 0x90);
      if (pcVar2 == (code *)0x0) {
        return 3;
      }
      uVar4 = (*pcVar2)(lVar1,param_1,param_2,param_3,1);
    }
  }
  return uVar4;
}


// ===== 00149ab0 FUN_00149ab0 =====

int FUN_00149ab0(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p, %u)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa97,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001499f0(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xa97,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00149bf0 FUN_00149bf0 =====

undefined8 FUN_00149bf0(char *param_1,long param_2)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x60) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x60) + 0x20),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00149c42. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 00149c60 FUN_00149c60 =====

int FUN_00149c60(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x7ea,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00149bf0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x7ea,iVar1,uVar2);
  return iVar1;
}


// ===== 00149da0 FUN_00149da0 =====

undefined8 FUN_00149da0(long param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(undefined8 **)(DAT_012164a0 + 0x130) != (undefined8 *)0x0)) &&
     (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(DAT_012164a0 + 0x130),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00149dcf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar1;
  }
  return 3;
}


// ===== 00149df0 nvmlEventSetCreate =====

int nvmlEventSetCreate(char *param_1)

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
    pcVar5 = "(nvmlEventSet_t *set)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x1a3,"nvmlEventSetCreate");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_00149da0(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1a3,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1a3,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00149fc0 FUN_00149fc0 =====

undefined8 FUN_00149fc0(undefined8 param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x130) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x130) + 0x20),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00149feb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar1;
  }
  return 3;
}


// ===== 0014a000 nvmlSystemEventSetCreate =====

int nvmlSystemEventSetCreate(char *param_1)

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
    pcVar5 = "(nvmlSystemEventSetCreateRequest_t *request)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x1bc,"nvmlSystemEventSetCreate");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_00149fc0(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1bc,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1bc,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0014a1d0 FUN_0014a1d0 =====

undefined8 FUN_0014a1d0(undefined8 param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x130) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x130) + 0x28),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014a1fb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar1;
  }
  return 3;
}


// ===== 0014a210 nvmlSystemEventSetFree =====

int nvmlSystemEventSetFree(char *param_1)

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
    pcVar5 = "(nvmlSystemEventSetFreeRequest_t *request)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x1c0,"nvmlSystemEventSetFree");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_0014a1d0(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1c0,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1c0,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0014a3e0 FUN_0014a3e0 =====

undefined8 FUN_0014a3e0(undefined8 param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x130) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x130) + 0x30),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014a40b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar1;
  }
  return 3;
}


// ===== 0014a420 nvmlSystemRegisterEvents =====

int nvmlSystemRegisterEvents(char *param_1)

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
    pcVar5 = "(nvmlSystemRegisterEventRequest_t *request)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x1c4,"nvmlSystemRegisterEvents");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_0014a3e0(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1c4,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1c4,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0014a5f0 FUN_0014a5f0 =====

undefined8 FUN_0014a5f0(undefined8 param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x130) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x130) + 0x38),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014a61b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar1;
  }
  return 3;
}


// ===== 0014a630 nvmlSystemEventSetWait =====

int nvmlSystemEventSetWait(char *param_1)

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
    pcVar5 = "(nvmlSystemEventSetWaitRequest_t *request)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x1c8,"nvmlSystemEventSetWait");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_0014a5f0(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1c8,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1c8,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0014a800 FUN_0014a800 =====

int FUN_0014a800(long param_1,undefined4 *param_2,undefined4 *param_3,ulong *param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  int iVar6;
  float fVar7;
  undefined8 uVar8;
  int local_54;
  int local_40;
  int local_3c [3];
  
  if (((DAT_012164a0 == 0) || (*(undefined8 **)(DAT_012164a0 + 0xf0) == (undefined8 *)0x0)) ||
     (pcVar1 = (code *)**(undefined8 **)(DAT_012164a0 + 0xf0), pcVar1 == (code *)0x0)) {
    local_54 = 3;
  }
  else {
    local_54 = (*pcVar1)(DAT_012164a0,&local_40);
    if (local_54 == 0) {
      if (local_40 == 0) {
        return 999;
      }
      iVar6 = local_40 + -1;
      iVar2 = local_40 + -8;
      if (iVar2 < 0) {
        iVar2 = 0;
      }
      if (iVar2 <= iVar6) {
        do {
          if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0xf0) == 0)) ||
             (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0xf0) + 8), pcVar1 == (code *)0x0)) {
            local_54 = 3;
LAB_0014a8fe:
            if (DAT_01216a78 < 2) {
              return local_54;
            }
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            fVar7 = fVar7 * DAT_00298548;
            uVar5 = 0x167e;
            uVar8 = 0x167e;
            goto LAB_0014a9c7;
          }
          local_54 = (*pcVar1)(DAT_012164a0,iVar6,param_2,local_3c,param_3,param_4);
          if (local_54 != 0) goto LAB_0014a8fe;
          if (*(int *)(param_1 + 4) == local_3c[0]) {
            uVar4 = *param_4 / 1000;
            goto LAB_0014aa13;
          }
          iVar6 = iVar6 + -1;
        } while (iVar2 <= iVar6);
      }
      *param_2 = 999;
      uVar4 = 0;
      *param_3 = 0;
LAB_0014aa13:
      *param_4 = uVar4;
      return 0;
    }
  }
  if (1 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    fVar7 = fVar7 * DAT_00298548;
    uVar5 = 0x166e;
    uVar8 = 0x166e;
LAB_0014a9c7:
    FUN_002340f0((double)fVar7,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,"api.c"
                 ,uVar5,"getXidInfo",uVar8,local_54);
  }
  return local_54;
}


// ===== 0014aa50 FUN_0014aa50 =====

undefined8 FUN_0014aa50(long param_1,long param_2,undefined4 param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return 2;
  }
  *(undefined8 *)(param_2 + 0x10) = 0;
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x130) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x130) + 0x18),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014aa9b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,1,param_1,param_2,param_3);
    return uVar1;
  }
  return 3;
}


// ===== 0014aac0 nvmlEventSetWait =====

int nvmlEventSetWait(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %u)\n","DEBUG",lVar3,
                 "entry_points.h",0x1af,"nvmlEventSetWait",
                 "(nvmlEventSet_t set, nvmlEventData_t * data, unsigned int timeoutms)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014aa50(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1af,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1af,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014ac90 FUN_0014ac90 =====

undefined8 FUN_0014ac90(long param_1,long param_2,undefined4 param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return 2;
  }
  *(undefined8 *)(param_2 + 0x10) = 0;
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x130) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x130) + 0x18),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014acdb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,2,param_1,param_2,param_3);
    return uVar1;
  }
  return 3;
}


// ===== 0014ad00 nvmlEventSetWait_v2 =====

int nvmlEventSetWait_v2(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %u)\n","DEBUG",lVar3,
                 "entry_points.h",0x1b3,"nvmlEventSetWait_v2",
                 "(nvmlEventSet_t set, nvmlEventData_t * data, unsigned int timeoutms)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014ac90(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1b3,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1b3,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014aed0 FUN_0014aed0 =====

undefined8 FUN_0014aed0(long param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x130) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x130) + 0x10),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014af00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar1;
  }
  return 3;
}


// ===== 0014af20 nvmlEventSetFree =====

int nvmlEventSetFree(char *param_1)

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
    pcVar5 = "(nvmlEventSet_t set)";
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p)\n","DEBUG",lVar3,
                 "entry_points.h",0x1b7,"nvmlEventSetFree");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_0014aed0(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1b7,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1b7,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0014b0f0 FUN_0014b0f0 =====

undefined8 FUN_0014b0f0(undefined4 param_1,long param_2,int param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if ((param_2 == 0) || (param_3 == 0)) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0xc0) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0xc0) + 0x10),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014b12b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1,param_2,param_3);
    return uVar1;
  }
  return 3;
}


// ===== 0014b150 nvmlSystemGetProcessName =====

int nvmlSystemGetProcessName(undefined4 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%u, %p, %u)\n","DEBUG",lVar3,
                 "entry_points.h",0x1f1,"nvmlSystemGetProcessName",
                 "(unsigned int pid, char *name, unsigned int length)",param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014b0f0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x1f1,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x1f1,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014b320 FUN_0014b320 =====

undefined8 FUN_0014b320(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x20) + 0x90),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014b375. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0014b3a0 nvmlDeviceGetBrand =====

int nvmlDeviceGetBrand(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x81,"nvmlDeviceGetBrand",
                 "(nvmlDevice_t device, nvmlBrandType_t *type)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014b320(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x81,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x81,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0014b580 FUN_0014b580 =====

int FUN_0014b580(char *param_1,undefined4 *param_2)

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
    if (*(int *)(param_1 + 0x648) == 0) {
      do {
        iVar2 = FUN_00291820(param_1 + 0x64c,1,0);
      } while (iVar2 != 0);
      if (*(int *)(param_1 + 0x648) == 0) {
        lVar4 = *(long *)(param_1 + 0x256d8);
        uVar3 = 3;
        if (((lVar4 != 0) && (*(long *)(lVar4 + 0x48) != 0)) &&
           (pcVar1 = *(code **)(*(long *)(lVar4 + 0x48) + 8), pcVar1 != (code *)0x0)) {
          uVar3 = (*pcVar1)(lVar4,param_1,param_1 + 0x644);
        }
        *(undefined4 *)(param_1 + 0x650) = uVar3;
        param_1[0x648] = '\x01';
        param_1[0x649] = '\0';
        param_1[0x64a] = '\0';
        param_1[0x64b] = '\0';
      }
      FUN_00291830(param_1 + 0x64c,0);
    }
    iVar2 = *(int *)(param_1 + 0x650);
    if (iVar2 == 0) {
      *param_2 = *(undefined4 *)(param_1 + 0x644);
    }
    else if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"api.c",0x1781,"tsapiDeviceGetBusType",0x1781,iVar2);
    }
  }
  return iVar2;
}


// ===== 0014b710 nvmlDeviceGetBusType =====

int nvmlDeviceGetBusType(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x58e,"nvmlDeviceGetBusType",
                 "(nvmlDevice_t device, nvmlBusType_t *type)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014b580(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x58e,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x58e,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0014b8f0 FUN_0014b8f0 =====

undefined8 FUN_0014b8f0(char *param_1,undefined4 param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  int local_1c;
  
  if (param_1 != (char *)0x0) {
    if ((*param_1 == '\x01') ||
       ((((uVar4 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
      iVar3 = FUN_00236dd0();
      uVar4 = 4;
      if (iVar3 != 0) {
        uVar4 = FUN_0014b580(param_1,&local_1c);
        if ((((int)uVar4 == 0) && (uVar4 = 3, local_1c == 2)) &&
           ((lVar1 = *(long *)(param_1 + 0x256d8), lVar1 != 0 &&
            ((*(long *)(lVar1 + 0x48) != 0 &&
             (pcVar2 = *(code **)(*(long *)(lVar1 + 0x48) + 0x40), pcVar2 != (code *)0x0)))))) {
          uVar4 = (*pcVar2)(lVar1,param_1,param_2);
        }
      }
    }
    return uVar4;
  }
  return 2;
}


// ===== 0014b9a0 FUN_0014b9a0 =====

int FUN_0014b9a0(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u)\n",
                 "DEBUG",lVar3,"entry_points.h",0x7e6,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014b8f0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x7e6,iVar1,uVar2);
  return iVar1;
}


// ===== 0014bae0 thunk_FUN_001317e0 =====

undefined8 thunk_FUN_001317e0(long param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  ushort *puVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  int *piVar15;
  long lVar16;
  undefined8 uVar17;
  float fVar18;
  double dVar19;
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  undefined4 uStack_4c;
  uint auStack_48 [2];
  undefined4 *puStack_40;
  
  if ((param_2 == 0 || param_3 == (undefined4 *)0x0) || (param_1 == 0)) {
    return 2;
  }
  iVar8 = FUN_001335a0();
  uVar17 = DAT_01216968;
  if (iVar8 != 0) {
    if (1 < DAT_01216a78) {
      uVar9 = FUN_001335a0();
      fVar18 = (float)FUN_002917b0(&DAT_01216a60);
      lVar16 = syscall(0xba);
      FUN_002340f0((double)(fVar18 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar16,"common/nvhwloc.c",0x256,"nvhwlocDeviceGetTopologyInternal",0x256,
                   uVar9);
    }
    return 3;
  }
  uStack_58 = 0;
  iVar8 = __isoc99_sscanf(param_1,"%x:%x.%x",&uStack_54,&uStack_50,auStack_48);
  if ((iVar8 == 3) ||
     (iVar8 = __isoc99_sscanf(param_1,&DAT_0029adca,&uStack_58,&uStack_54,&uStack_50,auStack_48),
     iVar8 == 4)) {
    uVar7 = auStack_48[0];
    uVar6 = uStack_50;
    uVar5 = uStack_54;
    uVar4 = uStack_58;
    puVar13 = (undefined4 *)0x0;
    do {
      iVar8 = FUN_00257fb0(uVar17,0xf);
      if (iVar8 + 2U < 2) goto LAB_00131b78;
      if (puVar13 == (undefined4 *)0x0) {
        puVar13 = (undefined4 *)FUN_002580d2(uVar17,iVar8,0);
      }
      else {
        if (iVar8 != puVar13[0xc]) goto LAB_00131b78;
        puVar13 = *(undefined4 **)(puVar13 + 0xe);
      }
      uVar3 = DAT_01216968;
      if (puVar13 == (undefined4 *)0x0) goto LAB_00131b78;
      puVar2 = *(ushort **)(puVar13 + 10);
    } while ((((uVar4 != *puVar2) || (uVar5 != (byte)puVar2[1])) ||
             (uVar6 != *(byte *)((long)puVar2 + 3))) || (uVar7 != (byte)puVar2[2]));
    uStack_58 = 0;
    iVar8 = __isoc99_sscanf(param_2,"%x:%x.%x",&uStack_54,&uStack_50,auStack_48);
    if ((iVar8 == 3) ||
       (iVar8 = __isoc99_sscanf(param_2,&DAT_0029adca,&uStack_58,&uStack_54,&uStack_50,auStack_48),
       iVar8 == 4)) {
      uVar7 = auStack_48[0];
      uVar6 = uStack_50;
      uVar5 = uStack_54;
      uVar4 = uStack_58;
      puVar14 = (undefined4 *)0x0;
      do {
        iVar8 = FUN_00257fb0(uVar3,0xf);
        if (iVar8 + 2U < 2) goto LAB_00131ba8;
        if (puVar14 == (undefined4 *)0x0) {
          puVar14 = (undefined4 *)FUN_002580d2(uVar3,iVar8,0);
        }
        else {
          if (iVar8 != puVar14[0xc]) goto LAB_00131ba8;
          puVar14 = *(undefined4 **)(puVar14 + 0xe);
        }
        if (puVar14 == (undefined4 *)0x0) goto LAB_00131ba8;
        puVar2 = *(ushort **)(puVar14 + 10);
      } while (((uVar4 != *puVar2) || (uVar5 != (byte)puVar2[1])) ||
              ((uVar6 != *(byte *)((long)puVar2 + 3) || (uVar7 != (byte)puVar2[2]))));
      if (puVar13 == puVar14) {
        if (DAT_01216a78 < 2) {
          return 3;
        }
        fVar18 = (float)FUN_002917b0(&DAT_01216a60);
        lVar16 = syscall(0xba);
        FUN_002340f0((double)(fVar18 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %s\n",
                     "ERROR",lVar16,"common/nvhwloc.c",0x26a,param_1,param_2);
        return 3;
      }
      puVar10 = (undefined4 *)FUN_0012fe50(DAT_01216968,puVar13,puVar13);
      if (puVar10 == (undefined4 *)0x0) {
        if (DAT_01216a78 < 2) {
          return 999;
        }
        fVar18 = (float)FUN_002917b0(&DAT_01216a60);
        lVar16 = syscall(0xba);
        uVar17 = 0x273;
        dVar19 = (double)(fVar18 * DAT_00298548);
      }
      else {
        puVar11 = (undefined4 *)FUN_0012fe50(DAT_01216968,puVar14,puVar14);
        if (puVar11 != (undefined4 *)0x0) {
          puVar12 = (undefined4 *)FUN_0012fe50(DAT_01216968,puVar13,puVar14);
          if (puVar12 == (undefined4 *)0x0) {
            do {
              puVar12 = puVar13;
              if (*(long *)(puVar13 + 0x2e) != 0) break;
              puVar13 = *(undefined4 **)(puVar13 + 0x12);
              puVar12 = puVar13;
            } while (puVar13 != (undefined4 *)0x0);
            do {
              if (*(long *)(puVar14 + 0x2e) != 0) break;
              puVar14 = *(undefined4 **)(puVar14 + 0x12);
            } while (puVar14 != (undefined4 *)0x0);
            while (puVar14 != puVar12) {
              iVar1 = puVar14[0xc];
              iVar8 = puVar12[0xc];
              while (iVar1 < iVar8) {
                puVar12 = *(undefined4 **)(puVar12 + 0x12);
                iVar8 = puVar12[0xc];
              }
              while (iVar8 < iVar1) {
                puVar14 = *(undefined4 **)(puVar14 + 0x12);
                iVar1 = puVar14[0xc];
              }
              if ((puVar12 != puVar14) && (iVar1 == iVar8)) {
                puVar12 = *(undefined4 **)(puVar12 + 0x12);
                puVar14 = *(undefined4 **)(puVar14 + 0x12);
              }
            }
            if (puVar14 == (undefined4 *)0x0) {
              if (DAT_01216a78 < 2) {
                return 999;
              }
              fVar18 = (float)FUN_002917b0(&DAT_01216a60);
              lVar16 = syscall(0xba);
              FUN_002340f0((double)(fVar18 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %s\n","ERROR",lVar16,
                           "common/nvhwloc.c",0x28d,param_1,param_2);
              return 999;
            }
          }
          switch(*puVar12) {
          case 0:
          case 1:
          case 2:
          case 0xc:
          case 0x11:
            auStack_48[0] = 0;
            *param_3 = 4;
            uStack_54 = 1;
            puStack_40 = puVar12;
            iVar8 = FUN_0025c292(DAT_01216968,auStack_48,&uStack_54,&uStack_50,0);
            if ((((iVar8 == 0) && (uStack_54 == 1)) &&
                ((int *)CONCAT44(uStack_4c,uStack_50) != (int *)0x0)) &&
               (*(int *)CONCAT44(uStack_4c,uStack_50) == 0xd)) {
              *param_3 = 3;
            }
            break;
          default:
            *param_3 = 4;
            break;
          case 0xd:
            *param_3 = 3;
            break;
          case 0xe:
            lVar16 = *(long *)(puVar12 + 10);
            if (*(int *)(lVar16 + 0x18) == 0) {
              *param_3 = 2;
            }
            else if (((puVar10 == puVar12) ||
                     (*(char *)(lVar16 + 0x1e) == *(char *)(*(long *)(puVar10 + 10) + 2))) &&
                    ((puVar11 == puVar12 ||
                     (*(char *)(lVar16 + 0x1e) == *(char *)(*(long *)(puVar11 + 10) + 2))))) {
              *param_3 = 0;
            }
            else {
              *param_3 = 1;
            }
          }
          if (4 < DAT_01216a78) {
            uVar9 = *param_3;
            fVar18 = (float)FUN_002917b0(&DAT_01216a60);
            lVar16 = syscall(0xba);
            FUN_002340f0((double)(fVar18 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %s %d\n","DEBUG",lVar16,
                         "common/nvhwloc.c",0x2b8,param_1,param_2,uVar9);
            return 0;
          }
          return 0;
        }
        if (DAT_01216a78 < 2) {
          return 999;
        }
        fVar18 = (float)FUN_002917b0(&DAT_01216a60);
        lVar16 = syscall(0xba);
        uVar17 = 0x27b;
        dVar19 = (double)(fVar18 * DAT_00298548);
        param_1 = param_2;
      }
    }
    else {
      piVar15 = __errno_location();
      *piVar15 = 0x16;
LAB_00131ba8:
      if (DAT_01216a78 < 2) {
        return 999;
      }
      fVar18 = (float)FUN_002917b0(&DAT_01216a60);
      lVar16 = syscall(0xba);
      uVar17 = 0x264;
      dVar19 = (double)(fVar18 * DAT_00298548);
      param_1 = param_2;
    }
  }
  else {
    piVar15 = __errno_location();
    *piVar15 = 0x16;
LAB_00131b78:
    if (DAT_01216a78 < 2) {
      return 999;
    }
    fVar18 = (float)FUN_002917b0(&DAT_01216a60);
    lVar16 = syscall(0xba);
    uVar17 = 0x25c;
    dVar19 = (double)(fVar18 * DAT_00298548);
  }
  FUN_002340f0(dVar19,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n","ERROR",lVar16,"common/nvhwloc.c",
               uVar17,param_1);
  return 999;
}


// ===== 0014baf0 FUN_0014baf0 =====

int FUN_0014baf0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x8ce,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_001317e0(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x8ce,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014bc30 thunk_FUN_001323c0 =====

int thunk_FUN_001323c0(char *param_1,int *param_2,long param_3)

{
  undefined4 *puVar1;
  ushort uVar2;
  undefined4 uVar3;
  ushort *puVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined8 uVar13;
  uint uVar14;
  uint uVar15;
  ulong uVar16;
  float fVar17;
  undefined8 uVar18;
  uint uStack_98;
  uint uStack_94;
  uint uStack_90;
  uint uStack_8c;
  undefined1 auStack_88 [36];
  undefined1 auStack_64 [52];
  
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
      iVar5 = FUN_0013ef00(param_1,auStack_88);
      if (iVar5 == 0) {
        iVar5 = FUN_001335a0();
        uVar13 = DAT_01216968;
        if (iVar5 == 0) {
          uStack_98 = 0;
          iVar5 = __isoc99_sscanf(auStack_64,"%x:%x.%x",&uStack_94,&uStack_90,&uStack_8c);
          if ((iVar5 == 3) ||
             (iVar5 = __isoc99_sscanf(auStack_64,&DAT_0029adca,&uStack_98,&uStack_94,&uStack_90,
                                      &uStack_8c), iVar5 == 4)) {
            uVar10 = uStack_98;
            lVar8 = 0;
            do {
              iVar5 = FUN_00257fb0(uVar13,0xf);
              if (iVar5 + 2U < 2) goto LAB_00132840;
              if (lVar8 == 0) {
                lVar8 = FUN_002580d2(uVar13,iVar5,0);
              }
              else {
                if (iVar5 != *(int *)(lVar8 + 0x30)) goto LAB_00132840;
                lVar8 = *(long *)(lVar8 + 0x38);
              }
              if (lVar8 == 0) goto LAB_00132840;
              puVar4 = *(ushort **)(lVar8 + 0x28);
            } while ((((uVar10 != *puVar4) || (uStack_94 != (byte)puVar4[1])) ||
                     (uStack_90 != *(byte *)((long)puVar4 + 3))) || (uStack_8c != (byte)puVar4[2]));
            uVar16 = 0;
            for (lVar8 = *(long *)(lVar8 + 0x48); lVar8 != 0; lVar8 = *(long *)(lVar8 + 0x48)) {
              if (*(int *)(*(long *)(lVar8 + 0x28) + 0x18) == 0) {
                if (4 < DAT_01216a78) {
                  fVar17 = (float)FUN_002917b0(&DAT_01216a60);
                  lVar8 = syscall(0xba);
                  FUN_002340f0((double)(fVar17 * DAT_00298548),
                               "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",lVar8,
                               "common/nvhwloc.c",0x2f1);
                }
                *param_2 = (int)uVar16;
                return 0;
              }
              uVar3 = *(undefined4 *)(lVar8 + 0x34);
              puVar1 = (undefined4 *)(param_3 + uVar16 * 0x1c);
              *puVar1 = uVar3;
              iVar5 = DAT_01216a78;
              uVar2 = **(ushort **)(lVar8 + 0x28);
              puVar1[1] = (uint)uVar2;
              uVar10 = (uint)*(byte *)(*(long *)(lVar8 + 0x28) + 0x10);
              puVar1[2] = uVar10;
              uVar11 = (uint)*(byte *)(*(long *)(lVar8 + 0x28) + 2);
              puVar1[3] = uVar11;
              uVar12 = (uint)*(byte *)(*(long *)(lVar8 + 0x28) + 0x1e);
              puVar1[4] = uVar12;
              uVar14 = (uint)*(ushort *)(*(long *)(lVar8 + 0x28) + 8);
              puVar1[5] = uVar14;
              uVar15 = (uint)*(ushort *)(*(long *)(lVar8 + 0x28) + 10);
              puVar1[6] = uVar15;
              if (4 < iVar5) {
                fVar17 = (float)FUN_002917b0(&DAT_01216a60);
                lVar7 = syscall(0xba);
                FUN_002340f0((double)(fVar17 * DAT_00298548),
                             "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %d %d %d %d %d %d\n","DEBUG",
                             lVar7,"common/nvhwloc.c",0x2e9,uVar3,(uint)uVar2,uVar10,uVar11,uVar12,
                             uVar14,uVar15);
              }
              uVar16 = (ulong)((int)uVar16 + 1);
            }
            if (1 < DAT_01216a78) {
              fVar17 = (float)FUN_002917b0(&DAT_01216a60);
              lVar8 = syscall(0xba);
              FUN_002340f0((double)(fVar17 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                           "ERROR",lVar8,"common/nvhwloc.c",0x2dd);
              return 999;
            }
          }
          else {
            piVar9 = __errno_location();
            *piVar9 = 0x16;
LAB_00132840:
            if (1 < DAT_01216a78) {
              fVar17 = (float)FUN_002917b0(&DAT_01216a60);
              lVar8 = syscall(0xba);
              FUN_002340f0((double)(fVar17 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n"
                           ,"ERROR",lVar8,"common/nvhwloc.c",0x2d6,auStack_64);
            }
          }
          return 999;
        }
        iVar5 = 3;
        if (DAT_01216a78 < 2) {
          return 3;
        }
        iVar6 = FUN_001335a0();
        fVar17 = (float)FUN_002917b0(&DAT_01216a60);
        lVar8 = syscall(0xba);
        fVar17 = fVar17 * DAT_00298548;
        uVar18 = 0x2d0;
        uVar13 = 0x2d0;
      }
      else {
        if (DAT_01216a78 < 2) {
          return iVar5;
        }
        fVar17 = (float)FUN_002917b0(&DAT_01216a60);
        lVar8 = syscall(0xba);
        fVar17 = fVar17 * DAT_00298548;
        uVar18 = 0x2ce;
        uVar13 = 0x2ce;
        iVar6 = iVar5;
      }
      FUN_002340f0((double)fVar17,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar8,
                   "common/nvhwloc.c",uVar13,"nvhwlocDeviceGetUpstreamBridgesInfo",uVar18,iVar6);
      return iVar5;
    }
  }
  return 2;
}


// ===== 0014bc40 FUN_0014bc40 =====

int FUN_0014bc40(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x988,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_001323c0(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x988,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014bd80 FUN_0014bd80 =====

undefined8 FUN_0014bd80(char *param_1,int param_2,long param_3,undefined4 param_4)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x20) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x20) + 0x50),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014bddd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3,param_4);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0014be00 FUN_0014be00 =====

int FUN_0014be00(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, 0x%x, %p, %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x7f6,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014bd80(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x7f6,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014bf50 FUN_0014bf50 =====

undefined8 FUN_0014bf50(int param_1,long param_2,undefined4 param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x20) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0x58),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014bf89. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1,param_2,param_3);
    return uVar1;
  }
  return 3;
}


// ===== 0014bfb0 FUN_0014bfb0 =====

int FUN_0014bfb0(undefined4 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(0x%x, %p, %d)\n","DEBUG",lVar3,
                 "entry_points.h",0x7fa,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014bf50(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x7fa,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014c0f0 FUN_0014c0f0 =====

undefined8 FUN_0014c0f0(undefined4 param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x160) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0x160) + 0x50),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014c11a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar1;
  }
  return 3;
}


// ===== 0014c130 FUN_0014c130 =====

int FUN_0014c130(undefined4 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%d)\n","DEBUG",
                 lVar3,"entry_points.h",0x7fe,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014c0f0(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x7fe,iVar1,uVar2);
  return iVar1;
}


// ===== 0014c260 FUN_0014c260 =====

undefined8 FUN_0014c260(char *param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  int local_1c;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((uVar3 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (param_2 == 0) {
      return 2;
    }
    uVar3 = FUN_0014b580(param_1,&local_1c);
    if ((((int)uVar3 == 0) && (uVar3 = 3, local_1c == 2)) &&
       ((lVar1 = *(long *)(param_1 + 0x256d8), lVar1 != 0 &&
        ((*(long *)(lVar1 + 0x48) != 0 &&
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x48) + 0x48), pcVar2 != (code *)0x0)))))) {
      uVar3 = (*pcVar2)(lVar1,param_1,param_2);
    }
  }
  return uVar3;
}


// ===== 0014c320 nvmlDeviceGetPcieSpeed =====

int nvmlDeviceGetPcieSpeed(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0x5b1,"nvmlDeviceGetPcieSpeed",
                 "(nvmlDevice_t device, unsigned int *pcieSpeed)",param_1,param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014c260(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5b1,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5b1,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0014c500 FUN_0014c500 =====

undefined8 FUN_0014c500(char *param_1,undefined4 param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  int local_1c;
  
  if (param_1 != (char *)0x0) {
    if ((*param_1 == '\x01') ||
       ((((uVar4 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
      iVar3 = FUN_00236dd0();
      uVar4 = 4;
      if (iVar3 != 0) {
        uVar4 = FUN_0014b580(param_1,&local_1c);
        if ((((int)uVar4 == 0) && (uVar4 = 3, local_1c == 2)) &&
           ((lVar1 = *(long *)(param_1 + 0x256d8), lVar1 != 0 &&
            ((*(long *)(lVar1 + 0x48) != 0 &&
             (pcVar2 = *(code **)(*(long *)(lVar1 + 0x48) + 0x50), pcVar2 != (code *)0x0)))))) {
          uVar4 = (*pcVar2)(lVar1,param_1,param_2);
        }
      }
    }
    return uVar4;
  }
  return 2;
}


// ===== 0014c5b0 FUN_0014c5b0 =====

int FUN_0014c5b0(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u)\n",
                 "DEBUG",lVar3,"entry_points.h",0x802,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014c500(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x802,iVar1,uVar2);
  return iVar1;
}


// ===== 0014c6f0 FUN_0014c6f0 =====

undefined8 FUN_0014c6f0(char *param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  int local_1c;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((uVar3 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (param_2 == 0) {
      return 2;
    }
    uVar3 = FUN_0014b580(param_1,&local_1c);
    if ((((int)uVar3 == 0) && (uVar3 = 3, local_1c == 2)) &&
       ((lVar1 = *(long *)(param_1 + 0x256d8), lVar1 != 0 &&
        ((*(long *)(lVar1 + 0x48) != 0 &&
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x48) + 0x58), pcVar2 != (code *)0x0)))))) {
      uVar3 = (*pcVar2)(lVar1,param_1,param_2);
    }
  }
  return uVar3;
}


// ===== 0014c7b0 FUN_0014c7b0 =====

int FUN_0014c7b0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x806,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014c6f0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x806,iVar1,uVar2);
  return iVar1;
}


// ===== 0014c8f0 FUN_0014c8f0 =====

undefined8 FUN_0014c8f0(char *param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  int local_1c;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((uVar3 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (param_2 == 0) {
      return 2;
    }
    uVar3 = FUN_0014b580(param_1,&local_1c);
    if ((((int)uVar3 == 0) && (uVar3 = 3, local_1c == 2)) &&
       ((lVar1 = *(long *)(param_1 + 0x256d8), lVar1 != 0 &&
        ((*(long *)(lVar1 + 0x48) != 0 &&
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x48) + 0x60), pcVar2 != (code *)0x0)))))) {
      uVar3 = (*pcVar2)(lVar1,param_1,param_2);
    }
  }
  return uVar3;
}


// ===== 0014c9b0 FUN_0014c9b0 =====

int FUN_0014c9b0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x80a,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014c8f0(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x80a,iVar1,uVar2);
  return iVar1;
}


// ===== 0014caf0 FUN_0014caf0 =====

undefined8 FUN_0014caf0(char *param_1,long param_2,undefined4 param_3)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  int local_2c [3];
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((uVar3 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (param_2 == 0) {
      return 2;
    }
    uVar3 = FUN_0014b580(param_1,local_2c);
    if ((((int)uVar3 == 0) && (uVar3 = 3, local_2c[0] == 2)) &&
       ((lVar1 = *(long *)(param_1 + 0x256d8), lVar1 != 0 &&
        ((*(long *)(lVar1 + 0x48) != 0 &&
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x48) + 0x68), pcVar2 != (code *)0x0)))))) {
      uVar3 = (*pcVar2)(lVar1,param_1,param_2,param_3);
    }
  }
  return uVar3;
}


// ===== 0014cbb0 FUN_0014cbb0 =====

int FUN_0014cbb0(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p, %u)\n",
                 "DEBUG",lVar3,"entry_points.h",0x80e,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014caf0(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x80e,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014ccf0 FUN_0014ccf0 =====

undefined8 FUN_0014ccf0(char *param_1,long param_2,undefined4 param_3)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  int local_2c [3];
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((uVar3 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (param_2 == 0) {
      return 2;
    }
    uVar3 = FUN_0014b580(param_1,local_2c);
    if ((((int)uVar3 == 0) && (uVar3 = 3, local_2c[0] == 2)) &&
       ((lVar1 = *(long *)(param_1 + 0x256d8), lVar1 != 0 &&
        ((*(long *)(lVar1 + 0x48) != 0 &&
         (pcVar2 = *(code **)(*(long *)(lVar1 + 0x48) + 0x70), pcVar2 != (code *)0x0)))))) {
      uVar3 = (*pcVar2)(lVar1,param_1,param_2,param_3);
    }
  }
  return uVar3;
}


// ===== 0014cdb0 FUN_0014cdb0 =====

int FUN_0014cdb0(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p, %u)\n",
                 "DEBUG",lVar3,"entry_points.h",0x812,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014ccf0(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x812,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014cef0 FUN_0014cef0 =====

undefined8 FUN_0014cef0(char *param_1,undefined4 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined8 uVar3;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 != '\x01') &&
     ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
       (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) {
    return 2;
  }
  iVar2 = FUN_00236dd0();
  if (iVar2 == 0) {
    return 4;
  }
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x58),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014cf5e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar3;
  }
  return 3;
}


// ===== 0014cfa0 FUN_0014cfa0 =====

int FUN_0014cfa0(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u, %u, %u)\n","DEBUG",lVar3,
                 "entry_points.h",0x816,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014cef0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x816,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014d0f0 FUN_0014d0f0 =====

undefined8 FUN_0014d0f0(char *param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  int local_2c [3];
  
  local_2c[0] = 0;
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if (((*param_1 == '\x01') ||
      ((((uVar4 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) &&
     (uVar4 = FUN_00139230(param_1,local_2c,8), (int)uVar4 == 0)) {
    if (local_2c[0] == 0) {
      return 3;
    }
    iVar3 = FUN_00236dd0();
    uVar4 = 4;
    if (iVar3 != 0) {
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (lVar1 == 0) {
        return 3;
      }
      if (*(long *)(lVar1 + 0x170) == 0) {
        return 3;
      }
      pcVar2 = *(code **)(*(long *)(lVar1 + 0x170) + 0xa8);
      if (pcVar2 == (code *)0x0) {
        return 3;
      }
      uVar4 = (*pcVar2)(lVar1,param_1,param_2,param_3);
    }
  }
  return uVar4;
}


// ===== 0014d1e0 nvmlDeviceSetGpuLockedClocks =====

int nvmlDeviceSetGpuLockedClocks(undefined8 param_1,undefined4 param_2,undefined4 param_3)

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
                 "entry_points.h",0x21c,"nvmlDeviceSetGpuLockedClocks",
                 "(nvmlDevice_t device, unsigned int minGpuClockMHz, unsigned int maxGpuClockMHz)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014d0f0(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x21c,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x21c,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014d3b0 FUN_0014d3b0 =====

undefined8 FUN_0014d3b0(char *param_1)

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
  if (((*param_1 == '\x01') ||
      ((((uVar4 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) &&
     (uVar4 = FUN_00139230(param_1,local_1c,8), (int)uVar4 == 0)) {
    if (local_1c[0] == 0) {
      return 3;
    }
    iVar3 = FUN_00236dd0();
    uVar4 = 4;
    if (iVar3 != 0) {
      lVar1 = *(long *)(param_1 + 0x256d8);
      if (lVar1 == 0) {
        return 3;
      }
      if (*(long *)(lVar1 + 0x170) == 0) {
        return 3;
      }
      pcVar2 = *(code **)(*(long *)(lVar1 + 0x170) + 0xb8);
      if (pcVar2 == (code *)0x0) {
        return 3;
      }
      uVar4 = (*pcVar2)(lVar1,param_1);
    }
  }
  return uVar4;
}


// ===== 0014d480 nvmlDeviceResetGpuLockedClocks =====

int nvmlDeviceResetGpuLockedClocks(char *param_1)

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
                 "entry_points.h",0x220,"nvmlDeviceResetGpuLockedClocks");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_0014d3b0(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x220,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x220,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0014d650 FUN_0014d650 =====

int FUN_0014d650(char *param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  int local_30;
  int local_2c;
  
  local_30 = 0;
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
  iVar2 = FUN_00139230(param_1,&local_30,10);
  if (iVar2 != 0) {
    return iVar2;
  }
  if (local_30 == 0) {
LAB_0014d778:
    iVar2 = 3;
  }
  else {
    iVar2 = FUN_00236dd0();
    if (iVar2 == 0) {
      return 4;
    }
    lVar3 = *(long *)(param_1 + 0x256d8);
    if (((lVar3 == 0) || (*(long *)(lVar3 + 0x170) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(lVar3 + 0x170) + 0x220), pcVar1 == (code *)0x0)) {
      iVar2 = 3;
    }
    else {
      iVar2 = (*pcVar1)(lVar3,param_1,&local_2c);
      if (iVar2 == 0) {
        if (((local_2c == 0) && (lVar3 = *(long *)(param_1 + 0x256d8), lVar3 != 0)) &&
           ((*(long *)(lVar3 + 0x170) != 0 &&
            (pcVar1 = *(code **)(*(long *)(lVar3 + 0x170) + 0xc0), pcVar1 != (code *)0x0)))) {
          iVar2 = (*pcVar1)(lVar3,param_1,param_2,param_3);
          return iVar2;
        }
        goto LAB_0014d778;
      }
    }
    if (1 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar3,"api.c",0x18d9,"tsapiDeviceSetMemoryLockedClocks",0x18d9,iVar2);
    }
  }
  return iVar2;
}


// ===== 0014d810 nvmlDeviceSetMemoryLockedClocks =====

int nvmlDeviceSetMemoryLockedClocks(undefined8 param_1,undefined4 param_2,undefined4 param_3)

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
                 "entry_points.h",0x224,"nvmlDeviceSetMemoryLockedClocks",
                 "(nvmlDevice_t device, unsigned int minMemClockMHz, unsigned int maxMemClockMHz)",
                 param_1,param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014d650(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x224,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x224,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014d9e0 FUN_0014d9e0 =====

int FUN_0014d9e0(char *param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  int local_20;
  int local_1c;
  
  local_20 = 0;
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if (((*param_1 == '\x01') ||
      ((((iVar2 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) &&
     (iVar2 = FUN_00139230(param_1,&local_20,10), iVar2 == 0)) {
    if (local_20 == 0) {
      return 3;
    }
    iVar3 = FUN_00236dd0();
    iVar2 = 4;
    if (iVar3 != 0) {
      lVar4 = *(long *)(param_1 + 0x256d8);
      if (((lVar4 == 0) || (*(long *)(lVar4 + 0x170) == 0)) ||
         (pcVar1 = *(code **)(*(long *)(lVar4 + 0x170) + 0x220), pcVar1 == (code *)0x0)) {
        iVar2 = 3;
      }
      else {
        iVar2 = (*pcVar1)(lVar4,param_1,&local_1c);
        if (iVar2 == 0) {
          if (local_1c != 0) {
            return 3;
          }
          lVar4 = *(long *)(param_1 + 0x256d8);
          if (lVar4 == 0) {
            return 3;
          }
          if (*(long *)(lVar4 + 0x170) == 0) {
            return 3;
          }
          pcVar1 = *(code **)(*(long *)(lVar4 + 0x170) + 200);
          if (pcVar1 != (code *)0x0) {
            iVar2 = (*pcVar1)(lVar4,param_1);
            return iVar2;
          }
          return 3;
        }
      }
      if (1 < DAT_01216a78) {
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                     "ERROR",lVar4,"api.c",0x18fd,"tsapiDeviceResetMemoryLockedClocks",0x18fd,iVar2)
        ;
      }
    }
  }
  return iVar2;
}


// ===== 0014dbb0 nvmlDeviceResetMemoryLockedClocks =====

int nvmlDeviceResetMemoryLockedClocks(char *param_1)

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
                 "entry_points.h",0x228,"nvmlDeviceResetMemoryLockedClocks");
  }
  iVar1 = FUN_0011fea0(pcVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_0014d9e0(param_1);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x228,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x228,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 0014dd80 FUN_0014dd80 =====

undefined8 FUN_0014dd80(char *param_1,uint param_2,long param_3)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  if (((param_1 != (char *)0x0) &&
      ((*param_1 == '\x01' ||
       ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) &&
     ((param_2 < 5 && (param_3 != 0)))) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0xf0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014dde1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,0,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0014de00 FUN_0014de00 =====

int FUN_0014de00(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %d, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0xa40,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014dd80(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xa40,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014df40 FUN_0014df40 =====

undefined8 FUN_0014df40(char *param_1,undefined4 param_2,long param_3)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x100),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014df9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0014dfc0 nvmlDeviceGetMaxCustomerBoostClock =====

int nvmlDeviceGetMaxCustomerBoostClock(undefined8 param_1,undefined4 param_2,undefined8 param_3)

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
                 "entry_points.h",0x234,"nvmlDeviceGetMaxCustomerBoostClock",
                 "(nvmlDevice_t device, nvmlClockType_t clockType, unsigned int *clockMHz)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014df40(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x234,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x234,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014e190 FUN_0014e190 =====

int FUN_0014e190(char *param_1,uint *param_2,void *param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  undefined1 local_43b8 [4];
  uint local_43b4;
  undefined1 local_43b0 [17296];
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((iVar3 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (param_2 == (uint *)0x0) {
      return 2;
    }
    if ((*param_2 != 0) && (param_3 == (void *)0x0)) {
      return 2;
    }
    lVar4 = *(long *)(param_1 + 0x256d8);
    if (((lVar4 == 0) || (*(long *)(lVar4 + 0x170) == 0)) ||
       (pcVar2 = *(code **)(*(long *)(lVar4 + 0x170) + 0x140), pcVar2 == (code *)0x0)) {
      iVar3 = 3;
    }
    else {
      iVar3 = (*pcVar2)(lVar4,param_1,local_43b8);
      if (iVar3 == 0) {
        uVar1 = *param_2;
        *param_2 = local_43b4;
        if (local_43b4 <= uVar1) {
          memcpy(param_3,local_43b0,(ulong)local_43b4 << 2);
          return 0;
        }
        return 7;
      }
    }
    if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"api.c",0x19a4,"tsapiDeviceGetSupportedMemoryClocks",0x19a4,iVar3);
      return iVar3;
    }
  }
  return iVar3;
}


// ===== 0014e320 nvmlDeviceGetSupportedMemoryClocks =====

int nvmlDeviceGetSupportedMemoryClocks(undefined8 param_1,undefined8 param_2,undefined8 param_3)

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
                 "entry_points.h",0x244,"nvmlDeviceGetSupportedMemoryClocks",
                 "(nvmlDevice_t device, unsigned int *count, unsigned int *clocksMHz)",param_1,
                 param_2,param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014e190(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x244,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x244,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014e4f0 FUN_0014e4f0 =====

int FUN_0014e4f0(char *param_1,uint param_2,uint *param_3,void *param_4)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  ulong uVar7;
  float fVar8;
  uint local_43c4;
  uint auStack_43c0 [96];
  undefined8 auStack_4240 [2114];
  
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
    if (((param_3 != (uint *)0x0) && (param_2 != 0)) &&
       ((*param_3 == 0 || (param_4 != (void *)0x0)))) {
      lVar4 = *(long *)(param_1 + 0x256d8);
      if (((lVar4 == 0) || (*(long *)(lVar4 + 0x170) == 0)) ||
         (pcVar2 = *(code **)(*(long *)(lVar4 + 0x170) + 0x140), pcVar2 == (code *)0x0)) {
        iVar3 = 3;
      }
      else {
        iVar3 = (*pcVar2)(lVar4,param_1);
        if (iVar3 == 0) {
          uVar7 = 0;
          if (local_43c4 != 0) {
            do {
              if (auStack_43c0[uVar7] == param_2) {
                lVar4 = (uVar7 & 0xffffffff) + 0x40;
                uVar1 = *param_3;
                uVar6 = auStack_43c0[lVar4];
                if (uVar6 <= uVar1) {
                  *param_3 = uVar6;
                  memcpy(param_4,(void *)auStack_4240[uVar7 & 0xffffffff],(ulong)uVar6 << 2);
                  return 0;
                }
                if (4 < DAT_01216a78) {
                  fVar8 = (float)FUN_002917b0(&DAT_01216a60);
                  lVar5 = syscall(0xba);
                  FUN_002340f0((double)(fVar8 * DAT_00298548),
                               "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %d %u\n","DEBUG",lVar5,"api.c"
                               ,0x19d1,uVar1,uVar7,(ulong)uVar6);
                  uVar6 = auStack_43c0[lVar4];
                }
                *param_3 = uVar6;
                return 7;
              }
              uVar7 = uVar7 + 1;
            } while (uVar7 != local_43c4);
          }
          return 6;
        }
      }
      if (DAT_01216a78 < 2) {
        return iVar3;
      }
      fVar8 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar8 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"api.c",0x19c7,"tsapiDeviceGetSupportedGraphicsClocks",0x19c7,iVar3
                  );
      return iVar3;
    }
  }
  return 2;
}


// ===== 0014e780 nvmlDeviceGetSupportedGraphicsClocks =====

int nvmlDeviceGetSupportedGraphicsClocks
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
                 ,"entry_points.h",0x248,"nvmlDeviceGetSupportedGraphicsClocks",
                 "(nvmlDevice_t device, unsigned int memoryClockMHz, unsigned int *count, unsigned int *clocksMHz)"
                 ,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014e4f0(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x248,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x248,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014e970 FUN_0014e970 =====

undefined8 FUN_0014e970(char *param_1,undefined4 *param_2)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  if (param_1 != (char *)0x0) {
    if ((*param_1 == '\x01') ||
       ((((uVar3 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
         (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
      if (param_2 == (undefined4 *)0x0) {
        uVar3 = 2;
      }
      else {
        lVar1 = *(long *)(param_1 + 0x256d8);
        uVar3 = 3;
        if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
           (pcVar2 = *(code **)(*(long *)(lVar1 + 0x170) + 0x140), pcVar2 != (code *)0x0)) {
          uVar3 = (*pcVar2)(lVar1,param_1,param_2);
        }
        *param_2 = 2;
      }
    }
    return uVar3;
  }
  return 2;
}


// ===== 0014ea10 FUN_0014ea10 =====

int FUN_0014ea10(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x977,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014e970(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x977,iVar1,uVar2);
  return iVar1;
}


// ===== 0014eb50 FUN_0014eb50 =====

undefined8 FUN_0014eb50(char *param_1,long param_2,int param_3)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x150) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x150) + 0x40),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014ebab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0014ebd0 nvmlDeviceGetSupportedPerformanceStates =====

int nvmlDeviceGetSupportedPerformanceStates
              (undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %p, %u)\n","DEBUG",lVar3,
                 "entry_points.h",0x5df,"nvmlDeviceGetSupportedPerformanceStates",
                 "(nvmlDevice_t device, nvmlPstates_t *pstates, unsigned int size)",param_1,param_2,
                 param_3);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014eb50(param_1,param_2,param_3);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5df,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5df,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014eda0 FUN_0014eda0 =====

undefined8 FUN_0014eda0(char *param_1,undefined4 param_2,long param_3)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x128) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x128) + 8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014edf7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0014ee20 FUN_0014ee20 =====

int FUN_0014ee20(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x81a,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014eda0(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x81a,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014ef60 FUN_0014ef60 =====

undefined8 FUN_0014ef60(char *param_1,long param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x38) + 0x50),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014efb2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0014efd0 FUN_0014efd0 =====

int FUN_0014efd0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x81e,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014ef60(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x81e,iVar1,uVar2);
  return iVar1;
}


// ===== 0014f110 FUN_0014f110 =====

undefined8 FUN_0014f110(char *param_1,undefined4 param_2,long param_3)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x148),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014f16a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0014f190 FUN_0014f190 =====

int FUN_0014f190(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x822,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014f110(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x822,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014f2d0 FUN_0014f2d0 =====

undefined8 FUN_0014f2d0(char *param_1,undefined4 param_2,undefined4 param_3)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x150),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014f324. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0014f350 FUN_0014f350 =====

int FUN_0014f350(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u, %u)\n",
                 "DEBUG",lVar3,"entry_points.h",0x826,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014f2d0(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x826,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014f490 FUN_0014f490 =====

undefined8 FUN_0014f490(long param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(undefined8 **)(DAT_012164a0 + 0xf0) != (undefined8 *)0x0)) &&
     (UNRECOVERED_JUMPTABLE = (code *)**(undefined8 **)(DAT_012164a0 + 0xf0),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014f4bf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,param_1);
    return uVar1;
  }
  return 3;
}


// ===== 0014f4e0 FUN_0014f4e0 =====

int FUN_0014f4e0(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p)\n","DEBUG",
                 lVar3,"entry_points.h",0x82a,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014f490(param_1);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x82a,iVar1,uVar2);
  return iVar1;
}


// ===== 0014f610 FUN_0014f610 =====

undefined8 FUN_0014f610(undefined4 param_1,long param_2,long param_3,long param_4)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined1 local_20 [16];
  
  if ((param_3 == 0 || param_4 == 0) || (param_2 == 0)) {
    return 2;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0xf0) != 0)) &&
     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0xf0) + 8), pcVar1 != (code *)0x0)) {
    uVar2 = (*pcVar1)(DAT_012164a0,param_1,param_2,param_3,param_4,local_20);
    return uVar2;
  }
  return 3;
}


// ===== 0014f690 FUN_0014f690 =====

int FUN_0014f690(undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

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
                 "entry_points.h",0x82e,param_1,param_2,param_3,param_4);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014f610(param_1,param_2,param_3,param_4);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x82e,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014f7e0 FUN_0014f7e0 =====

undefined8 FUN_0014f7e0(void)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_00236dd0();
  if (iVar1 == 0) {
    return 4;
  }
  if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0xf0) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(DAT_012164a0 + 0xf0) + 0x10),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014f818. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(DAT_012164a0,0);
    return uVar2;
  }
  return 3;
}


// ===== 0014f840 FUN_0014f840 =====

int FUN_0014f840(void)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t()\n","DEBUG",
                 lVar3,"entry_points.h",0x832);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014f7e0();
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x832,iVar1,uVar2);
  return iVar1;
}


// ===== 0014f960 FUN_0014f960 =====

undefined8 FUN_0014f960(char *param_1,undefined4 param_2,undefined4 param_3)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x118) + 0x20),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014f9b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0014f9e0 FUN_0014f9e0 =====

int FUN_0014f9e0(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u, %u)\n",
                 "DEBUG",lVar3,"entry_points.h",0x835,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014f960(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x835,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014fb20 FUN_0014fb20 =====

undefined8 FUN_0014fb20(char *param_1,undefined4 param_2)

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
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x118) + 0x28),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014fb72. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0014fb90 FUN_0014fb90 =====

int FUN_0014fb90(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u)\n",
                 "DEBUG",lVar3,"entry_points.h",0x839,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014fb20(param_1,param_2);
    FUN_0011ff20();
  }
  if (DAT_01216a78 < 5) {
    return iVar1;
  }
  uVar2 = nvmlErrorString(iVar1);
  fVar4 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG",
               lVar3,"entry_points.h",0x839,iVar1,uVar2);
  return iVar1;
}


// ===== 0014fcd0 FUN_0014fcd0 =====

undefined8 FUN_0014fcd0(char *param_1,undefined4 param_2,long param_3)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x118) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x118) + 0x30),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014fd27. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0014fd50 FUN_0014fd50 =====

int FUN_0014fd50(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %u, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x83d,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014fcd0(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x83d,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 0014fe90 FUN_0014fe90 =====

undefined8 FUN_0014fe90(char *param_1,long param_2,undefined8 param_3)

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
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x58) != 0)) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x58) + 8),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014fee5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2,param_3);
      return uVar2;
    }
    return 3;
  }
  return 2;
}


// ===== 0014ff10 FUN_0014ff10 =====

int FUN_0014ff10(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  float fVar4;
  
  if (4 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t(%p, %p, %p)\n",
                 "DEBUG",lVar3,"entry_points.h",0x841,param_1);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_0014fe90(param_1,param_2,param_3);
    FUN_0011ff20();
  }
  if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x841,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 00150050 FUN_00150050 =====

undefined8
FUN_00150050(char *param_1,undefined4 param_2,undefined4 param_3,long param_4,long param_5)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if (((*param_1 == '\x01') ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) &&
     (param_4 != 0 || param_5 != 0)) {
    lVar1 = *(long *)(param_1 + 0x256d8);
    if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
       (pcVar2 = *(code **)(*(long *)(lVar1 + 0x170) + 0x30), pcVar2 != (code *)0x0)) {
      uVar3 = (*pcVar2)(lVar1,param_1,param_2,param_3,0,0,0,param_4,param_5);
      return uVar3;
    }
    return 3;
  }
  return 2;
}


// ===== 00150100 nvmlDeviceGetMinMaxClockOfPState =====

int nvmlDeviceGetMinMaxClockOfPState
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
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s%s (%p, %u, %u, %p, %p)\n","DEBUG",
                 lVar3,"entry_points.h",0x5c6,"nvmlDeviceGetMinMaxClockOfPState",
                 "(nvmlDevice_t device, nvmlClockType_t type, nvmlPstates_t pstate, unsigned int * minClockMHz, unsigned int * maxClockMHz)"
                 ,param_1,param_2,param_3,param_4,param_5);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_00150050(param_1,param_2,param_3,param_4,param_5);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0x5c6,iVar1,uVar2);
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0x5c6,iVar1,uVar2);
  }
  return iVar1;
}


// ===== 001502f0 FUN_001502f0 =====

undefined8 FUN_001502f0(long param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x1e8),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0015031d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


// ===== 00150330 nvmlDeviceGetPowerMizerMode_v1 =====

int nvmlDeviceGetPowerMizerMode_v1(undefined8 param_1,undefined8 param_2)

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
                 "entry_points.h",0xe7,"nvmlDeviceGetPowerMizerMode_v1",
                 "(nvmlDevice_t device, nvmlDevicePowerMizerModes_v1_t *powerMizerMode)",param_1,
                 param_2);
  }
  iVar1 = FUN_0011fea0();
  if (iVar1 == 0) {
    iVar1 = FUN_001502f0(param_1,param_2);
    FUN_0011ff20();
    if (4 < DAT_01216a78) {
      uVar2 = nvmlErrorString(iVar1);
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar3,
                   "entry_points.h",0xe7,iVar1,uVar2);
      return iVar1;
    }
  }
  else if (4 < DAT_01216a78) {
    uVar2 = nvmlErrorString(iVar1);
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %s\n","DEBUG"
                 ,lVar3,"entry_points.h",0xe7,iVar1,uVar2);
    return iVar1;
  }
  return iVar1;
}


// ===== 00150510 FUN_00150510 =====

undefined8 FUN_00150510(long param_1,undefined8 param_2)

{
  long lVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x170) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(long *)(lVar1 + 0x170) + 0x1f0),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0015053d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,param_1,param_2);
    return uVar2;
  }
  return 3;
}


