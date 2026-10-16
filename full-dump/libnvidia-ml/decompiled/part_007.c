// ===== 00248340 FUN_00248340 =====

long FUN_00248340(undefined4 param_1,int *param_2)

{
  int iVar1;
  size_t sVar2;
  long lVar3;
  ulong local_c8;
  undefined8 *local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  sockaddr local_a8;
  undefined2 uStack_98;
  undefined6 uStack_96;
  undefined2 uStack_90;
  undefined6 uStack_8e;
  undefined2 uStack_88;
  undefined6 local_86;
  undefined2 uStack_80;
  undefined6 local_7e;
  undefined2 uStack_78;
  undefined6 uStack_76;
  undefined8 uStack_70;
  undefined2 uStack_68;
  undefined6 uStack_66;
  undefined8 uStack_60;
  undefined2 uStack_58;
  undefined6 local_56;
  undefined8 uStack_50;
  undefined2 uStack_48;
  undefined6 uStack_46;
  undefined2 uStack_40;
  undefined2 local_3e;
  undefined2 uStack_3c;
  
  local_c8 = local_c8 & 0xffffffff00000000;
  local_a8.sa_family = 1;
  local_a8.sa_data._0_6_ = SUB86(s__var_run_nvidia_persistenced_soc_002dd580._0_8_,0);
  local_a8.sa_data._6_2_ = SUB82(s__var_run_nvidia_persistenced_soc_002dd580._0_8_,6);
  local_a8.sa_data._8_6_ = SUB86(s__var_run_nvidia_persistenced_soc_002dd580._8_8_,0);
  uStack_98 = SUB82(s__var_run_nvidia_persistenced_soc_002dd580._8_8_,6);
  local_86 = 0x74656b;
  uStack_80 = 0;
  uStack_96 = (undefined6)s__var_run_nvidia_persistenced_soc_002dd580._16_8_;
  uStack_90 = SUB82(s__var_run_nvidia_persistenced_soc_002dd580._16_8_,6);
  uStack_8e = (undefined6)s__var_run_nvidia_persistenced_soc_002dd580._24_8_;
  uStack_88 = SUB82(s__var_run_nvidia_persistenced_soc_002dd580._24_8_,6);
  local_7e = 0;
  uStack_78 = 0;
  uStack_46 = 0;
  uStack_40 = 0;
  local_3e = 0;
  uStack_3c = 0;
  uStack_76 = 0;
  uStack_70 = 0;
  uStack_68 = 0;
  uStack_66 = 0;
  uStack_60 = 0;
  uStack_58 = 0;
  local_56 = 0;
  uStack_50 = 0;
  uStack_48 = 0;
  local_c0 = calloc(1,0x6e);
  if (local_c0 == (undefined8 *)0x0) {
    return 0;
  }
  local_c8 = 0x6e0000006e;
  *local_c0 = CONCAT62(local_a8.sa_data._0_6_,local_a8.sa_family);
  local_c0[1] = CONCAT62(local_a8.sa_data._8_6_,local_a8.sa_data._6_2_);
  local_c0[2] = CONCAT62(uStack_96,uStack_98);
  local_c0[3] = CONCAT62(uStack_8e,uStack_90);
  local_c0[0xc] = CONCAT62(uStack_46,uStack_48);
  local_c0[4] = CONCAT62(local_86,uStack_88);
  local_c0[5] = CONCAT62(local_7e,uStack_80);
  *(uint *)(local_c0 + 0xd) = CONCAT22(local_3e,uStack_40);
  local_c0[6] = CONCAT62(uStack_76,uStack_78);
  local_c0[7] = uStack_70;
  *(undefined2 *)((long)local_c0 + 0x6c) = uStack_3c;
  local_c0[8] = CONCAT62(uStack_66,uStack_68);
  local_c0[9] = uStack_60;
  local_c0[10] = CONCAT62(local_56,uStack_58);
  local_c0[0xb] = uStack_50;
  iVar1 = socket(1,1,0);
  *param_2 = iVar1;
  if (-1 < iVar1) {
    sVar2 = strlen(local_a8.sa_data);
    iVar1 = connect(iVar1,&local_a8,(int)sVar2 + 2);
    if (-1 < iVar1) {
      lVar3 = FUN_00293bb4(*param_2,&local_c8,0x88be,param_1,0,0);
      if (lVar3 != 0) {
        local_b0 = 0;
        local_b8 = 0x32;
        (**(code **)(*(long *)(lVar3 + 8) + 0x28))(lVar3,1,&local_b8);
      }
      goto LAB_002484f5;
    }
    iVar1 = *param_2;
  }
  lVar3 = 0;
  if (iVar1 != -1) {
    close(iVar1);
    free(local_c0);
    return 0;
  }
LAB_002484f5:
  free(local_c0);
  return lVar3;
}


// ===== 00248550 FUN_00248550 =====

undefined4
FUN_00248550(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  long lVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int local_cc;
  stat local_c8;
  
  local_cc = -1;
  iVar1 = __xstat(1,"/var/run/nvidia-persistenced/socket",&local_c8);
  if ((iVar1 < 0) || ((local_c8.st_mode & 0xf000) != 0xc000)) {
    uVar4 = 1;
  }
  else {
    lVar2 = FUN_00248340(1,&local_cc);
    if (lVar2 == 0) {
      uVar4 = 7;
    }
    else {
      uVar4 = 8;
      local_c8.st_dev._0_4_ = param_1;
      local_c8.st_dev._4_4_ = param_2;
      local_c8.st_ino._0_4_ = param_3;
      local_c8.st_ino._4_4_ = param_4;
      local_c8.st_nlink._0_4_ = param_5;
      puVar3 = (undefined4 *)FUN_00248030(&local_c8,lVar2);
      iVar1 = local_cc;
      if (puVar3 != (undefined4 *)0x0) {
        uVar4 = *puVar3;
      }
      (**(code **)(*(long *)(lVar2 + 8) + 0x20))(lVar2);
      if (-1 < iVar1) {
        close(iVar1);
      }
    }
  }
  return uVar4;
}


// ===== 00248680 FUN_00248680 =====

int FUN_00248680(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                int *param_5)

{
  int __fd;
  int iVar1;
  long lVar2;
  int *piVar3;
  int local_cc;
  stat local_c8;
  
  local_cc = -1;
  iVar1 = __xstat(1,"/var/run/nvidia-persistenced/socket",&local_c8);
  if ((iVar1 < 0) || ((local_c8.st_mode & 0xf000) != 0xc000)) {
    iVar1 = 1;
  }
  else {
    lVar2 = FUN_00248340(1,&local_cc);
    if (lVar2 == 0) {
      iVar1 = 7;
    }
    else {
      iVar1 = 8;
      local_c8.st_dev._0_4_ = param_1;
      local_c8.st_dev._4_4_ = param_2;
      local_c8.st_ino._0_4_ = param_3;
      local_c8.st_ino._4_4_ = param_4;
      piVar3 = (int *)FUN_00248090(&local_c8,lVar2);
      __fd = local_cc;
      if ((piVar3 != (int *)0x0) && (iVar1 = *piVar3, iVar1 == 0)) {
        *param_5 = piVar3[1];
      }
      (**(code **)(*(long *)(lVar2 + 8) + 0x20))(lVar2);
      if (-1 < __fd) {
        close(__fd);
      }
    }
  }
  return iVar1;
}


// ===== 002487b0 FUN_002487b0 =====

undefined4
FUN_002487b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  long lVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int local_cc;
  stat local_c8;
  
  local_cc = -1;
  iVar1 = __xstat(1,"/var/run/nvidia-persistenced/socket",&local_c8);
  if ((iVar1 < 0) || ((local_c8.st_mode & 0xf000) != 0xc000)) {
    uVar4 = 1;
  }
  else {
    lVar2 = FUN_00248340(2,&local_cc);
    if (lVar2 == 0) {
      uVar4 = 7;
    }
    else {
      uVar4 = 8;
      local_c8.st_dev._0_4_ = param_1;
      local_c8.st_dev._4_4_ = param_2;
      local_c8.st_ino._0_4_ = param_3;
      local_c8.st_ino._4_4_ = param_4;
      local_c8.st_nlink._0_4_ = param_5;
      puVar3 = (undefined4 *)FUN_002480f0(&local_c8,lVar2);
      iVar1 = local_cc;
      if (puVar3 != (undefined4 *)0x0) {
        uVar4 = *puVar3;
      }
      (**(code **)(*(long *)(lVar2 + 8) + 0x20))(lVar2);
      if (-1 < iVar1) {
        close(iVar1);
      }
    }
  }
  return uVar4;
}


// ===== 002488e0 FUN_002488e0 =====

undefined4
FUN_002488e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  long lVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int local_cc;
  stat local_c8;
  
  local_cc = -1;
  iVar1 = __xstat(1,"/var/run/nvidia-persistenced/socket",&local_c8);
  if ((iVar1 < 0) || ((local_c8.st_mode & 0xf000) != 0xc000)) {
    uVar4 = 1;
  }
  else {
    lVar2 = FUN_00248340(2,&local_cc);
    if (lVar2 == 0) {
      uVar4 = 7;
    }
    else {
      uVar4 = 8;
      local_c8.st_dev._0_4_ = param_1;
      local_c8.st_dev._4_4_ = param_2;
      local_c8.st_ino._0_4_ = param_3;
      local_c8.st_ino._4_4_ = param_4;
      local_c8.st_nlink._0_4_ = param_5;
      puVar3 = (undefined4 *)FUN_00248150(&local_c8,lVar2);
      iVar1 = local_cc;
      if (puVar3 != (undefined4 *)0x0) {
        uVar4 = *puVar3;
      }
      (**(code **)(*(long *)(lVar2 + 8) + 0x20))(lVar2);
      if (-1 < iVar1) {
        close(iVar1);
      }
    }
  }
  return uVar4;
}


// ===== 00248a10 FUN_00248a10 =====

undefined2 FUN_00248a10(uint param_1)

{
  undefined2 uVar1;
  uint uVar2;
  
  uVar2 = (param_1 ^ (int)param_1 >> 0x1f) - ((int)param_1 >> 0x1f);
  uVar1 = 0xffff;
  if ((int)uVar2 < 100) {
    uVar1 = *(undefined2 *)("/var/run/nvidia-persistenced/soc" + (ulong)uVar2 * 2 + 0x20);
  }
  return uVar1;
}


// ===== 00248a30 FUN_00248a30 =====

void FUN_00248a30(long param_1,int *param_2)

{
  long lVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  long *plVar5;
  
  lVar1 = *(long *)(param_2 + 6);
  piVar2 = *(int **)(param_2 + 8);
  plVar5 = (long *)(param_1 + 8);
  if ((lVar1 != 0) && (plVar5 = (long *)(lVar1 + 0x28), param_2 == *(int **)(lVar1 + 0x20))) {
    plVar5 = (long *)(lVar1 + 0x20);
  }
  *plVar5 = (long)piVar2;
  *(undefined8 *)(piVar2 + 6) = *(undefined8 *)(param_2 + 6);
  lVar1 = *(long *)(piVar2 + 10);
  *(long *)(param_2 + 8) = lVar1;
  if (lVar1 != 0) {
    *(int **)(lVar1 + 0x18) = param_2;
  }
  *(int **)(piVar2 + 10) = param_2;
  iVar3 = 0;
  *(int **)(param_2 + 6) = piVar2;
  if (*(int **)(param_2 + 10) != (int *)0x0) {
    iVar3 = **(int **)(param_2 + 10);
  }
  iVar4 = 0;
  if (*(int **)(param_2 + 8) != (int *)0x0) {
    iVar4 = **(int **)(param_2 + 8);
  }
  if (iVar4 < iVar3) {
    iVar4 = iVar3;
  }
  iVar3 = 0;
  *param_2 = iVar4 + 1;
  if (*(int **)(piVar2 + 10) != (int *)0x0) {
    iVar3 = **(int **)(piVar2 + 10);
  }
  iVar4 = 0;
  if (*(int **)(piVar2 + 8) != (int *)0x0) {
    iVar4 = **(int **)(piVar2 + 8);
  }
  if (iVar4 < iVar3) {
    iVar4 = iVar3;
  }
  *piVar2 = iVar4 + 1;
  return;
}


// ===== 00248ad0 FUN_00248ad0 =====

void FUN_00248ad0(long param_1,int *param_2)

{
  long lVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  long *plVar5;
  
  lVar1 = *(long *)(param_2 + 6);
  piVar2 = *(int **)(param_2 + 10);
  plVar5 = (long *)(param_1 + 8);
  if ((lVar1 != 0) && (plVar5 = (long *)(lVar1 + 0x28), param_2 == *(int **)(lVar1 + 0x20))) {
    plVar5 = (long *)(lVar1 + 0x20);
  }
  *plVar5 = (long)piVar2;
  *(undefined8 *)(piVar2 + 6) = *(undefined8 *)(param_2 + 6);
  lVar1 = *(long *)(piVar2 + 8);
  *(long *)(param_2 + 10) = lVar1;
  if (lVar1 != 0) {
    *(int **)(lVar1 + 0x18) = param_2;
  }
  *(int **)(piVar2 + 8) = param_2;
  iVar3 = 0;
  *(int **)(param_2 + 6) = piVar2;
  if (*(int **)(param_2 + 10) != (int *)0x0) {
    iVar3 = **(int **)(param_2 + 10);
  }
  iVar4 = 0;
  if (*(int **)(param_2 + 8) != (int *)0x0) {
    iVar4 = **(int **)(param_2 + 8);
  }
  if (iVar4 < iVar3) {
    iVar4 = iVar3;
  }
  iVar3 = 0;
  *param_2 = iVar4 + 1;
  if (*(int **)(piVar2 + 10) != (int *)0x0) {
    iVar3 = **(int **)(piVar2 + 10);
  }
  iVar4 = 0;
  if (*(int **)(piVar2 + 8) != (int *)0x0) {
    iVar4 = **(int **)(piVar2 + 8);
  }
  if (iVar4 < iVar3) {
    iVar4 = iVar3;
  }
  *piVar2 = iVar4 + 1;
  return;
}


// ===== 00248b70 FUN_00248b70 =====

void FUN_00248b70(undefined8 param_1,int *param_2,ulong param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined8 uVar6;
  int *piVar7;
  
  if (param_2 == (int *)0x0) {
    return;
  }
  param_3 = param_3 & 0xffffffff;
  uVar6 = 0;
  do {
    while( true ) {
      piVar4 = *(int **)(param_2 + 8);
      piVar7 = *(int **)(param_2 + 10);
      iVar5 = (int)param_3;
      if (piVar4 == (int *)0x0) break;
      iVar3 = *piVar4;
      if (piVar7 != (int *)0x0) goto LAB_00248ba3;
      if (iVar3 == -2) {
        if (iVar5 == 0) goto LAB_00248d29;
        goto LAB_00248c48;
      }
      if (iVar3 == 2) {
LAB_00248c82:
        piVar1 = *(int **)(piVar4 + 10);
        if (*(int **)(piVar4 + 8) != (int *)0x0) {
          iVar3 = **(int **)(piVar4 + 8);
          if (piVar1 != (int *)0x0) goto LAB_00248c96;
LAB_00248c98:
          if ((iVar3 != 1) && ((iVar3 != 0 || ((param_3 & 1) == 0)))) {
            if (iVar3 != -1) goto LAB_00248d0c;
            FUN_00248ad0(param_1);
          }
LAB_00248cb8:
          param_2 = (int *)FUN_00248a30(param_1,param_2);
          piVar4 = *(int **)(param_2 + 8);
          goto LAB_00248c5a;
        }
        iVar3 = 0;
        if (piVar1 != (int *)0x0) {
LAB_00248c96:
          iVar3 = iVar3 - *piVar1;
          goto LAB_00248c98;
        }
        if (iVar5 != 0) goto LAB_00248cb8;
LAB_00248d0c:
        iVar2 = 0;
        if (piVar7 != (int *)0x0) {
          iVar2 = *piVar7;
        }
      }
      else {
LAB_00248d29:
        iVar2 = 0;
      }
LAB_00248bc0:
      if (iVar2 <= *piVar4) {
        iVar2 = *piVar4;
      }
      *param_2 = iVar2 + 1;
      param_2 = *(int **)(param_2 + 6);
      if (param_2 == (int *)0x0) {
        return;
      }
    }
    iVar3 = 0;
    iVar2 = 0;
    if (piVar7 != (int *)0x0) {
LAB_00248ba3:
      iVar2 = *piVar7;
      if (iVar3 - iVar2 == -2) {
        piVar1 = *(int **)(piVar7 + 10);
        if (*(int **)(piVar7 + 8) == (int *)0x0) {
          iVar3 = 0;
          if (piVar1 != (int *)0x0) goto LAB_00248c22;
          if (iVar5 != 0) goto LAB_00248c48;
        }
        else {
          iVar3 = **(int **)(piVar7 + 8);
          if (piVar1 != (int *)0x0) {
LAB_00248c22:
            iVar3 = iVar3 - *piVar1;
          }
          if ((iVar3 != -1) && ((iVar3 != 0 || ((param_3 & 1) == 0)))) {
            if (iVar3 != 1) goto LAB_00248bbb;
            FUN_00248a30(param_1,piVar7);
          }
LAB_00248c48:
          param_2 = (int *)FUN_00248ad0(param_1,param_2);
          piVar4 = *(int **)(param_2 + 8);
LAB_00248c5a:
          piVar7 = *(int **)(param_2 + 10);
          iVar2 = 0;
          if (piVar7 != (int *)0x0) goto LAB_00248bb7;
        }
      }
      else {
        if (iVar3 - iVar2 == 2) {
          if (piVar4 != (int *)0x0) goto LAB_00248c82;
          if (iVar5 == 0) goto LAB_00248bea;
          goto LAB_00248cb8;
        }
LAB_00248bb7:
        iVar2 = *piVar7;
      }
LAB_00248bbb:
      if (piVar4 != (int *)0x0) goto LAB_00248bc0;
    }
LAB_00248bea:
    if (iVar2 < 0) {
      iVar2 = (int)uVar6;
    }
    *param_2 = iVar2 + 1;
    param_2 = *(int **)(param_2 + 6);
    if (param_2 == (int *)0x0) {
      return;
    }
  } while( true );
}


// ===== 00248d40 FUN_00248d40 =====

void FUN_00248d40(undefined8 *param_1,undefined8 param_2)

{
  param_1[1] = 0;
  *param_1 = param_2;
  return;
}


// ===== 00248d50 FUN_00248d50 =====

void FUN_00248d50(undefined1 (*param_1) [16])

{
  *param_1 = (undefined1  [16])0x0;
  return;
}


// ===== 00248d60 FUN_00248d60 =====

long FUN_00248d60(undefined8 *param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = param_1[1];
  if (lVar4 != 0) {
    lVar1 = lVar4;
    lVar4 = 0;
    do {
      while( true ) {
        lVar3 = lVar1;
        iVar2 = (*(code *)*param_1)(param_2,*(undefined8 *)(lVar3 + 8));
        if (iVar2 == 0) {
          return lVar3;
        }
        if (-1 < iVar2) break;
        lVar1 = *(long *)(lVar3 + 0x20);
        lVar4 = lVar3;
        if (*(long *)(lVar3 + 0x20) == 0) {
          return lVar3;
        }
      }
      lVar1 = *(long *)(lVar3 + 0x28);
    } while (*(long *)(lVar3 + 0x28) != 0);
  }
  return lVar4;
}


// ===== 00248dc0 FUN_00248dc0 =====

void FUN_00248dc0(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_2 + 0x18);
  plVar3 = (long *)(param_1 + 8);
  if ((lVar5 != 0) && (plVar3 = (long *)(lVar5 + 0x28), param_2 == *(long *)(lVar5 + 0x20))) {
    plVar3 = (long *)(lVar5 + 0x20);
  }
  lVar2 = *(long *)(param_2 + 0x20);
  lVar1 = *(long *)(param_2 + 0x28);
  if (lVar2 == 0) {
    if (lVar1 == 0) {
      *plVar3 = 0;
    }
    else {
      *plVar3 = lVar1;
      *(undefined8 *)(lVar1 + 0x18) = *(undefined8 *)(param_2 + 0x18);
      lVar5 = *(long *)(param_2 + 0x28);
    }
  }
  else if (lVar1 == 0) {
    *plVar3 = lVar2;
    *(undefined8 *)(lVar2 + 0x18) = *(undefined8 *)(param_2 + 0x18);
    lVar5 = *(long *)(param_2 + 0x20);
  }
  else {
    do {
      lVar2 = lVar1;
      lVar1 = *(long *)(lVar2 + 0x20);
    } while (*(long *)(lVar2 + 0x20) != 0);
    lVar5 = *(long *)(lVar2 + 0x18);
    plVar4 = (long *)(param_1 + 8);
    if ((lVar5 != 0) && (plVar4 = (long *)(lVar5 + 0x28), lVar2 == *(long *)(lVar5 + 0x20))) {
      plVar4 = (long *)(lVar5 + 0x20);
    }
    lVar5 = *(long *)(lVar2 + 0x28);
    *plVar4 = lVar5;
    if (lVar5 != 0) {
      *(undefined8 *)(lVar5 + 0x18) = *(undefined8 *)(lVar2 + 0x18);
    }
    lVar5 = *(long *)(lVar2 + 0x18);
    *plVar3 = lVar2;
    *(undefined8 *)(lVar2 + 0x18) = *(undefined8 *)(param_2 + 0x18);
    lVar1 = *(long *)(param_2 + 0x20);
    if (lVar5 == param_2) {
      lVar5 = lVar2;
    }
    *(long *)(lVar2 + 0x20) = lVar1;
    *(long *)(lVar1 + 0x18) = lVar2;
    lVar1 = *(long *)(param_2 + 0x28);
    *(long *)(lVar2 + 0x28) = lVar1;
    if (lVar1 != 0) {
      *(long *)(lVar1 + 0x18) = lVar2;
    }
  }
  *(undefined8 *)(param_2 + 0x18) = 0;
  *(undefined8 *)(param_2 + 0x20) = 0;
  *(undefined8 *)(param_2 + 0x28) = 0;
  FUN_00248b70(param_1,lVar5,1);
  return;
}


// ===== 00248ef0 FUN_00248ef0 =====

long FUN_00248ef0(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 8);
  lVar2 = 0;
  while (lVar1 = lVar3, lVar1 != 0) {
    lVar2 = lVar1;
    lVar3 = *(long *)(lVar1 + 0x20);
  }
  return lVar2;
}


// ===== 00248f10 FUN_00248f10 =====

long FUN_00248f10(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_1 + 0x28);
  if (*(long *)(param_1 + 0x28) == 0) {
    lVar1 = *(long *)(param_1 + 0x18);
    if (*(long *)(param_1 + 0x18) == 0) {
      lVar2 = 0;
    }
    else {
      while (lVar2 = lVar1, *(long *)(lVar2 + 0x20) != param_1) {
        lVar1 = *(long *)(lVar2 + 0x18);
        param_1 = lVar2;
        if (*(long *)(lVar2 + 0x18) == 0) {
          return 0;
        }
      }
    }
  }
  else {
    do {
      lVar2 = lVar1;
      lVar1 = *(long *)(lVar2 + 0x20);
    } while (*(long *)(lVar2 + 0x20) != 0);
  }
  return lVar2;
}


// ===== 00248f70 FUN_00248f70 =====

ulong FUN_00248f70(ulong param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = (ulong)(param_2 < param_1);
  if (param_1 < param_2) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ===== 00248f90 FUN_00248f90 =====

void FUN_00248f90(long param_1,code *param_2,undefined8 param_3)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  
  for (; param_1 != 0; param_1 = *(long *)(param_1 + 0x28)) {
    for (lVar1 = *(long *)(param_1 + 0x20); lVar1 != 0; lVar1 = *(long *)(lVar1 + 0x28)) {
      for (lVar2 = *(long *)(lVar1 + 0x20); lVar2 != 0; lVar2 = *(long *)(lVar2 + 0x28)) {
        for (lVar3 = *(long *)(lVar2 + 0x20); lVar3 != 0; lVar3 = *(long *)(lVar3 + 0x28)) {
          for (lVar4 = *(long *)(lVar3 + 0x20); lVar4 != 0; lVar4 = *(long *)(lVar4 + 0x28)) {
            for (lVar5 = *(long *)(lVar4 + 0x20); lVar5 != 0; lVar5 = *(long *)(lVar5 + 0x28)) {
              for (lVar6 = *(long *)(lVar5 + 0x20); lVar6 != 0; lVar6 = *(long *)(lVar6 + 0x28)) {
                for (lVar7 = *(long *)(lVar6 + 0x20); lVar7 != 0; lVar7 = *(long *)(lVar7 + 0x28)) {
                  for (lVar8 = *(long *)(lVar7 + 0x20); lVar8 != 0; lVar8 = *(long *)(lVar8 + 0x28))
                  {
                    FUN_00248f90(*(undefined8 *)(lVar8 + 0x20),param_2,param_3);
                    (*param_2)(param_3,*(undefined8 *)(lVar8 + 0x10));
                  }
                  (*param_2)(param_3,*(undefined8 *)(lVar7 + 0x10));
                }
                (*param_2)(param_3,*(undefined8 *)(lVar6 + 0x10));
              }
              (*param_2)(param_3,*(undefined8 *)(lVar5 + 0x10));
            }
            (*param_2)(param_3,*(undefined8 *)(lVar4 + 0x10));
          }
          (*param_2)(param_3,*(undefined8 *)(lVar3 + 0x10));
        }
        (*param_2)(param_3,*(undefined8 *)(lVar2 + 0x10));
      }
      (*param_2)(param_3,*(undefined8 *)(lVar1 + 0x10));
    }
    (*param_2)(param_3,*(undefined8 *)(param_1 + 0x10));
  }
  return;
}


// ===== 00249150 FUN_00249150 =====

void FUN_00249150(undefined8 param_1)

{
  FUN_00248d40(param_1,FUN_00248f70);
  return;
}


// ===== 00249160 thunk_FUN_00248d50 =====

void thunk_FUN_00248d50(undefined1 (*param_1) [16])

{
  *param_1 = (undefined1  [16])0x0;
  return;
}


// ===== 00249170 FUN_00249170 =====

void FUN_00249170(long param_1,code *param_2,undefined8 param_3)

{
  long lVar1;
  
  for (lVar1 = *(long *)(param_1 + 8); lVar1 != 0; lVar1 = *(long *)(lVar1 + 0x28)) {
    FUN_00248f90(*(undefined8 *)(lVar1 + 0x20),param_2,param_3);
    (*param_2)(param_3,*(undefined8 *)(lVar1 + 0x10));
  }
  return;
}


// ===== 002491c0 FUN_002491c0 =====

long * FUN_002491c0(undefined8 param_1,long param_2,long param_3)

{
  long lVar1;
  long *plVar2;
  
  lVar1 = FUN_00248d60();
  plVar2 = (long *)0x0;
  if (((lVar1 != 0) && (plVar2 = *(long **)(lVar1 + 0x10), plVar2 != (long *)0x0)) &&
     ((ulong)(param_2 + param_3) < (ulong)(plVar2[1] + *plVar2))) {
    plVar2 = (long *)0x0;
  }
  return plVar2;
}


// ===== 00249200 FUN_00249200 =====

void FUN_00249200(undefined8 param_1,long param_2)

{
  FUN_00248dc0(param_1,param_2 + 0x10);
  return;
}


// ===== 00249210 FUN_00249210 =====

void FUN_00249210(void *param_1,void *param_2)

{
  memcmp(param_1,param_2,0x10);
  return;
}


// ===== 00249220 FUN_00249220 =====

void FUN_00249220(undefined8 param_1)

{
  FUN_00248d40(param_1,FUN_00249210);
  return;
}


// ===== 00249230 FUN_00249230 =====

bool FUN_00249230(long param_1)

{
  return *(long *)(param_1 + 8) == 0;
}


// ===== 00249240 FUN_00249240 =====

undefined8 FUN_00249240(undefined8 param_1,long param_2)

{
  long lVar1;
  
  if (param_2 == 0) {
    lVar1 = FUN_00248ef0();
  }
  else {
    lVar1 = FUN_00248f10(param_2 + 0x18);
  }
  if (lVar1 != 0) {
    return *(undefined8 *)(lVar1 + 0x10);
  }
  return 0;
}


// ===== 00249270 FUN_00249270 =====

void FUN_00249270(undefined8 param_1)

{
  void *__ptr;
  
  while( true ) {
    __ptr = (void *)FUN_00249240(param_1,0);
    if (__ptr == (void *)0x0) break;
    FUN_00248dc0(param_1);
    if (*(long *)((long)__ptr + 0x48) != 0) {
      thunk_FUN_00248d50();
      free(*(void **)((long)__ptr + 0x48));
    }
    free(__ptr);
  }
  FUN_00248d50(param_1);
  return;
}


// ===== 002492d0 FUN_002492d0 =====

void FUN_002492d0(char *param_1,long param_2)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = *(uint *)(param_2 + 0x40);
  bVar2 = true;
  if (*param_1 == '\0') {
    if (uVar1 < 3) {
      if (uVar1 == 0) {
        bVar2 = false;
      }
    }
    else if (uVar1 != 4) {
      bVar2 = uVar1 - 2 < 5;
    }
  }
  *param_1 = bVar2;
  return;
}


// ===== 00249310 FUN_00249310 =====

int FUN_00249310(void)

{
  int iVar1;
  
  iVar1 = FUN_00242160();
  if (iVar1 != 1) {
    iVar1 = FUN_00242530(&DAT_002dd668,0,0);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  iVar1 = FUN_002420f0(0);
  if (iVar1 != 1) {
    FUN_00242530(&DAT_002dd668,&DAT_002dd66b,0);
  }
  return 0;
}


// ===== 00249380 FUN_00249380 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00249380(int param_1,ulong param_2,undefined8 param_3)

{
  int iVar1;
  int *piVar2;
  
  while( true ) {
    iVar1 = ioctl(param_1,param_2,param_3);
    if (-1 < iVar1) {
      return iVar1;
    }
    piVar2 = __errno_location();
    if ((*piVar2 != 4) && (*piVar2 != 0xb)) break;
    LOCK();
    _DAT_01217e88 = _DAT_01217e88 + 1;
    UNLOCK();
  }
  return iVar1;
}


// ===== 002493e0 FUN_002493e0 =====

void * FUN_002493e0(void *param_1,size_t param_2,int param_3,uint param_4,int param_5,
                   __off_t param_6)

{
  int iVar1;
  void *__addr;
  undefined4 *puVar2;
  void *local_58;
  size_t local_50;
  undefined8 local_48;
  
  while( true ) {
    __addr = mmap(param_1,param_2,param_3,param_4,param_5,param_6);
    if (__addr == (void *)0xffffffffffffffff) {
      return (void *)0xffffffffffffffff;
    }
    if (param_5 < 0) {
      return __addr;
    }
    local_48 = 0;
    local_58 = __addr;
    local_50 = param_2;
    puVar2 = (undefined4 *)FUN_0024a050();
    iVar1 = FUN_00249380(*puVar2,0x48,&local_58);
    if (iVar1 == -1) {
      if ((param_4 & 0x10) == 0) {
        munmap(__addr,param_2);
      }
      return (void *)0xffffffffffffffff;
    }
    if ((int)local_48 != 0x1e) break;
    if ((param_4 & 0x10) == 0) {
      munmap(__addr,param_2);
    }
  }
  return __addr;
}


// ===== 002494c0 FUN_002494c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong FUN_002494c0(long param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  ulong uVar5;
  undefined8 local_28;
  ulong local_20;
  
  local_28 = *(undefined8 *)(param_1 + 0x80);
  local_20 = 0;
  puVar3 = (undefined4 *)FUN_0024a050();
  uVar1 = *puVar3;
  while( true ) {
    iVar2 = FUN_00249380(uVar1,0x30000001,&local_28);
    if (iVar2 != 0) {
      piVar4 = __errno_location();
      uVar5 = FUN_00248a10(*piVar4);
      if ((int)uVar5 == 0) {
        return uVar5;
      }
      return 0x4b;
    }
    if ((int)local_20 != 3) break;
    LOCK();
    _DAT_01217e80 = _DAT_01217e80 + 1;
    UNLOCK();
  }
  return local_20 & 0xffffffff;
}


// ===== 00249540 FUN_00249540 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00249540(long param_1)

{
  char cVar1;
  int iVar2;
  int __fd;
  int iVar3;
  int *piVar4;
  int *piVar5;
  char local_41;
  int local_40;
  int local_3c;
  
  if (param_1 != 0) {
    return 0x29;
  }
  FUN_0024a080();
  iVar2 = 0x40;
  piVar4 = (int *)FUN_0024a050();
  local_41 = '\0';
  if (piVar4[3] == 0) goto LAB_00249600;
  iVar2 = 0x17;
  cVar1 = FUN_00249230(piVar4 + 0xc);
  if (cVar1 == '\0') goto LAB_00249600;
  iVar2 = 0x68;
  FUN_00249170(piVar4 + 4,FUN_002492d0,&local_41);
  if (local_41 != '\0') goto LAB_00249600;
  iVar2 = FUN_00249310();
  if (iVar2 == 0) {
    do {
      __fd = open("/dev/nvidia-uvm",0x80002,0);
      if (-1 < __fd) {
        iVar2 = 0x59;
        iVar3 = dup3(__fd,*piVar4,0x80000);
        if (iVar3 != *piVar4) goto LAB_00249638;
        close(__fd);
        if (piVar4[1] < 0) goto LAB_002496b8;
        goto LAB_00249670;
      }
      piVar5 = __errno_location();
      iVar2 = *piVar5;
    } while ((iVar2 == 4) || (iVar2 == 0xb));
    goto LAB_002495f1;
  }
  goto LAB_002495f5;
LAB_002496b8:
  iVar2 = FUN_002494c0(piVar4);
  if ((iVar2 == 0) && (iVar3 = piVar4[1], -1 < iVar3)) {
    local_40 = *piVar4;
    local_3c = 0;
    while (iVar2 = FUN_00249380(iVar3,0x4b,&local_40), iVar2 == 0) {
      iVar2 = local_3c;
      if (local_3c != 3) goto LAB_00249706;
      LOCK();
      _DAT_01217e80 = _DAT_01217e80 + 1;
      UNLOCK();
    }
    piVar5 = __errno_location();
    iVar2 = FUN_00248a10(*piVar5);
LAB_00249706:
    if (iVar2 != 0) {
      close(piVar4[1]);
    }
  }
LAB_00249638:
  close(__fd);
  goto LAB_00249600;
  while( true ) {
    piVar5 = __errno_location();
    iVar2 = *piVar5;
    if ((iVar2 != 4) && (iVar2 != 0xb)) break;
LAB_00249670:
    __fd = open("/dev/nvidia-uvm",0x80002,0);
    if (-1 < __fd) {
      iVar2 = 0x59;
      iVar3 = dup3(__fd,piVar4[1],0x80000);
      if (iVar3 == piVar4[1]) goto LAB_002496b8;
      goto LAB_00249638;
    }
  }
LAB_002495f1:
  if (iVar2 < 1) {
    *piVar5 = 1;
  }
LAB_002495f5:
  iVar2 = 0x4b;
LAB_00249600:
  FUN_0024a0a0();
  return iVar2;
}


// ===== 00249740 FUN_00249740 =====

undefined8 FUN_00249740(undefined4 *param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  
  if (param_1 != (undefined4 *)0x0) {
    lVar1 = FUN_0024a050();
    uVar2 = 0x40;
    if (*(int *)(lVar1 + 0xc) != 0) {
      puVar3 = (undefined4 *)FUN_0024a050();
      *param_1 = *puVar3;
      uVar2 = 0;
    }
    return uVar2;
  }
  return 0x1f;
}


// ===== 00249790 FUN_00249790 =====

undefined8 FUN_00249790(undefined4 *param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    lVar1 = FUN_0024a050();
    uVar2 = 0x40;
    if (*(int *)(lVar1 + 0xc) != 0) {
      lVar1 = FUN_0024a050();
      uVar2 = 0x56;
      if (-1 < *(int *)(lVar1 + 4)) {
        lVar1 = FUN_0024a050();
        *param_1 = *(undefined4 *)(lVar1 + 4);
        uVar2 = 0;
      }
    }
    return uVar2;
  }
  return 0x1f;
}


// ===== 002497f0 FUN_002497f0 =====

ulong FUN_002497f0(undefined1 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  ulong uVar4;
  ulong local_20;
  
  local_20 = 0;
  puVar2 = (undefined4 *)FUN_0024a050();
  iVar1 = FUN_00249380(*puVar2,0x27,&local_20);
  if (iVar1 != -1) {
    *param_1 = (undefined1)local_20;
    return local_20 >> 0x20;
  }
  piVar3 = __errno_location();
  uVar4 = FUN_00248a10(*piVar3);
  return uVar4;
}


// ===== 00249850 FUN_00249850 =====

ulong FUN_00249850(undefined8 param_1,ulong param_2)

{
  int iVar1;
  long lVar2;
  undefined4 *puVar3;
  int *piVar4;
  ulong uVar5;
  undefined8 local_48;
  ulong local_40;
  ulong local_38;
  
  lVar2 = FUN_0024a050();
  local_48 = param_1;
  if ((*(char *)(lVar2 + 0x70) == '\0') || (0x244 < *(uint *)(lVar2 + 0x74))) {
    local_40 = 0;
    puVar3 = (undefined4 *)FUN_0024a050();
    iVar1 = FUN_00249380(*puVar3,0x22,&local_48);
    if (iVar1 == 0) {
      return local_40 & 0xffffffff;
    }
  }
  else {
    local_38 = 0;
    local_40 = param_2;
    puVar3 = (undefined4 *)FUN_0024a050();
    iVar1 = FUN_00249380(*puVar3,0x22,&local_48);
    if (iVar1 == 0) {
      return local_38 & 0xffffffff;
    }
  }
  piVar4 = __errno_location();
  uVar5 = FUN_00248a10(*piVar4);
  return uVar5;
}


// ===== 00249910 FUN_00249910 =====

int FUN_00249910(undefined8 *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  int *piVar6;
  
  lVar4 = FUN_0024a050();
  uVar1 = *(uint *)(param_1 + 8);
  if (uVar1 < 3) {
    iVar2 = 0;
    if (uVar1 == 0) goto LAB_00249937;
LAB_00249998:
    lVar5 = FUN_002493e0(*param_1,param_1[1],0,0x32,0xffffffff,0);
    if (lVar5 == -1) {
      piVar6 = __errno_location();
      iVar2 = FUN_00248a10(*piVar6);
      if ((*(int *)(param_1 + 8) - 2U < 5) &&
         (iVar3 = FUN_00249850(*param_1,param_1[1]), iVar2 == 0)) {
        iVar2 = iVar3;
      }
      goto LAB_00249937;
    }
    uVar1 = *(uint *)(param_1 + 8);
  }
  else if (uVar1 == 4) goto LAB_00249998;
  if (uVar1 - 2 < 5) {
    iVar2 = FUN_00249850(*param_1,param_1[1]);
  }
  else {
    iVar2 = 0;
  }
LAB_00249937:
  if (*(char *)(lVar4 + 0x88) != '\0') {
    (**(code **)(lVar4 + 0xb8))(*param_1,param_1[1]);
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return iVar2;
}


// ===== 00249a10 FUN_00249a10 =====

undefined8 FUN_00249a10(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  void *__ptr;
  long lVar4;
  undefined8 *__ptr_00;
  undefined4 *puVar5;
  int *piVar6;
  undefined8 uVar7;
  
  piVar3 = (int *)FUN_0024a050();
  if (piVar3[3] == 0) {
    return 0x40;
  }
  iVar2 = piVar3[3] + -1;
  piVar3[3] = iVar2;
  if (0 < iVar2) {
    return 0;
  }
  free(*(void **)(piVar3 + 0x16));
  free(*(void **)(piVar3 + 0x18));
  while (__ptr = (void *)FUN_002491c0(piVar3 + 4,0,0xffffffffffffffff), __ptr != (void *)0x0) {
    FUN_00249910(__ptr);
    lVar4 = FUN_0024a050();
    FUN_00249200(lVar4 + 0x10);
    free(__ptr);
  }
  thunk_FUN_00248d50(piVar3 + 4);
  while (__ptr_00 = (undefined8 *)FUN_002491c0(piVar3 + 8,0,0xffffffffffffffff),
        __ptr_00 != (undefined8 *)0x0) {
    lVar4 = FUN_0024a050();
    FUN_00249200(lVar4 + 0x20,__ptr_00);
    FUN_00292e30(*__ptr_00,__ptr_00[1],2);
    free(__ptr_00);
  }
  thunk_FUN_00248d50(piVar3 + 8);
  FUN_00249270(piVar3 + 0xc);
  puVar5 = (undefined4 *)FUN_0024a050();
  iVar2 = FUN_00249380(*puVar5,0x30000002,0);
  if (iVar2 != 0) {
    piVar6 = __errno_location();
    uVar7 = 0xffff;
    iVar2 = FUN_00248a10(*piVar6);
    if (iVar2 != 0) goto LAB_00249b30;
  }
  uVar7 = 0;
LAB_00249b30:
  if (piVar3[1] < 0) {
    cVar1 = (char)piVar3[2];
  }
  else {
    iVar2 = close(piVar3[1]);
    if (iVar2 == -1) {
      uVar7 = 0xffff;
    }
    cVar1 = (char)piVar3[2];
  }
  if ((cVar1 != '\0') && (iVar2 = close(*piVar3), iVar2 == -1)) {
    uVar7 = 0xffff;
  }
  piVar3[0] = -1;
  piVar3[1] = -1;
  *(undefined1 *)(piVar3 + 0x1c) = 0;
  return uVar7;
}


// ===== 00249bb0 FUN_00249bb0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00249bb0(int param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  int iVar3;
  int *piVar4;
  long lVar5;
  ulong uVar6;
  void *pvVar7;
  ulong uVar8;
  int *piVar9;
  ulong uVar10;
  uint uVar11;
  ulong uVar12;
  int local_40;
  int local_3c;
  
  piVar4 = (int *)FUN_0024a050();
  FUN_0024a080();
  iVar3 = piVar4[3];
  piVar4[3] = iVar3 + 1;
  if (iVar3 == 0) {
    *(undefined1 *)(piVar4 + 0x10) = 0;
    iVar3 = FUN_002925f0();
    if (iVar3 == 0) goto LAB_00249c3d;
    lVar5 = FUN_00292660();
    *(long *)(piVar4 + 0x1a) = lVar5;
    if (lVar5 != 0) {
      uVar6 = FUN_00292620();
      *(ulong *)(piVar4 + 0x12) = uVar6;
      if (uVar6 != 0) {
        uVar11 = (int)uVar6 - 1;
        uVar12 = uVar6 & 0xffffffff;
        uVar10 = (ulong)(uVar11 >> 6);
        do {
          uVar2 = *(ulong *)(*(long *)(piVar4 + 0x1a) + uVar10 * 8);
          if (uVar2 != 0) {
            uVar8 = 0x3f;
            do {
              iVar3 = (int)uVar8;
              if ((uVar2 >> (uVar8 & 0x3f) & 1) != 0) {
                uVar12 = (ulong)(uint)((int)uVar10 * 0x40 + iVar3);
                goto LAB_00249ce8;
              }
              uVar8 = (ulong)(iVar3 - 1);
            } while (iVar3 != 0);
          }
          uVar10 = uVar10 - 1;
        } while ((int)uVar10 != -1);
LAB_00249ce8:
        *(ulong *)(piVar4 + 0x14) = uVar12;
        if (uVar12 < uVar6) {
          pvVar7 = calloc(((ulong)uVar11 + 0x40 >> 6) << 3,1);
          if (pvVar7 == (void *)0x0) {
            piVar4[0x16] = 0;
            piVar4[0x17] = 0;
            iVar3 = 0x51;
          }
          else {
            *(void **)(piVar4 + 0x16) = pvVar7;
            lVar5 = *(long *)(piVar4 + 0x12);
            pvVar7 = malloc(lVar5 - 1U);
            *(void **)(piVar4 + 0x18) = pvVar7;
            if (pvVar7 == (void *)0x0) {
              iVar3 = 0x51;
            }
            else {
              memset(pvVar7,0,lVar5 - 1U);
              iVar3 = FUN_002926a0(&local_40);
              if (iVar3 == 0) {
                memset(*(void **)(piVar4 + 0x16),0,
                       ((ulong)((int)*(undefined8 *)(piVar4 + 0x12) - 1) + 0x40 >> 6) << 3);
                *(undefined1 *)(piVar4 + 0x10) = 1;
              }
              else {
                piVar9 = __errno_location();
                if ((*piVar9 != 1) && (iVar3 = FUN_00248a10(), iVar3 != 0)) goto LAB_00249bf2;
              }
LAB_00249c3d:
              iVar3 = FUN_00249310();
              if (iVar3 == 0) {
                if (param_1 == -1) {
                  do {
                    iVar3 = open("/dev/nvidia-uvm",0x80002,0);
                    if (-1 < iVar3) {
                      *piVar4 = iVar3;
                      goto LAB_00249e60;
                    }
                    piVar9 = __errno_location();
                    iVar1 = *piVar9;
                  } while ((iVar1 == 4) || (iVar1 == 0xb));
                  if (iVar1 < 1) {
                    *piVar9 = 1;
                    iVar3 = 0x4b;
                    *piVar4 = -1;
                  }
                  else {
                    iVar3 = 0x4b;
                    *piVar4 = -iVar1;
                  }
                }
                else {
                  *piVar4 = param_1;
                  *(undefined1 *)(piVar4 + 2) = 0;
                  *(long *)(piVar4 + 0x20) = param_2;
                  iVar3 = FUN_002494c0(piVar4);
                  if (iVar3 == 0) goto LAB_00249c71;
                }
              }
              else {
                iVar3 = 0x4b;
              }
            }
          }
          goto LAB_00249bf2;
        }
      }
    }
    iVar3 = 0x40;
  }
  else {
    if (param_1 == -1) {
      if ((char)piVar4[2] != '\0') goto LAB_00249c16;
    }
    else if (*piVar4 == param_1) {
LAB_00249c16:
      iVar3 = 0x1f;
      if (*(long *)(piVar4 + 0x20) == param_2) goto LAB_00249c25;
      goto LAB_00249bf2;
    }
    iVar3 = 0x1f;
  }
  goto LAB_00249bf2;
  while( true ) {
    piVar9 = __errno_location();
    iVar1 = *piVar9;
    if ((iVar1 != 4) && (iVar1 != 0xb)) break;
LAB_00249e60:
    iVar3 = open("/dev/nvidia-uvm",0x80002,0);
    if (-1 < iVar3) {
      piVar4[1] = iVar3;
      *(undefined1 *)(piVar4 + 2) = 1;
      *(long *)(piVar4 + 0x20) = param_2;
      iVar3 = FUN_002494c0(piVar4);
      if (iVar3 != 0) goto LAB_00249bf2;
      local_40 = *piVar4;
      iVar1 = piVar4[1];
      local_3c = 0;
      goto LAB_00249ed0;
    }
  }
  if (iVar1 < 1) {
    *piVar9 = 1;
    iVar3 = 0x4b;
    piVar4[1] = -1;
  }
  else {
    iVar3 = 0x4b;
    piVar4[1] = -iVar1;
  }
  goto LAB_00249bf2;
LAB_00249ed0:
  iVar3 = FUN_00249380(iVar1,0x4b,&local_40);
  if (iVar3 != 0) goto LAB_00249f84;
  iVar3 = local_3c;
  if (local_3c != 3) goto LAB_00249ef2;
  LOCK();
  _DAT_01217e80 = _DAT_01217e80 + 1;
  UNLOCK();
  goto LAB_00249ed0;
LAB_00249f84:
  piVar9 = __errno_location();
  iVar3 = FUN_00248a10(*piVar9);
LAB_00249ef2:
  if (iVar3 == 0x10006) {
    close(piVar4[1]);
    piVar4[1] = -1;
    FUN_00249150(piVar4 + 8);
    FUN_00249150(piVar4 + 4);
    FUN_00249220(piVar4 + 0xc);
LAB_00249c25:
    iVar3 = 0;
    goto LAB_00249bf7;
  }
  if (iVar3 == 0) {
LAB_00249c71:
    FUN_00249150(piVar4 + 8);
    FUN_00249150(piVar4 + 4);
    FUN_00249220(piVar4 + 0xc);
    goto LAB_00249bf7;
  }
  close(piVar4[1]);
  piVar4[1] = -1;
LAB_00249bf2:
  FUN_00249a10();
LAB_00249bf7:
  FUN_0024a0a0();
  return iVar3;
}


// ===== 00249fc0 FUN_00249fc0 =====

undefined4 FUN_00249fc0(void)

{
  undefined4 uVar1;
  
  FUN_0024a080();
  uVar1 = FUN_00249a10();
  FUN_0024a0a0();
  return uVar1;
}


// ===== 00249ff0 FUN_00249ff0 =====

undefined8 FUN_00249ff0(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    uVar1 = 0x40;
    pthread_mutex_lock((pthread_mutex_t *)&DAT_01217ea0);
    if (DAT_01217ec8 == 0) {
      uVar1 = 0;
      DAT_01217ec8 = param_1;
    }
    pthread_mutex_unlock((pthread_mutex_t *)&DAT_01217ea0);
    return uVar1;
  }
  return 0x1f;
}


// ===== 0024a050 FUN_0024a050 =====

long FUN_0024a050(void)

{
  if (DAT_01217ec8 != 0) {
    return DAT_01217ec8;
  }
  FUN_00249ff0(&DAT_003804f8);
  return DAT_01217ec8;
}


// ===== 0024a080 FUN_0024a080 =====

void FUN_0024a080(void)

{
  long lVar1;
  
  lVar1 = FUN_0024a050();
  pthread_rwlock_wrlock((pthread_rwlock_t *)(lVar1 + -0x38));
  return;
}


// ===== 0024a0a0 FUN_0024a0a0 =====

void FUN_0024a0a0(void)

{
  long lVar1;
  
  lVar1 = FUN_0024a050();
  pthread_rwlock_unlock((pthread_rwlock_t *)(lVar1 + -0x38));
  return;
}


// ===== 0024a0c0 FUN_0024a0c0 =====

undefined8 FUN_0024a0c0(int *param_1,int *param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  
  if (((param_1 != (int *)0x0) && (param_2 != (int *)0x0)) && (param_3 - 1U < 0x43)) {
    if ((param_3 == 0x12) && (param_4 == 3)) {
      if (param_5 == 5) {
        param_5 = 7;
      }
    }
    else if (param_4 == 5) {
      if (param_5 - 5U < 3) {
        iVar1 = *(int *)(&DAT_002dd670 + (ulong)(param_5 - 5U) * 4);
        *param_1 = 6;
        *param_2 = iVar1;
        return 0;
      }
    }
    else if (param_4 == 8) {
      *param_1 = 8;
      if (param_5 == 2) {
        param_5 = 0;
      }
      *param_2 = param_5;
      return 0;
    }
    *param_1 = param_4;
    *param_2 = param_5;
    return 0;
  }
  return 0x1f;
}


// ===== 0024a160 FUN_0024a160 =====

undefined8 FUN_0024a160(long param_1,long param_2,undefined1 (*param_3) [16])

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  long *plVar5;
  ulong uVar6;
  undefined8 uVar7;
  long lVar8;
  int *piVar9;
  
  lVar8 = 0xc0;
  *param_3 = (undefined1  [16])0x0;
  param_3[1] = (undefined1  [16])0x0;
  uVar6 = 0;
  plVar5 = &DAT_002ddae8;
  while ((param_1 != lVar8 || (param_2 != *plVar5))) {
    uVar4 = (int)uVar6 + 1;
    uVar6 = (ulong)uVar4;
    if (uVar4 == 0x4b) {
      return 0x56;
    }
    lVar8 = plVar5[2];
    plVar5 = plVar5 + 3;
  }
  piVar9 = &DAT_002dd694;
  iVar1 = *(int *)((long)&DAT_002ddaf0 + uVar6 * 0x18 + 4);
  *(undefined8 *)*param_3 = (&DAT_002ddaf0)[uVar6 * 3];
  uVar6 = 0;
  if (iVar1 != 0xb) {
    do {
      uVar4 = (int)uVar6 + 1;
      uVar6 = (ulong)uVar4;
      if (uVar4 == 0x38) {
        return 0xffff;
      }
      iVar2 = *piVar9;
      piVar9 = piVar9 + 5;
    } while (iVar1 != iVar2);
  }
  uVar3 = (&DAT_002dd684)[uVar6 * 5];
  *(undefined8 *)param_3[1] = *(undefined8 *)(&DAT_002dd684 + uVar6 * 5);
  *(undefined8 *)(param_3[1] + 8) = *(undefined8 *)((long)&DAT_002dd68c + uVar6 * 0x14);
  uVar7 = FUN_0024a0c0(*param_3 + 8,*param_3 + 0xc,iVar1,uVar3,(&DAT_002dd688)[uVar6 * 5]);
  return uVar7;
}


// ===== 0024a230 FUN_0024a230 =====

int FUN_0024a230(uint param_1,void *param_2)

{
  void *__src;
  uint uVar1;
  long lVar2;
  ulong uVar3;
  char *__format;
  ulong uVar4;
  int iVar5;
  undefined1 local_3a8 [32];
  undefined1 local_388 [336];
  undefined1 local_238 [520];
  
  uVar4 = (ulong)param_1;
  FUN_0024c810(local_388,&DAT_0032a1c0,local_238,0x200);
  uVar1 = FUN_0024ca60(local_388,&DAT_0032a1e0);
  if (uVar1 == 0) {
    uVar1 = FUN_0024d1a0(local_388,&DAT_0032a200,uVar4);
    if (uVar1 == 0) {
      uVar1 = FUN_0024d1a0(local_388,&DAT_0032a220,&DAT_01000054);
      if (uVar1 != 0) {
        syslog(3,"failed to encode Fabric Manager command type %d version %d with error %d\n",
               (ulong)param_1,&DAT_01000054,(ulong)uVar1);
        fprintf(*(FILE **)PTR_stderr_0032efe0,
                "failed to encode Fabric Manager command type %d version %d with error %d\n",
                (ulong)param_1,&DAT_01000054,(ulong)uVar1);
        return -2;
      }
      uVar1 = FUN_0024ca60(local_388,&DAT_0032a280);
      if (uVar1 == 0) {
        uVar1 = FUN_0024d1c0(local_388,&DAT_002dec80,param_2,0x54);
        if (uVar1 == 0) {
          FUN_0024d110(local_388);
          FUN_0024d110(local_388);
          uVar1 = FUN_0024b9d0(local_3a8,&DAT_0032a1c0);
          if (uVar1 != 0) {
            syslog(3,"failed to create Fabric Manager response message with error %d\n",(ulong)uVar1
                  );
            fprintf(*(FILE **)PTR_stderr_0032efe0,
                    "failed to create Fabric Manager response message with error %d\n",(ulong)uVar1)
            ;
            return -2;
          }
          uVar1 = FUN_0024b290(local_388,local_3a8);
          if (uVar1 != 0) {
            syslog(3,
                   "failed to exchange message with running Fabric Manager instance with error %d\n"
                   ,(ulong)uVar1);
            fprintf(*(FILE **)PTR_stderr_0032efe0,
                    "failed to exchange message with running Fabric Manager instance with error %d\n"
                    ,(ulong)uVar1);
            FUN_0024ba60(local_3a8);
            if (0xca < uVar1 + 0xca) {
              return -2;
            }
            return (int)(char)(&DAT_002de7c0)[uVar1 + 0xca];
          }
          lVar2 = FUN_0024c790(local_3a8,&DAT_0032a1a0);
          if (lVar2 == 0) {
            syslog(3,"received Fabric Manager response does not have command arg\n");
            fwrite("received Fabric Manager response does not have command arg\n",1,0x3b,
                   *(FILE **)PTR_stderr_0032efe0);
            FUN_0024ba60(local_3a8);
            return -2;
          }
          lVar2 = FUN_0024c670(lVar2,&DAT_002dec80);
          if (lVar2 != 0) {
            __src = (void *)**(undefined8 **)(lVar2 + 8);
            if (__src != (void *)0x0) {
              memcpy(param_2,__src,(ulong)*(uint *)(*(undefined8 **)(lVar2 + 8) + 1));
              lVar2 = FUN_0024c790(local_3a8,&DAT_0032a1b0);
              if (lVar2 == 0) {
                syslog(3,"received Fabric Manager response does not have command response\n");
                fwrite("received Fabric Manager response does not have command response\n",1,0x40,
                       *(FILE **)PTR_stderr_0032efe0);
                FUN_0024ba60(local_3a8);
                return -2;
              }
              lVar2 = FUN_0024c670(lVar2,&DAT_0032a240);
              if (lVar2 != 0) {
                iVar5 = -2;
                uVar1 = **(int **)(lVar2 + 8) + 0xca;
                if (uVar1 < 0xcb) {
                  iVar5 = (int)(char)(&DAT_002de7c0)[uVar1];
                }
                FUN_0024ba60(local_3a8);
                return iVar5;
              }
              syslog(3,"received Fabric Manager response does not have command status\n");
              fwrite("received Fabric Manager response does not have command status\n",1,0x3e,
                     *(FILE **)PTR_stderr_0032efe0);
              FUN_0024ba60(local_3a8);
              return -2;
            }
          }
          syslog(3,"received Fabric Manager response does not have empty arg\n");
          fwrite("received Fabric Manager response does not have empty arg\n",1,0x39,
                 *(FILE **)PTR_stderr_0032efe0);
          FUN_0024ba60(local_3a8);
          return -2;
        }
        syslog(3,"failed to encode Fabric Manager command type %d arg content with error %d\n",uVar4
               ,(ulong)uVar1);
        uVar3 = (ulong)uVar1;
        __format = "failed to encode Fabric Manager command type %d arg content with error %d\n";
      }
      else {
        syslog(3,"failed to encode Fabric Manager command type %d arg with error %d\n",
               (ulong)param_1,(ulong)uVar1);
        uVar3 = (ulong)uVar1;
        __format = "failed to encode Fabric Manager command type %d arg with error %d\n";
      }
    }
    else {
      syslog(3,"request to encode Fabric Manager command type %d failed with error %d\n",
             (ulong)param_1,(ulong)uVar1);
      uVar3 = (ulong)uVar1;
      __format = "request to encode Fabric Manager command type %d failed with error %d\n";
    }
  }
  else {
    uVar3 = (ulong)uVar1;
    syslog(3,"failed to encode Fabric Manager command message %d with error %d\n",uVar4,(ulong)uVar1
          );
    __format = "failed to encode Fabric Manager command message %d with error %d\n";
  }
  fprintf(*(FILE **)PTR_stderr_0032efe0,__format,(ulong)param_1,uVar3);
  return -2;
}


// ===== 0024a6f0 FUN_0024a6f0 =====

undefined8 FUN_0024a6f0(void)

{
  int iVar1;
  undefined8 uVar2;
  
  do {
    iVar1 = FUN_00291820(&DAT_01217ed0,1,0);
  } while (iVar1 != 0);
  if (DAT_01217ed4 == '\0') {
    FUN_0024ae00();
    DAT_01217ed4 = '\x01';
    FUN_00291830(&DAT_01217ed0,0);
    uVar2 = 0;
  }
  else {
    FUN_00291830(&DAT_01217ed0,0);
    uVar2 = 0xfffffff9;
  }
  return uVar2;
}


// ===== 0024a760 FUN_0024a760 =====

undefined4 FUN_0024a760(undefined8 *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  stat local_b8;
  
  if (param_1 == (undefined8 *)0x0) {
    uVar4 = 0xffffffff;
    syslog(3,"fmInternalConnect with invalid argument.\n");
    fwrite("fmInternalConnect with invalid argument.\n",1,0x29,*(FILE **)PTR_stderr_0032efe0);
  }
  else {
    iVar2 = __xstat(1,"/var/run/nvidia-fabricmanager/socket",&local_b8);
    if (iVar2 < 0) {
      uVar4 = 0xfffffff7;
    }
    else {
      do {
        iVar2 = FUN_00291820(&DAT_01217ed0,1,0);
      } while (iVar2 != 0);
      if (DAT_01217ed4 == '\0') {
        uVar4 = 0xfffffffc;
        syslog(3,"fmInternalConnect called before initializing API interface library.\n");
        fwrite("fmInternalConnect called before initializing API interface library.\n",1,0x44,
               *(FILE **)PTR_stderr_0032efe0);
        FUN_00291830(&DAT_01217ed0,0);
      }
      else {
        cVar1 = FUN_0024b270();
        if (cVar1 == '\0') {
          iVar2 = FUN_0024ae30(param_2,param_3);
          if (iVar2 == 0) {
            uVar3 = FUN_0024b490();
            *param_1 = uVar3;
            FUN_00291830(&DAT_01217ed0,0);
            uVar4 = 0;
          }
          else {
            uVar4 = 0xfffffff7;
            FUN_00291830(&DAT_01217ed0,0);
            syslog(3,"failed to connect to Fabric Manager instance.\n");
            fwrite("failed to connect to Fabric Manager instance.\n",1,0x2e,
                   *(FILE **)PTR_stderr_0032efe0);
          }
        }
        else {
          uVar4 = 0;
          FUN_00291830(&DAT_01217ed0,0);
        }
      }
    }
  }
  return uVar4;
}


// ===== 0024a930 FUN_0024a930 =====

undefined8 FUN_0024a930(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined4 local_88;
  char local_84 [100];
  
  lVar3 = FUN_0024b490();
  if (param_1 == lVar3) {
    do {
      iVar2 = FUN_00291820(&DAT_01217ed0,1,0);
    } while (iVar2 != 0);
    if (DAT_01217ed4 == '\0') {
      syslog(3,"fmPrepareGpuForReset called before initializing API interface library.\n");
      fwrite("fmPrepareGpuForReset called before initializing API interface library.\n",1,0x47,
             *(FILE **)PTR_stderr_0032efe0);
      FUN_00291830(&DAT_01217ed0,0);
      return 0xfffffffc;
    }
    FUN_00291830(&DAT_01217ed0,0);
    if ((param_2 != 0) && (cVar1 = FUN_0024b270(), cVar1 != '\0')) {
      local_88 = 0x1000054;
      snprintf(local_84,0x50,"%s",param_2);
      uVar4 = FUN_0024a230(1,&local_88);
      return uVar4;
    }
  }
  syslog(3,"fmPrepareGpuForReset with invalid argument.\n");
  fwrite("fmPrepareGpuForReset with invalid argument.\n",1,0x2c,*(FILE **)PTR_stderr_0032efe0);
  return 0xffffffff;
}


// ===== 0024aa70 FUN_0024aa70 =====

undefined8 FUN_0024aa70(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined4 local_88;
  char local_84 [100];
  
  lVar3 = FUN_0024b490();
  if (param_1 == lVar3) {
    do {
      iVar2 = FUN_00291820(&DAT_01217ed0,1,0);
    } while (iVar2 != 0);
    if (DAT_01217ed4 == '\0') {
      FUN_00291830(&DAT_01217ed0,0);
      syslog(3,"fmShutdownGpuNVLinks called before initializing API interface library.\n");
      fwrite("fmShutdownGpuNVLinks called before initializing API interface library.\n",1,0x47,
             *(FILE **)PTR_stderr_0032efe0);
      return 0xfffffffc;
    }
    FUN_00291830(&DAT_01217ed0,0);
    if ((param_2 != 0) && (cVar1 = FUN_0024b270(), cVar1 != '\0')) {
      local_88 = 0x1000054;
      snprintf(local_84,0x50,"%s",param_2);
      uVar4 = FUN_0024a230(2,&local_88);
      return uVar4;
    }
  }
  syslog(3,"fmShutdownGpuNVLinks with invalid argument.\n");
  fwrite("fmShutdownGpuNVLinks with invalid argument.\n",1,0x2c,*(FILE **)PTR_stderr_0032efe0);
  return 0xffffffff;
}


// ===== 0024aba0 FUN_0024aba0 =====

undefined8 FUN_0024aba0(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined4 local_88;
  char local_84 [100];
  
  lVar3 = FUN_0024b490();
  if (param_1 == lVar3) {
    do {
      iVar2 = FUN_00291820(&DAT_01217ed0,1,0);
    } while (iVar2 != 0);
    if (DAT_01217ed4 == '\0') {
      FUN_00291830(&DAT_01217ed0,0);
      syslog(3,"fmResetGpuNVLinks called before initializing API interface library.\n");
      fwrite("fmResetGpuNVLinks called before initializing API interface library.\n",1,0x44,
             *(FILE **)PTR_stderr_0032efe0);
      return 0xfffffffc;
    }
    FUN_00291830(&DAT_01217ed0,0);
    if ((param_2 != 0) && (cVar1 = FUN_0024b270(), cVar1 != '\0')) {
      local_88 = 0x1000054;
      snprintf(local_84,0x50,"%s",param_2);
      uVar4 = FUN_0024a230(3,&local_88);
      return uVar4;
    }
  }
  syslog(3,"fmResetGpuNVLinks with invalid argument.\n");
  fwrite("fmResetGpuNVLinks with invalid argument.\n",1,0x29,*(FILE **)PTR_stderr_0032efe0);
  return 0xffffffff;
}


// ===== 0024acd0 FUN_0024acd0 =====

undefined8 FUN_0024acd0(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined4 local_88;
  char local_84 [100];
  
  lVar3 = FUN_0024b490();
  if (param_1 == lVar3) {
    do {
      iVar2 = FUN_00291820(&DAT_01217ed0,1,0);
    } while (iVar2 != 0);
    if (DAT_01217ed4 == '\0') {
      FUN_00291830(&DAT_01217ed0,0);
      syslog(3,"fmCompleteGpuReset called before initializing API interface library.\n");
      fwrite("fmCompleteGpuReset called before initializing API interface library.\n",1,0x45,
             *(FILE **)PTR_stderr_0032efe0);
      return 0xfffffffc;
    }
    FUN_00291830(&DAT_01217ed0,0);
    if ((param_2 != 0) && (cVar1 = FUN_0024b270(), cVar1 != '\0')) {
      local_88 = 0x1000054;
      snprintf(local_84,0x50,"%s",param_2);
      uVar4 = FUN_0024a230(4,&local_88);
      return uVar4;
    }
  }
  syslog(3,"fmCompleteGpuReset with invalid argument.\n");
  fwrite("fmCompleteGpuReset with invalid argument.\n",1,0x2a,*(FILE **)PTR_stderr_0032efe0);
  return 0xffffffff;
}


// ===== 0024ae00 FUN_0024ae00 =====

void FUN_0024ae00(void)

{
  long lVar1;
  undefined8 *puVar2;
  
  DAT_012182e0 = 0;
  DAT_003805b8 = 0xffffffff;
  puVar2 = &DAT_01217ee0;
  for (lVar1 = 0x80; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== 0024ae30 FUN_0024ae30 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0024ae30(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  long lVar4;
  ulong uVar5;
  char *__format;
  __fd_mask *p_Var6;
  timeval *__timeout;
  uint local_1c0;
  socklen_t local_1bc;
  timeval local_1b8;
  sockaddr local_1a8;
  char cStack_198;
  char cStack_197;
  undefined8 local_196;
  undefined8 uStack_18e;
  undefined4 local_186;
  undefined1 local_182;
  ulong local_138 [4];
  __fd_mask local_118;
  __fd_mask _Stack_110;
  __fd_mask local_108;
  __fd_mask _Stack_100;
  __fd_mask local_f8;
  __fd_mask _Stack_f0;
  __fd_mask local_e8;
  __fd_mask _Stack_e0;
  __fd_mask local_d8;
  __fd_mask _Stack_d0;
  __fd_mask local_c8;
  __fd_mask _Stack_c0;
  fd_set local_b8;
  
  local_1c0 = 0;
  local_1bc = 4;
  DAT_003805b8 = socket(1,1,0);
  if (DAT_003805b8 < 0) {
    puVar3 = (uint *)__errno_location();
    syslog(3,
           "request to initialize socket object for connecting with running Fabric Manager instance failed with error %d\n"
           ,(ulong)*puVar3);
    uVar5 = (ulong)*puVar3;
    __format = 
    "request to initialize socket object for connecting with running Fabric Manager instance failed with error %d\n"
    ;
    goto LAB_0024b153;
  }
  local_1a8.sa_family = 1;
  local_1a8.sa_data[0] = s__var_run_nvidia_persistenced_soc_002dd580[0];
  local_1a8.sa_data[1] = s__var_run_nvidia_persistenced_soc_002dd580[1];
  local_1a8.sa_data[2] = s__var_run_nvidia_persistenced_soc_002dd580[2];
  local_1a8.sa_data[3] = s__var_run_nvidia_persistenced_soc_002dd580[3];
  local_1a8.sa_data[4] = s__var_run_nvidia_persistenced_soc_002dd580[4];
  local_1a8.sa_data[5] = s__var_run_nvidia_persistenced_soc_002dd580[5];
  local_1a8.sa_data[6] = s__var_run_nvidia_persistenced_soc_002dd580[6];
  local_1a8.sa_data[7] = s__var_run_nvidia_persistenced_soc_002dd580[7];
  local_1a8.sa_data[8] = s__var_run_nvidia_persistenced_soc_002dd580[8];
  local_1a8.sa_data[9] = s__var_run_nvidia_persistenced_soc_002dd580[9];
  local_1a8.sa_data[10] = s__var_run_nvidia_persistenced_soc_002dd580[10];
  local_1a8.sa_data[0xb] = s__var_run_nvidia_persistenced_soc_002dd580[0xb];
  local_1a8.sa_data[0xc] = s__var_run_nvidia_persistenced_soc_002dd580[0xc];
  local_1a8.sa_data[0xd] = s__var_run_nvidia_persistenced_soc_002dd580[0xd];
  cStack_198 = s__var_run_nvidia_persistenced_soc_002dd580[0xe];
  cStack_197 = s__var_run_nvidia_persistenced_soc_002dd580[0xf];
  local_186 = 0x74656b63;
  local_182 = 0;
  local_196 = _DAT_002dec70;
  uStack_18e = _UNK_002dec78;
  local_1b8.tv_sec = (__time_t)(param_1 / 1000);
  local_1b8.tv_usec = (__suseconds_t)((param_1 % 1000) * 1000);
  p_Var6 = (__fd_mask *)local_138;
  for (lVar4 = 0x10; lVar4 != 0; lVar4 = lVar4 + -1) {
    *p_Var6 = 0;
    p_Var6 = p_Var6 + 1;
  }
  iVar2 = DAT_003805b8 + 0x3f;
  if (-1 < DAT_003805b8) {
    iVar2 = DAT_003805b8;
  }
  local_138[iVar2 >> 6] = local_138[iVar2 >> 6] | 1L << ((byte)(DAT_003805b8 % 0x40) & 0x3f);
  local_b8.fds_bits[0] = local_138[0];
  local_b8.fds_bits[1] = local_138[1];
  local_b8.fds_bits[6] = local_108;
  local_b8.fds_bits[7] = _Stack_100;
  local_b8.fds_bits[2] = local_138[2];
  local_b8.fds_bits[3] = local_138[3];
  local_b8.fds_bits[4] = local_118;
  local_b8.fds_bits[5] = _Stack_110;
  local_b8.fds_bits[8] = local_f8;
  local_b8.fds_bits[9] = _Stack_f0;
  local_b8.fds_bits[10] = local_e8;
  local_b8.fds_bits[0xb] = _Stack_e0;
  local_b8.fds_bits[0xc] = local_d8;
  local_b8.fds_bits[0xd] = _Stack_d0;
  local_b8.fds_bits[0xe] = local_c8;
  local_b8.fds_bits[0xf] = _Stack_c0;
  uVar1 = fcntl(DAT_003805b8,3,0);
  if ((int)uVar1 < 0) {
    puVar3 = (uint *)__errno_location();
    syslog(3,
           "request to get socket for connecting with running Fabric Manager instance failed with error %d\n"
           ,(ulong)*puVar3);
    uVar5 = (ulong)*puVar3;
    __format = 
    "request to get socket for connecting with running Fabric Manager instance failed with error %d\n"
    ;
    goto LAB_0024b153;
  }
  iVar2 = fcntl(DAT_003805b8,4,(ulong)uVar1 | 0x800);
  if (iVar2 < 0) {
    puVar3 = (uint *)__errno_location();
    syslog(3,
           "request to set socket object for connecting with running Fabric Manager instance failed with error %d\n"
           ,(ulong)*puVar3);
    uVar5 = (ulong)*puVar3;
    __format = 
    "request to set socket object for connecting with running Fabric Manager instance failed with error %d\n"
    ;
    goto LAB_0024b153;
  }
  iVar2 = connect(DAT_003805b8,&local_1a8,0x6e);
  if (iVar2 == 0) {
LAB_0024b0b5:
    iVar2 = fcntl(DAT_003805b8,4,(ulong)uVar1);
    if (-1 < iVar2) {
      local_1b8.tv_sec = (__time_t)(param_2 / 1000);
      local_1b8.tv_usec = (__suseconds_t)((param_2 % 1000) * 1000);
      setsockopt(DAT_003805b8,1,0x15,&local_1b8,0x10);
      return 0;
    }
    puVar3 = (uint *)__errno_location();
    syslog(3,
           "request to set socket blocking for connecting with running Fabric Manager instance failed with error %d\n"
           ,(ulong)*puVar3);
    uVar5 = (ulong)*puVar3;
    __format = 
    "request to set socket blocking for connecting with running Fabric Manager instance failed with error %d\n"
    ;
    goto LAB_0024b153;
  }
  puVar3 = (uint *)__errno_location();
  uVar5 = (ulong)*puVar3;
  if (*puVar3 == 0x73) {
    __timeout = &local_1b8;
    if (param_1 == 0) {
      __timeout = (timeval *)0x0;
    }
    iVar2 = select(DAT_003805b8 + 1,(fd_set *)local_138,&local_b8,(fd_set *)0x0,__timeout);
    if (-1 < iVar2) {
      if (iVar2 == 0) {
        *puVar3 = 0x6e;
        uVar5 = 0x6e;
        goto LAB_0024b136;
      }
      iVar2 = DAT_003805b8 + 0x3f;
      if (-1 < DAT_003805b8) {
        iVar2 = DAT_003805b8;
      }
      if (((local_138[iVar2 >> 6] >> ((ulong)(uint)(DAT_003805b8 % 0x40) & 0x3f) & 1) != 0) ||
         (((ulong)local_b8.fds_bits[iVar2 >> 6] >> ((ulong)(uint)(DAT_003805b8 % 0x40) & 0x3f) & 1)
          != 0)) {
        iVar2 = getsockopt(DAT_003805b8,1,4,&local_1c0,&local_1bc);
        if (iVar2 < 0) {
          syslog(3,
                 "request to connect with running Fabric Manager instance failed with get socket error %d\n"
                 ,(ulong)*puVar3);
          uVar5 = (ulong)*puVar3;
          __format = 
          "request to connect with running Fabric Manager instance failed with get socket error %d\n"
          ;
          goto LAB_0024b153;
        }
        if (local_1c0 != 0) {
          *puVar3 = local_1c0;
          syslog(3,
                 "request to connect with running Fabric Manager instance failed with socket error %d\n"
                );
          uVar5 = (ulong)*puVar3;
          __format = 
          "request to connect with running Fabric Manager instance failed with socket error %d\n";
          goto LAB_0024b153;
        }
        goto LAB_0024b0b5;
      }
    }
    uVar5 = (ulong)*puVar3;
  }
LAB_0024b136:
  syslog(3,"request to connect with running Fabric Manager instance failed with error %d\n",uVar5);
  uVar5 = (ulong)*puVar3;
  __format = "request to connect with running Fabric Manager instance failed with error %d\n";
LAB_0024b153:
  fprintf(*(FILE **)PTR_stderr_0032efe0,__format,uVar5);
  return 0xfffffffd;
}


// ===== 0024b270 FUN_0024b270 =====

uint FUN_0024b270(void)

{
  return ~DAT_003805b8 >> 0x1f;
}


// ===== 0024b280 FUN_0024b280 =====

void FUN_0024b280(void)

{
  DAT_012182e0 = DAT_012182e0 + 1;
  return;
}


// ===== 0024b290 FUN_0024b290 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0024b290(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  ssize_t sVar4;
  ulong uVar5;
  int *piVar6;
  uint *puVar7;
  undefined8 uVar8;
  int iVar9;
  undefined *local_40 [2];
  
  local_40[0] = (undefined *)0x0;
  cVar1 = FUN_0024b270();
  if (cVar1 == '\0') {
    syslog(3,"Fabric Manager instance is not connected.\n");
    fwrite("Fabric Manager instance is not connected.\n",1,0x2a,*(FILE **)PTR_stderr_0032efe0);
    uVar8 = 0xfffffffd;
  }
  else {
    uVar2 = FUN_0024ca20(param_1,local_40);
    memcpy(&DAT_01217ef4,local_40[0],(ulong)uVar2);
    uVar3 = FUN_0024b280();
    DAT_01217ee0._0_4_ = 0xabbcbcab;
    DAT_01217ee8._0_4_ =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    DAT_01217ee0._4_4_ =
         uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    ram0x01217eec = 0x10000;
    sVar4 = send(DAT_003805b8,&DAT_01217ee0,(ulong)(uVar2 + 0x14),0);
    if (uVar2 + 0x14 == (uint)sVar4) {
      iVar9 = 5;
      do {
        uVar5 = recv(DAT_003805b8,&DAT_01217ee0,0x400,0);
        if (0x14 < (int)uVar5) goto LAB_0024b348;
        piVar6 = __errno_location();
        if (*piVar6 != 0xb) {
          *piVar6 = 0xb;
        }
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      if ((int)uVar5 == 0x14) {
LAB_0024b348:
        local_40[0] = &DAT_01217ef4;
        uVar2 = FUN_0024bbb0(param_2,&DAT_01217ef4,uVar5 & 0xffffffff);
        if (uVar2 == 0) {
          uVar8 = 0;
        }
        else {
          syslog(3,"failed to decode response message from Fabric Manager instance with error %d\n",
                 (ulong)uVar2);
          fprintf(*(FILE **)PTR_stderr_0032efe0,
                  "failed to decode response message from Fabric Manager instance with error %d\n",
                  (ulong)uVar2);
          uVar8 = 0xfffffffe;
        }
      }
      else {
        syslog(3,
               "received message from Fabric Manager instance is not valid due to header size mismatch.\n"
              );
        fwrite("received message from Fabric Manager instance is not valid due to header size mismatch.\n"
               ,1,0x58,*(FILE **)PTR_stderr_0032efe0);
        uVar8 = 0xfffffffe;
      }
    }
    else {
      puVar7 = (uint *)__errno_location();
      syslog(3,"failed to send the message to Fabric Manager instance with error %d.\n",
             (ulong)*puVar7);
      fprintf(*(FILE **)PTR_stderr_0032efe0,
              "failed to send the message to Fabric Manager instance with error %d.\n",
              (ulong)*puVar7);
      uVar8 = 0xffffffb8;
    }
  }
  return uVar8;
}


// ===== 0024b490 FUN_0024b490 =====

undefined4 * FUN_0024b490(void)

{
  return &DAT_003805b8;
}


// ===== 0024b4a0 FUN_0024b4a0 =====

void FUN_0024b4a0(long *param_1)

{
  byte bVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  void *pvVar4;
  char *pcVar5;
  long lVar6;
  
  lVar6 = *param_1;
  puVar2 = *(undefined8 **)(lVar6 + 0x18);
  puVar3 = malloc(0x10);
  *(undefined4 *)(param_1 + 2) = 1;
  param_1[1] = (long)puVar3;
  if (puVar3 == (undefined8 *)0x0) {
    pcVar5 = "Failed to allocate memory for default field\n";
    goto LAB_0024b739;
  }
  if ((*(byte *)(lVar6 + 5) & 1) == 0) {
    if (puVar2 != (undefined8 *)0x0) {
      (*DAT_0037f118)("Warning! Field without default flag has default value.\n");
      lVar6 = *param_1;
    }
LAB_0024b4f4:
    bVar1 = *(byte *)(lVar6 + 4);
    switch(bVar1) {
    case 0:
    case 1:
    case 2:
    case 3:
      *(undefined8 *)param_1[1] = 0;
      break;
    case 4:
    case 5:
    case 6:
    case 7:
      *(undefined4 *)param_1[1] = 0;
      break;
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
      *(undefined4 *)param_1[1] = 0;
      break;
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x1c:
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x2c:
    case 0x2d:
    case 0x2e:
    case 0x2f:
      *(undefined8 *)param_1[1] = 0;
      break;
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
      *(undefined1 *)param_1[1] = 0;
      break;
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
      *(undefined4 *)param_1[1] = *(undefined4 *)**(undefined8 **)(lVar6 + 0x10);
      break;
    case 0x38:
    case 0x39:
    case 0x3a:
    case 0x3b:
      puVar2 = (undefined8 *)param_1[1];
      pvVar4 = malloc(1);
      *puVar2 = pvVar4;
      if (*(undefined1 **)param_1[1] != (undefined1 *)0x0) {
        **(undefined1 **)param_1[1] = 0;
        *(undefined4 *)(param_1[1] + 8) = 0;
        return;
      }
LAB_0024b728:
      pcVar5 = "Failed to allocate memory for default string\n";
LAB_0024b739:
                    /* WARNING: Could not recover jumptable at 0x0024b743. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*DAT_0037f118)(pcVar5);
      return;
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
      *(undefined8 *)param_1[1] = 0;
      *(undefined4 *)(param_1[1] + 8) = 0;
      break;
    default:
switchD_0024b519_default:
                    /* WARNING: Could not recover jumptable at 0x0024b669. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*DAT_0037f118)("Invalid default field type %u\n",bVar1 >> 2,DAT_0037f118);
      return;
    }
  }
  else {
    if (puVar2 == (undefined8 *)0x0) {
      (*DAT_0037f118)("Warning! Field with default flag has no default value.\n");
      lVar6 = *param_1;
      goto LAB_0024b4f4;
    }
    bVar1 = *(byte *)(lVar6 + 4);
    switch(bVar1) {
    case 0:
    case 1:
    case 2:
    case 3:
      *puVar3 = *puVar2;
      break;
    case 4:
    case 5:
    case 6:
    case 7:
      *(undefined4 *)puVar3 = *(undefined4 *)puVar2;
      break;
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
      *(undefined4 *)puVar3 = *(undefined4 *)puVar2;
      break;
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x1c:
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x2c:
    case 0x2d:
    case 0x2e:
    case 0x2f:
      *puVar3 = *puVar2;
      break;
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
      *(undefined1 *)puVar3 = *(undefined1 *)puVar2;
      break;
    case 0x38:
    case 0x39:
    case 0x3a:
    case 0x3b:
      pcVar5 = malloc((ulong)(*(int *)(puVar2 + 1) + 1));
      *puVar3 = pcVar5;
      if (pcVar5 != (char *)0x0) {
        strncpy(pcVar5,(char *)*puVar2,(ulong)(*(int *)(puVar2 + 1) + 1));
        *(undefined4 *)(puVar3 + 1) = *(undefined4 *)(puVar2 + 1);
        return;
      }
      goto LAB_0024b728;
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
      pcVar5 = malloc((ulong)*(uint *)(puVar2 + 1));
      *puVar3 = pcVar5;
      if ((*(uint *)(puVar2 + 1) != 0) && (pcVar5 == (char *)0x0)) {
        pcVar5 = "Failed to allocate memory for default bytes\n";
        goto LAB_0024b739;
      }
      strncpy(pcVar5,(char *)*puVar2,(ulong)*(uint *)(puVar2 + 1));
      *(undefined4 *)(puVar3 + 1) = *(undefined4 *)(puVar2 + 1);
      break;
    default:
      goto switchD_0024b519_default;
    }
  }
  return;
}


// ===== 0024b770 FUN_0024b770 =====

ulong FUN_0024b770(long param_1)

{
  byte bVar1;
  byte *pbVar2;
  byte bVar3;
  byte *pbVar4;
  ulong uVar5;
  
  uVar5 = 0;
  pbVar4 = *(byte **)(param_1 + 8);
  pbVar2 = *(byte **)(param_1 + 0x10);
  bVar3 = 0;
  do {
    if (pbVar2 < pbVar4) {
      (*DAT_0037f118)("WARNING: _prbBufLeft overrun.  pos is %d, end is %d.\n");
      pbVar4 = *(byte **)(param_1 + 8);
      if (pbVar4 <= *(byte **)(param_1 + 0x10)) {
        if ((int)*(byte **)(param_1 + 0x10) != (int)pbVar4) {
LAB_0024b7e1:
          bVar1 = *pbVar4;
          *(byte **)(param_1 + 8) = pbVar4 + 1;
          uVar5 = uVar5 | (ulong)bVar1 << (bVar3 & 0x3f);
        }
        return uVar5;
      }
LAB_0024b814:
      (*DAT_0037f118)("WARNING: _prbBufLeft overrun.  pos is %d, end is %d.\n");
      return uVar5;
    }
    if ((int)pbVar2 == (int)pbVar4) {
      if (pbVar4 <= pbVar2) {
        return uVar5;
      }
      goto LAB_0024b814;
    }
    bVar1 = *pbVar4;
    if (-1 < (char)bVar1) {
      if (pbVar2 < pbVar4) goto LAB_0024b814;
      goto LAB_0024b7e1;
    }
    pbVar4 = pbVar4 + 1;
    *(byte **)(param_1 + 8) = pbVar4;
    uVar5 = uVar5 | (ulong)(bVar1 & 0x7f) << (bVar3 & 0x3f);
    bVar3 = bVar3 + 7;
  } while( true );
}


// ===== 0024b840 FUN_0024b840 =====

undefined8 FUN_0024b840(uint param_1,long param_2,ulong *param_3)

{
  byte *pbVar1;
  ulong uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  bool bVar7;
  
  if (param_1 == 2) {
    uVar2 = FUN_0024b770(param_2);
    *param_3 = uVar2;
    uVar6 = *(ulong *)(param_2 + 8);
    param_3[1] = uVar6;
    bVar7 = DAT_012182e8 != '\0';
    *(ulong *)(param_2 + 8) = uVar6 + uVar2;
    if (bVar7) {
      (*DAT_0037f118)("WT_STRING len = 0x%llX %llu ",*param_3,*param_3);
    }
  }
  else if (param_1 < 3) {
    if (param_1 == 0) {
      uVar6 = FUN_0024b770(param_2);
      bVar7 = DAT_012182e8 != '\0';
      *param_3 = uVar6;
      if (bVar7) {
        (*DAT_0037f118)("WT_VARINT: 0x%llX %lld ",uVar6,uVar6);
        return 0;
      }
    }
    else {
      if (param_1 != 1) goto LAB_0024b900;
      *param_3 = 0;
      iVar4 = 0;
      do {
        pbVar1 = *(byte **)(param_2 + 8);
        *(byte **)(param_2 + 8) = pbVar1 + 1;
        bVar3 = (byte)iVar4;
        iVar4 = iVar4 + 8;
        uVar6 = (ulong)*pbVar1 << (bVar3 & 0x3f) | *param_3;
        *param_3 = uVar6;
      } while (iVar4 != 0x40);
      if (DAT_012182e8 != '\0') {
        (*DAT_0037f118)("WT_64BIT: 0x%llX %lld ",uVar6,uVar6);
        return 0;
      }
    }
  }
  else {
    if (param_1 != 5) {
LAB_0024b900:
      (*DAT_0037f118)("Unrecognized wire type %u\n",param_1);
      return 4;
    }
    *(uint *)param_3 = 0;
    iVar4 = 0;
    do {
      pbVar1 = *(byte **)(param_2 + 8);
      *(byte **)(param_2 + 8) = pbVar1 + 1;
      bVar3 = (byte)iVar4;
      iVar4 = iVar4 + 8;
      uVar5 = (uint)*pbVar1 << (bVar3 & 0x1f) | (uint)*param_3;
      *(uint *)param_3 = uVar5;
    } while (iVar4 != 0x20);
    if (DAT_012182e8 != '\0') {
      (*DAT_0037f118)("WT_32BIT: 0x%X %d ",uVar5,uVar5);
      return 0;
    }
  }
  return 0;
}


// ===== 0024b9d0 FUN_0024b9d0 =====

undefined8 FUN_0024b9d0(undefined8 *param_1,uint *param_2)

{
  long *plVar1;
  void *pvVar2;
  ulong uVar3;
  undefined8 uVar4;
  uint uVar5;
  
  *param_1 = param_2;
  pvVar2 = malloc((ulong)*param_2 * 0x18);
  param_1[1] = pvVar2;
  if (pvVar2 == (void *)0x0) {
    (*DAT_0037f118)("Failed to allocate memory for message\n");
    uVar4 = 2;
  }
  else {
    *(undefined4 *)(param_1 + 2) = 0;
    if (*param_2 != 0) {
      uVar5 = 0;
      while( true ) {
        uVar3 = (ulong)uVar5;
        uVar5 = uVar5 + 1;
        plVar1 = (long *)((long)pvVar2 + uVar3 * 0x18);
        *plVar1 = uVar3 * 0x20 + *(long *)(param_2 + 2);
        plVar1[1] = 0;
        *(undefined4 *)(plVar1 + 2) = 0;
        if (*param_2 <= uVar5) break;
        pvVar2 = (void *)param_1[1];
      }
    }
    uVar4 = 0;
  }
  return uVar4;
}


// ===== 0024ba60 FUN_0024ba60 =====

void FUN_0024ba60(undefined8 *param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  ulong uVar3;
  
  if (*(int *)*param_1 != 0) {
    uVar3 = 0;
    do {
      uVar2 = (int)uVar3 + 1;
      puVar1 = (undefined8 *)(param_1[1] + uVar3 * 0x18);
      FUN_0024baf0(puVar1);
      free((void *)puVar1[1]);
      *puVar1 = 0;
      puVar1[1] = 0;
      *(undefined4 *)(puVar1 + 2) = 0;
      uVar3 = (ulong)uVar2;
    } while (uVar2 < *(uint *)*param_1);
  }
  free((void *)param_1[1]);
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = 0;
  return;
}


// ===== 0024baf0 FUN_0024baf0 =====

void FUN_0024baf0(long *param_1)

{
  byte bVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  uint uVar5;
  
  bVar1 = *(byte *)(*param_1 + 4) >> 2;
  if (*(byte *)(*param_1 + 4) < 0x40) {
    if (bVar1 < 0xe) {
      return;
    }
    uVar5 = *(uint *)(param_1 + 2);
  }
  else {
    if (bVar1 != 0x10) {
      return;
    }
    uVar3 = 0;
    if ((int)param_1[2] == 0) {
      return;
    }
    do {
      uVar2 = (int)uVar3 + 1;
      FUN_0024ba60(*(undefined8 *)(uVar3 * 0x10 + param_1[1]));
      uVar5 = *(uint *)(param_1 + 2);
      uVar3 = (ulong)uVar2;
    } while (uVar2 < uVar5);
  }
  if (uVar5 != 0) {
    uVar3 = 0;
    do {
      uVar5 = (int)uVar3 + 1;
      lVar4 = uVar3 * 0x10;
      free(*(void **)(param_1[1] + lVar4));
      *(undefined8 *)(param_1[1] + lVar4) = 0;
      *(undefined4 *)(param_1[1] + 8 + lVar4) = 0;
      uVar3 = (ulong)uVar5;
    } while (uVar5 < *(uint *)(param_1 + 2));
  }
  return;
}


// ===== 0024bbb0 FUN_0024bbb0 =====

undefined8 FUN_0024bbb0(undefined8 *param_1,ulong param_2,uint param_3)

{
  byte bVar1;
  int *piVar2;
  ulong uVar3;
  undefined8 uVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  long *plVar9;
  undefined8 local_a0;
  undefined1 local_98 [16];
  undefined1 local_88 [16];
  ulong local_78;
  ulong local_70;
  ulong local_68;
  ulong local_58;
  ulong local_50;
  ulong local_48;
  
  local_68 = param_3 + param_2;
  *(uint *)(param_1 + 2) = *(int *)(param_1 + 2) + param_3;
  local_98 = (undefined1  [16])0x0;
  local_78 = param_2;
  local_70 = param_2;
  if (param_2 <= local_68) {
LAB_0024bc10:
    if ((int)local_68 != (int)local_70) {
      uVar3 = FUN_0024b770(&local_78);
      iVar6 = DAT_012182e4;
      local_98._0_8_ = uVar3;
      if (DAT_012182e8 != '\0') {
        if (DAT_012182e4 != 0) {
          iVar7 = 0;
          do {
            iVar7 = iVar7 + 1;
            (*DAT_0037f118)(&DAT_002e8ec1);
          } while (iVar6 != iVar7);
          if (DAT_012182e8 == '\0') goto LAB_0024bc4d;
        }
        (*DAT_0037f118)("Tag = %d ",uVar3 >> 3 & 0xffffffff);
      }
LAB_0024bc4d:
      uVar4 = FUN_0024b840((uint)uVar3 & 7,&local_78,local_98);
      if ((int)uVar4 != 0) {
        return uVar4;
      }
      if (*(uint *)*param_1 != 0) {
        lVar8 = 0;
        do {
          piVar2 = *(int **)(param_1[1] + lVar8);
          plVar9 = (long *)(param_1[1] + lVar8);
          if (*piVar2 == (int)(uVar3 >> 3)) {
            if ((*(byte *)((long)piVar2 + 5) & 2) != 0) {
              if (DAT_012182e8 != '\0') {
                (*DAT_0037f118)("Packed\n");
                plVar9 = (long *)(lVar8 + param_1[1]);
              }
              local_88 = (undefined1  [16])0x0;
              local_48 = (ulong)(uint)local_98._0_4_ + local_98._8_8_;
              local_58 = local_98._8_8_;
              local_50 = local_98._8_8_;
              DAT_012182e4 = DAT_012182e4 + 1;
              switch(*(undefined1 *)(*plVar9 + 4)) {
              case 0:
              case 1:
              case 2:
              case 3:
              case 0x24:
              case 0x25:
              case 0x26:
              case 0x27:
              case 0x2c:
              case 0x2d:
              case 0x2e:
              case 0x2f:
                local_a0 = 1;
                break;
              case 4:
              case 5:
              case 6:
              case 7:
              case 0x20:
              case 0x21:
              case 0x22:
              case 0x23:
              case 0x28:
              case 0x29:
              case 0x2a:
              case 0x2b:
                local_a0 = 5;
                break;
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
              case 0x30:
              case 0x31:
              case 0x32:
              case 0x33:
              case 0x34:
              case 0x35:
              case 0x36:
              case 0x37:
                local_a0 = 0;
                break;
              default:
                (*DAT_0037f118)("Invalid packed field wire type %u\n",0);
                return 4;
              }
              goto LAB_0024bdaa;
            }
            if (DAT_012182e8 != '\0') {
              (*DAT_0037f118)("Not packed ");
              plVar9 = (long *)(lVar8 + param_1[1]);
            }
            uVar4 = FUN_0024c010(plVar9,local_98);
            if ((int)uVar4 != 0) {
              return uVar4;
            }
            break;
          }
          lVar8 = lVar8 + 0x18;
        } while ((ulong)*(uint *)*param_1 * 0x18 != lVar8);
      }
      goto LAB_0024bdd0;
    }
    goto LAB_0024bdf3;
  }
LAB_0024bde1:
  (*DAT_0037f118)("WARNING: _prbBufLeft overrun.  pos is %d, end is %d.\n");
LAB_0024bdf3:
  uVar3 = 0;
  puVar5 = (uint *)*param_1;
  if (*puVar5 != 0) {
    do {
      while( true ) {
        iVar6 = (int)uVar3;
        plVar9 = (long *)(param_1[1] + uVar3 * 0x18);
        bVar1 = *(byte *)(*plVar9 + 4);
        if ((bVar1 & 3) != 0) break;
        if ((int)plVar9[2] == 0) {
          FUN_0024b4a0();
          uVar3 = (ulong)(iVar6 + 1U);
          (*DAT_0037f118)("Missing required field\n");
          puVar5 = (uint *)*param_1;
          if (*puVar5 <= iVar6 + 1U) {
            return 0;
          }
        }
        else {
LAB_0024be50:
          uVar3 = (ulong)(iVar6 + 1U);
          if (*puVar5 <= iVar6 + 1U) {
            return 0;
          }
        }
      }
      if ((((bVar1 & 3) != 1) || ((int)plVar9[2] != 0)) || ((bVar1 & 0xfc) == 0x40))
      goto LAB_0024be50;
      FUN_0024b4a0();
      uVar3 = (ulong)(iVar6 + 1U);
      puVar5 = (uint *)*param_1;
    } while (iVar6 + 1U < *puVar5);
  }
  return 0;
LAB_0024bdaa:
  iVar6 = DAT_012182e4;
  if (local_48 < local_50) goto code_r0x0024bdaf;
  if ((int)local_48 == (int)local_50) goto LAB_0024bdc1;
  if ((DAT_012182e8 != '\0') && (DAT_012182e4 != 0)) {
    iVar7 = 0;
    do {
      iVar7 = iVar7 + 1;
      (*DAT_0037f118)(&DAT_002e8ec1);
    } while (iVar6 != iVar7);
  }
  uVar4 = FUN_0024b840(local_a0,&local_58,local_88);
  if ((int)uVar4 != 0) {
    return uVar4;
  }
  uVar4 = FUN_0024c010(plVar9,local_88);
  if ((int)uVar4 != 0) {
    return uVar4;
  }
  goto LAB_0024bdaa;
code_r0x0024bdaf:
  (*DAT_0037f118)("WARNING: _prbBufLeft overrun.  pos is %d, end is %d.\n");
LAB_0024bdc1:
  DAT_012182e4 = DAT_012182e4 + -1;
LAB_0024bdd0:
  if (local_68 < local_70) goto LAB_0024bde1;
  goto LAB_0024bc10;
}


// ===== 0024c010 FUN_0024c010 =====

int FUN_0024c010(long *param_1,float *param_2)

{
  byte bVar1;
  int iVar2;
  undefined8 *puVar3;
  void *pvVar4;
  uint uVar5;
  ulong uVar6;
  long lVar8;
  long lVar9;
  long lVar10;
  bool bVar11;
  ulong uVar7;
  
  lVar10 = *param_1;
  bVar1 = *(byte *)(lVar10 + 4) & 3;
  if (bVar1 < 2) {
    if ((int)param_1[2] == 1) {
      if ((*(byte *)(lVar10 + 4) & 0xfc) == 0x40) {
        puVar3 = (undefined8 *)param_1[1];
        uVar6 = 0;
      }
      else {
        FUN_0024baf0();
        uVar6 = 0;
        puVar3 = (undefined8 *)param_1[1];
      }
      goto LAB_0024c06a;
    }
    uVar7 = 0;
    uVar6 = 0;
    puVar3 = malloc(0x10);
    *(undefined4 *)(param_1 + 2) = 1;
    param_1[1] = (long)puVar3;
    if ((*(byte *)(lVar10 + 4) & 0xfc) != 0x40) goto LAB_0024c06a;
    *puVar3 = 0;
  }
  else {
    if (bVar1 != 2) {
      (*DAT_0037f118)("Unrecognized field qualifier %u\n",3);
      return 4;
    }
    uVar6 = (ulong)*(uint *)(param_1 + 2);
    uVar5 = *(uint *)(param_1 + 2) + 1;
    *(uint *)(param_1 + 2) = uVar5;
    puVar3 = realloc((void *)param_1[1],(ulong)uVar5 << 4);
    param_1[1] = (long)puVar3;
    if ((*(byte *)(*param_1 + 4) & 0xfc) == 0x40) {
      puVar3[uVar6 * 2] = 0;
      puVar3 = (undefined8 *)param_1[1];
    }
LAB_0024c06a:
    if (puVar3 == (undefined8 *)0x0) {
      (*DAT_0037f118)("Failed to allocate memory for field\n");
      return 2;
    }
    lVar10 = *param_1;
    uVar7 = uVar6;
  }
  bVar1 = *(byte *)(lVar10 + 4);
  if (0x43 < bVar1) {
    if (DAT_012182e8 == '\0') {
      return 4;
    }
    (*DAT_0037f118)("Unrecognized field type %u\n",bVar1 >> 2);
    return 4;
  }
  bVar11 = DAT_012182e8 != '\0';
  switch(bVar1) {
  default:
    if (bVar11) {
      (*DAT_0037f118)(*(undefined8 *)param_2,"PRB_DOUBLE: %f\n");
    }
    iVar2 = 0;
    *(undefined8 *)(uVar7 * 0x10 + param_1[1]) = *(undefined8 *)param_2;
    break;
  case 4:
  case 5:
  case 6:
  case 7:
    if (bVar11) {
      (*DAT_0037f118)((double)*param_2,"PRB_FLOAT: %f\n");
    }
    iVar2 = 0;
    *(float *)(uVar7 * 0x10 + param_1[1]) = *param_2;
    break;
  case 8:
  case 9:
  case 10:
  case 0xb:
    if (bVar11) {
      (*DAT_0037f118)("PRB_INT32: %d\n",*param_2);
    }
    goto LAB_0024c218;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    if (bVar11) {
      (*DAT_0037f118)("PRB_INT64: %lld\n",*(undefined8 *)param_2);
    }
    goto LAB_0024c1d8;
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
    if (bVar11) {
      (*DAT_0037f118)("PRB_UINT32: %u\n",*param_2);
    }
    goto LAB_0024c218;
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
    if (bVar11) {
      (*DAT_0037f118)("PRB_UINT64: %llu\n",*(undefined8 *)param_2);
    }
    goto LAB_0024c1d8;
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
    if (bVar11) {
      (*DAT_0037f118)("PRB_SINT32: %d\n",
                      (int)((int)((uint)*(undefined8 *)param_2 << 0x1f) >> 0x1f ^
                           (uint)*(undefined8 *)param_2) >> 1);
    }
    iVar2 = 0;
    *(int *)(uVar7 * 0x10 + param_1[1]) =
         (int)((int)((uint)*(undefined8 *)param_2 << 0x1f) >> 0x1f ^ (uint)*(undefined8 *)param_2)
         >> 1;
    break;
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
    if (bVar11) {
      (*DAT_0037f118)("PRB_SINT64: %lld\n",
                      (long)((long)(*(ulong *)param_2 << 0x3f) >> 0x3f ^ *(ulong *)param_2) >> 1);
    }
    iVar2 = 0;
    *(long *)(uVar7 * 0x10 + param_1[1]) =
         (long)((long)(*(ulong *)param_2 << 0x3f) >> 0x3f ^ *(ulong *)param_2) >> 1;
    break;
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
    if (bVar11) {
      (*DAT_0037f118)("PRB_FIXED32: %u\n",*param_2);
    }
    goto LAB_0024c218;
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
    if (bVar11) {
      (*DAT_0037f118)("PRB_FIXED64: %llu\n",*(undefined8 *)param_2);
    }
    goto LAB_0024c1d8;
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
    if (bVar11) {
      (*DAT_0037f118)("PRB_SFIXED32: %d\n",*param_2);
    }
    goto LAB_0024c218;
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
    if (bVar11) {
      (*DAT_0037f118)("PRB_SFIXED64: %lld\n",*(undefined8 *)param_2);
    }
LAB_0024c1d8:
    *(undefined8 *)(uVar7 * 0x10 + param_1[1]) = *(undefined8 *)param_2;
    return 0;
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
    if (bVar11) {
      (*DAT_0037f118)("PRB_BOOL: %u\n",*param_2);
    }
    iVar2 = 0;
    *(undefined1 *)(uVar7 * 0x10 + param_1[1]) = *(undefined1 *)param_2;
    break;
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
    if (bVar11) {
      (*DAT_0037f118)("PRB_ENUM: %d\n",*param_2);
    }
LAB_0024c218:
    *(float *)(uVar7 * 0x10 + param_1[1]) = *param_2;
    return 0;
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
    if (bVar11) {
      (*DAT_0037f118)("PRB_STRING\n");
    }
    lVar10 = param_1[1];
    lVar8 = uVar7 * 0x10;
    pvVar4 = malloc(*(long *)param_2 + 1);
    *(void **)(lVar10 + lVar8) = pvVar4;
    if (*(void **)(param_1[1] + lVar8) == (void *)0x0) {
      iVar2 = 2;
      (*DAT_0037f118)("Failed to allocate memory for string\n");
    }
    else {
      iVar2 = 0;
      memcpy(*(void **)(param_1[1] + lVar8),*(void **)(param_2 + 2),*(size_t *)param_2);
      *(undefined1 *)(*(long *)(param_1[1] + lVar8) + *(long *)param_2) = 0;
      *(int *)(param_1[1] + 8 + lVar8) = (int)*(undefined8 *)param_2;
    }
    break;
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
    if (bVar11) {
      (*DAT_0037f118)("PRB_BYTES\n");
    }
    lVar10 = param_1[1];
    lVar8 = uVar7 * 0x10;
    pvVar4 = malloc(*(size_t *)param_2);
    *(void **)(lVar10 + lVar8) = pvVar4;
    if ((*(size_t *)param_2 == 0) || (*(void **)(param_1[1] + lVar8) != (void *)0x0)) {
      iVar2 = 0;
      memcpy(*(void **)(param_1[1] + lVar8),*(void **)(param_2 + 2),*(size_t *)param_2);
      *(int *)(param_1[1] + 8 + lVar8) = (int)*(undefined8 *)param_2;
    }
    else {
      iVar2 = 2;
      (*DAT_0037f118)("Failed to allocate memory for bytes\n");
    }
    break;
  case 0x40:
  case 0x41:
  case 0x42:
  case 0x43:
    if (bVar11) {
      (*DAT_0037f118)("PRB_MESSAGE\n");
    }
    lVar10 = param_1[1];
    lVar9 = uVar7 * 0x10;
    lVar8 = *(long *)(lVar10 + lVar9);
    if (lVar8 == 0) {
      pvVar4 = malloc(0x18);
      *(long *)(lVar10 + lVar9) = (long)pvVar4;
      *(undefined4 *)(param_1[1] + 8 + lVar9) = 0x18;
      if (*(long *)(param_1[1] + lVar9) == 0) {
        (*DAT_0037f118)("Failed to allocate message field\n");
        return 2;
      }
      iVar2 = FUN_0024b9d0(*(long *)(param_1[1] + lVar9),*(undefined8 *)(*param_1 + 8));
      if (iVar2 != 0) {
        (*DAT_0037f118)("Failed to create message field\n");
        return iVar2;
      }
      lVar8 = *(long *)(param_1[1] + lVar9);
    }
    DAT_012182e4 = DAT_012182e4 + 1;
    iVar2 = FUN_0024bbb0(lVar8,*(undefined8 *)(param_2 + 2),*(undefined8 *)param_2);
    DAT_012182e4 = DAT_012182e4 + -1;
  }
  return iVar2;
}


// ===== 0024c670 FUN_0024c670 =====

long * FUN_0024c670(undefined8 *param_1,long param_2)

{
  long *plVar1;
  long *plVar2;
  
  if (*(int *)*param_1 != 0) {
    plVar2 = (long *)param_1[1];
    plVar1 = plVar2 + (ulong)(*(int *)*param_1 - 1) * 3 + 3;
    do {
      if (*plVar2 == param_2) {
        return plVar2;
      }
      plVar2 = plVar2 + 3;
    } while (plVar2 != plVar1);
  }
  (*DAT_0037f118)("Invalid message field\n");
  return (long *)0x0;
}


// ===== 0024c6c0 FUN_0024c6c0 =====

undefined8 FUN_0024c6c0(undefined8 *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 1) != 0) {
    piVar2 = (int *)*param_1;
    piVar1 = piVar2 + (ulong)(*(int *)(param_1 + 1) - 1) * 4 + 4;
    do {
      if (*piVar2 == param_2) {
        return *(undefined8 *)(piVar2 + 2);
      }
      piVar2 = piVar2 + 4;
    } while (piVar2 != piVar1);
  }
  (*DAT_0037f118)("Invalid %s enum value %d\n",param_1[2]);
  return 0;
}


// ===== 0024c720 FUN_0024c720 =====

long FUN_0024c720(long *param_1,undefined8 param_2)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  
  if ((int)param_1[2] == 0) {
    return 0;
  }
  if ((*(byte *)(*param_1 + 4) & 0xfc) == 0x40) {
    uVar3 = 0;
    do {
      lVar1 = FUN_0024c790(*(undefined8 *)(uVar3 * 0x10 + param_1[1]),param_2);
      if (lVar1 != 0) {
        return lVar1;
      }
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulong)uVar2;
    } while (uVar2 < *(uint *)(param_1 + 2));
  }
  return 0;
}


// ===== 0024c790 FUN_0024c790 =====

undefined8 * FUN_0024c790(undefined8 *param_1,int *param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  
  if ((int *)*param_1 == param_2) {
    return param_1;
  }
  uVar2 = 0;
  if (*(int *)*param_1 != 0) {
    do {
      puVar1 = (undefined8 *)FUN_0024c720(param_1[1] + (ulong)uVar2 * 0x18,param_2);
      if (puVar1 != (undefined8 *)0x0) {
        return puVar1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)*param_1);
  }
  return (undefined8 *)0x0;
}


// ===== 0024c810 FUN_0024c810 =====

void FUN_0024c810(long *param_1,long param_2,long param_3,uint param_4)

{
  *param_1 = param_3;
  param_1[1] = param_3;
  param_1[0x28] = 1;
  param_1[2] = param_3 + (ulong)param_4;
  param_1[3] = 0;
  param_1[4] = param_2;
  return;
}


// ===== 0024c840 FUN_0024c840 =====

ulong FUN_0024c840(ulong param_1,ulong param_2,uint param_3)

{
  long lVar1;
  ulong uVar2;
  
  if (param_2 < param_1) {
    if (param_3 != 0) {
      lVar1 = -1;
      do {
        *(undefined1 *)(param_3 + param_1 + lVar1) = *(undefined1 *)(param_2 + param_3 + lVar1);
        lVar1 = lVar1 + -1;
      } while (-2 - (ulong)(param_3 - 1) != lVar1);
    }
  }
  else if ((param_2 != param_1) && (param_3 != 0)) {
    uVar2 = 0;
    do {
      *(undefined1 *)(param_1 + uVar2) = *(undefined1 *)(param_2 + uVar2);
      uVar2 = uVar2 + 1;
    } while (uVar2 != param_3);
    return param_1;
  }
  return param_1;
}


// ===== 0024c8b0 FUN_0024c8b0 =====

undefined8 FUN_0024c8b0(long param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  int *piVar4;
  long lVar5;
  byte *pbVar6;
  long lVar7;
  uint uVar8;
  ulong uVar9;
  byte bVar10;
  ulong uVar11;
  
  iVar3 = *(int *)(param_1 + 0x140);
  if (iVar3 < 1) {
    return 3;
  }
  if ((*(uint *)(param_1 + 0x144) & 4) == 0) {
    return 0;
  }
  *(uint *)(param_1 + 0x144) = *(uint *)(param_1 + 0x144) & 0xfffffffb;
  piVar4 = *(int **)(param_1 + 0x18 + (long)(iVar3 + -1) * 0x28);
  lVar1 = param_1 + (long)iVar3 * 0x28;
  lVar5 = *(long *)(lVar1 + -0x28);
  uVar9 = *(long *)(lVar1 + -0x20) - lVar5;
  if (iVar3 == 1) {
    return 3;
  }
  *(int *)(param_1 + 0x140) = iVar3 + -1;
  uVar8 = (uint)uVar9;
  if (uVar8 != 0) {
    pbVar6 = *(byte **)(lVar1 + -0x48);
    lVar7 = (long)(iVar3 + -2);
    uVar11 = (ulong)(*piVar4 * 8 + 2);
    lVar2 = param_1 + lVar7 * 0x28;
    if (*(int *)(lVar2 + 0x10) == (int)pbVar6) {
      return 1;
    }
    do {
      bVar10 = (byte)uVar11;
      if (uVar11 < 0x80) {
        *pbVar6 = bVar10;
        uVar9 = uVar9 & 0xffffffff;
        lVar2 = param_1 + lVar7 * 0x28;
        pbVar6 = (byte *)(*(long *)(lVar1 + -0x48) + 1);
        *(byte **)(lVar1 + -0x48) = pbVar6;
        uVar11 = uVar9;
        if (*(int *)(lVar2 + 0x10) == (int)pbVar6) {
          return 1;
        }
        do {
          bVar10 = (byte)uVar11;
          if (uVar11 < 0x80) {
            *pbVar6 = bVar10;
            lVar2 = *(long *)(lVar1 + -0x48) + 1;
            *(long *)(lVar1 + -0x48) = lVar2;
            if ((uint)((int)*(undefined8 *)(param_1 + 0x10 + lVar7 * 0x28) - (int)lVar2) < uVar8) {
              return 1;
            }
            FUN_0024c840(lVar2,lVar5);
            *(long *)(lVar1 + -0x48) = *(long *)(lVar1 + -0x48) + uVar9;
            return 0;
          }
          uVar11 = uVar11 >> 7;
          *pbVar6 = bVar10 | 0x80;
          pbVar6 = (byte *)(*(long *)(lVar1 + -0x48) + 1);
          *(byte **)(lVar1 + -0x48) = pbVar6;
        } while (*(int *)(lVar2 + 0x10) != (int)pbVar6);
        return 1;
      }
      uVar11 = uVar11 >> 7;
      *pbVar6 = bVar10 | 0x80;
      pbVar6 = (byte *)(*(long *)(lVar1 + -0x48) + 1);
      *(byte **)(lVar1 + -0x48) = pbVar6;
    } while (*(int *)(lVar2 + 0x10) != (int)pbVar6);
    return 1;
  }
  return 0;
}


// ===== 0024ca20 FUN_0024ca20 =====

long FUN_0024ca20(long *param_1,long *param_2)

{
  long lVar1;
  
  if ((*(byte *)((long)param_1 + 0x144) & 1) == 0) {
    FUN_0024c8b0();
  }
  lVar1 = *param_1;
  *param_2 = lVar1;
  *(uint *)((long)param_1 + 0x144) = *(uint *)((long)param_1 + 0x144) | 1;
  return param_1[1] - lVar1;
}


// ===== 0024ca60 FUN_0024ca60 =====

undefined8 FUN_0024ca60(long param_1,long param_2)

{
  long *plVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  uint uVar5;
  
  if ((*(byte *)(param_1 + 0x144) & 1) != 0) {
    return 3;
  }
  uVar3 = FUN_0024c8b0();
  if ((int)uVar3 == 0) {
    if ((*(byte *)(param_2 + 4) & 0xfc) != 0x40) {
      return 3;
    }
    iVar2 = *(int *)(param_1 + 0x140);
    if (iVar2 < 8) {
      *(int *)(param_1 + 0x140) = iVar2 + 1;
      plVar1 = (long *)(param_1 + (long)iVar2 * 0x28);
      plVar1[3] = param_2;
      plVar1[4] = *(long *)(param_2 + 8);
      uVar5 = (int)*(undefined8 *)(param_1 + 0x10 + (long)(iVar2 + -1) * 0x28) - (int)plVar1[-4];
      if (uVar5 < 10) {
        *(int *)(param_1 + 0x140) = iVar2;
        uVar3 = 1;
      }
      else {
        lVar4 = plVar1[-4] + 10;
        *plVar1 = lVar4;
        plVar1[1] = lVar4;
        plVar1[2] = lVar4 + (ulong)(uVar5 - 10);
      }
    }
    else {
      uVar3 = 2;
    }
  }
  return uVar3;
}


// ===== 0024cb40 FUN_0024cb40 =====

/* WARNING: Type propagation algorithm not settling */

int FUN_0024cb40(long param_1,int *param_2,ulong *param_3)

{
  void *__dest;
  long *plVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  byte *pbVar5;
  uint uVar6;
  ulong __n;
  ulong uVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  uint uVar11;
  void *__src;
  
  if ((*(byte *)(param_1 + 0x144) & 1) != 0) {
    return 3;
  }
  if (*(int *)(param_1 + 0x140) < 1) {
    return 3;
  }
  lVar10 = (long)(*(int *)(param_1 + 0x140) + -1);
  piVar4 = *(int **)(param_1 + 0x20 + lVar10 * 0x28);
  iVar3 = *piVar4;
  if (iVar3 == 0) {
    return 3;
  }
  piVar4 = *(int **)(piVar4 + 2);
  __n = 0;
  if (param_2 != piVar4) {
    iVar8 = 0;
    do {
      iVar8 = iVar8 + 1;
      if (iVar8 == iVar3) {
        return 3;
      }
      piVar4 = piVar4 + 8;
    } while (param_2 != piVar4);
  }
  bVar2 = *(byte *)((long)param_2 + 5) & 2;
  if ((*(byte *)((long)param_2 + 5) & 2) != 0) {
    lVar9 = param_1 + lVar10 * 0x28;
    if (*(int **)(lVar9 + 0x18) != param_2) {
      iVar3 = FUN_0024c8b0(param_1);
      if (iVar3 != 0) {
        return iVar3;
      }
      if ((*(byte *)((long)param_2 + 5) & 2) == 0) {
        return 3;
      }
      iVar3 = *(int *)(param_1 + 0x140);
      if (7 < iVar3) {
        return 2;
      }
      lVar10 = (long)iVar3;
      *(int *)(param_1 + 0x140) = iVar3 + 1;
      plVar1 = (long *)(param_1 + lVar10 * 0x28);
      lVar9 = param_1 + (long)(iVar3 + -1) * 0x28;
      plVar1[3] = (long)param_2;
      plVar1[4] = *(long *)(lVar9 + 0x20);
      uVar6 = *(uint *)(param_1 + 0x144);
      *(uint *)(param_1 + 0x144) = uVar6 | 4;
      uVar11 = (int)*(undefined8 *)(lVar9 + 0x10) - (int)plVar1[-4];
      if (uVar11 < 10) {
        *(int *)(param_1 + 0x140) = iVar3;
        *(uint *)(param_1 + 0x144) = uVar6 & 0xfffffffb;
        return 1;
      }
      lVar9 = plVar1[-4] + 10;
      *plVar1 = lVar9;
      plVar1[1] = lVar9;
      lVar9 = lVar9 + (ulong)(uVar11 - 10);
      plVar1[2] = lVar9;
      goto LAB_0024cc9a;
    }
    iVar3 = (int)*(undefined8 *)(lVar9 + 0x10);
    switch((char)param_2[1]) {
    case '\0':
    case '\x01':
    case '\x02':
    case '\x03':
    case '$':
    case '%':
    case '&':
    case '\'':
    case ',':
    case '-':
    case '.':
    case '/':
      goto switchD_0024ccc6_caseD_0;
    case '\x04':
    case '\x05':
    case '\x06':
    case '\a':
    case ' ':
    case '!':
    case '\"':
    case '#':
    case '(':
    case ')':
    case '*':
    case '+':
      goto switchD_0024ccc6_caseD_4;
    case '\b':
    case '\t':
    case '\n':
    case '\v':
    case '4':
    case '5':
    case '6':
    case '7':
      goto switchD_0024ccc6_caseD_8;
    case '\f':
    case '\r':
    case '\x0e':
    case '\x0f':
    case '\x14':
    case '\x15':
    case '\x16':
    case '\x17':
      goto switchD_0024ccc6_caseD_c;
    case '\x10':
    case '\x11':
    case '\x12':
    case '\x13':
      goto switchD_0024ccc6_caseD_10;
    case '\x18':
    case '\x19':
    case '\x1a':
    case '\x1b':
      goto switchD_0024ccc6_caseD_18;
    case '\x1c':
    case '\x1d':
    case '\x1e':
    case '\x1f':
      goto switchD_0024ccc6_caseD_1c;
    case '0':
    case '1':
    case '2':
    case '3':
      goto switchD_0024ccc6_caseD_30;
    case '8':
    case '9':
    case ':':
    case ';':
    case '<':
    case '=':
    case '>':
    case '?':
    case '@':
    case 'A':
    case 'B':
    case 'C':
      goto switchD_0024ccc6_caseD_38;
    default:
      pbVar5 = *(byte **)(lVar9 + 8);
      uVar6 = 0;
      goto LAB_0024cce7;
    }
  }
  iVar3 = FUN_0024c8b0(param_1);
  if (iVar3 != 0) {
    return iVar3;
  }
  lVar10 = (long)(*(int *)(param_1 + 0x140) + -1);
  lVar9 = *(long *)(param_1 + 0x10 + lVar10 * 0x28);
LAB_0024cc9a:
  iVar3 = (int)lVar9;
  bVar2 = *(byte *)((long)param_2 + 5) & 2;
  switch((char)param_2[1]) {
  case '\0':
  case '\x01':
  case '\x02':
  case '\x03':
  case '$':
  case '%':
  case '&':
  case '\'':
  case ',':
  case '-':
  case '.':
  case '/':
    goto switchD_0024ccc6_caseD_0;
  case '\x04':
  case '\x05':
  case '\x06':
  case '\a':
  case ' ':
  case '!':
  case '\"':
  case '#':
  case '(':
  case ')':
  case '*':
  case '+':
switchD_0024ccc6_caseD_4:
    uVar6 = (uint)*param_3;
    __n = (ulong)uVar6;
    if (bVar2 != 0) {
      pbVar5 = *(byte **)(param_1 + 8 + lVar10 * 0x28);
LAB_0024cce7:
      if (3 < (uint)(iVar3 - (int)pbVar5)) {
        *pbVar5 = (byte)uVar6;
        param_1 = param_1 + lVar10 * 0x28;
        *(char *)(*(long *)(param_1 + 8) + 1) = (char)(uVar6 >> 8);
        *(char *)(*(long *)(param_1 + 8) + 2) = (char)(uVar6 >> 0x10);
        *(char *)(*(long *)(param_1 + 8) + 3) = (char)(uVar6 >> 0x18);
        *(long *)(param_1 + 8) = *(long *)(param_1 + 8) + 4;
        return 0;
      }
      return 1;
    }
    uVar6 = 5;
    __src = (void *)0x0;
    goto LAB_0024cedf;
  case '\b':
  case '\t':
  case '\n':
  case '\v':
  case '4':
  case '5':
  case '6':
  case '7':
switchD_0024ccc6_caseD_8:
    __n = (ulong)(int)(uint)*param_3;
    break;
  case '\f':
  case '\r':
  case '\x0e':
  case '\x0f':
  case '\x14':
  case '\x15':
  case '\x16':
  case '\x17':
switchD_0024ccc6_caseD_c:
    __n = *param_3;
    break;
  case '\x10':
  case '\x11':
  case '\x12':
  case '\x13':
switchD_0024ccc6_caseD_10:
    __n = (ulong)(uint)*param_3;
    break;
  case '\x18':
  case '\x19':
  case '\x1a':
  case '\x1b':
switchD_0024ccc6_caseD_18:
    __n = (ulong)((uint)*param_3 * 2 ^ (int)(uint)*param_3 >> 0x1f);
    break;
  case '\x1c':
  case '\x1d':
  case '\x1e':
  case '\x1f':
switchD_0024ccc6_caseD_1c:
    __n = *param_3 * 2 ^ (long)*param_3 >> 0x3f;
    break;
  case '0':
  case '1':
  case '2':
  case '3':
switchD_0024ccc6_caseD_30:
    __n = (ulong)(byte)*param_3;
    break;
  case '8':
  case '9':
  case ':':
  case ';':
  case '<':
  case '=':
  case '>':
  case '?':
  case '@':
  case 'A':
  case 'B':
  case 'C':
switchD_0024ccc6_caseD_38:
    __src = (void *)*param_3;
    __n = (ulong)(uint)param_3[1];
    if (bVar2 != 0) {
      pbVar5 = *(byte **)(param_1 + 8 + lVar10 * 0x28);
LAB_0024cdeb:
      lVar9 = param_1 + lVar10 * 0x28;
      uVar7 = __n;
      if (iVar3 == (int)pbVar5) {
        return 1;
      }
      do {
        if (uVar7 < 0x80) {
          *pbVar5 = (byte)uVar7;
          param_1 = param_1 + lVar10 * 0x28;
          __dest = (void *)(*(long *)(param_1 + 8) + 1);
          *(void **)(param_1 + 8) = __dest;
          if (__n <= (uint)((int)*(undefined8 *)(param_1 + 0x10) - (int)__dest)) {
            if ((*(byte *)(param_2 + 1) & 0xfc) == 0x40) {
              FUN_0024c840(__dest,__src,__n & 0xffffffff);
            }
            else {
              memcpy(__dest,__src,__n);
            }
            *(long *)(param_1 + 8) = *(long *)(param_1 + 8) + __n;
            return 0;
          }
          return 1;
        }
        *pbVar5 = (byte)uVar7 | 0x80;
        pbVar5 = (byte *)(*(long *)(lVar9 + 8) + 1);
        *(byte **)(lVar9 + 8) = pbVar5;
        uVar7 = uVar7 >> 7;
      } while ((int)*(undefined8 *)(lVar9 + 0x10) != (int)pbVar5);
      return 1;
    }
    uVar6 = 2;
    goto LAB_0024cedf;
  default:
    uVar6 = 5;
    __src = (void *)0x0;
    if (bVar2 == 0) goto LAB_0024cedf;
    uVar6 = 0;
    pbVar5 = *(byte **)(param_1 + 8 + lVar10 * 0x28);
    goto LAB_0024cce7;
  }
  if (bVar2 != 0) {
LAB_0024ce84:
    param_1 = param_1 + lVar10 * 0x28;
    pbVar5 = *(byte **)(param_1 + 8);
    if (iVar3 == (int)pbVar5) {
      return 1;
    }
    do {
      bVar2 = (byte)__n;
      if (__n < 0x80) {
        *pbVar5 = bVar2;
        *(long *)(param_1 + 8) = *(long *)(param_1 + 8) + 1;
        return 0;
      }
      __n = __n >> 7;
      *pbVar5 = bVar2 | 0x80;
      pbVar5 = (byte *)(*(long *)(param_1 + 8) + 1);
      *(byte **)(param_1 + 8) = pbVar5;
    } while ((int)*(undefined8 *)(param_1 + 0x10) != (int)pbVar5);
    return 1;
  }
  uVar6 = 0;
  __src = (void *)0x0;
LAB_0024cedf:
  lVar9 = param_1 + lVar10 * 0x28;
  uVar7 = (ulong)(*param_2 * 8 | uVar6);
  pbVar5 = *(byte **)(lVar9 + 8);
  if (iVar3 != (int)pbVar5) {
    do {
      bVar2 = (byte)uVar7;
      if (uVar7 < 0x80) {
        *pbVar5 = bVar2;
        pbVar5 = (byte *)(*(long *)(lVar9 + 8) + 1);
        *(byte **)(lVar9 + 8) = pbVar5;
        if (uVar6 == 2) {
          iVar3 = (int)*(undefined8 *)(param_1 + 0x10 + lVar10 * 0x28);
          goto LAB_0024cdeb;
        }
        if (2 < uVar6) {
          if (uVar6 != 5) {
            return 0;
          }
          uVar6 = (uint)__n;
          iVar3 = (int)*(undefined8 *)(param_1 + 0x10 + lVar10 * 0x28);
          goto LAB_0024cce7;
        }
        if (uVar6 == 0) {
          iVar3 = (int)*(undefined8 *)(param_1 + 0x10 + lVar10 * 0x28);
          goto LAB_0024ce84;
        }
        if (uVar6 != 1) {
          return 0;
        }
        iVar3 = (int)*(undefined8 *)(param_1 + 0x10 + lVar10 * 0x28);
        goto LAB_0024cd47;
      }
      uVar7 = uVar7 >> 7;
      *pbVar5 = bVar2 | 0x80;
      pbVar5 = (byte *)(*(long *)(lVar9 + 8) + 1);
      *(byte **)(lVar9 + 8) = pbVar5;
    } while ((int)*(undefined8 *)(lVar9 + 0x10) != (int)pbVar5);
  }
  return 1;
switchD_0024ccc6_caseD_0:
  __n = *param_3;
  if (bVar2 != 0) {
    pbVar5 = *(byte **)(param_1 + 8 + lVar10 * 0x28);
LAB_0024cd47:
    if (7 < (uint)(iVar3 - (int)pbVar5)) {
      *pbVar5 = (byte)__n;
      param_1 = param_1 + lVar10 * 0x28;
      *(char *)(*(long *)(param_1 + 8) + 1) = (char)(__n >> 8);
      *(char *)(*(long *)(param_1 + 8) + 2) = (char)(__n >> 0x10);
      *(char *)(*(long *)(param_1 + 8) + 3) = (char)(__n >> 0x18);
      *(char *)(*(long *)(param_1 + 8) + 4) = (char)(__n >> 0x20);
      *(char *)(*(long *)(param_1 + 8) + 5) = (char)(__n >> 0x28);
      *(char *)(*(long *)(param_1 + 8) + 6) = (char)(__n >> 0x30);
      *(char *)(*(long *)(param_1 + 8) + 7) = (char)(__n >> 0x38);
      *(long *)(param_1 + 8) = *(long *)(param_1 + 8) + 8;
      return 0;
    }
    return 1;
  }
  uVar6 = 1;
  __src = (void *)0x0;
  goto LAB_0024cedf;
}


// ===== 0024d110 FUN_0024d110 =====

undefined8 FUN_0024d110(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 local_28 [16];
  
  local_28 = (undefined1  [16])0x0;
  if ((*(byte *)(param_1 + 0x144) & 1) != 0) {
    return 3;
  }
  uVar3 = FUN_0024c8b0();
  if ((int)uVar3 == 0) {
    iVar2 = *(int *)(param_1 + 0x140);
    if (iVar2 < 2) {
      return 3;
    }
    lVar1 = param_1 + (long)iVar2 * 0x28;
    *(int *)(param_1 + 0x140) = iVar2 + -1;
    uVar3 = *(undefined8 *)(lVar1 + -0x28);
    local_28._8_4_ = (int)*(undefined8 *)(lVar1 + -0x20) - (int)uVar3;
    local_28._0_8_ = uVar3;
    uVar3 = FUN_0024cb40(param_1,*(undefined8 *)(param_1 + 0x18 + (long)(iVar2 + -1) * 0x28),
                         local_28);
  }
  return uVar3;
}


// ===== 0024d1a0 FUN_0024d1a0 =====

void FUN_0024d1a0(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  undefined4 local_18;
  undefined1 auStack_14 [12];
  
  auStack_14 = SUB1612((undefined1  [16])0x0,4);
  local_18 = param_3;
  FUN_0024cb40(param_1,param_2,&local_18);
  return;
}


// ===== 0024d1c0 FUN_0024d1c0 =====

void FUN_0024d1c0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined8 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  local_18 = param_3;
  local_10 = param_4;
  FUN_0024cb40(param_1,param_2,&local_18);
  return;
}


// ===== 0024d1e1 FUN_0024d1e1 =====

long FUN_0024d1e1(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long local_10;
  
  iVar1 = FUN_002620a3(param_2);
  if (iVar1 == 0) {
    for (local_10 = *(long *)(param_3 + 0x78); local_10 != 0; local_10 = *(long *)(local_10 + 0x58))
    {
      if ((*(long *)(local_10 + 0xb8) != 0) &&
         (iVar1 = FUN_002623d5(param_2,*(undefined8 *)(local_10 + 0xb8)), iVar1 != 0)) {
        return local_10;
      }
    }
  }
  return 0;
}


// ===== 0024d268 FUN_0024d268 =====

undefined8 FUN_0024d268(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_00257fb0(param_1,param_2);
  if (iVar1 == -1) {
    uVar2 = 0;
  }
  else if (iVar1 == -2) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_002580d2(param_1,iVar1,param_3);
  }
  return uVar2;
}


// ===== 0024d2be FUN_0024d2be =====

void FUN_0024d2be(undefined8 param_1)

{
  FUN_002580d2(param_1,0,0);
  return;
}


// ===== 0024d2e2 FUN_0024d2e2 =====

undefined8 FUN_0024d2e2(uint param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = param_1 >> 8;
  if ((((((uVar1 == 3) || (uVar1 == 2)) || (uVar1 == 1)) || ((uVar1 == 0 || (uVar1 == 0xb)))) ||
      ((param_1 == 0xc04 || ((param_1 == 0xc06 || (param_1 == 0x502)))))) ||
     ((uVar1 == 6 || (uVar1 == 0x12)))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 0024d345 FUN_0024d345 =====

bool FUN_0024d345(int param_1)

{
  return param_1 != 4;
}


// ===== 0024d358 FUN_0024d358 =====

bool FUN_0024d358(undefined8 param_1,undefined4 param_2)

{
  int local_c;
  
  local_c = 1;
  FUN_002543c3(param_1,param_2,&local_c);
  if (local_c == 3) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("filter != HWLOC_TYPE_FILTER_KEEP_IMPORTANT",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/include/hwloc/plugins.h"
                  ,0x218,"hwloc_filter_check_keep_object_type");
  }
  return local_c != 1;
}


// ===== 0024d3b8 FUN_0024d3b8 =====

undefined8 FUN_0024d3b8(undefined8 param_1,int *param_2)

{
  undefined8 uVar1;
  int local_10;
  int local_c;
  
  local_c = *param_2;
  local_10 = 1;
  FUN_002543c3(param_1,local_c,&local_10);
  if (local_10 == 1) {
    return 0;
  }
  if (local_10 == 3) {
    if (local_c == 0xf) {
      uVar1 = FUN_0024d2e2(*(undefined2 *)(*(long *)(param_2 + 10) + 6));
      return uVar1;
    }
    if (local_c == 0x10) {
      uVar1 = FUN_0024d345(**(undefined4 **)(param_2 + 10));
      return uVar1;
    }
  }
  return 1;
}


// ===== 0024d442 FUN_0024d442 =====

int FUN_0024d442(uint param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 2) {
    if ((param_1 == 0) || (3 < param_1)) {
      iVar1 = -1;
    }
    else {
      iVar1 = param_1 + 8;
    }
  }
  else if ((param_1 == 0) || (5 < param_1)) {
    iVar1 = -1;
  }
  else {
    iVar1 = param_1 + 3;
  }
  return iVar1;
}


// ===== 0024d488 FUN_0024d488 =====

undefined8 FUN_0024d488(uint param_1)

{
  undefined8 uVar1;
  
  if ((param_1 < 0xd) || (param_1 == 0x13)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 0024d4a9 FUN_0024d4a9 =====

undefined8 FUN_0024d4a9(int param_1)

{
  undefined8 uVar1;
  
  if ((param_1 == 0xd) || (param_1 == 0x12)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 0024d4ca FUN_0024d4ca =====

undefined8 FUN_0024d4ca(uint param_1)

{
  undefined8 uVar1;
  
  if ((param_1 < 0xe) || (0x11 < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== 0024d4eb FUN_0024d4eb =====

undefined8 FUN_0024d4eb(uint param_1)

{
  undefined8 uVar1;
  
  if ((param_1 < 0xe) || (0x10 < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== 0024d50c FUN_0024d50c =====

undefined8 FUN_0024d50c(uint param_1)

{
  undefined8 uVar1;
  
  if ((param_1 < 4) || (0xb < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== 0024d52d FUN_0024d52d =====

undefined8 FUN_0024d52d(uint param_1)

{
  undefined8 uVar1;
  
  if ((param_1 < 4) || (8 < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== 0024d54e FUN_0024d54e =====

undefined8 FUN_0024d54e(uint param_1)

{
  undefined8 uVar1;
  
  if ((param_1 < 9) || (0xb < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== 0024d56f FUN_0024d56f =====

void FUN_0024d56f(undefined8 *param_1,size_t param_2)

{
  if (param_1 == (undefined8 *)0x0) {
    malloc(param_2);
  }
  else {
    (*(code *)*param_1)(param_1,param_2);
  }
  return;
}


// ===== 0024d5ad FUN_0024d5ad =====

void * FUN_0024d5ad(undefined8 param_1,size_t param_2)

{
  void *__s;
  
  __s = (void *)FUN_0024d56f(param_1,param_2);
  if (__s != (void *)0x0) {
    memset(__s,0,param_2);
  }
  return __s;
}


// ===== 0024d5f6 FUN_0024d5f6 =====

void FUN_0024d5f6(void)

{
  return;
}


// ===== 0024d64f FUN_0024d64f =====

int FUN_0024d64f(void)

{
  char *__nptr;
  
  if (DAT_012182ec == 0) {
    __nptr = getenv("HWLOC_HIDE_ERRORS");
    if (__nptr != (char *)0x0) {
      DAT_003805bc = atoi(__nptr);
    }
    DAT_012182ec = 1;
  }
  return DAT_003805bc;
}


// ===== 0024d69c FUN_0024d69c =====

void FUN_0024d69c(char *param_1,size_t param_2,long param_3)

{
  char *pcVar1;
  undefined *puVar2;
  undefined *local_58;
  void *local_50;
  undefined1 local_48 [64];
  
  local_58 = (undefined *)0x0;
  FUN_00258b4a(local_48,0x40,param_3,0);
  FUN_00261562(&local_50,*(undefined8 *)(param_3 + 0xb8));
  if (*(long *)(param_3 + 200) != 0) {
    FUN_00261562(&local_58,*(undefined8 *)(param_3 + 200));
  }
  if (*(int *)(param_3 + 0x10) == -1) {
    if (local_58 == (undefined *)0x0) {
      puVar2 = &DAT_002e931d;
      pcVar1 = "";
    }
    else {
      pcVar1 = " nodeset ";
      puVar2 = local_58;
    }
    snprintf(param_1,param_2,"%s (cpuset %s%s%s)",local_48,local_50,pcVar1,puVar2);
  }
  else {
    if (local_58 == (undefined *)0x0) {
      puVar2 = &DAT_002e931d;
      pcVar1 = "";
    }
    else {
      pcVar1 = " nodeset ";
      puVar2 = local_58;
    }
    snprintf(param_1,param_2,"%s (P#%u cpuset %s%s%s)",local_48,(ulong)*(uint *)(param_3 + 0x10),
             local_50,pcVar1,puVar2);
  }
  free(local_50);
  free(local_58);
  return;
}


// ===== 0024d7f9 FUN_0024d7f9 =====

void FUN_0024d7f9(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  undefined1 local_408 [512];
  undefined1 local_208 [512];
  
  if ((param_4 != 0) && (DAT_012182f0 == 0)) {
    iVar1 = FUN_0024d64f();
    if (iVar1 < 2) {
      FUN_0024d69c(local_408,0x200,param_1);
      FUN_0024d69c(local_208,0x200,param_2);
      fwrite("****************************************************************************\n",1,0x4d
             ,*(FILE **)PTR_stderr_0032efe0);
      fprintf(*(FILE **)PTR_stderr_0032efe0,
              "* hwloc %s received invalid information from the operating system.\n","2.9.2");
      fwrite(&DAT_002e93f4,1,2,*(FILE **)PTR_stderr_0032efe0);
      fprintf(*(FILE **)PTR_stderr_0032efe0,"* Failed with: %s\n",param_3);
      fprintf(*(FILE **)PTR_stderr_0032efe0,"* while inserting %s at %s\n",local_408,local_208);
      fprintf(*(FILE **)PTR_stderr_0032efe0,"* coming from: %s\n",param_4);
      fwrite(&DAT_002e93f4,1,2,*(FILE **)PTR_stderr_0032efe0);
      fwrite("* The following FAQ entry in the hwloc documentation may help:\n",1,0x3f,
             *(FILE **)PTR_stderr_0032efe0);
      fwrite("*   What should I do when hwloc reports \"operating system\" warnings?\n",1,0x45,
             *(FILE **)PTR_stderr_0032efe0);
      fwrite("* Otherwise please report this error message to the hwloc user\'s mailing list,\n",1,
             0x4f,*(FILE **)PTR_stderr_0032efe0);
      fwrite("* along with the files generated by the hwloc-gather-topology script.\n",1,0x46,
             *(FILE **)PTR_stderr_0032efe0);
      fwrite(&DAT_002e955f,1,3,*(FILE **)PTR_stderr_0032efe0);
      fwrite("* hwloc will now ignore this invalid topology information and continue.\n",1,0x48,
             *(FILE **)PTR_stderr_0032efe0);
      fwrite("****************************************************************************\n",1,0x4d
             ,*(FILE **)PTR_stderr_0032efe0);
      DAT_012182f0 = 1;
    }
  }
  return;
}


// ===== 0024da86 FUN_0024da86 =====

int FUN_0024da86(uint param_1)

{
  long lVar1;
  
  if ((param_1 & 1) != 0) {
    lVar1 = sysconf(0x53);
    if ((int)lVar1 != -1) {
      return (int)lVar1;
    }
  }
  lVar1 = sysconf(0x54);
  return (int)lVar1;
}


// ===== 0024dac5 FUN_0024dac5 =====

undefined8 FUN_0024dac5(void)

{
  return 0xffffffffffffffff;
}


// ===== 0024dad7 FUN_0024dad7 =====

void FUN_0024dad7(undefined8 param_1,uint param_2)

{
  long lVar1;
  undefined8 uVar2;
  uint local_10;
  int local_c;
  
  FUN_0024d5f6(&DAT_002e95c6,"\n\n * CPU cpusets *\n\n");
  local_c = 0;
  for (local_10 = 0; local_10 < param_2; local_10 = local_10 + 1) {
    lVar1 = FUN_0024febd(param_1,3,local_c);
    uVar2 = FUN_00260eab();
    *(undefined8 *)(lVar1 + 0xb8) = uVar2;
    FUN_002618f3(*(undefined8 *)(lVar1 + 0xb8),local_c);
    FUN_0024fb45(param_1,0,lVar1,"core:pulevel");
    local_c = local_c + 1;
  }
  return;
}


// ===== 0024db80 FUN_0024db80 =====

void FUN_0024db80(void *param_1,uint param_2)

{
  uint local_c;
  
  for (local_c = 0; local_c < param_2; local_c = local_c + 1) {
    free(*(void **)((long)param_1 + (ulong)local_c * 0x10));
    free(*(void **)((long)param_1 + (ulong)local_c * 0x10 + 8));
  }
  free(param_1);
  return;
}


// ===== 0024dbec FUN_0024dbec =====

undefined8 FUN_0024dbec(undefined8 *param_1,uint *param_2,char *param_3,char *param_4)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  void *local_20;
  
  uVar1 = *param_2;
  local_20 = (void *)*param_1;
  uVar2 = uVar1 + 8 & 0xfffffff8;
  if (uVar1 != uVar2) {
    local_20 = realloc(local_20,(ulong)uVar2 << 4);
    if (local_20 == (void *)0x0) {
      return 0xffffffff;
    }
    *param_1 = local_20;
  }
  pcVar3 = strdup(param_3);
  *(char **)((ulong)uVar1 * 0x10 + (long)local_20) = pcVar3;
  if (*(long *)((long)local_20 + (ulong)uVar1 * 0x10) != 0) {
    pcVar3 = strdup(param_4);
    *(char **)((long)local_20 + (ulong)uVar1 * 0x10 + 8) = pcVar3;
    if (*(long *)((long)local_20 + (ulong)uVar1 * 0x10 + 8) != 0) {
      *param_2 = uVar1 + 1;
      return 0;
    }
    free(*(void **)((long)local_20 + (ulong)uVar1 * 0x10));
  }
  return 0xffffffff;
}


// ===== 0024dd20 FUN_0024dd20 =====

undefined8 FUN_0024dd20(long *param_1,uint *param_2,char *param_3,char *param_4,int param_5)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  undefined8 uVar5;
  uint local_c;
  
  lVar2 = *param_1;
  uVar1 = *param_2;
  local_c = 0;
  while( true ) {
    if (uVar1 <= local_c) {
      uVar5 = FUN_0024dbec(param_1,param_2,param_3,param_4);
      return uVar5;
    }
    iVar3 = strcmp(*(char **)(lVar2 + (ulong)local_c * 0x10),param_3);
    if (iVar3 == 0) break;
    local_c = local_c + 1;
  }
  if (param_5 != 0) {
    pcVar4 = strdup(param_4);
    if (pcVar4 == (char *)0x0) {
      return 0xffffffff;
    }
    free(*(void **)(lVar2 + (ulong)local_c * 0x10 + 8));
    *(char **)((ulong)local_c * 0x10 + lVar2 + 8) = pcVar4;
  }
  return 0;
}


// ===== 0024de0e FUN_0024de0e =====

undefined8 FUN_0024de0e(undefined8 *param_1,uint *param_2,undefined8 *param_3,uint *param_4)

{
  uint uVar1;
  void *__ptr;
  uint uVar2;
  undefined8 uVar3;
  uint local_1c;
  void *local_18;
  uint local_c;
  
  local_c = *param_2;
  local_18 = (void *)*param_1;
  uVar1 = *param_4;
  __ptr = (void *)*param_3;
  uVar2 = uVar1 + local_c + 7 & 0xfffffff8;
  if ((local_c == uVar2) ||
     (local_18 = realloc(local_18,(ulong)uVar2 << 4), local_18 != (void *)0x0)) {
    for (local_1c = 0; local_1c < uVar1; local_1c = local_1c + 1) {
      *(undefined8 *)((long)local_18 + (ulong)local_c * 0x10) =
           *(undefined8 *)((long)__ptr + (ulong)local_1c * 0x10);
      *(undefined8 *)((long)local_18 + (ulong)local_c * 0x10 + 8) =
           *(undefined8 *)((long)__ptr + (ulong)local_1c * 0x10 + 8);
      local_c = local_c + 1;
    }
    *param_1 = local_18;
    *param_2 = local_c;
    free(__ptr);
    *param_3 = 0;
    *param_4 = 0;
    uVar3 = 0;
  }
  else {
    for (local_1c = 0; local_1c < uVar1; local_1c = local_1c + 1) {
      free(*(void **)((long)__ptr + (ulong)local_1c * 0x10));
      free(*(void **)((long)__ptr + (ulong)local_1c * 0x10 + 8));
    }
    free(__ptr);
    *param_3 = 0;
    *param_4 = 0;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ===== 0024dfb5 FUN_0024dfb5 =====

void FUN_0024dfb5(long param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_0024dbec(param_1 + 0xd8,param_1 + 0xe0,param_2,param_3);
  return;
}


// ===== 0024dff4 FUN_0024dff4 =====

void FUN_0024dff4(int *param_1)

{
  if (*param_1 == 0xd) {
    free(*(void **)(*(long *)(param_1 + 10) + 0x10));
  }
  FUN_0024db80(*(undefined8 *)(param_1 + 0x36),param_1[0x38]);
  free(*(void **)(param_1 + 10));
  free(*(void **)(param_1 + 0x1c));
  free(*(void **)(param_1 + 2));
  free(*(void **)(param_1 + 6));
  FUN_00260f71(*(undefined8 *)(param_1 + 0x2e));
  FUN_00260f71(*(undefined8 *)(param_1 + 0x30));
  FUN_00260f71(*(undefined8 *)(param_1 + 0x32));
  FUN_00260f71(*(undefined8 *)(param_1 + 0x34));
  return;
}


// ===== 0024e0d0 FUN_0024e0d0 =====

void FUN_0024e0d0(void *param_1)

{
  FUN_0024dff4(param_1);
  free(param_1);
  return;
}


// ===== 0024e0f7 FUN_0024e0f7 =====

void FUN_0024e0f7(void *param_1,void *param_2)

{
  FUN_0024dff4(param_1);
  *(undefined8 *)((long)param_2 + 0x48) = *(undefined8 *)((long)param_1 + 0x48);
  *(undefined8 *)((long)param_2 + 0x58) = *(undefined8 *)((long)param_1 + 0x58);
  *(undefined8 *)((long)param_2 + 0x78) = *(undefined8 *)((long)param_1 + 0x78);
  *(undefined8 *)((long)param_2 + 0x90) = *(undefined8 *)((long)param_1 + 0x90);
  *(undefined8 *)((long)param_2 + 0xa0) = *(undefined8 *)((long)param_1 + 0xa0);
  *(undefined8 *)((long)param_2 + 0xb0) = *(undefined8 *)((long)param_1 + 0xb0);
  memcpy(param_1,param_2,0xf8);
  memset(param_2,0,0xf8);
  return;
}


// ===== 0024e1b6 FUN_0024e1b6 =====

void FUN_0024e1b6(long *param_1)

{
  long lVar1;
  undefined8 local_18;
  undefined8 local_10;
  
  lVar1 = *param_1;
  local_18 = (long *)(lVar1 + 0x78);
  local_10 = *local_18;
  while (local_10 != 0) {
    FUN_0024e1b6(local_18);
    if (local_10 == *local_18) {
      local_18 = (long *)(local_10 + 0x58);
    }
    local_10 = *local_18;
  }
  local_18 = (long *)(lVar1 + 0x90);
  local_10 = *local_18;
  while (local_10 != 0) {
    FUN_0024e1b6(local_18);
    if (local_10 == *local_18) {
      local_18 = (long *)(local_10 + 0x58);
    }
    local_10 = *local_18;
  }
  local_18 = (long *)(lVar1 + 0xa0);
  local_10 = *local_18;
  while (local_10 != 0) {
    FUN_0024e1b6(local_18);
    if (local_10 == *local_18) {
      local_18 = (long *)(local_10 + 0x58);
    }
    local_10 = *local_18;
  }
  local_18 = (long *)(lVar1 + 0xb0);
  local_10 = *local_18;
  while (local_10 != 0) {
    FUN_0024e1b6(local_18);
    if (local_10 == *local_18) {
      local_18 = (long *)(local_10 + 0x58);
    }
    local_10 = *local_18;
  }
  *param_1 = *(long *)(lVar1 + 0x58);
  FUN_0024e0d0(lVar1);
  return;
}


// ===== 0024e331 FUN_0024e331 =====

void FUN_0024e331(undefined8 param_1)

{
  undefined8 local_10;
  
  local_10 = param_1;
  FUN_0024e1b6(&local_10);
  return;
}


// ===== 0024e34c FUN_0024e34c =====

void FUN_0024e34c(long param_1)

{
  long local_10;
  
  local_10 = param_1;
  while (local_10 != 0) {
    FUN_0024e1b6(&local_10);
  }
  return;
}


// ===== 0024e372 FUN_0024e372 =====

long FUN_0024e372(long *param_1,long param_2,undefined8 param_3)

{
  long local_10;
  
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("firstnew",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x2bd,"insert_siblings_list");
  }
  *param_1 = param_2;
  *(undefined8 *)(param_2 + 0x48) = param_3;
  local_10 = param_2;
  while (*(long *)(local_10 + 0x58) != 0) {
    local_10 = *(long *)(local_10 + 0x58);
    *(undefined8 *)(local_10 + 0x48) = param_3;
  }
  return local_10 + 0x58;
}


// ===== 0024e3fc FUN_0024e3fc =====

void FUN_0024e3fc(long *param_1,long param_2,undefined8 param_3)

{
  long local_38;
  long *local_30;
  int local_24;
  long local_20;
  long local_18;
  long *local_10;
  
  local_24 = 0;
  local_20 = 0;
  for (local_10 = &local_38; *local_10 != 0; local_10 = (long *)(*local_10 + 0x58)) {
    *(undefined8 *)(*local_10 + 0x48) = param_3;
    local_24 = local_24 + 1;
    local_20 = *local_10;
  }
  for (local_18 = *param_1; local_18 != 0; local_18 = *(long *)(local_18 + 0x58)) {
    *(int *)(local_18 + 0x50) = *(int *)(local_18 + 0x50) + local_24;
  }
  local_38 = param_2;
  local_30 = param_1;
  *local_10 = *param_1;
  if (*local_30 != 0) {
    *(long *)(*local_30 + 0x60) = local_20;
  }
  *local_30 = local_38;
  return;
}


// ===== 0024e4c8 FUN_0024e4c8 =====

void FUN_0024e4c8(long *param_1,long param_2,undefined8 param_3)

{
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_24 = 0;
  local_20 = 0;
  for (local_10 = param_1; local_18 = param_2, *local_10 != 0; local_10 = (long *)(*local_10 + 0x58)
      ) {
    local_24 = local_24 + 1;
    local_20 = *local_10;
  }
  for (; local_18 != 0; local_18 = *(long *)(local_18 + 0x58)) {
    *(undefined8 *)(local_18 + 0x48) = param_3;
    *(int *)(local_18 + 0x50) = *(int *)(local_18 + 0x50) + local_24;
  }
  *local_10 = param_2;
  if (param_2 != 0) {
    *(long *)(param_2 + 0x60) = local_20;
  }
  return;
}


// ===== 0024e578 FUN_0024e578 =====

void FUN_0024e578(undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 *local_10;
  
  piVar1 = (int *)*param_1;
  local_10 = param_1;
  if (*piVar1 == 0x11) {
    if (*(long *)(piVar1 + 0x1e) != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!old->first_child",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x30e,"unlink_and_free_single_object");
    }
    if (*(long *)(piVar1 + 0x24) != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!old->memory_first_child",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x310,"unlink_and_free_single_object");
    }
    if (*(long *)(piVar1 + 0x28) != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!old->io_first_child",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x312,"unlink_and_free_single_object");
    }
    if (*(long *)(piVar1 + 0x2c) != 0) {
      local_10 = (undefined8 *)
                 FUN_0024e372(param_1,*(undefined8 *)(piVar1 + 0x2c),*(undefined8 *)(piVar1 + 0x12))
      ;
    }
    *local_10 = *(undefined8 *)(piVar1 + 0x16);
  }
  else {
    iVar2 = FUN_0024d4eb(*piVar1);
    if (iVar2 == 0) {
      iVar2 = FUN_0024d4a9(*piVar1);
      if (iVar2 == 0) {
        if (*(long *)(piVar1 + 0x1e) != 0) {
          local_10 = (undefined8 *)
                     FUN_0024e372(param_1,*(undefined8 *)(piVar1 + 0x1e),
                                  *(undefined8 *)(piVar1 + 0x12));
        }
        *local_10 = *(undefined8 *)(piVar1 + 0x16);
        if (*(long *)(piVar1 + 0x24) != 0) {
          FUN_0024e4c8(*(long *)(piVar1 + 0x12) + 0x90,*(undefined8 *)(piVar1 + 0x24),
                       *(undefined8 *)(piVar1 + 0x12));
        }
        if (*(long *)(piVar1 + 0x28) != 0) {
          FUN_0024e4c8(*(long *)(piVar1 + 0x12) + 0xa0,*(undefined8 *)(piVar1 + 0x28),
                       *(undefined8 *)(piVar1 + 0x12));
        }
        if (*(long *)(piVar1 + 0x2c) != 0) {
          FUN_0024e4c8(*(long *)(piVar1 + 0x12) + 0xb0,*(undefined8 *)(piVar1 + 0x2c),
                       *(undefined8 *)(piVar1 + 0x12));
        }
      }
      else {
        if (*(long *)(piVar1 + 0x1e) != 0) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("!old->first_child",
                        "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                        ,0x334,"unlink_and_free_single_object");
        }
        if (*(long *)(piVar1 + 0x28) != 0) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("!old->io_first_child",
                        "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                        ,0x336,"unlink_and_free_single_object");
        }
        if (*(long *)(piVar1 + 0x24) != 0) {
          local_10 = (undefined8 *)
                     FUN_0024e372(param_1,*(undefined8 *)(piVar1 + 0x24),
                                  *(undefined8 *)(piVar1 + 0x12));
        }
        *local_10 = *(undefined8 *)(piVar1 + 0x16);
        if (*(long *)(piVar1 + 0x2c) != 0) {
          FUN_0024e4c8(*(long *)(piVar1 + 0x12) + 0xb0,*(undefined8 *)(piVar1 + 0x2c),
                       *(undefined8 *)(piVar1 + 0x12));
        }
      }
    }
    else {
      if (*(long *)(piVar1 + 0x1e) != 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!old->first_child",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,800,"unlink_and_free_single_object");
      }
      if (*(long *)(piVar1 + 0x24) != 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!old->memory_first_child",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x322,"unlink_and_free_single_object");
      }
      if (*(long *)(piVar1 + 0x28) != 0) {
        local_10 = (undefined8 *)
                   FUN_0024e372(param_1,*(undefined8 *)(piVar1 + 0x28),
                                *(undefined8 *)(piVar1 + 0x12));
      }
      *local_10 = *(undefined8 *)(piVar1 + 0x16);
      if (*(long *)(piVar1 + 0x2c) != 0) {
        FUN_0024e4c8(*(long *)(piVar1 + 0x12) + 0xb0,*(undefined8 *)(piVar1 + 0x2c),
                     *(undefined8 *)(piVar1 + 0x12));
      }
    }
  }
  FUN_0024e0d0(piVar1);
  return;
}


// ===== 0024e995 FUN_0024e995 =====

int FUN_0024e995(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(&DAT_002eb440 + (ulong)param_1 * 4);
  iVar2 = *(int *)(&DAT_002eb440 + (ulong)param_2 * 4);
  iVar3 = FUN_0024d488(param_1);
  if (((iVar3 == 0) && (iVar3 = FUN_0024d488(param_2), iVar3 != 0)) && (param_2 != 0)) {
    return 0x7fffffff;
  }
  iVar3 = FUN_0024d488(param_2);
  if (((iVar3 == 0) && (iVar3 = FUN_0024d488(param_1), iVar3 != 0)) && (param_1 != 0)) {
    return 0x7fffffff;
  }
  return iVar1 - iVar2;
}


// ===== 0024ea2d FUN_0024ea2d =====

undefined8 FUN_0024ea2d(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_0024e995(*param_1,*param_2);
  if (iVar1 == 0x7fffffff) {
    uVar2 = 4;
  }
  else if (iVar1 < 1) {
    if (iVar1 < 0) {
      uVar2 = 2;
    }
    else if ((*param_1 == 0xc) &&
            ((*(int *)(*(long *)(param_1 + 10) + 4) != *(int *)(*(long *)(param_2 + 10) + 4) ||
             (*(int *)(*(long *)(param_1 + 10) + 8) != *(int *)(*(long *)(param_2 + 10) + 8))))) {
      uVar2 = 4;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


// ===== 0024ead8 FUN_0024ead8 =====

undefined8 FUN_0024ead8(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  long local_18;
  long local_10;
  
  iVar1 = FUN_0024d4ca(*param_1);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!hwloc__obj_type_is_special(obj1->type)",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x520,"hwloc_obj_cmp_sets");
  }
  iVar1 = FUN_0024d4ca(*param_2);
  if (iVar1 == 0) {
    if ((*(long *)(param_1 + 0x30) == 0) || (*(long *)(param_2 + 0x30) == 0)) {
      local_10 = *(long *)(param_1 + 0x2e);
      local_18 = *(long *)(param_2 + 0x2e);
    }
    else {
      local_10 = *(long *)(param_1 + 0x30);
      local_18 = *(long *)(param_2 + 0x30);
    }
    if ((((local_10 != 0) && (local_18 != 0)) && (iVar1 = FUN_002620a3(local_10), iVar1 == 0)) &&
       (iVar1 = FUN_002620a3(local_18), iVar1 == 0)) {
      uVar2 = FUN_00262ee8(local_10,local_18);
      return uVar2;
    }
    return 4;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("!hwloc__obj_type_is_special(obj2->type)",
                "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                ,0x521,"hwloc_obj_cmp_sets");
}


// ===== 0024ebf0 FUN_0024ebf0 =====

undefined8 FUN_0024ebf0(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((*(long *)(param_1 + 0xc0) == 0) || (*(long *)(param_2 + 0xc0) == 0)) {
    if ((*(long *)(param_1 + 0xb8) == 0) || (*(long *)(param_2 + 0xb8) == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = FUN_00262ca9(*(undefined8 *)(param_1 + 0xb8),*(undefined8 *)(param_2 + 0xb8));
    }
  }
  else {
    uVar1 = FUN_00262ca9(*(undefined8 *)(param_1 + 0xc0),*(undefined8 *)(param_2 + 0xc0));
  }
  return uVar1;
}


// ===== 0024ec8d FUN_0024ec8d =====

void FUN_0024ec8d(uint *param_1,long param_2)

{
  uint uVar1;
  
  if (*(int *)(param_2 + 0x10) == -1) {
    *(uint *)(param_2 + 0x10) = param_1[4];
  }
  if (param_1[0x38] != 0) {
    FUN_0024de0e(param_2 + 0xd8,param_2 + 0xe0,param_1 + 0x36,param_1 + 0x38);
  }
  if ((*(long *)(param_1 + 6) != 0) && (*(long *)(param_2 + 0x18) == 0)) {
    *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)(param_1 + 6);
    param_1[6] = 0;
    param_1[7] = 0;
  }
  if ((*(long *)(param_1 + 2) != 0) && (*(long *)(param_2 + 8) == 0)) {
    *(undefined8 *)(param_2 + 8) = *(undefined8 *)(param_1 + 2);
    param_1[2] = 0;
    param_1[3] = 0;
  }
  uVar1 = *param_1;
  if (3 < uVar1) {
    if (uVar1 < 0xc) {
      if (**(long **)(param_2 + 0x28) == 0) {
        **(undefined8 **)(param_2 + 0x28) = **(undefined8 **)(param_1 + 10);
      }
      if (*(int *)(*(long *)(param_2 + 0x28) + 0xc) == 0) {
        **(ulong **)(param_2 + 0x28) = (ulong)*(uint *)(*(long *)(param_1 + 10) + 0xc);
      }
      if (*(int *)(*(long *)(param_2 + 0x28) + 0x10) == 0) {
        **(ulong **)(param_2 + 0x28) = (ulong)*(uint *)(*(long *)(param_1 + 10) + 0xc);
      }
    }
    else if (((uVar1 == 0xd) && (**(long **)(param_1 + 10) != 0)) &&
            (**(long **)(param_2 + 0x28) == 0)) {
      **(undefined8 **)(param_2 + 0x28) = **(undefined8 **)(param_1 + 10);
      free(*(void **)(*(long *)(param_2 + 0x28) + 0x10));
      *(undefined4 *)(*(long *)(param_2 + 0x28) + 8) = *(undefined4 *)(*(long *)(param_1 + 10) + 8);
      *(undefined8 *)(*(long *)(param_2 + 0x28) + 0x10) =
           *(undefined8 *)(*(long *)(param_1 + 10) + 0x10);
      *(undefined8 *)(*(long *)(param_1 + 10) + 0x10) = 0;
      *(undefined4 *)(*(long *)(param_1 + 10) + 8) = 0;
    }
  }
  return;
}


// ===== 0024eea7 FUN_0024eea7 =====

int * FUN_0024eea7(long param_1,int *param_2,int *param_3)

{
  if ((*param_3 == 0xc) && (*param_2 == 0xc)) {
    if (*(char *)(*(long *)(param_3 + 10) + 0xc) == '\0') {
      if ((*(char *)(*(long *)(param_2 + 10) + 0xc) == '\0') &&
         (*(uint *)(*(long *)(param_3 + 10) + 4) < *(uint *)(*(long *)(param_2 + 10) + 4))) {
        FUN_0024e0f7(param_2,param_3);
        *(undefined4 *)(param_1 + 0xd0) = 1;
      }
    }
    else if (*(char *)(*(long *)(param_2 + 10) + 0xc) == '\0') {
      FUN_0024e0f7(param_2,param_3);
      *(undefined4 *)(param_1 + 0xd0) = 1;
      param_2 = param_3;
    }
    else {
      param_2 = (int *)0x0;
    }
  }
  else if ((*param_3 == 0xc) && (*(char *)(*(long *)(param_3 + 10) + 0xc) == '\0')) {
    if ((*param_2 == 3) && (*(int *)(*(long *)(param_3 + 10) + 4) == 0x3e9)) {
      param_2 = (int *)0x0;
    }
  }
  else if ((*param_2 == 0xc) && (*(char *)(*(long *)(param_2 + 10) + 0xc) == '\0')) {
    if ((*param_3 == 3) && (*(int *)(*(long *)(param_2 + 10) + 4) == 0x3e9)) {
      param_2 = (int *)0x0;
    }
    else {
      FUN_0024e0f7(param_2,param_3);
      *(undefined4 *)(param_1 + 0xd0) = 1;
    }
  }
  else {
    param_2 = (int *)0x0;
  }
  return param_2;
}


// ===== 0024f03c FUN_0024f03c =====

undefined4 * FUN_0024f03c(long param_1,long param_2,undefined4 *param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_3c;
  long *local_38;
  long *local_30;
  long *local_28;
  long local_20;
  undefined4 *local_18;
  undefined4 *local_10;
  
  local_18 = (undefined4 *)0x0;
  local_28 = (long *)(param_2 + 0x78);
  local_30 = (long *)(param_3 + 0x1e);
  local_38 = (long *)0x0;
  iVar2 = FUN_0024d4a9(*param_3);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!hwloc__obj_type_is_memory(obj->type)",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x5d6,"hwloc___insert_object_by_cpuset");
  }
  local_10 = *(undefined4 **)(param_2 + 0x78);
  if (local_10 != (undefined4 *)0x0) {
    local_18 = *(undefined4 **)(local_10 + 0x16);
  }
  while (local_10 != (undefined4 *)0x0) {
    iVar2 = FUN_0024ead8(param_3,local_10);
    local_3c = iVar2;
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)FUN_0024eea7(param_1,local_10,param_3);
      if (puVar3 != (undefined4 *)0x0) {
        return puVar3;
      }
      local_3c = FUN_0024ea2d(param_3,local_10);
    }
    switch(local_3c) {
    case 0:
      FUN_0024ec8d(param_3,local_10);
      return local_10;
    case 1:
      puVar3 = (undefined4 *)FUN_0024f03c(param_1,local_10,param_3,param_4);
      return puVar3;
    case 2:
      *local_28 = *(long *)(local_10 + 0x16);
      *(undefined8 *)(local_10 + 0x16) = 0;
      *local_30 = (long)local_10;
      local_30 = (long *)(local_10 + 0x16);
      *(undefined4 **)(local_10 + 0x12) = param_3;
      if (iVar2 == 0) {
        *(undefined8 *)(param_3 + 0x24) = *(undefined8 *)(local_10 + 0x24);
        *(undefined8 *)(local_10 + 0x24) = 0;
        for (local_20 = *(long *)(param_3 + 0x24); local_20 != 0;
            local_20 = *(long *)(local_20 + 0x58)) {
          *(undefined4 **)(local_20 + 0x48) = param_3;
        }
      }
      break;
    case 3:
      FUN_0024d7f9(param_3,local_10,"intersection without inclusion",param_4);
      if (local_38 == (long *)0x0) {
        local_28 = (long *)(param_2 + 0x78);
      }
      else {
        local_28 = local_38;
      }
      while (lVar1 = *(long *)(param_3 + 0x1e), lVar1 != 0) {
        *(undefined8 *)(param_3 + 0x1e) = *(undefined8 *)(lVar1 + 0x58);
        while ((*local_28 != 0 && (iVar2 = FUN_0024ebf0(*local_28,lVar1), iVar2 < 0))) {
          local_28 = (long *)(*local_28 + 0x58);
        }
        *(long *)(lVar1 + 0x58) = *local_28;
        *local_28 = lVar1;
        *(long *)(lVar1 + 0x48) = param_2;
      }
      return (undefined4 *)0x0;
    case 4:
      if ((local_38 == (long *)0x0) && (iVar2 = FUN_0024ebf0(param_3,local_10), iVar2 < 0)) {
        local_38 = local_28;
      }
      local_28 = (long *)(local_10 + 0x16);
    }
    local_10 = local_18;
    if (local_18 != (undefined4 *)0x0) {
      local_18 = *(undefined4 **)(local_18 + 0x16);
    }
  }
  if (*local_30 == 0) {
    if (*local_28 == 0) {
      if (local_38 == (long *)0x0) {
        local_38 = local_28;
      }
      *(long *)(param_3 + 0x16) = *local_38;
      *local_38 = (long)param_3;
      *(long *)(param_3 + 0x12) = param_2;
      *(undefined4 *)(param_1 + 0xd0) = 1;
      return param_3;
    }
                    /* WARNING: Subroutine does not return */
    __assert_fail("!*cur_children",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x617,"hwloc___insert_object_by_cpuset");
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("!*obj_children",
                "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                ,0x616,"hwloc___insert_object_by_cpuset");
}


// ===== 0024f405 FUN_0024f405 =====

long FUN_0024f405(undefined8 param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = FUN_0024d1e1(param_1,param_3,param_2);
  if ((lVar2 != 0) &&
     ((lVar2 == 0 ||
      (iVar1 = FUN_00262158(*(undefined8 *)(lVar2 + 0xb8),param_3), param_2 = lVar2, iVar1 == 0))))
  {
    param_2 = FUN_0024f405(param_1,lVar2,param_3);
  }
  return param_2;
}


// ===== 0024f485 FUN_0024f485 =====

int * FUN_0024f485(long param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  int *piVar4;
  int *local_10;
  
  iVar1 = FUN_002620a3(*(undefined8 *)(param_2 + 0xb8));
  if (iVar1 == 0) {
    local_10 = (int *)FUN_0024f405(param_1,*(undefined8 *)**(undefined8 **)(param_1 + 0x18),
                                   *(undefined8 *)(param_2 + 0xb8));
    if (local_10 == (int *)0x0) {
      local_10 = (int *)FUN_0024d2be(param_1);
    }
    if ((*local_10 == 3) && (local_10 = *(int **)(local_10 + 0x12), local_10 == (int *)0x0)) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("parent",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x65f,"hwloc__find_insert_memory_parent");
    }
    if ((local_10 != *(int **)**(undefined8 **)(param_1 + 0x18)) &&
       (iVar1 = FUN_00262158(*(undefined8 *)(local_10 + 0x2e),*(undefined8 *)(param_2 + 0xb8)),
       iVar1 != 0)) {
      return local_10;
    }
  }
  else {
    local_10 = *(int **)**(undefined8 **)(param_1 + 0x18);
  }
  iVar1 = FUN_0024d358(param_1,0xc);
  if ((iVar1 != 0) && (piVar2 = (int *)FUN_0024febd(param_1,0xc,0xffffffff), piVar2 != (int *)0x0))
  {
    *(undefined4 *)(*(long *)(piVar2 + 10) + 4) = 0x3e9;
    uVar3 = FUN_002611e2(*(undefined8 *)(param_2 + 0xb8));
    *(undefined8 *)(piVar2 + 0x2e) = uVar3;
    uVar3 = FUN_002611e2(*(undefined8 *)(param_2 + 0xc0));
    *(undefined8 *)(piVar2 + 0x30) = uVar3;
    if (((*(long *)(param_2 + 0xb8) == 0) == (*(long *)(piVar2 + 0x2e) == 0)) &&
       ((*(long *)(param_2 + 0xc0) == 0) == (*(long *)(piVar2 + 0x30) == 0))) {
      piVar4 = (int *)FUN_0024fb45(param_1,local_10,piVar2,param_3);
      if ((piVar4 != (int *)0x0) && (local_10 = piVar2, piVar4 != piVar2)) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("result == group",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x686,"hwloc__find_insert_memory_parent");
      }
    }
    else {
      FUN_0024e0d0(piVar2);
    }
  }
  return local_10;
}


// ===== 0024f6dc FUN_0024f6dc =====

int * FUN_0024f6dc(long param_1,long param_2,int *param_3,undefined8 param_4)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  long *local_10;
  
  local_10 = (long *)(param_2 + 0x90);
  uVar1 = FUN_00262aab(*(undefined8 *)(param_3 + 0x32));
  while( true ) {
    if (*local_10 == 0) {
      param_3[0x16] = 0;
      param_3[0x17] = 0;
      *local_10 = (long)param_3;
      param_3[0x24] = 0;
      param_3[0x25] = 0;
      *(long *)(param_3 + 0x12) = param_2;
      *(undefined4 *)(param_1 + 0xd0) = 1;
      return param_3;
    }
    piVar3 = (int *)*local_10;
    uVar2 = FUN_00262aab(*(undefined8 *)(piVar3 + 0x32));
    if (uVar1 < uVar2) {
      *(int **)(param_3 + 0x16) = piVar3;
      *local_10 = (long)param_3;
      param_3[0x24] = 0;
      param_3[0x25] = 0;
      *(long *)(param_3 + 0x12) = param_2;
      *(undefined4 *)(param_1 + 0xd0) = 1;
      return param_3;
    }
    if (uVar1 == uVar2) break;
    local_10 = (long *)(piVar3 + 0x16);
  }
  if (*param_3 != 0xd) {
    if (*param_3 != 0x12) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("obj->type == HWLOC_OBJ_MEMCACHE",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x6ad,"hwloc___attach_memory_object_by_nodeset");
    }
    if (*piVar3 == 0x12) {
      if (*(int *)(*(long *)(piVar3 + 10) + 8) == *(int *)(*(long *)(param_3 + 10) + 8)) {
        return (int *)0x0;
      }
      if (*(uint *)(*(long *)(param_3 + 10) + 8) < *(uint *)(*(long *)(piVar3 + 10) + 8)) {
        piVar3 = (int *)FUN_0024f6dc(param_1,piVar3,param_3,param_4);
        return piVar3;
      }
    }
    *(undefined8 *)(param_3 + 0x16) = *(undefined8 *)(piVar3 + 0x16);
    piVar3[0x16] = 0;
    piVar3[0x17] = 0;
    *(int **)(param_3 + 0x24) = piVar3;
    *(int **)(piVar3 + 0x12) = param_3;
    *local_10 = (long)param_3;
    *(long *)(param_3 + 0x12) = param_2;
    *(undefined4 *)(param_1 + 0xd0) = 1;
    return param_3;
  }
  if (*piVar3 == 0xd) {
    FUN_0024d7f9(param_3,piVar3,"NUMAnodes with identical nodesets",param_4);
    return (int *)0x0;
  }
  if (*piVar3 == 0x12) {
    piVar3 = (int *)FUN_0024f6dc(param_1,piVar3,param_3,param_4);
    return piVar3;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("cur->type == HWLOC_OBJ_MEMCACHE",
                "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                ,0x6a8,"hwloc___attach_memory_object_by_nodeset");
}


// ===== 0024f974 FUN_0024f974 =====

int * FUN_0024f974(long param_1,undefined4 *param_2,int *param_3,undefined8 param_4)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  
  if (param_2 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("parent",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x6df,"hwloc__attach_memory_object");
  }
  iVar1 = FUN_0024d488(*param_2);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("hwloc__obj_type_is_normal(parent->type)",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x6e0,"hwloc__attach_memory_object");
  }
  if ((*(long *)(param_3 + 0x32) == 0) ||
     (iVar1 = FUN_002620a3(*(undefined8 *)(param_3 + 0x32)), iVar1 != 0)) {
    piVar2 = (int *)0x0;
  }
  else {
    if (*(long *)(param_3 + 0x34) == 0) {
      uVar3 = FUN_002611e2(*(undefined8 *)(param_3 + 0x32));
      *(undefined8 *)(param_3 + 0x34) = uVar3;
    }
    else {
      iVar1 = FUN_002623d5(*(undefined8 *)(param_3 + 0x32),*(undefined8 *)(param_3 + 0x34));
      if (iVar1 == 0) {
        return (int *)0x0;
      }
    }
    iVar1 = FUN_00262e86(*(undefined8 *)(param_3 + 0x32));
    if (iVar1 != 1) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_bitmap_weight(obj->nodeset) == 1",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x6ec,"hwloc__attach_memory_object");
    }
    piVar2 = (int *)FUN_0024f6dc(param_1,param_2,param_3,param_4);
    if ((piVar2 == param_3) && (*param_3 == 0xd)) {
      FUN_0026197d(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 200),param_3[4]);
      FUN_0026197d(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xd0),param_3[4]);
    }
    if (piVar2 != param_3) {
      FUN_0024e0d0(param_3);
    }
  }
  return piVar2;
}


// ===== 0024fb45 FUN_0024fb45 =====

int * FUN_0024fb45(long param_1,long param_2,int *param_3,undefined8 param_4)

{
  int iVar1;
  int *piVar2;
  long local_28;
  
  iVar1 = FUN_0024d4a9(*param_3);
  local_28 = param_2;
  if (iVar1 == 0) {
    if (param_2 == 0) {
      local_28 = *(long *)**(undefined8 **)(param_1 + 0x18);
    }
    piVar2 = (int *)FUN_0024f03c(param_1,local_28,param_3,param_4);
    if ((piVar2 != (int *)0x0) && (*piVar2 == 3)) {
      iVar1 = FUN_0026203b(*(undefined8 *)(piVar2 + 0x2e),piVar2[4]);
      if (iVar1 != 0) {
        FUN_0026197d(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xb8),piVar2[4]);
      }
      FUN_0026197d(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xc0),piVar2[4]);
    }
    if (piVar2 != param_3) {
      FUN_0024e0d0(param_3);
    }
  }
  else if ((param_2 == 0) && (local_28 = FUN_0024f485(param_1,param_3,param_4), local_28 == 0)) {
    FUN_0024e0d0(param_3);
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0024f974(param_1,local_28,param_3,param_4);
  }
  return piVar2;
}


// ===== 0024fc99 FUN_0024fc99 =====

void FUN_0024fc99(long param_1,long param_2,int *param_3)

{
  int iVar1;
  long *local_10;
  
  if (*param_3 == 0x11) {
    for (local_10 = (long *)(param_2 + 0xb0); *local_10 != 0; local_10 = (long *)(*local_10 + 0x58))
    {
    }
  }
  else {
    iVar1 = FUN_0024d4eb(*param_3);
    if (iVar1 == 0) {
      iVar1 = FUN_0024d4a9(*param_3);
      if (iVar1 == 0) {
        for (local_10 = (long *)(param_2 + 0x78); *local_10 != 0;
            local_10 = (long *)(*local_10 + 0x58)) {
        }
        if (*param_3 == 3) {
          iVar1 = FUN_0026203b(*(undefined8 *)(param_3 + 0x2e),param_3[4]);
          if (iVar1 != 0) {
            FUN_0026197d(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xb8),
                         param_3[4]);
          }
          FUN_0026197d(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xc0),param_3[4]
                      );
        }
      }
      else {
        for (local_10 = (long *)(param_2 + 0x90); *local_10 != 0;
            local_10 = (long *)(*local_10 + 0x58)) {
        }
        if (*param_3 == 0xd) {
          iVar1 = FUN_0026203b(*(undefined8 *)(param_3 + 0x32),param_3[4]);
          if (iVar1 != 0) {
            FUN_0026197d(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 200),
                         param_3[4]);
          }
          FUN_0026197d(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xd0),param_3[4]
                      );
        }
      }
    }
    else {
      for (local_10 = (long *)(param_2 + 0xa0); *local_10 != 0;
          local_10 = (long *)(*local_10 + 0x58)) {
      }
    }
  }
  *local_10 = (long)param_3;
  *(long *)(param_3 + 0x12) = param_2;
  param_3[0x16] = 0;
  param_3[0x17] = 0;
  *(undefined4 *)(param_1 + 0xd0) = 1;
  return;
}


// ===== 0024febd FUN_0024febd =====

undefined4 * FUN_0024febd(long param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  undefined4 *__s;
  undefined8 uVar2;
  
  __s = (undefined4 *)FUN_0024d56f(*(undefined8 *)(param_1 + 0x330),0xf8);
  if (__s == (undefined4 *)0x0) {
    __s = (undefined4 *)0x0;
  }
  else {
    memset(__s,0,0xf8);
    *__s = param_2;
    __s[4] = param_3;
    lVar1 = *(long *)(param_1 + 0xe0);
    *(long *)(param_1 + 0xe0) = lVar1 + 1;
    *(long *)(__s + 0x3c) = lVar1;
    uVar2 = FUN_0024d56f(*(undefined8 *)(param_1 + 0x330),0x28);
    *(undefined8 *)(__s + 10) = uVar2;
    if (*(long *)(__s + 10) == 0) {
      if ((*(long *)(param_1 + 0x330) != 0) && (*(int *)(*(long *)(param_1 + 0x330) + 0x10) != 0)) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!topology->tma || !topology->tma->dontfree",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x770,"hwloc_alloc_setup_object");
      }
      free(__s);
      __s = (undefined4 *)0x0;
    }
    else {
      memset(*(void **)(__s + 10),0,0x28);
    }
  }
  return __s;
}


// ===== 0024ffee FUN_0024ffee =====

long FUN_0024ffee(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long local_18;
  long local_10;
  
  local_10 = FUN_0024d2be(param_1);
  iVar1 = FUN_00262158(param_2,*(undefined8 *)(local_10 + 0xc0));
  if (iVar1 != 0) {
    return local_10;
  }
  do {
    for (local_18 = *(long *)(local_10 + 0x78); local_18 != 0; local_18 = *(long *)(local_18 + 0x58)
        ) {
      iVar1 = FUN_00262158(param_2,*(undefined8 *)(local_18 + 0xc0));
      if (iVar1 != 0) {
        return local_18;
      }
      iVar1 = FUN_002620a3(*(undefined8 *)(local_18 + 0xc0));
      if ((iVar1 == 0) &&
         (iVar1 = FUN_002623d5(param_2,*(undefined8 *)(local_18 + 0xc0)), iVar1 != 0)) break;
    }
    if (local_18 == 0) {
      return local_10;
    }
    local_10 = local_18;
  } while( true );
}


// ===== 002500cd FUN_002500cd =====

long FUN_002500cd(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  uVar2 = FUN_00255611(param_1);
  FUN_002626c1(param_2,param_2,uVar2);
  iVar1 = FUN_002620a3(param_2);
  if (iVar1 == 0) {
    lVar3 = FUN_0024ffee(param_1,param_2);
    iVar1 = FUN_00262158(*(undefined8 *)(lVar3 + 0xc0),param_2);
    if (((iVar1 == 0) && (iVar1 = FUN_0024d358(param_1,0xc), iVar1 != 0)) &&
       (lVar4 = FUN_0024febd(param_1,0xc,0xffffffff), lVar4 != 0)) {
      uVar2 = FUN_002611e2(param_2);
      *(undefined8 *)(lVar4 + 0xc0) = uVar2;
      uVar2 = FUN_00255632(param_1);
      FUN_002626c1(param_2,param_2,uVar2);
      uVar2 = FUN_002611e2(param_2);
      *(undefined8 *)(lVar4 + 0xb8) = uVar2;
      *(undefined4 *)(*(long *)(lVar4 + 0x28) + 4) = 1000;
      lVar5 = FUN_0024fb45(param_1,lVar3,lVar4,"topology:io_parent");
      if (lVar5 != 0) {
        if (lVar5 != lVar4) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("parent == group_obj",
                        "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                        ,0x866,"hwloc_find_insert_io_parent_by_complete_cpuset");
        }
        FUN_0025081a(lVar4);
        lVar3 = lVar5;
      }
    }
  }
  else {
    lVar3 = 0;
  }
  return lVar3;
}


// ===== 00250262 FUN_00250262 =====

undefined8 FUN_00250262(ulong *param_1,ulong *param_2)

{
  undefined8 uVar1;
  
  if (*param_2 == 0) {
    uVar1 = 0xffffffff;
  }
  else if (*param_2 == *param_1) {
    uVar1 = 0;
  }
  else if (*param_1 < *param_2) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== 002502cc FUN_002502cc =====

void FUN_002502cc(int *param_1)

{
  int local_14;
  long local_10;
  
  param_1[8] = 0;
  param_1[9] = 0;
  for (local_10 = *(long *)(param_1 + 0x1e); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)) {
    FUN_002502cc(local_10);
    *(long *)(param_1 + 8) = *(long *)(param_1 + 8) + *(long *)(local_10 + 0x20);
  }
  for (local_10 = *(long *)(param_1 + 0x24); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)) {
    FUN_002502cc(local_10);
    *(long *)(param_1 + 8) = *(long *)(param_1 + 8) + *(long *)(local_10 + 0x20);
  }
  if ((*param_1 == 0xd) &&
     (*(long *)(param_1 + 8) = *(long *)(param_1 + 8) + **(long **)(param_1 + 10),
     *(int *)(*(long *)(param_1 + 10) + 8) != 0)) {
    qsort(*(void **)(*(long *)(param_1 + 10) + 0x10),(ulong)*(uint *)(*(long *)(param_1 + 10) + 8),
          0x10,FUN_00250262);
    local_14 = *(int *)(*(long *)(param_1 + 10) + 8);
    while ((local_14 != 0 &&
           (*(long *)(*(long *)(*(long *)(param_1 + 10) + 0x10) + (ulong)(local_14 - 1) * 0x10) == 0
           ))) {
      local_14 = local_14 + -1;
    }
    *(int *)(*(long *)(param_1 + 10) + 8) = local_14;
  }
  return;
}


// ===== 00250431 FUN_00250431 =====

void FUN_00250431(long param_1)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 *local_18;
  
  local_18 = *(undefined4 **)(param_1 + 0x78);
  bVar1 = false;
  while( true ) {
    for (; local_18 != (undefined4 *)0x0; local_18 = *(undefined4 **)(local_18 + 0x16)) {
      FUN_002626c1(*(undefined8 *)(local_18 + 0x2e),*(undefined8 *)(local_18 + 0x2e),
                   *(undefined8 *)(param_1 + 0xb8));
      FUN_002626c1(*(undefined8 *)(local_18 + 0x32),*(undefined8 *)(local_18 + 0x32),
                   *(undefined8 *)(param_1 + 200));
      if (*(long *)(local_18 + 0x30) == 0) {
        uVar3 = FUN_002611e2(*(undefined8 *)(local_18 + 0x2e));
        *(undefined8 *)(local_18 + 0x30) = uVar3;
      }
      else {
        FUN_002626c1(*(undefined8 *)(local_18 + 0x30),*(undefined8 *)(local_18 + 0x30),
                     *(undefined8 *)(param_1 + 0xc0));
      }
      if (*(long *)(local_18 + 0x34) == 0) {
        uVar3 = FUN_002611e2(*(undefined8 *)(local_18 + 0x32));
        *(undefined8 *)(local_18 + 0x34) = uVar3;
      }
      else {
        FUN_002626c1(*(undefined8 *)(local_18 + 0x34),*(undefined8 *)(local_18 + 0x34),
                     *(undefined8 *)(param_1 + 0xd0));
      }
      iVar2 = FUN_002581af(*local_18);
      if (iVar2 != 0) {
        FUN_00261201(*(undefined8 *)(local_18 + 0x2e),*(undefined8 *)(param_1 + 0xb8));
        FUN_00261201(*(undefined8 *)(local_18 + 0x30),*(undefined8 *)(param_1 + 0xc0));
      }
      FUN_00250431(local_18);
    }
    if ((bVar1) || (*(long *)(param_1 + 0x90) == 0)) break;
    local_18 = *(undefined4 **)(param_1 + 0x90);
    bVar1 = true;
  }
  return;
}


// ===== 00250615 FUN_00250615 =====

undefined8 FUN_00250615(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_2 + 0xb8) != 0) {
    if (*(long *)(param_1 + 0xb8) == 0) {
      uVar2 = FUN_00260eab();
      *(undefined8 *)(param_1 + 0xb8) = uVar2;
    }
    if ((*(long *)(param_1 + 0xb8) == 0) ||
       (iVar1 = FUN_00262517(*(undefined8 *)(param_1 + 0xb8),*(undefined8 *)(param_1 + 0xb8),
                             *(undefined8 *)(param_2 + 0xb8)), iVar1 < 0)) {
      return 0xffffffff;
    }
  }
  if (*(long *)(param_2 + 0xc0) != 0) {
    if (*(long *)(param_1 + 0xc0) == 0) {
      uVar2 = FUN_00260eab();
      *(undefined8 *)(param_1 + 0xc0) = uVar2;
    }
    if ((*(long *)(param_1 + 0xc0) == 0) ||
       (iVar1 = FUN_00262517(*(undefined8 *)(param_1 + 0xc0),*(undefined8 *)(param_1 + 0xc0),
                             *(undefined8 *)(param_2 + 0xc0)), iVar1 < 0)) {
      return 0xffffffff;
    }
  }
  if (*(long *)(param_2 + 200) != 0) {
    if (*(long *)(param_1 + 200) == 0) {
      uVar2 = FUN_00260eab();
      *(undefined8 *)(param_1 + 200) = uVar2;
    }
    if ((*(long *)(param_1 + 200) == 0) ||
       (iVar1 = FUN_00262517(*(undefined8 *)(param_1 + 200),*(undefined8 *)(param_1 + 200),
                             *(undefined8 *)(param_2 + 200)), iVar1 < 0)) {
      return 0xffffffff;
    }
  }
  if (*(long *)(param_2 + 0xd0) != 0) {
    if (*(long *)(param_1 + 0xd0) == 0) {
      uVar2 = FUN_00260eab();
      *(undefined8 *)(param_1 + 0xd0) = uVar2;
    }
    if ((*(long *)(param_1 + 0xd0) == 0) ||
       (iVar1 = FUN_00262517(*(undefined8 *)(param_1 + 0xd0),*(undefined8 *)(param_1 + 0xd0),
                             *(undefined8 *)(param_2 + 0xd0)), iVar1 < 0)) {
      return 0xffffffff;
    }
  }
  return 0;
}


// ===== 0025081a FUN_0025081a =====

undefined8 FUN_0025081a(long param_1)

{
  undefined8 local_10;
  
  for (local_10 = *(long *)(param_1 + 0x78); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)) {
    FUN_00250615(param_1,local_10);
  }
  return 0;
}


// ===== 00250861 FUN_00250861 =====

void FUN_00250861(long param_1)

{
  undefined8 uVar1;
  undefined8 local_10;
  
  if (*(long *)(param_1 + 200) == 0) {
    uVar1 = FUN_00260eab();
    *(undefined8 *)(param_1 + 200) = uVar1;
  }
  if (*(long *)(param_1 + 0x48) == 0) {
    FUN_0026180c(*(undefined8 *)(param_1 + 200));
  }
  else {
    FUN_00261201(*(undefined8 *)(param_1 + 200),*(undefined8 *)(*(long *)(param_1 + 0x48) + 200));
  }
  if (*(long *)(param_1 + 0xd0) == 0) {
    uVar1 = FUN_002611e2(*(undefined8 *)(param_1 + 200));
    *(undefined8 *)(param_1 + 0xd0) = uVar1;
  }
  else {
    FUN_00262517(*(undefined8 *)(param_1 + 0xd0),*(undefined8 *)(param_1 + 0xd0),
                 *(undefined8 *)(param_1 + 200));
  }
  for (local_10 = *(long *)(param_1 + 0x90); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)) {
    FUN_00262517(*(undefined8 *)(param_1 + 200),*(undefined8 *)(param_1 + 200),
                 *(undefined8 *)(local_10 + 200));
    FUN_00262517(*(undefined8 *)(param_1 + 0xd0),*(undefined8 *)(param_1 + 0xd0),
                 *(undefined8 *)(local_10 + 0xd0));
  }
  for (local_10 = *(long *)(param_1 + 0x78); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)) {
    FUN_00250861(local_10);
  }
  for (local_10 = *(long *)(param_1 + 0x78); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)) {
    FUN_00262517(*(undefined8 *)(param_1 + 200),*(undefined8 *)(param_1 + 200),
                 *(undefined8 *)(local_10 + 200));
    FUN_00262517(*(undefined8 *)(param_1 + 0xd0),*(undefined8 *)(param_1 + 0xd0),
                 *(undefined8 *)(local_10 + 0xd0));
  }
  return;
}


// ===== 00250a5b FUN_00250a5b =====

void FUN_00250a5b(long param_1,long param_2)

{
  undefined8 local_10;
  
  FUN_002626c1(*(undefined8 *)(param_2 + 0xb8),*(undefined8 *)(param_2 + 0xb8),
               *(undefined8 *)(param_1 + 0x1b8));
  FUN_002626c1(*(undefined8 *)(param_2 + 200),*(undefined8 *)(param_2 + 200),
               *(undefined8 *)(param_1 + 0x1c0));
  for (local_10 = *(long *)(param_2 + 0x78); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)) {
    FUN_00250a5b(param_1,local_10);
  }
  for (local_10 = *(long *)(param_2 + 0x90); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)) {
    FUN_00250a5b(param_1,local_10);
  }
  return;
}


// ===== 00250b31 FUN_00250b31 =====

void FUN_00250b31(long param_1,long param_2,int param_3)

{
  int iVar1;
  uint *local_18;
  uint *local_10;
  
  local_18 = (uint *)(param_2 + 0xa0);
  local_10 = *(uint **)local_18;
  do {
    if (local_10 == (uint *)0x0) {
      return;
    }
    iVar1 = *(int *)(param_1 + 8 + ((ulong)*local_10 + 0x1c) * 4);
    FUN_00250b31(param_1,local_10,param_3 + 1);
    *(int *)(*(long *)(local_10 + 10) + 0x24) = param_3;
    if ((iVar1 == 3) && (*(long *)(local_10 + 0x28) == 0)) {
      if (*local_10 != 0xe) {
        if ((*local_10 != 0xf) || (*(ushort *)(*(long *)(local_10 + 10) + 6) >> 8 != 6))
        goto LAB_00250c24;
        if (*(long *)(local_10 + 2) != 0) {
          iVar1 = strcmp(*(char **)(local_10 + 2),"NVSwitch");
          if (iVar1 == 0) goto LAB_00250c24;
        }
      }
      FUN_0024e578(local_18);
      *(undefined4 *)(param_1 + 0xd0) = 1;
    }
LAB_00250c24:
    if (local_10 == *(uint **)local_18) {
      local_18 = local_10 + 0x16;
    }
    local_10 = *(uint **)local_18;
  } while( true );
}


// ===== 00250c56 FUN_00250c56 =====

void FUN_00250c56(undefined8 param_1,long param_2)

{
  undefined8 local_10;
  
  for (local_10 = *(long *)(param_2 + 0x78); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)) {
    FUN_00250c56(param_1,local_10);
  }
  FUN_00250b31(param_1,param_2,0);
  return;
}


// ===== 00250cb5 FUN_00250cb5 =====

void FUN_00250cb5(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 local_18;
  undefined8 local_10;
  
  local_18 = *(long *)(param_1 + 0x78);
  *(undefined8 *)(param_1 + 0x78) = 0;
  do {
    if (local_18 == 0) {
      return;
    }
    lVar1 = *(long *)(local_18 + 0x58);
    for (local_10 = (long *)(param_1 + 0x78); *local_10 != 0; local_10 = (long *)(*local_10 + 0x58))
    {
      iVar2 = FUN_0024ebf0(local_18,*local_10);
      if (iVar2 < 1) break;
    }
    *(long *)(local_18 + 0x58) = *local_10;
    *local_10 = local_18;
    local_18 = lVar1;
  } while( true );
}


// ===== 00250d56 FUN_00250d56 =====

void FUN_00250d56(long param_1,undefined8 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  long *local_18;
  long local_10;
  
  puVar1 = (undefined4 *)*param_2;
  local_18 = (long *)(puVar1 + 0x1e);
  local_10 = *local_18;
  while (local_10 != 0) {
    FUN_00250d56(param_1,local_18);
    if (local_10 == *local_18) {
      local_18 = (long *)(local_10 + 0x58);
    }
    local_10 = *local_18;
  }
  local_18 = (long *)(puVar1 + 0x24);
  local_10 = *local_18;
  while (local_10 != 0) {
    FUN_00250d56(param_1,local_18);
    if (local_10 == *local_18) {
      local_18 = (long *)(local_10 + 0x58);
    }
    local_10 = *local_18;
  }
  if (((*(long *)(puVar1 + 0x1e) == 0) && (*(long *)(puVar1 + 0x24) == 0)) &&
     (*(long *)(puVar1 + 0x28) == 0)) {
    iVar2 = FUN_0024d488(*puVar1);
    if (iVar2 == 0) {
      iVar2 = FUN_0024d4a9(*puVar1);
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("hwloc__obj_type_is_memory(obj->type)",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x99a,"remove_empty");
      }
      iVar2 = FUN_002620a3(*(undefined8 *)(puVar1 + 0x32));
    }
    else {
      iVar2 = FUN_002620a3(*(undefined8 *)(puVar1 + 0x2e));
    }
    if (iVar2 != 0) {
      FUN_0024d5f6(&DAT_002e95c6,"\nRemoving empty object ");
      FUN_0024e578(param_2);
      *(undefined4 *)(param_1 + 0xd0) = 1;
    }
  }
  return;
}


// ===== 00250f05 FUN_00250f05 =====

void FUN_00250f05(long param_1)

{
  undefined4 local_c;
  
  for (local_c = 0; local_c < 0xd; local_c = local_c + 1) {
    *(undefined4 *)(param_1 + 8 + ((ulong)local_c + 8) * 4) = 0xffffffff;
  }
  *(undefined4 *)(param_1 + 0x74) = 0xffffffff;
  return;
}


// ===== 00250f41 FUN_00250f41 =====

undefined8 FUN_00250f41(long param_1,uint param_2)

{
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (*(uint *)(*(long *)(param_1 + 0x10) + (ulong)param_2 * 4) <= local_c) {
      return 0;
    }
    if (*(char *)(*(long *)(*(long *)(*(long *)(*(long *)(param_1 + 0x18) + (ulong)param_2 * 8) +
                                     (ulong)local_c * 8) + 0x28) + 0xc) != '\0') break;
    local_c = local_c + 1;
  }
  return 1;
}


// ===== 00250fae FUN_00250fae =====

undefined8 FUN_00250fae(long param_1,uint param_2)

{
  undefined8 uVar1;
  uint local_c;
  
  if (*(int *)(*(long *)(param_1 + 0x10) + (ulong)(param_2 - 1) * 4) ==
      *(int *)(*(long *)(param_1 + 0x10) + (ulong)param_2 * 4)) {
    for (local_c = 0; local_c < *(uint *)(*(long *)(param_1 + 0x10) + (ulong)param_2 * 4);
        local_c = local_c + 1) {
      if (*(long *)(*(long *)(*(long *)(param_1 + 0x18) + (ulong)(param_2 - 1) * 8) +
                   (ulong)local_c * 8) !=
          *(long *)(*(long *)(*(long *)(*(long *)(param_1 + 0x18) + (ulong)param_2 * 8) +
                             (ulong)local_c * 8) + 0x48)) {
        return 0xffffffff;
      }
      if (*(int *)(*(long *)(*(long *)(*(long *)(param_1 + 0x18) + (ulong)(param_2 - 1) * 8) +
                            (ulong)local_c * 8) + 0x68) != 1) {
        return 0xffffffff;
      }
      if ((*(int *)**(undefined8 **)(*(long *)(param_1 + 0x18) + (ulong)param_2 * 8) == 3) &&
         (*(int *)(*(long *)(*(long *)(*(long *)(param_1 + 0x18) + (ulong)(param_2 - 1) * 8) +
                            (ulong)local_c * 8) + 0x8c) != 0)) {
        return 0xffffffff;
      }
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ===== 0025111e FUN_0025111e =====

undefined8 FUN_0025111e(long param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  uint local_30;
  int local_24;
  uint local_20;
  uint local_1c;
  
  local_24 = 0;
  if (*(int *)(param_1 + 0xd0) != 0) {
    FUN_00251e0d(*(undefined8 *)**(undefined8 **)(param_1 + 0x18));
    iVar9 = FUN_0025270e(param_1);
    if (iVar9 < 0) {
      return 0xffffffff;
    }
  }
  local_1c = *(uint *)(param_1 + 4);
  while (uVar4 = local_1c, local_1c = uVar4 - 1, local_1c != 0) {
    bVar7 = false;
    bVar8 = false;
    uVar1 = *(uint *)**(undefined8 **)(*(long *)(param_1 + 0x18) + (ulong)(uVar4 - 2) * 8);
    uVar2 = *(uint *)**(undefined8 **)(*(long *)(param_1 + 0x18) + (ulong)local_1c * 8);
    if (((*(int *)(param_1 + 8 + ((ulong)uVar1 + 0x1c) * 4) == 2) && (bVar8 = true, uVar1 == 0xc))
       && (iVar9 = FUN_00250f41(param_1,uVar4 - 2), iVar9 != 0)) {
      bVar8 = false;
    }
    if (((*(int *)(param_1 + 8 + ((ulong)uVar2 + 0x1c) * 4) == 2) && (bVar7 = true, uVar1 == 0xc))
       && (iVar9 = FUN_00250f41(param_1,local_1c), iVar9 != 0)) {
      bVar7 = false;
    }
    if ((bVar7) || (bVar8)) {
      if ((bVar8) && (bVar7)) {
        if (*(int *)(&DAT_002eb500 + (ulong)uVar1 * 4) < *(int *)(&DAT_002eb500 + (ulong)uVar2 * 4))
        {
          bVar7 = false;
        }
        else {
          bVar8 = false;
        }
      }
      iVar9 = FUN_00250fae(param_1,local_1c);
      if (-1 < iVar9) {
        uVar10 = FUN_002582d8(uVar2);
        uVar11 = FUN_002582d8(uVar1);
        FUN_0024d5f6("may merge levels #%u=%s and #%u=%s\n",uVar4 - 2,uVar11,local_1c,uVar10);
        for (local_20 = 0; local_20 < *(uint *)(*(long *)(param_1 + 0x10) + (ulong)local_1c * 4);
            local_20 = local_20 + 1) {
          lVar6 = *(long *)(*(long *)(*(long *)(param_1 + 0x18) + (ulong)(uVar4 - 2) * 8) +
                           (ulong)local_20 * 8);
          lVar5 = *(long *)(*(long *)(*(long *)(param_1 + 0x18) + (ulong)local_1c * 8) +
                           (ulong)local_20 * 8);
          if (bVar7) {
            *(undefined8 *)(lVar6 + 0x78) = *(undefined8 *)(lVar5 + 0x78);
            *(undefined8 *)(lVar6 + 0x80) = *(undefined8 *)(lVar5 + 0x80);
            *(undefined4 *)(lVar6 + 0x68) = *(undefined4 *)(lVar5 + 0x68);
            free(*(void **)(lVar6 + 0x70));
            *(undefined8 *)(lVar6 + 0x70) = *(undefined8 *)(lVar5 + 0x70);
            *(undefined8 *)(lVar5 + 0x70) = 0;
            for (local_30 = 0; local_30 < *(uint *)(lVar6 + 0x68); local_30 = local_30 + 1) {
              *(long *)(*(long *)(*(long *)(lVar6 + 0x70) + (ulong)local_30 * 8) + 0x48) = lVar6;
            }
            if (*(long *)(lVar5 + 0x90) != 0) {
              FUN_0024e4c8(lVar6 + 0x90,*(undefined8 *)(lVar5 + 0x90),lVar6);
              *(int *)(lVar6 + 0x8c) = *(int *)(lVar6 + 0x8c) + *(int *)(lVar5 + 0x8c);
            }
            if (*(long *)(lVar5 + 0xa0) != 0) {
              FUN_0024e4c8(lVar6 + 0xa0,*(undefined8 *)(lVar5 + 0xa0),lVar6);
              *(int *)(lVar6 + 0x98) = *(int *)(lVar6 + 0x98) + *(int *)(lVar5 + 0x98);
            }
            if (*(long *)(lVar5 + 0xb0) != 0) {
              FUN_0024e4c8(lVar6 + 0xb0,*(undefined8 *)(lVar5 + 0xb0),lVar6);
              *(int *)(lVar6 + 0xa8) = *(int *)(lVar6 + 0xa8) + *(int *)(lVar5 + 0xa8);
            }
            FUN_0024e0d0(lVar5);
          }
          else {
            if (*(long *)(lVar6 + 0x48) == 0) {
              *(long *)**(undefined8 **)(param_1 + 0x18) = lVar5;
              *(undefined8 *)(lVar5 + 0x48) = 0;
            }
            else {
              *(long *)(*(long *)(*(long *)(lVar6 + 0x48) + 0x70) +
                       (ulong)*(uint *)(lVar6 + 0x50) * 8) = lVar5;
              *(undefined4 *)(lVar5 + 0x50) = *(undefined4 *)(lVar6 + 0x50);
              if (*(int *)(lVar6 + 0x50) == 0) {
                *(long *)(*(long *)(lVar6 + 0x48) + 0x78) = lVar5;
              }
              else {
                *(undefined8 *)(lVar5 + 0x60) =
                     *(undefined8 *)
                      ((ulong)(*(int *)(lVar6 + 0x50) - 1) * 8 +
                      *(long *)(*(long *)(lVar6 + 0x48) + 0x70));
                *(long *)(*(long *)(lVar5 + 0x60) + 0x58) = lVar5;
              }
              if (*(int *)(lVar6 + 0x50) == *(int *)(*(long *)(lVar6 + 0x48) + 0x68) + -1) {
                *(long *)(*(long *)(lVar6 + 0x48) + 0x80) = lVar5;
              }
              else {
                *(undefined8 *)(lVar5 + 0x58) =
                     *(undefined8 *)
                      ((ulong)(*(int *)(lVar6 + 0x50) + 1) * 8 +
                      *(long *)(*(long *)(lVar6 + 0x48) + 0x70));
                *(long *)(*(long *)(lVar5 + 0x58) + 0x60) = lVar5;
              }
              *(undefined8 *)(lVar5 + 0x48) = *(undefined8 *)(lVar6 + 0x48);
            }
            if (*(long *)(lVar6 + 0x90) != 0) {
              FUN_0024e3fc(lVar5 + 0x90,*(undefined8 *)(lVar6 + 0x90),lVar5);
              *(int *)(lVar5 + 0x8c) = *(int *)(lVar5 + 0x8c) + *(int *)(lVar6 + 0x8c);
            }
            if (*(long *)(lVar6 + 0xa0) != 0) {
              FUN_0024e3fc(lVar5 + 0xa0,*(undefined8 *)(lVar6 + 0xa0),lVar5);
              *(int *)(lVar5 + 0x98) = *(int *)(lVar5 + 0x98) + *(int *)(lVar6 + 0x98);
            }
            if (*(long *)(lVar6 + 0xb0) != 0) {
              FUN_0024e3fc(lVar5 + 0xb0,*(undefined8 *)(lVar6 + 0xb0),lVar5);
              *(int *)(lVar5 + 0xa8) = *(int *)(lVar5 + 0xa8) + *(int *)(lVar6 + 0xa8);
            }
            FUN_0024e0d0(lVar6);
          }
        }
        if ((bVar8) && (1 < local_1c)) {
          for (local_20 = 0; local_20 < *(uint *)(*(long *)(param_1 + 0x10) + (ulong)local_1c * 4);
              local_20 = local_20 + 1) {
            lVar6 = *(long *)(*(long *)(*(long *)(param_1 + 0x18) + (ulong)local_1c * 8) +
                             (ulong)local_20 * 8);
            uVar3 = *(uint *)(lVar6 + 0x50);
            if (uVar3 == 0) {
              uVar10 = 0;
            }
            else {
              uVar10 = *(undefined8 *)
                        (*(long *)(*(long *)(lVar6 + 0x48) + 0x70) + (ulong)(uVar3 - 1) * 8);
            }
            *(undefined8 *)(lVar6 + 0x60) = uVar10;
            if (uVar3 < *(int *)(*(long *)(lVar6 + 0x48) + 0x68) - 1U) {
              uVar10 = *(undefined8 *)
                        (*(long *)(*(long *)(lVar6 + 0x48) + 0x70) + (ulong)(uVar3 + 1) * 8);
            }
            else {
              uVar10 = 0;
            }
            *(undefined8 *)(lVar6 + 0x58) = uVar10;
          }
        }
        if (bVar8) {
          free(*(void **)(*(long *)(param_1 + 0x18) + (ulong)(uVar4 - 2) * 8));
          memmove((void *)(*(long *)(param_1 + 0x18) + (ulong)(uVar4 - 2) * 8),
                  (void *)((ulong)local_1c * 8 + *(long *)(param_1 + 0x18)),
                  (ulong)(*(int *)(param_1 + 4) - local_1c) * 8);
          memmove((void *)(*(long *)(param_1 + 0x10) + (ulong)(uVar4 - 2) * 4),
                  (void *)((ulong)local_1c * 4 + *(long *)(param_1 + 0x10)),
                  (ulong)(*(int *)(param_1 + 4) - local_1c) * 4);
          uVar10 = FUN_002582d8(uVar1);
          FUN_0024d5f6("removed parent level %s at depth %u\n",uVar10,uVar4 - 2);
        }
        else {
          free(*(void **)(*(long *)(param_1 + 0x18) + (ulong)local_1c * 8));
          memmove((void *)(*(long *)(param_1 + 0x18) + (ulong)local_1c * 8),
                  (void *)((ulong)uVar4 * 8 + *(long *)(param_1 + 0x18)),
                  (ulong)((*(int *)(param_1 + 4) - local_1c) - 1) * 8);
          memmove((void *)(*(long *)(param_1 + 0x10) + (ulong)local_1c * 4),
                  (void *)((ulong)uVar4 * 4 + *(long *)(param_1 + 0x10)),
                  (ulong)((*(int *)(param_1 + 4) - local_1c) - 1) * 4);
          uVar10 = FUN_002582d8(uVar2);
          FUN_0024d5f6("removed child level %s at depth %u\n",uVar10,local_1c);
        }
        *(undefined4 *)((ulong)(*(int *)(param_1 + 4) - 1) * 4 + *(long *)(param_1 + 0x10)) = 0;
        *(undefined8 *)((ulong)(*(int *)(param_1 + 4) - 1) * 8 + *(long *)(param_1 + 0x18)) = 0;
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
        local_24 = local_24 + 1;
      }
    }
  }
  if (0 < local_24) {
    FUN_00250f05(param_1);
    for (local_1c = 0; local_1c < *(uint *)(param_1 + 4); local_1c = local_1c + 1) {
      uVar4 = *(uint *)**(undefined8 **)(*(long *)(param_1 + 0x18) + (ulong)local_1c * 8);
      for (local_20 = 0; local_20 < *(uint *)(*(long *)(param_1 + 0x10) + (ulong)local_1c * 4);
          local_20 = local_20 + 1) {
        *(uint *)(*(long *)(*(long *)(*(long *)(param_1 + 0x18) + (ulong)local_1c * 8) +
                           (ulong)local_20 * 8) + 0x30) = local_1c;
      }
      if (*(int *)(param_1 + 8 + ((ulong)uVar4 + 8) * 4) == -1) {
        *(uint *)(param_1 + 8 + ((ulong)uVar4 + 8) * 4) = local_1c;
      }
      else {
        *(undefined4 *)(param_1 + 8 + ((ulong)uVar4 + 8) * 4) = 0xfffffffe;
      }
    }
  }
  if ((0 < local_24) || (*(int *)(param_1 + 0xd0) != 0)) {
    iVar9 = FUN_00252651(param_1);
    if (iVar9 < 0) {
      return 0xffffffff;
    }
    *(undefined4 *)(param_1 + 0xd0) = 0;
  }
  return 0;
}


// ===== 00251ba3 FUN_00251ba3 =====

void FUN_00251ba3(undefined8 param_1,long param_2)

{
  uint uVar1;
  bool bVar2;
  long *__dest;
  uint local_18;
  long local_10;
  
  uVar1 = *(uint *)(param_2 + 0x68);
  *(undefined4 *)(param_2 + 0x88) = 0;
  if (uVar1 != 0) {
    bVar2 = true;
    for (local_10 = *(long *)(param_2 + 0x78); local_10 != 0; local_10 = *(long *)(local_10 + 0x58))
    {
      FUN_00251ba3(param_1,local_10);
      if (*(int *)(local_10 + 0x88) == 0) {
        bVar2 = false;
      }
    }
    if (!bVar2) {
      return;
    }
    if (uVar1 != 1) {
      __dest = malloc((ulong)uVar1 << 3);
      if (__dest == (long *)0x0) {
        return;
      }
      memcpy(__dest,*(void **)(param_2 + 0x70),(ulong)uVar1 * 8);
      while( true ) {
        for (local_18 = 1; local_18 < uVar1; local_18 = local_18 + 1) {
          if ((*(int *)(__dest[local_18] + 0x30) != *(int *)(*__dest + 0x30)) ||
             (*(int *)(__dest[local_18] + 0x68) != *(int *)(*__dest + 0x68))) {
            free(__dest);
            return;
          }
        }
        if (*(int *)(*__dest + 0x68) == 0) break;
        for (local_18 = 0; local_18 < uVar1; local_18 = local_18 + 1) {
          __dest[local_18] = *(long *)(__dest[local_18] + 0x78);
        }
      }
      free(__dest);
    }
  }
  *(undefined4 *)(param_2 + 0x88) = 1;
  return;
}


// ===== 00251d6a FUN_00251d6a =====

void FUN_00251d6a(long param_1)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  for (local_10 = 0; local_10 < *(uint *)(param_1 + 4); local_10 = local_10 + 1) {
    if (*(int *)**(undefined8 **)(*(long *)(param_1 + 0x18) + (ulong)local_10 * 8) == 0xc) {
      for (local_14 = 0; local_14 < *(uint *)(*(long *)(param_1 + 0x10) + (ulong)local_10 * 4);
          local_14 = local_14 + 1) {
        **(int **)(*(long *)(*(long *)(*(long *)(param_1 + 0x18) + (ulong)local_10 * 8) +
                            (ulong)local_14 * 8) + 0x28) = local_c;
      }
      local_c = local_c + 1;
    }
  }
  return;
}


// ===== 00251e0d FUN_00251e0d =====

void FUN_00251e0d(long param_1)

{
  uint uVar1;
  bool bVar2;
  void *pvVar3;
  undefined8 local_20;
  undefined8 local_18;
  undefined4 local_c;
  
  uVar1 = *(uint *)(param_1 + 0x68);
  bVar2 = true;
  local_20 = 0;
  local_c = 0;
  for (local_18 = *(long *)(param_1 + 0x78); local_18 != 0; local_18 = *(long *)(local_18 + 0x58)) {
    *(uint *)(local_18 + 0x50) = local_c;
    *(long *)(local_18 + 0x60) = local_20;
    if ((uVar1 <= local_c) ||
       (local_18 != *(long *)(*(long *)(param_1 + 0x70) + (ulong)local_c * 8))) {
      bVar2 = false;
    }
    FUN_00251e0d(local_18);
    local_c = local_c + 1;
    local_20 = local_18;
  }
  *(long *)(param_1 + 0x80) = local_20;
  *(uint *)(param_1 + 0x68) = local_c;
  if (local_c == 0) {
    free(*(void **)(param_1 + 0x70));
    *(undefined8 *)(param_1 + 0x70) = 0;
  }
  else if (!bVar2) {
    if (uVar1 < local_c) {
      free(*(void **)(param_1 + 0x70));
      pvVar3 = malloc((ulong)local_c << 3);
      *(void **)(param_1 + 0x70) = pvVar3;
    }
    local_c = 0;
    for (local_18 = *(long *)(param_1 + 0x78); local_18 != 0; local_18 = *(long *)(local_18 + 0x58))
    {
      *(long *)((ulong)local_c * 8 + *(long *)(param_1 + 0x70)) = local_18;
      local_c = local_c + 1;
    }
  }
  local_20 = 0;
  local_c = 0;
  for (local_18 = *(long *)(param_1 + 0x90); local_18 != 0; local_18 = *(long *)(local_18 + 0x58)) {
    *(long *)(local_18 + 0x48) = param_1;
    *(uint *)(local_18 + 0x50) = local_c;
    *(long *)(local_18 + 0x60) = local_20;
    FUN_00251e0d(local_18);
    local_c = local_c + 1;
    local_20 = local_18;
  }
  *(uint *)(param_1 + 0x8c) = local_c;
  local_20 = 0;
  local_c = 0;
  for (local_18 = *(long *)(param_1 + 0xa0); local_18 != 0; local_18 = *(long *)(local_18 + 0x58)) {
    *(long *)(local_18 + 0x48) = param_1;
    *(uint *)(local_18 + 0x50) = local_c;
    *(long *)(local_18 + 0x60) = local_20;
    FUN_00251e0d(local_18);
    local_c = local_c + 1;
    local_20 = local_18;
  }
  *(uint *)(param_1 + 0x98) = local_c;
  local_20 = 0;
  local_c = 0;
  for (local_18 = *(long *)(param_1 + 0xb0); local_18 != 0; local_18 = *(long *)(local_18 + 0x58)) {
    *(long *)(local_18 + 0x48) = param_1;
    *(uint *)(local_18 + 0x50) = local_c;
    *(long *)(local_18 + 0x60) = local_20;
    FUN_00251e0d(local_18);
    local_c = local_c + 1;
    local_20 = local_18;
  }
  *(uint *)(param_1 + 0xa8) = local_c;
  return;
}


// ===== 002520e3 FUN_002520e3 =====

undefined8 FUN_002520e3(long param_1,undefined8 param_2)

{
  int iVar1;
  long local_10;
  
  local_10 = *(long *)(param_1 + 0x78);
  while( true ) {
    if (local_10 == 0) {
      return 0;
    }
    iVar1 = FUN_0024ea2d(local_10,param_2);
    if (iVar1 == 0) break;
    iVar1 = FUN_002520e3(local_10,param_2);
    if (iVar1 != 0) {
      return 1;
    }
    local_10 = *(long *)(local_10 + 0x58);
  }
  return 1;
}


// ===== 00252157 FUN_00252157 =====

undefined8 FUN_00252157(uint *param_1)

{
  uint uVar1;
  void *pvVar2;
  long local_18;
  uint local_c;
  
  local_18 = *(long *)(param_1 + 4);
  local_c = 0;
  for (; uVar1 = local_c, local_18 != 0; local_18 = *(long *)(local_18 + 0x38)) {
    local_c = local_c + 1;
  }
  if (local_c != 0) {
    pvVar2 = malloc((ulong)local_c << 3);
    *(void **)(param_1 + 2) = pvVar2;
    if (*(long *)(param_1 + 2) == 0) {
      return 0xffffffff;
    }
    local_18 = *(long *)(param_1 + 4);
    local_c = 0;
    for (; local_18 != 0; local_18 = *(long *)(local_18 + 0x38)) {
      *(uint *)(local_18 + 0x34) = local_c;
      *(long *)((ulong)local_c * 8 + *(long *)(param_1 + 2)) = local_18;
      local_c = local_c + 1;
    }
  }
  *param_1 = uVar1;
  return 0;
}


// ===== 00252228 FUN_00252228 =====

void FUN_00252228(long param_1,long param_2)

{
  if (*(long *)(param_1 + 0x10) == 0) {
    *(undefined8 *)(param_2 + 0x40) = 0;
    *(long *)(param_1 + 0x18) = param_2;
    *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(param_1 + 0x18);
  }
  else {
    *(undefined8 *)(param_2 + 0x40) = *(undefined8 *)(param_1 + 0x18);
    *(long *)(*(long *)(param_2 + 0x40) + 0x38) = param_2;
    *(long *)(param_1 + 0x18) = param_2;
  }
  return;
}


// ===== 0025229a FUN_0025229a =====

void FUN_0025229a(long param_1,int *param_2)

{
  int iVar1;
  long local_10;
  
  if (*param_2 == 0xd) {
    param_2[0xe] = 0;
    param_2[0xf] = 0;
    param_2[0xc] = -3;
    FUN_00252228(param_1 + 0xf8,param_2);
    for (local_10 = *(long *)(param_2 + 0x2c); local_10 != 0; local_10 = *(long *)(local_10 + 0x58))
    {
      FUN_0025229a(param_1,local_10);
    }
  }
  else if (*param_2 == 0x12) {
    param_2[0xe] = 0;
    param_2[0xf] = 0;
    param_2[0xc] = -8;
    FUN_00252228(param_1 + 0x198,param_2);
    for (local_10 = *(long *)(param_2 + 0x24); local_10 != 0; local_10 = *(long *)(local_10 + 0x58))
    {
      FUN_0025229a(param_1,local_10);
    }
    for (local_10 = *(long *)(param_2 + 0x2c); local_10 != 0; local_10 = *(long *)(local_10 + 0x58))
    {
      FUN_0025229a(param_1,local_10);
    }
  }
  else if (*param_2 == 0x11) {
    param_2[0xe] = 0;
    param_2[0xf] = 0;
    param_2[0xc] = -7;
    FUN_00252228(param_1 + 0x178,param_2);
    for (local_10 = *(long *)(param_2 + 0x2c); local_10 != 0; local_10 = *(long *)(local_10 + 0x58))
    {
      FUN_0025229a(param_1,local_10);
    }
  }
  else {
    iVar1 = FUN_0024d4eb(*param_2);
    if (iVar1 == 0) {
      for (local_10 = *(long *)(param_2 + 0x1e); local_10 != 0;
          local_10 = *(long *)(local_10 + 0x58)) {
        FUN_0025229a(param_1,local_10);
      }
      for (local_10 = *(long *)(param_2 + 0x24); local_10 != 0;
          local_10 = *(long *)(local_10 + 0x58)) {
        FUN_0025229a(param_1,local_10);
      }
      for (local_10 = *(long *)(param_2 + 0x28); local_10 != 0;
          local_10 = *(long *)(local_10 + 0x58)) {
        FUN_0025229a(param_1,local_10);
      }
      for (local_10 = *(long *)(param_2 + 0x2c); local_10 != 0;
          local_10 = *(long *)(local_10 + 0x58)) {
        FUN_0025229a(param_1,local_10);
      }
    }
    else {
      param_2[0xe] = 0;
      param_2[0xf] = 0;
      if (*param_2 == 0xe) {
        param_2[0xc] = -4;
        FUN_00252228(param_1 + 0x118,param_2);
      }
      else if (*param_2 == 0xf) {
        param_2[0xc] = -5;
        FUN_00252228(param_1 + 0x138,param_2);
      }
      else if (*param_2 == 0x10) {
        param_2[0xc] = -6;
        FUN_00252228(param_1 + 0x158,param_2);
      }
      for (local_10 = *(long *)(param_2 + 0x28); local_10 != 0;
          local_10 = *(long *)(local_10 + 0x58)) {
        FUN_0025229a(param_1,local_10);
      }
      for (local_10 = *(long *)(param_2 + 0x2c); local_10 != 0;
          local_10 = *(long *)(local_10 + 0x58)) {
        FUN_0025229a(param_1,local_10);
      }
    }
  }
  return;
}


// ===== 00252651 FUN_00252651 =====

undefined8 FUN_00252651(long param_1)

{
  int iVar1;
  uint local_c;
  
  for (local_c = 0; local_c < 6; local_c = local_c + 1) {
    free(*(void **)(param_1 + (ulong)local_c * 0x20 + 0x100));
  }
  memset((void *)(param_1 + 0xf8),0,0xc0);
  FUN_0025229a(param_1,*(undefined8 *)**(undefined8 **)(param_1 + 0x18));
  local_c = 0;
  while( true ) {
    if (5 < local_c) {
      return 0;
    }
    iVar1 = FUN_00252157(param_1 + (ulong)local_c * 0x20 + 0xf8);
    if (iVar1 < 0) break;
    local_c = local_c + 1;
  }
  return 0xffffffff;
}


// ===== 0025270e FUN_0025270e =====

undefined8 FUN_0025270e(long param_1)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  undefined8 uVar4;
  long *__ptr;
  void *pvVar5;
  void *pvVar6;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint *local_28;
  undefined8 *local_20;
  undefined8 *local_18;
  uint local_10;
  uint local_c;
  
  for (local_c = 1; local_c < *(uint *)(param_1 + 4); local_c = local_c + 1) {
    free(*(void **)(*(long *)(param_1 + 0x18) + (ulong)local_c * 8));
  }
  memset((void *)(*(long *)(param_1 + 0x18) + 8),0,(ulong)(*(int *)(param_1 + 4) - 1) * 8);
  memset((void *)(*(long *)(param_1 + 0x10) + 4),0,(ulong)(*(int *)(param_1 + 4) - 1) * 4);
  *(undefined4 *)(param_1 + 4) = 1;
  FUN_00250f05(param_1);
  puVar1 = *(uint **)**(undefined8 **)(param_1 + 0x18);
  puVar1[0xc] = 0;
  *(undefined4 *)(param_1 + 8 + ((ulong)*puVar1 + 8) * 4) = 0;
  puVar1[0xd] = 0;
  puVar1[0x10] = 0;
  puVar1[0x11] = 0;
  puVar1[0xe] = 0;
  puVar1[0xf] = 0;
  puVar1[0x12] = 0;
  puVar1[0x13] = 0;
  puVar1[0x14] = 0;
  puVar1[0x18] = 0;
  puVar1[0x19] = 0;
  puVar1[0x16] = 0;
  puVar1[0x17] = 0;
  local_2c = *(uint *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0x68);
  local_18 = malloc((ulong)local_2c << 3);
  if (local_18 == (undefined8 *)0x0) {
    piVar3 = __errno_location();
    *piVar3 = 0xc;
    uVar4 = 0xffffffff;
  }
  else {
    memcpy(local_18,*(void **)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0x70),
           (ulong)local_2c * 8);
    while (local_2c != 0) {
      local_10 = 0;
      while ((local_10 < local_2c && (*(int *)local_18[local_10] == 3))) {
        local_10 = local_10 + 1;
      }
      if (local_10 == local_2c) {
        local_28 = (uint *)*local_18;
      }
      else {
        local_28 = (uint *)local_18[local_10];
      }
      for (local_10 = 0; local_10 < local_2c; local_10 = local_10 + 1) {
        iVar2 = FUN_0024ea2d(local_28,local_18[local_10]);
        if ((iVar2 != 0) && (iVar2 = FUN_002520e3(local_18[local_10],local_28), iVar2 != 0)) {
          local_28 = (uint *)local_18[local_10];
        }
      }
      __ptr = malloc((ulong)(local_2c + 1) << 3);
      if (__ptr == (long *)0x0) {
        free(local_18);
        piVar3 = __errno_location();
        *piVar3 = 0xc;
        return 0xffffffff;
      }
      local_34 = 0;
      for (local_10 = 0; local_10 < local_2c; local_10 = local_10 + 1) {
        if (*(int *)(local_18[local_10] + 0x68) == 0) {
          local_34 = local_34 + 1;
        }
        else {
          local_34 = local_34 + *(int *)(local_18[local_10] + 0x68);
        }
      }
      local_20 = malloc((ulong)local_34 << 3);
      if (local_20 == (undefined8 *)0x0) {
        free(local_18);
        free(__ptr);
        piVar3 = __errno_location();
        *piVar3 = 0xc;
        return 0xffffffff;
      }
      local_34 = 0;
      local_30 = 0;
      for (local_10 = 0; local_10 < local_2c; local_10 = local_10 + 1) {
        iVar2 = FUN_0024ea2d(local_28,local_18[local_10]);
        if (iVar2 == 0) {
          __ptr[local_30] = local_18[local_10];
          if (*(int *)(local_18[local_10] + 0x68) != 0) {
            memcpy(local_20 + local_34,*(void **)(local_18[local_10] + 0x70),
                   (ulong)*(uint *)(local_18[local_10] + 0x68) * 8);
          }
          local_34 = local_34 + *(int *)(local_18[local_10] + 0x68);
          local_30 = local_30 + 1;
        }
        else {
          local_20[local_34] = local_18[local_10];
          local_34 = local_34 + 1;
        }
      }
      if (local_34 == 0) {
        free(local_20);
        local_20 = (undefined8 *)0x0;
      }
      for (local_10 = 0; local_10 < local_30; local_10 = local_10 + 1) {
        *(undefined4 *)(__ptr[local_10] + 0x30) = *(undefined4 *)(param_1 + 4);
        *(uint *)(__ptr[local_10] + 0x34) = local_10;
        if (local_10 != 0) {
          *(long *)(__ptr[local_10] + 0x40) = __ptr[local_10 - 1];
          *(long *)(__ptr[local_10 - 1] + 0x38) = __ptr[local_10];
        }
      }
      *(undefined8 *)(*__ptr + 0x40) = 0;
      *(undefined8 *)(__ptr[local_30 - 1] + 0x38) = 0;
      uVar4 = FUN_002582d8(*local_28);
      FUN_0024d5f6("--- %s level",uVar4);
      FUN_0024d5f6(" has number %u\n\n",*(undefined4 *)(param_1 + 4));
      if (*(int *)(param_1 + 8 + ((ulong)*local_28 + 8) * 4) == -1) {
        *(undefined4 *)(param_1 + 8 + ((ulong)*local_28 + 8) * 4) = *(undefined4 *)(param_1 + 4);
      }
      else {
        *(undefined4 *)(param_1 + 8 + ((ulong)*local_28 + 8) * 4) = 0xfffffffe;
      }
      __ptr[local_30] = 0;
      if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
        pvVar5 = realloc(*(void **)(param_1 + 0x18),(ulong)(uint)(*(int *)(param_1 + 8) * 2) * 8);
        pvVar6 = realloc(*(void **)(param_1 + 0x10),(ulong)(uint)(*(int *)(param_1 + 8) * 2) * 4);
        if ((pvVar5 == (void *)0x0) || (pvVar6 == (void *)0x0)) {
          iVar2 = FUN_0024d64f();
          if (iVar2 < 2) {
            fprintf(*(FILE **)PTR_stderr_0032efe0,"hwloc: failed to realloc level arrays to %u\n",
                    (ulong)(uint)(*(int *)(param_1 + 8) * 2));
          }
          if (pvVar5 != (void *)0x0) {
            *(void **)(param_1 + 0x18) = pvVar5;
          }
          if (pvVar6 != (void *)0x0) {
            *(void **)(param_1 + 0x10) = pvVar6;
          }
          free(local_18);
          free(__ptr);
          free(local_20);
          piVar3 = __errno_location();
          *piVar3 = 0xc;
          return 0xffffffff;
        }
        *(void **)(param_1 + 0x18) = pvVar5;
        *(void **)(param_1 + 0x10) = pvVar6;
        memset((void *)((ulong)*(uint *)(param_1 + 8) * 8 + *(long *)(param_1 + 0x18)),0,
               (ulong)*(uint *)(param_1 + 8) * 8);
        memset((void *)((ulong)*(uint *)(param_1 + 8) * 4 + *(long *)(param_1 + 0x10)),0,
               (ulong)*(uint *)(param_1 + 8) * 4);
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) * 2;
      }
      *(uint *)(*(long *)(param_1 + 0x10) + (ulong)*(uint *)(param_1 + 4) * 4) = local_30;
      *(long **)(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(param_1 + 4) * 8) = __ptr;
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
      free(local_18);
      local_18 = local_20;
      local_2c = local_34;
    }
    free(local_18);
    uVar4 = 0;
  }
  return uVar4;
}


// ===== 00252fa3 FUN_00252fa3 =====

undefined8 FUN_00252fa3(long param_1,long param_2)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  
  if (param_2 == 0) {
    if (*(int *)(param_1 + 0xd0) == 0) {
      uVar3 = 0;
    }
    else {
      FUN_00251e0d(*(undefined8 *)**(undefined8 **)(param_1 + 0x18));
      iVar1 = FUN_0025270e(param_1);
      if (iVar1 < 0) {
        uVar3 = 0xffffffff;
      }
      else {
        iVar1 = FUN_00252651(param_1);
        if (iVar1 < 0) {
          uVar3 = 0xffffffff;
        }
        else {
          *(undefined4 *)(param_1 + 0xd0) = 0;
          uVar3 = 0;
        }
      }
    }
  }
  else {
    piVar2 = __errno_location();
    *piVar2 = 0x16;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ===== 0025303a FUN_0025303a =====

long FUN_0025303a(long param_1,long param_2)

{
  int iVar1;
  long local_20 [2];
  long *local_10;
  
  local_20[0] = param_1;
  for (local_10 = local_20; *local_10 != 0; local_10 = (long *)(*local_10 + 0x58)) {
    iVar1 = strcmp(*(char **)(*local_10 + 0x18),*(char **)(param_2 + 0x18));
    if (-1 < iVar1) break;
  }
  *(long *)(param_2 + 0x58) = *local_10;
  *local_10 = param_2;
  return local_20[0];
}


// ===== 002530b1 FUN_002530b1 =====

void FUN_002530b1(long param_1)

{
  int *piVar1;
  int *local_20;
  undefined8 local_18;
  long local_10;
  
  if (*(long *)(param_1 + 0xa0) != 0) {
    local_20 = (int *)(param_1 + 0xa0);
    local_18 = 0;
    while (piVar1 = *(int **)local_20, piVar1 != (int *)0x0) {
      if (*piVar1 == 0x10) {
        *(undefined8 *)local_20 = *(undefined8 *)(piVar1 + 0x16);
        piVar1[0x16] = 0;
        piVar1[0x17] = 0;
        local_18 = FUN_0025303a(local_18,piVar1);
      }
      else {
        local_20 = piVar1 + 0x16;
      }
    }
    *(undefined8 *)local_20 = local_18;
  }
  for (local_10 = *(long *)(param_1 + 0x78); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)) {
    FUN_002530b1(local_10);
  }
  for (local_10 = *(long *)(param_1 + 0x90); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)) {
    FUN_002530b1(local_10);
  }
  for (local_10 = *(long *)(param_1 + 0xa0); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)) {
    FUN_002530b1(local_10);
  }
  return;
}


// ===== 002531e1 FUN_002531e1 =====

void FUN_002531e1(long param_1)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 0xb8) == 0) {
    uVar1 = FUN_00260eab();
    *(undefined8 *)(param_1 + 0xb8) = uVar1;
  }
  if (*(long *)(param_1 + 0xc0) == 0) {
    uVar1 = FUN_00260eab();
    *(undefined8 *)(param_1 + 0xc0) = uVar1;
  }
  if (*(long *)(param_1 + 200) == 0) {
    uVar1 = FUN_00260eab();
    *(undefined8 *)(param_1 + 200) = uVar1;
  }
  if (*(long *)(param_1 + 0xd0) == 0) {
    uVar1 = FUN_00260eab();
    *(undefined8 *)(param_1 + 0xd0) = uVar1;
  }
  return;
}


// ===== 0025327c FUN_0025327c =====

void FUN_0025327c(long param_1,uint *param_2,undefined8 param_3)

{
  undefined8 *local_10;
  
  FUN_0024d5f6("%s phase discovery...\n",param_3);
  local_10 = *(undefined8 **)(param_1 + 0x318);
  while ((local_10 != (undefined8 *)0x0 && ((param_2[1] & *param_2) == 0))) {
    if (((*param_2 & *(uint *)(local_10 + 4)) != 0) && (local_10[9] != 0)) {
      FUN_0024d5f6("%s phase discovery in component %s...\n",param_3,*(undefined8 *)*local_10);
      (*(code *)local_10[9])(local_10,param_2);
    }
    local_10 = (undefined8 *)local_10[3];
  }
  return;
}


// ===== 00253349 FUN_00253349 =====

undefined8 FUN_00253349(long param_1,undefined4 *param_2)

{
  undefined8 *puVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  int *piVar5;
  char *pcVar6;
  long lVar7;
  void *__ptr;
  
  *(undefined4 *)(param_1 + 0xd0) = 0;
  uVar4 = FUN_00260f39();
  *(undefined8 *)(param_1 + 0x1b8) = uVar4;
  uVar4 = FUN_00260f39();
  *(undefined8 *)(param_1 + 0x1c0) = uVar4;
  if ((*(uint *)(param_1 + 0x328) & 1) != 0) {
    puVar1 = *(undefined8 **)(param_1 + 0x318);
    if (puVar1 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("global_backend",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0xd5b,"hwloc_discover");
    }
    if (*(int *)(puVar1 + 4) != 1) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("global_backend->phases == HWLOC_DISC_PHASE_GLOBAL",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0xd5c,"hwloc_discover");
    }
    FUN_0024d5f6("GLOBAL phase discovery...\n");
    FUN_0024d5f6("GLOBAL phase discovery with component %s...\n",*(undefined8 *)*puVar1);
    *param_2 = 1;
    (*(code *)puVar1[9])(puVar1,param_2);
  }
  if ((*(uint *)(param_1 + 0x328) & 2) != 0) {
    *param_2 = 2;
    FUN_0025327c(param_1,param_2,&DAT_002e9b4d);
  }
  if ((*(uint *)(param_1 + 0x328) & 3) == 0) {
    FUN_0024d5f6("No GLOBAL or CPU component phase found\n");
  }
  if ((*(long *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xb8) == 0) ||
     (iVar3 = FUN_002620a3(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xb8)),
     iVar3 != 0)) {
    FUN_0024d5f6(&DAT_002e95c6,"No PU added by any CPU or GLOBAL component phase\n");
    piVar5 = __errno_location();
    *piVar5 = 0x16;
    return 0xffffffff;
  }
  if ((*(uint *)(param_1 + 0x328) & 4) != 0) {
    *param_2 = 4;
    FUN_0025327c(param_1,param_2,"MEMORY");
  }
  if ((((*(long *)(param_1 + 0x280) != 0) && (*(int *)(param_1 + 200) != 0)) &&
      ((*(ulong *)(param_2 + 2) & 2) == 0)) &&
     (((*(ulong *)(param_1 + 0x20) & 4) != 0 ||
      ((pcVar6 = getenv("HWLOC_THISSYSTEM_ALLOWED_RESOURCES"), pcVar6 != (char *)0x0 &&
       (iVar3 = atoi(pcVar6), iVar3 != 0)))))) {
    (**(code **)(param_1 + 0x280))(param_1);
    *(ulong *)(param_2 + 2) = *(ulong *)(param_2 + 2) | 2;
  }
  iVar3 = FUN_002620a3(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xd0));
  if (iVar3 == 0) {
    free(*(void **)(param_1 + 0x348));
    memset((void *)(param_1 + 0x338),0,0x18);
  }
  else {
    FUN_0024d5f6(&DAT_002e95c6,"\nAdd missing single NUMA node\n");
    lVar7 = FUN_0024febd(param_1,0xd,0);
    uVar4 = FUN_002611e2(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xb8));
    *(undefined8 *)(lVar7 + 0xb8) = uVar4;
    uVar4 = FUN_00260eab();
    *(undefined8 *)(lVar7 + 200) = uVar4;
    FUN_0026197d(*(undefined8 *)(lVar7 + 200),0);
    memcpy(*(void **)(lVar7 + 0x28),(void *)(param_1 + 0x338),0x18);
    memset((void *)(param_1 + 0x338),0,0x18);
    FUN_0024fb45(param_1,0,lVar7,"core:defaultnumanode");
  }
  FUN_0024d5f6(&DAT_002e95c6,"\nFixup root sets\n");
  FUN_002626c1(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xb8),
               *(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xb8),
               *(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xc0));
  FUN_002626c1(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 200),
               *(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 200),
               *(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xd0));
  FUN_002626c1(*(undefined8 *)(param_1 + 0x1b8),*(undefined8 *)(param_1 + 0x1b8),
               *(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xb8));
  FUN_002626c1(*(undefined8 *)(param_1 + 0x1c0),*(undefined8 *)(param_1 + 0x1c0),
               *(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 200));
  FUN_0024d5f6(&DAT_002e95c6,"\nPropagate sets\n");
  FUN_00250861(*(undefined8 *)**(undefined8 **)(param_1 + 0x18));
  FUN_00250431(*(undefined8 *)**(undefined8 **)(param_1 + 0x18));
  if ((*(ulong *)(param_1 + 0x20) & 1) == 0) {
    FUN_0024d5f6(&DAT_002e95c6,"\nRemoving unauthorized sets from all sets\n");
    FUN_00250a5b(param_1,*(undefined8 *)**(undefined8 **)(param_1 + 0x18));
  }
  iVar3 = FUN_0024d3b8(param_1,*(undefined8 *)**(undefined8 **)(param_1 + 0x18));
  if (((iVar3 == 0) && (*(long *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0x78) != 0)) &&
     (*(long *)(*(long *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0x78) + 0x58) == 0)) {
    lVar7 = *(long *)**(undefined8 **)(param_1 + 0x18);
    lVar2 = *(long *)(lVar7 + 0x78);
    *(undefined8 *)(lVar2 + 0x48) = 0;
    *(long *)**(undefined8 **)(param_1 + 0x18) = lVar2;
    if (*(long *)(lVar7 + 0x90) != 0) {
      FUN_0024e3fc(lVar2 + 0x90,*(undefined8 *)(lVar7 + 0x90),lVar2);
    }
    if (*(long *)(lVar7 + 0xa0) != 0) {
      FUN_0024e3fc(lVar2 + 0xa0,*(undefined8 *)(lVar7 + 0xa0),lVar2);
    }
    if (*(long *)(lVar7 + 0xb0) != 0) {
      FUN_0024e3fc(lVar2 + 0xb0,*(undefined8 *)(lVar7 + 0xb0),lVar2);
    }
    FUN_0024e0d0(lVar7);
  }
  FUN_0024d5f6(&DAT_002e95c6,"\nOk, finished tweaking, now connect\n");
  iVar3 = FUN_00252fa3(param_1,0);
  if (iVar3 < 0) {
    return 0xffffffff;
  }
  FUN_0026365d(param_1);
  if ((*(uint *)(param_1 + 0x328) & 8) != 0) {
    *param_2 = 8;
    FUN_0025327c(param_1,param_2,&DAT_002e9c95);
  }
  if ((*(uint *)(param_1 + 0x328) & 0x10) != 0) {
    *param_2 = 0x10;
    FUN_0025327c(param_1,param_2,&DAT_002e9c99);
  }
  if ((*(uint *)(param_1 + 0x328) & 0x20) != 0) {
    *param_2 = 0x20;
    FUN_0025327c(param_1,param_2,&DAT_002e9c9c);
  }
  if ((*(uint *)(param_1 + 0x328) & 0x40) != 0) {
    *param_2 = 0x40;
    FUN_0025327c(param_1,param_2,"ANNOTATE");
  }
  FUN_002637b7(param_1);
  pcVar6 = getenv("HWLOC_DEBUG_SORT_CHILDREN");
  if (pcVar6 != (char *)0x0) {
    FUN_002530b1(*(undefined8 *)**(undefined8 **)(param_1 + 0x18));
  }
  FUN_0024d5f6(&DAT_002e95c6,"\nRemoving bridge objects if needed\n");
  FUN_00250c56(param_1,*(undefined8 *)**(undefined8 **)(param_1 + 0x18));
  FUN_0024d5f6(&DAT_002e95c6,"\nRemoving empty objects\n");
  FUN_00250d56(param_1,**(undefined8 **)(param_1 + 0x18));
  if (*(long *)**(undefined8 **)(param_1 + 0x18) == 0) {
    iVar3 = FUN_0024d64f();
    if (iVar3 < 2) {
      fwrite("hwloc: Topology became empty, aborting!\n",1,0x28,*(FILE **)PTR_stderr_0032efe0);
    }
    return 0xffffffff;
  }
  iVar3 = FUN_002620a3(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xb8));
  if (iVar3 != 0) {
    iVar3 = FUN_0024d64f();
    if (iVar3 < 2) {
      fwrite("hwloc: Topology does not contain any PU, aborting!\n",1,0x33,
             *(FILE **)PTR_stderr_0032efe0);
    }
    return 0xffffffff;
  }
  iVar3 = FUN_002620a3(*(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 200));
  if (iVar3 != 0) {
    iVar3 = FUN_0024d64f();
    if (iVar3 < 2) {
      fwrite("hwloc: Topology does not contain any NUMA node, aborting!\n",1,0x3a,
             *(FILE **)PTR_stderr_0032efe0);
    }
    return 0xffffffff;
  }
  FUN_0024d5f6(&DAT_002e95c6,"\nRemoving levels with HWLOC_TYPE_FILTER_KEEP_STRUCTURE\n");
  iVar3 = FUN_0025111e(param_1);
  if (iVar3 < 0) {
    return 0xffffffff;
  }
  FUN_0024d5f6(&DAT_002e95c6,"\nPropagate total memory up\n");
  FUN_002502cc(*(undefined8 *)**(undefined8 **)(param_1 + 0x18));
  FUN_00251ba3(param_1,*(undefined8 *)**(undefined8 **)(param_1 + 0x18));
  FUN_00251d6a(param_1);
  if (((*(long *)(param_1 + 0x318) != 0) &&
      (iVar3 = strcmp(*(char **)**(undefined8 **)(param_1 + 0x318),"xml"), iVar3 != 0)) &&
     (pcVar6 = getenv("HWLOC_DONT_ADD_VERSION_INFO"), pcVar6 == (char *)0x0)) {
    FUN_0024dfb5(*(undefined8 *)**(undefined8 **)(param_1 + 0x18),"hwlocVersion","2.9.2");
    __ptr = (void *)FUN_0026590a(param_1);
    if (__ptr != (void *)0x0) {
      FUN_0024dfb5(*(undefined8 *)**(undefined8 **)(param_1 + 0x18),"ProcessName",__ptr);
      free(__ptr);
    }
  }
  return 0;
}


// ===== 00253de7 FUN_00253de7 =====

void FUN_00253de7(long param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  memset((void *)(param_1 + 0x1c8),0,0xc0);
  memset(*(void **)(param_1 + 0x288),0,6);
  memset(*(void **)(param_1 + 0x290),0,0xb);
  memset(*(void **)(param_1 + 0x298),0,0xf);
  memset(*(void **)(param_1 + 0x2a0),0,1);
  *(undefined8 *)(param_1 + 0xe0) = 1;
  *(undefined4 *)(param_1 + 4) = 1;
  puVar1 = *(undefined8 **)(param_1 + 0x18);
  uVar2 = FUN_0024d56f(*(undefined8 *)(param_1 + 0x330),8);
  *puVar1 = uVar2;
  **(undefined4 **)(param_1 + 0x10) = 1;
  *(undefined8 *)(param_1 + 0x338) = 0;
  *(undefined4 *)(param_1 + 0x340) = 0;
  *(undefined8 *)(param_1 + 0x348) = 0;
  *(undefined8 *)(param_1 + 0x1b8) = 0;
  *(undefined8 *)(param_1 + 0x1c0) = 0;
  memset((void *)(param_1 + 0xf8),0,0xc0);
  FUN_00250f05(param_1);
  *(undefined4 *)(param_1 + 0x5c) = 0xfffffffd;
  *(undefined4 *)(param_1 + 0x6c) = 0xfffffff9;
  *(undefined4 *)(param_1 + 0x60) = 0xfffffffc;
  *(undefined4 *)(param_1 + 100) = 0xfffffffb;
  *(undefined4 *)(param_1 + 0x68) = 0xfffffffa;
  *(undefined4 *)(param_1 + 0x70) = 0xfffffff8;
  uVar2 = FUN_0024febd(param_1,0,0);
  *(undefined8 *)**(undefined8 **)(param_1 + 0x18) = uVar2;
  return;
}


// ===== 00253fb7 FUN_00253fb7 =====

undefined8 FUN_00253fb7(undefined8 *param_1,undefined4 param_2,undefined8 param_3)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined4 *)FUN_0024d56f(param_3,0x388);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    *(undefined8 *)(puVar1 + 0xcc) = param_3;
    FUN_0025e93d();
    FUN_0025ec9e(puVar1);
    FUN_002635f3(puVar1);
    puVar1[0x33] = 0;
    *(undefined8 *)(puVar1 + 8) = 0;
    puVar1[0x32] = 1;
    puVar1[0x35] = 0;
    *(undefined8 *)(puVar1 + 0x36) = 0;
    *puVar1 = 0x20400;
    *(undefined8 *)(puVar1 + 0x3a) = 0;
    *(undefined8 *)(puVar1 + 0x3c) = 0;
    uVar2 = FUN_0024d56f(param_3,6);
    *(undefined8 *)(puVar1 + 0xa2) = uVar2;
    uVar2 = FUN_0024d56f(param_3,0xb);
    *(undefined8 *)(puVar1 + 0xa4) = uVar2;
    uVar2 = FUN_0024d56f(param_3,0xf);
    *(undefined8 *)(puVar1 + 0xa6) = uVar2;
    uVar2 = FUN_0024d56f(param_3,1);
    *(undefined8 *)(puVar1 + 0xa8) = uVar2;
    puVar1[2] = param_2;
    uVar2 = FUN_0024d5ad(param_3,(ulong)(uint)puVar1[2] * 8);
    *(undefined8 *)(puVar1 + 6) = uVar2;
    uVar2 = FUN_0024d5ad(param_3,(ulong)(uint)puVar1[2] * 4);
    *(undefined8 *)(puVar1 + 4) = uVar2;
    FUN_00254203(puVar1);
    FUN_0025921c(puVar1);
    FUN_0025b10a(puVar1);
    FUN_0025ce15(puVar1);
    *(undefined8 *)(puVar1 + 0xaa) = 0;
    *(undefined8 *)(puVar1 + 0xac) = 0;
    puVar1[0xae] = 0;
    FUN_00253de7(puVar1);
    *param_1 = puVar1;
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 002541df FUN_002541df =====

void FUN_002541df(undefined8 param_1)

{
  FUN_00253fb7(param_1,0x10,0);
  return;
}


// ===== 00254203 FUN_00254203 =====

void FUN_00254203(long param_1)

{
  undefined4 local_c;
  
  for (local_c = 0; local_c < 0x14; local_c = local_c + 1) {
    *(undefined4 *)(param_1 + 8 + ((ulong)local_c + 0x1c) * 4) = 0;
  }
  *(undefined4 *)(param_1 + 0x9c) = 1;
  *(undefined4 *)(param_1 + 0xa0) = 1;
  *(undefined4 *)(param_1 + 0xa4) = 1;
  *(undefined4 *)(param_1 + 0xc0) = 1;
  *(undefined4 *)(param_1 + 0xa8) = 2;
  *(undefined4 *)(param_1 + 0xbc) = 1;
  *(undefined4 *)(param_1 + 0xb0) = 1;
  *(undefined4 *)(param_1 + 0xb4) = 1;
  *(undefined4 *)(param_1 + 0xb8) = 1;
  return;
}


// ===== 002542b2 FUN_002542b2 =====

undefined8 FUN_002542b2(long param_1,uint param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int local_18;
  
  if (((param_2 == 3) || (param_2 == 0xd)) || (param_2 == 0)) {
    if (param_3 != 0) {
      piVar2 = __errno_location();
      *piVar2 = 0x16;
      return 0xffffffff;
    }
  }
  else {
    iVar1 = FUN_0024d4ca(param_2);
    if (iVar1 == 0) {
      if ((param_2 == 0xc) && (param_3 == 0)) {
        piVar2 = __errno_location();
        *piVar2 = 0x16;
        return 0xffffffff;
      }
    }
    else if (param_3 == 2) {
      piVar2 = __errno_location();
      *piVar2 = 0x16;
      return 0xffffffff;
    }
  }
  iVar1 = FUN_0024d4ca(param_2);
  local_18 = param_3;
  if ((iVar1 == 0) && (param_3 == 3)) {
    local_18 = 0;
  }
  *(int *)(param_1 + 8 + ((ulong)param_2 + 0x1c) * 4) = local_18;
  return 0;
}


// ===== 00254366 FUN_00254366 =====

undefined8 FUN_00254366(long param_1,undefined4 param_2)

{
  int *piVar1;
  undefined8 uVar2;
  undefined4 local_c;
  
  if (*(int *)(param_1 + 0xcc) == 0) {
    for (local_c = 0; local_c < 0x14; local_c = local_c + 1) {
      FUN_002542b2(param_1,local_c,param_2);
    }
    uVar2 = 0;
  }
  else {
    piVar1 = __errno_location();
    *piVar1 = 0x10;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// ===== 002543c3 FUN_002543c3 =====

undefined8 FUN_002543c3(long param_1,uint param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined8 uVar2;
  
  if (param_2 < 0x14) {
    *param_3 = *(undefined4 *)(param_1 + 8 + ((ulong)param_2 + 0x1c) * 4);
    uVar2 = 0;
  }
  else {
    piVar1 = __errno_location();
    *piVar1 = 0x16;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// ===== 0025440a FUN_0025440a =====

void FUN_0025440a(long param_1)

{
  undefined4 local_c;
  
  FUN_0025ce4b(param_1);
  FUN_00259466(param_1);
  FUN_0025b3ab(param_1);
  FUN_0024e331(*(undefined8 *)**(undefined8 **)(param_1 + 0x18));
  FUN_00260f71(*(undefined8 *)(param_1 + 0x1b8));
  FUN_00260f71(*(undefined8 *)(param_1 + 0x1c0));
  for (local_c = 0; local_c < *(uint *)(param_1 + 4); local_c = local_c + 1) {
    free(*(void **)(*(long *)(param_1 + 0x18) + (ulong)local_c * 8));
  }
  for (local_c = 0; local_c < 6; local_c = local_c + 1) {
    free(*(void **)(param_1 + (ulong)local_c * 0x20 + 0x100));
  }
  free(*(void **)(param_1 + 0x348));
  return;
}


// ===== 002544f4 FUN_002544f4 =====

void FUN_002544f4(void *param_1)

{
  if (*(long *)((long)param_1 + 0xe8) == 0) {
    FUN_0025fe51(param_1);
    FUN_0025feee(param_1);
    FUN_0025f883();
    FUN_0025440a(param_1);
    free(*(void **)((long)param_1 + 0x18));
    free(*(void **)((long)param_1 + 0x10));
    free(*(void **)((long)param_1 + 0x288));
    free(*(void **)((long)param_1 + 0x290));
    free(*(void **)((long)param_1 + 0x298));
    free(*(void **)((long)param_1 + 0x2a0));
    free(param_1);
  }
  else {
    FUN_002653f1(param_1);
  }
  return;
}


// ===== 002545c4 FUN_002545c4 =====

undefined8 FUN_002545c4(long param_1)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined1 local_5c [4];
  undefined4 local_58;
  undefined4 local_54;
  ulong local_50;
  long local_48;
  long local_40;
  int local_34;
  char *local_30;
  char *local_28;
  char *local_20;
  char *local_18;
  char *local_10;
  
  if (*(int *)(param_1 + 0xcc) == 0) {
    FUN_0025925a(param_1);
    FUN_0025b184(param_1);
    pcVar4 = getenv("HWLOC_XML_USERDATA_NOT_DECODED");
    if (pcVar4 != (char *)0x0) {
      *(undefined4 *)(param_1 + 0x2b8) = 1;
    }
    pcVar4 = getenv("HWLOC_COMPONENTS");
    if (pcVar4 == (char *)0x0) {
      if (*(long *)(param_1 + 0x318) == 0) {
        local_10 = getenv("HWLOC_FSROOT");
        if (local_10 != (char *)0x0) {
          FUN_0025f125(param_1,1,"linux",0,0,0);
        }
      }
      if (*(long *)(param_1 + 0x318) == 0) {
        local_18 = getenv("HWLOC_CPUID_PATH");
        if (local_18 != (char *)0x0) {
          FUN_0025f125(param_1,1,&DAT_002e9e9c,0,0,0);
        }
      }
      if (*(long *)(param_1 + 0x318) == 0) {
        local_20 = getenv("HWLOC_SYNTHETIC");
        if (local_20 != (char *)0x0) {
          FUN_0025f125(param_1,1,"synthetic",local_20,0,0);
        }
      }
      if (*(long *)(param_1 + 0x318) == 0) {
        local_28 = getenv("HWLOC_XMLFILE");
        if (local_28 != (char *)0x0) {
          FUN_0025f125(param_1,1,&DAT_002e9e04,local_28,0,0);
        }
      }
    }
    local_54 = 0;
    local_50 = 0;
    local_30 = getenv("HWLOC_ALLOW");
    if (local_30 != (char *)0x0) {
      iVar1 = strcmp(local_30,"all");
      if (iVar1 == 0) {
        local_50 = local_50 | 2;
      }
    }
    FUN_0025f38d(param_1);
    FUN_0025fca4(param_1);
    FUN_0025fdf5(param_1);
    FUN_00260aa6(param_1);
    local_34 = FUN_00253349(param_1,&local_58);
    if (local_34 < 0) {
      FUN_002637b7(param_1);
      FUN_0025440a(param_1);
      FUN_00253de7(param_1);
      FUN_0025fe51(param_1);
      uVar3 = 0xffffffff;
    }
    else {
      pcVar4 = getenv("HWLOC_DEBUG_CHECK");
      if (pcVar4 != (char *)0x0) {
        FUN_00257529(param_1);
      }
      FUN_0025e18a(param_1);
      FUN_0025a2b5(param_1);
      FUN_0025a1b0(param_1);
      FUN_0025bc4b(param_1);
      FUN_0025bbe3(param_1);
      FUN_0025c4af(param_1);
      *(undefined4 *)(param_1 + 0xcc) = 1;
      if ((*(ulong *)(param_1 + 0x20) & 0x10) != 0) {
        local_40 = FUN_00260eab();
        if (local_40 != 0) {
          local_34 = FUN_00260254(param_1,local_40,4);
          if (local_34 == 0) {
            FUN_00255049(param_1,local_40,0);
          }
          FUN_00260f71(local_40);
        }
      }
      if ((*(ulong *)(param_1 + 0x20) & 0x20) != 0) {
        local_48 = FUN_00260eab();
        if (local_48 != 0) {
          local_34 = FUN_002604c0(param_1,local_48,local_5c,0x24);
          if (local_34 == 0) {
            FUN_00255049(param_1,local_48,8);
          }
          FUN_00260f71(local_48);
        }
      }
      if ((*(uint *)(param_1 + 0x328) & 0x80) != 0) {
        local_58 = 0x80;
        FUN_0025327c(param_1,&local_58,"TWEAK");
      }
      uVar3 = 0;
    }
  }
  else {
    piVar2 = __errno_location();
    *piVar2 = 0x10;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ===== 002549cd FUN_002549cd =====

void FUN_002549cd(long param_1,ulong param_2,undefined8 *param_3,undefined8 param_4,long param_5)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  long *local_18;
  long local_10;
  
  piVar1 = (int *)*param_3;
  iVar2 = FUN_002622a3(*(undefined8 *)(piVar1 + 0x30),param_4);
  bVar3 = iVar2 != 0;
  if (bVar3) {
    FUN_00262868(*(undefined8 *)(piVar1 + 0x2e),*(undefined8 *)(piVar1 + 0x2e),param_4);
    FUN_00262868(*(undefined8 *)(piVar1 + 0x30),*(undefined8 *)(piVar1 + 0x30),param_4);
  }
  if (param_5 != 0) {
    iVar2 = FUN_002622a3(*(undefined8 *)(piVar1 + 0x34),param_5);
    if (iVar2 != 0) {
      FUN_00262868(*(undefined8 *)(piVar1 + 0x32),*(undefined8 *)(piVar1 + 0x32),param_5);
      FUN_00262868(*(undefined8 *)(piVar1 + 0x34),*(undefined8 *)(piVar1 + 0x34),param_5);
      bVar3 = true;
    }
  }
  if (bVar3) {
    local_18 = (long *)(piVar1 + 0x1e);
    local_10 = *local_18;
    while (local_10 != 0) {
      FUN_002549cd(param_1,param_2,local_18,param_4,param_5);
      if (local_10 == *local_18) {
        local_18 = (long *)(local_10 + 0x58);
      }
      local_10 = *local_18;
    }
    FUN_00250cb5(piVar1);
    local_18 = (long *)(piVar1 + 0x24);
    local_10 = *local_18;
    while (local_10 != 0) {
      FUN_002549cd(param_1,param_2,local_18,param_4,param_5);
      if (local_10 == *local_18) {
        local_18 = (long *)(local_10 + 0x58);
      }
      local_10 = *local_18;
    }
  }
  if ((*(long *)(piVar1 + 0x1e) == 0) && (*(long *)(piVar1 + 0x24) == 0)) {
    iVar2 = FUN_002620a3(*(undefined8 *)(piVar1 + 0x2e));
    if ((iVar2 != 0) && ((*piVar1 != 0xd || ((param_2 & 1) != 0)))) {
      FUN_0024d5f6(&DAT_002e95c6,"\nRemoving object during restrict by cpuset");
      if ((param_2 & 4) == 0) {
        FUN_0024e34c(*(undefined8 *)(piVar1 + 0x28));
        piVar1[0x28] = 0;
        piVar1[0x29] = 0;
      }
      if ((param_2 & 2) == 0) {
        FUN_0024e34c(*(undefined8 *)(piVar1 + 0x2c));
        piVar1[0x2c] = 0;
        piVar1[0x2d] = 0;
      }
      if (*(long *)(piVar1 + 0x1e) != 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!obj->first_child",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x1088,"restrict_object_by_cpuset");
      }
      if (*(long *)(piVar1 + 0x24) != 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!obj->memory_first_child",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x1089,"restrict_object_by_cpuset");
      }
      FUN_0024e578(param_3);
      *(undefined4 *)(param_1 + 0xd0) = 1;
    }
  }
  return;
}


// ===== 00254d05 FUN_00254d05 =====

void FUN_00254d05(long param_1,ulong param_2,undefined8 *param_3,long param_4,undefined8 param_5)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  long *local_18;
  long local_10;
  
  piVar1 = (int *)*param_3;
  iVar2 = FUN_002622a3(*(undefined8 *)(piVar1 + 0x34),param_5);
  bVar3 = iVar2 != 0;
  if (bVar3) {
    FUN_00262868(*(undefined8 *)(piVar1 + 0x32),*(undefined8 *)(piVar1 + 0x32),param_5);
    FUN_00262868(*(undefined8 *)(piVar1 + 0x34),*(undefined8 *)(piVar1 + 0x34),param_5);
  }
  if (param_4 != 0) {
    iVar2 = FUN_002622a3(*(undefined8 *)(piVar1 + 0x30),param_4);
    if (iVar2 != 0) {
      FUN_00262868(*(undefined8 *)(piVar1 + 0x2e),*(undefined8 *)(piVar1 + 0x2e),param_4);
      FUN_00262868(*(undefined8 *)(piVar1 + 0x30),*(undefined8 *)(piVar1 + 0x30),param_4);
      bVar3 = true;
    }
  }
  if (bVar3) {
    local_18 = (long *)(piVar1 + 0x1e);
    local_10 = *local_18;
    while (local_10 != 0) {
      FUN_00254d05(param_1,param_2,local_18,param_4,param_5);
      if (local_10 == *local_18) {
        local_18 = (long *)(local_10 + 0x58);
      }
      local_10 = *local_18;
    }
    if ((param_2 & 0x10) != 0) {
      FUN_00250cb5(piVar1);
    }
    local_18 = (long *)(piVar1 + 0x24);
    local_10 = *local_18;
    while (local_10 != 0) {
      FUN_00254d05(param_1,param_2,local_18,param_4,param_5);
      if (local_10 == *local_18) {
        local_18 = (long *)(local_10 + 0x58);
      }
      local_10 = *local_18;
    }
  }
  if ((*(long *)(piVar1 + 0x1e) == 0) && (*(long *)(piVar1 + 0x24) == 0)) {
    iVar2 = FUN_002620a3(*(undefined8 *)(piVar1 + 0x32));
    if ((iVar2 != 0) && ((*piVar1 != 3 || ((param_2 & 0x10) != 0)))) {
      FUN_0024d5f6(&DAT_002e95c6,"\nRemoving object during restrict by nodeset");
      if ((param_2 & 4) == 0) {
        FUN_0024e34c(*(undefined8 *)(piVar1 + 0x28));
        piVar1[0x28] = 0;
        piVar1[0x29] = 0;
      }
      if ((param_2 & 2) == 0) {
        FUN_0024e34c(*(undefined8 *)(piVar1 + 0x2c));
        piVar1[0x2c] = 0;
        piVar1[0x2d] = 0;
      }
      if (*(long *)(piVar1 + 0x1e) != 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!obj->first_child",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x10c3,"restrict_object_by_nodeset");
      }
      if (*(long *)(piVar1 + 0x24) != 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!obj->memory_first_child",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x10c4,"restrict_object_by_nodeset");
      }
      FUN_0024e578(param_3);
      *(undefined4 *)(param_1 + 0xd0) = 1;
    }
  }
  return;
}


// ===== 00255049 FUN_00255049 =====

undefined8 FUN_00255049(long param_1,undefined8 param_2,ulong param_3)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  undefined8 uVar4;
  long local_28;
  long local_20;
  long local_18;
  long local_10;
  
  if (*(int *)(param_1 + 0xcc) == 0) {
    piVar2 = __errno_location();
    *piVar2 = 0x16;
    return 0xffffffff;
  }
  if (*(long *)(param_1 + 0xe8) != 0) {
    piVar2 = __errno_location();
    *piVar2 = 1;
    return 0xffffffff;
  }
  if ((param_3 & 0xffffffffffffffe0) != 0) {
    piVar2 = __errno_location();
    *piVar2 = 0x16;
    return 0xffffffff;
  }
  if ((param_3 & 8) == 0) {
    if ((param_3 & 0x10) != 0) {
      piVar2 = __errno_location();
      *piVar2 = 0x16;
      return 0xffffffff;
    }
  }
  else if ((param_3 & 1) != 0) {
    piVar2 = __errno_location();
    *piVar2 = 0x16;
    return 0xffffffff;
  }
  if ((((param_3 & 8) == 0) ||
      (iVar1 = FUN_002622a3(param_2,*(undefined8 *)(param_1 + 0x1c0)), iVar1 != 0)) &&
     (((param_3 & 8) != 0 ||
      (iVar1 = FUN_002622a3(param_2,*(undefined8 *)(param_1 + 0x1b8)), iVar1 != 0)))) {
    local_10 = FUN_00260eab();
    local_18 = FUN_00260eab();
    if ((local_10 == 0) || (local_18 == 0)) {
      FUN_00260f71(local_10);
      FUN_00260f71(local_18);
      return 0xffffffff;
    }
    if ((param_3 & 8) == 0) {
      FUN_00262a17(local_10,param_2);
      if ((param_3 & 1) != 0) {
        local_28 = FUN_0024d268(param_1,0xd,0);
        if (local_28 == 0) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("node",
                        "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                        ,0x1126,"hwloc_topology_restrict");
        }
        do {
          iVar1 = FUN_002620a3(*(undefined8 *)(local_28 + 0xb8));
          if ((iVar1 != 0) ||
             (iVar1 = FUN_002623d5(*(undefined8 *)(local_28 + 0xb8),local_10), iVar1 != 0)) {
            FUN_0026197d(local_18,*(undefined4 *)(local_28 + 0x10));
          }
          local_28 = *(long *)(local_28 + 0x38);
        } while (local_28 != 0);
        iVar1 = FUN_002623d5(*(undefined8 *)(param_1 + 0x1c0),local_18);
        if (iVar1 != 0) {
          piVar2 = __errno_location();
          *piVar2 = 0x16;
          FUN_00260f71(local_10);
          FUN_00260f71(local_18);
          return 0xffffffff;
        }
      }
      if (((param_3 & 1) == 0) || (iVar1 = FUN_002620a3(local_18), iVar1 != 0)) {
        FUN_00260f71(local_18);
        local_18 = 0;
      }
      FUN_002549cd(param_1,param_3,**(undefined8 **)(param_1 + 0x18),local_10,local_18);
      FUN_00262868(*(undefined8 *)(param_1 + 0x1b8),*(undefined8 *)(param_1 + 0x1b8),local_10);
      if (local_18 != 0) {
        FUN_00262868(*(undefined8 *)(param_1 + 0x1c0),*(undefined8 *)(param_1 + 0x1c0),local_18);
      }
    }
    else {
      FUN_00262a17(local_18,param_2);
      if ((param_3 & 0x10) != 0) {
        local_20 = FUN_0024d268(param_1,3,0);
        if (local_20 == 0) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("pu",
                        "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                        ,0x1102,"hwloc_topology_restrict");
        }
        do {
          iVar1 = FUN_002620a3(*(undefined8 *)(local_20 + 0xb8));
          if ((iVar1 != 0) ||
             (iVar1 = FUN_002623d5(*(undefined8 *)(local_20 + 200),local_18), iVar1 != 0)) {
            FUN_0026197d(local_10,*(undefined4 *)(local_20 + 0x10));
          }
          local_20 = *(long *)(local_20 + 0x38);
        } while (local_20 != 0);
        iVar1 = FUN_002623d5(*(undefined8 *)(param_1 + 0x1b8),local_10);
        if (iVar1 != 0) {
          piVar2 = __errno_location();
          *piVar2 = 0x16;
          FUN_00260f71(local_10);
          FUN_00260f71(local_18);
          return 0xffffffff;
        }
      }
      if (((param_3 & 0x10) == 0) || (iVar1 = FUN_002620a3(local_10), iVar1 != 0)) {
        FUN_00260f71(local_10);
        local_10 = 0;
      }
      FUN_00254d05(param_1,param_3,**(undefined8 **)(param_1 + 0x18),local_10,local_18);
      FUN_00262868(*(undefined8 *)(param_1 + 0x1c0),*(undefined8 *)(param_1 + 0x1c0),local_18);
      if (local_10 != 0) {
        FUN_00262868(*(undefined8 *)(param_1 + 0x1b8),*(undefined8 *)(param_1 + 0x1b8),local_10);
      }
    }
    FUN_00260f71(local_10);
    FUN_00260f71(local_18);
    iVar1 = FUN_0025111e(param_1);
    if (iVar1 < 0) {
      FUN_0025440a(param_1);
      FUN_00253de7(param_1);
      uVar4 = 0xffffffff;
    }
    else {
      FUN_0025a2b5(param_1);
      FUN_0025bc4b(param_1);
      FUN_00251ba3(param_1,*(undefined8 *)**(undefined8 **)(param_1 + 0x18));
      FUN_002502cc(*(undefined8 *)**(undefined8 **)(param_1 + 0x18));
      FUN_0025cef1(param_1);
      pcVar3 = getenv("HWLOC_DEBUG_CHECK");
      if (pcVar3 != (char *)0x0) {
        FUN_00257529(param_1);
      }
      uVar4 = 0;
    }
    return uVar4;
  }
  piVar2 = __errno_location();
  *piVar2 = 0x16;
  return 0xffffffff;
}


// ===== 00255600 FUN_00255600 =====

undefined4 FUN_00255600(long param_1)

{
  return *(undefined4 *)(param_1 + 4);
}


// ===== 00255611 FUN_00255611 =====

undefined8 FUN_00255611(undefined8 param_1)

{
  long lVar1;
  
  lVar1 = FUN_0024d2be(param_1);
  return *(undefined8 *)(lVar1 + 0xc0);
}


// ===== 00255632 FUN_00255632 =====

undefined8 FUN_00255632(undefined8 param_1)

{
  long lVar1;
  
  lVar1 = FUN_0024d2be(param_1);
  return *(undefined8 *)(lVar1 + 0xb8);
}


// ===== 00255653 FUN_00255653 =====

undefined8 FUN_00255653(undefined8 param_1)

{
  long lVar1;
  
  lVar1 = FUN_0024d2be(param_1);
  return *(undefined8 *)(lVar1 + 0xd0);
}


// ===== 00255674 FUN_00255674 =====

undefined8 FUN_00255674(undefined8 param_1)

{
  long lVar1;
  
  lVar1 = FUN_0024d2be(param_1);
  return *(undefined8 *)(lVar1 + 200);
}


// ===== 00255695 FUN_00255695 =====

void FUN_00255695(long param_1,long param_2,int param_3,uint param_4,long param_5,long param_6)

{
  if (param_1 != *(long *)(param_5 + 0x48)) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("child->parent == parent",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x11fb,"hwloc__check_child_siblings");
  }
  if (param_4 != *(uint *)(param_5 + 0x50)) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("child->sibling_rank == i",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x11fd,"hwloc__check_child_siblings");
  }
  if ((param_2 != 0) && (param_5 != *(long *)(param_2 + (ulong)param_4 * 8))) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("child == array[i]",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x11ff,"hwloc__check_child_siblings");
  }
  if ((param_6 != 0) && (param_5 != *(long *)(param_6 + 0x58))) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("prev->next_sibling == child",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x1202,"hwloc__check_child_siblings");
  }
  if (param_6 != *(long *)(param_5 + 0x60)) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("child->prev_sibling == prev",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x1203,"hwloc__check_child_siblings");
  }
  if (param_4 == 0) {
    if (*(long *)(param_5 + 0x60) != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("child->prev_sibling == ((void *)0)",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1206,"hwloc__check_child_siblings");
    }
  }
  else if (*(long *)(param_5 + 0x60) == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("child->prev_sibling != ((void *)0)",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x1208,"hwloc__check_child_siblings");
  }
  if (param_4 == param_3 - 1U) {
    if (*(long *)(param_5 + 0x58) != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("child->next_sibling == ((void *)0)",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x120b,"hwloc__check_child_siblings");
    }
  }
  else if (*(long *)(param_5 + 0x58) == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("child->next_sibling != ((void *)0)",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x120d,"hwloc__check_child_siblings");
  }
  return;
}


// ===== 00255871 FUN_00255871 =====

void FUN_00255871(undefined8 param_1,undefined8 param_2,int *param_3)

{
  int iVar1;
  int local_1c;
  undefined4 *local_18;
  undefined4 *local_10;
  
  if (param_3[0x1a] == 0) {
    if (*(long *)(param_3 + 0x1c) != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!parent->children",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x121c,"hwloc__check_normal_children");
    }
    if (*(long *)(param_3 + 0x1e) != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!parent->first_child",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x121d,"hwloc__check_normal_children");
    }
    if (*(long *)(param_3 + 0x20) != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!parent->last_child",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x121e,"hwloc__check_normal_children");
    }
  }
  else {
    if (*(long *)(param_3 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("parent->children",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1222,"hwloc__check_normal_children");
    }
    if (*(long *)(param_3 + 0x1e) == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("parent->first_child",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1223,"hwloc__check_normal_children");
    }
    if (*(long *)(param_3 + 0x20) == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("parent->last_child",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1224,"hwloc__check_normal_children");
    }
    local_18 = (undefined4 *)0x0;
    local_10 = *(undefined4 **)(param_3 + 0x1e);
    local_1c = 0;
    for (; local_10 != (undefined4 *)0x0; local_10 = *(undefined4 **)(local_10 + 0x16)) {
      iVar1 = FUN_0024d488(*local_10);
      if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("hwloc__obj_type_is_normal(child->type)",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x122b,"hwloc__check_normal_children");
      }
      if ((int)local_10[0xc] <= param_3[0xc]) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("child->depth > parent->depth",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x122d,"hwloc__check_normal_children");
      }
      FUN_00255695(param_3,*(undefined8 *)(param_3 + 0x1c),param_3[0x1a],local_1c,local_10,local_18)
      ;
      FUN_00256538(param_1,param_2,local_10);
      local_18 = local_10;
      local_1c = local_1c + 1;
    }
    if (local_1c != param_3[0x1a]) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("j == parent->arity",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1234,"hwloc__check_normal_children");
    }
    if (*(long *)(param_3 + 0x1e) != **(long **)(param_3 + 0x1c)) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("parent->first_child == parent->children[0]",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1236,"hwloc__check_normal_children");
    }
    if (*(long *)(param_3 + 0x20) !=
        *(long *)((ulong)(param_3[0x1a] - 1) * 8 + *(long *)(param_3 + 0x1c))) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("parent->last_child == parent->children[parent->arity-1]",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1237,"hwloc__check_normal_children");
    }
    if ((*param_3 == 3) && (param_3[0x1a] != 0)) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!parent->arity",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x123b,"hwloc__check_normal_children");
    }
  }
  return;
}


// ===== 00255b74 FUN_00255b74 =====

void FUN_00255b74(long param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  int local_14;
  long local_10;
  
  if (*param_2 == 3) {
    iVar2 = FUN_00262e86(*(undefined8 *)(param_2 + 0x2e));
    if (iVar2 != 1) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_bitmap_weight(obj->cpuset) == 1",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1247,"hwloc__check_children_cpusets");
    }
    iVar2 = FUN_00262aab(*(undefined8 *)(param_2 + 0x2e));
    if (iVar2 != param_2[4]) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_bitmap_first(obj->cpuset) == (int) obj->os_index",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1248,"hwloc__check_children_cpusets");
    }
    iVar2 = FUN_00262e86(*(undefined8 *)(param_2 + 0x30));
    if (iVar2 != 1) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_bitmap_weight(obj->complete_cpuset) == 1",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1249,"hwloc__check_children_cpusets");
    }
    iVar2 = FUN_00262aab(*(undefined8 *)(param_2 + 0x30));
    if (iVar2 != param_2[4]) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_bitmap_first(obj->complete_cpuset) == (int) obj->os_index",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x124a,"hwloc__check_children_cpusets");
    }
    if ((*(ulong *)(param_1 + 0x20) & 1) == 0) {
      iVar2 = FUN_0026203b(*(undefined8 *)(param_1 + 0x1b8),param_2[4]);
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("hwloc_bitmap_isset(topology->allowed_cpuset, (int) obj->os_index)",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x124c,"hwloc__check_children_cpusets");
      }
    }
    if (param_2[0x1a] != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!obj->arity",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x124e,"hwloc__check_children_cpusets");
    }
  }
  else {
    iVar2 = FUN_0024d4a9(*param_2);
    if (iVar2 == 0) {
      iVar2 = FUN_0024d4ca(*param_2);
      if (iVar2 == 0) {
        uVar3 = FUN_00260eab();
        for (local_10 = *(long *)(param_2 + 0x1e); local_10 != 0;
            local_10 = *(long *)(local_10 + 0x58)) {
          iVar2 = FUN_002622a3(uVar3,*(undefined8 *)(local_10 + 0xb8));
          if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
            __assert_fail("!hwloc_bitmap_intersects(set, child->cpuset)",
                          "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                          ,0x1258,"hwloc__check_children_cpusets");
          }
          FUN_00262517(uVar3,uVar3,*(undefined8 *)(local_10 + 0xb8));
        }
        iVar2 = FUN_00262158(uVar3,*(undefined8 *)(param_2 + 0x2e));
        if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("hwloc_bitmap_isequal(set, obj->cpuset)",
                        "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                        ,0x125b,"hwloc__check_children_cpusets");
        }
        FUN_00260f71(uVar3);
      }
    }
    else {
      iVar2 = FUN_00262158(*(undefined8 *)(*(long *)(param_2 + 0x12) + 0xb8),
                           *(undefined8 *)(param_2 + 0x2e));
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("hwloc_bitmap_isequal(obj->parent->cpuset, obj->cpuset)",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x1251,"hwloc__check_children_cpusets");
      }
      if (param_2[0x1a] != 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!obj->arity",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x1252,"hwloc__check_children_cpusets");
      }
    }
  }
  for (local_10 = *(long *)(param_2 + 0x24); local_10 != 0; local_10 = *(long *)(local_10 + 0x58)) {
    iVar2 = FUN_00262158(*(undefined8 *)(param_2 + 0x2e),*(undefined8 *)(local_10 + 0xb8));
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_bitmap_isequal(obj->cpuset, child->cpuset)",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1261,"hwloc__check_children_cpusets");
    }
  }
  local_14 = -1;
  bVar1 = false;
  local_10 = *(long *)(param_2 + 0x1e);
  do {
    if (local_10 == 0) {
      return;
    }
    iVar2 = FUN_00262aab(*(undefined8 *)(local_10 + 0xc0));
    if (iVar2 < 0) {
      bVar1 = true;
    }
    else {
      if (bVar1) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!prev_empty",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x126b,"hwloc__check_children_cpusets");
      }
      if (iVar2 <= local_14) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("prev_first < first",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x126c,"hwloc__check_children_cpusets");
      }
    }
    local_10 = *(long *)(local_10 + 0x58);
    local_14 = iVar2;
  } while( true );
}


// ===== 00255f7c FUN_00255f7c =====

void FUN_00255f7c(undefined8 param_1,undefined8 param_2,int *param_3)

{
  int iVar1;
  undefined4 *local_20;
  undefined4 *local_18;
  int local_c;
  
  if (param_3[0x23] == 0) {
    if (*(long *)(param_3 + 0x24) != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!parent->memory_first_child",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x127c,"hwloc__check_memory_children");
    }
  }
  else {
    if (*(long *)(param_3 + 0x24) == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("parent->memory_first_child",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1280,"hwloc__check_memory_children");
    }
    local_20 = (undefined4 *)0x0;
    local_18 = *(undefined4 **)(param_3 + 0x24);
    local_c = 0;
    for (; local_18 != (undefined4 *)0x0; local_18 = *(undefined4 **)(local_18 + 0x16)) {
      iVar1 = FUN_0024d4a9(*local_18);
      if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("hwloc__obj_type_is_memory(child->type)",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x1285,"hwloc__check_memory_children");
      }
      FUN_00255695(param_3,0,param_3[0x23],local_c,local_18,local_20);
      if (*(long *)(local_18 + 0x1e) != 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!child->first_child",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x1289,"hwloc__check_memory_children");
      }
      if (*(long *)(local_18 + 0x28) != 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!child->io_first_child",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x128a,"hwloc__check_memory_children");
      }
      FUN_00256538(param_1,param_2,local_18);
      local_20 = local_18;
      local_c = local_c + 1;
    }
    if (local_c != param_3[0x23]) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("j == parent->memory_arity",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x128e,"hwloc__check_memory_children");
    }
    if ((*param_3 == 0xd) && (param_3[0x23] != 0)) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!parent->memory_arity",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1292,"hwloc__check_memory_children");
    }
  }
  return;
}


// ===== 0025617d FUN_0025617d =====

void FUN_0025617d(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  undefined4 *local_20;
  undefined4 *local_18;
  int local_c;
  
  if (*(int *)(param_3 + 0x98) == 0) {
    if (*(long *)(param_3 + 0xa0) != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!parent->io_first_child",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x129d,"hwloc__check_io_children");
    }
  }
  else {
    if (*(long *)(param_3 + 0xa0) == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("parent->io_first_child",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x12a1,"hwloc__check_io_children");
    }
    local_20 = (undefined4 *)0x0;
    local_18 = *(undefined4 **)(param_3 + 0xa0);
    local_c = 0;
    for (; local_18 != (undefined4 *)0x0; local_18 = *(undefined4 **)(local_18 + 0x16)) {
      iVar1 = FUN_0024d4eb(*local_18);
      if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("hwloc__obj_type_is_io(child->type)",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x12a7,"hwloc__check_io_children");
      }
      FUN_00255695(param_3,0,*(undefined4 *)(param_3 + 0x98),local_c,local_18,local_20);
      if (*(long *)(local_18 + 0x1e) != 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!child->first_child",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x12ab,"hwloc__check_io_children");
      }
      if (*(long *)(local_18 + 0x24) != 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!child->memory_first_child",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x12ac,"hwloc__check_io_children");
      }
      FUN_00256538(param_1,param_2,local_18);
      local_20 = local_18;
      local_c = local_c + 1;
    }
    if (local_c != *(int *)(param_3 + 0x98)) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("j == parent->io_arity",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x12b0,"hwloc__check_io_children");
    }
  }
  return;
}


// ===== 00256346 FUN_00256346 =====

void FUN_00256346(undefined8 param_1,undefined8 param_2,long param_3)

{
  int *local_20;
  int *local_18;
  int local_c;
  
  if (*(int *)(param_3 + 0xa8) == 0) {
    if (*(long *)(param_3 + 0xb0) != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!parent->misc_first_child",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x12bb,"hwloc__check_misc_children");
    }
  }
  else {
    if (*(long *)(param_3 + 0xb0) == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("parent->misc_first_child",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x12bf,"hwloc__check_misc_children");
    }
    local_20 = (int *)0x0;
    local_18 = *(int **)(param_3 + 0xb0);
    local_c = 0;
    for (; local_18 != (int *)0x0; local_18 = *(int **)(local_18 + 0x16)) {
      if (*local_18 != 0x11) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("child->type == HWLOC_OBJ_MISC",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x12c5,"hwloc__check_misc_children");
      }
      FUN_00255695(param_3,0,*(undefined4 *)(param_3 + 0xa8),local_c,local_18,local_20);
      if (*(long *)(local_18 + 0x1e) != 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!child->first_child",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x12c9,"hwloc__check_misc_children");
      }
      if (*(long *)(local_18 + 0x24) != 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!child->memory_first_child",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x12ca,"hwloc__check_misc_children");
      }
      if (*(long *)(local_18 + 0x28) != 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!child->io_first_child",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x12cb,"hwloc__check_misc_children");
      }
      FUN_00256538(param_1,param_2,local_18);
      local_20 = local_18;
      local_c = local_c + 1;
    }
    if (local_c != *(int *)(param_3 + 0xa8)) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("j == parent->misc_arity",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x12cf,"hwloc__check_misc_children");
    }
  }
  return;
}


// ===== 00256538 FUN_00256538 =====

void FUN_00256538(undefined8 param_1,undefined8 param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  long local_18;
  long local_10;
  
  iVar1 = FUN_0026203b(param_2,*(ulong *)(param_3 + 0x3c) & 0xffffffff);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!hwloc_bitmap_isset(gp_indexes, obj->gp_index)",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x12d8,"hwloc__check_object");
  }
  FUN_0026197d(param_2,*(ulong *)(param_3 + 0x3c) & 0xffffffff);
  if (0x13 < *param_3) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("(unsigned) obj->type < HWLOC_OBJ_TYPE_MAX",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x12dc,"hwloc__check_object");
  }
  iVar1 = FUN_0024d3b8(param_1,param_3);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("hwloc_filter_check_keep_object(topology, obj)",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x12de,"hwloc__check_object");
  }
  iVar1 = FUN_0024d4ca(*param_3);
  if (iVar1 == 0) {
    if (*(long *)(param_3 + 0x2e) == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("obj->cpuset",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x12ec,"hwloc__check_object");
    }
    if (*param_3 == 0xd) {
      if (param_3[0xc] != 0xfffffffd) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("obj->depth == HWLOC_TYPE_DEPTH_NUMANODE",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x12ee,"hwloc__check_object");
      }
    }
    else if (*param_3 == 0x12) {
      if (param_3[0xc] != 0xfffffff8) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("obj->depth == HWLOC_TYPE_DEPTH_MEMCACHE",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x12f0,"hwloc__check_object");
      }
    }
    else if ((int)param_3[0xc] < 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("obj->depth >= 0",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x12f2,"hwloc__check_object");
    }
  }
  else {
    if (*(long *)(param_3 + 0x2e) != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!obj->cpuset",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x12e2,"hwloc__check_object");
    }
    if (*param_3 == 0xe) {
      if (param_3[0xc] != 0xfffffffc) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("obj->depth == HWLOC_TYPE_DEPTH_BRIDGE",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x12e4,"hwloc__check_object");
      }
    }
    else if (*param_3 == 0xf) {
      if (param_3[0xc] != 0xfffffffb) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("obj->depth == HWLOC_TYPE_DEPTH_PCI_DEVICE",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x12e6,"hwloc__check_object");
      }
    }
    else if (*param_3 == 0x10) {
      if (param_3[0xc] != 0xfffffffa) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("obj->depth == HWLOC_TYPE_DEPTH_OS_DEVICE",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x12e8,"hwloc__check_object");
      }
    }
    else if ((*param_3 == 0x11) && (param_3[0xc] != 0xfffffff9)) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("obj->depth == HWLOC_TYPE_DEPTH_MISC",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x12ea,"hwloc__check_object");
    }
  }
  if ((*param_3 == 0xc) && (**(int **)(param_3 + 10) == -1)) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("obj->attr->group.depth != (unsigned) -1",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x12f7,"hwloc__check_object");
  }
  if ((*(long *)(param_3 + 0x30) != 0) == (*(long *)(param_3 + 0x2e) == 0)) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!!obj->cpuset == !!obj->complete_cpuset",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x12fb,"hwloc__check_object");
  }
  if ((*(long *)(param_3 + 0x32) != 0) == (*(long *)(param_3 + 0x2e) == 0)) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!!obj->cpuset == !!obj->nodeset",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x12fc,"hwloc__check_object");
  }
  if ((*(long *)(param_3 + 0x34) != 0) == (*(long *)(param_3 + 0x32) == 0)) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!!obj->nodeset == !!obj->complete_nodeset",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x12fd,"hwloc__check_object");
  }
  if (*(long *)(param_3 + 0x2e) != 0) {
    iVar1 = FUN_002623d5(*(undefined8 *)(param_3 + 0x2e),*(undefined8 *)(param_3 + 0x30));
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_bitmap_isincluded(obj->cpuset, obj->complete_cpuset)",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1301,"hwloc__check_object");
    }
    iVar1 = FUN_002623d5(*(undefined8 *)(param_3 + 0x32),*(undefined8 *)(param_3 + 0x34));
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_bitmap_isincluded(obj->nodeset, obj->complete_nodeset)",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1302,"hwloc__check_object");
    }
  }
  iVar1 = FUN_0024d50c(*param_3);
  if (iVar1 != 0) {
    iVar1 = FUN_0024d54e(*param_3);
    if (iVar1 == 0) {
      iVar1 = FUN_0024d52d(*param_3);
      if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("0",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x130d,"hwloc__check_object");
      }
      if ((*(int *)(*(long *)(param_3 + 10) + 0x14) != 1) &&
         (*(int *)(*(long *)(param_3 + 10) + 0x14) != 0)) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("obj->attr->cache.type == HWLOC_OBJ_CACHE_DATA || obj->attr->cache.type == HWLOC_OBJ_CACHE_UNIFIED"
                      ,
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x130b,"hwloc__check_object");
      }
    }
    else if (*(int *)(*(long *)(param_3 + 10) + 0x14) != 2) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("obj->attr->cache.type == HWLOC_OBJ_CACHE_INSTRUCTION",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1308,"hwloc__check_object");
    }
    uVar2 = FUN_0024d442(*(undefined4 *)(*(long *)(param_3 + 10) + 8),
                         *(undefined4 *)(*(long *)(param_3 + 10) + 0x14));
    if (uVar2 != *param_3) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_cache_type_by_depth_type(obj->attr->cache.depth, obj->attr->cache.type) == obj->type"
                    ,
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x130e,"hwloc__check_object");
    }
  }
  local_10 = 0;
  if (*param_3 == 0xd) {
    local_10 = **(long **)(param_3 + 10);
  }
  for (local_18 = *(long *)(param_3 + 0x1e); local_18 != 0; local_18 = *(long *)(local_18 + 0x58)) {
    local_10 = local_10 + *(long *)(local_18 + 0x20);
  }
  for (local_18 = *(long *)(param_3 + 0x24); local_18 != 0; local_18 = *(long *)(local_18 + 0x58)) {
    local_10 = local_10 + *(long *)(local_18 + 0x20);
  }
  if (local_10 != *(long *)(param_3 + 8)) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("total_memory == obj->total_memory",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x131b,"hwloc__check_object");
  }
  FUN_00255871(param_1,param_2,param_3);
  FUN_00255f7c(param_1,param_2,param_3);
  FUN_0025617d(param_1,param_2,param_3);
  FUN_00256346(param_1,param_2,param_3);
  FUN_00255b74(param_1,param_3);
  return;
}


// ===== 00256bd3 FUN_00256bd3 =====

void FUN_00256bd3(long param_1,int *param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int local_14;
  long local_10;
  
  if (*param_2 == 0xd) {
    iVar1 = FUN_00262e86(*(undefined8 *)(param_2 + 0x32));
    if (iVar1 != 1) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_bitmap_weight(obj->nodeset) == 1",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x132e,"hwloc__check_nodesets");
    }
    iVar1 = FUN_00262aab(*(undefined8 *)(param_2 + 0x32));
    if (iVar1 != param_2[4]) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_bitmap_first(obj->nodeset) == (int) obj->os_index",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x132f,"hwloc__check_nodesets");
    }
    iVar1 = FUN_00262e86(*(undefined8 *)(param_2 + 0x34));
    if (iVar1 != 1) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_bitmap_weight(obj->complete_nodeset) == 1",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1330,"hwloc__check_nodesets");
    }
    iVar1 = FUN_00262aab(*(undefined8 *)(param_2 + 0x34));
    if (iVar1 != param_2[4]) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_bitmap_first(obj->complete_nodeset) == (int) obj->os_index",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1331,"hwloc__check_nodesets");
    }
    if ((*(ulong *)(param_1 + 0x20) & 1) == 0) {
      iVar1 = FUN_0026203b(*(undefined8 *)(param_1 + 0x1c0),param_2[4]);
      if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("hwloc_bitmap_isset(topology->allowed_nodeset, (int) obj->os_index)",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x1333,"hwloc__check_nodesets");
      }
    }
    if (param_2[0x1a] != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!obj->arity",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1335,"hwloc__check_nodesets");
    }
    if (param_2[0x23] != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!obj->memory_arity",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1336,"hwloc__check_nodesets");
    }
    iVar1 = FUN_002623d5(*(undefined8 *)(param_2 + 0x32),param_3);
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_bitmap_isincluded(obj->nodeset, parentset)",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1337,"hwloc__check_nodesets");
    }
  }
  else {
    uVar2 = FUN_00260eab();
    for (local_10 = *(long *)(param_2 + 0x24); local_10 != 0; local_10 = *(long *)(local_10 + 0x58))
    {
      iVar1 = FUN_002622a3(uVar2,*(undefined8 *)(local_10 + 200));
      if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!hwloc_bitmap_intersects(myset, child->nodeset)",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x133f,"hwloc__check_nodesets");
      }
      FUN_00262517(uVar2,uVar2,*(undefined8 *)(local_10 + 200));
    }
    iVar1 = FUN_002622a3(uVar2,param_3);
    if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!hwloc_bitmap_intersects(myset, parentset)",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1343,"hwloc__check_nodesets");
    }
    FUN_00262517(param_3,param_3,uVar2);
    FUN_00260f71(uVar2);
    uVar2 = FUN_00260eab();
    for (local_10 = *(long *)(param_2 + 0x1e); local_10 != 0; local_10 = *(long *)(local_10 + 0x58))
    {
      uVar3 = FUN_002611e2(param_3);
      FUN_00256bd3(param_1,local_10,uVar3);
      FUN_00262868(uVar3,uVar3,param_3);
      iVar1 = FUN_002622a3(uVar2,uVar3);
      if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!hwloc_bitmap_intersects(childset, set)",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x1350,"hwloc__check_nodesets");
      }
      FUN_00262517(uVar2,uVar2,uVar3);
      FUN_00260f71(uVar3);
    }
    iVar1 = FUN_002622a3(param_3,uVar2);
    if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!hwloc_bitmap_intersects(parentset, childset)",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1355,"hwloc__check_nodesets");
    }
    FUN_00262517(param_3,param_3,uVar2);
    FUN_00260f71(uVar2);
    iVar1 = FUN_00262158(*(undefined8 *)(param_2 + 0x32),param_3);
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_bitmap_isequal(obj->nodeset, parentset)",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1359,"hwloc__check_nodesets");
    }
  }
  local_14 = -1;
  local_10 = *(long *)(param_2 + 0x24);
  while( true ) {
    if (local_10 == 0) {
      return;
    }
    iVar1 = FUN_00262aab(*(undefined8 *)(local_10 + 0xd0));
    if (iVar1 <= local_14) break;
    local_10 = *(long *)(local_10 + 0x58);
    local_14 = iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("prev_first < first",
                "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                ,0x1362,"hwloc__check_nodesets");
}


// ===== 00257079 FUN_00257079 =====

void FUN_00257079(undefined8 param_1,int param_2,long param_3,long param_4)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  long lVar4;
  uint local_14;
  int *local_10;
  
  uVar1 = FUN_00258070(param_1,param_2);
  local_10 = (int *)0x0;
  for (local_14 = 0; local_14 < uVar1; local_14 = local_14 + 1) {
    piVar3 = (int *)FUN_002580d2(param_1,param_2,local_14);
    if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("obj",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1374,"hwloc__check_level");
    }
    if (param_2 != piVar3[0xc]) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("obj->depth == depth",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1375,"hwloc__check_level");
    }
    if (local_14 != piVar3[0xd]) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("obj->logical_index == j",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1376,"hwloc__check_level");
    }
    if (local_10 != (int *)0x0) {
      iVar2 = FUN_0024ea2d(piVar3,local_10);
      if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("hwloc_type_cmp(obj, prev) == HWLOC_OBJ_EQUAL",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x1379,"hwloc__check_level");
      }
      if (piVar3 != *(int **)(local_10 + 0xe)) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("prev->next_cousin == obj",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x137a,"hwloc__check_level");
      }
    }
    if (local_10 != *(int **)(piVar3 + 0x10)) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("obj->prev_cousin == prev",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x137c,"hwloc__check_level");
    }
    if (*piVar3 == 0xd) {
      iVar2 = FUN_00262e86(*(undefined8 *)(piVar3 + 0x34));
      if (iVar2 != 1) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("hwloc_bitmap_weight(obj->complete_nodeset) == 1",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x1380,"hwloc__check_level");
      }
      iVar2 = FUN_00262aab(*(undefined8 *)(piVar3 + 0x34));
      if (iVar2 != piVar3[4]) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("hwloc_bitmap_first(obj->complete_nodeset) == (int) obj->os_index",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x1381,"hwloc__check_level");
      }
    }
    local_10 = piVar3;
  }
  if ((local_10 != (int *)0x0) && (*(long *)(local_10 + 0xe) != 0)) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("prev->next_cousin == ((void *)0)",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x1386,"hwloc__check_level");
  }
  if (uVar1 != 0) {
    piVar3 = (int *)FUN_002580d2(param_1,param_2,0);
    if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("obj",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x138b,"hwloc__check_level");
    }
    if (*(long *)(piVar3 + 0x10) != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!obj->prev_cousin",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x138c,"hwloc__check_level");
    }
    iVar2 = FUN_00257fd9(param_1,param_2);
    if (iVar2 != *piVar3) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_get_depth_type(topology, depth) == obj->type",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x138e,"hwloc__check_level");
    }
    iVar2 = FUN_00257fb0(param_1,*piVar3);
    if (param_2 != iVar2) {
      iVar2 = FUN_00257fb0(param_1,*piVar3);
      if (iVar2 != -2) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("depth == hwloc_get_type_depth(topology, obj->type) || HWLOC_TYPE_DEPTH_MULTIPLE == hwloc_get_type_depth(topology, obj->type)"
                      ,
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x1390,"hwloc__check_level");
      }
    }
    lVar4 = FUN_002580d2(param_1,param_2,uVar1 - 1);
    if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("obj",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1393,"hwloc__check_level");
    }
    if (*(long *)(lVar4 + 0x38) != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!obj->next_cousin",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1394,"hwloc__check_level");
    }
  }
  if (param_2 < 0) {
    lVar4 = FUN_002580d2(param_1,param_2,0);
    if (param_3 != lVar4) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("first == hwloc_get_obj_by_depth(topology, depth, 0)",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1398,"hwloc__check_level");
    }
    lVar4 = FUN_002580d2(param_1,param_2,uVar1 - 1);
    if (param_4 != lVar4) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("last == hwloc_get_obj_by_depth(topology, depth, width-1)",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1399,"hwloc__check_level");
    }
  }
  else {
    if (param_3 != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!first",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x139b,"hwloc__check_level");
    }
    if (param_4 != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!last",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x139c,"hwloc__check_level");
    }
  }
  lVar4 = FUN_002580d2(param_1,param_2,uVar1);
  if (lVar4 != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!obj",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x13a1,"hwloc__check_level");
  }
  return;
}


// ===== 00257529 FUN_00257529 =====

void FUN_00257529(long param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  long lVar5;
  undefined8 uVar6;
  int local_14;
  uint local_10;
  uint local_c;
  
  if (*(int *)(param_1 + 0xa8) == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("topology->type_filter[HWLOC_OBJ_GROUP] != HWLOC_TYPE_FILTER_KEEP_ALL",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x13cb,"hwloc_topology_check");
  }
  for (local_c = 0; local_c < 0x14; local_c = local_c + 1) {
    if (local_c !=
        *(uint *)(&DAT_002eb4a0 + (ulong)*(uint *)(&DAT_002eb440 + (ulong)local_c * 4) * 4)) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("obj_order_type[obj_type_order[type]] == type",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x13cf,"hwloc_topology_check");
    }
  }
  for (local_10 = 0; local_10 < 0x14; local_10 = local_10 + 1) {
    if (local_10 !=
        *(uint *)(&DAT_002eb440 + (ulong)*(uint *)(&DAT_002eb4a0 + (ulong)local_10 * 4) * 4)) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("obj_type_order[obj_order_type[i]] == i",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x13d1,"hwloc_topology_check");
    }
  }
  iVar1 = FUN_00255600(param_1);
  if (*(int *)(param_1 + 0xd0) != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!topology->modified",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x13d5,"hwloc_topology_check");
  }
  iVar2 = FUN_00257fd9(param_1,0);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("hwloc_get_depth_type(topology, 0) == HWLOC_OBJ_MACHINE",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x13db,"hwloc_topology_check");
  }
  iVar2 = FUN_00257fd9(param_1,iVar1 + -1);
  if (iVar2 != 3) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("hwloc_get_depth_type(topology, depth-1) == HWLOC_OBJ_PU",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x13de,"hwloc_topology_check");
  }
  iVar2 = FUN_00258070(param_1,iVar1 + -1);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("hwloc_get_nbobjs_by_depth(topology, depth-1) > 0",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x13df,"hwloc_topology_check");
  }
  local_10 = 0;
  while( true ) {
    uVar3 = FUN_00258070(param_1,iVar1 + -1);
    if (uVar3 <= local_10) break;
    piVar4 = (int *)FUN_002580d2(param_1,iVar1 + -1,local_10);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("obj",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x13e2,"hwloc_topology_check");
    }
    if (*piVar4 != 3) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("obj->type == HWLOC_OBJ_PU",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x13e3,"hwloc_topology_check");
    }
    if (*(long *)(piVar4 + 0x24) != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!obj->memory_first_child",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x13e4,"hwloc_topology_check");
    }
    local_10 = local_10 + 1;
  }
  for (local_14 = 1; local_14 < iVar1 + -1; local_14 = local_14 + 1) {
    iVar2 = FUN_00257fd9(param_1,local_14);
    if (iVar2 == 3) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_get_depth_type(topology, j) != HWLOC_OBJ_PU",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x13e8,"hwloc_topology_check");
    }
    iVar2 = FUN_00257fd9(param_1,local_14);
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_get_depth_type(topology, j) != HWLOC_OBJ_MACHINE",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x13e9,"hwloc_topology_check");
    }
  }
  for (local_14 = 0; local_14 < iVar1; local_14 = local_14 + 1) {
    iVar2 = FUN_00257fd9(param_1,local_14);
    if (iVar2 == 0xd) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("type != HWLOC_OBJ_NUMANODE",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x13f0,"hwloc_topology_check");
    }
    if (iVar2 == 0x12) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("type != HWLOC_OBJ_MEMCACHE",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x13f1,"hwloc_topology_check");
    }
    if (iVar2 == 0xf) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("type != HWLOC_OBJ_PCI_DEVICE",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x13f2,"hwloc_topology_check");
    }
    if (iVar2 == 0xe) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("type != HWLOC_OBJ_BRIDGE",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x13f3,"hwloc_topology_check");
    }
    if (iVar2 == 0x10) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("type != HWLOC_OBJ_OS_DEVICE",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x13f4,"hwloc_topology_check");
    }
    if (iVar2 == 0x11) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("type != HWLOC_OBJ_MISC",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x13f5,"hwloc_topology_check");
    }
    iVar2 = FUN_00257fb0(param_1,iVar2);
    if ((iVar2 != local_14) && (iVar2 != -2)) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("d == j || d == HWLOC_TYPE_DEPTH_MULTIPLE",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x13f7,"hwloc_topology_check");
    }
  }
  for (local_c = 0; local_c < 0x14; local_c = local_c + 1) {
    iVar2 = FUN_00257fb0(param_1,local_c);
    if (local_c == 0xd) {
      if (iVar2 != -3) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("d == HWLOC_TYPE_DEPTH_NUMANODE",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x13ff,"hwloc_topology_check");
      }
      iVar2 = FUN_00257fd9(param_1,0xfffffffd);
      if (iVar2 != 0xd) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("hwloc_get_depth_type(topology, d) == HWLOC_OBJ_NUMANODE",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x1400,"hwloc_topology_check");
      }
    }
    else if (local_c == 0x12) {
      if (iVar2 != -8) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("d == HWLOC_TYPE_DEPTH_MEMCACHE",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x1402,"hwloc_topology_check");
      }
      iVar2 = FUN_00257fd9(param_1,0xfffffff8);
      if (iVar2 != 0x12) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("hwloc_get_depth_type(topology, d) == HWLOC_OBJ_MEMCACHE",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x1403,"hwloc_topology_check");
      }
    }
    else if (local_c == 0xe) {
      if (iVar2 != -4) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("d == HWLOC_TYPE_DEPTH_BRIDGE",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x1405,"hwloc_topology_check");
      }
      iVar2 = FUN_00257fd9(param_1,0xfffffffc);
      if (iVar2 != 0xe) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("hwloc_get_depth_type(topology, d) == HWLOC_OBJ_BRIDGE",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x1406,"hwloc_topology_check");
      }
    }
    else if (local_c == 0xf) {
      if (iVar2 != -5) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("d == HWLOC_TYPE_DEPTH_PCI_DEVICE",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x1408,"hwloc_topology_check");
      }
      iVar2 = FUN_00257fd9(param_1,0xfffffffb);
      if (iVar2 != 0xf) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("hwloc_get_depth_type(topology, d) == HWLOC_OBJ_PCI_DEVICE",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x1409,"hwloc_topology_check");
      }
    }
    else if (local_c == 0x10) {
      if (iVar2 != -6) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("d == HWLOC_TYPE_DEPTH_OS_DEVICE",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x140b,"hwloc_topology_check");
      }
      iVar2 = FUN_00257fd9(param_1,0xfffffffa);
      if (iVar2 != 0x10) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("hwloc_get_depth_type(topology, d) == HWLOC_OBJ_OS_DEVICE",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x140c,"hwloc_topology_check");
      }
    }
    else if (local_c == 0x11) {
      if (iVar2 != -7) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("d == HWLOC_TYPE_DEPTH_MISC",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x140e,"hwloc_topology_check");
      }
      iVar2 = FUN_00257fd9(param_1,0xfffffff9);
      if (iVar2 != 0x11) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("hwloc_get_depth_type(topology, d) == HWLOC_OBJ_MISC",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                      ,0x140f,"hwloc_topology_check");
      }
    }
    else if (((iVar2 < 0) && (iVar2 != -1)) && (iVar2 != -2)) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("d >=0 || d == HWLOC_TYPE_DEPTH_UNKNOWN || d == HWLOC_TYPE_DEPTH_MULTIPLE",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1411,"hwloc_topology_check");
    }
  }
  iVar2 = FUN_00258070(param_1,0);
  if (iVar2 != 1) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("hwloc_get_nbobjs_by_depth(topology, 0) == 1",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x1416,"hwloc_topology_check");
  }
  lVar5 = FUN_0024d2be(param_1);
  if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("obj",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x1418,"hwloc_topology_check");
  }
  if (*(long *)(lVar5 + 0x48) != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!obj->parent",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x1419,"hwloc_topology_check");
  }
  if (*(long *)(lVar5 + 0xb8) == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("obj->cpuset",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x141a,"hwloc_topology_check");
  }
  if (*(int *)(lVar5 + 0x30) != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!obj->depth",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                  ,0x141b,"hwloc_topology_check");
  }
  if ((*(ulong *)(param_1 + 0x20) & 1) == 0) {
    iVar2 = FUN_00262158(*(undefined8 *)(param_1 + 0x1b8),*(undefined8 *)(lVar5 + 0xb8));
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_bitmap_isequal(topology->allowed_cpuset, obj->cpuset)",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1422,"hwloc_topology_check");
    }
    iVar2 = FUN_00262158(*(undefined8 *)(param_1 + 0x1c0),*(undefined8 *)(lVar5 + 200));
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_bitmap_isequal(topology->allowed_nodeset, obj->nodeset)",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1423,"hwloc_topology_check");
    }
  }
  else {
    iVar2 = FUN_002623d5(*(undefined8 *)(param_1 + 0x1b8),*(undefined8 *)(lVar5 + 0xb8));
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_bitmap_isincluded(topology->allowed_cpuset, obj->cpuset)",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x141f,"hwloc_topology_check");
    }
    iVar2 = FUN_002623d5(*(undefined8 *)(param_1 + 0x1c0),*(undefined8 *)(lVar5 + 200));
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("hwloc_bitmap_isincluded(topology->allowed_nodeset, obj->nodeset)",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/topology.c"
                    ,0x1420,"hwloc_topology_check");
    }
  }
  for (local_14 = 0; local_14 < iVar1; local_14 = local_14 + 1) {
    FUN_00257079(param_1,local_14,0,0);
  }
  for (local_14 = 0; local_14 < 6; local_14 = local_14 + 1) {
    FUN_00257079(param_1,-3 - local_14,*(undefined8 *)(param_1 + ((long)local_14 + 8) * 0x20 + 8),
                 *(undefined8 *)(param_1 + ((long)local_14 + 8) * 0x20 + 0x10));
  }
  uVar6 = FUN_00260eab();
  FUN_00256538(param_1,uVar6,lVar5);
  FUN_00260f71(uVar6);
  uVar6 = FUN_00260eab();
  FUN_00256bd3(param_1,lVar5,uVar6);
  FUN_00260f71(uVar6);
  return;
}


// ===== 00257f4d FUN_00257f4d =====

undefined8 FUN_00257f4d(uint param_1)

{
  undefined8 uVar1;
  
  if ((param_1 < 0xd) || (param_1 == 0x13)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00257f6e FUN_00257f6e =====

undefined8 FUN_00257f6e(int param_1)

{
  undefined8 uVar1;
  
  if ((param_1 == 0xd) || (param_1 == 0x12)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00257f8f FUN_00257f8f =====

undefined8 FUN_00257f8f(uint param_1)

{
  undefined8 uVar1;
  
  if ((param_1 < 4) || (0xb < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== 00257fb0 FUN_00257fb0 =====

undefined4 FUN_00257fb0(long param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0x14) {
    uVar1 = *(undefined4 *)(param_1 + 8 + ((ulong)param_2 + 8) * 4);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ===== 00257fd9 FUN_00257fd9 =====

undefined4 FUN_00257fd9(long param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < *(uint *)(param_1 + 4)) {
    uVar1 = *(undefined4 *)**(undefined8 **)(*(long *)(param_1 + 0x18) + (long)(int)param_2 * 8);
  }
  else {
    switch(param_2) {
    case 0xfffffff8:
      uVar1 = 0x12;
      break;
    case 0xfffffff9:
      uVar1 = 0x11;
      break;
    case 0xfffffffa:
      uVar1 = 0x10;
      break;
    case 0xfffffffb:
      uVar1 = 0xf;
      break;
    case 0xfffffffc:
      uVar1 = 0xe;
      break;
    case 0xfffffffd:
      uVar1 = 0xd;
      break;
    default:
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}


// ===== 00258070 FUN_00258070 =====

undefined4 FUN_00258070(long param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < *(uint *)(param_1 + 4)) {
    uVar1 = *(undefined4 *)(*(long *)(param_1 + 0x10) + (long)(int)param_2 * 4);
  }
  else if (-param_2 - 3 < 6) {
    uVar1 = *(undefined4 *)(param_1 + (ulong)(-param_2 - 3) * 0x20 + 0xf8);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 002580d2 FUN_002580d2 =====

undefined8 FUN_002580d2(long param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (param_2 < *(uint *)(param_1 + 4)) {
    if (param_3 < *(uint *)(*(long *)(param_1 + 0x10) + (long)(int)param_2 * 4)) {
      uVar2 = *(undefined8 *)
               (*(long *)(*(long *)(param_1 + 0x18) + (long)(int)param_2 * 8) + (ulong)param_3 * 8);
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar1 = -param_2 - 3;
    if (uVar1 < 6) {
      if (param_3 < *(uint *)(param_1 + (ulong)uVar1 * 0x20 + 0xf8)) {
        uVar2 = *(undefined8 *)
                 (*(long *)(param_1 + (ulong)uVar1 * 0x20 + 0x100) + (ulong)param_3 * 8);
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


// ===== 00258198 FUN_00258198 =====

void FUN_00258198(undefined4 param_1)

{
  FUN_00257f4d(param_1);
  return;
}


// ===== 002581af FUN_002581af =====

void FUN_002581af(undefined4 param_1)

{
  FUN_00257f6e(param_1);
  return;
}


// ===== 002581c6 FUN_002581c6 =====

long FUN_002581c6(undefined8 param_1,undefined4 param_2,long param_3)

{
  long local_10;
  
  local_10 = FUN_002580d2(param_1,param_2,0);
  while( true ) {
    if (local_10 == 0) {
      return 0;
    }
    if (param_3 == *(long *)(local_10 + 0xf0)) break;
    local_10 = *(long *)(local_10 + 0x38);
  }
  return local_10;
}


// ===== 00258226 FUN_00258226 =====

long FUN_00258226(long param_1,int param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  uint local_c;
  
  iVar1 = FUN_00257fb0(param_1,param_2);
  if (iVar1 == -1) {
    lVar2 = 0;
  }
  else if (iVar1 == -2) {
    for (local_c = 1; local_c < *(int *)(param_1 + 4) - 1U; local_c = local_c + 1) {
      iVar1 = FUN_00257fd9(param_1,local_c);
      if ((param_2 == iVar1) && (lVar2 = FUN_002581c6(param_1,local_c,param_3), lVar2 != 0)) {
        return lVar2;
      }
    }
    lVar2 = 0;
  }
  else {
    lVar2 = FUN_002581c6(param_1,iVar1,param_3);
  }
  return lVar2;
}


// ===== 002582d8 FUN_002582d8 =====

char * FUN_002582d8(undefined4 param_1)

{
  char *pcVar1;
  
  switch(param_1) {
  case 0:
    pcVar1 = "Machine";
    break;
  case 1:
    pcVar1 = "Package";
    break;
  case 2:
    pcVar1 = "Core";
    break;
  case 3:
    pcVar1 = "PU";
    break;
  case 4:
    pcVar1 = "L1Cache";
    break;
  case 5:
    pcVar1 = "L2Cache";
    break;
  case 6:
    pcVar1 = "L3Cache";
    break;
  case 7:
    pcVar1 = "L4Cache";
    break;
  case 8:
    pcVar1 = "L5Cache";
    break;
  case 9:
    pcVar1 = "L1iCache";
    break;
  case 10:
    pcVar1 = "L2iCache";
    break;
  case 0xb:
    pcVar1 = "L3iCache";
    break;
  case 0xc:
    pcVar1 = "Group";
    break;
  case 0xd:
    pcVar1 = "NUMANode";
    break;
  case 0xe:
    pcVar1 = "Bridge";
    break;
  case 0xf:
    pcVar1 = "PCIDev";
    break;
  case 0x10:
    pcVar1 = "OSDev";
    break;
  case 0x11:
    pcVar1 = "Misc";
    break;
  case 0x12:
    pcVar1 = "MemCache";
    break;
  case 0x13:
    pcVar1 = "Die";
    break;
  default:
    pcVar1 = "Unknown";
  }
  return pcVar1;
}


// ===== 002583dc FUN_002583dc =====

char * FUN_002583dc(char *param_1,char *param_2,ulong param_3)

{
  uint local_1c;
  char *local_18;
  char *local_10;
  
  local_1c = 0;
  local_18 = param_2;
  local_10 = param_1;
  while( true ) {
    if (*local_10 == '\0') {
      if (local_1c < param_3) {
        local_10 = (char *)0x0;
      }
      return local_10;
    }
    if ((*local_10 != *local_18) && ((int)*local_10 != *local_18 + -0x20)) break;
    local_1c = local_1c + 1;
    local_10 = local_10 + 1;
    local_18 = local_18 + 1;
  }
  if (((*local_10 < 'a') || ('z' < *local_10)) &&
     (((*local_10 < 'A' || ('Z' < *local_10)) && (*local_10 != '-')))) {
    if (param_3 <= local_1c) {
      return local_10;
    }
    return (char *)0x0;
  }
  return (char *)0x0;
}


// ===== 002584c0 FUN_002584c0 =====

undefined8 FUN_002584c0(char *param_1,int *param_2,uint *param_3,ulong param_4)

{
  int iVar1;
  long lVar2;
  char *local_30;
  char *local_28;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  int local_c;
  
  local_c = 0xffffffff;
  local_10 = 0xffffffff;
  local_14 = 0xffffffff;
  local_18 = 0xffffffff;
  local_1c = 0xffffffff;
  lVar2 = FUN_002583dc(param_1,"osdev",2);
  if (lVar2 != 0) {
    local_c = 0x10;
    goto LAB_00258a77;
  }
  lVar2 = FUN_002583dc(param_1,"block",4);
  if (lVar2 != 0) {
    local_c = 0x10;
    local_1c = 0;
    goto LAB_00258a77;
  }
  lVar2 = FUN_002583dc(param_1,"network",3);
  if (lVar2 != 0) {
    local_c = 0x10;
    local_1c = 2;
    goto LAB_00258a77;
  }
  lVar2 = FUN_002583dc(param_1,"openfabrics",7);
  if (lVar2 != 0) {
    local_c = 0x10;
    local_1c = 3;
    goto LAB_00258a77;
  }
  lVar2 = FUN_002583dc(param_1,&DAT_002eba2d,3);
  if (lVar2 != 0) {
    local_c = 0x10;
    local_1c = 4;
    goto LAB_00258a77;
  }
  lVar2 = FUN_002583dc(param_1,&DAT_002eba31,3);
  if (lVar2 != 0) {
    local_c = 0x10;
    local_1c = 1;
    goto LAB_00258a77;
  }
  lVar2 = FUN_002583dc(param_1,"coproc",5);
  if ((lVar2 != 0) || (lVar2 = FUN_002583dc(param_1,"co-processor",6), lVar2 != 0)) {
    local_c = 0x10;
    local_1c = 5;
    goto LAB_00258a77;
  }
  lVar2 = FUN_002583dc(param_1,"machine",2);
  if (lVar2 != 0) {
    local_c = 0;
    goto LAB_00258a77;
  }
  lVar2 = FUN_002583dc(param_1,"numanode",2);
  if ((lVar2 != 0) || (lVar2 = FUN_002583dc(param_1,&DAT_002eba5a,2), lVar2 != 0)) {
    local_c = 0xd;
    goto LAB_00258a77;
  }
  lVar2 = FUN_002583dc(param_1,"memcache",5);
  if ((lVar2 != 0) || (lVar2 = FUN_002583dc(param_1,"memory-side cache",8), lVar2 != 0)) {
    local_c = 0x12;
    goto LAB_00258a77;
  }
  lVar2 = FUN_002583dc(param_1,"package",2);
  if ((lVar2 != 0) || (lVar2 = FUN_002583dc(param_1,"socket",2), lVar2 != 0)) {
    local_c = 1;
    goto LAB_00258a77;
  }
  lVar2 = FUN_002583dc(param_1,&DAT_002eba89,2);
  if (lVar2 != 0) {
    local_c = 0x13;
    goto LAB_00258a77;
  }
  lVar2 = FUN_002583dc(param_1,&DAT_002eba8d,2);
  if (lVar2 != 0) {
    local_c = 2;
    goto LAB_00258a77;
  }
  lVar2 = FUN_002583dc(param_1,&DAT_002eba92,2);
  if (lVar2 != 0) {
    local_c = 3;
    goto LAB_00258a77;
  }
  lVar2 = FUN_002583dc(param_1,&DAT_002eba95,4);
  if (lVar2 != 0) {
    local_c = 0x11;
    goto LAB_00258a77;
  }
  lVar2 = FUN_002583dc(param_1,"bridge",4);
  if (lVar2 != 0) {
    local_c = 0xe;
    goto LAB_00258a77;
  }
  lVar2 = FUN_002583dc(param_1,"hostbridge",6);
  if (lVar2 != 0) {
    local_c = 0xe;
    local_18 = 0;
    goto LAB_00258a77;
  }
  lVar2 = FUN_002583dc(param_1,"pcibridge",5);
  if (lVar2 != 0) {
    local_c = 0xe;
    local_18 = 1;
    goto LAB_00258a77;
  }
  lVar2 = FUN_002583dc(param_1,"pcidev",3);
  if (lVar2 != 0) {
    local_c = 0xf;
    goto LAB_00258a77;
  }
  if ((((*param_1 != 'l') && (*param_1 != 'L')) || (param_1[1] < '0')) || ('9' < param_1[1])) {
    local_30 = (char *)FUN_002583dc(param_1,"group",2);
    if (local_30 == (char *)0x0) {
      return 0xffffffff;
    }
    local_c = 0xc;
    if (('/' < *local_30) && (*local_30 < ':')) {
      lVar2 = strtol(local_30,&local_30,10);
      local_10 = (uint)lVar2;
    }
    goto LAB_00258a77;
  }
  lVar2 = strtol(param_1 + 1,&local_30,10);
  local_10 = (uint)lVar2;
  if ((*local_30 == 'i') || (*local_30 == 'I')) {
    if ((local_10 == 0) || (3 < local_10)) {
      return 0xffffffff;
    }
    local_c = local_10 + 8;
    local_14 = 2;
    local_28 = local_30 + 1;
  }
  else {
    if ((local_10 == 0) || (5 < local_10)) {
      return 0xffffffff;
    }
    local_c = local_10 + 3;
    if ((*local_30 == 'd') || (*local_30 == 'D')) {
      local_14 = 1;
    }
    else {
      if ((*local_30 != 'u') && (*local_30 != 'U')) {
        local_14 = 0;
        local_28 = local_30;
        goto LAB_002589e6;
      }
      local_14 = 0;
    }
    local_28 = local_30 + 1;
  }
LAB_002589e6:
  lVar2 = FUN_002583dc(local_28,"cache",0);
  if (lVar2 == 0) {
    return 0xffffffff;
  }
LAB_00258a77:
  *param_2 = local_c;
  if (param_3 != (uint *)0x0) {
    iVar1 = FUN_00257f8f(local_c);
    if ((iVar1 == 0) || (param_4 < 0x18)) {
      if ((local_c == 0xc) && (0xf < param_4)) {
        *param_3 = local_10;
      }
      else if ((local_c == 0xe) && (0x27 < param_4)) {
        param_3[6] = local_18;
        param_3[8] = 1;
      }
      else if ((local_c == 0x10) && (3 < param_4)) {
        *param_3 = local_1c;
      }
    }
    else {
      param_3[2] = local_10;
      param_3[5] = local_14;
    }
  }
  return 0;
}


// ===== 00258b0b FUN_00258b0b =====

char * FUN_00258b0b(int param_1)

{
  char *pcVar1;
  
  if (param_1 == 1) {
    pcVar1 = "d";
  }
  else if (param_1 == 0) {
    pcVar1 = "";
  }
  else if (param_1 == 2) {
    pcVar1 = "i";
  }
  else {
    pcVar1 = "unknown";
  }
  return pcVar1;
}


// ===== 00258b4a FUN_00258b4a =====

undefined8 FUN_00258b4a(undefined1 *param_1,long param_2,undefined4 *param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined8 uVar4;
  
  uVar1 = *param_3;
  switch(uVar1) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 0xd:
  case 0x11:
  case 0x12:
  case 0x13:
    uVar4 = FUN_002582d8(uVar1);
    uVar4 = FUN_002654ee(param_1,param_2,&DAT_002ebad6,uVar4);
    break;
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
    if (param_4 == 0) {
      pcVar3 = "";
    }
    else {
      pcVar3 = "Cache";
    }
    uVar4 = FUN_00258b0b(*(undefined4 *)(*(long *)(param_3 + 10) + 0x14));
    uVar4 = FUN_002654ee(param_1,param_2,"L%u%s%s",*(undefined4 *)(*(long *)(param_3 + 10) + 8),
                         uVar4,pcVar3);
    break;
  case 0xc:
    if (**(int **)(param_3 + 10) == -1) {
      uVar4 = FUN_002582d8(uVar1);
      uVar4 = FUN_002654ee(param_1,param_2,&DAT_002ebad6,uVar4);
    }
    else {
      uVar2 = **(undefined4 **)(param_3 + 10);
      uVar4 = FUN_002582d8(uVar1);
      uVar4 = FUN_002654ee(param_1,param_2,&DAT_002ebae7,uVar4,uVar2);
    }
    break;
  case 0xe:
    if (*(int *)(*(long *)(param_3 + 10) + 0x20) != 1) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("obj->attr->bridge.downstream_type == HWLOC_OBJ_BRIDGE_PCI",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/traversal.c"
                    ,0x21c,"hwloc_obj_type_snprintf");
    }
    if (*(int *)(*(long *)(param_3 + 10) + 0x18) == 1) {
      pcVar3 = "PCIBridge";
    }
    else {
      pcVar3 = "HostBridge";
    }
    uVar4 = FUN_002654ee(param_1,param_2,pcVar3);
    break;
  case 0xf:
    uVar4 = FUN_002654ee(param_1,param_2,&DAT_002ebb3f);
    break;
  case 0x10:
    switch(**(undefined4 **)(param_3 + 10)) {
    case 0:
      uVar4 = FUN_002654ee(param_1,param_2,"Block");
      break;
    case 1:
      uVar4 = FUN_002654ee(param_1,param_2,&DAT_002ebb65);
      break;
    case 2:
      if (param_4 == 0) {
        pcVar3 = "Net";
      }
      else {
        pcVar3 = "Network";
      }
      uVar4 = FUN_002654ee(param_1,param_2,pcVar3);
      break;
    case 3:
      uVar4 = FUN_002654ee(param_1,param_2,"OpenFabrics");
      break;
    case 4:
      uVar4 = FUN_002654ee(param_1,param_2,&DAT_002ebb61);
      break;
    case 5:
      if (param_4 == 0) {
        pcVar3 = "CoProc";
      }
      else {
        pcVar3 = "Co-Processor";
      }
      uVar4 = FUN_002654ee(param_1,param_2,pcVar3);
      break;
    default:
      if (param_2 != 0) {
        *param_1 = 0;
      }
      uVar4 = 0;
    }
    break;
  default:
    if (param_2 != 0) {
      *param_1 = 0;
    }
    uVar4 = 0;
  }
  return uVar4;
}


// ===== 00258e89 FUN_00258e89 =====

long FUN_00258e89(undefined8 param_1,int param_2)

{
  long local_10;
  
  local_10 = 0;
  do {
    local_10 = FUN_00258f7c(param_1,3,local_10);
    if (local_10 == 0) {
      return 0;
    }
  } while (param_2 != *(int *)(local_10 + 0x10));
  return local_10;
}


// ===== 00258edb FUN_00258edb =====

long FUN_00258edb(undefined8 param_1,int param_2)

{
  long local_10;
  
  local_10 = 0;
  do {
    local_10 = FUN_00258f7c(param_1,0xd,local_10);
    if (local_10 == 0) {
      return 0;
    }
  } while (param_2 != *(int *)(local_10 + 0x10));
  return local_10;
}


// ===== 00258f2d FUN_00258f2d =====

undefined8 FUN_00258f2d(undefined8 param_1,int param_2,long param_3)

{
  undefined8 uVar1;
  
  if (param_3 == 0) {
    uVar1 = FUN_002580d2(param_1,param_2,0);
  }
  else if (param_2 == *(int *)(param_3 + 0x30)) {
    uVar1 = *(undefined8 *)(param_3 + 0x38);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00258f7c FUN_00258f7c =====

undefined8 FUN_00258f7c(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_00257fb0(param_1,param_2);
  if ((iVar1 == -1) || (iVar1 == -2)) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00258f2d(param_1,iVar1,param_3);
  }
  return uVar2;
}


// ===== 00258fcd FUN_00258fcd =====

void FUN_00258fcd(void)

{
  return;
}


// ===== 00259026 FUN_00259026 =====

void FUN_00259026(long param_1)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  bool bVar4;
  char *__s;
  ulong uVar5;
  uint local_10;
  uint local_c;
  
  uVar1 = *(uint *)(param_1 + 0x18);
  lVar2 = *(long *)(param_1 + 0x40);
  lVar3 = *(long *)(param_1 + 0x28);
  if ((*(int *)(param_1 + 0xc) == 3) || (*(int *)(param_1 + 0xc) == 0xd)) {
    bVar4 = false;
  }
  else {
    bVar4 = true;
  }
  if (bVar4) {
    __s = "gp_index";
  }
  else {
    __s = "os_index";
  }
  fputs(__s,*(FILE **)PTR_stderr_0032efe0);
  for (local_10 = 0; local_10 < uVar1; local_10 = local_10 + 1) {
    if (bVar4) {
      uVar5 = *(ulong *)(*(long *)(lVar2 + (ulong)local_10 * 8) + 0xf0) & 0xffffffff;
    }
    else {
      uVar5 = (ulong)*(uint *)(*(long *)(lVar2 + (ulong)local_10 * 8) + 0x10);
    }
    fprintf(*(FILE **)PTR_stderr_0032efe0," % 5d",uVar5);
  }
  fputc(10,*(FILE **)PTR_stderr_0032efe0);
  for (local_c = 0; local_c < uVar1; local_c = local_c + 1) {
    if (bVar4) {
      uVar5 = *(ulong *)(*(long *)(lVar2 + (ulong)local_c * 8) + 0xf0) & 0xffffffff;
    }
    else {
      uVar5 = (ulong)*(uint *)(*(long *)(lVar2 + (ulong)local_c * 8) + 0x10);
    }
    fprintf(*(FILE **)PTR_stderr_0032efe0,"  % 5d",uVar5);
    for (local_10 = 0; local_10 < uVar1; local_10 = local_10 + 1) {
      fprintf(*(FILE **)PTR_stderr_0032efe0," % 5lld",
              *(undefined8 *)(lVar3 + (ulong)(local_10 + local_c * uVar1) * 8));
    }
    fputc(10,*(FILE **)PTR_stderr_0032efe0);
  }
  return;
}


// ===== 0025921c FUN_0025921c =====

void FUN_0025921c(long param_1)

{
  *(undefined8 *)(param_1 + 0x2c8) = 0;
  *(undefined8 *)(param_1 + 0x2c0) = *(undefined8 *)(param_1 + 0x2c8);
  *(undefined4 *)(param_1 + 0x2d0) = 0;
  return;
}


// ===== 0025925a FUN_0025925a =====

void FUN_0025925a(long param_1)

{
  int iVar1;
  char *pcVar2;
  double dVar3;
  
  *(undefined4 *)(param_1 + 0x2f0) = 1;
  if (*(int *)(param_1 + 0xa8) == 1) {
    *(undefined4 *)(param_1 + 0x2f0) = 0;
  }
  pcVar2 = getenv("HWLOC_GROUPING");
  if (pcVar2 != (char *)0x0) {
    iVar1 = atoi(pcVar2);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x2f0) = 0;
    }
  }
  if (*(int *)(param_1 + 0x2f0) != 0) {
    *(undefined4 *)(param_1 + 0x310) = 0;
    *(undefined4 *)(param_1 + 0x2fc) = 0;
    *(undefined4 *)(param_1 + 0x300) = DAT_002ec0dc;
    *(undefined4 *)(param_1 + 0x304) = DAT_002ec0e0;
    *(undefined4 *)(param_1 + 0x308) = DAT_002ec0e4;
    *(undefined4 *)(param_1 + 0x30c) = DAT_002ec0e8;
    *(undefined4 *)(param_1 + 0x2f8) = 5;
    pcVar2 = getenv("HWLOC_GROUPING_ACCURACY");
    if (pcVar2 == (char *)0x0) {
      *(undefined4 *)(param_1 + 0x2f8) = 1;
    }
    else {
      iVar1 = strcmp(pcVar2,"try");
      if (iVar1 != 0) {
        *(undefined4 *)(param_1 + 0x2f8) = 1;
        dVar3 = atof(pcVar2);
        *(float *)(param_1 + 0x2fc) = (float)dVar3;
      }
    }
    *(undefined4 *)(param_1 + 0x2f4) = 0;
    pcVar2 = getenv("HWLOC_GROUPING_VERBOSE");
    if (pcVar2 != (char *)0x0) {
      iVar1 = atoi(pcVar2);
      *(int *)(param_1 + 0x2f4) = iVar1;
    }
  }
  return;
}


// ===== 002593fc FUN_002593fc =====

void FUN_002593fc(undefined8 *param_1)

{
  free((void *)*param_1);
  free((void *)param_1[2]);
  free((void *)param_1[4]);
  free((void *)param_1[8]);
  free((void *)param_1[5]);
  free(param_1);
  return;
}


// ===== 00259466 FUN_00259466 =====

void FUN_00259466(long param_1)

{
  long lVar1;
  undefined8 local_10;
  
  local_10 = *(long *)(param_1 + 0x2c0);
  while (local_10 != 0) {
    lVar1 = *(long *)(local_10 + 0x50);
    FUN_002593fc(local_10);
    local_10 = lVar1;
  }
  *(undefined8 *)(param_1 + 0x2c8) = 0;
  *(undefined8 *)(param_1 + 0x2c0) = *(undefined8 *)(param_1 + 0x2c8);
  return;
}


// ===== 002594d2 FUN_002594d2 =====

void FUN_002594d2(undefined8 *param_1)

{
  free((void *)*param_1);
  free((void *)param_1[4]);
  free((void *)param_1[8]);
  free((void *)param_1[2]);
  free((void *)param_1[5]);
  free(param_1);
  return;
}


// ===== 0025953c FUN_0025953c =====

long * FUN_0025953c(long param_1,char *param_2,long param_3,long param_4)

{
  int iVar1;
  int *piVar2;
  long *plVar3;
  char *pcVar4;
  
  if (param_4 == 0) {
    plVar3 = calloc(1,0x58);
    if (plVar3 != (long *)0x0) {
      if (param_2 != (char *)0x0) {
        pcVar4 = strdup(param_2);
        *plVar3 = (long)pcVar4;
        if (*plVar3 == 0) {
          FUN_002594d2(plVar3);
          return (long *)0x0;
        }
      }
      plVar3[6] = param_3;
      *(undefined4 *)(plVar3 + 7) = 2;
      *(undefined4 *)((long)plVar3 + 0xc) = 0xffffffff;
      plVar3[2] = 0;
      *(undefined4 *)(plVar3 + 3) = 0;
      plVar3[4] = 0;
      plVar3[8] = 0;
      plVar3[5] = 0;
      iVar1 = *(int *)(param_1 + 0x2d0);
      *(int *)(param_1 + 0x2d0) = iVar1 + 1;
      *(int *)(plVar3 + 1) = iVar1;
      return plVar3;
    }
  }
  else {
    piVar2 = __errno_location();
    *piVar2 = 0x16;
  }
  return (long *)0x0;
}


// ===== 0025964e FUN_0025964e =====

undefined8
FUN_0025964e(undefined8 param_1,long param_2,uint param_3,undefined8 *param_4,long param_5,
            long param_6)

{
  int *piVar1;
  void *__ptr;
  uint local_4c;
  uint local_20;
  uint local_1c;
  void *local_18;
  int local_c;
  
  local_18 = (void *)0x0;
  local_20 = 0;
  if ((*(int *)(param_2 + 0x18) == 0) && ((*(uint *)(param_2 + 0x38) & 2) != 0)) {
    if ((((param_6 == 0) && (1 < param_3)) && (param_4 != (undefined8 *)0x0)) && (param_5 != 0)) {
      for (local_1c = 0; local_1c < param_3; local_1c = local_1c + 1) {
        if (param_4[local_1c] == 0) {
          local_20 = local_20 + 1;
        }
      }
      local_4c = param_3;
      if (local_20 != 0) {
        if (local_20 == param_3) {
          piVar1 = __errno_location();
          *piVar1 = 2;
          goto LAB_00259958;
        }
        FUN_00259e24(param_4,0,0,param_5,param_3,local_20);
        local_4c = param_3 - local_20;
      }
      __ptr = malloc((ulong)local_4c << 3);
      if (__ptr != (void *)0x0) {
        local_c = *(int *)*param_4;
        for (local_1c = 1; local_1c < local_4c; local_1c = local_1c + 1) {
          if (local_c != *(int *)param_4[local_1c]) {
            local_c = -1;
            break;
          }
        }
        if (local_c == -1) {
          local_18 = malloc((ulong)local_4c << 2);
          if (local_18 == (void *)0x0) {
            free(__ptr);
            goto LAB_00259958;
          }
          for (local_1c = 0; local_1c < local_4c; local_1c = local_1c + 1) {
            *(undefined4 *)((long)local_18 + (ulong)local_1c * 4) = *(undefined4 *)param_4[local_1c]
            ;
          }
        }
        *(uint *)(param_2 + 0x18) = local_4c;
        *(undefined8 **)(param_2 + 0x40) = param_4;
        *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) | 1;
        *(void **)(param_2 + 0x20) = __ptr;
        *(int *)(param_2 + 0xc) = local_c;
        *(void **)(param_2 + 0x10) = local_18;
        *(long *)(param_2 + 0x28) = param_5;
        if (local_18 != (void *)0x0) {
          *(ulong *)(param_2 + 0x30) = *(ulong *)(param_2 + 0x30) | 0x10;
        }
        if ((*(int *)(param_2 + 0xc) == 3) || (*(int *)(param_2 + 0xc) == 0xd)) {
          for (local_1c = 0; local_1c < local_4c; local_1c = local_1c + 1) {
            *(ulong *)(*(long *)(param_2 + 0x20) + (ulong)local_1c * 8) =
                 (ulong)*(uint *)(param_4[local_1c] + 0x10);
          }
        }
        else {
          for (local_1c = 0; local_1c < local_4c; local_1c = local_1c + 1) {
            *(undefined8 *)(*(long *)(param_2 + 0x20) + (ulong)local_1c * 8) =
                 *(undefined8 *)(param_4[local_1c] + 0xf0);
          }
        }
        return 0;
      }
    }
    else {
      piVar1 = __errno_location();
      *piVar1 = 0x16;
    }
  }
  else {
    piVar1 = __errno_location();
    *piVar1 = 0x16;
  }
LAB_00259958:
  FUN_002594d2(param_2);
  return 0xffffffff;
}


// ===== 0025996b FUN_0025996b =====

undefined8
FUN_0025996b(undefined8 param_1,long param_2,uint param_3,int param_4,long param_5,long param_6,
            long param_7)

{
  int *piVar1;
  void *pvVar2;
  
  if ((*(int *)(param_2 + 0x18) == 0) && ((*(uint *)(param_2 + 0x38) & 2) != 0)) {
    if ((((param_3 < 2) || (param_6 == 0)) || (param_7 == 0)) || ((param_4 == -1 && (param_5 == 0)))
       ) {
      piVar1 = __errno_location();
      *piVar1 = 0x16;
    }
    else {
      pvVar2 = malloc((ulong)param_3 << 3);
      if (pvVar2 != (void *)0x0) {
        *(uint *)(param_2 + 0x18) = param_3;
        *(void **)(param_2 + 0x40) = pvVar2;
        *(long *)(param_2 + 0x20) = param_6;
        *(int *)(param_2 + 0xc) = param_4;
        *(long *)(param_2 + 0x10) = param_5;
        *(long *)(param_2 + 0x28) = param_7;
        if (param_5 != 0) {
          *(ulong *)(param_2 + 0x30) = *(ulong *)(param_2 + 0x30) | 0x10;
        }
        return 0;
      }
    }
  }
  else {
    piVar1 = __errno_location();
    *piVar1 = 0x16;
  }
  FUN_002594d2(param_2);
  return 0xffffffff;
}


// ===== 00259a82 FUN_00259a82 =====

undefined8 FUN_00259a82(long param_1,long param_2,ulong param_3)

{
  int *piVar1;
  undefined4 local_24;
  long local_20;
  undefined4 local_14;
  undefined4 *local_10;
  
  local_20 = param_2;
  if ((*(int *)(param_2 + 0x18) == 0) || ((*(uint *)(param_2 + 0x38) & 2) == 0)) {
    piVar1 = __errno_location();
    *piVar1 = 0x16;
  }
  else {
    if (((param_3 & 1) == 0) || (*(long *)(param_2 + 0x40) != 0)) {
      if ((*(int *)(param_1 + 0x2f0) != 0) &&
         (((param_3 & 1) != 0 && (*(long *)(param_2 + 0x10) == 0)))) {
        local_24 = 0;
        if ((param_3 & 2) == 0) {
          local_10 = &local_24;
          local_14 = 1;
        }
        else {
          local_10 = (undefined4 *)(param_1 + 0x2fc);
          local_14 = *(undefined4 *)(param_1 + 0x2f8);
        }
        if (*(int *)(param_1 + 0x2f4) != 0) {
          fwrite("Trying to group objects using distance matrix:\n",1,0x2f,
                 *(FILE **)PTR_stderr_0032efe0);
          FUN_00259026(local_20);
        }
        FUN_0025a8f1(param_1,*(undefined4 *)(local_20 + 0x18),*(undefined8 *)(local_20 + 0x40),
                     *(undefined8 *)(local_20 + 0x28),*(undefined8 *)(local_20 + 0x30),local_14,
                     local_10,1);
      }
      if (*(long *)(param_1 + 0x2c8) == 0) {
        *(long *)(param_1 + 0x2c0) = local_20;
      }
      else {
        *(long *)(*(long *)(param_1 + 0x2c8) + 0x50) = local_20;
      }
      *(undefined8 *)(local_20 + 0x48) = *(undefined8 *)(param_1 + 0x2c8);
      *(undefined8 *)(local_20 + 0x50) = 0;
      *(long *)(param_1 + 0x2c8) = local_20;
      *(uint *)(local_20 + 0x38) = *(uint *)(local_20 + 0x38) & 0xfffffffd;
      return 0;
    }
    piVar1 = __errno_location();
    *piVar1 = 0x16;
  }
  FUN_002594d2(local_20);
  return 0xffffffff;
}


// ===== 00259c6e FUN_00259c6e =====

undefined8
FUN_00259c6e(undefined8 param_1,undefined8 param_2,undefined4 param_3,void *param_4,
            undefined4 param_5,void *param_6,void *param_7,undefined8 param_8,undefined8 param_9)

{
  int iVar1;
  long lVar2;
  void *local_40;
  void *local_38;
  
  lVar2 = FUN_0025953c(param_1,param_2,param_8,0);
  local_40 = param_6;
  local_38 = param_4;
  if ((lVar2 != 0) &&
     (iVar1 = FUN_0025996b(param_1,lVar2,param_5,param_3,param_4,param_6,param_7), -1 < iVar1)) {
    local_40 = (void *)0x0;
    local_38 = (void *)0x0;
    param_7 = (void *)0x0;
    iVar1 = FUN_00259a82(param_1,lVar2,param_9);
    if (-1 < iVar1) {
      return 0;
    }
  }
  free(local_40);
  free(local_38);
  free(param_7);
  return 0xffffffff;
}


// ===== 00259d57 FUN_00259d57 =====

undefined8
FUN_00259d57(undefined8 param_1,undefined8 param_2,undefined4 param_3,void *param_4,void *param_5,
            undefined8 param_6,undefined8 param_7)

{
  int iVar1;
  long lVar2;
  void *local_40;
  void *local_38;
  
  lVar2 = FUN_0025953c(param_1,param_2,param_6,0);
  local_40 = param_5;
  local_38 = param_4;
  if ((lVar2 != 0) && (iVar1 = FUN_0025964e(param_1,lVar2,param_3,param_4,param_5,0), -1 < iVar1)) {
    local_38 = (void *)0x0;
    local_40 = (void *)0x0;
    iVar1 = FUN_00259a82(param_1,lVar2,param_7);
    if (-1 < iVar1) {
      return 0;
    }
  }
  free(local_38);
  free(local_40);
  return 0xffffffff;
}


// ===== 00259e24 FUN_00259e24 =====

void FUN_00259e24(long param_1,long param_2,long param_3,long param_4,uint param_5,int param_6)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0;
  for (local_c = 0; local_c < param_5; local_c = local_c + 1) {
    if (*(long *)(param_1 + (ulong)local_c * 8) != 0) {
      local_18 = 0;
      for (local_14 = 0; local_14 < param_5; local_14 = local_14 + 1) {
        if (*(long *)(param_1 + (ulong)local_14 * 8) != 0) {
          *(undefined8 *)((ulong)(local_18 + (param_5 - param_6) * local_10) * 8 + param_4) =
               *(undefined8 *)((ulong)(local_14 + local_c * param_5) * 8 + param_4);
          local_18 = local_18 + 1;
        }
      }
      local_10 = local_10 + 1;
    }
  }
  local_10 = 0;
  for (local_c = 0; local_c < param_5; local_c = local_c + 1) {
    if (*(long *)(param_1 + (ulong)local_c * 8) != 0) {
      *(undefined8 *)(param_1 + (ulong)local_10 * 8) = *(undefined8 *)(param_1 + (ulong)local_c * 8)
      ;
      if (param_2 != 0) {
        *(undefined8 *)(param_2 + (ulong)local_10 * 8) =
             *(undefined8 *)(param_2 + (ulong)local_c * 8);
      }
      if (param_3 != 0) {
        *(undefined4 *)(param_3 + (ulong)local_10 * 4) =
             *(undefined4 *)(param_3 + (ulong)local_c * 4);
      }
      local_10 = local_10 + 1;
    }
  }
  return;
}


// ===== 00259fd9 FUN_00259fd9 =====

undefined8 FUN_00259fd9(undefined8 param_1,long param_2)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  int iVar6;
  undefined8 uVar7;
  long local_18;
  uint local_10;
  int local_c;
  
  iVar1 = *(int *)(param_2 + 0xc);
  lVar3 = *(long *)(param_2 + 0x10);
  uVar2 = *(uint *)(param_2 + 0x18);
  lVar4 = *(long *)(param_2 + 0x40);
  lVar5 = *(long *)(param_2 + 0x20);
  local_c = 0;
  if ((*(uint *)(param_2 + 0x38) & 1) == 0) {
    for (local_10 = 0; local_10 < uVar2; local_10 = local_10 + 1) {
      if ((iVar1 == 3) || (iVar1 == 0xd)) {
        if (iVar1 == 3) {
          local_18 = FUN_00258e89(param_1,*(ulong *)(lVar5 + (ulong)local_10 * 8) & 0xffffffff);
        }
        else {
          if (iVar1 != 0xd) {
                    /* WARNING: Subroutine does not return */
            abort();
          }
          local_18 = FUN_00258edb(param_1,*(ulong *)(lVar5 + (ulong)local_10 * 8) & 0xffffffff);
        }
      }
      else {
        iVar6 = iVar1;
        if (lVar3 != 0) {
          iVar6 = *(int *)(lVar3 + (ulong)local_10 * 4);
        }
        local_18 = FUN_00258226(param_1,iVar6,*(undefined8 *)(lVar5 + (ulong)local_10 * 8));
      }
      *(long *)((ulong)local_10 * 8 + lVar4) = local_18;
      if (local_18 == 0) {
        local_c = local_c + 1;
      }
    }
    if (uVar2 - local_c < 2) {
      uVar7 = 0xffffffff;
    }
    else {
      if (local_c != 0) {
        FUN_00259e24(lVar4,*(undefined8 *)(param_2 + 0x20),*(undefined8 *)(param_2 + 0x10),
                     *(undefined8 *)(param_2 + 0x28),uVar2,local_c);
        *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) - local_c;
      }
      *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) | 1;
      uVar7 = 0;
    }
  }
  else {
    uVar7 = 0;
  }
  return uVar7;
}


// ===== 0025a1b0 FUN_0025a1b0 =====

void FUN_0025a1b0(long param_1)

{
  long lVar1;
  int iVar2;
  long local_10;
  
  lVar1 = *(long *)(param_1 + 0x2c0);
  while( true ) {
    do {
      local_10 = lVar1;
      if (local_10 == 0) {
        return;
      }
      lVar1 = *(long *)(local_10 + 0x50);
      iVar2 = FUN_00259fd9(param_1,local_10);
    } while (-1 < iVar2);
    if ((*(long *)(param_1 + 0x330) != 0) && (*(int *)(*(long *)(param_1 + 0x330) + 0x10) != 0))
    break;
    if (*(long *)(local_10 + 0x48) == 0) {
      *(long *)(param_1 + 0x2c0) = lVar1;
    }
    else {
      *(long *)(*(long *)(local_10 + 0x48) + 0x50) = lVar1;
    }
    if (lVar1 == 0) {
      *(undefined8 *)(param_1 + 0x2c8) = *(undefined8 *)(local_10 + 0x48);
    }
    else {
      *(undefined8 *)(lVar1 + 0x48) = *(undefined8 *)(local_10 + 0x48);
    }
    FUN_002593fc(local_10);
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("!topology->tma || !topology->tma->dontfree",
                "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/distances.c"
                ,0x33c,"hwloc_internal_distances_refresh");
}


// ===== 0025a2b5 FUN_0025a2b5 =====

void FUN_0025a2b5(long param_1)

{
  undefined8 local_10;
  
  for (local_10 = *(long *)(param_1 + 0x2c0); local_10 != 0; local_10 = *(long *)(local_10 + 0x50))
  {
    *(uint *)(local_10 + 0x38) = *(uint *)(local_10 + 0x38) & 0xfffffffe;
  }
  return;
}


// ===== 0025a2f7 FUN_0025a2f7 =====

ulong FUN_0025a2f7(float param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  
  if ((param_1 == 0.0) ||
     ((float)param_2 * param_1 <= (float)(DAT_002ec0f0 & (uint)((float)param_2 - (float)param_3))))
  {
    if (param_2 < param_3) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = (ulong)(param_2 != param_3);
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 0025a3d0 FUN_0025a3d0 =====

int FUN_0025a3d0(float param_1,uint param_2,long param_3,void *param_4,int param_5)

{
  int iVar1;
  uint local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  ulong local_10;
  
  local_10 = 0xffffffffffffffff;
  local_14 = 1;
  local_24 = 0;
  memset(param_4,0,(ulong)param_2 * 4);
  for (local_18 = 0; local_18 < param_2; local_18 = local_18 + 1) {
    for (local_1c = 0; local_1c < param_2; local_1c = local_1c + 1) {
      if ((local_18 != local_1c) &&
         (*(ulong *)(param_3 + (ulong)(local_1c + local_18 * param_2) * 8) < local_10)) {
        local_10 = *(ulong *)(param_3 + (ulong)(local_1c + local_18 * param_2) * 8);
      }
    }
  }
  FUN_00258fcd("  found minimal distance %llu between objects\n",local_10);
  if (local_10 == 0xffffffffffffffff) {
    local_14 = 0;
  }
  else {
    for (local_18 = 0; local_18 < param_2; local_18 = local_18 + 1) {
      if (*(int *)((long)param_4 + (ulong)local_18 * 4) == 0) {
        *(int *)((ulong)local_18 * 4 + (long)param_4) = local_14;
        local_28 = 1;
        local_2c = local_18;
        while (local_2c != 0xffffffff) {
          local_30 = 0xffffffff;
          for (local_1c = local_2c; local_1c < param_2; local_1c = local_1c + 1) {
            if (local_14 == *(int *)((long)param_4 + (ulong)local_1c * 4)) {
              for (local_20 = 0; local_20 < param_2; local_20 = local_20 + 1) {
                if (*(int *)((long)param_4 + (ulong)local_20 * 4) == 0) {
                  iVar1 = FUN_0025a2f7(param_1,*(undefined8 *)
                                                (param_3 +
                                                (ulong)(local_20 + local_1c * param_2) * 8),local_10
                                      );
                  if (iVar1 == 0) {
                    *(int *)((ulong)local_20 * 4 + (long)param_4) = local_14;
                    local_28 = local_28 + 1;
                    if (local_30 == 0xffffffff) {
                      local_30 = local_20;
                    }
                    if (local_18 == local_1c) {
                      FUN_00258fcd("  object %u is minimally connected to %u\n",local_20,local_18);
                    }
                    else {
                      FUN_00258fcd("  object %u is minimally connected to %u through %u\n",local_20,
                                   local_18,local_1c);
                    }
                  }
                }
              }
            }
          }
          local_2c = local_30;
        }
        if (local_28 == 1) {
          *(undefined4 *)((long)param_4 + (ulong)local_18 * 4) = 0;
          local_24 = local_24 + 1;
        }
        else {
          local_14 = local_14 + 1;
          if (param_5 != 0) {
            fprintf(*(FILE **)PTR_stderr_0032efe0,
                    " Found transitive graph with %u objects with minimal distance %llu accuracy %f\n"
                    ,(double)param_1,(ulong)local_28,local_10);
          }
        }
      }
    }
    if ((local_14 == 2) && (local_24 == 0)) {
      local_14 = 0;
    }
    else {
      local_14 = local_14 + -1;
    }
  }
  return local_14;
}


// ===== 0025a6ca FUN_0025a6ca =====

undefined8 FUN_0025a6ca(undefined4 param_1,uint param_2,long param_3,int param_4)

{
  int iVar1;
  uint local_10;
  uint local_c;
  
  local_c = 0;
  do {
    local_10 = local_c;
    if (param_2 <= local_c) {
      return 0;
    }
    while (local_10 = local_10 + 1, local_10 < param_2) {
      iVar1 = FUN_0025a2f7(param_1,*(undefined8 *)
                                    (param_3 + (ulong)(local_10 + local_c * param_2) * 8),
                           *(undefined8 *)(param_3 + (ulong)(local_c + local_10 * param_2) * 8));
      if (iVar1 != 0) {
        if (param_4 != 0) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,
                  " Distance matrix asymmetric ([%u,%u]=%llu != [%u,%u]=%llu), aborting\n",
                  (ulong)local_c,(ulong)local_10,
                  *(undefined8 *)(param_3 + (ulong)(local_10 + local_c * param_2) * 8),
                  (ulong)local_10,(ulong)local_c,
                  *(undefined8 *)(param_3 + (ulong)(local_c + local_10 * param_2) * 8));
        }
        return 0xffffffff;
      }
      iVar1 = FUN_0025a2f7(param_1,*(undefined8 *)
                                    (param_3 + (ulong)(local_10 + local_c * param_2) * 8),
                           *(undefined8 *)(param_3 + (ulong)((param_2 + 1) * local_c) * 8));
      if (iVar1 < 1) {
        if (param_4 != 0) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,
                  " Distance to self not strictly minimal ([%u,%u]=%llu <= [%u,%u]=%llu), aborting\n"
                  ,(ulong)local_c,(ulong)local_10,
                  *(undefined8 *)(param_3 + (ulong)(local_10 + local_c * param_2) * 8),
                  (ulong)local_c,(ulong)local_c,
                  *(undefined8 *)(param_3 + (ulong)((param_2 + 1) * local_c) * 8));
        }
        return 0xffffffff;
      }
    }
    local_c = local_c + 1;
  } while( true );
}


// ===== 0025a8f1 FUN_0025a8f1 =====

void FUN_0025a8f1(long param_1,uint param_2,undefined8 *param_3,long param_4,ulong param_5,
                 uint param_6,long param_7,int param_8)

{
  float fVar1;
  int iVar2;
  int iVar3;
  void *__ptr;
  void *__ptr_00;
  void *__s;
  void *__s_00;
  long lVar4;
  undefined8 uVar5;
  int *piVar6;
  char *pcVar7;
  int local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  local_c = 0;
  iVar2 = *(int *)(param_1 + 0x2f4);
  local_18 = 0;
  if (((2 < param_2) && ((param_5 & 4) != 0)) &&
     (__ptr = malloc((ulong)param_2 << 2), __ptr != (void *)0x0)) {
    for (local_10 = 0; local_10 < param_6; local_10 = local_10 + 1) {
      if (iVar2 != 0) {
        fVar1 = *(float *)(param_7 + (ulong)local_10 * 4);
        uVar5 = FUN_002582d8(*(undefined4 *)*param_3);
        fprintf(*(FILE **)PTR_stderr_0032efe0,
                "Trying to group %u %s objects according to physical distances with accuracy %f\n",
                (double)fVar1,(ulong)param_2,uVar5);
      }
      if (((param_8 == 0) ||
          (iVar3 = FUN_0025a6ca(*(undefined4 *)(param_7 + (ulong)local_10 * 4),param_2,param_4,iVar2
                               ), -1 < iVar3)) &&
         (local_c = FUN_0025a3d0(*(undefined4 *)(param_7 + (ulong)local_10 * 4),param_2,param_4,
                                 __ptr,iVar2), local_c != 0)) break;
    }
    if (local_c != 0) {
      __ptr_00 = malloc((ulong)local_c << 3);
      __s = malloc((ulong)local_c << 2);
      __s_00 = malloc((ulong)(local_c * local_c) << 3);
      if (((__ptr_00 != (void *)0x0) && (__s != (void *)0x0)) && (__s_00 != (void *)0x0)) {
        memset(__s,0,(ulong)local_c * 4);
        for (local_10 = 0; local_10 < local_c; local_10 = local_10 + 1) {
          lVar4 = FUN_0024febd(param_1,0xc,0xffffffff);
          uVar5 = FUN_00260eab();
          *(undefined8 *)(lVar4 + 0xb8) = uVar5;
          *(undefined4 *)(*(long *)(lVar4 + 0x28) + 4) = 900;
          *(undefined4 *)(*(long *)(lVar4 + 0x28) + 8) = *(undefined4 *)(param_1 + 0x310);
          for (local_14 = 0; local_14 < param_2; local_14 = local_14 + 1) {
            if (*(int *)((long)__ptr + (ulong)local_14 * 4) == local_10 + 1) {
              FUN_00250615(lVar4,param_3[local_14]);
              piVar6 = (int *)((long)__s + (ulong)local_10 * 4);
              *piVar6 = *piVar6 + 1;
            }
          }
          if ((param_5 & 2) == 0) {
            pcVar7 = "distances:group";
          }
          else {
            pcVar7 = "distances:fromuser:group";
          }
          lVar4 = FUN_0024fb45(param_1,0,lVar4,pcVar7);
          if (lVar4 == 0) {
            local_18 = local_18 + 1;
          }
          *(long *)((ulong)local_10 * 8 + (long)__ptr_00) = lVar4;
        }
        *(int *)(param_1 + 0x310) = *(int *)(param_1 + 0x310) + 1;
        if (local_18 == 0) {
          memset(__s_00,0,(ulong)local_c * (ulong)local_c * 8);
          for (local_10 = 0; local_10 < param_2; local_10 = local_10 + 1) {
            if (*(int *)((long)__ptr + (ulong)local_10 * 4) != 0) {
              for (local_14 = 0; local_14 < param_2; local_14 = local_14 + 1) {
                if (*(int *)((long)__ptr + (ulong)local_14 * 4) != 0) {
                  *(long *)((long)__s_00 +
                           (ulong)((*(int *)((long)__ptr + (ulong)local_14 * 4) +
                                   (*(int *)((long)__ptr + (ulong)local_10 * 4) + -1) * local_c) - 1
                                  ) * 8) =
                       *(long *)(param_4 + (ulong)(local_14 + local_10 * param_2) * 8) +
                       *(long *)((long)__s_00 +
                                (ulong)((*(int *)((long)__ptr + (ulong)local_14 * 4) +
                                        (*(int *)((long)__ptr + (ulong)local_10 * 4) + -1) * local_c
                                        ) - 1) * 8);
                }
              }
            }
          }
          for (local_10 = 0; local_10 < local_c; local_10 = local_10 + 1) {
            for (local_14 = 0; local_14 < local_c; local_14 = local_14 + 1) {
              *(ulong *)((ulong)(local_14 + local_10 * local_c) * 8 + (long)__s_00) =
                   *(ulong *)((long)__s_00 + (ulong)(local_14 + local_10 * local_c) * 8) /
                   (ulong)(uint)(*(int *)((long)__s + (ulong)local_14 * 4) *
                                *(int *)((long)__s + (ulong)local_10 * 4));
            }
          }
          FUN_0025a8f1(param_1,local_c,__ptr_00,__s_00,param_5,param_6,param_7,0);
        }
      }
      free(__ptr_00);
      free(__s);
      free(__s_00);
    }
    free(__ptr);
  }
  return;
}


// ===== 0025aea7 FUN_0025aea7 =====

long FUN_0025aea7(undefined8 param_1,int param_2)

{
  long local_10;
  
  local_10 = 0;
  do {
    local_10 = FUN_0025aff0(param_1,3,local_10);
    if (local_10 == 0) {
      return 0;
    }
  } while (param_2 != *(int *)(local_10 + 0x10));
  return local_10;
}


// ===== 0025aef9 FUN_0025aef9 =====

long FUN_0025aef9(undefined8 param_1,int param_2)

{
  long local_10;
  
  local_10 = 0;
  do {
    local_10 = FUN_0025aff0(param_1,0xd,local_10);
    if (local_10 == 0) {
      return 0;
    }
  } while (param_2 != *(int *)(local_10 + 0x10));
  return local_10;
}


// ===== 0025af4b FUN_0025af4b =====

undefined8 FUN_0025af4b(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_00257fb0(param_1,param_2);
  if (iVar1 == -1) {
    uVar2 = 0;
  }
  else if (iVar1 == -2) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_002580d2(param_1,iVar1,param_3);
  }
  return uVar2;
}


// ===== 0025afa1 FUN_0025afa1 =====

undefined8 FUN_0025afa1(undefined8 param_1,int param_2,long param_3)

{
  undefined8 uVar1;
  
  if (param_3 == 0) {
    uVar1 = FUN_002580d2(param_1,param_2,0);
  }
  else if (param_2 == *(int *)(param_3 + 0x30)) {
    uVar1 = *(undefined8 *)(param_3 + 0x38);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 0025aff0 FUN_0025aff0 =====

undefined8 FUN_0025aff0(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_00257fb0(param_1,param_2);
  if ((iVar1 == -1) || (iVar1 == -2)) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0025afa1(param_1,iVar1,param_3);
  }
  return uVar2;
}


// ===== 0025b041 FUN_0025b041 =====

undefined8 FUN_0025b041(long param_1,char *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (*(uint *)(param_1 + 0xe0) <= local_c) {
      return 0;
    }
    puVar2 = (undefined8 *)(*(long *)(param_1 + 0xd8) + (ulong)local_c * 0x10);
    iVar1 = strcmp((char *)*puVar2,param_2);
    if (iVar1 == 0) break;
    local_c = local_c + 1;
  }
  return puVar2[1];
}


// ===== 0025b0b1 FUN_0025b0b1 =====

void FUN_0025b0b1(void)

{
  return;
}


// ===== 0025b10a FUN_0025b10a =====

void FUN_0025b10a(long param_1)

{
  *(undefined4 *)(param_1 + 0x2d4) = 0;
  *(undefined8 *)(param_1 + 0x2d8) = 0;
  return;
}


// ===== 0025b132 FUN_0025b132 =====

void FUN_0025b132(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  *(undefined4 *)(param_1 + 2) = param_4;
  *(undefined4 *)((long)param_1 + 0x14) = 0;
  param_1[3] = 0;
  return;
}


// ===== 0025b184 FUN_0025b184 =====

void FUN_0025b184(long param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(0x100);
  *(void **)(param_1 + 0x2d8) = pvVar1;
  if (*(long *)(param_1 + 0x2d8) != 0) {
    FUN_0025b132(*(undefined8 *)(param_1 + 0x2d8),"Capacity",1,5);
    FUN_0025b132(*(long *)(param_1 + 0x2d8) + 0x20,"Locality",2,5);
    FUN_0025b132(*(long *)(param_1 + 0x2d8) + 0x40,"Bandwidth",5,1);
    FUN_0025b132(*(long *)(param_1 + 0x2d8) + 0x80,"ReadBandwidth",5,1);
    FUN_0025b132(*(long *)(param_1 + 0x2d8) + 0xa0,"WriteBandwidth",5,1);
    FUN_0025b132(*(long *)(param_1 + 0x2d8) + 0x60,"Latency",6,1);
    FUN_0025b132(*(long *)(param_1 + 0x2d8) + 0xc0,"ReadLatency",6,1);
    FUN_0025b132(*(long *)(param_1 + 0x2d8) + 0xe0,"WriteLatency",6,1);
    *(undefined4 *)(param_1 + 0x2d4) = 8;
  }
  return;
}


// ===== 0025b311 FUN_0025b311 =====

void FUN_0025b311(int *param_1)

{
  if (*param_1 == 1) {
    FUN_00260f71(*(undefined8 *)(param_1 + 2));
  }
  return;
}


// ===== 0025b33b FUN_0025b33b =====

void FUN_0025b33b(long param_1,long param_2)

{
  undefined4 local_c;
  
  if ((*(ulong *)(param_1 + 8) & 4) != 0) {
    for (local_c = 0; local_c < *(uint *)(param_2 + 0x20); local_c = local_c + 1) {
      FUN_0025b311((ulong)local_c * 0x28 + *(long *)(param_2 + 0x28));
    }
  }
  free(*(void **)(param_2 + 0x28));
  return;
}


// ===== 0025b3ab FUN_0025b3ab =====

void FUN_0025b3ab(long param_1)

{
  undefined8 *puVar1;
  uint local_10;
  uint local_c;
  
  for (local_c = 0; local_c < *(uint *)(param_1 + 0x2d4); local_c = local_c + 1) {
    puVar1 = (undefined8 *)(*(long *)(param_1 + 0x2d8) + (ulong)local_c * 0x20);
    for (local_10 = 0; local_10 < *(uint *)((long)puVar1 + 0x14); local_10 = local_10 + 1) {
      FUN_0025b33b(puVar1,puVar1[3] + (ulong)local_10 * 0x30);
    }
    free((void *)puVar1[3]);
    if ((*(uint *)(puVar1 + 2) & 1) == 0) {
      free((void *)*puVar1);
    }
  }
  free(*(void **)(param_1 + 0x2d8));
  *(undefined8 *)(param_1 + 0x2d8) = 0;
  *(undefined4 *)(param_1 + 0x2d4) = 0;
  return;
}


// ===== 0025b497 FUN_0025b497 =====

undefined8 FUN_0025b497(long param_1,char *param_2,uint *param_3)

{
  int iVar1;
  int *piVar2;
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (*(uint *)(param_1 + 0x2d4) <= local_c) {
      piVar2 = __errno_location();
      *piVar2 = 0x16;
      return 0xffffffff;
    }
    iVar1 = strcmp(*(char **)(*(long *)(param_1 + 0x2d8) + (ulong)local_c * 0x20),param_2);
    if (iVar1 == 0) break;
    local_c = local_c + 1;
  }
  *param_3 = local_c;
  return 0;
}


// ===== 0025b514 FUN_0025b514 =====

undefined8 FUN_0025b514(long param_1,uint param_2,undefined8 *param_3)

{
  int *piVar1;
  undefined8 uVar2;
  
  if (param_2 < *(uint *)(param_1 + 0x2d4)) {
    *param_3 = *(undefined8 *)(*(long *)(param_1 + 0x2d8) + (ulong)param_2 * 0x20 + 8);
    uVar2 = 0;
  }
  else {
    piVar1 = __errno_location();
    *piVar1 = 0x16;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// ===== 0025b56f FUN_0025b56f =====

undefined8 FUN_0025b56f(long param_1,char *param_2,ulong param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  char *__ptr;
  void *pvVar4;
  uint local_c;
  
  if ((param_3 & 0xfffffffffffffff8) == 0) {
    if ((param_3 & 3) == 0) {
      piVar2 = __errno_location();
      *piVar2 = 0x16;
      uVar3 = 0xffffffff;
    }
    else if (((uint)param_3 & 3) == 3) {
      piVar2 = __errno_location();
      *piVar2 = 0x16;
      uVar3 = 0xffffffff;
    }
    else if (param_2 == (char *)0x0) {
      piVar2 = __errno_location();
      *piVar2 = 0x16;
      uVar3 = 0xffffffff;
    }
    else {
      for (local_c = 0; local_c < *(uint *)(param_1 + 0x2d4); local_c = local_c + 1) {
        iVar1 = strcmp(param_2,*(char **)(*(long *)(param_1 + 0x2d8) + (ulong)local_c * 0x20));
        if (iVar1 == 0) {
          piVar2 = __errno_location();
          *piVar2 = 0x10;
          return 0xffffffff;
        }
      }
      __ptr = strdup(param_2);
      if (__ptr == (char *)0x0) {
        uVar3 = 0xffffffff;
      }
      else {
        pvVar4 = realloc(*(void **)(param_1 + 0x2d8),(ulong)(*(int *)(param_1 + 0x2d4) + 1) << 5);
        if (pvVar4 == (void *)0x0) {
          free(__ptr);
          uVar3 = 0xffffffff;
        }
        else {
          FUN_0025b132((void *)((ulong)*(uint *)(param_1 + 0x2d4) * 0x20 + (long)pvVar4),__ptr,
                       param_3,0);
          *(uint *)((long)pvVar4 + (ulong)*(uint *)(param_1 + 0x2d4) * 0x20 + 0x10) =
               *(uint *)((long)pvVar4 + (ulong)*(uint *)(param_1 + 0x2d4) * 0x20 + 0x10) | 2;
          *param_4 = *(undefined4 *)(param_1 + 0x2d4);
          *(int *)(param_1 + 0x2d4) = *(int *)(param_1 + 0x2d4) + 1;
          *(void **)(param_1 + 0x2d8) = pvVar4;
          uVar3 = 0;
        }
      }
    }
  }
  else {
    piVar2 = __errno_location();
    *piVar2 = 0x16;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ===== 0025b77c FUN_0025b77c =====

undefined8 FUN_0025b77c(int *param_1,int *param_2)

{
  undefined8 uVar1;
  
  if (*param_1 == *param_2) {
    if (*param_1 == 0) {
      if ((param_1[6] == param_2[6]) && (*(long *)(param_1 + 4) == *(long *)(param_2 + 4))) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else if (*param_1 == 1) {
      uVar1 = FUN_002623d5(*(undefined8 *)(param_1 + 2),*(undefined8 *)(param_2 + 2));
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 0025b80b FUN_0025b80b =====

undefined8 FUN_0025b80b(long param_1,int *param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (*param_2 == 0) {
    lVar3 = FUN_00258226(param_1,param_2[6],*(undefined8 *)(param_2 + 4));
    if (lVar3 == 0) {
      FUN_0025b311(param_2);
      uVar2 = 0xffffffff;
    }
    else {
      *(long *)(param_2 + 2) = lVar3;
      uVar2 = 0;
    }
  }
  else {
    if (*param_2 != 1) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("0",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/memattrs.c"
                    ,0x1ae,"hwloc__imi_refresh");
    }
    FUN_002626c1(*(undefined8 *)(param_2 + 2),*(undefined8 *)(param_2 + 2),
                 *(undefined8 *)(*(long *)**(undefined8 **)(param_1 + 0x18) + 0xb8));
    iVar1 = FUN_002620a3(*(undefined8 *)(param_2 + 2));
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      FUN_0025b311(param_2);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}


// ===== 0025b8fb FUN_0025b8fb =====

undefined8 FUN_0025b8fb(undefined8 param_1,long param_2,long *param_3)

{
  int iVar1;
  undefined8 uVar2;
  uint local_18;
  uint local_14;
  long local_10;
  
  if ((*(uint *)(param_2 + 0x10) & 4) != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!(imattr->iflags & (1U<<2))",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/memattrs.c"
                  ,0x1bb,"hwloc__imtg_refresh");
  }
  if (param_3[2] == -1) {
    if ((int)param_3[1] == 0xd) {
      local_10 = FUN_0025aef9(param_1,*(undefined4 *)((long)param_3 + 0xc));
    }
    else if ((int)param_3[1] == 3) {
      local_10 = FUN_0025aea7(param_1,*(undefined4 *)((long)param_3 + 0xc));
    }
    else {
      local_10 = 0;
    }
  }
  else {
    local_10 = FUN_00258226(param_1,(int)param_3[1],param_3[2]);
  }
  if (local_10 == 0) {
    FUN_0025b33b(param_2,param_3);
    uVar2 = 0xffffffff;
  }
  else {
    param_3[2] = *(long *)(local_10 + 0xf0);
    *param_3 = local_10;
    if ((*(ulong *)(param_2 + 8) & 4) != 0) {
      local_18 = 0;
      for (local_14 = 0; local_14 < *(uint *)(param_3 + 4); local_14 = local_14 + 1) {
        iVar1 = FUN_0025b80b(param_1,param_3[5] + (ulong)local_14 * 0x28);
        if (-1 < iVar1) {
          if (local_14 != local_18) {
            memcpy((void *)((ulong)local_18 * 0x28 + param_3[5]),
                   (void *)(param_3[5] + (ulong)local_14 * 0x28),0x28);
          }
          local_18 = local_18 + 1;
        }
      }
      *(uint *)(param_3 + 4) = local_18;
      if ((int)param_3[4] == 0) {
        FUN_0025b33b(param_2,param_3);
        return 0xffffffff;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 0025bb02 FUN_0025bb02 =====

void FUN_0025bb02(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0;
  for (local_c = 0; local_c < *(uint *)(param_2 + 0x14); local_c = local_c + 1) {
    iVar1 = FUN_0025b8fb(param_1,param_2,*(long *)(param_2 + 0x18) + (ulong)local_c * 0x30);
    if (iVar1 == 0) {
      if (local_c != local_10) {
        memcpy((void *)((ulong)local_10 * 0x30 + *(long *)(param_2 + 0x18)),
               (void *)(*(long *)(param_2 + 0x18) + (ulong)local_c * 0x30),0x30);
      }
      local_10 = local_10 + 1;
    }
  }
  *(uint *)(param_2 + 0x14) = local_10;
  *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 2;
  return;
}


// ===== 0025bbe3 FUN_0025bbe3 =====

void FUN_0025bbe3(long param_1)

{
  long lVar1;
  undefined4 local_c;
  
  for (local_c = 0; local_c < *(uint *)(param_1 + 0x2d4); local_c = local_c + 1) {
    lVar1 = *(long *)(param_1 + 0x2d8) + (ulong)local_c * 0x20;
    if ((*(uint *)(lVar1 + 0x10) & 2) == 0) {
      FUN_0025bb02(param_1,lVar1);
    }
  }
  return;
}


// ===== 0025bc4b FUN_0025bc4b =====

void FUN_0025bc4b(long param_1)

{
  long lVar1;
  undefined4 local_c;
  
  for (local_c = 0; local_c < *(uint *)(param_1 + 0x2d4); local_c = local_c + 1) {
    lVar1 = *(long *)(param_1 + 0x2d8) + (ulong)local_c * 0x20;
    if ((*(uint *)(lVar1 + 0x10) & 4) == 0) {
      *(uint *)(lVar1 + 0x10) = *(uint *)(lVar1 + 0x10) & 0xfffffffd;
    }
  }
  return;
}


// ===== 0025bcaf FUN_0025bcaf =====

undefined8 * FUN_0025bcaf(long param_1,int param_2,long param_3,int param_4,int param_5)

{
  undefined8 *puVar1;
  void *pvVar2;
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (*(uint *)(param_1 + 0x14) <= local_c) {
      if (param_5 == 0) {
        puVar1 = (undefined8 *)0x0;
      }
      else {
        pvVar2 = realloc(*(void **)(param_1 + 0x18),(ulong)(*(int *)(param_1 + 0x14) + 1) * 0x30);
        if (pvVar2 == (void *)0x0) {
          puVar1 = (undefined8 *)0x0;
        }
        else {
          *(void **)(param_1 + 0x18) = pvVar2;
          puVar1 = (undefined8 *)((long)pvVar2 + (ulong)*(uint *)(param_1 + 0x14) * 0x30);
          *(int *)(puVar1 + 1) = param_2;
          puVar1[2] = param_3;
          *(int *)((long)puVar1 + 0xc) = param_4;
          *puVar1 = 0;
          *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffd;
          *(undefined4 *)(puVar1 + 4) = 0;
          puVar1[5] = 0;
          puVar1[3] = 0;
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
        }
      }
      return puVar1;
    }
    if ((param_2 == *(int *)((ulong)local_c * 0x30 + *(long *)(param_1 + 0x18) + 8)) &&
       (((param_3 != -1 &&
         (param_3 == *(long *)((ulong)local_c * 0x30 + *(long *)(param_1 + 0x18) + 0x10))) ||
        ((param_4 != -1 &&
         (param_4 == *(int *)((ulong)local_c * 0x30 + *(long *)(param_1 + 0x18) + 0xc))))))) break;
    local_c = local_c + 1;
  }
  return (undefined8 *)((ulong)local_c * 0x30 + *(long *)(param_1 + 0x18));
}


// ===== 0025be7d FUN_0025be7d =====

undefined8 * FUN_0025be7d(long param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined8 *puVar2;
  void *pvVar3;
  undefined8 uVar4;
  uint local_c;
  
  for (local_c = 0; local_c < *(uint *)(param_1 + 0x20); local_c = local_c + 1) {
    puVar2 = (undefined8 *)((ulong)local_c * 0x28 + *(long *)(param_1 + 0x28));
    iVar1 = FUN_0025b77c(param_2,puVar2);
    if (iVar1 != 0) {
      return puVar2;
    }
  }
  if (param_3 == 0) {
    puVar2 = (undefined8 *)0x0;
  }
  else {
    pvVar3 = realloc(*(void **)(param_1 + 0x28),(ulong)(*(int *)(param_1 + 0x20) + 1) * 0x28);
    if (pvVar3 == (void *)0x0) {
      puVar2 = (undefined8 *)0x0;
    }
    else {
      puVar2 = (undefined8 *)((long)pvVar3 + (ulong)*(uint *)(param_1 + 0x20) * 0x28);
      uVar4 = *(undefined8 *)(param_2 + 2);
      *puVar2 = *(undefined8 *)param_2;
      puVar2[1] = uVar4;
      uVar4 = *(undefined8 *)(param_2 + 6);
      puVar2[2] = *(undefined8 *)(param_2 + 4);
      puVar2[3] = uVar4;
      if (*param_2 == 1) {
        uVar4 = FUN_002611e2(*(undefined8 *)(param_2 + 2));
        puVar2[1] = uVar4;
        if (puVar2[1] == 0) {
          *(void **)(param_1 + 0x28) = pvVar3;
          return (undefined8 *)0x0;
        }
      }
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
      *(void **)(param_1 + 0x28) = pvVar3;
    }
  }
  return puVar2;
}


// ===== 0025bff3 FUN_0025bff3 =====

undefined8
FUN_0025bff3(long param_1,uint param_2,undefined4 param_3,undefined8 param_4,undefined4 param_5,
            long param_6,undefined8 param_7)

{
  int *piVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  if (param_2 < *(uint *)(param_1 + 0x2d4)) {
    lVar3 = *(long *)(param_1 + 0x2d8) + (ulong)param_2 * 0x20;
    if (((*(ulong *)(lVar3 + 8) & 4) == 0) || (param_6 != 0)) {
      if ((*(uint *)(lVar3 + 0x10) & 4) == 0) {
        if ((*(int *)(param_1 + 0xcc) != 0) && ((*(uint *)(lVar3 + 0x10) & 2) == 0)) {
          FUN_0025bb02(param_1,lVar3);
        }
        lVar4 = FUN_0025bcaf(lVar3,param_3,param_4,param_5,1);
        if (lVar4 == 0) {
          uVar2 = 0xffffffff;
        }
        else {
          if ((*(ulong *)(lVar3 + 8) & 4) == 0) {
            *(undefined8 *)(lVar4 + 0x18) = param_7;
          }
          else {
            lVar3 = FUN_0025be7d(lVar4,param_6,1);
            if (lVar3 == 0) {
              return 0xffffffff;
            }
            *(undefined8 *)(lVar3 + 0x20) = param_7;
          }
          uVar2 = 0;
        }
      }
      else {
        piVar1 = __errno_location();
        *piVar1 = 0x16;
        uVar2 = 0xffffffff;
      }
    }
    else {
      piVar1 = __errno_location();
      *piVar1 = 0x16;
      uVar2 = 0xffffffff;
    }
  }
  else {
    piVar1 = __errno_location();
    *piVar1 = 0x16;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// ===== 0025c155 FUN_0025c155 =====

void FUN_0025c155(undefined8 param_1,int param_2,undefined4 param_3,undefined8 param_4,
                 undefined4 param_5,undefined8 param_6,undefined8 param_7)

{
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("id != HWLOC_MEMATTR_ID_CAPACITY",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/memattrs.c"
                  ,0x39b,"hwloc_internal_memattr_set_value");
  }
  if (param_2 == 1) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("id != HWLOC_MEMATTR_ID_LOCALITY",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/memattrs.c"
                  ,0x39c,"hwloc_internal_memattr_set_value");
  }
  FUN_0025bff3(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}


// ===== 0025c1ed FUN_0025c1ed =====

undefined8 FUN_0025c1ed(long param_1,undefined8 param_2,ulong param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((param_3 & 4) == 0) {
    if (((param_3 & 1) != 0) &&
       (iVar1 = FUN_002623d5(param_2,*(undefined8 *)(param_1 + 0xb8)), iVar1 != 0)) {
      return 1;
    }
    if (((param_3 & 2) != 0) &&
       (iVar1 = FUN_002623d5(*(undefined8 *)(param_1 + 0xb8),param_2), iVar1 != 0)) {
      return 1;
    }
    uVar2 = FUN_00262158(*(undefined8 *)(param_1 + 0xb8),param_2);
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


// ===== 0025c292 FUN_0025c292 =====

undefined8 FUN_0025c292(undefined8 param_1,int *param_2,uint *param_3,long param_4,ulong param_5)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  long local_28;
  uint local_1c;
  long local_18;
  undefined8 local_10;
  
  if ((param_5 & 0xfffffffffffffff8) == 0) {
    if ((param_3 == (uint *)0x0) || ((*param_3 != 0 && (param_4 == 0)))) {
      piVar2 = __errno_location();
      *piVar2 = 0x16;
      uVar3 = 0xffffffff;
    }
    else {
      if (param_2 == (int *)0x0) {
        if ((param_5 & 4) == 0) {
          piVar2 = __errno_location();
          *piVar2 = 0x16;
          return 0xffffffff;
        }
        local_10 = 0;
      }
      else if (*param_2 == 1) {
        local_10 = *(undefined8 *)(param_2 + 2);
      }
      else {
        if (*param_2 != 0) {
          piVar2 = __errno_location();
          *piVar2 = 0x16;
          return 0xffffffff;
        }
        for (local_28 = *(long *)(param_2 + 2); *(long *)(local_28 + 0xb8) == 0;
            local_28 = *(long *)(local_28 + 0x48)) {
        }
        local_10 = *(undefined8 *)(local_28 + 0xb8);
      }
      local_1c = 0;
      for (local_18 = FUN_0025af4b(param_1,0xd,0); local_18 != 0;
          local_18 = *(long *)(local_18 + 0x38)) {
        iVar1 = FUN_0025c1ed(local_18,local_10,param_5);
        if (iVar1 != 0) {
          if (local_1c < *param_3) {
            *(long *)((ulong)local_1c * 8 + param_4) = local_18;
          }
          local_1c = local_1c + 1;
        }
      }
      *param_3 = local_1c;
      uVar3 = 0;
    }
  }
  else {
    piVar2 = __errno_location();
    *piVar2 = 0x16;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ===== 0025c42e FUN_0025c42e =====

int FUN_0025c42e(long param_1,long param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x10) == *(int *)(param_2 + 0x10)) {
    if (*(ulong *)(param_2 + 8) < *(ulong *)(param_1 + 8)) {
      iVar1 = -1;
    }
    else if (*(ulong *)(param_1 + 8) < *(ulong *)(param_2 + 8)) {
      iVar1 = 1;
    }
    else {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 0x10) - *(int *)(param_2 + 0x10);
  }
  return iVar1;
}


// ===== 0025c4af FUN_0025c4af =====

undefined8 FUN_0025c4af(long param_1)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined4 local_a8 [2];
  undefined8 local_a0;
  long local_88;
  char *local_80;
  long local_78;
  uint local_70;
  uint local_6c;
  void *local_68;
  uint local_5c;
  long local_58;
  char *local_50;
  char *local_48;
  long local_40;
  ulong local_38;
  long local_30;
  int local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  
  local_24 = -1;
  local_28 = 1;
  local_50 = getenv("HWLOC_MEMTIERS_GUESS");
  if (local_50 != (char *)0x0) {
    iVar3 = strcmp(local_50,"none");
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = strcmp(local_50,"default");
    if (iVar3 != 0) {
      iVar3 = strcmp(local_50,"spm_is_hbm");
      if (iVar3 == 0) {
        FUN_0025b0b1("Assuming SPM-tier is HBM, ignore bandwidth\n");
        local_24 = 1;
      }
      else {
        iVar3 = FUN_0024d64f();
        if (iVar3 < 2) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,
                  "hwloc: Failed to recognize HWLOC_MEMTIERS_GUESS value %s\n",local_50);
        }
      }
    }
  }
  local_58 = *(long *)(param_1 + 0x2d8) + 0x40;
  if ((*(uint *)(*(long *)(param_1 + 0x2d8) + 0x50) & 2) == 0) {
    FUN_0025bb02(param_1,local_58);
  }
  local_5c = FUN_00258070(param_1,0xfffffffd);
  if (local_5c == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("n",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/memattrs.c"
                  ,0x502,"hwloc_internal_memattrs_guess_memory_tiers");
  }
  local_68 = malloc((ulong)local_5c * 0x18);
  if (local_68 == (void *)0x0) {
    uVar4 = 0xffffffff;
  }
  else {
    for (local_1c = 0; local_1c < local_5c; local_1c = local_1c + 1) {
      local_40 = 0;
      local_78 = FUN_002580d2(param_1,0xfffffffd,local_1c);
      if (local_78 == 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("node",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/memattrs.c"
                      ,0x510,"hwloc_internal_memattrs_guess_memory_tiers");
      }
      *(long *)((ulong)local_1c * 0x18 + (long)local_68) = local_78;
      *(undefined4 *)((long)local_68 + (ulong)local_1c * 0x18 + 0x10) = 0;
      *(undefined8 *)((long)local_68 + (ulong)local_1c * 0x18 + 8) = 0;
      local_80 = (char *)FUN_0025b041(local_78,"DAXType");
      if ((local_80 != (char *)0x0) && (iVar3 = strcmp(local_80,"NVM"), iVar3 == 0)) {
        *(undefined4 *)((long)local_68 + (ulong)local_1c * 0x18 + 0x10) = 4;
      }
      if ((local_80 != (char *)0x0) && (iVar3 = strcmp(local_80,"SPM"), iVar3 == 0)) {
        *(undefined4 *)((long)local_68 + (ulong)local_1c * 0x18 + 0x10) = 3;
      }
      if ((*(long *)(local_78 + 8) != 0) &&
         (iVar3 = strcmp(*(char **)(local_78 + 8),"GPUMemory"), iVar3 == 0)) {
        *(undefined4 *)((long)local_68 + (ulong)local_1c * 0x18 + 0x10) = 5;
      }
      if (local_24 == -1) {
        for (local_20 = 0; local_20 < *(uint *)(local_58 + 0x14); local_20 = local_20 + 1) {
          if (local_78 == *(long *)((ulong)local_20 * 0x30 + *(long *)(local_58 + 0x18))) {
            local_40 = (ulong)local_20 * 0x30 + *(long *)(local_58 + 0x18);
            break;
          }
        }
        if ((local_40 != 0) && (iVar3 = FUN_002620a3(*(undefined8 *)(local_78 + 0xb8)), iVar3 == 0))
        {
          local_a8[0] = 1;
          local_a0 = *(undefined8 *)(local_78 + 0xb8);
          local_88 = FUN_0025be7d(local_40,local_a8,0);
          if (local_88 != 0) {
            *(undefined8 *)((long)local_68 + (ulong)local_1c * 0x18 + 8) =
                 *(undefined8 *)(local_88 + 0x20);
          }
        }
      }
    }
    qsort(local_68,(ulong)local_5c,0x18,FUN_0025c42e);
    FUN_0025b0b1("Sorting memory tiers...\n");
    for (local_1c = 0; local_1c < local_5c; local_1c = local_1c + 1) {
      FUN_0025b0b1("  tier %u = node L#%u P#%u with tier type %d and local BW #%llu\n",local_1c,
                   *(undefined4 *)(*(long *)((long)local_68 + (ulong)local_1c * 0x18) + 0x34),
                   *(undefined4 *)(*(long *)((long)local_68 + (ulong)local_1c * 0x18) + 0x10),
                   *(undefined4 *)((long)local_68 + (ulong)local_1c * 0x18 + 0x10),
                   *(undefined8 *)((long)local_68 + (ulong)local_1c * 0x18 + 8));
    }
    local_1c = 0;
    while ((uVar1 = local_1c, local_1c < local_5c &&
           (*(int *)((long)local_68 + (ulong)local_1c * 0x18 + 0x10) == 0))) {
      local_1c = local_1c + 1;
    }
    local_6c = local_1c;
    if (local_1c == 0) {
      local_30 = 0;
    }
    else {
      local_30 = *(long *)((long)local_68 + 8);
    }
    while ((local_1c < local_5c && (*(uint *)((long)local_68 + (ulong)local_1c * 0x18 + 0x10) < 4)))
    {
      local_1c = local_1c + 1;
    }
    local_70 = local_1c;
    if (uVar1 < local_1c) {
      local_38 = *(ulong *)((long)local_68 + (ulong)(local_1c - 1) * 0x18 + 8);
    }
    else {
      local_38 = 0;
    }
    if (local_24 == -1) {
      FUN_0025b0b1("UNKNOWN-memory-tier max bandwidth %llu\n",local_30);
      FUN_0025b0b1("SPM-memory-tier min bandwidth %llu\n",local_38);
      if (((local_30 == 0) || (local_38 == 0)) || (local_38 <= (ulong)(local_30 * 2))) {
        FUN_0025b0b1("cannot assume SPM means HBM\n");
        local_24 = 0;
      }
      else {
        FUN_0025b0b1(
                    "assuming SPM means HBM and !SPM means DRAM since bandwidths are very different\n"
                    );
        local_24 = 1;
      }
    }
    if (local_24 != 0) {
      for (local_1c = 0; local_1c < local_6c; local_1c = local_1c + 1) {
        *(undefined4 *)((long)local_68 + (ulong)local_1c * 0x18 + 0x10) = 1;
      }
      for (local_1c = local_6c; local_1c < local_70; local_1c = local_1c + 1) {
        *(undefined4 *)((long)local_68 + (ulong)local_1c * 0x18 + 0x10) = 2;
      }
    }
    if (local_6c == local_5c) {
      local_28 = 0;
    }
    for (local_1c = 0; local_1c < local_5c; local_1c = local_1c + 1) {
      local_48 = (char *)0x0;
      if (*(long *)(*(long *)((long)local_68 + (ulong)local_1c * 0x18) + 8) == 0) {
        uVar1 = *(uint *)((long)local_68 + (ulong)local_1c * 0x18 + 0x10);
        if (uVar1 == 2) {
          local_48 = "HBM";
        }
        else if (uVar1 < 3) {
          if ((uVar1 == 1) && (local_28 != 0)) {
            local_48 = "DRAM";
          }
        }
        else if (uVar1 == 3) {
          local_48 = "SPM";
        }
        else if (uVar1 == 4) {
          local_48 = "NVM";
        }
        if (local_48 != (char *)0x0) {
          FUN_0025b0b1("Marking node L#%u P#%u as %s\n",
                       *(undefined4 *)(*(long *)((long)local_68 + (ulong)local_1c * 0x18) + 0x34),
                       *(undefined4 *)(*(long *)((long)local_68 + (ulong)local_1c * 0x18) + 0x10),
                       local_48);
          lVar2 = *(long *)((long)local_68 + (ulong)local_1c * 0x18);
          pcVar5 = strdup(local_48);
          *(char **)(lVar2 + 8) = pcVar5;
        }
      }
    }
    free(local_68);
    uVar4 = 0;
  }
  return uVar4;
}


// ===== 0025cce2 FUN_0025cce2 =====

void FUN_0025cce2(undefined8 param_1)

{
  FUN_002580d2(param_1,0,0);
  return;
}


// ===== 0025cd06 FUN_0025cd06 =====

int FUN_0025cd06(ulong param_1)

{
  undefined8 local_20;
  undefined4 local_c;
  
  if (param_1 == 0) {
    local_c = 0;
  }
  else {
    local_c = 1;
    local_20 = param_1;
    if ((param_1 & 0xffffffff00000000) != 0) {
      local_20 = param_1 >> 0x20;
      local_c = 0x21;
    }
    if ((local_20 & 0xffff0000) != 0) {
      local_20 = local_20 >> 0x10;
      local_c = local_c + 0x10;
    }
    if ((local_20 & 0xff00) != 0) {
      local_20 = local_20 >> 8;
      local_c = local_c + 8;
    }
    if ((local_20 & 0xf0) != 0) {
      local_20 = local_20 >> 4;
      local_c = local_c + 4;
    }
    if ((local_20 & 0xc) != 0) {
      local_20 = local_20 >> 2;
      local_c = local_c + 2;
    }
    if ((local_20 & 2) != 0) {
      local_c = local_c + 1;
    }
  }
  return local_c;
}


// ===== 0025cdbc FUN_0025cdbc =====

void FUN_0025cdbc(void)

{
  return;
}


// ===== 0025ce15 FUN_0025ce15 =====

void FUN_0025ce15(long param_1)

{
  *(undefined8 *)(param_1 + 0x2e8) = 0;
  *(undefined4 *)(param_1 + 0x2e0) = 0;
  *(undefined4 *)(param_1 + 0x2e4) = 0;
  return;
}


// ===== 0025ce4b FUN_0025ce4b =====

void FUN_0025ce4b(long param_1)

{
  undefined8 *puVar1;
  uint local_c;
  
  for (local_c = 0; local_c < *(uint *)(param_1 + 0x2e0); local_c = local_c + 1) {
    puVar1 = (undefined8 *)((ulong)local_c * 0x28 + *(long *)(param_1 + 0x2e8));
    FUN_00260f71(*puVar1);
    FUN_0024db80(puVar1[4],*(undefined4 *)(puVar1 + 3));
  }
  free(*(void **)(param_1 + 0x2e8));
  *(undefined8 *)(param_1 + 0x2e8) = 0;
  *(undefined4 *)(param_1 + 0x2e0) = 0;
  return;
}


// ===== 0025cef1 FUN_0025cef1 =====

void FUN_0025cef1(long param_1)

{
  bool bVar1;
  int iVar2;
  undefined8 *__dest;
  long lVar3;
  uint local_c;
  
  bVar1 = false;
  for (local_c = 0; local_c < *(uint *)(param_1 + 0x2e0); local_c = local_c + 1) {
    __dest = (undefined8 *)((ulong)local_c * 0x28 + *(long *)(param_1 + 0x2e8));
    lVar3 = FUN_0025cce2(param_1);
    FUN_002626c1(*__dest,*__dest,*(undefined8 *)(lVar3 + 0xb8));
    iVar2 = FUN_002620a3(*__dest);
    if (iVar2 != 0) {
      FUN_00260f71(*__dest);
      FUN_0024db80(__dest[4],*(undefined4 *)(__dest + 3));
      memmove(__dest,__dest + 5,(ulong)((*(int *)(param_1 + 0x2e0) - local_c) - 1) * 0x28);
      local_c = local_c - 1;
      *(int *)(param_1 + 0x2e0) = *(int *)(param_1 + 0x2e0) + -1;
      bVar1 = true;
    }
  }
  if (bVar1) {
    FUN_0025e18a(param_1);
  }
  return;
}


// ===== 0025d026 FUN_0025d026 =====

undefined8 FUN_0025d026(long param_1,char *param_2,char *param_3)

{
  int iVar1;
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (*(uint *)(param_1 + 0x18) <= local_c) {
      return 0;
    }
    iVar1 = strcmp(*(char **)(*(long *)(param_1 + 0x20) + (ulong)local_c * 0x10),param_2);
    if ((iVar1 == 0) &&
       (iVar1 = strcmp(*(char **)(*(long *)(param_1 + 0x20) + (ulong)local_c * 0x10 + 8),param_3),
       iVar1 == 0)) break;
    local_c = local_c + 1;
  }
  return 1;
}


// ===== 0025d0b2 FUN_0025d0b2 =====

void FUN_0025d0b2(long param_1,long param_2,uint param_3)

{
  int iVar1;
  undefined4 local_c;
  
  for (local_c = 0; local_c < param_3; local_c = local_c + 1) {
    iVar1 = FUN_0025d026(param_1,*(undefined8 *)(param_2 + (ulong)local_c * 0x10),
                         *(undefined8 *)(param_2 + (ulong)local_c * 0x10 + 8));
    if (iVar1 == 0) {
      FUN_0024dbec(param_1 + 0x20,param_1 + 0x18,*(undefined8 *)(param_2 + (ulong)local_c * 0x10),
                   *(undefined8 *)(param_2 + (ulong)local_c * 0x10 + 8));
    }
  }
  return;
}


// ===== 0025d167 FUN_0025d167 =====

undefined8
FUN_0025d167(long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
            undefined4 param_5,ulong param_6)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined8 uVar5;
  uint local_2c;
  uint local_28;
  uint local_24;
  void *local_20;
  
  iVar3 = FUN_002620a3(param_2);
  if (iVar3 == 0) {
    if ((param_6 & 0xfffffffffffffffe) == 0) {
      cVar2 = FUN_0025cd06(*(int *)(param_1 + 0x2e0) * 2);
      local_28 = 1 << (cVar2 + 1U & 0x1f);
      if (local_28 < 8) {
        local_28 = 8;
      }
      local_20 = *(void **)(param_1 + 0x2e8);
      if (*(uint *)(param_1 + 0x2e4) < local_28) {
        local_20 = realloc(local_20,(ulong)local_28 * 0x28);
        if (local_20 == (void *)0x0) {
          FUN_00260f71(param_2);
          return 0xffffffff;
        }
        memset((void *)((long)local_20 + (ulong)*(uint *)(param_1 + 0x2e4) * 0x28),0,
               (ulong)(local_28 - *(int *)(param_1 + 0x2e4)) * 0x28);
        *(uint *)(param_1 + 0x2e4) = local_28;
        *(void **)(param_1 + 0x2e8) = local_20;
      }
      uVar1 = *(uint *)(param_1 + 0x2e0);
      local_2c = uVar1;
      for (local_24 = 0; local_24 < uVar1; local_24 = local_24 + 1) {
        iVar3 = FUN_00262ee8(param_2,*(undefined8 *)((long)local_20 + (ulong)local_24 * 0x28));
        if ((iVar3 == 3) || (iVar3 == 1)) {
          uVar5 = FUN_00260eab();
          *(undefined8 *)((ulong)local_2c * 0x28 + (long)local_20) = uVar5;
          *(undefined4 *)((long)local_20 + (ulong)local_2c * 0x28 + 8) = 0xffffffff;
          *(undefined4 *)((long)local_20 + (ulong)local_2c * 0x28 + 0xc) = param_3;
          FUN_002626c1(*(undefined8 *)((long)local_20 + (ulong)local_2c * 0x28),param_2,
                       *(undefined8 *)((long)local_20 + (ulong)local_24 * 0x28));
          FUN_0025d0b2((void *)((long)local_20 + (ulong)local_2c * 0x28),
                       *(undefined8 *)((long)local_20 + (ulong)local_24 * 0x28 + 0x20),
                       *(undefined4 *)((long)local_20 + (ulong)local_24 * 0x28 + 0x18));
          FUN_0025d0b2((void *)((ulong)local_2c * 0x28 + (long)local_20),param_4,param_5);
          FUN_00262868(*(undefined8 *)((long)local_20 + (ulong)local_24 * 0x28),
                       *(undefined8 *)((long)local_20 + (ulong)local_24 * 0x28),
                       *(undefined8 *)((long)local_20 + (ulong)local_2c * 0x28));
          FUN_00262868(param_2,param_2,*(undefined8 *)((long)local_20 + (ulong)local_2c * 0x28));
          local_2c = local_2c + 1;
        }
        else if ((iVar3 == 2) || (iVar3 == 0)) {
          FUN_0025d0b2((void *)((ulong)local_24 * 0x28 + (long)local_20),param_4,param_5);
          if (((param_6 & 1) != 0) ||
             (*(int *)((long)local_20 + (ulong)local_24 * 0x28 + 0xc) == -1)) {
            *(undefined4 *)((long)local_20 + (ulong)local_24 * 0x28 + 0xc) = param_3;
          }
          FUN_00262868(param_2,param_2,*(undefined8 *)((long)local_20 + (ulong)local_24 * 0x28));
        }
        else if (iVar3 != 4) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("res == 4",
                        "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/cpukinds.c"
                        ,0xcf,"hwloc_internal_cpukinds_register");
        }
        iVar3 = FUN_002620a3(param_2);
        if (iVar3 != 0) break;
      }
      iVar3 = FUN_002620a3(param_2);
      if (iVar3 == 0) {
        *(undefined8 *)((ulong)local_2c * 0x28 + (long)local_20) = param_2;
        *(undefined4 *)((long)local_20 + (ulong)local_2c * 0x28 + 8) = 0xffffffff;
        *(undefined4 *)((long)local_20 + (ulong)local_2c * 0x28 + 0xc) = param_3;
        FUN_0025d0b2((void *)((ulong)local_2c * 0x28 + (long)local_20),param_4,param_5);
        local_2c = local_2c + 1;
      }
      else {
        FUN_00260f71(param_2);
      }
      *(uint *)(param_1 + 0x2e0) = local_2c;
      uVar5 = 0;
    }
    else {
      piVar4 = __errno_location();
      *piVar4 = 0x16;
      uVar5 = 0xffffffff;
    }
  }
  else {
    FUN_00260f71(param_2);
    piVar4 = __errno_location();
    *piVar4 = 0x16;
    uVar5 = 0xffffffff;
  }
  return uVar5;
}


// ===== 0025d71e FUN_0025d71e =====

undefined8 FUN_0025d71e(long param_1)

{
  uint local_10;
  uint local_c;
  
  local_c = 0;
  do {
    local_10 = local_c;
    if (*(uint *)(param_1 + 0x2e0) <= local_c) {
      return 0;
    }
    while (local_10 = local_10 + 1, local_10 < *(uint *)(param_1 + 0x2e0)) {
      if (*(long *)((ulong)local_c * 0x28 + *(long *)(param_1 + 0x2e8) + 0x10) ==
          *(long *)((ulong)local_10 * 0x28 + *(long *)(param_1 + 0x2e8) + 0x10)) {
        return 0xffffffff;
      }
    }
    local_c = local_c + 1;
  } while( true );
}


// ===== 0025d7bd FUN_0025d7bd =====

undefined8 FUN_0025d7bd(long param_1)

{
  undefined8 uVar1;
  uint local_c;
  
  FUN_0025cdbc("Trying to rank cpukinds by forced efficiency...\n");
  local_c = 0;
  while( true ) {
    if (*(uint *)(param_1 + 0x2e0) <= local_c) {
      uVar1 = FUN_0025d71e(param_1);
      return uVar1;
    }
    if (*(int *)((ulong)local_c * 0x28 + *(long *)(param_1 + 0x2e8) + 0xc) == -1) break;
    *(long *)(*(long *)(param_1 + 0x2e8) + (ulong)local_c * 0x28 + 0x10) =
         (long)*(int *)((ulong)local_c * 0x28 + *(long *)(param_1 + 0x2e8) + 0xc);
    local_c = local_c + 1;
  }
  return 0xffffffff;
}


// ===== 0025d87f FUN_0025d87f =====

void FUN_0025d87f(long param_1,undefined4 *param_2)

{
  int iVar1;
  long lVar2;
  undefined8 *puVar3;
  uint local_10;
  uint local_c;
  
  *param_2 = 1;
  param_2[1] = 1;
  param_2[2] = 1;
  for (local_c = 0; local_c < *(uint *)(param_1 + 0x2e0); local_c = local_c + 1) {
    lVar2 = (ulong)local_c * 0x28 + *(long *)(param_1 + 0x2e8);
    for (local_10 = 0; local_10 < *(uint *)(lVar2 + 0x18); local_10 = local_10 + 1) {
      puVar3 = (undefined8 *)(*(long *)(lVar2 + 0x20) + (ulong)local_10 * 0x10);
      iVar1 = strcmp((char *)*puVar3,"FrequencyMaxMHz");
      if (iVar1 == 0) {
        iVar1 = atoi((char *)puVar3[1]);
        *(int *)((ulong)local_c * 0xc + *(long *)(param_2 + 4) + 4) = iVar1;
      }
      else {
        iVar1 = strcmp((char *)*puVar3,"FrequencyBaseMHz");
        if (iVar1 == 0) {
          iVar1 = atoi((char *)puVar3[1]);
          *(int *)((ulong)local_c * 0xc + *(long *)(param_2 + 4) + 8) = iVar1;
        }
        else {
          iVar1 = strcmp((char *)*puVar3,"CoreType");
          if (iVar1 == 0) {
            iVar1 = strcmp((char *)puVar3[1],"IntelAtom");
            if (iVar1 == 0) {
              *(undefined4 *)((ulong)local_c * 0xc + *(long *)(param_2 + 4)) = 1;
            }
            else {
              iVar1 = strcmp((char *)puVar3[1],"IntelCore");
              if (iVar1 == 0) {
                *(undefined4 *)((ulong)local_c * 0xc + *(long *)(param_2 + 4)) = 2;
              }
            }
          }
        }
      }
    }
    FUN_0025cdbc("cpukind #%u has intel_core_type %u max_freq %u base_freq %u\n",local_c,
                 *(undefined4 *)((ulong)local_c * 0xc + *(long *)(param_2 + 4)),
                 *(undefined4 *)((ulong)local_c * 0xc + *(long *)(param_2 + 4) + 4),
                 *(undefined4 *)((ulong)local_c * 0xc + *(long *)(param_2 + 4) + 8));
    if (*(int *)((ulong)local_c * 0xc + *(long *)(param_2 + 4) + 8) == 0) {
      param_2[1] = 0;
    }
    if (*(int *)((ulong)local_c * 0xc + *(long *)(param_2 + 4) + 4) == 0) {
      *param_2 = 0;
    }
    if (*(int *)((ulong)local_c * 0xc + *(long *)(param_2 + 4)) == 0) {
      param_2[2] = 0;
    }
  }
  return;
}


// ===== 0025db5b FUN_0025db5b =====

undefined8 FUN_0025db5b(long param_1,int param_2,int *param_3)

{
  long lVar1;
  undefined8 uVar2;
  uint local_c;
  
  if (param_2 == 4) {
    FUN_0025cdbc("Trying to rank cpukinds by coretype+frequency_strict...\n");
    if ((param_3[2] == 0) || ((*param_3 == 0 && (param_3[1] == 0)))) {
      return 0xffffffff;
    }
    for (local_c = 0; local_c < *(uint *)(param_1 + 0x2e0); local_c = local_c + 1) {
      lVar1 = (ulong)local_c * 0x28 + *(long *)(param_1 + 0x2e8);
      if (param_3[1] == 0) {
        *(ulong *)(lVar1 + 0x10) =
             (ulong)(uint)(*(int *)((ulong)local_c * 0xc + *(long *)(param_3 + 4) + 4) +
                          *(int *)((ulong)local_c * 0xc + *(long *)(param_3 + 4)) * 0x100000);
      }
      else {
        *(ulong *)(lVar1 + 0x10) =
             (ulong)(uint)(*(int *)((ulong)local_c * 0xc + *(long *)(param_3 + 4) + 8) +
                          *(int *)((ulong)local_c * 0xc + *(long *)(param_3 + 4)) * 0x100000);
      }
    }
  }
  else if (param_2 == 3) {
    FUN_0025cdbc("Trying to rank cpukinds by coretype+frequency...\n");
    if (((param_3[2] == 0) && (*param_3 == 0)) && (param_3[1] == 0)) {
      return 0xffffffff;
    }
    for (local_c = 0; local_c < *(uint *)(param_1 + 0x2e0); local_c = local_c + 1) {
      lVar1 = (ulong)local_c * 0x28 + *(long *)(param_1 + 0x2e8);
      if (param_3[1] == 0) {
        *(ulong *)(lVar1 + 0x10) =
             (ulong)(uint)(*(int *)((ulong)local_c * 0xc + *(long *)(param_3 + 4) + 4) +
                          *(int *)((ulong)local_c * 0xc + *(long *)(param_3 + 4)) * 0x100000);
      }
      else {
        *(ulong *)(lVar1 + 0x10) =
             (ulong)(uint)(*(int *)((ulong)local_c * 0xc + *(long *)(param_3 + 4) + 8) +
                          *(int *)((ulong)local_c * 0xc + *(long *)(param_3 + 4)) * 0x100000);
      }
    }
  }
  else if (param_2 == 5) {
    FUN_0025cdbc("Trying to rank cpukinds by coretype...\n");
    if (param_3[2] == 0) {
      return 0xffffffff;
    }
    for (local_c = 0; local_c < *(uint *)(param_1 + 0x2e0); local_c = local_c + 1) {
      *(ulong *)((ulong)local_c * 0x28 + *(long *)(param_1 + 0x2e8) + 0x10) =
           (ulong)(uint)(*(int *)((ulong)local_c * 0xc + *(long *)(param_3 + 4)) << 0x14);
    }
  }
  else if (param_2 == 6) {
    FUN_0025cdbc("Trying to rank cpukinds by frequency...\n");
    if ((*param_3 == 0) && (param_3[1] == 0)) {
      return 0xffffffff;
    }
    for (local_c = 0; local_c < *(uint *)(param_1 + 0x2e0); local_c = local_c + 1) {
      lVar1 = (ulong)local_c * 0x28 + *(long *)(param_1 + 0x2e8);
      if (param_3[1] == 0) {
        *(ulong *)(lVar1 + 0x10) =
             (ulong)*(uint *)((ulong)local_c * 0xc + *(long *)(param_3 + 4) + 4);
      }
      else {
        *(ulong *)(lVar1 + 0x10) =
             (ulong)*(uint *)((ulong)local_c * 0xc + *(long *)(param_3 + 4) + 8);
      }
    }
  }
  else if (param_2 == 7) {
    FUN_0025cdbc("Trying to rank cpukinds by frequency max...\n");
    if (*param_3 == 0) {
      return 0xffffffff;
    }
    for (local_c = 0; local_c < *(uint *)(param_1 + 0x2e0); local_c = local_c + 1) {
      *(ulong *)((ulong)local_c * 0x28 + *(long *)(param_1 + 0x2e8) + 0x10) =
           (ulong)*(uint *)((ulong)local_c * 0xc + *(long *)(param_3 + 4) + 4);
    }
  }
  else {
    if (param_2 != 8) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("0",
                    "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/cpukinds.c"
                    ,0x1ba,"hwloc__cpukinds_try_rank_by_info");
    }
    FUN_0025cdbc("Trying to rank cpukinds by frequency base...\n");
    if (param_3[1] == 0) {
      return 0xffffffff;
    }
    for (local_c = 0; local_c < *(uint *)(param_1 + 0x2e0); local_c = local_c + 1) {
      *(ulong *)((ulong)local_c * 0x28 + *(long *)(param_1 + 0x2e8) + 0x10) =
           (ulong)*(uint *)((ulong)local_c * 0xc + *(long *)(param_3 + 4) + 8);
    }
  }
  uVar2 = FUN_0025d71e(param_1);
  return uVar2;
}


// ===== 0025e0b9 FUN_0025e0b9 =====

ulong FUN_0025e0b9(long param_1,long param_2)

{
  ulong uVar1;
  
  if (*(ulong *)(param_1 + 0x10) < *(ulong *)(param_2 + 0x10)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (ulong)(*(ulong *)(param_2 + 0x10) < *(ulong *)(param_1 + 0x10));
  }
  return uVar1;
}


// ===== 0025e10e FUN_0025e10e =====

void FUN_0025e10e(long param_1)

{
  uint local_c;
  
  qsort(*(void **)(param_1 + 0x2e8),(ulong)*(uint *)(param_1 + 0x2e0),0x28,FUN_0025e0b9);
  for (local_c = 0; local_c < *(uint *)(param_1 + 0x2e0); local_c = local_c + 1) {
    *(uint *)(*(long *)(param_1 + 0x2e8) + (ulong)local_c * 0x28 + 8) = local_c;
  }
  return;
}


// ===== 0025e18a FUN_0025e18a =====

undefined8 FUN_0025e18a(long param_1)

{
  int iVar1;
  undefined1 local_58 [16];
  void *local_48;
  undefined1 local_38 [16];
  void *local_28;
  int local_1c;
  char *local_18;
  uint local_10;
  int local_c;
  
  if (*(int *)(param_1 + 0x2e0) == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x2e0) == 1) {
    *(undefined4 *)(*(long *)(param_1 + 0x2e8) + 8) = 0;
    return 0;
  }
  local_c = 0;
  local_18 = getenv("HWLOC_CPUKINDS_RANKING");
  if (local_18 != (char *)0x0) {
    iVar1 = strcmp(local_18,"default");
    if (iVar1 == 0) {
      local_c = 0;
    }
    else {
      iVar1 = strcmp(local_18,"none");
      if (iVar1 == 0) {
        local_c = 9;
      }
      else {
        iVar1 = strcmp(local_18,"coretype+frequency");
        if (iVar1 == 0) {
          local_c = 3;
        }
        else {
          iVar1 = strcmp(local_18,"coretype+frequency_strict");
          if (iVar1 == 0) {
            local_c = 4;
          }
          else {
            iVar1 = strcmp(local_18,"coretype");
            if (iVar1 == 0) {
              local_c = 5;
            }
            else {
              iVar1 = strcmp(local_18,"frequency");
              if (iVar1 == 0) {
                local_c = 6;
              }
              else {
                iVar1 = strcmp(local_18,"frequency_max");
                if (iVar1 == 0) {
                  local_c = 7;
                }
                else {
                  iVar1 = strcmp(local_18,"frequency_base");
                  if (iVar1 == 0) {
                    local_c = 8;
                  }
                  else {
                    iVar1 = strcmp(local_18,"forced_efficiency");
                    if (iVar1 == 0) {
                      local_c = 2;
                    }
                    else {
                      iVar1 = strcmp(local_18,"no_forced_efficiency");
                      if (iVar1 == 0) {
                        local_c = 1;
                      }
                      else {
                        iVar1 = FUN_0024d64f();
                        if (iVar1 < 2) {
                          fprintf(*(FILE **)PTR_stderr_0032efe0,
                                  "hwloc: Failed to recognize HWLOC_CPUKINDS_RANKING value %s\n",
                                  local_18);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ((local_c == 0) || (local_c == 1)) {
    if (local_c == 0) {
      FUN_0025cdbc("Using default ranking strategy...\n");
    }
    else {
      FUN_0025cdbc("Using custom ranking strategy from HWLOC_CPUKINDS_RANKING=%s\n",local_18);
    }
    if ((local_c != 1) && (local_1c = FUN_0025d7bd(param_1), local_1c == 0)) {
      local_1c = 0;
      goto LAB_0025e578;
    }
    local_28 = calloc((ulong)*(uint *)(param_1 + 0x2e0),0xc);
    if (local_28 == (void *)0x0) goto LAB_0025e51a;
    FUN_0025d87f(param_1,local_38);
    local_1c = FUN_0025db5b(param_1,3,local_38);
    free(local_28);
  }
  else {
    if (local_c == 2) {
      FUN_0025cdbc("Using custom ranking strategy from HWLOC_CPUKINDS_RANKING=%s\n",local_18);
      local_1c = FUN_0025d7bd(param_1);
      if (local_1c == 0) {
        local_1c = 0;
        goto LAB_0025e578;
      }
      goto LAB_0025e51a;
    }
    if (local_c == 9) goto LAB_0025e51a;
    FUN_0025cdbc("Using custom ranking strategy from HWLOC_CPUKINDS_RANKING=%s\n",local_18);
    local_48 = calloc((ulong)*(uint *)(param_1 + 0x2e0),0xc);
    if (local_48 == (void *)0x0) goto LAB_0025e51a;
    FUN_0025d87f(param_1,local_58);
    local_1c = FUN_0025db5b(param_1,local_c,local_58);
    free(local_48);
  }
  if (local_1c == 0) {
LAB_0025e578:
    for (local_10 = 0; local_10 < *(uint *)(param_1 + 0x2e0); local_10 = local_10 + 1) {
      FUN_0025cdbc("cpukind #%u got ranking value %llu\n",local_10,
                   *(undefined8 *)((ulong)local_10 * 0x28 + *(long *)(param_1 + 0x2e8) + 0x10));
    }
    FUN_0025e10e(param_1);
    FUN_0025cdbc(&DAT_002ec96c);
    return 0;
  }
LAB_0025e51a:
  for (local_10 = 0; local_10 < *(uint *)(param_1 + 0x2e0); local_10 = local_10 + 1) {
    *(undefined4 *)((ulong)local_10 * 0x28 + *(long *)(param_1 + 0x2e8) + 8) = 0xffffffff;
  }
  FUN_0025cdbc("Failed to rank cpukinds.\n\n");
  return 0;
}


// ===== 0025e5f1 FUN_0025e5f1 =====

undefined8 FUN_0025e5f1(undefined8 *param_1,undefined *param_2)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  size_t sVar4;
  long *local_20;
  
  iVar1 = strcmp((char *)*param_1,"stop");
  if (iVar1 == 0) {
    if (DAT_01218304 != 0) {
      fwrite("hwloc: Cannot register discovery component with reserved name `stop\'\n",1,0x45,
             *(FILE **)PTR_stderr_0032efe0);
    }
  }
  else {
    pcVar2 = strchr((char *)*param_1,0x2d);
    if ((pcVar2 == (char *)0x0) && (pcVar2 = strchr((char *)*param_1,0x3a), pcVar2 == (char *)0x0))
    {
      sVar3 = strcspn((char *)*param_1,",");
      sVar4 = strlen((char *)*param_1);
      if (sVar3 == sVar4) {
        if ((*(int *)(param_1 + 1) != 0) &&
           ((*(int *)(param_1 + 1) == 1 || ((*(uint *)(param_1 + 1) & 0xffffff01) == 0)))) {
          local_20 = &DAT_012182f8;
          do {
            if (*local_20 == 0) {
              if (DAT_01218304 != 0) {
                if (param_2 == (undefined *)0x0) {
                  param_2 = &DAT_002ecbb3;
                  pcVar2 = "statically build";
                }
                else {
                  pcVar2 = "from plugin ";
                }
                fprintf(*(FILE **)PTR_stderr_0032efe0,
                        "hwloc: Registered discovery component `%s\' phases 0x%x with priority %u (%s%s)\n"
                        ,*param_1,(ulong)*(uint *)(param_1 + 1),(ulong)*(uint *)(param_1 + 3),pcVar2
                        ,param_2);
              }
              for (local_20 = &DAT_012182f8;
                  (*local_20 != 0 && (*(uint *)(param_1 + 3) <= *(uint *)(*local_20 + 0x18)));
                  local_20 = (long *)(*local_20 + 0x20)) {
              }
              param_1[4] = *local_20;
              *local_20 = (long)param_1;
              return 0;
            }
            iVar1 = strcmp(*(char **)*local_20,(char *)*param_1);
            if (iVar1 == 0) {
              if (*(uint *)(param_1 + 3) <= *(uint *)(*local_20 + 0x18)) {
                if (DAT_01218304 != 0) {
                  fprintf(*(FILE **)PTR_stderr_0032efe0,
                          "hwloc: Ignoring new discovery component `%s\', priority %u lower than previously registered one %u\n"
                          ,*param_1,(ulong)*(uint *)(param_1 + 3),(ulong)*(uint *)(*local_20 + 0x18)
                         );
                }
                return 0xffffffff;
              }
              if (DAT_01218304 != 0) {
                fprintf(*(FILE **)PTR_stderr_0032efe0,
                        "hwloc: Dropping previously registered discovery component `%s\', priority %u lower than new one %u\n"
                        ,*(undefined8 *)*local_20,(ulong)*(uint *)(*local_20 + 0x18),
                        (ulong)*(uint *)(param_1 + 3));
              }
              *local_20 = *(long *)(*local_20 + 0x20);
            }
            local_20 = (long *)(*local_20 + 0x20);
          } while( true );
        }
        iVar1 = FUN_0024d64f();
        if (iVar1 < 2) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,
                  "hwloc: Cannot register discovery component `%s\' with invalid phases 0x%x\n",
                  *param_1,(ulong)*(uint *)(param_1 + 1));
        }
        return 0xffffffff;
      }
    }
    if (DAT_01218304 != 0) {
      fprintf(*(FILE **)PTR_stderr_0032efe0,
              "hwloc: Cannot register discovery component with name `%s\' containing reserved characters `%c,\'\n"
              ,*param_1,0x2d);
    }
  }
  return 0xffffffff;
}


// ===== 0025e93d FUN_0025e93d =====

void FUN_0025e93d(void)

{
  int iVar1;
  char *__nptr;
  ulong uVar2;
  uint local_c;
  
  pthread_mutex_lock((pthread_mutex_t *)&DAT_01218320);
  if (DAT_01218300 == -1) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("(unsigned) -1 != hwloc_components_users",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/components.c"
                  ,0x1be,"hwloc_components_init");
  }
  if (DAT_01218300 == 0) {
    DAT_01218300 = DAT_01218300 + 1;
    __nptr = getenv("HWLOC_COMPONENTS_VERBOSE");
    if (__nptr == (char *)0x0) {
      DAT_01218304 = 0;
    }
    else {
      DAT_01218304 = atoi(__nptr);
    }
    DAT_01218348 = (void *)0x0;
    DAT_01218350 = 0;
    for (local_c = 0; (&PTR_DAT_003805c0)[local_c] != (undefined *)0x0; local_c = local_c + 1) {
      DAT_01218350 = DAT_01218350 + 1;
    }
    if (DAT_01218350 != 0) {
      DAT_01218348 = calloc((ulong)DAT_01218350,8);
      if (DAT_01218348 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("hwloc_component_finalize_cbs",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/components.c"
                      ,0x1d7,"hwloc_components_init");
      }
      DAT_01218350 = 0;
    }
    for (local_c = 0; (&PTR_DAT_003805c0)[local_c] != (undefined *)0x0; local_c = local_c + 1) {
      if (*(long *)((&PTR_DAT_003805c0)[local_c] + 0x20) == 0) {
        if ((*(long *)((&PTR_DAT_003805c0)[local_c] + 8) == 0) ||
           (iVar1 = (**(code **)((&PTR_DAT_003805c0)[local_c] + 8))(0), -1 < iVar1)) {
          if (*(long *)((&PTR_DAT_003805c0)[local_c] + 0x10) != 0) {
            uVar2 = (ulong)DAT_01218350;
            DAT_01218350 = DAT_01218350 + 1;
            *(undefined8 *)((long)DAT_01218348 + uVar2 * 8) =
                 *(undefined8 *)((&PTR_DAT_003805c0)[local_c] + 0x10);
          }
          if (*(int *)((&PTR_DAT_003805c0)[local_c] + 0x18) == 0) {
            FUN_0025e5f1(*(undefined8 *)((&PTR_DAT_003805c0)[local_c] + 0x28),0);
          }
          else {
            if (*(int *)((&PTR_DAT_003805c0)[local_c] + 0x18) != 1) {
                    /* WARNING: Subroutine does not return */
              __assert_fail("0",
                            "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/components.c"
                            ,0x1f5,"hwloc_components_init");
            }
            FUN_00268f1e(*(undefined8 *)((&PTR_DAT_003805c0)[local_c] + 0x28));
          }
        }
        else if (DAT_01218304 != 0) {
          fwrite("hwloc: Ignoring static component, failed to initialize\n",1,0x37,
                 *(FILE **)PTR_stderr_0032efe0);
        }
      }
      else {
        iVar1 = FUN_0024d64f();
        if (iVar1 < 2) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,
                  "hwloc: Ignoring static component with invalid flags %lx\n",
                  *(undefined8 *)((&PTR_DAT_003805c0)[local_c] + 0x20));
        }
      }
    }
    pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218320);
  }
  else {
    DAT_01218300 = DAT_01218300 + 1;
    pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218320);
  }
  return;
}


// ===== 0025ec9e FUN_0025ec9e =====

void FUN_0025ec9e(long param_1)

{
  *(undefined4 *)(param_1 + 0x368) = 0;
  *(undefined8 *)(param_1 + 0x370) = 0;
  *(undefined8 *)(param_1 + 0x318) = 0;
  *(undefined4 *)(param_1 + 0x328) = 0;
  *(undefined4 *)(param_1 + 0x32c) = 0;
  return;
}


// ===== 0025ecf1 FUN_0025ecf1 =====

undefined8 * FUN_0025ecf1(char *param_1,long *param_2)

{
  int iVar1;
  char *pcVar2;
  size_t local_18;
  undefined8 *local_10;
  
  pcVar2 = strchr(param_1,0x3a);
  if (pcVar2 == (char *)0x0) {
    local_18 = strlen(param_1);
    if (param_2 != (long *)0x0) {
      *param_2 = 0;
    }
  }
  else {
    local_18 = (long)pcVar2 - (long)param_1;
    if (param_2 != (long *)0x0) {
      *param_2 = (long)(pcVar2 + 1);
    }
  }
  local_10 = DAT_012182f8;
  while( true ) {
    if (local_10 == (undefined8 *)0x0) {
      return (undefined8 *)0x0;
    }
    iVar1 = strncmp(param_1,(char *)*local_10,local_18);
    if (iVar1 == 0) break;
    local_10 = (undefined8 *)local_10[4];
  }
  return local_10;
}


// ===== 0025edb4 FUN_0025edb4 =====

ulong FUN_0025edb4(char *param_1)

{
  int iVar1;
  ulong uVar2;
  
  if (param_1 == (char *)0x0) {
    uVar2 = 0xffffffff;
  }
  else if ((*param_1 < '0') || ('9' < *param_1)) {
    iVar1 = strcasecmp(param_1,"global");
    if (iVar1 == 0) {
      uVar2 = 1;
    }
    else {
      iVar1 = strcasecmp(param_1,"cpu");
      if (iVar1 == 0) {
        uVar2 = 2;
      }
      else {
        iVar1 = strcasecmp(param_1,"memory");
        if (iVar1 == 0) {
          uVar2 = 4;
        }
        else {
          iVar1 = strcasecmp(param_1,"pci");
          if (iVar1 == 0) {
            uVar2 = 8;
          }
          else {
            iVar1 = strcasecmp(param_1,"io");
            if (iVar1 == 0) {
              uVar2 = 0x10;
            }
            else {
              iVar1 = strcasecmp(param_1,"misc");
              if (iVar1 == 0) {
                uVar2 = 0x20;
              }
              else {
                iVar1 = strcasecmp(param_1,"annotate");
                if (iVar1 == 0) {
                  uVar2 = 0x40;
                }
                else {
                  iVar1 = strcasecmp(param_1,"tweak");
                  if (iVar1 == 0) {
                    uVar2 = 0x80;
                  }
                  else {
                    uVar2 = 0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    uVar2 = strtoul(param_1,(char **)0x0,0);
  }
  return uVar2;
}


// ===== 0025ef06 FUN_0025ef06 =====

undefined8 FUN_0025ef06(long param_1,char *param_2)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  void *pvVar4;
  undefined8 local_28 [2];
  uint local_18;
  uint local_14;
  undefined8 *local_10;
  
  iVar1 = strcmp(param_2,"linuxpci");
  if ((iVar1 == 0) || (iVar1 = strcmp(param_2,"linuxio"), iVar1 == 0)) {
    if (DAT_01218304 != 0) {
      fprintf(*(FILE **)PTR_stderr_0032efe0,
              "hwloc: Replacing deprecated component `%s\' with `linux\' IO phases in blacklisting\n"
              ,param_2);
    }
    local_10 = (undefined8 *)FUN_0025ecf1("linux",0);
    local_14 = 0x78;
  }
  else {
    local_10 = (undefined8 *)FUN_0025ecf1(param_2,local_28);
    local_14 = FUN_0025edb4(local_28[0]);
  }
  if (local_10 == (undefined8 *)0x0) {
    piVar2 = __errno_location();
    *piVar2 = 0x16;
    uVar3 = 0xffffffff;
  }
  else {
    if (DAT_01218304 != 0) {
      fprintf(*(FILE **)PTR_stderr_0032efe0,"hwloc: Blacklisting component `%s` phases 0x%x\n",
              *local_10,(ulong)local_14);
    }
    for (local_18 = 0; local_18 < *(uint *)(param_1 + 0x368); local_18 = local_18 + 1) {
      if (local_10 == *(undefined8 **)(*(long *)(param_1 + 0x370) + (ulong)local_18 * 0x10)) {
        *(uint *)(*(long *)(param_1 + 0x370) + (ulong)local_18 * 0x10 + 8) =
             *(uint *)(*(long *)(param_1 + 0x370) + (ulong)local_18 * 0x10 + 8) | local_14;
        return 0;
      }
    }
    pvVar4 = realloc(*(void **)(param_1 + 0x370),(ulong)(*(int *)(param_1 + 0x368) + 1) << 4);
    if (pvVar4 == (void *)0x0) {
      uVar3 = 0xffffffff;
    }
    else {
      *(undefined8 **)((ulong)*(uint *)(param_1 + 0x368) * 0x10 + (long)pvVar4) = local_10;
      *(uint *)((long)pvVar4 + (ulong)*(uint *)(param_1 + 0x368) * 0x10 + 8) = local_14;
      *(void **)(param_1 + 0x370) = pvVar4;
      *(int *)(param_1 + 0x368) = *(int *)(param_1 + 0x368) + 1;
      uVar3 = 0;
    }
  }
  return uVar3;
}


// ===== 0025f125 FUN_0025f125 =====

undefined4
FUN_0025f125(long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5,undefined8 param_6)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  long lVar4;
  long lVar5;
  char *__nptr;
  
  if (*(int *)(param_1 + 0xcc) == 0) {
    lVar4 = FUN_0025ecf1(param_3,0);
    if (lVar4 == 0) {
      piVar3 = __errno_location();
      *piVar3 = 0x26;
      uVar1 = 0xffffffff;
    }
    else {
      lVar5 = (**(code **)(lVar4 + 0x10))(param_1,lVar4,0,param_4,param_5,param_6);
      if (lVar5 == 0) {
        uVar1 = 0xffffffff;
      }
      else {
        *(undefined4 *)(lVar5 + 0x10) = param_2;
        if (*(long *)(param_1 + 0x318) != 0) {
          FUN_0025fe51(param_1);
        }
        uVar1 = FUN_0025fab7(lVar5);
        if (((*(int *)(lVar4 + 8) == 1) &&
            (__nptr = getenv("HWLOC_ANNOTATE_GLOBAL_COMPONENTS"), __nptr != (char *)0x0)) &&
           (iVar2 = atoi(__nptr), iVar2 != 0)) {
          *(uint *)(param_1 + 0x32c) = *(uint *)(param_1 + 0x32c) & 0xffffffbf;
        }
      }
    }
  }
  else {
    piVar3 = __errno_location();
    *piVar3 = 0x10;
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ===== 0025f260 FUN_0025f260 =====

undefined8 FUN_0025f260(long param_1,undefined8 *param_2,int param_3,uint param_4)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  if ((~(*(uint *)(param_1 + 0x32c) | param_4) & *(uint *)(param_2 + 1)) == 0) {
    if (DAT_01218304 != 0) {
      fprintf(*(FILE **)PTR_stderr_0032efe0,
              "hwloc: Excluding discovery component `%s\' phases 0x%x, conflicts with excludes 0x%x\n"
              ,*param_2,(ulong)*(uint *)(param_2 + 1),(ulong)*(uint *)(param_1 + 0x32c));
    }
    return 0xffffffff;
  }
  lVar2 = (*(code *)param_2[2])(param_1,param_2,*(uint *)(param_1 + 0x32c) | param_4,0,0,0);
  if (lVar2 == 0) {
    if ((DAT_01218304 != 0) || ((param_3 != 0 && (iVar1 = FUN_0024d64f(), iVar1 < 2)))) {
      fprintf(*(FILE **)PTR_stderr_0032efe0,
              "hwloc: Failed to instantiate discovery component `%s\'\n",*param_2);
    }
    return 0xffffffff;
  }
  *(uint *)(lVar2 + 0x20) = ~param_4 & *(uint *)(lVar2 + 0x20);
  *(int *)(lVar2 + 0x10) = param_3;
  uVar3 = FUN_0025fab7(lVar2);
  return uVar3;
}


// ===== 0025f38d FUN_0025f38d =====

void FUN_0025f38d(long param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  size_t sVar5;
  long lVar6;
  undefined *puVar7;
  uint local_40;
  uint local_3c;
  char *local_38;
  char *local_30;
  char *local_28;
  uint local_20;
  undefined8 *local_18;
  undefined8 *local_10;
  
  bVar2 = true;
  pcVar4 = getenv("HWLOC_COMPONENTS");
  if (pcVar4 == (char *)0x0) {
    pcVar4 = (char *)0x0;
  }
  else {
    pcVar4 = strdup(pcVar4);
  }
  local_28 = pcVar4;
  if (pcVar4 != (char *)0x0) {
    while (*local_28 != '\0') {
      sVar5 = strcspn(local_28,",");
      if ((sVar5 != 0) && (*local_28 == '-')) {
        cVar1 = local_28[sVar5];
        local_28[sVar5] = '\0';
        FUN_0025ef06(param_1,local_28 + 1);
        for (local_20 = 0; local_20 < sVar5; local_20 = local_20 + 1) {
          local_28[local_20] = ',';
        }
        local_28[sVar5] = cVar1;
      }
      local_28 = local_28 + sVar5;
      if (*local_28 != '\0') {
        local_28 = local_28 + 1;
      }
    }
  }
  local_30 = pcVar4;
  if (pcVar4 != (char *)0x0) {
    while (*local_30 != '\0') {
      sVar5 = strcspn(local_30,",");
      if (sVar5 != 0) {
        iVar3 = strncmp(local_30,"stop",sVar5);
        if (iVar3 == 0) {
          bVar2 = false;
          break;
        }
        cVar1 = local_30[sVar5];
        local_30[sVar5] = '\0';
        local_38 = local_30;
        iVar3 = strcmp(local_30,"linuxpci");
        if ((iVar3 == 0) || (iVar3 = strcmp(local_30,"linuxio"), iVar3 == 0)) {
          if (DAT_01218304 != 0) {
            fprintf(*(FILE **)PTR_stderr_0032efe0,
                    "hwloc: Replacing deprecated component `%s\' with `linux\' in envvar forcing\n",
                    local_30);
          }
          local_38 = "linux";
        }
        lVar6 = FUN_0025ecf1(local_38,0);
        if (lVar6 == 0) {
          iVar3 = FUN_0024d64f();
          if (iVar3 < 2) {
            fprintf(*(FILE **)PTR_stderr_0032efe0,"hwloc: Cannot find discovery component `%s\'\n",
                    local_38);
          }
        }
        else {
          local_3c = 0;
          for (local_20 = 0; local_20 < *(uint *)(param_1 + 0x368); local_20 = local_20 + 1) {
            if (lVar6 == *(long *)(*(long *)(param_1 + 0x370) + (ulong)local_20 * 0x10)) {
              local_3c = *(uint *)(*(long *)(param_1 + 0x370) + (ulong)local_20 * 0x10 + 8);
              break;
            }
          }
          if ((*(uint *)(lVar6 + 8) & ~local_3c) != 0) {
            FUN_0025f260(param_1,lVar6,1,local_3c);
          }
        }
        local_30[sVar5] = cVar1;
      }
      local_30 = local_30 + sVar5;
      if (*local_30 != '\0') {
        local_30 = local_30 + 1;
      }
    }
  }
  if (bVar2) {
    for (local_10 = DAT_012182f8; local_10 != (undefined8 *)0x0;
        local_10 = (undefined8 *)local_10[4]) {
      local_40 = 0;
      if (*(int *)((long)local_10 + 0x1c) != 0) {
        for (local_20 = 0; local_20 < *(uint *)(param_1 + 0x368); local_20 = local_20 + 1) {
          if (local_10 == *(undefined8 **)(*(long *)(param_1 + 0x370) + (ulong)local_20 * 0x10)) {
            local_40 = *(uint *)(*(long *)(param_1 + 0x370) + (ulong)local_20 * 0x10 + 8);
            break;
          }
        }
        if ((*(uint *)(local_10 + 1) & ~local_40) == 0) {
          if (DAT_01218304 != 0) {
            fprintf(*(FILE **)PTR_stderr_0032efe0,
                    "hwloc: Excluding blacklisted discovery component `%s\' phases 0x%x\n",*local_10
                    ,(ulong)*(uint *)(local_10 + 1));
          }
        }
        else {
          FUN_0025f260(param_1,local_10,0,local_40);
        }
      }
    }
  }
  if (DAT_01218304 != 0) {
    bVar2 = true;
    local_18 = *(undefined8 **)(param_1 + 0x318);
    fwrite("hwloc: Final list of enabled discovery components: ",1,0x33,
           *(FILE **)PTR_stderr_0032efe0);
    for (; local_18 != (undefined8 *)0x0; local_18 = (undefined8 *)local_18[3]) {
      if (bVar2) {
        puVar7 = &DAT_002ecbb3;
      }
      else {
        puVar7 = &DAT_002eca36;
      }
      fprintf(*(FILE **)PTR_stderr_0032efe0,"%s%s(0x%x)",puVar7,*(undefined8 *)*local_18,
              (ulong)*(uint *)(local_18 + 4));
      bVar2 = false;
    }
    fputc(10,*(FILE **)PTR_stderr_0032efe0);
  }
  free(pcVar4);
  return;
}


// ===== 0025f883 FUN_0025f883 =====

void FUN_0025f883(void)

{
  uint local_c;
  
  pthread_mutex_lock((pthread_mutex_t *)&DAT_01218320);
  if (DAT_01218300 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("0 != hwloc_components_users",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/components.c"
                  ,0x388,"hwloc_components_fini");
  }
  DAT_01218300 = DAT_01218300 + -1;
  if (DAT_01218300 == 0) {
    for (local_c = 0; local_c < DAT_01218350; local_c = local_c + 1) {
      (**(code **)((ulong)((DAT_01218350 - local_c) - 1) * 8 + (long)DAT_01218348))(0);
    }
    free(DAT_01218348);
    DAT_01218348 = (void *)0x0;
    DAT_01218350 = 0;
    DAT_012182f8 = 0;
    FUN_00268f5e();
    pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218320);
  }
  else {
    pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218320);
  }
  return;
}


// ===== 0025f967 FUN_0025f967 =====

undefined8 * FUN_0025f967(long param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  int *piVar2;
  
  puVar1 = malloc(0x58);
  if (puVar1 == (undefined8 *)0x0) {
    piVar2 = __errno_location();
    *piVar2 = 0xc;
    puVar1 = (undefined8 *)0x0;
  }
  else {
    *puVar1 = param_2;
    puVar1[1] = param_1;
    *(uint *)(puVar1 + 4) = *(uint *)(param_2 + 1) & ~*(uint *)(param_1 + 0x32c);
    if ((*(int *)(puVar1 + 4) != *(int *)(param_2 + 1)) && (DAT_01218304 != 0)) {
      fprintf(*(FILE **)PTR_stderr_0032efe0,
              "hwloc: Trying discovery component `%s\' with phases 0x%x instead of 0x%x\n",*param_2,
              (ulong)*(uint *)(puVar1 + 4),(ulong)*(uint *)(param_2 + 1));
    }
    puVar1[5] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[8] = 0;
    *(undefined4 *)(puVar1 + 6) = 0xffffffff;
    puVar1[3] = 0;
    *(undefined4 *)(puVar1 + 2) = 0;
  }
  return puVar1;
}


// ===== 0025fa7e FUN_0025fa7e =====

void FUN_0025fa7e(void *param_1)

{
  if (*(long *)((long)param_1 + 0x40) != 0) {
    (**(code **)((long)param_1 + 0x40))(param_1);
  }
  free(param_1);
  return;
}


// ===== 0025fab7 FUN_0025fab7 =====

undefined8 FUN_0025fab7(long *param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  int *piVar4;
  long *local_10;
  
  lVar1 = param_1[1];
  if (param_1[5] == 0) {
    for (local_10 = (long *)(lVar1 + 0x318); *local_10 != 0; local_10 = (long *)(*local_10 + 0x18))
    {
      if (*(long *)*local_10 == *param_1) {
        if (DAT_01218304 != 0) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,
                  "hwloc: Cannot enable  discovery component `%s\' phases 0x%x twice\n",
                  *(undefined8 *)*param_1,(ulong)*(uint *)(*param_1 + 8));
        }
        FUN_0025fa7e(param_1);
        piVar4 = __errno_location();
        *piVar4 = 0x10;
        return 0xffffffff;
      }
    }
    if (DAT_01218304 != 0) {
      fprintf(*(FILE **)PTR_stderr_0032efe0,
              "hwloc: Enabling discovery component `%s\' with phases 0x%x (among 0x%x)\n",
              *(undefined8 *)*param_1,(ulong)*(uint *)(param_1 + 4),(ulong)*(uint *)(*param_1 + 8));
    }
    for (local_10 = (long *)(lVar1 + 0x318); *local_10 != 0; local_10 = (long *)(*local_10 + 0x18))
    {
    }
    param_1[3] = *local_10;
    *local_10 = (long)param_1;
    *(uint *)(lVar1 + 0x328) = *(uint *)(lVar1 + 0x328) | *(uint *)(*param_1 + 8);
    *(uint *)(lVar1 + 0x32c) = *(uint *)(lVar1 + 0x32c) | *(uint *)(*param_1 + 0xc);
    uVar3 = 0;
  }
  else {
    iVar2 = FUN_0024d64f();
    if (iVar2 < 2) {
      fprintf(*(FILE **)PTR_stderr_0032efe0,
              "hwloc: Cannot enable discovery component `%s\' phases 0x%x with unknown flags %lx\n",
              *(undefined8 *)*param_1,(ulong)*(uint *)(*param_1 + 8),param_1[5]);
    }
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ===== 0025fca4 FUN_0025fca4 =====

void FUN_0025fca4(long param_1)

{
  int iVar1;
  char *__nptr;
  long local_10;
  
  *(undefined4 *)(param_1 + 200) = 1;
  for (local_10 = *(long *)(param_1 + 0x318); local_10 != 0; local_10 = *(long *)(local_10 + 0x18))
  {
    if ((*(int *)(local_10 + 0x10) == 0) && (*(int *)(local_10 + 0x30) != -1)) {
      if (*(int *)(local_10 + 0x30) != 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("backend->is_thissystem == 0",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/components.c"
                      ,0x401,"hwloc_backends_is_thissystem");
      }
      *(undefined4 *)(param_1 + 200) = 0;
    }
  }
  if ((*(ulong *)(param_1 + 0x20) & 2) != 0) {
    *(undefined4 *)(param_1 + 200) = 1;
  }
  local_10 = *(long *)(param_1 + 0x318);
  do {
    if (local_10 == 0) {
      __nptr = getenv("HWLOC_THISSYSTEM");
      if (__nptr != (char *)0x0) {
        iVar1 = atoi(__nptr);
        *(int *)(param_1 + 200) = iVar1;
      }
      return;
    }
    if ((*(int *)(local_10 + 0x10) == 1) && (*(int *)(local_10 + 0x30) != -1)) {
      if (*(int *)(local_10 + 0x30) != 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("backend->is_thissystem == 0",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/components.c"
                      ,0x40f,"hwloc_backends_is_thissystem");
      }
      *(undefined4 *)(param_1 + 200) = 0;
    }
    local_10 = *(long *)(local_10 + 0x18);
  } while( true );
}


// ===== 0025fdf5 FUN_0025fdf5 =====

void FUN_0025fdf5(long param_1)

{
  long local_10;
  
  local_10 = *(long *)(param_1 + 0x318);
  *(undefined8 *)(param_1 + 800) = 0;
  while( true ) {
    if (local_10 == 0) {
      return;
    }
    if (*(long *)(local_10 + 0x50) != 0) break;
    local_10 = *(long *)(local_10 + 0x18);
  }
  *(long *)(param_1 + 800) = local_10;
  return;
}


// ===== 0025fe51 FUN_0025fe51 =====

void FUN_0025fe51(long param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  while (puVar2 = *(undefined8 **)(param_1 + 0x318), puVar2 != (undefined8 *)0x0) {
    uVar1 = puVar2[3];
    if (DAT_01218304 != 0) {
      fprintf(*(FILE **)PTR_stderr_0032efe0,"hwloc: Disabling discovery component `%s\'\n",
              *(undefined8 *)*puVar2);
    }
    FUN_0025fa7e(puVar2);
    *(undefined8 *)(param_1 + 0x318) = uVar1;
  }
  *(undefined8 *)(param_1 + 0x318) = 0;
  *(undefined4 *)(param_1 + 0x32c) = 0;
  return;
}


// ===== 0025feee FUN_0025feee =====

void FUN_0025feee(long param_1)

{
  if (*(long *)(param_1 + 0x318) != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!topology->backends",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/components.c"
                  ,0x440,"hwloc_topology_components_fini");
  }
  free(*(void **)(param_1 + 0x370));
  return;
}


// ===== 0025ff3f FUN_0025ff3f =====

undefined8 FUN_0025ff3f(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  long local_10;
  
  iVar1 = FUN_00257fb0(param_1,0xd);
  local_10 = 0;
  if (iVar1 == -1) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("depth != HWLOC_TYPE_DEPTH_UNKNOWN",
                  "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/include/hwloc/helper.h"
                  ,0x498,"hwloc_cpuset_from_nodeset");
  }
  FUN_0026180c(param_2);
  do {
    local_10 = FUN_0026000b(param_1,iVar1,local_10);
    if (local_10 == 0) {
      return 0;
    }
    iVar2 = FUN_0026203b(param_3,*(undefined4 *)(local_10 + 0x10));
  } while ((iVar2 == 0) ||
          (iVar2 = FUN_00262517(param_2,param_2,*(undefined8 *)(local_10 + 0xb8)), -1 < iVar2));
  return 0xffffffff;
}


// ===== 0026000b FUN_0026000b =====

undefined8 FUN_0026000b(undefined8 param_1,int param_2,long param_3)

{
  undefined8 uVar1;
  
  if (param_3 == 0) {
    uVar1 = FUN_002580d2(param_1,param_2,0);
  }
  else if (param_2 == *(int *)(param_3 + 0x30)) {
    uVar1 = *(undefined8 *)(param_3 + 0x38);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 0026005a FUN_0026005a =====

undefined8 FUN_0026005a(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int *piVar4;
  
  uVar2 = FUN_00255632(param_1);
  uVar3 = FUN_00255611(param_1);
  iVar1 = FUN_002620a3(param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_002623d5(param_2,uVar3);
    if (iVar1 == 0) {
      piVar4 = __errno_location();
      *piVar4 = 0x16;
      param_2 = 0;
    }
    else {
      iVar1 = FUN_002623d5(uVar2,param_2);
      if (iVar1 != 0) {
        param_2 = uVar3;
      }
    }
  }
  else {
    piVar4 = __errno_location();
    *piVar4 = 0x16;
    param_2 = 0;
  }
  return param_2;
}


// ===== 002600fa FUN_002600fa =====

ulong FUN_002600fa(long param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  int *piVar2;
  long lVar3;
  ulong uVar4;
  
  if ((param_3 & 0xfffffff0) != 0) {
    piVar2 = __errno_location();
    *piVar2 = 0x16;
    return 0xffffffff;
  }
  lVar3 = FUN_0026005a(param_1,param_2);
  if (lVar3 != 0) {
    if ((param_3 & 1) == 0) {
      if ((param_3 & 2) == 0) {
        if ((*(long *)(param_1 + 0x1c8) != 0) &&
           ((uVar1 = (**(code **)(param_1 + 0x1c8))(param_1,lVar3,param_3), -1 < (int)uVar1 ||
            (piVar2 = __errno_location(), *piVar2 != 0x26)))) {
          return (ulong)uVar1;
        }
        if (*(long *)(param_1 + 0x1d8) != 0) {
          uVar4 = (**(code **)(param_1 + 0x1d8))(param_1,lVar3,param_3);
          return uVar4;
        }
      }
      else if (*(long *)(param_1 + 0x1d8) != 0) {
        uVar4 = (**(code **)(param_1 + 0x1d8))(param_1,lVar3,param_3);
        return uVar4;
      }
    }
    else if (*(long *)(param_1 + 0x1c8) != 0) {
      uVar4 = (**(code **)(param_1 + 0x1c8))(param_1,lVar3,param_3);
      return uVar4;
    }
    piVar2 = __errno_location();
    *piVar2 = 0x26;
    return 0xffffffff;
  }
  return 0xffffffff;
}


// ===== 00260254 FUN_00260254 =====

ulong FUN_00260254(long param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  int *piVar2;
  ulong uVar3;
  
  if ((param_3 & 0xfffffff0) != 0) {
    piVar2 = __errno_location();
    *piVar2 = 0x16;
    return 0xffffffff;
  }
  if ((param_3 & 1) == 0) {
    if ((param_3 & 2) == 0) {
      if ((*(long *)(param_1 + 0x1d0) != 0) &&
         ((uVar1 = (**(code **)(param_1 + 0x1d0))(param_1,param_2,param_3), -1 < (int)uVar1 ||
          (piVar2 = __errno_location(), *piVar2 != 0x26)))) {
        return (ulong)uVar1;
      }
      if (*(long *)(param_1 + 0x1e0) != 0) {
        uVar3 = (**(code **)(param_1 + 0x1e0))(param_1,param_2,param_3);
        return uVar3;
      }
    }
    else if (*(long *)(param_1 + 0x1e0) != 0) {
      uVar3 = (**(code **)(param_1 + 0x1e0))(param_1,param_2,param_3);
      return uVar3;
    }
  }
  else if (*(long *)(param_1 + 0x1d0) != 0) {
    uVar3 = (**(code **)(param_1 + 0x1d0))(param_1,param_2,param_3);
    return uVar3;
  }
  piVar2 = __errno_location();
  *piVar2 = 0x26;
  return 0xffffffff;
}


// ===== 00260386 FUN_00260386 =====

ulong FUN_00260386(long param_1,undefined8 param_2,undefined8 param_3,uint param_4)

{
  uint uVar1;
  int *piVar2;
  ulong uVar3;
  
  if ((param_4 & 0xffffffc0) != 0) {
    piVar2 = __errno_location();
    *piVar2 = 0x16;
    return 0xffffffff;
  }
  if ((param_4 & 1) == 0) {
    if ((param_4 & 2) == 0) {
      if ((*(long *)(param_1 + 0x228) != 0) &&
         ((uVar1 = (**(code **)(param_1 + 0x228))(param_1,param_2,param_3,param_4), -1 < (int)uVar1
          || (piVar2 = __errno_location(), *piVar2 != 0x26)))) {
        return (ulong)uVar1;
      }
      if (*(long *)(param_1 + 0x238) != 0) {
        uVar3 = (**(code **)(param_1 + 0x238))(param_1,param_2,param_3,param_4);
        return uVar3;
      }
    }
    else if (*(long *)(param_1 + 0x238) != 0) {
      uVar3 = (**(code **)(param_1 + 0x238))(param_1,param_2,param_3,param_4);
      return uVar3;
    }
  }
  else if (*(long *)(param_1 + 0x228) != 0) {
    uVar3 = (**(code **)(param_1 + 0x228))(param_1,param_2,param_3,param_4);
    return uVar3;
  }
  piVar2 = __errno_location();
  *piVar2 = 0x26;
  return 0xffffffff;
}


// ===== 002604c0 FUN_002604c0 =====

int FUN_002604c0(undefined8 param_1,undefined8 param_2,undefined8 param_3,uint param_4)

{
  undefined8 uVar1;
  undefined4 local_c;
  
  if ((param_4 & 0x20) == 0) {
    uVar1 = FUN_00260eab();
    local_c = FUN_00260386(param_1,uVar1,param_3,param_4);
    if (local_c == 0) {
      FUN_0025ff3f(param_1,param_2,uVar1);
    }
    FUN_00260f71(uVar1);
  }
  else {
    local_c = FUN_00260386(param_1,param_2,param_3,param_4);
  }
  return local_c;
}


// ===== 0026054e FUN_0026054e =====

void * FUN_0026054e(undefined8 param_1,size_t param_2)

{
  void *pvVar1;
  
  pvVar1 = mmap((void *)0x0,param_2,3,0x22,-1,0);
  if (pvVar1 == (void *)0xffffffffffffffff) {
    pvVar1 = (void *)0x0;
  }
  return pvVar1;
}


// ===== 0026059d FUN_0026059d =====

int FUN_0026059d(undefined8 param_1,void *param_2,size_t param_3)

{
  int iVar1;
  
  if (param_2 == (void *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = munmap(param_2,param_3);
  }
  return iVar1;
}


// ===== 002605d4 FUN_002605d4 =====

undefined8 FUN_002605d4(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00255611(param_1);
  FUN_00261201(param_2,uVar1);
  return 0;
}


// ===== 00260609 FUN_00260609 =====

undefined8 FUN_00260609(void)

{
  return 0;
}


// ===== 0026061f FUN_0026061f =====

void FUN_0026061f(undefined8 param_1,undefined8 param_2)

{
  FUN_002605d4(param_1,param_2);
  return;
}


// ===== 00260647 FUN_00260647 =====

undefined8 FUN_00260647(void)

{
  return 0;
}


// ===== 0026065d FUN_0026065d =====

void FUN_0026065d(undefined8 param_1,undefined8 param_2)

{
  FUN_002605d4(param_1,param_2);
  return;
}


// ===== 00260685 FUN_00260685 =====

undefined8 FUN_00260685(void)

{
  return 0;
}


// ===== 0026069e FUN_0026069e =====

void FUN_0026069e(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_002605d4(param_1,param_3);
  return;
}


// ===== 002606c9 FUN_002606c9 =====

undefined8 FUN_002606c9(void)

{
  return 0;
}


// ===== 002606e3 FUN_002606e3 =====

void FUN_002606e3(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_002605d4(param_1,param_3);
  return;
}


// ===== 0026070f FUN_0026070f =====

undefined8 FUN_0026070f(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00255653(param_1);
  FUN_00261201(param_2,uVar1);
  *param_3 = 0xffffffff;
  return 0;
}


// ===== 00260752 FUN_00260752 =====

undefined8 FUN_00260752(void)

{
  return 0;
}


// ===== 0026076b FUN_0026076b =====

void FUN_0026076b(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_0026070f(param_1,param_2,param_3);
  return;
}


// ===== 0026079b FUN_0026079b =====

undefined8 FUN_0026079b(void)

{
  return 0;
}


// ===== 002607b4 FUN_002607b4 =====

void FUN_002607b4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_0026070f(param_1,param_2,param_3);
  return;
}


// ===== 002607e4 FUN_002607e4 =====

undefined8 FUN_002607e4(void)

{
  return 0;
}


// ===== 00260801 FUN_00260801 =====

void FUN_00260801(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_0026070f(param_1,param_3,param_4);
  return;
}


// ===== 00260835 FUN_00260835 =====

undefined8 FUN_00260835(void)

{
  return 0;
}


// ===== 00260858 FUN_00260858 =====

void FUN_00260858(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  FUN_0026070f(param_1,param_4,param_5);
  return;
}


// ===== 00260891 FUN_00260891 =====

void FUN_00260891(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 local_c [4];
  
  FUN_0026070f(param_1,param_4,local_c);
  return;
}


// ===== 002608c6 FUN_002608c6 =====

void FUN_002608c6(undefined8 param_1,size_t param_2)

{
  malloc(param_2);
  return;
}


// ===== 002608ef FUN_002608ef =====

undefined8 FUN_002608ef(undefined8 param_1,void *param_2)

{
  free(param_2);
  return 0;
}


// ===== 00260916 FUN_00260916 =====

void FUN_00260916(undefined8 *param_1)

{
  *param_1 = FUN_00260647;
  param_1[1] = FUN_0026065d;
  param_1[2] = FUN_00260609;
  param_1[3] = FUN_0026061f;
  param_1[4] = FUN_00260685;
  param_1[5] = FUN_0026069e;
  param_1[6] = FUN_002606c9;
  param_1[7] = FUN_002606e3;
  param_1[8] = FUN_0026065d;
  param_1[9] = FUN_0026061f;
  param_1[10] = FUN_0026069e;
  param_1[0xb] = FUN_00260752;
  param_1[0xc] = FUN_0026076b;
  param_1[0xd] = FUN_0026079b;
  param_1[0xe] = FUN_002607b4;
  param_1[0xf] = FUN_002607e4;
  param_1[0x10] = FUN_00260801;
  param_1[0x11] = FUN_00260835;
  param_1[0x12] = FUN_00260858;
  param_1[0x13] = FUN_00260891;
  param_1[0x15] = FUN_002608c6;
  param_1[0x16] = FUN_002608ef;
  return;
}


// ===== 00260a80 FUN_00260a80 =====

void FUN_00260a80(undefined8 param_1,undefined8 param_2)

{
  FUN_00279ca4(param_1,param_2);
  return;
}


// ===== 00260aa6 FUN_00260aa6 =====

void FUN_00260aa6(long param_1)

{
  if (*(int *)(param_1 + 200) == 0) {
    FUN_00260916(param_1 + 0x1c8,param_1 + 0x288);
  }
  else {
    FUN_00260a80(param_1 + 0x1c8,param_1 + 0x288);
  }
  if (*(int *)(param_1 + 200) != 0) {
    if (*(long *)(param_1 + 0x1c8) != 0) {
      **(undefined1 **)(param_1 + 0x290) = 1;
    }
    if (*(long *)(param_1 + 0x1d0) != 0) {
      *(undefined1 *)(*(long *)(param_1 + 0x290) + 1) = 1;
    }
    if (*(long *)(param_1 + 0x1e8) != 0) {
      *(undefined1 *)(*(long *)(param_1 + 0x290) + 2) = 1;
    }
    if (*(long *)(param_1 + 0x1f0) != 0) {
      *(undefined1 *)(*(long *)(param_1 + 0x290) + 3) = 1;
    }
    if (*(long *)(param_1 + 0x1d8) != 0) {
      *(undefined1 *)(*(long *)(param_1 + 0x290) + 4) = 1;
    }
    if (*(long *)(param_1 + 0x1e0) != 0) {
      *(undefined1 *)(*(long *)(param_1 + 0x290) + 5) = 1;
    }
    if (*(long *)(param_1 + 0x1f8) != 0) {
      *(undefined1 *)(*(long *)(param_1 + 0x290) + 6) = 1;
    }
    if (*(long *)(param_1 + 0x200) != 0) {
      *(undefined1 *)(*(long *)(param_1 + 0x290) + 7) = 1;
    }
    if (*(long *)(param_1 + 0x208) != 0) {
      *(undefined1 *)(*(long *)(param_1 + 0x290) + 8) = 1;
    }
    if (*(long *)(param_1 + 0x218) != 0) {
      *(undefined1 *)(*(long *)(param_1 + 0x290) + 9) = 1;
    }
    if (*(long *)(param_1 + 0x210) != 0) {
      *(undefined1 *)(*(long *)(param_1 + 0x290) + 10) = 1;
    }
    if (*(long *)(param_1 + 0x220) != 0) {
      **(undefined1 **)(param_1 + 0x298) = 1;
    }
    if (*(long *)(param_1 + 0x228) != 0) {
      *(undefined1 *)(*(long *)(param_1 + 0x298) + 1) = 1;
    }
    if (*(long *)(param_1 + 0x230) != 0) {
      *(undefined1 *)(*(long *)(param_1 + 0x298) + 4) = 1;
    }
    if (*(long *)(param_1 + 0x238) != 0) {
      *(undefined1 *)(*(long *)(param_1 + 0x298) + 5) = 1;
    }
    if (*(long *)(param_1 + 0x240) != 0) {
      *(undefined1 *)(*(long *)(param_1 + 0x298) + 2) = 1;
    }
    if (*(long *)(param_1 + 0x248) != 0) {
      *(undefined1 *)(*(long *)(param_1 + 0x298) + 3) = 1;
    }
    if (*(long *)(param_1 + 0x250) != 0) {
      *(undefined1 *)(*(long *)(param_1 + 0x298) + 6) = 1;
    }
    if (*(long *)(param_1 + 600) != 0) {
      *(undefined1 *)(*(long *)(param_1 + 0x298) + 7) = 1;
    }
    if (*(long *)(param_1 + 0x260) != 0) {
      *(undefined1 *)(*(long *)(param_1 + 0x298) + 0xe) = 1;
    }
    if (*(long *)(param_1 + 0x270) != 0) {
      *(undefined1 *)(*(long *)(param_1 + 0x298) + 8) = 1;
    }
  }
  return;
}


// ===== 00260da0 FUN_00260da0 =====

int FUN_00260da0(ulong param_1)

{
  undefined8 local_20;
  undefined4 local_c;
  
  if (param_1 == 0) {
    local_c = 0;
  }
  else {
    local_c = 1;
    local_20 = param_1;
    if ((param_1 & 0xffffffff00000000) != 0) {
      local_20 = param_1 >> 0x20;
      local_c = 0x21;
    }
    if ((local_20 & 0xffff0000) != 0) {
      local_20 = local_20 >> 0x10;
      local_c = local_c + 0x10;
    }
    if ((local_20 & 0xff00) != 0) {
      local_20 = local_20 >> 8;
      local_c = local_c + 8;
    }
    if ((local_20 & 0xf0) != 0) {
      local_20 = local_20 >> 4;
      local_c = local_c + 4;
    }
    if ((local_20 & 0xc) != 0) {
      local_20 = local_20 >> 2;
      local_c = local_c + 2;
    }
    if ((local_20 & 2) != 0) {
      local_c = local_c + 1;
    }
  }
  return local_c;
}


// ===== 00260e56 FUN_00260e56 =====

void FUN_00260e56(undefined8 param_1)

{
  FUN_002935f0(param_1);
  return;
}


// ===== 00260e6d FUN_00260e6d =====

void FUN_00260e6d(undefined8 *param_1,size_t param_2)

{
  if (param_1 == (undefined8 *)0x0) {
    malloc(param_2);
  }
  else {
    (*(code *)*param_1)(param_1,param_2);
  }
  return;
}


// ===== 00260eab FUN_00260eab =====

undefined4 * FUN_00260eab(void)

{
  undefined4 *__ptr;
  void *pvVar1;
  
  __ptr = malloc(0x18);
  if (__ptr == (undefined4 *)0x0) {
    __ptr = (undefined4 *)0x0;
  }
  else {
    *__ptr = 1;
    __ptr[1] = 8;
    pvVar1 = malloc(0x40);
    *(void **)(__ptr + 2) = pvVar1;
    if (*(long *)(__ptr + 2) == 0) {
      free(__ptr);
      __ptr = (undefined4 *)0x0;
    }
    else {
      **(undefined8 **)(__ptr + 2) = 0;
      __ptr[4] = 0;
    }
  }
  return __ptr;
}


// ===== 00260f39 FUN_00260f39 =====

long FUN_00260f39(void)

{
  long lVar1;
  
  lVar1 = FUN_00260eab();
  if (lVar1 != 0) {
    *(undefined4 *)(lVar1 + 0x10) = 1;
    **(undefined8 **)(lVar1 + 8) = 0xffffffffffffffff;
  }
  return lVar1;
}


// ===== 00260f71 FUN_00260f71 =====

void FUN_00260f71(void *param_1)

{
  if (param_1 != (void *)0x0) {
    free(*(void **)((long)param_1 + 8));
    free(param_1);
  }
  return;
}


// ===== 00260fa5 FUN_00260fa5 =====

undefined8 FUN_00260fa5(long param_1,uint param_2)

{
  byte bVar1;
  void *pvVar2;
  uint uVar3;
  
  bVar1 = FUN_00260da0((ulong)param_2 - 1);
  uVar3 = 1 << (bVar1 & 0x1f);
  if (*(uint *)(param_1 + 4) < uVar3) {
    pvVar2 = realloc(*(void **)(param_1 + 8),(ulong)uVar3 * 8);
    if (pvVar2 == (void *)0x0) {
      return 0xffffffff;
    }
    *(void **)(param_1 + 8) = pvVar2;
    *(uint *)(param_1 + 4) = uVar3;
  }
  return 0;
}


// ===== 0026102a FUN_0026102a =====

undefined8 FUN_0026102a(uint *param_1,uint param_2)

{
  int iVar1;
  undefined8 uVar2;
  uint local_c;
  
  if (*param_1 < param_2) {
    iVar1 = FUN_00260fa5(param_1,param_2);
    if (iVar1 < 0) {
      uVar2 = 0xffffffff;
    }
    else {
      for (local_c = *param_1; local_c < param_2; local_c = local_c + 1) {
        if (param_1[4] == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = 0xffffffffffffffff;
        }
        *(undefined8 *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) = uVar2;
      }
      *param_1 = param_2;
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 002610bc FUN_002610bc =====

undefined8 FUN_002610bc(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_00260fa5(param_1,param_2);
  if (iVar1 == 0) {
    *param_1 = param_2;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// ===== 002610f7 FUN_002610f7 =====

uint * FUN_002610f7(undefined8 param_1,uint *param_2)

{
  uint *__ptr;
  undefined8 uVar1;
  
  if (param_2 == (uint *)0x0) {
    __ptr = (uint *)0x0;
  }
  else {
    __ptr = (uint *)FUN_00260e6d(param_1,0x18);
    if (__ptr == (uint *)0x0) {
      __ptr = (uint *)0x0;
    }
    else {
      uVar1 = FUN_00260e6d(param_1,(ulong)param_2[1] * 8);
      *(undefined8 *)(__ptr + 2) = uVar1;
      if (*(long *)(__ptr + 2) == 0) {
        free(__ptr);
        __ptr = (uint *)0x0;
      }
      else {
        __ptr[1] = param_2[1];
        *__ptr = *param_2;
        memcpy(*(void **)(__ptr + 2),*(void **)(param_2 + 2),(ulong)*__ptr * 8);
        __ptr[4] = param_2[4];
      }
    }
  }
  return __ptr;
}


// ===== 002611e2 FUN_002611e2 =====

void FUN_002611e2(undefined8 param_1)

{
  FUN_002610f7(0,param_1);
  return;
}


// ===== 00261201 FUN_00261201 =====

undefined8 FUN_00261201(long param_1,uint *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_002610bc(param_1,*param_2);
  if (iVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    memcpy(*(void **)(param_1 + 8),*(void **)(param_2 + 2),(ulong)*param_2 * 8);
    *(uint *)(param_1 + 0x10) = param_2[4];
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 00261270 FUN_00261270 =====

int FUN_00261270(undefined1 *param_1,long param_2,int *param_3)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  undefined *puVar4;
  int local_34;
  ulong local_30;
  int local_28;
  int local_20;
  int local_1c;
  undefined1 *local_18;
  long local_10;
  
  local_20 = 0;
  bVar1 = false;
  local_30 = 0;
  local_34 = 0;
  if (param_2 != 0) {
    *param_1 = 0;
  }
  local_18 = param_1;
  local_10 = param_2;
  if (param_3[4] != 0) {
    local_20 = FUN_002654ee(param_1,param_2,"0xf...f");
    bVar1 = true;
    if (local_20 < 0) {
      return -1;
    }
    local_1c = local_20;
    if (param_2 <= local_20) {
      if (param_2 < 1) {
        local_1c = 0;
      }
      else {
        local_1c = (int)param_2 + -1;
      }
    }
    local_18 = param_1 + local_1c;
    local_10 = param_2 - local_1c;
  }
  local_28 = *param_3 + -1;
  if (param_3[4] == 0) {
    while ((-1 < local_28 && (*(long *)(*(long *)(param_3 + 2) + (long)local_28 * 8) == 0))) {
      local_28 = local_28 + -1;
    }
  }
  else {
    while ((-1 < local_28 && (*(long *)(*(long *)(param_3 + 2) + (long)local_28 * 8) == -1))) {
      local_28 = local_28 + -1;
    }
  }
  while ((-1 < local_28 || (local_34 != 0))) {
    if (local_34 == 0) {
      local_30 = *(ulong *)((long)local_28 * 8 + *(long *)(param_3 + 2));
      local_34 = 0x40;
      local_28 = local_28 + -1;
    }
    if ((local_30 & 0xffffffff00000000) == 0) {
      if ((local_28 == -1) && (local_34 == 0x20)) {
        if (bVar1) {
          puVar4 = &DAT_002ed339;
        }
        else {
          puVar4 = &DAT_002ed33e;
        }
        local_1c = FUN_002654ee(local_18,local_10,puVar4);
      }
      else if (bVar1) {
        local_1c = FUN_002654ee(local_18,local_10,&DAT_002ed342);
      }
      else {
        local_1c = 0;
      }
    }
    else {
      if (bVar1) {
        pcVar3 = ",0x%08lx";
      }
      else {
        pcVar3 = "0x%08lx";
      }
      local_1c = FUN_002654ee(local_18,local_10,pcVar3,local_30 >> 0x20);
      bVar1 = true;
    }
    if (local_1c < 0) {
      return -1;
    }
    local_20 = local_20 + local_1c;
    local_30 = local_30 << 0x20;
    local_34 = local_34 + -0x20;
    if (local_10 <= local_1c) {
      if (local_10 < 1) {
        local_1c = 0;
      }
      else {
        local_1c = (int)local_10 + -1;
      }
    }
    local_18 = local_18 + local_1c;
    local_10 = local_10 - local_1c;
  }
  if (local_20 != 0) {
    return local_20;
  }
  iVar2 = FUN_002654ee(local_18,local_10,&DAT_002ed33e);
  if (-1 < iVar2) {
    return iVar2;
  }
  return -1;
}


// ===== 00261562 FUN_00261562 =====

undefined8 FUN_00261562(undefined8 *param_1,undefined8 param_2)

{
  int iVar1;
  void *pvVar2;
  undefined8 uVar3;
  
  iVar1 = FUN_00261270(0,0,param_2);
  pvVar2 = malloc((long)(iVar1 + 1));
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0xffffffff;
  }
  else {
    *param_1 = pvVar2;
    uVar3 = FUN_00261270(pvVar2,(long)(iVar1 + 1),param_2);
  }
  return uVar3;
}


// ===== 002615d6 FUN_002615d6 =====

undefined8 FUN_002615d6(long param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  char *local_30;
  ulong local_28;
  undefined4 local_20;
  uint local_1c;
  ulong local_18;
  char *local_10;
  
  local_18 = 0;
  local_20 = 0;
  local_1c = 1;
  local_10 = param_2;
  while (local_10 = strchr(local_10 + 1,0x2c), local_10 != (char *)0x0) {
    local_1c = local_1c + 1;
  }
  local_10 = param_2;
  iVar1 = strncmp("0xf...f",param_2,7);
  if (iVar1 == 0) {
    if (local_10[7] != ',') {
      local_10 = local_10 + 7;
      FUN_0026187f(param_1);
      return 0;
    }
    local_10 = local_10 + 8;
    local_20 = 1;
    local_1c = local_1c - 1;
  }
  iVar1 = FUN_002610bc(param_1,(int)(local_1c + 1) / 2);
  if (iVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = 0;
    while (*local_10 != '\0') {
      local_28 = strtoul(local_10,&local_30,0x10);
      if ((int)local_1c < 1) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("count > 0",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/bitmap.c"
                      ,0x18b,"hwloc_bitmap_sscanf");
      }
      local_1c = local_1c - 1;
      local_18 = local_18 | local_28 << ((byte)((int)(local_1c * 0x20) % 0x40) & 0x3f);
      if ((local_1c & 1) == 0) {
        *(ulong *)(*(long *)(param_1 + 8) + (long)((int)local_1c / 2) * 8) = local_18;
        local_18 = 0;
      }
      if (*local_30 != ',') {
        if ((*local_30 != '\0') || (0 < (int)local_1c)) {
          FUN_0026180c(param_1);
          return 0xffffffff;
        }
        break;
      }
      local_10 = local_30 + 1;
    }
    *(undefined4 *)(param_1 + 0x10) = local_20;
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 002617c5 FUN_002617c5 =====

void FUN_002617c5(uint *param_1)

{
  uint local_c;
  
  for (local_c = 0; local_c < *param_1; local_c = local_c + 1) {
    *(undefined8 *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) = 0;
  }
  param_1[4] = 0;
  return;
}


// ===== 0026180c FUN_0026180c =====

void FUN_0026180c(undefined8 param_1)

{
  FUN_002610bc(param_1,1);
  FUN_002617c5(param_1);
  return;
}


// ===== 00261838 FUN_00261838 =====

void FUN_00261838(uint *param_1)

{
  uint local_c;
  
  for (local_c = 0; local_c < *param_1; local_c = local_c + 1) {
    *(undefined8 *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) = 0xffffffffffffffff;
  }
  param_1[4] = 1;
  return;
}


// ===== 0026187f FUN_0026187f =====

void FUN_0026187f(undefined8 param_1)

{
  FUN_002610bc(param_1,1);
  FUN_00261838(param_1);
  return;
}


// ===== 002618ab FUN_002618ab =====

undefined8 FUN_002618ab(uint *param_1,uint param_2)

{
  undefined8 uVar1;
  
  if (param_2 < *param_1) {
    uVar1 = *(undefined8 *)(*(long *)(param_1 + 2) + (ulong)param_2 * 8);
  }
  else if (param_1[4] == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffffffffffff;
  }
  return uVar1;
}


// ===== 002618f3 FUN_002618f3 =====

undefined8 FUN_002618f3(long param_1,uint param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_002610bc(param_1,(param_2 >> 6) + 1);
  if (iVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    FUN_002617c5(param_1);
    *(ulong *)(*(long *)(param_1 + 8) + (ulong)(param_2 >> 6) * 8) =
         *(ulong *)(*(long *)(param_1 + 8) + (ulong)(param_2 >> 6) * 8) |
         1L << ((byte)param_2 & 0x3f);
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 0026197d FUN_0026197d =====

undefined8 FUN_0026197d(int *param_1,uint param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((param_1[4] == 0) || (param_2 < (uint)(*param_1 << 6))) {
    iVar1 = FUN_0026102a(param_1,(param_2 >> 6) + 1);
    if (iVar1 < 0) {
      uVar2 = 0xffffffff;
    }
    else {
      *(ulong *)(*(long *)(param_1 + 2) + (ulong)(param_2 >> 6) * 8) =
           *(ulong *)(*(long *)(param_1 + 2) + (ulong)(param_2 >> 6) * 8) |
           1L << ((byte)param_2 & 0x3f);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 00261a1b FUN_00261a1b =====

undefined8 FUN_00261a1b(uint *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint local_10;
  uint local_c;
  
  if ((param_2 <= param_3) && ((param_1[4] == 0 || (param_2 < *param_1 << 6)))) {
    bVar1 = (byte)param_2;
    if (param_3 == 0xffffffff) {
      iVar2 = FUN_0026102a(param_1,(param_2 >> 6) + 1);
      if (iVar2 < 0) {
        return 0xffffffff;
      }
      local_c = param_2 >> 6;
      *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) =
           *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) | -1L << (bVar1 & 0x3f);
      while (local_c = local_c + 1, local_c < *param_1) {
        *(undefined8 *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) = 0xffffffffffffffff;
      }
      param_1[4] = 1;
    }
    else {
      local_10 = param_3;
      if ((param_1[4] != 0) && (*param_1 << 6 <= param_3)) {
        local_10 = *param_1 * 0x40 - 1;
      }
      iVar2 = FUN_0026102a(param_1,(local_10 >> 6) + 1);
      if (iVar2 < 0) {
        return 0xffffffff;
      }
      local_c = param_2 >> 6;
      uVar3 = local_10 >> 6;
      if (local_c == uVar3) {
        *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) =
             *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) |
             0xffffffffffffffffU >> (~(byte)local_10 & 0x3f) & -1L << (bVar1 & 0x3f);
      }
      else {
        *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) =
             *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) | -1L << (bVar1 & 0x3f);
        *(ulong *)(*(long *)(param_1 + 2) + (ulong)uVar3 * 8) =
             *(ulong *)(*(long *)(param_1 + 2) + (ulong)uVar3 * 8) |
             0xffffffffffffffffU >> (~(byte)local_10 & 0x3f);
      }
      while (local_c = local_c + 1, local_c < uVar3) {
        *(undefined8 *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) = 0xffffffffffffffff;
      }
    }
  }
  return 0;
}


// ===== 00261c9e FUN_00261c9e =====

undefined8 FUN_00261c9e(long param_1,uint param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_0026102a(param_1,param_2 + 1);
  if (iVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    *(undefined8 *)((ulong)param_2 * 8 + *(long *)(param_1 + 8)) = param_3;
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 00261cf0 FUN_00261cf0 =====

undefined8 FUN_00261cf0(int *param_1,uint param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((param_1[4] == 0) && ((uint)(*param_1 << 6) <= param_2)) {
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_0026102a(param_1,(param_2 >> 6) + 1);
    if (iVar1 < 0) {
      uVar2 = 0xffffffff;
    }
    else {
      *(ulong *)(*(long *)(param_1 + 2) + (ulong)(param_2 >> 6) * 8) =
           *(ulong *)(*(long *)(param_1 + 2) + (ulong)(param_2 >> 6) * 8) &
           ~(1L << ((byte)param_2 & 0x3f));
      uVar2 = 0;
    }
  }
  return uVar2;
}


// ===== 00261d97 FUN_00261d97 =====

undefined8 FUN_00261d97(uint *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint local_10;
  uint local_c;
  
  if ((param_2 <= param_3) && ((param_1[4] != 0 || (param_2 < *param_1 << 6)))) {
    bVar1 = (byte)param_2;
    if (param_3 == 0xffffffff) {
      iVar2 = FUN_0026102a(param_1,(param_2 >> 6) + 1);
      if (iVar2 < 0) {
        return 0xffffffff;
      }
      local_c = param_2 >> 6;
      *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) =
           *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) & ~(-1L << (bVar1 & 0x3f));
      while (local_c = local_c + 1, local_c < *param_1) {
        *(undefined8 *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) = 0;
      }
      param_1[4] = 0;
    }
    else {
      local_10 = param_3;
      if ((param_1[4] == 0) && (*param_1 << 6 <= param_3)) {
        local_10 = *param_1 * 0x40 - 1;
      }
      iVar2 = FUN_0026102a(param_1,(local_10 >> 6) + 1);
      if (iVar2 < 0) {
        return 0xffffffff;
      }
      local_c = param_2 >> 6;
      uVar3 = local_10 >> 6;
      if (local_c == uVar3) {
        *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) =
             *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) &
             ~(-1L << (bVar1 & 0x3f) & 0xffffffffffffffffU >> (~(byte)local_10 & 0x3f));
      }
      else {
        *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) =
             *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) & ~(-1L << (bVar1 & 0x3f));
        *(ulong *)(*(long *)(param_1 + 2) + (ulong)uVar3 * 8) =
             *(ulong *)(*(long *)(param_1 + 2) + (ulong)uVar3 * 8) &
             ~(0xffffffffffffffffU >> (~(byte)local_10 & 0x3f));
      }
      while (local_c = local_c + 1, local_c < uVar3) {
        *(undefined8 *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) = 0;
      }
    }
  }
  return 0;
}


// ===== 0026203b FUN_0026203b =====

bool FUN_0026203b(uint *param_1,uint param_2)

{
  ulong uVar1;
  
  if (param_2 >> 6 < *param_1) {
    uVar1 = *(ulong *)(*(long *)(param_1 + 2) + (ulong)(param_2 >> 6) * 8);
  }
  else if (param_1[4] == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffffffffffff;
  }
  return (uVar1 >> ((byte)param_2 & 0x3f) & 1) != 0;
}


// ===== 002620a3 FUN_002620a3 =====

undefined8 FUN_002620a3(uint *param_1)

{
  undefined8 uVar1;
  uint local_c;
  
  if (param_1[4] == 0) {
    for (local_c = 0; local_c < *param_1; local_c = local_c + 1) {
      if (*(long *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) != 0) {
        return 0;
      }
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 002620fd FUN_002620fd =====

undefined8 FUN_002620fd(uint *param_1)

{
  undefined8 uVar1;
  uint local_c;
  
  if (param_1[4] == 0) {
    uVar1 = 0;
  }
  else {
    for (local_c = 0; local_c < *param_1; local_c = local_c + 1) {
      if (*(long *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) != -1) {
        return 0;
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}


// ===== 00262158 FUN_00262158 =====

bool FUN_00262158(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  uint local_c;
  
  uVar1 = *param_1;
  uVar2 = *param_2;
  uVar3 = uVar1;
  if (uVar2 <= uVar1) {
    uVar3 = uVar2;
  }
  for (local_c = 0; local_c < uVar3; local_c = local_c + 1) {
    if (*(long *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) !=
        *(long *)(*(long *)(param_2 + 2) + (ulong)local_c * 8)) {
      return false;
    }
  }
  if (uVar1 != uVar2) {
    if (param_1[4] == 0) {
      lVar4 = 0;
    }
    else {
      lVar4 = -1;
    }
    local_c = uVar3;
    if (param_2[4] == 0) {
      lVar5 = 0;
    }
    else {
      lVar5 = -1;
    }
    for (; local_c < uVar1; local_c = local_c + 1) {
      if (lVar5 != *(long *)(*(long *)(param_1 + 2) + (ulong)local_c * 8)) {
        return false;
      }
    }
    while (local_c = uVar3, local_c < uVar2) {
      if (lVar4 != *(long *)(*(long *)(param_2 + 2) + (ulong)local_c * 8)) {
        return false;
      }
      uVar3 = local_c + 1;
    }
  }
  return param_1[4] == param_2[4];
}


// ===== 002622a3 FUN_002622a3 =====

undefined8 FUN_002622a3(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  uint local_c;
  
  uVar1 = *param_1;
  uVar2 = *param_2;
  uVar3 = uVar1;
  if (uVar2 <= uVar1) {
    uVar3 = uVar2;
  }
  for (local_c = 0; local_c < uVar3; local_c = local_c + 1) {
    if ((*(ulong *)(*(long *)(param_2 + 2) + (ulong)local_c * 8) &
        *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8)) != 0) {
      return 1;
    }
  }
  if (uVar1 != uVar2) {
    local_c = uVar3;
    if (param_2[4] != 0) {
      for (; local_c < *param_1; local_c = local_c + 1) {
        if (*(long *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) != 0) {
          return 1;
        }
      }
    }
    local_c = uVar3;
    if (param_1[4] != 0) {
      for (; local_c < *param_2; local_c = local_c + 1) {
        if (*(long *)(*(long *)(param_2 + 2) + (ulong)local_c * 8) != 0) {
          return 1;
        }
      }
    }
  }
  if ((param_1[4] == 0) || (param_2[4] == 0)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}


// ===== 002623d5 FUN_002623d5 =====

undefined8 FUN_002623d5(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  uint local_c;
  
  uVar1 = *param_2;
  uVar2 = *param_1;
  uVar3 = uVar1;
  if (uVar2 <= uVar1) {
    uVar3 = uVar2;
  }
  for (local_c = 0; local_c < uVar3; local_c = local_c + 1) {
    if (*(ulong *)(*(long *)(param_2 + 2) + (ulong)local_c * 8) !=
        (*(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) |
        *(ulong *)(*(long *)(param_2 + 2) + (ulong)local_c * 8))) {
      return 0;
    }
  }
  if (uVar1 != uVar2) {
    local_c = uVar3;
    if (param_2[4] == 0) {
      for (; local_c < uVar2; local_c = local_c + 1) {
        if (*(long *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) != 0) {
          return 0;
        }
      }
    }
    local_c = uVar3;
    if (param_1[4] != 0) {
      for (; local_c < uVar1; local_c = local_c + 1) {
        if (*(long *)(*(long *)(param_2 + 2) + (ulong)local_c * 8) != -1) {
          return 0;
        }
      }
    }
  }
  if ((param_1[4] == 0) || (param_2[4] != 0)) {
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


// ===== 00262517 FUN_00262517 =====

undefined8 FUN_00262517(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  uint local_c;
  
  uVar6 = *param_2;
  uVar1 = *param_3;
  uVar2 = uVar6;
  if (uVar6 <= uVar1) {
    uVar2 = uVar1;
  }
  uVar3 = (uVar1 + uVar6) - uVar2;
  iVar4 = FUN_002610bc(param_1,uVar2);
  if (iVar4 < 0) {
    uVar5 = 0xffffffff;
  }
  else {
    for (local_c = 0; local_c < uVar3; local_c = local_c + 1) {
      *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) =
           *(ulong *)(*(long *)(param_3 + 2) + (ulong)local_c * 8) |
           *(ulong *)(*(long *)(param_2 + 2) + (ulong)local_c * 8);
    }
    if (uVar6 != uVar1) {
      local_c = uVar3;
      if (uVar3 < uVar6) {
        if (param_3[4] == 0) {
          for (; local_c < uVar2; local_c = local_c + 1) {
            *(undefined8 *)((ulong)local_c * 8 + *(long *)(param_1 + 2)) =
                 *(undefined8 *)(*(long *)(param_2 + 2) + (ulong)local_c * 8);
          }
        }
        else {
          *param_1 = uVar3;
        }
      }
      else if (param_2[4] == 0) {
        for (; local_c < uVar2; local_c = local_c + 1) {
          *(undefined8 *)((ulong)local_c * 8 + *(long *)(param_1 + 2)) =
               *(undefined8 *)(*(long *)(param_3 + 2) + (ulong)local_c * 8);
        }
      }
      else {
        *param_1 = uVar3;
      }
    }
    if ((param_2[4] == 0) && (param_3[4] == 0)) {
      uVar6 = 0;
    }
    else {
      uVar6 = 1;
    }
    param_1[4] = uVar6;
    uVar5 = 0;
  }
  return uVar5;
}


// ===== 002626c1 FUN_002626c1 =====

undefined8 FUN_002626c1(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  uint local_c;
  
  uVar6 = *param_2;
  uVar1 = *param_3;
  uVar2 = uVar6;
  if (uVar6 <= uVar1) {
    uVar2 = uVar1;
  }
  uVar3 = (uVar1 + uVar6) - uVar2;
  iVar4 = FUN_002610bc(param_1,uVar2);
  if (iVar4 < 0) {
    uVar5 = 0xffffffff;
  }
  else {
    for (local_c = 0; local_c < uVar3; local_c = local_c + 1) {
      *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) =
           *(ulong *)(*(long *)(param_3 + 2) + (ulong)local_c * 8) &
           *(ulong *)(*(long *)(param_2 + 2) + (ulong)local_c * 8);
    }
    if (uVar6 != uVar1) {
      local_c = uVar3;
      if (uVar3 < uVar6) {
        if (param_3[4] == 0) {
          *param_1 = uVar3;
        }
        else {
          for (; local_c < uVar2; local_c = local_c + 1) {
            *(undefined8 *)((ulong)local_c * 8 + *(long *)(param_1 + 2)) =
                 *(undefined8 *)(*(long *)(param_2 + 2) + (ulong)local_c * 8);
          }
        }
      }
      else if (param_2[4] == 0) {
        *param_1 = uVar3;
      }
      else {
        for (; local_c < uVar2; local_c = local_c + 1) {
          *(undefined8 *)((ulong)local_c * 8 + *(long *)(param_1 + 2)) =
               *(undefined8 *)(*(long *)(param_3 + 2) + (ulong)local_c * 8);
        }
      }
    }
    if ((param_2[4] == 0) || (param_3[4] == 0)) {
      uVar6 = 0;
    }
    else {
      uVar6 = 1;
    }
    param_1[4] = uVar6;
    uVar5 = 0;
  }
  return uVar5;
}


// ===== 00262868 FUN_00262868 =====

undefined8 FUN_00262868(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  uint local_c;
  
  uVar6 = *param_2;
  uVar1 = *param_3;
  uVar2 = uVar6;
  if (uVar6 <= uVar1) {
    uVar2 = uVar1;
  }
  uVar3 = (uVar1 + uVar6) - uVar2;
  iVar4 = FUN_002610bc(param_1,uVar2);
  if (iVar4 < 0) {
    uVar5 = 0xffffffff;
  }
  else {
    for (local_c = 0; local_c < uVar3; local_c = local_c + 1) {
      *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) =
           *(ulong *)(*(long *)(param_2 + 2) + (ulong)local_c * 8) &
           ~*(ulong *)(*(long *)(param_3 + 2) + (ulong)local_c * 8);
    }
    if (uVar6 != uVar1) {
      local_c = uVar3;
      if (uVar3 < uVar6) {
        if (param_3[4] == 0) {
          for (; local_c < uVar2; local_c = local_c + 1) {
            *(undefined8 *)((ulong)local_c * 8 + *(long *)(param_1 + 2)) =
                 *(undefined8 *)(*(long *)(param_2 + 2) + (ulong)local_c * 8);
          }
        }
        else {
          *param_1 = uVar3;
        }
      }
      else if (param_2[4] == 0) {
        *param_1 = uVar3;
      }
      else {
        for (; local_c < uVar2; local_c = local_c + 1) {
          *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8) =
               ~*(ulong *)(*(long *)(param_3 + 2) + (ulong)local_c * 8);
        }
      }
    }
    if ((param_2[4] == 0) || (param_3[4] != 0)) {
      uVar6 = 0;
    }
    else {
      uVar6 = 1;
    }
    param_1[4] = uVar6;
    uVar5 = 0;
  }
  return uVar5;
}


// ===== 00262a17 FUN_00262a17 =====

undefined8 FUN_00262a17(long param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  uint local_c;
  
  uVar1 = *param_2;
  iVar2 = FUN_002610bc(param_1,uVar1);
  if (iVar2 < 0) {
    uVar3 = 0xffffffff;
  }
  else {
    for (local_c = 0; local_c < uVar1; local_c = local_c + 1) {
      *(ulong *)(*(long *)(param_1 + 8) + (ulong)local_c * 8) =
           ~*(ulong *)(*(long *)(param_2 + 2) + (ulong)local_c * 8);
    }
    *(uint *)(param_1 + 0x10) = (uint)(param_2[4] == 0);
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 00262aab FUN_00262aab =====

int FUN_00262aab(uint *param_1)

{
  ulong uVar1;
  long lVar2;
  int iVar3;
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (*param_1 <= local_c) {
      if (param_1[4] == 0) {
        iVar3 = -1;
      }
      else {
        iVar3 = *param_1 << 6;
      }
      return iVar3;
    }
    uVar1 = *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8);
    if (uVar1 != 0) break;
    local_c = local_c + 1;
  }
  lVar2 = 0;
  if (uVar1 != 0) {
    for (; (uVar1 >> lVar2 & 1) == 0; lVar2 = lVar2 + 1) {
    }
  }
  iVar3 = (int)lVar2;
  if (uVar1 == 0) {
    iVar3 = -1;
  }
  return local_c * 0x40 + iVar3;
}


// ===== 00262b2e FUN_00262b2e =====

int FUN_00262b2e(int *param_1)

{
  long lVar1;
  int iVar2;
  int local_c;
  
  if (param_1[4] == 0) {
    local_c = *param_1;
    do {
      local_c = local_c + -1;
      if (local_c < 0) {
        return -1;
      }
      lVar1 = *(long *)(*(long *)(param_1 + 2) + (long)local_c * 8);
    } while (lVar1 == 0);
    iVar2 = FUN_00260da0(lVar1);
    iVar2 = local_c * 0x40 + iVar2 + -1;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}


// ===== 00262ba7 FUN_00262ba7 =====

int FUN_00262ba7(uint *param_1,uint param_2)

{
  long lVar1;
  byte bVar2;
  int iVar3;
  ulong local_18;
  uint local_c;
  
  iVar3 = param_2 + 1;
  if ((int)(param_2 + 1) < 0) {
    iVar3 = param_2 + 0x40;
  }
  local_c = iVar3 >> 6;
  if (local_c < *param_1) {
    for (; local_c < *param_1; local_c = local_c + 1) {
      local_18 = *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8);
      if ((-1 < (int)param_2) && (local_c == param_2 >> 6)) {
        bVar2 = (byte)((int)param_2 >> 0x1f);
        local_18 = local_18 &
                   ~(0xffffffffffffffffU >>
                    (0x3f - (((char)param_2 + (bVar2 >> 2) & 0x3f) - (bVar2 >> 2)) & 0x3f));
      }
      if (local_18 != 0) {
        lVar1 = 0;
        if (local_18 != 0) {
          for (; (local_18 >> lVar1 & 1) == 0; lVar1 = lVar1 + 1) {
          }
        }
        iVar3 = (int)lVar1;
        if (local_18 == 0) {
          iVar3 = -1;
        }
        return local_c * 0x40 + iVar3;
      }
    }
    if (param_1[4] == 0) {
      iVar3 = -1;
    }
    else {
      iVar3 = *param_1 << 6;
    }
  }
  else if (param_1[4] == 0) {
    iVar3 = -1;
  }
  else {
    iVar3 = param_2 + 1;
  }
  return iVar3;
}


// ===== 00262ca9 FUN_00262ca9 =====

uint FUN_00262ca9(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint local_c;
  
  uVar1 = *param_1;
  uVar2 = *param_2;
  uVar6 = uVar1;
  if (uVar1 <= uVar2) {
    uVar6 = uVar2;
  }
  uVar6 = (uVar2 + uVar1) - uVar6;
  for (local_c = 0; local_c < uVar6; local_c = local_c + 1) {
    uVar4 = *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8);
    uVar3 = *(ulong *)(*(long *)(param_2 + 2) + (ulong)local_c * 8);
    if ((uVar4 != 0) || (uVar3 != 0)) {
      lVar5 = 0;
      if (uVar4 != 0) {
        for (; (uVar4 >> lVar5 & 1) == 0; lVar5 = lVar5 + 1) {
        }
      }
      iVar7 = (int)lVar5;
      if (uVar4 == 0) {
        iVar7 = -1;
      }
      iVar7 = iVar7 + 1;
      lVar5 = 0;
      if (uVar3 != 0) {
        for (; (uVar3 >> lVar5 & 1) == 0; lVar5 = lVar5 + 1) {
        }
      }
      iVar8 = (int)lVar5;
      if (uVar3 == 0) {
        iVar8 = -1;
      }
      iVar8 = iVar8 + 1;
      if ((iVar7 != 0) && (iVar8 != 0)) {
        return iVar7 - iVar8;
      }
      return iVar8 - iVar7;
    }
  }
  if (uVar1 != uVar2) {
    local_c = uVar6;
    if (uVar6 < uVar2) {
      for (; local_c < uVar2; local_c = local_c + 1) {
        uVar4 = *(ulong *)(*(long *)(param_2 + 2) + (ulong)local_c * 8);
        if (param_1[4] != 0) {
          return -(uint)((uVar4 & 1) == 0);
        }
        if (uVar4 != 0) {
          return 1;
        }
      }
    }
    else {
      for (; local_c < uVar1; local_c = local_c + 1) {
        uVar4 = *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_c * 8);
        if (param_2[4] != 0) {
          return (uint)((uVar4 & 1) == 0);
        }
        if (uVar4 != 0) {
          return 0xffffffff;
        }
      }
    }
  }
  return (uint)(param_1[4] != 0) - (uint)(param_2[4] != 0);
}


// ===== 00262e86 FUN_00262e86 =====

int FUN_00262e86(uint *param_1)

{
  int iVar1;
  uint local_10;
  int local_c;
  
  local_c = 0;
  if (param_1[4] == 0) {
    for (local_10 = 0; local_10 < *param_1; local_10 = local_10 + 1) {
      iVar1 = FUN_00260e56(*(undefined8 *)(*(long *)(param_1 + 2) + (ulong)local_10 * 8));
      local_c = local_c + iVar1;
    }
  }
  else {
    local_c = -1;
  }
  return local_c;
}


// ===== 00262ee8 FUN_00262ee8 =====

int FUN_00262ee8(uint *param_1,uint *param_2)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  ulong uVar4;
  ulong uVar5;
  uint local_18;
  int local_c;
  
  uVar3 = *param_1;
  if (*param_1 <= *param_2) {
    uVar3 = *param_2;
  }
  local_c = 0;
  bVar2 = true;
  bVar1 = true;
  local_18 = 0;
  do {
    if (uVar3 <= local_18) {
      if (param_1[4] == 0) {
        if (param_2[4] != 0) {
          if (local_c == 2) {
            if (bVar1) {
              local_c = 4;
            }
            else {
              local_c = 3;
            }
          }
          else if (local_c == 0) {
            local_c = 1;
          }
        }
      }
      else if (param_2[4] == 0) {
        if (local_c == 1) {
          if (bVar2) {
            local_c = 4;
          }
          else {
            local_c = 3;
          }
        }
        else if (local_c == 0) {
          local_c = 2;
        }
      }
      else if (local_c == 4) {
        local_c = 3;
      }
      return local_c;
    }
    if (local_18 < *param_1) {
      uVar4 = *(ulong *)(*(long *)(param_1 + 2) + (ulong)local_18 * 8);
    }
    else if (param_1[4] == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0xffffffffffffffff;
    }
    if (local_18 < *param_2) {
      uVar5 = *(ulong *)(*(long *)(param_2 + 2) + (ulong)local_18 * 8);
    }
    else if (param_2[4] == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = 0xffffffffffffffff;
    }
    if (uVar4 == 0) {
      if (uVar5 != 0) {
        if (local_c == 2) {
          if (!bVar1) {
            return 3;
          }
          local_c = 4;
        }
        else if (local_c == 0) {
          local_c = 1;
        }
        goto LAB_0026310b;
      }
    }
    else {
      if (uVar5 == 0) {
        if (local_c == 1) {
          if (!bVar2) {
            return 3;
          }
          local_c = 4;
        }
        else if (local_c == 0) {
          local_c = 2;
        }
      }
      else if (uVar4 == uVar5) {
        if (local_c == 4) {
          return 3;
        }
      }
      else if (uVar4 == (uVar4 & uVar5)) {
        if ((local_c == 2) || (local_c == 4)) {
          return 3;
        }
        local_c = 1;
      }
      else if (uVar5 == (uVar4 & uVar5)) {
        if ((local_c == 1) || (local_c == 4)) {
          return 3;
        }
        local_c = 2;
      }
      else {
        if ((uVar4 & uVar5) != 0) {
          return 3;
        }
        if ((local_c == 0) && (!bVar2)) {
          return 3;
        }
        if ((local_c == 1) && (!bVar2)) {
          return 3;
        }
        if ((local_c == 2) && (!bVar1)) {
          return 3;
        }
        local_c = 4;
      }
LAB_0026310b:
      bVar2 = (bool)(bVar2 & uVar4 == 0);
      bVar1 = (bool)(bVar1 & uVar5 == 0);
    }
    local_18 = local_18 + 1;
  } while( true );
}


// ===== 002631c3 FUN_002631c3 =====

void FUN_002631c3(undefined8 param_1)

{
  FUN_002580d2(param_1,0,0);
  return;
}


// ===== 002631e7 FUN_002631e7 =====

undefined8 FUN_002631e7(long param_1,char *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (*(uint *)(param_1 + 0xe0) <= local_c) {
      return 0;
    }
    puVar2 = (undefined8 *)(*(long *)(param_1 + 0xd8) + (ulong)local_c * 0x10);
    iVar1 = strcmp((char *)*puVar2,param_2);
    if (iVar1 == 0) break;
    local_c = local_c + 1;
  }
  return puVar2[1];
}


// ===== 00263257 FUN_00263257 =====

void FUN_00263257(void)

{
  return;
}


// ===== 002632b0 FUN_002632b0 =====

void FUN_002632b0(long param_1,char *param_2,uint *param_3)

{
  int iVar1;
  void *pvVar2;
  undefined1 local_38 [4];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  void *local_28;
  undefined8 local_20;
  char *local_18;
  uint local_c;
  
  local_c = *(uint *)(param_1 + 0x354);
  iVar1 = sscanf(param_2,"%x:%x-%x %x",&local_2c,&local_30,&local_34,local_38);
  if (iVar1 != 4) {
    iVar1 = sscanf(param_2,"%x:%x %x",&local_2c,&local_30,local_38);
    if (iVar1 == 3) {
      local_34 = local_30;
    }
    else {
      iVar1 = sscanf(param_2,"%x %x",&local_2c,local_38);
      if (iVar1 != 2) {
        return;
      }
      local_30 = 0;
      local_34 = 0xff;
    }
  }
  local_18 = strchr(param_2,0x20);
  if (local_18 == (char *)0x0) {
    return;
  }
  local_18 = local_18 + 1;
  local_20 = FUN_00260eab();
  FUN_002615d6(local_20,local_18);
  if (*param_3 == 0) {
    pvVar2 = malloc(0x18);
    *(void **)(param_1 + 0x358) = pvVar2;
    if (*(long *)(param_1 + 0x358) == 0) {
LAB_0026350c:
      FUN_00260f71(local_20);
      return;
    }
    *param_3 = 1;
  }
  else if (*param_3 <= local_c) {
    local_28 = realloc(*(void **)(param_1 + 0x358),(ulong)(*param_3 * 2) * 0x18);
    if (local_28 == (void *)0x0) goto LAB_0026350c;
    *(void **)(param_1 + 0x358) = local_28;
    *param_3 = *param_3 * 2;
  }
  *(undefined4 *)(*(long *)(param_1 + 0x358) + (ulong)local_c * 0x18) = local_2c;
  *(undefined4 *)(*(long *)(param_1 + 0x358) + (ulong)local_c * 0x18 + 4) = local_30;
  *(undefined4 *)(*(long *)(param_1 + 0x358) + (ulong)local_c * 0x18 + 8) = local_34;
  *(undefined8 *)(*(long *)(param_1 + 0x358) + (ulong)local_c * 0x18 + 0x10) = local_20;
  *(int *)(param_1 + 0x354) = *(int *)(param_1 + 0x354) + 1;
  return;
}


// ===== 00263521 FUN_00263521 =====

void FUN_00263521(undefined8 param_1,char *param_2)

{
  undefined4 local_2c;
  size_t local_28;
  char *local_20;
  char *local_18;
  char *local_10;
  
  local_20 = strdup(param_2);
  local_2c = 0;
  local_10 = local_20;
  while( true ) {
    local_28 = strcspn(local_10,";\r\n");
    local_18 = (char *)0x0;
    if ((local_10[local_28] != '\0') && (local_10[local_28] = '\0', local_10[local_28 + 1] != '\0'))
    {
      local_18 = local_10 + local_28 + 1;
    }
    FUN_002632b0(param_1,local_10,&local_2c);
    if (local_18 == (char *)0x0) break;
    local_10 = local_18;
  }
  free(local_20);
  return;
}


// ===== 002635f3 FUN_002635f3 =====

void FUN_002635f3(long param_1)

{
  *(undefined4 *)(param_1 + 0x350) = 0;
  *(undefined4 *)(param_1 + 0x354) = 0;
  *(undefined8 *)(param_1 + 0x358) = 0;
  *(undefined8 *)(param_1 + 0x380) = 0;
  *(undefined8 *)(param_1 + 0x378) = *(undefined8 *)(param_1 + 0x380);
  *(undefined8 *)(param_1 + 0x360) = 0xffffffffffffffff;
  return;
}


// ===== 0026365d FUN_0026365d =====

void FUN_0026365d(long param_1)

{
  int iVar1;
  size_t sVar2;
  undefined1 local_b8 [48];
  size_t local_88;
  void *local_20;
  int local_18;
  int local_14;
  char *local_10;
  
  local_10 = getenv("HWLOC_PCI_LOCALITY");
  if (local_10 != (char *)0x0) {
    *(undefined4 *)(param_1 + 0x350) = 1;
    local_14 = open(local_10,0);
    if (local_14 < 0) {
      FUN_00263521(param_1,local_10);
    }
    else {
      local_18 = FUN_002935c0(local_14,local_b8);
      if (local_18 == 0) {
        if ((long)local_88 < 0x10001) {
          local_20 = malloc(local_88 + 1);
          if (local_20 != (void *)0x0) {
            sVar2 = read(local_14,local_20,local_88);
            if (sVar2 == local_88) {
              *(undefined1 *)((long)local_20 + local_88) = 0;
              FUN_00263521(param_1,local_20);
            }
          }
          free(local_20);
        }
        else {
          iVar1 = FUN_0024d64f();
          if (iVar1 < 2) {
            fprintf(*(FILE **)PTR_stderr_0032efe0,
                    "hwloc/pci: Ignoring HWLOC_PCI_LOCALITY file `%s\' too large (%lu bytes)\n",
                    local_10,local_88);
          }
        }
      }
      close(local_14);
    }
  }
  return;
}


// ===== 002637b7 FUN_002637b7 =====

void FUN_002637b7(long param_1)

{
  void *pvVar1;
  undefined4 local_14;
  undefined8 local_10;
  
  for (local_14 = 0; local_14 < *(uint *)(param_1 + 0x354); local_14 = local_14 + 1) {
    FUN_00260f71(*(undefined8 *)((ulong)local_14 * 0x18 + *(long *)(param_1 + 0x358) + 0x10));
  }
  free(*(void **)(param_1 + 0x358));
  local_10 = *(void **)(param_1 + 0x378);
  while (local_10 != (void *)0x0) {
    pvVar1 = *(void **)((long)local_10 + 0x28);
    FUN_00260f71(*(undefined8 *)((long)local_10 + 0x10));
    free(local_10);
    local_10 = pvVar1;
  }
  FUN_002635f3(param_1);
  return;
}


// ===== 00263873 FUN_00263873 =====

undefined8 FUN_00263873(int *param_1,int *param_2)

{
  undefined8 uVar1;
  
  if (**(ushort **)(param_1 + 10) < **(ushort **)(param_2 + 10)) {
    uVar1 = 0;
  }
  else if (**(ushort **)(param_2 + 10) < **(ushort **)(param_1 + 10)) {
    uVar1 = 1;
  }
  else if ((((*param_1 == 0xe) && (*(int *)(*(long *)(param_1 + 10) + 0x20) == 1)) &&
           (*(byte *)(*(long *)(param_1 + 10) + 0x1e) <= *(byte *)(*(long *)(param_2 + 10) + 2))) &&
          (*(byte *)(*(long *)(param_2 + 10) + 2) <= *(byte *)(*(long *)(param_1 + 10) + 0x1f))) {
    uVar1 = 3;
  }
  else if (((*param_2 == 0xe) && (*(int *)(*(long *)(param_2 + 10) + 0x20) == 1)) &&
          ((*(byte *)(*(long *)(param_2 + 10) + 0x1e) <= *(byte *)(*(long *)(param_1 + 10) + 2) &&
           (*(byte *)(*(long *)(param_1 + 10) + 2) <= *(byte *)(*(long *)(param_2 + 10) + 0x1f)))))
  {
    uVar1 = 2;
  }
  else if (*(byte *)(*(long *)(param_1 + 10) + 2) < *(byte *)(*(long *)(param_2 + 10) + 2)) {
    uVar1 = 0;
  }
  else if (*(byte *)(*(long *)(param_2 + 10) + 2) < *(byte *)(*(long *)(param_1 + 10) + 2)) {
    uVar1 = 1;
  }
  else if (*(byte *)(*(long *)(param_1 + 10) + 3) < *(byte *)(*(long *)(param_2 + 10) + 3)) {
    uVar1 = 0;
  }
  else if (*(byte *)(*(long *)(param_2 + 10) + 3) < *(byte *)(*(long *)(param_1 + 10) + 3)) {
    uVar1 = 1;
  }
  else if (*(byte *)(*(long *)(param_1 + 10) + 4) < *(byte *)(*(long *)(param_2 + 10) + 4)) {
    uVar1 = 0;
  }
  else if (*(byte *)(*(long *)(param_2 + 10) + 4) < *(byte *)(*(long *)(param_1 + 10) + 4)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}


// ===== 00263a62 FUN_00263a62 =====

void FUN_00263a62(undefined8 param_1,long *param_2,int *param_3)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  long *local_18;
  long *local_10;
  
  local_10 = param_2;
  do {
    if (*local_10 == 0) {
      *(undefined8 *)(param_3 + 0x12) = param_1;
      param_3[0x16] = 0;
      param_3[0x17] = 0;
      *local_10 = (long)param_3;
      return;
    }
    uVar2 = FUN_00263873(param_3,*local_10);
    switch(uVar2) {
    case 0:
    case 3:
      *(long *)(param_3 + 0x16) = *local_10;
      *local_10 = (long)param_3;
      *(undefined8 *)(param_3 + 0x12) = param_1;
      if ((*param_3 == 0xe) && (*(int *)(*(long *)(param_3 + 10) + 0x20) == 1)) {
        local_18 = (long *)(param_3 + 0x28);
        local_10 = (long *)(param_3 + 0x16);
        while (*local_10 != 0) {
          lVar1 = *local_10;
          iVar3 = FUN_00263873(param_3,lVar1);
          if (iVar3 == 0) {
            if (**(ushort **)(param_3 + 10) < **(ushort **)(lVar1 + 0x28)) {
              return;
            }
            if (*(byte *)(*(long *)(param_3 + 10) + 0x1f) < *(byte *)(*(long *)(lVar1 + 0x28) + 2))
            {
              return;
            }
            local_10 = (long *)(lVar1 + 0x58);
          }
          else {
            *local_18 = lVar1;
            *local_10 = *(long *)(lVar1 + 0x58);
            *(int **)(*local_18 + 0x48) = param_3;
            *(undefined8 *)(*local_18 + 0x58) = 0;
            local_18 = (long *)(*local_18 + 0x58);
          }
        }
      }
      return;
    case 1:
      local_10 = (long *)(*local_10 + 0x58);
      break;
    case 2:
      FUN_00263a62(*local_10,*local_10 + 0xa0,param_3);
      return;
    case 4:
      if ((DAT_01218354 == 0) && (iVar3 = FUN_0024d64f(), iVar3 < 2)) {
        fwrite("*********************************************************\n",1,0x3a,
               *(FILE **)PTR_stderr_0032efe0);
        fprintf(*(FILE **)PTR_stderr_0032efe0,"* hwloc %s received invalid PCI information.\n",
                "2.9.2");
        fwrite(&DAT_002ed4fe,1,2,*(FILE **)PTR_stderr_0032efe0);
        fprintf(*(FILE **)PTR_stderr_0032efe0,
                "* Trying to insert PCI object %04x:%02x:%02x.%01x at %04x:%02x:%02x.%01x\n",
                (ulong)**(ushort **)(param_3 + 10),(ulong)*(byte *)(*(long *)(param_3 + 10) + 2),
                (ulong)*(byte *)(*(long *)(param_3 + 10) + 3),
                (ulong)*(byte *)(*(long *)(param_3 + 10) + 4),(ulong)**(ushort **)(*local_10 + 0x28)
                ,(ulong)*(byte *)(*(long *)(*local_10 + 0x28) + 2),
                (ulong)*(byte *)(*(long *)(*local_10 + 0x28) + 3),
                (ulong)*(byte *)(*(long *)(*local_10 + 0x28) + 4));
        fwrite(&DAT_002ed4fe,1,2,*(FILE **)PTR_stderr_0032efe0);
        fwrite("* hwloc will now ignore this object and continue.\n",1,0x32,
               *(FILE **)PTR_stderr_0032efe0);
        fwrite("*********************************************************\n",1,0x3a,
               *(FILE **)PTR_stderr_0032efe0);
        DAT_01218354 = 1;
      }
      FUN_0024e0d0(param_3);
      return;
    }
  } while( true );
}


// ===== 00263e31 FUN_00263e31 =====

void FUN_00263e31(undefined8 param_1,undefined8 param_2)

{
  FUN_00263a62(0,param_1,param_2);
  return;
}


// ===== 00263e59 FUN_00263e59 =====

/* WARNING: Restarted to delay deadcode elimination for space: stack */

long FUN_00263e59(undefined8 param_1,int *param_2)

{
  int *local_58;
  undefined8 local_50;
  long local_48;
  byte local_3d;
  uint local_3c;
  int **local_38;
  long local_30;
  byte local_21;
  int *local_20;
  int *local_18;
  long *local_10;
  
  local_48 = 0;
  local_10 = &local_48;
  local_58 = param_2;
  local_50 = param_1;
  while( true ) {
    if (local_58 == (int *)0x0) {
      return local_48;
    }
    local_30 = FUN_0024febd(local_50,0xe,0xffffffff);
    if (local_30 == 0) break;
    local_18 = (int *)(local_30 + 0xa0);
    local_38 = &local_58;
    local_20 = local_58;
    local_3c = (uint)**(ushort **)(local_58 + 10);
    local_3d = *(byte *)(*(long *)(local_58 + 10) + 2);
    local_21 = local_3d;
    FUN_00263257("Adding new PCI hostbridge %04x:%02x\n",local_3c,local_3d);
    do {
      *local_38 = *(int **)(local_20 + 0x16);
      *(int **)local_18 = local_20;
      *(long *)(local_20 + 0x12) = local_30;
      local_20[0x16] = 0;
      local_20[0x17] = 0;
      local_18 = local_20 + 0x16;
      if (((*local_20 == 0xe) && (*(int *)(*(long *)(local_20 + 10) + 0x20) == 1)) &&
         (local_21 < *(byte *)(*(long *)(local_20 + 10) + 0x1f))) {
        local_21 = *(byte *)(*(long *)(local_20 + 10) + 0x1f);
      }
      local_20 = *local_38;
    } while (((local_20 != (int *)0x0) && (local_3c == **(ushort **)(local_20 + 10))) &&
            (local_3d == *(byte *)(*(long *)(local_20 + 10) + 2)));
    *(undefined4 *)(*(long *)(local_30 + 0x28) + 0x18) = 0;
    *(undefined4 *)(*(long *)(local_30 + 0x28) + 0x20) = 1;
    *(short *)(*(long *)(local_30 + 0x28) + 0x1c) = (short)local_3c;
    *(byte *)(*(long *)(local_30 + 0x28) + 0x1e) = local_3d;
    *(byte *)(*(long *)(local_30 + 0x28) + 0x1f) = local_21;
    FUN_00263257("  new PCI hostbridge covers %04x:[%02x-%02x]\n",local_3c,local_3d,local_21);
    *local_10 = local_30;
    local_10 = (long *)(local_30 + 0x58);
  }
  *local_10 = (long)local_58;
  return local_48;
}


// ===== 0026405c FUN_0026405c =====

undefined8 FUN_0026405c(long param_1,short *param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  char *pcVar4;
  
  if (*(long *)(param_1 + 0x360) == -1) {
    *(undefined8 *)(param_1 + 0x360) = 0;
    uVar3 = FUN_002631c3(param_1);
    pcVar4 = (char *)FUN_002631e7(uVar3,"DMIBoardName");
    if ((pcVar4 != (char *)0x0) && (iVar1 = strcmp(pcVar4,"HPE CRAY EX235A"), iVar1 == 0)) {
      FUN_00263257("enabling for PCI locality quirk for HPE Cray EX235A\n");
      *(ulong *)(param_1 + 0x360) = *(ulong *)(param_1 + 0x360) | 1;
    }
    pcVar4 = getenv("HWLOC_PCI_LOCALITY_QUIRK_FAKE");
    if ((pcVar4 != (char *)0x0) && (iVar1 = atoi(pcVar4), iVar1 != 0)) {
      FUN_00263257("enabling for PCI locality fake quirk (attaching everything to last PU)\n");
      *(ulong *)(param_1 + 0x360) = *(ulong *)(param_1 + 0x360) | 0x4000000000000000;
    }
  }
  if ((*(ulong *)(param_1 + 0x360) & 0x4000000000000000) != 0) {
    uVar3 = FUN_00255632(param_1);
    uVar2 = FUN_00262b2e(uVar3);
    FUN_0026197d(param_3,uVar2);
    return 1;
  }
  if (((*(ulong *)(param_1 + 0x360) & 1) != 0) && (*param_2 == 0)) {
    if ((0xcf < *(byte *)(param_2 + 1)) && (*(byte *)(param_2 + 1) < 0xd2)) {
      FUN_00261a1b(param_3,0,7);
      FUN_00261a1b(param_3,0x40,0x47);
      return 1;
    }
    if ((0xd3 < *(byte *)(param_2 + 1)) && (*(byte *)(param_2 + 1) < 0xd7)) {
      FUN_00261a1b(param_3,8,0xf);
      FUN_00261a1b(param_3,0x48,0x4f);
      return 1;
    }
    if ((199 < *(byte *)(param_2 + 1)) && (*(byte *)(param_2 + 1) < 0xca)) {
      FUN_00261a1b(param_3,0x10,0x17);
      FUN_00261a1b(param_3,0x50,0x57);
      return 1;
    }
    if ((0xcb < *(byte *)(param_2 + 1)) && (*(byte *)(param_2 + 1) < 0xcf)) {
      FUN_00261a1b(param_3,0x18,0x1f);
      FUN_00261a1b(param_3,0x58,0x5f);
      return 1;
    }
    if ((0xd7 < *(byte *)(param_2 + 1)) && (*(byte *)(param_2 + 1) < 0xda)) {
      FUN_00261a1b(param_3,0x20,0x27);
      FUN_00261a1b(param_3,0x60,0x67);
      return 1;
    }
    if ((0xdb < *(byte *)(param_2 + 1)) && (*(byte *)(param_2 + 1) < 0xdf)) {
      FUN_00261a1b(param_3,0x28,0x2f);
      FUN_00261a1b(param_3,0x68,0x6f);
      return 1;
    }
    if ((0xbf < *(byte *)(param_2 + 1)) && (*(byte *)(param_2 + 1) < 0xc2)) {
      FUN_00261a1b(param_3,0x30,0x37);
      FUN_00261a1b(param_3,0x70,0x77);
      return 1;
    }
    if ((0xc3 < *(byte *)(param_2 + 1)) && (*(byte *)(param_2 + 1) < 199)) {
      FUN_00261a1b(param_3,0x38,0x3f);
      FUN_00261a1b(param_3,0x78,0x7f);
      return 1;
    }
  }
  return 0;
}


// ===== 00264441 FUN_00264441 =====

long FUN_00264441(long param_1,ushort *param_2)

{
  int iVar1;
  undefined8 uVar2;
  char local_148 [264];
  long local_40;
  char *local_38;
  undefined8 local_30;
  int local_24;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  long local_10;
  
  local_30 = FUN_00260eab();
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  FUN_00263257("Looking for parent of PCI busid %04x:%02x:%02x.%01x\n",*param_2,(char)param_2[1],
               *(undefined1 *)((long)param_2 + 3),(char)param_2[2]);
  if (*(int *)(param_1 + 0x350) != 0) {
    for (local_20 = 0; local_20 < *(uint *)(param_1 + 0x354); local_20 = local_20 + 1) {
      if ((((uint)*param_2 == *(uint *)((ulong)local_20 * 0x18 + *(long *)(param_1 + 0x358))) &&
          (*(uint *)((ulong)local_20 * 0x18 + *(long *)(param_1 + 0x358) + 4) <=
           (uint)(byte)param_2[1])) &&
         ((uint)(byte)param_2[1] <=
          *(uint *)((ulong)local_20 * 0x18 + *(long *)(param_1 + 0x358) + 8))) {
        FUN_00261201(local_30,*(undefined8 *)
                               ((ulong)local_20 * 0x18 + *(long *)(param_1 + 0x358) + 0x10));
        local_14 = 1;
        break;
      }
    }
    local_18 = 1;
  }
  if (local_14 == 0) {
    snprintf(local_148,0x100,"HWLOC_PCI_%04x_%02x_LOCALCPUS",(ulong)*param_2,(ulong)(byte)param_2[1]
            );
    local_38 = getenv(local_148);
    if (local_38 != (char *)0x0) {
      if ((*(int *)(param_1 + 0x350) == 0) && (DAT_01218358 == 0)) {
        iVar1 = FUN_0024d64f();
        if (iVar1 == 0) {
          fprintf(*(FILE **)PTR_stderr_0032efe0,
                  "hwloc/pci: Environment variable %s is deprecated, please use HWLOC_PCI_LOCALITY instead.\n"
                  ,local_38);
        }
        DAT_01218358 = 1;
      }
      if (*local_38 != '\0') {
        FUN_00263257("Overriding PCI locality using %s in the environment\n",local_148);
        FUN_002615d6(local_30,local_38);
        local_14 = 1;
      }
      local_18 = 1;
    }
  }
  if (((local_14 == 0) && (local_18 == 0)) && (*(long *)(param_1 + 0x360) != 0)) {
    local_24 = FUN_0026405c(param_1,param_2,local_30);
    if (0 < local_24) {
      local_1c = 1;
    }
  }
  if ((local_14 == 0) && (local_1c == 0)) {
    local_40 = *(long *)(param_1 + 800);
    if (local_40 == 0) {
      local_24 = -1;
    }
    else {
      local_24 = (**(code **)(local_40 + 0x50))(local_40,param_2,local_30);
    }
    if (local_24 < 0) {
      uVar2 = FUN_00255632(param_1);
      FUN_00261201(local_30,uVar2);
    }
  }
  local_10 = FUN_002500cd(param_1,local_30);
  if (local_10 == 0) {
    local_10 = FUN_002631c3(param_1);
  }
  FUN_00260f71(local_30);
  return local_10;
}


// ===== 002647ed FUN_002647ed =====

undefined8 FUN_002647ed(long param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int *piVar8;
  uint *__ptr;
  undefined8 uVar9;
  int *local_68;
  uint local_44;
  uint local_40;
  uint local_3c;
  undefined4 *local_38;
  int *local_30;
  
  if (param_2 != (int *)0x0) {
    local_68 = param_2;
    if (*(int *)(param_1 + 0xb0) != 1) {
      local_68 = (int *)FUN_00263e59(param_1,param_2);
    }
    while (local_68 != (int *)0x0) {
      if ((*local_68 == 0xe) && (*(int *)(*(long *)(local_68 + 10) + 0x18) == 0)) {
        local_30 = *(int **)(local_68 + 0x28);
      }
      else {
        local_30 = local_68;
      }
      if ((*local_30 != 0xf) &&
         ((*local_30 != 0xe || (*(int *)(*(long *)(local_30 + 10) + 0x18) != 1)))) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("pciobj->type == HWLOC_OBJ_PCI_DEVICE || (pciobj->type == HWLOC_OBJ_BRIDGE && pciobj->attr->bridge.upstream_type == HWLOC_OBJ_BRIDGE_PCI)"
                      ,
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/pci-common.c"
                      ,0x291,"hwloc_pcidisc_tree_attach");
      }
      if ((*local_68 == 0xe) && (*(int *)(*(long *)(local_68 + 10) + 0x20) == 1)) {
        uVar3 = *(ushort *)(*(long *)(local_68 + 10) + 0x1c);
        bVar1 = *(byte *)(*(long *)(local_68 + 10) + 0x1e);
        bVar2 = *(byte *)(*(long *)(local_68 + 10) + 0x1f);
      }
      else {
        uVar3 = **(ushort **)(local_30 + 10);
        bVar1 = *(byte *)(*(long *)(local_30 + 10) + 2);
        bVar2 = *(byte *)(*(long *)(local_30 + 10) + 2);
      }
      local_3c = (uint)uVar3;
      local_40 = (uint)bVar1;
      local_44 = (uint)bVar2;
      local_38 = (undefined4 *)FUN_00264441(param_1,*(undefined8 *)(local_30 + 10));
      if ((((*(long *)(param_1 + 0x380) == 0) ||
           (local_38 != *(undefined4 **)(*(long *)(param_1 + 0x380) + 0x18))) ||
          (local_3c != **(uint **)(param_1 + 0x380))) ||
         ((local_40 != *(uint *)(*(long *)(param_1 + 0x380) + 8) &&
          (local_40 != *(int *)(*(long *)(param_1 + 0x380) + 8) + 1U)))) {
        __ptr = malloc(0x30);
        if (__ptr == (uint *)0x0) {
          local_38 = (undefined4 *)FUN_002631c3(param_1);
        }
        else {
          *__ptr = local_3c;
          __ptr[1] = local_40;
          __ptr[2] = local_44;
          *(undefined4 **)(__ptr + 6) = local_38;
          uVar9 = FUN_002611e2(*(undefined8 *)(local_38 + 0x2e));
          *(undefined8 *)(__ptr + 4) = uVar9;
          if (*(long *)(__ptr + 4) == 0) {
            free(__ptr);
            local_38 = (undefined4 *)FUN_002631c3(param_1);
          }
          else {
            uVar4 = __ptr[2];
            uVar5 = __ptr[1];
            uVar6 = *__ptr;
            uVar7 = local_38[4];
            uVar9 = FUN_002582d8(*local_38);
            FUN_00263257("Adding PCI locality %s P#%u for bus %04x:[%02x:%02x]\n",uVar9,uVar7,uVar6,
                         uVar5,uVar4);
            if (*(long *)(param_1 + 0x380) == 0) {
              __ptr[8] = 0;
              __ptr[9] = 0;
              __ptr[10] = 0;
              __ptr[0xb] = 0;
              *(uint **)(param_1 + 0x378) = __ptr;
              *(uint **)(param_1 + 0x380) = __ptr;
            }
            else {
              *(undefined8 *)(__ptr + 8) = *(undefined8 *)(param_1 + 0x380);
              __ptr[10] = 0;
              __ptr[0xb] = 0;
              *(uint **)(*(long *)(param_1 + 0x380) + 0x28) = __ptr;
              *(uint **)(param_1 + 0x380) = __ptr;
            }
          }
        }
      }
      else {
        FUN_00263257("  Reusing PCI locality up to bus %04x:%02x\n",local_3c,local_44);
        *(uint *)(*(long *)(param_1 + 0x380) + 8) = local_44;
      }
      piVar8 = *(int **)(local_68 + 0x16);
      local_68[0x16] = 0;
      local_68[0x17] = 0;
      FUN_0024fc99(param_1,local_38,local_68);
      local_68 = piVar8;
    }
  }
  return 0;
}


// ===== 00264bbb FUN_00264bbb =====

long FUN_00264bbb(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined2 local_28;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 local_24;
  long local_10;
  
  local_10 = FUN_00264e51(param_1,param_2,param_3,param_4,param_5);
  if (local_10 == 0) {
    local_28 = (undefined2)param_2;
    local_26 = (undefined1)param_3;
    local_25 = (undefined1)param_4;
    local_24 = (undefined1)param_5;
    local_10 = FUN_00264441(param_1,&local_28);
  }
  return local_10;
}


// ===== 00264c2e FUN_00264c2e =====

int * FUN_00264c2e(int *param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  int *piVar1;
  int *local_10;
  
  local_10 = *(int **)(param_1 + 0x28);
  do {
    if (local_10 == (int *)0x0) {
      return param_1;
    }
    if ((*local_10 == 0xf) ||
       ((*local_10 == 0xe && (*(int *)(*(long *)(local_10 + 10) + 0x18) == 1)))) {
      if ((param_2 == **(ushort **)(local_10 + 10)) &&
         (((param_3 == *(byte *)(*(long *)(local_10 + 10) + 2) &&
           (param_4 == *(byte *)(*(long *)(local_10 + 10) + 3))) &&
          (param_5 == *(byte *)(*(long *)(local_10 + 10) + 4))))) {
        return local_10;
      }
      if (param_2 < **(ushort **)(local_10 + 10)) {
        return param_1;
      }
      if ((param_2 == **(ushort **)(local_10 + 10)) &&
         (param_3 < *(byte *)(*(long *)(local_10 + 10) + 2))) {
        return param_1;
      }
      if (((*local_10 == 0xe) && (*(int *)(*(long *)(local_10 + 10) + 0x20) == 1)) &&
         ((param_2 == *(ushort *)(*(long *)(local_10 + 10) + 0x1c) &&
          ((*(byte *)(*(long *)(local_10 + 10) + 0x1e) <= param_3 &&
           (param_3 <= *(byte *)(*(long *)(local_10 + 10) + 0x1f))))))) {
        piVar1 = (int *)FUN_00264c2e(local_10,param_2,param_3,param_4,param_5);
        return piVar1;
      }
    }
    else if (((((*local_10 == 0xe) && (*(int *)(*(long *)(local_10 + 10) + 0x18) != 1)) &&
              (*(int *)(*(long *)(local_10 + 10) + 0x20) == 1)) &&
             ((param_2 == *(ushort *)(*(long *)(local_10 + 10) + 0x1c) &&
              (*(byte *)(*(long *)(local_10 + 10) + 0x1e) <= param_3)))) &&
            (param_3 <= *(byte *)(*(long *)(local_10 + 10) + 0x1f))) {
      piVar1 = (int *)FUN_00264c2e(local_10,param_2,param_3,param_4,param_5);
      return piVar1;
    }
    local_10 = *(int **)(local_10 + 0x16);
  } while( true );
}


// ===== 00264e51 FUN_00264e51 =====

int * FUN_00264e51(long param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  int *piVar4;
  int *local_28;
  int *local_20;
  
  piVar2 = (int *)FUN_002631c3(param_1);
  local_28 = (int *)0x0;
  FUN_00263257("pcidisc looking for bus id %04x:%02x:%02x.%01x\n",param_2,param_3,param_4,param_5);
  local_20 = *(int **)(param_1 + 0x378);
  do {
    if (local_20 == (int *)0x0) {
LAB_00264f4e:
      if (local_28 == (int *)0x0) {
        local_28 = piVar2;
      }
      iVar1 = local_28[4];
      uVar3 = FUN_002582d8(*local_28);
      FUN_00263257("  looking for bus %04x:%02x:%02x.%01x below %s P#%u\n",param_2,param_3,param_4,
                   param_5,uVar3,iVar1);
      piVar4 = (int *)FUN_00264c2e(local_28,param_2,param_3,param_4,param_5);
      if (piVar4 == piVar2) {
        FUN_00263257("  found nothing better than root object, ignoring\n");
        piVar4 = (int *)0x0;
      }
      else if ((*piVar4 == 0xf) ||
              ((*piVar4 == 0xe && (*(int *)(*(long *)(piVar4 + 10) + 0x18) == 1)))) {
        FUN_00263257("  found busid %04x:%02x:%02x.%01x\n",**(undefined2 **)(piVar4 + 10),
                     *(undefined1 *)(*(long *)(piVar4 + 10) + 2),
                     *(undefined1 *)(*(long *)(piVar4 + 10) + 3),
                     *(undefined1 *)(*(long *)(piVar4 + 10) + 4));
      }
      else {
        iVar1 = piVar4[4];
        uVar3 = FUN_002582d8(*piVar4);
        FUN_00263257("  found parent %s P#%u\n",uVar3,iVar1);
      }
      return piVar4;
    }
    if (((param_2 == *local_20) && ((uint)local_20[1] <= param_3)) && (param_3 <= (uint)local_20[2])
       ) {
      local_28 = *(int **)(local_20 + 6);
      if (local_28 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("parent",
                      "/home/huyn/work/p4/sw/tools/unix/hosts/Linux-x86/targets/build-scripts/hwloc-2.9.2/hwloc/pci-common.c"
                      ,0x32a,"hwloc_pci_find_by_busid");
      }
      FUN_00263257("  found pci locality for %04x:[%02x:%02x]\n",*local_20,local_20[1],local_20[2]);
      goto LAB_00264f4e;
    }
    local_20 = *(int **)(local_20 + 10);
  } while( true );
}


// ===== 00265093 FUN_00265093 =====

byte FUN_00265093(long param_1,uint param_2)

{
  long lVar1;
  char *pcVar2;
  char local_118 [271];
  byte local_9;
  
  pcVar2 = local_118;
  for (lVar1 = 0x20; lVar1 != 0; lVar1 = lVar1 + -1) {
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    pcVar2[4] = '\0';
    pcVar2[5] = '\0';
    pcVar2[6] = '\0';
    pcVar2[7] = '\0';
    pcVar2 = pcVar2 + 8;
  }
  if ((*(byte *)(param_1 + 6) & 0x10) != 0) {
    local_9 = *(byte *)(param_1 + 0x34);
    while ((local_9 = local_9 & 0xfc, local_9 != 0 && (local_118[(int)(uint)local_9] == '\0'))) {
      local_118[(int)(uint)local_9] = '\x01';
      if (param_2 == *(byte *)(param_1 + (ulong)local_9)) {
        return local_9;
      }
      if (*(byte *)(param_1 + (ulong)local_9) == 0xff) {
        return 0;
      }
      local_9 = *(byte *)(param_1 + (ulong)local_9 + 1);
    }
  }
  return 0;
}


// ===== 00265174 FUN_00265174 =====

/* WARNING: Removing unreachable block (ram,0x002651c1) */
/* WARNING: Removing unreachable block (ram,0x0026528b) */

undefined8 FUN_00265174(long param_1,int param_2,float *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_c;
  
  uVar1 = *(uint *)(param_1 + (ulong)(param_2 + 0x12));
  uVar2 = uVar1 & 0xf;
  if (uVar2 < 3) {
    local_c = (float)uVar2 * DAT_002ede30 * DAT_002ede34;
  }
  else if (uVar2 < 6) {
    local_c = ((float)(1 << ((char)uVar2 - 3U & 0x1f)) * DAT_002ede38 * DAT_002ede3c) / DAT_002ede40
    ;
  }
  else {
    local_c = ((float)(1 << ((char)uVar2 - 3U & 0x1f)) * DAT_002ede38 * DAT_002ede44) / DAT_002ede48
    ;
  }
  *param_3 = ((float)(uVar1 >> 4 & 0x3f) * local_c) / DAT_002ede38;
  return 0;
}


// ===== 002652c0 FUN_002652c0 =====

undefined8 FUN_002652c0(int param_1,long param_2)

{
  undefined8 uVar1;
  
  if (param_1 == 0x604) {
    if ((*(byte *)(param_2 + 0xe) & 0x7f) == 1) {
      uVar1 = 0xe;
    }
    else {
      uVar1 = 0xf;
    }
  }
  else {
    uVar1 = 0xf;
  }
  return uVar1;
}


// ===== 00265300 FUN_00265300 =====

undefined8
FUN_00265300(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint *param_5,
            uint *param_6,long param_7)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  if (param_2 != *(byte *)(param_7 + 0x18)) {
    FUN_00263257("  %04x:%02x:%02x.%01x bridge with (ignored) invalid PCI_PRIMARY_BUS %02x\n",
                 param_1,param_2,param_3,param_4,*(undefined1 *)(param_7 + 0x18));
  }
  uVar1 = (uint)*(byte *)(param_7 + 0x19);
  uVar2 = (uint)*(byte *)(param_7 + 0x1a);
  if (((param_2 < uVar1) && (param_2 < uVar2)) && (uVar1 <= uVar2)) {
    *param_5 = uVar1;
    *param_6 = uVar2;
    uVar3 = 0;
  }
  else {
    FUN_00263257("  %04x:%02x:%02x.%01x bridge has invalid secondary-subordinate buses [%02x-%02x]\n"
                 ,param_1,param_2,param_3,param_4,uVar1,uVar2);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ===== 002653f1 FUN_002653f1 =====

void FUN_002653f1(void *param_1)

{
  FUN_0025f883();
  munmap(*(void **)((long)param_1 + 0xe8),*(size_t *)((long)param_1 + 0xf0));
  free(*(void **)((long)param_1 + 0x288));
  free(*(void **)((long)param_1 + 0x290));
  free(*(void **)((long)param_1 + 0x298));
  free(*(void **)((long)param_1 + 0x2a0));
  free(param_1);
  return;
}


// ===== 0026547e FUN_0026547e =====

undefined8 FUN_0026547e(long param_1,char *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (*(uint *)(param_1 + 0xe0) <= local_c) {
      return 0;
    }
    puVar2 = (undefined8 *)(*(long *)(param_1 + 0xd8) + (ulong)local_c * 0x10);
    iVar1 = strcmp((char *)*puVar2,param_2);
    if (iVar1 == 0) break;
    local_c = local_c + 1;
  }
  return puVar2[1];
}


// ===== 002654ee FUN_002654ee =====

int FUN_002654ee(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                char *param_9,size_t param_10,char *param_11,undefined8 param_12,undefined8 param_13
                ,undefined8 param_14)

{
  char in_AL;
  int *piVar1;
  size_t local_f8;
  char *local_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined1 *local_e0;
  undefined1 *local_d8;
  int local_cc;
  char *local_c8;
  size_t local_c0;
  undefined1 local_b8 [24];
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
  local_f8 = param_10;
  local_f0 = param_9;
  if (param_10 == 0) {
    local_f0 = &DAT_0121835c;
    local_f8 = 1;
  }
  local_e8 = 0x18;
  local_e4 = 0x30;
  local_e0 = &stack0x00000008;
  local_d8 = local_b8;
  local_a0 = param_12;
  local_98 = param_13;
  local_90 = param_14;
  local_cc = vsnprintf(local_f0,local_f8,param_11,&local_e8);
  if ((local_cc < 0) || ((long)local_cc == local_f8 - 1)) {
    local_c0 = local_f8;
    local_c8 = (char *)0x0;
    do {
      local_c0 = local_c0 << 1;
      free(local_c8);
      local_c8 = malloc(local_c0);
      if (local_c8 == (char *)0x0) {
        return -1;
      }
      local_e8 = 0x18;
      local_e4 = 0x30;
      local_e0 = &stack0x00000008;
      local_d8 = local_b8;
      piVar1 = __errno_location();
      *piVar1 = 0;
      local_cc = vsnprintf(local_c8,local_c0,param_11,&local_e8);
    } while (((long)local_cc == local_c0 - 1) ||
            ((local_cc < 0 &&
             ((piVar1 = __errno_location(), *piVar1 == 0 ||
              (piVar1 = __errno_location(), *piVar1 == 0x22))))));
    if ((-1 < local_cc) && (local_f8 != 0)) {
      if ((long)local_cc + 1U < local_f8) {
        local_f8 = (size_t)(local_cc + 1);
      }
      memcpy(local_f0,local_c8,local_f8 - 1);
      local_f0[local_f8 - 1] = '\0';
    }
    free(local_c8);
  }
  return local_cc;
}


// ===== 00265779 FUN_00265779 =====

void FUN_00265779(long param_1,utsname *param_2)

{
  int iVar1;
  long lVar2;
  utsname local_198;
  utsname *local_10;
  
  lVar2 = FUN_0026547e(*(undefined8 *)**(undefined8 **)(param_1 + 0x18),"OSName");
  if (lVar2 == 0) {
    local_10 = param_2;
    if (param_2 == (utsname *)0x0) {
      local_10 = &local_198;
      iVar1 = uname(local_10);
      if (iVar1 < 0) {
        return;
      }
    }
    if (local_10->sysname[0] != '\0') {
      FUN_0024dfb5(*(undefined8 *)**(undefined8 **)(param_1 + 0x18),"OSName",local_10);
    }
    if (local_10->release[0] != '\0') {
      FUN_0024dfb5(*(undefined8 *)**(undefined8 **)(param_1 + 0x18),"OSRelease",local_10->release);
    }
    if (local_10->version[0] != '\0') {
      FUN_0024dfb5(*(undefined8 *)**(undefined8 **)(param_1 + 0x18),"OSVersion",local_10->version);
    }
    if (local_10->nodename[0] != '\0') {
      FUN_0024dfb5(*(undefined8 *)**(undefined8 **)(param_1 + 0x18),"HostName",local_10->nodename);
    }
    if (local_10->machine[0] != '\0') {
      FUN_0024dfb5(*(undefined8 *)**(undefined8 **)(param_1 + 0x18),"Architecture",local_10->machine
                  );
    }
  }
  return;
}


// ===== 0026590a FUN_0026590a =====

char * FUN_0026590a(void)

{
  char *pcVar1;
  char *local_10;
  
  local_10 = *(char **)PTR_program_invocation_name_0032ef80;
  if (local_10 == (char *)0x0) {
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = strrchr(local_10,0x2f);
    if (pcVar1 != (char *)0x0) {
      local_10 = pcVar1 + 1;
    }
    pcVar1 = strdup(local_10);
  }
  return pcVar1;
}


